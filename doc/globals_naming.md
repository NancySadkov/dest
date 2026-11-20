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

## The BSS/DGROUP cell route: 10 globals named from writers already read

Rather than starting from the global list, this pass started from functions whose bodies had already
been read and asked which unattributed global each one writes.  Ten answered:

| address | name | evidence |
|---|---|---|
| `2000:d178` | `menuCursorX` | `draw_menuCursor` clamps it to 0..0x38 and stores it back at
`[GMenuItem]`; every reader adds 0xed..0x1c to make a screen x (`CrossBlitX = value + 0xed`,
3f0b:2252 uses `value - 0x1c`) |
| `2000:d17d` | `menuCursorY` | clamped to 0..0x1c; `CrossBlitY = value + 0x36` and 3f0b:2252
computes `(0x1c - value) * 100 / 0x1c` |
| `2000:d11b` | `blitFrameOfs` | `ovc13_blitAnimFrame` reads `((word *)&blitFrameOfs)[BlitFrame*2]`
as the offset of frame `BlitFrame` (0..5) |
| `2000:d11d` | `blitFrameSeg` | the segment half, same index |
| `2000:d1ae` | `trianglesShown` | cleared while the leader view is shown, set by
`ovc18_blitTriangles`, and tested against the `MouseX 10..0x16` / `MouseY >= 0x9e` hit region |
| `2000:ca6d` | `crossAgentIndex` | `CrossBlitX = value * 0x34 + 0x26` and the y comes from
`*(value * 0x34 + 0x1a)` |
| `2000:ccaf` | `rightButtonLatch` | `init2_updateMouseButtons` latches bit 1 of
`miceButton0PressStates` here |
| `2000:ccae` | `middleButtonLatch` | the same function latches bit 2 here |
| `2410:4757` | `suppressLoadError` | main sets it to 1 around the startup `save_loadGameFile()` and
back to 0; `stLoad` prints `"Load Error"` only when it is 0 |
| `2410:0161` | `timePassing` | set to 1 immediately before `"Time passes..."` is drawn, cleared by
the turn tick, tested by the draw state machine |

## Why the rest of the globals axis is now quantified, not just called "blocked"

For every one of the remaining auto-named globals, its name was searched across the whole decompiled
export (`tmp/global_refs.py`):

```
remaining auto globals: 214
  referenced 0 times: 151
  referenced 1 time : 16
  referenced 2 times: 5
  referenced 3+     : 42
```

**151 of 214 are never referenced by any recovered function** -- they are dead labels in BSS/DGROUP
whose only possible source of meaning would be code that was not recovered.  Of the 63 that are
referenced, the families checked this pass are write-only temporaries (`2000:d0a2..d0aa`,
`d0d0..d0e6`, `d163/d165`), which cannot be named from a store alone.

Globals: 222 -> 212.

## Second BSS/DGROUP pass: 15 more globals (222 -> 197)

Continuing the route of reading the store/read site of each still-referenced auto global:

| address | name | evidence |
|---|---|---|
| `2272:003a` / `2272:003c` | `vdiskBaseOfs` / `vdiskBaseHi` | the Int19 handler installs the fake
vdisk: `baseLo`/`baseHi` are stored here (1403:107a) |
| `2272:002c` / `2272:002e` | `vdiskEndOfs` / `vdiskEndHi` | the same handler stores `base+size`
(with `CARRY2`) here |
| `2000:d133` / `2000:d135` | `timeOfDayGfxOfs` / `timeOfDayGfxSeg` | `attact_usesBlitLoadRleGfx`
derives an index from `GTimeLo` (`(GTimeLo-0xf)/0xf`) and blits the pair to `0xa000:c510` |
| `2410:49f7` | `menuHighlightTable` | the byte at `0x49f7+0x0b+6*i` is passed as the `structType`
argument of `manage_highlightStructures` |
| `2410:4a0b` | `classLimitTable` | `F_SCOPY(&classLimitTable, ..., classLimits)` in
`manage_rollHitPoints` -- it is the source of the per-class random limits |
| `17f8:0000` / `17f8:0013` | `game4State` / `game4InitState` |
`fmemmove(&game4State, &game4InitState, 0x1631)` restores the scenario block from its pristine copy |
| `2000:d0fd` | `constructionDirty` | cleared each frame, set when a unit is placed, and tested to
repaint the construction overlay via `constr_usesBlitRect` |
| `2410:6ac4` | `msgFormat` | used as the `stsprintf` format argument in the three message emitters |
| `2410:69c2` / `69c5` / `69c8` | `paletteColorA/B/C` | copied into `colorA/B/C` and written into the
palette at offsets 0x2ac / 0x2b2 / 0x2be |

Reference census after this pass: of the 197 remaining auto globals, **151 are still never referenced
by any recovered function**.  The referenced remainder is 46, mostly the write-only pointer-pair
temporaries (`d0a2..d0aa`, `d0d0..d0e6`, `d163/d165`, `5dee/5df2`) whose stores carry no vocabulary
and whose readers live in the unrecovered overlays.

Globals: 222 -> 197 (7.7% auto-named).

## Third BSS/DGROUP pass: 4 more globals (197 -> 193)

| address | name | evidence |
|---|---|---|
| `2410:07e2` | `animBranchCode` | set to a distinct code (3, 4, 5, 6) on each branch of the agent
animation state machine immediately before `agnt_usesAnimFrame`, cleared to 0 by both reset paths |
| `2000:d2d6` | `cursorRecordFound` | set when the 0x12-stride map-record scan finds a record
covering the cursor; the caller returns early with `CurSfxType3 = 0x70`, and `agnt_isAnimating`
counts it as activity |
| `2000:d2e2` | `strongholdCheckPending` | cleared during setup, set by the map update; the draw
state machine calls `ovc24_checkStrongholds` only when it is non-zero |
| `2410:02f4` | `messageDelayTicks` | saved as a single byte between `unitUpdateTimer` and `GameTick`,
and used as `value << 4` timer ticks while the victory screen waits |

Refused this pass, with reasons: the audio driver pointer block `2000:066e..06be` (four functions
assign it from `stshStoreFile_2("*.com"/"*.adv")` results, but *no reader exists* in the export, so
the per-entry meaning is in the unrecovered driver loader); `2000:ccb0` (indexed as a byte table and
also used as a length bound, so its meaning is the structure that follows it); and
`2000:ca9b` (assigned into `GOngoingBattle` and toggled, i.e. a battle-state mirror whose semantics
are the caller's, not its own).

Globals: 197 -> 193 (7.5%).

## Fourth pass: `2000:06e2` = `mapViewActive` (193 -> 192)

`attact_usesBlitLoadRleGfx` sets it to 1 when it draws the map, the full-screen panels set it to
0xff and initialisation clears it.  The frame advance in `ovc13_usesMiceBlitRect` runs only when it
equals 1, together with `GPaused == 0` and `DGROUP_0845 == 0` -- i.e. the map view owns the screen.

Refused this pass: `2410:6a88` (saved byte with a single writer that stores 0, read as a gate on the
defeat test -- no vocabulary), `2000:0768` (cleared at the start of a saveui message and tested in
the new-world dialog), `2410:5ce4` (selects the wide-menu cursor path for items >= 0x7f, but the
layout it selects is not described anywhere), and `2410:0728` (used as a blit y origin).

## Fifth pass: 2 more globals (192 -> 190)

| address | name | evidence |
|---|---|---|
| `2410:5cf0` | `keyboardInputMode` | set to 1 immediately before `uiInputText` and cleared by every
menu handler; read as `value == 0 || MouseMoved != 0` to choose the keyboard path (the 0x24 scan code) |
| `2410:5ce4` | `menuBarShown` | when set, menu items with id ≥ 0x7f are laid out horizontally
(`x = (id-0xfc)*0x44+10`, `y = 0xb0`) instead of the vertical list; cleared with the menu |

### `2410:26f7` is the AgntGs array, and why it is still unconverted

This label is the **only** access path to the agent-type records in the export (126 references): the
code reads `(int)&data_[6].seg + 1 + g*0x95`, `(int)&data_[9].ofs + 1 + g*0x95`, etc. -- the 0x95
stride and the field usage (`gdata->flags`, `gdata->name`, `gdata->stdint_h_uint8_t`) are exactly the
`AgntGs` record, which is labelled at `195d:26d6`.

Naming this blob `AgntGs` would create **two symbols with the same name at different addresses**
(2410:26f7 here, 195d:26d6 there), which is worse for the export than a documented alias.  The
correct fix is to establish which segment mapping the code really uses for the table -- that is a
listing-level decision, not a rename.  Recorded as a refusal with the evidence above.

Globals: 192 -> 190 (7.4%).

## Structural audit: how many remaining globals are really struct fields?

Asked to check whether any of the remaining auto globals are members of larger structures rather
than standalone variables, two scripts were written:

* `scripts/ghidra/SymTypes.java` dumps every label with its data type and length (11795 symbols);
* `tmp/inside_struct.py` tests strict containment of each auto global in another labelled span;
* `tmp/adjacent_runs.py` / `tmp/run_status.py` group the auto globals by segment into contiguous
runs separated by at most 4 bytes.

**Strict containment inside a labelled span: 0.**  Ghidra does not allow two defined data items to
overlap, so no auto global sits inside an existing typed table.

**Contiguous runs: 134 of the 190 remaining auto globals (71%)**, spread over 27 runs.  Only 26 of
those 134 are referenced anywhere in the export; 108 are unreferenced table members:

| run | span | members | referenced | reading |
|---|---|---|---|---|
| `1000:131c-1348` | 46 | 23 | 0 | a 23-word CRT data table, unreferenced |
| `5087:0bd6-0bfe` | 42 | 21 | 0 | a 21-word OVC22 data table, unreferenced |
| `21f2:0000-0011` | 19 | 12 | 0 | **one GRecords record** (stride 0x12): `+0` timer, `+2` x0,
`+4` y, `+7` width, `+9` party, `+0xb` countdown, `+0xd` kind, `+0xe` done, `+0xf` tick |
| `2ca1:0000-0004` | 6 | 3 | 0 | **one `boinit_t` record**: `InitEnd` at `2ca1:001e` is exactly
5 x 6 bytes after `2ca1:0000`, so the array really is `boinit_t[5]` starting at 0000, not `[4]`
at 0006 |
| `2410:5dee-5df6` | 10 | 4 | 4 | **the LEVELBAND far pointers**: `5dec`/`5dee` and `5df0`/`5df2`
are (ofs, seg) pairs, `5df4`/`5df6` a third pair |
| `2000:d0a2-..-d0f2` | 10+8+6 | 14 | 14 | the audio-driver pointer block (writers only) |
| `2000:d15f-165` | 8 | 4 | 2 | a four-word BSS pair block |
| `3f0b:1abb-1ac3`, `3f0b:21da-21e4` | 10, 12 | 5, 6 | 0 | two overlay data tables |
| `4b0a:0b6b-b73`, `4d05:33bb-33bf`, `4d05:342f-3435` | 10, 6, 8 | 5, 3, 4 | 0 | overlay tables |
| `6018:16b9-16c5`, `6616:14b4/14b6`, `6616:14c8/14ca`, `21b1:0000/0002` | - | 6, 2, 2, 2 | 0 |
overlay tables |

### What was fixed from this

`2410:5dee` and `2410:5df2` are the **segment halves** of the `LevelBandMin`/`LevelBandMax` far
pointers, proven by `ovc30_usesRandBelow`:

```c
uStack_4 = word_5DEE;  bandMin = LevelBandMin;    /* 2410:5dec:5dee  */
uStack_8 = word_5DF2;  bandMax = LevelBandMax;    /* 2410:5df0:5df2  */
```

They are now `levelBandMinSeg` and `levelBandMaxSeg`; the pairs are 6 far pointers total with
`5df4`/`5df6` still unnamed (no reader).

### What cannot be fixed by naming

The 108 unreferenced members (and the 26 referenced but role-less ones) are **fields of tables whose
element type is not stated anywhere in the export**.  The correct fix is to type the regions as
arrays, which needs each table's element layout; naming the members individually would invent a
vocabulary.  The `boinit_t` case is fully proven (5 x 6 bytes) and is the one retype worth doing, but
it is a data-layout change rather than a rename.

Globals: 190 -> 188.

## `2410:26f7` resolved at runtime: `worldMenuLabels` (175 globals)

The emulator settled the global that had been refused as an "AgntGs alias": its thirteen far
pointers decode to `Peaceful`, `Aggressive`, `Hostile`, `Custom`, `Return`, `First City`,
`World 1`..`World 5`, `Random`, `Return` -- the new-world dialog's item labels.  See
`doc/emulator_findings.md` for the dump and for the withdrawal of the alias claim.

Globals: 176 -> 175.

## `LevelBandMin/Max` are `byte[4]`, and `demoCenterX/Y` (173 globals)

`ovc30_usesRandBelow` (619c:025d) copies four bytes into four adjacent locals and then
indexes them by the band argument:

```
byte bandMin[4], bandMax[4];
bandMin._0_2_ = LevelBandMin._0_2_;  bandMin._2_2_ = LevelBandMin._2_2_;
bandMax._0_2_ = LevelBandMax._0_2_;  bandMax._2_2_ = LevelBandMax._2_2_;
... bandMin[param_1] ... bandMax[param_1] ...
```

The live bytes are `LevelBandMin = 00 05 09 00` and `LevelBandMax = 04 08 FF FF`, i.e. the
level bands [0,4], [5,8], [9,255], [0,255].  Both globals were `undefined2` with a second
`word_..._5DEE`/`_5DF2` symbol covering their upper half; they are now `byte[4]` arrays and
those two half-symbols are deleted.  The retype is verified by re-decompiling the reader
(the listing now shows `byte bandMin[4]` and `LevelBandMin._2_2_`).

`word_2410_DATA_DGROUP_5DF4/5DF6` are the demo's map/spawn centre: `run_demo` (6d7a:08df)
writes `0x58` and `0x24` (or `0x1e`) there, calls `ovc30_textDivideError(mode 2)`, and copies
them into `GfxRndSeed`/`GfxRndSeed2`.  `ovc30_textDivideError` places units at random offsets
inside `centerX +/- 8` (clamped 8..0x8c) and `centerY +/- 4` (clamped 8..0x34).  Named
**`demoCenterX`** and **`demoCenterY`**.

Globals: 175 -> 173 (2548 -> 2546 symbols; the two deleted labels are the absorbed halves).

## `PromoteThreshold` is `byte[4]` (172 globals)

The same two-word copy pattern as `LevelBandMin/Max`: `season_repairBuildings` copies
`PromoteThreshold` and `word_..._69D9` into adjacent locals and then reads
`PromoteThreshold[rank]`:

```
promoteThreshold = PromoteThreshold;  uStack_4 = word_2410_DATA_DGROUP_69D9;
... *(byte *)((int)&promoteThreshold + rank) <= leader[0xa5] ...
```

So it is a four-byte table of promotion thresholds indexed by rank.  Retyped as `byte[4]` at
`2410:69d7`; the upper-half symbol at `2410:69d9` is deleted.  The `season_repairBuildings`
parameter that indexes it is now `rank`.

Globals: 173 -> 172.

## Five BSS/DGROUP bytes from the full-program xref scan (167 globals)

`scripts/ghidra/RefsToAddrs.java` was run over all 172 auto globals.  The export had hidden most
of their references; the full program gives 84 with xrefs.  Five had direct semantic evidence:

| address | name | evidence |
|---|---|---|
| `2000:ca9b` | `GBattleMode` | `ovc41_textCannotSeeTerrain` does `GBattleMode = 1 - (GBattleMode != 0); GOngoingBattle = GBattleMode;`; `ovc41_usesAgnt_clear` seeds `GOngoingBattle` from it; `main` clears it when a game starts. |
| `2000:d2e4` | `GYear` | `updSeason` increments it when `season == 0 && GTimeLo == 0`, once per three-season cycle; `init_usesClearEntities` resets it; it is saved right after `PlayerCount`. |
| `2000:d3cc` | `promotionCount` | incremented by `season_usesGPromotableCount` on a successful promotion; `season_usesGPromotableCount2` and the stats promotion case compute the next threshold as `promotionCount*0x32 + 0x32`. |
| `2000:d3cd` | `promotionBandUsed` | two-byte per-band latch: `season_compute1` indexes it with `ovc30_compute1(level)` (0..1), returns 0 if set, otherwise sets it; retyped `byte[2]`. |
| `2410:6a88` | `GHighScoreSaved` | set by `ovc38_usesStshAlloc` after it formats `"%c%s%s@%d"` and inserts the entry; `ovc24_textStrongholdDestroyed`, `season_textHalflingCastle` and `ovc38_usesStshAlloc` guard on it being 0. |

Re-decompiling the readers shows the new names (`GBattleMode = 1 - (GBattleMode != 0)`,
`promotionCount * 0x32 + 0x32`, `if (GHighScoreSaved == 0)`).  **Globals: 172 -> 167.**

## Two more referenced bytes (165 globals) and the audio-driver refusal

| address | name | evidence |
|---|---|---|
| `2000:d090` | `placementStatus` | `constr_usesGMapFlags`, `ovc22_textArena` and `ovc22_textRingProt` set it to 1 when the cell/flags are occupied, 2 when the coordinates are outside 0..0x93/0x3b, and 3 when the edge height difference is below 9; a valid plot leaves it 0. |
| `2000:d19c` | `inputCancelled` | `uiReadString` / `saveui_usesBlitText` clear it on entry and set it on Esc (`0x11b`), `0xfffe`, or the cancel-button click; `saveui_textWhichNewWorld` and `chargen` abort when it is nonzero. |

Re-decompiling the writers shows `placementStatus = 2/3/1` in the three branches and
`inputCancelled = 0/1` at entry/cancel.

### Refused: the audio-driver copy words (`2000:d0a2..d0f2`)

`RefsToAddrs.java` finds only writes for these words, all inside `stshLoadAudioDrivers`
(`4b0a:13d3`).  Their stored values duplicate already-named handles: `d0a2` gets
`sblasterComOfs`, `d0e4/d0e6` get `sblasterComOfs/Seg`, and `d0d8..d0de` get the same
`sbpro.com` far pointer twice.  No reader exists in the program and no indirect table access
into the block appears either, so the individual slots cannot be named without guessing; they
stay unnamed with this note.

Globals: 167 -> 165.

### Refused: writer-only temporaries and counters

* `2000:d114` (`word_2000_BSS_06E0`) is written by unrelated routines with unrelated values:
  `attact_usesMenuItemEnabled(...)` (a menu state), `uVar2` in `attact_textCannotAttractUnits`,
  a `pcVar3` pointer in `ovc18_spawnClassAgent`, `func_0x0004f501()` in `chargen_switch`, and
  `func_0x0004f501(0x3f0b)` in `attact_usesLDIV_at_`, which then divides by it.  It is a shared
  scratch slot, not one semantic variable.
* `2000:d163`/`2000:d165` are reset in `attact_usesAlignUp42` and then only incremented in
  `ovc26_usesStExit`; no reader exists, so they are counters with no recoverable meaning.

Both stay unnamed by design; the evidence above is the reason, not a guess.

## Construction projection tables are arrays (157 globals)

`init_computeMaxSquares` (`3381:17e8`) fills the projection tables in three loops:

* `cStack_f = 8..0`: `rowMapSquareEnd`, `rowMapSquareFirst`, `ScreenOriginY`, `ScreenOriginX`
  -- **9 words each**;
* `cStack_f = 2..0`: `rowBandSquareEnd`, `rowBandSquareFirst`, `RowScreenY`, `RowScreenX`
  -- **3 words each**;
* `GSMaxSquare = 0..0x24` (36): `squareSide`, `squareColumn`, `SquareRightX`, `SquareLeftX`,
  `SquareBottomY`, `SquareTopY` -- **36 words each**.

The named bases had been typed as single `undefined2`, so the last element of each short array
carried its own auto label (`word_..._0396/039C/03A2/03A8/05B4/05C6/05D8/05EA`).  The new
`RetypeArray.java` cleared and recreated the ranges as `uint16_t[N]`, which absorbed those eight
labels and restored the two missing X arrays (`RowScreenX` at `2000:cdd8`, `ScreenOriginX` at
`2000:d00e`), whose slots were only written by raw `ES:` stores in the initializer.  The eight
interior labels were then deleted with `RemoveSyms`.

Re-decompiling `constr_usesBlitGfxRect2` now shows the arrays and the X coordinate:

```
for (uVar5 = ((uint16_t *)rowBandSquareFirst)[dy]; uVar5 < rowBandSquareEnd[dy]; ...) {
  blit(..., ((uint16_t *)RowScreenX)[dy] - iStack_18, ...);
  ... ((uint16_t *)RowScreenY)[dy] - iStack_14 ...
}
```

**Globals: 165 -> 157.**

### The `1539:*` words are 432-word map-square arrays

`init_computeMaxSquares` fills six per-map-square tables with `ES = 0x2410`, and Ghidra's
overlay relocation resolves those stores to the six symbols at `1539:0000/0360/06c0/0a20/`
`0d80/1440`.  The stores give each offset its role:

| offset | name | store in `init_computeMaxSquares` |
|---|---|---|
| `0000` | `mapSquareSide` | `ES:[GMaxSquare*2 + 0] = 0/1/2` |
| `0360` | `mapSquareColumn` | `ES:[GMaxSquare*2 + 0x360] = column` |
| `06c0` | `mapSquareRightX` | `... + 0x6c0 = leftX + width` |
| `0a20` | `mapSquareLeftX` | `... + 0xa20 = iStack_a + uStack_14` |
| `0d80` | `mapSquareBottomY` | `... + 0xd80 = topY + height` |
| `1440` | `mapSquareTopY` | `... + 0x1440 = iStack_c + uStack_12` |

Each is 432 words because the loop guards on `0x1af < GMaxSquare` (0x1b0 = 432).  The bases
are 0x360 bytes apart and the last ends exactly at the block end (0x1440 + 0x360 = 0x17a0); the
0x10e0 slot between `mapSquareBottomY` and `mapSquareTopY` is unused (no reference).  Retyped
all six as `uint16_t[432]`; the six `word_1539...` autos are absorbed.

**Globals: 143 -> 137.**

## `timeOfDayGfx` is `far_t[12]` at 2000:d133 (144 globals)

`attact_usesBlitLoadRleGfx` picks a time-of-day image from `GTimeLo`:

```
uVar2 = (GTimeLo <= 0xe) ? GTimeLo : GTimeLo - 0xf;
if (0xe < uVar2) uVar2 = 0xe;
i = ((uVar2 * 12) / 15) * 4;
gfx.seg = timeOfDayGfx[i/4].seg;  gfx.ofs = timeOfDayGfx[i/4].ofs;
```

`i/4` reaches 11, so the table has 12 four-byte far pointers.  It starts at `2000:d133` and
ends exactly where the `d163/d165` counters begin (`d133 + 0x30 = d163`), which confirms both
the length and the earlier counter refusal.  The old `timeOfDayGfxSeg` at `d135` was entry 0's
segment, and the autos at `d15f/d161` were entry 11; all three are deleted.

Re-decompiling the reader now shows:

```
gfx.seg = *(&timeOfDayGfx[0].seg + iVar1 * 4);
gfx.ofs = ((far_t *)timeOfDayGfx + iVar1)->ofs;
```

**Globals: 146 -> 144.**

## `recordUpdateTick` is a 32-bit BDA timer at 2000:ca34 (143 globals)

`draw_usesPlay_sfx` pushes the far value at `DS:0x8936:0x8934` as one 32-bit tick to
`attact_usesBDADailyTimeCounter`, then refreshes it from the BIOS timer:

```
MOV AX,ES:[BX+2]      ; BDA daily-timer high word
MOV DX,ES:[BX]        ; low word
MOV [0x8936],AX       ; high half
MOV [0x8934],DX       ; low half
```

That pair is `2000:ca34` (low) and `ca36` (high), i.e. one `uint32_t`.  The old
`_bdata_at_`/`ExitEnd` labels at `ca34` are **not variables**: `startx` zeroes BSS with
`MOV DI,0x8934; MOV CX,0x949a; STOSB.REP`, so Ghidra labelled the first byte of that fill; both aliases are now removed.
The value is the tick that gates the `GRecordCount` update loop, hence `recordUpdateTick`.

Retyped `2000:ca34` as `/stdint.h/uint32_t` and deleted the high-half label at `ca36`.
Re-decompiling the writer shows `recordUpdateTick._2_2_` / `._0_2_` stores and
`attact_usesBDADailyTimeCounter((ulong *)recordUpdateTick, ...)`.

**Globals: 144 -> 143.**

### Refused: the `6616:*` overlay-stub header fields

`__InitModules` addresses the overlay stub with `ES = 0x226e`:

```
1403:02ce  CMP byte ptr ES:[0x1a],0xff
1403:02e2  MOV word ptr ES:[0x18],0x4c3
1403:02f0  ADD word ptr ES:[0x4],AX     ; AX = GUnitDescriptions[10] size
1403:02f5  ADC word ptr ES:[0x6],DX
```

Ghidra resolves those to `6616:14b4` (+0x4), `14b6` (+0x6), `14c8` (+0x18) and `14ca` (+0x1a),
i.e. a header based at `6616:14b0`: a 32-bit size accumulator at +0x4/+0x6, a word at +0x18 set
to 0x4c3, and a 0xff state byte at +0x1a.  The header's other fields and the meaning of the
0x4c3/0xff values are not established, so the four fields stay unnamed rather than being given
generic "headerFieldN" names.

## Resolved: the `6616:*` overlay-stub fields and `2410:073c/0740` (130 globals)

### The `6616:*` words are the Borland overlay-manager block

The `ES` in `__InitModules` is literal `0x226e`, which is the program's `OVR_STUB` block.  That
block already carries the canonical Borland symbols:

```
226e:0004 __OvrFileBase    226e:0012 __OvrCodeList
226e:0018 __OvrDosHandle   226e:001a __OvrLoadCount
```

`__InitModules` adds the overlay size through `ES:[0x4]/ES:[0x6]` (`__OvrFileBase` is a 32-bit
file position), writes `ES:[0x18] = 0x4c3`, compares `ES:[0x1a]` with 0xff, and sets
`ES:[0x12]` from the module-table entry.  The four `6616:14b4/14b6/14c8/14ca` symbols were
relocated image aliases of those fields.  They are now typed/named as the same fields
(`__OvrFileBase` dword absorbing the `14b6` high word, `__OvrDosHandle` word,
`__OvrLoadCount` byte), and the canonical `226e` fields were given their proper types too.

### `2410:073c` is the corner-shade bias table

`2410:073c..0741` is exactly six bytes (`0D 0A 05 03 02 01`) before `SmoothPrev` at `0742`.
`ovc23_usesCornerBR` subtracts element 0 from the four corner heights, while
`constr_usesAgnt_clear` reads `[SI+0x73c]` and `constr_usesBlitGfxRect2` reads `[SI+0x73e]`,
i.e. two overlapping 3-entry views (`0D/0A/05` and `05/03/02`) used to pick the minimum corner.
Typed `uint8_t[6] cornerShadeBias`; the `0740` interior label is deleted.

**Globals: 136 -> 130.**

### Refused: `2410:0845`

The byte is constant `0x00` in the image, has exactly one reference (the first guard of the
animation blit in `ovc13_usesMiceBlitRect`: `DGROUP_0845 == 0 && GPaused == 0 &&
byte_2000_06E2 == 1`), and **no writer anywhere in the program**.  It sits between `GMenuFlag`
(`0844`) and `flashPaletteEf` (`0846`).  A constant, never-written byte cannot be distinguished
from alignment padding or a compiled-out debug switch from this evidence, so it stays unnamed.

## No-xref sweep: the CRТ jump table, false code-data, strings (65 globals)

### `1000:131a` is `printfFormatJumpTable` (`uint16_t[24]`)

The CRT format parser at `1000:0f1a` reads a `%` directive, maps the byte through
`vprinter_printCtype[byte-0x20]` (96 entries at `2410:884b`), bounds-checks the index against
`0x17`, shifts it and executes `JMP word ptr CS:[BX + 0x131a]`.  The table is 24 code offsets
(`0x0f7b, 0x0f65, 0x0fb0, ... 0x0f91`) from `0x131a` to `0x1349`; a new function starts at
`0x134a`.  Retyped `uint16_t[24]`, absorbing the 23 `data_1000_TEXT_crtl_13xx_uint` autos.

### 32 auto words were code, not globals

In executable overlays several auto words were instruction bytes that Ghidra had typed as data
because the surrounding function bodies had gaps.  `ForceDisasm.java` clears a range and runs
`DisassembleCommand`; these five ranges decoded with zero holes:

```
3f0b:1ab9-1ac5   3f0b:21d8-21e6   4d05:33b8-33c1   4d05:342d-3437   5087:0bd2-0c02
```

Examples: `3f0b:1ab9 POP DX / ADD DX,AX / MOV [BP-4],DX / CMP [BP-4],0 / JNZ`;
`5087:0bd2 MOV DX,0x195D / PUSH ES / PUSH BX / ...` (the `0c00` word was even misaligned).
The false data units are gone, so they no longer appear as globals.

### Strings and the BIOS tick

Nine auto string units were named from their own bytes, using the existing address-suffixed
convention: `s_underscore_2410_2738`, `s_lf_2410_5fde/6097/6156`, and
`s_empty_2410_6939/6ac3/6b39/747d/78df` (the last is the null before `strong.dat`).
`0000:046c` is the BIOS data area `0040:006C` tick counter, typed `uint32_t BDA_TickCount`.

**Globals: 130 -> 65.**

## Residual no-xref items (52 globals)

| address | name | evidence |
|---|---|---|
| `4b0a:0b69` | `audioCommandSwitch` (`uint16_t[6]`) | the function at `4b0a:09ce` loads `AL=ES:[*arg]`, checks `BX <= 5` and executes `JMP word ptr CS:[BX + 0xb69]`; handlers are `0x09f4, 0x09fd, 0x0a16, 0x0a2f, 0x0a43, 0x0a5c`. |
| `6018:16b0` | `ovc28_codeOffsetTable` (`uint16_t[59]`) | a contiguous run of 59 descending 16-bit code offsets `0x0ff2..0x0c00` from `16b0` to `1725`; the run before it at `1670` and the ascending run at `1726` are separate. No dispatcher survives in the disassembled overlay, so the name states the data image rather than an unproven purpose. |
| `138e:0002` | `miceHandlerStack` (`uint8_t[256]`) | the INT 33 handler saves `SS`/`SP` at `GMiceSS`/`GMiceSP`, then `PUSH CS; POP SS; MOV BX,2; ADD BX,0xfe; MOV SP,BX`, so `SS=CS` and `SP=0x100`: `0002..0101` is the handler's private downward stack below the saved-state words. |
| `224a:0121` | `miceTileTail` (`uint8_t[15]`) | the `224a` block is 0x130 bytes; its first 0x121 bytes are `MiceSaveArea` (the template copied into the four `MicePtrs` buffers), while `video_copyScreenTile`/`miceBlitAtSeg` use the same segment as a screen-tile scratch, so `0121..012f` is the remaining 15 bytes. |

### Refused: `2ca1:0000/0002/0004`

Three words of `0x15D4` before `InitStart` (`boinit_t[4]` at `0006`).  They have no reader and no
writer, and they are not shaped like init records (which start `01 01 24 0D ...`); the earlier
`boinit_t[5]` typing was already withdrawn.  They stay unnamed.

**Globals: 65 -> 52.**

## `2000:d0a2` = `sbfmAdvSeg` (51 globals)

The audio-driver block `2000:d094..d0f3` is a run of far-pointer pairs written by
`stshLoadAudioDrivers`.  The loader was re-read instruction by instruction: the string table at
`2410:48d0` is `"sbfm.adv"`, `"sbp2fm.adv"`, `"sbp1fm.adv"`, `"pasfm..."`, and the store
right after the `sbfm.adv` call is

```
4b0a:154a  CALLF 4000:c070        ; stshStoreFile_2(DS:0x48d0 == "sbfm.adv", ..., 1)
4b0a:1555  MOV  ES:[0x8fa2],DX    ; segment  -> 2000:d0a2
4b0a:155a  MOV  ES:[0x8fa0],AX    ; offset   -> 2000:d0a0 (= sbfmAdvOfs)
```

so `d0a2` is the segment half of the `sbfm.adv` handle.  The decompiler had printed the source
as `pfVar2` (a stale register guess); the instruction above shows the pair comes from the same
`stshStoreFile_2` return.  Re-decompiling now shows `sbfmAdvOfs = stshStoreFile_2("sbfm.adv",...);
sbfmAdvSeg = ...;`.

### Still refused in this block

The remaining 15 autos (`d0a4..d0aa`, `d0d0/d0d2`, `d0d8..d0de`, `d0e4/d0e6`, `d0ee..d0f2`) are
**cleared to zero or duplicated** by the loader rather than loaded from a named file: e.g. after
the `sblaster.com` pair is stored the loader executes `MOV word ptr ES:[0x8fd2],0` /
`ES:[0x8fd0],0`, and `d0d8..d0de` is written twice from the same return value.  With no reader
and no file name attached, naming them would be positional guessing.

**Globals: 52 -> 51.**

## Whole-program read/write classification for every remaining auto global

`scripts/ghidra/RefKinds.java` classifies each reference with Ghidra's `RefType` and, where the
reference is unclassified, inspects the operand whose scalar matches the address (DS-relative or
BSS-relative) to read the READ/WRITE operand flags.  This replaces the earlier assumption that
most of the remainder were writer-only: it found readers the export had hidden, and it proves
which ones really have none.

| address | symbol | reads | writes |
|---|---|---|---|
| `0000:08b8` | DAT_0000_08b8 | reads=0 | writes=0 |
| `0000:08b9` | DAT_0000_08b9 | reads=0 | writes=0 |
| `0000:08ba` | DAT_0000_08ba | reads=0 | writes=0 |
| `0000:08bc` | DAT_0000_08bc | reads=0 | writes=0 |
| `0000:08be` | DAT_0000_08be | reads=0 | writes=0 |
| `0000:08c0` | DAT_0000_08c0 | reads=0 | writes=0 |
| `16b3:034c` | word_16b3_DATA_game2_034C | reads=1 | writes=0 |
| `16b3:04f0` | word_16b3_DATA_game2_04F0 | reads=1 | writes=0 |
| `21b1:0000` | data_21b1_DATA_game9_0000 | reads=0 | writes=0 |
| `21b1:0002` | data_21b1_DATA_game9_0002 | reads=0 | writes=0 |
| `225d:008e` | DAT_225d_008e | reads=1 | writes=0 |
| `2410:0845` | byte_2410_DATA_DGROUP_0845 | reads=1 | writes=0 |
| `2410:59bf` | data_2410_DATA_DGROUP_59BF | reads=0 | writes=0 |
| `2410:5a0d` | data_2410_DATA_DGROUP_5A0D | reads=0 | writes=0 |
| `2410:5a3d` | data_2410_DATA_DGROUP_5A3D | reads=0 | writes=0 |
| `2410:5a73` | data_2410_DATA_DGROUP_5A73 | reads=0 | writes=0 |
| `2410:5aa9` | data_2410_DATA_DGROUP_5AA9 | reads=0 | writes=0 |
| `2410:5ac1` | data_2410_DATA_DGROUP_5AC1 | reads=0 | writes=0 |
| `2410:5ad9` | data_2410_DATA_DGROUP_5AD9 | reads=0 | writes=0 |
| `2410:6594` | data_2410_DATA_DGROUP_6594 | reads=0 | writes=0 |
| `2410:6596` | data_2410_DATA_DGROUP_6596 | reads=0 | writes=0 |
| `2410:6598` | data_2410_DATA_DGROUP_6598 | reads=0 | writes=0 |
| `2410:65c4` | data_2410_DATA_DGROUP_65C4 | reads=0 | writes=0 |
| `2410:65fd` | data_2410_DATA_DGROUP_65FD | reads=0 | writes=0 |
| `2410:65ff` | data_2410_DATA_DGROUP_65FF | reads=0 | writes=0 |
| `2410:6ac6` | data_2410_DATA_DGROUP_6AC6 | reads=1 | writes=0 |
| `2ca1:0000` | data_2ca1_DATA_INIT_0000_word | reads=0 | writes=0 |
| `2ca1:0002` | data_2ca1_DATA_INIT_0002_word | reads=0 | writes=0 |
| `2ca1:0004` | data_2ca1_DATA_INIT_0004_word | reads=0 | writes=0 |
| `2000:ca7a` | byte_2000_BSS_0046 | reads=0 | writes=1 |
| `2000:d0a4` | word_2000_BSS_0670 | reads=0 | writes=2 |
| `2000:d0a6` | word_2000_BSS_0672 | reads=0 | writes=2 |
| `2000:d0a8` | word_2000_BSS_0674 | reads=0 | writes=2 |
| `2000:d0aa` | word_2000_BSS_0676 | reads=0 | writes=2 |
| `2000:d0d0` | word_2000_BSS_069C | reads=0 | writes=2 |
| `2000:d0d2` | word_2000_BSS_069E | reads=0 | writes=2 |
| `2000:d0d8` | word_2000_BSS_06A4 | reads=2 | writes=2 |
| `2000:d0da` | word_2000_BSS_06A6 | reads=2 | writes=2 |
| `2000:d0dc` | word_2000_BSS_06A8 | reads=0 | writes=2 |
| `2000:d0de` | word_2000_BSS_06AA | reads=0 | writes=2 |
| `2000:d0e4` | word_2000_BSS_06B0 | reads=0 | writes=2 |
| `2000:d0e6` | word_2000_BSS_06B2 | reads=0 | writes=2 |
| `2000:d0ee` | word_2000_BSS_06BA | reads=0 | writes=2 |
| `2000:d0f0` | word_2000_BSS_06BC | reads=0 | writes=2 |
| `2000:d0f2` | word_2000_BSS_06BE | reads=0 | writes=2 |
| `2000:d114` | word_2000_BSS_06E0 | reads=6 | writes=3 |
| `2000:d163` | word_2000_BSS_072F | reads=5 | writes=2 |
| `2000:d165` | word_2000_BSS_0731 | reads=5 | writes=2 |
| `2000:d187` | byte_2000_BSS_0753 | reads=2 | writes=0 |
| `2000:d1e2` | byte_2000_BSS_07AE | reads=1 | writes=0 |
| `3381:168f` | data_OVC09_init_c_168F | reads=0 | writes=0 |

### `16b3:034c` is `columnScreenY`, `uint16_t[211]` (51 -> 49)

`ovc49_body1` computes `screenY = columnScreenY[agnt_clampX(entity.x)] + entity.y + 3` (and the
same with a height adjustment in the other branch), and `agnt_compute1` returns
`columnScreenY[y - 0xc]` for `y` clamped to `0xc..0xde`.  `0xde - 0xc + 1 = 211` entries, so the
array spans `0x34c..0x4f1` and the old auto label at `0x4f0` is its last element.  Retyped and
relabelled; that label is gone.

### Two labels that are not globals

`2000:d187` and `2000:d1e2` are **computed-reference artifacts**, not variables:

```
1301:03d1  CMP byte ptr ES:[BX + 0x90de],0xff   ; BX = MenuItemEnabled index -> d1de + 4
1301:07fb  MOV AL,byte ptr ES:[BX + 0x9082]     ; d182 + 5
```

The first is `MenuItemEnabled[index]` and the second is element 5 of a table at `d182`.
Removing the labels makes Ghidra re-create them as `DAT_2000_d187`/`DAT_2000_d1e2` on save, so
they are recorded here as artifacts instead of being renamed.

### Corrected notes on earlier refusals

* `2000:d114` is not merely "shared scratch": it has 6 reads and 3 writes.  In
  `attact_textAbnormalProgramTermination` it receives the return value of `3000:f501`
  (`MOV [0x9014],AX`) and is then read back (`MOV AX,[0x9014]; INC AX`), so it is a compiler
  temporary for a call result; `attact_updateAttractEntry` reuses the same slot for a different
  value.  Different functions store unrelated values, so no single name is possible.
* `2000:d163`/`d165` do have readers: five each, every one a `PUSH [0x9063]`/`PUSH [0x9065]`
  immediately before a `printf` guarded by `DebugVerbose` (format `"%d %d %d  \r"` at
  `2410:08ea`).  They are incremented in `ovc26_usesStExit` (`INC word ptr ES:[0x9065]` after the
  `0x19`-tick guard, `INC word ptr ES:[0x9063]` when the gfx cell is empty) and cleared in
  `attact_usesAlignUp42`.  They are verbose-mode diagnostic counters; the format string does not
  say what they count.

## Pointer-target sweep: 14 auto globals resolved (49 -> 35)

The remaining auto labels were not independent variables.  Each one turned out to be either the
second word of a far pointer or the head of a record that a **named pointer table** points at.
The test that settled them is to read the table's own entries.

### `2410:6ac6` is the segment half of `msgFormat`

```
690b:0aee  PUSH word ptr [0x6ac6]      ; segment
690b:0af2  PUSH word ptr [0x6ac4]      ; offset
```

one 32-bit far argument, and the stored pair at `6ac4` is `6AC8:2410`, exactly the string at
`2410:6ac8`.  So `msgFormat` was a two-byte `undefined2` that should have been a `far_t`; retyped,
and the `6ac6` label removed.

### `2410:6592` is `strangeTableData`, `uint16_t[55]`

`GStrangeTable` (`far_t[98]` at `2410:6601`) has entries

```
6594 6596 6598 659A 659C 659E 65A0 65A2 6592 65A4 ... 65FD 65FF  (all segment 2410)
```

i.e. stride-2 records from `0x6592` to `0x65FF`, one per entry, plus the all-zero record at
`0x6592`.  The auto labels `6594/6596/6598/65C4/65FD/65FF` were individual record heads.  Retyped as
`uint16_t[55] strangeTableData`; the six labels are gone and the array covers `0x6592..0x65FF`.

### Seven `RampTables` rows

`RampTables` (`far_t[7]` at `2410:5aeb`) holds

```
59BF 5A0D 5A3D 5A73 5AA9 5AC1 5AD9  (all segment 2410)
```

which are exactly the seven remaining auto labels.  Each row runs to the next row's start, so its
length is fixed by the table itself:

| entry | address | length | name |
|---|---|---|---|
| 0 | `2410:59bf` | 78 | `rampRow0` |
| 1 | `2410:5a0d` | 48 | `rampRow1` |
| 2 | `2410:5a3d` | 54 | `rampRow2` |
| 3 | `2410:5a73` | 54 | `rampRow3` |
| 4 | `2410:5aa9` | 24 | `rampRow4` |
| 5 | `2410:5ac1` | 24 | `rampRow5` |
| 6 | `2410:5ad9` | 18 | `rampRow6` |

All seven retyped `uint8_t[N]`; the labels are gone.

### `2410:6b14` was inside a string

The bytes at `2410:6ac8` read "My %s, we in this neighborhood are doing well. We thank you for all
you have done to help your people." and end with a NUL at `2410:6b2e`.  `DAT_2410_6b14` was the
space at "have done", i.e. a split inside the string.  Retyped as `char[103]`
`s_my_s_we_in_this_neighborhood_are_doing_well`, which absorbs it; the stale zero-length alias on
`2410:6ac7` (the high byte of `msgFormat`) was removed too.

**Globals: 49 -> 35.**  Remaining: 15 audio-driver copy words, the 6 `0000:08b8..08c0` computed-
reference artifacts, 2 `DAT_2000_d1xx` artifacts, 3 `2ca1` words, `21b1` dwords, `225d:008e`
overlay-header padding, `2410:0845`, `2000:ca7a`, `d114`, `d163/d165`, and `3381:168f`.

### `21b1:0000` is `expThresholds`, `uint32_t[240]`

The `21b1` data block is indexed by sixteen code sites (`MOV DX,0x21b1` + `MOV ES,DX`).  One of them
shows the shape exactly (`6386:1d74`):

```
6386:1d74  SHL AX,0x2            ; index * 4
6386:1d78  ADD BX,AX
6386:1d7a  MOV AX,0x21b1 / MOV ES,AX
6386:1d7f  MOV AX,ES:[BX + 0x0]
6386:1d84  OR  AX,ES:[BX + 0x2]   ; test the whole dword for zero
```

so it is a table of 32-bit thresholds where `0` means "no entry".  The values are

```
0, 2000, 4000, 8000, 16000, 32000, 64000, 120000, 240000, 360000, 480000, 620000, 830000, 1050000 ...
```

the classic class-level experience ladder.  The entries run to `21b1:03BF` (240 dwords); the rest of
the 1040-byte block is zero padding.  Retyped `uint32_t[240] expThresholds`; the two old auto labels
were the two halves of entry 0.

**Globals: 49 -> 33** across this sweep.

## Audio-driver handle pairs: reading the loader's own push/store sequence

`stshLoadAudioDrivers` (`4b0a:13d3`) loads each driver file with
`CALL 4000:c070` (= `stshStoreFile_2`) and immediately stores the return in a DS-relative
word pair.  Because DS offsets map to BSS offsets by `+0x4100` (`DS:0x8f98` = `2000:d098`),
each pair can be tied to the exact string pushed just before the call.  The string table is
contiguous at `2410:486c`:

| string | address | pair (ofs/seg) |
|---|---|---|
| `midpak.ad` | `486c` | `2000:d098` (now `far_t midpakAd`) |
| `cmidpak.com` | `4876` | `2000:d094/d096` |
| `ibmsnd.com` | `4882` | `2000:d0c8/d0ca` |
| `sblaster.com` | `488d` | `2000:d0cc/d0ce` |
| `fibmbak.com` | `489a` | `2000:d0d4/d0d6` |
| `sbpro.com` | `48a6` | `2000:d0d8/d0da` |
| `paudio.com` | `48b0` | `2000:d0e0/d0e2` |
| `adlib.com` | `48bb` | `2000:d0e8/d0ea` |
| `adlibg.com` | `48c5` | `2000:d0ec/d0ee` |
| `sbfm.adv` | `48d0` | `2000:d0a0/d0a2` |
| `sbp2fm.adv` | `48d9` | `2000:d0ac/d0ae` |
| `sbp1fm.adv` | `48e4` | `2000:d0b0/d0b2` |
| `pasfm.adv` | `48ef` | `2000:d0b4/d0b6` |
| `pasopl.adv` | `48f9` | `2000:d0b8/d0ba` |
| `adlib.adv` | `4904` | `2000:d0bc/d0be` |
| `adlibg.adv` | `490e` | `2000:d0c0/d0c2` |
| `mt32mpu.adv` | `4919` | `2000:d0c4/d0c6` |

### The seven words resolved from it (33 -> 26)

```
4b0a:147c  PUSH 0x48a6                 ; "sbpro.com"
4b0a:1480  CALL 0x4000:c070
4b0a:148b  MOV ES:[0x8fda],DX          ; segment -> 2000:d0da
4b0a:1490  MOV ES:[0x8fd8],AX          ; offset  -> 2000:d0d8
4b0a:1499  MOV AX,ES:[0x8fda]          ; second copy of the same handle
4b0a:149d  MOV DX,ES:[0x8fd8]
4b0a:14a7  MOV ES:[0x8fde],AX          ; -> 2000:d0de
4b0a:14ab  MOV ES:[0x8fdc],DX          ; -> 2000:d0dc
4b0a:14d0  MOV AX,ES:[0x8fce]          ; second copy of the sblaster handle
4b0a:14d4  MOV DX,ES:[0x8fcc]
4b0a:14de  MOV ES:[0x8fe6],AX          ; -> 2000:d0e6
4b0a:14e2  MOV ES:[0x8fe4],DX          ; -> 2000:d0e4
4b0a:1505  PUSH 0x48c5                 ; "adlibg.com"
4b0a:1514  MOV ES:[0x8fee],DX          ; segment -> 2000:d0ee
```

so `d0d8/d0da` = `sbproComOfs`/`sbproComSeg`, `d0dc/d0de` = the second copy
(`sbproComCopyOfs`/`sbproComCopySeg`), `d0e4/d0e6` = the second copy of the sblaster handle
(`sblasterComCopyOfs`/`sblasterComCopySeg`), and `d0ee` = `adlibgComSeg` (its offset at
`d0ec` was already `adlibgComOfs`).  `d098` was retyped `far_t midpakAd`, replacing the
generic `far_t_2000_d098`.

### `3381:168f` is a jump table, not a variable (26 -> 25)

```
3381:1250  MOV AH,0x0
3381:1252  MOV BX,AX                   ; randBelow(4)
3381:1254  CMP BX,0x3
3381:125c  SHL BX,0x1
3381:125e  JMP word ptr CS:[BX + 0x168f]
```

Four words at `3381:168f` (all `0x1263`), retyped `uint16_t[4] init_textFilenameJumpTable`.

## What the last 25 are, with the operand counts

### Six `0000:08b8..08c0` labels are `unit_t[0]` shadows

The offsets of the six live references are `+0, +1, +2, +4, +6, +8` — exactly the field
offsets of `unit_t` (`bldType +0`, `level +1`, `unitType +2`, `flags +3`, `x +4`, `y +6`,
`timer +8`).  They sit in Ghidra's uninitialised `DS` block (`0000:0000-0000:0fff`,
`init=false`) and are produced by pointer analysis of `GUnits`, which `init_buffers` allocates
at runtime:

```
3381:16f2  PUSH 0x0 / PUSH 0x2a30      ; 0x2a30 = 1200 * sizeof(unit_t)
3381:16f7  CALLF 2000:33b3             ; allocate
3381:1709  MOV ES:[0x8995],AX          ; GUnits.ofs
3381:1704  MOV ES:[0x8997],DX          ; GUnits.seg
3381:1721  CALLF 1000:2642             ; _fmemset(GUnits, 0, 0x2a30)
```

So no real data lives at `0000:08b8`; Ghidra guessed that base for the runtime pointer.  They
stay labelled as artifacts rather than deleted (deleting regenerates them on save, the same
behaviour as `2000:d187/d1e2`).

### Still refused

| address | evidence |
|---|---|
| `2000:d0a4/d0a6`, `d0a8/d0aa`, `d0d0/d0d2`, `d0f0/d0f2` | zeroed by the loader right after the adjacent named pair (`MOV word ptr ES:[0x8fa6],0` etc.) and never read; they are placeholder slots, not file handles |
| `2410:0845` | one read (`3d16:0126 MOV AL,[0x845]` then `JNZ`), zero writes anywhere; it sits between `GMenuFlag` (0844) and `flashPaletteEf` (0846), so it is a sibling flag that no code ever sets |
| `2000:ca7a` | single write `1301:00bd MOV byte ptr ES:[0x897a],0x1` in `main`, immediately after `MenuMode = 1`; no reader |
| `2ca1:0000/0002/0004` | three words in front of `InitStart` (`boinit_t[4]` at `2ca1:0006`); no reference to segment `2ca1` anywhere |
| `225d:008e` | inside the Borland `OVRDATA` header next to `__OVRBACKLINK__`/`__OvrExepathBuf` |
| `2000:d114` | 6 reads / 3 writes: a compiler call-result temporary reused with unrelated values |
| `2000:d163/d165` | 5 reads each, all `PUSH [0x9063]`/`[0x9065]` before a `DebugVerbose`-gated `printf`; incremented in `ovc26_usesStExit` |
| `2000:d187`, `2000:d1e2` | computed-reference artifacts (`MenuItemEnabled[index]`, element 5 of a table at `d182`); the labels regenerate when removed |

## Closing the global axis: 25 -> 0 auto-named (0.0%)

### The six `0000:08b8..08c0` labels are one `unit_t` shadow

The live offsets of those labels are `+0,+1,+2,+4,+6,+8`, exactly the field offsets of
`unit_t` (`bldType +0`, `level +1`, `unitType +2`, `flags +3`, `x +4`, `y +6`, `timer +8`),
and they sit in Ghidra's uninitialised `DS` block (segment 0).  `init_buffers` allocates the
real array at runtime:

```
3381:16f2  PUSH 0x0 / PUSH 0x2a30      ; 0x2a30 = 1200 * sizeof(unit_t)
3381:16f7  CALLF 2000:33b3             ; allocate
3381:1709  MOV ES:[0x8995],AX          ; GUnits.ofs
3381:1704  MOV ES:[0x8997],DX          ; GUnits.seg
3381:1721  CALLF 1000:2642             ; _fmemset(GUnits, 0, 0x2a30)
```

so segment 0 is the analyzer's guess for the pointer target.  Deleting the labels regenerated
them (verified), so the 9 bytes were retyped as one `unit_t` named `GUnitsShadow` with a
comment; the six fields are now `GUnitsShadow.bldType/level/unitType/x/y/timer`.

### The four zeroed audio pairs are typed placeholders

`stshLoadAudioDrivers` zeroes these words in **both** the file-load and the stub-allocation
paths, and no instruction reads them:

| pair | zero stores | retyped |
|---|---|---|
| `2000:d0a4/d0a6` | `4b0a:1563/156a` and `4b0a:1778/177f` (`ES:[0x8fa6]/[0x8fa4]`) | `far_t audioPlaceholder0` |
| `2000:d0a8/d0aa` | `4b0a:1576/157d` and `4b0a:178b/1792` (`ES:[0x8faa]/[0x8fa8]`) | `far_t audioPlaceholder1` |
| `2000:d0d0/d0d2` | `4b0a:1450/1457` and `4b0a:1695/169c` (`ES:[0x8fd2]/[0x8fd0]`) | `far_t audioPlaceholder2` |
| `2000:d0f0/d0f2` | `4b0a:1522/1529` and `4b0a:173f/1746` (`ES:[0x8ff2]/[0x8ff0]`) | `far_t audioPlaceholder3` |

### `MenuItemEnabled` is a 5-byte array (absorbs `DAT_2000_d1e2`)

`main` sets `GMenuItem = 5` as the "no selection" sentinel and tests
`((undefined1 *)&MenuItemEnabled)[GMenuItem]` only under `GMenuItem < 5`; the navigation loops
wrap to 5 and stop.  `ovc41_usesMenuItemEnabled` also indexes `MenuItemEnabled[5]`.  Retyped
`uint8_t[5]`, so the former `DAT_2000_d1e2` at `[4]` is now `MenuItemEnabled[4]`.

### `2000:d187` is an out-of-range artifact of the menu table at `2000:d182`

`main` reads `*(byte *)(GMenuItem + 0x9082)` (= `2000:d182 + GMenuItem`) only inside
`GMenuItem < 5` guards, so the 5-byte array ends at `d186`; Ghidra still formed a reference at
`base+5`.  Typed `uint8_t` and named `reserved_187`.

### The remaining unreferenced blocks

* `2ca1:0000` — the six bytes immediately before `InitStart` (`boinit_t[4]` at `2ca1:0006`).
  No operand references segment `2ca1` at all; retyped `uint16_t[3] crtInitReserved`.
* `2410:0845` — one read (`3d16:0126 MOV AL,[0x845]; OR AX,AX; JNZ`), zero writes; it sits
  between `GMenuFlag` (0844) and `flashPaletteEf` (0846) -> `reserved_0845`.
* `2000:ca7a` — written 1 by `main` (`1301:00bd`) right after `MenuMode = 1`, never read ->
  `reserved_ca7a`.
* `225d:008e` — four bytes in the Borland `OVRDATA` header -> `uint32_t ovrHeaderReserved`.

### The three used scratch words got descriptive names

* `2000:d114` -> `callResultTemp`: three functions store a call result and read it back
  immediately (`3f0b:0551 MOV [0x9014],AX` then `3f0b:055d MOV AX,[0x9014]; INC AX`, plus
  `attact_usesLDIV_at_` and `attact_updateAttractEntry`).  The stored values are unrelated, so
  the name records exactly what it is: the last call result.
* `2000:d163` -> `debugEmptyCellCount`: incremented at `5d45:0406` immediately after
  `if (FillGrid[y*0xa1+x] == 0)`, printed only under `DebugVerbose` (`3f0b:10bc PUSH [0x9063]`,
  format at `3f0b:10cf`) and zeroed at `3f0b:10e0`.
* `2000:d165` -> `debugStaleTickCount`: incremented at `5d45:0371` on the
  `GameTick - entity.tick >= 0x19` path, printed with the previous counter and zeroed at
  `3f0b:10da`.

**Globals: 25 auto -> 0 auto (2435 symbols).**

## DGROUP aliasing: the same byte has two displacements

The symbol table names most of DGROUP through segment `2000`, but the code addresses the same
bytes through the program's real DGROUP segment `2410`:

```
2000:ca7a  ==  2410:897a      (0xca7a - 0x897a = 0x4100 = 0x410 << 4)
2000:d187  ==  2410:9087
```

Earlier displacement scans searched for `0xca7a` / `0xd187` and found nothing, which made those
bytes look unreferenced.  Scanning the `2410`-side offsets works.

## `reserved_187` was element 5 of an array (resolved)

`2410:9082` is a six-byte table with no symbol, and the code indexes it with `GMenuItem`:

```
2e25:0107  MOV AL,[0x8980]              ; GMenuItem
2e25:010f  MOV BL,[BP+0x6]              ; the row being drawn
2e25:0114  XCHG AX,BX
2e25:0116  MOV byte ptr ES:[BX+0x9082],AL   ; table[GMenuItem] = row
```

and reads it back in `main`:

```
1301:07fb  MOV AL,byte ptr ES:[BX + 0x9082]
1301:0802  DEC AX
1301:0804  CALLF 0x2000:2bf3            ; consumes (row - 1)
```

`GMenuItem` takes the values `0..5` (`main` sets `5`, and `INC` wraps `6 -> 0`), and
`0x9082..0x9087` is exactly six bytes ending at `StshSprIndex` (`0x9088`).  So the last byte is
`table[5]`, not a standalone reserved byte.  `reserved_187` was deleted and the whole six-byte
object created as:

```
2000:d182  menuItemRow  uint8_t[6]
2000:d187  menuItemRow[5]
```

Evidence for the name: the array maps a menu item to the screen row currently drawn for it, and
the only reader converts the stored value back to a row index (`DEC AX`).

## `reserved_0845` and `reserved_ca7a`: exact access counts

Both were re-scanned with the `2410`-side displacements:

| byte | accesses in the whole program | verdict |
|---|---|---|
| `2410:0845` | **1** - `3d16:0126 MOV AL,[0x845]`, image byte `0x00` | never written; a guard that is always true (`AND GPaused`, `AND mapViewActive`, then blit the animation frame) |
| `2410:897a` | **1** - `1301:00bd MOV byte ptr ES:[0x897a],1` | write-only dead store in `main`, between `GMenuItem = 5` and `ovr_uiMainMenu()`; never read |

Both are single-byte objects with exactly one access each, and neither is part of a larger word
(no word/dword access covers either offset).  They cannot be named from a reader, so they keep
their reserved names with these counts.

## Save-file scan for `agnt_t+0x2a` (inconclusive, recorded)

`tmp/scan_agnt_sav.py` scored every offset of all six saves for a 24 x 0x34 agent array using
gindex/faction/moveState/level/health/x/y plausibility.  It found tens of thousands of
candidate bases per file because long zero-filled regions satisfy every bound, and the best
hits had `gindex = 0` and `faction = 0` in all 24 records - i.e. padding, not agents.  The save
format does not expose the runtime `agnt_t` array at stride 0x34 in a way this test can
separate from zero fill, so `agnt_t+0x2a` still rests on the code evidence: exactly one reader
(`8699:1736 CMP byte ptr ES:[BX+0x2a],2`) and no writer.

## `reserved_0845` -> `noAnimBlit` (named from its only branch)

The byte at `2410:0845` has exactly **one** access in the whole program:

```
3d16:0126  MOV AL,[0x845]
3d16:012b  OR AX,AX
3d16:012d  JNZ 0x3000:d2e4        ; non-zero -> skip
3d16:012f  ...                     ; else restore the mouse area, ovc13_blitAnimFrame(),
                                   ;      and ovr_miceBlitRect()
```

so a non-zero value suppresses the animation-frame blit.  The image byte is `0x00` and no
instruction writes it, i.e. the skip is never enabled.  Named `noAnimBlit` from that branch and
typed `uint8_t`, with the exact store/read record in the symbol comment.

## `reserved_ca7a`: a real standalone byte, write-only

Its neighbourhood rules out both padding and a word half:

```
2410:8976  GGameExe     far_t   (0x8976-0x8979)
2410:8978  GGameExe.seg word    <- MOV ES:[0x8978],AX in main; PUSH ES:[0x8978] in init_paths
2410:897a  reserved_ca7a byte   <- MOV byte ptr ES:[0x897a],1 in main (1301:00bd)
2410:897b  CrossBlitCount2 byte <- written 0 by saveui_startCrossBlit and ovc28_startCrossBlit
2410:897c  CrossBlitY  word
```

`0x897a` is even-aligned, no word or dword access covers it (`ScanDisp` on `0x8978`, `0x8979`,
`0x897a`, `0x897b` returns exactly one access for `0x897a` - the write), so it is not padding
and not the high half of a wider field.  It is a one-byte variable that is written once in
`main` (value 1, immediately before `ovr_uiMainMenu()`) and never read.  With no reader the
name cannot be derived; the counts are recorded instead.

## `reserved_ca7a`: proven write-only by raw byte search (not padding)

A displacement-level scan can miss accesses that the listing never decoded, so the raw image
was searched with `scripts/ghidra/ScanBytes.java`:

```
direct forms (A0/A1/A3/8B06/8906/C706/803E/8D.. 7A 89)   -> 0 hits except
  C6 06 7A 89 xx   MOV byte ptr [0x897a], imm8            -> 1 hit  (the write)
any occurrence of the displacement bytes 7A 89             -> 1 hit  (same instruction)
```

So across the whole program image there is exactly **one** instruction that names `0x897a`, and
it is the store in `main`.  Combined with the byte layout proved earlier
(`GGameExe` far_t at `0x8976-0x8979`, `0x897a` even-aligned byte, `CrossBlitCount2` at `0x897b`,
`CrossBlitY` at `0x897c`), the object is a real standalone byte - not padding and not a word
half - that is written once and never read.  No name can be derived from a reader, so the
symbol keeps its offset name and the record above is the evidence.

## `ovrHeaderReserved`: removal attempted and reverted

The slot carries **0 code and 0 data references** (raw-byte scan), and its block is Borland's
`__OVRGROUP`:

```
225d:0080  __CALLEXTEMSSWAP
225d:0082  __CALLEXTEXIT
225d:0084  __CALLEMSEXIT
225d:0086  __OVRHOOK__        (4-byte far pointer; live value 0823:0837)
225d:008a  __OVRBACKLINK__
225d:008c  __OvrExepathBuf
225d:008e  ovrHeaderReserved  (4 bytes, all zero)
```

The labels advance by 2 from `0x80` to `0x8a` while the pointer actually read by
`CALLF [0x86]` needs 4 bytes, so the surrounding naming is inconsistent and no Borland name can
be attributed to the tail slot.

Removing the symbol was tried: `RemoveSymNamed` deleted it and Ghidra immediately re-created the
address as **`uint32_t_225d_008e`**, an auto-generated data name.  That is worse than an
explicit reserved name (the naming audit does not recognise the pattern, so it would silently
pass), so the symbol was restored with a comment recording the 0-reference evidence.
