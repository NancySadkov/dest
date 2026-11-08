"""Stage and build the linked byte-match harness.

Layout:  start.asm + <recovered>.c + DGLINK.OBJ (+ stubs.c)
DGLINK.OBJ is generated from the verified DGROUP bytes with all symbols
shifted by -8, so Turbo Link's reserved C0 header puts every symbol back at
its original DGROUP offset.  See scripts/fbov/gen_link_dgroup.py.
"""
import os
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
SRC = os.path.join(ROOT, "src")
WORK = os.path.join(ROOT, "src")
DST = os.path.join(ROOT, "tmp", "linkbuild")


def main():
    os.makedirs(DST, exist_ok=True)
    subprocess.check_call([sys.executable,
                           os.path.join(ROOT, "scripts", "fbov", "gen_link_dgroup.py")])

    shutil.copyfile(os.path.join(WORK, "main.c"), os.path.join(DST, "main.c"))
    shutil.copyfile(os.path.join(ROOT, "scripts", "fbov", "start.asm"),
                    os.path.join(DST, "start.asm"))
    shutil.copyfile(os.path.join(ROOT, "scripts", "fbov", "stubs.c"),
                    os.path.join(DST, "stubs.c"))
    shutil.copyfile(os.path.join(SRC, "st_compat.h"), os.path.join(DST, "compat.h"))
    shutil.copyfile(os.path.join(SRC, "st_types.h"), os.path.join(DST, "types.h"))
    s = open(os.path.join(SRC, "dgroup.h"), encoding="ascii").read()
    s = s.replace('#include "st_compat.h"', '#include "compat.h"')
    s = s.replace('#include "st_types.h"', '#include "types.h"')
    open(os.path.join(DST, "dgroup.h"), "w", encoding="ascii").write(s)

    shutil.copyfile(os.path.join(ROOT, "tmp", "dglink", "dglink.asm"),
                    os.path.join(DST, "dglink.asm"))

    bat = ("@echo off\r\n"
           "mode con lines=50\r\n"
           "D:\\BIN\\TCC.EXE -ml -1 -G -ID:\\INCLUDE -IC:\\ -LD:\\LIB -w- -c main.c\r\n"
           "D:\\BIN\\TCC.EXE -ml -1 -G -ID:\\INCLUDE -IC:\\ -LD:\\LIB -w- -c stubs.c\r\n"
           "E:\\BIN\\TASM.EXE start.asm\r\n"
           "E:\\BIN\\TASM.EXE dglink.asm\r\n"
           "D:\\BIN\\TLINK.EXE /m dglink.obj start.obj main.obj stubs.obj, "
           "out.exe, out.map\r\n"
           "pause\r\n")
    open(os.path.join(DST, "one.bat"), "w", newline="").write(bat)

    conf = ("[sdl]\nfullscreen = false\noutput = surface\n"
            "[dosbox]\nmachine = svga_s3\nmemsize = 16\n"
            "[cpu]\ncore = normal\ncputype = 386\ncycles = max\n"
            "[mixer]\nnosound = true\n[sblaster]\nsbtype = none\n[midi]\nmididevice = none\n"
            "[autoexec]\nmount c " + DST.replace("\\", "\\\\") + "\n"
            "mount d C:\\Users\\nangl\\d\\code\\dest\\tools\\TC30\n"
            "mount e C:\\Users\\nangl\\d\\code\\dest\\tools\\BC30\n"
            "c:\ncall one.bat\n")
    open(os.path.join(ROOT, "tmp", "link_build.conf"), "w").write(conf)
    print("staged", DST)


if __name__ == "__main__":
    main()
