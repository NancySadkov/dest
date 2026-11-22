"""Rename decompiler-named locals that the model cannot name.

`param_00` in ovc49_textLongerParalyzed is a *local*, so param_protos.tsv cannot
reach it.  It is assigned `(uint16_t *)((ulong)agnt >> 0x10)` - the segment half of
the agnt far pointer - and is used as that segment in every nearby CONCAT22, so
`agntSeg`.

usage: python scripts/fix_param_locals.py [--apply]
"""
import io
import re
import sys

apply = "--apply" in sys.argv

# (file, function, old, new, why)
JOBS = [
    ("src/decompiled/ovc49_agents.c", "ovc49_textLongerParalyzed",
     "param_00", "agntSeg", "segment half of the agnt far pointer"),
]

total = 0
for path, fn, old, new, why in JOBS:
    lines = io.open(path, encoding="utf-8", errors="ignore").read().split("\n")
    start = None
    for i, l in enumerate(lines):
        if re.search(r"\b" + fn + r"\s*\(", l) and not l.rstrip().endswith(";"):
            start = i
            break
    if start is None:
        continue
    depth = 0
    started = False
    end = len(lines) - 1
    for k in range(start, len(lines)):
        depth += lines[k].count("{") - lines[k].count("}")
        if "{" in lines[k]:
            started = True
        if started and depth == 0:
            end = k
            break
    n = 0
    for k in range(start, end + 1):
        before = lines[k]
        lines[k] = re.sub(r"\b" + re.escape(old) + r"\b", new, lines[k])
        if lines[k] != before:
            n += 1
    if n:
        total += n
        if apply:
            io.open(path, "w", encoding="utf-8", newline="\n").write("\n".join(lines))

print("local renames applied:", total)
print("mode:", "APPLY" if apply else "dry run")
