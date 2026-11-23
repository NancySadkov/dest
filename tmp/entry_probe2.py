"""NO_OVERLAY entry probe: derive the entry segment from the image, not the map.

1. find startx's prologue in the image;
2. find the map's segment range that contains that image offset;
3. patch CS:IP = (range start paragraph, offset within it);
4. put an exit-42 stub at the prologue.

usage: python tmp/entry_probe2.py
"""
import io
import os
import re
import struct
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"
EXE = os.path.join(ROOT, "tmp", "buildsrc", "REBUILT.EXE")
MAP = os.path.join(ROOT, "tmp", "buildsrc", "REBUILT.MAP")
PAT = bytes.fromhex("558bec83ec1c5657b89400")

b = bytearray(open(EXE, "rb").read())
hdr = struct.unpack("<H", b[8:10])[0] * 16
i = b.find(PAT, hdr)
if i < 0:
    raise SystemExit("prologue not found")
img = i - hdr
print("prologue at image 0x%x" % img)

ranges = []
for line in io.open(MAP, encoding="latin-1", errors="replace"):
    m = re.match(r"^\s*([0-9A-F]{5})H\s+([0-9A-F]{5})H\s+([0-9A-F]{5})H\s+(\S+)", line)
    if not m:
        continue
    start, end = int(m.group(2), 16), int(m.group(1), 16)
    if start <= img < end:
        ranges.append((start, end, m.group(4)))

if not ranges:
    raise SystemExit("no segment contains image 0x%x" % img)
start, end, name = ranges[0]
print("segment %s: 0x%x..0x%x" % (name, start, end))
seg = start >> 4
ip = img - start
print("entry %04X:%04X" % (seg, ip))

struct.pack_into("<HH", b, 0x14, ip, seg)
b[i:i + 5] = bytes.fromhex("b8424ccd21")
open(EXE, "wb").write(b)

subprocess.run([sys.executable, os.path.join(ROOT, "tmp", "exact_code.py")],
               check=False)
