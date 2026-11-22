"""Close the DGROUP gaps at 0x846..0x88d (records declared as scalars).

diff_dgroup.py: -17 at mouseSaveRect1 (0x858), -9 at Highlight1 (0x862),
-11 at SquareRecX (0x86e), -15 at SquareRecCount (0x881).

Image (PeekBytes 2410:0846 and 2410:0850):

  0846 18  flashPaletteEf {3F,00,00,3F,3F,3F,20,20,20,3F,3F,3F,3F,28,00,3F,30,00}
  0858 10  mouseSaveRect1 = {211,175,223,178,0xA000}   (a brect_t)
  0862  1  Highlight1 (the scalar the code uses)
  0863  1  a second byte, also labelled Highlight1 in the original
  0864 10  "(%d, %d)" - a second copy of that format string
  086e  2  SquareRecX
  0870 17  SquareRecY (byte table)
  0881  2  SquareRecCount
  0883  2  SquareRecIndex (scalar in the code) + 8 unnamed bytes
  088d 10  mouseSaveRect3 = {223,159,226,196,0xA000}

Highlight1, SquareRecIndex and the rects keep their scalar identity where the
code uses them as scalars; only the byte counts and the missing copies are added.
"""
import io

P = "src/decompiled/st_globals4.c"
t = io.open(P, encoding="latin-1").read()

subs = [
    ("undefined flashPaletteEf = 0x3F;",
     "/* 0846: eighteen palette bytes */\n"
     "uint8_t flashPaletteEf[18] = { 0x3F, 0x00, 0x00, 0x3F, 0x3F, 0x3F, 0x20, 0x20, 0x20,\n"
     "    0x3F, 0x3F, 0x3F, 0x3F, 0x28, 0x00, 0x3F, 0x30, 0x00 };"),
    ("undefined mouseSaveRect1 = 0xD3;",
     "/* 0858: a mouse save rectangle (10-byte brect_t) */\n"
     "brect_t mouseSaveRect1 = { 211, 175, 223, 178, 0xA000 };"),
    ("undefined1 Highlight1 = 0xFF;",
     "undefined1 Highlight1 = 0xFF;\n"
     "/* GUESS: 0x863, a second Highlight1-labelled byte in the original; only\n"
     "   the scalar is used by the code. */\n"
     "uint8_t highlight1Extra = 0xFF;\n"
     "/* 0864: a second \"(%d, %d)\" copy */\n"
     'char s_d_d_2410_0864[] = "(%d, %d)";'),
    ("uint16_t SquareRecY = 0x0000;",
     "/* 0870: seventeen byte counters */\n"
     "uint8_t SquareRecY[17] = { 0x00, 0x00, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x0E,\n"
     "    0x0E, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00 };"),
    ("uint16_t SquareRecIndex = 0x0000;",
     "uint16_t SquareRecIndex = 0x0000;\n"
     "/* GUESS: 0x885, eight unnamed bytes after the index scalar */\n"
     "uint8_t squareRecIndexExtra[8] = { 0x00, 0x01, 0x00, 0xFF, 0xFF, 0x00, 0x01, 0x00 };"),
    ("undefined mouseSaveRect3 = 0xDF;",
     "/* 088d: a mouse save rectangle (10-byte brect_t) */\n"
     "brect_t mouseSaveRect3 = { 223, 159, 226, 196, 0xA000 };"),
]
for a, b in subs:
    if a not in t:
        raise SystemExit("anchor not found: " + a)
    t = t.replace(a, b, 1)

io.open(P, "w", encoding="latin-1", newline="\n").write(t)
print("st_globals4.c: 6 declarations sized/typed")

H = "src/decompiled/st_globals.h"
h = io.open(H, encoding="latin-1").read()
add = ("extern uint8_t flashPaletteEf[18];\n"
       "extern brect_t mouseSaveRect1;\n"
       "extern uint8_t highlight1Extra;\n"
       "extern char s_d_d_2410_0864[];\n"
       "extern uint8_t SquareRecY[17];\n"
       "extern uint8_t squareRecIndexExtra[8];\n"
       "extern brect_t mouseSaveRect3;\n")
for old, new in (("extern undefined flashPaletteEf;", "extern uint8_t flashPaletteEf[18];"),
                 ("extern undefined mouseSaveRect1;", "extern brect_t mouseSaveRect1;"),
                 ("extern uint16_t SquareRecY;", "extern uint8_t SquareRecY[17];"),
                 ("extern undefined mouseSaveRect3;", "extern brect_t mouseSaveRect3;")):
    h = h.replace(old, new, 1)
if "highlight1Extra" not in h:
    h = h.replace("extern undefined1 Highlight1;",
                  "extern undefined1 Highlight1;\n" + add, 1)
io.open(H, "w", encoding="latin-1", newline="\n").write(h)
print("st_globals.h: declarations updated")
