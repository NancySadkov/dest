# Step 5: the `_fmemset` call sites

`_fmemset` was declared with a near pointer, so every call pushed 6 bytes where
the original pushes 8.  The prototype (and the recovered definition) now use
`void far *`, and the call sites are being rewritten one function at a time from
the disassembly.  `tmp/asm_*.txt` holds the dumps.

## Done

| function | calls | form |
|---|---|---|
| `ovc22_textRingProt` | 6 | `MK_FP(_SS,&uStack_28/_2e/_a/_42)`, `MK_FP(GUnitDescriptions[p].seg, ofs+0x9a)` |
| `ovc23_textAdlibNone` | 2 | `MK_FP(_DS, 0x91d7)`, `MK_FP(_DS, 0x90ea)` |
| `ovc23_usesGRecordCount3` | 1 | `MK_FP(_SS,&uStack_4)` |
| `ovc24_checkStrongholds` | 2 | `MK_FP(_SS,&uStack_10)` |
| `ovc17_stshInit` | 2 | `MK_FP(0x1ef4, 0x2420)`, `MK_FP(0x1ef4, 0x0880)` |
| `ovc17_initStshTables` | 1 | `MK_FP(0x1ef4, 0x0880)` |

Segment `1EF4h` is a fixed buffer segment (the stash area), so `MK_FP` with the
literal is exact - Ghidra had packed it as `0xffff1ef4` (`1EF4:FFFF`), and the
pushed offset is `2420h`/`0880h`.

## `ovc49_fillGridCells` - decoded, not applied

Five calls, all the same shape (`8699:1805...1822`):

```
MOV AX,[BP-2] / SUB AX,SI / INC AX      ; count
PUSH AX
MOV AL,[BP+6] / MOV AH,0                ; value
PUSH AX
MOV AX,DI / IMUL 69h / ADD AX,SI / ADD AX,<base>
PUSH 1726h                              ; segment
PUSH AX                                 ; offset
CALLF _fmemset / ADD SP,8
```

with `<base>` = `8fa`, `963`, `4e0`, `549`, `5b2`.  So each is

```
_fmemset(MK_FP(0x1726, DI*0x69 + SI + base), amount, (BP-2 - SI) + 1);
```

The recovered C has

```
_fmemset((void *)(ulong)CONCAT12(count,(int)&AgntAnms[0x75].halfWidth + 1),
         (iStack_4 - iVar4) + 1, unaff_DI);
```

i.e. the far pointer was rebuilt from a segment variable and a DGROUP address
instead of `1726h:<computed>`, and the value (the byte parameter) was replaced
by `unaff_DI` while the count took its place.

Applying it needs the DI/SI to C-variable mapping inside the loop: the count
expression `(iStack_4 - iVar4) + 1` matches `[BP-2] - SI + 1`, so `SI` is one of
them, but the `DI*0x69` row term has no identified C local yet.  Guessing it
would silently produce a wrong destination, so the call is left until that
mapping is established.

## Second batch

| function | asm | form |
|---|---|---|
| `ovc18_showLeaderView` | `48ac:0079` | `MK_FP(_SS,&pcStack_6), 0, 2` |
| `ovc30_createLeader` | `619c:041e` | `MK_FP(uStack_4,(uint16_t)pcStack_6), 0, 0xae` |
| `ovc26_usesFillGrid` | `5d45:000c` | `MK_FP(FillGrid>>16, FillGrid), 0, 0x6541` |
| `ovc14_attact` | `3f0b:1092` | `MK_FP(_SS,&uStack_c), 0, 5` |
| `ovc22_textRingProt` (2nd) | `5087:06da` | `GUnitDescriptions[p].ofs + 0xAA` (was 0x9A) |
| `ovc34_textDefineRegionCommand` | `6616:0dbc` | `MK_FP(_SS,&unitFlags), 0, 5` |
| `ovc27_usesRandBelow5` | `5ded:0975` | `MK_FP(_SS,&indexMap), 0, 0xf` |
| `init_usesClearEntities` | `3381:223a` | `MK_FP(_DS,&promotionBandUsed), 0, 2` |

Details worth keeping:

* `ovc22_textRingProt`'s **second** `GUnitDescriptions` fill targets `ofs + 0xAA`
  (`5087:06da ADD AX,0xAA`), not `0x9A` like the first one - the two had been
  given the same offset.
* `ovc26_usesFillGrid` pushes `[0x91ea]:[0x91e8]`, and the DGROUP map has the
  4-byte far pointer `FillGrid` at `0x91e8`, so the destination is that pointer.
* `init_usesClearEntities` pushes `2410h:-6D33h` = DGROUP:`0x92CD`, which the
  DGROUP map names `promotionBandUsed` (2 bytes).
* `ovc34_textDefineRegionCommand` clears 5 bytes that the C already indexes as
  `(&unitFlags)[i]`, `i = 0..4` - the array base is the memset target.
* `ovc27_usesRandBelow5` likewise: `(&indexMap)[i]`, `i = 0..0xe`.

Sites where the destination is a **far pointer held in a local** whose nearest
declared local in the recovered C is a near pointer (`ovc26_usesStExit`,
`ovc42_run_demo`, `ovc04_lbm`, `ovc20_stash`) are not converted yet: the C
itself writes through those near pointers (`peVar11->base`), so the fix is to
make the pointer far, not just the memset call.

## Far-pointer-in-near-local: `ovc26_usesStExit`

The entity pointer is far in the original: the prologue does

```
5d45:0334  MOV DX,word ptr ES:[0x9090]      ; segment
5d45:0339  MOV BX,word ptr ES:[0x908E]      ; offset
5d45:033a  ADD BX,AX                        ; + entityIndex * 0x37
5d45:0340  MOV [BP-0x6],DX / MOV [BP-0x8],BX
```

and every later access is `LES BX,[BP-0x8]`.  So `Entities` (DGROUP 0x908E) is a
**4-byte far pointer** whose segment half Ghidra exported separately as the
1-byte `DAT_2000_d190` at 0x9090.

Fixed:

* `entity_t far *Entities` (declaration + definition).  The initialised DGROUP
  bytes are now `c0 10 f4 1e` (offset 0x10C0, segment 0x1EF4), i.e. the whole
  pointer, where before only the offset was written.
* `peVar11` in `ovc26_usesStExit` is `entity_t far *`; the duplicate `uStack_a`
  (the same entity rebuilt with `CONCAT22(DAT_2000_d190,...)`) is gone, and the
  memset is
  `_fmemset(MK_FP(ST_SEG(peVar11), ST_OFF(peVar11) + 0x1b), 0, 0x14);`
  which is exactly the pushed `SS`-based pair in the disassembly.
* `ST_SEG`/`ST_OFF` added to `st_compat.h` (`dos.h` cannot be included
  everywhere).

Build note: `st_compat.h` must keep CRLF line endings.  Rewriting that header
with LF-only endings made BCC 3.0 report `Illegal character '#'` at its first
`#if`, which is why the edit is now done in place before the final `#endif`.

## The allocator returns a far pointer: `ovr_stshAlloc` is `void far *`

`undefined` is `unsigned char` in `st_types.h`, and `ovr_stshAlloc` was declared
`undefined ovr_stshAlloc();`.  Every one of its 362 call sites therefore used
only **AL** of the returned `DX:AX`, and the segment was recovered by Ghidra as
a separate `in_DX` local that our rebuild never assigns - so the high half of
every such pointer was garbage.

Declaring `void far *ovr_stshAlloc();` fixes the ABI at all call sites: the
compiler now keeps `DX:AX`.  Seven sites needed real edits because they wrote
the two halves by hand:

| site | now |
|---|---|
| `ovc09_init.init_buffers` | `GUnits/GUnitGrid/GMapFlags/GMapCells/Entities = ovr_stshAlloc(...)`, `FillGrid = (uint32_t)ovr_stshAlloc(...)`; the `in_DX` stores are gone |
| `ovc15_sprite.allocSprSeqs` | `StshSprites = ovr_stshAlloc(0x3650)`, and `StshSprites` is now `spr_t far *` |
| `ovc04_lbm.lbm_decode_body` | `buf = (uint32_t)ovr_stshAlloc(0xfa0f)` (the slot already had two halves) |
| `ovc29_anim.animInitSeqs` | `p = (uint32_t)ovr_stshAlloc(...)` |
| `ovc43_fli` / `ovc12_agnt` | `tempScreenOfs/tempScreenSeg` and `ptr` split from the far result with `ST_OFF`/`ST_SEG` |
| `ovc06_blit.stshRleSub` | keeps the size in the high word, so only the offset is stored (cast) |
| `ovc20_stash.stshStoreFile_2` | `void far *p = ovr_stshAlloc(...)`; `_fmemset(p,0,v)`, `read(fd,p,v)`, `buf.seg = ST_SEG(p)` |

`read` also takes a far buffer now (`void far *buf`), which is what the DOS
handle read needs; the recovered definition in `crtl.c` was updated with the
prototype.

`ovc20_stash.stshStoreFile_2` is the one this session set out to fix: it had
`_fmemset((void *)ZEXT24(plStack_c), v, unaff_DI)` where `plStack_c` is the
*file length*, plus `read(fd, CONCAT22(v, plStack_c), ...)` and
`buf.seg = (uint16_t)plStack_c`.  All three now use the allocator's pointer.

## `GLeaderSheets` is the table behind `*(u16*)(i*4+2)` (four sites)

The remaining table-indexed memsets were identified with a new Ghidra pass,
`scripts/ghidra/ListMemsetCalls.java`, which lists **every** `_fmemset` call
site with its containing function and the arguments pushed before it.  That
also proved the C contains 52 calls where the original has only 43 - nine are
duplicated by Ghidra's merged bodies.

The two in `upd_usesAlignUp4` (`5087:2AB9` and `5087:2ADE`) push

```
6A 06        push 6            ; count
6A 00        push 0            ; value
8B 5E EC     mov bx,[bp-0x14]  ; leader index
C1 E3 02     shl bx,2
B8 7A 21     mov ax,217Ah      ; segment
8E C0        mov es,ax
26 ...       mov ax,es:[bx]    ; sheet offset
05 6A 00     add ax,0x6A       ; / 0x76 in the second call
26 ...       push es:[bx+2]    ; sheet segment
```

`217Ah` is the segment of `GLeaderSheets` in `audit/symbols.tsv`
(`217a_DATA_game7`), whose DGROUP declaration in this tree was an array of
*near* pointers.  `GLeaderSheets` is now `char_sheet_t far *GLeaderSheets[80]`,
and the four calls (two in each merged copy) are

```c
_fmemset((char far *)GLeaderSheets[idx] + 0x6a, 0, 6);
_fmemset((char far *)GLeaderSheets[idx] + 0x76, 0, 6);
```

Note the segment is a link-time constant with a relocation, not a literal: a
hard-coded `0x217A` would move with nothing at run time.

## `GRecords` is an array of 0x12-byte records

The original keeps the construction records in their own data segment
(`21F2h`, block `21f2_DATA_game10`, labels `GRecords.*`), stride `0x12`, at most
`0x32` entries (the code guards with `if (0x31 < GRecordCount)`).

The tree had a single near `grec_t GRecords` and addressed records as
`GRecordCount * 0x12 + N`, i.e. DGROUP offsets.  Now:

* `grec_t GRecords[0x32]`;
* the two memsets are `_fmemset(GRecords + GRecordCount, 0, 0x12)`, which
  reproduces the pushed arguments exactly (count `0x12`, value `0`, far pointer
  `21F2h:GRecordCount*0x12`);
* the 44 field accesses became
  `*(T *)((uint8_t *)&GRecords[GRecordCount] + N)`.

The three `ovc19_save.c` uses are left alone: they are part of the save/load
path where every buffer segment arrives through `unaff_DI`, the same systemic
problem as `Entities`.

Status: 42 of 52 call sites converted.  The ten left split into

* four phantom duplicates (the C has 52 calls, the original 43) whose containing
  function has no `CALLF _fmemset` at all (`ovc25_intel`, `ovc43_fli`, and the
  copies inside merged bodies) - these should be removed by splitting the merged
  function bodies, not rewritten;
* six whose destination is a stack slot that the recovered declaration list does
  not name at that offset (`ovc24_textKill` x3 at `[BP-0x2a]/[BP-0x20]/
  [BP-0x22]`, `ovc38` at `[BP-0x80]`, `ovc42` at `[BP-0x76]`, `ovc41`, `ovc49`).

## Batch: ovc42 record, ovc24 timers, ovc38 menu array

Three sites were resolved by identifying the stack object from its later uses,
not by guessing a name:

* `ovc42_showAgentStats` clears `0x34` bytes at `[BP-0x3e]` and `0x37` at
  `[BP-0x76]`.  The field stores settle the mapping: `gindex` at `[BP-0x69]`,
  `animFrame` at `[BP-0x68]`, the entity pointer's `+3` at `[BP-0x5c]`, flags at
  `[BP-0x60]` - all `BP-0x76` plus the `agnt_t` offset, so the 0x37-byte record
  is `agntRec` and the 0x34-byte one is the temp passed to `ovr_drawAgntStats`.
  `agntRec` is now an `entity_t`, `agntTmp` an `agnt_t`.
* `ovc24_textKill` clears 8 bytes at `[BP-0x2a]` and two 2-byte slots at
  `[BP-0x20]`/`[BP-0x22]`.  `5943:0373` indexes the first with `BX = faction*4`
  and does a 32-bit `ADD SS:[BX],AX / ADC SS:[BX+2],DX`, and the reads at
  `5943:058d` take the high word from `[BP-0x28]` and the low from `[BP-0x2a]`:
  two 32-bit per-faction timers.  The two 2-byte slots are indexed by faction as
  bytes (`LEA DX,[BP-0x22] / ADD AX,DX`) and filled with `0xFF81`.
* `ovc38_showAchievements` clears 0x28 bytes at `[BP-0x80]` and then passes
  `SS:[BP-0x80]` to `ovr_uiMenu` with `nitems = 8`; entry 7 (`+0x1C`) is set to
  `s_done` (`0x6AB4`) with DS as its segment.  So the buffer is ten `far_t`
  menu items, and the call is `uiMenu(0, 0, items, SS, 8)`.

## Where the pass stands

`52` text sites, of which `47` are converted.  The original has **43**
`CALLF _fmemset` instructions, so the five left are:

| site | status |
|---|---|
| `ovc04_lbm.grabLbm` (`30e6:03a6`) | the only genuine one left: its `dst` local is still a near `stg_tmp_t *` while the original keeps the allocator's far pointer at `[BP-0x2e]/[BP-0x2c]`, and the surrounding "high word = segment" line has no asm counterpart |
| `ovc25_intel`, `ovc41_main`, `ovc43_fli`, `ovc49_agents` | **phantom duplicates**: their containing functions are 36-150 bytes and contain no `CALLF _fmemset` at all.  Ghidra merged a callee's body into the caller, so the statement exists only in the export.  Removing it is only correct together with splitting the merged body. |
