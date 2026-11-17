/*
 * ovc42.c - recovered from STRONG.EXE
 * memory block: OVC42
 * range: 6d7a:0000 - 6d7a:243f
 * functions: 12
 */
#include "recovered.h"


/* 6d7a:0000 */

/* WARNING: Removing unreachable block (ram,0x0006d82d) */

char * __cdecl16far OVC42_6d7a_0000(undefined2 param_1,undefined2 param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  uint16_t uVar3;
  char *pcVar4;
  int iVar5;
  ulong uVar6;
  
  uVar1 = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs + 2);
  uVar2 = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
  MiceNeedsUpdate = 1;
  do {
    uVar3 = ovr_biosKeyAvail();
    if ((char)uVar3 != '\0') {
      pcVar4 = (char *)ovr_gameProcessKey();
      if (pcVar4 == (char *)0x11b) {
        return (char *)0x102;
      }
      if (pcVar4 == (char *)"%s: provides housing and income." + 8) {
        return (char *)"%s: provides more housing." + 0x17;
      }
    }
    iVar5 = ovr_init2_3338_0415();
    if ((iVar5 != 0) || (DAT_2000_ccaf != '\0')) {
      if (DAT_2000_ccaf != '\0') {
        return (char *)"woodcarver";
      }
      return (char *)"arena" + 5;
    }
    uVar6 = ovr_attact_3f0b_082f(CONCAT22(uVar1,uVar2));
    if (CONCAT22(param_2,param_1) <= uVar6) {
      return (char *)0x0;
    }
  } while( true );
}



/* 6d7a:009b */

undefined2 __cdecl16far OVC42_6d7a_009b(byte param_1)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  undefined1 uVar4;
  undefined1 extraout_AH;
  ulong uVar5;
  
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs + 2);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
  DAT_2000_ccaf = 0;
  if (MiceNeedsUpdate == '\0') {
    bVar1 = false;
  }
  else {
    ovr_miceBlitRect(BlitRects + 1);
    bVar1 = true;
  }
  do {
    cVar2 = ovr_draw_2e25_1d7c();
  } while (cVar2 != '\0');
  while( true ) {
    if ((*(uint16_t *)(BDA_DailyTimeCounter.ofs + 2) != InputEventTime.hi) ||
       (*(uint16_t *)BDA_DailyTimeCounter != InputEventTime.lo)) {
      InputEventTime.hi = *(uint16_t *)(BDA_DailyTimeCounter.ofs + 2);
      InputEventTime.lo = *(uint16_t *)BDA_DailyTimeCounter;
      ovr_draw_2e25_0938();
    }
    uVar3 = ovr_draw_2e25_1d7c();
    cVar2 = (char)uVar3;
    if (cVar2 != '\0') break;
    uVar5 = ovr_attact_3f0b_082f(CONCAT22((*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)),(undefined2)TextBlitCycle));
    uVar3 = (uint)uVar5;
    if (((int)(uVar5 >> 0x10) != 0) || (param_1 <= uVar3)) break;
  }
  uVar4 = (undefined1)(uVar3 >> 8);
  if (bVar1) {
    ovr_miceRestoreArea(BlitRects + 1);
    uVar4 = extraout_AH;
  }
  return CONCAT11(uVar4,cVar2);
}



/* 6d7a:0190 */

void __cdecl16far OVC42_6d7a_0190(char param_1,int param_2,int param_3)

{
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  
  if ((param_1 != '\0') && (param_1 != '\x03')) {
    OVC42_6d7a_078f();
    ovr_inputUpdate(9);
  }
  if (param_1 != '\x02') {
    if (param_2 == 0 && param_3 == 0) {
      ovr_OVC40_69c8_0317();
    }
    else {
      ovr_OVC40_69c8_011e(param_2);
    }
  }
  ovr_miceRestoreArea(BlitRects + 1);
  ovr_init_3381_0000();
  GameRunning = false;
  gfx.seg = DAT_2000_d1a5;
  gfx.ofs = DAT_2000_d1a3;
  ovr_blitGfxRect(gfx,0,0,BlitRects + 1,0x10,false);
  gfx_00.seg = DAT_2000_d1a1;
  gfx_00.ofs = DAT_2000_d19f;
  ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)(0xa00009af)));
  gfx_01.seg = DAT_2000_caf3;
  gfx_01.ofs = DAT_2000_caf1;
  ovr_blitLoadRleGfx(gfx_01,far_from_u32((uint32_t)(0xa000c51d)));
  DAT_2000_d116 = 0;
  SaveAuto = 0;
  AgntFlag1 = false;
  ovr_init_3381_20ee();
  DAT_2410_07a6 = 0xff;
  CurSfxType3 = 0xff;
  ovr_stop_audio();
  if (param_1 != '\0') {
    ovr_OVC40_69c8_0317();
  }
  return;
}



/* 6d7a:02ab */

void __cdecl16far OVC42_6d7a_02ab(void)

{
  uint16_t uVar1;
  uint uVar2;
  uint16_t uVar3;
  
  for (uVar2 = 0; uVar2 < EntityCount; uVar2 = uVar2 + 1) {
    uVar3 = Entities.seg;
    uVar1 = Entities.ofs;
    if ((*(char *)(uVar1 + uVar2 * 0x37 + 0x1a) != -1) &&
       (*(char *)((int)(char **)GMenuStrings +
                 (uint)*(byte *)(uVar1 + uVar2 * 0x37 + 0xd) * 0x95 + 0x1f) != '\0')) {
      *(undefined2 *)(uVar1 + uVar2 * 0x37) = 0;
      *(undefined2 *)(Entities.ofs + uVar2 * 0x37 + 2) = 0;
    }
  }
  return;
}



/* 6d7a:033e */

void __cdecl16far
OVC42_6d7a_033e(byte param_1,undefined1 param_2,char param_3,uint16_t param_4,uint16_t param_5,
               byte param_6)

{
  int iVar1;
  undefined2 unaff_SS;
  far_t gfx;
  far_t cmap;
  undefined1 local_78 [13];
  byte bStack_6b;
  undefined1 uStack_6a;
  byte bStack_69;
  int iStack_68;
  int iStack_66;
  uint uStack_62;
  undefined1 uStack_5e;
  undefined1 local_40 [23];
  undefined1 *puStack_29;
  brect_t local_c;
  
  ovr_draw_2e25_1662();
  memcpy((uint8_t *)&local_c,(uint8_t *)(brect_t *)(BlitRects + 1),10);
  local_c.h = 150;
  gfx.seg = DAT_2000_cc87;
  gfx.ofs = DAT_2000_cc85;
  ovr_blitGfxRect(gfx,0,0,(brect_t *)CONCAT22(unaff_SS,&local_c),0x10,false);
  _fmemset((undefined1 *)CONCAT22(unaff_SS,local_40),0,0x34);
  _fmemset((undefined1 *)CONCAT22(unaff_SS,local_78),0,0x37);
  puStack_29 = local_78;
  bStack_6b = param_1;
  uStack_6a = 1;
  uStack_5e = param_2;
  if (param_3 != '\0') {
    uStack_62 = uStack_62 | 1;
  }
  if (param_6 == 0) {
    bStack_69 = *(byte *)((int)&far_t_ARRAY_2410_26f7[8].seg + (uint)param_1 * 0x95);
  }
  else {
    bStack_69 = param_6;
  }
  if (*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)param_1 * 0x95) == -1) {
    iStack_66 = *(int *)((uint)bStack_69 * 4 + -2);
    iStack_68 = *(int *)((uint)bStack_69 * 4 + -4);
  }
  else {
    iVar1 = (uint)*(byte *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)param_1 * 0x95) * 0x94 +
            (uint)bStack_69 * 4;
    iStack_66 = *(int *)(iVar1 + -2);
    iStack_68 = *(int *)(iVar1 + -4);
  }
  if (iStack_68 == 0 && iStack_66 == 0) {
    iStack_66 = 0;
    iStack_68 = 100;
  }
  cmap.seg = param_5;
  cmap.ofs = param_4;
  ovr_drawAgntStats((undefined1 *)CONCAT22(unaff_SS,local_40),cmap);
  return;
}



/* 6d7a:04f2 */

/* WARNING: Type propagation algorithm not settling */

void __cdecl16far OVC42_6d7a_04f2(byte param_1)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  uint16_t uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined2 unaff_SS;
  undefined2 uVar8;
  byte local_1c [14];
  uint8_t local_e [8];
  code *pcStack_6;
  code *pcStack_4;
  
  F_SCOPY(local_1c,(uint8_t *)0x7145,0xe);
  F_SCOPY(local_e,(uint8_t *)0x7153,8);
  pcStack_4 = (code *)init_3381_08dc;
  do {
    if (10 < (int)pcStack_4) {
      return;
    }
    for (pcStack_6 = (code *)init_3381_08dc; (int)pcStack_6 < 3; pcStack_6 = pcStack_6 + 1) {
      pcVar2 = pcStack_4 + GfxRndSeed;
      iVar3 = GfxRndSeed2 + (int)pcStack_6;
      if ((-0xb < (int)pcStack_4) || (uVar4 = ovr_randBelow(3), (uVar4 & 0xff) == 0)) {
        if (iVar3 == 0x24) {
          iVar5 = ovr_OVC23_55fe_3450(pcVar2);
          iVar6 = ovr_OVC23_55fe_3450(0x48);
          if (iVar5 == iVar6) goto LAB_6d7a_0627;
        }
        if ((((GfxRndSeed2 != iVar3) || ((int)pcVar2 < GfxRndSeed + -1)) ||
            (GfxRndSeed + 1 < (int)pcVar2)) &&
           (cVar1 = ovr_constr_36ce_306b(pcVar2,iVar3), cVar1 != '\0')) {
          uVar4 = ovr_randBelow(0xe);
          *(uint *)((int)DAT_2000_cb0d + (int)pcVar2 * 0x78 + iVar3 * 2) =
               (uint)local_1c[uVar4 & 0xff];
          uVar4 = ovr_randBelow(5);
          if ((uVar4 & 0xff) == 0) {
            uVar7 = (uint)param_1;
            uVar8 = 1;
            uVar4 = ovr_randBelow(8);
            ovr_OVC15_4207_10a3(pcVar2,iVar3,pcVar2,iVar3,
                                CONCAT11((char)((uint)(local_e + (uVar4 & 0xff)) >> 8),
                                         local_e[uVar4 & 0xff]),uVar8,uVar7);
          }
        }
      }
LAB_6d7a_0627:
    }
    pcStack_4 = pcStack_4 + 1;
  } while( true );
}



/* 6d7a:0643 */

void __cdecl16far OVC42_6d7a_0643(void)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  code *pcVar4;
  code *pcVar5;
  undefined2 uVar6;
  int iStack_a;
  
  for (iStack_a = -10; iStack_a < 0xb; iStack_a = iStack_a + 1) {
    for (pcVar5 = (code *)init_3381_08dc; (int)pcVar5 < 3; pcVar5 = pcVar5 + 1) {
      iVar3 = GfxRndSeed + iStack_a;
      pcVar4 = pcVar5 + GfxRndSeed2;
      cVar2 = ovr_constr_36ce_306b(iVar3,pcVar4);
      if (cVar2 != '\0') {
        uVar6 = (undefined2)((ulong)DAT_2000_cb0d >> 0x10);
        bVar1 = *(byte *)((int)DAT_2000_ca95 +
                         *(int *)((int)DAT_2000_cb0d + iVar3 * 0x78 + (int)pcVar4 * 2) * 9);
        if (*(char *)((uint)bVar1 * 0x27 + 300) != '\0') {
          *(int *)((int)DAT_2000_cb0d + iVar3 * 0x78 + (int)pcVar4 * 2) =
               (uint)bVar1 + (uint)*(byte *)((uint)bVar1 * 0x27 + 300);
        }
      }
    }
  }
  return;
}



/* 6d7a:0736 */

void __cdecl16far OVC42_6d7a_0736(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  
  _fmemmove((uint8_t *)(param_1 + 0x210),(uint8_t *)(param_1 + 0xf0),0xf0);
  for (pbVar2 = (byte *)0x0; pbVar2 < (byte *)0xfa00; pbVar2 = pbVar2 + 1) {
    bVar1 = *pbVar2;
    if ((0x4f < bVar1) && (bVar1 < 0xa0)) {
      *pbVar2 = bVar1 + 0x60;
    }
  }
  return;
}



/* 6d7a:078f */

void __cdecl16far OVC42_6d7a_078f(char *param_1,undefined2 param_2,byte param_3)

{
  far_t gfx;
  far_t handle;
  undefined2 unaff_SS;
  brect_t local_10;
  stg_tmp_t *psStack_6;
  
  F_SCOPY((uint8_t *)&local_10,(uint8_t *)0x715b,10);
  if (param_3 == 0) {
    gfx.seg = DAT_2000_cacf;
    gfx.ofs = DAT_2000_cacd;
    ovr_blitGfx10(gfx,0,0,(brect_t *)CONCAT22(unaff_SS,&local_10),0);
  }
  TextBlitY = (uint)param_3 * 0xd + 0x9e;
  TextBlitX = 0xb;
  (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)DAT_2000_d47e;
  handle.ofs = DAT_2000_d47c;
  (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)DAT_2000_d47e >> 8);
  psStack_6 = ovr_stshLoadGfx(handle);
  TextBlitDstSeg = 0xa000;
  ovr_blitLabel((char *)CONCAT22(param_2,param_1),psStack_6->cmap,319,0xe0);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs + 2);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
  return;
}



/* 6d7a:0850 */

void __cdecl16far OVC42_6d7a_0850(char *param_1,undefined2 param_2,byte param_3)

{
  stg_tmp_t *widths;
  far_t handle;
  
  BlitLetterType = 1;
  TextBlitY = (uint)param_3 * 0xd + 0x9c;
  TextBlitX = 0xb;
  handle.seg = DAT_2000_d47e;
  handle.ofs = DAT_2000_d47c;
  widths = ovr_stshLoadGfx(handle);
  ovr_blitLabel((char *)CONCAT22(param_2,param_1),widths->cmap,319,0xe0);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs + 2);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
  BlitLetterType = 0;
  return;
}



/* 6d7a:08df */

undefined2 __cdecl16far run_demo(void)

{
  byte bVar1;
  undefined2 uVar2;
  uint16_t uVar3;
  int iVar4;
  int iVar5;
  undefined2 unaff_SS;
  stg_tmp_t *psVar6;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t handle;
  far_t handle_00;
  far_t handle_01;
  far_t handle_02;
  far_t handle_03;
  uint8_t local_30c [768];
  stg_tmp_t *psStack_c;
  undefined1 uStack_7;
  byte bStack_6;
  byte bStack_5;
  byte bStack_4;
  byte bStack_3;
  
  srand8(100);
  DAT_2000_ca6f = 0;
  DAT_2000_d19d = 0;
  DAT_2000_d19e = 0;
  GameRunning = true;
  ovr_init_3381_2101();
  GameRunning = false;
  srand8(0xda);
  DAT_2410_5df4 = 0x58;
  DAT_2410_5df6 = 0x24;
  bStack_4 = ovr_OVC30_619c_05a5(10,1,2);
  GfxRndSeed = DAT_2410_5df4;
  GfxRndSeed2 = DAT_2410_5df6;
  strcpy((char *)*(undefined2 *)((uint)bStack_4 * 4),(char *)"Nasher");
  bStack_5 = ovr_OVC30_619c_05a5(10,1,2);
  strcpy((char *)*(undefined2 *)((uint)bStack_5 * 4),(char *)"Fordor");
  bStack_6 = ovr_OVC30_619c_05a5(10,1,2);
  strcpy((char *)*(undefined2 *)((uint)bStack_6 * 4),(char *)"Kaunas");
  OVC42_6d7a_04f2();
  for (iVar5 = -2; iVar5 < 3; iVar5 = iVar5 + 1) {
    for (iVar4 = -1; iVar4 < 1; iVar4 = iVar4 + 1) {
      ovr_OVC18_48ac_0bf4(iVar5 + 0x48,iVar4 + 0x24,0);
    }
  }
  ovr_OVC18_48ac_0bf4(0x49,0x24,0x40);
  ovr_OVC18_48ac_0bf4(0x47,0x23,0x3e);
  ovr_OVC18_48ac_0bf4(0x46,0x23,0x26);
  ovr_OVC18_48ac_0bf4(GfxRndSeed,GfxRndSeed2,0);
  ovr_OVC18_48ac_0bf4(GfxRndSeed + -1,GfxRndSeed2,0x8c);
  ovr_OVC30_619c_05a5(4,1,1);
  bStack_3 = ovr_OVC30_619c_05a5(0x1a,1,1);
  strcpy((char *)*(undefined2 *)((uint)bStack_3 * 4),(char *)"Mindark");
  ovr_OVC15_4207_10a3(0x48,0x24,0x48,0x24,1,1);
  ovr_OVC15_4207_10a3(0x48,0x24,0x48,0x24,2,1);
  ovr_OVC15_4207_10a3(0x48,0x24,0x48,0x24,2,1);
  ovr_OVC15_4207_10a3(0x48,0x24,0x48,0x24,0xb,1);
  ovr_OVC15_4207_10a3(GfxRndSeed + -1,GfxRndSeed2,GfxRndSeed + -1,GfxRndSeed2,10,1);
  ovr_OVC15_4207_10a3(GfxRndSeed + -1,GfxRndSeed2,GfxRndSeed + -1,GfxRndSeed2,8,1);
  ovr_OVC15_4207_10a3(GfxRndSeed + -1,GfxRndSeed2,GfxRndSeed + -1,GfxRndSeed2,3,1);
  ovr_OVC15_4207_10a3(GfxRndSeed + -5,GfxRndSeed2,GfxRndSeed + -1,GfxRndSeed2,10,1);
  ovr_OVC15_4207_10a3(GfxRndSeed + -5,GfxRndSeed2,GfxRndSeed + -1,GfxRndSeed2,1,1);
  ovr_OVC15_4207_10a3(GfxRndSeed + -5,GfxRndSeed2,GfxRndSeed + -1,GfxRndSeed2,0,1);
  GfxRndSeed = GfxRndSeed + -0x10;
  _fmemset((uint8_t *)CONCAT22(unaff_SS,local_30c),0,0x300);
  ovr_vgaSetPalette8bit(local_30c);
  ovr_driver_2d63_05e5(0,0,0x13f,199,0);
  ovr_fmFree();
  ovr_play_sfx(137,0);
  bVar1 = ovr_OVC43_6fbe_0322(DAT_2000_d480,DAT_2000_d482);
  if (bVar1 < 2) {
    bVar1 = OVC42_6d7a_0000(0x48);
    if (bVar1 < 2) {
      ovr_OVC40_69c8_011e(local_30c);
      handle.seg = DAT_2000_d45a;
      handle.ofs = DAT_2000_d458;
      psStack_c = ovr_stshLoadGfx(handle);
      memcpy(local_30c,((stg_tmp_t *)psStack_c)->cmap,0x300);
      ovr_driver_2d63_05e5(0,0,0x13f,199,0);
      gfx.seg = DAT_2000_d476;
      gfx.ofs = DAT_2000_d474;
      ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa0000000)));
      ovr_setSeasonPalette(local_30c);
      bVar1 = OVC42_6d7a_0000(0x48);
      if (bVar1 < 2) {
        ovr_OVC40_69c8_011e(local_30c);
        ovr_fmFree();
        ovr_play_sfx(46,3);
        GameRunning = true;
        ovr_init_3381_0000();
        handle_00.seg = Lbm_nwpanel1.seg;
        handle_00.ofs = Lbm_nwpanel1.ofs;
        psVar6 = ovr_stshLoadGfx(handle_00);
        psStack_c = psVar6;
        ovr_calcSeasonPalette((stg_tmp_t *)psVar6,(int)((ulong)psVar6 >> 0x10),local_30c);
        OVC42_6d7a_0736(local_30c);
        ovr_driver_2d63_05e5(0,0,0x13f,199,0);
        bVar1 = ovr_OVC43_6fbe_035f();
        if (bVar1 < 2) {
          bVar1 = OVC42_6d7a_0000(0x10);
          if (bVar1 < 2) {
            ovr_OVC40_69c8_011e(local_30c);
            ovr_init_3381_0000();
            ovr_OVC28_6018_0251();
            AgntFlag1 = false;
            ovr_OVC41_6a8f_11d2();
            OVC42_6d7a_1f25();
            OVC42_6d7a_078f();
            OVC42_6d7a_078f();
            ovr_OVC40_69c8_0317();
            ovr_miceBlitRect(BlitRects + 1);
            bVar1 = OVC42_6d7a_009b();
            if (bVar1 < 2) {
              ovr_miceRestoreArea(BlitRects + 1);
              GfxRndSeed = GfxRndSeed + 4;
              AgntFlag1 = false;
              ovr_OVC41_6a8f_11d2();
              ovr_miceBlitRect(BlitRects + 1);
              bVar1 = OVC42_6d7a_009b();
              if (bVar1 < 2) {
                ovr_miceRestoreArea(BlitRects + 1);
                GfxRndSeed = GfxRndSeed + 4;
                AgntFlag1 = false;
                ovr_OVC41_6a8f_11d2();
                ovr_miceBlitRect(BlitRects + 1);
                bVar1 = OVC42_6d7a_009b();
                if (bVar1 < 2) {
                  ovr_miceRestoreArea(BlitRects + 1);
                  GfxRndSeed = GfxRndSeed + 4;
                  AgntFlag1 = false;
                  ovr_OVC41_6a8f_11d2();
                  OVC42_6d7a_078f();
                  OVC42_6d7a_078f();
                  OVC42_6d7a_078f();
                  ovr_miceBlitRect(BlitRects + 1);
                  bVar1 = OVC42_6d7a_009b();
                  if (bVar1 < 2) {
                    ovr_miceRestoreArea(BlitRects + 1);
                    GfxRndSeed = GfxRndSeed + 4;
                    AgntFlag1 = false;
                    ovr_OVC41_6a8f_11d2();
                    ovr_miceBlitRect(BlitRects + 1);
                    bVar1 = OVC42_6d7a_009b();
                    if (bVar1 < 2) {
                      ovr_miceRestoreArea(BlitRects + 1);
                      ovr_OVC40_69c8_0317();
                      OVC42_6d7a_078f();
                      OVC42_6d7a_078f();
                      OVC42_6d7a_033e(0,CONCAT11((char)((uint)local_30c >> 8),bStack_4),0);
                      ovr_miceBlitRect(BlitRects + 1);
                      MiceUnkState = 0;
                      (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs + 2);
                      (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
                      uVar3 = ovr_inputUpdate(0x3c);
                      if ((byte)uVar3 < 2) {
                        ovr_miceRestoreArea(BlitRects + 1);
                        ovr_OVC40_69c8_011e(local_30c);
                        OVC42_6d7a_033e(3,CONCAT11((char)((uint)local_30c >> 8),bStack_5),1);
                        ovr_miceBlitRect(BlitRects + 1);
                        (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs + 2);
                        (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
                        uVar3 = ovr_inputUpdate(0x32);
                        if ((byte)uVar3 < 2) {
                          ovr_miceRestoreArea(BlitRects + 1);
                          ovr_OVC40_69c8_011e(local_30c);
                          OVC42_6d7a_033e(8,CONCAT11((char)((uint)local_30c >> 8),bStack_6),1);
                          ovr_miceBlitRect(BlitRects + 1);
                          (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs + 2);
                          (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
                          uVar3 = ovr_inputUpdate(0x32);
                          if ((byte)uVar3 < 2) {
                            ovr_miceRestoreArea(BlitRects + 1);
                            ovr_OVC40_69c8_011e(local_30c);
                            OVC42_6d7a_033e(1,CONCAT11((char)((uint)local_30c >> 8),bStack_6),0);
                            ovr_miceBlitRect(BlitRects + 1);
                            (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs + 2);
                            (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
                            uVar3 = ovr_inputUpdate(0x32);
                            if ((byte)uVar3 < 2) {
                              ovr_miceRestoreArea(BlitRects + 1);
                              ovr_OVC40_69c8_011e(local_30c);
                              OVC42_6d7a_078f();
                              OVC42_6d7a_078f();
                              OVC42_6d7a_078f();
                              OVC42_6d7a_033e(0x15,CONCAT11((char)((uint)local_30c >> 8),bStack_3),1
                                             );
                              ovr_miceBlitRect(BlitRects + 1);
                              (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs + 2);
                              (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
                              uVar3 = ovr_inputUpdate(0x32);
                              if ((byte)uVar3 < 2) {
                                ovr_miceRestoreArea(BlitRects + 1);
                                ovr_OVC40_69c8_011e(local_30c);
                                OVC42_6d7a_033e(0x24,CONCAT11((char)((uint)local_30c >> 8),bStack_3)
                                                ,1);
                                ovr_miceBlitRect(BlitRects + 1);
                                (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs + 2);
                                (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
                                uVar3 = ovr_inputUpdate(0x32);
                                if ((byte)uVar3 < 2) {
                                  ovr_miceRestoreArea(BlitRects + 1);
                                  ovr_OVC40_69c8_011e(local_30c);
                                  OVC42_6d7a_033e(0xe,CONCAT11((char)((uint)local_30c >> 8),bStack_3
                                                              ),1);
                                  ovr_miceBlitRect(BlitRects + 1);
                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) =
                                       *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs + 2);
                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
                                  uVar3 = ovr_inputUpdate(0x32);
                                  if ((byte)uVar3 < 2) {
                                    ovr_miceRestoreArea(BlitRects + 1);
                                    ovr_OVC40_69c8_011e(local_30c);
                                    ovr_OVC28_6018_0251();
                                    GfxRndSeed = 0x68;
                                    GfxRndSeed2 = 0x10;
                                    ovr_OVC18_48ac_0bf4(0x68,0x10,0);
                                    ovr_OVC18_48ac_0bf4(GfxRndSeed + -1,GfxRndSeed2,0x86);
                                    ovr_OVC15_4207_10a3(GfxRndSeed + -2,GfxRndSeed2,GfxRndSeed,
                                                        GfxRndSeed2,0xd,1);
                                    ovr_OVC15_4207_10a3(GfxRndSeed + -2,GfxRndSeed2,GfxRndSeed,
                                                        GfxRndSeed2,0x21,1);
                                    ovr_OVC15_4207_10a3(GfxRndSeed + -2,GfxRndSeed2,GfxRndSeed,
                                                        GfxRndSeed2,0x16,1);
                                    ovr_OVC15_4207_10a3(GfxRndSeed + -2,GfxRndSeed2,GfxRndSeed,
                                                        GfxRndSeed2,7,1);
                                    ovr_OVC15_4207_10a3(GfxRndSeed + 1,GfxRndSeed2,GfxRndSeed,
                                                        GfxRndSeed2,1,1);
                                    ovr_OVC15_4207_10a3(GfxRndSeed + 1,GfxRndSeed2,GfxRndSeed,
                                                        GfxRndSeed2,1,1);
                                    ovr_OVC15_4207_10a3(GfxRndSeed + 1,GfxRndSeed2,GfxRndSeed,
                                                        GfxRndSeed2,0,1);
                                    ovr_OVC15_4207_10a3(GfxRndSeed + 1,GfxRndSeed2,GfxRndSeed,
                                                        GfxRndSeed2,0,1);
                                    ovr_OVC15_4207_10a3(GfxRndSeed + 1,GfxRndSeed2,GfxRndSeed,
                                                        GfxRndSeed2,3,1);
                                    ovr_OVC15_4207_10a3(GfxRndSeed + 1,GfxRndSeed2,GfxRndSeed,
                                                        GfxRndSeed2,5,1);
                                    AgntFlag1 = false;
                                    ovr_OVC41_6a8f_11d2();
                                    OVC42_6d7a_078f();
                                    OVC42_6d7a_078f();
                                    ovr_OVC40_69c8_0317();
                                    bVar1 = OVC42_6d7a_009b();
                                    if (bVar1 < 2) {
                                      ovr_OVC40_69c8_0317();
                                      ovr_miceRestoreArea(BlitRects + 1);
                                      OVC42_6d7a_02ab();
                                      GfxRndSeed = 0x58;
                                      GfxRndSeed2 = 0x24;
                                      AgntFlag1 = false;
                                      ovr_OVC41_6a8f_11d2();
                                      OVC42_6d7a_078f();
                                      OVC42_6d7a_078f();
                                      ovr_OVC40_69c8_0317();
                                      ovr_miceBlitRect(BlitRects + 1);
                                      bVar1 = OVC42_6d7a_009b();
                                      if (bVar1 < 2) {
                                        ovr_miceRestoreArea(BlitRects + 1);
                                        OVC42_6d7a_0643();
                                        OVC42_6d7a_078f();
                                        AgntFlag1 = false;
                                        ovr_OVC41_6a8f_11d2();
                                        ovr_miceBlitRect(BlitRects + 1);
                                        bVar1 = OVC42_6d7a_009b();
                                        if (bVar1 < 2) {
                                          ovr_miceRestoreArea(BlitRects + 1);
                                          OVC42_6d7a_0643();
                                          OVC42_6d7a_078f();
                                          AgntFlag1 = false;
                                          ovr_OVC41_6a8f_11d2();
                                          ovr_miceBlitRect(BlitRects + 1);
                                          bVar1 = OVC42_6d7a_009b();
                                          if (bVar1 < 2) {
                                            ovr_miceRestoreArea(BlitRects + 1);
                                            ovr_OVC40_69c8_0317();
                                            OVC42_6d7a_078f();
                                            OVC42_6d7a_078f();
                                            OVC42_6d7a_033e(0x29,CONCAT11((char)((uint)local_30c >>
                                                                                8),bStack_3),1);
                                            ovr_miceBlitRect(BlitRects + 1);
                                            MiceUnkState = 0;
                                            uVar3 = ovr_inputUpdate(0x78);
                                            if ((byte)uVar3 < 2) {
                                              ovr_miceRestoreArea(BlitRects + 1);
                                              ovr_OVC40_69c8_011e(local_30c);
                                              bVar1 = ovr_OVC40_69c8_04c6(4,(char *)
                                                  "Demo cancelled." + 0xf,(char *)"puppetmaker" + 3,
                                                  (char *)"Demo cancelled." + 0xf,
                                                  (char *)"puppetmaker" + 3);
                                              if (bVar1 < 2) {
                                                ovr_miceRestoreArea(BlitRects + 1);
                                                DAT_2410_5df4 = 0x58;
                                                DAT_2410_5df6 = 0x1e;
                                                uStack_7 = ovr_OVC30_619c_05a5(0xb,1,2);
                                                GfxRndSeed = DAT_2410_5df4;
                                                GfxRndSeed2 = DAT_2410_5df6 + 2;
                                                OVC42_6d7a_04f2();
                                                ovr_OVC18_48ac_0bf4(GfxRndSeed + -1,GfxRndSeed2 + -2
                                                                    ,0);
                                                ovr_OVC18_48ac_0bf4(GfxRndSeed,GfxRndSeed2 + -2,0);
                                                ovr_OVC18_48ac_0bf4(GfxRndSeed + 1,GfxRndSeed2 + -2,
                                                                    0);
                                                ovr_OVC18_48ac_0bf4(GfxRndSeed + -2,GfxRndSeed2 + -2
                                                                    ,0x8b);
                                                AgntFlag1 = false;
                                                ovr_OVC41_6a8f_11d2();
                                                ovr_OVC40_69c8_0317();
                                                OVC42_6d7a_078f();
                                                ovr_miceBlitRect(BlitRects + 1);
                                                bVar1 = OVC42_6d7a_009b();
                                                if (bVar1 < 2) {
                                                  GfxRndSeed2 = GfxRndSeed2 + -1;
                                                  AgntFlag1 = false;
                                                  ovr_OVC41_6a8f_11d2();
                                                  ovr_miceRestoreArea(BlitRects + 1);
                                                  OVC42_6d7a_078f();
                                                  ovr_miceBlitRect(BlitRects + 1);
                                                  bVar1 = OVC42_6d7a_009b();
                                                  if (bVar1 < 2) {
                                                    GfxRndSeed2 = GfxRndSeed2 + -1;
                                                    AgntFlag1 = false;
                                                    ovr_OVC41_6a8f_11d2();
                                                    ovr_miceRestoreArea(BlitRects + 1);
                                                    OVC42_6d7a_078f();
                                                    ovr_miceBlitRect(BlitRects + 1);
                                                    bVar1 = OVC42_6d7a_009b();
                                                    if (bVar1 < 2) {
                                                      ovr_miceRestoreArea(BlitRects + 1);
                                                      ovr_OVC40_69c8_0317();
                                                      ovr_driver_2d63_05e5(0,0,0x13f,199,0);
                                                      ovr_init_3381_1fba();
                                                      bVar1 = ovr_OVC43_6fbe_0322(DAT_2000_d484,
                                                                                  DAT_2000_d486);
                                                      if (bVar1 < 2) {
                                                        (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) =
                                                             *(undefined2 *)
                                                              (BDA_DailyTimeCounter.ofs + 2);
                                                        (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) =
                                                             *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
                                                        bVar1 = OVC42_6d7a_0000(0x30);
                                                        if (bVar1 < 2) {
                                                          ovr_OVC40_69c8_011e(local_30c);
                                                          handle_01.seg = DAT_2000_d442;
                                                          handle_01.ofs = DAT_2000_d440;
                                                          psVar6 = ovr_stshLoadGfx(handle_01);
                                                          psStack_c = psVar6;
                                                          memcpy(local_30c,
                                                                 ((stg_tmp_t *)psVar6)->cmap,0x300);
                                                          ovr_driver_2d63_05e5(0,0,0x13f,199,0);
                                                          gfx_00.seg = DAT_2000_d462;
                                                          gfx_00.ofs = DAT_2000_d460;
                                                          ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)(0xa0000000)));
                                                  ovr_setSeasonPalette(local_30c);
                                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) =
                                                       *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs + 2)
                                                  ;
                                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) =
                                                       *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
                                                  uVar3 = ovr_inputUpdate(0xb4);
                                                  if ((byte)uVar3 < 2) {
                                                    ovr_OVC40_69c8_011e(local_30c);
                                                    handle_02.seg = DAT_2000_d446;
                                                    handle_02.ofs = DAT_2000_d444;
                                                    psVar6 = ovr_stshLoadGfx(handle_02);
                                                    psStack_c = psVar6;
                                                    memcpy(local_30c,((stg_tmp_t *)psVar6)->cmap,
                                                           0x300);
                                                    ovr_driver_2d63_05e5(0,0,0x13f,199,0);
                                                    gfx_01.seg = DAT_2000_d466;
                                                    gfx_01.ofs = DAT_2000_d464;
                                                    ovr_blitLoadRleGfx(gfx_01,far_from_u32((uint32_t)(0xa0000000)));
                                                    ovr_setSeasonPalette(local_30c);
                                                    (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) =
                                                         *(undefined2 *)
                                                          (BDA_DailyTimeCounter.ofs + 2);
                                                    (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) =
                                                         *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
                                                    uVar3 = ovr_inputUpdate(0xb4);
                                                    if ((byte)uVar3 < 2) {
                                                      ovr_OVC40_69c8_011e(local_30c);
                                                      handle_03.seg = DAT_2000_d44a;
                                                      handle_03.ofs = DAT_2000_d448;
                                                      psVar6 = ovr_stshLoadGfx(handle_03);
                                                      psStack_c = psVar6;
                                                      memcpy(local_30c,((stg_tmp_t *)psVar6)->cmap,
                                                             0x300);
                                                      ovr_driver_2d63_05e5(0,0,0x13f,199,0);
                                                      gfx_02.seg = DAT_2000_d46a;
                                                      gfx_02.ofs = DAT_2000_d468;
                                                      ovr_blitLoadRleGfx(gfx_02,far_from_u32((uint32_t)(0xa0000000)));
                                                      ovr_setSeasonPalette(local_30c);
                                                      (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) =
                                                           *(undefined2 *)
                                                            (BDA_DailyTimeCounter.ofs + 2);
                                                      (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) =
                                                           *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
                                                      uVar3 = ovr_inputUpdate(0xb4);
                                                      if ((byte)uVar3 < 2) {
                                                        OVC42_6d7a_0190();
                                                        GameRunning = false;
                                                        DAT_2410_07a6 = 0xff;
                                                        CurSfxType3 = 0xff;
                                                        uVar2 = 0;
                                                      }
                                                      else {
                                                        OVC42_6d7a_0190();
                                                        uVar2 = 1;
                                                      }
                                                    }
                                                    else {
                                                      OVC42_6d7a_0190();
                                                      uVar2 = 1;
                                                    }
                                                  }
                                                  else {
                                                    OVC42_6d7a_0190();
                                                    uVar2 = 1;
                                                  }
                                                  }
                                                  else {
                                                    OVC42_6d7a_0190();
                                                    uVar2 = 1;
                                                  }
                                                  }
                                                  else {
                                                    OVC42_6d7a_0190();
                                                    uVar2 = 1;
                                                  }
                                                  }
                                                  else {
                                                    OVC42_6d7a_0190();
                                                    uVar2 = 1;
                                                  }
                                                  }
                                                  else {
                                                    OVC42_6d7a_0190();
                                                    uVar2 = 1;
                                                  }
                                                }
                                                else {
                                                  OVC42_6d7a_0190();
                                                  uVar2 = 1;
                                                }
                                              }
                                              else {
                                                OVC42_6d7a_0190();
                                                uVar2 = 1;
                                              }
                                            }
                                            else {
                                              OVC42_6d7a_0190();
                                              uVar2 = 1;
                                            }
                                          }
                                          else {
                                            OVC42_6d7a_0190();
                                            uVar2 = 1;
                                          }
                                        }
                                        else {
                                          OVC42_6d7a_0190();
                                          uVar2 = 1;
                                        }
                                      }
                                      else {
                                        OVC42_6d7a_0190();
                                        uVar2 = 1;
                                      }
                                    }
                                    else {
                                      OVC42_6d7a_0190();
                                      uVar2 = 1;
                                    }
                                  }
                                  else {
                                    OVC42_6d7a_0190();
                                    uVar2 = 1;
                                  }
                                }
                                else {
                                  OVC42_6d7a_0190();
                                  uVar2 = 1;
                                }
                              }
                              else {
                                OVC42_6d7a_0190();
                                uVar2 = 1;
                              }
                            }
                            else {
                              OVC42_6d7a_0190();
                              uVar2 = 1;
                            }
                          }
                          else {
                            OVC42_6d7a_0190();
                            uVar2 = 1;
                          }
                        }
                        else {
                          OVC42_6d7a_0190();
                          uVar2 = 1;
                        }
                      }
                      else {
                        OVC42_6d7a_0190();
                        uVar2 = 1;
                      }
                    }
                    else {
                      OVC42_6d7a_0190();
                      uVar2 = 1;
                    }
                  }
                  else {
                    OVC42_6d7a_0190();
                    uVar2 = 1;
                  }
                }
                else {
                  OVC42_6d7a_0190();
                  uVar2 = 1;
                }
              }
              else {
                OVC42_6d7a_0190();
                uVar2 = 1;
              }
            }
            else {
              OVC42_6d7a_0190();
              uVar2 = 1;
            }
          }
          else {
            OVC42_6d7a_0190();
            uVar2 = 1;
          }
        }
        else {
          OVC42_6d7a_0190();
          uVar2 = 1;
        }
      }
      else {
        OVC42_6d7a_0190();
        uVar2 = 1;
      }
    }
    else {
      OVC42_6d7a_0190();
      uVar2 = 1;
    }
  }
  else {
    OVC42_6d7a_0190();
    uVar2 = 1;
  }
  return uVar2;
}



/* 6d7a:1f25 */

void __cdecl16far OVC42_6d7a_1f25(void)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  
  bVar2 = false;
  for (iVar3 = 0; iVar3 < (int)(uint)AgntCount; iVar3 = iVar3 + 1) {
    uVar1 = *(undefined4 *)(iVar3 * 0x34 + 0x1d);
    if (*(char *)((int)uVar1 + 1) == '\x02') {
      if (bVar2) {
        *(undefined2 *)(iVar3 * 0x34) = 0x6e;
        *(undefined2 *)(iVar3 * 0x34 + 2) = 0xb;
      }
      else {
        *(undefined2 *)(iVar3 * 0x34) = 0x2b;
        *(undefined2 *)(iVar3 * 0x34 + 2) = 2;
      }
      bVar2 = true;
    }
    else {
      uVar1 = *(undefined4 *)(iVar3 * 0x34 + 0x1d);
      if (*(char *)((int)uVar1 + 1) == '\x01') {
        *(undefined2 *)(iVar3 * 0x34) = 0x3d;
        *(undefined2 *)(iVar3 * 0x34 + 2) = 0x12;
      }
      else {
        uVar1 = *(undefined4 *)(iVar3 * 0x34 + 0x1d);
        if (*(char *)((int)uVar1 + 1) == '\v') {
          *(undefined2 *)(iVar3 * 0x34) = 0x56;
          *(undefined2 *)(iVar3 * 0x34 + 2) = 0x14;
        }
      }
    }
  }
  ovr_agnt_3b1d_1ad8();
  ovr_agnt_3b1d_1ad8();
  ovr_agnt_3b1d_1ad8();
  ovr_agnt_3b1d_1ad8();
  return;
}


