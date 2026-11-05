/*
 * ovc37_season.c - recovered from STRONG.EXE
 * memory block: OVC37_season.c
 * range: 67e7:0000 - 67e7:0c4f
 * functions: 11
 */
#include "recovered.h"


/* 67e7:0000 */

char * __cdecl16far season_67e7_0000(void)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if ((int)(uint)DAT_2000_d1e6 <= iVar1) {
      return (char *)0x1;
    }
    if ((*(char *)((int)*(undefined4 *)(iVar1 << 2) + 0x3d) != '\0') &&
       (*(char *)((int)*(undefined4 *)(iVar1 << 2) + 0x3f) != '\0')) break;
    iVar1 = iVar1 + 1;
  }
  return (char *)"main castle" + 1;
}



/* 67e7:004d */

uint __cdecl16far season_67e7_004d(undefined1 param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  size_t sVar4;
  undefined4 *puVar5;
  undefined1 uVar7;
  undefined2 uVar6;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  char *pcVar8;
  undefined2 unaff_SS;
  char *pcVar9;
  undefined4 uVar10;
  char local_a8 [80];
  undefined1 local_58 [80];
  int iStack_8;
  uint uStack_6;
  char cStack_4;
  byte bStack_3;
  
  uVar2 = ovr_manage_4d05_1b1d();
  bStack_3 = (byte)uVar2;
  if (bStack_3 == 0xff) {
    return uVar2 & 0xff00;
  }
  piVar3 = (int *)((uVar2 & 0xff) * 4);
  uVar2 = piVar3[1];
  iVar1 = *piVar3;
  _iStack_8 = CONCAT22(uVar2,iVar1);
  if (8 < *(byte *)(iVar1 + 0x86)) {
    return uVar2 & 0xff00;
  }
  *(char *)(iVar1 + 0x86) = *(char *)(iVar1 + 0x86) + '\x01';
  strcpy(local_a8,(char *)((far_t *)(GStatsLabels + 4) +
                          (uint)*(byte *)(iVar1 + 0x34) + (uint)*(byte *)(iVar1 + 0x86) * 2)->ofs);
  sVar4 = strlen(local_a8);
  pcVar8 = local_a8;
  pcVar8[sVar4 - 1] = '\0';
  puVar5 = (undefined4 *)(uint)DAT_2410_6a88;
  if (puVar5 == (undefined4 *)0x0) {
    if (((DAT_2000_d310 < 2) ||
        (pcVar8 = (char *)"halfling castle" + 0xc,
        *(char *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x33) != '\x02')) ||
       (puVar5 = (undefined4 *)season_67e7_0000(), (char)puVar5 == '\0')) {
      puVar5 = (undefined4 *)((uint)bStack_3 << 2);
      pcVar8 = (char *)"halfling castle" + 0xc;
      if (*(byte *)((int)*puVar5 + 0x86) < 9) goto LAB_67e7_0195;
      puVar5 = (undefined4 *)((uint)bStack_3 << 2);
      pcVar8 = (char *)"halfling castle" + 0xc;
      if (*(char *)((int)*puVar5 + 0x33) != '\0') {
        puVar5 = (undefined4 *)((uint)bStack_3 << 2);
        pcVar8 = (char *)"halfling castle" + 0xc;
        if ((*(char *)((int)*puVar5 + 0x33) != '\x01') ||
           (puVar5 = (undefined4 *)season_67e7_0000(), (char)puVar5 == '\0')) goto LAB_67e7_0195;
      }
    }
    uVar7 = (undefined1)((uint)puVar5 >> 8);
    cStack_4 = '\x01';
  }
  else {
LAB_67e7_0195:
    uVar7 = (undefined1)((uint)puVar5 >> 8);
    cStack_4 = '\0';
  }
  if (cStack_4 == '\0') {
    uVar10 = CONCAT22(CONCAT11(uVar7,param_1),unaff_SS);
    pcVar9 = local_a8;
    uVar6 = ovr_OVC15_4207_1c79(local_58);
    ovr_OVC40_69c8_04c6(0,uVar6,pcVar8,pcVar9,uVar10);
    uVar7 = extraout_AH_00;
  }
  else {
    uVar10 = CONCAT22(CONCAT11(uVar7,param_1),unaff_SS);
    pcVar9 = local_a8;
    uVar6 = ovr_OVC15_4207_1c79(local_58);
    ovr_OVC40_69c8_04c6(2,uVar6,pcVar8,pcVar9,uVar10);
    uVar7 = extraout_AH;
  }
  if (cStack_4 != '\0') {
    ovr_stop_audio();
    DAT_2410_07a6 = 0x54;
    ovr_play_sfx(84,0);
    ovr_OVC38_68ac_03fc();
    ovr_miceRestoreArea(BlitRects + 1);
    ovr_stats_6386_00f8();
    ovr_say("Your may continue playing, but your score will not be recorded.");
    ovr_OVC38_68ac_0148();
    ovr_OVC28_6018_0251();
    ovr_OVC41_6a8f_18c6();
    ovr_miceBlitRect(BlitRects + 1);
    ovr_stop_audio();
    uVar7 = 0x24;
    DAT_2410_07a6 = 0xff;
  }
  return CONCAT11(uVar7,1);
}



/* 67e7:026a */

undefined2 __cdecl16far season_67e7_026a(byte param_1)

{
  byte bVar1;
  int iVar2;
  undefined2 uVar3;
  
  if (*(char *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3f) == '\0') {
    uVar3 = 0;
  }
  else {
    iVar2 = (uint)*(byte *)((int)*(undefined4 *)((uint)param_1 << 2) + 0x3e) * 0x95;
    bVar1 = ovr_OVC30_619c_031d(CONCAT11((char)((uint)iVar2 >> 8),
                                         *(undefined1 *)
                                          ((int)&far_t_ARRAY_2410_26f7[0xc].seg + iVar2)));
    if (bVar1 < 2) {
      if (((undefined *)&DAT_2000_d3cd)[bVar1] != '\0') {
        return 0;
      }
      ((undefined *)&DAT_2000_d3cd)[bVar1] = 1;
    }
    uVar3 = season_67e7_004d(0);
  }
  return uVar3;
}



/* 67e7:030a */

void __cdecl16far season_67e7_030a(void)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined2 uVar6;
  uint uStack_6;
  
  DAT_2000_d3ca = 0;
  for (uStack_6 = 0xf8; uStack_6 < DAT_2000_ca99; uStack_6 = uStack_6 + 1) {
    uVar6 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
    iVar3 = (int)DAT_2000_ca95;
    bVar1 = *(byte *)(iVar3 + uStack_6 * 9 + 2);
    if ((((*(uint *)((uint)*(byte *)(iVar3 + uStack_6 * 9) * 0x27 + 0x121) & 0x60) == 0) &&
        (bVar1 != 0xff)) &&
       (uVar2 = *(undefined4 *)((uint)bVar1 << 2), *(char *)((int)uVar2 + 0x3f) == '\0')) {
      iVar3 = ovr_OVC23_55fe_3450(*(undefined2 *)(iVar3 + uStack_6 * 9 + 4));
      uVar5 = 0;
      for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
        uVar5 = uVar5 | *(uint *)((int)DAT_2000_cb09 +
                                  *(int *)((int)DAT_2000_ca95 + uStack_6 * 9 + 6) * 0x128 +
                                  (iVar3 + iVar4) * 2 + -4) & 0x3000;
      }
      if (uVar5 == 0x1000) {
        DAT_2000_d3ca = DAT_2000_d3ca + 1;
      }
    }
  }
  return;
}



/* 67e7:042b */

void __cdecl16far season_67e7_042b(void)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  
  season_67e7_030a();
  bVar1 = ovr_manage_4d05_1b1d();
  if ((bVar1 != 0xff) && (*(byte *)((int)*(undefined4 *)((uint)bVar1 << 2) + 0x86) < 9)) {
    uVar3 = ovr_manage_4d05_044e();
    bVar1 = season_67e7_04e5();
    if (bVar1 <= uVar3) {
      uVar3 = season_67e7_048f();
      if (uVar3 <= DAT_2000_d3ca) {
        cVar2 = season_67e7_004d(1);
        if (cVar2 != '\0') {
          DAT_2000_d3cc = DAT_2000_d3cc + '\x01';
        }
      }
    }
  }
  return;
}



/* 67e7:048f */

int __cdecl16far season_67e7_048f(void)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = ovr_manage_4d05_1b1d();
  if (bVar1 == 0xff) {
    iVar2 = 0;
  }
  else {
    iVar2 = DAT_2000_d3ca;
    if (*(byte *)(*(int *)((uint)bVar1 * 4) + 0x86) < 9) {
      iVar2 = (uint)DAT_2000_d3cc * 0x32 + 0x32;
    }
  }
  return iVar2;
}



/* 67e7:04e5 */

char __cdecl16far season_67e7_04e5(void)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  char cVar4;
  
  bVar3 = ovr_manage_4d05_1b1d();
  if (bVar3 == 0xff) {
    cVar4 = 'd';
  }
  else {
    iVar1 = ((int *)((uint)bVar3 * 4))[1];
    iVar2 = *(int *)((uint)bVar3 * 4);
    if (*(byte *)(iVar2 + 0x86) < 9) {
      if (DAT_2000_d19d == '\x01') {
        if (*(byte *)(iVar2 + 0x86) < 5) {
          cVar4 = *(char *)(iVar2 + 0x86) * '\x02' + '5';
        }
        else {
          cVar4 = *(char *)(iVar2 + 0x86) + '9';
        }
      }
      else if (DAT_2000_d19d == '\x02') {
        cVar4 = *(char *)(iVar2 + 0x86) * '\x02' + '5';
      }
      else {
        cVar4 = *(char *)(iVar2 + 0x86) * '\x03' + '4';
      }
    }
    else {
      cVar4 = 'd';
    }
  }
  return cVar4;
}



/* 67e7:058d */

uint16_t __cdecl16far
calcSeasonPalette(uint8_t *param_1,undefined2 param_2,uint8_t *param_3,undefined2 param_4)

{
  far_t handle;
  uint8_t local_a0 [136];
  uint16_t uStack_18;
  uint16_t uStack_16;
  byte bStack_13;
  uint8_t local_12 [4];
  uint8_t local_e [4];
  uint8_t local_a [4];
  stg_tmp_t *psStack_6;
  
  F_SCOPY(local_a0,(uint8_t *)&DAT_2410_693b,0x87);
  F_SCOPY(local_a,(uint8_t *)&DAT_2410_69c2,3);
  F_SCOPY(local_e,(uint8_t *)&DAT_2410_69c5,3);
  F_SCOPY(local_12,(uint8_t *)&DAT_2410_69c8,3);
  _fmemmove(param_3,param_1,0x300);
  uStack_16 = ((undefined2 *)&DAT_2000_d026)[((uint)DAT_2410_0744 + (uint)GSeason) * 2];
  uStack_18 = ((undefined2 *)&DAT_2000_d024)[((uint)DAT_2410_0744 + (uint)GSeason) * 2];
  handle.seg = uStack_16;
  handle.ofs = uStack_18;
  psStack_6 = ovr_stshLoadGfx(handle);
  _fmemmove(param_3 + 0x1e0,((stg_tmp_t *)psStack_6)->cmap,0x90);
  _fmemmove(param_3 + 0x2d0,local_a0 + (uint)GSeason * 0x2d,0x2d);
  if (GameRunning == false) {
    _fmemmove(param_3 + 0x2ac,local_a,3);
    _fmemmove(param_3 + 0x2af,local_a,3);
    _fmemmove(param_3 + 0x2b2,local_e,3);
    _fmemmove(param_3 + 0x2b5,local_e,3);
    _fmemmove(param_3 + 0x2be,local_12,3);
  }
  for (bStack_13 = 0; bStack_13 < 0x2d; bStack_13 = bStack_13 + 1) {
    param_3[bStack_13 + 0x2d0] = (uint8_t)((int)(uint)param_3[bStack_13 + 0x2d0] >> 2);
  }
  return uStack_18;
}



/* 67e7:073e */

void __cdecl16far updSeason(void)

{
  far_t handle;
  far_t handle_00;
  undefined2 unaff_SS;
  char *msg;
  stg_tmp_t *psVar1;
  uint16_t dst;
  undefined1 palette [768];
  uint8_t snames [12];
  char local_5a [81];
  byte seaon2;
  stg_tmp_t *psStack_8;
  byte s;
  byte season;
  
  F_SCOPY(snames,(uint8_t *)(far_t *)GSeasonNames,0xc);
  seaon2 = GSeason;
  season = GSeason;
  GTimeLo = GTimeLo + 1;
  if (((GTimeHi != '\0') && (GSeason == 0)) && (GTimeLo < 0xf)) {
    GTimeLo = 0xf;
    GTimeHi = '\0';
  }
  if (GSeason == 0) {
    if ((GTimeHi != '\0') || (0x1d < GTimeLo)) {
      season = 1;
      GTimeLo = 0;
    }
  }
  else if ((GTimeHi != '\0') || (0xe < GTimeLo)) {
    season = GSeason + 1;
    GTimeLo = 0;
  }
  if (2 < season) {
    season = 0;
  }
  if ((GSeason != season) || ((season == 0 && (GTimeLo == 0xf)))) {
    if ((season == 0) && (GTimeLo == 0)) {
      DAT_2000_d2e4 = DAT_2000_d2e4 + 1;
    }
    handle.seg = Lbm_nwpanel1.seg;
    handle.ofs = Lbm_nwpanel1.ofs;
    psStack_8 = ovr_stshLoadGfx(handle);
    calcSeasonPalette();
    ovr_OVC40_69c8_011e(palette);
    ovr_miceRestoreArea(BlitRects + 1);
    GSeason = season;
    ovr_OVC41_6a8f_11d2(0);
    ovr_miceBlitRect(BlitRects + 1);
    if ((season == 0) && (GTimeLo == 0xf)) {
      ovr_uiNotify("The season has changed to summer.",0xa000);
    }
    else {
      dst = 0xa000;
      msg = ovr_stsprintf(local_5a,"The season has changed to %s.",
                          *(char **)(snames + (uint)season * 4));
      ovr_uiNotify(msg,dst);
    }
    handle_00.seg = Lbm_nwpanel1.seg;
    handle_00.ofs = Lbm_nwpanel1.ofs;
    psVar1 = ovr_stshLoadGfx(handle_00);
    psStack_8 = psVar1;
    calcSeasonPalette();
    ovr_setSeasonPalette(palette);
    GTimeHi = '\0';
    if ((season == 0) && (GTimeLo == 0xf)) {
      s = 1;
    }
    else if (season == 0) {
      s = 0;
    }
    else {
      s = season + 1;
    }
    season_67e7_0a5c(s);
    if (DAT_2000_d2e6 < 100) {
      if (DAT_2000_d19d == '\x01') {
        if (s == 0) {
          DAT_2000_d2e6 = DAT_2000_d2e6 + 1;
        }
      }
      else if (DAT_2000_d19d == '\x03') {
        DAT_2000_d2e6 = DAT_2000_d2e6 + 1;
      }
      else if ((s & 1) != 0) {
        DAT_2000_d2e6 = DAT_2000_d2e6 + 1;
      }
    }
  }
  return;
}



/* 67e7:09b9 */

int __cdecl16far season_67e7_09b9(int param_1,byte param_2)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  
  iVar1 = ovr_OVC23_55fe_3450(*(undefined2 *)((int)DAT_2000_ca95 + param_1 * 9 + 4));
  uVar5 = 0;
  for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
    uVar5 = uVar5 | *(uint *)((int)DAT_2000_cb09 +
                              *(int *)((int)DAT_2000_ca95 + param_1 * 9 + 6) * 0x128 +
                              (iVar1 + iVar4) * 2 + -4) & 0x3000;
  }
  uVar2 = 0x1000 << (*(byte *)((int)*(undefined4 *)((uint)param_2 << 2) + 0x3f) & 0x1f);
  bVar3 = (byte)(uVar2 >> 8);
  if (uVar2 == uVar5) {
    iVar1 = CONCAT11(bVar3,1);
  }
  else {
    iVar1 = (uint)bVar3 << 8;
  }
  return iVar1;
}



/* 67e7:0a5c */

void __cdecl16far season_67e7_0a5c(byte param_1)

{
  char cVar1;
  uint uVar2;
  char *arg1;
  undefined2 uVar3;
  undefined2 unaff_SS;
  char *msg;
  uint16_t dst;
  char local_80 [121];
  byte bStack_7;
  undefined2 local_6;
  undefined2 uStack_4;
  
  uStack_4 = DAT_2410_69d9;
  local_6 = DAT_2410_69d7;
  arg1 = (char *)0x0;
  for (bStack_7 = 0; bStack_7 < DAT_2000_d1e6; bStack_7 = bStack_7 + 1) {
    if (*(byte *)((int)&local_6 + (uint)param_1) <=
        *(byte *)((int)*(undefined4 *)((uint)bStack_7 << 2) + 0xa5)) {
      for (uVar2 = 0xf8; uVar2 < DAT_2000_ca99; uVar2 = uVar2 + 1) {
        uVar3 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
        if (*(byte *)((int)DAT_2000_ca95 + uVar2 * 9 + 2) == bStack_7) {
          if (*(byte *)((int)DAT_2000_ca95 + uVar2 * 9 + 1) < 8) {
            cVar1 = season_67e7_09b9(uVar2,CONCAT11((char)(uVar2 * 9 >> 8),bStack_7));
            if (cVar1 != '\0') {
              *(undefined1 *)((int)DAT_2000_ca95 + uVar2 * 9 + 1) = 8;
              arg1 = arg1 + 1;
            }
          }
        }
      }
    }
  }
  if (arg1 != (char *)0x0) {
    ovr_inputUpdate(0x24);
    dst = 0xa000;
    ovr_OVC41_6a8f_0000(arg1);
    msg = ovr_stsprintf(local_80,"%d building%s repaired.",arg1);
    ovr_uiNotify(msg,dst);
  }
  return;
}


