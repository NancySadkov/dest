/*
 * ovc36_math.c - recovered from STRONG.EXE
 * memory block: OVC36_math.c
 * range: 67d1:0000 - 67d1:015f
 * functions: 1
 */
#include "recovered.h"


/* 67d1:0000 */

/* [R4] calls LDIV_at_ */

uint __cdecl16far ovc36_usesLDIV_at_(byte partyIndex,...)

{
  long *plVar1;
  undefined2 uVar2;
  undefined2 unaff_BP;
  undefined2 unaff_SI;
  int iVar3;
  undefined2 unaff_DI;
  uint uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  byte in_stack_00000004;
  ulong uVar8;
  undefined2 in_stack_0000fffc;
  uint uVar9;
  int iVar10;
  undefined2 uVar11;
  
  lVar6 = CONCAT22(unaff_BP,in_stack_0000fffc);
  lVar7 = CONCAT22(unaff_SI,unaff_DI);
  if (*(int *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x4d) == 0) {
    uVar4 = (uint)(in_stack_00000004 >> 6) << 8;
  }
  else {
    uVar8 = (ulong)*(uint *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x4d);
    uVar2 = 0;
    plVar1 = LXMUL_at_((long *)0x0,lVar7,lVar6);
    lVar5 = LDIV_at_((long)CONCAT22(uVar2,plVar1),uVar8);
    uVar4 = (uint)lVar5;
    if (200 < uVar4) {
      uVar4 = 200;
    }
    uVar8 = (ulong)*(uint *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x4d);
    uVar2 = 0;
    plVar1 = LXMUL_at_((long *)0x0,lVar7,lVar6);
    uVar11 = (undefined2)((ulong)lVar6 >> 0x10);
    lVar6 = LDIV_at_((long)CONCAT22(uVar2,plVar1),uVar8);
    uVar9 = (uint)lVar6;
    if (200 < uVar9) {
      uVar9 = 200;
    }
    lVar6 = CONCAT22(uVar11,uVar9);
    uVar8 = (ulong)*(uint *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x4d);
    uVar2 = 0;
    plVar1 = LXMUL_at_((long *)0x0,lVar7,lVar6);
    iVar10 = (int)lVar6;
    lVar7 = LDIV_at_((long)CONCAT22(uVar2,plVar1),uVar8);
    iVar3 = (int)lVar7;
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    if (200 < iVar3) {
      iVar3 = 200;
    }
    uVar4 = (uVar4 + iVar10 + iVar3) / 6;
  }
  return uVar4;
}


