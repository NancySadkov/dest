#!/usr/bin/env python3
"""Compile the recovered functional C init modules.

Sources: src/init/assets.c (init_assets, 6ffe:02f7), assets1.c (init_assets1,
7a57:0000), assets2.c (init_assets2, 81b9:0086).

This is the functional C reconstruction.  It is not yet byte-exact or linked
into the standalone build; the byte-exact build still uses the asm blocks.
"""
import os
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
SRC = os.path.join(ROOT, "src", "init")
WORK = os.path.join(ROOT, "tmp", "initbuild")


def main():
    shutil.rmtree(WORK, ignore_errors=True)
    os.makedirs(WORK, exist_ok=True)
    files = ["assets.c", "assets1.c", "assets2.c"]
    for name in ("compat.h", "types.h", "glob.h", "art.h", "func.h", "st.h"):
        shutil.copyfile(os.path.join(SRC, name), os.path.join(WORK, name))
    cmds = []
    for name in files:
        shutil.copyfile(os.path.join(SRC, name), os.path.join(WORK, name))
        cmds.append("D:\\BIN\\TCC.EXE -ml -ID:\\INCLUDE -IC:\\ -LD:\\LIB "
                    "-w- -c " + name)
    bat = ("@echo off\r\nmode con lines=50\r\n" + "\r\n".join(cmds) +
           "\r\npause\r\n")
    open(os.path.join(WORK, "build.bat"), "w", newline="").write(bat)
    conf = (
        "[sdl]\nfullscreen = false\noutput = surface\n"
        "[dosbox]\nmachine = svga_s3\nmemsize = 16\n"
        "[cpu]\ncore = normal\ncputype = 386\ncycles = max\n"
        "[mixer]\nnosound = true\n[sblaster]\nsbtype = none\n[midi]\nmididevice = none\n"
        "[autoexec]\nmount c " + WORK.replace("\\", "\\\\") + "\n"
        "mount d " + os.path.join(ROOT, "tools", "TC30").replace("\\", "\\\\") + "\n"
        "c:\ncall build.bat\n"
    )
    conf_path = os.path.join(ROOT, "tmp", "initbuild.conf")
    open(conf_path, "w").write(conf)
    subprocess.run(["powershell", "-NoProfile", "-Command",
                    "Get-Process | Where-Object {$_.ProcessName -match 'dosbox'} | "
                    "Stop-Process -Force -ErrorAction SilentlyContinue"],
                   capture_output=True)
    subprocess.run([sys.executable,
                    os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                    "--conf", conf_path, "--wait", "30"], check=True)
    ok = True
    for name in files:
        obj = os.path.join(WORK, name[:-2].upper() + ".OBJ")
        if os.path.exists(obj):
            print("OK   %-10s %d bytes" % (name, os.path.getsize(obj)))
        else:
            print("FAIL", name)
            ok = False
    if not ok:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
