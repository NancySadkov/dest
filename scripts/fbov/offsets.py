"""Collect the pointer-offset accesses used in one module.

For every byte offset in [lo, hi) print the distinct source lines that read or
write `base + offset`, so struct fields can be named from what the code does
with them.

Usage: python scripts/fbov/offsets.py tmp/decompiled4/ovc12_agnt.c 0 52
"""
import io
import re
import sys
from collections import OrderedDict

path = sys.argv[1]
lo = int(sys.argv[2], 0)
hi = int(sys.argv[3], 0)
lines = io.open(path, encoding='latin1').read().splitlines()

pat = re.compile(r'\+\s*(0x[0-9a-fA-F]+|\d+)\s*\)')
found = OrderedDict()
for i, line in enumerate(lines):
    for m in pat.finditer(line):
        off = int(m.group(1), 0)
        if not (lo <= off < hi):
            continue
        text = line.strip()
        if len(text) > 150:
            text = text[:150] + '...'
        found.setdefault(off, [])
        if text not in found[off]:
            found[off].append(text)

for off in sorted(found):
    print('+0x%02x' % off)
    for t in found[off][:4]:
        print('    ' + t)
