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
absent_path = (sys.argv[sys.argv.index("--list-absent") + 1]
               if "--list-absent" in sys.argv else None)

# ---- original DGROUP symbols -------------------------------------------------
orig = []          # (address, name)
interior = []      # "name+N" labels: inside the object above them, not symbols
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
    if "+" in name:            # interior label of the object above it ("s_x+3")
        if ":" in addr:
            interior.append((int(addr.split(":")[1], 16), name))
        continue
    if name.startswith(("__C0", "_argc", "_argv", "_environ", "_env", "_psp",
                        "DosVersion", "errno", "__brklvl", "_heapbase",
                        "__stklen", "__ovr")):
        continue               # the startup's own data belongs to C0, not to us
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
    # Both sides carry generated names of the form `<text>_2410_<orig-offset>` (the
    # audit's names for truncated/unnamed strings, and ours for the same objects).  The
    # offset is the object's identity, so pair on it directly - names are truncated at
    # different lengths on each side and cannot be compared as text.
    m = re.search(r"_2410_([0-9A-F]{4})$", k)
    if m:
        return "OFS_" + m.group(1)
    k = re.sub(r"\[[0-9]+\]$", "", k)
    # Some original DGROUP labels are not legal C identifiers ("s_bighous1.lbm",
    # "s_Mouse_error.", "s_anim\2rdrag0.lbm"), so the build necessarily emits them with
    # '_' in place of the illegal character.  Apply the same sanitiser to both sides;
    # without it the pair is reported as a miss although it is one object at one place,
    # and the mis-pairing also derails the constant-delta runs.
    k = re.sub(r"[^A-Z0-9_]", "_", k)
    return k


def variant_key(name):
    """`key()` of our names with the generated `_2410_XXXX` offset suffix removed.

    Most of our string symbols are declared as `s_<text>_2410_<orig-offset>`, so the key
    of our `s_cleric_2410_01da` is `OFS_01DA` while the original's name for the same
    object is `s_cleric`.  Without this the pair could only be found by the
    content-matching report, which then attributed it to whatever symbol happened to own
    the address in our layout (`s_cleric -> _S_FRMLND_LBM_2410_2E31`).

    This derives from the *raw* name: it used to strip the suffix from `key(name)`, which
    has already replaced it with `OFS_XXXX`, so the substitution never matched and every
    `_2410_`-suffixed symbol was invisible to this table.  That cost eight pairs
    (`s_change_party`, `s_done`, ... are all declared with offset suffixes here).
    """
    return re.sub(r"_2410_[0-9A-F]{4}$", "", name.upper().lstrip("_"))


def loose_key(name):
    """`key()` without the trailing digit.

    The trailing `_N` is only dropped as a *fallback*: `s_kill_3` and `s_kill_4`
    are two different strings six bytes apart, and stripping the digit up front
    made them collide, which paired `s_kill_3` with `s_kill_4`'s address and
    produced a bogus +6178 delta.  Exact keys are tried first, loose ones only for
    originals that have no exact candidate left.
    """
    return re.sub(r"_[0-9]$", "", key(name))

# our DGROUP segment: the map's _DATA segment (all our near data lives there)
dgroup_seg = None
for name, (seg, ofs) in ours.items():
    if key(name) == "DATA" and ofs == 0:
        dgroup_seg = seg
if dgroup_seg is None:
    dgroup_seg = ours.get("_ANIMSEQCOUNTS", (None, None))[0]
print("rebuilt DGROUP segment: %04x" % dgroup_seg if dgroup_seg else "DGROUP not found")

ours_by_key = {}
ours_by_loose = {}
ours_by_variant = {}
for name, (seg, ofs) in ours.items():
    if seg != dgroup_seg:
        continue
    ours_by_key.setdefault(key(name), []).append((ofs, name))
    ours_by_loose.setdefault(loose_key(name), []).append((ofs, name))
    if variant_key(name) != key(name):
        ours_by_variant.setdefault(variant_key(name), []).append((ofs, name))
for k in ours_by_key:
    ours_by_key[k].sort()
for k in ours_by_loose:
    ours_by_loose[k].sort()
for k in ours_by_variant:
    ours_by_variant[k].sort()

matched = []
unmatched = []      # (off, name, reason)
last = -1
used = set()
def pick_candidate(cands, used, last):
    """First unused candidate, preferring one that keeps the address order."""
    for oofs, oname in cands:
        if oofs not in used and oofs > last:
            return (oofs, oname)
    for oofs, oname in cands:
        if oofs not in used:
            return (oofs, oname)
    return None


for off, name in orig:
    k = key(name)
    # Priority, strictest first: the exact key, then names differing by a trailing
    # `_N`, then our generated names with the `_2410_XXXX` suffix removed.  A table is
    # only consulted when the previous one has no *unused* candidate - concatenating
    # them let `s_kill_3` fall through to our `_S_KILL_4` because the loose key of both
    # is `S_KILL`.
    tag = "_2410_%04X" % off
    pick = None
    had = False
    for tbl, kk in ((ours_by_key, k),
                    (ours_by_loose, loose_key(name)),
                    (ours_by_variant, variant_key(name))):
        cands = list(tbl.get(kk, ()))
        if not cands:
            continue
        had = True
        # a generated name carries the original offset, so that pairing is exact by
        # construction - try it before anything else in this table
        cands.sort(key=lambda c: (not c[1].upper().endswith(tag), c[0]))
        pick = pick_candidate(cands, used, last)
        if pick is not None:
            break
        # this table has candidates but none is free: do NOT fall through to a looser
        # key.  The original really can carry the same name twice (`s_kill_3` at 0x55E5
        # and 0x56F8); falling through paired the second one with `_S_KILL_4` and
        # invented a +6176 delta.
        break
    if pick is None:
        unmatched.append((off, name,
                          "candidate already consumed" if had
                          else "no name with this key"))
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
    if interior:
        buckets.setdefault("interior label (+N) - not a symbol", []).extend(interior)
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
    # ---- content-aware matching (additional rule) ----------------------------
    import csv
    import os
    texts = {}
    try:
        for r in csv.DictReader(io.open("audit/dgroup.csv", encoding="latin-1")):
            if r.get("type") == "string":
                texts[int(r["offset"], 16)] = r.get("repr", "")
    except OSError:
        texts = {}
    dump = b""
    dpath = os.path.join("tmp", "ours_postcfg.bin")
    if os.path.exists(dpath):
        dump = io.open(dpath, "rb").read()
    seg_off = {o: n for n, (s, o) in ours.items() if s == dgroup_seg}
    by_content = []
    inside = []
    absent = []
    for off, name, reason in unmatched:
        if "+" in name:
            continue
        text = texts.get(off, "")
        if not text:
            continue
        try:
            want = (text.encode("latin-1").decode("unicode_escape")
                    .encode("latin-1", "replace"))
        except (UnicodeDecodeError, UnicodeEncodeError):
            want = text.encode("latin-1", "replace")
        hits = [n for o, n in seg_off.items()
                if dump[o:o + len(want)] == want
                and dump[o + len(want):o + len(want) + 1] == b"\x00"]
        if hits:
            by_content.append((off, name, hits[0]))
        elif dump.find(want) >= 0:
            inside.append((off, name, text, dump.find(want)))
        else:
            absent.append((off, name, text))
    print("  matched by content, names differ : %d" % len(by_content))
    for off, name, oname in by_content[:8]:
        print("      %04x %-40s ours=%s" % (off, name[:40], oname))
    print("  text present but not at a symbol: %d" % len(inside))
    for off, name, text, at in inside[:6]:
        print("      %04x %-40s at %04x" % (off, name[:40], at))
    if absent_path:
        with io.open(absent_path, "w", encoding="utf-8", newline="\n") as fh:
            for off, name, text in absent:
                fh.write("%04x\t%s\t%s\n" % (off, name, text))
        print("  absent list written to %s" % absent_path)
    print("  text absent from our data       : %d" % len(absent))
    for off, name, text in absent[:8]:
        print("      %04x %-40s %r" % (off, name[:40], text[:30]))

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
