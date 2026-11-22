"""Run the rebuilt image and capture what it does.

Copies REBUILT.EXE next to the game data (STRONG.DAT etc. are what the loader
opens) and starts it under the headless DOSBox-X used by the rest of the tooling.
The program is graphical and waits for a key at the configuration screen, so the
run is time-boxed; the value is the console text and whether it dies immediately.
"""
import io
import os
import shutil
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"
SRC = os.path.join(ROOT, "tmp", "buildsrc", "REBUILT.EXE")
RUN = os.path.join(ROOT, "tmp", "runrebuild")

if not os.path.exists(SRC):
    print("no REBUILT.EXE")
    raise SystemExit(0)

if os.path.isdir(RUN):
    shutil.rmtree(RUN)
os.makedirs(RUN)
shutil.copyfile(SRC, os.path.join(RUN, "STRONG.EXE"))     # the name it expects
for name in ("STRONG.DAT", "STRONG.FLI", "STRONG.SAV", "Strong.bat", "DIR.TXT"):
    p = os.path.join(ROOT, "game", name)
    if os.path.exists(p):
        try:
            shutil.copyfile(p, os.path.join(RUN, name))
        except OSError as e:
            print('  skip', name, e)
# a fresh config so it takes the "reconfigure" path deterministically
for n in ("STRONG.CFG",):
    p = os.path.join(RUN, n)
    if os.path.exists(p):
        os.remove(p)

out = os.path.join(RUN, "RUN.LOG")
bat = ["@echo off", "c:", "cd \\", "STRONG.EXE > RUN.LOG", "echo EXITCODE=%ERRORLEVEL% >> RUN.LOG"]
io.open(os.path.join(RUN, "GO.BAT"), "w", encoding="ascii", newline="\r\n").write(
    "\n".join(bat) + "\n")

conf = ["[sdl]", "output = surface", "[dosbox]", "machine = svga_s3", "memsize = 16",
        "[cpu]", "core = normal", "cputype = 386", "cycles = max",
        "[mixer]", "nosound = true", "[autoexec]",
        "mount c " + RUN, "c:", "call GO.BAT"]
path = os.path.join(ROOT, "tmp", "runrebuild.conf")
io.open(path, "w", encoding="ascii", newline="\r\n").write("\n".join(conf) + "\n")

print("running STRONG.EXE (rebuilt) for up to 25 s ...")
subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                "--conf", path, "--wait", "25"], check=False)

log = os.path.join(RUN, "RUN.LOG")
if os.path.exists(log):
    txt = io.open(log, encoding="latin-1", errors="replace").read()
    print("--- RUN.LOG (%d bytes) ---" % len(txt))
    print(txt[:1500])
else:
    print("no RUN.LOG produced (the program may have hung before writing)")
