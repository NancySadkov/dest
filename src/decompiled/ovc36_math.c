/*
 * ovc36_math.c - recovered from STRONG.EXE
 * memory block: OVC36_math.c
 * range: 67d1:0000 - 67d1:015f
 * functions: 1
 */
#include "recovered.h"


/* 67d1:0000 */

/* [R4] calls LDIV_at_ */

uint __cdecl16far ovc36_usesLDIV_at_(byte partyIndex)

{
  long *plVar1;
  uint16_t uVar2;
  uint16_t unaff_SI;
  int iVar3;
  uint unaff_DI;
  uint uVar4;
  long lVar5;
  long lVar6;
  long *plVar7;
  uint16_t uVar8;
  uint16_t uVar9;
  uint32_t in_stack_0000fffa;
  int iVar10;
  
  lVar6 = CONCAT22((int)((ulong)in_stack_0000fffa >> 0x10),unaff_SI);
  if ((GLeaderSheets[partyIndex])->population == 0) {
    uVar4 = (uint)(partyIndex >> 6) << 8;
  }
  else {
    uVar8 = 0;
    plVar7 = (long *)(GLeaderSheets[partyIndex])->population;
    uVar2 = 0;
    plVar1 = LXMUL_at_(plVar7,(ulong)unaff_DI << 0x10,lVar6);
    lVar5 = LDIV_at_((long)CONCAT22(uVar2,plVar1),(long)CONCAT22(uVar8,plVar7));
    uVar4 = (uint)lVar5;
    if (200 < uVar4) {
      uVar4 = 200;
    }
    uVar8 = 0;
    plVar7 = (long *)(GLeaderSheets[partyIndex])->population;
    uVar2 = 0;
    plVar1 = LXMUL_at_(plVar7,(ulong)unaff_DI << 0x10,lVar6);
    uVar9 = (uint16_t)lVar6;
    lVar6 = LDIV_at_((long)CONCAT22(uVar2,plVar1),(long)CONCAT22(uVar8,plVar7));
    lVar5 = CONCAT22((uint)lVar6,uVar9);
    if (200 < (uint)lVar6) {
      lVar5 = CONCAT22(200,uVar9);
    }
    uVar8 = 0;
    plVar7 = (long *)(GLeaderSheets[partyIndex])->population;
    uVar2 = 0;
    plVar1 = LXMUL_at_(plVar7,(ulong)unaff_DI << 0x10,lVar5);
    iVar10 = (int)((ulong)lVar5 >> 0x10);
    lVar6 = LDIV_at_((long)CONCAT22(uVar2,plVar1),(long)CONCAT22(uVar8,plVar7));
    iVar3 = (int)lVar6;
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


