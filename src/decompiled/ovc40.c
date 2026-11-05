/*
 * ovc40.c - recovered from STRONG.EXE
 * memory block: OVC40
 * range: 69c8:0000 - 69c8:0c6f
 * functions: 8
 */
#include "recovered.h"


/* 69c8:0000 */

void __cdecl16far
OVC40_69c8_0000(char *param_1,int param_2,char *param_3,int param_4,byte param_5,uint8_t param_6)

{
  int iVar1;
  
  TextBlitFlag = 1;
  TextBlitDstSeg = 0xa000;
  if (GameRunning) {
    ovr_OVC42_6d7a_0850();
  }
  else {
    TextBlitX = 0;
    TextBlitY = (uint)param_5 * 0xb + 0x98;
    iVar1 = ovr_font_302d_06ea(param_1,param_2,Font03.ofs,Font03.seg);
    if ((param_3 == (char *)0x0 && param_4 == 0) || (iVar1 < 0x140)) {
      TextBlitX = TextBlitX + (0x140U - iVar1 >> 1);
    }
    else {
      param_2 = param_4;
      param_1 = param_3;
      iVar1 = ovr_font_302d_06ea(param_3,param_4,Font03.ofs,Font03.seg);
      if (iVar1 < 0x140) {
        TextBlitX = TextBlitX + (0x140U - iVar1 >> 1);
      }
    }
    BlitLetterType = 1;
    ovr_blitLabel((char *)CONCAT22(param_2,param_1),(uint8_t *)CONCAT22(Font03.seg,Font03.ofs),319,
                  param_6);
    BlitLetterType = 0;
  }
  return;
}



/* 69c8:011e */

void __cdecl16far OVC40_69c8_011e(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 unaff_SS;
  undefined1 local_306 [768];
  int iStack_6;
  int iStack_4;
  
  iStack_4 = *(int *)(BDA_DailyTimeCounter.ofs + 2);
  iStack_6 = *(int *)BDA_DailyTimeCounter;
  iVar2 = 10;
  do {
    if (iVar2 < 0) {
      return;
    }
    for (iVar1 = 0; iVar1 < 0x300; iVar1 = iVar1 + 1) {
      local_306[iVar1] =
           (char)(((long)(int)(uint)*(byte *)((int)param_1 + iVar1) * (long)iVar2 & 0xffffU) / 10);
    }
    ovr_vgaSetPalette8bit(local_306);
    do {
      if (*(int *)(BDA_DailyTimeCounter.ofs + 2) != iStack_4) break;
    } while (*(int *)BDA_DailyTimeCounter == iStack_6);
    iStack_4 = *(int *)(BDA_DailyTimeCounter.ofs + 2);
    iStack_6 = *(int *)BDA_DailyTimeCounter;
    iVar2 = iVar2 + -1;
  } while( true );
}



/* 69c8:01ac */

void __cdecl16far setSeasonPalette(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  undefined2 unaff_SS;
  undefined1 local_306 [768];
  int iStack_6;
  int iStack_4;
  
  iStack_4 = *(int *)(BDA_DailyTimeCounter.ofs + 2);
  iStack_6 = *(int *)BDA_DailyTimeCounter;
  uVar2 = 0;
  do {
    if (10 < uVar2) {
      return;
    }
    for (uVar1 = 0; uVar1 < 0x300; uVar1 = uVar1 + 1) {
      local_306[uVar1] =
           (char)(((long)(int)(uint)*(byte *)((int)param_1 + uVar1) * (long)(int)uVar2 & 0xffffU) /
                 10);
    }
    ovr_vgaSetPalette8bit(local_306);
    do {
      if (*(int *)(BDA_DailyTimeCounter.ofs + 2) != iStack_4) break;
    } while (*(int *)BDA_DailyTimeCounter == iStack_6);
    iStack_4 = *(int *)(BDA_DailyTimeCounter.ofs + 2);
    iStack_6 = *(int *)BDA_DailyTimeCounter;
    uVar2 = uVar2 + 1;
  } while( true );
}



/* 69c8:023a */

stg_tmp_t * __cdecl16far OVC40_69c8_023a(byte param_1)

{
  uint8_t *puVar1;
  stg_tmp_t *psVar2;
  far_t handle;
  far_t handle_00;
  far_t handle_01;
  far_t handle_02;
  uint8_t local_d6 [171];
  uint8_t local_2b [37];
  stg_tmp_t *psStack_6;
  
  handle.seg = DAT_2000_d3d2;
  handle.ofs = DAT_2000_d3d0;
  psStack_6 = ovr_stshLoadGfx(handle);
  _fmemmove(local_d6,((stg_tmp_t *)psStack_6)->cmap + 0x231,0xcf);
  handle_00.seg = Lbm_nwpanel1.seg;
  handle_00.ofs = Lbm_nwpanel1.ofs;
  psVar2 = ovr_stshLoadGfx(handle_00);
  psStack_6 = psVar2;
  _fmemmove(local_2b,((stg_tmp_t *)psVar2)->cmap + 0x2ac,0xc);
  if (param_1 == 4) {
    handle_01.seg = DAT_2000_d43e;
    handle_01.ofs = DAT_2000_d43c;
    psVar2 = ovr_stshLoadGfx(handle_01);
  }
  else {
    handle_02.seg = ((undefined2 *)&DAT_2000_d3d6)[(uint)param_1 * 2];
    handle_02.ofs = ((undefined2 *)&DAT_2000_d3d4)[(uint)param_1 * 2];
    psVar2 = ovr_stshLoadGfx(handle_02);
  }
  (*(uint16_t *)((uint8_t *)&(psStack_6))) = (stg_tmp_t *)psVar2;
  puVar1 = ((stg_tmp_t *)psStack_6)->cmap;
  psStack_6 = psVar2;
  _fmemmove(puVar1 + 0x231,local_d6,0xcf);
  return (stg_tmp_t *)psStack_6;
}



/* 69c8:0317 */

void __cdecl16far OVC40_69c8_0317(char param_1)

{
  far_t handle;
  undefined1 local_306 [768];
  stg_tmp_t *psStack_6;
  
  handle.seg = Lbm_nwpanel1.seg;
  handle.ofs = Lbm_nwpanel1.ofs;
  psStack_6 = ovr_stshLoadGfx(handle);
  ovr_calcSeasonPalette(psStack_6,local_306);
  if (param_1 == '\0') {
    OVC40_69c8_011e(local_306);
  }
  else {
    setSeasonPalette(local_306);
  }
  return;
}



/* 69c8:0373 */

void __cdecl16far OVC40_69c8_0373(byte param_1,int param_2,brect_t *param_3)

{
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  
  gfx.seg = ((undefined2 *)&DAT_2000_d3ee)[(uint)param_1 * 2];
  gfx.ofs = ((undefined2 *)&DAT_2000_d3ec)[(uint)param_1 * 2];
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)((ulong)((brect_t *)param_3)->seg << 0x10)));
  gfx_00.seg = ((undefined2 *)&DAT_2000_d3fe)[(uint)param_1 * 2];
  gfx_00.ofs = ((undefined2 *)&DAT_2000_d3fc)[(uint)param_1 * 2];
  ovr_blitGfx10(gfx_00,-(param_2 >> 1),0,param_3,0);
  gfx_01.seg = ((undefined2 *)&DAT_2000_d40e)[(uint)param_1 * 2];
  gfx_01.ofs = ((undefined2 *)&DAT_2000_d40c)[(uint)param_1 * 2];
  ovr_blitGfx10(gfx_01,0xdc - (param_2 >> 1),0,param_3,0);
  gfx_02.seg = ((undefined2 *)&DAT_2000_d41e)[(uint)param_1 * 2];
  gfx_02.ofs = ((undefined2 *)&DAT_2000_d41c)[(uint)param_1 * 2];
  ovr_blitGfx10(gfx_02,-param_2,0,param_3,0);
  gfx_03.seg = ((undefined2 *)&DAT_2000_d42e)[(uint)param_1 * 2];
  gfx_03.ofs = ((undefined2 *)&DAT_2000_d42c)[(uint)param_1 * 2];
  ovr_blitGfx10(gfx_03,0x118 - param_2,0,param_3,0);
  ovr_blitRect(param_3);
  return;
}



/* 69c8:047f */

void __cdecl16far OVC40_69c8_047f(void)

{
  uint16_t uVar1;
  bool bStack_3;
  
  do {
    uVar1 = ovr_biosKeyAvail();
    bStack_3 = (char)uVar1 != '\0';
    if (bStack_3) {
      ovr_gameProcessKey();
    }
    uVar1 = ovr_miceButtonsStates();
    bStack_3 = uVar1 != 0 || bStack_3;
  } while (bStack_3);
  DAT_2000_ccaf = 0;
  DAT_2000_ccae = 0;
  return;
}



/* 69c8:04c6 */

char __cdecl16far
OVC40_69c8_04c6(char param_1,char *param_2,undefined2 param_3,char *param_4,undefined2 param_5,
               byte param_6)

{
  char cVar1;
  bool bVar2;
  uint16_t uVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined2 unaff_SS;
  far_t fVar8;
  char *pcVar9;
  char *pcVar10;
  far_t gfx;
  undefined4 uVar11;
  far_t gfx_00;
  far_t gfx_01;
  undefined4 uVar12;
  char local_26c [256];
  char local_16c [256];
  uint8_t local_6c [4];
  char *pcStack_68;
  undefined2 uStack_66;
  undefined2 local_64 [4];
  undefined2 local_5c;
  undefined2 uStack_5a;
  char *pcStack_58;
  undefined2 uStack_56;
  undefined2 local_54 [4];
  undefined2 uStack_4c;
  undefined2 uStack_4a;
  undefined2 uStack_48;
  undefined2 uStack_46;
  undefined2 uStack_44;
  undefined2 uStack_42;
  undefined2 uStack_40;
  undefined2 uStack_3e;
  undefined2 uStack_3c;
  undefined2 uStack_3a;
  undefined2 uStack_38;
  undefined2 uStack_36;
  undefined2 uStack_34;
  undefined2 uStack_32;
  undefined2 uStack_30;
  undefined2 uStack_2e;
  char *pcStack_2c;
  undefined2 uStack_2a;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  undefined2 uStack_22;
  char cStack_1f;
  char cStack_1e;
  char cStack_1d;
  undefined2 uStack_1c;
  uint16_t uStack_1a;
  far_t fStack_18;
  uint8_t local_14 [8];
  uint16_t uStack_c;
  int iStack_a;
  int iStack_8;
  uint local_6;
  uint local_4;
  
  F_SCOPY((uint8_t *)&local_5c,(uint8_t *)(far_t *)far_t_ARRAY_2410_6b3a,0x3c);
  F_SCOPY(local_6c,(uint8_t *)(far_t *)(far_t_ARRAY_2410_6b3a + 0xf),0x10);
  F_SCOPY(local_14,(uint8_t *)0x6b86,10);
  cStack_1d = '\0';
  ovr_stop_audio();
  OVC40_69c8_047f();
  ovr_draw_2e25_1662();
  MiceUnkState = 0;
  fStack_18 = far_from_u32((uint32_t)(ovr_stshAlloc(0xfa0f)));
  fVar8 = ovr_alignToSeg(fStack_18);
  uVar3 = fVar8.seg;
  uStack_c = uVar3;
  if (GameRunning == false) {
    OVC40_69c8_0317();
  }
  MiceNeedsUpdate = 1;
  ovr_driver_2d63_05e5(0,0,0x13f,199,0xec);
  fVar8.seg = DAT_2000_d3ea;
  fVar8.ofs = DAT_2000_d3e8;
  ovr_blitLoadRleGfx(fVar8,far_from_u32((uint32_t)(0xa000b400)));
  if (param_1 == '\x02') {
    cStack_1f = '\x02';
  }
  else {
    cStack_1f = -2;
  }
  if (param_1 == '\x04') {
    gfx.seg = DAT_2000_d45e;
    gfx.ofs = DAT_2000_d45c;
    ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa0000000)));
  }
  else if (cStack_1f < '\0') {
    OVC40_69c8_0373(CONCAT11((char)((uint)local_14 >> 8),param_1),0xef,local_14);
  }
  else {
    OVC40_69c8_0373(CONCAT11((char)((uint)local_14 >> 8),param_1),0,local_14);
  }
  uStack_1c = OVC40_69c8_023a();
  if (param_6 == 4) {
    DAT_2410_07a6 = 0x44;
  }
  else if ((param_6 == 0) || (param_6 == 6)) {
    DAT_2410_07a6 = 0x21;
  }
  else {
    DAT_2410_07a6 = 0x2d;
  }
  uStack_1a = uVar3;
  ovr_play_sfx(CONCAT11(0x24,DAT_2410_07a6),0);
  setSeasonPalette(uStack_1c);
  if (param_6 == 2) {
    OVC40_69c8_0000(uStack_4c,uStack_4a,uStack_4c,uStack_4a,0);
    OVC40_69c8_0000(uStack_48,uStack_46,uStack_48,uStack_46,1);
    OVC40_69c8_0000(uStack_24,uStack_22,uStack_48,uStack_46,2);
  }
  else if (param_6 == 3) {
    OVC40_69c8_0000(uStack_44,uStack_42,uStack_44,uStack_42,0);
    OVC40_69c8_0000(uStack_40,uStack_3e,uStack_40,uStack_3e,1);
    OVC40_69c8_0000(uStack_3c,uStack_3a,uStack_3c,uStack_3a,2);
  }
  else if ((param_6 == 4) || (param_6 == 6)) {
    ovr_OVC15_4207_1c79(local_26c);
    uVar12 = 0xf20001;
    uVar11 = 0;
    pcVar9 = ovr_stsprintf(local_16c,(char *)CONCAT22(uStack_2a,pcStack_2c),local_26c);
    OVC40_69c8_0000((char *)pcVar9,(int)((ulong)pcVar9 >> 0x10),uVar11,uVar12);
  }
  else if (param_6 == 5) {
    ovr_OVC15_4207_1c79(local_26c);
    uVar12 = 0xf20000;
    uVar11 = 0;
    pcVar9 = ovr_stsprintf(local_16c,(char *)CONCAT22(uStack_2a,pcStack_2c),local_26c);
    OVC40_69c8_0000((char *)pcVar9,(int)((ulong)pcVar9 >> 0x10),uVar11,uVar12);
    OVC40_69c8_0000(uStack_28,uStack_26,0,0,1);
  }
  else {
    OVC40_69c8_0000(local_5c,uStack_5a,local_5c,uStack_5a,0);
    uVar11 = 0xf20001;
    pcVar9 = ovr_stsprintf(local_26c,(char *)CONCAT22(uStack_66,pcStack_68),param_2);
    pcVar10 = ovr_stsprintf(local_16c,(char *)CONCAT22(uStack_56,pcStack_58),param_2);
    OVC40_69c8_0000((char *)pcVar10,(int)((ulong)pcVar10 >> 0x10),pcVar9,uVar11);
    uVar11 = 0xf20002;
    pcVar9 = ovr_stsprintf(local_26c,
                           (char *)CONCAT22(local_64[(uint)param_6 * 2 + 1],
                                            (char *)local_64[(uint)param_6 * 2]),param_4);
    pcVar10 = ovr_stsprintf(local_16c,
                            (char *)CONCAT22(local_54[(uint)param_6 * 2 + 1],
                                             (char *)local_54[(uint)param_6 * 2]),param_4);
    OVC40_69c8_0000((char *)pcVar10,(int)((ulong)pcVar10 >> 0x10),pcVar9,uVar11);
  }
  OVC40_69c8_047f();
  ovr_init2_3338_0401();
  iStack_8 = *(int *)(BDA_DailyTimeCounter.ofs + 2);
  iVar6 = *(int *)BDA_DailyTimeCounter;
  if (param_1 == '\x04') {
    iStack_a = iVar6;
    uVar3 = ovr_inputUpdate(0xb4);
    if (1 < (byte)uVar3) {
      cStack_1d = '\x02';
    }
  }
  else {
    if (cStack_1f < '\0') {
      iVar7 = 0xee;
    }
    else {
      iVar7 = 1;
    }
    cStack_1e = 'w';
    while (cVar1 = cStack_1e + -1, bVar2 = cStack_1e != '\0', cStack_1e = cVar1, iStack_a = iVar6,
          bVar2) {
      if ((iVar7 == 100) && (param_6 == 2)) {
        gfx_00.seg = DAT_2000_d3ea;
        gfx_00.ofs = DAT_2000_d3e8;
        ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)(0xa000b400)));
        OVC40_69c8_0000(uStack_38,uStack_36,uStack_38,uStack_36,0);
        OVC40_69c8_0000(uStack_34,uStack_32,uStack_34,uStack_32,1);
        OVC40_69c8_0000(uStack_30,uStack_2e,uStack_30,uStack_2e,2);
      }
      OVC40_69c8_0373(CONCAT11((char)((uint)local_14 >> 8),param_1),iVar7,local_14);
      uVar3 = ovr_biosKeyAvail();
      if ((char)uVar3 != '\0') {
        pcVar4 = (char *)ovr_gameProcessKey();
        if (pcVar4 == (char *)0x11b) {
          cStack_1d = '\x02';
          break;
        }
        if (pcVar4 == (char *)"%s: provides housing and income." + 8) break;
      }
      iVar5 = ovr_init2_3338_0415();
      if (iVar5 != 0) break;
      if (DAT_2000_ccaf != '\0') {
        cStack_1d = '\x02';
        break;
      }
      do {
        ovr_audio_3a5b_0000();
        if (*(int *)(BDA_DailyTimeCounter.ofs + 2) != iStack_8) break;
      } while (*(int *)BDA_DailyTimeCounter == iStack_a);
      iStack_8 = *(int *)(BDA_DailyTimeCounter.ofs + 2);
      iVar6 = *(int *)BDA_DailyTimeCounter;
      iVar7 = iVar7 + cStack_1f;
    }
    if (cStack_1f < '\x01') {
      OVC40_69c8_0373(CONCAT11((char)((uint)local_14 >> 8),param_1),0,local_14);
    }
    else {
      OVC40_69c8_0373(CONCAT11((char)((uint)local_14 >> 8),param_1),0xef,local_14);
    }
    OVC40_69c8_047f();
    DAT_2000_ccaf = '\0';
    if ((param_6 == 2) || (param_6 == 3)) {
      (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
      iVar6 = *(int *)BDA_DailyTimeCounter;
      (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = iVar6;
      if (cStack_1d == '\0') {
        uVar3 = ovr_inputUpdate(0x48);
        cStack_1d = (char)uVar3;
      }
    }
    else {
      gfx_01.seg = far_t_2000_d3e4.seg;
      gfx_01.ofs = far_t_2000_d3e4.ofs;
      ovr_blitLoadRleGfx(gfx_01,far_from_u32((uint32_t)(0xa000e908)));
      MiceProcessed = 0;
      ovr_miceBlitRect(BlitRects + 1);
      do {
        do {
          ovr_audio_3a5b_0000();
          iVar7 = ovr_init2_3338_0388(&local_4);
          if ((((iVar7 != 0) && (0x87 < local_4)) && (0xb9 < local_6)) &&
             ((local_4 < 0xd6 && (local_6 < 0xc6)))) goto LAB_69c8_0af0;
          if (DAT_2000_ccaf != '\0') {
            cStack_1d = '\x02';
            goto LAB_69c8_0af0;
          }
          uVar3 = ovr_biosKeyAvail();
        } while ((char)uVar3 == '\0');
        pcVar4 = (char *)ovr_gameProcessKey();
        if (pcVar4 == (char *)0x11b) {
          cStack_1d = '\x02';
          break;
        }
      } while (pcVar4 != (char *)"%s: provides housing and income." + 8);
    }
  }
LAB_69c8_0af0:
  ovr_miceRestoreArea(BlitRects + 1);
  ovr_init2_3338_043e();
  ovr_stshFree(fStack_18);
  uStack_1c = OVC40_69c8_023a();
  uStack_1a = iVar6;
  OVC40_69c8_011e(uStack_1c);
  ovr_stop_audio();
  DAT_2410_07a6 = 0xff;
  ovr_init_3381_0000();
  if (GameRunning == false) {
    OVC40_69c8_0317();
  }
  ovr_OVC28_6018_0251();
  ovr_OVC41_6a8f_18c6();
  ovr_miceBlitRect(BlitRects + 1);
  return cStack_1d;
}


