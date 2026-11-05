/*
 * ovc27.c - recovered from STRONG.EXE
 * memory block: OVC27
 * range: 5ded:0000 - 5ded:22af
 * functions: 22
 */
#include "recovered.h"


/* 5ded:0000 */

void __cdecl16far
OVC27_5ded_0000(int param_1,int param_2,int param_3,int param_4,int *param_5,byte param_6)

{
  undefined1 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined2 uVar7;
  undefined2 unaff_SS;
  int local_30 [16];
  int iStack_10;
  int iStack_e;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  byte bStack_3;
  
  iVar5 = param_4;
  iVar4 = param_3;
  F_SCOPY((uint8_t *)local_30,(uint8_t *)((char *)"Intelligence reports %s attacking." + 0x24),0x20)
  ;
  if (param_3 < param_1) {
    param_3 = param_1;
    param_1 = iVar4;
    iStack_6 = param_4;
    param_4 = param_2;
    param_2 = iVar5;
  }
  if (param_1 < *param_5) {
    param_1 = *param_5;
  }
  uVar7 = (undefined2)((ulong)param_5 >> 0x10);
  piVar6 = (int *)param_5;
  if (piVar6[2] < param_3) {
    param_3 = piVar6[2];
  }
  if (param_1 <= param_3) {
    if (param_1 == param_3) {
      iStack_a = 0;
      iStack_c = 0;
    }
    else {
      iStack_a = (param_4 - param_2) / (param_3 - param_1);
      uVar2 = (param_4 - param_2) % (param_3 - param_1);
      uVar3 = (int)uVar2 >> 0xf;
      iStack_c = (uVar2 ^ uVar3) - uVar3;
    }
    iStack_e = ovr_OVC07_32c9_0026(param_4 - param_2);
    iStack_10 = param_3 - param_1 >> 1;
    bStack_3 = 0;
    for (iStack_8 = param_1; iStack_8 <= param_3; iStack_8 = iStack_8 + 1) {
      iVar4 = param_2 + local_30[(uint)bStack_3 + (uint)param_6 & 0xf];
      iVar5 = iVar4 + -1;
      bStack_3 = bStack_3 + 1;
      puVar1 = (undefined1 *)(iVar5 * 0x140 + iStack_8);
      if ((piVar6[1] <= iVar5) && (iVar5 <= piVar6[3])) {
        *puVar1 = 0xc;
      }
      if ((piVar6[1] <= iVar4) && (iVar4 <= piVar6[3])) {
        puVar1[0x140] = 0xf;
      }
      if ((piVar6[1] <= iVar4 + 1) && (iVar4 + 1 <= piVar6[3])) {
        puVar1[0x280] = 0xc;
      }
      param_2 = param_2 + iStack_a;
      iStack_10 = iStack_10 + iStack_c;
      if (param_3 - param_1 <= iStack_10) {
        param_2 = param_2 + iStack_e;
        iStack_10 = iStack_10 - (param_3 - param_1);
      }
    }
  }
  return;
}



/* 5ded:01ac */

void __cdecl16far
OVC27_5ded_01ac(int param_1,int param_2,int param_3,int param_4,int *param_5,byte param_6)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  uint16_t uVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  undefined2 uVar8;
  undefined2 unaff_SS;
  int local_70 [16];
  int local_50 [16];
  int local_30 [16];
  int iStack_10;
  int iStack_e;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  byte bStack_3;
  
  iVar1 = param_4;
  iVar2 = param_3;
  F_SCOPY((uint8_t *)local_30,(uint8_t *)0x594a,0x20);
  F_SCOPY((uint8_t *)local_50,(uint8_t *)0x596a,0x20);
  F_SCOPY((uint8_t *)local_70,(uint8_t *)0x598a,0x20);
  if (param_3 < param_1) {
    param_3 = param_1;
    param_1 = iVar2;
    iStack_6 = param_4;
    param_4 = param_2;
    param_2 = iVar1;
  }
  if (param_1 < *param_5) {
    param_1 = *param_5;
  }
  uVar8 = (undefined2)((ulong)param_5 >> 0x10);
  piVar7 = (int *)param_5;
  if (piVar7[2] < param_3) {
    param_3 = piVar7[2];
  }
  if (param_1 <= param_3) {
    if (param_1 == param_3) {
      iStack_a = 0;
      iStack_c = 0;
    }
    else {
      iStack_a = (param_4 - param_2) / (param_3 - param_1);
      uVar5 = (param_4 - param_2) % (param_3 - param_1);
      uVar6 = (int)uVar5 >> 0xf;
      iStack_c = (uVar5 ^ uVar6) - uVar6;
    }
    iStack_e = ovr_OVC07_32c9_0026(param_4 - param_2);
    iStack_10 = param_3 - param_1 >> 1;
    bStack_3 = param_6;
    for (iStack_8 = param_1; iStack_8 <= param_3; iStack_8 = iStack_8 + 1) {
      bStack_3 = bStack_3 + 1 & 0xf;
      iVar2 = param_2 + -1;
      puVar3 = (undefined1 *)(iVar2 * 0x140 + iStack_8);
      if ((((piVar7[1] <= iVar2) && (iVar2 <= piVar7[3])) && (local_30[bStack_3] != 0)) &&
         (uVar4 = ovr_randBelow(3), (uVar4 & 0xff) == 0)) {
        *puVar3 = (char)local_30[bStack_3];
      }
      if (((piVar7[1] <= param_2) && (param_2 <= piVar7[3])) &&
         ((local_50[bStack_3] != 0 && (uVar4 = ovr_randBelow(3), (uVar4 & 0xff) == 0)))) {
        puVar3[0x140] = (char)local_50[bStack_3];
      }
      if (((piVar7[1] <= param_2 + 1) && (param_2 + 1 <= piVar7[3])) &&
         ((local_70[bStack_3] != 0 && (uVar4 = ovr_randBelow(3), (uVar4 & 0xff) == 0)))) {
        puVar3[0x280] = (char)local_70[bStack_3];
      }
      param_2 = param_2 + iStack_a;
      iStack_10 = iStack_10 + iStack_c;
      if (param_3 - param_1 <= iStack_10) {
        param_2 = param_2 + iStack_e;
        iStack_10 = iStack_10 - (param_3 - param_1);
      }
    }
  }
  return;
}



/* 5ded:0404 */

uint __cdecl16far OVC27_5ded_0404(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  uint in_AX;
  byte bVar3;
  undefined1 uVar4;
  uint uVar2;
  int iVar5;
  undefined2 uVar6;
  
  uVar6 = (undefined2)((ulong)param_1 >> 0x10);
  iVar5 = (int)param_1;
  if ((*(uint *)((int)*(undefined4 *)(iVar5 + 0x1d) + 0x3c) & 2) != 0) {
    uVar1 = *(undefined4 *)(param_2 * 0x34 + 0x1d);
    bVar3 = (byte)((uint)(param_2 * 0x34) >> 8);
    if (((*(uint *)((int)uVar1 + 0x3e) & 0x10) != 0) &&
       (*(byte *)((int)*(undefined4 *)(iVar5 + 0x17) + 0xf) < 3)) {
      return (uint)bVar3 << 8;
    }
    return CONCAT11(bVar3,1);
  }
  if ((*(uint *)((int)*(undefined4 *)(iVar5 + 0x1d) + 0x3c) & 1) != 0) {
    in_AX = param_2 * 0x34;
    uVar4 = (undefined1)(in_AX >> 8);
    if (((*(uint *)((int)*(undefined4 *)(in_AX + 0x1d) + 0x3c) & 4) != 0) &&
       (3 < *(byte *)((int)*(undefined4 *)(iVar5 + 0x17) + 0xf))) {
      return CONCAT11(uVar4,1);
    }
    if (9 < *(byte *)((int)*(undefined4 *)(iVar5 + 0x17) + 0xf)) {
      return CONCAT11(uVar4,1);
    }
  }
  if (((*(uint *)((int)*(undefined4 *)(iVar5 + 0x1d) + 0x3c) & 0x800) == 0) ||
     (in_AX = param_2 * 0x34, (*(uint *)((int)*(undefined4 *)(in_AX + 0x1d) + 0x3c) & 4) == 0)) {
    uVar2 = in_AX & 0xff00;
  }
  else {
    uVar2 = CONCAT11((char)(in_AX >> 8),1);
  }
  return uVar2;
}



/* 5ded:04cd */

int __cdecl16far OVC27_5ded_04cd(undefined4 param_1,byte param_2)

{
  undefined4 uVar1;
  uint16_t uVar2;
  uint uVar3;
  byte bVar5;
  int iVar4;
  undefined1 uStack_4;
  
  uVar1 = *(undefined4 *)((int)param_1 + 0x17);
  bVar5 = *(byte *)((int)uVar1 + 0x1a);
  if (bVar5 == 0xff) {
    uStack_4 = 6;
  }
  else {
    uVar1 = *(undefined4 *)((uint)bVar5 << 2);
    uStack_4 = *(byte *)((int)uVar1 + (uint)param_2 + 0x29);
  }
  uVar2 = ovr_randBelow(0x28);
  uVar3 = (uVar2 & 0xff) + 1;
  bVar5 = (byte)(uVar3 >> 8);
  if (uStack_4 < uVar3) {
    iVar4 = (uint)bVar5 << 8;
  }
  else {
    iVar4 = CONCAT11(bVar5,1);
  }
  return iVar4;
}



/* 5ded:052d */

undefined2 __cdecl16far OVC27_5ded_052d(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint16_t uVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 unaff_SS;
  byte local_1c [12];
  int iStack_10;
  undefined2 uStack_e;
  byte local_c [10];
  
  F_SCOPY(local_c,(uint8_t *)0x59aa,10);
  F_SCOPY(local_1c,(uint8_t *)0x59b4,0xb);
  param_3 = param_3 * 0x34;
  _iStack_10 = CONCAT22(0x1726,param_3);
  uVar4 = (undefined2)((ulong)param_2 >> 0x10);
  iVar2 = (int)param_2;
  iVar3 = (int)param_1;
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  if (*(char *)(iVar2 + 8) == '\0') {
    if ((*(uint *)((int)*(undefined4 *)(iVar3 + 0x1d) + 0x3c) & 2) == 0) {
      return 0;
    }
    if (*(byte *)((int)*(undefined4 *)(iVar3 + 0x17) + 0xf) < local_c[*(byte *)(iVar2 + 9)]) {
      return 0;
    }
  }
  else if (*(char *)(iVar2 + 8) == '\x01') {
    if ((*(uint *)((int)*(undefined4 *)(iVar3 + 0x1d) + 0x3c) & 1) == 0) {
      return 0;
    }
    if (*(byte *)((int)*(undefined4 *)(iVar3 + 0x17) + 0xf) < local_1c[*(byte *)(iVar2 + 9)]) {
      return 0;
    }
  }
  else if ((*(char *)(iVar2 + 8) == '\x02') &&
          ((*(uint *)((int)*(undefined4 *)(iVar3 + 0x1d) + 0x3c) & 0x800) == 0)) {
    return 0;
  }
  if ((*(uint *)((int)*(undefined4 *)(param_3 + 0x1d) + 0x3c) & *(uint *)(iVar2 + 0x15)) == 0) {
    if ((*(uint *)((int)*(undefined4 *)(param_3 + 0x1d) + 0x3e) & *(uint *)(iVar2 + 0x19)) == 0) {
      if ((*(uint *)((int)*(undefined4 *)(param_3 + 0x1d) + 0x40) & *(uint *)(iVar2 + 0x1d)) == 0) {
        if ((*(uint *)(param_3 + 0x2b) & *(uint *)(iVar2 + 0xf)) == 0) {
          if ((*(uint *)((int)*(undefined4 *)(param_3 + 0x17) + 0x14) &
              (uint)*(byte *)(iVar2 + 0x13)) == 0) {
            if ((*(int *)(iVar2 + 0x17) != 0) &&
               ((*(uint *)((int)*(undefined4 *)(param_3 + 0x1d) + 0x3c) & *(uint *)(iVar2 + 0x17))
                == 0)) {
              return 0;
            }
            if ((*(int *)(iVar2 + 0x1b) != 0) &&
               ((*(uint *)((int)*(undefined4 *)(param_3 + 0x1d) + 0x3e) & *(uint *)(iVar2 + 0x1b))
                == 0)) {
              return 0;
            }
            if ((*(int *)(iVar2 + 0x1f) != 0) &&
               ((*(uint *)((int)*(undefined4 *)(param_3 + 0x1d) + 0x40) & *(uint *)(iVar2 + 0x1f))
                == 0)) {
              return 0;
            }
            if ((*(int *)(iVar2 + 0x11) != 0) &&
               ((*(uint *)(param_3 + 0x2b) & *(uint *)(iVar2 + 0x11)) == 0)) {
              return 0;
            }
            if ((*(char *)(iVar2 + 0x14) == '\0') ||
               ((*(uint *)((int)*(undefined4 *)(param_3 + 0x17) + 0x14) &
                (uint)*(byte *)(iVar2 + 0x14)) != 0)) {
              if ((*(char *)(iVar2 + 0xc) == '\0') || (*(char *)(param_3 + 0x11) == '\0')) {
                if (*(byte *)((int)*(undefined4 *)(param_3 + 0x17) + 0xf) < *(byte *)(iVar2 + 0xe))
                {
                  if ((*(byte *)(iVar2 + 0xd) < 100) &&
                     (uVar1 = ovr_randBelow(100), *(byte *)(iVar2 + 0xd) <= (byte)uVar1)) {
                    return 0;
                  }
                  uVar4 = 1;
                }
                else {
                  uVar4 = 0;
                }
              }
              else {
                uVar4 = 0;
              }
            }
            else {
              uVar4 = 0;
            }
          }
          else {
            uVar4 = 0;
          }
        }
        else {
          uVar4 = 0;
        }
      }
      else {
        uVar4 = 0;
      }
    }
    else {
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}



/* 5ded:079d */

undefined2 __cdecl16far OVC27_5ded_079d(byte param_1,byte param_2)

{
  undefined2 uVar1;
  uint16_t uVar2;
  
  if (param_1 < param_2) {
    uVar1 = 0;
  }
  else if (param_1 == param_2) {
    uVar2 = ovr_randBelow(8);
    if ((uVar2 & 0xff) == 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* 5ded:07d0 */

uint __cdecl16far OVC27_5ded_07d0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  char cVar2;
  uint in_AX;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined1 uStack_3;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  if ((*(uint *)((int)*(undefined4 *)(iVar4 + 0x1d) + 0x3c) & 2) == 0) {
    if ((*(uint *)((int)*(undefined4 *)(iVar4 + 0x1d) + 0x3c) & 1) == 0) {
      if (((((*(uint *)((int)*(undefined4 *)(iVar4 + 0x1d) + 0x3c) & 0x800) != 0) &&
           (in_AX = OVC27_5ded_04cd(iVar4,uVar5,5), (char)in_AX != '\0')) &&
          (in_AX = param_2 * 0x34, (*(uint *)(in_AX + 0x2b) & 0x7e0) == 0)) &&
         ((in_AX = param_2 * 0x34,
          (*(uint *)((int)*(undefined4 *)(in_AX + 0x1d) + 0x40) & 0x80) == 0 &&
          (in_AX = param_2 * 0x34, (*(uint *)((int)*(undefined4 *)(in_AX + 0x1d) + 0x3c) & 4) != 0))
         )) {
        return CONCAT11((char)(in_AX >> 8),1);
      }
      uVar3 = in_AX & 0xff00;
    }
    else {
      cVar2 = OVC27_5ded_052d(iVar4,uVar5,0x108,(char *)"n/s gate" + 4,param_2);
      if (cVar2 == '\0') {
        uVar3 = OVC27_5ded_052d(iVar4,uVar5,0x14a,(char *)"n/s gate" + 4,param_2);
        if ((char)uVar3 == '\0') {
          return uVar3 & 0xff00;
        }
        uStack_3 = 10;
      }
      else {
        uStack_3 = 4;
      }
      cVar2 = OVC27_5ded_079d(*(undefined1 *)((int)*(undefined4 *)(iVar4 + 0x17) + 0xf),uStack_3);
      if (cVar2 == '\0') {
        uVar3 = 0;
      }
      else {
        cVar2 = OVC27_5ded_04cd(iVar4,uVar5,2);
        if (cVar2 == '\0') {
          uVar3 = 0;
        }
        else {
          uVar3 = 1;
        }
      }
    }
  }
  else {
    cVar2 = OVC27_5ded_079d(*(undefined1 *)((int)*(undefined4 *)(iVar4 + 0x17) + 0xf),1);
    if (cVar2 == '\0') {
      uVar3 = 0;
    }
    else {
      uVar1 = *(undefined4 *)(param_2 * 0x34 + 0x1d);
      if (((*(uint *)((int)uVar1 + 0x3e) & 0x10) == 0) ||
         (2 < *(byte *)((int)*(undefined4 *)(iVar4 + 0x17) + 0xf))) {
        cVar2 = OVC27_5ded_04cd(iVar4,uVar5,1);
        if (cVar2 == '\0') {
          uVar3 = 0;
        }
        else {
          uVar3 = 1;
        }
      }
      else {
        uVar3 = param_2 * 0x34 & 0xff00;
      }
    }
  }
  return uVar3;
}



/* 5ded:0960 */

uint __cdecl16far OVC27_5ded_0960(undefined4 param_1)

{
  char cVar1;
  uint in_AX;
  uint uVar2;
  uint16_t uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_SS;
  char local_14 [16];
  byte bStack_4;
  byte bStack_3;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  if (*(char *)(iVar4 + 0xc) == -1) {
    uVar2 = in_AX & 0xff00;
  }
  else {
    _fmemset((char *)CONCAT22(unaff_SS,local_14),0,0xf);
    bStack_3 = 0;
    for (bStack_4 = 0; bStack_4 < 0xf; bStack_4 = bStack_4 + 1) {
      cVar1 = OVC27_5ded_052d(iVar4,uVar5,(uint)bStack_4 * 0x21,(char *)"n/s gate" + 4,
                              *(undefined1 *)(iVar4 + 0xc));
      if (cVar1 != '\0') {
        local_14[bStack_3] = bStack_4 + 1;
        bStack_3 = bStack_3 + 1;
      }
    }
    if (bStack_3 == 0) {
      uVar2 = 0;
    }
    else {
      uVar3 = ovr_randBelow((uint)bStack_3);
      uVar2 = CONCAT11((char)((uint)(local_14 + (uVar3 & 0xff)) >> 8),local_14[uVar3 & 0xff]);
    }
  }
  return uVar2;
}



/* 5ded:0a05 */

undefined2 __cdecl16far OVC27_5ded_0a05(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  char cVar3;
  uint16_t uVar4;
  char *arg1;
  uint16_t uVar5;
  int iVar6;
  int *piVar7;
  undefined2 uVar8;
  char *msg;
  char local_aa [151];
  byte bStack_13;
  int iStack_12;
  undefined2 uStack_10;
  int iStack_e;
  int iStack_c;
  int iStack_a;
  undefined2 uStack_8;
  int iStack_6;
  undefined2 uStack_4;
  
  iStack_6 = param_1 * 0x34;
  uStack_4 = 0x1726;
  if ((*(uint *)((int)*(undefined4 *)(iStack_6 + 0x1d) + 0x3c) & 0x803) == 0) {
    return 0;
  }
  if (*(char *)(iStack_6 + 0xe) == -1) {
    iStack_a = (uint)*(byte *)(iStack_6 + 0xc) * 0x34;
    uStack_8 = 0x1726;
    uVar8 = uStack_8;
    uStack_8 = 0x1726;
    uVar2 = uVar8;
    if (((((*(uint *)((int)*(undefined4 *)(iStack_6 + 0x1d) + 0x3c) & 0x1000) != 0) &&
         (uVar2 = uStack_8, (*(uint *)((int)*(undefined4 *)(iStack_a + 0x1d) + 0x3e) & 0x10) == 0))
        && ((uStack_8 = uVar8, (*(uint *)((int)*(undefined4 *)(iStack_a + 0x1d) + 0x3e) & 8) == 0 ||
            (cVar3 = ovr_agnt_3b1d_0c9f(), uVar2 = uStack_8, '\0' < cVar3)))) &&
       (uVar4 = ovr_randBelow(2), uVar2 = uStack_8, (uVar4 & 0xff) == 0)) {
      return 0;
    }
    uStack_8 = uVar2;
    bStack_13 = OVC27_5ded_0960();
    if (bStack_13 == 0) {
      ovr_agnt_3b1d_0a53();
      uVar8 = 0;
    }
    else {
      uVar8 = (undefined2)((ulong)*(undefined4 *)(iStack_6 + 0x1d) >> 0x10);
      iVar6 = (int)*(undefined4 *)(iStack_6 + 0x1d);
      uVar4 = DAT_2000_d0f7;
      arg1 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)(iVar6 + 0x24),*(undefined2 *)(iVar6 + 0x26)
                                         ,*(undefined2 *)((uint)bStack_13 * 0x21 + -0x21),
                                         *(undefined2 *)((uint)bStack_13 * 0x21 + -0x1f),
                                         *(undefined2 *)((uint)bStack_13 * 0x21 + -0x1d),
                                         *(undefined2 *)((uint)bStack_13 * 0x21 + -0x1b),
                                         *(undefined2 *)
                                          ((int)*(undefined4 *)(iStack_a + 0x1d) + 0x24));
      msg = ovr_stsprintf(local_aa,"%s casts a %s spell %s %s.",arg1);
      ovr_uiNotify(msg,uVar4);
      *(byte *)(iStack_6 + 0x2e) = bStack_13;
      if (*(char *)((uint)bStack_13 * 0x21 + -0x17) == '9') {
        uVar4 = ovr_audio_3a5b_0afd();
        iVar6 = 0;
        uVar5 = ovr_randBelow(2);
        ovr_play_sfxU((char)uVar5 + 0x39,iVar6,uVar4);
      }
      else {
        uVar4 = ovr_audio_3a5b_0afd();
        ovr_play_sfxU(*(byte *)((uint)bStack_13 * 0x21 + -0x17),0,uVar4);
      }
      if (*(char *)((uint)bStack_13 * 0x21 + -0x16) == '\0') {
        *(undefined1 *)(iStack_6 + 0xe) = 0xf5;
        uVar8 = 1;
      }
      else {
        uVar8 = *(undefined2 *)(iStack_6 + 0x15);
        _iStack_12 = CONCAT22(uVar8,*(int *)(iStack_6 + 0x13));
        piVar7 = (int *)(*(int *)(iStack_6 + 0x13) + (uint)*(byte *)(iStack_6 + 0x12) * 4);
        iVar6 = piVar7[1];
        iVar1 = *piVar7;
        _iStack_e = CONCAT22(iVar6,iVar1);
        if (iVar1 == 0 && iVar6 == 0) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x42);
        }
        *(undefined1 *)(iStack_6 + 0xe) = 0;
        *(char *)(iStack_6 + 10) = *(char *)(iVar1 + 0x15) + *(char *)(iStack_6 + 0x28);
        if (*(char *)(iStack_6 + 0xf) == '\0') {
          *(int *)(iStack_6 + 8) = *(int *)(iVar1 + 0x13) + *(int *)(iStack_6 + 0x26);
        }
        else {
          *(int *)(iStack_6 + 8) = *(int *)(iStack_6 + 0x26) - *(int *)(iVar1 + 0x13);
        }
        *(undefined1 *)(iStack_6 + 0xb) = *(undefined1 *)(iStack_6 + 0xf);
        uVar8 = 1;
      }
    }
    return uVar8;
  }
  return 0;
}



/* 5ded:0cc2 */

void __cdecl16far OVC27_5ded_0cc2(int param_1,brect_t *param_2,undefined2 param_3)

{
  undefined2 uVar1;
  uint16_t uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint16_t uVar6;
  uint16_t *puVar7;
  far_t gfx;
  far_t gfx_00;
  int iStack_e;
  undefined2 uStack_c;
  
  param_1 = param_1 * 0x34;
  iVar3 = (uint)*(byte *)(param_1 + 0xc) * 0x34;
  if (((*(char *)(param_1 + 0x24) == '\0') && (*(char *)(param_1 + 0xc) != -1)) &&
     (*(char *)(param_1 + 0xe) != -1)) {
    uVar1 = *(undefined2 *)(param_1 + 0x15);
    iVar5 = *(int *)(param_1 + 0x13);
    if (*(char *)(param_1 + 0x11) == '\0') {
      uStack_c = *(undefined2 *)(iVar5 + 0xe);
      iStack_e = *(int *)(iVar5 + 0xc);
    }
    else {
      uStack_c = *(undefined2 *)(iVar5 + 0x12);
      iStack_e = *(int *)(iVar5 + 0x10);
    }
    if (*(char *)(param_1 + 0xf) == '\0') {
      uVar4 = *(int *)(param_1 + 0x26) + *(int *)(iStack_e + 0x13);
      if (*(uint *)(iVar3 + 0x26) <= uVar4) {
        *(undefined1 *)(param_1 + 0xe) = 0xff;
        *(undefined1 *)(param_1 + 0x2e) = 0;
        return;
      }
    }
    else {
      uVar4 = *(int *)(param_1 + 0x26) - *(int *)(iStack_e + 0x13);
      if (uVar4 <= *(uint *)(iVar3 + 0x26)) {
        *(undefined1 *)(param_1 + 0xe) = 0xff;
        *(undefined1 *)(param_1 + 0x2e) = 0;
        return;
      }
    }
    puVar7 = (uint16_t *)(*(int *)(iVar3 + 0x13) + (uint)*(byte *)(iVar3 + 0x12) * 4);
    uVar2 = puVar7[1];
    uVar6 = *puVar7;
    if ((*(int *)(iVar3 + 0x28) != 0) || (*(int *)(iVar3 + 0x26) != 0)) {
      if (*(char *)(param_1 + 0x2e) == '\x01') {
        if (*(byte *)(param_1 + 0xe) < 0xfc) {
          OVC27_5ded_0000();
        }
        uVar4 = *(byte *)(param_1 + 0xe) & 3;
        gfx.seg = ((undefined2 *)&DAT_2000_d2ee)[uVar4 * 2];
        gfx.ofs = ((undefined2 *)&DAT_2000_d2ec)[uVar4 * 2];
        ovr_blitGfxRect(gfx,*(int16_t *)(iVar3 + 0x26),
                        *(int *)(iVar3 + 0x28) - (*(int *)(uVar6 + 0xd) >> 1),
                        (brect_t *)CONCAT22(param_3,param_2),0x10,false);
      }
      else {
        if (uVar4 < *(uint *)(iVar3 + 0x26)) {
          *(undefined1 *)(param_1 + 0x32) = 0;
        }
        else {
          *(undefined1 *)(param_1 + 0x32) = 1;
        }
        if (*(byte *)(param_1 + 0xe) < 0xfb) {
          OVC27_5ded_01ac();
        }
        if (0xf8 < *(byte *)(param_1 + 0xe)) {
          iVar5 = ovr_stash_474a_10ac();
          gfx_00.seg = uVar6;
          gfx_00.ofs = iVar5 + 6;
          ovr_blitGfxRect(gfx_00,*(int16_t *)(iVar3 + 0x26),*(int16_t *)(iVar3 + 0x28),
                          (brect_t *)CONCAT22(param_3,param_2),0x10,*(bool *)(param_1 + 0x32));
        }
      }
      *(char *)(param_1 + 0xe) = *(char *)(param_1 + 0xe) + '\x01';
      *(undefined1 *)(param_1 + 0x10) = 2;
      if (*(char *)(param_1 + 0xe) == -1) {
        ovr_OVC41_6a8f_297d();
        *(undefined1 *)(param_1 + 0x2e) = 0;
        *(undefined1 *)(param_1 + 0x10) = 0;
      }
    }
  }
  else {
    *(undefined1 *)(param_1 + 0xe) = 0xff;
    *(undefined1 *)(param_1 + 0x2e) = 0;
  }
  return;
}



/* 5ded:0fd2 */

undefined2 __cdecl16far OVC27_5ded_0fd2(undefined4 param_1)

{
  char *arg1;
  int iVar1;
  undefined2 uVar2;
  char *msg;
  uint16_t dst;
  undefined1 local_ca [80];
  char local_7a [120];
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (((*(char *)((int)*(undefined4 *)(iVar1 + 0x1d) + 0x46) == '\x04') &&
      (0xf < *(byte *)((int)*(undefined4 *)(iVar1 + 0x17) + 0xf))) ||
     ((*(char *)((int)*(undefined4 *)(iVar1 + 0x1d) + 0x46) == '\x06' &&
      (8 < *(byte *)((int)*(undefined4 *)(iVar1 + 0x17) + 0xf))))) {
    dst = DAT_2000_d0f7;
    uVar2 = ovr_agnt_3b1d_0ac0(iVar1,uVar2,local_ca);
    arg1 = (char *)ovr_OVC15_4207_1c16(uVar2);
    msg = ovr_stsprintf(local_7a,"%s takes half damage from spells.",arg1);
    ovr_uiNotify(msg,dst);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 5ded:105e */

undefined2 __cdecl16far OVC27_5ded_105e(undefined4 param_1)

{
  char *arg1;
  int iVar1;
  undefined2 uVar2;
  char *msg;
  uint16_t dst;
  undefined1 local_ca [80];
  char local_7a [120];
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (((*(char *)((int)*(undefined4 *)(iVar1 + 0x1d) + 0x46) == '\x05') &&
      (0xd < *(byte *)((int)*(undefined4 *)(iVar1 + 0x17) + 0xf))) ||
     ((*(char *)((int)*(undefined4 *)(iVar1 + 0x1d) + 0x46) == '\x06' &&
      (0xe < *(byte *)((int)*(undefined4 *)(iVar1 + 0x17) + 0xf))))) {
    dst = DAT_2000_d0f7;
    uVar2 = ovr_agnt_3b1d_0ac0(iVar1,uVar2,local_ca);
    arg1 = (char *)ovr_OVC15_4207_1c16(uVar2);
    msg = ovr_stsprintf(local_7a,"%s takes half damage from dragon breath.",arg1);
    ovr_uiNotify(msg,dst);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 5ded:10ea */

void __cdecl16far OVC27_5ded_10ea(undefined4 param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  undefined2 uVar4;
  char *pcVar5;
  uint16_t uVar6;
  undefined2 uVar7;
  int iVar8;
  uint uVar9;
  undefined2 uVar10;
  char *pcVar11;
  undefined4 uVar12;
  undefined1 local_124 [80];
  undefined1 local_d4 [80];
  char local_84 [120];
  int iStack_c;
  undefined2 uStack_a;
  int iStack_8;
  
  uVar7 = (undefined2)((ulong)((long)param_2 * 0x34) >> 0x10);
  iStack_c = (int)((long)param_2 * 0x34);
  uStack_a = 0x1726;
  uVar10 = (undefined2)((ulong)param_1 >> 0x10);
  iVar8 = (int)param_1;
  if (*(char *)(iVar8 + 0x2e) == '\x01') {
    if ((*(uint *)((int)*(undefined4 *)(iVar8 + 0x1d) + 0x40) & 1) == 0) {
      bVar1 = ovr_manage_4d05_01a3();
      uVar9 = (uint)bVar1;
      cVar2 = OVC27_5ded_0fd2();
      if (cVar2 != '\0') {
        uVar9 = (int)uVar9 >> 1;
      }
    }
    else {
      uVar9 = (uint)*(byte *)(iVar8 + 0x21);
      cVar2 = OVC27_5ded_105e();
      if (cVar2 != '\0') {
        uVar9 = (int)uVar9 >> 1;
      }
    }
    if ((*(uint *)((int)*(undefined4 *)(iStack_c + 0x1d) + 0x40) & 1) == 0) {
      cVar2 = OVC27_5ded_1c94(iStack_c,uStack_a,3);
      if (cVar2 != '\0') {
        uVar9 = (int)uVar9 >> 1;
      }
      ovr_OVC41_6a8f_1c74(iVar8,uVar10,iStack_c,uStack_a,uVar9);
      *(undefined1 *)(iStack_c + 0x30) = 0xb;
      *(undefined1 *)(iStack_c + 0x31) = 0;
      OVC27_5ded_1be7();
      return;
    }
    uVar6 = DAT_2000_d0f7;
    uVar7 = ovr_agnt_3b1d_0ac0(iStack_c,uStack_a,local_d4);
    pcVar5 = (char *)ovr_OVC15_4207_1c16(uVar7);
    pcVar11 = ovr_stsprintf(local_84,"%s takes half damage from lightning.",pcVar5);
    ovr_uiNotify(pcVar11,uVar6);
    OVC27_5ded_1be7();
    return;
  }
  if (*(char *)(iVar8 + 0x2e) == '\x02') {
    iStack_8 = (*(byte *)((int)*(undefined4 *)(iVar8 + 0x17) + 0xf) / 5) * 2 + 1;
    bVar1 = ovr_manage_4d05_01a3();
    iVar3 = (uint)bVar1 + iStack_8;
    cVar2 = OVC27_5ded_0fd2();
    if (cVar2 != '\0') {
      iVar3 = iVar3 >> 1;
    }
    ovr_OVC41_6a8f_1c74(iVar8,uVar10,iStack_c,uStack_a,iVar3);
    *(undefined1 *)(iStack_c + 0x30) = 0xb;
    *(undefined1 *)(iStack_c + 0x31) = 0;
    OVC27_5ded_1be7();
    return;
  }
  if (*(char *)(iVar8 + 0x2e) == '\n') {
    if ((*(uint *)(iStack_c + 0x2b) & 0x420) != 0) {
      OVC27_5ded_1be7();
      return;
    }
    uVar6 = ovr_randBelow(3);
    if (((uVar6 & 0xff) == 0) && (cVar2 = OVC27_5ded_1c94(iStack_c,uStack_a,3), cVar2 == '\0')) {
      uVar6 = DAT_2000_d0f7;
      uVar4 = ovr_agnt_3b1d_0ac0(iVar8,uVar10,local_124);
      uVar12 = CONCAT22(uVar7,uVar4);
      uVar4 = ovr_agnt_3b1d_0ac0(iStack_c,uStack_a,local_d4);
      pcVar5 = (char *)ovr_OVC15_4207_1c16(uVar4,uVar7,uVar12);
      pcVar11 = ovr_stsprintf(local_84,"%s is charmed by %s.",pcVar5);
      ovr_uiNotify(pcVar11,uVar6);
      ovr_OVC41_6a8f_0229();
      *(undefined1 *)(iStack_c + 0x2f) = *(undefined1 *)(iVar8 + 0x2f);
      *(uint *)(iStack_c + 0x2b) = *(uint *)(iStack_c + 0x2b) | 0x20;
      uVar6 = ovr_audio_3a5b_0afd();
      ovr_play_sfxU(0x1b,0,uVar6);
      OVC27_5ded_1be7();
      return;
    }
    uVar6 = DAT_2000_d0f7;
    uVar4 = ovr_agnt_3b1d_0ac0(iStack_c,uStack_a,local_124);
    uVar12 = CONCAT22(uVar7,uVar4);
    uVar10 = ovr_agnt_3b1d_0ac0(iVar8,uVar10,local_d4);
    pcVar5 = (char *)ovr_OVC15_4207_1c16(uVar10,uVar7,uVar12);
    pcVar11 = ovr_stsprintf(local_84,"%s fails to charm %s.",pcVar5);
    ovr_uiNotify(pcVar11,uVar6);
    *(uint *)(iStack_c + 0x2b) = *(uint *)(iStack_c + 0x2b) | 0x400;
    OVC27_5ded_1be7();
    return;
  }
  if ((*(char *)(iVar8 + 0x2e) != '\x03') && (*(char *)(iVar8 + 0x2e) != '\x05')) {
    OVC27_5ded_14a8();
    return;
  }
  if ((*(uint *)(iStack_c + 0x2b) & 0x20) != 0) {
    OVC27_5ded_1be7();
    return;
  }
  cVar2 = OVC27_5ded_1c94(iStack_c,0x1726,3);
  if (cVar2 == '\0') {
    uVar6 = DAT_2000_d0f7;
    uVar4 = ovr_agnt_3b1d_0ac0(iVar8,uVar10,local_124);
    uVar12 = CONCAT22(uVar7,uVar4);
    uVar4 = ovr_agnt_3b1d_0ac0(iStack_c,uStack_a,local_d4);
    pcVar5 = (char *)ovr_OVC15_4207_1c16(uVar4,uVar7,uVar12);
    pcVar11 = ovr_stsprintf(local_84,"%s is charmed by %s.",pcVar5);
    ovr_uiNotify(pcVar11,uVar6);
    *(undefined1 *)(iStack_c + 0x2f) = *(undefined1 *)(iVar8 + 0x2f);
    ovr_OVC41_6a8f_0229();
    *(uint *)(iStack_c + 0x2b) = *(uint *)(iStack_c + 0x2b) | 0x20;
    uVar6 = ovr_audio_3a5b_0afd();
    ovr_play_sfxU(0x1b,0,uVar6);
    OVC27_5ded_1be7();
    return;
  }
  OVC27_5ded_1be7();
  return;
}



/* 5ded:1433 */

void __cdecl16far OVC27_5ded_1433(void)

{
  uint *puVar1;
  char *arg1;
  uint16_t unk;
  int unaff_BP;
  undefined2 unaff_SS;
  char *msg;
  uint16_t in_stack_0000000a;
  
  ovr_agnt_3b1d_0ac0(*(undefined2 *)(unaff_BP + -10));
  arg1 = (char *)ovr_OVC15_4207_1c16();
  msg = ovr_stsprintf((char *)(unaff_BP + -0x82),"%s is charmed by %s.",arg1);
  ovr_uiNotify(msg,in_stack_0000000a);
  *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2f) =
       *(undefined1 *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2f);
  ovr_OVC41_6a8f_0229();
  puVar1 = (uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b);
  *puVar1 = *puVar1 | 0x20;
  unk = ovr_audio_3a5b_0afd();
  ovr_play_sfxU(0x1b,0,unk);
  OVC27_5ded_1be7();
  return;
}



/* 5ded:14a8 */

void __cdecl16far OVC27_5ded_14a8(void)

{
  uint *puVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  uint16_t uVar5;
  char *pcVar6;
  undefined2 uVar7;
  undefined2 in_DX;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_SS;
  char *pcVar8;
  undefined4 uVar9;
  
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\x04') {
    uVar5 = ovr_audio_3a5b_0afd();
    ovr_play_sfxU(0x4c,0,uVar5);
    uVar9 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x1d);
    if ((*(uint *)((int)uVar9 + 0x40) & 0x20) == 0) {
      ovr_OVC28_6018_0000(6);
      bVar2 = ovr_manage_4d05_01a3();
      iVar4 = bVar2 + 1;
      cVar3 = OVC27_5ded_1c94(*(undefined2 *)(unaff_BP + -10),*(undefined2 *)(unaff_BP + -8),3);
      if (cVar3 != '\0') {
        iVar4 = iVar4 >> 1;
      }
      cVar3 = OVC27_5ded_0fd2();
      if (cVar3 != '\0') {
        iVar4 = iVar4 >> 1;
      }
      uVar9 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x1d);
      if ((*(uint *)((int)uVar9 + 0x3e) & 0x200) != 0) {
        uVar5 = DAT_2000_d0f7;
        uVar7 = ovr_agnt_3b1d_0ac0(*(undefined2 *)(unaff_BP + -10),*(undefined2 *)(unaff_BP + -8),
                                   unaff_BP + -0xd2);
        pcVar6 = (char *)ovr_OVC15_4207_1c16(uVar7);
        pcVar8 = ovr_stsprintf((char *)(unaff_BP + -0x82),"%s takes half damage from fire.",pcVar6);
        ovr_uiNotify(pcVar8,uVar5);
        iVar4 = iVar4 >> 1;
      }
      ovr_OVC41_6a8f_1c74(*(undefined2 *)(unaff_BP + 6),*(undefined2 *)(unaff_BP + 8),
                          *(undefined2 *)(unaff_BP + -10),*(undefined2 *)(unaff_BP + -8),iVar4);
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 10;
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 0;
      OVC27_5ded_1be7();
      return;
    }
    uVar5 = DAT_2000_d0f7;
    uVar7 = ovr_agnt_3b1d_0ac0(*(undefined2 *)(unaff_BP + -10),*(undefined2 *)(unaff_BP + -8),
                               unaff_BP + -0xd2);
    pcVar6 = (char *)ovr_OVC15_4207_1c16(uVar7);
    pcVar8 = ovr_stsprintf((char *)(unaff_BP + -0x82),"%s is immune to fire.",pcVar6);
    ovr_uiNotify(pcVar8,uVar5);
    OVC27_5ded_1be7();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\x06') {
    if (*(char *)((int)*(undefined4 *)(unaff_BP + -10) + 0x11) != '\0') {
      OVC27_5ded_1be7();
      return;
    }
    if ((*(uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b) & 0x40) == 0) {
      cVar3 = OVC27_5ded_1c94(*(undefined2 *)(unaff_BP + -10),*(undefined2 *)(unaff_BP + -8),3);
      if (cVar3 == '\0') {
        uVar5 = DAT_2000_d0f7;
        uVar7 = ovr_agnt_3b1d_0ac0(*(undefined2 *)(unaff_BP + 6),*(undefined2 *)(unaff_BP + 8),
                                   unaff_BP + -0x122);
        uVar9 = CONCAT22(in_DX,uVar7);
        uVar7 = ovr_agnt_3b1d_0ac0(*(undefined2 *)(unaff_BP + -10),*(undefined2 *)(unaff_BP + -8),
                                   unaff_BP + -0xd2);
        pcVar6 = (char *)ovr_OVC15_4207_1c16(uVar7,in_DX,uVar9);
        pcVar8 = ovr_stsprintf((char *)(unaff_BP + -0x82),"%s is held by %s.",pcVar6);
        ovr_uiNotify(pcVar8,uVar5);
        ovr_OVC41_6a8f_0229();
        puVar1 = (uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b);
        *puVar1 = *puVar1 | 0x40;
        *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 0x10;
        *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 0;
        uVar5 = ovr_audio_3a5b_0afd();
        ovr_play_sfxU(0x1b,0,uVar5);
        OVC27_5ded_1be7();
        return;
      }
      OVC27_5ded_1be7();
      return;
    }
    OVC27_5ded_1be7();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\a') {
    if (*(char *)((int)*(undefined4 *)(unaff_BP + -10) + 0x11) != '\0') {
      OVC27_5ded_1be7();
      return;
    }
    if ((*(uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b) & 0x80) == 0) {
      uVar9 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x17);
      if (*(byte *)((int)uVar9 + 0xf) < 5) {
        uVar5 = DAT_2000_d0f7;
        uVar7 = ovr_agnt_3b1d_0ac0(*(undefined2 *)(unaff_BP + 6),*(undefined2 *)(unaff_BP + 8),
                                   unaff_BP + -0x122);
        uVar9 = CONCAT22(in_DX,uVar7);
        uVar7 = ovr_agnt_3b1d_0ac0(*(undefined2 *)(unaff_BP + -10),*(undefined2 *)(unaff_BP + -8),
                                   unaff_BP + -0xd2);
        pcVar6 = (char *)ovr_OVC15_4207_1c16(uVar7,in_DX,uVar9);
        pcVar8 = ovr_stsprintf((char *)(unaff_BP + -0x82),"%s is put to sleep by %s.",pcVar6);
        ovr_uiNotify(pcVar8,uVar5);
        ovr_OVC41_6a8f_0229();
        puVar1 = (uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b);
        *puVar1 = *puVar1 | 0x80;
        uVar5 = ovr_audio_3a5b_0afd();
        ovr_play_sfxU(0x1b,0,uVar5);
        *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 0xc;
        *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 0;
        OVC27_5ded_1be7();
        return;
      }
      OVC27_5ded_1be7();
      return;
    }
    OVC27_5ded_1be7();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\b') {
    if (*(char *)((int)*(undefined4 *)(unaff_BP + -10) + 0x11) != '\0') {
      OVC27_5ded_1be7();
      return;
    }
    if ((*(uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b) & 0x100) == 0) {
      uVar5 = DAT_2000_d0f7;
      uVar7 = ovr_agnt_3b1d_0ac0(*(undefined2 *)(unaff_BP + 6),*(undefined2 *)(unaff_BP + 8),
                                 unaff_BP + -0x122);
      uVar9 = CONCAT22(in_DX,uVar7);
      uVar7 = ovr_agnt_3b1d_0ac0(*(undefined2 *)(unaff_BP + -10),*(undefined2 *)(unaff_BP + -8),
                                 unaff_BP + -0xd2);
      pcVar6 = (char *)ovr_OVC15_4207_1c16(uVar7,in_DX,uVar9);
      pcVar8 = ovr_stsprintf((char *)(unaff_BP + -0x82),"%s is entangled in a web created by %s.",
                             pcVar6);
      ovr_uiNotify(pcVar8,uVar5);
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x33) =
           *(undefined1 *)((int)*(undefined4 *)(unaff_BP + 6) + 0x32);
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 0xd;
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 5;
      puVar1 = (uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b);
      *puVar1 = *puVar1 | 0x100;
      uVar5 = ovr_audio_3a5b_0afd();
      ovr_play_sfxU(0x1b,0,uVar5);
      OVC27_5ded_1be7();
      return;
    }
    OVC27_5ded_1be7();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\t') {
    if ((*(uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b) & 0x40) != 0) {
      OVC27_5ded_1be7();
      return;
    }
    cVar3 = OVC27_5ded_1c94(*(undefined2 *)(unaff_BP + -10),*(undefined2 *)(unaff_BP + -8),3);
    if (cVar3 == '\0') {
      uVar5 = DAT_2000_d0f7;
      uVar7 = ovr_agnt_3b1d_0ac0(*(undefined2 *)(unaff_BP + 6),*(undefined2 *)(unaff_BP + 8),
                                 unaff_BP + -0x122);
      uVar9 = CONCAT22(in_DX,uVar7);
      uVar7 = ovr_agnt_3b1d_0ac0(*(undefined2 *)(unaff_BP + -10),*(undefined2 *)(unaff_BP + -8),
                                 unaff_BP + -0xd2);
      pcVar6 = (char *)ovr_OVC15_4207_1c16(uVar7,in_DX,uVar9);
      pcVar8 = ovr_stsprintf((char *)(unaff_BP + -0x82),"%s is held by %s.",pcVar6);
      ovr_uiNotify(pcVar8,uVar5);
      ovr_OVC41_6a8f_0229();
      puVar1 = (uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b);
      *puVar1 = *puVar1 | 0x40;
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 0x10;
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 0;
      uVar5 = ovr_audio_3a5b_0afd();
      ovr_play_sfxU(0x1b,0,uVar5);
      OVC27_5ded_1be7();
      return;
    }
    OVC27_5ded_1be7();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\v') {
    cVar3 = OVC27_5ded_1c94(*(undefined2 *)(unaff_BP + -10),*(undefined2 *)(unaff_BP + -8),3);
    if (cVar3 == '\0') {
      ovr_OVC41_6a8f_1c74(*(undefined2 *)(unaff_BP + 6),*(undefined2 *)(unaff_BP + 8),
                          *(undefined2 *)(unaff_BP + -10),*(undefined2 *)(unaff_BP + -8),
                          *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x21));
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 0xb;
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 0;
      OVC27_5ded_1be7();
      return;
    }
    OVC27_5ded_1be7();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\f') {
    uVar9 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x17);
    if (7 < *(byte *)((int)uVar9 + 0xf)) {
      OVC27_5ded_1be7();
      return;
    }
    cVar3 = OVC27_5ded_1c94(*(undefined2 *)(unaff_BP + -10),*(undefined2 *)(unaff_BP + -8),3);
    if (cVar3 == '\0') {
      ovr_OVC41_6a8f_1c74(*(undefined2 *)(unaff_BP + 6),*(undefined2 *)(unaff_BP + 8),
                          *(undefined2 *)(unaff_BP + -10),*(undefined2 *)(unaff_BP + -8),
                          *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x21));
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 0xb;
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 0;
      OVC27_5ded_1be7();
      return;
    }
    OVC27_5ded_1be7();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\r') {
    cVar3 = OVC27_5ded_1c94(*(undefined2 *)(unaff_BP + -10),*(undefined2 *)(unaff_BP + -8),3);
    if (cVar3 == '\0') {
      ovr_OVC41_6a8f_1c74(*(undefined2 *)(unaff_BP + 6),*(undefined2 *)(unaff_BP + 8),
                          *(undefined2 *)(unaff_BP + -10),*(undefined2 *)(unaff_BP + -8),
                          *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x21));
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x30) = 0xb;
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x31) = 0;
      OVC27_5ded_1be7();
      return;
    }
    OVC27_5ded_1be7();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) == '\x0e') {
    if (*(char *)((int)*(undefined4 *)(unaff_BP + -10) + 0x11) != '\0') {
      OVC27_5ded_1be7();
      return;
    }
    cVar3 = OVC27_5ded_1c94(*(undefined2 *)(unaff_BP + -10),*(undefined2 *)(unaff_BP + -8),3);
    if (cVar3 == '\0') {
      ovr_OVC41_6a8f_0229();
      puVar1 = (uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b);
      *puVar1 = *puVar1 | 0x800;
      uVar5 = ovr_audio_3a5b_0afd();
      ovr_play_sfxU(0x1b,0,uVar5);
      OVC27_5ded_1be7();
      return;
    }
    OVC27_5ded_1be7();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2e) != '\x0f') {
    OVC27_5ded_1be7();
    return;
  }
  *(undefined2 *)(unaff_BP + -4) = 0x1e;
  *(undefined2 *)(unaff_BP + -2) = 0;
  do {
    if (((*(uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b) & 0x20) == 0) &&
       (cVar3 = OVC27_5ded_1c94(*(undefined2 *)(unaff_BP + -10),*(undefined2 *)(unaff_BP + -8),3),
       cVar3 == '\0')) {
      uVar5 = DAT_2000_d0f7;
      uVar7 = ovr_agnt_3b1d_0ac0(*(undefined2 *)(unaff_BP + 6),*(undefined2 *)(unaff_BP + 8),
                                 unaff_BP + -0x122);
      uVar9 = CONCAT22(in_DX,uVar7);
      uVar7 = ovr_agnt_3b1d_0ac0(*(undefined2 *)(unaff_BP + -10),*(undefined2 *)(unaff_BP + -8),
                                 unaff_BP + -0xd2);
      pcVar6 = (char *)ovr_OVC15_4207_1c16(uVar7,in_DX,uVar9);
      pcVar8 = ovr_stsprintf((char *)(unaff_BP + -0x82),"%s is charmed by %s.",pcVar6);
      in_DX = (undefined2)((ulong)pcVar8 >> 0x10);
      ovr_uiNotify(pcVar8,uVar5);
      ovr_OVC41_6a8f_0229();
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2f) =
           *(undefined1 *)((int)*(undefined4 *)(unaff_BP + 6) + 0x2f);
      puVar1 = (uint *)((int)*(undefined4 *)(unaff_BP + -10) + 0x2b);
      *puVar1 = *puVar1 | 0x20;
      uVar5 = ovr_audio_3a5b_0afd();
      ovr_play_sfxU(0x1b,0,uVar5);
    }
    do {
      uVar7 = OVC27_5ded_1beb();
      *(undefined2 *)(unaff_BP + -8) = in_DX;
      *(undefined2 *)(unaff_BP + -10) = uVar7;
      if (*(int *)(unaff_BP + -10) == 0 && *(int *)(unaff_BP + -8) == 0) break;
    } while (*(int *)(unaff_BP + -2) == unaff_DI);
    if (*(int *)(unaff_BP + -10) != 0 || *(int *)(unaff_BP + -8) != 0) {
      uVar9 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -10) + 0x17);
      *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) - (uint)*(byte *)((int)uVar9 + 0xf);
    }
    if ((*(int *)(unaff_BP + -10) == 0 && *(int *)(unaff_BP + -8) == 0) ||
       (*(int *)(unaff_BP + -4) == 0)) {
      return;
    }
  } while( true );
}



/* 5ded:1be7 */

void __cdecl16far OVC27_5ded_1be7(void)

{
  return;
}



/* 5ded:1beb */

int __cdecl16far OVC27_5ded_1beb(undefined4 param_1,byte param_2,byte param_3,int *param_4)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  undefined2 uVar4;
  
  do {
    if ((int)(uint)AgntCount <= *param_4) {
      return 0;
    }
    uVar2 = *(undefined4 *)(*param_4 * 0x34 + 0x17);
    if (*(byte *)((int)uVar2 + 0xf) <= param_3) {
      uVar4 = (undefined2)((ulong)param_1 >> 0x10);
      if ((*(char *)*(undefined4 *)(*param_4 * 0x34 + 0x1d) != *(char *)((int)param_1 + 0x2f)) &&
         (cVar3 = OVC27_5ded_052d((int)param_1,uVar4,(uint)param_2 * 0x21,(char *)"n/s gate" + 4,
                                  *param_4), cVar3 != '\0')) {
        iVar1 = *param_4;
        *param_4 = *param_4 + 1;
        return iVar1 * 0x34;
      }
    }
    *param_4 = *param_4 + 1;
  } while( true );
}



/* 5ded:1c94 */

int __cdecl16far OVC27_5ded_1c94(undefined4 param_1,byte param_2)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *puVar3;
  uint16_t uVar4;
  int iVar5;
  undefined2 uVar6;
  byte bStack_9;
  byte bStack_8;
  byte bStack_7;
  undefined4 uStack_6;
  
  uVar6 = (undefined2)((ulong)param_1 >> 0x10);
  iVar5 = (int)param_1;
  bStack_7 = *(byte *)((int)*(undefined4 *)(iVar5 + 0x17) + 0xf);
  bStack_8 = *(byte *)((int)*(undefined4 *)(iVar5 + 0x1d) + 0x46);
  if ((bStack_8 == 0xff) && (bStack_8 = 0, *(byte *)((int)*(undefined4 *)(iVar5 + 0x1d) + 0x53) < 4)
     ) {
    bStack_7 = bStack_7 >> 1;
  }
  uStack_6 = (byte *)CONCAT22(*(undefined2 *)
                               ((int)&far_t_ARRAY_2410_5aeb[0].seg + (uint)bStack_8 * 4),
                              (byte *)((far_t *)far_t_ARRAY_2410_5aeb + bStack_8)->ofs);
  while ((*uStack_6 != 0xff && (*uStack_6 < bStack_7))) {
    uStack_6 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(byte *)uStack_6 + 6);
  }
  bStack_9 = ((byte *)uStack_6)[param_2 + 1];
  if ((param_2 == 3) && (*(char *)((int)*(undefined4 *)(iVar5 + 0x17) + 0x1a) != -1)) {
    puVar3 = (undefined4 *)((uint)*(byte *)((int)*(undefined4 *)(iVar5 + 0x17) + 0x1a) << 2);
    uVar1 = *puVar3;
    cVar2 = ovr_manage_4d05_118b
                      (CONCAT11((char)((uint)puVar3 >> 8),*(undefined1 *)((int)uVar1 + 0x2b)));
    bStack_9 = bStack_9 - cVar2;
  }
  uVar4 = ovr_randBelow(0x14);
  if ((int)((uVar4 & 0xff) + 1) < (int)(char)bStack_9) {
    iVar5 = (uint)(byte)((char)bStack_9 >> 7) << 8;
  }
  else {
    iVar5 = CONCAT11((char)bStack_9 >> 7,1);
  }
  return iVar5;
}



/* 5ded:1d8e */

int __cdecl16far OVC27_5ded_1d8e(undefined4 param_1,byte param_2)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *puVar3;
  uint16_t uVar4;
  int iVar5;
  undefined2 uVar6;
  byte bStack_9;
  byte bStack_8;
  byte bStack_7;
  undefined4 uStack_6;
  
  uVar6 = (undefined2)((ulong)param_1 >> 0x10);
  iVar5 = (int)param_1;
  bStack_7 = *(byte *)(iVar5 + 0xf);
  bStack_8 = *(byte *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)*(byte *)(iVar5 + 0xd) * 0x95)
  ;
  if ((bStack_8 == 0xff) &&
     (bStack_8 = 0,
     *(byte *)((int)&far_t_ARRAY_2410_26f7[0xc].seg + (uint)*(byte *)(iVar5 + 0xd) * 0x95) < 4)) {
    bStack_7 = bStack_7 >> 1;
  }
  uStack_6 = (byte *)CONCAT22(*(undefined2 *)
                               ((int)&far_t_ARRAY_2410_5aeb[0].seg + (uint)bStack_8 * 4),
                              (byte *)((far_t *)far_t_ARRAY_2410_5aeb + bStack_8)->ofs);
  while ((*uStack_6 != 0xff && (*uStack_6 < bStack_7))) {
    uStack_6 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(byte *)uStack_6 + 6);
  }
  bStack_9 = ((byte *)uStack_6)[param_2 + 1];
  if ((param_2 == 3) && (*(char *)(iVar5 + 0x1a) != -1)) {
    uVar1 = *(undefined4 *)((uint)*(byte *)(iVar5 + 0x1a) << 2);
    *(undefined1 *)((int)uVar1 + 0x2b) = 0x12;
    puVar3 = (undefined4 *)((uint)*(byte *)(iVar5 + 0x1a) << 2);
    uVar1 = *puVar3;
    cVar2 = ovr_manage_4d05_118b
                      (CONCAT11((char)((uint)puVar3 >> 8),*(undefined1 *)((int)uVar1 + 0x2b)));
    bStack_9 = bStack_9 - cVar2;
  }
  uVar4 = ovr_randBelow(0x14);
  if ((int)((uVar4 & 0xff) + 1) < (int)(char)bStack_9) {
    iVar5 = (uint)(byte)((char)bStack_9 >> 7) << 8;
  }
  else {
    iVar5 = CONCAT11((char)bStack_9 >> 7,1);
  }
  return iVar5;
}



/* 5ded:1eb7 */

undefined2 __cdecl16far OVC27_5ded_1eb7(undefined4 param_1,char param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  bool bVar7;
  byte bStack_6;
  uint uStack_4;
  
  uStack_4 = 0;
  while( true ) {
    iVar5 = (int)param_1;
    uVar6 = (undefined2)((ulong)param_1 >> 0x10);
    if ((param_2 == '\0') || (*(char *)(iVar5 + 0xf) == '\0')) break;
    bVar3 = ovr_OVC15_4207_25dd(iVar5,uVar6);
    uStack_4 = uStack_4 + bVar3;
    *(char *)(iVar5 + 0xf) = *(char *)(iVar5 + 0xf) + -1;
    param_2 = param_2 + -1;
  }
  bVar7 = *(char *)(iVar5 + 0xf) == '\0';
  if (bVar7) {
    *(undefined1 *)(iVar5 + 0xf) = 1;
  }
  if (uStack_4 < *(byte *)(iVar5 + 0x32)) {
    *(char *)(iVar5 + 0x32) = *(char *)(iVar5 + 0x32) - (char)uStack_4;
  }
  else {
    *(undefined1 *)(iVar5 + 0x32) = 1;
  }
  if (uStack_4 < *(byte *)(iVar5 + 0x31)) {
    *(char *)(iVar5 + 0x31) = *(char *)(iVar5 + 0x31) - (char)uStack_4;
  }
  else {
    *(undefined1 *)(iVar5 + 0x31) = 1;
  }
  if (*(byte *)(iVar5 + 0x32) < *(byte *)(iVar5 + 0x31)) {
    *(undefined1 *)(iVar5 + 0x31) = *(undefined1 *)(iVar5 + 0x32);
  }
  bStack_6 = *(byte *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)*(byte *)(iVar5 + 0xd) * 0x95)
  ;
  if (bStack_6 == 0xff) {
    bStack_6 = 0;
  }
  iVar4 = (uint)bStack_6 * 0x94 + (uint)*(byte *)(iVar5 + 0xf) * 4;
  uVar1 = *(undefined2 *)(iVar4 + -2);
  uVar2 = *(undefined2 *)(iVar4 + -4);
  *(undefined2 *)(iVar5 + 0x12) = uVar1;
  *(undefined2 *)(iVar5 + 0x10) = uVar2;
  return CONCAT11((char)((uint)uVar1 >> 8),bVar7);
}



/* 5ded:1fe1 */

undefined2 __cdecl16far
OVC27_5ded_1fe1(undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined1 param_4)

{
  int iVar1;
  char cVar2;
  undefined2 uVar3;
  uint16_t unk;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  
  uVar6 = (undefined2)((ulong)param_3 >> 0x10);
  iVar4 = (int)param_3;
  uVar3 = *(undefined2 *)(iVar4 + 0x19);
  iVar1 = *(int *)(iVar4 + 0x17);
  cVar2 = OVC27_5ded_1eb7(iVar1,uVar3,CONCAT11((char)((uint)uVar3 >> 8),param_4));
  if (cVar2 == '\0') {
    for (iVar5 = 0; iVar5 < (int)(uint)AgntCount; iVar5 = iVar5 + 1) {
      if (*(int *)(iVar5 * 0x34 + 0x1b) == *(int *)(iVar4 + 0x1b)) {
        if (*(byte *)(iVar1 + 0x32) < *(byte *)(iVar5 * 0x34 + 0x22)) {
          *(undefined1 *)(iVar5 * 0x34 + 0x22) = *(undefined1 *)(iVar1 + 0x32);
        }
        if (*(byte *)(iVar5 * 0x34 + 0x22) < *(byte *)(iVar5 * 0x34 + 0x21)) {
          *(undefined1 *)(iVar5 * 0x34 + 0x21) = *(undefined1 *)(iVar5 * 0x34 + 0x22);
        }
      }
    }
    unk = ovr_audio_3a5b_0afd(iVar4,uVar6);
    ovr_play_sfxU(0x1c,0,unk);
    uVar3 = 1;
  }
  else {
    ovr_OVC41_6a8f_063f(param_1,param_2,iVar4,uVar6);
    uVar3 = 0;
  }
  return uVar3;
}



/* 5ded:218c */

void __cdecl16far switchD_6000_3cd8_caseD_0(void)

{
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  
  *(char *)(unaff_BP + unaff_SI) = *(char *)(unaff_BP + unaff_SI) + '\x01';
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


