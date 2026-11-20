# Recovery status snapshot

Measured by `scripts/ghidra/AuditNaming.java`; the raw output quoted here is
`tmp/auditn553/naming_summary.txt`.

## Where the model stands

```
functions                1123
  no prototype            114
  weak return type        963
  has struct-typed arg    169
parameters               1613   auto-named    0   (0.0%)
locals                    659   auto-named    0   (0.0%)
structs                    37
  struct fields           334   generated     0   (0.0%)
globals                  2434   auto-named    0   (0.0%)
```

Function names are complete: 1590 functions (including 460 thunks), 0 duplicates,
0 address-shaped names (`ListFuncs.java` -> `tmp/funcs11.tsv`).  The address stays in
every exported header (`// name @ addr [module]`) and in `doc/functions_renamed.tsv`.

## What is done

| area | result |
|---|---|
| function names | 1590/1590 unique and address-free; 591 renames recorded with evidence tier |
| string labels | 1516 `s_*` labels from their own bytes (`doc/strings_renamed.tsv`) |
| globals | 1096 -> 0 auto-named (26 previously unnamed DGROUP tables labelled, 74 sprite-array symbols named from the asset table); every rename quotes its writer/consumer in `doc/globals_naming.md` |
| structures | `spr_t`, `unit_t` and `entity_t` complete; `agnt_t` rebuilt as `agnt_t[52]` + `tick` + `dir`; `bld_inst_t` and most of `char_sheet_t` recovered |
| struct fields | 266 -> 0 generated |
| typing | struct-typed arguments 80 -> 172; variable type audit: params 1622 unresolved 0, locals 657 unresolved 0; of 34 heuristic far_t and 12 char[N] typings, 11 unused far_t reverted to uint32_t and the other 35 confirmed by a .ofs/.seg reader, an index, a text callee or address decay; `_fmemmove`/`__fmovmem`/`memcpy` re-typed to `(far dst, far src, count)`; `blit_usesDrawGfx`'s rectangle parameter retyped `brect_t *`, which resolves its fields by name |
| corrections | wrong names/types found by later evidence reverted (three pointer widenings, `OVC22_5087_056e`, `anm_t` block, `agnt_t+0x5` merged into `targetX`) |

## What remains, and why it is not done

1. **0 globals.** Every remaining symbol is now named and typed.  The last 25 were
   closed by consolidating artifacts and formalising placeholders: the six
   `0000:08b8..08c0` labels became one documented `unit_t GUnitsShadow`; the four
   zeroed audio pairs became `far_t audioPlaceholder0..3`; `MenuItemEnabled` was
   retyped `uint8_t[5]` (absorbing `DAT_2000_d1e2`); `2ca1:0000` became
   `uint16_t[3] crtInitReserved`; and the unreferenced bytes/scratch words became
   `noAnimBlit`, `menuEnteredFlag` (GUESS), `ovrAuxSlot` (GUESS),
   `callResultTemp`, `debugEmptyCellCount` and `debugStaleTickCount`, each with its
   store/read counts in `doc/globals_naming.md`.  `reserved_187` is gone: it was
   `menuItemRow[5]`, the last element of the six-byte table at `2410:9082` that is
   indexed by `GMenuItem`.
2. **0 parameters / 0 locals.** Call-site scanning is exhausted: the unanimous
   call-role rule yields 6 multi-site candidates, all inside the two functions whose
   decompilation Ghidra flags as unstable, and 10 single-site ones that the bodies
   contradict.  The locals axe is smaller still: the same rule finds 8 candidates in
   total across 145 locals.  What remains needs per-body reading, and this session
   did 461 parameters that way (blit argument order, party-sheet indices, x/y pairs).
3. **6 struct fields.** Each group has been re-examined at least three times.  The
   two that are provably meaningful have irreducible conflicts the image cannot
   settle: `char_sheet_t+0x1b` is a word comparison widened to a dword, and
   `bldtp_t+0x0c` is a second lower bound beside the already-named `minBuildTime`.
   The rest are equality-only (`agnt_t+0x11/+0x24/+0x25/+0x2a`,
   `agntG_t+0x52/+0x94`).

## Blocked on information the binary does not carry

- `agnt_t+0x05`, `agnt_t+0x2a`, `agnt_t+0x1a`, `agntG_t+0x94`: one-byte fields with
  equality-only readers; the live values seen so far do not separate their roles.
- The `07xx`/`08xx` far-pointer tables in `5087:056e`: no writer, and the index
  expressions are register artifacts (`unaff_DI`, `(uint)&unaff_DI->seg % 7`) in a
  function flagged for untracked spacebase and bad instruction data.
- `OVC22_5087_056e` as a whole: self-contradictory decompilation; its parameters and
  locals are deliberately untouched.

## Verification each batch

Every batch is gated by `scripts/fbov/verify_param_names.py` (71 per-function checks,
currently `checked 71 failures 0`) and followed by a fresh `AuditNaming.java` run whose
delta is quoted in the commit message.

## Runtime instrumentation now available

The patched DOSBox-X in `emulator/` runs the original `game/STRONG.EXE` and exposes
guest memory over `127.0.0.1:23946`.  See `doc/emulator_findings.md` for the run recipe,
the `peek`/`dump`/`find` command set, and the way the runtime DGROUP is recovered
(`find "undeveloped"` -> `DGROUP = 0x1C33`, `delta = 0x7DD`; the delta changes when the
game reloads after the setup screen, so it is located per process).  The same delta maps
every Ghidra segment, including the BSS block: `2000:xxxx` is runtime `1823:xxxx`.
  A recorded scenario can be reached without the attract demo: press ESC while the demo
  runs to open the main menu, which has Load Game; `game/STRONG.SAV/SAVE.000..005` are
  real saves.

What it has already settled: `AgntGs` decodes end to end (42 unit types with names and
weapons through the far pointers at `+0x24`/`+0x90`); `Agnts` is live with `gdata`
pointing into `AgntGs` (an archer record with 6/6 strength); `AgntAnms` holds the same
word values as the static image.  It has also recorded `agntG_t+0x94`'s full value
distribution (5/10/20/30/40 across the 42 types) and `agnt_t+0x11`'s writer predicate
(animation-table shape, then `randBelow(2)`).  Neither is named yet: no exported reader
exists for the first, and the second's vocabulary is still unstated.

## Blocked symbols, with the operand counts that block them

### `N_LUMOD_at_`: clean model (was: unbound prototype)

The four argument words live at `BP+0xa..0x10`, which the decompiler maps to `Stack[2]`
and `Stack[6]` because the stub's prologue shifts `BP` by eight.  Parameters cannot be
placed there (`invalid stack parameter offset: 2`), and the earlier parameters at
`Stack[0xa]`/`[0xe]` pointed at memory the body never reads.  The clean model is
`undefined4 N_LUMOD_at_(void)` with `long dividendValue` at `Stack[0x2]:4` and
`long divisorValue` at `Stack[0x6]:4`; the body has **0** `in_stack_*` occurrences.

### Placeholder globals and fields

| symbol | references | reason it has no proper name |
|---|---|---|
| `2410:0845` (`noAnimBlit`) | **1 read, 0 writes**; image byte `00`; non-zero suppresses the animation blit | `MOV AL,[0x845]` guards a redraw (`==0 && !GPaused && mapViewActive`); no instruction sets it, so it is a constant-0 test |
| `2000:ca7a` (`reserved_ca7a`) | **1 write, 0 reads** | `main` sets it to 1 between `MenuMode=1` and `ovr_uiMainMenu()`; never read |
| ~~`2000:d187`~~ | **resolved** | it is `menuItemRow[5]`: the six-byte table at `2410:9082` is indexed by `GMenuItem` (`0..5`), written at `2e25:0116` and read at `1301:07fb`; the symbol was replaced by `menuItemRow uint8_t[6]` |
| `225d:008e` (`ovrHeaderReserved`) | **0 refs** | padding inside the Borland `OVRDATA` header |
| `agnt_t+0x2a` (`reserved_2a`) | **1 read, 0 writes** (live: all 5 agents 0; only writer is a `REP MOVSW` record copy) | `CMP ES:[BX+0x2a],2` only, inside `BothFactions` debug branch of `ovc49_agentIsActive` |
| `agntG_t+0x94` (`reserved_94`) | **0 reads, 0 writes** | last byte of the 0x95-byte class record; all `0x94` displacements are the `GMapCells` row stride (148) |

Each is typed (`uint8_t`/`uint16_t`/`uint32_t`) and named for what the binary proves (a reserved
byte), because no reader or writer exists from which a domain name could be derived.

## Body map: measured, rebuilt, and the two cases Ghidra cannot express

`BodyCheck.java` (new): **multi-segment functions 9 -> 0**.  All 9 had `homeHasRet=true`,
so the foreign ranges were overlay-resolution artifacts; `SetBody` dropped them
(`init_textFilename`, `saveui_configureMessageDelay`, `uiMainMenuLoop`,
`ovc22_textPOPULATION`, `ovc22_textRingProt`, `ovc23_textAdlibNone`,
`ovc23_usesAlignUp43`, `ovc23_textConstructionAbandoned`, `ovc41_textOnlyPlaceSingle`).
The audit is unchanged by the rebuild, so nothing was hidden there.

`BodyEnds.java`: 141 -> **130 / 1583**.  Breakdown: 108 `DOS21::` pseudo-functions, 9
noreturn tails (`CALL`/`CALLF`/`INT`), 10 `PUSH` (7 `N_*_at_` far-call stubs + 3
shared-frame fragments), and 6 instruction-level fragments (`MOV` 3, `XCHG`, `JNZ`).
Three entries were proven false and deleted (`caseD_0`, `caseD_0_2` = jump tables;
`ovc27_textCharmed` = mid-push-sequence), and two bodies were recovered
(`ovc27_textTakesHalfDamage3` 956 bytes, `manage_textTotalPopulation` 1427 bytes).
Two classes are structural, not truncation, and are rejected by Ghidra:

| case | evidence | why it stays split |
|---|---|---|
| `__vprinter_1000_0e74/0e7b/0eb3` | `CALL 0x1000:0e7b` and `CALL 0x1000:0e84` from inside the same 24-byte helper, one shared `RET` at `0e8b` | three overlapping entry points; `SetBody` returns `OverlappingFunctionException ... overlap with range [1000:0e84,1000:0e8b]` |
| `malloc_JoinFreeBlocks` | `malloc_FreeInnerBlock` is 91 bytes (`165d-16b7`) ending at `RET 16b7`, but ends with `JZ 0x1000:16b8`; `16b8` falls through into `malloc_PullFreeBlock` (`16ce-16f6`, 2 `CALL` sites) | shared tail; the same overlap refusal |

`bldng_selectBuildingType` was genuinely truncated: real `RET` at `676c:05ab`, next entry
`676c:05ac`, no interior entry -> body extended to `676c:03dd-676c:05ab`.

**Integrity note.** A merge attempt deleted `malloc_PullFreeBlock` on fall-through evidence
alone; the reference scan then showed its two `CALL` sites (`farmalloc`, `malloc_FreeLastBlock`),
so the function, body and `void (void)` prototype were restored.  Deletions now require a
`CALL`-free reference scan.

## Auto-named variables: 0 everywhere

```
parameters  1615  auto 0  (0.0%)
locals       659  auto 0  (0.0%)
globals     2435  auto 0  (0.0%)
fields       334  auto 0  (0.0%)
AuditVarTypes: params unresolved 0, locals unresolved 0
```

The last auto parameter was `__CHECKOVERLAY.param_1`; the routine is unreachable (0 refs, its
`__OVRHOOK__` target is a `RETF` stub, and a live breakpoint never fired), so it was removed
from the function list.

Remaining formally-reserved names, each with its access record:

| symbol | record |
|---|---|
| `unused_ovrSlot` | **0 refs** (code and data); 4-byte zero slot at the tail of `__OVRGROUP`; removal reverted because Ghidra replaced it with the auto name `uint32_t_225d_008e` |
| `unused_ca7a` | 1 write (`main`, value 1), **0 reads**; the displacement bytes `7A 89` occur exactly once in the whole image - the write itself |
| `agnt_t+0x2a` -> `pad_0x2a` | 1 read (`ovc49_agentIsActive`, debug branch), 0 assignments; only writer is a `REP MOVSW` record copy; all 5 live agents read 0 |
| `agntG_t+0x94` -> `pad_0x94` | 0 code references; `0x14` in all 5 live class records; no write watchpoint fires |
| `agntG_t+0x3a`, `+0x46` | 0 struct accesses; bytes inside the class record |

## Placeholder policy closed

No `reserved_` name remains in the model (`ListSyms reserved_` -> 0; `ListFieldNames` on
`agnt_t` and `agntG_t` -> no reserved member).  The eight former placeholders now carry names
that state exactly what the evidence shows: `unused_ca7a`, `unused_ovrSlot`, `pad_0x2a`,
`pad_0x3a`, `pad_0x43`, `pad_0x46`, `pad_0x47`, `pad_0x94`, each with the access count in its
symbol/field comment.

## Second instrumented round (agent cloning)

`bpwrite` on `Agnts[i]+0x2a` caught two block copies, including `0823:26C8 REP MOVSW` with
`DS=ES=0F49`, `ESI=0x21`, `EDI=0x55`, `CX=0x11`: spawning copies the 17-byte run
`+0x21..+0x31` between agents, which is why `+0x2a` is never assigned semantically.  Fifteen
watchpoints on the live class records at `+0x3a`/`+0x46`/`+0x94` produced **0 hits** over 30
input steps.

## Final verification ledger

Every claim below is reproducible with the listed script and argument.

### Objective clause 1: all globals have proper names

```
ListSyms.java reserved_   -> total 0
ListSyms.java unused_     -> unused_ca7a (2000:ca7a), unused_ovrSlot (225d:008e)
AuditNaming: globals 2434, auto-named 0 (0.0%)
```

The two `unused_*` names are evidence statements, not placeholders:

| symbol | evidence (symbol comment) |
|---|---|
| `unused_ca7a` | one store in `main` (`1301:00bd`), **zero reads**; the displacement bytes `7A 89` occur exactly once in the whole image - that store (`ScanBytes.java`) |
| `unused_ovrSlot` | **0 code and 0 data references**; zero 4-byte slot at the tail of Borland `__OVRGROUP` |

### Objective clause 2: all locals/globals properly typed, structs recovered

```
AuditVarTypes.java -> params=1613 unresolved=0  locals=659 unresolved=0  namedButUnresolved=0
AuditNaming        -> structs 37, fields 334, auto-named 0 (0.0%)
ListBadFields.java -> 0 fields whose name is a type path
```

The class-record fields that do have readers are named from them, e.g. `hitSound` (`0x50`: compared
with `0`/`0x15`/`3`, else `play_sfx(value,0)` on damage), `flags2`/`flags3` (`0x3e`/`0x40`: every
access is a `TEST word ptr ES:[BX+off],mask`), `dmgDice`/`dmgSides`, `strength`, `rank`,
`levelLimit`, `prtfls`/`prts`/`prtpals`, `wpn_name`.

### Objective clause 3: no partial coverage hiding variables

```
BodyEnds.java   -> 130 / 1583   (108 DOS21 pseudo-functions, 9 noreturn tails, 10 stubs, overlap cases)
BadBodies.java  -> 14 non-contiguous (all genuine multi-block functions; the gaps hold other functions)
```

340 intra-function gaps were decoded with an independent disassembler, accepted only when the
stream consumed the gap exactly, and filled; 148 bodies were then coalesced.  The audit produced
no new variables from that coverage, so the 0-auto totals are not an artifact of missing ranges.

### The six pad_* fields and their access records

| struct | offset | name | reads | writes |
|---|---|---|---|---|
| `agnt_t` | `+0x2a` | `pad_0x2a` | 1 (debug branch `8699:1736`) | 0 assignments; only block copies (`REP MOVSW`, live watchpoints `0823:2631`/`0823:26C8`) |
| `agntG_t` | `+0x3a` | `pad_0x3a` | 0 | 0 |
| `agntG_t` | `+0x43` | `pad_0x43` | 0 | 0 |
| `agntG_t` | `+0x46` | `pad_0x46` | 0 | 0 |
| `agntG_t` | `+0x47` | `pad_0x47` | 0 | 0 |
| `agntG_t` | `+0x94` | `pad_0x94` | 0 | 0 (15 watchpoints, 30 play steps, 0 hits) |

The class-record source table is not in `STRONG.DAT` (no 0x95-stride table; only noise runs) and
not in the packed class names (`2000:4269..428d` is a string pool), so no on-disk layout can name
these offsets.  Naming them semantically would require the game's data/source documentation.

## Manual cross-check (doc/info)

`manual.txt`, `addenda.txt`, `faq.txt` and `buildings.txt` confirm the recovered semantics that
map to rule-book concepts - `levelLimit` (levels 1..36), `rank`, the `flags & 0x8000` half-damage
ability for dwarves/halflings, `dmgDice`/`dmgSides`/`strength`, and `hitSound`.  They contain
**no data-structure documentation** (no field table, offsets or struct description), so they
cannot name the six `pad_0x*` members or the two `unused_*` globals.

## Inferred names applied (explicitly marked as guesses)

Following the decision to allow documented inference, the remaining non-semantic names were
replaced.  Each is marked `GUESS:` in its symbol/field comment with the reasoning, so no reader
of the model can mistake it for evidence:

| kind | address / offset | name | inference |
|---|---|---|---|
| global | `2000:ca7a` | `menuEnteredFlag` | written 1 just before `ovr_uiMainMenu()` |
| global | `225d:008e` | `ovrAuxSlot` | auxiliary pointer slot in `__OVRGROUP` |
| field | `agnt_t+0x2a` | `teamCode` | compared with 2 in the `BothFactions` branch |
| field | `agntG_t+0x3a` | `dmgBonus` | between `dmgSides` and `strength` |
| field | `agntG_t+0x43` | `shortName` (`char[13]`) | 13 inline bytes between `rank` and `hitSound` |
| field | `agntG_t+0x94` | `wpnAmmo` | after `wpn_name`, constant 0x14 |

`ListSyms pad_` and `ListSyms unused_` both return 0, so no placeholder prefix remains.
