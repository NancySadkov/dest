#include "dgroup.h"

#define GGameExeP ((void far * far *)MK_FP(0x1410, 0x8976))
#define GExeArgP  ((void far * far *)MK_FP(0x1410, 0x8972))

#define DB(off) (*(undefined1 far *)MK_FP(0x1410, (off)))
#define DW(off) (*(undefined2 far *)MK_FP(0x1410, (off)))
#define A90DE ((undefined1 far *)MK_FP(0x1410, 0x90de))
#define A9082 ((undefined1 far *)MK_FP(0x1410, 0x9082))

void __cdecl16far f_12e3_0025(void);
unsigned char __cdecl16far f_13e3_0020(void);
void __cdecl16far f_1347_0020(int);
void __cdecl16far f_13d5_008e(void);
void __cdecl16far f_12f8_0020(int, int);
int  __cdecl16far f_12bb_0052(void);
void __cdecl16far f_12bb_0057(void);
void __cdecl16far f_0000_2747(char far *, int);

void __cdecl16far f_12bb_005c(void);
void __cdecl16far f_12bb_0061(void);
void __cdecl16far f_13d5_007f(int, int);
void __cdecl16far f_1400_0020(int);
void __cdecl16far f_2e25_130a(void);
void __cdecl16far f_2e25_025a(void);
void __cdecl16far f_1391_002f(void);
void __cdecl16far f_13d5_0084(void);
void __cdecl16far f_1315_0020(void);
void __cdecl16far f_1315_0039(int, int);
void __cdecl16far f_13d5_005c(char);
void __cdecl16far f_12bb_0084(int, int);
void __cdecl16far f_12bb_0043(int, int);
void __cdecl16far f_13b6_0025(char);
void __cdecl16far f_1356_0020(void);
void __cdecl16far f_1391_0052(void);
void __cdecl16far f_1391_0048(int);
void __cdecl16far f_12c4_005c(char far *, int);
unsigned char __cdecl16far f_1322_0057(void);
void __cdecl16far f_4d05_1835(void);
void __cdecl16far f_6a8f_199c(void);
void __cdecl16far f_6a8f_1847(void);
void __cdecl16far f_6a8f_04c0(int);
void __cdecl16far f_6a8f_15a0(int, int);
void __cdecl16far f_6616_0689(int);
void __cdecl16far f_7e7c_004b(int);
void __cdecl16far f_6018_007e(void);

int __cdecl16far main(int argc, char **argv)
{
  unsigned char sel;
  volatile unsigned key;

  *GGameExeP = (void far *)argv[0];
  if (argc >= 2) {
    *GExeArgP = (void far *)argv[1];
  }
  else {
    *GExeArgP = (void far *)s__2410_0094;
  }

  f_12e3_0025();                 /* 0x1301:005C */
  do {
    ;
  } while (!f_13e3_0020());      /* 0x1301:0061 */

  DB(0x4757) = 1;                /* DAT_2410_4757 */
  f_1347_0020(0);                /* 0x1301:006B */
  DB(0x4757) = 0;

  DB(0x899c) = 0;                /* GOngoingBattle */
  DB(0x899b) = 0;                /* DAT_2000_ca9b */
  DB(0x8980) = 5;                /* GMenuItem */
  DB(0x896f) = 1;                /* DAT_2000_ca6f */
  DB(0x897a) = 1;                /* DAT_2000_ca7a */

  f_13d5_008e();                 /* 0x1301:00B8 */
  f_12f8_0020(7, 0);             /* 0x1301:00BE */

  {
L_loop:
    DB(0x4e0) = 1;               /* MiceUnkState */
    key = f_12bb_0052();         /* 0x1301:00D5 */
    DW(0x430) = 0xa000;          /* TextBlitDstSeg */
    DW(0x898e) = 0x21;           /* GGameState */

    if (DB(0x438)) {
      f_0000_2747((char far *)s__d_2410_0095, DW(0x898e));
    }
    if (key == 0xffff) {
      f_12bb_0057();
    }
    DW(0x898e) = 0x16;           /* GGameState */

    if (DB(0x438)) {
      f_0000_2747((char far *)s__d_2410_0095, DW(0x898e));
    }

    switch (key) {
    case 0x0f00:
    case 0x0f09:
      do {
        if (DB(0x8980) != 0) {
          DB(0x8980)--;
        }
        else {
          DB(0x8980) = 5;
        }
      } while (DB(0x8980) != 5 && A90DE[DB(0x8980)] == 0xff);
      DB(0x896f) = 0;
      f_12bb_005c();
      f_12bb_0061();
      break;

    case 0x1c0d:
      do {
        DB(0x8980)++;
        if (DB(0x8980) >= 6) {
          DB(0x8980) = 0;
        }
      } while (DB(0x8980) != 5 && A90DE[DB(0x8980)] == 0xff);
      DB(0x896f) = 0;
      f_12bb_005c();
      f_12bb_0061();
      break;

    case 0x4800: f_13d5_007f(0, 0); break;
    case 0x4b00: f_13d5_007f(3, 0); break;
    case 0x5000: f_13d5_007f(2, 0); break;
    case 0x4d00: f_13d5_007f(1, 0); break;
    case 0x4900: f_13d5_007f(0, 1); break;
    case 0x4700: f_13d5_007f(3, 1); break;
    case 0x5100: f_13d5_007f(2, 1); break;
    case 0x4f00: f_13d5_007f(1, 1); break;

    case 0x3f00: f_7e7c_004b(0); break;
    case 0x4000: f_7e7c_004b(1); break;
    case 0x4100: f_7e7c_004b(2); break;
    case 0x4200: f_7e7c_004b(3); break;

    case 0x2247:
    case 0x2267:
      DB(0x8980) = 5;
      DB(0x896f) = 1;
      f_2e25_130a();
      f_2e25_025a();
      break;

    case 0x1950:
    case 0x1970:
      f_1391_002f();
      break;

    case 0x2f56:
    case 0x2f76:
      f_13d5_0084();
      break;

    case 0x011b:
    case 0x3b00:
      f_1315_0020();
      f_13d5_008e();
      break;

    case 0x0231:
    case 0x0332:
    case 0x0433:
    case 0x0534:
    case 0x0635:
    case 0x4b34:
    case 0x4c35:
    case 0x4f31:
    case 0x5032:
    case 0x5133:
      sel = (key & 0xf) - 1;
      if (A90DE[sel] == 0xff) {
        break;
      }
      if (DB(0x8980) == sel && DB(0x896f) == 1) {
        DB(0x896f) = 2;
      }
      else {
        DB(0x896f) = 1;
      }
      DB(0x8980) = sel;
      if (DB(0x896f) == 2) {
        f_1315_0039(DB(0x8980), 1);
      }
      f_12bb_005c();
      f_12bb_0061();
      if (DB(0x896f) != 1) {
        break;
      }
      f_13d5_005c(DB(0x8980));
      break;
      break;

    case 0x3920:
      if (!DB(0x899c) && f_1322_0057()) {
        f_12c4_005c((char far *)(gap_2410_009A + 0), 0xa000);
        break;
      }
      DB(0x0161) = 1;
      f_12c4_005c((char far *)(gap_2410_009A + 0x2e), 0xa000);
      if (DB(0x0439) == 0) {
        break;
      }
      DB(0x0439) = 0;
      f_1391_0052();
      f_1391_0048(3);
      DB(0x0439) = 1;
      f_1391_0052();
      break;
      break;

    case 0x1e41:
    case 0x1e61:
      if (DB(0x8980) > 4) {
        break;
      }
      if (!DB(0x899c)) {
        f_13d5_0084();
      }
      f_13b6_0025(DB(0x8980));
      break;
      break;

    case 0x184f:
    case 0x186f:
      if (DB(0x90ae) == 0) {
        break;
      }
      f_1356_0020();
      break;
      break;

    case 0x2e43:
    case 0x2e63:
      if (DB(0x8980) > 4) {
        break;
      }
      f_12bb_0084(0x1c, 0x0e);
      f_13d5_005c(DB(0x8980));
      DB(0x896f) = 1;
      break;
      break;

    case 0x1454:
    case 0x1474:
    case 0x332c:
      if (DB(0x8980) > 4) {
        break;
      }
      f_12bb_0084(0, 0x1c);
      f_13d5_005c(DB(0x8980));
      DB(0x896f) = 1;
      break;
      break;

    case 0x1352:
    case 0x1372:
    case 0x342e:
      if (DB(0x8980) > 4) {
        break;
      }
      f_12bb_0084(0x38, 0x1c);
      f_13d5_005c(DB(0x8980));
      DB(0x896f) = 1;
      break;
      break;

    case 0x2646:
    case 0x266c:
    case 0x3042:
    case 0x3062:
      if (DB(0x8980) > 4) {
        break;
      }
      f_12bb_0084(0x1c, 0);
      f_13d5_005c(DB(0x8980));
      DB(0x896f) = 1;
      break;
      break;

    case 0x0c2d:
    case 0x333c:
    case 0x492d:
    case 0x4a2d:
      if (DB(0x8980) > 4) {
        break;
      }
      DB(0x896f) = 2;
      f_12bb_0043(A9082[DB(0x8980)] - 1, 0xa000);
      f_1315_0039(DB(0x8980), 1);
      f_12bb_0061();
      break;
      break;

    case 0x0d2b:
    case 0x0d3b:
    case 0x0d3d:
    case 0x343e:
    case 0x4e2b:
      if (DB(0x8980) <= 4) {
        DB(0x896f) = 2;
        f_12bb_0043(A9082[DB(0x8980)] + 1, 0xa000);
        f_1315_0039(DB(0x8980), 1);
        f_12bb_0061();
        break;
      }

    }

    if (DB(0x8990)) {
      f_13d5_008e();
    }
    DW(0x898e) = 0x17;
    if (DB(0x438) == 0) {
      goto L_loop;
    }
    f_0000_2747((char far *)s__d_2410_0095, DW(0x898e));
    goto L_loop;
    goto L_loop;
  }
}
