"""Resolve the INT 3Fh handler address recorded in DBG.TXT for the last build."""
import io
import os
import re
import struct

ROOT = r"C:\Users\nangl\d\code\dest"
MAP = os.path.join(ROOT, "tmp", "buildsrc", "REBUILT.MAP")
EXE = os.path.join(ROOT, "tmp", "buildsrc", "REBUILT.EXE")
DBG = os.path.join(ROOT, "tmp", "runcode", "DBG.TXT")

data = open(DBG, "rb").read() if os.path.exists(DBG) else b""
print("DBG.TXT:", data)

m = re.findall(r"([0-9A-F]{4}):([0-9A-F]{4})\s+(?:idle\s+)?_STARTX\s*$",
               io.open(MAP, encoding="latin-1", errors="replace").read(), re.M)
sseg = int(m[-1][0], 16)
print("_STARTX segment %04X" % sseg)

if b"#" in data:
    i = data.index(b"#")
    dseg = int(data[i + 1:i + 3], 16)
    dofs = int(data[i + 3:i + 7], 16)
    off = (sseg + dseg) * 16 + dofs
    exe = open(EXE, "rb").read()
    img = struct.unpack("<H", exe[8:10])[0] * 16
    print("handler image 0x%x bytes %s"
          % (off, exe[img + off:img + off + 12].hex(" ")))
    from capstone import Cs, CS_ARCH_X86, CS_MODE_16
    md = Cs(CS_ARCH_X86, CS_MODE_16)
    for ins in md.disasm(exe[img + off:img + off + 0x30], off):
        print("  %05x %-8s %s" % (ins.address, ins.mnemonic, ins.op_str))
