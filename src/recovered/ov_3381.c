/* Recovered overlay OVC_09 (code segment 3381) helpers. */
#include "dgroup.h"

#define SBUF ((char far *)MK_FP(0x280, 0x8bb1))
#define GGameExeP (*(far_t far *)MK_FP(0x280, 0x8976))
#define EMPTY_5BB ((char far *)&GCfgFileName[-1])
#define MAPDIR ((char far * far *)MK_FP(0x280, 0x8a05))
#define MAPFLG ((uint16_t far * far *)MK_FP(0x280, 0x8a09))

/* String/path helpers in segment 0x1000 (not yet recovered). */
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

/* 3381:0132 -- append a trailing backslash to a path if needed.
 * Returns the same far pointer.
 */
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

/* 3381:00fe -- remove a trailing backslash when the name is longer than 3. */
char far * __cdecl16far f_3381_00fe(char far *s)
{
  int n;

  n = f_1000_2d9b(s);
  if (n > 3 && s[n - 1] == '\\') {
    s[n - 1] = 0;
  }
  return s;
}

/* 3381:009a -- join two path components in the static DGROUP buffer. */
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

/* 3381:016c -- handle a drive-letter path spec. */
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

/* 3381:023c -- enable the mouse configuration flag. */
void __cdecl16far f_3381_023c(void)
{
  *(uint16_t far *)MK_FP(0x280, 0x432) = 1;
}

/* 3381:01c8 -- initialise the saved-game path buffer from argv[0]. */
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

/* 3381:1fa9 -- clear the entity count. */
void __cdecl16far f_3381_1fa9(void)
{
  *(undefined2 far *)MK_FP(0x280, 0x9097) = 0;
}

/* placeholder until 3381:1fba is recovered */
void __cdecl16far f_3381_1fba(void) { }

/* 3381:20ee -- start a game mode and refresh the clock. */
void __cdecl16far f_3381_20ee(void)
{
  f_1400_0039(1);
  f_3381_1fba();
}

typedef char maprow[0x94];
typedef uint16_t mapfrow[0x94];

/* 3381:233e -- read a map cell. */
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

/* 3381:237a -- write a map cell. */
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

/* 3381:23b5 -- read a map flag word. */
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
/* 3381:23f9 -- sum the four cells around a corner. */
int __cdecl16far f_3381_23f9(int x, int y)
{
  return (unsigned char)f_3381_233e(x, y)
       + (unsigned char)f_3381_233e(x + 1, y)
       + (unsigned char)f_3381_233e(x, y + 1)
       + (unsigned char)f_3381_233e(x + 1, y + 1);
}







/* 3381:2e9a -- remove spaces from a string in place. */
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

/* 3381:1697 -- initialise the 0xF8 entity slots (assembly body). */
void __cdecl16far f_3381_1697(void)
{
  asm db 033h,0C9h,0EBh,049h,08Bh,0C1h,0BAh,009h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h
  asm db 026h,0C4h,01Eh,095h,089h,003h,0D8h,08Ah,0C1h,026h,088h,007h,08Bh,0C1h,0BAh,009h
  asm db 000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h,026h,0C4h,01Eh,095h,089h,003h,0D8h,026h
  asm db 0C6h,047h,001h,0FFh,08Bh,0C1h,0BAh,009h,000h,0F7h,0EAh,0BAh,080h,002h,08Eh,0C2h
  asm db 026h,0C4h,01Eh,095h,089h,003h,0D8h,026h,0C6h,047h,002h,0FFh,041h,081h,0F9h,0F8h
  asm db 000h,07Ch,0B1h
}


/* placeholders for OVC_09 functions not yet recovered */
void __cdecl16far f_3381_024d(void) { }
void __cdecl16far f_3381_2d9e(void) { }
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

/* far/segment 0x1000 and other overlay helpers */
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

/* 3381:0579 -- main initialisation for the overlay. */
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



