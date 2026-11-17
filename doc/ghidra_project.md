# Ghidra project mapping

The decompiler output is only trustworthy after the Ghidra program model is
correct.  This document tracks the project-level fixes.

## Root cause of `"string" + offset`

The baseline export (`reference/decompiled_baseline/`) was produced without
disabling the decompiler's constant-pointer inference.  Ghidra therefore
rendered every scalar that fell inside a string as a pointer into that string:

```c
else if ((char *)key == (char *)"mason's hall" + 7) { ... }   /* == 0x2300 */
DGROUP_at__at_ = (uint16_t)("puppetmaker" + 3);               /* == 0x2410 */
```

`"puppetmaker"` is at DGROUP `0x240D`, so `+ 3` is `0x2410`, the **DGROUP
segment**.  `"mason's hall"` is at `0x22F9`, so `+ 7` is the scan code
`0x2300`.

## Project fixes applied

1. `scripts/ghidra/ExportAll.java` now calls
   `opts.setInferConstantPointers(false);`.  This removes the inferred
   pointers from the whole export.
2. `2410:0004` (`__C0_ASM_CopyRight`) was retyped from `string` to a 43-byte
   array.  Small integer constants such as `0x0006`/`0x0008` no longer
   resolve to `"Borland C++ - Copyright 1991 Borland Intl." + n`.
3. A `DGROUP_SEG = 0x2410` equate was created and applied to the 4,621
   scalar operands with that value.
4. `scripts/ghidra/AuditProject.java` reports naming coverage.
   `scripts/ghidra/RetypeCopyright.java` performs step 2.
   `scripts/ghidra/CreateEquate.java` performs step 3.

## Effect on the export

Counts of `"string" + offset` expressions:

| export | expressions | `"puppetmaker"` |
|---|---|---|
| old baseline | 2,224 | 633 |
| `InferConstantPointers(false)` | 386 | 34 |
| plus copyright retype | 252 | 37 |
| plus `sweep_string_offsets.py` | **106** | **0** |

The sweep resolved every expression whose value is a segment constant and
replaced it with `DGROUP_SEG` or `SEG_xxxx` (`tmp/export_swept6`).  It also
renamed 561 raw segment scalars and replaced 89 small-integer collisions with
their integers, so the key debug call now reads:

```c
ovr_OVC40_69c8_04c6(0,0x251,DGROUP_SEG,0x27a,DGROUP_SEG,0);
```

The remaining 106 expressions all resolve to **real DGROUP data offsets**, not
segment values or integer constants.  The most common bases are:

```text
0x4234/0x4236  building record base (units)
0x3F48         build\thfres01.lbm follow-on table
0x69E4/0x69E2  substring pointers inside the save warning text
0x20A8/0x20AF  substring pointers inside "cleric castle"
```

Those need the DGROUP symbol/gap name (e.g. `BLD_RECORDS`) rather than a
segment name.


## Naming coverage (final)

```text
functions=1590 default=0
symbols=13360 default=0
definedData=2440 noSymbol=0 defaultSymbol=0
equates=26
```

All functions, symbols and defined data items now have names.  The semantic
names for the in-game state are recorded in `doc/bss_globals.md`; the rest use
the deterministic type/address scheme from the bulk pass below.  The old
`LAB_`/`DAT_`/`UNK_` prefixes are gone.

## Next project work

1. The string-offset sweep is complete: every remaining expression is mapped
   by `scripts/fbov/map_string_offsets.py`; the report
   `tmp/string_offset_targets2.csv` has **0 unresolved** values.  The common
   targets are real data, e.g. `0x4234 -> gap_2410_2A7C + 6072`
   (`BLD_RECORDS`), `0x69E4 -> s_Your_may_continue_p_2410_69db + 9`.
2. Fix function prototypes for the functions where segment values were
   typed as pointers so the clean export stays clean without the sweep.
3. Refine the type/address names for individual subsystems into semantic
   names; every item already has a unique name, but only the in-game state and
   BSS globals are semantically named so far.
4. Replace `unaff_`/`in_`/`extraout_` locals by fixing signatures and
   register/return types.


## Bulk naming pass

After the semantic names above, the remaining default symbols were given
deterministic, type-based names by `scripts/ghidra/BulkNameRemaining.java`:

```text
LAB_*   -> L_<function>_<offset>
DAT_*   -> <type>_<block>_<offset>
SUB_*   -> sub_<block>_<offset>
UNK_*   -> unk_<block>_<offset>
unsymbolized data -> data_<block>_<offset>_<type>
```

`scripts/ghidra/RefineBulkNames.java` then turns `undefined1/2/4_` prefixes into
`byte_/word_/dword_`.  Every function, data item and symbol now has a name; the
semantic names for the in-game state and BSS continue to take precedence.
Project backup before the bulk pass: `gpr_bak_before_bulk`.


## Prototype tooling

`scripts/ghidra/DumpProtos.java` prints signatures, parameter storage and
return storage for a list of addresses.  `scripts/ghidra/SetProtoSimple.java`
copies a return type and a parameter type from donor functions.

Caution: for a `__cdecl16far` function that returns a far pointer, Ghidra may
insert a hidden `__return_storage_ptr__` parameter instead of using `DX:AX`.
`manage_4d05_03a4` needs its return type modeled as a scalar (`uint32_t`) or
with explicit custom storage before its callers lose the `in_DX` artifact.


`SetProtoCustom.java` sets a function return/parameter with explicit storage.
For `manage_4d05_03a4` it now produces the correct signature without a hidden
return pointer:

```text
void * manage_4d05_03a4(char * p)   cc=__cdecl16far
return DX:2,AX:2
param p char *32 @ Stack[0x6]:4
```

`SetProtoTwo.java` does the same for two far-pointer parameters; it was used
to correct `font_302d_06ea` to
`uint16_t font_302d_06ea(char *text, uint8_t *widths)`.

The remaining `in_DX`/`extraout_AH` values in `manage_4d05_056e` come from
`blitLabel`/`77eb:0904` calls whose far-pointer or long arguments are still
reconstructed from split return registers; the sheet fields themselves are
now fully typed.


## Unit and building structs

`scripts/ghidra/RecoverStructs.java` creates and applies the game structs.

```c
struct unit_t {          /* size 9, GUnits[] */
    byte bldType;        /* index into BuildingTypes, stride 0x27 */
    byte level;          /* level/count */
    byte unitType;
    byte flags;
    short x;
    short y;
    byte timer;
};

struct entity_t {        /* size 0x37, Entities[] */
    struct agnt_t base;  /* 0x00..0x33 */
    byte reserved[3];
};

struct bld_inst_t {      /* size 0xC, BldInstances[75] */
    short field0;
    short field2;
    byte data[8];
};
```

Typed globals:

```text
2000:CA95  GUnits       unit_t *32
2000:D18E  Entities     entity_t *32
2000:CB05  GMapCells    byte[59][148] *32
2000:CB09  GMapFlags    short[60][148] *32
2000:CB0D  GUnitGrid    short[148][60] *32
2410:4234  BldInstances bld_inst_t[75]
195D:010E  BuildingTypes bldtp_t[248]   (already present)
1726:0000  Agnts        agnt_t[24]      (already present)
195D:26D6  AgntGs       agntG_t[42]     (already present)
2410:0958  AgntAnms     anm_t[139]      (already present)
```

The `agnt_t` fields at offsets 0 and 2 are named `x` and `y`: they index
`GMapFlags[y][x]`.

Verification from the re-decompiled functions:

```c
/* upd_units_5087_1d7d */
((unit_t *)GUnits)[i].flags
((unit_t *)GUnits)[i].x
((unit_t *)GUnits)[i].y
((unit_t *)GUnits)[i].bldType

/* OVC13_3d16_0255 */
((entity_t *)Entities)[i].base.y
((entity_t *)Entities)[i].base.field15_0x17
```


## UI and character-sheet structs

`scripts/ghidra/RecoverUiStructs.java` creates `char_sheet_t` and `ui_menu_t`
and applies `char_sheet_t *` to the dialogs.  A freshly constructed dynamic
`StructureDataType` reports length 1 even with no components, so the script
treats an empty structure as length 0 in `padTo()`; without that correction
every field lands one byte early (`stats[i + 1]`, `stats[0] |= 0x20`).

```c
struct char_sheet_t {    /* size 0xAE, character/town record */
    byte pad_0[0x28];
    byte statMask;       /* 0x28, bit 5 = stats rolled, bit 1/2 = dialog flags */
    byte stats[6];       /* 0x29..0x2e */
    byte cls;            /* 0x2f, -1 = no class */
    byte race;           /* 0x30 */
    byte alignment;      /* 0x33 */
    byte gender;         /* 0x34 */
    far_t name;          /* 0x35 */
    byte active;         /* 0x3d */
    byte classStr;       /* 0x3e */
    byte excluded;       /* 0x3f */
    short population;    /* 0x4d */
    short foodProd;      /* 0x4f */
    byte charIndex;      /* 0x51, -1 = none */
    short income;        /* 0x54 */
    long gold;           /* 0x56 */
    short housing;       /* 0x5b */
    long foodStored;     /* 0x60 */
    long foodStorage;    /* 0x7e */
    byte popularity;     /* 0x84 */
    byte level;          /* 0x86 */
    short rank;          /* 0x87, clamped to 10 for Fund Access */
    byte partySlot;      /* 0x89, 0xff = none */
    long vaultStorage;   /* 0x8a */
    short maxTrade;      /* 0xa0 */
    short foodSold;      /* 0xa2 */
};

struct ui_menu_t {       /* size 0x10; far-pointer entry list */
    far_t title;         /* entries[0], not selectable */
    far_t items[3];      /* entries[1..3] */
};
```

Evidence applied in the project:

- `manage_4d05_01d4` rolls `stats[0..5]` and sets `statMask |= 0x20`.
- `manage_4d05_03a4` returns a title from `cls`, `level`, `race` and `gender`.
- `manage_4d05_056e` reads `population`, `foodProd`, `charIndex`, `gold`,
  `foodStored`, `housing`, `foodStorage`, `income`, `vaultStorage`,
  `maxTrade` and `foodSold` directly from the sheet.
- `manage_4d05_0d7b(byte, char_sheet_t *)` and
  `manage_4d05_2d79(byte, short, char_sheet_t *)` take the sheet after the
  leading byte/short arguments.
- `manage_4d05_029d`, `02f1`, `0340` and `11cb` read `cls`, `race` and
  `stats`; `alignmentDlg` writes `alignment` and `uiPickGender` writes
  `gender`.
- `uiInputText(far_t *entries, short count, byte *hint, byte flags)` receives
  the `ui_menu_t` entry list; its first entry is the title.

### Byte-exact replacements

`src/game/ui.c` holds twenty-two recompiled UI functions.  With byte returns and
the recovered structs they compile to the original instruction streams exactly:

```text
4D05:0081 229 bytes  manage_4d05_0081   (chargen panel setup)
4D05:0166  61 bytes  manage_4d05_0166   (standard panel)
4D05:01A3  49 bytes  manage_4d05_01a3   (3d6 ability roll)
4D05:01D4 102 bytes  manage_4d05_01d4   (roll the six starting stats)
4D05:023A  99 bytes  manage_4d05_023a   (ordinal suffix)
4D05:029D  84 bytes  manage_4d05_029d
4D05:02F1  79 bytes  manage_4d05_02f1
4D05:0340 100 bytes  manage_4d05_0340
4D05:03A4 170 bytes  manage_4d05_03a4   (class/level title)
4D05:044E 120 bytes  manage_4d05_044e   (average active popularity)
4D05:04C6  83 bytes  manage_4d05_04c6   (right-align text run)
4D05:0519  85 bytes  manage_4d05_0519   (right-align text at row)
4D05:0D7B  67 bytes  manage_4d05_0d7b
4D05:1095 177 bytes  manage_4d05_1095   (alignment picker)
4D05:1146  69 bytes  manage_4d05_1146   (gender picker)
4D05:118B  64 bytes  manage_4d05_118b   (alignment stop by race)
4D05:11CB 145 bytes  manage_4d05_11cb   (starting hit points)
4D05:125C  58 bytes  manage_4d05_125c   (default class by race)
4D05:1B1D  52 bytes  manage_4d05_1b1d   (first levelled record)
4D05:1B51 157 bytes  manage_4d05_1b51   (next record by excluded status)
4D05:217A 313 bytes  manage_4d05_217a   (comma-separated decimal)
4D05:330C 346 bytes  manage_4d05_330c   (unit filter description)
```

`scripts/fbov/verify_ui_bytes.py` parses `UI.OBJ` and compares every body with
the original overlay.  It allows relative call/jump operands to differ (they
encode positions inside the overlay) and masks OMF relocation sites, which it
prints together with their target symbols so a wrong global reference is
visible.  Current relocations:

- `_f_474a_0b26` (random roll) in `01a3`/`01d4`;
- `_f_302d_06ea` (text width) and `_f_302d_0634` (text blit) in `04c6`/`0519`
  — the call operands are FBOV overlay-header trampoline offsets;
- `_DAT_2000_d1e6` (`GLeaderCount`, DGROUP `0x90E6`) in `044e`/`1b1d`;
- `__DATA` (DGROUP offset 0) as the base of the character-pointer table at
  load-time segment `0x0070`.  The original linker emitted a zero offset for
  that table, so the recovered source uses `&_DATA` to reproduce the
  relocatable zero and the 4-byte `les bx, es:[bx+0]` encoding.
- `F_SCOPY@` plus `_GPlayerTitles`, `_GAlignmentString`, `_GStatsLabels`,
  `_GAlignmentsNames` and `_DAT_2000_d1e5` in the dialog helpers.  The original
  copied menus/title sets with C struct assignment, which TCC implements with
  the resident `SCOPY@` block copy (`dst`, `src` on the stack, byte count in
  `CX`).  `03a4` and `1095` reproduce that with struct assignments; the string
  literals (`""`, `"Select an alignment."`, `"Male or female?"`) resolve to
  the original DGROUP pool (e.g. `""` shares the NUL of `"Lawful"` at
  `0x4B75`).

The character table itself is an array of `char_sheet_t far *` at offset 0 of
segment `0x0070`; the count lives in `GLeaderCount`.  `044e` and `1b1d` must
not cache the table pointer: the original recomputes the far address for every
field access, which the macro in `ui.c` reproduces.

Two functions need a link-time fix-up rather than a source shape:

- `17c7` calls `1bee` in the same overlay.  That call was a cross-module
  `lcall` at compile time; the overlay linker rewrote it into
  `push cs; call rel16; nop` (one byte larger than TCC's own
  `push cs; call rel16`).  Reproducing it needs either a one-byte padding
  pass or an out-of-line definition, so `17c7` is not in `ui.c` yet.
- `22b3` indexes the entity array as `base + i`; TCC schedules the pointer
  load before the `i * 0x37` scaling, while the original computes the index
  first.  The function is semantically understood but awaits the idiom that
  reproduces that order.

(`build_game.py` compiles `ui.c` alongside the other recovered fragments.)
