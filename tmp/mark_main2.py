"""Mark main's body and the ovr_init_game call site with exit codes.

usage: python tmp/mark_main2.py [--revert]
"""
import io
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"

if "--revert" in sys.argv:
    subprocess.run(["git", "checkout", "--", "src/decompiled/main.c"], cwd=ROOT,
                   check=False)
    print("reverted")
    raise SystemExit

p = ROOT + r"\src\decompiled\main.c"
t = io.open(p, encoding="latin-1").read()

anchor = '  byte bStack_6;'
i = t.index(anchor)
end = i + len(anchor)
t = t[:end] + "\n  asm { mov ax,4c40h; int 21h };" + t[end:]

anchor = '  ovr_init_game();'
i = t.index(anchor)
t = t[:i] + "  asm { mov ax,4c41h; int 21h };\n" + t[i:]

io.open(p, "w", encoding="latin-1", newline="\n").write(t)
print("main markers 0x40 (body) and 0x41 (call site) inserted")
