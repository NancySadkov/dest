# Step 6: measured overlay-layout comparison (rebuilt vs original)

Everything below is counted from files in this repository; no assumptions.

## Original

`audit/functions.tsv` lists every function Ghidra recovered from `game/STRONG.EXE`
with its address, block and size.  Counting the distinct code segments (the part of
the address before `:`):

```
distinct code segments (VROOMM overlay units): 107
sum of function sizes                        : 367,822 bytes
resident image (EXE header cblp)             : 110.4 KB
```

Largest units, to show how coarse the original's units are:

```
  seg 6ffe   5 functions  30,021 bytes
  seg 5087  31 functions  20,275
  seg 81b9   4 functions  17,997
  seg 7a57   1 function   15,626
  seg 8699   9 functions  15,133
```

So Borland VROOMM happily carries 30 KB units; a unit is a *module*, not a
function, and its size is not capped near 64 KB in practice.

## Rebuilt

`scripts/link_standalone.py` splits resident objects from the rest and passes the
rest after TLINK's positional `/o`:

```
objects 63 = 12 resident + 51 overlay units
resident: CRTL MAIN MOUSE VIDEO OVR STUBS INTRINS GLOB..GLOB5
REBUILT.EXE 735,872 bytes = 129.6 KB resident + 589.1 KB overlays
```

## What the comparison says

| | original | rebuilt |
|---|---|---|
| overlay units | 107 | 51 |
| overlay code | 367,822 bytes | 603,238 bytes |
| resident | 110.4 KB | 129.6 KB |

* The rebuilt image has **fewer** units than the original, so a VROOMM unit-count
  limit cannot explain the startup abort.
* The rebuilt *code* is **1.64x** the original's.  That is the real layout
  difference: our recovered bodies still carry decompiler temporaries
  (`uVar`, `in_stack_`, CONCAT shuffles, struct copies) which the original
  compiler did not emit.
* The abort therefore is not a layout limit.  It happens before `main` for a
  one-function program as well (exit code 2 with a tiny resident `main` that
  prints nothing), so it is a property of the object mix/runtime data the
  startup sees, not of the overlay table size.

## Reproduce

```
python -c "import io,collections; ..."   # see the counting commands in the
                                         # commit that added this file
python scripts/link_standalone.py
```

The counting script for the original:

```python
import io, collections
rows = [l.split("\t") for l in io.open("audit/functions.tsv", encoding="utf-8")][1:]
seg = collections.Counter(r[0].split(":")[0] for r in rows if len(r) > 4)
print(len(seg))                                    # 107 units
print(sum(int(r[3]) for r in rows if len(r) > 4))  # 367822 bytes
```
