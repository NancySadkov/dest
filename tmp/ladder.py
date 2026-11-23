"""Run the ladder: nop the given exit-code markers, run, print the first code.

usage: python tmp/ladder.py 30 31 ...      (codes are hex without 0x)
"""
import os
import shutil
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"
EXE = os.path.join(ROOT, "tmp", "buildsrc", "REBUILT.EXE")
BAK = EXE + ".bak"

codes = [int(a, 16) for a in sys.argv[1:]]
shutil.copyfile(EXE, BAK)
try:
    b = bytearray(open(EXE, "rb").read())
    for c in codes:
        pat = bytes([0xB8, c, 0x4C, 0xCD, 0x21])
        n = b.count(pat)
        b = b.replace(pat, b"\x90" * 5)
        if n:
            print("nop %02x (%d)" % (c, n))
    open(EXE, "wb").write(b)
    subprocess.run([sys.executable, os.path.join(ROOT, "tmp", "exact_code.py")],
                   check=False)
finally:
    shutil.move(BAK, EXE)
