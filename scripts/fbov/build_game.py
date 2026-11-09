#!/usr/bin/env python3
"""Compile and link the recovered in-game-loop C fragments.

Sources: src/game/key.c (gameProcessKey), src/game/manage.c (management index
setup).  These are functional C reconstructions; the byte-exact build still
uses the asm blocks.
"""
import os
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
SRC = os.path.join(ROOT, "src", "game")
WORK = os.path.join(ROOT, "tmp", "gamebuild_src")


def extdef(path):
    d = open(path, "rb").read()
    i = 0
    out = []
    while i + 3 <= len(d):
        t = d[i]
        ln = d[i + 1] | (d[i + 2] << 8)
        p = d[i + 3:i + 3 + ln]
        i += 3 + ln
        if t == 0x8C:
            j = 0
            while j < len(p) - 1:
                n = p[j]
                name = p[j + 1:j + 1 + (n & 0x7F)].decode("latin1")
                j += 1 + (n & 0x7F)
                if name:
                    out.append(name)
                if n & 0x80:
                    j += 1
        elif t == 0x8A:
            break
    return out


def main():
    shutil.rmtree(WORK, ignore_errors=True)
    os.makedirs(WORK, exist_ok=True)
    for name in ("compat.h", "types.h", "dgroup.h"):
        shutil.copyfile(os.path.join(ROOT, "src",
                                     "st_compat.h" if name == "compat.h"
                                     else "st_types.h" if name == "types.h"
                                     else "dgroup.h"),
                        os.path.join(WORK, name))
    shutil.copyfile(os.path.join(ROOT, "src", "game", "bss.h"),
                    os.path.join(WORK, "bss.h"))
    h = open(os.path.join(WORK, "dgroup.h"), encoding="ascii").read()
    h = h.replace('#include "st_compat.h"', '#include "compat.h"')
    h = h.replace('#include "st_types.h"', '#include "types.h"')
    open(os.path.join(WORK, "dgroup.h"), "w", encoding="ascii",
         newline="").write(h)
    files = ["key.c", "keybody.inc", "manage.c", "screen.c", "sbody.inc",
             "units.c", "ubody.inc", "menu.c", "menubody.inc"]
    for name in files:
        shutil.copyfile(os.path.join(SRC, name), os.path.join(WORK, name))
    cmds = [
        "D:\\BIN\\TCC.EXE -ml -1 -G -O -ID:\\INCLUDE -IC:\\ -LD:\\LIB -w- -c key.c > build.log 2>&1",
        "D:\\BIN\\TCC.EXE -ml -1 -G -O -ID:\\INCLUDE -IC:\\ -LD:\\LIB -w- -c manage.c >> build.log 2>&1",
        "D:\\BIN\\TCC.EXE -ml -1 -G -O -ID:\\INCLUDE -IC:\\ -LD:\\LIB -w- -c screen.c >> build.log 2>&1",
        "D:\\BIN\\TCC.EXE -ml -1 -G -O -ID:\\INCLUDE -IC:\\ -LD:\\LIB -w- -c units.c >> build.log 2>&1",
        "D:\\BIN\\TCC.EXE -ml -1 -G -O -ID:\\INCLUDE -IC:\\ -LD:\\LIB -w- -c menu.c >> build.log 2>&1",
    ]
    open(os.path.join(WORK, "build.bat"), "w", newline="").write(
        "@echo off\r\nmode con lines=50\r\n" + "\r\n".join(cmds) +
        "\r\npause\r\n")
    conf = (
        "[sdl]\nfullscreen = false\noutput = surface\n"
        "[dosbox]\nmachine = svga_s3\nmemsize = 16\n"
        "[cpu]\ncore = normal\ncputype = 386\ncycles = max\n"
        "[mixer]\nnosound = true\n[sblaster]\nsbtype = none\n[midi]\nmididevice = none\n"
        "[autoexec]\nmount c " + WORK.replace("\\", "\\\\") + "\n"
        "mount d " + os.path.join(ROOT, "tools", "TC30").replace("\\", "\\\\") + "\n"
        "c:\ncall build.bat\n"
    )
    conf_path = os.path.join(ROOT, "tmp", "gamebuild_src.conf")
    open(conf_path, "w").write(conf)
    subprocess.run(["powershell", "-NoProfile", "-Command",
                    "Get-Process | Where-Object {$_.ProcessName -match 'dosbox'} | "
                    "Stop-Process -Force -ErrorAction SilentlyContinue"],
                   capture_output=True)
    subprocess.run([sys.executable,
                    os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                    "--conf", conf_path, "--wait", "25"], check=True)
    objs = []
    for name in ("KEY.OBJ", "MANAGE.OBJ", "SCREEN.OBJ", "UNITS.OBJ",
                 "MENU.OBJ"):
        p = os.path.join(WORK, name)
        if os.path.exists(p):
            print("OK   %-10s %d bytes" % (name, os.path.getsize(p)))
            objs.append(name)
        else:
            print("FAIL", name)
    if len(objs) != 5:
        raise SystemExit(1)

    names = set()
    for obj in objs:
        names |= set(extdef(os.path.join(WORK, obj)))
    lines = ["GAMESTUB SEGMENT PARA PUBLIC 'CODE'"]
    for n in sorted(names):
        lines += ["PUBLIC " + n, n + ":", "  ret"]
    lines += ["GAMESTUB ENDS", "END", ""]
    open(os.path.join(WORK, "gstub.asm"), "w", newline="").write(
        "\r\n".join(lines))
    bat = ("@echo off\r\nmode con lines=50\r\n"
           "E:\\BIN\\TASM.EXE gstub.asm\r\n"
           "D:\\BIN\\TLINK.EXE /m " + " ".join(objs) +
           " GSTUB.OBJ, game.exe, game.map\r\npause\r\n")
    open(os.path.join(WORK, "link.bat"), "w", newline="").write(bat)
    conf = (
        "[sdl]\nfullscreen = false\noutput = surface\n"
        "[dosbox]\nmachine = svga_s3\nmemsize = 16\n"
        "[cpu]\ncore = normal\ncputype = 386\ncycles = max\n"
        "[mixer]\nnosound = true\n[sblaster]\nsbtype = none\n[midi]\nmididevice = none\n"
        "[autoexec]\nmount c " + WORK.replace("\\", "\\\\") + "\n"
        "mount d " + os.path.join(ROOT, "tools", "TC30").replace("\\", "\\\\") + "\n"
        "mount e " + os.path.join(ROOT, "tools", "BC30").replace("\\", "\\\\") + "\n"
        "c:\ncall link.bat\n"
    )
    conf_path = os.path.join(ROOT, "tmp", "gamelink.conf")
    open(conf_path, "w").write(conf)
    for name in ("GAME.EXE", "GAME.MAP"):
        try:
            os.remove(os.path.join(WORK, name))
        except FileNotFoundError:
            pass
    subprocess.run([sys.executable,
                    os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                    "--conf", conf_path, "--wait", "20"], check=True)
    exe = os.path.join(WORK, "GAME.EXE")
    if not os.path.exists(exe):
        raise SystemExit("game link failed")
    print("LINK OK game.exe %d bytes" % os.path.getsize(exe))


if __name__ == "__main__":
    main()
