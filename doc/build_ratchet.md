# Compile ratchet

`scripts/build_standalone.py` compiles `src/decompiled` with Turbo C++ 3.0, **one
module per TCC invocation**, inside the modded DOSBox-X.  Per-module logs and a
summary land in `tmp/buildsrc/*.log` and `tmp/build_report.tsv`.

```powershell
python scripts/build_standalone.py                # all modules
python scripts/build_standalone.py --only main    # one module
python scripts/build_standalone.py --keep-stage   # reuse tmp/buildsrc
```

It stages through `scripts/stage_build.py` (8.3 names, `st.h` aggregate), writes
`BUILD.BAT` with one `TCC -ml -1 -G -O -c` line per module, runs
`scripts/fbov/run_dosbox.py`, then parses `*** N errors in Compile ***` from each
log.  Exit status is 0 only when every module compiled.

`-ml` is required: the original is a large-model build, so a near-pointer
`char *` here is a bug, not a choice.

## Baseline after the 2026-11-21 export

```
modules compiled clean : 9 / 57
total errors           : 675
```

Clean modules: `MAIN`, `MOUSE`, `VIDEO`, `OVRSTUB`, `O05`, `O31`, `O36`, `O39`,
`O50`.

`main.c` is green (0 errors, 2 warnings), which is the root AGENTS.md step 3
needs: the walk outward can start there and every module added to the clean set
is a ratchet tooth.

Error classes, whole tree:

| count | class |
|---:|---|
| 237 | Nonportable pointer conversion |
| 90 | Undefined symbol |
| 90 | Too few parameters in call to |
| 61 | Incompatible type conversion |
| 50 | Invalid indirection |
| 43 | Declaration is not allowed here |
| 30 | Pointer to structure required on left side of `->` |
| 26 | Type mismatch in parameter |

Two caveats on these numbers.  Sixteen modules stop at 25 errors
(`Too many error or warning messages`), so the true count is higher and per-class
counts move when an earlier error is fixed.  Re-run the report after every model
change rather than comparing a single class in isolation.

## Defects already fixed by the first compile

1. `char_sheet_t` had **two fields named `level`** (+0x52 and +0x86), which is a
   hard error in C.  +0x86 is only read by title code and compared with 0 and 8,
   so it is now `titleIndex` (marked GUESS).  Reported by `types.h 199`.
2. 145 functions with **no named parameter were flagged variadic**, which Ghidra
   prints as `f(void...)` - not valid C.  `scripts/ghidra/FixVarArgs.java` clears
   the flag (no call site passes arguments to any of them).  Reported by
   `func.h 102, 244...`.
3. Ghidra's 3-byte working types `int3`/`uint3`/`undefined3` were undeclared.
   They are now typedef'd in `st_compat.h`, which exists for exactly this.

## Diagnosed, not yet fixed

**Byte parameters are stored as one byte.**  A `char` parameter occupies a full
word on the stack, because C promotes it.  When the callee reads the whole word,
Ghidra sees a 2-byte access to a 1-byte variable, creates an overlapping high
variable, prints it with a leading underscore, and never declares it.  That is
the whole `Undefined symbol '_count'` / `'_shade1'` / `'_uStack0004'` class
(70 distinct names, 90 references).

Evidence, `blit_usesRandBelow` at `317e:0879`:

```
317e:087d  8B 76 0A   MOV SI,word ptr [BP + 0xa]   ; 'char count', whole word
```

while the model stores it as `Stack[0x8]:1`.  The fix is to give one-byte
parameters **two-byte stack storage** (keeping the `char` type), which should
also remove the `Too few parameters`/`Type mismatch` residuals that come from the
same overlapping-variable confusion.
