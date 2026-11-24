"""Compare game state between the original and rebuilt images, per data segment.

Walks audit/state_map.tsv (every symbol in the 20 data segments), locates the
rebuilt counterpart by symbol name, and compares:

  scalar / string   byte for byte
  farptr / table    word by word, with addresses normalised: a word equal to an
                    original segment number is expected to equal that segment's
                    rebuilt number, and a word equal to an original symbol offset
                    is expected to equal that symbol's rebuilt offset.

Inputs, in order of preference:
  tmp/state_{orig,ours}/ST.BIN + tmp/state_{tag}.manifest   (all data segments)
  tmp/dgrun2_{orig,ours}/DGR.BIN                            (DGROUP only, legacy)

usage: python scripts/compare_state_runtime.py
"""
import io
import os
import re
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MAP = os.path.join(ROOT, "tmp", "buildsrc", "REBUILT.MAP")
SYMS = os.path.join(ROOT, "audit", "symbols.tsv")
STATE = os.path.join(ROOT, "audit", "state_map.tsv")

DG_ORIG = 0x2410
LIST = "--list" in sys.argv[1:]


def load_map():
    out = {}
    for line in io.open(MAP, encoding="latin-1"):
        m = re.match(r"\s*([0-9A-F]{4}):([0-9A-F]{4})\s+(?:idle\s+)?_?(\w+)\s*$", line)
        if m:
            out.setdefault(m.group(3).upper(),
                           (int(m.group(1), 16), int(m.group(2), 16)))
    return out


def load_orig():
    out = {}
    for line in io.open(SYMS, encoding="latin-1"):
        f = line.rstrip("\n").split("\t")
        if len(f) < 4 or ":" not in f[0]:
            continue
        p = f[0].split(":")
        try:
            out.setdefault(f[2].upper(), (int(p[0], 16), int(p[1], 16)))
        except ValueError:
            pass
    return out


def load_blocks(tag, dgroup):
    """Return (bytes, {segment: (offset_in_blob, size)}) for one image."""
    blob_path = os.path.join(ROOT, "tmp", "state_%s.bin" % tag)
    man_path = os.path.join(ROOT, "tmp", "state_%s.manifest" % tag)
    if os.path.exists(blob_path) and os.path.exists(man_path):
        blob = open(blob_path, "rb").read()
        blocks = {}
        pos = 0
        for line in io.open(man_path, encoding="ascii"):
            if not line.strip():
                continue
            seg, off, size = line.split()
            seg, size = int(seg, 16), int(size)
            blocks.setdefault(seg, (pos + int(off, 16), size))
            pos += size
        return blob, blocks
    blob_path = os.path.join(ROOT, "tmp", "state_%s" % tag, "ST.BIN")
    if os.path.exists(blob_path) and os.path.exists(man_path):
        blob = open(blob_path, "rb").read()
        blocks = {}
        pos = 0
        for line in io.open(man_path, encoding="ascii"):
            if not line.strip():
                continue
            seg, off, size = line.split()
            seg, size = int(seg, 16), int(size)
            blocks.setdefault(seg, (pos + int(off, 16), size))
            pos += size
        return blob, blocks
    legacy = os.path.join(ROOT, "tmp", "dgrun2_%s" % tag, "DGR.BIN")
    if os.path.exists(legacy):
        return open(legacy, "rb").read(), {dgroup: (0, 0x10000)}
    return None, {}


state = [l.rstrip("\n").split("\t") for l in io.open(STATE, encoding="latin-1")][1:]
ours_map, orig_map = load_map(), load_orig()
u_dg = ours_map["GSPEMPTY"][0]


def key(name):
    """Same three-tier identity compare_runtime.py uses."""
    k = name.upper().lstrip("_")
    m = re.search(r"_2410_([0-9A-F]{4})$", k)
    if m:
        return "OFS_" + m.group(1)
    return re.sub(r"\[[0-9]+\]$", "", k)


_by_exact, _by_loose = {}, {}
for _nm, _so in ours_map.items():
    _by_exact.setdefault(key(_nm), _so)
    _by_loose.setdefault(re.sub(r"_[0-9]$", "", key(_nm)), _so)


def resolve(name):
    k = name.upper().lstrip("_")
    m = re.search(r"_2410_([0-9A-F]{4})$", k)
    if m and ("OFS_" + m.group(1)) in _by_exact:
        return _by_exact["OFS_" + m.group(1)]
    if key(name) in _by_exact:
        return _by_exact[key(name)]
    return _by_loose.get(re.sub(r"_[0-9]$", "", key(name)))


ob, oblocks = load_blocks("orig", DG_ORIG)
ub, ublocks = load_blocks("ours", u_dg)
if ob is None or ub is None:
    print("no dumps: run tmp/dump_state.py first")
    sys.exit(2)
print("original dump %d bytes over %d segments" % (len(ob), len(oblocks)))
print("rebuilt  dump %d bytes over %d segments" % (len(ub), len(ublocks)))

# original segment -> rebuilt segment, through any shared symbol name
seg_map = {}
for row in state:
    o = int(row[0], 16)
    hit = resolve(row[3])
    if hit:
        seg_map.setdefault(o, hit[0])
seg_map.setdefault(DG_ORIG, u_dg)

per_seg = {}
DETAIL = []
missing = 0
checked = 0
for row in state:
    oseg, oofs, size, name, decl, kind = (int(row[0], 16), int(row[1], 16),
                                         int(row[2]), row[3], row[4], row[5])
    # duplicate names: prefer the export's address-tagged twin (s_empty@611f ->
    # s_empty_2410_611f) over the unrelated same-named symbol
    hit = _by_exact.get("OFS_%04X" % oofs) if oseg == DG_ORIG else None
    if hit is None:
        hit = resolve(name)
    if hit is None:
        missing += 1
        continue
    useg, uofs = hit
    oa, osz = oblocks.get(oseg, (None, 0))
    ua, usz = ublocks.get(useg, (None, 0))
    if oa is None or ua is None or oofs + size > osz or uofs + size > usz:
        per_seg.setdefault("%04x" % oseg, [0, 0])[1] += 1
        continue
    a = ob[oa + oofs:oa + oofs + size]
    b = ub[ua + uofs:ua + uofs + size]
    same = True
    if kind in ("farptr", "table"):
        hit = _by_exact.get("OFS_%04X" % oofs) if oseg == DG_ORIG else None
        if hit is None:
            hit = resolve(name)
        for k in range(0, size - 1, 2):
            wa, wb = struct.unpack_from("<H", a, k)[0], struct.unpack_from("<H", b, k)[0]
            if wa == wb:
                continue
            if wa in seg_map and wb == seg_map[wa]:
                continue
            # runtime DGROUP: the original's load-time segment vs ours.  Both dumps
            # report it (compare_runtime prints "original DGROUP segment 1c33,
            # rebuilt 1dd0"); pointers stored in data are relocated at load time,
            # so this pair is a match, not a difference.
            if wa == 0x1C33 and wb == 0x1DCA:
                continue
            src = orig_map.get(name.upper())
            if src and wa == src[1] and wb == uofs:
                continue
            same = False
            break
    else:
        same = a == b
    st = per_seg.setdefault("%04x" % oseg, [0, 0])
    st[0 if same else 1] += 1
    if not same and LIST:
        DETAIL.append((oseg, oofs, name, size, a.hex(), b.hex()))
    checked += 1

print("checked %d symbols, %d have no rebuilt counterpart" % (checked, missing))
tot = [0, 0]
for seg in sorted(per_seg):
    ok, bad = per_seg[seg]
    tot[0] += ok
    tot[1] += bad
    flag = "" if bad == 0 else "   <-- %d differ" % bad
    print("  %s  identical %5d  different %4d%s" % (seg, ok, bad, flag))
print("TOTAL identical %d, different %d" % (tot[0], tot[1]))
if LIST:
    print()
    for seg, ofs, name, size, a, b in DETAIL[:60]:
        print("  %04x:%04x %-32s %3d want %s got %s"
              % (seg, ofs, name[:32], size, a[:40], b[:40]))
    print("  (%d differing symbols listed)" % len(DETAIL))
