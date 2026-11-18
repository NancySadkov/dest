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
