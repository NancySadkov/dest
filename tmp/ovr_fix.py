"""Give VROOMM a name it can open, with working instrumentation.

Two earlier problems are fixed here:
* BCC's inline assembler rejects `0xNNh` when a hex letter precedes the `h`
  (e.g. 0x4c5ah) - that silently broke a build and made a probe look like a
  hang.  Plain `4C5Ah` form is used.
* DS is set explicitly before every AH=40h write, so the marker cannot depend on
  whatever _c0crtinit left in DS.

The manager's `exename` argument is a FAR pointer ([bp+6]/[bp+8] = ofs:seg), so
the prototype is `char far *` and the name is a DGROUP string.

usage: python tmp/ovr_fix.py [--revert]
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

s = io.open(GLOB, encoding="latin-1").read()
if "st_traceCh" not in s:
    s = s.replace("uint16_t GRecordCount = 0x0000;",
                  "uint16_t GRecordCount = 0x0000;\nvolatile char st_traceCh;", 1)
    io.open(GLOB, "w", encoding="latin-1", newline="").write(s)
s = io.open(HDR, encoding="latin-1").read()
if "st_traceCh" not in s:
    s = s.replace("extern uint16_t GRecordCount;",
                  "extern uint16_t GRecordCount;\nextern volatile char st_traceCh;", 1)
    io.open(HDR, "w", encoding="latin-1", newline="").write(s)

WRITE = ("  asm {\n"
         "    mov ax,seg st_traceCh;\n"
         "    mov ds,ax;\n"
         "    mov bx,1;\n"
         "    mov dx,offset st_traceCh;\n"
         "    mov cx,1;\n"
         "    mov ah,40h;\n"
         "    int 21h;\n"
         "  }\n")

t = io.open(SRC, encoding="latin-1").read()
t = t.replace('#include "recovered.h"',
              '#include "recovered.h"\n\n'
              'int __cdecl16far _OVRINIT(char far *exename, uint16_t bufend, uint16_t bufbeg);',
              1)
a = "  /* __setargv is not recovered yet"
block = (
    "  /* VROOMM: __OVRINIT could not open the exe (INIT_NOEXE) because\n"
    "     __EXENAME__ is empty; pass a far pointer to a DGROUP name instead. */\n"
    "  {\n"
    "    uint16_t bufseg = 0;\n"
    "    uint16_t flags = 0;\n"
    "    int rc;\n\n"
    "    asm {\n"
    "      mov ah,48h;\n"
    "      mov bx,2000h;\n"
    "      int 21h;\n"
    "      mov bufseg,ax;\n"
    "      pushf;\n"
    "      pop ax;\n"
    "      mov flags,ax;\n"
    "    }\n"
    "    st_traceCh = (char)('A' + (flags & 1));\n" + WRITE +
    "    rc = _OVRINIT((char far *)\"STRONG.EXE\",\n"
    "                  (uint16_t)(bufseg + 0x2000), bufseg);\n"
    "    st_traceCh = (char)('0' + (rc & 7));\n" + WRITE +
    "  }\n\n")
t = t.replace(a, block + a, 1)
io.open(SRC, "w", encoding="latin-1", newline="\n").write(t)
print("far-name _OVRINIT with observable alloc inserted")

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
print("RUN.LOG head:", d[:24])
print("STRONG.SAV", os.path.exists(os.path.join(ROOT, "tmp", "runcode", "STRONG.SAV")))
