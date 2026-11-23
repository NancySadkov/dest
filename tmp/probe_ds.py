"""Probe DS at main's entry: write DS (2 bytes) then 64 KB from DS:0.

usage: python tmp/probe_ds.py
"""
import os
import re
import shutil
import struct
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"
EXE = os.path.join(ROOT, "tmp", "buildsrc", "REBUILT.EXE")

# mov ax,ds / push ax / mov bx,1 / mov cx,2 / mov dx,sp / mov ah,40h / int 21h
# add sp,2 / mov bx,1 / mov cx,0ffffh / mov dx,0 / mov ah,40h / int 21h
# mov ax,4c00h / int 21h
STUB = bytes.fromhex(
    "8cd8" "50" "bb0100" "b90200" "89e2" "b440" "cd21" "83c402"
    "bb0100" "b9ffff" "ba0000" "b440" "cd21" "b8004c" "cd21")

s = open(os.path.join(ROOT, "tmp", "buildsrc", "REBUILT.MAP"),
         encoding="latin-1", errors="replace").read()
m = re.search(r"([0-9A-F]{4}):([0-9A-F]{4})\s+(?:idle\s+)?_MAIN\s*$", s, re.M)
off = int(m.group(1), 16) * 16 + int(m.group(2), 16)
print("main at image 0x%x" % off)

d = os.path.join(ROOT, "tmp", "dsprobe")
if os.path.isdir(d):
    shutil.rmtree(d)
os.makedirs(d)
b = bytearray(open(EXE, "rb").read())
img = struct.unpack("<H", b[8:10])[0] * 16
b[img + off:img + off + len(STUB)] = STUB
open(os.path.join(d, "STRONG.EXE"), "wb").write(b)
for n in ("STRONG.DAT", "STRONG.FLI"):
    p = os.path.join(ROOT, "game", n)
    if os.path.exists(p):
        shutil.copyfile(p, os.path.join(d, n))
bat = ["@echo off", "c:", "cd \\", "STRONG.EXE > OUT.BIN", "echo DONE > DONE.FLG"]
open(os.path.join(d, "GO.BAT"), "w", encoding="ascii",
     newline="\r\n").write("\n".join(bat) + "\n")
conf = ["[sdl]", "output = surface", "[dosbox]", "machine = svga_s3",
        "memsize = 16", "[cpu]", "core = normal", "cputype = 386",
        "cycles = max", "[mixer]", "nosound = true", "[autoexec]",
        "mount c " + d, "c:", "call GO.BAT"]
path = os.path.join(ROOT, "tmp", "dsprobe.conf")
open(path, "w", encoding="ascii", newline="\r\n").write("\n".join(conf) + "\n")
subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                "--conf", path, "--wait", "40"], check=False)
out = os.path.join(d, "OUT.BIN")
data = open(out, "rb").read() if os.path.exists(out) else b""
print("OUT.BIN", len(data), "bytes")
if len(data) >= 2:
    print("DS at main entry = 0x%04x" % struct.unpack("<H", data[:2])[0])
