/*
 * ovc07.c - recovered from STRONG.EXE
 * memory block: OVC07
 * range: 32c9:0000 - 32c9:06ef
 * functions: 5
 */
#include "recovered.h"


/* 32c9:0000 */

void __cdecl16far OVC07_32c9_0000(undefined2 *param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  
  uVar1 = *param_1;
  *param_1 = *param_2;
  *param_2 = uVar1;
  return;
}



/* 32c9:0026 */

undefined2 __cdecl16far OVC07_32c9_0026(int param_1)

{
  undefined2 uVar1;
  
  if (param_1 < 0) {
    uVar1 = 0xffff;
  }
  else if (param_1 < 1) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* 32c9:0044 */

void __cdecl16far
OVC07_32c9_0044(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
               undefined2 param_7,int *param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  undefined2 uVar11;
  int iStack_1a;
  int iStack_18;
  int iStack_16;
  int iStack_12;
  int iStack_10;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  int iStack_4;
  
  iVar4 = param_4;
  iVar10 = param_1;
  iVar5 = *param_8;
  uVar11 = (undefined2)((ulong)param_8 >> 0x10);
  piVar8 = (int *)param_8;
  iVar1 = piVar8[1];
  iVar2 = piVar8[2];
  iVar3 = piVar8[3];
  if (((((((param_1 < iVar5) || (iVar2 < param_1)) || (param_2 < iVar1)) ||
        ((iVar3 < param_2 || (param_3 < iVar5)))) ||
       ((iVar2 < param_3 || ((param_4 < iVar1 || (iVar3 < param_4)))))) || (param_5 < iVar5)) ||
     (((iVar2 < param_5 || (param_6 < iVar1)) || (iVar3 < param_6)))) {
    if (param_4 < param_2) {
      param_4 = param_2;
      param_1 = param_3;
      param_3 = iVar10;
      param_2 = iVar4;
    }
    iVar4 = param_3;
    iVar10 = param_1;
    iVar9 = param_6;
    if (param_6 < param_2) {
      param_1 = param_5;
      param_5 = iVar10;
      iVar9 = param_2;
      param_2 = param_6;
    }
    iVar10 = iVar9;
    if (iVar9 < param_4) {
      param_3 = param_5;
      param_5 = iVar4;
      iVar10 = param_4;
      param_4 = iVar9;
    }
    if ((((param_2 <= iVar3) && (iVar1 <= iVar10)) &&
        ((iVar5 <= param_1 || ((iVar5 <= param_3 || (iVar5 <= param_5)))))) &&
       ((param_1 <= iVar2 || ((param_3 <= iVar2 || (param_5 <= iVar2)))))) {
      if (199 < param_2) {
        printf("y1 %d yn %d y3 %d yx %d ",param_2);
        ovr_biosReadKey();
      }
      iStack_8 = param_1;
      if (param_2 != iVar10) {
        iStack_16 = (param_5 - param_1) / (iVar10 - param_2);
        uVar6 = (param_5 - param_1) % (iVar10 - param_2);
        uVar7 = (int)uVar6 >> 0xf;
        iStack_18 = (uVar6 ^ uVar7) - uVar7;
        iStack_1a = OVC07_32c9_0026(param_5 - param_1);
        iStack_a = iVar10 - param_2 >> 1;
      }
      iStack_4 = param_1;
      iStack_6 = param_4 - param_2 >> 1;
      iVar5 = OVC07_32c9_0026(param_3 - param_1);
      iStack_c = param_2;
      if (param_2 == param_4) {
        iStack_10 = 0;
        iStack_12 = 0;
      }
      else {
        iStack_10 = (param_3 - param_1) / (param_4 - param_2);
        uVar6 = (param_3 - param_1) % (param_4 - param_2);
        uVar7 = (int)uVar6 >> 0xf;
        iStack_12 = (uVar6 ^ uVar7) - uVar7;
      }
      for (; iStack_c < param_4; iStack_c = iStack_c + 1) {
        if ((iVar1 <= iStack_c) && (iStack_c <= iVar3)) {
          ovr_driver_2d63_09c9(iStack_4,iStack_8,iStack_c,param_7,piVar8,uVar11);
        }
        iStack_4 = iStack_4 + iStack_10;
        iStack_6 = iStack_6 + iStack_12;
        if (param_4 - param_2 <= iStack_6) {
          iStack_4 = iStack_4 + iVar5;
          iStack_6 = iStack_6 - (param_4 - param_2);
        }
        iStack_8 = iStack_8 + iStack_16;
        iStack_a = iStack_a + iStack_18;
        if (iVar10 - param_2 <= iStack_a) {
          iStack_8 = iStack_8 + iStack_1a;
          iStack_a = iStack_a - (iVar10 - param_2);
        }
      }
      iStack_4 = param_3;
      iStack_6 = iVar10 - param_4 >> 1;
      iVar5 = OVC07_32c9_0026(param_5 - param_3);
      if (param_4 == iVar10) {
        iStack_10 = 0;
        iStack_12 = 0;
      }
      else {
        iStack_10 = (param_5 - param_3) / (iVar10 - param_4);
        uVar6 = (param_5 - param_3) % (iVar10 - param_4);
        uVar7 = (int)uVar6 >> 0xf;
        iStack_12 = (uVar6 ^ uVar7) - uVar7;
      }
      for (iStack_c = param_4; iStack_c <= iVar10; iStack_c = iStack_c + 1) {
        if ((iVar1 <= iStack_c) && (iStack_c <= iVar3)) {
          ovr_driver_2d63_09c9(iStack_4,iStack_8,iStack_c,param_7,piVar8,uVar11);
        }
        iStack_4 = iStack_4 + iStack_10;
        iStack_6 = iStack_6 + iStack_12;
        if (iVar10 - param_4 <= iStack_6) {
          iStack_4 = iStack_4 + iVar5;
          iStack_6 = iStack_6 - (iVar10 - param_4);
        }
        iStack_8 = iStack_8 + iStack_16;
        iStack_a = iStack_a + iStack_18;
        if (iVar10 - param_2 <= iStack_a) {
          iStack_8 = iStack_8 + iStack_1a;
          iStack_a = iStack_a - (iVar10 - param_2);
        }
      }
    }
  }
  else {
    ovr_driver_2d63_0846(param_1,param_2,param_3,param_4,param_5,param_6,param_7,piVar8[4]);
  }
  return;
}



/* 32c9:03c4 */

void __cdecl16far
OVC07_32c9_03c4(int param_1,int param_2,int param_3,int param_4,undefined2 param_5,int *param_6)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined2 uVar4;
  
  iVar2 = param_4;
  iVar1 = param_3;
  if (param_3 < param_1) {
    param_3 = param_1;
    param_1 = iVar1;
  }
  if (param_4 < param_2) {
    param_4 = param_2;
    param_2 = iVar2;
  }
  if (param_1 < *param_6) {
    param_1 = *param_6;
  }
  uVar4 = (undefined2)((ulong)param_6 >> 0x10);
  piVar3 = (int *)param_6;
  if (param_2 < piVar3[1]) {
    param_2 = piVar3[1];
  }
  if (piVar3[2] < param_3) {
    param_3 = piVar3[2];
  }
  if (piVar3[3] < param_4) {
    param_4 = piVar3[3];
  }
  if ((param_1 <= param_3) && (param_2 <= param_4)) {
    ovr_driver_2d63_05e5(param_1,param_2,param_3,param_4,param_5,piVar3[4]);
  }
  return;
}



/* 32c9:0466 */

void __cdecl16far
OVC07_32c9_0466(int param_1,int param_2,int param_3,int param_4,undefined1 param_5,int *param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  undefined2 uVar9;
  bool bVar10;
  long lVar11;
  long lVar12;
  byte bStack_10;
  byte bStack_f;
  byte bStack_e;
  
  iVar1 = *param_6;
  uVar9 = (undefined2)((ulong)param_6 >> 0x10);
  piVar7 = (int *)param_6;
  iVar2 = piVar7[1];
  iVar3 = piVar7[2];
  iVar4 = piVar7[3];
  bStack_f = param_1 < iVar1;
  if (iVar3 < param_1) {
    bStack_f = bStack_f + 4;
  }
  if (param_2 < iVar2) {
    bStack_f = bStack_f + 2;
  }
  if (iVar4 < param_2) {
    bStack_f = bStack_f + 8;
  }
  bStack_10 = param_3 < iVar1;
  if (iVar3 < param_3) {
    bStack_10 = bStack_10 + 4;
  }
  if (param_4 < iVar2) {
    bStack_10 = bStack_10 + 2;
  }
  if (iVar4 < param_4) {
    bStack_10 = bStack_10 + 8;
  }
  bVar10 = bStack_f != 0 || bStack_10 != 0;
  bStack_e = bStack_f & bStack_10;
  while ((bStack_e == 0 && (bVar10))) {
    iVar6 = param_1;
    iVar8 = param_2;
    if (bStack_f == 0) {
      bVar5 = bStack_f;
      bStack_f = bStack_10;
      iVar6 = param_3;
      iVar8 = param_4;
      param_3 = param_1;
      param_4 = param_2;
      bStack_10 = bVar5;
    }
    param_1 = iVar6;
    if ((bStack_f & 1) == 0) {
      if ((bStack_f & 2) == 0) {
        if ((bStack_f & 4) == 0) {
          param_2 = iVar8;
          if ((bStack_f & 8) != 0) {
            lVar12 = (long)(param_4 - iVar8);
            lVar11 = LXMUL_at_((long)(iVar4 - iVar8),(long)(param_3 - param_1));
            lVar11 = LDIV_at_(lVar11,lVar12);
            param_1 = param_1 + (int)lVar11;
            param_2 = iVar4;
          }
        }
        else {
          lVar12 = (long)(param_3 - param_1);
          lVar11 = LXMUL_at_((long)(iVar3 - param_1),(long)(param_4 - iVar8));
          lVar11 = LDIV_at_(lVar11,lVar12);
          param_1 = iVar3;
          param_2 = iVar8 + (int)lVar11;
        }
      }
      else {
        lVar12 = (long)(param_4 - iVar8);
        lVar11 = LXMUL_at_((long)(iVar2 - iVar8),(long)(param_3 - param_1));
        lVar11 = LDIV_at_(lVar11,lVar12);
        param_1 = param_1 + (int)lVar11;
        param_2 = iVar2;
      }
    }
    else {
      lVar12 = (long)(param_3 - param_1);
      lVar11 = LXMUL_at_((long)(iVar1 - param_1),(long)(param_4 - iVar8));
      lVar11 = LDIV_at_(lVar11,lVar12);
      param_1 = iVar1;
      param_2 = iVar8 + (int)lVar11;
    }
    bStack_f = param_1 < iVar1;
    if (iVar3 < param_1) {
      bStack_f = bStack_f + 4;
    }
    if (param_2 < iVar2) {
      bStack_f = bStack_f + 2;
    }
    if (iVar4 < param_2) {
      bStack_f = bStack_f + 8;
    }
    bVar10 = bStack_f != 0 || bStack_10 != 0;
    bStack_e = bStack_f & bStack_10;
  }
  if (!bVar10) {
    ovr_vga_2d63_04b7(param_1,param_2,param_3,param_4,param_5,piVar7[4]);
  }
  return;
}


