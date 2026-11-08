#include "k2d63.h"

void __cdecl16far f_2d63_05a9(void)
{
  asm db 006h,057h,08Bh,046h,00Eh,08Eh,0C0h,08Bh,046h,006h,03Bh,046h,008h,076h,009h,08Bh
  asm db 07Eh,008h,089h,046h,008h,089h,07Eh,006h,08Bh,07Eh,006h,08Bh,046h,00Ah,086h,0C4h
  asm db 003h,0F8h,0D1h,0E8h,0D1h,0E8h,003h,0F8h,08Bh,04Eh,008h,02Bh,04Eh,006h,041h,08Ah
  asm db 046h,00Ch,0FCh,0F3h,0AAh,05Fh,007h
}

void __cdecl16far f_2d63_05e5(void)
{
  asm db 006h,057h,050h,051h,053h,052h,08Bh,046h,010h,08Eh,0C0h,08Bh,046h,006h,03Bh,046h
  asm db 00Ah,076h,009h,08Bh,07Eh,00Ah,089h,046h,00Ah,089h,07Eh,006h,08Bh,046h,008h,03Bh
  asm db 046h,00Ch,076h,009h,08Bh,07Eh,00Ch,089h,046h,00Ch,089h,07Eh,008h,08Bh,07Eh,006h
  asm db 08Bh,046h,008h,086h,0C4h,003h,0F8h,0D1h,0E8h,0D1h,0E8h,003h,0F8h,08Bh,04Eh,00Ch
  asm db 02Bh,04Eh,008h,083h,0C1h,001h,08Bh,05Eh,00Ah,02Bh,05Eh,006h,083h,0C3h,001h,0BAh
  asm db 040h,001h,02Bh,0D3h,0FCh,051h,08Bh,0CBh,08Ah,046h,00Eh,0F3h,0AAh,003h,0FAh,059h
  asm db 0E2h,0F3h,05Ah,05Bh,059h,058h,05Fh,007h,05Dh,0CBh,055h,0FCh,08Bh,0ECh,006h,057h
  asm db 08Bh,046h,00Eh,08Eh,0C0h,08Bh,07Eh,006h,08Ah,066h,008h,032h,0C0h,003h,0F8h,0D1h
  asm db 0E8h,0D1h,0E8h,003h,0F8h,08Ah,046h,00Ah,08Ah,0E0h,0ABh,081h,0C7h,03Eh,001h,0AAh
  asm db 08Ah,046h,00Ch,08Ah,0E0h,0AAh,081h,0C7h,03Eh,001h,0ABh,05Fh,007h,05Dh,0CBh,055h
  asm db 0FCh,08Bh,0ECh,006h,057h,08Bh,046h,00Eh,08Eh,0C0h,08Bh,07Eh,006h,08Ah,066h,008h
  asm db 032h,0C0h,003h,0F8h,0D1h,0E8h,0D1h,0E8h,003h,0F8h,08Ah,046h,00Ah,08Ah,0E0h,0ABh
  asm db 081h,0C7h,03Fh,001h,0AAh,083h,0EFh,002h,08Ah,046h,00Ch,08Ah,0E0h,0AAh,081h,0C7h
  asm db 03Fh,001h,0ABh,05Fh,007h
}

void __cdecl16far f_2d63_06bf(void)
{
  ENTER_INT66;
  asm mov ax, 0x689
  asm int 0x66
  LEAVE_INT66;
}

void __cdecl16far f_2d63_06d1(char far *p)
{
  ENTER_INT66;
  asm mov ax, 0x68b
  asm db 0C5h, 76h, 06h        /* lds si, [bp+6] */
  asm int 0x66
  LEAVE_INT66;
}

void __cdecl16far f_2d63_06e6(char far *p)
{
  ENTER_INT66;
  asm mov ax, 0x694
  asm db 0C5h, 76h, 06h        /* lds si, [bp+6] */
  asm int 0x66
  LEAVE_INT66;
}

void __cdecl16far f_2d63_06fb(void)
{
  ENTER_INT66;
  asm mov ax, 0x68f
  asm int 0x66
  LEAVE_INT66;
}
