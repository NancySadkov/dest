# Quirks of recovering Stronghold functions

Practical notes for turning an `asm db` body in `src/ov_<seg>.c` into C that
the VROOMM verifier accepts.  The target is Turbo C++ 3.0, large model,
`-ml -1 -G -O`.

## 1. Acceptance rule

A function is accepted when its compiled bytes match the original overlay
bytes **except for direct call/jump operands**.  Those operands are copied
from the original image because they encode the original segment addresses.

The verifier (`scripts/fbov/vroomm_subst.py`) refuses any other difference.
When the function is already byte-exact the staged `STRONG.EXE` stays
byte-identical; that is the expected parity result, not a no-op failure.

## 2. Source conventions

- `src/ov_<seg>.c` contains one function per original symbol, named
  `f_<seg>_<offset>`.
- A function's size is the next function's offset (or the overlay `codesz`
  for the last one).
- `__cdecl16far` is a compatibility macro that expands to nothing.  The
  large model makes ordinary functions far (`retf`); `__cdecl16far` does not
  change calling convention.
- `far_t` is `{ uint16_t ofs; uint16_t seg; }`.
- `MK_FP(seg, ofs)` is a project macro:
  `((void far *)(((uint32_t)(seg) << 16) | (uint16_t)(ofs)))`.
- Named DGROUP globals come from `doc/dgroup_map.csv`; use the name rather
  than a raw offset when possible.  Addresses in another segment (0x280,
  0x68, 0x50, 0x40 BIOS data, 0) must use `MK_FP`.

## 3. The recovery loop

1. Disassemble the original function (see §9) and identify arguments,
   return value, globals and called functions.
2. Write a candidate in a scratch `.c` with the same name and a prototype
   for anything it calls.
3. Compile with the TC30 flags below and compare with
   `scripts/fbov/ov_compare.py` or a batch helper.
4. If the candidate calls functions defined in the same module, or touches
   DGROUP, test it in the **real module** before trusting a scratch result
   (§5, §6).
5. Only after a PASS, put the body into `src/`.
6. Re-run `vroomm_verify_linked.py` for that module and refresh
   `doc/vroomm_accepted.md` (`vroomm_manifest.py`).
7. Re-run the rebuilt EXE occasionally; the hash must remain
   `AEBDE62F…` for accepted byte-exact functions.

Compile command used everywhere:

```text
D:\BIN\TCC.EXE -ml -1 -G -O -ID:\INCLUDE -IC:\ -LD:\LIB -w- -c module.c
```

`-w-` suppresses warnings but **not errors**.

## 4. Compiler/codegen quirks

### 4.1 Instruction encodings

TASM-inline-asm and the original compiler often pick different but equivalent
encodings.  These are the ones that repeatedly showed up:

| Instruction | Original | TCC inline asm |
|---|---|---|
| `mov bx, ax` | `8B D8` | `89 C3` |
| `mov ax, bx` | `8B C3` | `89 D8` |
| `add dx, ax` | `03 D0` | `01 C2` |
| `xor ax, ax` | `33 C0` | `31 C0` |
| `xor bx, bx` | `33 DB` | `31 DB` |
| `xor cx, cx` | `33 C9` | `31 C9` |
| `xor ah, ah` | `32 E4` | `30 E4` |

If a whole function otherwise matches and only these bytes differ, emit the
exact bytes with `asm db` and keep a comment:

```c
asm db 33h, 0C0h        /* xor ax, ax */
```

This is still accepted recovered C; the verifier only cares about bytes.

### 4.2 `asm push/pop es` and SI/DI save wrappers

Two related traps:

- Inline `asm push es` was observed to assemble as `push di` in this
  toolchain.  Use `asm db 06h` / `asm db 07h` for `push es` / `pop es`.
- Mentioning `si` or `di` in inline asm (`lds si, ...`, `mov si, ...`,
  `les di, ...`, `push di`) can make the compiler wrap the whole function in
  `push si; push di` / `pop di; pop si`, adding bytes the original does not
  have.  Encode those instructions with `asm db` instead:

```c
asm db 0C5h, 76h, 06h        /* lds si, [bp+6] */
asm db 8Bh, 7Eh, 0Ch        /* mov di, [bp+0ch] */
```

The same applies to `rep movsw` / `rep stosw` if the compiler decides to save
SI/DI; using `asm db` for the loads and keeping `asm rep movsw` usually works.

### 4.3 Argument types and stack offsets

- A function with two `unsigned char` parameters gets them at
  `[bp+6]`, `[bp+8]` (each promoted to a word), not `[bp+6]`, `[bp+7]`.
- A function with one 16-bit parameter and two byte extraction points uses
  `[bp+6]`, `[bp+7]` (the high byte of the word).
- `char` parameters can push only `AL` (no `mov ah,0`).  `unsigned char`
  parameters often force `mov ah,0` / zero-extension.  If the original pushes
  bytes without clearing AH, declare the parameter **and** the callee
  prototype as `char`, not `unsigned char`.
- A function returning `char` sets only `AL`; `unsigned char`/`int` may set
  the whole `AX`.  Match the original’s `mov al,...` vs `mov ax,...`.
- A 4-byte `far_t` return is in `DX:AX`.  Returning a far pointer
  (`void far *`) is often friendlier than returning `far_t`: `far_t` can
  make TC allocate stack locals and use `leave` (`c9`).

### 4.4 Same-segment far calls

The original compiler often emits a far call to a function in the same
overlay segment as:

```text
push cs
call near
```

Whereas a scratch file that only has a prototype emits a direct far call
(`9A`).  In the real module, with the callee defined in the same file, TC
usually reproduces the `push cs; call near` form.  **Do not reject a
candidate based only on a scratch-file call mismatch**; test it in module
context first.

### 4.5 Callee signatures of still-`asm db` functions

When a new C function calls an existing `asm db` function, the old function
usually still says `(void)`.  Update its definition to the real arity, with
**named** parameters (Borland rejects unnamed parameters in definitions):

```c
void __cdecl16far f_3a5b_026f(unsigned a)
{
  asm db ...
}
```

The body does not change and the bytes stay identical; only the prototype
information changes.  Return type matters too: using the result of a
`void` function is a compile error, so change it to `int`, `unsigned`, or
`char` as appropriate.

### 4.6 Switch jump tables

TC emits switch tables as segment-relative code offsets.  A standalone OMF
object preserves the original internal layout, so those entries match.  A
linked harness can shift the module layout and perturb table entries; that is
why the verifier prefers the standalone object and only uses the linked
image for DGROUP offsets.

### 4.7 Loops and hand-optimized routines

Simple C loops often compile to a different shape than the original:

- `loop` (`E2 rel8`) vs `dec/jnz`;
- `lodsb`/`stosw`/`movsw` with `DS:SI`/`ES:DI` vs the compiler’s `ES:BX`
  addressing;
- byte-at-a-time carry chains (`add dl,bh; adc dh,0`) for a 16-bit sum.

When the whole routine is built around such an idiom, keep the `asm db`
body.  The compiler will not reproduce it from ordinary C without large
`asm` blocks, and a partially matching body is not accepted.

## 5. Standalone vs linked verification

- **Standalone** (`--obj`) is best: it preserves the original internal
  layout, so switch tables and intra-segment offsets are right.
- **Linked** (`--linked-exe/--linked-map`) resolves DGROUP-relative
  immediates (e.g. `push offset GSaveFileName`).  It needs the harness
  `dglink.obj` plus a per-module object.
- The verifier tries standalone first and only falls back to linked.  Use
  `vroomm_verify_linked.py --src-dir <dir>` to test a candidate module
  without touching `src/`.
- A linked harness can fail if the module’s DGROUP contribution pushes the
  harness group over 64 KiB (seen with `ov_6ffe`) or if a stub duplicates a
  symbol defined by the module.  In that case the verifier falls back to the
  standalone object.
- `--wait` is the DOS build timeout.  Large modules need more: `ov_6ffe.c`
  is 167 KB and needs about 60 seconds; 20–25 seconds is enough for most.

## 6. Data and segment references

- DGROUP offsets live in `doc/dgroup_map.csv`.  Examples:
  - `0x07AC` `MusRunning`
  - `0x0898A` `TextBlitCycle`
  - `0x08BAE`/`0x08BAF` `DAT_2000_ccae`/`ccaf`
  - `0x06601` `GStrangeTable` (`far_t[98]`)
- Several routines access a **mirror in segment 0x280** (e.g.
  `es:[0x7144]`, `es:[0x899c]`, `es:[0x8a01]`).  These are not the DGROUP
  symbols even when the offset matches; use `MK_FP(0x280, ...)`.
- Segment `0x40` is the BIOS data area (keyboard buffer etc.).
- Far tables in other segments (0x68, 0x50) must be accessed through a far
  pointer, not a near array.

## 7. DOSBox/tooling notes

- Always kill DOSBox before patching `tmp/vroomm/STRONG.EXE`; otherwise the
  file is locked.
- `run_dosbox.py` is headless (`SDL_VIDEODRIVER=dummy`).  It terminates the
  emulator after `--wait`, or keeps it alive with `--keep`.
- TCC diagnostics go to the DOS text screen.  The debug server can dump the
  text buffer:

```text
dump B8000 4000 C:\...\tmp\text.bin
```

  Decode it as 80×25 `(char, attr)` pairs.  The `shot` command’s text-mode
  rendering can be garbled; the raw buffer is reliable.
- The harness patches `f_00e0_002a`, `f_0000_06f8`, `f_0150_*` etc. into
  `scripts/fbov/stubs.c`.  If a module references a new external symbol, add
  a stub; if a stub duplicates a symbol the module defines, the link fails.

## 8. Checklist for a new function

1. Find the original bytes and disassemble.
2. Decide the signature from the `[bp+...]` accesses:
   - two bytes at 6/8 → two words/chars;
   - bytes at 6/7/9/8 → one or two 16-bit arguments being split;
   - `les bx,[bp+6]` → far pointer.
3. Write the candidate with correct return type (`void`, `char`,
   `unsigned char`, `int`, `unsigned`, `void far *`).
4. Compile in a scratch object and compare.
5. If it calls same-module functions or uses DGROUP, copy the real module
   to a temp directory, replace the body, and run the verifier with
   `--src-dir`.
6. If it passes, apply it to `src/`, run the module verifier, and refresh
   the manifest.
7. If it does not, prefer restoring the original `asm db` block over leaving
   a non-matching C body in the tree.

## 9. Useful commands

```text
# compare one function in a scratch object
python scripts/fbov/ov_compare.py --obj tmp/ovbuild/TRY.OBJ \
    --name c_name --overlay-seg 2d63 --ofs 0x1C8 --size 116

# dump a function body from an object
python scripts/fbov/objdump_fn.py tmp/ovbuild/TRY.OBJ c_name 64

# verify a module from its real source
python scripts/fbov/vroomm_verify_linked.py 2d63:ov_2d63

# verify a candidate module source without touching src/
python scripts/fbov/vroomm_verify_linked.py 2d63:ov_2d63 \
    --src-dir tmp/cand --wait 25

# verify every overlay module and refresh the manifest
python scripts/fbov/vroomm_sweep.py --wait 20

# rebuild only the manifest from a log
python scripts/fbov/vroomm_manifest.py --log tmp/verify_all.log
```

`vroomm_subst.py --len` is decimal-only; convert hex sizes first.

## 10. What is still hard

- Palette loops built around `out dx, al`, `lodsb`, `loop`.
- Hand-written `rep movs`/`rep stos` helpers where TC chooses `ES:BX`.
- Functions that clean arguments with `pop cx` instead of `add sp, n`
  (the original compiler’s choice; hard to force from C).
- Switch-heavy functions whose jump table shifts in a linked harness.
- Large functions where a single differing byte is hidden among thousands;
  always bisect with the verifier’s `DIFF offset` output.
