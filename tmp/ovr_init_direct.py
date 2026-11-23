"""Initialise VROOMM by calling __OVRINIT directly with a DOS-allocated buffer.

`_OVRPREPARE()` links and runs but the program exits with code 3 (Borland abort),
so either `_farmalloc` returned 0 (our far heap is not initialised that early) or
`__OVRINIT` could not open/find the exe.  Calling `__OVRINIT` ourselves removes
both unknowns: the buffer comes from DOS AH=48h and the exe name is explicit.
The return code is written to stdout as one digit so the failure is visible.

usage: python tmp/ovr_init_direct.py [--revert]
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

CALL = (
    "  /* VROOMM: allocate the overlay buffer with DOS and initialise the\n"
    "     manager explicitly (C0 would call __OvrPrepare, which uses\n"
    "     _farmalloc; our far heap is not set up that early). */\n"
    "  {\n"
    "    uint16_t bufseg = 0;\n"
    "    int rc;\n\n"
    "    asm { mov ah,0x48; mov bx,0x4000; int 21h; mov bufseg,ax }\n"
    "    rc = _OVRINIT(\"STRONG.EXE\", (uint16_t)(bufseg + 0x4000), bufseg);\n"
    "    st_ovrRc = rc;\n"
    "    st_traceCh = (char)(rc + 0x30);\n"
    "    asm { mov bx,1; mov dx,offset st_traceCh; mov cx,1; mov ah,0x40; int 21h };\n"
    "  }\n\n")

t = io.open(SRC, encoding="latin-1").read()
if "_OVRINIT" not in t:
    t = t.replace('#include "recovered.h"',
                  '#include "recovered.h"\n\n'
                  'int __cdecl16far _OVRINIT(char *exename, uint16_t bufend, uint16_t bufbeg);',
                  1)
    a = "  /* __setargv is not recovered yet"
    t = t.replace(a, CALL + a, 1)
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
print("_OVRINIT call inserted")

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
print("_OVRINIT ->", first[0].decode() if first else "no code (hang)")
print("RUN.LOG head:", d[:16])
print("STRONG.SAV", os.path.exists(os.path.join(ROOT, "tmp", "runcode", "STRONG.SAV")))
