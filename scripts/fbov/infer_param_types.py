#!/usr/bin/env python3
"""Infer parameter struct types from the exported C (alias + declaration aware).

Output: tmp/param_types.txt  (function<TAB>param_index<TAB>struct)
"""
import argparse
import collections
import csv
import glob
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
FUNC_RE = re.compile(
    r"^([A-Za-z_][\w \t\*]*?)\s+(\w+)\s*\(([^)]*)\)\s*$", re.M)
DECL_RE = re.compile(
    r"^\s*([A-Za-z_][\w \t]*?)\s*\*+\s*(\w+)\s*(?:\[[^\]]*\])?\s*;", re.M)
SIZES = {"char": 1, "byte": 1, "undefined1": 1, "uint8_t": 1,
         "undefined": 1, "bool": 1, "signed char": 1,
         "int": 2, "uint": 2, "short": 2, "undefined2": 2, "uint16_t": 2,
         "int16_t": 2, "word": 2, "unsigned": 2,
         "long": 4, "ulong": 4, "undefined4": 4, "uint32_t": 4,
         "int32_t": 4, "dword": 4, "far_t": 4, "DW": 4}


def load_structs():
    rows = list(csv.DictReader(open(os.path.join(ROOT, "doc",
                                                 "ghidra_types_audit.csv"))))
    structs = {}
    for r in rows:
        if r["offset"] == "":
            continue
        name = r["struct"].rstrip()
        if not name.startswith("/st.h/"):
            continue
        s = structs.setdefault(name, {"size": int(r["size"]),
                                      "offsets": set()})
        s["offsets"].add(int(r["offset"]))
    return structs


def params(args):
    out = []
    for a in args.split(","):
        a = a.strip()
        if not a:
            continue
        m = re.search(r"(\w+)\s*$", a)
        if m:
            out.append(m.group(1))
    return out


def decl_sizes(body):
    d = {}
    for m in DECL_RE.finditer(body):
        base = re.sub(r"\s+", " ", m.group(1).strip())
        # keep the last type word ("long int" -> int etc is fine)
        for k, v in SIZES.items():
            if base.endswith(k):
                d[m.group(2)] = v
                break
    return d


def aliases(body, roots, sizes):
    amap = {r: (r, 1) for r in roots}
    changed = True
    while changed:
        changed = False
        for m in re.finditer(
                r"\b(\w+)\s*=\s*(?:\(\s*([A-Za-z_][\w ]*?)\s*\*+\s*\))?\s*"
                r"(\w+)\b", body):
            dst, cast, src = m.group(1), m.group(2), m.group(3)
            if src not in amap or dst in amap:
                continue
            root, base = amap[src]
            key = re.sub(r"\s+", " ", (cast or "").strip())
            esz = SIZES.get(key) or sizes.get(dst) or base
            amap[dst] = (root, esz)
            changed = True
    return amap


def offsets_for(body, amap, sizes):
    offs = collections.defaultdict(set)
    for var, (root, esz) in amap.items():
        v = re.escape(var)
        e = sizes.get(var, esz)
        for m in re.finditer(r"\(int\)\s*" + v +
                             r"\s*\+\s*(0x[0-9a-fA-F]+|\d+)", body):
            offs[root].add(int(m.group(1), 0))
        for m in re.finditer(r"\b" + v +
                             r"\s*\+\s*(0x[0-9a-fA-F]+|\d+)\b", body):
            offs[root].add(int(m.group(1), 0) * e)
        for m in re.finditer(r"\b" + v + r"\s*\[\s*(\d+)\s*\]", body):
            offs[root].add(int(m.group(1)) * e)
    return offs


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--export", default=os.path.join(ROOT, "tmp", "decompiled"))
    ap.add_argument("--out", default=os.path.join(ROOT, "tmp", "param_types.txt"))
    a = ap.parse_args()
    structs = load_structs()

    results = []
    for path in sorted(glob.glob(os.path.join(a.export, "ovc*.c"))):
        text = open(path, encoding="latin1", errors="replace").read()
        for m in FUNC_RE.finditer(text):
            i = text.find("{", m.end())
            if i < 0 or i - m.end() > 4:
                continue
            depth = 0
            for j in range(i, len(text)):
                if text[j] == "{":
                    depth += 1
                elif text[j] == "}":
                    depth -= 1
                    if depth == 0:
                        break
            body = text[i:j + 1]
            name = m.group(2)
            ps = params(m.group(3))
            if not ps:
                continue
            sizes = decl_sizes(body)
            amap = aliases(body, ps, sizes)
            offs = offsets_for(body, amap, sizes)
            for idx, p in enumerate(ps):
                o = offs.get(p)
                if not o or len(o) < 3:
                    continue
                best = None
                for sname, s in structs.items():
                    size = s["size"]
                    if max(o) >= size:
                        continue
                    hit = len(o & s["offsets"])
                    if hit < 2:
                        continue
                    score = hit / float(len(o))
                    if score < 0.75:
                        continue
                    if best is None or score > best[0]:
                        best = (score, sname)
                if best:
                    results.append((name, idx, best[1]))

    with open(a.out, "w", encoding="ascii", newline="") as f:
        for row in results:
            f.write("%s\t%d\t%s\n" % row)
    c = collections.Counter(r[2] for r in results)
    print("parameter matches:", len(results))
    for s, n in c.most_common():
        print("  %-24s %d" % (s, n))
    print("wrote", a.out)


if __name__ == "__main__":
    main()
