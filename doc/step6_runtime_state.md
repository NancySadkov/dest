# Step 6: runtime DGROUP comparison at `main`

## How the state is captured

Both images are patched at `main`'s entry with an 18-byte stub:

```asm
mov bx,1 / mov cx,0FFFFh / mov dx,0 / mov ah,40h / int 21h / mov ax,4C00h / int 21h
```

i.e. "write all 64 KB at DS:0 to stdout and exit".  The batch redirects
`STRONG.EXE` to `DGR.BIN`, so the dump needs no file-creation call (an earlier
version that used `INT 21h AH=3Ch` hung: headless DOS raised its critical-error
dialog on the first bad path).

`tmp/dump_dgroup_stdout.py` patches both images and runs them;
`scripts/compare_runtime.py` maps each original DGROUP symbol (name + length
from `audit/dgroup_data.csv`) to its matching address in `REBUILT.MAP` (the same
matching rules as `diff_dgroup.py`) and compares the runtime bytes.

## Result

```
original dump: 61440 bytes, rebuilt dump: 65535 bytes
symbols matched: 976
identical state: 933
DIFFERENT state:  43
```

## The 43 differences classify into three groups

1. **Far pointers whose segment is the literal `0x2410`.**  Example:

   ```
   00eb GUnitDescriptions  want ...6901331c7101331c   got ...6901102471011024
   26d7 GYesNo             want 4a28331c4e28331c      got 4a2810244e281024
   ```

   The original's tables hold the load-time DGROUP segment (`0x1c33`); ours hold
   `0x2410`, the segment written in the original image file.  These initialisers
   are literals such as `(char far *)(0x24100000UL + 0x27ebUL)`, so the linker
   never relocates them - the static byte comparison passed because the *file*
   bytes match, and only the runtime state exposes the defect.

   Fix: declare those tables as `char far *` arrays initialised with the address
   of the string (`char far *GYesNo[2] = { s_yes, s_no };`), which makes BCC emit
   a normal relocation for the segment half.

2. **Startup state that legitimately differs per run**: `_StartTime` (system
   clock), `_brklvl` (heap break after the resize), `_DATA` (the CRT's own
   word).

3. A handful of remaining items still to classify (they are listed by the tool).

## Why this matters

This is the first *runtime* data-state comparison, and it shows a class of
defect the static comparison cannot see: data that is byte-identical in the file
but wrong in memory because it should have been relocated.
