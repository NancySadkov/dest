#!/usr/bin/env python3
"""Verify a recovered static function against the original image.

Usage:
  python scripts/fbov/verify_static.py --seg 138E --ofs 01A6 --len 37 \
      --src tmp/cand.c --name f_138e_01a6
"""
import argparse
import os
import re
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
WORK = os.path.join(ROOT, "tmp", "staticverify")
LINK = os.path.join(ROOT, "tmp", "linkbuild")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--seg", required=True)
    ap.add_argument("--ofs", required=True)
    ap.add_argument("--len", required=True, type=lambda x: int(x, 0))
    ap.add_argument("--src", required=True)
    ap.add_argument("--name", required=True)
    ap.add_argument("--wait", type=int, default=15)
    a = ap.parse_args()

    shutil.rmtree(WORK, ignore_errors=True)
    os.makedirs(WORK, exist_ok=True)
    for name in ("dglink.obj", "start.obj", "stubs.c", "compat.h", "types.h",
                 "dgroup.h"):
        shutil.copyfile(os.path.join(LINK, name), os.path.join(WORK, name))
    shutil.copyfile(a.src, os.path.join(WORK, "cand.c"))

    defined = set(re.findall(
        r"__cdecl16far\s+(f_[0-9a-f]{4}_[0-9a-f]+)\s*\(",
        open(a.src, encoding="ascii").read()))
    lines = []
    for line in open(os.path.join(WORK, "stubs.c"), encoding="ascii").read().splitlines():
        m = re.search(r"(f_[0-9a-f]{4}_[0-9a-f]+)\s*\(", line)
        if m and m.group(1) in defined:
            continue
        lines.append(line)
    open(os.path.join(WORK, "stubs.c"), "w", newline="").write(
        "\n".join(lines) + "\n")

    bat = ("@echo off\r\nmode con lines=50\r\n"
           "D:\\BIN\\TCC.EXE -ml -1 -G -O -ID:\\INCLUDE -IC:\\ -LD:\\LIB -w- -c cand.c\r\n"
           "D:\\BIN\\TCC.EXE -ml -1 -G -O -ID:\\INCLUDE -IC:\\ -LD:\\LIB -w- -c stubs.c\r\n"
           "D:\\BIN\\TLINK.EXE /m dglink.obj cand.obj start.obj stubs.obj, out.exe, out.map\r\n"
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
    conf_path = os.path.join(ROOT, "tmp", "staticverify.conf")
    open(conf_path, "w").write(conf)
    subprocess.run(["powershell", "-NoProfile", "-Command",
                    "Get-Process | Where-Object {$_.ProcessName -match 'dosbox'} | "
                    "Stop-Process -Force -ErrorAction SilentlyContinue"],
                   capture_output=True)
    for name in ("OUT.EXE", "OUT.MAP"):
        try:
            os.remove(os.path.join(WORK, name))
        except FileNotFoundError:
            pass
    subprocess.run([sys.executable,
                    os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                    "--conf", conf_path, "--wait", str(a.wait)], check=True)

    map_path = os.path.join(WORK, "OUT.MAP")
    if not os.path.exists(map_path):
        raise SystemExit("link failed; no map")
    text = open(map_path, encoding="ascii", errors="replace").read()
    if "Error:" in text:
        for line in text.splitlines():
            if "Error:" in line:
                print(line)
    m = re.search(r"^\s*([0-9A-F]{4}):([0-9A-F]{4})\s+_?%s\s*$"
                  % re.escape(a.name), text, re.M | re.I)
    if not m:
        raise SystemExit("symbol %s missing from map" % a.name)
    ofs = int(m.group(2), 16)
    r = subprocess.run(
        [sys.executable, os.path.join(ROOT, "scripts", "fbov",
                                      "vroomm_subst.py"),
         "--seg", a.seg, "--ofs", a.ofs, "--len", str(a.len),
         "--compiled", os.path.join(WORK, "OUT.EXE"),
         "--compiled-ofs", "0x%X" % ofs],
        capture_output=True, text=True)
    print(r.stdout.rstrip())
    if r.returncode != 0:
        print(r.stderr.rstrip())
        raise SystemExit(1)
    print("PASS %s:%s" % (a.seg, a.ofs))


if __name__ == "__main__":
    main()
