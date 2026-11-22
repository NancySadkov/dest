"""Emit the non-DGROUP data as far data, as the original modules did.

The original image has one data segment per module (195d_DATA_entity.c,
17f8_DATA_game4, 1539_DATA_game1, ...).  Turbo C++ 3.0 accepts far data objects
(`int far x;` compiles), so those tables are declared `far` and land in _FARDATA
instead of _DATA, exactly like the original.

Input: scripts/model/far_data.tsv (name, original segment, note)

usage: python scripts/fix_far_data.py [--apply]
"""
import io
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TSV = os.path.join(HERE, "model", "far_data.tsv")
HEADER = "src/decompiled/st_globals.h"
BODIES = ("src/decompiled/st_globals.c", "src/decompiled/st_globals2.c")

apply = "--apply" in sys.argv

names = []
seg = {}
for line in io.open(TSV, encoding="utf-8"):
    line = line.rstrip("\n")
    if not line or line.startswith("#"):
        continue
    parts = line.split("\t")
    if len(parts) < 2:
        continue
    names.append(parts[0])
    seg[parts[0]] = parts[1]

print("far data symbols:", len(names))

# HEADER: extern <type> <name>[...];  ->  extern <type> far <name>[...];
done_h = []
skipped = []
lines = io.open(HEADER, encoding="utf-8", errors="ignore").read().split("\n")
for i, line in enumerate(lines):
    m = re.match(r"^extern\s+(.*?)([A-Za-z_]\w*)\s*((?:\[[^\]]*\])+)\s*;\s*$", line)
    if not m or m.group(2) not in names:
        continue
    base, name, dims = m.group(1).strip(), m.group(2), m.group(3)
    if base.endswith("*"):
        skipped.append(name)          # `T *name[]`: `far` would retype the element
        continue
    lines[i] = "extern %s far %s%s;" % (base, name, dims)
    done_h.append(name)

# BODIES: <type> <name>[...] = ...  ->  <type> far <name>[...] = ...
done_b = []
for path in BODIES:
    src = io.open(path, encoding="utf-8", errors="ignore").read().split("\n")
    for i, line in enumerate(src):
        m = re.match(r"^([A-Za-z_][\w ]*?)\s+([A-Za-z_]\w*)\s*((?:\[[^\]]*\])+)\s*=", line)
        if not m or m.group(2) not in names:
            continue
        base, name, dims = m.group(1).strip(), m.group(2), m.group(3)
        if base.endswith("*"):
            continue
        src[i] = "%s far %s%s =%s" % (base, name, dims, line[m.end():])
        done_b.append(name)
    if apply:
        io.open(path, "w", encoding="utf-8", newline="\n").write("\n".join(src))

print("header declarations converted:", len(done_h))
print("definitions converted:", len(done_b), "in", len(BODIES), "files")
if skipped:
    print("skipped (pointer element type):", ", ".join(sorted(set(skipped))))
missing = sorted(set(names) - set(done_b))
if missing:
    print("NOT converted (no definition matched):", ", ".join(missing))
if apply:
    io.open(HEADER, "w", encoding="utf-8", newline="\n").write("\n".join(lines))
print("mode:", "APPLY" if apply else "dry run")
