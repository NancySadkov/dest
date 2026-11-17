#!/usr/bin/env python3
"""Measure how much of the byte-dump tree has a Ghidra C body available.

`scripts/ghidra/ExportRecovered.java` writes one C file per module into
tmp/decompiled.  This script compares that export with the hand-maintained
tree in src/ and reports, per module, how many functions are still byte dumps
and how many of those have a decompiled C body to start from.

Usage:
  python scripts/fbov/export_coverage.py [--export DIR] [--detail]
"""
import argparse
import glob
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
SRC = os.path.join(ROOT, "src")
FUNC_RE = re.compile(
    r"^[A-Za-z_][\w \t\*]*__cdecl16(?:far|near)\s+(\w+)\s*\([^;{]*\)\s*\{", re.M)


def functions(path):
    s = open(path, encoding="latin1").read()
    out = {}
    for m in FUNC_RE.finditer(s):
        i = m.end() - 1
        depth = 0
        for j in range(i, len(s)):
            if s[j] == "{":
                depth += 1
            elif s[j] == "}":
                depth -= 1
                if depth == 0:
                    break
        out[m.group(1)] = s[i:j + 1]
    return out


def module_sources(seg):
    beh = os.path.join(SRC, "behaviour")
    pats = ("ov_%04x.c" % seg, "c%04x" % seg)
    found = []
    for root in (beh, SRC):
        for p in sorted(glob.glob(os.path.join(root, "*"))):
            b = os.path.basename(p).lower()
            for pat in pats:
                if b.startswith(pat):
                    found.append(p)
        if found:
            return found
    return found


def export_for(seg, exp):
    for p in glob.glob(os.path.join(exp, "*.c")):
        b = os.path.basename(p).lower()
        if b.startswith("ovc") and b[3:].lstrip("0").startswith(
                "%x" % seg):
            pass
    # The exporter names modules by segment number in hex without leading zeros.
    cand = [p for p in glob.glob(os.path.join(exp, "*.c"))
            if re.search(r"ovc0*%x(_|\.)" % seg, os.path.basename(p).lower())]
    return functions(cand[0]) if cand else {}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--export", default=os.path.join(ROOT, "tmp", "decompiled"))
    ap.add_argument("--detail", action="store_true")
    a = ap.parse_args()
    if not os.path.isdir(a.export):
        raise SystemExit("missing export dir " + a.export)

    import csv
    rows = []
    left_total = dump_total = avail_total = 0
    for r in csv.DictReader(open(os.path.join(ROOT, "doc",
                                              "fbov_overlays.csv"))):
        seg = int(r["code_seg"], 16)
        if int(r["codesz"], 16) == 0:
            continue
        srcs = module_sources(seg)
        if not srcs:
            continue
        have = {}
        for p in srcs:
            have.update(functions(p))
        exported = export_for(seg, a.export)
        dumps = [n for n, body in have.items() if "asm db" in body]
        avail = [n for n in dumps if n in exported]
        left_total += len(have)
        dump_total += len(dumps)
        avail_total += len(avail)
        rows.append((seg, len(have), len(dumps), len(avail)))
    if a.detail:
        print("%-6s %6s %6s %6s" % ("seg", "funcs", "dump", "have C"))
        for seg, n, d, v in rows:
            print("%04X   %6d %6d %6d" % (seg, n, d, v))
    print("functions            %d" % left_total)
    print("still byte dumps     %d" % dump_total)
    print("dump with export C   %d" % avail_total)
    print("coverage of dumps    %.0f%%"
          % (100.0 * avail_total / max(dump_total, 1)))


if __name__ == "__main__":
    main()
