/* ovc25_spyReportNotice - per-leader neighbour census: counts entities on
   the tile and within 10 half-cells, records the nearest enemy,
   then the nearest other leader, and finally emits the notice or spawns a
   unit near the leader.  Locals named from those assignments (leaderIdx,
   idx, enemyDist/enemyIdx, leaderX, otherIdx/otherDist, enemyDist2,
   classIdx/classValue, spawnX/spawnY, otherLeaderIdx). */
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
  char *unaff_SS;
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
      leaderX = ovr_alignUp4(((char_sheet_t *)((leaderIdx << 2)))->x);
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
               (uVar2 = ovr_alignUp4(*(int *)((int)Entities + idx * 0x37)), uVar2 == leaderX
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
                *(int *)((int)Entities + enemyIdx * 0x37);
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
              uVar4 = ovr_randBelow(0x28);
              spawnX = ((char_sheet_t *)((leaderIdx << 2)))->x + -0x14 +
                         (uVar4 & 0xff);
              if ((int)spawnX < 4) {
                spawnX = 4;
              }
              if (0x8c < (int)spawnX) {
                spawnX = 0x8b;
              }
              uVar4 = ovr_randBelow(0x14);
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
              msg = ovr_stsprintf((char *)&text,(char *)CONCAT22(0x58c0,unaff_SS),
                                  (char *)CONCAT22(*(uint16_t *)
                                                    ((int)&worldMenuLabels[0].seg + 1 + iVar7),
                                                   (char *)0x26510),
                                  *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + iVar7),uVar2);
              ovr_uiNotify(msg,uVar4);
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
          ovc25_usesAlignUp43((byte)leaderIdx,5,*(uint16_t *)((int)Entities + enemyIdx * 0x37),
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
