"""Dump the installed INT 3Fh handler address (relative to our CS) to DBG.TXT.

CS is CRTL_SEG, which the map lists as paragraph 006C, so

    handler map paragraph = 0x6C + (vecSeg - cs)
    handler map offset    = vecOfs

gives the image offset to disassemble.  Six hex digits are appended to DBG.TXT
after the usual markers.

usage: python tmp/ovr_vecaddr.py [--revert]
"""
import io
import os
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"
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

HEXOUT = '''
static void st_dbg_hex(uint16_t v, int digits)
{
  int i;
  char d;

  for (i = digits - 1; i >= 0; i--) {
    d = (char)((v >> (i * 4)) & 0xF);
    st_dbg((char)(d < 10 ? '0' + d : 'A' + d - 10));
  }
}
'''

t = io.open(SRC, encoding="latin-1").read()
if "st_dbg" not in t:
    t = t.replace("void startx(void)", HELPER + HEXOUT + "\nvoid startx(void)", 1)
    t = t.replace('#include "recovered.h"',
                  '#include "recovered.h"\n\n'
                  'int __cdecl16far _OVRINIT(char far *exename, uint16_t bufend, uint16_t bufbeg);',
                  1)
    a = "  /* __setargv is not recovered yet"
    block = (
        "  {\n"
        "    uint16_t bufseg = 0, fl = 0, csval = 0;\n"
        "    uint16_t viofs = 0, viseg = 0;\n"
        "    int rc;\n\n"
        "    asm { mov ax,cs; mov csval,ax }\n"
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
        "      mov ax,0;\n"
        "      mov es,ax;\n"
        "      mov ax,es:[0FCh];\n"
        "      mov viofs,ax;\n"
        "      mov ax,es:[0FEh];\n"
        "      mov viseg,ax;\n"
        "    }\n"
        "    st_dbg('#');\n"
        "    st_dbg_hex((uint16_t)(viseg - csval), 4);\n"
        "    st_dbg_hex(viofs, 4);\n"
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
print("vector address dump inserted")

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
subprocess.run([sys.executable, os.path.join(ROOT, "tmp", "exact_code.py")],
               stdout=subprocess.DEVNULL)
dbg = os.path.join(ROOT, "tmp", "runcode", "DBG.TXT")
print("DBG.TXT:", open(dbg, "rb").read() if os.path.exists(dbg) else "missing")
