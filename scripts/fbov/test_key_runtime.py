#!/usr/bin/env python3
"""Compile and run the recovered gameProcessKey in a real 16-bit DOS session.

The test links src/game/key.c against tiny stubs for the game/OS calls and
feeds one scan code at a time.  It checks the dispatch constants and the
arguments of the debug-key branches (including the DGROUP strings used by the
0x1300 key).
"""
import os
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
WORK = os.path.join(ROOT, "tmp", "keytest")


def build():
    shutil.rmtree(WORK, ignore_errors=True)
    os.makedirs(WORK)
    for src, dst in (("src/st_compat.h", "compat.h"),
                     ("src/st_types.h", "types.h"),
                     ("src/game/key.c", "key.c"),
                     ("src/game/keybody.inc", "keybody.inc"),
                     ("src/game/keytest.c", "keytest.c")):
        shutil.copyfile(os.path.join(ROOT, src), os.path.join(WORK, dst))
    h = open(os.path.join(ROOT, "src", "dgroup.h"), encoding="ascii").read()
    h = h.replace('#include "st_compat.h"', '#include "compat.h"')
    h = h.replace('#include "st_types.h"', '#include "types.h"')
    open(os.path.join(WORK, "dgroup.h"), "w", encoding="ascii",
         newline="").write(h)
    open(os.path.join(WORK, "link.rsp"), "w", newline="").write(
        "D:\\LIB\\C0L.OBJ KEY.OBJ KEYTEST.OBJ,KEYTEST.EXE,KEYTEST.MAP,"
        "D:\\LIB\\CL.LIB\r\n")
    open(os.path.join(WORK, "b.bat"), "w", newline="").write(
        "@echo off\r\nmode con lines=50\r\n"
        "D:\\BIN\\TCC.EXE -ml -1 -G -O -ID:\\INCLUDE -IC:\\ -LD:\\LIB -w- -c key.c > build.log\r\n"
        "D:\\BIN\\TCC.EXE -ml -1 -G -O -ID:\\INCLUDE -IC:\\ -LD:\\LIB -w- -c keytest.c >> build.log\r\n"
        "D:\\BIN\\TLINK.EXE @link.rsp >> build.log\r\n"
        "echo LINKERR=%errorlevel% >> build.log\r\n"
        "if exist keytest.exe keytest.exe > out.txt\r\n"
        "pause\r\n")
    conf = (
        "[sdl]\nfullscreen = false\noutput = surface\n"
        "[dosbox]\nmachine = svga_s3\nmemsize = 16\n"
        "[cpu]\ncore = normal\ncputype = 386\ncycles = max\n"
        "[mixer]\nnosound = true\n[sblaster]\nsbtype = none\n"
        "[midi]\nmididevice = none\n"
        "[autoexec]\nmount c " + WORK.replace("\\", "\\\\") + "\n"
        "mount d " + os.path.join(ROOT, "tools", "TC30").replace("\\", "\\\\") +
        "\nc:\ncall b.bat\n")
    conf_path = os.path.join(ROOT, "tmp", "keytest.conf")
    open(conf_path, "w").write(conf)
    subprocess.run(["powershell", "-NoProfile", "-Command",
                    "Get-Process | Where-Object {$_.ProcessName -match 'dosbox'} | "
                    "Stop-Process -Force -ErrorAction SilentlyContinue"],
                   capture_output=True)
    subprocess.run([sys.executable,
                    os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                    "--conf", conf_path, "--wait", "30"], check=True)
    out = os.path.join(WORK, "out.txt")
    if not os.path.exists(out):
        raise SystemExit("keytest.exe did not run; see " +
                         os.path.join(WORK, "build.log"))
    return open(out, encoding="ascii", errors="replace").read()


def main():
    text = build()
    print(text.rstrip())
    required = {
        "key=1300 ret=1300 hit=7": "0x1300 debug branch",
        "key=2100 ret=2100 hit=9": "0x2100 branch",
        "key=2300 ret=2300 hit=2": "0x2300 (GSeed) branch",
        "key=2400 ret=2400 hit=12": "0x2400 branch",
        "key=2C00 ret=2C00 hit=11": "0x2C00 branch",
        "key=2E00 ret=2E00 hit=10": "0x2E00 branch",
        "key=3000 ret=3000 hit=9": "0x3000 branch",
        "key=3200 ret=3200 hit=4": "0x3200 branch",
        "a=[WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW]":
            "0x1300 first string argument",
        "b=[Archduchess]": "0x1300 second string argument",
    }
    bad = [what for token, what in required.items() if token not in text]
    if bad:
        print("FAILED:", ", ".join(bad))
        raise SystemExit(1)
    print("KEY RUNTIME TEST: PASS")


if __name__ == "__main__":
    main()
