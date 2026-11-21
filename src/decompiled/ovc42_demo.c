/*
 * ovc42_demo.c - recovered from STRONG.EXE
 * memory block: OVC42_demo.c
 * range: 6d7a:0000 - 6d7a:243f
 * functions: 12
 */
#include "recovered.h"


/* 6d7a:0000 */

/* [R2] string "%s: provides more housing." */

char * __cdecl16far ovc42_textProvidesMoreHousing(uint32_t timeoutTicks)

{
  ulong *__return_storage_ptr__;
  uint16_t uVar1;
  uint uVar2;
  ulong *puVar3;
  uint uVar4;
  undefined2 unaff_SI;
  ulong prevTick;
  
  __return_storage_ptr__ = (ulong *)*(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
  uVar4 = *(uint *)BDA_DailyTimeCounter;
  prevTick = CONCAT22(uVar4,unaff_SI);
  MiceNeedsUpdate = 1;
  do {
    uVar1 = ovr_biosKeyAvail();
    if ((char)uVar1 != '\0') {
      uVar1 = ovr_gameProcessKey();
      if (uVar1 == 0x11b) {
        return (char *)((int)&GUnitDescriptions[5].seg + 1);
      }
      if (uVar1 == 0x1c0d) {
        return (char *)"%s: provides more housing." + 0x17;
      }
    }
    uVar2 = ovr_init2_updateMouseButtons();
    if ((uVar2 != 0) || (rightButtonLatch != '\0')) {
      if (rightButtonLatch != '\0') {
        return (char *)"woodcarver";
      }
      return (char *)"arena" + 5;
    }
    puVar3 = ovr_attact_usesBDADailyTimeCounter
                       (__return_storage_ptr__,prevTick,(int)(prevTick >> 0x10));
  } while ((uVar4 < (*(uint16_t *)((uint8_t *)&(timeoutTicks) + 2))) ||
          ((uVar4 == (*(uint16_t *)((uint8_t *)&(timeoutTicks) + 2)) && (puVar3 < (ulong *)timeoutTicks))));
  return (char *)((uint)puVar3 & 0xff00);
}



/* 6d7a:009b */

/* [R4] calls ovr_miceBlitRect */

undefined2 __cdecl16far ovc42_usesMiceBlitRect(byte timeoutTicks)

{
  bool bVar1;
  undefined1 uVar2;
  undefined1 extraout_AH;
  ulong *puVar3;
  undefined1 uVar4;
  uint16_t uVar5;
  undefined2 unaff_BP;
  undefined1 in_stack_0000fffc;
  undefined1 in_stack_0000fffd;
  char cVar6;
  
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = (ulong *)*(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter;
  rightButtonLatch = 0;
  if (MiceNeedsUpdate == '\0') {
    cVar6 = '\0';
  }
  else {
    ovr_miceBlitRect((brect_t *)CONCAT13(in_stack_0000fffd,CONCAT12(in_stack_0000fffc,0x2410)),0x44a
                    );
    cVar6 = '\x01';
  }
  do {
    bVar1 = ovr_draw_textProvidesMoreHousing();
  } while (bVar1);
  while( true ) {
    uVar5 = *(uint16_t *)BDA_DailyTimeCounter;
    if ((*(uint16_t *)(BDA_DailyTimeCounter.ofs + 2) != InputEventTime.hi) ||
       (uVar5 != InputEventTime.lo)) {
      InputEventTime.hi = *(uint16_t *)(BDA_DailyTimeCounter.ofs + 2);
      uVar5 = *(uint16_t *)BDA_DailyTimeCounter;
      InputEventTime.lo = uVar5;
      ovr_draw_usesPrintf();
    }
    uVar2 = ovr_draw_textProvidesMoreHousing();
    puVar3 = (ulong *)CONCAT11(extraout_AH,uVar2);
    if ((bool)uVar2) break;
    puVar3 = ovr_attact_usesBDADailyTimeCounter
                       ((*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)),(ulong)CONCAT21(unaff_BP,cVar6) << 8,
                        (undefined2)TextBlitCycle,0);
    if ((uVar5 != 0) || ((ulong *)(uint)timeoutTicks <= puVar3)) break;
  }
  uVar4 = (undefined1)((uint)puVar3 >> 8);
  if (cVar6 != '\0') {
    ovr_miceRestoreArea((brect_t *)CONCAT13(cVar6,CONCAT12(uVar2,0x2410)),0x44a);
  }
  return CONCAT11(uVar4,uVar2);
}



/* 6d7a:0190 */

/* Ends the demo: reports cancellation, restores the palette and mouse, clears GameRunning and
   restores the menu graphics. */

void __cdecl16far ovc42_endDemo(char exitCode,int paletteOfs,int paletteSeg)

{
  uint16_t unaff_BP;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  char useVgaPalette;
  far_t dst;
  far_t dst_00;
  
  if ((exitCode != '\0') && (exitCode != '\x03')) {
    ovc42_drawTextRow("Demo cancelled.",0);
    ovr_inputUpdate();
  }
  if (exitCode != '\x02') {
    if (paletteOfs == 0 && paletteSeg == 0) {
      ovr_ovc40_usesCalcSeasonPalette((char)unaff_BP,0);
    }
    else {
      ovr_ovc40_usesVgaSetPalette8bit();
    }
  }
  ovr_miceRestoreArea();
  ovr_init_usesBlitGfxRect();
  GameRunning = false;
  gfx.seg = 0;
  gfx.ofs = nwpanel2Cut1Seg;
  ovr_blitGfxRect(gfx,0,1098,(brect_t *)0x102410,0x0,SUB21(unaff_BP,0),nwpanel2Cut1Ofs);
  dst.seg = unaff_BP;
  dst.ofs = 0xa000;
  gfx_00.seg = 0x9af;
  gfx_00.ofs = GMenuGfxSeg;
  ovr_blitLoadRleGfx(gfx_00,dst,GMenuGfxOfs);
  dst_00.seg = dst.seg;
  dst_00.ofs = 0xa000;
  gfx_01.seg = 0xc51d;
  gfx_01.ofs = panel01Cut3Seg;
  ovr_blitLoadRleGfx(gfx_01,dst_00,panel01Cut3Ofs);
  mapViewActive = 0;
  SaveAuto = 0;
  AgntFlag1 = false;
  useVgaPalette = (char)dst_00.seg;
  ovr_freeGameResources();
  CurMusicType = 0xff;
  CurSfxType3 = 0xff;
  ovr_stop_audio();
  if (exitCode != '\0') {
    ovr_ovc40_usesCalcSeasonPalette(useVgaPalette,1);
  }
  return;
}



/* 6d7a:02ab */

/* [R6] touches EntityCount, Entities */

void __cdecl16far ovc42_usesEntityCount(void)

{
  entity_t *peVar1;
  uint uVar2;
  undefined2 uVar3;
  
  for (uVar2 = 0; uVar2 < EntityCount; uVar2 = uVar2 + 1) {
    uVar3 = (undefined2)((ulong)Entities >> 0x10);
    peVar1 = (entity_t *)Entities;
    if ((*(char *)((int)&peVar1[uVar2].base.entity + 3) != -1) &&
       (*(char *)((int)(char **)GMenuStrings + (uint)peVar1[uVar2].base.gindex * 0x95 + 0x1f) !=
        '\0')) {
      ((peVar1 + uVar2)->base).x = 0;
      ((entity_t *)Entities)[uVar2].base.y = 0;
    }
  }
  return;
}



/* 6d7a:033e */

/* WARNING: Variable defined which should be unmapped: agntRec */
/* Builds a temporary agent record and draws its stats page with the given palette. */

void __cdecl16far
ovc42_showAgentStats(byte gindex,uint8_t partyIndex,char flag,far_t cmap,byte level)

{
  uint16_t count;
  brect_t *unaff_SS;
  far_t gfx;
  undefined4 uStack_7a;
  agnt_t agntRec;
  uint8_t agntTmp;
  uint8_t rect;
  undefined2 uStack_6;
  
  count = agntRec.x;
  ovr_draw_freeRingBuffers();
  memcpy((char *)CONCAT22(unaff_SS,&rect),(char *)(BlitRects + 1),10);
  uStack_6 = 0x96;
  gfx.seg = 0;
  gfx.ofs = talkwin9Cut1Seg;
  ovr_blitGfxRect(gfx,0,(int16_t)&rect,(brect_t *)CONCAT22(0x10,unaff_SS),0x0,(*(uint8_t *)((uint8_t *)&(agntRec.x))),
                  talkwin9Cut1Ofs);
  _fmemset((void *)ZEXT24(unaff_SS),0x34,count);
  _fmemset((void *)ZEXT24(unaff_SS),0x37,count);
  ovr_drawAgntStats();
  return;
}



/* 6d7a:04f2 */

/* Fills the area around the cursor with random unit types and spawns the matching agents. */

void __cdecl16far ovc42_populateArea(byte partyIndex)

{
  uint16_t y;
  uint16_t x;
  uint16_t uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 unaff_DI;
  uint16_t unaff_SS;
  far_t dst;
  far_t dst_00;
  undefined4 uVar4;
  uint8_t unitTypeMap;
  uint8_t spawnGindexMap;
  int iStack_6;
  int iStack_4;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&unitTypeMap;
  F_SCOPY(far_from_u32((uint32_t)(0x24107145)),dst);
  dst_00.seg = unaff_SS;
  dst_00.ofs = (uint16_t)&spawnGindexMap;
  F_SCOPY(far_from_u32((uint32_t)(0x24107153)),dst_00);
  iStack_4 = -0x14;
  do {
    if (10 < iStack_4) {
      return;
    }
    for (iStack_6 = -0x14; iStack_6 < 3; iStack_6 = iStack_6 + 1) {
      y = GfxRndSeed + iStack_4;
      x = GfxRndSeed2 + iStack_6;
      if ((-0xb < iStack_4) || (uVar1 = ovr_randBelow(), (uVar1 & 0xff) == 0)) {
        if (x == 0x24) {
          uVar2 = ovr_alignUp4();
          uVar3 = ovr_alignUp4();
          if (uVar2 == uVar3) goto L_OVC42_6d7a_04f2_0627;
        }
        if ((((GfxRndSeed2 != x) || ((int)y < GfxRndSeed + -1)) || (GfxRndSeed + 1 < (int)y)) &&
           (uVar2 = ovr_constr_usesGMapFlags(), (char)uVar2 != '\0')) {
          uVar1 = ovr_randBelow();
          (*(short (*) [148] [60])GUnitGrid)[y][x] = (uint)(&unitTypeMap)[uVar1 & 0xff];
          uVar1 = ovr_randBelow();
          if ((uVar1 & 0xff) == 0) {
            uVar4 = CONCAT22((uint)partyIndex,1);
            uVar1 = ovr_randBelow();
            ovr_ovc15_usesLDIV_at_
                      (x,y,x,CONCAT11((char)((uint)(&spawnGindexMap + (uVar1 & 0xff)) >> 8),
                                      (&spawnGindexMap)[uVar1 & 0xff]),(byte)uVar4,
                       (uint8_t)((ulong)uVar4 >> 0x10),(byte)unaff_DI,y);
          }
        }
      }
L_OVC42_6d7a_04f2_0627:
    }
    iStack_4 = iStack_4 + 1;
  } while( true );
}



/* 6d7a:0643 */

/* [R6] touches GfxRndSeed, GfxRndSeed2 */

void __cdecl16far ovc42_usesGfxRndSeed(void)

{
  byte bVar1;
  int iVar2;
  int x;
  uint uVar3;
  int iVar4;
  int unaff_DI;
  undefined2 uVar5;
  int iStack_a;
  
  for (iStack_a = -10; iStack_a < 0xb; iStack_a = iStack_a + 1) {
    for (iVar4 = -0x14; iVar4 < 3; iVar4 = iVar4 + 1) {
      iVar2 = GfxRndSeed + iStack_a;
      x = GfxRndSeed2 + iVar4;
      uVar3 = ovr_constr_usesGMapFlags(x,unaff_DI,iVar2);
      if ((char)uVar3 != '\0') {
        uVar5 = (undefined2)((ulong)GUnitGrid >> 0x10);
        bVar1 = ((unit_t *)GUnits + (*(short (*) [148] [60])GUnitGrid)[iVar2][x])->bldType;
        if (*(char *)((uint)bVar1 * 0x27 + 300) != '\0') {
          (*(short (*) [148] [60])GUnitGrid)[iVar2][x] =
               (uint)bVar1 + (uint)*(byte *)((uint)bVar1 * 0x27 + 300);
        }
      }
    }
  }
  return;
}



/* 6d7a:0736 */

/* [R7] body shape: copy */

void __cdecl16far ovc42_copy1(char *buf)

{
  byte bVar1;
  byte *pbVar2;
  
  _fmemmove((char *)CONCAT22((*(uint16_t *)((uint8_t *)&(buf) + 2)),(char *)buf + 0x210),
            (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(buf) + 2)),(char *)buf + 0xf0),0xf0);
  for (pbVar2 = (byte *)0x0; pbVar2 < (byte *)0xfa00; pbVar2 = pbVar2 + 1) {
    bVar1 = *pbVar2;
    if ((0x4f < bVar1) && (bVar1 < 0xa0)) {
      *pbVar2 = bVar1 + 0x60;
    }
  }
  return;
}



/* 6d7a:078f */

/* WARNING: Variable defined which should be unmapped: dst */
/* Draws one row of text at y = row*0xd + 0x9e in demfont1, with the background at row 0. */

void __cdecl16far ovc42_drawTextRow(char *text,byte row)

{
  far_t gfx;
  far_t dst_00;
  far_t handle;
  uint8_t *puVar1;
  uint unaff_SS;
  uint8_t dst;
  undefined1 uStack_f;
  stg_tmp_t *psStack_6;
  uint8_t *puStack_4;
  
  dst_00.seg = unaff_SS;
  dst_00.ofs = (uint16_t)&dst;
  F_SCOPY(far_from_u32((uint32_t)(0x2410715b)),dst_00);
  if (row == 0) {
    gfx.seg = 0;
    gfx.ofs = fullScreenGfxSeg;
    ovr_blitGfx10(gfx,0,(uint16_t)&dst,(brect_t *)(ulong)unaff_SS,(bool)dst,fullScreenGfxOfs);
  }
  TextBlitY = (uint)row * 0xd + 0x9e;
  puVar1 = (uint8_t *)((char *)"puppetmaker" + 3);
  TextBlitX = 0xb;
  (*(uint8_t *)((uint8_t *)&(handle.seg))) = dst;
  handle.ofs = demfont1FontSeg;
  (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = uStack_f;
  psStack_6 = ovr_stshLoadGfx(handle,demfont1FontOfs);
  TextBlitDstSeg = 0xa000;
  puStack_4 = puVar1;
  ovr_blitLabel((char *)CONCAT22(psStack_6,(*(uint16_t *)((uint8_t *)&(text) + 2))),(uint8_t *)CONCAT22(0x13f,puVar1),224,dst,
                (char *)text);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter;
  return;
}



/* 6d7a:0850 */

/* [R4] calls ovr_blitLabel */

void __cdecl16far ovc42_usesBlitLabel(char *text,byte row,...)

{
  stg_tmp_t *psVar1;
  uint8_t *puVar2;
  undefined2 in_stack_00000004;
  
  BlitLetterType = 1;
  TextBlitY = (uint)(*(uint8_t *)((uint8_t *)&(text) + 2)) * 0xd + 0x9c;
  puVar2 = (uint8_t *)((char *)"puppetmaker" + 3);
  TextBlitX = 0xb;
  psVar1 = ovr_stshLoadGfx();
  ovr_blitLabel((char *)CONCAT22(psVar1,(char *)text),(uint8_t *)CONCAT22(0x13f,puVar2),224,
                (uint8_t)psVar1,in_stack_00000004);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter;
  BlitLetterType = 0;
  return;
}



/* 6d7a:08df */

undefined2 __cdecl16far run_demo(void)

{
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t cmap;
  far_t cmap_00;
  far_t cmap_01;
  far_t cmap_02;
  far_t cmap_03;
  far_t cmap_04;
  far_t cmap_05;
  far_t cmap_06;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t palette_00;
  far_t handle;
  far_t dst;
  far_t palette_01;
  far_t palette_02;
  far_t handle_00;
  far_t palette_03;
  far_t palette_04;
  far_t palette_05;
  far_t palette_06;
  far_t palette_07;
  far_t palette_08;
  far_t palette_09;
  far_t palette_10;
  far_t palette_11;
  far_t palette_12;
  far_t handle_01;
  far_t dst_00;
  far_t palette_13;
  far_t palette_14;
  far_t handle_02;
  far_t dst_01;
  far_t palette_15;
  far_t palette_16;
  far_t handle_03;
  far_t dst_02;
  far_t palette_17;
  byte bVar1;
  char *pcVar2;
  undefined2 uVar3;
  uint16_t uVar4;
  undefined1 extraout_AH;
  undefined1 uVar6;
  uint8_t *puVar5;
  undefined2 uVar7;
  int iVar8;
  undefined2 unaff_DI;
  int iVar9;
  uint unaff_SS;
  undefined1 uVar10;
  undefined1 uVar11;
  byte percent;
  uint8_t palette;
  stg_tmp_t *psStack_c;
  undefined2 uStack_a;
  byte bStack_7;
  byte bStack_6;
  byte bStack_5;
  byte bStack_4;
  byte bStack_3;
  
  percent = (byte)unaff_DI;
  uVar6 = (undefined1)((uint)unaff_DI >> 8);
  srand8(100);
  MenuMode = 0;
  Difficulty = 0;
  worldIndex = 0;
  GameRunning = true;
  ovr_init_usesClearEntities();
  GameRunning = false;
  srand8(0xda);
  demoCenterX = 0x58;
  demoCenterY = 0x24;
  bStack_4 = ovr_ovc30_textDivideError(1,2,'d',percent,10,2,100);
  GfxRndSeed = demoCenterX;
  GfxRndSeed2 = demoCenterY;
  uVar3 = ((undefined2 *)((uint)bStack_4 * 4))[1];
  strcpy((char *)CONCAT13((char)((uint)uVar3 >> 8),
                          CONCAT12((char)uVar3,*(undefined2 *)((uint)bStack_4 * 4))),"Nasher");
  bStack_5 = ovr_ovc30_textDivideError(1,2,'d',percent,10,2,100);
  uVar3 = ((undefined2 *)((uint)bStack_5 * 4))[1];
  strcpy((char *)CONCAT13((char)((uint)uVar3 >> 8),
                          CONCAT12((char)uVar3,*(undefined2 *)((uint)bStack_5 * 4))),"Fordor");
  bStack_6 = ovr_ovc30_textDivideError(1,2,'d',percent,10,2,100);
  uVar3 = ((undefined2 *)((uint)bStack_6 * 4))[1];
  strcpy((char *)CONCAT13((char)((uint)uVar3 >> 8),
                          CONCAT12((char)uVar3,*(undefined2 *)((uint)bStack_6 * 4))),"Kaunas");
  ovc42_populateArea(bStack_4);
  for (iVar9 = -2; iVar9 < 3; iVar9 = iVar9 + 1) {
    for (iVar8 = -1; iVar8 < 1; iVar8 = iVar8 + 1) {
      ovr_ovc18_usesRandBelow(iVar8 + 0x24,0,0xff,percent,(char)(iVar9 + 0x48),0,0xff);
    }
  }
  ovr_ovc18_usesRandBelow(0x24,0x40,0xff,percent,0x49,0x40,0xff);
  ovr_ovc18_usesRandBelow(0x23,0x3e,0xff,percent,0x47,0x3e,0xff);
  ovr_ovc18_usesRandBelow(0x23,0x26,0xff,percent,0x46,0x26,0xff);
  ovr_ovc18_usesRandBelow(GfxRndSeed2,0,0xff,percent,(char)GfxRndSeed,0,0xff);
  ovr_ovc18_usesRandBelow(GfxRndSeed2,0x8c,0xff,percent,(char)(GfxRndSeed - 1),0x8c,0xff);
  ovr_ovc30_textDivideError(1,1,'d',percent,4,1,100);
  bStack_3 = ovr_ovc30_textDivideError(1,1,'d',percent,0x1a,1,100);
  uVar7 = 0x217a;
  uVar3 = ((undefined2 *)((uint)bStack_3 * 4))[1];
  strcpy((char *)CONCAT13((char)((uint)uVar3 >> 8),
                          CONCAT12((char)uVar3,*(undefined2 *)((uint)bStack_3 * 4))),"Mindark");
  ovr_ovc15_usesLDIV_at_(0x24,0x48,0x24,1,1,0x1,percent,0x48,0x48,0x24,1,1,1);
  ovr_ovc15_usesLDIV_at_(0x24,0x48,0x24,2,1,0x1,percent,0x48,0x48,0x24,2,1,1);
  ovr_ovc15_usesLDIV_at_(0x24,0x48,0x24,2,1,0x1,percent,0x48,0x48,0x24,2,1,1);
  ovr_ovc15_usesLDIV_at_(0x24,0x48,0x24,0xb,1,0x1,percent,0x48,0x48,0x24,0xb,1,1);
  ovr_ovc15_usesLDIV_at_
            (GfxRndSeed2,GfxRndSeed - 1,GfxRndSeed2,10,1,0x1,percent,GfxRndSeed - 1,
             (char)(GfxRndSeed - 1),(char)GfxRndSeed2,10,1,1);
  ovr_ovc15_usesLDIV_at_
            (GfxRndSeed2,GfxRndSeed - 1,GfxRndSeed2,8,1,0x1,percent,GfxRndSeed - 1,
             (char)(GfxRndSeed - 1),(char)GfxRndSeed2,8,1,1);
  ovr_ovc15_usesLDIV_at_
            (GfxRndSeed2,GfxRndSeed - 1,GfxRndSeed2,3,1,0x1,percent,GfxRndSeed - 1,
             (char)(GfxRndSeed - 1),(char)GfxRndSeed2,3,1,1);
  ovr_ovc15_usesLDIV_at_
            (GfxRndSeed2,GfxRndSeed - 1,GfxRndSeed2,10,1,0x1,percent,GfxRndSeed - 5,
             (char)(GfxRndSeed - 1),(char)GfxRndSeed2,10,1,1);
  ovr_ovc15_usesLDIV_at_
            (GfxRndSeed2,GfxRndSeed - 1,GfxRndSeed2,1,1,0x1,percent,GfxRndSeed - 5,
             (char)(GfxRndSeed - 1),(char)GfxRndSeed2,1,1,1);
  ovr_ovc15_usesLDIV_at_
            (GfxRndSeed2,GfxRndSeed - 1,GfxRndSeed2,0,1,0x1,percent,GfxRndSeed - 5,
             (char)(GfxRndSeed - 1),(char)GfxRndSeed2,0,1,1);
  GfxRndSeed = GfxRndSeed - 0x10;
  _fmemset((void *)(ulong)unaff_SS,0x300,CONCAT11(uVar6,percent));
  ovr_vgaSetPalette8bit((uint8_t *)CONCAT13(uVar6,CONCAT12(percent,unaff_SS)),(char)&palette);
  ovr_driver_fillRect(0,0x13f,199,0,0x0,0,0x3f,199,0);
  ovr_fmFree();
  ovr_play_sfx(0,0x89);
  bVar1 = 0x10;
  (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)&palette;
  gfx.ofs = l9Cut4Seg;
  (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)((uint)&palette >> 8);
  ovr_ovc43_playArchiveFli(gfx,(char)l9Cut4Ofs);
  if (bVar1 < 2) {
    pcVar2 = ovc42_textProvidesMoreHousing(0x48);
    if ((byte)pcVar2 < 2) {
      (*(uint8_t *)((uint8_t *)&(palette_00.seg))) = percent;
      palette_00.ofs = unaff_SS;
      (*(uint8_t *)((uint8_t *)&(palette_00.seg) + 1)) = uVar6;
      ovr_ovc40_usesVgaSetPalette8bit(palette_00,(char)&palette);
      (*(uint8_t *)((uint8_t *)&(handle.seg))) = percent;
      handle.ofs = ssilogoCut1Seg;
      (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = uVar6;
      psStack_c = ovr_stshLoadGfx(handle,(char)ssilogoCut1Ofs);
      uVar10 = (undefined1)unaff_SS;
      uVar11 = (undefined1)(unaff_SS >> 8);
      uStack_a = uVar7;
      memcpy((char *)CONCAT13(uVar11,CONCAT12(uVar10,&palette)),
             (char *)CONCAT13((char)((uint)uVar7 >> 8),CONCAT12((char)uVar7,psStack_c)),0x300);
      ovr_driver_fillRect(0,0x13f,199,0,0x0,0,0x3f,199,0);
      gfx_01.seg = 0;
      gfx_01.ofs = ssilogoCut2Seg;
      (*(uint8_t *)((uint8_t *)&(dst.seg))) = percent;
      dst.ofs = 0xa000;
      (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = uVar6;
      ovr_blitLoadRleGfx(gfx_01,dst,(char)ssilogoCut2Ofs,0);
      (*(uint8_t *)((uint8_t *)&(palette_01.seg))) = percent;
      palette_01.ofs = unaff_SS;
      (*(uint8_t *)((uint8_t *)&(palette_01.seg) + 1)) = uVar6;
      ovr_setSeasonPalette(palette_01,(char)&palette);
      pcVar2 = ovc42_textProvidesMoreHousing(0x48);
      if ((byte)pcVar2 < 2) {
        (*(uint8_t *)((uint8_t *)&(palette_02.seg))) = percent;
        palette_02.ofs = unaff_SS;
        (*(uint8_t *)((uint8_t *)&(palette_02.seg) + 1)) = uVar6;
        ovr_ovc40_usesVgaSetPalette8bit(palette_02,(char)&palette);
        ovr_fmFree();
        ovr_play_sfx(3,0x2e);
        GameRunning = true;
        ovr_init_usesBlitGfxRect();
        (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = percent;
        handle_00.ofs = Lbm_nwpanel1.seg;
        (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = uVar6;
        psStack_c = ovr_stshLoadGfx(handle_00,(char)Lbm_nwpanel1.ofs);
        uStack_a = uVar7;
        ovr_calcSeasonPalette
                  ((uint8_t *)CONCAT13((char)((uint)&palette >> 8),CONCAT12((char)&palette,uVar7)),
                   (char)psStack_c);
        ovc42_copy1((char *)CONCAT13(uVar11,CONCAT12(uVar10,&palette)));
        ovr_driver_fillRect(0,0x13f,199,0,0x0,0,0x3f,199,0);
        bVar1 = ovr_ovc43_playFli((uint16_t)&palette,0x84);
        if (bVar1 < 2) {
          pcVar2 = ovc42_textProvidesMoreHousing(0x10);
          if ((byte)pcVar2 < 2) {
            (*(uint8_t *)((uint8_t *)&(palette_03.seg))) = percent;
            palette_03.ofs = unaff_SS;
            (*(uint8_t *)((uint8_t *)&(palette_03.seg) + 1)) = uVar6;
            ovr_ovc40_usesVgaSetPalette8bit(palette_03,(char)&palette);
            ovr_init_usesBlitGfxRect();
            ovr_ovc28_textHalflingCastle();
            AgntFlag1 = false;
            ovr_ovc41_usesAgnt_clear(percent,0);
            ovc42_usesAgntCount();
            ovc42_drawTextRow("A new land lies before you. Choose carefully",0);
            ovc42_drawTextRow("where you settle.",1);
            ovr_ovc40_usesCalcSeasonPalette(percent,1);
            ovr_miceBlitRect((brect_t *)CONCAT13(uVar6,CONCAT12(percent,0x2410)),0x4a);
            uVar3 = ovc42_usesMiceBlitRect(0x32);
            if ((byte)uVar3 < 2) {
              ovr_miceRestoreArea((brect_t *)CONCAT13(uVar6,CONCAT12(percent,0x2410)),0x4a);
              GfxRndSeed = GfxRndSeed + 4;
              AgntFlag1 = false;
              ovr_ovc41_usesAgnt_clear(percent,0);
              ovr_miceBlitRect((brect_t *)CONCAT13(uVar6,CONCAT12(percent,0x2410)),0x4a);
              uVar3 = ovc42_usesMiceBlitRect(0x32);
              if ((byte)uVar3 < 2) {
                ovr_miceRestoreArea((brect_t *)CONCAT13(uVar6,CONCAT12(percent,0x2410)),0x4a);
                GfxRndSeed = GfxRndSeed + 4;
                AgntFlag1 = false;
                ovr_ovc41_usesAgnt_clear(percent,0);
                ovr_miceBlitRect((brect_t *)CONCAT13(uVar6,CONCAT12(percent,0x2410)),0x4a);
                uVar3 = ovc42_usesMiceBlitRect(0x32);
                if ((byte)uVar3 < 2) {
                  ovr_miceRestoreArea((brect_t *)CONCAT13(uVar6,CONCAT12(percent,0x2410)),0x4a);
                  GfxRndSeed = GfxRndSeed + 4;
                  AgntFlag1 = false;
                  ovr_ovc41_usesAgnt_clear(percent,0);
                  ovc42_drawTextRow("Your goal: Create a thriving community.",0);
                  ovc42_drawTextRow("Balance building, money, and food production",1);
                  ovc42_drawTextRow("to keep your people happy.",2);
                  ovr_miceBlitRect((brect_t *)CONCAT13(uVar6,CONCAT12(percent,0x2410)),0x4a);
                  uVar3 = ovc42_usesMiceBlitRect(0x32);
                  if ((byte)uVar3 < 2) {
                    ovr_miceRestoreArea((brect_t *)CONCAT13(uVar6,CONCAT12(percent,0x2410)),0x4a);
                    GfxRndSeed = GfxRndSeed + 4;
                    AgntFlag1 = false;
                    ovr_ovc41_usesAgnt_clear(percent,0);
                    ovr_miceBlitRect((brect_t *)CONCAT13(uVar6,CONCAT12(percent,0x2410)),0x4a);
                    uVar3 = ovc42_usesMiceBlitRect(0x4b);
                    if ((byte)uVar3 < 2) {
                      ovr_miceRestoreArea((brect_t *)CONCAT13(uVar6,CONCAT12(percent,0x2410)),0x4a);
                      ovr_ovc40_usesCalcSeasonPalette(percent,0);
                      ovc42_drawTextRow("Your world will be filled with a full range",0);
                      ovc42_drawTextRow("of official D&D@ game characters.",1);
                      (*(uint8_t *)((uint8_t *)&(cmap.seg))) = uVar10;
                      cmap.ofs = (uint16_t)&palette;
                      (*(uint8_t *)((uint8_t *)&(cmap.seg) + 1)) = uVar11;
                      ovc42_showAgentStats(0,bStack_4,'\0',cmap,0);
                      ovr_miceBlitRect((brect_t *)CONCAT13(uVar6,CONCAT12(percent,0x2410)),0x4a);
                      MiceUnkState = 0;
                      (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
                      (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter;
                      uVar4 = ovr_inputUpdate((ulong)CONCAT11(uVar6,percent) << 0x10,0x3c);
                      if ((byte)uVar4 < 2) {
                        ovr_miceRestoreArea((brect_t *)CONCAT13(uVar6,CONCAT12(percent,0x2410)),0x4a
                                           );
                        (*(uint8_t *)((uint8_t *)&(palette_04.seg))) = percent;
                        palette_04.ofs = unaff_SS;
                        (*(uint8_t *)((uint8_t *)&(palette_04.seg) + 1)) = uVar6;
                        ovr_ovc40_usesVgaSetPalette8bit(palette_04,(char)&palette);
                        (*(uint8_t *)((uint8_t *)&(cmap_00.seg))) = uVar10;
                        cmap_00.ofs = (uint16_t)&palette;
                        (*(uint8_t *)((uint8_t *)&(cmap_00.seg) + 1)) = uVar11;
                        ovc42_showAgentStats(3,bStack_5,'\x01',cmap_00,0);
                        ovr_miceBlitRect((brect_t *)CONCAT13(uVar6,CONCAT12(percent,0x2410)),0x4a);
                        (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
                        (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter;
                        uVar4 = ovr_inputUpdate((ulong)CONCAT11(uVar6,percent) << 0x10,0x32);
                        if ((byte)uVar4 < 2) {
                          ovr_miceRestoreArea((brect_t *)CONCAT13(uVar6,CONCAT12(percent,0x2410)),
                                              0x4a);
                          (*(uint8_t *)((uint8_t *)&(palette_05.seg))) = percent;
                          palette_05.ofs = unaff_SS;
                          (*(uint8_t *)((uint8_t *)&(palette_05.seg) + 1)) = uVar6;
                          ovr_ovc40_usesVgaSetPalette8bit(palette_05,(char)&palette);
                          (*(uint8_t *)((uint8_t *)&(cmap_01.seg))) = uVar10;
                          cmap_01.ofs = (uint16_t)&palette;
                          (*(uint8_t *)((uint8_t *)&(cmap_01.seg) + 1)) = uVar11;
                          ovc42_showAgentStats(8,bStack_6,'\x01',cmap_01,0);
                          ovr_miceBlitRect((brect_t *)CONCAT13(uVar6,CONCAT12(percent,0x2410)),0x4a)
                          ;
                          (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
                          (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter;
                          uVar4 = ovr_inputUpdate((ulong)CONCAT11(uVar6,percent) << 0x10,0x32);
                          if ((byte)uVar4 < 2) {
                            ovr_miceRestoreArea((brect_t *)CONCAT13(uVar6,CONCAT12(percent,0x2410)),
                                                0x4a);
                            (*(uint8_t *)((uint8_t *)&(palette_06.seg))) = percent;
                            palette_06.ofs = unaff_SS;
                            (*(uint8_t *)((uint8_t *)&(palette_06.seg) + 1)) = uVar6;
                            ovr_ovc40_usesVgaSetPalette8bit(palette_06,(char)&palette);
                            (*(uint8_t *)((uint8_t *)&(cmap_02.seg))) = uVar10;
                            cmap_02.ofs = (uint16_t)&palette;
                            (*(uint8_t *)((uint8_t *)&(cmap_02.seg) + 1)) = uVar11;
                            ovc42_showAgentStats(1,bStack_6,'\0',cmap_02,0xc);
                            ovr_miceBlitRect((brect_t *)CONCAT13(uVar6,CONCAT12(percent,0x2410)),
                                             0x4a);
                            (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
                            (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter;
                            uVar4 = ovr_inputUpdate((ulong)CONCAT11(uVar6,percent) << 0x10,0x32);
                            if ((byte)uVar4 < 2) {
                              ovr_miceRestoreArea((brect_t *)
                                                  CONCAT13(uVar6,CONCAT12(percent,0x2410)),0x4a);
                              (*(uint8_t *)((uint8_t *)&(palette_07.seg))) = percent;
                              palette_07.ofs = unaff_SS;
                              (*(uint8_t *)((uint8_t *)&(palette_07.seg) + 1)) = uVar6;
                              ovr_ovc40_usesVgaSetPalette8bit(palette_07,(char)&palette);
                              ovc42_drawTextRow("You are not alone in this pristine land.",0);
                              ovc42_drawTextRow("Official D&D@ game monsters will fight to",1);
                              ovc42_drawTextRow("destroy your city.",2);
                              (*(uint8_t *)((uint8_t *)&(cmap_03.seg))) = uVar10;
                              cmap_03.ofs = (uint16_t)&palette;
                              (*(uint8_t *)((uint8_t *)&(cmap_03.seg) + 1)) = uVar11;
                              ovc42_showAgentStats(0x15,bStack_3,'\x01',cmap_03,0);
                              ovr_miceBlitRect((brect_t *)CONCAT13(uVar6,CONCAT12(percent,0x2410)),
                                               0x4a);
                              (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
                              (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter;
                              uVar4 = ovr_inputUpdate((ulong)CONCAT11(uVar6,percent) << 0x10,0x32);
                              if ((byte)uVar4 < 2) {
                                ovr_miceRestoreArea((brect_t *)
                                                    CONCAT13(uVar6,CONCAT12(percent,0x2410)),0x4a);
                                (*(uint8_t *)((uint8_t *)&(palette_08.seg))) = percent;
                                palette_08.ofs = unaff_SS;
                                (*(uint8_t *)((uint8_t *)&(palette_08.seg) + 1)) = uVar6;
                                ovr_ovc40_usesVgaSetPalette8bit(palette_08,(char)&palette);
                                (*(uint8_t *)((uint8_t *)&(cmap_04.seg))) = uVar10;
                                cmap_04.ofs = (uint16_t)&palette;
                                (*(uint8_t *)((uint8_t *)&(cmap_04.seg) + 1)) = uVar11;
                                ovc42_showAgentStats(0x24,bStack_3,'\x01',cmap_04,0);
                                ovr_miceBlitRect((brect_t *)CONCAT13(uVar6,CONCAT12(percent,0x2410))
                                                 ,0x4a);
                                (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
                                (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter;
                                uVar4 = ovr_inputUpdate((ulong)CONCAT11(uVar6,percent) << 0x10,0x32)
                                ;
                                if ((byte)uVar4 < 2) {
                                  ovr_miceRestoreArea((brect_t *)
                                                      CONCAT13(uVar6,CONCAT12(percent,0x2410)),0x4a)
                                  ;
                                  (*(uint8_t *)((uint8_t *)&(palette_09.seg))) = percent;
                                  palette_09.ofs = unaff_SS;
                                  (*(uint8_t *)((uint8_t *)&(palette_09.seg) + 1)) = uVar6;
                                  ovr_ovc40_usesVgaSetPalette8bit(palette_09,(char)&palette);
                                  (*(uint8_t *)((uint8_t *)&(cmap_05.seg))) = uVar10;
                                  cmap_05.ofs = (uint16_t)&palette;
                                  (*(uint8_t *)((uint8_t *)&(cmap_05.seg) + 1)) = uVar11;
                                  ovc42_showAgentStats(0xe,bStack_3,'\x01',cmap_05,0);
                                  ovr_miceBlitRect((brect_t *)
                                                   CONCAT13(uVar6,CONCAT12(percent,0x2410)),0x4a);
                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) =
                                       *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 *)BDA_DailyTimeCounter;
                                  uVar4 = ovr_inputUpdate((ulong)CONCAT11(uVar6,percent) << 0x10,
                                                          0x32);
                                  if ((byte)uVar4 < 2) {
                                    ovr_miceRestoreArea((brect_t *)
                                                        CONCAT13(uVar6,CONCAT12(percent,0x2410)),
                                                        0x4a);
                                    (*(uint8_t *)((uint8_t *)&(palette_10.seg))) = percent;
                                    palette_10.ofs = unaff_SS;
                                    (*(uint8_t *)((uint8_t *)&(palette_10.seg) + 1)) = uVar6;
                                    ovr_ovc40_usesVgaSetPalette8bit(palette_10,(char)&palette);
                                    ovr_ovc28_textHalflingCastle();
                                    GfxRndSeed = 0x68;
                                    GfxRndSeed2 = 0x10;
                                    ovr_ovc18_usesRandBelow(0x10,0,0xff,percent,0x68,0,0xff);
                                    ovr_ovc18_usesRandBelow
                                              (GfxRndSeed2,0x86,0xff,percent,(char)(GfxRndSeed - 1),
                                               0x86,0xff);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed2,GfxRndSeed,GfxRndSeed2,0xd,1,0x1,percent,
                                               GfxRndSeed - 2,(char)GfxRndSeed,(char)GfxRndSeed2,0xd
                                               ,1,1);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed2,GfxRndSeed,GfxRndSeed2,0x21,1,0x1,percent
                                               ,GfxRndSeed - 2,(char)GfxRndSeed,(char)GfxRndSeed2,
                                               0x21,1,1);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed2,GfxRndSeed,GfxRndSeed2,0x16,1,0x1,percent
                                               ,GfxRndSeed - 2,(char)GfxRndSeed,(char)GfxRndSeed2,
                                               0x16,1,1);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed2,GfxRndSeed,GfxRndSeed2,7,1,0x1,percent,
                                               GfxRndSeed - 2,(char)GfxRndSeed,(char)GfxRndSeed2,7,1
                                               ,1);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed2,GfxRndSeed,GfxRndSeed2,1,1,0x1,percent,
                                               GfxRndSeed + 1,(char)GfxRndSeed,(char)GfxRndSeed2,1,1
                                               ,1);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed2,GfxRndSeed,GfxRndSeed2,1,1,0x1,percent,
                                               GfxRndSeed + 1,(char)GfxRndSeed,(char)GfxRndSeed2,1,1
                                               ,1);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed2,GfxRndSeed,GfxRndSeed2,0,1,0x1,percent,
                                               GfxRndSeed + 1,(char)GfxRndSeed,(char)GfxRndSeed2,0,1
                                               ,1);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed2,GfxRndSeed,GfxRndSeed2,0,1,0x1,percent,
                                               GfxRndSeed + 1,(char)GfxRndSeed,(char)GfxRndSeed2,0,1
                                               ,1);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed2,GfxRndSeed,GfxRndSeed2,3,1,0x1,percent,
                                               GfxRndSeed + 1,(char)GfxRndSeed,(char)GfxRndSeed2,3,1
                                               ,1);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed2,GfxRndSeed,GfxRndSeed2,5,1,0x1,percent,
                                               GfxRndSeed + 1,(char)GfxRndSeed,(char)GfxRndSeed2,5,1
                                               ,1);
                                    AgntFlag1 = false;
                                    ovr_ovc41_usesAgnt_clear(percent,0);
                                    ovc42_drawTextRow("Force and fury meet magic spells as battles",
                                                      0);
                                    ovc42_drawTextRow(
                                                  "play out in the courtyards of mighty castles.",1)
                                    ;
                                    ovr_ovc40_usesCalcSeasonPalette(percent,1);
                                    uVar3 = ovc42_usesMiceBlitRect(0xa0);
                                    if ((byte)uVar3 < 2) {
                                      ovr_ovc40_usesCalcSeasonPalette(percent,0);
                                      ovr_miceRestoreArea((brect_t *)
                                                          CONCAT13(uVar6,CONCAT12(percent,0x2410)),
                                                          0x4a);
                                      ovc42_usesEntityCount();
                                      GfxRndSeed = 0x58;
                                      GfxRndSeed2 = 0x24;
                                      AgntFlag1 = false;
                                      ovr_ovc41_usesAgnt_clear(percent,0);
                                      ovc42_drawTextRow("Your people will fight bravely and work",0)
                                      ;
                                      ovc42_drawTextRow("hard. Your city will grow...",1);
                                      ovr_ovc40_usesCalcSeasonPalette(percent,1);
                                      ovr_miceBlitRect((brect_t *)
                                                       CONCAT13(uVar6,CONCAT12(percent,0x2410)),0x4a
                                                      );
                                      uVar3 = ovc42_usesMiceBlitRect(0x32);
                                      if ((byte)uVar3 < 2) {
                                        ovr_miceRestoreArea((brect_t *)
                                                            CONCAT13(uVar6,CONCAT12(percent,0x2410))
                                                            ,0x4a);
                                        ovc42_usesGfxRndSeed();
                                        ovc42_drawTextRow("and grow...",2);
                                        AgntFlag1 = false;
                                        ovr_ovc41_usesAgnt_clear(percent,0);
                                        ovr_miceBlitRect((brect_t *)
                                                         CONCAT13(uVar6,CONCAT12(percent,0x2410)),
                                                         0x4a);
                                        uVar3 = ovc42_usesMiceBlitRect(0x32);
                                        if ((byte)uVar3 < 2) {
                                          ovr_miceRestoreArea((brect_t *)
                                                              CONCAT13(uVar6,CONCAT12(percent,0x2410
                                                                                     )),0x4a);
                                          ovc42_usesGfxRndSeed();
                                          ovc42_drawTextRow("                     and grow...",2);
                                          AgntFlag1 = false;
                                          ovr_ovc41_usesAgnt_clear(percent,0);
                                          ovr_miceBlitRect((brect_t *)
                                                           CONCAT13(uVar6,CONCAT12(percent,0x2410)),
                                                           0x4a);
                                          uVar3 = ovc42_usesMiceBlitRect(100);
                                          if ((byte)uVar3 < 2) {
                                            ovr_miceRestoreArea((brect_t *)
                                                                CONCAT13(uVar6,CONCAT12(percent,
                                                  0x2410)),0x4a);
                                            ovr_ovc40_usesCalcSeasonPalette(percent,0);
                                            ovc42_drawTextRow("But beware the evil Mindark, whose",0
                                                             );
                                            ovc42_drawTextRow(
                                                  "hordes destroyed your homeland long ago.",1);
                                            (*(uint8_t *)((uint8_t *)&(cmap_06.seg))) = uVar10;
                                            cmap_06.ofs = (uint16_t)&palette;
                                            (*(uint8_t *)((uint8_t *)&(cmap_06.seg) + 1)) = uVar11;
                                            ovc42_showAgentStats(0x29,bStack_3,'\x01',cmap_06,0);
                                            ovr_miceBlitRect((brect_t *)
                                                             CONCAT13(uVar6,CONCAT12(percent,0x2410)
                                                                     ),0x4a);
                                            MiceUnkState = 0;
                                            uVar4 = ovr_inputUpdate((ulong)CONCAT11(uVar6,percent)
                                                                    << 0x10,0x78);
                                            if ((byte)uVar4 < 2) {
                                              ovr_miceRestoreArea((brect_t *)
                                                                  CONCAT13(uVar6,CONCAT12(percent,
                                                  0x2410)),0x4a);
                                              (*(uint8_t *)((uint8_t *)&(palette_11.seg))) = percent;
                                              palette_11.ofs = unaff_SS;
                                              (*(uint8_t *)((uint8_t *)&(palette_11.seg) + 1)) = uVar6;
                                              ovr_ovc40_usesVgaSetPalette8bit
                                                        (palette_11,(char)&palette);
                                              bVar1 = ovr_ovc40_usesAlignToSeg
                                                                ('t',(char *)0x71742410,0x2410,
                                                                 (char *)((int)(undefined4 *)&_DATA
                                                                         + 2),4,0x10,0x74,0x10,2);
                                              if (bVar1 < 2) {
                                                ovr_miceRestoreArea((brect_t *)
                                                                    CONCAT13(uVar6,CONCAT12(percent,
                                                  0x2410)),0x4a);
                                                demoCenterX = 0x58;
                                                demoCenterY = 0x1e;
                                                bStack_7 = ovr_ovc30_textDivideError
                                                                     (1,2,'d',percent,0xb,2,100);
                                                GfxRndSeed = demoCenterX;
                                                GfxRndSeed2 = demoCenterY + 2;
                                                ovc42_populateArea(bStack_4);
                                                ovr_ovc18_usesRandBelow
                                                          (GfxRndSeed2 - 2,0,bStack_7,percent,
                                                           (char)(GfxRndSeed - 1),0,bStack_7);
                                                ovr_ovc18_usesRandBelow
                                                          (GfxRndSeed2 - 2,0,bStack_7,percent,
                                                           (char)GfxRndSeed,0,bStack_7);
                                                ovr_ovc18_usesRandBelow
                                                          (GfxRndSeed2 - 2,0,bStack_7,percent,
                                                           (char)(GfxRndSeed + 1),0,bStack_7);
                                                ovr_ovc18_usesRandBelow
                                                          (GfxRndSeed2 - 2,0x8b,bStack_7,percent,
                                                           (char)(GfxRndSeed - 2),0x8b,bStack_7);
                                                AgntFlag1 = false;
                                                ovr_ovc41_usesAgnt_clear(percent,0);
                                                ovr_ovc40_usesCalcSeasonPalette(percent,1);
                                                ovc42_drawTextRow(
                                                  "If you lead with wisdom and cunning...",0);
                                                ovr_miceBlitRect((brect_t *)
                                                                 CONCAT13(uVar6,CONCAT12(percent,
                                                  0x2410)),0x4a);
                                                uVar3 = ovc42_usesMiceBlitRect(0x3c);
                                                if ((byte)uVar3 < 2) {
                                                  GfxRndSeed2 = GfxRndSeed2 - 1;
                                                  AgntFlag1 = false;
                                                  ovr_ovc41_usesAgnt_clear(percent,0);
                                                  ovr_miceRestoreArea((brect_t *)
                                                                      CONCAT13(uVar6,CONCAT12(
                                                  percent,0x2410)),0x4a);
                                                  ovc42_drawTextRow(
                                                  "If you fight with valor and guile...",1);
                                                  ovr_miceBlitRect((brect_t *)
                                                                   CONCAT13(uVar6,CONCAT12(percent,
                                                  0x2410)),0x4a);
                                                  uVar3 = ovc42_usesMiceBlitRect(0x3c);
                                                  if ((byte)uVar3 < 2) {
                                                    GfxRndSeed2 = GfxRndSeed2 - 1;
                                                    AgntFlag1 = false;
                                                    ovr_ovc41_usesAgnt_clear(percent,0);
                                                    ovr_miceRestoreArea((brect_t *)
                                                                        CONCAT13(uVar6,CONCAT12(
                                                  percent,0x2410)),0x4a);
                                                  ovc42_drawTextRow(
                                                  "You will truly be master of your...",2);
                                                  ovr_miceBlitRect((brect_t *)
                                                                   CONCAT13(uVar6,CONCAT12(percent,
                                                  0x2410)),0x4a);
                                                  uVar3 = ovc42_usesMiceBlitRect(0x3c);
                                                  if ((byte)uVar3 < 2) {
                                                    ovr_miceRestoreArea((brect_t *)
                                                                        CONCAT13(uVar6,CONCAT12(
                                                  percent,0x2410)),0x4a);
                                                  ovr_ovc40_usesCalcSeasonPalette(percent,0);
                                                  ovr_driver_fillRect(0,0x13f,199,0,0x0,0,0x3f,199,0
                                                                     );
                                                  ovr_freeLeaderData();
                                                  bVar1 = 0x10;
                                                  (*(uint8_t *)((uint8_t *)&(gfx_00.seg))) = (char)&palette;
                                                  gfx_00.ofs = sky06FliSeg;
                                                  (*(uint8_t *)((uint8_t *)&(gfx_00.seg) + 1)) = (char)((uint)&palette >> 8);
                                                  ovr_ovc43_playArchiveFli(gfx_00,(char)sky06FliOfs)
                                                  ;
                                                  if (bVar1 < 2) {
                                                    (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) =
                                                         *(undefined2 *)
                                                          (BDA_DailyTimeCounter.ofs + 2);
                                                    uVar3 = *(undefined2 *)BDA_DailyTimeCounter;
                                                    (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = uVar3;
                                                    pcVar2 = ovc42_textProvidesMoreHousing(0x30);
                                                    if ((byte)pcVar2 < 2) {
                                                      (*(uint8_t *)((uint8_t *)&(palette_12.seg))) = percent;
                                                      palette_12.ofs = unaff_SS;
                                                      (*(uint8_t *)((uint8_t *)&(palette_12.seg) + 1)) = uVar6;
                                                      ovr_ovc40_usesVgaSetPalette8bit
                                                                (palette_12,(char)&palette);
                                                      (*(uint8_t *)((uint8_t *)&(handle_01.seg))) = percent;
                                                      handle_01.ofs = cred01Cut1Seg;
                                                      (*(uint8_t *)((uint8_t *)&(handle_01.seg) + 1)) = uVar6;
                                                      psStack_c = ovr_stshLoadGfx(handle_01,
                                                                                  (char)
                                                  cred01Cut1Ofs);
                                                  uStack_a = uVar3;
                                                  memcpy((char *)CONCAT13(uVar11,CONCAT12(uVar10,&
                                                  palette)),
                                                  (char *)CONCAT13((char)((uint)uVar3 >> 8),
                                                                   CONCAT12((char)uVar3,psStack_c)),
                                                  0x300);
                                                  ovr_driver_fillRect(0,0x13f,199,0,0x0,0,0x3f,199,0
                                                                     );
                                                  gfx_02.seg = 0;
                                                  gfx_02.ofs = cred01Cut2Seg;
                                                  (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = percent;
                                                  dst_00.ofs = 0xa000;
                                                  (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = uVar6;
                                                  ovr_blitLoadRleGfx(gfx_02,dst_00,
                                                                     (char)cred01Cut2Ofs,0);
                                                  (*(uint8_t *)((uint8_t *)&(palette_13.seg))) = percent;
                                                  palette_13.ofs = unaff_SS;
                                                  (*(uint8_t *)((uint8_t *)&(palette_13.seg) + 1)) = uVar6;
                                                  ovr_setSeasonPalette(palette_13,(char)&palette);
                                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) =
                                                       *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2)
                                                  ;
                                                  uVar3 = *(undefined2 *)BDA_DailyTimeCounter;
                                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = uVar3;
                                                  uVar4 = ovr_inputUpdate((ulong)CONCAT11(uVar6,
                                                  percent) << 0x10,0xb4);
                                                  if ((byte)uVar4 < 2) {
                                                    (*(uint8_t *)((uint8_t *)&(palette_14.seg))) = percent;
                                                    palette_14.ofs = unaff_SS;
                                                    (*(uint8_t *)((uint8_t *)&(palette_14.seg) + 1)) = uVar6;
                                                    ovr_ovc40_usesVgaSetPalette8bit
                                                              (palette_14,(char)&palette);
                                                    (*(uint8_t *)((uint8_t *)&(handle_02.seg))) = percent;
                                                    handle_02.ofs = cred02Cut1Seg;
                                                    (*(uint8_t *)((uint8_t *)&(handle_02.seg) + 1)) = uVar6;
                                                    psStack_c = ovr_stshLoadGfx(handle_02,
                                                                                (char)cred02Cut1Ofs)
                                                    ;
                                                    uStack_a = uVar3;
                                                    memcpy((char *)CONCAT13(uVar11,CONCAT12(uVar10,&
                                                  palette)),
                                                  (char *)CONCAT13((char)((uint)uVar3 >> 8),
                                                                   CONCAT12((char)uVar3,psStack_c)),
                                                  0x300);
                                                  ovr_driver_fillRect(0,0x13f,199,0,0x0,0,0x3f,199,0
                                                                     );
                                                  gfx_03.seg = 0;
                                                  gfx_03.ofs = cred02Cut2Seg;
                                                  (*(uint8_t *)((uint8_t *)&(dst_01.seg))) = percent;
                                                  dst_01.ofs = 0xa000;
                                                  (*(uint8_t *)((uint8_t *)&(dst_01.seg) + 1)) = uVar6;
                                                  ovr_blitLoadRleGfx(gfx_03,dst_01,
                                                                     (char)cred02Cut2Ofs,0);
                                                  (*(uint8_t *)((uint8_t *)&(palette_15.seg))) = percent;
                                                  palette_15.ofs = unaff_SS;
                                                  (*(uint8_t *)((uint8_t *)&(palette_15.seg) + 1)) = uVar6;
                                                  ovr_setSeasonPalette(palette_15,(char)&palette);
                                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) =
                                                       *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2)
                                                  ;
                                                  uVar3 = *(undefined2 *)BDA_DailyTimeCounter;
                                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = uVar3;
                                                  uVar4 = ovr_inputUpdate((ulong)CONCAT11(uVar6,
                                                  percent) << 0x10,0xb4);
                                                  if ((byte)uVar4 < 2) {
                                                    (*(uint8_t *)((uint8_t *)&(palette_16.seg))) = percent;
                                                    palette_16.ofs = unaff_SS;
                                                    (*(uint8_t *)((uint8_t *)&(palette_16.seg) + 1)) = uVar6;
                                                    ovr_ovc40_usesVgaSetPalette8bit
                                                              (palette_16,(char)&palette);
                                                    (*(uint8_t *)((uint8_t *)&(handle_03.seg))) = percent;
                                                    handle_03.ofs = cred03Cut1Seg;
                                                    (*(uint8_t *)((uint8_t *)&(handle_03.seg) + 1)) = uVar6;
                                                    psStack_c = ovr_stshLoadGfx(handle_03,
                                                                                (char)cred03Cut1Ofs)
                                                    ;
                                                    uStack_a = uVar3;
                                                    memcpy((char *)CONCAT13(uVar11,CONCAT12(uVar10,&
                                                  palette)),
                                                  (char *)CONCAT13((char)((uint)uVar3 >> 8),
                                                                   CONCAT12((char)uVar3,psStack_c)),
                                                  0x300);
                                                  ovr_driver_fillRect(0,0x13f,199,0,0x0,0,0x3f,199,0
                                                                     );
                                                  gfx_04.seg = 0;
                                                  gfx_04.ofs = cred03Cut2Seg;
                                                  (*(uint8_t *)((uint8_t *)&(dst_02.seg))) = percent;
                                                  dst_02.ofs = 0xa000;
                                                  (*(uint8_t *)((uint8_t *)&(dst_02.seg) + 1)) = uVar6;
                                                  ovr_blitLoadRleGfx(gfx_04,dst_02,
                                                                     (char)cred03Cut2Ofs,0);
                                                  (*(uint8_t *)((uint8_t *)&(palette_17.seg))) = percent;
                                                  palette_17.ofs = unaff_SS;
                                                  (*(uint8_t *)((uint8_t *)&(palette_17.seg) + 1)) = uVar6;
                                                  ovr_setSeasonPalette(palette_17,(char)&palette);
                                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) =
                                                       *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2)
                                                  ;
                                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) =
                                                       *(undefined2 *)BDA_DailyTimeCounter;
                                                  uVar4 = ovr_inputUpdate((ulong)CONCAT11(uVar6,
                                                  percent) << 0x10,0xb4);
                                                  if ((byte)uVar4 < 2) {
                                                    ovc42_endDemo('\0',(int)&palette,unaff_SS);
                                                    GameRunning = false;
                                                    CurMusicType = 0xff;
                                                    CurSfxType3 = 0xff;
                                                    uVar3 = 0x2400;
                                                  }
                                                  else {
                                                    puVar5 = &palette;
                                                    ovc42_endDemo('\x03',(int)puVar5,unaff_SS);
                                                    uVar3 = CONCAT11((char)((uint)puVar5 >> 8),1);
                                                  }
                                                  }
                                                  else {
                                                    puVar5 = &palette;
                                                    ovc42_endDemo('\x03',(int)puVar5,unaff_SS);
                                                    uVar3 = CONCAT11((char)((uint)puVar5 >> 8),1);
                                                  }
                                                  }
                                                  else {
                                                    puVar5 = &palette;
                                                    ovc42_endDemo('\x03',(int)puVar5,unaff_SS);
                                                    uVar3 = CONCAT11((char)((uint)puVar5 >> 8),1);
                                                  }
                                                  }
                                                  else {
                                                    puVar5 = &palette;
                                                    ovc42_endDemo('\x03',(int)puVar5,unaff_SS);
                                                    uVar3 = CONCAT11((char)((uint)puVar5 >> 8),1);
                                                  }
                                                  }
                                                  else {
                                                    puVar5 = &palette;
                                                    ovc42_endDemo('\x03',(int)puVar5,unaff_SS);
                                                    uVar3 = CONCAT11((char)((uint)puVar5 >> 8),1);
                                                  }
                                                  }
                                                  else {
                                                    ovc42_endDemo('\x01',0,0);
                                                    uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
                                                  }
                                                  }
                                                  else {
                                                    ovc42_endDemo('\x01',0,0);
                                                    uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
                                                  }
                                                }
                                                else {
                                                  ovc42_endDemo('\x01',0,0);
                                                  uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
                                                }
                                              }
                                              else {
                                                uVar6 = extraout_AH;
                                                ovc42_endDemo('\x02',0,0);
                                                uVar3 = CONCAT11(uVar6,1);
                                              }
                                            }
                                            else {
                                              puVar5 = &palette;
                                              ovc42_endDemo('\x01',(int)puVar5,unaff_SS);
                                              uVar3 = CONCAT11((char)((uint)puVar5 >> 8),1);
                                            }
                                          }
                                          else {
                                            ovc42_endDemo('\x01',0,0);
                                            uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
                                          }
                                        }
                                        else {
                                          ovc42_endDemo('\x01',0,0);
                                          uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
                                        }
                                      }
                                      else {
                                        ovc42_endDemo('\x01',0,0);
                                        uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
                                      }
                                    }
                                    else {
                                      ovc42_endDemo('\x01',0,0);
                                      uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
                                    }
                                  }
                                  else {
                                    puVar5 = &palette;
                                    ovc42_endDemo('\x01',(int)puVar5,unaff_SS);
                                    uVar3 = CONCAT11((char)((uint)puVar5 >> 8),1);
                                  }
                                }
                                else {
                                  puVar5 = &palette;
                                  ovc42_endDemo('\x01',(int)puVar5,unaff_SS);
                                  uVar3 = CONCAT11((char)((uint)puVar5 >> 8),1);
                                }
                              }
                              else {
                                puVar5 = &palette;
                                ovc42_endDemo('\x01',(int)puVar5,unaff_SS);
                                uVar3 = CONCAT11((char)((uint)puVar5 >> 8),1);
                              }
                            }
                            else {
                              puVar5 = &palette;
                              ovc42_endDemo('\x01',(int)puVar5,unaff_SS);
                              uVar3 = CONCAT11((char)((uint)puVar5 >> 8),1);
                            }
                          }
                          else {
                            puVar5 = &palette;
                            ovc42_endDemo('\x01',(int)puVar5,unaff_SS);
                            uVar3 = CONCAT11((char)((uint)puVar5 >> 8),1);
                          }
                        }
                        else {
                          puVar5 = &palette;
                          ovc42_endDemo('\x01',(int)puVar5,unaff_SS);
                          uVar3 = CONCAT11((char)((uint)puVar5 >> 8),1);
                        }
                      }
                      else {
                        puVar5 = &palette;
                        ovc42_endDemo('\x01',(int)puVar5,unaff_SS);
                        uVar3 = CONCAT11((char)((uint)puVar5 >> 8),1);
                      }
                    }
                    else {
                      ovc42_endDemo('\x01',0,0);
                      uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
                    }
                  }
                  else {
                    ovc42_endDemo('\x01',0,0);
                    uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
                  }
                }
                else {
                  ovc42_endDemo('\x01',0,0);
                  uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
                }
              }
              else {
                ovc42_endDemo('\x01',0,0);
                uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
              }
            }
            else {
              ovc42_endDemo('\x01',0,0);
              uVar3 = CONCAT11((char)((uint)uVar3 >> 8),1);
            }
          }
          else {
            puVar5 = &palette;
            ovc42_endDemo('\x03',(int)puVar5,unaff_SS);
            uVar3 = CONCAT11((char)((uint)puVar5 >> 8),1);
          }
        }
        else {
          puVar5 = &palette;
          ovc42_endDemo('\x03',(int)puVar5,unaff_SS);
          uVar3 = CONCAT11((char)((uint)puVar5 >> 8),1);
        }
      }
      else {
        puVar5 = &palette;
        ovc42_endDemo('\x03',(int)puVar5,unaff_SS);
        uVar3 = CONCAT11((char)((uint)puVar5 >> 8),1);
      }
    }
    else {
      puVar5 = &palette;
      ovc42_endDemo('\x03',(int)puVar5,unaff_SS);
      uVar3 = CONCAT11((char)((uint)puVar5 >> 8),1);
    }
  }
  else {
    puVar5 = &palette;
    ovc42_endDemo('\x03',(int)puVar5,unaff_SS);
    uVar3 = CONCAT11((char)((uint)puVar5 >> 8),1);
  }
  return uVar3;
}



/* 6d7a:1f25 */

/* [R6] touches AgntCount */

void __cdecl16far ovc42_usesAgntCount(void)

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
  ovr_agnt_usesAlignToSeg();
  ovr_agnt_usesAlignToSeg();
  ovr_agnt_usesAlignToSeg();
  ovr_agnt_usesAlignToSeg();
  return;
}


