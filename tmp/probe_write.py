"""Stage 1: is the AH=40h write channel usable inside startx's body?

Earlier markers in startx produced nothing while the same write from an
interrupt handler worked.  The likely cause is DS: after _c0crtinit() it need not
be DGROUP, so `offset st_traceCh` addresses the wrong segment.  This sets DS
explicitly before the write.

usage: python tmp/probe_write.py [--revert]
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

t = io.open(SRC, encoding="latin-1").read()
a = "  /* __setargv is not recovered yet"
mark = ("  st_traceCh = 'Z';\n"
        "  asm {\n"
        "    mov ax,seg st_traceCh;\n"
        "    mov ds,ax;\n"
        "    mov bx,1;\n"
        "    mov dx,offset st_traceCh;\n"
        "    mov cx,1;\n"
        "    mov ah,0x40;\n"
        "    int 21h;\n"
        "  }\n\n")
t = t.replace(a, mark + a, 1)
io.open(SRC, "w", encoding="latin-1", newline="\n").write(t)
print("write marker inserted (DS set explicitly)")

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
print("RUN.LOG head:", d[:24])
