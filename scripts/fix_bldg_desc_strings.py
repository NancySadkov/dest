"""Restore the nine building description strings at 0x1b81..0x1cec.

diff_dgroup.py: -539 at s_Chop_Down (0x1cec).  Part of that is nine strings the
export dropped; the bytes come from PeekBytes 2410:1b81 and 2410:1cb9:

  1b81 33  "%s: enhances weapons production."
  1ba2 29  "%s: creates food and income."
  1bbf 23  "%s: enhances training."
  1bd6 20  "%s: creates arrows."
  1bea 27  "%s: provides more housing."
  1c05 33  "%s: provides housing and income."
  1c26 20  "%s: blocks passage."
  1c3a 31  "%s: allows passage over water."
  1cb9 51  "%s: blocks enemy passage. Allows friendly passage."

The first eight sit before s__s__provides_storag_2410_1c59 in the image order;
the last sits between s__s__adds_to_crop_va (0x1c88) and s_Chop_Down (0x1cec).
"""
import io

P = "src/decompiled/st_globals5.c"
t = io.open(P, encoding="latin-1").read()

anchor = 'char s__s__provides_storag_2410_1c59[] = "%s: provides storage and distribution of food.";\n'
if anchor not in t:
    raise SystemExit("provides_storag anchor not found")
block = (
    '/* 1b81..1c3a: the eight per-building description strings */\n'
    'char s_s_enh_weapons_2410_1b81[] = "%s: enhances weapons production.";\n'
    'char s_s_creates_food_2410_1ba2[] = "%s: creates food and income.";\n'
    'char s_s_enh_training_2410_1bbf[] = "%s: enhances training.";\n'
    'char s_s_creates_arrows_2410_1bd6[] = "%s: creates arrows.";\n'
    'char s_s_more_housing_2410_1bea[] = "%s: provides more housing.";\n'
    'char s_s_housing_income_2410_1c05[] = "%s: provides housing and income.";\n'
    'char s_s_blocks_passage_2410_1c26[] = "%s: blocks passage.";\n'
    'char s_s_allows_water_2410_1c3a[] = "%s: allows passage over water.";\n')
t = t.replace(anchor, block + anchor, 1)

anchor2 = 'char s__s__adds_to_crop_va_2410_1c88[] = "%s: adds to crop value and gives access to fund.";\n'
if anchor2 not in t:
    raise SystemExit("adds_to_crop anchor not found")
t = t.replace(anchor2, anchor2 +
              '/* 1cb9: the enemy-passage description */\n'
              'char s_s_blocks_enemy_pa_2410_1cb9[] = '
              '"%s: blocks enemy passage. Allows friendly passage.";\n', 1)

io.open(P, "w", encoding="latin-1", newline="\n").write(t)
print("st_globals5.c: 9 description strings restored")

H = "src/decompiled/st_globals.h"
h = io.open(H, encoding="latin-1").read()
names = ["s_s_enh_weapons_2410_1b81", "s_s_creates_food_2410_1ba2",
         "s_s_enh_training_2410_1bbf", "s_s_creates_arrows_2410_1bd6",
         "s_s_more_housing_2410_1bea", "s_s_housing_income_2410_1c05",
         "s_s_blocks_passage_2410_1c26", "s_s_allows_water_2410_1c3a",
         "s_s_blocks_enemy_pa_2410_1cb9"]
add = "".join("extern char %s[];\n" % n for n in names)
if names[0] not in h:
    h = h.replace("extern char s__s__provides_storag_2410_1c59[];", add +
                  "extern char s__s__provides_storag_2410_1c59[];", 1)
    io.open(H, "w", encoding="latin-1", newline="\n").write(h)
    print("st_globals.h: declarations added")
