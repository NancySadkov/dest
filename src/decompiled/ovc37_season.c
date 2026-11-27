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
    if (((GLeaderSheets[iVar1])->active != '\0') &&
       (*((char far *)GLeaderSheets[iVar1] + 0x3f) != '\0')) break;
    iVar1 = iVar1 + 1;
  }
  return false;
}



/* 67e7:004d */

/* [R2] string "halfling castle" */

uint __cdecl16far season_textHalflingCastle(uint8_t formatIndex)

{
  char_sheet_t far *sheet;
  bool isMain;
  byte extraout_AH;
  uint result;
  size_t sVar4;
  char *capText;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined1 retHi;
  uint8_t *capTextSeg;
  uint8_t *puVar7;
  ulong packed;
  uint8_t text;
  static char text2[64];   /* DGROUP-backed formatting buffer */
  int iStack_8;
  char mayContinue;
  byte leaderIdx;
  
  leaderIdx = ovr_manage_findFirstLeader();
  if (leaderIdx == 0xff) {
    result = (uint)extraout_AH << 8;
  }
  else {
    result = (uint16_t)SEG_OF(GLeaderSheets[leaderIdx]);
    sheet = GLeaderSheets[leaderIdx];
    iStack_8 = CONCAT22(result,far_ofs_u32(sheet));
    if (sheet->titleIndex < 9) {
      sheet->titleIndex = sheet->titleIndex + '\x01';
      strcpy((char *)CONCAT22(_SS,&text),
             (char *)CONCAT22(*(uint16_t *)
                               ((int)&GStatsLabels[4].seg +
                               (uint)sheet->titleIndex * 8 + (uint)sheet->gender * 4
                               ),(char *)((far_t *)(GStatsLabels + 4) +
                                         (uint)sheet->gender +
                                         (uint)sheet->titleIndex * 2)->ofs));
      sVar4 = strlen((char *)CONCAT22(_SS,&text));
      capTextSeg = &text;
      capTextSeg[sVar4 - 1] = 0x0;
      if ((GHighScoreSaved == '\0') &&
         ((((1 < PlayerIndex &&
            (capTextSeg = (uint8_t *)((char *)0x2627a),
            (GLeaderSheets[leaderIdx])->alignment == '\x02')) &&
           (isMain = season_textMainCastle(), isMain)) ||
          ((capTextSeg = (uint8_t *)((char *)0x2627a),
           8 < (GLeaderSheets[leaderIdx])->titleIndex &&
           ((capTextSeg = (uint8_t *)((char *)0x2627a),
            (GLeaderSheets[leaderIdx])->alignment == '\0' ||
            ((capTextSeg = (uint8_t *)((char *)0x2627a),
             (GLeaderSheets[leaderIdx])->alignment == '\x01' &&
             (isMain = season_textMainCastle(), isMain)))))))))) {
        mayContinue = '\x01';
      }
      else {
        mayContinue = '\0';
      }
      if (mayContinue == '\0') {
        packed = (ulong)CONCAT12(formatIndex,_SS);
        puVar7 = &text;
        capText = ovr_ovc15_capitalize(text2);
        ovr_ovc40_usesAlignToSeg
                  ('\0',capText,(uint16_t)capTextSeg,(char *)puVar7,(uint16_t)packed,(byte)(packed >> 0x10),0,0,0,0);
        retHi = extraout_AH_01;
      }
      else {
        packed = (ulong)CONCAT12(formatIndex,_SS);
        puVar7 = &text;
        capText = ovr_ovc15_capitalize(text2);
        ovr_ovc40_usesAlignToSeg
                  ('\x02',capText,(uint16_t)capTextSeg,(char *)puVar7,(uint16_t)packed,(byte)(packed >> 0x10),0,0,0,0);
        retHi = extraout_AH_00;
      }
      if (mayContinue != '\0') {
        ovr_stop_audio();
        CurMusicType = 0x54;
        ovr_play_sfx(84,0,0);
        ovr_ovc38_usesStshAlloc();
        ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0);
        ovr_stats_drawStatsPanel();
        ovr_say((char *)"Your may continue playing, but your score will not be recorded.",0);
        ovr_ovc38_showAchievements();
        ovr_ovc28_textHalflingCastle();
        ovr_ovc41_usesGMenuItem();
        ovr_miceBlitRect((brect_t *)(BlitRects + 1),0);
        ovr_stop_audio();
        retHi = 0x24;
        CurMusicType = 0xff;
      }
      result = CONCAT11(retHi,1);
    }
    else {
      result = result & 0xff00;
    }
  }
  return result;
}



/* 67e7:026a */

/* Runs the end-of-game score screen once per leader-type band. */

uint __cdecl16far season_checkEndGame(byte leaderIndex)

{
  byte bandIndex;
  uint uVar2;
  
  if (*(char *)((int)*(uint32_t *)((uint)leaderIndex << 2) + 0x3f) == '\0') {
    uVar2 = 0;
  }
  else {
    bandIndex = ovr_ovc30_compute1(*(byte *)((int)&worldMenuLabels[0xc].seg +
                                        (uint)(GLeaderSheets[leaderIndex])->classStr * 0x95));
    if (bandIndex < 2) {
      if (((byte *)promotionBandUsed)[bandIndex] != 0) {
        return 0;
      }
      ((byte *)promotionBandUsed)[bandIndex] = 1;
    }
    uVar2 = season_textHalflingCastle(0x0);
  }
  return uVar2;
}



/* 67e7:030a */

/* Recomputes GPromotableCount by counting the units whose four map-flag words OR to 0x1000. */

void __cdecl16far season_countPromotable(void)

{
  /* Re-derived: every unit from index 0xf8 upwards that is promotable.  A unit is
     promotable when its building's flag word at 0x121 has both bits 0x60 clear, its
     unitType is not 0xff, its leader sheet's byte at +0x3f is clear, and the four map
     flag words to its right OR together to exactly 0x1000. */
  unit_t *units;
  uint32_t sheetRef;
  uint alignedX;
  uint flagAcc;
  uint unitIdx;
  int k;

  GPromotableCount = 0;
  for (unitIdx = 0xf8; unitIdx < GUnitCount; unitIdx = unitIdx + 1) {
    units = GUnits;
    if ((((BuildingTypes[(uint)(units + unitIdx)->bldType].flags2 & 0x60) == 0) &&
        (units[unitIdx].unitType != 0xff)) &&
       (sheetRef = *(uint32_t *)((uint)units[unitIdx].unitType << 2),
        *(char *)((int)sheetRef + 0x3f) == '\0')) {
      alignedX = ovr_alignUp4(units[unitIdx].x,0,0);
      flagAcc = 0;
      for (k = 0; k < 4; k = k + 1) {
        flagAcc = flagAcc |
                  ((short (*) [60] [148])GMapFlags)[-1][units[unitIdx].y + 0x3b]
                  [alignedX + k + 0x92] & 0x3000U;
      }
      if (flagAcc == 0x1000) {
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
  if ((bVar1 != 0xff) && ((GLeaderSheets[bVar1])->titleIndex < 9)) {
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
    if (*((uint8_t far *)GLeaderSheets[bVar1] + 0x86) < 9) {
      iVar2 = (uint)promotionCount * 0x32 + 0x32;
    }
  }
  return iVar2;
}



/* 67e7:04e5 */

/* [R6] touches Difficulty */

char __cdecl16far season_usesDifficulty(void)

{
  char_sheet_t far *sheet;
  byte leaderIdx;
  char grade;
  
  leaderIdx = ovr_manage_findFirstLeader();
  if (leaderIdx == 0xff) {
    grade = 'd';
  }
  else {
    sheet = GLeaderSheets[leaderIdx];
    if (sheet->titleIndex < 9) {
      if (Difficulty == '\x01') {
        if (sheet->titleIndex < 5) {
          grade = sheet->titleIndex * '\x02' + '5';
        }
        else {
          grade = sheet->titleIndex + '9';
        }
      }
      else if (Difficulty == '\x02') {
        grade = sheet->titleIndex * '\x02' + '5';
      }
      else {
        grade = sheet->titleIndex * '\x03' + '4';
      }
    }
    else {
      grade = 'd';
    }
  }
  return grade;
}



/* 67e7:058d */

uint16_t __cdecl16far
calcSeasonPalette(uint8_t *srcOfs,uint16_t srcSeg,uint8_t *dstOfs,uint16_t dstSeg,uint16_t arg5,uint16_t arg6)

{
  far_t dst;
  far_t dst_00;
  far_t dst_01;
  far_t dst_02;
  far_t handle;
  uint16_t uVar1;
  uint8_t seasonPalette;
  uint16_t uStack_18;
  uint16_t uStack_16;
  byte bStack_13;
  uint8_t colorC;
  uint8_t colorB;
  uint8_t colorA;
  stg_tmp_t *psStack_6;
  uint16_t uStack_4;
  
  dst.seg = _SS;
  dst.ofs = (uint16_t)&seasonPalette;
  F_SCOPY(far_from_u32((uint32_t)(0x2410693b)),dst,135);
  dst_00.seg = _SS;
  dst_00.ofs = (uint16_t)&colorA;
  F_SCOPY(far_from_u32((uint32_t)(0x241069c2)),dst_00,3);
  dst_01.seg = _SS;
  dst_01.ofs = (uint16_t)&colorB;
  F_SCOPY(far_from_u32((uint32_t)(0x241069c5)),dst_01,3);
  dst_02.seg = _SS;
  dst_02.ofs = (uint16_t)&colorC;
  F_SCOPY(far_from_u32((uint32_t)(0x241069c8)),dst_02,3);
  _fmemmove((char far *)MK_FP(dstSeg,dstOfs),(char far *)MK_FP(srcSeg,srcOfs),0x300);
  uStack_16 = ((uint16_t *)&l1Cut2Seg)[((uint)seasonGroupBase + (uint)GSeason) * 2];
  uVar1 = ((uint16_t *)&l1Cut2Ofs)[((uint)seasonGroupBase + (uint)GSeason) * 2];
  handle.seg = uStack_16;
  handle.ofs = uVar1;
  uStack_18 = uVar1;
  psStack_6 = ovr_stshLoadGfx(handle);
  uStack_4 = uVar1;
  _fmemmove((char far *)MK_FP(dstSeg,dstOfs + 0x1e0),(char far *)MK_FP(uVar1,psStack_6),0x90);
  _fmemmove((char far *)MK_FP(dstSeg,dstOfs + 0x2d0),
            (char far *)MK_FP(_SS,&seasonPalette + (uint)GSeason * 0x2d),0x2d);
  if (GameRunning == false) {
    _fmemmove((char far *)MK_FP(dstSeg,dstOfs + 0x2ac),(char far *)MK_FP(_SS,&colorA),3);
    _fmemmove((char far *)MK_FP(dstSeg,dstOfs + 0x2af),(char far *)MK_FP(_SS,&colorA),3);
    _fmemmove((char far *)MK_FP(dstSeg,dstOfs + 0x2b2),(char far *)MK_FP(_SS,&colorB),3);
    _fmemmove((char far *)MK_FP(dstSeg,dstOfs + 0x2b5),(char far *)MK_FP(_SS,&colorB),3);
    _fmemmove((char far *)MK_FP(dstSeg,dstOfs + 0x2be),(char far *)MK_FP(_SS,&colorC),3);
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
  far_t dst;
  far_t handle;
  far_t palette_00;
  far_t handle_00;
  far_t palette_01;
  uint8_t palette [768];
  char snames [12];
  static char text[64];   /* DGROUP-backed formatting buffer */
  stg_tmp_t *gfxRec;
  char *pcStack_6;
  uint8_t s;
  uint8_t season;
  
  dst.seg = (uint16_t)_SS;
  dst.ofs = (uint16_t)snames;
  F_SCOPY(far_from_u32((uint32_t)(0x241069cb)),dst,12);
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
    gfxRec = ovr_stshLoadGfx(handle);
    calcSeasonPalette(gfxRec->cmap,(uint16_t)in_DX,palette,(uint16_t)_SS,0,0);
    palette_00.seg = (uint16_t)_SS;
    palette_00.ofs = (uint16_t)palette;
    ovr_ovc40_usesVgaSetPalette8bit(palette_00);
    ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0);
    GSeason = season;
    ovr_ovc41_usesAgnt_clear('\0');
    ovr_miceBlitRect((brect_t *)(BlitRects + 1),0);
    if ((season == 0x0) && (GTimeLo == 0xf)) {
      ovr_uiNotify((char *)"The season has changed to summer.",0x2410,0);
    }
    else {
      in_DX = snames;
      msg = ovr_stsprintf(text,(char *)CONCAT22(0x6a50,_SS),
                          (char *)CONCAT22(*(uint16_t *)(in_DX + (uint)season * 4),
                                           (char *)0x26510),
                          *(uint16_t *)(snames + (uint)season * 4 + 2));
      ovr_uiNotify(msg,(uint16_t)in_DX,0);
    }
    handle_00.seg = Lbm_nwpanel1.seg;
    handle_00.ofs = Lbm_nwpanel1.ofs;
    gfxRec = ovr_stshLoadGfx(handle_00);
    pcStack_6 = in_DX;
    calcSeasonPalette(gfxRec->cmap,(uint16_t)in_DX,palette,(uint16_t)_SS,0,0);
    palette_01.seg = (uint16_t)_SS;
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
  /* Re-derived (67e7:09b9): 1 when the four map-flag words to the right of the unit's cell
     OR to exactly 0x1000 << (party sheet byte 0x3f), else 0.  The tail writes only AL
     (mov al,1 at 0x5A6C2, mov al,0 at 0x5A6C6), so the exported CONCAT11 / <<8 values were
     stale-AH artifacts of that shift. */
  uint alignedX;
  uint flags;
  uint expected;
  int k;

  alignedX = ovr_alignUp4((GUnits)[unitIndex].x,0,0);
  flags = 0;
  for (k = 0; k < 4; k = k + 1) {
    flags = flags |
            ((short (*) [60] [148])GMapFlags)[-1][(GUnits)[unitIndex].y + 0x3b]
            [alignedX + k + 0x92] & 0x3000U;
  }
  expected = 0x1000 << (*((byte far *)GLeaderSheets[partyIndex] + 0x3f) & 0x1f);
  if (expected == flags) {
    return 1;
  }
  return 0;
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
  static char text[64];   /* DGROUP-backed formatting buffer */
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
        if ((GUnits)[unitIndex].unitType == bStack_7) {
          dst = (char *)0x26510;
          if ((GUnits)[unitIndex].level < 8) {
            iVar1 = season_usesAlignUp42(unitIndex,bStack_7);
            if ((char)iVar1 != '\0') {
              dst = (char *)0x26510;
              (GUnits)[unitIndex].level = 8;
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
    msg = ovr_stsprintf(text,(char *)CONCAT22(0x6a6e,_SS),
                        (char *)CONCAT22(count,(char *)0x26510),uVar2,dst);
    ovr_uiNotify(msg,(uint16_t)dst,0);
  }
  return;
}


