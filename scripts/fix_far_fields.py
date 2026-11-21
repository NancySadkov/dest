"""Write 4-byte pointers as `T far *` in the generated type header.

DataTypeWriter prints a bare `*` for every pointer, so a struct that embeds a
far pointer comes out 2 bytes shorter per far field: `agnt_t` has frames, entity
and gdata as 4-byte pointers in the model (offsets 19, 23, 29, total size 52),
but the header declared them as 2-byte near pointers and the compiler saw 46
bytes - against an array stride of 0x34 = 52.  Every `[i].base.` site then
indexes 6 bytes early.

ExportRecovered writes st_far_fields.tsv (struct, field) from the model; this
script inserts `far` on exactly those declarations.  Turbo C keeps `far`
pointers at 4 bytes and the compiler is invoked with -a- (byte alignment), so the
field offsets then match the model exactly.

usage: python scripts/fix_far_fields.py [--apply]
"""
import io
import os
import sys

TYPES = "src/decompiled/st_types.h"
TSV = "src/decompiled/st_far_fields.tsv"

if not os.path.isfile(TSV):
    print("no far-field table:", TSV)
    raise SystemExit(0)

fields = {}
for line in io.open(TSV, encoding="utf-8"):
    p = line.rstrip("\n").split("\t")
    if len(p) < 2 or p[0] == "struct":
        continue
    fields.setdefault(p[0], set()).add(p[1])
print("structs with far fields:", len(fields),
      "fields:", sum(len(v) for v in fields.values()))

lines = io.open(TYPES, encoding="utf-8", errors="ignore").read().split("\n")
cur = None
changed = 0
for i, line in enumerate(lines):
    s = line.strip()
    if s.startswith("struct ") and "{" in s:
        # the opener may carry a trailing comment: `struct X { /* ... */`
        head = s[len("struct "):s.index("{")].strip()
        cur = head
        continue
    if s.startswith("}"):
        cur = None
        continue
    if cur not in fields:
        continue
    for f in fields[cur]:
        # `TYPE *field;` / `TYPE *field[N];`  ->  `TYPE far *field...`
        marker = "*" + f
        if marker not in line:
            continue
        idx = line.find(marker)
        if line[:idx].rstrip().endswith(" far"):
            continue
        lines[i] = line[:idx].rstrip() + " far " + line[idx:]
        changed += 1
        break

print("declarations rewritten:", changed)
if "--apply" in sys.argv:
    io.open(TYPES, "w", encoding="utf-8", newline="\n").write("\n".join(lines))
    print("mode: APPLY")
else:
    print("mode: dry run")
