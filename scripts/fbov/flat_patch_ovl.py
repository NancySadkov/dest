#!/usr/bin/env python3
"""Patch the resident-overlay-loader build.

Compared with flat_patch.py:
  * overlay code is not in the image; it becomes OVL.BIN with per-overlay
    fixup tables applied by the resident loader,
  * header segments are already INT 3F entries,
  * the C0 init-table entry is pointed at _ovl_init.
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
exe_orig = open(os.path.join(ROOT, "game", "STRONG.EXE"), "rb").read()

# ---- map ---------------------------------------------------------------
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

orig = {}


def add(static, name):
    if name not in start:
        raise SystemExit("segment %s (%04X) missing" % (name, static))
    orig[static] = start[name]


add(0x2410, "_DATA")
add(0x1301, "MAIN_TEXT")
for s, v in segmap["code"].items():
    add(int(s), v["seg"])
for s, v in segmap["data"].items():
    add(int(s), v["seg"])
for s, v in segmap["headers"].items():
    add(int(s), v["seg"])
for s, v in segmap.get("ov_ids", {}).items():
    pass

zero_para = start[segmap["zero"]] // 16


def flat_para(static):
    if static in orig:
        return orig[static] // 16
    if static >= 0x2CA0:
        return zero_para
    raise SystemExit("no flat segment for static %04X" % static)


# ---- image -------------------------------------------------------------
raw = bytearray(open(exe_path, "rb").read())
(e_magic, e_cblp, e_cp, e_crlc, e_cparhdr, e_minalloc, e_maxalloc,
 e_ss, e_sp, e_csum, e_ip, e_cs, e_lfarlc, e_ovno) = struct.unpack_from(
    "<14H", raw, 0)
image_off = e_cparhdr * 16
image = raw[image_off:]

old_relocs = [struct.unpack_from("<HH", raw, e_lfarlc + 4 * i)
              for i in range(e_crlc)]
reloc_set = set(old_relocs)
new_relocs = []


def write_word(pos, val):
    struct.pack_into("<H", image, pos, val)


def add_reloc(pos):
    ofs, seg = pos % 16, pos // 16
    if (ofs, seg) not in reloc_set:
        reloc_set.add((ofs, seg))
        new_relocs.append((ofs, seg))


# ---- MZ relocations (resident image only) ------------------------------
patched = 0
for r in man["relocs"]:
    target = r["target_seg"]
    if target == 0:
        target = 0x1000
    site_static = 0x1000 + r["seg"]
    if site_static == 0x1301:
        continue            # main's Turbo Link references are already right
    if site_static not in orig:
        continue
    pos = orig[site_static] + r["ofs"]
    write_word(pos, flat_para(target))
    add_reloc(pos)
    patched += 1

# ---- point the C0 init record at _ovl_init -----------------------------
if "_OVL_INIT" not in symtab:
    raise SystemExit("_ovl_init missing from map")
init_seg, init_ofs = symtab["_OVL_INIT"]
dg = orig[0x2410]
image[dg + 0x8916] = 1                 # flag: far init function
write_word(dg + 0x8918, init_ofs)
write_word(dg + 0x891A, init_seg)
add_reloc(dg + 0x891A)

# ---- generate OVL.BIN and the loader metadata -------------------------
ovex = open(os.path.join(ROOT, "game", "STRONG.EXE"), "rb").read()
ovs = sorted(man["overlays"], key=lambda o: o["code_seg"])
fix_by_seg = {}
for f in man["fixups"]:
    fix_by_seg.setdefault(f["site_seg"], []).append(f)

ovl = bytearray()
codesz = []
fixcnt = []
codeoff = []
fixoff = []
for ov in ovs:
    code = ovex[ov["code_file_offset"]:ov["code_file_offset"] + ov["codesz"]]
    fx = fix_by_seg.get(ov["code_seg"], [])
    codeoff.append(len(ovl))
    ovl += code
    fixoff.append(len(ovl))
    for f in fx:
        ovl += struct.pack("<HH", f["site_ofs"], flat_para(f["target_seg"]))
    codesz.append(ov["codesz"])
    fixcnt.append(len(fx))

open(os.path.join(FLAT, "OVL.BIN"), "wb").write(ovl)

arrays = {
    "_OVL_CODESZ": codesz,
    "_OVL_FIXCNT": fixcnt,
    "_OVL_CODEOFF_LO": [v & 0xFFFF for v in codeoff],
    "_OVL_CODEOFF_HI": [(v >> 16) & 0xFFFF for v in codeoff],
    "_OVL_FIXOFF_LO": [v & 0xFFFF for v in fixoff],
    "_OVL_FIXOFF_HI": [(v >> 16) & 0xFFFF for v in fixoff],
    "_OVL_SLOT_PARA": [start[name] // 16 for name in segmap["slots"]],
}
for name, vals in arrays.items():
    key = "_" + name.lstrip("_").upper()
    if key not in symtab:
        raise SystemExit("%s missing from map" % key)
    seg, ofs = symtab[key]
    base = seg * 16 + ofs
    for i, v in enumerate(vals):
        struct.pack_into("<H", image, base + 2 * i, v)

print("patched %d sites; %d overlays; OVL.BIN %d bytes"
      % (patched, len(ovs), len(ovl)))

# ---- rebuild EXE with the enlarged relocation table --------------------
all_relocs = old_relocs + new_relocs
need = e_lfarlc + 4 * len(all_relocs)
new_parhdr = max(e_cparhdr, (need + 15) // 16)
header = bytearray(new_parhdr * 16)
header[:image_off] = raw[:image_off]
for i, (ofs, seg) in enumerate(all_relocs):
    struct.pack_into("<HH", header, e_lfarlc + 4 * i, ofs, seg)

out = header + image
size = len(out)
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
print("relocs %d -> %d; header %d -> %d; size %d"
      % (len(old_relocs), len(all_relocs), e_cparhdr, new_parhdr, len(out)))
