#!/usr/bin/env python3
"""Extract the asset operations from the recovered init_assets decompilation.

Writes doc/init_assets_ops.csv: one row per helper call, in order.
This is the operation list that the C reconstruction and the eventual
byte-exact version must reproduce.
"""
import csv
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
SRC = os.path.join(ROOT, "reference", "decompiled_baseline", "hard",
                   "ovc44_strong_dat__init_assets.c")
OUT = os.path.join(ROOT, "doc", "init_assets_ops.csv")
CALL = re.compile(r"(ovr_[A-Za-z0-9_]+|func_0x0007ffe0)\s*\(([^;]*)\)")


def main():
    rows = []
    for line_no, line in enumerate(open(SRC, encoding="ascii"), 1):
        for m in CALL.finditer(line):
            args = " ".join(m.group(2).split())
            rows.append((line_no, m.group(1), args))
    with open(OUT, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["line", "call", "args"])
        w.writerows(rows)
    counts = {}
    for _, name, _ in rows:
        counts[name] = counts.get(name, 0) + 1
    print("wrote", OUT, len(rows), "calls")
    for name, n in sorted(counts.items(), key=lambda x: -x[1]):
        print("  %-28s %d" % (name, n))


if __name__ == "__main__":
    main()
