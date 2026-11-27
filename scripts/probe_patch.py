"""Patch one symbol's entry to `retf` in the rebuilt image and re-sample at the first key read.

Used to test which routine performs a stray DGROUP write: with the routine disabled the sample either
shows the damage (not it) or not (it is).  Usage:

    python tmp/probe_patch.py <symbol> [N]
"""

import io
import os
import re
import struct
import sys

ROOT = r"C:\Users\nangl\d\code\dest"
SYM = sys.argv[1]
NN = sys.argv[2] if len(sys.argv) > 2 else "1"

sys.path.insert(0, os.path.join(ROOT, "scripts"))
_saved_argv = list(sys.argv)
sys.argv = ["dump_at_key.py", NN]
import dump_at_key as harness          # noqa: E402
sys.argv = _saved_argv

MAP = os.path.join(ROOT, "tmp", "buildsrc", "REBUILT.MAP")
EXE = os.path.join(ROOT, "tmp", "buildsrc", "REBUILT.EXE")

exe = open(EXE, "rb").read()
entry_ip, entry_cs = struct.unpack("<HH", exe[0x14:0x18])
text = io.open(MAP, encoding="latin-1", errors="replace").read()
m = re.search(r"([0-9A-F]{4}):([0-9A-F]{4})\s+(?:idle\s+)?_STARTX\s*$", text, re.M)
base = entry_cs - int(m.group(1), 16) if m and int(m.group(2), 16) == entry_ip else None
assert base is not None, "cannot derive the load base"

hits = re.findall(r"^\s*([0-9A-Fa-f]{4}):([0-9A-Fa-f]{4})\s+(?:\S+\s+)?_" + SYM.upper() + r"\s*$",
                  text, re.M)
assert hits, "%s not in the map" % SYM
seg, ofs = int(hits[0][0], 16), int(hits[0][1], 16)
img = struct.unpack("<H", exe[8:10])[0] * 16
off = img + (seg - base) * 16 + ofs
patched = bytearray(exe)
original = bytes(patched[off:off + 4])
patched[off] = 0xCB                    # retf
print("%s at %04x:%04x -> patched %#x (was %s)" % (SYM, seg, ofs, off, original.hex(" ")))

tmp_exe = os.path.join(ROOT, "tmp", "PROBE.EXE")
open(tmp_exe, "wb").write(bytes(patched))
data = harness.run("ours", tmp_exe)
assert data, "no dump"
print("ours 0x1fa..0x206: %s" % data[0x1FA:0x206].hex(" "))
orig = io.open(os.path.join(ROOT, "tmp", "dgrun2_orig", "DGR.BIN"), "rb").read()
print("orig 0x1fa..0x206: %s" % orig[0x1FA:0x206].hex(" "))
print("verdict: %s" % ("clean - this routine is the writer"
                       if data[0x1FA:0x206] == orig[0x1FA:0x206] else "still damaged - not it"))
