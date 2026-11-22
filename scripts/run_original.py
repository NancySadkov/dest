"""Control run: the original STRONG.EXE through the same harness.

Without this, "no output" from REBUILT.EXE proves nothing - the game may simply be
silent under a headless run.  If the original prints the configuration prompt and
the rebuilt one does not, the rebuilt image is failing early.
"""
import io
import os
import shutil
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"
RUN = os.path.join(ROOT, "tmp", "runoriginal")
ORIG = os.path.join(ROOT, "game", "STRONG.EXE")

if os.path.isdir(RUN):
    shutil.rmtree(RUN)
os.makedirs(RUN)
shutil.copyfile(ORIG, os.path.join(RUN, "STRONG.EXE"))
for name in ("STRONG.DAT", "STRONG.FLI", "Strong.bat", "DIR.TXT"):
    p = os.path.join(ROOT, "game", name)
    if os.path.exists(p):
        try:
            shutil.copyfile(p, os.path.join(RUN, name))
        except OSError as e:
            print("  skip", name, e)

io.open(os.path.join(RUN, "GO.BAT"), "w", encoding="ascii", newline="\r\n").write(
    "@echo off\r\nc:\r\ncd \\\r\nSTRONG.EXE > RUN.LOG\r\necho EXITCODE=%ERRORLEVEL% >> RUN.LOG\r\n")

conf = ["[sdl]", "output = surface", "[dosbox]", "machine = svga_s3", "memsize = 16",
        "[cpu]", "core = normal", "cputype = 386", "cycles = max",
        "[mixer]", "nosound = true", "[autoexec]",
        "mount c " + RUN, "c:", "call GO.BAT"]
path = os.path.join(ROOT, "tmp", "runoriginal.conf")
io.open(path, "w", encoding="ascii", newline="\r\n").write("\n".join(conf) + "\n")

print("running the ORIGINAL STRONG.EXE for up to 25 s ...")
subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                "--conf", path, "--wait", "25"], check=False)

log = os.path.join(RUN, "RUN.LOG")
if os.path.exists(log):
    txt = io.open(log, encoding="latin-1", errors="replace").read()
    print("--- original RUN.LOG (%d bytes) ---" % len(txt))
    print(txt[:1200])
else:
    print("original produced no RUN.LOG")
