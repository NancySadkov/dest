/*
 * mouse.c - recovered from STRONG.EXE
 * memory block: 138e_TEXT_mouse
 * range: 138e:0002 - 138e:01ca
 * functions: 3
 */
#include "recovered.h"


/* 138e:0108 */

/* WARNING: This function may have set the stack pointer */

void __cdecl16far
miceHandler(uint16_t mask,uint16_t buttons,uint16_t x,uint16_t y,uint16_t dx,uint16_t dy)

{
  undefined1 stk_fff0;   /* stack slot fff0 */
  uint in_AX;
  undefined2 in_CX;
  undefined2 in_DX;
  undefined2 unaff_SS;
  
                    /* Mask bits:
                        0 call if mouse moves
                        1 call if left button pressed
                        2 call if left button released
                        3 call if right button pressed
                        4 call if right button released
                        5 call if middle button pressed (Mouse Systems/Logitech/Genius mouse)
                        6 call if middle button released (Mouse Systems/Logitech/Genius mouse)
                        7-15 unused */
  if ((in_AX & 3) != 0) {
                    /* WARNING: Read-only address (ram,0x00010104) is written */
                    /* WARNING: Read-only address (ram,0x00010106) is written */
                    /* WARNING: Read-only address (ram,0x000100fe) is written */
                    /* WARNING: Read-only address (ram,0x000100fc) is written */
                    /* WARNING: Read-only address (ram,0x000100fa) is written */
                    /* WARNING: Read-only address (ram,0x000100f6) is written */
                    /* WARNING: Read-only address (ram,0x000100f8) is written */
    uRam000100f8 = 0x1000;
    uRam000100f6 = 0x3a17;
    uRam00010104 = unaff_SS;
    puRam00010106 = &stk_fff0;
    uRam000100fa = in_CX;
    uRam000100fc = in_DX;
    uRam000100fe = in_AX;
    videoMiceEvent(uRam000000fa,uRam000000fc,uRam000000fe);
  }
  return;
}



/* 138e:014b */

bool __cdecl16far miceInitDriver(void)

{
  code *pcVar1;
  int iVar2;
  
                    /* WARNING: Read-only address (ram,0x00010102) is written */
  uRam00010102 = 0x2410;
  pcVar1 = (code *)swi(0x33);
  iVar2 = (*pcVar1)();
  if (iVar2 == -1) {
    pcVar1 = (code *)swi(0x33);
    (*pcVar1)();
    pcVar1 = (code *)swi(0x33);
    (*pcVar1)();
    pcVar1 = (code *)swi(0x33);
    (*pcVar1)();
    pcVar1 = (code *)swi(0x33);
    (*pcVar1)();
    return false;
  }
  return true;
}



/* 138e:01a6 */

void __cdecl16far blitTillAlpha(far_t dst,far_t src,uint16_t size)

{
  char *pcVar1;
  char *pcVar2;
  uint16_t s;
  uint16_t d;
  uint32_t pd;
  uint32_t ps;
  
  s = src.ofs;
  d = dst.ofs;
  do {
    while( true ) {
      pcVar1 = (char *)s;
      s = s + 1;
      if (*pcVar1 == '\0') break;
      pcVar2 = (char *)d;
      d = d + 1;
      *pcVar2 = *pcVar1;
      size = size - 1;
      if (size == 0) {
        return;
      }
    }
    d = d + 1;
    size = size - 1;
  } while (size != 0);
  return;
}


