/*
 * ovc18_leaderview.c - recovered from STRONG.EXE
 * memory block: OVC18_leaderview.c
 * range: 48ac:0000 - 48ac:150f
 * functions: 9
 */
#include "recovered.h"


/* 48ac:0000 */

/* Blits the trianglsCut4 graphic to the screen and sets its loaded flag. */

void __cdecl16far ovc18_blitTriangles(void)

{
  far_t gfx;
  
  gfx.seg = trianglsCut4Seg;
  gfx.ofs = trianglsCut4Ofs;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c306)),0);
  trianglesShown = 1;
  return;
}



/* 48ac:0027 */

/* Blits the nwpanel1Cut4 panel to the screen when GameRunning is clear. */

void __cdecl16far ovc18_blitPanelIfNotRunning(void)

{
  far_t gfx;
  
  if (!GameRunning) {
    gfx.seg = nwpanel1Cut4Seg;
    gfx.ofs = nwpanel1Cut4Ofs;
    ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c306)),0);
  }
  return;
}



/* 48ac:0051 */

/* Shows the "View %s." description and graphics for the leader standing on the cursor cell. */

void __cdecl16far ovc18_showLeaderView(void)

{
  bool arenaReady;
  char *msg;
  uint placeResult;
  char *nameOfs;
  int leaderIdx;
  uint8_t partyCounts;
  char *savedNameOfs;
  uint16_t nameSeg;
  
  trianglesShown = 0;
  if ((MsgShown != '\0') || (GameRunning)) {
    MsgShown = '\0';
  }
  else {
    _fmemset(MK_FP(_SS, &savedNameOfs), 0, 2);
    for (leaderIdx = 0; leaderIdx < (int)(uint)GLeaderCount; leaderIdx = leaderIdx + 1) {
      if ((((GLeaderSheets[leaderIdx])->active != '\0') &&
          ((&partyCounts)[*((uint8_t far *)GLeaderSheets[leaderIdx] + 0x3f)] =
                (&partyCounts)[*((uint8_t far *)GLeaderSheets[leaderIdx] + 0x3f)] + 0x1,
          (GLeaderSheets[leaderIdx])->x == GfxRndSeed)) &&
         ((GLeaderSheets[leaderIdx])->y == GfxRndSeed2)) {
        arenaReady = ovr_draw_textArena();
        if (!arenaReady) {
          return;
        }
        nameSeg = (uint16_t)SEG_OF(GLeaderSheets[leaderIdx]);
        nameOfs = (char *)far_ofs_u32(GLeaderSheets[leaderIdx]);
        savedNameOfs = nameOfs;
        if (GameRunning == false) {
          msg = ovr_fmVsprintf("View %s.",(char *)CONCAT22(nameSeg,nameOfs));
          ovr_say(msg,nameOfs);
        }
        ovc18_blitTriangles();
        return;
      }
    }
    if (PartyCount != 0) {
      nameSeg = (uint16_t)SEG_OF(GLeaderSheets[PartyCount - 1]);
      nameOfs = (char *)far_ofs_u32(GLeaderSheets[PartyCount - 1]);
      savedNameOfs = nameOfs;
      placeResult = ovc18_usesAlignUp4();
      if ((char)placeResult == '\0') {
        msg = ovr_fmVsprintf("View %s. (Cannot place)",(char *)CONCAT22(nameSeg,savedNameOfs));
        ovr_say(msg,nameOfs);
      }
      else {
        msg = ovr_fmVsprintf("Place %s.",(char *)CONCAT22(nameSeg,savedNameOfs));
        ovr_say(msg,nameOfs);
      }
      trianglesShown = 1;
      ovc18_blitTriangles();
      return;
    }
    if (CurPartySlot < PartySize) {
      if (GameRunning == false) {
        if (CurPartySlot == 0) {
          ovr_say((char *)"Create baron or baroness.",0x2410);
        }
        else {
          ovr_say((char *)"Create party member.",0x2410);
        }
      }
      trianglesShown = 1;
      ovc18_blitTriangles();
      return;
    }
  }
  ovc18_blitPanelIfNotRunning();
  return;
}



/* 48ac:0251 */
uint8_t * __cdecl16far
ovc18_spawnClassAgent
          (uint16_t x,uint16_t y,uint16_t destX,uint16_t destY,uint8_t classStr,uint8_t partyIndex,
          uint16_t mode)

{
  uint8_t sprite;
  uint8_t leaderClass;

  leaderClass = (GLeaderSheets[partyIndex])->classStr;
  if ((AgntGs[(uint)leaderClass].flags3 & 0x800) != 0) {
    /* random sprite index; 0x13/0x19/6/0x1a as the image's five-entry jump table stores them */
    switch ((uint16_t)(ovr_randBelow(5,0) & 0xff)) {
    case 0:
      sprite = 0x13;
      break;
    case 1:
      sprite = 0x19;
      break;
    case 2:
      sprite = 6;
      break;
    default:
      sprite = 0x1a;
      break;
    }
  }
  else if ((byte)classStr < 6) {
    sprite = 6;
  }
  else if ((byte)classStr < 0xb) {
    sprite = 0x19;
  }
  else {
    sprite = 0x13;
  }
  if ((byte)mode == 2) {
    return (uint8_t *)
           ovr_ovc15_usesLDIV_at_(x,y,destX,destY,sprite,0xa,partyIndex);
  }
  return (uint8_t *)
         ovr_ovc15_usesLDIV_at_
                   (x,y,destX,destY,sprite,
                    *(uint8_t *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0xa4),partyIndex);
}


/* 48ac:0382 */

/* Places the leader's figure: one of seven fixed sprite indices by class, two coin flips for
   class 0, the class's own animation index for 0xff, and then a spawnClassAgent pass when the
   class record's flags2 bit 0x8000 is set.  Re-derived from the image; the former body held
   another function's text-drawing code (see doc/step6_entry.md). */

char * __cdecl16far
ovc18_textTypeLen
          (uint8_t partyIndex,uint16_t destX,uint16_t destY,uint8_t mode)

{
  uint8_t classStr;
  uint16_t sheetX;
  uint16_t sheetY;
  char_sheet_t far *sheet;

  sheet = GLeaderSheets[partyIndex];
  sheetX = sheet->x;
  sheetY = sheet->y;
  switch (sheet->cls) {
  case 0:
    if ((ovr_randBelow(2,0) & 0xff) == 0) {
      ovr_ovc15_usesLDIV_at_(sheetX,sheetY,destX,destY,0,1,partyIndex);
      if ((ovr_randBelow(2,0) & 0xff) == 0) {
        ovr_ovc15_usesLDIV_at_(sheetX,sheetY,destX,destY,5,1,partyIndex);
      }
    }
    else {
      ovr_ovc15_usesLDIV_at_(sheetX,sheetY,destX,destY,5,1,partyIndex);
      if ((ovr_randBelow(2,0) & 0xff) == 0) {
        ovr_ovc15_usesLDIV_at_(sheetX,sheetY,destX,destY,0,1,partyIndex);
      }
    }
    break;
  case 1:
    ovr_ovc15_usesLDIV_at_(sheetX,sheetY,destX,destY,1,1,partyIndex);
    break;
  case 2:
    ovr_ovc15_usesLDIV_at_(sheetX,sheetY,destX,destY,2,1,partyIndex);
    break;
  case 3:
    ovr_ovc15_usesLDIV_at_(sheetX,sheetY,destX,destY,3,1,partyIndex);
    break;
  case 4:
    ovr_ovc15_usesLDIV_at_(sheetX,sheetY,destX,destY,0xa,1,partyIndex);
    break;
  case 5:
    ovr_ovc15_usesLDIV_at_(sheetX,sheetY,destX,destY,8,1,partyIndex);
    break;
  case 6:
    ovr_ovc15_usesLDIV_at_(sheetX,sheetY,destX,destY,0xb,1,partyIndex);
    break;
  case 0xff:
    classStr = sheet->classStr;
    if ((AgntGs[(uint)classStr].flags3 & 0x800) == 0) {
      ovr_ovc15_usesLDIV_at_(sheetX,sheetY,destX,destY,sheet->classStr,1,partyIndex);
    }
    break;
  }
  classStr = sheet->classStr;
  if ((AgntGs[(uint)classStr].flags2 & 0x8000) != 0) {
    return (char *)
           ovc18_spawnClassAgent(sheetX,sheetY,destX,destY,1,partyIndex,mode);
  }
  return (char *)0x0;
}


/* 48ac:05f2 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Checks a fortress site and reports the matching rejection message. */

void __cdecl16far ovc18_checkFortressPlacement(char strongholdKind)

{
  undefined1 stk_ffea;   /* stack slot ffea */
  undefined1 stk_ffec;   /* stack slot ffec */
  uint32_t lastPartyPtr;
  far_t dst;
  bool arenaDrawn;
  uint uVar3;
  char *textPtr;
  undefined1 *bufPtr;
  uint entSign;
  uint uVar3Sign;
  uint entityIndex;
  int leaderIndex;
  uint16_t unaff_DI;
  undefined1 xLo;
  undefined1 xHi;
  char partyIndex;
  undefined1 auStack_12 [13];
  uint8_t uStack_5;
  uint foundIdx;
  
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = (char)_SS;
  dst.ofs = (uint16_t)auStack_12;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = (char)((uint)_SS >> 8);
  F_SCOPY(far_from_u32((uint32_t)(0x241045b9)),dst,12);
  for (entityIndex = 0; partyIndex = (char)unaff_DI, entityIndex < EntityCount; entityIndex = entityIndex + 1) {
    if (AgntGs[(uint)(Entities)[entityIndex].base.gindex].ai != '\0') {
      uVar3 = ovr_alignUp4((Entities)[entityIndex].base.x,0,0);
      xLo = (undefined1)uVar3;
      xHi = (undefined1)(uVar3 >> 8);
      uVar3 = ovr_alignUp4(GfxRndSeed,0,0);
      if ((CONCAT11(xHi,xLo) == uVar3) &&
         ((Entities)[entityIndex].base.y == GfxRndSeed2)) {
        ovr_stats_openCastlePanel();
        ovr_say((char *)"A fortress cannot be placed among enemy units.",0x10);
        MsgShown = 1;
        return;
      }
    }
  }
  for (leaderIndex = 0; leaderIndex < (int)(uint)GLeaderCount; leaderIndex = leaderIndex + 1) {
    if ((((GLeaderSheets[leaderIndex])->active != '\0') &&
        ((GLeaderSheets[leaderIndex])->x == GfxRndSeed)) &&
       ((GLeaderSheets[leaderIndex])->y == GfxRndSeed2)) {
      ovr_stats_openCastlePanel();
      ovr_say((char *)"Cannot place another fortress here.",0x10);
      MsgShown = 1;
      return;
    }
  }
  if (strongholdKind == '\x02') {
    entityIndex = ovr_constr_usesGMapFlags(GfxRndSeed - 2,GfxRndSeed2,(char)GfxRndSeed2);
    if ((((entityIndex & 0xff) == 0) ||
        (entityIndex = ovr_constr_usesGMapFlags(GfxRndSeed - 1,GfxRndSeed2,(char)GfxRndSeed2),
        (entityIndex & 0xff) == 0)) ||
       ((entityIndex = ovr_constr_usesGMapFlags(GfxRndSeed,GfxRndSeed2,(char)GfxRndSeed2),
        (entityIndex & 0xff) == 0 ||
        (entityIndex = ovr_constr_usesGMapFlags(GfxRndSeed + 1,GfxRndSeed2,(char)GfxRndSeed2),
        (entityIndex & 0xff) == 0)))) {
      ovr_stats_openCastlePanel();
      bufPtr = &stk_ffea;
      textPtr = ovr_fmVsprintf("This location is unsuitable for a main stronghold.  %s",
                              (char *)CONCAT13((char)((uint)*(uint16_t *)
                                                             (&stk_ffec +
                                                             (uint)placementStatus * 4) >> 8),
                                               CONCAT12((char)*(uint16_t *)
                                                               (&stk_ffec +
                                                               (uint)placementStatus * 4),
                                                        *(uint16_t *)
                                                         (bufPtr + (uint)placementStatus * 4))));
      ovr_say(textPtr,(char)bufPtr);
      MsgShown = 1;
      return;
    }
  }
  else {
    entityIndex = ovr_constr_usesGMapFlags(GfxRndSeed - 1,GfxRndSeed2,(char)GfxRndSeed2);
    if (((entityIndex & 0xff) == 0) ||
       (entityIndex = ovr_constr_usesGMapFlags(GfxRndSeed,GfxRndSeed2,(char)GfxRndSeed2),
       (entityIndex & 0xff) == 0)) {
      ovr_stats_openCastlePanel();
      bufPtr = &stk_ffea;
      textPtr = ovr_fmVsprintf("This location is unsuitable.  %s",
                              (char *)CONCAT13((char)((uint)*(uint16_t *)
                                                             (&stk_ffec +
                                                             (uint)placementStatus * 4) >> 8),
                                               CONCAT12((char)*(uint16_t *)
                                                               (&stk_ffec +
                                                               (uint)placementStatus * 4),
                                                        *(uint16_t *)
                                                         (bufPtr + (uint)placementStatus * 4))));
      ovr_say(textPtr,(char)bufPtr);
      MsgShown = 1;
      return;
    }
  }
  arenaDrawn = ovr_draw_textArena();
  if (arenaDrawn) {
    if (1 < CurPartySlot) {
      foundIdx = 0xffff;
      for (leaderIndex = 0; leaderIndex < (int)(uint)GLeaderCount; leaderIndex = leaderIndex + 1) {
        if ((((GLeaderSheets[leaderIndex])->active != '\0') &&
            (*((char far *)GLeaderSheets[leaderIndex] + 0x3f) == '\0')) &&
           (entityIndex = (GLeaderSheets[leaderIndex])->x - GfxRndSeed,
           entSign = (int)entityIndex >> 0xf,
           uVar3 = (GLeaderSheets[leaderIndex])->y - GfxRndSeed2,
           uVar3Sign = (int)uVar3 >> 0xf, entityIndex = ((entityIndex ^ entSign) - entSign) + ((uVar3 ^ uVar3Sign) - uVar3Sign),
           entityIndex < foundIdx)) {
          foundIdx = entityIndex;
        }
      }
      if (0x1e < foundIdx) {
        ovr_stats_openCastlePanel();
        ovr_say((char *)"Your stronghold is too far away.",0x10);
        MsgShown = 1;
        return;
      }
    }
    lastPartyPtr = *(uint32_t *)((uint)PartyCount * 4 + -4);
    *(uint16_t *)((int)lastPartyPtr + 0x39) = GfxRndSeed;
    lastPartyPtr = *(uint32_t *)((uint)PartyCount * 4 + -4);
    *(uint16_t *)((int)lastPartyPtr + 0x3b) = GfxRndSeed2;
    lastPartyPtr = *(uint32_t *)((uint)PartyCount * 4 + -4);
    *(undefined1 *)((int)lastPartyPtr + 0x3d) = 1;
    lastPartyPtr = *(uint32_t *)((uint)PartyCount * 4 + -4);
    *(char *)((int)lastPartyPtr + 0x89) = CurPartySlot - 1;
    if (strongholdKind == '\x02') {
      lastPartyPtr = *(uint32_t *)((uint)PartyCount * 4 + -4);
      *(undefined1 *)((int)lastPartyPtr + 0x5a) = 1;
      ovr_createConstructionRecordFar
                (0x89,GfxRndSeed - 2,GfxRndSeed2,(uint8_t *)CONCAT22(_SS,&uStack_5),
                 PartyCount - 1,partyIndex,(char)GfxRndSeed2,(char)&uStack_5,PartyCount - 1);
      ovc18_textTypeLen(PartyCount - 1,GfxRndSeed,GfxRndSeed2,0x0);
      ovr_ovc22_usesRandBelow2(PartyCount - 1,(uint16_t)&uStack_5);
    }
    else {
      lastPartyPtr = *(uint32_t *)((uint)PartyCount * 4 + -4);
      *(char *)((int)lastPartyPtr + 0x5a) = strongholdKind;
      lastPartyPtr = *(uint32_t *)((uint)PartyCount * 4 + -4);
      ovr_createConstructionRecordFar
                (*(byte *)((int)(far_t *)(worldMenuLabels + 0xb) +
                          (uint)*(byte *)((int)lastPartyPtr + 0x3e) * 0x95),GfxRndSeed - 1,GfxRndSeed2,
                 (uint8_t *)CONCAT22(_SS,&uStack_5),PartyCount - 1,partyIndex,(char)GfxRndSeed2
                 ,(char)&uStack_5,PartyCount - 1);
      ovc18_textTypeLen(PartyCount - 1,GfxRndSeed,GfxRndSeed2,0x0);
    }
    if (2 < Difficulty) {
      ovr_ovc22_usesRandBelow2(PartyCount - 1,(uint16_t)&uStack_5);
    }
    ovr_ovc22_textRingProt(PartyCount - 1);
    PartyCount = 0;
    ovr_manage_mapPartySlots();
    ovr_stats_openCastlePanel();
    ovr_unit_usesAlignUp4();
    ovr_say((char *)0x286cd,0x10);
    if (PlayerIndex == '\0') {
      ovr_ovc30_nextWave(2);
    }
  }
  else {
    ovr_stats_openCastlePanel();
    ovr_say((char *)"Your stronghold is too far away.",0x10);
    MsgShown = 1;
  }
  return;
}



/* 48ac:0bf4 */

/* [R4] calls ovr_randBelow */

uint __cdecl16far ovc18_usesRandBelow(int x,int y,byte bldType,byte unitType,uint16_t arg5,uint16_t arg6)

{
  uint16_t *puVar1;
  uint uVar2;
  uint16_t randDraw;
  short (*paasVar4) [148] [60];
  uint unaff_SI;
  uint16_t uVar6;
  uint uStack_6;
  
  paasVar4 = (short (*) [148] [60])GUnitGrid;
  uVar6 = (uint16_t)((ulong)GUnitGrid >> 0x10);
  if (bldType == 0) {
    if ((uint)(*paasVar4)[x][y] < 0xf8) {
      (*paasVar4)[x][y] = 0;
    }
    else {
      unaff_SI = (*paasVar4)[x][y];
      (GUnits + unaff_SI)->bldType = 0;
      (GUnits)[unaff_SI].level = 8;
      (GUnits)[unaff_SI].unitType = 0xff;
      (*(short (*) [148] [60])GUnitGrid)[x][y] = 0;
    }
    puVar1 = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y] + x);
    *puVar1 = *puVar1 & 0x3fff;
  }
  else {
    if ((uint)(*paasVar4)[x][y] < 0xf8) {
      unaff_SI = 0xf8;
      while ((unaff_SI < GUnitCount && ((GUnits + unaff_SI)->bldType != 0))) {
        unaff_SI = unaff_SI + 1;
      }
      if (GUnitCount <= unaff_SI) {
        if (GUnitCount + 1 < 0x4b0) {
          GUnitCount = GUnitCount + 1;
        }
        else {
          randDraw = ovr_randBelow(0x3b8,0);
          uVar2 = (randDraw & 0xff) + 0xf8;
          unaff_SI = uVar2;
          do {
            if ((((*(uint *)((uint8_t *)&BuildingTypes[unaff_SI] + 19) & 0xa0) != 0) ||
                (*(char *)((uint8_t *)&BuildingTypes[unaff_SI] + 37) == '\0')) ||
               (*(char *)((uint8_t *)&BuildingTypes[unaff_SI] + 37) == '\a')) break;
            unaff_SI = unaff_SI + 1;
            if (0x4af < unaff_SI) {
              unaff_SI = 0xf8;
            }
          } while (uVar2 != unaff_SI);
          for (uStack_6 = 0; uStack_6 < 0x94; uStack_6 = uStack_6 + 1) {
            for (uVar2 = 0; uVar2 < 0x3c; uVar2 = uVar2 + 1) {
              uVar6 = (uint16_t)((ulong)GUnitGrid >> 0x10);
              if ((*(short (*) [148] [60])GUnitGrid)[uStack_6][uVar2] == unaff_SI) {
                (*(short (*) [148] [60])GUnitGrid)[uStack_6][uVar2] = 0;
              }
            }
          }
        }
      }
    }
    else {
      unaff_SI = (*paasVar4)[x][y];
    }
    (GUnits + unaff_SI)->bldType = bldType;
    (GUnits)[unaff_SI].level = 8;
    (GUnits)[unaff_SI].unitType = unitType;
    (GUnits)[unaff_SI].x = x;
    (GUnits)[unaff_SI].y = y;
    (*(short (*) [148] [60])GUnitGrid)[x][y] = unaff_SI;
    uVar6 = (uint16_t)((ulong)GMapFlags >> 0x10);
    (*(short (*) [60] [148])GMapFlags)[y][x] =
         (*(short (*) [60] [148])GMapFlags)[y][x] & 0x3fffU |
         (uint)BuildingTypes[bldType].flags << 0xe;
    if ((BuildingTypes[bldType].flags2 & 0x40) == 0) {
      (GUnits)[unaff_SI].timer = 0;
    }
    else {
      uVar2 = ovr_constr_usesGMapFlags2(x,y);
      if ((uVar2 & 0xff) == 3) {
        randDraw = ovr_randBelow(0x28,0);
        (GUnits)[unaff_SI].timer = (char)randDraw + 0x1e;
      }
      else if ((uVar2 & 0xff) == 4) {
        randDraw = ovr_randBelow(0x50,0);
        (GUnits)[unaff_SI].timer = (char)randDraw + 0x3c;
      }
      else {
        randDraw = ovr_randBelow(0x14,0);
        (GUnits)[unaff_SI].timer = (char)randDraw + 0xf;
      }
    }
  }
  return unaff_SI;
}



/* 48ac:1022 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R2] string "arena" */

bool __cdecl16far ovc18_textArena(uint16_t x,uint16_t y)

{
  uint xAligned;
  uint entX;
  uint uVar3;
  
  xAligned = ovr_alignUp4(x,0,0);
  uVar3 = 0;
  while( true ) {
    if (EntityCount <= uVar3) {
      return false;
    }
    entX = ovr_alignUp4((Entities)[uVar3].base.x,0,0);
    if ((entX == xAligned) && ((Entities)[uVar3].base.y == y)) break;
    uVar3 = uVar3 + 1;
  }
  return true;
}



/* 48ac:1092 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

byte __cdecl16far ovc18_usesAlignUp4(void)

{
  /* Re-derived: 1 when the cursor may place a unit - not on an entity, not on a leader, and the
     two cells to the left free; additionally the cells two-left and one-right when CurPartySlot
     is 1, and no active leader further than 0x1e away when it is above 1.  The exported
     `return uVar5 & 0xff00` in the leader branch was stale AH: ip 0x0110 is `mov al,0`. */
  bool inArena;
  bool blocked;
  uint entAlignedX;
  uint cursorAlignedX;
  uint dx;
  uint dxSign;
  uint dy;
  uint dySign;
  uint dist;
  uint bestDist;
  uint ok;
  int leaderIdx;

  inArena = ovr_draw_textArena();
  if (inArena == false) {
    return 0;
  }
  for (leaderIdx = 0; leaderIdx < (int)(uint)EntityCount; leaderIdx = leaderIdx + 1) {
    if (AgntGs[(uint)(Entities)[leaderIdx].base.gindex].ai != '\0') {
      entAlignedX = ovr_alignUp4((Entities)[leaderIdx].base.x,0,0);
      cursorAlignedX = ovr_alignUp4(GfxRndSeed,0,0);
      if ((entAlignedX == cursorAlignedX) &&
         ((uint)(Entities)[leaderIdx].base.y == (uint)GfxRndSeed2)) {
        return 0;
      }
    }
  }
  for (leaderIdx = 0; leaderIdx < (int)(uint)GLeaderCount; leaderIdx = leaderIdx + 1) {
    if (((GLeaderSheets[leaderIdx])->active != '\0') &&
       ((GLeaderSheets[leaderIdx])->x == GfxRndSeed) &&
       ((GLeaderSheets[leaderIdx])->y == GfxRndSeed2)) {
      return 0;
    }
  }
  ok = ovr_constr_usesGMapFlags(GfxRndSeed + -1,GfxRndSeed2,0);
  blocked = ((ok & 0xff) == 0);
  if (blocked == false) {
    ok = ovr_constr_usesGMapFlags(GfxRndSeed,GfxRndSeed2,0);
    blocked = ((ok & 0xff) == 0);
  }
  if (blocked) {
    return 0;
  }
  if (CurPartySlot == 1) {
    ok = ovr_constr_usesGMapFlags(GfxRndSeed + -2,GfxRndSeed2,0);
    blocked = ((ok & 0xff) == 0);
    if (blocked == false) {
      ok = ovr_constr_usesGMapFlags(GfxRndSeed + 1,GfxRndSeed2,0);
      blocked = ((ok & 0xff) == 0);
    }
    if (blocked) {
      return 0;
    }
  }
  if (1 < CurPartySlot) {
    bestDist = 0xffff;
    for (leaderIdx = 0; leaderIdx < (int)(uint)GLeaderCount; leaderIdx = leaderIdx + 1) {
      if (((GLeaderSheets[leaderIdx])->active != '\0') &&
         (*((char far *)GLeaderSheets[leaderIdx] + 0x3f) == '\0')) {
        dx = (GLeaderSheets[leaderIdx])->x - GfxRndSeed;
        dxSign = (int)dx >> 0xf;
        dy = (GLeaderSheets[leaderIdx])->y - GfxRndSeed2;
        dySign = (int)dy >> 0xf;
        dist = ((dx ^ dxSign) - dxSign) + ((dy ^ dySign) - dySign);
        if (dist < bestDist) {
          bestDist = dist;
        }
      }
    }
    if (0x1e < bestDist) {
      return 0;
    }
  }
  return 1;
}


