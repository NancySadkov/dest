"""Close the DGROUP gaps at 0x732 and 0x745.

diff_dgroup.py: -10 at cornerShadeBias (0x73c) and -5 at rowBandOrigin (0x74b).
The image (PeekBytes 2410:0728) shows:

  0728 10  bandOrigin       4E 49 47 45 43 41 40 3F 3E 3D   (already correct)
  0732 10  unnamed table    10 0C 06 04 02 01 01 01 01 01
  073c  6  cornerShadeBias  0D 0A 05 03 02 01               (already correct)
  0742  2  SmoothPrev
  0744  1  seasonGroupBase
  0745  6  shadeTable       10 0C 06 04 02 01
  074b 10  rowBandOrigin    1F 1C 19 16 10 0C 06 04 02 01   (already correct)

The export dropped the 10-byte table at 0x732 and declared `shadeTable` as a
single `undefined` byte instead of 6.
"""
import io

P = "src/decompiled/st_globals4.c"
t = io.open(P, encoding="latin-1").read()

old = "uint8_t cornerShadeBias[6] = { 0xD, 0xA, 0x5, 0x3, 0x2, 0x1 };"
new = ("/* GUESS: 0x732, a ten-byte shade ramp with no symbol of its own;\n"
       "   emitted so cornerShadeBias and everything after stay at the original\n"
       "   addresses. */\n"
       "uint8_t bandShadeTable[10] = { 0x10, 0x0C, 0x06, 0x04, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01 };\n"
       + old)
if old not in t:
    raise SystemExit("cornerShadeBias anchor not found")
t = t.replace(old, new, 1)

if "undefined shadeTable = 0x10;" not in t:
    raise SystemExit("shadeTable anchor not found")
t = t.replace("undefined shadeTable = 0x10;",
              "/* 0745: six shade bytes */\nuint8_t shadeTable[6] = { 0x10, 0x0C, 0x06, 0x04, 0x02, 0x01 };", 1)

io.open(P, "w", encoding="latin-1", newline="\n").write(t)
print("st_globals4.c: bandShadeTable[10] + shadeTable[6]")

H = "src/decompiled/st_globals.h"
h = io.open(H, encoding="latin-1").read()
if "bandShadeTable" not in h:
    h = h.replace("extern uint8_t cornerShadeBias[6];",
                  "extern uint8_t bandShadeTable[10];\nextern uint8_t cornerShadeBias[6];", 1)
    h = h.replace("extern undefined shadeTable;", "extern uint8_t shadeTable[6];", 1)
    io.open(H, "w", encoding="latin-1", newline="\n").write(h)
    print("st_globals.h: declarations updated")
