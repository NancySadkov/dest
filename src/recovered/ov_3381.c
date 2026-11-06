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


void __cdecl16far f_3381_024d(void) { }
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
  if (!*(unsigned char far *)MK_FP(0x280, 0x7144)) {
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
