/*
 * ovc37_season.c - recovered from STRONG.EXE
 * memory block: OVC37_season.c
 * range: 67e7:0000 - 67e7:0c4f
 * functions: 11
 */
#include "recovered.h"


/* 67e7:0000 */

/* [R2] string "main castle" */

bool __cdecl16far season_textMainCastle(void)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if ((int)(uint)GLeaderCount <= iVar1) {
      return true;
    }
    if ((((char_sheet_t *)((iVar1 << 2)))->active != '\0') &&
       (*(char *)((int)*(uint32_t *)(iVar1 << 2) + 0x3f) != '\0')) break;
    iVar1 = iVar1 + 1;
  }
  return false;
}



/* 67e7:004d */

/* [R2] string "halfling castle" */

uint __cdecl16far season_textHalflingCastle(uint8_t formatIndex,...)

{
  int iVar1;
  bool bVar2;
  byte extraout_AH;
  uint uVar3;
  size_t sVar4;
  char *pcVar5;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined1 uVar6;
  uint8_t *capTextSeg;
  uint16_t unaff_SS;
  uint8_t *puVar7;
  ulong uVar8;
  uint8_t text;
  uint8_t text2;
  int iStack_8;
  uint uStack_6;
  char cStack_4;
  byte bStack_3;
  
  bStack_3 = ovr_manage_findFirstLeader();
  if (bStack_3 == 0xff) {
    uVar3 = (uint)extraout_AH << 8;
  }
  else {
    uVar3 = ((int *)((uint)bStack_3 * 4))[1];
    iVar1 = *(int *)((uint)bStack_3 * 4);
    iStack_8 = CONCAT22(uVar3,iVar1);
    if (*(byte *)(iVar1 + 0x86) < 9) {
      *(char *)(iVar1 + 0x86) = *(char *)(iVar1 + 0x86) + '\x01';
      strcpy((char *)CONCAT22(unaff_SS,&text),
             (char *)CONCAT22(*(uint16_t *)
                               ((int)&GStatsLabels[4].seg +
                               (uint)*(byte *)(iVar1 + 0x86) * 8 + (uint)*(byte *)(iVar1 + 0x34) * 4
                               ),(char *)((far_t *)(GStatsLabels + 4) +
                                         (uint)*(byte *)(iVar1 + 0x34) +
                                         (uint)*(byte *)(iVar1 + 0x86) * 2)->ofs));
      sVar4 = strlen((char *)CONCAT22(unaff_SS,&text));
      capTextSeg = &text;
      capTextSeg[sVar4 - 1] = 0x0;
      if ((GHighScoreSaved == '\0') &&
         ((((1 < PlayerIndex &&
            (capTextSeg = (uint8_t *)((char *)0x2627a),
            ((char_sheet_t *)(((uint)bStack_3 << 2)))->alignment == '\x02')) &&
           (bVar2 = season_textMainCastle(), bVar2)) ||
          ((capTextSeg = (uint8_t *)((char *)0x2627a),
           8 < ((char_sheet_t *)(((uint)bStack_3 << 2)))->titleIndex &&
           ((capTextSeg = (uint8_t *)((char *)0x2627a),
            ((char_sheet_t *)(((uint)bStack_3 << 2)))->alignment == '\0' ||
            ((capTextSeg = (uint8_t *)((char *)0x2627a),
             ((char_sheet_t *)(((uint)bStack_3 << 2)))->alignment == '\x01' &&
             (bVar2 = season_textMainCastle(), bVar2)))))))))) {
        cStack_4 = '\x01';
      }
      else {
        cStack_4 = '\0';
      }
      if (cStack_4 == '\0') {
        uVar8 = (ulong)CONCAT12(formatIndex,unaff_SS);
        puVar7 = &text;
        pcVar5 = ovr_ovc15_capitalize((char *)&text2);
        ovr_ovc40_usesAlignToSeg
                  ('\0',pcVar5,(uint16_t)capTextSeg,(char *)puVar7,(uint16_t)uVar8,
                   (byte)(uVar8 >> 0x10));
        uVar6 = extraout_AH_01;
      }
      else {
        uVar8 = (ulong)CONCAT12(formatIndex,unaff_SS);
        puVar7 = &text;
        pcVar5 = ovr_ovc15_capitalize((char *)&text2);
        ovr_ovc40_usesAlignToSeg
                  ('\x02',pcVar5,(uint16_t)capTextSeg,(char *)puVar7,(uint16_t)uVar8,
                   (byte)(uVar8 >> 0x10));
        uVar6 = extraout_AH_00;
      }
      if (cStack_4 != '\0') {
        ovr_stop_audio();
        CurMusicType = 0x54;
        ovr_play_sfx(84,0);
        ovr_ovc38_usesStshAlloc();
        ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
        ovr_stats_drawStatsPanel();
        ovr_say((char *)"Your may continue playing, but your score will not be recorded.");
        ovr_ovc38_showAchievements();
        ovr_ovc28_textHalflingCastle();
        ovr_ovc41_usesGMenuItem();
        ovr_miceBlitRect((brect_t *)(BlitRects + 1));
        ovr_stop_audio();
        uVar6 = 0x24;
        CurMusicType = 0xff;
      }
      uVar3 = CONCAT11(uVar6,1);
    }
    else {
      uVar3 = uVar3 & 0xff00;
    }
  }
  return uVar3;
}



/* 67e7:026a */

/* Runs the end-of-game score screen once per leader-type band. */

uint __cdecl16far season_checkEndGame(byte leaderIndex,...)

{
  byte bVar1;
  uint uVar2;
  
  if (*(char *)((int)*(uint32_t *)((uint)leaderIndex << 2) + 0x3f) == '\0') {
    uVar2 = 0;
  }
  else {
    bVar1 = ovr_ovc30_compute1(*(byte *)((int)&worldMenuLabels[0xc].seg +
                                        (uint)((char_sheet_t *)(((uint)leaderIndex << 2)))->classStr * 0x95));
    if (bVar1 < 2) {
      if (((byte *)promotionBandUsed)[bVar1] != 0) {
        return 0;
      }
      ((byte *)promotionBandUsed)[bVar1] = 1;
    }
    uVar2 = season_textHalflingCastle(0x0);
  }
  return uVar2;
}



/* 67e7:030a */

/* Recomputes GPromotableCount by counting the units whose four map-flag words OR to 0x1000. */

void __cdecl16far season_countPromotable(void)

{
  uint32_t uVar1;
  uint uVar2;
  unit_t *puVar3;
  int iVar4;
  uint uVar5;
  uint16_t uVar6;
  uint uStack_6;
  
  GPromotableCount = 0;
  for (uStack_6 = 0xf8; uStack_6 < GUnitCount; uStack_6 = uStack_6 + 1) {
    uVar6 = (uint16_t)((ulong)GUnits >> 0x10);
    puVar3 = (unit_t *)GUnits;
    if ((((*(uint *)((uint)(puVar3 + uStack_6)->bldType * 0x27 + 0x121) & 0x60) == 0) &&
        (puVar3[uStack_6].unitType != 0xff)) &&
       (uVar1 = *(uint32_t *)((uint)puVar3[uStack_6].unitType << 2),
       *(char *)((int)uVar1 + 0x3f) == '\0')) {
      uVar2 = ovr_alignUp4(puVar3[uStack_6].x);
      uVar5 = 0;
      for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
        uVar5 = uVar5 | ((short (*) [60] [148])GMapFlags)[-1][((unit_t *)GUnits)[uStack_6].y + 0x3b]
                        [uVar2 + iVar4 + 0x92] & 0x3000U;
      }
      if (uVar5 == 0x1000) {
        GPromotableCount = GPromotableCount + 1;
      }
    }
  }
  return;
}



/* 67e7:042b */

/* [R6] touches GPromotableCount */

void __cdecl16far season_usesGPromotableCount(void)

{
  byte bVar1;
  uint uVar2;
  
  season_countPromotable();
  bVar1 = ovr_manage_findFirstLeader();
  if ((bVar1 != 0xff) && (((char_sheet_t *)(((uint)bVar1 << 2)))->titleIndex < 9)) {
    uVar2 = ovr_manage_usesGLeaderCount();
    bVar1 = season_usesDifficulty();
    if (bVar1 <= uVar2) {
      uVar2 = season_usesGPromotableCount2();
      if (uVar2 <= GPromotableCount) {
        uVar2 = season_textHalflingCastle(0x1);
        if ((char)uVar2 != '\0') {
          promotionCount = promotionCount + '\x01';
        }
      }
    }
  }
  return;
}



/* 67e7:048f */

/* [R6] touches GPromotableCount */

int __cdecl16far season_usesGPromotableCount2(void)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = ovr_manage_findFirstLeader();
  if (bVar1 == 0xff) {
    iVar2 = 0;
  }
  else {
    iVar2 = GPromotableCount;
    if (*(byte *)(*(int *)((uint)bVar1 * 4) + 0x86) < 9) {
      iVar2 = (uint)promotionCount * 0x32 + 0x32;
    }
  }
  return iVar2;
}



/* 67e7:04e5 */

/* [R6] touches Difficulty */

char __cdecl16far season_usesDifficulty(void)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  char cVar4;
  
  bVar3 = ovr_manage_findFirstLeader();
  if (bVar3 == 0xff) {
    cVar4 = 'd';
  }
  else {
    iVar1 = ((int *)((uint)bVar3 * 4))[1];
    iVar2 = *(int *)((uint)bVar3 * 4);
    if (*(byte *)(iVar2 + 0x86) < 9) {
      if (Difficulty == '\x01') {
        if (*(byte *)(iVar2 + 0x86) < 5) {
          cVar4 = *(char *)(iVar2 + 0x86) * '\x02' + '5';
        }
        else {
          cVar4 = *(char *)(iVar2 + 0x86) + '9';
        }
      }
      else if (Difficulty == '\x02') {
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
calcSeasonPalette(uint8_t *srcOfs,uint16_t srcSeg,uint8_t *dstOfs,uint16_t dstSeg,...)

{
  far_t dst;
  far_t dst_00;
  far_t dst_01;
  far_t dst_02;
  far_t handle;
  uint16_t uVar1;
  uint16_t unaff_SS;
  uint8_t seasonPalette;
  uint16_t uStack_18;
  uint16_t uStack_16;
  byte bStack_13;
  uint8_t colorC;
  uint8_t colorB;
  uint8_t colorA;
  stg_tmp_t *psStack_6;
  uint16_t uStack_4;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&seasonPalette;
  F_SCOPY(far_from_u32((uint32_t)(0x2410693b)),dst);
  dst_00.seg = unaff_SS;
  dst_00.ofs = (uint16_t)&colorA;
  F_SCOPY(far_from_u32((uint32_t)(0x241069c2)),dst_00);
  dst_01.seg = unaff_SS;
  dst_01.ofs = (uint16_t)&colorB;
  F_SCOPY(far_from_u32((uint32_t)(0x241069c5)),dst_01);
  dst_02.seg = unaff_SS;
  dst_02.ofs = (uint16_t)&colorC;
  F_SCOPY(far_from_u32((uint32_t)(0x241069c8)),dst_02);
  _fmemmove((char *)CONCAT22(dstSeg,dstOfs),(char *)CONCAT22(srcSeg,srcOfs),0x300);
  uStack_16 = ((uint16_t *)&l1Cut2Seg)[((uint)seasonGroupBase + (uint)GSeason) * 2];
  uVar1 = ((uint16_t *)&l1Cut2Ofs)[((uint)seasonGroupBase + (uint)GSeason) * 2];
  handle.seg = uStack_16;
  handle.ofs = uVar1;
  uStack_18 = uVar1;
  psStack_6 = ovr_stshLoadGfx(handle);
  uStack_4 = uVar1;
  _fmemmove((char *)CONCAT22(dstSeg,dstOfs + 0x1e0),(char *)CONCAT22(uVar1,psStack_6),0x90);
  _fmemmove((char *)CONCAT22(dstSeg,dstOfs + 0x2d0),
            (char *)CONCAT22(unaff_SS,&seasonPalette + (uint)GSeason * 0x2d),0x2d);
  if (GameRunning == false) {
    _fmemmove((char *)CONCAT22(dstSeg,dstOfs + 0x2ac),(char *)CONCAT22(unaff_SS,&colorA),3);
    _fmemmove((char *)CONCAT22(dstSeg,dstOfs + 0x2af),(char *)CONCAT22(unaff_SS,&colorA),3);
    _fmemmove((char *)CONCAT22(dstSeg,dstOfs + 0x2b2),(char *)CONCAT22(unaff_SS,&colorB),3);
    _fmemmove((char *)CONCAT22(dstSeg,dstOfs + 0x2b5),(char *)CONCAT22(unaff_SS,&colorB),3);
    _fmemmove((char *)CONCAT22(dstSeg,dstOfs + 0x2be),(char *)CONCAT22(unaff_SS,&colorC),3);
  }
  for (bStack_13 = 0; bStack_13 < 0x2d; bStack_13 = bStack_13 + 1) {
    dstOfs[bStack_13 + 0x2d0] = (uint8_t)((int)(uint)dstOfs[bStack_13 + 0x2d0] >> 2);
  }
  return uStack_18;
}



/* 67e7:073e */

void __cdecl16far updSeason(void)

{
  char *msg;
  char *in_DX;
  char *unaff_SS;
  far_t dst;
  far_t handle;
  far_t palette_00;
  far_t handle_00;
  far_t palette_01;
  uint8_t palette [768];
  char snames [12];
  uint8_t text;
  uint8_t seaon2;
  stg_tmp_t *psStack_8;
  char *pcStack_6;
  uint8_t s;
  uint8_t season;
  
  dst.seg = (uint16_t)unaff_SS;
  dst.ofs = (uint16_t)snames;
  F_SCOPY(far_from_u32((uint32_t)(0x241069cb)),dst);
  seaon2 = GSeason;
  season = GSeason;
  GTimeLo = GTimeLo + 1;
  if (((GTimeHi != '\0') && (GSeason == 0x0)) && (GTimeLo < 0xf)) {
    GTimeLo = 0xf;
    GTimeHi = '\0';
  }
  if (GSeason == 0x0) {
    if ((GTimeHi != '\0') || (0x1d < GTimeLo)) {
      season = 0x1;
      GTimeLo = 0;
    }
  }
  else if ((GTimeHi != '\0') || (0xe < GTimeLo)) {
    season = GSeason + 0x1;
    GTimeLo = 0;
  }
  if (2 < season) {
    season = 0x0;
  }
  if ((GSeason != season) || ((season == 0x0 && (GTimeLo == 0xf)))) {
    if ((season == 0x0) && (GTimeLo == 0)) {
      GYear = GYear + 1;
    }
    handle.seg = Lbm_nwpanel1.seg;
    handle.ofs = Lbm_nwpanel1.ofs;
    psStack_8 = ovr_stshLoadGfx(handle);
    calcSeasonPalette(psStack_8->cmap,(uint16_t)in_DX,palette,(uint16_t)unaff_SS);
    palette_00.seg = (uint16_t)unaff_SS;
    palette_00.ofs = (uint16_t)palette;
    ovr_ovc40_usesVgaSetPalette8bit(palette_00);
    ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
    GSeason = season;
    ovr_ovc41_usesAgnt_clear('\0');
    ovr_miceBlitRect((brect_t *)(BlitRects + 1));
    if ((season == 0x0) && (GTimeLo == 0xf)) {
      ovr_uiNotify((char *)"The season has changed to summer.",0x2410);
    }
    else {
      in_DX = snames;
      msg = ovr_stsprintf((char *)&text,(char *)CONCAT22(0x6a50,unaff_SS),
                          (char *)CONCAT22(*(uint16_t *)(in_DX + (uint)season * 4),
                                           (char *)0x26510),
                          *(uint16_t *)(snames + (uint)season * 4 + 2));
      ovr_uiNotify(msg,(uint16_t)in_DX);
    }
    handle_00.seg = Lbm_nwpanel1.seg;
    handle_00.ofs = Lbm_nwpanel1.ofs;
    psStack_8 = ovr_stshLoadGfx(handle_00);
    pcStack_6 = in_DX;
    calcSeasonPalette(psStack_8->cmap,(uint16_t)in_DX,palette,(uint16_t)unaff_SS);
    palette_01.seg = (uint16_t)unaff_SS;
    palette_01.ofs = (uint16_t)palette;
    ovr_setSeasonPalette(palette_01);
    GTimeHi = '\0';
    if ((season == 0x0) && (GTimeLo == 0xf)) {
      s = 0x1;
    }
    else if (season == 0x0) {
      s = 0x0;
    }
    else {
      s = season + 0x1;
    }
    season_repairBuildings(s);
    if (PlayerCount < 100) {
      if (Difficulty == '\x01') {
        if (s == 0x0) {
          PlayerCount = PlayerCount + 1;
        }
      }
      else if (Difficulty == '\x03') {
        PlayerCount = PlayerCount + 1;
      }
      else if ((s & 1) != 0) {
        PlayerCount = PlayerCount + 1;
      }
    }
  }
  return;
}



/* 67e7:09b9 */

/* [R4] calls ovr_alignUp4 */

int __cdecl16far season_usesAlignUp42(int unitIndex,byte partyIndex)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = ovr_alignUp4(((unit_t *)GUnits)[unitIndex].x);
  uVar4 = 0;
  for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
    uVar4 = uVar4 | ((short (*) [60] [148])GMapFlags)[-1][((unit_t *)GUnits)[unitIndex].y + 0x3b]
                    [uVar1 + iVar3 + 0x92] & 0x3000U;
  }
  uVar1 = 0x1000 << (*(byte *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x3f) & 0x1f);
  bVar2 = (byte)(uVar1 >> 8);
  if (uVar1 == uVar4) {
    iVar3 = CONCAT11(bVar2,1);
  }
  else {
    iVar3 = (uint)bVar2 << 8;
  }
  return iVar3;
}



/* 67e7:0a5c */

/* Runs the building repair pass and reports how many buildings were repaired. */

void __cdecl16far season_repairBuildings(byte rank)

{
  int iVar1;
  char *msg;
  char *dst;
  uint unitIndex;
  int count;
  uint16_t uVar2;
  char *unaff_SS;
  uint8_t text;
  byte bStack_7;
  uint8_t promoteThreshold;
  byte abStack_4 [2];
  
  memcpy(&abStack_4, &((*(uint16_t *)((uint8_t *)&(PromoteThreshold) + 2))), 2);
  promoteThreshold = (*(uint16_t *)((uint8_t *)&(PromoteThreshold)));
  count = 0;
  dst = (char *)(*(uint16_t *)((uint8_t *)&(PromoteThreshold)));
  for (bStack_7 = 0; bStack_7 < GLeaderCount; bStack_7 = bStack_7 + 1) {
    dst = (char *)((uint)bStack_7 << 2);
    if ((&promoteThreshold)[rank] <= *(byte *)((int)*(uint32_t *)dst + 0xa5)) {
      for (unitIndex = 0xf8; unitIndex < GUnitCount; unitIndex = unitIndex + 1) {
        dst = (char *)0x26510;
        uVar2 = (uint16_t)((ulong)GUnits >> 0x10);
        if (((unit_t *)GUnits)[unitIndex].unitType == bStack_7) {
          dst = (char *)0x26510;
          if (((unit_t *)GUnits)[unitIndex].level < 8) {
            iVar1 = season_usesAlignUp42(unitIndex,bStack_7);
            if ((char)iVar1 != '\0') {
              dst = (char *)0x26510;
              ((unit_t *)GUnits)[unitIndex].level = 8;
              count = count + 1;
            }
          }
        }
      }
    }
  }
  if (count != 0) {
    ovr_inputUpdate(0x24);
    uVar2 = ovr_ovc41_pluralSuffix(count);
    msg = ovr_stsprintf((char *)&text,(char *)CONCAT22(0x6a6e,unaff_SS),
                        (char *)CONCAT22(count,(char *)0x26510),uVar2,dst);
    ovr_uiNotify(msg,(uint16_t)dst);
  }
  return;
}


