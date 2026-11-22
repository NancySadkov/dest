# Step 5: ovc22_textRingProt (2,576 artifacts)

`audit/functions.tsv`: `5087:056e OVC22 ovc22_textRingProt 3168`; the recovered
C is `src/decompiled/ovc22_classes.c` lines 395-2690 (2,296 lines), the
disassembly `tmp/asm_ring.txt` (1,100 instructions, `DumpAsmNamed.java`).

## Opening block, from the disassembly

```
5087:0576  CMP byte ptr [BP+6],0xff      ; partyIndex == 0xff ?
5087:057f  MOV word ptr [BP-0x1c],0
5087:0584  MOV word ptr [BP-0x1e],0
5087:0589  MOV word ptr [BP-0x44],0
5087:058e  MOV word ptr [BP-0x20],0
5087:0593  MOV word ptr [BP-0x22],0
5087:0598  MOV word ptr [BP-0x1e],0xa
5087:059d  PUSH 6 / PUSH 0 / PUSH SS / LEA AX,[BP-0x28] / PUSH AX / CALLF _fmemset
5087:05ae  PUSH 6 / PUSH 0 / PUSH SS / LEA AX,[BP-0x2e] / PUSH AX / CALLF _fmemset
5087:05bf  PUSH 3 / PUSH 0 / GUnitDescriptions[partyIndex] + 0x9a / CALLF _fmemset
```

So the first two `_fmemset`s clear 6 bytes at `SS:[BP-0x28]` and
`SS:[BP-0x2e]`, and the third clears 3 bytes at
`GUnitDescriptions[partyIndex].ofs + 0x9a`.

## What the recovered C says instead

```c
_fmemset((void *)ZEXT24(unaff_SS),6,(uint16_t)unaff_DI);
_fmemset((void *)ZEXT24(unaff_SS),6,CONCAT11(uVar68,cVar25));
_fmemset((void *)(ulong)*(uint *)((uint)partyIndex * 4 + 2),3,CONCAT11(uVar68,cVar25));
```

Three separate defects, all visible in one call:

* the arguments are in the wrong order - `_fmemset(dest, value, count)` became
  `(dest, count, value)`, so `6` is where the fill value belongs;
* the destination is `ZEXT24(unaff_SS)` (a segment value used as a pointer)
  instead of `MK_FP(_SS, &local)`;
* the count/value come from `unaff_DI` / `CONCAT11(uVar68,cVar25)` instead of
  the immediate `6` / `0` the disassembly pushes.

## Consequence for the ratchet

Renaming `uVar`/`pVar` locals on top of expressions that are already wrong would
bake the errors in and make the later, real recovery harder to review.  This
function needs a block-by-block rewrite from `tmp/asm_ring.txt`, of which the
opening block above is the first unit; the 1,100 instructions are enough to do
it, but it is not a rename pass.
