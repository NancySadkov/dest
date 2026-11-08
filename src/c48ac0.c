#include "k48ac.h"

void __cdecl16far f_48ac_0000(void)
{
  f_118_002a(*(char far * far *)MK_FP(0x280, 0x89c5),
             (char far *)MK_FP(0xa000, 0xc306));
  DAT_2000_d1ae = 1;
}

void __cdecl16far f_48ac_0027(void)
{
  if (!*(unsigned char far *)MK_FP(0x280, 0x7144))
    f_118_002a((char far *)MK_FP(DAT_2000_d1aa, DAT_2000_d1a8),
               (char far *)MK_FP(0xa000, 0xc306));
}

void __cdecl16far f_48ac_0051(void)
{
  unsigned char pad[0x6];
  asm db 056h,0C6h,006h,0AEh,090h,000h,080h,03Eh,0B8h,045h,000h,075h,00Dh,0B8h,080h,002h
  asm db 08Eh,0C0h,026h,080h,03Eh,044h,071h,000h,074h,008h,0C6h,006h,0B8h,045h,000h,0E9h
  asm db 0D1h,001h,06Ah,002h,06Ah,000h,016h,08Dh,046h,0FAh,050h,09Ah,066h,026h,000h,000h
  asm db 083h,0C4h,008h,033h,0F6h,0E9h,0D1h,000h,08Bh,0DEh,0C1h,0E3h,002h,0B8h,070h,000h
  asm db 08Eh,0C0h,026h,0C4h,09Fh,000h,000h,026h,080h,07Fh,03Dh,000h,075h,003h,0E9h,0B7h
  asm db 000h,08Bh,0DEh,0C1h,0E3h,002h,0B8h,070h,000h,08Eh,0C0h,026h,0C4h,09Fh,000h,000h
  asm db 026h,08Ah,047h,03Fh,0B4h,000h,08Dh,056h,0FAh,003h,0C2h,08Bh,0D8h,036h,0FEh,007h
  asm db 08Bh,0DEh,0C1h,0E3h,002h,0B8h,070h,000h,08Eh,0C0h,026h,0C4h,09Fh,000h,000h,026h
  asm db 08Bh,047h,039h,0BAh,080h,002h,08Eh,0C2h,026h,03Bh,006h,09Fh,089h,075h,079h,08Bh
  asm db 0DEh,0C1h,0E3h,002h,0B8h,070h,000h,08Eh,0C0h,026h,0C4h,09Fh,000h,000h,026h,08Bh
  asm db 047h,03Bh,0BAh,080h,002h,08Eh,0C2h,026h,03Bh,006h,09Dh,089h,075h,05Ah,09Ah,02Fh
  asm db 000h,0F0h,000h,0B4h,000h,00Bh,0C0h,075h,003h,0E9h,03Bh,001h,08Bh,0DEh,0C1h,0E3h
  asm db 002h,0B8h,070h,000h,08Eh,0C0h,026h,08Bh,087h,002h,000h,026h,08Bh,097h,000h,000h
  asm db 089h,046h,0FEh,089h,056h,0FCh,0B8h,080h,002h,08Eh,0C0h,026h,0A0h,044h,071h,0B4h
  asm db 000h,00Bh,0C0h,075h,01Ch,0FFh,076h,0FEh,0FFh,076h,0FCh,01Eh,068h,0C5h,045h,09Ah
  asm db 04Dh,000h,070h,001h,083h,0C4h,008h,052h,050h,09Ah,03Eh,000h,0F8h,000h,083h,0C4h
  asm db 004h,00Eh,0E8h,0A4h,0FEh,0E9h,0EFh,000h,046h,0B8h,080h,002h,08Eh,0C0h,026h,0A0h
  asm db 0E6h,090h,0B4h,000h,03Bh,0C6h,07Eh,003h,0E9h,01Dh,0FFh,0B8h,080h,002h,08Eh,0C0h
  asm db 026h,080h,03Eh,0E4h,090h,000h,074h,073h,0B8h,080h,002h,08Eh,0C0h,026h,0A0h,0E4h
  asm db 090h,0B4h,000h,0C1h,0E0h,002h,0BAh,070h,000h,08Bh,0D8h,08Eh,0C2h,026h,08Bh,087h
  asm db 0FEh,0FFh,026h,08Bh,097h,0FCh,0FFh,089h,046h,0FEh,089h,056h,0FCh,090h,00Eh,0E8h
  asm db 0E9h,00Eh,00Ah,0C0h,074h,01Eh,0FFh,076h,0FEh,0FFh,076h,0FCh,01Eh,068h,0CEh,045h
  asm db 09Ah,04Dh,000h,070h,001h,083h,0C4h,008h,052h,050h,09Ah,03Eh,000h,0F8h,000h,083h
  asm db 0C4h,004h,0EBh,01Ch,0FFh,076h,0FEh,0FFh,076h,0FCh,01Eh,068h,0D8h,045h,09Ah,04Dh
  asm db 000h,070h,001h,083h,0C4h,008h,052h,050h,09Ah,03Eh,000h,0F8h,000h,083h,0C4h,004h
  asm db 0C6h,006h,0AEh,090h,001h,00Eh,0E8h,010h,0FEh,0EBh,05Ch,0B8h,080h,002h,08Eh,0C0h
  asm db 026h,0A0h,0E5h,090h,0BAh,080h,002h,08Eh,0C2h,026h,03Ah,006h,0E3h,090h,073h,043h
  asm db 0B8h,080h,002h,08Eh,0C0h,026h,0A0h,044h,071h,0B4h,000h,00Bh,0C0h,075h,029h,0B8h
  asm db 080h,002h,08Eh,0C0h,026h,0A0h,0E5h,090h,0B4h,000h,00Bh,0C0h,075h,00Eh,01Eh,068h
  asm db 0F0h,045h,09Ah,03Eh,000h,0F8h,000h,083h,0C4h,004h,0EBh,00Ch,01Eh,068h,00Ah,046h
  asm db 09Ah,03Eh,000h,0F8h,000h,083h,0C4h,004h,0C6h,006h,0AEh,090h,001h,00Eh,0E8h,0B8h
  asm db 0FDh,0EBh,004h,00Eh,0E8h,0D9h,0FDh,05Eh
  (void)pad;
}
