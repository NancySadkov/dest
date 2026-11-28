"""Compare one function's image call targets with the callees its C body invokes.

This is the instrument that finished `3f0b:1082`: `structural_deficits.py` reports a single delta per
function, which hides *which* target is short.  Here the image's `call`/`lcall` instructions are
resolved to names through `audit/functions_real.tsv` and grouped, and the body's counted callees are
grouped the same way, so a mismatch shows up per target - e.g. `ovr_randBelow 43 vs 31` or
`attact_usesSCARRY2` absent while `func_0x0004f32d` appears instead.

Usage: python scripts/callsite_diff.py <seg>:<ofs> <module.c> [--offsets]

`--offsets` prints every image call site with its address, which is what pins down which of several
same-target calls a body statement corresponds to.

Limitations, the same two the other census tools have: the body side only sees identifiers that
appear in the audit table or start with `ovr_`, and the image side counts instructions, so an
unrolled image loop shows as many sites where the body has one.
"""

import io
import os
import re
import struct
import sys
from collections import Counter

import capstone

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXE = io.open(os.path.join(ROOT, "game", "STRONG.EXE"), "rb").read()
IMG = struct.unpack("<H", EXE[8:10])[0] * 16
MD = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_16)

seg, ofs = (int(x, 16) for x in sys.argv[1].split(":"))
src = sys.argv[2]
SHOW = "--offsets" in sys.argv

names = {}
for line in io.open(os.path.join(ROOT, "audit", "functions_real.tsv"), encoding="latin-1"):
    f = line.rstrip("\n").split("\t")
    if len(f) < 3 or ":" not in f[0]:
        continue
    s, o = (int(x, 16) for x in f[0].split(":"))
    names[(s, o)] = f[1]
    if s == seg and o == ofs:
        size = int(f[2])

windows = {}
for line in io.open(os.path.join(ROOT, "audit", "overlay_segments.csv"), encoding="latin-1"):
    f = line.rstrip("\n").split("\t")
    if len(f) >= 2 and re.match(r"^[0-9a-fA-F]+$", f[0]):
        windows[int(f[0], 16)] = f[1].split(",")

base = IMG + (seg - 0x1000) * 16 + ofs
img = Counter()
for ins in MD.disasm(EXE[base:base + size], ofs):
    if ins.mnemonic == "lcall":
        m = re.match(r"0x([0-9a-f]+), 0x([0-9a-f]+)", ins.op_str)
        if not m:
            continue
        tseg, tofs = int(m.group(1), 16), int(m.group(2), 16)
    elif ins.mnemonic == "call":
        m = re.match(r"0x([0-9a-f]+)", ins.op_str)
        if not m:
            continue
        tseg, tofs = seg, int(m.group(1), 16)
    else:
        continue
    if tseg == 0:
        label = "crt:%s" % names.get((0x1000, tofs), "0x%04x" % tofs)
    elif (tseg, tofs) in names:
        label = names[(tseg, tofs)]
    elif tseg in windows:
        label = "window%03x:%04x" % (tseg, tofs)
    else:
        label = "%04x:%04x" % (tseg, tofs)
    img[label] += 1
    if SHOW:
        print("  %04x  %-32s %s" % (ins.address, label, ins.op_str))

print("image calls (%d):" % sum(img.values()))
for k, v in sorted(img.items()):
    print("  %-34s %d" % (k, v))

body = io.open(os.path.join(ROOT, "src", "decompiled", src), encoding="latin-1").read()
s = body.index("/* %04x:%04x */" % (seg, ofs))
m = re.search(r"/\* [0-9a-f]{4}:[0-9a-f]{4} \*/", body[s + 10:])
nxt = s + 10 + m.start() if m else len(body)
body = re.sub(r"/\*.*?\*/", "", body[s:nxt], flags=re.S)

known = set(names.values())
mine = Counter(mo.group(1) for mo in re.finditer(r"\b([A-Za-z_][A-Za-z0-9_]*)\s*\(", body)
               if mo.group(1) in known or mo.group(1).startswith("ovr_"))
print("\nbody callees (%d):" % sum(mine.values()))
for k, v in sorted(mine.items()):
    print("  %-34s %d" % (k, v))
