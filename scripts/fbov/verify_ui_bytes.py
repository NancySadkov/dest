#!/usr/bin/env python3
"""Verify recovered UI functions recompile to the original overlay bytes.

Each function is compiled into UI.OBJ by build_game.py.  The compiled body
must be the same length as the original slot and may differ only in relative
call/jump operands (those encode positions inside the overlay).
"""
import csv
import os
import sys

import capstone

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(ROOT, "scripts", "fbov"))
from byte_match import parse_omf  # noqa: E402

OBJ = os.path.join(ROOT, "tmp", "gamebuild_src", "UI.OBJ")
EXE = os.path.join(ROOT, "game", "STRONG.EXE")

# Symbol -> (overlay code segment, offset, length up to the next function).
FUNCS = [
    ("manage_4d05_029d", 0x4D05, 0x029D, 0x54),
    ("manage_4d05_02f1", 0x4D05, 0x02F1, 0x4F),
    ("manage_4d05_0340", 0x4D05, 0x0340, 0x64),
    ("manage_4d05_0d7b", 0x4D05, 0x0D7B, 0x43),
]


def overlay_offset(seg):
    for row in csv.DictReader(open(os.path.join(ROOT, "doc", "fbov_overlays.csv"))):
        if int(row["code_seg"], 16) == seg:
            return int(row["code_file_offset"], 0)
    raise SystemExit("overlay segment %04X not found" % seg)


def operand_mask(md, code, ofs):
    mask = set()
    for ins in md.disasm(code, ofs):
        if ins.mnemonic in ("call", "lcall"):
            if ins.bytes[0] == 0xE8:
                mask.update(ins.address + 1 - ofs + i for i in range(2))
            elif ins.bytes[0] == 0x9A:
                mask.update(ins.address + 1 - ofs + i for i in range(4))
        elif ins.mnemonic == "jmp":
            if ins.bytes[0] == 0xEB:
                mask.add(ins.address + 1 - ofs)
            elif ins.bytes[0] == 0xE9:
                mask.update(ins.address + 1 - ofs + i for i in range(2))
            elif ins.bytes[0] == 0xEA:
                mask.update(ins.address + 1 - ofs + i for i in range(4))
        elif ins.mnemonic.startswith("j") and 0x70 <= ins.bytes[0] <= 0x7F:
            mask.add(ins.address + 1 - ofs)
    return mask


def main():
    segdata, pub = parse_omf(OBJ)
    image = open(EXE, "rb").read()
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_16)
    ok = True
    for name, seg, ofs, length in FUNCS:
        segno, pos = pub[name]
        compiled = bytes(segdata[segno][pos:pos + length])
        end = compiled.find(b"\x5d\xcb")
        if end < 0:
            print("FAIL %-22s no retf in compiled body" % name)
            ok = False
            continue
        compiled = compiled[:end + 2]
        start = overlay_offset(seg) + ofs
        original = image[start:start + length]
        if len(compiled) != length:
            print("FAIL %-22s length %d != %d" % (name, len(compiled), length))
            ok = False
            continue
        mask = operand_mask(md, compiled, ofs)
        diffs = [i for i in range(length) if compiled[i] != original[i]]
        bad = [i for i in diffs if i not in mask]
        if bad:
            print("FAIL %-22s unmasked differences at %s"
                  % (name, [hex(x) for x in bad[:12]]))
            ok = False
        elif diffs:
            print("OK   %-22s %d bytes, %d relocated operands"
                  % (name, length, len(diffs)))
        else:
            print("OK   %-22s %d bytes, exact match" % (name, length))
    if not ok:
        raise SystemExit(1)
    print("UI functions: all compiled bodies match the original overlay")


if __name__ == "__main__":
    main()
