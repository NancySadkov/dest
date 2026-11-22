"""Provide documented stubs for the symbols the recovery cannot resolve.

These 22 symbols are the ones left after the evidence ran out (see
scripts/model/func_addr_names.tsv and the commit log for the forensics):

  * 11 func_0x<linear> call targets - `push cs; call near` far calls whose target
    addresses are data or 1..3-byte fragments in the original image, so they cannot
    be decompiled;
  * attact_textAbnormalProgramTermination - declared, never recovered (it is the
    "abnormal program termination" reporter);
  * EXT_FUN_8000_f2fa - the target of the ovr_EXT_FUN_8000_f2fa thunk, outside
    every segment we have;
  * halt_baddata, smm_restore_state, DOS_GetInterruptHandler,
    DOS_SetInterruptHandler - CRT/game helpers with no recovered body;
  * swi - `(code *)swi(0x21)` is called through, so it must return a non-null code
    pointer; it points at a function that returns 0;
  * _emu and _fperror - Borland floating-point runtime data (the emulator flag and
    the FPE handler pointer), referenced by compiler-generated FP support.

Every stub is marked GUESS in the file and listed in scripts/model/unresolved.tsv,
so they are trivial to revisit.  They exist so the image links and can be run.

usage: python scripts/gen_stubs.py [--apply]
"""
import io
import os
import sys

apply = "--apply" in sys.argv
OUT = "src/decompiled/st_stubs.c"
TSV = "scripts/model/unresolved.tsv"

FUNC_0X = [
    "func_0x00010264", "func_0x00010268", "func_0x000318f5", "func_0x0004f29c",
    "func_0x0004f32d", "func_0x0004f68f", "func_0x0004f735", "func_0x0004f930",
    "func_0x0004fcda", "func_0x0007164e", "func_0x0007ffe0",
]
OTHER = [
    "EXT_FUN_8000_f2fa", "halt_baddata", "smm_restore_state",
    "DOS_GetInterruptHandler", "DOS_SetInterruptHandler",
    "ovr_season_usesGPromotable_e11a",
]
DATA = ["_emu", "_fperror"]

lines = [
    "/* GUESS: stubs for the symbols the recovery could not resolve.",
    " *",
    " * Each one is listed in scripts/model/unresolved.tsv with the reason.  They",
    " * return 0 (or are zero-initialised), so the image links and can be run; they",
    " * are placeholders, not recovered code. */",
    '#include "recovered.h"',
    "",
]
for f in FUNC_0X:
    lines.append("/* GUESS: target address is data or a fragment in the original */")
    lines.append("int %s()" % f)
    lines.append("{")
    lines.append("  return 0;")
    lines.append("}")
    lines.append("")
for f in OTHER:
    lines.append("/* GUESS: body not recovered */")
    lines.append("int %s()" % f)
    lines.append("{")
    lines.append("  return 0;")
    lines.append("}")
    lines.append("")
lines += [
    "/* GUESS: swi() is called through, so return a real code pointer, not null */",
    "static unsigned short st_swi_target(void)",
    "{",
    "  return 0;",
    "}",
    "",
    "code *swi(int vector)",
    "{",
    "  (void)vector;",
    "  return (code *)st_swi_target;",
    "}",
    "",
]
for d in DATA:
    lines.append("/* GUESS: Borland floating-point runtime data */")
    lines.append("int %s = 0;" % d)
    lines.append("")

text = "\n".join(lines)
print("stubs:", len(FUNC_0X) + len(OTHER) + 1 + len(DATA))
if apply:
    io.open(OUT, "w", encoding="utf-8", newline="\n").write(text)
    rows = ["# Symbols no longer recoverable, kept as documented stubs.",
            "# name<TAB>kind<TAB>reason"]
    for f in FUNC_0X:
        rows.append("%s\tfunction\tfunc_0x target is data/fragment in the image" % f)
    for f in OTHER:
        rows.append("%s\tfunction\tbody not recovered" % f)
    rows.append("swi\tfunction\treturns a stub code pointer")
    for d in DATA:
        rows.append("%s\tdata\tBorland FP runtime" % d)
    rows.append("F_FTOL@\tfunction\tasm stub in ovr_thunks.asm (identifier has '@')")
    io.open(TSV, "w", encoding="utf-8", newline="\n").write("\n".join(rows) + "\n")
    print("wrote", OUT, "and", TSV)
else:
    print("mode: dry run")
