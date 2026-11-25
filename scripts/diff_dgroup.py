"""Diff the recovered DGROUP layout against the original's addresses.

The original EXE lists every DGROUP symbol with its offset in
audit/symbols.tsv (block 2410_DATA_DGROUP).  A TLINK map built with /m lists
the same publics with our offsets.  If the recovered data is byte-identical in
order and padding, then `our_offset - original_offset` is one constant for
every symbol; whenever a gap is lost or invented, the constant changes by
exactly that many bytes.

That is how the four missing 4-byte enemy-band tables were found
(doc/dgroup_layout.md); this script makes the check systematic.

Usage: python scripts/diff_dgroup.py [--verbose]
"""
import io
import re
import sys

MAP = "tmp/buildsrc/REBUILT.MAP"
SYMS = "audit/symbols.tsv"

verbose = "--verbose" in sys.argv
why = "--why" in sys.argv
list_path = (sys.argv[sys.argv.index("--list") + 1]
             if "--list" in sys.argv else None)

# ---- original DGROUP symbols -------------------------------------------------
orig = []          # (address, name)
for line in io.open(SYMS, encoding="utf-8"):
    f = line.rstrip("\n").split("\t")
    if len(f) < 4:
        continue
    addr, block, name, kind = f[0], f[1], f[2], f[3]
    if block != "2410_DATA_DGROUP":
        continue
    if kind not in ("Label",):
        continue
    if "[" in name:            # element labels collide with the array base
        continue
    if name.startswith(("__C0", "_argc", "_argv", "_environ", "_env", "_psp",
                        "DosVersion", "errno", "__brklvl", "_heapbase",
                        "__stklen", "__ovr")):
        continue               # the startup's own data belongs to C0M, not to us
    if ":" not in addr:
        continue
    off = int(addr.split(":")[1], 16)
    orig.append((off, name))
orig.sort()

# ---- our publics -------------------------------------------------------------
pat = re.compile(r"^\s*([0-9A-Fa-f]{4}):([0-9A-Fa-f]{4})\s+(?:\S+\s+)?(\S+)\s*$")
ours = {}
for line in io.open(MAP, encoding="latin-1", errors="replace"):
    m = pat.match(line.rstrip("\n"))
    if not m:
        continue
    seg, ofs, name = int(m.group(1), 16), int(m.group(2), 16), m.group(3)
    ours.setdefault(name.upper(), (seg, ofs))

def key(name):
    k = name.upper().lstrip("_")
    k = re.sub(r"\[[0-9]+\]$", "", k)
    k = re.sub(r"_[0-9]$", "", k)
    return k

# our DGROUP segment: the map's _DATA segment (all our near data lives there)
dgroup_seg = None
for name, (seg, ofs) in ours.items():
    if key(name) == "DATA" and ofs == 0:
        dgroup_seg = seg
if dgroup_seg is None:
    dgroup_seg = ours.get("_ANIMSEQCOUNTS", (None, None))[0]
print("rebuilt DGROUP segment: %04x" % dgroup_seg if dgroup_seg else "DGROUP not found")

ours_by_key = {}
for name, (seg, ofs) in ours.items():
    if seg != dgroup_seg:
        continue
    ours_by_key.setdefault(key(name), []).append((ofs, name))
for k in ours_by_key:
    ours_by_key[k].sort()

matched = []
unmatched = []      # (off, name, reason)
last = -1
used = set()
for off, name in orig:
    k = key(name)
    cands = ours_by_key.get(k)
    if not cands:
        unmatched.append((off, name, "no name with this key"))
        continue
    # duplicate names (the original reuses s_mage for "Mage" and "mage"):
    # consume the next public in address order so each maps once
    pick = None
    for oofs, oname in cands:
        if (seg_ok := True) and oofs not in used and oofs > last:
            pick = (oofs, oname)
            break
    if pick is None:
        for oofs, oname in cands:
            if oofs not in used:
                pick = (oofs, oname)
                break
    if pick is None:
        unmatched.append((off, name, "candidate already consumed"))
        continue
    used.add(pick[0])
    last = pick[0]
    matched.append((off, name, pick[0], dgroup_seg))

print("original DGROUP symbols: %d, matched in the rebuilt image: %d"
      % (len(orig), len(matched)))

# ---- constant-delta runs -----------------------------------------------------
if not matched:
    print("no matches - is the map built with /m?")
    raise SystemExit(1)

runs = []          # (delta, first_orig_off, first_name, count)
for off, name, oofs, seg in matched:
    d = oofs - off
    if not runs or runs[-1][0] != d:
        runs.append([d, off, name, 1])
    else:
        runs[-1][3] += 1

if why:
    # classify: interior labels have no counterpart by construction; the rest are
    # either a name variant of one of our symbols or genuinely absent.
    def strip_suffix(n):
        return re.sub(r"_2410_[0-9A-Fa-f]{4}$", "", n.upper().lstrip("_"))

    ours_stripped = {}
    for nm, (seg, ofs) in ours.items():
        if seg == dgroup_seg:
            ours_stripped.setdefault(strip_suffix(nm), []).append(nm)

    buckets = {}
    variants = []
    for off, name, reason in unmatched:
        if "+" in name:
            cls = "interior label (+N) - not a symbol"
        elif name.upper() in ("DATASEG", "DGROUP", "_DATA", "_BSS", "_TEXT"):
            cls = "group/segment name - not a variable"
        elif re.search(r"\.(seg|ofs)$", name):
            cls = "C0 record field label - not a variable"
        elif reason.startswith("candidate already"):
            cls = "duplicate name, all twins consumed"
        elif name.startswith("s_") or name.startswith("S_"):
            cls = "string literal whose name we do not have"
        elif reason.startswith("candidate already"):
            cls = "duplicate name, all twins consumed"
        else:
            v = ours_stripped.get(strip_suffix(name))
            if v:
                cls = "name variant of our symbol"
                variants.append((off, name, v[0]))
            else:
                cls = "no counterpart at all"
        buckets.setdefault(cls, []).append((off, name))
    if list_path:
        with io.open(list_path, "w", encoding="utf-8", newline="\n") as fh:
            for off, name, reason in unmatched:
                fh.write("%04x\t%s\t%s\n" % (off, name, reason))
        print("unmatched list written to %s" % list_path)
    print("unmatched: %d" % len(unmatched))
    for cls, items in sorted(buckets.items(), key=lambda kv: -len(kv[1])):
        print("  %-34s %d" % (cls, len(items)))
        for off, name in items[:6]:
            print("      %04x %s" % (off, name))
    if variants:
        print("  name variants (first 6):")
        for off, name, oname in variants[:6]:
            print("      %04x %-28s ours=%s" % (off, name, oname))

print("distinct layout deltas: %d" % len(runs))
for i, (d, off, name, count) in enumerate(runs):
    note = "  <-- layout changes by %+d bytes here" % (d - runs[i - 1][0]) if i else ""
    print("  delta %+6d from %s (%04x), %d symbols%s"
          % (d, name, off, count, note))
    if verbose:
        for o2, n2, oo2, s2 in matched:
            if o2 >= off and o2 - off < 0x40:
                print("      %04x %-28s ours=%04x:%04x" % (o2, n2, s2, oo2))
