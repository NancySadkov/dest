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
