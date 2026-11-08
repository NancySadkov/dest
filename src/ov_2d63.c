#include "dgroup.h"

/* INT 66h service wrappers preserve es, ds, si and di. */
#define ENTER_INT66 asm db 06h, 1Eh, 56h, 57h
#define LEAVE_INT66 asm db 5Fh, 5Eh, 1Fh, 07h

/* 2D63:0000  linear address -> far pointer (result in DX:AX) */
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

/* 2D63:0016  BIOS video service, all registers preserved */
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

/* 2D63:0030  BIOS keyboard read (result in AX) */
void __cdecl16far f_2d63_0030(void)
{
  asm db 32h, 0E4h        /* xor ah, ah */
  asm int 0x16
}

/* 2D63:0039  key available? (result in AX) */
void __cdecl16far f_2d63_0039(void)
{
  asm mov ah, 1
  asm int 0x16
  asm mov ax, 0
  asm db 74h, 03h        /* je +3 (flags from int 16h) */
  asm mov ax, 1
}

/* 2D63:004A  mouse button state (result in AX, low 3 bits) */
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

/* 2D63:00EB  build a far pointer from two words (result in DX:AX) */
void __cdecl16far f_2d63_00eb(unsigned segv, unsigned offv)
{
  asm mov al, byte ptr [bp+9]
  asm mov ah, byte ptr [bp+8]
  asm mov dl, byte ptr [bp+6]
  asm mov dh, byte ptr [bp+7]
}

/* 2D63:00FC  byte-swap a word (result in AX) */
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

/* 2D63:017A  mouse reset */
void __cdecl16far f_2d63_017a(void)
{
  asm db 56h, 57h, 06h, 1Eh, 0Eh, 07h   /* push si,di,es,ds, push cs, pop es */
  asm mov ax, 0xc
  asm db 33h, 0C9h                       /* xor cx, cx */
  asm int 0x33
  asm db 1Fh, 07h, 5Fh, 5Eh             /* pop ds, es, di, si */
}

/* 2D63:0190  mouse button state (result in AX) */
void __cdecl16far f_2d63_0190(void)
{
  asm db 06h, 57h, 1Eh, 56h             /* push es, di, ds, si */
  asm mov ax, 5
  asm db 33h, 0DBh                       /* xor bx, bx */
  asm int 0x33
  asm and ax, 7
  asm db 5Eh, 1Fh, 5Fh, 07h             /* pop si, ds, di, es */
}

/* 2D63:01A7  mouse position */
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

void __cdecl16far f_2d63_03fc(void)
{
  asm db 056h,057h,01Eh,006h,032h,0EDh,0C5h,076h,006h,0C4h,056h,00Ah,08Bh,07Eh,00Eh,003h
  asm db 0FAh,04Fh,0FCh,0ACh,03Ch,080h,074h,0FBh,073h,012h,08Ah,0C8h,080h,0C1h,001h,0ACh
  asm db 00Ah,0C0h,074h,003h,026h,088h,005h,04Fh,0E2h,0F5h,0EBh,014h,034h,0FFh,08Ah,0C8h
  asm db 080h,0C1h,002h,0ACh,00Ah,0C0h,074h,006h,0FDh,0F3h,0AAh,0FCh,0EBh,002h,02Bh,0F9h
  asm db 03Bh,0FAh,073h,0CFh,02Bh,076h,006h,08Bh,0C6h,007h,01Fh,05Fh,05Eh
}

void __cdecl16far f_2d63_044f(void)
{
  asm db 057h,056h,01Eh,006h,08Bh,04Eh,00Ah,0C4h,07Eh,006h,08Ah,076h,00Eh,0C5h,076h,010h
  asm db 032h,0C0h,08Ah,05Eh,00Ch,08Bh,06Eh,014h,00Ah,0DBh,074h,026h,026h,08Ah,025h,00Ah
  asm db 0E4h,074h,01Ah,045h,081h,0E5h,0FFh,000h,03Eh,08Ah,012h,03Ah,0D6h,073h,009h,086h
  asm db 0D8h,0AAh,086h,0D8h,0E2h,0E6h,0EBh,027h,0AAh,0E2h,0E1h,0EBh,022h,047h,0E2h,0DCh
  asm db 0EBh,01Dh,026h,08Ah,005h,00Ah,0C0h,074h,013h,03Eh,08Ah,012h,045h,081h,0E5h,0FFh
  asm db 000h,03Ah,0D6h,072h,002h,032h,0C0h,0AAh,0E2h,0E8h,0EBh,003h,047h,0E2h,0E3h,007h
  asm db 01Fh,05Eh,05Fh
}

void __cdecl16far f_2d63_04b7(void)
{
  asm db 083h,0ECh,006h,006h,056h,057h,051h,052h,053h,0FCh,0BEh,040h,001h,08Bh,04Eh,00Ah
  asm db 02Bh,04Eh,006h,074h,055h,079h,014h,0F7h,0D9h,08Bh,05Eh,00Ah,087h,05Eh,006h,089h
  asm db 05Eh,00Ah,08Bh,05Eh,00Ch,087h,05Eh,008h,089h,05Eh,00Ch,08Bh,05Eh,00Ch,02Bh,05Eh
  asm db 008h,074h,05Eh,079h,004h,0F7h,0DBh,0F7h,0DEh,056h,0C7h,046h,0FAh,060h,005h,03Bh
  asm db 0D9h,07Eh,007h,0C7h,046h,0FAh,078h,005h,087h,0D9h,0D1h,0E3h,089h,05Eh,0FEh,02Bh
  asm db 0D9h,08Bh,0F3h,02Bh,0D9h,089h,05Eh,0FCh,051h,08Bh,046h,008h,08Bh,05Eh,006h,0E8h
  asm db 07Dh,000h,08Bh,0FBh,059h,041h,05Bh,0FFh,066h,0FAh,08Bh,046h,008h,08Bh,05Eh,00Ch
  asm db 08Bh,0CBh,02Bh,0C8h,07Dh,004h,0F7h,0D9h,08Bh,0C3h,041h,08Bh,05Eh,006h,051h,0E8h
  asm db 05Dh,000h,059h,08Bh,0FBh,04Eh,08Ah,046h,00Eh,0AAh,003h,0FEh,0E2h,0FBh,0EBh,045h
  asm db 090h,051h,08Bh,046h,008h,08Bh,05Eh,006h,0E8h,044h,000h,08Bh,0FBh,059h,041h,08Ah
  asm db 046h,00Eh,0F3h,0AAh,0EBh,02Fh,08Ah,046h,00Eh,0AAh,00Bh,0F6h,079h,007h,003h,076h
  asm db 0FEh,0E2h,0F6h,0EBh,020h,003h,076h,0FCh,003h,0FBh,0E2h,0EDh,0EBh,017h,08Ah,046h
  asm db 00Eh,0AAh,003h,0FBh,00Bh,0F6h,079h,008h,003h,076h,0FEh,04Fh,0E2h,0F3h,0EBh,005h
  asm db 003h,076h,0FCh,0E2h,0ECh,05Bh,05Ah,059h,05Fh,05Eh,007h,08Bh,0E5h
}

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
  asm db 0E2h,0F3h,05Ah,05Bh,059h,058h,05Fh,007h
}

/* 2D63:06BF  INT 66h service 0x689 */
void __cdecl16far f_2d63_06bf(void)
{
  ENTER_INT66;
  asm mov ax, 0x689
  asm int 0x66
  LEAVE_INT66;
}

/* 2D63:06D1  INT 66h service 0x68B, si:ds = string */
void __cdecl16far f_2d63_06d1(char far *p)
{
  ENTER_INT66;
  asm mov ax, 0x68b
  asm db 0C5h, 76h, 06h        /* lds si, [bp+6] */
  asm int 0x66
  LEAVE_INT66;
}

/* 2D63:06E6  INT 66h service 0x694, si:ds = string */
void __cdecl16far f_2d63_06e6(char far *p)
{
  ENTER_INT66;
  asm mov ax, 0x694
  asm db 0C5h, 76h, 06h        /* lds si, [bp+6] */
  asm int 0x66
  LEAVE_INT66;
}

/* 2D63:06FB  INT 66h service 0x68F */
void __cdecl16far f_2d63_06fb(void)
{
  ENTER_INT66;
  asm mov ax, 0x68f
  asm int 0x66
  LEAVE_INT66;
}

void __cdecl16far f_2d63_070d(void)
{
  asm db 01Eh,056h,0B8h,08Ah,006h,0C5h,076h,006h,0CDh,066h,05Eh,01Fh
}

/* 2D63:075F  INT 66h service 0x702, bx = value */
void __cdecl16far f_2d63_075f(unsigned x)
{
  ENTER_INT66;
  asm mov ax, 0x702
  asm mov bx, x
  asm int 0x66
  LEAVE_INT66;
}

/* 2D63:0774  INT 66h service 0x703, bx/cx = values */
void __cdecl16far f_2d63_0774(unsigned x, unsigned y)
{
  ENTER_INT66;
  asm mov ax, 0x703
  asm mov bx, x
  asm mov cx, y
  asm int 0x66
  LEAVE_INT66;
}

/* 2D63:078C  INT 66h service 0x704 */
void __cdecl16far f_2d63_078c(unsigned a, unsigned b, unsigned c, unsigned d)
{
  ENTER_INT66;
  asm mov ax, 0x704
  asm mov bx, a
  asm mov cx, b
  asm db 8Bh, 76h, 0Ah        /* mov si, [bp+0ah] */
  asm db 8Bh, 7Eh, 0Ch        /* mov di, [bp+0ch] */
  asm int 0x66
  LEAVE_INT66;
}

/* 2D63:07AA  INT 66h service 0x705 */
void __cdecl16far f_2d63_07aa(void)
{
  ENTER_INT66;
  asm mov ax, 0x705
  asm int 0x66
  LEAVE_INT66;
}

/* 2D63:07BC  INT 66h service 0x70C */
void __cdecl16far f_2d63_07bc(void)
{
  ENTER_INT66;
  asm mov ax, 0x70c
  asm int 0x66
  LEAVE_INT66;
}

void __cdecl16far f_2d63_07ce(void)
{
  asm db 01Eh,056h,0BEh,098h,001h,033h,0C0h,08Eh,0D8h,0C5h,034h,00Bh,0F6h,074h,017h,083h
  asm db 0EEh,006h,081h,03Ch,04Dh,049h,075h,00Eh,081h,07Ch,002h,044h,049h,075h,007h,0B8h
  asm db 001h,000h,05Eh,01Fh
}

/* 2D63:07FB  INT 66h service 0x710, bx/cx/dx/si from args */
void __cdecl16far f_2d63_07fb(unsigned a, unsigned b, unsigned c, unsigned d)
{
  ENTER_INT66;
  asm mov bx, b
  asm mov cx, a
  asm mov dx, d
  asm db 8Bh, 76h, 0Ah        /* mov si, [bp+0ah] */
  asm mov ax, 0x710
  asm int 0x66
  LEAVE_INT66;
}

/* 2D63:0819  INT 66h service 0x697, dx = value */
void __cdecl16far f_2d63_0819(unsigned x)
{
  ENTER_INT66;
  asm mov dx, x
  asm mov ax, 0x697
  asm int 0x66
  LEAVE_INT66;
}

/* 2D63:082E  INT 66h service 0x70F, bx/cx = values */
void __cdecl16far f_2d63_082e(unsigned a, unsigned b)
{
  ENTER_INT66;
  asm mov ax, 0x70f
  asm mov bx, a
  asm mov cx, b
  asm int 0x66
  LEAVE_INT66;
}

void __cdecl16far f_2d63_0846(void)
{
  asm db 083h,0ECh,016h,056h,057h,006h,01Eh,08Bh,046h,014h,08Eh,0C0h,08Ah,046h,008h,03Ah
  asm db 046h,00Ch,076h,015h,08Ah,05Eh,00Ch,088h,046h,00Ch,088h,05Eh,008h,08Bh,046h,006h
  asm db 08Bh,05Eh,00Ah,089h,05Eh,006h,089h,046h,00Ah,08Ah,046h,008h,03Ah,046h,010h,076h
  asm db 015h,08Ah,05Eh,010h,088h,046h,010h,088h,05Eh,008h,08Bh,046h,006h,08Bh,05Eh,00Eh
  asm db 089h,05Eh,006h,089h,046h,00Eh,08Ah,046h,00Ch,03Ah,046h,010h,076h,015h,08Ah,05Eh
  asm db 010h,088h,046h,010h,088h,05Eh,00Ch,08Bh,046h,00Ah,08Bh,05Eh,00Eh,089h,05Eh,00Ah
  asm db 089h,046h,00Eh,08Bh,046h,00Eh,02Bh,046h,006h,099h,0D1h,0E2h,042h,089h,056h,0EEh
  asm db 032h,0EDh,08Ah,04Eh,010h,02Ah,04Eh,008h,088h,04Eh,0ECh,088h,04Eh,0F4h,075h,006h
  asm db 033h,0C0h,033h,0D2h,0EBh,009h,099h,0F7h,0F9h,00Bh,0D2h,079h,002h,0F7h,0DAh,088h
  asm db 056h,0F0h,005h,040h,001h,089h,046h,0F2h,0D0h,06Eh,0F4h,08Bh,046h,00Ah,02Bh,046h
  asm db 006h,099h,0D1h,0E2h,042h,089h,056h,0F8h,032h,0EDh,08Ah,04Eh,00Ch,02Ah,04Eh,008h
  asm db 088h,04Eh,0FEh,088h,04Eh,0F6h,075h,006h,033h,0C0h,033h,0D2h,0EBh,009h,099h,0F7h
  asm db 0F9h,00Bh,0D2h,079h,002h,0F7h,0DAh,088h,056h,0FAh,005h,040h,001h,089h,046h,0FCh
  asm db 0D0h,06Eh,0FEh,08Bh,076h,006h,08Ah,066h,008h,032h,0C0h,003h,0F0h,0D1h,0E8h,0D1h
  asm db 0E8h,003h,0F0h,08Bh,0FEh,00Ah,0C9h,074h,003h,0E8h,055h,000h,08Bh,046h,00Eh,02Bh
  asm db 046h,00Ah,099h,0D1h,0E2h,042h,089h,056h,0F8h,032h,0EDh,08Ah,04Eh,010h,02Ah,04Eh
  asm db 00Ch,088h,04Eh,0F6h,088h,04Eh,0FEh,075h,006h,033h,0C0h,033h,0D2h,0EBh,009h,099h
  asm db 0F7h,0F9h,00Bh,0D2h,079h,002h,0F7h,0DAh,088h,056h,0FAh,005h,040h,001h,089h,046h
  asm db 0FCh,0D0h,06Eh,0FEh,08Bh,076h,00Ah,08Ah,066h,00Ch,032h,0C0h,003h,0F0h,0D1h,0E8h
  asm db 0D1h,0E8h,003h,0F0h,0FEh,0C1h,0E8h,008h,000h,01Fh,007h,05Fh,05Eh,08Bh,0E5h
}

void __cdecl16far f_2d63_09c9(void)
{
  asm db 057h,006h,01Eh,08Bh,07Eh,006h,08Bh,04Eh,008h,03Bh,0F9h,07Eh,002h,087h,0CFh,0C5h
  asm db 05Eh,00Eh,03Bh,03Fh,07Dh,002h,08Bh,03Fh,03Bh,04Fh,004h,07Eh,003h,08Bh,04Fh,004h
  asm db 02Bh,0CFh,07Ch,023h,08Ah,076h,00Ah,03Ah,077h,002h,072h,01Bh,03Ah,077h,006h,077h
  asm db 016h,041h,032h,0D2h,003h,0FAh,0D1h,0EAh,0D1h,0EAh,003h,0FAh,08Bh,057h,008h,08Eh
  asm db 0C2h,08Ah,046h,00Ch,0FCh,0F3h,0AAh,01Fh,007h,05Fh
}

/* 2D63:0A18  multiplex interrupt 0x16, low result byte */
void __cdecl16far f_2d63_0a18(void)
{
  asm mov ax, 0x1600
  asm int 0x2f
  asm db 32h, 0E4h            /* xor ah, ah */
}

void __cdecl16far f_2d63_0a24(void)
{
  asm db 006h,057h,0C4h,07Eh,006h,003h,07Eh,00Ah,003h,07Eh,00Ah,08Bh,046h,00Ch,0BBh,028h
  asm db 001h,0F7h,0E3h,003h,0F8h,08Bh,04Eh,010h,02Bh,04Eh,00Ch,041h,08Bh,056h,00Eh,02Bh
  asm db 056h,00Ah,042h,08Bh,0F7h,08Bh,046h,012h,051h,08Bh,0CAh,026h,009h,005h,083h,0C7h
  asm db 002h,0E2h,0F8h,059h,081h,0C6h,028h,001h,08Bh,0FEh,0E2h,0ECh,05Fh,007h
}

void __cdecl16far f_2d63_0a67(void)
{
  asm db 006h,057h,056h,0C4h,07Eh,006h,003h,07Eh,00Ah,003h,07Eh,00Ah,08Bh,046h,00Ch,0BBh
  asm db 028h,001h,0F7h,0E3h,003h,0F8h,08Bh,04Eh,010h,02Bh,04Eh,00Ch,041h,08Bh,056h,00Eh
  asm db 02Bh,056h,00Ah,042h,08Bh,0F7h,08Bh,046h,012h,051h,08Bh,0CAh,026h,021h,005h,083h
  asm db 0C7h,002h,0E2h,0F8h,059h,081h,0C6h,028h,001h,08Bh,0FEh,0E2h,0ECh,05Eh,05Fh,007h
}

void __cdecl16far f_2d63_0aac(void)
{
  asm db 006h,01Eh,056h,057h,053h,051h,0FCh,0C5h,076h,006h,0C4h,07Eh,00Ah,08Bh,0D7h,032h
  asm db 0E4h,0BDh,0C8h,000h,08Bh,0FAh,0ACh,08Ah,0D8h,084h,0DBh,0EBh,01Ah,090h,0ACh,084h
  asm db 0C0h,078h,00Ch,08Bh,0C8h,0ACh,0F3h,0AAh,0FEh,0CBh,075h,0F2h,0EBh,00Bh,090h,0F6h
  asm db 0D8h,08Bh,0C8h,0F3h,0A4h,0FEh,0CBh,075h,0E5h,081h,0C2h,040h,001h,04Dh,075h,0D4h
  asm db 059h,05Bh,05Fh,05Eh,01Fh,007h
}

void __cdecl16far f_2d63_0af7(void)
{
  asm db 006h,01Eh,056h,057h,053h,051h,0FCh,0C5h,076h,006h,0C4h,07Eh,00Ah,0ADh,0BAh,040h
  asm db 001h,0F7h,0E2h,003h,0F8h,0ADh,08Bh,0E8h,08Bh,0D7h,032h,0E4h,08Bh,0FAh,0ACh,08Ah
  asm db 0D8h,084h,0DBh,0EBh,01Dh,090h,0ACh,003h,0F8h,0ACh,084h,0C0h,078h,00Bh,08Bh,0C8h
  asm db 0F3h,0A4h,0FEh,0CBh,075h,0F0h,0EBh,00Ch,090h,0F6h,0D8h,08Bh,0C8h,0ACh,0F3h,0AAh
  asm db 0FEh,0CBh,075h,0E2h,081h,0C2h,040h,001h,04Dh,075h,0D1h,059h,05Bh,05Fh,05Eh,01Fh
  asm db 007h
}

void __cdecl16far f_2d63_0b4d(void)
{
  asm db 01Eh,056h,057h,051h,053h,0FCh,0C5h,076h,006h,0BFh,000h,000h,0ADh,08Bh,0D8h,085h
  asm db 0DBh,0EBh,01Fh,090h,0ACh,003h,0F8h,0ACh,08Bh,0C8h,00Bh,0C9h,075h,003h,0B9h,000h
  asm db 001h,0BAh,0C8h,003h,08Bh,0C7h,0EEh,047h,042h,0ACh,0EEh,0ACh,0EEh,0ACh,0EEh,0E2h
  asm db 0F0h,04Bh,075h,0E0h,05Bh,059h,05Fh,05Eh,01Fh
}

/* 2D63:0B94  linear address -> far pointer (result in DX:AX) */
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

/* 2D63:0BAD  copy words between far pointers */
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

/* 2D63:0BC8  fill a far buffer with words */
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
