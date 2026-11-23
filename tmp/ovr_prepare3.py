"""Call the VROOMM prepare entry from startx, address taken from the map.

The original's startx walks _INITSTART.._INITEND and runs the priority-1 entry,
which is the overlay manager's prepare routine.  In the original that routine is
at 1403:0D24 (SEG_1403_CODE); in our link the same code is the first bytes of
_OVRTEXT_ at offset 0D24.  Both disassemble identically apart from the segment
immediates, which our link resolved to our own _OVRDATA_/DGROUP paragraphs:

    original: mov ax,125Dh (_OVRDATA_) / mov ax,1410h (DGROUP)
    ours    : mov ax,13F9h (_OVRDATA_) / mov ax,163Ah (DGROUP)

so the routine is callable as-is; only the call was missing.

usage: python tmp/ovr_prepare3.py [--revert]
"""
import io
import os
import re
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"
SRC = ROOT + r"\src\decompiled\crtl.c"
MAP = ROOT + r"\tmp\buildsrc\REBUILT.MAP"

if "--revert" in sys.argv:
    subprocess.run(["git", "checkout", "--", SRC], cwd=ROOT, check=False)
    print("reverted")
    raise SystemExit


def ovrtext_para():
    for line in io.open(MAP, encoding="latin-1", errors="replace"):
        m = re.match(r"^\s*([0-9A-F]{5})H\s+([0-9A-F]{5})H\s+([0-9A-F]{5})H\s+_OVRTEXT_\s+CODE",
                     line)
        if m:
            return int(m.group(1), 16) >> 4
    raise SystemExit("_OVRTEXT_ not in the map")


para = ovrtext_para()
print("_OVRTEXT_ paragraph %04X, prepare entry at %04X:0D24" % (para, para))

t = io.open(SRC, encoding="latin-1").read()
anchor = "  /* __setargv is not recovered yet"
assert anchor in t
call = (
    "  /* VROOMM prepare: the original runs this as the priority-1 init-table\n"
    "     entry (1403:0D24 in STRONG.EXE).  Our copy is the first code of\n"
    "     _OVRTEXT_, at offset 0D24; the paragraph comes from the link map and\n"
    "     the load base from the PSP. */\n"
    "  {\n"
    "    uint16_t ovrSeg = (uint16_t)(_psp + 0x10 + 0x%04X);\n\n"
    "    ((void (far *)(void))MK_FP(ovrSeg, 0x0D24))();\n"
    "  }\n\n" % para)
t = t.replace(anchor, call + anchor, 1)
io.open(SRC, "w", encoding="latin-1", newline="\n").write(t)
print("prepare call inserted")

subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "build_standalone.py"),
                "--wait", "3000"], stdout=subprocess.DEVNULL)
subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "link_standalone.py")],
               stdout=subprocess.DEVNULL)
subprocess.run([sys.executable, os.path.join(ROOT, "tmp", "plainrun.py")],
               stdout=subprocess.DEVNULL)
d = os.path.join(ROOT, "tmp", "plainrun")
print("STRONG.SAV:", os.path.exists(os.path.join(d, "STRONG.SAV")))
print("OUT.BIN size:", os.path.getsize(os.path.join(d, "OUT.BIN"))
      if os.path.exists(os.path.join(d, "OUT.BIN")) else "missing")
subprocess.run(["git", "checkout", "--", SRC], cwd=ROOT, check=False)
print("reverted")
