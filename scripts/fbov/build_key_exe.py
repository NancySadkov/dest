#!/usr/bin/env python3
"""Build a functional EXE with the recovered gameProcessKey in its original slot.

The C image is built by make_key_image.py (true DGROUP offsets + original far
call operands).  The original FBOV fixup table is rewritten so every new call
site is relocated by the loader exactly like the original calls, and the old
data-fixup sites inside the replaced function point at harmless padding.

The image is 604 bytes and replaces 2E25:0ADF..0D3A in place.
"""
import csv
import json
import os
import shutil
import struct
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
OV_SEG = "2E25"
OV_OFS = 0x0ADF
OV_SIZE = 0x25C
PAD_SITE = 0x0D20


def overlay_row():
    for r in csv.DictReader(open(os.path.join(ROOT, "doc",
                                              "fbov_overlays.csv"))):
        if r["code_seg"] == OV_SEG:
            return r
    raise SystemExit("overlay not found")


def patch_fixups(path):
    row = overlay_row()
    table_off = int(row["code_file_offset"], 0) + int(row["codesz"], 16)
    table_sz = int(row["fixupsz"], 16)

    exe = open(os.path.join(ROOT, "game", "STRONG.EXE"), "rb").read()
    man = json.load(open(os.path.join(ROOT, "doc", "fbov_manifest.json")))
    ov = [x for x in man["overlays"] if x["code_seg"] == int(OV_SEG, 16)][0]
    orig = exe[ov["code_file_offset"]:ov["code_file_offset"] + ov["codesz"]]
    image = open(os.path.join(ROOT, "tmp", "key_patched.bin"), "rb").read()

    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_16)
    new_calls = [OV_OFS + x.address + 3 for x in md.disasm(image, 0)
                 if x.mnemonic == "lcall"]

    kinds = {}
    for r in csv.DictReader(open(os.path.join(ROOT, "doc",
                                              "fbov_fixups.csv"))):
        if r["code_seg"] == OV_SEG:
            kinds[int(r["site_ofs"], 16)] = r["target_class"]

    data = bytearray(open(path, "rb").read())
    vals = list(struct.unpack_from("<%dH" % (table_sz // 2), data, table_off))
    old_calls = []
    for i, q in enumerate(vals):
        if (OV_OFS <= q < OV_OFS + OV_SIZE and kinds.get(q) == "OVR"
                and orig[q - 3] == 0x9A):
            old_calls.append((i, q))
    if len(old_calls) != len(new_calls):
        raise SystemExit("fixup call mismatch: %d/%d" %
                         (len(old_calls), len(new_calls)))
    old_calls.sort(key=lambda x: x[1])
    new_sorted = sorted(new_calls)
    call_sites = {}
    for (idx, _), nq in zip(old_calls, new_sorted):
        vals[idx] = nq
        call_sites[idx] = nq
    moved = 0
    for i, q in enumerate(vals):
        if i in call_sites:
            continue
        if OV_OFS <= q < OV_OFS + OV_SIZE:
            vals[i] = PAD_SITE
            moved += 1
    struct.pack_into("<%dH" % len(vals), data, table_off, *vals)
    open(path, "wb").write(data)
    print("rewrote %d call fixups, %d data fixups -> pad %04X"
          % (len(old_calls), moved, PAD_SITE))


def main():
    subprocess.run([sys.executable,
                    os.path.join(ROOT, "scripts", "fbov",
                                 "make_key_image.py")], check=True)
    image = open(os.path.join(ROOT, "tmp", "key_patched.bin"), "rb").read()
    if len(image) != OV_SIZE:
        raise SystemExit("key image size %d != %d" % (len(image), OV_SIZE))

    ovpath = os.path.join(ROOT, "tmp", "ovcode", "OV_2E25.BIN")
    backup = ovpath + ".bak"
    shutil.copyfile(ovpath, backup)
    try:
        d = bytearray(open(ovpath, "rb").read())
        d[OV_OFS:OV_OFS + OV_SIZE] = image
        open(ovpath, "wb").write(d)
        out = os.path.join(ROOT, "out", "STRONG_KEY.EXE")
        subprocess.run([sys.executable,
                        os.path.join(ROOT, "scripts", "fbov",
                                     "build_standalone.py"),
                        "--skip-overlays", "--skip-static", "--skip-mz",
                        "--allow-mismatch", "--out", out], check=True)
    finally:
        shutil.move(backup, ovpath)

    patch_fixups(out)
    print("wrote", out)


if __name__ == "__main__":
    main()
