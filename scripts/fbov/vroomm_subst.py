#!/usr/bin/env python3
"""Substitute one recovered function into the VROOMM baseline.

The compiled function is compared with the original bytes at its original
segment:offset.  Differences are allowed only inside direct call/jump
operands; those operands are taken from the original image (they encode the
original segment addresses).  The patched bytes are written back to the staged
EXE, and the tool asserts that the FBOV-relevant image layout is unchanged.

Example:
  python scripts/fbov/vroomm_subst.py --seg 1301 --ofs 000C --len 2246 \
      --compiled tmp/linkbuild/OUT.EXE --compiled-ofs 94AB
"""
import argparse
import os
import struct

import capstone

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
STAGED = os.path.join(ROOT, "tmp", "vroomm", "STRONG.EXE")
LOAD = 0x1E00
STATIC_BASE = 0x1000


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--seg", help="original static segment, e.g. 1301")
    ap.add_argument("--ofs", required=True, help="offset inside that segment")
    ap.add_argument("--len", required=True, type=int)
    ap.add_argument("--compiled", help="linked EXE containing the function")
    ap.add_argument("--compiled-ofs", help="image offset inside --compiled")
    ap.add_argument("--obj", help="OMF object containing an overlay function")
    ap.add_argument("--name", help="symbol in --obj")
    ap.add_argument("--linked-exe", help="linked harness EXE containing an overlay function")
    ap.add_argument("--linked-map", help="map file for --linked-exe")
    ap.add_argument("--symbol", help="symbol in --linked-map, e.g. _F_3381_01C8")
    ap.add_argument("--segname", help="code segment in --linked-map, e.g. OV_3381_TEXT")
    ap.add_argument("--overlay-seg", help="overlay code segment, e.g. 3381")
    a = ap.parse_args()

    if a.obj or a.linked_exe:
        import csv
        import sys
        sys.path.insert(0, os.path.join(ROOT, "scripts", "fbov"))

        seg = int(a.overlay_seg, 16)
        ofs = int(a.ofs, 16)
        pos = None
        for r in csv.DictReader(open(os.path.join(ROOT, "doc", "fbov_overlays.csv"))):
            if int(r["code_seg"], 16) == seg:
                pos = int(r["code_file_offset"], 0) + ofs - int(r["code_disp"], 16)
                break
        if pos is None:
            raise SystemExit("overlay segment not found")
        staged = bytearray(open(STAGED, "rb").read())
        orig_pos = pos
        original = bytes(staged[orig_pos:orig_pos + a.len])
        if a.obj:
            from byte_match import parse_omf
            segdata, pub = parse_omf(a.obj)
            sseg, soff = pub[a.name]
            compiled = bytes(segdata[sseg][soff:soff + a.len])
        else:
            from link_compare import load_image
            _, real = load_image(a.linked_map, a.segname, a.symbol)
            cdata = open(a.linked_exe, "rb").read()
            cimage = struct.unpack_from("<H", cdata, 8)[0] * 16
            compiled = cdata[cimage + real:cimage + real + a.len]
    else:
        seg = int(a.seg, 16)
        ofs = int(a.ofs, 16)
        cseg = int(a.compiled_ofs, 16)
        staged = bytearray(open(STAGED, "rb").read())
        orig_pos = LOAD + (seg - STATIC_BASE) * 16 + ofs
        original = bytes(staged[orig_pos:orig_pos + a.len])
        cdata = open(a.compiled, "rb").read()
        cimage = struct.unpack_from("<H", cdata, 8)[0] * 16
        compiled = cdata[cimage + cseg:cimage + cseg + a.len]

    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_16)
    mask = set()
    for ins in md.disasm(compiled, ofs):
        if ins.mnemonic in ("call", "lcall"):
            if ins.bytes[0] in (0xE8, 0x9A):
                n = 2 if ins.bytes[0] == 0xE8 else 4
                mask.update(ins.address + 1 - ofs + i for i in range(n))
        elif ins.mnemonic == "jmp":
            if ins.bytes[0] == 0xEB:
                mask.add(ins.address + 1 - ofs)
            elif ins.bytes[0] == 0xE9:
                mask.update(ins.address + 1 - ofs + i for i in range(2))
            elif ins.bytes[0] == 0xEA:
                mask.update(ins.address + 1 - ofs + i for i in range(4))
        elif ins.mnemonic.startswith("j") and ins.bytes[0] >= 0x70 and ins.bytes[0] <= 0x7F:
            mask.add(ins.address + 1 - ofs)

    diffs = [i for i in range(a.len) if compiled[i] != original[i]]
    # The overlay linker rewrites cross-module far calls to
    # `nop; push cs; call rel16` (or the nop after the call).
    for i in range(a.len - 4):
        if compiled[i] != 0x9A:
            continue
        nop_first = (original[i] == 0x90 and original[i + 1] == 0x0E
                     and original[i + 2] == 0xE8)
        nop_last = (original[i] == 0x0E and original[i + 1] == 0xE8
                    and original[i + 4] == 0x90)
        if nop_first or nop_last:
            mask.update(range(i, i + 5))
    bad = [i for i in diffs if i not in mask]
    if bad:
        raise SystemExit("unmasked differences at %s" % [hex(x) for x in bad[:20]])

    patched = bytearray(compiled)
    for i in diffs:
        patched[i] = original[i]
    if bytes(patched) != original:
        raise SystemExit("relocated body does not match the original bytes")

    staged[orig_pos:orig_pos + a.len] = patched
    open(STAGED, "wb").write(staged)
    print("substituted %04X:%04X (%d bytes); %d differences, all call/jump operands; image unchanged"
          % (seg, ofs, a.len, len(diffs)))


if __name__ == "__main__":
    main()
