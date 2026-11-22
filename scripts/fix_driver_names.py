"""Restore the sound-driver filename table at 0x4867..0x4926 (191 bytes).

diff_dgroup: -191 at Cancelled (0x4926).  The image holds the 18 driver
filenames the game probes, all missing from the export:

  4867  5  ".xmi"          4876 12 "cmidpak.com"    488d 13 "sblaster.com"
  486c 10  "midpak.ad"     4882 11 "ibmsnd.com"     489a 12 "fibmbak.com"
  48a6 10  "sbpro.com"     48b0 11 "paudio.com"     48bb 10 "adlib.com"
  48c5 11  "adlibg.com"    48d0  9 "sbfm.adv"      48d9 11 "sbp2fm.adv"
  48e4 11  "sbp1fm.adv"    48ef 10 "pasfm.adv"     48f9 11 "pasopl.adv"
  4904 10  "adlib.adv"     490e 11 "adlibg.adv"    4919 13 "mt32mpu.adv"

Total 191 bytes, which is exactly the measured gap.  They sit between
s_type__d_len__ld (0x4855) and Cancelled (0x4926).
"""
import io

P = "src/decompiled/st_globals5.c"
t = io.open(P, encoding="latin-1").read()

anchor = 'char s_type__d_len__ld_2410_4855[] = "type %d len %ld \\r";\n'
if anchor not in t:
    raise SystemExit("anchor not found")

rows = [
    (0x4867, "s_dot_xmi_2410_4867", ".xmi"),
    (0x486C, "s_midpak_ad_2410_486c", "midpak.ad"),
    (0x4876, "s_cmidpak_com_2410_4876", "cmidpak.com"),
    (0x4882, "s_ibmsnd_com_2410_4882", "ibmsnd.com"),
    (0x488D, "s_sblaster_com_2410_488d", "sblaster.com"),
    (0x489A, "s_fibmbak_com_2410_489a", "fibmbak.com"),
    (0x48A6, "s_sbpro_com_2410_48a6", "sbpro.com"),
    (0x48B0, "s_paudio_com_2410_48b0", "paudio.com"),
    (0x48BB, "s_adlib_com_2410_48bb", "adlib.com"),
    (0x48C5, "s_adlibg_com_2410_48c5", "adlibg.com"),
    (0x48D0, "s_sbfm_adv_2410_48d0", "sbfm.adv"),
    (0x48D9, "s_sbp2fm_adv_2410_48d9", "sbp2fm.adv"),
    (0x48E4, "s_sbp1fm_adv_2410_48e4", "sbp1fm.adv"),
    (0x48EF, "s_pasfm_adv_2410_48ef", "pasfm.adv"),
    (0x48F9, "s_pasopl_adv_2410_48f9", "pasopl.adv"),
    (0x4904, "s_adlib_adv_2410_4904", "adlib.adv"),
    (0x490E, "s_adlibg_adv_2410_490e", "adlibg.adv"),
    (0x4919, "s_mt32mpu_adv_2410_4919", "mt32mpu.adv"),
]
SIZES = [5, 10, 12, 11, 13, 12, 10, 11, 10, 11, 9, 11, 11, 10, 11, 10, 11, 13]
total = sum(SIZES)
if total != 0x4926 - 0x4867:
    raise SystemExit("size mismatch: %d vs %d" % (total, 0x4926 - 0x4867))

block = ("/* 4867..4926: the 18 sound-driver filenames the game probes */\n"
         + "\n".join('char %s[%d] = "%s";' % (n, SIZES[i], s) for i, (_, n, s) in enumerate(rows))
         + "\n")
t = t.replace(anchor, anchor + block, 1)
io.open(P, "w", encoding="latin-1", newline="\n").write(t)
print("st_globals5.c: 18 driver filenames inserted (%d bytes)" % total)

H = "src/decompiled/st_globals.h"
h = io.open(H, encoding="latin-1").read()
decls = "".join("extern char %s[];\n" % n for _, n, _ in rows)
if rows[0][1] not in h:
    h = h.replace("extern char s_type__d_len__ld_2410_4855[];",
                  "extern char s_type__d_len__ld_2410_4855[];\n" + decls, 1)
    io.open(H, "w", encoding="latin-1", newline="\n").write(h)
    print("st_globals.h: 18 declarations added")
