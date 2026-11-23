/* Compatibility shims for Ghidra's decompiler output. */
#ifndef ST_COMPAT_H
#define ST_COMPAT_H
/* Turbo C++ 3.0 defines __TURBOC__, not __BORLANDC__; testing
   only the latter made `far` an empty macro here, so every far
   pointer degraded to a near one.  Turbo C also spells the
   conventions cdecl/pascal, and cdecl is the default. */
#if defined(__BORLANDC__) || defined(__TURBOC__)
#define __cdecl16far
#define __cdecl16near
#define __stdcall16far
#define __stdcall16near
#else
#define __cdecl16far
#define __cdecl16near
#define __stdcall16far
#define __stdcall16near
#define __cdecl
#define __pascal
#define __fastcall
#define far
#define near
#endif
typedef unsigned short code();
typedef unsigned short blitfn_t();
typedef unsigned long int3;
typedef unsigned long uint3;
typedef unsigned long undefined3;
typedef double longdouble;
code *swi(int vector);

/* Minimal DOS register blocks.  <dos.h> cannot be included: its prototypes for
   _doserrno / unlink / ... conflict with the recovered CRT declarations. */
union st_regs {
    struct { unsigned short ax, bx, cx, dx, si, di, cflag, flags; } x;
    struct { unsigned char al, ah, bl, bh, cl, ch, dl, dh; } h;
};
struct st_sregs { unsigned short es, cs, ss, ds; };
int int86(int intr, union st_regs *inregs, union st_regs *outregs);
int int86x(int intr, union st_regs *inregs, union st_regs *outregs,
           struct st_sregs *segregs);
#define MK_FP(seg,ofs) ((void far *)(((uint32_t)(seg) << 16) | (uint16_t)(ofs)))
#define far_ofs_u32(v) ((uint16_t)((uint32_t)(v)))
#define CONCAT11(a,b) ((uint16_t)(((uint8_t)(a) << 8) | (uint8_t)(b)))
#define CONCAT12(a,b) ((uint16_t)(((uint8_t)(a) << 8) | (uint16_t)(b)))
#define CONCAT13(a,b) ((uint16_t)(((uint8_t)(a) << 8) | (uint16_t)(b)))
#define CONCAT14(a,b) CONCAT12(a,b)
#define CONCAT21(a,b) ((uint16_t)(((uint16_t)(a) >> 8) | ((uint16_t)(b) << 8)))
#define CONCAT22(a,b) ((uint32_t)(((uint16_t)(a) << 16) | (uint16_t)(b)))
#define CONCAT31(a,b) CONCAT22(a,b)
/* segment half of a far pointer value (the far segment of a far object) */
#define SEG_OF(p) ((uint16_t)((uint32_t)(p) >> 16))
#define CONCAT44(a,b) ((uint32_t)(((uint32_t)(a) << 16) | (uint16_t)(b)))
#define CARRY1(a,b) ((uint8_t)((uint16_t)(a) + (uint16_t)(b) > 0xff))
#define CARRY2(a,b) ((uint8_t)((uint32_t)(a) + (uint32_t)(b) > 0xffff))
#define CARRY4(a,b) ((uint8_t)((uint32_t)(a) + (uint32_t)(b) < (uint32_t)(a)))
#define SBORROW1(a,b) ((uint8_t)((int16_t)(int8_t)(a) - (int16_t)(int8_t)(b) < -0x80))
#define SBORROW2(a,b) ((uint8_t)((int32_t)(int16_t)(a) - (int32_t)(int16_t)(b) < -0x8000))
#define SBORROW4(a,b) ((uint8_t)((int32_t)(a) - (int32_t)(b) < 0))
#define SUB41(x,n) ((uint8_t)((uint16_t)(x) >> ((n)*8)))
#define SUB42(x,n) ((uint16_t)((uint32_t)(x) >> ((n)*8)))
#define SUB84(x,n) ((uint32_t)(x) >> ((n)*8))
#define SEXT12(x) ((int16_t)(int8_t)(x))
#define SEXT13(x) SEXT12(x)
#define SEXT14(x) SEXT12(x)
#define SEXT21(x) ((int32_t)(int16_t)(x))
#define SEXT22(x) SEXT21(x)
#define SEXT24(x) SEXT21(x)
#define SEXT31(x) ((int32_t)(int8_t)(x))
#define SEXT41(x) SEXT31(x)
#define ZEXT12(x) ((uint16_t)(uint8_t)(x))
#define ZEXT14(x) ZEXT12(x)
#define ZEXT21(x) ((uint32_t)(uint16_t)(x))
#define ZEXT22(x) ZEXT21(x)
#define ZEXT24(x) ZEXT21(x)
#define ZEXT41(x) ((uint32_t)(uint8_t)(x))
#define SCARRY1(a,b) ((uint8_t)((int16_t)(int8_t)(a) + (int16_t)(int8_t)(b) > 0x7f))
#define SCARRY2(a,b) ((uint8_t)((int32_t)(int16_t)(a) + (int32_t)(int16_t)(b) > 0x7fff))
#define SCARRY4(a,b) ((uint8_t)((int32_t)(a) + (int32_t)(b) < 0))
#define SUB21(x,n) ((uint16_t)((uint32_t)(x) >> ((n)*8)))
#define SUB43(x,n) ((uint8_t)((uint32_t)(x) >> ((n)*8)))
#define ZEXT23(x) ((uint32_t)(uint16_t)(x))
#define POPCOUNT(x) ((uint8_t)(((x) & 1) + (((x) >> 1) & 1) + (((x) >> 2) & 1) + (((x) >> 3) & 1) + (((x) >> 4) & 1) + (((x) >> 5) & 1) + (((x) >> 6) & 1) + (((x) >> 7) & 1)))
int in();
void out();
#define builtin_memcpy memcpy
#ifndef true
#define true 1
#define false 0
#endif
/* Borland's @-suffixed startup symbols. */
#define _argv ((str_t *)_argv_at_)
#define _argc ((int)_argc_at_)
#define _envseg _envseg_at_
#define _envSize _envSize_at_
#define bdata bdata_at_
#define DGROUP_ DGROUP_at__at_
#define _bdata_at_ bdata_at_

/* far-pointer halves, for the places where the original code
   keeps a pointer in two 16-bit words */
#define ST_SEG(p) ((uint16_t)((uint32_t)(void far *)(p) >> 16))
#define ST_OFF(p) ((uint16_t)(void far *)(p))
#endif
