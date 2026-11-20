/*
 * ovc24.c - recovered from STRONG.EXE
 * memory block: OVC24
 * range: 5943:000e - 5943:222f
 * functions: 10
 */
#include "recovered.h"


/* 5943:000e */

/* [R4] calls alignUp4 */

void __cdecl16far ovc24_usesAlignUp4(void)

{
  char cVar1;
  uint16_t uVar2;
  uint uVar3;
  uint uVar4;
  entity_t *peVar5;
  uint uVar6;
  uint uVar7;
  undefined2 uVar8;
  
  for (uVar7 = 0; uVar7 < EntityCount; uVar7 = uVar7 + 1) {
    *(undefined1 *)((int)&((entity_t *)Entities)[uVar7].base.entity + 1) = 0;
  }
  uVar7 = 0;
  do {
    if (EntityCount <= uVar7) {
      return;
    }
    uVar8 = (undefined2)((ulong)Entities >> 0x10);
    peVar5 = (entity_t *)Entities;
    if (*(char *)((int)&peVar5[uVar7].base.entity + 1) == '\0') {
      cVar1 = *(char *)((int)(char **)GMenuStrings + (uint)peVar5[uVar7].base.gindex * 0x95 + 0x1f);
      uVar3 = alignUp4(((peVar5 + uVar7)->base).x);
      uVar2 = ((entity_t *)Entities)[uVar7].base.y;
      for (uVar6 = 0; uVar6 < EntityCount; uVar6 = uVar6 + 1) {
        uVar8 = (undefined2)((ulong)Entities >> 0x10);
        peVar5 = (entity_t *)Entities;
        if (((peVar5[uVar6].base.y == uVar2) &&
            (*(char *)((int)(char **)GMenuStrings + (uint)peVar5[uVar6].base.gindex * 0x95 + 0x1f)
             != cVar1)) && (uVar4 = alignUp4(((peVar5 + uVar6)->base).x), uVar4 == uVar3)) {
          *(undefined1 *)((int)&((entity_t *)Entities)[uVar7].base.entity + 1) = 1;
          *(undefined1 *)((int)&((entity_t *)Entities)[uVar6].base.entity + 1) = 1;
          break;
        }
      }
    }
    uVar7 = uVar7 + 1;
  } while( true );
}



/* 5943:0196 */

/* [R6] touches Entities */

char __cdecl16far ovc24_usesEntities(int entityIndex)

{
  byte bVar1;
  char cVar2;
  entity_t *peVar3;
  undefined2 uVar4;
  char cStack_3;
  
  bVar1 = ovr_agnt_compute8((agnt_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(Entities) + 2)),(entity_t *)Entities + entityIndex));
  uVar4 = (undefined2)((ulong)Entities >> 0x10);
  peVar3 = (entity_t *)Entities;
  cStack_3 = peVar3[entityIndex].base.level + bVar1 +
             *(char *)((int)&worldMenuLabels[8].ofs + 1 +
                      (uint)peVar3[entityIndex].base.gindex * 0x95) +
             *(char *)((int)&worldMenuLabels[8].seg + 1 +
                      (uint)peVar3[entityIndex].base.gindex * 0x95) + '\t';
  cVar2 = ovr_stats_compute4((agnt_t *)CONCAT22(uVar4,peVar3 + entityIndex));
  cStack_3 = cStack_3 - cVar2;
  if (cStack_3 < '\0') {
    cStack_3 = '\0';
  }
  return cStack_3;
}



/* 5943:026e */

/* [R2] string "kill 3\r" */

void __cdecl16far ovc24_textKill(uint entityIndex)

{
  uint *puVar1;
  uint8_t *puVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  long *plVar7;
  uint16_t uVar8;
  uint16_t uVar9;
  uint16_t uVar10;
  char *pcVar11;
  uint16_t uVar12;
  entity_t *peVar13;
  undefined2 unaff_SI;
  uint entityIndex_00;
  uint uVar14;
  undefined2 unaff_DI;
  undefined2 uVar15;
  uint16_t unaff_SS;
  long lVar16;
  undefined1 uVar17;
  undefined1 uVar18;
  undefined1 uVar19;
  undefined1 uVar20;
  undefined1 uVar21;
  undefined1 uVar22;
  uint8_t *puVar23;
  byte *pbVar24;
  undefined1 uVar25;
  undefined1 uVar26;
  undefined2 uVar27;
  long in_stack_0000ffd2;
  byte bVar29;
  ulong uVar28;
  int iStack_2a;
  undefined4 uStack_28;
  uint8_t factionMax [4];
  long *plStack_18;
  int iStack_16;
  char cStack_12;
  byte bStack_10;
  uint uStack_a;
  uint uStack_8;
  
  uVar15 = (undefined2)((ulong)Entities >> 0x10);
  uVar12 = ((entity_t *)Entities)[entityIndex].base.y;
  uVar5 = alignUp4((((entity_t *)Entities + entityIndex)->base).x);
  _fmemset(&stack0xffd4,unaff_SS,0);
  _fmemset(factionMax + 2,unaff_SS,0xff81);
  _fmemset(factionMax,unaff_SS,0xff81);
  uVar14 = entityIndex;
  do {
    entityIndex_00 = uVar14;
    uVar15 = (undefined2)((ulong)Entities >> 0x10);
    bVar29 = ((entity_t *)Entities)[entityIndex_00].base.gindex;
    *(undefined1 *)((int)&((entity_t *)Entities)[entityIndex_00].base.entity + 2) = 1;
    bVar3 = *(byte *)((int)(char **)GMenuStrings + (uint)bVar29 * 0x95 + 0x1f);
    bVar4 = ovc24_usesEntities(entityIndex_00);
    uVar6 = (uint)bVar4 * (uint)bVar4 * (uint)((entity_t *)Entities)[entityIndex_00].base.animFrame;
    puVar1 = (uint *)(&stack0xffd4 + (uint)bVar3 * 4);
    uVar14 = *puVar1;
    *puVar1 = *puVar1 + uVar6;
    (&iStack_2a)[(uint)bVar3 * 2] =
         (&iStack_2a)[(uint)bVar3 * 2] + ((int)uVar6 >> 0xf) + (uint)CARRY2(uVar14,uVar6);
    if (((*(uint *)((int)&worldMenuLabels[6].seg + 1 + (uint)bVar29 * 0x95) & 8) == 0) &&
       ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)bVar29 * 0x95) & 0x20) == 0)) {
      puVar23 = factionMax + bVar3;
      bVar4 = ovr_agnt_compute8((agnt_t *)
                                CONCAT13((char)((ulong)Entities >> 0x18),
                                         CONCAT12((char)((ulong)Entities >> 0x10),
                                                  (entity_t *)Entities + entityIndex_00)));
      if ((char)*puVar23 < (char)bVar4) {
        pbVar24 = factionMax + bVar3;
        bVar4 = ovr_agnt_compute8((agnt_t *)
                                  CONCAT13((char)((ulong)Entities >> 0x18),
                                           CONCAT12((char)((ulong)Entities >> 0x10),
                                                    (entity_t *)Entities + entityIndex_00)));
        *pbVar24 = bVar4;
      }
    }
    if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 + (uint)bVar29 * 0x95) & 8) == 0) {
      puVar23 = factionMax + bVar3 + 2;
      bVar4 = ovr_agnt_compute8((agnt_t *)
                                CONCAT13((char)((ulong)Entities >> 0x18),
                                         CONCAT12((char)((ulong)Entities >> 0x10),
                                                  (entity_t *)Entities + entityIndex_00)));
      if ((char)*puVar23 < (char)bVar4) {
        pbVar24 = factionMax + bVar3 + 2;
        bVar4 = ovr_agnt_compute8((agnt_t *)
                                  CONCAT13((char)((ulong)Entities >> 0x18),
                                           CONCAT12((char)((ulong)Entities >> 0x10),
                                                    (entity_t *)Entities + entityIndex_00)));
        *pbVar24 = bVar4;
      }
    }
    if (((char)factionMax[bVar3 + 2] < '\x02') &&
       ((*(uint *)((int)&worldMenuLabels[6].seg + 1 + (uint)bVar29 * 0x95) & 2) != 0)) {
      factionMax[bVar3 + 2] = 0x2;
    }
    uVar14 = entityIndex_00;
    if ((((char)factionMax[bVar3] < '\x02') &&
        ((*(uint *)((int)&worldMenuLabels[6].seg + 1 + (uint)bVar29 * 0x95) & 2) != 0)) &&
       (4 < ((entity_t *)Entities)[entityIndex_00].base.level)) {
      factionMax[bVar3] = 0x2;
    }
    do {
      uVar14 = uVar14 + 1;
      if (EntityCount <= uVar14) break;
      uVar15 = (undefined2)((ulong)Entities >> 0x10);
    } while ((((entity_t *)Entities)[uVar14].base.y != uVar12) ||
            (uVar6 = alignUp4((((entity_t *)Entities + uVar14)->base).x), uVar6 != uVar5));
  } while (uVar14 < EntityCount);
  iStack_16 = 0;
  plStack_18 = (long *)"Time passes...";
  plVar7 = (long *)((ulong)in_stack_0000ffd2 >> 0x10);
  if ((-1 < iStack_2a) && ((0 < iStack_2a || ((long *)"Time passes..." < plVar7)))) {
    iStack_16 = iStack_2a;
    plStack_18 = plVar7;
  }
  if ((iStack_16 <= (*(uint16_t *)((uint8_t *)&(uStack_28) + 2))) &&
     ((iStack_16 < (*(uint16_t *)((uint8_t *)&(uStack_28) + 2)) || (plStack_18 < (long *)uStack_28)))) {
    iStack_16 = (*(uint16_t *)((uint8_t *)&(uStack_28) + 2));
    plStack_18 = (long *)uStack_28;
  }
  uVar21 = (undefined1)iStack_16;
  uVar25 = (undefined1)((uint)iStack_16 >> 8);
  uVar17 = SUB21(plStack_18,0);
  uVar19 = (undefined1)((uint)plStack_18 >> 8);
  uVar15 = 0;
  uVar18 = uVar17;
  uVar20 = uVar19;
  uVar22 = uVar21;
  uVar26 = uVar25;
  plVar7 = LXMUL_at_(plStack_18,CONCAT22(unaff_SI,unaff_DI),in_stack_0000ffd2);
  uVar27 = (undefined2)in_stack_0000ffd2;
  lVar16 = LDIV_at_(CONCAT13((char)((uint)uVar15 >> 8),CONCAT12((char)uVar15,plVar7)),
                    CONCAT13(uVar26,CONCAT12(uVar22,CONCAT11(uVar20,uVar18))));
  iStack_2a = (int)((ulong)(lVar16 + 0x14) >> 0x10);
  lVar16 = CONCAT22((int)(lVar16 + 0x14),uVar27);
  uVar15 = 0;
  plVar7 = LXMUL_at_(plStack_18,CONCAT22(unaff_SI,unaff_DI),lVar16);
  uVar10 = (uint16_t)((ulong)lVar16 >> 0x10);
  uStack_28 = LDIV_at_(CONCAT13((char)((uint)uVar15 >> 8),CONCAT12((char)uVar15,plVar7)),
                       CONCAT13(uVar25,CONCAT12(uVar21,CONCAT11(uVar19,uVar17))));
  uStack_28 = uStack_28 + 0x14;
  uVar8 = ovr_randBelow(uVar10);
  uVar9 = ovr_randBelow((uint16_t)(long *)uStack_28);
  uVar10 = ovr_randBelow(uVar10);
  uStack_8 = uVar10 & 0xff;
  uVar10 = ovr_randBelow((uint16_t)(long *)uStack_28);
  uVar14 = uVar10 & 0xff;
  if ((uVar9 & 0xff) < (uVar8 & 0xff)) {
    uStack_8 = uStack_8 / (uVar14 + 1);
    bStack_10 = 1;
  }
  else {
    if (uVar14 <= uStack_8) {
      return;
    }
    uStack_8 = uVar14 / (uStack_8 + 1);
    bStack_10 = 0;
  }
  uStack_8 = uStack_8 + 1;
  if (2 < uStack_8) {
    uStack_8 = 2;
  }
  uVar28 = 0xff00;
  uVar14 = 0xffff;
  uStack_a = 0xffff;
  do {
    if ((int)entityIndex_00 < (int)entityIndex) {
      if (uStack_a != 0xffff) {
        if (uVar14 == 0xffff) {
          ovr_attact_usesRandBelow
                    ((agnt_t *)
                     CONCAT13((char)((ulong)Entities >> 0x18),
                              CONCAT12((char)((ulong)Entities >> 0x10),
                                       (entity_t *)Entities + uStack_a)),
                     ((entity_t *)Entities)[uStack_a].base.target);
          ovr_attact_usesEntities(uStack_a,0,0,0,0);
          uVar15 = (undefined2)((ulong)Entities >> 0x10);
          if (*(char *)((int)(char **)GMenuStrings +
                       (uint)((entity_t *)Entities)[uStack_a].base.gindex * 0x95 + 0x1f) == '\0') {
            alignUp4((((entity_t *)Entities + entityIndex)->base).x);
            uVar12 = 0x195d;
            pcVar11 = ovr_fmVsprintf((char *)
                                     "Intelligence reports %s unit fleeing from battle. (%d, %d)",
                                     (char *)"puppetmaker" + 3);
            ovr_uiNotify(pcVar11,uVar12);
          }
        }
        else {
          if (((entity_t *)Entities)[uVar14].base.animFrame <= uStack_8) {
            uStack_8 = (uint)((entity_t *)Entities)[uVar14].base.animFrame;
          }
          ((entity_t *)Entities)[uVar14].base.animFrame =
               ((entity_t *)Entities)[uVar14].base.animFrame - (byte)uStack_8;
          ovr_ovc41_compute4((agnt_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(Entities) + 2)),(entity_t *)Entities + uVar14),
                             (byte)uStack_8,(byte)((entity_t *)Entities + uStack_a),
                             (agnt_t *)CONCAT22(unaff_DI,(*(uint16_t *)((uint8_t *)&(Entities) + 2))));
          ovr_ovc25_attackingNotice(*(byte *)((int)&((entity_t *)Entities)[uVar14].base.entity + 3))
          ;
          if (((entity_t *)Entities)[uVar14].base.animFrame != 0x0) {
            ovc24_usesLDIV_at_(uVar14);
            uVar15 = (undefined2)((ulong)Entities >> 0x10);
            peVar13 = (entity_t *)Entities;
            if (((*(uint *)((int)&worldMenuLabels[7].ofs + 1 +
                           (uint)peVar13[uStack_a].base.gindex * 0x95) & 4) != 0) &&
               ((*(uint *)((int)&peVar13[uVar14].base.frames + 1) & 1) == 0)) {
              uVar5 = ovr_ovc27_rollToHitAgent
                                (CONCAT13((char)((ulong)Entities >> 0x18),
                                          CONCAT12((char)((ulong)Entities >> 0x10),peVar13 + uVar14)
                                         ),0);
              if ((uVar5 & 0xff) == 0) {
                puVar1 = (uint *)((int)&((entity_t *)Entities)[uVar14].base.frames + 1);
                *puVar1 = *puVar1 | 1;
                alignUp4((((entity_t *)Entities + entityIndex)->base).x);
                uVar12 = 0x195d;
                pcVar11 = ovr_fmVsprintf((char *)
                                         "Intelligence reports %s unit infected with disease. (%d, %d)"
                                         ,(char *)"puppetmaker" + 3);
                ovr_uiNotify(pcVar11,uVar12);
              }
            }
            if ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 +
                          (uint)((entity_t *)Entities)[uStack_a].base.gindex * 0x95) & 0xc00) != 0)
            {
              uVar5 = ovr_ovc27_rollToHitAgent
                                (CONCAT13((char)((ulong)Entities >> 0x18),
                                          CONCAT12((char)((ulong)Entities >> 0x10),
                                                   (entity_t *)Entities + uVar14)),3);
              if ((uVar5 & 0xff) == 0) {
                if ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 +
                              (uint)((entity_t *)Entities)[uStack_a].base.gindex * 0x95) & 0x800) ==
                    0) {
                  cStack_12 = '\x01';
                }
                else {
                  cStack_12 = '\x02';
                }
                uVar15 = ovr_ovc27_compute3(CONCAT13((char)((ulong)Entities >> 0x18),
                                                     CONCAT12((char)((ulong)Entities >> 0x10),
                                                              (entity_t *)Entities + uVar14)),
                                            cStack_12);
                if ((char)uVar15 != '\0') {
                  if (DebugVerbose != false) {
                    printf("kill 3\r");
                  }
                  uVar15 = (undefined2)((ulong)Entities >> 0x10);
                  if (((entity_t *)Entities)[uVar14].base.animFrame != 0x0) {
                    puVar2 = &((entity_t *)Entities)[uVar14].base.animFrame;
                    *puVar2 = *puVar2 + 0xff;
                  }
                }
                alignUp4((((entity_t *)Entities + entityIndex)->base).x);
                uVar12 = 0x195d;
                pcVar11 = ovr_fmVsprintf((char *)
                                         "Intelligence reports %s unit drained of energy. (%d, %d)",
                                         (char *)"puppetmaker" + 3);
                ovr_uiNotify(pcVar11,uVar12);
              }
            }
          }
        }
      }
      return;
    }
    if (((entity_t *)Entities)[entityIndex].base.y == uVar12) {
      uVar6 = alignUp4((((entity_t *)Entities + entityIndex)->base).x);
      if (uVar6 == uVar5) {
        uVar15 = (undefined2)((ulong)Entities >> 0x10);
        peVar13 = (entity_t *)Entities;
        if (*(byte *)((int)(char **)GMenuStrings +
                     (uint)peVar13[entityIndex].base.gindex * 0x95 + 0x1f) == bStack_10) {
          bVar29 = (byte)(uVar28 >> 8);
          if (peVar13[entityIndex].base.level < bVar29) {
L_OVC24_5943_026e_0772:
            uVar15 = (undefined2)((ulong)Entities >> 0x10);
            bVar29 = ((entity_t *)Entities)[entityIndex].base.gindex;
            if (((((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)bVar29 * 0x95) & 0x40) == 0)
                 || ('\x01' < (char)factionMax[(bStack_10 ^ 1) + 2])) &&
                (((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)bVar29 * 0x95) & 8) == 0 ||
                 ('\0' < (char)factionMax[(bStack_10 ^ 1) + 2])))) &&
               (((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)bVar29 * 0x95) & 0x10) == 0 ||
                (-1 < (char)factionMax[bStack_10 ^ 1])))) {
              uVar28 = (ulong)CONCAT11(((entity_t *)Entities)[entityIndex].base.level,(char)uVar28);
              uVar14 = entityIndex;
            }
          }
          else if (peVar13[entityIndex].base.level == bVar29) {
            uVar8 = ovr_randBelow(3);
            if ((uVar8 & 0xff) == 0) goto L_OVC24_5943_026e_0772;
          }
        }
        else if ((byte)uVar28 < peVar13[entityIndex].base.level) {
L_OVC24_5943_026e_088A:
          uVar28 = CONCAT31((int3)(uVar28 >> 8),((entity_t *)Entities)[entityIndex].base.level);
          uStack_a = entityIndex;
        }
        else if (peVar13[entityIndex].base.level == (byte)uVar28) {
          uVar8 = ovr_randBelow(3);
          if ((uVar8 & 0xff) == 0) goto L_OVC24_5943_026e_088A;
        }
      }
    }
    entityIndex = entityIndex + 1;
  } while( true );
}



/* 5943:0d5a */

/* Kills and reports every entity except the one under the cursor, then sets GGameState = 0x20. */

void __cdecl16far ovc24_removeOtherEntities(uint8_t *reportedOut)

{
  uint uVar1;
  uint uVar2;
  char *msg;
  uint16_t dst;
  entity_t *peVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined2 in_stack_00000006;
  
  if (!GameRunning) {
    for (uVar4 = 0; uVar4 < EntityCount; uVar4 = uVar4 + 1) {
      *(undefined1 *)((int)&((entity_t *)Entities)[uVar4].base.entity + 2) = 0;
    }
    for (uVar4 = 0; uVar4 < EntityCount; uVar4 = uVar4 + 1) {
      uVar5 = (undefined2)((ulong)Entities >> 0x10);
      peVar3 = (entity_t *)Entities;
      if ((*(char *)((int)&peVar3[uVar4].base.entity + 1) != '\0') &&
         (*(char *)((int)&peVar3[uVar4].base.entity + 2) == '\0')) {
        if ((GOngoingBattle == '\0') && (peVar3[uVar4].base.y == GfxRndSeed2)) {
          uVar1 = alignUp4(((peVar3 + uVar4)->base).x);
          uVar2 = alignUp4(GfxRndSeed);
          if (uVar1 == uVar2) goto L_OVC24_5943_0d5a_0E37;
        }
        ovc24_textKill(uVar4);
      }
L_OVC24_5943_0d5a_0E37:
      ovc24_intelUnitReport(uVar4);
    }
    GGameState = 0x20;
    uVar4 = EntityCount;
    while (uVar4 = uVar4 - 1, -1 < (int)uVar4) {
      uVar5 = (undefined2)((ulong)Entities >> 0x10);
      peVar3 = (entity_t *)Entities;
      if (peVar3[uVar4].base.animFrame == 0x0) {
        if ((GOngoingBattle == '\0') &&
           (uVar5 = ovr_ovc23_isCursorAt(((peVar3 + uVar4)->base).x,peVar3[uVar4].base.y),
           (char)uVar5 != '\0')) {
          uVar1 = (uint)AgntCount;
          do {
            uVar1 = uVar1 - 1;
            if ((int)uVar1 < 0) break;
          } while (*(uint *)(uVar1 * 0x34 + 0x1b) != uVar4);
          if ((int)uVar1 < 0) {
            if (*(char *)((int)(char **)GMenuStrings +
                         (uint)((entity_t *)Entities)[uVar4].base.gindex * 0x95 + 0x1f) == '\0') {
              ovr_play_sfx(8,0);
            }
            else {
              ovr_play_sfx(11,0);
            }
            ovr_ovc15_removeEntity(uVar4);
          }
        }
        else {
          alignUp4((((entity_t *)Entities + uVar4)->base).x);
          dst = 0x195d;
          msg = ovr_fmVsprintf((char *)"Intelligence reports %s unit destroyed. (%d, %d)",
                               (char *)"puppetmaker" + 3);
          ovr_uiNotify(msg,dst);
          ovr_ovc15_removeEntity(uVar4);
        }
        *_reportedOut = 0x1;
      }
    }
  }
  return;
}



/* 5943:1007 */

/* Returns the unit index at a leader's map position. */

undefined2 __cdecl16far ovc24_unitAtLeader(byte leaderIndex)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  unit_t *puVar4;
  short sVar5;
  undefined2 uVar6;
  
  iVar3 = *(int *)((int)*(undefined4 *)((uint)leaderIndex << 2) + 0x39);
  iVar1 = *(int *)((int)*(undefined4 *)((uint)leaderIndex << 2) + 0x3b);
  bVar2 = ovr_manage_findFirstLeader();
  uVar6 = (undefined2)((ulong)GUnitGrid >> 0x10);
  if (leaderIndex == bVar2) {
    sVar5 = ((short (*) [148] [60])GUnitGrid)[-1][iVar3 + 0x92][iVar1];
  }
  else {
    sVar5 = ((short (*) [148] [60])GUnitGrid)[-1][iVar3 + 0x93][iVar1];
  }
  uVar6 = (undefined2)((ulong)GUnits >> 0x10);
  puVar4 = (unit_t *)GUnits;
  if (puVar4[sVar5].unitType == leaderIndex) {
    iVar3 = (uint)(puVar4 + sVar5)->bldType * 0x27;
    if ((*(uint *)(iVar3 + 0x121) & 4) == 0) {
      uVar6 = CONCAT11((char)((uint)iVar3 >> 8),1);
    }
    else if ((*(char *)((int)*(undefined4 *)((uint)leaderIndex << 2) + 0x3f) == '\0') &&
            (puVar4[sVar5].level == 0)) {
      uVar6 = 1;
    }
    else {
      uVar6 = 0;
    }
  }
  else {
    uVar6 = CONCAT11((char)((uint)(sVar5 * 9) >> 8),1);
  }
  return uVar6;
}



/* 5943:112e */

/* Checks every side's stronghold each turn and reports destruction, defeat or victory. */

void __cdecl16far ovc24_checkStrongholds(void)

{
  bool bVar1;
  undefined2 uVar2;
  char *pcVar3;
  uint uVar4;
  uint16_t uVar5;
  int iVar6;
  char *unaff_SS;
  uint8_t text;
  char sbuf [120];
  uint8_t outFlag;
  uint8_t excludedFlags;
  char cStack_11;
  uint uStack_10;
  uint16_t uStack_e;
  uint uStack_c;
  char cStack_a;
  byte bStack_9;
  byte bStack_8;
  byte bStack_7;
  uint uStack_6;
  char cStack_4;
  byte bStack_3;
  
  strongholdCheckPending = 0;
  cStack_4 = '\0';
  if (!GameRunning) {
    cStack_a = '\0';
    bVar1 = false;
    for (uStack_6 = 0; (int)uStack_6 < (int)(uint)GLeaderCount; uStack_6 = uStack_6 + 1) {
      if (*(char *)((int)*(undefined4 *)(uStack_6 << 2) + 0x3d) != '\0') {
        bStack_9 = *(byte *)((int)*(undefined4 *)(uStack_6 << 2) + 0x3e);
        bStack_7 = *(byte *)((int)*(undefined4 *)(uStack_6 << 2) + 0x3f);
        uStack_c = 0x1000 << (1U - (bStack_7 != 0) & 0x1f);
        bStack_8 = '\0' << (bStack_7 & 0x1f);
        uStack_e = alignUp4(*(int *)((int)*(undefined4 *)(uStack_6 << 2) + 0x39));
        uVar4 = *(uint *)((int)*(undefined4 *)(uStack_6 << 2) + 0x3b);
        uStack_10 = 0;
        for (iVar6 = -2; iVar6 < 2; iVar6 = iVar6 + 1) {
          uStack_10 = uStack_10 | (*(short (*) [60] [148])GMapFlags)[uVar4][uStack_e + iVar6];
        }
        if (((uStack_10 & bStack_8) == 0) && ((uStack_10 & uStack_c) != 0)) {
          uVar2 = ovc24_unitAtLeader((byte)uStack_6);
          if (((char)uVar2 == '\0') ||
             (pcVar3 = ovc24_textArena(uStack_e,uVar4,bStack_7), ((uint)pcVar3 & 0xff) != 0))
          goto L_OVC24_5943_112e_1255;
        }
        else {
L_OVC24_5943_112e_1255:
          if (((destroyLatchSide1 == '\0') || (bStack_7 == 0)) &&
             ((destroyLatchSide0 == '\0' || (bStack_7 != 0)))) goto L_OVC24_5943_112e_15E7;
        }
        ovr_stop_audio();
        destroyLatchSide1 = '\0';
        destroyLatchSide0 = '\0';
        bStack_3 = ovr_manage_findFirstLeader();
        if (bStack_7 == 0) {
          ovr_play_sfx(68,0);
        }
        else {
          ovr_play_sfx(44,0);
          strongholdsDestroyed = strongholdsDestroyed + 1;
          cStack_a = '\x01';
        }
        uVar5 = 0x195d;
        if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)bStack_9 * 0x95) & 0x800) == 0) {
          alignUp4(*(int *)((int)*(undefined4 *)(uStack_6 << 2) + 0x39));
          uVar5 = 0x195d;
          ovr_ovc15_capitalize((char *)CONCAT22(unaff_SS,&text));
          pcVar3 = ovr_stsprintf(sbuf,unaff_SS,(char *)"%s stronghold destroyed. (%d, %d)");
          ovr_uiNotify(pcVar3,uVar5);
        }
        else {
          alignUp4(*(int *)((int)*(undefined4 *)(uStack_6 << 2) + 0x39));
          pcVar3 = ovr_stsprintf(sbuf,unaff_SS,(char *)"Mindark\'s keep destroyed. (%d, %d)");
          ovr_uiNotify(pcVar3,uVar5);
        }
        if (bStack_3 == uStack_6) {
          ovr_createConstructionRecordFar
                    (0,*(int *)((int)*(undefined4 *)(uStack_6 << 2) + 0x39) + -2,uVar4,&outFlag,
                     (byte)unaff_SS,-1);
        }
        else {
          ovr_createConstructionRecordFar
                    (0,*(int *)((int)*(undefined4 *)(uStack_6 << 2) + 0x39) + -1,uVar4,&outFlag,
                     (byte)unaff_SS,-1);
        }
        CurSfxType3 = 0xff;
        *(undefined1 *)((int)*(undefined4 *)(uStack_6 << 2) + 0x3d) = 0;
        bVar1 = true;
        ovr_manage_mapPartySlots();
        ovr_font_usesMiceBlitRect(0x5a);
        _fmemset(&excludedFlags,(uint16_t)unaff_SS,0);
        if (bStack_7 == 0) {
          iVar6 = (uint)*(byte *)((int)*(undefined4 *)(uStack_6 << 2) + 0x3e) * 0x95;
          ovr_ovc40_usesAlignToSeg
                    ('\x01',(char *)*(undefined2 *)((int)&worldMenuLabels[0].seg + 1 + iVar6),
                     *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + iVar6),(char *)0x0,0,4);
        }
        else {
          uVar4 = ovr_season_checkEndGame((byte)uStack_6);
          if ((uVar4 & 0xff) == 0) {
            for (iVar6 = 0; iVar6 < (int)(uint)GLeaderCount; iVar6 = iVar6 + 1) {
              if (*(char *)((int)*(undefined4 *)(iVar6 << 2) + 0x3d) != '\0') {
                (&excludedFlags)[*(byte *)((int)*(undefined4 *)(iVar6 << 2) + 0x3f)] = 0x1;
              }
            }
            if ((((cStack_11 == '\0') && (1 < PlayerIndex)) && (GHighScoreSaved == '\0')) &&
               ((*(char *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x33) == '\x02' ||
                ((*(char *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x33) == '\x01' &&
                 (8 < *(byte *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x86))))))) {
              cStack_4 = '\x01';
            }
            if (cStack_4 == '\0') {
              iVar6 = (uint)*(byte *)((int)*(undefined4 *)(uStack_6 << 2) + 0x3e) * 0x95;
              ovr_ovc40_usesAlignToSeg
                        ('\x03',(char *)*(undefined2 *)((int)&worldMenuLabels[0].seg + 1 + iVar6),
                         *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + iVar6),(char *)0x0,0,6);
            }
            else {
              iVar6 = (uint)*(byte *)((int)*(undefined4 *)(uStack_6 << 2) + 0x3e) * 0x95;
              ovr_ovc40_usesAlignToSeg
                        ('\x02',(char *)*(undefined2 *)((int)&worldMenuLabels[0].seg + 1 + iVar6),
                         *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + iVar6),(char *)0x0,0,5);
            }
          }
        }
        ovc24_usesGLeaderCount((byte)uStack_6);
      }
L_OVC24_5943_112e_15E7:
    }
    if (bVar1) {
      bStack_3 = ovr_manage_findFirstLeader();
      _fmemset(&excludedFlags,(uint16_t)unaff_SS,0);
      for (uStack_6 = 0; (int)uStack_6 < (int)(uint)GLeaderCount; uStack_6 = uStack_6 + 1) {
        if (*(char *)((int)*(undefined4 *)(uStack_6 << 2) + 0x3d) != '\0') {
          (&excludedFlags)[*(byte *)((int)*(undefined4 *)(uStack_6 << 2) + 0x3f)] = 0x1;
        }
      }
      if ((bStack_3 == 0xff) ||
         (*(char *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x3d) == '\0')) {
        ovr_play_sfx(68,0);
        CurMusicType = 0x44;
        ovr_uiNotify((char *)"Your main stronghold has been destroyed. Game over.",0x2410);
        GGameInProgress = 1;
        ovr_ovc38_usesStshAlloc();
        ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
        ovr_stats_drawStatsPanel();
        ovr_ovc38_showAchievements();
        ovr_clearMiceProcessed();
        ovr_miceBlitRect((brect_t *)(BlitRects + 1));
        ovr_stop_audio();
        CurMusicType = 0xff;
      }
      else if ((cStack_11 == '\0') && (PlayerIndex == 1)) {
        ovr_ovc30_nextWave(1);
      }
      else if ((cStack_a != '\0') && ((cStack_11 == '\0' && (1 < PlayerIndex)))) {
        ovr_stop_audio();
        CurMusicType = 0x54;
        ovr_play_sfx(84,0);
        ovr_uiNotify((char *)"You have defeated all enemies.",0x2410);
        ovr_font_usesMiceBlitRect(messageDelayTicks << 4);
        if (cStack_4 == '\0') {
          ovr_inputUpdate((long)(int)((uint)messageDelayTicks << 4));
        }
        else {
          ovr_ovc38_usesStshAlloc();
          ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
          ovr_stats_drawStatsPanel();
          ovr_uiNotify((char *)"You may continue playing, but your score will not be recorded.",
                       0x2410);
          ovr_ovc38_showAchievements();
          ovr_clearMiceProcessed();
          ovr_ovc28_textHalflingCastle();
          ovr_ovc41_usesGMenuItem();
          ovr_miceBlitRect((brect_t *)(BlitRects + 1));
        }
        CurMusicType = 0xff;
        ovr_stop_audio();
      }
    }
  }
  return;
}



/* 5943:181d */

/* [R4] calls LDIV_at_ */

void __cdecl16far ovc24_usesLDIV_at_(int entityIndex)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  long *plVar5;
  int iVar6;
  byte unaff_BP;
  undefined2 unaff_SI;
  undefined2 uVar7;
  long lVar8;
  long *b;
  undefined4 in_stack_0000fffa;
  
  lVar8 = CONCAT22((int)((ulong)in_stack_0000fffa >> 0x10),unaff_SI);
  b = (long *)0x8000;
  uVar4 = rand();
  iVar6 = (int)uVar4 >> 0xf;
  plVar5 = LXLSH_at_((long *)b,lVar8,unaff_BP);
  lVar8 = LDIV_at_((long)CONCAT22(iVar6,plVar5),(long)b);
  if ((int)lVar8 == 0) {
    uVar7 = (undefined2)((ulong)Entities >> 0x10);
    if (((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                   (uint)((entity_t *)Entities)[entityIndex].base.gindex * 0x95) & 0x2000) != 0) &&
       (bVar1 = ovr_agnt_compute8((agnt_t *)CONCAT22(uVar7,(entity_t *)Entities + entityIndex)),
       -1 < (char)bVar1)) {
      uVar7 = (undefined2)((ulong)Entities >> 0x10);
      cVar2 = ((entity_t *)Entities)[entityIndex].dir - ((entity_t *)Entities)[entityIndex].dir % 6;
      cVar3 = ovr_ovc22_compute3(bVar1 - 1);
      ((entity_t *)Entities)[entityIndex].dir = cVar2 + cVar3;
    }
  }
  return;
}



/* 5943:190b */

/* [R6] touches GLeaderCount, EntityCount */

void __cdecl16far ovc24_usesGLeaderCount(byte leaderIndex)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  undefined2 uVar6;
  uint uStack_a;
  uint uStack_8;
  byte bStack_6;
  byte bStack_5;
  uint uStack_4;
  
  uStack_8 = 0xffff;
  uStack_a = 0xffff;
  bStack_5 = 0xff;
  bStack_6 = 0xff;
  if (*(char *)((int)*(undefined4 *)((uint)leaderIndex << 2) + 0x3f) == '\0') {
    for (bVar3 = 0; bVar3 < GLeaderCount; bVar3 = bVar3 + 1) {
      if (((*(char *)((int)*(undefined4 *)((uint)bVar3 << 2) + 0x3d) != '\0') &&
          (*(char *)((int)*(undefined4 *)((uint)bVar3 << 2) + 0x3f) ==
           *(char *)((int)*(undefined4 *)((uint)leaderIndex << 2) + 0x3f))) &&
         (uVar1 = *(int *)((int)*(undefined4 *)((uint)bVar3 << 2) + 0x39) -
                  *(int *)((int)*(undefined4 *)((uint)leaderIndex << 2) + 0x39),
         uVar4 = (int)uVar1 >> 0xf,
         uVar2 = *(int *)((int)*(undefined4 *)((uint)bVar3 << 2) + 0x3b) -
                 *(int *)((int)*(undefined4 *)((uint)leaderIndex << 2) + 0x3b),
         uVar5 = (int)uVar2 >> 0xf, uVar1 = ((uVar1 ^ uVar4) - uVar4) + ((uVar2 ^ uVar5) - uVar5),
         uVar1 < uStack_8)) {
        uStack_8 = uVar1;
        bStack_5 = bVar3;
      }
    }
  }
  else {
    for (bVar3 = 0; bVar3 < GLeaderCount; bVar3 = bVar3 + 1) {
      if (((*(char *)((int)*(undefined4 *)((uint)bVar3 << 2) + 0x3d) != '\0') &&
          (*(char *)((int)*(undefined4 *)((uint)bVar3 << 2) + 0x3f) == '\0')) &&
         (uVar1 = *(int *)((int)*(undefined4 *)((uint)bVar3 << 2) + 0x39) -
                  *(int *)((int)*(undefined4 *)((uint)leaderIndex << 2) + 0x39),
         uVar4 = (int)uVar1 >> 0xf,
         uVar2 = *(int *)((int)*(undefined4 *)((uint)bVar3 << 2) + 0x3b) -
                 *(int *)((int)*(undefined4 *)((uint)leaderIndex << 2) + 0x3b),
         uVar5 = (int)uVar2 >> 0xf,
         uVar1 = ((uVar1 ^ uVar4) - uVar4) + ((uVar2 ^ uVar5) - uVar5) * 2, uVar1 < uStack_a)) {
        uStack_a = uVar1;
        bStack_6 = bVar3;
      }
    }
  }
  for (uVar1 = 0; uVar1 < EntityCount; uVar1 = uVar1 + 1) {
    uVar6 = (undefined2)((ulong)Entities >> 0x10);
    if ((*(byte *)((int)&((entity_t *)Entities)[uVar1].base.entity + 3) == leaderIndex) &&
       (*(byte *)((int)&((entity_t *)Entities)[uVar1].base.entity + 3) = bStack_5, bStack_6 != 0xff)
       ) {
      ((entity_t *)Entities)[uVar1].base.destX =
           *(uint16_t *)((int)*(undefined4 *)((uint)bStack_6 << 2) + 0x39);
      ((entity_t *)Entities)[uVar1].base.destY =
           *(uint16_t *)((int)*(undefined4 *)((uint)bStack_6 << 2) + 0x3b);
    }
  }
  for (uStack_4 = 0xf8; uStack_4 < GUnitCount; uStack_4 = uStack_4 + 1) {
    uVar6 = (undefined2)((ulong)GUnits >> 0x10);
    if (((unit_t *)GUnits)[uStack_4].unitType == leaderIndex) {
      ((unit_t *)GUnits)[uStack_4].unitType = 0xff;
    }
  }
  return;
}



/* 5943:1bff */

/* Formats the per-unit intelligence report (cured/diseased/poisoned variants). */

void __cdecl16far ovc24_intelUnitReport(int entityIndex)

{
  uint *puVar1;
  bool bVar2;
  byte bVar3;
  uint uVar4;
  uint16_t uVar5;
  char *pcVar6;
  entity_t *peVar7;
  uint uVar8;
  int iVar9;
  undefined2 uVar10;
  
  uVar10 = (undefined2)((ulong)Entities >> 0x10);
  if ((*(uint *)((int)&((entity_t *)Entities)[entityIndex].base.frames + 1) & 1) != 0) {
    uVar4 = alignUp4((((entity_t *)Entities + entityIndex)->base).x);
    uVar10 = (undefined2)((ulong)Entities >> 0x10);
    peVar7 = (entity_t *)Entities;
    uVar5 = peVar7[entityIndex].base.y;
    if (*(char *)((int)&peVar7[entityIndex].base.entity + 1) == '\0') {
      bVar2 = false;
      for (uVar8 = 0; uVar8 < EntityCount; uVar8 = uVar8 + 1) {
        if (((*(uint *)((int)&worldMenuLabels[6].seg + 1 + (uint)peVar7[uVar8].base.gindex * 0x95) &
             1) != 0) && (5 < peVar7[uVar8].base.level)) {
          bVar2 = true;
          break;
        }
      }
      if (!bVar2) {
        for (iVar9 = 0; iVar9 < 4; iVar9 = iVar9 + 1) {
          bVar3 = ovr_ovc45_getUnitType(uVar4 + iVar9 + -2,uVar5);
          if ((*(uint *)((uint)bVar3 * 0x27 + 0x121) & 0x100) != 0) {
            bVar2 = true;
            break;
          }
        }
      }
      if (bVar2) {
        puVar1 = (uint *)((int)&((entity_t *)Entities)[entityIndex].base.frames + 1);
        *puVar1 = *puVar1 & 0xfffe;
        alignUp4((((entity_t *)Entities + entityIndex)->base).x);
        uVar5 = 0x195d;
        pcVar6 = ovr_fmVsprintf((char *)"Intelligence reports %s unit cured of disease. (%d, %d)",
                                (char *)"puppetmaker" + 3);
        ovr_uiNotify(pcVar6,uVar5);
        return;
      }
    }
    uVar5 = ovr_randBelow(0x28);
    if ((uVar5 & 0xff) == 0) {
      uVar4 = 0;
      while( true ) {
        uVar10 = (undefined2)((ulong)Entities >> 0x10);
        if ((EntityCount <= uVar4) ||
           ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 +
                      (uint)((entity_t *)Entities)[uVar4].base.gindex * 0x95) & 4) != 0)) break;
        uVar4 = uVar4 + 1;
      }
      if (uVar4 < EntityCount) {
        alignUp4((((entity_t *)Entities + entityIndex)->base).x);
        uVar5 = 0x195d;
        pcVar6 = ovr_fmVsprintf((char *)
                                "Intelligence reports %s unit succombs to blast spore disease. (%d, %d)"
                                ,(char *)"puppetmaker" + 3);
        ovr_uiNotify(pcVar6,uVar5);
        uVar10 = (undefined2)((ulong)Entities >> 0x10);
        ovr_ovc15_usesLDIV_at_2
                  (entityIndex,((entity_t *)Entities)[uVar4].base.gindex,
                   *(char *)((int)&((entity_t *)Entities)[uVar4].base.entity + 3));
      }
    }
  }
  return;
}



/* 5943:1eeb */

/* [R2] string "arena" */

char * __cdecl16far ovc24_textArena(uint16_t x,uint y,char faction)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  
  if (GOngoingBattle == '\0') {
    uVar2 = GfxRndSeed2;
    if (GfxRndSeed2 == y) {
      uVar1 = alignUp4(x);
      uVar2 = alignUp4(GfxRndSeed);
      if (uVar1 == uVar2) {
        iVar4 = 0;
        while( true ) {
          if ((int)(uint)AgntCount <= iVar4) {
            return (char *)0x0;
          }
          if (((*(uint *)(iVar4 * 0x34 + 0x2b) & 0xae4) == 0) &&
             (*(char *)(iVar4 * 0x34 + 0x2f) == faction)) break;
          iVar4 = iVar4 + 1;
        }
        return (char *)CONCAT11((char)((uint)(iVar4 * 0x34) >> 8),1);
      }
    }
    pcVar3 = (char *)(uVar2 & 0xff00);
  }
  else {
    pcVar3 = (char *)"arena" + 4;
  }
  return pcVar3;
}


