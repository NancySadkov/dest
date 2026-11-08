#!/usr/bin/env python3
"""Assemble the static load module from src/static/*.asm.

The static segments keep their original bytes and function labels.  This
script assembles them, places each segment at its original file offset, and
writes tmp/static_load.bin.  It does not read game/STRONG.EXE.
"""
import json
import os
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
SRC = os.path.join(ROOT, "src")
STATIC = os.path.join(SRC, "static")
WORK = os.path.join(ROOT, "tmp", "staticbuild")
LOAD = 0x1E00

sys.path.insert(0, os.path.join(ROOT, "scripts", "fbov"))
from byte_match import parse_omf


def main():
    index = json.load(open(os.path.join(SRC, "static_index.json")))
    shutil.rmtree(WORK, ignore_errors=True)
    os.makedirs(WORK, exist_ok=True)
    cmds = []
    for ent in index:
        shutil.copyfile(os.path.join(STATIC, ent["name"] + ".asm"),
                        os.path.join(WORK, ent["name"] + ".asm"))
        cmds.append("E:\\BIN\\TASM.EXE " + ent["name"] + ".asm")
    bat = ("@echo off\r\nmode con lines=50\r\n" + "\r\n".join(cmds) +
           "\r\npause\r\n")
    open(os.path.join(WORK, "build.bat"), "w", newline="").write(bat)
    conf = (
        "[sdl]\nfullscreen = false\noutput = surface\n"
        "[dosbox]\nmachine = svga_s3\nmemsize = 16\n"
        "[cpu]\ncore = normal\ncputype = 386\ncycles = max\n"
        "[mixer]\nnosound = true\n[sblaster]\nsbtype = none\n[midi]\nmididevice = none\n"
        "[autoexec]\nmount c " + WORK.replace("\\", "\\\\") + "\n"
        "mount e " + os.path.join(ROOT, "tools", "BC30").replace("\\", "\\\\") + "\n"
        "c:\ncall build.bat\n"
    )
    conf_path = os.path.join(ROOT, "tmp", "staticbuild.conf")
    open(conf_path, "w").write(conf)
    subprocess.run(["powershell", "-NoProfile", "-Command",
                    "Get-Process | Where-Object {$_.ProcessName -match 'dosbox'} | "
                    "Stop-Process -Force -ErrorAction SilentlyContinue"],
                   capture_output=True)
    subprocess.run([sys.executable,
                    os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                    "--conf", conf_path, "--wait", "60"], check=True)

    end = index[-1]["file_offset"] + index[-1]["size"]
    image = bytearray(end - LOAD)
    for ent in index:
        segdata, _ = parse_omf(os.path.join(WORK, ent["name"] + ".OBJ"))
        bufs = [bytes(b) for b in segdata.values() if len(b)]
        if len(bufs) != 1:
            raise SystemExit("%s: expected one segment, got %d"
                             % (ent["name"], len(bufs)))
        data = bufs[0]
        if len(data) != ent["size"]:
            raise SystemExit("%s: size %d != %d"
                             % (ent["name"], len(data), ent["size"]))
        off = ent["file_offset"] - LOAD
        image[off:off + len(data)] = data
    out = os.path.join(ROOT, "tmp", "static_load.bin")
    open(out, "wb").write(image)
    print("wrote", out, len(image), "bytes")

    base = os.path.join(SRC, "base_static.bin")
    if os.path.exists(base):
        orig = open(base, "rb").read()[LOAD:]
        if bytes(image) != orig:
            d = [i for i in range(min(len(image), len(orig)))
                 if image[i] != orig[i]]
            print("differs from base_static.bin at", len(d), "byte(s)")
            for i in d[:10]:
                print("  %04X: %02X != %02X" % (LOAD + i, image[i], orig[i]))
            raise SystemExit(1)
        print("matches base_static.bin")


if __name__ == "__main__":
    main()
