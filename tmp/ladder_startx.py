"""Insert exit-code markers into startx for the bisect ladder.

usage: python tmp/ladder_startx.py [--revert]
"""
import io
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"

if "--revert" in sys.argv:
    subprocess.run(["git", "checkout", "--", "src/decompiled/crtl.c"], cwd=ROOT,
                   check=False)
    print("reverted")
    raise SystemExit

p = ROOT + r"\src\decompiled\crtl.c"
t = io.open(p, encoding="latin-1").read()

steps = [
    ('  asm { mov ax, seg DosVersion; mov ds, ax };', 0x30),
    ('  SaveVectors();', 0x31),
    ('  _setupio();', 0x36),
    ('  _c0crtinit();', 0x37),
    ('  pmain = main;', 0x38),
]

for anchor, code in steps:
    i = t.index(anchor, t.index('void startx(void)'))
    end = i + len(anchor)
    t = (t[:end] + "\n  asm { mov ax,4c%02Xh; int 21h };" % code + t[end:])

io.open(p, "w", encoding="latin-1", newline="\n").write(t)
print("ladder markers inserted:", ", ".join("0x%02x" % c for _, c in steps))
