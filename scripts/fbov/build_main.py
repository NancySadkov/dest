#!/usr/bin/env python3
"""Build main() from src/main.c for the static load module.

Compiles without -O (the original main was built without it), links against
the recovered DGROUP, extracts the MAIN_TEXT segment and applies the committed
call/jump operand patches in src/main_patch.csv.

Output: tmp/main_code.bin
"""
import csv
import os
import re
import shutil
import struct
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
SRC = os.path.join(ROOT, "src")
WORK = os.path.join(ROOT, "tmp", "mainbuild_src")
OVWORK = os.path.join(ROOT, "tmp", "ovbuild_src")
LINK = os.path.join(ROOT, "tmp", "linkbuild")


def main():
    shutil.rmtree(WORK, ignore_errors=True)
    os.makedirs(WORK, exist_ok=True)
    base = OVWORK if os.path.exists(os.path.join(OVWORK, "DGLINK.OBJ")) else LINK
    for name in ("compat.h", "types.h", "dgroup.h", "stubs.c"):
        shutil.copyfile(os.path.join(base, name), os.path.join(WORK, name))
    dglink = "DGLINK.OBJ" if os.path.exists(os.path.join(base, "DGLINK.OBJ")) \
        else "dglink.obj"
    shutil.copyfile(os.path.join(base, dglink), os.path.join(WORK, "dglink.obj"))
    shutil.copyfile(os.path.join(SRC, "main.c"), os.path.join(WORK, "main.c"))

    lines = []
    for line in open(os.path.join(WORK, "stubs.c"), encoding="ascii").read().splitlines():
        if re.search(r"\bmain\s*\(", line):
            continue
        lines.append(line)
    open(os.path.join(WORK, "stubs.c"), "w", newline="").write(
        "\n".join(lines) + "\n")

    bat = ("@echo off\r\nmode con lines=50\r\n"
           "D:\\BIN\\TCC.EXE -ml -1 -G -ID:\\INCLUDE -IC:\\ -LD:\\LIB -w- -c main.c\r\n"
           "D:\\BIN\\TCC.EXE -ml -1 -G -ID:\\INCLUDE -IC:\\ -LD:\\LIB -w- -c stubs.c\r\n"
           "D:\\BIN\\TLINK.EXE /m dglink.obj main.obj stubs.obj, out.exe, out.map\r\n"
           "pause\r\n")
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
    conf_path = os.path.join(ROOT, "tmp", "mainbuild_src.conf")
    open(conf_path, "w").write(conf)
    subprocess.run(["powershell", "-NoProfile", "-Command",
                    "Get-Process | Where-Object {$_.ProcessName -match 'dosbox'} | "
                    "Stop-Process -Force -ErrorAction SilentlyContinue"],
                   capture_output=True)
    subprocess.run([sys.executable,
                    os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                    "--conf", conf_path, "--wait", "20"], check=True)

    mp = open(os.path.join(WORK, "OUT.MAP"), encoding="ascii",
              errors="replace").read()
    m = re.search(r"^\s*([0-9A-F]{4}):([0-9A-F]{4})\s+_MAIN\s*$", mp,
                  re.M | re.I)
    if not m:
        raise SystemExit("main missing from map")
    image = open(os.path.join(WORK, "OUT.EXE"), "rb").read()
    base_off = struct.unpack_from("<H", image, 8)[0] * 16
    ofs = int(m.group(2), 16)
    code = bytearray(image[base_off + ofs:base_off + ofs + 2246])

    for r in csv.DictReader(open(os.path.join(SRC, "main_patch.csv"))):
        code[int(r["offset"], 16)] = int(r["value"], 16)
    out = os.path.join(ROOT, "tmp", "main_code.bin")
    open(out, "wb").write(code)
    print("wrote", out, len(code), "bytes")


if __name__ == "__main__":
    main()
