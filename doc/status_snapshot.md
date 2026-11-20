# Recovery status snapshot

Measured by `scripts/ghidra/AuditNaming.java`; the raw output quoted here is
`tmp/auditn526/naming_summary.txt`.

## Where the model stands

```
functions                1130
  no prototype            114
  weak return type        970
  has struct-typed arg    169
parameters               1618   auto-named    9   (0.6%)
locals                    657   auto-named    0   (0.0%)
structs                    37
  struct fields           334   generated     0   (0.0%)
globals                  2435   auto-named    0   (0.0%)
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
   `reserved_187`, `reserved_0845`, `reserved_ca7a`, `ovrHeaderReserved`,
   `callResultTemp`, `debugEmptyCellCount` and `debugStaleTickCount`, each with its
   store/read counts in `doc/globals_naming.md`.
2. **9 parameters / 0 locals.** Call-site scanning is exhausted: the unanimous
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

### Unbound prototype: `N_LUMOD_at_`

`long dividend` / `long divisor` sit at `Stack[0xa]:4` / `Stack[0xe]:4`, which is the proven
ABI (`MOV AX,[BP+0xa]`/`MOV DX,[BP+0xc]`, `MOV BX,[BP+0xe]`/`MOV CX,[BP+0x10]`; return in
`DX:AX`).  The decompiler renders those four operand reads as `in_stack_00000002..08` because
its frame maps `BP+0xa` to `Stack[2]`.  Placing the parameters there is rejected:
`InvalidInputException: Variable contains invalid stack parameter offset: dividendLo offset 2`
(parameters may not sit below the return address).  The prototype storage is exact; the body
binding cannot be forced, so this is recorded rather than worked around.

### Placeholder globals and fields

| symbol | references | reason it has no proper name |
|---|---|---|
| `2410:0845` (`reserved_0845`) | **1 read, 0 writes**; image byte `00` | `MOV AL,[0x845]` guards a redraw (`==0 && !GPaused && mapViewActive`); no instruction sets it, so it is a constant-0 test |
| `2000:ca7a` (`reserved_ca7a`) | **1 write, 0 reads** | `main` sets it to 1 between `MenuMode=1` and `ovr_uiMainMenu()`; never read |
| `2000:d187` (`reserved_187`) | **0 live refs** | computed ref at `MenuItemEnabled[5]`, but every actual read is under `GMenuItem < 5`; the 5-byte table ends at `d186` |
| `225d:008e` (`ovrHeaderReserved`) | **0 refs** | padding inside the Borland `OVRDATA` header |
| `agnt_t+0x2a` (`reserved_2a`) | **1 read, 0 writes** | `CMP ES:[BX+0x2a],2` only, inside `BothFactions` debug branch of `ovc49_agentIsActive` |
| `agntG_t+0x94` (`reserved_94`) | **0 reads, 0 writes** | last byte of the 0x95-byte class record; all `0x94` displacements are the `GMapCells` row stride (148) |

Each is typed (`uint8_t`/`uint16_t`/`uint32_t`) and named for what the binary proves (a reserved
byte), because no reader or writer exists from which a domain name could be derived.
