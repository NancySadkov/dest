"""Add AH=40h progress markers to init_game and main.

Only an explicit write to handle 1 reaches the batch-redirected file in this
harness (AH=02 output is not captured - see doc/step6_runtime_state.md).

usage: python tmp/trace_init.py [--revert]
"""
import io
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"

if "--revert" in sys.argv:
    subprocess.run(["git", "checkout", "--", "src/decompiled/ovc09_init.c",
                    "src/decompiled/main.c"], cwd=ROOT, check=False)
    print("reverted")
    raise SystemExit

p = ROOT + r"\src\decompiled\ovc09_init.c"
t = io.open(p, encoding="latin-1").read()

if 'st_traceCh' not in t:
    anchor = '#include "recovered.h"'
    t = t.replace(anchor, anchor + '\n\nchar st_traceCh;   /* progress trace */', 1)

MARK = ("\n  st_traceCh = '%s';\n"
        "  asm { mov bx,1; mov dx,offset st_traceCh; mov cx,1; "
        "mov ah,0x40; int 21h };")

steps = [("  _OvrInitExt(0,0);", "A"),
         ("  ovr_init_base();", "B"),
         ("  init_paths();", "C"),
         ("  init_cfg();", "D"),
         ("  clrscr();", "E"),
         ("  ovr_stshAlloc(0xfa0f);", "F"),
         ("  ovr_init_assets();", "G")]

i0 = t.index('void __cdecl16far init_game(void)')
for call, ch in steps:
    i = t.index(call, i0)
    end = i + len(call)
    t = t[:end] + (MARK % ch) + t[end:]

io.open(p, "w", encoding="latin-1", newline="\n").write(t)

p = ROOT + r"\src\decompiled\main.c"
t = io.open(p, encoding="latin-1").read()
if 'st_traceCh' not in t:
    anchor = '#include "recovered.h"'
    t = t.replace(anchor, anchor + '\n\nextern char st_traceCh;', 1)
i = t.index('  byte bStack_6;')
end = i + len('  byte bStack_6;')
t = t[:end] + (MARK % "S") + t[end:]
i = t.index('  ovr_init_game();')
end = i + len('  ovr_init_game();')
t = t[:end] + (MARK % "M") + t[end:]
io.open(p, "w", encoding="latin-1", newline="\n").write(t)
print("markers inserted (AH=40h)")
