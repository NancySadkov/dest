/* BSS globals used by the recovered in-game code.
 *
 * The authoritative names live in the Ghidra project (symbols at 2000:xxxx,
 * annotated by scripts/ghidra/AnnotateBss.java).  The recovered C still sees
 * the older DAT_2000_ names, so map them here.
 */
#ifndef ST_GAME_BSS_H
#define ST_GAME_BSS_H

#define GUnits           DAT_2000_ca95  /* far ptr, unit array, stride 9 */
#define GUnitCount       DAT_2000_ca99  /* valid unit slots, starts at 0xF8 */
#define GLeaderCount     DAT_2000_d1e6  /* leaders/entities iterated per turn */
#define GMenuGfxOfs      DAT_2000_d19f  /* menu/title RLE bitmap offset */
#define GMenuGfxSeg      DAT_2000_d1a1  /* menu/title RLE bitmap segment */
#define GPopulationLo    DAT_2000_ca91  /* low word of the population counter */
#define GPopulationHi    DAT_2000_ca93  /* high word of the population counter */
#define GUnitGrid        DAT_2000_cb0d  /* 0x4560-byte unit grid, 0x78-byte rows */
#define GMapFlags        DAT_2000_cb09  /* 0x4560-byte map flags, 0x128-byte rows */
#define GGameInProgress  DAT_2000_ca90  /* non-zero while a game is running */

#endif
