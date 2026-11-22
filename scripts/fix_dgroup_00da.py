"""Close the DGROUP gaps at 0x0da and 0x161.

diff_dgroup.py reports -10 at MouseX (0xe4) and -1 at GCharLevelsInc (0x163).
The image shows:

  d8     00                          bigcompFrame
  d9     00                          TextBlitFlag
  da..e3 86 00 93 00 A0 00 AD 00 BA 00   a 5-word table, NO references
  161    00 00                       timePassing (a word, not a byte)
  163    00                          GCharLevelsInc

RefsToAddrs: 2410:00da -> 0 references (dead data), 2410:0161 -> 3 references
(main, draw_usesPrintf, attact_usesUpdSeason), so timePassing is really a word.

Fixes:
  * emit the dead 10-byte table so the addresses after it stay exact,
  * declare timePassing as uint16_t (its two uses compare/store 0/1, so the
    behaviour is unchanged).
"""
import io

P = "src/decompiled/st_globals4.c"
t = io.open(P, encoding="latin-1").read()

old = "undefined1 TextBlitFlag = 0x00;\n"
new = ("undefined1 TextBlitFlag = 0x00;\n"
       "/* GUESS: 0x0da, 5 words with no references in the image; emitted so the\n"
       "   addresses after it (MouseX at 0x0e4) stay exact. */\n"
       "uint16_t textBlitTable[5] = { 0x0086, 0x0093, 0x00A0, 0x00AD, 0x00BA };\n")
if old not in t:
    raise SystemExit("TextBlitFlag anchor not found")
t = t.replace(old, new, 1)

if "undefined1 timePassing = 0x00;" not in t:
    raise SystemExit("timePassing anchor not found")
t = t.replace("undefined1 timePassing = 0x00;",
              "/* 0161: a 2-byte flag (three code references, word sized) */\n"
              "uint16_t timePassing = 0x0000;", 1)

io.open(P, "w", encoding="latin-1", newline="\n").write(t)
print("st_globals4.c: textBlitTable[5] added, timePassing is uint16_t")

H = "src/decompiled/st_globals.h"
h = io.open(H, encoding="latin-1").read()
if "textBlitTable" not in h:
    h = h.replace("extern undefined1 TextBlitFlag;",
                  "extern undefined1 TextBlitFlag;\nextern uint16_t textBlitTable[5];", 1)
    h = h.replace("extern undefined1 timePassing;", "extern uint16_t timePassing;", 1)
    io.open(H, "w", encoding="latin-1", newline="\n").write(h)
    print("st_globals.h: declarations updated")
