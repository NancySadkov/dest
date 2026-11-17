#!/usr/bin/env python3
"""Dump every recovered game function as a compilable stub.

Reads the Ghidra export's index.tsv and writes one C module per original
overlay into src/, each function a stub with its recovered signature.  The
result always compiles; functions are then replaced one at a time, starting
from main().

Usage:
  python scripts/fbov/make_stub_tree.py [--export tmp/decompiled2] [--out src]
"""
import argparse
import collections
import csv
import io
import os
import re
import shutil

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
SPECIAL = ["main", "mouse", "video", "crtl", "ovl"]


def short_name(mod):
    if mod in SPECIAL:
        return mod
    m = re.match(r"ovc(\d+)", mod)
    return "o%02d" % int(m.group(1)) if m else re.sub(r"\W", "_", mod)


def clean_sig(sig):
    s = re.sub(r"switchD_[0-9a-fA-F]+:[0-9a-fA-F]+::", "", sig)
    s = re.sub(r"\buint3\b", "uint32_t", s)
    s = re.sub(r"\bundefined3\b", "uint32_t", s)
    s = re.sub(r"\blongdouble\b", "long double", s)
    return s


def fname_of(sig):
    m = re.search(r"(\w+)\s*\([^()]*\)\s*;?\s*$", sig)
    return m.group(1) if m else None


def return_type(sig):
    m = re.search(r"^(.*?)\b__(?:cdecl|stdcall|pascal)16(?:near|far)\b", sig)
    if m:
        return m.group(1).strip() or "int"
    # K&R-ish: text before the identifier that introduces the parameter list
    i = sig.find("(")
    head = sig[:i].strip()
    parts = head.rsplit(None, 1)
    return parts[0] if len(parts) == 2 else "int"


def stub(sig):
    decl = sig.rstrip().rstrip(";")
    rt = return_type(decl)
    if rt == "void":
        return decl + "\n{\n}\n"
    return decl + "\n{\n    %s r;\n\n    return r;\n}\n" % rt


def split_params(inner):
    out, depth, cur = [], 0, ""
    for ch in inner:
        if ch in "([":
            depth += 1
        elif ch in ")]":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur)
            cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur)
    return [p.strip() for p in out]


def param_names(sig):
    i, j = sig.find("("), sig.rfind(")")
    inner = sig[i + 1:j].strip()
    if not inner or inner == "void":
        return []
    names = []
    for p in split_params(inner):
        if "..." in p:
            return None
        m = re.search(r"([A-Za-z_]\w*)\s*(?:\[\s*\])?\s*$", p)
        if not m or m.group(1) in ("void",):
            return None
        names.append(m.group(1))
    return names


def forwarder(sig, fn, name):
    """Rename `fn` to `name` in the signature and forward the call."""
    decl = re.sub(r"\b%s\s*\(" % re.escape(fn), name + "(", sig, count=1)
    args = param_names(sig)
    if args is None:
        return stub(decl)
    rt = return_type(sig)
    call = "%s(%s);" % (fn, ", ".join(args))
    body = "    return " + call if rt != "void" else "    " + call
    return decl.rstrip().rstrip(";") + "\n{\n" + body + "\n}\n"


TYPE_BYTES = {"undefined": 1, "undefined1": 1, "char": 1, "byte": 1,
              "uint8_t": 1, "int8_t": 1, "bool": 1, "undefined2": 2,
              "word": 2, "int": 2, "uint": 2, "short": 2, "uint16_t": 2,
              "int16_t": 2, "undefined4": 4, "long": 4, "ulong": 4,
              "uint32_t": 4, "int32_t": 4, "dword": 4, "DW": 4, "far_t": 4}


def decl_bytes(line):
    m = re.match(r"\s*([A-Za-z_]\w*)\s", line)
    base = TYPE_BYTES.get(m.group(1), 2) if m else 2
    n = 1
    for dim in re.findall(r"\[\s*(0x[0-9a-fA-F]+|\d+)\s*\]", line):
        n *= int(dim, 0)
    q = re.search(r'= "(.*)"', line)
    if q:
        n = max(n, len(q.group(1)) + 1)
    return base * n


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--export", default=os.path.join(ROOT, "tmp", "decompiled2"))
    ap.add_argument("--out", default=os.path.join(ROOT, "src"))
    ap.add_argument("--force", action="store_true",
                    help="overwrite files whose bodies have been recovered")
    a = ap.parse_args()
    if not os.path.isdir(a.export):
        raise SystemExit("missing export " + a.export)

    rows = []
    for r in csv.DictReader(open(os.path.join(a.export, "index.tsv"),
                                 encoding="utf-8"), delimiter="\t"):
        sig = r.get("signature") or ""
        mod = r.get("module") or ""
        if not sig or not (mod in SPECIAL or re.match(r"ovc\d+", mod)):
            continue
        sig = clean_sig(sig)
        fn = fname_of(sig)
        if not fn:
            continue
        rows.append({"mod": mod, "addr": r["address"], "name": fn,
                     "sig": sig})

    # Deduplicate function names: keep the lowest address, suffix the rest.
    by_name = collections.defaultdict(list)
    for r in rows:
        by_name[r["name"]].append(r)
    for name, group in by_name.items():
        group.sort(key=lambda x: int(x["addr"].split(":")[1], 16))
        for i, r in enumerate(group):
            if i:
                r["name"] = "%s_%s" % (name, r["addr"].split(":")[1])
            # rewrite the identifier in the signature
            r["sig"] = re.sub(r"\b%s\s*\(" % re.escape(name),
                              r["name"] + "(", r["sig"], count=1)

    # Overlay thunks.  The original binary calls a per-overlay entry stub
    # (`ovr_<name>`) that loads the overlay and jumps to `<name>`.  The
    # rebuilt tree has no overlays, so each thunk becomes a forwarder with
    # the target's recovered signature.
    thunks = []
    stubsc = os.path.join(a.export, "ovr_stubs.c")
    if os.path.exists(stubsc):
        txt = io.open(stubsc, encoding="latin1").read()
        for loc, target in re.findall(r"/\* ([0-9a-f]{4}:[0-9a-f]{4}) -> (\w+) \*/",
                                      txt):
            group = by_name.get(target)
            if not group or len(group) != 1:
                continue                # unknown or ambiguous target
            t = group[0]
            thunks.append({"loc": loc, "name": "ovr_" + target, "target": t})

    mods = collections.defaultdict(list)
    for r in rows:
        mods[r["mod"]].append(r)

    def mkey(m):
        if m in SPECIAL:
            return (0, SPECIAL.index(m), m)
        return (1, int(re.match(r"ovc(\d+)", m).group(1)), m)

    order = sorted(mods, key=mkey)

    out = {}

    def emit(name, text, enc="ascii"):
        out[name] = text

    def copy_file(src, dst):
        p = os.path.join(a.export, src)
        if os.path.exists(p):
            emit(dst, io.open(p, encoding="latin1").read())
        return p

    os.makedirs(a.out, exist_ok=True)
    for src, dst in (("st_compat.h", "compat.h"), ("st_types.h", "types.h"),
                     ("st_globals.h", "globals.h")):
        copy_file(src, dst)
    for src, dst in (("st_globals.c", "globals.c"),
                     ("support.c", "support.c")):
        p = os.path.join(a.export, src)
        if not os.path.exists(p):
            continue
        s = io.open(p, encoding="latin1").read()
        s = s.replace('#include "recovered.h"', '#include "st.h"')
        if src == "st_globals.c":
            # The data image is not part of the stub stage: stubs reference
            # nothing, and the definitions arrive with the functions.  The
            # declarations stay in globals.h.
            continue
        emit(dst, s)
    emit("st.h",
         "/* Rebuild aggregate header (generated by make_stub_tree.py). */\n"
         "#ifndef ST_REBUILD_H\n#define ST_REBUILD_H\n"
         '#include "compat.h"\n#include "types.h"\n'
         '#include "globals.h"\n#include "funcs.h"\n'
         "#endif\n")

    protos = ["/* Prototypes for every recovered function (generated). */",
              "#ifndef ST_FUNCS_H", "#define ST_FUNCS_H", ""]
    total = 0
    for m in order:
        name = short_name(m)
        lines = ['#include "st.h"', "",
                 "/* %s: %d function(s) */" % (m, len(mods[m])), ""]
        protos.append("/* %s */" % m)
        for r in sorted(mods[m], key=lambda x: int(x["addr"].split(":")[1], 16)):
            lines.append("/* %s */" % r["addr"])
            lines.append(stub(r["sig"]))
            protos.append(r["sig"])
            total += 1
        protos.append("")
        emit(name + ".c", "\n".join(lines) + "\n")

    if thunks:
        lines = ['#include "st.h"', "",
                 "/* Overlay entry stubs: %d forwarder(s). */" % len(thunks), ""]
        protos.append("/* overlay thunks */")
        for t in thunks:
            tgt = t["target"]
            lines.append("/* %s -> %s */" % (t["loc"], tgt["name"]))
            lines.append(forwarder(tgt["sig"], tgt["name"], t["name"]))
            protos.append(forwarder(tgt["sig"], tgt["name"], t["name"])
                          .split("\n", 1)[0] + ";")
        protos.append("")
        total += len(thunks)
        emit("ovr.c", "\n".join(lines) + "\n")

    protos.append("#endif")
    emit("funcs.h", "\n".join(protos) + "\n")

    # Never clobber recovered bodies: report files that already differ.
    changed = []
    for name, text in out.items():
        p = os.path.join(a.out, name)
        if os.path.exists(p):
            cur = io.open(p, encoding="latin1").read()
            if cur.replace("\r\n", "\n") != text.replace("\r\n", "\n"):
                changed.append(name)
    if changed and not a.force:
        print("%d file(s) in %s differ from the generated stubs:"
              % (len(changed), a.out))
        print("  " + " ".join(sorted(changed)))
        print("re-run with --force to overwrite recovered work")
        return 1

    for name, text in out.items():
        io.open(os.path.join(a.out, name), "w", encoding="latin1",
                newline="\n").write(text)
    print("wrote %d modules, %d stubs to %s" % (len(order), total, a.out))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())