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

## Sizing the `"puppetmaker" + 3` fold class

`tmp/size_segclass.py` and `tmp/size_puppet.py` classify every occurrence of the
constant `0x2410` that the decompiler renders as `(char *)"puppetmaker" + 3`
(the string starts at DGROUP `0x240d`, so `+3` is `0x2410`).

```
total folds                                 324
  inside CONCAT22(<unassigned segment>, ...)  29   9%
  inside CONCAT22(<some variable>, ...)      295  91%
```

So the earlier explanation - an untracked segment local - accounts for only 29 of
them, in 19 functions across 11 modules (`ovc13_panel` 10, `ovc16_saveui` 4,
`ovc18_leaderview` 3, ...).  The dominant form is

```c
CONCAT22(GSeed, (char *)"puppetmaker" + 3)
CONCAT22(uVar7, (char *)"puppetmaker" + 3)
```

i.e. a **variable segment half paired with the constant `0x2410` as the offset
half**, 146 of them as call arguments and 178 in assignments and nested casts.

That makes the class a register-pair problem, not a stack-local problem: the
segment and offset halves of the same far pointer are being taken from the wrong
sources.  Sizing it precisely needs the operand provenance of the `CONCAT22`
halves at a sample of those sites, which is the next investigation - not a blind
retype.

## Ratchet update: 2026-11-21 second pass

```
modules compiled clean : 10 / 57   (was 9)
total errors           : 659       (was 675)
```

`O29` is the module that turned green.

### Byte parameters: smaller than claimed

`scripts/ghidra/FixByteParams.java` widens a one-byte parameter only when the
body performs a word access on its own slot, and records the instruction as
evidence.  Only **six** parameters in the whole program qualify:

| function | parameter | witness |
|---|---|---|
| `toupper` | `c` | `1000:0e33 MOV DX,word ptr [BP + 0x6]` |
| `biosVideoCall` | `operation` | `2d63:0021 MOV AX,word ptr [BP + 0x6]` |
| `attact_textArena` | `mode` | `3f0b:1a37 MOV DI,word ptr [BP + 0xa]` |
| `attact_usesAlignUp44` | `y` | `3f0b:23b0 MOV DI,word ptr [BP + 0xa]` |
| `fmReadIntoHimem` | `useEms` | `474a:0c0d CMP DX,word ptr [BP + 0x10]` |
| `ovc41_compute4` | `pad` | `6a8f:01c2 PUSH word ptr [BP + 0xc]` |

They were applied with `SetVarType` to `/int`; the stack slot of a one-byte
parameter is already two bytes, so nothing moved.  Measured effect: 675 -> 671.
So byte width is **not** the explanation for the `_xxx` class - the earlier note
in this document was wrong on that point.

### What the `_xxx` class really is

Not a width problem and not an untracked local: Ghidra **declares one name and
uses another**.  In `ovc02_draw.c`, `draw_menuRowBar`:

```c
  undefined1 uStack0004;          /* declaration */
  ...
  if ((_uStack0004 < 5) && ...    /* use, one underscore later */
```

For parameters the pair is `count` / `_count`, `gfx_id` / `_gfx_id`,
`shade1` / `_shade1`.  The underscore is Ghidra's disambiguator for a name that
shadows something in scope, applied to the use but not to the declaration.

`ExportRecovered.fixShadowedParamUses()` now rewrites `_x` to `x` **for
parameter names only**, because Borland's runtime globals are also spelled with
a leading underscore (`_drive`, `_c`) and must not be touched.  Parameters are
exactly the `_count`/`_gfx_id`/`_shade1` pattern.

Measured effect: `Undefined symbol` 85 -> 62, total 671 -> 659, and `O29`
(`_gfx_id` in `animAdvance`) compiles clean.

Locals printed this way (`_uStack0004`) are still undeclared; extending the rule
to locally declared names needs the same care about Borland's `_`-prefixed
globals, and is the next refinement.

### Third pass: shadow rewrite extended to locals

`ExportRecovered.fixShadowedParamUses()` now covers names the function declares
**itself**, not just parameters, with the same guard: a name is only rewritten
when the *unprefixed* spelling is declared in this body and the prefixed spelling
is not a program symbol (so Borland's `_drive`, `_c`, `_argv` are untouched).

```
modules compiled clean : 10 / 57   (unchanged)
total errors           : 609       (was 659)
_uStack0004 occurrences: 0
Undefined symbol class : no longer in the top eight
```

Measured effect: 659 -> 609, a 50-error drop, with the clean count unchanged --
the modules that had these names have other errors left.

### O08 is not a quick win: the caller's parameter list is under-modelled

`miceBlitRect` is declared `void miceBlitRect(brect_t *br, ...)` and calls
`miceSaveArea()` with no arguments, while `miceSaveArea` reads `[BP+6]`, `[BP+8]`
and `LES [BP+0xa]`, so it really does take three arguments.

The caller's body reads **six words** from `BP+6` (`in_stack_00000004[0..4]` plus
`br`), and Ghidra represents the first two as
`CONCAT22((brect_t *)br, in_stack_00000004)`.  Only one parameter is modelled, so
the decompiler resolved the rest as an `in_stack_` array and dropped the nested
call's arguments.  Widening `br` to a far pointer was tried and does not help (it
is used as the *segment* half there); it was reverted.  Recovering the missing
parameters is per-function step-3 work, not a sweep.

### Fourth pass: parameter slot off-by-two, and O08 recovered

**A bug in my own tooling.** `SetProtoSeq` and `FixFarParamOffsets` treated the
BP-relative offset as a Ghidra stack address.  The mapping is

```
Stack[n] = BP + n + 2      so a far function's first parameter is Stack[4] (BP+6)
```

Both scripts started at 6, so every prototype they rebuilt sat **two bytes too
high**.  `blitRaw` is the witness: it was `x1 @ Stack[0x6]` while its body reads
`[BP+6]`.  Both scripts now start at `4` (far) / `2` (near), the 308 + 28 + 1
restored prototypes were re-applied, and `FixFarParamOffsets` re-widened 30 of them.

`fmVsprintf` now sits at `Stack[0x4]` / `Stack[0x8]`, matching its
`PUSH [BP+6]` / `PUSH [BP+8]` far pair.  `blitRaw` starts at `Stack[0x4]`.

**`miceBlitRect` recovered as the first step-3 function.**  Its body reads exactly
two words from `BP+6` and `BP+8`, and Ghidra paired them as
`CONCAT22((brect_t *)br, in_stack_00000004)` - the two halves of **one far
pointer** whose offset half was unclaimed.  Placing `brect_t *32 br` at
`Stack[0x4]` (instead of `Stack[0x6]`) removes `in_stack_00000004` entirely and
frees the nested call's arguments:

```c
/* before */  miceSaveArea();
              if ((*(int *)CONCAT22((brect_t *)br,in_stack_00000004) <= ...

/* after  */  miceSaveArea(dst_x,dst_y,br,in_stack_00000006);
              miceBlitAtSeg(br->seg,src,dst_x,dst_y);
```

```
$ python scripts/build_standalone.py --only o08
compiled 1/1 modules
```

Ratchet after this pass:

```
modules compiled clean : 15 / 57   (was 10)
total errors           : 617
clean: main mouse o05 o07 o08 o10 o24 o25 o29 o31 o36 o39 o50 ovrstub video
```

`O07`, `O10`, `O24`, `O25` and `O08` all turned green in this pass; the
`Too few parameters` class (91 before) no longer appears in the top eight.  A
residual `in_stack_00000006` remains in `miceBlitRect`, i.e. one more word
parameter at `BP+0xa` still to be recovered.

### Fifth pass: globals printed with a leading underscore

Ghidra prefixes `_` to some **globals** as well as locals: `st_globals.h`
declares `cred03Cut3Ofs`, while `save_loadArchiveGame` uses `_cred03Cut3Ofs`.
`fixShadowedParamUses()` now also rewrites `_X` to `X` when

* `X` is a declared **data** symbol (not a function), and
* nothing in that function declares `X` (so the use cannot be redirected to a
  local), and
* `_X` is not a symbol itself.

That is deliberately narrower than the local rule: rewriting a genuinely
shadowed global reference would silently change which object is touched.

```
total errors : 615 -> 611
Undefined symbol class : gone from the top eight
modules clean : 16 / 57 (unchanged)
```

### The cheap-module route is now exhausted

The remaining low-error modules fail on **expression-level typing**, not parameter
lists, so they cannot be fixed by rebuilding a prototype:

| module | last error | what it is |
|---|---|---|
| `o37` | `abStack_4 = (byte [2])(*(uint16_t *)(...));` | Ghidra assigns to an array-typed local; only 3 such sites exist in the tree |
| `o26` | `uStack_a->base.x` | local declared `undefined4`, used as a pointer; a decompiler high-variable, not a model variable |
| `o34` | `cursorX = (byte *)((GfxRndSeed - Seed_2000_d110) * 2 + 7);` | integer expression assigned to a `byte *` local |
| `o19` | `*(undefined2 *)(iVar2 * 4) = pvVar3;` | pointer stored through an `undefined2` slot |

None of these is a `[BP+d]` parameter-list defect.  Moving the clean count from
here needs either per-function decompiler work (step 3 proper) or a deliberate
normalisation pass over the decompiler's expression types - not another sweep.
