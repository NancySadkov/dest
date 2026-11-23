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
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint16_t uVar6;
  
  uVar1 = ovr_alignUp4(destX,0,0);
  uVar2 = ovr_alignUp4(x,0,0);
  uVar5 = 0;
  do {
    if (EntityCount <= uVar5) {
      return 0xffff;
    }
    uVar6 = (uint16_t)((ulong)Entities >> 0x10);
    iVar4 = (int)Entities;
    if ((*(char *)(iVar4 + uVar5 * 0x37 + 0x1a) == partyIndex) &&
       ((*(byte *)(iVar4 + uVar5 * 0x37 + 0x33) & 2) == 0)) {
      uVar3 = ovr_alignUp4(*(int *)((entity_t *)iVar4 + uVar5),0,0);
      uVar6 = (uint16_t)((ulong)Entities >> 0x10);
      if ((uVar3 == uVar2) && (((entity_t *)Entities)[uVar5].base.y == y)) {
        return uVar5;
      }
      uVar3 = ovr_alignUp4(((entity_t *)Entities)[uVar5].base.destX,0,0);
      if (uVar3 != uVar1) {
        return uVar5;
      }
      if (((entity_t *)Entities)[uVar5].base.destY != destY) {
        return uVar5;
      }
    }
    uVar5 = uVar5 + 1;
  } while( true );
}



/* 5b66:00ff */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

uint16_t __cdecl16far
ovc25_usesAlignUp42(char partyIndex,byte count,uint16_t destX,uint16_t destY,uint16_t x,uint16_t y)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint16_t uVar5;
  int iStack_4;
  
  uVar4 = 0;
  do {
    if (EntityCount <= uVar4) {
      if (count != 0) {
        iStack_4 = 0;
        while ((iStack_4 < (int)(uint)count &&
               (uVar4 = ovc25_usesAlignUp4(partyIndex,x,y,destX,destY), -1 < (int)uVar4))) {
          ((entity_t *)Entities)[uVar4].base.state = 0;
          ((entity_t *)Entities)[uVar4].base.destX = destX;
          ((entity_t *)Entities)[uVar4].base.destY = destY;
          pbVar1 = (byte *)((uint8_t *)((entity_t *)Entities + uVar4) + 0x33);
          *pbVar1 = *pbVar1 | 8;
          iStack_4 = iStack_4 + 1;
        }
      }
      return 0xffff;
    }
    uVar5 = (uint16_t)((ulong)Entities >> 0x10);
    if (*(char *)((int)&((entity_t *)Entities)[uVar4].base.entity + 3) == partyIndex) {
      uVar2 = ovr_alignUp4(((entity_t *)Entities)[uVar4].base.x,0,0);
      uVar3 = ovr_alignUp4(destX,0,0);
      uVar5 = (uint16_t)((ulong)Entities >> 0x10);
      if ((uVar2 != uVar3) || (((entity_t *)Entities)[uVar4].base.y != destY)) {
        uVar2 = ovr_alignUp4(((entity_t *)Entities)[uVar4].base.destX,0,0);
        uVar3 = ovr_alignUp4(destX,0,0);
        if ((uVar2 != uVar3) || (((entity_t *)Entities)[uVar4].base.destY != destY))
        goto L_OVC25_5b66_00ff_01D9;
      }
      pbVar1 = (byte *)((uint8_t *)((entity_t *)Entities + uVar4) + 0x33);
      *pbVar1 = *pbVar1 | 8;
    }
L_OVC25_5b66_00ff_01D9:
    uVar4 = uVar4 + 1;
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
  int entitiesOfs;
  uint entityIndex;
  int targetY;
  uint bestDist;
  
  bestDist = 0xffff;
  targetX = ovr_alignUp4(x,0,0);
  for (entityIndex = 0; entityIndex < EntityCount; entityIndex = entityIndex + 1) {
    if (*(char *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3) == (char)partyIndex) {
      dist = ovr_alignUp4(((entity_t *)Entities)[entityIndex].base.x,0,0);
      signMaskX = (int)(dist - targetX) >> 0xf;
      entitiesOfs = (int)Entities;
      dy = ((entity_t *)entitiesOfs)[entityIndex].base.y - targetY;
      signMaskY = (int)dy >> 0xf;
      dist = ((dist - targetX ^ signMaskX) - signMaskX) + ((dy ^ signMaskY) - signMaskY) * 2;
      if ((((dist != 0) && (dist < bestDist)) &&
          ((*(byte *)(entitiesOfs + entityIndex * 0x37 + 0x33) & 2) == 0)) &&
         ((includeFlag8 != '\0' || ((*(byte *)(entitiesOfs + entityIndex * 0x37 + 0x33) & 8) == 0)))) {
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
      if (*(char *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3) == partyIndex) {
        uVar3 = ovr_alignUp4(((entity_t *)Entities)[entityIndex].base.x,0,0);
        uVar4 = ovr_alignUp4(destX,0,0);
        uVar6 = (uint16_t)((ulong)Entities >> 0x10);
        if ((uVar3 != uVar4) || (((entity_t *)Entities)[entityIndex].base.y != destY))
        {
          uVar3 = ovr_alignUp4(((entity_t *)Entities)[entityIndex].base.destX,0,0);
          uVar4 = ovr_alignUp4(destX,0,0);
          if ((uVar3 != uVar4) ||
             (((entity_t *)Entities)[entityIndex].base.destY != destY))
          goto L_OVC25_5b66_038d_0482;
        }
        iVar5 = iVar5 + 1;
        if (setFlag8 != '\0') {
          pbVar1 = (byte *)((uint8_t *)((entity_t *)Entities + entityIndex) + 0x33);
          *pbVar1 = *pbVar1 | 8;
        }
      }
L_OVC25_5b66_038d_0482:
    }
    while ((iVar5 < (int)(uint)count &&
           (bVar2 = ovc25_textArena((uint *)CONCAT22(curSeg,&entityIndex),setFlag8,
                                    (uint)(byte)partyIndex,destX), bVar2))) {
      ((entity_t *)Entities)[entityIndex].base.state = 0;
      ((entity_t *)Entities)[entityIndex].base.destX = destX;
      ((entity_t *)Entities)[entityIndex].base.destY = destY;
      if (setFlag8 != '\0') {
        pbVar1 = (byte *)((uint8_t *)((entity_t *)Entities + entityIndex) + 0x33);
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
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint16_t uVar5;
  uint16_t curSeg = _SS;
  uint8_t entityIndex;
  
  if (count != 0) {
    iVar4 = 0;
    for (entityIndex = 0; entityIndex < EntityCount; entityIndex = entityIndex + 1) {
      uVar5 = (uint16_t)((ulong)Entities >> 0x10);
      if (*(char *)((int)&((entity_t *)Entities)[entityIndex].base.entity + 3) == partyIndex) {
        uVar2 = ovr_alignUp4(((entity_t *)Entities)[entityIndex].base.destX,0,0);
        uVar3 = ovr_alignUp4(destX,0,0);
        if ((uVar2 == uVar3) && (((entity_t *)Entities)[entityIndex].base.destY == destY))
        {
          iVar4 = iVar4 + 1;
        }
      }
    }
    while ((iVar4 < (int)(uint)count &&
           (bVar1 = ovc25_textArena((uint *)CONCAT22(curSeg,&entityIndex),'\x02',
                                    (uint)(byte)partyIndex,destX), bVar1))) {
      ((entity_t *)Entities)[entityIndex].base.state = 0;
      ((entity_t *)Entities)[entityIndex].base.destX = destX;
      ((entity_t *)Entities)[entityIndex].base.destY = destY;
      iVar4 = iVar4 + 1;
    }
    while ((iVar4 < (int)(uint)count &&
           (bVar1 = ovc25_textArena((uint *)CONCAT22(curSeg,&entityIndex),'\x01',
                                    (uint)(byte)partyIndex,destX), bVar1))) {
      ((entity_t *)Entities)[entityIndex].base.state = 0;
      ((entity_t *)Entities)[entityIndex].base.destX = destX;
      ((entity_t *)Entities)[entityIndex].base.destY = destY;
      iVar4 = iVar4 + 1;
    }
    while ((iVar4 < (int)(uint)count &&
           (bVar1 = ovc25_textArena((uint *)CONCAT22(curSeg,&entityIndex),'\0',
                                    (uint)(byte)partyIndex,destX), bVar1))) {
      ((entity_t *)Entities)[entityIndex].base.state = 0;
      ((entity_t *)Entities)[entityIndex].base.destX = destX;
      ((entity_t *)Entities)[entityIndex].base.destY = destY;
      iVar4 = iVar4 + 1;
    }
  }
  return;
}



/* 5b66:0722 */

/* Searches square rings out to 99 cells for a cell occupied by a unit (attact_usesGUnits), writing
   the found coordinates through the two pointers. */

uint __cdecl16far ovc25_findUnitCell(int *x,uint *y)

{
  int iVar1;
  uint uVar2;
  uint16_t uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int *in_stack_00000004;
  char cStack_a;
  byte bStack_9;
  uint uStack_8;
  
  iVar1 = *(int *)CONCAT22((int *)x,in_stack_00000004);
  uVar2 = *(uint *)CONCAT22((uint *)y,(*(uint16_t *)((uint8_t *)&(x) + 2)));
  uStack_8 = 0;
  uVar4 = uVar2;
  do {
    if (99 < uStack_8) {
      return uVar4 & 0xff00;
    }
    for (uVar6 = 0; uVar6 <= uStack_8; uVar6 = uVar6 + 1) {
      for (uVar5 = 0; uVar5 <= uStack_8; uVar5 = uVar5 + 1) {
        bStack_9 = 0xff;
        while ((0x7f < bStack_9 || ((uVar6 != 0 && ((char)bStack_9 < '\x02'))))) {
          cStack_a = -1;
          while ((cStack_a < '\0' || ((uVar5 != 0 && (cStack_a < '\x02'))))) {
            uVar3 = ovr_attact_usesGUnits
                              (iVar1 + uVar6 * (int)cStack_a,uVar2 + uVar5 * (int)cStack_a);
            if ((char)uVar3 != '\0') {
              *(uint *)CONCAT22((int *)x,in_stack_00000004) = iVar1 + uVar6 * (int)cStack_a;
              *(uint *)CONCAT22((uint *)y,(*(uint16_t *)((uint8_t *)&(x) + 2))) = uVar2 + uVar5 * (int)cStack_a;
              return CONCAT11((char)(uVar5 * (int)cStack_a >> 8),1);
            }
            cStack_a = cStack_a + '\x02';
            uVar4 = CONCAT11((char)((uint)uVar3 >> 8),cStack_a);
          }
          bStack_9 = bStack_9 + 2;
          uVar4 = CONCAT11((char)(uVar4 >> 8),bStack_9);
        }
      }
    }
    uStack_8 = uStack_8 + 1;
  } while( true );
}



/* 5b66:080f */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches EntityCount, Entities */

void __cdecl16far ovc25_usesEntityCount(char partyIndex)

{
  byte *pbVar1;
  uint uVar2;
  uint16_t uVar3;
  
  for (uVar2 = 0; uVar2 < EntityCount; uVar2 = uVar2 + 1) {
    uVar3 = (uint16_t)((ulong)Entities >> 0x10);
    if (*(char *)((int)&((entity_t *)Entities)[uVar2].base.entity + 3) == partyIndex) {
      pbVar1 = (byte *)((uint8_t *)((entity_t *)Entities + uVar2) + 0x33);
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
  int *piVar1;
  uint uVar2;
  uint uVar3;
  char *msg;
  uint16_t uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint enemyIdx;
  uint16_t uVar8;
  uint16_t curSeg = _SS;
  uint8_t text;
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
    if (((char_sheet_t *)((leaderIdx << 2)))->active != '\0') {
      ((char_sheet_t *)((leaderIdx << 2)))->unitsOnTile = 0;
      ((char_sheet_t *)((leaderIdx << 2)))->unitsNear = 0;
      ((char_sheet_t *)((leaderIdx << 2)))->enemiesNear = 0;
      ((char_sheet_t *)((leaderIdx << 2)))->unitCount = 0;
      enemyDist = 0xffff;
      enemyIdx = 0xffff;
      leaderX = ovr_alignUp4(((char_sheet_t *)((leaderIdx << 2)))->x,0,0);
      for (idx = 0; idx < EntityCount; idx = idx + 1) {
        uVar8 = (uint16_t)((ulong)Entities >> 0x10);
        iVar7 = (int)Entities;
        if (*(byte *)(iVar7 + idx * 0x37 + 0x1a) == leaderIdx) {
          uVar2 = ((char_sheet_t *)((leaderIdx << 2)))->x -
                  *(int *)((entity_t *)iVar7 + idx);
          uVar5 = (int)uVar2 >> 0xf;
          uVar3 = ((char_sheet_t *)((leaderIdx << 2)))->y -
                  ((entity_t *)iVar7)[idx].base.y;
          uVar6 = (int)uVar3 >> 0xf;
          piVar1 = (int *)((int)*(uint32_t *)(leaderIdx << 2) + 0x45);
          *piVar1 = *piVar1 + 1;
          if ((int)((uVar2 ^ uVar5) - uVar5) / 2 + ((uVar3 ^ uVar6) - uVar6) < 10) {
            piVar1 = (int *)((int)*(uint32_t *)(leaderIdx << 2) + 0x41);
            *piVar1 = *piVar1 + 1;
            uVar8 = (uint16_t)((ulong)Entities >> 0x10);
            if ((((char_sheet_t *)((leaderIdx << 2)))->y ==
                 ((entity_t *)Entities)[idx].base.y) &&
               (uVar2 = ovr_alignUp4(((entity_t *)Entities)[idx].base.x,0,0), uVar2 == leaderX
               )) {
              piVar1 = (int *)((int)*(uint32_t *)(leaderIdx << 2) + 0x47);
              *piVar1 = *piVar1 + 1;
            }
          }
        }
        else if (*(char *)((int)(char **)GMenuStrings +
                          (uint)((entity_t *)iVar7)[idx].base.gindex * 0x95 + 0x1f) !=
                 *(char *)((int)*(uint32_t *)(leaderIdx << 2) + 0x3f)) {
          uVar2 = ((char_sheet_t *)((leaderIdx << 2)))->x -
                  *(int *)((entity_t *)iVar7 + idx);
          uVar5 = (int)uVar2 >> 0xf;
          uVar3 = ((char_sheet_t *)((leaderIdx << 2)))->y -
                  ((entity_t *)iVar7)[idx].base.y;
          uVar6 = (int)uVar3 >> 0xf;
          uVar2 = (int)((uVar2 ^ uVar5) - uVar5) / 2 + ((uVar3 ^ uVar6) - uVar6);
          if (uVar2 < enemyDist) {
            enemyIdx = idx;
            enemyDist = uVar2;
          }
          if (uVar2 < 10) {
            piVar1 = (int *)((int)*(uint32_t *)(leaderIdx << 2) + 0x43);
            *piVar1 = *piVar1 + 1;
          }
        }
      }
      ((char_sheet_t *)((leaderIdx << 2)))->nearestEnemy = enemyIdx;
      otherIdx = 0xff;
      if (*(char *)((int)*(uint32_t *)(leaderIdx << 2) + 0x40) != '\0') {
        otherDist = 0xffff;
        for (idx = 0; (int)idx < (int)(uint)GLeaderCount; idx = idx + 1) {
          if ((*(char *)((int)*(uint32_t *)(idx << 2) + 0x3f) !=
               *(char *)((int)*(uint32_t *)(leaderIdx << 2) + 0x3f)) &&
             (uVar2 = ((char_sheet_t *)((leaderIdx << 2)))->x -
                      ((char_sheet_t *)((idx << 2)))->x,
             uVar5 = (int)uVar2 >> 0xf,
             uVar3 = ((char_sheet_t *)((leaderIdx << 2)))->y -
                     ((char_sheet_t *)((idx << 2)))->y, uVar6 = (int)uVar3 >> 0xf
             , uVar2 = (int)((uVar2 ^ uVar5) - uVar5) / 2 + ((uVar3 ^ uVar6) - uVar6),
             uVar2 < otherDist)) {
            otherIdx = (undefined1)idx;
            otherDist = uVar2;
          }
        }
      }
      *(undefined1 *)((int)*(uint32_t *)(leaderIdx << 2) + 0x49) = otherIdx;
    }
  }
  for (leaderIdx = 0; (int)leaderIdx < (int)(uint)GLeaderCount; leaderIdx = leaderIdx + 1) {
    if ((*(char *)((int)*(uint32_t *)(leaderIdx << 2) + 0x40) != '\0') &&
       (((char_sheet_t *)((leaderIdx << 2)))->active != '\0')) {
      ovc25_intelAttackingNotice((byte)leaderIdx);
      if (((char_sheet_t *)((leaderIdx << 2)))->nearestEnemy == -1) {
        enemyDist2 = 0xffff;
      }
      else {
        enemyIdx = ((char_sheet_t *)((leaderIdx << 2)))->nearestEnemy;
        uVar8 = (uint16_t)((ulong)Entities >> 0x10);
        uVar2 = ((char_sheet_t *)((leaderIdx << 2)))->x -
                ((entity_t *)Entities)[enemyIdx].base.x;
        uVar5 = (int)uVar2 >> 0xf;
        uVar3 = ((char_sheet_t *)((leaderIdx << 2)))->y -
                ((entity_t *)Entities)[enemyIdx].base.y;
        uVar6 = (int)uVar3 >> 0xf;
        enemyDist2 = (int)((uVar2 ^ uVar5) - uVar5) / 2 + ((uVar3 ^ uVar6) - uVar6);
      }
      if ((((char_sheet_t *)((leaderIdx << 2)))->enemiesNear == 0) || (9 < enemyDist2)) {
        if ((*(char *)((int)*(uint32_t *)(leaderIdx << 2) + 0x49) == -1) ||
           ((((char_sheet_t *)((leaderIdx << 2)))->flags5d & 1) == 0)) {
          if (((char_sheet_t *)((leaderIdx << 2)))->unitsOnTile < 10) {
            ovc25_usesAlignUp43((byte)leaderIdx,10,
                                ((char_sheet_t *)((leaderIdx << 2)))->x,
                                ((char_sheet_t *)((leaderIdx << 2)))->y,'\0');
            ((char_sheet_t *)((leaderIdx << 2)))->reportState = 0;
          }
          else {
            ((char_sheet_t *)((leaderIdx << 2)))->reportState = 0;
            classIdx = ((char_sheet_t *)((leaderIdx << 2)))->classStr;
            classValue = ovc25_compute1(classIdx);
            if ((int)(uint)PlayerCount < classValue) {
              uVar4 = ovr_randBelow(0x28,0);
              spawnX = ((char_sheet_t *)((leaderIdx << 2)))->x + -0x14 +
                         (uVar4 & 0xff);
              if ((int)spawnX < 4) {
                spawnX = 4;
              }
              if (0x8c < (int)spawnX) {
                spawnX = 0x8b;
              }
              uVar4 = ovr_randBelow(0x14,0);
              spawnY = ((char_sheet_t *)((leaderIdx << 2)))->y + -10 + (uVar4 & 0xff)
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
          otherLeaderIdx = *(byte *)((int)*(uint32_t *)(leaderIdx << 2) + 0x49);
          if (0xe < ((char_sheet_t *)((leaderIdx << 2)))->unitsOnTile) {
            ovc25_usesAlignUp42((byte)leaderIdx,10,
                                ((char_sheet_t *)(((uint)otherLeaderIdx << 2)))->x,
                                ((char_sheet_t *)(((uint)otherLeaderIdx << 2)))->y,
                                ((char_sheet_t *)((leaderIdx << 2)))->x,
                                ((char_sheet_t *)((leaderIdx << 2)))->y);
            if (((char_sheet_t *)((leaderIdx << 2)))->reportState != '\x02') {
              uVar2 = ovr_alignUp4(((char_sheet_t *)(((uint)otherLeaderIdx << 2)))->x,
                                   ((char_sheet_t *)(((uint)otherLeaderIdx << 2)))->y,0xa000);
              iVar7 = (uint)((char_sheet_t *)((leaderIdx << 2)))->classStr * 0x95;
              uVar4 = 0x195d;
              msg = ovr_stsprintf((char *)&text,(char *)CONCAT22(0x58c0,curSeg),
                                  (char *)CONCAT22(*(uint16_t *)
                                                    ((int)&worldMenuLabels[0].seg + 1 + iVar7),
                                                   (char *)0x26510),
                                  *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + iVar7),uVar2);
              ovr_uiNotify(msg,uVar4,0);
            }
          }
          ovc25_usesAlignUp43((byte)leaderIdx,0xf,
                              ((char_sheet_t *)((leaderIdx << 2)))->x,
                              ((char_sheet_t *)((leaderIdx << 2)))->y,'\0');
          ((char_sheet_t *)((leaderIdx << 2)))->reportState = 2;
        }
      }
      else {
        ovc25_usesEntityCount((byte)leaderIdx);
        if (9 < ((char_sheet_t *)((leaderIdx << 2)))->unitsOnTile) {
          uVar8 = (uint16_t)((ulong)Entities >> 0x10);
          ovc25_usesAlignUp43((byte)leaderIdx,5,((entity_t *)Entities)[enemyIdx].base.x,
                              ((entity_t *)Entities)[enemyIdx].base.y,'\x01');
        }
        ovc25_usesAlignUp43((byte)leaderIdx,10,
                            ((char_sheet_t *)((leaderIdx << 2)))->x,
                            ((char_sheet_t *)((leaderIdx << 2)))->y,'\0');
        ((char_sheet_t *)((leaderIdx << 2)))->reportState = 1;
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
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = ovr_alignUp4(x,0,0);
  uVar4 = uVar3 + 3;
  if (((((int)uVar4 < 0x94) && (-1 < (int)uVar3)) && (y < 0x3c)) && (-1 < y)) {
    for (iVar5 = -2; iVar5 < 2; iVar5 = iVar5 + 1) {
      iVar2 = (*(short (*) [148] [60])GUnitGrid)[uVar3 + iVar5][y];
      bVar1 = ((unit_t *)GUnits + iVar2)->bldType;
      uVar4 = CONCAT11((char)((uint)(iVar2 * 9) >> 8),bVar1);
      if ((bVar1 < 0xf8) && (uVar4 = (uint)bVar1 * 0x27, *(char *)(uVar4 + 0x11a) != '\0')) {
        return CONCAT11((char)(uVar4 >> 8),1);
      }
    }
  }
  return uVar4 & 0xff00;
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
    if ((((*((uint8_t far *)&((entity_t *)Entities)[uVar3].base.flags32 + 1) & 2) != 0) &&
        (uVar2 = ovr_alignUp4(((entity_t *)Entities)[uVar3].base.targetX,0,0), uVar2 == uVar1)) &&
       (((entity_t *)Entities)[uVar3].base.targetY == y)) {
      *(undefined1 *)CONCAT22((uint8_t *)foundFlag,in_stack_0000000a) = 1;
    }
    uVar2 = ovr_alignUp4(((entity_t *)Entities)[uVar3].base.x,0,0);
    if (uVar2 == uVar1) {
      uVar4 = (uint16_t)((ulong)Entities >> 0x10);
      if (((entity_t *)Entities)[uVar3].base.y == y) {
        if (*(char *)((int)(char **)GMenuStrings +
                     (uint)((entity_t *)Entities)[uVar3].base.gindex * 0x95 + 0x1f) != excluded
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
    AGNT_FIELD(&((entity_t *)Entities)[uStack_6], base.entity, 2) = 0;
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
  uint32_t uVar1;
  uint uVar2;
  uint uVar3;
  uint16_t uVar4;
  int iVar5;
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
       *(undefined1 *)((int)(char **)GMenuStrings + (uint)*(byte *)(unaff_BP + -0xb) * 0x95 + 0x1f);
  uVar7 = (uint16_t)((ulong)Entities >> 0x10);
  if ((*(char *)((int)Entities + *(int *)(unaff_BP + -4) * 0x37 + 0x18) != '\0') ||
     (*(char *)(unaff_BP + -0xd) != '\0')) {
    if (*(char *)(unaff_BP + -0xd) == '\0') {
      OVC25_5b66_131f_entry();
      return;
    }
    uVar1 = *(uint32_t *)((uint)*(byte *)(unaff_BP + -0xc) << 2);
    if (*(char *)((int)uVar1 + 0x4a) != '\0') {
      OVC25_5b66_131f_entry();
      return;
    }
  }
  uVar2 = ovr_alignUp4(*(int *)((int)Entities + *(int *)(unaff_BP + -4) * 0x37),0,0);
  *(uint *)(unaff_BP + -6) = uVar2;
  uVar7 = (uint16_t)((ulong)Entities >> 0x10);
  iVar5 = (int)Entities;
  if (((*(int *)(iVar5 + *(int *)(unaff_BP + -4) * 0x37 + 8) == 0) &&
      (*(int *)(iVar5 + *(int *)(unaff_BP + -4) * 0x37 + 10) == 0)) &&
     ((*(byte *)(iVar5 + *(int *)(unaff_BP + -4) * 0x37 + 0x33) & 3) == 0)) {
    uVar2 = *(uint *)(unaff_BP + -4);
  }
  else {
    uVar2 = 0xffff;
  }
  *(uint16_t *)(unaff_BP + -0x10) = 1;
  uVar6 = *(uint *)(unaff_BP + -4);
  while (uVar6 = uVar6 + 1, uVar6 < EntityCount) {
    uVar3 = ovr_alignUp4(((entity_t *)Entities)[uVar6].base.x,0,0);
    if (uVar3 == *(uint *)(unaff_BP + -6)) {
      uVar7 = (uint16_t)((ulong)Entities >> 0x10);
      iVar5 = (int)Entities;
      if (((entity_t *)iVar5)[uVar6].base.y == *(int *)(iVar5 + *(int *)(unaff_BP + -4) * 0x37 + 2)
         ) {
        *(undefined1 *)(iVar5 + uVar6 * 0x37 + 0x19) = 1;
        uVar7 = (uint16_t)((ulong)Entities >> 0x10);
        iVar5 = (int)Entities;
        if (((((entity_t *)iVar5)[uVar6].base.destX == 0) && (((entity_t *)iVar5)[uVar6].base.destY == 0)
            ) && ((*(char *)(iVar5 + uVar6 * 0x37 + 0x18) == '\0' &&
                  ((*(char *)((int)(char **)GMenuStrings +
                             (uint)((entity_t *)iVar5)[uVar6].base.gindex * 0x95 + 0x1f) ==
                    *(char *)(unaff_BP + -0xd) &&
                   (*(int *)(unaff_BP + -0x10) = *(int *)(unaff_BP + -0x10) + 1,
                   (*((uint8_t far *)&((entity_t *)Entities)[uVar6].base.flags32 + 1) & 3) == 0)))))) {
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
  uVar4 = ovr_randBelow(4,0);
  *(undefined1 *)(unaff_BP + -9) = (char)uVar4;
  *(undefined1 *)(unaff_BP + -10) = *(undefined1 *)(unaff_BP + -9);
  uVar6 = ovr_alignUp4(((entity_t *)Entities)[uVar2].base.x +
                       *(char *)(*(byte *)(unaff_BP + -9) + 0x885) * 4,0,0);
  *(uint *)(unaff_BP + -6) = uVar6;
  *(int *)(unaff_BP + -8) =
       ((entity_t *)Entities)[uVar2].base.y +
       (int)*(char *)(*(byte *)(unaff_BP + -9) + 0x889);
  uVar7 = ovr_attact_usesGUnits(*(int *)(unaff_BP + -6),*(int *)(unaff_BP + -8));
  if ((char)uVar7 != '\0') {
    iVar5 = ovc25_usesAlignUp46(*(uint16_t *)(unaff_BP + -6),*(uint16_t *)(unaff_BP + -8),
                                *(char *)(unaff_BP + -0xd),
                                (uint8_t *)CONCAT22(in_stack_00000000,curSeg));
    *(int *)(unaff_BP + -2) = iVar5;
    if (*(uint *)(unaff_BP + -0x10) <= *(uint *)(unaff_BP + -2)) {
      OVC25_5b66_131f_entry();
      return;
    }
    ((entity_t *)Entities)[uVar2].base.destX = *(uint16_t *)(unaff_BP + -6);
    ((entity_t *)Entities)[uVar2].base.destY = *(uint16_t *)(unaff_BP + -8);
    if ((*(char *)(unaff_BP + -0xd) == '\0') && (*(char *)(unaff_BP + -0xe) == '\0')) {
      ((entity_t *)Entities)[uVar2].base.targetX = *(uint16_t *)(unaff_BP + -6);
      ((entity_t *)Entities)[uVar2].base.targetY = *(uint16_t *)(unaff_BP + -8);
      AGNT_FIELD(&((entity_t *)Entities)[uVar2], base.flags32, 1) = 2;
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
  ((entity_t *)Entities)[unaff_DI].base.destX = *(uint16_t *)(unaff_BP + -6);
  ((entity_t *)Entities)[unaff_DI].base.destY = *(uint16_t *)(unaff_BP + -8);
  if ((*(char *)(unaff_BP + -0xd) == '\0') && (*(char *)(unaff_BP + -0xe) == '\0')) {
    ((entity_t *)Entities)[unaff_DI].base.targetX = *(uint16_t *)(unaff_BP + -6);
    ((entity_t *)Entities)[unaff_DI].base.targetY = *(uint16_t *)(unaff_BP + -8);
    AGNT_FIELD(&((entity_t *)Entities)[unaff_DI], base.flags32, 1) = 2;
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
  uint uVar1;
  uint16_t uVar2;
  int iVar3;
  int unaff_BP;
  int unaff_DI;
  uint16_t curSeg = _SS;
  uint16_t in_stack_00000000;
  
  *(byte *)(unaff_BP + -9) = *(char *)(unaff_BP + -9) + 1U & 3;
  if (*(char *)(unaff_BP + -9) != *(char *)(unaff_BP + -10)) {
    uVar1 = ovr_alignUp4(((entity_t *)Entities)[unaff_DI].base.x +
                         *(char *)(*(byte *)(unaff_BP + -9) + 0x885) * 4,0,0);
    *(uint *)(unaff_BP + -6) = uVar1;
    *(int *)(unaff_BP + -8) =
         ((entity_t *)Entities)[unaff_DI].base.y +
         (int)*(char *)(*(byte *)(unaff_BP + -9) + 0x889);
    uVar2 = ovr_attact_usesGUnits(*(int *)(unaff_BP + -6),*(int *)(unaff_BP + -8));
    if ((char)uVar2 == '\0') {
      ovc25_usesAlignUp48();
      return;
    }
    iVar3 = ovc25_usesAlignUp46(*(uint16_t *)(unaff_BP + -6),*(uint16_t *)(unaff_BP + -8),
                                *(char *)(unaff_BP + -0xd),
                                (uint8_t *)CONCAT22(in_stack_00000000,curSeg));
    *(int *)(unaff_BP + -2) = iVar3;
    if (*(uint *)(unaff_BP + -0x10) <= *(uint *)(unaff_BP + -2)) {
      OVC25_5b66_131f_entry();
      return;
    }
    ((entity_t *)Entities)[unaff_DI].base.destX = *(uint16_t *)(unaff_BP + -6);
    ((entity_t *)Entities)[unaff_DI].base.destY = *(uint16_t *)(unaff_BP + -8);
    if ((*(char *)(unaff_BP + -0xd) == '\0') && (*(char *)(unaff_BP + -0xe) == '\0')) {
      ((entity_t *)Entities)[unaff_DI].base.targetX = *(uint16_t *)(unaff_BP + -6);
      ((entity_t *)Entities)[unaff_DI].base.targetY = *(uint16_t *)(unaff_BP + -8);
      AGNT_FIELD(&((entity_t *)Entities)[unaff_DI], base.flags32, 1) = 2;
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
  byte *pbVar1;
  uint16_t uVar2;
  uint8_t *puVar3;
  char *msg;
  uint uVar4;
  uint16_t curSeg = _SS;
  uint8_t text;
  byte bStack_3;
  
  if (((partyIndex != 0xff) &&
      (*(char *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x3f) != '\0')) &&
     (*(int *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x5e) == 0)) {
    bStack_3 = ((char_sheet_t *)(((uint)partyIndex << 2)))->classStr;
    uVar4 = (uint)*(byte *)((int)&worldMenuLabels[8].seg + (uint)bStack_3 * 0x95) +
            (uint)*(byte *)((int)&worldMenuLabels[8].ofs + 1 + (uint)bStack_3 * 0x95) +
            (uint)*(byte *)((int)&worldMenuLabels[8].seg + 1 + (uint)bStack_3 * 0x95);
    if (((uVar4 < PlayerCount) &&
        ((((char_sheet_t *)(((uint)partyIndex << 2)))->flags5d & 1) == 0)) &&
       (uVar2 = ovr_randBelow(100,0), (int)(uVar2 & 0xff) < (int)(PlayerCount - uVar4))) {
      *(uint16_t *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x5e) = 0x19;
      ovr_play_sfx(82,0,0);
      uVar2 = 0x217a;
      puVar3 = ovr_ovc15_usesStshRealloc
                         ((char *)*(uint16_t *)((uint)partyIndex * 4),((uint16_t *)((uint)partyIndex * 4))[1],GSavedBlitSeg,0,0,0,0,0);
      msg = ovr_stsprintf((char *)&text,(char *)CONCAT22(0x58f5,curSeg),
                          (char *)CONCAT22(puVar3,(char *)0x26510),uVar2);
      ovr_uiNotify(msg,uVar2,0);
      pbVar1 = (byte *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x5d);
      *pbVar1 = *pbVar1 | 1;
    }
  }
  return;
}



/* 5b66:18cc */

/* [R7] body shape: compute */

int __cdecl16far ovc25_compute1(byte gindex)

{
  return (uint)*(byte *)((int)&worldMenuLabels[8].seg + (uint)gindex * 0x95) +
         (uint)*(byte *)((int)&worldMenuLabels[8].ofs + 1 + (uint)gindex * 0x95) +
         (uint)*(byte *)((int)&worldMenuLabels[8].seg + 1 + (uint)gindex * 0x95);
}



/* 5b66:1929 */

/* Emits the "Intelligence reports %s attacking." notice for a party. */

void __cdecl16far ovc25_intelAttackingNotice(byte partyIndex)

{
  byte *pbVar1;
  char cVar2;
  uint16_t uVar3;
  uint8_t *puVar4;
  char *msg;
  uint16_t curSeg = _SS;
  uint8_t text;
  byte bStack_5;
  int iStack_4;
  
  iStack_4 = ovc25_compute1(((char_sheet_t *)(((uint)partyIndex << 2)))->classStr);
  if ((((((iStack_4 < (int)(uint)PlayerCount) &&
         (*(int *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x5e) == 0)) &&
        (*(char *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x40) != '\0')) &&
       (((((char_sheet_t *)(((uint)partyIndex << 2)))->flags5d & 1) == 0 &&
        (9 < ((char_sheet_t *)(((uint)partyIndex << 2)))->unitCount)))) &&
      ((*(char *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x49) != -1 &&
       ((bStack_5 = *(byte *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x49),
        ((char_sheet_t *)(((uint)bStack_5 << 2)))->unitCount < 0x50 ||
        (uVar3 = ovr_randBelow(0x28,0), (char)uVar3 == '\0')))))) &&
     (8 < ((agnt_t *)(((uint)partyIndex << 2)))->teamCode)) {
    if (((char_sheet_t *)(((uint)bStack_5 << 2)))->unitCount < 0x28) {
      if (((char_sheet_t *)(((uint)bStack_5 << 2)))->unitCount < 0x14) {
        return;
      }
      uVar3 = ovr_randBelow(0x78,0);
      cVar2 = (char)uVar3;
    }
    else {
      uVar3 = ovr_randBelow(0x50,0);
      cVar2 = (char)uVar3;
    }
    if (cVar2 == '\0') {
      ovr_play_sfx(82,0,0);
      *(uint16_t *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x5e) = 0x19;
      uVar3 = 0x217a;
      puVar4 = ovr_ovc15_usesStshRealloc
                         ((char *)*(uint16_t *)((uint)partyIndex * 4),((uint16_t *)((uint)partyIndex * 4))[1],GSavedBlitSeg,0,0,0,0,0);
      msg = ovr_stsprintf((char *)&text,(char *)CONCAT22(0x5906,curSeg),
                          (char *)CONCAT22(puVar4,(char *)0x26510),uVar3);
      ovr_uiNotify(msg,uVar3,0);
      pbVar1 = (byte *)((int)*(uint32_t *)((uint)partyIndex << 2) + 0x5d);
      *pbVar1 = *pbVar1 | 1;
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
  
  if ((((*(char *)((int)*(uint32_t *)(partyIndex << 2) + 0x3f) != '\0') &&
       (*(int *)((int)*(uint32_t *)(partyIndex << 2) + 0x5e) != 0)) &&
      (piVar1 = (int *)((int)*(uint32_t *)(partyIndex << 2) + 0x5e), *piVar1 = *piVar1 + -1,
      (((char_sheet_t *)((partyIndex << 2)))->flags5d & 1) != 0)) &&
     (*(int *)((int)*(uint32_t *)(partyIndex << 2) + 0x5e) == 0)) {
    *(uint16_t *)((int)*(uint32_t *)(partyIndex << 2) + 0x5e) = 10;
    pbVar2 = (byte *)((int)*(uint32_t *)(partyIndex << 2) + 0x5d);
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
  uint16_t uVar28;
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
  uVar28 = (uint16_t)((ulong)uVar7 >> 0x10);
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


