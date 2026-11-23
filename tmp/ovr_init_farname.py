"""__OVRINIT failed with INIT_NOEXE: all three exe opens failed.

The tracer reached `mov ax,0xfffe` (INIT_NOEXE), so the manager never opened our
own EXE.  Two causes:

* `__OvrExeOpenFilename` uses `__EXENAME__`, which C0 fills from argv[0]; our
  __setargv is a stub, so it is empty;
* the `exename` argument is a **far** pointer (the routine reads [bp+6]/[bp+8]
  as ofs:seg), but the earlier prototype declared `char *` - in medium model that
  is near, so the segment half was garbage.

This passes a proper far pointer to a DGROUP string.

usage: python tmp/ovr_init_farname.py [--revert]
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

t = io.open(SRC, encoding="latin-1").read()
if "_OVRINIT" not in t:
    t = t.replace('#include "recovered.h"',
                  '#include "recovered.h"\n\n'
                  'int __cdecl16far _OVRINIT(char far *exename, uint16_t bufend, uint16_t bufbeg);',
                  1)
    a = "  /* __setargv is not recovered yet"
    call = (
        "  /* VROOMM: the manager opens the exe by name; __EXENAME__ is empty\n"
        "     because __setargv is not recovered, so pass the name explicitly.\n"
        "     The argument is a far pointer (the routine reads ofs:seg). */\n"
        "  {\n"
        "    uint16_t bufseg = 0;\n"
        "    uint16_t ok = 1;\n"
        "    int rc;\n\n"
        "    asm {\n"
        "      mov ah,0x48;\n"
        "      mov bx,0x2000;\n"
        "      int 21h;\n"
        "      mov bufseg,ax;\n"
        "      pushf;\n"
        "      pop ax;\n"
        "      mov ok,ax;\n"
        "    }\n"
        "    st_traceCh = (char)('0' + (ok & 1));\n"
        "    asm { mov bx,1; mov dx,offset st_traceCh; mov cx,1; mov ah,0x40; int 21h };\n"
        "    if ((ok & 1) == 0) {\n"
        "      rc = _OVRINIT((char far *)\"STRONG.EXE\",\n"
        "                    (uint16_t)(bufseg + 0x2000), bufseg);\n"
        "      st_ovrRc = rc;\n"
        "      st_traceCh = (char)(rc + 0x30);\n"
        "      asm { mov bx,1; mov dx,offset st_traceCh; mov cx,1; mov ah,0x40; int 21h };\n"
        "    }\n"
        "  }\n\n")
    t = t.replace(a, call + a, 1)
    io.open(SRC, "w", encoding="latin-1", newline="\n").write(t)

s = io.open(GLOB, encoding="latin-1").read()
if "st_ovrRc" not in s:
    s = s.replace("uint16_t GRecordCount = 0x0000;",
                  "uint16_t GRecordCount = 0x0000;\nint st_ovrRc;\nvolatile char st_traceCh;", 1)
    io.open(GLOB, "w", encoding="latin-1", newline="").write(s)
s = io.open(HDR, encoding="latin-1").read()
if "st_ovrRc" not in s:
    s = s.replace("extern uint16_t GRecordCount;",
                  "extern uint16_t GRecordCount;\nextern int st_ovrRc;\n"
                  "extern volatile char st_traceCh;", 1)
    io.open(HDR, "w", encoding="latin-1", newline="").write(s)
print("far-name _OVRINIT call inserted")

subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "build_standalone.py"),
                "--wait", "3000"], stdout=subprocess.DEVNULL)
rows = [l.rstrip("\n").split("\t")
        for l in io.open(os.path.join(ROOT, "tmp", "build_report.tsv"), encoding="utf-8")][1:]
print("clean %d errors %d" % (sum(1 for r in rows if r[1] == "ok"),
                              sum(int(r[2]) for r in rows)))
for r in rows:
    if r[1] != "ok":
        print(" ", r[0], r[4][:110])
subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "link_standalone.py")],
               stdout=subprocess.DEVNULL)
subprocess.run([sys.executable, os.path.join(ROOT, "tmp", "exact_code.py")],
               stdout=subprocess.DEVNULL)
d = open(os.path.join(ROOT, "tmp", "runcode", "RUN.LOG"), "rb").read()
first = [l for l in d.splitlines() if l.startswith(b"CODE=")]
print("result ->", first[0].decode() if first else "no code (hang)")
print("RUN.LOG head:", d[:16])
print("STRONG.SAV", os.path.exists(os.path.join(ROOT, "tmp", "runcode", "STRONG.SAV")))
