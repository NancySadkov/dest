"""Insert AH=40h progress markers into startx for the NO_OVERLAY trace.

usage: python tmp/trace_startx.py [--revert]
"""
import io
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"

if "--revert" in sys.argv:
    subprocess.run(["git", "checkout", "--", "src/decompiled/crtl.c",
                    "src/decompiled/st_globals5.c", "src/decompiled/st_globals.h"],
                   cwd=ROOT, check=False)
    print("reverted")
    raise SystemExit

# trace byte in DGROUP
p = ROOT + r"\src\decompiled\st_globals5.c"
t = io.open(p, encoding="latin-1").read()
if 'st_traceCh' not in t:
    t = t.replace('uint16_t GRecordCount = 0x0000;',
                  'uint16_t GRecordCount = 0x0000;\nvolatile char st_traceCh;',
                  1)
    io.open(p, "w", encoding="latin-1", newline="").write(t)

p = ROOT + r"\src\decompiled\st_globals.h"
t = io.open(p, encoding="latin-1").read()
if 'st_traceCh' not in t:
    t = t.replace('extern uint16_t GRecordCount;',
                  'extern uint16_t GRecordCount;\nextern volatile char st_traceCh;', 1)
    io.open(p, "w", encoding="latin-1", newline="").write(t)

MARK = ("\n  st_traceCh = '%s';\n"
        "  asm { mov bx,1; mov dx,offset st_traceCh; mov cx,1; "
        "mov ah,0x40; int 21h };")

p = ROOT + r"\src\decompiled\crtl.c"
t = io.open(p, encoding="latin-1").read()

steps = [('  asm { mov ax, seg DosVersion; mov ds, ax };', "S"),
         ('  SaveVectors();', "A"),
         ('  _setupio();', "B"),
         ('  _c0crtinit();', "C"),
         ('  pmain = main;', "D")]

for anchor, ch in steps:
    i = t.index(anchor, t.index('void startx(void)'))
    end = i + len(anchor)
    t = t[:end] + (MARK % ch) + t[end:]

io.open(p, "w", encoding="latin-1", newline="\n").write(t)
print("startx markers inserted")
