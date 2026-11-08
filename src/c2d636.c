#include "k2d63.h"

void __cdecl16far f_2d63_0b94(unsigned offv, unsigned segv)
{
  asm push cx
  asm mov ax, offv
  asm mov dx, segv
  asm mov cl, 4
  asm shr ax, cl
  asm db 03h, 0D0h            /* add dx, ax */
  asm mov ax, offv
  asm and ax, 0xf
  asm pop cx
}

void __cdecl16far f_2d63_0bad(char far *src, char far *dst, unsigned words)
{
  asm db 06h, 57h, 1Eh, 56h, 51h       /* push es,di,ds,si,cx */
  asm db 0C5h, 76h, 06h                /* lds si, [bp+6] */
  asm db 0C4h, 7Eh, 0Ah                /* les di, [bp+0ah] */
  asm mov cx, words
  asm cld
  asm rep movsw
  asm db 59h, 5Eh, 1Fh, 5Fh, 07h       /* pop cx,si,ds,di,es */
}

void __cdecl16far f_2d63_0bc8(char far *dst, unsigned words)
{
  asm db 06h, 57h, 51h                 /* push es,di,cx */
  asm db 0C4h, 7Eh, 06h                /* les di, [bp+6] */
  asm mov cx, words
  asm db 33h, 0C0h                     /* xor ax, ax */
  asm cld
  asm rep stosw
  asm db 59h, 5Fh, 07h                 /* pop cx,di,es */
}

void __cdecl16far f_2d63_0bde(void)
{
  asm db 01Eh,056h,057h,051h,053h,0FCh,0C5h,076h,006h,0C4h,07Eh,00Ah,0ADh,08Bh,0D8h,085h
  asm db 0DBh,0EBh,019h,090h,0ACh,003h,0F8h,003h,0F8h,003h,0F8h,0ACh,00Ah,0C0h,075h,003h
  asm db 0B8h,000h,001h,08Bh,0C8h,003h,0C8h,003h,0C8h,0F3h,0A4h,04Bh,075h,0E6h,05Bh,059h
  asm db 05Fh,05Eh,01Fh
}
