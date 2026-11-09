/*
 * Runtime test for the recovered gameProcessKey (2E25:0ADF).
 *
 * This is a standalone DOS test, not part of the game build.  It links the
 * real src/game/key.c against tiny stubs for the game/OS calls and feeds one
 * scan code at a time, so the dispatch constants and the data references are
 * exercised by an actual 16-bit run.
 */
#include <stdarg.h>
#include "dgroup.h"

int printf(const char *fmt,...);
int vsprintf(char *buf,const char *fmt,va_list ap);
char *strncpy(char *d,const char *s,unsigned n);

/* The subset of DGROUP used by gameProcessKey. */
unsigned char AudioAssetsReady1;
unsigned char AudioAssetsReady2;
bool GDebug;
undefined2 VideoFlag_2410_0167;
undefined2 GfxRndSeed;
undefined2 GfxRndSeed2;
undefined2 GSeed;
undefined2 DAT_2410_26e1;
bool DebugVerbose;
undefined1 GCharLevelsInc;
undefined1 DAT_2410_0164;
undefined1 DAT_2410_0165;
undefined1 GTimeHi;
brect_t BlitRects[5];
char s_W_2410_0251[41] = "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW";
char s_Archduchess_2410_027a[12] = "Archduchess";

uint16_t testkey;

extern uint16_t __cdecl16far gameProcessKey(void);

static int hit;
static char said[256];
static char seeded[128];
static char arg1[64], arg2[64];

uint16_t __cdecl16far f_2d63_0030(void) { return testkey; }
void __cdecl16far f_302d_0a1b(char *m) { hit = 2; strncpy(said, m, 255); said[255]=0; }
void __cdecl16far f_3338_0000(brect_t *br) { (void)br; }
void __cdecl16far f_3338_0256(brect_t *br) { (void)br; }
void __cdecl16far f_3a5b_032e(void) { hit = 1; }
char * __cdecl16far f_474a_09df(char *buf, char *fmt, ...)
{
  va_list ap; va_start(ap, fmt); vsprintf(buf, fmt, ap); va_end(ap);
  strncpy(seeded, buf, 127); seeded[127]=0;
  hit = 3; return buf;
}
uint16_t __cdecl16far f_474a_0b26(uint16_t n) { (void)n; return 0; }
void __cdecl16far f_4b0a_010c(void) { hit = 4; }
void __cdecl16far f_619c_0a5e(int a, int b) { (void)a; (void)b; hit = 5; }
uint __cdecl16far f_67e7_004d(undefined1 a) { (void)a; hit = 6; return 0; }
char __cdecl16far f_69c8_04c6(int a, char *b, char *c, int d)
{
  (void)a; (void)d; hit = 7;
  strncpy(arg1, b, 63); arg1[63]=0;
  strncpy(arg2, c, 63); arg2[63]=0;
  return 0;
}
void __cdecl16far f_6a8f_076f(void) { hit = 8; }
void __cdecl16far f_6a8f_0fc1(char a) { hit = 9; GCharLevelsInc = (unsigned char)a; }
void __cdecl16far f_6a8f_108a(void) { hit = 10; }
void __cdecl16far f_6a8f_29a0(void) { hit = 11; }
void __cdecl16far f_7e7c_0000(void) { hit = 12; }

static void run(uint16_t k)
{
  hit = 0; said[0]=0; seeded[0]=0; arg1[0]=0; arg2[0]=0;
  testkey = k;
  {
    uint16_t r = gameProcessKey();
    printf("key=%04X ret=%04X hit=%d seed=[%s] a=[%s] b=[%s]\n",
           k, r, hit, seeded, arg1, arg2);
  }
}

void main(void)
{
  GDebug = 1;
  GSeed = 0x5678; DAT_2410_26e1 = 0x1234;
  printf("keytest start\n");
  run(0x320D); run(0x1F13);
  run(0x1000); run(0x1300); run(0x1500); run(0x1900);
  run(0x1F00); run(0x2000); run(0x2100); run(0x2200);
  run(0x2300); run(0x2400); run(0x2500); run(0x2600);
  run(0x2C00); run(0x2E00); run(0x3000); run(0x3200);
  run(0x9999);
  printf("keytest done\n");
}
