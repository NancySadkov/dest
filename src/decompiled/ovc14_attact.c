/*
 * ovc14_attact.c - recovered from STRONG.EXE
 * memory block: OVC14_attact.c
 * range: 3f0b:0000 - 3f0b:2fbf
 * functions: 36
 */
#include "recovered.h"


/* 3f0b:0000 */

uint __cdecl16far attact_3f0b_0000(uint param_1,int param_2)

{
  uint in_AX;
  uint uVar1;
  int iVar2;
  byte bVar3;
  undefined2 uVar4;
  
  if (((((int)param_1 < 0) || (param_2 < 0)) || (in_AX = param_1 + 1, 0x93 < (int)in_AX)) ||
     (in_AX = param_2 + 1, 0x3b < (int)in_AX)) {
    uVar1 = in_AX & 0xff00;
  }
  else {
    uVar4 = (undefined2)((ulong)DAT_2000_cb09 >> 0x10);
    if ((*(uint *)((int)DAT_2000_cb09 + param_2 * 0x128 + param_1 * 2) & 3) == 0) {
      iVar2 = param_2 * 0x128 + (int)DAT_2000_cb09 + param_1 * 2;
      bVar3 = (byte)((uint)iVar2 >> 8);
      if ((*(uint *)(iVar2 + 0x128) & 3) == 0) {
        uVar1 = CONCAT11(bVar3,1);
      }
      else {
        uVar1 = (uint)bVar3 << 8;
      }
    }
    else {
      uVar1 = ((param_1 & 0x7fff) >> 7) << 8;
    }
  }
  return uVar1;
}



/* 3f0b:007e */

uint __cdecl16far attact_3f0b_007e(int param_1,int param_2)

{
  uint in_AX;
  uint uVar1;
  int iVar2;
  byte bVar3;
  
  if ((((param_1 < 0) || (param_2 < 0)) || (in_AX = param_1 + 1, 0x93 < (int)in_AX)) ||
     (in_AX = param_2 + 1, 0x3b < (int)in_AX)) {
    uVar1 = in_AX & 0xff00;
  }
  else {
    iVar2 = param_2 * 0x128 + (int)DAT_2000_cb09 + param_1 * 2;
    bVar3 = (byte)((uint)iVar2 >> 8);
    if ((*(uint *)(iVar2 + 0x128) & 3) == 0) {
      uVar1 = CONCAT11(bVar3,1);
    }
    else {
      uVar1 = (uint)bVar3 << 8;
    }
  }
  return uVar1;
}



/* 3f0b:00d8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl16far attact_3f0b_00d8(int param_1,int param_2)

{
  uint in_AX;
  uint uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_SS;
  int local_a [4];
  
  if ((((param_1 < 0) || (param_2 < 0)) || (in_AX = param_1 + 1, 0x93 < (int)in_AX)) ||
     (in_AX = param_2 + 1, 0x3b < (int)in_AX)) {
    uVar1 = in_AX & 0xff00;
  }
  else {
    uVar5 = (undefined2)((ulong)DAT_2000_cb05 >> 0x10);
    iVar3 = (int)DAT_2000_cb05;
    local_a[0] = (int)*(char *)(iVar3 + param_2 * 0x94 + param_1);
    local_a[1] = (int)*(char *)(iVar3 + param_2 * 0x94 + param_1 + 1);
    local_a[2] = (int)*(char *)(param_2 * 0x94 + iVar3 + param_1 + 0x94);
    local_a[3] = (int)*(char *)(param_2 * 0x94 + iVar3 + param_1 + 0x95);
    iVar3 = local_a[0];
    for (iVar4 = 1; iVar4 < 4; iVar4 = iVar4 + 1) {
      if (local_a[iVar4] < iVar3) {
        iVar3 = local_a[iVar4];
      }
      if (local_a[0] < local_a[iVar4]) {
        local_a[0] = local_a[iVar4];
      }
    }
    bVar2 = (byte)((uint)(local_a[0] - iVar3) >> 8);
    if (local_a[0] - iVar3 < 0x3c) {
      uVar1 = CONCAT11(bVar2,1);
    }
    else {
      uVar1 = (uint)bVar2 << 8;
    }
  }
  return uVar1;
}



/* 3f0b:01ec */

undefined2 __cdecl16far attact_3f0b_01ec(int param_1,int param_2)

{
  char cVar1;
  undefined2 uVar2;
  
  cVar1 = attact_3f0b_007e(param_1,param_2);
  if (cVar1 == '\0') {
    uVar2 = 0;
  }
  else {
    cVar1 = attact_3f0b_00d8(param_1,param_2);
    if (cVar1 == '\0') {
      uVar2 = 0;
    }
    else if ((*(byte *)((uint)*(byte *)((int)DAT_2000_ca95 +
                                       *(int *)((int)DAT_2000_cb0d + param_1 * 0x78 + param_2 * 2) *
                                       9) * 0x27 + 0x11e) & 3) == 3) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* 3f0b:027d */

uint __cdecl16far attact_3f0b_027d(int param_1,int param_2,byte param_3,char param_4)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  
  iVar1 = (int)*(char *)(param_3 + 0x885);
  if ((((param_1 + iVar1 < 2) ||
       (iVar1 = (int)*(char *)(param_3 + 0x889), SCARRY2(param_2,iVar1) != param_2 + iVar1 < 0)) ||
      (iVar1 = (int)*(char *)(param_3 + 0x885), 0x91 < param_1 + iVar1)) ||
     (iVar1 = (int)*(char *)(param_3 + 0x889), 0x39 < param_2 + iVar1)) {
    uVar2 = CONCAT11((char)((uint)iVar1 >> 8),1);
  }
  else {
    uVar3 = (undefined2)((ulong)DAT_2000_cb09 >> 0x10);
    uVar2 = *(uint *)((int)DAT_2000_cb09 + param_2 * 0x128 + param_1 * 2) >> (param_3 + 4 & 0x1f);
    if (((uVar2 & 1) == 0) || (param_4 != '\0')) {
      uVar2 = (uint)((byte)uVar2 & 1);
    }
    else {
      uVar2 = *(uint *)((int)DAT_2000_cb09 + param_2 * 0x128 + param_1 * 2) >> (param_3 + 8 & 0x1f)
              & 0xff01 ^ 1;
    }
  }
  return uVar2;
}



/* 3f0b:0362 */

uint __cdecl16far attact_3f0b_0362(int param_1,int param_2,byte param_3,char param_4,char param_5)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  
  iVar1 = (int)*(char *)(param_3 + 0x885);
  if (((1 < param_1 + iVar1) &&
      (iVar1 = (int)*(char *)(param_3 + 0x889), SCARRY2(param_2,iVar1) == param_2 + iVar1 < 0)) &&
     (iVar1 = (int)*(char *)(param_3 + 0x885), param_1 + iVar1 < 0x92)) {
    iVar1 = (int)*(char *)(param_3 + 0x889);
    if (param_2 + iVar1 < 0x3a) {
      if (param_5 != '\0') {
        return (uint)(byte)(*(char *)(param_3 + 0x889) >> 7) << 8;
      }
      uVar3 = (undefined2)((ulong)DAT_2000_cb09 >> 0x10);
      uVar2 = *(uint *)((int)DAT_2000_cb09 + param_2 * 0x128 + param_1 * 2) >> (param_3 + 4 & 0x1f);
      if (((uVar2 & 1) != 0) && (param_4 == '\0')) {
        return *(uint *)((int)DAT_2000_cb09 + param_2 * 0x128 + param_1 * 2) >> (param_3 + 8 & 0x1f)
               & 0xff01 ^ 1;
      }
      return (uint)((byte)uVar2 & 1);
    }
  }
  return CONCAT11((char)((uint)iVar1 >> 8),1);
}



/* 3f0b:0451 */

int __cdecl16far attact_3f0b_0451(byte param_1)

{
  uint16_t uVar1;
  uint uVar2;
  int iVar3;
  uint16_t uVar4;
  
  iVar3 = 0;
  if (((undefined1 *)&DAT_2000_d1de)[param_1] == -1) {
    iVar3 = 0;
  }
  else {
    for (uVar2 = 0; uVar2 < EntityCount; uVar2 = uVar2 + 1) {
      uVar4 = Entities.seg;
      uVar1 = Entities.ofs;
      if (((*(char *)(uVar1 + uVar2 * 0x37 + 0x1a) == ((undefined1 *)&DAT_2000_d1de)[param_1]) &&
          (((*(uint *)(uVar1 + uVar2 * 0x37) < GfxRndSeed - 2U ||
            (GfxRndSeed + 1U < *(uint *)(uVar1 + uVar2 * 0x37))) ||
           (*(int *)(uVar1 + uVar2 * 0x37 + 2) != GfxRndSeed2)))) &&
         ((*(byte *)(uVar1 + uVar2 * 0x37 + 0x33) & 2) == 0)) {
        iVar3 = iVar3 + 1;
      }
    }
    if (0x50 < iVar3) {
      iVar3 = 0x50;
    }
  }
  return iVar3;
}



/* 3f0b:0540 */

undefined2 __cdecl16far attact_3f0b_0540(int param_1)

{
  long lVar1;
  long b;
  
  DAT_2000_d114 = attact_3f0b_0451();
  b = 0x51;
  lVar1 = LXMUL_at_((ulong)(DAT_2000_d114 + 1),(long)param_1);
  lVar1 = LDIV_at_(lVar1,b);
  return (int)lVar1;
}



/* 3f0b:057a */

void __cdecl16far attact_3f0b_057a(void)

{
  DAT_2410_0881 = 0;
  return;
}



/* 3f0b:0585 */

int __cdecl16far attact_3f0b_0585(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (DAT_2410_0881 <= uVar1) {
      return 0x86e;
    }
    if ((*(int *)(uVar1 * 0x13) == param_1) && (*(int *)(uVar1 * 0x13 + 2) == param_2)) break;
    uVar1 = uVar1 + 1;
  }
  return uVar1 * 0x13;
}



/* 3f0b:05df */

void __cdecl16far attact_3f0b_05df(void)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (DAT_2410_0881 <= uVar1) {
      DAT_2410_086e = GfxRndSeed;
      DAT_2410_0870 = GfxRndSeed2;
      memcpy((uint8_t *)0x9074,(uint8_t *)&DAT_2410_086e,0x13);
      DAT_2410_0883 = DAT_2410_0881;
      return;
    }
    if ((*(int *)(uVar1 * 0x13) == GfxRndSeed) && (*(int *)(uVar1 * 0x13 + 2) == GfxRndSeed2))
    break;
    uVar1 = uVar1 + 1;
  }
  memcpy((uint8_t *)0x9074,(uint8_t *)(uVar1 * 0x13),0x13);
  DAT_2410_0883 = uVar1;
  return;
}



/* 3f0b:0685 */

void __cdecl16far attact_3f0b_0685(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  
  if (AgntFlag1) {
    cVar3 = ovr_OVC15_4207_288b();
    if (cVar3 == '\0') {
      for (iVar4 = 0; iVar4 < (int)(uint)AgntCount; iVar4 = iVar4 + 1) {
        uVar1 = *(undefined4 *)(iVar4 * 0x34 + 0x17);
        uVar2 = *(undefined4 *)(iVar4 * 0x34 + 0x17);
        *(undefined1 *)((int)uVar2 + 0x31) = *(undefined1 *)((int)uVar1 + 0x32);
      }
    }
    else {
      for (iVar4 = 0; iVar4 < (int)(uint)AgntCount; iVar4 = iVar4 + 1) {
        uVar1 = *(undefined4 *)(iVar4 * 0x34 + 0x17);
        *(undefined1 *)((int)uVar1 + 0x31) = *(undefined1 *)(iVar4 * 0x34 + 0x21);
      }
    }
  }
  if (DAT_2410_0883 < DAT_2410_0881) {
    if (DAT_2410_0883 + 1 < DAT_2410_0881) {
      _fmemmove((uint8_t *)(DAT_2410_0883 * 0x13),(uint8_t *)((DAT_2410_0883 + 1) * 0x13),
                ((DAT_2410_0881 - DAT_2410_0883) + -1) * 0x13);
    }
    DAT_2410_0881 = DAT_2410_0881 - 1;
    iVar4 = memcmp(0x86e,(char *)"puppetmaker" + 3,0x9074,(char *)"puppetmaker" + 3,0x13);
    if (iVar4 == 0) {
      func_0x00030e61(0x1000,0x9074,(char *)"puppetmaker" + 3);
      return;
    }
  }
  else {
    iVar4 = memcmp(0x86e,(char *)"puppetmaker" + 3,0x9074,(char *)"puppetmaker" + 3,0x13);
    if (iVar4 == 0) {
      func_0x00030e61(0x1000,0x9074,(char *)"puppetmaker" + 3);
      return;
    }
    if (299 < DAT_2410_0881) {
      _fmemmove((uint8_t *)0x0,
                (uint8_t *)((char *)"Borland C++ - Copyright 1991 Borland Intl." + 0xf),0x1631);
      DAT_2410_0881 = 299;
    }
  }
  memcpy((uint8_t *)(DAT_2410_0881 * 0x13),(uint8_t *)0x9074,0x13);
  iVar4 = DAT_2410_0881 * 0x13;
  DAT_2410_0881 = DAT_2410_0881 + 1;
  func_0x00030e61(0x1000,iVar4,0x17f8);
  return;
}



/* 3f0b:082f */

/* WARNING: Removing unreachable block (ram,0x0003f909) */

ulong __cdecl16far attact_3f0b_082f(ulong param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs + 2);
  uVar1 = *(uint *)BDA_DailyTimeCounter;
  if (CONCAT22(iVar3,uVar1) < param_1) {
    iVar2 = (uVar1 + 0xb0) - (uint)param_1;
    iVar3 = ((iVar3 + 0x18 + (uint)(0xff4f < uVar1)) - (*(uint16_t *)((uint8_t *)&(param_1) + 2))) -
            (uint)(uVar1 + 0xb0 < (uint)param_1);
  }
  else {
    iVar2 = uVar1 - (uint)param_1;
    iVar3 = (iVar3 - (*(uint16_t *)((uint8_t *)&(param_1) + 2))) - (uint)(uVar1 < (uint)param_1);
  }
  return CONCAT22(iVar3,iVar2);
}



/* 3f0b:0880 */

void __cdecl16far attact_3f0b_0880(char *param_1)

{
  if (*param_1 != '\0') {
    *param_1 = *param_1 + -1;
  }
  return;
}



/* 3f0b:0894 */

int __cdecl16far attact_3f0b_0894(int param_1)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  undefined1 uStack_3;
  
  uStack_3 = 0;
  for (bVar3 = 0; bVar3 < AgntCount; bVar3 = bVar3 + 1) {
    if (((*(int *)((uint)bVar3 * 0x34 + 0x1b) == param_1) &&
        (*(char *)((uint)bVar3 * 0x34 + 0x25) != '\x02')) &&
       ((*(uint *)((uint)bVar3 * 0x34 + 0x2b) & 0xae4) == 0)) {
      uStack_3 = uStack_3 + 1;
    }
  }
  uVar1 = (*(byte *)(Entities.ofs + param_1 * 0x37 + 0xe) + 0xf) / 0x10;
  if (uVar1 < uStack_3) {
    iVar2 = 0;
  }
  else {
    iVar2 = uVar1 - uStack_3;
  }
  return iVar2;
}



/* 3f0b:0941 */

void __cdecl16far attact_3f0b_0941(undefined2 param_1,int param_2,char param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uStack_8;
  byte bStack_3;
  
  if (param_3 != -1) {
    iVar1 = ovr_OVC23_55fe_3450(param_1);
    for (bStack_3 = 0; bStack_3 < 5; bStack_3 = bStack_3 + 1) {
      if (((undefined1 *)&DAT_2000_d1de)[bStack_3] == param_3) {
        uVar3 = 0;
        while ((uVar3 < DAT_2410_0881 &&
               ((iVar2 = ovr_OVC23_55fe_3450(*(undefined2 *)(uVar3 * 0x13)), iVar2 != iVar1 ||
                (*(int *)(uVar3 * 0x13 + 2) != param_2))))) {
          uVar3 = uVar3 + 1;
        }
        if (DAT_2410_0881 <= uVar3) {
          return;
        }
        uStack_8 = 0;
        for (uVar4 = 0; uVar4 < EntityCount; uVar4 = uVar4 + 1) {
          iVar2 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + uVar4 * 0x37 + 8));
          if (iVar2 == iVar1) {
            if ((*(int *)(Entities.ofs + uVar4 * 0x37 + 10) == param_2) &&
               (*(char *)(Entities.ofs + uVar4 * 0x37 + 0x1a) == param_3)) {
              uStack_8 = uStack_8 + 1;
            }
          }
        }
        if (*(byte *)(uVar3 * 0x13 + (uint)bStack_3 + 0xe) != uStack_8) {
          *(undefined1 *)(uVar3 * 0x13 + (uint)bStack_3 + 0xe) = (undefined1)uStack_8;
          iVar2 = ovr_OVC23_55fe_3450(GfxRndSeed);
          if ((iVar2 == iVar1) && (GfxRndSeed2 == param_2)) {
            if ((int)param_4 == 0 && (*(uint16_t *)((uint8_t *)&(param_4) + 2)) == 0) {
              ovr_OVC41_6a8f_1be0(bStack_3);
            }
            else {
              *(undefined1 *)((int)param_4 + (uint)bStack_3) = 1;
            }
          }
        }
      }
    }
  }
  return;
}



/* 3f0b:0ade */

void __cdecl16far
attact_3f0b_0ade(int param_1,int param_2,int param_3,undefined2 param_4,undefined2 param_5)

{
  int iVar1;
  int iVar2;
  uint16_t uVar3;
  uint16_t uVar4;
  
  *(undefined1 *)(Entities.ofs + param_1 * 0x37 + 0x2f) = 0;
  *(undefined1 *)(Entities.ofs + param_1 * 0x37 + 0x30) = 0;
  uVar4 = Entities.seg;
  uVar3 = Entities.ofs;
  iVar1 = *(int *)(uVar3 + param_1 * 0x37 + 8);
  iVar2 = *(int *)(uVar3 + param_1 * 0x37 + 10);
  if ((*(int *)(uVar3 + param_1 * 0x37) == param_2) &&
     (*(int *)(uVar3 + param_1 * 0x37 + 2) == param_3)) {
    param_2 = 0;
    param_3 = 0;
  }
  *(int *)(uVar3 + param_1 * 0x37 + 8) = param_2;
  *(int *)(Entities.ofs + param_1 * 0x37 + 10) = param_3;
  if ((iVar1 != 0) || (iVar2 != 0)) {
    attact_3f0b_0941(iVar1,iVar2,
                     CONCAT11((char)((uint)(param_1 * 0x37) >> 8),
                              *(undefined1 *)(Entities.ofs + param_1 * 0x37 + 0x1a)),param_4,param_5
                    );
  }
  if ((param_2 != 0) || (param_3 != 0)) {
    attact_3f0b_0941(param_2,param_3,
                     CONCAT11((char)((uint)(param_1 * 0x37) >> 8),
                              *(undefined1 *)(Entities.ofs + param_1 * 0x37 + 0x1a)),param_4,param_5
                    );
  }
  return;
}



/* 3f0b:0c2a */

void __stdcall16far attact_3f0b_0c2a(void)

{
  uint *puVar1;
  uint16_t uVar2;
  uint uVar3;
  uint16_t uVar4;
  
  ovr_driver_2d63_0a67((undefined2)DAT_2000_cb09,(*(uint16_t *)((uint8_t *)&(DAT_2000_cb09) + 2)),0,0,0x93,0x3b,0xcfff);
  for (uVar3 = 0; uVar3 < EntityCount; uVar3 = uVar3 + 1) {
    uVar4 = Entities.seg;
    uVar2 = Entities.ofs;
    puVar1 = (uint *)((int)DAT_2000_cb09 + *(int *)(uVar2 + uVar3 * 0x37 + 2) * 0x128 +
                     *(int *)(uVar2 + uVar3 * 0x37) * 2);
    *puVar1 = *puVar1 | 0x1000 << (*(byte *)((int)(char **)GMenuStrings +
                                            (uint)*(byte *)(uVar2 + uVar3 * 0x37 + 0xd) * 0x95 +
                                            0x1f) & 0x1f);
  }
  ovr_OVC15_4207_288b();
  draw_2e25_1e42();
  return;
}



/* 3f0b:1082 */

void __cdecl16far attact_3f0b_1082(void)

{
  undefined4 uVar1;
  uint16_t uVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  uint16_t uVar8;
  uint *puVar9;
  uint uVar10;
  uint index;
  char *pcVar11;
  undefined2 unaff_SS;
  far_t ptr;
  undefined4 uStack_1e;
  char cStack_1a;
  char local_17;
  int iStack_16;
  int iStack_14;
  int iStack_12;
  undefined1 uStack_f;
  char local_e [6];
  uint uStack_8;
  uint uStack_6;
  byte bStack_4;
  undefined1 uStack_3;
  
  func_0x0004f735();
  local_17 = '\0';
  _fmemset((char *)CONCAT22(unaff_SS,local_e),0,5);
  GGameState = 0x3f;
  if (DebugVerbose != false) {
    printf("%d %d %d \r",0x3f);
  }
  DAT_2000_d165 = 0;
  DAT_2000_d163 = 0;
  index = 0;
  do {
    uVar2 = Entities.seg;
    if (EntityCount <= index) {
      GGameState = 0x3c;
      if (DebugVerbose != false) {
        printf("%d %d %d  \r",0x3c);
      }
      func_0x0004fcda();
      GGameState = 0x3d;
      if (DebugVerbose != false) {
        printf("%d %d %d  \r",0x3d);
      }
      ovr_OVC23_55fe_2b82();
      GGameState = 0xc;
      if (DebugVerbose != false) {
        printf("%d %d %d  \r",0xc);
      }
      ovr_OVC24_5943_0d5a(&local_17);
      GGameState = 0x1f;
      if (local_17 != '\0') {
        ovr_constr_36ce_03a6();
        GGameState = 0x13;
      }
      func_0x0004f68f();
      GGameState = 0x1d;
      for (iVar6 = 0; iVar6 < 5; iVar6 = iVar6 + 1) {
        if (local_e[iVar6] != '\0') {
          ovr_OVC41_6a8f_1be0();
        }
      }
      GGameState = 0xd;
      if (DebugVerbose != false) {
        printf("%d %d %d  \r",0xd);
      }
      ovr_OVC24_5943_112e();
      GGameState = 0xe;
      DAT_2410_648e = 1;
      return;
    }
    puVar9 = (uint *)(Entities.ofs + index * 0x37);
    uStack_1e = (uint *)CONCAT22(Entities.seg,puVar9);
    iVar6 = ovr_OVC23_55fe_3450();
    iVar7 = ovr_OVC23_55fe_3450();
    if ((iVar6 == iVar7) && (puVar9[5] == puVar9[1])) {
      manage_4d05_2b3e(index,puVar9[4],puVar9[5],local_e);
    }
    if ((puVar9[4] != 0 || puVar9[5] != 0) && ((char)puVar9[0xc] == '\0')) {
      uStack_3 = (*(uint *)((int)&far_t_ARRAY_2410_26f7[7].ofs + 1 +
                           (uint)*(byte *)((int)puVar9 + 0xd) * 0x95) & 0x4000) != 0;
      uStack_6 = *uStack_1e;
      uStack_8 = puVar9[1];
      uStack_f = *(undefined1 *)
                  ((int)(char **)GMenuStrings + (uint)*(byte *)((int)puVar9 + 0xd) * 0x95 + 0x1f);
      if (*(byte *)((int)puVar9 + 0x2f) < (byte)puVar9[0x18]) {
        uVar10 = (int)(uint)*(byte *)((int)puVar9 +
                                     ((int)(uint)*(byte *)((int)puVar9 + 0x2f) >> 2) + 0x1b) >>
                 ((*(byte *)((int)puVar9 + 0x2f) & 3) << 1) & 0xff03;
        *(char *)(puVar9 + 6) = (char)uVar10;
        cVar3 = func_0x0004f32d((char *)"dwarf outpost" + 6,*uStack_1e,puVar9[1],
                                CONCAT11((char)(uVar10 >> 8),(char)puVar9[6]));
        if (cVar3 == '\0') {
          *uStack_1e = *uStack_1e + (int)*(char *)((byte)puVar9[6] + 0x885);
          puVar9[1] = puVar9[1] + (int)*(char *)((byte)puVar9[6] + 0x889);
          *(char *)((int)puVar9 + 0x2f) = *(char *)((int)puVar9 + 0x2f) + '\x01';
        }
        else {
          *(undefined1 *)((int)puVar9 + 0x2f) = 0;
          *(undefined1 *)(puVar9 + 0x18) = 0;
        }
      }
      else {
        iStack_12 = ovr_OVC07_32c9_0026();
        pcVar11 = (char *)"public baths" + 6;
        iStack_14 = ovr_OVC07_32c9_0026();
        if (iStack_12 != 0) {
          pcVar11 = (char *)"glassworks" + 9;
          uVar8 = ovr_randBelow(2);
          if ((char)uVar8 != '\0') {
            cVar3 = func_0x0004f412((char *)"glassworks" + 9,uStack_6,uStack_8,
                                    '\x02' - (char)iStack_12,uStack_f);
            if (cVar3 == '\0') {
              *uStack_1e = *uStack_1e + iStack_12;
              *(char *)(puVar9 + 6) = '\x02' - (char)iStack_12;
              goto LAB_3f0b_1477;
            }
          }
        }
        if (iStack_14 != 0) {
          cVar3 = func_0x0004f412(pcVar11,uStack_6,uStack_8,(char)iStack_14 + '\x01',uStack_f);
          if (cVar3 == '\0') {
            puVar9[1] = puVar9[1] + iStack_14;
            *(char *)(puVar9 + 6) = (char)iStack_14 + '\x01';
            goto LAB_3f0b_1477;
          }
        }
        if (iStack_12 != 0) {
          cVar3 = func_0x0004f412(pcVar11,uStack_6,uStack_8,'\x02' - (char)iStack_12,uStack_f);
          if (cVar3 == '\0') {
            *uStack_1e = *uStack_1e + iStack_12;
            *(char *)(puVar9 + 6) = '\x02' - (char)iStack_12;
            goto LAB_3f0b_1477;
          }
        }
        cVar3 = ovr_OVC26_5d45_031f();
        if (cVar3 == '\0') {
          cVar3 = ovr_OVC26_5d45_06f0(index,&local_17);
          if ((cVar3 == '\0') &&
             (*(char *)((int)(char **)GMenuStrings +
                       (uint)*(byte *)((int)puVar9 + 0xd) * 0x95 + 0x1f) == '\0')) {
            manage_4d05_2b3e(index,puVar9[2],puVar9[3],local_e);
          }
        }
        else {
          uVar10 = (int)(uint)*(byte *)((int)puVar9 +
                                       ((int)(uint)*(byte *)((int)puVar9 + 0x2f) >> 2) + 0x1b) >>
                   ((*(byte *)((int)puVar9 + 0x2f) & 3) << 1) & 0xff03;
          *(char *)(puVar9 + 6) = (char)uVar10;
          cVar3 = func_0x0004f32d((char *)"elf outpost" + 5,uStack_6,uStack_8,
                                  CONCAT11((char)(uVar10 >> 8),(char)puVar9[6]));
          if (cVar3 == '\0') {
            *uStack_1e = *uStack_1e + (int)*(char *)((byte)puVar9[6] + 0x885);
            puVar9[1] = puVar9[1] + (int)*(char *)((byte)puVar9[6] + 0x889);
            *(char *)((int)puVar9 + 0x2f) = *(char *)((int)puVar9 + 0x2f) + '\x01';
          }
        }
      }
LAB_3f0b_1477:
      local_17 = '\x01';
      iVar6 = ovr_OVC23_55fe_3450();
      iVar7 = ovr_OVC23_55fe_3450();
      if ((iVar6 == iVar7) && (puVar9[5] == puVar9[1])) {
        puVar9[4] = 0;
        puVar9[5] = 0;
        if ((char)puVar9[0xd] == -1) {
          bStack_4 = 0xff;
        }
        else {
          uVar1 = *(undefined4 *)((uint)(byte)puVar9[0xd] << 2);
          bStack_4 = *(byte *)((int)uVar1 + 0x89);
        }
        if (bStack_4 != 0xff) {
          for (uVar10 = 0; uVar10 < DAT_2410_0881; uVar10 = uVar10 + 1) {
            iVar6 = ovr_OVC23_55fe_3450();
            iVar7 = ovr_OVC23_55fe_3450();
            if ((iVar6 == iVar7) && (*(uint *)(uVar10 * 0x13 + 2) == puVar9[1])) {
              manage_4d05_28e0((char *)"dwarf outpost" + 6,uVar10 * 0x13 + (uint)bStack_4 + 0xe);
              if (*(uint *)(uVar10 * 0x13 + 2) == GfxRndSeed2) {
                iVar6 = ovr_OVC23_55fe_3450();
                iVar7 = ovr_OVC23_55fe_3450();
                if (iVar6 == iVar7) {
                  local_e[bStack_4] = '\x01';
                }
              }
              break;
            }
          }
        }
      }
      if (AgntFlag1 != false) {
        if (((*uStack_1e < GfxRndSeed - 2U) || (GfxRndSeed + 1U < *uStack_1e)) ||
           (puVar9[1] != GfxRndSeed2)) {
          bVar4 = false;
        }
        else {
          bVar4 = true;
        }
        if (((uStack_6 < GfxRndSeed - 2U) || (GfxRndSeed + 1U < uStack_6)) ||
           (GfxRndSeed2 != uStack_8)) {
          bVar5 = false;
        }
        else {
          bVar5 = true;
        }
        if (bVar5 || bVar4) {
          if (bVar5) {
            if (bVar4) {
              for (cStack_1a = manage_4d05_28f4(); cStack_1a != '\0'; cStack_1a = cStack_1a + -1) {
                if ((puVar9[6] & 1) == 0) {
                  iStack_16 = 0;
                }
                else {
                  iStack_16 = (byte)puVar9[6] - 2;
                }
                cVar3 = ovr_OVC15_4207_2301(index,iStack_16);
                if (cVar3 == '\0') break;
              }
            }
            else {
              cStack_1a = (char)((ulong)((byte)puVar9[7] + 0xf) / 0x10);
              while (cStack_1a != '\0') {
                ptr.seg = Entities.seg;
                ptr.ofs = Entities.ofs + index * 0x37;
                ovr_agnt_3b1d_196b(ptr);
                cStack_1a = cStack_1a + -1;
              }
            }
          }
          else {
            ovr_OVC15_4207_0b88();
            cStack_1a = (char)((ulong)((byte)puVar9[7] + 0xf) / 0x10);
            if ((puVar9[6] & 1) == 0) {
              iStack_16 = 0;
            }
            else {
              iStack_16 = (byte)puVar9[6] - 2;
            }
            while (cStack_1a != '\0') {
              ovr_OVC15_4207_2301(index,iStack_16);
              cStack_1a = cStack_1a + -1;
            }
          }
        }
      }
    }
    index = index + 1;
  } while( true );
}



/* 3f0b:18fe */

void __cdecl16far attact_3f0b_18fe(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  char *txt;
  undefined2 dst;
  char local_56 [80];
  char *pcStack_6;
  byte bStack_4;
  char cStack_3;
  
  if ((param_1 < 5) &&
     ((pcStack_6 = (char *)(uint)*(byte *)(param_1 + -0x6f7e), param_2 != 0 ||
      (DAT_2000_d112 != pcStack_6)))) {
    DAT_2000_d112 = pcStack_6;
    ovr_font_302d_0a30();
    bStack_4 = ((undefined1 *)&DAT_2000_d1de)[param_1];
    if (bStack_4 != 0xff) {
      iVar1 = ovr_OVC23_55fe_2da3();
      if (iVar1 < 0) {
        ovr_drawTextAt("You cannot attract units to this location.",0xa000);
        *(undefined1 *)(param_1 + -0x6f7e) = 0;
      }
      else {
        pcVar2 = (char *)func_0x0004f501();
        DAT_2000_d114 = pcVar2;
        if (pcVar2 < pcStack_6) {
          (*(uint8_t *)((uint8_t *)&(pcStack_6))) = SUB21(pcVar2,0);
          *(undefined1 *)(param_1 + -0x6f7e) = (*(uint8_t *)((uint8_t *)&(pcStack_6)));
          pcStack_6 = pcVar2;
        }
        cStack_3 = *(char *)((int)*(undefined4 *)((uint)bStack_4 << 2) + 0x2f);
        if (cStack_3 != -1) {
          dst = 0xa000;
          ovr_OVC41_6a8f_0000();
          txt = ovr_stsprintf(local_56,"Attracting %d of a possible %d %s%s to this location.",
                              pcStack_6);
          ovr_drawTextAt(txt,dst);
        }
      }
    }
  }
  return;
}



/* 3f0b:1a2f */

char * __cdecl16far
attact_3f0b_1a2f(uint *param_1,int param_2,char param_3,undefined2 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint16_t uVar7;
  uint uVar8;
  uint16_t uVar9;
  uint uStack_4;
  
  uStack_4 = 0xffff;
  iVar1 = ovr_OVC23_55fe_3450(param_4);
  for (uVar8 = 0; uVar8 < EntityCount; uVar8 = uVar8 + 1) {
    if (*(char *)(Entities.ofs + uVar8 * 0x37 + 0x1a) == param_3) {
      iVar2 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + uVar8 * 0x37));
      uVar5 = iVar2 - iVar1 >> 0xf;
      uVar3 = *(int *)(Entities.ofs + uVar8 * 0x37 + 2) - param_5;
      uVar6 = (int)uVar3 >> 0xf;
      uVar3 = ((iVar2 - iVar1 ^ uVar5) - uVar5) + ((uVar3 ^ uVar6) - uVar6) * 2;
      if ((uVar3 != 0) && (uVar3 < uStack_4)) {
        iVar2 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + uVar8 * 0x37 + 8));
        uVar7 = Entities.ofs;
        uVar9 = Entities.seg;
        if (((iVar2 != iVar1) || (*(int *)(uVar7 + uVar8 * 0x37 + 10) != param_5)) &&
           ((((param_2 == 0 && ((*(byte *)(uVar7 + uVar8 * 0x37 + 0x33) & 2) == 0)) ||
             ((param_2 == 1 &&
              (((*(int *)(uVar7 + uVar8 * 0x37 + 8) == 0 &&
                (*(int *)(uVar7 + uVar8 * 0x37 + 10) == 0)) &&
               ((*(byte *)(uVar7 + uVar8 * 0x37 + 0x33) & 2) == 0)))))) ||
            (((param_2 == 2 && ((*(byte *)(uVar7 + uVar8 * 0x37 + 0x33) & 1) != 0)) ||
             ((param_2 == 3 && ((*(byte *)(uVar7 + uVar8 * 0x37 + 0x33) & 4) != 0)))))))) {
          *param_1 = uVar8;
          uStack_4 = uVar3;
        }
      }
    }
  }
  if (uStack_4 == 0xffff) {
    pcVar4 = (char *)"arena" + 4;
  }
  else {
    pcVar4 = (char *)"arena" + 5;
  }
  return pcVar4;
}



/* 3f0b:1bfc */

char * __cdecl16far attact_3f0b_1bfc(uint *param_1,char param_2,undefined2 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uStack_4;
  
  uStack_4 = 0;
  iVar1 = ovr_OVC23_55fe_3450(param_3);
  for (uVar7 = 0; uVar7 < EntityCount; uVar7 = uVar7 + 1) {
    if (*(char *)(Entities.ofs + uVar7 * 0x37 + 0x1a) == param_2) {
      iVar2 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + uVar7 * 0x37));
      uVar5 = iVar2 - iVar1 >> 0xf;
      uVar3 = *(int *)(Entities.ofs + uVar7 * 0x37 + 2) - param_4;
      uVar6 = (int)uVar3 >> 0xf;
      uVar3 = ((iVar2 - iVar1 ^ uVar5) - uVar5) + ((uVar3 ^ uVar6) - uVar6) * 2;
      if (((uStack_4 < uVar3) &&
          (iVar2 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + uVar7 * 0x37 + 8)),
          iVar2 == iVar1)) && (*(int *)(Entities.ofs + uVar7 * 0x37 + 10) == param_4)) {
        *param_1 = uVar7;
        uStack_4 = uVar3;
      }
    }
  }
  if (uStack_4 == 0) {
    pcVar4 = (char *)"arena" + 4;
  }
  else {
    pcVar4 = (char *)"arena" + 5;
  }
  return pcVar4;
}



/* 3f0b:1cfb */

char * __cdecl16far attact_3f0b_1cfb(uint *param_1,char param_2,undefined2 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uStack_4;
  
  uStack_4 = 0;
  iVar1 = ovr_OVC23_55fe_3450(param_3);
  for (uVar7 = 0; uVar7 < EntityCount; uVar7 = uVar7 + 1) {
    if (*(char *)(Entities.ofs + uVar7 * 0x37 + 0x1a) == param_2) {
      iVar2 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + uVar7 * 0x37));
      uVar5 = iVar2 - iVar1 >> 0xf;
      uVar3 = *(int *)(Entities.ofs + uVar7 * 0x37 + 2) - param_4;
      uVar6 = (int)uVar3 >> 0xf;
      uVar3 = ((iVar2 - iVar1 ^ uVar5) - uVar5) + ((uVar3 ^ uVar6) - uVar6) * 2;
      if (uStack_4 < uVar3) {
        *param_1 = uVar7;
        uStack_4 = uVar3;
      }
    }
  }
  if (uStack_4 == 0) {
    pcVar4 = (char *)"arena" + 4;
  }
  else {
    pcVar4 = (char *)"arena" + 5;
  }
  return pcVar4;
}



/* 3f0b:1db1 */

void __cdecl16far attact_3f0b_1db1(int *param_1)

{
  byte *pbVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  undefined2 uVar8;
  int iStack_8;
  uint uStack_6;
  byte bStack_3;
  
  iVar3 = ovr_OVC23_55fe_3450(*param_1);
  iStack_8 = *param_1;
  uVar8 = (undefined2)((ulong)param_1 >> 0x10);
  piVar5 = (int *)param_1;
  cVar2 = func_0x0004f29c((char *)"dwarf outpost" + 6,iStack_8,piVar5[1]);
  if (cVar2 == '\0') {
    uStack_6 = 0xfffe;
    while (((int)uStack_6 < 2 &&
           (cVar2 = func_0x0004f29c((char *)"dwarf outpost" + 6,iStack_8 + uStack_6,piVar5[1]),
           cVar2 == '\0'))) {
      uStack_6 = uStack_6 + 1;
    }
    if ((int)uStack_6 < 2) {
      iStack_8 = iStack_8 + uStack_6;
    }
  }
  for (uVar7 = 0; (int)uVar7 < 5; uVar7 = uVar7 + 1) {
    uVar6 = 0;
    for (uStack_6 = 0; uStack_6 < EntityCount; uStack_6 = uStack_6 + 1) {
      bStack_3 = *(byte *)(Entities.ofs + uStack_6 * 0x37 + 0x1a);
      if ((((bStack_3 != 0xff) &&
           (*(byte *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x89) == uVar7)) &&
          (iVar4 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + uStack_6 * 0x37 + 8)),
          iVar4 == iVar3)) && (*(int *)(Entities.ofs + uStack_6 * 0x37 + 10) == piVar5[1])) {
        uVar6 = uVar6 + 1;
      }
    }
    bStack_3 = ((undefined1 *)&DAT_2000_d1de)[uVar7];
    if (*(byte *)((int)piVar5 + uVar7 + 0xe) != uVar6) {
      while (((int)uVar6 < (int)(uint)*(byte *)((int)piVar5 + uVar7 + 0xe) &&
             (cVar2 = attact_3f0b_1a2f(&uStack_6), cVar2 != '\0'))) {
        *(undefined1 *)(Entities.ofs + uStack_6 * 0x37 + 0x30) = 0;
        *(int *)(Entities.ofs + uStack_6 * 0x37 + 8) = iStack_8;
        *(int *)(Entities.ofs + uStack_6 * 0x37 + 10) = piVar5[1];
        pbVar1 = (byte *)(Entities.ofs + uStack_6 * 0x37 + 0x33);
        *pbVar1 = *pbVar1 & 0xfb;
        uVar6 = uVar6 + 1;
      }
      while (((int)uVar6 < (int)(uint)*(byte *)((int)piVar5 + uVar7 + 0xe) &&
             (cVar2 = attact_3f0b_1a2f(&uStack_6), cVar2 != '\0'))) {
        *(undefined1 *)(Entities.ofs + uStack_6 * 0x37 + 0x30) = 0;
        *(int *)(Entities.ofs + uStack_6 * 0x37 + 8) = iStack_8;
        *(int *)(Entities.ofs + uStack_6 * 0x37 + 10) = piVar5[1];
        uVar6 = uVar6 + 1;
      }
      while (((int)uVar6 < (int)(uint)*(byte *)((int)piVar5 + uVar7 + 0xe) &&
             (cVar2 = attact_3f0b_1a2f(&uStack_6), cVar2 != '\0'))) {
        *(undefined1 *)(Entities.ofs + uStack_6 * 0x37 + 0x30) = 0;
        *(int *)(Entities.ofs + uStack_6 * 0x37 + 8) = iStack_8;
        *(int *)(Entities.ofs + uStack_6 * 0x37 + 10) = piVar5[1];
        uVar6 = uVar6 + 1;
      }
      while (((int)uVar6 < (int)(uint)*(byte *)((int)piVar5 + uVar7 + 0xe) &&
             (cVar2 = attact_3f0b_1a2f(&uStack_6), cVar2 != '\0'))) {
        *(undefined1 *)(Entities.ofs + uStack_6 * 0x37 + 0x30) = 0;
        *(int *)(Entities.ofs + uStack_6 * 0x37 + 8) = iStack_8;
        *(int *)(Entities.ofs + uStack_6 * 0x37 + 10) = piVar5[1];
        uVar6 = uVar6 + 1;
      }
      while (((int)(uint)*(byte *)((int)piVar5 + uVar7 + 0xe) < (int)uVar6 &&
             (cVar2 = attact_3f0b_1bfc(&uStack_6), cVar2 != '\0'))) {
        *(undefined1 *)(Entities.ofs + uStack_6 * 0x37 + 0x30) = 0;
        *(undefined2 *)(Entities.ofs + uStack_6 * 0x37 + 8) =
             *(undefined2 *)(Entities.ofs + uStack_6 * 0x37 + 4);
        *(undefined2 *)(Entities.ofs + uStack_6 * 0x37 + 10) =
             *(undefined2 *)(Entities.ofs + uStack_6 * 0x37 + 6);
        uVar6 = uVar6 - 1;
      }
    }
  }
  return;
}



/* 3f0b:21ef */

undefined2 __cdecl16far attact_3f0b_21ef(byte param_1)

{
  uint uVar1;
  long lVar2;
  ulong b;
  uint uStack_4;
  
  DAT_2000_d114 = func_0x0004f501((char *)"build\\elfres02.lbm" + 0xc);
  if (DAT_2000_d114 == 0) {
    uStack_4 = 0;
  }
  else {
    b = (ulong)DAT_2000_d114;
    lVar2 = LXMUL_at_(0x50,(ulong)*(byte *)(param_1 + 0x9082));
    lVar2 = LDIV_at_(lVar2,b);
    uStack_4 = (uint)lVar2;
  }
  uVar1 = uStack_4;
  if (0x50 < uStack_4) {
    uStack_4 = 0x50;
  }
  return CONCAT11((char)(uVar1 >> 8),(undefined1)uStack_4);
}



/* 3f0b:2252 */

void __cdecl16far attact_3f0b_2252(byte param_1,byte *param_2,char *param_3,char *param_4)

{
  int iVar1;
  
  *param_2 = (byte)(((0x1c - (char)((undefined *)&DAT_2000_d17d)[param_1]) * 100) / 0x1c);
  iVar1 = (int)(char)((undefined *)&DAT_2000_d17d)[param_1] << 1;
  if (iVar1 == 0) {
    *param_4 = '\0';
    *param_3 = '\0';
  }
  else {
    *param_4 = (char)((int)((100 - (uint)*param_2) *
                           ((int)(char)((undefined *)&DAT_2000_d178)[param_1] + iVar1 / 2 + -0x1c))
                     / iVar1);
    *param_3 = ('d' - *param_2) - *param_4;
  }
  return;
}



/* 3f0b:2303 */

void __cdecl16far
attact_3f0b_2303(undefined4 param_1,byte param_2,byte *param_3,char *param_4,char *param_5)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  *param_3 = (byte)(((0x1c - *(char *)(iVar2 + (uint)param_2 + 9)) * 100) / 0x1c);
  iVar1 = (int)*(char *)(iVar2 + (uint)param_2 + 9) << 1;
  if (iVar1 == 0) {
    *param_5 = '\0';
    *param_4 = '\0';
  }
  else {
    *param_5 = (char)((int)((100 - (uint)*param_3) *
                           ((int)*(char *)(iVar2 + (uint)param_2 + 4) + iVar1 / 2 + -0x1c)) / iVar1)
    ;
    *param_4 = ('d' - *param_3) - *param_5;
  }
  return;
}



/* 3f0b:23ab */

undefined2 __cdecl16far
attact_3f0b_23ab(int *param_1,undefined2 param_2,byte param_3,undefined1 param_4)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  
  pcVar6 = (char *)"build\\elfres02.lbm" + 0xc;
  if ((param_3 & 1) == 0) {
    uVar2 = func_0x0004f32d((char *)"build\\elfres02.lbm" + 0xc,*param_1,param_2,param_3,param_4);
  }
  else {
    iVar5 = *param_1;
    do {
      cVar1 = func_0x0004f32d(pcVar6,*param_1,param_2,param_3,param_4);
      if (cVar1 != '\0') {
        return 1;
      }
      iVar5 = iVar5 + *(char *)(param_3 + 0x885);
      iVar3 = ovr_OVC23_55fe_3450(*param_1);
      pcVar6 = (char *)"dwarf outpost" + 6;
      iVar4 = ovr_OVC23_55fe_3450(iVar5);
    } while (iVar3 == iVar4);
    *param_1 = iVar5;
    uVar2 = 0;
  }
  return uVar2;
}



/* 3f0b:2430 */

void __cdecl16far attact_3f0b_2430(int *param_1,byte param_2)

{
  char cVar1;
  uint16_t uVar2;
  int iVar3;
  int *piVar4;
  undefined2 uVar5;
  undefined1 uVar6;
  int local_8;
  int iStack_6;
  int iStack_4;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  piVar4 = (int *)param_1;
  uVar6 = *(undefined1 *)
           ((int)(char **)GMenuStrings + (uint)*(byte *)((int)piVar4 + 0xd) * 0x95 + 0x1f);
  if (param_2 == 0xff) {
    uVar2 = ovr_randBelow(4);
    param_2 = (byte)uVar2;
    do {
      local_8 = *param_1;
      cVar1 = attact_3f0b_23ab(&local_8);
      if (cVar1 == '\0') goto LAB_3f0b_24bf;
      param_2 = param_2 + 1 & 3;
    } while (param_2 != (byte)uVar2);
  }
  else {
    local_8 = *param_1;
    param_2 = param_2 ^ 2;
LAB_3f0b_24bf:
    iStack_4 = *param_1;
    iStack_6 = piVar4[1];
    piVar4[1] = piVar4[1] + (int)*(char *)(param_2 + 0x889);
    iVar3 = ovr_OVC23_55fe_2e2b(local_8 + *(char *)(param_2 + 0x885),piVar4[1],uVar6);
    *param_1 = iVar3;
    func_0x0004fcda((char *)"thief outpost" + 10);
    DAT_2000_d0fd = 1;
  }
  return;
}



/* 3f0b:251d */

void __cdecl16far attact_3f0b_251d(void)

{
  bool bVar1;
  
  GWantsExit2 = 1;
  DAT_2000_d167 = DAT_2000_d167 + 1;
  GGameState = 3;
  if (DebugVerbose) {
    printf("%d \r",3);
  }
  DAT_2410_0161 = 0;
  attact_3f0b_1082();
  if (DAT_2000_ca90 == '\0') {
    DAT_2000_d16f = DAT_2000_d16f + 1;
    if (9 < DAT_2000_d16f) {
      DAT_2000_d16f = 0;
      GGameState = 7;
      if (DebugVerbose != false) {
        printf("%d \r",7);
      }
      ovr_OVC25_5b66_085d();
    }
    DAT_2000_d16e = DAT_2000_d16e + 1;
    if (0xe < DAT_2000_d16e) {
      DAT_2000_d16e = 0;
      GGameState = 5;
      if (DebugVerbose != false) {
        printf("%d \r",5);
      }
      ovr_OVC22_5087_4dd9();
      ovr_season_67e7_042b();
      ovr_unit_6616_00d8();
      ovr_updSeason();
    }
    if (GTimeHi != '\0') {
      ovr_updSeason();
    }
    DAT_2000_d16d = DAT_2000_d16d + 1;
    if (4 < DAT_2000_d16d) {
      DAT_2000_d16d = 0;
      GGameState = 0x20;
      if (DebugVerbose != false) {
        printf("%d \r",0x20);
      }
      ovr_upd_units_5087_1d7d();
      GGameState = 0x3c;
      if (DebugVerbose != false) {
        printf("%d \r",0x3c);
      }
    }
    bVar1 = 0xfffe < DAT_2000_d169;
    DAT_2000_d169 = DAT_2000_d169 + 1;
    DAT_2000_d16b = DAT_2000_d16b + (uint)bVar1;
    (*(uint16_t *)((uint8_t *)&(GDailyTimeCounter) + 2)) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs + 2);
    (*(uint16_t *)((uint8_t *)&(GDailyTimeCounter))) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
  }
  return;
}



/* 3f0b:26bd */

void __cdecl16far attact_3f0b_26bd(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined1 uStack_3;
  
  uVar3 = 0;
  do {
    if (EntityCount <= uVar3) {
      return;
    }
    cVar1 = ovr_OVC23_55fe_05db(*(undefined2 *)(Entities.ofs + uVar3 * 0x37),
                                *(undefined2 *)(Entities.ofs + uVar3 * 0x37 + 2));
    if (cVar1 != '\0') {
      for (iVar2 = manage_4d05_28f4(uVar3); iVar2 != 0; iVar2 = iVar2 + -1) {
        if ((*(byte *)(Entities.ofs + uVar3 * 0x37 + 0xc) & 1) == 0) {
          uStack_3 = '\0';
        }
        else {
          uStack_3 = *(char *)(Entities.ofs + uVar3 * 0x37 + 0xc) + -2;
        }
        cVar1 = ovr_OVC15_4207_2301(uVar3,uStack_3,0);
        if (cVar1 == '\0') break;
      }
    }
    uVar3 = uVar3 + 1;
  } while( true );
}



/* 3f0b:277b */

void __cdecl16far attact_3f0b_277b(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  uint16_t uVar5;
  uint uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  uint16_t uVar9;
  
  uVar7 = (undefined2)((ulong)param_2 >> 0x10);
  ((uint *)param_2)[1] = 0;
  *param_2 = 0;
  uVar8 = (undefined2)((ulong)param_1 >> 0x10);
  ((uint *)param_1)[1] = 0;
  *param_1 = 0;
  for (uVar6 = 0; uVar6 < EntityCount; uVar6 = uVar6 + 1) {
    cVar3 = ovr_OVC23_55fe_05db(*(undefined2 *)(Entities.ofs + uVar6 * 0x37),
                                *(undefined2 *)(Entities.ofs + uVar6 * 0x37 + 2));
    if (cVar3 != '\0') {
      uVar9 = Entities.seg;
      uVar5 = Entities.ofs;
      if (*(char *)((int)(char **)GMenuStrings +
                   (uint)*(byte *)(uVar5 + uVar6 * 0x37 + 0xd) * 0x95 + 0x1f) == '\0') {
        uVar4 = (uint)*(byte *)(uVar5 + uVar6 * 0x37 + 0xe) *
                (uint)*(byte *)(uVar5 + uVar6 * 0x37 + 0xf) *
                (uint)*(byte *)(uVar5 + uVar6 * 0x37 + 0xf);
        uVar2 = *param_1;
        *param_1 = *param_1 + uVar4;
        puVar1 = (uint *)param_1 + 1;
        *puVar1 = *puVar1 + ((int)uVar4 >> 0xf) + (uint)CARRY2(uVar2,uVar4);
      }
      else {
        uVar4 = (uint)*(byte *)(uVar5 + uVar6 * 0x37 + 0xe) *
                (uint)*(byte *)(uVar5 + uVar6 * 0x37 + 0xf) *
                (uint)*(byte *)(uVar5 + uVar6 * 0x37 + 0xf);
        uVar2 = *param_2;
        *param_2 = *param_2 + uVar4;
        puVar1 = (uint *)param_2 + 1;
        *puVar1 = *puVar1 + ((int)uVar4 >> 0xf) + (uint)CARRY2(uVar2,uVar4);
      }
    }
  }
  return;
}



/* 3f0b:28eb */

void __cdecl16far attact_3f0b_28eb(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  
  uVar5 = (undefined2)((ulong)param_2 >> 0x10);
  ((uint *)param_2)[1] = 0;
  *param_2 = 0;
  uVar6 = (undefined2)((ulong)param_1 >> 0x10);
  ((uint *)param_1)[1] = 0;
  *param_1 = 0;
  for (iVar4 = 0; iVar4 < (int)(uint)AgntCount; iVar4 = iVar4 + 1) {
    if ((*(uint *)(iVar4 * 0x34 + 0x2b) & 0xae4) == 0) {
      if (*(char *)(iVar4 * 0x34 + 0x2f) == '\0') {
        uVar3 = (uint)*(byte *)(iVar4 * 0x34 + 0x21);
        uVar2 = *param_1;
        *param_1 = *param_1 + uVar3;
        puVar1 = (uint *)param_1 + 1;
        *puVar1 = *puVar1 + (uint)CARRY2(uVar2,uVar3);
      }
      else {
        uVar3 = (uint)*(byte *)(iVar4 * 0x34 + 0x21);
        uVar2 = *param_2;
        *param_2 = *param_2 + uVar3;
        puVar1 = (uint *)param_2 + 1;
        *puVar1 = *puVar1 + (uint)CARRY2(uVar2,uVar3);
      }
    }
  }
  return;
}



/* 3f0b:2997 */

void __cdecl16far attact_3f0b_2997(void)

{
  int iVar1;
  uint uVar2;
  far_t gfx;
  
  DAT_2000_d116 = 1;
  uVar2 = GTimeLo;
  if (0xe < GTimeLo) {
    uVar2 = GTimeLo - 0xf;
  }
  if (0xe < uVar2) {
    uVar2 = 0xe;
  }
  iVar1 = (int)(((long)(int)uVar2 * 0xc & 0xffffU) / 0xf) * 4;
  gfx.seg = *(uint16_t *)((undefined *)&DAT_2000_d135 + iVar1);
  gfx.ofs = *(uint16_t *)((undefined *)&DAT_2000_d133 + iVar1);
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c510)));
  ovr_OVC13_3d16_0000();
  return;
}



/* 3f0b:2a09 */

void __cdecl16far attact_3f0b_2a09(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined2 unaff_SS;
  long lVar4;
  far_t gfx;
  far_t gfx_00;
  long lVar5;
  uint local_20;
  int iStack_1e;
  uint local_1c;
  int iStack_1a;
  char cStack_17;
  brect_t local_16;
  brect_t local_c;
  
  F_SCOPY((uint8_t *)&local_c,(uint8_t *)0x88d,10);
  F_SCOPY((uint8_t *)&local_16,(uint8_t *)0x897,10);
  if (GameRunning == false) {
    cStack_17 = MiceNeedsUpdate == '\0';
    cVar1 = ovr_draw_2e25_15d6();
    if (cVar1 == '\0') {
      if (cStack_17 != '\0') {
        ovr_miceRestoreArea((brect_t *)CONCAT22(unaff_SS,&local_16));
      }
      attact_3f0b_2997();
      if (cStack_17 != '\0') {
        ovr_miceBlitRect((brect_t *)CONCAT22(unaff_SS,&local_16));
      }
    }
    else {
      attact_3f0b_277b(&local_1c);
      if ((local_1c == 0 && iStack_1a == 0) || (local_20 == 0 && iStack_1e == 0)) {
        if (cStack_17 != '\0') {
          ovr_miceRestoreArea((brect_t *)CONCAT22(unaff_SS,&local_16));
        }
        attact_3f0b_2997();
        if (cStack_17 != '\0') {
          ovr_miceBlitRect((brect_t *)CONCAT22(unaff_SS,&local_16));
        }
      }
      else {
        if (DAT_2000_d116 != '\0') {
          if (cStack_17 != '\0') {
            ovr_miceRestoreArea((brect_t *)CONCAT22(unaff_SS,&local_16));
          }
          gfx.seg = DAT_2000_d119;
          gfx.ofs = DAT_2000_d117;
          ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c510)));
          gfx_00.seg = DAT_2000_caf3;
          gfx_00.ofs = DAT_2000_caf1;
          ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)(0xa000c51d)));
          if (cStack_17 != '\0') {
            ovr_miceBlitRect((brect_t *)CONCAT22(unaff_SS,&local_16));
          }
        }
        if (cStack_17 != '\0') {
          ovr_miceRestoreArea((brect_t *)CONCAT22(unaff_SS,&local_c));
        }
        DAT_2000_d116 = '\0';
        if ((local_1c == 0 && iStack_1a == 0) && (local_20 != 0 || iStack_1e != 0)) {
          uVar2 = 0;
        }
        else if ((local_1c == 0 && iStack_1a == 0) || (local_20 != 0 || iStack_1e != 0)) {
          lVar5 = CONCAT22(iStack_1e + iStack_1a + (uint)CARRY2(local_20,local_1c),
                           local_20 + local_1c);
          lVar4 = LXMUL_at_(0x24,CONCAT22(iStack_1a,local_1c));
          lVar4 = LDIV_at_(lVar4,lVar5);
          uVar2 = (int)lVar4 + 1;
        }
        else {
          uVar2 = 0x26;
        }
        if ((AgntFlag1 != false) &&
           ((attact_3f0b_28eb(&local_1c), local_1c != 0 || iStack_1a != 0 ||
            (local_20 != 0 || iStack_1e != 0)))) {
          if ((local_1c == 0 && iStack_1a == 0) && (local_20 != 0 || iStack_1e != 0)) {
            iVar3 = 0;
          }
          else if ((local_1c == 0 && iStack_1a == 0) || (local_20 != 0 || iStack_1e != 0)) {
            lVar5 = CONCAT22(iStack_1e + iStack_1a + (uint)CARRY2(local_20,local_1c),
                             local_20 + local_1c);
            lVar4 = LXMUL_at_(0x24,CONCAT22(iStack_1a,local_1c));
            lVar4 = LDIV_at_(lVar4,lVar5);
            iVar3 = (int)lVar4 + 1;
          }
          else {
            iVar3 = 0x26;
          }
          uVar2 = uVar2 + iVar3 >> 1;
        }
        if (0x9e < 0xc4 - uVar2) {
          ovr_driver_2d63_05e5(0xdf,0x9f,0xe2,0xc4 - uVar2,0x24);
        }
        if (uVar2 != 0) {
          ovr_driver_2d63_05e5(0xdf,0xc5 - uVar2,0xe2,0xc4,7);
        }
        if (cStack_17 != '\0') {
          ovr_miceBlitRect((brect_t *)CONCAT22(unaff_SS,&local_c));
        }
      }
    }
  }
  return;
}



/* 3f0b:2da0 */

/* WARNING: Control flow encountered bad instruction data */

void __cdecl16far switchD_4000_6835_caseD_0(void)

{
  byte in_CL;
  byte *unaff_DI;
  
  *unaff_DI = *unaff_DI & in_CL;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


