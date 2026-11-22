"""Let OVERLAY.LIB own the VROOMM manager state.

OVERLAY.LIB exports

    __OvrFileBase  __OVRHOOK__  __OVRFILENAME  __OvrMinHeapSize
    __OvrTrapCount __OvrRetrySize __OvrHeapPtr  __OvrCodeList ...

and our recovered globals define the *same* names (they came from the original's
overlay-manager data segment 195d).  Because our definitions are in an object file
that is always linked, the library member that carries the manager is never pulled
in: the overlay stubs have no manager behind them and the program dies during
startup with exit code 3, before main.

Removing our definitions lets the library provide both the data and the manager.

usage: python scripts/fix_overlay_manager.py [--apply]
"""
import glob
import io
import re
import sys

apply = "--apply" in sys.argv

# The original overlay manager's own state, recovered from segment 195d.
NAMES = {
    "__SEGTABLE__", "__SEGTABEND__", "__OvrFileBase", "__OvrLoadList",
    "__OvrHeapPtr", "__OvrHeapOrg", "__OvrHeapEnd", "__OvrRetrySize",
    "__OvrProbation", "__OvrTrapCount", "__OvrLoadCount", "__OvrCodeList",
    "__OvrDosHandle", "__OvrMinHeapSize", "__OvrExepathBuf", "__OvrMemorySwap",
    "__OVRVDISK", "__OVRHOOK__", "__OVRFILENAME", "__OVRBACKLINK__",
    "__OVRTRAP__", "__OVRDATA", "_OVR_STUB_", "__FakeVdisk",
    "__CALLEXTEXIT", "__CALLEXTEMSSWAP", "__CALLEMSEXIT",
    "__ExtStartAddress", "__ExtRec", "__ExtEndAddress", "__ExtChecked",
    "__EmsVersion", "__EmsRec", "__EmsPages", "__EmsPageFrame", "__EmsHandle",
    "__EmsFirstPage", "__EmsChecked", "__XmsHandle", "__XmsControl", "__XmsBase",
    "__XMSGDT", "__OvrSize", "__EXENAME__", "__EXEDATE__", "OvrFlags",
    "Int19Seg", "_BootHandlerCode", "vdiskBaseOfs", "vdiskBaseHi", "vdiskEndOfs",
    "vdiskEndHi", "data_OVR01_0000", "__OvrInit", "__Ovri", "segh", "segh2",
}

DECL = re.compile(r"^[A-Za-z_][\w ]*?[\s\*]([A-Za-z_]\w*)\s*(\[[^\]]*\])?\s*(=|;)")
EXTERN = re.compile(r"^extern\s+[A-Za-z_][\w ]*?[\s\*]([A-Za-z_]\w*)\s*(\[[^\]]*\])?\s*;")

removed_def = removed_ext = 0
for path in sorted(glob.glob("src/decompiled/st_globals*.c")):
    lines = io.open(path, encoding="utf-8", errors="ignore").read().split("\n")
    keep = []
    n = 0
    for l in lines:
        m = DECL.match(l)
        if m and m.group(1) in NAMES:
            keep.append("/* %s: owned by OVERLAY.LIB (VROOMM manager). */" % m.group(1))
            n += 1
            continue
        keep.append(l)
    if n:
        removed_def += n
        if apply:
            io.open(path, "w", encoding="utf-8", newline="\n").write("\n".join(keep))

hdr = "src/decompiled/st_globals.h"
lines = io.open(hdr, encoding="utf-8", errors="ignore").read().split("\n")
keep = []
for l in lines:
    m = EXTERN.match(l)
    if m and m.group(1) in NAMES:
        removed_ext += 1
        continue
    keep.append(l)
if apply:
    io.open(hdr, "w", encoding="utf-8", newline="\n").write("\n".join(keep))

print("definitions withheld:", removed_def, " externs removed:", removed_ext)
print("mode:", "APPLY" if apply else "dry run")
