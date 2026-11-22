"""Close the DGROUP gaps at 0x43f and 0x472.

diff_dgroup.py reports the layout one byte short at BlitRects (0x440) and 33
bytes short at MiceFlag (0x4b8).  The image shows:

  0x43d  00 14     __stklen = 0x1400
  0x43f  00        one unnamed padding byte (BlitRects is word aligned)
  0x440  50 bytes  BlitRects[5] (already present, byte exact)
  0x472  32 bytes  an unreferenced 16-word table
  0x492  ...       s_error_27

RefsToAddrs reports zero references to 2410:0472, so the table is dead data in
the original image; the values are the image's bytes.  It is emitted only so the
DGROUP addresses after it stay exact.
"""
import io

P = "src/decompiled/st_globals4.c"
t = io.open(P, encoding="latin-1").read()

old = "uint16_t __stklen = 0x1400;\n"
new = ("uint16_t __stklen = 0x1400;\n"
       "/* GUESS: unnamed padding byte at 0x43f (word-aligns BlitRects). */\n"
       "uint8_t __stklenPad = 0x00;\n")
if old not in t:
    raise SystemExit("__stklen anchor not found")
t = t.replace(old, new, 1)

anchor = ("char s_error_27__2410_0492[] = \"error(27) \\r\";\n")
table = ("/* GUESS: 0x472, 16 words with no references in the image; emitted so the\n"
         "   addresses of s_error_27 and everything after stay exact. */\n"
         "uint16_t lineMaskTable[16] = { 0x0001, 0x0101, 0x0821, 0x1111, 0x2249, 0x4545,\n"
         "    0x2A55, 0x5555, 0xAAD5, 0xB5B5, 0xDB6D, 0xDDDD, 0xDEF7, 0xEFEF, 0xFEFF, 0xFFFF };\n")
if anchor not in t:
    raise SystemExit("s_error_27 anchor not found")
t = t.replace(anchor, table + anchor, 1)
io.open(P, "w", encoding="latin-1", newline="\n").write(t)
print("st_globals4.c: 0x43f pad + 0x472 table added")

H = "src/decompiled/st_globals.h"
h = io.open(H, encoding="latin-1").read()
add = ("extern uint8_t __stklenPad;\n"
       "extern uint16_t lineMaskTable[16];\n")
if "lineMaskTable" not in h:
    h = h.replace("extern uint16_t __stklen;", "extern uint16_t __stklen;\n" + add, 1)
    if "extern uint16_t __stklen;" not in h:
        # the declaration may be written differently; append near BlitRects
        h = h.replace("extern brect_t BlitRects[5];", add + "extern brect_t BlitRects[5];", 1)
    io.open(H, "w", encoding="latin-1", newline="\n").write(h)
    print("st_globals.h: declarations added")
