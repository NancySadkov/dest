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

## In-game loop C status

The active init path (`main`, `f_3381_0579`) is C.  The large init modules
are in `src/init/` and compile/link.

The byte-exact build still uses asm blocks for the in-game loop.  Recovered
functional C fragments are in `src/game/`:

- `gameProcessKey` (`2e25:0ADF`),
- management index setup (`4d05:0000`),
- management screen loop (`4d05:056E`).

They compile and link via `scripts/fbov/build_game.py` (`game.exe` 4,539
bytes with generated stubs).

The remaining large loop pieces still resist C recovery:

- `5087:056E` unit update: 123 KB Ghidra source with `unaff_` registers and
  `halt_baddata` failures.
- `ovc02_draw.c`: compiler table limit exceeded in `draw_2e25_025a`.
- `uiMainMenuLoop`: Ghidra stack/unaff artifacts.
