"""Close the DGROUP gaps at 0x4b8..0x50a.

diff_dgroup.py: -20 at MiceOfsX (0x4ce), -1 at StshStrongDatHnd (0x4e4),
-9 at edgeMaskTable (0x4f2), -15 at neighbourOfsTable (0x502).

Original sizes from audit/symbols.tsv and bytes from PeekBytes 2410:04b8:

  04b8 22   MiceFlag  = word 0 followed by ten words 0,0,10,16,13,12,15,16,7,10
  04ce  8   MiceOfsX  {0,1,5,6}          (already correct)
  04d6  8   MiceOfsY  {0,15,3,5}         (already correct)
  04de  2   MiceIndex
  04e0  1   MiceUnkState
  04e1  3   s__2410_04e1  "\\r" plus two NULs
  04e4  2   StshStrongDatHnd
  04e6  2   GCrLf
  04e8 10   scaleTable       {10,12,6,4,2,1,1,1,1,1}
  04f2 16   edgeMaskTable    {3,6,0,1,5,3,1,0,0,2,3,5,2,0,6,3}
  0502  8   neighbourOfsTable{0,1,1,2,2,3,3,0}
  050a  4   GrayscalePalette (already correct)

The export had MiceFlag/scaleTable/edgeMaskTable/neighbourOfsTable as single
bytes and s__2410_04e1 as 2 bytes.  Only the byte counts change; the named
symbols keep their names so existing &symbol access still works.
"""
import io

P = "src/decompiled/st_globals4.c"
t = io.open(P, encoding="latin-1").read()

subs = [
    ("uint16_t MiceFlag = 0x0000;",
     "uint16_t MiceFlag = 0x0000;\n"
     "/* GUESS: 0x4ba, ten words with no symbol of their own; emitted so MiceOfsX\n"
     "   and everything after stay at the original addresses. */\n"
     "uint16_t miceFlagTable[10] = { 0x0000, 0x0000, 0x000A, 0x0010, 0x000D,\n"
     "    0x000C, 0x000F, 0x0010, 0x0007, 0x000A };"),
    ('char s__2410_04e1[] = "\\r";',
     '/* 04e1: 3 bytes - "\\r" plus two NULs */\nchar s__2410_04e1[3] = "\\r";'),
    ("undefined scaleTable = 0x10;",
     "/* 04e8: ten scale bytes */\nuint8_t scaleTable[10] = { 0x10, 0x0C, 0x06, 0x04, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01 };"),
    ("undefined edgeMaskTable = 0x03;",
     "/* 04f2: sixteen mask bytes */\n"
     "uint8_t edgeMaskTable[16] = { 0x03, 0x06, 0x00, 0x01, 0x05, 0x03, 0x01, 0x00,\n"
     "    0x00, 0x02, 0x03, 0x05, 0x02, 0x00, 0x06, 0x03 };"),
    ("undefined neighbourOfsTable = 0x00;",
     "/* 0502: eight neighbour offsets */\n"
     "uint8_t neighbourOfsTable[8] = { 0x00, 0x01, 0x01, 0x02, 0x02, 0x03, 0x03, 0x00 };"),
]
for a, b in subs:
    if a not in t:
        raise SystemExit("anchor not found: " + a)
    t = t.replace(a, b, 1)

io.open(P, "w", encoding="latin-1", newline="\n").write(t)
print("st_globals4.c: MiceFlag table + 4 sized declarations")

H = "src/decompiled/st_globals.h"
h = io.open(H, encoding="latin-1").read()
if "miceFlagTable" not in h:
    h = h.replace("extern uint16_t MiceFlag;",
                  "extern uint16_t MiceFlag;\nextern uint16_t miceFlagTable[10];", 1)
    h = h.replace("extern undefined scaleTable;", "extern uint8_t scaleTable[10];", 1)
    h = h.replace("extern undefined edgeMaskTable;", "extern uint8_t edgeMaskTable[16];", 1)
    h = h.replace("extern undefined neighbourOfsTable;",
                  "extern uint8_t neighbourOfsTable[8];", 1)
    io.open(H, "w", encoding="latin-1", newline="\n").write(h)
    print("st_globals.h: declarations updated")
