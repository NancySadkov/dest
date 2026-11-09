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

The in-game loop modules (`ovc02_draw`, `ovc16_saveui`, `ovc21_manage`,
`ovc22`) are still asm blocks in the byte-exact build.  The Ghidra baseline C
for them does not compile under TC30:

- `ovc02_draw.c`: compiler table limit exceeded in `draw_2e25_025a`.
- `ovc21_manage.c` / `ovc22.c`: prototype and type mismatches.

Manual byte-exact recovery of these modules is the remaining work.
