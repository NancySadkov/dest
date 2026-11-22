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
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint16_t uVar8;
  
  for (uVar7 = 0; uVar7 < EntityCount; uVar7 = uVar7 + 1) {
    *(undefined1 *)((int)Entities + uVar7 * 0x37 + 0x18) = 0;
  }
  uVar7 = 0;
  do {
    if (EntityCount <= uVar7) {
      return;
    }
    uVar8 = (uint16_t)((ulong)Entities >> 0x10);
    iVar4 = (int)Entities;
    if (*(char *)(iVar4 + uVar7 * 0x37 + 0x18) == '\0') {
      cVar1 = *(char *)((int)(char **)GMenuStrings +
                       (uint)((entity_t *)iVar4)[uVar7].base.gindex * 0x95 + 0x1f);
      uVar2 = alignUp4(*(int *)((entity_t *)iVar4 + uVar7),0,0);
      iVar4 = ((entity_t *)Entities)[uVar7].base.y;
      for (uVar6 = 0; uVar6 < EntityCount; uVar6 = uVar6 + 1) {
        uVar8 = (uint16_t)((ulong)Entities >> 0x10);
        iVar5 = (int)Entities;
        if (((((entity_t *)iVar5)[uVar6].base.y == iVar4) &&
            (*(char *)((int)(char **)GMenuStrings +
                      (uint)((entity_t *)iVar5)[uVar6].base.gindex * 0x95 + 0x1f) != cVar1)) &&
           (uVar3 = alignUp4(*(int *)((entity_t *)iVar5 + uVar6),0,0), uVar3 == uVar2)) {
          *(undefined1 *)((int)Entities + uVar7 * 0x37 + 0x18) = 1;
          *(undefined1 *)((int)Entities + uVar6 * 0x37 + 0x18) = 1;
          break;
        }
      }
    }
    uVar7 = uVar7 + 1;
  } while( true );
}



/* 5943:0196 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches Entities */

char __cdecl16far ovc24_usesEntities(int entityIndex)

{
  byte bVar1;
  char cVar2;
  entity_t *peVar3;
  uint16_t uVar4;
  char cStack_3;
  
  bVar1 = ovr_agnt_compute8(&Entities[entityIndex].base,DAT_2000_d190);
  uVar4 = (uint16_t)((ulong)Entities >> 0x10);
  peVar3 = (entity_t *)Entities;
  cStack_3 = peVar3[entityIndex].base.level + bVar1 +
             *(char *)((int)&worldMenuLabels[8].ofs + 1 +
                      (uint)peVar3[entityIndex].base.gindex * 0x95) +
             *(char *)((int)&worldMenuLabels[8].seg + 1 +
                      (uint)peVar3[entityIndex].base.gindex * 0x95) + '\t';
  cVar2 = ovr_stats_compute4(&peVar3[entityIndex].base,uVar4);
  cStack_3 = cStack_3 - cVar2;
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
  byte bVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  long *plVar8;
  uint16_t uVar9;
  uint16_t uVar10;
  uint16_t uVar11;
  int iVar12;
  char *pcVar13;
  uint16_t uVar14;
  entity_t *peVar15;
  uint16_t unaff_SI;
  uint entityIndex_00;
  uint uVar16;
  uint16_t unaff_DI;
  uint16_t uVar17;
  uint unaff_SS;
  undefined1 uVar18;
  undefined1 uVar19;
  byte bVar20;
  undefined1 uVar21;
  undefined1 uVar22;
  undefined1 uVar23;
  undefined1 uVar24;
  uint8_t *puVar25;
  byte *pbVar26;
  undefined1 uVar27;
  undefined1 uVar28;
  uint32_t in_stack_0000ffd0;
  long lVar29;
  uint32_t factionTimer[2];   /* [BP-0x2a]: two 32-bit per-faction timers */
  uint8_t factionFlagsB[2];   /* [BP-0x20] */
  uint8_t factionFlagsA[2];   /* [BP-0x22] */
  uint8_t factionMax [4];
  long *plStack_18;
  int iStack_16;
  char cStack_12;
  byte bStack_10;
  uint uStack_a;
  uint uStack_8;
  
  lVar29 = CONCAT22((int)((ulong)in_stack_0000ffd0 >> 0x10),unaff_SI);
  uVar17 = (uint16_t)((ulong)Entities >> 0x10);
  uVar14 = ((entity_t *)Entities)[entityIndex].base.y;
  uVar6 = alignUp4((((entity_t *)Entities + entityIndex)->base).x,0,0);
  _fmemset(MK_FP(_SS, factionTimer), 0, 8);
  _fmemset(MK_FP(_SS, factionFlagsB), 0xFF81, 2);
  _fmemset(MK_FP(_SS, factionFlagsA), 0xFF81, 2);
  uVar16 = entityIndex;
  do {
    entityIndex_00 = uVar16;
    uVar17 = (uint16_t)((ulong)Entities >> 0x10);
    bVar20 = ((entity_t *)Entities)[entityIndex_00].base.gindex;
    *(undefined1 *)((int)&((entity_t *)Entities)[entityIndex_00].base.entity + 2) = 1;
    bVar4 = *(byte *)((int)(char **)GMenuStrings + (uint)bVar20 * 0x95 + 0x1f);
    bVar5 = ovc24_usesEntities(entityIndex_00);
    uVar7 = (uint)bVar5 * (uint)bVar5 * (uint)((entity_t *)Entities)[entityIndex_00].base.animFrame
    ;
    puVar1 = (uint *)(&factionTimer[0] + bVar4);
    uVar16 = *puVar1;
    *puVar1 = *puVar1 + uVar7;
    piVar2 = (int *)((int)&factionTimer[0] + (uint)bVar4 * 4 + 2);
    *piVar2 = *piVar2 + ((int)uVar7 >> 0xf) + (uint)CARRY2(uVar16,uVar7);
    if (((*(uint *)((int)&worldMenuLabels[6].seg + 1 + (uint)bVar20 * 0x95) & 8) == 0) &&
       ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)bVar20 * 0x95) & 0x20) == 0)) {
      puVar25 = factionMax + bVar4;
      bVar5 = ovr_agnt_compute8(&((entity_t *)Entities)[entityIndex_00].base,
                                (char)((ulong)Entities >> 0x10));
      if ((char)*puVar25 < (char)bVar5) {
        pbVar26 = factionMax + bVar4;
        bVar5 = ovr_agnt_compute8(&Entities[entityIndex_00].base,(char)((ulong)Entities >> 0x10));
        *pbVar26 = bVar5;
      }
    }
    if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 + (uint)bVar20 * 0x95) & 8) == 0) {
      puVar25 = factionMax + bVar4 + 2;
      bVar5 = ovr_agnt_compute8(&Entities[entityIndex_00].base,(char)((ulong)Entities >> 0x10));
      if ((char)*puVar25 < (char)bVar5) {
        pbVar26 = factionMax + bVar4 + 2;
        bVar5 = ovr_agnt_compute8(&Entities[entityIndex_00].base,(char)((ulong)Entities >> 0x10));
        *pbVar26 = bVar5;
      }
    }
    if (((char)factionMax[bVar4 + 2] < '\x02') &&
       ((*(uint *)((int)&worldMenuLabels[6].seg + 1 + (uint)bVar20 * 0x95) & 2) != 0)) {
      factionMax[bVar4 + 2] = 0x2;
    }
    uVar16 = entityIndex_00;
    if ((((char)factionMax[bVar4] < '\x02') &&
        ((*(uint *)((int)&worldMenuLabels[6].seg + 1 + (uint)bVar20 * 0x95) & 2) != 0)) &&
       (4 < ((entity_t *)Entities)[entityIndex_00].base.level)) {
      factionMax[bVar4] = 0x2;
    }
    do {
      uVar16 = uVar16 + 1;
      if (EntityCount <= uVar16) break;
      uVar17 = (uint16_t)((ulong)Entities >> 0x10);
    } while ((((entity_t *)Entities)[uVar16].base.y != uVar14) ||
            (uVar7 = alignUp4((((entity_t *)Entities + uVar16)->base).x,0,0), uVar7 != uVar6));
  } while (uVar16 < EntityCount);
  iStack_16 = 0;
  plStack_18 = (long *)"Time passes...";
  if ((-1 < (*(uint16_t *)((uint8_t *)&(factionTimer[0]) + 2))) &&
     ((0 < (*(uint16_t *)((uint8_t *)&(factionTimer[0]) + 2)) || ((long *)"Time passes..." < (long *)factionTimer[0])))) {
    iStack_16 = (*(uint16_t *)((uint8_t *)&(factionTimer[0]) + 2));
    plStack_18 = (long *)factionTimer[0];
  }
  if ((iStack_16 <= (*(uint16_t *)((uint8_t *)&(factionTimer[1]) + 2))) &&
     ((iStack_16 < (*(uint16_t *)((uint8_t *)&(factionTimer[1]) + 2)) || (plStack_18 < (long *)factionTimer[1])))) {
    iStack_16 = (*(uint16_t *)((uint8_t *)&(factionTimer[1]) + 2));
    plStack_18 = (long *)factionTimer[1];
  }
  uVar23 = (undefined1)iStack_16;
  uVar27 = (undefined1)((uint)iStack_16 >> 8);
  uVar18 = SUB21(plStack_18,0);
  uVar21 = (undefined1)((uint)plStack_18 >> 8);
  uVar17 = 0;
  uVar19 = uVar18;
  uVar22 = uVar21;
  uVar24 = uVar23;
  uVar28 = uVar27;
  plVar8 = LXMUL_at_(plStack_18,CONCAT22(unaff_DI,iStack_16),lVar29);
  factionTimer[0] = LDIV_at_(CONCAT13((char)((uint)uVar17 >> 8),CONCAT12((char)uVar17,plVar8)),
                       CONCAT13(uVar28,CONCAT12(uVar24,CONCAT11(uVar22,uVar19))));
  factionTimer[0] = factionTimer[0] + 0x14;
  uVar17 = 0;
  plVar8 = LXMUL_at_(plStack_18,CONCAT22(unaff_DI,iStack_16),lVar29);
  factionTimer[1] = LDIV_at_(CONCAT13((char)((uint)uVar17 >> 8),CONCAT12((char)uVar17,plVar8)),
                       CONCAT13(uVar27,CONCAT12(uVar23,CONCAT11(uVar21,uVar18))));
  factionTimer[1] = factionTimer[1] + 0x14;
  uVar9 = ovr_randBelow((uint16_t)(long *)factionTimer[0],0);
  uVar10 = ovr_randBelow((uint16_t)(long *)factionTimer[1],0);
  uVar11 = ovr_randBelow((uint16_t)(long *)factionTimer[0],0);
  uStack_8 = uVar11 & 0xff;
  uVar11 = ovr_randBelow((uint16_t)(long *)factionTimer[1],0);
  uVar16 = uVar11 & 0xff;
  if ((uVar10 & 0xff) < (uVar9 & 0xff)) {
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
  uStack_a = 0xffff;
  do {
    if ((int)entityIndex_00 < (int)entityIndex) {
      if (uStack_a != 0xffff) {
        if (uVar16 == 0xffff) {
          bVar20 = (byte)((ulong)Entities >> 0x10);
          ovr_attact_usesRandBelow
                    (&Entities[uStack_a].base,bVar20,bVar20,Entities[uStack_a].base.target);
          ovr_attact_usesEntities(uStack_a,0,0,0,0,0,0,0,0);
          uVar17 = (uint16_t)((ulong)Entities >> 0x10);
          peVar15 = (entity_t *)Entities;
          bVar20 = peVar15[uStack_a].base.gindex;
          if (*(char *)((int)(char **)GMenuStrings + (uint)bVar20 * 0x95 + 0x1f) == '\0') {
            alignUp4(((peVar15 + entityIndex)->base).x,(char)peVar15[entityIndex].base.y,0);
            iVar12 = (uint)bVar20 * 0x95;
            uVar14 = 0x195d;
            uVar17 = *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + iVar12);
            pcVar13 = ovr_fmVsprintf("Intelligence reports %s unit fleeing from battle. (%d, %d)",
                                     (char *)CONCAT13((char)((uint)uVar17 >> 8),
                                                      CONCAT12((char)uVar17,
                                                               *(uint16_t *)
                                                                ((int)&worldMenuLabels[0].seg + 1 +
                                                                iVar12))));
            ovr_uiNotify(pcVar13,uVar14,(char)uVar14);
          }
        }
        else {
          if (Entities[uVar16].base.animFrame <= uStack_8) {
            uStack_8 = (uint)Entities[uVar16].base.animFrame;
          }
          Entities[uVar16].base.animFrame = Entities[uVar16].base.animFrame - (byte)uStack_8;
          bVar20 = (byte)((ulong)Entities >> 0x10);
          ovr_ovc41_compute4(&Entities[uVar16].base,bVar20,(byte)uStack_8,&Entities[uStack_a].base,
                             bVar20,(byte)uStack_8,(char)(Entities + uStack_a),bVar20);
          ovr_ovc25_attackingNotice
                    (*(byte *)((int)&((entity_t *)Entities)[uVar16].base.entity + 3));
          if (((entity_t *)Entities)[uVar16].base.animFrame != 0x0) {
            ovc24_usesLDIV_at_(uVar16);
            uVar17 = (uint16_t)((ulong)Entities >> 0x10);
            peVar15 = (entity_t *)Entities;
            if (((*(uint *)((int)&worldMenuLabels[7].ofs + 1 +
                           (uint)peVar15[uStack_a].base.gindex * 0x95) & 4) != 0) &&
               ((*(uint *)((int)&peVar15[uVar16].base.frames + 1) & 1) == 0)) {
              uVar6 = ovr_ovc27_rollToHitAgent
                                (CONCAT13((char)((ulong)Entities >> 0x18),
                                          CONCAT12((char)((ulong)Entities >> 0x10),peVar15 + uVar16
                                                  )),0);
              if ((uVar6 & 0xff) == 0) {
                puVar1 = (uint *)((int)&((entity_t *)Entities)[uVar16].base.frames + 1);
                *puVar1 = *puVar1 | 1;
                uVar17 = (uint16_t)((ulong)Entities >> 0x10);
                alignUp4((((entity_t *)Entities + entityIndex)->base).x,
                         (char)((entity_t *)Entities)[entityIndex].base.y,0);
                iVar12 = (uint)((entity_t *)Entities)[uVar16].base.gindex * 0x95;
                uVar14 = 0x195d;
                uVar17 = *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + iVar12);
                pcVar13 = ovr_fmVsprintf("Intelligence reports %s unit infected with disease. (%d, %d)"
                                         ,(char *)CONCAT13((char)((uint)uVar17 >> 8),
                                                           CONCAT12((char)uVar17,
                                                                    *(uint16_t *)
                                                                     ((int)&worldMenuLabels[0].seg +
                                                                      1 + iVar12))));
                ovr_uiNotify(pcVar13,uVar14,(char)uVar14);
              }
            }
            if ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 +
                          (uint)((entity_t *)Entities)[uStack_a].base.gindex * 0x95) & 0xc00) != 0)
            {
              uVar6 = ovr_ovc27_rollToHitAgent
                                (CONCAT13((char)((ulong)Entities >> 0x18),
                                          CONCAT12((char)((ulong)Entities >> 0x10),
                                                   (entity_t *)Entities + uVar16)),3);
              if ((uVar6 & 0xff) == 0) {
                if ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 +
                              (uint)((entity_t *)Entities)[uStack_a].base.gindex * 0x95) & 0x800)
                    == 0) {
                  cStack_12 = '\x01';
                }
                else {
                  cStack_12 = '\x02';
                }
                uVar17 = ovr_ovc27_compute3(CONCAT13((char)((ulong)Entities >> 0x18),
                                                     CONCAT12((char)((ulong)Entities >> 0x10),
                                                              (entity_t *)Entities + uVar16)),
                                            cStack_12);
                if ((char)uVar17 != '\0') {
                  if (DebugVerbose != false) {
                    printf("kill 3\r");
                  }
                  uVar17 = (uint16_t)((ulong)Entities >> 0x10);
                  if (((entity_t *)Entities)[uVar16].base.animFrame != 0x0) {
                    puVar3 = &((entity_t *)Entities)[uVar16].base.animFrame;
                    *puVar3 = *puVar3 + 0xff;
                  }
                }
                uVar17 = (uint16_t)((ulong)Entities >> 0x10);
                alignUp4((((entity_t *)Entities + entityIndex)->base).x,
                         (char)((entity_t *)Entities)[entityIndex].base.y,0);
                iVar12 = (uint)((entity_t *)Entities)[uVar16].base.gindex * 0x95;
                uVar14 = 0x195d;
                uVar17 = *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + iVar12);
                pcVar13 = ovr_fmVsprintf("Intelligence reports %s unit drained of energy. (%d, %d)",
                                         (char *)CONCAT13((char)((uint)uVar17 >> 8),
                                                          CONCAT12((char)uVar17,
                                                                   *(uint16_t *)
                                                                    ((int)&worldMenuLabels[0].seg +
                                                                     1 + iVar12))));
                ovr_uiNotify(pcVar13,uVar14,(char)uVar14);
              }
            }
          }
        }
      }
      return;
    }
    if (Entities[entityIndex].base.y == uVar14) {
      uVar7 = alignUp4(((Entities + entityIndex)->base).x,0,0);
      if (uVar7 == uVar6) {
        uVar17 = (uint16_t)((ulong)Entities >> 0x10);
        peVar15 = (entity_t *)Entities;
        if (*(byte *)((int)(char **)GMenuStrings +
                     (uint)peVar15[entityIndex].base.gindex * 0x95 + 0x1f) == bStack_10) {
          bVar20 = (byte)((ulong)lVar29 >> 0x18);
          if (peVar15[entityIndex].base.level < bVar20) {
L_OVC24_5943_026e_0772:
            uVar17 = (uint16_t)((ulong)Entities >> 0x10);
            bVar20 = ((entity_t *)Entities)[entityIndex].base.gindex;
            if (((((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)bVar20 * 0x95) & 0x40) == 0)
                 || ('\x01' < (char)factionMax[(bStack_10 ^ 1) + 2])) &&
                (((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)bVar20 * 0x95) & 8) == 0 ||
                 ('\0' < (char)factionMax[(bStack_10 ^ 1) + 2])))) &&
               (((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)bVar20 * 0x95) & 0x10) == 0 ||
                (-1 < (char)factionMax[bStack_10 ^ 1])))) {
              lVar29 = CONCAT13(((entity_t *)Entities)[entityIndex].base.level,(int3)lVar29);
              uVar16 = entityIndex;
            }
          }
          else if (peVar15[entityIndex].base.level == bVar20) {
            uVar9 = ovr_randBelow(3,0);
            if ((uVar9 & 0xff) == 0) goto L_OVC24_5943_026e_0772;
          }
        }
        else {
          bVar20 = (byte)((ulong)lVar29 >> 0x10);
          if (bVar20 < peVar15[entityIndex].base.level) {
L_OVC24_5943_026e_088A:
            lVar29 = (ulong)CONCAT11((char)((ulong)lVar29 >> 0x18),
                                     ((entity_t *)Entities)[entityIndex].base.level) << 0x10;
            uStack_a = entityIndex;
          }
          else if (peVar15[entityIndex].base.level == bVar20) {
            uVar9 = ovr_randBelow(3,0);
            if ((uVar9 & 0xff) == 0) goto L_OVC24_5943_026e_088A;
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

void __cdecl16far ovc24_removeOtherEntities(uint8_t *reportedOut)

{
  uint uVar1;
  uint uVar2;
  char *msg;
  uint16_t dst;
  int iVar3;
  uint uVar4;
  uint16_t uVar5;
  uint16_t in_stack_00000006;
  
  if (!GameRunning) {
    for (uVar4 = 0; uVar4 < EntityCount; uVar4 = uVar4 + 1) {
      *(undefined1 *)((int)Entities + uVar4 * 0x37 + 0x19) = 0;
    }
    for (uVar4 = 0; uVar4 < EntityCount; uVar4 = uVar4 + 1) {
      uVar5 = (uint16_t)((ulong)Entities >> 0x10);
      iVar3 = (int)Entities;
      if ((*(char *)(iVar3 + uVar4 * 0x37 + 0x18) != '\0') &&
         (*(char *)(iVar3 + uVar4 * 0x37 + 0x19) == '\0')) {
        if ((GOngoingBattle == '\0') && (((entity_t *)iVar3)[uVar4].base.y == GfxRndSeed2)) {
          uVar1 = alignUp4(*(int *)((entity_t *)iVar3 + uVar4),0,0);
          uVar2 = alignUp4(GfxRndSeed,0,0);
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
      uVar5 = (uint16_t)((ulong)Entities >> 0x10);
      iVar3 = (int)Entities;
      if (((entity_t *)iVar3)[uVar4].base.animFrame == '\0') {
        if ((GOngoingBattle == '\0') &&
           (uVar5 = ovr_ovc23_isCursorAt
                              (*(uint16_t *)((entity_t *)iVar3 + uVar4),((entity_t *)iVar3)[uVar4].base.y,0), (char)uVar5 != '\0')) {
          uVar1 = (uint)AgntCount;
          do {
            uVar1 = uVar1 - 1;
            if ((int)uVar1 < 0) break;
          } while (*(uint *)(uVar1 * 0x34 + 0x1b) != uVar4);
          if ((int)uVar1 < 0) {
            if (*(char *)((int)(char **)GMenuStrings +
                         (uint)((entity_t *)Entities)[uVar4].base.gindex * 0x95 + 0x1f) == '\0'
               ) {
              ovr_play_sfx(8,0,0);
            }
            else {
              ovr_play_sfx(11,0,0);
            }
            ovr_ovc15_removeEntity(uVar4);
          }
        }
        else {
          uVar5 = (uint16_t)((ulong)Entities >> 0x10);
          alignUp4(*(int *)((int)Entities + uVar4 * 0x37),
                   ((entity_t *)Entities)[uVar4].base.y,0xa000);
          iVar3 = (uint)((entity_t *)Entities)[uVar4].base.gindex * 0x95;
          dst = 0x195d;
          msg = ovr_fmVsprintf("Intelligence reports %s unit destroyed. (%d, %d)",
                               (char *)CONCAT22(*(uint16_t *)
                                                 ((int)&worldMenuLabels[1].ofs + 1 + iVar3),
                                                (char *)*(uint16_t *)
                                                         ((int)&worldMenuLabels[0].seg + 1 + iVar3))
                              );
          ovr_uiNotify(msg,dst,0);
          ovr_ovc15_removeEntity(uVar4);
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
  int iVar1;
  byte bVar2;
  int iVar3;
  unit_t *puVar4;
  short sVar5;
  uint16_t uVar6;
  
  iVar3 = ((char_sheet_t *)(((uint)leaderIndex << 2)))->x;
  iVar1 = ((char_sheet_t *)(((uint)leaderIndex << 2)))->y;
  bVar2 = ovr_manage_findFirstLeader();
  uVar6 = (uint16_t)((ulong)GUnitGrid >> 0x10);
  if (leaderIndex == bVar2) {
    sVar5 = ((short (*) [148] [60])GUnitGrid)[-1][iVar3 + 0x92][iVar1];
  }
  else {
    sVar5 = ((short (*) [148] [60])GUnitGrid)[-1][iVar3 + 0x93][iVar1];
  }
  uVar6 = (uint16_t)((ulong)GUnits >> 0x10);
  puVar4 = (unit_t *)GUnits;
  if (puVar4[sVar5].unitType == leaderIndex) {
    iVar3 = (uint)(puVar4 + sVar5)->bldType * 0x27;
    if ((*(uint *)(iVar3 + 0x121) & 4) == 0) {
      uVar6 = CONCAT11((char)((uint)iVar3 >> 8),1);
    }
    else if ((*(char *)((int)*(uint32_t *)((uint)leaderIndex << 2) + 0x3f) == '\0') &&
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
  bool bVar2;
  uint16_t uVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  uint16_t uVar7;
  int probeOfs;
  uint16_t unaff_DI;
  char *unaff_SS;
  uint8_t text;
  char sbuf [120];
  uint8_t outFlag;
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
      if (((char_sheet_t *)((leaderIndex << 2)))->active != '\0') {
        leaderClass = ((char_sheet_t *)((leaderIndex << 2)))->classStr;
        side = *(byte *)((int)*(uint32_t *)(leaderIndex << 2) + 0x3f);
        ownMask = 0x1000 << (1U - (side != 0) & 0x1f);
        enemyMask = '\0' << (side & 0x1f);
        cellX = alignUp4(((char_sheet_t *)((leaderIndex << 2)))->x,0,0);
        uVar6 = ((char_sheet_t *)((leaderIndex << 2)))->y;
        flagMask = 0;
        for (probeOfs = -2; probeOfs < 2; probeOfs = probeOfs + 1) {
          flagMask = flagMask | (*(short (*) [60] [148])GMapFlags)[uVar6][cellX + probeOfs];
        }
        if (((flagMask & enemyMask) == 0) && ((flagMask & ownMask) != 0)) {
          uVar3 = ovc24_unitAtLeader((byte)leaderIndex);
          if (((char)uVar3 == '\0') || (bVar2 = ovc24_textArena(cellX,uVar6,side), bVar2))
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
        if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)leaderClass * 0x95) & 0x800) == 0) {
          uVar4 = alignUp4(((char_sheet_t *)((leaderIndex << 2)))->x,uVar6,0);
          uVar7 = 0x195d;
          pcVar5 = ovr_ovc15_capitalize((char *)&text);
          pcVar5 = ovr_stsprintf(sbuf,(char *)CONCAT22(0x578d,unaff_SS),
                                 (char *)CONCAT22(pcVar5,(char *)0x26510),uVar7,uVar4);
          ovr_uiNotify(pcVar5,uVar7,0);
        }
        else {
          uVar4 = alignUp4(((char_sheet_t *)((leaderIndex << 2)))->x,uVar6,0);
          pcVar5 = ovr_stsprintf(sbuf,(char *)CONCAT22(0x576a,unaff_SS),
                                 (char *)CONCAT22(uVar4,(char *)0x26510));
          ovr_uiNotify(pcVar5,uVar7,0);
        }
        if (firstLeader == leaderIndex) {
          ovr_createConstructionRecordFar
                    (0,((char_sheet_t *)((leaderIndex << 2)))->x + -2,uVar6,(uint8_t *)CONCAT22(unaff_SS,&outFlag),0xff,(char)unaff_DI,0xff,0,0);
        }
        else {
          ovr_createConstructionRecordFar
                    (0,((char_sheet_t *)((leaderIndex << 2)))->x + -1,uVar6,(uint8_t *)CONCAT22(unaff_SS,&outFlag),0xff,(char)unaff_DI,0xff,0,0);
        }
        CurSfxType3 = 0xff;
        ((char_sheet_t *)((leaderIndex << 2)))->active = 0;
        bVar1 = true;
        ovr_manage_mapPartySlots();
        ovr_font_usesMiceBlitRect(0x5a);
        _fmemset(MK_FP(_SS, &flagMask), 0, 2);
        if (side == 0) {
          probeOfs = (uint)((char_sheet_t *)((leaderIndex << 2)))->classStr * 0x95;
          ovr_ovc40_usesAlignToSeg
                    ('\x01',(char *)*(uint16_t *)((int)&worldMenuLabels[0].seg + 1 + probeOfs),*(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + probeOfs),(char *)0x0,0,4,0,0,0,0);
        }
        else {
          uVar6 = ovr_season_checkEndGame((byte)leaderIndex);
          if ((uVar6 & 0xff) == 0) {
            for (probeOfs = 0; probeOfs < (int)(uint)GLeaderCount; probeOfs = probeOfs + 1) {
              if (((char_sheet_t *)((probeOfs << 2)))->active != '\0') {
                (&excludedFlags)[*(byte *)((int)*(uint32_t *)(probeOfs << 2) + 0x3f)] = 0x1;
              }
            }
            if ((((cStack_11 == '\0') && (1 < PlayerIndex)) && (GHighScoreSaved == '\0')) &&
               ((((char_sheet_t *)(((uint)firstLeader << 2)))->alignment == '\x02' ||
                ((((char_sheet_t *)(((uint)firstLeader << 2)))->alignment == '\x01' &&
                 (8 < ((char_sheet_t *)(((uint)firstLeader << 2)))->titleIndex)))))) {
              cStack_4 = '\x01';
            }
            if (cStack_4 == '\0') {
              probeOfs = (uint)((char_sheet_t *)((leaderIndex << 2)))->classStr * 0x95;
              ovr_ovc40_usesAlignToSeg
                        ('\x03',(char *)*(uint16_t *)((int)&worldMenuLabels[0].seg + 1 + probeOfs),*(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + probeOfs),(char *)0x0,0,6,0,0,0,0);
            }
            else {
              probeOfs = (uint)((char_sheet_t *)((leaderIndex << 2)))->classStr * 0x95;
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
        if (((char_sheet_t *)((leaderIndex << 2)))->active != '\0') {
          (&excludedFlags)[*(byte *)((int)*(uint32_t *)(leaderIndex << 2) + 0x3f)] = 0x1;
        }
      }
      if ((firstLeader == 0xff) ||
         (((char_sheet_t *)(((uint)firstLeader << 2)))->active == '\0')) {
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
  byte bVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  long *plVar5;
  int iVar6;
  uint16_t unaff_SI;
  long lVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  uint16_t uVar10;
  byte in_stack_0000fffc;
  
  uVar10 = 0;
  uVar8 = 0;
  uVar9 = 0x80;
  uVar4 = rand();
  iVar6 = (int)uVar4 >> 0xf;
  plVar5 = LXLSH_at_((long *)CONCAT11(uVar9,uVar8),CONCAT22(unaff_SI,uVar10),in_stack_0000fffc);
  lVar7 = LDIV_at_((long)CONCAT22(iVar6,plVar5),CONCAT22(uVar10,CONCAT11(uVar9,uVar8)));
  if ((int)lVar7 == 0) {
    uVar10 = (uint16_t)((ulong)Entities >> 0x10);
    if (((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                   (uint)((entity_t *)Entities)[entityIndex].base.gindex * 0x95) & 0x2000) != 0
        ) && (bVar1 = ovr_agnt_compute8((agnt_t *)((int)Entities + entityIndex * 0x37),uVar10),
             -1 < (char)bVar1)) {
      uVar10 = (uint16_t)((ulong)Entities >> 0x10);
      cVar2 = ((entity_t *)Entities)[entityIndex].dir -
              ((entity_t *)Entities)[entityIndex].dir % 6;
      cVar3 = ovr_ovc22_compute3(bVar1 - 1);
      ((entity_t *)Entities)[entityIndex].dir = cVar2 + cVar3;
    }
  }
  return;
}



/* 5943:190b */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches GLeaderCount, EntityCount */

void __cdecl16far ovc24_usesGLeaderCount(byte leaderIndex)

{
  uint uVar1;
  uint uVar2;
  byte leaderIdx;
  uint uVar4;
  uint uVar5;
  uint16_t uVar6;
  uint bestOtherDist;
  uint bestDist;
  byte bestOtherIdx;
  byte bestSameIdx;
  uint unitIdx;
  
  bestDist = 0xffff;
  bestOtherDist = 0xffff;
  bestSameIdx = 0xff;
  bestOtherIdx = 0xff;
  if (*(char *)((int)*(uint32_t *)((uint)leaderIndex << 2) + 0x3f) == '\0') {
    for (leaderIdx = 0; leaderIdx < GLeaderCount; leaderIdx = leaderIdx + 1) {
      if (((((char_sheet_t *)(((uint)leaderIdx << 2)))->active != '\0') &&
          (*(char *)((int)*(uint32_t *)((uint)leaderIdx << 2) + 0x3f) ==
           *(char *)((int)*(uint32_t *)((uint)leaderIndex << 2) + 0x3f))) &&
         (uVar1 = ((char_sheet_t *)(((uint)leaderIdx << 2)))->x -
                  ((char_sheet_t *)(((uint)leaderIndex << 2)))->x,
         uVar4 = (int)uVar1 >> 0xf,
         uVar2 = ((char_sheet_t *)(((uint)leaderIdx << 2)))->y -
                 ((char_sheet_t *)(((uint)leaderIndex << 2)))->y,
         uVar5 = (int)uVar2 >> 0xf, uVar1 = ((uVar1 ^ uVar4) - uVar4) + ((uVar2 ^ uVar5) - uVar5),
         uVar1 < bestDist)) {
        bestDist = uVar1;
        bestSameIdx = leaderIdx;
      }
    }
  }
  else {
    for (leaderIdx = 0; leaderIdx < GLeaderCount; leaderIdx = leaderIdx + 1) {
      if (((((char_sheet_t *)(((uint)leaderIdx << 2)))->active != '\0') &&
          (*(char *)((int)*(uint32_t *)((uint)leaderIdx << 2) + 0x3f) == '\0')) &&
         (uVar1 = ((char_sheet_t *)(((uint)leaderIdx << 2)))->x -
                  ((char_sheet_t *)(((uint)leaderIndex << 2)))->x,
         uVar4 = (int)uVar1 >> 0xf,
         uVar2 = ((char_sheet_t *)(((uint)leaderIdx << 2)))->y -
                 ((char_sheet_t *)(((uint)leaderIndex << 2)))->y,
         uVar5 = (int)uVar2 >> 0xf,
         uVar1 = ((uVar1 ^ uVar4) - uVar4) + ((uVar2 ^ uVar5) - uVar5) * 2, uVar1 < bestOtherDist)) {
        bestOtherDist = uVar1;
        bestOtherIdx = leaderIdx;
      }
    }
  }
  for (uVar1 = 0; uVar1 < EntityCount; uVar1 = uVar1 + 1) {
    uVar6 = (uint16_t)((ulong)Entities >> 0x10);
    if ((*(byte *)((int)Entities + uVar1 * 0x37 + 0x1a) == leaderIndex) &&
       (*(byte *)((int)Entities + uVar1 * 0x37 + 0x1a) = bestSameIdx, bestOtherIdx != 0xff)) {
      ((entity_t *)Entities)[uVar1].base.destX =
           ((char_sheet_t *)(((uint)bestOtherIdx << 2)))->x;
      ((entity_t *)Entities)[uVar1].base.destY =
           ((char_sheet_t *)(((uint)bestOtherIdx << 2)))->y;
    }
  }
  for (unitIdx = 0xf8; unitIdx < GUnitCount; unitIdx = unitIdx + 1) {
    uVar6 = (uint16_t)((ulong)GUnits >> 0x10);
    if (((unit_t *)GUnits)[unitIdx].unitType == leaderIndex) {
      ((unit_t *)GUnits)[unitIdx].unitType = 0xff;
    }
  }
  return;
}



/* 5943:1bff */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Formats the per-unit intelligence report (cured/diseased/poisoned variants). */

void __cdecl16far ovc24_intelUnitReport(int entityIndex)

{
  uint *puVar1;
  bool bVar2;
  byte bVar3;
  uint uVar4;
  uint16_t uVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  uint uVar9;
  uint16_t uVar10;
  
  uVar10 = (uint16_t)((ulong)Entities >> 0x10);
  if ((*(uint *)((int)Entities + entityIndex * 0x37 + 0x14) & 1) != 0) {
    uVar4 = alignUp4(*(int *)((int)Entities + entityIndex * 0x37),0,0);
    uVar10 = (uint16_t)((ulong)Entities >> 0x10);
    iVar8 = (int)Entities;
    iVar6 = ((entity_t *)iVar8)[entityIndex].base.y;
    if (*(char *)(iVar8 + entityIndex * 0x37 + 0x18) == '\0') {
      bVar2 = false;
      for (uVar9 = 0; uVar9 < EntityCount; uVar9 = uVar9 + 1) {
        if (((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                       (uint)((entity_t *)iVar8)[uVar9].base.gindex * 0x95) & 1) != 0) &&
           (5 < ((entity_t *)iVar8)[uVar9].base.level)) {
          bVar2 = true;
          break;
        }
      }
      if (!bVar2) {
        for (iVar8 = 0; iVar8 < 4; iVar8 = iVar8 + 1) {
          bVar3 = ovr_ovc45_getUnitType(uVar4 + iVar8 + -2,iVar6);
          if ((*(uint *)((uint)bVar3 * 0x27 + 0x121) & 0x100) != 0) {
            bVar2 = true;
            break;
          }
        }
      }
      if (bVar2) {
        puVar1 = (uint *)((int)Entities + entityIndex * 0x37 + 0x14);
        *puVar1 = *puVar1 & 0xfffe;
        uVar10 = (uint16_t)((ulong)Entities >> 0x10);
        alignUp4(*(int *)((int)Entities + entityIndex * 0x37),
                 ((entity_t *)Entities)[entityIndex].base.y,0xa000);
        iVar6 = (uint)((entity_t *)Entities)[entityIndex].base.gindex * 0x95;
        uVar5 = 0x195d;
        pcVar7 = ovr_fmVsprintf("Intelligence reports %s unit cured of disease. (%d, %d)",
                                (char *)CONCAT22(*(uint16_t *)
                                                  ((int)&worldMenuLabels[1].ofs + 1 + iVar6),
                                                 (char *)*(uint16_t *)
                                                          ((int)&worldMenuLabels[0].seg + 1 + iVar6)
                                                ));
        ovr_uiNotify(pcVar7,uVar5,0);
        return;
      }
    }
    uVar5 = ovr_randBelow(0x28,0);
    if ((uVar5 & 0xff) == 0) {
      uVar4 = 0;
      while( true ) {
        iVar6 = (int)Entities;
        uVar10 = (uint16_t)((ulong)Entities >> 0x10);
        if ((EntityCount <= uVar4) ||
           ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 +
                      (uint)((entity_t *)iVar6)[uVar4].base.gindex * 0x95) & 4) != 0)) break;
        uVar4 = uVar4 + 1;
      }
      if (uVar4 < EntityCount) {
        alignUp4(*(int *)((entity_t *)iVar6 + entityIndex),
                 ((entity_t *)iVar6)[entityIndex].base.y,0xa000);
        iVar6 = (uint)((entity_t *)Entities)[entityIndex].base.gindex * 0x95;
        uVar5 = 0x195d;
        pcVar7 = ovr_fmVsprintf("Intelligence reports %s unit succombs to blast spore disease. (%d, %d)"
                                ,(char *)CONCAT22(*(uint16_t *)
                                                   ((int)&worldMenuLabels[1].ofs + 1 + iVar6),
                                                  (char *)*(uint16_t *)
                                                           ((int)&worldMenuLabels[0].seg + 1 + iVar6
                                                           )));
        ovr_uiNotify(pcVar7,uVar5,0);
        uVar10 = (uint16_t)((ulong)Entities >> 0x10);
        ovr_ovc15_usesLDIV_at_2
                  (entityIndex,((entity_t *)Entities)[uVar4].base.gindex,
                   *(char *)((int)Entities + uVar4 * 0x37 + 0x1a));
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
        if (((*(uint *)(iVar3 * 0x34 + 0x2b) & 0xae4) == 0) &&
           (*(char *)(iVar3 * 0x34 + 0x2f) == faction)) break;
        iVar3 = iVar3 + 1;
      }
      return true;
    }
  }
  return false;
}


