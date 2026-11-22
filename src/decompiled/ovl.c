/*
 * ovl.c - recovered from STRONG.EXE
 * memory block: 1403_OVRTEXT_
 * range: 1403:0002 - 1403:125f
 * functions: 53
 */
#include "recovered.h"


/* 1403:000d */
undefined2 __stdcall16far __OVRINIT(void)

{
  code *pcVar1;
  uint in_AX;
  undefined2 uVar2;
  bool bVar3;
  uint in_stack_00000004;
  uint in_stack_00000006;
  int iStack_16;
  
  uVar2 = (uint)startx;   /* hand fix: startx is a function */
  bVar3 = false;
  if (*(int *)((int)&GUnitDescriptions[9].ofs + 1) == 0) {
    uVar2 = 0;
  }
  else {
    __OvrExeOpenEnv();
    if (bVar3) {
      bVar3 = false;
      in_AX = in_stack_00000004 | in_stack_00000006;
      __OvrExeOpenFilename();
      if ((bVar3) && (__OvrExeOpenEnvPath(), bVar3)) {
        return 0xfffe;
      }
    }
    bVar3 = false;
    *(uint *)((int)&GUnitDescriptions[0xf].ofs + 1) = in_AX;
    __OvrReadHeader();
    if ((!bVar3) && (iStack_16 == 0x5a4d)) {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)();
      __OvrReadHeader();
    }
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    uVar2 = 0xffff;
  }
  return uVar2;
}


/* 1403:013d */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far __OvrResetInterruptVector(void)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined2 in_BX;
  undefined2 unaff_ES;
  undefined2 in_stack_00000000;
  undefined2 in_stack_00000002;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)(in_BX);
  *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = in_stack_00000000;
  *(undefined2 *)(byte *)__C0_ASM_CopyRight = in_stack_00000002;
  if (*(int *)((int)&GUnitDescriptions[0xf].ofs + 1) == 0) {
    pcVar1 = (code *)swi(0x21);
    uVar2 = (*pcVar1)();
    *(undefined2 *)((int)&GUnitDescriptions[0xf].ofs + 1) = uVar2;
  }
  else {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    *(undefined2 *)((int)&GUnitDescriptions[0xf].ofs + 1) = 0;
  }
  return;
}



/* 1403:0190 */
void __cdecl16far __OVREXIT(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  uVar1 = (uint)startx;   /* hand fix: startx is a function */
  uVar2 = 0x2410;
  if (*(int *)((int)&GUnitDescriptions[0xf].ofs + 1) != 0) {
    __OvrResetInterruptVector();
  }
  (*(code *)*(undefined2 *)&__CALLEMSEXIT)(0x1000,uVar2);
  (*(code *)*(undefined2 *)&__CALLEXTEXIT)(0x1000);
  return;
}


/* 1403:01b2 */

void __cdecl16near __OvrExeOpenFilename(void)

{
  OvrDoOpenFile();
  return;
}



/* 1403:01be */

void __cdecl16near __OvrExeOpenEnv(void)

{
  char *pcVar1;
  char cVar2;
  code *pcVar3;
  undefined2 uVar4;
  byte bVar5;
  char *pcVar6;
  char *pcVar7;
  undefined2 uStack0002;
  
  pcVar3 = (code *)swi(0x21);
  bVar5 = (*pcVar3)();
  uVar4 = _envseg_at_;
  if (2 < bVar5) {
    __C0_ASM_CopyRight[2] = 0x20;
    uStack0002 = 0x2410;
    pcVar7 = (char *)0x0;
    do {
      do {
        pcVar6 = pcVar7;
        pcVar7 = pcVar6 + 1;
      } while (*pcVar6 != '\0');
      pcVar7 = pcVar6 + 2;
    } while (pcVar6[1] != '\0');
    pcVar6 = pcVar6 + 4;
    pcVar7 = (char *)((int)&_brklvl.ofs + 1);
    do {
      pcVar1 = pcVar6;
      pcVar6 = pcVar6 + 1;
      cVar2 = *pcVar1;
      pcVar1 = pcVar7;
      pcVar7 = pcVar7 + 1;
      *pcVar1 = cVar2;
    } while (cVar2 != '\0');
    OvrDoOpenFile();
  }
  return;
}



/* 1403:0203 */

void __cdecl16near __OvrExeOpenEnvPath(void)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  byte *pbVar4;
  undefined2 uVar5;
  byte bVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  bool bVar10;
  
  uVar5 = _envseg_at_;
  pbVar8 = (byte *)0x0;
  bVar10 = true;
  do {
    pbVar9 = (byte *)__C0_ASM_CopyRight + 2;
    iVar7 = 5;
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pbVar4 = pbVar9;
      pbVar9 = pbVar9 + 1;
      pbVar1 = pbVar8;
      pbVar8 = pbVar8 + 1;
      bVar10 = *pbVar1 == *pbVar4;
    } while (bVar10);
    if (bVar10) {
      do {
        if (*pbVar8 == 0) {
          return;
        }
        pbVar9 = (byte *)((int)&_brklvl.ofs + 1);
        bVar6 = 0;
        while( true ) {
          pbVar2 = pbVar8 + 1;
          bVar3 = *pbVar8;
          if ((bVar3 == 0) || (pbVar8 = pbVar2, bVar3 == 0x3b)) break;
          pbVar1 = pbVar9;
          pbVar9 = pbVar9 + 1;
          *pbVar1 = bVar3;
          bVar6 = bVar3;
        }
        bVar10 = bVar6 < 0x3a;
        if ((bVar6 != 0x3a) && (bVar10 = bVar6 < 0x5c, bVar6 != 0x5c)) {
          *pbVar9 = 0x5c;
        }
        OvrDoOpenFile();
      } while (bVar10);
      return;
    }
    pbVar8 = pbVar8 + -1;
    do {
      pbVar1 = pbVar8;
      pbVar8 = pbVar8 + 1;
    } while (*pbVar1 != 0);
    bVar10 = false;
    if (*pbVar8 == 0) {
      return;
    }
  } while( true );
}



/* 1403:0260 */

void __cdecl16near OvrDoOpenFile(void)

{
  char *pcVar1;
  char cVar2;
  code *pcVar3;
  int iVar4;
  int unaff_BP;
  char *pcVar5;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  int iVar6;
  
  iVar6 = (int)((ulong)*(undefined4 *)(unaff_BP + 6) >> 0x10);
  pcVar5 = (char *)(char *)*(undefined4 *)(unaff_BP + 6);
  if (iVar6 != 0 || pcVar5 != (char *)0x0) {
    iVar4 = 0xc;
    do {
      pcVar1 = pcVar5;
      pcVar5 = pcVar5 + 1;
      cVar2 = *pcVar1;
      pcVar1 = unaff_DI;
      unaff_DI = unaff_DI + 1;
      *pcVar1 = cVar2;
      if (cVar2 == '\0') goto L_OvrDoOpenFile_0275;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    *unaff_DI = '\0';
  }
L_OvrDoOpenFile_0275:
  pcVar3 = (code *)swi(0x21);
  (*pcVar3)();
  return;
}



/* 1403:0288 */

void __cdecl16near __OvrReadHeader(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  return;
}



/* 1403:0298 */

undefined2 __cdecl16near __InitModules(void)

{
  uint *puVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  undefined2 uVar6;
  bool bVar7;
  
  iRam0001000b = _psp + 0x10;
                    /* WARNING: Read-only address (ram,0x0001000b) is written */
  uVar6 = 0x226e;
  uVar4 = 0;
  pcVar5 = (char *)0x242a0;
  do {
    if (((*(uint *)(pcVar5 + 4) & 2) != 0) && (*(int *)(pcVar5 + 2) != 0)) {
      uVar2 = *(undefined2 *)pcVar5;
      *(undefined2 *)((byte *)__C0_ASM_CopyRight + 0xe) = uVar2;
      if (((byte *)__C0_ASM_CopyRight)[0x16] == 0xff) {
        ((byte *)__C0_ASM_CopyRight + 0xe)[0] = 0;
        ((byte *)__C0_ASM_CopyRight + 0xe)[1] = 0;
      }
      else {
        ((byte *)__C0_ASM_CopyRight + 0x14)[0] = 0xc3;
        uVar3 = (*(uint16_t *)((uint8_t *)&(GUnitDescriptions) + 43));
        ((byte *)__C0_ASM_CopyRight + 0x14)[1] = 4;
        puVar1 = (uint *)__C0_ASM_CopyRight;
        bVar7 = CARRY2(*puVar1,(*(uint16_t *)((uint8_t *)&(GUnitDescriptions[10]) + 1)));
        *puVar1 = *puVar1 + (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[10]) + 1));
        *(uint *)((byte *)__C0_ASM_CopyRight + 2) =
             *(int *)((byte *)__C0_ASM_CopyRight + 2) + uVar3 + (uint)bVar7;
        __OvrCalcSize();
        uVar6 = uVar2;
        if (uVar4 < uVar3) {
          uVar4 = uVar3;
        }
      }
    }
    pcVar5 = pcVar5 + 8;
  } while (pcVar5 < (char *)0x478);
  (*(uint16_t *)((uint8_t *)&(GUnitDescriptions) + 47)) = uVar4 + 2;
  return 0;
}



/* 1403:0318 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16near __OvrInitReadSegs(void)

{
  undefined2 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  undefined2 uVar7;
  
  uVar7 = (*(uint16_t *)((uint8_t *)&(GUnitDescriptions) + 59));
  (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0x10]) + 1)) = (*(uint16_t *)((uint8_t *)&(GUnitDescriptions) + 55));
  iVar3 = (*(uint16_t *)((uint8_t *)&(GUnitDescriptions) + 55));
  iVar5 = (*(uint16_t *)((uint8_t *)&(GUnitDescriptions) + 55));
  (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0xd]) + 1)) = (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0xe]) + 1));
  while ((iVar4 = iVar3, iVar3 = *(int *)((byte *)__C0_ASM_CopyRight + 0xe), iVar3 != 0 &&
         (uVar2 = (int)(CONCAT22((*(int *)((byte *)__C0_ASM_CopyRight + 2) -
                                 *(int *)((byte *)__C0_ASM_CopyRight + 2)) -
                                 (uint)(*(uint *)__C0_ASM_CopyRight < *(uint *)__C0_ASM_CopyRight),
                                 *(uint *)__C0_ASM_CopyRight - *(uint *)__C0_ASM_CopyRight) / 0x10)
                  + (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0xd]) + 1)), uVar2 <= (uint)uVar7))) {
    *(undefined2 *)((byte *)__C0_ASM_CopyRight + 0xc) = (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0xd]) + 1));
    *(int *)((byte *)__C0_ASM_CopyRight + 0x18) = iVar3;
    iVar5 = iVar4;
    (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0xd]) + 1)) = uVar2;
  }
  ((byte *)__C0_ASM_CopyRight + 0x18)[0] = 0;
  ((byte *)__C0_ASM_CopyRight + 0x18)[1] = 0;
  if ((*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0xd]) + 1)) != (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0xe]) + 1))) {
    bVar6 = false;
    __OvrRead();
    if (!bVar6) {
      uVar7 = 0x2410;
      iVar3 = (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0x10]) + 1));
      do {
        if (*(int *)((byte *)__C0_ASM_CopyRight + 6) != 0) {
          __OvrDoFixups();
        }
        if (*(int *)((byte *)__C0_ASM_CopyRight + 8) != 0) {
          __OvrUntrapJmps();
        }
        *(int *)((byte *)__C0_ASM_CopyRight + 10) = iVar3;
        puVar1 = (undefined2 *)((int)(uint16_t *)&__brklvl + 1);
        (*(code *)*puVar1)(0x1000,iVar3,uVar7);
        iVar3 = *(int *)((byte *)__C0_ASM_CopyRight + 0x18);
      } while (iVar3 != 0);
    }
  }
  return;
}



/* 1403:03d8 */

/* rotates the DX_AX dword right by four bits */

uint __cdecl16near ovl_rotateRight4(void)

{
  uint in_AX;
  int in_DX;
  
  return in_AX >> 4 | in_DX << 0xc;
}



/* 1403:03e5 */

void __cdecl16near __OvrRead(void)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  uint unaff_SI;
  int unaff_DI;
  bool bVar4;
  undefined2 uStack0002;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  uStack0002 = 0x2410;
  do {
    uVar3 = 0xfff0;
    if (unaff_DI == 0) {
      uVar3 = unaff_SI;
    }
    bVar4 = false;
    pcVar1 = (code *)swi(0x21);
    uVar2 = (*pcVar1)();
    if (bVar4) {
      return;
    }
    if (uVar2 < uVar3) {
      return;
    }
    bVar4 = unaff_SI < uVar2;
    unaff_SI = unaff_SI - uVar2;
    unaff_DI = unaff_DI - (uint)bVar4;
  } while (unaff_SI != 0 || unaff_DI != 0);
  return;
}



/* 1403:041e */

void __cdecl16near __OvrDoFixups(void)

{
  uint uVar1;
  undefined2 *puVar2;
  int iVar3;
  uint uVar4;
  uint in_CX;
  uint uVar5;
  undefined2 *puVar6;
  undefined2 unaff_ES;
  
  uVar1 = *(uint *)((byte *)__C0_ASM_CopyRight + 4);
  puVar6 = (undefined2 *)(uVar1 & 0xf);
  iVar3 = *(int *)((byte *)__C0_ASM_CopyRight + 0xc);
  uVar5 = in_CX >> 1;
  do {
    puVar2 = puVar6;
    puVar6 = puVar6 + 1;
    uVar4 = *(uint *)*puVar2;
    *(uint *)*puVar2 = *(uint *)(uVar4 & 0xfff8);
    if ((uVar4 & 1) != 0) {
      __OvrFixupFunref();
    }
    uVar5 = uVar5 - 1;
  } while (uVar5 != 0);
  return;
}



/* 1403:0463 */

void __cdecl16near __OvrFixupFunref(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined2 in_DX;
  int in_BX;
  int iVar4;
  undefined2 unaff_ES;
  
  uVar1 = CONCAT11(*(undefined1 *)(in_BX + -1),*(undefined1 *)(in_BX + -1)) & 0xf807;
  if (((((char)(uVar1 >> 8) == -0x48) &&
       (uVar2 = CONCAT11(*(undefined1 *)(in_BX + 2),*(undefined1 *)(in_BX + 2)) & 0xf807,
       (char)(uVar2 >> 8) == 'P')) && ((char)uVar2 == (char)uVar1)) &&
     ((uVar1 == (CONCAT11(*(undefined1 *)(in_BX + 3),*(undefined1 *)(in_BX + 3)) & 0xf807) &&
      ((CONCAT11(*(undefined1 *)(in_BX + 6),*(undefined1 *)(in_BX + 6)) & 0xf807) == uVar2)))) {
    iVar4 = 0x20;
    iVar3 = *(int *)((byte *)__C0_ASM_CopyRight + 8);
    while (*(int *)(in_BX + 4) != *(int *)(iVar4 + 2)) {
      iVar4 = iVar4 + 5;
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) {
        return;
      }
    }
    *(int *)(in_BX + 4) = iVar4;
  }
  return;
}



/* 1403:04c3 */

void __cdecl16near __ReadOvrDisk(void)

{
  undefined2 unaff_ES;
  bool bVar1;
  
  bVar1 = false;
  __OvrRead();
  if ((!bVar1) && (*(int *)((byte *)__C0_ASM_CopyRight + 6) != 0)) {
    __OvrDoFixups();
  }
  return;
}



/* 1403:04f1 */

/* WARNING: Removing unreachable block (ram,0x0001452a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

undefined2 __OvrTrapHandler(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  undefined4 in_stack_00000000;
  
  if ((int)in_stack_00000000 == 2) {
    __OvrFixupTrap();
  }
  else {
    LOCK();
    UNLOCK();
    __OvrFixupTrap();
    LOCK();
    UNLOCK();
  }
  ((byte *)__C0_ASM_CopyRight)[0x16] = ((byte *)__C0_ASM_CopyRight)[0x16] & 0xf7;
  puVar1 = (undefined2 *)((int)(uint16_t *)&__brklvl + 1);
  (*(code *)*puVar1)(0x1000);
  return in_AX;
}



/* 1403:0557 */

void __cdecl16near __OvrAllocateSpace(void)

{
  byte *pbVar1;
  uint uVar2;
  uint in_DX;
  undefined2 unaff_ES;
  byte in_CF;
  
  (*(uint16_t *)((uint8_t *)&(GUnitDescriptions) + 63)) = (*(uint16_t *)((uint8_t *)&(GUnitDescriptions) + 63)) + 1;
  __OvrCalcSize();
  while( true ) {
    uVar2 = __OvrGetSegMemInfo();
    if (in_DX <= uVar2) break;
    if ((in_CF & 1) != 0) {
      __OvrAddToLoadList();
    }
    in_CF = 0;
    if (((byte *)__C0_ASM_CopyRight)[0x17] == 0) {
      (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0x10]) + 1)) = *(undefined2 *)((byte *)__C0_ASM_CopyRight + 0x18);
      __OvrAllocEvict();
      __OvrCalcCodeSz();
    }
    else {
      pbVar1 = (byte *)__C0_ASM_CopyRight + 0x17;
      (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0x10]) + 1)) = *(undefined2 *)((byte *)__C0_ASM_CopyRight + 0x18);
      *pbVar1 = *pbVar1 - 1;
      __OvrCompactHeap();
      __OvrAddToLoadList_2();
    }
  }
  *(undefined2 *)((byte *)__C0_ASM_CopyRight + 0xc) = (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0xd]) + 1));
  return;
}



/* 1403:05a1 */

void __cdecl16near __OvrFixupTrap(void)

{
  int iVar1;
  int in_AX;
  uint uVar2;
  uint uVar3;
  undefined2 unaff_ES;
  int iVar4;
  undefined1 uVar5;
  
  (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0xc]) + 1)) = (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0xc]) + 1)) + 1;
  if (*(int *)((byte *)__C0_ASM_CopyRight + 0xc) == 0) {
    uVar5 = 0;
    ((byte *)__C0_ASM_CopyRight)[0x16] = ((byte *)__C0_ASM_CopyRight)[0x16] | 8;
    __OvrAllocateSpace();
    *(undefined2 *)((byte *)__C0_ASM_CopyRight + 10) = unaff_ES;
    (**(code **)((byte *)__C0_ASM_CopyRight + 0x14))();
    if ((bool)uVar5) {
      __OverlayHalt();
      return;
    }
    __OvrAddToLoadList_2();
  }
  else {
    ((byte *)__C0_ASM_CopyRight)[0x17] = 1;
    ((byte *)__C0_ASM_CopyRight)[0x16] = ((byte *)__C0_ASM_CopyRight)[0x16] | 4;
  }
  __OvrUntrapJmpsAndStack();
  ((byte *)__C0_ASM_CopyRight)[0x17] =
       ((byte *)__C0_ASM_CopyRight)[0x17] + (((byte *)__C0_ASM_CopyRight)[0x16] & 3);
  uVar2 = __OvrGetSegMemInfo();
  iVar4 = (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0x10]) + 1));
  for (; (iVar1 = *(int *)((byte *)__C0_ASM_CopyRight + 0x18), iVar1 != 0 &&
         (uVar2 < (uint)(*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0xb]) + 1)))); uVar2 = uVar3 + uVar2) {
    if (((byte *)__C0_ASM_CopyRight)[0x17] == 0) {
      __OvrTrapJmpsAndStack();
      uVar3 = __OvrCalcCodeSz();
    }
    else {
      uVar3 = 0;
    }
    iVar4 = iVar1;
  }
  return;
}



/* 1403:061c */
void __cdecl16near __OvrAllocEvict(void)

{
  undefined2 unaff_ES;
  
  __OvrTrapJmpsAndStack();
  if (*(int *)((byte *)__C0_ASM_CopyRight + 0x14) == 0x4c3) {
    (*(code **)&ram0x00024180)();
  }
  ((byte *)__C0_ASM_CopyRight + 0xc)[0] = 0;
  ((byte *)__C0_ASM_CopyRight + 0xc)[1] = 0;
  return;
}


/* 1403:0634 */

void __cdecl16near __OvrAddToLoadList(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  do {
    iVar4 = (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0x10]) + 1));
    iVar2 = iVar2 + 1;
    (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0x10]) + 1)) = *(undefined2 *)((byte *)__C0_ASM_CopyRight + 0x18);
  } while ((*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0x10]) + 1)) != 0);
  (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0xd]) + 1)) = (*(uint16_t *)((uint8_t *)&(GUnitDescriptions) + 59));
  do {
    iVar3 = iVar2;
    *(undefined2 *)((byte *)__C0_ASM_CopyRight + 0x18) = (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0x10]) + 1));
    (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0x10]) + 1)) = iVar4;
    uVar1 = __OvrCalcCodeSz();
    (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0xd]) + 1)) = (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0xd]) + 1)) - uVar1;
    __OvrCompactHeap();
    iVar2 = iVar3 + -1;
    iVar4 = iVar3;
  } while (iVar2 != 0);
  (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0xd]) + 1)) = (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0xe]) + 1));
  return;
}



/* 1403:066f */

void __cdecl16near __OvrUntrapJmpsAndStack(void)

{
  byte *pbVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  byte *pbVar5;
  undefined2 unaff_ES;
  
  if (*(int *)((byte *)__C0_ASM_CopyRight + 8) == 0) {
    return;
  }
  if (((byte *)__C0_ASM_CopyRight)[0x1c] != 0xea) {
    if (*(int *)((int)(undefined4 *)&_DATA + 2) != 0) {
      __OvrPatchStack();
    }
    uVar2 = *(undefined2 *)((byte *)__C0_ASM_CopyRight + 0xc);
    iVar4 = *(int *)((byte *)__C0_ASM_CopyRight + 8);
    pbVar5 = (byte *)__C0_ASM_CopyRight + 0x1c;
    do {
      uVar3 = *(undefined2 *)(pbVar5 + 2);
      *pbVar5 = 0xea;
      pbVar1 = pbVar5 + 3;
      *(undefined2 *)(pbVar5 + 1) = uVar3;
      pbVar5 = pbVar5 + 5;
      *(undefined2 *)pbVar1 = uVar2;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}



/* 1403:0690 */

void __cdecl16near __OvrUntrapJmps(void)

{
  byte *pbVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  byte *pbVar5;
  undefined2 unaff_ES;
  
  uVar2 = *(undefined2 *)((byte *)__C0_ASM_CopyRight + 0xc);
  iVar4 = *(int *)((byte *)__C0_ASM_CopyRight + 8);
  pbVar5 = (byte *)__C0_ASM_CopyRight + 0x1c;
  do {
    uVar3 = *(undefined2 *)(pbVar5 + 2);
    *pbVar5 = 0xea;
    pbVar1 = pbVar5 + 3;
    *(undefined2 *)(pbVar5 + 1) = uVar3;
    pbVar5 = pbVar5 + 5;
    *(undefined2 *)pbVar1 = uVar2;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}



/* 1403:06ae */

void __cdecl16near __OvrTrapJmpsAndStack(void)

{
  byte *pbVar1;
  undefined2 uVar2;
  int iVar3;
  byte *pbVar4;
  undefined2 unaff_ES;
  
  if (((byte *)__C0_ASM_CopyRight)[0x1c] != 0xcd) {
    uVar2 = 0;
    __OvrPatchStack();
    *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = uVar2;
    iVar3 = *(int *)((byte *)__C0_ASM_CopyRight + 8);
    pbVar4 = (byte *)__C0_ASM_CopyRight + 0x1c;
    do {
      uVar2 = *(undefined2 *)(pbVar4 + 1);
      *(undefined2 *)pbVar4 = (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[9]) + 1));
      pbVar1 = pbVar4 + 4;
      *(undefined2 *)(pbVar4 + 2) = uVar2;
      pbVar4 = pbVar4 + 5;
      *pbVar1 = 0;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}



/* 1403:06e1 */

undefined2 __cdecl16near __OvrCompactHeap(void)

{
  undefined2 *puVar1;
  uint uVar2;
  undefined2 uVar3;
  uint uVar4;
  int iVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  byte *pbVar8;
  undefined2 unaff_ES;
  bool bVar9;
  
  uVar3 = (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0xd]) + 1));
  uVar2 = *(uint *)((byte *)__C0_ASM_CopyRight + 0xc);
  *(undefined2 *)((byte *)__C0_ASM_CopyRight + 0xc) = (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0xd]) + 1));
  uVar4 = *(int *)((byte *)__C0_ASM_CopyRight + 4) + 1U >> 1;
  puVar6 = (undefined2 *)0x0;
  bVar9 = uVar2 <= (uint)uVar3;
  puVar7 = puVar6;
  if (bVar9) {
    puVar6 = (undefined2 *)((uVar4 - 1) * 2);
    puVar7 = puVar6;
  }
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    puVar1 = puVar6;
    puVar6 = puVar6 + (uint)bVar9 * -2 + 1;
    *puVar7 = *puVar1;
    puVar7 = puVar7 + (uint)bVar9 * -2 + 1;
  }
  *(undefined2 *)((byte *)__C0_ASM_CopyRight + 10) = unaff_ES;
  if (((byte *)__C0_ASM_CopyRight)[0x1c] != 0xcd) {
    __OvrPatchStack_2();
    iVar5 = *(int *)((byte *)__C0_ASM_CopyRight + 8);
    pbVar8 = (byte *)__C0_ASM_CopyRight + 0x1f;
    do {
      *(undefined2 *)pbVar8 = uVar3;
      pbVar8 = pbVar8 + 5;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return uVar3;
}



/* 1403:0732 */

/* duplicate name, disambiguated by address order */

void __cdecl16near __OvrAddToLoadList_2(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined2 unaff_ES;
  
  uVar2 = __OvrCalcCodeSz();
  (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0xd]) + 1)) = (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0xd]) + 1)) + uVar2;
  iVar1 = 0x226e;
  do {
    iVar3 = iVar1;
    iVar1 = *(int *)((byte *)__C0_ASM_CopyRight + 0x18);
  } while (*(int *)((byte *)__C0_ASM_CopyRight + 0x18) != 0);
  *(undefined2 *)((byte *)__C0_ASM_CopyRight + 0x18) = unaff_ES;
  ((byte *)__C0_ASM_CopyRight + 0x18)[0] = 0;
  ((byte *)__C0_ASM_CopyRight + 0x18)[1] = 0;
  return;
}



/* 1403:0750 */

void __cdecl16near __OvrPatchStack(void)

{
  undefined2 in_CX;
  int in_BX;
  undefined2 unaff_SS;
  
  __OvrPatchStack_2();
  if (in_BX != 0) {
    LOCK();
    *(undefined2 *)(in_BX + 2) = in_CX;
    UNLOCK();
  }
  return;
}



/* 1403:075c */

/* duplicate name, disambiguated by address order */

void __cdecl16near __OvrPatchStack_2(void)

{
  uint in_AX;
  uint uVar1;
  uint in_DX;
  uint *puVar2;
  uint *unaff_BP;
  undefined2 unaff_SS;
  
  puVar2 = (uint *)0x0;
  while( true ) {
    uVar1 = *unaff_BP >> 1;
    if (uVar1 == 0) break;
    if ((((*unaff_BP & 1) == 0) && (in_DX == unaff_BP[2])) &&
       (unaff_BP[2] = in_AX, puVar2 == (uint *)0x0)) {
      puVar2 = unaff_BP;
    }
    unaff_BP = (uint *)(uVar1 << 1);
  }
  return;
}



/* 1403:0782 */

int __cdecl16near __OvrGetSegMemInfo(void)

{
  int iVar1;
  
  if (((*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0x10]) + 1)) == 0) ||
     (iVar1 = *(uint *)((byte *)__C0_ASM_CopyRight + 0xc) - (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0xd]) + 1)),
     *(uint *)((byte *)__C0_ASM_CopyRight + 0xc) < (uint)(*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0xd]) + 1)))) {
    iVar1 = (*(uint16_t *)((uint8_t *)&(GUnitDescriptions) + 59)) - (*(uint16_t *)((uint8_t *)&(GUnitDescriptions[0xd]) + 1));
  }
  return iVar1;
}



/* 1403:079e */

uint __cdecl16near __OvrCalcCodeSz(void)

{
  undefined2 unaff_ES;
  
  return *(int *)((byte *)__C0_ASM_CopyRight + 4) + 0x11U >> 4;
}



/* 1403:07aa */

void __cdecl16near __OvrCalcSize(void)

{
  return;
}



/* 1403:07c2 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far __ISOVERLAYMOD(void)

{
  uint in_AX;
  undefined2 uVar1;
  
  if ((((in_AX < *(uint *)((int)&GUnitDescriptions[0xe].ofs + 1)) ||
       (*(uint *)((int)&GUnitDescriptions[0xe].seg + 1) <= in_AX)) ||
      (uVar1 = *(undefined2 *)((byte *)__C0_ASM_CopyRight + 10),
      *(int *)((int)&GUnitDescriptions[9].ofs + 1) != *(int *)0x0)) ||
     (in_AX != *(uint *)((byte *)__C0_ASM_CopyRight + 0xc))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 1403:07f8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far __CHECKSTACK(void)

{
  undefined1 stk_fffe;   /* stack slot fffe */
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  uint *in_CX;
  uint *puVar6;
  uint uVar7;
  undefined2 unaff_SS;
  
  bVar5 = false;
  iVar2 = *(int *)((int)&GUnitDescriptions[9].ofs + 1);
  uVar3 = *(uint *)((int)&GUnitDescriptions[0xe].ofs + 1);
  puVar6 = (uint *)&stk_fffe;
  while (puVar6 < in_CX) {
    uVar7 = *puVar6 >> 1;
    if (uVar7 == 0) break;
    if (((((*puVar6 & 1) == 0) && (uVar4 = puVar6[2], uVar4 < uVar3)) && (puVar6[1] == 0)) &&
       (*(int *)0x0 == iVar2)) {
      bVar5 = true;
      *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = 0;
    }
    puVar6 = (uint *)(uVar7 << 1);
  }
  if (bVar5) {
    while( true ) {
      uVar7 = *puVar6 >> 1;
      if (uVar7 == 0) break;
      if ((((*puVar6 & 1) == 0) && (uVar4 = puVar6[2], uVar4 < uVar3)) &&
         ((puVar6[1] != 0 &&
          ((*(int *)0x0 == iVar2 && (*(int *)((int)(undefined4 *)&_DATA + 2) == 0)))))) {
        LOCK();
        puVar1 = (uint *)((int)(undefined4 *)&_DATA + 2);
        uVar4 = *puVar1;
        *puVar1 = puVar6[1];
        UNLOCK();
        puVar6[1] = uVar4;
      }
      puVar6 = (uint *)(uVar7 << 1);
    }
  }
  return;
}



/* 1403:08e8 */
int __cdecl16far _OvrInitEms(uint16_t emsHandle,uint16_t firstPage,uint16_t pages)

{
  long lVar1;
  long lVar2;
  undefined2 uVar3;
  uint uVar4;
  uint16_t uVar5;
  undefined2 uVar6;
  
  uVar3 = (uint)startx;   /* hand fix: startx is a function */
  if ((((byte *)__C0_ASM_CopyRight)[0xc] & 1) == 0) {
    if (emsHandle == 0) {
      uVar4 = __INITEMS();
      if (uVar4 == 0) {
        return -1;
      }
      if (uVar4 <= firstPage) {
        return -1;
      }
      if ((pages == 0) || (uVar4 - firstPage <= pages)) {
        pages = uVar4 - firstPage;
      }
    }
    else {
      if (pages == 0) {
        return -1;
      }
      if (pages <= firstPage) {
        return -1;
      }
      ((char *)"Divide error\r\n")[9] = ((char *)"Divide error\r\n")[9] | 1;
    }
    uVar4 = (uint)(CONCAT22(*(int *)0x8514 + (uint)(0xc000 < *(uint *)&__OvrSize),
                            *(uint *)&__OvrSize + 0x3fff) / 0x4000);
    if (uVar4 < pages) {
      pages = uVar4;
    }
    if ((3 < pages) || (*(uint *)((int)&GUnitDescriptions[0xb].seg + 1) <= pages * 0x400)) {
      uVar5 = __INITEMSPAGE(pages,firstPage,emsHandle);
      if (uVar5 == 0) {
        lVar1 = (ulong)firstPage * 0x4000;
        uVar6 = (undefined2)((ulong)lVar1 >> 0x10);
        *(undefined2 *)((int)&GUnitDescriptions[0x15].ofs + 1) = (int)lVar1;
        *(undefined2 *)((int)&GUnitDescriptions[0x15].seg + 1) = uVar6;
        lVar2 = (ulong)pages * 0x4000 + lVar1;
        *(undefined2 *)((int)&GUnitDescriptions[0x16].ofs + 1) = (int)lVar2;
        *(undefined2 *)((int)&GUnitDescriptions[0x16].seg + 1) = (int)((ulong)lVar2 >> 0x10);
        *(undefined2 *)((int)&GUnitDescriptions[0x17].ofs + 1) = (int)lVar1;
        *(undefined2 *)((int)&GUnitDescriptions[0x17].seg + 1) = uVar6;
        *(undefined2 *)((int)&GUnitDescriptions[0x18].ofs + 1) = 0xa48;
        *(undefined2 *)((int)&GUnitDescriptions[0x18].seg + 1) = 0;
        *(undefined2 *)((int)&GUnitDescriptions[9].seg + 1) = 1;
        ((byte *)__C0_ASM_CopyRight)[0xc] = ((byte *)__C0_ASM_CopyRight)[0xc] | 2;
        *(undefined2 *)((int)(uint32_t *)&_StartTime + 3) = 0xe9f;
        *(undefined2 *)((int)(int *)&errno + 1) = 0xd0e;
        return 0;
      }
      return uVar5;
    }
  }
  return -1;
}


/* 1403:09c8 */
void __cdecl16near OVRSWAP_1403_09c8(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  code *pcVar3;
  bool bVar4;
  undefined2 uVar5;
  int iVar6;
  undefined2 in_CX;
  uint uVar7;
  undefined2 in_DX;
  undefined1 *puVar8;
  uint uVar9;
  undefined2 in_BX;
  undefined1 *puVar10;
  undefined2 unaff_ES;
  undefined1 in_CF;
  
  uVar5 = 0x2271;
  OVRSWAP_1403_0c2b();
  if ((bool)in_CF) {
    return;
  }
  (*(code **)&ram0x00024186)(0x1403,in_DX,in_CX,in_BX,uVar5);
  puVar8 = (undefined1 *)(undefined1 *)(CONCAT22(in_CX,in_BX) % 0x4000);
  pcVar3 = (code *)swi(0x67);
  iVar6 = (*pcVar3)();
  if (-1 < iVar6) {
    uVar9 = *(uint *)((byte *)__C0_ASM_CopyRight + 4);
    puVar10 = (undefined1 *)0x0;
    do {
      uVar7 = 0x4000U - (int)puVar8;
      if (uVar9 <= 0x4000U - (int)puVar8) {
        uVar7 = uVar9;
      }
      uVar9 = uVar9 - uVar7;
      pcVar3 = (code *)swi(0x67);
      iVar6 = (*pcVar3)();
      bVar4 = true;
      if (iVar6 < 0) goto L_OVRSWAP_1403_09c8_0A34;
      uVar5 = *(undefined2 *)((byte *)__C0_ASM_CopyRight + 0xc);
      for (; uVar7 != 0; uVar7 = uVar7 - 1) {
        puVar2 = puVar8;
        puVar8 = puVar8 + 1;
        puVar1 = puVar10;
        puVar10 = puVar10 + 1;
        *puVar2 = *puVar1;
      }
      puVar8 = (undefined1 *)0x0;
    } while (uVar9 != 0);
    bVar4 = false;
L_OVRSWAP_1403_09c8_0A34:
    pcVar3 = (code *)swi(0x67);
    (*pcVar3)();
    if (!bVar4) {
      return;
    }
  }
  __OverlayHalt();
  return;
}


/* 1403:0a48 */

void __cdecl16near OVRSWAP_1403_0a48(void)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  code *pcVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  undefined1 *puVar8;
  uint uVar9;
  undefined1 *puVar10;
  undefined2 unaff_ES;
  
  pcVar4 = (code *)swi(0x67);
  iVar6 = (*pcVar4)();
  if (-1 < iVar6) {
    puVar8 = (undefined1 *)
             (undefined1 *)
             (CONCAT22(*(undefined2 *)((byte *)__C0_ASM_CopyRight + 0x12),
                       *(undefined2 *)((byte *)__C0_ASM_CopyRight + 0x10)) % 0x4000);
    uVar9 = *(uint *)((byte *)__C0_ASM_CopyRight + 4);
    puVar10 = (undefined1 *)0x0;
    do {
      uVar7 = 0x4000U - (int)puVar8;
      if (uVar9 <= 0x4000U - (int)puVar8) {
        uVar7 = uVar9;
      }
      uVar9 = uVar9 - uVar7;
      pcVar4 = (code *)swi(0x67);
      iVar6 = (*pcVar4)();
      bVar5 = true;
      if (iVar6 < 0) break;
      uVar1 = *(undefined2 *)((byte *)__C0_ASM_CopyRight + 0xc);
      for (; uVar7 != 0; uVar7 = uVar7 - 1) {
        puVar3 = puVar10;
        puVar10 = puVar10 + 1;
        puVar2 = puVar8;
        puVar8 = puVar8 + 1;
        *puVar3 = *puVar2;
      }
      puVar8 = (undefined1 *)0x0;
      bVar5 = false;
    } while (uVar9 != 0);
    pcVar4 = (code *)swi(0x67);
    (*pcVar4)();
    if (!bVar5) {
      return;
    }
  }
  __OverlayHalt();
  return;
}



/* 1403:0ab2 */
int __cdecl16far _OvrInitExt(uint32_t startAddress,uint32_t length)

{
  bool bVar1;
  undefined2 uVar2;
  int iVar3;
  uint sizeLo;
  int in_DX;
  uint sizeHi;
  
  uVar2 = (uint)startx;   /* hand fix: startx is a function */
  if ((*(byte *)&OvrFlags & 2) == 0) {
    bVar1 = false;
    iVar3 = __INITEXT();
    if (iVar3 == 0 && in_DX == 0) {
L__OvrInitExt_0AD7:
      iVar3 = -1;
    }
    else {
      while( true ) {
        if (((*(uint16_t *)((uint8_t *)&(startAddress) + 2)) < *(uint *)0x3c) ||
           (((*(uint16_t *)((uint8_t *)&(startAddress) + 2)) == *(uint *)0x3c &&
            ((uint)startAddress < *(uint *)&__ExtStartAddress)))) {
          (*(uint16_t *)((uint8_t *)&(startAddress) + 2)) = *(uint *)0x3c;
          (*(uint16_t *)((uint8_t *)&(startAddress))) = *(uint *)&__ExtStartAddress;
        }
        if ((*(uint *)0x40 < (*(uint16_t *)((uint8_t *)&(startAddress) + 2))) ||
           ((*(uint *)0x40 <= (*(uint16_t *)((uint8_t *)&(startAddress) + 2)) && (*(uint *)&__ExtEndAddress < (uint)startAddress)
            ))) goto L__OvrInitExt_0AD7;
        sizeLo = *(uint *)&__ExtEndAddress - (uint)startAddress;
        sizeHi = (*(int *)0x40 - (*(uint16_t *)((uint8_t *)&(startAddress) + 2))) -
                 (uint)(*(uint *)&__ExtEndAddress < (uint)startAddress);
        if (((uint)length != 0 || (*(uint16_t *)((uint8_t *)&(length) + 2)) != 0) &&
           (((*(uint16_t *)((uint8_t *)&(length) + 2)) <= sizeHi &&
            (((*(uint16_t *)((uint8_t *)&(length) + 2)) < sizeHi || (*(uint *)&__ExtEndAddress < sizeLo)))))) {
          sizeLo = (uint)length;
          sizeHi = (*(uint16_t *)((uint8_t *)&(length) + 2));
        }
        if ((*(uint *)((char *)0x69e4
                      ) <= sizeHi) &&
           ((*(uint *)((char *)0x69e4
                      ) < sizeHi ||
            (*(uint *)((char *)0x69e2
                      ) < sizeLo)))) {
          sizeHi = *(uint *)((char *)
                             (char *)0x69e4);
          sizeLo = *(uint *)((char *)
                             (char *)0x69e2);
        }
        length = CONCAT22(sizeHi,sizeLo);
        if ((sizeHi == 0) && (sizeLo >> 4 < *(uint *)&__OvrMinHeapSize)) goto L__OvrInitExt_0AD7;
        *(uint *)&__EmsRec = (uint)startAddress;
        *(uint *)0x132 = (*(uint16_t *)((uint8_t *)&(startAddress) + 2));
        *(int *)0x134 = sizeLo + (uint)startAddress;
        *(int *)0x136 = sizeHi + (*(uint16_t *)((uint8_t *)&(startAddress) + 2)) + (uint)CARRY2(sizeLo,(uint)startAddress);
        *(uint *)0x138 = (uint)startAddress;
        *(uint *)0x13a = (*(uint16_t *)((uint8_t *)&(startAddress) + 2));
        iVar3 = __INITEXTMEM(sizeLo,sizeHi,(uint)startAddress,(*(uint16_t *)((uint8_t *)&(startAddress) + 2)));
        if (iVar3 != 0) {
          return iVar3;
        }
        if (bVar1) break;
        bVar1 = true;
      }
      *(undefined2 *)0x13c = 0xbfb;
      *(undefined2 *)0x13e = 0;
      *(undefined2 *)0x112 = 1;
      *(byte *)&OvrFlags = *(byte *)&OvrFlags | 1;
      *(undefined2 *)&__CALLEXTEXIT = 0x1152;
      *(undefined2 *)&__CALLEXTEMSSWAP = 0xd0e;
      iVar3 = 0;
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}


/* 1403:0bcc */
void __cdecl16near OVRSWAP_1403_0bcc(void)

{
  undefined2 uVar1;
  undefined2 in_CX;
  undefined2 in_DX;
  undefined2 in_BX;
  undefined2 unaff_ES;
  undefined1 in_CF;
  bool bVar2;
  
  uVar1 = 0x2270;
  OVRSWAP_1403_0c2b();
  if (!(bool)in_CF) {
    (*(code **)&ram0x00024186)(0x1403,in_DX,in_CX,in_BX,uVar1);
    bVar2 = (int)((ulong)*(uint *)((byte *)__C0_ASM_CopyRight + 0xc) * 0x10 >> 0x10) != 0;
    __EXTCOPY();
    if (bVar2) {
      __OverlayHalt();
      return;
    }
  }
  return;
}


/* 1403:0bfb */

void __cdecl16near OVRSWAP_1403_0bfb(void)

{
  undefined2 unaff_ES;
  bool bVar1;
  
  OVRSWAP_1403_0c1f();
  bVar1 = (int)((ulong)*(uint *)((byte *)__C0_ASM_CopyRight + 0xc) * 0x10 >> 0x10) != 0;
  __EXTCOPY();
  if (bVar1) {
    __OverlayHalt();
    return;
  }
  return;
}



/* 1403:0c1f */

void __cdecl16near OVRSWAP_1403_0c1f(void)

{
  return;
}



/* 1403:0c2b */

void __cdecl16near OVRSWAP_1403_0c2b(void)

{
  uint *puVar1;
  undefined2 in_AX;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  undefined2 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined2 uVar9;
  uint uVar10;
  uint unaff_SI;
  uint unaff_DI;
  undefined2 unaff_ES;
  
  uVar10 = *(uint *)((byte *)__C0_ASM_CopyRight + 4);
  uVar2 = *(uint *)__C0_ASM_CopyRight - uVar10;
  iVar6 = *(int *)((byte *)__C0_ASM_CopyRight + 6);
  uVar7 = (*(int *)((byte *)__C0_ASM_CopyRight + 2) - iVar6) -
          (uint)(*(uint *)__C0_ASM_CopyRight < uVar10);
  uVar3 = uVar2;
  uVar8 = uVar7;
  OVRSWAP_1403_0c1f();
  if (uVar8 < unaff_DI || uVar8 - unaff_DI < (uint)(uVar3 < unaff_SI)) {
    pcVar4 = OVRSWAP_1403_0cd2();
    if (pcVar4 != (char *)0x0) {
      uVar5 = *(undefined2 *)((byte *)__C0_ASM_CopyRight + 10);
      *(undefined2 *)((byte *)__C0_ASM_CopyRight + 10) =
           *(undefined2 *)((byte *)__C0_ASM_CopyRight + 10);
      ((byte *)__C0_ASM_CopyRight + 10)[0] = 0;
      ((byte *)__C0_ASM_CopyRight + 10)[1] = 0;
      OVRSWAP_1403_0d01();
      *(undefined2 *)((byte *)__C0_ASM_CopyRight + 10) = uVar5;
    }
    uVar10 = *(uint *)0x0;
    *(uint *)((byte *)__C0_ASM_CopyRight + 4) = uVar10;
    iVar6 = *(int *)((int)(undefined4 *)&_DATA + 2);
    *(int *)((byte *)__C0_ASM_CopyRight + 6) = iVar6;
    OVRSWAP_1403_0c1f();
    unaff_SI = uVar2;
    unaff_DI = uVar7;
  }
  pcVar4 = OVRSWAP_1403_0cd2();
  if (pcVar4 != (char *)0x0) {
    *(undefined2 *)((byte *)__C0_ASM_CopyRight + 10) =
         *(undefined2 *)((byte *)__C0_ASM_CopyRight + 10);
  }
  puVar1 = (uint *)((byte *)__C0_ASM_CopyRight + 4);
  uVar3 = *puVar1;
  *puVar1 = *puVar1 + unaff_SI;
  *(uint *)((byte *)__C0_ASM_CopyRight + 6) =
       *(int *)((byte *)__C0_ASM_CopyRight + 6) + unaff_DI + (uint)CARRY2(uVar3,unaff_SI);
  *(uint *)((byte *)__C0_ASM_CopyRight + 0x10) = uVar10;
  *(int *)((byte *)__C0_ASM_CopyRight + 0x12) = iVar6;
  uVar5 = *(undefined2 *)((byte *)__C0_ASM_CopyRight + 8);
  *(undefined2 *)((byte *)__C0_ASM_CopyRight + 0x14) = uVar5;
  uVar9 = unaff_ES;
  OVRSWAP_1403_0d01();
  *(undefined2 *)((byte *)__C0_ASM_CopyRight + 10) = uVar9;
  *(undefined2 *)((byte *)__C0_ASM_CopyRight + 10) = uVar5;
  return;
}



/* 1403:0cd2 */

char * __cdecl16near OVRSWAP_1403_0cd2(void)

{
  uint uVar1;
  uint uVar2;
  uint in_CX;
  uint uVar3;
  uint in_BX;
  undefined2 unaff_BP;
  uint unaff_SI;
  uint unaff_DI;
  char *pcVar4;
  char *pcVar5;
  
  pcVar5 = (char *)0x26510;
  pcVar4 = (char *)0x0;
  while( true ) {
    pcVar5 = *(char **)((byte *)__C0_ASM_CopyRight + 10);
    if (pcVar5 == (char *)0x0) {
      return pcVar4;
    }
    uVar1 = (uint)(*(uint *)((byte *)__C0_ASM_CopyRight + 0x10) < in_BX);
    uVar2 = *(uint *)((byte *)__C0_ASM_CopyRight + 0x12) - in_CX;
    uVar3 = uVar2 - uVar1;
    if (*(uint *)((byte *)__C0_ASM_CopyRight + 0x12) < in_CX || uVar2 < uVar1) break;
    if (unaff_DI <= uVar3 &&
        (uint)(*(uint *)((byte *)__C0_ASM_CopyRight + 0x10) - in_BX < unaff_SI) <= uVar3 - unaff_DI)
    {
      return pcVar4;
    }
    *(undefined2 *)((byte *)__C0_ASM_CopyRight + 0x14) = unaff_BP;
    pcVar4 = pcVar5;
  }
  return pcVar4;
}



/* 1403:0d01 */

void __cdecl16near OVRSWAP_1403_0d01(void)

{
  int iVar1;
  
  iVar1 = 0x2410;
  do {
    iVar1 = *(int *)((byte *)__C0_ASM_CopyRight + 10);
  } while (iVar1 != 0);
  return;
}



/* 1403:0d0e */

void __cdecl16near __SwapOverlay(void)

{
  if ((OvrFlags & 1) != 0) {
    OVRSWAP_1403_0bcc();
    return;
  }
  if ((OvrFlags & 2) != 0) {
    OVRSWAP_1403_09c8();
  }
  return;
}



/* 1403:0d24 */

void __cdecl16far __OvrPrepare(void)

{
  far_t *pfVar1;
  int iVar2;
  uint uVar3;
  far_t *pfVar4;
  
  __InitModules();
  uVar3 = __ovrbuffer;
  if (__ovrbuffer <= __OvrMinHeapSize) {
    uVar3 = __OvrMinHeapSize << 1;
  }
  pfVar4 = (far_t *)((ulong)(uVar3 + 1) * 0x10);
  pfVar1 = farmalloc((far_t *)pfVar4,CONCAT22(uVar3 + 1,(int)((ulong)pfVar4 >> 0x10)));
  if ((pfVar1 != (far_t *)0x0 || (int)((ulong)pfVar4 >> 0x10) != 0) &&
     (iVar2 = __OVRINIT(), iVar2 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  _abort();
}



/* 1403:0d88 */
int __cdecl16far __INITEMS(void)

{
  code *pcVar1;
  char cVar2;
  char extraout_AH;
  undefined2 uVar3;
  char extraout_AH_00;
  char extraout_AH_01;
  uint extraout_DX;
  int in_BX;
  undefined2 unaff_SI;
  int unaff_ES;
  bool bVar4;
  
  bVar4 = false;
  if ((((char *)"Divide error\r\n")[9] & 1U) == 0) {
    pcVar1 = (code *)swi(0x21);
    in_BX = (*pcVar1)();
    if (bVar4) goto L__INITEMS_0E2A;
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    if ((!bVar4) && (bVar4 = false, (extraout_DX & 0x80) != 0)) {
      pcVar1 = (code *)swi(0x21);
      cVar2 = (*pcVar1)();
      if (!bVar4) {
        pcVar1 = (code *)swi(0x21);
        (*pcVar1)();
        if (cVar2 == -1) {
          pcVar1 = (code *)swi(0x21);
          (*pcVar1)();
          if (unaff_ES == 0 && in_BX == 0) goto L__INITEMS_0E2A;
          pcVar1 = (code *)swi(0x67);
          (*pcVar1)();
          if (extraout_AH != '\0') goto L__INITEMS_0E2A;
          ((char *)"Divide error\r\n")[9] = '\x01';
          pcVar1 = (code *)swi(0x67);
          uVar3 = (*pcVar1)();
          if (((char)((uint)uVar3 >> 8) != '\0') || ((byte)uVar3 < 0x32)) goto L__INITEMS_0E2A;
          ((char *)"Divide error\r\n")[10] = (byte)uVar3;
          pcVar1 = (code *)swi(0x67);
          (*pcVar1)();
          if (extraout_AH_00 != '\0') goto L__INITEMS_0E2A;
          *(int *)((char *)0x30) = in_BX;
          goto L__INITEMS_0E14;
        }
      }
    }
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
  }
  else {
    unaff_SI = (uint)startx;   /* hand fix: startx is a function */
    if ((((char *)"Divide error\r\n")[9] & 2U) != 0) {
      return *(int *)((char *)0x36);
    }
L__INITEMS_0E14:
    pcVar1 = (code *)swi(0x67);
    (*pcVar1)();
    if (extraout_AH_01 == '\0') {
      *(int *)((char *)0x36) = in_BX;
      ((char *)0x32)[0] = -1;
      ((char *)0x32)[1] = -1;
      return in_BX;
    }
  }
L__INITEMS_0E2A:
  ((char *)"Divide error\r\n")[9] = '\0';
  return 0;
}


/* 1403:0e3a */
uint16_t __stdcall16far __INITEMSPAGE(uint16_t pageCount,uint16_t frameSeg,uint16_t handle)

{
  code *pcVar1;
  undefined2 uVar2;
  char extraout_AH;
  char extraout_AH_00;
  undefined1 extraout_AH_01;
  uint16_t extraout_DX;
  
  uVar2 = (uint)startx;   /* hand fix: startx is a function */
  if ((((char *)"Divide error\r\n")[9] & 1U) != 0) {
    if ((((char *)"Divide error\r\n")[9] & 2U) != 0) {
      return 0;
    }
    ((char *)"Divide error\r\n")[9] = ((char *)"Divide error\r\n")[9] | 2;
    *(uint16_t *)((char *)0x34) = frameSeg;
    *(uint16_t *)((char *)0x36) = pageCount;
    if (handle == 0) {
      pcVar1 = (code *)swi(0x67);
      (*pcVar1)();
      if (extraout_AH != '\0') {
        return 0xffff;
      }
      ((char *)"Divide error\r\n")[9] = ((char *)"Divide error\r\n")[9] | 4;
      handle = extraout_DX;
    }
    *(uint16_t *)((char *)0x32) = handle;
    pcVar1 = (code *)swi(0x67);
    (*pcVar1)();
    if (extraout_AH_00 == '\0') {
      pcVar1 = (code *)swi(0x67);
      (*pcVar1)();
      return CONCAT11(extraout_AH_01,extraout_AH_01);
    }
  }
  return 0xffff;
}


/* 1403:0e9f */
void __cdecl16far __EXITEMS(void)

{
  code *pcVar1;
  undefined2 uVar2;
  
  uVar2 = (uint)startx;   /* hand fix: startx is a function */
  if (((((char *)"Divide error\r\n")[9] & 4U) != 0) &&
     (*(int *)((char *)0x32) != -1)) {
    pcVar1 = (code *)swi(0x67);
    (*pcVar1)();
    ((char *)0x32)[0] = -1;
    ((char *)0x32)[1] = -1;
    ((char *)"Divide error\r\n")[9] = '\0';
  }
  return;
}


/* 1403:0eca */
int __cdecl16far __INITEXT(void)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  code *pcVar5;
  long lVar6;
  undefined2 uVar7;
  char cVar8;
  undefined2 uVar9;
  byte extraout_AH;
  uint uVar10;
  uint uVar11;
  int iVar12;
  undefined2 in_BX;
  byte *pbVar13;
  byte *pbVar14;
  undefined2 unaff_SS;
  bool bVar15;
  undefined1 uVar16;
  undefined4 uVar17;
  uint8_t cmpBuf [8];
  uint uStack_17;
  uint uStack_f;
  
  uVar7 = (uint)startx;   /* hand fix: startx is a function */
  if ((((char *)"Abnormal program termination\r\n")[5] & 1U) == 0) {
    ((char *)"Abnormal program termination\r\n")[5] = '\x01';
L__INITEXT_0EEC:
    ((char *)0x3a)[0] = '\0';
    ((char *)0x3a)[1] = '\0';
    ((char *)0x3c)[0] = '\x10';
    ((char *)0x3c)[1] = '\0';
    ((char *)0x3e)[0] = '\0';
    ((char *)0x3e)[1] = '\0';
    ((char *)0x40)[0] = '\x10';
    ((char *)0x40)[1] = '\0';
    pcVar5 = (code *)swi(0x21);
    uVar9 = (*pcVar5)();
    if (((((byte)uVar9 < 10) && ((*(byte *)0xFFFE) < 0xfd)) && ((*(byte *)0xFFFE) != 0xfb)) &&
       ((*(byte *)0xFFFE) != 0xf9)) {
      if (0x30 < CONCAT11((byte)uVar9,(char)((uint)uVar9 >> 8))) {
        pcVar5 = (code *)swi(0x2f);
        cVar8 = (*pcVar5)();
        if (cVar8 == -0x80) {
          pcVar5 = (code *)swi(0x2f);
          (*pcVar5)();
          *(undefined2 *)((char *)0x43) = in_BX;
          ((char *)0x45)[0] = '\0';
          ((char *)0x45)[1] = -0x10;
          (**(code **)((char *)0x43))();
          if (1 < extraout_AH) {
            uVar11 = (**(code **)((char *)0x43))();
            if (uVar11 != 0) {
              uVar17 = (**(code **)((char *)0x43))();
              if ((int)uVar17 != 0) {
                *(int *)((char *)0x47) =
                     (int)((ulong)uVar17 >> 0x10);
                uVar17 = (**(code **)((char *)0x43))();
                if ((int)uVar17 != 0) {
                  *(undefined2 *)((char *)0x3a) = in_BX;
                  *(int *)((char *)0x3c) = (int)((ulong)uVar17 >> 0x10);
                  uVar10 = (uint)((ulong)uVar11 * 0x400);
                  uVar4 = *(uint *)((char *)0x3a);
                  iVar12 = *(int *)((char *)0x3c);
                  *(uint *)((char *)0x3e) =
                       uVar10 + *(uint *)((char *)0x3a);
                  *(uint *)((char *)0x40) =
                       (int)((ulong)uVar11 * 0x400 >> 0x10) + iVar12 + (uint)CARRY2(uVar10,uVar4);
                }
                (**(code **)((char *)0x43))();
                (**(code **)((char *)0x43))();
                ((char *)0x47)[0] = '\0';
                ((char *)0x47)[1] = '\0';
              }
            }
            goto L__INITEXT_105D;
          }
        }
      }
      pcVar5 = (code *)swi(0x15);
      uVar11 = (*pcVar5)();
      if (uVar11 != 0) {
        lVar6 = (ulong)uVar11 * 0x400;
        *(int *)((char *)0x3e) = (int)lVar6;
        *(uint *)((char *)0x40) =
             CONCAT11((char)((ulong)lVar6 >> 0x18),(char)((ulong)lVar6 >> 0x10) + '\x10');
        if (*(int *)((char *)0x43) != 0 ||
            *(int *)((char *)0x45) != 0) {
          ((char *)"Divide error\r\n")[0xd] = '\x11';
          ((char *)0x3a)[0] = '\0';
          ((char *)0x3a)[1] = '\0';
        }
        bVar15 = false;
        uVar16 = 1;
        __EXTCOPY();
        if (!bVar15) {
          pbVar14 = cmpBuf;
          pbVar13 = (byte *)__C0_ASM_CopyRight + 0x1c;
          iVar12 = 5;
          do {
            if (iVar12 == 0) break;
            iVar12 = iVar12 + -1;
            pbVar2 = pbVar14;
            pbVar14 = pbVar14 + 1;
            pbVar1 = pbVar13;
            pbVar13 = pbVar13 + 1;
            uVar16 = *pbVar1 == *pbVar2;
          } while ((bool)uVar16);
          if ((bool)uVar16) {
            *(int *)((char *)0x3a) = (int)((ulong)uStack_17 * (ulong)uStack_f);
            ((char *)"Divide error\r\n")[0xd] =
                 (char)((ulong)uStack_17 * (ulong)uStack_f >> 0x10) + '\x10';
          }
          bVar15 = true;
          pbVar13 = (byte *)__C0_ASM_CopyRight + 0xe;
          pbVar14 = (byte *)__C0_ASM_CopyRight + 0x1c;
          iVar12 = 5;
          do {
            if (iVar12 == 0) break;
            iVar12 = iVar12 + -1;
            pbVar2 = pbVar13;
            pbVar13 = pbVar13 + 1;
            pbVar1 = pbVar14;
            pbVar14 = pbVar14 + 1;
            bVar15 = *pbVar1 == *pbVar2;
          } while (bVar15);
          if (bVar15) {
            bVar3 = ((byte *)__C0_ASM_CopyRight)[0x2a];
            if (((byte)((char *)"Divide error\r\n")[0xd] <= bVar3) &&
               ((bVar3 != ((char *)"Divide error\r\n")[0xd] ||
                (*(uint *)((char *)0x3a) <
                 *(uint *)((byte *)__C0_ASM_CopyRight + 0x28))))) {
              *(uint *)((char *)0x3a) =
                   *(uint *)((byte *)__C0_ASM_CopyRight + 0x28);
              ((char *)"Divide error\r\n")[0xd] = bVar3;
            }
          }
          goto L__INITEXT_105D;
        }
      }
    }
    iVar12 = 0;
  }
  else {
    if ((((char *)"Abnormal program termination\r\n")[5] & 2U) == 0) goto L__INITEXT_0EEC;
L__INITEXT_105D:
    iVar12 = *(int *)((char *)0x3e) -
             *(int *)((char *)0x3a);
  }
  return iVar12;
}


/* 1403:107a */
undefined2 __stdcall16far __INITEXTMEM(uint sizeLo,int sizeHi,uint baseLo,int baseHi)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar1 = (uint)startx;   /* hand fix: startx is a function */
  if ((((char *)"Abnormal program termination\r\n")[5] & 1U) != 0) {
    if ((((char *)"Abnormal program termination\r\n")[5] & 2U) != 0) {
      return 0;
    }
    ((char *)"Abnormal program termination\r\n")[5] =
         ((char *)"Abnormal program termination\r\n")[5] | 2;
    if (*(int *)((char *)0x43) == 0 &&
        *(int *)((char *)0x45) == 0) {
      *(uint *)((char *)0x3a) = baseLo;
      *(int *)((char *)0x3c) = baseHi;
      _BootHandlerCode = uRam00000064;
      Int19Seg = uRam00000066;
      uRam00000064 = 0x3f;
      uRam00000066 = 0x2272;
      vdiskBaseOfs = baseLo;
      vdiskBaseHi = (undefined1)baseHi;
      iVar2 = baseLo + sizeLo;
      iVar3 = baseHi + sizeHi + (uint)CARRY2(baseLo,sizeLo);
      vdiskEndHi = (undefined1)iVar3;
      vdiskEndOfs = iVar2;
L__INITEXTMEM_113B:
      *(int *)((char *)0x3e) = iVar2;
      *(int *)((char *)0x40) = iVar3;
      return 0;
    }
    uVar4 = 0x400;
    uVar5 = (**(code **)((char *)0x43))(0x1000);
    if ((int)uVar5 != 0) {
      *(int *)((char *)0x47) = (int)((ulong)uVar5 >> 0x10);
      uVar5 = (**(code **)((char *)0x43))(0x1000);
      iVar3 = (int)((ulong)uVar5 >> 0x10);
      if ((int)uVar5 != 0) {
        *(uint *)((char *)0x3a) = uVar4;
        *(int *)((char *)0x3c) = iVar3;
        *(uint *)((char *)0x49) = uVar4;
        *(int *)((char *)0x4b) = iVar3;
        iVar2 = uVar4 + sizeLo;
        iVar3 = iVar3 + sizeHi + (uint)CARRY2(uVar4,sizeLo);
        goto L__INITEXTMEM_113B;
      }
    }
  }
  return 0xffff;
}


/* 1403:1152 */
void __cdecl16far __EXITEXT(void)

{
  undefined2 uVar1;
  
  uVar1 = (uint)startx;   /* hand fix: startx is a function */
  if (((char *)"Abnormal program termination\r\n")[5] != '\0') {
    if (*(int *)((char *)0x47) == 0) {
      if (iRam00000066 == 0x2272) {
        uRam00000064 = _BootHandlerCode;
        iRam00000066 = Int19Seg;
        ((char *)"Abnormal program termination\r\n")[5] = '\0';
      }
    }
    else {
      (**(code **)((char *)0x43))(0x1000,0x2410);
      (**(code **)((char *)0x43))(0x1000);
    }
  }
  return;
}


/* 1403:11a6 */
int __cdecl16near __EXTCOPY(void)

{
  code *pcVar1;
  undefined2 uVar2;
  uint in_AX;
  int iVar3;
  uint in_CX;
  uint16_t uVar4;
  uint in_DX;
  uint uVar5;
  uint in_BX;
  uint unaff_SI;
  int unaff_DI;
  bool bVar6;
  byte bVar7;
  
  uVar2 = (uint)startx;   /* hand fix: startx is a function */
  if (*(int *)((char *)0x47) == 0) {
    bVar7 = false;
    ((far_t far *)(GSTARTX_SavedVectors + 1))->ofs = in_AX;
    *(byte *)&GSTARTX_SavedVectors[1].seg = (byte)in_DX;
    ((far_t far *)(GSTARTX_SavedVectors + 3))->ofs = in_BX;
    *(byte *)&GSTARTX_SavedVectors[3].seg = (byte)in_CX;
    pcVar1 = (code *)swi(0x15);
    (*pcVar1)(0x2410);
    if (!(bool)bVar7) {
      return 0;
    }
  }
  else {
    *(uint *)((char *)0x4d) = unaff_SI + 1 & 0xfffe;
    *(uint *)((char *)0x4f) =
         unaff_DI + (uint)(0xfffe < unaff_SI);
    if ((byte)in_DX < 0x10) {
      ((char *)0x51)[0] = '\0';
      ((char *)0x51)[1] = '\0';
      uVar5 = in_DX >> 4 | in_DX << 0xc;
    }
    else {
      *(undefined2 *)((char *)0x51) =
           *(undefined2 *)((char *)0x47);
      bVar6 = in_AX < *(uint *)((char *)0x49);
      in_AX = in_AX - *(uint *)((char *)0x49);
      uVar5 = (in_DX - *(int *)((char *)0x4b)) - (uint)bVar6;
    }
    *(uint *)((char *)0x53) = in_AX;
    *(uint *)((char *)0x55) = uVar5;
    if ((byte)in_CX < 0x10) {
      ((char *)0x57)[0] = '\0';
      ((char *)0x57)[1] = '\0';
      uVar4 = in_CX >> 4 | in_CX << 0xc;
    }
    else {
      *(undefined2 *)((char *)0x57) =
           *(undefined2 *)((char *)0x47);
      bVar6 = in_BX < *(uint *)((char *)0x49);
      in_BX = in_BX - *(uint *)((char *)0x49);
      uVar4 = (in_CX - *(int *)((char *)0x4b)) - (uint)bVar6;
    }
    *(uint *)((char *)0x59) = in_BX;
    ((far_t far *)GSTARTX_SavedVectors)->ofs = uVar4;
    iVar3 = (**(code **)((char *)0x43))(0x1000);
    if (iVar3 != 0) {
      return 0;
    }
    bVar7 = 1;
  }
  return -(uint)bVar7;
}


/* 1403:1253 */

void __cdecl16near OvrExtEmsSwapStub(void)

{
  return;
}



/* 1403:1254 */

void __cdecl16far OvrEmsExitStub(void)

{
  return;
}


