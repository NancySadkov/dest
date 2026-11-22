/* Ghidra pseudo-variables: register shadows, and absolute addresses. */
#ifndef ST_ARTIFACTS_H
#define ST_ARTIFACTS_H

/* Our DGROUP segment, taken from a variable the linker places there.
   Used for addresses that were DGROUP-relative in the original. */
extern int errno;
#define ST_DGROUP_SEG ((uint16_t)((uint32_t)(void far *)&errno >> 16))

#define cRam00005e2c (*(char far *)MK_FP(0x05e2, 0x000c))
#define cRam00033f01 (*(char far *)MK_FP(ST_DGROUP_SEG, 0xfe01))
#define iRam00000066 (*(int16_t far *)MK_FP(0x0000, 0x0066))
#define iRam0001000b (*(int16_t far *)MK_FP(0x1000, 0x000b))
#define iRam0002d2d7 (*(int16_t far *)MK_FP(ST_DGROUP_SEG, 0x91d7))
#define iRam00033501 (*(int16_t far *)MK_FP(ST_DGROUP_SEG, 0xf401))
extern uint8_t in_AF;
extern uint8_t in_AL;
extern uint16_t in_AX;
extern uint8_t in_BL;
extern uint16_t in_BX;
extern uint8_t in_CF;
extern uint8_t in_CL;
extern uint16_t in_CX;
extern uint8_t in_DL;
extern uint16_t in_DX;
extern uint32_t in_ESP;
extern uint16_t in_FS;
extern uint16_t in_GS;
extern uint8_t in_IF;
extern uint8_t in_NT;
extern uint16_t in_ST0;
extern uint8_t in_TF;
extern uint8_t in_ZF;
extern uint16_t in_stack_00000000;
extern uint16_t in_stack_00000002;
extern uint16_t in_stack_00000004;
extern uint16_t in_stack_00000005;
extern uint16_t in_stack_00000006;
extern uint16_t in_stack_00000007;
extern uint16_t in_stack_00000008;
extern uint16_t in_stack_0000000a;
extern uint16_t in_stack_0000000c;
extern uint16_t in_stack_0000000d;
extern uint16_t in_stack_0000000e;
extern uint16_t in_stack_0000000f;
extern uint16_t in_stack_00000010;
extern uint16_t in_stack_00000012;
extern uint16_t in_stack_00000014;
extern uint16_t in_stack_00000016;
extern uint16_t in_stack_00000018;
extern uint16_t in_stack_0000001c;
extern uint16_t in_stack_00000020;
extern uint16_t in_stack_0000fc0c;
extern uint16_t in_stack_0000fc0d;
extern uint16_t in_stack_0000fc0e;
extern uint16_t in_stack_0000fc10;
extern uint16_t in_stack_0000fc14;
extern uint16_t in_stack_0000ff5e;
extern uint16_t in_stack_0000ff62;
extern uint16_t in_stack_0000ff74;
extern uint16_t in_stack_0000ffa6;
extern uint16_t in_stack_0000ffae;
extern uint16_t in_stack_0000ffb8;
extern uint16_t in_stack_0000ffb9;
extern uint16_t in_stack_0000ffbe;
extern uint16_t in_stack_0000ffc0;
extern uint16_t in_stack_0000ffc2;
extern uint16_t in_stack_0000ffd0;
extern uint16_t in_stack_0000ffd2;
extern uint16_t in_stack_0000ffd8;
extern uint16_t in_stack_0000ffde;
extern uint16_t in_stack_0000ffe0;
extern uint16_t in_stack_0000ffe2;
extern uint16_t in_stack_0000ffe4;
extern uint16_t in_stack_0000ffe8;
extern uint16_t in_stack_0000ffea;
extern uint16_t in_stack_0000ffeb;
extern uint16_t in_stack_0000ffec;
extern uint16_t in_stack_0000ffee;
extern uint16_t in_stack_0000ffef;
extern uint16_t in_stack_0000fff0;
extern uint16_t in_stack_0000fff1;
extern uint16_t in_stack_0000fff2;
extern uint16_t in_stack_0000fff3;
extern uint16_t in_stack_0000fff4;
extern uint16_t in_stack_0000fff5;
extern uint16_t in_stack_0000fff6;
extern uint16_t in_stack_0000fff8;
extern uint16_t in_stack_0000fff9;
extern uint16_t in_stack_0000fffa;
extern uint16_t in_stack_0000fffb;
extern uint16_t in_stack_0000fffc;
extern uint16_t in_stack_0000fffd;
#define puRam00010106 (*(undefined2 * far *)MK_FP(0x1010, 0x0006))
#define ram0x0000d528 (*(undefined1 far *)MK_FP(0x0d52, 0x0008))
#define ram0x00024180 (*(undefined1 far *)MK_FP(ST_DGROUP_SEG, 0x0080))
#define ram0x00024186 (*(undefined1 far *)MK_FP(ST_DGROUP_SEG, 0x0086))
#define ram0x0002c9bb (*(undefined1 far *)MK_FP(ST_DGROUP_SEG, 0x88bb))
extern undefined1 stack0x0000;
extern undefined1 stack0x0004;
extern undefined1 stack0x0007;
extern undefined1 stack0x0035;
extern undefined1 stack0x02c2;
extern undefined1 stack0x681c;
extern undefined1 stack0x6ffe;
extern undefined1 stack0x8d06;
extern undefined1 stack0x8ed6;
extern undefined1 stack0xbac4;
extern undefined1 stack0xc1dd;
extern undefined1 stack0xd744;
extern undefined1 stack0xfc0c;
extern undefined1 stack0xfc0e;
extern undefined1 stack0xfe0a;
extern undefined1 stack0xfe3a;
extern undefined1 stack0xfecc;
extern undefined1 stack0xfed4;
extern undefined1 stack0xfed6;
extern undefined1 stack0xfed8;
extern undefined1 stack0xfeda;
extern undefined1 stack0xfedc;
extern undefined1 stack0xfef4;
extern undefined1 stack0xff60;
extern undefined1 stack0xff61;
extern undefined1 stack0xff74;
extern undefined1 stack0xffaa;
extern undefined1 stack0xffaf;
extern undefined1 stack0xffb4;
extern undefined1 stack0xffbc;
extern undefined1 stack0xffd4;
extern undefined1 stack0xffd6;
extern undefined1 stack0xffdc;
extern undefined1 stack0xffde;
extern undefined1 stack0xffe0;
extern undefined1 stack0xffe2;
extern undefined1 stack0xffe4;
extern undefined1 stack0xffe8;
extern undefined1 stack0xffe9;
extern undefined1 stack0xffea;
extern undefined1 stack0xffeb;
extern undefined1 stack0xffec;
extern undefined1 stack0xfff0;
extern undefined1 stack0xfff2;
extern undefined1 stack0xfff5;
extern undefined1 stack0xfff6;
extern undefined1 stack0xfff8;
extern undefined1 stack0xfffa;
extern undefined1 stack0xfffc;
extern undefined1 stack0xfffe;
extern undefined1 stack0xffff;
#define uRam00000064 (*(undefined2 far *)MK_FP(0x0000, 0x0064))
#define uRam00000066 (*(undefined2 far *)MK_FP(0x0000, 0x0066))
#define uRam000000fa (*(undefined2 far *)MK_FP(0x0000, 0x00fa))
#define uRam000000fc (*(undefined2 far *)MK_FP(0x0000, 0x00fc))
#define uRam000000fe (*(undefined2 far *)MK_FP(0x0000, 0x00fe))
#define uRam000100f6 (*(undefined2 far *)MK_FP(0x100f, 0x0006))
#define uRam000100f8 (*(undefined2 far *)MK_FP(0x100f, 0x0008))
#define uRam000100fa (*(undefined2 far *)MK_FP(0x100f, 0x000a))
#define uRam000100fc (*(undefined2 far *)MK_FP(0x100f, 0x000c))
#define uRam000100fe (*(undefined2 far *)MK_FP(0x100f, 0x000e))
#define uRam00010102 (*(undefined2 far *)MK_FP(0x1010, 0x0002))
#define uRam00010104 (*(undefined2 far *)MK_FP(0x1010, 0x0004))
#define uRam0002db84 (*(undefined2 far *)MK_FP(ST_DGROUP_SEG, 0x9a84))
extern uint16_t unaff_BP;
extern uint16_t unaff_DI;
extern uint32_t unaff_ES;
extern uint16_t unaff_SI;
extern uint16_t unaff_SS;
#endif
