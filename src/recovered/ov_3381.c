#include "dgroup.h"

#define SBUF ((char far *)MK_FP(0x280, 0x8bb1))
#define GGameExeP (*(far_t far *)MK_FP(0x280, 0x8976))
#define EMPTY_5BB ((char far *)&GCfgFileName[-1])
#define MAPDIR ((char far * far *)MK_FP(0x280, 0x8a05))
#define MAPFLG ((uint16_t far * far *)MK_FP(0x280, 0x8a09))

int __cdecl16far f_1000_2d9b(char far *s);
char far * __cdecl16far f_1000_2d31(char far *dst, char far *src);
char far * __cdecl16far f_1000_2cc2(char far *dst, char far *src);
int __cdecl16far f_1000_0865(char far *s);
int __cdecl16far f_1000_0e30(int c);
void __cdecl16far f_1000_09a2(int v);
void __cdecl16far f_1000_2568(char far *buf, int len);
int __cdecl16far f_1000_0e04(int c);
void __cdecl16far f_3381_1fba(void);
void __cdecl16far f_1400_0039(int);

/* 3381:0132 */
char far * __cdecl16far f_3381_0132(char far *s)
{
  int n;

  n = f_1000_2d9b(s);
  if (n == 0 || s[n - 1] != '\\') {
    s[n] = '\\';
    s[n + 1] = 0;
  }
  return s;
}

/* 3381:00fe */
char far * __cdecl16far f_3381_00fe(char far *s)
{
  int n;

  n = f_1000_2d9b(s);
  if (n > 3 && s[n - 1] == '\\') {
    s[n - 1] = 0;
  }
  return s;
}

/* 3381:009a */
char far * __cdecl16far f_3381_009a(char far *a, char far *b)
{
  int n;

  f_1000_2d31(SBUF, a);
  n = f_1000_2d9b(SBUF);
  while (n > 0 && SBUF[n - 1] != '\\') {
    n--;
  }
  SBUF[n] = 0;
  f_1000_2cc2(SBUF, b);
  return SBUF;
}

/* 3381:016c */
void __cdecl16far f_3381_016c(char far *s)
{
  char c;

  if (f_1000_0865(s) == 0) {
    c = (char)f_1000_0e30((int)s[0]);
    if (s[1] == ':' && c >= 'A' && c <= 'Z') {
      f_1000_09a2(f_1000_0e30((int)c) - 0x41);
    }
  }
}

/* 3381:023c */
void __cdecl16far f_3381_023c(void)
{
  *(uint16_t far *)MK_FP(0x280, 0x432) = 1;
}

/* 3381:01c8 */
void __cdecl16far f_3381_01c8(void)
{
  f_1000_2568((char far *)MK_FP(0x280, 0x8c28), 0x44);
  f_1000_2d31((char far *)MK_FP(0x280, 0x8c6c),
              (char far *)MK_FP(0x280, 0x8c28));
  f_3381_0132((char far *)MK_FP(0x280, 0x8c6c));
  f_1000_2cc2((char far *)MK_FP(0x280, 0x8c6c),
              (char far *)GSaveFileName);
  f_3381_016c(f_3381_00fe(
      f_3381_009a(*(char far * far *)&GGameExeP, EMPTY_5BB)));
}

/* 3381:1fa9 */
void __cdecl16far f_3381_1fa9(void)
{
  *(undefined2 far *)MK_FP(0x280, 0x9097) = 0;
}

void __cdecl16far f_3381_1fba(void)
{
  asm db 056h,033h,0F6h,0EBh,01Dh,08Bh,0DEh,0C1h,0E3h,002h,0B8h,070h,000h,08Eh,0C0h,026h
  asm db 0FFh,0B7h,002h,000h,026h,0FFh,0B7h,000h,000h,09Ah,070h,000h,070h,001h,083h,0C4h
  asm db 004h,046h,0B8h,080h,002h,08Eh,0C0h,026h,0A0h,0E6h,090h,0B4h,000h,03Bh,0C6h,07Fh
  asm db 0D4h,0B8h,080h,002h,08Eh,0C0h,026h,0C6h,006h,0E6h,090h,000h,0B8h,080h,002h,08Eh
  asm db 0C0h,026h,0A1h,0E3h,007h,026h,00Bh,006h,0E5h,007h,074h,017h,0B8h,080h,002h,08Eh
  asm db 0C0h,026h,0FFh,036h,0E5h,007h,026h,0FFh,036h,0E3h,007h,09Ah,070h,000h,070h,001h
  asm db 083h,0C4h,004h,0B8h,080h,002h,08Eh,0C0h,026h,0A1h,0E7h,007h,026h,00Bh,006h,0E9h
  asm db 007h,074h,017h,0B8h,080h,002h,08Eh,0C0h,026h,0FFh,036h,0E9h,007h,026h,0FFh,036h
  asm db 0E7h,007h,09Ah,070h,000h,070h,001h,083h,0C4h,004h,0B8h,080h,002h,08Eh,0C0h,026h
  asm db 0A1h,005h,01Dh,026h,00Bh,006h,007h,01Dh,074h,017h,0B8h,080h,002h,08Eh,0C0h,026h
  asm db 0FFh,036h,007h,01Dh,026h,0FFh,036h,005h,01Dh,09Ah,070h,000h,070h,001h,083h,0C4h
  asm db 004h,0B8h,080h,002h,08Eh,0C0h,026h,0C7h,006h,007h,01Dh,000h,000h,026h,0C7h,006h
  asm db 005h,01Dh,000h,000h,0B8h,080h,002h,08Eh,0C0h,026h,0C7h,006h,0E5h,007h,000h,000h
  asm db 026h,0C7h,006h,0E3h,007h,000h,000h,0B8h,080h,002h,08Eh,0C0h,026h,0C7h,006h,0E9h
  asm db 007h,000h,000h,026h,0C7h,006h,0E7h,007h,000h,000h,09Ah,06Bh,000h,070h,001h,0B8h
  asm db 080h,002h,08Eh,0C0h,026h,0A1h,034h,004h,026h,00Bh,006h,036h,004h,074h,017h,0B8h
  asm db 080h,002h,08Eh,0C0h,026h,0FFh,036h,036h,004h,026h,0FFh,036h,034h,004h,09Ah,070h
  asm db 000h,070h,001h,083h,0C4h,004h,0B8h,080h,002h,08Eh,0C0h,026h,0C7h,006h,036h,004h
  asm db 000h,000h,026h,0C7h,006h,034h,004h,000h,000h,09Ah,039h,000h,028h,001h,05Eh
}

/* 3381:20ee */
void __cdecl16far f_3381_20ee(void)
{
  f_1400_0039(1);
  f_3381_1fba();
}

typedef char maprow[0x94];
typedef uint16_t mapfrow[0x94];

/* 3381:233e */
char __cdecl16far f_3381_233e(register int x, register int y)
{
  if (x >= 0x94 || x < 0 || y >= 0x3c || y < 0) {
    return 0;
  }
  asm db 8Bh,0C7h
  asm mov dx,0x94
  asm imul dx
  asm mov dx,0x280
  asm mov es,dx
  asm db 26h,0C4h,1Eh,05h,08Ah
  asm db 03h,0D8h
  asm db 26h,08Ah,00h
  return;
}

/* 3381:237a */
void __cdecl16far f_3381_237a(register int x, register int y, char v)
{
  if (x >= 0x94 || x < 0 || y >= 0x3c || y < 0) {
    return;
  }
  asm db 8Bh,0C7h
  asm mov dx,0x94
  asm imul dx
  asm mov dx,0x280
  asm mov es,dx
  asm db 26h,0C4h,1Eh,05h,08Ah
  asm db 03h,0D8h
  asm db 8Ah,46h,0Ah
  asm db 26h,88h,00h
}

/* 3381:23b5 */
char __cdecl16far f_3381_23b5(register int x, register int y)
{
  if (x >= 0x94 || x < 0 || y >= 0x3c || y < 0) {
    return 0;
  }
  asm db 8Bh,0C7h
  asm mov dx,0x128
  asm imul dx
  asm mov dx,0x280
  asm mov es,dx
  asm db 26h,0C4h,1Eh,09h,08Ah
  asm db 03h,0D8h
  asm db 8Bh,0C6h
  asm db 0D1h,0E0h
  asm db 03h,0D8h
  asm db 26h,08Ah,07h
  asm db 24h,03h
  return;
}
/* 3381:23f9 */
int __cdecl16far f_3381_23f9(int x, int y)
{
  return (unsigned char)f_3381_233e(x, y)
       + (unsigned char)f_3381_233e(x + 1, y)
       + (unsigned char)f_3381_233e(x, y + 1)
       + (unsigned char)f_3381_233e(x + 1, y + 1);
}







/* 3381:2e9a */
void __cdecl16far f_3381_2e9a(char far *p)
{
  int i;
  int j;

  if (p == 0) {
    return;
  }
  i = 0;
  j = 0;
  while (p[i] != 0) {
    if (p[i] != ' ') {
      p[j] = (char)f_1000_0e04((int)p[i]);
      j++;
    }
    i++;
  }
  p[j] = 0;
}

/* 3381:1697 */
void __cdecl16far f_3381_1697(void)
{
  asm db 033h,0C9h,0EBh,049h,08Bh,0C1h,0BAh,009h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h
  asm db 026h,0C4h,01Eh,095h,089h,003h,0D8h,08Ah,0C1h,026h,088h,007h,08Bh,0C1h,0BAh,009h
  asm db 000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,095h,089h,003h,0D8h,026h
  asm db 0C6h,047h,001h,0FFh,08Bh,0C1h,0BAh,009h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h
  asm db 026h,0C4h,01Eh,095h,089h,003h,0D8h,026h,0C6h,047h,002h,0FFh,041h,081h,0F9h,0F8h
  asm db 000h,07Ch,0B1h
}


void __cdecl16far f_3381_024d(void)
{
  volatile unsigned char pad[0x56];
  asm db 056h,057h,0A1h,0E6h,004h,089h,046h,0FCh,0C6h,046h,0FBh,000h,068h,080h,002h,068h
  asm db 06Ch,08Ch,01Eh,068h,0BCh,005h,016h
  asm lea ax,pad
  asm db 050h,09Ah,07Ah,000h,070h,001h,083h,0C4h,00Ch,052h,050h,09Ah,066h,000h,070h,001h
  asm db 083h,0C4h,004h,08Bh,0F8h,00Bh,0FFh,07Dh,00Bh,068h,080h,000h,09Ah,020h,000h,008h
  asm db 001h,083h,0C4h,002h,057h,09Ah,025h,000h,0E0h,001h,083h,0C4h,002h,088h,046h,0FFh
  asm db 08Ah,046h,0FFh,098h,00Bh,0C0h,075h,00Bh,068h,080h,000h,09Ah,020h,000h,008h,001h
  asm db 083h,0C4h,002h,080h,07Eh,0FFh,031h,07Ch,00Eh,080h,07Eh,0FFh,039h,07Fh,008h,08Ah
  asm db 046h,0FFh,0A2h,027h,08Ch,0EBh,03Dh,080h,07Eh,0FFh,041h,07Ch,00Eh,080h,07Eh,0FFh
  asm db 042h,07Fh,008h,08Ah,046h,0FFh,0A2h,027h,08Ch,0EBh,029h,080h,07Eh,0FFh,061h,07Ch
  asm db 018h,080h,07Eh,0FFh,062h,07Fh,012h,08Ah,046h,0FFh,098h,050h,09Ah,030h,00Eh,000h
  asm db 000h,083h,0C4h,002h,0A2h,027h,08Ch,0EBh,00Bh,068h,080h,000h,09Ah,020h,000h,008h
  asm db 001h,083h,0C4h,002h,057h,09Ah,025h,000h,0E0h,001h,083h,0C4h,002h,088h,046h,0FFh
  asm db 08Ah,046h,0FFh,098h,00Bh,0C0h,075h,00Bh,068h,080h,000h,09Ah,020h,000h,008h,001h
  asm db 083h,0C4h,002h,080h,07Eh,0FFh,031h,07Ch,00Eh,080h,07Eh,0FFh,039h,07Fh,008h,08Ah
  asm db 046h,0FFh,0A2h,026h,08Ch,0EBh,03Dh,080h,07Eh,0FFh,041h,07Ch,00Eh,080h,07Eh,0FFh
  asm db 042h,07Fh,008h,08Ah,046h,0FFh,0A2h,026h,08Ch,0EBh,029h,080h,07Eh,0FFh,061h,07Ch
  asm db 018h,080h,07Eh,0FFh,062h,07Fh,012h,08Ah,046h,0FFh,098h,050h,09Ah,030h,00Eh,000h
  asm db 000h,083h,0C4h,002h,0A2h,026h,08Ch,0EBh,00Bh,068h,080h,000h,09Ah,020h,000h,008h
  asm db 001h,083h,0C4h,002h,057h,09Ah,025h,000h,0E0h,001h,083h,0C4h,002h,088h,046h,0FFh
  asm db 08Ah,046h,0FFh,098h,00Bh,0C0h,075h,00Bh,068h,080h,000h,09Ah,020h,000h,008h,001h
  asm db 083h,0C4h,002h,080h,07Eh,0FFh,030h,07Ch,006h,080h,07Eh,0FFh,039h,07Eh,00Ch,080h
  asm db 07Eh,0FFh,041h,07Ch,00Eh,080h,07Eh,0FFh,046h,07Fh,008h,08Ah,046h,0FFh,0A2h,025h
  asm db 08Ch,0EBh,00Bh,068h,080h,000h,09Ah,020h,000h,008h,001h,083h,0C4h,002h,057h,09Ah
  asm db 025h,000h,0E0h,001h,083h,0C4h,002h,088h,046h,0FEh,080h,07Eh,0FEh,031h,07Ch,02Ah
  asm db 080h,07Eh,0FEh,032h,07Fh,024h,080h,07Eh,0FEh,031h,075h,00Eh,0B8h,080h,002h,08Eh
  asm db 0C0h,026h,0C7h,006h,032h,004h,001h,000h,0EBh,02Dh,0B8h,080h,002h,08Eh,0C0h,026h
  asm db 0C7h,006h,032h,004h,000h,000h,0EBh,01Fh,0EBh,01Dh,00Eh,0E8h,041h,0FEh,0C6h,046h
  asm db 0FBh,001h,0C6h,046h,0FEh,032h,0B8h,080h,002h,08Eh,0C0h,026h,083h,03Eh,032h,004h
  asm db 000h,074h,004h,0C6h,046h,0FEh,031h,057h,09Ah,025h,022h,000h,000h,083h,0C4h,002h
  asm db 080h,07Eh,0FBh,000h,075h,003h,0E9h,04Fh,001h,068h,080h,002h,068h,06Ch,08Ch,01Eh
  asm db 068h,0BCh,005h,016h,08Dh,046h,0AAh,050h,09Ah,07Ah,000h,070h,001h,083h,0C4h,00Ch
  asm db 052h,050h,09Ah,061h,000h,070h,001h,083h,0C4h,004h,08Bh,0F0h,00Bh,0F6h,07Dh,00Bh
  asm db 068h,083h,000h,09Ah,020h,000h,008h,001h,083h,0C4h,002h,06Ah,001h,068h,080h,002h
  asm db 068h,027h,08Ch,056h,09Ah,0A8h,02Fh,000h,000h,083h,0C4h,008h,03Dh,001h,000h,074h
  asm db 005h,0B8h,001h,000h,0EBh,002h,033h,0C0h,088h,046h,0FAh,06Ah,002h,016h,08Dh,046h
  asm db 0FCh,050h,056h,09Ah,0A8h,02Fh,000h,000h,083h,0C4h,008h,03Dh,002h,000h,074h,005h
  asm db 0B8h,001h,000h,0EBh,002h,033h,0C0h,008h,046h,0FAh,06Ah,001h,068h,080h,002h,068h
  asm db 026h,08Ch,056h,09Ah,0A8h,02Fh,000h,000h,083h,0C4h,008h,03Dh,001h,000h,074h,005h
  asm db 0B8h,001h,000h,0EBh,002h,033h,0C0h,088h,046h,0FAh,06Ah,002h,016h,08Dh,046h,0FCh
  asm db 050h,056h,09Ah,0A8h,02Fh,000h,000h,083h,0C4h,008h,03Dh,002h,000h,074h,005h,0B8h
  asm db 001h,000h,0EBh,002h,033h,0C0h,008h,046h,0FAh,06Ah,001h,068h,080h,002h,068h,025h
  asm db 08Ch,056h,09Ah,0A8h,02Fh,000h,000h,083h,0C4h,008h,03Dh,001h,000h,074h,005h,0B8h
  asm db 001h,000h,0EBh,002h,033h,0C0h,088h,046h,0FAh,06Ah,002h,016h,08Dh,046h,0FCh,050h
  asm db 056h,09Ah,0A8h,02Fh,000h,000h,083h,0C4h,008h,03Dh,002h,000h,074h,005h,0B8h,001h
  asm db 000h,0EBh,002h,033h,0C0h,008h,046h,0FAh,06Ah,001h,016h,08Dh,046h,0FEh,050h,056h
  asm db 09Ah,0A8h,02Fh,000h,000h,083h,0C4h,008h,03Dh,001h,000h,074h,005h,0B8h,001h,000h
  asm db 0EBh,002h,033h,0C0h,008h,046h,0FAh,06Ah,002h,016h,08Dh,046h,0FCh,050h,056h,09Ah
  asm db 0A8h,02Fh,000h,000h,083h,0C4h,008h,03Dh,002h,000h,074h,005h,0B8h,001h,000h,0EBh
  asm db 002h,033h,0C0h,008h,046h,0FAh,056h,09Ah,025h,022h,000h,000h,083h,0C4h,002h,008h
  asm db 046h,0FAh,080h,07Eh,0FAh,000h,074h,00Bh,068h,080h,000h,09Ah,020h,000h,008h,001h
  asm db 083h,0C4h,002h,09Ah,0E9h,013h,000h,000h,05Fh,05Eh
}
void __cdecl16far f_3381_2d9e(void)
{
  volatile unsigned char pad[0x14];
  asm db 056h,057h
  asm lea ax,pad
  asm db 016h,050h,01Eh,068h,00Eh,005h,0B9h,00Bh,000h,09Ah,04Fh,009h,000h,000h,0A1h,00Ah
  asm db 005h,00Bh,006h,00Ch,005h,075h,014h,06Ah,000h,068h,000h,001h,09Ah,043h,000h,070h
  asm db 001h,083h,0C4h,004h,089h,016h,00Ch,005h,0A3h,00Ah,005h,0B8h,080h,002h,08Eh,0C0h
  asm db 026h,0FFh,036h,0D2h,090h,026h,0FFh,036h,0D0h,090h,09Ah,020h,000h,070h,001h,083h
  asm db 0C4h,004h,089h,056h,0FAh,089h,046h,0F8h,08Bh,046h,0FAh,08Bh,056h,0F8h,089h,046h
  asm db 0FEh,089h,056h,0FCh,0C4h,01Eh,00Ah,005h,026h,0C6h,007h,000h,0BEh,001h,000h,0E9h
  asm db 082h,000h,08Bh,0C6h,0D1h,0E0h,003h,0C6h,0C4h,05Eh,0FCh,003h,0D8h,026h,08Ah,007h
  asm db 0B4h,000h,08Bh,0F8h,08Bh,0DEh,0D1h,0E3h,003h,0DEh,08Eh,046h,0FEh,003h,05Eh,0FCh
  asm db 026h,08Ah,047h,001h,0B4h,000h,03Bh,0C7h,076h,014h,08Bh,0DEh,0D1h,0E3h,003h,0DEh
  asm db 08Eh,046h,0FEh,003h,05Eh,0FCh,026h,08Ah,047h,001h,0B4h,000h,08Bh,0F8h,08Bh,0DEh
  asm db 0D1h,0E3h,003h,0DEh,08Eh,046h,0FEh,003h,05Eh,0FCh,026h,08Ah,047h,002h,0B4h,000h
  asm db 03Bh,0C7h,076h,014h,08Bh,0DEh,0D1h,0E3h,003h,0DEh,08Eh,046h,0FEh,003h,05Eh,0FCh
  asm db 026h,08Ah,047h,002h,0B4h,000h,08Bh,0F8h,08Bh,0C7h,0BAh,00Bh,000h,0F7h,0EAh,0C1h
  asm db 0E8h,006h,08Dh,056h,0ECh,003h,0C2h,08Bh,0D8h,036h,08Ah,007h,0C4h,01Eh,00Ah,005h
  asm db 026h,088h,000h,046h,081h,0FEh,000h,001h,07Dh,003h,0E9h,075h,0FFh,05Fh,05Eh
}
void __cdecl16far f_3381_17e8(void) { }
char far * __cdecl16far f_474a_075a(int, int);
void __cdecl16far f_1000_2642(char far *, int, int);
void __cdecl16far f_3381_16ef(void)
{
  *(char far * far *)MK_FP(0x280, 0x8995) = f_474a_075a(0x2a30, 0);
  f_1000_2642(*(char far * far *)MK_FP(0x280, 0x8995), 0x2a30, 0);
  f_3381_1697();
  *(undefined2 far *)MK_FP(0x280, 0x8999) = 0xf8;
  *(char far * far *)MK_FP(0x280, 0x8a0d) = f_474a_075a(0x4560, 0);
  *(char far * far *)MK_FP(0x280, 0x8a09) = f_474a_075a(0x4560, 0);
  *(char far * far *)MK_FP(0x280, 0x8a05) = f_474a_075a(0x22b0, 0);
  *(char far * far *)MK_FP(0x280, 0x908e) = f_474a_075a(0x80e8, 0);
  *(char far * far *)MK_FP(0x280, 0x91e8) = f_474a_075a(0x6541, 0);
  asm nop
  f_3381_17e8();
  *(undefined1 far *)MK_FP(0x280, 0x90e6) = 0;
  *(undefined1 far *)MK_FP(0x280, 0x909b) = 0;
  *(undefined1 far *)MK_FP(0x280, 0x9016) = 0xff;
}

void __cdecl16far f_1403_0ab2(int, int, int, int);
void __cdecl16far f_1403_08e8(int, int, int);
void __cdecl16far f_6257_046a(void);
void __cdecl16far f_1000_13e9(void);
void __cdecl16far f_1000_0730(far_t);
int  __cdecl16far f_1000_2d01(far_t, char far *);
int  __cdecl16far f_1700_002a(int);
void __cdecl16far f_1700_0034(void);
void __cdecl16far f_6ffe_02f7(int);
void __cdecl16far f_474a_0470(void);
void __cdecl16far f_3381_17e8(void);
void __cdecl16far f_474a_0a10(void);
void __cdecl16far f_3a5b_081e(void);
void __cdecl16far f_3a5b_0956(void);
void __cdecl16far f_317e_11f0(void);
void __cdecl16far f_3338_034a(void);
void __cdecl16far f_2d63_0016(int);
void __cdecl16far f_4b0a_1150(void);
void __cdecl16far f_6316_00b1(void);
void __cdecl16far f_3a5b_0633(int, int);

/* 3381:0579 */
void __cdecl16far f_3381_0579(void)
{
  f_1403_0ab2(0, 0, 0, 0);
  f_1403_08e8(0, 0, 0);
  f_6257_046a();
  f_3381_01c8();
  f_3381_024d();
  f_1000_13e9();
  f_1000_0730(**(far_t far * far *)MK_FP(0x280, 0x15b));
  f_474a_075a(0xfa0f, 0);
  if (f_1000_2d01(*(far_t far *)MK_FP(0x280, 0x8972),
                  (char far *)s_debug_2410_05c7) == 0) {
    *(bool far *)MK_FP(0x280, 0x43a) = 1;
  }
  if (f_1000_2d01(*(far_t far *)MK_FP(0x280, 0x8972),
                  (char far *)s_grab_2410_05cd) == 0) {
    *(bool far *)MK_FP(0x280, 0x43a) = 1;
    f_6ffe_02f7(1);
  }
  else {
    f_6ffe_02f7(0);
  }
  f_474a_0470();
  StshStrongDatHnd = f_1700_002a(0);
  f_3a5b_081e();
  f_3a5b_0956();
  f_317e_11f0();
  f_3338_034a();
  f_2d63_0016(0x13);
  asm nop
  f_3381_2d9e();
  f_4b0a_1150();
  asm nop
  f_3381_16ef();
  f_474a_0a10();
  f_6316_00b1();
  f_3a5b_0633(0x53, 0);
}




void __cdecl16far f_118_002a(far_t, int, int);
void __cdecl16far f_118_0034(far_t, int, int, char far *, int, int);

void __cdecl16far f_3381_0000(void)
{
  f_118_002a(*(far_t far *)MK_FP(0x280, 0x89cd), 0, 0xa000);
  f_118_002a(*(far_t far *)MK_FP(0x280, 0x909f), 0x9af, 0xa000);
  f_118_0034(*(far_t far *)MK_FP(0x280, 0x90a3), 0, 0,
             (char far *)MK_FP(0x280, 0x44a), 0x10, 0);
  if (!GameRunning) {
    f_118_002a(*(far_t far *)MK_FP(0x280, 0x89f1), 0xc51d, 0xa000);
    *(unsigned char far *)MK_FP(0x280, 0x9016) = 0;
  }
}


char __cdecl16far f_3381_2452(register int x, register int y, unsigned char dir)
{
  volatile unsigned char i;

  for (i = 0; i < 4; i++) {
    if (i != (dir ^ 2)) {
      if (f_3381_23b5(x + (char)*(unsigned char far *)MK_FP(0x280, 0x885 + i),
                      y + (char)*(unsigned char far *)MK_FP(0x280, 0x889 + i))) {
        return 0;
      }
    }
  }
  return 1;
}

char __cdecl16far f_3381_1f1d(int x, int y)
{
  asm db 056h,057h,08Bh,076h,006h,08Bh,07Eh,008h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh
  asm db 080h,002h,08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah,003h,0D8h,026h,080h,038h,000h,074h
  asm db 062h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh
  asm db 005h,08Ah,003h,0D8h,026h,080h,078h,001h,000h,074h,048h,08Bh,0C7h,0BAh,094h,000h
  asm db 0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,08Bh,016h,007h,08Ah,026h,003h,006h,005h
  asm db 08Ah,08Bh,0D8h,08Eh,0C2h,026h,080h,0B8h,094h,000h,000h,074h,026h,08Bh,0C7h,0BAh
  asm db 094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,08Bh,016h,007h,08Ah,026h,003h
  asm db 006h,005h,08Ah,08Bh,0D8h,08Eh,0C2h,026h,080h,0B8h,094h,000h,000h,074h,004h,0B0h
  asm db 001h,0EBh,002h,0B0h,000h,05Fh,05Eh
  return;
}

void __cdecl16far f_3381_2d36(void)
{
  volatile unsigned char k;
  asm db 056h,057h,033h,0FFh,0EBh,052h,033h,0F6h,0EBh,048h,0C6h,046h,0FFh,000h,0EBh,03Bh
  asm mov al,k
  asm db 050h,056h,057h,09Ah,048h,000h,0A0h,001h,083h,0C4h,006h,00Ah,0C0h,074h,026h,0B8h
  asm db 010h,000h,08Ah,04Eh,0FFh,0D3h,0E0h,050h,08Bh,0C6h,0BAh,028h,001h,0F7h,0EAh,0BAh
  asm db 080h,002h,08Eh,0C2h,026h,0C4h,01Eh,009h,08Ah,003h,0D8h,08Bh,0C7h,0D1h,0E0h,003h
  asm db 0D8h,058h,026h,009h,007h,0FEh,046h,0FFh,080h,07Eh,0FFh,004h,072h,0BFh,046h,083h
  asm db 0FEh,03Ch,07Ch,0B3h,047h,081h,0FFh,094h,000h,07Ch,0A8h,05Fh,05Eh
}

void __cdecl16far f_3381_0693(void)
{
  asm db 056h,057h,033h,0FFh,0E9h,033h,002h,033h,0F6h,0E9h,024h,002h,08Bh,0C7h,0BAh,028h
  asm db 001h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,009h,08Ah,003h,0D8h,08Bh
  asm db 0C6h,0D1h,0E0h,003h,0D8h,026h,0F7h,007h,004h,000h,075h,003h,0E9h,008h,001h,08Bh
  asm db 0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,08Bh,016h,007h,08Ah
  asm db 026h,003h,006h,005h,08Ah,08Bh,0D8h,08Eh,0C2h,026h,08Ah,080h,094h,000h,098h,00Bh
  asm db 0C0h,075h,054h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h
  asm db 0C4h,01Eh,005h,08Ah,003h,0D8h,026h,08Ah,040h,001h,098h,00Bh,0C0h,075h,038h,08Bh
  asm db 0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah
  asm db 003h,0D8h,026h,08Ah,000h,098h,00Bh,0C0h,075h,01Dh,08Bh,0C7h,0BAh,028h,001h,0F7h
  asm db 0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,009h,08Ah,003h,0D8h,08Bh,0C6h,0D1h
  asm db 0E0h,003h,0D8h,026h,083h,00Fh,001h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h
  asm db 002h,08Eh,0C2h,026h,08Bh,016h,007h,08Ah,026h,003h,006h,005h,08Ah,08Bh,0D8h,08Eh
  asm db 0C2h,026h,08Ah,080h,094h,000h,098h,00Bh,0C0h,074h,003h,0E9h,061h,001h,08Bh,0C7h
  asm db 0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah,003h
  asm db 0D8h,026h,08Ah,040h,001h,098h,00Bh,0C0h,074h,003h,0E9h,042h,001h,08Bh,0C7h,0BAh
  asm db 094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,08Bh,016h,007h,08Ah,026h,003h
  asm db 006h,005h,08Ah,08Bh,0D8h,08Eh,0C2h,026h,08Ah,080h,095h,000h,098h,00Bh,0C0h,074h
  asm db 003h,0E9h,01Bh,001h,08Bh,0C7h,0BAh,028h,001h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h
  asm db 026h,0C4h,01Eh,009h,08Ah,003h,0D8h,08Bh,0C6h,0D1h,0E0h,003h,0D8h,026h,083h,00Fh
  asm db 002h,0E9h,0FBh,000h,0E9h,0F8h,000h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h
  asm db 002h,08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah,003h,0D8h,026h,08Ah,000h,098h,00Bh,0C0h
  asm db 075h,065h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,08Bh
  asm db 016h,007h,08Ah,026h,003h,006h,005h,08Ah,08Bh,0D8h,08Eh,0C2h,026h,08Ah,080h,095h
  asm db 000h,098h,00Bh,0C0h,075h,041h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h
  asm db 08Eh,0C2h,026h,08Bh,016h,007h,08Ah,026h,003h,006h,005h,08Ah,08Bh,0D8h,08Eh,0C2h
  asm db 026h,08Ah,080h,094h,000h,098h,00Bh,0C0h,075h,01Dh,08Bh,0C7h,0BAh,028h,001h,0F7h
  asm db 0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,009h,08Ah,003h,0D8h,08Bh,0C6h,0D1h
  asm db 0E0h,003h,0D8h,026h,083h,00Fh,001h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h
  asm db 002h,08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah,003h,0D8h,026h,08Ah,000h,098h,00Bh,0C0h
  asm db 075h,05Dh,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,08Bh
  asm db 016h,007h,08Ah,026h,003h,006h,005h,08Ah,08Bh,0D8h,08Eh,0C2h,026h,08Ah,080h,095h
  asm db 000h,098h,00Bh,0C0h,075h,039h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h
  asm db 08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah,003h,0D8h,026h,08Ah,040h,001h,098h,00Bh,0C0h
  asm db 075h,01Dh,08Bh,0C7h,0BAh,028h,001h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h
  asm db 01Eh,009h,08Ah,003h,0D8h,08Bh,0C6h,0D1h,0E0h,003h,0D8h,026h,083h,00Fh,002h,046h
  asm db 081h,0FEh,093h,000h,07Dh,003h,0E9h,0D3h,0FDh,047h,083h,0FFh,03Bh,07Dh,003h,0E9h
  asm db 0C5h,0FDh,05Fh,05Eh
}

void __cdecl16far f_3381_08dc(void)
{
  volatile unsigned char pad[0xa2];
  asm db 056h,057h
  asm mov byte ptr pad[0x95],0
  asm db 033h,0F6h,0EBh,04Eh,06Ah,00Ah,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,0B4h,000h
  asm db 00Bh,0C0h,075h,028h,06Ah,002h,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,0D0h,0E0h
  asm db 002h,046h,0F3h,0FEh,0C8h,088h,046h,0F3h,080h,07Eh,0F3h,0FFh,07Dh,004h,0C6h,046h
  asm db 0F3h,0FFh,080h,07Eh,0F3h,001h,07Eh,004h,0C6h,046h,0F3h,001h,00Bh,0F6h,074h,006h
  asm db 081h,0FEh,093h,000h,075h,004h,0C6h,046h,0F3h,000h,08Ah,046h,0F3h,088h,082h,05Eh
  asm db 0FFh,046h,081h,0FEh,094h,000h,07Ch,0ACh,0C7h,046h,0F6h,000h,000h,0C7h,046h,0F8h
  asm db 000h,000h,06Ah,000h,068h,060h,045h,0B8h,080h,002h,08Eh,0C0h,026h,0FFh,036h,00Fh
  asm db 08Ah,026h,0FFh,036h,00Dh,08Ah,09Ah,042h,026h,000h,000h,083h,0C4h,008h,06Ah,000h
  asm db 068h,060h,045h,0B8h,080h,002h,08Eh,0C0h,026h,0FFh,036h,00Bh,08Ah,026h,0FFh,036h
  asm db 009h,08Ah,09Ah,042h,026h,000h,000h,083h,0C4h,008h,033h,0FFh,0E9h,074h,004h,0F7h
  asm db 0C7h,001h,000h,074h,003h,0E9h,034h,002h,033h,0F6h,0E9h,023h,002h,0C7h,046h,0F6h
  asm db 000h,000h,00Bh,0F6h,074h,01Bh,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h
  asm db 08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah,003h,0D8h,026h,08Ah,040h,0FFh,098h,089h,046h
  asm db 0F6h,00Bh,0FFh,074h,02Eh,08Ah,082h,05Eh,0FFh,098h,050h,08Bh,0C7h,0BAh,094h,000h
  asm db 0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,08Bh,016h,007h,08Ah,026h,003h,006h,005h
  asm db 08Ah,003h,0C6h,05Bh,003h,0C3h,08Bh,0D8h,08Eh,0C2h,026h,08Ah,087h,06Ch,0FFh,098h
  asm db 001h,046h,0F6h,08Bh,046h,0F6h,0D1h,0F8h,089h,046h,0F6h,00Bh,0F6h,074h,037h,08Ah
  asm db 082h,05Dh,0FFh,03Ah,082h,05Eh,0FFh,074h,02Dh,06Ah,008h,09Ah,05Ch,000h,070h,001h
  asm db 083h,0C4h,002h,0B4h,000h,089h,046h,0FAh,083h,07Eh,0FAh,001h,075h,00Ah,08Ah,082h
  asm db 05Dh,0FFh,088h,082h,05Eh,0FFh,0EBh,00Eh,083h,07Eh,0FAh,002h,075h,008h,08Ah,082h
  asm db 05Eh,0FFh,088h,082h,05Dh,0FFh,06Ah,010h,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h
  asm db 0B4h,000h,00Bh,0C0h,074h,003h,0E9h,0CEh,000h,00Bh,0F6h,074h,036h,08Ah,082h,05Dh
  asm db 0FFh,088h,046h,0F3h,06Ah,002h,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,0D0h,0E0h
  asm db 002h,046h,0F3h,0FEh,0C8h,088h,046h,0F3h,080h,07Eh,0F3h,0FFh,07Dh,004h,0C6h,046h
  asm db 0F3h,0FFh,080h,07Eh,0F3h,001h,07Eh,004h,0C6h,046h,0F3h,001h,08Ah,046h,0F3h,088h
  asm db 082h,05Eh,0FFh,083h,07Eh,0F6h,055h,07Eh,014h,06Ah,011h,09Ah,05Ch,000h,070h,001h
  asm db 083h,0C4h,002h,0B4h,000h,005h,0F8h,0FFh,089h,046h,0F8h,0EBh,07Ah,083h,07Eh,0F6h
  asm db 040h,07Eh,014h,06Ah,008h,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,0B4h,000h,005h
  asm db 0FCh,0FFh,089h,046h,0F8h,0EBh,060h,083h,07Eh,0F6h,02Ah,07Eh,014h,06Ah,00Bh,09Ah
  asm db 05Ch,000h,070h,001h,083h,0C4h,002h,0B4h,000h,005h,0FBh,0FFh,089h,046h,0F8h,0EBh
  asm db 046h,083h,07Eh,0F6h,015h,07Eh,014h,06Ah,010h,09Ah,05Ch,000h,070h,001h,083h,0C4h
  asm db 002h,0B4h,000h,005h,0F8h,0FFh,089h,046h,0F8h,0EBh,02Ch,083h,07Eh,0F6h,000h,07Eh
  asm db 014h,06Ah,008h,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,0B4h,000h,005h,0FBh,0FFh
  asm db 089h,046h,0F8h,0EBh,012h,06Ah,009h,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,0B4h
  asm db 000h,005h,0FEh,0FFh,089h,046h,0F8h,083h,07Eh,0F6h,055h,07Eh,007h,0C7h,046h,0F4h
  asm db 009h,000h,0EBh,039h,083h,07Eh,0F6h,040h,07Eh,007h,0C7h,046h,0F4h,013h,000h,0EBh
  asm db 02Ch,083h,07Eh,0F6h,02Ah,07Eh,007h,0C7h,046h,0F4h,005h,000h,0EBh,01Fh,083h,07Eh
  asm db 0F6h,015h,07Eh,007h,0C7h,046h,0F4h,00Fh,000h,0EBh,012h,083h,07Eh,0F6h,000h,07Eh
  asm db 007h,0C7h,046h,0F4h,005h,000h,0EBh,005h,0C7h,046h,0F4h,00Bh,000h,0FFh,076h,0F4h
  asm db 09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,0B4h,000h,08Bh,056h,0F4h,0D1h,0FAh,02Bh
  asm db 0C2h,003h,046h,0F8h,040h,001h,046h,0F6h,083h,07Eh,0F6h,0DDh,07Dh,010h,0C7h,046h
  asm db 0F6h,0DDh,0FFh,08Bh,046h,0F8h,099h,033h,0C2h,02Bh,0C2h,089h,046h,0F8h,083h,07Eh
  asm db 0F6h,07Fh,07Eh,012h,0C7h,046h,0F6h,07Fh,000h,08Bh,046h,0F8h,099h,033h,0C2h,02Bh
  asm db 0C2h,0F7h,0D8h,089h,046h,0F8h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h
  asm db 08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah,003h,0D8h,08Ah,046h,0F6h,026h,088h,000h,046h
  asm db 081h,0FEh,094h,000h,07Dh,003h,0E9h,0D4h,0FDh,0E9h,036h,002h,0BEh,093h,000h,0E9h
  asm db 029h,002h,0C7h,046h,0F6h,000h,000h,081h,0FEh,093h,000h,074h,01Bh,08Bh,0C7h,0BAh
  asm db 094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah,003h,0D8h
  asm db 026h,08Ah,040h,001h,098h,089h,046h,0F6h,00Bh,0FFh,074h,02Eh,08Ah,082h,05Eh,0FFh
  asm db 098h,050h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,08Bh
  asm db 016h,007h,08Ah,026h,003h,006h,005h,08Ah,003h,0C6h,05Bh,003h,0C3h,08Bh,0D8h,08Eh
  asm db 0C2h,026h,08Ah,087h,06Ch,0FFh,098h,001h,046h,0F6h,08Bh,046h,0F6h,0D1h,0F8h,089h
  asm db 046h,0F6h,081h,0FEh,093h,000h,074h,037h,08Ah,082h,05Fh,0FFh,03Ah,082h,05Eh,0FFh
  asm db 074h,02Dh,06Ah,010h,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,0B4h,000h,089h,046h
  asm db 0FAh,083h,07Eh,0FAh,001h,075h,00Ah,08Ah,082h,05Fh,0FFh,088h,082h,05Eh,0FFh,0EBh
  asm db 00Eh,083h,07Eh,0FAh,002h,075h,008h,08Ah,082h,05Eh,0FFh,088h,082h,05Fh,0FFh,06Ah
  asm db 010h,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,0B4h,000h,00Bh,0C0h,074h,003h,0E9h
  asm db 0D0h,000h,081h,0FEh,093h,000h,074h,036h,08Ah,082h,05Fh,0FFh,088h,046h,0F3h,06Ah
  asm db 002h,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,0D0h,0E0h,002h,046h,0F3h,0FEh,0C8h
  asm db 088h,046h,0F3h,080h,07Eh,0F3h,0FFh,07Dh,004h,0C6h,046h,0F3h,0FFh,080h,07Eh,0F3h
  asm db 001h,07Eh,004h,0C6h,046h,0F3h,001h,08Ah,046h,0F3h,088h,082h,05Eh,0FFh,083h,07Eh
  asm db 0F6h,055h,07Eh,014h,06Ah,011h,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,0B4h,000h
  asm db 005h,0F8h,0FFh,089h,046h,0F8h,0EBh,07Ah,083h,07Eh,0F6h,040h,07Eh,014h,06Ah,008h
  asm db 09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,0B4h,000h,005h,0FCh,0FFh,089h,046h,0F8h
  asm db 0EBh,060h,083h,07Eh,0F6h,02Ah,07Eh,014h,06Ah,00Bh,09Ah,05Ch,000h,070h,001h,083h
  asm db 0C4h,002h,0B4h,000h,005h,0FBh,0FFh,089h,046h,0F8h,0EBh,046h,083h,07Eh,0F6h,015h
  asm db 07Eh,014h,06Ah,010h,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,0B4h,000h,005h,0F8h
  asm db 0FFh,089h,046h,0F8h,0EBh,02Ch,083h,07Eh,0F6h,000h,07Eh,014h,06Ah,008h,09Ah,05Ch
  asm db 000h,070h,001h,083h,0C4h,002h,0B4h,000h,005h,0FBh,0FFh,089h,046h,0F8h,0EBh,012h
  asm db 06Ah,009h,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,0B4h,000h,005h,0FEh,0FFh,089h
  asm db 046h,0F8h,083h,07Eh,0F6h,055h,07Eh,007h,0C7h,046h,0F4h,009h,000h,0EBh,039h,083h
  asm db 07Eh,0F6h,040h,07Eh,007h,0C7h,046h,0F4h,013h,000h,0EBh,02Ch,083h,07Eh,0F6h,02Ah
  asm db 07Eh,007h,0C7h,046h,0F4h,005h,000h,0EBh,01Fh,083h,07Eh,0F6h,015h,07Eh,007h,0C7h
  asm db 046h,0F4h,00Fh,000h,0EBh,012h,083h,07Eh,0F6h,000h,07Eh,007h,0C7h,046h,0F4h,005h
  asm db 000h,0EBh,005h,0C7h,046h,0F4h,00Bh,000h,0FFh,076h,0F4h,09Ah,05Ch,000h,070h,001h
  asm db 083h,0C4h,002h,0B4h,000h,08Bh,056h,0F4h,0D1h,0FAh,02Bh,0C2h,003h,046h,0F8h,040h
  asm db 001h,046h,0F6h,083h,07Eh,0F6h,081h,07Dh,010h,0C7h,046h,0F6h,081h,0FFh,08Bh,046h
  asm db 0F8h,099h,033h,0C2h,02Bh,0C2h,089h,046h,0F8h,083h,07Eh,0F6h,07Fh,07Eh,012h,0C7h
  asm db 046h,0F6h,07Fh,000h,08Bh,046h,0F8h,099h,033h,0C2h,02Bh,0C2h,0F7h,0D8h,089h,046h
  asm db 0F8h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh
  asm db 005h,08Ah,003h,0D8h,08Ah,046h,0F6h,026h,088h,000h,04Eh,00Bh,0F6h,07Ch,003h,0E9h
  asm db 0D0h,0FDh,047h,083h,0FFh,03Ch,07Dh,003h,0E9h,084h,0FBh,033h,0FFh,0E9h,0F5h,000h
  asm db 033h,0F6h,0E9h,0E6h,000h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh
  asm db 0C2h,026h,0C4h,01Eh,005h,08Ah,003h,0D8h,026h,080h,038h,000h,07Dh,017h,08Bh,0C7h
  asm db 0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah,003h
  asm db 0D8h,026h,0C6h,000h,000h,081h,0FEh,093h,000h,075h,003h,0E9h,0ACh,000h,083h,0FFh
  asm db 03Ch,075h,003h,0E9h,0A4h,000h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h
  asm db 08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah,003h,0D8h,026h,08Ah,040h,001h,098h,050h,08Bh
  asm db 0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,08Bh,016h,007h,08Ah
  asm db 026h,003h,006h,005h,08Ah,08Bh,0D8h,08Eh,0C2h,026h,08Ah,080h,094h,000h,098h,05Ah
  asm db 02Bh,0C2h,099h,033h,0C2h,02Bh,0C2h,050h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh
  asm db 080h,002h,08Eh,0C2h,026h,08Bh,016h,007h,08Ah,026h,003h,006h,005h,08Ah,08Bh,0D8h
  asm db 08Eh,0C2h,026h,08Ah,080h,095h,000h,098h,050h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh
  asm db 0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah,003h,0D8h,026h,08Ah,000h,098h
  asm db 05Ah,02Bh,0C2h,099h,033h,0C2h,02Bh,0C2h,05Ah,03Bh,0D0h,07Dh,01Dh,08Bh,0C7h,0BAh
  asm db 028h,001h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,009h,08Ah,003h,0D8h
  asm db 08Bh,0C6h,0D1h,0E0h,003h,0D8h,026h,083h,00Fh,004h,046h,081h,0FEh,094h,000h,07Dh
  asm db 003h,0E9h,011h,0FFh,047h,083h,0FFh,03Ch,07Dh,003h,0E9h,003h,0FFh,00Eh,0E8h,089h
  asm db 0F7h,090h,00Eh,0E8h,074h,019h,00Eh,0E8h,080h,0F7h,033h,0FFh,0E9h,01Fh,004h,033h
  asm db 0F6h,0E9h,010h,004h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h
  asm db 026h,0C4h,01Eh,005h,08Ah,003h,0D8h,026h,080h,038h,000h,075h,003h,0E9h,0F3h,003h
  asm db 08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,005h
  asm db 08Ah,003h,0D8h,026h,080h,078h,001h,000h,075h,003h,0E9h,0D6h,003h,08Bh,0C7h,0BAh
  asm db 094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,08Bh,016h,007h,08Ah,026h,003h
  asm db 006h,005h,08Ah,08Bh,0D8h,08Eh,0C2h,026h,080h,0B8h,094h,000h,000h,075h,003h,0E9h
  asm db 0B1h,003h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,08Bh
  asm db 016h,007h,08Ah,026h,003h,006h,005h,08Ah,08Bh,0D8h,08Eh,0C2h,026h,080h,0B8h,094h
  asm db 000h,000h,075h,003h,0E9h,08Ch,003h,057h,056h,090h,00Eh,0E8h,00Eh,014h,083h,0C4h
  asm db 004h,0B4h,000h,00Bh,0C0h,074h,003h,0E9h,079h,003h,08Bh,0C7h,0BAh,094h,000h,0F7h
  asm db 0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah,003h,0D8h,026h,08Ah,000h
  asm db 098h,089h,046h,0F6h,083h,07Eh,0F6h,06Ah,07Eh,066h,06Ah,004h,09Ah,05Ch,000h,070h
  asm db 001h,083h,0C4h,002h,0B4h,000h,03Dh,002h,000h,074h,00Eh,03Dh,003h,000h,074h,009h
  asm db 0E9h,040h,003h,0E9h,03Dh,003h,0E9h,03Ah,003h,057h,056h,09Ah,02Ah,000h,038h,001h
  asm db 083h,0C4h,004h,00Ah,0C0h,075h,003h,0E9h,029h,003h,06Ah,009h,09Ah,05Ch,000h,070h
  asm db 001h,083h,0C4h,002h,0B4h,000h,005h,067h,000h,050h,08Bh,0C6h,0BAh,078h,000h,0F7h
  asm db 0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,00Dh,08Ah,003h,0D8h,08Bh,0C7h,0D1h
  asm db 0E0h,003h,0D8h,058h,026h,089h,007h,0E9h,0F9h,002h,0E9h,0F6h,002h,0E9h,0F3h,002h
  asm db 083h,07Eh,0F6h,055h,07Fh,003h,0E9h,0EAh,000h,06Ah,004h,09Ah,05Ch,000h,070h,001h
  asm db 083h,0C4h,002h,0B4h,000h,03Dh,001h,000h,074h,00Eh,03Dh,003h,000h,075h,003h,0E9h
  asm db 08Ah,000h,0E9h,0CEh,002h,0E9h,0CBh,002h,057h,056h,09Ah,02Ah,000h,038h,001h,083h
  asm db 0C4h,004h,00Ah,0C0h,075h,003h,0E9h,0BAh,002h,06Ah,002h,09Ah,05Ch,000h,070h,001h
  asm db 083h,0C4h,002h,0B4h,000h,00Bh,0C0h,075h,030h,06Ah,006h,09Ah,05Ch,000h,070h,001h
  asm db 083h,0C4h,002h,0B4h,000h,005h,03Dh,000h,050h,08Bh,0C6h,0BAh,078h,000h,0F7h,0EAh
  asm db 0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,00Dh,08Ah,003h,0D8h,08Bh,0C7h,0D1h,0E0h
  asm db 003h,0D8h,058h,026h,089h,007h,0E9h,07Ah,002h,06Ah,009h,09Ah,05Ch,000h,070h,001h
  asm db 083h,0C4h,002h,0B4h,000h,005h,067h,000h,050h,08Bh,0C6h,0BAh,078h,000h,0F7h,0EAh
  asm db 0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,00Dh,08Ah,003h,0D8h,08Bh,0C7h,0D1h,0E0h
  asm db 003h,0D8h,058h,026h,089h,007h,0E9h,04Ah,002h,0E9h,047h,002h,057h,056h,09Ah,02Ah
  asm db 000h,038h,001h,083h,0C4h,004h,00Ah,0C0h,075h,003h,0E9h,036h,002h,06Ah,009h,09Ah
  asm db 05Ch,000h,070h,001h,083h,0C4h,002h,0B4h,000h,005h,067h,000h,050h,08Bh,0C6h,0BAh
  asm db 078h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,00Dh,08Ah,003h,0D8h
  asm db 08Bh,0C7h,0D1h,0E0h,003h,0D8h,058h,026h,089h,007h,0E9h,006h,002h,0E9h,003h,002h
  asm db 0E9h,000h,002h,083h,07Eh,0F6h,03Fh,07Eh,06Fh,06Ah,004h,09Ah,05Ch,000h,070h,001h
  asm db 083h,0C4h,002h,0B4h,000h,03Dh,003h,000h,074h,006h,0E9h,0E6h,001h,0E9h,0E3h,001h
  asm db 057h,056h,09Ah,02Ah,000h,038h,001h,083h,0C4h,004h,00Ah,0C0h,075h,003h,0E9h,0D2h
  asm db 001h,06Ah,002h,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,00Ah,0C0h,075h,003h,0E9h
  asm db 0C1h,001h,06Ah,009h,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,0B4h,000h,005h,067h
  asm db 000h,050h,08Bh,0C6h,0BAh,078h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h
  asm db 01Eh,00Dh,08Ah,003h,0D8h,08Bh,0C7h,0D1h,0E0h,003h,0D8h,058h,026h,089h,007h,0E9h
  asm db 091h,001h,0E9h,08Eh,001h,0E9h,08Bh,001h,083h,07Eh,0F6h,02Ah,07Fh,003h,0E9h,096h
  asm db 000h,06Ah,004h,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,0B4h,000h,03Dh,001h,000h
  asm db 074h,00Bh,03Dh,003h,000h,074h,039h,0E9h,069h,001h,0E9h,066h,001h,06Ah,006h,09Ah
  asm db 05Ch,000h,070h,001h,083h,0C4h,002h,0B4h,000h,005h,03Dh,000h,050h,08Bh,0C6h,0BAh
  asm db 078h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,00Dh,08Ah,003h,0D8h
  asm db 08Bh,0C7h,0D1h,0E0h,003h,0D8h,058h,026h,089h,007h,0E9h,036h,001h,0E9h,033h,001h
  asm db 057h,056h,09Ah,02Ah,000h,038h,001h,083h,0C4h,004h,00Ah,0C0h,075h,003h,0E9h,022h
  asm db 001h,06Ah,009h,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,0B4h,000h,005h,067h,000h
  asm db 050h,08Bh,0C6h,0BAh,078h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh
  asm db 00Dh,08Ah,003h,0D8h,08Bh,0C7h,0D1h,0E0h,003h,0D8h,058h,026h,089h,007h,0E9h,0F2h
  asm db 000h,0E9h,0EFh,000h,0E9h,0ECh,000h,083h,07Eh,0F6h,015h,07Eh,050h,06Ah,004h,09Ah
  asm db 05Ch,000h,070h,001h,083h,0C4h,002h,0B4h,000h,08Bh,0D8h,083h,0FBh,003h,076h,003h
  asm db 0E9h,0D0h,000h,0D1h,0E3h,02Eh,0FFh,0A7h,08Fh,016h,06Ah,006h,09Ah,05Ch,000h,070h
  asm db 001h,083h,0C4h,002h,0B4h,000h,005h,03Dh,000h,050h,08Bh,0C6h,0BAh,078h,000h,0F7h
  asm db 0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,00Dh,08Ah,003h,0D8h,08Bh,0C7h,0D1h
  asm db 0E0h,003h,0D8h,058h,026h,089h,007h,0E9h,099h,000h,0E9h,096h,000h,06Ah,004h,09Ah
  asm db 05Ch,000h,070h,001h,083h,0C4h,002h,0B4h,000h,03Dh,002h,000h,074h,009h,03Dh,003h
  asm db 000h,074h,033h,0EBh,07Eh,0EBh,07Ch,06Ah,006h,09Ah,05Ch,000h,070h,001h,083h,0C4h
  asm db 002h,0B4h,000h,005h,03Dh,000h,050h,08Bh,0C6h,0BAh,078h,000h,0F7h,0EAh,0BAh,080h
  asm db 002h,08Eh,0C2h,026h,0C4h,01Eh,00Dh,08Ah,003h,0D8h,08Bh,0C7h,0D1h,0E0h,003h,0D8h
  asm db 058h,026h,089h,007h,0EBh,04Dh,057h,056h,09Ah,02Ah,000h,038h,001h,083h,0C4h,004h
  asm db 00Ah,0C0h,074h,03Fh,06Ah,002h,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,0B4h,000h
  asm db 00Bh,0C0h,075h,02Fh,06Ah,009h,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,0B4h,000h
  asm db 005h,067h,000h,050h,08Bh,0C6h,0BAh,078h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h
  asm db 026h,0C4h,01Eh,00Dh,08Ah,003h,0D8h,08Bh,0C7h,0D1h,0E0h,003h,0D8h,058h,026h,089h
  asm db 007h,0EBh,000h,046h,081h,0FEh,093h,000h,07Dh,003h,0E9h,0E7h,0FBh,047h,083h,0FFh
  asm db 03Bh,07Dh,003h,0E9h,0D9h,0FBh,0BFh,001h,000h,0E9h,039h,003h,0BEh,001h,000h,0E9h
  asm db 029h,003h,06Ah,002h,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,0B4h,000h,00Bh,0C0h
  asm db 074h,003h,0E9h,015h,003h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh
  asm db 0C2h,026h,0C4h,01Eh,005h,08Ah,003h,0D8h,026h,080h,078h,0FFh,000h,075h,003h,0E9h
  asm db 0F8h,002h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,08Bh
  asm db 016h,007h,08Ah,026h,003h,006h,005h,08Ah,08Bh,0D8h,08Eh,0C2h,026h,080h,0B8h,093h
  asm db 000h,000h,075h,003h,0E9h,0D3h,002h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h
  asm db 002h,08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah,003h,0D8h,026h,080h,038h,000h,075h,003h
  asm db 0E9h,0B7h,002h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h
  asm db 08Bh,016h,007h,08Ah,026h,003h,006h,005h,08Ah,08Bh,0D8h,08Eh,0C2h,026h,080h,0B8h
  asm db 094h,000h,000h,075h,003h,0E9h,092h,002h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh
  asm db 080h,002h,08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah,003h,0D8h,026h,080h,078h,001h,000h
  asm db 075h,003h,0E9h,075h,002h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh
  asm db 0C2h,026h,08Bh,016h,007h,08Ah,026h,003h,006h,005h,08Ah,08Bh,0D8h,08Eh,0C2h,026h
  asm db 080h,0B8h,095h,000h,000h,075h,003h,0E9h,050h,002h,08Bh,0C7h,0BAh,094h,000h,0F7h
  asm db 0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah,003h,0D8h,026h,08Ah,000h
  asm db 050h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh
  asm db 005h,08Ah,003h,0D8h,058h,026h,03Ah,040h,001h,07Eh,003h,0E9h,01Ch,002h,08Bh,0C7h
  asm db 0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah,003h
  asm db 0D8h,026h,08Ah,000h,050h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh
  asm db 0C2h,026h,0C4h,01Eh,005h,08Ah,003h,0D8h,058h,026h,03Ah,040h,0FFh,07Eh,003h,0E9h
  asm db 0E8h,001h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h
  asm db 01Eh,005h,08Ah,003h,0D8h,026h,08Ah,000h,050h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh
  asm db 0BAh,080h,002h,08Eh,0C2h,026h,08Bh,016h,007h,08Ah,026h,003h,006h,005h,08Ah,08Bh
  asm db 0D8h,08Eh,0C2h,058h,026h,03Ah,080h,06Ch,0FFh,07Eh,003h,0E9h,0ACh,001h,08Bh,0C7h
  asm db 0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah,003h
  asm db 0D8h,026h,08Ah,040h,001h,050h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h
  asm db 08Eh,0C2h,026h,08Bh,016h,007h,08Ah,026h,003h,006h,005h,08Ah,08Bh,0D8h,08Eh,0C2h
  asm db 058h,026h,03Ah,080h,06Dh,0FFh,07Eh,003h,0E9h,06Fh,001h,08Bh,0C7h,0BAh,094h,000h
  asm db 0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah,003h,0D8h,026h,08Ah
  asm db 000h,050h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,08Bh
  asm db 016h,007h,08Ah,026h,003h,006h,005h,08Ah,08Bh,0D8h,08Eh,0C2h,058h,026h,03Ah,080h
  asm db 094h,000h,07Eh,003h,0E9h,033h,001h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h
  asm db 002h,08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah,003h,0D8h,026h,08Ah,040h,001h,050h,08Bh
  asm db 0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,08Bh,016h,007h,08Ah
  asm db 026h,003h,006h,005h,08Ah,08Bh,0D8h,08Eh,0C2h,058h,026h,03Ah,080h,095h,000h,07Eh
  asm db 003h,0E9h,0F6h,000h,057h,056h,090h,00Eh,0E8h,031h,00Eh,083h,0C4h,004h,0B4h,000h
  asm db 00Bh,0C0h,074h,003h,0E9h,0E3h,000h,057h,08Bh,0C6h,048h,050h,090h,00Eh,0E8h,01Bh
  asm db 00Eh,083h,0C4h,004h,0B4h,000h,00Bh,0C0h,074h,003h,0E9h,0CDh,000h,057h,056h,09Ah
  asm db 061h,000h,038h,001h,083h,0C4h,004h,03Ch,002h,074h,003h,0E9h,0BCh,000h,08Bh,0C6h
  asm db 0BAh,078h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,08Bh,016h,00Fh,08Ah,026h
  asm db 003h,006h,00Dh,08Ah,08Bh,0DFh,0D1h,0E3h,003h,0C3h,08Bh,0D8h,08Eh,0C2h,026h,08Bh
  asm db 087h,010h,0FFh,089h,046h,0FCh,08Bh,046h,0FCh,0BAh,009h,000h,0F7h,0EAh,0BAh,080h
  asm db 002h,08Eh,0C2h,026h,0C4h,01Eh,095h,089h,003h,0D8h,026h,08Ah,007h,088h,046h,0FFh
  asm db 08Ah,046h,0FFh,0B4h,000h,0BAh,027h,000h,0F7h,0EAh,0BAh,060h,000h,08Bh,0D8h,08Eh
  asm db 0C2h,026h,080h,0BFh,01Bh,001h,002h,073h,061h,057h,056h,09Ah,061h,000h,038h,001h
  asm db 083h,0C4h,004h,03Ch,003h,073h,053h,06Ah,005h,09Ah,05Ch,000h,070h,001h,083h,0C4h
  asm db 002h,0B4h,000h,005h,092h,000h,050h,08Bh,0C6h,0BAh,078h,000h,0F7h,0EAh,0BAh,080h
  asm db 002h,08Eh,0C2h,026h,08Bh,016h,00Fh,08Ah,026h,003h,006h,00Dh,08Ah,08Bh,0DFh,0D1h
  asm db 0E3h,003h,0C3h,08Bh,0D8h,08Eh,0C2h,058h,026h,089h,047h,088h,08Bh,0C6h,0BAh,078h
  asm db 000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,00Dh,08Ah,003h,0D8h,08Bh
  asm db 0C7h,0D1h,0E0h,003h,0D8h,026h,0C7h,007h,000h,000h,046h,081h,0FEh,092h,000h,07Dh
  asm db 003h,0E9h,0CEh,0FCh,047h,083h,0FFh,03Ah,07Dh,003h,0E9h,0BFh,0FCh,090h,00Eh,0E8h
  asm db 0ABh,016h,05Fh,05Eh
}

void __cdecl16far f_3381_2651(void)
{
  asm db 056h,057h,08Bh,076h,006h,08Bh,07Eh,008h,08Bh,0C7h,0BAh,028h,001h,0F7h,0EAh,0BAh
  asm db 080h,002h,08Eh,0C2h,026h,0C4h,01Eh,009h,08Ah,003h,0D8h,08Bh,0C6h,0D1h,0E0h,003h
  asm db 0D8h,026h,0F7h,007h,004h,000h,075h,003h,0E9h,008h,001h,08Bh,0C7h,0BAh,094h,000h
  asm db 0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,08Bh,016h,007h,08Ah,026h,003h,006h,005h
  asm db 08Ah,08Bh,0D8h,08Eh,0C2h,026h,08Ah,080h,094h,000h,098h,00Bh,0C0h,075h,054h,08Bh
  asm db 0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah
  asm db 003h,0D8h,026h,08Ah,040h,001h,098h,00Bh,0C0h,075h,038h,08Bh,0C7h,0BAh,094h,000h
  asm db 0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah,003h,0D8h,026h,08Ah
  asm db 000h,098h,00Bh,0C0h,075h,01Dh,08Bh,0C7h,0BAh,028h,001h,0F7h,0EAh,0BAh,080h,002h
  asm db 08Eh,0C2h,026h,0C4h,01Eh,009h,08Ah,003h,0D8h,08Bh,0C6h,0D1h,0E0h,003h,0D8h,026h
  asm db 083h,00Fh,001h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h
  asm db 08Bh,016h,007h,08Ah,026h,003h,006h,005h,08Ah,08Bh,0D8h,08Eh,0C2h,026h,08Ah,080h
  asm db 094h,000h,098h,00Bh,0C0h,074h,003h,0E9h,061h,001h,08Bh,0C7h,0BAh,094h,000h,0F7h
  asm db 0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah,003h,0D8h,026h,08Ah,040h
  asm db 001h,098h,00Bh,0C0h,074h,003h,0E9h,042h,001h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh
  asm db 0BAh,080h,002h,08Eh,0C2h,026h,08Bh,016h,007h,08Ah,026h,003h,006h,005h,08Ah,08Bh
  asm db 0D8h,08Eh,0C2h,026h,08Ah,080h,095h,000h,098h,00Bh,0C0h,074h,003h,0E9h,01Bh,001h
  asm db 08Bh,0C7h,0BAh,028h,001h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,009h
  asm db 08Ah,003h,0D8h,08Bh,0C6h,0D1h,0E0h,003h,0D8h,026h,083h,00Fh,002h,0E9h,0FBh,000h
  asm db 0E9h,0F8h,000h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h
  asm db 0C4h,01Eh,005h,08Ah,003h,0D8h,026h,08Ah,000h,098h,00Bh,0C0h,075h,065h,08Bh,0C7h
  asm db 0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,08Bh,016h,007h,08Ah,026h
  asm db 003h,006h,005h,08Ah,08Bh,0D8h,08Eh,0C2h,026h,08Ah,080h,095h,000h,098h,00Bh,0C0h
  asm db 075h,041h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,08Bh
  asm db 016h,007h,08Ah,026h,003h,006h,005h,08Ah,08Bh,0D8h,08Eh,0C2h,026h,08Ah,080h,094h
  asm db 000h,098h,00Bh,0C0h,075h,01Dh,08Bh,0C7h,0BAh,028h,001h,0F7h,0EAh,0BAh,080h,002h
  asm db 08Eh,0C2h,026h,0C4h,01Eh,009h,08Ah,003h,0D8h,08Bh,0C6h,0D1h,0E0h,003h,0D8h,026h
  asm db 083h,00Fh,001h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h
  asm db 0C4h,01Eh,005h,08Ah,003h,0D8h,026h,08Ah,000h,098h,00Bh,0C0h,075h,05Dh,08Bh,0C7h
  asm db 0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,08Bh,016h,007h,08Ah,026h
  asm db 003h,006h,005h,08Ah,08Bh,0D8h,08Eh,0C2h,026h,08Ah,080h,095h,000h,098h,00Bh,0C0h
  asm db 075h,039h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h
  asm db 01Eh,005h,08Ah,003h,0D8h,026h,08Ah,040h,001h,098h,00Bh,0C0h,075h,01Dh,08Bh,0C7h
  asm db 0BAh,028h,001h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,009h,08Ah,003h
  asm db 0D8h,08Bh,0C6h,0D1h,0E0h,003h,0D8h,026h,083h,00Fh,002h,05Fh,05Eh
}

void __cdecl16far f_3381_24c3(void)
{
  volatile unsigned char pad[0xc];
  asm db 056h,057h,08Bh,07Eh,006h,0FFh,076h,008h,057h,00Eh,0E8h,023h,0FFh,083h,0C4h,004h
  asm db 005h,014h,000h
  asm mov word ptr pad[2],ax
  asm db 08Bh,046h,0F6h,089h,046h,0F4h,0C6h,046h,0FCh,0FFh,0C6h,046h,0FDh,0FFh,0C6h,046h
  asm db 0FBh,0FFh,0C6h,046h,0FAh,0FFh,06Ah,004h,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h
  asm db 088h,046h,0FEh,08Ah,046h,0FEh,088h,046h,0FFh,08Ah,046h,0FFh,02Ah,046h,00Ah,024h
  asm db 003h,088h,046h,0F9h,080h,07Eh,0F9h,002h,075h,003h,0E9h,0B5h,000h,0C4h,05Eh,010h
  asm db 026h,080h,03Fh,002h,072h,00Eh,0C4h,05Eh,00Ch,026h,08Ah,007h,03Ah,046h,0F9h,075h
  asm db 003h,0E9h,09Eh,000h,08Ah,046h,0FFh,088h,046h,0FAh,08Ah,046h,0FFh,0B4h,000h,0BAh
  asm db 080h,002h,08Bh,0D8h,08Eh,0C2h,026h,08Ah,087h,089h,008h,098h,08Bh,056h,008h,003h
  asm db 0D0h,052h,08Ah,046h,0FFh,0B4h,000h,0BAh,080h,002h,08Bh,0D8h,08Eh,0C2h,026h,08Ah
  asm db 087h,085h,008h,098h,08Bh,0D7h,003h,0D0h,052h,00Eh,0E8h,08Dh,0FEh,083h,0C4h,004h
  asm db 08Bh,0F0h,03Bh,076h,0F6h,077h,009h,08Ah,046h,0FFh,088h,046h,0FDh,089h,076h,0F6h
  asm db 08Ah,046h,0FFh,050h,08Ah,046h,0FFh,0B4h,000h,0BAh,080h,002h,08Bh,0D8h,08Eh,0C2h
  asm db 026h,08Ah,087h,089h,008h,098h,08Bh,056h,008h,003h,0D0h,052h,08Ah,046h,0FFh,0B4h
  asm db 000h,0BAh,080h,002h,08Bh,0D8h,08Eh,0C2h,026h,08Ah,087h,085h,008h,098h,08Bh,0D7h
  asm db 003h,0D0h,052h,00Eh,0E8h,09Ch,0FEh,083h,0C4h,006h,00Ah,0C0h,074h,014h,08Ah,046h
  asm db 0FFh,088h,046h,0FBh,03Bh,076h,0F4h,077h,009h,08Ah,046h,0FFh,088h,046h,0FCh,089h
  asm db 076h,0F4h,08Ah,046h,0FFh,0FEh,0C0h,024h,003h,088h,046h,0FFh,08Ah,046h,0FFh,03Ah
  asm db 046h,0FEh,074h,003h,0E9h,022h,0FFh,080h,07Eh,0FCh,0FFh,074h,008h,08Ah,046h,0FCh
  asm db 088h,046h,0FFh,0EBh,022h,080h,07Eh,0FBh,0FFh,074h,008h,08Ah,046h,0FBh,088h,046h
  asm db 0FFh,0EBh,014h,080h,07Eh,0FDh,0FFh,074h,008h,08Ah,046h,0FDh,088h,046h,0FFh,0EBh
  asm db 006h,08Ah,046h,0FAh,088h,046h,0FFh,08Ah,046h,0FFh,02Ah,046h,00Ah,024h,003h,088h
  asm db 046h,0F9h,080h,07Eh,0F9h,000h,074h,023h,0C4h,05Eh,00Ch,026h,08Ah,007h,03Ah,046h
  asm db 0F9h,074h,012h,0C4h,05Eh,010h,026h,0C6h,007h,000h,0C4h,05Eh,00Ch,08Ah,046h,0F9h
  asm db 026h,088h,007h,0EBh,006h,0C4h,05Eh,010h,026h,0FEh,007h,08Ah,046h,0FFh,05Fh,05Eh
}

void __cdecl16far f_3381_2ee2(void)
{
  volatile unsigned char pad[0x5a];
  asm db 080h,03Eh,019h,005h,000h,074h,003h,0E9h,033h,002h,06Ah,019h,09Ah,05Ch,000h,070h
  asm db 001h,083h,0C4h,002h
  asm mov byte ptr pad[0x59],al
  asm db 0C6h,046h,0FEh,000h,080h,07Eh,0FEh,004h,072h,021h,0B8h,080h,002h,08Eh,0C0h,026h
  asm db 080h,03Eh,056h,047h,000h,074h,00Ah,06Ah,000h,09Ah,025h,000h,080h,001h,083h,0C4h
  asm db 002h,06Ah,000h,09Ah,020h,000h,008h,001h,083h,0C4h,002h,09Ah,025h,000h,068h,001h
  asm db 0B8h,080h,002h,08Eh,0C0h,026h,0C7h,006h,02Ch,004h,016h,000h,0B8h,080h,002h,08Eh
  asm db 0C0h,026h,0C7h,006h,02Eh,004h,00Ch,000h,06Ah,008h,068h,0DEh,000h,0B8h,080h,002h
  asm db 08Eh,0C0h,026h,0FFh,036h,027h,08Ah,026h,0FFh,036h,025h,08Ah,01Eh,068h,0B1h,006h
  asm db 09Ah,02Fh,000h,0F8h,000h,083h,0C4h,00Ch,0B8h,080h,002h,08Eh,0C0h,026h,0C7h,006h
  asm db 02Ch,004h,016h,000h,0B8h,080h,002h,08Eh,0C0h,026h,0C7h,006h,02Eh,004h,02Fh,000h
  asm db 06Ah,008h,068h,0DEh,000h,0B8h,080h,002h,08Eh,0C0h,026h,0FFh,036h,027h,08Ah,026h
  asm db 0FFh,036h,025h,08Ah,08Ah,046h,0FFh,0B4h,000h,08Bh,0D8h,08Ah,087h,01Ah,005h,0B4h
  asm db 000h,050h,01Eh,068h,0CDh,006h,016h,08Dh,046h,0A6h,050h,09Ah,07Ah,000h,070h,001h
  asm db 083h,0C4h,00Ah,052h,050h,09Ah,02Fh,000h,0F8h,000h,083h,0C4h,00Ch,0B8h,080h,002h
  asm db 08Eh,0C0h,026h,0C7h,006h,02Ch,004h,016h,000h,0B8h,080h,002h,08Eh,0C0h,026h,0C7h
  asm db 006h,02Eh,004h,043h,000h,06Ah,008h,068h,0DEh,000h,0B8h,080h,002h,08Eh,0C0h,026h
  asm db 0FFh,036h,027h,08Ah,026h,0FFh,036h,025h,08Ah,08Ah,046h,0FFh,0B4h,000h,08Bh,0D8h
  asm db 08Ah,087h,033h,005h,0B4h,000h,050h,01Eh,068h,0EDh,006h,016h,08Dh,046h,0A6h,050h
  asm db 09Ah,07Ah,000h,070h,001h,083h,0C4h,00Ah,052h,050h,09Ah,02Fh,000h,0F8h,000h,083h
  asm db 0C4h,00Ch,0B8h,080h,002h,08Eh,0C0h,026h,0C7h,006h,02Ch,004h,016h,000h,0B8h,080h
  asm db 002h,08Eh,0C0h,026h,0C7h,006h,02Eh,004h,057h,000h,06Ah,008h,068h,0DEh,000h,0B8h
  asm db 080h,002h,08Eh,0C0h,026h,0FFh,036h,027h,08Ah,026h,0FFh,036h,025h,08Ah,01Eh,068h
  asm db 012h,007h,09Ah,02Fh,000h,0F8h,000h,083h,0C4h,00Ch,0C7h,046h,0F8h,000h,000h,0C7h
  asm db 046h,0F6h,000h,000h,06Ah,000h,06Ah,002h,09Ah,043h,000h,070h,001h,083h,0C4h,004h
  asm db 089h,056h,0FCh,089h,046h,0FAh,08Ah,046h,0FFh,0B4h,000h,0C1h,0E0h,002h,08Bh,0D8h
  asm db 0C4h,09Fh,04Ch,005h,026h,08Ah,007h,0C4h,05Eh,0FAh,026h,088h,007h,0C4h,05Eh,0FAh
  asm db 026h,0C6h,047h,001h,000h,0FFh,076h,0FCh,0FFh,076h,0FAh,06Ah,006h,06Ah,000h,06Ah
  asm db 000h,09Ah,02Fh,000h,068h,001h,083h,0C4h,00Ah,089h,056h,0F8h,089h,046h,0F6h,0FFh
  asm db 076h,0F8h,0FFh,076h,0F6h,00Eh,0E8h,0F2h,0FDh,083h,0C4h,004h,0B8h,080h,002h,08Eh
  asm db 0C0h,026h,080h,03Eh,0FCh,091h,000h,074h,021h,0B8h,080h,002h,08Eh,0C0h,026h,080h
  asm db 03Eh,056h,047h,000h,074h,00Ah,06Ah,000h,09Ah,025h,000h,080h,001h,083h,0C4h,002h
  asm db 06Ah,000h,09Ah,020h,000h,008h,001h,083h,0C4h,002h,08Bh,046h,0F6h,00Bh,046h,0F8h
  asm db 074h,034h,08Ah,046h,0FFh,0B4h,000h,0C1h,0E0h,002h,08Bh,0D8h,0FFh,0B7h,04Eh,005h
  asm db 0FFh,0B7h,04Ch,005h,0FFh,076h,0F8h,0FFh,076h,0F6h,09Ah,05Ah,02Dh,000h,000h,083h
  asm db 0C4h,008h,031h,0C0h,075h,010h,0FFh,076h,0F8h,0FFh,076h,0F6h,09Ah,070h,000h,070h
  asm db 001h,083h,0C4h,004h,0EBh,006h,0FEh,046h,0FEh,0E9h,0E8h,0FDh,09Ah,025h,000h,068h
  asm db 001h,0C6h,006h,019h,005h,001h
}

void __cdecl16far f_3381_2883(void)
{
  asm db 083h,0ECh,022h,056h,057h,08Dh,046h,0DEh,016h,050h,01Eh,068h,0F2h,004h,0B9h,010h
  asm db 000h,09Ah,04Fh,009h,000h,000h,08Dh,046h,0F8h,016h,050h,01Eh,068h,002h,005h,0B9h
  asm db 008h,000h,09Ah,04Fh,009h,000h,000h,0C7h,046h,0F0h,000h,000h,0E9h,070h,004h,068h
  asm db 093h,000h,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,0B4h,000h,08Bh,0F0h,06Ah,03Bh
  asm db 09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,0B4h,000h,08Bh,0F8h,0C6h,046h,0F7h,064h
  asm db 057h,056h,00Eh,0E8h,062h,0FAh,083h,0C4h,004h,088h,046h,0F6h,08Ah,046h,0F6h,03Ah
  asm db 046h,0F7h,073h,006h,08Ah,046h,0F6h,088h,046h,0F7h,057h,08Bh,0C6h,040h,050h,00Eh
  asm db 0E8h,045h,0FAh,083h,0C4h,004h,088h,046h,0F6h,08Ah,046h,0F6h,03Ah,046h,0F7h,073h
  asm db 006h,08Ah,046h,0F6h,088h,046h,0F7h,08Bh,0C7h,040h,050h,056h,00Eh,0E8h,028h,0FAh
  asm db 083h,0C4h,004h,088h,046h,0F6h,08Ah,046h,0F6h,03Ah,046h,0F7h,073h,006h,08Ah,046h
  asm db 0F6h,088h,046h,0F7h,08Bh,0C7h,040h,050h,08Bh,0C6h,040h,050h,00Eh,0E8h,008h,0FAh
  asm db 083h,0C4h,004h,088h,046h,0F6h,08Ah,046h,0F6h,03Ah,046h,0F7h,073h,006h,08Ah,046h
  asm db 0F6h,088h,046h,0F7h,08Ah,046h,0F7h,050h,057h,056h,00Eh,0E8h,026h,0FAh,083h,0C4h
  asm db 006h,08Ah,046h,0F7h,050h,057h,08Bh,0C6h,040h,050h,00Eh,0E8h,016h,0FAh,083h,0C4h
  asm db 006h,08Ah,046h,0F7h,050h,08Bh,0C7h,040h,050h,056h,00Eh,0E8h,006h,0FAh,083h,0C4h
  asm db 006h,08Ah,046h,0F7h,050h,08Bh,0C7h,040h,050h,08Bh,0C6h,040h,050h,00Eh,0E8h,0F3h
  asm db 0F9h,083h,0C4h,006h,08Ah,046h,0F7h,0B4h,000h,00Bh,0C0h,075h,039h,057h,056h,00Eh
  asm db 0E8h,0B8h,0FCh,083h,0C4h,004h,057h,08Bh,0C6h,048h,050h,00Eh,0E8h,0ACh,0FCh,083h
  asm db 0C4h,004h,057h,08Bh,0C6h,040h,050h,00Eh,0E8h,0A0h,0FCh,083h,0C4h,004h,08Bh,0C7h
  asm db 048h,050h,056h,00Eh,0E8h,094h,0FCh,083h,0C4h,004h,08Bh,0C7h,040h,050h,056h,00Eh
  asm db 0E8h,088h,0FCh,083h,0C4h,004h,0C6h,046h,0F4h,000h,0C6h,046h,0F3h,000h,06Ah,004h
  asm db 09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,088h,046h,0EFh,081h,0FEh,093h,000h,07Ch
  asm db 003h,0E9h,038h,003h,00Bh,0F6h,07Dh,003h,0E9h,031h,003h,083h,0FFh,03Bh,07Ch,003h
  asm db 0E9h,029h,003h,00Bh,0FFh,07Dh,003h,0E9h,022h,003h,08Bh,0C7h,0BAh,094h,000h,0F7h
  asm db 0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,005h,08Ah,003h,0D8h,026h,08Ah,000h
  asm db 098h,00Bh,0C0h,075h,067h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh
  asm db 0C2h,026h,0C4h,01Eh,005h,08Ah,003h,0D8h,026h,08Ah,040h,001h,098h,00Bh,0C0h,075h
  asm db 04Bh,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,08Bh,016h
  asm db 007h,08Ah,026h,003h,006h,005h,08Ah,08Bh,0D8h,08Eh,0C2h,026h,08Ah,080h,094h,000h
  asm db 098h,00Bh,0C0h,075h,027h,08Bh,0C7h,0BAh,094h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh
  asm db 0C2h,026h,08Bh,016h,007h,08Ah,026h,003h,006h,005h,08Ah,08Bh,0D8h,08Eh,0C2h,026h
  asm db 08Ah,080h,095h,000h,098h,00Bh,0C0h,075h,003h,0E9h,0A0h,002h,08Bh,0C7h,0BAh,028h
  asm db 001h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,009h,08Ah,003h,0D8h,08Bh
  asm db 0C6h,0D1h,0E0h,003h,0D8h,026h,08Bh,007h,025h,003h,000h,03Dh,003h,000h,075h,003h
  asm db 0E9h,079h,002h,08Bh,0C7h,0BAh,028h,001h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h
  asm db 0C4h,01Eh,009h,08Ah,003h,0D8h,08Bh,0C6h,0D1h,0E0h,003h,0D8h,026h,0F7h,007h,003h
  asm db 000h,074h,01Dh,08Bh,0C7h,0BAh,028h,001h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h
  asm db 0C4h,01Eh,009h,08Ah,003h,0D8h,08Bh,0C6h,0D1h,0E0h,003h,0D8h,026h,083h,00Fh,003h
  asm db 016h,08Dh,046h,0F3h,050h,016h,08Dh,046h,0F4h,050h,08Ah,046h,0EFh,050h,057h,056h
  asm db 00Eh,0E8h,0C9h,0F9h,083h,0C4h,00Eh,088h,046h,0EEh,080h,07Eh,0EEh,0FFh,075h,003h
  asm db 0E9h,019h,002h,08Ah,046h,0EFh,0B4h,000h,08Ah,056h,0EEh,0B6h,000h,083h,0F2h,002h
  asm db 03Bh,0C2h,075h,003h,0E9h,005h,002h,08Ah,046h,0EFh,0B4h,000h,0C1h,0E0h,002h,08Ah
  asm db 056h,0EEh,0B6h,000h,003h,0C2h,08Dh,056h,0DEh,003h,0C2h,08Bh,0D8h,036h,08Ah,007h
  asm db 0B4h,000h,00Bh,0C0h,075h,003h,0E9h,0E3h,001h,08Bh,0C7h,0BAh,028h,001h,0F7h,0EAh
  asm db 0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,009h,08Ah,003h,0D8h,08Bh,0C6h,0D1h,0E0h
  asm db 003h,0D8h,026h,083h,027h,0FBh,08Ah,046h,0EFh,0B4h,000h,0C1h,0E0h,002h,08Ah,056h
  asm db 0EEh,0B6h,000h,003h,0C2h,08Dh,056h,0DEh,003h,0C2h,08Bh,0D8h,036h,08Ah,007h,0B4h
  asm db 000h,050h,08Bh,0C7h,0BAh,028h,001h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h
  asm db 01Eh,009h,08Ah,003h,0D8h,08Bh,0C6h,0D1h,0E0h,003h,0D8h,058h,026h,009h,007h,08Ah
  asm db 046h,0EFh,0B4h,000h,0D1h,0E0h,08Dh,056h,0F8h,003h,0C2h,08Bh,0D8h,036h,08Ah,007h
  asm db 0B4h,000h,0D1h,0F8h,08Bh,0D7h,003h,0D0h,052h,08Ah,046h,0EFh,0B4h,000h,0D1h,0E0h
  asm db 08Dh,056h,0F8h,003h,0C2h,08Bh,0D8h,036h,08Ah,007h,0B4h,000h,025h,001h,000h,08Bh
  asm db 0D6h,003h,0D0h,052h,00Eh,0E8h,070h,0F7h,083h,0C4h,004h,088h,046h,0F6h,08Ah,046h
  asm db 0EFh,0B4h,000h,0D1h,0E0h,08Dh,056h,0F9h,003h,0C2h,08Bh,0D8h,036h,08Ah,007h,0B4h
  asm db 000h,0D1h,0F8h,08Bh,0D7h,003h,0D0h,052h,08Ah,046h,0EFh,0B4h,000h,0D1h,0E0h,08Dh
  asm db 056h,0F9h,003h,0C2h,08Bh,0D8h,036h,08Ah,007h,0B4h,000h,025h,001h,000h,08Bh,0D6h
  asm db 003h,0D0h,052h,00Eh,0E8h,031h,0F7h,083h,0C4h,004h,088h,046h,0F5h,08Ah,046h,0F6h
  asm db 03Ah,046h,0F7h,073h,006h,08Ah,046h,0F6h,088h,046h,0F7h,08Ah,046h,0F5h,03Ah,046h
  asm db 0F7h,073h,006h,08Ah,046h,0F5h,088h,046h,0F7h,08Ah,046h,0F7h,050h,08Ah,046h,0EEh
  asm db 0B4h,000h,0D1h,0E0h,08Dh,056h,0F8h,003h,0C2h,08Bh,0D8h,036h,08Ah,007h,0B4h,000h
  asm db 0D1h,0F8h,08Bh,0D7h,003h,0D0h,052h,08Ah,046h,0EEh,0B4h,000h,0D1h,0E0h,08Dh,056h
  asm db 0F8h,003h,0C2h,08Bh,0D8h,036h,08Ah,007h,0B4h,000h,025h,001h,000h,08Bh,0D6h,003h
  asm db 0D0h,052h,00Eh,0E8h,00Eh,0F7h,083h,0C4h,006h,08Ah,046h,0F7h,050h,08Ah,046h,0EEh
  asm db 0B4h,000h,0D1h,0E0h,08Dh,056h,0F9h,003h,0C2h,08Bh,0D8h,036h,08Ah,007h,0B4h,000h
  asm db 0D1h,0F8h,08Bh,0D7h,003h,0D0h,052h,08Ah,046h,0EEh,0B4h,000h,0D1h,0E0h,08Dh,056h
  asm db 0F9h,003h,0C2h,08Bh,0D8h,036h,08Ah,007h,0B4h,000h,025h,001h,000h,08Bh,0D6h,003h
  asm db 0D0h,052h,00Eh,0E8h,0CEh,0F6h,083h,0C4h,006h,08Ah,046h,0F7h,0B4h,000h,00Bh,0C0h
  asm db 075h,039h,057h,056h,00Eh,0E8h,093h,0F9h,083h,0C4h,004h,057h,08Bh,0C6h,048h,050h
  asm db 00Eh,0E8h,087h,0F9h,083h,0C4h,004h,057h,08Bh,0C6h,040h,050h,00Eh,0E8h,07Bh,0F9h
  asm db 083h,0C4h,004h,08Bh,0C7h,048h,050h,056h,00Eh,0E8h,06Fh,0F9h,083h,0C4h,004h,08Bh
  asm db 0C7h,040h,050h,056h,00Eh,0E8h,063h,0F9h,083h,0C4h,004h,08Ah,046h,0EEh,0B4h,000h
  asm db 0BAh,080h,002h,08Bh,0D8h,08Eh,0C2h,026h,08Ah,087h,085h,008h,098h,003h,0F0h,08Ah
  asm db 046h,0EEh,0B4h,000h,0BAh,080h,002h,08Bh,0D8h,08Eh,0C2h,026h,08Ah,087h,089h,008h
  asm db 098h,003h,0F8h,08Ah,046h,0EEh,088h,046h,0EFh,0E9h,0BFh,0FCh,0FFh,046h,0F0h,0A0h
  asm db 0B0h,08Bh,0B4h,000h,03Bh,046h,0F0h,07Eh,003h,0E9h,083h,0FBh,05Fh,05Eh,0C9h,0CBh
  asm db 055h,08Bh,0ECh,083h,0ECh,002h,056h,057h,033h,0FFh,0EBh,052h,033h,0F6h,0EBh,048h
  asm db 0C6h,046h,0FFh,000h,0EBh,03Bh,08Ah,046h,0FFh,050h,056h,057h,09Ah,048h,000h,0A0h
  asm db 001h,083h,0C4h,006h,00Ah,0C0h,074h,026h,0B8h,010h,000h,08Ah,04Eh,0FFh,0D3h,0E0h
  asm db 050h,08Bh,0C6h,0BAh,028h,001h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh
  asm db 009h,08Ah,003h,0D8h,08Bh,0C7h,0D1h,0E0h,003h,0D8h,058h,026h,009h,007h,0FEh,046h
  asm db 0FFh,080h,07Eh,0FFh,004h,072h,0BFh,046h,083h,0FEh,03Ch,07Ch,0B3h,047h,081h,0FFh
  asm db 094h,000h,07Ch,0A8h,05Fh,05Eh,0C9h,0CBh,055h,08Bh,0ECh,083h,0ECh,014h,056h,057h
  asm db 08Dh,046h,0ECh,016h,050h,01Eh,068h,00Eh,005h,0B9h,00Bh,000h,09Ah,04Fh,009h,000h
  asm db 000h,0A1h,00Ah,005h,00Bh,006h,00Ch,005h,075h,014h,06Ah,000h,068h,000h,001h,09Ah
  asm db 043h,000h,070h,001h,083h,0C4h,004h,089h,016h,00Ch,005h,0A3h,00Ah,005h,0B8h,080h
  asm db 002h,08Eh,0C0h,026h,0FFh,036h,0D2h,090h,026h,0FFh,036h,0D0h,090h,09Ah,020h,000h
  asm db 070h,001h,083h,0C4h,004h,089h,056h,0FAh,089h,046h,0F8h,08Bh,046h,0FAh,08Bh,056h
  asm db 0F8h,089h,046h,0FEh,089h,056h,0FCh,0C4h,01Eh,00Ah,005h,026h,0C6h,007h,000h,0BEh
  asm db 001h,000h,0E9h,082h,000h,08Bh,0C6h,0D1h,0E0h,003h,0C6h,0C4h,05Eh,0FCh,003h,0D8h
  asm db 026h,08Ah,007h,0B4h,000h,08Bh,0F8h,08Bh,0DEh,0D1h,0E3h,003h,0DEh,08Eh,046h,0FEh
  asm db 003h,05Eh,0FCh,026h,08Ah,047h,001h,0B4h,000h,03Bh,0C7h,076h,014h,08Bh,0DEh,0D1h
  asm db 0E3h,003h,0DEh,08Eh,046h,0FEh,003h,05Eh,0FCh,026h,08Ah,047h,001h,0B4h,000h,08Bh
  asm db 0F8h,08Bh,0DEh,0D1h,0E3h,003h,0DEh,08Eh,046h,0FEh,003h,05Eh,0FCh,026h,08Ah,047h
  asm db 002h,0B4h,000h,03Bh,0C7h,076h,014h,08Bh,0DEh,0D1h,0E3h,003h,0DEh,08Eh,046h,0FEh
  asm db 003h,05Eh,0FCh,026h,08Ah,047h,002h,0B4h,000h,08Bh,0F8h,08Bh,0C7h,0BAh,00Bh,000h
  asm db 0F7h,0EAh,0C1h,0E8h,006h,08Dh,056h,0ECh,003h,0C2h,08Bh,0D8h,036h,08Ah,007h,0C4h
  asm db 01Eh,00Ah,005h,026h,088h,000h,046h,081h,0FEh,000h,001h,07Dh,003h,0E9h,075h,0FFh
  asm db 05Fh,05Eh,0C9h,0CBh,055h,08Bh,0ECh,056h,057h,08Bh,046h,006h,00Bh,046h,008h,074h
  asm db 037h,033h,0F6h,033h,0FFh,0EBh,021h,0C4h,05Eh,006h,026h,080h,038h,020h,074h,017h
  asm db 0C4h,05Eh,006h,026h,08Ah,000h,098h,050h,09Ah,004h,00Eh,000h,000h,083h,0C4h,002h
  asm db 0C4h,05Eh,006h,026h,088h,001h,047h,046h,0C4h,05Eh,006h,026h,080h,038h,000h,075h
  asm db 0D6h,0C4h,05Eh,006h,026h,0C6h,001h,000h,05Fh,05Eh
}

void __cdecl16far f_e0_011f(char far *);
void __cdecl16far f_190_004d(void);

void __cdecl16far f_e0_011f(char far *);
void __cdecl16far f_190_004d(void);

void __cdecl16far f_3381_2101(void)
{
  volatile unsigned char pad[0x304];
  asm db 0B8h,080h,002h,08Eh,0C0h,026h,0C7h,006h,099h,089h,0F8h,000h,00Eh,0E8h,07Fh,0F5h
  asm db 0B8h,080h,002h,08Eh,0C0h,026h,0C6h,006h,096h,090h,000h,00Eh,0E8h,0C7h,0FFh,0B8h
  asm db 080h,002h,08Eh,0C0h,026h,0C6h,006h,0E6h,090h,000h,0B8h,080h,002h,08Eh,0C0h,026h
  asm db 0C6h,006h,0E5h,090h,000h,0B8h,080h,002h,08Eh,0C0h,026h,0C6h,006h,0E3h,090h,005h
  asm db 0B8h,080h,002h,08Eh,0C0h,026h,0C6h,006h,0E4h,090h,000h,0B8h,080h,002h,08Eh,0C0h
  asm db 026h,0C7h,006h,0DFh,091h,000h,000h,0B8h,080h,002h,08Eh,0C0h,026h,0C6h,006h,06Fh
  asm db 090h,000h,0B8h,080h,002h,08Eh,0C0h,026h,0C6h,006h,06Eh,090h,000h,0B8h,080h,002h
  asm db 08Eh,0C0h,026h,0C6h,006h,06Dh,090h,000h,0B8h,080h,002h,08Eh,0C0h,026h,0C7h,006h
  asm db 06Bh,090h,000h,000h,026h,0C7h,006h,069h,090h,000h,000h,0B8h,080h,002h,08Eh,0C0h
  asm db 026h,0C6h,006h,010h,092h,000h,06Ah,003h,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h
  asm db 0B4h,000h,08Bh,0D0h,0D1h,0E2h,003h,0D0h,0B8h,080h,002h,08Eh,0C0h,026h,088h,016h
  asm db 044h,007h,0B8h,080h,002h,08Eh,0C0h,026h,080h,03Eh,044h,071h,000h,074h,012h,0B8h
  asm db 080h,002h,08Eh,0C0h,026h,0C6h,006h,044h,007h,000h,0C6h,006h,0B0h,08Bh,014h,0EBh
  asm db 00Dh,06Ah,014h,09Ah,05Ch,000h,070h,001h,083h,0C4h,002h,0A2h,0B0h,08Bh,00Eh,0E8h
  asm db 0F2h,0E6h,09Ah,02Ah,000h,058h,001h,00Eh,0E8h,0B6h,0FDh,09Ah,020h,000h,0A8h,001h
  asm db 0B8h,080h,002h,08Eh,0C0h,026h,0C7h,006h,09Fh,089h,048h,000h,0B8h,080h,002h,08Eh
  asm db 0C0h,026h,0C7h,006h,09Dh,089h,01Eh,000h,0B8h,080h,002h,08Eh,0C0h,026h,0C6h,006h
  asm db 056h,047h,001h,0B8h,080h,002h,08Eh,0C0h,026h,0C7h,006h,014h,04Ah,000h,000h,026h
  asm db 0C7h,006h,012h,04Ah,000h,000h,0B8h,080h,002h,08Eh,0C0h,026h,0C7h,006h,067h,090h
  asm db 000h,000h,06Ah,002h,06Ah,000h,068h,080h,002h,068h,0CDh,092h,09Ah,066h,026h,000h
  asm db 000h,083h,0C4h,008h,0B8h,080h,002h,08Eh,0C0h,026h,0C6h,006h,0CCh,092h,000h,0B8h
  asm db 080h,002h,08Eh,0C0h,026h,0C7h,006h,086h,06Ah,000h,000h,0B8h,080h,002h,08Eh,0C0h
  asm db 026h,0C6h,006h,088h,06Ah,000h,0B8h,080h,002h,08Eh,0C0h,026h,0C7h,006h,0CAh,092h
  asm db 000h,000h,0B8h,080h,002h,08Eh,0C0h,026h,0C7h,006h,093h,089h,000h,000h,026h,0C7h
  asm db 006h,091h,089h,000h,000h,0B8h,080h,002h,08Eh,0C0h,026h,0C6h,006h,090h,089h,000h
  asm db 0B8h,080h,002h,08Eh,0C0h,026h,0C6h,006h,03Ah,069h,000h,0B8h,080h,002h,08Eh,0C0h
  asm db 026h,0C7h,006h,0C8h,092h,000h,000h,0B8h,080h,002h,08Eh,0C0h,026h,080h,03Eh,09Dh
  asm db 090h,003h,072h,00Bh,0B8h,080h,002h,08Eh,0C0h,026h,0C6h,006h,0E6h,091h,002h,0B8h
  asm db 080h,002h,08Eh,0C0h,026h,0C7h,006h,0E4h,091h,000h,000h,0B8h,080h,002h,08Eh,0C0h
  asm db 026h,0C6h,006h,0C6h,092h,000h,0B8h,080h,002h,08Eh,0C0h,026h,0C6h,006h,0E2h,091h
  asm db 000h,0B8h,080h,002h,08Eh,0C0h,026h,0FFh,036h,0D2h,090h,026h,0FFh,036h,0D0h,090h
  asm db 09Ah,020h,000h,070h,001h,083h,0C4h,004h,089h,056h,0FEh,089h,046h,0FCh,016h,08Dh
  asm db 086h,0FCh,0FCh,050h,0FFh,076h,0FEh,0FFh,076h,0FCh,09Ah,02Fh,000h,010h,002h,083h
  asm db 0C4h,008h,0B8h,080h,002h,08Eh,0C0h,026h
  if (!GameRunning) {
    f_e0_011f((char far *)pad);
  }
  f_190_004d();
}

