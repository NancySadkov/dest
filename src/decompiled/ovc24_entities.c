/*
 * ovc24_entities.c - recovered from STRONG.EXE
 * memory block: OVC24_entities.c
 * range: 5943:000e - 5943:222f
 * functions: 10
 */
#include "recovered.h"


/* 5943:000e */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls alignUp4 */

void __cdecl16far ovc24_usesAlignUp4(void)

{
  /* Re-derived.  Clears the shared-cell flag on every entity, then flags each pair of
     entities that share alignUp4(x) and y but whose AgntGs[gindex].ai values differ. */
  char aiType;
  uint entAlignedX;
  uint otherAlignedX;
  int j;
  int entY;
  uint i;

  for (i = 0; i < EntityCount; i = i + 1) {
    AGNT_FIELD(&(Entities)[i], base.entity, 1) = 0;
  }
  i = 0;
  do {
    if (EntityCount <= i) {
      return;
    }
    if (AGNT_FIELD(&(Entities)[i], base.entity, 1) == '\0') {
      aiType = AgntGs[(uint)((entity_t far *)Entities)[i].base.gindex].ai;
      entAlignedX = alignUp4(*(int *)((entity_t far *)Entities + i),0,0);
      entY = (Entities)[i].base.y;
      for (j = 0; j < EntityCount; j = j + 1) {
        if (((((entity_t far *)Entities)[j].base.y == entY) &&
            (AgntGs[(uint)((entity_t far *)Entities)[j].base.gindex].ai != aiType)) &&
           (otherAlignedX = alignUp4(*(int *)((entity_t far *)Entities + j),0,0),
            otherAlignedX == entAlignedX)) {
          AGNT_FIELD(&(Entities)[i], base.entity, 1) = 1;
          AGNT_FIELD(&(Entities)[j], base.entity, 1) = 1;
          break;
        }
      }
    }
    i = i + 1;
  } while( true );
}



/* 5943:0196 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches Entities */

char __cdecl16far ovc24_usesEntities(int entityIndex)

{
  byte rankBonus;
  char statResult;
  entity_t *peVar3;
  uint16_t entitiesSeg;
  char cStack_3;
  
  rankBonus = ovr_agnt_compute8(&Entities[entityIndex].base,DAT_2000_d190);
  entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
  peVar3 = Entities;
  cStack_3 = peVar3[entityIndex].base.level + rankBonus +
             AgntGs[(uint)peVar3[entityIndex].base.gindex].rank +
             AgntGs[(uint)peVar3[entityIndex].base.gindex].shortName[1] + '\t';
  statResult = ovr_stats_compute4(&peVar3[entityIndex].base,entitiesSeg);
  cStack_3 = cStack_3 - statResult;
  if (cStack_3 < '\0') {
    cStack_3 = '\0';
  }
  return cStack_3;
}



/* 5943:026e */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R2] string "kill 3\r" */

void __cdecl16far ovc24_textKill(uint entityIndex)

{
  uint *puVar1;
  int *piVar2;
  uint8_t *puVar3;
  byte agentAI;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  long *plVar8;
  uint16_t randPick;
  uint16_t randPickB;
  uint16_t randPick2;
  int gOfs;
  char *msg;
  uint16_t startY;
  entity_t *peVar15;
  uint16_t unaff_SI;
  uint entityIndex_00;
  uint uVar16;
  uint16_t unaff_DI;
  uint16_t entitiesSeg;
  undefined1 timerB0;
  undefined1 timerB0c;
  byte gindex;
  undefined1 timerB1;
  undefined1 timerB1c;
  undefined1 timerB2;
  undefined1 timerB2c;
  uint8_t *puVar25;
  byte *pbVar26;
  undefined1 timerB3;
  undefined1 timerB3c;
  uint32_t in_stack_0000ffd0;
  long lVar29;
  uint32_t factionTimer[2];   /* [BP-0x2a]: two 32-bit per-faction timers */
  uint8_t factionFlagsB[2];   /* [BP-0x20] */
  uint8_t factionFlagsA[2];   /* [BP-0x22] */
  uint8_t factionMax [4];
  long *plStack_18;
  int timerHi;
  char cStack_12;
  byte bStack_10;
  uint otherIdx;
  uint uStack_8;
  
  lVar29 = CONCAT22((int)((ulong)in_stack_0000ffd0 >> 0x10),unaff_SI);
  entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
  startY = (Entities)[entityIndex].base.y;
  uVar6 = alignUp4(((Entities + entityIndex)->base).x,0,0);
  _fmemset(MK_FP(_SS, factionTimer), 0, 8);
  _fmemset(MK_FP(_SS, factionFlagsB), 0xFF81, 2);
  _fmemset(MK_FP(_SS, factionFlagsA), 0xFF81, 2);
  uVar16 = entityIndex;
  do {
    entityIndex_00 = uVar16;
    entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
    gindex = (Entities)[entityIndex_00].base.gindex;
    *(undefined1 *)((int)&(Entities)[entityIndex_00].base.entity + 2) = 1;
    agentAI = AgntGs[(uint)gindex].ai;
    bVar5 = ovc24_usesEntities(entityIndex_00);
    uVar7 = (uint)bVar5 * (uint)bVar5 * (uint)(Entities)[entityIndex_00].base.animFrame
    ;
    puVar1 = (uint *)(&factionTimer[0] + agentAI);
    uVar16 = *puVar1;
    *puVar1 = *puVar1 + uVar7;
    piVar2 = (int *)((int)&factionTimer[0] + (uint)agentAI * 4 + 2);
    *piVar2 = *piVar2 + ((int)uVar7 >> 0xf) + (uint)CARRY2(uVar16,uVar7);
    if (((AgntGs[(uint)gindex].flags & 8) == 0) &&
       ((AgntGs[(uint)gindex].flags2 & 0x20) == 0)) {
      puVar25 = factionMax + agentAI;
      bVar5 = ovr_agnt_compute8(&(Entities)[entityIndex_00].base,
                                (char)((ulong)Entities >> 0x10));
      if ((char)*puVar25 < (char)bVar5) {
        pbVar26 = factionMax + agentAI;
        bVar5 = ovr_agnt_compute8(&Entities[entityIndex_00].base,(char)((ulong)Entities >> 0x10));
        *pbVar26 = bVar5;
      }
    }
    if ((AgntGs[(uint)gindex].flags & 8) == 0) {
      puVar25 = factionMax + agentAI + 2;
      bVar5 = ovr_agnt_compute8(&Entities[entityIndex_00].base,(char)((ulong)Entities >> 0x10));
      if ((char)*puVar25 < (char)bVar5) {
        pbVar26 = factionMax + agentAI + 2;
        bVar5 = ovr_agnt_compute8(&Entities[entityIndex_00].base,(char)((ulong)Entities >> 0x10));
        *pbVar26 = bVar5;
      }
    }
    if (((char)factionMax[agentAI + 2] < '\x02') &&
       ((AgntGs[(uint)gindex].flags & 2) != 0)) {
      factionMax[agentAI + 2] = 0x2;
    }
    uVar16 = entityIndex_00;
    if ((((char)factionMax[agentAI] < '\x02') &&
        ((AgntGs[(uint)gindex].flags & 2) != 0)) &&
       (4 < (Entities)[entityIndex_00].base.level)) {
      factionMax[agentAI] = 0x2;
    }
    do {
      uVar16 = uVar16 + 1;
      if (EntityCount <= uVar16) break;
      entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
    } while (((Entities)[uVar16].base.y != startY) ||
            (uVar7 = alignUp4(((Entities + uVar16)->base).x,0,0), uVar7 != uVar6));
  } while (uVar16 < EntityCount);
  timerHi = 0;
  plStack_18 = (long *)"Time passes...";
  if ((-1 < (*(uint16_t *)((uint8_t *)&(factionTimer[0]) + 2))) &&
     ((0 < (*(uint16_t *)((uint8_t *)&(factionTimer[0]) + 2)) || ((long *)"Time passes..." < (long *)factionTimer[0])))) {
    timerHi = (*(uint16_t *)((uint8_t *)&(factionTimer[0]) + 2));
    plStack_18 = (long *)factionTimer[0];
  }
  if ((timerHi <= (*(uint16_t *)((uint8_t *)&(factionTimer[1]) + 2))) &&
     ((timerHi < (*(uint16_t *)((uint8_t *)&(factionTimer[1]) + 2)) || (plStack_18 < (long *)factionTimer[1])))) {
    timerHi = (*(uint16_t *)((uint8_t *)&(factionTimer[1]) + 2));
    plStack_18 = (long *)factionTimer[1];
  }
  timerB2 = (undefined1)timerHi;
  timerB3 = (undefined1)((uint)timerHi >> 8);
  timerB0 = SUB21(plStack_18,0);
  timerB1 = (undefined1)((uint)plStack_18 >> 8);
  entitiesSeg = 0;
  timerB0c = timerB0;
  timerB1c = timerB1;
  timerB2c = timerB2;
  timerB3c = timerB3;
  plVar8 = LXMUL_at_(plStack_18,CONCAT22(unaff_DI,timerHi),lVar29);
  factionTimer[0] = LDIV_at_(CONCAT13((char)((uint)entitiesSeg >> 8),CONCAT12((char)entitiesSeg,plVar8)),
                       CONCAT13(timerB3c,CONCAT12(timerB2c,CONCAT11(timerB1c,timerB0c))));
  factionTimer[0] = factionTimer[0] + 0x14;
  entitiesSeg = 0;
  plVar8 = LXMUL_at_(plStack_18,CONCAT22(unaff_DI,timerHi),lVar29);
  factionTimer[1] = LDIV_at_(CONCAT13((char)((uint)entitiesSeg >> 8),CONCAT12((char)entitiesSeg,plVar8)),
                       CONCAT13(timerB3,CONCAT12(timerB2,CONCAT11(timerB1,timerB0))));
  factionTimer[1] = factionTimer[1] + 0x14;
  randPick = ovr_randBelow((uint16_t)(long *)factionTimer[0],0);
  randPickB = ovr_randBelow((uint16_t)(long *)factionTimer[1],0);
  randPick2 = ovr_randBelow((uint16_t)(long *)factionTimer[0],0);
  uStack_8 = randPick2 & 0xff;
  randPick2 = ovr_randBelow((uint16_t)(long *)factionTimer[1],0);
  uVar16 = randPick2 & 0xff;
  if ((randPickB & 0xff) < (randPick & 0xff)) {
    uStack_8 = uStack_8 / (uVar16 + 1);
    bStack_10 = 1;
  }
  else {
    if (uVar16 <= uStack_8) {
      return;
    }
    uStack_8 = uVar16 / (uStack_8 + 1);
    bStack_10 = 0;
  }
  uStack_8 = uStack_8 + 1;
  if (2 < uStack_8) {
    uStack_8 = 2;
  }
  lVar29 = -0x1000000;
  uVar16 = 0xffff;
  otherIdx = 0xffff;
  do {
    if ((int)entityIndex_00 < (int)entityIndex) {
      if (otherIdx != 0xffff) {
        if (uVar16 == 0xffff) {
          gindex = (byte)((ulong)Entities >> 0x10);
          ovr_attact_usesRandBelow
                    (&Entities[otherIdx].base,gindex,gindex,Entities[otherIdx].base.target);
          ovr_attact_usesEntities(otherIdx,0,0,0,0,0,0,0,0);
          entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
          peVar15 = Entities;
          gindex = peVar15[otherIdx].base.gindex;
          if (AgntGs[(uint)gindex].ai == '\0') {
            alignUp4(((peVar15 + entityIndex)->base).x,(char)peVar15[entityIndex].base.y,0);
            gOfs = (uint)gindex * 0x95;
            entitiesSeg = *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + gOfs);
            msg = ovr_fmVsprintf("Intelligence reports %s unit fleeing from battle. (%d, %d)",
                                     (char *)CONCAT13((char)((uint)entitiesSeg >> 8),
                                                      CONCAT12((char)entitiesSeg,
                                                               *(uint16_t *)
                                                                ((int)&worldMenuLabels[0].seg + 1 +
                                                                gOfs))));
            asm { mov startY,dx };
            ovr_uiNotify(msg,startY,(char)startY);
          }
        }
        else {
          if (Entities[uVar16].base.animFrame <= uStack_8) {
            uStack_8 = (uint)Entities[uVar16].base.animFrame;
          }
          Entities[uVar16].base.animFrame = Entities[uVar16].base.animFrame - (byte)uStack_8;
          gindex = (byte)((ulong)Entities >> 0x10);
          ovr_ovc41_compute4(&Entities[uVar16].base,gindex,(byte)uStack_8,&Entities[otherIdx].base,
                             gindex,(byte)uStack_8,(char)(Entities + otherIdx),gindex);
          ovr_ovc25_attackingNotice
                    (*(byte *)((int)&(Entities)[uVar16].base.entity + 3));
          if ((Entities)[uVar16].base.animFrame != 0x0) {
            ovc24_usesLDIV_at_(uVar16);
            entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
            peVar15 = Entities;
            if (((AgntGs[(uint)peVar15[otherIdx].base.gindex].flags2 & 4) != 0) &&
               ((*(uint *)((int)&peVar15[uVar16].base.frames + 1) & 1) == 0)) {
              uVar6 = ovr_ovc27_rollToHitAgent
                                (CONCAT13((char)((ulong)Entities >> 0x18),
                                          CONCAT12((char)((ulong)Entities >> 0x10),peVar15 + uVar16
                                                  )),0);
              if ((uVar6 & 0xff) == 0) {
                puVar1 = (uint *)((int)&(Entities)[uVar16].base.frames + 1);
                *puVar1 = *puVar1 | 1;
                entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
                alignUp4(((Entities + entityIndex)->base).x,
                         (char)(Entities)[entityIndex].base.y,0);
                gOfs = (uint)(Entities)[uVar16].base.gindex * 0x95;
                entitiesSeg = *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + gOfs);
                msg = ovr_fmVsprintf("Intelligence reports %s unit infected with disease. (%d, %d)"
                                         ,(char *)CONCAT13((char)((uint)entitiesSeg >> 8),
                                                           CONCAT12((char)entitiesSeg,
                                                                    *(uint16_t *)
                                                                     ((int)&worldMenuLabels[0].seg +
                                                                      1 + gOfs))));
                asm { mov startY,dx };
                ovr_uiNotify(msg,startY,(char)startY);
              }
            }
            if ((AgntGs[(uint)(Entities)[otherIdx].base.gindex].flags2 & 0xc00) != 0)
            {
              uVar6 = ovr_ovc27_rollToHitAgent
                                (CONCAT13((char)((ulong)Entities >> 0x18),
                                          CONCAT12((char)((ulong)Entities >> 0x10),
                                                   Entities + uVar16)),3);
              if ((uVar6 & 0xff) == 0) {
                if ((AgntGs[(uint)(Entities)[otherIdx].base.gindex].flags2 & 0x800)
                    == 0) {
                  cStack_12 = '\x01';
                }
                else {
                  cStack_12 = '\x02';
                }
                entitiesSeg = ovr_ovc27_compute3(CONCAT13((char)((ulong)Entities >> 0x18),
                                                     CONCAT12((char)((ulong)Entities >> 0x10),
                                                              Entities + uVar16)),
                                            cStack_12);
                if ((char)entitiesSeg != '\0') {
                  if (DebugVerbose != false) {
                    printf("kill 3\r");
                  }
                  entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
                  if ((Entities)[uVar16].base.animFrame != 0x0) {
                    puVar3 = &(Entities)[uVar16].base.animFrame;
                    *puVar3 = *puVar3 + 0xff;
                  }
                }
                entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
                alignUp4(((Entities + entityIndex)->base).x,
                         (char)(Entities)[entityIndex].base.y,0);
                gOfs = (uint)(Entities)[uVar16].base.gindex * 0x95;
                entitiesSeg = *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + gOfs);
                msg = ovr_fmVsprintf("Intelligence reports %s unit drained of energy. (%d, %d)",
                                         (char *)CONCAT13((char)((uint)entitiesSeg >> 8),
                                                          CONCAT12((char)entitiesSeg,
                                                                   *(uint16_t *)
                                                                    ((int)&worldMenuLabels[0].seg +
                                                                     1 + gOfs))));
                asm { mov startY,dx };
                ovr_uiNotify(msg,startY,(char)startY);
              }
            }
          }
        }
      }
      return;
    }
    if (Entities[entityIndex].base.y == startY) {
      uVar7 = alignUp4(((Entities + entityIndex)->base).x,0,0);
      if (uVar7 == uVar6) {
        entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
        peVar15 = Entities;
        if (AgntGs[(uint)peVar15[entityIndex].base.gindex].ai == bStack_10) {
          gindex = (byte)((ulong)lVar29 >> 0x18);
          if (peVar15[entityIndex].base.level < gindex) {
L_OVC24_5943_026e_0772:
            entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
            gindex = (Entities)[entityIndex].base.gindex;
            if (((((AgntGs[(uint)gindex].flags3 & 0x40) == 0)
                 || ('\x01' < (char)factionMax[(bStack_10 ^ 1) + 2])) &&
                (((AgntGs[(uint)gindex].flags2 & 8) == 0 ||
                 ('\0' < (char)factionMax[(bStack_10 ^ 1) + 2])))) &&
               (((AgntGs[(uint)gindex].flags2 & 0x10) == 0 ||
                (-1 < (char)factionMax[bStack_10 ^ 1])))) {
              lVar29 = CONCAT13((Entities)[entityIndex].base.level,(int3)lVar29);
              uVar16 = entityIndex;
            }
          }
          else if (peVar15[entityIndex].base.level == gindex) {
            randPick = ovr_randBelow(3,0);
            if ((randPick & 0xff) == 0) goto L_OVC24_5943_026e_0772;
          }
        }
        else {
          gindex = (byte)((ulong)lVar29 >> 0x10);
          if (gindex < peVar15[entityIndex].base.level) {
L_OVC24_5943_026e_088A:
            lVar29 = (ulong)CONCAT11((char)((ulong)lVar29 >> 0x18),
                                     (Entities)[entityIndex].base.level) << 0x10;
            otherIdx = entityIndex;
          }
          else if (peVar15[entityIndex].base.level == gindex) {
            randPick = ovr_randBelow(3,0);
            if ((randPick & 0xff) == 0) goto L_OVC24_5943_026e_088A;
          }
        }
      }
    }
    entityIndex = entityIndex + 1;
  } while( true );
}



/* 5943:0d5a */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Kills and reports every entity except the one under the cursor, then sets GGameState = 0x20. */

void __cdecl16far ovc24_removeOtherEntities(uint8_t far *reportedOut)

{
  uint alignedX;
  uint agntIdx;
  uint alignedSeed;
  char *msg;
  uint16_t dst;
  int labelOfs;
  uint ent;
  uint16_t cursorHit;
  
  if (!GameRunning) {
    for (ent = 0; ent < EntityCount; ent = ent + 1) {
      AGNT_FIELD(&(Entities)[ent], base.entity, 2) = 0;
    }
    for (ent = 0; ent < EntityCount; ent = ent + 1) {
      if ((AGNT_FIELD(&(Entities)[ent], base.entity, 1) != '\0') &&
         (AGNT_FIELD(&(Entities)[ent], base.entity, 2) == '\0')) {
        if ((GOngoingBattle == '\0') && (((entity_t far *)Entities)[ent].base.y == GfxRndSeed2)) {
          alignedX = alignUp4(*(int *)((entity_t far *)Entities + ent),0,0);
          alignedSeed = alignUp4(GfxRndSeed,0,0);
          if (alignedX == alignedSeed) goto L_OVC24_5943_0d5a_0E37;
        }
        ovc24_textKill(ent);
      }
L_OVC24_5943_0d5a_0E37:
      ovc24_intelUnitReport(ent);
    }
    GGameState = 0x20;
    ent = EntityCount;
    while (ent = ent - 1, -1 < (int)ent) {
      if (((entity_t far *)Entities)[ent].base.animFrame == '\0') {
        if ((GOngoingBattle == '\0') &&
           (cursorHit = ovr_ovc23_isCursorAt
                              (*(uint16_t *)((entity_t far *)Entities + ent),((entity_t far *)Entities)[ent].base.y,0), (char)cursorHit != '\0')) {
          agntIdx = (uint)AgntCount;
          do {
            agntIdx = agntIdx - 1;
            if ((int)agntIdx < 0) break;
          } while (Agnts[agntIdx].owner != ent);
          if ((int)agntIdx < 0) {
            if (AgntGs[(uint)(Entities)[ent].base.gindex].ai == '\0'
               ) {
              ovr_play_sfx(8,0,0);
            }
            else {
              ovr_play_sfx(11,0,0);
            }
            ovr_ovc15_removeEntity(ent);
          }
        }
        else {
          alignUp4((Entities)[ent].base.x,
                   (Entities)[ent].base.y,0xa000);
          labelOfs = (uint)(Entities)[ent].base.gindex * 0x95;
          msg = ovr_fmVsprintf("Intelligence reports %s unit destroyed. (%d, %d)",
                               (char *)CONCAT22(*(uint16_t *)
                                                 ((int)&worldMenuLabels[1].ofs + 1 + labelOfs),
                                                (char *)*(uint16_t *)
                                                         ((int)&worldMenuLabels[0].seg + 1 + labelOfs))
                              );
          asm { mov dst,dx };
          ovr_uiNotify(msg,dst,0);
          ovr_ovc15_removeEntity(ent);
        }
        *reportedOut = 0x1;
      }
    }
  }
  return;
}



/* 5943:1007 */

/* Returns the unit index at a leader's map position. */

uint16_t __cdecl16far ovc24_unitAtLeader(byte leaderIndex)

{
  /* Re-derived: 1 when the leader's own unit stands on the leader's cell with unitType equal
     to the leader index, the building flag word at 0x121 has bit 4 set, the leader sheet's
     +0x3f byte is clear and the unit's level is 0. */
  int leaderY;
  byte firstLeader;
  int leaderX;
  unit_t *units;
  short unitIdx;
  uint bldOfs;

  leaderX = (GLeaderSheets[leaderIndex])->x;
  leaderY = (GLeaderSheets[leaderIndex])->y;
  firstLeader = ovr_manage_findFirstLeader();
  if (leaderIndex == firstLeader) {
    unitIdx = ((short (*) [148] [60])GUnitGrid)[-1][leaderX + 0x92][leaderY];
  }
  else {
    unitIdx = ((short (*) [148] [60])GUnitGrid)[-1][leaderX + 0x93][leaderY];
  }
  units = GUnits;
  if (units[unitIdx].unitType != leaderIndex) {
    return 1;
  }
  bldOfs = (uint)(units + unitIdx)->bldType * 0x27;
  if ((*(uint *)(bldOfs + 0x121) & 4) == 0) {
    return 1;
  }
  if ((*(char *)((int)*(uint32_t *)((uint)leaderIndex << 2) + 0x3f) == '\0') &&
     (units[unitIdx].level == 0)) {
    return 1;
  }
  return 0;
}



/* 5943:112e */

/* Checks every side's stronghold each turn and reports destruction, defeat or victory. */

void __cdecl16far ovc24_checkStrongholds(void)

{
  bool bVar1;
  bool bVar2;
  uint16_t unitIdx;
  uint aligned;
  char *pcVar5;
  uint uVar6;
  uint16_t uVar7;
  int probeOfs;
  uint16_t unaff_DI;
  static char text[64];   /* DGROUP-backed formatting buffer */
  char sbuf [120];
  static char outFlag[64];   /* DGROUP-backed formatting buffer */
  uint8_t excludedFlags;
  char cStack_11;
  uint flagMask;
  uint16_t cellX;
  uint ownMask;
  char cStack_a;
  byte leaderClass;
  byte enemyMask;
  byte side;
  uint leaderIndex;
  char cStack_4;
  byte firstLeader;
  
  strongholdCheckPending = 0;
  cStack_4 = '\0';
  if (!GameRunning) {
    cStack_a = '\0';
    bVar1 = false;
    for (leaderIndex = 0; (int)leaderIndex < (int)(uint)GLeaderCount; leaderIndex = leaderIndex + 1) {
      if ((GLeaderSheets[leaderIndex])->active != '\0') {
        leaderClass = (GLeaderSheets[leaderIndex])->classStr;
        side = *((byte far *)GLeaderSheets[leaderIndex] + 0x3f);
        ownMask = 0x1000 << (1U - (side != 0) & 0x1f);
        enemyMask = '\0' << (side & 0x1f);
        cellX = alignUp4((GLeaderSheets[leaderIndex])->x,0,0);
        uVar6 = (GLeaderSheets[leaderIndex])->y;
        flagMask = 0;
        for (probeOfs = -2; probeOfs < 2; probeOfs = probeOfs + 1) {
          flagMask = flagMask | (*(short (*) [60] [148])GMapFlags)[uVar6][cellX + probeOfs];
        }
        if (((flagMask & enemyMask) == 0) && ((flagMask & ownMask) != 0)) {
          unitIdx = ovc24_unitAtLeader((byte)leaderIndex);
          if (((char)unitIdx == '\0') || (bVar2 = ovc24_textArena(cellX,uVar6,side), bVar2))
          goto L_OVC24_5943_112e_1255;
        }
        else {
L_OVC24_5943_112e_1255:
          if (((destroyLatchSide1 == '\0') || (side == 0)) &&
             ((destroyLatchSide0 == '\0' || (side != 0)))) goto L_OVC24_5943_112e_15E7;
        }
        ovr_stop_audio();
        destroyLatchSide1 = '\0';
        destroyLatchSide0 = '\0';
        firstLeader = ovr_manage_findFirstLeader();
        if (side == 0) {
          ovr_play_sfx(68,0,0);
        }
        else {
          ovr_play_sfx(44,0,0);
          strongholdsDestroyed = strongholdsDestroyed + 1;
          cStack_a = '\x01';
        }
        uVar7 = 0x195d;
        if ((AgntGs[(uint)leaderClass].flags3 & 0x800) == 0) {
          aligned = alignUp4((GLeaderSheets[leaderIndex])->x,uVar6,0);
          pcVar5 = ovr_ovc15_capitalize(text);
          pcVar5 = ovr_stsprintf(sbuf,(char *)CONCAT22(0x578d,_SS),
                                 (char *)CONCAT22(pcVar5,(char *)0x26510),uVar7,aligned);
          ovr_uiNotify(pcVar5,uVar7,0);
        }
        else {
          aligned = alignUp4((GLeaderSheets[leaderIndex])->x,uVar6,0);
          pcVar5 = ovr_stsprintf(sbuf,(char *)CONCAT22(0x576a,_SS),
                                 (char *)CONCAT22(aligned,(char *)0x26510));
          ovr_uiNotify(pcVar5,uVar7,0);
        }
        if (firstLeader == leaderIndex) {
          ovr_createConstructionRecordFar
                    (0,(GLeaderSheets[leaderIndex])->x + -2,uVar6,(uint8_t *)outFlag,0xff,(char)unaff_DI,0xff,0,0);
        }
        else {
          ovr_createConstructionRecordFar
                    (0,(GLeaderSheets[leaderIndex])->x + -1,uVar6,(uint8_t *)outFlag,0xff,(char)unaff_DI,0xff,0,0);
        }
        CurSfxType3 = 0xff;
        (GLeaderSheets[leaderIndex])->active = 0;
        bVar1 = true;
        ovr_manage_mapPartySlots();
        ovr_font_usesMiceBlitRect(0x5a);
        _fmemset(MK_FP(_SS, &flagMask), 0, 2);
        if (side == 0) {
          probeOfs = (uint)(GLeaderSheets[leaderIndex])->classStr * 0x95;
          ovr_ovc40_usesAlignToSeg
                    ('\x01',(char *)*(uint16_t *)((int)&worldMenuLabels[0].seg + 1 + probeOfs),*(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + probeOfs),(char *)0x0,0,4,0,0,0,0);
        }
        else {
          uVar6 = ovr_season_checkEndGame((byte)leaderIndex);
          if ((uVar6 & 0xff) == 0) {
            for (probeOfs = 0; probeOfs < (int)(uint)GLeaderCount; probeOfs = probeOfs + 1) {
              if ((GLeaderSheets[probeOfs])->active != '\0') {
                (&excludedFlags)[*((byte far *)GLeaderSheets[probeOfs] + 0x3f)] = 0x1;
              }
            }
            if ((((cStack_11 == '\0') && (1 < PlayerIndex)) && (GHighScoreSaved == '\0')) &&
               (((GLeaderSheets[firstLeader])->alignment == '\x02' ||
                (((GLeaderSheets[firstLeader])->alignment == '\x01' &&
                 (8 < (GLeaderSheets[firstLeader])->titleIndex)))))) {
              cStack_4 = '\x01';
            }
            if (cStack_4 == '\0') {
              probeOfs = (uint)(GLeaderSheets[leaderIndex])->classStr * 0x95;
              ovr_ovc40_usesAlignToSeg
                        ('\x03',(char *)*(uint16_t *)((int)&worldMenuLabels[0].seg + 1 + probeOfs),*(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + probeOfs),(char *)0x0,0,6,0,0,0,0);
            }
            else {
              probeOfs = (uint)(GLeaderSheets[leaderIndex])->classStr * 0x95;
              ovr_ovc40_usesAlignToSeg
                        ('\x02',(char *)*(uint16_t *)((int)&worldMenuLabels[0].seg + 1 + probeOfs),*(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + probeOfs),(char *)0x0,0,5,0,0,0,0);
            }
          }
        }
        ovc24_usesGLeaderCount((byte)leaderIndex);
      }
L_OVC24_5943_112e_15E7:
    }
    if (bVar1) {
      firstLeader = ovr_manage_findFirstLeader();
      _fmemset(MK_FP(_SS, &flagMask), 0, 2);
      for (leaderIndex = 0; (int)leaderIndex < (int)(uint)GLeaderCount; leaderIndex = leaderIndex + 1) {
        if ((GLeaderSheets[leaderIndex])->active != '\0') {
          (&excludedFlags)[*((byte far *)GLeaderSheets[leaderIndex] + 0x3f)] = 0x1;
        }
      }
      if ((firstLeader == 0xff) ||
         ((GLeaderSheets[firstLeader])->active == '\0')) {
        ovr_play_sfx(68,0,0);
        CurMusicType = 0x44;
        ovr_uiNotify((char *)"Your main stronghold has been destroyed. Game over.",0x2410,0);
        GGameInProgress = 1;
        ovr_ovc38_usesStshAlloc();
        ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
        ovr_stats_drawStatsPanel();
        ovr_ovc38_showAchievements();
        ovr_clearMiceProcessed();
        ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
        ovr_stop_audio();
        CurMusicType = 0xff;
      }
      else if ((cStack_11 == '\0') && (PlayerIndex == 1)) {
        ovr_ovc30_nextWave(1);
      }
      else if ((cStack_a != '\0') && ((cStack_11 == '\0' && (1 < PlayerIndex)))) {
        ovr_stop_audio();
        CurMusicType = 0x54;
        ovr_play_sfx(84,0,0);
        ovr_uiNotify((char *)"You have defeated all enemies.",0x2410,0);
        ovr_font_usesMiceBlitRect(messageDelayTicks << 4);
        if (cStack_4 == '\0') {
          ovr_inputUpdate((ulong)messageDelayTicks << 4);
        }
        else {
          ovr_ovc38_usesStshAlloc();
          ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
          ovr_stats_drawStatsPanel();
          ovr_uiNotify((char *)"You may continue playing, but your score will not be recorded.",
                       0x2410,0);
          ovr_ovc38_showAchievements();
          ovr_clearMiceProcessed();
          ovr_ovc28_textHalflingCastle();
          ovr_ovc41_usesGMenuItem();
          ovr_miceBlitRect((brect_t *)(BlitRects + 1),0x10);
        }
        CurMusicType = 0xff;
        ovr_stop_audio();
      }
    }
  }
  return;
}



/* 5943:181d */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls LDIV_at_ */

void __cdecl16far ovc24_usesLDIV_at_(int entityIndex)

{
  byte stepVal;
  char dirBase;
  char dirStep;
  uint randVal;
  long *plVar5;
  int randSign;
  uint16_t unaff_SI;
  long lVar7;
  undefined1 scaleLo;
  undefined1 scaleHi;
  uint16_t uVar10;
  byte in_stack_0000fffc;
  
  uVar10 = 0;
  scaleLo = 0;
  scaleHi = 0x80;
  randVal = rand();
  randSign = (int)randVal >> 0xf;
  plVar5 = LXLSH_at_((long *)CONCAT11(scaleHi,scaleLo),CONCAT22(unaff_SI,uVar10),in_stack_0000fffc);
  lVar7 = LDIV_at_((long)CONCAT22(randSign,plVar5),CONCAT22(uVar10,CONCAT11(scaleHi,scaleLo)));
  if ((int)lVar7 == 0) {
    uVar10 = (uint16_t)((ulong)Entities >> 0x10);
    if (((AgntGs[(uint)(Entities)[entityIndex].base.gindex].flags & 0x2000) != 0
        ) && (stepVal = ovr_agnt_compute8((agnt_t far *)((uint8_t *)&(Entities)[entityIndex]),uVar10),
             -1 < (char)stepVal)) {
      uVar10 = (uint16_t)((ulong)Entities >> 0x10);
      dirBase = (Entities)[entityIndex].dir -
              (Entities)[entityIndex].dir % 6;
      dirStep = ovr_ovc22_compute3(stepVal - 1);
      (Entities)[entityIndex].dir = dirBase + dirStep;
    }
  }
  return;
}



/* 5943:190b */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches GLeaderCount, EntityCount */

void __cdecl16far ovc24_usesGLeaderCount(byte leaderIndex)

{
  uint dist;
  uint entIdx;
  uint dy;
  byte leaderIdx;
  uint xSign;
  uint ySign;
  uint16_t entitiesSeg;
  uint16_t unitsSeg;
  uint bestOtherDist;
  uint bestDist;
  byte bestOtherIdx;
  byte bestSameIdx;
  uint unitIdx;
  
  bestDist = 0xffff;
  bestOtherDist = 0xffff;
  bestSameIdx = 0xff;
  bestOtherIdx = 0xff;
  if (*((char far *)GLeaderSheets[leaderIndex] + 0x3f) == '\0') {
    for (leaderIdx = 0; leaderIdx < GLeaderCount; leaderIdx = leaderIdx + 1) {
      if ((((GLeaderSheets[leaderIdx])->active != '\0') &&
          (*((char far *)GLeaderSheets[leaderIdx] + 0x3f) ==
           *((char far *)GLeaderSheets[leaderIndex] + 0x3f))) &&
         (dist = (GLeaderSheets[leaderIdx])->x -
                  (GLeaderSheets[leaderIndex])->x,
         xSign = (int)dist >> 0xf,
         dy = (GLeaderSheets[leaderIdx])->y -
                 (GLeaderSheets[leaderIndex])->y,
         ySign = (int)dy >> 0xf, dist = ((dist ^ xSign) - xSign) + ((dy ^ ySign) - ySign),
         dist < bestDist)) {
        bestDist = dist;
        bestSameIdx = leaderIdx;
      }
    }
  }
  else {
    for (leaderIdx = 0; leaderIdx < GLeaderCount; leaderIdx = leaderIdx + 1) {
      if ((((GLeaderSheets[leaderIdx])->active != '\0') &&
          (*((char far *)GLeaderSheets[leaderIdx] + 0x3f) == '\0')) &&
         (dist = (GLeaderSheets[leaderIdx])->x -
                  (GLeaderSheets[leaderIndex])->x,
         xSign = (int)dist >> 0xf,
         dy = (GLeaderSheets[leaderIdx])->y -
                 (GLeaderSheets[leaderIndex])->y,
         ySign = (int)dy >> 0xf,
         dist = ((dist ^ xSign) - xSign) + ((dy ^ ySign) - ySign) * 2, dist < bestOtherDist)) {
        bestOtherDist = dist;
        bestOtherIdx = leaderIdx;
      }
    }
  }
  for (entIdx = 0; entIdx < EntityCount; entIdx = entIdx + 1) {
    entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
    if ((AGNT_FIELD(&(Entities)[entIdx], base.entity, 3) == leaderIndex) &&
       (AGNT_FIELD(&(Entities)[entIdx], base.entity, 3) = bestSameIdx, bestOtherIdx != 0xff)) {
      (Entities)[entIdx].base.destX =
           (GLeaderSheets[bestOtherIdx])->x;
      (Entities)[entIdx].base.destY =
           (GLeaderSheets[bestOtherIdx])->y;
    }
  }
  for (unitIdx = 0xf8; unitIdx < GUnitCount; unitIdx = unitIdx + 1) {
    unitsSeg = (uint16_t)((ulong)GUnits >> 0x10);
    if ((GUnits)[unitIdx].unitType == leaderIndex) {
      (GUnits)[unitIdx].unitType = 0xff;
    }
  }
  return;
}



/* 5943:1bff */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Formats the per-unit intelligence report (cured/diseased/poisoned variants). */

void __cdecl16far ovc24_intelUnitReport(int entityIndex)

{
  /* Re-derived: when the entity is a "cured of disease" report, look for a neighbouring building
     whose flags2 has 0x100 (or an agent whose AgntGs flags has bit 0 and level above 5); if one is
     found, clear bit 0 of the entity's frames word, report it and stop.  Otherwise roll 0x28 and,
     on a hit, scan for an entity whose AgntGs flags2 has bit 4, report the blast-spore variant and
     apply ovc15_usesLDIV_at_2 to it.  Names only: every expression is the export's. */
  uint *framesWordPtr;
  bool found;
  byte bldType;
  uint alignedX;
  uint sporeIdx;
  uint16_t msgSeg;
  uint16_t randPick;
  int entY;
  int dirOfs;
  int gindexOfs;
  char *msg;
  uint scanIdx;

  if ((AGNT_WORD(&(Entities)[entityIndex], base.frames, 1) & 1) != 0) {
    alignedX = alignUp4((Entities)[entityIndex].base.x,0,0);
    entY = ((entity_t far *)Entities)[entityIndex].base.y;
    if (AGNT_FIELD(&(Entities)[entityIndex], base.entity, 1) == '\0') {
      found = false;
      for (scanIdx = 0; scanIdx < EntityCount; scanIdx = scanIdx + 1) {
        if (((AgntGs[(uint)((entity_t far *)Entities)[scanIdx].base.gindex].flags & 1) != 0) &&
           (5 < ((entity_t far *)Entities)[scanIdx].base.level)) {
          found = true;
          break;
        }
      }
      if (!found) {
        for (dirOfs = 0; dirOfs < 4; dirOfs = dirOfs + 1) {
          bldType = ovr_ovc45_getUnitType(alignedX + dirOfs + -2,entY);
          if ((BuildingTypes[bldType].flags2 & 0x100) != 0) {
            found = true;
            break;
          }
        }
      }
      if (found) {
        framesWordPtr = (uint *)((uint8_t *)&(Entities)[entityIndex] + 0x14);
        *framesWordPtr = *framesWordPtr & 0xfffe;
        alignUp4((Entities)[entityIndex].base.x,
                 (Entities)[entityIndex].base.y,0xa000);
        gindexOfs = (uint)(Entities)[entityIndex].base.gindex * 0x95;
        msg = ovr_fmVsprintf("Intelligence reports %s unit cured of disease. (%d, %d)",
                                (char *)CONCAT22(*(uint16_t *)
                                                  ((int)&worldMenuLabels[1].ofs + 1 + gindexOfs),
                                                 (char *)*(uint16_t *)
                                                          ((int)&worldMenuLabels[0].seg + 1 + gindexOfs)
                                                ));
        asm { mov msgSeg,dx };
        ovr_uiNotify(msg,msgSeg,0);
        return;
      }
    }
    randPick = ovr_randBelow(0x28,0);
    if ((randPick & 0xff) == 0) {
      sporeIdx = 0;
      while( true ) {
        if ((EntityCount <= sporeIdx) ||
           ((AgntGs[(uint)((entity_t far *)Entities)[sporeIdx].base.gindex].flags2 & 4) != 0)) break;
        sporeIdx = sporeIdx + 1;
      }
      if (sporeIdx < EntityCount) {
        alignUp4(*(int *)((entity_t far *)Entities + entityIndex),
                 ((entity_t far *)Entities)[entityIndex].base.y,0xa000);
        gindexOfs = (uint)(Entities)[entityIndex].base.gindex * 0x95;
        msg = ovr_fmVsprintf("Intelligence reports %s unit succombs to blast spore disease. (%d, %d)"
                                ,(char *)CONCAT22(*(uint16_t *)
                                                   ((int)&worldMenuLabels[1].ofs + 1 + gindexOfs),
                                                  (char *)*(uint16_t *)
                                                           ((int)&worldMenuLabels[0].seg + 1 + gindexOfs
                                                           )));
        asm { mov msgSeg,dx };
        ovr_uiNotify(msg,msgSeg,0);
        ovr_ovc15_usesLDIV_at_2
                  (entityIndex,(Entities)[sporeIdx].base.gindex,
                   *(char *)((int)&(Entities)[sporeIdx].base.entity + 3));
      }
    }
  }
  return;
}



/* 5943:1eeb */

/* [R2] string "arena" */

bool __cdecl16far ovc24_textArena(uint16_t x,uint y,char faction)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if ((GOngoingBattle == '\0') && (GfxRndSeed2 == y)) {
    uVar1 = alignUp4(x,0,0);
    uVar2 = alignUp4(GfxRndSeed,0,0);
    if (uVar1 == uVar2) {
      iVar3 = 0;
      while( true ) {
        if ((int)(uint)AgntCount <= iVar3) {
          return false;
        }
        if (((Agnts[iVar3].flags & 0xae4) == 0) &&
           (Agnts[iVar3].faction == faction)) break;
        iVar3 = iVar3 + 1;
      }
      return true;
    }
  }
  return false;
}


