"""Build a naming worklist for the auto-named globals.

For each global whose name is still generated (byte_2000_BSS_00xx, ...), report
how often the recovered code references it and quote the first few uses, so the
name can be chosen from evidence instead of guessed.

Usage: python scripts/fbov/worklist_globals.py [--export tmp/decompiled4]
"""
import argparse
import collections
import csv
import glob
import io
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--export", default=os.path.join(ROOT, "tmp", "decompiled4"))
    ap.add_argument("--audit", default=os.path.join(ROOT, "tmp", "auditn",
                                                   "naming_globals.tsv"))
    ap.add_argument("--out", default=os.path.join(ROOT, "tmp",
                                                  "worklist_globals.tsv"))
    a = ap.parse_args()

    names = {}
    for r in csv.DictReader(io.open(a.audit, encoding="utf-8"), delimiter="\t"):
        names[r["name"]] = r

    refs = collections.Counter()
    samples = collections.defaultdict(list)
    pat = re.compile(r"\b(%s)\b" % "|".join(re.escape(n) for n in names))
    for path in sorted(glob.glob(os.path.join(a.export, "*.c"))):
        mod = os.path.basename(path)[:-2]
        for line in io.open(path, encoding="latin1"):
            for m in pat.finditer(line):
                n = m.group(1)
                refs[n] += 1
                if len(samples[n]) < 3:
                    samples[n].append("%s: %s" % (mod, line.strip()[:120]))

    rows = []
    for n, r in names.items():
        rows.append((refs[n], n, r["type"], r["address"],
                     " | ".join(samples[n])))
    rows.sort(key=lambda x: -x[0])

    with io.open(a.out, "w", encoding="utf-8", newline="") as f:
        f.write("refs\tname\ttype\taddress\tsamples\n")
        for row in rows:
            f.write("\t".join(str(x) for x in row) + "\n")
    print("wrote %d globals to %s" % (len(rows), a.out))
    print("named in code: %d of %d" % (sum(1 for r in rows if r[0]), len(rows)))


if __name__ == "__main__":
    sys.exit(main())
