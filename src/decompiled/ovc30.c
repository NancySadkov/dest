/*
 * ovc30.c - recovered from STRONG.EXE
 * memory block: OVC30
 * range: 619c:0000 - 619c:0baf
 * functions: 7
 */
#include "recovered.h"


/* 619c:0000 */

uint __cdecl16far OVC30_619c_0000(void)

{
  uint uVar1;
  
  if (*(char *)(DAT_2000_d19d + 0x5de4) == '\0') {
    uVar1 = 10;
  }
  else {
    uVar1 = (uint)(0x3c / (ulong)(long)(int)(uint)*(byte *)(DAT_2000_d19d + 0x5de4));
    if (uVar1 == 0) {
      uVar1 = 1;
    }
    if (9 < uVar1) {
      uVar1 = 10;
    }
  }
  return uVar1;
}



/* 619c:004e */

void __cdecl16far OVC30_619c_004e(byte param_1)

{
  undefined2 uVar1;
  char *msg;
  char cVar2;
  uint16_t uVar3;
  char local_7c [121];
  char cStack_3;
  
  if (DAT_2000_d310 < 2) {
    DAT_2000_d310 = DAT_2000_d310 + 1;
    if (DAT_2000_d310 == 1) {
      cVar2 = *(char *)(DAT_2000_d19d + 0x5dcb);
      uVar3 = ovr_randBelow((byte)((undefined1 *)&DAT_2410_5dcf)[DAT_2000_d19d] + 1);
      cStack_3 = cVar2 + (char)uVar3;
      while (cStack_3 != '\0') {
        cStack_3 = cStack_3 + -1;
        uVar1 = OVC30_619c_025d(0,1,1,0x19);
        OVC30_619c_05a5(uVar1,0,0,0);
      }
      cVar2 = *(char *)(DAT_2000_d19d + 0x5dd3);
      cStack_3 = cStack_3 + -1;
      uVar3 = ovr_randBelow((byte)((undefined1 *)&DAT_2410_5dcf)[DAT_2000_d19d] + 1);
      cStack_3 = cVar2 + (char)uVar3;
      while (cStack_3 != '\0') {
        cStack_3 = cStack_3 + -1;
        uVar1 = OVC30_619c_025d(1,1,1,0x19);
        OVC30_619c_05a5(uVar1,0,0,0);
      }
      cVar2 = *(char *)(DAT_2000_d19d + 0x5ddb);
      cStack_3 = cStack_3 + -1;
      uVar3 = ovr_randBelow((byte)((undefined1 *)&DAT_2410_5ddf)[DAT_2000_d19d] + 1);
      cStack_3 = cVar2 + (char)uVar3;
      while (cStack_3 != '\0') {
        cStack_3 = cStack_3 + -1;
        uVar1 = OVC30_619c_025d(2,1,1,0);
        OVC30_619c_05a5(uVar1,0,0,0);
      }
      cStack_3 = -1;
    }
    else {
      cStack_3 = *(char *)(DAT_2000_d19d + 0x5de3);
      while (cVar2 = cStack_3 + -1, cStack_3 != '\0') {
        cStack_3 = cVar2;
        uVar1 = OVC30_619c_025d(3,1,1,0);
        OVC30_619c_05a5(uVar1,0,0,0);
      }
      cStack_3 = cVar2;
      if (1 < DAT_2000_d19d) {
        uVar1 = OVC30_619c_025d(4,1,1,0);
        OVC30_619c_05a5(uVar1,0,0,0);
      }
      if ((param_1 & 1) != 0) {
        ovr_uiNotify("All enemies destroyed.",0xa000);
        ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x36));
      }
      uVar3 = 0xa000;
      msg = ovr_stsprintf(local_7c,"Next wave of enemies appear.",(char *)(DAT_2000_d310 + 1));
      ovr_uiNotify(msg,uVar3);
      ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x36));
    }
    if ((param_1 & 2) == 0) {
      ovr_constr_36ce_03a6();
    }
  }
  return;
}



/* 619c:025d */

undefined2 __cdecl16far OVC30_619c_025d(byte param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  undefined2 uVar1;
  uint16_t uVar2;
  undefined2 unaff_SS;
  undefined2 local_a;
  undefined2 uStack_8;
  undefined2 local_6;
  undefined2 uStack_4;
  
  uStack_4 = DAT_2410_5dee;
  local_6 = DAT_2410_5dec;
  uStack_8 = DAT_2410_5df2;
  local_a = DAT_2410_5df0;
  if (param_1 == 4) {
    uVar1 = CONCAT11((char)((uint)DAT_2410_5df2 >> 8),0x29);
  }
  else {
    do {
      do {
        uVar2 = ovr_randBelow(0x2a);
      } while ((char)uVar2 == ')');
    } while (((*(char *)((int)(char **)GMenuStrings + (uVar2 & 0xff) * 0x95 + 0x1f) == '\0') ||
             (*(byte *)((int)&far_t_ARRAY_2410_26f7[0xc].seg + (uVar2 & 0xff) * 0x95) <
              *(byte *)((int)&local_6 + (uint)param_1))) ||
            (*(byte *)((int)&local_a + (uint)param_1) <
             *(byte *)((int)&far_t_ARRAY_2410_26f7[0xc].seg + (uVar2 & 0xff) * 0x95)));
    uVar1 = CONCAT11((char)((int)&local_a + (uint)param_1 >> 8),(char)uVar2);
  }
  return uVar1;
}



/* 619c:031d */

undefined1 __cdecl16far OVC30_619c_031d(byte param_1)

{
  undefined1 uVar1;
  
  if (param_1 < 5) {
    uVar1 = 0;
  }
  else if (param_1 < 9) {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}



/* 619c:0339 */

uint __cdecl16far OVC30_619c_0339(byte param_1,undefined2 param_2,undefined2 param_3)

{
  uint uVar1;
  uint16_t uVar2;
  char *pcVar3;
  uint uStack_8;
  char *pcStack_6;
  undefined2 uStack_4;
  
  uStack_8 = 0;
  while ((uStack_8 < DAT_2000_d1e6 &&
         (*(char *)((int)*(undefined4 *)(uStack_8 << 2) + 0x28) != '\0'))) {
    uStack_8 = uStack_8 + 1;
  }
  if (uStack_8 < DAT_2000_d1e6) {
    uStack_4 = ((undefined2 *)(uStack_8 * 4))[1];
    pcStack_6 = (char *)*(undefined2 *)(uStack_8 * 4);
  }
  else {
    if (0x4f < DAT_2000_d1e6) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x21);
    }
    if (!GameRunning) {
      ovr_fmFreeAudio(1);
    }
    pcVar3 = ovr_stshAlloc(0xae);
    pcStack_6 = (char *)pcVar3;
    uStack_4 = (undefined2)((ulong)pcVar3 >> 0x10);
    uStack_8 = (uint)DAT_2000_d1e6;
    uVar1 = (uint)DAT_2000_d1e6;
    ((undefined2 *)(uVar1 * 4))[1] = uStack_4;
    *(undefined2 *)(uVar1 * 4) = (uint16_t)(ulong)pcStack_6;
    DAT_2000_d1e6 = DAT_2000_d1e6 + 1;
  }
  _fmemset((char *)CONCAT22(uStack_4,pcStack_6),0,0xae);
  strcpy(pcStack_6,
         (char *)*(undefined2 *)((int)&far_t_ARRAY_2410_26f7[0].seg + 1 + (uint)param_1 * 0x95));
  pcStack_6[0x3d] = '\x01';
  *(undefined2 *)(pcStack_6 + 0x39) = param_2;
  *(undefined2 *)(pcStack_6 + 0x3b) = param_3;
  pcStack_6[0x3e] = param_1;
  pcStack_6[0x2f] = -1;
  pcStack_6[0x30] = '\x03';
  uVar2 = ovr_randBelow(1);
  pcStack_6[0x34] = (char)uVar2;
  ovr_manage_4d05_01d4(pcStack_6,uStack_4);
  if (*(char *)((int)&far_t_ARRAY_2410_26f7[0xc].seg + (uint)param_1 * 0x95) != -1) {
    pcStack_6[0x2a] = *(char *)((int)&far_t_ARRAY_2410_26f7[0xc].seg + (uint)param_1 * 0x95);
  }
  if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[7].seg + 1 + (uint)param_1 * 0x95) & 0x800) != 0) {
    pcStack_6[0x2d] = '\x12';
  }
  pcStack_6[0x3f] = *(char *)((int)(char **)GMenuStrings + (uint)param_1 * 0x95 + 0x1f);
  pcStack_6[0x33] = *(char *)((int)(far_t *)(far_t_ARRAY_2410_26f7 + 9) + (uint)param_1 * 0x95);
  pcStack_6[0x31] = *(char *)((int)&far_t_ARRAY_2410_26f7[6].seg + (uint)param_1 * 0x95);
  pcStack_6[0x32] = pcStack_6[0x31];
  pcStack_6[0x28] = pcStack_6[0x28] | 0x16;
  pcStack_6[0x40] = '\x01';
  (pcStack_6 + 0x58)[0] = '\0';
  (pcStack_6 + 0x58)[1] = '\0';
  (pcStack_6 + 0x56)[0] = 'd';
  (pcStack_6 + 0x56)[1] = '\0';
  pcStack_6[0x89] = -1;
  ovr_OVC22_5087_056e();
  return uStack_8 & 0xff;
}



/* 619c:05a5 */

byte __cdecl16far OVC30_619c_05a5(byte param_1,int param_2,char param_3,byte param_4)

{
  byte *pbVar1;
  undefined4 uVar2;
  bool bVar3;
  char cVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined1 uVar11;
  undefined1 uVar12;
  undefined1 extraout_AH;
  uint16_t uVar10;
  uint uVar13;
  uint uVar14;
  byte bStack_13;
  byte bStack_11;
  int iStack_10;
  uint uStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  int iStack_4;
  
  iStack_6 = 1;
  bStack_11 = 0xff;
  iVar6 = ovr_OVC25_5b66_18cc(param_1);
  iStack_10 = iVar6 * 3 + 0xf;
  if (0x31 < iStack_10) {
    iStack_10 = 0x32;
  }
  do {
    if (param_2 == 0) {
      return bStack_11;
    }
    if (param_3 == '\x02') {
      uStack_c = DAT_2410_5df6;
      param_3 = '\x01';
      uVar9 = DAT_2410_5df4;
    }
    else if (param_3 == '\0') {
      iStack_8 = DAT_2410_5df4 + iStack_6 * -8;
      iStack_a = DAT_2410_5df4 + iStack_6 * 8;
      if (iStack_8 < 8) {
        iStack_8 = 8;
      }
      if (0x8c < iStack_a) {
        iStack_a = 0x8c;
      }
      uVar10 = ovr_randBelow((iStack_a - iStack_8) + 1);
      uVar9 = (uVar10 & 0xff) + iStack_8 & 0xfffc;
      iStack_8 = DAT_2410_5df6 + iStack_6 * -4;
      iStack_a = DAT_2410_5df6 + iStack_6 * 4;
      if (iStack_8 < 8) {
        iStack_8 = 8;
      }
      if (0x34 < iStack_a) {
        iStack_a = 0x34;
      }
      uVar10 = ovr_randBelow((iStack_a - iStack_8) + 1);
      uStack_c = (uVar10 & 0xff) + iStack_8;
    }
    else {
      bStack_13 = 0;
      do {
        bVar3 = false;
        uVar10 = ovr_randBelow(0x8c);
        uVar9 = (uVar10 & 0xff) + 4 & 0xfffc;
        uVar10 = ovr_randBelow(0x3a);
        uStack_c = uVar10 & 0xff;
        for (iVar6 = 0; iVar6 < (int)(uint)DAT_2000_d1e6; iVar6 = iVar6 + 1) {
          if (((*(char *)((int)*(undefined4 *)(iVar6 << 2) + 0x3d) != '\0') &&
              (*(char *)((int)*(undefined4 *)(iVar6 << 2) + 0x3f) != '\0')) &&
             (uVar7 = *(int *)((int)*(undefined4 *)(iVar6 << 2) + 0x39) - uVar9,
             uVar13 = (int)uVar7 >> 0xf,
             uVar8 = *(int *)((int)*(undefined4 *)(iVar6 << 2) + 0x3b) - uStack_c,
             uVar14 = (int)uVar8 >> 0xf,
             (int)((int)((uVar7 ^ uVar13) - uVar13) / 2 + ((uVar8 ^ uVar14) - uVar14)) < 10)) {
            bVar3 = true;
            bStack_13 = bStack_13 + 1;
            break;
          }
          if (((*(char *)((int)*(undefined4 *)(iVar6 << 2) + 0x3d) != '\0') &&
              (*(char *)((int)*(undefined4 *)(iVar6 << 2) + 0x3f) == '\0')) &&
             (uVar7 = *(int *)((int)*(undefined4 *)(iVar6 << 2) + 0x39) - uVar9,
             uVar13 = (int)uVar7 >> 0xf,
             uVar8 = *(int *)((int)*(undefined4 *)(iVar6 << 2) + 0x3b) - uStack_c,
             uVar14 = (int)uVar8 >> 0xf,
             (int)((int)((uVar7 ^ uVar13) - uVar13) / 2 + ((uVar8 ^ uVar14) - uVar14)) < iStack_10))
          {
            bVar3 = true;
            bStack_13 = bStack_13 + 1;
            break;
          }
        }
      } while ((bVar3) && (bStack_13 < 100));
    }
    cVar4 = ovr_constr_36ce_306b(uVar9 - 1,uStack_c);
    if (((cVar4 == '\0') || (cVar4 = ovr_constr_36ce_306b(uVar9,uStack_c), cVar4 == '\0')) ||
       (cVar4 = ovr_OVC18_48ac_1022(uVar9,uStack_c), cVar4 != '\0')) {
      iStack_6 = iStack_6 + 1;
      if (500 < iStack_6) {
        return bStack_11;
      }
    }
    else {
      bStack_11 = OVC30_619c_0339(param_1,uVar9,uStack_c);
      if (1 < DAT_2000_d310) {
        pbVar1 = (byte *)((int)*(undefined4 *)((uint)bStack_11 << 2) + 0x5d);
        *pbVar1 = *pbVar1 | 0x10;
      }
      uVar11 = (undefined1)((uint)param_1 * 0x95 >> 8);
      if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[7].seg + 1 + (uint)param_1 * 0x95) & 0x800) == 0) {
        if (DAT_2000_d310 < 2) {
          uVar2 = *(undefined4 *)((uint)bStack_11 << 2);
          uVar12 = (undefined1)(((uint)bStack_11 << 2) >> 8);
          ovr_OVC15_4207_10a3(uVar9,uStack_c,uVar9,uStack_c,CONCAT11(uVar12,param_1),
                              CONCAT11(uVar12,*(undefined1 *)((int)uVar2 + 0xa4)),
                              CONCAT11(uVar11,bStack_11));
        }
        else {
          for (iStack_4 = 0; bVar5 = OVC30_619c_0000(), iStack_4 < (int)(uint)bVar5;
              iStack_4 = iStack_4 + 1) {
            ovr_OVC15_4207_10a3(uVar9,uStack_c,uVar9,uStack_c,param_1,10,bStack_11);
          }
        }
      }
      else {
        ovr_OVC15_4207_10a3(uVar9,uStack_c,uVar9,uStack_c,CONCAT11(uVar11,param_1),1,
                            CONCAT11(uVar11,bStack_11));
        iStack_4 = 0;
        while( true ) {
          bVar5 = OVC30_619c_0000();
          iVar6 = (uint)bVar5 * 2;
          if (iVar6 - iStack_4 == 0 || iVar6 < iStack_4) break;
          ovr_OVC18_48ac_0382(CONCAT11((char)((uint)iVar6 >> 8),bStack_11),uVar9,uStack_c,2);
          iStack_4 = iStack_4 + 1;
        }
      }
      if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[7].seg + 1 + (uint)param_1 * 0x95) & 0x1000) != 0)
      {
        OVC30_619c_0a5e(uVar9,uStack_c);
      }
      *(undefined1 *)((int)*(undefined4 *)((uint)bStack_11 << 2) + 0x5a) = 0;
      *(uint *)(uVar9 * 0x78 + (int)DAT_2000_cb0d + uStack_c * 2 + -0x78) =
           (uint)*(byte *)((int)(far_t *)(far_t_ARRAY_2410_26f7 + 0xb) + (uint)param_1 * 0x95);
      iVar6 = uVar9 * 0x78 + (int)DAT_2000_cb0d + uStack_c * 2;
      ovr_OVC23_55fe_1005(uVar9 - 1,uStack_c,
                          CONCAT11((char)((uint)iVar6 >> 8),*(undefined1 *)(iVar6 + -0x78)),
                          bStack_11);
      ovr_OVC23_55fe_1005(uVar9,uStack_c,0,CONCAT11(extraout_AH,bStack_11));
      *(undefined2 *)((int)DAT_2000_cb0d + uVar9 * 0x78 + uStack_c * 2) = 0;
      param_2 = param_2 + -1;
      DAT_2410_5df6 = uStack_c;
      DAT_2410_5df4 = uVar9;
      uVar10 = ovr_randBelow(100);
      param_3 = (byte)uVar10 < param_4;
      iStack_6 = 0;
    }
  } while( true );
}



/* 619c:0a5e */

void __cdecl16far OVC30_619c_0a5e(int param_1,int param_2)

{
  char cVar1;
  uint16_t uVar2;
  int iVar3;
  undefined2 uStack_6;
  
  for (uStack_6 = -0xc; uStack_6 < 0xd; uStack_6 = uStack_6 + 1) {
    for (iVar3 = -8; iVar3 < 9; iVar3 = iVar3 + 1) {
      uVar2 = ovr_randBelow(2);
      if ((uVar2 & 0xff) == 0) {
        cVar1 = ovr_OVC45_77eb_0aea(param_1 + uStack_6,param_2 + iVar3);
        if (cVar1 != '\0') {
          uVar2 = ovr_randBelow(9);
          *(int *)((int)DAT_2000_cb0d + (param_1 + uStack_6) * 0x78 + (param_2 + iVar3) * 2) =
               (uVar2 & 0xff) + 0xef;
        }
      }
    }
  }
  return;
}


