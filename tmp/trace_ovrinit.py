"""Trace how far __OVRINIT gets, using INT 60h markers.

Builds with the INT 60h handler and a direct _OVRINIT call installed, then marks
instruction boundaries inside __OVRINIT one at a time.  The last address that
reports CODE=80 is where the manager stops.

usage: python tmp/trace_ovrinit.py
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
SRC = os.path.join(ROOT, "src", "decompiled", "crtl.c")
GLOB = os.path.join(ROOT, "src", "decompiled", "st_globals5.c")
HDR = os.path.join(ROOT, "src", "decompiled", "st_globals.h")

sys.path.insert(0, os.path.join(ROOT, "tmp"))
ns = {}
exec(io.open(os.path.join(ROOT, "tmp", "trace60.py"), encoding="utf-8")
     .read().split("install()\nbuild()")[0], ns)


def revert():
    subprocess.run(["git", "checkout", "--", SRC, GLOB, HDR], cwd=ROOT, check=False)


# install the INT 60h handler (from trace60) and the _OVRINIT call
ns["install"]()
t = io.open(SRC, encoding="latin-1").read()
t = t.replace('#include "recovered.h"',
              '#include "recovered.h"\n\n'
              'int __cdecl16far _OVRINIT(char *exename, uint16_t bufend, uint16_t bufbeg);', 1)
a = "  /* __setargv is not recovered yet"
call = ("  {\n"
        "    uint16_t bufseg = 0;\n"
        "    asm { mov ah,0x48; mov bx,0x4000; int 21h; mov bufseg,ax }\n"
        "    _OVRINIT(0, (uint16_t)(bufseg + 0x4000), bufseg);\n"
        "  }\n\n")
t = t.replace(a, call + a, 1)
io.open(SRC, "w", encoding="latin-1", newline="\n").write(t)
ns["build"]()

s = io.open(MAP, encoding="latin-1", errors="replace").read()
m = re.findall(r"([0-9A-F]{4}):([0-9A-F]{4})\s+(?:idle\s+)?__OVRINIT\s*$", s, re.M)
seg, ofs = m[-1]
entry = int(seg, 16) * 16 + int(ofs, 16)
base = open(EXE, "rb").read()
img = struct.unpack("<H", base[8:10])[0] * 16
print("__OVRINIT at image 0x%x" % entry)

from capstone import Cs, CS_ARCH_X86, CS_MODE_16
md = Cs(CS_ARCH_X86, CS_MODE_16)
ins = list(md.disasm(base[img + entry:img + entry + 0x120], entry))
targets = [entry]
for i in ins:
    if i.mnemonic in ("call", "lcall") and len(targets) < 9:
        targets.append(i.address)
print("probe points:", [hex(t) for t in targets])

for t in targets:
    print("0x%-6x -> %s" % (t, ns["run"](base, img, t)))

open(EXE, "wb").write(base)
revert()
ns["build"]()
print("reverted and rebuilt")
