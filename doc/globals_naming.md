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

## Batch 5 - message latch

2410:45B8 is set right after a notification and used to skip one update pass:

    if ((byte_45B8 != 0) || (GameRunning)) { byte_45B8 = 0; }
    else { ...rebuild the leader list... }

    /* where it is set: the player entity stands on the cursor square */
    stats_6386_232d(); say(); byte_45B8 = 1; return;

Named MsgShown.

## Batch 6 - XMS copy state

xms_1000_032f loads the extended-memory copy parameters into DGROUP cells,
advances the offsets and issues the driver call:

    word_02BD = xms_data2;  word_02BF = param_3;  word_02C1 = param_4;
    word_02C5 = param_1;    word_02C7 = param_2;
    if ((param_5 & 1) != 0) { 02B9 = 2; 02BB = 0; (*xms_driver)(0x1000);
        bVar1 = 0xfffe < 02BF;  02BF++;  02C1 += bVar1;  02C5++; ... }

so 02BF/02C1 are the 32-bit source offset and 02C5/02C7 the destination offset,
02BD the handle and 02B9 the command word.  Named XmsHandle, XmsCmd, XmsSrcLo,
XmsSrcHi, XmsDstLo, XmsDstHi.

## Batch 7 - XMS command word

The same routine sets the command as a 32-bit value before calling the driver:

    word_02B9 = 2;  word_02BB = 0;  (*xms_driver)(0x1000);

so 02B9/02BB are its low and high words: XmsCmdLo / XmsCmdHi (the earlier
XmsCmd name covered only the low word).

## Batch 8 - the remaining two index permutations

2000:0020 and 2000:002C follow the same pattern as IndexPermA/B: a 12-byte
table initialised from a constant template, then permuted in place with the
X[uVar2] = X[param_1] and X[i] == i idiom.

    0020: memcpy(&X, 0x6e14, 0xc)   -> IndexPermC (2000:ca54)
    002C: memcpy(&X, 0x6e08, 0xc)   -> IndexPermD (2000:ca60)

yte_2410_DATA_DGROUP_00D8 is a 0..6 index (bound 6 <), used as * 2 and
added into a byte offset; seven values with no identifying consumer, so it stays
unnamed.

## Batch 9 - overlay flag byte

225d:0010 (the OVRDATA segment) is a flag byte: bit 0 is set and bits 0 and 1
are tested by the overlay manager in \ovl\.

    225d:0010 -> OvrFlags

0:06C0\ is a 0/1 flag paired with an agent's 0x2a == 2 test and
\DS:0198\ is a far pointer used by the driver module; neither has a consumer
that fixes a name, so both stay unnamed.

## Batch 10 - the sound driver pointer

`DS:0198` is a far pointer to a loaded sound driver.  The checker validates the
tag six bytes before it:

```c
iVar2 = (int)data_DS_0198;
if (*(int *)(iVar2 + -6) == 0x494d && *(int *)(iVar2 + -4) == 0x4944) {   /* "MIDI" */
    pcVar1 = (code *)swi(0x66);
    if ((*pcVar1)(0x2410) == 0) return_false;
}
else if (*(int *)(iVar2 + -6) != 0x454b || *(int *)(iVar2 + -4) != 0x4e52)  /* "KERN" */
    return_false;
```

Named `DriverEntry` (`0000:0198`).

`2000:06C0` still has no consumer that fixes a meaning: its only context is
`agent->0x2a == 2 && flag != 0`, which names neither side.

## Batch 11 - animation activity flag

`2000:06C2` mirrors the activity predicate: it is set whenever
`agnt_3b1d_0000()` reports something moving

```c
/* agnt_3b1d_0000: AgntCount != 0 || byte_2000_BSS_08A2 != 0 || GAnimPlaying != 0 */
bVar1 = agnt_3b1d_0000();
if (bVar1) byte_2000_BSS_06C2 = 1;
...
if ((byte_2000_BSS_06C2 != 0) && (GOngoingBattle == 0)) ...
```

Named `AnimActive` (`2000:d0f6`).

Examined and left unnamed in the same pass:

- `2000:027C` - start of a byte buffer that is scanned backwards until a `\`
  and initialised with a random value or 20; the buffer is the object, not this
  byte.
- `2410:5AEB` - an array of seven far pointers, each walked in 6-byte steps
  while the level is halved (`bStack_7 >>= 1`) until `0xff`; it is a ramp search
  but whether the entries are palettes or shade bands is not fixed.

## Batch 12 - the ramp table array

2410:5AEB holds seven far pointers (offset at 0x5aeb, segment at 0x5aed,
BX = i*4), and OVC27_5ded_1c94 walks the selected table in 6-byte steps:

    while (*p != 0xff && (*p < level)) { p += 6; level >>= 1; }

so each table maps a value to one of six buckets by successive halving, and 0xff
terminates.  Named RampTables: the layout and the lookup are proven, the payload
of each 6-byte entry (colour? shade?) is not.

The disassembly confirms the base:

    5ded:1cc0  MOV AX,word ptr [BX + 0x5aed]     ; segment
    5ded:1cc4  MOV DX,word ptr [BX + 0x5aeb]     ; offset

## Batch 13 - palette flash toggle

2000:06D1 flips on every pass and selects one of two 3-byte colours for the
palette call:

    byte_2000_BSS_06D1 = 1 - (byte_2000_BSS_06D1 != 0);
    ovr_vgaSetPalette(local_1e + (uint)byte_2000_BSS_06D1 * 3);
    ovr_vgaSetPalette(local_18 + (uint)byte_2000_BSS_06D1 * 3);

Named FlashToggle (2000:d105).

## Batch 14 - `2000:027C` is not a variable

The consumer is `append_name_to_path`, which copies a path into `GStaticBuffer`,
scans back to the last backslash, truncates and appends a name:

```c
strcpy((char *)&GStaticBuffer,path);
for (l = strlen((char *)&GStaticBuffer);
     (0 < (int)l && (((undefined1 *)&byte_2000_BSS_027C)[l] != '\\')); l = l - 1) { }
((undefined *)&GStaticBuffer)[l] = 0;
strcat((char *)&GStaticBuffer,name);
```

The two symbols are adjacent, not equal: `byte_2000_BSS_027C` is at
`2000:ccb0` and `GStaticBuffer` at `2000:ccb1`.  The scan therefore addresses
one byte before the buffer, i.e. `027C` is only the base of a
symbol-relative pointer expression - the nearest label minus one - not a
storage location of its own.

It must not be given a name: the correct model fix is to drop the redundant
label so those references resolve to `GStaticBuffer`.  That is a symbol cleanup
(needs a remove-symbol pass), not a rename, and it is recorded here rather than
papered over with a name like `PathScanBase`.

## Batch 15 - RNG seed high word

¡0:26E1\ is combined with GSeed as one 32-bit seed and refreshed from the
BIOS timer:

    word_26E1 = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
    srand8(CONCAT22(word_26E1, GSeed));

Named SeedHi.  ¡0:74AC\ (ovc45) has only a conditional and one assignment in
the export and stays unnamed.

## Batch 16 - smoothing latch

¡0:0742\ stores the previous value of an interpolation step:

    iVar1 = constr_36ce_0000(param_1,param_2);  *param_3 = iVar1;
    iVar1 = (*param_3 - word_0742) * 3;
    if (iVar1 < 0) iVar1 = iVar1 * *(byte*)(param_2+0x733) / 0x10;
    else           iVar1 = iVar1 * *(byte*)(param_2+0x733) >> 4;
    ... word_0742 = iVar1 / 3;

The delta from the stored value is scaled by a per-object factor with the same
signed shift in both branches, i.e. a lerp, and the result is stored back.
Named SmoothPrev.  ¡0:74AC\ is compared against entity+0x1a (an id set from a
constructor argument) as a fallback match; it stays unnamed.

## Batch 17 - sound repeat deadline

For sound 0x76 the audio routine checks a stored time against the current counter
before playing again:

    uVar3 = ovr_attact_3f0b_082f();
    if ((in_DX == 0) && (uVar3 < word_07B2)) return;
    ... word_07B2 = bVar2 + 0x80;

so 07B2 is the earliest time the sound may repeat.  Named SfxDeadline.

## Batch 18 - menu blit frame

0:06CC\ is a six-frame counter for the menu blit:

    if (5 < byte_2000_BSS_06CC) byte_2000_BSS_06CC = 0;
    ovr_blitLoadRleGfx();
    byte_2000_BSS_06CC = byte_2000_BSS_06CC + 1;

Named BlitFrame (2000:d100).

## Batch 19 - audio graphics handle

¡0:07B6\ receives a handle from stshLoadGfx and passes it straight into the
audio routine:

    word_07B6 = ovr_stshLoadGfx();
    audio_3a5b_0761(word_07B6, in_DX, ...);

Named SfxGfx.  ¡0:07B5\ caches its previous argument for change detection
(compared, then assigned from param_1) and stays unnamed because the argument's
own meaning is not established.

## Batch 20 - draw busy flag

¡0:0160\ brackets draw_2e25_0938: set to 1 at entry next to MiceUnkState and
GGameState, cleared to 0 before returning, and never read in any exported module,
so the consumer is code outside the export (an interrupt handler guarding the
screen).  Named DrawBusy.

## Batch 21 - XMS padding word

@0:02C3\ lies between the 32-bit source offset (02BF/02C1) and the 32-bit
destination offset (02C5/02C7) in the XMS request block; the routine zeroes it
and never reads it.

    02BD handle | 02BF/02C1 source | 02C3 zeroed | 02C5/02C7 destination

Named XmsPad.  Note this also confirms the offset assignment used earlier: the
destination really is the 02C5/02C7 pair, because both halves are written
consecutively (02C5 = param_1, 02C7 = param_2).

## Batch 22 - current music track

¡0:07B5\ records the track the MIDI routine last started: the routine returns
early when the requested track already matches it, and stores the argument after
registering the XMIDI and starting playback.

    if ((byte_07B5 == param_1 || ...)) ...;
    midRegisterXMIDI(...); midSetRelativeValue(100,0); midPlaySequence();
    byte_07B5 = param_1;

Named CurrentTrack.  The earlier refusal was premature: it was based on the
store alone, and the caller shows the comparison that fixes the meaning.

## Batch 23 - both factions present

0:06C0\ is computed from a two-byte faction map: the loop marks one byte per
agent faction (agent+0x2f) and the flag is 1 only when both bytes are set.

    ((char *)&map)[agents[i] * 0x34 + 0x2f] = 1;
    if ((map[0] == 0) || (map[1] == 0)) 06C0 = 0; else 06C0 = 1;

Named BothFactions (2000:d0f4).  This is the second previously-refused entry that
reading the call site resolved.

## Batch 24 - text-mode screen height

\DS:0484\ is the text-mode height in rows: mode 3 is 80x25, so a value above 24
means a taller text mode and the CRT switches to its special mode 0x40.

    if ((uVar1 == 0x3) && ('\x18' < data_DS_0484_undefined1)) { _video.currmode = 0x40; }

Named ScreenHeight (0000:0484).

¡0:74AC\ remains unnamed: it is a stored value compared against entity+0x1a
as a fallback match, and entity+0x1a is a small index into a pointer table set
from a constructor argument, so 74AC is an id in that space whose subject is not
named anywhere.

## Batch 25 - interrupt result flags

\DS:0487\ is the flags byte of the software-interrupt helper: bit 0 (carry) is
cleared on one result path and set on the other, around the INT 10h call.

    if (cVar2 != 0x1a) data_DS_0487 = data_DS_0487 & 0xfe;   /* CF = 0 */
    ...                data_DS_0487 = data_DS_0487 | 1;      /* CF = 1 */

Named IntFlags (0000:0487).

## Batch 26 - music graphics far pointer

`2410:07BE`/`07C0` are the offset and segment of the graphics loaded for the
music routine: the offset comes from `stshLoadGfx()`, the segment from the
register the loader returns, and the pair is passed to `audio_3a5b_0761`
together with the MIDI handle.  Named `MidGfxOfs` / `MidGfxSeg`.  It is the
same shape as `SfxGfx` (07B6), the single-word handle for the effects path.

## Batch 27 - music sequence handle

`2410:07CA` holds the handle that `audio_3a5b_0761` returns for the music
sequence, after the second graphics load:

    word_07C6 = ovr_stshLoadGfx();  word_07C8 = in_DX;
    word_07CA = audio_3a5b_0761(word_07C6, in_DX, *(undefined2 *)(iVar2 + 5), ...);

Named MusHandle.  The pair `07C6`/`07C8` is examined but unnamed: it is a
second graphics far pointer (offset from stshLoadGfx, segment from the same
register), and which asset it is cannot be told apart from the 07BE/07C0 pair.
