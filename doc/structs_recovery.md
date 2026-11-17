# Structure recovery ledger

Each structure is rebuilt from the code that allocates and accesses it.  A field
is only named when a use fixes its meaning; the remaining generated names are
listed at the end.

## `spr_t` - done (was 166 fields, 164 generated)

Evidence, `ovc15` (`stshRleAnims`, `stshStoreSprite`):

```c
psVar3 = (spr_t *)StshSprites + StshSprIndex;
_fsetmem((spr_t *)CONCAT22(psVar3,psVar2),0xb0,0);      /* clears 176 bytes */
...
psVar2->frames[bVar1 - 0x16].seg = uVar4;
(psVar2->frames + (bVar1 - 0x16))->ofs = (uint16_t)(panms + i);
...
pframe.seg = pofs->frames[bVar1].seg;
pframe.ofs = (pofs->frames + bVar1)->ofs;
```

- `0xb0` = 176 is the record size.
- `frames[i]` is addressed as `.seg`/`.ofs`, i.e. an array of `far_t`.
- 176 - 4 (the far `anm_t *anm` pointer at offset 0) = 172 = 43 x 4.

Result (`RebuildSpr.java`):

```
+0 anm    : anm_t * (4-byte far pointer)
+4 frames : far_t[43]
length    : 176
```

The 164 one-byte `undefined` members were an artifact of the decompiler not
seeing the array; they are gone.

## `agnt_t` - in progress (52 bytes, 28 generated fields)

The record is the base of `entity_t`:

```c
/* entity_t is agnt_t plus three bytes: 33000 / 600 = 55 */
struct entity_t { struct agnt_t base; byte reserved[3]; };
```

Evidence: `ovc22` indexes `((entity_t *)Entities)[uVar7].base.field_0xa`, and
`Entities` is allocated with `stshAlloc(33000)`, i.e. 600 records of 55 bytes.
The decompiler therefore prints `...base.field_0xNN`, which makes the field
uses readable without any guessing.

Field uses found in the export (`.base.field_0xNN`, count of distinct sites):

| offset | observed use | status |
|---|---|---|
| `0x0c` | set to `0xff`; `& 1` tested; `+ 0xfe` used as index | unnamed |
| `0x0d` | `base + field_0xd * 0x95 + 0x1f` (stride of the 149-byte records) | **`gindex`** |
| `0x0e` | `(field_0xe + 0xf) / 0x10`, `field_0xe * field_0xf * field_0xf` | unnamed |
| `0x0f` | compared and multiplied with `0x0e` | unnamed |
| `0x10` | 16-bit, set to 0, tested `== 0` | unnamed |
| `0x12` | 16-bit, set from `*(undefined2 *)(iVar5 - 2)` | unnamed |
| `0x13` | 4-byte value, byte at +1 tested with `& 1` | unnamed |
| `0x17` | 4-byte value; `agnt_3b1d_0c9f` dereferences it and reads `+0x36` | unnamed |
| `0x2b` | only ever masked: `& 0xae4`, `& 0xfff5` | **`flags`** |
| `0x2f` | set to 0 in `attact`; compared between two entities | unnamed |
| `0x30` | byte at +1 written from a scan | unnamed |
| `0x32` | byte at +1 tested with `& 1`, `& 2`, `| 8` | unnamed |

`agnt_3b1d_196b` reads the segment in its prologue:

```
MOV DX,0x1726          ; agent data segment
MOV AX,word ES:[BX + 0x19]
MOV DX,word ES:[BX + 0x17]
CMP AX,[BP + 8]
CMP DX,[BP + 6]
```

so the array base is segment `0x1726` with stride `0x34`, and the pair at
`0x17`/`0x19` is one four-byte value compared against a caller-supplied far
pointer.

### Applied this pass

- `0x0d` -> `gindex`, `0x2b` -> `flags` (`RenameFields.java`).
- Ten functions take the record as a typed parameter (`TypeAgentParams.java`):
  `agnt_3b1d_0a53`, `0a8d`, `0a9f`, `0ac0`, `0d1c`, `0d82` as `agnt_t *agnt`;
  `0c7c`, `0c9f`, `0cc6`, `0cef` as `entity_t *ent` because they touch `+0x36`.

The typed view now decompiles as:

```c
void __cdecl16far agnt_3b1d_0a53(agnt_t *agnt)
{
  paVar1->field_0xe = 0xff;
  paVar1->field_0xc = 0xff;
  paVar1->field_0x10 = 0x0;
  paVar1->gindex = 0x0;
  paVar1->flags = paVar1->flags & 0xfff5;
  ...
}
```

## `agntG_t` - rebuilt (149 bytes, 13 generated fields left)

The generic-agent records are **not** in DGROUP: `ovc15` stores the pointer into
the agent record as a segment and an offset pair:

```c
*(undefined2 *)(agent + 0x1f) = 0x195d;                  /* segment */
*(int *)(agent + 0x1d) = bVar3 * 0x95 + 0x26d6;          /* offset  */
```

The record was rebuilt from every offset reached through `agnt_t->gdata`
(`0x1d) + 0xNN` in the export): `0x1b..0x23`, `0x38..0x3c`, `0x3e`, `0x40`,
`0x42`, `0x46`, `0x50`, `0x51`, `0x53`.

The nine bytes at `0x1b..0x23` are three identical triples used by three draw
paths as (left offset, right offset, half height):

```c
iStack_a = ((g->0x1b + frm->x + *param_1) >> 1) - 1;
iStack_c = iStack_a + ((g->0x1c - g->0x1b) >> 1);
...        iStack_8 <= (g->0x1d >> 1);
```

with the same shape at `0x1e/0x1f/0x20` (`ovc49`) and `0x21/0x22/0x23`
(`ovc12`).  They are one field, `sbyte extents[3][3]`.

The three 16-bit values that the old layout had split into single bytes are now
words; `0x3c` is `flags` because it is only ever masked (`&1, &2, &4, &0x20,
&0x800`), `0x40` is only tested with `& 4`.

```
+0   ai        byte            +27  extents  sbyte[3][3]
+1   type      byte            +36  name     char *
+2   nanims    sbyte           +40  anms     anm_t *
+3   sprs      spr_t *[6]      +44  sprfls   short[6]
+56  0x38..0x3b   four unread bytes
+60  flags     word            +62  word     +64  word
+66  0x42 state byte           +67  reserved_43[3]
+70  0x46 state byte           +71  reserved_47[9]
+80  0x50 state byte  +81 -1 sentinel  +82  +83
+84  prtfls short[6]  +96 prts far_t[6]  +120 prtpals far_t[6]
+144 wpn_name char *  +148 byte
length 149
```

The decompiler now resolves the chain without casts:

```c
paVar1 = ((agnt_t *)agnt)->gdata;
if ((paVar1->field14_0x40 & 4) == 0) agnt_3b1d_0a53(agnt);
```

## `agnt_t` - additions

| offset | evidence | name |
|---|---|---|
| `0x1b` | compared against an index into `Entities`: `*(int *)(i * 0x34 + 0x1b) == param_1` | `owner` |
| `0x1d` | holds `195d:26d6 + gindex * 0x95` | `gdata` (`agntG_t *`) |

## Remaining structures with generated field names

| structure | size | fields | generated |
|---|---|---|---|
| `/st.h/agntG_t` | 149 | 28 | 13 |
| `/st.h/agnt_t` | 52 | 32 | 26 |
| `/st.h/bldtp_t` | 39 | 26 | 14 |
| `/st.h/anm_t` | 30 | 24 | 12 |
| `/st.h/unk01_t` | 6 | 3 | 3 |

73 fields in total still carry `field_0xNN`; each needs the same treatment
(allocation size or access pattern), not a guess.

### `bldtp_t` - rebuilt (39 bytes, 11 generated fields left)

`BuildingTypes` is at `195d:010e` and the code indexes it as
`*(T *)(idx * 0x27 + 0x10e + off)`, which gives a complete field map: `0x00`,
`0x02` (name halves), `0x04`, `0x06` (description), `0x08`, `0x0a` (action),
`0x0c`, `0x0d`, `0x0e`, `0x0f`, `0x10` (bits 0 and 1 tested), `0x11`
(`1 << n` mask), `0x12`, `0x13` (masked with `0x20` and `0x800`), `0x15`
(signed compare), `0x17`, `0x19` (accumulated), `0x1c`, `0x20`, `0x22`
(`100 - x`), `0x23` (compared with 1, 2, 3), `0x24`, `0x25`, `0x26`.

The earlier note that the stride was wrong was an arithmetic mistake: element 12
start is `0x010e + 12*0x27 = 0x2E2`, so its `0x1e` field is at `0x300`, exactly
where Ghidra labelled it.  The rebuild confirms it - the relabelled data still
reads `BuildingTypes[0].flags2` at `195d:0121` (= base + `0x13`) and
`BuildingTypes[12].field17_0x1e` at `195d:0300`.

Two fields became typed instead of split bytes: `flags` at `0x10` (bits tested)
and `flags2` at `0x13` (a word masked with `0x20`/`0x800`).  The eleven bytes
that remain unnamed have only a comparison each (`== 2`, `< 2`, `< 3`,
`!= 0`, `& 0x80`), which fixes their width but not their meaning.

### `anm_t`

Bytes 16..26 and 29 have **no reader in the export**: every `* 0x1e + offset`
access lands on 0, 3, 9, `0x1b` or an already-named field.  They are asset-file
bytes, so only the format documentation could name them.
