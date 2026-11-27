"""Resolve an overlay far call (`lcall sel,ofs`) to its overlay entry, authoritatively.

`audit/overlay_segments.csv` maps a runtime selector to the overlay segment that supplies it, and the
segment plus offset then names the entry.  That mapping is the authority: a selector resolves to ONE
overlay segment, so one (selector, offset) pair has one target.

This matters because the cross-reference shortcut (looking at how other derived modules happen to name
the same pair) can disagree with itself.  For example, selector 0x170 offset 0x5c is used 43 times in
`3381:08dc`, and scanning other modules' bodies yields three different names for it
(`constr_usesGMapFlags`, `constr_usesGMapFlags2`, `init_getMapFlags`) while the map says, uniquely,
`ovr_randBelow`.  Use this tool first and treat a cross-reference disagreement as a signal that those
other names are the ones to fix, not this one.

Usage:
    python scripts/resolve_selector.py 170 5c 138 2a 138 61
"""

import io
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ADDR = re.compile(r"^([0-9A-Fa-f]{4}):([0-9A-Fa-f]{4})$")


def load_segments():
    """selector -> [overlay segment, ...]"""
    out = {}
    path = os.path.join(ROOT, "audit", "overlay_segments.csv")
    for line in io.open(path, encoding="latin-1"):
        f = line.rstrip("\n").split("\t")
        if len(f) > 1 and f[0] != "runtime_segment":
            out[f[0].upper()] = [s.strip().upper() for s in f[1].split(",") if s.strip()]
    return out


def load_names():
    """(segment, offset) -> name, from the function table then the symbol table."""
    names = {}
    sym = os.path.join(ROOT, "audit", "symbols.tsv")
    for line in io.open(sym, encoding="latin-1"):
        f = line.rstrip("\n").split("\t")
        if len(f) > 3:
            m = ADDR.match(f[0])
            if m:
                names[(m.group(1).upper(), m.group(2).upper())] = f[2]
    fn = os.path.join(ROOT, "audit", "functions_real.tsv")
    for line in io.open(fn, encoding="latin-1"):
        f = line.rstrip("\n").split("\t")
        m = ADDR.match(f[0])
        if m:
            names[(m.group(1).upper(), m.group(2).upper())] = f[1]
    return names


def main():
    args = sys.argv[1:]
    if len(args) < 2 or len(args) % 2:
        print(__doc__.strip().splitlines()[-1])
        return 1
    segs = load_segments()
    names = load_names()
    for i in range(0, len(args), 2):
        sel, ofs = args[i].upper().zfill(4), args[i + 1].upper().zfill(4)
        cands = segs.get(sel, [])
        if sel == "0000" and not cands:
            # selector 0 is the resident (non-overlay) text segment
            cands = ["1000"]
        hits = []
        for s in cands:
            n = names.get((s, ofs))
            if n:
                hits.append((s, n))
        print("lcall %s,%s" % (sel, ofs))
        if not cands:
            print("   selector absent from audit/overlay_segments.csv - unresolvable")
        elif not hits:
            print("   segments %s: no symbol at offset %s" % (",".join(cands), ofs))
        elif len(hits) == 1:
            print("   -> %s   (segment %s)" % (hits[0][1], hits[0][0]))
        else:
            print("   ambiguous: " + ", ".join("%s (segment %s)" % (n, s) for s, n in hits))
    return 0


if __name__ == "__main__":
    sys.exit(main())
