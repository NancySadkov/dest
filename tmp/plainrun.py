"""Run an EXE unpatched in the harness with stdout redirected to OUT.BIN."""
import os
import shutil
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"
rel = sys.argv[1] if len(sys.argv) > 1 else r"tmp/buildsrc/REBUILT.EXE"
d = os.path.join(ROOT, "tmp", "plainrun")
if os.path.isdir(d):
    shutil.rmtree(d)
os.makedirs(d)
shutil.copyfile(os.path.join(ROOT, rel), os.path.join(d, "STRONG.EXE"))
for n in ("STRONG.DAT", "STRONG.FLI"):
    p = os.path.join(ROOT, "game", n)
    if os.path.exists(p):
        shutil.copyfile(p, os.path.join(d, n))
bat = ["@echo off", "c:", "cd \\", "STRONG.EXE > OUT.BIN", "echo DONE > DONE.FLG"]
open(os.path.join(d, "GO.BAT"), "w", encoding="ascii",
     newline="\r\n").write("\n".join(bat) + "\n")
conf = ["[sdl]", "output = surface", "[dosbox]", "machine = svga_s3",
        "memsize = 16", "[cpu]", "core = normal", "cputype = 386",
        "cycles = max", "[mixer]", "nosound = true", "[autoexec]",
        "mount c " + d, "c:", "call GO.BAT"]
path = os.path.join(ROOT, "tmp", "plainrun.conf")
open(path, "w", encoding="ascii", newline="\r\n").write("\n".join(conf) + "\n")
subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                "--conf", path, "--wait", "45"], check=False)
out = os.path.join(d, "OUT.BIN")
b = open(out, "rb").read() if os.path.exists(out) else b""
print("OUT.BIN", len(b), "bytes:", b[:60])
print("files:", sorted(os.listdir(d)))
