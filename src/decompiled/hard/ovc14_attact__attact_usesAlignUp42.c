void __cdecl16far attact_usesAlignUp42(void)

{
  uint16_t *puVar1;
  uint8_t *puVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  char cVar5;
  bool bVar6;
  bool bVar7;
  uint uVar8;
  uint uVar9;
  undefined1 uVar13;
  uint16_t uVar10;
  uint uVar11;
  char *pcVar12;
  entity_t *peVar14;
  uint16_t unaff_DI;
  uint16_t index;
  undefined2 uVar15;
  uint unaff_SS;
  entity_t *uStack_1e;   /* hand fix: dereferenced as uStack_1e->base */
  char cStack_1a;
  uint8_t reported;
  int iStack_16;
  int iStack_14;
  int iStack_12;
  undefined1 uStack_f;
  uint8_t reportedUnits;
  uint16_t uStack_8;
  uint16_t uStack_6;
  byte bStack_4;
  undefined1 uStack_3;
  
  func_0x0004f735(0x3f0b);
  reported = 0x0;
  _fmemset((void *)(ulong)unaff_SS,5,unaff_DI);
  GGameState = 0x3f;
  if (DebugVerbose != false) {
    printf("%d %d %d \r");
  }
  uVar15 = 0x1000;
  debugStaleTickCount = 0;
  debugEmptyCellCount = 0;
  index = 0;
  do {
    uVar4 = DAT_2000_d190;
    if (EntityCount <= index) {
      GGameState = 0x3c;
      if (DebugVerbose != false) {
        uVar15 = 0x1000;
        printf("%d %d %d  \r");
      }
      func_0x0004fcda(uVar15);
      GGameState = 0x3d;
      if (DebugVerbose != false) {
        printf("%d %d %d  \r");
      }
      ovr_OVC23_55fe_29a2_entry();
      GGameState = 0xc;
      if (DebugVerbose != false) {
        printf("%d %d %d  \r");
      }
      uVar15 = 0x2379;
      ovr_ovc24_removeOtherEntities(&reported);
      GGameState = 0x1f;
      if (reported != 0x0) {
        uVar15 = 0x22ef;
        ovr_constr_usesBlitRect();
        GGameState = 0x13;
      }
      func_0x0004f68f(uVar15);
      GGameState = 0x1d;
      for (uVar8 = 0; (int)uVar8 < 5; uVar8 = uVar8 + 1) {
        if ((&reportedUnits)[uVar8] != 0x0) {
          ovr_ovc41_usesMiceBlitRect(uVar8);
        }
      }
      GGameState = 0xd;
      if (DebugVerbose != false) {
        printf("%d %d %d  \r");
      }
      ovr_ovc24_checkStrongholds();
      GGameState = 0xe;
      mapDirty = 1;
      return;
    }
    peVar14 = Entities + index;
    uStack_1e = (entity_t *)CONCAT22(DAT_2000_d190,peVar14);
    uVar8 = ovr_alignUp4((peVar14->base).destX);
    uVar15 = 0x2379;
    uVar9 = ovr_alignUp4((uStack_1e->base).x);
    if ((uVar8 == uVar9) && ((peVar14->base).destY == (peVar14->base).y)) {
      func_0x0004fb8e(0x2379,index,(peVar14->base).destX,(peVar14->base).destY);
    }
    if (((peVar14->base).destX != 0 || (peVar14->base).destY != 0) &&
       (*(char *)((int)&(peVar14->base).entity + 1) == '\0')) {
      uStack_3 = (*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)(peVar14->base).gindex * 0x95)
                 & 0x4000) != 0;
      uStack_6 = (uStack_1e->base).x;
      uStack_8 = (peVar14->base).y;
      uStack_f = *(undefined1 *)
                  ((int)(char **)GMenuStrings + (uint)(peVar14->base).gindex * 0x95 + 0x1f);
      if ((peVar14->base).faction < (byte)(peVar14->base).state) {
        uVar8 = (int)(uint)*(byte *)((int)&(peVar14->base).owner +
                                    ((int)(uint)(peVar14->base).faction >> 2)) >>
                (((peVar14->base).faction & 3) << 1) & 0xff03;
        (peVar14->base).target = (uint8_t)uVar8;
        uVar13 = (undefined1)(uVar8 >> 8);
        cVar5 = func_0x0004f32d(0x2379,(uStack_1e->base).x,(peVar14->base).y,
                                CONCAT11(uVar13,(peVar14->base).target),CONCAT11(uVar13,uStack_f));
        if (cVar5 == '\0') {
          (uStack_1e->base).x = (uStack_1e->base).x + (int)*(char *)((peVar14->base).target + 0x885)
          ;
          puVar1 = &(peVar14->base).y;
          *puVar1 = *puVar1 + (int)*(char *)((peVar14->base).target + 0x889);
          puVar2 = &(peVar14->base).faction;
          *puVar2 = *puVar2 + 0x1;
        }
        else {
          (peVar14->base).faction = 0x0;
          *(undefined1 *)&(peVar14->base).state = 0;
        }
      }
      else {
        iStack_12 = ovr_ovc07_signum((peVar14->base).destX - (uStack_1e->base).x);
        uVar15 = 0x22da;
        iStack_14 = ovr_ovc07_signum((peVar14->base).destY - (peVar14->base).y);
        if (iStack_12 != 0) {
          uVar15 = 0x2337;
          uVar10 = ovr_randBelow(2);
          if ((char)uVar10 != '\0') {
            cVar5 = func_0x0004f412(0x2337,uStack_6,uStack_8,'\x02' - (char)iStack_12,uStack_f,
                                    uStack_3);
            if (cVar5 == '\0') {
              (uStack_1e->base).x = (uStack_1e->base).x + iStack_12;
              (peVar14->base).target = 0x2 - (char)iStack_12;
              goto L_attact_3f0b_1082_1477;
            }
          }
        }
        if (iStack_14 != 0) {
          cVar5 = func_0x0004f412(uVar15,uStack_6,uStack_8,(char)iStack_14 + '\x01',uStack_f,
                                  uStack_3);
          if (cVar5 == '\0') {
            puVar1 = &(peVar14->base).y;
            *puVar1 = *puVar1 + iStack_14;
            (peVar14->base).target = (char)iStack_14 + 0x1;
            goto L_attact_3f0b_1082_1477;
          }
        }
        if (iStack_12 != 0) {
          cVar5 = func_0x0004f412(uVar15,uStack_6,uStack_8,'\x02' - (char)iStack_12,uStack_f,
                                  uStack_3);
          if (cVar5 == '\0') {
            (uStack_1e->base).x = (uStack_1e->base).x + iStack_12;
            (peVar14->base).target = 0x2 - (char)iStack_12;
            goto L_attact_3f0b_1082_1477;
          }
        }
        uVar8 = ovr_ovc26_usesStExit(index);
        if ((char)uVar8 == '\0') {
          uVar8 = ovr_ovc26_usesRandBelow
                            (index,(uint16_t)&reported,unaff_SS,(uint16_t)&reportedUnits,unaff_SS);
          if (((uVar8 & 0xff) == 0) &&
             (*(char *)((int)(char **)GMenuStrings + (uint)(peVar14->base).gindex * 0x95 + 0x1f) ==
              '\0')) {
            func_0x0004fb8e(0x2386,index,(peVar14->base).targetX,(peVar14->base).targetY);
          }
        }
        else {
          uVar8 = (int)(uint)*(byte *)((int)&(peVar14->base).owner +
                                      ((int)(uint)(peVar14->base).faction >> 2)) >>
                  (((peVar14->base).faction & 3) << 1) & 0xff03;
          (peVar14->base).target = (uint8_t)uVar8;
          uVar13 = (undefined1)(uVar8 >> 8);
          cVar5 = func_0x0004f32d(0x2386,uStack_6,uStack_8,CONCAT11(uVar13,(peVar14->base).target),
                                  CONCAT11(uVar13,uStack_f));
          if (cVar5 == '\0') {
            (uStack_1e->base).x =
                 (uStack_1e->base).x + (int)*(char *)((peVar14->base).target + 0x885);
            puVar1 = &(peVar14->base).y;
            *puVar1 = *puVar1 + (int)*(char *)((peVar14->base).target + 0x889);
            puVar2 = &(peVar14->base).faction;
            *puVar2 = *puVar2 + 0x1;
          }
        }
      }
L_attact_3f0b_1082_1477:
      reported = 0x1;
      uVar8 = ovr_alignUp4((peVar14->base).destX);
      uVar9 = ovr_alignUp4((uStack_1e->base).x);
      if ((uVar8 == uVar9) && ((peVar14->base).destY == (peVar14->base).y)) {
        (peVar14->base).destX = 0;
        (peVar14->base).destY = 0;
        if (*(char *)((int)&(peVar14->base).entity + 3) == -1) {
          bStack_4 = 0xff;
        }
        else {
          uVar3 = *(undefined4 *)((uint)*(byte *)((int)&(peVar14->base).entity + 3) << 2);
          bStack_4 = *(byte *)((int)uVar3 + 0x89);
        }
        if (bStack_4 != 0xff) {
          for (uVar8 = 0; uVar8 < SquareRecCount; uVar8 = uVar8 + 1) {
            uVar9 = ovr_alignUp4(*(int *)(uVar8 * 0x13));
            uVar11 = ovr_alignUp4((uStack_1e->base).x);
            if ((uVar9 == uVar11) && (*(uint16_t *)((uint8_t *)&SquareRecs[uVar8] + 2) == (peVar14->base).y)) {
              func_0x0004f930(0x2379,uVar8 * 0x13 + (uint)bStack_4 + 0xe,0x17f8);
              if (*(uint16_t *)((uint8_t *)&SquareRecs[uVar8] + 2) == GfxRndSeed2) {
                uVar8 = ovr_alignUp4(*(int *)(uVar8 * 0x13));
                uVar9 = ovr_alignUp4(GfxRndSeed);
                if (uVar8 == uVar9) {
                  (&reportedUnits)[bStack_4] = 0x1;
                }
              }
              break;
            }
          }
        }
      }
      uVar15 = 0x2379;
      if (AgntFlag1 != false) {
        if ((((uStack_1e->base).x < GfxRndSeed - 2U) || (GfxRndSeed + 1U < (uStack_1e->base).x)) ||
           ((peVar14->base).y != GfxRndSeed2)) {
          bVar6 = false;
        }
        else {
          bVar6 = true;
        }
        if (((uStack_6 < GfxRndSeed - 2U) || (GfxRndSeed + 1U < uStack_6)) ||
           (GfxRndSeed2 != uStack_8)) {
          bVar7 = false;
        }
        else {
          bVar7 = true;
        }
        if (bVar7 || bVar6) {
          if (bVar7) {
            if (bVar6) {
              for (cStack_1a = func_0x0004f944(); cStack_1a != '\0'; cStack_1a = cStack_1a + -1) {
                if (((peVar14->base).target & 1) == 0) {
                  iStack_16 = 0;
                }
                else {
                  iStack_16 = (peVar14->base).target - 2;
                }
                uVar15 = 0x2322;
                pcVar12 = ovr_ovc15_textArena(index);
                if (((uint)pcVar12 & 0xff) == 0) break;
              }
            }
            else {
              cStack_1a = (char)((ulong)((peVar14->base).animFrame + 0xf) / 0x10);
              while (cStack_1a != '\0') {
                uVar15 = 0x22ff;
                ovr_agnt_usesAgntCount6(Entities + index,DAT_2000_d190);
                cStack_1a = cStack_1a + -1;
              }
            }
          }
          else {
            ovr_ovc15_clearVisited();
            cStack_1a = (char)((ulong)((peVar14->base).animFrame + 0xf) / 0x10);
            if (((peVar14->base).target & 1) == 0) {
              iStack_16 = 0;
            }
            else {
              iStack_16 = (peVar14->base).target - 2;
            }
            while( true ) {
              uVar15 = 0x2322;
              if (cStack_1a == '\0') break;
              ovr_ovc15_textArena(index);
              cStack_1a = cStack_1a + -1;
            }
          }
        }
      }
    }
    index = index + 1;
  } while( true );
}
