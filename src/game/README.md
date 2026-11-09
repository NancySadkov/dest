# In-game loop C fragments

Recovered C for the main in-game loop/control functions:

| File | Original | Function |
|---|---|---|
| `key.c` | `2e25:0ADF` | `gameProcessKey` |
| `manage.c` | `4d05:0000` | management index setup |
| `screen.c` | `4d05:056E` | management screen loop |

`screen.c` includes `sbody.inc` and `key.c` includes `keybody.inc`.

Compile and link check:

```text
python scripts/fbov/build_game.py
```

Result:

```text
OK   KEY.OBJ    1926 bytes
OK   MANAGE.OBJ 420 bytes
OK   SCREEN.OBJ 4528 bytes
LINK OK game.exe 4539 bytes
```

Status: functional C, not byte-exact, and not yet linked into the byte-exact
standalone build.  The active build still uses the asm blocks, so its SHA-256
remains unchanged.

The large unit-update function (`5087:056E`) remains asm: the Ghidra source
is 123 KB with `unaff_` registers and `halt_baddata` decompiler failures.
