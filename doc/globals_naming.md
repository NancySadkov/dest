# Global naming ledger

Every rename is recorded with the evidence that forced it.  No name here is a
guess: each one is a consequence of a quoted use.

## Batch 1 - string literals (433 renamed)

Rule: a string's own bytes are its evidence.

```
data_2410_DATA_DGROUP_0012_string -> s_vdisk_fake           ("VDISK FAKE")
data_2410_DATA_DGROUP_002F_string -> s_divide_error         ("Divide error\n")
data_2410_DATA_DGROUP_003D_string -> s_abnormal_program_termination
```

Applied by `scripts/ghidra/RenameStrings.java`; every `s_*` string label with
its escaped bytes is in `doc/strings_renamed.tsv` (1516 rows), so any name can
be checked against the data it names.  9 candidates were skipped because the
data at the label is not printable text.

## Batch 2 - mouse cursor state (4 renamed)

Evidence, `ovc02_draw` (`draw_2e25_0d35`), the loop that erases and redraws the
pointer:

```c
iVar3 = word_2410_DATA_DGROUP_00E6;          /* Y */
iVar2 = word_2410_DATA_DGROUP_00E4;          /* X */
...
byte_2410_DATA_DGROUP_00EA =
    *(undefined1 *)(word_2410_DATA_DGROUP_00E6 * 0x140 + word_2410_DATA_DGROUP_00E4);
```

`0x140` is the 320-byte framebuffer row, so 00E4/00E6 are the pointer
coordinates.  The same block sets 00E8 just before restoring and redrawing the
saved pixel and tests it as "the pointer moved":

```c
if (!bVar1) { word_2410_DATA_DGROUP_00E8 = 1; }
ovr_miceRestoreArea();
byte_2410_DATA_DGROUP_00EA = ...screen[y * 320 + x];
draw_2e25_0ad1();
```

| old | new |
|---|---|
| `word_2410_DATA_DGROUP_00E4` | `MouseX` |
| `word_2410_DATA_DGROUP_00E6` | `MouseY` |
| `word_2410_DATA_DGROUP_00E8` | `MouseMoved` |
| `byte_2410_DATA_DGROUP_00EA` | `MouseBkgPixel` |

## Batch 3 - menu state and music (2 renamed)

`2000:07AA` is indexed by the selected item and `0xff` disables the entry:

```c
if (((undefined1 *)&byte_2000_BSS_07AA)[mi] != -1) { ... }
} while ((GMenuItem != 5) && (((undefined1 *)&byte_2000_BSS_07AA)[GMenuItem] == -1));
```

| old | new |
|---|---|
| `byte_2000_BSS_07AA` | `MenuItemEnabled` |

`2410:07A6` is the music-side counterpart of the already-named `CurSfxType3`,
tested only under `MusRunning`, `0xff` = nothing, and holds track ids:

```c
if (((MusRunning != '\0') && (byte_2410_DATA_DGROUP_07A6 != -1)) &&
   (cVar1 = audio_3a5b_034e(), cVar1 == '\0')) { play_sfx(); }
if (((SfxRunning != '\0') && (CurSfxType3 != 0xff)) ...
```

| old | new |
|---|---|
| `byte_2410_DATA_DGROUP_07A6` | `CurMusicType` |

## Still generated

657 globals keep their generated names.  They are not named yet because the
evidence has not been read, not because the names are unknown: the worklist is
`tmp/globals_by_module.tsv`, ordered by how many modules reference each one.

## Batch 4 - construction row table

`2000:039E` is filled per row index in `ovc09_init` and read back in
`ovc10_constr` only as a blit y coordinate:

```c
((undefined2 *)&word_2000_BSS_039E)[iVar8] = ...;          /* init, by row */
gfxRlePrepare(..., ((undefined2 *)&word_2000_BSS_039E)[iVar8] - iStack_14, ...);
```

so it is the per-row screen y base, named `RowScreenY` (`2000:cdd2`).
