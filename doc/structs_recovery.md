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

## Agent hit test (`agnt_3b1d_00ce`)

Its signature is now `(agnt_t *agnt, uint8_t *result)`; `param_2` was evidently
the output pointer because the body ends with

```c
*param_2 = *(undefined1 *)(row * 0x69 + col + 0x8fa);
```

The function walks the columns between the frame extents and the rows around
`agnt->y >> 1`, testing two grids at DGROUP offsets `+0x8fa` and `+0x4e0`
(stride `0x69` = 105 columns, 10 rows).  It accepts a cell's agent index when

```c
*(char *)(idx * 0x34 - 5)  != agnt->0x2f     /* different faction */
*(char *)(idx * 0x34 - 0x10) == 0            /* and the 0x24 flag is clear */
```

so `agnt_t+0x2f` is the agent's **faction** (now named) and `+0x24` a state
byte.  The two tables are indexed with a 0x69 (105) stride, but the expressions
carry only an offset (0x4e0, 0x8fa), not a segment; `0x4e0` is also the address
of `MiceUnkState`, so these are offsets inside a segment the decompiler dropped,
not DGROUP globals.  They must not be turned into DGROUP symbols.

The function's remaining stack slots are decompiler artifacts at positive
offsets (beyond the two parameters), so they cannot be named until its stack
model is fixed.

## Animation cursor (`agnt_t+0x0e`, `anm_t+0x1a`)

```c
*(char *)(rec + 0xe) = *(char *)(rec + 0xe) + 1;
if (*(byte *)(anm + 0x1b) <= *(byte *)(rec + 0xe))
    *(byte *)(rec + 0xe) = *(byte *)(anm + 0x1a);
```

`anm+0x1b` is `nframes`, so the record byte at `0x0e` is the animation frame
cursor (`animFrame`, `0xff` = no animation) and `anm+0x1a` is the frame it is
reset to (`startFrame`).

## `agnt_t+0x17` and `entity_t+0x36`

`agnt_t+0x17` is a far pointer to the agent's `entity_t`.  The callers build the
argument to `agnt_3b1d_196b` from the entity array

```c
ptr.seg = Entities.seg;
ptr.ofs = (entity_t *)Entities + index;
ovr_agnt_3b1d_196b(ptr);
```

and the function compares `*(int *)(agent + 0x17)` and `*(int *)(agent + 0x19)`
against it, so the four bytes at 0x17 are that pointer.  With the field typed,
the decompiler resolves the chain:

```c
byte __cdecl16far agnt_3b1d_0c9f(entity_t *ent)
{
  entity_t *peVar1 = ((entity_t *)ent)->base.entity;
  bVar2 = ((entity_t *)peVar1)->reserved[2] % 6;   /* byte 0x36 */
  if (3 < bVar2) bVar2 = bVar2 - 6;
  return bVar2;
}
```

The value reduced modulo 6 into -3..3 is the sprite direction, so
`entity_t+0x36` (the third byte of `reserved`) is a **direction**, not reserved.
`entity_t` still carries `byte reserved[3]`; the next step is to rebuild it as
two unnamed bytes plus `dir`.

## `entity_t` rebuilt, `agnt_t+0x0c` named

```
entity_t (55 bytes)
  +0  base        agnt_t
  +52 field_0x34  byte   (shifted left in ovc22)
  +53 field_0x35  byte   (no reader yet)
  +54 dir         byte   (sprite direction)
```

`reserved[3]` was hiding three unrelated bytes; the audit now counts two of
them as generated, which is the honest reading.

`agnt_t+0x0c` is a direction.  The attack code computes the sign of the step it
is about to take and encodes it as `2 - sign`:

```c
iStack_12 = OVC07_32c9_0026(entity.field_0x8 - other->x);   /* -1, 0, 1 */
entity.x += iStack_12;
entity.field_0xc = 0x2 - iStack_12;                          /* 1..3 */
func_0x0004f412(..., '\x02' - iStack_12, ...);
```

Readers shift it back (`field_0xc + 0xfe` = value - 2) and test its low bit;
`0xff` is the "none" value written by the clear-orders routine.  The vertical
branch uses the same encoding with `dy + 1` (0..2).

## `agnt_t+0x10` = `health`

The entity constructor writes 100 into it and reloads it from a per-type table
(`*(undefined2 *)(table + type*4 - 4)`); the idle predicate tests the dying
range:

```c
if (paVar2->animFrame == 0xff) {
  if ((char)paVar2->health < 2) return 1;
  else if (paVar2->health == 4) return 1;
}
```

It stays a byte in the structure because the readers use `*(char *)`; the
16-bit initialisation is a word store over `0x10..0x11`.

## `agnt_t` coordinates from the constructor

`OVC15_4207_10a3(x, y, tx, ty, gindex, param6, param7)` fills a fresh record:

```c
field_0x4 = tx;  field_0x6 = ty;
if (tx == x && ty == y) { field_0x8 = 0; field_0xa = 0; }
else                    { field_0x8 = tx; field_0xa = ty; }
x = x;  y = y;
field_0xc = 0xff;              /* dir = none */
field_0xd = gindex;            /* the generic-agent index */
field_0x10 = 100;              /* health */
field_0x12 = 0;
field_0x13.hi + 1 = 0;         /* the word at 0x16 */
```

so `0x4`/`0x6` are the requested target and `0x8`/`0xa` the destination actually
used (zero when the target is the square the agent already stands on).  All
four are named.

The constructor also copies the generic record's byte `0x1a` into the record's
`0x31` and `0x32`, and sets `0x33` to 2, which is why those bytes appear in the
0x30 group.

## More typed agent helpers

`agnt_3b1d_0079` reads the record's `y`, `x` and `0x25` before delegating, so it
is another `agnt_t *` consumer:

```c
undefined1 __cdecl16far agnt_3b1d_0079(agnt_t *agnt)
{
  if (((((int)paVar3->y < 0x15) || (paVar3->field_0x25 == 1)) &&
       ((int)agnt->x < 0xd3)) && (-1 < (int)agnt->x)) {
    iVar2 = ovr_OVC49_8699_06dc((int *)paVar3);
```

The bounds (`x` in 0..210, `y` in 0..20) are the agent map extent.

Typed record-taking functions: 13 of the 34 in `ovc12_agnt` (`agnt_t *`:
`0032`? no - `0079`, `00ce`, `0a53`, `0a8d`, `0a9f`, `0ac0`, `0d1c`, `0d82`;
`entity_t *`: `0c7c`, `0c9f`, `0cc6`, `0cef`).

## The generic-record base is settled: `195d:26d6`

The constructor's load disassembles to

```
4207:1255  MOV AL,byte ptr [BP + 0xe]    ; the gindex argument
4207:1258  MOV AH,0x0
4207:125a  MOV DX,0x95
4207:125d  IMUL DX
4207:125f  MOV DX,0x195d                 ; segment
4207:1262  MOV BX,AX
4207:1266  MOV AL,byte ptr ES:[BX + 0x2711]
4207:127b  MOV byte ptr ES:[BX + 0x31],AL
```

so the byte is at `195d:2711 + gindex * 0x95`.  The other function stores the
record pointer as `gindex * 0x95 + 0x26d6`, and `0x2711 - 0x26d6 = 0x3b`.
Therefore:

- the records are at **`195d:26d6`**, stride `0x95`;
- the field the constructor reads is **`agntG_t+0x3b`**, not `+0x1a`.

The `+0x1a` in the decompiled line was arithmetic relative to the symbol at
`2410:26f7` (`0x26f7 + 26 = 0x2711`), which is correct but misleading: the
access uses the entity segment, not DGROUP.

`agntG_t+0x3b` is a byte: the constructor copies it into both `agnt_t+0x31` and
`agnt_t+0x32`, and `ovc41` copies it into an agent's `+0x21`.  Those three
targets are drawing extents, so the byte is a size/scale, but its exact meaning
is not pinned yet; it stays unnamed rather than guessed.

## The `0x3b` size byte and the record's `0x21`/`0x22`/`0x31`/`0x32`

Consumers of the byte at `agntG_t+0x3b`:

```c
/* constructor: copy, then a randomised variation, floored at 1 */
entity.base.field_0x31 = generic[0x3b];
entity.base.field_0x32 = generic[0x3b];
if (generic's 0x2f != -1) {
    cVar4 = agnt_3b1d_0c1e();
    iStack_6 = generic[0x3b] + cVar4;
    if (iStack_6 < 1) iStack_6 = 1;
    entity.base.field_0x31 = iStack_6;
    entity.base.field_0x32 = iStack_6;
}

/* per agent record: copied from those entity bytes */
agent[0x21] = entity.field_0x31;
agent[0x22] = entity.field_0x32;

/* then compared across agents, keeping the larger/smaller */
if (agent_a[0x22] < agent_b[0x21]) agent_a[0x21] = agent_a[0x22];
if (agent[0x22] < bVar27) bVar27 = agent[0x22];

/* attack code copies it back into an entity */
*(byte *)(x + 0x31) = *(byte *)(agent + 0x21);
```

So `0x3b` is a per-generic-agent quantity that is copied per instance, perturbed
by a random offset, floored at 1, and then min/max'ed across agents.  That fixes
its behaviour but not its unit: it is not proven whether it is a level, a size
in pixels, or a strength.  The four dependent bytes (`agntG_t+0x3b`,
`agnt_t+0x21`, `+0x22`, and the entity `0x31`/`0x32` pair) therefore stay
unnamed; naming them would be a guess.

## `agnt_t+0x21` / `agntG_t+0x3b` = `strength`

The only consumer settles the unit: `attact_3f0b_28eb(uint *faction0, uint
*others)` walks every agent and accumulates this byte into one of two 32-bit
totals, split by faction (`agent[0x2f] == 0` is the player):

```c
if ((*(uint *)(agent + 0x2b) & 0xae4) == 0) {
    if (*(char *)(agent + 0x2f) == '\0') { *faction0 += agent[0x21]; }
    else                                  { *others   += agent[0x21]; }
```

It is therefore a per-agent combat quantity that each side sums, initialised
from `agntG_t+0x3b` with a random perturbation and a floor of 1, and mirrored
back into the entity's `0x31`/`0x32` (`*(byte *)(x + 0x31) = agent[0x21]`).  Both
are named `strength`.

An observer pass (`ovc21`) keeps the smallest `agent[0x22]`, a separate byte
that is *not* this value; it stays unnamed.

## `agntG_t+0x42` = `rank`

Both consumers compare it with the ladder `agnt_3b1d_1bc1` returns (9..16 map to
9..12, 17 and above to 13+):

```c
bVar1 = agnt_3b1d_1bc1(param_2);
if      (bVar1 + 2 <  value) icon = 0xd;
else if (bVar1 + 2 == value) icon = 0xb;
else if (bVar1 + 1 == value) icon = 9;
else if (bVar1     == value) icon = 7;      /* OVC41_6a8f_0a45 */
```

and `OVC41_6a8f_0aa7` selects one of three management actions from the same
comparison.  No other code reads the byte, so its only role is a rank level.

## Correction: `agnt_t+0x0c` is `target`, not `dir`

An earlier turn named `0x0c` `dir` from writes of the form `0x2 - sign(dx)`,
which only ever produce 1..3.  `agnt_3b1d_0d82` shows what the field is used
for:

```c
iVar3 = (uint)*(byte *)(agent + 0xc) * 0x34;        /* Agents[agent->0xc] */
piVar8 = (int *)(*(int *)(iVar3 + 0x13) + (uint)*(byte *)(iVar3 + 0x12) * 4);
```

`0x0c` is multiplied by the record size and used as a base, and
`agnt_3b1d_196b` range-checks it (`param1 < agent[0x0c] <= param2`) while
`agnt_3b1d_0a53` clears it to `0xff`.  That is an index of another agent
record with `0xff` as "none"; the 1..3 writes are the index of a neighbour.
The field is renamed `target`.

The dir value used for sprite selection is `entity_t+0x36` (`dir`), which is a
separate field in a separate structure.

## What `agntG_t+0x46` actually selects

The branch it guards formats a notification; the message is in the export as a
literal (the typed export dropped it):

```c
if (((g[0x46] == 4) && (15 < entity[0xf])) ||
    ((g[0x46] == 6) && ( 8 < entity[0xf]))) {
    agnt_3b1d_0ac0(agent, buf);
    arg1 = OVC15_4207_1c16(buf);
    msg  = stsprintf(local, "%s takes half damage from spells.", arg1);
    uiNotify(msg, GSavedBlitSeg);
}
```

So `0x46` is a byte that selects *which level threshold* enables the
"half damage from spells" trait: kind 4 at level 16, kind 6 at level 9.  It is
therefore a creature/unit kind, but the only values ever tested are 4, 5 and 6
and there is no table mapping them to names, so calling it `kind` or `type`
would still be a guess.  It stays unnamed, with this evidence recorded.

Note that this also identifies `entity_t.base.field_0xf` as a **level**: it is
the value compared against 15 and 8 here, and `ovc15` uses it as
`table[field_0xf * 4]`, a per-level table.

`agnt_t+0x0f` is therefore named **`level`**: it is compared with the per-kind
thresholds (15 and 8) and used as `table[level*4]` in the constructor.  Generated
struct fields: 58.

## `SelectedAgent` and the agent's screen position

`2000:003A` (BSS `0x3a`, address `2000:ca6e`) is an agent index: it is
bounds-checked against `AgntCount` and used to read that record's position into
the crosshair blit variables:

```c
if (byte_2000_BSS_003A < AgntCount) {
    CrossBlitX = *(undefined2 *)(byte_2000_BSS_003A * 0x34 + 0x26);
    CrossBlitY = *(int *)(byte_2000_BSS_003A * 0x34 + 0x28) + -0x10;
}
```

so it is `SelectedAgent`, and `agnt_t+0x26` / `+0x28` are the record's screen
coordinates (`screenX`, `screenY`); the draw path also compares those two
across agents to order the blits.

`word_2000_BSS_06D6` and `06D8` (ovc13) are used as the first index of two
fixed-width strips (`base <= v <= base+0xf` with stride 3, and
`base <= v <= base+0x22` with stride 2), i.e. UI list origins, but which lists
is not fixed by their uses, so they stay unnamed.

## The 19-byte record list in `ovc14_attact`

`word_2410_DATA_DGROUP_0881` counts a list of `0x13`-byte records and
`0883` indexes it while one is removed:

```c
if (memcmp(0x86e, 0x2410, 0x9074, 0x2410, 0x13) == 0) { ...; return; }  /* unchanged */
if (299 < word_2410_DATA_DGROUP_0881) { compact; word_2410_DATA_DGROUP_0881 = 299; }
memcpy(buf + word_2410_DATA_DGROUP_0881 * 0x13, (uint8_t *)0x9074, 0x13);
...
_fmemmove(buf + word_2410_DATA_DGROUP_0883 * 0x13,
          buf + (word_2410_DATA_DGROUP_0883 + 1) * 0x13,
          (word_2410_DATA_DGROUP_0881 - word_2410_DATA_DGROUP_0883 - 1) * 0x13);
```

Each record is a 19-byte snapshot of the scratch record at `2410:086e`,
appended only when it differs from the previous one.  The pair is named
`AttactRecCount` / `AttactRecIndex`: what they count/index is proven, while the
payload's meaning is not (the static record at `2410:9074` is all zeroes and is
filled at run time by code outside the export's reach), so no richer name is
claimed.

## The 19-byte records are per map square

`attact_3f0b_05df` shows what the list holds.  It looks for a record whose first
two words match the current square, and appends one when missing:

```c
while (true) {
    if (word_2410_DATA_DGROUP_0881 <= uVar1) {       /* not found */
        word_2410_DATA_DGROUP_086E = GfxRndSeed;     /* square x */
        word_2410_DATA_DGROUP_0870 = GfxRndSeed2;    /* square y */
        memcpy(0x9074, &word_2410_DATA_DGROUP_086E, 0x13);
        ...;
        return;
    }
    if ((*(int *)(uVar1 * 0x13) == GfxRndSeed) &&
        (*(int *)(uVar1 * 0x13 + 2) == GfxRndSeed2)) { ... }
```

`GfxRndSeed` / `GfxRndSeed2` are the square x/y used by `ovc15`
(`entity.x <= GfxRndSeed + 1 && entity.y == GfxRndSeed2`), so the records are
keyed by map square, one 19-byte record per square, max 299.  Renamed:

| address | name | role |
|---|---|---|
| `2410:086e` | `SquareRecord` | scratch record for the current square |
| `2410:0881` | `SquareRecCount` | number of per-square records |
| `2410:0883` | `SquareRecIndex` | index during compaction |

(The earlier `AttactRec*` names are superseded by these.)

## The `06D6`/`06D8` pair is a panel grid origin

Both are read as the top-left of a cell grid that is hit-tested and converted
to screen coordinates:

```c
if (... (map flags & 8) && OVC13_3d16_1045(entity) &&
    (word_2000_BSS_06D8 <= x) && (x <= word_2000_BSS_06D8 + 0x22) &&
    (word_2000_BSS_06D6 <= y) && (y <= word_2000_BSS_06D6 + 0xf)) {
    screenY = (y - word_2000_BSS_06D6) * 3 + 7;
    screenX = (x - word_2000_BSS_06D8) * 2 + 0xef;
    cStack_3 = OVC13_3d16_0186(screenX, screenY, 0x45e, 0x2410);
}
```

So `06D8` is the first column and `06D6` the first row of a 35 x 16 cell grid
whose cells are 2 x 3 pixels on screen, drawn only for cells whose map flag has
bit 3 set and that pass the entity filter.  They are named `PanelGridX` /
`PanelGridY` (`2000:d10c` / `2000:d10a`): what they are is proven, while *which*
panel it is (minimap, roster, ...) is not fixed by this code and is therefore
not claimed in the name.

## Two 12-entry index permutations in `ovc41`

`2000:0008` and `2000:0014` are initialised from constant templates and then
permuted in place:

```c
memcpy(&byte_2000_BSS_0008, (uint8_t *)0x6e2c, 0xc);
if (((undefined1 *)&byte_2000_BSS_0008)[uVar2] == param_1) { ... }
((undefined1 *)&byte_2000_BSS_0008)[uVar2] = ((undefined1 *)&byte_2000_BSS_0008)[param_1];
```

i.e. 12-byte tables looked up and swapped entry by entry and compared with
`table[i] == i`.  Named `IndexPermA` (`2000:ca3c`, template `0x6e2c`) and
`IndexPermB` (`2000:ca48`, template `0x6e20`).  What is proven is that they are
12-entry permutations; which 12 things they order is not in this code, so that
is not claimed.

`word_2000_BSS_05EE` (ovc10) holds 0..7 and is scaled with `v * 0xff >> 3` and
`v * 0xff >> 0xb` before being handed to a draw call, so it is a small intensity
or shade level; it stays unnamed because no consumer says which of the two.

## `word_2000_BSS_05EE` = `HighlightLevel`

Its draw call settles the range.  It is handed to the ability-select blit as a
fourth colour argument, scaled to a byte:

```c
gfxRlePrepare(..., 0, 0, word_2000_BSS_05EE * 0xff >> 3, 0);
```

with the bounds `1 < word_2000_BSS_05EE` and `7 < word_2000_BSS_05EE` elsewhere.
Eight levels scaled by `*0xff>>3` cover 0..223, i.e. an intensity, not an index;
the neighbouring `*0xff>>0xb` term is always zero for a 0..7 value and is a
decompiler artefact of the packed argument.  Named `HighlightLevel`
(`2000:d022`).

## `agnt_t+0x2e` = `variant`

A 0/1 selector used as a table index, not a boolean state:

```c
*(byte *)(agent + 0x2e) = 0;   /* or 1 */
... (*(byte *)(agent + 0x2e) * 0x21 + -0x16) ...      /* 0x21 = 33-byte records */
```

The value picks one of two 33-byte records, and the clear-orders routine resets
it to 0, so it selects a variant of the agent.

## Open question: is `entity_t.base` really `agnt_t`?

The layout cannot be fixed by widening or narrowing bytes, because two
16-bit fields overlap:

- the constructor ORs a word at `0x16`:
  ```
  4207:13c8  OR word ptr ES:[BX + 0x16],0x1
  4207:13f7  OR word ptr ES:[BX + 0x16],0x1
  ```
  on `((entity_t *)Entities)[EntityCount].base`;
- `agnt_3b1d_196b` compares a word at `0x17` of the *other* record array
  (`ES = 0x1726`, stride `0x34`):
  ```
  197a  MOV DX,0x1726
  1981  MOV AX,word ptr ES:[BX + 0x19]
  1986  MOV DX,word ptr ES:[BX + 0x17]
  ```

Both arrays are indexed by 0x34/0x37 strides, but a word at `0x16` in the
entity and a word at `0x17` in the 1726 array cannot both hold unless the two
records have different layouts.  So `entity_t.base` may not be the same
`agnt_t` as the 1726 array, and the current definition (which reuses agnt_t)
would then be wrong for one of them.

Until that is settled, `agnt_t+0x13`/`0x16` stays unnamed and unchanged: naming
it would freeze an unresolved conflict into the model.  The next step is to
diff the field usage of `Entities[i].base` against `agent[i]` at 0x1726.

### Result of the `Entities[].base` vs `0x1726` diff

```
Entities[].base : 04 06 08 0a 0c 0d 0e 0f 10 12 13 17 2a 2f 30 32
i*0x34 array    : 02 04 05 06 08 0a 0b 0c 0d 0e 0f 10 11 12 13 15 17 19
                  1a 1b 1d 1f 21 22 23 24 25 26 28 2b 2d 2e 2f 30 31 34 36
shared          : 04 06 08 0a 0c 0d 0e 0f 10 12 13 17 2f 30
```

The two records agree on every offset that both touch, including `0x17`, which
on `Entities[]` is a four-byte value addressed byte-wise (`field_0x17.lo + 1` =
`0x18`, `.hi + 1` = `0x1a`) and in the `0x1726` array is compared as a word at
`0x17` and `0x19`.  So `entity_t.base` **is** the same record as the `0x1726`
array; the record is not being split.

The only real conflict is the word OR at `0x16`, which overlaps the low byte of
that four-byte value at `0x17`.  The same bytes are therefore used two ways:

- `DGROUP:0x16` — `OR word ptr [BX+0x16],1` (constructor),
- `0x17..0x1a` — the entity far pointer (`CMP word [BX+0x17]`, `CMP [BX+0x19]`).

That is a union in the original source, not a modelling error in `agnt_t`.
Ghidra needs a union type over `0x13..0x1a`, or the two uses keep overwriting
each other in the decompiler.  Until that union exists, `0x13`/`0x16` cannot be
named without misdescribing one of the two uses.

### The bitfield plan does not work, and the diff needs re-reading

Modelling `0x13..0x16` as a bitfield cannot remove the overlap: the instruction
is a two-byte write,

```
4207:13c8  OR word ptr ES:[BX + 0x16],0x1
4207:13f7  OR word ptr ES:[BX + 0x16],0x1
```

so any field at `0x16` covers `0x16..0x17` whatever its bit layout, and
`0x17` is where the `0x1726` array keeps a word of its far pointer.  A union
cannot help either, because a union member must start at the union's own base:
`0x16` and `0x17` are different offsets.

Re-reading the earlier diff with **access widths** instead of bare offsets shows
why it did not settle the question:

| offset | `Entities[].base` | `0x1726` array |
|---|---|---|
| `0x14` | word, `& 1` (`field_0x13.lo + 1`) | 16-bit read |
| `0x16` | **word** OR `| 1` | — |
| `0x17` | **byte** (`field_0x17.lo + 1` = `0x18`) | **word** `CMP [BX+0x17]` |
| `0x19` | **byte** (`field_0x17.hi + 1` = `0x1a`) | **word** `CMP [BX+0x19]` |

The same offsets carry different widths in the two records, which means they are
**not** the same layout after all: `Entities[].base` appears to hold a 32-bit
flags value with words at `0x14` and `0x16`, while the `0x1726` array holds a
far pointer with words at `0x17` and `0x19`.  The earlier "no split needed"
conclusion compared offsets only and was therefore wrong.

Settling it needs one more disassembly: the instructions that read `0x17`/`0x19`
on `Entities[]` (whether they are byte or word moves) and the ones that write
`0x14`/`0x16` on the `0x1726` array.  Only then can `entity_t.base` and the
agent array element be declared as two different structures, which would also
change the 92 functions currently typed as `agnt_t *`.

### The widths confirm two different records

Disassembly of `OVC13_3d16_0255` (which walks `Entities[]`):

```
3d16:02a9  CMP byte ptr ES:[BX + 0x18],0x0
3d16:0391  CMP byte ptr ES:[BX + 0x18],0x0
```

together with the constructor's `OR word ptr ES:[BX + 0x16],0x1`, and the
agent-array disassembly

```
197a  MOV DX,0x1726
1986  MOV DX,word ptr ES:[BX + 0x17]
```

means:

- `Entities[].base`: word at `0x14`, **word at `0x16`** (covering `0x16..0x17`),
  **byte at `0x18`**, byte at `0x1a`;
- the `0x1726` element: **word at `0x17`** and word at `0x19`.

A byte at `0x18` is impossible if `0x17` starts a word there, so the two records
cannot share one layout.  `entity_t.base` is a distinct structure from the
`0x1726` array element, and reusing `agnt_t` for both is wrong for one of them.

Consequence: the 92 functions typed `agnt_t *` split into two groups.  Those
called with segment `0x1726` (e.g. `ovc27: ovr_agnt_3b1d_0a53(param_1,0x1726)`)
are array elements and keep `agnt_t`; those reached from
`((entity_t *)Entities)[i].base` need the entity base type.  The split must
happen before `0x13`/`0x16` and `entity_t+0x34`/`+0x35` can be named.

### The split was wrong: the overlap is inside one record

After creating `entBase_t` the entity-typed function was re-decompiled:

```c
byte __cdecl16far agnt_3b1d_0c9f(entity_t *ent)
{
  uVar1 = *(undefined4 *)((int)&(((entity_t *)ent)->base).flags16 + 1);  /* 0x17 */
  bVar2 = *(byte *)((int)uVar1 + 0x36) % 6;
  ...
```

`0x17` is dereferenced as a four-byte pointer on the **entity** as well, exactly
as in the `0x1726` array.  So the entity record really does hold a pointer at
`0x17..0x1a`, and the word OR at `0x16` overlaps its first byte *within the same
record*.  Two structures cannot express that; the earlier reading of
`CMP byte [BX+0x18]` as "a separate byte field" was wrong (it is a byte of that
pointer).

Consequences, applied:

- `entity_t` is back to `{ agnt_t base; byte field_0x34; byte field_0x35; byte dir; }`;
- `/st.h/entBase_t` was deleted, restoring the audit to 35 structs / 313 fields
  / 55 generated.

The `0x13..0x1a` overlap remains an unresolved modelling problem: it is a
deliberate union/bitfield overlap in the original source, and Ghidra's type
system here cannot place a word at `0x16` and a pointer at `0x17` in one
structure.  Naming those bytes would require rewriting the pointer as two
words, which contradicts every reader of the pointer.

## `agntG_t+0x3e` / `+0x40` = `flags2` / `flags3`

Both are bit-mask words used exactly like `flags` at `0x3c`; they are only ever
tested, and also ANDed with another record's mask word:

```c
(gdata->0x3e & 0x10) == 0 ... (& 8) ... (& 4) ... (& other->mask)
(gdata->0x40 & 0x80) == 0 ... (& 1) ... (& 0x100) ... (& other->mask)
```

No consumer computes a value from them, so nothing distinguishes an individual
bit; what the evidence fixes is that each is a flag word.  Named `flags2` and
`flags3`, continuing `flags` at `0x3c`.  Generated struct fields: 55 -> 53.

## `agntG_t+0x50` = `hitSound`

It is consulted at the moment a unit takes damage, right after its strength is
reduced, and each value chooses a different effect:

```c
*(char *)(agent + 0x21) = *(char *)(agent + 0x21) - (char)param_3;   /* damage */
...
if (*(char *)(gdata + 0x50) == '\0')      { audio_3a5b_0afd(); randBelow(); play_sfxU(); }
else if (*(char *)(gdata + 0x50) == 0x15)  { cVar1 = randBelow(); ... }
else if (*(char *)(gdata + 0x50) == 3)     { ... }
```

so it selects the impact-sound variant for the unit.  `0x51` is only ever
compared with `-1` in a single place and stays unnamed.

## Correction: the four `+0x36` readers take `agnt_t *`

`agnt_3b1d_0c7c`, `0c9f`, `0cc6` and `0cef` are called with segment `0x1726`
(`ovc27: agnt_3b1d_0c9f(param_1,0x1726)`), so their parameter is an agent-array
element.  The `+0x36` they read belongs to the record reached through
`agnt_t.entity`, not to the parameter itself; retyping them as `entity_t *` had
hidden that.  With `agnt_t *` the whole chain is typed and named:

```c
byte __cdecl16far agnt_3b1d_0c9f(agnt_t *agnt)
{
  peVar1 = ((agnt_t *)agnt)->entity;
  bVar2 = ((entity_t *)peVar1)->dir % 6;
  if (3 < bVar2) bVar2 = bVar2 - 6;
  return bVar2;
}
```

This also validates `agnt_t.entity` and `entity_t.dir` end to end.

## `agnt_3b1d_11c1` typed from its call site

Called as `agnt_3b1d_11c1(iVar3, 0x1726)`, and its body reads `0x30`, `0x31`
and the `flags` word at `0x2b`, so it takes `agnt_t *`:

```c
void __cdecl16far agnt_3b1d_11c1(agnt_t *agnt)
{
  if ((char)paVar1->field_0x30 == '\0') {
    if ((paVar1->flags & 0x100) == 0) {
      if ((paVar1->flags & 0x80) != 0) {
        *(undefined1 *)&paVar1->field_0x30 = 0xc;
```

`0x30` takes 0, 0xc or 0xd depending on `flags & 0x80` / `flags & 0x100`, i.e. it
is a small state value, but the values are opaque and it stays unnamed.
Struct-typed functions: 92 -> 93.

## Why `0426`/`0d4d` cannot be typed by changing one parameter

Their callers pass the record as an offset plus its segment, because the thunk
call splits the far pointer:

```c
/* ovc49 */
ovr_agnt_3b1d_0426(piVar7, uVar8, &local_5)
ovr_agnt_3b1d_0d4d(piVar7, uVar8, ...)
```

`piVar7` is an agent record (`piVar7[1]` is y, `piVar7 + 0x1d` is gdata), and
`uVar8` is its segment.  Ghidra recovered the prototype as
`0426(int *param_1, byte *param_2, char param_3)`, i.e. the offset in `param_1`
and the segment in `param_2`, so replacing `param_1` alone with a four-byte
pointer would swallow half of `param_2` and corrupt the rest of the signature.

The fix for these two is to correct the *prototype first* (one far-pointer
parameter instead of offset+segment), then type it.  `RenameVars` cannot do that
because it only renames existing variables, and a wrong width here would shift
every argument after it — the same class of mistake as the `entity_t *` retype.

## Prototypes repaired for the split-far-pointer entry points

`ApplyProto.java` applies a C prototype from a TSV (parse + apply), which is what
these needed: their callers push a far pointer as offset+segment, so Ghidra had
recovered two parameters where the source has one.

| function | before | after |
|---|---|---|
| `agnt_3b1d_196b` | `(void)` | `void agnt_3b1d_196b(entity_t *ptr)` |
| `agnt_3b1d_0426` | `(int *,byte *,char)` | `undefined1 agnt_3b1d_0426(agnt_t *agnt, byte *out)` |
| `agnt_3b1d_0d4d` | `(uint *,int *)` | `uint agnt_3b1d_0d4d(agnt_t *a, agnt_t *b)` |

Call sites that forced the shapes:

```c
ovr_agnt_3b1d_0426(piVar7, uVar8, &local_5);                        /* ptr + out   */
ovr_agnt_3b1d_0d4d(piVar7, uVar8, (uint)local_5*0x34 - 0x34, 0x1726); /* two agents */
```

`196b` now decompiles the comparison through the typed pointer:

```c
void __cdecl16far agnt_3b1d_196b(entity_t *ptr)
{
  for (i = 0; i < (int)(uint)AgntCount; i = i + 1) {
    if ((*(int *)(i * 0x34 + 0x19) == in_stack_00000006) &&
       ((entity_t *)*(int *)(i * 0x34 + 0x17) == ptr)) {
```

(the remaining `in_stack_00000006` is the segment half the thunk pushes; the
pointer parameter consumed the offset half.)

## \gnt_3b1d_1c26\ typed

Its prototype already carried the far pointer as one four-byte parameter, so only
the type was missing; the caller passes \piVar7\ (an agent record) and
\&local_5\.  Typed \gnt_t *agnt\.  Struct-typed functions: 95 -> 96;
auto parameters: 1234 -> 1233.

The rest of the xxx\ group (C5(byte)\, Pb(uint,int)\, 
bd(uint)\,
cd(int)\, f(int)\) takes plain indices, not records, so there is nothing
to type there.

## agnt_t+0x30 = state

Set together with 0x31 by the flag-driven transitions in agnt_3b1d_11c1
(0 -> 0xc when flags&0x80, -> 0xd when flags&0x100), and only ever 0, 0xc or
0xd, so it is a small state value.  Generated struct fields: 52 -> 51
(agnt_t 11).

## agnt_t+0x32 = flags32

The first attempt to name 0x33 as a byte failed because no component starts
there: the construction switch ORs 8 into the *high byte* of the 16-bit word at
0x32, and the constructor initialises that high byte to 2 (0x0200).  So 0x32 is
a flags word and the observed bit is 0x800:

    pbVar1 = &entity.base.field_0x32 + 1;   /* 0x33, high byte */
    *pbVar1 = *pbVar1 | 8;                  /* word bit 0x800    */

Named flags32.  Generated struct fields: 51 -> 50 (agnt_t 10).

## There is only one 149-byte table, not two

Disassembly of OVC13_3d16_1045, the access that looked like
\GMenuStrings + gindex*0x95 + 0x1f\:

    3d16:10f0  MOV DX,0x95
    3d16:10f3  IMUL DX
    3d16:10f5  MOV DX,0x195d
    3d16:10f8  MOV BX,AX
    3d16:10fa  MOV DX,ES
    3d16:10fc  MOV AL,byte ptr ES:[BX + 0x26d6]

ES is 0x195d, so the address is 95d:26d6 + gindex*0x95\ - the same entity-segment
table that agntG_t models.  The \GMenuStrings + 0x1f\ form was a symbol-relative
rendering: GMenuStrings sits at 2410:26b7 and 0x26b7+0x1f = 0x26d6, a numeric
coincidence, not a second array.

Offset 0x1f is therefore not a field of its own: 31 decimal falls inside
\xtents[3][3]\ (27..35) as \xtents[1][1]\, the second triple's right extent.
Comparing it with 0 is testing for an empty frame, not reading a separate flag.
No name is added because there is no field there.

## agnt_3b1d_093e prototype repaired

    caller: ovr_agnt_3b1d_093e(piVar7,uVar8,&local_8)   /* far ptr + out */
    before: bool agnt_3b1d_093e(int *,undefined2 *,undefined2 *,uint *)
    after : bool agnt_3b1d_093e(agnt_t *agnt,undefined2 *out)

The four-parameter shape came from the thunk pushing the pointer as offset plus
segment and Ghidra inventing two extra pointers.  Struct-typed functions:
96 -> 97; auto parameters: 1233 -> 1229.

## agntG_t+0x3a = attackBonus

When the unit's 0x3e bit 0x200 is clear, the combat value is built as

    bVar4 = manage_4d05_01a3(gdata[0x38], gdata[0x39]);
    iVar5 = bVar4 + gdata[0x3a];
    uVar8 = iVar5 + (dir % 6);        /* used as the strength/damage value */

so 0x3a is an additive bonus on that value.  0x38/0x39 are the two arguments of
that routine and stay unnamed: elsewhere it is called with the constants (2,6),
(3,6) and (4,6), which fixes neither argument.

## agnt_t+0x22 = strengthMax

It caps the combat strength at 0x21:

    if (agent[0x22] < agent[0x21]) agent[0x21] = agent[0x22];

and it is set from the entity's 0x32, the strength copy the constructor fills
from the generic record's 0x3b.  Generated struct fields: 49 -> 48 (agnt_t 9).

agnt_t+0x11 is a plain 0/1 flag (set to 0, 1 or a byte, tested against 0) with no
consumer that fixes its meaning, so it stays unnamed.

## agntG_t+0x46 = kind

The disassembly of the constructor's else-branch shows it indexing a table with
a stride of 0x94:

    4207:1589  MOV AL,byte ptr ES:[BX + 0x271c]   ; 0x26d6 + 0x46
    4207:1590  MOV DX,0x94
    4207:1593  IMUL DX

and the same byte selects per-kind rules in ovc27 (spell resistance at level 16
for 4, level 9 for 6).  Named kind.  Generated struct fields: 48 -> 47
(agntG_t 6).

## agnt_t+0x10/+0x12: the table is at a runtime segment offset

Both constructors load the pair from the same expression:

```c
iVar11 = (uint)peVar8[EntityCount].base.field_0xf * 4;      /* level * 4 */
uVar6 = *(undefined2 *)(iVar11 + -4);
*(undefined2 *)&peVar8[EntityCount].base.field_0x12 = *(undefined2 *)(iVar11 + -2);
*(undefined2 *)&peVar8[iVar13].base.field_0x10 = uVar6;
```

There is no base symbol and no segment override in the decompiled form: the
address is `(level-1)*4` from offset zero of whatever DS points at when the
constructor runs.  In the static image offset 0 of a segment is the PSP, so the
segment must be selected at run time (a loaded asset segment), which is why no
symbol exists there and why the earlier search for a base in the function body
found none.

Consequence: the table cannot be peeked from the program image at all.  Settling
`0x10`/`0x12` therefore requires the asset format (which record holds the
per-level pair), not further disassembly.  `0x10` stays `health` because its
default 100 and its `< 2` dying test are proven independently; `0x12` remains
unnamed.

## agntG_t+0x53 = levelLimit

The random-band selector in ovc30 compares this byte against a per-slot minimum and
maximum (LevelBandMin/LevelBandMax), and ovc22 writes 4, 8 or 0xc into it and
compares it with the entity level (agnt_t+0x0f).  Both uses make it a level cap;
0xff means none.  Generated struct fields: 47 -> 46 (agntG_t 5).

## `agntG_t+0x38`/`+0x39` = `dmgDice`/`dmgSides`, and the roll prototype

The routine the constructor calls with these two bytes had been recovered with
one parameter, but the stack disassembly shows two:

```
4d05:01af  MOV AL,byte ptr [BP + 0x8]    ; sides -> pushed to randBelow
4d05:01b5  CALLF ovr_randBelow
4d05:01c5  MOV AL,byte ptr [BP + 0x6]    ; count -> loop counter
4d05:01cd  JNZ  (loop)
```

so `ApplyProto.java` applied `char manage_4d05_01a3(char count, char sides)`,
and the body now reads correctly:

```c
char __cdecl16far manage_4d05_01a3(char count,char sides)
{
  uStack_3 = '\0';
  while (count != '\0') {
    uVar1 = ovr_randBelow((uint)(byte)sides);
    uStack_3 = (char)uVar1 + uStack_3 + '\x01';
    count = count + -1;
  }
  return uStack_3;
}
```

i.e. `count + sum(randBelow(sides))`, a dice roll.  The attack code feeds it the
two record bytes and adds the bonus and direction:

```c
bVar4 = manage_4d05_01a3(gdata->dmgDice, gdata->dmgSides);
iVar5 = bVar4 + gdata->attackBonus;
uVar8 = iVar5 + dir;
```

and other callers pass the constants `(2,6)`, `(3,6)`, `(4,6)`.  Named
`dmgDice` / `dmgSides`.  Generated struct fields: 46 -> 44; auto parameters:
1229 -> 1227.

### `agnt_t+0x2a` - examined, not named

Three consumers, no shared meaning:

```c
/* ovc49 */ 0x2a == 2 && BothFactions          -> returns "busy"
/* ovc25 */ 8 < (record + 0x2a)                -> gate on a count/quantity
/* ovc21 */ peVar22[0xb4].base.field_0x2a == 0 -> index expression is bogus
```

The values seen are 0, 2 and something above 8, which fits a count, a state and
an index equally well; nothing computes with it.  It stays unnamed rather than
being called "count" on the strength of one comparison.

## `agntG_t+0x51` = `actSound`

The decompiler showed two identical branches, because the argument that differs
was hidden.  The disassembly shows it:

```
6a8f:2016  LES BX,ES:[BX + 0x1d]
6a8f:201a  CMP byte ptr ES:[BX + 0x51],0xff
6a8f:201f  JZ  (default path)
...
6a8f:2039  MOV AL,byte ptr ES:[BX + 0x51]
6a8f:203d  PUSH AX                  ; the record's own id
6a8f:203e  CALLF ovr_play_sfxU
...
6a8f:2059  PUSH 0x4                 ; default path: fixed id 4
6a8f:205b  CALLF ovr_play_sfxU
```

so the byte selects which sound an agent plays when it acts, `0xff` meaning
"use the default".  With the field named the decompiler now shows the two
branches distinctly:

```c
if (((agntG_t *)paVar5->gdata)->actSound == 0xff) { ... }
ovr_play_sfxU(((agntG_t *)paVar5->gdata)->actSound,0,uVar4);
```

Generated struct fields: 44 -> 43 (`agntG_t` 2).

## Parameter names from body and call sites

`agnt_3b1d_005e(int x)` clamps its argument to `[0, 0xd2]`, and every caller
passes the record's first word, which is `agnt_t.x`:

```c
copy = agnt_3b1d_005e(*(undefined2 *)(agentRecord));   /* ovc49 */
iVar4 = agnt_3b1d_005e(*param_1);                      /* ovc15, *param_1 = x */
```

`agnt_3b1d_0032(int y)` clamps to `[0xc, 0xde]` and indexes the row table with
`table[(v - 0xc) * 2 + 0x34c]`, i.e. it maps a vertical coordinate to a screen
row.  Both names are now visible in the decompiled bodies:

```c
int __cdecl16far agnt_3b1d_005e(int x) { if (x < 0) x = 0; if (0xd2 < x) x = 0xd2; return x; }
undefined2 __cdecl16far agnt_3b1d_0032(int y) { if (y < 0xc) y = 0xc; ... }
```

Auto-named parameters: 1227 -> 1225.

### Examined, not named

- `2000:06D2`/`06D4` (`ovc13`): copies of the BIOS tick counter's low and high
  words (`BDA_DailyTimeCounter`), written once and never read in any exported
  module.  Two such copies exist (`06CD`/`06CF` too), so which timer each
  snapshot belongs to is not established; they stay unnamed rather than being
  given a shared name that hides that.

## Six more record consumers typed from their bodies

Each reads agent-record fields through its first argument, and every caller
pushes the record as offset+segment, so the parameter is one far `agnt_t *`
rather than the near `int *`/`undefined4` the export had recovered.

| function | what it reads | new prototype |
|---|---|---|
| `3a5b:0afd` | `record.x` scaled to `0..0x7f`, returned inverted | `int audio_3a5b_0afd(agnt_t *agnt)` |
| `6a8f:0229` | `record + 0x2b` flags (`& 0xae4`) | `void OVC41_6a8f_0229(agnt_t *agnt)` |
| `6a8f:063f` | both records: `+0x24`, `+0x1d`, `+0x2f`, `+0x17` | `undefined2 OVC41_6a8f_063f(agnt_t *a, agnt_t *b)` |
| `5ded:0960` | `record + 0xc` (target) | `uint OVC27_5ded_0960(agnt_t *agnt)` |
| `5ded:105e` | `record + 0x1d`, `+0x17`, `+0x46` | `undefined2 OVC27_5ded_105e(agnt_t *agnt)` |
| `5ded:04cd` | `record + 0x17`, plus a byte mode | `int OVC27_5ded_04cd(agnt_t *agnt, byte mode)` |

With the types applied the pan helper reads through the record field instead of
an anonymous dereference:

```c
int __cdecl16far audio_3a5b_0afd(agnt_t *agnt)
{
  uVar1 = (uint)(((long)(int)_agnt->x * 0x7f & 0xffffU) / 0xd2);
  if (0x7f < uVar1) uVar1 = 0x7f;
  return 0x7f - uVar1;
}
```

Struct-typed functions: 97 -> 103.  Auto-named parameters: 1225 -> 1217.

## Four more record consumers (second pass)

| function | what it reads | new prototype |
|---|---|---|
| `5ded:0fd2` | `gdata->kind` (0x46) and `entity->level` (0xf) | `undefined2 OVC27_5ded_0fd2(agnt_t *agnt)` |
| `5ded:0404` | `gdata->flags` (0x3c, bit 2) | `uint OVC27_5ded_0404(agnt_t *agnt,int param)` |
| `5ded:07d0` | `gdata->flags` (0x3c, bit 2) | `uint OVC27_5ded_07d0(agnt_t *agnt,int param)` |
| `3b1d:1da5` | `gdata->flags`/`flags2`/`flags3` of both arguments | `undefined1 agnt_3b1d_1da5(agnt_t *a,agnt_t *b)` |

The last one is the clearest: both parameters are dereferenced at `+0x1d` and
the resulting generic record is tested at `0x3c`, `0x3e` and `0x40`, i.e. the
three flag words named earlier.

Struct-typed functions: 103 -> 107.  Auto-named parameters: 1217 -> 1210.

## Correction: `ApplyProto` produced near pointers

`CParserUtils.parseSignature` sizes a plain `T *` with the program's default
pointer size, which in this 16-bit program is 2.  Every function typed through
`ApplyProto` with `agnt_t *` therefore got a **near** pointer, and the callee
consumed only the offset word.  The decompiler showed it plainly as the segment
half left on the stack:

```c
/* before the fix */
int __cdecl16far audio_3a5b_0afd(agnt_t *agnt)
{
  undefined2 in_stack_00000006;
  uVar1 = (uint)(((long)(int)_agnt->x * 0x7f & 0xffffU) / 0xd2);

int __cdecl16far OVC27_5ded_1beb(agnt_t *agnt,byte recIndex,byte maxLevel,int *cursor)
{
  _agnt = CONCAT13(in_stack_00000007,CONCAT12(recIndex,agnt));
```

`RenameVars.java` builds a four-byte pointer explicitly (`PointerDataType(base,4)`),
so the 21 parameters were re-typed through it.  Both bodies are now clean:

```c
int __cdecl16far audio_3a5b_0afd(agnt_t *agnt)
{
  uVar1 = (uint)(((long)(int)agnt->x * 0x7f & 0xffffU) / 0xd2);

int __cdecl16far OVC27_5ded_1beb(agnt_t *agnt,byte recIndex,byte maxLevel,int *cursor)
{
  while( true ) {
    if ((int)(uint)AgntCount <= *_cursor) return 0;
    uVar2 = *(undefined4 *)(*_cursor * 0x34 + 0x17);
    if (((*(byte *)((int)uVar2 + 0xf) <= maxLevel) &&
        (*(uint8_t *)*(undefined4 *)(*_cursor * 0x34 + 0x1d) != ((agnt_t *)agnt)->faction)) ...
```

and `agnt_3b1d_196b` uses the pointer's segment via `ptr._2_2_` rather than an
unnamed stack word.

Rule recorded: prototype *shape* repairs go through `ApplyProto`, but the far
pointer types must be applied afterwards with `RenameVars`.

## `attact_3f0b_2430` typed, and its direction argument

It reads the record's `gindex` (`0xd`), indexes the `0x95`-stride table with it,
and uses the record's `x`, so the first argument is an agent record passed far:

```c
void __cdecl16far attact_3f0b_2430(agnt_t *agnt,byte dir)
{
  uVar6 = *(undefined1 *)((int)(char **)GMenuStrings + (uint)agnt->gindex * 0x95 + 0x1f);
  if (dir == 0xff) { ... dir = dir + 1 & 3; ... }
  else { dir = dir ^ 2; ... }
  agnt->y = agnt->y + (int)*(char *)(dir + 0x889);
  iVar3 = ovr_OVC23_55fe_2e2b(agnt->x + *(char *)(dir + 0x885), agnt->y, uVar6);
```

The second argument is a direction `0..3`: it is masked with `& 3` when
randomised, `^ 2` reverses it, and it indexes the four-entry dx/dy tables at
`0x885`/`0x889`.  Named `dir`.

Struct-typed functions: 111 -> 112.  Auto-named parameters: 1198 -> 1196.

### Scan result

The three scans for remaining record consumers are now empty: no function reached
with `0x1726`, no function doing `(ulong)param_N >> 0x10` on an untyped pointer,
and no function mixing `* 0x95` with `0x34` still carries an `int *`/`undefined4`
first parameter.  What remains untyped takes plain values (coordinates, counts,
VGA registers) rather than records.

## Correction: `bldtp_t+0x23` is `resource`, not `tier`

`tier` was named from equality tests with 1, 2 and 3 alone, which is also exactly
what a good index looks like.  The ovc22 consumer decides it:

```c
int local_32[4];
...
local_32[(uint)bldtp->resource]          = local_32[...] + (uint)bldtp->output;
local_32[(uint)bldtp->resource + 3]      = local_32[...] + ...;
... && (bldtp->resource < 4)
...
*(int  *)(record + 0x70) = local_32[0];      /* amounts stored into a unit */
*(undefined2 *)(record + 0x70) = local_32[1];
*(uint *)(record + 0x72)    = local_32[2];
```

A `0..3` value used to index a four-entry array (`< 4` guarded) whose slots are
then written into a unit record as amounts is a **good index**, not a tier.
Renamed `resource`.

The same consumer names the neighbour: `bldtp_t+0x1b` is the amount added to that
resource total each step, so it is `output`.

Generated struct fields: 41 -> 40.

### Tooling note

`SetFieldType` needs the full type path with a leading slash; passing
`stdint.h/uint8_t` fails silently as "typed=0 failed=2" until corrected to
`/stdint.h/uint8_t`.

## `bldtp_t+0x0e`/`+0x0f` = build duration floor and value

The building instance records are `0x12` bytes and carry the building type at
`+8` — `bldtp[record[8]]->resource` is what ovc21 compares against the requested
goods — and a progress counter at `+0x11` tested against the duration at `+6`:

```c
if (record[0x11] + 1 < record[6]) { record[0xe] = 2; ... }   /* ovc02_draw */
```

The duration itself is the type's value clamped to a floor:

```c
v = bldtp->buildTime;  if (v == 0) v = 1;
record[6] = (v < bldtp->minBuildTime) ? bldtp->minBuildTime : v;   /* ovc22 */
```

so `+0x0e` is `minBuildTime` and `+0x0f` `buildTime`.  Generated struct fields:
40 -> 38.

## Four index parameters

`agnt_3b1d_1035`, `15bd`, `16cd` and `177f` do not take records: they multiply
their argument by the `0x34` record stride or compare it against an index stored
in a grid.  Renamed to `index` / `agntIndex`.  The live decompile of `1035` also
shows its full prototype `(byte index, brect_t *param_2, undefined2 param_3)`,
which the older export had truncated to one parameter.

Auto-named parameters: 1196 -> 1192.

## `bldtp_t+0x1a` = `production`

Tracing the value rather than the merged block: `OVC22_5087_0234` reads the byte,
scales it by season, and the only caller formats the result into the construction
message.

```c
uVar7 = bldtp->production;
if (category == 0x19) {
    if (GSeason == 0)      uVar7 >>= (GTimeLo < 0xf) ? 2 : 1;   /* winter   */
    else if (GSeason == 2) uVar7 += uVar7 >> 2;                 /* summer   */
}
...
uStack_16 = OVC22_5087_0234(buildingType, entityId, ...);       /* ovc45 */
OVC45_77eb_1ba2(uStack_16);  fmVsprintf();  say();              /* shown    */
```

A per-building amount that winter reduces and summer raises, whose result is
reported to the player, is `production` (distinct from `output`, which is added
into the resource totals).  Generated struct fields: 38 -> 37.

## Seven entity-index parameters

`OVC13_3d16_1045`, `OVC22_5087_1470/1532`, `OVC24_5943_0196`,
`stats_6386_1572`, `OVC15_4207_0e17` and `OVC45_77eb_16b2` all index
`((entity_t *)Entities)[param_1]` (or take `Entities + param_1`), so the
parameter is an entity index, not a record.  Renamed `entityIndex`; the live
decompile now reads `int entityIndex`.

Auto-named parameters: 1192 -> 1185.

## Entity-index and agent-index parameter sweeps

Two verified sweeps, each function checked for the indexing expression before the
rename:

**Entity index** (8 functions) — body indexes `((entity_t *)Entities)[param_1]`
or takes `Entities + param_1`:
`OVC22_5087_1991/1ac1/1ca4`, `OVC24_5943_026e/181d/1bff`,
`OVC15_4207_1aae/16a5` -> `entityIndex`.

**Agent index** (13 functions) — body multiplies the argument by the `0x34`
agent-record stride and reads the record's entity/gdata pointers:
`stats_6386_12b7/16a2/1837/1997/1a19/1a9b`, `OVC15_4207_1d87`,
`OVC27_5ded_0a05/0cc2`, `OVC41_6a8f_01e7/0256/0807/08c2` -> `agntIndex`.

A live decompile confirms the second sweep:

```c
char * __cdecl16far stats_6386_12b7(byte agntIndex,char *param_2)
{
  uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + 0x17);   /* entity pointer */
```

Auto-named parameters: 1185 -> 1164 (8 + 13).

## Unit-index, owner-index and coordinate parameters

**Unit index** (4): `OVC22_5087_1674`, `unit_6616_0000`, `season_67e7_09b9`,
`constrct_7e7c_2e8e` index `((unit_t *)GUnits)[param_1]` and never `Entities`.

**Owner index** (1): `attact_3f0b_0894` compares each agent's owner
(`record + 0x1b`) with its argument and counts matches:

```c
for (bVar3 = 0; bVar3 < AgntCount; bVar3++)
    if (*(int *)(bVar3 * 0x34 + 0x1b) == ownerIndex && ... ) bStack_3++;
```

**Coordinates** (2 functions, 4 parameters): `OVC23_55fe_05db` and
`OVC15_4207_0ff0` take an x (clamped with the square-x helper and compared with
`GfxRndSeed`) and a y (compared with `GfxRndSeed2` / the entity's `targetY`):

```c
uint __cdecl16far OVC23_55fe_05db(int x,int y)
{
  uVar1 = ovr_OVC23_55fe_3450(x);
  uVar2 = ovr_OVC23_55fe_3450(GfxRndSeed);
  if ((uVar1 == uVar2) && (GfxRndSeed2 == y)) { ... }
```

Auto-named parameters: 1164 -> 1155.

## Map-coordinate parameters (x, y)

The map arrays are `[60][148]`, so the first index is y (`0..0x3b`) and the second
x (`0..0x93`).  Five functions bound their arguments accordingly and index
`GMapCells`/`GMapFlags[y][x]`, which pins the order:

```c
uint __cdecl16far init_3381_233e(int x,int y)
{
  if ((((x < 0x94) && (-1 < x)) && (y < 0x3c)) && (-1 < y)) {
    uVar1 = CONCAT11((char)((uint)(y * 0x94) >> 8), (*(byte (*)[59][148])GMapCells)[y][x]);
```

`init_3381_233e/237a/23b5`, `constr_36ce_306b` and `OVC13_3d16_01a4` now read
`(int x,int y)`; `01a4` makes the split explicit by adding the view origin:
`GMapCells[Seed_2000_d10e + y][Seed_2000_d110 + x]`.

Auto-named parameters: 1155 -> 1145.

### `char_sheet_t` - investigated, not renamed

Two names in the recovered character sheet look suspicious, and the evidence does
not settle them either way:

- `race` (`+48`) is compared against per-class thresholds (`cls == 4 && race > 12`),
  indexes `cls * 0x94 + race * 4`, and is used as the iteration count when hit
  points are rolled (`for (i = 0; i < sheet->race; i++) hp += rand + statMod(stats[4]) + 1`).
  That reads like a level, but `race = 6` is also assigned as an initial value and
  `level` (`+134`) is set to 1 alongside an `if (level != 0)` validity test, so the
  two names cannot simply be swapped.
- the same function confirms `manage_4d05_118b` is an ability modifier (it maps
  3..18-style scores to `-3..+3`), which is why `stats[4]` behaves like a
  constitution value - useful evidence, but it does not name the padded regions.

No rename is applied: guessing `race` -> `level` here would repeat the `tier`
mistake in the opposite direction.

## More map coordinates, a structure type and an ability score

Six more functions take map `(x, y)` pairs, verified per function:

| function | evidence |
|---|---|
| `3f0b:0000`, `3f0b:007e` | bounds `0..0x93` / `0..0x3b`, `GMapFlags[param_2] + param_1` |
| `3f0b:01ec` | forwards both to `007e`/`00d8` |
| `3f0b:027d`, `3f0b:0362` | bounds `0x91`/`0x39` plus the direction offsets at `0x885`/`0x889`, `GMapFlags[param_2][param_1]` |
| `48ac:0bf4` | `GUnitGrid[param_1][param_2]` (declared `[148][60]`) and `GMapFlags[param_2] + param_1` |

`manage_4d05_2bc4`'s second argument is compared against `GStructures[i].type`
while searching the thirty structure records, so it is `structType`.

`manage_4d05_118b` is an ability modifier and now says so:

```c
undefined1 __cdecl16far manage_4d05_118b(byte abilityScore)
{
  if (abilityScore < 4) uVar1 = 0xfd;        /* -3 */
  else if (abilityScore < 6) uVar1 = 0xfe;   /* -2 */
  ...                                        /* +3 at 18 and above */
```

Auto-named parameters: 1145 -> 1131 (12 + 2).

### `char_sheet_t.pad_31` - no reader

`manage_4d05_11cb` writes the same rolled value into both bytes
(`pad_31[0] = value; pad_31[1] = value;`) after summing hit-dice-style rolls, but
**no function reads `pad_31`** anywhere in the export.  Whether it is hit points
split into two bytes or two separate stats cannot be decided from a write-only
pair, so the field keeps its padded name.

## Screen coordinates and one more map pair

`OVC13_3d16_0186` reads the framebuffer directly, which fixes both arguments:

```c
return CONCAT11((char)((uint)(screenY * 0x140) >> 8),
                *(undefined1 *)(screenX + screenY * 0x140));
```

`0x140` is the 320-byte row, so the first argument is the screen x (`0..319`) and
the second the screen y.

`OVC13_3d16_01fb` bounds its arguments around the view origin and indexes
`GMapFlags[origin_y + param_2][origin_x + param_1]`, so it is the map `(x, y)`
pair like its neighbour `01a4`.

Auto-named parameters: 1131 -> 1127.

### Remaining generated struct fields, from a fresh type audit

| struct | offsets left | note |
|---|---|---|
| `anm_t` | 11 | no reader in any export (asset-file bytes) |
| `agnt_t` | `0x05`, `0x11`, `0x12`, `0x13`(+`0x16`/`0x17`), `0x23`, `0x24`, `0x25`, `0x2a`, `0x2d` | four inside the word/pointer overlap; the rest are set/cleared but never compute |
| `bldtp_t` | `0x0c`, `0x1e`, `0x1f`, `0x24`, `0x25` | equality tests only |
| `entity_t` | `0x34`, `0x35` | no typed reader |
| `agntG_t` | `0x52`, `0x94` | no reader |

`agnt_t+0x23`/`+0x24` are always written together on the reset path (`0x23 = 10`
with `0x24 = 2`, or `0x23 = 5` with `0x24 = 1`) and cleared elsewhere, which is a
timer/state pair but does not fix which is which; they stay unnamed.

## Index and handle parameters from the pointer/record tables

Seven more parameters, each verified from the expression it feeds:

| function | expression | name |
|---|---|---|
| `save_49fd_01da` | forwards `param_1` as the first argument of `save_49fd_0000` twice (file position/length pairs) | `handle` |
| `OVC23_55fe_1803` | `_fmemmove(param_1 * 0x12, param_1 * 0x12 + 0x12, ...)` over `GRecordCount` | `recordIndex` |
| `OVC23_55fe_29a2`, `2937` | read `*(byte *)(param_1 * 0x12 + 9)` and the record's coordinates | `recordIndex` |
| `OVC24_5943_1007` | `*(undefined4 *)(param_1 << 2) + 0x39 / 0x3b` | `leaderIndex` |
| `OVC24_5943_190b`, `season_67e7_026a` | `*(undefined4 *)(param_1 << 2) + 0x3e / 0x3f` | `leaderIndex` |

Live confirmation:

```c
void __cdecl16far OVC23_55fe_29a2(int recordIndex)
uint __cdecl16far save_49fd_01da(int handle)
{
  if (-1 < handle) { ... }        /* file-handle test */
```

Auto-named parameters: 1127 -> 1120.

## Building-type and generic-agent-index parameters

**`bldType` (11 functions):** each multiplies the first argument by the `0x27`
`bldtp_t` stride and reads named fields through it (`+0x121` flags2, `+0x123`
income, `+0x128` production, `+0x133` resource, `+0x134` flags3):

`OVC22_5087_0119/015c/018f/0234/0411`, `bldng_676c_003d`,
`OVC45_77eb_0683/0708/0742/0778/0c36`.

**`gindex` (4 functions):** each indexes the `0x95`-stride generic-agent table
with the argument, i.e. the same index stored in `agnt_t.gindex`:

```c
int __cdecl16far OVC25_5b66_18cc(byte gindex)
{
  return (uint)*(byte *)((int)&26F7[8].seg + (uint)gindex * 0x95) + ...;
}
```

`OVC25_5b66_173b/18cc`, `OVC30_619c_031d/0339` -> `gindex`.

Live confirmation: `char * __cdecl16far OVC45_77eb_0c36(byte bldType)`.

Auto-named parameters: 1120 -> 1105 (11 + 4).

## Correction: scan windows leaked into the next function

The parameter sweeps matched an expression anywhere in the **next 80 source
lines**, which can cross into the following function.  Re-checking every renamed
function against its own body (split on the `/* addr */` markers) exposed six
names that came from the neighbour:

| function | wrong name | body actually shows | corrected to |
|---|---|---|---|
| `OVC22_5087_0119`, `015c`, `018f` | `bldType` | a far-pointer table with a dropped base, read at `+0x2f`, `+0x87` | `param_1` |
| `OVC30_619c_031d` | `gindex` | only `< 5` / `< 9` classification, no table | `param_1` |
| `OVC25_5b66_173b` | `gindex` | pointer table at `+0x3e/+0x3f/+0x5d/+0x5e`, no `0x95` | `param_1` |
| `OVC22_5087_1470` | `entityIndex` | pointer table at `+0x3f/+0x45/+0x4f`, not `Entities[]` | `param_1` |

Three of the same batch were right for a different reason and are now named
correctly, and two more functions that the window had hidden are fixed:

| function | body | corrected to |
|---|---|---|
| `OVC45_77eb_0683`, `0708`, `0742` | `GMapFlags[y][x]` | `x`, `y` |
| `OVC23_55fe_2937` | `record+2 <= x <= record+2+width`, `record+4 == y` | `x`, `y` |
| `OVC41_6a8f_01e7` | `(int)param_1 + 0x17` (dereferences a far pointer) | `agnt_t *agnt` |

Verified signatures after the fix:

```
OVC22_5087_1470(byte param_1)
OVC30_619c_031d(byte param_1)
OVC25_5b66_173b(byte param_1)
OVC23_55fe_2937(int x, int y)
OVC41_6a8f_01e7(agnt_t * agnt)
```

Auto-named parameters: 1105 -> 1107 (six false names withdrawn, the correct ones
kept).  Struct-typed functions: 112 -> 113.

### Method fix

The sweeps now extract a function body strictly between `/* addr */` markers and
search only inside it - `scripts/fbov/verify_param_names.py` re-runs 53 such checks
and reports failures, so a leaking window cannot pass silently again.

## The 0x217A far-pointer table is the party's character sheets

The five withdrawn names were re-examined at the disassembly, and the base that
the decompiler had dropped is an explicit segment load:

```
5087:011c  MOV AL,[BP+6]
5087:0121  SHL AX,2
5087:0124  MOV DX,0x217A
5087:0127  MOV BX,AX
5087:0129  MOV ES,DX            ; ES = 0x217A
5087:012b  LES BX,ES:[BX+0]     ; far pointer per entry
5087:0130  MOV AL,ES:[BX+0x2F]
```

`0x217A:0000` is zero in the image, i.e. a runtime array of far pointers, and the
records they point at carry the character-sheet fields:

| read | `char_sheet_t` field |
|---|---|
| `+0x2F` | `cls` (47) — compared with `7`, matching the seven classes |
| `+0x3E`, `+0x3F` | `classStr`, `excluded` |
| `+0x5D`, `+0x5E` | `flags5d`, `pad_5e` |
| `+0x87` | `rank` (135) |
| `+0x45`, `+0x4F` | inside `pad_40` / `foodProd` |

So the table is the party's character sheets and the argument is a party member
index.  Verified signatures:

```
char * OVC22_5087_0119(byte partyIndex)
void   OVC25_5b66_173b(byte partyIndex)
undefined2 OVC22_5087_1470(byte partyIndex)
```

`5087:0119`, `015c`, `018f`, `5b66:173b` and `5087:1470` -> `partyIndex`.
Auto-named parameters: 1107 -> 1102.

### Verification now covers 60 checks

`scripts/fbov/verify_param_names.py` re-checks every renamed parameter (entity,
agent, unit, party, leader, record arrays, coordinates, bldType, gindex) against
its own function body and reports zero failures.

## Seven GUnitGrid map-coordinate pairs

`GUnitGrid` is declared `[148][60]` (x, y) and each of these bodies indexes it as
`(*(short (*)[148][60])GUnitGrid)[param_1][param_2]`, so the arguments are the map
coordinates:

| module | function | use of the cell |
|---|---|---|
| ovc22 | `5087:3c93` | `GUnits[cell].unitType == param_3` |
| ovc22 | `5087:3d25`, `3dc7`, `3eb1` | read the cell's unit index |
| ovc23 | `55fe:1005` | read the cell's unit index |
| ovc45 | `77eb:0121` | `GUnits[cell].bldType` |
| ovc45 | `77eb:0179` | read the cell's unit index |

Verified signatures:

```
uint OVC22_5087_3d25(int x, int y)
byte OVC45_77eb_0121(int x, int y)
```

Auto-named parameters: 1102 -> 1088 (7 pairs).

### Struct fields checked this pass, still unnamed

- `agnt_t+0x05` (and `+0x04`) are written with `randBelow() - 1`/`-value` and
  tested as signed bytes, i.e. small signed random offsets, but `0x04..0x05` is
  also stored as the 16-bit `targetX` word by the constructor - a byte/word
  overlap like `0x13..0x1a`, so no name is added.
- `bldtp_t+0x1e`/`+0x1f` have **no reader at all** in the export.
- `bldtp_t+0x25` is only compared for equality with the menu highlight selector
  (`Highlight1`) or a caller's category, which does not distinguish
  "category" from "resource" - and `0x23` is already `resource`.
- `2410:02F4` is shifted left four and combined as `CONCAT11(0x24, v << 4)` for a
  text blit, so it is a colour attribute, but which palette entry is not stated.

## Two more agent-pointer prototypes repaired

`OVC41_6a8f_22cb` receives one far agent pointer — it splits it as
`(int)param_1, param_1._2_2_` when forwarding to `agnt_3b1d_0ac0` — plus an
integer:

```c
void OVC41_6a8f_22cb(agnt_t * agnt, int param)
```

`OVC41_6a8f_297d` was three `undefined2` parameters because the thunk splits the
pointer; it forwards `(param_1, param_2)` as that pointer and `param_3` as the
integer, so the prototype is one far pointer plus one word:

```c
void OVC41_6a8f_297d(agnt_t * agnt, undefined2 param)
```

Struct-typed functions: 113 -> 115.  Auto-named parameters: 1088 -> 1083
(the repaired prototype merges two parameter slots into one).

### Text-in-data sweep: no new names

`scripts/ghidra/FindTextData.java` scans every auto-named data symbol for bytes
that look like ASCII with a space.  It found five, all offset artefacts rather
than strings:

| address | bytes | why not a string |
|---|---|---|
| `2410:02F4` | `.Error 4 %d .` | the middle of a format string; the symbol itself is the colour attribute |
| `2410:69D9` | `..Your may continue play` | the high word of `PromoteThreshold` |
| `2410:6AC4`, `6AC6` | `.j.$My %s, we in this ne` | one or two bytes before a far pointer to the text |
| `2410:74AC` | `..w.$.w.$..$Choose party` | byte before a pointer table, then text |

So no data blob hides an unlabelled string: the string pass plus the offset
artefacts account for the text in DGROUP.

## Two label helpers: far text pointer plus x

Both functions measured a string and used the width to place it:

```c
iVar1 = ovr_font_302d_06ea(param_1,param_2,Font02.ofs,Font02.seg);
TextBlitX = param_3 - iVar1;
ovr_blitLabel();
```

`font_302d_06ea` takes two far pointers, so `(param_1, param_2)` is one text
pointer and `param_3` is the centre x.  The prototypes are now one four-byte
pointer plus an int:

```
void manage_4d05_04c6(undefined4 text, int x)
void manage_4d05_0519(undefined4 text, int x)
```

The pointer keeps the `undefined4` type (the char-pointer type path did not
resolve through `RenameVars`), but its shape is right and both slots are named.

Auto-named parameters: 1083 -> 1076 (two merged slots removed, four names added).
The verification script runs 71 checks.

## `bldtp_t+0x25` = `unitType`

It is compared for equality with the same selector as `unit_t.unitType`:

```c
(*(char *)(bldtp->... + 0x133) == Highlight1) ...      /* ovc13 */
(puVar7[uVar8].unitType == Highlight1 || Highlight1 == 0xff)
```

`Highlight1` is the menu's selected unit type (`0xff`/`-1`/`-2` as sentinels), so
the building field is the unit type that building relates to - the one it can
provide.  Named `unitType`; `ovc18` breaking its scan on values 0 and 7 is
consistent with `0` meaning none.  Generated struct fields: 37 -> 36.

## `agnt_t+0x2d` = `visited`

It is a per-search marker: one routine clears it for every agent, and a scan sets
it as it examines each candidate so that no agent is considered twice in the same
pass:

```c
if (((agent[0x2d] == 0) && (agent[0x1b] == param_1) && ...)) {
    agent[0x2d] = 1;
    ...
```

Generated struct fields: 35 -> 34.

## `agnt_t+0x24` - analysed, still unnamed

Two writers bracket the values, and together they describe a death path rather
than a named state:

```c
/* orders cleared (ovc41) */
flags |= 4;  agent[0x24] = 1;  targetY = 0;  agent[0x23] = 5;  clearOrders();

/* remove/kill path (ovc49) */
strength (0x21) = 0;  agent[0x23] = 10;  agent[0x24] = 2;  targetY = 0;
```

and readers skip a unit whose value is 2 (`!= 2` guards in ovc15/ovc41/ovc49).
So 1 accompanies "orders cleared" and 2 accompanies "strength zeroed", which is
the death/removal path - but the field itself is a small enum whose third value
(0) also appears, and naming it `dead` or `state` would encode only one of the
three meanings.  It stays generated with this analysis recorded.

`bldtp_t+0x0c` likewise stays: every use is `== 2` in the placement checks, with no
computation on the value.

## `agnt_t+0x12` = `frameIndex`

The visual routine shows the value's only computed use - it indexes the table
held in the field at `+0x13`:

```c
uVar1 = *(undefined2 *)(iVar5 * 0x34 + 0x15);
piVar4 = (int *)(*(int *)(iVar5 * 0x34 + 0x13)
                 + (uint)*(byte *)(iVar5 * 0x34 + 0x12) * 4);
iVar2 = piVar4[1];  iVar3 = *piVar4;              /* a far frame record */
```

so `0x12` is a byte index into a far-pointer table of frame records.  The special
values tested elsewhere (`== 3`, `== 0x0f`) are poses of that table, so the name is
`frameIndex` rather than a pose id.  Generated struct fields: 34 -> 33.

Note that this particular access is raw pointer arithmetic (`iVar5 * 0x34 + 0x12`),
so the decompiled text still shows an offset even though the structure names it.

### `bldtp_t+0x24` - still unnamed

Its single read compares it with one magic value and packs it into a combined
key:

```c
cVar10 = *(char *)(bldtp + 0x132);
uStack_6 = CONCAT13(cVar10, ...);
if (((5 < unit.level) && (cVar10 == -0x7a)) && ...) { ... }
```

One equality against `-0x7a` identifies neither the domain nor the meaning.

## Local variable names (first pass)

Until now only parameters, fields and globals had been named; the 317 auto-named
locals were untouched.  `scripts/ghidra/ListVars.java` now dumps the *stored*
variables of a function, which is what `RenameVars` operates on, and that exposed a
method limit worth recording.

### Only stored variables can be named

`ListVars 7e7c:004b` lists 11 locals, while the decompiled body shows about 30
names.  The extra ones (`iStack_14`, `bStack_1d`, `auStack_14`, `cStack_23`, ...)
are synthesised by the decompiler from unmodelled stack slots and **do not exist as
variables**, so `RenameVars` reports `NOVAR` for them.  Names therefore have to come
from the stored set:

```
RenameVars 7e7c:004b auStack_14 ...  ->  NOVAR 7e7c:004b auStack_14
RenameVars 7e7c:004b bStack_1d ...   ->  NOVAR 7e7c:004b bStack_1d
RenameVars ...                      ->  renamed=4 missing=2 failed=0
```

### Named locals

| function | local | name | evidence |
|---|---|---|---|
| `land_info` (7e7c:004b) | `local_226[513]` | `msg` | `strcpy` destination that is then displayed |
| | `local_24e[20]` | `menuItems` | array of offset/segment pairs for "Change party" and "Done" |
| | `local_1a` | `tileX` | `GfxRndSeed + param_1 - 2`, passed as the x coordinate |
| | `local_20` | `entityIndex` | filled by `ovc45_77eb_02c1(...,&local_20)`, then used to index `Entities` |
| `ui_unit_order_6616_0689` | `local_132[240]` | `msg` | `stsprintf` destination passed to `say()` |
| | `local_36` | `cursorX` | `(GfxRndSeed - Seed_2000_d110) * 2 + 7`, the x argument of `blitGfx10` |
| | `local_38` | `cursorY` | `(GfxRndSeed2 - Seed_2000_d10e) * 3 + 8`, the y argument of `blitGfx10` |
| | `local_16` | `saveArea` | `memcpy` destination (0x440 bytes) passed to `miceRestoreArea`/`blitRect` |
| `OVC40_69c8_04c6` | `local_4`, `local_6` | `clickX`, `clickY` | filled by the input poll, then tested `0x87 < x < 0xd6`, `0xb9 < y < 0xc6` |

The decompiler keeps the array sizes it inferred after the renames, which is the
check that the name landed on the right variable:

```c
undefined2 menuItems [20];
char msg [513];
tileX = GfxRndSeed + (char)param_1 + -2;
uVar2 = ovr_OVC45_77eb_20e8(&tileX);
```

Auto-named locals: 317 -> 307.

### Examined, not named

- `init_3381_2883` has only five stored locals (`local_9`, `local_a`, `local_e`,
  `local_f`, `local_24`) and the interesting values in its body (`bStack_b` = the
  running minimum of the four neighbour cells, `iStack_12` = the loop index) are
  synthesised slots, not variables, so they cannot be named.
- `OVC22_5087_056e` carries `Unable to track spacebase fully` and `Type propagation
  algorithm not settling` warnings, so names on its locals would rest on a suspect
  decompilation; skipped deliberately.
- `local_14`/`local_16` in `OVC22_5087_0234` hold `0x22c4` plus a changing low word
  immediately before `blitLabel`/`stsprintf`, i.e. a far pointer to a format string;
  naming them would describe the argument, not a quantity, so they stay.

### Second pass: text buffers, tile corners and the DOS drive helpers

`scripts/ghidra/ListAllVars.java` dumps every stored variable of every function
(`tmp/allvars.csv`, 692 locals), so candidates can be picked from real variables
instead of guessing at decompiler slots.

| function | local | name | evidence |
|---|---|---|---|
| `OVC45_77eb_0d61` | `local_3cc[712]` | `msg` | `stsprintf` destination, then `strcat`-ed repeatedly |
| `OVC45_77eb_1754` | `local_268[512]` | `msg` | `strcpy` destination handed to the dialog function |
| `OVC45_77eb_1bb3` | `local_26a[512]` | `msg` | same shape |
| `uiReadString` (4528:0c98) | `local_5c[80]` | `text` | `strcpy` destination measured with `strlen` |
| `season_67e7_004d` | `local_a8[80]` | `text` | `strcpy` destination measured with `strlen`, then walked |
| `constr_36ce_1f99` | `local_1c` | `cornerTL` | `constr_36ce_0101(x, y-1, &out)` |
| | `local_1e` | `cornerTR` | `constr_36ce_0101(x+1, y-1, &out)` |
| | `local_20` | `cornerBL` | `constr_36ce_0101(x, y, &out)` |
| | `local_22` | `cornerBR` | `constr_36ce_0101(x+1, y, &out)` |
| `getdisk` (1000:0988) | `local_4` | `drive` | `_dos_getdrive(&local_4)`, returned as `local_4 - 1` |
| `setdisk` (1000:09a2) | `local_4` | `driveCount` | `_dos_setdrive(drive+1, &local_4)`, returned |

The four corner values are the raw cell values written by the third argument of
`constr_36ce_0101` before scaling, taken at the four corners of one tile, and then
passed together to `constr_36ce_049f`, which shades that tile.

Live check:

```c
undefined1 cornerBR [2];
int cornerTR;
iStack_14 = constr_36ce_0101(iVar4,     iVar5 + -1, &cornerTL);
iStack_16 = constr_36ce_0101(iVar4 + 1, iVar5 + -1, &cornerTR);

char msg [712];
ovr_stsprintf(msg, unaff_SS, (char *)"%s:");
strcat(msg, unaff_SS);
```

Auto-named locals: 317 -> 296 over the two passes.

### Third pass: loop indices, an agent snapshot and a description buffer

| function | local | name | evidence |
|---|---|---|---|
| `OVC25_5b66_038d`, `OVC25_5b66_0530` | `local_4` | `entityIndex` | `for (local_4 = 0; local_4 < EntityCount; local_4++)` then `Entities[local_4]` |
| `OVC15_4207_2301` | `local_3e` | `agntCopy` | `_fmemmove(dst = agntCopy:SS, src = 0x1726:index * 0x34, count = 0x34)` - one 0x34-byte agent record; **corrected** in the `_fmemmove` pass (the old three-argument rendering showed the source offset where the count belonged) |
| `OVC49_8699_0874` | `local_aa[80]` | `text` | destination of `agnt_3b1d_0ac0(agnt, local_aa)` |
| | `local_5` | `agntIndex` | filled by the hit tests whose `out` parameter is an index, then used as `local_5 * 0x34` |

`OVC22_5087_056e` and `OVC22_5087_0234` were left alone: the first carries
`Unable to track spacebase fully` / `Type propagation algorithm not settling`, and
the second's `local_14`/`local_16` are a far pointer to a format string rather than a
quantity.  `OVC40_69c8_023a`'s `local_d6[171]`/`local_2b[37]` are save/restore blocks
copied out of a sprite and back, which describes the operation, not the data.

Auto-named locals over the whole turn: 317 -> 291.

### Fourth pass: out-parameters, a record buffer and `bld_inst_t`

Candidates came from a scan of every `&local_X` handed to a known callee plus the
`allvars.csv` inventory, so each name below starts from a stored variable whose
address is taken or whose value is indexed.

| function | local | name | evidence |
|---|---|---|---|
| `OVC49_8699_1e09` | `local_1c` | `agntIndex` | out-parameter of the hit tests, then `*(char *)(agent + 0xc) = local_1c - 1` |
| `upd_units_5087_1d7d` | `local_20` | `bldType` | `= (unit)->bldType`, then `* 0x27 + 0x121` and `BldInstances[local_20]` |
| | `local_1c` | `found` | `= 0`, set by `OVC22_5087_1674(unit, &local_1c, ...)` (which does `*param_2 = 1`), tested `!= 0` at the end |
| `unit_6616_10d5` | `local_16` | `rec` | the `0x13`-byte square record being compared against `SquareRecX` and appended to the list |
| `saveui_4528_055b` | `local_c` | `rect` | `brect_t` whose `.x`/`.y` are filled from the caller's outputs |

Live check:

```c
char found;
found = '\0';
bldType = (puVar15 + uVar22)->bldType;
OVC22_5087_1674(uVar22,&found,uVar29);
found = '\x01';

uint rec;
rec = GfxRndSeed;
iVar3 = memcmp((char *)&SquareRecX,(char *)"puppetmaker" + 3,(int)&rec);
```

Auto-named locals: 291 -> 286.

## `bld_inst_t` is a graphics far pointer plus eight spare bytes

The construction module fills the first two words from a loader and a constant
segment, which is exactly a far pointer:

```c
sVar5 = ovr_stshStoreFile();                 /* AX = offset */
uVar4 = 0x195d;                              /* DX = segment */
((bld_inst_t *)BldInstances + i)->ofs = sVar5;
*(uint16_t *)((int)&BldInstances[0].seg + i * 0xc) = (uint16_t)pbVar11;
```

and the consumers test the pair for zero to detect an empty slot:

```c
BldInstances[i].ofs != 0 || *(int *)((int)&BldInstances[0].seg + i * 0xc) != 0
```

| offset | name | note |
|---|---|---|
| `0x0` | `ofs` | offset half |
| `0x2` | `seg` | segment half |
| `0x4` | `data[8]` | untouched by any reader found |

These two fields did not move the audit's count - `AUTO_FIELD` only treats
`fieldN_0xNN`, `pad_N`, `unnamed*`, `unk*` and `FUN_`/`DAT_` names as generated, and
`field0`/`field2` are not in that set - but the struct is now recovered rather than
carrying placeholder names.

### Examined, not named this pass

- `2000:0744`/`2000:0749` are per-index small x/y offsets: they are added to a base
  to place a blit (`CrossBlitX = value + 0xed`, `CrossBlitY = value + 0x36`), store
  the player's clamped value back per `GMenuItem`, and one consumer turns 0749 into a
  percentage (`(0x1c - value) * 100 / 0x1c`).  Whether the index is a menu item, an
  entity or a sprite is not stated, so the two names would be guesses.
- `2410:5CF0`, `2410:5CEF`, `2410:648E`, `2000:027B` and `2410:07E2` were re-checked
  and keep the refusals recorded in `doc/globals_naming.md`: two boolean gates with an
  unstated subject, a packed pointer byte, a one-shot change flag, and a write-only
  byte.
- `55fe:2f90`'s `local_6` is a plain zero-then-increment counter bounded by a
  parameter; `count` would restate the mechanism, so it stays.

## Parameters typed from their bodies (fifth pass)

### A tooling rule that made three of these possible

`RenameVars.java` handles a pointer type by taking `spec` minus ` *` and calling
`dtm.getDataType(...)`, so the base type **must be a full path with a leading
slash**.  Passing `char *` silently produced a type the decompiler rendered as
`long text`; passing `/char *` produces the correct four-byte far pointer:

```
RenameVars ... param_1 text char *     -> int font_302d_06ea(long text, undefined4 font)
RenameVars ... param_1 text /char *    -> int font_302d_06ea(char * text, char * font)
```

The two label helpers from an earlier batch (`manage_4d05_04c6`/`0519`) were re-typed
the same way and now read `char * text`.

### Named and typed

| function | old | new | evidence |
|---|---|---|---|
| `font_302d_06ea` | `param_1`, `param_2` | `char *text`, `char *font` | sums `font[text[i] + 0xa1]` over the string |
| `OVC45_77eb_226e` | `param_1..5` | `char *dest`, `char *src`, `char *font`, `uint maxWidth`, `char mode` | copies src into dest until the pixel budget runs out, then appends `..`/`...` and a terminator |
| `OVC41_6a8f_0246` | `param_1` | `agnt_t *agnt` | reads `*(undefined4 *)((int)param_1 + 0x17)` |
| `OVC41_6a8f_29ea` | `param_1` | `agnt_t *agnt` | reads `+0xd` (`gindex`) and `+0xf` (`level`) |
| `OVC23_55fe_0000` | `param_3` | `agnt_t *agnt` | compares `+0x1b` (`owner`) with the agent owner field |
| `OVC18_48ac_0251` | `param_2` | `anm_t *anims` | indexes it with the `0x1e` stride and reads `sy`, `fw`, `fh` |

Live signatures:

```
int font_302d_06ea(char * text, char * font)
int OVC45_77eb_226e(char * dest, char * src, char * font, uint maxWidth, char mode)
int OVC41_6a8f_29ea(agnt_t * agnt)
uint8_t * OVC18_48ac_0251(uint8_t * param_1, anm_t * anims, uint8_t * param_3, byte param_4, char param_5)
```

Auto-named parameters: 1076 -> 1065.  Struct-typed functions: 115 -> 119.

### Correction accepted mid-batch

`48ac:0251`'s parameter was first applied as `/frm_t *` from the `0x1e` stride, but
the type audit shows `frm_t` is 20 bytes while `anm_t` is 30 = `0x1e`, and the three
offsets read through the stride (`+3`, `+9`, `+10`) are `sy`, `fw`, `fh` of `anm_t`.
It was re-applied as `anm_t *anims`.

## Locals (fifth pass)

`abilitiesDlg` keeps two per-class stat maps as locals, copied from constant tables;
the bytes at the copy sources are the proof:

```
2410:49DD  00 01 02 03 00 00 00 FF      /* class -> primary stat, 0xFF = none   */
2410:49E4  FF FF FF FF FF 01 03         /* class -> secondary stat             */
```

| function | local | name | evidence |
|---|---|---|---|
| `abilitiesDlg` | `local_a[8]` | `classStatMap1` | copied from `49DD`, indexed `[sheet->cls]`, passed to the ability-modifier helper |
| | `local_12[8]` | `classStatMap2` | copied from `49E4`, tested `!= 0xff` |
| | `local_18[6]` | `statIndex` | `[0]` reused as scan counter, `[1]` the chosen primary stat, `[entry + 1]` the stat offered per entry |
| | `local_2a[4]` | `menuItems` | far pointers to `GStatsLabels` filled per entry and passed to `uiInputText` |
| `constr_36ce_0995` | `local_26/28/2a/2c` | `cornerTL/TR/BL/BR` | the same four `constr_36ce_0101(x, y-1 … x+1, y)` calls as `constr_36ce_1f99` |

Live check:

```c
far_t menuItems [4];
byte statIndex [6];
byte classStatMap1 [8];
F_SCOPY((uint8_t *)0x49dd, ..., (uint16_t)classStatMap1);
_fsetmem(menuItems, unaff_SS, 0x10);
```

Auto-named locals: 286 -> 278.

### 2000:0744 / 2000:0749 re-derived - still refused

The writer is `draw_2e25_10c7(x, y)`: it clamps `x` to `0..0x38` and `y` to `0..0x1c`,
*restores* the stored pair when the new point falls inside `x < 0x1c && y < 0x1c - x`,
otherwise stores the new pair for `GMenuItem`, and then draws with
`x + 0xf3` / `y + 0x3b`.  The consumers scale them differently:

```c
iVar1 = (char)0749[param_1] * 0x12 / 0x39;   /* ovc02_draw: y used in a screen y */
iVar2 = (char)0744[param_1] * 0x12 / 0x39;   /* ovc02_draw: x used in a screen x */
and in the 0x13-byte square record (unit_6616_10d5):
local_12[param_1] = 0744[param_1];
local_d[param_1]  = 0749[param_1];
```

So the index is a five-slot value shared between `GMenuItem` at the drawing sites and
the slot index inside a square record - not provably "menu item", "entity" or
"sprite" - and the value is used both as a scaled coordinate and as a percentage
(`(0x1c - v) * 100 / 0x1c` in ovc14_attact).  Position and amount are both consistent
with the evidence, so no name is applied; this is the derivation the next pass should
start from.

### Flash palette pair and a save rectangle

`OVC13_3d16_005b` flashes three palette blocks and saves the drawing area around the
redraw:

```c
FlashToggle = 1 - (FlashToggle != 0);
ovr_vgaSetPalette(&stack0xffe2 + (uint)FlashToggle * 3, ..., 0xef);
ovr_vgaSetPalette(flashPalette1 + (uint)FlashToggle * 3, ..., 0xee);
ovr_vgaSetPalette(flashPalette2 + (uint)FlashToggle * 3, ..., 0xeb);
...
ovr_miceRestoreArea(&rect);  OVC13_3d16_0000();  ovr_miceBlitRect(&rect);
```

Each six-byte block therefore holds two three-byte colour entries selected by the
toggle, so they are `flashPalette1`/`flashPalette2`, and the `brect_t` used for the
save/restore is `rect`.

Auto-named locals: 278 -> 275 (286 at the start of the turn).

## Locals (sixth pass) - menu tables, seeds, corners, colours

Read from `tmp/decompiled5` (the regenerated export) and `tmp/allvars2.csv`.

### Menu tables built from the game's own pointer tables

`saveui_4528_1ae8` copies slices of the thirteen-entry table at `2410:26F7` into
locals and passes each as a menu:

```c
F_SCOPY(2410:26F7 + 5, ..., worldItems);          /* 32 bytes = 8 pointers */
puVar1 = worldItems; items.seg = (uint16_t)puVar1;
uiMenu((char *)"Which new world:", items, unaff_SS);

F_SCOPY(2410:26F7, ..., hostilityItems);          /* 12 bytes = 3 pointers */
puVar1 = hostilityItems; uiMenu((char *)"Hostility level:", ...);
```

which matches the strings those entries point at - "First City", "World 1..5",
"Random" for the eight world choices and "Peaceful", "Aggressive", "Hostile"
for the three hostility levels.  The third local holds the per-world seed pairs:

```c
SeedHi = seedTable[(uint)bStack_b * 2 + 1];
GSeed  = seedTable[(uint)bStack_b * 2];
```

`local_20[20]` in the same function is copied from `2410:26E3` and never read, so it
keeps its generated name.

### Tile corners, twice more

`OVC23_55fe_0617` and `OVC23_55fe_0768` use exactly the `constr_36ce_0101` corner
pattern already established for `constr_36ce_1f99`/`0995`, with the same argument
order `(x, y-1)`, `(x+w, y-1)`, `(x, y)`, `(x+w, y)`:

```c
iVar1    = ovr_constr_36ce_0101(param_1 + 1, -1, &cornerTL);
iStack_4 = ovr_constr_36ce_0101(param_1 + 1,  0, &cornerBL);
```

### Season palette and its three colour entries

`calcSeasonPalette` copies the season palette and three single colour entries, then
writes them into palette slots:

```c
F_SCOPY(SeasonPalettes, ..., seasonPalette);          /* 3 * 0x2d bytes */
_fmemmove(param_3 + 0x2d0, ..., seasonPalette + (uint)GSeason * 0x2d);
F_SCOPY(2410:69C2, ..., colorA);   _fmemmove(param_3 + 0x2ac, ..., colorA);
F_SCOPY(2410:69C5, ..., colorB);   _fmemmove(param_3 + 0x2b2, ..., colorB);
F_SCOPY(2410:69C8, ..., colorC);   _fmemmove(param_3 + 0x2be, ..., colorC);
```

The three sources are 3-byte RGB triples (`22 24 3F`, `29 2C 3F`, `3F 00 00`), so
they are colour entries; the ordering A/B/C follows their source addresses and the
ascending destination offsets.

### Summary of names

| function | local | name | evidence |
|---|---|---|---|
| `saveui_4528_1ae8` | `local_54[32]` | `worldItems` | eight pointers from `26F7+5`, menu title "Which new world:" |
| | `local_34[12]` | `hostilityItems` | three pointers from `26F7`, title "Hostility level:" |
| | `local_28[4]` | `seedTable` | `SeedHi`/`GSeed` read as `[n*2+1]`/`[n*2]` |
| `chargen` | `local_a[2]` | `keepDiscard` | copied from `GKeepDiscardStrings`, passed to `uiInputText` with 2 entries |
| | `local_66[80]` | `msg` | `stsprintf(local_66, ..., "Keep %s.")` |
| `OVC23_55fe_0617` | `local_6/8/a/c` | `cornerTL/TR/BL/BR` | corner pattern |
| `OVC23_55fe_0768` | `local_a/c/e/10` | `cornerTL/TR/BL/BR` | corner pattern |
| `OVC41_6a8f_2084` | `local_1c` | `agnt` | `agnt_t *` assigned from the caller's agent |
| `calcSeasonPalette` | `local_a0[136]` | `seasonPalette` | copy of `SeasonPalettes`, indexed by `GSeason * 0x2d` |
| | `local_a/e/12` | `colorA/B/C` | 3-byte RGB triples from `69C2/69C5/69C8` written into palette slots |
| `saveui_4528_1d55` | `local_5c[80]` | `text` | prompt buffer passed to `saveui_4528_055b` |
| `OVC45_77eb_1754` | `local_290[20]` | `menuItems` | offset/segment menu entries, `"Done"` last |
| | `local_68[81]` | `text` | destination of the ellipsis-truncation helper |

Live check:

```c
int cornerBR;  int cornerBL;  int cornerTR;  int cornerTL;
iVar1    = ovr_constr_36ce_0101(param_1 + 1, -1, &cornerTL);
iStack_4 = ovr_constr_36ce_0101(param_1 + 1,  0, &cornerBL);

undefined1 seasonPalette [136];  undefined1 colorA [4];  undefined1 colorB [4];
```

Auto-named locals: 275 -> 254.

## One parameter: OVC22_5087_0234's agent

Its third argument is dereferenced as an agent and handed to the pan helper:

```c
} while (*(uint16_t *)((int)pcVar8 * 0x34 + 0x1b) != ((agnt_t *)param_3)->owner);
uVar11 = ovr_audio_3a5b_0afd(param_3);
```

so it is `agnt` (`agnt_t *`).  Auto-named parameters: 1065 -> 1064; struct-typed
functions: 119 -> 120.

### Examined, not named

- `attact_3f0b_2a09`'s two `brect_t` locals are constant rectangles copied from
  `2410:088D` = (223,159)-(226,196) and `2410:0897` = (208,157)-(226,196).  They are
  save areas for `miceRestoreArea`/`miceBlitRect` (`local_16` around every animation
  step, `local_c` around one larger redraw), but naming them by role would need the
  meaning of the two screen regions, which the code does not give.
- `saveui_4528_1ae8`'s `local_20[20]` is copied from `2410:26E3` and never read.
- `saveui_4528_1d55`'s `local_8` is only ever an `&local_8` output of
  `saveui_4528_055b`; the callee does not show what it returns.

### Seventh pass: status buffers and a signed x delta

| function | local | name | evidence |
|---|---|---|---|
| `OVC49_8699_0874` | `local_5a[80]` | `msg` | `stsprintf(local_5a, ..., "%s is no longer paralyzed.")` and the web/freedom variants |
| | `local_8` | `dx` | written only by `agnt_3b1d_093e(agnt, &local_8)`, then tested `< 0` / `== 0` and negated into `targetX` |
| `OVC41_6a8f_04c0` | `local_7e[122]` | `msg` | `txt = ovr_stsprintf(local_7e, unaff_SS, ...)` |

Live check:

```c
char msg [80];
int dx;
bVar3 = ovr_agnt_3b1d_093e(agnt,&dx);
paVar10->targetX = -(uint8_t)dx;
```

Auto-named locals: 254 -> 251.

### Left alone in the same functions

- `OVC49_8699_0874`'s `local_a` and `local_4` have **no assignment anywhere** in the
  decompiled text (the writes go through a pointer the decompiler did not recover),
  so their values cannot be characterised.  `local_a` is only ever stored into
  `agnt_t+0x5`, which is the high byte of the word-sized `targetX` - the overlap
  already documented for that field.
- `OVC41_6a8f_04c0`'s `local_3`/`local_4` are the two out-parameters of
  `attact_3f0b_2252`, whose own body does not state what it returns.
- `OVC26_5d45_0000`'s four `int[300]` locals are only ever stored as pointers into
  other variables, so the flood-fill queues cannot be told apart from the code shown.

## Locals (eighth pass) - text buffers, menu and label arrays, the polled pointer

### A rename that failed loudly (and why that matters)

`RenameVars` refuses a name that already exists in the function's namespace:

```
RenameVars ... 77eb:0d61 local_b4 msg
  -> FAIL 77eb:0d61 local_b4 : ghidra.util.exception.DuplicateNameException:
     a Local Var symbol with name msg already exists in namespace OVC45_77eb_0d61
  -> renamed=4 missing=0 failed=1
```

`OVC45_77eb_0d61` already had a `msg` (the description buffer named in an earlier
batch), so the requirement/warning buffer became `reqMsg` instead.  This is the
opposite of `Rename.java`, which reports success on a symbol-name collision and
leaves the old name in place.

### Named

| function | local | name | evidence |
|---|---|---|---|
| `OVC45_77eb_0d61` | `local_b4[161]` | `reqMsg` | destination of `stsprintf` for " Next outpost available at rank %s.", " Requires a rank of %s.", " Location is too narrow for %s.", " It will cost %s the %s %d gp. " |
| | `local_104[80]` | `text` | destination of the ellipsis-truncation helper `OVC45_77eb_226e` |
| `OVC41_6a8f_2084` | `local_e4[80]` | `text` | `agnt_3b1d_0ac0(param_1, local_e4)` builds the agent description |
| | `local_94[20]` | `msg` | `stsprintf(local_94, ...)` caption |
| `OVC45_77eb_04d8` | `local_2e[20]` | `menuItems` | filled two words at a time from the candidate table and passed as the entries of `ovc28_6018_1527(puVar4, ..., iVar6, ...)` |
| `OVC22_5087_0234` | `local_96[24]` | `labelPtrs` | `ovr_blitLabel(local_96[i*2], local_96[i*2+1], ...)` |
| | `local_13e[36]` | `numBuf` | `stsprintf(local_13e, ..., "%d")` then measured with `font_302d_06ea` |
| | `local_66[20]` | `menuItems` | menu array passed to `ovc28_6018_1527` |
| `land_info` | `local_18` | `gfxOfs` | `local_18 = far_t_2410_78e4.ofs` (segment stays in the synthesised `uStack_16`) |
| | `local_29e[80]`, `local_2ee[80]` | `text1`, `text2` | both are destinations of `OVC45_77eb_226e` and go into the same formatted line |
| `ui_unit_order_6616_0689` | `local_2e`, `local_30` | `mouseX`, `mouseY` | the poll `ovr_init2_3338_0388((uint16_t *)&local_2e, ...)` writes the word pair and the code compares both against the previous pair to detect movement; the lower word is x, matching the MouseX/Y globals at `00E4`/`00E6` |
| | `local_3b` | `input` | the poll's return value, `} while (local_3b == 0);` |
| | `local_1aa[120]` | `text` | destination of the ellipsis helper |

Live checks:

```c
byte *mouseY;
byte *mouseX;
bVar1 = ovr_init2_3338_0388((uint16_t *)&mouseX,unaff_SS);
if ((mouseX != pbStack_2a) || (mouseY != pbStack_2c)) { ... }

char text [120];
byte input;
```

Auto-named locals: 251 -> 236.

### Refused

- `OVC45_77eb_04d8`'s `local_42[10]` collects `local_6` (an entity index) per menu
  entry and is **never read**, so its meaning is not established.
- `ui_unit_order_6616_0689`'s `local_42[5]` has no reference in the body at all.
- `land_info`'s `local_1e`/`local_22` are only ever `&local_1e`/`&local_22` outputs of
  `constrct_7e7c_0b9c` and `ovc45_77eb_02c1`, and the callers of neither state what
  they return.
- `bios`'s `local_8` is the `_wherexy()` result handed to `moveto`, while `local_4` and
  `local_6` are `screenpos()` results for the two cursor addresses; these are CRT
  internals whose roles are already expressed by the calls themselves.

### Ninth pass: the manage-result tables and the structure-name copy

`manage_4d05_26f6` copies the result-label table, re-lays it as far pointers and copies
the thirty structure names:

```c
F_SCOPY(ManageResultPtrs, ..., resultPtrs);           /* 0x14 bytes = 5 pointers as words */
uVar7 = resultPtrs[i * 2];
menuItems[i].seg = resultPtrs[i * 2 + 1];
(menuItems + i)->ofs = uVar7;
structNames[i * 2 + 1] = *(undefined2 *)((int)&GStructures[0].name + 2 + i * 6);
structNames[i * 2]     = uVar4;
... ovr_OVC28_6018_1398(menuItems, ...);
```

Live check:

```c
uint16_t resultPtrs [10];
far_t menuItems [5];
undefined2 structNames [60];
```

Auto-named locals: 236 -> 233 (251 at the start of the turn).

## Struct fields re-examined in the fresh export (no name added)

Each of the remaining generated fields was searched again in `tmp/decompiled5`, this
time with the accesses that only appear through typed pointers:

| field | every access found | conclusion |
|---|---|---|
| `agnt_t+0x11` | writes `0`, `1`, `randBelow()`; reads are only `== 0` tests in five functions | a flag/selector whose subject is never computed with; unchanged refusal |
| `agnt_t+0x2a` | one read, `peVar24[0xb4].base.field_0x2a == 0` | equality only |
| `agnt_t+0x24` | written `1` on the orders-cleared path and `2` on the strength-zeroed path, tested `!= 2` | three-state byte, each name would cover one meaning |
| `agnt_t+0x25` | `== 0`, `!= 1`, `!= 2`, `< 2` | state byte, comparison only |
| `bldtp_t+0x0c` | `== 2` in the placement checks | equality only |
| `char_sheet_t.pad_40` | `sheet->pad_40[0] = 1` in `OVC30_619c_0339` and `OVC43_6fbe_0000` | write-only |
| `char_sheet_t.pad_0` | `*(int *)(sheet->pad_0 + 0x1b)` compared with an agent owner; in `OVC43_6fbe_0000`: `*(int *)(param_2->pad_0 + 4) - 0xb`, `param_2->pad_0 + 6`, and `param_2->pad_0 + *(int *)uStack_6->pad_0` | the block is indexed as an array and holds dwords at `+4` and `+0x1b`; what those dwords mean (an owner index and an index into another sheet's block) does not name the 40-byte region |

The `pad_0` evidence is new: `OVC43_6fbe_0000` treats it as an *indexed base*, so the
block is not padding but an array of records whose element index comes from another
sheet.  That is a real step towards it, but a name would still be an interpretation of
who those records describe, so none is applied.

## Locals (tenth pass) - paired text lines and the combat message buffers

### Two formatted lines and their format tables

`OVC40_69c8_04c6` formats two lines per mode and draws them in one call; the format
tables are the two small arrays it indexes:

```c
puVar8 = local_64;
pcVar4 = ovr_stsprintf(local_26c, unaff_SS, (char *)puVar8[(uint)param_6 * 2]);
puVar9 = local_54;
pcVar5 = ovr_stsprintf(local_16c, unaff_SS, (char *)puVar9[(uint)param_6 * 2]);
OVC40_69c8_0000(pcVar5,(int)puVar9,pcVar4,(int)puVar8,bVar3,uVar13);
```

so each buffer pairs with the table that supplies its format: `text1`/`format1`
(`local_26c`, `local_64`) and `text2`/`format2` (`local_16c`, `local_54`).
The numbering follows the pairing, not the addresses (`local_16c` is the lower one).

Live check:

```c
char text1 [256];
char text2 [256];
undefined2 format1 [4];
undefined2 format2 [4];
```

### Agent-name pairs feeding a result sentence

Two spells share one shape - fill one or two name buffers, then format the sentence:

```c
/* OVC41_6a8f_22cb */
ovr_agnt_3b1d_0ac0(uStack_8, actorName);   /* actor  */
ovr_agnt_3b1d_0ac0(agnt,     targetName);  /* target */
ovr_stsprintf(msg, unaff_SS, "%s poisons %s.");
... "%s drains all energy from %s." / "%s drains a level from %s."

/* OVC41_6a8f_1c74 */
ovr_agnt_3b1d_0ac0(param_1, victimName);   /* the one afflicted */
ovr_agnt_3b1d_0ac0(param_2, sourceName);   /* the cause        */
ovr_stsprintf(msg, unaff_SS, "%s is paralyzed by %s.");
... "%s is stoned by %s." / "%s is no longer charmed."
```

Live check:

```c
char victimName [80];
char sourceName [80];
char msg [121];
ovr_agnt_3b1d_0ac0(param_1,victimName);
```

### Display buffers

| function | local | name | evidence |
|---|---|---|---|
| `drawAgntStats` | `local_7e[121]` | `line` | `stsprintf(local_7e, ...)` for "Unit of %d", "%d%s level, ", then truncated by the ellipsis helper |
| | `local_f6[120]` | `text` | `stsprintf(local_f6, "Loyal to %s")`, `litoa10(local_f6, ...)`, `stats_6386_065c(local_f6, ...)` |
| `OVC27_5ded_10ea` | `local_84[120]` | `msg` | `stsprintf(local_84, "%s is charmed by %s.")`, "%s fails to charm %s." |
| `stats_6386_13a1` | `local_82[120]` | `msg` | `stsprintf(local_82, "%s is no longer ready.")` |
| | `local_d2[80]` | `text` | filled by `stats_6386_12b7(agnt_id, local_d2)` |

Auto-named locals: 233 -> 218.

### Refused this pass

- `OVC27_5ded_10ea`'s `local_124`/`local_d4` swap roles between call sites (line 95
  puts `param_1`'s name in one, line 130 puts `param_2`'s name in the same one), so a
  name like `actorName` would be wrong for half the calls; only the message buffer
  was named.
- `OVC40_69c8_04c6`'s `local_6c` is the tail of `RankMsgPtrs` copied in and never
  read, and `local_5c` is a `char *` that receives a pointer-array copy - the
  decompiler's sizing for both is inconsistent with the copy lengths, so neither is
  named.
- `stats_6386_13a1`'s `local_a[6]` is only an output of `attact_3f0b_0ade(i,0,0,
  local_a, ...)`; that callee does not state what it writes.
- `OVC24_5943_026e`'s `local_24[4]` is a 2x2 byte state (`local_24[side]` and
  `local_24[side+2]`, values compared `< 2` and set to `2`); what the two halves
  distinguish is not stated.  Its `local_22`/`local_2c` are unreferenced in the
  current decompilation, so the 8-byte scratch pair described earlier no longer
  exists in the recovered code and cannot be renamed.
- `attact_3f0b_2a09`'s two constant rects stay unnamed; the only information about
  them is their geometry.

## Prototypes repaired (second pass) - a far byte buffer and two far strings

### `blit_317e_0879`: two slots are one far pointer

The loop advances a far pointer, so the decompiler's first argument and the integer
after it were halves of the same pointer:

```c
_param_1 = (byte *)CONCAT22(param_2, param_1 + 1);
```

After `ApplyProto` for the shape and `RenameVars` for the four-byte type:

```c
void blit_317e_0879(byte *buf, char count, byte value, byte chance)
{
  while (_count != 0) {
    if (*buf != 0) {
      uVar1 = ovr_randBelow(0x100);
      if (chance < (byte)uVar1) *buf = 0; else *buf = value;
    }
    buf = (byte *)CONCAT22(buf._2_2_, (byte *)buf + 1);
  }
}
```

i.e. it rewrites each non-zero byte of a buffer to `value` with probability
`chance/256`, else to zero - a speckle/dither pass.

### `saveui_4528_1d0f`: the string is far too

```c
_param_1 = (char *)CONCAT22(in_stack_00000006, param_1 + 1);
iVar1 = (int)*_param_1 + iVar1 * 10 + -0x30;   /* with an isdigit() guard */
```

so it parses a far string as a decimal number: `int saveui_4528_1d0f(char * str)`.

### Named in the same pass

| function | param | name | evidence |
|---|---|---|---|
| `blit_317e_04c2`, `blit_317e_0f7d` | `param_1` | `gfx` | `far_t` tested `param_1.ofs != 0 || param_1.seg != 0` |
| `vgaSetPalette8bit` | `param_1` | `pal` | walks 256 RGB triples: `out(0x3c9,*param_1); param_1 = param_1 + 3;` |
| `drawAnimTextAt` | `param_1` | `text` | forwarded to `drawTextAt(param_1, param_2)` |

Live signatures:

```
void blit_317e_04c2(far_t gfx, int param_2, int param_3, int * param_4)
undefined1 vgaSetPalette8bit(undefined1 * pal)
void drawAnimTextAt(char * text, uint16_t param_2)
```

Auto-named parameters: 1064 -> 1055.

## Three DGROUP bytes are constants, not variables

`2410:0728`, `2410:073C` and `2410:074B` were re-checked in the fresh export: **none
of them is ever written**, so they are initialised data rather than state.  Their
values, read from the image, and the roles their uses give them:

| address | value | every use |
|---|---|---|
| `2410:0728` | `0x4E` (78) | the minuend of y coordinates: `(uint)byte_0728 - offset` passed as a y argument to four drawing calls |
| `2410:073C` | `0x0D` (13) | subtracted from tile corner heights before the average is clamped to the lowest corner, so the result is at most `lowestCorner - 13` |
| `2410:074B` | `0x1F` (31) | the minuend of a y coordinate in `constr_36ce_1f99`/`init_3381_08dc`: `(uint)byte_074B - offset` |

Naming them would mean asserting what those baselines are (a panel row, a wall height);
the arithmetic fixes only that they are constants subtracted from a coordinate, so they
keep their generated names with the values recorded.  Note that the same region holds
other referenced bytes (`0730`, `0731`, `0740`, `074D`, `074E`) which are equally
constant, so this is a family, not three isolated cases.

### Eleventh pass: terrain neighbour tables and a player-exclusion array

`init_3381_2883` copies two constant tables and uses them as neighbour data while
generating terrain:

```c
F_SCOPY(0x4f2, ..., edgeMasks);        /* 16 bytes = 4 directions x 4 values */
*puVar1 = *puVar1 | (uint)edgeMasks[bStack_13 * 4 + (uVar3 & 0xff)];
F_SCOPY(0x502, ..., neighbourOfs);     /* 8 bytes = 4 pairs */
init_3381_233e(x + (neighbourOfs[bStack_13 * 2]     & 1),
               y + ((int)(uint)neighbourOfs[bStack_13 * 2] >> 1));
init_3381_233e(x + (neighbourOfs[bStack_13 * 2 + 1] & 1),
               y + ((int)(uint)neighbourOfs[bStack_13 * 2 + 1] >> 1));
```

The first table's values are OR-ed into a word (bit masks per direction), the second
packs `dx = value & 1` and `dy = value >> 1` (the four neighbour offsets).

`OVC24_5943_112e` keeps a per-player exclusion array indexed by the sheet's own flag:

```c
_fmemset(excludedFlags, 0, ...);
excludedFlags[*(byte *)((int)*(undefined4 *)(iVar5 << 2) + 0x3f)] = 1;  /* char_sheet_t.excluded */
if (((excludedFlags[1] == 0) && (1 < PlayerIndex)) ...
```

and draws a caption through `ovr_OVC15_4207_1c79(text, ...)`.

`OVC42_6d7a_033e` builds the blit rectangle it hands to `ovr_blitGfxRect`:
`memcpy(dst = &rect, src = BlitRects + 1, 10); rect.h = 150;   /* 10 = sizeof(brect_t) */

Auto-named locals: 218 -> 213.

### Refused

- `init_3381_2883`'s `local_e`/`local_f` are only `&local_e`/`&local_f` outputs of
  `init_3381_24c3`, initialised to zero and never otherwise used.
- `attact_3f0b_2a09`'s `local_1c` is only an `&local_1c` output of
  `attact_3f0b_277b`, tested for zero.
- `OVC42_6d7a_033e`'s `local_40[23]`/`local_78[13]` are `_fmemset` targets with no
  reader in the recovered body.

## `entity_t` is now fully recovered - the tail is a tick stamp

The machine code, not the decompiler, decides the width of `+0x34`:

```
5d45:035e  SUB AX,word ptr ES:[BX + 0x34]      ; elapsed = GameTick - tick
5d45:0362  CMP AX,0x19
5d45:0365  JNC ...
5d45:04c0  MOV word ptr ES:[BX + 0x34],AX      ; tick = GameTick
```

The decompiler had printed a 32-bit lvalue for both accesses, which is why the field
had been left as two bytes; the instructions are words.  The surrounding test is a
periodic-update gate (`elapsed >= 25`), the same timestamp idiom as the building
instance records.

`SetFieldType` cannot widen the field in place:

```
FAIL /entity_t+0x34 : Not enough undefined bytes to fit /stdint.h/uint16_t in
structure /entity_t at offset 0x34. It needs 1 more byte(s) to be able to fit.
```

so `RebuildEntity.java` was updated to build the record exactly as the sizes demand -
`Entities` is 33000 bytes for 600 records, so 55 bytes:

```
entity_t length=55
  +0  base : agnt_t   [52]
  +52 tick : uint16_t [2]
  +54 dir  : byte     [1]
```

and the decompile now reads `GameTick - peVar8->tick`.  `entity_t` is complete:
3 fields, 0 generated (`entity_t 3 0` in `naming_structs.tsv`).

## Three bit-plane tables feed a terrain-plane write

`OVC27_5ded_01ac` copies three 16-entry tables and writes each to a different VGA
plane of a 320-byte-wide region:

```c
F_SCOPY(2410:594A, ..., plane0);   F_SCOPY(2410:596A, ..., plane1);
F_SCOPY(2410:598A, ..., plane2);
*puVar3       = (char)plane0[bStack_3];   /* +0     */
puVar3[0x140] = (char)plane1[bStack_3];   /* +320   */
puVar3[0x280] = (char)plane2[bStack_3];   /* +640   */
```

The plane offset is what names them - each table can only ever land in its own plane.

Auto-named locals: 213 -> 210.  Generated struct fields: 33 -> 31.

## Struct fields re-examined (no name added)

| field group | search result | conclusion |
|---|---|---|
| `anm_t` `0x10`..`0x1d` | the only `field_0x18` hits are symbol-relative addresses such as `&AgntAnms[0x75].field_0x18`, i.e. DGROUP addresses rendered through the wrong symbol | still no typed `anm_t` read of that block |
| `agntG_t+0x52`, `+0x94` | no `field_0x52`/`field_0x94` access anywhere in the export | unread |
| `entity_t+0x34`/`+0x35` | `SUB/MOV word ptr ES:[BX+0x34]` | resolved: now `tick` |
| `agnt_t+0x11`, `+0x24`, `+0x25`, `+0x2a`; `bldtp_t+0x0c` | unchanged from the previous pass (writes of 0/1/random, equality tests only) | unchanged refusals |

### `OVC22_5087_056e` - still refused

The function the step named is the one whose export carries `Unable to track spacebase
fully` and `Type propagation algorithm not settling`, and its locals confirm it:
`local_c` is a loop counter (`for (local_c = 0; local_c < GLeaderCount; local_c++)`),
an entity index (`Entities[(int)local_c].base.y`), a `far_t *` and a byte
(`(char)local_c`) in different places.  Naming any of them would encode one of those
contradictions, so the function stays untouched.

## Twelfth pass: the sprintf-destination family

A scan of the stored locals against the fresh export found 35 of them in one role: the
**destination of `sprintf`/`stsprintf`**.  That is a single, mechanical piece of
evidence, so they were named in one batch rather than one function at a time.

### `msg` (28)

Every one of these is the first argument of a formatting call, i.e. the buffer that
receives the rendered text:

| function | local | function | local |
|---|---|---|---|
| `gameProcessKey` | `local_52[80]` | `manage_4d05_056e` | `local_7e[120]` |
| `copyProtectionCheck` | `local_5c[80]` | `manage_4d05_2bc4` | `local_106[256]` |
| `OVC13_3d16_1558` | `local_7a[80]` | `manage_4d05_330c` | `local_106[256]` |
| `attact_3f0b_18fe` | `local_56[80]` | `OVC25_5b66_085d` | `local_68[81]` |
| `saveui_4528_120d` | `local_16[20]` | `OVC25_5b66_173b` | `local_54[81]` |
| `OVC23_55fe_2e4c` | `local_56[80]` | `OVC25_5b66_1929` | `local_56[81]` |
| `OVC27_5ded_0a05` | `local_aa[151]` | `OVC28_6018_0251` | `local_104[128]` |
| `OVC27_5ded_0fd2` | `local_7a[120]` | `OVC27_5ded_105e` | `local_7a[120]` |

plus the remaining entries of the same shape.  Live check:

```c
char msg [80];
pcVar2 = ovr_stsprintf(msg, unaff_SS, (char *)"The seed is %lx.");
```

### `text` / `text2` (7)

These are the destinations of the ellipsis-truncation helper (`OVC45_77eb_226e`) or of
the text-draw call (`OVC15_4207_1c79`), i.e. buffers that are displayed rather than
formatted: `55fe:2e4c`, `6018:0251`, `6018:0456`, `6018:0813`, `67e7:004d`.  Two of
them collided with an existing `text` in the same function and became `text2`:

```
FAIL 55fe:2e4c local_a6 : DuplicateNameException: A Local Var symbol with name text
     already exists in namespace OVC23_55fe_2e4c
FAIL 67e7:004d local_58 : ... already exists in namespace season_67e7_004d
```

### Not in the batch

`fmVsprintf` (`474a:0953`) also formats into a local (`local_d0[200]`), but that local
sits inside the formatter itself, where the buffer holds padding state rather than a
message; it was left out deliberately.

Auto-named locals: 213 -> 177.

## Correction: `+0x53` exists in two different structures

Re-reading every `+0x53` access in the fresh export separates two things that an
earlier batch had merged:

| base expression | structure | accesses |
|---|---|---|
| `(int)*(undefined4 *)((uint)param_1 << 2) + 0x53` | `char_sheet_t` (the `217A` party-sheet pointer table) | writes `4`, `8`, `0xc`, `0xff` in `OVC22_5087_056e`; compared with `entity.base.level`; tested `< 4` in `upd_units_5087_1d7d` and `OVC23_55fe_0af5` |
| `*(byte *)((int)*(undefined4 *)(agent + 0x1d) + 0x53)` | `agntG_t` (via `gdata`) | `< 4` in `OVC27_5ded_1c94`; the level-band comparison in `OVC30_619c_025d` |

So the `4/8/0xc/0xff` writes cited earlier for `agntG_t+0x53` are actually
`char_sheet_t+0x53`, i.e. the **high byte of the `pad_52[2]` field at 0x52**.  The name
`levelLimit` on `agntG_t+0x53` still stands, but on its own evidence only: the `< 4`
test through `gdata` and the band comparison, plus the values read from the table
itself (`00 01 07 0B 0D FF` across the first fourteen records).

`char_sheet_t+0x53` is therefore also a level-cap byte (4/8/0xc, `0xff` = none) and
should be recovered when that struct is rebuilt - it cannot be named today because it
is the second byte of a two-byte `pad_52` component and `SetFieldType` cannot split a
component.

## `agntG_t+0x52`: the table data does not decide between the two readings

The step suggested reading the field across records, so all fourteen records at
`195d:26d6 + 0x52 + n * 0x95` were dumped:

```
rec  0 +0x52=00 +0x53=FF      rec  7 +0x52=00 +0x53=07
rec  1 +0x52=00 +0x53=FF      rec  8 +0x52=00 +0x53=FF
rec  2 +0x52=00 +0x53=FF      rec  9 +0x52=00 +0x53=0B
rec  3 +0x52=00 +0x53=FF      rec 10 +0x52=00 +0x53=FF
rec  4 +0x52=08 +0x53=0D      rec 11 +0x52=00 +0x53=FF
rec  5 +0x52=00 +0x53=FF      rec 12 +0x52=00 +0x53=00
rec  6 +0x52=00 +0x53=01      rec 13 +0x52=00 +0x53=01
```

`+0x52` is zero in thirteen of fourteen records and `08` in one; `+0x53` varies over
`00..0D` with `FF` as "none", which is what a level cap looks like and confirms the
`levelLimit` reading for the neighbour byte.

For `+0x52` itself the two consumers remain irreconcilable:

```c
/* OVC49_8699_1e09 - clean: uVar5 = *(undefined4 *)(agent + 0x1d) is gdata */
iStack_28 = *(int *)(iVar14 * 2 + 0x34c) + *(int *)(agent + 2) +
            (int)*(char *)((int)uVar5 + 0x52) + -0x16;

/* OVC22_5087_18b6 - suspect: the index is the high byte of the entity pointer */
uVar1 = *(undefined4 *)((uint)*(byte *)(iVar4 + 0x1a) << 2);
uVar2 = *(byte *)((int)uVar1 + 0x52) + 1;
if (*(byte *)(iVar4 + 0xf) < uVar2) uVar2 = *(byte *)(iVar4 + 0xf);
```

The first is a signed byte added to a screen y with a `-0x16` base; the second treats
it as a level floor, but reaches it through `*(byte *)(agent + 0x1a)`, which is the
high byte of the entity far pointer - a decompiler artifact, not a real index.  Since
the table says the value is 0 almost everywhere, both "default vertical offset" and
"minimum level - 1" fit, and the only *trustworthy* consumer is the offset one.  No
name is applied; naming it after the suspect consumer is exactly the kind of error the
`tier` -> `resource` correction taught us to avoid.

## One more local

`constr_36ce_023c` probes five columns with `constr_36ce_0101(x, -1, &local_6)`
(`x = -1, 0, 1, 2, -2`) and uses only the return value, so the local is the cell value
at the probed column: `cell`.

Auto-named locals: 177 -> 176.

## `char_sheet_t+0x39` is the leader's map position

The generic-agent constructor writes the two words at `+0x39` from its last two
arguments, and its caller hands it exactly the coordinates it had just passed to the
map-coordinate helpers:

```c
uVar8 = ovr_constr_36ce_306b(uVar11, (int)pbStack_c);     /* x, y - named earlier */
...
uVar8 = OVC30_619c_0339(param_1, uVar11, pbStack_c);

/* inside */
*(undefined2 *)sheet->pos     = param_2;   /* x */
*(undefined2 *)(sheet->pos + 2) = param_3; /* y */
```

So the four bytes are the leader's map position, stored as two words.  The field was a
`byte[4]` named `pad_39`; it is now `pos` with the layout in its comment (it cannot be
split into two `uint16_t` components without rebuilding the 38-field struct, and no
reader of the block exists yet to justify that).

Generated struct fields: 31 -> 30 (`char_sheet_t` 8 -> 7).  `char_sheet_t` still has
`pad_0`, `pad_31`, `pad_40`, `pad_52`, `pad_64`, `pad_82`, `pad_8e`, and its neighbour
`pad_52`'s high byte carries the 4/8/0xc level cap described above.

## `char_sheet_t` rebuilt: `pos` split into x/y and the level cap broken out

The two proven facts - that `+0x39` holds the map position as two words and that
`+0x53` is a level cap - could not be expressed by editing components in place, so the
structure was rebuilt from a description.  New tool: `scripts/ghidra/RebuildStruct.java`
takes a TSV of `offset<TAB>typePath<TAB>name<TAB>comment` lines, deletes every
component and re-adds them in order, supporting `type[n]` array syntax.

The description was generated from the existing layout, with two changes:

| offset | before | after |
|---|---|---|
| `0x39` | `pos` `byte[4]` | `x` `uint16_t`, `y` `uint16_t` |
| `0x52` | `pad_52` `byte[2]` | `pad_52` `uint8_t`, `levelLimit` `uint8_t` |

Verification that nothing else moved - every other component identical, size unchanged:

```
size before/after fields: 38 40
changed offsets:
  (57, ('pos', 4), ('x', 2))
  (59, None, ('y', 2))
  (82, ('pad_52', 2), ('pad_52', 1))
  (83, None, ('levelLimit', 1))
```

and the decompile now shows the words separately:

```c
sheet->x = param_2;
sheet->y = param_3;
```

### Honest accounting

This does **not** improve the audit's ratio: splitting two components adds two fields,
so the total moves 312 -> 314 while the generated count stays 30 (`char_sheet_t` still
has 7, because the remaining byte of the old `pad_52` keeps its generated name - the
0..10 value stored there in `OVC22_5087_056e` has no evidence to name it by).  What
improved is the description: the position is two words as the code writes it, and the
level cap is a field of its own instead of the unknown high half of a pad.

### Tooling notes

- A rebuild script must split TSV lines with a negative limit: Java's `split("\\t")`
  drops trailing empty fields, so rows with an empty comment were silently skipped and
  the first attempt left `char_sheet_t` as three components.  The struct was rebuilt
  again from the untouched description and the layout compared against the previous
  CSV, which is how the table above was produced - a rebuild is never accepted without
  that comparison.
- `line.trim()` before splitting removes the trailing tab as well, which is the same
  trap from the other side; the check is now `line.trim().isEmpty()` instead.

### One more local: chargen's menu array

`chargen`'s `local_92` is the first `far_t` of a menu array - entry 0 is set directly
(`0x2410:4FCE`) and the rest through `(&local_92)[i].seg` / `(&local_92 + i)->ofs`, with
a parallel synthesized byte array holding the entry codes:

```c
local_92.seg = 0x2410;  local_92.ofs = 0x4fce;
(&local_92)[iVar6].seg = *(uint16_t *)(iStack_12 * 4 + 0xed);
(&local_92 + iVar6)->ofs = uVar5;
```

so it is `menuItems`.

Auto-named locals: 176 -> 175.

## `char_sheet_t+0x31` is the hit-point pair

`manage_4d05_11cb` rolls the character's hit dice - the sum over its levels of
`randBelow() + CON-modifier + 1`, clamped to at least 1 - and stores that total into
both bytes of the field:

```c
for (iVar5 = 0; iVar5 < pcVar4->race; iVar5 = iVar5 + 1) {
    bVar1 = ovr_randBelow();
    cVar2 = manage_4d05_118b(pcVar4->stats[4]);   /* CON modifier, proven earlier */
    iVar3 = (uint)bVar1 + (int)cVar2 + 1;
    if (iVar3 < 1) iVar3 = 1;
    iStack_4 = iStack_4 + iVar3;
}
pcVar4->hp[0] = (byte)iStack_4;
pcVar4->hp[1] = (byte)iStack_4;
```

The machine code confirms these are two separate byte stores of the same value, not a
16-bit word:

```
4d05:1242  MOV byte ptr ES:[BX + 0x31],AL
4d05:124c  MOV byte ptr ES:[BX + 0x32],AL
```

so the field is a current/maximum pair initialised from one roll, and `pad_31` became
`hp`.  Nothing reads it back in the export, so the name rests on the roll and on that
initialisation, not on a reader.

Generated struct fields: 30 -> 29 (`char_sheet_t` 7 -> 6).

## Three index parameters from their record-count bounds

A scan for parameters bounded by the record counts found three counters whose limit and
stride settle them:

| function | parameter | bound / use | name |
|---|---|---|---|
| `OVC18_48ac_0382` | `param_2` | `param_2 = param_2 + 1; if (GRecordCount <= param_2)` | `recordIndex` |
| `OVC23_55fe_0af5` | `param_2` | `param_2 = param_2 + 1; if (GUnitCount <= param_2) break;` then `(int)param_2 * 9` indexes `GUnits` | `unitIndex` |
| `stats_6386_1c9f` | `param_1` | `if (AgntCount <= param_1) return AgntCount;` | `agntIndex` |

The first two were typed as pointers only because the decompiler rendered the increment
as a pointer bump (`param_2 = (int *)param_2 + 1`); both are two-byte values, so they
were retyped to `int16_t`/`uint16_t` without changing the calling convention.

Live signatures:

```
uint * OVC23_55fe_0af5(int param_1, uint16_t unitIndex, byte param_3)
char * OVC18_48ac_0382(far_t param_1, int16_t recordIndex, int * param_3, ...)
byte stats_6386_1c9f(byte agntIndex, byte param_2, int16_t param_3, ...)
```

Auto-named parameters: 1055 -> 1052.

## `OVC41_6a8f_016b`: the argument list has a padding byte

Callers pass two far pointers and a flag, and the stack layout proves it:

```
6a8f:0171  MOV AL,byte ptr [BP + 0xa]        ; the flag
6a8f:017a  LES BX,[BP + 0xc]                 ; second far pointer: offset +0xc
6a8f:019d  PUSH word ptr [BP + 0x8]          ; first far pointer: segment +8
6a8f:01a0  PUSH word ptr [BP + 0x6]          ;                    offset  +6
6a8f:01bf  PUSH word ptr [BP + 0xe]          ; second far pointer: segment +0xe
6a8f:01c2  PUSH word ptr [BP + 0xc]
```

So the layout is `+6..+9` (pointer), `+0xa` (flag), **`+0xb` is padding**, `+0xc..+0xf`
(second pointer).  Ghidra does not insert that padding itself, so the prototype declares
it: `void OVC41_6a8f_016b(agnt_t *agnt, byte flag, byte pad, agnt_t *other)`.

`pad` is a representation name for a real padding byte, not a claim about meaning; the
alternative would be to leave it `param_3`.  The two pointers are now four-byte types and
the first one reads correctly: `OVC41_6a8f_29ea(agnt);`.

Residual limitation: the second pointer's *field* accesses still render as
`CONCAT11(in_stack_0000000b, pad) + 0xd` instead of `other->gindex`, because Ghidra has not
bound the far pointer across the padding byte; the value itself is passed correctly
(`ovr_OVC15_4207_26bc(..., (agnt_t *)other, ...)`).

Auto-named parameters for this function: 4 -> 0.

## Two more parameters from their bodies

| function | parameter | evidence | name |
|---|---|---|---|
| `agnt_3b1d_0ac0` | `param_2` | `pcVar1 = ovr_stsprintf(param_2, in_stack_0000000a, "he...")` | `text` |
| `constr_36ce_0101` | `param_3` | writes the raw cell value through it (`*param_3 = iVar1`) before scaling; callers pass the corner slots | `cell` |

Auto-named parameters: 1052 -> 1046 over the turn; struct-typed functions: 120 -> 121.

## `bldtp_t+0x1e` is a half-width, and it has a computing consumer

The machine code decides the width - a **word**, not two bytes:

```
6616:0063  MOV SI,word ptr ES:[BX + 0x12e]
```

and the consumer scales it and uses it as a span around the unit:

```c
iVar5 = *(int *)(bldType * 0x27 + 0x12e);
uVar3 = ovr_constr_36ce_3172(x, y) & 0xff;      /* terrain type */
if (uVar3 == 3)      iVar5 = iVar5 * 3 >> 1;   /* +50% */
else if (uVar3 == 4) iVar5 = iVar5 << 1;       /* +100% */
if (unitType != 0xff && (unitType->[0x5d] & 8)) iVar5 += 5;
...
uVar6 = ovr_OVC23_55fe_3450(iVar4 + iVar7 * -2);   /* left  edge */
uVar6 = ovr_OVC23_55fe_3450(iVar4 + iVar7 *  2);   /* right edge */
```

so the building type carries a **half-width** that terrain and a unit flag widen, and the
drawing code turns it into `x +- halfWidth * 2`.  A zero value means "nothing to draw"
(the callers guard with `!= 0`).  The two 1-byte components at `0x1e`/`0x1f` were merged
into one `uint16_t` named `halfWidth`, which required rebuilding the struct (SetFieldType
cannot span adjacent byte components).

`RebuildStruct.java` gained `BASE *` (two-byte) and `BASE *32` (four-byte) specs so the
existing pointer fields could be reproduced exactly; the layout comparison shows only the
intended change:

```
30 ('-', 1) -> ('halfWidth', 2)
31 ('-', 1) -> None
```

Generated struct fields: 29 -> 27 (`bldtp_t` 4 -> 2); total fields 314 -> 313.

### Tooling trap: placeholder names inflate the audit

`AuditTypes` renders a generated component name as `-`, and my first rebuild fed that
back in as the component's *real* name, so two unidentified bytes at `0x0c` and `0x24`
stopped matching `AUTO_FIELD` and were counted as named.  They were renamed back to
`field_0x0c`/`field_0x24` before quoting any number - the audit above is measured after
that correction.

## Four locals from constant-table copies

| function | local | name | evidence |
|---|---|---|---|
| `constr_36ce_0995` | `local_18[6]` | `shades` | copied from `2410:0745` (10 0C 06 04 02 01) and fed one per step as the colour of the rectangle calls |
| `manage_4d05_0166` | `local_c` | `rect` | copied from a brect-shaped constant (`2410:493B` = 12,99,222,150,seg 0xA000) and passed to `ovr_blitGfxRect` |
| `OVC27_5ded_052d` | `local_c[10]` | `reqLevel1` | ascending table `00 01 03 05 07 09 0B 0F 12 15` compared with the entity level, indexed by a unit-record byte |
| | `local_1c[12]` | `reqLevel2` | the second table at `2410:59B4`, same comparison |

```c
if (*(byte *)((int)*(undefined4 *)(iVar7 + 0x17) + 0xf) < reqLevel1[*(byte *)(iVar6 + 9)])
    return ...;
```

Auto-named locals: 175 -> 171.

## Readers re-checked

- `agntG_t+0x94`: the `+ 0x94` hits all belong to other bases (the `217A` party-sheet table
  and `*piVar23 + 0x8e/0x94`), so the field still has no reader.
- `bldtp_t+0x1f` no longer exists as a separate field (merged into `halfWidth`).
- `bldtp_t+0x24`: byte, tested `& 0x80` only.
- `agntG_t+0x52`: unchanged - two consumers, one clean (a signed y offset) and one that
  indexes a table with the high byte of an entity pointer (a decompiler artifact).

## Two locals that are slices of a named table

`manage_4d05_2d79` copies parts of `LevelBandLabels` into two locals and uses them exactly
as that table is used elsewhere - as label far pointers:

```c
F_SCOPY(LevelBandLabels,       ..., bandLabels);    /* first slice  */
F_SCOPY(LevelBandLabels + 0xc, ..., bandLabels2);   /* second slice */
in_DX = bandLabels[pcVar15 * 2];
ovr_blitLabel((char *)bandLabels[iVar9 * 2], (uint8_t *)bandLabels[iVar9 * 2 + 1], ...);
```

Auto-named locals: 171 -> 169.

## `char_sheet_t.pad_0` is the record prefix, and it holds the owner

`pad_0` is a `byte[40]` at offset 0, so `sheet->pad_0 + N` is simply `sheet + N`.  That
re-reads the three `OVC43_6fbe_0000` uses as accesses to `+0` (an index), `+4` (a value
minus 11) and `+6` (a base pointer), and gives the decisive one in `manage_4d05_2d79`:

```c
} while (*(int *)(iVar10 * 0x34 + 0x1b) != *(int *)(sheet->pad_0 + 0x1b));
```

left side is `agnt_t+0x1b` (the agent's `owner`), so `char_sheet_t+0x1b` is a **dword owner
id** - the same quantity in the sheet record.

It is not renamed, and the reason is measurable rather than lazy: splitting the 40-byte pad
into `blob[0x1b]` + `owner` + `blob[9]` would turn one generated component into **two**
(the two residual blobs are still pads), so the operation would *raise* the generated
field count by one while only one field gained a name.  It is recorded here as the concrete
shape to apply if `char_sheet_t` is ever rebuilt field by field with the other two blobs
identified at the same time.

## `agntG_t+0x52`, `+0x94` re-checked in the new export

Nothing changed in `tmp/decompiled6`: `+0x52` still has one clean consumer (a signed y
offset, `+ -0x16`) and one that indexes with the high byte of an entity pointer, and `+0x94`
has no reader at all.  Both stay unnamed.

### Parameters stored straight into the field they are named after

A scan for `-><field> = param_N` assignments found three:

```c
/* OVC30_619c_0339 */
sheet->x = param_2;   sheet->y = param_3;
/* OVC18_48ac_0bf4 */
((unit_t *)GUnits + unaff_SI)->bldType = param_3;
```

so they are `x`, `y` and `bldType`.  The live signature confirms the first two:
`uint OVC30_619c_0339(byte gindex, undefined2 x, undefined2 y)`.

Auto-named parameters: 1046 -> 1043.

## `anm_t`'s generated block has no reader - now verified field by field

`stshRleAnims` is the one function that walks an `anm_t` array with typed code, and it
reads these offsets:

```c
while ((i < nanims && (*(char *)(nanims + i * 0x1e + 0x1b) != '\0'))) {   /* nframes  */
  count = (uint)*(byte *)(nanims + i * 0x1e);            /* frmid  (0)  */
  sx = *(uint16_t *)(nanims + i * 0x1e + 1);             /* sx     (1)  */
  sy = *(uint16_t *)(nanims + i * 0x1e + 3);             /* sy     (3)  */
  ex = *(uint16_t *)(nanims + i * 0x1e + 5);             /* ex     (5)  */
  ey = *(uint16_t *)(nanims + i * 0x1e + 7);             /* ey     (7)  */
  ((frm_t *)frm)->x  = *(int16_t *)(nanims + i * 0x1e + 0xb);   /* x  (0x0b) */
  ((frm_t *)frm)->y  = *(int16_t *)(nanims + i * 0x1e + 0xd);   /* y  (0x0d) */
  if ((*(byte *)(nanims + i * 0x1e + 0x1c) & 1) == 0) {        /* flags (0x1c) */
  ((frm_t *)frm)->ow = *(uint8_t *)(nanims + i * 0x1e + 0xf);  /* ow (0x0f) */
}
```

Together with `fw`/`fh` (`+9`/`+10`) read elsewhere, that accounts for every offset the
code touches.  A whole-export search for `0x1e + 0x1[0-9a-d]` returns only `0x1b` and
`0x1c`, so the eleven generated bytes at `0x10..0x19` and `0x1d` are **never read by any
exported module** - they are asset-file data that the loader copies wholesale.  This is a
closed question rather than a pending one: no amount of further scanning will name them,
only the asset format would.

## `agnt_t`'s four state bytes: every access, once more

| field | accesses in `tmp/decompiled6` |
|---|---|
| `+0x11` | writes `0`, `1`, `randBelow()`; reads are `== 0` in five functions |
| `+0x24` | `== 0` (always beside `target != 0xff` / `animFrame != 0xff`), `== 2`, and writes `1`/`2` |
| `+0x25` | `== 1`, `== 0`, `!= 2`, `!= 1`, write `1` |
| `+0x2a` | one read, `peVar24[0xb4].base.field_0x2a == 0` |

No arithmetic or indexing on any of them, so none can be named from its use.

## Two more locals

| function | local | name | evidence |
|---|---|---|---|
| `OVC41_6a8f_08c2` | `local_a[4]` | `xOfs` | copy of `2410:6E00` (54, 39, 29, 16) added or subtracted from the record's first word (`agnt_t.x`) per direction |
| `OVC40_69c8_04c6` | `local_14` | `rect` | brect-shaped constant from `2410:6B86`, passed to the draw helper `OVC40_69c8_0373(param_1, 0xef, &local_14)` |

```c
*(int *)(uVar1 * 0x34) = *(int *)(agntIndex * 0x34) + xOfs[iStack_c];
*(int *)(uVar1 * 0x34) = *(int *)(agntIndex * 0x34) - xOfs[iStack_c];
```

Auto-named locals: 171 -> 167 over the turn; auto-named parameters: 1046 -> 1043.

## Two label helpers take one far text pointer and a row

`ovr_blitLabel(ofs, seg, font_ofs, font_seg)` is what revealed the split: the first two
arguments are one far pointer, and the callers pass literals plus a row index:

```c
OVC42_6d7a_078f((char *)"Demo cancelled.",        (char *)"puppetmaker" + 3, 0);
OVC42_6d7a_078f((char *)"where you settle.",      (char *)"puppetmaker" + 3, 1);
OVC42_6d7a_078f((char *)"Your goal: Create a thriving community.", ..., 2);

TextBlitY = (uint)row * 0xd + 0x9c;   /* 13 = row height */
```

so both helpers are `void (char *text, byte row)`.  The merged pointer reads back as one
value in the body, which is the check that the merge is right:

```c
void __cdecl16far OVC42_6d7a_0850(char *text,byte row)
{
  TextBlitY = (uint)row * 0xd + 0x9c;
  ...
  ovr_blitLabel((char *)text,text._2_2_,(int16_t)max_width,term);
}
```

`OVC40_69c8_0000` was left alone deliberately: it takes *two* far text pointers followed by
two byte arguments, and in 16-bit cdecl each byte still occupies a word slot, so widening
both pointers would place the bytes at `+8`/`+9` where the code reads `+0xa`/`+0xc`.  It
would need explicit padding parameters, which is a worse description than leaving the
split.

Auto-named parameters: 1043 -> 1037.

## Two buffers identified by their copy destination

| function | local | name | evidence |
|---|---|---|---|
| `drawString` (6386:24c2) | `local_c` | `rect` | `memcpy(dst = &rect:SS, src = BlitRects + 1, 10)` - one 10-byte `brect_t`; then `.y/.h/.x/.w` are overwritten before `ovr_blitGfxRect(gfx,0,0,&rect,...)`.  **Corrected**: the old three-argument `memcpy` rendering made `0x44a` look like a size, but it is the source offset and the real size is 10 |
| `blit_317e_04c2` | `local_160[320]` | `rowBuf` | `dst_00 = {ofs = rowBuf, seg = SS}; ovr_unrle(src, dst_00, width)` fills it with one decoded row, and `memcpy(dst, src = rowBuf + i, w)` copies it out - a decoded screen row.  **Corrected**: `320` in the old rendering was the source offset, not a byte count |

Auto-named locals: 167 -> 165.

### An export failure that is not a broken function

The new export reports `ok=1125 fail=5` (it was 1126/4); the additional failure is
`OVC45_77eb_0d61`.  It is **not** damaged: `DecompileAt 77eb:0d61` produces its usual 3030
lines on demand, and its signature still reads `undefined OVC45_77eb_0d61()` with its five
locals (`reqMsg`, `text`, `msg`, ...) intact.  So the `fail` is an artifact of that
`ExportAll` run (the batch decompiler gives up on some long functions), not a change in the
program.  Recorded so a later pass checks with `DecompileAt` before treating a missing body
as evidence.

## Split far-pointer scan: what is left, and why each refusal stands

Scanning the fresh export for `CONCAT22(param_2, param_1)` (the clearest signature of a
far pointer the decompiler split into two parameters) leaves only these non-CRT cases:

| function | why it is not merged |
|---|---|
| `OVC27_5ded_10ea` | Ghidra marks it *Unknown calling convention - yet parameter storage is locked*, so a prototype change is refused by the program model; its single caller also builds the pointer with `CONCAT13(...,CONCAT12((char)agnt,0x6a8f))`, i.e. a constant segment, and the function reads its agent index from a stack slot. |
| `OVC40_69c8_0000` | two far text pointers followed by two byte arguments; in 16-bit cdecl each byte still occupies a word slot, so widening both pointers would place the bytes at `+8`/`+9` where the code reads `+0xa`/`+0xc`. Expressing it correctly needs explicit padding parameters. |
| `OVC45_77eb_0d61` | the `CONCAT22` there builds a far pointer from a local plus a synthesized stack word (`local_5c` + `iStack_5a`); the pointer is not a parameter at all. |

### A function whose body cannot be recovered

`manage_4d05_1bee` fails in `ExportAll`; an earlier note said it also failed in
`DecompileAt`, but re-checking after the prototype fixes shows it decompiles on demand
(7841 lines).  Its three stored locals (`local_13`, `local_1f6`, `local_21e`, all
byte-sized slots at large stack offsets) are **never referenced** in that body, so there is
no writer or consumer to quote for them.  They stay unnamed: naming them from the offsets alone
would be guessing, which is exactly what the method forbids.  This is the one case where a
missing export really does mean a missing body, unlike `OVC45_77eb_0d61` from the previous
pass.

### Globals tail unchanged

The worklist regenerated from the current audit still reports the same 35 single-module
globals, every one of which has been examined and refused on its own evidence
(`00D8`, `5DF2`, `49F7`, `076F`/`0771`, `2272:002C/002E/003A/003C`, ...).  No new payload or
guarding comparison appeared after the recent renames, so nothing was named in this batch.

## Twelve XMS parameters, named by the structure they fill

Both block-move helpers write the caller's arguments straight into the XMS request
structure, which is what names them:

```c
XmsDstLo = param_1;  XmsDstHi = param_2;    /* destination address */
XmsSrcLo = param_3;  XmsSrcHi = param_4;    /* source address      */
if ((param_5 & 1) != 0) { ... }             /* odd length handling */
param_5 = param_5 - 1;  param_6 = param_6 - (uint)bVar1;
if ((param_6 == 0) && (param_5 == 0)) ...
XmsCmdLo = param_5;  XmsCmdHi = param_6;    /* count handed to the driver */
```

The pair `param_5`/`param_6` is a 32-bit count that is decremented with borrow and tested
for zero - not a flags word, which is what the `& 1` alone would have suggested.  So the
names are `dstLo/dstHi`, `srcLo/srcHi`, `countLo/countHi`, applied to both functions:

```
void xms_1000_032f(int dstLo, undefined2 dstHi, uint srcLo, int srcHi, uint countLo, int countHi)
void xms_1000_03c2(uint dstLo, int dstHi, int srcLo, undefined2 srcHi, uint countLo, int countHi)
```

Auto-named parameters: 1037 -> 1025.

## Eight more parameters: string destinations and string arguments

### A far string, not two arguments (correction)

`OVC15_4207_1c79` first looked like `(dest, src)` because the body renders as
`strcpy(param_1, param_2)`.  The callers say otherwise:

```c
ovr_OVC15_4207_1c79(text2, unaff_SS);      /* one far pointer, not two arguments */
```

and the body itself uses `_param_1`, the decompiler's far view of a single pointer.  So the
signature is one four-byte `char *`, and after `ApplyProto` + a `/char *` retype the body
reads

```c
char * __cdecl16far OVC15_4207_1c79(char *text)
{
  strcpy((char *)text,text._2_2_);     /* the split halves of the same pointer */
  cVar1 = toupper(*text);
  *text = cVar1;
  return (char *)text;
}
```

The `strcpy` line is still a decompiler artifact (it feeds the offset and segment halves to
`strcpy` as dst and src), and it is recorded as such rather than "explained" by inventing a
second parameter.  This is the same lesson as `SfxGfx`: a plausible-looking pair of
arguments can be one object.

### `sprintf` destinations

`stats_6386_12b7`'s second argument receives "  %s is ready." / "  %s is not readied.", so it
is `text`.

### Parameters walked as NUL-terminated strings

A scan for `strlen(param)` and for `_ctype[*param]` found five parameters that can only be
strings, all named `text`:

| function | parameter |
|---|---|
| `OVC15_4207_1c16` | `param_1` |
| `saveui_4528_10c5` | `param_2` |
| `stats_6386_065c` | `param_1` |
| `drawString` (6386:24c2) | `param_1` |
| `OVC50_8adb_0000` | `param_1` |

`OVC15_4207_1c16` was also retyped: its callers push two words for it
(`1c16(0x4f9c, 0x2410)`), so the single argument is a four-byte far pointer.  `ListVars`
confirms the type now reads `char *32 [4]` and the body starts with
`sVar2 = strlen((char *)text);`.  The `in_DX` visible beside it is a register artifact of
that function, not the parameter.

Auto-named parameters: 1025 -> 1017.

## A wrong CRT prototype that every `_fmemmove` call inherited

`_fmemmove` (1000:26d7) was described as `(dst, src, count)` with three **near**
pointers - six bytes of parameters, while the function actually consumes ten:

```
1000:26d7  PUSH [BP + 0xe]     ; count
1000:26da  PUSH [BP + 0x8]     ; second word
1000:26dd  PUSH [BP + 0x6]     ; first word
1000:26e0  PUSH [BP + 0xc]     ; fourth word
1000:26e3  PUSH [BP + 0xa]     ; third word
1000:26e6  PUSH CS
1000:26e9  CALL 0x1000:2685    ; __fmovmem
```

and the callee proves the layout, because it loads the pointers with far loads:

```
1000:2688  LDS SI,[BP + 0x6]    ; source  far pointer
1000:26a5  LES DI,[BP + 0xa]    ; destination far pointer
1000:26a8  MOV CX,word ptr [BP + 0xe]   ; count
```

A far pointer is four bytes in this program's data model, so ten parameter bytes are
`(dst, src, count)` with two four-byte pointers.  The old signature covered only the
first six, which had two consequences visible throughout the export:

- the count was invisible (it leaked into an `in_stack_...` slot), and
- the third displayed argument was the **source offset**, not the count.

Rebuilt as `void * _fmemmove(char *dst, char *src, word count)` and
`void * __fmovmem(char *src, char *dst, word count)`, with the pointer parameters
retyped through `/char *`.  Call sites now read correctly, e.g.

```c
_fmemmove((char *)CONCAT22(unaff_SS,cmap),(char *)CONCAT22(in_stack_00000006,gfx),0x300);
_fmemmove((char *)CONCAT22(unaff_SS,&agntCopy),
          (char *)CONCAT22(0x1726,(char *)(uStack_8 * 0x34)),0x34);
```

The wrapper's own body still renders oddly (`__fmovmem` forwarding through registers),
which is expected for a hand-written far-copy shim and does not affect callers.

### Evidence checked because of the change

Every documented claim that rested on an `_fmemmove` third argument was re-read:

- `OVC15_4207_2301`'s local was the one real casualty: the copy is **one** 0x34-byte
  record out of the agent table, not "count * 0x34".  It was renamed `agntCopy` and
  typed `agnt_t`, which is also why the decompile now shows `agntCopy.target = 0xff;`
  and passes `&agntCopy` as a struct pointer.
- `OVC23_55fe_1803`'s `recordIndex` still holds: the corrected call puts
  `recordIndex * 0x12` at segment `0x21f2`, i.e. the 0x12-stride record array.
- the `seasonPalette`/`colorA`-`colorC` destinations in `calcSeasonPalette` still hold;
  the corrected calls write `dstOfs + 0x2d0`, `+0x2ac`, `+0x2b2`, `+0x2be`.

## `calcSeasonPalette`'s two far pointers

With the copy prototype fixed the calls are legible:

```c
_fmemmove((char *)CONCAT22(dstSeg,dstOfs),(char *)CONCAT22(srcSeg,srcOfs),0x300);
_fmemmove((char *)CONCAT22(dstSeg,dstOfs + 0x1e0),
          (char *)CONCAT22(uVar1,psStack_6),0x90);
_fmemmove((char *)CONCAT22(dstSeg,dstOfs + 0x2d0),
          (char *)CONCAT22(unaff_SS,seasonPalette + (uint)GSeason * 0x2d),0x2d);
```

and every caller passes `->cmap` first and a local buffer third:
`ovr_calcSeasonPalette(psVar2->cmap, iVar3, &stack0xfcfa, unaff_SS);` - so
`srcOfs`/`srcSeg` and `dstOfs`/`dstSeg`.

## `heapMemmove` and the audio block aligner

| function | parameters | evidence |
|---|---|---|
| `heapMemmove` (6316:0039) | `dstOfs`, `dstSeg`, `srcOfs`, `srcSeg`, `countLo`, `countHi` | `ovr_mkp(param_1, param_2)` / `ovr_mkp(param_3, param_4)` are the two far pointers of the `_fmemmove`, and the last pair is decremented with borrow (`param_6 -= (param_5 < count); param_5 -= count;`) |
| `audio_3a5b_0761` | `ofs`, `seg`, `size` | `if ((param_1 & 0xf) == 0) alignToSeg(...)` else `_fmemmove((CONCAT22(param_2 + 1, param_1) & 0xfffffff0), CONCAT22(param_2, param_1), param_3 - 0xf)` - shifts the block one paragraph to align the offset |

## Three agent-index parameters, re-confirmed after the export refresh

| function | parameter | evidence |
|---|---|---|
| `OVC27_5ded_052d` | `param_3` -> `agntIndex`, `param_1` -> `agnt` | `uVar2 = param_3 * 0x34; CONCAT22(0x1726, uVar2)`; `param_1` is dereferenced at `+0x1d` (gdata) and `+0x17` (entity) |
| `stats_6386_1abe` | `param_1` -> `agntIndex` | `*(int *)(param_1 * 0x34 + 0x1b)` (owner) and `drawAgntStats(CONCAT22(0x1726, param_1 * 0x34), ...)` |
| `OVC41_6a8f_2084` | `param_2` -> `agntIndex` | `paVar4 = (agnt_t *)((long)param_2 * 0x34); ... paVar9->flags & 0x820` |

Auto-named parameters over the turn: 1017 -> 997.  Struct-typed arguments: 121 -> 122.
The stored-variable inventory moved 3117 -> 3112 rows because the two copy wrappers now
have five parameters each instead of six near ones.

## `memcpy` had the same wrong prototype as `_fmemmove`

`memcpy` (1000:261e) is the second hand-written far-copy wrapper, and it was also
described with near pointers, so the same two symptoms appeared: the count was hidden
and the third displayed argument was the source offset.  Its machine code:

```
1000:2625  LES DI,[BP + 0x6]               ; destination far pointer
1000:2628  LDS SI,[BP + 0xa]               ; source far pointer
1000:262b  MOV CX,word ptr [BP + 0xe]      ; size
1000:2631  MOVSW.REP ES:DI,SI
```

Rebuilt as `void * memcpy(char *dst, char *src, word size)` with `/char *` retypes.
A call site that reads correctly now:

```c
memcpy(dst = &rect:SS, src = BlitRects + 1, 10);
```

### Evidence corrected by the change

| claim | before | after (verified) |
|---|---|---|
| `drawString`'s `rect` | `memcpy(&local_c, ..., 0x44a)` read as a 0x44a-byte copy | one 10-byte `brect_t` from `BlitRects + 1`; the name stands, the size did not |
| `blit_317e_04c2`'s `rowBuf` | `memcpy(..., local_160 + i, 320)` read as a 320-byte copy | `ovr_unrle(src, {ofs=rowBuf, seg=SS}, width)` fills it, then `memcpy(dst, rowBuf + i, w)` copies it out; the name stands, the role is clearer (one decoded row) |
| `IndexPermC`/`IndexPermD` | `memcpy(&X, 0x6e14, 0xc)` | `memcpy(&IndexPermC, (char *)0x24106e08, 0xc)` - a 12-byte table copy, as the naming assumed |
| `attact_3f0b_05df`'s square-record save | `memcpy(0x9074, &word_...086E, 0x13)` | `memcpy(dst = 0x2410:0x9074, src = &SquareRecX, 0x13)` |

## Parameters named from the corrected `memcpy` calls

| function | parameters | evidence |
|---|---|---|
| `stats_6386_01a4` | `gdata` (`agntG_t *`), `portraitIndex`, `palette` | caller passes the agent's `gdata` far pointer (`agnt_t+0x1d`); the body indexes `agntG_t.prts`/`agntG_t.prtpals` (both `far_t[6]`) with the byte index; the third argument is `calcSeasonPalette`'s destination and receives `gfx->cmap + 3` for 0xed bytes |
| `video_13aa_0266` | `srcSeg`, `x`, `y` | caller `video_13aa_0266(0xa000, dx, dy)`; body copies `min(0x140 - x, 0x11)` pixels from `srcSeg:(x + y * 0x140 + row)` for `min(200 - y, 0x11)` rows |
| `agnt_3b1d_177f` | `agntIndex` (was `index`), `agntSaved` (`agnt_t`, was `local_36`) | the function keeps the agent table ordered: it saves the record, shifts the ones between with `_fmemmove`, then writes the saved 0x34-byte record into its new slot |

The typed access confirms the portrait tables:

```c
if (((paVar2->prts + portraitIndex)->ofs != 0 || paVar2->prts[portraitIndex].seg != 0) &&
    ((paVar2->prtpals + portraitIndex)->ofs != 0 || paVar2->prtpals[portraitIndex].seg != 0)) {
    handle_00.seg = paVar2->prtpals[portraitIndex].seg;
```

Auto-named parameters: 997 -> 991; auto-named locals: 165 -> 164; struct-typed
arguments: 122 -> 123.  New evidence base: `tmp/decompiled9` (ok=1125 fail=5) and
`tmp/allvars11.csv` (3112 vars).

## The construction-record builder: `OVC23_55fe_184e` and its trampoline

These two functions create the 0x12-byte construction records at segment `0x21f2`,
and the field stores name the parameters:

```c
*(byte *)(GRecordCount * 0x12 + 8) = bldType;   /* bldType * 0x27 indexes bldtp_t   */
*(int  *)(GRecordCount * 0x12 + 2) = x;
*(int  *)(GRecordCount * 0x12 + 4) = y;
*(char *)(GRecordCount * 0x12 + 9) = partyIndex;
*(int  *)(GRecordCount * 0x12 + 0xf) = GameTick;   /* record timestamp */
*outFlag = 1;
```

`partyIndex` is confirmed twice over: it is stored at `+9` and used as
`(char *)(*(u32 *)(partyIndex << 2))->excluded`, i.e. an index into the party-sheet
far-pointer table; and the callers pass `PartyCount - 1`.

`x`/`y` come from the callers:
`1e87(0, GUnits[i].x, GUnits[i].y, ...)` and `1e87(0x89, GfxRndSeed - 2, GfxRndSeed2, ...)`.

`outFlag` is the byte that receives the 1, and every caller passes the address of a
local (`&cStack_1c`, `&local_5`).  Its companion word (`param_5`) is left unnamed: its
only use is inside the decompiler's 24-bit pointer build, so calling it a segment would
be a guess about the rendering rather than about the code.

### A merge that had to be reverted (recorded because it is instructive)

The first attempt declared the flag as one four-byte pointer:

```
void OVC23_55fe_184e(byte bldType, int x, int y, char * outFlag, char partyIndex)
```

which produced

```c
*(undefined1 *)CONCAT22((char *)outFlag, in_stack_000000a) = 1;
if (*(char *)((int)*(undefined4 *)((uint)outFlag._2_1_ << 2) + 0x3f) == '\0') {
*(char *)(GRecordCount * 0x12 + 9) = outFlag._2_1_;      /* partyIndex disappeared */
```

The four-byte pointer swallowed `partyIndex`'s word, because this function's arguments
are already word-aligned by the caller (`offset, segment, byte`), so widening the
pointer shifted every later parameter.  The prototype was reverted to the original
sizes with only the names changed, and the body became coherent again:

```c
_outFlag = (undefined1 *)CONCAT13(in_stack_0000000d,CONCAT12(param_5,outFlag));
*_outFlag = 1;
OVC23_55fe_1005(x + iVar4,y,0,partyIndex);
```

Same sizes, names only - the opposite lesson to `blit_317e_0879`, where widening a
split pointer *was* correct because the two words were adjacent halves of one argument.

Auto-named parameters over this turn: 991 -> 980.

## `OVC42_6d7a_0736` takes one far buffer

With the corrected far-copy prototype the two stack words become one pointer:

```c
void __cdecl16far OVC42_6d7a_0736(char *buf)
{
  _fmemmove((char *)CONCAT22(buf._2_2_,(char *)buf + 0x210),
            (char *)CONCAT22(buf._2_2_,(char *)buf + 0xf0),0xf0);
  for (pbVar2 = (byte *)0x0; pbVar2 < (byte *)0xfa00; pbVar2++) {
    bVar1 = *pbVar2;
    if ((0x4f < bVar1) && (bVar1 < 0xa0)) *pbVar2 = bVar1 + 0x60;
  }
}
```

i.e. it copies a 0xf0-byte block forward inside the buffer and then remaps the byte
range `0x50..0x9f` by `+0x60` - a demo transition effect.  The parameter is the buffer,
not two words.

## Re-checked, unchanged

`agnt_t+0x11`, `+0x24` and `+0x25` still have no computing consumer in `tmp/decompiled10`
- the only forms are `= 0`, `= 1`, `= 2` and `== 0` / `!= 2` / `< 2` tests.  The
`char_sheet_t` pads and `agntG_t+0x94` likewise keep their earlier refusals.

## Splitting isn't always wrong: the `far_t` parameter merges

A generic scan for the inverse pattern - two adjacent word parameters that the body
immediately stores into a `far_t` - found six functions, and in each of them the pair is
one pointer argument that the compiler passed as two words:

| function | merged parameter | body evidence |
|---|---|---|
| `OVC23_55fe_0863` | `far_t dst` | `dst.seg = param_2; dst.ofs = param_1;` then `ovr_animAdvance(..., dst)` and `ovr_constr_36ce_04e9(dst.ofs, dst.seg)` |
| `blit_317e_0db7` | `far_t gfx` | stored then `blitGfxN(gfx, ...)` |
| `blit_317e_1240` | `far_t gfx`, `far_t gfx_00` | two pairs, each passed to its own `blitGfxN` |
| `saveui_4528_055b` | `far_t gfx` | stored then `ovr_blitGfx10(gfx, ...)`, twice |
| `OVC20_4b0a_08ee` | `far_t buf` and `DW sz` | `buf.ofs/seg = param_1/2`, `sz.lo/hi = param_3/4`, then `StshCtOfs.lo += sz.lo; StshCtOfs.hi += sz.hi + carry` |
| `OVC42_6d7a_033e` | `far_t cmap` | `cmap.ofs/seg = param_4/5`, then `ovr_drawAgntStats(..., cmap)` |

Because a `far_t` is four bytes and the two words were four bytes, **every later argument
kept its slot** - that is the check that distinguishes this from the `OVC23_55fe_184e`
case above, where widening a pointer did move the following word.  The decompiled bodies
were compared before and after; e.g. `blit_317e_0db7` went from
`blitGfxN(gfx,...)` on a local to the parameter directly.

Live checks:

```c
void OVC23_55fe_0863(far_t dst)
... ovr_animAdvance(..., dst);  ovr_constr_36ce_04e9(dst.ofs,dst.seg);

undefined1 * OVC20_4b0a_08ee(far_t buf, DW sz)
... bVar2 = CARRY2(StshCtOfs.lo,sz.lo);  StshCtOfs.lo = StshCtOfs.lo + sz.lo;
```

## `uiReadString`: the merge was refused, so only the names changed

Its five words are two far pointers and a row:

```c
if (textOfs != 0 || textSeg != 0) { TextBlitX = 0x16; ...
                                    ovr_blitText(textOfs,(byte *)textSeg,...); }
TextBlitY = row * 0xf + 0x1d;                      /* 15 = row height     */
if (gfxOfs != 0 || gfxSeg != 0) { handle.seg = gfxSeg;
                                  handle.ofs = (uint16_t)gfxOfs;
                                  ovr_stshFree(handle); }   /* a supplied block */
```

`ApplyFunctionSignatureCmd` refuses the merged form here (even with the correct return
type), and one intermediate attempt with a 4-byte return type made it worse by inserting
a hidden `__return_storage_ptr__`; the original signature was re-applied and verified with
`ShowFunc` before the names were set.  The parameters are therefore named without merging:
`textOfs`, `textSeg`, `row`, `gfxOfs`, `gfxSeg`.  This is recorded as a tool limitation,
not a semantic doubt - the two halves are unambiguous.

Auto-named parameters over this turn: 980 -> 959 (8 merged away, 8 new merged-pointer
names, 5 names on `uiReadString`).  Struct-typed arguments: 123 -> 127.

## Two more `far_t` merges, and a refusal that turned out to be stale

### `OVC40_69c8_0000`: the case I had written off as needing padding

An earlier pass recorded that merging this signature's two far pointers would misplace
the two byte arguments.  That was wrong, and the merge works:

```c
void __cdecl16far OVC40_69c8_0000(far_t text1,far_t text2,byte row,byte param_4)
{
  if (GameRunning) ovr_OVC42_6d7a_0850((char *)text1,row);
  else {
    TextBlitY = (uint)row * 0xb + 0x98;
    iVar1 = ovr_font_302d_06ea((char *)text1,...);
    if ((text2.ofs == 0 && text2.seg == 0) || (iVar1 < 0x140)) ...
    else { text1 = text2; ... }
    ovr_blitLabel((char *)text1.ofs,(uint8_t *)text1.seg,...);
  }
}
```

So the arguments are two formatted lines (drawn, or replaced by the shorter one), a row,
and one byte the body never reads (every caller passes `0xf2`).  Ghidra places the byte
parameters on word slots itself, which is why the earlier "needs explicit padding"
conclusion was unnecessary: the `far_t` merges give 10 nominal bytes for 12 pushed bytes
and the binding is still correct.

The local names from the previous batch (`text1`/`text2` in `OVC40_69c8_04c6`) are the same
two lines, so the parameters carry the same names.

### `OVC43_6fbe_0000`: a sheet chain

```c
uStack_6 = (char_sheet_t *)CONCAT22(sheetSeg,sheet);
pcVar5 = (char_sheet_t *)(sheet->pad_0 + 6);
uVar6  = *(int *)(sheet->pad_0 + 4) - 0xb;
... param_2 = pcVar4;  param_3 = pcVar5;      /* advance to the next sheet */
```

`sheet`/`sheetSeg` are the two halves of one far sheet pointer.  They are **not** merged,
because keeping the near pointer typed gives readable field access (`sheet->pad_0`) and the
far view is needed in one place only; the segment half is typed `uint16_t` so the
`CONCAT22` reads honestly.

## An export failure does not mean a missing body - four checks

`ExportAll` gives up on five functions.  Each was retried with `DecompileAt`:

| function | on-demand result | conclusion |
|---|---|---|
| `constrct_7e7c_0b9c` | 5976 lines | four locals named below |
| `manage_4d05_1bee` | **7841 lines** | the earlier "fails in both" note was stale; its three stored locals (`local_13`, `local_1f6`, `local_21e`) are simply **never referenced** in the body, so they stay unnamed |
| `OVC49_8699_18c4` | 3009 lines | the body contains no stored `local_*` at all |
| `OVC45_77eb_0d61` | 3036 lines | already named in an earlier pass |
| `rle_line` (2d63:032d) | 2 lines | genuinely no body |

### Four locals in `constrct_7e7c_0b9c`

| local | name | evidence |
|---|---|---|
| `local_16` | `tileX` | `tileX = (GfxRndSeed + (uint)param_1) - 2;` then passed to `ovr_OVC45_77eb_20e8(&tileX)` and `ovr_OVC45_77eb_0179(tileX, GfxRndSeed2)` - the identical formula and consumers as `land_info`'s `tileX` |
| `local_ca[80]` | `text1` | destination of the ellipsis helper for a character name (`ovr_OVC45_77eb_226e(dst = text1, src = name, font, 0x46, 3)`) |
| `local_7a[72]` | `text2` | destination of the same helper for a unit-type name |
| `local_2ca[512]` | `msg` | `strcpy(msg, ...)` / `ovr_stsprintf(msg, ...)` before the `"%s (%d/%d): Owned by %s. Active party is %s the %s."` render |

Live check:

```c
undefined2 tileX;
tileX = (GfxRndSeed + (uint)param_1) - 2;
uVar15 = ovr_OVC45_77eb_20e8(&tileX);
uStack_26 = ovr_OVC45_77eb_0179(tileX,GfxRndSeed2);
```

Auto-named parameters over this turn: 959 -> 952.  Auto-named locals: 164 -> 160.
Struct-typed arguments: 127 -> 128.

## `char_sheet_t` pads: why the prefix is still not split

The step asked for a field-by-field rebuild now that `+0x1b` is a proven dword owner.
Re-checking every writer of the region first turned up a **conflict** that has to be
settled before any rebuild:

| function | store | reads as |
|---|---|---|
| `OVC18_48ac_05f2` | `*(uint16_t *)(uVar1 + 0x39) = GfxRndSeed;`  `*(uint16_t *)(uVar1 + 0x3b) = GfxRndSeed2;` | a coordinate pair |
| `OVC30_619c_0339` | `sheet->x = param_2;  sheet->y = param_3;` (caller passes map x, y) | a coordinate pair |
| `OVC43_6fbe_0000` | `*(undefined2 *)((char *)uStack_6 + 0x39) = uVar8;`  `*(char_sheet_t **)((char *)uStack_6 + 0x3b) = sheet;` | a pointer at `+0x3b` |

Two independent functions store a coordinate pair at `+0x39`/`+0x3b`, so the second
field is a y word and the earlier `pos` -> `x`/`y` split stands.  The `OVC43_6fbe_0000`
store sits inside a branch the decompiler mangled badly (that function carries
`Instruction at ... overlaps instruction at ...`, and the same branch emits
`_fmemset(sheet, sheet._2_2_, 0)` and `strcpy(sheet, sheet._2_2_)`), so it is recorded as
an artifact of that decompilation rather than as counter-evidence.  Had I trusted it, I
would have turned a proved field back into an unknown.

For the prefix itself the outcome is unchanged: `+0x1b` is a dword compared against
`agnt_t+0x1b`, but nothing in the export reads `+0x00`, `+4`, `+6` or any other prefix
byte except through that one comparison.  Splitting `pad_0` into
`byte[0x1b]` + `owner` + `byte[9]` would add two generated components to name one field
whose width the comparison alone does not fix (the left side of that comparison is itself
a 4-byte read spanning `owner` and the `gdata` word).  Not done, and the reason is
recorded rather than the step being silently skipped.

## Generated struct fields re-checked in `tmp/decompiled13`

| field | references | every form found |
|---|---|---|
| `agnt_t+0x11` | 10 | `= 0`, `= 1`, `= (char)uVar8`, `!= '\0'`, `== '\0'` |
| `agnt_t+0x24` | 12 | `= 1`, `= 2`, `== '\0'`, `!= '\x02'` |
| `agnt_t+0x25` | 9 | `= 1`, `= 2`, `< 2`, `!= '\x02'`, `== '\x02'` |
| `agnt_t+0x2a` | 0 raw | only the typed read `peVar24[0xb4].base.field_0x2a == 0` |
| `bldtp_t+0x0c` | 4 | `uStack_6._3_1_ < byte[bldType*0x27+0x11c]` and `instance[+6] = byte[...+0x11c]` (a bound copied into the build duration) |
| `bldtp_t+0x24` | 3 | `& 0x80` only |

No arithmetic or indexing appears on any of them, so the refusals stand.

## Four more parameters: a menu row's value and the destination segment

| function | parameter | evidence |
|---|---|---|
| `draw_2e25_0000` | `menuItem` | `(param_1 < 5) && MenuItemEnabled[param_1] != -1`, `param_1 * 0xd + 0x91` (row); callers pass `GMenuItem` |
| | `dstSeg` | passed last to `ovr_driver_2d63_05e5(..., SpecialColors[6], param_2)`; callers pass `TextBlitDstSeg` / `0xa000` |
| `draw_2e25_0098` | `value` | callers pass `*(byte *)(GMenuItem + 0x9082) + 1` and `- 1`, and the body stores it back: `*(undefined1 *)(GMenuItem + 0x9082) = (undefined1)param_1;` |
| | `dstSeg` | `param_2 == -0x6000` (0xa000) triggers `draw_2e25_0573()`; callers pass `TextBlitDstSeg` and `-0x6000` |

Auto-named parameters over this turn: 952 -> 948.

## The `dstSeg` family, mapped mechanically from the call sites

`tmp/dstseg_scan.py` walks every call in the export, splits the argument list, and maps
each argument that is literally `TextBlitDstSeg`, `0xa000` or `-0x6000` onto the callee's
parameter in that position.  Only five callees matched, and three of them already had the
parameter named, which is a good sign for the method: the scan re-derived `dst_seg`,
`dstSeg` and `dstSeg` where earlier passes had named them by reading one site.

The one unnamed case with many sites was `driver_2d63_05e5`, where 15 call sites pass a
screen segment as the sixth argument.  Its body settles all six names:

```c
if (x2 < x1) { x2 = x1; x1 = uVar3; }      /* ordering */
if (y2 < y1) { y2 = y1; y1 = uVar2; }
rows = (y2 - y1) + 1;  cols = (x2 - x1) + 1;
puVar7 = x1 + y1 * 320;                    /* 320-byte stride */
*puVar7 = colour;                          /* fill */
```

so `driver_2d63_05e5(x1, y1, x2, y2, colour, dstSeg)`.

The line drawer beside it is the same shape in offsets rather than coordinates:

```c
iVar2 = ofs2 - ofs1;   iVar3 = row2 - row1;
*ofs1 = colour;  ofs1 = ofs1 + 0x140;      /* vertical case */
```

so `vga_2d63_04b7(ofs1, row1, ofs2, row2, colour)`.

### `blitRaw`'s w/h were really inclusive end coordinates

`blitRaw` already had parameter names, but two of them were wrong in a way the arithmetic
shows plainly:

```c
iVar3 = (h - y) + 1;        /* rows, so h is the bottom coordinate, not a height */
iVar5 = (w - x) + 1;        /* cols, so w is the right coordinate               */
puVar6 = puVar6 + (0x140 - iVar5);   /* advance to the next row */
```

renamed to `x1, y1, x2, y2, srcSeg, dstSeg`.

### What the scan could not reach

The overlay copies of these same routines live at `22a6:00f2`, `22a6:0101`, `22a6:0043`
(`ovr_driver_2d63_05e5`, `ovr_vga_2d63_04b7`, `ovr_blitRaw`).  `RenameVars` addresses
functions with `AddressFactory.getAddress(addr)`, and for that segment it resolves to the
default address space, so `getFunctionAt` returns null and every line reports `NOVAR`:

```
NOVAR 22a6:00f2 param_1      (17 of 34 lines)
renamed=17 missing=17 failed=0
```

The 17 that did land are the `2d63:` twins, which is why the audit moved.  The overlay
entries keep their generated names until a script resolves overlay addresses by function
name instead of by address.  This is a tooling gap, recorded rather than worked around by
editing the wrong function.

## `OVC49_8699_18c4`: a rename that had to be reverted for the second time

Its `param_1` is unmistakably an agent record - the body reads `+0x11`, `+0x12`
(`frameIndex`), `+0x13` (`entity`), `+0x15` (`level`) and `[0]` (`x`).  Typing it as
`agnt_t *` did make the code read better:

```c
iVar13 = ovr_agnt_3b1d_005e(agnt->x);
if ((((agntG_t *)paVar20->gdata)->stdint_h_uint16_t & 4) == 0) {
```

but it also changed the *rest* of the signature, because a far pointer is four bytes and
the old `int *` was two:

```
before: uint OVC49_8699_18c4(int *param_1,byte *param_2,char *param_3,int param_4,char param_5)
after:  uint OVC49_8699_18c4(agnt_t *agnt,byte *param_2,int param_3,undefined2 param_4,char param_5)
```

and `param_3` became an entity index (`Entities[param_3]`) - proof that the arguments had
shifted.  The callers only push five words, so this function's true convention has a
segment word the model does not carry; widening a parameter cannot be correct until that
is resolved.  The original prototype was re-applied and verified with `ShowFunc`:

```
uint OVC49_8699_18c4(int * param_1, byte * param_2, char * param_3, int param_4, char param_5)
```

Auto-named parameters over this turn: 948 -> 937.

## The `22a6:` overlay entries are thunks - correcting my own tooling claim

Last pass reported that the overlay twins could not be renamed because their addresses
resolve in the wrong address space.  Extending `RenameVars` to fall back to a *name* lookup
(`FunctionManager.getFunctions(true)`, exactly-one match required) found the functions fine
and then still reported `NOVAR` for every parameter:

```
BYNAME ovr_driver_2d63_05e5 -> 22a6:00f2
NOVAR  ovr_driver_2d63_05e5 param_1
... renamed=0 missing=17 failed=0
```

The reason is not a tooling gap but a Ghidra feature: these entries are **thunks**.  Adding
thunk reporting to `ListVars` shows it directly:

```
FUNC ovr_driver_2d63_05e5 @ 22a6:00f2
THUNK of driver_2d63_05e5
param x1 uint 2
param y1 uint 2
param x2 uint 2
param y2 uint 2
param colour undefined1 1
param dstSeg undefined2 2
```

A thunk delegates its prototype to its target, so renaming `driver_2d63_05e5`'s parameters
*had already* renamed `ovr_driver_2d63_05e5`'s - which is why `param_1` no longer existed when
the overlay lines ran.  All three twins verify cleanly:

| thunk | target | parameters now |
|---|---|---|
| `ovr_driver_2d63_05e5` | `driver_2d63_05e5` | `x1, y1, x2, y2, colour, dstSeg` |
| `ovr_vga_2d63_04b7` | `vga_2d63_04b7` | `ofs1, row1, ofs2, row2, colour` |
| `ovr_blitRaw` | `blitRaw` | `x1, y1, x2, y2, srcSeg, dstSeg` |

`AuditNaming` iterates 1034 of the 1130 functions (it skips thunks), so those names cannot
move its counters - the previous turn's "17 NOVAR lines" were therefore the expected result,
not a failure, and the claim that a script change was needed to fix them is withdrawn.  The
name fallback stays in `RenameVars`/`ListVars` anyway, because it is what made the thunk
relationship visible, and it will be needed for any genuinely overlay-resident function.

## A mechanical family: locals that are a callee's out-parameter

`tmp/outparam_names.py` finds auto locals whose every use is `&local` passed to a parameter
that already has a real name.  The local *is* that out-parameter, so it takes the same name:

| function | local | name | callee parameter |
|---|---|---|---|
| `OVC18_48ac_05f2` | `local_5` | `outFlag` | `OVC23_55fe_1e87`'s `outFlag`, four call sites, never read |
| `OVC24_5943_112e` | `local_13` | `outFlag` | same |
| `stats_6386_232d` | `local_10` | `dst` | the destination rect of `blitGfx10`/`blitGfxRect`/`blitRect` |
| `OVC42_6d7a_078f` | `local_10` | `dst` | same |
| `stats_6386_1c9f` | `local_38` | `entries` | `ovr_uiInputText`'s `entries` |
| `OVC02_2e25_046b` | `local_c` | `rect` | `br` (a `brect_t *`) of `miceRestoreArea`/`miceBlitRect` |
| `attact_3f0b_2a09` | `local_16` | `rect` | same, called around every animation step |
| | `local_c` | `rect2` | same, around the one larger redraw |

A note on the last two: an earlier pass refused them because "naming by role would need the
meaning of the two screen regions".  That refusal was too strict - `rect`/`rect2` claims only
that they are the save/restore rectangles the calls write and read, which is exactly what the
call sites show; the region meaning is still not claimed.

Live checks:

```c
brect_t dst;  dst.y = 7;  dst.h = 0xc2;  dst.x = 8;  dst.w = 0xe2;
ovr_blitGfx10(gfx_00,0,0,&dst,SUB21(unaff_SS,0));

undefined1 outFlag;
ovr_OVC23_55fe_1e87(0x89,GfxRndSeed - 2,GfxRndSeed2,&outFlag,(byte)unaff_SS,PartyCount - 1);
```

Auto-named locals over this turn: 160 -> 152.  Auto-named parameters unchanged at 937
(the thunk parameters were already named by delegation).

## Function naming: convention, tooling and the first batch

Variable names are done function by function, so the function names had to stop being
address soup first.  The inventory (`scripts/ghidra/ListFuncs.java` -> `tmp/funcs3.tsv`)
is 1590 functions, of which 460 are thunks; 868 names still match an address-shaped
pattern.  The 460 thunks are already systematic: their names are `ovr_<target>`, so they
will follow their targets as those are named.

### Convention

- `<module>_<verb><Object>` - `driver_fillRect`, `createConstructionRecord`,
  `freeLeaderData`, `clearSquareRecords`.  The module word is the existing one where it
  meant something (`driver`, `stsh`, `agnt`, `constr`, `stats`, `saveui`).
- `ovr_<target>` for overlay entries (Ghidra thunks and the hand-written forwarders).
- The **address is not part of the name** any more.  `ExportAll` already writes
  `// <name> @ <addr>  [<module>]` at the top of every function, which is what makes
  dropping the address safe:

```
// driver_fillRect @ 2d63:05e5  [OVC01_driver.c]
/* fills the rectangle (x1,y1)-(x2,y2) with one colour */
```

Every rename also sets a one-line comment quoting the evidence, so the reason survives in
the export.  `doc/functions_renamed.tsv` keeps the old-name mapping.

### Tooling

- `scripts/ghidra/RenameFunctions.java` - TSV `address-or-name <TAB> newName <TAB> comment`.
  Resolves by name when the address does not resolve (overlay spaces), and renames every
  thunk called `ovr_<oldName>` to `ovr_<newName>` so the pair never drifts.
- `scripts/ghidra/ListFuncs.java` - address, name, thunk target, size, parameter count.

### First batch (14 functions, 9 thunks)

| address | old | new | evidence |
|---|---|---|---|
| `2d63:05e5` | `driver_2d63_05e5` | `driver_fillRect` | rows = `y2-y1+1`, cols = `x2-x1+1`, then writes `colour` along a 320-byte stride |
| `2d63:04b7` | `vga_2d63_04b7` | `driver_drawLine` | `ofs2-ofs1`, `row2-row1` drive a loop writing `colour`, `+= 0x140` per row |
| `2d63:0bc8` | `driver_2d63_0bc8` | `driver_zeroWords` | writes 0 to consecutive words, count from the third stack argument |
| `55fe:184e` | `OVC23_55fe_184e` | `createConstructionRecord` | writes the 0x12-byte records at 0x21f2: bldType `+8`, x `+2`, y `+4`, party `+9`, tick `+0xf` |
| `55fe:1e87` | `OVC23_55fe_1e87` | `createConstructionRecordFar` | forwards all six arguments to the above |
| `55fe:3450` | `OVC23_55fe_3450` | `alignUp4` | `return param_1 + 2U & 0xfffc;` |
| `3f0b:057a` | `attact_3f0b_057a` | `clearSquareRecords` | `SquareRecCount = 0;` |
| `3381:1fa9` | `init_3381_1fa9` | `clearEntities` | `EntityCount = 0;` |
| `302d:0a30` | `font_302d_0a30` | `resetTextBlitCycle` | clears both halves of `TextBlitCycle` |
| `3338:043e` | `init2_3338_043e` | `clearMiceProcessed` | `MiceProcessed = 0;` |
| `3381:1fba` | `init_3381_1fba` | `freeLeaderData` | `stshFree` on every leader sheet and four cached blocks, then `GLeaderCount = 0` |
| `3381:20ee` | `init_3381_20ee` | `freeGameResources` | `ovr_fmFreeAudio(1)` then `freeLeaderData()` |
| `1403:03d8` | `ovrman_1000_4408` | `ovl_rotateRight4` | `return AX >> 4 | DX << 0xc;` |
| `5ded:1be7` | `OVC27_5ded_1be7` | `emptyFunction` | empty body |

The thunks tracked automatically: `ovr_driver_fillRect`, `ovr_driver_drawLine`,
`ovr_createConstructionRecord`, `ovr_createConstructionRecordFar`, `ovr_freeGameResources`,
and five more.

### Deliberately not named yet

`agnt_3b1d_0a8d` (sets `health = 0` and clears one global byte, but has **no caller** in the
export); `draw_2e25_0245` (`(0x13f - x) * 0x80 / 0x140`, context not established);
`bldng_676c_05ac` (reads `GStrangeTable[i].ofs + 1`, table meaning unknown); and the trivial
predicates (`return param_1 != 1;`, `return *p != 0;`), where a name would only restate the
expression.  Each needs the surrounding module read before it earns a name.

### Second batch: the driver segment (2d63)

18 functions in `2d63` still had address-shaped names.  Five bodies were decisive:

| address | old | new | evidence |
|---|---|---|---|
| `2d63:02fe` | `driver_2d63_02fe` | `countRunLength` | compares `*p[0]` with successive bytes until a mismatch or the limit argument, returns the offset |
| `2d63:0b94` | `driver_2d63_0b94` | `lowNibble` | `return param_1 & 0xf;` |
| `2d63:0bad` | `driver_2d63_0bad` | `driver_copyWords` | `*dst = *src` over a word count from the fourth stack argument |
| `2d63:0aac` | `driver_2d63_0aac` | `driver_unrleScreen` | decodes 200 rows of run/literal pairs, destination advancing `0x140` per row |
| `2d63:0af7` | `driver_2d63_0af7` | `driver_unrleSprite` | header `param_1[0]` = row offset, `param_1[1]` = height; each run adds an x delta then copies literals or repeats a byte |

The last two were first written `driver_rleImage`/`driver_rleSprite` and then corrected to
`unrle` spelling, because the same segment already contains `unrle` (PCX run-length) and
`rle_blit_decode`; keeping one prefix means a reader can tell the three decoders apart by
their targets rather than by which synonym was used.

Deferred, with reasons: `driver_2d63_0107`/`014b` (a clamped sum scaled by five, role not
established), `driver_2d63_0652`/`0687` (a 2-wide, 3-tall two-colour diagonal stamp; the
terrain shading that consumes it is not visible from this segment), `driver_2d63_044e`,
`0846`, `09c9`, `0a24`, `0a67` (rect blits whose callers are not in the export), and
`driver_2d63_0599` (the decompiler shows a return of a stack argument - the prototype is not
trustworthy yet).

### The binary carries 48 original source comments

A scan for non-`WARNING` comments in the decompiled bodies found **48 functions whose
original C comments survived into the image**, e.g.

```
2d63:0000 mkp        packs seg+ofs into a uint32_t
2d63:00eb be4        Loads big-endian 32bit integer into DX:AX pair NOTE: the function has a bug
2d63:00fc be2        Flips bytes in a 16bt word
317e:0148 stshRleCut Cuts X,Y,W,H rect out of 8bit pixels pointed by src. returns ptrr to stg_t struct
317e:01b2 blitLoadRleGfx  typedef struct { ... uint8_t type; //0=not loaded, 1=loaded ... } gfx_t;
4b0a:07d3 stshSpriteStub  anms points to the array 0x1e sized anim_t entries, the last entry has nframes == 0 ...
```

Every one of those 48 already had a proper name, so they produced no renames - but they are
now the strongest available confirmation of those names, and three of them state facts no
amount of body-reading gave:

- `anm_t` entries are **0x1e sized** and the array is terminated by `nframes == 0`
  (`stshSpriteStub`'s own comment), which independently confirms the `0x1e` stride used
  throughout `stshRleAnims`.
- `gfx_t`'s layout is given in source: `type` (0 = not loaded, 1 = loaded), `sz`, `width`,
  `height`, then `pixels[width*height]`.
- `be4`'s comment names a **known bug** (high-order bytes swapped) - the function is not to
  be "fixed" during reconstruction.

This is a better source of names than body-reading wherever it exists, so the next batches
will start by harvesting these comments and then work outward through each module's callers.

`doc/functions_renamed.tsv` is updated with the whole driver batch.

## Struct fields re-examined with the named functions (no rebuild)

`char_sheet_t.pad_0`: every access in `tmp/decompiled19` is one of three:

```
manage_textTotal:   *(int *)(sheet->pad_0 + 0x1b)  !=  *(int *)(agent * 0x34 + 0x1b)
ovc43_usesFmFreeAudio: pcVar5 = (char_sheet_t *)(sheet->pad_0 + 6);
                       uVar6  = *(int *)(sheet->pad_0 + 4) - 0xb;
```

The `+0x1b` comparison is **not** proof of a dword: on the agent side `+0x1b` is the word
`owner` followed by the low word of `gdata`, so the decompiler widened a word comparison.
Splitting `pad_0` into `byte[0x1b]` + `owner` + `byte[9]` would therefore encode a guess
about the width and add two generated components to name one field.  Not done.

`bldtp_t+0x0c`: the only consumer is

```c
if (bStack_3 < *(byte *)(bldType * 0x27 + 0x11c)) instance[+6] = *(byte *)(... + 0x11c);
else                                            instance[+6] = bStack_3;
```

where `bStack_3` is taken from the *terrain* building type's `+0x0d` (`size`).  So the field
is a lower bound on the build duration - but the neighbouring `+0x0e` is already named
`minBuildTime`, and calling both minima would be a contradiction.  Settling which one is
the minimum needs a writer, and the export has none (the table is loaded data).  Refused,
with this evidence recorded.

`bldtp_t+0x24`: only `& 0x80`; `agntG_t+0x52`/`+0x94` and the `anm_t` block keep their
earlier refusals.

### Struct refusals re-confirmed after the latest re-export

- `char_sheet_t.pad_0` `+0x1b`: the comparison reads a dword on both sides, but the agent
  side spans `owner` (word) and the low word of `gdata`, so the width is a word; splitting
  `pad_0` would encode a guess and add two generated components.
- `bldtp_t+0x0c`: a lower bound on build duration, but `+0x0e` is already `minBuildTime` and
  no writer exists in the export to settle which is the minimum.
- `bldtp_t+0x24` (`& 0x80` only), `agntG_t+0x52` (one clean signed-y-offset consumer, one
  index through a pointer's high byte), `agntG_t+0x94` (no reader) and the `anm_t` block
  (`stshRleAnims` reads only the already-named fields) are unchanged.

## Parameters named from the recovered structs and the named callees

Two scans over `tmp/decompiled21` (with `allvars20.csv`): parameters that are stored
straight into a recovered field, and parameters passed as an argument whose callee
parameter already has a name.

### Stored into a field (24)

| function | parameters | evidence |
|---|---|---|
| `4207:10a3` (entity spawn) | `x`, `y`, `destX`, `destY`, `gindex`, `animFrame` | `Entities[EntityCount].base.x/y/targetX/targetY/destX/destY/gindex/animFrame = param_1..6` |
| `attact_3f0b_0ade` | `destX`, `destY` | `Entities[param_1].base.destX/destY = param_2/3` |
| `OVC25_5b66_00ff`, `_038d`, `_0530` | `destX`, `destY` | same two stores through `Entities[...]` |
| `OVC18_48ac_0bf4` | `unitType` | `((unit_t *)GUnits)[i].unitType = param_4` |
| `OVC15_4207_2301` | `owner` | `agntCopy.owner = param_1` |
| `OVC15_4207_16a5` | `gindex` | `Entities[i].base.gindex = param_2` |
| `OVC23_55fe_1005`, `2b9e`, `0617` | `bldType` | index `bldtp_t` with `* 0x27` (base 0x110) |
| `OVC23_55fe_1ea9`, `23d8`, `2f90` | `recordIndex` | index the 0x12-stride record array |
| `OVC26_5d45_06f0` | `entityIndex` | indexes `Entities[...]` and reads x/y/destX/destY/targetX/targetY |

### Passed to a named parameter (17)

`tmp/param_args.py` maps each call argument to the callee's parameter name at that position
and keeps only roles where **every** observation agrees and at least two sites exist:

| role | functions | sites |
|---|---|---|
| `x` / `y` | `init_3381_23f9`, `OVC13_3d16_0c22`, `OVC22_5087_4576`, `OVC10_36ce_2b9e` | 2-9 each |
| `partyIndex` | `manage_4d05_2bc4`, `manage_4d05_330c`, `OVC22_5087_0234`, `OVC22_5087_0411` | 2 each |
| `rect` | `OVC23_55fe_1ea9`, `23d8`, `OVC27_5ded_0cc2`, `OVC06_317e_1240` | 2-13 each |
| `outFlag` | `OVC22_5087_1674` | 4 |

The `rect` translation matters: the callee parameter is named `dst` but is typed
`brect_t *` (`blitGfxRect(gfx, x, y, dst, type, mirror)`), so the caller's argument is a
**rectangle**, not a destination.  Naming the callers' parameters `dst` would have hidden
the type the signature already shows.

### Examined and refused

- `OVC22_5087_056e`'s `param_4`/`param_5` were voted `dst` but the body writes
  `*(undefined1 *)CONCAT22(param_5,param_4) = 1;`, i.e. they are the two halves of a far
  **byte pointer**, not a rect and not a destination block.  The function is also one of the
  two whose decompilation is flagged unstable, so it stays untouched.
- `OVC23_55fe_0617`'s `param_1` is only ever a coordinate passed to the height probe; it has
  no stored field and no unanimous callee role, so it keeps its number.

Auto-named parameters: 937 -> 891.

## Locals named from unanimous call roles and from their own contents (7)

The parameter scan's rule was applied to the 152 auto-named locals: a local passed where the
callee's parameter already has a semantic name, with two or more sites and no disagreement.
Only eight candidates survived the filter, which is itself the finding: the local tail is
not hiding a large family.

| function | local | name | evidence |
|---|---|---|---|
| `constr_36ce_04e9` | `local_a` | `cell` | out-parameter of `constr_usesSmoothPrev(..., &local_a)`, then read as the cell in the shading call |
| `saveui_4528_0706` | `local_28` | `dest` | 0x1c-byte block `_fsetmem`-ed and passed as the destination of the blit/mouse helpers |
| `OVC27_5ded_10ea` | `local_124` / `local_d4` | `text1` / `text2` | both passed to `ovr_agnt_textHeld(agnt, text)`; the earlier refusal was about actor/target semantics, which these names do not claim |
| `OVC06_317e_08ed` | `local_15e` | `skip` | passed as `masked_memcpy`'s `skip` and used as an offset into the palette copy |
| `attact_3f0b_2430` | `local_8` | `agntX` | `local_8 = agnt->x`, then `alignUp4(&local_8, ...)` and `local_8 + dirOffset` |
| `OVC42_6d7a_08df` | `local_30c[768]` | `palette` | cleared, handed to `vgaSetPalette8bit`, filled by `calcSeasonPalette(..., local_30c, ...)`, used as `cmap.ofs` |

Live check:

```c
uint8_t palette [768];
_fmemset(palette,unaff_SS,0);
ovr_vgaSetPalette8bit(palette);
```

The 768 bytes (256 x RGB) are the type-level proof, independent of the calls.

### Examined and refused in the same pass

- `OVC22_5087_056e`'s `local_2a` (loads `.animFrame`) and `local_c` (loads `.y`): the function
  is one of the two with flagged-unstable decompilation, and its own locals already
  contradict each other, so nothing there is renamed.
- `OVC40_69c8_04c6`'s `local_5c` (stores into `.ofs`) and `OVC42_6d7a_08df`'s sibling
  `local_30c`-style blocks were re-checked; the first is the pointer-array copy already
  refused for inconsistent sizing.

Auto-named locals: 152 -> 145.  No local remains whose only use is an unexamined call.

## Parameters (second pass with named callees): 39 more

Two cycles of `tmp/param_scan4.py` against `decompiled23`/`decompiled24`: role A is
"stored into a recovered field", role B is "passed where the callee's parameter is named,
unanimous over >=2 sites", role C accepts a **single** site only when the callee's
parameter names a concrete recovered role (a coordinate, a colour, a party/unit/entity
index, an out-flag, or an agent pointer).

| function | parameters | evidence |
|---|---|---|
| `OVC45_77eb_0778` | `x`, `y` (12 sites each) | callers pass them where a drawing helper takes x/y |
| `OVC45_77eb_0aea` | `x`, `y` (3 / 6 sites) | same |
| `blit_317e_0db7` | `x`, `y` | same |
| `init_3381_24c3`, `stats_6386_1c9f` | `x`, `y` | same |
| `OVC07_32c9_03c4` | `x1`, `y1`, `x2`, `y2`, `colour` | passed as `fillRect`'s five arguments |
| `OVC07_32c9_0466` | `ofs1`, `row1`, `ofs2`, `row2`, `colour` | passed as `drawLine`'s arguments |
| `OVC15_4207_26bc`, `stats_6386_05d3` | `agntPtr`, `agnt` | passed where the callee takes `agnt_t *` |
| `OVC22_5087_4975`, `OVC23_55fe_0000` | `partyIndex`, `outFlag` | the two roles of that pair |
| `OVC26_5d45_06f0` | `outFlag` | passed as the out-flag |
| `OVC23_55fe_0f39` | `unitIndex` | passed as a unit index |
| `OVC45_77eb_1754` | `entityIndex` | passed as an entity index |
| `OVC23_55fe_1ea9`, `23d8`, `OVC27_5ded_0cc2`, `OVC06_317e_1240` | `type` | the blit `type` argument |
| `stats_6386_0411` | `term` | `blitLabel`'s terminator argument |
| `saveui_69c8_0373` | `rect` | already typed `brect_t *`, passed where the callee calls it `dst` |
| `OVC49_8699_1753` | `count` | five sites pass it as a count |

### The collision that RenameVars is supposed to catch

Typing `OVC41_6a8f_2084`'s first parameter as `agnt_t *` and naming it `agnt` failed:

```
FAIL 6a8f:2084 param_1 : DuplicateNameException: A Local Var symbol with name agnt
     already exists in namespace ovc41_textOnlyPlaceSingle
```

The function already had a local `agnt` from an earlier pass, so the parameter became
`agntPtr` instead - and because `RenameVars` applies the type before the name, the type had
already landed, which the signature confirms:

```c
byte * ovc41_textOnlyPlaceSingle(agnt_t * agntPtr, int agntIndex)
```

### Refused in this pass

- `OVC22_5087_056e`: the vote offers `partyIndex`, `dst` and `type`, but the function is one
  of the two with flagged-unstable decompilation and its `param_4`/`param_5` are the halves of
  a far byte pointer (`*(undefined1 *)CONCAT22(param_5,param_4) = 1;`), not a rect.  All of
  its parameters stay as they are.
- Role A hits that store into `.ofs`/`.seg` of a local `far_t` (12 cases) were not renamed:
  `ofs`/`seg` would collide with the existing names in those functions and say no more than
  the assignment already does.

Auto-named parameters: 891 -> 852.  Struct-typed arguments: 128 -> 130.

### Parameter scan after the second pass: the family is exhausted

`tmp/param_scan4.py` on `decompiled25` returns only three multi-site candidates, all inside
`OVC22_5087_056e` (the function with flagged-unstable decompilation), and twelve single-site
ones.  Each of the latter was checked and refused:

| candidate | why refused |
|---|---|
| `OVC15_4207_26bc` `param_2` | typed `agnt_t *` already, but the body treats it as a scratch
  value (`param_2._2_2_`, `param_2 = CONCAT22(...)`, arithmetic on it), so naming it would
  describe a register, not an argument |
| `OVC23_55fe_0cdf` `param_1` | passed where a callee calls the value `rect`, but in this body
  it is a base pointer moved by a direction offset (`param_1 + *(char *)(param_3 + 0x885)`) |
| `OVC06_317e_1240` `param_3`/`param_6`/`param_7` | single-site votes through an unnamed
  callee's argument order, with no coordinate arithmetic to confirm it |
| `buf` / `count` / `text` single-site votes | the callee parameter is generic; the name would
  add nothing |

So the call-role rule now yields nothing new that its own evidence supports.  The remaining
852 parameter names are in functions where no call or field pins the value.

## Per-function reading: the blit callers around `brect_t` (8 parameters)

With the call-site scans exhausted, the remaining candidates were read body by body.  The
`brect_t *` callers all pass the pointer into the same argument slot of `blitGfxRect`:

```c
ovr_blitGfxRect(gfx, screenX, y, rect, (uint8_t)type, true);
```

which fixes two parameters per function:

| function | parameters | evidence |
|---|---|---|
| `constr_usesBlitRaw` | `rect` | its `seg` is swapped to 0xa000 and it is handed to `blitRaw` as the destination |
| `constr_usesBlitGfxRect` | `rect`, `type` | arguments 4 and 5 of `blitGfxRect` |
| `agnt_usesBlitGfxRect` | `rect`, `type` | same |
| `stats_usesAlignUp42` | `rect`, `type` | same |
| `agnt_usesPlay_sfxU` | `agntIndex` | the body writes `*param_2 = <agent loop index> + 1` - an out-parameter holding a 1-based agent index, the same convention the other hit tests use |

Live signatures:

```
void constr_usesBlitRaw(brect_t * rect)
byte stats_usesAlignUp42(byte agntIndex, byte param_2, int16_t x, int16_t y, brect_t * rect, undefined2 type)
undefined2 agnt_usesPlay_sfxU(agnt_t * agnt, char * agntIndex)
```

Auto-named parameters: 852 -> 844.

## Per-function reading: the blit-N argument order and the party-sheet index (49)

Call sites settle the two `blitGfxN` wrappers completely, because every caller passes the
same shape.  `36ce:0995` is the clearest:

```c
blit_usesBlitGfxN(gfx, x,
                 y,          shades[i],
                 y2,         shades[i + 1],
                 (brect_t *)BlitRects, type);
```

and the body swaps the two endpoints together with their shades, which is only meaningful
if the fourth and sixth arguments belong to the third and fifth:

```c
if (param_5 < y) { y = param_5; ...; param_4 = param_6; param_6 = bVar1; }
```

`blit_usesBlitGfxN2` gets `x1, y1, shade1, x2, y2, shade2, rect, type`, and its last
argument is `HighlightLevel` at every observed call, compared in the body against
`(*p & 7)`, so it is `highlightLevel`.

| function | parameters | evidence |
|---|---|---|
| `blit_usesBlitGfxN` | `shade1`, `y2`, `shade2`, `rect`, `type` | argument slots 4-8, shade/y pairing proved by the swap |
| `blit_usesBlitGfxN2` | `x1`, `y1`, `shade1`, `x2`, `y2`, `shade2`, `highlightLevel` | slots 3-8 and 11; `HighlightLevel` at every call |
| `constr_usesScreenOriginY` | `rect`, `type` | the single `blit_usesBlitGfxN` call's last two slots |
| `ovc28_usesBlitLabel` | `x`, `y` | `dst.ofs = x + y * 0x140`, `TextBlitX = x + 6`, `TextBlitY = y + 2` |
| `blit_usesDrawGfx` | `x`, `y`, and `rect` retyped `brect_t *` | `rect[0..3]` bound the blit, `rect[4]` is the destination segment |
| `ovc23_usesBlitGfxRect`, `...Rect2` | `x`, `y` | `x = param_1 - 1`, `row = param_2 + k`, then every blit uses `x` and `row` |
| `ovc40_usesBlitGfx10` | `backdropIndex`, `scrollOffset` | the index selects six parallel backdrop cut tables; the offset is halved and subtracted from `0xdc` |

### The 0x217A table: 17 more `partyIndex` parameters

The party-sheet table's access form is unmistakable and now appears in 17 more functions:

```c
*(undefined4 *)((uint)param_N << 2)          /* far pointer per sheet */
*(byte *)((...) + 0x2f)                      /* cls        */
*(byte *)((...) + 0x3e) / + 0x3f             /* classStr / excluded */
*(byte *)((...) + 0x5d)                      /* flags5d    */
*(int *)((...) + 0x56)                       /* the value compute3 adds */
```

Before renaming, every candidate's field offsets were listed and all of them fall inside the
documented `char_sheet_t` range (`0x29..0x9c`): `3b1d:0c1e` 0x29, `4207:10a3` 0x2f/0x5d,
`4d05:1b51` 0x3d/0x3f, `5087:3dc7` 0x2f/0x5d, `5087:4576` 0x3e/0x3f/0x4d/0x4f/0x5d,
`55fe:2f90` 0x9b/0x9c, `5b66:1929` 0x2a/0x3e/0x40/0x45/0x49/0x5d/0x5e, `67d1:0000` 0x4d,
`67e7:09b9` 0x3f, `690b:0180` 0x3f/0x4d/0x4f/0x54/0x5b, `77eb:0976` 0x87 (rank),
`77eb:09c1` 0x56, `7e7c:2b4c` 0x3e, `676c:0000` 0x2f.

`agnt_compute7` gets one more: it reads `*(sheet + param_2 + 0x29)` and maps the value
through thresholds 4/6/9/0xd/0x10/0x12 to -3..3, so `param_2` is an ability index and the
byte array at `+0x29` holds the six ability scores.

### Refused in this pass

| candidate | why refused |
|---|---|
| `bldng_usesBldng` `param_4` | it is forwarded to `ovc45_compute3` (a party-sheet index) **and** to `bldng_textArena`, whose second argument is compared with a byte inside an entity record. Both can only be true if that entity byte stores a party slot, which nothing shows |
| `ovc27_usesRandBelow3` `param_2` | an `undefined4` far pointer whose target is read at +8/+9/+0xf/+0x13/+0x15 but never named; typing it would require inventing a struct |
| `stats_usesAlignUp42` `param_2` | the function carries *Control flow encountered bad instruction data* and an overlapping-instruction warning |
| `ovc45_usesClose` `param_1`/`param_2` | the function has no stored prototype (0 parameters), so the names in its decompiled text are not variables that `RenameVars` can set; giving it one would change its stack layout without evidence |
| `ovc22_textRingProt` | unchanged: flagged-unstable decompilation, and `param_4`/`param_5` are the halves of a far byte pointer |

Auto-named parameters: 844 -> 795.  Struct-typed arguments stay at 130.

## Per-body reading continued: the table parameters (15)

### The 0x222B requirement table

`ovc27_usesRandBelow3`'s second parameter is a far pointer into segment `0x222b`, and
every call site shows the same table:

```c
ovc27_usesRandBelow3(agnt, 0x222b0108, param);
ovc27_usesRandBelow3(agnt, 0x222b014a, param);
ovc27_usesRandBelow3(agnt, CONCAT22(0x222b, recIndex * 0x21), 3);
```

0x108/0x21 = 8 and 0x14a/0x21 = 10, so the records are 0x21 bytes.  The body reads
+8 (a kind 0/1/2 that selects the `agntG_t.flags` bit 2/1/0x800), +9 (an index into the
`reqLevel1`/`reqLevel2` rows copied from 0x59AA/0x59B4), and the mask words +0xf, +0x13,
+0x15, +0x17, +0x19, +0x1b, +0x1d.  So the parameter is `reqRecord`.

### The menu text table

`saveui_usesBlitLoadRleGfx2` and `saveui_usesMouseMoved` share one shape:

```c
puVar1 = (undefined2 *)((int)param_1 + (row + param_3) * 4);
ovr_blitText((char *)*puVar1, (byte *)puVar1[1], Font03.ofs, (uint8_t)Font03.seg);
TextBlitY = param_2 * 0xf + 0x1d;          /* 15-pixel row pitch */
dst.ofs  = param_2 * 0x12c0 + 0x2096;      /* 0x12c0 = 15 * 320 */
```

so `param_1` is the far-pointer table, `param_2` a row and `param_3` an item offset.  The
callers confirm it: `uiMenuSub` passes `GMenuItem - 1`, and `saveui_usesMouseMoved` passes
`(MouseY - 0x1a) / 0xf`.  In `saveui_usesMouseMoved` the *entered* `param_2` is only a
vertical bound (`MouseY <= param_2 * 0xf + 0x19`), so that copy is `rowLimit` while the row
actually drawn comes from `MouseY`.

### Two CRT arguments

| function | parameter | evidence |
|---|---|---|
| `_brk_normalize` | `brkOfs`, `brkSeg` | `_brklvl.ofs = param_1; _brklvl.seg = param_2;` and `(param_2 - _psp) >> 6` |
| `__crtinit` | `videoMode` | `_video.currmode = param_1`, then `if (param_1 != _video.currmode)` to detect a rejected mode |
| `ovc28_usesUiInputText` | `entries`, `count`, `flags` | forwarded at the same positions into `uiInputText(far_t *entries, short count, byte *hint, byte flags)` |

### The per-entity party slot: a new field fact and a typing inconsistency

`ovc45_textDone` reads a byte from an entity record and hands it to `ovc28_textGold`:

```c
byte_2410_DATA_DGROUP_5CEF =
    *(undefined1 *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3);
...
if (byte_2410_DATA_DGROUP_5CEF != 0xff) ovc28_textGold(byte_2410_DATA_DGROUP_5CEF);
```

`ovc28_textGold(byte partyIndex)` indexes the 0x217A party table and formats
`sheet[partyIndex] + 0x56/+0x58` as a decimal, so the byte must be a party slot in 0..4 or
0xff.  `bldng_textArena` compares its second argument against the same byte, and its only
caller passes the party index of `bldng_usesBldng` -- which resolves that earlier refusal.

The inconsistency to record: `agnt_t.entity` is typed `entity_t *32` at +0x17, so its byte
+3 is the high byte of the far pointer's segment, not a slot.  Either the field is not a
4-byte far pointer there, or the decompiler renders a raw byte access that way.  The value's
range (0..4/0xff, consumed by a function that needs a party index) rules out the segment
reading, so the layout needs a disassembly check before `entity` is retyped.

### Refused in this pass

| candidate | why refused |
|---|---|
| `agnt_usesStExit` `param_2`, `param_3` | `param_2` is read as ints at +0xf/+0x11/+0x1c and `param_3` at +5; the only caller passes a record that `ovc49_usesBlitGfxRect` reads at +0x19/+0x1b/+0x1c/+0x1d, which is the `anm_t` block this project already recorded as unreadable |
| `ovc18_textBathHouse` `param_3` | compared with 6 and 0xb to pick a graphic **and** used as the upper bound of the anims walk -- two incompatible roles |
| `ovc18_textBathHouse` `param_5` | only ever compared with 2 |
| `stats_usesAlignUp42` `param_2` | *Control flow encountered bad instruction data* + overlapping instruction |
| `setvbuf` `param_2`/`param_3`/`param_4` | the decompiled signature splits the far buffer into ofs/seg words; naming them CRT buffer halves would not teach the game model anything |

Auto-named parameters: 804 -> 780 over the two batches.

## The per-entity party byte: disassembled, and why it must not become a field

The open question from the previous pass was whether `agnt_t`'s `entity` field is really a
4-byte far pointer at +0x17, or whether the decompiler's `(int)&...entity + 3` was hiding a
separate byte field.  `scripts/ghidra/ListInsn.java` (added this pass) prints the listing, and
the answer is unambiguous.

**Read side** (`ovc45_textDone`, 77eb:1754): the byte is read at `entity+0x1a` and fed
straight into the 0x217A party table:

```
77eb:181c  MOV  AX,[BP + 0xa]            ; entityIndex
77eb:181f  MOV  DX,0x37                 ; entity_t stride
77eb:1822  IMUL DX
77eb:1829  LES  BX,ES:[0x908e]          ; Entities (far pointer)
77eb:182e  ADD  BX,AX
77eb:1830  MOV  AL,byte ptr ES:[BX + 0x1a]
```

and at another site the same byte indexes the party table, with the raw bytes confirming the
`MOV ES,DX` that Ghidra mis-renders as `MOV DX,ES`:

```
77eb:1866  26 8A 47 1A        MOV AL,ES:[BX+0x1a]
77eb:186a  B4 00              MOV AH,0
77eb:186c  C1 E0 02           SHL AX,2
77eb:186f  BA 7A 21           MOV DX,0x217a
77eb:1872  8B D8              MOV BX,AX
77eb:1874  8E C2              MOV ES,DX        ; ES = 0x217a  (bytes 8E C2)
77eb:1876  26 FF B7 02 00     PUSH ES:[BX+2]   ; partyTable[b].seg
77eb:187b  26 FF B7 00 00     PUSH ES:[BX+0]   ; partyTable[b].ofs
```

**Write side** (`ovc15_usesAgntFlag1`, 4207:0e17): the same four bytes are written as a far
pointer, offset first and segment second:

```
4207:0f9c  MOV word ptr ES:[BX + 0x19],DX   ; entity.seg = Entities.seg
4207:0fa1  MOV word ptr ES:[BX + 0x17],AX   ; entity.ofs = Entities + index
```

and `ovc15_usesStExit` writes the identical pair.  So `agnt_t+0x17` **is** a 4-byte far
pointer, `+0x19` is its segment word, and `+0x1a` is the high byte of that segment.  There is
no room for a separate byte field: any `partySlot` added at 0x1a would overlap the pointer and
break the eight `LES BX,ES:[BX+0x17]; ... [BX+0xf]` dereferences that read the target's level.

### What the byte means, independently

The value stored in that byte is treated as a party index by two unrelated functions:

| site | evidence |
|---|---|
| `ovc45_textDone` | read from the byte, tested `!= 0xff`, passed to `ovc28_textGold(byte partyIndex)`, which indexes 0x217A and formats `sheet+0x56/+0x58` |
| `ovc13_usesEntities` | `partyFilter` is assigned from `manage_textAllUnits`' `partyIndex` parameter and compared with this same byte; 0xff means none |

So the party slot is `entity.seg >> 8`.  `agnt_t.entity` therefore stays `entity_t *32` and no
field is added; the fact is recorded here instead, because expressing it as a field would make
the struct disagree with the pointer loads the same code performs.

### Consequence for the decompiled source

The correct rewrite of the party-slot sites is `entity.seg >> 8`, not a new field.  I have not
applied that rewrite because it needs a small custom script (the decompiler will keep printing
`&entity + 3` until the expression is rewritten), and inventing a struct field to make the text
prettier would be exactly the kind of guess this project refuses.

### Two globals that came out of the same reading

| global | name | evidence |
|---|---|---|
| `2410:4B6D` | `levelRangeIndex` | `LevelRangeMin[4B6D] <= entity.base.level <= LevelRangeMax[4B6D]`, with 0xfe handled as a special case |
| `2410:4B6E` | `partyFilter` | assigned from `manage_textAllUnits`' `partyIndex` parameter, 0xff for none, compared with the per-entity party byte |

## Two more struct fields from the listing (27 -> 25)

### `anm_t+0x1d` is `sfxId`

`agnt_usesStExit`'s second parameter, which the decompiler typed `undefined4`, is an
`anm_t *`.  The listing shows it driving the agent's frame counter:

```
3b1d:0fef  LES  BX,[BP + 0x6]        ; agnt
3b1d:0ff2  INC  byte ptr ES:[BX + 0xe]   ; agnt->animFrame++
3b1d:0ff9  MOV  AL,ES:[BX + 0xe]
3b1d:0ffd  LES  BX,[BP + 0xa]        ; param_2 (anm_t *)
3b1d:1000  CMP  AL,ES:[BX + 0x1b]    ; nframes
3b1d:1004  JC   ...
3b1d:1006  LES  BX,[BP + 0xa]
3b1d:1009  CMP  byte ptr ES:[BX + 0x1a],0xff   ; startFrame sentinel
3b1d:100e  JZ   ...
3b1d:1010  LES  BX,[BP + 0xa]
3b1d:1013  MOV  AL,ES:[BX + 0x1a]
3b1d:1017  LES  BX,[BP + 0x6]
3b1d:101a  MOV  byte ptr ES:[BX + 0xe],AL   ; restart at startFrame
```

so `+0x1a` = `startFrame`, `+0x1b` = `nframes` and `+0x1c` = `flags` exactly as the struct
already had them.  The remaining byte `+0x1d` is passed as the sound id:

```c
ovr_play_sfxU(*(byte *)((int)uStack_12 + 0x1d), 0, uVar12);   /* 4 sites */
```

and `play_sfxU(byte fid, int type, uint16_t unk)` fixes the first argument as the sound file
id, so the field is `sfxId`.

### `agnt_t+0x13` is `frames`, a far pointer to 4-byte entries

`ovc49_usesBlitGfxRect` builds a far pointer from the words at agnt+0x13/+0x15 and indexes it:

```c
uStack_a = CONCAT22(*(undefined2 *)(uStack_22 * 0x34 + 0x15),
                    *(undefined2 *)(uStack_22 * 0x34 + 0x13));
uVar10   = ovc49_body1(...);                       /* frame id */
puVar16  = (undefined2 *)((int)uStack_a + (uVar10 & 0xff) * 4);
uStack_12 = CONCAT22(puVar16[1], *puVar16);        /* far pointer per entry */
```

The field was a bare `DW`; it is now `far_t *` named `frames` (same four bytes, so no layout
change).  The entries it points at are the `anm_t` records whose `nframes`/`sfxId` the same
function consumes.

### The `anm_t+0x0x0f` / `+0x11` width conflict - refused, with opcodes

The same listing shows genuine 16-bit reads where the struct has single bytes:

```
3b1d:0ec6  C4 5E 0A        LES BX,[BP + 0xa]
           26 39 77 0F     CMP ES:[BX+0x0f],SI      ; 16-bit compare
3b1d:0ec9  C4 5E 0A        LES BX,[BP + 0xa]
           26 8B 77 0F     MOV SI,ES:[BX+0x0f]     ; 16-bit load
```

and the same two forms at `+0x11` (0e5c, 0e6a, 0e78, 0e84).  But `ow` at `+0x0f` has four
byte uses that are equally direct:

```c
((frm_t *)frm)->ow = *(uint8_t *)(nanims + i * 0x1e + 0xf);   /* stshRleAnims */
((frm_t *)frm)->ow = (char)exx - (char)xx;
*(uint8_t *)((int)&pfVar6[1].ofs + 1) = ((anm_t *)anims)[i].ow;   /* textBathHouse */
```

So `+0x0f` is read both as a byte and as a word, and `+0x11`/`+0x12` are read as one word.
Either the two bytes are a 16-bit value whose low byte is `ow`, or the movement code reads
the pair deliberately.  `stshRleAnims` only *writes* `ow` as a byte and nothing writes anm's
`+0x0f` as a word, so the binary does not settle the width.  Retyping would have to delete
`ow`, and a wrong merge would silently change every byte access to it.  Refused; the finding
is recorded here with the opcodes so it can be decided if a writer ever turns up.

### Independent confirmation of the per-entity party byte

`partyFilter` (2410:4B6E) is assigned from `manage_textAllUnits`' `partyIndex` parameter and
compared with the same `entity+0x1a` byte that `ovc45_textDone` passes to `ovc28_textGold`.
Two unrelated functions treating the byte as a party index is what makes `entity.seg >> 8`
the right reading of it rather than a decompiler artifact.

Struct fields: 27 -> 25 generated.

### The two opaque pointers in agnt_usesStExit, now typed (2)

The listing identified the second parameter as an `anm_t`, and the caller fixes the third:

```c
uStack_12 = CONCAT22(puVar16[1], *puVar16);            /* anm_t * entry */
psVar11   = ovr_stash_usesStExit((stg_tmp_t *)*(undefined2 *)(iVar17 + 0x58), ...);
uStack_18 = (stg_tmp_t *)CONCAT22(uVar15, psVar11);
ovr_agnt_usesStExit((agnt_t *)..., uStack_12, uStack_18);
```

so the signature is

```
void agnt_usesStExit(agnt_t * agnt, anm_t * anim, stg_tmp_t * sprite)
```

and the body now reads `sprite->cmap[5]` instead of a raw byte at +5.  Both parameters were
`undefined4` (4 bytes) before, so the retype is size-neutral and the argument order is
unchanged.

Auto-named parameters: 780 -> 778.

## `anm_t+0x19` is read, and gates an effect (25 -> 24)

The earlier note that `anm_t 0x10..0x1d` is never read was wrong again.  Inside the
per-agent loop of `ovc49_usesBlitGfxRect` the pointer `uStack_12` is an `anm_t` (its
`nframes` and `y` are used by name), and it drives a running frame counter:

```c
uStack_1a = uStack_1a + 1;
if (((anm_t *)uStack_12)->field_0x19 + 1 == uStack_1a) {
    ovr_ovc41_textPoisons((agnt_t *)..., *(byte *)(uStack_22 * 0x34 + 0xc));
}
if ((int)uStack_1a < (int)(uint)((anm_t *)uStack_12)->nframes) { ... }
```

so the byte is the frame index at which the animation fires its effect, and the same byte is
compared with the agent word at +6 in the same loop.  It is now `eventFrame`.

### The `agnt_t+4..+7` width conflict - refused, with the stores

The entity spawner writes 16-bit coordinates:

```
4207:113e  MOV word ptr ES:[BX + 0x4],SI   ; targetX?
4207:1150  MOV word ptr ES:[BX + 0x6],DI   ; targetY
```

but the movement code reads the same bytes as two independent signed directions:

```c
if (*(char *)(i * 0x34 + 4) < 1) {
  if (*(char *)(i * 0x34 + 4) < 0) *(int *)(i * 0x34) -= cmap[5];
} else *(int *)(i * 0x34) += cmap[5];
/* and the identical shape at i * 0x34 + 5 */
```

A 16-bit store into a byte field is not something a C compiler emits for a byte assignment,
so `+4` really is 16 bits at the spawn, while `+4` and `+5` really are separate bytes during
movement.  The two readings cannot both be a flat field.  `field_0x5` is the high byte of that
word, so removing it would make the movement code read the top of a coordinate as a sign --
and keeping it leaves the spawn's word store spanning two fields.  Refused; recorded with the
instructions so it can be settled if a writer for the movement path turns up.

### The general pattern now visible

Three of the four open width questions have the same shape: a 16-bit access spanning two
adjacent byte components (`agnt_t+4/+5`, `anm_t+0x0f/+0x10`, `anm_t+0x11/+0x12`), where each
byte is also used on its own somewhere.  In every case the word access is a single
instruction in a hot path, which is what a compiler does when it moves two byte fields
together -- not proof that the field is 16 bits.  That is why none of them is merged.

### Corroboration: the party slot is a char_sheet_t field too

char_sheet_t+137 (+0x89) is already named partySlot, and the value the entity pointer's
segment high byte carries is compared against partyFilter and handed to ovc28_textGold as a
party index.  So the slot exists as a real field on the character sheet and the entity record
mirrors it in the segment byte -- which is why ntity.seg >> 8 is the correct reading rather
than a decompiler artifact.

## `agnt_t+0x11` disassembled: a coin-flip variant, refused

`ovc15_usesLDIV_at_2` respawns an agent from an entity record and sets the byte from the
animation's two pointer words:

```c
if ((*(int *)(iVar10 + 0x68) == 0 && *(int *)(iVar10 + 0x6a) == 0) ||
    (*(int *)(iVar10 + 0x58) == 0 && *(int *)(iVar10 + 0x5a) == 0)) {
  if (frames->w68 == 0 && frames->w6a == 0) agent[+0x11] = 0;
  else                                     agent[+0x11] = 1;
}
else agent[+0x11] = (char)ovr_randBelow(2);
```

So the byte is a two-valued variant choice that is a coin flip in the common branch, and the
same function picks an animation variant from `entity.frames` byte +3 (the party-slot byte)
and the entity level.  There is no name the binary supports here: `variant` would be a guess
about which variant the 0/1 means.

`agnt_t+0x24` / `+0x25` are the same story at the width level: all twelve accesses are single
bytes (`MOV AL,ES:[BX+0x24]`, `CMP byte ptr ES:[BX+0x25],0x2`, `MOV byte ptr ES:[BX+0x24],0`)
with the values 0/1/2 selecting different sprite branches, but nothing states what the three
values mean.

### Five parameters from the saves-index helpers and the gfx-block owners (5)

`saveui_textSsavesTxt` fills an array of far pointers while reading the saves index, and
`saveui_usesStshFree` walks the same array:

```c
/* textSsavesTxt */
puVar4 = (undefined2 *)(param_1 + uVar5 * 4);
/* usesStshFree */
for (uVar6 = 0; uVar6 < param_2; uVar6 = uVar6 + 1) {
  piVar3 = (int *)(iVar2 + uVar6 * 4);
  ... handle.seg = puVar5[1]; handle.ofs = *puVar5;
```

so `param_1` is the `entries` array and the free's second argument is the `count`.

`init_special_graphics` and `ovc20_compute1` are both called with loaded graphics block
pairs and act on the far pointer nested at block+0x11/+0x13:

```c
if (*(int *)(param_1 + 0x11) != 0 || *(int *)(param_1 + 0x13) != 0) {
  handle.seg = *(uint16_t *)(param_1 + 0x13);
  handle.ofs = *(uint16_t *)(param_1 + 0x11);
  ovr_stshFree(handle);
}
/* ovc20_compute1 */
*(undefined2 *)(param_1 + 0x13) = 0;
*(undefined2 *)(param_1 + 0x11) = 0;
```

Call sites are `Lbm_nwpanel1.ofs/seg`, `specialColorsOfs/Seg`, `gamfont1Cut1Ofs/Seg`,
`davfontCut1Ofs/Seg` and `_davfont2Cut1Ofs/Seg`, so the pointer is a `gfxBlock`.  Both
functions leave their second argument unused, which is why it stays auto-named.

Auto-named parameters: 771 -> 766.

## Saves-index helpers, prompts and map squares (18 parameters)

### The three saves-index walkers

`saveui_textSsavesTxt2`, `saveui_usesStshFree` and `saveui_usesBlitLoadRleGfx3` all walk the
same array of far pointers with a bound:

```c
puVar1 = (undefined2 *)((int)entries + i * 4);      /* far_t per entry */
for (i = 0; i < count; i = i + 1) { ... }
```

so their first argument is `entries` and the bound is `count`.  `saveui_usesWrite` forwards
both of its own into the C library: `write(handle, text, count)`.

### `saveui_usesBlitText` (the new-world prompt helper)

```c
ovr_blitText(prompt, (byte *)param_2, Font03.ofs, (uint8_t)Font03.seg);
TextBlitY = row * 0xf + 0x1d;
pfStack_c = ovr_stshRleCut(..., row * 0xf + 0x1d, 222, row * 0xf + 0x27, ...);
```

The first argument is `blitText`'s `text`, and the third is a 15-pixel row used for both the
text baseline and the cut rectangle.  The first rename was rejected:

```
FAIL 4528:1d55 param_1 : DuplicateNameException: A Local Var symbol with name text
     already exists in namespace saveui_usesBlitText
```

because the function already has a local `char text[80]`, so the parameter became `prompt`.

### `saveui_usesStshAlloc`

```c
iVar1 = read(fd, local_52 + iVar3, unSS);
```

so its single argument is the saves-file descriptor.

### `attact_usesMenuItemEnabled` -> `menuIndex`

```c
if (((undefined1 *)&MenuItemEnabled)[param_1] == -1) ...
... == ((undefined1 *)&MenuItemEnabled)[param_1]
```

### `manage_compute1` -> `n`, `attact_compute1` -> `counter`

`manage_compute1` returns `"st"`/`"nd"`/`"rd"`/`"th"` from `param_1 % 10` with the 0xb/0xc/0xd
exceptions, i.e. an ordinal suffix for a number.  `attact_compute1` does
`if (*p != 0) *p -= 1`, so its argument points at a countdown byte.

### Map coordinates, pinned two ways

`attact_usesGMapCells` bounds its arguments with the array's own dimensions and indexes the
declared `byte [59][148]`:

```c
if (param_1 < 0 || param_2 < 0 || 0x93 < param_1 + 1 || 0x3b < param_2 + 1) ...
local_a[0] = (int)(char)(*paabVar3)[param_2][param_1];
```

so `param_1` is the 148-wide coordinate (x) and `param_2` the 59-wide one (y).

`attact_usesSquareRecCount` searches the 0x13-stride square records by their first two ints:

```c
if ((*(int *)(uVar1 * 0x13) == param_1) && (*(int *)(uVar1 * 0x13 + 2) == param_2)) break;
```

and the same record is matched elsewhere against `GfxRndSeed`/`GfxRndSeed2`, which
`attact_usesMenuItemEnabled` compares with `entity.base.x` / `entity.base.y`.  So those two
arguments are x and y as well.

### The two accumulators

`attact_usesEntityCount2` and `attact_usesAgntCount2` zero a 32-bit output and add
`animFrame * level * level` with an explicit carry into the second word, so their first
argument is `sum`.  Both leave their second pointer argument unused -- the third accumulator
arrives on the stack -- so it stays auto-named.

Auto-named parameters: 766 -> 748.

## The `bldtp_t` access base is 0x10E, not 0x110 - and that closes the +0x0c conflict

The table's first far pointer is built from two words 2 bytes apart, which fixes the base:

```c
((char *)CONCAT22(*(undefined2 *)(bldType * 0x27 + 0x110),
                  *(undefined2 *)(bldType * 0x27 + 0x10e)));   /* name.ofs/segs */
```

so `name` starts at **0x10e**.  Four independent fields confirm it:

| code offset | field | evidence |
|---|---|---|
| `0x116` / `0x118` | `action` (+8) | null-tested as a pair and copied into `menuItems[2]/[3]` |
| `0x11a` | `field_0x0c` | `== 2` |
| `0x11b` | `size` (+0x0d) | compared `< 2` and `< 3` |
| `0x121` | `flags2` (+0x13) | `& 0x800`, `& 0x20` |
| `0x130` | `durability` (+0x22) | `100 - value` |

With the corrected base, the construction-time code reads:

```c
bStack_3 = *(byte *)(terrainType * 0x27 + 0x11d);   /* buildTime      (+0x0f) */
if (bStack_3 == 0) bStack_3 = 1;
if (bStack_3 < *(byte *)(bldType * 0x27 + 0x11c))  /* minBuildTime   (+0x0e) */
    record[+6] = *(byte *)(bldType * 0x27 + 0x11c);
else
    record[+6] = bStack_3;
```

i.e. the new construction's duration is `max(current building's buildTime, the new type's
minBuildTime)`.  Both fields are already named, and `record[+6]` is the duration
(`draw_usesPlay_sfx` tests `record[+0x11] + 1 < record[+6]`).

**So `bldtp_t+0x0c` is not a second lower bound at all** -- the 0x11c read is `minBuildTime`
at +0x0e, and the older note came from assuming the base was 0x110.  What survives at +0x0c is
a single test:

```c
if (*(char *)(bldType * 0x27 + 0x11a) == '\x02') { ... ovc23_textUnitDrowns(x, y); }
```

so `field_0x0c == 2` marks squares where units drown.  One value with one effect is not enough
to name the field (a terrain-class taxonomy cannot be enumerated from a single member), so it
stays generated, but the record now says what the byte does rather than claiming a time bound.

## `agnt_t+4..+7` settled as bytes, with the mechanism

The spawner's store is one instruction:

```
4207:113e  MOV word ptr ES:[BX + 0x4],SI
4207:1150  MOV word ptr ES:[BX + 0x6],DI
```

and the movement code reads the same bytes as independent signs:

```c
if (*(char *)(i * 0x34 + 4) < 0) *(int *)(i * 0x34) -= cmap[5];
else if (...)                    *(int *)(i * 0x34) += cmap[5];
/* identical at i * 0x34 + 5 */
```

The two are consistent if the 16-bit move writes **two adjacent byte fields** at once -- the
classic 8086 peephole that loads two bytes into AL/AH and stores the pair with one `MOV`.  The
decisive argument is the sign test: if +4 were the low half of a 16-bit coordinate, testing its
bit 7 as a movement direction would be meaningless, whereas as a signed direction byte it is
exactly right.  So the byte layout stands and `field_0x5` is a real field, not a spurious high
byte; the earlier "width conflict" is closed as a compiler artifact rather than a layout error.

## Six parameters from the direction tables (6)

`0x885` and `0x889` are per-direction delta tables, and the same index is a bit position in
`GMapFlags`:

```c
iVar1 = (int)*(char *)(dir + 0x885);        /* dx */
iVar1 = (int)*(char *)(dir + 0x889);        /* dy */
GMapFlags[y][x] >> (dir + 4 & 0x1f);
GMapFlags[y][x] >> (dir + 8 & 0x1f);
```

so `attact_usesSCARRY2` and `attact_usesSCARRY22`'s third parameter is `dir`.
`attact_usesAlignUp44` takes x by pointer, the matching segment, y, and the same direction:

```c
*_param_1 = iVar4;                       /* the stepped x is stored back */
func_0x0004f32d(..., *_param_1, param_3, param_4, ...);
iVar4 = iVar4 + *(char *)(param_4 + 0x885);
```

so `xPtr`, `xSeg`, `y`, `dir`.

Auto-named parameters: 748 -> 742.

## `anm_t 0x10..0x18` re-verified two ways

The nine remaining `anm_t` bytes were checked by field name (`field_0x10`..`field_0x18`
appear nowhere in the export) **and** by raw stride: there are 25 sites of the form
`... * 0x1e ...` in `tmp/decompiled33`, and the only record offsets they add are `0x1b`
(`nframes`) and `0x1c` (`flags`):

```c
while ((i < in_stack_0000000c && (*(char *)(nanims + i * 0x1e + 0x1b) != '\0'))) { ... }
if (*(byte *)(nanims + (int)((long)(int)i * 0x1e) + 0x1b) <= j) break;
if ((*(byte *)(nanims + i * 0x1e + 0x1c) & 1) == 0) { ... }
```

the other `0x10`-looking hits are `>> 0x10` shifts.  So the block is genuinely never read by
any exported body, and the fields stay generated rather than guessed from their position.

### The one remaining anm width question

`anm_t+0x0f` and `+0x11` are read as 16-bit words in `agnt_usesStExit`
(`CMP ES:[BX+0x0f],SI`, `MOV SI,ES:[BX+0x0f]`, and the same at `+0x11`) while `ow` at `+0x0f`
has four direct byte uses.  No writer exists: the records are constant data loaded from the
archive, so the binary cannot say whether the byte pair is one word.  Unchanged and recorded.

## Four parameters from the manage/saveui screens (4)

### `saveui_usesBlitGfx10`

```c
ovr_blitText(text, widths, Font03.ofs, (uint8_t)Font03.seg);
rect.x = *cursorX;
if (TextBlitX < *cursorX) { ... }
*cursorX = TextBlitX;          /* the running text cursor is written back */
```

so the 2nd and 3rd arguments are `blitText`'s `text`/`widths` and the 4th is `cursorX`, a
pointer to the current text x.  The 5th argument is never read -- the row comes in on the
stack -- so it stays auto-named.

### `manage_textAllUnitsDisplayed`

```c
unitTypeFilter = (undefined1)unitType;    /* 0xfe = all types */
partyFilter    = partyIndex;              /* 0xff = all parties */
...
if (unitType == 0xfe) { if (partyIndex == 0xff) ovr_say("All units are displayed."); ... }
else if (partyIndex == 0xff) ovr_say("Only units of %s are displayed.");
else ovr_say("Only units of %s loyal to %s the %s are displayed.");
```

so its second argument is the unit type being filtered on.  That also corrects the global
named last pass: `levelRangeIndex` is really `unitTypeFilter` (renamed), because the value is
the selected unit type and `LevelRangeMin/Max` are simply looked up by that type.

### `attact_usesLDIV_at_` and `attact_textAbnormalProgramTermination`

Neither is nameable: the former's `param_1` is never read (it works from
`word_2000_BSS_06E0`, a stack product and a 0x50 clamp), and the latter's lone argument is only
reached through a string-literal error path.

## `char_sheet_t+0x1b`: the listing cannot settle it

The comparison that created the width question is in `manage_textTotalPopulation`:

```c
} while (*(int *)(iVar10 * 0x34 + 0x1b) != *(int *)(sheet->pad_0 + 0x1b));
```

`ListInsn` over that function reports `body=557`, 197 instructions, and **no access at offset
0x1b at all** (the only offsets present are 0x00, 0x21, 0x22, 0x2f).  The function also carries
*Instruction at (ram,0x0005ff51) overlaps instruction at (ram,0x0005ff50)*, so its tracked body
and the region the decompiler emitted are not the same code.  The width therefore cannot be
read off the listing, and the existing refusal (agent side is `owner` word + `gdata` low word)
stands unchanged.  What would settle it is a byte-level dump of the 0x5ff50 region, which
needs the overlay's load base -- not something the current tools expose.

## The `char_sheet_t` pads re-examined at raw offsets

The scan for `+ 0x52` / `+ 0x94` on the party-sheet pointer found real accesses that the
field-name search could not see (the decompiler prints them numerically), and they are
recorded here without names because both are ambiguous.

### `char_sheet_t+0x52` (`pad_52`, byte) - two incompatible uses

```c
/* write, in textRingProt, with a sentinel */
if (uStack_24 < (byte *)0x100) sheet[0x52] = (char)uStack_24; else sheet[0x52] = 0xff;
/* read 1: a base value clamped by the agent's level and 36 */
uVar2 = *(byte *)(sheet + 0x52) + 1;
if (*(byte *)(agnt + 0xf) < uVar2) uVar2 = *(byte *)(agnt + 0xf);
if (0x24 < uVar2) uVar2 = 0x24;
piVar3 = (int *)(cls * 0x94 + uVar2 * 4);   /* 37 four-byte entries per class row */
LUDIV_at_(*piVar3, piVar3[1], 0x1e, 0);
/* read 2: a signed pixel offset */
iVar = (int)*(char *)(sheet + 0x52) + -0x16;
```

Read 1 treats it as an index into a per-class table of 37 entries and clamps it to the agent's
level; read 2 treats it as a signed byte and subtracts 22 to get a screen offset.  A level index
and a pixel offset cannot be the same quantity, and nothing writes it with a value whose units
are stated.  Refused.

### `char_sheet_t+0x94` (`pad_5e`, byte[2]) - written as a word, read as a byte

```c
*(undefined2 *)(sheet + 0x94) = local_c;      /* 16-bit write, in textRingProt */
CONCAT12((char)iVar28, *(...) + 0x94)         /* low byte read, three sites */
```

The 2-byte field being written as a word is consistent with a 16-bit value, but every read takes
only the low byte, and the word write comes from a function that copies a dozen sheet fields at
once (`+0x66`, `+0x68`, `+0x70`, `+0x72`, `+0x74`, `+0x87`, `+0x94`, `+0x96`, `+0x98`, `+0xaa`,
`+0x52`, `+0x84`) -- i.e. a bulk copy whose source is a whole record, so the copy tells us the
width but not the meaning.  Refused.

### What did become certain

`char_sheet_t+0x96..+0x99` is written as two consecutive words right after `+0x94`
(`+0x96 = pfStack_a`, `+0x98 = uStack_8`), which confirms `foodStored` at +96 as a 4-byte field
and confirms that `+0x94` is a field boundary rather than the start of a larger value.

## 17 parameters from the stash reader, the manage counters, the CRT and the menu drawing (17)

### `fmReadIntoHimem`

```c
h = open_wait_unlock_and_disk(filename);
if (skipLo != 0 || skipHi != 0) { lseek(h, ...); len -= (skipHi:skipLo); }
if ((limitHi <= len) && (len != limitHi || limitLo < lenLo)) { len = limitHi:limitLo; }
if (useEms == 0) xms_usesXmsHandle2(...) else ems_memmove2(...);
```

so `filename`, a 32-bit `skipLo`/`skipHi` subtracted from the file length, a 32-bit
`limitLo`/`limitHi` cap, and `useEms` selecting the XMS or EMS mover.  Its second parameter is
never read and stays auto-named.  (The `lseek` call renders the high half as the offset; the
subtraction below it uses the pair as one 32-bit quantity, which is what the naming follows.)

### `manage_usesGUnitCount`

```c
if ((*(char *)(rec * 0x12 + 9) == partyIndex) &&
    (*(char *)(bldType * 0x27 + 0x133) == unitType)) { ... }
if (partyIndex != -1) break;
```

`record[+9]` is the party slot and `bldtp_t+0x25` (`unitType`, base 0x10e) is the unit type.
The seven counters it fills are per-`resource` tallies (`bldtp_t+0x23`); their individual
meanings are not stated, so they stay auto-named.

### The CRT quartet

| function | parameter | evidence |
|---|---|---|
| `_atol` | `s` | whitespace skip via `_ctype & 1`, `+`/`-` (0x2b/0x2d), digit accumulation |
| `fflush`, `ftell` | `stream` | `param_1[9] == param_1` self pointer, `param_1[1] & 0x200`, `param_1[2]` fd, `param_1[6]/[7]` buffer/end |
| `_tell` | `fd` | `lseek(param_1, 0x10000, ...)` = whence 1, offset 0 |
| `screenpos` | `vramOfs` | `(param_1 >> 1) / screenwidth` and `% screenwidth`, 2 bytes per cell |

### Menu drawing

`draw_usesBlitLoadRleGfx3`, `draw_compute1` and `draw_compute2` all index the same per-item
tables from one value:

```c
((undefined1 *)&MenuItemEnabled)[menuIndex] != -1
*(int *)(menuIndex * 2 + 0xda)
((undefined *)&data_2000_BSS_0749)[menuIndex], ((undefined *)&data_2000_BSS_0744)[menuIndex]
```

and `draw_compute3` maps an x coordinate between screen widths:
`(0x13f - x) * 0x80 / 0x140` (319/320 -> 128).

## `agntG_t+0x52` / `+0x94` have no accesses at all

Both offsets were re-checked two ways: the 0x95 stride form (`... * 0x95 ... + 0x52`) and the
generated field names.  Neither appears anywhere in `tmp/decompiled35`, so these two components
exist only because the record size and the neighbouring fields were rebuilt -- they are
size-derived padding, not fields the program reads or writes.  The `+0x52`/`+0x94` accesses
found in the previous pass are **`char_sheet_t`** offsets reached through the 0x217A party
table, not `agntG_t`.

Auto-named parameters: 738 -> 721.

## 15 parameters across the palette writer, the CRT and the map/cell helpers (15)

### The palette writer and two one-liners

`vgaDoSomethingWithPalette` walks a count followed by `(start, runLength, r,g,b ...)` groups and
writes each colour through `out(0x3c8)`/`out(0x3c9)`, so its argument is the palette script;
`lowNibble` is literally `param_1 & 0xf`; `agnt_compute4` is `*param_1 != 0`.

### The CRT batch

| function | parameter | evidence |
|---|---|---|
| `__exit` | `status` | `___exit(param_1, 0, 1)` |
| `__IOerror`, `__DOSerror` | `dosErr` | `_doserrno = param_1`, `errno = _dosErrorToSV[param_1]`, and the second forwards to the first |
| `fputchar` | `c` | `fputc((byte)param_1, stdout)` |
| `CreateFile` | `mode` | `((uint16_t *)_openfd)[fd] = param_1` |
| `fseek_Displacement` | `stream` | receives `ftell`'s `FILE *` and tests `param_1[1] & 0x40` |

### Positional and store evidence

- `init_usesTolower` lower-cases in place with `tolower(*(char *)(base + i))` and drops spaces,
  so its argument is the string `s`.
- `drawAnimTextAt` forwards positionally into `drawTextAt(char *txt, uint16_t dst)` -> `dst`.
- `font_usesMiceBlitRect` passes its argument as `inputUpdate(ulong msg_delay)` -> `msgDelay`.
- `init_usesGMapCells3` does `GMapCells[y][x] = param_3` -> `cell`.

### Two `brect_t *` retypes (struct-typed arguments 130 -> 132)

`ovc07_usesFillRect` and `ovc07_usesLDIV_at_` both take an `int *` whose first four words clamp
their two corners, and the first also passes `param_6[4]` as the destination segment:

```c
if (x1 < (int)*rect) x1 = *rect;      if (y1 < rect[1]) y1 = rect[1];
if (rect[2] < x2)    x2 = rect[2];    if (rect[3] < y2) y2 = rect[3];
ovr_driver_fillRect(x1,y1,x2,y2,colour,rect[4]);
```

That is exactly `brect_t` (x, y, w, h, seg), so both parameters are now `brect_t * rect`.
The retype is size-neutral (a 2-byte `int *` becomes a 4-byte far pointer only where the
argument was already a far pointer, and the call sites pass `&rect` / `BlitRects + n`).

Auto-named parameters: 721 -> 706.

## 43 parameters from the text primitives, the driver fills and two rect clipping paths

Three scans first confirmed the remaining tail has no shortcut left: comparing auto parameters
against the known counters (`AgntCount`, `EntityCount`, `PartySize`, `GMenuItem`, ...) yields
exactly one candidate, and scaling them by a known struct stride yields exactly one -- the
already-refused `ovc22_textRingProt`.  So the rest came from reading bodies.

### The Borland text primitives

`_gettext` and `_puttext` both call `__VALIDATEXY(param_4, param_3, param_2, param_1)` and then
`width = (param_3 - param_1) + 1` walking `param_2 .. param_4`:

```c
iVar1 = __VALIDATEXY(param_4,param_3,param_2,param_1);
iVar1 = (param_3 - param_1) + 1;
for (; param_2 <= param_4; param_2 = param_2 + 1)
    __SCREENIO(iVar1, param_5, param_6, ...);
```

so `x1, y1, x2, y2, buf, bufSeg`.  `_movetext` adds a second `__VALIDATEXY` on a destination
rectangle anchored at `(param_5, param_6)` with the same size, so `x1, y1, x2, y2, dstX, dstY`.

### `driver_scan4`

```c
puVar4 = (uint *)((int)param_1 + param_2 * 2 + param_3 * 0x128);  /* 0x128 = 148 words */
rows = (param_5 - param_3) + 1;  cols = (param_4 - param_2) + 1;
*puVar4 = *puVar4 & param_6;
```

→ `buf, x1, y1, x2, y2, mask`; the caller's `driver_scan4(GMapFlags,0,0,0x93,0x3b,0xfff7)` is the
whole 148x60 flag map with a keep-mask.

### `__LONGTOA`

```c
if ((param_3 < 0x25) && (1 < (byte)param_3)) { ... param_6 = param_6 / param_3 ... }
if (param_2 != '\0') { *param_4 = '-'; ... }
cVar4 = (bVar2 - 10) + param_1;
```

→ `radix`, `signed` (enables the leading '-'), `alphaBase` (the letter base for digits >= 10),
`buf`, and `valueLo` (the low word of the 32-bit value, whose high word arrives on the stack).
`param_5` is never read.

### Two rectangle clippers

`ovc22_usesGMapFlags2` walks a line between two map squares -- `GMapFlags[param_3][param_2]`
with deltas `(param_4 - param_2)` and `(param_5 - param_3)` -- so `x1, y1, x2, y2`.

`ovc27_usesRandBelow` clips a sprite rect and swaps both coordinate pairs together:

```c
if (param_3 < param_1) { swap(param_3, param_1); swap(param_4, param_2); }
if (param_1 < rect[0]) param_1 = rect[0];      if (rect[2] < param_3) param_3 = rect[2];
if ((rect[1] <= param_2) && (param_2 <= rect[3])) ...
```

→ `x1, y1, x2, y2`, `rect` (retyped `brect_t *` -- [0]/[2] are the x bounds and [1]/[3] the y
bounds) and `rectSeg` (the pointer is built as `CONCAT12(param_6, param_5)`).

### `driver_scan1`

A dithered span fill: it counts down `param_3`, steps one byte per iteration through a pattern
at `param_5` (offset low word, segment high word) and writes 0 or `param_4` depending on the
threshold test -- so `buf`, `count`, `fill`, `pattern`.  `param_2` and `param_6` are never read.

Auto-named parameters: 706 -> 663.  Struct-typed arguments: 132 -> 133.

## 20 parameters: the OR-mask fill, a three-vertex clipper and two arena searches

### `driver_scan3` (6)

Byte-for-byte the same loop as `driver_scan4` -- the same `0x128` row stride (148 words) and the
same `(param_5 - param_3)` / `(param_4 - param_2)` extents -- with `|=` instead of `&=`:

```c
*puVar4 = *puVar4 | param_6;      /* scan4 does & param_6 */
```

so the same `buf, x1, y1, x2, y2, mask`.

### `ovc07_usesBiosReadKey` (8)

Three vertices tested against a four-word clip rectangle, with the first two swapped when they
are out of order:

```c
if ((param_1 < r[0]) || (r[2] < param_1) || (param_2 < r[1]) || (r[3] < param_2) ||
    (param_3 < r[0]) || ... || (param_6 < r[1]) || (r[3] < param_6)) {
  if (param_4 < param_2) { param_4 = param_2; param_1 = param_3; param_3 = iVar9; param_2 = iVar4; }
}
```

So `x1,y1,x2,y2,x3,y3`, then `rectSeg` and `rect` -- the pointer is built as
`CONCAT12(param_7, param_8)` and its four words are the bounds, so `rect` is retyped
`brect_t *` (struct-typed arguments 133 -> 134).

### `ovc45_textArena` (4)

```c
uVar1 = ovr_alignUp4(param_1); ... ovr_alignUp4(entity.x) == uVar1
if (peVar4[uVar5].base.y == param_2) { ... *_param_3 = uVar5; }
*_param_3 = 0xffff;   *_param_5 = 0;  ... *_param_5 = 1;
```

so `x`, `y`, `foundIndex` (0xffff until a match) and `foundFlag`.  `param_4` is never read.

### `ovc25_textArena` (2)

The same search from the other module: `param_4` is compared with the per-entity party byte and
`param_5` is aligned exactly like an entity x, so `partyIndex` and `x`.  Its first two arguments
are the halves of a pointer (`CONCAT12(param_2, param_1)`) that is never dereferenced, and
`param_3` is unused, so those stay auto-named.

Auto-named parameters: 663 -> 643.

## 21 parameters: an entity matcher, two arena searches and a sprite-run blitter

### `ovc25_usesAlignUp4` (5) - the cleanest entity lookup yet

Every argument is matched against exactly one field, so there is no inference:

```c
if ((*(char *)((int)&peVar4[uVar5].base.entity + 3) == param_1) &&
    ((*(byte *)((int)&peVar4[uVar5].base.flags32 + 1) & 2) == 0)) {
  if ((alignUp4(entity.x) == alignUp4(param_2)) && (entity.y == param_3)) return uVar5;
  if (alignUp4(entity.destX) != alignUp4(param_4)) return uVar5;
  if (entity.destY != param_5) return uVar5;
}
```

→ `partyIndex, x, y, destX, destY`.

### The arena searches (3)

`attact_textArena` compares `param_4` with the per-entity party byte and aligns `param_5` like
an entity x, while `param_3` selects which `flags32` bit the search requires (0,1,2,3) -- so
`partyIndex`, `x`, `mode`.  `param_2` is never read.  Its sibling `ovc25_textArena`'s `partyIndex`
and `x` were named in the previous pass; this one adds the mode byte.

### `ovc13_compute2` (3)

`puVar1 = (undefined1 *)(param_1 + param_2 * 0x140)` and `CONCAT22(param_5, puVar1)` -- a screen
pixel at (x, y) with the 320-byte pitch plus its segment, then four single-pixel writes at
+0x140/+0x141/+0x280/+0x281 selected by two bit masks.  `x`, `y` and `seg` are named; the two
masks are not, because one value with one effect is not a name.

### `ovc43_usesStExit` (2)

It reads only its last two arguments and forwards them as the halves of the sheet pointer to
`ovc43_usesFmFreeAudio(undefined4 gindex, char_sheet_t * sheet, uint16_t sheetSeg)`, so
`sheetOfs`/`sheetSeg`.  They are deliberately **not** retyped: both are 2-byte parameters and a
4-byte pointer in the first slot would consume the second (the documented widening hazard).

### `blit_usesStExit` (8) - pinned by the call sites

`constr_usesScreenOriginY` calls it with a horizontal run:

```c
blit_usesStExit(gfx_11, SquareLeftX[i], RowScreenY[i] - off1, shades[i],
                SquareRightX[i], RowScreenY[i] - off2, shades[i], &BlitRects[3].x, 0x10);
```

so slots 2..7 are two `(x, y, shade)` endpoints and the body's `if (param_5 < param_2)` swap
carries `y` and the shades with the x -- exactly the `blit_usesBlitGfxN` family pattern, but
with x as the ordered key.  The destination rect arrives as two 2-byte halves
(`CONCAT12(param_9, param_8)`), so `rectOfs`/`rectSeg` rather than a retype.

Auto-named parameters: 643 -> 622.

## 22 parameters: driver pixel blocks, a span fill, and three C streams

### The driver pixel pair (8)

`driver_compute3` and `driver_compute4` are the same four-pixel block with the two colours
swapped on the second row:

```c
puVar1 = (undefined2 *)(param_1 + param_2 * 0x140);
*puVar1 = CONCAT11(param_3,param_3);            (puVar1 + 0xa0) = param_3;   /* 0x140 bytes */
(int)puVar1 + 0x141 = param_4;                 puVar1[0x140] = CONCAT11(param_4,param_4);
```

so `ofs` (screen base), `y`, `colour1`, `colour2`; `param_5` is never read in either.

### `driver_loop1` (3)

```c
if (param_2 < param_1) swap(param_1, param_2);
for (iVar3 = (param_2 - param_1) + 1; iVar3 != 0; iVar3--) *puVar4++ = param_4;
```

→ `x1`, `x2`, `colour`.  `param_3` is a base added as `seg + (seg >> 2)` with its bytes
swapped (`CONCAT11`), which does not match a 16-byte paragraph conversion, so it stays
auto-named rather than guessed.

### Three C streams (3)

`fseek(stream, ...)`, `fputc(c, stream)` and `__fputn(stream, n, buf)` -- the call-role scan
found two, three and two agreeing sites for each.

### `ovc25_usesAlignUp42` (4)

```c
if (*(char *)((int)&Entities[uVar4].base.entity + 3) == param_1) { ... }
while ((iStack_4 < param_2) && (uVar4 = ovc25_usesAlignUp4(param_1,param_5,param_6,destX,destY), ...))
```

→ `partyIndex`, `count`, and `x`/`y` from position in the `ovc25_usesAlignUp4(partyIndex, x, y,
destX, destY)` call whose own parameters were pinned last pass.

### `gfxRlePrepare` and `ovc40_usesAlignToSeg` (4)

Both complete a pointer from two 2-byte halves rather than taking one:
`_param_4 = CONCAT13(..., CONCAT12(param_5, param_4))` and `CONCAT22(param_5, param_4)`, so the
pairs are `rectOfs`/`rectSeg` and `textOfs`/`textSeg`.  Naming them as halves rather than
retyping avoids consuming the neighbouring slot.

Auto-named parameters: 622 -> 600.

## 11 parameters: setvbuf's buffer pair and another rect clipper

### `setvbuf` (5)

The decompiled form splits the far buffer into words, but each word's role is written down:

```c
if ((((FILE *)param_1->token == param_1) && ((int)param_5 < 3)) && (size < 0x8000)) {
  *(int *)((int)&param_1->buffer + 2) = param_2;   /* default buffer segment */
  *(int *)((int)&param_1->curp   + 2) = param_2;
  ...
  *(int *)((int)&param_1->buffer + 2) = param_4;   /* caller's buffer seg */
  *(uint8_t **)&param_1->buffer       = param_3;   /* caller's buffer ofs */
  if (param_5 == 1) { ... }
```

so `stream`, `defaultSeg`, `bufOfs`, `bufSeg`, `mode` (compared `< 3`, `== 1`, `== 2`, i.e. the
three `_IOFBF`/`_IOLBF`/`_IONBF` constants).

### `ovc27_textIntelligenceReportsAttacking` (6)

The identical clip to `ovc27_usesRandBelow`, so the identical names:

```c
if (param_3 < param_1) { swap(param_3,param_1); swap(param_4,param_2); }
if (param_1 < rect[0]) param_1 = rect[0];
if (rect[2] < param_3) param_3 = rect[2];
_param_5 = (int *)CONCAT13(..., CONCAT12(param_6, param_5));
```

→ `x1, y1, x2, y2, rectOfs, rectSeg`.

### Examined and refused in the same pass

| function | why refused |
|---|---|
| `blit_compute1` (14 auto) | its only caller passes 10 locals whose meanings are themselves unresolved inside `blit_usesStExit`, so the slots cannot be pinned |
| `driver_compute1/2` | pure arithmetic on three bytes (`(param_3+param_1+param_2)`, `(param_2-param_1)>>2`) with no positional meaning |
| `constr_compute1/2` | only forwards three arguments and then tests `param_4 & param_5`; the AND is symmetric so neither mask can be told from the other |
| `manage_usesGUnitCount`'s seven counters | the call sites pass each as a (pointer, segment) pair, i.e. far pointers to the caller's locals; the tallies are per-`resource` but the mapping to slots differs between the record loop and the unit loop |
| `ems_memmove1/2` | the EMS register block assigns `param_1/param_2`, `param_3/param_4` and `param_5/param_6` to `emms_var05c1/05c3`, `05ba/05bc` and `05b3/05b5` respectively, and call sites disagree on which pair is source and destination |
| `__setargv` | carries *Unable to track spacebase fully for stack* and an untracked jumptable |

Auto-named parameters: 600 -> 589.

## 12 parameters from a store-to-global scan and four short bodies

A new scan looked for parameters stored straight into an **already named global** (filtering
out locals and generated global names).  It found four, three usable:

```c
ovc42_usesAlignUp4:     partyIndex   = param_1;
audio_textMidiError:    CurrentTrack = param_1;
__setargv:              __setargv_SavedES = param_1;
```

so `partyIndex`, `track`, `savedES`.  (The fourth hit, `ovc28_usesUiInputText`'s `param_5`,
stores into a stack local, not a global.)

### `stats_compute1/2/3` (3, retyped)

All three read `agnt->gdata` (`+0x1d`) and `agnt->entity` (`+0x17`), and return a difficulty
character from the class byte at `gdata+0x46` and the level at `entity+0xf`:

```c
if ((*(char *)((int)*(undefined4 *)(iVar2 + 0x1d) + 0x46) == '\x04') &&
    (0xb < *(byte *)((int)*(undefined4 *)(iVar2 + 0x17) + 0xf))) { ... }
```

so the argument is an `agnt_t *`.  It was already `undefined4` (4 bytes), so the retype is
size-neutral and moves no argument -- struct-typed arguments 134 -> 137.

### `attact_compute3` (4)

```c
*pctOut = (byte)(((0x1c - *(char *)(table + index + 9)) * 100) / 0x1c);
iVar1   = (int)*(char *)(table + index + 9) << 1;
*remainderOut = ('d' - *pctOut) - *in_stack;      /* 'd' is 0x64 = 100 */
```

→ `table`, `index`, `pctOut`, `remainderOut`; its sibling `attact_compute2` is the same
computation with the table fixed at `data_2000_BSS_0744/0749`.  `param_4` is never read.

### Two one-liners

`ovc15_loop1` takes a byte offset, halves it (`param_1 >> 1`, i.e. 2 bytes per cell) and uses it
to index a 0x69-stride table of 10 rows -- `vramOfs`.  `ovc07_compute2` is a sign function
(-1 / 0 / 1 for `<0`, `<1`, else), so its argument is the `value` whose sign it returns.

Auto-named parameters: 589 -> 577.

## A writer for the party byte - the `agnt_t+0x1a` question is closed

`ovc15_usesLDIV_at_2` builds an entity record from scratch and is the writer that was missing:

```c
((entity_t *)Entities)[entityIndex].base.target = 0xff;
peVar6[entityIndex].base.gindex = gindex;
peVar6[entityIndex].base.level  = gdata[gindex].level;
... puVar1[0] = 0; puVar1[1] = 0;            /* frameIndex */
... puVar1[0] = 0x64; puVar1[1] = 0;          /* health = 100 */
*(undefined2 *)((int)&peVar6[entityIndex].base.frames + 1) = 0;
*(undefined2 *)((int)&peVar6[entityIndex].base.frames + 3) = 0;
*(char *)((int)&peVar6[entityIndex].base.entity + 3) = param_3;   /* <- the slot */
```

The 32 bits at `base.entity` are zeroed first (`frames+1` and `frames+3` are the two words of
the same four bytes) and then **only byte 3 is written**, with the parameter guarded by
`if (param_3 != -1)`.  So the byte at `agnt_t+0x1a` is written as a party slot with an 0xff-style
sentinel, and the parameter is now `partySlot`.

This closes the loop on the earlier far-pointer finding.  The two writes are the same 32 bits:

| writer | bytes written |
|---|---|
| `ovc15_usesAgntFlag1` / `ovc15_usesStExit` | `+0x17 = Entities + index`, `+0x19 = Entities.seg` |
| `ovc15_usesLDIV_at_2` | `+0x1a = partySlot` (after zeroing the other three) |
| `ovc15_usesAgntFlag1` (line 39-40) | `frames+1 = 0`, `frames+3 = 0` |

So the entity pointer's **segment high byte is the party slot** -- the design stores the slot in
the top byte of the segment, which is exactly why every reader takes `entity.seg >> 8`.  The
decompiler cannot express that as two fields, and a `partySlot` component at 0x1a would overlap
the pointer, so `agnt_t.entity` stays `entity_t *32` and the fact is recorded here (this is now
confirmed by a writer, not only by readers).  `char_sheet_t+0x89` carries the same value as
`partySlot`, so the two records agree.

## Two more parameters (2)

- `ovc15_usesLDIV_at_2`'s `param_3` -> `partySlot`, from the store above.
- `draw_compute4`'s `param_1` -> `type`: it returns 1 only for the hard-coded set
  {9, 0xe, 0x1c, 0x1e, 0x1f, 0x20, 0x37, 0x38, 0x39, 0x44, 0x45, 0x55} and 0 otherwise, i.e. a
  membership test over type codes.

Auto-named parameters: 577 -> 575.

## 14 parameters: the save primitives, an entity state setter and another matcher

### `save_usesWrite` / `save_usesRead` (8)

Both forward to the C library and compare the result with the requested count, and the call
sites spell the argument order out:

```c
save_usesWrite(iVar2, (void *)SaveHeader.ofs, SaveHeader.seg, 0x28);
save_usesWrite(iVar2, GUnitGrid, GUnitGrid._2_2_, 0x4560);   /* 148 * 60 * 2 */
save_usesWrite(iVar2, GMapCells, GMapCells._2_2_, 0x22b0);  /* 59 * 148 */
```

so `handle`, `buf` (offset), `bufSeg`, `count` -- eight parameters across the pair.  The
decompiled body passes `param_3` to `write()` as the length because the far pointer's second
word was split into its own argument; the call sites are what identify it as the segment.

### `unit_usesEntities` (2)

```c
if (param_1 != '\x02') {
  if (param_1 == '\x03') { flags32 |= 1; ovr_attact_usesEntities(param_2,0,0,param_3,param_4); }
  else if (param_1 == '\x04') { flags32 |= 2; targetX = x; targetY = y; ... }
}
```

so `param_1` is a small `state` code and `param_2` is the `entityIndex` into `Entities`.

### `ovc25_usesAlignUp46` (4)

```c
uVar2 = alignUp4(*(int *)&Entities[i].base.targetX);  if (uVar2 == alignUp4(param_1)) ...
if (Entities[i].base.targetY == param_2) ...
if (*(char *)((int)(char **)GMenuStrings + gindex * 0x95 + 0x1f) != param_3) return 0xff;
*_param_4 = 0;  ...  *_param_4 = 1;
```

→ `x`, `y`, `excluded` (the per-gindex byte the project already names `excluded`), `foundFlag`.

Auto-named parameters: 575 -> 561.

## `bldtp_t+0x24` has a reader after all - it is the building's SFX type (24 -> 23)

The field was recorded as "only `& 0x80`", but a raw-offset scan for `0x27 + 0x132` finds a
reader in `ovc23_textAdlibNone`:

```c
cVar12 = *(char *)((uint)bVar13 * 0x27 + 0x132);
uStack_6 = (byte *)CONCAT13(cVar12,(uint3)uStack_6);
if (((5 < Entities[i].level) && (cVar12 == -0x7a)) && (bVar4 = bVar4 + 1, bVar4 < 2)) ...
if (uStack_6._3_1_ != 0x0) {
  if (CurSfxType3 == 0xff) { in_DX = CONCAT11(0x24, uStack_6._3_1_); CurSfxType3 = uStack_6._3_1_; }
  else { if ((ovr_randBelow(2) & 0xff) == 0) { in_DX = uStack_6._3_1_; CurSfxType3 = ...; } }
}
```

The value is loaded into **`CurSfxType3`**, the named global that is elsewhere compared with
0x76 and 0x70 to choose the sound, and the value 0x86 (`-0x7a`) is special-cased when the
entity's level is above 5.  So the field is the building type's `sfxType`.

That leaves `bldtp_t` with a single generated field (`field_0x0c`), whose only observed effect is
drowning when equal to 2.

## Two more parameters (2)

`ovc27_usesPlay_sfxU` builds a far pointer from its first two arguments --
`CONCAT13((char)(param_2 >> 8), CONCAT12((char)param_2, param_1))` -- so `ptrOfs` and `ptrSeg`.
Its third argument was already typed `agnt_t *`; the fourth goes to `ovc27_compute3` whose own
parameters are still unnamed, so it stays auto-named.

### Examined and refused in the same pass

- `ovc15_usesRandBelow`'s four arguments: the function picks a sound into a two-word out-pair
  (`*param_1`, `param_1[1] = randBelow(0x14)`) with two independent mode flags, so the slots
  exist but their meanings are not stated anywhere in the body.
- `ovc43_usesBiosKeyAvail`: its first three arguments are forwarded into
  `ovc43_usesStExit`'s **unused** parameters and the fourth is never read.
- `agnt_t+0x24`/`+0x25`: still byte-wide 0/1/2 state with no stated value meaning.

Auto-named parameters: 561 -> 559.  Struct fields: 24 -> 23.

## The 23 remaining struct fields: a complete accounting by code offset

Each generated component was re-checked through the offset the code actually uses (the technique
that recovered `bldtp_t+0x24`), and every one now has its obstacle recorded.  The audit's `pad_`
count is worth explaining first: `AUTO_FIELD` matches `pad_\d+`, so it counts only the
**all-digit** pad names.  `char_sheet_t` therefore reports 6 (`pad_0`, `pad_40`, `pad_52`,
`pad_64`, `pad_82`, `pad_85`); `pad_5a`, `pad_5e`, `pad_8e` and `pad_a4` contain letters and do
not match, even though they are equally generated.  `ListFieldNames.java` (new) prints exactly
which components the audit counts.

| struct | offset | obstacle |
|---|---|---|
| `char_sheet_t` | `+0` `pad_0` | passed as `blitLabel`'s **`widths`** table (`ovr_blitLabel(pcVar3, widths->pad_0, uVar7, term)`) while also read as 4-byte ints at `+4` and `+6` and compared dword-wise at `+0x1b` -- heterogeneous, and the widths use contradicts a plain 40-byte blob |
| `char_sheet_t` | `+64` `pad_40` | written `pad_40[0] = 1` in the two character-creation routines and never read |
| `char_sheet_t` | `+82` `pad_52` | written with a 0xff sentinel, then read as a table index clamped to the agent level and as a signed pixel offset (two incompatible uses) |
| `char_sheet_t` | `+100` `pad_64` | no access anywhere in the export |
| `char_sheet_t` | `+130` `pad_82` | no access anywhere in the export |
| `char_sheet_t` | `+133` `pad_85` | written `pad_85[0] = 7` in `chargen` and never read |
| `bldtp_t` | `+12` `field_0x0c` | one test, `== 2`, whose branch drowns units; a single value is not a taxonomy |
| `agnt_t` | `+5` `field_0x5` | high byte of the 16-bit store at `+4` (the two-byte peephole); the byte layout is proven by the per-byte sign tests |
| `agnt_t` | `+17` `field_0x11` | 0/1 variant that is `randBelow(2)` in the common branch |
| `agnt_t` | `+36` `field_0x24` | byte-wide 0/1/2 state selecting sprite branches; no stated value meaning |
| `agnt_t` | `+37` `field_0x25` | same, set to 2 and tested `== 2` |
| `agnt_t` | `+42` `field_0x2a` | one comparison with 0 |
| `anm_t` | `0x10..0x18` (9) | no read by field name and none by `* 0x1e` stride offset; the records are constant archive data, so no writer exists either |
| `agntG_t` | `+82`, `+148` | no access at all (size-derived padding) |

That is the whole of the 23, each with the specific reason a name would be a guess rather than
a finding.

## One more parameter (1)

`ovc15_compute1`'s argument is an `agnt_t *`: it reads `+0x11`, and the far pointer at
`+0x13/+0x15` (`frames`), and `*param_1` is the agent's `x`.  Only the name is applied; the
declared type stays a 2-byte pointer because widening it would change what callers push.

Auto-named parameters: 559 -> 558.

## Correction: the `+0x94` word write is in `pad_8e`, not `pad_5e`

An earlier note in this document described a 16-bit write at "`char_sheet_t+0x94`
(`pad_5e`)".  The two numbers are different: `AuditTypes` prints component offsets in
**decimal**, so `pad_5e` is at 94 = `0x5e`, while the code's `+ 0x94` is 148 -- inside
`pad_8e` (142..159), six bytes in.  `pad_5e` therefore has **no access anywhere** in the
export, and the word write belongs to `pad_8e`.

## The four lettered pads, checked by code offset

`AUTO_FIELD` only matches `pad_\d+`, so `pad_5a`, `pad_5e`, `pad_8e` and `pad_a4` are
generated fields the audit does not count.  Their code offsets are `+0x5a`, `+0x5e`, `+0x8e`
and `+0xa4`, and searching those finds real accesses:

| pad | offset | evidence |
|---|---|---|
| `pad_5a` | `+0x5a` | `*(char *)(sheet + 0x5a) = param_1` in `ovc18_textFortressCannotPlaced`, with a separate `= 1` branch when the argument is 2: a mode byte whose two values are the only evidence, so refused |
| `pad_5e` | `+0x5e` | **no access at all** |
| `pad_8e` | `+0x8e` | `if (*(int *)(sheet + 0x8e) == 0) { piVar = (int *)(sheet + 0x8e); ... }` -- a 32-bit field whose address is taken, plus a 16-bit write six bytes in (the `+0x94` above); it behaves like a far pointer but is never built from an ofs/seg pair, so refused |
| `pad_a4` | `+0xa4` | `ovc22_usesPlayerCount`: `bVar2 = PlayerCount / 2 + 1; if (10 < bVar2) bVar2 = 10; *(byte *)(sheet + 0xa4) = bVar2;` and readers add it to another byte; the formula is pinned but what the number *is* is not stated |

## `driver_compute5`'s six slots (6)

Its only call site groups the arguments as (x, y) pairs, and the body sorts exactly the three
second elements:

```c
ovr_driver_compute5(0x12e, row1, ofs2, y1, 0x126, row1 + 8);
/* body: if (param_4 < param_2) { param_4 = param_2; param_2 = bVar1; } ... param_6 ... */
```

so `x1, y1, x2, y2, x3, y3` -- three vertices sorted by y for a scanline fill.  This is the one
case where the earlier refusal was lifted: the call site shows the pairing, and the body's sort
of the even-numbered arguments confirms which ones are the y values.

Auto-named parameters: 558 -> 552.

## `agnt_t+0x24`/`+0x25`: every writer enumerated, still unnamed

The step asked for a writer that assigns a symbolic value.  A scan of every store to the two
bytes across the export finds only constants:

| site | store |
|---|---|
| `agnt_usesAgntCount` | `+0x25 <- 1` |
| `ovc15_usesAgntFlag1` | `+0x24 <- 2` |
| `ovc41_textFailsTurn` | `+0x24 <- 1` |
| `ovc49_usesBlitGfxRect` | `+0x25 <- 2` (four sites), `+0x24 <- 0` (two), `+0x24 <- 2` (one) |

No store comes from a named global, a parameter, or a table entry -- so the value set is
`{0,1,2}` and nothing in the binary says what the three states mean.  The readers select one of
three sprite branches (`== 0` blits the anim block at `cmap + 6`, `== 1` blits a second block and
counts down `agnt+0x23` (`timer`), `== 2` blits a third), so a name would be a description of the
artwork rather than of the code.  Final refusal, with the complete writer list above.

## Nine parameters from the construction corner helpers and the blitter (9)

### The three corner/map reads

All three take a map **column**:

```c
/* ovc23_usesCornerBR  */ constr_usesSmoothPrev(param_1, -1, &cornerTL);  ... param_1 + 1/2/4
/* ovc23_usesCornerBR2 */ constr_usesSmoothPrev(param_1, ...);           ... param_1 + param_2
/* ovc23_usesGMapFlags */ if ((-1 < param_1) && (param_1 < 0x94)) GMapFlags[unitIndex][param_1]
```

so `x` in each, and `ovc23_usesCornerBR2`'s second argument is the `step` added to reach the far
corner (its own `param_2 == 4` branch picks a hard-coded pair instead).

### `blit_compute1` - three of fourteen

Its only call site passes 14 arguments, three of which are unambiguous:

```c
blit_compute1(rectOfs[4], iVar2, iStack_12, CONCAT22(iStack_c,unaff_SS),
              *(uint *)(uVar5 + 5), uStack_10,
              *(uint *)((uint)bStack_7 * 2 + 0x470), uStack_22,   /* mask, x2 - x1 */
              iStack_1c, iStack_1e, iStack_20, iStack_16, iStack_1a, unaff_DI);
```

arg1 is the destination segment (`rect[4]`), arg7 is the table value ANDed with a rotating bit
inside, and arg8 is `uStack_22 = x2 - x1` -- so `dstSeg`, `mask`, `dx`.  The other eleven depend
on locals of `blit_usesStExit`, which is itself an unresolved dither blitter, so they stay
auto-named rather than guessed.

### `ovc23_textConstructionAbandoned` - two halves

`dst.seg = (uint16_t)param_2; dst.ofs = (uint16_t)param_1;` makes the first two arguments the
halves of a far pointer (`ofs`, `seg`).  The third indexes the `0x885`/`0x889` direction tables
but is also compared `(byte)param_3 < 6` / `< 0xb` to pick a graphic, so it stays auto-named.

Auto-named parameters: 552 -> 543.

## 20 parameters: the construction/map helpers and the driver primitives

### OVC23's map-coordinate readers (11)

Five functions in `OVC23` take a map coordinate pair, each pinned by the array or the cursor
global it is compared with:

```c
ovc23_usesGUnits:       GUnitGrid[param_1][param_2]                    /* 148 x 60 */
ovc23_usesGfxRndSeed2:  GfxRndSeed2 == param_2 && GfxRndSeed-2 <= param_1 <= GfxRndSeed+1
ovc23_usesAlignUp4:     alignUp4(param_1) vs record[+2],  record[+4] == param_2,
                        sheet->excluded == param_3
ovc23_usesAlignUp44:    GMapFlags[param_2 + 1][param_1]
ovc23_compute2:         forwards positionally into usesAlignUp44
```

`GfxRndSeed`/`GfxRndSeed2` are the map cursor x/y (they are what `attact_usesMenuItemEnabled`
compares with `entity.base.x`/`.y`), which is what makes the second line's x/y unambiguous.

### The driver primitives (9)

| function | parameters | evidence |
|---|---|---|
| `driver_zeroWords` | `dst` | `*dst++ = 0`, count on the stack; `param_2` unread |
| `driver_copyWords` | `src`, `dst` | `*dst++ = *src++`; `param_3` is used as a pointer |
| `vgaSetPalette` | `paletteOfs`, `paletteSeg`, `startIndex` | pointer halves via `CONCAT12`, and `out(0x3c8, param_3)` |
| `countRunLength` | `src`, `limit` | run of equal bytes, clamped by `param_3` and a stack limit |
| `driver_loop3` | `paletteData` | count at `*param_1`, then runs advanced by `n * 3` (RGB triples) |

`driver_loop3` is the memory-writing twin of `vgaDoSomethingWithPalette` (which writes the same
script through `out(0x3c8)`/`out(0x3c9)`), so both take a `paletteData` script.

### Refused in the same pass

- `ovc23_usesAlignUp43` (55fe:0af5): carries *Control flow encountered bad instruction data* and
  an overlapping-instruction warning at 0x53af7/0x53af6.
- `driver_compute1`/`driver_compute2`: pure byte arithmetic (`(param_3+param_1+param_2)`,
  `(param_2-param_1)>>2`) with no positional meaning.
- `driver_scan1`'s `param_2`/`param_6`, `driver_loop1`'s `param_3`, `driver_compute3`/`4`'s
  `param_5`: never read.

Auto-named parameters: 543 -> 523.

## 13 parameters from the RLE decoders and two clipped fills

### The RLE decoders

| function | parameters | evidence |
|---|---|---|
| `driver_unrleScreen` | `src` | the whole body reads `param_1` as the stream (200 rows, `+0x140` stride into a stack destination); `param_2` is never read |
| `driver_unrleSprite` | `spr`, `dst` | `pbVar10 = (byte *)((int)dst + *spr * 0x140)`, the stream starts at `spr + 2`, and `spr[1]` is the row count |
| `drawLine2` | `src`, `dstOfs` | writes backwards from `stackDst + dstOfs - 1` down to `dstOfs` (`while ((uint)dstOfs <= pbVar6)`); `param_2` is never read |

### `driver_loop2` (5)

A clipped horizontal fill, the same shape as `ovc07_usesFillRect`:

```c
if (param_2 < param_1) swap(param_1, param_2);
if (param_1 < rect[0]) param_1 = rect[0];
if (rect[2] < x2) x2 = rect[2];
if ((rect[1] <= y) && (y <= rect[3])) {
  puVar4 = (undefined1 *)(x1 + y * 0x140);
  for (i = (x2 - x1) + 1; i != 0; i--) *puVar4++ = colour;
}
```

so `x1, x2, y, colour, rect`.  The rect is named rather than retyped: it is a 2-byte `int *`
and widening it would change what callers push.

### `gfxRlePrepare` (3 of 7)

```c
uVar1 = (int)((uint)(byte)scale * *(int *)(gfx.ofs + 1)) >> 4;
x = x - uVar1;
y = y - ((int)((uint)(byte)scale * *(int *)(gfx.ofs + 3)) >> 4);
if (x < rect[0]) ...
```

so `x`, `y` and `scale` (a fraction in 16ths).  Its `param_7` selects one of two reference
edges (the plain width or `right - left`) but nothing states which, so it stays auto-named, as
does `param_4`/`param_5` (the rect halves).

Auto-named parameters: 523 -> 510.

## 8 parameters: the season-palette fades and OVC22's map tests

### The two palette fades (2)

`setSeasonPalette` and `ovc40_usesVgaSetPalette8bit` run the same loop:

```c
for (u = 0; u < 0x300; u++)
    local[u] = (char)(((long)(int)(uint)*(byte *)((int)param_1 + u) * (long)(int)step & 0xffff) / 10);
ovr_vgaSetPalette8bit(local);
```

0x300 = 768 bytes and the division by 10 is the fade step, so `param_1` is the target `palette`
in both.

### `ovc40_usesStshLoadGfx` (1)

```c
if (param_1 == 4) { handle = youlose1Cut1; }
else { handle.seg = ((undefined2 *)&back03Cut1Seg)[param_1 * 2];
       handle.ofs = ((undefined2 *)&back03Cut1Ofs)[param_1 * 2]; }
```

a backdrop selector with 4 special-cased to the losing screen -- the same role as
`ovc40_usesBlitGfx10`'s `backdropIndex`, so the same name.

### `ovc22_usesGMapFlags` (3)

```c
pcVar1 = ovc22_textArena(param_1, param_2);
... if ((GMapFlags[param_2][param_1] & param_3) == 0) ...
```

so `x`, `y` and a `mask`, with the pair also forwarded positionally into `ovc22_textArena`.

### `ovc22_loop1` (3 of 5)

It walks outward from a coordinate pair held **by pointer** (the loop writes `*xPtr`) and uses
its fifth argument to index the party table (`*(undefined4 *)((uint)partyIndex << 2)` then
`+0x3f`, the field this project names `excluded`), so `xPtr`, `yPtr`, `partyIndex`.  Its third
and fourth arguments are packed into a far pointer byte-by-byte
(`CONCAT12(param_4, CONCAT11(..., param_3))`), which is a decompiler artifact rather than two
named slots, so they stay auto-named.

Auto-named parameters: 510 -> 502.

## 10 parameters: the construction tallies and three more map pairs

### `manage_usesGUnitCount`'s counters (4 of 7)

The function counts construction records and placed units for one `(partyIndex, unitType)`
pair, split by `bldtp_t+0x23` (`resource`):

```c
/* units loop */
if (resource == 1) *param_3 += 1;
else if (resource == 2) *param_5 += 1;
else if (resource == 3) *param_7 += 1;
/* records loop */
*param_9 += 1;                       /* every matching record */
if (resource == 1) *stack_18 += 1; else if (resource == 2) *stack_1c += 1; else *stack_20 += 1;
...
*param_3 -= *stack_1c;   *param_5 -= *stack_20;
```

so `resource1Count`, `resource2Count`, `resource3Count` and `recordCount`.  The subtraction of
the record tallies at the end is recorded but does not change what each slot holds: the number
of **units** whose building type carries that resource value.

**`param_4`, `param_6` and `param_8` are never dereferenced** -- the caller passes a (pointer,
segment) pair for each output, and the even slots are the segment words.  They stay auto-named
because a name would describe the calling convention, not the data.

### Three more map pairs (6)

| function | evidence |
|---|---|
| `ovc22_textArena` | bounds `param_1 + 1 <= 0x93` and `param_2 + 1 <= 0x3b`, then `GMapFlags[param_2][param_1]` and `GMapCells[param_2+1][param_1+1]` |
| `ovc22_usesGOngoingBattle` | `param_2` against `GfxRndSeed2 - k` and `param_1` against `GfxRndSeed + table[...]` |
| `ovc22_usesGOngoingBattle2` | the same with a different k |

All three are `x`/`y`; `GfxRndSeed`/`GfxRndSeed2` are the cursor pair already pinned against
`entity.base.x`/`.y`.

### The 4528 tail

Only three parameters remain in `saveui` and none is nameable:
`saveui_usesBlitGfx10`'s `param_5` and `saveui_textSsavesTxt`'s `param_2` are never read, and
`saveui_usesBlitText`'s `param_2` lands in `blitText`'s `widths` slot while every caller passes
the string's **segment** (`0x2410`) there -- a far-pointer split, so a name would describe the
decompiler's argument mapping rather than the code.

Auto-named parameters: 502 -> 492.

## 6 parameters from OVC45/OVC43/OVC28

### `ovc45_usesGMapFlags5` (3)

```c
if (param_1 == '\x01') { ... GMapFlags[param_3] + param_2 ... }
else if (param_1 == '\x02') { ... GMapFlags[param_3][param_2] & 1 ... }
```

so `mode`, `x`, `y` -- the first argument only chooses which flag bits are tested.

### Three map lookups and one asset open

| function | parameter | evidence |
|---|---|---|
| `ovc45_usesGMapFlags4` | `x`, `y` | bounds `0x93`/`0x3b`, then `GMapFlags[y][x]` |
| `ovc45_usesLand_info` | `screenX` | converts its argument to a map column with `(param_1 - 9) / 0x30` (0x30 = 48, the cell size) |
| `ovc28_usesUiInputText`, `ovc28_compute2` | `hint` | the third argument sits in `uiInputText`'s `hint` position |
| `ovc43_textToymaker` | `fileId` | `file_id = ovr_stshOpen(param_1)`, then `ovc43_usesBiosKeyAvail(file_id, ...)` |

### The party-gold check (2 of 3)

`ovc45_usesGPopulationLo` compares its second and third arguments with the party sheet's 32-bit
value before subtracting:

```c
iVar6 = *(int *)(iVar5 + 0x58);
if ((iVar6 < param_3) || ((iVar6 == param_3) && (*(uint *)(iVar5 + 0x56) < param_2))) ...
uVar3 = param_2 - uVar4;
```

`+0x56/+0x58` is the sheet's `gold` long (`ovc28_textGold` formats exactly that pair), so the
arguments are `goldLo`/`goldHi`.  Its first argument indexes the 0x217A table and is already
`partyIndex` (renamed in an earlier pass, which is why the tool reported it as missing).

### Refused

`stats_textRingProt` (6386:0411) carries *Control flow encountered bad instruction data*, an
overlapping instruction at 0x6014c/0x6014b and an untracked spacebase, so its three slots stay
auto-named.

Auto-named parameters: 484 -> 478.

## 12 parameters from the OVC45 done-screens and the stats helpers

### `ovc45_usesAlignUp4` (4)

It searches the entity list for the **lowest party slot above** its first argument at a map
cell:

```c
if ((alignUp4(entity.x) == param_2) && (entity.y == param_3) &&
    (param_1 < *(byte *)((int)&entity + 3))) && (*(byte *)((int)&entity + 3) < bStack_3))
  { bStack_3 = slot; *_param_4 = index; }
```

so `slotMin`, `x`, `y` and `entityIndexOut` (the out-parameter holding the matching index).

### The two done-screens (5)

`ovc45_textDone` and `ovc45_textDone2` share their shape:

```c
x = param_4;                                  /* the record's x */
createConstructionRecordFar(..., (int)x, GfxRndSeed2, outFlag, (byte)param_6, ...)
```

and the fifth argument of `createConstructionRecordFar` is the **segment half** of its outFlag
pointer -- callers elsewhere pass `(byte)unaff_SS` there.  So `x` and `outFlagSeg`.
`textDone2`'s third argument indexes `Entities` and is `entityIndex`.

### Two stat helpers (3)

| function | parameter | evidence |
|---|---|---|
| `stats_compute6` | `x`, `y` | forwards both into `video_usesAgntCount`, whose only other caller passes `(MouseX - 0xc, MouseY - 7)` |
| `stats_usesLDIV_at_` | `valueLo` | `litoa10(text, CONCAT22(stackHigh, param_3))`; `param_2` is never read |

### Refused in the same pass

- `ovc43_usesStshSeek`'s four: the first is only used as `*(u16 *)((int)param_1 + 3)` for a seek
  target and the other three are forwarded into `ovc43_usesBiosKeyAvail`'s three **unused**
  parameters.
- `ovc43_usesBiosKeyAvail`'s four: three are forwarded into `ovc43_usesStExit`'s unused slots and
  the fourth is never read.
- `ovc45_textDone`'s `param_1` and `ovc45_textDone2`'s `param_1`: only ever tested `!= 0`.

Auto-named parameters: 478 -> 466.

## 65 parameters from the CRT, the driver and five game modules

### The pointer-width hazard, re-confirmed

`ovc18_textTypeLen` takes a 4-byte far pointer to a party sheet.  Renaming it with
`/char_sheet_t *` applied a **2-byte near pointer** and Ghidra re-derived the parameter list:
`param_4` changed from `int *` to `undefined2`.  The fix is the explicit far type:

```
48ac:0382	sheet	sheet	/char_sheet_t *32
```

`/char_sheet_t *32` is size 4 (like `/st.h/agnt_t *32`), so the nine-parameter layout
(4 + 2 + 7*2 = 20 bytes) is preserved and `param_4` is `int *` again.  A second detail: a rename
entry must use the variable's *current* name, so after the first attempt `param_1` no longer
existed and the corrected line had to say `sheet`.  The audit's struct-argument count does not
move for `*32` types (they are composites, not `Pointer` instances), which is why the metric
stays at 137 while the declaration is now correct.

### The CRT text primitives (12)

| function | parameters | evidence |
|---|---|---|
| `__VALIDATEXY` | `y2, x2, y1, x1` | x bounded by `_video.screenwidth`, y by `_video.screenheight`, requiring `x2 >= x1` and `y2 >= y1` |
| `__SCREENIO` | `width, srcOfs, srcSeg, dstOfs, dstSeg` | from `_puttext`: first arg is `(x2-x1)+1`, last two are the `__VPTR(y,x)` halves |
| `__write` | `fd, bufOfs, bufSeg, count` | `uStack_e = CONCAT22(param_3, param_2)` builds a far pointer; `param_4 + 1 < 2` is the zero-length test |
| `LUDIV_at_` | `dividendLo, dividendHi, divisorLo, divisorHi` | fast path divides `CONCAT22(param_2,param_1)` by `param_3`; the loop subtracts `param_4:param_3` from the remainder |
| `__INITEXTMEM` | `sizeLo, sizeHi, baseLo, baseHi` | `(param_4:param_3) + (param_2:param_1)` stored as base then top |

### The driver and OVC42/OVC45/OVC34 (20)

- `constr_compute1/2` get `cornerA/cornerB/cornerC, flags, bit`: call sites pass three corner
  samples plus a mask and a literal 1 or 2, which also **lifts the earlier `flags & bit`
  refusal** -- the AND is not symmetric once the fifth slot is always a single bit.
- `ovc42_usesBlitGfxRect` gets `exitCode, paletteOfs, paletteSeg`: its callers pass a literal
  0 or 3 and `CONCAT22(unaff_SS, (int)palette)`, and the body rebuilds the 4-byte palette
  pointer before calling the already-named `...VgaSetPalette8bit`.
- `ovc42_usesBlitGfxRect2` gets `flag` (sets bit 0 of a flags word) and `level` (a non-zero
  value replaces the level that would be read from the 0x95-stride table, then indexes the
  stride-4 level table).
- `unit_usesAlignUp42` gets `menuIndex, x, y`: it indexes the 0x744/0x749 per-menu tables and
  builds a 0x13-stride square record from `alignUp4(x)` and `y`.
- `ovc41_textParalyzed` gets `strength` (clamped to the target's own strength; only a stronger
  attack paralyzes).
- `bldng_usesBldng` gets `bldTypes, entries, count`: a selection sort over a stride-2 word array
  and a parallel stride-4 far-pointer array, both swapped together.
- `ovc22_usesAlignUp4` gets `unitType` (compared with `GUnits[..].unitType`) and `mask` (OR of a
  +/-2 `GMapFlags` window).
- `ovc22_usesAlignUp42` gets `xOut`, `yOutOfs`, `yOutSeg` (it writes the aligned x through
  `param_1` and the record y through the split pointer).
- `ovc22_usesLUDIV_at_2` gets `valueLo`, `valueHi` (the pair passed to `LUDIV_at_` as the
  dividend's low and high words).
- `ovc45_usesAlignUp4` gets `slotMin, x, y, entityIndexOut` -- it finds the lowest party slot
  strictly above `slotMin` at a cell.
- `ovc45_usesGMapFlags5` gets `mode, x, y`; `ovc45_usesGMapFlags4` `x, y`;
  `ovc45_usesLand_info` `screenX` (`(x - 9) / 0x30`, 0x30 = the 48-pixel cell).
- `ovc45_textChoosePartyBuild` gets `x, y, entityIndexPtr`; `ovc43_textToymaker` `fileId`
  (`ovr_stshOpen(param_1)`).
- `stats_compute6` gets `x, y` (forwards into `video_usesAgntCount`, whose other caller passes
  `MouseX-0xc, MouseY-7`).
- The two `ovc45_textDone` screens get `x` and `outFlagSeg` (the fifth argument of
  `createConstructionRecordFar` is the segment half of its outFlag pointer; other callers pass
  `(byte)unaff_SS`). `textDone2` also gets `entityIndex`.
- `manage_usesGUnitCount` gets `resource1Count/resource2Count/resource3Count/recordCount`
  (split by `bldtp_t+0x23`), while its `param_4/param_6/param_8` are the never-dereferenced
  segment words of the caller's output pairs.
- `ovc23_usesCornerBR/CornerBR2/usesGMapFlags` get `x` (and `step` for CornerBR2);
  `ovc23_usesGUnits` `x, y`; `ovc23_usesGfxRndSeed2` `x, y`; `ovc23_usesAlignUp44`/
  `ovc23_compute2` `x, y`; `ovc23_usesAlignUp4` `x, y, excluded`.

### Refused in the same pass, with the obstacle

| candidate | why |
|---|---|
| `ovc18_textTypeLen`'s `param_3..param_9` | only `param_4` (`-= stack`) and `param_8` (`+= 1`) are written and `param_6/7/9` are never read; `param_3`'s low byte is forwarded into `ovc18_textBathHouse`'s already-refused flag slot |
| `ovc41_textParalyzed`'s `param_1`/`param_2` | the body sets the target's timer on `param_2` (so it is the victim) while the message reads `agnt_textHeld(param_1, victimName)` first -- the two disagree, so neither slot is named |
| `ems_memmove1/2` (6 each) | the INT 67h register block assigns `param_1/param_2`, `param_3/param_4`, `param_5/param_6` to `emms_var05c1/05c3`, `05ba/05bc`, `05b3/05b5`, and call sites disagree on which pair is source |
| `blit_compute1`'s remaining 11 | they depend on locals of `blit_usesStExit`, itself an unresolved dither blitter |
| `ovc22_textRingProt` (7) | unstable decompilation, unchanged |
| `ovc43_usesStshSeek` / `ovc43_usesBiosKeyAvail` (8) | three of each four arguments are forwarded into `ovc43_usesStExit`'s **unused** parameters |
| `ovc15_usesRandBelow` (4) | it fills a two-word sound out-pair and branches on two mode flags whose meanings are not stated |
| `ovc49_body1` (5) | the batch decompiler times out on it |

Auto-named parameters: 466 -> 401.

## 33 parameters from a call-slot scan, plus what it cannot decide

The scan behind this batch is narrow on purpose: for each still-unnamed parameter, collect
**every** line where it appears, and accept a name only if the only use is one argument
position of a call whose callee slot already carries that name.  It is a candidate generator,
not a proof -- `saveui_usesBlitText`'s `param_2` satisfies it (`ovr_blitText(text, param_2, ...)`,
the `widths` slot) but is refused, because every caller passes the string's **segment**
(`0x2410`) there.  Each candidate below was therefore read line by line first.

| function | parameters | evidence |
|---|---|---|
| `__UTOA` | `buf`, `valueLo` | tail-calls `__LONGTOA('a','\0',10, param_1, param_2, param_3)` and `param_2` is the slot `__LONGTOA` never reads |
| `bios` | `width`, `vramOfs`, `vramSeg` | counts down `param_1`, walks `CONCAT22(param_3, param_2 + 1)` and measures it with `screenpos` |
| `_atoi`, `_fputc` | `s`; `c`, `stream` | single forwards into `_atol` / `fputc` |
| `ovc22_textArena2` | `x`, `y` | forwards into `ovc22_textArena(x, y)` and also indexes the map with the same pair |
| `ovc22_loop1` | `yOutOfs`, `yOutSeg` | the third argument goes to `ovc22_usesAlignUp42`'s `yOutOfs` slot and `param_4` is the same split pointer's high word |
| `ovc23_usesGUnitGrid`, `ovc23_compute1` | `unitType` | `ovr_ovc18_usesRandBelow(x,y,bldType,param_4)` at every site (8 for `compute1`) |
| `ovc23_textUnitDrowns` | `x`, `y` | `GMapFlags[param_2 + 1][param_1]` and comparisons with `entity.x`/`entity.y` |
| `ovc31_usesClose` | `filename` | `file_open_rdonly(param_1)` |
| `drawString`, `ovc50_usesBlitText` | `widths` | single use as `ovr_blitText`'s `widths` slot |
| `ui_textDefineRegionCommand`, `ovc41_usesDrawTextAt`, `ovc41_usesMiceBlitRect` | `menuIndex` | index `MenuItemEnabled` / compared with `GMenuItem` |
| `season_textHalflingCastle` | `formatIndex` | `ovr_ovc40_usesAlignToSeg(..., param_1)` at both sites |
| `ovc38_usesStshFree` | `handle` | `ovr_stshFree(param_1)` |
| `ovc40_usesAlignToSeg`, `ovc41_usesBiosKeyAvail` | `backdropIndex` | passed to `ovc40_usesBlitGfx10`/`ovc40_usesStshLoadGfx`, whose slot is already `backdropIndex` |
| `ovc18_textTypeLen` | `recordCount` | `*_param_8 += 1` once per matching construction record -- the same statement that gave `manage_usesGUnitCount` its `recordCount` |
| `ovc28_usesBlitGfx10`, `ovc28_usesScreenMode` | `entries`, `count` | a stride-4 far-pointer table whose entries are null-tested (`*p != 0 || p[1] != 0`), bounded by the second argument |
| `keyprocessor_usesBiosKeyAvail` | `x` | moves `*param_1` in 8-pixel steps clamped to `0xde` |
| `ovc26_usesRandBelow` | `outFlagSeg` | `ovr_createConstructionRecordFar(..., (byte)param_3, partySlot)` -- the fifth slot is the outFlag pointer's segment |

### What the EMS pair actually does, and why it still has no names

Comparing the two functions side by side settles their *shapes* even though no field of the
block is named anywhere in the program:

```c
/* ems_memmove1 */                       /* ems_memmove2 */
var05b7 = 1;  var05b8 = EMS_Handle;      var05b7 = 0;  var05b8 = 0;
var05bc = page(param_4, param_3);        var05ba = param_3;  var05bc = param_4;
var05ba = param_3 & 0x3fff;
var05be = 0;  var05bf = 0;               var05be = 1;  var05bf = EMS_Handle;
var05c1 = param_1; var05c3 = param_2;    var05c3 = page(param_2, param_1);
                                        var05c1 = param_1 & 0x3fff;
var05b3 = param_5; var05b5 = param_6;    var05b3 = param_5; var05b5 = param_6;
```

So exactly one of the two 32-bit addresses is converted to an expanded-memory page plus a
14-bit offset (`& 0x3fff`, and the shifted page built from the other word), and the other is
stored raw -- i.e. one side is EMS and the other conventional memory.  `ems_memmove1` converts
the **third/fourth** arguments and `ems_memmove2` the **first/second**.  But which side is the
source is decided by field order only: the only markers are `emms_var05b7/05b8` versus
`emms_var05be/05bf`, which are the decompiler's auto-names for an absolute data block, and no
symbol at that block exists in the export.  Naming `src`/`dst` from that ordering would be a
guess about which label is the source type, so both functions stay refused -- now with the
asymmetry documented, which is the part the binary does state.

Auto-named parameters: 401 -> 368.

## `F_SCOPY`'s parameter names were inverted - corrected (12 locals + 1 signature)

The compiler helper was declared `F_SCOPY(uint8_t *dst, uint8_t *src, uint16_t nbytes)`, but its
body says otherwise:

```c
for (uVar3 = in_CX >> 1; uVar3 != 0; uVar3--) {
  puVar2 = (uint8_t *)nbytes;  nbytes  = nbytes + 2;   /* written */
  puVar1 = dst;                dst     = dst + 2;      /* read    */
  *(undefined2 *)puVar2 = *(undefined2 *)puVar1;
}
```

The **third** argument is the destination and the **first** is the source; the count travels in
`CX`.  Every call site agrees: `F_SCOPY(0x59aa, 0x2410, reqLevel1)` copies `DGROUP:59AA` into
the stack array, so the middle argument is the *source segment* (the routine relies on DS/ES
being preset, which is why the body never touches it).  The parameters are now
`srcOfs`, `srcSeg`, `dst`.

That correction immediately made twelve locals readable, because each was only ever the copy
destination:

| local | new name | evidence |
|---|---|---|
| `36ce:1f99 local_c[2]` | `dst` | sole use is the third argument of one `F_SCOPY` |
| `4528:1ae8 local_20[20]` | `dst` | same |
| `69c8:04c6 local_6c[4]` | `dst` | same |
| `69c8:011e`, `69c8:01ac` `local_306[768]` | `pal` | filled element-wise, then handed to `ovr_vgaSetPalette8bit` |
| `69c8:0317 local_306[768]` | `pal` | passed to `calcSeasonPalette`, `usesVgaSetPalette8bit` and `setSeasonPalette` (two of the three slots are the palette) |
| `5ded:0fd2`, `5ded:105e`, `6a8f:0b39` `local_ca[80]`/`local_aa[80]` | `text` | the only use is `ovr_agnt_textHeld(agnt, <local>)` |
| `68ac:0148 local_5a[80]` | `text` | filled char-by-char, then `ovr_blitText(<local>, ...)` |
| `1000:2e59 local_90[130]` | `buf` | the text-mode conversion buffer passed to `write(fd, <local>, ...)` |
| `6018:1398 local_36[9]` | `menuEntries` | a `far_t[9]` built in place and passed to `uiInputText`'s `entries` slot; `entries` alone collided with the parameter |

## The animation frame tables: identified as tables, not nameable as sprites

`init_assets2` builds dozens of **frame tables** as pairs of word globals used with a 4-byte
stride, `((undefined2 *)&word_X)[frame * 2] = asset` and `[frame * 2] = seg`.  Extracting each
table's source LBM and frame count gives a precise picture:

| table (ofs/seg) | LBMs | frames | built by |
|---|---|---|---|
| `0231`/`0233` | 12 | 4 | `stshRleType2(..., 16, i*0xe+0xd, 24, 6, 4)` in the **same loop** as `CrossBlitGfx` (`stshRleCut(..., 46, i*0xe+0xd, 55)`) |
| `01D5`..`021F` (4 tables) | 93 | 0x17, 0x18, 0x20, 0xe | `stshRleType2` |
| `0175`..`01CB` (6 tables) | 94, 95, 96 | 0xe, 0x11 | `stshRleType2` |
| `00F5`..`016D` (8 tables) | 531, 532, 533, 534 | 0x20, 0xe | `stshRleType2` |
| `07BA`..`086C` (12 tables) | **all 535** | 5, 7, 8, 3, 0x11, 0xe | `stshRleType2`, one of them right after `anim_tmstrsCut1` |
| `08B8`/`08BA` | 35 | 4 (`if (3 < i) break`) | `stshRleType2(..., 0, i*0x16+0x15, 14, 11, 7)` |

So the *kind* of each global is settled (a frame-indexed far-pointer table of RLE-type-2 cuts),
but the sprite identity is not: twelve different tables come from LBM 535 and six from LBM 93/94,
and the LBM filename therefore cannot distinguish them.  The consumers index them by
`animFrame & 3`, `timer & 3` or `BlitFrame`, which says *when* a table is used, not *what* it is.
Naming them `...FramesOfs` would require inventing the sprite name, so they stay refused with the
table above as the evidence.

One finding from the same pass is worth stating: `word_2000_BSS_06E7`/`06E9` is indexed by
`BlitFrame` in `ovc13_usesBlitLoadRleGfx` but has **no writer anywhere in the export**, so the
six-frame mouse cursor table is filled by code outside these overlays.

Local variables: 145 -> 133.  Globals and struct fields unchanged.

## `agnt_t+0x24` / `+0x25`: width confirmed from the listing

The opcodes settle the width question the decompiled text left implicit:

```
4207:0e50  CMP byte ptr ES:[BX + 0x24],0x2      ; compare with constant 2
4207:0e66  MOV byte ptr ES:[BX + 0x24],0x2      ; store constant 2
```

Both are single-byte accesses against immediate constants, and the complete writer list from the
earlier sweep is `+0x24 <- {0,1,2}` and `+0x25 <- {1,2}` from seven sites.  There is no writer whose
source is a named global, a parameter or a table entry, and the readers select one of three sprite
branches (`== 0` blits `cmap + 6`, `== 1` blits a second block and counts down `agnt+0x23`, `== 2` a
third).  Width is therefore settled (byte) and the role is settled (sprite-state selector), but the
*meaning* of states 0/1/2 is not stated anywhere in the binary, so both stay generated.

## 3 parameters from `ovc30_textDivideError`

| parameter | name | evidence |
|---|---|---|
| `param_2` | `frames` | iteration countdown: `if (param_2 == 0) return;` ... `param_2 += -1` at the end of each pass |
| `param_3` | `mode` | selects the spawn behaviour (`== 2` uses the stored centre, `== 0` picks a random one) and is replaced each pass by the next mode |
| `param_4` | `percent` | `uVar10 = ovr_randBelow(100); param_3 = (byte)uVar10 < param_4;` |

`ovc43_usesStExit`'s `param_1`/`param_2`/`param_3` are refused: the body reads only `param_4` and
`param_5` (already `sheetOfs`/`sheetSeg`), so those three slots carry no data to name.

Auto-named parameters: 368 -> 365.

## `anm_t+0x0f` and `+0x11` are 16-bit fields: `maxDx` / `maxDy` (fields 23 -> 20)

The recorded refusal said these two offsets could not be settled because `ow` at `+0x0f` is read as
a byte while the same offset is read as a word.  Three independent pieces of evidence settle it:

1. **The listing reads words.** `3b1d:0ec9 CMP word ptr ES:[BX+0xf],SI`,
   `3b1d:0ed2 MOV SI,word ptr ES:[BX+0xf]`, and `3b1d:0e5c MOV AX,word ptr ES:[BX+0x11]` (four
   sites at `+0x11`, five at `+0x0f`).
2. **The use is a clamp.** `agnt_usesStExit` computes the per-frame x delta and clamps it:

```c
uVar4 = entity->x - agnt->destX;
if (anm->maxDx < (int)uVar4) uVar4 = anm->maxDx;
else if (-uVar4 != anm->maxDx && (int)uVar4 <= -anm->maxDx) uVar4 = -anm->maxDx;
```

   and the same shape for the y delta with `maxDy`.  A `movement step limit` is the only reading that
   makes the clamp meaningful.
3. **The data agrees.**  All 68 `AgntAnms` records were dumped: byte `+0x10` and byte `+0x12` are
   **always 0**, so the word value equals its low byte and the existing byte reader of
   `+0x0f` (`ow`) sees exactly the same number.  Most records hold 1, one holds 0.

`anm_t` was rebuilt (30 bytes, 22 components):

| offset | field |
|---|---|
| +0x0f | `maxDx` (`int16_t`) |
| +0x11 | `maxDy` (`int16_t`) |
| +0x13..+0x18 | `field_0x13`..`field_0x18` (6 bytes, still unread) |

`ow` no longer exists as a separate field: it was the low byte of `maxDx`, and the revision is
recorded here so the earlier note stays traceable.

### My own tooling error in this pass, and the fix

`SetFieldType` refused (correctly, as documented): *"Not enough undefined bytes to fit int16_t at
offset 0xf"*.  I then wrote `MergeField.java`, which cleared the overlapping components and called
`replace` - that **corrupted the layout**: `StructureDB.replace` inserted a component instead of
spanning, so `maxDx` ended up 1 byte wide and two unnamed `int16_t` fields appeared at +21 and +24.
The correct tool is a full rebuild: `RebuildStruct2.java` deletes every component and re-adds the
declared list, which produced the exact 30-byte layout above.  `MergeField.java` is kept but marked
obsolete in this note; use the rebuild path for any span change.

## 2 parameters: an agent pointer and a graphics pointer

| function | parameter | evidence |
|---|---|---|
| `ovc15_usesRandBelow` | `agnt` (`agnt_t *`) | its callers pass `(int *)&agntCopy`, and the body writes offsets 0 and 2 (x, y) while reading `+0x17` as a far pointer to the entity |
| `ovc43_usesStshSeek` | `gfx` | both call sites pass a far pointer assembled from a named cut-graphics pair (`l9Cut4Ofs/Seg`, `sky06FliOfs/Seg`), and the body reads a word at +3 as the seek target |

`ovc43_usesStExit`'s `param_1`..`param_3` stay refused: the body reads only `param_4`/`param_5`.

Struct fields: 313 -> 311 components, 23 -> 20 auto.  Parameters: 365 -> 363.

## `char_sheet_t+0x52` is `level` -- the "dual use" was a base conflation (20 -> 19)

The refusal said this byte was used two incompatible ways: as a per-class table index and as a
signed pixel offset.  Checking the *base* of the second use shows it is not the character sheet at
all:

```c
uVar5 = *(undefined4 *)(uStack_22 * 0x34 + 0x1d);      /* agnt->gdata, not a sheet */
iStack_28 = ... + (int)*(char *)((int)uVar5 + 0x52) + -0x16;
```

`agnt_t+0x1d` is `gdata`, so that access is **`agntG_t+0x52`**.  The sheet has exactly one use, and
it is decisive:

```c
uVar2 = *(byte *)((int)uVar1 + 0x52) + 1;
if (*(byte *)(iVar4 + 0xf) < uVar2) uVar2 = *(byte *)(iVar4 + 0xf);   /* clamp to agnt->level */
if (0x24 < uVar2) uVar2 = 0x24;                                      /* 36 */
bStack_3 = *(byte *)((int)uVar1 + 0x2f);                             /* cls */
piVar3 = (int *)((uint)bStack_3 * 0x94 + uVar2 * 4);                 /* 0x94 = 37 * 4 */
LUDIV_at_(*piVar3, piVar3[1], 0x1e, 0);
```

A per-class table whose stride is exactly `37 * 4`, indexed by the byte clamped to `level` and to
36, is a per-level progression table; the byte is therefore the sheet's **`level`**, and the
already-named `levelLimit` at `+0x53` is its cap.  Field renamed to `level`.

### Correction: `agntG_t+0x52` *is* read

The earlier note said `agntG_t+0x52`/`+0x94` have no access at all.  That was wrong for `+0x52`:
I had searched for the stride form (`* 0x95 + 0x52`) and missed the pointer form.  The real read is
the one quoted above, a **signed byte added to a screen y** (`- 0x16`), i.e. a per-unit-type
vertical offset.  Dumping `AgntGs` (`195d:26d6`, stride 0x95) shows the byte is 0 in eleven of the
thirteen sampled records and 8 in one, which fits an offset that is normally zero.  It stays
generated because nothing in the export writes it -- the table is constant data.

`agntG_t+0x94` remains refused: its data is meaningful (5, 20, 40 across the sample) but no function
in the export reads it.

## `ovc18_textTypeLen`'s remaining slots - refused with call-site evidence

| slot | evidence |
|---|---|
| `param_3` | every call site passes `(int *)0x0`, and the body only tests `(char)param_3 == 0` before forwarding it into `ovc18_textBathHouse`'s already-refused flag slot |
| `param_4` | the body only does `*param_4 -= <count of resource-3 records>`; callers pass split stack words (`CONCAT11(...)`, `unaff_DI`), so the pointee has no recoverable meaning |
| `param_5`, `param_6`, `param_7`, `param_9` | never read anywhere in the body |

Struct fields: 311 components, 19 auto.

## Two more base conflations, and `agntG_t+0x52` becomes `yOffset` (19 -> 18)

The `char_sheet_t+0x52` result was not a one-off: two more of my stored refusals came from reading
the same offset on two different structures as if it were one.

### `agnt_t+0x11` is a byte flag - the "dword readers" were `anm_t+0x11`

The refusal said writers store bytes `{0,1,randBelow(2)}` while readers take a 32-bit step.  After
`anm_t+0x11` became the 16-bit `maxDy`, the dword reads vanished and what remains on the agent is
byte-only:

```c
*(char *)(agnt + 0x11) == '\0'        /* six sites in ovc49_usesBlitGfxRect */
MOV AL,byte ptr ES:[BX + 0x11]        /* 8699:21fa, 8699:23f1 */
CMP byte ptr ES:[BX + 0x11],0x0       /* 8699:2264, 2829, 287f, 2b28 */
```

The 16-bit reads that used to appear at `+0x11` are the animation record's `maxDy` clamp
(`paVar9->maxDy`), and the arithmetic that looked like `x -= agnt[0x11]` is
`*piVar1 = *piVar1 - paVar18->maxDy`, i.e. on the `anm_t *`.  So the **width is settled (byte)**;
only the *meaning* of the flag is unstated (it is tested `== 0` in six places and set to
0/1/`randBelow(2)`), and it stays generated on that ground alone.

### `char_sheet_t+0x1b` is compared with `agnt->owner`

The one read is

```c
} while (*(int *)(i * 0x34 + 0x1b) != *(int *)(sheet->pad_0 + 0x1b));
```

`agnt_t+0x1b` is the already-named `owner`, and other functions read it as a **word** and use it as
an `Entities` index:

```c
} while (*(uint16_t *)(i * 0x34 + 0x1b) != ((agnt_t *)param_2)->owner);   /* ovc15_textError */
peVar3 = (entity_t *)Entities + *(int *)(uVar4 * 0x34 + 0x1b);           /* ovc15_usesAgntFlag1 */
```

So the sheet's `+0x1b` holds the same kind of value: an entity index identifying the character's
unit.  What stops a name is the **width**: the only sheet-side read is the dword comparison, while
the agent side is proven 16-bit, and the function carrying the comparison
(`manage_textTotalPopulation`) has an overlapping-instruction warning at `0x5ff50` and a listing
that does not contain the code, so the opcodes cannot arbitrate.  `pad_0` stays a 40-byte blob and
the finding is recorded instead of a guess.

### `agntG_t+0x52` -> `yOffset`

Read as a signed byte added to the screen y of an agent sprite:

```c
iStack_28 = rowScreenY + agnt->y + (int)*(char *)(gdata + 0x52) - 0x16;
```

The `AgntGs` table (`195d:26d6`, stride 0x95) holds 0 in eleven of the thirteen sampled records and
8 in one, which fits a per-unit-type vertical adjustment that is normally zero.  Named `yOffset`.

`agntG_t+0x94` stays generated: its data is meaningful (5, 20, 40 across the sample) but the only
`+ 0x94` reads in the export are on the party-sheet table (`param_1 << 2`) and on stride-4 entries,
never on a `gdata` pointer.

Struct fields: 311 components, 18 auto.
