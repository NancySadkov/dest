entity_t * __cdecl16far
ovc15_textView(undefined4 param_1,int *param_2,int *param_3,undefined2 param_4,undefined2 param_5,
              int *param_6,int *param_7,int *param_8,int *param_9)

{
  uint8_t *puVar1;
  undefined4 uVar2;
  far_t handle;
  far_t handle_00;
  undefined4 *puVar3;
  char cVar4;
  far_t *pfVar5;
  stg_tmp_t *gfx;
  cte_t *pcVar6;
  uint32_t *puVar7;
  int iVar8;
  uint uVar9;
  undefined2 uVar10;
  long *plVar11;
  undefined2 uVar12;
  entity_t *peVar13;
  uint uVar14;
  int iVar15;
  uint8_t unaff_BP;
  int unaff_SI;
  uint unaff_DI;
  uint uVar16;
  int iVar17;
  undefined2 unaff_SS;
  bool bVar18;
  far_t pixels;
  undefined4 in_stack_0000ffee;
  undefined1 uVar19;
  undefined1 uVar20;
  undefined1 in_stack_0000fff8;
  undefined1 in_stack_0000fff9;
  uint16_t uVar21;
  byte bVar22;
  undefined4 in_stack_0000fffa;
  uint16_t uVar23;
  uint16_t uVar24;
  
  iVar17 = (int)((ulong)param_1 >> 0x10);
  uVar14 = (uint)param_1;
  cVar4 = *(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)*(byte *)(uVar14 + 0xd) * 0x95);
  iVar8 = (int)((ulong)in_stack_0000fffa >> 0x10);
  uVar16 = CONCAT11(cVar4,(byte)in_stack_0000fffa);
  if (cVar4 == -1) {
    uVar16 = (uint)(byte)in_stack_0000fffa;
  }
  uVar9 = (uVar16 >> 8) - 1;
  if (5 < uVar9) {
    if (*(byte *)(uVar14 + 0xf) < 10) {
      cVar4 = ovr_manage_rollDice('\x01','\b');
      uVar19 = 0;
      uVar10 = ovr_agnt_abilityModifier(*(byte *)(uVar14 + 0x1a),4);
      iVar17 = CONCAT11(uVar19,cVar4) + (int)(char)uVar10;
    }
    else {
      iVar17 = 2;
    }
    bVar22 = (byte)iVar17;
    if (iVar17 < 1) {
      bVar22 = 1;
    }
    return (entity_t *)(uint)bVar22;
  }
  iVar15 = uVar9 * 2;
  bVar18 = iVar15 == 0;
  switch(uVar9) {
  case 1:
    *(undefined2 *)((int)AgntGs[0].sprs + 10 + iVar15) = 0x195d;
    do {
      *(uint *)((int)AgntGs[0].sprs + 8 + iVar15) = uVar9;
      while( true ) {
        for (iVar17 = 0; iVar17 < 3; iVar17 = iVar17 + 1) {
          iVar8 = unaff_SI * 0x95 + iVar17 * 2;
          if (*(int *)((int)AgntGs[0].sprfls + 6 + iVar8) == 0) {
            iVar8 = unaff_SI * 0x95 + iVar17 * 4;
            uVar10 = *(undefined2 *)((int)AgntGs[0].sprs + iVar8);
            iVar15 = unaff_SI * 0x95 + iVar17 * 4;
            *(undefined2 *)((int)AgntGs[0].sprs + 0xe + iVar15) =
                 *(undefined2 *)((int)AgntGs[0].sprs + 2 + iVar8);
            *(undefined2 *)((int)AgntGs[0].sprs + 0xc + iVar15) = uVar10;
          }
          else {
            uVar10 = 0x195d;
            pfVar5 = stshSprite((far_t *)*(undefined2 *)
                                          ((int)AgntGs[0].sprfls + 6 + unaff_SI * 0x95 + iVar17 * 2)
                                ,*(int16_t *)((int)&AgntGs[0].anms + unaff_SI * 0x95),
                                (anm_t *)(ulong)CONCAT12(*(undefined1 *)
                                                          ((int)&AgntGs[0].nanims + unaff_SI * 0x95)
                                                         ,*(undefined2 *)
                                                           ((int)&AgntGs[0].anms + 2 +
                                                           unaff_SI * 0x95)),
                                CONCAT11((char)((uint)iVar8 >> 8),(char)param_1),
                                (bool)in_stack_0000fff8);
            iVar8 = unaff_SI * 0x95 + iVar17 * 4;
            *(undefined2 *)((int)AgntGs[0].sprs + 0xe + iVar8) = uVar10;
            *(undefined2 *)((int)AgntGs[0].sprs + 0xc + iVar8) =(uint16_t)( pfVar5);
          }
        }
        for (iVar17 = 0; iVar17 < 6; iVar17 = iVar17 + 1) {
          uVar10 = 0x195d;
          if (*(int *)((int)AgntGs[0].prtfls + unaff_SI * 0x95 + iVar17 * 2) != 0) {
            if ((char)param_1 == '\0') {
              pfVar5 = ovr_stshAllocStub((far_t *)CONCAT11(in_stack_0000fff9,in_stack_0000fff8));
              iVar8 = unaff_SI * 0x95 + iVar17 * 4;
              uVar12 = 0x195d;
              *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar8) = uVar10;
              *(undefined2 *)((int)AgntGs[0].prts + iVar8) =(uint16_t)( pfVar5);
              pfVar5 = ovr_stshAllocStub((far_t *)CONCAT11(in_stack_0000fff9,in_stack_0000fff8));
              iVar8 = unaff_SI * 0x95 + iVar17 * 4;
              *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar8) = uVar12;
              *(undefined2 *)((int)AgntGs[0].prtpals + iVar8) =(uint16_t)( pfVar5);
            }
            else {
              uVar12 = 0x195d;
              gfx = ovr_grabLbm(*(int16_t *)((int)AgntGs[0].prtfls + unaff_SI * 0x95 + iVar17 * 2));
              uVar10 = uVar12;
              ovr_stshUniqueColorsRemap(gfx);
              pixels.seg = 0;
              pixels.ofs = (gfx->aptr).seg;
              pfVar5 = ovr_stshRleType2((far_t *)(&gfx->aptr)->ofs,pixels,0,114);
              pcVar6 = ovr_stshStoreFile((uint8_t *)pfVar5);
              iVar8 = unaff_SI * 0x95 + iVar17 * 4;
              uVar10 = 0x195d;
              *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar8) = uVar12;
              *(undefined2 *)((int)AgntGs[0].prts + iVar8) =(uint16_t)( pcVar6);
              puVar7 = ovr_stshWrite((uint32_t *)gfx);
              iVar8 = unaff_SI * 0x95 + iVar17 * 4;
              *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar8) = uVar10;
              *(undefined2 *)((int)AgntGs[0].prtpals + iVar8) =(uint16_t)( puVar7);
              ovr_stgFreeTmp(gfx);
            }
          }
        }
        peVar13 = (entity_t *)
                  (*(uint *)((int)AgntGs[0].prts + 4 + unaff_SI * 0x95) |
                  *(uint *)((int)AgntGs[0].prts + 6 + unaff_SI * 0x95));
        if ((peVar13 == (entity_t *)0x0) &&
           (peVar13 = (entity_t *)0x0,
           *(int *)((int)AgntGs[0].prts + unaff_SI * 0x95) != 0 ||
           *(int *)((int)AgntGs[0].prts + 2 + unaff_SI * 0x95) != 0)) {
          uVar10 = *(undefined2 *)((int)AgntGs[0].prts + unaff_SI * 0x95);
          *(undefined2 *)((int)AgntGs[0].prts + 6 + unaff_SI * 0x95) =
               *(undefined2 *)((int)AgntGs[0].prts + 2 + unaff_SI * 0x95);
          *(undefined2 *)((int)AgntGs[0].prts + 4 + unaff_SI * 0x95) = uVar10;
          peVar13 = (entity_t *)*(uint *)((int)AgntGs[0].prtpals + unaff_SI * 0x95);
          *(undefined2 *)((int)AgntGs[0].prtpals + 6 + unaff_SI * 0x95) =
               *(undefined2 *)((int)AgntGs[0].prtpals + 2 + unaff_SI * 0x95);
          *(uint *)((int)AgntGs[0].prtpals + 4 + unaff_SI * 0x95) = (uint)peVar13;
        }
        for (iVar17 = 2; iVar17 < 6; iVar17 = iVar17 + 2) {
          iVar8 = unaff_SI * 0x95 + iVar17 * 4;
          if ((*(int *)((int)AgntGs[0].prts + 4 + iVar8) == 0 &&
               *(int *)((int)AgntGs[0].prts + 6 + iVar8) == 0) &&
             (iVar8 = unaff_SI * 0x95 + iVar17 * 4,
             *(int *)((int)AgntGs[0].prtfls + 8 + iVar8) != 0 ||
             *(int *)((int)AgntGs[0].prtfls + 10 + iVar8) != 0)) {
            iVar8 = unaff_SI * 0x95 + iVar17 * 4;
            uVar10 = *(undefined2 *)((int)AgntGs[0].prtfls + 8 + iVar8);
            iVar15 = unaff_SI * 0x95 + iVar17 * 4;
            *(undefined2 *)((int)AgntGs[0].prts + 6 + iVar15) =
                 *(undefined2 *)((int)AgntGs[0].prtfls + 10 + iVar8);
            *(undefined2 *)((int)AgntGs[0].prts + 4 + iVar15) = uVar10;
            iVar8 = unaff_SI * 0x95 + iVar17 * 4;
            uVar10 = *(undefined2 *)((int)AgntGs[0].prts + 0x14 + iVar8);
            iVar15 = unaff_SI * 0x95 + iVar17 * 4;
            *(undefined2 *)((int)AgntGs[0].prtpals + 6 + iVar15) =
                 *(undefined2 *)((int)AgntGs[0].prts + 0x16 + iVar8);
            *(undefined2 *)((int)AgntGs[0].prtpals + 4 + iVar15) = uVar10;
          }
          iVar8 = unaff_SI * 0x95 + iVar17 * 4;
          peVar13 = (entity_t *)
                    (*(uint *)((int)AgntGs[0].prts + iVar8) |
                    *(uint *)((int)AgntGs[0].prts + 2 + iVar8));
          if (peVar13 == (entity_t *)0x0) {
            iVar8 = unaff_SI * 0x95 + iVar17 * 4;
            if (*(int *)((int)AgntGs[0].prtfls + 4 + iVar8) == 0 &&
                *(int *)((int)AgntGs[0].prtfls + 6 + iVar8) == 0) {
              peVar13 = (entity_t *)0x0;
            }
            else {
              iVar8 = unaff_SI * 0x95 + iVar17 * 4;
              uVar10 = *(undefined2 *)((int)AgntGs[0].prtfls + 4 + iVar8);
              iVar15 = unaff_SI * 0x95 + iVar17 * 4;
              *(undefined2 *)((int)AgntGs[0].prts + 2 + iVar15) =
                   *(undefined2 *)((int)AgntGs[0].prtfls + 6 + iVar8);
              *(undefined2 *)((int)AgntGs[0].prts + iVar15) = uVar10;
              iVar8 = unaff_SI * 0x95 + iVar17 * 4;
              peVar13 = (entity_t *)*(uint *)((int)AgntGs[0].prts + 0x10 + iVar8);
              iVar15 = unaff_SI * 0x95 + iVar17 * 4;
              *(undefined2 *)((int)AgntGs[0].prtpals + 2 + iVar15) =
                   *(undefined2 *)((int)AgntGs[0].prts + 0x12 + iVar8);
              *(uint *)((int)AgntGs[0].prtpals + iVar15) = (uint)peVar13;
            }
          }
        }
        unaff_SI = unaff_SI + 1;
        if (0x29 < unaff_SI) {
          return peVar13;
        }
        uVar10 = 0x195d;
        pfVar5 = stshSprite((far_t *)*(undefined2 *)((int)AgntGs[0].sprfls + unaff_SI * 0x95),
                            *(int16_t *)((int)&AgntGs[0].anms + unaff_SI * 0x95),
                            (anm_t *)(ulong)CONCAT12(*(undefined1 *)
                                                      ((int)&AgntGs[0].nanims + unaff_SI * 0x95),
                                                     *(undefined2 *)
                                                      ((int)&AgntGs[0].anms + 2 + unaff_SI * 0x95)),
                            CONCAT11((char)((uint)peVar13 >> 8),(char)param_1),
                            (bool)in_stack_0000fff8);
        *(undefined2 *)((int)AgntGs[0].sprs + 2 + unaff_SI * 0x95) = uVar10;
        *(undefined2 *)((int)AgntGs[0].sprs + unaff_SI * 0x95) =(uint16_t)( pfVar5);
        if (*(int *)((int)AgntGs[0].sprfls + 2 + unaff_SI * 0x95) == 0) {
          uVar10 = *(undefined2 *)((int)AgntGs[0].sprs + unaff_SI * 0x95);
          *(undefined2 *)((int)AgntGs[0].sprs + 6 + unaff_SI * 0x95) =
               *(undefined2 *)((int)AgntGs[0].sprs + 2 + unaff_SI * 0x95);
          *(undefined2 *)((int)AgntGs[0].sprs + 4 + unaff_SI * 0x95) = uVar10;
        }
        else {
          uVar10 = 0x195d;
          pfVar5 = stshSprite((far_t *)*(undefined2 *)((int)AgntGs[0].sprfls + 2 + unaff_SI * 0x95),
                              *(int16_t *)((int)&AgntGs[0].anms + unaff_SI * 0x95),
                              (anm_t *)(ulong)CONCAT12(*(undefined1 *)
                                                        ((int)&AgntGs[0].nanims + unaff_SI * 0x95),
                                                       *(undefined2 *)
                                                        ((int)&AgntGs[0].anms + 2 + unaff_SI * 0x95)
                                                      ),
                              CONCAT11((char)((uint)(unaff_SI * 0x95) >> 8),(char)param_1),
                              (bool)in_stack_0000fff8);
          *(undefined2 *)((int)AgntGs[0].sprs + 6 + unaff_SI * 0x95) = uVar10;
          *(undefined2 *)((int)AgntGs[0].sprs + 4 + unaff_SI * 0x95) =(uint16_t)( pfVar5);
        }
        if (*(int *)((int)AgntGs[0].sprfls + 4 + unaff_SI * 0x95) == 0) break;
        uVar10 = 0x195d;
        pfVar5 = stshSprite((far_t *)*(undefined2 *)((int)AgntGs[0].sprfls + 4 + unaff_SI * 0x95),
                            *(int16_t *)((int)&AgntGs[0].anms + unaff_SI * 0x95),
                            (anm_t *)(ulong)CONCAT12(*(undefined1 *)
                                                      ((int)&AgntGs[0].nanims + unaff_SI * 0x95),
                                                     *(undefined2 *)
                                                      ((int)&AgntGs[0].anms + 2 + unaff_SI * 0x95)),
                            CONCAT11((char)((uint)(unaff_SI * 0x95) >> 8),(char)param_1),
                            (bool)in_stack_0000fff8);
        *(undefined2 *)((int)AgntGs[0].sprs + 10 + unaff_SI * 0x95) = uVar10;
        *(undefined2 *)((int)AgntGs[0].sprs + 8 + unaff_SI * 0x95) =(uint16_t)( pfVar5);
      }
      uVar9 = *(uint *)((int)AgntGs[0].sprs + 4 + unaff_SI * 0x95);
      iVar15 = unaff_SI * 0x95;
      *(undefined2 *)((int)AgntGs[0].sprs + 10 + iVar15) =
           *(undefined2 *)((int)AgntGs[0].sprs + 6 + unaff_SI * 0x95);
    } while( true );
  case 2:
    do {
      cVar4 =(uint16_t)( ovr_ovc15_textView())   /* hand fix: self-call, args lost */;
      uVar10 = (undefined2)((ulong)Entities >> 0x10);
      *(char *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) =
           *(char *)((int)&((entity_t *)Entities)[EntityCount].base.state + 1) + cVar4;
      uVar10 = (undefined2)((ulong)Entities >> 0x10);
      *(char *)&((entity_t *)Entities)[EntityCount].base.flags32 =
           (char)((entity_t *)Entities)[EntityCount].base.flags32 + cVar4;
      puVar1 = &((entity_t *)Entities)[EntityCount].base.level;
      *puVar1 = *puVar1 + 0x1;
      iVar17 = EntityCount;
      uVar10 = (undefined2)((ulong)Entities >> 0x10);
      peVar13 = (entity_t *)Entities;
    } while (peVar13[EntityCount].base.level < 5);
    if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)(byte)param_3 * 0x95) == -1) {
      iVar8 = (uint)peVar13[EntityCount].base.level * 4;
      uVar12 = *(undefined2 *)(iVar8 + -4);
      *(undefined2 *)&peVar13[EntityCount].base.frameIndex = *(undefined2 *)(iVar8 + -2);
      *(undefined2 *)&peVar13[iVar17].base.health = uVar12;
    }
    else {
      iVar8 = (uint)*(byte *)((int)&worldMenuLabels[9].ofs + 1 + (uint)(byte)param_3 * 0x95) * 0x94
              + (uint)peVar13[EntityCount].base.level * 4;
      uVar12 = *(undefined2 *)(iVar8 + -4);
      *(undefined2 *)&peVar13[EntityCount].base.frameIndex = *(undefined2 *)(iVar8 + -2);
      *(undefined2 *)&peVar13[iVar17].base.health = uVar12;
    }
    iVar17 = EntityCount;
    uVar10 = (undefined2)((ulong)Entities >> 0x10);
    peVar13 = (entity_t *)Entities;
    if (*(int *)&peVar13[EntityCount].base.health == 0 &&
        *(int *)&peVar13[EntityCount].base.frameIndex == 0) {
      puVar1 = &peVar13[EntityCount].base.frameIndex;
      puVar1[0] = 0x0;
      puVar1[1] = 0x0;
      puVar1 = &peVar13[iVar17].base.health;
      puVar1[0] = 0x64;
      puVar1[1] = 0x0;
    }
    iVar17 = EntityCount;
    EntityCount = EntityCount + 1;
    ovr_attact_usesGMapFlags3();
    if (AgntFlag1 != false) {
      uVar10 = (undefined2)((ulong)Entities >> 0x10);
      peVar13 = (entity_t *)Entities;
      if (((GfxRndSeed - 2U <= ((peVar13 + iVar17)->base).x) &&
          (((peVar13 + iVar17)->base).x <= GfxRndSeed + 1U)) &&
         (peVar13[iVar17].base.y == GfxRndSeed2)) {
        ovc15_textArena(iVar17);
      }
    }
    peVar13 = Entities + iVar17;
    return peVar13;
  case 3:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 4:
    uVar2 = *(undefined4 *)((uint)PartyCount * 4 + -4);
    ovr_createConstructionRecordFar
              (*(byte *)((int)(far_t *)(worldMenuLabels + 0xb) +
                        (uint)*(byte *)((int)uVar2 + 0x3e) * 0x95),GfxRndSeed + -1);
    ovr_ovc18_textTypeLen(PartyCount - 1)   /* hand fix: prototype has 4 params */;
    if (2 < Difficulty) {
      ovr_ovc22_usesRandBelow2(PartyCount - 1);
    }
    ovr_ovc22_textRingProt(PartyCount - 1);
    PartyCount = 0;
    ovr_manage_mapPartySlots();
    ovr_stats_openCastlePanel();
    ovr_unit_usesAlignUp4();
    ovr_say((char *)0x45cd);
    peVar13 = (entity_t *)(uint)PlayerIndex;
    if (peVar13 == (entity_t *)0x0) {
      ovr_ovc30_nextWave(2);
    }
    return peVar13;
  case 5:
    do {
      if (bVar18) {
        *param_9 = *param_9 + 1;
      }
      while( true ) {
        while( true ) {
          do {
            do {
              unaff_DI = unaff_DI + 1;
              if (GRecordCount <= unaff_DI) {
                iVar17 = *param_8;
                iVar15 = *param_9;
                *param_2 = *param_2 - *param_8;
                *param_3 = *param_3 - *param_9;
                return (entity_t *)(iVar8 - (iVar17 + iVar15));
              }
            } while (*(char *)(unaff_DI * 0x12 + 9) != (char)param_1);
            bVar22 = *(byte *)(unaff_DI * 0x12 + 8);
          } while (*(char *)((uint)bVar22 * 0x27 + 0x133) != (*(uint8_t *)((uint8_t *)&(param_1) + 2)));
          *param_6 = *param_6 + 1;
          if (*(char *)((uint)bVar22 * 0x27 + 0x131) != '\x01') break;
          *param_7 = *param_7 + 1;
        }
        if (*(char *)((uint)bVar22 * 0x27 + 0x131) != '\x02') break;
        *param_8 = *param_8 + 1;
      }
      bVar18 = *(char *)((uint)bVar22 * 0x27 + 0x131) == '\x03';
    } while( true );
  }
  if (((byte)uVar9 & (&stack0x02c2)[unaff_DI]) == 0) {
    iVar17 = iVar17 + (uint)(0xffec < uVar14);
    plVar11 = LXRSH_at_((long *)CONCAT11(in_stack_0000fff9,in_stack_0000fff8),CONCAT22(iVar8,uVar16)
                        ,unaff_BP);
    uVar14 = (int)plVar11 + HeapPtr;
    iVar17 = iVar17 + (uint)CARRY2((uint)plVar11,HeapPtr);
    uVar16 = uVar14;
    if (iVar17 != 0) {
      uVar16 = 0xffff;
    }
    if (((MUSHandle.ofs != 0 || MUSHandle.seg != 0) && ((iVar17 != 0 || (MUSHandle.seg < uVar14))))
       || ((DIGHandle.ofs != 0 || DIGHandle.seg != 0 && ((iVar17 != 0 || (MUSHandle.seg < uVar14))))
          )) {
      ovr_fmFreeAudio(1);
    }
    HeapPtr = 0xffff;
    uVar14 = 0xffff;
    bVar18 = false;
    uVar24 = StshCtPtr2.seg;
    for (uVar21 = StshCtPtr2.ofs; iVar17 = (int)in_stack_0000ffee, uVar21 != 0 || uVar24 != 0;
        uVar21 = *(uint16_t *)(uVar21 + 9)) {
      uVar23 = uVar24;
      if (*(int *)(uVar21 + 0x11) != 0 || *(int *)(uVar21 + 0x13) != 0) {
        if (*(uint *)(uVar21 + 0x13) < uVar16) {
          in_stack_0000ffee = CONCAT22(0x887f,iVar17);
          (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)*(undefined2 *)(uVar21 + 0x13);
          handle.ofs = *(undefined2 *)(uVar21 + 0x11);
          (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)*(undefined2 *)(uVar21 + 0x13) >> 8);
          stshFree(handle);
          *(undefined2 *)(uVar21 + 0x13) = 0;
          *(undefined2 *)(uVar21 + 0x11) = 0;
          bVar18 = true;
          uVar23 = uVar24;
        }
        else {
          if (*(uint *)(uVar21 + 0x13) < uVar14) {
            uVar14 = *(uint *)(uVar21 + 0x13);
            in_stack_0000ffee = CONCAT22(uVar24,uVar21);
          }
          if (*(uint *)(uVar21 + 0x13) < HeapPtr) {
            HeapPtr = *(uint *)(uVar21 + 0x13);
          }
        }
      }
      uVar24 = *(uint16_t *)(uVar21 + 0xb);
    }
    if (!bVar18) {
      if (uVar14 == 0xffff) {
        bVar18 = ovr_fmFreeAudio(1);
        if (bVar18) {
          return (entity_t *)((int)(undefined4 *)&_DATA + 1);
        }
        if (audioBusy != '\0') {
          return (entity_t *)0x0;
        }
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0x14);
      }
      uVar10 = (undefined2)((ulong)in_stack_0000ffee >> 0x10);
      uVar19 = (undefined1)*(undefined2 *)(iVar17 + 0x13);
      uVar20 = (undefined1)((uint)*(undefined2 *)(iVar17 + 0x13) >> 8);
      uVar12 = 0x8939;
      (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = uVar19;
      handle_00.ofs = *(undefined2 *)(iVar17 + 0x11);
      (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = uVar20;
      stshFree(handle_00);
      *(undefined2 *)(iVar17 + 0x13) = 0;
      *(undefined2 *)(iVar17 + 0x11) = 0;
      HeapPtr = CONCAT11(uVar20,uVar19);
    }
    puVar3 = (undefined4 *)&_DATA;
  }
  else {
    puVar3 = (undefined4 *)&_DATA;
  }
  return (entity_t *)((int)puVar3 + 1);
}
