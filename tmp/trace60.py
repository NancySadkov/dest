"""Reachability tracer using INT 60h markers (2 bytes, no immediates).

INT 3 did not work: DOSBox intercepts it internally, so the installed handler
never ran and every probe answered "no code".  INT 60h is an unused software
interrupt that goes through the IVT, and a 2-byte `CD 60` marker cannot be
corrupted by a relocation unless one lands inside those two bytes (they are
dropped).

The handler writes one byte to stdout and exits with 0x50, so a reached address
shows up as CODE=80.

usage: python tmp/trace60.py
"""
import io
import os
import re
import struct
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"
EXE = os.path.join(ROOT, "tmp", "buildsrc", "REBUILT.EXE")
MAP = os.path.join(ROOT, "tmp", "buildsrc", "REBUILT.MAP")
SRC = ROOT + r"\src\decompiled\crtl.c"
HDR = ROOT + r"\src\decompiled\st_globals.h"
GLOB = ROOT + r"\src\decompiled\st_globals5.c"

HANDLER = '''
/* Tracer handler: the marked address was reached. */
void st_trace60(void)
{
  st_traceCh = 'T';
  asm {
    mov bx,1;
    mov dx,offset st_traceCh;
    mov cx,1;
    mov ah,0x40;
    int 21h;
    mov ax,0x4c50;
    int 21h;
  }
}
'''


def revert():
    subprocess.run(["git", "checkout", "--", SRC, HDR, GLOB], cwd=ROOT, check=False)


def install():
    t = io.open(GLOB, encoding="latin-1").read()
    if "st_traceCh" not in t:
        t = t.replace("uint16_t GRecordCount = 0x0000;",
                      "uint16_t GRecordCount = 0x0000;\nvolatile char st_traceCh;", 1)
        io.open(GLOB, "w", encoding="latin-1", newline="").write(t)
    t = io.open(HDR, encoding="latin-1").read()
    if "st_traceCh" not in t:
        t = t.replace("extern uint16_t GRecordCount;",
                      "extern uint16_t GRecordCount;\nextern volatile char st_traceCh;", 1)
        io.open(HDR, "w", encoding="latin-1", newline="").write(t)
    t = io.open(SRC, encoding="latin-1").read()
    t = t.replace("void startx(void)", HANDLER + "void startx(void)", 1)
    inst = ("  {\n"
            "    uint16_t hofs = (uint16_t)st_trace60;\n\n"
            "    asm {\n"
            "      cli;\n"
            "      xor ax,ax;\n"
            "      mov es,ax;\n"
            "      mov ax,hofs;\n"
            "      mov word ptr es:[0x180],ax;\n"
            "      mov word ptr es:[0x182],cs;\n"
            "      sti;\n"
            "    }\n"
            "  }\n\n")
    anchor = "  asm { mov ax, seg DosVersion; mov ds, ax };"
    i = t.index(anchor, t.index("void startx(void)"))
    end = i + len(anchor)
    t = t[:end] + "\n" + inst + t[end:]
    io.open(SRC, "w", encoding="latin-1", newline="\n").write(t)


def build():
    subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "build_standalone.py"),
                    "--wait", "3000"], stdout=subprocess.DEVNULL)
    subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "link_standalone.py")],
                   stdout=subprocess.DEVNULL)


def symbol(name):
    s = io.open(MAP, encoding="latin-1", errors="replace").read()
    hits = re.findall(r"([0-9A-F]{4}):([0-9A-F]{4})\s+(?:idle\s+)?" + name + r"\s*$", s, re.M)
    seg, ofs = hits[-1]
    return int(seg, 16) * 16 + int(ofs, 16)


def drop(b, lo, hi):
    n = struct.unpack("<H", b[6:8])[0]
    off = struct.unpack("<H", b[0x18:0x1a])[0]
    keep = []
    for k in range(n):
        o, s = struct.unpack("<HH", b[off + 4 * k:off + 4 * k + 4])
        if lo <= o < hi:
            continue
        keep.append((o, s))
    b[off:off + 4 * n] = b"\0" * (4 * n)
    for k, (o, s) in enumerate(keep):
        struct.pack_into("<HH", b, off + 4 * k, o, s)
    struct.pack_into("<H", b, 6, len(keep))


def run(base, img, target):
    b = bytearray(base)
    drop(b, target, target + 2)
    b[img + target:img + target + 2] = b"\xcd\x60"
    open(EXE, "wb").write(b)
    subprocess.run([sys.executable, os.path.join(ROOT, "tmp", "exact_code.py")],
                   stdout=subprocess.DEVNULL)
    d = open(os.path.join(ROOT, "tmp", "runcode", "RUN.LOG"), "rb").read()
    first = [l for l in d.splitlines() if l.startswith(b"CODE=")]
    return first[0].decode() if first else "no code"


install()
build()
base = open(EXE, "rb").read()
img = struct.unpack("<H", base[8:10])[0] * 16
entry = symbol("_MAIN")
assert base[img + entry:img + entry + 2] == b"\x55\x8b"
lcall = entry + 0x3C
tofs, tseg = struct.unpack("<HH", base[img + lcall + 1:img + lcall + 5])
thunk = tseg * 16 + tofs
sofs, sseg = struct.unpack("<HH", base[img + thunk + 1:img + thunk + 5])
stub = sseg * 16 + sofs
print("main 0x%x  lcall 0x%x  thunk 0x%x  stub 0x%x" % (entry, lcall, thunk, stub))

for label, target in [("entry", entry), ("argc", entry + 0x1C),
                      ("branch", entry + 0x2E), ("lcall", lcall),
                      ("thunk", thunk), ("stub", stub)]:
    print("%-8s 0x%-6x -> %s" % (label, target, run(base, img, target)))

open(EXE, "wb").write(base)
revert()
build()
print("reverted and rebuilt")
