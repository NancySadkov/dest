"""List the overlay functions whose C body still issues fewer calls than the image.

This is the structural counterpart to `scripts/screen_calls.py`.  `screen_calls` prints the raw
per-function delta and stops at the largest rows, which buries the functions that are actually
unwritten under the ones that differ by one or two.  This script applies the two corrections that
make the delta interpretable and reports only the functions where code is genuinely absent:

1. **The +1 definition bias.**  `screen_calls` matches `IDENT(` over the whole body, and the body
   starts at the `/* seg:ofs */` marker, so the function's own `type name(args)` signature line is
   counted as a call.  Measured over all screened functions the distribution is

       delta  +1   817 functions        delta   0   34 functions
       delta <=-2   36 functions        delta >=+2   29 functions

   i.e. `+1` is parity.  This script subtracts the signature line so `0` is parity, matching the
   image's call count.

2. **Unrolled-image loops.**  Several image routines unroll a loop that the C body writes as a
   loop (`6ffe:009b` / `6ffe:01c5`, the nine/nine stub slots).  Those show a large negative delta
   with a correct body and are excluded by `ARTEFACTS`.

3. **Inlined helpers.**  A few bodies fold a tiny helper the image still calls (`2d63:04b7`'s three
   `call 0x599` sites, inlined as `x + y*320`).  Also excluded by `ARTEFACTS`.

Anything left is a body that is absent, stubbed, or truncated, with the size and the missing call
count as the work estimate.

Usage: python scripts/structural_deficits.py [min_deficit] [max_rows]
"""

import glob
import io
import os
import re
import struct
import sys

import capstone

ROOT = r"C:\Users\nangl\d\code\dest"
MIN = int(sys.argv[1]) if len(sys.argv) > 1 else 3
MAX = int(sys.argv[2]) if len(sys.argv) > 2 else 60
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# Bodies that are complete but whose loop/helper shape differs from the image's shape.  Each entry
# is (file, seg:ofs) with the reason.
ARTEFACTS = {
    ("ovc44_strong_dat.c", "6ffe:009b"): "image unrolls 9 allocator calls; body loops",
    ("ovc44_strong_dat.c", "6ffe:01c5"): "image unrolls 9 allocator calls; body loops",
    ("ovc01_driver.c", "2d63:04b7"): "image calls the row-base helper 3x; body inlines it",
}

EXE = io.open(os.path.join(ROOT, "game", "STRONG.EXE"), "rb").read()
IMG = struct.unpack("<H", EXE[8:10])[0] * 16
MD = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_16)

starts = {}
known = set()
for line in io.open(os.path.join(ROOT, "audit", "functions_real.tsv"), encoding="latin-1"):
    f = line.rstrip("\n").split("\t")
    if len(f) < 4 or ":" not in f[0]:
        continue
    seg, ofs = (int(x, 16) for x in f[0].split(":"))
    starts.setdefault(seg, set()).add(ofs)
    known.add(f[1])
for seg in starts:
    starts[seg] = sorted(starts[seg])

# Same continuation list as screen_calls.py: entries that share the preceding frame are not entry
# points, so the measured extent must not stop there.
CONTINUATIONS = [(0x5ded, 0x14a8), (0x5ded, 0x1433), (0x4d05, 0x277a), (0x4d05, 0x2b09)]
for seg, ofs in CONTINUATIONS:
    if seg in starts and ofs in starts[seg]:
        starts[seg].remove(ofs)

IDENTS = re.compile(r"\b([A-Za-z_][A-Za-z0-9_]*)\s*\(")
MARK = re.compile(r"^/\* ([0-9a-f]{4}):([0-9a-f]{4}) \*/$")
COMMENTS = re.compile(r"/\*.*?\*/", re.S)
LOCAL_WRAPPERS = {"stsh_store", "func_0x0007ffe0"}

rows = []
for path in sorted(glob.glob(os.path.join(ROOT, "src", "decompiled", "*.c"))):
    base = os.path.basename(path)
    L = io.open(path, encoding="latin-1").read().split("\n")
    marks = []
    for k in range(len(L)):
        m = MARK.match(L[k].strip())
        if m:
            marks.append((k, int(m.group(1), 16), int(m.group(2), 16)))
    groups = []
    for ln, seg, ofs in marks:
        if groups and groups[-1][1] == seg and groups[-1][2] == ofs:
            groups[-1] = (ln, seg, ofs)
        else:
            groups.append((ln, seg, ofs))
    for i, (ln, seg, ofs) in enumerate(groups):
        tag = "%04x:%04x" % (seg, ofs)
        if (base, tag) in ARTEFACTS:
            continue
        end_ln = groups[i + 1][0] - 1 if i + 1 < len(groups) else len(L) - 1
        body = COMMENTS.sub("", "\n".join(L[ln:end_ln + 1]))
        n = sum(1 for m in IDENTS.finditer(body)
                if m.group(1) in known or m.group(1) in LOCAL_WRAPPERS
                or m.group(1).startswith("ovr_") or m.group(1).startswith("litoa"))
        n -= 1                                   # the function's own signature line
        nxt = next((s for s in starts[seg] if s > ofs), None)
        if nxt is None:
            continue
        code = EXE[IMG + (seg - 0x1000) * 16 + ofs:IMG + (seg - 0x1000) * 16 + nxt]
        ic = sum(1 for ins in MD.disasm(code, 0) if ins.mnemonic in ("call", "lcall"))
        if ic - n >= MIN:
            rows.append((n - ic, base, tag, n, ic, nxt - ofs))

rows.sort()
print("%-18s %-10s %6s %5s %6s %s" % ("file", "address", "bytes", "C", "image", "delta"))
for d, f, a, n, ic, sz in rows[:MAX]:
    print("%-18s %-10s %6d %5d %6d %+d" % (f, a, sz, n, ic, d))
print()
print("%d functions with a real call deficit >= %d (game code; crtl.c/ovl.c are supplied)" % (len(rows), MIN))
if ARTEFACTS:
    print("\nexcluded as shape differences, not missing code:")
    for (f, a), why in sorted(ARTEFACTS.items()):
        print("  %-18s %-10s %s" % (f, a, why))
