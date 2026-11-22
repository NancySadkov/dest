char * __cdecl16far saveui_configureMessageDelay(void)

{
  uint *puVar1;
  uint16_t *puVar2;
  uint8_t *puVar3;
  byte *pbVar4;
  undefined4 uVar5;
  char cVar6;
  undefined1 uVar7;
  uint uVar8;
  uint uVar9;
  uint16_t uVar10;
  char *pcVar11;
  uint8_t *puVar12;
  int in_CX;
  sbyte sVar13;
  undefined2 in_DX;
  entity_t *peVar14;
  uint *puVar15;
  int iVar16;
  byte *unaff_SI;
  uint unaff_DI;
  undefined2 uVar18;
  undefined2 uVar19;
  uint16_t unaff_SS;
  byte abStackY_15bc [5516];
  undefined2 uStackY_30;
  undefined2 uStackY_2e;
  undefined2 uStackY_2c;
  far_t items;
  uint8_t menuLabel;
  char *pcStack_22;
  entity_t *uStack_1e;   /* hand fix: ->base deref */
  undefined2 uStack_1a;
  undefined2 uStack_18;
  int iStack_16;
  int iStack_14;
  int iStack_12;
  undefined1 uStack_f;
  char acStack_e [6];
  uint16_t uStack_8;
  uint16_t uStack_6;
  byte bStack_4;
  byte bStack_3;
  byte bVar17;
  
  bStack_3 = 0;
  GMenuItem = '\x01';
  while( true ) {
    ovr_resetTextBlitCycle();
    saveui_blitPanel();
    pcStack_22 = (char *)CONCAT22(menuLabel,(char *)(uint)MessageDelay);
    pcVar11 = ovr_fmVsprintf("Message delay is now %d.",pcStack_22);
    pcStack_22 = (char *)CONCAT22(menuLabel,in_DX);
    ovr_say(pcVar11);
    if (MessageDelay == 0) {
      uStack_1e = (entity_t *)0x0;
      uVar10 = 0;
    }
    else {
      uStack_1e = (entity_t *)0x2410;
      uVar10 = 0x2765;
    }
    if (MessageDelay < 0x28) {
      uStack_1a = 0x2410;
      uStack_1e = (entity_t *)CONCAT22(0x277c,(entity_t *)uStack_1e);
    }
    else {
      uStack_1a = 0;
    }
    iStack_16 = 0x2410;
    uStack_18 = 0x2793;
    iStack_12 = 0x2410;
    iStack_14 = 0x2798;
    pcStack_22 = (char *)CONCAT22(uVar10,CONCAT11(0x24,GMenuItem));
    items.seg = 4;
    items.ofs = unaff_SS;
    puVar12 = &menuLabel;
    uStackY_2c = 0x279d;
    uStackY_2e = 0x22c4;
    uStackY_30 = 0x662e;
    uiMenuSub((char *)CONCAT22(puVar12,(char *)0x26510),items,CONCAT11(0x24,GMenuItem),
              uVar10);
    bStack_4 = (byte)puVar12;
    uVar9 = (uint)puVar12 & 0xff;
    if (uVar9 < 5) break;
    if ((char *)(uint)bStack_3 != (char *)0x0) {
      return (char *)(uint)bStack_3;
    }
  }
  puVar15 = (uint *)(uVar9 * 2);
  uVar19 = 0x4000;
  switch(uVar9) {
  default:
    if (GMenuItem == '\0') {
      pcVar11 = (char *)0x2400;
    }
    else {
      pcVar11 = (char *)CONCAT11(0x24,GMenuItem + (char)uStack_6);
    }
    GMenuFlag = 0;
    return pcVar11;
  case 1:
    bVar17 = *unaff_SI;
    *(uint *)((byte *)((int)puVar15 + (int)unaff_SI) + -0x6af7) =
         *(uint *)((byte *)((int)puVar15 + (int)unaff_SI) + -0x6af7) | unaff_DI;
    *(uint *)(&stack0x0007 + (int)unaff_SI) =
         *(uint *)(&stack0x0007 + (int)unaff_SI) | (uint)unaff_SI;
    puVar1 = (uint *)(&stack0xffff + unaff_DI);
    *puVar1 = *puVar1 | unaff_DI;
    *puVar15 = *puVar15 | (uint)&stack0xffff;
                    /* WARNING: Read-only address (ram,0x00025f09) is written */
    (*(uint16_t *)((uint8_t *)&(s_fighters__residence_2410_1e09))) = (uint)&stack0xffde | 0x6966;
    bVar17 = (byte)((uint)puVar15 >> 8) | (byte)in_CX | bVar17 | (byte)unaff_DI;
    iVar16 = CONCAT11(bVar17,(byte)puVar15);
    pbVar4 = (byte *)(iVar16 + -0x51f8);
    *pbVar4 = *pbVar4 | bVar17;
    ((char *)0x2c508)[unaff_DI] =
         ((char *)0x2c508)[unaff_DI] | (byte)in_DX | (byte)puVar15;
    unaff_SI[iVar16 + 8] = unaff_SI[iVar16 + 8] | bVar17;
    (&stack0x0007)[(int)unaff_SI] = (&stack0x0007)[(int)unaff_SI] | (byte)puVar12;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 2:
    ((byte *)((int)puVar15 + (int)unaff_SI))[-0x75] =
         ((byte *)((int)puVar15 + (int)unaff_SI))[-0x75] + (byte)in_DX;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 3:
    break;
  }
switchD_4000_6642_caseD_3:
  *(int *)(abStackY_15bc + (int)unaff_SI) = *(int *)(abStackY_15bc + (int)unaff_SI) + in_CX;
  if (uVar9 == 0) {
    pcStack_22 = (char *)CONCAT22(menuLabel,uVar19);
    ovr_ovc15_clearVisited();
    uVar19 = (undefined2)((ulong)uStack_1e >> 0x10);
    peVar14 = (entity_t *)uStack_1e;
    uStack_1a = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),(char)((ulong)((peVar14->base).animFrame + 0xf) / 0x10));
    if (((peVar14->base).target & 1) == 0) {
      iStack_16 = 0;
    }
    else {
      iStack_16 = (peVar14->base).target - 2;
    }
    while( true ) {
      uVar19 = 0x2322;
      cVar6 = (char)uStack_1a;
      uStack_1a = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),(char)uStack_1a + -1);
      if (cVar6 == '\0') break;
      pcStack_22 = (char *)((ulong)pcStack_22 & 0xffff0000);
      ovr_ovc15_textArena(unaff_DI);
    }
  }
  else if ((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) == '\0') {
    uStack_1a = (uint)(byte)((ulong)((((entity_t *)uStack_1e)->base).animFrame + 0xf) / 0x10);
    while( true ) {
      cVar6 = (char)uStack_1a;
      uStack_1a = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),(char)uStack_1a + -1);
      if (cVar6 == '\0') break;
      pcStack_22 = (char *)CONCAT22(menuLabel,DAT_2000_d190);
      uVar19 = 0x22ff;
      ovr_agnt_usesAgntCount6(Entities + unaff_DI);
    }
  }
  else if (((char)uStack_18 != '\0') && ((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)) != '\0')) {
    pcStack_22 = (char *)CONCAT22(menuLabel,unaff_DI);
    uVar7 = manage_usesLitoa103();
    uStack_1a = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),uVar7);
    while ((char)uStack_1a != '\0') {
      uVar19 = (undefined2)((ulong)uStack_1e >> 0x10);
      if (((((entity_t *)uStack_1e)->base).target & 1) == 0) {
        iStack_16 = 0;
      }
      else {
        iStack_16 = (((entity_t *)uStack_1e)->base).target - 2;
      }
      pcStack_22 = (char *)((ulong)pcStack_22 & 0xffff0000);
      uVar19 = 0x2322;
      pcVar11 = ovr_ovc15_textArena(unaff_DI);
      if (((uint)pcVar11 & 0xff) == 0) break;
      uStack_1a = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_1a) + 1)),(char)uStack_1a + -1);
    }
  }
  do {
    do {
      do {
        unaff_DI = unaff_DI + 1;
        if (EntityCount <= unaff_DI) {
          GGameState = 0x3c;
          uVar18 = uVar19;
          if (DebugVerbose != false) {
            pcStack_22 = (char *)CONCAT22(menuLabel,debugStaleTickCount);
            uVar18 = 0x1000;
            uStackY_2e = 0x878;
            uStackY_2c = uVar19;
            printf("%d %d %d  \r");
          }
          func_0x0004fcda();
          GGameState = 0x3d;
          if (DebugVerbose != false) {
            uStackY_2e = 0x8b3;
            uStackY_2c = uVar18;
            printf("%d %d %d  \r");
          }
          ovr_OVC23_55fe_29a2_entry();
          GGameState = 0xc;
          if (DebugVerbose != false) {
            uStackY_2c = 0x236f;
            uStackY_2e = 0x8ef;
            printf("%d %d %d  \r");
          }
          uVar19 = 0x2379;
          ovr_ovc24_removeOtherEntities((uint8_t *)((int)&uStack_18 + 1));
          GGameState = 0x1f;
          if ((*(uint8_t *)((uint8_t *)&(uStack_18) + 1)) != '\0') {
            uVar19 = 0x22ef;
            ovr_constr_usesBlitRect();
            GGameState = 0x13;
          }
          pcStack_22 = (char *)CONCAT22(menuLabel,uVar19);
          func_0x0004f68f();
          GGameState = 0x1d;
          for (uVar9 = 0; (int)uVar9 < 5; uVar9 = uVar9 + 1) {
            if (acStack_e[uVar9] != '\0') {
              pcStack_22 = (char *)CONCAT22(menuLabel,uVar9);
              uVar19 = 0x23d5;
              ovr_ovc41_usesMiceBlitRect(uVar9);
            }
          }
          GGameState = 0xd;
          uVar18 = uVar19;
          if (DebugVerbose != false) {
            pcStack_22 = (char *)CONCAT22(menuLabel,debugStaleTickCount);
            uVar18 = 0x1000;
            uStackY_2e = 0x98b;
            uStackY_2c = uVar19;
            printf("%d %d %d  \r");
          }
          pcStack_22 = (char *)CONCAT22(menuLabel,uVar18);
          ovr_ovc24_checkStrongholds();
          GGameState = 0xe;
          mapDirty = 1;
          return (char *)0x26510;
        }
        uStack_1e = (entity_t *)CONCAT22(DAT_2000_d190,Entities + unaff_DI);
        uVar8 = ovr_alignUp4(Entities[unaff_DI].base.destX);
        uVar19 = 0x2379;
        uVar9 = ovr_alignUp4((uStack_1e->base).x);
        if ((uVar8 == uVar9) &&
           (uVar18 = (undefined2)((ulong)uStack_1e >> 0x10),
           (((entity_t *)uStack_1e)->base).destY == (((entity_t *)uStack_1e)->base).y)) {
          pcStack_22 = (char *)CONCAT22(menuLabel,unaff_SS);
          uStackY_2c = 0x2379;
          uStackY_2e = 0x204;
          manage_usesCurSfxType32();
        }
        uVar18 = (undefined2)((ulong)uStack_1e >> 0x10);
        peVar14 = (entity_t *)uStack_1e;
      } while (((peVar14->base).destX == 0 && (peVar14->base).destY == 0) ||
              (*(char *)((int)&(peVar14->base).entity + 1) != '\0'));
      bStack_3 = (*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)(peVar14->base).gindex * 0x95)
                 & 0x4000) != 0;
      uStack_6 = (uStack_1e->base).x;
      uStack_8 = (peVar14->base).y;
      uStack_f = *(undefined1 *)
                  ((int)(char **)GMenuStrings + (uint)(peVar14->base).gindex * 0x95 + 0x1f);
      if ((peVar14->base).faction < (byte)(peVar14->base).state) {
        sVar13 = ((peVar14->base).faction & 3) << 1;
        in_CX = CONCAT11((char)((uint)in_CX >> 8),sVar13);
        (peVar14->base).target =
             (byte)((int)(uint)*(byte *)((int)&(peVar14->base).owner +
                                        ((int)(uint)(peVar14->base).faction >> 2)) >> sVar13) & 3;
        uStackY_2c = 0x2e4;
        cVar6 = func_0x0004f32d();
        peVar14 = (entity_t *)uStack_1e;
        uVar19 = (undefined2)((ulong)uStack_1e >> 0x10);
        if (cVar6 == '\0') {
          (uStack_1e->base).x = (uStack_1e->base).x + (int)*(char *)((peVar14->base).target + 0x885)
          ;
          puVar2 = &(peVar14->base).y;
          *puVar2 = *puVar2 + (int)*(char *)((peVar14->base).target + 0x889);
          puVar3 = &(peVar14->base).faction;
          *puVar3 = *puVar3 + 0x1;
        }
        else {
          (peVar14->base).faction = 0x0;
          *(undefined1 *)&(peVar14->base).state = 0;
        }
      }
      else {
        iStack_12 = ovr_ovc07_signum((peVar14->base).destX - (uStack_1e->base).x);
        uVar19 = (undefined2)((ulong)uStack_1e >> 0x10);
        uVar18 = 0x22da;
        iStack_14 = ovr_ovc07_signum((((entity_t *)uStack_1e)->base).destY -
                                     (((entity_t *)uStack_1e)->base).y);
        if (iStack_12 != 0) {
          uVar18 = 0x2337;
          uVar10 = ovr_randBelow(2);
          if ((char)uVar10 != '\0') {
            uStackY_2c = 0x2337;
            uStackY_2e = 0x399;
            cVar6 = sub_OVC21_manage_c_23C2();
            if (cVar6 == '\0') {
              (uStack_1e->base).x = (uStack_1e->base).x + iStack_12;
              (((entity_t *)uStack_1e)->base).target = 0x2 - (char)iStack_12;
              goto L_attact_3f0b_1082_1477;
            }
          }
        }
        if (iStack_14 != 0) {
          uStackY_2e = 0x3d8;
          uStackY_2c = uVar18;
          cVar6 = sub_OVC21_manage_c_23C2();
          if (cVar6 == '\0') {
            uVar19 = (undefined2)((ulong)uStack_1e >> 0x10);
            puVar2 = &(((entity_t *)uStack_1e)->base).y;
            *puVar2 = *puVar2 + iStack_14;
            (((entity_t *)uStack_1e)->base).target = (char)iStack_14 + 0x1;
            goto L_attact_3f0b_1082_1477;
          }
        }
        if (iStack_12 != 0) {
          uStackY_2e = 0x418;
          uStackY_2c = uVar18;
          cVar6 = sub_OVC21_manage_c_23C2();
          if (cVar6 == '\0') {
            (uStack_1e->base).x = (uStack_1e->base).x + iStack_12;
            (((entity_t *)uStack_1e)->base).target = 0x2 - (char)iStack_12;
            goto L_attact_3f0b_1082_1477;
          }
        }
        uVar8 = ovr_ovc26_usesStExit(unaff_DI);
        if ((char)uVar8 == '\0') {
          uStackY_2c = 0x2386;
          uStackY_2e = 0x4e3;
          uVar8 = ovr_ovc26_usesRandBelow
                            (unaff_DI,(int)&uStack_18 + 1,unaff_SS,(uint16_t)acStack_e,unaff_SS);
          if (((uVar8 & 0xff) == 0) &&
             (*(char *)((int)(char **)GMenuStrings +
                       (uint)(((entity_t *)uStack_1e)->base).gindex * 0x95 + 0x1f) == '\0')) {
            uStackY_2c = 0x2386;
            uStackY_2e = 0x524;
            manage_usesCurSfxType32();
          }
        }
        else {
          uVar19 = (undefined2)((ulong)uStack_1e >> 0x10);
          peVar14 = (entity_t *)uStack_1e;
          sVar13 = ((peVar14->base).faction & 3) << 1;
          in_CX = CONCAT11((char)((uint)in_CX >> 8),sVar13);
          (peVar14->base).target =
               (byte)((int)(uint)*(byte *)((int)&(peVar14->base).owner +
                                          ((int)(uint)(peVar14->base).faction >> 2)) >> sVar13) & 3;
          uStackY_2c = 0x48f;
          cVar6 = func_0x0004f32d();
          if (cVar6 == '\0') {
            uVar19 = (undefined2)((ulong)uStack_1e >> 0x10);
            peVar14 = (entity_t *)uStack_1e;
            (uStack_1e->base).x =
                 (uStack_1e->base).x + (int)*(char *)((peVar14->base).target + 0x885);
            puVar2 = &(peVar14->base).y;
            *puVar2 = *puVar2 + (int)*(char *)((peVar14->base).target + 0x889);
            puVar3 = &(peVar14->base).faction;
            *puVar3 = *puVar3 + 0x1;
          }
        }
      }
L_attact_3f0b_1082_1477:
      uStack_18 = CONCAT11(1,(char)uStack_18);
      uVar8 = ovr_alignUp4((((entity_t *)uStack_1e)->base).destX);
      uVar9 = ovr_alignUp4((uStack_1e->base).x);
      if (uVar8 == uVar9) {
        uVar19 = (undefined2)((ulong)uStack_1e >> 0x10);
        peVar14 = (entity_t *)uStack_1e;
        if ((peVar14->base).destY == (peVar14->base).y) {
          (peVar14->base).destX = 0;
          (peVar14->base).destY = 0;
          if (*(char *)((int)&(peVar14->base).entity + 3) == -1) {
            bStack_4 = 0xff;
          }
          else {
            uVar5 = *(undefined4 *)((uint)*(byte *)((int)&(peVar14->base).entity + 3) << 2);
            bStack_4 = *(byte *)((int)uVar5 + 0x89);
          }
          if (bStack_4 != 0xff) {
            for (unaff_SI = (byte *)0x0; unaff_SI < SquareRecCount; unaff_SI = unaff_SI + 1) {
              uVar8 = ovr_alignUp4(*(int *)((int)unaff_SI * 0x13));
              uVar9 = ovr_alignUp4((uStack_1e->base).x);
              if ((uVar8 == uVar9) &&
                 (*(uint16_t *)((int)unaff_SI * 0x13 + 2) == (((entity_t *)uStack_1e)->base).y)) {
                pcStack_22 = (char *)CONCAT22(menuLabel,0x17f8);
                func_0x0004f930();
                if (*(uint16_t *)((int)unaff_SI * 0x13 + 2) == GfxRndSeed2) {
                  uVar8 = ovr_alignUp4(*(int *)((int)unaff_SI * 0x13));
                  uVar9 = ovr_alignUp4(GfxRndSeed);
                  if (uVar8 == uVar9) {
                    acStack_e[bStack_4] = '\x01';
                  }
                }
                break;
              }
            }
          }
        }
      }
      uVar19 = 0x2379;
    } while (AgntFlag1 == false);
    if ((((uStack_1e->base).x < GfxRndSeed - 2U) || (GfxRndSeed + 1U < (uStack_1e->base).x)) ||
       ((((entity_t *)uStack_1e)->base).y != GfxRndSeed2)) {
      cVar6 = '\0';
    }
    else {
      cVar6 = '\x01';
    }
    uStack_1a = CONCAT11(cVar6,(char)uStack_1a);
    if (((uStack_6 < GfxRndSeed - 2U) || (GfxRndSeed + 1U < uStack_6)) || (GfxRndSeed2 != uStack_8))
    {
      bVar17 = 0;
    }
    else {
      bVar17 = 1;
    }
    uStack_18 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStack_18) + 1)),bVar17);
  } while (bVar17 == 0 && cVar6 == '\0');
  uVar9 = (uint)bVar17;
  goto switchD_4000_6642_caseD_3;
}
