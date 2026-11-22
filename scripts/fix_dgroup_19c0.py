"""Close the remaining 152 bytes before s_Chop_Down and the -7 at 0x1d11.

diff_dgroup: delta changes by -152 at s_Chop_Down (0x1cec) and by -7 at
s_undeveloped_land (0x1d11).

Image (PeekBytes 2410:19c0, 2410:1af2, 2410:1d09):

  19c0 25  "%s: increases unit size."
  19d9 29  "%s: enhances building speed."
  1af2 45  "%s: enhances training for entire stronghold."   (already present)
  1b20 20  "%s: creates income."
  1b33 29  "%s: produces food in winter."
  1b50 29  "%s: creates gambling income."
  1b6d 20  "%s: creates income."                            (a second copy)
  1d09  8  sfxXOffsets = { 0x21, 0x51, 0x81, 0xB1 }          (four words)

25 + 29 + 20 + 29 + 29 + 20 = 152, which is exactly the missing amount.
`sfxXOffsets` was a single `undefined` byte; the image has four words.
"""
import io
import re

P = "src/decompiled/st_globals5.c"
t = io.open(P, encoding="latin-1").read()

anchor = 'char s__s__produces_rings__2410_19f6[] = "%s: produces rings of protection.";\n'
if anchor not in t:
    raise SystemExit("produces_rings anchor not found")
t = t.replace(anchor,
              '/* 19c0/19d9: two more description strings */\n'
              'char s_s_inc_unit_size_2410_19c0[] = "%s: increases unit size.";\n'
              'char s_s_inc_bldg_speed_2410_19d9[] = "%s: enhances building speed.";\n'
              + anchor, 1)

anchor2 = 'char s__s__enhances_traini_2410_1af2[] = "%s: enhances training for entire stronghold.";\n'
if anchor2 not in t:
    raise SystemExit("enhances_traini anchor not found")
t = t.replace(anchor2, anchor2 +
              '/* 1b20..1b6d: income and winter-food strings */\n'
              'char s_s_creates_income_2410_1b20[] = "%s: creates income.";\n'
              'char s_s_food_in_winter_2410_1b33[] = "%s: produces food in winter.";\n'
              'char s_s_gambling_income_2410_1b50[] = "%s: creates gambling income.";\n'
              'char s_s_creates_income_2410_1b6d[] = "%s: creates income.";\n', 1)

if "undefined sfxXOffsets = 0x21;" not in t:
    raise SystemExit("sfxXOffsets anchor not found")
t = t.replace("undefined sfxXOffsets = 0x21;",
              "/* 1d09: four sfx x offsets */\n"
              "uint16_t sfxXOffsets[4] = { 0x21, 0x51, 0x81, 0xB1 };", 1)

io.open(P, "w", encoding="latin-1", newline="\n").write(t)
print("st_globals5.c: 6 strings + sfxXOffsets[4]")

H = "src/decompiled/st_globals.h"
h = io.open(H, encoding="latin-1").read()
names = ["s_s_inc_unit_size_2410_19c0", "s_s_inc_bldg_speed_2410_19d9",
         "s_s_creates_income_2410_1b20", "s_s_food_in_winter_2410_1b33",
         "s_s_gambling_income_2410_1b50", "s_s_creates_income_2410_1b6d"]
add = "".join("extern char %s[];\n" % n for n in names)
if names[0] not in h:
    h = h.replace("extern char s__s__produces_rings__2410_19f6[];",
                  add + "extern char s__s__produces_rings__2410_19f6[];", 1)
    h = h.replace("extern undefined sfxXOffsets;", "extern uint16_t sfxXOffsets[4];", 1)
    io.open(H, "w", encoding="latin-1", newline="\n").write(h)
    print("st_globals.h: declarations updated")
