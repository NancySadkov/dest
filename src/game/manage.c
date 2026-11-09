#include "dgroup.h"

struct unit4d2 {
  char pad0[0x3D];
  unsigned char f3d;
  char pad1[0x4B];
  unsigned char f89;
};

void __cdecl16far f_4d05_0000(void)
{
  int i;
  struct unit4d2 far *p;
  for (i = 0; i < 5; i++)
    ((unsigned char far *)MK_FP(0x0280, 0x90DE))[i] = 0xFF;
  for (i = 0; i < DAT_2000_d1e6; i++) {
    p = *(struct unit4d2 far * far *)MK_FP(0x0070, i * 4);
    if (p->f3d != 0 && p->f89 != 0xFF)
      ((unsigned char far *)MK_FP(0x0280, 0x90DE))[p->f89] =
          (unsigned char)i;
  }
}
