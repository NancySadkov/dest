/*
 * ovc42_demo.c - recovered from STRONG.EXE
 * memory block: OVC42_demo.c
 * range: 6d7a:0000 - 6d7a:243f
 * functions: 12
 */
#include "recovered.h"


/* 6d7a:0000 */
char * __cdecl16far ovc42_textProvidesMoreHousing(uint32_t timeoutTicks)

{
  undefined2 uVar1;
  ulong *__return_storage_ptr__;
  uint16_t uVar2;
  uint uVar3;
  ulong *puVar4;
  ulong *puVar5;
  uint unaff_SI;
  undefined2 uVar6;
  ulong prevTick;
  
  prevTick = (ulong)unaff_SI << 0x10;
  uVar1 = *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
  __return_storage_ptr__ = *(ulong **)BDA_DailyTimeCounter.ofs   /* hand fix: the offset half is the address, not the far_t struct */;
  MiceNeedsUpdate = 1;
  puVar5 = __return_storage_ptr__;
  do {
    uVar6 = (undefined2)(prevTick >> 0x10);
    uVar2 = ovr_biosKeyAvail();
    if ((char)uVar2 != '\0') {
      uVar2 = ovr_gameProcessKey();
      if (uVar2 == 0x11b) {
        return (char *)((int)&GUnitDescriptions[5].seg + 1);
      }
      if (uVar2 == 0x1c0d) {
        return (char *)0x1c01;
      }
    }
    uVar3 = ovr_init2_updateMouseButtons();
    if ((uVar3 != 0) || (rightButtonLatch != '\0')) {
      if (rightButtonLatch != '\0') {
        return (char *)"woodcarver";
      }
      return (char *)0x2401;
    }
    prevTick = CONCAT22(uVar6,uVar1);
    puVar4 = ovr_attact_usesBDADailyTimeCounter(__return_storage_ptr__,prevTick);
  } while ((puVar5 < (*(uint16_t *)((uint8_t *)&(timeoutTicks) + 2))) ||
          ((puVar5 == (*(uint16_t *)((uint8_t *)&(timeoutTicks) + 2)) && (puVar4 < (ulong *)timeoutTicks))));
  return (char *)((uint)puVar4 & 0xff00);
}


/* 6d7a:009b */
undefined2 __cdecl16far ovc42_usesMiceBlitRect(byte timeoutTicks)

{
  bool bVar1;
  undefined1 extraout_AH;
  ulong *puVar2;
  undefined1 uVar3;
  uint16_t uVar4;
  ulong prevTick;
  
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
  rightButtonLatch = 0;
  if (MiceNeedsUpdate == '\0') {
    prevTick = 0;
  }
  else {
    ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x2410);
    prevTick = 0x1000000;
  }
  do {
    prevTick = prevTick & 0xffff0000;
    bVar1 = ovr_draw_textProvidesMoreHousing();
  } while (bVar1);
  while( true ) {
    uVar3 = (undefined1)(prevTick >> 0x18);
    uVar4 = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
    if ((*(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2) != InputEventTime.hi) ||
       (uVar4 != InputEventTime.lo)) {
      InputEventTime.hi = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
      uVar4 = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
      InputEventTime.lo = uVar4;
      ovr_draw_usesPrintf();
    }
    bVar1 = ovr_draw_textProvidesMoreHousing();
    puVar2 = (ulong *)CONCAT11(extraout_AH,bVar1);
    prevTick = (ulong)CONCAT11(uVar3,bVar1) << 0x10;
    if (bVar1) break;
    prevTick = CONCAT22(CONCAT11(uVar3,bVar1),(*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)));
    puVar2 = ovr_attact_usesBDADailyTimeCounter((ulong *)TextBlitCycle,prevTick);
    if ((uVar4 != 0) || ((ulong *)(uint)timeoutTicks <= puVar2)) break;
  }
  uVar3 = (undefined1)((uint)puVar2 >> 8);
  if ((char)(prevTick >> 0x18) != '\0') {
    prevTick = CONCAT22((int)(prevTick >> 0x10),0x2410);
    ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
  }
  return CONCAT11(uVar3,(char)(prevTick >> 0x10));
}


/* 6d7a:0190 */

/* Ends the demo: reports cancellation, restores the palette and mouse, clears GameRunning and
   restores the menu graphics. */

void __cdecl16far ovc42_endDemo(char exitCode,int paletteOfs,int paletteSeg)

{
  far_t gfx;
  far_t gfx_00;
  far_t palette;
  far_t gfx_01;
  
  if ((exitCode != '\0') && (exitCode != '\x03')) {
    ovc42_drawTextRow("Demo cancelled.",0);
    ovr_inputUpdate(9);
  }
  if (exitCode != '\x02') {
    if (paletteOfs == 0 && paletteSeg == 0) {
      ovr_ovc40_usesCalcSeasonPalette('\0');
    }
    else {
      (*(uint8_t *)((uint8_t *)&(palette.seg))) = (char)paletteSeg;
      palette.ofs = paletteOfs;
      (*(uint8_t *)((uint8_t *)&(palette.seg) + 1)) = (char)((uint)paletteSeg >> 8);
      ovr_ovc40_usesVgaSetPalette8bit(palette);
    }
  }
  ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
  ovr_init_usesBlitGfxRect();
  GameRunning = false;
  gfx_01.seg = nwpanel2Cut1Seg;
  gfx_01.ofs = nwpanel2Cut1Ofs;
  ovr_blitGfxRect(gfx_01,0,0,(brect_t *)(BlitRects + 1),0x10,true,0x10,0x10,0);
  (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)GMenuGfxSeg;
  gfx.ofs = GMenuGfxOfs;
  (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)((uint)GMenuGfxSeg >> 8);
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa00009af)),0xaf);
  (*(uint8_t *)((uint8_t *)&(gfx_00.seg))) = (char)panel01Cut3Seg;
  gfx_00.ofs = panel01Cut3Ofs;
  (*(uint8_t *)((uint8_t *)&(gfx_00.seg) + 1)) = (char)((uint)panel01Cut3Seg >> 8);
  ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)(0xa000c51d)),0x1d);
  mapViewActive = 0;
  SaveAuto = 0;
  AgntFlag1 = false;
  ovr_freeGameResources();
  CurMusicType = 0xff;
  CurSfxType3 = 0xff;
  ovr_stop_audio();
  if (exitCode != '\0') {
    ovr_ovc40_usesCalcSeasonPalette('\x01');
  }
  return;
}



/* 6d7a:02ab */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches EntityCount, Entities */

void __cdecl16far ovc42_usesEntityCount(void)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  
  for (uVar2 = 0; uVar2 < EntityCount; uVar2 = uVar2 + 1) {
    uVar3 = (undefined2)((ulong)Entities >> 0x10);
    iVar1 = (int)Entities;
    if ((*(char *)(iVar1 + uVar2 * 0x37 + 0x1a) != -1) &&
       (*(char *)((int)(char **)GMenuStrings +
                 (uint)*(byte *)(iVar1 + uVar2 * 0x37 + 0xd) * 0x95 + 0x1f) != '\0')) {
      *(undefined2 *)(iVar1 + uVar2 * 0x37) = 0;
      *(undefined2 *)((int)Entities + uVar2 * 0x37 + 2) = 0;
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
  far_t cmap_00;
  int iVar1;
  uint unaff_SS;
  far_t gfx;
  agnt_t agntRec;
  uint8_t agntTmp;
  entity_t *peStack_29;
  uint8_t rect;
  int16_t iStack_6;
  
  ovr_draw_freeRingBuffers();
  memcpy((char *)CONCAT22(unaff_SS,&rect),(char *)(BlitRects + 1),10);
  iStack_6 = 150;
  gfx.seg = talkwin9Cut1Seg;
  gfx.ofs = talkwin9Cut1Ofs;
  ovr_blitGfxRect(gfx,0,0,(brect_t *)&rect,(uint8_t)unaff_SS,true,0);
  _fmemset((void *)(ulong)unaff_SS,0x34,agntRec.x);
  _fmemset((void *)(ulong)unaff_SS,0x37,agntRec.x);
  peStack_29 = (entity_t *)&agntRec;
  agntRec.gindex = gindex;
  agntRec.animFrame = 0x1;
  (*(uint8_t *)((uint8_t *)&(agntRec.entity) + 3)) = partyIndex;
  if (flag != '\0') {
    (*(uint16_t *)((uint8_t *)&(agntRec) + 22)) = (*(uint16_t *)((uint8_t *)&(agntRec) + 22)) | 1;
  }
  if (level == 0) {
    agntRec.level = *(uint8_t *)((int)&worldMenuLabels[8].seg + (uint)gindex * 0x95);
  }
  else {
    agntRec.level = level;
  }
  if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)gindex * 0x95) == -1) {
    (*(uint16_t *)((uint8_t *)&(agntRec) + 18)) = *(undefined2 *)((uint)agntRec.level * 4 + -2);
    (*(uint16_t *)((uint8_t *)&(agntRec) + 16)) = *(undefined2 *)((uint)agntRec.level * 4 + -4);
  }
  else {
    iVar1 = (uint)*(byte *)((int)&worldMenuLabels[9].ofs + 1 + (uint)gindex * 0x95) * 0x94 +
            (uint)agntRec.level * 4;
    (*(uint16_t *)((uint8_t *)&(agntRec) + 18)) = *(undefined2 *)(iVar1 + -2);
    (*(uint16_t *)((uint8_t *)&(agntRec) + 16)) = *(undefined2 *)(iVar1 + -4);
  }
  if ((*(uint16_t *)((uint8_t *)&(agntRec) + 16)) == 0 && (*(uint16_t *)((uint8_t *)&(agntRec) + 18)) == 0) {
    (*(uint16_t *)((uint8_t *)&(agntRec) + 18)) = 0;
    agntRec.health = 0x64;
    agntRec.animVariant = 0x0;
  }
  cmap_00.seg = cmap.ofs;
  cmap_00.ofs = unaff_SS;
  ovr_drawAgntStats((agnt_t *)&agntTmp,cmap_00,cmap.seg);
  return;
}



/* 6d7a:04f2 */

/* Fills the area around the cursor with random unit types and spawns the matching agents. */

void __cdecl16far ovc42_populateArea(byte partyIndex)

{
  uint16_t x;
  uint16_t y;
  uint16_t uVar1;
  uint uVar2;
  uint uVar3;
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
      x = GfxRndSeed + iStack_4;
      y = GfxRndSeed2 + iStack_6;
      if ((-0xb < iStack_4) || (uVar1 = ovr_randBelow(3), (uVar1 & 0xff) == 0)) {
        if (y == 0x24) {
          uVar2 = ovr_alignUp4(x);
          uVar3 = ovr_alignUp4(0x48);
          if (uVar2 == uVar3) goto L_OVC42_6d7a_04f2_0627;
        }
        if ((((GfxRndSeed2 != y) || ((int)x < GfxRndSeed + -1)) || (GfxRndSeed + 1 < (int)x)) &&
           (uVar2 = ovr_constr_usesGMapFlags(x,y), (char)uVar2 != '\0')) {
          uVar1 = ovr_randBelow(0xe);
          (*(short (*) [148] [60])GUnitGrid)[x][y] = (uint)(&unitTypeMap)[uVar1 & 0xff];
          uVar1 = ovr_randBelow(5);
          if ((uVar1 & 0xff) == 0) {
            uVar4 = CONCAT22((uint)partyIndex,1);
            uVar1 = ovr_randBelow(8);
            ovr_ovc15_usesLDIV_at_
                      (x,y,x,y,(&spawnGindexMap)[uVar1 & 0xff],(uint8_t)uVar4,
                       (byte)((ulong)uVar4 >> 0x10));
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
  int x;
  int y;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  int iStack_a;
  
  for (iStack_a = -10; iStack_a < 0xb; iStack_a = iStack_a + 1) {
    for (iVar3 = -0x14; iVar3 < 3; iVar3 = iVar3 + 1) {
      x = GfxRndSeed + iStack_a;
      y = GfxRndSeed2 + iVar3;
      uVar2 = ovr_constr_usesGMapFlags(x,y);
      if ((char)uVar2 != '\0') {
        uVar4 = (undefined2)((ulong)GUnitGrid >> 0x10);
        bVar1 = ((unit_t *)GUnits + (*(short (*) [148] [60])GUnitGrid)[x][y])->bldType;
        if (*(char *)((uint)bVar1 * 0x27 + 300) != '\0') {
          (*(short (*) [148] [60])GUnitGrid)[x][y] =
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
void __cdecl16far ovc42_drawTextRow(char *text,byte row)

{
  int16_t max_width;
  uint16_t unaff_SS;
  far_t gfx;
  far_t dst_00;
  far_t handle;
  uint8_t dst;
  stg_tmp_t *psStack_6;
  int16_t iStack_4;
  
  dst_00.seg = unaff_SS;
  dst_00.ofs = (uint16_t)&dst;
  F_SCOPY(far_from_u32((uint32_t)(0x2410715b)),dst_00);
  if (row == 0) {
    gfx.seg = fullScreenGfxSeg;
    gfx.ofs = fullScreenGfxOfs;
    ovr_blitGfx10(gfx,0,0,(brect_t *)&dst,SUB21(unaff_SS,0));
  }
  TextBlitY = (uint)row * 0xd + 0x9e;
  max_width = 9232;
  TextBlitX = 0xb;
  handle.seg = demfont1FontSeg;
  handle.ofs = demfont1FontOfs;
  psStack_6 = ovr_stshLoadGfx(handle);
  TextBlitDstSeg = 0xa000;
  iStack_4 = max_width;
  ovr_blitLabel((char *)text,(uint8_t *)CONCAT22(psStack_6,(*(uint16_t *)((uint8_t *)&(text) + 2))),max_width,0x3f);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
  return;
}


/* 6d7a:0850 */
void __cdecl16far ovc42_usesBlitLabel(char *text,byte row,...)

{
  stg_tmp_t *psVar1;
  int16_t max_width;
  byte in_stack_00000008;
  far_t handle;
  
  BlitLetterType = 1;
  TextBlitY = (uint)in_stack_00000008 * 0xd + 0x9c;
  max_width = 9232;
  TextBlitX = 0xb;
  handle.seg = demfont1FontSeg;
  handle.ofs = demfont1FontOfs;
  psVar1 = ovr_stshLoadGfx(handle);
  ovr_blitLabel(text,(uint8_t *)CONCAT22(psVar1,row),max_width,0x3f);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
  BlitLetterType = 0;
  return;
}


/* 6d7a:08df */
undefined2 __cdecl16far run_demo(void)

{
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t cmap;
  far_t cmap_00;
  far_t cmap_01;
  far_t cmap_02;
  far_t cmap_03;
  far_t cmap_04;
  far_t cmap_05;
  far_t cmap_06;
  far_t palette_00;
  far_t handle;
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
  far_t palette_13;
  far_t palette_14;
  far_t handle_02;
  far_t palette_15;
  far_t palette_16;
  far_t handle_03;
  far_t palette_17;
  byte bVar1;
  char *pcVar2;
  undefined2 uVar3;
  undefined1 extraout_AH;
  undefined1 uVar5;
  uint8_t *puVar4;
  uint16_t uVar6;
  int iVar7;
  uint16_t unaff_DI;
  int iVar8;
  uint unaff_SS;
  undefined1 uVar9;
  uint8_t palette;
  stg_tmp_t *psStack_c;
  uint16_t uStack_a;
  byte bStack_7;
  byte bStack_6;
  byte bStack_5;
  byte bStack_4;
  byte bStack_3;
  
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
  bStack_4 = ovr_ovc30_textDivideError(10,1,'\x02',100,1,2);
  GfxRndSeed = demoCenterX;
  GfxRndSeed2 = demoCenterY;
  uVar3 = ((undefined2 *)((uint)bStack_4 * 4))[1];
  strcpy((char *)CONCAT13((char)((uint)uVar3 >> 8),
                          CONCAT12((char)uVar3,*(undefined2 *)((uint)bStack_4 * 4))),"Nasher");
  bStack_5 = ovr_ovc30_textDivideError(10,1,'\x02',100,1,2);
  uVar3 = ((undefined2 *)((uint)bStack_5 * 4))[1];
  strcpy((char *)CONCAT13((char)((uint)uVar3 >> 8),
                          CONCAT12((char)uVar3,*(undefined2 *)((uint)bStack_5 * 4))),"Fordor");
  bStack_6 = ovr_ovc30_textDivideError(10,1,'\x02',100,1,2);
  uVar3 = ((undefined2 *)((uint)bStack_6 * 4))[1];
  strcpy((char *)CONCAT13((char)((uint)uVar3 >> 8),
                          CONCAT12((char)uVar3,*(undefined2 *)((uint)bStack_6 * 4))),"Kaunas");
  ovc42_populateArea(bStack_4);
  for (iVar8 = -2; iVar8 < 3; iVar8 = iVar8 + 1) {
    for (iVar7 = -1; iVar7 < 1; iVar7 = iVar7 + 1) {
      ovr_ovc18_usesRandBelow(iVar8 + 0x48,iVar7 + 0x24,0,0xff,(char)(iVar7 + 0x24),0);
    }
  }
  ovr_ovc18_usesRandBelow(0x49,0x24,0x40,0xff,0x24,0x40);
  ovr_ovc18_usesRandBelow(0x47,0x23,0x3e,0xff,0x23,0x3e);
  ovr_ovc18_usesRandBelow(0x46,0x23,0x26,0xff,0x23,0x26);
  ovr_ovc18_usesRandBelow(GfxRndSeed,GfxRndSeed2,0,0xff,(char)GfxRndSeed2,0);
  ovr_ovc18_usesRandBelow(GfxRndSeed - 1,GfxRndSeed2,0x8c,0xff,(char)GfxRndSeed2,0x8c);
  ovr_ovc30_textDivideError(4,1,'\x01',100,1,1);
  bStack_3 = ovr_ovc30_textDivideError(0x1a,1,'\x01',100,1,1);
  uVar6 = 0x217a;
  uVar3 = ((undefined2 *)((uint)bStack_3 * 4))[1];
  strcpy((char *)CONCAT13((char)((uint)uVar3 >> 8),
                          CONCAT12((char)uVar3,*(undefined2 *)((uint)bStack_3 * 4))),"Mindark");
  ovr_ovc15_usesLDIV_at_(0x48,0x24,0x48,0x24,1,0x1,1,0x48,0x24,1,1);
  ovr_ovc15_usesLDIV_at_(0x48,0x24,0x48,0x24,2,0x1,1,0x48,0x24,2,1);
  ovr_ovc15_usesLDIV_at_(0x48,0x24,0x48,0x24,2,0x1,1,0x48,0x24,2,1);
  ovr_ovc15_usesLDIV_at_(0x48,0x24,0x48,0x24,0xb,0x1,1,0x48,0x24,0xb,1);
  ovr_ovc15_usesLDIV_at_
            (GfxRndSeed - 1,GfxRndSeed2,GfxRndSeed - 1,GfxRndSeed2,10,0x1,1,(char)(GfxRndSeed - 1),
             (char)GfxRndSeed2,10,1);
  ovr_ovc15_usesLDIV_at_
            (GfxRndSeed - 1,GfxRndSeed2,GfxRndSeed - 1,GfxRndSeed2,8,0x1,1,(char)(GfxRndSeed - 1),
             (char)GfxRndSeed2,8,1);
  ovr_ovc15_usesLDIV_at_
            (GfxRndSeed - 1,GfxRndSeed2,GfxRndSeed - 1,GfxRndSeed2,3,0x1,1,(char)(GfxRndSeed - 1),
             (char)GfxRndSeed2,3,1);
  ovr_ovc15_usesLDIV_at_
            (GfxRndSeed - 5,GfxRndSeed2,GfxRndSeed - 1,GfxRndSeed2,10,0x1,1,(char)(GfxRndSeed - 1),
             (char)GfxRndSeed2,10,1);
  ovr_ovc15_usesLDIV_at_
            (GfxRndSeed - 5,GfxRndSeed2,GfxRndSeed - 1,GfxRndSeed2,1,0x1,1,(char)(GfxRndSeed - 1),
             (char)GfxRndSeed2,1,1);
  ovr_ovc15_usesLDIV_at_
            (GfxRndSeed - 5,GfxRndSeed2,GfxRndSeed - 1,GfxRndSeed2,0,0x1,1,(char)(GfxRndSeed - 1),
             (char)GfxRndSeed2,0,1);
  GfxRndSeed = GfxRndSeed - 0x10;
  _fmemset((void *)(ulong)unaff_SS,0x300,unaff_DI);
  ovr_vgaSetPalette8bit(&palette);
  ovr_driver_fillRect(0,0,0x13f,199,0x0,0xa000,0,0x3f,199,0,0);
  ovr_fmFree();
  ovr_play_sfx(137,0,0);
  bVar1 = 0x10;
  (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)l9Cut4Seg;
  gfx.ofs = l9Cut4Ofs;
  (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)((uint)l9Cut4Seg >> 8);
  ovr_ovc43_playArchiveFli(gfx,(uint16_t)&palette,(char)&palette);
  if (bVar1 < 2) {
    pcVar2 = ovc42_textProvidesMoreHousing(0x48);
    if ((byte)pcVar2 < 2) {
      uVar5 = (undefined1)unaff_SS;
      uVar9 = (undefined1)(unaff_SS >> 8);
      (*(uint8_t *)((uint8_t *)&(palette_00.seg))) = uVar5;
      palette_00.ofs = (uint16_t)&palette;
      (*(uint8_t *)((uint8_t *)&(palette_00.seg) + 1)) = uVar9;
      ovr_ovc40_usesVgaSetPalette8bit(palette_00);
      (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)ssilogoCut1Seg;
      handle.ofs = ssilogoCut1Ofs;
      (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)ssilogoCut1Seg >> 8);
      psStack_c = ovr_stshLoadGfx(handle);
      uStack_a = uVar6;
      memcpy((char *)CONCAT13(uVar9,CONCAT12(uVar5,&palette)),
             (char *)CONCAT13((char)(uVar6 >> 8),CONCAT12((char)uVar6,psStack_c)),0x300);
      ovr_driver_fillRect(0,0,0x13f,199,0x0,0xa000,0,0x3f,199,0,0);
      (*(uint8_t *)((uint8_t *)&(gfx_01.seg))) = (char)ssilogoCut2Seg;
      gfx_01.ofs = ssilogoCut2Ofs;
      (*(uint8_t *)((uint8_t *)&(gfx_01.seg) + 1)) = (char)((uint)ssilogoCut2Seg >> 8);
      ovr_blitLoadRleGfx(gfx_01,far_from_u32((uint32_t)(0xa0000000)),0);
      (*(uint8_t *)((uint8_t *)&(palette_01.seg))) = uVar5;
      palette_01.ofs = (uint16_t)&palette;
      (*(uint8_t *)((uint8_t *)&(palette_01.seg) + 1)) = uVar9;
      ovr_setSeasonPalette(palette_01);
      pcVar2 = ovc42_textProvidesMoreHousing(0x48);
      if ((byte)pcVar2 < 2) {
        (*(uint8_t *)((uint8_t *)&(palette_02.seg))) = uVar5;
        palette_02.ofs = (uint16_t)&palette;
        (*(uint8_t *)((uint8_t *)&(palette_02.seg) + 1)) = uVar9;
        ovr_ovc40_usesVgaSetPalette8bit(palette_02);
        ovr_fmFree();
        ovr_play_sfx(46,3,3);
        GameRunning = true;
        ovr_init_usesBlitGfxRect();
        (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = (char)Lbm_nwpanel1.seg;
        handle_00.ofs = Lbm_nwpanel1.ofs;
        (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = (char)(Lbm_nwpanel1.seg >> 8);
        psStack_c = ovr_stshLoadGfx(handle_00);
        uStack_a = uVar6;
        ovr_calcSeasonPalette(psStack_c->cmap,uVar6,&palette,(char)uVar6,(char)&palette);
        ovc42_copy1((char *)CONCAT13(uVar9,CONCAT12(uVar5,&palette)));
        ovr_driver_fillRect(0,0,0x13f,199,0x0,0xa000,0,0x3f,199,0,0);
        bVar1 = ovr_ovc43_playFli(0x184,(uint16_t)&palette,(char)&palette);
        if (bVar1 < 2) {
          pcVar2 = ovc42_textProvidesMoreHousing(0x10);
          if ((byte)pcVar2 < 2) {
            (*(uint8_t *)((uint8_t *)&(palette_03.seg))) = uVar5;
            palette_03.ofs = (uint16_t)&palette;
            (*(uint8_t *)((uint8_t *)&(palette_03.seg) + 1)) = uVar9;
            ovr_ovc40_usesVgaSetPalette8bit(palette_03);
            ovr_init_usesBlitGfxRect();
            ovr_ovc28_textHalflingCastle();
            AgntFlag1 = false;
            ovr_ovc41_usesAgnt_clear('\0');
            ovc42_usesAgntCount();
            ovc42_drawTextRow("A new land lies before you. Choose carefully",0);
            ovc42_drawTextRow("where you settle.",1);
            ovr_ovc40_usesCalcSeasonPalette('\x01');
            ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
            uVar3 = ovc42_usesMiceBlitRect(0x32);
            if ((byte)uVar3 < 2) {
              ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
              GfxRndSeed = GfxRndSeed + 4;
              AgntFlag1 = false;
              ovr_ovc41_usesAgnt_clear('\0');
              ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
              uVar3 = ovc42_usesMiceBlitRect(0x32);
              if ((byte)uVar3 < 2) {
                ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                GfxRndSeed = GfxRndSeed + 4;
                AgntFlag1 = false;
                ovr_ovc41_usesAgnt_clear('\0');
                ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                uVar3 = ovc42_usesMiceBlitRect(0x32);
                if ((byte)uVar3 < 2) {
                  ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                  GfxRndSeed = GfxRndSeed + 4;
                  AgntFlag1 = false;
                  ovr_ovc41_usesAgnt_clear('\0');
                  ovc42_drawTextRow("Your goal: Create a thriving community.",0);
                  ovc42_drawTextRow("Balance building, money, and food production",1);
                  ovc42_drawTextRow("to keep your people happy.",2);
                  ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                  uVar3 = ovc42_usesMiceBlitRect(0x32);
                  if ((byte)uVar3 < 2) {
                    ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                    GfxRndSeed = GfxRndSeed + 4;
                    AgntFlag1 = false;
                    ovr_ovc41_usesAgnt_clear('\0');
                    ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                    uVar3 = ovc42_usesMiceBlitRect(0x4b);
                    if ((byte)uVar3 < 2) {
                      ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                      ovr_ovc40_usesCalcSeasonPalette('\0');
                      ovc42_drawTextRow("Your world will be filled with a full range",0);
                      ovc42_drawTextRow("of official D&D@ game characters.",1);
                      (*(uint8_t *)((uint8_t *)&(cmap.seg))) = uVar5;
                      cmap.ofs = (uint16_t)&palette;
                      (*(uint8_t *)((uint8_t *)&(cmap.seg) + 1)) = uVar9;
                      ovc42_showAgentStats(0,bStack_4,'\0',cmap,0);
                      ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                      MiceUnkState = 0;
                      (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
                      (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
                      uVar6 = ovr_inputUpdate(0x3c);
                      if ((byte)uVar6 < 2) {
                        ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                        (*(uint8_t *)((uint8_t *)&(palette_04.seg))) = uVar5;
                        palette_04.ofs = (uint16_t)&palette;
                        (*(uint8_t *)((uint8_t *)&(palette_04.seg) + 1)) = uVar9;
                        ovr_ovc40_usesVgaSetPalette8bit(palette_04);
                        (*(uint8_t *)((uint8_t *)&(cmap_00.seg))) = uVar5;
                        cmap_00.ofs = (uint16_t)&palette;
                        (*(uint8_t *)((uint8_t *)&(cmap_00.seg) + 1)) = uVar9;
                        ovc42_showAgentStats(3,bStack_5,'\x01',cmap_00,0);
                        ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                        (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
                        (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
                        uVar6 = ovr_inputUpdate(0x32);
                        if ((byte)uVar6 < 2) {
                          ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                          (*(uint8_t *)((uint8_t *)&(palette_05.seg))) = uVar5;
                          palette_05.ofs = (uint16_t)&palette;
                          (*(uint8_t *)((uint8_t *)&(palette_05.seg) + 1)) = uVar9;
                          ovr_ovc40_usesVgaSetPalette8bit(palette_05);
                          (*(uint8_t *)((uint8_t *)&(cmap_01.seg))) = uVar5;
                          cmap_01.ofs = (uint16_t)&palette;
                          (*(uint8_t *)((uint8_t *)&(cmap_01.seg) + 1)) = uVar9;
                          ovc42_showAgentStats(8,bStack_6,'\x01',cmap_01,0);
                          ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                          (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
                          (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
                          uVar6 = ovr_inputUpdate(0x32);
                          if ((byte)uVar6 < 2) {
                            ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                            (*(uint8_t *)((uint8_t *)&(palette_06.seg))) = uVar5;
                            palette_06.ofs = (uint16_t)&palette;
                            (*(uint8_t *)((uint8_t *)&(palette_06.seg) + 1)) = uVar9;
                            ovr_ovc40_usesVgaSetPalette8bit(palette_06);
                            (*(uint8_t *)((uint8_t *)&(cmap_02.seg))) = uVar5;
                            cmap_02.ofs = (uint16_t)&palette;
                            (*(uint8_t *)((uint8_t *)&(cmap_02.seg) + 1)) = uVar9;
                            ovc42_showAgentStats(1,bStack_6,'\0',cmap_02,0xc);
                            ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                            (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
                            (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
                            uVar6 = ovr_inputUpdate(0x32);
                            if ((byte)uVar6 < 2) {
                              ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                              (*(uint8_t *)((uint8_t *)&(palette_07.seg))) = uVar5;
                              palette_07.ofs = (uint16_t)&palette;
                              (*(uint8_t *)((uint8_t *)&(palette_07.seg) + 1)) = uVar9;
                              ovr_ovc40_usesVgaSetPalette8bit(palette_07);
                              ovc42_drawTextRow("You are not alone in this pristine land.",0);
                              ovc42_drawTextRow("Official D&D@ game monsters will fight to",1);
                              ovc42_drawTextRow("destroy your city.",2);
                              (*(uint8_t *)((uint8_t *)&(cmap_03.seg))) = uVar5;
                              cmap_03.ofs = (uint16_t)&palette;
                              (*(uint8_t *)((uint8_t *)&(cmap_03.seg) + 1)) = uVar9;
                              ovc42_showAgentStats(0x15,bStack_3,'\x01',cmap_03,0);
                              ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                              (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
                              (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
                              uVar6 = ovr_inputUpdate(0x32);
                              if ((byte)uVar6 < 2) {
                                ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                                (*(uint8_t *)((uint8_t *)&(palette_08.seg))) = uVar5;
                                palette_08.ofs = (uint16_t)&palette;
                                (*(uint8_t *)((uint8_t *)&(palette_08.seg) + 1)) = uVar9;
                                ovr_ovc40_usesVgaSetPalette8bit(palette_08);
                                (*(uint8_t *)((uint8_t *)&(cmap_04.seg))) = uVar5;
                                cmap_04.ofs = (uint16_t)&palette;
                                (*(uint8_t *)((uint8_t *)&(cmap_04.seg) + 1)) = uVar9;
                                ovc42_showAgentStats(0x24,bStack_3,'\x01',cmap_04,0);
                                ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                                (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
                                (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
                                uVar6 = ovr_inputUpdate(0x32);
                                if ((byte)uVar6 < 2) {
                                  ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                                  (*(uint8_t *)((uint8_t *)&(palette_09.seg))) = uVar5;
                                  palette_09.ofs = (uint16_t)&palette;
                                  (*(uint8_t *)((uint8_t *)&(palette_09.seg) + 1)) = uVar9;
                                  ovr_ovc40_usesVgaSetPalette8bit(palette_09);
                                  (*(uint8_t *)((uint8_t *)&(cmap_05.seg))) = uVar5;
                                  cmap_05.ofs = (uint16_t)&palette;
                                  (*(uint8_t *)((uint8_t *)&(cmap_05.seg) + 1)) = uVar9;
                                  ovc42_showAgentStats(0xe,bStack_3,'\x01',cmap_05,0);
                                  ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) =
                                       *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
                                  uVar6 = ovr_inputUpdate(0x32);
                                  if ((byte)uVar6 < 2) {
                                    ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                                    (*(uint8_t *)((uint8_t *)&(palette_10.seg))) = uVar5;
                                    palette_10.ofs = (uint16_t)&palette;
                                    (*(uint8_t *)((uint8_t *)&(palette_10.seg) + 1)) = uVar9;
                                    ovr_ovc40_usesVgaSetPalette8bit(palette_10);
                                    ovr_ovc28_textHalflingCastle();
                                    GfxRndSeed = 0x68;
                                    GfxRndSeed2 = 0x10;
                                    ovr_ovc18_usesRandBelow(0x68,0x10,0,0xff,0x10,0);
                                    ovr_ovc18_usesRandBelow
                                              (GfxRndSeed - 1,GfxRndSeed2,0x86,0xff,
                                               (char)GfxRndSeed2,0x86);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed - 2,GfxRndSeed2,GfxRndSeed,GfxRndSeed2,0xd
                                               ,0x1,1,(char)GfxRndSeed,(char)GfxRndSeed2,0xd,1);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed - 2,GfxRndSeed2,GfxRndSeed,GfxRndSeed2,
                                               0x21,0x1,1,(char)GfxRndSeed,(char)GfxRndSeed2,0x21,1)
                                    ;
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed - 2,GfxRndSeed2,GfxRndSeed,GfxRndSeed2,
                                               0x16,0x1,1,(char)GfxRndSeed,(char)GfxRndSeed2,0x16,1)
                                    ;
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed - 2,GfxRndSeed2,GfxRndSeed,GfxRndSeed2,7,
                                               0x1,1,(char)GfxRndSeed,(char)GfxRndSeed2,7,1);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed + 1,GfxRndSeed2,GfxRndSeed,GfxRndSeed2,1,
                                               0x1,1,(char)GfxRndSeed,(char)GfxRndSeed2,1,1);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed + 1,GfxRndSeed2,GfxRndSeed,GfxRndSeed2,1,
                                               0x1,1,(char)GfxRndSeed,(char)GfxRndSeed2,1,1);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed + 1,GfxRndSeed2,GfxRndSeed,GfxRndSeed2,0,
                                               0x1,1,(char)GfxRndSeed,(char)GfxRndSeed2,0,1);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed + 1,GfxRndSeed2,GfxRndSeed,GfxRndSeed2,0,
                                               0x1,1,(char)GfxRndSeed,(char)GfxRndSeed2,0,1);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed + 1,GfxRndSeed2,GfxRndSeed,GfxRndSeed2,3,
                                               0x1,1,(char)GfxRndSeed,(char)GfxRndSeed2,3,1);
                                    ovr_ovc15_usesLDIV_at_
                                              (GfxRndSeed + 1,GfxRndSeed2,GfxRndSeed,GfxRndSeed2,5,
                                               0x1,1,(char)GfxRndSeed,(char)GfxRndSeed2,5,1);
                                    AgntFlag1 = false;
                                    ovr_ovc41_usesAgnt_clear('\0');
                                    ovc42_drawTextRow("Force and fury meet magic spells as battles",
                                                      0);
                                    ovc42_drawTextRow(
                                                  "play out in the courtyards of mighty castles.",1)
                                    ;
                                    ovr_ovc40_usesCalcSeasonPalette('\x01');
                                    uVar3 = ovc42_usesMiceBlitRect(0xa0);
                                    if ((byte)uVar3 < 2) {
                                      ovr_ovc40_usesCalcSeasonPalette('\0');
                                      ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                                      ovc42_usesEntityCount();
                                      GfxRndSeed = 0x58;
                                      GfxRndSeed2 = 0x24;
                                      AgntFlag1 = false;
                                      ovr_ovc41_usesAgnt_clear('\0');
                                      ovc42_drawTextRow("Your people will fight bravely and work",0)
                                      ;
                                      ovc42_drawTextRow("hard. Your city will grow...",1);
                                      ovr_ovc40_usesCalcSeasonPalette('\x01');
                                      ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                                      uVar3 = ovc42_usesMiceBlitRect(0x32);
                                      if ((byte)uVar3 < 2) {
                                        ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                                        ovc42_usesGfxRndSeed();
                                        ovc42_drawTextRow("and grow...",2);
                                        AgntFlag1 = false;
                                        ovr_ovc41_usesAgnt_clear('\0');
                                        ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                                        uVar3 = ovc42_usesMiceBlitRect(0x32);
                                        if ((byte)uVar3 < 2) {
                                          ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                                          ovc42_usesGfxRndSeed();
                                          ovc42_drawTextRow("                     and grow...",2);
                                          AgntFlag1 = false;
                                          ovr_ovc41_usesAgnt_clear('\0');
                                          ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                                          uVar3 = ovc42_usesMiceBlitRect(100);
                                          if ((byte)uVar3 < 2) {
                                            ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                                            ovr_ovc40_usesCalcSeasonPalette('\0');
                                            ovc42_drawTextRow("But beware the evil Mindark, whose",0
                                                             );
                                            ovc42_drawTextRow(
                                                  "hordes destroyed your homeland long ago.",1);
                                            (*(uint8_t *)((uint8_t *)&(cmap_06.seg))) = uVar5;
                                            cmap_06.ofs = (uint16_t)&palette;
                                            (*(uint8_t *)((uint8_t *)&(cmap_06.seg) + 1)) = uVar9;
                                            ovc42_showAgentStats(0x29,bStack_3,'\x01',cmap_06,0);
                                            ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                                            MiceUnkState = 0;
                                            uVar6 = ovr_inputUpdate(0x78);
                                            if ((byte)uVar6 < 2) {
                                              ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
                                              (*(uint8_t *)((uint8_t *)&(palette_11.seg))) = uVar5;
                                              palette_11.ofs = (uint16_t)&palette;
                                              (*(uint8_t *)((uint8_t *)&(palette_11.seg) + 1)) = uVar9;
                                              ovr_ovc40_usesVgaSetPalette8bit(palette_11);
                                              bVar1 = ovr_ovc40_usesAlignToSeg
                                                                ('\x04',(char *)0x7174,0x2410,
                                                                 (char *)0x7174,
                                                                 0x2410,2,0x74,0x10,0x74,0x10);
                                              if (bVar1 < 2) {
                                                ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10)
                                                ;
                                                demoCenterX = 0x58;
                                                demoCenterY = 0x1e;
                                                bStack_7 = ovr_ovc30_textDivideError
                                                                     (0xb,1,'\x02',100,1,2);
                                                GfxRndSeed = demoCenterX;
                                                GfxRndSeed2 = demoCenterY + 2;
                                                ovc42_populateArea(bStack_4);
                                                ovr_ovc18_usesRandBelow
                                                          (GfxRndSeed - 1,GfxRndSeed2 - 2,0,bStack_7
                                                           ,(char)(GfxRndSeed2 - 2),0);
                                                ovr_ovc18_usesRandBelow
                                                          (GfxRndSeed,GfxRndSeed2 - 2,0,bStack_7,
                                                           (char)(GfxRndSeed2 - 2),0);
                                                ovr_ovc18_usesRandBelow
                                                          (GfxRndSeed + 1,GfxRndSeed2 - 2,0,bStack_7
                                                           ,(char)(GfxRndSeed2 - 2),0);
                                                ovr_ovc18_usesRandBelow
                                                          (GfxRndSeed - 2,GfxRndSeed2 - 2,0x8b,
                                                           bStack_7,(char)(GfxRndSeed2 - 2),0x8b);
                                                AgntFlag1 = false;
                                                ovr_ovc41_usesAgnt_clear('\0');
                                                ovr_ovc40_usesCalcSeasonPalette('\x01');
                                                ovc42_drawTextRow(
                                                  "If you lead with wisdom and cunning...",0);
                                                ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                                                uVar3 = ovc42_usesMiceBlitRect(0x3c);
                                                if ((byte)uVar3 < 2) {
                                                  GfxRndSeed2 = GfxRndSeed2 - 1;
                                                  AgntFlag1 = false;
                                                  ovr_ovc41_usesAgnt_clear('\0');
                                                  ovr_miceRestoreArea((brect_t *)(BlitRects + 1),
                                                                      0x10);
                                                  ovc42_drawTextRow(
                                                  "If you fight with valor and guile...",1);
                                                  ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                                                  uVar3 = ovc42_usesMiceBlitRect(0x3c);
                                                  if ((byte)uVar3 < 2) {
                                                    GfxRndSeed2 = GfxRndSeed2 - 1;
                                                    AgntFlag1 = false;
                                                    ovr_ovc41_usesAgnt_clear('\0');
                                                    ovr_miceRestoreArea((brect_t *)(BlitRects + 1),
                                                                        0x10);
                                                    ovc42_drawTextRow(
                                                  "You will truly be master of your...",2);
                                                  ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
                                                  uVar3 = ovc42_usesMiceBlitRect(0x3c);
                                                  if ((byte)uVar3 < 2) {
                                                    ovr_miceRestoreArea((brect_t *)(BlitRects + 1),
                                                                        0x10);
                                                    ovr_ovc40_usesCalcSeasonPalette('\0');
                                                    ovr_driver_fillRect(0,0,0x13f,199,0x0,0xa000,0,
                                                                        0x3f,199,0,0);
                                                    ovr_freeLeaderData();
                                                    bVar1 = 0x10;
                                                    (*(uint8_t *)((uint8_t *)&(gfx_00.seg))) = (char)sky06FliSeg;
                                                    gfx_00.ofs = sky06FliOfs;
                                                    (*(uint8_t *)((uint8_t *)&(gfx_00.seg) + 1)) =
                                                         (char)((uint)sky06FliSeg >> 8);
                                                    ovr_ovc43_playArchiveFli
                                                              (gfx_00,(uint16_t)&palette,
                                                               (char)&palette);
                                                    if (bVar1 < 2) {
                                                      (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) =
                                                           *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
                                                      uVar3 = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
                                                      (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = uVar3;
                                                      pcVar2 = ovc42_textProvidesMoreHousing(0x30);
                                                      if ((byte)pcVar2 < 2) {
                                                        (*(uint8_t *)((uint8_t *)&(palette_12.seg))) = uVar5;
                                                        palette_12.ofs = (uint16_t)&palette;
                                                        (*(uint8_t *)((uint8_t *)&(palette_12.seg) + 1)) = uVar9;
                                                        ovr_ovc40_usesVgaSetPalette8bit(palette_12);
                                                        (*(uint8_t *)((uint8_t *)&(handle_01.seg))) = (char)cred01Cut1Seg;
                                                        handle_01.ofs = cred01Cut1Ofs;
                                                        (*(uint8_t *)((uint8_t *)&(handle_01.seg) + 1)) =
                                                             (char)((uint)cred01Cut1Seg >> 8);
                                                        psStack_c = ovr_stshLoadGfx(handle_01);
                                                        uStack_a = uVar3;
                                                        memcpy((char *)CONCAT13(uVar9,CONCAT12(uVar5
                                                  ,&palette)),
                                                  (char *)CONCAT13((char)((uint)uVar3 >> 8),
                                                                   CONCAT12((char)uVar3,psStack_c)),
                                                  0x300);
                                                  ovr_driver_fillRect(0,0,0x13f,199,0x0,0xa000,0,
                                                                      0x3f,199,0,0);
                                                  (*(uint8_t *)((uint8_t *)&(gfx_02.seg))) = (char)cred01Cut2Seg;
                                                  gfx_02.ofs = cred01Cut2Ofs;
                                                  (*(uint8_t *)((uint8_t *)&(gfx_02.seg) + 1)) =
                                                       (char)((uint)cred01Cut2Seg >> 8);
                                                  ovr_blitLoadRleGfx(gfx_02,far_from_u32((uint32_t)(0xa0000000)),0);
                                                  (*(uint8_t *)((uint8_t *)&(palette_13.seg))) = uVar5;
                                                  palette_13.ofs = (uint16_t)&palette;
                                                  (*(uint8_t *)((uint8_t *)&(palette_13.seg) + 1)) = uVar9;
                                                  ovr_setSeasonPalette(palette_13);
                                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) =
                                                       *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2)
                                                  ;
                                                  uVar3 = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
                                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = uVar3;
                                                  uVar6 = ovr_inputUpdate(0xb4);
                                                  if ((byte)uVar6 < 2) {
                                                    (*(uint8_t *)((uint8_t *)&(palette_14.seg))) = uVar5;
                                                    palette_14.ofs = (uint16_t)&palette;
                                                    (*(uint8_t *)((uint8_t *)&(palette_14.seg) + 1)) = uVar9;
                                                    ovr_ovc40_usesVgaSetPalette8bit(palette_14);
                                                    (*(uint8_t *)((uint8_t *)&(handle_02.seg))) = (char)cred02Cut1Seg;
                                                    handle_02.ofs = cred02Cut1Ofs;
                                                    (*(uint8_t *)((uint8_t *)&(handle_02.seg) + 1)) =
                                                         (char)((uint)cred02Cut1Seg >> 8);
                                                    psStack_c = ovr_stshLoadGfx(handle_02);
                                                    uStack_a = uVar3;
                                                    memcpy((char *)CONCAT13(uVar9,CONCAT12(uVar5,&
                                                  palette)),
                                                  (char *)CONCAT13((char)((uint)uVar3 >> 8),
                                                                   CONCAT12((char)uVar3,psStack_c)),
                                                  0x300);
                                                  ovr_driver_fillRect(0,0,0x13f,199,0x0,0xa000,0,
                                                                      0x3f,199,0,0);
                                                  (*(uint8_t *)((uint8_t *)&(gfx_03.seg))) = (char)cred02Cut2Seg;
                                                  gfx_03.ofs = cred02Cut2Ofs;
                                                  (*(uint8_t *)((uint8_t *)&(gfx_03.seg) + 1)) =
                                                       (char)((uint)cred02Cut2Seg >> 8);
                                                  ovr_blitLoadRleGfx(gfx_03,far_from_u32((uint32_t)(0xa0000000)),0);
                                                  (*(uint8_t *)((uint8_t *)&(palette_15.seg))) = uVar5;
                                                  palette_15.ofs = (uint16_t)&palette;
                                                  (*(uint8_t *)((uint8_t *)&(palette_15.seg) + 1)) = uVar9;
                                                  ovr_setSeasonPalette(palette_15);
                                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) =
                                                       *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2)
                                                  ;
                                                  uVar3 = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
                                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = uVar3;
                                                  uVar6 = ovr_inputUpdate(0xb4);
                                                  if ((byte)uVar6 < 2) {
                                                    (*(uint8_t *)((uint8_t *)&(palette_16.seg))) = uVar5;
                                                    palette_16.ofs = (uint16_t)&palette;
                                                    (*(uint8_t *)((uint8_t *)&(palette_16.seg) + 1)) = uVar9;
                                                    ovr_ovc40_usesVgaSetPalette8bit(palette_16);
                                                    (*(uint8_t *)((uint8_t *)&(handle_03.seg))) = (char)cred03Cut1Seg;
                                                    handle_03.ofs = cred03Cut1Ofs;
                                                    (*(uint8_t *)((uint8_t *)&(handle_03.seg) + 1)) =
                                                         (char)((uint)cred03Cut1Seg >> 8);
                                                    psStack_c = ovr_stshLoadGfx(handle_03);
                                                    uStack_a = uVar3;
                                                    memcpy((char *)CONCAT13(uVar9,CONCAT12(uVar5,&
                                                  palette)),
                                                  (char *)CONCAT13((char)((uint)uVar3 >> 8),
                                                                   CONCAT12((char)uVar3,psStack_c)),
                                                  0x300);
                                                  ovr_driver_fillRect(0,0,0x13f,199,0x0,0xa000,0,
                                                                      0x3f,199,0,0);
                                                  (*(uint8_t *)((uint8_t *)&(gfx_04.seg))) = (char)cred03Cut2Seg;
                                                  gfx_04.ofs = cred03Cut2Ofs;
                                                  (*(uint8_t *)((uint8_t *)&(gfx_04.seg) + 1)) =
                                                       (char)((uint)cred03Cut2Seg >> 8);
                                                  ovr_blitLoadRleGfx(gfx_04,far_from_u32((uint32_t)(0xa0000000)),0);
                                                  (*(uint8_t *)((uint8_t *)&(palette_17.seg))) = uVar5;
                                                  palette_17.ofs = (uint16_t)&palette;
                                                  (*(uint8_t *)((uint8_t *)&(palette_17.seg) + 1)) = uVar9;
                                                  ovr_setSeasonPalette(palette_17);
                                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) =
                                                       *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2)
                                                  ;
                                                  (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) =
                                                       *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs)   /* hand fix: the offset half is the address, not the far_t struct */;
                                                  uVar6 = ovr_inputUpdate(0xb4);
                                                  if ((byte)uVar6 < 2) {
                                                    ovc42_endDemo('\0',(int)&palette,unaff_SS);
                                                    GameRunning = false;
                                                    CurMusicType = 0xff;
                                                    CurSfxType3 = 0xff;
                                                    uVar3 = 0x2400;
                                                  }
                                                  else {
                                                    puVar4 = &palette;
                                                    ovc42_endDemo('\x03',(int)puVar4,unaff_SS);
                                                    uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
                                                  }
                                                  }
                                                  else {
                                                    puVar4 = &palette;
                                                    ovc42_endDemo('\x03',(int)puVar4,unaff_SS);
                                                    uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
                                                  }
                                                  }
                                                  else {
                                                    puVar4 = &palette;
                                                    ovc42_endDemo('\x03',(int)puVar4,unaff_SS);
                                                    uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
                                                  }
                                                  }
                                                  else {
                                                    puVar4 = &palette;
                                                    ovc42_endDemo('\x03',(int)puVar4,unaff_SS);
                                                    uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
                                                  }
                                                  }
                                                  else {
                                                    puVar4 = &palette;
                                                    ovc42_endDemo('\x03',(int)puVar4,unaff_SS);
                                                    uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
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
                                                uVar5 = extraout_AH;
                                                ovc42_endDemo('\x02',0,0);
                                                uVar3 = CONCAT11(uVar5,1);
                                              }
                                            }
                                            else {
                                              puVar4 = &palette;
                                              ovc42_endDemo('\x01',(int)puVar4,unaff_SS);
                                              uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
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
                                    puVar4 = &palette;
                                    ovc42_endDemo('\x01',(int)puVar4,unaff_SS);
                                    uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
                                  }
                                }
                                else {
                                  puVar4 = &palette;
                                  ovc42_endDemo('\x01',(int)puVar4,unaff_SS);
                                  uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
                                }
                              }
                              else {
                                puVar4 = &palette;
                                ovc42_endDemo('\x01',(int)puVar4,unaff_SS);
                                uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
                              }
                            }
                            else {
                              puVar4 = &palette;
                              ovc42_endDemo('\x01',(int)puVar4,unaff_SS);
                              uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
                            }
                          }
                          else {
                            puVar4 = &palette;
                            ovc42_endDemo('\x01',(int)puVar4,unaff_SS);
                            uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
                          }
                        }
                        else {
                          puVar4 = &palette;
                          ovc42_endDemo('\x01',(int)puVar4,unaff_SS);
                          uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
                        }
                      }
                      else {
                        puVar4 = &palette;
                        ovc42_endDemo('\x01',(int)puVar4,unaff_SS);
                        uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
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
            puVar4 = &palette;
            ovc42_endDemo('\x03',(int)puVar4,unaff_SS);
            uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
          }
        }
        else {
          puVar4 = &palette;
          ovc42_endDemo('\x03',(int)puVar4,unaff_SS);
          uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
        }
      }
      else {
        puVar4 = &palette;
        ovc42_endDemo('\x03',(int)puVar4,unaff_SS);
        uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
      }
    }
    else {
      puVar4 = &palette;
      ovc42_endDemo('\x03',(int)puVar4,unaff_SS);
      uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
    }
  }
  else {
    puVar4 = &palette;
    ovc42_endDemo('\x03',(int)puVar4,unaff_SS);
    uVar3 = CONCAT11((char)((uint)puVar4 >> 8),1);
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


