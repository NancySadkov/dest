/*
 * ovc24_entities.c - recovered from STRONG.EXE
 * memory block: OVC24_entities.c
 * range: 5943:000e - 5943:222f
 * functions: 10
 */
#include "recovered.h"


/* 5943:000e */

/* [R4] calls alignUp4 */

void __cdecl16far ovc24_usesAlignUp4(void...)

{
  char cVar1;
  uint16_t uVar2;
  uint uVar3;
  uint uVar4;
  entity_t *peVar5;
  uint uVar6;
  int unaff_DI;
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
      uVar3 = alignUp4(unaff_DI,((peVar5 + uVar7)->base).x);
      uVar2 = ((entity_t *)Entities)[uVar7].base.y;
      for (uVar6 = 0; uVar6 < EntityCount; uVar6 = uVar6 + 1) {
        uVar8 = (undefined2)((ulong)Entities >> 0x10);
        peVar5 = (entity_t *)Entities;
        if (((peVar5[uVar6].base.y == uVar2) &&
            (*(char *)((int)(char **)GMenuStrings + (uint)peVar5[uVar6].base.gindex * 0x95 + 0x1f)
             != cVar1)) && (uVar4 = alignUp4(unaff_DI,((peVar5 + uVar6)->base).x), uVar4 == uVar3))
        {
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
  undefined2 uVar2;
  entity_t *peVar3;
  undefined2 unaff_SI;
  agnt_t *paVar4;
  char cStack_3;
  
  bVar1 = ovr_agnt_compute8((agnt_t *)CONCAT22(unaff_SI,(*(uint16_t *)((uint8_t *)&(Entities) + 2))),
                            (entity_t *)Entities + entityIndex);
  paVar4 = (agnt_t *)((ulong)Entities >> 0x10);
  peVar3 = (entity_t *)Entities;
  uVar2 = CONCAT11((char)((uint)(entityIndex * 0x37) >> 8),
                   peVar3[entityIndex].base.level + bVar1 +
                   *(char *)((int)&worldMenuLabels[8].ofs + 1 +
                            (uint)peVar3[entityIndex].base.gindex * 0x95) +
                   *(char *)((int)&worldMenuLabels[8].seg + 1 +
                            (uint)peVar3[entityIndex].base.gindex * 0x95) + '\t');
  cStack_3 = ovr_stats_compute4((agnt_t *)CONCAT22(uVar2,paVar4),peVar3 + entityIndex);
  cStack_3 = (char)uVar2 - cStack_3;
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
  uint16_t uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  long *plVar8;
  uint16_t uVar9;
  uint16_t uVar10;
  uint16_t uVar11;
  int iVar12;
  char *pcVar13;
  entity_t *peVar14;
  undefined2 unaff_SI;
  uint entityIndex_00;
  uint uVar15;
  int unaff_DI;
  undefined2 uVar16;
  uint unaff_SS;
  long lVar17;
  undefined1 uVar18;
  undefined1 uVar19;
  undefined1 uVar20;
  undefined1 uVar21;
  undefined1 uVar22;
  uint8_t *puVar23;
  byte *pbVar24;
  undefined1 uVar25;
  undefined1 uVar26;
  undefined1 uVar27;
  long a;
  undefined2 uVar28;
  long in_stack_0000ffd2;
  byte bVar30;
  ulong uVar29;
  long *plStack_2a;
  undefined4 uStack_28;
  uint8_t factionMax [4];
  uint uStack_18;
  long *plStack_16;
  undefined1 uStack_12;
  byte bStack_10;
  uint uStack_a;
  uint uStack_8;
  
  a = CONCAT22(unaff_SI,unaff_DI);
  uVar16 = (undefined2)((ulong)Entities >> 0x10);
  uVar4 = ((entity_t *)Entities)[entityIndex].base.y;
  uVar6 = alignUp4(unaff_DI,(char)(((entity_t *)Entities + entityIndex)->base).x);
  _fmemset((void *)(ulong)unaff_SS,8,(uint16_t)a);
  _fmemset((void *)CONCAT13(0xff,CONCAT12(0x81,unaff_SS)),2,(uint16_t)a);
  _fmemset((void *)CONCAT13(0xff,CONCAT12(0x81,unaff_SS)),2,(uint16_t)a);
  uVar15 = entityIndex;
  do {
    entityIndex_00 = uVar15;
    uVar16 = (undefined2)((ulong)Entities >> 0x10);
    bVar30 = ((entity_t *)Entities)[entityIndex_00].base.gindex;
    *(undefined1 *)((int)&((entity_t *)Entities)[entityIndex_00].base.entity + 2) = 1;
    bVar3 = *(byte *)((int)(char **)GMenuStrings + (uint)bVar30 * 0x95 + 0x1f);
    bVar5 = ovc24_usesEntities(entityIndex_00);
    uVar16 = (undefined2)((ulong)Entities >> 0x10);
    uVar7 = (uint)bVar5 * (uint)bVar5 * (uint)((entity_t *)Entities)[entityIndex_00].base.animFrame;
    puVar1 = (uint *)(&stack0xffd4 + (uint)bVar3 * 4);
    uVar15 = *puVar1;
    *puVar1 = *puVar1 + uVar7;
    (&plStack_2a)[(uint)bVar3 * 2] =
         (long *)((int)(&plStack_2a)[(uint)bVar3 * 2] +
                 (uint)CARRY2(uVar15,uVar7) + ((int)uVar7 >> 0xf));
    if (((*(uint *)((int)&worldMenuLabels[6].seg + 1 + (uint)bVar30 * 0x95) & 8) == 0) &&
       ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)bVar30 * 0x95) & 0x20) == 0)) {
      puVar23 = factionMax + bVar3;
      bVar5 = ovr_agnt_compute8((agnt_t *)
                                CONCAT13((char)((uint)puVar23 >> 8),CONCAT12((char)puVar23,uVar16)),
                                (entity_t *)Entities + entityIndex_00);
      if ((char)*puVar23 < (char)bVar5) {
        pbVar24 = factionMax + bVar3;
        bVar5 = ovr_agnt_compute8((agnt_t *)
                                  CONCAT13((char)((uint)pbVar24 >> 8),
                                           CONCAT12((char)pbVar24,(*(uint16_t *)((uint8_t *)&(Entities) + 2)))),
                                  (entity_t *)Entities + entityIndex_00);
        *pbVar24 = bVar5;
      }
    }
    if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 + (uint)bVar30 * 0x95) & 8) == 0) {
      puVar23 = factionMax + bVar3 + 2;
      bVar5 = ovr_agnt_compute8((agnt_t *)
                                CONCAT13((char)((uint)puVar23 >> 8),
                                         CONCAT12((char)puVar23,(*(uint16_t *)((uint8_t *)&(Entities) + 2)))),
                                (entity_t *)Entities + entityIndex_00);
      if ((char)*puVar23 < (char)bVar5) {
        pbVar24 = factionMax + bVar3 + 2;
        bVar5 = ovr_agnt_compute8((agnt_t *)
                                  CONCAT13((char)((uint)pbVar24 >> 8),
                                           CONCAT12((char)pbVar24,(*(uint16_t *)((uint8_t *)&(Entities) + 2)))),
                                  (entity_t *)Entities + entityIndex_00);
        *pbVar24 = bVar5;
      }
    }
    if (((char)factionMax[bVar3 + 2] < '\x02') &&
       ((*(uint *)((int)&worldMenuLabels[6].seg + 1 + (uint)bVar30 * 0x95) & 2) != 0)) {
      factionMax[bVar3 + 2] = 0x2;
    }
    uVar15 = entityIndex_00;
    if ((((char)factionMax[bVar3] < '\x02') &&
        ((*(uint *)((int)&worldMenuLabels[6].seg + 1 + (uint)bVar30 * 0x95) & 2) != 0)) &&
       (4 < ((entity_t *)Entities)[entityIndex_00].base.level)) {
      factionMax[bVar3] = 0x2;
    }
    do {
      uVar15 = uVar15 + 1;
      if (EntityCount <= uVar15) break;
      uVar16 = (undefined2)((ulong)Entities >> 0x10);
    } while ((((entity_t *)Entities)[uVar15].base.y != uVar4) ||
            (uVar7 = alignUp4((int)a,(char)(((entity_t *)Entities + uVar15)->base).x),
            uVar7 != uVar6));
  } while (uVar15 < EntityCount);
  plStack_16 = (long *)0x0;
  uStack_18 = 200;
  uVar15 = (uint)((ulong)in_stack_0000ffd2 >> 0x10);
  if ((-1 < (int)plStack_2a) && ((0 < (int)plStack_2a || (200 < uVar15)))) {
    plStack_16 = plStack_2a;
    uStack_18 = uVar15;
  }
  if (((int)plStack_16 <= (int)(*(uint16_t *)((uint8_t *)&(uStack_28) + 2))) &&
     (((int)plStack_16 < (int)(*(uint16_t *)((uint8_t *)&(uStack_28) + 2)) || (uStack_18 < (uint)uStack_28)))) {
    plStack_16 = (*(uint16_t *)((uint8_t *)&(uStack_28) + 2));
    uStack_18 = (uint)uStack_28;
  }
  uVar20 = SUB21(plStack_16,0);
  uVar25 = (undefined1)((uint)plStack_16 >> 8);
  uVar18 = (undefined1)uStack_18;
  uVar19 = (undefined1)(uStack_18 >> 8);
  uVar16 = 0;
  uVar22 = uVar18;
  uVar27 = uVar19;
  uVar21 = uVar20;
  uVar26 = uVar25;
  plVar8 = LXMUL_at_(plStack_16,a,in_stack_0000ffd2);
  uVar28 = (undefined2)in_stack_0000ffd2;
  lVar17 = LDIV_at_((long)CONCAT22(uVar16,plVar8),
                    CONCAT13(uVar26,CONCAT12(uVar21,CONCAT11(uVar27,uVar22))));
  plStack_2a = (long *)((ulong)(lVar17 + 0x14) >> 0x10);
  lVar17 = CONCAT22((int)(lVar17 + 0x14),uVar28);
  uVar16 = 0;
  plVar8 = LXMUL_at_(plStack_16,a,lVar17);
  uVar22 = (undefined1)((ulong)lVar17 >> 0x10);
  uStack_28 = LDIV_at_((long)CONCAT22(uVar16,plVar8),
                       CONCAT13(uVar25,CONCAT12(uVar20,CONCAT11(uVar19,uVar18))));
  uStack_28 = uStack_28 + 0x14;
  uVar9 = ovr_randBelow((uint16_t)a,uVar22);
  uVar10 = ovr_randBelow((uint16_t)a,(char)uStack_28);
  uVar11 = ovr_randBelow((uint16_t)a,uVar22);
  uStack_8 = uVar11 & 0xff;
  uVar11 = ovr_randBelow((uint16_t)a,(char)uStack_28);
  uVar15 = uVar11 & 0xff;
  if ((uVar10 & 0xff) < (uVar9 & 0xff)) {
    uStack_8 = uStack_8 / (uVar15 + 1);
    bStack_10 = 1;
  }
  else {
    if (uVar15 <= uStack_8) {
      return;
    }
    uStack_8 = uVar15 / (uStack_8 + 1);
    bStack_10 = 0;
  }
  uStack_8 = uStack_8 + 1;
  if (2 < uStack_8) {
    uStack_8 = 2;
  }
  uVar29 = 0xff00;
  uVar15 = 0xffff;
  uStack_a = 0xffff;
  do {
    uVar9 = (uint16_t)a;
    if ((int)entityIndex_00 < (int)entityIndex) {
      if (uStack_a != 0xffff) {
        if (uVar15 == 0xffff) {
          ovr_attact_usesRandBelow
                    ((agnt_t *)
                     CONCAT13((char)(uStack_a * 0x37 >> 8),
                              CONCAT12(((entity_t *)Entities)[uStack_a].base.target,(*(uint16_t *)((uint8_t *)&(Entities) + 2))))
                     ,(byte)a,(entity_t *)Entities + uStack_a);
          ovr_attact_usesEntities();
          uVar16 = (undefined2)((ulong)Entities >> 0x10);
          peVar14 = (entity_t *)Entities;
          bVar30 = peVar14[uStack_a].base.gindex;
          if (*(char *)((int)(char **)GMenuStrings + (uint)bVar30 * 0x95 + 0x1f) == '\0') {
            uVar22 = 0;
            uVar27 = 0xa0;
            uVar15 = alignUp4(peVar14[entityIndex].base.y,((peVar14 + entityIndex)->base).x);
            iVar12 = (uint)bVar30 * 0x95;
            uVar16 = 0x195d;
            pcVar13 = ovr_fmVsprintf((char *)CONCAT22(*(undefined2 *)
                                                       ((int)&worldMenuLabels[0].seg + 1 + iVar12),
                                                      (char *)"puppetmaker" + 3),
                                     (char *)CONCAT22(uVar15,(char *)*(undefined2 *)
                                                                      ((int)&worldMenuLabels[1].ofs
                                                                       + 1 + iVar12)));
            ovr_uiNotify((char *)CONCAT13(uVar27,CONCAT12(uVar22,uVar16)),uVar9,pcVar13);
          }
        }
        else {
          if (((entity_t *)Entities)[uVar15].base.animFrame <= uStack_8) {
            uStack_8 = (uint)((entity_t *)Entities)[uVar15].base.animFrame;
          }
          ((entity_t *)Entities)[uVar15].base.animFrame =
               ((entity_t *)Entities)[uVar15].base.animFrame - (char)uStack_8;
          ovr_ovc41_compute4();
          ovr_ovc25_attackingNotice
                    ((byte)uVar9,
                     *(undefined1 *)((int)&((entity_t *)Entities)[uVar15].base.entity + 3));
          if (((entity_t *)Entities)[uVar15].base.animFrame != 0x0) {
            ovc24_usesLDIV_at_(uVar15);
            uVar6 = (uint)((ulong)Entities >> 0x10);
            peVar14 = (entity_t *)Entities;
            if (((*(uint *)((int)&worldMenuLabels[7].ofs + 1 +
                           (uint)peVar14[uStack_a].base.gindex * 0x95) & 4) != 0) &&
               ((*(uint *)((int)&peVar14[uVar15].base.frames + 1) & 1) == 0)) {
              uVar6 = ovr_ovc27_rollToHitAgent((ulong)uVar6,(byte)uVar9,peVar14 + uVar15);
              if ((uVar6 & 0xff) == 0) {
                puVar1 = (uint *)((int)&((entity_t *)Entities)[uVar15].base.frames + 1);
                *puVar1 = *puVar1 | 1;
                uVar22 = 0;
                uVar27 = 0xa0;
                uVar16 = (undefined2)((ulong)Entities >> 0x10);
                uVar6 = alignUp4(((entity_t *)Entities)[entityIndex].base.y,
                                 (((entity_t *)Entities + entityIndex)->base).x);
                iVar12 = (uint)((entity_t *)Entities)[uVar15].base.gindex * 0x95;
                uVar16 = 0x195d;
                pcVar13 = ovr_fmVsprintf((char *)CONCAT22(*(undefined2 *)
                                                           ((int)&worldMenuLabels[0].seg + 1 +
                                                           iVar12),(char *)"puppetmaker" + 3),
                                         (char *)CONCAT22(uVar6,(char *)*(undefined2 *)
                                                                         ((int)&worldMenuLabels[1].
                                                                                ofs + 1 + iVar12)));
                ovr_uiNotify((char *)CONCAT13(uVar27,CONCAT12(uVar22,uVar16)),uVar9,pcVar13);
              }
            }
            uVar16 = (undefined2)((ulong)Entities >> 0x10);
            if ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 +
                          (uint)((entity_t *)Entities)[uStack_a].base.gindex * 0x95) & 0xc00) != 0)
            {
              uVar6 = ovr_ovc27_rollToHitAgent
                                ((ulong)CONCAT12(3,uVar16),(byte)uVar9,(entity_t *)Entities + uVar15
                                );
              if ((uVar6 & 0xff) == 0) {
                uVar16 = (undefined2)((ulong)Entities >> 0x10);
                iVar12 = (uint)((entity_t *)Entities)[uStack_a].base.gindex * 0x95;
                if ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + iVar12) & 0x800) == 0) {
                  uStack_12 = 1;
                }
                else {
                  uStack_12 = 2;
                }
                uVar16 = ovr_ovc27_compute3(CONCAT13((char)((uint)iVar12 >> 8),
                                                     CONCAT12(uStack_12,uVar16)),(char)uVar9,
                                            (entity_t *)Entities + uVar15);
                if ((char)uVar16 != '\0') {
                  if (DebugVerbose != false) {
                    printf("kill 3\r");
                  }
                  uVar16 = (undefined2)((ulong)Entities >> 0x10);
                  if (((entity_t *)Entities)[uVar15].base.animFrame != 0x0) {
                    puVar2 = &((entity_t *)Entities)[uVar15].base.animFrame;
                    *puVar2 = *puVar2 + 0xff;
                  }
                }
                uVar22 = 0;
                uVar27 = 0xa0;
                uVar16 = (undefined2)((ulong)Entities >> 0x10);
                uVar6 = alignUp4(((entity_t *)Entities)[entityIndex].base.y,
                                 (((entity_t *)Entities + entityIndex)->base).x);
                iVar12 = (uint)((entity_t *)Entities)[uVar15].base.gindex * 0x95;
                uVar16 = 0x195d;
                pcVar13 = ovr_fmVsprintf((char *)CONCAT22(*(undefined2 *)
                                                           ((int)&worldMenuLabels[0].seg + 1 +
                                                           iVar12),(char *)"puppetmaker" + 3),
                                         (char *)CONCAT22(uVar6,(char *)*(undefined2 *)
                                                                         ((int)&worldMenuLabels[1].
                                                                                ofs + 1 + iVar12)));
                ovr_uiNotify((char *)CONCAT13(uVar27,CONCAT12(uVar22,uVar16)),uVar9,pcVar13);
              }
            }
          }
        }
      }
      return;
    }
    if (((entity_t *)Entities)[entityIndex].base.y == uVar4) {
      uVar7 = alignUp4(uVar9,(char)(((entity_t *)Entities + entityIndex)->base).x);
      if (uVar7 == uVar6) {
        uVar16 = (undefined2)((ulong)Entities >> 0x10);
        peVar14 = (entity_t *)Entities;
        if (*(byte *)((int)(char **)GMenuStrings +
                     (uint)peVar14[entityIndex].base.gindex * 0x95 + 0x1f) == bStack_10) {
          bVar30 = (byte)(uVar29 >> 8);
          if (peVar14[entityIndex].base.level < bVar30) {
L_OVC24_5943_026e_0772:
            uVar16 = (undefined2)((ulong)Entities >> 0x10);
            bVar30 = ((entity_t *)Entities)[entityIndex].base.gindex;
            if (((((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)bVar30 * 0x95) & 0x40) == 0)
                 || ('\x01' < (char)factionMax[(bStack_10 ^ 1) + 2])) &&
                (((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)bVar30 * 0x95) & 8) == 0 ||
                 ('\0' < (char)factionMax[(bStack_10 ^ 1) + 2])))) &&
               (((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)bVar30 * 0x95) & 0x10) == 0 ||
                (-1 < (char)factionMax[bStack_10 ^ 1])))) {
              uVar29 = (ulong)CONCAT11(((entity_t *)Entities)[entityIndex].base.level,(char)uVar29);
              uVar15 = entityIndex;
            }
          }
          else if (peVar14[entityIndex].base.level == bVar30) {
            uVar9 = ovr_randBelow((uint16_t)a,3);
            if ((uVar9 & 0xff) == 0) goto L_OVC24_5943_026e_0772;
          }
        }
        else if ((byte)uVar29 < peVar14[entityIndex].base.level) {
L_OVC24_5943_026e_088A:
          uVar29 = CONCAT31((int3)(uVar29 >> 8),((entity_t *)Entities)[entityIndex].base.level);
          uStack_a = entityIndex;
        }
        else if (peVar14[entityIndex].base.level == (byte)uVar29) {
          uVar9 = ovr_randBelow((uint16_t)a,3);
          if ((uVar9 & 0xff) == 0) goto L_OVC24_5943_026e_088A;
        }
      }
    }
    entityIndex = entityIndex + 1;
  } while( true );
}



/* 5943:0d5a */

/* Kills and reports every entity except the one under the cursor, then sets GGameState = 0x20. */

void __cdecl16far ovc24_removeOtherEntities(uint8_t *reportedOut,...)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  entity_t *peVar4;
  uint uVar5;
  undefined2 uVar6;
  undefined1 *in_stack_00000004;
  
  if (!GameRunning) {
    for (uVar5 = 0; uVar5 < EntityCount; uVar5 = uVar5 + 1) {
      *(undefined1 *)((int)&((entity_t *)Entities)[uVar5].base.entity + 2) = 0;
    }
    for (uVar5 = 0; uVar5 < EntityCount; uVar5 = uVar5 + 1) {
      uVar6 = (undefined2)((ulong)Entities >> 0x10);
      peVar4 = (entity_t *)Entities;
      if ((*(char *)((int)&peVar4[uVar5].base.entity + 1) != '\0') &&
         (*(char *)((int)&peVar4[uVar5].base.entity + 2) == '\0')) {
        if ((GOngoingBattle == '\0') && (peVar4[uVar5].base.y == GfxRndSeed2)) {
          uVar1 = alignUp4();
          uVar2 = alignUp4();
          if (uVar1 == uVar2) goto L_OVC24_5943_0d5a_0E37;
        }
        ovc24_textKill(uVar5);
      }
L_OVC24_5943_0d5a_0E37:
      ovc24_intelUnitReport(uVar5);
    }
    GGameState = 0x20;
    uVar5 = EntityCount;
    while( true ) {
      uVar5 = uVar5 - 1;
      if ((int)uVar5 < 0) break;
      if (((entity_t *)Entities)[uVar5].base.animFrame == 0x0) {
        if ((GOngoingBattle == '\0') && (uVar6 = ovr_ovc23_isCursorAt(), (char)uVar6 != '\0')) {
          uVar1 = (uint)AgntCount;
          do {
            uVar1 = uVar1 - 1;
            if ((int)uVar1 < 0) break;
          } while (*(uint *)(uVar1 * 0x34 + 0x1b) != uVar5);
          if ((int)uVar1 < 0) {
            if (*(char *)((int)(char **)GMenuStrings +
                         (uint)((entity_t *)Entities)[uVar5].base.gindex * 0x95 + 0x1f) == '\0') {
              ovr_play_sfx();
            }
            else {
              ovr_play_sfx();
            }
            ovr_ovc15_removeEntity();
          }
        }
        else {
          uVar1 = alignUp4();
          iVar3 = (uint)((entity_t *)Entities)[uVar5].base.gindex * 0x95;
          ovr_fmVsprintf((char *)CONCAT22(*(undefined2 *)((int)&worldMenuLabels[0].seg + 1 + iVar3),
                                          (char *)"puppetmaker" + 3),
                         (char *)CONCAT22(uVar1,(char *)*(undefined2 *)
                                                         ((int)&worldMenuLabels[1].ofs + 1 + iVar3))
                        );
          ovr_uiNotify();
          ovr_ovc15_removeEntity();
        }
        *(undefined1 *)CONCAT22((uint8_t *)reportedOut,in_stack_00000004) = 1;
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

void __cdecl16far ovc24_checkStrongholds(void...)

{
  byte bVar10;
  uint16_t x;
  bool bVar1;
  bool bVar2;
  undefined2 uVar3;
  char *pcVar4;
  uint uVar5;
  char *arg1;
  int iVar6;
  undefined2 unaff_DI;
  char *unaff_SS;
  undefined1 uVar7;
  undefined1 uVar8;
  byte msgDelay;
  undefined1 uVar9;
  uint8_t text;
  char sbuf [120];
  uint8_t outFlag;
  uint8_t excludedFlags;
  char cStack_11;
  uint uStack_10;
  uint uStack_e;
  uint uStack_c;
  char cStack_a;
  byte bStack_9;
  byte bStack_8;
  byte bStack_7;
  uint uStack_6;
  char cStack_4;
  byte bStack_3;
  
  msgDelay = (byte)unaff_DI;
  uVar9 = (undefined1)((uint)unaff_DI >> 8);
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
        uStack_e = alignUp4(CONCAT11(uVar9,msgDelay),
                            (char)*(undefined2 *)((int)*(undefined4 *)(uStack_6 << 2) + 0x39));
        x = *(uint16_t *)((int)*(undefined4 *)(uStack_6 << 2) + 0x3b);
        uStack_10 = 0;
        for (iVar6 = -2; iVar6 < 2; iVar6 = iVar6 + 1) {
          uStack_10 = uStack_10 | (*(short (*) [60] [148])GMapFlags)[x][uStack_e + iVar6];
        }
        if (((uStack_10 & bStack_8) == 0) && ((uStack_10 & uStack_c) != 0)) {
          uVar3 = ovc24_unitAtLeader((byte)uStack_6);
          if (((char)uVar3 == '\0') ||
             (bVar2 = ovc24_textArena(x,CONCAT11((char)((uint)uVar3 >> 8),bStack_7),msgDelay,
                                      uStack_e,bStack_7), bVar2)) goto L_OVC24_5943_112e_1255;
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
          ovr_play_sfx(0,68);
        }
        else {
          ovr_play_sfx(0,44);
          strongholdsDestroyed = strongholdsDestroyed + 1;
          cStack_a = '\x01';
        }
        uVar3 = 0x195d;
        if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)bStack_9 * 0x95) & 0x800) == 0) {
          uVar7 = 0;
          uVar8 = 0xa0;
          uVar5 = alignUp4(x,*(undefined2 *)((int)*(undefined4 *)(uStack_6 << 2) + 0x39));
          arg1 = (char *)&AgntAnms[0x88].missileDy;
          pcVar4 = ovr_ovc15_capitalize();
          pcVar4 = ovr_stsprintf((char *)CONCAT22(0x578d,unaff_SS),
                                 (char *)CONCAT22(pcVar4,(char *)"puppetmaker" + 3),arg1,sbuf,uVar5)
          ;
          ovr_uiNotify((char *)CONCAT13(uVar8,CONCAT12(uVar7,arg1)),(uint16_t)pcVar4);
        }
        else {
          uVar7 = 0;
          uVar8 = 0xa0;
          alignUp4(x,*(undefined2 *)((int)*(undefined4 *)(uStack_6 << 2) + 0x39));
          pcVar4 = ovr_stsprintf();
          ovr_uiNotify((char *)CONCAT13(uVar8,CONCAT12(uVar7,uVar3)),(uint16_t)pcVar4);
        }
        if (bStack_3 == uStack_6) {
          iVar6 = *(int *)((int)*(undefined4 *)(uStack_6 << 2) + 0x39) + -2;
          ovr_createConstructionRecordFar
                    ((byte)iVar6,x,(int)&outFlag,(uint8_t *)(ulong)CONCAT12(0xff,unaff_SS),msgDelay,
                     '\0',iVar6,0xff);
        }
        else {
          iVar6 = *(int *)((int)*(undefined4 *)(uStack_6 << 2) + 0x39) + -1;
          ovr_createConstructionRecordFar
                    ((byte)iVar6,x,(int)&outFlag,(uint8_t *)(ulong)CONCAT12(0xff,unaff_SS),msgDelay,
                     '\0',iVar6,0xff);
        }
        CurSfxType3 = 0xff;
        *(undefined1 *)((int)*(undefined4 *)(uStack_6 << 2) + 0x3d) = 0;
        bVar1 = true;
        ovr_manage_mapPartySlots();
        ovr_font_usesMiceBlitRect(msgDelay,0x5a);
        _fmemset((void *)ZEXT24(unaff_SS),2,CONCAT11(uVar9,msgDelay));
        if (bStack_7 == 0) {
          iVar6 = (uint)*(byte *)((int)*(undefined4 *)(uStack_6 << 2) + 0x3e) * 0x95;
                    /* WARNING: Load size is inaccurate */
          _bVar10 = *(byte *)((int)&worldMenuLabels[0].seg + 1 + iVar6);
          ovr_ovc40_usesAlignToSeg
                    ((byte)_bVar10,
                     (char *)(ulong)*(uint *)((int)&worldMenuLabels[1].ofs + 1 + iVar6),0,
                     (char *)(byte *)__C0_ASM_CopyRight,1,_bVar10,4);
        }
        else {
          uVar5 = ovr_season_checkEndGame(msgDelay,(byte)uStack_6);
          if ((uVar5 & 0xff) == 0) {
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
                    /* WARNING: Load size is inaccurate */
              _bVar10 = *(byte *)((int)&worldMenuLabels[0].seg + 1 + iVar6);
              ovr_ovc40_usesAlignToSeg
                        ((byte)_bVar10,
                         (char *)(ulong)*(uint *)((int)&worldMenuLabels[1].ofs + 1 + iVar6),0,
                         (char *)((byte *)__C0_ASM_CopyRight + 2),3,_bVar10,6);
            }
            else {
              iVar6 = (uint)*(byte *)((int)*(undefined4 *)(uStack_6 << 2) + 0x3e) * 0x95;
                    /* WARNING: Load size is inaccurate */
              _bVar10 = *(byte *)((int)&worldMenuLabels[0].seg + 1 + iVar6);
              ovr_ovc40_usesAlignToSeg
                        ((byte)_bVar10,
                         (char *)(ulong)*(uint *)((int)&worldMenuLabels[1].ofs + 1 + iVar6),0,
                         (char *)((byte *)__C0_ASM_CopyRight + 1),2,_bVar10,5);
            }
          }
        }
        ovc24_usesGLeaderCount((byte)uStack_6);
      }
L_OVC24_5943_112e_15E7:
    }
    if (bVar1) {
      bStack_3 = ovr_manage_findFirstLeader();
      _fmemset((void *)ZEXT24(unaff_SS),2,CONCAT11(uVar9,msgDelay));
      for (uStack_6 = 0; (int)uStack_6 < (int)(uint)GLeaderCount; uStack_6 = uStack_6 + 1) {
        if (*(char *)((int)*(undefined4 *)(uStack_6 << 2) + 0x3d) != '\0') {
          (&excludedFlags)[*(byte *)((int)*(undefined4 *)(uStack_6 << 2) + 0x3f)] = 0x1;
        }
      }
      if ((bStack_3 == 0xff) ||
         (*(char *)((int)*(undefined4 *)((uint)bStack_3 << 2) + 0x3d) == '\0')) {
        ovr_play_sfx(0,68);
        CurMusicType = 0x44;
        ovr_uiNotify((char *)0xa0002410,0x57af);
        GGameInProgress = 1;
        ovr_ovc38_usesStshAlloc();
        ovr_miceRestoreArea((brect_t *)CONCAT13(uVar9,CONCAT12(msgDelay,0x2410)),0x44a);
        ovr_stats_drawStatsPanel();
        ovr_ovc38_showAchievements();
        ovr_clearMiceProcessed();
        ovr_miceBlitRect((brect_t *)CONCAT13(uVar9,CONCAT12(msgDelay,0x2410)),0x44a);
        ovr_stop_audio();
        CurMusicType = 0xff;
      }
      else if ((cStack_11 == '\0') && (PlayerIndex == 1)) {
        ovr_ovc30_nextWave(msgDelay,1);
      }
      else if ((cStack_a != '\0') && ((cStack_11 == '\0' && (1 < PlayerIndex)))) {
        ovr_stop_audio();
        CurMusicType = 0x54;
        ovr_play_sfx(0,84);
        ovr_uiNotify((char *)0xa0002410,0x57e3);
        ovr_font_usesMiceBlitRect(msgDelay,messageDelayTicks << 4);
        if (cStack_4 == '\0') {
          ovr_inputUpdate((ulong)CONCAT11(uVar9,msgDelay) << 0x10,(uint)messageDelayTicks << 4);
        }
        else {
          ovr_ovc38_usesStshAlloc();
          ovr_miceRestoreArea((brect_t *)CONCAT13(uVar9,CONCAT12(msgDelay,0x2410)),0x44a);
          ovr_stats_drawStatsPanel();
          ovr_uiNotify((char *)0xa0002410,0x5802);
          ovr_ovc38_showAchievements();
          ovr_clearMiceProcessed();
          ovr_ovc28_textHalflingCastle();
          ovr_ovc41_usesGMenuItem();
          ovr_miceBlitRect((brect_t *)CONCAT13(uVar9,CONCAT12(msgDelay,0x2410)),0x44a);
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
  char direction;
  char cVar2;
  uint uVar3;
  long *plVar4;
  int iVar5;
  byte unaff_BP;
  undefined2 unaff_SI;
  agnt_t *paVar6;
  long lVar7;
  undefined2 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined1 in_stack_0000fffc;
  undefined1 in_stack_0000fffd;
  
  uVar9 = 0;
  uVar10 = 0;
  uVar8 = 0x8000;
  uVar3 = rand();
  iVar5 = (int)uVar3 >> 0xf;
  plVar4 = LXLSH_at_((long *)CONCAT11(uVar10,uVar9),
                     CONCAT13(in_stack_0000fffd,CONCAT12(in_stack_0000fffc,unaff_SI)),unaff_BP);
  lVar7 = LDIV_at_((long)CONCAT22(iVar5,plVar4),CONCAT13(uVar10,CONCAT12(uVar9,uVar8)));
  if ((int)lVar7 == 0) {
    paVar6 = (agnt_t *)((ulong)Entities >> 0x10);
    if (((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                   (uint)((entity_t *)Entities)[entityIndex].base.gindex * 0x95) & 0x2000) != 0) &&
       (bVar1 = ovr_agnt_compute8((agnt_t *)CONCAT22(unaff_SI,paVar6),
                                  (entity_t *)Entities + entityIndex), -1 < (char)bVar1)) {
      uVar8 = (undefined2)((ulong)Entities >> 0x10);
      direction = ((entity_t *)Entities)[entityIndex].dir -
                  ((entity_t *)Entities)[entityIndex].dir % 6;
      cVar2 = ovr_ovc22_compute3(direction,
                                 CONCAT11((char)((uint)(entityIndex * 0x37) >> 8),bVar1 - 1));
      ((entity_t *)Entities)[entityIndex].dir = direction + cVar2;
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
  uint16_t uVar4;
  int iVar5;
  entity_t *peVar6;
  uint uVar7;
  undefined2 uVar8;
  
  if ((*(uint *)((int)&((entity_t *)Entities)[entityIndex].base.frames + 1) & 1) != 0) {
    alignUp4();
    uVar8 = (undefined2)((ulong)Entities >> 0x10);
    peVar6 = (entity_t *)Entities;
    if (*(char *)((int)&peVar6[entityIndex].base.entity + 1) == '\0') {
      bVar2 = false;
      for (uVar7 = 0; uVar7 < EntityCount; uVar7 = uVar7 + 1) {
        if (((*(uint *)((int)&worldMenuLabels[6].seg + 1 + (uint)peVar6[uVar7].base.gindex * 0x95) &
             1) != 0) && (5 < peVar6[uVar7].base.level)) {
          bVar2 = true;
          break;
        }
      }
      if (!bVar2) {
        for (iVar5 = 0; iVar5 < 4; iVar5 = iVar5 + 1) {
          bVar3 = ovr_ovc45_getUnitType();
          if ((*(uint *)((uint)bVar3 * 0x27 + 0x121) & 0x100) != 0) {
            bVar2 = true;
            break;
          }
        }
      }
      if (bVar2) {
        puVar1 = (uint *)((int)&((entity_t *)Entities)[entityIndex].base.frames + 1);
        *puVar1 = *puVar1 & 0xfffe;
        uVar7 = alignUp4();
        iVar5 = (uint)((entity_t *)Entities)[entityIndex].base.gindex * 0x95;
        ovr_fmVsprintf((char *)CONCAT22(*(undefined2 *)((int)&worldMenuLabels[0].seg + 1 + iVar5),
                                        (char *)"puppetmaker" + 3),
                       (char *)CONCAT22(uVar7,(char *)*(undefined2 *)
                                                       ((int)&worldMenuLabels[1].ofs + 1 + iVar5)));
        ovr_uiNotify();
        return;
      }
    }
    uVar4 = ovr_randBelow();
    if ((uVar4 & 0xff) == 0) {
      uVar7 = 0;
      while( true ) {
        if ((EntityCount <= uVar7) ||
           ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 +
                      (uint)((entity_t *)Entities)[uVar7].base.gindex * 0x95) & 4) != 0)) break;
        uVar7 = uVar7 + 1;
      }
      if (uVar7 < EntityCount) {
        uVar7 = alignUp4();
        iVar5 = (uint)((entity_t *)Entities)[entityIndex].base.gindex * 0x95;
        ovr_fmVsprintf((char *)CONCAT22(*(undefined2 *)((int)&worldMenuLabels[0].seg + 1 + iVar5),
                                        (char *)"puppetmaker" + 3),
                       (char *)CONCAT22(uVar7,(char *)*(undefined2 *)
                                                       ((int)&worldMenuLabels[1].ofs + 1 + iVar5)));
        ovr_uiNotify();
        ovr_ovc15_usesLDIV_at_2();
      }
    }
  }
  return;
}



/* 5943:1eeb */

/* [R2] string "arena" */

bool __cdecl16far ovc24_textArena(uint16_t x,uint y,char faction,...)

{
  uint value;
  uint uVar1;
  int unaff_SI;
  int iVar2;
  undefined2 in_stack_00000004;
  
  if ((GOngoingBattle == '\0') && (GfxRndSeed2 == x)) {
    value = alignUp4(unaff_SI,in_stack_00000004);
    uVar1 = alignUp4(value,GfxRndSeed);
    if (value == uVar1) {
      iVar2 = 0;
      while( true ) {
        if ((int)(uint)AgntCount <= iVar2) {
          return false;
        }
        if (((*(uint *)(iVar2 * 0x34 + 0x2b) & 0xae4) == 0) &&
           (*(char *)(iVar2 * 0x34 + 0x2f) == (char)y)) break;
        iVar2 = iVar2 + 1;
      }
      return true;
    }
  }
  return false;
}


