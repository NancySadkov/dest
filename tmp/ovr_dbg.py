"""Debug markers that survive a hang: open/seek-end/write/close per marker.

RUN.LOG only grows when the program exits (the shell closes its redirection file
then), so a hanging probe reports 0 bytes even when the write succeeded.  This
helper appends one byte to DBG.TXT and closes it, flushing immediately.

usage: python tmp/ovr_dbg.py [--revert]
"""
import io
import os
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"
SRC = os.path.join(ROOT, "src", "decompiled", "crtl.c")
GLOB = os.path.join(ROOT, "src", "decompiled", "st_globals5.c")
HDR = os.path.join(ROOT, "src", "decompiled", "st_globals.h")

if "--revert" in sys.argv:
    subprocess.run(["git", "checkout", "--", SRC, GLOB, HDR], cwd=ROOT, check=False)
    print("reverted")
    raise SystemExit

HELPER = '''
/* Append one debug byte to DBG.TXT and close it, so the byte survives a hang. */
static char dbgName[] = "DBG.TXT";
static char dbgCh;
void st_dbg(char c)
{
  uint16_t h = 0;
  uint16_t need_create = 0;
  uint16_t fl = 0;

  dbgCh = c;
  asm {
    mov ax,seg dbgName;
    mov ds,ax;
    mov dx,offset dbgName;
    mov ax,3D02h;
    int 21h;
    mov h,ax;
    pushf;
    pop ax;
    and ax,1;
    mov need_create,ax;
  }
  if (need_create) {
    asm {
      mov cx,0;
      mov ah,3Ch;
      mov dx,offset dbgName;
      int 21h;
      mov h,ax;
    }
  }
  asm {
    mov bx,h;
    mov ax,4202h;
    xor cx,cx;
    xor dx,dx;
    int 21h;
    mov bx,h;
    mov dx,offset dbgCh;
    mov cx,1;
    mov ah,40h;
    int 21h;
    pushf;
    pop ax;
    and ax,1;
    mov fl,ax;
    mov bx,h;
    mov ah,3Eh;
    int 21h;
  }
  if (fl) {
    st_dbg('!');
  }
}
'''

t = io.open(SRC, encoding="latin-1").read()
if "st_dbg" not in t:
    t = t.replace("void startx(void)", HELPER + "\nvoid startx(void)", 1)
    t = t.replace('#include "recovered.h"',
                  '#include "recovered.h"\n\n'
                  'int __cdecl16far _OVRINIT(char far *exename, uint16_t bufend, uint16_t bufbeg);',
                  1)
    a = "  /* __setargv is not recovered yet"
    block = (
        "  {\n"
        "    uint16_t bufseg = 0;\n"
        "    uint16_t fl = 0;\n"
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
        "  }\n\n")
    t = t.replace(a, block + a, 1)
    io.open(SRC, "w", encoding="latin-1", newline="\n").write(t)
print("debug helper and _OVRINIT block inserted")

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
d = open(os.path.join(ROOT, "tmp", "runcode", "RUN.LOG"), "rb").read()
first = [l for l in d.splitlines() if l.startswith(b"CODE=")]
print("result ->", first[0].decode() if first else "no code (hang)")
dbg = os.path.join(ROOT, "tmp", "runcode", "DBG.TXT")
print("DBG.TXT:", open(dbg, "rb").read() if os.path.exists(dbg) else "missing")
print("STRONG.SAV", os.path.exists(os.path.join(ROOT, "tmp", "runcode", "STRONG.SAV")))
