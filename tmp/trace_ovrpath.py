"""Did __OVRINIT fail to open the exe, or get past it?

__OVRINIT's shape (current build, relative to its entry):
  +0x19  cmp word ptr [0xa0],0     ; __OVRTRAP__ present?
  +0x1E  call __OvrExeOpenEnv
  +0x30  call __OvrExeOpenFilename
  +0x35  call __OvrExeOpenEnvPath
  +0x3A  mov ax,0xfffe             ; INIT_NOEXE  (all three opens failed)
  +0x4A  success path              ; handle stored, FBOV search follows

usage: python tmp/trace_ovrpath.py
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

ns = {}
exec(io.open(os.path.join(ROOT, "tmp", "trace60.py"), encoding="utf-8")
     .read().split("install()\nbuild()")[0], ns)


def revert():
    subprocess.run(["git", "checkout", "--", SRC, GLOB, HDR], cwd=ROOT, check=False)


ns["install"]()
t = io.open(SRC, encoding="latin-1").read()
t = t.replace('#include "recovered.h"',
              '#include "recovered.h"\n\n'
              'int __cdecl16far _OVRINIT(char *exename, uint16_t bufend, uint16_t bufbeg);', 1)
a = "  /* __setargv is not recovered yet"
t = t.replace(a,
              "  {\n"
              "    uint16_t bufseg = 0;\n"
              "    asm { mov ah,0x48; mov bx,0x4000; int 21h; mov bufseg,ax }\n"
              "    _OVRINIT(0, (uint16_t)(bufseg + 0x4000), bufseg);\n"
              "  }\n\n" + a, 1)
io.open(SRC, "w", encoding="latin-1", newline="\n").write(t)
ns["build"]()

s = io.open(MAP, encoding="latin-1", errors="replace").read()
seg, ofs = re.findall(r"([0-9A-F]{4}):([0-9A-F]{4})\s+(?:idle\s+)?__OVRINIT\s*$", s, re.M)[-1]
entry = int(seg, 16) * 16 + int(ofs, 16)
base = open(EXE, "rb").read()
img = struct.unpack("<H", base[8:10])[0] * 16
print("__OVRINIT 0x%x" % entry)

from capstone import Cs, CS_ARCH_X86, CS_MODE_16
md = Cs(CS_ARCH_X86, CS_MODE_16)
ins = list(md.disasm(base[img + entry:img + entry + 0x60], entry))
want = {}
for i in ins:
    if i.mnemonic == "mov" and "0xfffe" in i.op_str:
        want["INIT_NOEXE"] = i.address
    if i.mnemonic == "call":
        want.setdefault("call%d" % len(want), i.address)
print("points:", {k: hex(v) for k, v in want.items()})

for label, t in list(want.items())[:5]:
    print("%-10s 0x%-6x -> %s" % (label, t, ns["run"](base, img, t)))

open(EXE, "wb").write(base)
revert()
ns["build"]()
print("reverted and rebuilt")
