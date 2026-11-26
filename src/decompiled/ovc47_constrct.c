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
  uint16_t *puVar5;
  int computed;
  uint8_t *stashOfs;
  uint16_t retSeg;
  uint16_t entrySeg;
  int pctRemaining;
  unit_t *puVar10;
  uint16_t gUnitsSeg;
  uint16_t entitiesSeg;
  uint16_t mapFlag;
  uint16_t msgSeg;
  uint16_t choice;
  undefined1 entryLo;
  undefined1 delayArg;
  undefined1 uVar13;
  undefined1 uVar14;
  int16_t type;
  far_t hint;
  far_t hint_00;
  far_t hint_01;
  uint8_t text2;
  uint8_t text1;
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
  undefined1 auStack_14 [10];
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
  uVar13 = SUB21(_SS,0);
  uVar14 = (undefined1)((uint)_SS >> 8);
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
        puVar10 = GUnits;
        if (puVar10[unitIdx].unitType == 0xff) {
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
                             ((char *)BLD_WORD(&BuildingTypes[bldType], name, 0),BLD_WORD(&BuildingTypes[bldType], name, 2),*(uint16_t *)((uint)puVar10[unitIdx].unitType * 4),0,0,0,0,0);
          asm { mov retSeg,dx };
          textMsg = ovr_fmVsprintf("%s: Held by %s.",(char *)CONCAT22(retSeg,stashOfs));
          strcpy((char *)CONCAT22(_SS,&msg),(char *)CONCAT22(retSeg,textMsg));
        }
        else {
          b = BuildingTypes[bldType].durability;
          computed = ovr_ovc45_compute7(puVar10[unitIdx].level,b,b,
                                      (uint)BuildingTypes[bldType].durability,
                                      *(uint16_t *)((uint)puVar10[unitIdx].unitType * 4));
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
        puVar5 = (uint16_t *)
                 ((uint)*(byte *)(GTileRecords[tileIdx] * 0x12 + 9) * 4);
        entrySeg = puVar5[1];
        entrySeg = *puVar5;
        entryLo = (undefined1)entrySeg;
        computed = ovr_ovc45_compute9((char *)&text1,
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
      (*(uint8_t *)((uint8_t *)&(entries.seg))) = uVar13;
      entries.ofs = (uint16_t)stashOfs;
      (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = uVar14;
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
            constrct_buildInfoText
                      (0x23f1,CONCAT11((char)((uint)&outFlag >> 8),tileOffset),(char)&outFlag);
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
        auStack_14[0] = 1;
      }
      menuCount = (uint)(bldType != 0);
      if (foundFlag != 0x0) {
        segTable[menuCount * 2] = _DS;   /* hand fix: this slot holds the DGROUP segment half, exactly as segTable[0] = 0x2410 above; the literal offset Ghidra printed is that same value */
        *(char **)(&menuItems + menuCount * 4) = (char *)"Change party";
        auStack_14[menuCount] = 2;
        menuCount = menuCount + 1;
      }
      segTable[menuCount * 2] = _DS;   /* hand fix: this slot holds the DGROUP segment half, exactly as segTable[0] = 0x2410 above; the literal offset Ghidra printed is that same value */
      *(char **)(&menuItems + menuCount * 4) = (char *)"Done";
      auStack_14[menuCount] = 3;
      again = '\0';
      do {
        entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
        if (bldType == 0) {
          textMsg = ovr_ovc22_className(AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3),0);
          puVar5 = (uint16_t *)((uint)AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3) * 4);
          msgSeg = _DS;
          computed = ovr_ovc45_compute9((char *)&text2,(char *)CONCAT22(*puVar5,_SS),
                                     (char *)CONCAT13((char)(Font03.ofs >> 8),
                                                      CONCAT12((char)Font03.ofs,puVar5[1])),
                                     Font03.seg,'J',(char)Font03.ofs,(char)Font03.seg,0x4a,3,textMsg)
          ;
          puVar5 = (uint16_t *)
                   ((uint)*(byte *)(GTileRecords[tileIdx] * 0x12 + 9) * 4);
          computed = ovr_ovc45_compute9((char *)&text1,(char *)CONCAT22(*puVar5,_SS),
                                     (char *)CONCAT22(Font03.ofs,(char *)puVar5[1]),Font03.seg,'J',
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
          puVar5 = (uint16_t *)((uint)AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3) * 4);
          msgSeg = _DS;
          computed = ovr_ovc45_compute9((char *)&text2,(char *)CONCAT22(*puVar5,_SS),
                                     (char *)CONCAT13((char)(Font03.ofs >> 8),
                                                      CONCAT12((char)Font03.ofs,puVar5[1])),
                                     Font03.seg,'_',(char)Font03.ofs,(char)Font03.seg,0x5f,3,textMsg)
          ;
          puVar5 = (uint16_t *)
                   ((uint)*(byte *)(GTileRecords[tileIdx] * 0x12 + 9) * 4);
          delayArg = 0x7a;
          computed = ovr_ovc45_compute9((char *)&text1,(char *)CONCAT22(*puVar5,_SS),
                                     (char *)CONCAT22(Font03.ofs,(char *)puVar5[1]),Font03.seg,'_',
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
        (*(uint8_t *)((uint8_t *)&(entries_00.seg))) = uVar13;
        entries_00.ofs = (uint16_t)stashOfs;
        (*(uint8_t *)((uint8_t *)&(entries_00.seg) + 1)) = uVar14;
        ovr_ovc28_compute2(entries_00,menuCount + 1,hint_00,0,0);
        itemCode = (char)stashOfs;
        goldPartyIndex = 0xff;
        if (itemCode != '\0') {
          itemCode = auStack_14[((uint)stashOfs & 0xff) - 1];
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
          (*(uint8_t *)((uint8_t *)&(entries_01.seg))) = uVar13;
          entries_01.ofs = (uint16_t)stashOfs;
          (*(uint8_t *)((uint8_t *)&(entries_01.seg) + 1)) = uVar14;
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
  byte bVar1;
  int iVar2;
  
  bVar1 = ovr_manage_findFirstLeader();
  if (bVar1 == 0xff) {
    iVar2 = 0;
  }
  else if ((GLeaderSheets[bVar1])->titleIndex < 5) {
    iVar2 = 0x14;
  }
  else {
    iVar2 = (uint)(GLeaderSheets[bVar1])->titleIndex * 4 + 0x14;
  }
  return iVar2;
}



/* 7e7c:0b9c */
/* DECOMPILATION FAILED: Exception while decompiling 7e7c:0b9c: process: timeout
 */
undefined constrct_buildInfoText() { return 0; }

/* 7e7c:2b4c */
void __cdecl16far constrct_usesLDIV_at_(byte partyIndex,int entityIndex)

{
  undefined1 stk_ff60;   /* stack slot ff60 */
  uint *puVar1;
  int *piVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  long *plVar6;
  char *msg;
  uint16_t uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint16_t unaff_SI;
  uint uVar12;
  long *unaff_DI;
  int iVar13;
  uint16_t uVar14;
  uint16_t uVar15;
  long lVar16;
  long lVar17;
  uint32_t in_stack_0000ff5e;
  long in_stack_0000ff62;
  uint16_t count;
  
  lVar17 = CONCAT22((int)((ulong)in_stack_0000ff5e >> 0x10),unaff_SI);
  bVar3 = AGNT_FIELD(&(Entities)[entityIndex], base.entity, 3);
  if ((partyIndex != 0xff) && (bVar3 != 0xff)) {
    bVar4 = (GLeaderSheets[partyIndex])->classStr;
    iVar9 = AGNT_WORD(&AgntGs[(uint)bVar4], shortName, 5);
    uVar5 = AGNT_WORD(&AgntGs[(uint)bVar4], shortName, 5) * 0xf;
    iVar13 = 0;
    for (uVar12 = 0; uVar12 < EntityCount; uVar12 = uVar12 + 1) {
      uVar14 = (uint16_t)((ulong)Entities >> 0x10);
      uVar14 = ovr_ovc23_isCursorAt
                         ((Entities)[uVar12].base.x,(Entities)[uVar12].base.y,0);
      if (((char)uVar14 != '\0') &&
         (AgntGs[(uint)(Entities)[uVar12].base.gindex].ai == '\0')) {
        iVar13 = iVar13 + 1;
      }
    }
    lVar16 = LDIV_at_((ulong)(uint)(iVar9 * 0xf),(long)iVar13);
    uVar7 = (uint16_t)((ulong)(lVar16 + 1) >> 0x10);
    uVar14 = uVar7;
    plVar6 = LXMUL_at_(unaff_DI,lVar17,in_stack_0000ff62);
    count = (uint16_t)(lVar16 + 1);
    msg = ovr_stsprintf(&stk_ff60,(char *)CONCAT22(0x81dc,_SS),
                        (char *)CONCAT22(plVar6,(char *)0x2410),uVar14,count,uVar7,
                        uVar5);
    ovr_say(msg,0);
    lVar17 = LDIV_at_((ulong)uVar5,10);
    uVar14 = (uint16_t)((ulong)*(uint32_t *)((uint)bVar3 << 2) >> 0x10);
    iVar9 = (int)*(uint32_t *)((uint)bVar3 << 2);
    uVar8 = uVar5 - (uint)lVar17;
    puVar1 = (uint *)(iVar9 + 0x56);
    uVar12 = *puVar1;
    *puVar1 = *puVar1 + uVar8;
    piVar2 = (int *)(iVar9 + 0x58);
    *piVar2 = *piVar2 + (-(uint)(uVar5 < (uint)lVar17) - (int)((ulong)lVar17 >> 0x10)) +
              (uint)CARRY2(uVar12,uVar8);
    lVar17 = lVar17 + CONCAT22(GPopulationHi,GPopulationLo);
    GPopulationLo = (uint16_t)lVar17;
    GPopulationHi = (uint16_t)((ulong)lVar17 >> 0x10);
    uVar14 = (uint16_t)((ulong)*(uint32_t *)((uint)bVar3 << 2) >> 0x10);
    iVar10 = (int)*(uint32_t *)((uint)bVar3 << 2);
    iVar9 = *(int *)(iVar10 + 0x58);
    uVar7 = (uint16_t)((ulong)*(uint32_t *)((uint)bVar3 << 2) >> 0x10);
    iVar11 = (int)*(uint32_t *)((uint)bVar3 << 2);
    iVar13 = *(int *)(iVar11 + 0x8c);
    if ((iVar13 <= iVar9) &&
       ((iVar13 < iVar9 || (*(uint *)(iVar11 + 0x8a) < *(uint *)(iVar10 + 0x56))))) {
      uVar7 = (uint16_t)((ulong)*(uint32_t *)((uint)bVar3 << 2) >> 0x10);
      iVar9 = (int)*(uint32_t *)((uint)bVar3 << 2);
      uVar14 = *(uint16_t *)(iVar9 + 0x8a);
      uVar15 = (uint16_t)((ulong)*(uint32_t *)((uint)bVar3 << 2) >> 0x10);
      iVar13 = (int)*(uint32_t *)((uint)bVar3 << 2);
      *(uint16_t *)(iVar13 + 0x58) = *(uint16_t *)(iVar9 + 0x8c);
      *(uint16_t *)(iVar13 + 0x56) = uVar14;
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
  uint32_t sheetRef;
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
  sheetRef = *(uint32_t *)((uint)units[unitIndex].unitType << 2);
  if (*(char *)((int)sheetRef + 0x3f) != '\0') {
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


