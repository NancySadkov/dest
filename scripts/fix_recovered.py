#!/usr/bin/env python3
"""Post-process the Ghidra export in src/decompiled.

Run this once after a fresh ExportRecovered/ExportData export.  It rewrites
Ghidra decompiler artifacts into constructs Turbo C++ 3.0 accepts.  It is not
idempotent: re-running it on an already-post-processed tree can re-wrap casts.
"""
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, "src", "decompiled")

NS_RE = re.compile(r"switchD_[0-9a-fA-F]+:[0-9a-fA-F]+::(caseD_[0-9]+)")

OVERLAY_RE = re.compile(
    r"((?:[A-Za-z_]\w*(?:\s*\[[^\]]*\])?)(?:\s*(?:\.|->)\s*[A-Za-z_]\w*(?:\s*\[[^\]]*\])?)*)"
    r"\._(\d+)_(\d+)_")

def overlay_repl(m):
    base, off, size = m.group(1), int(m.group(2)), int(m.group(3))
    typ = {1: "uint8_t", 2: "uint16_t", 4: "uint32_t"}.get(size)
    if typ is None:
        typ = "uint32_t"
    if off:
        return "(*(%s *)((uint8_t *)&(%s) + %d))" % (typ, base, off)
    return "(*(%s *)((uint8_t *)&(%s)))" % (typ, base)

def rewrite_overlays():
    changed = 0
    total = 0
    for name in os.listdir(OUT):
        if not name.endswith(".c"):
            continue
        path = os.path.join(OUT, name)
        with open(path, "r", encoding="utf-8", errors="replace") as f:
            s = f.read()
        new, n = OVERLAY_RE.subn(overlay_repl, s)
        if n:
            with open(path, "w", encoding="utf-8", errors="replace") as f:
                f.write(new)
            changed += 1
            total += n
    return changed, total

def nearest_is_far(s, pos, var):
    """True if the nearest declaration of var before pos is far_t."""
    far_pat = re.compile(r"\bfar_t\s+" + re.escape(var) + r"\b")
    other_pat = re.compile(
        r"(?m)^\s*[A-Za-z_]\w*(?:\s+[A-Za-z_]\w*)*\s*\*+\s*"
        + re.escape(var) + r"\b")
    loose_pat = re.compile(
        r"(?m)^\s*(?:void|uint32_t|uint16_t|uint8_t|uint|int|long|undefined4|"
        r"undefined2|undefined1|undefined|char|byte|bool|DW|stg_tmp_t|far_t)\b"
        r"[^;\n]*\b" + re.escape(var) + r"\b")
    far = None
    for m in far_pat.finditer(s, 0, pos):
        far = m
    other = None
    for p in (other_pat, loose_pat):
        for m in p.finditer(s, 0, pos):
            if other is None or m.start() > other.start():
                other = m
    if far is None:
        return False
    return other is None or far.start() >= other.start()

def rewrite_far_casts():
    total = 0
    for name in os.listdir(OUT):
        if not name.endswith(".c"):
            continue
        path = os.path.join(OUT, name)
        s = open(path, "r", encoding="utf-8", errors="replace").read()
        far_vars = set(re.findall(r"\bfar_t\s+([A-Za-z_]\w*)", s))
        out = []
        i = 0
        n = 0
        while True:
            j = s.find("(far_t)", i)
            if j < 0:
                out.append(s[i:])
                break
            out.append(s[i:j])
            k = j + 7
            while k < len(s) and s[k].isspace():
                k += 1
            if k < len(s) and s[k] == "(":
                depth = 0
                e = k
                while e < len(s):
                    if s[e] == "(":
                        depth += 1
                    elif s[e] == ")":
                        depth -= 1
                        if depth == 0:
                            e += 1
                            break
                    e += 1
                expr = s[k:e]
                out.append("far_from_u32((uint32_t)%s)" % expr)
                i = e
                n += 1
                continue
            m = re.match(r"[A-Za-z_]\w*", s[k:])
            if not m:
                m2 = re.match(r"[^;,)\s]+", s[k:])
                if m2:
                    expr = m2.group(0)
                    out.append("far_from_u32((uint32_t)(%s))" % expr)
                    i = k + len(expr)
                    n += 1
                    continue
                out.append("(far_t)")
                i = j + 7
                continue
            root = m.group(0)
            e = k + len(root)
            while e < len(s):
                if s[e] == "[":
                    depth = 0
                    while e < len(s):
                        if s[e] == "[":
                            depth += 1
                        elif s[e] == "]":
                            depth -= 1
                            if depth == 0:
                                e += 1
                                break
                        e += 1
                    continue
                if s[e] == "(":
                    depth = 0
                    while e < len(s):
                        if s[e] == "(":
                            depth += 1
                        elif s[e] == ")":
                            depth -= 1
                            if depth == 0:
                                e += 1
                                break
                        e += 1
                    continue
                mm = re.match(r"\s*(\.|->)\s*[A-Za-z_]\w*", s[e:])
                if mm:
                    e += mm.end()
                    continue
                break
            expr = s[k:e]
            if root in far_vars and not re.match(r"\s*\(", s[k+len(root):]) and nearest_is_far(s, j, root):
                out.append(expr)
            else:
                out.append("far_from_u32((uint32_t)(%s))" % expr)
            i = e
            n += 1
        if True:
            joined = "".join(out)
            cast_re = re.compile(
                r"\((ulong|uint32_t|long)\)\s*([A-Za-z_]\w*)"
                r"(?:\s*\[[^\]]*\])?(?!\s*(?:\.|->))")
            def cast_repl(m):
                typ, var = m.group(1), m.group(2)
                if not nearest_is_far(joined, m.start(), var):
                    return m.group(0)
                inner = "far_to_u32(%s)" % var
                return inner if typ != "long" else "(long)" + inner
            joined = cast_re.sub(cast_repl, joined)
            ptr_re = re.compile(r"\(([A-Za-z_]\w*)\s*\*\)\s*([A-Za-z_]\w*)\b(?!\s*\.)")
            def ptr_repl(m):
                typ, var = m.group(1), m.group(2)
                if nearest_is_far(joined, m.start(), var):
                    return "(%s *)MK_FP(%s.seg, %s.ofs)" % (typ, var, var)
                return m.group(0)
            joined = ptr_re.sub(ptr_repl, joined)
            # far_t compared against a zero far pointer
            joined = re.sub(r"\b([A-Za-z_]\w*)\s*(==|!=)\s*far_from_u32\(\(uint32_t\)\(0x0\)\)",
                            lambda m: "far_to_u32(%s) %s 0" % (m.group(1), m.group(2))
                            if nearest_is_far(joined, m.start(), m.group(1)) else m.group(0),
                            joined)
            # far_t == far_t / far_t != far_t
            def cmp_repl(m):
                a, op, b = m.group(1), m.group(2), m.group(3)
                if nearest_is_far(joined, m.start(), a) and nearest_is_far(joined, m.end(), b):
                    return "far_to_u32(%s) %s far_to_u32(%s)" % (a, op, b)
                return m.group(0)
            joined = re.sub(r"\b([A-Za-z_]\w*)\s*(==|!=)\s*([A-Za-z_]\w*)\b",
                            cmp_repl, joined)
            # far_t = allocator(...)
            allocs = ("ovr_heapMalloc", "ovr_heapRealloc",
                      "ovr_stshAlloc", "ovr_stshRealloc", "malloc", "calloc")
            def alloc_repl(m):
                ws, lhs, fn, args = m.group(1), m.group(2), m.group(3), m.group(4)
                if nearest_is_far(joined, m.start(), lhs):
                    return "%s%s = far_from_u32((uint32_t)%s(%s));" % (ws, lhs, fn, args)
                return m.group(0)
            joined = re.sub(r"(?m)^(\s*)([A-Za-z_]\w*)\s*=\s*(" +
                            "|".join(allocs) + r")\s*\(([^;\n]*)\);",
                            alloc_repl, joined)
            # undo the earlier over-eager form: (T *)MK_FP(x.seg,x.ofs).ofs
            joined = re.sub(r"\(([A-Za-z_]\w*)\s*\*\)\s*MK_FP\((\w+)\.seg,\s*\2\.ofs\)\.ofs",
                            r"(\1 *)\2.ofs", joined)
            joined = re.sub(r"\(([A-Za-z_]\w*)\s*\*\)\s*MK_FP\((\w+)\.seg,\s*\2\.ofs\)\.seg",
                            r"(\1 *)\2.seg", joined)
            open(path, "w", encoding="utf-8", errors="replace").write(joined)
            total += n
    return total

def rewrite_ptr_to_word():
    glob = os.path.join(OUT, "st_globals.h")
    if not os.path.isfile(glob):
        return 0
    txt = open(glob, "r", encoding="utf-8", errors="replace").read()
    types = {}
    for m in re.finditer(r"extern\s+(undefined1|uint8_t|undefined2|uint16_t|int16_t)\s+(\w+);", txt):
        types[m.group(2)] = m.group(1)
    cast = {"undefined1": "uint8_t", "uint8_t": "uint8_t",
            "undefined2": "uint16_t", "uint16_t": "uint16_t", "int16_t": "int16_t"}
    total = 0
    for name in os.listdir(OUT):
        if not name.endswith(".c"):
            continue
        path = os.path.join(OUT, name)
        s = open(path, "r", encoding="utf-8", errors="replace").read()
        def repl(m):
            nonlocal total
            ws, lhs, typ, expr = m.group(1), m.group(2), m.group(3), m.group(4)
            if lhs not in types:
                return m.group(0)
            total += 1
            return "%s%s = (%s)(%s);" % (ws, lhs, cast.get(types[lhs], "uint16_t"), expr)
        s2 = re.sub(r"(?m)^(\s*)([A-Za-z_]\w*)\s*=\s*\(([A-Za-z_]\w*)\s*\*\)\s*([^;\n]+);",
                    repl, s)
        def arr_repl(m):
            nonlocal total
            total += 1
            return "%s = (uint16_t)(%s);" % (m.group(1), m.group(3))
        s2 = re.sub(
            r"(\(\s*(?:undefined2|uint16_t)\s*\*\)\s*&[A-Za-z_]\w*\)\[[^\]]*\])\s*=\s*"
            r"\(([A-Za-z_]\w*)\s*\*\)\s*([^;\n]+);",
            arr_repl, s2)
        if s2 != s:
            open(path, "w", encoding="utf-8", errors="replace").write(s2)
    return total

def rewrite_names():
    for name in os.listdir(OUT):
        if not name.endswith(".c"):
            continue
        pp = os.path.join(OUT, name)
        t = open(pp, "r", encoding="utf-8", errors="replace").read()
        t2 = re.sub(r"(?<![A-Za-z0-9])_DAT_(2000|2410)_", r"DAT_\1_", t)
        if t2 != t:
            open(pp, "w", encoding="utf-8", errors="replace").write(t2)
    changed = 0
    for name in os.listdir(OUT):
        if not name.endswith((".c", ".h")):
            continue
        path = os.path.join(OUT, name)
        with open(path, "r", encoding="utf-8", errors="replace") as f:
            s = f.read()
        # switchD_SEG:OFF::caseD_N -> switchD_SEG_OFF_caseD_N
        new = re.sub(r"switchD_([0-9a-fA-F]+):([0-9a-fA-F]+)::(caseD_[0-9]+)",
                     r"switchD_\1_\2_\3", s)
        if new != s:
            with open(path, "w", encoding="utf-8") as f:
                f.write(new)
            changed += 1
    return changed

def ident_type(name):
    if name.startswith(("stack0x", "ram0x")):
        return "undefined1"
    if name.startswith("far_t_ARRAY_"):
        return "far_t"
    if name.startswith("UNK_"):
        return "uint32_t"
    if name.startswith("_font_"):
        return "int"
    if "Stack_" in name:
        if name.startswith("_") or name.lower().startswith(("u", "i")):
            return "uint32_t"
        if name.lower().startswith("p"):
            return "undefined1 *"
        return "uint16_t"
    if name.startswith("puRam"):
        return "undefined2 *"
    if name.startswith("pcRam"):
        return "char *"
    if name.startswith("pRam"):
        return "undefined1 *"
    if name.startswith("uRam"):
        return "undefined2"
    if name.startswith("iRam"):
        return "int16_t"
    if name.startswith("cRam"):
        return "char"
    if name.startswith(("in_", "unaff_", "extraout_", "out_")):
        suf = name.split("_", 1)[1]
        if suf in ("CF", "ZF", "SF", "OF", "AF", "PF", "IF", "TF", "DF", "NT"):
            return "uint8_t"
        if suf in ("AL", "AH", "BL", "BH", "CL", "CH", "DL", "DH", "AX8", "BX8", "CX8", "DX8"):
            return "uint8_t"
        if suf.startswith(("E",)):
            return "uint32_t"
        return "uint16_t"
    return None

def generate_artifacts():
    ids = set()
    pat = re.compile(r"\b((?:p?[uic]?Ram[0-9a-fA-F]{5,8})|(?:stack0x[0-9a-fA-F]+)|(?:in_[A-Za-z0-9_]+)|(?:unaff_[A-Za-z0-9_]+)|(?:extraout_[A-Za-z0-9_]+)|(?:out_[A-Za-z0-9_]+)|(?:_?[A-Za-z]*Stack_[0-9a-fA-F]+)|(?:ram0x[0-9a-fA-F]+)|(?:far_t_ARRAY_[0-9a-fA-F_]+)|(?:UNK_[0-9A-Fa-f_]+)|(?:_font_[0-9a-fA-F_]+))\b")
    for name in os.listdir(OUT):
        if not name.endswith(".c"):
            continue
        with open(os.path.join(OUT, name), "r", encoding="utf-8", errors="replace") as f:
            ids.update(pat.findall(f.read()))
    path = os.path.join(OUT, "st_artifacts.h")
    with open(path, "w", encoding="utf-8") as f:
        f.write("/* Declarations for Ghidra decompiler RAM/register pseudo-variables. */\n")
        f.write("#ifndef ST_ARTIFACTS_H\n#define ST_ARTIFACTS_H\n")
        for i in sorted(ids):
            t = ident_type(i)
            if t:
                if i.startswith("far_t_ARRAY_"):
                    f.write("extern %s %s[];\n" % (t, i))
                else:
                    f.write("extern %s %s;\n" % (t, i))
        f.write("#endif\n")
    return len(ids)

def patch_headers():
    rec = os.path.join(OUT, "recovered.h")
    with open(rec, "r", encoding="utf-8") as f:
        s = f.read()
    if "st_artifacts.h" not in s:
        s = s.replace('#include "st_globals.h"',
                      '#include "st_globals.h"\n#include "st_artifacts.h"')
        with open(rec, "w", encoding="utf-8") as f:
            f.write(s)

    compat = os.path.join(OUT, "st_compat.h")
    with open(compat, "r", encoding="utf-8") as f:
        s = f.read()
    extra = []
    if "#define true" not in s:
        extra.append("#ifndef true\n#define true 1\n#define false 0\n#endif")
    if "#define _argv" not in s:
        extra.append("/* Borland's @-suffixed startup symbols. */")
        extra.append("#define _argv ((str_t *)_argv_at_)")
        extra.append("#define _argc ((int)_argc_at_)")
        extra.append("#define _envseg _envseg_at_")
        extra.append("#define _envSize _envSize_at_")
        extra.append("#define bdata bdata_at_")
        extra.append("#define DGROUP_ DGROUP_at__at_")
    if "#define _bdata_at_" not in s:
        extra.append("#define _bdata_at_ bdata_at_")
    if extra:
        # insert before the final #endif
        idx = s.rfind("#endif")
        s = s[:idx] + "\n".join(extra) + "\n" + s[idx:]
        with open(compat, "w", encoding="utf-8") as f:
            f.write(s)

def fix_global_data():
    """Make the exported data file acceptable to TC30.

    - Shorten Borland-visible string symbols to 31 chars.
    - Declare string tables as ``char`` arrays.
    - Fix a few scalar/array types the exporter inferred differently.
    """
    files = [f for f in os.listdir(OUT) if f.endswith((".c", ".h"))]
    texts = {}
    for f in files:
        texts[f] = open(os.path.join(OUT, f), "r", encoding="utf-8",
                        errors="replace").read()

    pat = re.compile(r"\bs_[A-Za-z0-9_]+_(?:2410|2000)_[0-9a-fA-F]{4}\b")
    names = set()
    for s in texts.values():
        names.update(pat.findall(s))
    rename = {}
    used = set()
    for n in sorted(names):
        if len(n) <= 31:
            used.add(n)
            continue
        m = re.search(r"(_(?:2410|2000)_[0-9a-fA-F]{4})$", n)
        if not m:
            continue
        suffix = m.group(1)
        prefix = n[: len(n) - len(suffix)]
        room = 31 - len(suffix)
        cand = prefix[:room] + suffix
        k = 0
        while cand in used or (cand in names and cand != n):
            k += 1
            tail = "_%d" % k
            cand = prefix[: room - len(tail)] + tail + suffix
        rename[n] = cand
        used.add(cand)
    for f in files:
        s = texts[f]
        for a, b in rename.items():
            s = re.sub(r"\b" + re.escape(a) + r"\b", b, s)
        if f == "st_globals.c":
            s = re.sub(r'(?m)^undefined (s_[A-Za-z0-9_]+\[\]) = "',
                       r'char \1 = "', s)
            s = s.replace("undefined DAT_2000_d1c0 = 0x00;",
                          "undefined2 DAT_2000_d1c0 = 0x00;")
            s = s.replace("undefined s__2410_62db[] = { 0x7F };",
                          "char s__2410_62db[] = { 0x7F };")
        if f == "st_globals.h":
            s = re.sub(r'(?m)^extern undefined (s_[A-Za-z0-9_]+\[\]);',
                       r'extern char \1;', s)
        texts[f] = s
    changed = 0
    for f in files:
        if texts[f] != open(os.path.join(OUT, f), "r", encoding="utf-8",
                            errors="replace").read():
            changed += 1
        with open(os.path.join(OUT, f), "w", encoding="utf-8",
                  errors="replace") as fh:
            fh.write(texts[f])
    return len(rename), changed

if __name__ == "__main__":
    if not os.path.isdir(OUT):
        print("missing", OUT)
        sys.exit(1)
    n = rewrite_names()
    f = rewrite_far_casts()
    w = rewrite_ptr_to_word()
    o, ot = rewrite_overlays()
    gr, gc = fix_global_data()
    a = generate_artifacts()
    patch_headers()
    print("rewrote files:", n, "far casts:", f, "ptr->word:", w,
          "overlay files:", o, "overlay refs:", ot, "renamed globals:", gr,
          "global files:", gc, "artifact declarations:", a)


# Sweeps that must run inside the pipeline so a re-export cannot wipe them.
import subprocess as _sp
_HERE = os.path.dirname(os.path.abspath(__file__))
for _name in ("fix_string_folds.py", "fix_raw_arrays.py", "fix_bda_far.py",
              "fix_far_fields.py", "fix_field_access.py", "fix_dgroup_ptrs.py",
              "fix_far_data.py", "fix_struct_stride.py", "fix_long_identifiers.py",
              "fix_startup_owned.py", "fix_startup_globals.py",
              "gen_ovr_thunks.py"):
    _script = os.path.join(_HERE, _name)
    if os.path.isfile(_script):
        _sp.run([sys.executable, _script, "--apply"], check=False)

# The globals TU is ~100 KB of data; Turbo C stops at 64 KB, so it is emitted as
# st_globals.c + st_globals2.c (stage_build maps the second to glob2.c).
_sp.run([sys.executable, os.path.join(_HERE, "split_globals.py")], check=False)

# split_globals.py regenerates st_globals.h from the definitions, which drops the
# `far` the far-data pass put on the declarations.  Re-apply it, now that the
# header exists in its final shape: without this every reference to
# BldGfxNormal / BldGfxRuin / AgntGs is a near reference to far data and TLINK
# reports thousands of fixup overflows.
_sp.run([sys.executable, os.path.join(_HERE, "fix_far_data.py"), "--apply"],
        check=False)

# The committed overrides carry hand-written signatures; keep them in step with
# the prototypes the export just produced.
_sp.run([sys.executable, os.path.join(_HERE, "fix_override_signatures.py")],
        check=False)

# The decompiler sometimes unrolls a loop thousands of times, which trips Turbo C's
# table limit (o02 draw_textTalkwin9Lbm).
_sp.run([sys.executable, os.path.join(_HERE, "compress_repeats.py"),
         os.path.join(ROOT if "ROOT" in dir() else ".", "src", "decompiled"),
         "8", "--apply"], check=False)
