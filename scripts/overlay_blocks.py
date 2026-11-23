"""List the overlay blocks of the linked REBUILT.EXE.

TLINK -V writes each overlay block after the resident image; the map lists each
block segment with its absolute start (the file offset) and length.  This prints
the table an overlay loader would need: block id, segment, file offset, size.

usage: python scripts/overlay_blocks.py [out.csv]
"""
import io
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MAP = os.path.join(ROOT, "tmp", "buildsrc", "REBUILT.MAP")

rows = []
for line in io.open(MAP, encoding="latin-1", errors="replace"):
    m = re.match(r"^\s*([0-9A-F]{5})H\s+([0-9A-F]{5})H\s+([0-9A-F]{5})H\s+O(\d+)_SEG\s+(\S+)",
                 line)
    if not m:
        continue
    start = int(m.group(1), 16)
    length = int(m.group(3), 16)
    if not length:
        continue
    rows.append((int(m.group(4)), start >> 4, start, length, m.group(5)))

rows.sort()
out = sys.argv[1] if len(sys.argv) > 1 else None
if out:
    with io.open(out, "w", encoding="utf-8", newline="\n") as f:
        f.write("id\tsegment\tfile_offset\tsize\tclass\n")
        for i, seg, start, length, cls in rows:
            f.write("%d\t%04X\t0x%05X\t%d\t%s\n" % (i, seg, start, length, cls))
print("overlay blocks: %d, total %d bytes" % (len(rows), sum(r[3] for r in rows)))
for i, seg, start, length, cls in rows[:8]:
    print("  O%02d  %04X  file 0x%05X  %5d bytes  %s" % (i, seg, start, length, cls))
