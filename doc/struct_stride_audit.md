# Stride audit: every `* 0xNN` in the recovered tree

Question asked: in `(*(uint16_t *)(iVar2 + uVar3 * 0x37 + 2))`, is `0x37` a
struct size or a matrix row stride?

Method: took the committed tree (`git archive HEAD src/decompiled`), collected
every `<expr> * 0xNN` with a non-zero constant, and compared each constant with
(a) the size the recovered `st_types.h` structs actually have and (b) the element
sizes recorded for the corresponding data symbols.

52 distinct strides, 3355 occurrences. The ten most frequent:

| stride | uses | what it is | verdict |
|---|---|---|---|
| 0x34 | 897 | **agent record** (`agnt_t`) | model `agnt_t` = **46**, stride 52 → **6 bytes short** |
| 0x37 | 506 | **entity record** = agent record + `tick`(2) + `dir`(1) | model `entity_t` = **49**, stride 55 → **6 bytes short** |
| 0x95 | 420 | generic-agent/menu record (`agntG_t`) | model `agntG_t` = **131**, stride 149 → **18 bytes short** |
| 0x27 | 39 | 39-byte record (`BuildingTypes` region) | matches the recorded element size 39 |
| 0x12 | 18 | frame record `frm_t` / `grec_t` | matches (18) |
| 0x0c | 12 | `bld_inst_t` | matches (12) |
| 0x1e | 30 | `anm_t` | matches (30) |
| 0x140 | 41 | **VGA scanline**, 320 bytes | row stride, not a struct |
| 0x13 | 19 | `squarerec_t` | matches (19) |
| 0x21 | 23 | `bldtp_t` | matches (33 = 0x21) |

So: **`0x37` is a struct size**, not a row stride — it is the entity record, and
`0x34` is the agent record embedded in it. The row strides are the large ones
(`0x140` = 320 = screen width, `0xa1` = 161 = the FillGrid row).

## The three mismatches are real defects

`agnt_t` field offsets up to 0x2d agree with the code (`frames` at 0x13, the
6-byte tail is the gap):

```
model agnt_t : ... faction(41)  state(42..43)  flags32(44..45)   -> 46 bytes
code stride  : 0x34 = 52                                         -> 6 bytes used
```

Those six bytes are all addressed individually by the original code:

```
0x2e  *(char  *)(... + 0x2e) == 4        ovc27_combat
0x2f  *(char  *)(i*0x34 + 0x2f) == 0     ovc14_attact
0x30  *(undefined1 *)(Entities + i*0x37 + 0x30) = 0
0x31  *(undefined1 *)(index*0x34 + 0x31)          ovc12_agnt
0x32  *(byte *)(u + 0x32) < *(byte *)(i*0x34 + 0x22)   ovc15_sprite
0x33  (*(byte *)(ent*0x37 + 0x33) & 1) == 0       ovc13_panel
```

Consequence: 256 sites index `...[i].base.` through `entity_t` and 23 through
`Entities[i]`. With `sizeof(entity_t)` = 49 instead of 55, **every one of those
accesses reads and writes 6 bytes too early per element.** A rebuilt exe would
not match the original data state for that reason alone.

`agntG_t` is 18 bytes short by the same argument (stride 0x95 = 149 vs 131), and
its internal offsets disagree with the comments already in the model
(`dmgBonus` cited at +0x39 but laid out at 0x2a), so the missing bytes are
*inside* that struct, not at its end.

## Planned fixes (in the Ghidra project, not the dump)

1. `agnt_t`: append six byte fields at 0x2e..0x33 (`unk2e`..`unk33`, each with
   the reader/writer quoted in its comment) so the layout is 52 bytes and
   `entity_t` becomes 55 automatically.
2. `agntG_t`: recover the 18 missing bytes from the cited offsets (+0x39, +0x3b,
   +0x40) before touching anything else, because a tail pad there would leave
   every field after the gap misaddressed.
3. Re-run this audit after each change; the table above is the acceptance test
   (stride == struct size for every struct-typed stride).

The script that produced the numbers is `tmp/strides.py`; the struct sizer is
`tmp/structsizes2.py`; the tail-byte evidence is `tmp/agnttail.py`.
