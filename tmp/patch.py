"""Patch the built image, removing DOS relocations that overlap the patch.

Any 5-byte exit stub written over an instruction whose segment word is a
relocation target gets corrupted at load time: DOS adds the load segment to the
two bytes inside the patch.  Every probe touching a `9A`/`EA` operand on a
relocated word silently produced garbage until this was handled.

usage: python tmp/patch.py <image-offset-hex> <exit-code-hex> [--keep-relocs]
"""
import os
import struct
import subprocess
import sys

ROOT = r"C:\Users\nangl\d\code\dest"
EXE = os.path.join(ROOT, "tmp", "buildsrc", "REBUILT.EXE")


def load():
    b = bytearray(open(EXE, "rb").read())
    img = struct.unpack("<H", b[8:10])[0] * 16
    return b, img


def reloc_table(b):
    n = struct.unpack("<H", b[6:8])[0]
    off = struct.unpack("<H", b[0x18:0x1a])[0]
    return n, off


def drop_relocs(b, lo, hi):
    """Remove every relocation whose offset lies in [lo, hi)."""
    n, off = reloc_table(b)
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
    return n - len(keep)


def main():
    off = int(sys.argv[1], 16)
    code = int(sys.argv[2], 16)
    b, img = load()
    print("before:", b[img + off:img + off + 5].hex(" "))
    removed = drop_relocs(b, off, off + 5)
    b[img + off:img + off + 5] = bytes([0xB8, code, 0x4C, 0xCD, 0x21])
    open(EXE, "wb").write(b)
    print("patched 0x%x with exit 0x%02x, dropped %d relocation(s)" % (off, code, removed))
    subprocess.run([sys.executable, os.path.join(ROOT, "tmp", "exact_code.py")],
                   stdout=subprocess.DEVNULL)
    log = os.path.join(ROOT, "tmp", "runcode", "RUN.LOG")
    d = open(log, "rb").read() if os.path.exists(log) else b""
    first = [l for l in d.splitlines() if l.startswith(b"CODE=")]
    print("result:", first[0].decode() if first else "no code (hang)")


main()
