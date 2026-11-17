/* Compatibility shims for Ghidra's decompiler output. */
#ifndef ST_COMPAT_H
#define ST_COMPAT_H
#ifdef __BORLANDC__
#define __cdecl16far
#define __cdecl16near __cdecl
#define __stdcall16far __pascal
#define __stdcall16near __pascal
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
code *swi(int vector);
#define MK_FP(seg,ofs) ((void far *)(((uint32_t)(seg) << 16) | (uint16_t)(ofs)))
#define CONCAT11(a,b) ((uint16_t)(((uint8_t)(a) << 8) | (uint8_t)(b)))
#define CONCAT12(a,b) ((uint16_t)(((uint8_t)(a) << 8) | (uint16_t)(b)))
#define CONCAT13(a,b) ((uint16_t)(((uint8_t)(a) << 8) | (uint16_t)(b)))
#define CONCAT14(a,b) CONCAT12(a,b)
#define CONCAT21(a,b) ((uint16_t)(((uint16_t)(a) >> 8) | ((uint16_t)(b) << 8)))
#define CONCAT22(a,b) ((uint32_t)(((uint16_t)(a) << 16) | (uint16_t)(b)))
#define CONCAT31(a,b) CONCAT22(a,b)
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
#endif
