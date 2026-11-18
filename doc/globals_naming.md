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

## Batch 28 - saved INT 19h segment

`2272:0031` is the segment half of the old INT 19h vector, saved before the
overlay handler installs itself:

```c
_BootHandlerCode = uRam00000064;          /* 0x19*4 = old offset   */
word_2272_0031   = uRam00000066;          /* old segment           */
uRam00000064 = 0x3f;
uRam00000066 = 0x2272;                    /* new vector            */
```

The vector address `0000:0064` is `0x19 * 4`, and the pair
(`_BootHandlerCode`, this word) is exactly an interrupt vector's two halves.
Named `Int19Seg`.  Its partner `_BootHandlerCode` was already named, which is
what made the pairing checkable.

## Batch 29 - the midLoadDriver argument pairs

`musInit` stores two consecutive far-pointer pairs and passes them straight
into the driver load:

```c
MusHandle     = audio_3a5b_0761(word_07C6->cmap, in_DX, ...);  /* AX = offset */
MusHandleSeg  = in_DX;                                        /* DX = segment */
MusDrvOfs     = ovr_stshLoadGfx(handle_00);                   /* AX = offset */
MusDrvSeg     = in_DX;                                        /* DX = segment */
ovr_midLoadDriver(MusHandle, MusHandleSeg, MusDrvOfs, MusDrvSeg);
```

Every one of the four is either the AX return of a loader or the DX segment
that accompanies it, and the callee (`midLoadDriver`) names what the pair
feeds.  Renamed `07CC` to `MusHandleSeg` (completing the `MusHandle` offset
named earlier) and `07CE`/`07D0` to `MusDrvOfs`/`MusDrvSeg`.

The decompiler confirms the flow:

```c
MidGfxOfs = ovr_stshLoadGfx(_word_2000_BSS_0660);
MidGfxSeg = in_DX;
MusHandle = audio_3a5b_0761(word_2410_DATA_DGROUP_07C6->cmap, in_DX, ...);
MusHandleSeg = in_DX;
MusDrvOfs = ovr_stshLoadGfx(handle_00);
MusDrvSeg = in_DX;
```

The remaining `07C6`/`07C8` pair stays unnamed: it is a second raw graphics
pointer whose only distinguished use is being handed to `audio_3a5b_0761`,
which the `MidGfx` pair already does.

## Batch 30 - battle setup delay

`2410:07F6` counts animation passes before a battle is set up:

```c
if (((AnimActive != '\0') && (GOngoingBattle == '\0')) &&
    (BattleDelay = BattleDelay + 1, 2 < BattleDelay)) {
    word_2000_BSS_06C5 = ovr_stshAlloc();      /* blit buffer */
    ...
    BattleDelay = 0;                           /* after setup */
```

It is incremented in the animation-without-battle branch, the setup runs when
it exceeds 2, and it is cleared immediately after the setup, so it delays the
battle by three passes.  Named `BattleDelay`.

## Batch 31 - menu redraw cache

`2000:06DE` stores the menu-item value that was drawn last, so the tooltip is
only redrawn when it changes (or the caller forces a redraw):

```c
uStack_6 = *(byte *)(menuIndex + 0x9082);
if ((force != 0) || (word_2000_BSS_06DE != uStack_6)) {
    word_2000_BSS_06DE = uStack_6;
    font_302d_0a30();
    ...draw the item...
```

Named `PrevMenuValue` (`2000:d112`).

### Examined and not named

- `2410:00D8` (`ovc02_draw`): bounded `0..6`, used as `*2` and repeatedly as
  an addend in an unrolled byte accumulation.  The bound and the arithmetic
  are clear, the quantity being accumulated is not, so the earlier refusal
  stands.
- `2410:49F7` (`ovc21_manage`): the five entries really are far pointers, and
  their targets are readable in the image:

  ```
  [0] 4EE9:2410  "has achieved the rank of EMPEROR.  Congratulations!"
  [1] 4F1D:2410  "has destroyed all enemies and has achieved EMPEROR. ..."
  [2] 4F62:2410  "has destroyed all enemies.  Congratulations!"
  [3] 4F8F:2410  "OK"
  [4] 4F92:2410  "Try Again"
  ```

  but the same module reads a *six-byte-stride* table at `0x4A02`
  (`4d05:2b37 MOV AL,byte ptr [BX + 0x4a02]`, `BX = index*6`), which lies
  inside entry 2's segment word.  Pointer array and byte table cannot both
  be correct at those addresses, so the extent of the array is unresolved and
  no name is applied yet.
- `2000:076F`/`0771` (`ovc48`): another `stshAllocStub()` far pointer
  (offset/segment) allocated in `init_assets2` next to `GMenuGfxOfs`/
  `GMenuGfxSeg`.  Which asset it holds is not distinguished by the code.

## Batch 32 - pending sound request

`2410:5CF1` is a one-shot sound request in the menu input loop: the only
reader plays a sound and clears the flag, and no exported module sets it:

```c
if (byte_2410_DATA_DGROUP_5CF1 != '\0') {
    ovr_play_sfx();
    byte_2410_DATA_DGROUP_5CF1 = '\0';
}
```

Named `SfxPending`.  As with `DrawBusy`, the setter is outside the export, and
the doc records that rather than hiding the inference.

### `2410:49F7` - the overlap is real, and ES is 2410

The `49F7` question is settled as far as the image allows.  The instruction
that reads the six-byte table is preceded by an explicit segment load, and the
raw bytes prove it is `MOV ES,AX` rather than the decompiler's `MOV AX,ES`:

```
4d05:2b1e  B8 10 24     MOV AX,0x2410
4d05:2b21  8E C0        MOV ES,AX          <- 8E C0, not 8C C0
4d05:2b23  26 C6 06 F0 5C 01   MOV byte ptr ES:[0x5cf0],1
4d05:2b2b  8A 46 EB     MOV AL,[BP-0x15]
4d05:2b30  BA 06 00     MOV DX,6
4d05:2b33  F7 EA        IMUL DX
4d05:2b37  8A 87 02 4A  MOV AL,byte ptr [BX+0x4a02]
```

So the read really is `DGROUP:0x4A02 + index*6`, and `0x4A02` is the last byte
of the `4F62:2410` pointer in the array that starts at `0x49F7`.  Both cannot
be plain static objects, which means the region is **dual-use**: it is
initialised as a far-pointer table (whose targets are the congratulation and
OK/Try-Again strings) and is also read as a six-byte-stride table at run time.
A single structure cannot describe that, so `49F7` stays unnamed; the finding
is recorded here instead of being resolved by picking one of the two uses.

## Batch 33 - the rank announcement phrase table

`2410:6B3A` is an array of nineteen far pointers, all into DGROUP, and the
bytes they point at are the phrases the rank announcement is assembled from:

```
[0] 6B90:2410  "On this day it was declared to all the Realms"
[1] 6BBE:2410  "that %s shall henceforth hold the rank of"
[2] 6BE8:2410  "%s, in recognition of valor on the field of battle."
...
[15] 6BBD:2410  points at the terminating zero of the previous phrase,
                i.e. an intentionally empty slot
```

`ovc40` copies entries `0..14` (0x3c bytes) and `15..18` (0x10 bytes) into a
local, i.e. it is a fixed nineteen-entry table.  Named `RankMsgPtrs`.

Examined and left unnamed in the same pass:

- `2410:5DF2` (`ovc30`): one of four consecutive words (`5DEC`, `5DEE`, `5DF0`,
  `5DF2`) loaded as a group and used only as `CONCAT11(word >> 8, 0x29)`; the
  group is real, but which of the four is what is not distinguished.
- `2000:0039` (`ovc02_draw`): the raw code confirms the odd arithmetic —
  `MOV AL,[0x896d]; IMUL 0x34; ADD AX,0x26; MOV [0x897e],AX` and then that
  value is used as a *row* into the `0x34c` table.  The distance between
  "agent index" and "row coordinate" is unresolved, so it stays unnamed.

The name is visible in the live decompile of the consumer, which also shows the
whole table is copied into locals before use:

    F_SCOPY((far_t *)RankMsgPtrs, ..., &local_5c)        /* entries 0..14  */
    F_SCOPY((far_t *)(RankMsgPtrs + 0xf), ..., local_6c) /* entries 15..18 */
    F_SCOPY((uint8_t *)0x6b86, ..., &local_14)           /* 10 bytes after  */

## Batch 34 - level bands and the level cap they select on

`OVC30_619c_025d(param_1)` picks a random generic agent whose cap falls in a
per-slot band.  Four consecutive DGROUP words are loaded as two byte arrays and
indexed by `param_1`:

```c
local_6 = LevelBandMin;   /* 5DEC, array spans 5DEC..5DEF */
local_a = LevelBandMax;   /* 5DF0, array spans 5DF0..5DF3 */
do {
    uVar2 = ovr_randBelow(0x2a);
    if ((char)uVar2 == 0x29) continue;            /* 0x29 excluded */
} while (GMenuStrings[i*0x95 + 0x1f] == 0 ||
         gdata->levelLimit < *(byte *)(&local_6 + param_1) ||
         *(byte *)(&local_a + param_1) < gdata->levelLimit);
```

So the four words are a minimum and a maximum level array of four bytes each,
indexed by the slot, and the compared record byte is a **level cap**.  That byte
is `agntG_t+0x53`, whose other uses agree: `ovc22` writes 4, 8 or 0xc into it
from the progression counters (`0xff` for none), compares it with
`entity.base.level` (`field_0xf`), and `ovc27` tests it against 4.

| symbol | name | evidence |
|---|---|---|
| `2410:5DEC` | `LevelBandMin` | first word of the 4-byte per-slot minimum array |
| `2410:5DF0` | `LevelBandMax` | first word of the 4-byte per-slot maximum array |
| `agntG_t+0x53` | `levelLimit` | compared against entity level; 4/8/0xc, 0xff = none |

The tail words `5DEE` and `5DF2` are the second half of each four-byte array; they
are not separate variables and must not be named as such.

## Batch 35 - level-band labels

`2410:4B06` is an array of twenty far pointers into DGROUP, and the bytes they
target are the level-band labels:

```
[0] 53E9:2410  "level 1"      [1] "level 2"      [2] "level 3"
[3] "level 4"      [4] "level 5"      [5] "levels 6-10"
[6] "levels 11-15"  [7] "levels 16-20"  [8] "levels 20-25" ...
```

`ovc21_manage` copies entries `0..11` (0x30 bytes) and `12..19` (0x30 bytes)
into a local before display.  Named `LevelBandLabels`; it is the label side of
the same bands that `LevelBandMin`/`LevelBandMax` encode numerically.

## Batch 36 - three more label tables

Each is a fixed far-pointer table copied wholesale into a local by its only
consumer, and the bytes they point at are readable text, so the payload is the
evidence.

| symbol | consumer | copied | targets | name |
|---|---|---|---|---|
| `2410:45B9` | `OVC18_48ac_05f2` | `0xc` (3 ptrs) | "Strongholds cannot be placed on rivers." ... | `PlaceErrPtrs` |
| `2410:4ADA` | `manage_4d05_26f6` | `0x14` (5 ptrs) | "Done", "Summary 1", "Summary 2", "Summary 3", "Damage" | `ManageResultPtrs` |
| `2410:6E38` | `OVC41_6a8f_2084` | `0x10` (4 ptrs) | "cure light wounds", "cure serious wounds", "cure critical wounds", "cure all" | `CureSpellPtrs` |

The byte counts prove the entry count (`0xc/4 = 3`, `0x14/4 = 5`, `0x10/4 = 4`),
and every target was read from the image.  The live decompiles now show the
names at the copy sites:

```c
F_SCOPY((far_t *)PlaceErrPtrs, ...);        /* 48ac:05f2 */
F_SCOPY((far_t *)CureSpellPtrs, ...);       /* 6a8f:2084 */
F_SCOPY((far_t *)ManageResultPtrs, ...);    /* 4d05:26f6 */
```

### 2000:0039 - no writer anywhere in the export

A full search finds only the two reads in draw_2e25_0217 and no write at all, so
the byte is produced by code outside the exported modules.  Combined with the
index-used-as-coordinate arithmetic recorded earlier, there is not enough to name
it, and it stays unnamed.

## Batch 37 - four more data tables from their payload

Found by listing every remaining `far_t[n]` symbol and reading the bytes each
pointer targets.

| symbol | declared | targets | name |
|---|---|---|---|
| `2410:49EB` | `far_t[3]` | "A LAWFUL leader must achieve the rank of EMPEROR.", "A NEUTRAL leader ..." | `RankReqMsgPtrs` |
| `2410:4B56` | `far_t[4]` | "levels 6-8c", "levels 8d-8h", "levels 8i-8k", NULL | `LevelRangeLabels` |
| `2410:74AD` | `far_t[2]` | "person", "people" | `PersonWordPtrs` |
| `2410:84A8` | `far_t[9]` | "Summary", "Now what?", "City", "Buildings", "Money", "Popularity", "Combat", "Winter", ... | `StatsTabPtrs` |

`StatsTabPtrs` is confirmed by both sides: nine declared entries and a consumer
that copies `0x24 = 9 * 4` bytes:

```c
F_SCOPY((far_t *)StatsTabPtrs, ..., local_2a);   /* ovc50, 0x24 bytes */
```

### `49EB` and `49F7` are one table

The pointer sequence is continuous across the two symbols:

```
49EB: 4E41 (A LAWFUL leader ...)   49EF: 4E73 (A NEUTRAL leader ...)
49F3: 4EBE                        49F7: 4EE9 (has achieved the rank of EMPEROR ...)
49FB: 4F1D                        49FF: 4F62
4A03: 4F8F ("OK")                 4A07: 4F92 ("Try Again")
```

so the real array is eight entries (`49EB..4A0A`), and Ghidra split it into
`far_t[3]` + `far_t[5]` at `49F7`.  The first symbol carries the name; `49F7`
stays unlabelled as the interior continuation rather than being given a second
name for the same object.  The six-byte read at `0x4A02` (`ovc21_manage`) still
overlaps entry 6 and remains unexplained; that anomaly is unchanged by this
naming.

## Batch 38 - the square record's two key words

`attact_3f0b_05df` builds the per-square record from the square coordinates and
the list search compares exactly those two words:

```c
word_2410_DATA_DGROUP_086E = GfxRndSeed;    /* square x */
word_2410_DATA_DGROUP_0870 = GfxRndSeed2;   /* square y */
...
if ((*(int *)(uVar1 * 0x13) == GfxRndSeed) &&
    (*(int *)(uVar1 * 0x13 + 2) == GfxRndSeed2)) { ... }
```

so the first word named `SquareRecord` is really the x and the next word the y:

| address | name |
|---|---|
| `2410:086E` | `SquareRecX` (renamed) |
| `2410:0870` | `SquareRecY` (new) |

## The `26F7` symbol is a numeric coincidence, not a table use

The data at `2410:26F7` really is a thirteen-entry far-pointer table, and its
targets are readable:

```
2915 "Peaceful"   291E "Aggressive"   2929 "Hostile"   2931 "Custom"
2938 "Return"     293F "First City"   294A "World 1"    2952 "World 2"
295A "World 3"    2962 "World 4"      296A "World 5"    2972 "Random"
```

but **all 136 references to the symbol in the decompiled output are
symbol-relative renderings of offsets into a different segment** — every one has
the shape `&26F7[k].seg + index * 0x95`, i.e. the constant is an offset inside
the `195d:26d6` generic-agent table that happens to fall numerically inside this
DGROUP table's address range (e.g. `0x2711 = 0x26d6 + 0x3b`, and
`26F7 + 0x1A = 0x2711`).  The same coincidence is what makes some code appear to
write into the string `"Peaceful"`.

Consequences, deliberately not acted on:

- the symbol is **not** renamed, because giving it a menu name would relabel
  those 136 agent-table expressions with a menu name and make the decompiled
  code actively misleading;
- the generic-agent table base stays `195d:26d6` with stride `0x95`, as
  established from the constructor's `ES:[BX+0x2711]` and the stored pointer
  `gindex * 0x95 + 0x26d6`.

## The nine skipped string labels are one-character literals or offset artifacts

Batch 1 skipped nine `_string` candidates because the data at the label is not
printable.  Reading their bytes explains all nine:

| address | first bytes | what it really is |
|---|---|---|
| `2410:5FDE` | `0A 00` | a one-character `"\n"` literal, followed by "Adlib (1. Original 2. Gold):" |
| `2410:6097` | `0A 00` | `"\n"`, followed by "Pro Audio Spectrum (1. Plus 2..." |
| `2410:6156` | `0A 00` | `"\n"`, followed by "Largest executable program siz..." |
| `2410:2738` | `5F 00` | `"_"`, then a separate `"\r\n"` literal |
| `2410:747D` | `00` | NUL; `"strong.dat"` starts one byte later |
| `2410:78DF` | `00 00 01 00 00` | a small struct whose far pointer precedes "Done" |
| `2410:6939` | `00 00 43 8B 27 3F ...` | not text at all: a coordinate/value table |
| `2410:6AC3` | `00 C8 6A 10 24` | NUL then the far pointer `6AC8:2410`, then "My %s, we in this neighbourhood..." |
| `2410:6B39` | `00 90 6B 10 24 ...` | one byte before `RankMsgPtrs` (`6B3A`) |

So three are genuine single-character newline literals, and the rest are labels
sitting one or two bytes before the real object (a string, a struct, or the
pointer table already named).  None of them is a meaningful nameable string, and
they are left as they are rather than given invented text names.

## Batch 39 - the music-path graphics pair

`musInit` loads two graphics pairs and uses them for different things:

```c
MidGfxOfs = ovr_stshLoadGfx(_word_2000_BSS_0660);   /* fixed asset      */
MidGfxSeg = in_DX;
MIDHandle.ofs = audio_3a5b_0761(MidGfxOfs->cmap, in_DX, ...);

MusGfxOfs = ovr_stshLoadGfx(handle);                 /* per music type   */
MusGfxSeg = in_DX;
MusHandle  = audio_3a5b_0761(MusGfxOfs->cmap, in_DX, ...);
```

The second pair therefore feeds only the music handle, so it is
`MusGfxOfs`/`MusGfxSeg` (`2410:07C6`/`07C8`), while `07BE`/`07C0` stay the
`MidGfx` pair that feeds `MIDHandle`.  Auto globals: 599 -> 597.

## Batch 40 - the twelve-entry level range tables

`2410:4AEE` and `2410:4AFA` are two twelve-byte tables read with the same index,
and the code tests the entity level against both:

```c
if ((byte)((undefined1 *)&LevelRangeMin)[byte_2410_DATA_DGROUP_4B6D] <= entity.base.level) {
    if (entity.base.level <= (byte)((undefined1 *)&LevelRangeMax)[byte_2410_DATA_DGROUP_4B6D])
        goto accept;
}
return 0;
```

The values are monotonic, which is why they read as bounds:

```
min: 00 02 03 04 05 06 0B 10 14 1A 1F 24
max: 01 02 03 04 05 0A 0F 14 19 1E 23 FF
```

Named `LevelRangeMin` / `LevelRangeMax`.  The index `4B6D` is a selector with
`0xfe`/`0xff` sentinels set from a caller argument in `ovc21_manage`; what the
twelve entries are keyed by is not established, so the names say only what the
comparison proves (a per-index level range).

The same decompile also shows `entity.base.level`, i.e. the `agnt_t+0x0f` name
resolving in a third module.  Auto globals: 597 -> 595.

## Batch 41 - correcting `SfxGfx` into its two halves

`sfxInit` shows `2410:07B6` is only the offset of a far-pointer pair whose segment
is `2410:07B8`, and the pair builds the digital-sound handle:

```c
SfxGfxOfs = ovr_stshLoadGfx(handle);          /* AX */
SfxGfxSeg = in_DX;                            /* DX */
DIGHandle.ofs = audio_3a5b_0761(SfxGfxOfs->cmap, in_DX, ...);
DIGHandle.seg = in_DX;
```

The earlier single name covered only the offset half, so it is renamed and the
segment named:

| address | name |
|---|---|
| `2410:07B6` | `SfxGfxOfs` (renamed from `SfxGfx`) |
| `2410:07B8` | `SfxGfxSeg` (new) |

That completes the three audio graphics pairs, all built the same way
(`stshLoadGfx` for the offset, the returned `DX` for the segment):
`MidGfxOfs`/`MidGfxSeg` (07BE/07C0), `MusGfxOfs`/`MusGfxSeg` (07C6/07C8) and
`SfxGfxOfs`/`SfxGfxSeg` (07B6/07B8).  Auto globals: 595 -> 594.

## Batch 42 - season palettes and the promotion threshold

`2410:693B` is three 45-byte blocks selected by the season:

```c
F_SCOPY(&local_a0, &SeasonPalettes, 0x87);                  /* 3 * 0x2d */
_fmemmove(dest + 0x2d0, local_a0 + (uint)GSeason * 0x2d, 0x2d);
```

The copy size and the `GSeason * 0x2d` selection fix both the block size and the
count, so it is `SeasonPalettes`.

`2410:69D7` (its second word is `69D9`) is a four-byte threshold array indexed by
the caller's argument and compared with the leader record's `0xa5` byte; reaching
it promotes the matching units that are below level 8:

```c
local_6 = PromoteThreshold;                     /* with 69D9 as the high word */
for (bStack_7 = 0; bStack_7 < GLeaderCount; bStack_7 = bStack_7 + 1) {
    if (*(byte *)(&local_6 + param_1) <= *(byte *)(leader + 0xa5)) {
        for (...) if (unit.level < 8) { ... unit.level = 8; iVar3++; }
```

Named `PromoteThreshold`.  Its high word `69D9` is part of the same array and is
not a separate variable.

Auto globals: 594 -> 592.

## Batch 44 - party creation slots and the panel mode

`2000:07AF` is the party size and `2000:07B1` the 1-based slot of the character
being created:

```c
PartySize = 5;                        /* ovc09_init */
if (07B1 < PartySize) { ...; *(char *)(record + 0x89) = 07B1 - 1; }   /* partySlot */
if (PartySize <= 07B1) { ... next screen ... }
```

so `2000:d1e3` = `PartySize` and `2000:d1e5` = `CurPartySlot`.

`2410:26A8` records which full-screen panel is drawn: the manage-screen painter
sets it to 1, the unit-stats page to 2, and the draw routines test `== 0` to
decide whether painting is needed:

```c
byte_2000_BSS_06E2 = 0xff;
ScreenMode = 1;                       /* manage_4d05_0081 */
```

Auto globals: 589 -> 586.

### Correction: 2000:26A8 is not 2410:26A8

The first attempt renamed `2000:d0dc` (BSS offset `0x06A8`) because the audit name
`byte_2410_DATA_DGROUP_26A8` was misread as a BSS address.  The code references
the **DGROUP** address, so:

- `2000:d0dc` is restored to its generated name `word_2000_BSS_06A8`;
- `2410:26A8` is the one named `ScreenMode`.

Tooling note: `Rename.java` reports success even when the target name collides
with an existing symbol (`byte_2000_BSS_06A8` did), and the symbol keeps its old
name.  The audit then shows no change; always confirm with `ListSyms`.

## Batch 45 - the menu mode and its saved copy

`2000:003B` selects which menu screen is active.  `main` sets it to 1 immediately
before `uiMainMenu()` and whenever a menu item is chosen, and `ovc02_draw`
branches on 1/2 to draw the matching crosshair.  `2000:003C` is its save slot:

```c
MenuModeSaved = MenuMode;      /* ovc41 before a nested screen */
...
MenuMode = MenuModeSaved;      /* afterwards */
```

and `ovc21`/`ovc33` snapshot it the same way.  Named `MenuMode` (`2000:ca6f`) and
`MenuModeSaved` (`2000:ca70`); the live decompile of `6a8f:199c` reads
`MenuModeSaved = MenuMode;`.

Auto globals: 586 -> 584.

### `2410:07E2` - examined, write-only

It has 25 references and **all of them are stores** (values `0..0xf` written from
`ovc12_agnt` and `ovc49`, next to `agnt_3b1d_0a53`/`play_sfx` calls).  A full
search finds no reader anywhere in the export, so the value domain alone (sixteen
small ids) does not identify whether it is an action id, a sound id or a cursor
state.  It stays unnamed rather than guessed.

## Batch 46 - the difficulty setting

`2000:0769` is the new-game difficulty index.  The setup screen assigns it right
before the game initialiser runs:

```c
byte_2000_BSS_0769 = bStack_b;
byte_2000_BSS_076A = cStack_c;
ovr_init_3381_2101();
```

and every consumer treats it as one of four values (`== 1`, `== 2`, `2 < value`),
matching the four difficulty strings of the new-game menu - "Peaceful",
"Aggressive", "Hostile", "Custom".  It is also an index into the per-value
constant table at `2410:5DE4`, where the timer period is computed from it:

```c
uVar1 = 0x3c / (*(byte *)(Difficulty + 0x5de4));
```

Named `Difficulty` (`2000:d19d`); the live decompile of `619c:0000` reads
`*(char *)(Difficulty + 0x5de4)`.

Auto globals: 584 -> 583.

### Examined, not named

- `2000:076A` is written next to `Difficulty` (the second setup value) but has **no
  reader** anywhere in the export, so what it selects is not established.
- `2000:027B` (22 refs, 8 modules) is only ever set to 0/1 and tested `!= 0` as an
  early-out, with no computation on the value; a boolean flag whose subject the
  code never states.

## Batch 47 - the square's two screen edges

The init loop computes the pair one from the other, which settles both:

```c
((undefined2 *)&SquareLeftX)[GSMaxSquare]  = iStack_8 + uStack_14;
((undefined2 *)&SquareRightX)[GSMaxSquare] = SquareLeftX[GSMaxSquare] + uStack_4;
```

So `2000:0482` is the left screen x of a square and `2000:043A` its right edge;
the earlier single name (`SquareScreenX`) covered only the left table, and it is
now `SquareLeftX` (`2000:ceb6`) plus `SquareRightX` (`2000:ce6e`), verified in the
live decompile of `3381:17e8`.

Auto globals: 583 -> 582.

### Examined, not named

All three are 0/1 style gates whose subject the code never states, so the evidence
does not distinguish them from any other busy-flag:

- `2410:5CF0` (20 refs) is set to 1 around a nested UI call and cleared after, and
  consumers skip the redraw while it is set *and* the mouse has not moved
  (`5CF0 == 0 || MouseMoved != 0`).  It behaves like a screen lock, but the names
  would only restate that.
- `2410:5CEF` (15 refs) is a small id with `0xff` as "none", written by the
  construction modules and passed to one UI function; what the id denotes is not
  expressed anywhere.
- `2410:4926` (17 refs) is set to 1 in six modules and returned by a stats
  predicate - again a boolean whose subject is unnamed.

## Batch 48 - the square's two screen edges, vertical pair

The same init loop that produced the horizontal pair also produces the vertical
one from the shared `0x111` origin:

```c
iVar1   = 0x111 - uStack_12;                       /* y base */
SquareTopY[GSMaxSquare]    = iVar1 + uStack_12;
SquareBottomY[GSMaxSquare] = SquareTopY[GSMaxSquare] + uStack_6;
iStack_8 = 0x111 - uStack_14;                      /* x base */
SquareLeftX[GSMaxSquare]   = iStack_8 + uStack_14;
SquareRightX[GSMaxSquare]  = SquareLeftX[GSMaxSquare] + uStack_4;
```

`uStack_12`/`uStack_6` come from `local_1e[cStack_f + 1]` (the row extent) while
`uStack_14`/`uStack_4` come from `local_1e[cStack_f]` (the column extent), so the
first pair is y and the second x.  Named `SquareTopY` (`2000:cf8e`) and
`SquareBottomY` (`2000:cefe`), confirmed live in `3381:17e8`.

Auto globals: 582 -> 580.

### `agnt_t+0x23` = `timer`

The reset paths store 10 or 5 into it and the per-tick code decrements it:

```c
pcVar1 = (char *)(agent + 0x23);
*pcVar1 = *pcVar1 + -1;            /* ovc49, when flags & 0x64 */
```

Readers test it for zero, so it is a countdown `timer`.  `0x24` stays unnamed: it
is only compared with 0/1/2 and set on the same resets, with no computation on the
value.  Generated struct fields: 36 -> 35.

## Batch 49 - the side being initialised

`2000:08DC` enumerates the two sides of a new game.  Init clears it, and the setup
routine walks it up to two while spawning each side's starting units from the
per-difficulty tables:

```c
if (PlayerIndex < 2) {
    PlayerIndex = PlayerIndex + 1;
    if (PlayerIndex == 1) {
        cVar5 = *(char *)(Difficulty + 0x5dcb);   /* per-difficulty unit count */
        ...
```

and the consumers branch on `== 1` / `1 <` to treat the second side differently.
Named `PlayerIndex` (`2000:d310`); confirmed live in `619c:004e`.

Auto globals: 580 -> 579.

## Batch 50 - the cancel flag

`2410:4926` records that a screen was left through its cancel path.  The screens
set it when their input result is the `-2` sentinel, and the caller propagates it:

```c
if (cVar8 == -2) { Cancelled = 1; }                    /* ovc21 */
if (Cancelled != 0) return Cancelled;                  /* ovc33 */
Cancelled = 0;                                         /* before entering */
```

Named `Cancelled`, confirmed live in `6386:1c9f` and with `ListSyms` at
`2410:4926`.  Auto globals: 579 -> 578.

## Batch 51 - the agents-changed flag

`2000:06C1` marks that the agent set changed during a pass.  `ovc41` sets it at
the end of the per-agent block that may zero strength and mark the unit dead, and
`ovc49` consumes it once at the start of the next battle step:

```c
byte_2000_BSS_06C1 = 1;                                  /* after the block  */
if (byte_2000_BSS_06C1 != 0) {                           /* next step        */
    ovr_attact_3f0b_26bd();
    byte_2000_BSS_06C1 = 0;
}
```

Named `AgentsChanged` (`2000:d0f5`); confirmed with `ListSyms`.

Auto globals: 578 -> 577.

### `2410:5CF0` - examined again, still not named

The consumers are mouse hit tests.  They proceed only when the flag is clear **or**
the pointer moved:

```c
if (((5CF0 == 0) || (MouseMoved != 0)) || (MouseX outside the panel ...)) { ... }
```

The writer brackets a nested screen call (`5CF0 = 1; ...nested screen...; 5CF0 = 0`)
and the screens clear it while drawing.  That is consistent with "a child screen is
open", but the same conditions would hold for "the pointer is hidden", and nothing
in the code chooses between them, so it keeps its generated name.

## Batch 52 - the flood-fill grid and the game tick

`2000:08B4` is a far pointer (allocated with `stshAlloc`, segment in `DX`) to a
scratch grid whose size and stride are both in the code:

```c
_fmemset(FillGrid, ..., 0x6541);                     /* 0x101 * 0xA1 bytes */
*(byte *)((int)FillGrid + (param_1 + iVar7) * 0xa1 + param_2 + iVar8) = 1;
```

`0x6541 = 161 * 161` with stride `0xa1`, cleared then seeded and flooded with
neighbour checks during map generation, so it is `FillGrid` (`2000:d2e8`).

`2000:0733` is the game tick counter: it is incremented every pass, buildings store
it as a timestamp and delays are the difference:

```c
GameTick = GameTick + 1;                              /* ovc14 */
*(undefined2 *)(record * 0x12 + 0xf) = GameTick;      /* timestamp */
uVar8 = GameTick - *(int *)(record * 0x12 + 0xf);     /* elapsed */
```

so it is `GameTick` (`2000:d167`).  Both confirmed live (`55fe:0487`, `5d45:0000`)
and with `ListSyms`.

Auto globals: 577 -> 575.

### Examined, not named

- `agnt_t+0x2a`: three consumers disagree on the domain (`== 2` together with
  `BothFactions`, `8 < value`, and a `== 0` test) and none computes with it, so a
  count, a battle state and an index all remain possible.
- `char_sheet_t.pad_0`: the 40-byte block has exactly one consumer
  (`*(int *)(sheet->pad_0 + 0x1b) == agent->owner`), which identifies a dword at
  offset 0x1b inside it but not the block's role; splitting it would encode that
  one comparison as the whole field's meaning.

## Batch 53 - player count and the resumable entity scan

`2000:08B2` is the number of players, which the init code ties to the difficulty:

```c
if (2 < Difficulty) { byte_2000_BSS_08B2 = 2; }        /* custom = two players */
bVar2 = PlayerCount / 2 + 1;
if ((int)(uint)PlayerCount < iVar28) { ... }
```

Named `PlayerCount` (`2000:d2e6`).

`2410:55D6` is a scan position into the entity array that survives across calls:
a routine starts from it, stops when it has done its work, and stores the index
back so the next call continues:

```c
if (EntityCount <= EntityScanPos) { EntityScanPos = 0; ... }
for (uStack_16 = EntityScanPos; uStack_16 < EntityCount; uStack_16 = uStack_16 + 1)
    ...  EntityScanPos = uStack_16;
```

Named `EntityScanPos` (`2410:55d6`).  Both confirmed in the live decompile of
`5087:056e` and with `ListSyms`.

Auto globals: 575 -> 573.

### `2410:648E` - examined, not named

Six modules set it to 1 and `ovc34_unit` clears it while testing `!= 0`, i.e. a
one-shot "something changed" flag with the same shape as `AgentsChanged`, but the
setters do not say what changed and the consumer only calls an unnamed routine
before clearing it.

## Batch 54 - the small pending list

`2000:0992` is the entry count of a small word list (capped at five).  `ovc23`
appends to it and the other modules use the count as a loop bound and presence
test:

```c
if ((bldtp->unitType == 0x12) && (ListCount < 5)) {
    *(uint *)((uint)ListCount * 2 + base) = uVar6;
    ListCount = ListCount + 1;
}
for (bStack_8 = 0; bStack_8 < ListCount; bStack_8 = bStack_8 + 1) { ... }
```

What the appended entries denote is never stated, so the name says only what is
proven - it is the list's count.  `2000:d3c6`, confirmed live in `55fe:1005`.

Auto globals: 573 -> 572.

### Examined, not named

- `2000:0998` is incremented when a promotion event succeeds and is used as
  `0998 * 0x32 + 0x32`, i.e. an index into 50-byte records.  Whether it counts
  turns, seasons or promotions is not distinguishable from those two uses.
- `word_2000_BSS_06E0` caches the count returned by `attact_3f0b_0451` (entities
  near the cursor matching a menu value) and is used as `(count + 1) * param / 0x51`;
  the divisor `0x51` has no stated meaning, so the quantity is unnamed.
- `word_2000_BSS_03F2` holds per-square values that can be negative (the init
  loop counts down into it) and is used as the x operand of
  `constr_36ce_0101`, so it is an offset of some kind rather than a coordinate.
- `byte_2410_DATA_DGROUP_0728` is only ever the minuend of a coordinate
  (`0728 - offset`) like `ScreenOriginY`, but which origin is not stated.

## Evidence base regenerated (decompiled6)

The export used for the last several passes predated ~45 renames, so it was rebuilt:
`ExportAll` -> `tmp/decompiled6` (ok=1126 fail=4) and `ListAllVars` ->
`tmp/allvars8.csv`.  Re-running the parameter scans against it returned only cases that
are already handled; the remaining hits are CRT internals.

### `bldtp_t+0x0c` is a bound on the build duration, not equality-only

Accessed as `bldType * 0x27 + 0x11c`, the field is compared as an upper bound and then
copied into the building instance's duration byte as a fallback:

```c
if (bStack_3 < *(byte *)((uint)param_1 * 0x27 + 0x11c)) {
    *(undefined1 *)(GRecordCount * 0x12 + 6) = *(byte *)((uint)param_1 * 0x27 + 0x11c);
```

That is a real computing consumer, so the "equality only" description recorded earlier
was incomplete.  It still does not name the field: the value bounds the build duration
(which is the neighbouring `0x0f`), and nothing distinguishes "maximum duration" from
"default duration", so it stays generated with this evidence recorded.

## Batch - the audio driver blocks and the full-screen image

`stshLoadAudioDrivers` (4b0a:13d3) loads each sound driver file into its own pair of
words, so the pair is one far pointer and the file literal names it:

```c
cmidpakComOfs = stshStoreFile_2((far_t *)"cmidpak.com", ..., 1);
_cmidpakComSeg = in_DX;                 /* the segment half, stored on the next line */
ibmsndComOfs  = stshStoreFile_2((far_t *)"ibmsnd.com", ...);
ibmsndComSeg  = in_DX;
...
```

30 globals were named on that evidence:

| file | offset / segment names |
|---|---|
| `cmidpak.com` | `cmidpakComOfs` / `cmidpakComSeg` |
| `ibmsnd.com` | `ibmsndComOfs` / `ibmsndComSeg` |
| `sblaster.com` | `sblasterComOfs` / `sblasterComSeg` |
| `fibmbak.com` | `fibmbakComOfs` / `fibmbakComSeg` |
| `paudio.com` | `paudioComOfs` / `paudioComSeg` |
| `adlib.com` | `adlibComOfs` / `adlibComSeg` |
| `adlibg.com` | `adlibgComOfs` / `adlibgComSeg` |
| `sbfm.adv` | `sbfmAdvOfs` / `sbfmAdvSeg` |
| `sbp2fm.adv` | `sbp2fmAdvOfs` / `sbp2fmAdvSeg` |
| `sbp1fm.adv` | `sbp1fmAdvOfs` / `sbp1fmAdvSeg` |
| `pasfm.adv` | `pasfmAdvOfs` / `pasfmAdvSeg` |
| `pasopl.adv` | `pasoplAdvOfs` / `pasoplAdvSeg` |
| `adlib.adv` | `adlibAdvOfs` / `adlibAdvSeg` |
| `adlibg.adv` | `adlibgAdvOfs` / `adlibgAdvSeg` |
| `mt32mpu.adv` | `mt32mpuAdvOfs` / `mt32mpuAdvSeg` |
| (full screen cut) | `fullScreenGfxOfs` / `fullScreenGfxSeg` |

`fullScreenGfxOfs/Seg` (2000:0099/009B) is separate evidence: `init_assets2` cuts the
rectangle (0, 319, 199) - the whole 320x200 screen - and stores it there, and every later
use loads the pair into `gfx.ofs` / `gfx.seg` for a full-screen blit:

```c
word_2000_BSS_0099 = ovr_stshStoreFile_2((uint8_t *)pfVar2);   /* cut 0,319,199 */
word_2000_BSS_009B = puVar7;
...
gfx_00.ofs = fullScreenGfxOfs;  gfx_00.seg = fullScreenGfxSeg;
```

### Evidence checked and left alone

- `word_2000_BSS_06B0` / `_06B2` are assigned `sblasterComOfs` / `sblasterComSeg` in every
  loader, i.e. they alias the sblaster block.  A name would have to say *why* the same
  pointer is kept twice (selected driver? rollback copy?), and the export never
  distinguishes the two, so they stay generated.
- `word_2000_BSS_06A8`/`_06AA` receive a second copy of the `sbpro.com` block in the same
  function; same reasoning.
- `word_2000_BSS_069C`/`_069E`, `_0670`/`_0672`, `_0674`/`_0676`, `_06BC`/`_06BE` are all
  zeroed next to a driver block and never read in the export.

Auto-named globals: 572 -> 542.

## Batch - the asset name table unlocks 176 cut-graphics globals

`StshNames` (1ef4:0000) is a table of far pointers to the archive's file names, and **the
strings are plain ASCII in DGROUP**:

```
1ef4:0000  7C 2A 10 24  87 2A 10 24  93 2A 10 24 ...     /* far_t -> DGROUP strings */
2410:2A7C  "strong.dat\0bigcomp.lbm\0bighous1.lbm\0bighous2.lbm\0..."
```

Walking the table until the segment stops being `0x2410` yields **544 entries**:
`0 = strong.dat`, `1 = bigcomp.lbm`, `2 = bighous1.lbm`, `8 = gamfont1.lbm`,
`9 = mouse.lbm`, `10 = nwpanel2.lbm`, `11 = build\\rock01.lbm`, ...  That is the id space
of `grabLbm(file_id, x, y)` and `stshOpen(file_id)`, so an asset id can now be turned into
a real file name.

`init_assets2` (81b9:0086) cuts rectangles out of those images and stores each cut as a
block (offset, then the segment word):

```c
psVar1 = ovr_grabLbm(10,0,0);                       /* id 10 = nwpanel2.lbm */
pfVar2 = ovr_stshRleCut((far_t *)(&psVar1->aptr)->ofs, src_10, 57, 314, 113, ...);
nwpanel1Cut1Ofs = ovr_stshStoreFile_2((uint8_t *)pfVar2);
nwpanel1Cut1Seg = puVar7;
```

so each stored pair is named `<sourceFile>Cut<n>Ofs` / `<sourceFile>Cut<n>Seg`, where the
number is the n-th cut taken from that file in source order.  176 globals:

| source file | globals |
|---|---|
| `nwpanel1.lbm` | `nwpanel1Cut1..5Ofs/Seg` |
| `nwpanel2.lbm` | `nwpanel2Cut1..Ofs/Seg` |
| `talkwin9.lbm` | `talkwin9Cut1..Ofs/Seg` |
| `gamfont1.lbm`, `davfont.lbm`, `davfont2.lbm` | `...Cut1Ofs/Seg` |
| `anim\\tmstrs.lbm` | `anim_tmstrsCut1Ofs/Seg` |
| ... 20 further source files | the same pattern |

Live check:

```c
nwpanel1Cut1Ofs = ovr_stshStoreFile_2((uint8_t *)pfVar2);
gamfont1Cut1Ofs = ovr_stshStoreFile_2((uint8_t *)pfVar2);
talkwin9Cut1Ofs = ovr_stshStoreFile_2((uint8_t *)pfVar2);
```

Blocks that `stshAllocStub` allocates before the first `grabLbm` deliberately keep their
generated names: they are computed buffers, not cuts of a named file, so the table gives
no name for them.

Auto-named globals: 536 -> 360.

### Reusable consequence

Any code that indexes an asset by a number can now be read through this table: the id to
file name mapping is data, not inference.  `stshOpen(file_id)` reads
`*(u16 *)(file_id * 4)` as the name pointer, which is exactly `StshNames[file_id].ofs`.

## Batch - the transparency-remap cuts and the cached upper-case text

The first asset batch only followed `grabLbm(id)`, so the cuts made from a **transparency
remapped** load (`grabLbmTR(id)`) were missed.  Same table, same rule:

```c
psVar1 = ovr_grabLbmTR(10);                        /* id 10 = nwpanel2.lbm */
pfVar2 = ovr_stshRleType2(..., 7, 222, 150, -12, -7, ...);
nwpanel2Cut1Ofs = ovr_stshStoreFile_2((uint8_t *)pfVar2);
nwpanel2Cut1Seg = puVar7;
```

22 more globals:

| source | globals |
|---|---|
| `nwpanel2.lbm` (id 10) | `nwpanel2Cut1Ofs` / `Seg` |
| `triangls.lbm` | `trianglsCut1..6Ofs` / `Seg` |
| `panel01.lbm` | `panel01Cut1..3Ofs` / `Seg` |

### The cached upper-case text buffer

`OVC15_4207_1c16` upper-cases a string for display and keeps it in a persistent block:

```c
sVar2 = strlen((char *)text);
puVar3 = ovr_stshRealloc(_word_2410_1D05, sVar2 + 1);
_word_2410_1D05 = CONCAT22(in_DX, puVar3);
strcpy((char *)puVar3, in_DX);
uVar1 = toupper(*_word_2410_1D05);
```

and `freeLeaderData` / `draw_usesRingBuffer` free the pair as one handle, so it is
`upperTextOfs` / `upperTextSeg`.

Auto-named globals: 360 -> 338.

## Batch - a screen-sized temp block and the SFX start tick

| global | name | evidence |
|---|---|---|
| `word_2000_BSS_06C5` / `_06C7` | `tempScreenOfs` / `tempScreenSeg` | `stshAlloc_2(0xfa0f)` = 64000 pixels plus the 15-byte `stg_tmp_t` header, passed to `alignToSeg`, then used as a far gfx handle and freed |
| `word_2410_07AE` / `_07B0` | `sfxTickLo` / `sfxTickHi` | saved from `BDA_DailyTimeCounter` before an SFX is scheduled and compared with `SfxDeadline` |

```c
word_2000_BSS_06C5 = ovr_stshAlloc_2(0xfa0f);   /* 320*200 pixels + header */
word_2000_BSS_06C7 = in_DX;
ovr_alignToSeg(word_2000_BSS_06C5,ptr);
```

Auto-named globals: 338 -> 334.

## The `07xx`/`08xx` pointer tables in `5087:056e` - examined, refused

The function indexes twelve far-pointer tables by small values and blits each handle:

```c
gfx_06.seg = ((uint16_t *)&word_2000_BSS_07F0)[(unaff_DI % 7) * 2];
gfx_06.ofs = ((uint16_t *)&word_2000_BSS_07EE)[(unaff_DI % 7) * 2];
ovr_blitGfxRect(gfx_06, ...);
gfx_10.ofs = ((uint16_t *)&word_2000_BSS_07BA)[(unaff_DI % 5) * 2];
```

Each pair (`07EE`/`07F0`, `07CE`/`07D0`, `07BA`/`07BC`) is one interleaved array of `far_t`
handles, because the second name is the first + 2.  Two independent reasons stop a name:

1. **No writer exists in the export.**  Neither the arrays nor the single-word tables
   (`080C`, `0828`, `086C`, `01D5`/`01D7`, `0205`) are assigned anywhere in
   `tmp/decompiled20`; they must be filled through a pointer or in unexported code, so the
   contents cannot be characterised from the image.
2. **The index expressions are register artifacts.**  `unaff_DI` is an unmodelled register,
   and one index is literally `(uint)&unaff_DI->seg % 7`; the function carries
   *Unable to track spacebase fully* and *Control flow encountered bad instruction data*.
   Naming a table `unitFramePtrs7` from `unaff_DI % 7` would be reading the decompiler's
   confusion as if it were the program's structure.

The same refusal applies to the single-word handles (`0205`, `080C`, `0828`, `086C`): they
are loaded into `gfx.ofs`/`seg` and blitted, nothing more.

## Batch - the tick handler's periodic counters

`attact_usesUpdSeason` (3f0b:251d) is the per-tick handler: it bumps `GameTick`, then runs
three period counters and one 32-bit counter, all of which are also written to save games.
Each timer is named by the action it gates:

```c
byte_073B++; if (9 < byte_073B)  { byte_073B = 0; ovr_ovc25_textSpiesReportHeading(); }
byte_073A++; if (0xe < byte_073A){ byte_073A = 0; textDecreaseMessageDelay();
                                  GPromotableCount(); unit_alignUp4(); updSeason(); }
byte_0739++; if (4 < byte_0739)  { byte_0739 = 0; upd_usesAlignUp4(); }  /* the unit update */
bVar1 = 0xfffe < word_0735;  word_0735++;  word_0737 += bVar1;
```

| global | name | evidence |
|---|---|---|
| `byte_2000_BSS_073B` | `spyReportTimer` | resets at 10 and calls the spies-report builder |
| `byte_2000_BSS_073A` | `seasonTimer` | resets at 15 and runs the message-delay, promotion and season updates |
| `byte_2000_BSS_0739` | `unitUpdateTimer` | resets at 5 and calls `upd_usesAlignUp4`, the unit updater |
| `word_2000_BSS_0735` | `tickCountLo` | incremented with carry into 0737 every tick |
| `word_2000_BSS_0737` | `tickCountHi` | high half of the same counter |

The 32-bit width is not inferred from the carry alone: `stSave` writes it as one field of
size 4 from the address of `0735`:

```c
save_usesWrite(handle,(undefined2 *)&word_2000_BSS_0735,...,4u)
```

and `save_textLoading` reads the same four bytes back, which is why `0737` has no separate
save entry.

Auto-named globals: 334 -> 329.

## Batch - the two stronghold-destruction latches

`gameProcessKey` latches two debug keys into bytes, and `textStrongholdDestroyed` consumes
them per side:

```c
else if (key == 0x2200) byte_2410_DATA_DGROUP_0165 = 1;
else if (key == 0x2500) byte_2410_DATA_DGROUP_0164 = 1;

if (((byte_0164 == '\0') || (side == 0)) &&
    ((byte_0165 == '\0') || (side != 0))) goto skip;
byte_0164 = '\0';  byte_0165 = '\0';
```

so `0164` is required when the side argument is non-zero and `0165` when it is zero:
`destroyLatchSide1` and `destroyLatchSide0`.

Auto-named globals: 329 -> 327.

### Examined and refused in the same pass

- `byte_2000_BSS_027A` / `027B`: set to 1 next to the mouse-button thunks and cleared in
  `inputUpdate`, read by `uiReadKey2` and the region-definition loop.  Both buttons and both
  edges are plausible from that, so the names would encode a guess about which button.
- `byte_2000_BSS_06E2`: written `0xff`, `1` and `0` in five different places and tested
  `!= 0` / `== 1`; nothing states what the three states mean.

## Batch - the two cursor/flash tick snapshots

Two places stamp `BDA_DailyTimeCounter` into a word pair and then compare it on the next
call to decide whether enough ticks have passed:

```c
puVar1 = ovr_attact_usesBDADailyTimeCounter(word_2000_BSS_06CD, ...);
if ((in_DX == 0) && (puVar1 <= (byte *)__C0_ASM_CopyRight + 4)) { /* too soon */ }
else {
  word_2000_BSS_06CF = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
  word_2000_BSS_06CD = *(ulong **)BDA_DailyTimeCounter;
  FlashToggle = 1 - (FlashToggle != 0);
  ovr_vgaSetPalette(&stack0xffe2 + (uint)FlashToggle * 3, ...);
}
```

| global | name | evidence |
|---|---|---|
| `word_2000_BSS_06CD` / `_06CF` | `flashTickLo` / `flashTickHi` | the tick at which the palette flash was last started; gates the next one |
| `word_2000_BSS_06D2` / `_06D4` | `blitFrameTickLo` / `blitFrameTickHi` | the same snapshot taken beside the `BlitFrame` counter that resets at 6 |

Both are written low-word-then-high-word in that order, which is why the odd address is the
low half.  Auto-named globals: 327 -> 323.

### Examined and refused in the same pass

- `byte_2000_BSS_0046` (`main` sets it to 1) and `word_2000_BSS_0002`: each has exactly one
  write and **no reader anywhere** in the export, so nothing states what they gate.
- `2410:5DCF/5DD7/5DDF/5DE7` are written from stack bytes in `saveui` with one write each and
  no read; four adjacent unknown bytes with no consumer.
- `0x59AA`/`0x59B4` (copied into `reqLevel1[10]`/`reqLevel2[10]`) are rows of a packed level
  table, not strings: the bytes there are `05 0D 0E 0D 10 ...`, so naming them would mean
  naming a table whose column meaning is not stated.

## Batch - season, menu, redraw, party slot and six asset blocks (13)

### `seasonGroupBase` (2410:0744)

```c
uVar1 = ovr_randBelow(3);
srcSeg = (uVar1 & 0xff) * 3;
seasonGroupBase = (undefined1)srcSeg;        /* 0, 3 or 6 */
...
gfx.ofs = ((undefined2 *)&l1Cut1Ofs)[((uint)seasonGroupBase + (uint)GSeason) * 4];
iVar4   = iStack_e * 0xc + (uint)GSeason * 4;   /* 0xc / 4 = 3 seasons per group */
```

It is one of three 3-season groups in the `l1Cut1/l1Cut2/l1Cut3` art tables, it is saved to
the save game, and it is added to `GSeason` everywhere it is used.

### `savedMenuItem` (2000:003D)

Six screens store `GMenuItem` into it on exit and two restore `GMenuItem` from it on
re-entry (`GMenuItem = savedMenuItem`), so it is the menu selection kept across screens.

### `mapDirty` (2410:648E)

```c
if (mapDirty != '\0') {
  mapDirty = '\0';
  ovr_driver_scan4((short (*)[60][148])GMapFlags, 0, 0, 0x93, 0x3b, 0xfff7);
  for (uStack_c = 0; uStack_c < EntityCount; uStack_c++) { ... }
}
```

Ten state-changing screens set it to 1; this one place consumes and clears it by redrawing
the map and every entity.

### `goldPartyIndex` (2410:5CEF) and `selectedPartyIndex` (2410:74AC)

`5CEF` is loaded from the per-entity party-slot byte, tested against 0xff and passed to
`ovc28_textGold`, which indexes the 0x217A party table and formats that sheet's
`+0x56/+0x58` -- the gold value.  `74AC` is stored from the chosen entity's same byte and
compared against another entity's to find the member's entity.

### Six asset blocks

| globals | name | evidence |
|---|---|---|
| `2000:0A48/0A4A` | `demfont1FontOfs/Seg` | `grabLbm(411)` = `demfont1.lbm`, then `stshProcessFontSub`, then `stshWrite(pfVar2, puVar9, FontSize)` |
| `2000:0A50/0A52` | `sky06FliOfs/Seg` | `stshStoreFile_3(StshNames[0x19f])` and entry 415 is `sky06.fli` |
| `2000:0798/079A` | `specialColorsOfs/Seg` | `stshWrite((uint32_t *)SpecialColors, ..., 8)`, later `init_special_graphics(ofs, seg)` |
| `2410:07E3/07E5` | `audioSaveCut1Ofs/Seg` | `stshRleCut(NULL, src, 7, 222, 77)` inside `agnt_usesFmFreeAudio` |
| `2410:07E7/07E9` | `audioSaveCut2Ofs/Seg` | `stshRleCut(NULL, src_00, 78, 222, 150)` in the same call |
| `2410:00D8` | `bigcompFrame` | `gfx_00 = LbmBigcomp50x42[bigcompFrame]` and `draw_textTalkwin9L` bounds it with `6 < bigcompFrame` (7 frames) |

### Examined and refused in the same pass

| global | why refused |
|---|---|
| `2410:07E2` | fifteen writes of 0..15 and **no read** anywhere |
| `2410:5CF0`, `2410:5CE4`, `2000:0768` | toggled 0/1 by several UI screens; nothing states which condition the flag represents |
| `2000:06E0` | assigned from four different calls and used both as an `LXMUL` operand and as a comparison bound; its role differs per site |
| `2000:027A` / `027B` | set by bits 2 and 4 of `miceButton0PressStates`; the bit meanings (button vs edge) are not stated |
| `2410:5DF4`/`5DF6` | used as a screen centre in `textDivideError` and copied into `GfxRndSeed` in `run_demo` -- two incompatible roles |
| `2000:0998` | incremented on one condition and used as `*0x32 + 0x32` for a far pointer; the 50-byte table it indexes has no name |

Auto-named globals: 320 -> 307.

## Batch - level-range index and party filter

| global | name | evidence |
|---|---|---|
| `2410:4B6D` | `levelRangeIndex` | `LevelRangeMin[4B6D] <= entity.base.level <= LevelRangeMax[4B6D]`, with 0xfe special-cased before the range test |
| `2410:4B6E` | `partyFilter` | assigned from `manage_textAllUnits`' `partyIndex` parameter, 0xff for none, compared with the per-entity party byte |

```c
if (byte_2410_DATA_DGROUP_4B6D == 0xfe) goto L_...;
if ((byte)((undefined1 *)&LevelRangeMin)[levelRangeIndex] <= peVar3[entityIndex].base.level)
  if (peVar3[entityIndex].base.level <=
      (byte)((undefined1 *)&LevelRangeMax)[levelRangeIndex]) goto L_...;
```

Auto-named globals: 307 -> 305.

### Examined and refused in the same pass

- `2410:6A88`: a one-shot guard around the `stshAlloc_2(0x18)` block that
  `ovc38_textShighTxt` fills, saved to the save game.  It has one setter, one clearer at
  init, and only `== 0` tests -- a name could only restate `if (never done)`.

## Parameter batch - pure positional forwarders (7)

A function whose body is a single tail call passing every parameter in order has no room for
an argument-order mistake, so the callee's names transfer exactly.  Seven such forwarders
exist; four of them map onto already-named parameters:

| function | parameters | callee |
|---|---|---|
| `ovc28_compute2` | `entries`, `count`, `flags` | `ovc28_usesUiInputText` |
| `__brk` | `brkOfs`, `brkSeg` | `_brk_normalize` |
| `heapFreeSub` | `entry` | `heapValidate` |

A seventh comes from the body rather than a call:

```c
if (param_1 == 0xffff) return 0xffff;                 /* EOF
else if (((byte *)_ctype + 1)[param_1 & 0xff] & 4) return (param_1 & 0xff) + 0x20;
```

so `tolower`'s argument is the character code `c`.

Auto-named parameters: 778 -> 771.

## Batch - new-world prompts, a stronghold counter and the music-driver table (9)

### The four new-world counters (string-labelled)

`saveui_textWhichNewWorld` prompts for each count and stores it immediately after:

```c
iStack_a = saveui_usesBlitText((char *)"Low intelligence enemies:", ...);
iStack_8 = saveui_usesBlitText((char *)"Medium intelligence enemies:", ...);
iStack_6 = saveui_usesBlitText((char *)"High intelligence enemies:", ...);
iStack_4 = saveui_usesBlitText((char *)"Size of second wave:", ...);
if (0x3c < iStack_a + iStack_8 + iStack_6 + iStack_4)
    ovr_say("Too many enemies. 60 enemies maximum.");
lowIntelEnemies  = (undefined1)iStack_a;
medIntelEnemies  = (undefined1)iStack_8;
highIntelEnemies = (undefined1)iStack_6;
secondWaveSize   = (undefined1)iStack_4;
```

All four are save-game fields, and the 60 total is the dialog's own limit.

### `worldIndex`

```c
uiMenu((char *)"Which new world:", items, ...);
bStack_b = (byte)puVar1;
...
cStack_c = bStack_b - 1;          /* 0-based world */
uiMenu((char *)"Hostility level:", items_00, ...);
Difficulty = bStack_b;            /* the hostility result */
worldIndex = cStack_c;
```

so the earlier "zeroed next to a driver block and never read" note was about a different
byte, and this one is the menu selection.

### `strongholdsDestroyed` (2410:6A86)

```c
if (bStack_7 == 0) ovr_play_sfx(68,0);
else { ovr_play_sfx(44,0); strongholdsDestroyed = strongholdsDestroyed + 1; }
```

and `ovc38_scan1` compares it with a value parsed from a decimal string.  It is saved.

### `audioBusy` (2410:2A4E)

Set immediately before and cleared immediately after an audio handle operation, and consulted
by the audio error paths:

```c
byte_2410_DATA_DGROUP_2A4E = 1;
if (DIGHandle.ofs != 0 || DIGHandle.seg != 0) ovr_stshFree(DIGHandle);
... byte_2410_DATA_DGROUP_2A4E = 0;
```

`fmOutOfMemory` / `fmMallocRecover` take the normal path only when it is 0, and `textError` /
`textView` branch on it.  It is transient (always cleared), so it is a busy flag rather than a
sticky error.

### The music-driver table

`musInit` turns the configured music device into an index and reads a far pointer out of a
4-byte-stride table based at 0x0668:

```c
if (('1' <= CFG_Mus) && (CFG_Mus <= '9')) unaff_SI = CFG_Mus - '1';
else if (('@' < CFG_Mus) && (CFG_Mus < 'G')) unaff_SI = CFG_Mus - 0x38;
if (((undefined2 *)&word_2000_BSS_0668)[unaff_SI * 2] != 0 ||
    ((undefined2 *)&word_2000_BSS_066A)[unaff_SI * 2] != 0) {
  handle.ofs = ((undefined2 *)&word_2000_BSS_0668)[unaff_SI * 2];
  handle.seg = ((undefined2 *)&word_2000_BSS_066A)[unaff_SI * 2];
  MusGfxOfs = ovr_stshLoadGfx(handle);
```

so `0668`/`066A` are the offset and segment of table entry 0 (the `* 2` on a word pointer is
the 4-byte stride).  Named `musDriver0Ofs` / `musDriver0Seg` rather than `musDrivers`, because
the symbol covers one entry and the array length (index range from the device letters) is not
stated anywhere.

Auto-named globals: 305 -> 296.

### Examined and refused in the same pass

| global | why refused |
|---|---|
| `2000:0067` | toggled (`1 - (x != 0)`) and copied into `GOngoingBattle`; the two are kept in sync by explicit copies, so a distinct name would have to invent why both exist |
| `2410:4757` | set 1 before `save_textSsave()` in `main`, cleared right after, and checked as `== 0` before printing "Load Error"; with three sites the polarity cannot be settled |
| `2000:072F` / `0731` | reset in `attact_usesAlignUp42`, incremented in `ovc26_usesStExit`, and never read |
| `2000:06A4`, `06A6`, `069C`, `069E` | written next to the audio driver pairs and never read |
| `2410:0161`, `5CE4`, `5CF0` | toggled by several screens with no stated condition |

## Globals pass - the string-adjacent scan is now exhausted

Re-running the string-adjacent store scan over `tmp/decompiled32` returns only the globals
already named or already refused: the new-world dialog was the only place where a prompt's
own text labels the store, and those five are done.  A tighter scan for assignments whose
**right-hand side** contains a prompt literal returns nothing, because the dialogs all stage
their result through a stack local first.

Refusals re-confirmed with their sites:

| global | evidence |
|---|---|
| `2000:0067` | toggled and copied into `GOngoingBattle`; the two are kept in sync explicitly |
| `2410:4757` | set 1 before `save_textSsave()` and 0 right after, checked as `== 0` before printing "Load Error" -- three sites, polarity unresolved |
| `2000:072F` / `0731` | reset each turn, incremented, never read |
| `2000:06A4` / `06A6` / `069C` / `069E` | written beside the audio driver pairs, never read |

## Correction - `levelRangeIndex` is really `unitTypeFilter`

The global at 2410:4B6D was named last pass from the fact that it indexes `LevelRangeMin` and
`LevelRangeMax`.  Reading the screen that sets it shows what the value *is*:

```c
unitTypeFilter = (undefined1)unitType;    /* manage_textAllUnitsDisplayed, 0xfe = all types */
partyFilter    = partyIndex;              /* 0xff = all parties */
...
byte_2410_DATA_DGROUP_4B6D = 0xff;        /* clear after the redraw */
byte_2410_DATA_DGROUP_4B6E = 0xff;
```

and the level-range lookup is a consequence (`ovc13_usesEntities` bounds the displayed entities'
levels with `LevelRangeMin[type]`/`LevelRangeMax[type]`).  Renamed to `unitTypeFilter` with the
old name recorded here so earlier notes stay traceable.

## Batch - 17 DGROUP data tables named through `F_SCOPY`'s corrected signature (17 new globals)

Now that `F_SCOPY` reads as `(srcOfs, srcSeg, dst)`, every call site names a data table that the
code copies into a local.  The 29 sites with a literal source were enumerated, each source was
checked for an existing symbol (`SymAt.java`: all 29 were **completely unnamed**, not merely
auto-named), and the bytes were dumped (`DumpData.java`) so the name could follow the contents:

| address | name | destination | dumped contents |
|---|---|---|---|
| `2410:04F2` | `edgeMaskTable` | `edgeMasks` | `03 06 00 01 05 03 01 00` -- edge bit masks |
| `2410:0502` | `neighbourOfsTable` | `neighbourOfs` | `00 01 01 02 02 03 03 00` -- neighbour offsets |
| `2410:0745` | `shadeTable` | `shades` | `10 0C 06 04 02 01 1F 1C 19 16 10 0C` -- descending shade steps |
| `2410:49DD` | `classStatTable1` | `classStatMap1` | `00 01 02 03 00 00 00 FF FF FF` |
| `2410:49E4` | `classStatTable2` | `classStatMap2` | `FF FF FF FF FF 01 03 ...` |
| `2410:594A` | `ditherPlane0` | `plane0` (`int[16]`) | `0,0,4,12,13,13,13,13,12,4,...` |
| `2410:596A` | `ditherPlane1` | `plane1` | `13,13,13,13,12,4,4,12,...` |
| `2410:598A` | `ditherPlane2` | `plane2` | `12,4,0,...,4,12,13,13,13,13` |
| `2410:59AA` | `reqLevelRow1` | `reqLevel1[10]` | `00 01 03 05 07 09 0B 0F 12 15` (strictly increasing) |
| `2410:59B4` | `reqLevelRow2` | `reqLevel2` | `00 02 04 06 08 0A 0C 11 11 11` |
| `2410:6E00` | `xOfsTable` | `xOfs` | words `0x36 0x27 0x1D 0x10`, then `01 02 03 03` |
| `2410:6E48` | `growthTable` | `local_30` | `5,10,20,35,75,175,275,450,650,900,1000,1100` |
| `2410:7145` | `unitTypeTable` | `local_1c` | `07 28 25 34 35 01 02 03 2E 2F 30 1C 1F 71`; its entries are stored into `GUnitGrid[x][y]` |
| `2410:1D09` | `sfxXOffsets` | `&stack0xfff2` | words `33,81,129,177` |
| `2410:26AD` | `promptRect` | `&rect` | `{22,29,222,39,0xA000}` -- exactly the prompt row, since the caller sets `TextBlitX = 0x16` and `TextBlitY = row*0xf + 0x1d` |
| `2410:6B86` | `fullWidthRect` | `&rect` | `{0,0,319,143,0xA000}` |
| `2410:715B` | `lowerScreenRect` | `&dst` | `{0,152,319,199,0xA000}` -- the bottom 48 rows, full width |

The rectangles also settle what a `brect_t` holds: `left, top, right, bottom, seg` (not width and
height), because `{22,29,222,39}` only makes sense as a 200x10 text row and `{0,0,319,143}` as the
full width.  The decompiled call sites now read
`F_SCOPY((uint8_t *)&shadeTable, 0x2410, shades)` instead of `F_SCOPY((uint8_t *)0x745, ...)`.

Because these addresses had **no symbol at all**, they were not part of the 2533 counted globals;
naming them raises the total to 2550 (auto-named stays 296, so 11.6%).

### Examined and refused in the same pass (the rest of the 29 sources)

| source | dumped / obstacle |
|---|---|
| `2410:04E8` | `16,12,6,4,2,1,1,1,1,1` copied into a 10-byte local that is multiplied by screen dimensions and divided by `0x30`; the divisors say "fractions of 48" but not what is being scaled |
| `2410:074F` | only 2 bytes (`16,12`) reach `local_c[2]`; two values cannot name a table |
| `2410:07EC`, `2410:842C` | both `{12,7,222,150}`; naming them "panel" would be an inference about the UI, and they are byte-identical so a distinguishing name is not available |
| `2410:493B` | `{12,99,222,150}` -- same size, different y |
| `2410:088D`, `2410:0897`, `2410:0858` | small rects `{223,159,226,196}`, `{208,157,226,196}`, `{211,175,223,178}`; their roles are battle-UI markers whose names are not stated |
| `2410:0846` | not a rect at all: `3F 00 00 3F 3F 3F 20 20 20 3F 3F 3F`, a `'?'`/space pattern |
| `2410:26E3` | `100,200,300,400` into a 20-byte local; the values alone do not say what is being counted |
| `2410:4B66` | the destination is `acStack_e + 4`, i.e. the middle of a stack buffer, so the copy offset is part of the structure |
| `2410:7153` | `0,1,2,3,5,8,10,11` copied into an 8-byte local passed as one argument to `ovc15_usesLDIV_at_` |

New tool this pass: `scripts/ghidra/LabelData.java` creates a label at a data address (and sets an
EOL comment), because `Rename.java` intentionally only renames an existing symbol and reported
`missing=16` for these.

## Batch - the remaining `F_SCOPY` sources, part 2 (9 globals)

Each of the thirteen remaining sources was read against the *consumer* of its destination local,
not just its bytes.  Nine resolved; four are refused below with the reason.

| address | name | evidence |
|---|---|---|
| `2410:7153` | `spawnGindexTable` | copied into `local_e[8]`, indexed by `ovr_randBelow(8)`, and the entry is passed as `ovc15_usesLDIV_at_`'s **`gindex`** argument (which assigns `entity.base.gindex`) |
| `2410:04E8` | `scaleTable` | copied into `local_1e[10]`; every use is `entry * <screen dimension> / 0x30` (or `/0x10`) added to a base byte at `+0x728/+0x729/+0x74b/+0x74c` |
| `2410:0846` | `flashPaletteEf` | **not a rect**: `3F 00 00 3F 3F 3F 20 20 20 3F 3F 3F` is four 3-byte colours, loaded at DAC index `0xef` as `&stack0xffe2 + FlashToggle*3` |
| `2410:0858` | `mouseSaveRect1` | `{211,175,223,178}`; `ovr_miceRestoreArea` / `ovr_miceBlitRect` in `ovc13_usesMiceBlitRect` |
| `2410:0897` | `mouseSaveRect2` | `{208,157,226,196}`; the same pair in `attact_usesLDIV_at_2` |
| `2410:088D` | `mouseSaveRect3` | `{223,159,226,196}`; the same pair in the same function |
| `2410:07EC` | `mouseSaveRect4` | `{12,7,222,150}`; `ovr_miceBlitRect` in `agnt_usesAlignToSeg` |
| `2410:842C` | `agentClipRect` | `{12,7,222,150}`; it is the `dst` rectangle of *every* `ovr_blitGfxRect` in `ovc49_usesBlitGfxRect` |
| `2410:493B` | `panelClipRect` | `{12,99,222,150}`; the `dst` of `ovr_blitGfxRect(gfx,0,0,...)` in `manage_usesBlitGfxRect2` |

`2410:0846` is the interesting one: it was on my rejected list as "a `'?'`/space pattern" because
the bytes looked like text.  Reading the consumer showed it is a palette loaded three bytes at a
time at DAC index `0xef`, which is why the pattern is `3F 00 00 / 3F 3F 3F / 20 20 20 / 3F 3F 3F`.
Note that `2410:07EC` and `2410:842C` are byte-identical rectangles with **different roles**
(mouse save area vs. sprite clip), so the duplicate bytes are not a duplicated constant.

### Deliberately still refused

| source | reason |
|---|---|
| `2410:074F` | only two bytes (`16,12`) reach `local_c[2]`; two values cannot name a table |
| `2410:26E3` | `100,200,300,400` are copied into `saveui_textWhichNewWorld`'s `local_20[20]`, which is **never read** again in that function |
| `2410:4B66` | the destination is `acStack_e + 4`, the middle of a stack buffer, so the copy is a partial overwrite whose structure is not visible |

Globals: 2550 -> 2559 named (auto-named still 296, 11.6%).

## Seven locals named from their now-named source tables

With the tables above labelled, the locals that receive them are the working copies:

| local | name | source |
|---|---|---|
| `6a8f:29ea local_30[22]` | `growthMap` | `&growthTable` |
| `4d05:03a4 local_3a[28]` | `titlesMap` | `GPlayerTitles + 0x12` (an already-named global table) |
| `6d7a:04f2 local_1c[14]` | `unitTypeMap` | `&unitTypeTable` |
| `6d7a:04f2 local_e[8]` | `spawnGindexMap` | `&spawnGindexTable` |
| `3381:17e8 local_1e[10]` | `scaleMap` | `&scaleTable` |
| `474a:0953 local_d0` | `buf` | the single output buffer of `vsprintf` |
| `36ce:04e9 local_c[2]` | `cellNext` | `constr_usesSmoothPrev(i+1, -1, ...)` beside `cell` from `(i, -1)` |

Locals: 133 -> 126.

## Batch - the sprite arrays, named from the asset table (68 globals)

The project's `StshNames` dump (`tmp/asset_lookup.py` over `1ef4:0000`, 544 far pointers) resolves
`grabLbm(n)` ids to filenames, and that is what unblocked this region:

| asset id | file |
|---|---|
| 12 | `star.lbm` |
| 35 | `bolt.lbm` |
| 93, 94, 95, 96 | `csite1.lbm` .. `csite4.lbm` |
| 531, 532, 533, 534 | `csite5.lbm` .. `csite8.lbm` |
| 535 | `anim\tmstrs.lbm` |

With the ids resolved, `init_assets2`'s loops become readable, and the arrays are **contiguous**:
the arithmetic closes exactly at every boundary, which is what proves the base and the length of
each one (it also proves that the `0199`, `01B1`, `0119`, `013D`, `0161` symbols are *not* bases
but interior addresses of the preceding array):

```
00F5 csite5   9 entries -> 0119
0119 csite6   9 entries -> 013D
013D csite7   9 entries -> 0161
0161 csite8   5 entries -> 0175
0175 csite2   9 entries -> 0199
0199 csite3   6 entries -> 01B1
01B1 csite4   9 entries -> 01D5
01D5 csite1  23 entries -> 0231
0231 star     4 entries -> 0241
07BA tmstrs1  5 entries -> 07CE
07CE tmstrs2  7        07EE   tmstrs3  7       080A tmstrs4  7
0826 tmstrs5  7        0842   tmstrs6  7       085E tmstrs7  3
086A tmstrs8  7        0886   tmstrs9  7
```

Each array is a packed array of far pointers (ofs at `base + 4k`, seg at `base + 4k + 2`), and the
consumers index it from zero -- `((undefined2 *)&csite1Ofs)[(i + 0xc) * 2]` for csite1's 23
entries, `(&tmstrsSprites1Ofs)[(x % 5) * 2]` for the 5-entry tmstrs animation.  Symbols:
`<asset>Ofs`/`<asset>Seg` for the base, `<asset>_<k>Ofs`/`_<k>Seg` for the interior block whose
far-pointer index is `k = (address - base) / 4`.  Two further tables came from the same reasoning:
`crossBlitType2Ofs/Seg` (2410:0231, four entries cut from `star.lbm` in the same loop as
`CrossBlitGfx`, with `stshRleType2` instead of `stshRleCut`) and `boltSpritesOfs/Seg`
(2410:08B8, four entries from `bolt.lbm`).

### A correction to the earlier frame-table note

The first pass reported frame counts of 23/24/32 for these tables.  Those were the bounds of the
**`else` (no-assets) branch** loops, which allocate the whole array in one go; the `if (grab)`
branch fills the same array in blocks of 3-6, which is why Ghidra created a separate word symbol
at every block boundary.  The real lengths are the ones in the layout above, and they are
confirmed by the boundary arithmetic rather than by any single loop bound.

Auto-named globals: 296 -> 228.

## Batch - the last entry of three arrays, and two contradictions that stop the method

Extending the array naming to *every* auto symbol that falls inside a known array (computed from
`k = (dgroupOffset - base) / 4` and `dgroupOffset % 4`) produced nine candidates.  Six are real and
are now named; three are contradictions, and they are the important part of this pass.

| address | name | why |
|---|---|---|
| `2000:cbe1/cbe3` | `csite3_5Ofs`/`Seg` | csite3 is 3+3 entries from `0199`, so entry 5 is `0199+20 = 01AD` |
| `2000:cc05/cc07` | `csite4_8Ofs`/`Seg` | csite4 is 3+3+3 from `01B1`, entry 8 = `01B1+32 = 01D1` |
| `2000:cc61/cc63` | `csite1_22Ofs`/`Seg` | csite1 is 6+6+6+5 from `01D5`, entry 22 = `01D5+88 = 022D` |

All three are additionally read as a *single* far pointer (a fallback sprite) in
`ovc23_usesBlitGfxRect` / `ovc22_textRingProt`, which is consistent with being one entry of the
array rather than a separate variable.

### Retraction - the two "contradictions" were a category error

The previous pass reported that `2410:0161` and `2410:07E2` refuted the csite8 base and the
`tmstrsSprites2` length, because both offsets are occupied by byte variables.  That reasoning was
wrong: the sprite arrays live in the **BSS segment (2000)** while those byte flags live in the
**DATA segment (2410)**.  Identical offsets in two different segments of a group are different
memory, and the symbols are distinct:

```
2000:cb95  csite8Ofs            (the array's offset word)
2410:0161  byte_2410_DATA_DGROUP_0161   (the flag)
2000:ce02  NOSYM               (no BSS symbol at this offset at all)
2410:07e2  byte_2410_DATA_DGROUP_07E2   (the state code)
```

So no name from the previous batch is invalidated: `csite8Ofs` stands, and the `tmstrsSpritesN`
lengths stand as loop-bound readings (hypotheses, but no longer refuted).  The recorded lesson is
the one that actually applies: **compare segments before comparing offsets.**

Auto-named globals: 228 -> 222.
