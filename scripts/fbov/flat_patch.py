#!/usr/bin/env python3
"""Apply the original EXE's MZ relocations and FBOV fixups to the flat build.

Reads tmp/flat/FLAT.EXE + FLAT.MAP + segmap.json + doc/fbov_manifest.json and
rewrites FLAT.EXE so that every original segment reference points at the
corresponding flat segment.  New MZ relocation entries are added so DOS adds
the load segment at run time.
"""
import json
import os
import re
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
FLAT = os.path.join(ROOT, "tmp", "flat")
MAN = os.path.join(ROOT, "doc", "fbov_manifest.json")

exe_path = sys.argv[1] if len(sys.argv) > 1 else os.path.join(FLAT, "FLAT.EXE")
map_path = sys.argv[2] if len(sys.argv) > 2 else os.path.join(FLAT, "FLAT.MAP")

man = json.load(open(MAN))
segmap = json.load(open(os.path.join(FLAT, "segmap.json")))

# ---- parse the link map -------------------------------------------------
start = {}
symtab = {}
pat = re.compile(r"^\s*([0-9A-F]+)H\s+([0-9A-F]+)H\s+([0-9A-F]+)H\s+(\S+)")
sympat = re.compile(r"^\s*([0-9A-F]{4}):([0-9A-F]{4})\s+(\S+)")
for line in open(map_path, encoding="ascii", errors="replace"):
    m = pat.match(line)
    if m:
        start[m.group(4)] = int(m.group(1), 16)
        continue
    m = sympat.match(line)
    if m:
        symtab[m.group(3).upper()] = (int(m.group(1), 16), int(m.group(2), 16))

# ---- original static segment -> flat content start (bytes) --------------
orig = {}


def add(static, name):
    if name not in start:
        raise SystemExit("segment %s (for %04X) missing from map" % (name, static))
    orig[static] = start[name]


add(0x2410, "_DATA")
add(0x1301, "MAIN_TEXT")
for s, v in segmap["code"].items():
    add(int(s), v["seg"])
for s, v in segmap["data"].items():
    add(int(s), v["seg"])
for s, v in segmap["headers"].items():
    add(int(s), v["seg"])
for ov in man["overlays"]:
    add(ov["code_seg"], "OV_%04X_TEXT" % ov["code_seg"])

zero_para = start[segmap["zero"]] // 16


def flat_para(static):
    if static in orig:
        return orig[static] // 16
    if static >= 0x2CA0:
        return zero_para
    raise SystemExit("no flat segment for original static %04X" % static)


def site_pos(static, ofs):
    return orig[static] + ofs


# ---- read the EXE -------------------------------------------------------
raw = bytearray(open(exe_path, "rb").read())
(e_magic, e_cblp, e_cp, e_crlc, e_cparhdr, e_minalloc, e_maxalloc,
 e_ss, e_sp, e_csum, e_ip, e_cs, e_lfarlc, e_ovno) = struct.unpack_from(
    "<14H", raw, 0)
image_off = e_cparhdr * 16
image = raw[image_off:]

old_relocs = []
for i in range(e_crlc):
    old_relocs.append(struct.unpack_from("<HH", raw, e_lfarlc + 4 * i))
reloc_set = set(old_relocs)


def read_word(pos, site):
    if pos + 1 >= len(image):
        raise SystemExit("site %04X outside image" % site)
    return struct.unpack_from("<H", image, pos)[0]


def write_word(pos, val, site):
    if pos + 1 >= len(image):
        raise SystemExit("site %04X outside image" % site)
    struct.pack_into("<H", image, pos, val)


new_relocs = []
patched = 0
skipped = 0

# ---- MZ relocations -----------------------------------------------------
for r in man["relocs"]:
    target = r["target_seg"]
    if target == 0:
        # raw value 0 denotes the resident segment (static 0x1000)
        target = 0x1000
    if not target:
        skipped += 1
        continue
    site_static = 0x1000 + r["seg"]
    if site_static == 0x1301:
        # main is compiled from C: Turbo Link already resolved every far
        # reference to the flat code segment, and its offset words point at
        # the recovered functions directly.  Re-targeting them at the
        # overlay-header trampolines would mismatch the offset.
        continue
    pos = site_pos(site_static, r["ofs"])
    write_word(pos, flat_para(target), r["file_offset"])
    patched += 1
    ofs = pos % 16
    seg = pos // 16
    if (ofs, seg) not in reloc_set:
        reloc_set.add((ofs, seg))
        new_relocs.append((ofs, seg))

# ---- FBOV overlay fixups ------------------------------------------------
for f in man["fixups"]:
    target = f["target_seg"]
    if not target:
        skipped += 1
        continue
    site_static = f["site_seg"]
    pos = site_pos(site_static, f["site_ofs"])
    write_word(pos, flat_para(target), f["site_file_offset"])
    patched += 1
    ofs = pos % 16
    seg = pos // 16
    if (ofs, seg) not in reloc_set:
        reloc_set.add((ofs, seg))
        new_relocs.append((ofs, seg))

# ---- header trampolines -------------------------------------------------
for static_s, info in segmap["headers"].items():
    para = start[info["seg"]]
    for ent in info.get("entries", []):
        tgt_seg = start["OV_%04X_TEXT" % ent["code"]] // 16
        tgt_ofs = ent["target"]
        pos = para + ent["off"]
        image[pos] = 0xEA
        struct.pack_into("<H", image, pos + 1, tgt_ofs)
        struct.pack_into("<H", image, pos + 3, tgt_seg)
        patched += 1
        ofs = (pos + 3) % 16
        seg = (pos + 3) // 16
        if (ofs, seg) not in reloc_set:
            reloc_set.add((ofs, seg))
            new_relocs.append((ofs, seg))

# ---- skip the VROOMM overlay-manager initialiser ------------------------
# The C0 init table entry at DGROUP:0x8916 calls __OvrInit, which insists on
# reading a Borland FBOV trailer from the program file.  The flat build has
# no overlays, so neutralise that one entry.
init_flag = orig[0x2410] + 0x8916
image[init_flag] = 0xFF

# ---- rebuild the file with an enlarged relocation table -----------------
all_relocs = old_relocs + new_relocs
lfarlc = e_lfarlc
need = lfarlc + 4 * len(all_relocs)
new_parhdr = max(e_cparhdr, (need + 15) // 16)
header = bytearray(new_parhdr * 16)
header[:image_off] = raw[:image_off]
for i, (ofs, seg) in enumerate(all_relocs):
    struct.pack_into("<HH", header, lfarlc + 4 * i, ofs, seg)

out = header + image
size = len(out)
# Put the initial stack after the whole image.  Turbo Link placed _STACK
# immediately before the code segments, so the MZ SS would otherwise point
# inside the image; the C0 startup then grows its stack over the game code.
image_paras = (len(image) + 15) // 16
e_ss = image_paras + 0x10
e_sp = 0x1000
if size % 512 == 0:
    e_cblp, e_cp = 0, size // 512
else:
    e_cp = size // 512 + 1
    e_cblp = size % 512

struct.pack_into("<H", out, 2, e_cblp)
struct.pack_into("<H", out, 4, e_cp)
struct.pack_into("<H", out, 6, len(all_relocs))
struct.pack_into("<H", out, 8, new_parhdr)
struct.pack_into("<H", out, 0x0E, e_ss)
struct.pack_into("<H", out, 0x10, e_sp)

open(exe_path, "wb").write(out)
print("patched %d sites (%d skipped); relocs %d -> %d; header %d -> %d; size %d"
      % (patched, skipped, len(old_relocs), len(all_relocs),
         e_cparhdr, new_parhdr, len(out)))
