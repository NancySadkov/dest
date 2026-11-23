# AGENTS.md §5 grep classes: what each one is and how to remove it

Generated from `python scripts/grep_checks.py` on the current tree.
`TOTAL 58,424`.  The table is the progress ratchet; this file records what each
row actually is, which rows have a mechanical fix, and which need real recovery.

## Current table

| class | count | worst files |
|---|---|---|
| `char [N] = ""` | 1,408 | `st_globals5.c` 1,297, `st_globals4.c` 110, `crtl.c` 1 |
| `[iusbc]Var` | 35,603 | `ovc22_classes.c` 3,216, `ovc23_bldrec.c` 2,558, `ovc45_unitinfo.c` 2,216 |
| `p[iusbc]Var` | 8,797 | `ovc49_agents.c` 955, `ovc22_classes.c` 738, `ovc02_draw.c` 717 |
| `[iusc]Stack_` | 5,433 | `ovc22_classes.c` 850, `ovc21_manage.c` 416 |
| `in_stack_` | 1,539 | `ovc49_agents.c` 278, `ovc15_sprite.c` 147 |
| `bStack_` | 1,216 | `ovc09_init.c` 149, `ovc34_unit.c` 114 |
| `unaff_DI` | 1,159 | `ovc48_assets2.c` 284, `ovc44_strong_dat.c` 238 |
| `in_REG` | 937 | `crtl.c` 154, `ovl.c` 106, `ovc27_combat.c` 72 |
| `unaff_SI` | 828 | `ovc46_assets.c` 191, `ovc19_save.c` 108 |
| `(D) far const` | 652 | `ovc49_agents.c` 175, `ovc15_sprite.c` 66 |
| `p[iusc]Stack_` | 597 | `ovc22_classes.c` 140 |
| `(C) idx*stride` | 132 | `ovc25_intel.c` 31, `ovc45_unitinfo.c` 24 |
| `unaff_ES` | 60 | `ovl.c` 25, `ovc21_manage.c` 15, `crtl.c` 11 |
| `param_` | 46 | `ovc15_sprite.c` 36, `crtl.c` 10 |
| `...)` | 10 | `ovc41_main.c` 2, `crtl.c` 2 |
| `ram0x` | 7 | `ovl.c` 3, `crtl.c` 2 |
| already 0 | — | `" + x`, `argN_`, `arg_`, `undefined[24]`, `stack0x`, `unaff_SS`, `valueN`, `numN`, `ptrN`, `(A)`, `(B)`, `LAB_`, `->pad_...` |

## Rows that are mechanically removable (done, or a recipe exists)

### `unaff_SS` — done, 797 → 0

`unaff_SS` is Ghidra's name for "the SS register, unaffected by this code".  The
program never changes SS, so it is always the current stack segment and Turbo C
spells it `_SS`.

* Most sites: rename `unaff_SS` → `_SS` and delete the dead `uint16_t unaff_SS;`.
* Two functions (`ovc25_intel.c`, `ovc26_fillgrid.c`) *assign* it inside a loop;
  there it is a real local tracking a segment → `uint16_t curSeg = _SS;`.

Script: `tmp/fix_unaff_ss.py`.

### `ptrN` — done, 264 → 0

Three unrelated kinds, all with the digit/underscore after `ptr`:

```c
__return_storage_ptr__      Ghidra's hidden struct-return pointer  -> retStorage
ptr_base / ptr_base_NN      far_t operand of the PADD_at_ helper    -> padBaseNN
ptr_ofs  / ptr_ofs_NN                                               -> padOfsNN
ptr_00                      the block handed to heapFree            -> blockPtr
```

Script: `tmp/fix_ptr_names.py`.

### Far-segment byte pokes (`(*(uint8_t *)&(x.seg))+1 = hi`)

1,075 occurrences tree-wide, e.g.

```c
(*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)audioSaveCut1Seg;
gfx.ofs = audioSaveCut1Ofs;
(*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)((uint)audioSaveCut1Seg >> 8);
```

is one 16-bit store `gfx.seg = audioSaveCut1Seg;` (and `dst.seg = _SS;` where the
source was `unaff_SS`).  These lines are not counted by any §5 grep, so this is
code-quality work, not gate work.

## Rows that need real recovery

### `[iusbc]Var`, `p[iusbc]Var`, `[iusc]Stack_`, `bStack_`, `in_stack_` (~52k)

Ordinary unnamed locals.  Only function-by-function reading removes them; the
single-shape pool at high use counts is exhausted, and the remaining large
functions are the merged/corrupted bodies listed below.

Read one slot at a time with

```
python tmp/slot_show.py <file> <function> <slot>
python tmp/rename_slot.py <file> <function> <slot> <newname>
```

Rules used so far: name the *role* (what the value is), never the type; if a slot
has two roles, split the variable or leave it.

### `unaff_DI` 1,159 / `unaff_SI` 828 / `unaff_ES` 60

These carry a *register value* across the function, e.g.

```c
pfVar2 = ovr_stshRleType2(...,(int16_t)unaff_SI,0,0);   /* SI at that point  */
*unaff_DI = cVar9;                                     /* DI is a pointer    */
```

There is no safe mechanical substitute: `_DI`/`_SI` would read whatever the
rebuilt code happens to leave in the register.  Each site needs the original
expression recovered (usually a parameter that the prototype dropped, or a
pointer that a `les`/`lds` loaded).  When the value is known, replace it with
that expression and delete the `unaff_*` declaration.

### `(D) far const` 652 and `(C) idx*stride` 132

Both are index*stride+offset addressing that should be a typed field access:

```c
*(int *)((int)uStackY_22 * 0x34 + 2)          /* agent record, field at +2 */
*(char *)((int)Entities + i * 0x37 + 0x1a)     /* entity record, field 0x1a */
```

`0x34` is `sizeof(agnt_t)`, `0x37` is `sizeof(entity_t)`.  Removing these means
naming the field in the struct and rewriting the expression as
`((agnt_t *)base)[i].field`; that needs the field table for each record, which is
the same work as the remaining struct refinement.

### `in_REG` 937

Register outputs that the recovered prototypes drop.  The general fix is to
declare the called function with the correct return type so the register value
becomes an ordinary return value (this is how `stshStoreFile`'s DX was fixed).
154 of the 937 are in `crtl.c`, which is compiler-supplied.

### `char [N] = ""` 1,408

**These are genuine data.**  Example:

```c
char s_bigcomp_lbm_2410_2a87[12] = "bigcomp.lbm";
```

The `2410_2a87` suffix is the original far address: the string really lives at
`2410:2a87` in the image.  Inlining it at the call site would delete bytes the
original stores, which the project's byte-exact-data rule forbids.  Reducing this
row requires a policy decision (for example declaring the block as one
`char[..]` table with explicit initialisers), not a rename.

## Bodies that cannot be cleaned at source level

These functions decompile into garbage because their code spans an overlay
boundary, so Ghidra models the continuation as arithmetic:

```
draw_textTalkwin9Lbm   ovc02_draw.c     543 C lines for a 515-byte / 161-insn body
ovc45_buildPlacementMessage ovc45_unitinfo.c 3354 lines for 1752 bytes
ovc22_textRingProt     ovc22_classes.c  2301 lines
ovc49_body1            ovc49_agents.c   2593 lines
```

`draw_textTalkwin9Lbm` is the clearest: its `JMP` targets inside the model are
`0x2000:e4xx` (the overlay thunk segment), the C body pushes those return offsets
onto the stack by hand, and the tail writes to string constants such as
`s_halfling_lodge_2410_1efd`.  Renaming its locals would be cosmetic on wrong
code; it needs the function body re-exported with the overlay model.

A quick screen for "safe to rename" is `C lines / (bytes/1024)`:

* 70–100 lines/KB — normal, hand-naming works (`constr_usesBlitGfxRect2` 80,
  `ovc49_drawAgents` 90);
* > 300 lines/KB — merged or split body, leave alone until the model is fixed.
