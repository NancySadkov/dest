# In-game boot check

`scripts/fbov/boot_game.py` drives the source-built EXE from startup into the
in-game map screen.

Flow:

1. Boot `out/STRONG.EXE` with `STRONG.DAT`/`STRONG.FLI`.
2. Select sound option 6 (off).
3. Press Enter through the intro until the map screen.
4. Dump VGA `A0000` and detect the map screen from the minimap and bottom
   text bands.
5. Save `tmp/boot_game.png`.

Detection thresholds (320x200 mode 13h frame):

| Band | Region | Threshold |
|---|---|---|
| minimap | x 250..317, y 5..69 | brightness sum > 800000 |
| map text | x 5..314, y 160..197 | brightness sum > 1500000 |

Result:

```text
IN GAME at step 3 (mini=888145 text=1928449)
saved tmp/boot_game.png
```

The captured frame shows the map with the minimap and the message:

```text
A new land lies before you. Choose carefully where you settle.
```

## Functional C integration

`scripts/fbov/build_functional_exe.py` substitutes the C
`f_4d05_0000` into the overlay, pads it to the original 129 bytes, rewrites
the runtime DGROUP/unit-array segment operands and neutralises the stale
FBOV fixup sites.

Run:

```text
python scripts/fbov/build_functional_exe.py
python scripts/fbov/boot_game.py --exe out/STRONG_FUNC.EXE --mem-out tmp/func_mem.bin
```

With the synthesized clock/date setup (`date 01-01-1993`, `time 00:00:00`,
`synchronize time = false`, `cycles = fixed 20000`), the functional EXE boots
into the same map screen.  The full deterministic harness
(`scripts/fbov/boot_game_det.py`) also resets the timer fields and advances an
exact instruction count; original and functional C EXE then produce
**identical DGROUP state (0 differing bytes)**.  Regression check:
`python scripts/fbov/check_determinism.py --exe out/STRONG.EXE`.
See `doc/memory_state.md`.

## In-game loop C status

The active init path (`main`, `f_3381_0579`) is C.  The large init modules
are in `src/init/` and compile/link.

The byte-exact build still uses asm blocks for the in-game loop.  Recovered
functional C fragments are in `src/game/`:

- `gameProcessKey` (`2e25:0ADF`),
- management index setup (`4d05:0000`),
- management screen loop (`4d05:056E`),
- unit update loop `upd_units_5087_1d7d` (`5087:1D7D`),
- main menu loop `uiMainMenuLoop` (`4528:14B1`).

They compile and link via `scripts/fbov/build_game.py` (`game.exe` 18,022
bytes with generated stubs).

The remaining large loop pieces still resist C recovery:

- `5087:056E` helper: 123 KB Ghidra source with `unaff_` registers and
  `halt_baddata` failures.
- `ovc02_draw.c`: compiler table limit exceeded in `draw_2e25_025a`.
- `uiMainMenuLoop`: Ghidra stack/unaff artifacts.
