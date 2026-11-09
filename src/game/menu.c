#pragma warn -pnt
#include "dgroup.h"
#include "bss.h"

#define ovr_OVC23_55fe_05db f_55fe_05db
#define ovr_OVC23_55fe_2b82 f_55fe_2b82
#define ovr_OVC28_6018_0251 f_6018_0251
#define ovr_blitLoadRleGfx f_317e_01b2
#define ovr_constr_36ce_3172 f_36ce_3172
#define ovr_mkp f_2d63_0000
#define ovr_play_sfx f_3a5b_0633
#define ovr_randBelow f_474a_0b26
#define ovr_say f_302d_0a1b
#define ovr_stExit f_3168_0000
#define ovr_stats_6386_00f8 f_6386_00f8
#define ovr_stop_audio f_3a5b_032e
#define ovr_stshAlloc f_474a_075a
#define ovr_stshAllocStub f_6ffe_0000
#define ovr_stshFree f_474a_0718

undefined2 __cdecl16far f_55fe_05db();
byte * __cdecl16far f_55fe_2b82();
byte * __cdecl16far f_6018_0251();
void __cdecl16far f_317e_01b2(far_t a, far_t b);
undefined2 __cdecl16far f_36ce_3172();
uint32_t __cdecl16far f_2d63_0000(unsigned a, unsigned b);
void __cdecl16far f_3a5b_0633(int a, int b);
uint16_t __cdecl16far f_474a_0b26(uint16_t n);
void __cdecl16far f_302d_0a1b(char *msg);
void __cdecl16far f_3168_0000(int n);
void __cdecl16far f_6386_00f8(void);
void __cdecl16far f_3a5b_032e(void);
far_t __cdecl16far f_474a_075a(uint32_t n);
far_t __cdecl16far f_6ffe_0000(void);
void __cdecl16far f_474a_0718(far_t h);

far_t far_from_u32(uint32_t v)
{
  far_t r;
  r.ofs = (uint16_t)v;
  r.seg = (uint16_t)(v >> 16);
  return r;
}

#define halt_baddata() do{}while(0)

#include "menubody.inc"
