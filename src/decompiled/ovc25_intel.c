/*
 * ovc25_intel.c - recovered from STRONG.EXE
 * memory block: OVC25_intel.c
 * range: 5b66:0000 - 5b66:1def
 * functions: 20
 */
#include "recovered.h"


/* 5b66:0000 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

uint __cdecl16far
ovc25_usesAlignUp4(char partyIndex,uint16_t x,uint16_t y,uint16_t destX,uint16_t destY)

{
  /* Re-derived: the first entity of the given party that is either standing at (x,y) or whose
     destination is not (destX,destY) - a unit not already committed there - skipping entities
     whose flags32 word has bit 1 set; 0xffff when none is found. */
  uint destAligned;
  uint entAligned;
  uint checkAligned;
  int entitiesOfs;
  uint entIdx;

  destAligned = ovr_alignUp4(destX,0,0);
  entAligned = ovr_alignUp4(x,0,0);
  entIdx = 0;
  do {
    if (EntityCount <= entIdx) {
      return 0xffff;
    }
    entitiesOfs = (int)Entities;
    if ((AGNT_FIELD(&(Entities)[entIdx], base.entity, 3) == partyIndex) &&
       ((AGNT_FIELD(&(Entities)[entIdx], base.flags32, 1) & 2) == 0)) {
      checkAligned = ovr_alignUp4(*(int *)((entity_t *)entitiesOfs + entIdx),0,0);
      if ((checkAligned == entAligned) && ((Entities)[entIdx].base.y == y)) {
        return entIdx;
      }
      checkAligned = ovr_alignUp4((Entities)[entIdx].base.destX,0,0);
      if (checkAligned != destAligned) {
        return entIdx;
      }
      if ((Entities)[entIdx].base.destY != destY) {
        return entIdx;
      }
    }
    entIdx = entIdx + 1;
  } while( true );
}



/* 5b66:00ff */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

uint16_t __cdecl16far
ovc25_usesAlignUp42(char partyIndex,byte count,uint16_t destX,uint16_t destY,uint16_t x,uint16_t y)

{
  /* Re-derived: flags every entity of the party that stands at the destination cell, or is
     already heading there, with bit 8; then places up to `count` further units there and
     returns 0xffff when the scan ends.  The export's label existed only to skip the flag
     store, so it is a guard on that statement. */
  byte *flagsPtr;
  uint entAligned;
  uint destAligned;
  uint entIdx;
  int placed;
  bool atCell;

  entIdx = 0;
  do {
    if (EntityCount <= entIdx) {
      if (count != 0) {
        for (placed = 0;
             (placed < (int)(uint)count &&
              (entIdx = ovc25_usesAlignUp4(partyIndex,x,y,destX,destY), -1 < (int)entIdx));
             placed = placed + 1) {
          (Entities)[entIdx].base.state = 0;
          (Entities)[entIdx].base.destX = destX;
          (Entities)[entIdx].base.destY = destY;
          flagsPtr = (byte *)((uint8_t *)&(Entities)[entIdx] + 0x33);
          *flagsPtr = *flagsPtr | 8;
        }
      }
      return 0xffff;
    }
    if (*(char *)((int)&(Entities)[entIdx].base.entity + 3) == partyIndex) {
      atCell = true;
      entAligned = ovr_alignUp4((Entities)[entIdx].base.x,0,0);
      destAligned = ovr_alignUp4(destX,0,0);
      if ((entAligned != destAligned) ||
         ((Entities)[entIdx].base.y != destY)) {
        entAligned = ovr_alignUp4((Entities)[entIdx].base.destX,0,0);
        destAligned = ovr_alignUp4(destX,0,0);
        atCell = !((entAligned != destAligned) ||
                   ((Entities)[entIdx].base.destY != destY));
      }
      if (atCell) {
        flagsPtr = (byte *)((uint8_t *)&(Entities)[entIdx] + 0x33);
        *flagsPtr = *flagsPtr | 8;
      }
    }
    entIdx = entIdx + 1;
  } while( true );
}



/* 5b66:028d */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R2] string "arena" */

bool __cdecl16far ovc25_textArena(uint *foundIndexOut,char includeFlag8,uint16_t partyIndex,int x)

{
  uint targetX;
  uint dist;
  uint dy;
  uint signMaskX;
  uint signMaskY;
  uint entityIndex;
  int targetY;
  uint bestDist;
  
  bestDist = 0xffff;
  targetX = ovr_alignUp4(x,0,0);
  for (entityIndex = 0; entityIndex < EntityCount; entityIndex = entityIndex + 1) {
    if (*(char *)((int)&(Entities)[entityIndex].base.entity + 3) == (char)partyIndex) {
      dist = ovr_alignUp4((Entities)[entityIndex].base.x,0,0);
      signMaskX = (int)(dist - targetX) >> 0xf;
      dy = (Entities)[entityIndex].base.y - targetY;
      signMaskY = (int)dy >> 0xf;
      dist = ((dist - targetX ^ signMaskX) - signMaskX) + ((dy ^ signMaskY) - signMaskY) * 2;
      if ((((dist != 0) && (dist < bestDist)) &&
          ((AGNT_FIELD(&(Entities)[entityIndex], base.flags32, 1) & 2) == 0)) &&
         ((includeFlag8 != '\0' || ((AGNT_FIELD(&(Entities)[entityIndex], base.flags32, 1) & 8) == 0)))) {
        *foundIndexOut = entityIndex;
        bestDist = dist;
      }
    }
  }
  return bestDist != 0xffff;
}



/* 5b66:038d */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

void __cdecl16far
ovc25_usesAlignUp43(char partyIndex,byte count,uint16_t destX,uint16_t destY,char setFlag8)

{
  byte *pbVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint16_t uVar6;
  uint16_t curSeg = _SS;
  uint8_t entityIndex;
  
  if (count != 0) {
    iVar5 = 0;
    for (entityIndex = 0; entityIndex < EntityCount; entityIndex = entityIndex + 1) {
      uVar6 = (uint16_t)((ulong)Entities >> 0x10);
      if (*(char *)((int)&(Entities)[entityIndex].base.entity + 3) == partyIndex) {
        uVar3 = ovr_alignUp4((Entities)[entityIndex].base.x,0,0);
        uVar4 = ovr_alignUp4(destX,0,0);
        uVar6 = (uint16_t)((ulong)Entities >> 0x10);
        if ((uVar3 != uVar4) || ((Entities)[entityIndex].base.y != destY))
        {
          uVar3 = ovr_alignUp4((Entities)[entityIndex].base.destX,0,0);
          uVar4 = ovr_alignUp4(destX,0,0);
          if ((uVar3 != uVar4) ||
             ((Entities)[entityIndex].base.destY != destY))
          goto L_OVC25_5b66_038d_0482;
        }
        iVar5 = iVar5 + 1;
        if (setFlag8 != '\0') {
          pbVar1 = (byte *)((uint8_t *)&(Entities)[entityIndex] + 0x33);
          *pbVar1 = *pbVar1 | 8;
        }
      }
L_OVC25_5b66_038d_0482:
    }
    while ((iVar5 < (int)(uint)count &&
           (bVar2 = ovc25_textArena((uint *)CONCAT22(curSeg,&entityIndex),setFlag8,
                                    (uint)(byte)partyIndex,destX), bVar2))) {
      (Entities)[entityIndex].base.state = 0;
      (Entities)[entityIndex].base.destX = destX;
      (Entities)[entityIndex].base.destY = destY;
      if (setFlag8 != '\0') {
        pbVar1 = (byte *)((uint8_t *)&(Entities)[entityIndex] + 0x33);
        *pbVar1 = *pbVar1 | 8;
      }
      iVar5 = iVar5 + 1;
    }
  }
  return;
}



/* 5b66:0530 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

void __cdecl16far ovc25_usesAlignUp44(char partyIndex,byte count,uint16_t destX,uint16_t destY)

{
  bool ok;
  uint entX;
  uint wantX;
  int placed;
  uint16_t curSeg = _SS;
  uint8_t entityIndex;
  
  if (count != 0) {
    placed = 0;
    for (entityIndex = 0; entityIndex < EntityCount; entityIndex = entityIndex + 1) {
      if (*(char *)((int)&(Entities)[entityIndex].base.entity + 3) == partyIndex) {
        entX = ovr_alignUp4((Entities)[entityIndex].base.destX,0,0);
        wantX = ovr_alignUp4(destX,0,0);
        if ((entX == wantX) && ((Entities)[entityIndex].base.destY == destY))
        {
          placed = placed + 1;
        }
      }
    }
    while ((placed < (int)(uint)count &&
           (ok = ovc25_textArena((uint *)CONCAT22(curSeg,&entityIndex),'\x02',
                                    (uint)(byte)partyIndex,destX), ok))) {
      (Entities)[entityIndex].base.state = 0;
      (Entities)[entityIndex].base.destX = destX;
      (Entities)[entityIndex].base.destY = destY;
      placed = placed + 1;
    }
    while ((placed < (int)(uint)count &&
           (ok = ovc25_textArena((uint *)CONCAT22(curSeg,&entityIndex),'\x01',
                                    (uint)(byte)partyIndex,destX), ok))) {
      (Entities)[entityIndex].base.state = 0;
      (Entities)[entityIndex].base.destX = destX;
      (Entities)[entityIndex].base.destY = destY;
      placed = placed + 1;
    }
    while ((placed < (int)(uint)count &&
           (ok = ovc25_textArena((uint *)CONCAT22(curSeg,&entityIndex),'\0',
                                    (uint)(byte)partyIndex,destX), ok))) {
      (Entities)[entityIndex].base.state = 0;
      (Entities)[entityIndex].base.destX = destX;
      (Entities)[entityIndex].base.destY = destY;
      placed = placed + 1;
    }
  }
  return;
}



/* 5b66:0722 */

/* Searches square rings out to 99 cells for a cell occupied by a unit (attact_usesGUnits), writing
   the found coordinates through the two pointers. */

uint __cdecl16far ovc25_findUnitCell(int *x,uint *y)

{
  /* Re-derived from 5b66:0722.  Both parameters are far pointers read directly by the
     original (`les bx, ptr [bp+6]` / `les bx, ptr [bp+0xa]`), so the exported CONCAT22 forms
     were wrong: they invented an in_stack_00000004 slot at [bp+4] - the far return CS, never
     read - and built the y pointer from x's segment word as an offset.  The spiral search is
     unchanged. */
  int baseX;
  uint baseY;
  uint16_t found;
  uint retAcc;
  uint dy;
  uint dx;
  char stepX;
  byte stepY;
  uint radius;

  baseX = *x;
  baseY = *y;
  radius = 0;
  retAcc = baseY;
  do {
    if (99 < radius) {
      return retAcc & 0xff00;
    }
    for (dx = 0; dx <= radius; dx = dx + 1) {
      for (dy = 0; dy <= radius; dy = dy + 1) {
        stepY = 0xff;
        while ((0x7f < stepY || ((dx != 0 && ((char)stepY < '\x02'))))) {
          stepX = -1;
          while ((stepX < '\0' || ((dy != 0 && (stepX < '\x02'))))) {
            found = ovr_attact_usesGUnits(baseX + dx * (int)stepX,
                                          baseY + dy * (int)stepX);
            if ((char)found != '\0') {
              *x = baseX + dx * (int)stepX;
              *y = baseY + dy * (int)stepX;
              return CONCAT11((char)(dy * (int)stepX >> 8),1);
            }
            stepX = stepX + '\x02';
            retAcc = CONCAT11((char)((uint)found >> 8),stepX);
          }
          stepY = stepY + '\x02';
          retAcc = CONCAT11((char)(retAcc >> 8),stepY);
        }
      }
    }
    radius = radius + 1;
  } while( true );
}



/* 5b66:080f */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches EntityCount, Entities */

void __cdecl16far ovc25_usesEntityCount(char partyIndex)

{
  byte *pbVar1;
  uint uVar2;
  
  for (uVar2 = 0; uVar2 < EntityCount; uVar2 = uVar2 + 1) {
    if (*(char *)((int)&(Entities)[uVar2].base.entity + 3) == partyIndex) {
      pbVar1 = (byte *)((uint8_t *)&(Entities)[uVar2] + 0x33);
      *pbVar1 = *pbVar1 & 0xf7;
    }
  }
  return;
}



/* 5b66:085d */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Emits the spy report for a party heading towards a stronghold. */

void __cdecl16far ovc25_spyReportNotice(void)

{
  int *counterPtr;
  uint dist;
  uint alignX;
  uint dy;
  char *msg;
  uint16_t randPick;
  uint distSign;
  uint dySign;
  int labelOfs;
  uint enemyIdx;
  uint16_t entitiesSeg;
  uint16_t curSeg = _SS;
  static char text[64];   /* DGROUP-backed formatting buffer */
  byte classIdx;
  undefined1 otherIdx;
  byte otherLeaderIdx;
  uint enemyDist2;
  uint leaderX;
  uint otherDist;
  uint enemyDist;
  uint idx;
  uint leaderIdx;
  uint16_t spawnY;
  uint16_t spawnX;
  int classValue;
  
  for (leaderIdx = 0; (int)leaderIdx < (int)(uint)GLeaderCount; leaderIdx = leaderIdx + 1) {
    if ((GLeaderSheets[leaderIdx])->active != '\0') {
      (GLeaderSheets[leaderIdx])->unitsOnTile = 0;
      (GLeaderSheets[leaderIdx])->unitsNear = 0;
      (GLeaderSheets[leaderIdx])->enemiesNear = 0;
      (GLeaderSheets[leaderIdx])->unitCount = 0;
      enemyDist = 0xffff;
      enemyIdx = 0xffff;
      leaderX = ovr_alignUp4((GLeaderSheets[leaderIdx])->x,0,0);
      for (idx = 0; idx < EntityCount; idx = idx + 1) {
        entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
        if (AGNT_FIELD(&(Entities)[idx], base.entity, 3) == leaderIdx) {
          dist = (GLeaderSheets[leaderIdx])->x -
                  *(int *)(Entities + idx);
          distSign = (int)dist >> 0xf;
          dy = (GLeaderSheets[leaderIdx])->y -
                  (Entities)[idx].base.y;
          dySign = (int)dy >> 0xf;
          counterPtr = (int *)((int)(uint32_t)GLeaderSheets[leaderIdx] + 0x45);
          *counterPtr = *counterPtr + 1;
          if ((int)((dist ^ distSign) - distSign) / 2 + ((dy ^ dySign) - dySign) < 10) {
            counterPtr = (int *)((int)(uint32_t)GLeaderSheets[leaderIdx] + 0x41);
            *counterPtr = *counterPtr + 1;
            entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
            if (((GLeaderSheets[leaderIdx])->y ==
                 (Entities)[idx].base.y) &&
               (alignX = ovr_alignUp4((Entities)[idx].base.x,0,0), alignX == leaderX
               )) {
              counterPtr = (int *)((int)(uint32_t)GLeaderSheets[leaderIdx] + 0x47);
              *counterPtr = *counterPtr + 1;
            }
          }
        }
        else if (AgntGs[(uint)(Entities)[idx].base.gindex].ai !=
                 *((char far *)GLeaderSheets[leaderIdx] + 0x3f)) {
          dist = (GLeaderSheets[leaderIdx])->x -
                  *(int *)(Entities + idx);
          distSign = (int)dist >> 0xf;
          dy = (GLeaderSheets[leaderIdx])->y -
                  (Entities)[idx].base.y;
          dySign = (int)dy >> 0xf;
          dist = (int)((dist ^ distSign) - distSign) / 2 + ((dy ^ dySign) - dySign);
          if (dist < enemyDist) {
            enemyIdx = idx;
            enemyDist = dist;
          }
          if (dist < 10) {
            counterPtr = (int *)((int)(uint32_t)GLeaderSheets[leaderIdx] + 0x43);
            *counterPtr = *counterPtr + 1;
          }
        }
      }
      (GLeaderSheets[leaderIdx])->nearestEnemy = enemyIdx;
      otherIdx = 0xff;
      if (*((char far *)GLeaderSheets[leaderIdx] + 0x40) != '\0') {
        otherDist = 0xffff;
        for (idx = 0; (int)idx < (int)(uint)GLeaderCount; idx = idx + 1) {
          if ((*((char far *)GLeaderSheets[idx] + 0x3f) !=
               *((char far *)GLeaderSheets[leaderIdx] + 0x3f)) &&
             (dist = (GLeaderSheets[leaderIdx])->x -
                      (GLeaderSheets[idx])->x,
             distSign = (int)dist >> 0xf,
             dy = (GLeaderSheets[leaderIdx])->y -
                     (GLeaderSheets[idx])->y, dySign = (int)dy >> 0xf
             , dist = (int)((dist ^ distSign) - distSign) / 2 + ((dy ^ dySign) - dySign),
             dist < otherDist)) {
            otherIdx = (undefined1)idx;
            otherDist = dist;
          }
        }
      }
      *((undefined1 far *)GLeaderSheets[leaderIdx] + 0x49) = otherIdx;
    }
  }
  for (leaderIdx = 0; (int)leaderIdx < (int)(uint)GLeaderCount; leaderIdx = leaderIdx + 1) {
    if ((*((char far *)GLeaderSheets[leaderIdx] + 0x40) != '\0') &&
       ((GLeaderSheets[leaderIdx])->active != '\0')) {
      ovc25_intelAttackingNotice((byte)leaderIdx);
      if ((GLeaderSheets[leaderIdx])->nearestEnemy == -1) {
        enemyDist2 = 0xffff;
      }
      else {
        enemyIdx = (GLeaderSheets[leaderIdx])->nearestEnemy;
        entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
        dist = (GLeaderSheets[leaderIdx])->x -
                (Entities)[enemyIdx].base.x;
        distSign = (int)dist >> 0xf;
        dy = (GLeaderSheets[leaderIdx])->y -
                (Entities)[enemyIdx].base.y;
        dySign = (int)dy >> 0xf;
        enemyDist2 = (int)((dist ^ distSign) - distSign) / 2 + ((dy ^ dySign) - dySign);
      }
      if (((GLeaderSheets[leaderIdx])->enemiesNear == 0) || (9 < enemyDist2)) {
        if ((*((char far *)GLeaderSheets[leaderIdx] + 0x49) == -1) ||
           (((GLeaderSheets[leaderIdx])->flags5d & 1) == 0)) {
          if ((GLeaderSheets[leaderIdx])->unitsOnTile < 10) {
            ovc25_usesAlignUp43((byte)leaderIdx,10,
                                (GLeaderSheets[leaderIdx])->x,
                                (GLeaderSheets[leaderIdx])->y,'\0');
            (GLeaderSheets[leaderIdx])->reportState = 0;
          }
          else {
            (GLeaderSheets[leaderIdx])->reportState = 0;
            classIdx = (GLeaderSheets[leaderIdx])->classStr;
            classValue = ovc25_compute1(classIdx);
            if ((int)(uint)PlayerCount < classValue) {
              randPick = ovr_randBelow(0x28,0);
              spawnX = (GLeaderSheets[leaderIdx])->x + -0x14 +
                         (randPick & 0xff);
              if ((int)spawnX < 4) {
                spawnX = 4;
              }
              if (0x8c < (int)spawnX) {
                spawnX = 0x8b;
              }
              randPick = ovr_randBelow(0x14,0);
              spawnY = (GLeaderSheets[leaderIdx])->y + -10 + (randPick & 0xff)
              ;
              if ((int)spawnY < 1) {
                spawnY = 1;
              }
              if (0x3a < (int)spawnY) {
                spawnY = 0x3a;
              }
              ovc25_usesAlignUp44((char)leaderIdx,1,spawnX,spawnY);
            }
          }
        }
        else {
          ovc25_usesEntityCount((byte)leaderIdx);
          otherLeaderIdx = *((byte far *)GLeaderSheets[leaderIdx] + 0x49);
          if (0xe < (GLeaderSheets[leaderIdx])->unitsOnTile) {
            ovc25_usesAlignUp42((byte)leaderIdx,10,
                                (GLeaderSheets[otherLeaderIdx])->x,
                                (GLeaderSheets[otherLeaderIdx])->y,
                                (GLeaderSheets[leaderIdx])->x,
                                (GLeaderSheets[leaderIdx])->y);
            if ((GLeaderSheets[leaderIdx])->reportState != '\x02') {
              alignX = ovr_alignUp4((GLeaderSheets[otherLeaderIdx])->x,
                                   (GLeaderSheets[otherLeaderIdx])->y,0xa000);
              labelOfs = (uint)(GLeaderSheets[leaderIdx])->classStr * 0x95;
              msg = ovr_stsprintf(text,(char *)CONCAT22(0x58c0,curSeg),
                                  (char *)CONCAT22(*(uint16_t *)
                                                    ((int)&worldMenuLabels[0].seg + 1 + labelOfs),
                                                   (char *)0x26510),
                                  *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + labelOfs),alignX);
              asm { mov randPick,dx };
              ovr_uiNotify(msg,randPick,0);
            }
          }
          ovc25_usesAlignUp43((byte)leaderIdx,0xf,
                              (GLeaderSheets[leaderIdx])->x,
                              (GLeaderSheets[leaderIdx])->y,'\0');
          (GLeaderSheets[leaderIdx])->reportState = 2;
        }
      }
      else {
        ovc25_usesEntityCount((byte)leaderIdx);
        if (9 < (GLeaderSheets[leaderIdx])->unitsOnTile) {
          entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
          ovc25_usesAlignUp43((byte)leaderIdx,5,(Entities)[enemyIdx].base.x,
                              (Entities)[enemyIdx].base.y,'\x01');
        }
        ovc25_usesAlignUp43((byte)leaderIdx,10,
                            (GLeaderSheets[leaderIdx])->x,
                            (GLeaderSheets[leaderIdx])->y,'\0');
        (GLeaderSheets[leaderIdx])->reportState = 1;
      }
    }
  }
  ovc25_clearEntityFlags();
  return;
}



/* 5b66:112d */

/* Returns whether a building stands within two columns of (x,y). */

uint __cdecl16far ovc25_hasBuildingNear(uint16_t x,int y)

{
  /* 5b66:112d, re-derived.  Scans the four grid columns starting at alignUp4(x) for a
     unit whose BuildingTypes[bldType].byte_0x11a is set; bldType >= 0xf8 means "empty".
     The tail sets only AL (mov al,0 at 0x4E5BD and 0x4E625, mov al,1 at 0x4E61B), so the
     exported CONCAT11 / `& 0xff00` returns were stale-AH artifacts and this is a
     boolean. */
  uint alignedX;
  uint alignedEnd;
  int gx;
  int unitIdx;
  byte bldType;
  uint bldOfs;

  alignedX = ovr_alignUp4(x,0,0);
  alignedEnd = alignedX + 3;
  if (((int)alignedEnd < 0x94) && (-1 < (int)alignedX) && (y < 0x3c) && (-1 < y)) {
    for (gx = -2; gx < 2; gx = gx + 1) {
      unitIdx = (*(short (*) [148] [60])GUnitGrid)[alignedX + gx][y];
      bldType = (GUnits + unitIdx)->bldType;
      bldOfs = (uint)bldType * 0x27;
      if ((bldType < 0xf8) && (*(char *)(bldOfs + 0x11a) != '\0')) {
        return 1;
      }
    }
  }
  return 0;
}



/* 5b66:11cb */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

int __cdecl16far ovc25_usesAlignUp46(uint16_t x,uint16_t y,char excluded,uint8_t *foundFlag)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint16_t uVar4;
  undefined1 *in_stack_0000000a;
  int iStack_4;
  
  uVar1 = ovr_alignUp4(x,0,0);
  iStack_4 = 0;
  *(undefined1 *)CONCAT22((uint8_t *)foundFlag,in_stack_0000000a) = 0;
  uVar3 = 0;
  do {
    if (EntityCount <= uVar3) {
      return iStack_4;
    }
    uVar4 = (uint16_t)((ulong)Entities >> 0x10);
    if ((((*((uint8_t far *)&(Entities)[uVar3].base.flags32 + 1) & 2) != 0) &&
        (uVar2 = ovr_alignUp4((Entities)[uVar3].base.targetX,0,0), uVar2 == uVar1)) &&
       ((Entities)[uVar3].base.targetY == y)) {
      *(undefined1 *)CONCAT22((uint8_t *)foundFlag,in_stack_0000000a) = 1;
    }
    uVar2 = ovr_alignUp4((Entities)[uVar3].base.x,0,0);
    if (uVar2 == uVar1) {
      uVar4 = (uint16_t)((ulong)Entities >> 0x10);
      if ((Entities)[uVar3].base.y == y) {
        if (AgntGs[(uint)(Entities)[uVar3].base.gindex].ai != excluded
           ) {
          return 0xff;
        }
        iStack_4 = iStack_4 + 1;
      }
    }
    uVar3 = uVar3 + 1;
  } while( true );
}



/* 5b66:12de */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Clears the per-entity byte at base.entity+2 and rebuilds the derived table when entities exist.
    */

void __cdecl16far ovc25_clearEntityFlags(void)

{
  uint16_t uStack_6;
  
  for (uStack_6 = 0; uStack_6 < EntityCount; uStack_6 = uStack_6 + 1) {
    AGNT_FIELD(&(Entities)[uStack_6], base.entity, 2) = 0;
  }
  if (EntityCount != 0) {
    ovc25_usesAlignUp47();
    return;
  }
  return;
}



/* 5b66:131f */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* [R4] calls ovr_alignUp4 */

void ovc25_usesAlignUp47(void)

{
  uint32_t tablePtr;
  uint uVar2;
  uint alignedX;
  uint16_t randDir;
  int result46;
  int unaff_BP;
  uint uVar6;
  uint16_t uVar7;
  uint16_t curSeg = _SS;
  uint16_t in_stack_00000000;
  
  uVar7 = (uint16_t)((ulong)Entities >> 0x10);
  if (*(char *)((int)Entities + *(int *)(unaff_BP + -4) * 0x37 + 0x19) != '\0') {
    OVC25_5b66_131f_entry();
    return;
  }
  *(undefined1 *)((int)Entities + *(int *)(unaff_BP + -4) * 0x37 + 0x19) = 1;
  *(undefined1 *)(unaff_BP + -0xc) =
       *(undefined1 *)((int)Entities + *(int *)(unaff_BP + -4) * 0x37 + 0x1a);
  *(undefined1 *)(unaff_BP + -0xb) =
       *(undefined1 *)((int)Entities + *(int *)(unaff_BP + -4) * 0x37 + 0xd);
  *(undefined1 *)(unaff_BP + -0xd) =
       AgntGs[(uint)*(byte *)(unaff_BP + -0xb)].ai;
  uVar7 = (uint16_t)((ulong)Entities >> 0x10);
  if ((*(char *)((int)Entities + *(int *)(unaff_BP + -4) * 0x37 + 0x18) != '\0') ||
     (*(char *)(unaff_BP + -0xd) != '\0')) {
    if (*(char *)(unaff_BP + -0xd) == '\0') {
      OVC25_5b66_131f_entry();
      return;
    }
    tablePtr = *(uint32_t *)((uint)*(byte *)(unaff_BP + -0xc) << 2);
    if (*(char *)((int)tablePtr + 0x4a) != '\0') {
      OVC25_5b66_131f_entry();
      return;
    }
  }
  uVar2 = ovr_alignUp4(*(int *)((int)Entities + *(int *)(unaff_BP + -4) * 0x37),0,0);
  *(uint *)(unaff_BP + -6) = uVar2;
  uVar7 = (uint16_t)((ulong)Entities >> 0x10);
  if (((*(int *)(result46 + *(int *)(unaff_BP + -4) * 0x37 + 8) == 0) &&
      (*(int *)(result46 + *(int *)(unaff_BP + -4) * 0x37 + 10) == 0)) &&
     ((*(byte *)(result46 + *(int *)(unaff_BP + -4) * 0x37 + 0x33) & 3) == 0)) {
    uVar2 = *(uint *)(unaff_BP + -4);
  }
  else {
    uVar2 = 0xffff;
  }
  *(uint16_t *)(unaff_BP + -0x10) = 1;
  uVar6 = *(uint *)(unaff_BP + -4);
  while (uVar6 = uVar6 + 1, uVar6 < EntityCount) {
    alignedX = ovr_alignUp4((Entities)[uVar6].base.x,0,0);
    if (alignedX == *(uint *)(unaff_BP + -6)) {
      uVar7 = (uint16_t)((ulong)Entities >> 0x10);
      if (((entity_t far *)Entities)[uVar6].base.y == *(int *)(result46 + *(int *)(unaff_BP + -4) * 0x37 + 2)
         ) {
        AGNT_FIELD(&(Entities)[uVar6], base.entity, 2) = 1;
        uVar7 = (uint16_t)((ulong)Entities >> 0x10);
        if (((((entity_t far *)Entities)[uVar6].base.destX == 0) && (((entity_t far *)Entities)[uVar6].base.destY == 0)
            ) && ((AGNT_FIELD(&(Entities)[uVar6], base.entity, 1) == '\0' &&
                  ((AgntGs[(uint)((entity_t far *)Entities)[uVar6].base.gindex].ai ==
                    *(char *)(unaff_BP + -0xd) &&
                   (*(int *)(unaff_BP + -0x10) = *(int *)(unaff_BP + -0x10) + 1,
                   (*((uint8_t far *)&(Entities)[uVar6].base.flags32 + 1) & 3) == 0)))))) {
          uVar2 = uVar6;
        }
      }
    }
  }
  if (uVar2 == 0xffff) {
    OVC25_5b66_131f_entry();
    return;
  }
  if (*(uint *)(unaff_BP + -0x10) < 2) {
    OVC25_5b66_131f_entry();
    return;
  }
  randDir = ovr_randBelow(4,0);
  *(undefined1 *)(unaff_BP + -9) = (char)randDir;
  *(undefined1 *)(unaff_BP + -10) = *(undefined1 *)(unaff_BP + -9);
  uVar6 = ovr_alignUp4((Entities)[uVar2].base.x +
                       *(char *)(*(byte *)(unaff_BP + -9) + 0x885) * 4,0,0);
  *(uint *)(unaff_BP + -6) = uVar6;
  *(int *)(unaff_BP + -8) =
       (Entities)[uVar2].base.y +
       (int)*(char *)(*(byte *)(unaff_BP + -9) + 0x889);
  uVar7 = ovr_attact_usesGUnits(*(int *)(unaff_BP + -6),*(int *)(unaff_BP + -8));
  if ((char)uVar7 != '\0') {
    result46 = ovc25_usesAlignUp46(*(uint16_t *)(unaff_BP + -6),*(uint16_t *)(unaff_BP + -8),
                                *(char *)(unaff_BP + -0xd),
                                (uint8_t *)CONCAT22(in_stack_00000000,curSeg));
    *(int *)(unaff_BP + -2) = result46;
    if (*(uint *)(unaff_BP + -0x10) <= *(uint *)(unaff_BP + -2)) {
      OVC25_5b66_131f_entry();
      return;
    }
    (Entities)[uVar2].base.destX = *(uint16_t *)(unaff_BP + -6);
    (Entities)[uVar2].base.destY = *(uint16_t *)(unaff_BP + -8);
    if ((*(char *)(unaff_BP + -0xd) == '\0') && (*(char *)(unaff_BP + -0xe) == '\0')) {
      (Entities)[uVar2].base.targetX = *(uint16_t *)(unaff_BP + -6);
      (Entities)[uVar2].base.targetY = *(uint16_t *)(unaff_BP + -8);
      AGNT_FIELD(&(Entities)[uVar2], base.flags32, 1) = 2;
      OVC25_5b66_131f_entry();
      return;
    }
    *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) + 1;
    if (EntityCount <= *(uint *)(unaff_BP + -4)) {
      return;
    }
    ovc25_usesAlignUp47();
    return;
  }
  ovc25_usesAlignUp48();
  return;
}



/* 5b66:1667 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* [R6] touches Entities, destX */

void ovc25_usesEntities(void)

{
  uint16_t in_AX;
  int unaff_BP;
  int unaff_DI;
  uint16_t curSeg = _SS;
  
  *(uint16_t *)(unaff_BP + -2) = in_AX;
  if (*(uint *)(unaff_BP + -0x10) <= *(uint *)(unaff_BP + -2)) {
    OVC25_5b66_131f_entry();
    return;
  }
  (Entities)[unaff_DI].base.destX = *(uint16_t *)(unaff_BP + -6);
  (Entities)[unaff_DI].base.destY = *(uint16_t *)(unaff_BP + -8);
  if ((*(char *)(unaff_BP + -0xd) == '\0') && (*(char *)(unaff_BP + -0xe) == '\0')) {
    (Entities)[unaff_DI].base.targetX = *(uint16_t *)(unaff_BP + -6);
    (Entities)[unaff_DI].base.targetY = *(uint16_t *)(unaff_BP + -8);
    AGNT_FIELD(&(Entities)[unaff_DI], base.flags32, 1) = 2;
    OVC25_5b66_131f_entry();
    return;
  }
  *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) + 1;
  if (*(uint *)(unaff_BP + -4) < EntityCount) {
    ovc25_usesAlignUp47();
    return;
  }
  return;
}



/* 5b66:170e */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* [R4] calls ovr_alignUp4 */

void ovc25_usesAlignUp48(void)

{
  uint alignedX;
  uint16_t unitsResult;
  int result46;
  int unaff_BP;
  int unaff_DI;
  uint16_t curSeg = _SS;
  uint16_t in_stack_00000000;
  
  *(byte *)(unaff_BP + -9) = *(char *)(unaff_BP + -9) + 1U & 3;
  if (*(char *)(unaff_BP + -9) != *(char *)(unaff_BP + -10)) {
    alignedX = ovr_alignUp4((Entities)[unaff_DI].base.x +
                         *(char *)(*(byte *)(unaff_BP + -9) + 0x885) * 4,0,0);
    *(uint *)(unaff_BP + -6) = alignedX;
    *(int *)(unaff_BP + -8) =
         (Entities)[unaff_DI].base.y +
         (int)*(char *)(*(byte *)(unaff_BP + -9) + 0x889);
    unitsResult = ovr_attact_usesGUnits(*(int *)(unaff_BP + -6),*(int *)(unaff_BP + -8));
    if ((char)unitsResult == '\0') {
      ovc25_usesAlignUp48();
      return;
    }
    result46 = ovc25_usesAlignUp46(*(uint16_t *)(unaff_BP + -6),*(uint16_t *)(unaff_BP + -8),
                                *(char *)(unaff_BP + -0xd),
                                (uint8_t *)CONCAT22(in_stack_00000000,curSeg));
    *(int *)(unaff_BP + -2) = result46;
    if (*(uint *)(unaff_BP + -0x10) <= *(uint *)(unaff_BP + -2)) {
      OVC25_5b66_131f_entry();
      return;
    }
    (Entities)[unaff_DI].base.destX = *(uint16_t *)(unaff_BP + -6);
    (Entities)[unaff_DI].base.destY = *(uint16_t *)(unaff_BP + -8);
    if ((*(char *)(unaff_BP + -0xd) == '\0') && (*(char *)(unaff_BP + -0xe) == '\0')) {
      (Entities)[unaff_DI].base.targetX = *(uint16_t *)(unaff_BP + -6);
      (Entities)[unaff_DI].base.targetY = *(uint16_t *)(unaff_BP + -8);
      AGNT_FIELD(&(Entities)[unaff_DI], base.flags32, 1) = 2;
      OVC25_5b66_131f_entry();
      return;
    }
  }
  *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) + 1;
  if (*(uint *)(unaff_BP + -4) < EntityCount) {
    ovc25_usesAlignUp47();
    return;
  }
  return;
}



/* 5b66:1723 */

/* [R1] forwards to OVC25_5b66_131f */

void __cdecl16far OVC25_5b66_131f_entry(void)

{
  int unaff_BP;
  uint16_t curSeg = _SS;
  
  *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) + 1;
  if (*(uint *)(unaff_BP + -4) < EntityCount) {
    ovc25_usesAlignUp47();
    return;
  }
  return;
}



/* 5b66:173b */

/* Formats the "%s is attacking." notice. */

void __cdecl16far ovc25_attackingNotice(byte partyIndex)

{
  byte *flagPtr;
  uint16_t randRoll;
  uint16_t notifySeg;
  uint8_t *stashPtr;
  char *msg;
  uint classWeight;
  uint16_t curSeg = _SS;
  static char text[64];   /* DGROUP-backed formatting buffer */
  byte partyClass;
  
  if (((partyIndex != 0xff) &&
      (*(char *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x3f) != '\0')) &&
     (*(int *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x5e) == 0)) {
    partyClass = (GLeaderSheets[partyIndex])->classStr;
    classWeight = (uint)AgntGs[(uint)partyClass].shortName[0] +
            (uint)AgntGs[(uint)partyClass].rank +
            (uint)AgntGs[(uint)partyClass].shortName[1];
    if (((classWeight < PlayerCount) &&
        (((GLeaderSheets[partyIndex])->flags5d & 1) == 0)) &&
       (randRoll = ovr_randBelow(100,0), (int)(randRoll & 0xff) < (int)(PlayerCount - classWeight))) {
      *(uint16_t *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x5e) = 0x19;
      ovr_play_sfx(82,0,0);
      notifySeg = _DS;
      stashPtr = ovr_ovc15_usesStshRealloc
                         ((char *)*(uint16_t *)((uint)partyIndex * 4),((uint16_t *)((uint)partyIndex * 4))[1],GSavedBlitSeg,0,0,0,0,0);
      msg = ovr_stsprintf(text,(char *)CONCAT22(0x58f5,curSeg),
                          (char *)CONCAT22(stashPtr,(char *)0x26510),notifySeg);
      ovr_uiNotify(msg,notifySeg,0);
      flagPtr = (byte *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x5d);
      *flagPtr = *flagPtr | 1;
    }
  }
  return;
}



/* 5b66:18cc */

/* [R7] body shape: compute */

int __cdecl16far ovc25_compute1(byte gindex)

{
  return (uint)AgntGs[(uint)gindex].shortName[0] +
         (uint)AgntGs[(uint)gindex].rank +
         (uint)AgntGs[(uint)gindex].shortName[1];
}



/* 5b66:1929 */

/* Emits the "Intelligence reports %s attacking." notice for a party. */

void __cdecl16far ovc25_intelAttackingNotice(byte partyIndex)

{
  byte *flagPtr;
  char roll;
  uint16_t randRoll;
  uint16_t notifySeg;
  uint8_t *stashPtr;
  char *msg;
  uint16_t curSeg = _SS;
  static char text[64];   /* DGROUP-backed formatting buffer */
  byte partyClass;
  int classCount;
  
  classCount = ovc25_compute1((GLeaderSheets[partyIndex])->classStr);
  if ((((((classCount < (int)(uint)PlayerCount) &&
         (*(int *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x5e) == 0)) &&
        (*(char *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x40) != '\0')) &&
       ((((GLeaderSheets[partyIndex])->flags5d & 1) == 0 &&
        (9 < (GLeaderSheets[partyIndex])->unitCount)))) &&
      ((*(char *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x49) != -1 &&
       ((partyClass = *(byte *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x49),
        (GLeaderSheets[partyClass])->unitCount < 0x50 ||
        (randRoll = ovr_randBelow(0x28,0), (char)randRoll == '\0')))))) &&
     (8 < ((agnt_t far *)(((uint)partyIndex << 2)))->teamCode)) {
    if ((GLeaderSheets[partyClass])->unitCount < 0x28) {
      if ((GLeaderSheets[partyClass])->unitCount < 0x14) {
        return;
      }
      randRoll = ovr_randBelow(0x78,0);
      roll = (char)randRoll;
    }
    else {
      randRoll = ovr_randBelow(0x50,0);
      roll = (char)randRoll;
    }
    if (roll == '\0') {
      ovr_play_sfx(82,0,0);
      *(uint16_t *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x5e) = 0x19;
      notifySeg = _DS;
      stashPtr = ovr_ovc15_usesStshRealloc
                         ((char *)*(uint16_t *)((uint)partyIndex * 4),((uint16_t *)((uint)partyIndex * 4))[1],GSavedBlitSeg,0,0,0,0,0);
      msg = ovr_stsprintf(text,(char *)CONCAT22(0x5906,curSeg),
                          (char *)CONCAT22(stashPtr,(char *)0x26510),notifySeg);
      ovr_uiNotify(msg,notifySeg,0);
      flagPtr = (byte *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x5d);
      *flagPtr = *flagPtr | 1;
    }
  }
  return;
}



/* 5b66:1b48 */

/* Ticks the party's +0x5e countdown; at zero it resets it to 10 and clears bit 0 of flags5d. */

void __cdecl16far ovc25_tickCountdown(int partyIndex)

{
  int *piVar1;
  byte *pbVar2;
  
  if ((((*((char far *)GLeaderSheets[partyIndex] + 0x3f) != '\0') &&
       (*((int far *)GLeaderSheets[partyIndex] + 0x5e) != 0)) &&
      (piVar1 = (int *)((int)(uint32_t)GLeaderSheets[partyIndex] + 0x5e), *piVar1 = *piVar1 + -1,
      ((GLeaderSheets[partyIndex])->flags5d & 1) != 0)) &&
     (*((int far *)GLeaderSheets[partyIndex] + 0x5e) == 0)) {
    *((uint16_t far *)GLeaderSheets[partyIndex] + 0x5e) = 10;
    pbVar2 = (byte *)((int)(uint32_t)GLeaderSheets[partyIndex] + 0x5d);
    *pbVar2 = *pbVar2 & 0xfe;
  }
  return;
}



/* 5b66:1d94 */

/* WARNING: Instruction at (ram,0x0005d43a) overlaps instruction at (ram,0x0005d438)
    */

uint16_t __cdecl16far SUB_5b66_1d94(gridX,gridY,ignoreBlocked)
int gridX;
int gridY;
char ignoreBlocked;

{
  uint *puVar1;
  char *pcVar2;
  byte *pbVar3;
  int x;
  int y;
  char cVar4;
  uint uVar5;
  long lVar6;
  uint32_t uVar7;
  int *piVar8;
  uint16_t uVar9;
  int *piVar10;
  uint16_t uVar11;
  int *piVar12;
  int *piVar13;
  uint in_AX;
  uint uVar14;
  byte bVar16;
  byte bVar17;
  uint uVar15;
  char cVar18;
  uint16_t in_CX;
  byte bVar19;
  uint in_DX;
  int iVar21;
  uint uVar22;
  uint in_BX;
  int iVar23;
  byte bVar24;
  uint unaff_BP;
  uint uVar25;
  int iVar26;
  uint *unaff_SI;
  uint unaff_DI;
  uint *puVar27;
  uint16_t unaff_ES;
  uint16_t curSeg = _SS;
  byte in_CF;
  bool bVar29;
  bool bVar30;
  bool bVar31;
  uint *count;
  byte *pbVar32;
  int aiStack_980 [300];
  int aiStack_728 [300];
  int aiStack_4d0 [300];
  int aiStack_278 [300];
  byte bStack_1f;
  int *piStack_1e;
  uint16_t uVar33;
  int *piStack_1a;
  uint16_t uVar34;
  int *piStack_12;
  uint16_t uVar35;
  int *piStack_e;
  int iStack_a;
  int iStack_8;
  byte bVar20;
  
  uVar15 = unaff_BP - *(uint *)(unaff_DI + 0x971b);
  uVar25 = uVar15 - in_CF;
  uVar15 = (uint)(unaff_BP < *(uint *)(unaff_DI + 0x971b) || uVar15 < in_CF);
  uVar22 = in_AX - *(uint *)((int)unaff_SI + 0x6e1b);
  uVar14 = uVar22 - uVar15;
  uVar15 = (uint)(in_AX < *(uint *)((int)unaff_SI + 0x6e1b) || uVar22 < uVar15);
  uVar22 = in_DX - *(uint *)(unaff_DI + 0x1b);
  iVar21 = uVar22 - uVar15;
  uVar15 = (uint)(in_DX < *(uint *)(unaff_DI + 0x1b) || uVar22 < uVar15);
  uVar22 = uVar25 - *(uint *)(in_BX + (int)unaff_SI);
  iVar26 = uVar22 - uVar15;
  uVar15 = (uint)(uVar25 < *(uint *)(in_BX + (int)unaff_SI) || uVar22 < uVar15);
  iVar23 = (in_BX - AgntAnms[0xf].sx) - uVar15;
  uVar15 = (uint)(in_BX < (uint)AgntAnms[0xf].sx || in_BX - AgntAnms[0xf].sx < uVar15);
  bVar29 = unaff_DI < uVar14 || unaff_DI - uVar14 < uVar15;
  puVar27 = (uint *)((unaff_DI - uVar14) - uVar15);
  bVar17 = (byte)(uVar14 >> 8);
  bVar20 = (byte)((uint)iVar21 >> 8);
  bVar16 = bVar17 - bVar20;
  bVar30 = bVar17 < bVar20 || bVar16 < bVar29;
  bVar16 = bVar16 - bVar29;
  bVar19 = (byte)iVar21;
  bVar17 = bVar19 - bVar16;
  bVar29 = bVar19 < bVar16 || bVar17 < bVar30;
  uVar22 = CONCAT11(bVar20,bVar17 - bVar30);
  bVar17 = (byte)uVar14 - bVar20;
  bVar30 = (byte)uVar14 < bVar20 || bVar17 < bVar29;
  bVar20 = (byte)((uint)in_CX >> 8);
  bVar19 = bVar20 - *(byte *)(iVar26 + -0x6be6);
  bVar31 = bVar20 < *(byte *)(iVar26 + -0x6be6) || bVar19 < bVar30;
  bVar19 = bVar19 - bVar30;
  bVar24 = (byte)((uint)iVar23 >> 8);
  bVar20 = bVar24 - (char)puVar27[0xd];
  uVar14 = CONCAT11(bVar20 - bVar31,(char)iVar23);
  cVar18 = ((char)in_CX - *(char *)((int)unaff_SI + uVar14 + 0x1a)) -
           (bVar24 < (byte)puVar27[0xd] || bVar20 < bVar31);
  uVar14 = uVar14 ^ *(uint *)(iVar26 + (int)unaff_SI);
  cVar4 = (bVar17 - bVar29) + -0x1a;
  puVar1 = (uint *)(iVar26 + (int)unaff_SI);
  uVar15 = *puVar1;
  *puVar1 = *puVar1 + uVar14;
  if (CONCAT11(bVar19,cVar18) == 0) {
    pcVar2 = (char *)((int)puVar27 + uVar14 + 0x18);
    *pcVar2 = (*pcVar2 - bVar19) - CARRY2(uVar15,uVar14);
    puVar1 = (uint *)(uVar14 + (int)unaff_SI);
    iVar21 = (uVar14 & 3) - (*puVar1 & 3);
    *puVar1 = *puVar1 + (uint)(0 < iVar21) * iVar21;
  }
  uVar7 = *(uint32_t *)(uVar14 + (int)puVar27);
  iVar21 = (int)uVar7;
  count = puVar27 + 1;
  uVar25 = *puVar27;
  uVar14 = *unaff_SI;
  puVar1 = (uint *)((char *)0x2a919 + iVar26);
  uVar15 = *puVar1;
  uVar5 = *puVar1 - CONCAT11(bVar16,cVar4);
  *puVar1 = uVar5 - (uVar14 < uVar25);
  puVar1 = (uint *)((int)unaff_SI + iVar21 + 2);
  uVar14 = (uint)(uVar15 < CONCAT11(bVar16,cVar4) || uVar5 < (uVar14 < uVar25));
  puVar27 = (uint *)*puVar1;
  uVar15 = *puVar1;
  *puVar1 = (uVar15 - (int)count) - uVar14;
  puVar1 = count;
  uVar14 = (uint)(puVar27 < count || uVar15 - (int)count < uVar14);
  uVar15 = *puVar1;
  uVar25 = *puVar1 - uVar22;
  *puVar1 = uVar25 - uVar14;
  uVar15 = (uint)(uVar15 < uVar22 || uVar25 < uVar14);
  pbVar32 = (byte *)-uVar15;
  bVar17 = bVar16 - (byte)uVar7;
  bVar29 = bVar16 < (byte)uVar7 || bVar17 < (uVar15 != 0);
  bVar17 = bVar17 - (uVar15 != 0);
  pbVar3 = (byte *)((int)count + iVar21 + -0x54e8);
  bVar24 = (byte)((ulong)uVar7 >> 8);
  bVar30 = *pbVar3 < bVar24 || (byte)(*pbVar3 - bVar24) < bVar29;
  *pbVar3 = (*pbVar3 - bVar24) - bVar29;
  pbVar3 = (byte *)((int)count + (int)(uint16_t *)(SquareBottomY + 0xd) + iVar21);
  bVar16 = *pbVar3;
  bVar20 = *pbVar3 - bVar17;
  *pbVar3 = bVar20 - bVar30;
  pcVar2 = (char *)((int)count + iVar26 + 0x18);
  *pcVar2 = (*pcVar2 - bVar24) - (bVar16 < bVar17 || bVar20 < bVar30);
  lVar6 = (long)*(int *)(pbVar32 + iVar21) * 0x1863;
  bVar29 = (int)lVar6 != lVar6;
  iVar21 = (int)lVar6 + -1;
  pbVar3 = pbVar32;
  bVar16 = *pbVar3;
  bVar17 = *pbVar3;
  *pbVar3 = (bVar17 - bVar19) - bVar29;
  ((byte *)__C0_ASM_CopyRight)[0x14] =
       (((byte *)__C0_ASM_CopyRight)[0x14] - cVar18) -
       (bVar16 < bVar19 || (byte)(bVar17 - bVar19) < bVar29);
  pbVar32[iVar21] = pbVar32[iVar21] + cVar4;
  pbVar32[iVar21] = pbVar32[iVar21] + cVar4;
  pbVar32[iVar21] = pbVar32[iVar21] + cVar4;
  pbVar32[iVar21] = pbVar32[iVar21] + cVar4;
  pbVar32[iVar21] = pbVar32[iVar21] + cVar4;
  _fmemset((void *)(ulong)*(uint *)((int)(uint32_t *)&FillGrid + 2),0x6541,(uint16_t)count);
  iVar21 = 0x50 - gridX;
  iVar23 = 0x50 - gridY;
  iStack_a = 1;
  piStack_1a = (int *)CONCAT22(curSeg,aiStack_278);
  piStack_1e = (int *)CONCAT22(curSeg,aiStack_4d0);
  piStack_e = aiStack_728;
  piStack_12 = aiStack_980;
  *(undefined1 *)((int)*(uint32_t *)&FillGrid + (gridX + iVar21) * 0xa1 + gridY + iVar23) = 1;
  *piStack_1a = gridX;
  *piStack_1e = gridY;
  bStack_1f = 2;
  uVar35 = curSeg;
  while( true ) {
    piVar13 = piStack_e;
    piVar12 = piStack_12;
    piVar10 = piStack_1a;
    if (0x50 < bStack_1f) {
      return;
    }
    iVar26 = 0;
    iStack_8 = 0;
    while( true ) {
      piVar8 = piStack_1e;
      piStack_1a = (int *)piVar10;
      uVar34 = (uint16_t)((ulong)piVar10 >> 0x10);
      uVar11 = uVar34;
      uVar33 = (uint16_t)((ulong)piStack_1e >> 0x10);
      uVar9 = uVar33;
      if (iStack_a <= iStack_8) break;
      x = piStack_1a[iStack_8];
      y = piStack_1e[iStack_8];
      piStack_1e = piVar8;
      if (((*(char *)((x + iVar21) * 0xa1 + *(int *)&FillGrid + y + iVar23 + -0xa1) == '\0') &&
          (uVar15 = ovr_attact_usesSCARRY2(x,y,3,ignoreBlocked,count,pbVar32), (uVar15 & 0xff) == 0)) &&
         (iVar26 < 300)) {
        *(byte *)((x + iVar21) * 0xa1 + *(int *)&FillGrid + y + iVar23 + -0xa1) = bStack_1f;
        piStack_e[iVar26] = x + -1;
        piStack_12[iVar26] = y;
        iVar26 = iVar26 + 1;
      }
      if (((*(char *)((x + iVar21) * 0xa1 + *(int *)&FillGrid + y + iVar23 + 0xa1) == '\0') &&
          (uVar15 = ovr_attact_usesSCARRY2(x,y,1,ignoreBlocked,count,pbVar32), (uVar15 & 0xff) == 0)) &&
         (iVar26 < 300)) {
        *(byte *)((x + iVar21) * 0xa1 + *(int *)&FillGrid + y + iVar23 + 0xa1) = bStack_1f;
        piStack_e[iVar26] = x + 1;
        piStack_12[iVar26] = y;
        iVar26 = iVar26 + 1;
      }
      if (((*(char *)((int)*(uint32_t *)&FillGrid + (x + iVar21) * 0xa1 + y + iVar23 + -1) == '\0'
           ) && (uVar15 = ovr_attact_usesSCARRY2(x,y,0,ignoreBlocked,0,0), (uVar15 & 0xff) == 0)) &&
         (iVar26 < 300)) {
        *(byte *)((int)*(uint32_t *)&FillGrid + (x + iVar21) * 0xa1 + y + iVar23 + -1) = bStack_1f
        ;
        piStack_e[iVar26] = x;
        piStack_12[iVar26] = y + -1;
        iVar26 = iVar26 + 1;
      }
      if (((*(char *)((int)*(uint32_t *)&FillGrid + (x + iVar21) * 0xa1 + y + iVar23 + 1) == '\0')
          && (uVar15 = ovr_attact_usesSCARRY2(x,y,2,ignoreBlocked,0,0), (uVar15 & 0xff) == 0)) &&
         (iVar26 < 300)) {
        *(byte *)((int)*(uint32_t *)&FillGrid + (x + iVar21) * 0xa1 + y + iVar23 + 1) = bStack_1f;
        piStack_e[iVar26] = x;
        piStack_12[iVar26] = y + 1;
        iVar26 = iVar26 + 1;
      }
      iStack_8 = iStack_8 + 1;
    }
    if (iVar26 == 0) break;
    piStack_e = piStack_1a;
    piStack_1a = (int *)CONCAT22(curSeg,piVar13);
    piStack_12 = piStack_1e;
    piStack_1e = (int *)CONCAT22(uVar35,piVar12);
    bStack_1f = bStack_1f + 1;
    iStack_a = iVar26;
    curSeg = uVar11;
    uVar35 = uVar9;
  }
  return;
}


