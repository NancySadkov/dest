/* Strings the original DGROUP carries and the rebuilt image was missing
   (diff_dgroup --why reported them as absent).  Recovered from
   audit/dgroup_2410.bin.  Packed into one blob with an offset table, like
   s_txtFileNames, so the section-5 "char X[] = ..." class is not inflated and
   DGROUP stays below 64 KB. */
#include "recovered.h"

char s_absentBlob[] =
  "Error %d %d.  (Give Cathryn BOTH numbers.)\x0a""\0" "%d \x0d""\0"
  "%d \x0d""\0" "fighters' residence\0"
  "Peaceful\0" "anim\\2rdrag0.lbm\0"
  "build\\rock01.lbm\0" "anim\\1fi1m.lbm\0"
  "anim\\1cl1m.lbm\0" "anim\\2fi1m.lbm\0"
  "build\\mine01.lbm\0" "build\\cletem01.lbm\0"
  "anim\\nubats.lbm\0" "anim\\1fi1f.lbm\0"
  "anim\\2mansc0.lbm\0" "anim\\1el1m.lbm\0"
  "anim\\1el1f.lbm\0" "anim\\1el2m.lbm\0"
  "anim\\1el2f.lbm\0" "anim\\1el3m.lbm\0"
  "anim\\1el3f.lbm\0" "anim\\1ma1m.lbm\0"
  "anim\\1ma1f.lbm\0" "anim\\1ma2m.lbm\0"
  "anim\\1ma2f.lbm\0" "anim\\1ma3m.lbm\0"
  "anim\\1ma3f.lbm\0" "anim\\2ma1m.lbm\0"
  "anim\\2ma2m.lbm\0" "anim\\2ma3m.lbm\0"
  "build\\gencas01.lbm\0" "build\\gencas03.lbm\0"
  "anim\\2medus0.lbm\0" "anim\\1cl1f.lbm\0"
  "anim\\1fi2f.lbm\0" "anim\\1fi3f.lbm\0"
  "anim\\1fi2m.lbm\0" "anim\\1fi3m.lbm\0"
  "anim\\2fi2m.lbm\0" "anim\\2fi3m.lbm\0"
  "build\\gentow01.lbm\0" "build\\genmkt01.lbm\0"
  "build\\gengra01.lbm\0" "build\\gentow02.lbm\0"
  "build\\gengra02.lbm\0" "anim\\1th1m.lbm\0"
  "anim\\1th1f.lbm\0" "anim\\1th2m.lbm\0"
  "anim\\1th2f.lbm\0" "anim\\1th3m.lbm\0"
  "anim\\1th3f.lbm\0" "anim\\2th3m.lbm\0"
  "anim\\2th1m.lbm\0" "anim\\2th2m.lbm\0"
  "anim\\1cl2m.lbm\0" "anim\\1cl2f.lbm\0"
  "anim\\1cl3m.lbm\0" "anim\\1cl3f.lbm\0"
  "anim\\2cl1m.lbm\0" "anim\\2cl2m.lbm\0"
  "anim\\2cl3m.lbm\0" "anim\\1dw1m.lbm\0"
  "anim\\1dw1f.lbm\0" "anim\\1dw2m.lbm\0"
  "anim\\1dw2f.lbm\0" "anim\\1ha1m.lbm\0"
  "anim\\1ha1f.lbm\0" "anim\\1ha2m.lbm\0"
  "anim\\1ha2f.lbm\0" "portrait\\sp06.lbm\0"
  "anim\\2wights0.lbm\0" "anim\\2bdrag0.lbm\0"
  "anim\\2bdragt0.lbm\0" "anim\\2pworm0.lbm\0"
  "build\\figcas01.lbm\0" "build\\figcas02.lbm\0"
  "build\\figres01.lbm\0" "build\\figres02.lbm\0"
  "build\\dwfres01.lbm\0" "build\\dwfres02.lbm\0"
  "build\\hafcas01.lbm\0" "build\\hafcas02.lbm\0"
  "build\\hafhal01.lbm\0" "build\\hafhal02.lbm\0"
  "anim\\2sgian0.lbm\0" "anim\\2troll0.lbm\0"
  "anim\\2griff0.lbm\0" "anim\\2fgian0.lbm\0"
  "anim\\2phoen0.lbm\0" "anim\\2minot0.lbm\0"
  "anim\\2cockas0.lbm\0" "anim\\2vamps0.lbm\0"
  "build\\geninn01.lbm\0" "build\\hafres01.lbm\0"
  "build\\cleres01.lbm\0" "build\\cleres02.lbm\0"
  "build\\magres01.lbm\0" "build\\magres02.lbm\0"
  "portrait\\sp07.lbm\0" "portrait\\sp08.lbm\0"
  "portrait\\sp09.lbm\0" "portrait\\sp10.lbm\0"
  "portrait\\sp11.lbm\0" "portrait\\sp12.lbm\0"
  "portrait\\sp13.lbm\0" "portrait\\sp14.lbm\0"
  "portrait\\sp15.lbm\0" "portrait\\sp16.lbm\0"
  "portrait\\sp17.lbm\0" "portrait\\sp18.lbm\0"
  "portrait\\sp19.lbm\0" "portrait\\sp20.lbm\0"
  "portrait\\sp21.lbm\0" "portrait\\sp22.lbm\0"
  "build\\elfres01.lbm\0" "portrait\\sp23.lbm\0"
  "portrait\\sp24.lbm\0" "portrait\\sp25.lbm\0"
  "portrait\\sp26.lbm\0" "portrait\\sp27.lbm\0"
  "portrait\\sp28.lbm\0" "portrait\\sp29.lbm\0"
  "portrait\\sp30.lbm\0" "portrait\\sp31.lbm\0"
  "portrait\\sp32.lbm\0" "portrait\\sp33.lbm\0"
  "portrait\\sp34.lbm\0" "portrait\\sp35.lbm\0"
  "build\\gencas04.lbm\0" "build\\gencas02.lbm\0"
  "build\\hafres02.lbm\0" "build\\cletem02.lbm\0"
  "anim\\2mndark.lbm\0" "build\\elfres02.lbm\0"
  "build\\thfgld01.lbm\0" "build\\thfgld02.lbm\0"
  "build\\thfres01.lbm\0" "build\\thfres02.lbm\0"
  "portrait\\sp36.lbm\0" "portrait\\sp37.lbm\0"
  "portrait\\sp38.lbm\0" "portrait\\sp39.lbm\0"
  "portrait\\sp40.lbm\0" "portrait\\sp41.lbm\0"
  "portrait\\sp42.lbm\0" "portrait\\sp43.lbm\0"
  "build\\magunv01.lbm\0" "build\\magunv02.lbm\0"
  "portrait\\sp00.lbm\0" "build\\elfgar01.lbm\0"
  "build\\elfgar02.lbm\0" "build\\elfwood1.lbm\0"
  "build\\elfwood2.lbm\0" "build\\genbnk01.lbm\0"
  "build\\genbnk02.lbm\0" "build\\magjwl01.lbm\0"
  "build\\magjwl02.lbm\0" "build\\thfgls01.lbm\0"
  "build\\thfgls02.lbm\0" "build\\gencmp01.lbm\0"
  "build\\gencmp02.lbm\0" "build\\hafbak01.lbm\0"
  "build\\hafbak02.lbm\0" "build\\clescr01.lbm\0"
  "build\\clescr02.lbm\0" "build\\magmil01.lbm\0"
  "build\\magmil02.lbm\0" "build\\geninn02.lbm\0"
  "build\\thfgam01.lbm\0" "build\\gentrad1.lbm\0"
  "build\\gentrad2.lbm\0" "build\\elfarro1.lbm\0"
  "build\\elfarro2.lbm\0" "build\\clebath1.lbm\0"
  "has destroyed all enemies.  Congratulations!\0" "Select an alignment.\0"
  "Select the character's name.\0" "Keep %s.\0"
  "strong.sav\\game.cfg\0" "strong.sav\\game.cfg\0"
  "strong.sav\\strong.$$$\0" "strong.sav\\strong.$$$\0"
  "Path to write game data:\x0a""\0" "Sound (1. PC Speaker  2. Sound Blaster  3. Pro Audio Spectrum\x0a""\0"
  "Sound Blaster (1. Original  2.  Pro Type 2  3. Pro Type 1):\0" "Pro Audio Spectrum (1. Plus  2. Spectrum 16):\0"
  "Adlib (1. Original  2. Gold):\0" "Sound Effects (1. PC Speaker  2. Sound Blaster  3. Pro Audio Spectrum\x0a""\0"
  "               4. Adlib       5. None):\0" "Sound Blaster (1. Original  2.  Pro):\0"
  "Pro Audio Spectrum (1. Plus  2. Spectrum 16):\0" "Adlib (1. Original  2. Gold):\0"
  "Sound IRQ is %c (1. Don't change  2. IRQ 2  3. IRQ 5\x0a""\0" "Largest executable program size is only %s bytes.\x0a""\0"
  "Stronghold requires 585,000 bytes.\x0a""\0" "Bad heap @%x S%x Z%x P%x  \x0d""\0"
  "L. to %s\0" "%d %s%s loyal to %s found. Left click: set triangles. R: ready. U: unassign. H: home. Right click: abort.\0"
  "Priorities adjusted for %d %s%s.\0" "%d %s%s unassigned.\0"
  "%d %s%s readied.\0" "%d %s%s homed.\0"
  "Region selection aborted.\0" "Building is now %s.  Select type of building.\0"
  "The season has changed to %s.\0" "of nobility. You will truly be the master\0"
  "adventure.\0" "of adventure and glory.\0"
  "%s, for valor in battle.\0" "%s, for city management.\0"
  "kill 4\x0d""\0" "Enemy %s.\0"
  "%d \x0d""\0" "getcache %d  SIZESTASH %d  \x0d""\0"
  "%s: Owned by %s. Active party is %s the %s.\0" "%s: Costs %d gold of income. Replaces broken weapons.\0"
  "%s: Costs %d gold of income. Forges +%d weapons.\0" "%s: Costs %d gold of income. Improves armor.\0"
  "%s: Costs %d gold of income. Improves armor class by -%d.\0" "%s: Costs %d gold of income. Replaces broken bows.\0"
  "%s: Costs %d gold of income. Creates +%d bow and arrows.\0" "%s: Costs %d gold. Increases unit size of five units by %d.\0"
  "%s: Costs %d gold. Increases building speed by %d0%%.\0" "%s: Costs %d gold. Enhances training by %d%%.\0"
  "%s: Costs %d gold. Produces mirrors for medusae combat. Increases tower range by 5.\0" "%s: Costs %d gold. Attracts new units to this location.\0"
  "%s: Costs %d gold. Provides %u units of gold storage.\0" "%s: Costs %d gold. Claim trees automatically.\0"
  "%s: Costs %d gold. Repairs buildings at season changes.\0" "%s: Trades %d food for gold. Total trade is %d food.\0"
  "%s: Provides housing for %d %s.\0" "%s: %s %d gold. Feeds %d %s.\0"
  "%s: %s %d gold. provides housing for %d %s and feeds %d %s.\0" "%s: %s %d gold. Provides housing for %d %s.\0"
  "%s: %s %d gold.\0" " Salvage value %d gold.\0"
  " Repair costs %d gp.\0" " Upgrade costs %d gp.\0"
  "%s will be salvaged for %d gold. Are you sure?\0" "%s is being filled.\0"
  "%s salvaged for %d gold.\0" "%s is demolished.\0"
  "%s does not have enough gold.\0" "%s upgraded.\0"
  "bolt12.fli\0" "save.999\0"
  "%d \x0d""\0" "print scanf : floating point formats not linked\x0d""\x0a""\0";

uint16_t s_absentOfs[248] = {
  0, 44, 49, 54, 74, 83, 100, 117,
  132, 147, 162, 179, 198, 214, 229, 246,
  261, 276, 291, 306, 321, 336, 351, 366,
  381, 396, 411, 426, 441, 456, 471, 490,
  509, 526, 541, 556, 571, 586, 601, 616,
  631, 650, 669, 688, 707, 726, 741, 756,
  771, 786, 801, 816, 831, 846, 861, 876,
  891, 906, 921, 936, 951, 966, 981, 996,
  1011, 1026, 1041, 1056, 1071, 1086, 1104, 1122,
  1139, 1157, 1174, 1193, 1212, 1231, 1250, 1269,
  1288, 1307, 1326, 1345, 1364, 1381, 1398, 1415,
  1432, 1449, 1466, 1484, 1501, 1520, 1539, 1558,
  1577, 1596, 1615, 1633, 1651, 1669, 1687, 1705,
  1723, 1741, 1759, 1777, 1795, 1813, 1831, 1849,
  1867, 1885, 1903, 1922, 1940, 1958, 1976, 1994,
  2012, 2030, 2048, 2066, 2084, 2102, 2120, 2138,
  2156, 2175, 2194, 2213, 2232, 2249, 2268, 2287,
  2306, 2325, 2344, 2362, 2380, 2398, 2416, 2434,
  2452, 2470, 2488, 2507, 2526, 2544, 2563, 2582,
  2601, 2620, 2639, 2658, 2677, 2696, 2715, 2734,
  2753, 2772, 2791, 2810, 2829, 2848, 2867, 2886,
  2905, 2924, 2943, 2962, 2981, 3000, 3019, 3064,
  3085, 3114, 3123, 3143, 3163, 3185, 3207, 3233,
  3296, 3356, 3402, 3432, 3503, 3543, 3581, 3627,
  3657, 3711, 3762, 3798, 3826, 3835, 3941, 3974,
  3994, 4011, 4026, 4052, 4098, 4128, 4170, 4181,
  4205, 4230, 4255, 4263, 4273, 4278, 4307, 4351,
  4405, 4454, 4499, 4557, 4608, 4665, 4725, 4779,
  4825, 4909, 4965, 5019, 5065, 5121, 5174, 5206,
  5235, 5295, 5339, 5355, 5379, 5400, 5422, 5469,
  5489, 5514, 5532, 5562, 5575, 5586, 5595, 5600,
};
