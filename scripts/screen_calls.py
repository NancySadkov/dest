"""Screen overlay modules for per-function call-count mismatches (deduped markers).

Two fixes over the first passes:

  * several functions carry the `/* seg:ofs */` marker twice (once before a descriptive comment and
    once before the signature), which previously created a second, empty "function"; markers are
    now grouped by address and the body runs from the last marker of a group to the next group;
  * only known function names are counted (the audit table's names plus `ovr_` thunks), so
    `far(`/`near(`/`sizeof(` no longer inflate the C side.

A large mismatch means the exported body does not belong to that address range (the Ghidra
structuring defect that hit ovc18_spawnClassAgent and ovc18_textTypeLen), or that the body is a stub.

Usage: python scripts/screen_calls.py [min_mismatch] [max_rows]
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
MAX = int(sys.argv[2]) if len(sys.argv) > 2 else 40
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

b = io.open(os.path.join(ROOT, "game", "STRONG.EXE"), "rb").read()
img = struct.unpack("<H", b[8:10])[0] * 16
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_16)

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

# Continuation-aware boundaries.  Ghidra splits some routines across several entries: a block that
# shares the preceding function's stack frame is not an entry point.  A general heuristic is not safe -
# "has a prologue" flags 591 entries and "byte before is a terminator" flags 568, almost all of them CRT
# or overlay code that legitimately has no frame - so the merged entries are listed explicitly with
# their evidence in the measurement log.  Each is (segment, offset).
CONTINUATIONS = [
    (0x5ded, 0x14a8),   # no prologue, reads 5ded:10ea's frame, reached by `jmp 0x14a8`
    (0x5ded, 0x1433),   # no caller and no jump reaches it: mid-flow of 10ea's state-3/5 arm
]
for seg, ofs in CONTINUATIONS:
    if seg in starts and ofs in starts[seg]:
        starts[seg].remove(ofs)

IDENTS = re.compile(r"\b([A-Za-z_][A-Za-z0-9_]*)\s*\(")
MARK = re.compile(r"^/\* ([0-9a-f]{4}):([0-9a-f]{4}) \*/$")


COMMENTS = re.compile(r"/\*.*?\*/", re.S)

# Local C wrappers that stand in for an image callee, so they must count as calls too.  stsh_store is
# the st_stubs.c wrapper around ovr_stshStoreFile: it performs the image's two-word call and returns
# DX:AX.  Counting it closes the gap for every asset loader that stores a sprite.
LOCAL_WRAPPERS = {"stsh_store", "func_0x0007ffe0"}


def count_calls(body):
    # Prose in a comment mentions call shapes ("digSoundPlaying()", 'strcat(dst, "") ...'), and
    # matching those reported already-correct bodies as mismatches - audio_isPlaying and
    # file_open_rdonly both appeared on the list with their bodies right.  Strip comments first.
    body = COMMENTS.sub("", body)
    return sum(1 for m in IDENTS.finditer(body)
               if m.group(1) in known or m.group(1) in LOCAL_WRAPPERS
               or m.group(1).startswith("ovr_") or m.group(1).startswith("litoa"))


rows = []
for path in sorted(glob.glob(os.path.join(ROOT, "src", "decompiled", "*.c"))):
    L = io.open(path, encoding="latin-1").read().split("\n")
    marks = []
    for k in range(len(L)):
        m = MARK.match(L[k].strip())
        if m:
            marks.append((k, int(m.group(1), 16), int(m.group(2), 16)))
    # group consecutive markers that repeat an address
    groups = []
    for ln, seg, ofs in marks:
        if groups and groups[-1][1] == seg and groups[-1][2] == ofs:
            groups[-1] = (ln, seg, ofs)          # keep the LAST marker of the duplicate run
        else:
            groups.append((ln, seg, ofs))

    for i, (ln, seg, ofs) in enumerate(groups):
        end_ln = groups[i + 1][0] - 1 if i + 1 < len(groups) else len(L) - 1
        body = "\n".join(L[ln:end_ln + 1])
        ncalls = count_calls(body)
        if seg not in starts:
            continue
        nxt = next((s for s in starts[seg] if s > ofs), None)
        if nxt is None:
            continue
        base = img + (seg - 0x1000) * 16
        code = b[base + ofs:base + nxt]
        icalls = sum(1 for ins in md.disasm(code, 0) if ins.mnemonic in ("call", "lcall"))
        rows.append((abs(ncalls - icalls), os.path.basename(path), "%04x:%04x" % (seg, ofs),
                     ncalls, icalls, nxt - ofs))

rows.sort(reverse=True)
print("%-18s %-10s %6s %5s %6s %s" % ("file", "address", "bytes", "C", "image", "delta"))
for d, f, a, nc, ic, sz in rows[:MAX]:
    if d < MIN:
        break
    print("%-18s %-10s %6d %5d %6d %+d" % (f, a, sz, nc, ic, nc - ic))
print()
print("%d functions screened, %d with |delta| >= %d" % (len(rows), sum(1 for r in rows if r[0] >= MIN), MIN))
