"""Remove the x87 register remnants the model cannot supply.

Ghidra models an x87 register value as an ordinary local:

    longdouble in_ST0;                       /* never assigned */
    *__return_storage_ptr__ = (long)in_ST0;   /* reads it */
    ... = (double)in_ST0;

`in_ST0` is never written, so every read is undefined behaviour, and the compiler
turns the conversions into 80-bit runtime helpers (FIDRQQ, F_FTOL@) that are called
with *near* relocations - which cannot be resolved from another segment and show up
as TLINK "Fixup overflow" at O09_SEG:181E.

Replacing the reads with a constant removes the helper calls.  This is a GUESS in the
sense that the original value is genuinely lost; but the current expression has no
defined value either, so nothing correct is being discarded.

usage: python scripts/fix_x87_remnants.py [--apply]
"""
import glob
import io
import re
import sys

apply = "--apply" in sys.argv

total = 0
files = 0
for path in sorted(glob.glob("src/decompiled/*.c")):
    t = io.open(path, encoding="latin-1").read()
    new = t
    new = new.replace("(long)in_ST0", "0L")
    new = new.replace("(double)in_ST0", "0.0")
    new = new.replace("(float)in_ST0", "0.0f")
    # A store of a double through a computed pointer makes Turbo C pull in the
    # 80-bit float I/O helpers (FIDRQQ/FIWRQQ), which are called with *near*
    # relocations and therefore overflow ("Fixup overflow at O33_SEG:12F0").  These
    # stores only ever wrote the x87 remnant, so with the value gone the store is
    # meaningless and is dropped.  No other double stores exist in the tree.
    new = re.sub(r"\*\s*\(double \*\)[^;=]*=\s*0\.0f?\s*;", "(void)0;", new)
    if new != t:
        total += sum(t.count(p) for p in ("(long)in_ST0", "(double)in_ST0", "(float)in_ST0"))
        files += 1
        if apply:
            io.open(path, "w", encoding="latin-1", newline="\n").write(new)

print("x87 remnants neutralised:", total, "in", files, "files")
print("mode:", "APPLY" if apply else "dry run")
