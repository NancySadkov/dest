#!/usr/bin/env python3
"""Create the layout-preserving VROOMM baseline.

All recovered code regions and DGROUP are byte-exact against the original, so
the first VROOMM-mode build is the original load module + FBOV trailer.  This
script stages that image (and the game data) and verifies the static layout
before it is handed to the original VROOMM manager.

Function substitution happens later by compiling a recovered function,
verifying it against the original bytes (call operands masked), relocating its
far references to the original segment addresses, and patching the matching
overlay blob in the staged EXE.  Because the FBOV file offsets and overlay
header entries stay unchanged, VROOMM keeps loading the same overlays.
"""
import os
import shutil
import struct

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
GAME = os.path.join(ROOT, "game")
OUT = os.path.join(ROOT, "tmp", "vroomm")
os.makedirs(OUT, exist_ok=True)

src = os.path.join(GAME, "STRONG.EXE")
dst = os.path.join(OUT, "STRONG.EXE")
shutil.copyfile(src, dst)

# sanity: original MZ/FBOV markers
d = open(dst, "rb").read()
h = struct.unpack_from("<14H", d, 0)
assert h[0] == 0x5A4D
load = h[4] * 16
assert d[load:load + 3] == b"\xBA\x10\x14", "resident startup not at load base"
assert len(d) == 511280

for name in ("STRONG.DAT", "STRONG.FLI"):
    s = os.path.join(GAME, name)
    if os.path.exists(s):
        shutil.copyfile(s, os.path.join(OUT, name))

sav = os.path.join(OUT, "STRONG.SAV")
os.makedirs(sav, exist_ok=True)
gsav = os.path.join(GAME, "STRONG.SAV")
if os.path.isdir(gsav):
    for f in os.listdir(gsav):
        shutil.copyfile(os.path.join(gsav, f), os.path.join(sav, f))

print("staged VROOMM baseline in", OUT, "(%d bytes)" % len(d))
