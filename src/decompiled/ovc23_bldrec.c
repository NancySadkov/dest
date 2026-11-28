/*
 * ovc23_bldrec.c - recovered from STRONG.EXE
 * memory block: OVC23_bldrec.c
 * range: 55fe:0000 - 55fe:345d
 * functions: 26
 */
#include "recovered.h"


/* 55fe:0000 */

/* Cursor scan for a building site: accumulates the four map-flag words to the right of the cursor,
   clears the per-record "already visited" mask, then walks the record list looking for a record that
   matches the cursor's column so the placement outline can be drawn.

   GUESS (recorded per AGENTS.md): two DGROUP areas this function touches have no symbol in the
   audit table - the 8-byte mask at 0x91d7 (filled with 0xff at 0x0066) and the 4-byte buffer at
   0x90ea (zeroed at 0x0076).  They are named here by address rather than through a recovered symbol.
   `cursorRecordFound` at 0x91d6 does have a symbol and is used normally. */
uint16_t __cdecl16far ovc23_textAdlibNone(void)

{
  uint16_t flags;
  int alignedX;
  int i;
  int record;
  int d;
  int si;
  byte colOfs;
  int idx;
  byte unitType;
  byte bldType;
  byte sfx;
  uint16_t kindSum;
  byte minLevel;
  byte sameSfx;
  int col;
  byte mapClass;

  flags = 0;
  alignedX = (int)ovr_alignUp4((uint16_t)GfxRndSeed);
  for (i = 0; i < 4; i++) {
    flags = (uint16_t)(flags |
                       (((short (*)[148])GMapFlags)[GfxRndSeed2][alignedX + i - 2] & 0x3000));
  }

  cursorRecordFound = 0;
  _fmemset((void far *)MK_FP(0x280,0x91d7),0xff,8);
  _fmemset((void far *)MK_FP(_DS,0x90ea),0,4);

  for (record = 0; (uint16_t)record < GRecordCount; record++) {
    /* The 0x12-stride record list lives at segment 0x88; the image compares its word at +4 with
       GfxRndSeed2, tests bit 0 of the byte at +0xd and reads the byte at +7 into [bp-4]. */
    if (((short (*)[0x12])MK_FP(0x88,0))[record][2] != (int)GfxRndSeed2) {
      continue;
    }
    if ((((byte (*)[0x12])MK_FP(0x88,0))[record][13] & 1) == 0) {
      continue;
    }
    colOfs = ((byte (*)[0x12])MK_FP(0x88,0))[record][7];
    /* 0x00d5..0x0180: place this record's columns relative to the cursor column. */
    d = ((short (*)[0x12])MK_FP(0x88,0))[record][1] - (int)(GfxRndSeed - 2);
    if (((d + (int)colOfs) - 1) < 0) {
      continue;
    }
    if (d > 3) {
      continue;
    }
    if (((short (*)[0x12])MK_FP(0x88,0))[record][0] > 0x4e20) {
      ((short (*)[0x12])MK_FP(0x88,0))[record][0] = 3;
    }
    for (si = 0; si < (int)colOfs; si++) {
      if ((si + d) < 0) {
        continue;
      }
      if ((si + d) > 3) {
        continue;
      }
      /* GUESS: the 8-byte table at 0x91d7 holds the record index per column (0x0163), and the
         4-byte area at 0x90ea marks the columns past the first (0x016e). Both are addressed
         absolutely because the audit table has no symbol for either. */
      ((uint16_t *)(uint16_t)0x91d7)[si + d] = (uint16_t)record;
      if (si > 0) {
        ((byte *)(uint16_t)0x90ea)[d + si] = 1;
      }
    }
    cursorRecordFound = 1;
  }

  /* 0x0191..0x03c5: the cursor sound is cleared, then set from the accumulated flags and the
     placed-record state.  `CurSfxType3` (DGROUP 0x7a7) carries it. */
  CurSfxType3 = 0xff;
  if (GOngoingBattle != 0) {
    return flags;
  }
  if (flags == 0x3000) {
    return flags;
  }
  if (cursorRecordFound) {
    CurSfxType3 = 0x70;
    return flags;
  }
  /* 0x01cd..0x037a: probe the four columns around the cursor.  `minLevel` becomes the smallest level
     of a friendly building found on them, `kindSum` the sum of the BuildingTypes kinds, and `sfx` the
     per-building cursor sound that the loop copies into CurSfxType3. */
  sfx = 0;
  kindSum = 0;
  minLevel = 0xff;
  sameSfx = 0;
  for (col = -2; col <= 1; col++) {
    idx = (int)ovr_ovc45_getUnitIndex(GfxRndSeed + col,GfxRndSeed2);
    bldType = (byte)ovr_ovc45_getUnitType(GfxRndSeed + col,GfxRndSeed2);
    unitType = GUnits[idx].unitType;
    if ((idx >= 0xf8) && (unitType != 0xff)) {
      if (((GLeaderSheets[unitType])->faction == 0) &&
          (GUnits[idx].level <= minLevel)) {
        minLevel = GUnits[idx].level;
      }
    }
    if (((GLeaderSheets[unitType])->faction == 0) && (unitType != 0xff)) {
      kindSum = (uint16_t)(kindSum + BuildingTypes[bldType].kind);
    }
    sfx = BuildingTypes[bldType].sfxType;
    if ((GUnits[idx].level >= 6) && (sfx == 0x86)) {
      sameSfx = sameSfx + 1;
      if (sameSfx < 2) {
        sfx = 0;
      }
    }
    if (sfx != 0) {
      if (CurSfxType3 == 0xff) {
        CurSfxType3 = sfx;
      }
      else if (ovr_randBelow(2) == 0) {
        CurSfxType3 = sfx;
      }
    }
  }
  if ((flags == 0x1000) && (CurSfxType3 == 0xff)) {
    if (minLevel != 0xff) {
      if (minLevel < 5) {
        CurSfxType3 = 0x61;
      }
      else if (kindSum >= 3) {
        CurSfxType3 = 0x5e;
      }
    }
  }
  if (CurSfxType3 != 0xff) {
    return flags;
  }
  /* 0x03e5..0x0479: the map-flag class picks the cursor sound through the cs:0x47d table
     (0x400=0x80, 0x40d=0x83, 0x41a=GSeason?0x7a:0x76, 0x443=GSeason?0x7a:0x7d, 0x46c=0x7a). */
  mapClass = (byte)ovr_constr_usesGMapFlags2(GfxRndSeed,GfxRndSeed2 + 1);
  switch ((uint16_t)mapClass) {
  case 0:
    CurSfxType3 = 0x80;
    break;
  case 1:
    CurSfxType3 = 0x83;
    break;
  case 2:
    CurSfxType3 = (GSeason == 2) ? 0x7a : 0x76;
    break;
  case 3:
    CurSfxType3 = (GSeason == 2) ? 0x7a : 0x7d;
    break;
  case 4:
    CurSfxType3 = 0x7a;
    break;
  }
  return flags;
}
/* 55fe:0487 */

/* Stamps GameTick on the records overlapping a column and counts down their timers. */

bool __cdecl16far ovc23_tickRecordsAt(uint16_t x,int y,char excluded,uint16_t arg4)

{
  byte party;
  uint32_t sheetRef;
  uint alignedX;
  uint i;
  bool found;
  
  alignedX = ovr_alignUp4(x,0,0);
  found = 0;
  for (i = 0; i < GRecordCount; i = i + 1) {
    if ((((GRecords[i].y == y) && (GRecords[i].x <= alignedX + 1)) &&
        (alignedX - 2 <= (GRecords[i].x + (uint)GRecords[i].width) - 1)) &&
       ((party = GRecords[i].party, party != 0xff &&
        (sheetRef = *(uint32_t *)((uint)party << 2), *(char *)((int)sheetRef + 0x3f) == excluded)))) {
      GRecords[i].tick = GameTick;
      if (GRecords[i].countdown != '\0') {
        GRecords[i].countdown = GRecords[i].countdown - 1;
      }
      if (GRecords[i].countdown == '\0') {
        GRecords[i].state = 1;
      }
      found = 1;
    }
  }
  return found;
}



/* 55fe:05db */

/* Returns whether the point matches the cell in GfxRndSeed/GfxRndSeed2. */

bool __cdecl16far ovc23_isCursorAt(uint16_t x,int y)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = ovr_alignUp4(x,0,0);
  uVar2 = ovr_alignUp4(GfxRndSeed,0,0);
  if ((uVar1 == uVar2) && (uVar2 = GfxRndSeed2, GfxRndSeed2 == y)) {
    uVar2 = CONCAT11((char)(GfxRndSeed2 >> 8),1);
  }
  else {
    uVar2 = uVar2 & 0xff00;
  }
  return uVar2;
}



/* 55fe:0617 */

/* [R6] touches cornerBR, cornerBL */

int __cdecl16far ovc23_usesCornerBR(int x,int bldType)

{
  int smoothTL;
  int smoothBL;
  int minEdge;
  uint shadeBias;
  int cornerSampleBR;
  int cornerSample;
  static char cornerBR[64];
  static char cornerBL[64];
  static char cornerTR[64];
  static char cornerTL[64];
  int minShade;
  
  smoothTL = ovr_constr_usesSmoothPrev(x,-1,(int *)&cornerTL,0,0);
  smoothBL = ovr_constr_usesSmoothPrev(x,0,(int *)&cornerBL,0,0);
  if (*(byte *)((uint8_t *)&BuildingTypes[bldType] + 13) < 2) {
    cornerSample = ovr_constr_usesSmoothPrev(x + 1,-1,(int *)&cornerTR,0,0);
    cornerSampleBR = ovr_constr_usesSmoothPrev(x + 1,0,(int *)&cornerBR,0,0);
  }
  else if (*(byte *)((uint8_t *)&BuildingTypes[bldType] + 13) < 3) {
    cornerSample = ovr_constr_usesSmoothPrev(x + 2,-1,(int *)&cornerTR,0,0);
    cornerSampleBR = ovr_constr_usesSmoothPrev(x + 2,0,(int *)&cornerBR,0,0);
  }
  else {
    cornerSample = ovr_constr_usesSmoothPrev(x + 4,-1,(int *)&cornerTR,0,0);
    cornerSampleBR = ovr_constr_usesSmoothPrev(x + 4,0,(int *)&cornerBR,0,0);
  }
  shadeBias = (uint)cornerShadeBias[0];
  minShade = smoothBL + smoothTL + cornerSample + cornerSampleBR >> 2;
  if ((int)(smoothTL - shadeBias) < (int)(cornerSample - shadeBias)) {
    minEdge = smoothTL - shadeBias;
  }
  else {
    minEdge = cornerSample - shadeBias;
  }
  if (minShade < minEdge) {
    if ((int)(smoothTL - shadeBias) < (int)(cornerSample - shadeBias)) {
      minShade = smoothTL - shadeBias;
    }
    else {
      minShade = cornerSample - shadeBias;
    }
  }
  return minShade;
}



/* 55fe:0768 */

/* [R6] touches cornerBR, cornerBL */

int __cdecl16far ovc23_usesCornerBR2(int x,int step)

{
  int cornerSampleTL;
  int iVar2;
  int iStack_12;
  static char cornerBR[64];
  static char cornerBL[64];
  static char cornerTR[64];
  static char cornerTL[64];
  int cornerSampleBR;
  int cornerSampleTR;
  int cornerSampleBL;
  
  if (step == 4) {
    cornerSampleTL = ovr_constr_usesSmoothPrev(x + 1,-1,(int *)&cornerTL,0,0);
    cornerSampleBL = ovr_constr_usesSmoothPrev(x + 1,0,(int *)&cornerBL,0,0);
    cornerSampleTR = ovr_constr_usesSmoothPrev(x + 2,-1,(int *)&cornerTR,0,0);
    cornerSampleBR = ovr_constr_usesSmoothPrev(x + 2,0,(int *)&cornerBR,0,0);
  }
  else {
    cornerSampleTL = ovr_constr_usesSmoothPrev(x,-1,(int *)&cornerTL,0,0);
    cornerSampleBL = ovr_constr_usesSmoothPrev(x,0,(int *)&cornerBL,0,0);
    cornerSampleTR = ovr_constr_usesSmoothPrev(x + step,-1,(int *)&cornerTR,0,0);
    cornerSampleBR = ovr_constr_usesSmoothPrev(x + step,0,(int *)&cornerBR,0,0);
  }
  iStack_12 = cornerSampleBL + cornerSampleTL + cornerSampleTR + cornerSampleBR >> 2;
  iVar2 = cornerSampleTR;
  if (cornerSampleTL < cornerSampleTR) {
    iVar2 = cornerSampleTL;
  }
  if ((iStack_12 < iVar2) && (iStack_12 = cornerSampleTR, cornerSampleTL < cornerSampleTR)) {
    iStack_12 = cornerSampleTL;
  }
  return iStack_12;
}



/* 55fe:0863 */

/* [R2] string "build\\thfres01.lbm" */

void __cdecl16far ovc23_textBuildThfres01Lbm(far_t dst)

{
  uint16_t play_id;
  bool drew;                /* set when anything was drawn for this row */
  byte hlRes;               /* ovr_constr_setHighlightAtOffset's result */
  undefined1 extraout_AH;
  int height;               /* ovc23_usesCornerBR/BR2's height for the frame */
  uint16_t siArg;           /* the value the image leaves in SI */
  uint16_t diArg;           /* the value the image leaves in DI */
  uint16_t sq;              /* the square index along row 0 */
  int sprIdx;              /* the sprite index built from AH and the highlight */
  int recIdx;              /* the construction record the square maps to */
  
  drew = false;
  GAnimPlaying = 0;
  sq = rowMapSquareFirst[0];
  while( true ) {
    if (rowMapSquareEnd[0] <= sq) break;
    play_id = *(uint16_t *)(&mapSquareColumn[sq]);
    if ((-3 < (int)play_id) && ((int)play_id < 2)) {
      hlRes = ovr_constr_setHighlightAtOffset(play_id,0,0);
      sprIdx = CONCAT11(extraout_AH,hlRes);
      if (((char *)0x28048)[sprIdx * 3 + *(int *)(sq * 2)] != '\0') {
        height = ovc23_usesCornerBR(play_id,sprIdx);
        ovr_animAdvance(play_id,((char *)0x28048)
                                [sprIdx * 3 + *(int *)(sq * 2)],*(uint16_t *)(&mapSquareLeftX[sq]),
                        (uint)bandOrigin[0] - height,dst);
        drew = true;
      }
      recIdx = iRam0002d2d7;
      if (*(int *)(play_id * 2 + -0x6e25) != -1) {
        if (*(char *)(play_id + 0x90ec) == '\0') {
          recIdx = *(int *)(play_id * 2 + -0x6e25);
          height = ovc23_usesCornerBR2(play_id,(uint)GRecords[recIdx].width);
          ovc23_usesBlitGfxRect2
                    ((uint)bandOrigin[0] - height,recIdx,dst.ofs,(brect_t *)CONCAT22(diArg,dst.seg)
                     ,siArg);
          drew = true;
        }
        else if (play_id == 0xfffe) {
          height = ovc23_usesCornerBR2(-2,(uint)GRecords[iRam0002d2d7].width);
          ovc23_usesBlitGfxRect2
                    ((uint)bandOrigin[0] - height,recIdx,dst.ofs,(brect_t *)CONCAT22(diArg,dst.seg)
                     ,siArg);
          drew = true;
        }
      }
    }
    sq = sq + 1;
  }
  if (drew) {
    ovr_constr_usesScreenOriginY(dst.ofs,dst.seg,0);
  }
  return;
}



/* 55fe:0a56 */

/* Returns whether the building at the cell has bldtp_t.size >= 2. */

int __cdecl16far ovc23_isLargeBuilding(int x,int y)

{
  int iVar1;
  byte bVar2;
  byte bldType;

  bldType = (GUnits + ((short (*) [148] [60])GUnitGrid)[-1][x + 0x93][y])->bldType;
  iVar1 = (uint)bldType * 0x27;
  bVar2 = (byte)((uint)iVar1 >> 8);
  if (BuildingTypes[bldType].size < 2) {
    iVar1 = (uint)bVar2 << 8;
  }
  else {
    iVar1 = CONCAT11(bVar2,1);
  }
  return iVar1;
}



/* 55fe:0aba */

/* [R6] touches GfxRndSeed2, GfxRndSeed */

void __cdecl16far ovc23_usesGfxRndSeed2(int x,int y)

{
  if (((GfxRndSeed2 == y) && (GfxRndSeed + -2 <= x)) && (x <= GfxRndSeed + 1)) {
    AgntClearFlag = true;
  }
  return;
}



/* 55fe:0af5 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00053af7) overlaps instruction at (ram,0x00053af6)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

uint __cdecl16far ovc23_usesAlignUp43(int x,int y,byte dir)

{
  /* Re-derived from 55fe:0af5 (482 bytes; retf at 0x0cd6, 4-entry table at 0x0cd7).  Returns 1
     when the neighbouring unit cell in `dir` holds a placed building whose BuildingTypes flag
     byte at +0x11e has that direction's bit, 0 otherwise; the opening attact_usesGUnits test
     returns 1 immediately when the stepped cell is empty.  Cases 2 and 3 address the same cell
     (GUnitGrid[x][y]); that is what the instructions do, so it is kept as decoded. */
  uint idx;
  byte bldType;

  if ((char)ovr_attact_usesGUnits(x + *(char *)(dir + 0x885),
                                  y + *(char *)(dir + 0x889)) == '\0') {
    return 1;
  }
  switch(dir) {
  case 0:
    idx = (*(short (*) [148] [60])GUnitGrid)[x][y + -1];
    bldType = (GUnits + idx)->bldType;
    if ((bldType < 0xf8) && ((BuildingTypes[(uint)bldType].flags & 1) != 0)) {
      return 1;
    }
    break;
  case 1:
    idx = (*(short (*) [148] [60])GUnitGrid)[x + 1][y];
    bldType = (GUnits + idx)->bldType;
    if ((bldType < 0xf8) && ((BuildingTypes[(uint)bldType].flags & 2) != 0)) {
      return 1;
    }
    break;
  case 2:
    idx = (*(short (*) [148] [60])GUnitGrid)[x][y];
    bldType = (GUnits + idx)->bldType;
    if ((bldType < 0xf8) && ((BuildingTypes[(uint)bldType].flags & 1) != 0)) {
      return 1;
    }
    break;
  case 3:
    idx = (*(short (*) [148] [60])GUnitGrid)[x][y];
    bldType = (GUnits + idx)->bldType;
    if ((bldType < 0xf8) && ((BuildingTypes[(uint)bldType].flags & 2) != 0)) {
      return 1;
    }
    break;
  }
  return 0;
}



/* 55fe:0cdf */
bool __cdecl16far ovc23_textConstructionAbandoned(int x,int y,byte dir)

{
  /* Re-derived from 55fe:0cdf (594 bytes; retf at 0x251, jump table at ip 0xf31 -> 0x65, 0xe2,
     0x166, 0x1dd).  Returns true when the neighbouring cell in `dir` holds a placed building that
     still has construction going on: the direction's own bit (1 for 0 and 2, 2 for 1 and 3) and
     the shared 0x20 bit must both be set in BuildingTypes[bldType].flags.  Cases 2 and 3 read the
     same cell (GUnitGrid[x][y]), which is what the instructions do. */
  byte bldType;
  uint idx;

  if ((char)ovr_attact_usesGUnits(x + *(char *)(dir + 0x885),
                                 y + *(char *)(dir + 0x889)) == '\0') {
    return false;
  }
  switch(dir) {
  case 0:
    idx = (*(short (*) [148] [60])GUnitGrid)[x][y + -1];
    break;
  case 1:
    idx = (*(short (*) [148] [60])GUnitGrid)[x + 1][y];
    break;
  case 2:
    idx = (*(short (*) [148] [60])GUnitGrid)[x][y];
    break;
  case 3:
    idx = (*(short (*) [148] [60])GUnitGrid)[x][y];
    break;
  default:
    return false;
  }
  bldType = (GUnits + idx)->bldType;
  if (0xf8 <= bldType) {
    return false;
  }
  if ((dir == 0) || (dir == 2)) {
    if ((BuildingTypes[bldType].flags & 1) == 0) {
      return false;
    }
  }
  else if ((BuildingTypes[bldType].flags & 2) == 0) {
    return false;
  }
  if ((BuildingTypes[bldType].flags & 0x20) == 0) {
    return false;
  }
  return true;
}


/* 55fe:0f39 */

/* Rebuilds the four direction bits of a map cell from its neighbour tests. */

void __cdecl16far ovc23_rebuildDirectionFlags(int x,int y)

{
  /* Re-derived: clears the four direction bits in the cell's flag word (& 0xff0f), then for
     each of the four directions sets 0x10<<d when ovc23_usesAlignUp43 reports the direction is
     usable and 0x100<<d when the construction there is abandoned. */
  uint16_t *flagWord;
  bool abandoned;
  uint dirResult;
  byte dir;

  if ((((x < 0x94) && (-1 < x)) && (y < 0x3c)) && (-1 < y)) {
    flagWord = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y] + x);
    *flagWord = *flagWord & 0xff0f;
    for (dir = 0; dir < 4; dir = dir + 1) {
      dirResult = ovc23_usesAlignUp43(x,y,dir);
      if ((char)dirResult != '\0') {
        flagWord = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y] + x);
        *flagWord = *flagWord | 0x10 << (dir & 0x1f);
      }
      abandoned = ovc23_textConstructionAbandoned(x,y,dir);
      if (abandoned) {
        flagWord = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y] + x);
        *flagWord = *flagWord | 0x100 << (dir & 0x1f);
      }
    }
  }
  return;
}



/* 55fe:1005 */

/* Places a building of the given bldType/unitType at (x,y). */

void __cdecl16far ovc23_placeBuilding(int x,int y,byte bldType,uint8_t unitType)

{
  byte *unitFlagsPtr;
  uint16_t *flagPtr;
  byte cellBldType;
  int unitIdx;
  uint16_t cellType;
  uint newUnitIdx;
  
  unitIdx = (*(short (*) [148] [60])GUnitGrid)[x][y];
  cellBldType = (GUnits + unitIdx)->bldType;
  if ((BuildingTypes[cellBldType].flags2 & 4) != 0) {
    strongholdCheckPending = 1;
  }
  newUnitIdx = ovr_ovc18_usesRandBelow(x,y,bldType,unitType,0,0);
  if ((BuildingTypes[bldType].flags & 2) == 2) {
    ovc23_usesGfxRndSeed2(x,y);
  }
  if (((BuildingTypes[bldType].flags & 0xf) != 0) ||
     ((BuildingTypes[cellBldType].flags & 0xf) != 0)) {
    ovc23_rebuildDirectionFlags(x,y);
  }
  if (((BuildingTypes[cellBldType].flags & 1) != 0) ||
     ((BuildingTypes[bldType].flags & 1) != 0)) {
    ovc23_rebuildDirectionFlags(x,y + 1);
  }
  if (((BuildingTypes[bldType].flags & 2) != 0) ||
     ((BuildingTypes[cellBldType].flags & 2) != 0)) {
    ovc23_rebuildDirectionFlags(x + -1,y);
  }
  if (((BuildingTypes[bldType].flags & 3) == 3) ||
     ((BuildingTypes[cellBldType].flags & 3) == 3)) {
    ovc23_rebuildDirectionFlags(x + 1,y);
    ovc23_rebuildDirectionFlags(x,y + 1);
  }
  if (BuildingTypes[bldType].kind == '\x02') {
    if (((*(short (*) [60] [148])GMapFlags)[y + 1][x] & 3U) != 0) {
      unitFlagsPtr = &(GUnits)[newUnitIdx].flags;
      *unitFlagsPtr = *unitFlagsPtr | 4;
      flagPtr = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y + 1] + x);
      *flagPtr = *flagPtr & 0xfffc;
    }
    if ((BuildingTypes[bldType].flags & 4) != 0) {
      if (((*(short (*) [60] [148])GMapFlags)[y][x + 0x93] & 3U) != 0) {
        unitFlagsPtr = &(GUnits)[newUnitIdx].flags;
        *unitFlagsPtr = *unitFlagsPtr | 8;
        flagPtr = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y] + x + 0x93);
        *flagPtr = *flagPtr & 0xfffc;
        ovc23_rebuildDirectionFlags(x + -2,y);
        ovc23_rebuildDirectionFlags(x + -1,y + -1);
        ovc23_rebuildDirectionFlags(x + -1,y + 1);
      }
      if (((*(short (*) [60] [148])GMapFlags)[y + 1][x + 1] & 3U) != 0) {
        unitFlagsPtr = &(GUnits)[newUnitIdx].flags;
        *unitFlagsPtr = *unitFlagsPtr | 0x10;
        flagPtr = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y + 1] + x + 1);
        *flagPtr = *flagPtr & 0xfffc;
        ovc23_rebuildDirectionFlags(x + 1,y + -1);
        ovc23_rebuildDirectionFlags(x + 1,y + 1);
        ovc23_rebuildDirectionFlags(x + 2,y);
      }
    }
    if ((BuildingTypes[bldType].flags & 8) != 0) {
      if (((*(short (*) [60] [148])GMapFlags)[y][x] & 3U) != 0) {
        unitFlagsPtr = &(GUnits)[newUnitIdx].flags;
        *unitFlagsPtr = *unitFlagsPtr | 8;
        flagPtr = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y] + x);
        *flagPtr = *flagPtr & 0xfffc;
        ovc23_rebuildDirectionFlags(x + -1,y + -1);
        ovc23_rebuildDirectionFlags(x + 1,y + -1);
        ovc23_rebuildDirectionFlags(x,y + -2);
      }
      if (((*(short (*) [60] [148])GMapFlags)[y + 2][x] & 3U) != 0) {
        unitFlagsPtr = &(GUnits)[newUnitIdx].flags;
        *unitFlagsPtr = *unitFlagsPtr | 0x10;
        flagPtr = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y + 2] + x);
        *flagPtr = *flagPtr & 0xfffc;
        ovc23_rebuildDirectionFlags(x + -1,y + 1);
        ovc23_rebuildDirectionFlags(x + 1,y + 1);
        ovc23_rebuildDirectionFlags(x,y + 2);
      }
    }
    ovc23_rebuildDirectionFlags(x,y);
    ovc23_rebuildDirectionFlags(x + 1,y);
    ovc23_rebuildDirectionFlags(x + -1,y);
    ovc23_rebuildDirectionFlags(x,y + -1);
    ovc23_rebuildDirectionFlags(x,y + 1);
  }
  if (BuildingTypes[cellBldType].kind == '\x02') {
    ovc23_usesGfxRndSeed2(x,y);
    if (((GUnits)[unitIdx].flags & 4) != 0) {
      ovc23_drownUnitsAt(x,y);
    }
    if (BuildingTypes[cellBldType].flags == '\x04') {
      cellType = ovr_ovc45_getUnitType(x + -1,y);
      if ((cellType == 0) && (((GUnits)[unitIdx].flags & 8) != 0)) {
        ovc23_usesGfxRndSeed2(x + -1,y);
        ovc23_drownUnitsAt(x - 1,y);
        ovc23_rebuildDirectionFlags(x + -1,y + -1);
        ovc23_rebuildDirectionFlags(x + -1,y + 1);
        ovc23_rebuildDirectionFlags(x + -2,y);
      }
      cellType = ovr_ovc45_getUnitType(x + 1,y);
      if ((cellType == 0) && (((GUnits)[unitIdx].flags & 0x10) != 0))
      {
        ovc23_usesGfxRndSeed2(x + 1,y);
        ovc23_drownUnitsAt(x + 1,y);
        ovc23_rebuildDirectionFlags(x + 1,y + -1);
        ovc23_rebuildDirectionFlags(x + 1,y + 1);
        ovc23_rebuildDirectionFlags(x + 2,y);
      }
    }
    else if (BuildingTypes[cellBldType].flags == '\b') {
      cellType = ovr_ovc45_getUnitType(x,y + -1);
      if ((cellType == 0) && (((GUnits)[unitIdx].flags & 8) != 0)) {
        ovc23_usesGfxRndSeed2(x,y + -1);
        ovc23_drownUnitsAt(x,y - 1);
        ovc23_rebuildDirectionFlags(x + -1,y + -1);
        ovc23_rebuildDirectionFlags(x + 1,y + -1);
        ovc23_rebuildDirectionFlags(x,y + -2);
      }
      cellType = ovr_ovc45_getUnitType(x,y + 1);
      if ((cellType == 0) && (((GUnits)[unitIdx].flags & 0x10) != 0))
      {
        ovc23_usesGfxRndSeed2(x,y + 1);
        ovc23_drownUnitsAt(x,y + 1);
        ovc23_rebuildDirectionFlags(x + -1,y + 1);
        ovc23_rebuildDirectionFlags(x + 1,y + 1);
        ovc23_rebuildDirectionFlags(x,y + 2);
      }
    }
    ovc23_rebuildDirectionFlags(x,y);
    ovc23_rebuildDirectionFlags(x + 1,y);
    ovc23_rebuildDirectionFlags(x + -1,y);
    ovc23_rebuildDirectionFlags(x,y + -1);
    ovc23_rebuildDirectionFlags(x,y + 1);
  }
  if ((BuildingTypes[bldType].unitType == '\x12') && (ListCount < 5)) {
    *(uint *)((uint)ListCount * 2 + -0x6d44) = newUnitIdx;
    ListCount = ListCount + 1;
  }
  if ((BuildingTypes[bldType].sight != 0) || (BuildingTypes[cellBldType].sight != 0))
  {
    ovr_unit_usesAlignUp4();
  }
  return;
}



/* 55fe:1803 */

/* Removes a record from the 0x12-stride table at GRecords, compacts the tail and decrements
   GRecordCount. */

void __cdecl16far ovc23_removeRecord(int recordIndex)

{
  agnt_t far *in_stack_00000000;
  
  if (recordIndex + 1U < GRecordCount) {
    _fmemmove((char *)CONCAT22(_DS,(char *)&GREC_FIELD(&GRecords[recordIndex], buildTimer, 0)),
              (char *)CONCAT22(_DS,(char *)&GREC_FIELD(&GRecords[recordIndex + 1], buildTimer, 0)),
              ((GRecordCount - recordIndex) + -1) * 0x12);
  }
  GRecordCount = GRecordCount - 1;
  ovc23_textAdlibNone();
  return;
}



/* 55fe:184e */

/* appends a construction record (bldType, x, y, party, tick) */

void __cdecl16far
createConstructionRecord(byte bldType,int x,int y,uint8_t *outFlag,char partyIndex,uint16_t arg6,uint16_t arg7,uint16_t arg8,uint16_t arg9,uint16_t arg10)

{
  int *xPtr;                /* &GRecords[n].x */
  byte *flagsPtr;           /* &GRecords[n] + 0xd */
  undefined1 bldSize;       /* BuildingTypes[bStack_5].size */
  int largeRes;             /* ovc23_isLargeBuilding's result */
  uint16_t battleRes;       /* ovr_ovc22_usesGOngoingBattle's result */
  uint16_t gridSegDead;     /* GUnitGrid's segment: stored, never read */
  uint16_t expVal;          /* ovc23_usesGRecordCount3's result */
  uint battleRes2;          /* the same call inside the record scan */
  uint bestAge;             /* the largest GameTick - tick found */
  uint bestIdx;             /* the record the scan settled on, or 0xffff */
  uint newIdx;              /* the record just appended */
  undefined1 outHi;         /* the high byte of the outFlag far pointer */
  byte actorIdx;           /* the acting agent's index */
  char flagArg;            /* the flag argument */
  agnt_t far *foundRec;    /* ovc23_findRecordAt's result, as an index */
  uint recIdx;              /* the loop counter, over building size and records */
  byte bStack_5;
  byte bStack_3;
  
  outFlag = (undefined1 *)CONCAT13(outHi,CONCAT12(partyIndex,outFlag));
  for (recIdx = 0; (int)recIdx < (int)(uint)BuildingTypes[bldType].size;
      recIdx = recIdx + 1) {
    foundRec = (agnt_t far *)ovc23_findRecordAt(x + recIdx,y,0);
    if (-1 < (int)foundRec) {
      ovc23_removeRecord((int)foundRec);
    }
  }
  largeRes = ovc23_isLargeBuilding(x,y);
  if ((char)largeRes != '\0') {
    ovc23_placeBuilding(x + -1,y,0,actorIdx);
    battleRes = ovr_ovc22_usesGOngoingBattle((byte)x - 1,(byte)y);
    if ((char)battleRes != '\0') {
      *outFlag = 1;
    }
  }
  for (recIdx = 1; (int)recIdx < (int)(uint)BuildingTypes[bldType].size;
      recIdx = recIdx + 1) {
    ovc23_placeBuilding(x + recIdx,y,0,actorIdx);
    battleRes = ovr_ovc22_usesGOngoingBattle((byte)x + (char)recIdx,(byte)y);
    if ((char)battleRes != '\0') {
      *outFlag = 1;
    }
  }
  if (*(char *)((int)*(uint32_t *)((uint)actorIdx << 2) + 0x3f) == '\0') {
    if (0x31 < GRecordCount) {
      bestAge = 0;
      bestIdx = 0xffff;
      for (recIdx = 0; recIdx < GRecordCount; recIdx = recIdx + 1) {
        battleRes2 = ovr_ovc22_usesGOngoingBattle
                          (GREC_FIELD(&GRecords[recIdx], x, 0),GREC_FIELD(&GRecords[recIdx], y, 0));
        if (((battleRes2 & 0xff) == 0) && (bestAge <= (uint)(GameTick - GRecords[recIdx].tick)))
        {
          bestAge = GameTick - GRecords[recIdx].tick;
          bestIdx = recIdx;
        }
      }
      if (bestIdx == 0xffff) {
        for (recIdx = 0; recIdx < GRecordCount; recIdx = recIdx + 1) {
          if (bestAge <= (uint)(GameTick - GRecords[recIdx].tick)) {
            bestAge = GameTick - GRecords[recIdx].tick;
            bestIdx = recIdx;
          }
        }
      }
      if (bestIdx == 0xffff) {
        return;
      }
      if (bestIdx + 1 < GRecordCount) {
        _fmemmove((char *)CONCAT22(_DS,(char *)&GREC_FIELD(&GRecords[bestIdx], buildTimer, 0)),
                  (char *)CONCAT22(_DS,(char *)&GREC_FIELD(&GRecords[bestIdx + 1], buildTimer, 0)),
                  ((GRecordCount - bestIdx) + -1) * 0x12);
      }
      GRecordCount = GRecordCount - 1;
    }
    _fmemset(GRecords + GRecordCount, 0, 0x12);
    *(byte *)((uint8_t *)&GRecords[GRecordCount] + 8) = bldType;
    *(int *)((uint8_t *)&GRecords[GRecordCount] + 2) = x;
    *(int *)((uint8_t *)&GRecords[GRecordCount] + 4) = y;
    *(byte *)((uint8_t *)&GRecords[GRecordCount] + 9) = actorIdx;
    largeRes = ovc23_isLargeBuilding(x,y);
    gridSegDead = (uint16_t)((ulong)GUnitGrid >> 0x10);
    if ((char)largeRes == '\0') {
      bStack_5 = (GUnits + (*(short (*) [148] [60])GUnitGrid)[x][y])->bldType;
    }
    else {
      bStack_5 = (GUnits + ((short (*) [148] [60])GUnitGrid)[-1][x + 0x93][y])->bldType;
    }
    bStack_3 = BuildingTypes[bStack_5].buildTime;
    bldSize = BuildingTypes[bStack_5].size;
    if (bStack_3 == 0) {
      bStack_3 = 1;
    }
    if (bStack_3 < BuildingTypes[bldType].minBuildTime) {
      *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 6) = BuildingTypes[bldType].minBuildTime;
    }
    else {
      *(byte *)((uint8_t *)&GRecords[GRecordCount] + 6) = bStack_3;
    }
    *(int *)((uint8_t *)&GRecords[GRecordCount] + 0xf) = GameTick;
    *(uint16_t *)(&GRecords[GRecordCount]) = 0;
    expVal = ovc23_usesGRecordCount3
                      (BuildingTypes[bldType].expinc,actorIdx,GRecordCount);
    *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0xc) = (char)expVal;
    if (*(char *)((uint8_t *)&GRecords[GRecordCount] + 0xc) == '\0') {
      *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0xc) = 1;
    }
    if (bldType == 0) {
      largeRes = ovc23_isLargeBuilding(x,y);
      if ((char)largeRes != '\0') {
        xPtr = (int *)((uint8_t *)&GRecords[GRecordCount] + 2);
        *xPtr = *xPtr + -1;
      }
      *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 7) = bldSize;
      if (flagArg == '\x01') {
        *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0xe) = 1;
      }
      else {
        *(char *)((uint8_t *)&GRecords[GRecordCount] + 0xc) = flagArg;
        *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0xe) = 0;
      }
      flagsPtr = (byte *)((uint8_t *)&GRecords[GRecordCount] + 0xd);
      *flagsPtr = *flagsPtr | 3;
    }
    else {
      *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 7) = BuildingTypes[bldType].size;
      if (flagArg != '\0') {
        ovc23_placeBuilding(x,y,0,actorIdx);
        battleRes = ovr_ovc22_usesGOngoingBattle((byte)x,(byte)y);
        if ((char)battleRes != '\0') {
          *outFlag = 1;
        }
      }
      *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0xe) = 0;
    }
    *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0x11) = 0;
    *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0xb) = *(undefined1 *)((uint8_t *)&GRecords[GRecordCount] + 0xc);
    newIdx = GRecordCount;
    GRecordCount = GRecordCount + 1;
    ovc23_abandonConstruction(newIdx);
    ovc23_textAdlibNone();
  }
  else {
    ovc23_placeBuilding(x,y,bldType,actorIdx);
    battleRes = ovr_ovc22_usesGOngoingBattle((byte)x,(byte)y);
    if ((char)battleRes != '\0') {
      *outFlag = 1;
    }
  }
  return;
}



/* 55fe:1e87 */

/* overlay entry that forwards to createConstructionRecord */

void __cdecl16far
createConstructionRecordFar
          (byte bldType,int x,int y,uint8_t *outFlag,byte outFlagSeg,char partyIndex,uint16_t arg7,uint16_t arg8,uint16_t arg9)

{
  uint16_t in_AX;
  
  createConstructionRecord
            (bldType,x,y,(uint8_t *)outFlag,(char)((ulong)outFlag >> 0x10),CONCAT11((char)((uint)in_AX >> 8),outFlagSeg),1,0,0,0);
  return;
}



/* 55fe:1ea9 */

/* [R4] calls ovr_blitGfxRect */

void __cdecl16far ovc23_usesBlitGfxRect(int x,int y,int recordIndex,brect_t *rect,uint16_t type)

{
  int y_00;
  byte state;
  byte frame;
  uint buildTimer;
  int x_00;
  uint animPhase;
  int in_stack_00000004;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t gfx_05;
  far_t gfx_06;
  far_t gfx_07;
  far_t gfx_08;
  far_t gfx_09;
  far_t gfx_10;
  far_t gfx_11;
  uint8_t typeByte;
  uint spanCount;
  uint spanLeft;
  int curY;
  uint16_t gfxOfs;
  uint16_t gfxSeg;
  
  spanCount = (uint)GRecords[y].frameCount;
  buildTimer = GRecords[y].buildTimer;
  state = GRecords[y].state;
  frame = GRecords[y].frame;
  if (frame < spanCount) {
    spanCount = frame + 1;
  }
  x_00 = in_stack_00000004 + -1;
  curY = x + spanCount * -0x26 + -0x32;
  spanLeft = spanCount;
  while (spanLeft = spanLeft - 1, -1 < (int)spanLeft) {
    y_00 = curY + 0x26;
    typeByte = (uint8_t)rect;
    if ((state == 2) || (0x13 < buildTimer)) {
      if (state < 2) {
        if ((spanLeft == 0) && ((buildTimer - x_00 & 0x3f) < 0x20)) {
          animPhase = buildTimer - x_00 & 0x3f;
          gfxSeg = ((uint16_t *)&csite5Seg)[animPhase * 2];
          gfxOfs = ((uint16_t *)&csite5Ofs)[animPhase * 2];
        }
        else {
          gfxSeg = csite3_5Seg;
          gfxOfs = csite3_5Ofs;
        }
        if (spanLeft == 0) {
          animPhase = (buildTimer + GfxRndSeed2) % 0xe;
          gfx_01.seg = ((uint16_t *)&tmstrsSprites6Seg)[animPhase * 2];
          gfx_01.ofs = ((uint16_t *)&tmstrsSprites6Ofs)[animPhase * 2];
          ovr_blitGfxRect(gfx_01,in_stack_00000004 + 0xe,curY + 0x8b,(brect_t *)recordIndex,typeByte,true,1,0,0,0,0,0);
        }
        gfx_02.seg = gfxSeg;
        gfx_02.ofs = gfxOfs;
        ovr_blitGfxRect(gfx_02,x_00,y_00,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
        if ((buildTimer + spanLeft + GfxRndSeed2 + x_00 & 0x1f) < 0x11) {
          animPhase = buildTimer + spanLeft + GfxRndSeed2 + x_00 & 0x1f;
          gfx_03.seg = ((uint16_t *)&tmstrsSprites5Seg)[animPhase * 2];
          gfx_03.ofs = ((uint16_t *)&tmstrsSprites5Ofs)[animPhase * 2];
          ovr_blitGfxRect(gfx_03,x_00 + ((uint)*(byte *)((buildTimer + spanLeft + GfxRndSeed2 + x_00 >> 5
                                                         ) + spanLeft + GfxRndSeed2 & 0xff) * 0x50)
                                        / 0x100,curY + 0x66,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
        }
        if ((((buildTimer + spanLeft) - GfxRndSeed2) - x_00 & 0xf) < 7) {
          animPhase = ((buildTimer + spanLeft) - GfxRndSeed2) - x_00 & 0xf;
          gfx_04.seg = ((uint16_t *)&tmstrsSprites4Seg)[animPhase * 2];
          gfx_04.ofs = ((uint16_t *)&tmstrsSprites4Ofs)[animPhase * 2];
          ovr_blitGfxRect(gfx_04,x_00 + ((uint)*(byte *)((((((buildTimer + spanLeft) - GfxRndSeed2) -
                                                            x_00 >> 4) + spanLeft) - GfxRndSeed2) +
                                                         0xe & 0xff) * 0x50) / 0x100,curY + 0x66,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
        }
        animPhase = (buildTimer + 5) % 7;
        gfx_05.seg = ((uint16_t *)&tmstrsSprites3Seg)[animPhase * 2];
        gfx_05.ofs = ((uint16_t *)&tmstrsSprites3Ofs)[animPhase * 2];
        ovr_blitGfxRect(gfx_05,in_stack_00000004 + 9,curY + 0x62,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
        gfx_06.seg = ((uint16_t *)&tmstrsSprites3Seg)[(buildTimer % 7) * 2];
        gfx_06.ofs = ((uint16_t *)&tmstrsSprites3Ofs)[(buildTimer % 7) * 2];
        ovr_blitGfxRect(gfx_06,in_stack_00000004 + 0xd,curY + 0x62,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
        animPhase = (buildTimer + 2) % 7;
        gfx_07.seg = ((uint16_t *)&tmstrsSprites3Seg)[animPhase * 2];
        gfx_07.ofs = ((uint16_t *)&tmstrsSprites3Ofs)[animPhase * 2];
        ovr_blitGfxRect(gfx_07,in_stack_00000004 + 0x31,curY + 0x62,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
        animPhase = buildTimer + 3 & 7;
        gfx_08.seg = ((uint16_t *)&tmstrsSprites2Seg)[animPhase * 2];
        gfx_08.ofs = ((uint16_t *)&tmstrsSprites2Ofs)[animPhase * 2];
        ovr_blitGfxRect(gfx_08,in_stack_00000004 + 0x45,curY + 0x62,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
        gfx_09.seg = ((uint16_t *)&tmstrsSprites2Seg)[(buildTimer & 7) * 2];
        gfx_09.ofs = ((uint16_t *)&tmstrsSprites2Ofs)[(buildTimer & 7) * 2];
        ovr_blitGfxRect(gfx_09,in_stack_00000004 + 0x3b,curY + 0x62,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
        gfx_10.seg = ((uint16_t *)&tmstrsSprites1Seg)[(buildTimer % 5) * 2];
        gfx_10.ofs = ((uint16_t *)&tmstrsSprites1Ofs)[(buildTimer % 5) * 2];
        ovr_blitGfxRect(gfx_10,in_stack_00000004 + 0x27,curY + 0x62,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
        gfx_11.seg = ((uint16_t *)&tmstrsSprites1Seg)[(buildTimer % 5) * 2];
        gfx_11.ofs = ((uint16_t *)&tmstrsSprites1Ofs)[(buildTimer % 5) * 2];
        ovr_blitGfxRect(gfx_11,in_stack_00000004 + 0x3f,curY + 0x62,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
        curY = y_00;
      }
      else {
        if (buildTimer < 9) {
          gfxSeg = ((uint16_t *)&csite2Seg)[(buildTimer + 0xe) * 2];
          gfxOfs = ((uint16_t *)&csite2Ofs)[(buildTimer + 0xe) * 2];
        }
        else {
          gfxSeg = csite4_8Seg;
          gfxOfs = csite4_8Ofs;
        }
        gfx_00.seg = gfxSeg;
        gfx_00.ofs = gfxOfs;
        ovr_blitGfxRect(gfx_00,x_00,y_00,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
        curY = y_00;
      }
    }
    else {
      if ((spanCount - 1 == spanLeft) && (buildTimer < 0xf)) {
        gfxSeg = ((uint16_t *)&csite2Seg)[buildTimer * 2];
        gfxOfs = ((uint16_t *)&csite2Ofs)[buildTimer * 2];
      }
      else {
        gfxSeg = csite3_5Seg;
        gfxOfs = csite3_5Ofs;
      }
      gfx.seg = gfxSeg;
      gfx.ofs = gfxOfs;
      ovr_blitGfxRect(gfx,x_00,y_00,(brect_t *)recordIndex,typeByte,true,0,0,0,0,0,0);
      curY = y_00;
    }
  }
  return;
}



/* 55fe:23d8 */

/* [R4] calls ovr_blitGfxRect */

void __cdecl16far ovc23_usesBlitGfxRect2(int x,int y,int recordIndex,brect_t *rect,uint16_t type)

{
  int y_00;
  byte bVar1;
  byte frame;
  uint buildTimer;
  uint16_t spriteOfs;
  uint16_t spriteSeg;
  int x_00;
  uint animPhase;
  uint16_t unaff_SI;
  uint16_t unaff_DI;
  int in_stack_00000004;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t gfx_05;
  far_t gfx_06;
  far_t gfx_07;
  far_t gfx_08;
  far_t gfx_09;
  far_t gfx_10;
  far_t gfx_11;
  uint8_t type_00;
  brect_t *rect_00;
  uint spanCount;
  uint spanLeft;
  int yBase;
  uint16_t gfxOfs;
  uint16_t gfxSeg;
  
  bVar1 = GRecords[y].width;
  if (bVar1 < 2) {
    spanCount = (uint)GRecords[y].frameCount;
    buildTimer = GRecords[y].buildTimer;
    bVar1 = GRecords[y].state;
    frame = GRecords[y].frame;
    if (frame < spanCount) {
      spanCount = frame + 1;
    }
    x_00 = in_stack_00000004 + -1;
    yBase = x + spanCount * -0x13 + 0x2a;
    spanLeft = spanCount;
    while (spriteSeg = csite1_12Seg, spriteOfs = csite1_12Ofs, spanLeft = spanLeft - 1, -1 < (int)spanLeft)
    {
      y_00 = yBase + 0x13;
      type_00 = (uint8_t)rect;
      if ((bVar1 == 2) || (0x13 < buildTimer)) {
        if (bVar1 < 2) {
          if (spanLeft == 0) {
            animPhase = (buildTimer + GfxRndSeed2) % 0xe;
            gfx_01.seg = ((uint16_t *)&tmstrsSprites6Seg)[animPhase * 2];
            gfx_01.ofs = ((uint16_t *)&tmstrsSprites6Ofs)[animPhase * 2];
            ovr_blitGfxRect(gfx_01,in_stack_00000004 + 0xe,yBase + 0x22,(brect_t *)recordIndex,type_00,true,1,0,0,0,0,0);
          }
          gfx_02.seg = spriteSeg;
          gfx_02.ofs = spriteOfs;
          ovr_blitGfxRect(gfx_02,x_00,y_00,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
          if ((buildTimer + spanLeft + GfxRndSeed2 + x_00 & 0x1f) < 0x11) {
            animPhase = buildTimer + spanLeft + GfxRndSeed2 + x_00 & 0x1f;
            gfx_03.seg = ((uint16_t *)&tmstrsSprites5Seg)[animPhase * 2];
            gfx_03.ofs = ((uint16_t *)&tmstrsSprites5Ofs)[animPhase * 2];
            ovr_blitGfxRect(gfx_03,x_00 + ((int)((uint)*(byte *)((buildTimer + spanLeft + GfxRndSeed2 +
                                                                  x_00 >> 5) + spanLeft +
                                                                 GfxRndSeed2 & 0xff) * 0x25) >> 8) +
                                   3,yBase + 0x10,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
          }
          if ((((buildTimer + spanLeft) - GfxRndSeed2) - x_00 & 0xf) < 7) {
            animPhase = ((buildTimer + spanLeft) - GfxRndSeed2) - x_00 & 0xf;
            gfx_04.seg = ((uint16_t *)&tmstrsSprites4Seg)[animPhase * 2];
            gfx_04.ofs = ((uint16_t *)&tmstrsSprites4Ofs)[animPhase * 2];
            ovr_blitGfxRect(gfx_04,x_00 + ((int)((uint)*(byte *)((((((buildTimer + spanLeft) -
                                                                    GfxRndSeed2) - x_00 >> 4) +
                                                                  spanLeft) - GfxRndSeed2) + 0xe &
                                                                0xff) * 0x25) >> 8) + 3,yBase + 0x10,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
          }
          animPhase = (buildTimer + 5) % 7;
          gfx_05.seg = ((uint16_t *)&tmstrsSprites3Seg)[animPhase * 2];
          gfx_05.ofs = ((uint16_t *)&tmstrsSprites3Ofs)[animPhase * 2];
          ovr_blitGfxRect(gfx_05,in_stack_00000004 + 4,yBase + 0xd,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
          gfx_06.seg = ((uint16_t *)&tmstrsSprites3Seg)[(buildTimer % 7) * 2];
          gfx_06.ofs = ((uint16_t *)&tmstrsSprites3Ofs)[(buildTimer % 7) * 2];
          ovr_blitGfxRect(gfx_06,in_stack_00000004 + 6,yBase + 0xd,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
          animPhase = (buildTimer + 2) % 7;
          gfx_07.seg = ((uint16_t *)&tmstrsSprites3Seg)[animPhase * 2];
          gfx_07.ofs = ((uint16_t *)&tmstrsSprites3Ofs)[animPhase * 2];
          ovr_blitGfxRect(gfx_07,in_stack_00000004 + 0x18,yBase + 0xd,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
          animPhase = buildTimer + 3 & 7;
          gfx_08.seg = ((uint16_t *)&tmstrsSprites2Seg)[animPhase * 2];
          gfx_08.ofs = ((uint16_t *)&tmstrsSprites2Ofs)[animPhase * 2];
          ovr_blitGfxRect(gfx_08,in_stack_00000004 + 0x22,yBase + 0xd,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
          gfx_09.seg = ((uint16_t *)&tmstrsSprites2Seg)[(buildTimer & 7) * 2];
          gfx_09.ofs = ((uint16_t *)&tmstrsSprites2Ofs)[(buildTimer & 7) * 2];
          ovr_blitGfxRect(gfx_09,in_stack_00000004 + 0x1d,yBase + 0xd,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
          gfx_10.seg = ((uint16_t *)&tmstrsSprites1Seg)[(buildTimer % 5) * 2];
          gfx_10.ofs = ((uint16_t *)&tmstrsSprites1Ofs)[(buildTimer % 5) * 2];
          ovr_blitGfxRect(gfx_10,in_stack_00000004 + 0x13,yBase + 0xd,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
          gfx_11.seg = ((uint16_t *)&tmstrsSprites1Seg)[(buildTimer % 5) * 2];
          gfx_11.ofs = ((uint16_t *)&tmstrsSprites1Ofs)[(buildTimer % 5) * 2];
          ovr_blitGfxRect(gfx_11,in_stack_00000004 + 0x1f,yBase + 0xd,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
          yBase = y_00;
        }
        else {
          if (buildTimer < 10) {
            gfxSeg = ((uint16_t *)&csite1Seg)[(buildTimer + 0xc) * 2];
            gfxOfs = ((uint16_t *)&csite1Ofs)[(buildTimer + 0xc) * 2];
          }
          else {
            gfxSeg = csite1_22Seg;
            gfxOfs = csite1_22Ofs;
          }
          gfx_00.seg = gfxSeg;
          gfx_00.ofs = gfxOfs;
          ovr_blitGfxRect(gfx_00,x_00,y_00,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
          yBase = y_00;
        }
      }
      else {
        if ((spanCount - 1 == spanLeft) && (buildTimer < 0xd)) {
          gfxSeg = ((uint16_t *)&csite1Seg)[buildTimer * 2];
          gfxOfs = ((uint16_t *)&csite1Ofs)[buildTimer * 2];
        }
        else {
          gfxSeg = csite1_12Seg;
          gfxOfs = csite1_12Ofs;
        }
        gfx.seg = gfxSeg;
        gfx.ofs = gfxOfs;
        ovr_blitGfxRect(gfx,x_00,y_00,(brect_t *)recordIndex,type_00,true,0,0,0,0,0,0);
        yBase = y_00;
      }
    }
  }
  else {
    rect_00 = (brect_t *)CONCAT22(unaff_DI,(brect_t *)rect);
    ovc23_usesBlitGfxRect(x + 10,y,recordIndex,rect_00,unaff_SI);
    if (2 < bVar1) {
      ovc23_usesBlitGfxRect
                (x + 10,y,recordIndex,
                 (brect_t *)CONCAT22((int)((ulong)rect_00 >> 0x10),(brect_t *)rect),unaff_SI);
    }
  }
  return;
}



/* 55fe:2937 */

/* Returns the index of the 0x12-stride record at 0x21f2 whose row is y and whose x-span contains x,
   or 0xffff. */

uint __cdecl16far ovc23_findRecordAt(int x,int y,uint16_t arg3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    if (GRecordCount <= uVar2) {
      return 0xffff;
    }
    if (((GRecords[uVar2].y == y) &&
        (iVar1 = GRecords[uVar2].x,
        x <= (int)(iVar1 + (uint)GRecords[uVar2].width + -1))) && (iVar1 <= x)) break;
    uVar2 = uVar2 + 1;
  }
  return uVar2;
}



/* 55fe:29a2 */

/* Removes an unreachable construction record and reports "Construction abandoned." on the cursor
   cell. */

void __cdecl16far ovc23_abandonConstruction(int recordIndex)

{
  /* 55fe:29a2 (file 0x4A782), re-derived from the original:

       party = GRecords[idx].party                      ; +9
       if (GLeaderSheets[party][0x3f] != 0) return       ; 0x70 table, stride 4
       x = alignUp4(GRecords[idx].x)                     ; +2
       y = GRecords[idx].y                               ; +4
       mask1 = 0x1000 << sheet[0x3f]
       mask2 = 0x1000 << (sheet[0x3f] ^ 1)
       for (b = 0; b < 4; b++)                           ; 0x4A840..0x4A874
           acc |= word[GMapFlags + y*0x128 + (x+b)*2 - 4] & 0x3000
       if ((kind & 3) == 1 && acc == mask2 &&
           ovc24_textArena(x, y, sheet[0x3f]) == 0) {     ; 0x4A896..0x4A8C9
           if (ovc23_isCursorAt(x, y)) ovr_say("Construction abandoned.");
           if (idx + 1 < GRecordCount) fmemmove(...);
           GRecordCount--;
           ovc23_textAdlibNone();                        ; push cs / call, no arguments
       }
       else if ((kind & 1) == 0 && (mask1 & acc) != 0) {
           kind |= 1;
       }

     Corrections to the exported form: the loop counter is a plain byte 0..3 (the export
     packed it together with the party index through CONCAT11 and named the result `agnt`,
     then recovered the counter with `(byte)((uint)agnt >> 8)`), and the four repeated reads
     of the 0x70 sheet pointer collapse to one local.

     Recorded defect: the tail call is `push cs; call 0x47de0` (55fe:0000) with no `add sp`
     afterwards, i.e. ovc23_textAdlibNone takes NO arguments, while our declaration gives it
     three - the three pseudo-registers the export passed were never real arguments.  The
     zeros below are the closest expressible form; the declaration needs fixing separately. */
  byte party;
  uint16_t x;
  uint16_t y;
  uint16_t mask1;
  uint16_t mask2;
  uint16_t acc;
  byte b;
  uint32_t sheetRef;

  party = GRecords[recordIndex].party;
  sheetRef = *(uint32_t *)((uint)party << 2);
  if (*(char *)((int)sheetRef + 0x3f) == '\0') {
    x = ovr_alignUp4(GRecords[recordIndex].x,0,0);
    y = GRecords[recordIndex].y;
    mask1 = 0x1000 << (*(byte *)((int)sheetRef + 0x3f) & 0x1f);
    mask2 = 0x1000 << ((*(byte *)((int)sheetRef + 0x3f) ^ 1) & 0x1f);
    acc = 0;
    for (b = 0; b < 4; b++) {
      acc = acc | ((short (*) [60] [148])GMapFlags)[-1][y + 0x3b][x + b + 0x92] & 0x3000U;
    }
    if (((GRecords[recordIndex].kind & 3) == 1) && (acc == mask2) &&
        (ovr_ovc24_textArena(x,y,*(char *)((int)sheetRef + 0x3f)) == 0)) {
      if ((char)ovc23_isCursorAt(x,y) != '\0') {
        ovr_say((char *)"Construction abandoned.",0x2410);
      }
      if (recordIndex + 1U < GRecordCount) {
        _fmemmove((char *)CONCAT22(_DS,(char *)&GREC_FIELD(&GRecords[recordIndex], buildTimer, 0)),
                  (char *)CONCAT22(_DS,(char *)&GREC_FIELD(&GRecords[recordIndex + 1], buildTimer, 0)),
                  ((GRecordCount - recordIndex) + -1) * 0x12);
      }
      GRecordCount = GRecordCount - 1;
      ovc23_textAdlibNone();
    }
    else if (((GRecords[recordIndex].kind & 1) == 0) && ((mask1 & acc) != 0)) {
      GRecords[recordIndex].kind = GRecords[recordIndex].kind | 1;
    }
  }
  return;
}



/* 55fe:2b82 */

/* [R1] forwards to OVC23_55fe_29a2 */

void __cdecl16far OVC23_55fe_29a2_entry(void)

{
  int recordIndex;
  
  recordIndex = GRecordCount;
  while (recordIndex = recordIndex + -1, -1 < recordIndex) {
    ovc23_abandonConstruction(recordIndex);
  }
  return;
}



/* 55fe:2b9e */

/* [R7] body shape: compute */

uint __cdecl16far ovc23_compute1(int x,int y,byte bldType,uint8_t unitType)

{
  char bldFlags;
  byte neighbourType;
  int stepCoord;
  uint result;
  
  bldFlags = BuildingTypes[bldType].flags;
  if (bldFlags == '\0') {
    result = 0;
  }
  else if (bldFlags == '\x01') {
    neighbourType = ovr_ovc45_getUnitType(x,y + -1);
    if (BuildingTypes[neighbourType].flags == '\x02') {
      ovc23_placeBuilding(x,y,bldType + 2,unitType);
    }
    else {
      ovc23_placeBuilding(x,y,bldType,unitType);
    }
    neighbourType = ovr_ovc45_getUnitType(x + -1,y);
    if (BuildingTypes[neighbourType].flags == '\x02') {
      stepCoord = x + -1;
      ovc23_placeBuilding(stepCoord,y,neighbourType + 1,unitType);
    }
    result = CONCAT11((char)((uint)stepCoord >> 8),1);
  }
  else if (bldFlags == '\x02') {
    neighbourType = ovr_ovc45_getUnitType(x + 1,y);
    if (BuildingTypes[neighbourType].flags == '\x01') {
      ovc23_placeBuilding(x,y,bldType + 1,unitType);
    }
    else {
      ovc23_placeBuilding(x,y,bldType,unitType);
    }
    neighbourType = ovr_ovc45_getUnitType(x,y + 1);
    if (BuildingTypes[neighbourType].flags == '\x01') {
      stepCoord = y + 1;
      ovc23_placeBuilding(x,stepCoord,neighbourType + 2,unitType);
    }
    result = CONCAT11((char)((uint)stepCoord >> 8),1);
  }
  else if (bldFlags == '!') {
    neighbourType = ovr_ovc45_getUnitType(x + -1,y);
    result = (uint)neighbourType * 0x27;
    if (BuildingTypes[neighbourType].flags == '\x02') {
      result = x - 1;
      ovc23_placeBuilding(result,y,neighbourType + 1,unitType);
    }
    result = result & 0xff00;
  }
  else if (bldFlags == '\"') {
    neighbourType = ovr_ovc45_getUnitType(x,y + 1);
    result = (uint)neighbourType * 0x27;
    if (BuildingTypes[neighbourType].flags == '\x01') {
      result = y + 1;
      ovc23_placeBuilding(x,result,neighbourType + 2,unitType);
    }
    result = result & 0xff00;
  }
  else {
    result = 0;
  }
  return result;
}



/* 55fe:2da3 */

/* Scans four columns from alignUp4(x) for a cell with clear low flag bits and returns its x, else
   -1. */

int __cdecl16far ovc23_findClearColumn(int x,int y)

{
  uint uVar1;
  int iVar2;
  
  if (((*(short (*) [60] [148])GMapFlags)[y + 1][x] & 3U) != 0) {
    uVar1 = ovr_alignUp4(x,0,0);
    for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
      if (((*(short (*) [60] [148])GMapFlags)[y][uVar1 + iVar2 + 0x92] & 3U) == 0) {
        return uVar1 + iVar2 + -2;
      }
    }
    x = -1;
  }
  return x;
}



/* 55fe:2e2b */

/* [R7] body shape: compute */

int __cdecl16far ovc23_compute2(int x,uint16_t y)

{
  int iVar1;
  
  iVar1 = ovc23_findClearColumn(x,y);
  if (iVar1 < 0) {
    iVar1 = x;
  }
  return iVar1;
}



/* 55fe:2e4c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Drowns the units at (x,y): marks the cell and reports each drowning. */

void __cdecl16far ovc23_drownUnitsAt(uint16_t x,uint16_t y)

{
  uint16_t *flagPtr;
  char *entName;
  char *message;
  uint16_t dst;
  uint entityIndex;
  uint16_t notifySeg;
  uint16_t msgX;
  uint16_t msgY;
  static char text2[64];   /* DGROUP-backed formatting buffer */
  static char text[64];   /* DGROUP-backed formatting buffer */
  int clearCol;
  byte gindex;
  
  flagPtr = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y + 1] + x);
  *flagPtr = *flagPtr | 3;
  entityIndex = EntityCount;
  while (entityIndex = entityIndex - 1, -1 < (int)entityIndex) {
    notifySeg = (uint16_t)((ulong)Entities >> 0x10);
    if (((Entities)[entityIndex].base.x == x) &&
       ((Entities)[entityIndex].base.y == y)) {
      clearCol = ovc23_findClearColumn(x,y);
      notifySeg = (uint16_t)((ulong)Entities >> 0x10);
      if (clearCol < 0) {
        gindex = (Entities)[entityIndex].base.gindex;
        if (AgntGs[(uint)gindex].ai == '\0') {
          notifySeg = 0xa000;
          dst = 0x195d;
          msgX = x;
          msgY = y;
          entName = ovr_ovc15_capitalize(text2);
          message = ovr_stsprintf(text,(char *)CONCAT22(0x5665,_SS),
                                 (char *)CONCAT22(entName,(char *)0x26510),dst,msgX,msgY,
                                 notifySeg);
          ovr_uiNotify(message,dst,0);
        }
        ovr_ovc15_removeEntity(entityIndex);
      }
      else {
        (Entities)[entityIndex].base.x = clearCol;
      }
    }
  }
  return;
}



/* 55fe:2f90 */

/* [R6] touches GRecordCount */

byte __cdecl16far ovc23_usesGRecordCount3(byte amount,byte partyIndex,int recordIndex)

{
  /* 55fe:2f90 (file 0x4AD70), re-derived from the original:

       [bp-6] = (word)amount
       memset(&[bp-4], 0, 3)                         ; three byte counters
       for (si = 0; si < GRecordCount; si++) {
           if (GRecords[si].party != partyIndex) continue;
           if (GRecords[si].kind & 4)    [bp-4]++;
           if (GRecords[si].kind & 8)    [bp-3]++;
           if (GRecords[si].kind & 0x10) [bp-2]++;
       }
       sheet = GLeaderSheets[partyIndex]
       if (sheet[0x9c] > [bp-2])      { amount = amount*7/10;  kind |= 0x10; }
       else if (sheet[0x9b] > [bp-3]) { amount = amount*8/100; kind |= 8; }
       else if (sheet[0x9a] > [bp-4]) { amount = amount*9/10;  kind |= 4; }
       return amount                  ; only `mov al,[bp-6]` at 0x4AED1

     Corrections: the counters are named for the flag they count and are initialised
     directly instead of relying on a memset over three adjacent stack slots in declaration
     order; the return is a byte because the original sets only AL - the exported
     CONCAT11((char)((uint)iVar4 >> 8), uStack_8) was modelling a stale AH; and the repeated
     `(uint32_t)GLeaderSheets[partyIndex]` reads collapse to one local. */
  byte kind4Count;
  byte kind8Count;
  byte kind10Count;
  byte value;
  uint i;
  uint32_t sheetRef;

  value = amount;
  kind4Count = 0;
  kind8Count = 0;
  kind10Count = 0;
  for (i = 0; i < GRecordCount; i++) {
    if (GRecords[i].party == partyIndex) {
      if ((GRecords[i].kind & 4) != 0) {
        kind4Count = kind4Count + 1;
      }
      if ((GRecords[i].kind & 8) != 0) {
        kind8Count = kind8Count + 1;
      }
      if ((GRecords[i].kind & 0x10) != 0) {
        kind10Count = kind10Count + 1;
      }
    }
  }
  sheetRef = (uint32_t)GLeaderSheets[partyIndex];
  if (*(byte *)((int)sheetRef + 0x9c) > kind10Count) {
    value = (byte)((uint)value * 7 / 10);
    GRecords[recordIndex].kind = GRecords[recordIndex].kind | 0x10;
  }
  else if (*(byte *)((int)sheetRef + 0x9b) > kind8Count) {
    value = (byte)(((uint)value << 3) / 100);
    GRecords[recordIndex].kind = GRecords[recordIndex].kind | 8;
  }
  else if (*(byte *)((int)sheetRef + 0x9a) > kind4Count) {
    value = (byte)((uint)value * 9 / 10);
    GRecords[recordIndex].kind = GRecords[recordIndex].kind | 4;
  }
  return value;
}



/* 55fe:3450 */

/* rounds a byte offset up to the next multiple of four */

uint __cdecl16far alignUp4(int value,uint16_t arg2,uint16_t arg3)

{
  return value + 2U & 0xfffc;
}


