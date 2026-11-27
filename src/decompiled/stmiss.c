/* Strings the original DGROUP carries and the rebuilt image was missing
   (diff_dgroup --why reported them as absent).  Recovered from
   audit/dgroup_2410.bin.  Packed into one blob with an offset table, like
   s_txtFileNames, so the section-5 "char X[] = ..." class is not inflated and
   DGROUP stays below 64 KB. */
#include "recovered.h"

/* The blob that used to sit here was a duplicate: every string it held is declared at its own
   offset (diff_dgroup matches them at delta 0), and the array itself lived at DGROUP:0xb0c0, past
   the end of the original's initialised image.  Removed; the declarations below stay. */

/* s_absentOfs removed: unreferenced, and its indices shift as entries migrate. */

/* Moved out of GLOB.OBJ's head so that DGROUP:0x94 is the original's s__2410_0094.
   The audit puts GMiceDS/GMiceSS/GMiceSP in the mouse module's code segment
   (138e:0102/0104/0106), not in DGROUP, and `__DATA` here is the one-byte symbol that
   mangles to ___DATA - not the DGROUP pointer `_DATA`, which lives at 0x00.  They are
   ordinary globals only this tree addresses, so their position is functionally neutral and
   stmiss.c is the last object on the link line. */
undefined GMiceDS = 0x00;
undefined GMiceSS = 0x00;
undefined GMiceSP = 0x00;
undefined __DATA = 0x10;
