/*
 * ovc49.c - recovered from STRONG.EXE
 * memory block: OVC49
 * range: 8699:0000 - 8699:441f
 * functions: 9
 */
#include "recovered.h"


/* 8699:0000 */

undefined1 __cdecl16far OVC49_8699_0000(int *param_1,undefined1 *param_2)

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
  if (*(char *)((int)*(undefined4 *)((int)piVar5 + 0x1d) + 0x1f) == '\0') {
    *param_2 = 0;
  }
  else {
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
      iStack_a = ((int)*(char *)((int)*(undefined4 *)((int)piVar5 + 0x1d) + 0x1e) +
                  *(int *)(iVar2 + 0x17) + *param_1 >> 1) + -1;
      iStack_c = iStack_a +
                 ((int)*(char *)((int)*(undefined4 *)((int)piVar5 + 0x1d) + 0x1f) -
                  (int)*(char *)((int)*(undefined4 *)((int)piVar5 + 0x1d) + 0x1e) >> 1);
    }
    else {
      cStack_d = -1;
      iStack_a = ((-*(int *)(iVar2 + 0x17) -
                  (int)*(char *)((int)*(undefined4 *)((int)piVar5 + 0x1d) + 0x1e)) + *param_1 >> 1)
                 + 1;
      iStack_c = iStack_a -
                 ((int)*(char *)((int)*(undefined4 *)((int)piVar5 + 0x1d) + 0x1f) -
                  (int)*(char *)((int)*(undefined4 *)((int)piVar5 + 0x1d) + 0x1e) >> 1);
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
          iStack_8 <= (int)*(char *)((int)*(undefined4 *)((int)piVar5 + 0x1d) + 0x20) >> 1;
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
              cVar3 = ovr_agnt_3b1d_00b7((undefined1 *)param_2,(*(uint16_t *)((uint8_t *)&(param_2) + 2)));
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
    }
    *param_2 = 0;
  }
  return 0;
}



/* 8699:036e */

undefined1 __cdecl16far OVC49_8699_036e(int *param_1,undefined1 *param_2)

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
  if (*(char *)((int)*(undefined4 *)((int)piVar5 + 0x1d) + 0x1c) == '\0') {
    *param_2 = 0;
  }
  else {
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
      iStack_a = ((int)*(char *)((int)*(undefined4 *)((int)piVar5 + 0x1d) + 0x1b) +
                  *(int *)(iVar2 + 0x17) + *param_1 >> 1) + -1;
      iStack_c = iStack_a +
                 ((int)*(char *)((int)*(undefined4 *)((int)piVar5 + 0x1d) + 0x1c) -
                  (int)*(char *)((int)*(undefined4 *)((int)piVar5 + 0x1d) + 0x1b) >> 1);
    }
    else {
      cStack_d = -1;
      iStack_a = ((-*(int *)(iVar2 + 0x17) -
                  (int)*(char *)((int)*(undefined4 *)((int)piVar5 + 0x1d) + 0x1b)) + *param_1 >> 1)
                 + 1;
      iStack_c = iStack_a -
                 ((int)*(char *)((int)*(undefined4 *)((int)piVar5 + 0x1d) + 0x1c) -
                  (int)*(char *)((int)*(undefined4 *)((int)piVar5 + 0x1d) + 0x1b) >> 1);
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
          iStack_8 <= (int)*(char *)((int)*(undefined4 *)((int)piVar5 + 0x1d) + 0x1d) >> 1;
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
              cVar3 = ovr_agnt_3b1d_00b7((undefined1 *)param_2,(*(uint16_t *)((uint8_t *)&(param_2) + 2)));
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
    }
    *param_2 = 0;
  }
  return 0;
}



/* 8699:06dc */

int __cdecl16far OVC49_8699_06dc(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte bVar5;
  uint uVar4;
  int *piVar6;
  int *piVar7;
  undefined2 uVar8;
  int iStack_6;
  int iStack_4;
  
  uVar8 = (undefined2)((ulong)param_1 >> 0x10);
  piVar6 = (int *)param_1;
  piVar7 = (int *)(*(int *)((int)piVar6 + 0x13) + (uint)*(byte *)(piVar6 + 9) * 4);
  iVar3 = piVar7[1];
  iVar1 = *piVar7;
  iVar2 = piVar6[1] >> 1;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  if (7 < iVar2) {
    iVar2 = 7;
  }
  iStack_4 = *param_1 - *(int *)(iVar1 + 0x17) >> 1;
  iStack_6 = *param_1 + *(int *)(iVar1 + 0x17) >> 1;
  if (iStack_4 < 0) {
    iStack_4 = 0;
  }
  if (iStack_6 < 0) {
    iStack_6 = 0;
  }
  if (0x68 < iStack_4) {
    iStack_4 = 0x68;
  }
  if (0x68 < iStack_6) {
    iStack_6 = 0x68;
  }
  if (iStack_6 < iStack_4) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x1e);
  }
  uVar4 = (uint)*(byte *)((int)piVar6 + 0x11);
  if (uVar4 == 0) {
    iVar3 = 0;
    for (; bVar5 = (byte)((uint)iVar3 >> 8), iStack_4 <= iStack_6; iStack_4 = iStack_4 + 1) {
      if (*(char *)(iVar2 * 0x69 + iStack_4 + 0x8fa) != '\0') {
        return CONCAT11((char)((uint)(iVar2 * 0x69) >> 8),1);
      }
      iVar3 = iVar2 * 0x69;
      if (*(char *)(iVar3 + iStack_4 + 0x963) != '\0') {
        return CONCAT11((char)((uint)iVar3 >> 8),1);
      }
    }
  }
  else {
    for (; bVar5 = (byte)(uVar4 >> 8), iStack_4 <= iStack_6; iStack_4 = iStack_4 + 1) {
      if (*(char *)(iVar2 * 0x69 + iStack_4 + 0x4e0) != '\0') {
        return CONCAT11((char)((uint)(iVar2 * 0x69) >> 8),1);
      }
      if (*(char *)(iVar2 * 0x69 + iStack_4 + 0x549) != '\0') {
        return CONCAT11((char)((uint)(iVar2 * 0x69) >> 8),1);
      }
      uVar4 = iVar2 * 0x69;
      if (*(char *)(uVar4 + iStack_4 + 0x5b2) != '\0') {
        return CONCAT11((char)(uVar4 >> 8),1);
      }
    }
  }
  return (uint)bVar5 << 8;
}



/* 8699:0849 */

uint __cdecl16far OVC49_8699_0849(int param_1)

{
  uint in_AX;
  uint uVar1;
  
  if ((param_1 < 0) || (0xd2 < param_1)) {
    uVar1 = in_AX & 0xff00;
  }
  else {
    uVar1 = (uint)(*(int *)(param_1 * 2) == 0);
  }
  return uVar1;
}



/* 8699:0874 */

void __cdecl16far OVC49_8699_0874(int *param_1,byte param_2)

{
  undefined4 uVar1;
  char cVar2;
  uint16_t uVar3;
  undefined2 uVar4;
  char *pcVar5;
  uint uVar6;
  int *piVar7;
  undefined2 uVar8;
  char *pcVar9;
  undefined1 local_aa [80];
  char local_5a [80];
  undefined1 local_a;
  int local_8;
  byte local_5;
  uint local_4;
  
  uVar8 = (undefined2)((ulong)param_1 >> 0x10);
  piVar7 = (int *)param_1;
  if (((char)piVar7[0x12] == '\0') && ((char)piVar7[7] == -1)) {
    if (((*(uint *)((int)piVar7 + 0x2b) & 0x200) != 0) &&
       (uVar3 = ovr_randBelow(0xc), (uVar3 & 0xff) == 0)) {
      *(uint *)((int)piVar7 + 0x2b) = *(uint *)((int)piVar7 + 0x2b) & 0xfdff;
      uVar3 = DAT_2000_d0f7;
      uVar4 = ovr_agnt_3b1d_0ac0(piVar7,uVar8,local_aa);
      pcVar5 = (char *)ovr_OVC15_4207_1c16(uVar4);
      pcVar9 = ovr_stsprintf(local_5a,"%s is no longer paralyzed.",pcVar5);
      ovr_uiNotify(pcVar9,uVar3);
      ovr_OVC41_6a8f_0246();
      ovr_attact_3f0b_2a09();
    }
    if (((*(uint *)((int)piVar7 + 0x2b) & 0x100) != 0) &&
       ((uVar3 = ovr_randBelow(0x40), (uVar3 & 0xff) == 0 ||
        (((*(uint *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x40) & 0x2000) != 0 &&
         (uVar3 = ovr_randBelow(0x20), (uVar3 & 0xff) == 0)))))) {
      *(uint *)((int)piVar7 + 0x2b) = *(uint *)((int)piVar7 + 0x2b) & 0xfeff;
      uVar3 = DAT_2000_d0f7;
      uVar4 = ovr_agnt_3b1d_0ac0(piVar7,uVar8,local_aa);
      pcVar5 = (char *)ovr_OVC15_4207_1c16(uVar4);
      pcVar9 = ovr_stsprintf(local_5a,"%s breaks free of the web.",pcVar5);
      ovr_uiNotify(pcVar9,uVar3);
      *(undefined1 *)(piVar7 + 0x18) = 0;
      ovr_agnt_3b1d_11c1();
      ovr_attact_3f0b_2a09();
    }
    if ((*(uint *)((int)piVar7 + 0x2b) & 0xbc0) == 0) {
      if (((*(char *)((int)piVar7 + 5) < '\0') || (piVar7[1] < 0x15)) ||
         (cVar2 = OVC49_8699_1711(), cVar2 != '\0')) {
        cVar2 = OVC49_8699_1711();
        if (cVar2 == '\0') {
          if ((*(char *)((int)piVar7 + 0x11) == '\0') ||
             (cVar2 = ovr_agnt_3b1d_0d1c(), cVar2 == '\0')) {
            if ((((*(char *)((int)piVar7 + 0x11) == '\0') &&
                 (cVar2 = ovr_agnt_3b1d_0d1c(), cVar2 != '\0')) &&
                (*(char *)((int)piVar7 + 0x25) == '\0')) && ((char)piVar7[7] == -1)) {
              if ((((*(uint *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x3c) & 1) == 0) ||
                  (cVar2 = ovr_OVC27_5ded_04cd(piVar7,uVar8,2), cVar2 == '\0')) ||
                 (cVar2 = ovr_agnt_3b1d_1c26(piVar7,uVar8), cVar2 == '\0')) {
                if ((((*(uint *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x3c) & 1) == 0) ||
                    (*(byte *)((int)*(undefined4 *)((int)piVar7 + 0x17) + 0xf) < 2)) ||
                   ((cVar2 = ovr_OVC27_5ded_04cd(piVar7,uVar8,2), cVar2 == '\0' ||
                    (cVar2 = ovr_agnt_3b1d_0426(piVar7,uVar8,&local_5), cVar2 == '\0')))) {
                  if (((((*(uint *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x3c) & 0x400) == 0)
                       || (0x14 < piVar7[1])) ||
                      (cVar2 = OVC49_8699_0000(piVar7,uVar8), cVar2 == '\0')) ||
                     ((0x14 < *(int *)((uint)local_5 * 0x34 + -0x32) ||
                      (cVar2 = ovr_OVC27_5ded_07d0(piVar7,uVar8,local_5 - 1), cVar2 == '\0')))) {
                    if ((piVar7[1] < 0x15) &&
                       (cVar2 = ovr_OVC27_5ded_04cd(piVar7,uVar8,3), cVar2 != '\0')) {
                      cVar2 = OVC49_8699_036e(piVar7,uVar8,&local_5);
                      if ((cVar2 == '\0') || (0x14 < *(int *)((uint)local_5 * 0x34 + -0x32))) {
                        if ((((((*(uint *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x3e) & 1) ==
                                0) || (cVar2 = ovr_agnt_3b1d_00ce(piVar7,uVar8,&local_5),
                                      cVar2 == '\0')) ||
                             (0x14 < *(int *)((uint)local_5 * 0x34 + -0x32))) ||
                            (((*(uint *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x40) & 0x400)
                              != 0 && (uVar3 = ovr_randBelow(0x14), (uVar3 & 0xff) != 0)))) ||
                           (cVar2 = ovr_agnt_3b1d_1da5(piVar7,uVar8,(uint)local_5 * 0x34 + -0x34,
                                                       0x1726), cVar2 == '\0')) {
                          if (((((*(uint *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x3e) & 0x200
                                 ) == 0) ||
                               (cVar2 = ovr_agnt_3b1d_00ce(piVar7,uVar8,&local_5), cVar2 == '\0'))
                              || (((*(uint *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x40) &
                                   0x400) != 0 && (uVar3 = ovr_randBelow(0x14), (uVar3 & 0xff) != 0)
                                  ))) || (0x14 < *(int *)((uint)local_5 * 0x34 + -0x32))) {
                            if ((((*(uint *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x40) & 1)
                                  != 0) &&
                                (cVar2 = ovr_agnt_3b1d_00ce(piVar7,uVar8,&local_5), cVar2 != '\0'))
                               && (*(int *)((uint)local_5 * 0x34 + -0x32) < 0x15)) {
                              *(undefined1 *)(piVar7 + 8) = 2;
                              piVar7[3] = 0;
                              *(byte *)(piVar7 + 6) = local_5 - 1;
                              *(undefined1 *)((int)piVar7 + 0xd) = 5;
                            }
                          }
                          else {
                            *(undefined1 *)(piVar7 + 8) = 2;
                            piVar7[3] = 0;
                            *(byte *)(piVar7 + 6) = local_5 - 1;
                            *(undefined1 *)((int)piVar7 + 0xd) = 4;
                          }
                        }
                        else {
                          *(undefined1 *)(piVar7 + 8) = 2;
                          piVar7[3] = 0;
                          *(byte *)(piVar7 + 6) = local_5 - 1;
                          *(undefined1 *)((int)piVar7 + 0xd) = 2;
                        }
                      }
                      else {
                        *(undefined1 *)(piVar7 + 8) = 2;
                        piVar7[3] = 0;
                        *(byte *)(piVar7 + 6) = local_5 - 1;
                        *(undefined1 *)((int)piVar7 + 0xd) = 0;
                      }
                    }
                    else if (((piVar7[1] < 0x15) &&
                             (uVar3 = ovr_randBelow(0x20), (uVar3 & 0xff) == 0)) &&
                            (((*(uint *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x3c) & 0x4000)
                              != 0 && (((char)piVar7[8] != '\x04' &&
                                       (*(char *)((int)*(undefined4 *)((int)piVar7 + 0x17) + 0x18)
                                        != '\0')))))) {
                      *(undefined1 *)(piVar7 + 8) = 4;
                      piVar7[3] = 0;
                      uVar3 = ovr_audio_3a5b_0afd();
                      ovr_play_sfxU(0x32,0,uVar3);
                    }
                    else if ((((piVar7[1] < 0x15) && (uVar3 = ovr_randBelow(8), (uVar3 & 0xff) == 0)
                              ) && ((*(uint *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x3e) &
                                    0x40) != 0)) &&
                            ((((char)piVar7[8] != '\x05' &&
                              (cVar2 = OVC49_8699_0000(piVar7,uVar8), cVar2 != '\0')) &&
                             (uVar1 = *(undefined4 *)((uint)local_5 * 0x34 + -0x17),
                             (*(uint *)((int)uVar1 + 0x3e) & 0x80) != 0)))) {
                      uVar3 = ovr_audio_3a5b_0afd();
                      ovr_play_sfxU(0x1e,0,uVar3);
                      *(byte *)(piVar7 + 6) = local_5 - 1;
                      *(undefined1 *)(piVar7 + 8) = 5;
                      piVar7[3] = 0;
                    }
                    else if (((piVar7[1] < 0x15) &&
                             ((*(uint *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x3e) & 0x100)
                              != 0)) &&
                            (((char)piVar7[8] != '\x06' &&
                             ((((cVar2 = OVC49_8699_0000(piVar7,uVar8), cVar2 != '\0' &&
                                (cVar2 = ovr_agnt_3b1d_0d4d(piVar7,uVar8,
                                                            (uint)local_5 * 0x34 + -0x34,0x1726),
                                cVar2 != '\0')) &&
                               ((*(uint *)((uint)local_5 * 0x34 + -9) & 0x800) == 0)) &&
                              (uVar1 = *(undefined4 *)((uint)local_5 * 0x34 + -0x17),
                              (*(uint *)((int)uVar1 + 0x3c) & 4) != 0)))))) {
                      uVar3 = ovr_audio_3a5b_0afd();
                      ovr_play_sfxU(0x1f,0,uVar3);
                      *(byte *)(piVar7 + 6) = local_5 - 1;
                      *(undefined1 *)(piVar7 + 8) = 6;
                      piVar7[3] = 0;
                      *(undefined1 *)((int)piVar7 + 0xd) = 3;
                    }
                    else if ((((*(uint *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x40) & 0x200)
                               == 0) ||
                             (uVar6 = (uint)*(byte *)(piVar7 + 0x11),
                             uVar6 < *(byte *)((int)piVar7 + 0x21) + 3)) ||
                            (uVar3 = ovr_randBelow(0x40), (uVar3 & 0xff) != 0)) {
                      if (((((char)piVar7[2] == '\0') && (*(char *)((int)piVar7 + 5) == '\0')) ||
                          (uVar3 = ovr_randBelow(8), (uVar3 & 0xff) == 0)) &&
                         ((char)piVar7[8] != '\x04')) {
                        uVar3 = ovr_randBelow(0xc);
                        if ((uVar3 & 0xff) == 0) {
                          if (((char)piVar7[2] == '\0') && (*(char *)((int)piVar7 + 5) == '\0')) {
                            uVar3 = ovr_randBelow(2);
                            *(char *)(piVar7 + 2) = (char)uVar3 * '\x02' + -1;
                            uVar3 = ovr_randBelow(3);
                            *(char *)((int)piVar7 + 5) = (char)uVar3 + -1;
                          }
                          else {
                            *(undefined1 *)(piVar7 + 2) = 0;
                            *(undefined1 *)((int)piVar7 + 5) = 0;
                          }
                        }
                        else {
                          cVar2 = ovr_agnt_3b1d_093e(piVar7,uVar8,&local_8);
                          if (cVar2 == '\0') {
                            uVar3 = ovr_randBelow(8);
                            if ((uVar3 & 0xff) == 0) {
                              if ((char)piVar7[2] == '\0') {
                                uVar3 = ovr_randBelow(2);
                                *(char *)(piVar7 + 2) = (char)uVar3 * '\x02' + -1;
                              }
                              else {
                                *(undefined1 *)(piVar7 + 2) = 0;
                              }
                            }
                            *(undefined1 *)((int)piVar7 + 5) = 0;
                          }
                          else {
                            *(undefined1 *)((int)piVar7 + 5) = local_a;
                            if ((local_4 < 0x6e) &&
                               ((*(uint *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x40) & 0x10)
                                != 0)) {
                              if (local_4 < 0x30) {
                                if (((uint)piVar7[0x13] < 0x14) || (0xbe < (uint)piVar7[0x13])) {
                                  uVar3 = ovr_randBelow(2);
                                  *(char *)(piVar7 + 2) = (char)uVar3 * '\x02' + -1;
                                  uVar3 = ovr_randBelow(3);
                                  *(char *)((int)piVar7 + 5) = (char)uVar3 + -1;
                                }
                                else if (local_8 == 0) {
                                  uVar3 = ovr_randBelow(2);
                                  *(char *)(piVar7 + 2) = (char)uVar3 * '\x02' + -1;
                                }
                                else {
                                  *(char *)(piVar7 + 2) = -(char)local_8;
                                }
                              }
                              else {
                                if (local_8 < 0) {
                                  *(undefined1 *)((int)piVar7 + 0xf) = 1;
                                }
                                else {
                                  *(undefined1 *)((int)piVar7 + 0xf) = 0;
                                }
                                *(undefined1 *)(piVar7 + 2) = 0;
                                *(undefined1 *)((int)piVar7 + 5) = 0;
                              }
                            }
                            else if (local_4 < 6) {
                              if (local_8 < 0) {
                                *(undefined1 *)((int)piVar7 + 0xf) = 1;
                              }
                              else {
                                *(undefined1 *)((int)piVar7 + 0xf) = 0;
                              }
                              *(undefined1 *)(piVar7 + 2) = 0;
                              *(undefined1 *)((int)piVar7 + 5) = 0;
                            }
                            else if (local_8 == 0) {
                              uVar3 = ovr_randBelow(2);
                              *(char *)(piVar7 + 2) = (char)uVar3 * '\x02' + -1;
                            }
                            else {
                              *(char *)(piVar7 + 2) = (char)local_8;
                            }
                          }
                        }
                        if ((((char)piVar7[2] < '\x01') || (*(char *)((int)piVar7 + 0xf) == '\0'))
                           && ((-1 < (char)piVar7[2] || (*(char *)((int)piVar7 + 0xf) != '\0')))) {
                          *(undefined1 *)(piVar7 + 8) = 0;
                        }
                        else {
                          *(undefined1 *)(piVar7 + 8) = 1;
                        }
                      }
                    }
                    else {
                      *(char *)((int)piVar7 + 0x21) = *(char *)((int)piVar7 + 0x21) + '\x03';
                      uVar3 = ovr_audio_3a5b_0afd();
                      ovr_play_sfxU(0x4a,0,uVar3);
                      uVar3 = DAT_2000_d0f7;
                      uVar8 = ovr_agnt_3b1d_0ac0(piVar7,uVar8,local_aa);
                      pcVar5 = (char *)ovr_OVC15_4207_1c16(uVar8,uVar6);
                      pcVar9 = ovr_stsprintf(local_5a,
                                             "%s regenerates 3 hitpoints to a total of %d hitpoints."
                                             ,pcVar5);
                      ovr_uiNotify(pcVar9,uVar3);
                    }
                  }
                  else {
                    *(undefined1 *)(piVar7 + 8) = 2;
                    piVar7[3] = 0;
                    *(byte *)(piVar7 + 6) = local_5 - 1;
                    *(undefined1 *)((int)piVar7 + 0xd) = 1;
                  }
                }
                else {
                  *(undefined1 *)(piVar7 + 8) = 3;
                  piVar7[3] = 0;
                  *(byte *)(piVar7 + 6) = local_5 - 1;
                  *(uint *)((int)piVar7 + 0x2b) = *(uint *)((int)piVar7 + 0x2b) | 0x18;
                  *(undefined1 *)((int)piVar7 + 0xd) = 0;
                }
              }
              else {
                *(undefined1 *)(piVar7 + 8) = 3;
                piVar7[3] = 0;
                *(byte *)(piVar7 + 6) = local_5 - 1;
                *(undefined1 *)((int)piVar7 + 0xd) = 6;
              }
            }
          }
          else if (((((*(uint *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x3c) & 0x400) == 0) ||
                    ((0x14 < piVar7[1] ||
                     (cVar2 = OVC49_8699_0000(piVar7,uVar8,&local_5), cVar2 == '\0')))) ||
                   (0x14 < *(int *)((uint)local_5 * 0x34 + -0x32))) ||
                  (cVar2 = ovr_OVC27_5ded_07d0(piVar7,uVar8,local_5 - 1), cVar2 == '\0')) {
            if ((((piVar7[1] < 0x15) && (cVar2 = ovr_OVC27_5ded_04cd(piVar7,uVar8,3), cVar2 != '\0')
                 ) && (cVar2 = OVC49_8699_036e(piVar7,uVar8,&local_5), cVar2 != '\0')) &&
               (*(int *)((uint)local_5 * 0x34 + -0x32) < 0x15)) {
              *(undefined1 *)(piVar7 + 8) = 2;
              piVar7[3] = 0;
              *(byte *)(piVar7 + 6) = local_5 - 1;
              *(undefined1 *)((int)piVar7 + 0xd) = 0;
            }
            else if ((((*(uint *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x3e) & 0x200) == 0) ||
                     (0x14 < piVar7[1])) ||
                    ((cVar2 = ovr_agnt_3b1d_00ce(piVar7,uVar8,&local_5), cVar2 == '\0' ||
                     (0x14 < *(int *)((uint)local_5 * 0x34 + -0x32))))) {
              if ((((*(uint *)((int)*(undefined4 *)((int)piVar7 + 0x1d) + 0x40) & 1) == 0) ||
                  (0x14 < piVar7[1])) ||
                 ((cVar2 = ovr_agnt_3b1d_00ce(piVar7,uVar8,&local_5), cVar2 == '\0' ||
                  (0x14 < *(int *)((uint)local_5 * 0x34 + -0x32))))) {
                if (((('\0' < (char)piVar7[2]) && (0xaa < *param_1)) ||
                    (((char)piVar7[2] < '\0' && (*param_1 < 0x34)))) &&
                   (uVar3 = ovr_randBelow(8), (uVar3 & 0xff) == 0)) {
                  cVar2 = ovr_agnt_3b1d_093e(piVar7,uVar8,&local_8);
                  if (cVar2 == '\0') {
                    *(undefined1 *)((int)piVar7 + 5) = 0;
                  }
                  else {
                    *(undefined1 *)((int)piVar7 + 5) = local_a;
                  }
                  *(char *)(piVar7 + 2) = -(char)piVar7[2];
                  *(undefined1 *)((uint)param_2 * 0x34 + 0x10) = 1;
                  piVar7[3] = 0;
                }
              }
              else {
                *(undefined1 *)(piVar7 + 8) = 2;
                piVar7[3] = 0;
                *(byte *)(piVar7 + 6) = local_5 - 1;
                *(undefined1 *)((int)piVar7 + 0xd) = 5;
              }
            }
            else {
              *(undefined1 *)(piVar7 + 8) = 2;
              piVar7[3] = 0;
              *(byte *)(piVar7 + 6) = local_5 - 1;
              *(undefined1 *)((int)piVar7 + 0xd) = 4;
            }
          }
          else {
            *(undefined1 *)(piVar7 + 8) = 2;
            piVar7[3] = 0;
            *(byte *)(piVar7 + 6) = local_5 - 1;
            *(undefined1 *)((int)piVar7 + 0xd) = 1;
          }
        }
        else if ((*(char *)((int)piVar7 + 0x25) != '\x02') &&
                ((((*(char *)((int)piVar7 + 5) == '\0' && ((char)piVar7[2] == '\0')) &&
                  (uVar3 = ovr_randBelow(4), (uVar3 & 0xff) == 0)) ||
                 (((*(char *)((int)piVar7 + 5) < '\0' || (*(char *)((int)piVar7 + 0x25) != '\x01'))
                  || (uVar3 = ovr_randBelow(8), (uVar3 & 0xff) == 0)))))) {
          *(undefined1 *)((int)piVar7 + 0x25) = 1;
          uVar3 = ovr_randBelow(2);
          *(undefined1 *)((int)piVar7 + 5) = (char)uVar3;
          uVar3 = ovr_randBelow(2);
          *(char *)(piVar7 + 2) = (char)uVar3 * '\x02' + -1;
          if (*param_1 < 0x2a) {
            *(undefined1 *)(piVar7 + 2) = 0xff;
          }
          else if (*param_1 < 0xb5) {
            *(undefined1 *)((int)piVar7 + 5) = 1;
          }
          else {
            *(undefined1 *)(piVar7 + 2) = 1;
          }
        }
      }
      else {
        *(undefined1 *)((int)piVar7 + 5) = 0xff;
        if ((char)piVar7[2] == '\0') {
          uVar3 = ovr_randBelow(3);
          *(char *)(piVar7 + 2) = (char)uVar3 + -1;
        }
      }
    }
    else {
      *(undefined1 *)(piVar7 + 2) = 0;
      *(undefined1 *)((int)piVar7 + 5) = 0;
      *(undefined1 *)(piVar7 + 8) = 0;
    }
  }
  return;
}



/* 8699:1711 */

undefined2 __cdecl16far OVC49_8699_1711(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if ((*(byte *)(iVar1 + 0x25) < 2) &&
     ((((*(uint *)(iVar1 + 0x2b) & 4) != 0 || (*(char *)(iVar1 + 0x25) == '\x01')) ||
      ((*(char *)(iVar1 + 0x2a) == '\x02' && (DAT_2000_d0f4 != '\0')))))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 8699:1753 */

void * __cdecl16far OVC49_8699_1753(byte param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  int *piVar7;
  undefined2 uVar8;
  void *pvVar9;
  int iStack_4;
  
  uVar8 = (undefined2)((ulong)param_2 >> 0x10);
  piVar6 = (int *)param_2;
  piVar7 = (int *)(*(int *)((int)piVar6 + 0x13) + (uint)*(byte *)(piVar6 + 9) * 4);
  iVar1 = piVar7[1];
  iVar2 = *piVar7;
  iVar3 = piVar6[1] >> 1;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  if (7 < iVar3) {
    iVar3 = 7;
  }
  iVar4 = *param_2 - *(int *)(iVar2 + 0x17) >> 1;
  iStack_4 = *param_2 + *(int *)(iVar2 + 0x17) >> 1;
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  if (iStack_4 < 0) {
    iStack_4 = 0;
  }
  if (0x68 < iVar4) {
    iVar4 = 0x68;
  }
  if (0x68 < iStack_4) {
    iStack_4 = 0x68;
  }
  if (*(char *)((int)piVar6 + 0x11) == '\0') {
    _fmemset((void *)CONCAT22(0x1726,(void *)(iVar3 * 0x69 + iVar4 + 0x8fa)),(uint)param_1,
             (iStack_4 - iVar4) + 1);
    pvVar9 = _fmemset((void *)CONCAT22(0x1726,(void *)(iVar3 * 0x69 + iVar4 + 0x963)),(uint)param_1,
                      (iStack_4 - iVar4) + 1);
    pvVar5 = (void *)pvVar9;
  }
  else {
    _fmemset((void *)CONCAT22(0x1726,(void *)(iVar3 * 0x69 + iVar4 + 0x4e0)),(uint)param_1,
             (iStack_4 - iVar4) + 1);
    _fmemset((void *)CONCAT22(0x1726,(void *)(iVar3 * 0x69 + iVar4 + 0x549)),(uint)param_1,
             (iStack_4 - iVar4) + 1);
    pvVar9 = _fmemset((void *)CONCAT22(0x1726,(void *)(iVar3 * 0x69 + iVar4 + 0x5b2)),(uint)param_1,
                      (iStack_4 - iVar4) + 1);
    pvVar5 = (void *)pvVar9;
  }
  return pvVar5;
}



/* 8699:18c4 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00088b74) overlaps instruction at (ram,0x00088b73)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint __cdecl16far
OVC49_8699_18c4(int *param_1,byte *param_2,undefined2 param_3,undefined2 param_4,char param_5)

{
  char *pcVar1;
  int *piVar2;
  uint *puVar3;
  bool bVar4;
  undefined4 uVar5;
  far_t pixels;
  far_t pixels_00;
  far_t pixels_01;
  far_t pixels_02;
  far_t pixels_03;
  far_t pixels_04;
  far_t pixels_05;
  far_t pixels_06;
  far_t pixels_07;
  far_t pixels_08;
  far_t pixels_09;
  far_t pixels_10;
  far_t pixels_11;
  far_t pixels_12;
  far_t pixels_13;
  far_t pixels_14;
  far_t pixels_15;
  far_t pixels_16;
  far_t pixels_17;
  far_t pixels_18;
  far_t pixels_19;
  far_t pixels_20;
  far_t pixels_21;
  far_t pixels_22;
  far_t pixels_23;
  far_t pixels_24;
  far_t pixels_25;
  far_t pixels_26;
  far_t pixels_27;
  far_t pixels_28;
  far_t pixels_29;
  far_t pixels_30;
  far_t pixels_31;
  far_t pixels_32;
  far_t pixels_33;
  far_t pixels_34;
  far_t pixels_35;
  far_t pixels_36;
  far_t pixels_37;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t gfx_05;
  far_t src;
  far_t src_00;
  far_t src_01;
  far_t src_02;
  far_t src_03;
  far_t src_04;
  far_t src_05;
  far_t src_06;
  far_t src_07;
  far_t src_08;
  far_t src_09;
  far_t src_10;
  far_t src_11;
  far_t src_12;
  far_t src_13;
  far_t src_14;
  far_t src_15;
  far_t src_16;
  far_t src_17;
  far_t src_18;
  far_t src_19;
  far_t src_20;
  far_t src_21;
  far_t src_22;
  far_t src_23;
  far_t src_24;
  far_t src_25;
  far_t src_26;
  far_t src_27;
  far_t src_28;
  far_t src_29;
  far_t src_30;
  far_t src_31;
  far_t src_32;
  far_t src_33;
  far_t src_34;
  far_t src_35;
  far_t src_36;
  far_t src_37;
  far_t src_38;
  far_t src_39;
  far_t src_40;
  far_t src_41;
  far_t src_42;
  far_t src_43;
  far_t src_44;
  far_t src_45;
  far_t src_46;
  far_t src_47;
  far_t src_48;
  far_t src_49;
  far_t src_50;
  far_t src_51;
  far_t src_52;
  far_t src_53;
  far_t src_54;
  far_t src_55;
  far_t src_56;
  far_t src_57;
  far_t src_58;
  far_t src_59;
  far_t src_60;
  far_t src_61;
  far_t src_62;
  far_t src_63;
  far_t src_64;
  far_t src_65;
  far_t src_66;
  far_t src_67;
  far_t src_68;
  far_t src_69;
  far_t src_70;
  far_t src_71;
  far_t src_72;
  far_t src_73;
  far_t gfx_06;
  far_t hndl;
  far_t dst;
  far_t dst_00;
  byte bVar6;
  byte bVar7;
  char cVar8;
  undefined1 uVar9;
  char cVar10;
  cte_t *pcVar11;
  stg_tmp_t *psVar12;
  int iVar13;
  uint uVar14;
  uint16_t uVar15;
  int iVar16;
  char *pcVar17;
  int iVar18;
  uint16_t uVar19;
  undefined1 *puVar20;
  char *pcVar21;
  int *piVar22;
  char *pcVar23;
  int unaff_SI;
  undefined2 uVar24;
  undefined2 uVar25;
  char *pcVar26;
  char *unaff_SS;
  byte in_AF;
  far_t fVar27;
  far_t fVar28;
  far_t fVar29;
  far_t fVar30;
  far_t fVar31;
  far_t fVar32;
  uint8_t *puVar33;
  far_t fVar34;
  far_t fVar35;
  far_t fVar36;
  far_t fVar37;
  far_t fVar38;
  far_t fVar39;
  far_t fVar40;
  far_t fVar41;
  far_t fVar42;
  stg_tmp_t *psVar43;
  uint32_t uVar44;
  cte_t *pcVar45;
  far_t fVar46;
  far_t fVar47;
  far_t fVar48;
  char *apcStackY_2f2 [20];
  char acStackY_2ca [664];
  char acStackY_32 [6];
  char acStackY_2c [3];
  char cStackY_29;
  int iStackY_28;
  undefined1 auStackY_26 [2];
  undefined2 uStackY_24;
  undefined2 uStackY_22;
  undefined2 uStackY_20;
  char *in_stack_0000ffe2;
  undefined2 uStackY_1c;
  int in_stack_0000ffe8;
  char *pcVar49;
  uint16_t uVar50;
  undefined1 uVar51;
  undefined1 uVar52;
  undefined1 uVar53;
  undefined1 uVar54;
  stg_tmp_t *psStack_a;
  char *pcStack_8;
  char cVar55;
  char cVar56;
  undefined1 uVar57;
  uint in_stack_0000fffc;
  
  cVar10 = (char)((uint)in_stack_0000ffe2 >> 8);
  uVar24 = (undefined2)((ulong)param_1 >> 0x10);
  piVar22 = (int *)param_1;
  pcStack_8 = (char *)*(int *)((int)piVar22 + 0x13);
  uVar53 = (undefined1)*(undefined2 *)((int)piVar22 + 0x15);
  uVar54 = (undefined1)((uint)*(undefined2 *)((int)piVar22 + 0x15) >> 8);
  uVar9 = 0x99;
  uVar51 = 0x86;
  pcVar49 = (char *)0x8278;
  iVar13 = ovr_agnt_3b1d_005e();
  iVar13 = *(int *)(iVar13 * 2 + 0x1a6);
  uVar57 = (undefined1)in_stack_0000fffc;
  if ((char)piVar22[0x12] != '\x01') {
    if ((char)piVar22[0x12] == '\x02') {
      uVar25 = (undefined2)(CONCAT13(uVar54,CONCAT12(uVar53,pcStack_8)) >> 0x10);
      if (*(int *)(pcStack_8 + 0xa0) == 0 && *(int *)(pcStack_8 + 0xa2) == 0) {
        if (*(char *)((int)piVar22 + 0x11) == '\0') {
          in_stack_0000fffc = in_stack_0000fffc & 0xff;
        }
        else {
          in_stack_0000fffc = CONCAT11(4,uVar57);
        }
      }
      else {
        in_stack_0000fffc = CONCAT11(0x12,uVar57);
      }
    }
    else {
      if ((char)piVar22[2] < '\x01') {
        if ((char)piVar22[2] < '\0') {
          if (*(char *)((int)piVar22 + 5) < '\x01') {
            if (*(char *)((int)piVar22 + 5) < '\0') {
              in_stack_0000fffc = 0x201;
            }
            else if (iVar13 < 8) {
              if (iVar13 < -7) {
                in_stack_0000fffc = 0x201;
              }
              else {
                in_stack_0000fffc = 1;
              }
            }
            else {
              in_stack_0000fffc = 0x101;
            }
          }
          else {
            in_stack_0000fffc = 0x101;
          }
        }
        else {
          uVar9 = *(undefined1 *)((int)piVar22 + 0xf);
          in_stack_0000fffc = CONCAT11((char)(in_stack_0000fffc >> 8),uVar9);
          if (*(char *)((int)piVar22 + 5) < '\x01') {
            if (*(char *)((int)piVar22 + 5) < '\0') {
              in_stack_0000fffc = CONCAT11(2,uVar9);
            }
            else if ((*(uint *)((int)piVar22 + 0x2b) & 0x100) == 0) {
              in_stack_0000fffc = CONCAT11(1,uVar9);
            }
            else {
              uVar15 = ovr_randBelow(3);
              uVar14 = uVar15 & 0xff;
              if (uVar14 == 0) {
                in_stack_0000fffc = in_stack_0000fffc & 0xff;
              }
              else if (uVar14 == 1) {
                in_stack_0000fffc = CONCAT11(2,(char)in_stack_0000fffc);
              }
              else if (uVar14 == 2) {
                in_stack_0000fffc = CONCAT11(1,(char)in_stack_0000fffc);
              }
            }
          }
          else {
            in_stack_0000fffc = CONCAT11(1,uVar9);
          }
        }
      }
      else if (*(char *)((int)piVar22 + 5) < '\x01') {
        if (*(char *)((int)piVar22 + 5) < '\0') {
          in_stack_0000fffc = 0x200;
        }
        else if (iVar13 < 8) {
          if (iVar13 < -7) {
            in_stack_0000fffc = 0x100;
          }
          else {
            in_stack_0000fffc = 0;
          }
        }
        else {
          in_stack_0000fffc = 0x200;
        }
      }
      else {
        in_stack_0000fffc = 0x100;
      }
      uVar9 = (undefined1)in_stack_0000fffc;
      if (*(char *)((int)piVar22 + 0x11) == '\0') {
        if ((char)piVar22[8] == '\x02') {
          if ((*(char *)((int)piVar22 + 0xd) == '\x01') &&
             (uVar25 = (undefined2)(CONCAT13(uVar54,CONCAT12(uVar53,pcStack_8)) >> 0x10),
             *(int *)(pcStack_8 + 0x74) != 0 || *(int *)(pcStack_8 + 0x76) != 0)) {
            in_stack_0000fffc = CONCAT11(7,uVar9);
          }
          else if ((*(char *)((int)piVar22 + 0xd) == '\x02') &&
                  (uVar25 = (undefined2)(CONCAT13(uVar54,CONCAT12(uVar53,pcStack_8)) >> 0x10),
                  *(int *)(pcStack_8 + 0xa8) != 0 || *(int *)(pcStack_8 + 0xaa) != 0)) {
            in_stack_0000fffc = CONCAT11(0x14,uVar9);
          }
          else {
            in_stack_0000fffc = CONCAT11(3,uVar9);
          }
        }
        else if ((char)piVar22[8] == '\x03') {
          uVar25 = (undefined2)(CONCAT13(uVar54,CONCAT12(uVar53,pcStack_8)) >> 0x10);
          if (*(int *)(pcStack_8 + 0x74) == 0 && *(int *)(pcStack_8 + 0x76) == 0) {
            in_stack_0000fffc = CONCAT11(3,uVar9);
          }
          else {
            in_stack_0000fffc = CONCAT11(7,uVar9);
          }
        }
        else if ((char)piVar22[8] == '\x01') {
          uVar25 = (undefined2)(CONCAT13(uVar54,CONCAT12(uVar53,pcStack_8)) >> 0x10);
          if (*(int *)(pcStack_8 + 0x9c) != 0 || *(int *)(pcStack_8 + 0x9e) != 0) {
            in_stack_0000fffc = CONCAT11(0x11,uVar9);
          }
        }
        else if ((char)piVar22[8] == '\x04') {
          uVar25 = (undefined2)(CONCAT13(uVar54,CONCAT12(uVar53,pcStack_8)) >> 0x10);
          if (*(int *)(pcStack_8 + 0xa4) != 0 || *(int *)(pcStack_8 + 0xa6) != 0) {
            in_stack_0000fffc = CONCAT11(0x13,uVar9);
          }
        }
        else if ((((char)piVar22[8] == '\x05') || ((char)piVar22[8] == '\x06')) &&
                (uVar25 = (undefined2)(CONCAT13(uVar54,CONCAT12(uVar53,pcStack_8)) >> 0x10),
                *(int *)(pcStack_8 + 0xac) != 0 || *(int *)(pcStack_8 + 0xae) != 0)) {
          in_stack_0000fffc = CONCAT11(0x15,uVar9);
        }
      }
      else {
        in_stack_0000fffc = CONCAT11(4,uVar9);
        if ((char)piVar22[8] == '\x02') {
          in_stack_0000fffc = CONCAT11(0xf,uVar9);
        }
        else if ((char)piVar22[8] == '\x01') {
          in_stack_0000fffc = CONCAT11(5,uVar9);
        }
        uVar25 = (undefined2)(CONCAT13(uVar54,CONCAT12(uVar53,pcStack_8)) >> 0x10);
        if (*(int *)(pcStack_8 + (in_stack_0000fffc >> 8) * 4 + 0x58) == 0 &&
            *(int *)(pcStack_8 + (in_stack_0000fffc >> 8) * 4 + 0x5a) == 0) {
          in_stack_0000fffc = CONCAT11(4,(char)in_stack_0000fffc);
        }
      }
    }
LAB_8699_1ca7:
    uVar25 = (undefined2)(CONCAT13(uVar54,CONCAT12(uVar53,pcStack_8)) >> 0x10);
    if (*(int *)(pcStack_8 + (in_stack_0000fffc >> 8) * 4 + 0x58) == 0 &&
        *(int *)(pcStack_8 + (in_stack_0000fffc >> 8) * 4 + 0x5a) == 0) {
      if (*(char *)((int)piVar22 + 0x11) == '\0') {
        in_stack_0000fffc = in_stack_0000fffc & 0xff;
      }
      else {
        in_stack_0000fffc = CONCAT11(4,(char)in_stack_0000fffc);
      }
    }
    bVar7 = (byte)(in_stack_0000fffc >> 8);
    if ((((*(char *)((int)piVar22 + 0x11) == '\0') && (bVar7 != 0x12)) && ((char)piVar22[8] == '\0')
        ) && ((*(char *)((int)piVar22 + 5) == '\0' && ((char)piVar22[2] == '\0')))) {
      piVar22[3] = 0;
    }
    *(undefined1 *)((int)piVar22 + 0xf) = (char)in_stack_0000fffc;
    *(byte *)(piVar22 + 9) = bVar7;
    uVar25 = (undefined2)(CONCAT13(uVar54,CONCAT12(uVar53,pcStack_8)) >> 0x10);
    iVar13 = *(int *)((int)(pcStack_8 + (uint)bVar7 * 4) + 2);
    iVar16 = *(int *)(pcStack_8 + (uint)bVar7 * 4);
    uVar9 = (undefined1)iVar16;
    uVar51 = (undefined1)((uint)iVar16 >> 8);
    if (*(char *)(iVar16 + 0x1a) == -1) {
      if ((int)(uint)*(byte *)(iVar16 + 0x1b) <= piVar22[3] + 1) {
        if ((*(uint *)((int)*(undefined4 *)((int)piVar22 + 0x1d) + 0x40) & 4) == 0) {
          *(undefined1 *)(piVar22 + 8) = 0;
        }
        else if ((char)piVar22[7] == -1) {
          DAT_2410_07e2 = 1;
          ovr_agnt_3b1d_0a53();
        }
        else {
          *(undefined1 *)(piVar22 + 8) = 0;
        }
        if ((int)(uint)*(byte *)(CONCAT11(uVar51,uVar9) + 0x1b) <= piVar22[3]) {
          piVar22[3] = 0;
        }
      }
    }
    else if ((int)(uint)*(byte *)(iVar16 + 0x1b) <= piVar22[3]) {
      piVar22[3] = (uint)*(byte *)(iVar16 + 0x1a);
    }
    return in_stack_0000fffc >> 8;
  }
  if ((*(uint *)((int)*(undefined4 *)((int)piVar22 + 0x1d) + 0x40) & 2) != 0) {
    in_stack_0000fffc = CONCAT11(0x12,uVar57);
    goto LAB_8699_1ca7;
  }
  uVar57 = SUB21(unaff_SS,0);
  uVar52 = (undefined1)((uint)unaff_SS >> 8);
  if (*(char *)((int)piVar22 + 0x11) != '\0') {
    uVar14 = *(byte *)((int)piVar22 + 0x23) & 3;
    if (uVar14 < 4) {
      switch(uVar14) {
      case 0:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 1:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 2:
                    /* WARNING (jumptable): Read-only address (ram,0x0002db84) is written */
                    /* WARNING: Read-only address (ram,0x0002db84) is written */
        pcVar1 = (char *)(uVar14 * 2 + unaff_SI);
        uRam0002db84 = uVar14;
        *pcVar1 = *pcVar1 + -0x4d;
        (*(uint8_t *)((uint8_t *)&(fVar36.seg))) = (char)DAT_2410_07e5;
        fVar36.ofs = DAT_2410_07e3;
        (*(uint8_t *)((uint8_t *)&(fVar36.seg) + 1)) = (char)((uint)DAT_2410_07e5 >> 8);
        (*(uint8_t *)((uint8_t *)&(dst.seg))) = (char)stack0xffd6;
        dst.ofs = 0x8cc;
        (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = (char)((uint)stack0xffd6 >> 8);
        ovr_blitLoadRleGfx(fVar36,dst);
        (*(uint8_t *)((uint8_t *)&(gfx_06.seg))) = (char)DAT_2410_07e9;
        gfx_06.ofs = DAT_2410_07e7;
        (*(uint8_t *)((uint8_t *)&(gfx_06.seg) + 1)) = (char)((uint)DAT_2410_07e9 >> 8);
        (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = (char)stack0xffd6;
        dst_00.ofs = (uint16_t)((char *)"Stronghold requires 585,000 bytes.\n" + 1);
        (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = (char)((uint)stack0xffd6 >> 8);
        ovr_blitLoadRleGfx(gfx_06,dst_00);
        GGameState = 0x2c;
        ovr_OVC23_55fe_0863();
        cVar10 = 'o';
        cVar8 = '#';
        _fmemset((void *)CONCAT13(uVar52,CONCAT12(uVar57,&stack0xffec)),0,2);
        for (uStackY_22 = (cte_t *)0x0; (int)uStackY_22 < (int)(uint)AgntCount;
            uStackY_22 = (cte_t *)((int)uStackY_22 + 1)) {
          (&stack0xffec)[*(byte *)((int)uStackY_22 * 0x34 + 0x2f)] = 1;
        }
        if ((cVar10 == '\0') || (cVar8 == '\0')) {
          DAT_2000_d0f4 = 0;
        }
        else {
          DAT_2000_d0f4 = 1;
        }
        GGameState = 0x2d;
        if (DebugVerbose != false) {
          printf("%d \r",0x2d);
        }
        pcVar26 = (char *)&AgntAnms[0x38].field_0x18;
        uStackY_22 = (cte_t *)0x0;
        goto LAB_8699_29b9;
      case 3:
        bVar7 = ((byte)uVar14 + (9 < (byte)uVar14 | in_AF) * '\x06' & 0xf &
                (byte)*(undefined2 *)(&stack0x02c2 + iVar13)) * '\x02' - 1;
        uVar14 = (uint)bVar7;
        *(byte *)(piVar22 + 2) = bVar7;
        if ((((char)piVar22[2] < '\x01') || (*(char *)((int)piVar22 + 0xf) == '\0')) &&
           ((-1 < (char)piVar22[2] || (uVar14 = (uint)*(char *)((int)piVar22 + 0xf), uVar14 != 0))))
        {
          *(undefined1 *)(piVar22 + 8) = 0;
        }
        else {
          *(undefined1 *)(piVar22 + 8) = 1;
        }
                    /* WARNING: Read-only address (ram,0x0002db84) is written */
        return uVar14;
      }
    }
    goto LAB_8699_1ca7;
  }
  if ((char)piVar22[2] < '\x01') {
    if (*(char *)((int)piVar22 + 5) < '\0') {
      iVar13 = 5;
    }
    else if (*(char *)((int)piVar22 + 5) == '\0') {
      iVar13 = 4;
    }
    else {
      iVar13 = 3;
    }
  }
  else if (*(char *)((int)piVar22 + 5) < '\0') {
    iVar13 = 0;
  }
  else if (*(char *)((int)piVar22 + 5) == '\0') {
    iVar13 = 1;
  }
  else {
    iVar13 = 2;
  }
  uVar14 = ((uint)*(byte *)((int)piVar22 + 0x23) + iVar13) % 6;
  if (5 < uVar14) goto LAB_8699_1ca7;
  switch(uVar14) {
  case 0:
    do {
      iVar16 = 0;
      uVar24 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
      iVar13 = (int)DAT_2000_ca95;
      uStackY_20 = (char *)((int)(((long)*(int *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 0x125) *
                                   (long)(int)(uint)*(byte *)(iVar13 + (int)auStackY_26 * 9 + 1) &
                                  0xffffU) / 0x18) + 1);
      if (*(int *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 0x116) == 0 &&
          *(int *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 0x118) == 0) {
        if ((((uint)auStackY_26 < 0xf8) || (*(int *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 0x125) == 0))
           || ((*(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 0x121) & 4) != 0)) {
          if ((((*(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 0x121) & 4) == 0) ||
              (*(char *)(iVar13 + (int)auStackY_26 * 9 + 2) == -1)) ||
             (uVar5 = *(undefined4 *)((uint)*(byte *)(iVar13 + (int)auStackY_26 * 9 + 2) << 2),
             *(char *)((int)uVar5 + 0x3f) != '\0')) {
            apcStackY_2f2[1] = (char *)"puppetmaker" + 3;
            apcStackY_2f2[0] = (char *)"Demolish";
            iVar16 = 1;
          }
          uStackY_20 = (char *)0x0;
        }
        else {
          apcStackY_2f2[1] = (char *)"puppetmaker" + 3;
          apcStackY_2f2[0] = (char *)"Salvage";
          iVar16 = 1;
          if (cStackY_29 != '\0') {
            pcVar49 = ovr_fmVsprintf((char *)" Salvage value %d gold.",uStackY_20);
            strcat(acStackY_2ca,pcVar49);
          }
        }
      }
      else {
        apcStackY_2f2[1] = (char *)*(undefined2 *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 0x118);
        apcStackY_2f2[0] = (char *)*(undefined2 *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 0x116);
        iVar16 = 1;
      }
      pcVar49 = (char *)"trade faire" + 8;
      cVar10 = ovr_OVC45_77eb_2226();
      if ((cVar10 == '\0') || (7 < *(byte *)((int)DAT_2000_ca95 + (int)auStackY_26 * 9 + 1))) {
        pcVar49 = (char *)"trade faire" + 8;
        cVar10 = ovr_OVC45_77eb_2226();
        if ((cVar10 != '\0') && (*(char *)(((uint)uStackY_22 >> 8) * 0x27 + 300) != '\0')) {
          (&stack0xffec)[iVar16] = 3;
          apcStackY_2f2[iVar16 * 2 + 1] = (char *)"puppetmaker" + 3;
          apcStackY_2f2[iVar16 * 2] = (char *)"Upgrade";
          iVar16 = iVar16 + 1;
          in_stack_0000ffe2 =
               (char *)*(undefined2 *)
                        (((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) +
                         (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 300)) * 0x27 + 0x125);
          if (cStackY_29 == '\0') {
            pcVar26 = ovr_fmVsprintf((char *)" Upgrade costs %d gp.",in_stack_0000ffe2);
            pcVar49 = (char *)0x1000;
            strcat(acStackY_2ca,pcVar26);
          }
        }
      }
      else {
        (&stack0xffec)[iVar16] = 2;
        apcStackY_2f2[iVar16 * 2 + 1] = (char *)"puppetmaker" + 3;
        apcStackY_2f2[iVar16 * 2] = (char *)"Repair";
        iVar16 = iVar16 + 1;
        in_stack_0000ffe2 = (char *)(*(uint *)(((uint)uStackY_22 >> 8) * 0x27 + 0x125) / 5 + 1);
        if (cStackY_29 == '\0') {
          pcVar26 = ovr_fmVsprintf((char *)" Repair costs %d gp.",in_stack_0000ffe2);
          pcVar49 = (char *)0x1000;
          strcat(acStackY_2ca,pcVar26);
        }
      }
      bVar7 = *(byte *)((int)DAT_2000_ca95 + (int)auStackY_26 * 9 + 2);
      uStackY_24 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStackY_24) + 1)),bVar7);
      if ((((*(uint *)(((uint)uStackY_22 >> 8) * 0x27 + 0x121) & 0x400) == 0) && (bVar7 != 0xff)) &&
         (*(char *)((int)*(undefined4 *)((uint)bVar7 << 2) + 0x3f) == '\0')) {
        (&stack0xffec)[iVar16] = 7;
        apcStackY_2f2[iVar16 * 2 + 1] = (char *)"puppetmaker" + 3;
        apcStackY_2f2[iVar16 * 2] = (char *)"Information";
        iVar16 = iVar16 + 1;
      }
      uVar9 = 0x19;
      if (((*(uint *)(((uint)uStackY_22 >> 8) * 0x27 + 0x121) & 4) == 0) &&
         (0xf7 < (uint)auStackY_26)) {
        uVar9 = 0x24;
        if (*(char *)(Entities.ofs + (*(uint16_t *)((uint8_t *)&(param_2) + 2)) * 0x37 + 0x1a) != (char)uStackY_24) {
          (&stack0xffec)[iVar16] = 6;
          apcStackY_2f2[iVar16 * 2 + 1] = (char *)"puppetmaker" + 3;
          apcStackY_2f2[iVar16 * 2] = (char *)"New Owner";
          iVar16 = iVar16 + 1;
        }
      }
      if (param_5 != '\0') {
        (&stack0xffec)[iVar16] = 4;
        apcStackY_2f2[iVar16 * 2 + 1] = (char *)"puppetmaker" + 3;
        apcStackY_2f2[iVar16 * 2] = (char *)"Change Party";
        iVar16 = iVar16 + 1;
      }
      (&stack0xffec)[iVar16] = 5;
      apcStackY_2f2[iVar16 * 2 + 1] = (char *)"puppetmaker" + 3;
      apcStackY_2f2[iVar16 * 2] = (char *)"Done";
      pcVar23 = (char *)(iVar16 + 1);
      puVar20 = (undefined1 *)CONCAT11(uVar9,(undefined1)uStackY_22);
      DAT_2410_5cef = (undefined1)uStackY_22;
      in_stack_0000ffe8 = 0xaf7;
      pcVar26 = unaff_SS;
      pcVar17 = pcVar23;
      bVar6 = ovr_OVC28_6018_1527();
      DAT_2410_5cef = 0xff;
      bVar7 = 0;
      if (bVar6 != 0) {
        puVar20 = &stack0xffeb;
        bVar7 = puVar20[bVar6];
      }
      uStackY_1c = (char *)CONCAT11(bVar7,(char)uStackY_1c);
      pcVar11 = (cte_t *)(uint)bVar7;
      fVar35.seg = (uint16_t)puVar20;
      fVar35.ofs = (uint16_t)pcVar11;
      if ((cte_t *)0x7 < pcVar11) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      pcVar21 = (char *)((int)pcVar11 * 2);
      switch(pcVar11) {
      case (cte_t *)0x0:
        do {
          if (*(char *)((int)pcVar11 * 0x34 + 5) < '\0') {
            piVar2 = (int *)((int)uStackY_22 * 0x34 + 2);
            *piVar2 = *piVar2 - *(int *)(pcVar26 + 0x11);
          }
LAB_8699_21a5:
          do {
            cVar10 = (char)((uint)in_stack_0000ffe2 >> 8);
            if ((*(int *)((int)uStackY_22 * 0x34) < 0) || (0xd2 < *(int *)((int)uStackY_22 * 0x34)))
            {
LAB_8699_2229:
              bVar4 = false;
            }
            else {
code_r0x00088b64:
              if ((*(int *)((int)uStackY_22 * 0x34 + 2) < 0) ||
                 ((*(char *)((int)uStackY_22 * 0x34 + 0x11) == '\0' &&
                  (cVar8 = OVC49_8699_0849(), cVar8 != '\0')))) goto LAB_8699_2229;
              bVar4 = true;
            }
            if ((bVar4) && (*(int *)((int)uStackY_22 * 0x34 + 2) < 0x15)) {
              uVar9 = 1;
            }
            else {
              uVar9 = 0;
            }
            uStackY_20 = (char *)CONCAT11(bVar4,uVar9);
            if (*(char *)((int)uStackY_22 * 0x34 + 0x11) == '\0') {
              iVar13 = ovr_agnt_3b1d_005e();
              iStackY_28 = *(int *)(iVar13 * 2 + 0x34c) + *(int *)((int)uStackY_22 * 0x34 + 2) + 3;
            }
            else {
              iVar13 = ovr_agnt_3b1d_005e();
              iStackY_28 = *(int *)(iVar13 * 2 + 0x34c) + *(int *)((int)uStackY_22 * 0x34 + 2) +
                           -0x16;
            }
            pcVar26 = (char *)"mason\'s hall" + 6;
            *(int *)((int)uStackY_22 * 0x34 + 0x28) = iStackY_28;
            if ((*(char *)((int)uStackY_22 * 0x34 + 0x10) == '\x05') &&
               (*(char *)((int)uStackY_22 * 0x34 + 0xc) != -1)) {
              pcVar26 = (char *)"builder\'s hall" + 8;
              ovr_OVC41_6a8f_08c2();
            }
            cVar8 = OVC49_8699_1711();
            if (((cVar8 == '\0') || (*(int *)((int)uStackY_22 * 0x34 + 2) < 0)) ||
               ((-1 < *(int *)((int)uStackY_22 * 0x34) &&
                ((*(int *)((int)uStackY_22 * 0x34) < 0xd3 &&
                 ((uint)(*(int *)((int)uStackY_22 * 0x34 + 0x28) - *(int *)(in_stack_0000ffe8 + 9))
                  < 0x96)))))) {
              if (*(char *)((int)uStackY_22 * 0x34 + 0x11) == '\0') {
                cVar8 = OVC49_8699_0849();
                if (cVar8 != '\0') {
                  *(undefined2 *)((int)uStackY_22 * 0x34) = uStackY_24;
                  *(undefined2 *)((int)uStackY_22 * 0x34 + 2) = auStackY_26;
                  if (*(char *)((int)uStackY_22 * 0x34 + 4) == '\0') {
                    uVar15 = ovr_randBelow(3);
                    *(char *)((int)uStackY_22 * 0x34 + 4) = (char)uVar15 + -1;
                  }
                  else {
                    *(char *)((int)uStackY_22 * 0x34 + 4) = -*(char *)((int)uStackY_22 * 0x34 + 4);
                  }
                  cVar10 = OVC49_8699_1711();
                  if (cVar10 == '\0') {
                    uVar15 = ovr_randBelow(3);
                    *(char *)((int)uStackY_22 * 0x34 + 5) = (char)uVar15 + -1;
                  }
                  else {
                    uVar15 = ovr_randBelow(2);
                    *(undefined1 *)((int)uStackY_22 * 0x34 + 5) = (char)uVar15;
                  }
                  pcVar26 = (char *)"glassworks" + 9;
                  if (*(char *)((int)uStackY_22 * 0x34 + 4) == '\0') {
                    *(undefined1 *)((int)uStackY_22 * 0x34 + 5) = 0;
                  }
                  if ((('\0' < *(char *)((int)uStackY_22 * 0x34 + 4)) &&
                      (*(char *)((int)uStackY_22 * 0x34 + 0xf) != '\0')) ||
                     ((*(char *)((int)uStackY_22 * 0x34 + 4) < '\0' &&
                      (*(char *)((int)uStackY_22 * 0x34 + 0xf) == '\0')))) {
                    *(undefined1 *)((int)uStackY_22 * 0x34 + 0x10) = 1;
                  }
                  cVar10 = '\0';
                  *(undefined2 *)((int)uStackY_22 * 0x34 + 6) = 0;
                  OVC49_8699_18c4();
                  goto LAB_8699_2982;
                }
              }
              if (((*(uint8_t *)((uint8_t *)&(uStackY_20) + 1)) == '\0') ||
                 ((((char)uStackY_20 == '\0' && (-1 < *(char *)((int)uStackY_22 * 0x34 + 5))) &&
                  (cVar8 = OVC49_8699_1711(), cVar8 == '\0')))) {
                if (*(char *)((int)uStackY_22 * 0x34 + 0x25) != '\x02') {
                  *(undefined2 *)((int)uStackY_22 * 0x34) = uStackY_24;
                  *(undefined2 *)((int)uStackY_22 * 0x34 + 2) = auStackY_26;
                  if ((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 0xbc0) == 0) {
                    if (*(char *)((int)uStackY_22 * 0x34 + 4) == '\0') {
                      uVar15 = ovr_randBelow(2);
                      *(char *)((int)uStackY_22 * 0x34 + 4) = (char)uVar15 * '\x02' + -1;
                    }
                    else {
                      *(char *)((int)uStackY_22 * 0x34 + 4) = -*(char *)((int)uStackY_22 * 0x34 + 4)
                      ;
                    }
                    pcVar26 = (char *)"glassworks" + 9;
                    uVar15 = ovr_randBelow(3);
                    *(char *)((int)uStackY_22 * 0x34 + 5) = (char)uVar15 + -1;
                  }
                  if ((('\0' < *(char *)((int)uStackY_22 * 0x34 + 4)) &&
                      (*(char *)((int)uStackY_22 * 0x34 + 0xf) != '\0')) ||
                     ((*(char *)((int)uStackY_22 * 0x34 + 4) < '\0' &&
                      (*(char *)((int)uStackY_22 * 0x34 + 0xf) == '\0')))) {
                    *(undefined1 *)((int)uStackY_22 * 0x34 + 0x10) = 1;
                  }
                  cVar10 = '\0';
                  *(undefined2 *)((int)uStackY_22 * 0x34 + 6) = 0;
                  OVC49_8699_18c4();
                }
              }
              else {
                cVar8 = OVC49_8699_06dc();
                if (cVar8 != '\0') {
                  *(undefined2 *)((int)uStackY_22 * 0x34) = uStackY_24;
                  *(undefined2 *)((int)uStackY_22 * 0x34 + 2) = auStackY_26;
                  if ((*(char *)((int)uStackY_22 * 0x34 + 0x11) == '\0') ||
                     (*(char *)((int)uStackY_22 * 0x34 + 4) != '\0')) {
                    if (*(char *)((int)uStackY_22 * 0x34 + 0x11) == '\0') {
                      *(undefined1 *)((int)uStackY_22 * 0x34 + 4) = 0;
                    }
                    else {
                      *(char *)((int)uStackY_22 * 0x34 + 4) = -*(char *)((int)uStackY_22 * 0x34 + 4)
                      ;
                    }
                  }
                  else {
                    pcVar26 = (char *)"glassworks" + 9;
                    uVar15 = ovr_randBelow(2);
                    *(char *)((int)uStackY_22 * 0x34 + 4) = (char)uVar15 * '\x02' + -1;
                  }
                  *(undefined1 *)((int)uStackY_22 * 0x34 + 5) = 0;
                  *(undefined2 *)((int)uStackY_22 * 0x34 + 6) = 0;
                  if ((('\0' < *(char *)((int)uStackY_22 * 0x34 + 4)) &&
                      (*(char *)((int)uStackY_22 * 0x34 + 0xf) != '\0')) ||
                     ((*(char *)((int)uStackY_22 * 0x34 + 4) < '\0' &&
                      (*(char *)((int)uStackY_22 * 0x34 + 0xf) == '\0')))) {
                    *(undefined1 *)((int)uStackY_22 * 0x34 + 0x10) = 1;
                  }
                  cVar10 = '\0';
                  OVC49_8699_18c4();
                }
              }
            }
            else {
              *(undefined1 *)((int)uStackY_22 * 0x34 + 0x25) = 2;
            }
LAB_8699_2982:
            OVC49_8699_1753();
            if (cVar10 != '\0') {
              pcVar26 = (char *)"mason\'s hall" + 6;
              cVar10 = ovr_agnt_3b1d_177f();
              if (cVar10 != '\0') {
                uStackY_22 = (cte_t *)(uStackY_22[-1].info + 0xb);
              }
            }
            uStackY_22 = (cte_t *)&uStackY_22->ofs;
LAB_8699_29b9:
            if ((int)(uint)AgntCount <= (int)uStackY_22) {
              GGameState = 0x2e;
              if (DebugVerbose != false) {
                pcVar26 = (char *)&AgntAnms[0x38].field_0x18;
                printf("%d \r",0x2e);
              }
              uStackY_22 = (cte_t *)0x0;
              goto LAB_8699_3bde;
            }
            uVar24 = *(undefined2 *)((int)uStackY_22 * 0x34 + 0x15);
            iVar13 = *(int *)((int)uStackY_22 * 0x34 + 0x13);
            OVC49_8699_1753();
            OVC49_8699_0874();
            _auStackY_26 = CONCAT22(*(undefined2 *)((int)uStackY_22 * 0x34),
                                    *(undefined2 *)((int)uStackY_22 * 0x34 + 2));
            bVar7 = OVC49_8699_18c4();
            uStackY_1c = (char *)CONCAT11(bVar7,(char)uStackY_1c);
            pcVar49 = (char *)0x1726;
            uVar24 = *(undefined2 *)(iVar13 + (uint)bVar7 * 4 + 0x58);
            uVar9 = (undefined1)uVar24;
            uVar51 = (undefined1)((uint)uVar24 >> 8);
            in_stack_0000ffe8 = ovr_stash_474a_10ac();
            pcVar17 = (char *)CONCAT11(uVar51,uVar9);
            if (*(char *)((int)uStackY_22 * 0x34 + 4) < '\x01') {
              if (*(char *)((int)uStackY_22 * 0x34 + 4) < '\0') {
                *(int *)((int)uStackY_22 * 0x34) =
                     *(int *)((int)uStackY_22 * 0x34) - (int)*(char *)(in_stack_0000ffe8 + 5);
              }
            }
            else {
              *(int *)((int)uStackY_22 * 0x34) =
                   *(int *)((int)uStackY_22 * 0x34) + (int)*(char *)(in_stack_0000ffe8 + 5);
            }
            in_stack_0000ffe2 = (char *)((int)&GUnitDescriptions[5].ofs + 1);
            if (*(char *)((int)uStackY_22 * 0x34 + 5) < '\x01') {
              if (*(char *)((int)uStackY_22 * 0x34 + 5) < '\0') {
                piVar2 = (int *)((int)uStackY_22 * 0x34 + 2);
                *piVar2 = *piVar2 - *(int *)(pcVar26 + 0x11);
              }
              else {
                in_stack_0000ffe2 = (char *)0x0;
              }
            }
            else {
              piVar2 = (int *)((int)uStackY_22 * 0x34 + 2);
              *piVar2 = *piVar2 + *(int *)(pcVar26 + 0x11);
            }
          } while (*(int *)((int)uStackY_22 * 0x34 + 2) < 0x15);
          pcVar11 = uStackY_22;
        } while (*(char *)((int)uStackY_22 * 0x34 + 5) < '\x01');
        piVar2 = (int *)((int)uStackY_22 * 0x34 + 2);
        *piVar2 = *piVar2 + *(int *)(pcVar26 + 0x11);
        goto LAB_8699_21a5;
      case (cte_t *)0x1:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case (cte_t *)0x2:
        pcVar49 = ovr_fmVsprintf((char *)"%s: %s %d gold. Feeds %d %s.",(char *)*(char **)pcVar23);
        pcStack_8 = (char *)"glassworks" + 9;
        psStack_a = (stg_tmp_t *)((char *)"choose" + 4);
        strcpy(acStackY_2ca,pcVar49);
        break;
      case (cte_t *)0x3:
        SpecialColors[2] =
             ((char *)"If you lead with wisdom and cunning..." + 9)[(psStack_a->aptr).ofs];
        SpecialColors[3] =
             ((char *)"ENTER: use previous configuration, SPACE: reconfigure, ESC: quit" + 0x12)
             [(psStack_a->aptr).ofs];
        SpecialColors[4] = ((char *)"%s turns %d undead." + 0x10)[(psStack_a->aptr).ofs];
        SpecialColors[5] = *(uint8_t *)((int)&GStrangeTable[0x12].seg + 1 + (psStack_a->aptr).ofs);
        SpecialColors[6] = *(uint8_t *)((int)(uint16_t *)&DAT_2000_d43e + (psStack_a->aptr).ofs);
        SpecialColors[7] = *(uint8_t *)((psStack_a->aptr).ofs + 0x936e);
        SpecialColors[1] = bVar7;
        uVar44 = ovr_stshWrite((uint8_t *)SpecialColors,8);
        DAT_2000_d1ce = (undefined2)(uVar44 >> 0x10);
        DAT_2000_d1cc = (undefined2)uVar44;
        uVar15 = (psStack_a->aptr).seg;
        (*(uint8_t *)((uint8_t *)&(src.seg))) = (char)uVar15;
        src.ofs = (&psStack_a->aptr)->ofs;
        (*(uint8_t *)((uint8_t *)&(src.seg) + 1)) = (char)(uVar15 >> 8);
        fVar36 = ovr_stshRleCut(src,234,64,314,120);
        pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
        DAT_2000_cafb = (undefined2)((ulong)pcVar45 >> 0x10);
        DAT_2000_caf9 = (uint16_t)(pcVar45);
        uVar15 = (psStack_a->aptr).seg;
        (*(uint8_t *)((uint8_t *)&(src_00.seg))) = (char)uVar15;
        src_00.ofs = (&psStack_a->aptr)->ofs;
        (*(uint8_t *)((uint8_t *)&(src_00.seg) + 1)) = (char)(uVar15 >> 8);
        fVar36 = ovr_stshRleCut(src_00,208,158,228,176);
        pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
        DAT_2000_cb13 = (undefined2)((ulong)pcVar45 >> 0x10);
        DAT_2000_cb11 = (uint16_t)(pcVar45);
        uVar15 = (psStack_a->aptr).seg;
        (*(uint8_t *)((uint8_t *)&(src_01.seg))) = (char)uVar15;
        src_01.ofs = (&psStack_a->aptr)->ofs;
        (*(uint8_t *)((uint8_t *)&(src_01.seg) + 1)) = (char)(uVar15 >> 8);
        fVar36 = ovr_stshRleCut(src_01,179,180,198,196);
        pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
        DAT_2000_cacb = (undefined2)((ulong)pcVar45 >> 0x10);
        DAT_2000_cac9 = (uint16_t)(pcVar45);
        uVar15 = (psStack_a->aptr).seg;
        (*(uint8_t *)((uint8_t *)&(src_02.seg))) = (char)uVar15;
        src_02.ofs = (&psStack_a->aptr)->ofs;
        (*(uint8_t *)((uint8_t *)&(src_02.seg) + 1)) = (char)(uVar15 >> 8);
        fVar36 = ovr_stshRleCut(src_02,207,180,226,196);
        pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
        DAT_2000_cac7 = (undefined2)((ulong)pcVar45 >> 0x10);
        DAT_2000_cac5 = (uint16_t)(pcVar45);
        uVar15 = (psStack_a->aptr).seg;
        (*(uint8_t *)((uint8_t *)&(src_03.seg))) = (char)uVar15;
        src_03.ofs = (&psStack_a->aptr)->ofs;
        (*(uint8_t *)((uint8_t *)&(src_03.seg) + 1)) = (char)(uVar15 >> 8);
        fVar36 = ovr_stshRleCut(src_03,38,181,57,196);
        pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
        DAT_2000_cac3 = (undefined2)((ulong)pcVar45 >> 0x10);
        DAT_2000_cac1 = (uint16_t)(pcVar45);
        uVar15 = (psStack_a->aptr).seg;
        (*(uint8_t *)((uint8_t *)&(src_04.seg))) = (char)uVar15;
        src_04.ofs = (&psStack_a->aptr)->ofs;
        (*(uint8_t *)((uint8_t *)&(src_04.seg) + 1)) = (char)(uVar15 >> 8);
        fVar36 = ovr_stshRleCut(src_04,9,181,24,196);
        pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
        DAT_2000_cabf = (undefined2)((ulong)pcVar45 >> 0x10);
        DAT_2000_cabd = (uint16_t)(pcVar45);
        ovr_stgFreeTmp((stg_tmp_t *)
                       CONCAT13((char)((uint)pcStack_8 >> 8),CONCAT12((char)pcStack_8,psStack_a)));
        if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
          fVar36 = ovr_stshAllocStub();
          DAT_2000_ca3a = fVar36.seg;
          DAT_2000_ca38 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_caf7 = fVar36.seg;
          DAT_2000_caf5 = (uint16_t)(fVar36.ofs);
          fVar27 = ovr_stshAllocStub();
          psVar43 = (stg_tmp_t *)CONCAT22(pcStack_8,psStack_a);
        }
        else {
          psVar43 = ovr_grabLbmTR(127);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          psVar12 = (stg_tmp_t *)psVar43;
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_05.seg))) = (char)uVar15;
          src_05.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_05.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_05,245,116,267,128);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_ca3a = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_ca38 = (uint16_t)(pcVar45);
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_06.seg))) = (char)uVar15;
          src_06.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_06.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_06,292,114,314,133);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_caf7 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_caf5 = (uint16_t)(pcVar45);
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_07.seg))) = (char)uVar15;
          src_07.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_07.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_07,221,157,228,198);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_caf3 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_caf1 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          fVar27.seg = DAT_2000_caf3;
          fVar27.ofs = (uint16_t)DAT_2000_caf1;
        }
        DAT_2000_caf3 = fVar27.seg;
        DAT_2000_caf1 = (uint16_t)(fVar27.ofs);
        if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
          Lbm_nwpanel1 = ovr_stshAllocStub();
          fVar36 = ovr_stshAllocStub();
          DAT_2000_caff = fVar36.seg;
          DAT_2000_cafd = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_cacf = fVar36.seg;
          DAT_2000_cacd = (uint16_t)(fVar36.ofs);
          FontHandle = ovr_stshAllocStub();
          fVar36 = ovr_stshAllocStub();
          DAT_2000_cabb = fVar36.seg;
          DAT_2000_cab9 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_caab = fVar36.seg;
          DAT_2000_caa9 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d1aa = fVar36.seg;
          DAT_2000_d1a8 = (uint16_t)(fVar36.ofs);
          fVar28 = ovr_stshAllocStub();
        }
        else {
          psVar43 = ovr_grabLbm(15,0,0);
          psVar12 = (stg_tmp_t *)psVar43;
          Lbm_nwpanel1 = far_from_u32((uint32_t)(ovr_stshWrite(psVar12->cmap,0x300)));
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_08.seg))) = (char)uVar15;
          src_08.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_08.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_08,230,57,314,113);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_caff = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_cafd = (uint16_t)(pcVar45);
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_09.seg))) = (char)uVar15;
          src_09.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_09.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_09,0,0,319,199);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_cacf = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_cacd = (uint16_t)(pcVar45);
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_10.seg))) = (char)uVar15;
          src_10.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_10.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_10,29,156,207,199);
          FontHandle = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs))));
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_11.seg))) = (char)uVar15;
          src_11.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_11.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_11,9,181,28,196);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_cabb = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_cab9 = (uint16_t)(pcVar45);
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_12.seg))) = (char)uVar15;
          src_12.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_12.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_12,223,8,237,50);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_caab = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_caa9 = (uint16_t)(pcVar45);
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_13.seg))) = (char)uVar15;
          src_13.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_13.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_13,6,156,28,171);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d1aa = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d1a8 = (uint16_t)(pcVar45);
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_14.seg))) = (char)uVar15;
          src_14.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_14.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_14,208,157,229,198);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d119 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d117 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          fVar28.seg = DAT_2000_d119;
          fVar28.ofs = (uint16_t)DAT_2000_d117;
        }
        DAT_2000_d119 = fVar28.seg;
        DAT_2000_d117 = (uint16_t)(fVar28.ofs);
        if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
          iVar13 = 0;
          while( true ) {
            DAT_2000_d119 = fVar28.seg;
            DAT_2000_d117 = (uint16_t)(fVar28.ofs);
            if (3 < iVar13) break;
            fVar36 = ovr_stshAllocStub();
            *(uint16_t *)((int)&CrossBlitGfx.seg + iVar13 * 4) = fVar36.seg;
            ((far_t *)&CrossBlitGfx + iVar13)->ofs = fVar36.ofs;
            fVar36 = ovr_stshAllocStub();
            ((undefined2 *)&DAT_2000_cc67)[iVar13 * 2] = fVar36.seg;
            ((undefined2 *)&DAT_2000_cc65)[iVar13 * 2] = fVar36.ofs;
            fVar28.seg = DAT_2000_d119;
            fVar28.ofs = (uint16_t)DAT_2000_d117;
            iVar13 = iVar13 + 1;
          }
        }
        else {
          psVar43 = ovr_grabLbm(12,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          psVar12 = (stg_tmp_t *)psVar43;
          for (iVar13 = 0; iVar13 < 4; iVar13 = iVar13 + 1) {
            uVar15 = (psVar12->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(src_15.seg))) = (char)uVar15;
            src_15.ofs = (&psVar12->aptr)->ofs;
            (*(uint8_t *)((uint8_t *)&(src_15.seg) + 1)) = (char)(uVar15 >> 8);
            fVar36 = ovr_stshRleCut(src_15,iVar13 * 0xe,46,iVar13 * 0xe + 0xd,55);
            pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
            *(undefined2 *)((int)&CrossBlitGfx.seg + iVar13 * 4) = (int)((ulong)pcVar45 >> 0x10);
            ((far_t *)&CrossBlitGfx + iVar13)->ofs = (uint16_t)(cte_t *)pcVar45;
            pixels.seg = (psVar12->aptr).seg;
            pixels.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)ovr_stshRleType2(pixels,iVar13 * 0xe,16,iVar13 * 0xe + 0xd,24,6,4);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cc67)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cc65)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          ovr_stgFreeTmp(psVar43);
          fVar28.seg = DAT_2000_d119;
          fVar28.ofs = (uint16_t)DAT_2000_d117;
        }
        DAT_2000_d119 = fVar28.seg;
        DAT_2000_d117 = (uint16_t)(fVar28.ofs);
        if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
          iVar13 = 0;
          while( true ) {
            DAT_2000_d119 = fVar28.seg;
            DAT_2000_d117 = (uint16_t)(fVar28.ofs);
            if (0x16 < iVar13) break;
            fVar36 = ovr_stshAllocStub();
            ((undefined2 *)&DAT_2000_cc0b)[iVar13 * 2] = fVar36.seg;
            ((undefined2 *)&DAT_2000_cc09)[iVar13 * 2] = fVar36.ofs;
            fVar28.seg = DAT_2000_d119;
            fVar28.ofs = (uint16_t)DAT_2000_d117;
            iVar13 = iVar13 + 1;
          }
          iVar13 = 0;
          while( true ) {
            DAT_2000_d119 = fVar28.seg;
            DAT_2000_d117 = (uint16_t)(fVar28.ofs);
            if (0x17 < iVar13) break;
            fVar36 = ovr_stshAllocStub();
            ((undefined2 *)&DAT_2000_cbab)[iVar13 * 2] = fVar36.seg;
            ((undefined2 *)&DAT_2000_cba9)[iVar13 * 2] = fVar36.ofs;
            fVar28.seg = DAT_2000_d119;
            fVar28.ofs = (uint16_t)DAT_2000_d117;
            iVar13 = iVar13 + 1;
          }
          iVar13 = 0;
          while( true ) {
            DAT_2000_d119 = fVar28.seg;
            DAT_2000_d117 = (uint16_t)(fVar28.ofs);
            if (0x1f < iVar13) break;
            fVar36 = ovr_stshAllocStub();
            ((undefined2 *)&DAT_2000_cb2b)[iVar13 * 2] = fVar36.seg;
            ((undefined2 *)&DAT_2000_cb29)[iVar13 * 2] = fVar36.ofs;
            fVar28.seg = DAT_2000_d119;
            fVar28.ofs = (uint16_t)DAT_2000_d117;
            iVar13 = iVar13 + 1;
          }
          iVar13 = 0;
          while( true ) {
            DAT_2000_d119 = fVar28.seg;
            DAT_2000_d117 = (uint16_t)(fVar28.ofs);
            if (0xd < iVar13) break;
            fVar36 = ovr_stshAllocStub();
            ((undefined2 *)&DAT_2000_d2a0)[iVar13 * 2] = fVar36.seg;
            ((undefined2 *)&DAT_2000_d29e)[iVar13 * 2] = fVar36.ofs;
            fVar28.seg = DAT_2000_d119;
            fVar28.ofs = (uint16_t)DAT_2000_d117;
            iVar13 = iVar13 + 1;
          }
          iVar13 = 0;
          while( true ) {
            DAT_2000_d119 = fVar28.seg;
            DAT_2000_d117 = (uint16_t)(fVar28.ofs);
            if (0x10 < iVar13) break;
            fVar36 = ovr_stshAllocStub();
            ((undefined2 *)&DAT_2000_d25c)[iVar13 * 2] = fVar36.seg;
            ((undefined2 *)&DAT_2000_d25a)[iVar13 * 2] = fVar36.ofs;
            fVar28.seg = DAT_2000_d119;
            fVar28.ofs = (uint16_t)DAT_2000_d117;
            iVar13 = iVar13 + 1;
          }
          iVar13 = 0;
          while( true ) {
            DAT_2000_d119 = fVar28.seg;
            DAT_2000_d117 = (uint16_t)(fVar28.ofs);
            if (6 < iVar13) break;
            fVar36 = ovr_stshAllocStub();
            ((undefined2 *)&DAT_2000_d240)[iVar13 * 2] = fVar36.seg;
            ((undefined2 *)&DAT_2000_d23e)[iVar13 * 2] = fVar36.ofs;
            fVar28.seg = DAT_2000_d119;
            fVar28.ofs = (uint16_t)DAT_2000_d117;
            iVar13 = iVar13 + 1;
          }
          iVar13 = 0;
          while( true ) {
            DAT_2000_d119 = fVar28.seg;
            DAT_2000_d117 = (uint16_t)(fVar28.ofs);
            if (6 < iVar13) break;
            fVar36 = ovr_stshAllocStub();
            ((undefined2 *)&DAT_2000_d224)[iVar13 * 2] = fVar36.seg;
            ((undefined2 *)&DAT_2000_d222)[iVar13 * 2] = fVar36.ofs;
            fVar28.seg = DAT_2000_d119;
            fVar28.ofs = (uint16_t)DAT_2000_d117;
            iVar13 = iVar13 + 1;
          }
          iVar13 = 0;
          while( true ) {
            DAT_2000_d119 = fVar28.seg;
            DAT_2000_d117 = (uint16_t)(fVar28.ofs);
            if (7 < iVar13) break;
            fVar36 = ovr_stshAllocStub();
            ((undefined2 *)&DAT_2000_d204)[iVar13 * 2] = fVar36.seg;
            ((undefined2 *)&DAT_2000_d202)[iVar13 * 2] = fVar36.ofs;
            fVar28.seg = DAT_2000_d119;
            fVar28.ofs = (uint16_t)DAT_2000_d117;
            iVar13 = iVar13 + 1;
          }
          iVar13 = 0;
          while( true ) {
            DAT_2000_d119 = fVar28.seg;
            DAT_2000_d117 = (uint16_t)(fVar28.ofs);
            if (4 < iVar13) break;
            fVar36 = ovr_stshAllocStub();
            ((undefined2 *)&DAT_2000_d1f0)[iVar13 * 2] = fVar36.seg;
            ((undefined2 *)&DAT_2000_d1ee)[iVar13 * 2] = fVar36.ofs;
            fVar28.seg = DAT_2000_d119;
            fVar28.ofs = (uint16_t)DAT_2000_d117;
            iVar13 = iVar13 + 1;
          }
        }
        else {
          psVar43 = ovr_grabLbm(93,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          psVar12 = (stg_tmp_t *)psVar43;
          for (iVar13 = 0; iVar13 < 6; iVar13 = iVar13 + 1) {
            pixels_00.seg = (psVar12->aptr).seg;
            pixels_00.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_00,8,iVar13 * 0x20 + 10,63,iVar13 * 0x20 + 0x24,0,0);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cc0b)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cc09)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          for (iVar13 = 0; iVar13 < 6; iVar13 = iVar13 + 1) {
            pixels_01.seg = (psVar12->aptr).seg;
            pixels_01.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_01,85,iVar13 * 0x20 + 10,140,iVar13 * 0x20 + 0x24,0,0)
            ;
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cc23)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cc21)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          for (iVar13 = 0; iVar13 < 6; iVar13 = iVar13 + 1) {
            pixels_02.seg = (psVar12->aptr).seg;
            pixels_02.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_02,159,iVar13 * 0x20 + 10,214,iVar13 * 0x20 + 0x24,0,0
                                      );
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cc3b)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cc39)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          for (iVar13 = 0; iVar13 < 5; iVar13 = iVar13 + 1) {
            pixels_03.seg = (psVar12->aptr).seg;
            pixels_03.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_03,229,iVar13 * 0x20 + 10,284,iVar13 * 0x20 + 0x24,0,0
                                      );
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cc53)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cc51)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(94,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          psVar12 = (stg_tmp_t *)psVar43;
          for (iVar13 = 0; iVar13 < 3; iVar13 = iVar13 + 1) {
            pixels_04.seg = (psVar12->aptr).seg;
            pixels_04.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_04,0,iVar13 * 0x3d + 0x11,104,iVar13 * 0x3d + 0x49,0,
                                       -60);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cbab)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cba9)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          for (iVar13 = 0; iVar13 < 3; iVar13 = iVar13 + 1) {
            pixels_05.seg = (psVar12->aptr).seg;
            pixels_05.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_05,109,iVar13 * 0x3d + 0x11,213,iVar13 * 0x3d + 0x49,0
                                       ,-60);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cbb7)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cbb5)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          for (iVar13 = 0; iVar13 < 3; iVar13 = iVar13 + 1) {
            pixels_06.seg = (psVar12->aptr).seg;
            pixels_06.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_06,215,iVar13 * 0x3d + 0x11,319,iVar13 * 0x3d + 0x49,0
                                       ,-60);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cbc3)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cbc1)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(95,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          psVar12 = (stg_tmp_t *)psVar43;
          for (iVar13 = 0; iVar13 < 3; iVar13 = iVar13 + 1) {
            pixels_07.seg = (psVar12->aptr).seg;
            pixels_07.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_07,0,iVar13 * 0x3d + 0x11,104,iVar13 * 0x3d + 0x49,0,
                                       -60);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cbcf)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cbcd)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          for (iVar13 = 0; iVar13 < 3; iVar13 = iVar13 + 1) {
            pixels_08.seg = (psVar12->aptr).seg;
            pixels_08.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_08,109,iVar13 * 0x3d + 0x11,213,iVar13 * 0x3d + 0x49,0
                                       ,-60);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cbdb)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cbd9)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(96,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          psVar12 = (stg_tmp_t *)psVar43;
          for (iVar13 = 0; iVar13 < 3; iVar13 = iVar13 + 1) {
            pixels_09.seg = (psVar12->aptr).seg;
            pixels_09.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_09,0,iVar13 * 0x3d + 0x11,104,iVar13 * 0x3d + 0x49,0,
                                       -60);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cbe7)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cbe5)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          for (iVar13 = 0; iVar13 < 3; iVar13 = iVar13 + 1) {
            pixels_10.seg = (psVar12->aptr).seg;
            pixels_10.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_10,109,iVar13 * 0x3d + 0x11,213,iVar13 * 0x3d + 0x49,0
                                       ,-60);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cbf3)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cbf1)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          for (iVar13 = 0; iVar13 < 3; iVar13 = iVar13 + 1) {
            pixels_11.seg = (psVar12->aptr).seg;
            pixels_11.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_11,215,iVar13 * 0x3d + 0x11,319,iVar13 * 0x3d + 0x49,0
                                       ,-60);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cbff)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cbfd)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(531,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          psVar12 = (stg_tmp_t *)psVar43;
          for (iVar13 = 0; iVar13 < 3; iVar13 = iVar13 + 1) {
            pixels_12.seg = (psVar12->aptr).seg;
            pixels_12.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_12,1,iVar13 * 0x3d + 0x11,103,iVar13 * 0x3d + 0x49,-4,
                                       -60);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cb2b)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cb29)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          for (iVar13 = 0; iVar13 < 3; iVar13 = iVar13 + 1) {
            pixels_13.seg = (psVar12->aptr).seg;
            pixels_13.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_13,104,iVar13 * 0x3d + 0x11,206,iVar13 * 0x3d + 0x49,
                                       -4,-60);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cb37)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cb35)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          for (iVar13 = 0; iVar13 < 3; iVar13 = iVar13 + 1) {
            pixels_14.seg = (psVar12->aptr).seg;
            pixels_14.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_14,209,iVar13 * 0x3d + 0x11,311,iVar13 * 0x3d + 0x49,
                                       -4,-60);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cb43)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cb41)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(532,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          psVar12 = (stg_tmp_t *)psVar43;
          for (iVar13 = 0; iVar13 < 3; iVar13 = iVar13 + 1) {
            pixels_15.seg = (psVar12->aptr).seg;
            pixels_15.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_15,1,iVar13 * 0x3d + 0x11,103,iVar13 * 0x3d + 0x49,-4,
                                       -60);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cb4f)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cb4d)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          for (iVar13 = 0; iVar13 < 3; iVar13 = iVar13 + 1) {
            pixels_16.seg = (psVar12->aptr).seg;
            pixels_16.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_16,104,iVar13 * 0x3d + 0x11,206,iVar13 * 0x3d + 0x49,
                                       -4,-60);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cb5b)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cb59)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          for (iVar13 = 0; iVar13 < 3; iVar13 = iVar13 + 1) {
            pixels_17.seg = (psVar12->aptr).seg;
            pixels_17.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_17,209,iVar13 * 0x3d + 0x11,311,iVar13 * 0x3d + 0x49,
                                       -4,-60);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cb67)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cb65)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(533,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          psVar12 = (stg_tmp_t *)psVar43;
          for (iVar13 = 0; iVar13 < 3; iVar13 = iVar13 + 1) {
            pixels_18.seg = (psVar12->aptr).seg;
            pixels_18.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_18,1,iVar13 * 0x3d + 0x11,103,iVar13 * 0x3d + 0x49,-4,
                                       -60);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cb73)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cb71)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          for (iVar13 = 0; iVar13 < 3; iVar13 = iVar13 + 1) {
            pixels_19.seg = (psVar12->aptr).seg;
            pixels_19.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_19,104,iVar13 * 0x3d + 0x11,206,iVar13 * 0x3d + 0x49,
                                       -4,-60);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cb7f)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cb7d)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          for (iVar13 = 0; iVar13 < 3; iVar13 = iVar13 + 1) {
            pixels_20.seg = (psVar12->aptr).seg;
            pixels_20.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_20,209,iVar13 * 0x3d + 0x11,311,iVar13 * 0x3d + 0x49,
                                       -4,-60);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cb8b)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cb89)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(534,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          psVar12 = (stg_tmp_t *)psVar43;
          for (iVar13 = 0; iVar13 < 3; iVar13 = iVar13 + 1) {
            pixels_21.seg = (psVar12->aptr).seg;
            pixels_21.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_21,1,iVar13 * 0x3d + 0x11,103,iVar13 * 0x3d + 0x49,-4,
                                       -60);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cb97)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cb95)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          for (iVar13 = 0; iVar13 < 2; iVar13 = iVar13 + 1) {
            pixels_22.seg = (psVar12->aptr).seg;
            pixels_22.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_22,104,iVar13 * 0x3d + 0x11,206,iVar13 * 0x3d + 0x49,
                                       -4,-60);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_cba3)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_cba1)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(535,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          psVar12 = (stg_tmp_t *)psVar43;
          for (iVar13 = 0; iVar13 < 7; iVar13 = iVar13 + 1) {
            pixels_23.seg = (psVar12->aptr).seg;
            pixels_23.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_23,6,iVar13 * 0x1b + 8,33,iVar13 * 0x1b + 0x13,0,0);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_d2a0)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_d29e)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          for (iVar13 = 0; iVar13 < 7; iVar13 = iVar13 + 1) {
            pixels_24.seg = (psVar12->aptr).seg;
            pixels_24.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_24,35,iVar13 * 0x1b + 8,62,iVar13 * 0x1b + 0x13,0,0);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_d2bc)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_d2ba)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          for (iVar13 = 0; iVar13 < 7; iVar13 = iVar13 + 1) {
            pixels_25.seg = (psVar12->aptr).seg;
            pixels_25.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_25,76,iVar13 * 0x1b + 8,88,iVar13 * 0x1b + 0x13,0,0);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_d25c)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_d25a)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          for (iVar13 = 0; iVar13 < 7; iVar13 = iVar13 + 1) {
            pixels_26.seg = (psVar12->aptr).seg;
            pixels_26.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_26,102,iVar13 * 0x1b + 8,114,iVar13 * 0x1b + 0x13,0,0)
            ;
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_d278)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_d276)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          for (iVar13 = 0; iVar13 < 3; iVar13 = iVar13 + 1) {
            pixels_27.seg = (psVar12->aptr).seg;
            pixels_27.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_27,128,iVar13 * 0x1b + 8,140,iVar13 * 0x1b + 0x13,0,0)
            ;
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_d294)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_d292)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          for (iVar13 = 0; iVar13 < 7; iVar13 = iVar13 + 1) {
            pixels_28.seg = (psVar12->aptr).seg;
            pixels_28.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_28,154,iVar13 * 0x1b + 8,163,iVar13 * 0x1b + 0x13,0,0)
            ;
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_d240)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_d23e)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          for (iVar13 = 0; iVar13 < 7; iVar13 = iVar13 + 1) {
            pixels_29.seg = (psVar12->aptr).seg;
            pixels_29.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_29,184,iVar13 * 0x1b + 8,185,iVar13 * 0x1b + 0x13,0,0)
            ;
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_d224)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_d222)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          for (iVar13 = 0; iVar13 < 7; iVar13 = iVar13 + 1) {
            pixels_30.seg = (psVar12->aptr).seg;
            pixels_30.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_30,207,iVar13 * 0x1b + 8,223,iVar13 * 0x1b + 0x13,0,0)
            ;
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_d204)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_d202)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          pixels_31.seg = (psVar12->aptr).seg;
          pixels_31.ofs = (&psVar12->aptr)->ofs;
          puVar33 = (uint8_t *)ovr_stshRleType2(pixels_31,235,8,251,19,0,0);
          pcVar45 = ovr_stshStoreFile(puVar33);
          iVar13 = 0;
          while( true ) {
            DAT_2000_d220 = (undefined2)((ulong)pcVar45 >> 0x10);
            DAT_2000_d21e = (uint16_t)(pcVar45);
            if (4 < iVar13) break;
            pixels_32.seg = (psVar12->aptr).seg;
            pixels_32.ofs = (&psVar12->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_32,267,iVar13 * 0x1b + 8,286,iVar13 * 0x1b + 0x13,0,0)
            ;
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_d1f0)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_d1ee)[iVar13 * 2] = (uint16_t)(pcVar45);
            pcVar45 = (cte_t *)CONCAT22(DAT_2000_d220,DAT_2000_d21e);
            iVar13 = iVar13 + 1;
          }
          ovr_stgFreeTmp(psVar43);
          fVar28.seg = DAT_2000_d119;
          fVar28.ofs = (uint16_t)DAT_2000_d117;
        }
        DAT_2000_d119 = fVar28.seg;
        DAT_2000_d117 = (uint16_t)(fVar28.ofs);
        if ((*(uint8_t *)((uint8_t *)&(param_1))) != false) {
          psVar43 = ovr_grabLbm(35,0,0);
          fVar28.seg = DAT_2000_d119;
          fVar28.ofs = (uint16_t)DAT_2000_d117;
        }
        pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
        psStack_a = (stg_tmp_t *)psVar43;
        iVar13 = 0;
        while( true ) {
          DAT_2000_d119 = fVar28.seg;
          DAT_2000_d117 = (uint16_t)(fVar28.ofs);
          if (3 < iVar13) break;
          if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
            fVar36 = ovr_stshAllocStub();
            ((undefined2 *)&DAT_2000_d2ee)[iVar13 * 2] = fVar36.seg;
            ((undefined2 *)&DAT_2000_d2ec)[iVar13 * 2] = fVar36.ofs;
          }
          else {
            pixels_33.seg = (psStack_a->aptr).seg;
            pixels_33.ofs = (&psStack_a->aptr)->ofs;
            puVar33 = (uint8_t *)
                      ovr_stshRleType2(pixels_33,iVar13 * 0x16,0,iVar13 * 0x16 + 0x15,14,11,7);
            pcVar45 = ovr_stshStoreFile(puVar33);
            ((undefined2 *)&DAT_2000_d2ee)[iVar13 * 2] = (int)((ulong)pcVar45 >> 0x10);
            ((undefined2 *)&DAT_2000_d2ec)[iVar13 * 2] = (uint16_t)(pcVar45);
          }
          fVar28.seg = DAT_2000_d119;
          fVar28.ofs = (uint16_t)DAT_2000_d117;
          iVar13 = iVar13 + 1;
        }
        if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
          fVar29 = ovr_stshAllocStub();
        }
        else {
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(8,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          uVar15 = (((stg_tmp_t *)psVar43)->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_16.seg))) = (char)uVar15;
          src_16.ofs = (&((stg_tmp_t *)psVar43)->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_16.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_16,0,0,319,199);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d1ca = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d1c8 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          fVar29.seg = DAT_2000_d1ca;
          fVar29.ofs = (uint16_t)DAT_2000_d1c8;
        }
        DAT_2000_d1ca = fVar29.seg;
        DAT_2000_d1c8 = (uint16_t)(fVar29.ofs);
        if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
          fVar30 = ovr_stshAllocStub();
        }
        else {
          psVar43 = ovr_grabLbm(6,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          uVar15 = (((stg_tmp_t *)psVar43)->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_17.seg))) = (char)uVar15;
          src_17.ofs = (&((stg_tmp_t *)psVar43)->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_17.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_17,0,0,319,199);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d1c6 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d1c4 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          fVar30.seg = DAT_2000_d1c6;
          fVar30.ofs = (uint16_t)DAT_2000_d1c4;
        }
        DAT_2000_d1c6 = fVar30.seg;
        DAT_2000_d1c4 = (uint16_t)(fVar30.ofs);
        if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
          fVar31 = ovr_stshAllocStub();
        }
        else {
          psVar43 = ovr_grabLbm(140,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          uVar15 = (((stg_tmp_t *)psVar43)->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_18.seg))) = (char)uVar15;
          src_18.ofs = (&((stg_tmp_t *)psVar43)->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_18.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_18,0,0,319,27);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d1c2 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d1c0 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          fVar31.seg = DAT_2000_d1c2;
          fVar31.ofs = (uint16_t)DAT_2000_d1c0;
        }
        DAT_2000_d1c2 = fVar31.seg;
        DAT_2000_d1c0 = (uint16_t)(fVar31.ofs);
        if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
          fVar32 = ovr_stshAllocStub();
        }
        else {
          psVar43 = ovr_grabLbm(411,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          FontSize.hi = 0;
          FontSize.lo = 0;
          uVar15 = (((stg_tmp_t *)psVar43)->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(hndl.seg))) = (char)uVar15;
          hndl.ofs = (&((stg_tmp_t *)psVar43)->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(hndl.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshProcessFontSub(hndl);
          uVar44 = ovr_stshWrite((uint8_t *)fVar36.ofs,
                                 CONCAT13((char)(FontSize.hi >> 8),
                                          CONCAT12((char)FontSize.hi,FontSize.lo)));
          DAT_2000_d47e = (uint16_t)(uVar44 >> 0x10);
          DAT_2000_d47c = (uint16_t)uVar44;
          ovr_stgFreeTmp(psVar43);
          fVar32.seg = DAT_2000_d47e;
          fVar32.ofs = DAT_2000_d47c;
        }
        DAT_2000_d47e = fVar32.seg;
        DAT_2000_d47c = fVar32.ofs;
        if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
          fVar36 = ovr_stshAllocStub();
          DAT_2000_cc87 = fVar36.seg;
          DAT_2000_cc85 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d3a6 = fVar36.seg;
          DAT_2000_d3a4 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d3a2 = fVar36.seg;
          DAT_2000_d3a0 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d39e = fVar36.seg;
          DAT_2000_d39c = (uint16_t)(fVar36.ofs);
          fVar34 = ovr_stshAllocStub();
        }
        else {
          psVar43 = ovr_grabLbm(78,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          psVar12 = (stg_tmp_t *)psVar43;
          pixels_34.seg = (psVar12->aptr).seg;
          pixels_34.ofs = (&psVar12->aptr)->ofs;
          puVar33 = (uint8_t *)ovr_stshRleType2(pixels_34,8,3,226,194,-8,-3);
          pcVar45 = ovr_stshStoreFile(puVar33);
          DAT_2000_cc87 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_cc85 = (uint16_t)(pcVar45);
          pixels_35.seg = (psVar12->aptr).seg;
          pixels_35.ofs = (&psVar12->aptr)->ofs;
          puVar33 = (uint8_t *)ovr_stshRleType2(pixels_35,221,157,229,198,-221,-157);
          pcVar45 = ovr_stshStoreFile(puVar33);
          DAT_2000_d3a6 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d3a4 = (uint16_t)(pcVar45);
          pixels_36.seg = (psVar12->aptr).seg;
          pixels_36.ofs = (&psVar12->aptr)->ofs;
          puVar33 = (uint8_t *)ovr_stshRleType2(pixels_36,208,195,223,199,-208,-195);
          pcVar45 = ovr_stshStoreFile(puVar33);
          DAT_2000_d3a2 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d3a0 = (uint16_t)(pcVar45);
          pixels_37.seg = (psVar12->aptr).seg;
          pixels_37.ofs = (&psVar12->aptr)->ofs;
          puVar33 = (uint8_t *)ovr_stshRleType2(pixels_37,8,117,226,194,-8,-117);
          pcVar45 = ovr_stshStoreFile(puVar33);
          DAT_2000_d39e = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d39c = (uint16_t)(pcVar45);
          uVar44 = ovr_stshWrite(psVar12->cmap,0x300);
          DAT_2000_d386 = (uint16_t)(uVar44 >> 0x10);
          DAT_2000_d384 = (uint16_t)uVar44;
          ovr_stgFreeTmp(psVar43);
          fVar34.seg = DAT_2000_d386;
          fVar34.ofs = DAT_2000_d384;
        }
        DAT_2000_d386 = fVar34.seg;
        DAT_2000_d384 = fVar34.ofs;
        if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
          LbxButton2 = ovr_stshAllocStub();
          fVar35 = ovr_stshAllocStub();
          pcVar21 = (char *)"puppetmaker" + 3;
code_r0x00083f6a:
          *(uint16_t *)&DAT_2000_d36e = fVar35.seg;
          *(cte_t **)&DAT_2000_d36c = (cte_t *)fVar35.ofs;
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d372 = fVar36.seg;
          DAT_2000_d370 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d376 = fVar36.seg;
          DAT_2000_d374 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d37a = fVar36.seg;
          DAT_2000_d378 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d37e = fVar36.seg;
          DAT_2000_d37c = (uint16_t)(fVar36.ofs);
          fVar37 = ovr_stshAllocStub();
        }
        else {
          psVar43 = ovr_grabLbm(543,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          uVar15 = (((stg_tmp_t *)psVar43)->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_19.seg))) = (char)uVar15;
          src_19.ofs = (&((stg_tmp_t *)psVar43)->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_19.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_19,8,5,16,10);
          LbxButton2 = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs))));
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(139,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          psVar12 = (stg_tmp_t *)psVar43;
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_20.seg))) = (char)uVar15;
          src_20.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_20.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_20,16,121,57,131);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d36e = (undefined2)((ulong)pcVar45 >> 0x10);
          DAT_2000_d36c = (uint16_t)(pcVar45);
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_21.seg))) = (char)uVar15;
          src_21.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_21.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_21,16,134,57,144);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d372 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d370 = (uint16_t)(pcVar45);
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_22.seg))) = (char)uVar15;
          src_22.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_22.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_22,234,121,300,131);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d376 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d374 = (uint16_t)(pcVar45);
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_23.seg))) = (char)uVar15;
          src_23.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_23.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_23,234,134,300,144);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d37a = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d378 = (uint16_t)(pcVar45);
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_24.seg))) = (char)uVar15;
          src_24.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_24.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_24,153,121,230,131);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d37e = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d37c = (uint16_t)(pcVar45);
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_25.seg))) = (char)uVar15;
          src_25.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_25.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_25,153,134,230,144);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d382 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d380 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          fVar37.seg = DAT_2000_d382;
          fVar37.ofs = (uint16_t)DAT_2000_d380;
        }
        DAT_2000_d382 = fVar37.seg;
        DAT_2000_d380 = (uint16_t)(fVar37.ofs);
        if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
          fVar36 = ovr_stshAllocStub();
          DAT_2000_cab7 = fVar36.seg;
          DAT_2000_cab5 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_cab3 = fVar36.seg;
          DAT_2000_cab1 = (uint16_t)(fVar36.ofs);
          fVar38 = ovr_stshAllocStub();
        }
        else {
          psVar43 = ovr_grabLbm(179,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          psVar12 = (stg_tmp_t *)psVar43;
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_26.seg))) = (char)uVar15;
          src_26.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_26.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_26,94,47,108,89);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_cab7 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_cab5 = (uint16_t)(pcVar45);
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_27.seg))) = (char)uVar15;
          src_27.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_27.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_27,114,47,128,89);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_cab3 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_cab1 = (uint16_t)(pcVar45);
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_28.seg))) = (char)uVar15;
          src_28.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_28.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_28,223,8,237,50);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_caaf = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_caad = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          fVar38.seg = DAT_2000_caaf;
          fVar38.ofs = (uint16_t)DAT_2000_caad;
        }
        DAT_2000_caaf = fVar38.seg;
        DAT_2000_caad = (uint16_t)(fVar38.ofs);
        if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d3d6 = fVar36.seg;
          DAT_2000_d3d4 = fVar36.ofs;
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d3ee = fVar36.seg;
          DAT_2000_d3ec = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d3fe = fVar36.seg;
          DAT_2000_d3fc = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d40e = fVar36.seg;
          DAT_2000_d40c = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d41e = fVar36.seg;
          DAT_2000_d41c = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d42e = fVar36.seg;
          DAT_2000_d42c = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d3d2 = fVar36.seg;
          DAT_2000_d3d0 = fVar36.ofs;
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d3ea = fVar36.seg;
          DAT_2000_d3e8 = (uint16_t)(fVar36.ofs);
          far_t_2000_d3e4 = ovr_stshAllocStub();
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d3da = fVar36.seg;
          DAT_2000_d3d8 = fVar36.ofs;
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d3f2 = fVar36.seg;
          DAT_2000_d3f0 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d402 = fVar36.seg;
          DAT_2000_d400 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d412 = fVar36.seg;
          DAT_2000_d410 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d422 = fVar36.seg;
          DAT_2000_d420 = (uint16_t)(fVar36.ofs);
          fVar39 = ovr_stshAllocStub();
        }
        else {
          psVar43 = ovr_grabLbm(158,0,0);
          psVar12 = (stg_tmp_t *)psVar43;
          uVar44 = ovr_stshWrite(psVar12->cmap,0x300);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          DAT_2000_d3d6 = (uint16_t)(uVar44 >> 0x10);
          DAT_2000_d3d4 = (uint16_t)uVar44;
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_29.seg))) = (char)uVar15;
          src_29.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_29.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_29,0,0,319,80);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d3ee = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d3ec = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(159,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          uVar15 = (((stg_tmp_t *)psVar43)->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_30.seg))) = (char)uVar15;
          src_30.ofs = (&((stg_tmp_t *)psVar43)->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_30.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_30,0,0,219,143);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d3fe = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d3fc = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(159,220,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          uVar15 = (((stg_tmp_t *)psVar43)->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_31.seg))) = (char)uVar15;
          src_31.ofs = (&((stg_tmp_t *)psVar43)->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_31.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_31,0,0,219,143);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d40e = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d40c = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(160,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          uVar15 = (((stg_tmp_t *)psVar43)->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_32.seg))) = (char)uVar15;
          src_32.ofs = (&((stg_tmp_t *)psVar43)->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_32.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_32,0,0,279,143);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d41e = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d41c = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(160,280,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          uVar15 = (((stg_tmp_t *)psVar43)->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_33.seg))) = (char)uVar15;
          src_33.ofs = (&((stg_tmp_t *)psVar43)->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_33.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_33,0,0,279,143);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d42e = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d42c = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(161,0,0);
          psVar12 = (stg_tmp_t *)psVar43;
          uVar44 = ovr_stshWrite(psVar12->cmap,0x300);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          DAT_2000_d3d2 = (uint16_t)(uVar44 >> 0x10);
          DAT_2000_d3d0 = (uint16_t)uVar44;
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_34.seg))) = (char)uVar15;
          src_34.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_34.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_34,0,144,319,199);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d3ea = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d3e8 = (uint16_t)(pcVar45);
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_35.seg))) = (char)uVar15;
          src_35.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_35.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_35,0,0,47,10);
          far_t_2000_d3e4 = far_from_u32((uint32_t)(ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs))));
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(412,0,0);
          psVar12 = (stg_tmp_t *)psVar43;
          uVar44 = ovr_stshWrite(psVar12->cmap,0x300);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          DAT_2000_d3da = (uint16_t)(uVar44 >> 0x10);
          DAT_2000_d3d8 = (uint16_t)uVar44;
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_36.seg))) = (char)uVar15;
          src_36.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_36.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_36,0,0,319,80);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d3f2 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d3f0 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(414,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          uVar15 = (((stg_tmp_t *)psVar43)->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_37.seg))) = (char)uVar15;
          src_37.ofs = (&((stg_tmp_t *)psVar43)->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_37.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_37,0,0,219,143);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d402 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d400 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(414,220,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          uVar15 = (((stg_tmp_t *)psVar43)->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_38.seg))) = (char)uVar15;
          src_38.ofs = (&((stg_tmp_t *)psVar43)->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_38.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_38,0,0,219,143);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d412 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d410 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(413,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          uVar15 = (((stg_tmp_t *)psVar43)->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_39.seg))) = (char)uVar15;
          src_39.ofs = (&((stg_tmp_t *)psVar43)->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_39.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_39,0,0,279,143);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d422 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d420 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(413,280,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          uVar15 = (((stg_tmp_t *)psVar43)->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_40.seg))) = (char)uVar15;
          src_40.ofs = (&((stg_tmp_t *)psVar43)->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_40.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_40,0,0,279,143);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d432 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d430 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          fVar39.seg = DAT_2000_d432;
          fVar39.ofs = (uint16_t)DAT_2000_d430;
        }
        DAT_2000_d432 = fVar39.seg;
        DAT_2000_d430 = (uint16_t)(fVar39.ofs);
        if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d3de = fVar36.seg;
          DAT_2000_d3dc = fVar36.ofs;
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d3f6 = fVar36.seg;
          DAT_2000_d3f4 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d406 = fVar36.seg;
          DAT_2000_d404 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d416 = fVar36.seg;
          DAT_2000_d414 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d426 = fVar36.seg;
          DAT_2000_d424 = (uint16_t)(fVar36.ofs);
          fVar40 = ovr_stshAllocStub();
        }
        else {
          psVar43 = ovr_grabLbm(422,0,0);
          psVar12 = (stg_tmp_t *)psVar43;
          uVar44 = ovr_stshWrite(psVar12->cmap,0x300);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          DAT_2000_d3de = (uint16_t)(uVar44 >> 0x10);
          DAT_2000_d3dc = (uint16_t)uVar44;
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_41.seg))) = (char)uVar15;
          src_41.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_41.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_41,0,0,319,113);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d3f6 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d3f4 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(421,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          uVar15 = (((stg_tmp_t *)psVar43)->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_42.seg))) = (char)uVar15;
          src_42.ofs = (&((stg_tmp_t *)psVar43)->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_42.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_42,0,0,219,143);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d406 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d404 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(421,220,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          uVar15 = (((stg_tmp_t *)psVar43)->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_43.seg))) = (char)uVar15;
          src_43.ofs = (&((stg_tmp_t *)psVar43)->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_43.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_43,0,0,219,143);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d416 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d414 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(420,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          uVar15 = (((stg_tmp_t *)psVar43)->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_44.seg))) = (char)uVar15;
          src_44.ofs = (&((stg_tmp_t *)psVar43)->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_44.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_44,0,0,279,143);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d426 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d424 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(420,280,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          uVar15 = (((stg_tmp_t *)psVar43)->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_45.seg))) = (char)uVar15;
          src_45.ofs = (&((stg_tmp_t *)psVar43)->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_45.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_45,0,0,279,143);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d436 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d434 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          fVar40.seg = DAT_2000_d436;
          fVar40.ofs = (uint16_t)DAT_2000_d434;
        }
        DAT_2000_d436 = fVar40.seg;
        DAT_2000_d434 = (uint16_t)(fVar40.ofs);
        if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d3e2 = fVar36.seg;
          DAT_2000_d3e0 = fVar36.ofs;
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d3fa = fVar36.seg;
          DAT_2000_d3f8 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d40a = fVar36.seg;
          DAT_2000_d408 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d41a = fVar36.seg;
          DAT_2000_d418 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d42a = fVar36.seg;
          DAT_2000_d428 = (uint16_t)(fVar36.ofs);
          fVar41 = ovr_stshAllocStub();
        }
        else {
          psVar43 = ovr_grabLbm(437,0,0);
          psVar12 = (stg_tmp_t *)psVar43;
          uVar44 = ovr_stshWrite(psVar12->cmap,0x300);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          DAT_2000_d3e2 = (uint16_t)(uVar44 >> 0x10);
          DAT_2000_d3e0 = (uint16_t)uVar44;
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_46.seg))) = (char)uVar15;
          src_46.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_46.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_46,0,0,319,113);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d3fa = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d3f8 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(438,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          uVar15 = (((stg_tmp_t *)psVar43)->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_47.seg))) = (char)uVar15;
          src_47.ofs = (&((stg_tmp_t *)psVar43)->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_47.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_47,0,0,219,143);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d40a = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d408 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(438,220,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          uVar15 = (((stg_tmp_t *)psVar43)->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_48.seg))) = (char)uVar15;
          src_48.ofs = (&((stg_tmp_t *)psVar43)->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_48.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_48,0,0,219,143);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d41a = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d418 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(439,0,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          uVar15 = (((stg_tmp_t *)psVar43)->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_49.seg))) = (char)uVar15;
          src_49.ofs = (&((stg_tmp_t *)psVar43)->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_49.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_49,0,0,279,143);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d42a = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d428 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(439,280,0);
          uVar24 = (undefined2)((ulong)psVar43 >> 0x10);
          uVar15 = (((stg_tmp_t *)psVar43)->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_50.seg))) = (char)uVar15;
          src_50.ofs = (&((stg_tmp_t *)psVar43)->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_50.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_50,0,0,279,143);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d43a = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d438 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          fVar41.seg = DAT_2000_d43a;
          fVar41.ofs = (uint16_t)DAT_2000_d438;
        }
        DAT_2000_d43a = fVar41.seg;
        DAT_2000_d438 = (uint16_t)(fVar41.ofs);
        if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d04a = fVar36.seg;
          DAT_2000_d048 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d026 = fVar36.seg;
          DAT_2000_d024 = fVar36.ofs;
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d04e = fVar36.seg;
          DAT_2000_d04c = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d052 = fVar36.seg;
          DAT_2000_d050 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d02a = fVar36.seg;
          DAT_2000_d028 = fVar36.ofs;
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d056 = fVar36.seg;
          DAT_2000_d054 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d05a = fVar36.seg;
          DAT_2000_d058 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d02e = fVar36.seg;
          DAT_2000_d02c = fVar36.ofs;
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d05e = fVar36.seg;
          DAT_2000_d05c = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d062 = fVar36.seg;
          DAT_2000_d060 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d032 = fVar36.seg;
          DAT_2000_d030 = fVar36.ofs;
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d066 = fVar36.seg;
          DAT_2000_d064 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d06a = fVar36.seg;
          DAT_2000_d068 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d036 = fVar36.seg;
          DAT_2000_d034 = fVar36.ofs;
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d06e = fVar36.seg;
          DAT_2000_d06c = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d072 = fVar36.seg;
          DAT_2000_d070 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d03a = fVar36.seg;
          DAT_2000_d038 = fVar36.ofs;
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d076 = fVar36.seg;
          DAT_2000_d074 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d07a = fVar36.seg;
          DAT_2000_d078 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d03e = fVar36.seg;
          DAT_2000_d03c = fVar36.ofs;
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d07e = fVar36.seg;
          DAT_2000_d07c = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d082 = fVar36.seg;
          DAT_2000_d080 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d042 = fVar36.seg;
          DAT_2000_d040 = fVar36.ofs;
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d086 = fVar36.seg;
          DAT_2000_d084 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d08a = fVar36.seg;
          DAT_2000_d088 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d046 = fVar36.seg;
          DAT_2000_d044 = fVar36.ofs;
          fVar42 = ovr_stshAllocStub();
        }
        else {
LAB_81b9_2fc9:
          DAT_2000_d43a = fVar41.seg;
          DAT_2000_d438 = (uint16_t)(fVar41.ofs);
          psVar43 = ovr_grabLbm(305,0,0);
          ovr_stshUniqueColorsRemap(psVar43);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          psStack_a = (stg_tmp_t *)psVar43;
          uVar15 = (psStack_a->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_51.seg))) = (char)uVar15;
          src_51.ofs = (&psStack_a->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_51.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_51,0,0,319,59);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d04a = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d048 = (uint16_t)(pcVar45);
          uVar44 = ovr_stshWrite(psStack_a->cmap + 0x1e0,0x90);
          DAT_2000_d026 = (uint16_t)(uVar44 >> 0x10);
          DAT_2000_d024 = (uint16_t)uVar44;
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(305,320,0);
          ovr_stshUniqueColorsRemap(psVar43);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          psStack_a = (stg_tmp_t *)psVar43;
          uVar15 = (psStack_a->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_52.seg))) = (char)uVar15;
          src_52.ofs = (&psStack_a->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_52.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_52,0,0,319,59);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d04e = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d04c = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(328,0,0);
          ovr_stshUniqueColorsRemap(psVar43);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          psStack_a = (stg_tmp_t *)psVar43;
          uVar15 = (psStack_a->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_53.seg))) = (char)uVar15;
          src_53.ofs = (&psStack_a->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_53.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_53,0,0,319,59);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d052 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d050 = (uint16_t)(pcVar45);
          uVar44 = ovr_stshWrite(psStack_a->cmap + 0x1e0,0x90);
          DAT_2000_d02a = (uint16_t)(uVar44 >> 0x10);
          DAT_2000_d028 = (uint16_t)uVar44;
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(328,320,0);
          ovr_stshUniqueColorsRemap(psVar43);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          psStack_a = (stg_tmp_t *)psVar43;
          uVar15 = (psStack_a->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_54.seg))) = (char)uVar15;
          src_54.ofs = (&psStack_a->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_54.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_54,0,0,319,59);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d056 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d054 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(331,0,0);
          ovr_stshUniqueColorsRemap(psVar43);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          psStack_a = (stg_tmp_t *)psVar43;
          uVar15 = (psStack_a->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_55.seg))) = (char)uVar15;
          src_55.ofs = (&psStack_a->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_55.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_55,0,0,319,59);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d05a = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d058 = (uint16_t)(pcVar45);
          uVar44 = ovr_stshWrite(psStack_a->cmap + 0x1e0,0x90);
          DAT_2000_d02e = (uint16_t)(uVar44 >> 0x10);
          DAT_2000_d02c = (uint16_t)uVar44;
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(331,320,0);
          ovr_stshUniqueColorsRemap(psVar43);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          psStack_a = (stg_tmp_t *)psVar43;
          uVar15 = (psStack_a->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_56.seg))) = (char)uVar15;
          src_56.ofs = (&psStack_a->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_56.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_56,0,0,319,59);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d05e = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d05c = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(307,0,0);
          ovr_stshUniqueColorsRemap(psVar43);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          psStack_a = (stg_tmp_t *)psVar43;
          uVar15 = (psStack_a->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_57.seg))) = (char)uVar15;
          src_57.ofs = (&psStack_a->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_57.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_57,0,0,319,59);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d062 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d060 = (uint16_t)(pcVar45);
          uVar44 = ovr_stshWrite(psStack_a->cmap + 0x1e0,0x90);
          DAT_2000_d032 = (uint16_t)(uVar44 >> 0x10);
          DAT_2000_d030 = (uint16_t)uVar44;
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(307,320,0);
          ovr_stshUniqueColorsRemap(psVar43);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          psStack_a = (stg_tmp_t *)psVar43;
          uVar15 = (psStack_a->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_58.seg))) = (char)uVar15;
          src_58.ofs = (&psStack_a->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_58.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_58,0,0,319,59);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d066 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d064 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(329,0,0);
          ovr_stshUniqueColorsRemap(psVar43);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          psStack_a = (stg_tmp_t *)psVar43;
          uVar15 = (psStack_a->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_59.seg))) = (char)uVar15;
          src_59.ofs = (&psStack_a->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_59.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_59,0,0,319,59);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d06a = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d068 = (uint16_t)(pcVar45);
          uVar44 = ovr_stshWrite(psStack_a->cmap + 0x1e0,0x90);
          DAT_2000_d036 = (uint16_t)(uVar44 >> 0x10);
          DAT_2000_d034 = (uint16_t)uVar44;
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(329,320,0);
          ovr_stshUniqueColorsRemap(psVar43);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          psStack_a = (stg_tmp_t *)psVar43;
          uVar15 = (psStack_a->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_60.seg))) = (char)uVar15;
          src_60.ofs = (&psStack_a->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_60.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_60,0,0,319,59);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d06e = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d06c = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(332,0,0);
          ovr_stshUniqueColorsRemap(psVar43);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          psStack_a = (stg_tmp_t *)psVar43;
          uVar15 = (psStack_a->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_61.seg))) = (char)uVar15;
          src_61.ofs = (&psStack_a->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_61.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_61,0,0,319,59);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d072 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d070 = (uint16_t)(pcVar45);
          uVar44 = ovr_stshWrite(psStack_a->cmap + 0x1e0,0x90);
          DAT_2000_d03a = (uint16_t)(uVar44 >> 0x10);
          DAT_2000_d038 = (uint16_t)uVar44;
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(332,320,0);
          ovr_stshUniqueColorsRemap(psVar43);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          psStack_a = (stg_tmp_t *)psVar43;
          uVar15 = (psStack_a->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_62.seg))) = (char)uVar15;
          src_62.ofs = (&psStack_a->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_62.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_62,0,0,319,59);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d076 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d074 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(306,0,0);
          ovr_stshUniqueColorsRemap(psVar43);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          psStack_a = (stg_tmp_t *)psVar43;
          uVar15 = (psStack_a->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_63.seg))) = (char)uVar15;
          src_63.ofs = (&psStack_a->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_63.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_63,0,0,319,59);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d07a = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d078 = (uint16_t)(pcVar45);
          uVar44 = ovr_stshWrite(psStack_a->cmap + 0x1e0,0x90);
          DAT_2000_d03e = (uint16_t)(uVar44 >> 0x10);
          DAT_2000_d03c = (uint16_t)uVar44;
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(306,320,0);
          ovr_stshUniqueColorsRemap(psVar43);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          psStack_a = (stg_tmp_t *)psVar43;
          uVar15 = (psStack_a->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_64.seg))) = (char)uVar15;
          src_64.ofs = (&psStack_a->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_64.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_64,0,0,319,59);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d07e = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d07c = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(330,0,0);
          ovr_stshUniqueColorsRemap(psVar43);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          psStack_a = (stg_tmp_t *)psVar43;
          uVar15 = (psStack_a->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_65.seg))) = (char)uVar15;
          src_65.ofs = (&psStack_a->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_65.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_65,0,0,319,59);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d082 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d080 = (uint16_t)(pcVar45);
          uVar44 = ovr_stshWrite(psStack_a->cmap + 0x1e0,0x90);
          DAT_2000_d042 = (uint16_t)(uVar44 >> 0x10);
          DAT_2000_d040 = (uint16_t)uVar44;
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(330,320,0);
          ovr_stshUniqueColorsRemap(psVar43);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          psStack_a = (stg_tmp_t *)psVar43;
          uVar15 = (psStack_a->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_66.seg))) = (char)uVar15;
          src_66.ofs = (&psStack_a->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_66.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_66,0,0,319,59);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d086 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d084 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(333,0,0);
          ovr_stshUniqueColorsRemap(psVar43);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          psStack_a = (stg_tmp_t *)psVar43;
          uVar15 = (psStack_a->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_67.seg))) = (char)uVar15;
          src_67.ofs = (&psStack_a->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_67.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_67,0,0,319,59);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d08a = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d088 = (uint16_t)(pcVar45);
          uVar44 = ovr_stshWrite(psStack_a->cmap + 0x1e0,0x90);
          DAT_2000_d046 = (uint16_t)(uVar44 >> 0x10);
          DAT_2000_d044 = (uint16_t)uVar44;
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(333,320,0);
          ovr_stshUniqueColorsRemap(psVar43);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          psStack_a = (stg_tmp_t *)psVar43;
          uVar15 = (psStack_a->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_68.seg))) = (char)uVar15;
          src_68.ofs = (&psStack_a->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_68.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_68,0,0,319,59);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d08e = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d08c = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          fVar42.seg = DAT_2000_d08e;
          fVar42.ofs = (uint16_t)DAT_2000_d08c;
        }
        DAT_2000_d08e = fVar42.seg;
        DAT_2000_d08c = (uint16_t)(fVar42.ofs);
        ovr_stshInitAudioAssets();
        ovr_stshLoadAudioDrivers((*(uint8_t *)((uint8_t *)&(param_1))));
        ovr_stshInitSprites((*(uint8_t *)((uint8_t *)&(param_1))));
        stshInitTxtFiles();
        if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
          fVar36 = ovr_stshAllocStub();
        }
        else {
          fVar36 = ovr_stshStoreFile_2((char *)StshNames[0x19f],0);
        }
        DAT_2000_d486 = fVar36.seg;
        DAT_2000_d484 = fVar36.ofs;
        if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
          fVar36 = ovr_stshAllocStub();
        }
        else {
          fVar36 = ovr_stshStoreFile_2((char *)"bolt12.fli",0);
        }
        DAT_2000_d482 = fVar36.seg;
        DAT_2000_d480 = fVar36.ofs;
        if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d45a = fVar36.seg;
          DAT_2000_d458 = fVar36.ofs;
          fVar46 = ovr_stshAllocStub();
        }
        else {
          psVar43 = ovr_grabLbm(417,0,0);
          psVar12 = (stg_tmp_t *)psVar43;
          uVar44 = ovr_stshWrite(psVar12->cmap,0x300);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          DAT_2000_d45a = (uint16_t)(uVar44 >> 0x10);
          DAT_2000_d458 = (uint16_t)uVar44;
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_69.seg))) = (char)uVar15;
          src_69.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_69.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_69,0,0,319,199);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d476 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d474 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          fVar46.seg = DAT_2000_d476;
          fVar46.ofs = (uint16_t)DAT_2000_d474;
        }
        DAT_2000_d476 = fVar46.seg;
        DAT_2000_d474 = (uint16_t)(fVar46.ofs);
        if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d43e = fVar36.seg;
          DAT_2000_d43c = fVar36.ofs;
          fVar47 = ovr_stshAllocStub();
        }
        else {
          psVar43 = ovr_grabLbm(542,0,0);
          psVar12 = (stg_tmp_t *)psVar43;
          uVar44 = ovr_stshWrite(psVar12->cmap,0x300);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          DAT_2000_d43e = (uint16_t)(uVar44 >> 0x10);
          DAT_2000_d43c = (uint16_t)uVar44;
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_70.seg))) = (char)uVar15;
          src_70.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_70.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_70,0,0,319,144);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d45e = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d45c = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          fVar47.seg = DAT_2000_d45e;
          fVar47.ofs = (uint16_t)DAT_2000_d45c;
        }
        DAT_2000_d45e = fVar47.seg;
        DAT_2000_d45c = (uint16_t)(fVar47.ofs);
        if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d442 = fVar36.seg;
          DAT_2000_d440 = fVar36.ofs;
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d462 = fVar36.seg;
          DAT_2000_d460 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d446 = fVar36.seg;
          DAT_2000_d444 = fVar36.ofs;
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d466 = fVar36.seg;
          DAT_2000_d464 = (uint16_t)(fVar36.ofs);
          fVar36 = ovr_stshAllocStub();
          DAT_2000_d44a = fVar36.seg;
          DAT_2000_d448 = fVar36.ofs;
          fVar48 = ovr_stshAllocStub();
        }
        else {
          psVar43 = ovr_grabLbm(539,0,0);
          psVar12 = (stg_tmp_t *)psVar43;
          uVar44 = ovr_stshWrite(psVar12->cmap,0x300);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          DAT_2000_d442 = (uint16_t)(uVar44 >> 0x10);
          DAT_2000_d440 = (uint16_t)uVar44;
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_71.seg))) = (char)uVar15;
          src_71.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_71.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_71,0,0,319,199);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d462 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d460 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(540,0,0);
          psVar12 = (stg_tmp_t *)psVar43;
          uVar44 = ovr_stshWrite(psVar12->cmap,0x300);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          DAT_2000_d446 = (uint16_t)(uVar44 >> 0x10);
          DAT_2000_d444 = (uint16_t)uVar44;
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_72.seg))) = (char)uVar15;
          src_72.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_72.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_72,0,0,319,199);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d466 = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d464 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          psVar43 = ovr_grabLbm(541,0,0);
          psVar12 = (stg_tmp_t *)psVar43;
          uVar44 = ovr_stshWrite(psVar12->cmap,0x300);
          pcStack_8 = (char *)((ulong)psVar43 >> 0x10);
          DAT_2000_d44a = (uint16_t)(uVar44 >> 0x10);
          DAT_2000_d448 = (uint16_t)uVar44;
          uVar15 = (psVar12->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_73.seg))) = (char)uVar15;
          src_73.ofs = (&psVar12->aptr)->ofs;
          (*(uint8_t *)((uint8_t *)&(src_73.seg) + 1)) = (char)(uVar15 >> 8);
          fVar36 = ovr_stshRleCut(src_73,0,0,319,199);
          pcVar45 = ovr_stshStoreFile((uint8_t *)MK_FP(fVar36.seg, fVar36.ofs));
          DAT_2000_d46a = (uint16_t)((ulong)pcVar45 >> 0x10);
          DAT_2000_d468 = (uint16_t)(pcVar45);
          ovr_stgFreeTmp(psVar43);
          fVar48.seg = DAT_2000_d46a;
          fVar48.ofs = (uint16_t)DAT_2000_d468;
        }
        DAT_2000_d46a = fVar48.seg;
        DAT_2000_d468 = (uint16_t)(fVar48.ofs);
        if ((*(uint8_t *)((uint8_t *)&(param_1))) == false) {
          fVar36 = ovr_stshAllocStub();
          uVar14 = fVar36.ofs;
        }
        else {
          fVar36 = ovr_stshStoreFile_2((char *)"save.999",0);
          uVar14 = fVar36.ofs;
        }
        DAT_2000_d1b2 = fVar36.seg;
        DAT_2000_d1b0 = fVar36.ofs;
        return uVar14;
      case (cte_t *)0x4:
        *pcVar23 = *pcVar23 + (0x44 < bVar7);
        fVar41.seg = DAT_2000_d43a;
        fVar41.ofs = (uint16_t)DAT_2000_d438;
        goto LAB_81b9_2fc9;
      case (cte_t *)0x5:
        goto code_r0x00083f6a;
      case (cte_t *)0x6:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case (cte_t *)0x7:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    } while( true );
  case 1:
    if (((uVar14 != 0) || (uVar15 = ovr_randBelow(4), (uVar15 & 0xff) != 0)) &&
       ((-1 < *(char *)((int)piVar22 + 5) && (*(char *)((int)piVar22 + 0x25) == '\x01')))) {
      uVar15 = ovr_randBelow(8);
      if ((uVar15 & 0xff) != 0) {
        return uVar15 & 0xff;
      }
    }
    *(undefined1 *)((int)piVar22 + 0x25) = 1;
    uVar15 = ovr_randBelow(2);
    *(undefined1 *)((int)piVar22 + 5) = (char)uVar15;
    uVar15 = ovr_randBelow(2);
    bVar7 = (char)uVar15 * '\x02' - 1;
    uVar14 = (uint)bVar7;
    *(byte *)(piVar22 + 2) = bVar7;
    if (*param_1 < 0x2a) {
      *(undefined1 *)(piVar22 + 2) = 0xff;
      return uVar14;
    }
    if (0xb4 < *param_1) {
      *(undefined1 *)(piVar22 + 2) = 1;
      return uVar14;
    }
    *(undefined1 *)((int)piVar22 + 5) = 1;
    return uVar14;
  case 2:
    break;
  case 3:
    break;
  case 4:
    uVar53 = 9;
    uVar54 = 0;
    if (*(char *)((int)piVar22 + 0xf) != '\0') {
      cVar10 = -1;
      psStack_a = (stg_tmp_t *)
                  (((-*(int *)(pcVar49 + 0x17) -
                    (int)*(char *)((int)*(undefined4 *)((int)piVar22 + 0x1d) + 0x1e)) + *param_1 >>
                   1) + 1);
      iVar13 = (int)psStack_a -
               ((int)*(char *)((int)*(undefined4 *)((int)piVar22 + 0x1d) + 0x1f) -
                (int)*(char *)((int)*(undefined4 *)((int)piVar22 + 0x1d) + 0x1e) >> 1);
      goto LAB_8699_0121;
    }
    break;
  case 5:
    goto code_r0x00088b64;
  }
  cVar10 = '\x01';
  psStack_a = (stg_tmp_t *)
              (((int)*(char *)((int)*(undefined4 *)((int)piVar22 + 0x1d) + 0x1e) +
                *(int *)(pcVar49 + 0x17) + *param_1 >> 1) + -1);
  iVar13 = (int)psStack_a +
           ((int)*(char *)((int)*(undefined4 *)((int)piVar22 + 0x1d) + 0x1f) -
            (int)*(char *)((int)*(undefined4 *)((int)piVar22 + 0x1d) + 0x1e) >> 1);
LAB_8699_0121:
  if ((int)psStack_a < 0) {
    psStack_a = (stg_tmp_t *)0x0;
  }
  if (iVar13 < 0) {
    iVar13 = 0;
  }
  if (0x68 < (int)psStack_a) {
    psStack_a = (stg_tmp_t *)0x68;
  }
  if (0x68 < iVar13) {
    iVar13 = 0x68;
  }
  do {
    if (psStack_a == (stg_tmp_t *)iVar13) {
      *param_2 = 0;
                    /* WARNING: Read-only address (ram,0x0002db84) is written */
      return 0;
    }
    for (pcStack_8 = (char *)0x0;
        (int)pcStack_8 <= (int)*(char *)((int)*(undefined4 *)((int)piVar22 + 0x1d) + 0x20) >> 1;
        pcStack_8 = (char *)((int)pcStack_8 + 1)) {
      cVar8 = -1;
      while (((cVar8 < '\x02' && (pcStack_8 != (char *)0x0)) ||
             ((cVar8 == -1 && (pcStack_8 == (char *)0x0))))) {
        iVar16 = CONCAT11(uVar54,uVar53) + (int)pcStack_8 * (int)cVar8;
        if ((-1 < iVar16) && (iVar16 < 10)) {
          if ((*(char *)(iVar16 * 0x69 + (int)psStack_a + 0x8fa) != '\0') &&
             (((*(byte *)(iVar16 * 0x69 + (int)psStack_a + 0x8fa) <= AgntCount &&
               (*(char *)((uint)*(byte *)(iVar16 * 0x69 + (int)psStack_a + 0x8fa) * 0x34 + -5) !=
                (char)(in_stack_0000fffc >> 8))) &&
              (*(char *)((uint)*(byte *)(iVar16 * 0x69 + (int)psStack_a + 0x8fa) * 0x34 + -0x10) ==
               '\0')))) {
            *param_2 = *(byte *)(iVar16 * 0x69 + (int)psStack_a + 0x8fa);
            cVar56 = ovr_agnt_3b1d_00b7();
            if (cVar56 != '\0') {
              return (uint)*param_2;
            }
          }
          if (((*(char *)(iVar16 * 0x69 + (int)psStack_a + 0x4e0) != '\0') &&
              (*(byte *)(iVar16 * 0x69 + (int)psStack_a + 0x4e0) <= AgntCount)) &&
             ((*(char *)((uint)*(byte *)(iVar16 * 0x69 + (int)psStack_a + 0x4e0) * 0x34 + -5) !=
               (char)(in_stack_0000fffc >> 8) &&
              (*(char *)((uint)*(byte *)(iVar16 * 0x69 + (int)psStack_a + 0x4e0) * 0x34 + -0x10) ==
               '\0')))) {
            *param_2 = *(byte *)(iVar16 * 0x69 + (int)psStack_a + 0x4e0);
            return (uint)*param_2;
          }
        }
        cVar8 = cVar8 + '\x02';
      }
    }
    psStack_a = (stg_tmp_t *)((int)psStack_a + (int)cVar10);
  } while( true );
LAB_8699_3bde:
  if ((int)(uint)AgntCount <= (int)uStackY_22) goto LAB_8699_3bf1;
  uVar24 = *(undefined2 *)((int)uStackY_22 * 0x34 + 0x15);
  iVar13 = *(int *)((int)uStackY_22 * 0x34 + 0x13);
  cVar10 = *(char *)((int)uStackY_22 * 0x34 + 0x12);
  uStackY_1c = (char *)CONCAT11(cVar10,(char)uStackY_1c);
  GGameState = 0x37;
  if (DebugVerbose != false) {
    pcVar26 = (char *)&AgntAnms[0x38].field_0x18;
    printf("%d \r",0x37);
  }
  iVar16 = ovr_stash_474a_10ac();
  GGameState = 0x38;
  pcVar49 = pcVar26;
  if (DebugVerbose != false) {
    pcVar49 = (char *)"glassworks" + 9;
    printf("%d \r",0x38);
  }
  pcVar17 = (char *)(*(int *)((int)uStackY_22 * 0x34) + 0xc);
  if (*(char *)((int)uStackY_22 * 0x34 + 0x11) == '\0') {
    uVar9 = 0x3e;
    uVar51 = 0x95;
    iVar18 = ovr_agnt_3b1d_005e();
    iStackY_28 = *(int *)(iVar18 * 2 + 0x34c) + *(int *)((int)uStackY_22 * 0x34 + 2) + 3;
  }
  else {
    uVar9 = 0xd9;
    uVar51 = 0x94;
    iVar18 = ovr_agnt_3b1d_005e();
    uVar5 = *(undefined4 *)((int)uStackY_22 * 0x34 + 0x1d);
    iStackY_28 = *(int *)(iVar18 * 2 + 0x34c) + *(int *)((int)uStackY_22 * 0x34 + 2) +
                 (int)*(char *)((int)uVar5 + 0x52) + -0x16;
  }
  pcVar23 = (char *)"mason\'s hall" + 6;
  *(uint16_t *)((int)uStackY_22 * 0x34 + 0x26) = (uint16_t)pcVar17;
  *(int16_t *)((int)uStackY_22 * 0x34 + 0x28) = iStackY_28;
  if ((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 0x800) == 0) {
    if (*(char *)((int)uStackY_22 * 0x34 + 0x24) == '\0') {
      GGameState = 0x32;
      pcVar49 = acStackY_32;
      uStackY_1c = (char *)"mason\'s hall" + 6;
      pcVar23 = (char *)"bath house" + 10;
      gfx.seg = (uint16_t)pcVar17;
      gfx.ofs = iVar16 + 6;
      uVar9 = uVar57;
      uVar51 = uVar52;
      ovr_blitGfxRect(gfx,(int16_t)pcVar17,iStackY_28,
                      (brect_t *)CONCAT13(uVar52,CONCAT12(uVar57,pcVar49)),0x10,
                      *(bool *)((int)uStackY_22 * 0x34 + 0xf));
      GGameState = 0x33;
      if ((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 100) != 0) {
        bVar4 = *(bool *)((int)uStackY_22 * 0x34 + 0xf);
        pcVar49 = acStackY_32;
        bVar7 = *(byte *)((int)uStackY_22 * 0x34 + 0x23);
        pcVar1 = (char *)((int)uStackY_22 * 0x34 + 0x23);
        *pcVar1 = *pcVar1 + -1;
        uVar14 = bVar7 & 3;
        uStackY_1c = (char *)"bath house" + 10;
        pcVar23 = (char *)"bath house" + 10;
        gfx_00.seg = ((undefined2 *)&DAT_2000_cc67)[uVar14 * 2];
        gfx_00.ofs = ((undefined2 *)&DAT_2000_cc65)[uVar14 * 2];
        uVar9 = uVar57;
        uVar51 = uVar52;
        ovr_blitGfxRect(gfx_00,(int16_t)pcVar17,iStackY_28 - stack0xffdb,
                        (brect_t *)CONCAT13(uVar52,CONCAT12(uVar57,pcVar49)),0x10,bVar4);
      }
    }
    else if (*(char *)((int)uStackY_22 * 0x34 + 0x24) == '\x01') {
      uVar5 = *(undefined4 *)((int)uStackY_22 * 0x34 + 0x1d);
      if ((*(uint *)((int)uVar5 + 0x40) & 2) == 0) {
        gfx_02.seg = (uint16_t)pcVar17;
        gfx_02.ofs = iVar16 + 6;
        ovr_blitGfxRect(gfx_02,(int16_t)pcVar17,iStackY_28,
                        (brect_t *)CONCAT13(uVar52,CONCAT12(uVar57,acStackY_32)),0x10,
                        *(bool *)((int)uStackY_22 * 0x34 + 0xf));
        pcVar49 = acStackY_32;
        uVar14 = *(byte *)((int)uStackY_22 * 0x34 + 0x23) & 3;
        uStackY_1c = (char *)"bath house" + 10;
        pcVar23 = (char *)"bath house" + 10;
        gfx_03.seg = ((undefined2 *)&DAT_2000_cc67)[uVar14 * 2];
        gfx_03.ofs = ((undefined2 *)&DAT_2000_cc65)[uVar14 * 2];
        uVar9 = uVar57;
        uVar51 = uVar52;
        ovr_blitGfxRect(gfx_03,(int16_t)pcVar17,iStackY_28 - stack0xffdb,
                        (brect_t *)CONCAT13(uVar52,CONCAT12(uVar57,pcVar49)),0x10,
                        *(bool *)((int)uStackY_22 * 0x34 + 0xf));
        if (*(char *)((int)uStackY_22 * 0x34 + 0x23) == '\0') {
          *(undefined1 *)((int)uStackY_22 * 0x34 + 0x24) = 0;
        }
        else {
          pcVar1 = (char *)((int)uStackY_22 * 0x34 + 0x23);
          *pcVar1 = *pcVar1 + -1;
        }
      }
      else {
        pcVar49 = acStackY_32;
        uStackY_1c = (char *)"mason\'s hall" + 6;
        pcVar23 = (char *)"bath house" + 10;
        gfx_01.seg = (uint16_t)pcVar17;
        gfx_01.ofs = iVar16 + 6;
        uVar9 = uVar57;
        uVar51 = uVar52;
        ovr_blitGfxRect(gfx_01,(int16_t)pcVar17,iStackY_28,
                        (brect_t *)CONCAT13(uVar52,CONCAT12(uVar57,pcVar49)),0x10,
                        *(bool *)((int)uStackY_22 * 0x34 + 0xf));
        if ((int)(uint)(byte)pcVar49[0x1b] <= *(int *)((int)uStackY_22 * 0x34 + 6) + 1) {
          *(undefined1 *)((int)uStackY_22 * 0x34 + 0x24) = 0;
        }
      }
    }
    else if (*(char *)((int)uStackY_22 * 0x34 + 0x24) == '\x02') {
      if (cVar10 == '\x12') {
        pcVar49 = acStackY_32;
        uStackY_1c = (char *)"mason\'s hall" + 6;
        pcVar23 = (char *)"bath house" + 10;
        gfx_04.seg = (uint16_t)pcVar17;
        gfx_04.ofs = iVar16 + 6;
        uVar9 = uVar57;
        uVar51 = uVar52;
        ovr_blitGfxRect(gfx_04,(int16_t)pcVar17,iStackY_28,
                        (brect_t *)CONCAT13(uVar52,CONCAT12(uVar57,pcVar49)),0x10,
                        *(bool *)((int)uStackY_22 * 0x34 + 0xf));
        if ((int)(uint)(byte)pcVar49[0x1b] <= *(int *)((int)uStackY_22 * 0x34 + 6) + 1) {
          *(undefined1 *)((int)uStackY_22 * 0x34 + 0x25) = 2;
          pcVar23 = (char *)"builder\'s hall" + 8;
          uVar9 = 0x9a;
          uVar51 = 0x99;
          ovr_OVC41_6a8f_0807();
        }
      }
      else {
        ovr_randBelow(0x100);
        uVar9 = 1;
        uVar51 = 0;
        pcVar49 = (char *)CONCAT11((char)((uint)((int)uStackY_22 * 0x34) >> 8),
                                   *(undefined1 *)((int)uStackY_22 * 0x34 + 0xf));
        uStackY_20 = acStackY_2c;
        uStackY_22 = (cte_t *)((char *)"glassworks" + 9);
        pcVar23 = (char *)"bath house" + 10;
        _auStackY_26 = CONCAT22(0x98d2,auStackY_26);
        ovr_gfxRlePrepare();
        if (*(char *)((int)uStackY_22 * 0x34 + 0x23) == '\0') {
          *(undefined1 *)((int)uStackY_22 * 0x34 + 0x25) = 2;
          pcVar23 = (char *)"builder\'s hall" + 8;
          uVar9 = 0x20;
          uVar51 = 0x99;
          ovr_OVC41_6a8f_0807();
          uStackY_1c = pcVar17;
        }
        else {
          pcVar1 = (char *)((int)uStackY_22 * 0x34 + 0x23);
          *pcVar1 = *pcVar1 + -1;
          uStackY_1c = pcVar17;
        }
      }
    }
  }
  else {
    uVar9 = 0xff;
    uVar51 = 0;
    pcVar49 = (char *)CONCAT11((char)((uint)((int)uStackY_22 * 0x34) >> 8),
                               *(undefined1 *)((int)uStackY_22 * 0x34 + 0xf));
    uStackY_20 = acStackY_2c;
    uStackY_22 = (cte_t *)((char *)"mason\'s hall" + 6);
    pcVar23 = (char *)"bath house" + 10;
    _auStackY_26 = CONCAT22(0x95e4,auStackY_26);
    ovr_gfxRlePrepare();
    uStackY_1c = pcVar17;
  }
  pcVar26 = pcVar23;
  if (*(char *)((int)uStackY_22 * 0x34 + 0x30) != '\0') {
    uVar51 = (undefined1)((uint)acStackY_32 >> 8);
    pcVar26 = (char *)"mason\'s hall" + 6;
    uVar9 = (undefined1)uStackY_22;
    ovr_agnt_3b1d_1035();
    pcVar49 = pcVar23;
  }
  if (((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 8) == 0) ||
     ((uint)(byte)pcVar49[0x19] != *(uint *)((int)uStackY_22 * 0x34 + 6))) {
    if (((uint)(byte)pcVar49[0x19] == *(uint *)((int)uStackY_22 * 0x34 + 6)) &&
       ((*(char *)((int)uStackY_22 * 0x34 + 0x24) == '\0' &&
        (*(char *)((int)uStackY_22 * 0x34 + 0xe) == -1)))) {
      if (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\0') {
        cVar10 = OVC49_8699_036e();
        if (cVar10 == '\0') {
          if ((*(char *)((int)uStackY_22 * 0x34 + 0x12) == '\x03') ||
             (*(char *)((int)uStackY_22 * 0x34 + 0x12) == '\x0f')) {
            uVar15 = ovr_audio_3a5b_0afd();
            ovr_play_sfxU(0x33,0,uVar15);
          }
          DAT_2410_07e2 = 9;
          pcVar26 = (char *)"mason\'s hall" + 6;
          ovr_agnt_3b1d_0a9f();
        }
        else {
          *(char *)((int)uStackY_22 * 0x34 + 0xc) = (char)uStackY_1c + -1;
        }
      }
      else if (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x01') {
        cVar10 = OVC49_8699_0000();
        if (cVar10 != '\0') {
          pcVar26 = (char *)"elf outpost" + 8;
          cVar10 = ovr_OVC27_5ded_0404();
          if (cVar10 != '\0') {
            *(char *)((int)uStackY_22 * 0x34 + 0xc) = (char)uStackY_1c + -1;
            goto LAB_8699_3310;
          }
        }
        DAT_2410_07e2 = 10;
        pcVar26 = (char *)"mason\'s hall" + 6;
        ovr_agnt_3b1d_0a9f();
      }
      else if (((*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x02') ||
               (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x04')) ||
              (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x05')) {
        pcVar26 = (char *)"mason\'s hall" + 6;
        cVar10 = ovr_agnt_3b1d_00ce();
        if (cVar10 == '\0') {
          DAT_2410_07e2 = 0xb;
          pcVar26 = (char *)"mason\'s hall" + 6;
          ovr_agnt_3b1d_0a9f();
        }
        else {
          *(char *)((int)uStackY_22 * 0x34 + 0xc) = (char)uStackY_1c + -1;
        }
      }
LAB_8699_3310:
      bVar7 = *(char *)((int)uStackY_22 * 0x34 + 0xc) + 1;
      uStackY_1c = (char *)(uint)bVar7;
      uVar9 = SUB21(pcVar26,0);
      uVar51 = (undefined1)((uint)pcVar26 >> 8);
      if (((bVar7 == 0) || (*(char *)((uint)bVar7 * 0x34 + -0x10) != '\0')) ||
         ((*(char *)((int)uStackY_22 * 0x34 + 0xd) != '\x06' &&
          ((0x14 < *(int *)((int)uStackY_22 * 0x34 + 2) ||
           (0x14 < *(int *)((uint)bVar7 * 0x34 + -0x32))))))) {
        DAT_2410_07e2 = 0xc;
        pcVar26 = (char *)"mason\'s hall" + 6;
        ovr_agnt_3b1d_0a9f();
      }
      else if (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x01') {
        pcVar26 = (char *)"elf outpost" + 8;
        cVar10 = ovr_OVC27_5ded_0a05();
        if (cVar10 == '\0') {
          DAT_2410_07e2 = 0xf;
          pcVar26 = (char *)"mason\'s hall" + 6;
          ovr_agnt_3b1d_0a9f();
        }
      }
      else if (((*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x02') ||
               (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x04')) &&
              (*(char *)((int)uStackY_22 * 0x34 + 0xe) == -1)) {
        iVar16 = -0x61fb;
        uVar15 = ovr_audio_3a5b_0afd();
        uVar53 = (undefined1)(uVar15 >> 8);
        bVar7 = *(byte *)(iVar16 + 0x1d);
        pcVar49 = (char *)"stonemasonry" + 0xc;
        pcVar26 = (char *)"stonemasonry" + 0xc;
        ovr_play_sfxU(bVar7,0,uVar15);
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0xe) = 0;
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0x2e) = 0;
        *(char *)((int)uStackY_22 * 0x34 + 10) = pcVar49[0x15] + (char)iStackY_28;
        if (*(char *)((int)uStackY_22 * 0x34 + 0xf) == '\0') {
          *(undefined2 *)((int)uStackY_22 * 0x34 + 8) = pcVar17 + *(int *)(pcVar49 + 0x13);
        }
        else {
          *(int *)((int)uStackY_22 * 0x34 + 8) = (int)pcVar17 - *(int *)(pcVar49 + 0x13);
        }
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0xb) =
             *(undefined1 *)((int)uStackY_22 * 0x34 + 0xf);
      }
      else if ((*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\0') &&
              (uVar5 = *(undefined4 *)((int)uStackY_22 * 0x34 + 0x1d),
              (*(uint *)((int)uVar5 + 0x3c) & 8) == 0)) {
        iVar16 = -0x60d4;
        uVar15 = ovr_audio_3a5b_0afd();
        ovr_play_sfxU(*(byte *)(iVar16 + 0x1d),0,uVar15);
        pcVar26 = (char *)"builder\'s hall" + 8;
        ovr_OVC41_6a8f_297d();
      }
      else if (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x03') {
        cVar10 = ovr_agnt_3b1d_0d4d();
        if ((cVar10 != '\0') && ((*(uint *)((uint)bVar7 * 0x34 + -9) & 0x800) == 0)) {
          uVar5 = *(undefined4 *)((uint)bVar7 * 0x34 + -0x1d);
          if (((*(uint *)((int)uVar5 + 0x14) & 2) == 0) ||
             ((uVar15 = ovr_randBelow(2), (uVar15 & 0xff) != 0 ||
              ((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 0x800) == 0)))) {
            ovr_OVC41_6a8f_0229();
            puVar3 = (uint *)((uint)bVar7 * 0x34 + -9);
            *puVar3 = *puVar3 | 0x800;
            uVar15 = ovr_audio_3a5b_0afd();
            ovr_play_sfxU(0x1b,0,uVar15);
          }
          else {
            uVar15 = ovr_audio_3a5b_0afd();
            ovr_play_sfxU(0x1b,0,uVar15);
            ovr_OVC41_6a8f_0229();
            puVar3 = (uint *)((int)uStackY_22 * 0x34 + 0x2b);
            *puVar3 = *puVar3 | 0x800;
          }
        }
        DAT_2410_07e2 = 0xd;
        pcVar26 = (char *)"mason\'s hall" + 6;
        ovr_agnt_3b1d_0a9f();
      }
      else if (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x05') {
        iVar16 = -0x5edf;
        uVar15 = ovr_audio_3a5b_0afd();
        pcVar26 = (char *)"stonemasonry" + 0xc;
        ovr_play_sfxU(*(byte *)(iVar16 + 0x1d),0,uVar15);
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0xe) = 0xf5;
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0x2e) = 1;
      }
      else if (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x06') {
        iVar16 = -0x5e71;
        uVar15 = ovr_audio_3a5b_0afd();
        ovr_play_sfxU(*(byte *)(iVar16 + 0x1d),0,uVar15);
        pcVar26 = (char *)"builder\'s hall" + 8;
        ovr_OVC41_6a8f_297d();
      }
      else {
        DAT_2410_07e2 = 0xe;
        pcVar26 = (char *)"mason\'s hall" + 6;
        ovr_agnt_3b1d_0a9f();
      }
    }
  }
  else {
    pcVar26 = (char *)"builder\'s hall" + 8;
    ovr_OVC41_6a8f_297d();
  }
  GGameState = 0x39;
  if (DebugVerbose != false) {
    pcVar26 = (char *)&AgntAnms[0x38].field_0x18;
    printf("%d \r",0x39);
  }
  piVar2 = (int *)((int)uStackY_22 * 0x34 + 6);
  *piVar2 = *piVar2 + 1;
  if (*(char *)((int)uStackY_22 * 0x34 + 0xe) != -1) {
    if (*(char *)((int)uStackY_22 * 0x34 + 0xc) == -1) {
      pcVar26 = (char *)"mason\'s hall" + 6;
      ovr_agnt_3b1d_0a53();
      DAT_2410_07e2 = 7;
    }
    else if ((*(char *)((int)uStackY_22 * 0x34 + 0x2e) == '\0') ||
            (*(char *)((uint)*(byte *)((int)uStackY_22 * 0x34 + 0x2e) * 0x21 + -0x16) != '\0')) {
      uVar53 = (undefined1)uVar24;
      uVar54 = (undefined1)((uint)uVar24 >> 8);
      uVar9 = (undefined1)iVar13;
      uVar51 = (undefined1)((uint)iVar13 >> 8);
      if (*(char *)((int)uStackY_22 * 0x34 + 0x2e) == '\0') {
        uVar14 = 6;
      }
      else {
        uVar14 = (uint)*(byte *)((uint)*(byte *)((int)uStackY_22 * 0x34 + 0x2e) * 0x21 + -0x16);
      }
      uVar24 = (undefined2)(CONCAT13(uVar54,CONCAT12(uVar53,iVar13)) >> 0x10);
      piVar22 = (int *)(iVar13 + uVar14 * 4);
      if (*piVar22 == 0 && piVar22[1] == 0) {
        uVar53 = (undefined1)SprProjectiles.seg;
        uVar54 = (undefined1)(SprProjectiles.seg >> 8);
        uVar9 = (undefined1)SprProjectiles.ofs;
        uVar51 = (undefined1)(SprProjectiles.ofs >> 8);
      }
      uVar24 = (undefined2)(CONCAT13(uVar54,CONCAT12(uVar53,CONCAT11(uVar51,uVar9))) >> 0x10);
      piVar22 = (int *)(CONCAT11(uVar51,uVar9) + uVar14 * 4);
      if (*piVar22 == 0 && piVar22[1] == 0) {
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0xf);
      }
      iVar13 = ovr_stash_474a_10ac();
      GGameState = 0x30;
      pcVar49 = acStackY_32;
      uVar15 = *(uint16_t *)((int)uStackY_22 * 0x34 + 8);
      uVar19 = iVar13 + 6;
      uStackY_1c = (char *)"glassworks" + 9;
      pcVar26 = (char *)"bath house" + 10;
      gfx_05.seg = uVar15;
      gfx_05.ofs = uVar19;
      uVar50 = uVar15;
      uVar9 = uVar57;
      uVar51 = uVar52;
      ovr_blitGfxRect(gfx_05,uVar15,(uint)*(byte *)((int)uStackY_22 * 0x34 + 10),
                      (brect_t *)CONCAT13(uVar52,CONCAT12(uVar57,pcVar49)),0x10,
                      *(bool *)((int)uStackY_22 * 0x34 + 0xb));
      iVar13 = CONCAT11(uVar51,uVar9);
      GGameState = 0x31;
      if ((pcVar49[0x1c] & 2U) == 0) {
        if (*(char *)((int)uStackY_22 * 0x34 + 0xb) == '\0') {
          piVar2 = (int *)((int)uStackY_22 * 0x34 + 8);
          *piVar2 = *piVar2 + (int)*(char *)(uVar15 + 5);
        }
        else {
          piVar2 = (int *)((int)uStackY_22 * 0x34 + 8);
          *piVar2 = *piVar2 - (int)*(char *)(uVar15 + 5);
        }
        iVar16 = uVar19 + 1;
        if ((byte)pcVar49[0x19] + 1 == iVar16) {
          iVar13 = (int)uStackY_22 * 0x34;
          pcVar49 = (char *)"bath house" + 10;
          pcVar26 = (char *)"builder\'s hall" + 8;
          ovr_OVC41_6a8f_22cb();
        }
        if (iVar16 < (int)(uint)(byte)pcVar49[0x1b]) {
          *(undefined1 *)((int)uStackY_22 * 0x34 + 0xe) = (char)iVar16;
        }
        else {
          DAT_2410_07e2 = 8;
          pcVar26 = (char *)"mason\'s hall" + 6;
          ovr_agnt_3b1d_0a53();
        }
      }
      else {
        pcVar26 = (char *)"mason\'s hall" + 6;
        ovr_agnt_3b1d_0d82();
      }
    }
    else {
      pcVar26 = (char *)"elf outpost" + 8;
      ovr_OVC27_5ded_0cc2();
    }
  }
  uStackY_22 = (cte_t *)((int)uStackY_22 + 1);
  goto LAB_8699_3bde;
LAB_8699_3bf1:
  GGameState = 0x3a;
  if (DebugVerbose != false) {
    printf("%d \r",0x3a);
  }
  ovr_constr_36ce_08ee();
  GGameState = 0x2f;
  if (DebugVerbose != false) {
    printf("%d \r",0x2f);
  }
  if (DAT_2000_d0f5 != '\0') {
    ovr_attact_3f0b_26bd();
    DAT_2000_d0f5 = '\0';
  }
  cVar10 = '\0';
  cVar8 = '\0';
  uStackY_22 = (cte_t *)(uint)AgntCount;
  do {
    do {
      uStackY_22 = (cte_t *)((int)uStackY_22 - 1);
      if ((int)uStackY_22 < 0) goto LAB_8699_3cf7;
    } while (((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 0xae4) != 0) ||
            (*(char *)((int)uStackY_22 * 0x34 + 0x25) == '\x02'));
    if (*(char *)((int)uStackY_22 * 0x34 + 0x2f) == '\0') {
      cVar8 = '\x01';
    }
    else {
      cVar10 = '\x01';
    }
  } while ((cVar10 == '\0') || (cVar8 == '\0'));
LAB_8699_3cf7:
  if ((cVar8 == '\0') || (cVar10 == '\0')) {
    cVar56 = '\x01';
  }
  else {
    cVar56 = '\0';
  }
  cVar55 = '\0';
  uStackY_22 = (cte_t *)(uint)AgntCount;
  while (uStackY_22 = (cte_t *)((int)uStackY_22 - 1), -1 < (int)uStackY_22) {
    if (*(char *)((int)uStackY_22 * 0x34 + 0x25) == '\x02') {
      ovr_OVC41_6a8f_0256();
      DAT_2000_d0f5 = '\x01';
    }
    else if ((cVar56 != '\0') && ((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 0xae4) != 0)) {
      cVar55 = '\x01';
      *(undefined1 *)((int)uStackY_22 * 0x34 + 0x30) = 0;
      if ((((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 0x800) == 0) &&
          ((*(char *)*(undefined4 *)((int)uStackY_22 * 0x34 + 0x1d) == '\0' || (cVar10 != '\0'))))
         && ((*(char *)*(undefined4 *)((int)uStackY_22 * 0x34 + 0x1d) != '\0' || (cVar8 != '\0'))))
      {
        puVar3 = (uint *)((int)uStackY_22 * 0x34 + 0x2b);
        *puVar3 = *puVar3 & 0xf51b;
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0x2f) =
             *(undefined1 *)*(undefined4 *)((int)uStackY_22 * 0x34 + 0x1d);
        ovr_OVC41_6a8f_0246();
      }
      else {
        puVar3 = (uint *)((int)uStackY_22 * 0x34 + 0x2b);
        *puVar3 = *puVar3 & 0xf51b;
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0x21) = 0;
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0x23) = 10;
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0x24) = 2;
        *(undefined2 *)((int)uStackY_22 * 0x34 + 6) = 0;
      }
      DAT_2000_d0f5 = '\x01';
    }
  }
  if (DAT_2000_d0f5 != '\0') {
    ovr_attact_3f0b_26bd();
    DAT_2000_d0f5 = '\0';
  }
  iVar13 = EntityCount;
  if (cVar55 != '\0') {
    ovr_play_sfxU(0x3b,0,0x80);
    iVar13 = EntityCount;
  }
  do {
    do {
      iVar13 = iVar13 + -1;
      if (iVar13 < 0) {
        uVar14 = ovr_OVC41_6a8f_05ad();
        return uVar14;
      }
    } while ((*(char *)(Entities.ofs + iVar13 * 0x37 + 0xe) != '\0') ||
            (cVar10 = ovr_OVC23_55fe_05db(), cVar10 == '\0'));
    uStackY_22 = (cte_t *)(uint)AgntCount;
    do {
      uStackY_22 = (cte_t *)((int)uStackY_22 - 1);
      if ((int)uStackY_22 < 0) break;
    } while (*(int *)((int)uStackY_22 * 0x34 + 0x1b) != iVar13);
    if ((int)uStackY_22 < 0) {
      ovr_OVC15_4207_0e17();
      DAT_2000_d0fd = 1;
    }
  } while( true );
}



/* 8699:1e09 */

void __cdecl16far OVC49_8699_1e09(void)

{
  int *piVar1;
  char *pcVar2;
  uint *puVar3;
  bool mirror;
  byte bVar4;
  undefined4 uVar5;
  far_t gfx;
  far_t gfx_00;
  far_t dst;
  far_t dst_00;
  far_t gfx_01;
  char cVar6;
  uint16_t uVar7;
  int iVar8;
  uint uVar9;
  undefined2 uVar10;
  undefined2 *puVar11;
  int iVar12;
  int *piVar13;
  uint16_t *puVar14;
  undefined2 uVar15;
  uint16_t uVar16;
  undefined2 unaff_SS;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t gfx_05;
  far_t gfx_06;
  far_t gfx_07;
  undefined1 uVar17;
  undefined1 uVar18;
  uint8_t local_32 [8];
  undefined2 uStack_2a;
  int iStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  uint uStack_22;
  char cStack_20;
  char cStack_1f;
  byte bStack_1e;
  char cStack_1d;
  byte local_1c;
  byte bStack_1b;
  uint uStack_1a;
  int iStack_18;
  uint16_t uStack_16;
  char local_14 [2];
  uint16_t uStack_12;
  uint16_t uStack_10;
  undefined4 uStack_e;
  undefined4 uStack_a;
  char cStack_6;
  char cStack_5;
  char cStack_4;
  char cStack_3;
  
  F_SCOPY(local_32,(uint8_t *)0x842c,10);
  DAT_2000_d0f5 = '\0';
  uStack_2a = DAT_2000_d0f7;
  GGameState = 0x2b;
  if (DebugVerbose != false) {
    printf("%d \r",0x2b);
  }
  (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)DAT_2410_07e5;
  gfx.ofs = DAT_2410_07e3;
  (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)((uint)DAT_2410_07e5 >> 8);
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = (char)uStack_2a;
  dst.ofs = 0x8cc;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = (char)((uint)uStack_2a >> 8);
  ovr_blitLoadRleGfx(gfx,dst);
  (*(uint8_t *)((uint8_t *)&(gfx_00.seg))) = (char)DAT_2410_07e9;
  gfx_00.ofs = DAT_2410_07e7;
  (*(uint8_t *)((uint8_t *)&(gfx_00.seg) + 1)) = (char)((uint)DAT_2410_07e9 >> 8);
  (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = (char)uStack_2a;
  dst_00.ofs = (uint16_t)((char *)"Stronghold requires 585,000 bytes.\n" + 1);
  (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = (char)((uint)uStack_2a >> 8);
  ovr_blitLoadRleGfx(gfx_00,dst_00);
  GGameState = 0x2c;
  ovr_OVC23_55fe_0863((char)local_32);
  uVar17 = (undefined1)unaff_SS;
  uVar18 = (undefined1)((uint)unaff_SS >> 8);
  _fmemset((void *)CONCAT13(uVar18,CONCAT12(uVar17,local_14)),0,2);
  for (uStack_22 = 0; (int)uStack_22 < (int)(uint)AgntCount; uStack_22 = uStack_22 + 1) {
    local_14[*(byte *)(uStack_22 * 0x34 + 0x2f)] = '\x01';
  }
  if ((local_14[0] == '\0') || (local_14[1] == '\0')) {
    DAT_2000_d0f4 = 0;
  }
  else {
    DAT_2000_d0f4 = 1;
  }
  GGameState = 0x2d;
  if (DebugVerbose != false) {
    printf("%d \r",0x2d);
  }
  for (uStack_22 = 0; (int)uStack_22 < (int)(uint)AgntCount; uStack_22 = uStack_22 + 1) {
    uStack_a = CONCAT22(*(undefined2 *)(uStack_22 * 0x34 + 0x15),
                        *(undefined2 *)(uStack_22 * 0x34 + 0x13));
    OVC49_8699_1753(0,(char)(uStack_22 * 0x34),0x26);
    OVC49_8699_0874((char)(uStack_22 * 0x34),0x26,(char)uStack_22);
    uStack_24 = *(undefined2 *)(uStack_22 * 0x34);
    uStack_26 = *(undefined2 *)(uStack_22 * 0x34 + 2);
    bStack_1b = OVC49_8699_18c4((char)(uStack_22 * 0x34),0x26);
    uVar15 = (undefined2)((ulong)uStack_a >> 0x10);
    puVar11 = (undefined2 *)((int)uStack_a + (uint)bStack_1b * 4);
    _uStack_12 = CONCAT22(puVar11[1],*puVar11);
    uVar10 = 0x1726;
    iVar12 = (int)uStack_a + (uint)bStack_1b * 4;
    iVar12 = ovr_stash_474a_10ac((char)*(undefined2 *)(iVar12 + 0x58),
                                 (char)*(undefined2 *)(iVar12 + 0x5a),
                                 *(undefined1 *)(uStack_22 * 0x34 + 6));
    _iStack_18 = CONCAT22(uVar10,iVar12);
    if (*(char *)(uStack_22 * 0x34 + 4) < '\x01') {
      if (*(char *)(uStack_22 * 0x34 + 4) < '\0') {
        *(int *)(uStack_22 * 0x34) = *(int *)(uStack_22 * 0x34) - (int)*(char *)(iVar12 + 5);
      }
    }
    else {
      *(int *)(uStack_22 * 0x34) = *(int *)(uStack_22 * 0x34) + (int)*(char *)(iVar12 + 5);
    }
    cStack_1d = '\x01';
    iVar12 = (int)_uStack_12;
    uVar10 = (undefined2)((ulong)_uStack_12 >> 0x10);
    if (*(char *)(uStack_22 * 0x34 + 5) < '\x01') {
      if (*(char *)(uStack_22 * 0x34 + 5) < '\0') {
        piVar1 = (int *)(uStack_22 * 0x34 + 2);
        *piVar1 = *piVar1 - *(int *)(iVar12 + 0x11);
      }
      else {
        cStack_1d = '\0';
      }
    }
    else {
      piVar1 = (int *)(uStack_22 * 0x34 + 2);
      *piVar1 = *piVar1 + *(int *)(iVar12 + 0x11);
    }
    if (0x14 < *(int *)(uStack_22 * 0x34 + 2)) {
      if (*(char *)(uStack_22 * 0x34 + 5) < '\x01') {
        if (*(char *)(uStack_22 * 0x34 + 5) < '\0') {
          piVar1 = (int *)(uStack_22 * 0x34 + 2);
          *piVar1 = *piVar1 - *(int *)(iVar12 + 0x11);
        }
      }
      else {
        piVar1 = (int *)(uStack_22 * 0x34 + 2);
        *piVar1 = *piVar1 + *(int *)(iVar12 + 0x11);
      }
    }
    if ((((*(int *)(uStack_22 * 0x34) < 0) || (0xd2 < *(int *)(uStack_22 * 0x34))) ||
        (*(int *)(uStack_22 * 0x34 + 2) < 0)) ||
       ((*(char *)(uStack_22 * 0x34 + 0x11) == '\0' &&
        (cVar6 = OVC49_8699_0849((char)*(undefined2 *)(uStack_22 * 0x34)), cVar6 != '\0')))) {
      cStack_1f = '\0';
    }
    else {
      cStack_1f = '\x01';
    }
    if ((cStack_1f == '\0') || (0x14 < *(int *)(uStack_22 * 0x34 + 2))) {
      cStack_20 = '\0';
    }
    else {
      cStack_20 = '\x01';
    }
    if (*(char *)(uStack_22 * 0x34 + 0x11) == '\0') {
      iVar12 = ovr_agnt_3b1d_005e((char)*(undefined2 *)(uStack_22 * 0x34));
      iStack_28 = *(int *)(iVar12 * 2 + 0x34c) + *(int *)(uStack_22 * 0x34 + 2) + 3;
    }
    else {
      iVar12 = ovr_agnt_3b1d_005e((char)*(undefined2 *)(uStack_22 * 0x34));
      iStack_28 = *(int *)(iVar12 * 2 + 0x34c) + *(int *)(uStack_22 * 0x34 + 2) + -0x16;
    }
    *(int *)(uStack_22 * 0x34 + 0x28) = iStack_28;
    if ((*(char *)(uStack_22 * 0x34 + 0x10) == '\x05') && (*(char *)(uStack_22 * 0x34 + 0xc) != -1))
    {
      ovr_OVC41_6a8f_08c2((char)uStack_22);
    }
    cVar6 = OVC49_8699_1711((char)(uStack_22 * 0x34),0x26);
    if (((cVar6 == '\0') || (*(int *)(uStack_22 * 0x34 + 2) < 0)) ||
       ((-1 < *(int *)(uStack_22 * 0x34) &&
        ((*(int *)(uStack_22 * 0x34) < 0xd3 &&
         ((uint)(*(int *)(uStack_22 * 0x34 + 0x28) - *(int *)((int)_iStack_18 + 9)) < 0x96)))))) {
      if ((*(char *)(uStack_22 * 0x34 + 0x11) == '\0') &&
         (cVar6 = OVC49_8699_0849((char)*(undefined2 *)(uStack_22 * 0x34)), cVar6 != '\0')) {
        *(undefined2 *)(uStack_22 * 0x34) = uStack_24;
        *(undefined2 *)(uStack_22 * 0x34 + 2) = uStack_26;
        if (*(char *)(uStack_22 * 0x34 + 4) == '\0') {
          uVar7 = ovr_randBelow(3);
          *(char *)(uStack_22 * 0x34 + 4) = (char)uVar7 + -1;
        }
        else {
          *(char *)(uStack_22 * 0x34 + 4) = -*(char *)(uStack_22 * 0x34 + 4);
        }
        cVar6 = OVC49_8699_1711((char)(uStack_22 * 0x34),0x26);
        if (cVar6 == '\0') {
          uVar7 = ovr_randBelow(3);
          *(char *)(uStack_22 * 0x34 + 5) = (char)uVar7 + -1;
        }
        else {
          uVar7 = ovr_randBelow(2);
          *(undefined1 *)(uStack_22 * 0x34 + 5) = (char)uVar7;
        }
        if (*(char *)(uStack_22 * 0x34 + 4) == '\0') {
          *(undefined1 *)(uStack_22 * 0x34 + 5) = 0;
        }
        if ((('\0' < *(char *)(uStack_22 * 0x34 + 4)) && (*(char *)(uStack_22 * 0x34 + 0xf) != '\0')
            ) || ((*(char *)(uStack_22 * 0x34 + 4) < '\0' &&
                  (*(char *)(uStack_22 * 0x34 + 0xf) == '\0')))) {
          *(undefined1 *)(uStack_22 * 0x34 + 0x10) = 1;
        }
        cStack_1d = '\0';
        *(undefined2 *)(uStack_22 * 0x34 + 6) = 0;
        OVC49_8699_18c4((char)(uStack_22 * 0x34),0x26);
      }
      else if ((cStack_1f == '\0') ||
              (((cStack_20 == '\0' && (-1 < *(char *)(uStack_22 * 0x34 + 5))) &&
               (cVar6 = OVC49_8699_1711((char)(uStack_22 * 0x34),0x26), cVar6 == '\0')))) {
        if (*(char *)(uStack_22 * 0x34 + 0x25) != '\x02') {
          *(undefined2 *)(uStack_22 * 0x34) = uStack_24;
          *(undefined2 *)(uStack_22 * 0x34 + 2) = uStack_26;
          if ((*(uint *)(uStack_22 * 0x34 + 0x2b) & 0xbc0) == 0) {
            if (*(char *)(uStack_22 * 0x34 + 4) == '\0') {
              uVar7 = ovr_randBelow(2);
              *(char *)(uStack_22 * 0x34 + 4) = (char)uVar7 * '\x02' + -1;
            }
            else {
              *(char *)(uStack_22 * 0x34 + 4) = -*(char *)(uStack_22 * 0x34 + 4);
            }
            uVar7 = ovr_randBelow(3);
            *(char *)(uStack_22 * 0x34 + 5) = (char)uVar7 + -1;
          }
          if ((('\0' < *(char *)(uStack_22 * 0x34 + 4)) &&
              (*(char *)(uStack_22 * 0x34 + 0xf) != '\0')) ||
             ((*(char *)(uStack_22 * 0x34 + 4) < '\0' && (*(char *)(uStack_22 * 0x34 + 0xf) == '\0')
              ))) {
            *(undefined1 *)(uStack_22 * 0x34 + 0x10) = 1;
          }
          cStack_1d = '\0';
          *(undefined2 *)(uStack_22 * 0x34 + 6) = 0;
          OVC49_8699_18c4((char)(uStack_22 * 0x34),0x26);
        }
      }
      else {
        cVar6 = OVC49_8699_06dc((char)(uStack_22 * 0x34),0x26);
        if (cVar6 != '\0') {
          *(undefined2 *)(uStack_22 * 0x34) = uStack_24;
          *(undefined2 *)(uStack_22 * 0x34 + 2) = uStack_26;
          if ((*(char *)(uStack_22 * 0x34 + 0x11) == '\0') ||
             (*(char *)(uStack_22 * 0x34 + 4) != '\0')) {
            if (*(char *)(uStack_22 * 0x34 + 0x11) == '\0') {
              *(undefined1 *)(uStack_22 * 0x34 + 4) = 0;
            }
            else {
              *(char *)(uStack_22 * 0x34 + 4) = -*(char *)(uStack_22 * 0x34 + 4);
            }
          }
          else {
            uVar7 = ovr_randBelow(2);
            *(char *)(uStack_22 * 0x34 + 4) = (char)uVar7 * '\x02' + -1;
          }
          *(undefined1 *)(uStack_22 * 0x34 + 5) = 0;
          *(undefined2 *)(uStack_22 * 0x34 + 6) = 0;
          if ((('\0' < *(char *)(uStack_22 * 0x34 + 4)) &&
              (*(char *)(uStack_22 * 0x34 + 0xf) != '\0')) ||
             ((*(char *)(uStack_22 * 0x34 + 4) < '\0' && (*(char *)(uStack_22 * 0x34 + 0xf) == '\0')
              ))) {
            *(undefined1 *)(uStack_22 * 0x34 + 0x10) = 1;
          }
          cStack_1d = '\0';
          OVC49_8699_18c4((char)(uStack_22 * 0x34),0x26);
        }
      }
    }
    else {
      *(undefined1 *)(uStack_22 * 0x34 + 0x25) = 2;
    }
    OVC49_8699_1753((char)uStack_22 + '\x01',(char)(uStack_22 * 0x34),0x26);
    if ((cStack_1d != '\0') && (cVar6 = ovr_agnt_3b1d_177f((char)uStack_22), cVar6 != '\0')) {
      uStack_22 = uStack_22 + -1;
    }
  }
  GGameState = 0x2e;
  if (DebugVerbose != false) {
    printf("%d \r",0x2e);
  }
  for (uStack_22 = 0; (int)uStack_22 < (int)(uint)AgntCount; uStack_22 = uStack_22 + 1) {
    uVar10 = *(undefined2 *)(uStack_22 * 0x34 + 0x15);
    iVar12 = *(int *)(uStack_22 * 0x34 + 0x13);
    uStack_a = CONCAT22(uVar10,iVar12);
    uStack_1a = *(uint *)(uStack_22 * 0x34 + 6);
    bStack_1b = *(byte *)(uStack_22 * 0x34 + 0x12);
    puVar11 = (undefined2 *)(iVar12 + (uint)bStack_1b * 4);
    _uStack_12 = CONCAT22(puVar11[1],*puVar11);
    GGameState = 0x37;
    if (DebugVerbose != false) {
      printf("%d \r",0x37);
    }
    uVar15 = 0x1726;
    uVar10 = (undefined2)((ulong)uStack_a >> 0x10);
    iVar12 = (int)uStack_a + (uint)bStack_1b * 4;
    uVar10 = ovr_stash_474a_10ac((char)*(undefined2 *)(iVar12 + 0x58),
                                 (char)*(undefined2 *)(iVar12 + 0x5a),
                                 *(undefined1 *)(uStack_22 * 0x34 + 6));
    _iStack_18 = CONCAT22(uVar15,uVar10);
    GGameState = 0x38;
    if (DebugVerbose != false) {
      printf("%d \r",0x38);
    }
    iVar12 = *(int *)(uStack_22 * 0x34) + 0xc;
    if (*(char *)(uStack_22 * 0x34 + 0x11) == '\0') {
      iVar8 = ovr_agnt_3b1d_005e((char)*(undefined2 *)(uStack_22 * 0x34));
      iStack_28 = *(int *)(iVar8 * 2 + 0x34c) + *(int *)(uStack_22 * 0x34 + 2) + 3;
    }
    else {
      iVar8 = ovr_agnt_3b1d_005e((char)*(undefined2 *)(uStack_22 * 0x34));
      uVar5 = *(undefined4 *)(uStack_22 * 0x34 + 0x1d);
      iStack_28 = *(int *)(iVar8 * 2 + 0x34c) + *(int *)(uStack_22 * 0x34 + 2) +
                  (int)*(char *)((int)uVar5 + 0x52) + -0x16;
    }
    *(int *)(uStack_22 * 0x34 + 0x26) = iVar12;
    *(int16_t *)(uStack_22 * 0x34 + 0x28) = iStack_28;
    if ((*(uint *)(uStack_22 * 0x34 + 0x2b) & 0x800) == 0) {
      if (*(char *)(uStack_22 * 0x34 + 0x24) == '\0') {
        GGameState = 0x32;
        gfx_02.seg = uStack_16;
        gfx_02.ofs = iStack_18 + 6;
        ovr_blitGfxRect(gfx_02,iVar12,iStack_28,
                        (brect_t *)CONCAT13(uVar18,CONCAT12(uVar17,local_32)),0x10,
                        *(bool *)(uStack_22 * 0x34 + 0xf));
        GGameState = 0x33;
        if ((*(uint *)(uStack_22 * 0x34 + 0x2b) & 100) != 0) {
          mirror = *(bool *)(uStack_22 * 0x34 + 0xf);
          iVar8 = *(int *)((int)_uStack_12 + 0xd);
          bVar4 = *(byte *)(uStack_22 * 0x34 + 0x23);
          pcVar2 = (char *)(uStack_22 * 0x34 + 0x23);
          *pcVar2 = *pcVar2 + -1;
          uVar9 = bVar4 & 3;
          gfx_03.seg = ((undefined2 *)&DAT_2000_cc67)[uVar9 * 2];
          gfx_03.ofs = ((undefined2 *)&DAT_2000_cc65)[uVar9 * 2];
          ovr_blitGfxRect(gfx_03,iVar12,iStack_28 - iVar8,
                          (brect_t *)CONCAT13(uVar18,CONCAT12(uVar17,local_32)),0x10,mirror);
        }
      }
      else if (*(char *)(uStack_22 * 0x34 + 0x24) == '\x01') {
        uVar5 = *(undefined4 *)(uStack_22 * 0x34 + 0x1d);
        if ((*(uint *)((int)uVar5 + 0x40) & 2) == 0) {
          gfx_05.seg = uStack_16;
          gfx_05.ofs = iStack_18 + 6;
          ovr_blitGfxRect(gfx_05,iVar12,iStack_28,
                          (brect_t *)CONCAT13(uVar18,CONCAT12(uVar17,local_32)),0x10,
                          *(bool *)(uStack_22 * 0x34 + 0xf));
          uVar9 = *(byte *)(uStack_22 * 0x34 + 0x23) & 3;
          gfx_06.seg = ((undefined2 *)&DAT_2000_cc67)[uVar9 * 2];
          gfx_06.ofs = ((undefined2 *)&DAT_2000_cc65)[uVar9 * 2];
          ovr_blitGfxRect(gfx_06,iVar12,iStack_28 - *(int *)((int)_uStack_12 + 0xd),
                          (brect_t *)CONCAT13(uVar18,CONCAT12(uVar17,local_32)),0x10,
                          *(bool *)(uStack_22 * 0x34 + 0xf));
          if (*(char *)(uStack_22 * 0x34 + 0x23) == '\0') {
            *(undefined1 *)(uStack_22 * 0x34 + 0x24) = 0;
          }
          else {
            pcVar2 = (char *)(uStack_22 * 0x34 + 0x23);
            *pcVar2 = *pcVar2 + -1;
          }
        }
        else {
          gfx_04.seg = uStack_16;
          gfx_04.ofs = iStack_18 + 6;
          ovr_blitGfxRect(gfx_04,iVar12,iStack_28,
                          (brect_t *)CONCAT13(uVar18,CONCAT12(uVar17,local_32)),0x10,
                          *(bool *)(uStack_22 * 0x34 + 0xf));
          if ((int)(uint)*(byte *)((int)_uStack_12 + 0x1b) <= *(int *)(uStack_22 * 0x34 + 6) + 1) {
            *(undefined1 *)(uStack_22 * 0x34 + 0x24) = 0;
          }
        }
      }
      else if (*(char *)(uStack_22 * 0x34 + 0x24) == '\x02') {
        if (bStack_1b == 0x12) {
          gfx_07.seg = uStack_16;
          gfx_07.ofs = iStack_18 + 6;
          ovr_blitGfxRect(gfx_07,iVar12,iStack_28,
                          (brect_t *)CONCAT13(uVar18,CONCAT12(uVar17,local_32)),0x10,
                          *(bool *)(uStack_22 * 0x34 + 0xf));
          if ((int)(uint)*(byte *)((int)_uStack_12 + 0x1b) <= *(int *)(uStack_22 * 0x34 + 6) + 1) {
            *(undefined1 *)(uStack_22 * 0x34 + 0x25) = 2;
            ovr_OVC41_6a8f_0807((char)uStack_22);
          }
        }
        else {
          ovr_randBelow(0x100);
          ovr_gfxRlePrepare(iStack_18 + 6,uStack_16,iVar12,iStack_28);
          if (*(char *)(uStack_22 * 0x34 + 0x23) == '\0') {
            *(undefined1 *)(uStack_22 * 0x34 + 0x25) = 2;
            ovr_OVC41_6a8f_0807((char)uStack_22);
          }
          else {
            pcVar2 = (char *)(uStack_22 * 0x34 + 0x23);
            *pcVar2 = *pcVar2 + -1;
          }
        }
      }
    }
    else {
      ovr_gfxRlePrepare(iStack_18 + 6,uStack_16,iVar12,iStack_28);
    }
    if (*(char *)(uStack_22 * 0x34 + 0x30) != '\0') {
      ovr_agnt_3b1d_1035((char)uStack_22,(char)local_32);
    }
    uVar10 = (undefined2)((ulong)_uStack_12 >> 0x10);
    if (((*(uint *)(uStack_22 * 0x34 + 0x2b) & 8) == 0) ||
       ((uint)*(byte *)((int)_uStack_12 + 0x19) != *(uint *)(uStack_22 * 0x34 + 6))) {
      if (((uint)*(byte *)((int)_uStack_12 + 0x19) == *(uint *)(uStack_22 * 0x34 + 6)) &&
         ((*(char *)(uStack_22 * 0x34 + 0x24) == '\0' && (*(char *)(uStack_22 * 0x34 + 0xe) == -1)))
         ) {
        if (*(char *)(uStack_22 * 0x34 + 0xd) == '\0') {
          cVar6 = OVC49_8699_036e(uStack_22 * 0x34,0x26,(char)&local_1c);
          if (cVar6 == '\0') {
            if ((*(char *)(uStack_22 * 0x34 + 0x12) == '\x03') ||
               (*(char *)(uStack_22 * 0x34 + 0x12) == '\x0f')) {
              uVar7 = ovr_audio_3a5b_0afd((char)(uStack_22 * 0x34),0x26);
              ovr_play_sfxU(0x33,0,uVar7);
            }
            DAT_2410_07e2 = 9;
            ovr_agnt_3b1d_0a9f((char)(uStack_22 * 0x34),0x26);
          }
          else {
            *(char *)(uStack_22 * 0x34 + 0xc) = local_1c - 1;
          }
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x01') {
          cVar6 = OVC49_8699_0000(uStack_22 * 0x34,0x26,(char)&local_1c);
          if ((cVar6 == '\0') ||
             (cVar6 = ovr_OVC27_5ded_0404((char)(uStack_22 * 0x34),0x26,local_1c - 1), cVar6 == '\0'
             )) {
            DAT_2410_07e2 = 10;
            ovr_agnt_3b1d_0a9f((char)(uStack_22 * 0x34),0x26);
          }
          else {
            *(char *)(uStack_22 * 0x34 + 0xc) = local_1c - 1;
          }
        }
        else if (((*(char *)(uStack_22 * 0x34 + 0xd) == '\x02') ||
                 (*(char *)(uStack_22 * 0x34 + 0xd) == '\x04')) ||
                (*(char *)(uStack_22 * 0x34 + 0xd) == '\x05')) {
          cVar6 = ovr_agnt_3b1d_00ce(uStack_22 * 0x34,0x26,(char)&local_1c);
          if (cVar6 == '\0') {
            DAT_2410_07e2 = 0xb;
            ovr_agnt_3b1d_0a9f((char)(uStack_22 * 0x34),0x26);
          }
          else {
            *(char *)(uStack_22 * 0x34 + 0xc) = local_1c - 1;
          }
        }
        local_1c = *(char *)(uStack_22 * 0x34 + 0xc) + 1;
        if (((local_1c == 0) || (*(char *)((uint)local_1c * 0x34 + -0x10) != '\0')) ||
           ((*(char *)(uStack_22 * 0x34 + 0xd) != '\x06' &&
            ((0x14 < *(int *)(uStack_22 * 0x34 + 2) ||
             (0x14 < *(int *)((uint)local_1c * 0x34 + -0x32))))))) {
          DAT_2410_07e2 = 0xc;
          ovr_agnt_3b1d_0a9f((char)(uStack_22 * 0x34),0x26);
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x01') {
          cVar6 = ovr_OVC27_5ded_0a05((char)uStack_22);
          if (cVar6 == '\0') {
            DAT_2410_07e2 = 0xf;
            ovr_agnt_3b1d_0a9f((char)(uStack_22 * 0x34),0x26);
          }
        }
        else if (((*(char *)(uStack_22 * 0x34 + 0xd) == '\x02') ||
                 (*(char *)(uStack_22 * 0x34 + 0xd) == '\x04')) &&
                (*(char *)(uStack_22 * 0x34 + 0xe) == -1)) {
          uVar7 = ovr_audio_3a5b_0afd((char)(uStack_22 * 0x34),0x26);
          ovr_play_sfxU(*(byte *)((int)_uStack_12 + 0x1d),0,uVar7);
          *(undefined1 *)(uStack_22 * 0x34 + 0xe) = 0;
          *(undefined1 *)(uStack_22 * 0x34 + 0x2e) = 0;
          uVar10 = (undefined2)((ulong)_uStack_12 >> 0x10);
          iVar8 = (int)_uStack_12;
          *(char *)(uStack_22 * 0x34 + 10) = *(char *)(iVar8 + 0x15) + (char)iStack_28;
          if (*(char *)(uStack_22 * 0x34 + 0xf) == '\0') {
            *(int *)(uStack_22 * 0x34 + 8) = *(int *)(iVar8 + 0x13) + iVar12;
          }
          else {
            *(int *)(uStack_22 * 0x34 + 8) = iVar12 - *(int *)(iVar8 + 0x13);
          }
          *(undefined1 *)(uStack_22 * 0x34 + 0xb) = *(undefined1 *)(uStack_22 * 0x34 + 0xf);
        }
        else if ((*(char *)(uStack_22 * 0x34 + 0xd) == '\0') &&
                (uVar5 = *(undefined4 *)(uStack_22 * 0x34 + 0x1d),
                (*(uint *)((int)uVar5 + 0x3c) & 8) == 0)) {
          uVar7 = ovr_audio_3a5b_0afd((char)(uStack_22 * 0x34),0x26);
          ovr_play_sfxU(*(byte *)((int)_uStack_12 + 0x1d),0,uVar7);
          ovr_OVC41_6a8f_297d((char)(uStack_22 * 0x34),0x26,*(undefined1 *)(uStack_22 * 0x34 + 0xc))
          ;
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x03') {
          cVar6 = ovr_agnt_3b1d_0d4d(uStack_22 * 0x34,0x26,local_1c * '4' + -0x34,0x26);
          if ((cVar6 != '\0') && ((*(uint *)((uint)local_1c * 0x34 + -9) & 0x800) == 0)) {
            uVar5 = *(undefined4 *)((uint)local_1c * 0x34 + -0x1d);
            if (((*(uint *)((int)uVar5 + 0x14) & 2) == 0) ||
               ((uVar7 = ovr_randBelow(2), (uVar7 & 0xff) != 0 ||
                ((*(uint *)(uStack_22 * 0x34 + 0x2b) & 0x800) == 0)))) {
              ovr_OVC41_6a8f_0229(local_1c * '4' + -0x34,0x26);
              puVar3 = (uint *)((uint)local_1c * 0x34 + -9);
              *puVar3 = *puVar3 | 0x800;
              uVar7 = ovr_audio_3a5b_0afd(local_1c * '4' + -0x34,0x26);
              ovr_play_sfxU(0x1b,0,uVar7);
            }
            else {
              uVar7 = ovr_audio_3a5b_0afd((char)(uStack_22 * 0x34),0x26);
              ovr_play_sfxU(0x1b,0,uVar7);
              ovr_OVC41_6a8f_0229(local_1c * '4' + -0x34,0x26);
              puVar3 = (uint *)(uStack_22 * 0x34 + 0x2b);
              *puVar3 = *puVar3 | 0x800;
            }
          }
          DAT_2410_07e2 = 0xd;
          ovr_agnt_3b1d_0a9f((char)(uStack_22 * 0x34),0x26);
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x05') {
          uVar7 = ovr_audio_3a5b_0afd((char)(uStack_22 * 0x34),0x26);
          ovr_play_sfxU(*(byte *)((int)_uStack_12 + 0x1d),0,uVar7);
          *(undefined1 *)(uStack_22 * 0x34 + 0xe) = 0xf5;
          *(undefined1 *)(uStack_22 * 0x34 + 0x2e) = 1;
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x06') {
          uVar7 = ovr_audio_3a5b_0afd((char)(uStack_22 * 0x34),0x26);
          ovr_play_sfxU(*(byte *)((int)_uStack_12 + 0x1d),0,uVar7);
          ovr_OVC41_6a8f_297d((char)(uStack_22 * 0x34),0x26,*(undefined1 *)(uStack_22 * 0x34 + 0xc))
          ;
        }
        else {
          DAT_2410_07e2 = 0xe;
          ovr_agnt_3b1d_0a9f((char)(uStack_22 * 0x34),0x26);
        }
      }
    }
    else {
      ovr_OVC41_6a8f_297d((char)(uStack_22 * 0x34),0x26,*(undefined1 *)(uStack_22 * 0x34 + 0xc));
    }
    GGameState = 0x39;
    if (DebugVerbose != false) {
      printf("%d \r",0x39);
    }
    piVar1 = (int *)(uStack_22 * 0x34 + 6);
    *piVar1 = *piVar1 + 1;
    if (*(char *)(uStack_22 * 0x34 + 0xe) != -1) {
      if (*(char *)(uStack_22 * 0x34 + 0xc) == -1) {
        ovr_agnt_3b1d_0a53((char)(uStack_22 * 0x34),0x26);
        DAT_2410_07e2 = 7;
      }
      else if ((*(char *)(uStack_22 * 0x34 + 0x2e) == '\0') ||
              (*(char *)((uint)*(byte *)(uStack_22 * 0x34 + 0x2e) * 0x21 + -0x16) != '\0')) {
        bVar4 = *(byte *)(uStack_22 * 0x34 + 0xe);
        uStack_1a = (uint)bVar4;
        uVar10 = (undefined2)((ulong)uStack_a >> 0x10);
        uStack_e = uStack_a;
        if (*(char *)(uStack_22 * 0x34 + 0x2e) == '\0') {
          bStack_1e = 6;
        }
        else {
          bStack_1e = *(byte *)((uint)*(byte *)(uStack_22 * 0x34 + 0x2e) * 0x21 + -0x16);
        }
        piVar13 = (int *)((int)uStack_a + (uint)bStack_1e * 4);
        if (*piVar13 == 0 && piVar13[1] == 0) {
          uStack_e = CONCAT22(SprProjectiles.seg,SprProjectiles.ofs);
        }
        uVar10 = (undefined2)((ulong)uStack_e >> 0x10);
        iVar12 = (int)uStack_e;
        puVar14 = (uint16_t *)(iVar12 + (uint)bStack_1e * 4);
        uVar7 = *puVar14;
        _uStack_12 = CONCAT22(puVar14[1],uVar7);
        piVar13 = (int *)(iVar12 + (uint)bStack_1e * 4);
        if (*piVar13 == 0 && piVar13[1] == 0) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0xf);
        }
        iVar12 = iVar12 + (uint)bStack_1e * 4;
        iVar12 = ovr_stash_474a_10ac((char)*(undefined2 *)(iVar12 + 0x58),
                                     (char)*(undefined2 *)(iVar12 + 0x5a),bVar4);
        _iStack_18 = CONCAT22(uVar7,iVar12);
        GGameState = 0x30;
        gfx_01.seg = uVar7;
        gfx_01.ofs = iVar12 + 6;
        ovr_blitGfxRect(gfx_01,*(int16_t *)(uStack_22 * 0x34 + 8),
                        (uint)*(byte *)(uStack_22 * 0x34 + 10),
                        (brect_t *)CONCAT13(uVar18,CONCAT12(uVar17,local_32)),0x10,
                        *(bool *)(uStack_22 * 0x34 + 0xb));
        GGameState = 0x31;
        uVar10 = (undefined2)((ulong)_uStack_12 >> 0x10);
        iVar12 = (int)_uStack_12;
        if ((*(byte *)(iVar12 + 0x1c) & 2) == 0) {
          uVar15 = (undefined2)((ulong)_iStack_18 >> 0x10);
          if (*(char *)(uStack_22 * 0x34 + 0xb) == '\0') {
            piVar1 = (int *)(uStack_22 * 0x34 + 8);
            *piVar1 = *piVar1 + (int)*(char *)((int)_iStack_18 + 5);
          }
          else {
            piVar1 = (int *)(uStack_22 * 0x34 + 8);
            *piVar1 = *piVar1 - (int)*(char *)((int)_iStack_18 + 5);
          }
          uStack_1a = uStack_1a + 1;
          if (*(byte *)(iVar12 + 0x19) + 1 == uStack_1a) {
            ovr_OVC41_6a8f_22cb((char)(uStack_22 * 0x34),0x26,
                                *(undefined1 *)(uStack_22 * 0x34 + 0xc));
          }
          if ((int)uStack_1a < (int)(uint)*(byte *)((int)_uStack_12 + 0x1b)) {
            *(undefined1 *)(uStack_22 * 0x34 + 0xe) = (undefined1)uStack_1a;
          }
          else {
            DAT_2410_07e2 = 8;
            ovr_agnt_3b1d_0a53((char)(uStack_22 * 0x34),0x26);
          }
        }
        else {
          ovr_agnt_3b1d_0d82(uStack_22 * 0x34,0x1726,iVar12,(char)((ulong)_uStack_12 >> 0x10),
                             (char)_iStack_18,(char)((ulong)_iStack_18 >> 0x10));
        }
      }
      else {
        ovr_OVC27_5ded_0cc2((char)uStack_22,(char)local_32);
      }
    }
  }
  GGameState = 0x3a;
  if (DebugVerbose != false) {
    printf("%d \r",0x3a);
  }
  ovr_constr_36ce_08ee((char)local_32);
  GGameState = 0x2f;
  if (DebugVerbose != false) {
    printf("%d \r",0x2f);
  }
  if (DAT_2000_d0f5 != '\0') {
    ovr_attact_3f0b_26bd();
    DAT_2000_d0f5 = '\0';
  }
  cStack_3 = '\0';
  cStack_4 = '\0';
  uStack_22 = (uint)AgntCount;
  do {
    do {
      uStack_22 = uStack_22 - 1;
      if ((int)uStack_22 < 0) goto LAB_8699_3cf7;
    } while (((*(uint *)(uStack_22 * 0x34 + 0x2b) & 0xae4) != 0) ||
            (*(char *)(uStack_22 * 0x34 + 0x25) == '\x02'));
    if (*(char *)(uStack_22 * 0x34 + 0x2f) == '\0') {
      cStack_3 = '\x01';
    }
    else {
      cStack_4 = '\x01';
    }
  } while ((cStack_4 == '\0') || (cStack_3 == '\0'));
LAB_8699_3cf7:
  if ((cStack_3 == '\0') || (cStack_4 == '\0')) {
    cStack_5 = '\x01';
  }
  else {
    cStack_5 = '\0';
  }
  cStack_6 = '\0';
  uStack_22 = (uint)AgntCount;
  while (uStack_22 = uStack_22 - 1, -1 < (int)uStack_22) {
    if (*(char *)(uStack_22 * 0x34 + 0x25) == '\x02') {
      ovr_OVC41_6a8f_0256((char)uStack_22,0);
      DAT_2000_d0f5 = '\x01';
    }
    else if ((cStack_5 != '\0') && ((*(uint *)(uStack_22 * 0x34 + 0x2b) & 0xae4) != 0)) {
      cStack_6 = '\x01';
      *(undefined1 *)(uStack_22 * 0x34 + 0x30) = 0;
      if ((((*(uint *)(uStack_22 * 0x34 + 0x2b) & 0x800) == 0) &&
          ((*(char *)*(undefined4 *)(uStack_22 * 0x34 + 0x1d) == '\0' || (cStack_4 != '\0')))) &&
         ((*(char *)*(undefined4 *)(uStack_22 * 0x34 + 0x1d) != '\0' || (cStack_3 != '\0')))) {
        puVar3 = (uint *)(uStack_22 * 0x34 + 0x2b);
        *puVar3 = *puVar3 & 0xf51b;
        *(undefined1 *)(uStack_22 * 0x34 + 0x2f) =
             *(undefined1 *)*(undefined4 *)(uStack_22 * 0x34 + 0x1d);
        ovr_OVC41_6a8f_0246((char)(uStack_22 * 0x34),0x26);
      }
      else {
        puVar3 = (uint *)(uStack_22 * 0x34 + 0x2b);
        *puVar3 = *puVar3 & 0xf51b;
        *(undefined1 *)(uStack_22 * 0x34 + 0x21) = 0;
        *(undefined1 *)(uStack_22 * 0x34 + 0x23) = 10;
        *(undefined1 *)(uStack_22 * 0x34 + 0x24) = 2;
        *(undefined2 *)(uStack_22 * 0x34 + 6) = 0;
      }
      DAT_2000_d0f5 = '\x01';
    }
  }
  if (DAT_2000_d0f5 != '\0') {
    ovr_attact_3f0b_26bd();
    DAT_2000_d0f5 = '\0';
  }
  iVar12 = EntityCount;
  if (cStack_6 != '\0') {
    ovr_play_sfxU(0x3b,0,0x80);
    iVar12 = EntityCount;
  }
  do {
    do {
      iVar12 = iVar12 + -1;
      if (iVar12 < 0) {
        ovr_OVC41_6a8f_05ad();
        return;
      }
      uVar16 = Entities.seg;
      uVar7 = Entities.ofs;
    } while ((*(char *)(uVar7 + iVar12 * 0x37 + 0xe) != '\0') ||
            (cVar6 = ovr_OVC23_55fe_05db((char)*(undefined2 *)(uVar7 + iVar12 * 0x37),
                                         (char)*(undefined2 *)(uVar7 + iVar12 * 0x37 + 2)),
            cVar6 == '\0'));
    uStack_22 = (uint)AgntCount;
    do {
      uStack_22 = uStack_22 - 1;
      if ((int)uStack_22 < 0) break;
    } while (*(int *)(uStack_22 * 0x34 + 0x1b) != iVar12);
    if ((int)uStack_22 < 0) {
      ovr_OVC15_4207_0e17((char)iVar12);
      DAT_2000_d0fd = 1;
    }
  } while( true );
}


