"""Check the ovr_init_game thunk's far-jump target against O09_SEG.

usage: python tmp/thunk_check.py
"""
import io
import re
import struct

ROOT = r"C:\Users\nangl\d\code\dest"
MAP = ROOT + r"\tmp\buildsrc\REBUILT.MAP"
EXE = ROOT + r"\tmp\buildsrc\REBUILT.EXE"

b = open(EXE, "rb").read()
img = struct.unpack("<H", b[8:10])[0] * 16

# segment table: paragraph -> file start
tbl = {}
for line in io.open(MAP, encoding="latin-1", errors="replace"):
    m = re.match(r"^\s*([0-9A-F]{5})H\s+([0-9A-F]{5})H\s+([0-9A-F]{5})H\s+(\S+)\s+(\S+)", line)
    if m:
        start = int(m.group(1), 16)
        tbl[start >> 4] = (start, m.group(4), m.group(5))

# symbol
s = io.open(MAP, encoding="latin-1", errors="replace").read()
m = re.search(r"([0-9A-F]{4}):([0-9A-F]{4})\s+(?:idle\s+)?_OVR_INIT_GAME\s*$", s, re.M)
if not m:
    raise SystemExit("_OVR_INIT_GAME not in the map")
seg, ofs = int(m.group(1), 16), int(m.group(2), 16)
print("map: _OVR_INIT_GAME %04X:%04X" % (seg, ofs))
if seg not in tbl:
    raise SystemExit("segment %04X not in the segment table" % seg)
start, name, cls = tbl[seg]
print("segment %s starts at file 0x%05X (%s)" % (name, start, cls))

o = start + ofs
print("thunk bytes:", b[img + o:img + o + 8].hex(" "))
if b[img + o] == 0xEA:
    tofs, tseg = struct.unpack("<HH", b[img + o + 1:img + o + 5])
    print("  ljmp %04X:%04X" % (tseg, tofs))
    if tseg in tbl:
        tstart, tname, tcls = tbl[tseg]
        print("  target segment %s at file 0x%05X (%s)" % (tname, tstart, tcls))
        print("  target bytes:", b[img + tstart + tofs:img + tstart + tofs + 8].hex(" "))
    else:
        print("  target segment not in the table")
    n = struct.unpack("<H", b[6:8])[0]
    relofs = struct.unpack("<H", b[0x18:0x1a])[0]
    ents = set(struct.unpack("<HH", b[relofs + 4 * k:relofs + 4 * k + 4])[0]
               for k in range(n))
    print("  segment word at image 0x%x relocated: %s" % (o + 3, (o + 3) in ents))

# O09_SEG from the fresh block table
for line in io.open(ROOT + r"\audit\overlay_blocks.csv", encoding="utf-8"):
    f = line.rstrip("\n").split("\t")
    if len(f) >= 4 and f[0] == "9":
        print("O09_SEG: segment %s, file 0x%s, size %s" % (f[1], f[2], f[3]))
