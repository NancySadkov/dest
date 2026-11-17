#!/usr/bin/env python3
"""Apply the reproducible subset of compile fixes to src/decompiled.

The tree in src/decompiled is the exported Ghidra source plus the fixes made
while getting it to compile with Turbo C++ 3.0.  This script re-applies the
mechanical, unambiguous rewrites so that a fresh export can be brought back to
the same state.  Per-function type fixes that needed judgement live only in
the tree (and are tracked in doc/source_recovery.md).

Usage:
  python scripts/fbov/fix_compile.py [--dry-run]
"""
import argparse
import glob
import io
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
OUT = os.path.join(ROOT, "src", "decompiled")

# Decompiler names/types that Turbo C does not accept, and their meaning.
SUBS = [
    (r"\buint3\b", "uint32_t"),
    (r"\bundefined3\b", "uint32_t"),
    (r"\blongdouble\b", "long double"),
    (r"\b_pcStackY_20\b", "pcStackY_20"),
    (r"\b_path\b", "path"),
    # Ghidra sometimes prefixes a stack local with an underscore at use sites.
    (r"\b_([a-z]Stack[0-9A-Fa-f]+)\b", r"\1"),
    # far_t used as an address: dereference through its own segment/offset.
    (r"\*\(int \*\)\(BDA_DailyTimeCounter\.ofs \+ 2\)",
     "*(int far *)MK_FP(BDA_DailyTimeCounter.seg, "
     "BDA_DailyTimeCounter.ofs + 2)"),
    (r"\*\(int \*\)BDA_DailyTimeCounter",
     "*(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)"),
    (r"\*\(undefined2 \*\)\(BDA_DailyTimeCounter\.ofs \+ 2\)",
     "*(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, "
     "BDA_DailyTimeCounter.ofs + 2)"),
    (r"\*\(undefined2 \*\)BDA_DailyTimeCounter",
     "*(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, "
     "BDA_DailyTimeCounter.ofs)"),
]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--dry-run", action="store_true")
    a = ap.parse_args()
    changed = 0
    total = 0
    for p in glob.glob(os.path.join(OUT, "*.c")) + \
            glob.glob(os.path.join(OUT, "*.h")):
        s = io.open(p, encoding="latin1").read()
        o = s
        n = 0
        for pat, rep in SUBS:
            s, k = re.subn(pat, rep, s)
            n += k
        if s != o:
            changed += 1
            total += n
            print("%-24s %d" % (os.path.basename(p), n))
            if not a.dry_run:
                io.open(p, "w", encoding="latin1", newline="").write(s)
    print("files %d, rewrites %d" % (changed, total))


if __name__ == "__main__":
    main()
