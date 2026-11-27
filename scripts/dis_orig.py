"""Disassemble a region of the original image by 1000-relative offset (capstone, 16-bit)."""

import io
import sys

import capstone

ROOT = r"C:\Users\nangl\d\code\dest"
START = int(sys.argv[1], 16)
LEN = int(sys.argv[2], 16) if len(sys.argv) > 2 else 0x120

b = io.open(ROOT + r"\game\STRONG.EXE", "rb").read()
# The load image starts after the MZ header: patch tools add this base before the linear offset.
import struct
img = struct.unpack("<H", b[8:10])[0] * 16
code = b[img + START:img + START + LEN]
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_16)
for insn in md.disasm(code, START):
    print("%04x  %-8s %s" % (insn.address, insn.mnemonic, insn.op_str))
