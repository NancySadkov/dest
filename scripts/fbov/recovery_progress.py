#!/usr/bin/env python3
"""Report how much of the recovered source tree is still byte-dump code.

The recovered tree keeps a function as an inline byte dump (`asm db`) when it
has not been converted to C yet.  This script counts, per overlay module:

  * functions and how many still contain `asm db`,
  * the number of emitted bytes inside `asm db` statements,
  * the number of byte patches in `src/ov_patch.csv` (the link-time fixups
    that restore overlay trampoline operands).

Usage:
  python scripts/fbov/recovery_progress.py            # summary
  python scripts/fbov/recovery_progress.py --detail   # per-module table
"""
import argparse
import csv
import glob
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
SRC = os.path.join(ROOT, "src")

FUNC_RE = re.compile(
    r"^[A-Za-z_][\w \t\*]*__cdecl16(?:far|near)\s+\w+\s*\([^;{]*\)\s*\{", re.M)
DB_RE = re.compile(r"asm\s+db\s+([0-9A-Fa-fxh,]+)")


def functions(path):
    s = open(path, encoding="latin1").read()
    out = []
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
        body = s[i:j + 1]
        nbytes = 0
        for d in DB_RE.finditer(body):
            nbytes += len([x for x in d.group(1).split(",") if x.strip()])
        out.append((m.group(0).split()[-1].split("(")[0], nbytes))
    return out


def module_files(seg):
    pats = ("c%04x" % int(seg, 16), "ov_%04x" % int(seg, 16),
            "a%04x" % int(seg, 16))
    found = []
    for p in sorted(glob.glob(os.path.join(SRC, "*"))):
        base = os.path.basename(p)
        for pat in pats:
            if base.lower().startswith(pat) and base.rsplit(".", 1)[-1] in (
                    "c", "asm"):
                found.append(p)
    return found


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--detail", action="store_true")
    a = ap.parse_args()

    patches = {}
    for r in csv.DictReader(open(os.path.join(SRC, "ov_patch.csv"))):
        patches[r["seg"]] = patches.get(r["seg"], 0) + 1

    rows = []
    total_funcs = total_c = total_dump = total_bytes = 0
    for r in csv.DictReader(open(os.path.join(ROOT, "doc",
                                              "fbov_overlays.csv"))):
        seg = r["code_seg"].upper()
        size = int(r["codesz"], 16)
        if size == 0:
            continue
        fs = module_files(seg)
        if not fs:
            continue
        funcs = []
        for p in fs:
            funcs.extend(functions(p))
        c = sum(1 for _, nb in funcs if nb == 0)
        d = len(funcs) - c
        db = sum(nb for _, nb in funcs)
        total_funcs += len(funcs)
        total_c += c
        total_dump += d
        total_bytes += db
        rows.append((seg, size, len(funcs), c, d, db, patches.get(seg, 0)))

    if a.detail:
        print("%-6s %7s %6s %6s %6s %9s %8s" % ("seg", "size", "funcs", "C",
                                                "dump", "dump bytes",
                                                "patches"))
        for seg, size, n, c, d, db, p in rows:
            print("%-6s %7d %6d %6d %6d %9d %8d"
                  % (seg, size, n, c, d, db, p))
    print("modules             %d" % len(rows))
    print("functions           %d" % total_funcs)
    print("C functions         %d (%.0f%%)"
          % (total_c, 100.0 * total_c / max(total_funcs, 1)))
    print("byte-dump functions %d" % total_dump)
    print("dump bytes          %d" % total_bytes)
    print("ov_patch entries    %d" % sum(patches.values()))


if __name__ == "__main__":
    main()
