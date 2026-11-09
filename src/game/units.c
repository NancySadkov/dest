#include "dgroup.h"
extern far_t far_t_ARRAY_2410_26f7[];

/* DGROUP 0x4234: array of 0xc-byte building records.  Ghidra rendered the
   base as (char *)"build\\clebath2.lbm" + 0xc; the disassembly uses the
   constant es:[bx+0x4234], i.e. DGROUP offset 0x4234. */
#define BLD_RECORDS ((uint8_t *)gap_2410_2A7C + 0x17B8)

#define ovr_OVC15_4207_0e17 f_4207_0e17
#define ovr_OVC15_4207_26bc f_4207_26bc
#define ovr_OVC23_55fe_0487 f_55fe_0487
#define ovr_OVC23_55fe_3450 f_55fe_3450
#define ovr_OVC25_5b66_1b48 f_5b66_1b48
#define ovr_OVC41_6a8f_002e f_6a8f_002e
#define ovr_attact_3f0b_0585 f_3f0b_0585
#define ovr_attact_3f0b_2303 f_3f0b_2303
#define ovr_constr_36ce_1db4 f_36ce_1db4
#define ovr_driver_2d63_0a67 f_2d63_0a67
#define ovr_fmVsprintf f_474a_0953
#define ovr_inputUpdate f_302d_072b
#define ovr_manage_4d05_1b1d f_4d05_1b1d
#define ovr_play_sfx f_3a5b_0633
#define ovr_randBelow f_474a_0b26
#define ovr_say f_302d_0a1b
#define ovr_uiNotify f_302d_0a41
#define ovr_unit_6616_00d8 f_6616_00d8

void __cdecl16far f_4207_0e17();
char * __cdecl16far f_4207_26bc();
undefined1 __cdecl16far f_55fe_0487();
uint __cdecl16far f_55fe_3450();
void __cdecl16far f_5b66_1b48();
void __cdecl16far f_6a8f_002e();
int __cdecl16far f_3f0b_0585();
void __cdecl16far f_3f0b_2303();
void __cdecl16far f_36ce_1db4();
void __cdecl16far f_2d63_0a67();
char * __cdecl16far f_474a_0953();
uint16_t __cdecl16far f_302d_072b(unsigned long d);
byte __cdecl16far f_4d05_1b1d();
void __cdecl16far f_3a5b_0633();
uint16_t __cdecl16far f_474a_0b26();
void __cdecl16far f_302d_0a1b();
void __cdecl16far f_302d_0a41();
void __cdecl16far f_6616_00d8();

#include "ubody.inc"
