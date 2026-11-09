# Ghidra string-address artifacts

Ghidra's decompiler sometimes prints an **integer constant** as a pointer into
a string, e.g.

```c
else if ((char *)key == (char *)"mason's hall" + 7) { ... }
```

That looks like a data-segment reference, but it is only an artifact: the
constant `0x2300` happens to fall inside the bytes of `"mason's hall"`, which
starts at DGROUP offset `0x22F9`, so `0x22F9 + 7 == 0x2300`.

The same rendering also appears when the constant is the **DGROUP segment
value** `0x2410`; that is numerically `"puppetmaker" + 3` (`0x240D + 3`), so
Ghidra prints the segment as a string pointer.

## Verified key constants

`gameProcessKey` (`2E25:0ADF`) compares the scan code read from the keyboard
against plain integers.  Every string expression below is the same integer.

| Ghidra text                        | string offset | constant |
|------------------------------------|---------------|----------|
| `"marble.lbm" + 5`                 | `0x3208`      | `0x320D` |
| `"halfling abode" + 7`             | `0x1F0C`      | `0x1F13` |
| `"main castle" + 1`                | `0x20FF`      | `0x2100` |
| `"manned corner wall" + 0x0B`      | `0x21F5`      | `0x2200` |
| `"mason's hall" + 7`               | `0x22F9`      | `0x2300` |
| `"arena" + 4`                      | `0x23FC`      | `0x2400` |
| `"dagger"`                         | `0x24FA`      | `0x2500` |
| `"wood golem" + 6`                 | `0x25FA`      | `0x2600` |
| `"wall2.lbm" + 2`                  | `0x2BFE`      | `0x2C00` |
| `"magelop2.xmi" + 0x0B`            | `0x2DF5`      | `0x2E00` |
| `"strong4.lbm" + 4`                | `0x31FC`      | `0x3200` |

The original disassembly contains only the integer compares:

```text
0AED  cmp si, 0x320d
0B21  cmp si, 0x1f13
...
0C5F  cmp si, 0x2100
0C72  cmp si, 0x2200
0C80  cmp si, 0x2300
0CB2  cmp si, 0x2400
0CBF  cmp si, 0x2500
0CCC  cmp si, 0x2600
0CF9  cmp si, 0x2c00
0D06  cmp si, 0x2e00
0D13  cmp si, 0x3000
0D25  cmp si, 0x3200
```

The old C produced a completely different dispatch (compiled constants `5`,
`0x12`, `0x33`, `0x49`, ...), so this was not a cosmetic issue.

## Other artifacts in the in-game sources

### `OVC40_69c8_04c6` call (`keybody.inc`)

Ghidra printed six arguments, but the original pushes only six words:

```text
push 0
push ds
push 0x027A     ; "Archduchess"
push ds
push 0x0251     ; the 40-byte "WWWW..." string
push 0
lcall ...
```

The callee reads `[bp+6]` (mode), a far pointer at `[bp+8]/[bp+0A]`, a far
pointer at `[bp+0C]/[bp+0E]`, and `[bp+10]` (mode), i.e. exactly

```c
f(int, char *, char *, int)
```

so the recovered call is

```c
ovr_OVC40_69c8_04c6(0, s_W_2410_0251, s_Archduchess_2410_027a, 0);
```

The two strings were added to `doc/dgroup_candidate.csv`, which regenerates
`src/dgroup.c`/`dgroup.h` without changing any DGROUP byte.

### `build\clebath2.lbm` (`ubody.inc`)

The string is at DGROUP `0x4228`; `+ 0x0C` is the constant `0x4234`, which is
exactly what the disassembly uses:

```text
1FBA  mov dx, 0x0c
1FBD  imul dx
1FC6  mov ax, es:[bx + 0x4234]
1FCB  or  ax, es:[bx + 0x4236]
```

So this base is real, not a string reference.  `units.c` now expresses it as
`BLD_RECORDS` (`gap_2410_2A7C + 0x17B8`).

### `manage_4d05_0519` (`sbody.inc`)

The call pushes `0x4d6c`, `ds`, `0x7d`, `0xe0` — a far `char *` plus two
integers.  The callee reads `[bp+6]/[bp+8]` as the far pointer and `[bp+0A]`,
`[bp+0C]` as the two integers, so the second string argument in the Ghidra C
was spurious.  The recovered call is `manage_4d05_0519("popularity",0x7d,0xe0)`.

## Still to re-recover

These expressions are still Ghidra artifacts and must be re-derived from the
disassembly before the fragments are trusted:

* `menubody.inc` — the whole function is based on a bad jump-table parse
  (`WARNING: Instruction at 0x4b811 overlaps 0x4b810`); its tail is a different
  routine.  Recovered only as a compile/format exercise for now.
* `sbody.inc:69` and `ubody.inc:570` — `fmVsprintf` returns a far pointer in
  `DX:AX`; Ghidra split it into an offset local plus a bogus segment constant.
* `ubody.inc:633` — the argument passed to `attact_3f0b_2303` still needs the
  push sequence checked.
* `menubody.inc:125`, `menubody.inc:198` — constants `"thief"+5` and
  `"y1 ..."+0x11` still need the real integer values.

## Regression evidence

Compile/link:

```text
OK   KEY.OBJ    1672 bytes
OK   MANAGE.OBJ 397 bytes
OK   SCREEN.OBJ 4486 bytes
OK   UNITS.OBJ  12481 bytes
OK   MENU.OBJ   3627 bytes
LINK OK game.exe 17660 bytes
```

Runtime dispatch test (real 16-bit DOS run with stubbed game calls):

```text
key=1300 ret=1300 hit=7 a=[WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW] b=[Archduchess]
key=2100 ret=2100 hit=9
key=2300 ret=2300 hit=2 seed=[The seed is ...]
key=2600 ret=2600 hit=2 seed=[Increase by 11 levels. ...]
key=2C00 ret=2C00 hit=11
key=2E00 ret=2E00 hit=10
key=3200 ret=3200 hit=4
```

Link check with the real DGROUP object: `s_W_2410_0251` is at
`DGROUP:0x02A1` and `s_Archduchess_2410_027a` at `DGROUP:0x02CA`; the linker
reserves `0x50` bytes, so both are at their true offsets `0x251` and `0x27A`.
