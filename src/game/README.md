# In-game loop C fragments

Recovered C for the main in-game loop/control functions:

| File | Original | Function |
|---|---|---|
| `key.c` | `2e25:0ADF` | `gameProcessKey` |
| `manage.c` | `4d05:0000` | management index setup |
| `screen.c` | `4d05:056E` | management screen loop |
| `units.c` | `5087:1D7D` | `upd_units_5087_1d7d` unit update loop |
| `menu.c` | `4528:14B1` | `uiMainMenuLoop` |

`screen.c` includes `sbody.inc`, `units.c` includes `ubody.inc`, `menu.c`
includes `menubody.inc`, and `key.c` includes `keybody.inc`.

Compile and link check:

```text
python scripts/fbov/build_game.py
```

Result:

```text
OK   KEY.OBJ    1926 bytes
OK   MANAGE.OBJ 397 bytes
OK   SCREEN.OBJ 4528 bytes
OK   UNITS.OBJ  12541 bytes
OK   MENU.OBJ   3627 bytes
LINK OK game.exe 18022 bytes
```

Status: functional C, not byte-exact.  `f_4d05_0000` is small enough to fit
the original 129-byte slot and is substituted by
`scripts/fbov/build_functional_exe.py`; the resulting `out/STRONG_FUNC.EXE`
boots to the map screen and matches DGROUP exactly when run through the
deterministic harness `scripts/fbov/boot_game_det.py` (0 differing bytes).
See `doc/memory_state.md`.  The other fragments are larger than their original
slots and still need an overlay-growth/relocation step before substitution.

The active byte-exact build remains unchanged (original SHA-256).

`units.c` is the main per-turn unit update loop (37 KB of C source).  The
larger `5087:056E` helper remains asm: its Ghidra source is 123 KB with
`unaff_` registers and `halt_baddata` failures.
