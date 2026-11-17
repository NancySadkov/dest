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

## Remaining structures with generated field names

| structure | size | fields | generated |
|---|---|---|---|
| `/st.h/agntG_t` | 149 | 49 | 38 |
| `/st.h/agnt_t` | 52 | 32 | 28 |
| `/st.h/bldtp_t` | 39 | 26 | 14 |
| `/st.h/anm_t` | 30 | 24 | 12 |
| `/st.h/unk01_t` | 6 | 3 | 3 |

100 fields in total still carry `field_0xNN`; each needs the same treatment
(allocation size or access pattern), not a guess.
