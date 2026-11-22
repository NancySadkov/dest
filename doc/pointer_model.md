# Pointer and memory model

What the recovered code assumes, and what the build must therefore do.

## Established by measurement (do not re-litigate)

| fact | evidence |
|---|---|
| a plain `T *` in the recovered model is a **2-byte near pointer** | `agnt_t` = 52, `entity_t` = 55, `agntG_t` = 149, `bldtp_t` = 39 match the observed strides 0x34 / 0x37 / 0x95 / 0x27 |
| `T far *` is **4 bytes** | `far_t` is `{ uint16 ofs; uint16 seg; }`, 4 bytes |
| functions are **far** | the original's calls are far, and each module lives in its own code segment |
| `far` must be a real keyword, not a macro | `st_compat.h` used to `#define far` under the host-compiler branch, which Turbo C++ 3.0 also took because it defines `__TURBOC__`, not `__BORLANDC__`. Verified with `#ifdef far` inside the staged tree: it was TRUE, so every far pointer was silently near |
| Turbo C spells the conventions `cdecl` / `pascal`, not `__cdecl` / `__pascal` | `void __cdecl f(void);` -> "Size of '__cdecl' is unknown or zero"; `void cdecl f(void);` compiles |

## Accepted model: `-mm` (medium)

Turbo C's model letters are easy to read backwards; the truth is:

| flag | code | data | correct for us |
|---|---|---|---|
| `-ms` small | near | near | no |
| `-mc` compact | **near** | far | no - calls to other segments overflow |
| `-mm` medium | **far** | **near** | **yes** |
| `-ml` large | far | far | no |

Proof that `-mc` is wrong: its `-S` listing contains `call near ptr _printf`, and
TLINK then reports 576 "Fixup overflow" errors. Under `-mm` the same tree links
with **1** (inside the library's own floating-point printer).

The library must match the model: `-mm` uses `CM.LIB` (CC/CL/CS are the other
models). `CL.LIB` in `tools/TC30/LIB` is a 44-byte error message, not a library;
the working libraries come from `tools/BC30/LIB`.

## Data placement: DGROUP vs per-module far data

The original image's memory blocks are named after the modules that produced them
(`ProjectInfo.java`):

```
195d_DATA_entity.c  22,896     1539_DATA_game1    6,048
1ef4_DATA_stash.c   10,336     17f8_DATA_game4    5,712
1726_DATA_agent.c    3,360     1703_DATA_audio.c    560
224a_DATA_mice.c       304     225d_OVRDATA_        272
```

So most data is **not** in DGROUP. Flattening it into `_DATA` is what produced
"Segment _DATA exceeds 64K": 76,158 bytes against a 64 KB limit.

Turbo C++ 3.0 accepts far *data objects* (`int far x;` compiles; only `__far` is
rejected) and emits them into `<module>_DATA` of class `FAR_DATA` - the same
mechanism. `scripts/fix_far_data.py` + `scripts/model/far_data.tsv` therefore
declare the 25 bulk tables `far`, which moves 46,436 bytes out of `_DATA`.

Do not replace this with `MK_FP` macros: redefining a symbol as a pointer changes
`sizeof`, address-of and assignment semantics at every site, and an earlier
attempt broke 211 sites.

## Overlay entries

`ovr_<name>` is a Borland VROOMM overlay entry; the body is an `INT 3Fh` stub that
jumps to the resident routine. The recovered prototypes have no parameter lists
(the decompiler could not recover their arguments), so calling the target
directly is rejected ("Too few parameters") and a C forwarding function would have
to invent the argument list. `scripts/gen_ovr_thunks.py` emits real thunks:

```
    extrn _blitRaw:far
OVRT_TEXT segment byte public 'CODE'
_blitRaw_thunk_public ...
_blitRaw proc far
    jmp _blitRaw
_blitRaw endp
```

Two constraints, both measured:

* `extrn` must be declared **before** the segment, otherwise TASM assembles the
  jump as *near* and TLINK reports "Fixup overflow".
* TASM truncates symbols at 31 characters, so thunk symbols are truncated the
  same way; two different long names that truncate to the same symbol cannot both
  be defined and are reported instead.
