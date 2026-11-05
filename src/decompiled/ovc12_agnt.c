/*
 * ovc12_agnt.c - recovered from STRONG.EXE
 * memory block: OVC12_agnt.c
 * range: 3b1d:0000 - 3b1d:1f8f
 * functions: 34
 */
#include "recovered.h"


/* 3b1d:0000 */

bool __cdecl16far agnt_3b1d_0000(void)

{
  bool bVar1;
  
  if (((AgntCount == '\0') && (DAT_2000_d2d6 == '\0')) && (GAnimPlaying == '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}



/* 3b1d:0032 */

undefined2 __cdecl16far agnt_3b1d_0032(int param_1)

{
  if (param_1 < 0xc) {
    param_1 = 0xc;
  }
  if (0xde < param_1) {
    param_1 = 0xde;
  }
  return *(undefined2 *)((param_1 + -0xc) * 2 + 0x34c);
}



/* 3b1d:005e */

int __cdecl16far agnt_3b1d_005e(int param_1)

{
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (0xd2 < param_1) {
    param_1 = 0xd2;
  }
  return param_1;
}



/* 3b1d:0079 */

undefined1 __cdecl16far agnt_3b1d_0079(int *param_1)

{
  undefined1 uVar1;
  int *piVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  piVar2 = (int *)param_1;
  if ((((piVar2[1] < 0x15) || (*(char *)((int)piVar2 + 0x25) == '\x01')) && (*param_1 < 0xd3)) &&
     (-1 < *param_1)) {
    uVar1 = ovr_OVC49_8699_06dc(piVar2,uVar3);
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* 3b1d:00b7 */

bool __cdecl16far agnt_3b1d_00b7(char *param_1)

{
  return *param_1 != '\0';
}



/* 3b1d:00ce */

undefined1 __cdecl16far agnt_3b1d_00ce(int *param_1,undefined1 *param_2)

{
  char cVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined2 uVar7;
  char cStack_e;
  char cStack_d;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  
  uVar7 = (undefined2)((ulong)param_1 >> 0x10);
  piVar5 = (int *)param_1;
  if (piVar5[1] < 0x15) {
    cVar1 = *(char *)((int)piVar5 + 0x2f);
    piVar6 = (int *)(*(int *)((int)piVar5 + 0x13) + (uint)*(byte *)(piVar5 + 9) * 4);
    iVar4 = piVar6[1];
    iVar2 = *piVar6;
    iStack_6 = piVar5[1] >> 1;
    if (iStack_6 < 0) {
      iStack_6 = 0;
    }
    if (9 < iStack_6) {
      iStack_6 = 9;
    }
    if (*(char *)((int)piVar5 + 0xf) == '\0') {
      cStack_d = '\x01';
      iStack_a = ((int)*(char *)((int)*(undefined4 *)((int)piVar5 + 0x1d) + 0x21) +
                  *(int *)(iVar2 + 0x17) + *param_1 >> 1) + -1;
      iStack_c = iStack_a +
                 ((int)*(char *)((int)*(undefined4 *)((int)piVar5 + 0x1d) + 0x22) -
                  (int)*(char *)((int)*(undefined4 *)((int)piVar5 + 0x1d) + 0x21) >> 1);
    }
    else {
      cStack_d = -1;
      iStack_a = ((-*(int *)(iVar2 + 0x17) -
                  (int)*(char *)((int)*(undefined4 *)((int)piVar5 + 0x1d) + 0x21)) + *param_1 >> 1)
                 + 1;
      iStack_c = iStack_a -
                 ((int)*(char *)((int)*(undefined4 *)((int)piVar5 + 0x1d) + 0x22) -
                  (int)*(char *)((int)*(undefined4 *)((int)piVar5 + 0x1d) + 0x21) >> 1);
    }
    if (iStack_a < 0) {
      iStack_a = 0;
    }
    if (iStack_c < 0) {
      iStack_c = 0;
    }
    if (0x68 < iStack_a) {
      iStack_a = 0x68;
    }
    if (0x68 < iStack_c) {
      iStack_c = 0x68;
    }
    while( true ) {
      for (iStack_8 = 0;
          iStack_8 <= (int)*(char *)((int)*(undefined4 *)((int)piVar5 + 0x1d) + 0x23) >> 1;
          iStack_8 = iStack_8 + 1) {
        cStack_e = -1;
        while (((cStack_e < '\x02' && (iStack_8 != 0)) || ((cStack_e == -1 && (iStack_8 == 0))))) {
          iVar4 = iStack_6 + iStack_8 * cStack_e;
          if ((-1 < iVar4) && (iVar4 < 10)) {
            if ((*(char *)(iVar4 * 0x69 + iStack_a + 0x8fa) != '\0') &&
               (((*(byte *)(iVar4 * 0x69 + iStack_a + 0x8fa) <= AgntCount &&
                 (*(char *)((uint)*(byte *)(iVar4 * 0x69 + iStack_a + 0x8fa) * 0x34 + -5) != cVar1))
                && (*(char *)((uint)*(byte *)(iVar4 * 0x69 + iStack_a + 0x8fa) * 0x34 + -0x10) ==
                    '\0')))) {
              *param_2 = *(undefined1 *)(iVar4 * 0x69 + iStack_a + 0x8fa);
              cVar3 = agnt_3b1d_00b7((undefined1 *)param_2,param_2._2_2_);
              if (cVar3 != '\0') {
                return *param_2;
              }
            }
            if (((*(char *)(iVar4 * 0x69 + iStack_a + 0x4e0) != '\0') &&
                (*(byte *)(iVar4 * 0x69 + iStack_a + 0x4e0) <= AgntCount)) &&
               ((*(char *)((uint)*(byte *)(iVar4 * 0x69 + iStack_a + 0x4e0) * 0x34 + -5) != cVar1 &&
                (*(char *)((uint)*(byte *)(iVar4 * 0x69 + iStack_a + 0x4e0) * 0x34 + -0x10) == '\0')
                ))) {
              *param_2 = *(undefined1 *)(iVar4 * 0x69 + iStack_a + 0x4e0);
              return *param_2;
            }
          }
          cStack_e = cStack_e + '\x02';
        }
      }
      if (iStack_a == iStack_c) break;
      iStack_a = iStack_a + cStack_d;
    }
    *param_2 = 0;
  }
  else {
    *param_2 = 0;
  }
  return 0;
}



/* 3b1d:0426 */

/* WARNING: Type propagation algorithm not settling */

undefined1 __cdecl16far agnt_3b1d_0426(int *param_1,byte *param_2,char param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char cVar4;
  undefined1 uVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  undefined2 uVar9;
  char cStack_e;
  char cStack_d;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  
  uVar9 = (undefined2)((ulong)param_1 >> 0x10);
  piVar7 = (int *)param_1;
  if (((*(byte *)((int)piVar7 + 0x21) < *(byte *)(piVar7 + 0x11)) &&
      ((*(uint *)((int)piVar7 + 0x2b) & 0x820) == 0)) &&
     ((*(uint *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x3c) & 0x20) == 0)) {
    *param_2 = param_3 + 1;
    uVar5 = 1;
  }
  else {
    cVar1 = *(char *)((int)piVar7 + 0x2f);
    piVar8 = (int *)(*(int *)((int)piVar7 + 0x13) + (uint)*(byte *)(piVar7 + 9) * 4);
    iVar6 = piVar8[1];
    iVar2 = *piVar8;
    iStack_6 = piVar7[1] >> 1;
    if (iStack_6 < 0) {
      iStack_6 = 0;
    }
    if (9 < iStack_6) {
      iStack_6 = 9;
    }
    if (*(char *)((int)piVar7 + 0xf) == '\0') {
      cStack_d = '\x01';
      iStack_a = ((int)*(char *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x1b) +
                  *(int *)(iVar2 + 0x17) + *param_1 >> 1) + -1;
      iStack_c = iStack_a +
                 ((int)*(char *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x1c) -
                  (int)*(char *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x1b) >> 1);
    }
    else {
      cStack_d = -1;
      iStack_a = ((-*(int *)(iVar2 + 0x17) -
                  (int)*(char *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x1b)) + *param_1 >> 1)
                 + 1;
      iStack_c = iStack_a -
                 ((int)*(char *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x1c) -
                  (int)*(char *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x1b) >> 1);
    }
    if (iStack_a < 0) {
      iStack_a = 0;
    }
    if (iStack_c < 0) {
      iStack_c = 0;
    }
    if (0x68 < iStack_a) {
      iStack_a = 0x68;
    }
    if (0x68 < iStack_c) {
      iStack_c = 0x68;
    }
    for (; iStack_a != iStack_c; iStack_a = iStack_a + cStack_d) {
      for (iStack_8 = 0;
          iStack_8 <= (int)*(char *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x1d) >> 1;
          iStack_8 = iStack_8 + 1) {
        cStack_e = -1;
        while (((cStack_e < '\x02' && (iStack_8 != 0)) || ((cStack_e == -1 && (iStack_8 == 0))))) {
          iVar6 = iStack_6 + iStack_8 * cStack_e;
          if ((-1 < iVar6) && (iVar6 < 10)) {
            if ((*(char *)(iVar6 * 0x69 + iStack_a + 0x8fa) != '\0') &&
               ((((*(byte *)(iVar6 * 0x69 + iStack_a + 0x8fa) <= AgntCount &&
                  (*(byte *)((uint)*(byte *)(iVar6 * 0x69 + iStack_a + 0x8fa) * 0x34 + -0x13) <
                   *(byte *)((uint)*(byte *)(iVar6 * 0x69 + iStack_a + 0x8fa) * 0x34 + -0x12))) &&
                 (*(char *)((uint)*(byte *)(iVar6 * 0x69 + iStack_a + 0x8fa) * 0x34 + -5) == cVar1))
                && ((*(char *)*(undefined4 *)
                               ((uint)*(byte *)(iVar6 * 0x69 + iStack_a + 0x8fa) * 0x34 + -0x17) ==
                     cVar1 && (uVar3 = *(undefined4 *)
                                        ((uint)*(byte *)(iVar6 * 0x69 + iStack_a + 0x8fa) * 0x34 +
                                        -0x17), (*(uint *)((int)uVar3 + 0x3c) & 0x20) == 0)))))) {
              *param_2 = *(byte *)(iVar6 * 0x69 + iStack_a + 0x8fa);
              cVar4 = agnt_3b1d_00b7((byte *)param_2,param_2._2_2_);
              if ((cVar4 != '\0') &&
                 ((*(byte *)((uint)*param_2 * 0x34 + -0x13) <
                   *(byte *)((uint)*param_2 * 0x34 + -0x12) &&
                  ((*(uint *)((uint)*param_2 * 0x34 + -9) & 0x820) == 0)))) {
                return *(undefined1 *)(iVar6 * 0x69 + iStack_a + 0x8fa);
              }
            }
            if ((((*(char *)(iVar6 * 0x69 + iStack_a + 0x4e0) != '\0') &&
                 (*(byte *)(iVar6 * 0x69 + iStack_a + 0x4e0) <= AgntCount)) &&
                (*(byte *)((uint)*(byte *)(iVar6 * 0x69 + iStack_a + 0x4e0) * 0x34 + -0x13) <
                 *(byte *)((uint)*(byte *)(iVar6 * 0x69 + iStack_a + 0x4e0) * 0x34 + -0x12))) &&
               (((*(char *)((uint)*(byte *)(iVar6 * 0x69 + iStack_a + 0x4e0) * 0x34 + -5) == cVar1
                 && (*(char *)*(undefined4 *)
                               ((uint)*(byte *)(iVar6 * 0x69 + iStack_a + 0x4e0) * 0x34 + -0x17) ==
                     cVar1)) &&
                (uVar3 = *(undefined4 *)
                          ((uint)*(byte *)(iVar6 * 0x69 + iStack_a + 0x4e0) * 0x34 + -0x17),
                (*(uint *)((int)uVar3 + 0x3c) & 0x20) == 0)))) {
              *param_2 = *(byte *)(iVar6 * 0x69 + iStack_a + 0x4e0);
              return *(undefined1 *)(iVar6 * 0x69 + iStack_a + 0x4e0);
            }
          }
          cStack_e = cStack_e + '\x02';
        }
      }
    }
    *param_2 = 0;
    uVar5 = 0;
  }
  return uVar5;
}



/* 3b1d:093e */

bool __cdecl16far agnt_3b1d_093e(int *param_1,undefined2 *param_2,undefined2 *param_3,uint *param_4)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  undefined2 uVar8;
  byte bStack_4;
  
  uVar8 = (undefined2)((ulong)param_1 >> 0x10);
  piVar7 = (int *)param_1;
  cVar1 = *(char *)((int)piVar7 + 0x2f);
  *param_4 = 0xffff;
  for (bStack_4 = 0; bStack_4 < AgntCount; bStack_4 = bStack_4 + 1) {
    if ((*(char *)((uint)bStack_4 * 0x34 + 0x2f) != cVar1) &&
       (uVar2 = *(int *)((uint)bStack_4 * 0x34) - *param_1, uVar5 = (int)uVar2 >> 0xf,
       uVar3 = *(int *)((uint)bStack_4 * 0x34 + 2) - piVar7[1], uVar6 = (int)uVar3 >> 0xf,
       uVar2 = ((uVar2 ^ uVar5) - uVar5) + ((uVar3 ^ uVar6) - uVar6), uVar2 < *param_4)) {
      *param_4 = uVar2;
      uVar4 = ovr_OVC07_32c9_0026(*(int *)((uint)bStack_4 * 0x34) - *param_1);
      *param_2 = uVar4;
      uVar4 = ovr_OVC07_32c9_0026(*(int *)((uint)bStack_4 * 0x34 + 2) - piVar7[1]);
      *param_3 = uVar4;
    }
  }
  return *param_4 != 0xffff;
}



/* 3b1d:0a53 */

void __cdecl16far agnt_3b1d_0a53(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined1 *)(iVar1 + 0xe) = 0xff;
  *(undefined1 *)(iVar1 + 0xc) = 0xff;
  *(undefined1 *)(iVar1 + 0x10) = 0;
  *(undefined1 *)(iVar1 + 0xd) = 0;
  *(uint *)(iVar1 + 0x2b) = *(uint *)(iVar1 + 0x2b) & 0xfff5;
  *(undefined1 *)(iVar1 + 0x2e) = 0;
  DAT_2410_07e2 = 0;
  return;
}



/* 3b1d:0a8d */

void __cdecl16far agnt_3b1d_0a8d(undefined4 param_1)

{
  *(undefined1 *)((int)param_1 + 0x10) = 0;
  DAT_2410_07e2 = 0;
  return;
}



/* 3b1d:0a9f */

void __cdecl16far agnt_3b1d_0a9f(undefined4 param_1)

{
  undefined4 uVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  uVar1 = *(undefined4 *)((int)param_1 + 0x1d);
  if ((*(uint *)((int)uVar1 + 0x40) & 4) == 0) {
    agnt_3b1d_0a53((int)param_1,uVar2);
  }
  return;
}



/* 3b1d:0ac0 */

char * __cdecl16far agnt_3b1d_0ac0(undefined4 param_1,char *param_2)

{
  char *pcVar1;
  int iVar2;
  undefined2 uVar3;
  char *pcVar4;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if ((*(uint *)(iVar2 + 0x2b) & 0x20) == 0) {
    if ((*(uint *)(iVar2 + 0x2b) & 4) == 0) {
      if ((*(uint *)(iVar2 + 0x2b) & 0x800) == 0) {
        if ((*(uint *)((int)*(undefined4 *)(iVar2 + 0x17) + 0x14) & 1) == 0) {
          if ((*(uint *)(iVar2 + 0x2b) & 0x200) == 0) {
            if ((*(uint *)(iVar2 + 0x2b) & 0x80) == 0) {
              if ((*(uint *)(iVar2 + 0x2b) & 0x40) == 0) {
                pcVar1 = (char *)*(undefined2 *)((int)*(undefined4 *)(iVar2 + 0x1d) + 0x24);
              }
              else {
                pcVar4 = ovr_stsprintf(param_2,"held %s",
                                       (char *)*(undefined2 *)
                                                ((int)*(undefined4 *)(iVar2 + 0x1d) + 0x24));
                pcVar1 = (char *)pcVar4;
              }
            }
            else {
              pcVar4 = ovr_stsprintf(param_2,"sleeping %s",
                                     (char *)*(undefined2 *)
                                              ((int)*(undefined4 *)(iVar2 + 0x1d) + 0x24));
              pcVar1 = (char *)pcVar4;
            }
          }
          else {
            pcVar4 = ovr_stsprintf(param_2,"paralyzed %s",
                                   (char *)*(undefined2 *)
                                            ((int)*(undefined4 *)(iVar2 + 0x1d) + 0x24));
            pcVar1 = (char *)pcVar4;
          }
        }
        else {
          pcVar4 = ovr_stsprintf(param_2,"diseased %s",
                                 (char *)*(undefined2 *)((int)*(undefined4 *)(iVar2 + 0x1d) + 0x24))
          ;
          pcVar1 = (char *)pcVar4;
        }
      }
      else {
        pcVar4 = ovr_stsprintf(param_2,"stoned %s",
                               (char *)*(undefined2 *)((int)*(undefined4 *)(iVar2 + 0x1d) + 0x24));
        pcVar1 = (char *)pcVar4;
      }
    }
    else {
      pcVar4 = ovr_stsprintf(param_2,"turned %s",
                             (char *)*(undefined2 *)((int)*(undefined4 *)(iVar2 + 0x1d) + 0x24));
      pcVar1 = (char *)pcVar4;
    }
  }
  else {
    pcVar4 = ovr_stsprintf(param_2,"charmed %s",
                           (char *)*(undefined2 *)((int)*(undefined4 *)(iVar2 + 0x1d) + 0x24));
    pcVar1 = (char *)pcVar4;
  }
  return pcVar1;
}



/* 3b1d:0c1e */

undefined2 __cdecl16far agnt_3b1d_0c1e(byte param_1,byte param_2)

{
  byte bVar1;
  undefined2 uVar2;
  
  bVar1 = *(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + (uint)param_2 + 0x29);
  if (bVar1 < 4) {
    uVar2 = 0xfd;
  }
  else if (bVar1 < 6) {
    uVar2 = 0xfe;
  }
  else if (bVar1 < 9) {
    uVar2 = 0xff;
  }
  else if (bVar1 < 0xd) {
    uVar2 = 0;
  }
  else if (bVar1 < 0x10) {
    uVar2 = 1;
  }
  else if (bVar1 < 0x12) {
    uVar2 = 2;
  }
  else {
    uVar2 = 3;
  }
  return uVar2;
}



/* 3b1d:0c7c */

byte __cdecl16far agnt_3b1d_0c7c(undefined4 param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)((int)param_1 + 0x36) % 6;
  if (3 < bVar1) {
    bVar1 = bVar1 - 6;
  }
  return bVar1;
}



/* 3b1d:0c9f */

byte __cdecl16far agnt_3b1d_0c9f(undefined4 param_1)

{
  undefined4 uVar1;
  byte bVar2;
  
  uVar1 = *(undefined4 *)((int)param_1 + 0x17);
  bVar2 = *(byte *)((int)uVar1 + 0x36) % 6;
  if (3 < bVar2) {
    bVar2 = bVar2 - 6;
  }
  return bVar2;
}



/* 3b1d:0cc6 */

byte __cdecl16far agnt_3b1d_0cc6(undefined4 param_1)

{
  byte bVar1;
  
  bVar1 = (byte)(((ulong)*(byte *)((int)param_1 + 0x36) / 6) % 6);
  if (4 < bVar1) {
    bVar1 = bVar1 - 6;
  }
  return bVar1;
}



/* 3b1d:0cef */

byte __cdecl16far agnt_3b1d_0cef(undefined4 param_1)

{
  undefined4 uVar1;
  byte bVar2;
  
  uVar1 = *(undefined4 *)((int)param_1 + 0x17);
  bVar2 = (byte)(((ulong)*(byte *)((int)uVar1 + 0x36) / 6) % 6);
  if (4 < bVar2) {
    bVar2 = bVar2 - 6;
  }
  return bVar2;
}



/* 3b1d:0d1c */

undefined1 __cdecl16far agnt_3b1d_0d1c(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if (*(char *)(iVar2 + 0xe) == -1) {
    if (*(char *)(iVar2 + 0x10) < '\x02') {
      uVar1 = 1;
    }
    else if (*(char *)(iVar2 + 0x10) == '\x04') {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 3b1d:0d4d */

uint __cdecl16far agnt_3b1d_0d4d(uint *param_1,int *param_2)

{
  char cVar1;
  uint uVar2;
  undefined2 uVar3;
  
  uVar2 = *param_1;
  uVar3 = (undefined2)((ulong)param_2 >> 0x10);
  if ((int)uVar2 < *param_2) {
    if (*(char *)((int)(int *)param_2 + 0xf) != '\0') {
      return CONCAT11((char)(uVar2 >> 8),1);
    }
  }
  else {
    cVar1 = *(char *)((int)(int *)param_2 + 0xf);
    uVar2 = (uint)cVar1;
    if (uVar2 == 0) {
      return CONCAT11(cVar1 >> 7,1);
    }
  }
  return uVar2 & 0xff00;
}



/* 3b1d:0d82 */

void __cdecl16far agnt_3b1d_0d82(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  uint uStack_10;
  
  uVar10 = (undefined2)((ulong)param_1 >> 0x10);
  iVar7 = (int)param_1;
  iVar3 = (uint)*(byte *)(iVar7 + 0xc) * 0x34;
  piVar8 = (int *)(*(int *)(iVar3 + 0x13) + (uint)*(byte *)(iVar3 + 0x12) * 4);
  iVar1 = piVar8[1];
  iVar2 = *piVar8;
  if (iVar2 == 0 && iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x12);
  }
  uVar4 = *(int *)(iVar3 + 0x26) - *(int *)(iVar7 + 8);
  uStack_10 = (*(int *)(iVar3 + 0x28) - (uint)*(byte *)(iVar7 + 10)) - (*(int *)(iVar2 + 0xd) >> 1);
  if (((int)((uVar4 ^ (int)uVar4 >> 0xf) - ((int)uVar4 >> 0xf)) < 4) &&
     ((int)((uStack_10 ^ (int)uStack_10 >> 0xf) - ((int)uStack_10 >> 0xf)) < 4)) {
    ovr_OVC41_6a8f_297d(iVar7,uVar10,*(undefined1 *)(iVar7 + 0xc));
    DAT_2410_07e2 = 3;
    agnt_3b1d_0a53(iVar7,uVar10);
  }
  else {
    uVar11 = (undefined2)((ulong)param_2 >> 0x10);
    iVar9 = (int)param_2;
    if (-uStack_10 == *(int *)(iVar9 + 0x11) || -*(int *)(iVar9 + 0x11) < (int)uStack_10) {
      if (*(int *)(iVar9 + 0x11) < (int)uStack_10) {
        uStack_10 = *(uint *)(iVar9 + 0x11);
      }
    }
    else {
      uStack_10 = -*(int *)(iVar9 + 0x11);
    }
    uVar12 = (undefined2)((ulong)param_3 >> 0x10);
    if (*(char *)((int)param_3 + 5) != '\0') {
      *(char *)(iVar7 + 10) = *(char *)(iVar7 + 10) + (char)uStack_10;
    }
    if (*(int *)(iVar9 + 0xf) < (int)uVar4) {
      uVar4 = *(uint *)(iVar9 + 0xf);
    }
    else if (-uVar4 != *(int *)(iVar9 + 0xf) && (int)uVar4 <= -*(int *)(iVar9 + 0xf)) {
      uVar4 = -*(int *)(iVar9 + 0xf);
    }
    if (((*(byte *)(iVar9 + 0x1c) & 4) == 0) &&
       (((*(int *)(iVar3 + 0x28) - (uint)*(byte *)(iVar7 + 10) != *(int *)(iVar2 + 0xd) >> 1 ||
         ((*(char *)(iVar7 + 0xb) == '\0' && ((int)uVar4 < 0)))) ||
        ((*(char *)(iVar7 + 0xb) != '\0' && (0 < (int)uVar4)))))) {
      if (*(char *)(iVar7 + 0xb) == '\0') {
        uVar4 = *(uint *)(iVar9 + 0xf);
      }
      else {
        uVar4 = -*(int *)(iVar9 + 0xf);
      }
    }
    if (*(char *)((int)param_3 + 5) != '\0') {
      *(int *)(iVar7 + 8) = *(int *)(iVar7 + 8) + uVar4;
    }
    uVar4 = *(int *)(iVar3 + 0x26) - *(int *)(iVar7 + 8);
    uVar5 = (*(int *)(iVar3 + 0x28) - (uint)*(byte *)(iVar7 + 10)) - (*(int *)(iVar2 + 0xd) >> 1);
    uVar6 = (int)uVar4 >> 0xf;
    if (((int)((uVar4 ^ uVar6) - uVar6) < 4) &&
       (uVar4 = (int)uVar5 >> 0xf, (int)((uVar5 ^ uVar4) - uVar4) < 4)) {
      ovr_OVC41_6a8f_297d(iVar7,uVar10,*(undefined1 *)(iVar7 + 0xc));
      DAT_2410_07e2 = 5;
      agnt_3b1d_0a53(iVar7,uVar10);
    }
    else if ((*(int *)(iVar7 + 8) < -0xe) || (0xe0 < *(int *)(iVar7 + 8))) {
      DAT_2410_07e2 = 4;
      agnt_3b1d_0a53(iVar7,uVar10);
    }
    else {
      *(char *)(iVar7 + 0xe) = *(char *)(iVar7 + 0xe) + '\x01';
      if (*(byte *)(iVar9 + 0x1b) <= *(byte *)(iVar7 + 0xe)) {
        if (*(char *)(iVar9 + 0x1a) == -1) {
          agnt_3b1d_0a53(iVar7,uVar10);
          DAT_2410_07e2 = 6;
        }
        else {
          *(undefined1 *)(iVar7 + 0xe) = *(undefined1 *)(iVar9 + 0x1a);
        }
      }
    }
  }
  return;
}



/* 3b1d:1035 */

void __cdecl16far agnt_3b1d_1035(byte param_1,brect_t *param_2,undefined2 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int16_t y;
  uint16_t uVar7;
  int *piVar8;
  far_t gfx;
  uint16_t uStack_e;
  uint16_t uStack_c;
  
  iVar5 = (uint)param_1 * 0x34;
  uStack_c = *(uint16_t *)(iVar5 + 0x15);
  uStack_e = *(uint16_t *)(iVar5 + 0x13);
  piVar8 = (int *)(uStack_e + (uint)*(byte *)(iVar5 + 0x12) * 4);
  iVar1 = piVar8[1];
  iVar2 = *piVar8;
  piVar8 = (int *)(uStack_e + (uint)*(byte *)(iVar5 + 0x30) * 4);
  if (*piVar8 == 0 && piVar8[1] == 0) {
    uStack_e = SprProjectiles.ofs;
    uStack_c = SprProjectiles.seg;
  }
  piVar8 = (int *)(uStack_e + (uint)*(byte *)(iVar5 + 0x30) * 4);
  iVar3 = piVar8[1];
  iVar4 = *piVar8;
  uVar7 = 0x1726;
  iVar6 = ovr_stash_474a_10ac();
  if (*(char *)(iVar5 + 0x30) == '\r') {
    y = *(int16_t *)(iVar5 + 0x28);
  }
  else if (*(char *)(iVar5 + 0x30) == '\f') {
    y = *(int *)(iVar5 + 0x28) - *(int *)(iVar2 + 0xd);
  }
  else {
    y = *(int *)(iVar5 + 0x28) - (*(int *)(iVar2 + 0xd) >> 1);
  }
  gfx.seg = uVar7;
  gfx.ofs = iVar6 + 6;
  ovr_blitGfxRect(gfx,*(int16_t *)(iVar5 + 0x26),y,(brect_t *)CONCAT22(param_3,param_2),0x10,
                  *(bool *)(iVar5 + 0x33));
  *(char *)(iVar5 + 0x31) = *(char *)(iVar5 + 0x31) + '\x01';
  if (*(byte *)(iVar4 + 0x1b) <= *(byte *)(iVar5 + 0x31)) {
    if (*(char *)(iVar4 + 0x1a) == -1) {
      *(undefined1 *)(iVar5 + 0x30) = 0;
    }
    else {
      *(undefined1 *)(iVar5 + 0x31) = *(undefined1 *)(iVar4 + 0x1a);
    }
  }
  agnt_3b1d_11c1(iVar5,0x1726);
  return;
}



/* 3b1d:11c1 */

void __cdecl16far agnt_3b1d_11c1(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(char *)(iVar1 + 0x30) == '\0') {
    if ((*(uint *)(iVar1 + 0x2b) & 0x100) == 0) {
      if ((*(uint *)(iVar1 + 0x2b) & 0x80) != 0) {
        *(undefined1 *)(iVar1 + 0x30) = 0xc;
        *(undefined1 *)(iVar1 + 0x31) = 0;
      }
    }
    else {
      *(undefined1 *)(iVar1 + 0x30) = 0xd;
      *(undefined1 *)(iVar1 + 0x31) = 5;
    }
  }
  return;
}



/* 3b1d:120b */

void __cdecl16far agnt_3b1d_120b(uint param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined2 uStack_4;
  
  if ((int)param_1 < param_2) {
    for (iVar3 = 0; iVar3 < 10; iVar3 = iVar3 + 1) {
      for (iVar2 = 0; iVar2 < 0x69; iVar2 = iVar2 + 1) {
        if (((int)(param_1 + 1) < (int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x8fa)) &&
           ((int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x8fa) <= param_2 + 1)) {
          pcVar1 = (char *)(iVar3 * 0x69 + iVar2 + 0x8fa);
          *pcVar1 = *pcVar1 + -1;
        }
        else if ((uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x8fa) == param_1 + 1) {
          *(char *)(iVar3 * 0x69 + iVar2 + 0x8fa) = (char)param_2 + '\x01';
        }
        if (((int)(param_1 + 1) < (int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x4e0)) &&
           ((int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x4e0) <= param_2 + 1)) {
          pcVar1 = (char *)(iVar3 * 0x69 + iVar2 + 0x4e0);
          *pcVar1 = *pcVar1 + -1;
        }
        else if ((uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x4e0) == param_1 + 1) {
          *(char *)(iVar3 * 0x69 + iVar2 + 0x4e0) = (char)param_2 + '\x01';
        }
      }
    }
    for (uStack_4 = 0; uStack_4 < (int)(uint)AgntCount; uStack_4 = uStack_4 + 1) {
      if (*(char *)(uStack_4 * 0x34 + 0xc) != -1) {
        if (((int)param_1 < (int)(uint)*(byte *)(uStack_4 * 0x34 + 0xc)) &&
           ((int)(uint)*(byte *)(uStack_4 * 0x34 + 0xc) <= param_2)) {
          pcVar1 = (char *)(uStack_4 * 0x34 + 0xc);
          *pcVar1 = *pcVar1 + -1;
        }
        else if (*(byte *)(uStack_4 * 0x34 + 0xc) == param_1) {
          *(char *)(uStack_4 * 0x34 + 0xc) = (char)param_2;
        }
      }
    }
  }
  else {
    for (iVar3 = 0; iVar3 < 10; iVar3 = iVar3 + 1) {
      for (iVar2 = 0; iVar2 < 0x69; iVar2 = iVar2 + 1) {
        if (((int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x8fa) < param_2 + 1) ||
           ((int)(param_1 + 1) <= (int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x8fa))) {
          if ((uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x8fa) == param_1 + 1) {
            *(char *)(iVar3 * 0x69 + iVar2 + 0x8fa) = (char)param_2 + '\x01';
          }
        }
        else {
          pcVar1 = (char *)(iVar3 * 0x69 + iVar2 + 0x8fa);
          *pcVar1 = *pcVar1 + '\x01';
        }
        if (((int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x4e0) < param_2 + 1) ||
           ((int)(param_1 + 1) <= (int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x4e0))) {
          if ((uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x4e0) == param_1 + 1) {
            *(char *)(iVar3 * 0x69 + iVar2 + 0x4e0) = (char)param_2 + '\x01';
          }
        }
        else {
          pcVar1 = (char *)(iVar3 * 0x69 + iVar2 + 0x4e0);
          *pcVar1 = *pcVar1 + '\x01';
        }
      }
    }
    for (uStack_4 = 0; uStack_4 < (int)(uint)AgntCount; uStack_4 = uStack_4 + 1) {
      if (*(char *)(uStack_4 * 0x34 + 0xc) != -1) {
        if (((int)(uint)*(byte *)(uStack_4 * 0x34 + 0xc) < param_2) ||
           ((int)param_1 <= (int)(uint)*(byte *)(uStack_4 * 0x34 + 0xc))) {
          if (*(byte *)(uStack_4 * 0x34 + 0xc) == param_1) {
            *(char *)(uStack_4 * 0x34 + 0xc) = (char)param_2;
          }
        }
        else {
          pcVar1 = (char *)(uStack_4 * 0x34 + 0xc);
          *pcVar1 = *pcVar1 + '\x01';
        }
      }
    }
  }
  return;
}



/* 3b1d:15bd */

void __cdecl16far agnt_3b1d_15bd(uint param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  for (iVar3 = 0; iVar3 < 10; iVar3 = iVar3 + 1) {
    for (iVar2 = 0; iVar2 < 0x69; iVar2 = iVar2 + 1) {
      if ((AgntCount < *(byte *)(iVar3 * 0x69 + iVar2 + 0x8fa)) ||
         ((int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x8fa) <= (int)param_1)) {
        if (*(byte *)(iVar3 * 0x69 + iVar2 + 0x8fa) == param_1) {
          *(undefined1 *)(iVar3 * 0x69 + iVar2 + 0x8fa) = 0;
        }
      }
      else {
        pcVar1 = (char *)(iVar3 * 0x69 + iVar2 + 0x8fa);
        *pcVar1 = *pcVar1 + -1;
      }
      if ((AgntCount < *(byte *)(iVar3 * 0x69 + iVar2 + 0x4e0)) ||
         ((int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x4e0) <= (int)param_1)) {
        if (*(byte *)(iVar3 * 0x69 + iVar2 + 0x4e0) == param_1) {
          *(undefined1 *)(iVar3 * 0x69 + iVar2 + 0x4e0) = 0;
        }
      }
      else {
        pcVar1 = (char *)(iVar3 * 0x69 + iVar2 + 0x4e0);
        *pcVar1 = *pcVar1 + -1;
      }
    }
  }
  return;
}



/* 3b1d:16cd */

void __cdecl16far agnt_3b1d_16cd(int param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  for (iVar3 = 0; iVar3 < 10; iVar3 = iVar3 + 1) {
    for (iVar2 = 0; iVar2 < 0x69; iVar2 = iVar2 + 1) {
      if ((*(byte *)(iVar3 * 0x69 + iVar2 + 0x8fa) <= AgntCount) &&
         (param_1 <= (int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x8fa))) {
        pcVar1 = (char *)(iVar3 * 0x69 + iVar2 + 0x8fa);
        *pcVar1 = *pcVar1 + '\x01';
      }
      if ((*(byte *)(iVar3 * 0x69 + iVar2 + 0x4e0) <= AgntCount) &&
         (param_1 <= (int)(uint)*(byte *)(iVar3 * 0x69 + iVar2 + 0x4e0))) {
        pcVar1 = (char *)(iVar3 * 0x69 + iVar2 + 0x4e0);
        *pcVar1 = *pcVar1 + '\x01';
      }
    }
  }
  return;
}



/* 3b1d:177f */

undefined2 __cdecl16far agnt_3b1d_177f(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  uint8_t local_36 [52];
  
  if ((param_1 < 1) ||
     (iVar2 = param_1, *(int *)(param_1 * 0x34 + -0x32) <= *(int *)(param_1 * 0x34 + 2))) {
    if ((param_1 + 1 < (int)(uint)AgntCount) &&
       (iVar2 = param_1, *(int *)(param_1 * 0x34 + 0x36) < *(int *)(param_1 * 0x34 + 2))) {
      do {
        iVar3 = iVar2 + 1;
        if ((int)(uint)AgntCount <= iVar2 + 2) break;
        iVar2 = iVar3;
      } while (*(int *)(iVar3 * 0x34 + 0x36) < *(int *)(param_1 * 0x34 + 2));
      memcpy(local_36,(uint8_t *)(param_1 * 0x34),0x34);
      _fmemmove((uint8_t *)(param_1 * 0x34),(uint8_t *)(param_1 * 0x34 + 0x34),
                (iVar3 - param_1) * 0x34);
      memcpy((uint8_t *)(iVar3 * 0x34),local_36,0x34);
      agnt_3b1d_120b(param_1,iVar3);
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    do {
      iVar2 = iVar2 + -1;
      if (iVar2 < 1) break;
    } while (*(int *)(param_1 * 0x34 + 2) < *(int *)(iVar2 * 0x34 + -0x32));
    memcpy(local_36,(uint8_t *)(param_1 * 0x34),0x34);
    _fmemmove((uint8_t *)(iVar2 * 0x34 + 0x34),(uint8_t *)(iVar2 * 0x34),(param_1 - iVar2) * 0x34);
    memcpy((uint8_t *)(iVar2 * 0x34),local_36,0x34);
    agnt_3b1d_120b(param_1,iVar2);
    uVar1 = 0;
  }
  return uVar1;
}



/* 3b1d:196b */

void __cdecl16far agnt_3b1d_196b(far_t ptr)

{
  int i;
  
  for (i = 0; i < (int)(uint)AgntCount; i = i + 1) {
    if ((*(uint16_t *)(i * 0x34 + 0x19) == ptr.seg) && (*(uint16_t *)(i * 0x34 + 0x17) == ptr.ofs))
    {
      if (*(byte *)(i * 0x34 + 0x25) < 2) {
        *(undefined1 *)(i * 0x34 + 0x25) = 1;
      }
      *(undefined1 *)(i * 0x34 + 4) = 0;
    }
  }
  return;
}



/* 3b1d:19e0 */

void __cdecl16far agnt_3b1d_19e0(void)

{
  bool bVar1;
  far_t fVar2;
  far_t fVar3;
  far_t handle;
  
  if (DAT_2410_07e3 != 0 || DAT_2410_07e5 != 0) {
    fVar2.seg = DAT_2410_07e5;
    fVar2.ofs = DAT_2410_07e3;
    ovr_stshFree(fVar2);
  }
  if (DAT_2410_07e7 != 0 || DAT_2410_07e9 != 0) {
    handle.seg = DAT_2410_07e9;
    handle.ofs = DAT_2410_07e7;
    ovr_stshFree(handle);
  }
  GGameState = 0x28;
  if (GameRunning == false) {
    ovr_fmFreeAudio(1);
  }
  else {
    ovr_fmFreeAudio(0);
  }
  fVar2 = ovr_stshRleCut((far_t)((ulong)BlitRects[0].seg << 0x10),12,7,222,77);
  DAT_2410_07e5 = fVar2.seg;
  DAT_2410_07e3 = fVar2.ofs;
  fVar3 = ovr_stshRleCut((far_t)((ulong)BlitRects[0].seg << 0x10),12,78,222,150);
  DAT_2410_07e9 = fVar3.seg;
  DAT_2410_07e7 = fVar3.ofs;
  GGameState = 0x29;
  if (AgntFlag2 != false) {
    ovr_OVC15_4207_0bb7();
    fVar3.seg = DAT_2410_07e9;
    fVar3.ofs = DAT_2410_07e7;
  }
  DAT_2410_07e9 = fVar3.seg;
  DAT_2410_07e7 = fVar3.ofs;
  AgntFlag2 = false;
  DAT_2000_d0f7 = BlitRects[0].seg;
  GGameState = 0x2a;
  ovr_OVC49_8699_1e09();
  bVar1 = agnt_3b1d_0000();
  if (bVar1) {
    DAT_2000_d0f6 = 1;
  }
  return;
}



/* 3b1d:1ad8 */

void __cdecl16far agnt_3b1d_1ad8(void)

{
  bool bVar1;
  undefined2 unaff_SS;
  far_t fVar2;
  brect_t local_c;
  
  F_SCOPY((uint8_t *)&local_c,(uint8_t *)0x7ec,10);
  DAT_2000_d0fd = '\0';
  bVar1 = agnt_3b1d_0000();
  if (bVar1) {
    DAT_2000_d0f6 = '\x01';
  }
  if (((DAT_2000_d0f6 != '\0') && (GOngoingBattle == '\0')) &&
     (DAT_2410_07f6 = DAT_2410_07f6 + 1, 2 < DAT_2410_07f6)) {
    fVar2 = (far_t)ovr_stshAlloc(0xfa0f);
    DAT_2000_d0fb = fVar2.seg;
    DAT_2000_d0f9 = fVar2.ofs;
    fVar2 = ovr_alignToSeg(fVar2);
    DAT_2000_d0f7 = fVar2.seg;
    local_c.seg = DAT_2000_d0f7;
    bVar1 = agnt_3b1d_0000();
    if (!bVar1) {
      DAT_2000_d0f6 = '\0';
    }
    ovr_OVC49_8699_1e09();
    DAT_2410_07f6 = 0;
    agnt_3b1d_1d0c();
    ovr_miceBlitRect((brect_t *)CONCAT22(unaff_SS,&local_c));
    ovr_blitRaw(0xc,7,0xde,0x96,DAT_2000_d0f7,0xa000);
    ovr_miceUpdate();
    fVar2.seg = DAT_2000_d0fb;
    fVar2.ofs = DAT_2000_d0f9;
    ovr_stshFree(fVar2);
    if (DAT_2000_d0fd != '\0') {
      ovr_constr_36ce_03a6();
    }
  }
  return;
}



/* 3b1d:1bc1 */

byte __cdecl16far agnt_3b1d_1bc1(byte param_1)

{
  if (8 < param_1) {
    if ((param_1 < 9) || (0x10 < param_1)) {
      param_1 = (char)((int)(param_1 - 0x11) >> 2) + 0xd;
    }
    else {
      param_1 = (char)((int)(param_1 - 9) >> 1) + 9;
    }
  }
  return param_1;
}



/* 3b1d:1bf5 */

int __cdecl16far agnt_3b1d_1bf5(byte param_1,undefined1 param_2)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    bVar1 = agnt_3b1d_1bc1(param_2);
    bVar3 = (byte)(bVar1 + 2 >> 8);
    if (bVar1 + 2 < (uint)param_1) {
      iVar2 = (uint)bVar3 << 8;
    }
    else {
      iVar2 = CONCAT11(bVar3,1);
    }
  }
  return iVar2;
}



/* 3b1d:1c26 */

undefined2 __cdecl16far agnt_3b1d_1c26(undefined4 param_1,char *param_2)

{
  undefined4 uVar1;
  char cVar2;
  uint16_t unk;
  int iVar3;
  undefined2 uVar4;
  int iStack_4;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  if ((*(uint *)(iVar3 + 0x2b) & 1) == 0) {
    for (iStack_4 = 0; iStack_4 < (int)(uint)AgntCount; iStack_4 = iStack_4 + 1) {
      if ((((*(char *)(iStack_4 * 0x34 + 0x2f) != *(char *)(iVar3 + 0x2f)) &&
           ((*(uint *)(iStack_4 * 0x34 + 0x2b) & 0xae4) == 0)) &&
          (*(char *)(iStack_4 * 0x34 + 0x24) == '\0')) &&
         (uVar1 = *(undefined4 *)(iStack_4 * 0x34 + 0x1d),
         cVar2 = agnt_3b1d_1bf5(CONCAT11((char)((uint)(iStack_4 * 0x34) >> 8),
                                         *(undefined1 *)((int)uVar1 + 0x42)),
                                *(undefined1 *)((int)*(undefined4 *)(iVar3 + 0x17) + 0xf)),
         cVar2 != '\0')) {
        *(uint *)(iVar3 + 0x2b) = *(uint *)(iVar3 + 0x2b) | 3;
        *param_2 = (char)iStack_4 + '\x01';
        unk = ovr_audio_3a5b_0afd(iVar3,uVar4);
        ovr_play_sfxU(0x3b,0,unk);
        return 1;
      }
    }
  }
  return 0;
}



/* 3b1d:1d0c */

void __cdecl16far agnt_3b1d_1d0c(void)

{
  far_t gfx;
  far_t dst;
  
  if (((CrossBlitFlag != '\0') && (CrossBlitCount != 0)) && (CrossBlitCount < 5)) {
    dst.seg = DAT_2000_d0f7;
    dst.ofs = CrossBlitX + CrossBlitY * 0x140;
    gfx.seg = *(uint16_t *)((uint)CrossBlitCount * 4 + -0x748d);
    gfx.ofs = *(uint16_t *)((uint)CrossBlitCount * 4 + -0x748f);
    ovr_blitLoadRleGfx(gfx,dst);
    CrossBlitCount = CrossBlitCount + 1;
    if (4 < CrossBlitCount) {
      CrossBlitCount = 0;
    }
  }
  return;
}



/* 3b1d:1da5 */

undefined1 __cdecl16far agnt_3b1d_1da5(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 uVar2;
  char cVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  uVar1 = *(undefined4 *)((int)param_1 + 0x1d);
  if ((*(uint *)((int)uVar1 + 0x3c) & 2) == 0) {
    uVar2 = 1;
  }
  else {
    cVar3 = agnt_3b1d_0c9f((int)param_1,uVar4);
    uVar4 = (undefined2)((ulong)param_2 >> 0x10);
    uVar1 = *(undefined4 *)((int)param_2 + 0x1d);
    if (((*(uint *)((int)uVar1 + 0x40) & 0x40) == 0) || ('\x01' < cVar3)) {
      uVar1 = *(undefined4 *)((int)param_2 + 0x1d);
      if (((*(uint *)((int)uVar1 + 0x3e) & 8) == 0) || ('\0' < cVar3)) {
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


