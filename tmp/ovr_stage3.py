"""Mark only verified instruction starts inside the manager's loader.

Previous stage markers used offsets copied from another build's disassembly and
landed mid-instruction, which corrupted the flow and triggered the manager's
`ljmp 0:0x2AE` path (observable as a duplicate `I` after a reboot).

This disassembles `_OVRTEXT_ + 0x59F` in the *same* build that is probed and
places one `CD 60` marker at each instruction start.

usage: python tmp/ovr_stage3.py [--revert]
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
MAIN = os.path.join(ROOT, "src", "decompiled", "main.c")
GLOB = os.path.join(ROOT, "src", "decompiled", "st_globals5.c")
HDR = os.path.join(ROOT, "src", "decompiled", "st_globals.h")

if "--revert" in sys.argv:
    subprocess.run(["git", "checkout", "--", SRC, MAIN, GLOB, HDR], cwd=ROOT, check=False)
    print("reverted")
    raise SystemExit

spec = io.open(os.path.join(ROOT, "tmp", "ovr_dbg.py"), encoding="utf-8").read()
HELPER = spec.split("HELPER = '''")[1].split("'''")[0]

PROBE = '''
/* INT 60h probe: mark and spin so the marker survives the hang. */
void st_probe60(void)
{
  st_dbg('X');
  for (;;) {
  }
}
'''

t = io.open(SRC, encoding="latin-1").read()
if "st_dbg" not in t:
    t = t.replace("void startx(void)", HELPER + PROBE + "\nvoid startx(void)", 1)
    t = t.replace('#include "recovered.h"',
                  '#include "recovered.h"\n\n'
                  'int __cdecl16far _OVRINIT(char far *exename, uint16_t bufend, uint16_t bufbeg);',
                  1)
    a = "  /* __setargv is not recovered yet"
    block = (
        "  {\n"
        "    uint16_t bufseg = 0, fl = 0;\n"
        "    uint16_t pofs = (uint16_t)st_probe60;\n"
        "    int rc;\n\n"
        "    asm {\n"
        "      mov ah,48h;\n"
        "      mov bx,2000h;\n"
        "      int 21h;\n"
        "      mov bufseg,ax;\n"
        "      pushf;\n"
        "      pop ax;\n"
        "      mov fl,ax;\n"
        "    }\n"
        "    st_dbg((char)('A' + (fl & 1)));\n"
        "    rc = _OVRINIT((char far *)\"STRONG.EXE\",\n"
        "                  (uint16_t)(bufseg + 0x2000), bufseg);\n"
        "    st_dbg((char)('0' + (rc & 7)));\n"
        "    asm {\n"
        "      cli;\n"
        "      xor ax,ax;\n"
        "      mov es,ax;\n"
        "      mov ax,pofs;\n"
        "      mov word ptr es:[180h],ax;\n"
        "      mov word ptr es:[182h],cs;\n"
        "      sti;\n"
        "    }\n"
        "  }\n\n")
    t = t.replace(a, block + a, 1)
    io.open(SRC, "w", encoding="latin-1", newline="\n").write(t)

s = io.open(HDR, encoding="latin-1").read()
if "st_dbg" not in s:
    s = s.replace("extern uint16_t GRecordCount;",
                  "extern uint16_t GRecordCount;\nvoid st_dbg(char c);", 1)
    io.open(HDR, "w", encoding="latin-1", newline="").write(s)

m = io.open(MAIN, encoding="latin-1").read()
if "st_dbg" not in m:
    i = m.index("  ovr_init_game();")
    m = m[:i] + "  st_dbg('I');\n" + m[i:]
    io.open(MAIN, "w", encoding="latin-1", newline="\n").write(m)

subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "build_standalone.py"),
                "--wait", "3000"], stdout=subprocess.DEVNULL)
rows = [l.rstrip("\n").split("\t")
        for l in io.open(os.path.join(ROOT, "tmp", "build_report.tsv"), encoding="utf-8")][1:]
print("clean %d errors %d" % (sum(1 for r in rows if r[1] == "ok"),
                              sum(int(r[2]) for r in rows)))
for r in rows:
    if r[1] != "ok":
        print(" ", r[0], r[4][:120])
subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "link_standalone.py")],
               stdout=subprocess.DEVNULL)

base_exe = open(EXE, "rb").read()
img = struct.unpack("<H", base_exe[8:10])[0] * 16
mm = re.search(r"^\s*([0-9A-F]{5})H\s+([0-9A-F]{5})H\s+([0-9A-F]{5})H\s+_OVRTEXT_\s+CODE",
               io.open(MAP, encoding="latin-1", errors="replace").read(), re.M)
ovrbase = (int(mm.group(1), 16) >> 4) * 16

from capstone import Cs, CS_ARCH_X86, CS_MODE_16
md = Cs(CS_ARCH_X86, CS_MODE_16)
start = ovrbase + 0x59F
ins = list(md.disasm(base_exe[img + start:img + start + 0x50], start))
print("_OVRTEXT_ base 0x%x, loader 0x%x" % (ovrbase, start))
starts = [(("%05x %s %s" % (i.address, i.mnemonic, i.op_str))[:40], i.address - start)
          for i in ins[:9]]

for label, off in starts:
    b = bytearray(base_exe)
    b[img + start + off:img + start + off + 2] = b"\xcd\x60"
    open(EXE, "wb").write(b)
    subprocess.run([sys.executable, os.path.join(ROOT, "tmp", "exact_code.py")],
                   stdout=subprocess.DEVNULL)
    dbg = os.path.join(ROOT, "tmp", "runcode", "DBG.TXT")
    d = open(dbg, "rb").read() if os.path.exists(dbg) else b""
    print("+0x%03X %-38s -> %s" % (off, label, d))

open(EXE, "wb").write(base_exe)
