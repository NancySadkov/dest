#!/usr/bin/env python3
"""Build a functional EXE with the recovered C management setup.

Steps:
  1. compile src/game/manage.c,
  2. extract f_4d05_0000 and rewrite its segment placeholders to the runtime
     DGROUP/unit-array segments,
  3. pad it to the original 129-byte function size,
  4. replace the first function in OV_4D05.BIN and rebuild the EXE,
  5. neutralise the now-stale FBOV fixup sites inside the replaced function.

The result boots into the in-game map screen and matches the original DGROUP
state up to the game's run-to-run nondeterminism.
"""
import argparse
import csv
import os
import shutil
import struct
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
WORK = os.path.join(ROOT, "tmp", "funcbuild")


def compile_manage():
    shutil.rmtree(WORK, ignore_errors=True)
    os.makedirs(WORK, exist_ok=True)
    for src, dst in (("st_compat.h", "compat.h"), ("st_types.h", "types.h"),
                     ("dgroup.h", "dgroup.h")):
        shutil.copyfile(os.path.join(ROOT, "src", src),
                        os.path.join(WORK, dst))
    h = open(os.path.join(WORK, "dgroup.h"), encoding="ascii").read()
    h = h.replace('#include "st_compat.h"', '#include "compat.h"')
    h = h.replace('#include "st_types.h"', '#include "types.h"')
    open(os.path.join(WORK, "dgroup.h"), "w", encoding="ascii",
         newline="").write(h)
    shutil.copyfile(os.path.join(ROOT, "src", "game", "manage.c"),
                    os.path.join(WORK, "manage.c"))
    open(os.path.join(WORK, "b.bat"), "w", newline="").write(
        "@echo off\r\nmode con lines=50\r\n"
        "D:\\BIN\\TCC.EXE -ml -1 -G -O -ID:\\INCLUDE -IC:\\ -LD:\\LIB "
        "-w- -c manage.c\r\npause\r\n")
    conf = (
        "[sdl]\nfullscreen = false\noutput = surface\n"
        "[dosbox]\nmachine = svga_s3\nmemsize = 16\n"
        "[cpu]\ncore = normal\ncputype = 386\ncycles = max\n"
        "[mixer]\nnosound = true\n[sblaster]\nsbtype = none\n[midi]\nmididevice = none\n"
        "[autoexec]\nmount c " + WORK.replace("\\", "\\\\") + "\n"
        "mount d " + os.path.join(ROOT, "tools", "TC30").replace("\\", "\\\\") + "\n"
        "c:\ncall b.bat\n"
    )
    conf_path = os.path.join(ROOT, "tmp", "funcbuild.conf")
    open(conf_path, "w").write(conf)
    subprocess.run(["powershell", "-NoProfile", "-Command",
                    "Get-Process | Where-Object {$_.ProcessName -match 'dosbox'} | "
                    "Stop-Process -Force -ErrorAction SilentlyContinue"],
                   capture_output=True)
    subprocess.run([sys.executable,
                    os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                    "--conf", conf_path, "--wait", "20"], check=True)
    obj = os.path.join(WORK, "MANAGE.OBJ")
    if not os.path.exists(obj):
        raise SystemExit("manage.c did not compile")
    return obj


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--ds", type=lambda x: int(x, 0), default=0x1C32,
                    help="runtime DGROUP segment")
    ap.add_argument("--unit", type=lambda x: int(x, 0), default=0x199C,
                    help="runtime unit-array segment")
    ap.add_argument("--out", default=os.path.join(ROOT, "out",
                                                  "STRONG_FUNC.EXE"))
    a = ap.parse_args()

    obj = compile_manage()
    sys.path.insert(0, os.path.join(ROOT, "scripts", "fbov"))
    from byte_match import parse_omf
    segdata, pub = parse_omf(obj)
    seg, ofs = pub["f_4d05_0000"]
    func = bytearray(segdata[seg][ofs:ofs + 129])
    end = func.find(b"\xcb")
    if end < 0:
        raise SystemExit("no retf in compiled function")
    func = func[:end + 1]
    if len(func) > 129:
        raise SystemExit("compiled function is larger than 129 bytes")
    for i in range(len(func) - 2):
        if func[i] in (0xB8, 0xBA) and func[i + 1] == 0x80 and func[i + 2] == 0x02:
            struct.pack_into("<H", func, i + 1, a.ds)
        if func[i] in (0xB8, 0xBA) and func[i + 1] == 0x70 and func[i + 2] == 0x00:
            struct.pack_into("<H", func, i + 1, a.unit)
    func += b"\x90" * (129 - len(func))

    ov = os.path.join(ROOT, "tmp", "ovcode", "OV_4D05.BIN")
    if not os.path.exists(ov):
        raise SystemExit("run build_overlays.py first; missing " + ov)
    backup = ov + ".bak"
    shutil.copyfile(ov, backup)
    try:
        d = bytearray(open(ov, "rb").read())
        d[:129] = func
        open(ov, "wb").write(d)
        subprocess.run([sys.executable,
                        os.path.join(ROOT, "scripts", "fbov",
                                     "build_standalone.py"),
                        "--skip-overlays", "--skip-static", "--skip-mz",
                        "--allow-mismatch", "--out", a.out], check=True)
    finally:
        shutil.move(backup, ov)

    # The FBOV fixup table still names sites inside the old function.  Point
    # those entries at the nop padding after the new function.
    row = [r for r in csv.DictReader(open(os.path.join(ROOT, "doc",
                                                       "fbov_overlays.csv")))
           if r["code_seg"] == "4D05"][0]
    off = int(row["code_file_offset"], 0) + int(row["codesz"], 16)
    sz = int(row["fixupsz"], 16)
    d = bytearray(open(a.out, "rb").read())
    n = 0
    for i in range(0, sz, 2):
        if struct.unpack_from("<H", d, off + i)[0] < 0x81:
            struct.pack_into("<H", d, off + i, 0x78)
            n += 1
    open(a.out, "wb").write(d)
    print("wrote", a.out, "patched fixups", n)


if __name__ == "__main__":
    main()
