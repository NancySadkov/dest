/*
 * ovc47_constrct.c - recovered from STRONG.EXE
 * memory block: OVC47_constrct.c
 * range: 7e7c:0000 - 7e7c:33cf
 * functions: 6
 */
#include "recovered.h"


/* 7e7c:0000 */

/* [R6] touches GLeaderCount */

void __cdecl16far constrct_usesGLeaderCount(void)

{
  int iVar1;
  uint8_t outFlag;
  byte bStack_3;
  
  outFlag = 0x0;
  for (bStack_3 = 0; bStack_3 < GLeaderCount; bStack_3 = bStack_3 + 1) {
    for (iVar1 = 0; iVar1 < 10; iVar1 = iVar1 + 1) {
      ovr_ovc22_usesRandBelow2(bStack_3,(uint16_t)&outFlag,_SS);
    }
  }
  if (outFlag != 0x0) {
    ovr_constr_flushDirtyRects();
  }
  return;
}



/* 7e7c:004b */
void __cdecl16far land_info(byte tileOffset)

{
  byte b;
  far_t entries;
  far_t entries_00;
  far_t entries_01;
  char keyPressed;
  uint tileVal;
  uint unitIdx;
  uint menuCount;
  uint16_t sfxRoll;
  uint16_t retSegB;
  char *textMsg;
  uint16_t *wordPair;
  int computed;
  uint8_t *stashOfs;
  uint16_t retSeg;
  uint16_t entrySeg;
  int pctRemaining;
  unit_t *units;
  uint16_t gUnitsSeg;
  uint16_t entitiesSeg;
  uint16_t mapFlag;
  uint16_t msgSeg;
  uint16_t choice;
  undefined1 entryLo;
  undefined1 delayArg;
  undefined1 ssLo;
  undefined1 ssHi;
  int16_t type;
  far_t hint;
  far_t hint_00;
  far_t hint_01;
  static char text2[64];   /* DGROUP-backed formatting buffer */
  static char text1[64];   /* DGROUP-backed formatting buffer */
  uint8_t menuItems;
  uint16_t segTable [19];
  uint8_t msg;
  char tileClass;
  byte unitType;
  char again;
  uint8_t foundFlag;
  byte tileIdx;
  uint8_t entityIndex;
  uint8_t outFlag;
  byte bldType;
  char resultCode;
  char choiceCode;
  char itemCode;
  uint8_t tileX;
  uint8_t gfxOfs;
  undefined1 menuCodes [10];
  uint8_t menuLabel;
  uint16_t tableOfs;
  uint16_t arg2Pair;
  uint16_t tableSeg;
  
  gfxOfs = far_t_2410_78e4.ofs;
  ovr_attact_usesAgntFlag1();
  savedMenuItem = GMenuItem;
  outFlag = 0x0;
  ovr_ovc18_blitPanelIfNotRunning();
  if ('\x02' < (char)tileOffset) {
    tileOffset = 3;
  }
  if ((char)tileOffset < '\0') {
    tileOffset = 0;
  }
  tileIdx = 0xff;
  unitType = 0xff;
  tileX = (GfxRndSeed + (int)(char)tileOffset) - 2;
  tileVal = ovr_ovc45_usesGfxRndSeed2((int *)&tileX);
  bldType = (byte)tileVal;
  unitIdx = ovr_ovc45_getUnitIndex(tileX,GfxRndSeed2);
  gUnitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
  if ((GUnits)[unitIdx].unitType != 0xff) {
    unitType = (GUnits)[unitIdx].unitType;
  }
  if (GTileRecords[tileOffset] != -1) {
    if (*(char *)(GTileRecords[tileOffset] * 0x12 + 0xc) == '\0') {
      *(undefined1 *)(GTileRecords[tileOffset] * 0x12 + 0xc) = 1;
    }
    tileIdx = tileOffset;
    unitType = *(byte *)(GTileRecords[tileIdx] * 0x12 + 9);
  }
  if (((BuildingTypes[bldType].flags2 & 0x80) == 0) &&
     ((GUnits)[unitIdx].level < 3)) {
    type = 0;
    sfxRoll = ovr_randBelow(2,0);
    ovr_play_sfx(CONCAT11((char)(sfxRoll >> 8),(char)sfxRoll + '?'),type,0);
  }
  ssLo = SUB21(_SS,0);
  ssHi = (undefined1)((uint)_SS >> 8);
  textMsg = ovr_ovc45_findEntityAt
                     (GfxRndSeed,GfxRndSeed2,(uint *)&entityIndex,(char)GfxRndSeed2,
                      (char)&entityIndex);
  resultCode = (char)textMsg;
  if (resultCode == -1) {
    ovr_ovc41_enterLeaderView();
  }
  else {
    if (resultCode == '\0') {
      if (tileIdx == 0xff) {
        gUnitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
        units = GUnits;
        if (units[unitIdx].unitType == 0xff) {
          if (bldType == 0) {
            mapFlag = ovr_ovc45_usesGMapFlags4(tileX,GfxRndSeed2);
            tileClass = (char)mapFlag;
          }
          else {
            tileClass = '\0';
          }
          if (tileClass == '\x02') {
            strcpy((char *)CONCAT22(_SS,&msg),"Water:");
          }
          else if (tileClass == '\x01') {
            strcpy((char *)CONCAT22(_SS,&msg),"Shore:");
          }
          else {
            stashOfs = ovr_ovc15_usesStshRealloc
                               ((char *)BLD_WORD(&BuildingTypes[bldType], name, 0),0,0,0,0,0,0,0);
            asm { mov retSeg,dx };
            textMsg = ovr_fmVsprintf("%s:",(char *)CONCAT22(retSeg,stashOfs));
            strcpy((char *)CONCAT22(_SS,&msg),(char *)CONCAT22(retSeg,textMsg));
          }
        }
        else if (BuildingTypes[bldType].durability == 'd') {
          stashOfs = ovr_ovc15_usesStshRealloc
                             ((char *)BLD_WORD(&BuildingTypes[bldType], name, 0),BLD_WORD(&BuildingTypes[bldType], name, 2),*(uint16_t *)((uint)units[unitIdx].unitType * 4),0,0,0,0,0);
          asm { mov retSeg,dx };
          textMsg = ovr_fmVsprintf("%s: Held by %s.",(char *)CONCAT22(retSeg,stashOfs));
          strcpy((char *)CONCAT22(_SS,&msg),(char *)CONCAT22(retSeg,textMsg));
        }
        else {
          b = BuildingTypes[bldType].durability;
          computed = ovr_ovc45_compute7(units[unitIdx].level,b,b,
                                      (uint)BuildingTypes[bldType].durability,
                                      *(uint16_t *)((uint)units[unitIdx].unitType * 4));
          stashOfs = ovr_ovc15_usesStshRealloc
                             ((char *)BLD_WORD(&BuildingTypes[bldType], name, 0),(char)BLD_WORD(&BuildingTypes[bldType], name, 2),(char)computed,0,0,0,0,0);
          asm { mov retSeg,dx };
          textMsg = ovr_fmVsprintf("%s (%u/%u): Held by %s.",
                                  (char *)CONCAT13((char)((uint)retSeg >> 8),
                                                   CONCAT12((char)retSeg,stashOfs)));
          strcpy((char *)CONCAT22(_SS,&msg),(char *)CONCAT22(retSeg,textMsg));
          keyPressed = func_0x0007164e(0x1000);
          if (keyPressed != '\0') {
            strcat((char *)CONCAT22(_SS,&msg)," Home a unit here to halt damage.");
          }
        }
      }
      else {
        bldType = *(byte *)(GTileRecords[tileIdx] * 0x12 + 8);
        wordPair = (uint16_t *)
                 ((uint)*(byte *)(GTileRecords[tileIdx] * 0x12 + 9) * 4);
        entrySeg = wordPair[1];
        entrySeg = *wordPair;
        entryLo = (undefined1)entrySeg;
        computed = ovr_ovc45_compute9(text1,
                                   (char *)CONCAT13((char)((uint)entrySeg >> 8),
                                                    CONCAT12(entryLo,_SS)),
                                   (char *)CONCAT13((char)(Font03.ofs >> 8),
                                                    CONCAT12((char)Font03.ofs,entrySeg)),Font03.seg,
                                   -0x47,entryLo,(char)entrySeg,(char)Font03.ofs);
        stashOfs = ovr_ovc15_usesStshRealloc
                           ((char *)BLD_WORD(&BuildingTypes[bldType], name, 0),(char)BLD_WORD(&BuildingTypes[bldType], name, 2),100 - ((uint)*(byte *)(GTileRecords[tileIdx] * 0x12 +
                                                  0xb) * 100) /
                                  (uint)*(byte *)(GTileRecords[tileIdx] * 0x12 +
                                                 0xc),computed,0,0,0,0);
        asm { mov retSeg,dx };
        textMsg = ovr_fmVsprintf("%s: %d%% complete. Owned by %s.",
                                (char *)CONCAT13((char)((uint)retSeg >> 8),
                                                 CONCAT12((char)retSeg,stashOfs)));
        strcpy((char *)CONCAT22(_SS,&msg),(char *)CONCAT22(retSeg,textMsg));
      }
      hint.seg = (uint16_t)_SS;
      hint.ofs = (uint16_t)&msg;
      stashOfs = &gfxOfs;
      (*(uint8_t *)((uint8_t *)&(entries.seg))) = ssLo;
      entries.ofs = (uint16_t)stashOfs;
      (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = ssHi;
      ovr_ovc28_compute2(entries,1,hint,0,0);
      itemCode = (char)stashOfs;
    }
    else if (tileIdx == 0xff) {
      if (((BuildingTypes[bldType].flags2 & 2) == 0) || (0xf7 < unitIdx)) {
        if (((BuildingTypes[bldType].flags2 & 0x20) == 0) || (0xf7 < unitIdx)) {
          if (bldType == 0) {
            ovr_ovc45_buildPlacementMessage
                      ((char)(GfxRndSeed + (int)(char)tileOffset + -2),(char)GfxRndSeed2,
                       entityIndex,(uint)textMsg & 0xff,foundFlag);
          }
          else {
            /* The image pushes five arguments; the Ghidra text had collapsed them into three. */
            constrct_buildInfoText((int)(char)tileOffset,
                                   (byte far *)MK_FP(_SS,(uint16_t)&outFlag),entityIndex,0,0);
          }
        }
        else {
          ovr_ovc45_textDone2(foundFlag,bldType,entityIndex,tileX,(uint16_t)&outFlag,
                              (uint16_t)_SS,bldType,(char)entityIndex);
        }
      }
      else {
        ovr_ovc45_textDone(foundFlag,bldType,entityIndex,tileX,(uint16_t)&outFlag,
                           (uint16_t)_SS,bldType,(char)entityIndex);
      }
    }
    else {
      bldType = *(byte *)(GTileRecords[tileIdx] * 0x12 + 8);
      if (bldType != 0) {
        segTable[0] = _DS;
        menuItems = 0x7969;
        menuCodes[0] = 1;
      }
      menuCount = (uint)(bldType != 0);
      if (foundFlag != 0x0) {
        segTable[menuCount * 2] = _DS;   /* hand fix: this slot holds the DGROUP segment half, exactly as segTable[0] = 0x2410 above; the literal offset Ghidra printed is that same value */
        *(char **)(&menuItems + menuCount * 4) = (char *)"Change party";
        menuCodes[menuCount] = 2;
        menuCount = menuCount + 1;
      }
      segTable[menuCount * 2] = _DS;   /* hand fix: this slot holds the DGROUP segment half, exactly as segTable[0] = 0x2410 above; the literal offset Ghidra printed is that same value */
      *(char **)(&menuItems + menuCount * 4) = (char *)"Done";
      menuCodes[menuCount] = 3;
      again = '\0';
      do {
        entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
        if (bldType == 0) {
          textMsg = ovr_ovc22_className(AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3),0);
          wordPair = (uint16_t *)((uint)AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3) * 4);
          msgSeg = _DS;
          computed = ovr_ovc45_compute9(text2,(char *)CONCAT22(*wordPair,_SS),
                                     (char *)CONCAT13((char)(Font03.ofs >> 8),
                                                      CONCAT12((char)Font03.ofs,wordPair[1])),
                                     Font03.seg,'J',(char)Font03.ofs,(char)Font03.seg,0x4a,3,textMsg)
          ;
          wordPair = (uint16_t *)
                   ((uint)*(byte *)(GTileRecords[tileIdx] * 0x12 + 9) * 4);
          computed = ovr_ovc45_compute9(text1,(char *)CONCAT22(*wordPair,_SS),
                                     (char *)CONCAT22(Font03.ofs,(char *)wordPair[1]),Font03.seg,'J',
                                     0x4a,2,(char)computed,msgSeg);
          pctRemaining = 100 - ((uint)*(byte *)(GTileRecords[tileIdx] * 0x12 + 0xb) * 100
                        ) / (uint)*(byte *)(GTileRecords[tileIdx] * 0x12 + 0xc);
          textMsg = ovr_fmVsprintf("Clearing of land: %d%% complete. Owned by %s. Active party is %s the %s."
                                  ,(char *)CONCAT13((char)((uint)computed >> 8),
                                                    CONCAT12((char)computed,pctRemaining)));
          strcpy((char *)CONCAT22(_SS,&msg),(char *)CONCAT22(pctRemaining,textMsg));
        }
        else {
          textMsg = ovr_ovc22_className(AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3),0);
          wordPair = (uint16_t *)((uint)AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3) * 4);
          msgSeg = _DS;
          computed = ovr_ovc45_compute9(text2,(char *)CONCAT22(*wordPair,_SS),
                                     (char *)CONCAT13((char)(Font03.ofs >> 8),
                                                      CONCAT12((char)Font03.ofs,wordPair[1])),
                                     Font03.seg,'_',(char)Font03.ofs,(char)Font03.seg,0x5f,3,textMsg)
          ;
          wordPair = (uint16_t *)
                   ((uint)*(byte *)(GTileRecords[tileIdx] * 0x12 + 9) * 4);
          delayArg = 0x7a;
          computed = ovr_ovc45_compute9(text1,(char *)CONCAT22(*wordPair,_SS),
                                     (char *)CONCAT22(Font03.ofs,(char *)wordPair[1]),Font03.seg,'_',
                                     0x5f,2,(char)computed,msgSeg);
          stashOfs = ovr_ovc15_usesStshRealloc
                             ((char *)BLD_WORD(&BuildingTypes[bldType], name, 0),BLD_WORD(&BuildingTypes[bldType], name, 2),100 - ((uint)*(byte *)(GTileRecords[tileIdx] * 0x12
                                                    + 0xb) * 100) /
                                    (uint)*(byte *)(GTileRecords[tileIdx] * 0x12 +
                                                   0xc),(char)computed,delayArg,0,0,0);
          asm { mov retSeg,dx };
          textMsg = ovr_fmVsprintf("%s: %d%% complete. Owned by %s. Active party is %s the %s.",
                                  (char *)CONCAT22(retSeg,stashOfs));
          strcpy((char *)CONCAT22(_SS,&msg),(char *)CONCAT22(retSeg,textMsg));
        }
        goldPartyIndex = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
        hint_00.seg = (uint16_t)_SS;
        hint_00.ofs = (uint16_t)&msg;
        stashOfs = &menuItems;
        (*(uint8_t *)((uint8_t *)&(entries_00.seg))) = ssLo;
        entries_00.ofs = (uint16_t)stashOfs;
        (*(uint8_t *)((uint8_t *)&(entries_00.seg) + 1)) = ssHi;
        ovr_ovc28_compute2(entries_00,menuCount + 1,hint_00,0,0);
        itemCode = (char)stashOfs;
        goldPartyIndex = 0xff;
        if (itemCode != '\0') {
          itemCode = menuCodes[((uint)stashOfs & 0xff) - 1];
        }
        if (itemCode == '\x01') {
          tableOfs = segTable[0];
          menuLabel = menuItems;
          tableSeg = _DS;
          arg2Pair = 0x7a02;
          stashOfs = ovr_ovc15_usesStshRealloc
                             ((char *)BLD_WORD(&BuildingTypes[bldType], name, 0),0,0,0,0,0,0,0);
          asm { mov retSegB,dx };
          textMsg = ovr_fmVsprintf("Construction of %s will be permanently suspended. Are you sure?",
                                  (char *)CONCAT22(retSegB,stashOfs));
          hint_01.seg = retSegB;
          hint_01.ofs = (uint16_t)textMsg;
          stashOfs = &menuLabel;
          (*(uint8_t *)((uint8_t *)&(entries_01.seg))) = ssLo;
          entries_01.ofs = (uint16_t)stashOfs;
          (*(uint8_t *)((uint8_t *)&(entries_01.seg) + 1)) = ssHi;
          ovr_ovc28_compute2(entries_01,2,hint_01,0,0);
          itemCode = (char)stashOfs;
          if (itemCode == '\x01') {
            ovr_ovc23_removeRecord(GTileRecords[tileIdx]);
          }
          again = '\x01';
        }
        else if (itemCode == '\x02') {
          choice = ovr_ovc45_textChoosePartyBuild
                             ((GfxRndSeed + (int)(char)tileOffset) - 2,GfxRndSeed2,(int *)&entityIndex,0);
          choiceCode = (char)choice;
          if (choiceCode == -1) {
            again = '\x01';
          }
        }
        else if ((itemCode == '\x03') || (itemCode == '\0')) {
          again = '\x01';
        }
      } while (again == '\0');
    }
    if (outFlag != 0x0) {
      ovr_constr_flushDirtyRects();
    }
    ovr_ovc28_textHalflingCastle();
    ovr_ovc41_enterLeaderView();
  }
  return;
}


/* 7e7c:0b40 */

/* [R7] body shape: compute */

int __cdecl16far constrct_compute1(void)

{
  byte leaderIdx;
  int iVar2;
  
  leaderIdx = ovr_manage_findFirstLeader();
  if (leaderIdx == 0xff) {
    iVar2 = 0;
  }
  else if ((GLeaderSheets[leaderIdx])->titleIndex < 5) {
    iVar2 = 0x14;
  }
  else {
    iVar2 = (uint)(GLeaderSheets[leaderIdx])->titleIndex * 4 + 0x14;
  }
  return iVar2;
}



/* 7e7c:0b9c */

/* Building information / action menu for the square under the cursor.

   Structure (derived in doc/7e7c_0b9c_spec.md): the routine loops twice.  With `done` clear it runs
   pass 1, which reports who owns the square (leaves 1-3) and then continues at 0x1f1a, where the cost
   estimate and the far-pointer action list are built.  With `done` set it re-enters at 0x0f16 and
   runs the unitType description arms (leaves 4-45), then the action menu.  `GUnits[unitIdx].unitType`
   is rewritten from the entity between passes (0x2b20), and 0x2b23 flips `done`.

   GAP markers: the two unnameable calls in the pass-2 preamble (198,0057 / 198,005c), the pass-2 arms
   whose per-arm varargs are not yet transcribed, and the menu build/dispatch 0x2000..0x2af0. */
void constrct_buildInfoText(int x,byte far *flag,int entityIdx,int arg4,int arg5)

{
  bldtp_t far *bld;
  byte bldType;
  int unitIdx;
  byte owner;
  byte done;
  int cost;
  int n;
  int v16;
  int v18;
  int choice;
  uint16_t nounIdx;
  uint16_t repairCost;
  uint16_t upgradeCost;
  uint16_t gold;
  char far *noun;
  char far *res;
  char outBuf[0x2b0];
  char line1[0x50];
  char line2[0x50];
  far_t list[0x10];
  byte codes[0x10];

  done = 0;
  n = 0;
  x = (int)(GfxRndSeed + x - 2);
  bldType = (byte)ovr_ovc45_usesGfxRndSeed2((void far *)MK_FP(_SS,(uint16_t)&x));
  unitIdx = (int)ovr_ovc45_getUnitIndex(GfxRndSeed2,x);

  do {
    /* GUESS: +0x1a of the entity record - agnt_t names +0x17 as `entity` (4 bytes) and +0x1b as
       `owner`, so this byte falls inside the entity pointer; kept raw until the layout is settled. */
    owner = ((byte far *)&Entities[entityIdx])[0x1a];
    bld = &BuildingTypes[bldType];

    if (done == 0) {
      /* ---- pass 1: ownership only (leaves 1-3), decoded exactly ---- */
      if (GUnits[unitIdx].unitType == 0xff) {
        /* leaf 3: the owner's sheet is rendered once, at y = 0x55 */
        res = ovr_fmVsprintf((char far *)"%s: Active party is %s the %s.",
                             (uint16_t)ovr_ovc15_usesStshRealloc(
                                 (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                   (uint16_t)bld->name)),
                             (uint16_t)ovr_ovc45_compute9(
                                 (char far *)MK_FP(_SS,(uint16_t)line2),
                                 (void far *)MK_FP(Font03.seg,Font03.ofs),0x55,3,
                                 (char far *)((char_sheet_t far *)GLeaderSheets[owner])),
                             (uint16_t)ovr_ovc22_className(owner));
        strcpy(outBuf,res);
      }
      else if (bld->durability == 0x64) {
        /* leaf 2: two line renders at y = 0x46 */
        res = ovr_fmVsprintf((char far *)"%s: Owned by %s. Active party is %s the %s.",
                             (uint16_t)ovr_ovc15_usesStshRealloc(
                                 (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                   (uint16_t)bld->name)),
                             (uint16_t)ovr_ovc45_compute9(
                                 (char far *)MK_FP(_SS,(uint16_t)line2),
                                 (void far *)MK_FP(Font03.seg,Font03.ofs),0x46,2,
                                 (char far *)((char_sheet_t far *)GLeaderSheets[GUnits[unitIdx].unitType])),
                             (uint16_t)ovr_ovc45_compute9(
                                 (char far *)MK_FP(_SS,(uint16_t)line1),
                                 (void far *)MK_FP(Font03.seg,Font03.ofs),0x46,3,
                                 (char far *)((char_sheet_t far *)GLeaderSheets[owner])),
                             (uint16_t)ovr_ovc22_className(owner));
        strcpy(outBuf,res);
      }
      else {
        /* leaf 1: the same two renders plus the level/durability pair */
        res = ovr_fmVsprintf(
                  (char far *)"%s (%d/%d): Owned by %s. Active party is %s the %s.",
                  (uint16_t)ovr_ovc15_usesStshRealloc(
                      (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                        (uint16_t)bld->name)),
                  (uint16_t)ovr_ovc45_compute7(GUnits[unitIdx].level,bld->durability),
                  bld->durability,
                  (uint16_t)ovr_ovc45_compute9(
                      (char far *)MK_FP(_SS,(uint16_t)line2),
                      (void far *)MK_FP(Font03.seg,Font03.ofs),0x46,2,
                      (char far *)((char_sheet_t far *)GLeaderSheets[GUnits[unitIdx].unitType])),
                  (uint16_t)ovr_ovc45_compute9(
                      (char far *)MK_FP(_SS,(uint16_t)line1),
                      (void far *)MK_FP(Font03.seg,Font03.ofs),0x46,3,
                      (char far *)((char_sheet_t far *)GLeaderSheets[owner])),
                  (uint16_t)ovr_ovc22_className(owner));
        strcpy(outBuf,res);
      }
    }
    else {
      /* ---- pass 2 preamble (0x0f16) ---- */
      if (GUnits[unitIdx].unitType != 0xff) {
        /* GAP: `lcall 0x198,0x57` and `lcall 0x198,0x5c`, both (bld, unitType, x, y), 4 words each.
           Neither pair resolves to a name in this module; they feed the two %d arguments below. */
        v16 = 0;
        v18 = bld->housing;
      }
      else {
        v16 = 0;
        v18 = 0;
      }

      /* ---- pass 2: the unitType description arms (leaves 4-23) ---- */
      if (bld->unitType == 6) {
        ovr_stsprintf((char far *)MK_FP(_SS,(uint16_t)outBuf),
                      (char far *)"%s: Costs %d gold and provides training to level %d.",
                      (uint16_t)ovr_ovc15_usesStshRealloc(
                          (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                            (uint16_t)bld->name)),0);
      }
      else if (bld->unitType == 1) {
        if (bld->resource == 1) {
          res = ovr_fmVsprintf(
                    (char far *)"%s: Costs %d gold of income. Replaces broken weapons.",
                    (uint16_t)ovr_ovc15_usesStshRealloc(
                        (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                          (uint16_t)bld->name)),bld->cost);
        }
        else {
          res = ovr_fmVsprintf((char far *)"%s: Costs %d gold of income. Forges +%d weapons.",
                               (uint16_t)ovr_ovc15_usesStshRealloc(
                                   (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                     (uint16_t)bld->name)),bld->cost,0);
        }
        strcpy(outBuf,res);
      }
      else if (bld->unitType == 0x1d) {
        if (bld->resource == 1) {
          res = ovr_fmVsprintf((char far *)"%s: Costs %d gold of income. Improves armor.",
                               (uint16_t)ovr_ovc15_usesStshRealloc(
                                   (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                     (uint16_t)bld->name)),bld->cost);
        }
        else {
          res = ovr_fmVsprintf(
                    (char far *)"%s: Costs %d gold of income. Improves armor class by -%d.",
                    (uint16_t)ovr_ovc15_usesStshRealloc(
                        (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                          (uint16_t)bld->name)),bld->cost,0);
        }
        strcpy(outBuf,res);
      }
      else if (bld->unitType == 0xd) {
        if (bld->resource == 1) {
          res = ovr_fmVsprintf((char far *)"%s: Costs %d gold of income. Replaces broken bows.",
                               (uint16_t)ovr_ovc15_usesStshRealloc(
                                   (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                     (uint16_t)bld->name)),bld->cost);
        }
        else {
          res = ovr_fmVsprintf(
                    (char far *)"%s: Costs %d gold of income. Creates +%d bow and arrows.",
                    (uint16_t)ovr_ovc15_usesStshRealloc(
                        (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                          (uint16_t)bld->name)),bld->cost,0);
        }
        strcpy(outBuf,res);
      }
      else if (bld->unitType == 0xe) {
        /* GUESS: the trailing %d is an unproven field; the frame carries one extra word. */
        res = ovr_fmVsprintf((char far *)"%s: Costs %d gold. Increases unit size of five units by %d.",
                             (uint16_t)ovr_ovc15_usesStshRealloc(
                                 (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                   (uint16_t)bld->name)),bld->cost,0);
        strcpy(outBuf,res);
      }
      else if (bld->unitType == 0xf) {
        res = ovr_fmVsprintf((char far *)"%s: Costs %d gold. Increases building speed by %d0%%.",
                             (uint16_t)ovr_ovc15_usesStshRealloc(
                                 (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                   (uint16_t)bld->name)),bld->cost,0);
        strcpy(outBuf,res);
      }
      else if (bld->unitType == 0x17) {
        res = ovr_fmVsprintf((char far *)"%s: Costs %d gold. Enhances training by %d%%.",
                             (uint16_t)ovr_ovc15_usesStshRealloc(
                                 (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                   (uint16_t)bld->name)),bld->cost,0);
        strcpy(outBuf,res);
      }
      else if (bld->unitType == 0x10) {
        res = ovr_fmVsprintf((char far *)"%s: Costs %d gold. Produces +%d rings of protection.",
                             (uint16_t)ovr_ovc15_usesStshRealloc(
                                 (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                   (uint16_t)bld->name)),bld->cost,0);
        strcpy(outBuf,res);
      }
      else if (bld->unitType == 0x11) {
        res = ovr_fmVsprintf(
                  (char far *)"%s: Costs %d gold. Produces mirrors for medusae combat. Increases tower range by %d%%.",
                  (uint16_t)ovr_ovc15_usesStshRealloc(
                      (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                        (uint16_t)bld->name)),bld->cost,0);
        strcpy(outBuf,res);
      }
      else if (bld->unitType == 0x12) {
        res = ovr_fmVsprintf((char far *)"%s: Costs %d gold. Attracts new units to this location.",
                             (uint16_t)ovr_ovc15_usesStshRealloc(
                                 (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                   (uint16_t)bld->name)),bld->cost);
        strcpy(outBuf,res);
      }
      else if (bld->unitType == 0x13) {
        res = ovr_fmVsprintf((char far *)"%s: Costs %d gold. Provides %u units of gold storage.",
                             (uint16_t)ovr_ovc15_usesStshRealloc(
                                 (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                   (uint16_t)bld->name)),bld->cost,bld->storage);
        strcpy(outBuf,res);
      }
      else if (bld->unitType == 0x14) {
        res = ovr_fmVsprintf((char far *)"%s: Costs %d gold. Claim trees automatically.",
                             (uint16_t)ovr_ovc15_usesStshRealloc(
                                 (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                   (uint16_t)bld->name)),bld->cost);
        strcpy(outBuf,res);
      }
      else if (bld->unitType == 0x15) {
        res = ovr_fmVsprintf((char far *)"%s: Costs %d gold. Repairs buildings at season changes.",
                             (uint16_t)ovr_ovc15_usesStshRealloc(
                                 (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                   (uint16_t)bld->name)),bld->cost);
        strcpy(outBuf,res);
      }
      else if (bld->unitType == 0x16) {
        /* GUESS: the second %d is unproven; the frame carries one extra word (bld byte +0xa0?). */
        res = ovr_fmVsprintf(
                  (char far *)"%s: Trades %d food for gold. Total trade is %d food.",
                  (uint16_t)ovr_ovc15_usesStshRealloc(
                      (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                        (uint16_t)bld->name)),bld->cost,0);
        strcpy(outBuf,res);
      }
      else if (bld->unitType == 4) {
        res = ovr_fmVsprintf(
                  (char far *)"%s: Creates %d gold of income, and accesses %d%% of the market fund.",
                  (uint16_t)ovr_ovc15_usesStshRealloc(
                      (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                        (uint16_t)bld->name)),bld->cost,0);
        strcpy(outBuf,res);
      }
      else if (bld->unitType == 2) {
        res = ovr_fmVsprintf(
                  (char far *)"%s: Costs %d gold of income and provides visibility of %d squares n/s, %d squares e/w.",
                  (uint16_t)ovr_ovc15_usesStshRealloc(
                      (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                        (uint16_t)bld->name)),bld->cost,0,0);
        strcpy(outBuf,res);
      }
      else if (bld->unitType == 5) {
        res = ovr_fmVsprintf(
                  (char far *)"%s: Costs %d gold of income and provides storage for %u food.",
                  (uint16_t)ovr_ovc15_usesStshRealloc(
                      (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                        (uint16_t)bld->name)),bld->cost,bld->storage);
        strcpy(outBuf,res);
      }
      else if (bld->unitType == 0x13) {
        res = ovr_fmVsprintf(
                  (char far *)"%s: Costs %d gold of income and provides storage for %u gold.",
                  (uint16_t)ovr_ovc15_usesStshRealloc(
                      (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                        (uint16_t)bld->name)),bld->cost,bld->storage);
        strcpy(outBuf,res);
      }
      else if (bld->unitType == 0) {
        /* The tooltip noun is the DGROUP 0x74ad far-pointer table indexed by
           ovc45_compute6(v18, bld->storage); the image calls it once inside each branch
           (0x1a82 / 0x1ae7 for type 0, 0x1b85 / 0x1c05 for type 8). */
        if (bld->storage != 0) {
          nounIdx = (uint16_t)ovr_ovc45_compute6(v18,bld->storage);
          noun = (nounIdx != 0) ? (char far *)"people" : (char far *)"person";
          res = ovr_fmVsprintf(
                    (char far *)"%s: Provides housing for %d %s and storage for %d food.",
                    (uint16_t)ovr_ovc15_usesStshRealloc(
                        (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                          (uint16_t)bld->name)),v18,(uint16_t)noun,
                    bld->storage);
          strcpy(outBuf,res);
        }
        else {
          nounIdx = (uint16_t)ovr_ovc45_compute6(v18,bld->storage);
          noun = (nounIdx != 0) ? (char far *)"people" : (char far *)"person";
          res = ovr_fmVsprintf((char far *)"%s: Provides housing for %d %s.",
                               (uint16_t)ovr_ovc15_usesStshRealloc(
                                   (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                     (uint16_t)bld->name)),v18,(uint16_t)noun);
          strcpy(outBuf,res);
        }
      }
      else if (bld->unitType == 8) {
        /* The tooltip noun is the DGROUP 0x74ad far-pointer table indexed by
           ovc45_compute6(v18, bld->storage); the image calls it once inside each branch
           (0x1a82 / 0x1ae7 for type 0, 0x1b85 / 0x1c05 for type 8). */
        if (bld->storage != 0) {
          nounIdx = (uint16_t)ovr_ovc45_compute6(v18,bld->storage);
          noun = (nounIdx != 0) ? (char far *)"people" : (char far *)"person";
          res = ovr_fmVsprintf(
                    (char far *)"%s: Provides housing for %d %s and storage for %d food.",
                    (uint16_t)ovr_ovc15_usesStshRealloc(
                        (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                          (uint16_t)bld->name)),v18,(uint16_t)noun,
                    bld->storage);
          strcpy(outBuf,res);
        }
        else {
          nounIdx = (uint16_t)ovr_ovc45_compute6(v18,bld->storage);
          noun = (nounIdx != 0) ? (char far *)"people" : (char far *)"person";
          res = ovr_fmVsprintf((char far *)"%s: Provides housing for %d %s.",
                               (uint16_t)ovr_ovc15_usesStshRealloc(
                                   (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                     (uint16_t)bld->name)),v18,(uint16_t)noun);
          strcpy(outBuf,res);
        }
      }
      else if (bld->unitType == 9) {
        /* Four variants on the two quantities the pass-2 preamble computed: v16 (feeds) and v18
           (housing).  The image computes the noun (DGROUP 0x74ad via ovc45_compute6) and the gold
           figure (ovc45_costOrIncomeLabel) *inside* each variant - 0x1d2c/0x1d50/0x1dcb/0x1e4f and
           0x1d7a/0x1df5/0x1e79/0x1ecf - so they are repeated per branch here too. */
        /* The arm opens with the plain "Feeds" form before the v16/v18 dispatch refines it
           (0x1c87..0x1f02: compute6, costOrIncomeLabel, fmVsprintf 0x7fd5, strcpy). */
        nounIdx = (uint16_t)ovr_ovc45_compute6(v18,bld->storage);
        noun = (nounIdx != 0) ? (char far *)"people" : (char far *)"person";
        gold = (uint16_t)ovr_ovc45_costOrIncomeLabel(v16,(uint16_t)(v16 < 0 ? -v16 : v16));
        res = ovr_fmVsprintf((char far *)"%s: %s %d gold. Feeds %d %s.",
                             (uint16_t)ovr_ovc15_usesStshRealloc(
                                 (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                   (uint16_t)bld->name)),(uint16_t)noun,gold,
                             v16,(uint16_t)noun);
        strcpy(outBuf,res);
        if ((v16 == 0) && (v18 == 0)) {
          /* nothing further to report */
        }
        else if (v16 > 0) {
          if (v18 > 0) {
            nounIdx = (uint16_t)ovr_ovc45_compute6(v18,bld->storage);
            noun = (nounIdx != 0) ? (char far *)"people" : (char far *)"person";
            gold = (uint16_t)ovr_ovc45_costOrIncomeLabel(v16,(uint16_t)(v16 < 0 ? -v16 : v16));
            res = ovr_fmVsprintf(
                      (char far *)"%s: %s %d gold. provides housing for %d %s and feeds %d %s.",
                      (uint16_t)ovr_ovc15_usesStshRealloc(
                          (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                            (uint16_t)bld->name)),(uint16_t)noun,gold,
                      v18,(uint16_t)noun,v16,(uint16_t)noun);
            strcpy(outBuf,res);
          }
          else {
            nounIdx = (uint16_t)ovr_ovc45_compute6(v18,bld->storage);
            noun = (nounIdx != 0) ? (char far *)"people" : (char far *)"person";
            gold = (uint16_t)ovr_ovc45_costOrIncomeLabel(v16,(uint16_t)(v16 < 0 ? -v16 : v16));
            res = ovr_fmVsprintf((char far *)"%s: %s %d gold. Feeds %d %s.",
                                 (uint16_t)ovr_ovc15_usesStshRealloc(
                                     (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                       (uint16_t)bld->name)),(uint16_t)noun,gold,
                                 v16,(uint16_t)noun);
            strcpy(outBuf,res);
          }
        }
        else {
          if (v18 > 0) {
            nounIdx = (uint16_t)ovr_ovc45_compute6(v18,bld->storage);
            noun = (nounIdx != 0) ? (char far *)"people" : (char far *)"person";
            gold = (uint16_t)ovr_ovc45_costOrIncomeLabel(v16,(uint16_t)(v16 < 0 ? -v16 : v16));
            res = ovr_fmVsprintf((char far *)"%s: %s %d gold. Provides housing for %d %s.",
                                 (uint16_t)ovr_ovc15_usesStshRealloc(
                                     (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                       (uint16_t)bld->name)),(uint16_t)noun,gold,
                                 v18,(uint16_t)noun);
            strcpy(outBuf,res);
          }
          else {
            nounIdx = (uint16_t)ovr_ovc45_compute6(v18,bld->storage);
            noun = (nounIdx != 0) ? (char far *)"people" : (char far *)"person";
            gold = (uint16_t)ovr_ovc45_costOrIncomeLabel(v16,(uint16_t)(v16 < 0 ? -v16 : v16));
            res = ovr_fmVsprintf((char far *)"%s: %s %d gold.",
                                 (uint16_t)ovr_ovc15_usesStshRealloc(
                                     (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                       (uint16_t)bld->name)),(uint16_t)noun,
                                 gold);
            strcpy(outBuf,res);
          }
        }
      }
      /* GAP: the remaining pass-2 arms (unitType 3, 7, 0xa, 0xb, 0xc) - their literals are in the
         inventory but their argument tables are not yet resolved. */
    }

    /* ---- 0x1f1a continuation: cost estimate + the far-pointer action list ---- */
    cost = (int)((long)bld->cost * GUnits[unitIdx].level / 0x18 + 1);
    repairCost = (uint16_t)((long)bld->cost / 5 + 1);
    upgradeCost = (uint16_t)((long)bld->cost / 5 + 1);
    codes[n] = 1;
    if (bld->action != (char far *)0) {
      list[n].ofs = (uint16_t)bld->action;
      list[n].seg = (uint16_t)((uint32_t)bld->action >> 16);
      n++;
    }
    else if ((unitIdx >= 0xf8) && (bld->cost != 0) && ((bld->flags2 & 4) == 0)) {
      list[n].seg = (uint16_t)_DS;
      list[n].ofs = (uint16_t)"Salvage";
      n++;
      /* leaf 34: the salvage value line is appended to the message (0x2007) */
      res = ovr_fmVsprintf((char far *)" Salvage value %d gold.",cost);
      strcat(outBuf,res);
    }
      /* ---- the action menu (0x2000..0x2b38) ---- */
      /* Entries are appended to the same list as the description, each with a code byte that the
         jump table at cs:0x2b3c dispatches on: 0 Demolish, 1 Salvage, 2 Repair, 3 Upgrade,
         4 Change Party, 5 Done, 6 New Owner, 7 Information. */
      if ((bld->flags2 & 4) != 0) {
        if ((GUnits[unitIdx].unitType != 0xff) &&
            (((char_sheet_t far *)GLeaderSheets[GUnits[unitIdx].unitType])->faction == 0)) {
          codes[n] = 0;
          list[n].seg = (uint16_t)_DS;
          list[n].ofs = (uint16_t)"Demolish";
          n++;
        }
      }
      /* The image calls compute8 twice - once for the Repair entry (0x20ea) and once for the
         Upgrade entry (0x2170) - so it is evaluated per entry, not once for both. */
      if (ovr_ovc45_compute8(GUnits[unitIdx].unitType) != 0) {
        if (GUnits[unitIdx].level < 8) {
          codes[n] = 2;
          list[n].seg = (uint16_t)_DS;
          list[n].ofs = (uint16_t)"Repair";
          n++;
          if (done == 0) {
            /* leaf 35 (0x2137) */
            res = ovr_fmVsprintf((char far *)" Repair costs %d gp.",repairCost);
            strcat(outBuf,res);
          }
        }
      }
      if (ovr_ovc45_compute8(GUnits[unitIdx].unitType) != 0) {
        if (bld->halfWidth != 0) {
          codes[n] = 3;
          list[n].seg = (uint16_t)_DS;
          list[n].ofs = (uint16_t)"Upgrade";
          n++;
          if (done == 0) {
            /* leaf 36 (0x21ff) */
            res = ovr_fmVsprintf((char far *)" Upgrade costs %d gp.",upgradeCost);
            strcat(outBuf,res);
          }
        }
      }
      if (((bld->flags2 & 0x400) == 0) && (arg4 != 0xff)) {
        codes[n] = 7;
        list[n].seg = (uint16_t)_DS;
        list[n].ofs = (uint16_t)"Information";
        n++;
      }
      if (((bld->flags2 & 4) == 0) && (unitIdx >= 0xf8)) {
        codes[n] = 6;
        list[n].seg = (uint16_t)_DS;
        list[n].ofs = (uint16_t)"New Owner";
        n++;
      }
      if (arg5 != 0) {
        codes[n] = 4;
        list[n].seg = (uint16_t)_DS;
        list[n].ofs = (uint16_t)"Change Party";
        n++;
      }
      codes[n] = 5;
      list[n].seg = (uint16_t)_DS;
      list[n].ofs = (uint16_t)"Done";
      n++;

      /* Show the list and dispatch the choice through the cs:0x2b3c table.  Cases 1/2/3/6/7 carry
         the action bodies (salvage value, repair, upgrade, new owner, information); 0 and 5 leave
         the routine. */
      choice = (int)ovr_ovc28_compute2(list,(uint16_t)n,
                                       (char far *)MK_FP(_SS,(uint16_t)outBuf));
      switch (choice) {
      case 1:
        /* ---- salvage (0x2376..0x244a) ---- */
        if (unitIdx >= 0xf8) {
          res = (char far *)0;
          if (cost != 0) {
            res = ovr_fmVsprintf((char far *)"%s will be salvaged for %d gold. Are you sure?",
                                 (uint16_t)ovr_ovc15_usesStshRealloc(
                                     (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                       (uint16_t)bld->name)),cost);
          }
          else if ((bld->flags2 & 4) != 0) {
            choice = 1;
          }
          else {
            res = ovr_fmVsprintf((char far *)"Get rid of %s permanently. Are you sure?",
                                 (uint16_t)ovr_ovc15_usesStshRealloc(
                                     (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                       (uint16_t)bld->name)));
            /* the second prompt variant has its own list call (image 0x2436) */
            choice = (int)ovr_ovc28_compute2(&list[n],2,res);
          }
          if (res != (char far *)0) {
            choice = (int)ovr_ovc28_compute2(&list[n],2,res);
          }
          if (choice != 1) {
            return;
          }
        }
        else {
          cost = 0;
        }
        /* shared action tail (0x2451): a rodent-free demolish calls the next function in this module */
        if ((bld->flags2 & 4) != 0) {
          constrct_usesLDIV_at_((byte)entityIdx,GUnits[unitIdx].unitType);
          /* 0x24bd: the demolish path also creates the record, before the flags2&0x400 pair below */
          ovr_createConstructionRecordFar(0,x,GfxRndSeed2,arg4,arg5,owner);
          *flag = 1;
        }
        /* ---- shared action tail (0x24cd..0x278b) ---- */
        if ((bld->flags2 & 0x400) != 0) {
          ovr_createConstructionRecord(0,x,GfxRndSeed2,arg4,owner,3);
        }
        else {
          ovr_createConstructionRecordFar(0,x,GfxRndSeed2,arg4,owner,3);
        }
        if ((bld->flags2 & 0x20) != 0) {
          ovr_play_sfx(0,0x56);
        }
        else {
          ovr_play_sfx(0,0x4f);
        }
        if ((bld->flags2 & 0x400) != 0) {
          res = ovr_fmVsprintf((char far *)"%s is being filled.",
                               (uint16_t)ovr_ovc15_usesStshRealloc(
                                   (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                     (uint16_t)bld->name)));
          ovr_say(res);
          ovr_inputUpdate(MessageDelay);
        }
        else if (cost > 0) {
          res = ovr_fmVsprintf((char far *)"%s salvaged for %d gold.",
                               (uint16_t)ovr_ovc15_usesStshRealloc(
                                   (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                     (uint16_t)bld->name)),cost);
          ovr_say(res);
          ovr_inputUpdate(MessageDelay);
        }
        else {
          res = ovr_fmVsprintf((char far *)"%s is demolished.",
                               (uint16_t)ovr_ovc15_usesStshRealloc(
                                   (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                     (uint16_t)bld->name)));
          ovr_say(res);
          ovr_inputUpdate(MessageDelay);
        }
        /* GAP: `lcall 0x1a8,0x2a` at 0x2780 - the pair has no same-module vote and the co-residency
           anchor maps it to ovc24_checkStrongholds, a 3-byte stub of the wrong module. */
        return;
      case 2:
        /* ---- repair (0x278b..0x291e) ---- */
        ovr_ovc45_compute3(unitIdx,entityIdx);
        res = ovr_fmVsprintf((char far *)"%s does not have enough gold.",
                             (uint16_t)ovr_ovc15_usesStshRealloc(
                                 (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                   (uint16_t)bld->name)));
        ovr_say(res);
        ovr_inputUpdate(MessageDelay);
        ovr_play_sfx(0,0);
        res = ovr_fmVsprintf((char far *)"%s repaired.",
                             (uint16_t)ovr_ovc15_usesStshRealloc(
                                 (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                   (uint16_t)bld->name)));
        ovr_say(res);
        ovr_ovc45_usesGPopulationLo(owner,0,0);
        ovr_inputUpdate(MessageDelay);
        break;
      case 3:
        /* ---- upgrade (0x291e..0x2ab4) ---- */
        ovr_ovc45_compute3(unitIdx,entityIdx);
        res = ovr_fmVsprintf((char far *)"%s does not have enough gold.",
                             (uint16_t)ovr_ovc15_usesStshRealloc(
                                 (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                   (uint16_t)bld->name)));
        ovr_say(res);
        ovr_say((char far *)"Too many construction sites.");
        ovr_inputUpdate(MessageDelay);
        ovr_play_sfx(0,0);
        res = ovr_fmVsprintf((char far *)"%s upgraded.",
                             (uint16_t)ovr_ovc15_usesStshRealloc(
                                 (char far *)MK_FP((uint16_t)((uint32_t)bld->name >> 16),
                                                   (uint16_t)bld->name)));
        ovr_say(res);
        (void)ovr_createConstructionRecord(owner,unitIdx,0);
        ovr_ovc45_usesGPopulationLo(owner,0,0);
        ovr_inputUpdate(MessageDelay);
        *flag = 1;
        break;
      case 6:
        /* ---- new owner (0x2aee) ---- */
        owner = ((byte far *)&Entities[entityIdx])[0x1a];
        break;
      case 7:
        done = (byte)(done ^ 1);
        break;
      default:
        return;
      }
    break;
  } while (done == 0);
}
/* 7e7c:2b4c */
void __cdecl16far constrct_usesLDIV_at_(byte partyIndex,int entityIndex)

{
  undefined1 stk_ff60;   /* stack slot ff60 */
  uint *goldLoPtr;          /* &sheet->gold, the low word */
  int *goldHiPtr;           /* &sheet->gold + 2, the high word */
  byte entityIdx;
  byte classStrVal;
  uint classCost;
  long *plVar6;
  char *msg;
  uint16_t countHi;         /* the high half of (trainCost * 0xf) / count */
  uint16_t recSeg2;         /* the sheet's segment, hoisted before a 32-bit read */
  uint costRemainder;
  int trainCost;           /* AgntGs[class].shortName[5], the class cost */
  int entRecA;             /* (int)Entities[entityIdx], the sheet pointer */
  int goldHiA;             /* sheet->gold's high word */
  int entPtr;
  int entPtrB;
  uint16_t argLo;           /* argWord's low word, left in SI */
  uint scanIdx;            /* 0 .. EntityCount */
  uint oldGoldLo;          /* sheet->gold's low word before the add */
  long *mulOperand;         /* the left operand the image leaves in DI */
  int trainCount;          /* how many idle agents are at the cursor */
  int foodHiA;             /* sheet's +0x8c word */
  int entRecB;             /* a second copy of the sheet pointer */
  uint16_t entSegTmp;       /* SEG_OF(Entities), overwritten before use */
  uint16_t atCursor;        /* ovr_ovc23_isCursorAt's result */
  uint16_t costHi;          /* the high half of the training cost */
  uint16_t recSeg;          /* the sheet's segment */
  uint16_t foodLoA;         /* sheet's +0x8a word */
  uint16_t entSeg;
  long lVar16;
  long lVar17;
  uint32_t argWord;         /* the caller's 32-bit argument at [bp-0xa2] */
  long mulRet;              /* LXMUL_at_'s return storage */
  uint16_t count;
  
  lVar17 = CONCAT22((int)((ulong)argWord >> 0x10),argLo);
  entityIdx = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
  if ((partyIndex != 0xff) && (entityIdx != 0xff)) {
    classStrVal = (GLeaderSheets[partyIndex])->classStr;
    trainCost = AGNT_WORD(&AgntGs[(uint)classStrVal], shortName, 5);
    classCost = AGNT_WORD(&AgntGs[(uint)classStrVal], shortName, 5) * 0xf;
    trainCount = 0;
    for (scanIdx = 0; scanIdx < EntityCount; scanIdx = scanIdx + 1) {
      entSegTmp = (uint16_t)((ulong)Entities >> 0x10);
      atCursor = ovr_ovc23_isCursorAt
                         ((Entities)[scanIdx].base.x,(Entities)[scanIdx].base.y,0);
      if (((char)atCursor != '\0') &&
         (AgntGs[(uint)(Entities)[scanIdx].base.gindex].ai == '\0')) {
        trainCount = trainCount + 1;
      }
    }
    lVar16 = LDIV_at_((ulong)(uint)(trainCost * 0xf),(long)trainCount);
    countHi = (uint16_t)((ulong)(lVar16 + 1) >> 0x10);
    costHi = countHi;
    plVar6 = LXMUL_at_(mulOperand,lVar17,mulRet);
    count = (uint16_t)(lVar16 + 1);
    msg = ovr_stsprintf(&stk_ff60,(char *)CONCAT22(0x81dc,_SS),
                        (char *)CONCAT22(plVar6,(char *)0x2410),costHi,count,countHi,
                        classCost);
    ovr_say(msg,0);
    lVar17 = LDIV_at_((ulong)classCost,10);
    recSeg = (uint16_t)((ulong)*(uint32_t *)((uint)entityIdx << 2) >> 0x10);
    entRecA = (int)*(uint32_t *)((uint)entityIdx << 2);
    costRemainder = classCost - (uint)lVar17;
    goldLoPtr = (uint *)(entRecA + 0x56);
    oldGoldLo = *goldLoPtr;
    *goldLoPtr = *goldLoPtr + costRemainder;
    goldHiPtr = (int *)(entRecA + 0x58);
    *goldHiPtr = *goldHiPtr + (-(uint)(classCost < (uint)lVar17) - (int)((ulong)lVar17 >> 0x10)) +
              (uint)CARRY2(oldGoldLo,costRemainder);
    lVar17 = lVar17 + CONCAT22(GPopulationHi,GPopulationLo);
    GPopulationLo = (uint16_t)lVar17;
    GPopulationHi = (uint16_t)((ulong)lVar17 >> 0x10);
    recSeg = (uint16_t)((ulong)*(uint32_t *)((uint)entityIdx << 2) >> 0x10);
    entPtr = (int)*(uint32_t *)((uint)entityIdx << 2);
    goldHiA = *(int *)(entPtr + 0x58);
    recSeg2 = (uint16_t)((ulong)*(uint32_t *)((uint)entityIdx << 2) >> 0x10);
    entPtrB = (int)*(uint32_t *)((uint)entityIdx << 2);
    foodHiA = *(int *)(entPtrB + 0x8c);
    if ((foodHiA <= goldHiA) &&
       ((foodHiA < goldHiA || (*(uint *)(entPtrB + 0x8a) < *(uint *)(entPtr + 0x56))))) {
      recSeg2 = (uint16_t)((ulong)*(uint32_t *)((uint)entityIdx << 2) >> 0x10);
      entRecA = (int)*(uint32_t *)((uint)entityIdx << 2);
      foodLoA = *(uint16_t *)(entRecA + 0x8a);
      entSeg = (uint16_t)((ulong)*(uint32_t *)((uint)entityIdx << 2) >> 0x10);
      entRecB = (int)*(uint32_t *)((uint)entityIdx << 2);
      *(uint16_t *)(entRecB + 0x58) = *(uint16_t *)(entRecA + 0x8c);
      *(uint16_t *)(entRecB + 0x56) = foodLoA;
      lVar17 = CONCAT22(GPopulationHi,GPopulationLo);
    }
    GPopulationHi = (uint16_t)((ulong)lVar17 >> 0x10);
    GPopulationLo = (uint16_t)lVar17;
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)) = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
    (*(uint16_t *)((uint8_t *)&(TextBlitCycle))) = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);   /* hand fix: the offset half is the address, not the far_t struct */
    ovr_inputUpdate(0x36);
  }
  return;
}


/* 7e7c:2e8e */

/* Returns whether none of the four map-flag words covering the unit's footprint is set. */

byte __cdecl16far constrct_unitFlagsClear(int unitIndex)

{
  /* Re-derived (7e7c:2e8e): 1 when none of the four map-flag words to the right of the
     unit's cell has bit 0x1000 set; 0 when the unit type is 0xff, when the leader sheet's
     +0x3f byte is set, or when any of the four words has the bit.  All three exits set only
     AL, so the exported CONCAT11 / <<8 returns were stale-AH artifacts of the
     `and ax,0x1000` inside the loop. */
  unit_t *units;
  uint entY;
  uint alignedX;
  uint flagWord;
  uint flags;
  int k;

  units = GUnits;
  if (units[unitIndex].unitType == 0xff) {
    return 0;
  }
  /* GLeaderSheets is a far pointer array (image: `mov dx,0x70 / les bx,es:[bx]`), so the sheet must
     be reached as a far record - the previous near cast kept only the offset. */
  if (GLeaderSheets[units[unitIndex].unitType]->faction != 0) {
    return 0;
  }
  alignedX = ovr_alignUp4(units[unitIndex].x,0,0);
  entY = (GUnits)[unitIndex].y;
  flags = 0;
  for (k = 0; k < 4; k = k + 1) {
    flagWord = ((short (*) [60] [148])GMapFlags)[-1][entY + 0x3b][alignedX + k + 0x92] &
               0x1000;
    flags = flags | flagWord;
  }
  if (flags == 0) {
    return 1;
  }
  return 0;
}


