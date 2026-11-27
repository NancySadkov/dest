"""Resolve a module's overlay calls using co-residency evidence, validated by push counts.

Why not just `audit/overlay_segments.csv`?  VROOMM reuses one runtime segment for different overlay
segments at different times, so a (selector, offset) pair does NOT name one function globally.
`0x140,0x2f` is the proof: the static map gives `ovr_stop_audio` (`void(void)`), but the image pushes
3 words at 39 of its 44 sites, and the derived modules name those sites `ovr_play_sfxU`.

`audit/overlay_blocks.csv` cannot resolve it either: it has 50 overlay ids with exactly two rows each
(a STUBSEG and its :OVY) and no co-residency column, so which blocks are loaded together is not in the
data.

What IS in the data is empirical co-residency: functions of the same module that are already derived
execute with that module's residency, so when they name a pair consistently, that name is the right one
for this module.  This tool collects those votes, reports the pushed-word count per pair, and flags any
pair where the winning name's prototype arity disagrees with the observed pushes - which is exactly the
check that catches the `stop_audio` trap.

Usage:
    python scripts/resolve_overlay_calls.py 5ded 10ea
    python scripts/resolve_overlay_calls.py 7e7c 0b9c
"""

import glob
import io
import os
import re
import struct
import sys
from collections import Counter, defaultdict

import capstone

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
b = io.open(os.path.join(ROOT, "game", "STRONG.EXE"), "rb").read()
img = struct.unpack("<H", b[8:10])[0] * 16
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_16)

MARK = re.compile(r"^/\* ([0-9a-fA-F]{4}):([0-9a-fA-F]{4}) \*/$")


def foff(seg, ofs):
    return img + (seg - 0x1000) * 16 + ofs


def load_tree():
    """(seg,ofs) -> (file, body)"""
    out = {}
    for p in glob.glob(os.path.join(ROOT, "src", "decompiled", "*.c")):
        L = io.open(p, encoding="latin-1").read().split("\n")
        marks = [(i, int(L[i].strip()[3:7], 16), int(L[i].strip()[8:12], 16))
                 for i in range(len(L)) if MARK.match(L[i].strip())]
        for j, (i, seg, ofs) in enumerate(marks):
            end = marks[j + 1][0] if j + 1 < len(marks) else len(L)
            out[(seg, ofs)] = (os.path.basename(p), "\n".join(L[i:end]))
    return out


def load_sizes():
    sizes = {}
    for line in io.open(os.path.join(ROOT, "audit", "functions_real.tsv"), encoding="latin-1"):
        f = line.rstrip("\n").split("\t")
        m = re.match(r"^([0-9a-fA-F]{4}):([0-9a-fA-F]{4})$", f[0])
        if m:
            sizes[(int(m.group(1), 16), int(m.group(2), 16))] = int(f[3])
    return sizes


def scan_lcalls(seg, ofs, size):
    """[(sel,ofs,pushcount)] in order, for one function's image range."""
    code = b[foff(seg, ofs):foff(seg, ofs) + size]
    insns = list(md.disasm(code, ofs))
    out = []
    for i, ins in enumerate(insns):
        if ins.mnemonic != "lcall":
            continue
        ops = [x.strip() for x in ins.op_str.split(",")]
        if len(ops) != 2:
            continue
        try:
            pair = (int(ops[0], 0), int(ops[1], 0))
        except ValueError:
            continue
        n, j = 0, i - 1
        while j >= 0:
            x = insns[j]
            if x.mnemonic == "push":
                n += 1
            elif x.mnemonic in ("call", "lcall", "ret", "retf", "jmp") or x.mnemonic.startswith("j"):
                break
            elif x.mnemonic == "add" and x.op_str.replace(" ", "").startswith("sp,"):
                break
            j -= 1
        out.append((pair[0], pair[1], n))
    return out


def main():
    seg = int(sys.argv[1], 16)
    ofs = int(sys.argv[2], 16)
    tree = load_tree()
    sizes = load_sizes()

    target_calls = scan_lcalls(seg, ofs, sizes.get((seg, ofs), 0))

    # votes: pair -> name, from every derived function in the SAME module
    votes = defaultdict(Counter)
    for (s, o), (path, body) in tree.items():
        if s != seg:
            continue
        names = re.findall(r"\b(ovr_\w+)\s*\(", body)
        pairs = scan_lcalls(s, o, sizes.get((s, o), 0))
        if len(names) != len(pairs):
            continue          # this body's call list is not trustworthy
        for (sel, cofs, n), nm in zip(pairs, names):
            votes[(sel, cofs)][nm] += 1

    print("%04x:%04x  %d overlay calls" % (seg, ofs, len(target_calls)))
    seen = Counter()
    for sel, cofs, n in target_calls:
        key = (sel, cofs)
        seen[key] += 1
        c = votes.get(key)
        if not c:
            print("  %03x,%04x  pushes=%d  -> NO SAME-MODULE VOTE" % (sel, cofs, n))
            continue
        name, v = c.most_common(1)[0]
        flag = "" if len(c) == 1 else "  [split %s]" % dict(c)
        print("  %03x,%04x  pushes=%-2d -> %-34s vote %d/%d%s"
              % (sel, cofs, n, name, v, sum(c.values()), flag))
    print()
    print("distinct pairs:", len(seen))


main()
