"""Restore the four description strings at 0x1a55..0x1ad5.

Same block as fix_bldg_desc_strings.py: the image has

  1a55 33  "%s: populates a remote location."
  1a76 27  "%s: provides gold storage."
  1a91 31  "%s: enables claiming of trees."
  1ad5 29  "%s: provides for food trade."

each matching its symbol size exactly (text + NUL), and they sit between
s__s__creates_mirrors (0x1a18) and s__s__repairs_buildings (0x1ab0).
"""
import io

P = "src/decompiled/st_globals5.c"
t = io.open(P, encoding="latin-1").read()

anchor = 'char s__s__repairs_buildin_2410_1ab0[] = "%s: repairs buildings automatically.";\n'
if anchor not in t:
    # fall back: any declaration with that prefix
    import re
    m = re.search(r'char s__s__repairs_buildin[^;]*;\n', t)
    if not m:
        raise SystemExit("repairs_buildin anchor not found")
    anchor = m.group(0)

block = ('/* 1a55..1ad5: four more building description strings */\n'
         'char s_s_remote_place_2410_1a55[] = "%s: populates a remote location.";\n'
         'char s_s_gold_storage_2410_1a76[] = "%s: provides gold storage.";\n'
         'char s_s_claim_trees_2410_1a91[] = "%s: enables claiming of trees.";\n'
         'char s_s_food_trade_2410_1ad5[] = "%s: provides for food trade.";\n')
t = t.replace(anchor, block + anchor, 1)

io.open(P, "w", encoding="latin-1", newline="\n").write(t)
print("st_globals5.c: 4 more description strings restored")

H = "src/decompiled/st_globals.h"
h = io.open(H, encoding="latin-1").read()
names = ["s_s_remote_place_2410_1a55", "s_s_gold_storage_2410_1a76",
         "s_s_claim_trees_2410_1a91", "s_s_food_trade_2410_1ad5"]
add = "".join("extern char %s[];\n" % n for n in names)
if names[0] not in h:
    h = h.replace("extern char s__s__repairs_buildin_2410_1ab0[];",
                  add + "extern char s__s__repairs_buildin_2410_1ab0[];", 1)
    io.open(H, "w", encoding="latin-1", newline="\n").write(h)
    print("st_globals.h: declarations added")
