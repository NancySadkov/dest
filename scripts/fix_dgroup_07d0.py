"""Close the DGROUP gaps at 0x7d0 and 0x7ec.

diff_dgroup.py: -4 at s_midi_error (0x7d6), -9 at BattleDelay (0x7f6).

Image (PeekBytes 2410:07d0):

  07d0  6  MusDrvSeg (word) followed by 4 unnamed bytes (00 00 00 00)
  07d6 12  "Midi error\\r"        (already correct)
  07e2  1  animBranchCode ...
  07ec 10  mouseSaveRect4 = { 12, 7, 222, 150, 0xA000 }  (a brect_t)
  07f6  2  BattleDelay

The export had MusDrvSeg as a lone word and mouseSaveRect4 as a single
`undefined` initialised with 0x0C (the first word of the rect).
"""
import io

P = "src/decompiled/st_globals4.c"
t = io.open(P, encoding="latin-1").read()

old = "uint16_t MusDrvSeg = 0x0000;\n"
new = ("uint16_t MusDrvSeg = 0x0000;\n"
       "/* GUESS: 0x7d2, four unnamed bytes after MusDrvSeg; emitted so the\n"
       "   addresses after 0x7d6 stay exact. */\n"
       "uint8_t musDrvExtra[4] = { 0x00, 0x00, 0x00, 0x00 };\n")
if old not in t:
    raise SystemExit("MusDrvSeg anchor not found")
t = t.replace(old, new, 1)

old2 = "undefined mouseSaveRect4 = 0x0C;"
new2 = ("/* 07ec: a mouse save rectangle (10-byte brect_t) */\n"
        "brect_t mouseSaveRect4 = { 12, 7, 222, 150, 0xA000 };")
if old2 not in t:
    raise SystemExit("mouseSaveRect4 anchor not found")
t = t.replace(old2, new2, 1)

io.open(P, "w", encoding="latin-1", newline="\n").write(t)
print("st_globals4.c: musDrvExtra[4] + mouseSaveRect4 as brect_t")

H = "src/decompiled/st_globals.h"
h = io.open(H, encoding="latin-1").read()
if "musDrvExtra" not in h:
    h = h.replace("extern uint16_t MusDrvSeg;",
                  "extern uint16_t MusDrvSeg;\nextern uint8_t musDrvExtra[4];", 1)
    h = h.replace("extern undefined mouseSaveRect4;", "extern brect_t mouseSaveRect4;", 1)
    io.open(H, "w", encoding="latin-1", newline="\n").write(h)
    print("st_globals.h: declarations updated")
