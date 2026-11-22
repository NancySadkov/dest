"""Ask the compiler, not a Python model, for the recovered struct sizes.

The strides observed in the original code (0x34 for agnt_t, 0x37 for entity_t,
0x95 for agntG_t, 0x27 for bldtp_t) are the acceptance test for the recovered
structs.  A negative array size is a compile error, so

    char chk_agnt_t[sizeof(agnt_t) == 52 ? 1 : -1];

fails the build exactly when the layout is wrong.  This matters especially for
`far` fields: while `far` was an empty macro every far pointer was 2 bytes and the
compiled structs were smaller than the model.
"""
import io
import os
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"
B = os.path.join(ROOT, "tmp", "buildsrc")
TC = os.path.join(ROOT, "tools", "TC30")

SIZES = [("agnt_t", 52), ("entity_t", 55), ("agntG_t", 149), ("bldtp_t", 39)]

src = ['#include "st.h"']
for name, want in SIZES:
    src.append("char chk_%s[sizeof(%s) == %d ? 1 : -1];" % (name, name, want))
io.open(os.path.join(B, "CHK.C"), "w", encoding="ascii", newline="\r\n").write(
    "\n".join(src) + "\n")

io.open(os.path.join(B, "CHK.BAT"), "w", encoding="ascii", newline="\r\n").write(
    "@echo off\r\nset PATH=D:\\BIN\r\nset INCLUDE=D:\\INCLUDE\r\n"
    "D:\\BIN\\TCC.EXE -mm -1 -G -O -c -w- -a- -I. CHK.C > CHK.LOG\r\n"
    "echo done > CHK.FLG\r\n")
for n in ("CHK.FLG", "CHK.OBJ", "CHK.LOG"):
    if os.path.exists(os.path.join(B, n)):
        os.remove(os.path.join(B, n))
conf = ["[sdl]", "output = surface", "[dosbox]", "machine = svga_s3", "memsize = 16",
        "[cpu]", "core = normal", "cputype = 386", "cycles = max",
        "[mixer]", "nosound = true", "[autoexec]",
        "mount c " + B, "mount d " + TC, "c:", "call CHK.BAT", "exit"]
path = os.path.join(ROOT, "tmp", "chk.conf")
io.open(path, "w", encoding="ascii", newline="\r\n").write("\n".join(conf) + "\n")
subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                "--conf", path, "--until", os.path.join(B, "CHK.FLG"), "--wait", "90"],
               check=False)

log = os.path.join(B, "CHK.LOG")
txt = io.open(log, encoding="ascii", errors="replace").read() if os.path.exists(log) else ""
errs = [l.strip() for l in txt.splitlines() if "Error" in l]
if errs:
    print("compiled struct sizes DISAGREE with the model:")
    for e in errs:
        print("   ", e[:100])
else:
    print("compiled struct sizes match the model:",
          ", ".join("%s=%d" % (n, w) for n, w in SIZES))
