/*
 * ovl.c - recovered from STRONG.EXE
 * memory block: 1403_OVRTEXT_
 * range: 1403:0002 - 1403:125f
 * functions: 54
 */
#include "recovered.h"


/* 1403:000d */

/* WARNING: Removing unreachable block (ram,0x000140eb) */
/* WARNING: Removing unreachable block (ram,0x000140fa) */
/* WARNING: Removing unreachable block (ram,0x0001414b) */
/* WARNING: Removing unreachable block (ram,0x00014158) */
/* WARNING: Removing unreachable block (ram,0x00014145) */
/* WARNING: Removing unreachable block (ram,0x000140f2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __stdcall16far __OVRINIT(void)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  bool bVar4;
  int iStack_16;
  
  uVar3 = startx;
  bVar4 = false;
  if (*(int *)((int)&GUnitDescriptions[9].ofs + 1) == 0) {
    uVar3 = 0;
  }
  else {
    uVar2 = __OvrExeOpenEnv();
    if (bVar4) {
      bVar4 = false;
      uVar2 = __OvrExeOpenFilename();
      if ((bVar4) && (uVar2 = __OvrExeOpenEnvPath(), bVar4)) {
        return 0xfffe;
      }
    }
    bVar4 = false;
    *(undefined2 *)((int)&GUnitDescriptions[0xf].ofs + 1) = uVar2;
    __OvrReadHeader();
    if ((!bVar4) && (iStack_16 == 0x5a4d)) {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)();
      __OvrReadHeader();
    }
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    uVar3 = 0xffff;
  }
  return uVar3;
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
  *(undefined2 *)(char *)"Borland C++ - Copyright 1991 Borland Intl." = in_stack_00000002;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far __OVREXIT(void)

{
  undefined2 uVar1;
  
  uVar1 = startx;
  if (*(int *)((int)&GUnitDescriptions[0xf].ofs + 1) != 0) {
    __OvrResetInterruptVector((char *)"puppetmaker" + 3);
  }
  (*(code *)*(undefined2 *)&__CALLEMSEXIT)(0x1000);
  (*(code *)*(undefined2 *)&__CALLEXTEXIT)(0x1000);
  return;
}



/* 1403:01b2 */

void __cdecl16near __OvrExeOpenFilename(void)

{
  OvrDoOpenFile((char *)"puppetmaker" + 3);
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
  
  pcVar3 = (code *)swi(0x21);
  bVar5 = (*pcVar3)();
  uVar4 = _envseg_at_;
  if (2 < bVar5) {
                    /* WARNING: Read-only address (ram,0x00024106) is written */
    __C0_ASM_CopyRight[2] = ' ';
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
  byte bVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  undefined2 uVar9;
  bool bVar10;
  char *pcVar11;
  
  pcVar11 = (char *)"puppetmaker" + 3;
  pbVar7 = (byte *)0x0;
  bVar10 = true;
  do {
    pbVar8 = (byte *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 2);
    iVar6 = 5;
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      pbVar4 = pbVar8;
      pbVar8 = pbVar8 + 1;
      pbVar1 = pbVar7;
      pbVar7 = pbVar7 + 1;
      bVar10 = *pbVar1 == *pbVar4;
    } while (bVar10);
    uVar9 = _envseg_at_;
    if (bVar10) {
      do {
        if (*pbVar7 == 0) {
          return;
        }
        pbVar8 = (byte *)((int)&_brklvl.ofs + 1);
        bVar5 = 0;
        while( true ) {
          pbVar2 = pbVar7 + 1;
          bVar3 = *pbVar7;
          if ((bVar3 == 0) || (pbVar7 = pbVar2, bVar3 == 0x3b)) break;
          pbVar1 = pbVar8;
          pbVar8 = pbVar8 + 1;
          *pbVar1 = bVar3;
          bVar5 = bVar3;
        }
        bVar10 = bVar5 < 0x3a;
        if ((bVar5 != 0x3a) && (bVar10 = bVar5 < 0x5c, bVar5 != 0x5c)) {
          *pbVar8 = 0x5c;
        }
        OvrDoOpenFile(pbVar7,uVar9,pcVar11);
      } while (bVar10);
      return;
    }
    pbVar7 = pbVar7 + -1;
    do {
      pbVar1 = pbVar7;
      pbVar7 = pbVar7 + 1;
    } while (*pbVar1 != 0);
    bVar10 = false;
    if (*pbVar7 == 0) {
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
      if (cVar2 == '\0') goto LAB_1403_0277;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    *unaff_DI = '\0';
  }
LAB_1403_0277:
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
  char *pcVar2;
  undefined2 uVar3;
  uint extraout_DX;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  
  iRam0001000b = _psp + 0x10;
                    /* WARNING: Read-only address (ram,0x0001000b) is written */
  pcVar6 = (char *)"manned n/s gate" + 0xe;
  uVar4 = 0;
  pcVar5 = (char *)"mages" + 1;
  do {
    if (((*(uint *)(pcVar5 + 4) & 2) != 0) && (*(int *)(pcVar5 + 2) != 0)) {
      pcVar2 = *(char **)pcVar5;
      *(char **)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xe) = pcVar2;
      if (((char *)"Borland C++ - Copyright 1991 Borland Intl.")[0x16] == -1) {
        ((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xe)[0] = '\0';
        ((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xe)[1] = '\0';
      }
      else {
        ((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x14)[0] = -0x3d;
        uVar3 = GUnitDescriptions._43_2_;
        ((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x14)[1] = '\x04';
        puVar1 = (uint *)"Borland C++ - Copyright 1991 Borland Intl.";
        bVar7 = CARRY2(*puVar1,GUnitDescriptions[10]._1_2_);
        *puVar1 = *puVar1 + GUnitDescriptions[10]._1_2_;
        *(uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 2) =
             *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 2) + uVar3 +
             (uint)bVar7;
        __OvrCalcSize();
        pcVar6 = pcVar2;
        if (uVar4 < extraout_DX) {
          uVar4 = extraout_DX;
        }
      }
    }
    pcVar5 = pcVar5 + 8;
  } while (pcVar5 < (char *)0x478);
  GUnitDescriptions._47_2_ = uVar4 + 2;
  return 0;
}



/* 1403:0318 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16near __OvrInitReadSegs(void)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  char *pcVar8;
  
  uVar2 = GUnitDescriptions._59_2_;
  GUnitDescriptions[0x10]._1_2_ = GUnitDescriptions._55_2_;
  iVar4 = GUnitDescriptions._55_2_;
  iVar6 = GUnitDescriptions._55_2_;
  GUnitDescriptions[0xd]._1_2_ = GUnitDescriptions[0xe]._1_2_;
  while ((iVar5 = iVar4,
         iVar4 = *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xe), iVar4 != 0 &&
         (uVar3 = (int)(CONCAT22((*(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 2)
                                 - *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 2
                                           )) -
                                 (uint)(*(uint *)"Borland C++ - Copyright 1991 Borland Intl." <
                                       *(uint *)"Borland C++ - Copyright 1991 Borland Intl."),
                                 *(uint *)"Borland C++ - Copyright 1991 Borland Intl." -
                                 *(uint *)"Borland C++ - Copyright 1991 Borland Intl.") / 0x10) +
                  GUnitDescriptions[0xd]._1_2_, uVar3 <= (uint)uVar2))) {
    *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xc) =
         GUnitDescriptions[0xd]._1_2_;
    *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x18) = iVar4;
    iVar6 = iVar5;
    GUnitDescriptions[0xd]._1_2_ = uVar3;
  }
  ((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x18)[0] = '\0';
  ((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x18)[1] = '\0';
  if (GUnitDescriptions[0xd]._1_2_ != GUnitDescriptions[0xe]._1_2_) {
    bVar7 = false;
    __OvrRead();
    if (!bVar7) {
      pcVar8 = (char *)"puppetmaker" + 3;
      iVar4 = GUnitDescriptions[0x10]._1_2_;
      do {
        if (*(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 6) != 0) {
          __OvrDoFixups(pcVar8);
        }
        if (*(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 8) != 0) {
          __OvrUntrapJmps();
        }
        *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 10) = iVar4;
        puVar1 = (undefined2 *)((int)(uint16_t *)&__brklvl + 1);
        (*(code *)*puVar1)(0x1000);
        iVar4 = *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x18);
      } while (iVar4 != 0);
    }
  }
  return;
}



/* 1403:03d8 */

uint __cdecl16near ovrman_1000_4408(void)

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
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
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
  
  uVar1 = *(uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4);
  puVar6 = (undefined2 *)(uVar1 & 0xf);
  iVar3 = *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xc);
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
    iVar3 = *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 8);
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
  if ((!bVar1) && (*(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 6) != 0)) {
    __OvrDoFixups();
  }
  return;
}



/* 1403:04f1 */

/* WARNING: Removing unreachable block (ram,0x0001452a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far __OvrTrapHandler(void)

{
  undefined2 *puVar1;
  undefined2 in_AX;
  undefined2 *in_stack_00000000;
  
  if ((undefined2 *)in_stack_00000000 == (undefined2 *)((int)(undefined4 *)&_DATA + 2)) {
    __OvrFixupTrap(*in_stack_00000000);
  }
  else {
    LOCK();
    UNLOCK();
    __OvrFixupTrap(*in_stack_00000000);
    LOCK();
    UNLOCK();
  }
  ((char *)"Borland C++ - Copyright 1991 Borland Intl.")[0x16] =
       ((char *)"Borland C++ - Copyright 1991 Borland Intl.")[0x16] & 0xf7;
  puVar1 = (undefined2 *)((int)(uint16_t *)&__brklvl + 1);
  (*(code *)*puVar1)(0x1000);
  return in_AX;
}



/* 1403:0557 */

void __cdecl16near __OvrAllocateSpace(void)

{
  char *pcVar1;
  uint uVar2;
  undefined2 unaff_ES;
  byte in_CF;
  undefined4 uVar3;
  
  GUnitDescriptions._63_2_ = GUnitDescriptions._63_2_ + 1;
  __OvrCalcSize();
  while( true ) {
    uVar3 = __OvrGetSegMemInfo();
    uVar2 = (uint)((ulong)uVar3 >> 0x10);
    if (uVar2 <= (uint)uVar3) break;
    if ((in_CF & 1) != 0) {
      __OvrAddToLoadList(uVar2);
    }
    in_CF = 0;
    if (((char *)"Borland C++ - Copyright 1991 Borland Intl.")[0x17] == '\0') {
      GUnitDescriptions[0x10]._1_2_ =
           *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x18);
      __OvrAllocEvict();
      __OvrCalcCodeSz();
    }
    else {
      pcVar1 = (char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x17;
      GUnitDescriptions[0x10]._1_2_ =
           *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x18);
      *pcVar1 = *pcVar1 + -1;
      __OvrCompactHeap();
      __OvrAddToLoadList();
    }
  }
  *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xc) =
       GUnitDescriptions[0xd]._1_2_;
  return;
}



/* 1403:05a1 */

void __cdecl16near __OvrFixupTrap(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined2 unaff_ES;
  undefined1 uVar4;
  
  GUnitDescriptions[0xc]._1_2_ = GUnitDescriptions[0xc]._1_2_ + 1;
  if (*(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xc) == 0) {
    uVar4 = 0;
    ((char *)"Borland C++ - Copyright 1991 Borland Intl.")[0x16] =
         ((char *)"Borland C++ - Copyright 1991 Borland Intl.")[0x16] | 8;
    iVar3 = __OvrAllocateSpace();
    *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 10) = unaff_ES;
    (**(code **)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x14))();
    if ((bool)uVar4) {
      __OverlayHalt();
      return;
    }
    __OvrAddToLoadList();
  }
  else {
    ((char *)"Borland C++ - Copyright 1991 Borland Intl.")[0x17] = '\x01';
    ((char *)"Borland C++ - Copyright 1991 Borland Intl.")[0x16] =
         ((char *)"Borland C++ - Copyright 1991 Borland Intl.")[0x16] | 4;
  }
  __OvrUntrapJmpsAndStack();
  ((char *)"Borland C++ - Copyright 1991 Borland Intl.")[0x17] =
       ((char *)"Borland C++ - Copyright 1991 Borland Intl.")[0x17] +
       (((char *)"Borland C++ - Copyright 1991 Borland Intl.")[0x16] & 3U);
  uVar2 = __OvrGetSegMemInfo();
  iVar3 = GUnitDescriptions[0x10]._1_2_;
  while ((iVar1 = *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x18), iVar1 != 0
         && (uVar2 < (uint)GUnitDescriptions[0xb]._1_2_))) {
    if (((char *)"Borland C++ - Copyright 1991 Borland Intl.")[0x17] == '\0') {
      __OvrTrapJmpsAndStack();
      iVar3 = __OvrCalcCodeSz();
    }
    else {
      iVar3 = 0;
    }
    uVar2 = iVar3 + uVar2;
    iVar3 = iVar1;
  }
  return;
}



/* 1403:061c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16near __OvrAllocEvict(void)

{
  undefined2 unaff_ES;
  
  __OvrTrapJmpsAndStack();
  if (*(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x14) == 0x4c3) {
    (*ram0x00024180)();
  }
  ((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xc)[0] = '\0';
  ((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xc)[1] = '\0';
  return;
}



/* 1403:0634 */

void __cdecl16near __OvrAddToLoadList(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  do {
    iVar3 = GUnitDescriptions[0x10]._1_2_;
    iVar1 = iVar1 + 1;
    GUnitDescriptions[0x10]._1_2_ =
         *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x18);
  } while (GUnitDescriptions[0x10]._1_2_ != 0);
  GUnitDescriptions[0xd]._1_2_ = GUnitDescriptions._59_2_;
  do {
    iVar2 = iVar1;
    *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x18) =
         GUnitDescriptions[0x10]._1_2_;
    GUnitDescriptions[0x10]._1_2_ = iVar3;
    iVar1 = __OvrCalcCodeSz();
    GUnitDescriptions[0xd]._1_2_ = GUnitDescriptions[0xd]._1_2_ - iVar1;
    __OvrCompactHeap();
    iVar1 = iVar2 + -1;
    iVar3 = iVar2;
  } while (iVar1 != 0);
  GUnitDescriptions[0xd]._1_2_ = GUnitDescriptions[0xe]._1_2_;
  return;
}



/* 1403:066f */

void __cdecl16near __OvrUntrapJmpsAndStack(void)

{
  char *pcVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  char *pcVar5;
  undefined2 unaff_ES;
  
  if (*(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 8) == 0) {
    return;
  }
  if (((char *)"Borland C++ - Copyright 1991 Borland Intl.")[0x1c] != -0x16) {
    if (*(int *)((int)(undefined4 *)&_DATA + 2) != 0) {
      __OvrPatchStack();
    }
    uVar2 = *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xc);
    iVar4 = *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 8);
    pcVar5 = (char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x1c;
    do {
      uVar3 = *(undefined2 *)(pcVar5 + 2);
      *pcVar5 = -0x16;
      pcVar1 = pcVar5 + 3;
      *(undefined2 *)(pcVar5 + 1) = uVar3;
      pcVar5 = pcVar5 + 5;
      *(undefined2 *)pcVar1 = uVar2;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}



/* 1403:0690 */

void __cdecl16near __OvrUntrapJmps(void)

{
  char *pcVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  char *pcVar5;
  undefined2 unaff_ES;
  
  uVar2 = *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xc);
  iVar4 = *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 8);
  pcVar5 = (char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x1c;
  do {
    uVar3 = *(undefined2 *)(pcVar5 + 2);
    *pcVar5 = -0x16;
    pcVar1 = pcVar5 + 3;
    *(undefined2 *)(pcVar5 + 1) = uVar3;
    pcVar5 = pcVar5 + 5;
    *(undefined2 *)pcVar1 = uVar2;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}



/* 1403:06ae */

void __cdecl16near __OvrTrapJmpsAndStack(void)

{
  char *pcVar1;
  undefined2 uVar2;
  int iVar3;
  char *pcVar4;
  undefined2 unaff_ES;
  
  if (((char *)"Borland C++ - Copyright 1991 Borland Intl.")[0x1c] != -0x33) {
    uVar2 = 0;
    __OvrPatchStack();
    *(undefined2 *)((int)(undefined4 *)&_DATA + 2) = uVar2;
    iVar3 = *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 8);
    pcVar4 = (char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x1c;
    do {
      uVar2 = *(undefined2 *)(pcVar4 + 1);
      *(undefined2 *)pcVar4 = GUnitDescriptions[9]._1_2_;
      pcVar1 = pcVar4 + 4;
      *(undefined2 *)(pcVar4 + 2) = uVar2;
      pcVar4 = pcVar4 + 5;
      *pcVar1 = '\0';
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
  char *pcVar8;
  undefined2 unaff_ES;
  bool bVar9;
  
  uVar3 = GUnitDescriptions[0xd]._1_2_;
  uVar2 = *(uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xc);
  *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xc) =
       GUnitDescriptions[0xd]._1_2_;
  uVar4 = *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4) + 1U >> 1;
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
  *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 10) = unaff_ES;
  if (((char *)"Borland C++ - Copyright 1991 Borland Intl.")[0x1c] != -0x33) {
    uVar3 = __OvrPatchStack();
    iVar5 = *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 8);
    pcVar8 = (char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x1f;
    do {
      *(undefined2 *)pcVar8 = uVar3;
      pcVar8 = pcVar8 + 5;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return uVar3;
}



/* 1403:0732 */

void __cdecl16near __OvrAddToLoadList(void)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  undefined2 unaff_ES;
  
  iVar2 = __OvrCalcCodeSz();
  GUnitDescriptions[0xd]._1_2_ = GUnitDescriptions[0xd]._1_2_ + iVar2;
  pcVar1 = (char *)"manned n/s gate" + 0xe;
  do {
    pcVar3 = pcVar1;
    pcVar1 = *(char **)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x18);
  } while (*(char **)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x18) != (char *)0x0);
  *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x18) = unaff_ES;
  ((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x18)[0] = '\0';
  ((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x18)[1] = '\0';
  return;
}



/* 1403:0750 */

void __cdecl16near __OvrPatchStack(void)

{
  undefined2 in_CX;
  int in_BX;
  undefined2 unaff_SS;
  
  __OvrPatchStack();
  if (in_BX != 0) {
    LOCK();
    *(undefined2 *)(in_BX + 2) = in_CX;
    UNLOCK();
  }
  return;
}



/* 1403:075c */

void __cdecl16near __OvrPatchStack(void)

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
  
  if ((GUnitDescriptions[0x10]._1_2_ == 0) ||
     (iVar1 = *(uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xc) -
              GUnitDescriptions[0xd]._1_2_,
     *(uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xc) <
     (uint)GUnitDescriptions[0xd]._1_2_)) {
    iVar1 = GUnitDescriptions._59_2_ - GUnitDescriptions[0xd]._1_2_;
  }
  return iVar1;
}



/* 1403:079e */

uint __cdecl16near __OvrCalcCodeSz(void)

{
  undefined2 unaff_ES;
  
  return *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4) + 0x11U >> 4;
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
      (uVar1 = *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 10),
      *(int *)((int)&GUnitDescriptions[9].ofs + 1) != *(int *)0x0)) ||
     (in_AX != *(uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xc))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 1403:07f8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far __CHECKSTACK(void)

{
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
  puVar6 = (uint *)&stack0xfffe;
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



/* 1403:0890 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far __CHECKOVERLAY(undefined2 param_1,undefined2 param_2)

{
  undefined2 *puVar1;
  char *pcVar2;
  
  pcVar2 = (char *)"puppetmaker" + 3;
  if ((*(int *)((int)&GUnitDescriptions[9].ofs + 1) == *(int *)0x0) &&
     ((*(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xc) == 0 ||
      (((char *)"Borland C++ - Copyright 1991 Borland Intl.")[0x1c] == -0x33)))) {
    __OvrFixupTrap();
    ((char *)"Borland C++ - Copyright 1991 Borland Intl.")[0x16] =
         ((char *)"Borland C++ - Copyright 1991 Borland Intl.")[0x16] & 0xf7;
    puVar1 = (undefined2 *)((int)(uint16_t *)&__brklvl + 1);
    (*(code *)*puVar1)(0x1000,param_2,pcVar2);
  }
  return;
}



/* 1403:08e8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl16far _OvrInitEms(uint16_t emsHandle,uint16_t firstPage,uint16_t pages)

{
  long lVar1;
  long lVar2;
  undefined2 uVar3;
  uint uVar4;
  int iVar5;
  undefined2 uVar6;
  
  uVar3 = startx;
  if ((((char *)"Borland C++ - Copyright 1991 Borland Intl.")[0xc] & 1U) == 0) {
    if (emsHandle == 0) {
      uVar4 = __INITEMS((char *)"puppetmaker" + 3);
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
      iVar5 = __INITEMSPAGE(pages,firstPage,emsHandle);
      if (iVar5 == 0) {
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
        ((char *)"Borland C++ - Copyright 1991 Borland Intl.")[0xc] =
             ((char *)"Borland C++ - Copyright 1991 Borland Intl.")[0xc] | 2;
        *(undefined2 *)((int)(uint32_t *)&_StartTime + 3) = 0xe9f;
        *(undefined2 *)((int)(int *)&errno + 1) = 0xd0e;
        return 0;
      }
      return iVar5;
    }
  }
  return -1;
}



/* 1403:09c8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16near OVRSWAP_1403_09c8(void)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  code *pcVar4;
  bool bVar5;
  int iVar6;
  undefined2 in_CX;
  uint uVar7;
  undefined1 *puVar8;
  uint uVar9;
  undefined2 in_BX;
  undefined1 *puVar10;
  undefined2 unaff_ES;
  undefined1 in_CF;
  undefined4 uVar11;
  
  uVar11 = OVRSWAP_1403_0c2b();
  if ((bool)in_CF) {
    return;
  }
  (*ram0x00024186)(0x1403,(int)((ulong)uVar11 >> 0x10),in_CX,in_BX,(int)uVar11);
  puVar8 = (undefined1 *)(undefined1 *)(CONCAT22(in_CX,in_BX) % 0x4000);
  pcVar4 = (code *)swi(0x67);
  iVar6 = (*pcVar4)();
  if (-1 < iVar6) {
    uVar9 = *(uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4);
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
      if (iVar6 < 0) goto LAB_1403_0a36;
      uVar1 = *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xc);
      for (; uVar7 != 0; uVar7 = uVar7 - 1) {
        puVar3 = puVar8;
        puVar8 = puVar8 + 1;
        puVar2 = puVar10;
        puVar10 = puVar10 + 1;
        *puVar3 = *puVar2;
      }
      puVar8 = (undefined1 *)0x0;
    } while (uVar9 != 0);
    bVar5 = false;
LAB_1403_0a36:
    pcVar4 = (code *)swi(0x67);
    (*pcVar4)();
    if (!bVar5) {
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
             (CONCAT22(*(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x12),
                       *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x10))
             % 0x4000);
    uVar9 = *(uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4);
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
      uVar1 = *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xc);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl16far _OvrInitExt(uint32_t startAddress,uint32_t length)

{
  bool bVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  int in_DX;
  uint uVar5;
  
  uVar2 = startx;
  if ((*(byte *)&DAT_225d_0010 & 2) == 0) {
    bVar1 = false;
    iVar3 = __INITEXT();
    if (iVar3 == 0 && in_DX == 0) {
LAB_1403_0ad9:
      iVar3 = -1;
    }
    else {
      while( true ) {
        if ((startAddress._2_2_ < *(uint *)0x3c) ||
           ((startAddress._2_2_ == *(uint *)0x3c &&
            ((uint)startAddress < *(uint *)&__ExtStartAddress)))) {
          startAddress._2_2_ = *(uint *)0x3c;
          startAddress._0_2_ = *(uint *)&__ExtStartAddress;
        }
        if ((*(uint *)0x40 < startAddress._2_2_) ||
           ((*(uint *)0x40 <= startAddress._2_2_ && (*(uint *)&__ExtEndAddress < (uint)startAddress)
            ))) goto LAB_1403_0ad9;
        uVar4 = *(uint *)&__ExtEndAddress - (uint)startAddress;
        uVar5 = (*(int *)0x40 - startAddress._2_2_) -
                (uint)(*(uint *)&__ExtEndAddress < (uint)startAddress);
        if (((uint)length != 0 || length._2_2_ != 0) &&
           ((length._2_2_ <= uVar5 &&
            ((length._2_2_ < uVar5 || (*(uint *)&__ExtEndAddress < uVar4)))))) {
          uVar4 = (uint)length;
          uVar5 = length._2_2_;
        }
        if ((*(uint *)((char *)"Your may continue playing, but your score will not be recorded." + 9
                      ) <= uVar5) &&
           ((*(uint *)((char *)"Your may continue playing, but your score will not be recorded." + 9
                      ) < uVar5 ||
            (*(uint *)((char *)"Your may continue playing, but your score will not be recorded." + 7
                      ) < uVar4)))) {
          uVar5 = *(uint *)((char *)
                            "Your may continue playing, but your score will not be recorded." + 9);
          uVar4 = *(uint *)((char *)
                            "Your may continue playing, but your score will not be recorded." + 7);
        }
        length = CONCAT22(uVar5,uVar4);
        if ((uVar5 == 0) && (uVar4 >> 4 < *(uint *)&__OvrMinHeapSize)) goto LAB_1403_0ad9;
        *(uint *)&__EmsRec = (uint)startAddress;
        *(uint *)0x132 = startAddress._2_2_;
        *(int *)0x134 = uVar4 + (uint)startAddress;
        *(int *)0x136 = uVar5 + startAddress._2_2_ + (uint)CARRY2(uVar4,(uint)startAddress);
        *(uint *)0x138 = (uint)startAddress;
        *(uint *)0x13a = startAddress._2_2_;
        iVar3 = __INITEXTMEM(uVar4,uVar5,(uint)startAddress,startAddress._2_2_);
        if (iVar3 != 0) {
          return iVar3;
        }
        if (bVar1) break;
        bVar1 = true;
      }
      *(undefined2 *)0x13c = 0xbfb;
      *(undefined2 *)0x13e = 0;
      *(undefined2 *)0x112 = 1;
      *(byte *)&DAT_225d_0010 = *(byte *)&DAT_225d_0010 | 1;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16near OVRSWAP_1403_0bcc(void)

{
  undefined2 in_CX;
  undefined2 in_BX;
  undefined2 unaff_ES;
  undefined1 in_CF;
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = OVRSWAP_1403_0c2b();
  if (!(bool)in_CF) {
    (*ram0x00024186)(0x1403,(int)((ulong)uVar2 >> 0x10),in_CX,in_BX,(int)uVar2);
    bVar1 = (int)((ulong)*(uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xc) *
                  0x10 >> 0x10) != 0;
    __EXTCOPY();
    if (bVar1) {
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
  bVar1 = (int)((ulong)*(uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xc) * 0x10
               >> 0x10) != 0;
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
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined2 extraout_DX;
  undefined2 uVar6;
  uint uVar7;
  uint unaff_SI;
  uint unaff_DI;
  undefined2 unaff_ES;
  bool bVar8;
  undefined4 uVar9;
  char *pcVar10;
  
  pcVar10 = (char *)"puppetmaker" + 3;
  uVar7 = *(uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4);
  bVar8 = *(uint *)"Borland C++ - Copyright 1991 Borland Intl." < uVar7;
  uVar2 = *(uint *)"Borland C++ - Copyright 1991 Borland Intl." - uVar7;
  iVar3 = *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 6);
  iVar4 = *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 2) - iVar3;
  uVar9 = OVRSWAP_1403_0c1f();
  uVar5 = (uint)((ulong)uVar9 >> 0x10);
  if (uVar5 < unaff_DI || uVar5 - unaff_DI < (uint)((uint)uVar9 < unaff_SI)) {
    iVar3 = OVRSWAP_1403_0cd2();
    if (iVar3 != 0) {
      *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 10) =
           *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 10);
      ((char *)"Borland C++ - Copyright 1991 Borland Intl." + 10)[0] = '\0';
      ((char *)"Borland C++ - Copyright 1991 Borland Intl." + 10)[1] = '\0';
      OVRSWAP_1403_0d01();
      *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 10) = extraout_DX;
    }
    uVar7 = *(uint *)0x0;
    *(uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4) = uVar7;
    iVar3 = *(int *)((int)(undefined4 *)&_DATA + 2);
    *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 6) = iVar3;
    OVRSWAP_1403_0c1f();
    unaff_SI = uVar2;
    unaff_DI = iVar4 - (uint)bVar8;
  }
  iVar4 = OVRSWAP_1403_0cd2();
  if (iVar4 != 0) {
    *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 10) =
         *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 10);
  }
  puVar1 = (uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + unaff_SI;
  *(uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 6) =
       *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 6) + unaff_DI +
       (uint)CARRY2(uVar2,unaff_SI);
  *(uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x10) = uVar7;
  *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x12) = iVar3;
  *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x14) =
       *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 8);
  uVar9 = OVRSWAP_1403_0d01(pcVar10);
  uVar6 = (undefined2)((ulong)uVar9 >> 0x10);
  *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 10) = uVar6;
  *(int *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 10) = (int)uVar9;
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
  
  pcVar5 = (char *)"puppetmaker" + 3;
  pcVar4 = (char *)0x0;
  while( true ) {
    pcVar5 = *(char **)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 10);
    if (pcVar5 == (char *)0x0) {
      return pcVar4;
    }
    uVar1 = (uint)(*(uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x10) < in_BX);
    uVar2 = *(uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x12) - in_CX;
    uVar3 = uVar2 - uVar1;
    if (*(uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x12) < in_CX ||
        uVar2 < uVar1) break;
    if (unaff_DI <= uVar3 &&
        (uint)(*(uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x10) - in_BX <
              unaff_SI) <= uVar3 - unaff_DI) {
      return pcVar4;
    }
    *(undefined2 *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x14) = unaff_BP;
    pcVar4 = pcVar5;
  }
  return pcVar4;
}



/* 1403:0d01 */

void __cdecl16near OVRSWAP_1403_0d01(void)

{
  char *pcVar1;
  
  pcVar1 = (char *)"puppetmaker" + 3;
  do {
    pcVar1 = *(char **)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 10);
  } while (pcVar1 != (char *)0x0);
  return;
}



/* 1403:0d0e */

void __cdecl16near __SwapOverlay(void)

{
  if ((DAT_225d_0010 & 1) != 0) {
    OVRSWAP_1403_0bcc();
    return;
  }
  if ((DAT_225d_0010 & 2) != 0) {
    OVRSWAP_1403_09c8();
  }
  return;
}



/* 1403:0d24 */

void __cdecl16far __OvrPrepare(void)

{
  int iVar1;
  uint uVar2;
  far_t fVar3;
  
  __InitModules();
  uVar2 = __ovrbuffer;
  if (__ovrbuffer <= __OvrMinHeapSize) {
    uVar2 = __OvrMinHeapSize << 1;
  }
  uVar2 = uVar2 + 1;
  fVar3 = farmalloc((ulong)uVar2 * 0x10);
  if ((fVar3 != (far_t)0x0) &&
     (iVar1 = fVar3.seg + 1, iVar1 = __OVRINIT(0,0,uVar2 + iVar1,iVar1), iVar1 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  _abort();
}



/* 1403:0d88 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
    if (bVar4) goto LAB_1403_0e2c;
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
          if (unaff_ES == 0 && in_BX == 0) goto LAB_1403_0e2c;
          pcVar1 = (code *)swi(0x67);
          (*pcVar1)();
          if (extraout_AH != '\0') goto LAB_1403_0e2c;
          ((char *)"Divide error\r\n")[9] = '\x01';
          pcVar1 = (code *)swi(0x67);
          uVar3 = (*pcVar1)();
          if (((char)((uint)uVar3 >> 8) != '\0') || ((byte)uVar3 < 0x32)) goto LAB_1403_0e2c;
          ((char *)"Divide error\r\n")[10] = (byte)uVar3;
          pcVar1 = (code *)swi(0x67);
          (*pcVar1)();
          if (extraout_AH_00 != '\0') goto LAB_1403_0e2c;
          *(int *)((char *)"Divide error\r\n" + 1) = in_BX;
          goto LAB_1403_0e16;
        }
      }
    }
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
  }
  else {
    unaff_SI = startx;
    if ((((char *)"Divide error\r\n")[9] & 2U) != 0) {
      return *(int *)((char *)"Divide error\r\n" + 7);
    }
LAB_1403_0e16:
    pcVar1 = (code *)swi(0x67);
    (*pcVar1)();
    if (extraout_AH_01 == '\0') {
      *(int *)((char *)"Divide error\r\n" + 7) = in_BX;
      ((char *)"Divide error\r\n" + 3)[0] = -1;
      ((char *)"Divide error\r\n" + 3)[1] = -1;
      return in_BX;
    }
  }
LAB_1403_0e2c:
  ((char *)"Divide error\r\n")[9] = '\0';
  return 0;
}



/* 1403:0e3a */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __stdcall16far __INITEMSPAGE(undefined2 param_1,undefined2 param_2,int param_3)

{
  code *pcVar1;
  undefined2 uVar2;
  char extraout_AH;
  char extraout_AH_00;
  undefined1 extraout_AH_01;
  int extraout_DX;
  
  uVar2 = startx;
  if ((((char *)"Divide error\r\n")[9] & 1U) != 0) {
    if ((((char *)"Divide error\r\n")[9] & 2U) != 0) {
      return 0;
    }
    ((char *)"Divide error\r\n")[9] = ((char *)"Divide error\r\n")[9] | 2;
    *(undefined2 *)((char *)"Divide error\r\n" + 5) = param_2;
    *(undefined2 *)((char *)"Divide error\r\n" + 7) = param_1;
    if (param_3 == 0) {
      pcVar1 = (code *)swi(0x67);
      (*pcVar1)();
      if (extraout_AH != '\0') {
        return 0xffff;
      }
      ((char *)"Divide error\r\n")[9] = ((char *)"Divide error\r\n")[9] | 4;
      param_3 = extraout_DX;
    }
    *(int *)((char *)"Divide error\r\n" + 3) = param_3;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far __EXITEMS(void)

{
  code *pcVar1;
  undefined2 uVar2;
  
  uVar2 = startx;
  if (((((char *)"Divide error\r\n")[9] & 4U) != 0) &&
     (*(int *)((char *)"Divide error\r\n" + 3) != -1)) {
    pcVar1 = (code *)swi(0x67);
    (*pcVar1)();
    ((char *)"Divide error\r\n" + 3)[0] = -1;
    ((char *)"Divide error\r\n" + 3)[1] = -1;
    ((char *)"Divide error\r\n")[9] = '\0';
  }
  return;
}



/* 1403:0eca */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl16far __INITEXT(void)

{
  char *pcVar1;
  char *pcVar2;
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
  char *pcVar13;
  char *pcVar14;
  undefined2 unaff_SS;
  bool bVar15;
  undefined1 uVar16;
  undefined4 uVar17;
  char local_1f [8];
  uint uStack_17;
  uint uStack_f;
  
  uVar7 = startx;
  if ((((char *)"Abnormal program termination\r\n")[5] & 1U) == 0) {
    ((char *)"Abnormal program termination\r\n")[5] = '\x01';
LAB_1403_0eee:
    ((char *)"Divide error\r\n" + 0xb)[0] = '\0';
    ((char *)"Divide error\r\n" + 0xb)[1] = '\0';
    ((char *)"Divide error\r\n" + 0xd)[0] = '\x10';
    ((char *)"Divide error\r\n" + 0xd)[1] = '\0';
    ((char *)"Abnormal program termination\r\n" + 1)[0] = '\0';
    ((char *)"Abnormal program termination\r\n" + 1)[1] = '\0';
    ((char *)"Abnormal program termination\r\n" + 3)[0] = '\x10';
    ((char *)"Abnormal program termination\r\n" + 3)[1] = '\0';
    pcVar5 = (code *)swi(0x21);
    uVar9 = (*pcVar5)();
    if (((((byte)uVar9 < 10) && (DAT_f000_fffe < 0xfd)) && (DAT_f000_fffe != 0xfb)) &&
       (DAT_f000_fffe != 0xf9)) {
      if (0x30 < CONCAT11((byte)uVar9,(char)((uint)uVar9 >> 8))) {
        pcVar5 = (code *)swi(0x2f);
        cVar8 = (*pcVar5)();
        if (cVar8 == -0x80) {
          pcVar5 = (code *)swi(0x2f);
          (*pcVar5)();
          *(undefined2 *)((char *)"Abnormal program termination\r\n" + 6) = in_BX;
          ((char *)"Abnormal program termination\r\n" + 8)[0] = '\0';
          ((char *)"Abnormal program termination\r\n" + 8)[1] = -0x10;
          (**(code **)((char *)"Abnormal program termination\r\n" + 6))();
          if (1 < extraout_AH) {
            uVar11 = (**(code **)((char *)"Abnormal program termination\r\n" + 6))();
            if (uVar11 != 0) {
              uVar17 = (**(code **)((char *)"Abnormal program termination\r\n" + 6))();
              if ((int)uVar17 != 0) {
                *(int *)((char *)"Abnormal program termination\r\n" + 10) =
                     (int)((ulong)uVar17 >> 0x10);
                uVar17 = (**(code **)((char *)"Abnormal program termination\r\n" + 6))();
                if ((int)uVar17 != 0) {
                  *(undefined2 *)((char *)"Divide error\r\n" + 0xb) = in_BX;
                  *(int *)((char *)"Divide error\r\n" + 0xd) = (int)((ulong)uVar17 >> 0x10);
                  uVar10 = (uint)((ulong)uVar11 * 0x400);
                  uVar4 = *(uint *)((char *)"Divide error\r\n" + 0xb);
                  iVar12 = *(int *)((char *)"Divide error\r\n" + 0xd);
                  *(uint *)((char *)"Abnormal program termination\r\n" + 1) =
                       uVar10 + *(uint *)((char *)"Divide error\r\n" + 0xb);
                  *(uint *)((char *)"Abnormal program termination\r\n" + 3) =
                       (int)((ulong)uVar11 * 0x400 >> 0x10) + iVar12 + (uint)CARRY2(uVar10,uVar4);
                }
                (**(code **)((char *)"Abnormal program termination\r\n" + 6))();
                (**(code **)((char *)"Abnormal program termination\r\n" + 6))();
                ((char *)"Abnormal program termination\r\n" + 10)[0] = '\0';
                ((char *)"Abnormal program termination\r\n" + 10)[1] = '\0';
              }
            }
            goto LAB_1403_105f;
          }
        }
      }
      pcVar5 = (code *)swi(0x15);
      uVar11 = (*pcVar5)();
      if (uVar11 != 0) {
        lVar6 = (ulong)uVar11 * 0x400;
        *(int *)((char *)"Abnormal program termination\r\n" + 1) = (int)lVar6;
        *(uint *)((char *)"Abnormal program termination\r\n" + 3) =
             CONCAT11((char)((ulong)lVar6 >> 0x18),(char)((ulong)lVar6 >> 0x10) + '\x10');
        if (*(int *)((char *)"Abnormal program termination\r\n" + 6) != 0 ||
            *(int *)((char *)"Abnormal program termination\r\n" + 8) != 0) {
          ((char *)"Divide error\r\n")[0xd] = '\x11';
          ((char *)"Divide error\r\n" + 0xb)[0] = '\0';
          ((char *)"Divide error\r\n" + 0xb)[1] = '\0';
        }
        bVar15 = false;
        uVar16 = 1;
        __EXTCOPY();
        if (!bVar15) {
          pcVar14 = local_1f;
          pcVar13 = (char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x1c;
          iVar12 = 5;
          do {
            if (iVar12 == 0) break;
            iVar12 = iVar12 + -1;
            pcVar2 = pcVar14;
            pcVar14 = pcVar14 + 1;
            pcVar1 = pcVar13;
            pcVar13 = pcVar13 + 1;
            uVar16 = *pcVar1 == *pcVar2;
          } while ((bool)uVar16);
          if ((bool)uVar16) {
            *(int *)((char *)"Divide error\r\n" + 0xb) = (int)((ulong)uStack_17 * (ulong)uStack_f);
            ((char *)"Divide error\r\n")[0xd] =
                 (char)((ulong)uStack_17 * (ulong)uStack_f >> 0x10) + '\x10';
          }
          bVar15 = true;
          pcVar13 = (char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xe;
          pcVar14 = (char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x1c;
          iVar12 = 5;
          do {
            if (iVar12 == 0) break;
            iVar12 = iVar12 + -1;
            pcVar2 = pcVar13;
            pcVar13 = pcVar13 + 1;
            pcVar1 = pcVar14;
            pcVar14 = pcVar14 + 1;
            bVar15 = *pcVar1 == *pcVar2;
          } while (bVar15);
          if (bVar15) {
            bVar3 = ((char *)"Borland C++ - Copyright 1991 Borland Intl.")[0x2a];
            if (((byte)((char *)"Divide error\r\n")[0xd] <= bVar3) &&
               ((bVar3 != ((char *)"Divide error\r\n")[0xd] ||
                (*(uint *)((char *)"Divide error\r\n" + 0xb) <
                 *(uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x28))))) {
              *(uint *)((char *)"Divide error\r\n" + 0xb) =
                   *(uint *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0x28);
              ((char *)"Divide error\r\n")[0xd] = bVar3;
            }
          }
          goto LAB_1403_105f;
        }
      }
    }
    iVar12 = 0;
  }
  else {
    if ((((char *)"Abnormal program termination\r\n")[5] & 2U) == 0) goto LAB_1403_0eee;
LAB_1403_105f:
    iVar12 = *(int *)((char *)"Abnormal program termination\r\n" + 1) -
             *(int *)((char *)"Divide error\r\n" + 0xb);
  }
  return iVar12;
}



/* 1403:107a */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __stdcall16far __INITEXTMEM(uint param_1,int param_2,uint param_3,int param_4)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar1 = startx;
  if ((((char *)"Abnormal program termination\r\n")[5] & 1U) != 0) {
    if ((((char *)"Abnormal program termination\r\n")[5] & 2U) != 0) {
      return 0;
    }
    ((char *)"Abnormal program termination\r\n")[5] =
         ((char *)"Abnormal program termination\r\n")[5] | 2;
    if (*(int *)((char *)"Abnormal program termination\r\n" + 6) == 0 &&
        *(int *)((char *)"Abnormal program termination\r\n" + 8) == 0) {
      *(uint *)((char *)"Divide error\r\n" + 0xb) = param_3;
      *(int *)((char *)"Divide error\r\n" + 0xd) = param_4;
      _BootHandlerCode = uRam00000064;
      DAT_2272_0031 = pcRam00000066;
      uRam00000064 = 0x3f;
      pcRam00000066 = (char *)"nursery" + 2;
      DAT_2272_003a = param_3;
      DAT_2272_003c = (undefined1)param_4;
      iVar2 = param_3 + param_1;
      iVar3 = param_4 + param_2 + (uint)CARRY2(param_3,param_1);
      DAT_2272_002e = (undefined1)iVar3;
      DAT_2272_002c = iVar2;
LAB_1403_113d:
      *(int *)((char *)"Abnormal program termination\r\n" + 1) = iVar2;
      *(int *)((char *)"Abnormal program termination\r\n" + 3) = iVar3;
      return 0;
    }
    uVar4 = 0x400;
    uVar5 = (**(code **)((char *)"Abnormal program termination\r\n" + 6))(0x1000);
    if ((int)uVar5 != 0) {
      *(int *)((char *)"Abnormal program termination\r\n" + 10) = (int)((ulong)uVar5 >> 0x10);
      uVar5 = (**(code **)((char *)"Abnormal program termination\r\n" + 6))(0x1000);
      iVar3 = (int)((ulong)uVar5 >> 0x10);
      if ((int)uVar5 != 0) {
        *(uint *)((char *)"Divide error\r\n" + 0xb) = uVar4;
        *(int *)((char *)"Divide error\r\n" + 0xd) = iVar3;
        *(uint *)((char *)"Abnormal program termination\r\n" + 0xc) = uVar4;
        *(int *)((char *)"Abnormal program termination\r\n" + 0xe) = iVar3;
        iVar2 = uVar4 + param_1;
        iVar3 = iVar3 + param_2 + (uint)CARRY2(uVar4,param_1);
        goto LAB_1403_113d;
      }
    }
  }
  return 0xffff;
}



/* 1403:1152 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far __EXITEXT(void)

{
  undefined2 uVar1;
  
  uVar1 = startx;
  if (((char *)"Abnormal program termination\r\n")[5] != '\0') {
    if (*(int *)((char *)"Abnormal program termination\r\n" + 10) == 0) {
      if (pcRam00000066 == (char *)"nursery" + 2) {
        uRam00000064 = _BootHandlerCode;
        pcRam00000066 = DAT_2272_0031;
        ((char *)"Abnormal program termination\r\n")[5] = '\0';
      }
    }
    else {
      (**(code **)((char *)"Abnormal program termination\r\n" + 6))
                (0x1000,(char *)"puppetmaker" + 3);
      (**(code **)((char *)"Abnormal program termination\r\n" + 6))(0x1000);
    }
  }
  return;
}



/* 1403:11a6 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  
  uVar2 = startx;
  if (*(int *)((char *)"Abnormal program termination\r\n" + 10) == 0) {
    bVar7 = false;
    ((far_t *)(GSTARTX_SavedVectors + 1))->ofs = in_AX;
    *(byte *)&GSTARTX_SavedVectors[1].seg = (byte)in_DX;
    ((far_t *)(GSTARTX_SavedVectors + 3))->ofs = in_BX;
    *(byte *)&GSTARTX_SavedVectors[3].seg = (byte)in_CX;
    pcVar1 = (code *)swi(0x15);
    (*pcVar1)((char *)"puppetmaker" + 3);
    if (!(bool)bVar7) {
      return 0;
    }
  }
  else {
    *(uint *)((char *)"Abnormal program termination\r\n" + 0x10) = unaff_SI + 1 & 0xfffe;
    *(uint *)((char *)"Abnormal program termination\r\n" + 0x12) =
         unaff_DI + (uint)(0xfffe < unaff_SI);
    if ((byte)in_DX < 0x10) {
      ((char *)"Abnormal program termination\r\n" + 0x14)[0] = '\0';
      ((char *)"Abnormal program termination\r\n" + 0x14)[1] = '\0';
      uVar5 = in_DX >> 4 | in_DX << 0xc;
    }
    else {
      *(undefined2 *)((char *)"Abnormal program termination\r\n" + 0x14) =
           *(undefined2 *)((char *)"Abnormal program termination\r\n" + 10);
      bVar6 = in_AX < *(uint *)((char *)"Abnormal program termination\r\n" + 0xc);
      in_AX = in_AX - *(uint *)((char *)"Abnormal program termination\r\n" + 0xc);
      uVar5 = (in_DX - *(int *)((char *)"Abnormal program termination\r\n" + 0xe)) - (uint)bVar6;
    }
    *(uint *)((char *)"Abnormal program termination\r\n" + 0x16) = in_AX;
    *(uint *)((char *)"Abnormal program termination\r\n" + 0x18) = uVar5;
    if ((byte)in_CX < 0x10) {
      ((char *)"Abnormal program termination\r\n" + 0x1a)[0] = '\0';
      ((char *)"Abnormal program termination\r\n" + 0x1a)[1] = '\0';
      uVar4 = in_CX >> 4 | in_CX << 0xc;
    }
    else {
      *(undefined2 *)((char *)"Abnormal program termination\r\n" + 0x1a) =
           *(undefined2 *)((char *)"Abnormal program termination\r\n" + 10);
      bVar6 = in_BX < *(uint *)((char *)"Abnormal program termination\r\n" + 0xc);
      in_BX = in_BX - *(uint *)((char *)"Abnormal program termination\r\n" + 0xc);
      uVar4 = (in_CX - *(int *)((char *)"Abnormal program termination\r\n" + 0xe)) - (uint)bVar6;
    }
    *(uint *)((char *)"Abnormal program termination\r\n" + 0x1c) = in_BX;
    ((far_t *)GSTARTX_SavedVectors)->ofs = uVar4;
    iVar3 = (**(code **)((char *)"Abnormal program termination\r\n" + 6))(0x1000);
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


