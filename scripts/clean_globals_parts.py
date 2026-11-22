"""Delete stale split parts of the globals TU before ExportData rewrites it.

split_globals.py merges existing st_globalsN.c back before splitting, which is
what makes it idempotent -- but only when the main file *is* a split part.  After
ExportData has regenerated a complete st_globals.c, merging a stale part would
duplicate every definition.  So the parts are removed first.
"""
import glob
import os
import sys

out = sys.argv[1] if len(sys.argv) > 1 else "src/decompiled"
removed = 0
for p in glob.glob(os.path.join(out, "st_globals[0-9]*.c")):
    name = os.path.basename(p)
    if name == "st_globals.c":
        continue
    os.remove(p)
    removed += 1
    print("removed stale part", name)
print("stale globals parts removed:", removed)
