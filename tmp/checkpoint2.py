"""Second runtime checkpoint: dump DGROUP right after ovr_init_game().

The original's main calls ovr_init_game at 1301:0025 and then ovr_run_demo at
1301:0061 (file offsets 0x4E60 / 0x4E71 from the code block at 0x4E1C).  Replace
the ovr_run_demo call with the 18-byte "write 64 KB from DS:0 to stdout and exit"
stub in both images, so the state captured is exactly what exists after the
initialisation and before the first demo frame.

usage: python tmp/checkpoint2.py
"""
import os
import shutil
import struct
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"
STUB = bytes.fromhex("bb0100" "b9ffff" "ba0000" "b440" "cd21" "b8004c" "cd21")

# file offset of `lcall ovr_run_demo` in each image
CALL = {"orig": ("game/STRONG.EXE", 0x4E71),
        "ours": ("tmp/buildsrc/REBUILT.EXE", 0x7544)}


def run(tag, rel_exe, call_at):
    d = os.path.join(ROOT, "tmp", "ck2_" + tag)
    if os.path.isdir(d):
        shutil.rmtree(d)
    os.makedirs(d)
    data = bytearray(open(os.path.join(ROOT, rel_exe), "rb").read())
    print(tag, "call bytes:", data[call_at:call_at + 5].hex(" "))
    data[call_at:call_at + len(STUB)] = STUB
    open(os.path.join(d, "STRONG.EXE"), "wb").write(data)
    for n in ("STRONG.DAT", "STRONG.FLI"):
        p = os.path.join(ROOT, "game", n)
        if os.path.exists(p):
            shutil.copyfile(p, os.path.join(d, n))
    bat = ["@echo off", "c:", "cd \\", "STRONG.EXE > DGR.BIN", "echo DONE > DONE.FLG"]
    open(os.path.join(d, "GO.BAT"), "w", encoding="ascii",
         newline="\r\n").write("\n".join(bat) + "\n")
    conf = ["[sdl]", "output = surface", "[dosbox]", "machine = svga_s3",
            "memsize = 16", "[cpu]", "core = normal", "cputype = 386",
            "cycles = max", "[mixer]", "nosound = true", "[autoexec]",
            "mount c " + d, "c:", "call GO.BAT"]
    path = os.path.join(ROOT, "tmp", "ck2_%s.conf" % tag)
    open(path, "w", encoding="ascii", newline="\r\n").write("\n".join(conf) + "\n")
    subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                    "--conf", path, "--wait", "60"], check=False)
    out = os.path.join(d, "DGR.BIN")
    return open(out, "rb").read() if os.path.exists(out) else None


for tag, (rel, at) in CALL.items():
    dump = run(tag, rel, at)
    print(tag, "dump bytes:", len(dump) if dump else "none")
