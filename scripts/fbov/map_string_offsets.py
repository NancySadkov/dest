#!/usr/bin/env python3
"""Map every remaining `"string" + offset` value to its DGROUP symbol/gap.

Reads the sweep report produced by sweep_string_offsets.py and resolves each
numeric value against doc/dgroup_map.csv plus the gap arrays in src/dgroup.h.
"""
import argparse
import csv
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def build_symbols():
    syms = []
    for r in csv.DictReader(open(os.path.join(ROOT, "doc", "dgroup_map.csv"))):
        off = int(r["offset"], 16)
        syms.append((off, off + int(r["length"]), r["name"]))
    text = open(os.path.join(ROOT, "src", "dgroup.h")).read()
    for m in re.finditer(r"extern uint8_t (gap_2410_([0-9A-Fa-f]{4}))\[(\d+)\];",
                         text):
        off = int(m.group(2), 16)
        syms.append((off, off + int(m.group(3)), m.group(1)))
    syms.sort()
    return syms


def resolve(val, syms):
    for s, e, name in syms:
        if s <= val < e:
            return name, val - s
    return None, 0


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--report", required=True)
    ap.add_argument("--out", required=True)
    a = ap.parse_args()
    syms = build_symbols()
    rows = list(csv.DictReader(open(a.report)))
    with open(a.out, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["file", "line", "expression", "kind", "value",
                    "symbol", "delta"])
        for r in rows:
            if r["kind"] not in ("other", "unmapped"):
                continue
            if not r["value"]:
                w.writerow([r["file"], r["line"], r["expression"], r["kind"],
                            "", "", ""])
                continue
            val = int(r["value"], 16)
            name, delta = resolve(val, syms)
            w.writerow([r["file"], r["line"], r["expression"], r["kind"],
                        r["value"], name or "", delta])
    print("wrote", a.out)


if __name__ == "__main__":
    main()
