# `uiMainMenuLoop` recovery notes (`4528:14B1`)

The Ghidra export in `reference/decompiled_baseline/ovc16_saveui.c` is **not**
reliable for this function.  Its own header contains:

```text
WARNING: Instruction at (ram,0x0004b811) overlaps instruction at (ram,0x0004b810)
WARNING: Control flow encountered bad instruction data
```

The switch jump table lives immediately after the function's `retf` at
`0x1AD6`, and Ghidra followed it as code.  As a result the tail of the
decompiled function is a different routine (file I/O, `stExit`, unit
creation).  `src/game/menubody.inc` is therefore marked compile-only.

## Real layout

Function: `4528:14B1 .. 4528:1AD5`, `retf` at `1AD5`.
Jump table: nine words at `4528:1AD6`:

| result | target | menu item |
|--------|--------|-----------|
| 0 | `1A71` | cancel / Begin Play |
| 1 | `15BA` | `New Game` |
| 2 | `1615` | `Save Game` |
| 3 | `189B` | `Load Game` |
| 4 | `193F` | `Delete Game` |
| 5 | `1A39` | `Quit Game` |
| 6 | `1A60` | `Message Delay` |
| 7 | `1A6A` | `Great Achievements` |
| 8 | `1A71` | `Begin Play` |

`uiMenu` returns `item_index + 1`; 0 means cancel.  The menu has eight far
pointers copied from `GMenuStrings` (DGROUP `0x26B7`).  Item 1 is cleared when
`SaveAuto == 0`; item 7 is cleared unless `SaveAuto != 0` and
`DAT_2000_ca90 == 0`.

## Stack frame

| offset | use |
|--------|-----|
| `bp-0x32` | `char *menu[8]` (32 bytes, copied from `GMenuStrings`) |
| `bp-0x11` | `uiMenu` result byte |
| `bp-0x10` | `char *yesno[2]` (8 bytes, copied from `GYesNo`) |
| `bp-0x06/-0x04` | far pointer returned by `stshAlloc(400)` |
| `bp-0x02` | exit flag (set only by the `1A71` block) |
| `bp-0x01` | confirmation flag used by `New Game` |

The function takes no parameters (no `[bp+...]` references in the whole body).

## Case blocks

* `15BA` New Game: `saveui_4528_0533`, then if `SaveAuto != 0` and
  `DAT_2000_909b != 0` show `"Game not saved: Are you sure?"`; on confirm call
  `0130:0052` and `4528:1AE8`.
* `1615` Save Game: `saveui_4528_1288`, `4528:1175`, then the
  `"Save Game:"` / `"Name this save: ..."` / `"Name for this save: ..."`
  dialogs and the save helper calls.
* `189B` Load Game: `"Load Game:"` dialog.
* `193F` Delete Game: `"Delete Game:"` / `"Delete %..."` dialog.
* `1A39` Quit Game: if `SaveAuto` call `0180:0025`; then `0108:0020` (exit).
* `1A60` Message Delay: `4528:1303`, `saveui_4528_0533`.
* `1A6A` Great Achievements: `0218:0025`.
* `1A71` Begin Play: if `DAT_2000_ca90 == 0` and `SaveAuto != 0`, set the
  exit flag; then fall through to the loop check.

Near helpers are ordinary `call` targets in the same overlay:
`0533`, `10A8` (`uiMenu`), `1175`, `1288`, `1303`, `144E`, `1470`, `1AE8`.

## Local data observed at runtime

At the map screen the copied `GMenuStrings` far pointers have segment
`0x1C32` (the runtime DGROUP), not the static `0x1410`, because the loader
patches the DGROUP contents too.  A recovered C version must use the symbol
values, not hard-coded `0x1410`.

## Next steps

1. Translate the loop skeleton and the nine case blocks from the disassembly.
2. Introduce the near helpers as named functions in the same overlay; their
   C bodies are separate recovery targets (`4528:0533`, `10A8`, `1175`, ...).
3. Compile and compare against the original `0x624`-byte slot; this function
   is larger than its slot only if the helper calls are expanded, so check the
   size before attempting substitution.


## Resolved

`scripts/ghidra/AddJumpTable.java` attaches the nine-word table at
`4528:1AD6` to the function as a Ghidra jump-table override (the override has
to use the `jmp` site `4528:15B5`, not the table address, because the table is
outside the function body).  Decompiling `4528:14B1` now yields:

```c
void __cdecl16far uiMainMenuLoop(void)
```

with eight case bodies in target order:

| case body target | menu result | menu item |
|---|---|---|
| `15BA` | 1 | New Game |
| `1615` | 2 | Save Game |
| `189B` | 3 | Load Game |
| `193F` | 4 | Delete Game |
| `1A39` | 5 | Quit Game |
| `1A60` | 6 | Message Delay |
| `1A6A` | 7 | Great Achievements |
| `1A71` | 0/8 | Begin Play / exit |

`src/game/menubody.inc` is now generated from that decompilation (with the
`uiMenu` result and menu-array entries restored), and `menu.c` compiles and
links with `build_game.py`.


## Validation

The compiled `uiMainMenuLoop` has **69 call instructions**, the same number
and order as the original `4528:14B1..1AD5` body.  The sequence was checked
side by side (`tmp/cmpcalls.py`); the only expected difference is that the
near helpers are declared far in the standalone fragment so it can link
against the generated stubs.
