#include "k2d63.h"

void __cdecl16far f_2d63_0000(unsigned offv, unsigned segv)
{
  asm mov dx, segv
  asm mov ax, offv
  asm db 8Bh, 0D8h        /* mov bx, ax */
  asm mov cl, 4
  asm shr bx, cl
  asm db 03h, 0D3h        /* add dx, bx */
  asm and ax, 0xf
}

void __cdecl16far f_2d63_0016(unsigned v)
{
  asm db 06h              /* push es */
  asm db 1Eh              /* push ds */
  asm db 50h              /* push ax */
  asm db 53h              /* push bx */
  asm db 51h              /* push cx */
  asm db 52h              /* push dx */
  asm db 56h              /* push si */
  asm db 57h              /* push di */
  asm mov ax, v
  asm int 0x10
  asm db 5Fh              /* pop di */
  asm db 5Eh              /* pop si */
  asm db 5Ah              /* pop dx */
  asm db 59h              /* pop cx */
  asm db 5Bh              /* pop bx */
  asm db 58h              /* pop ax */
  asm db 1Fh              /* pop ds */
  asm db 07h              /* pop es */
}

void __cdecl16far f_2d63_0030(void)
{
  asm db 32h, 0E4h        /* xor ah, ah */
  asm int 0x16
}

void __cdecl16far f_2d63_0039(void)
{
  asm mov ah, 1
  asm int 0x16
  asm mov ax, 0
  asm db 74h, 03h        /* je +3 (flags from int 16h) */
  asm mov ax, 1
}

void __cdecl16far f_2d63_004a(void)
{
  asm db 06h              /* push es */
  asm db 57h              /* push di */
  asm mov ax, 3
  asm int 0x33
  asm db 8Bh, 0C3h        /* mov ax, bx */
  asm and ax, 7
  asm db 5Fh              /* pop di */
  asm db 07h              /* pop es */
}

void __cdecl16far f_2d63_005d(void)
{
  asm db 056h,057h,006h,01Eh,08Bh,046h,008h,086h,0E0h,08Bh,0F0h,0D1h,0E8h,0D1h,0E8h,003h
  asm db 0F0h,003h,076h,006h,08Bh,0FEh,08Bh,04Eh,00Ch,02Bh,04Eh,008h,083h,0C1h,001h,08Bh
  asm db 05Eh,00Ah,02Bh,05Eh,006h,083h,0C3h,001h,0BAh,040h,001h,02Bh,0D3h,08Bh,046h,00Eh
  asm db 08Eh,0D8h,08Bh,046h,010h,08Eh,0C0h,0FCh,051h,08Bh,0CBh,0F3h,0A4h,003h,0F2h,003h
  asm db 0FAh,059h,0E2h,0F4h,01Fh,007h,05Fh,05Eh
}

void __cdecl16far f_2d63_00aa(void)
{
  asm db 056h,057h,006h,01Eh,0FCh,0C5h,076h,006h,0C4h,07Eh,00Ah,0B4h,001h,08Ah,04Eh,010h
  asm db 0D2h,0C4h,08Bh,04Eh,00Eh,0B6h,080h,08Bh,05Eh,012h,08Bh,0EEh,08Bh,0F5h,032h,0C0h
  asm db 0B2h,001h,084h,034h,074h,002h,00Ah,0C2h,0D0h,0C2h,003h,0F3h,03Ah,0D4h,075h,0F2h
  asm db 0AAh,0D0h,0CEh,073h,001h,045h,0E2h,0E4h,01Fh,007h,05Fh,05Eh
}

void __cdecl16far f_2d63_00eb(unsigned segv, unsigned offv)
{
  asm mov al, byte ptr [bp+9]
  asm mov ah, byte ptr [bp+8]
  asm mov dl, byte ptr [bp+6]
  asm mov dh, byte ptr [bp+7]
}

void __cdecl16far f_2d63_00fc(unsigned x)
{
  asm mov al, byte ptr [bp+7]
  asm mov ah, byte ptr [bp+6]
}

void __cdecl16far f_2d63_0107(void)
{
  asm db 08Ah,05Eh,008h,08Ah,07Eh,006h,08Ah,056h,00Ah,032h,0F6h,002h,0D7h,002h,0D3h,080h
  asm db 0D6h,000h,0B1h,007h,0D3h,0EAh,080h,0FAh,002h,076h,002h,0B2h,002h,08Ah,0F2h,0B1h
  asm db 002h,0D2h,0E2h,002h,0D6h,080h,0C2h,0F4h,02Ah,0DFh,0D2h,0FBh,002h,0D9h,079h,004h
  asm db 032h,0DBh,0EBh,007h,080h,0FBh,004h,076h,002h,0B3h,004h,02Ah,0D3h,08Ah,0C2h
}

void __cdecl16far f_2d63_014b(void)
{
  asm db 08Ah,05Eh,008h,08Ah,07Eh,006h,08Ah,056h,00Ah,032h,0F6h,002h,0D7h,002h,0D3h,080h
  asm db 0D6h,000h,0B1h,007h,0D3h,0EAh,080h,0FAh,002h,076h,002h,0B2h,002h,08Ah,0F2h,0B1h
  asm db 002h,0D2h,0E2h,002h,0D6h,080h,0C2h,0F2h,08Ah,0C2h
}

void __cdecl16far f_2d63_017a(void)
{
  asm db 56h, 57h, 06h, 1Eh, 0Eh, 07h   /* push si,di,es,ds, push cs, pop es */
  asm mov ax, 0xc
  asm db 33h, 0C9h                       /* xor cx, cx */
  asm int 0x33
  asm db 1Fh, 07h, 5Fh, 5Eh             /* pop ds, es, di, si */
}

void __cdecl16far f_2d63_0190(void)
{
  asm db 06h, 57h, 1Eh, 56h             /* push es, di, ds, si */
  asm mov ax, 5
  asm db 33h, 0DBh                       /* xor bx, bx */
  asm int 0x33
  asm and ax, 7
  asm db 5Eh, 1Fh, 5Fh, 07h             /* pop si, ds, di, es */
}

void __cdecl16far f_2d63_01a7(unsigned x, unsigned y)
{
  asm db 06h, 57h, 1Eh, 56h             /* push es, di, ds, si */
  asm mov ax, 4
  asm mov cx, x
  asm mov dx, y
  asm int 0x33
  asm db 5Eh, 1Fh, 5Fh, 07h             /* pop si, ds, di, es */
}

void __cdecl16far f_2d63_01bf(void)
{
  asm db 056h,01Eh,0BAh,0C8h,003h,08Ah,046h,00Ah,0EEh,042h,08Bh,04Eh,00Ch,0C5h,076h,006h
  asm db 0FCh,0ACh,0EEh,0ACh,0EEh,0ACh,0EEh,0E2h,0F8h,01Fh,05Eh
}

void __cdecl16far f_2d63_01df(void)
{
  asm db 051h,052h,056h,01Eh,0BAh,0C8h,003h,0B8h,000h,000h,0EEh,042h,0B9h,000h,001h,0C5h
  asm db 076h,006h,0FCh,0ACh,0EEh,0ACh,0EEh,0ACh,0EEh,0E2h,0F8h,01Fh,05Eh,05Ah,059h
}

void __cdecl16far f_2d63_0203(void)
{
  asm db 056h,057h,01Eh,006h,0FCh,032h,0EDh,0C5h,076h,006h,0C4h,07Eh,00Ah,08Bh,056h,00Eh
  asm db 003h,0D7h,0ACh,03Ch,080h,074h,0FBh,073h,009h,08Ah,0C8h,080h,0C1h,001h,0F3h,0A4h
  asm db 0EBh,00Ah,034h,0FFh,08Ah,0C8h,080h,0C1h,002h,0ACh,0F3h,0AAh,03Bh,0FAh,072h,0E2h
  asm db 02Bh,076h,006h,08Bh,0C6h,007h,01Fh,05Fh,05Eh
}

void __cdecl16far f_2d63_0241(void)
{
  asm db 056h,057h,01Eh,006h,0FCh,032h,0EDh,0C5h,076h,006h,0C4h,07Eh,00Ah,08Bh,056h,00Eh
  asm db 003h,0D7h,0ACh,03Ch,080h,074h,0FBh,073h,014h,08Ah,0C8h,080h,0C1h,001h,0ACh,00Ah
  asm db 0C0h,074h,003h,026h,088h,005h,083h,0C7h,001h,0E2h,0F3h,0EBh,012h,034h,0FFh,08Ah
  asm db 0C8h,080h,0C1h,002h,0ACh,00Ah,0C0h,074h,004h,0F3h,0AAh,0EBh,002h,003h,0F9h,03Bh
  asm db 0FAh,072h,0CFh,02Bh,076h,006h,08Bh,0C6h,007h,01Fh,05Fh,05Eh
}

void __cdecl16far f_2d63_0292(void)
{
  asm db 056h,01Eh,0FCh,0C5h,076h,006h,08Ah,056h,00Ah,08Ah,076h,00Ch,0B9h,000h,0FAh,08Ah
  asm db 004h,03Ah,0C2h,075h,002h,088h,034h,083h,0C6h,001h,0E2h,0F3h,01Fh,05Eh
}

void __cdecl16far f_2d63_02b5(void)
{
  asm db 056h,057h,01Eh,006h,0C5h,076h,00Ah,08Bh,05Eh,010h,003h,0DEh,0C4h,07Eh,006h,08Bh
  asm db 056h,012h,003h,0D7h,08Bh,04Eh,014h,08Bh,06Eh,00Eh,03Bh,0FAh,073h,022h,03Bh,0F3h
  asm db 073h,01Eh,0F7h,0C1h,001h,000h,074h,013h,00Bh,0EDh,074h,005h,083h,0EDh,001h,0EBh
  asm db 00Ah,08Ah,004h,00Ah,0C0h,074h,003h,026h,088h,005h,047h,046h,0D1h,0C9h,0EBh,0DAh
  asm db 007h,01Fh,05Fh,05Eh
}

void __cdecl16far f_2d63_02fe(void)
{
  asm db 056h,01Eh,0FCh,08Bh,056h,00Ah,03Bh,056h,00Ch,076h,003h,08Bh,056h,00Ch,0C5h,076h
  asm db 006h,08Bh,0DEh,003h,0D6h,0ACh,08Ah,0E0h,03Bh,0F2h,073h,008h,0ACh,03Ah,0E0h,074h
  asm db 0F7h,083h,0EEh,001h,02Bh,0F3h,08Bh,0C6h,01Fh,05Eh
}

void __cdecl16far f_2d63_032d(void)
{
  asm db 056h,057h,01Eh,006h,055h,0FCh,0C5h,076h,006h,08Bh,0DEh,08Bh,056h,00Eh,003h,0D6h
  asm db 0C4h,07Eh,00Ah,08Bh,0EEh,08Bh,0CAh,02Bh,0CEh,081h,0F9h,080h,000h,072h,003h,0B9h
  asm db 080h,000h,003h,0CEh,08Ah,004h,046h,03Bh,0F1h,073h,004h,03Ah,004h,074h,0F7h,02Bh
  asm db 0F5h,087h,0F5h,083h,0FDh,003h,072h,025h,03Bh,0DEh,074h,00Fh,08Bh,0CEh,02Bh,0CBh
  asm db 08Ah,0C1h,0FEh,0C8h,0AAh,08Bh,0F3h,0F3h,0A4h,08Bh,0DEh,0B0h,001h,02Bh,0C5h,0AAh
  asm db 08Ah,004h,0AAh,003h,0F5h,08Bh,0DEh,03Bh,0F2h,072h,0B8h,0EBh,01Dh,046h,08Bh,0CEh
  asm db 02Bh,0CBh,080h,0F9h,080h,073h,004h,03Bh,0F2h,072h,0A8h,08Ah,0C1h,0FEh,0C8h,0AAh
  asm db 08Bh,0F3h,0F3h,0A4h,08Bh,0DEh,03Bh,0F2h,072h,099h,08Bh,0C7h,05Dh,02Bh,046h,00Ah
  asm db 007h,01Fh,05Fh,05Eh
}

void __cdecl16far f_2d63_03b6(void)
{
  asm db 056h,057h,01Eh,006h,0FDh,032h,0EDh,0C5h,076h,006h,0C4h,056h,00Ah,08Bh,07Eh,00Eh
  asm db 003h,0FAh,04Fh,0FCh,0ACh,03Ch,080h,074h,0FAh,073h,00Dh,08Ah,0C8h,080h,0C1h,001h
  asm db 0FCh,0ACh,0FDh,0AAh,0E2h,0FAh,0EBh,00Ch,034h,0FFh,08Ah,0C8h,080h,0C1h,002h,0FCh
  asm db 0ACh,0FDh,0F3h,0AAh,03Bh,0FAh,073h,0DBh,02Bh,076h,006h,08Bh,0C6h,007h,01Fh,05Fh
  asm db 05Eh
}
