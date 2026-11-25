"""Prove the multi-segment dump stub, and provide it for the runtime instrument.

The existing dump stub writes DS:0..#FFFF to stdout.  The tables that the rewritten ability
routines read are not all in DS (probe_fields.py: four are outside DGROUP entirely, four are
far-pointer slots), so the instrument needs to dump a *second* segment as well.

The stub built here does exactly that: it dumps DS, then reads a 4-byte far pointer from a known
DGROUP slot and dumps the segment that pointer names.  Both images get the same stub shape with
their own slot offsets, so the two dumps are comparable.

Mechanism test: slot 0x033e in the original's DGROUP holds 1C33:0352, a pointer back into DGROUP,
so both blocks come from the same segment.  The output is 131,070 bytes (2 x 0xFFFF), which proves
the second write path without needing a populated non-DGROUP pointer - none exists at the
main-entry checkpoint.

Caveat measured while testing: a DGROUP dump is NOT byte-stable between runs of the same binary.
Two runs of the original differed in 26 bytes - 0x0081..0x0083 (_StartTime) and a cluster at
0xa86e..0xa881 - so any differential checkpoint has to normalise those before comparing.
"""

import io
import os
import shutil
import struct
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"

# push ds / mov bx,1 / mov cx,0xFFFF / mov dx,0 / mov ah,0x40 / int 0x21
DUMP_DS = bytes.fromhex("1e" "bb0100" "b9ffff" "ba0000" "b440" "cd21")
EXIT = bytes.fromhex("b8004c" "cd21")


def stub_with_slot(slot):
    """DS dump, then dump the segment named by the far pointer at DGROUP:slot."""
    return (DUMP_DS +
            b"\x1f"                       # pop ds      -> back to DGROUP
            b"\xa1" + struct.pack("<H", slot)          # mov ax,[slot]     (offset)
            + b"\x8e\x1e" + struct.pack("<H", slot + 2)  # mov ds,[slot+2]  (segment)
            + b"\x89\xc2"                 # mov dx,ax
            + b"\xbb\x01\x00"             # mov bx,1
            + b"\xb9\xff\xff"             # mov cx,0xFFFF
            + b"\xb4\x40"                 # mov ah,0x40
            + b"\xcd\x21"                 # int 0x21
            + EXIT)


def patch(path, image_offset, stub):
    b = bytearray(open(path, "rb").read())
    img = struct.unpack("<H", b[8:10])[0] * 16
    b[img + image_offset:img + image_offset + len(stub)] = stub
    return bytes(b)


def run(tag, data, autoexec_extra=()):
    d = os.path.join(ROOT, "tmp", "dgx_" + tag)
    if os.path.isdir(d):
        shutil.rmtree(d)
    os.makedirs(d)
    open(os.path.join(d, "STRONG.EXE"), "wb").write(data)
    for n in ("STRONG.DAT", "STRONG.FLI"):
        p = os.path.join(ROOT, "game", n)
        if os.path.exists(p):
            shutil.copyfile(p, os.path.join(d, n))
    bat = (["@echo off", "c:", "cd \\"] + list(autoexec_extra) +
           ["STRONG.EXE > DGR.BIN", "echo DONE > DONE.FLG"])
    open(os.path.join(d, "GO.BAT"), "w", encoding="ascii",
         newline="\r\n").write("\n".join(bat) + "\n")
    conf = ["[sdl]", "output = surface", "[dosbox]", "machine = svga_s3",
            "memsize = 16", "[cpu]", "core = normal", "cputype = 386",
            "cycles = max", "[mixer]", "nosound = true", "[autoexec]",
            "mount c " + d, "c:", "call GO.BAT"]
    path = os.path.join(ROOT, "tmp", "dgx_%s.conf" % tag)
    open(path, "w", encoding="ascii", newline="\r\n").write("\n".join(conf) + "\n")
    subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                    "--conf", path, "--wait", "40"], check=False)
    out = os.path.join(d, "DGR.BIN")
    return open(out, "rb").read() if os.path.exists(out) else None


SLOT = 0x033E          # holds 1C33:0352 in the original's DGROUP
data = patch(os.path.join(ROOT, "game", "STRONG.EXE"), 0x301C, stub_with_slot(SLOT))
print("stub length %d bytes, slot %#06x" % (len(stub_with_slot(SLOT)), SLOT))
blob = run("orig2", data)
if blob is None:
    print("no dump produced")
    raise SystemExit(1)
print("dump size: %d bytes (%.2f x 64K)" % (len(blob), len(blob) / 65536.0))
if len(blob) >= 2 * 0xFFFF:
    a, b = blob[:0xFFFF], blob[0xFFFF:2 * 0xFFFF]
    print("first block == second block:", a == b)
