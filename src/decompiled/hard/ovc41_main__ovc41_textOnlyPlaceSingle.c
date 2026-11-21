byte * __cdecl16far ovc41_textOnlyPlaceSingle(agnt_t *agntPtr,int agntIndex)

{
  char *pcVar1;
  undefined2 uVar2;
  char cVar3;
  agnt_t *paVar4;
  code *pcVar5;
  far_t dst;
  far_t gfx;
  far_t gfx_00;
  far_t dst_00;
  far_t gfx_01;
  far_t dst_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t dst_02;
  far_t dst_03;
  byte bVar6;
  char *pcVar7;
  byte *pbVar8;
  undefined1 extraout_AH;
  brect_t *br;
  agnt_t *paVar9;
  uint16_t uVar10;
  uint8_t *puVar11;
  int iVar12;
  char cVar13;
  uint8_t *puVar14;
  agnt_t *paVar15;
  uint uVar16;
  agnt_t *paVar17;
  undefined1 *puVar18;
  int unaff_SI;
  undefined2 *unaff_DI;
  char *pcVar19;
  int iVar20;
  uint16_t *unaff_SS;
  char acStack_1aa [104];
  undefined2 uStack_142;
  undefined2 uStack_140;
  char *pcStack_13e;
  uint16_t *count;
  undefined4 uStack_132;
  bool type;
  undefined1 uVar21;
  undefined2 uVar22;
  uint8_t uStack_120;
  undefined1 uStack_11f;
  undefined1 uStack_11e;
  undefined1 uStack_11d;
  uint16_t uStack_10e;
  uint8_t text;
  uint8_t msg;
  char acStack_80 [62];
  char acStack_42 [6];
  byte bStack_3c;
  byte bStack_3b;
  uint uStack_3a;
  agnt_t *paStack_38;
  agnt_t *paStack_36;
  agnt_t *paStack_34;
  agnt_t *paStack_32;
  agnt_t *paStack_30;
  agnt_t *paStack_2e;
  agnt_t *paStack_2c;
  agnt_t *paStack_2a;
  agnt_t *paStack_28;
  agnt_t *paStack_26;
  agnt_t *paStack_24;
  agnt_t *paStack_22;
  agnt_t *paStack_20;
  agnt_t *paStack_1e;
  agnt_t *agnt;   /* hand fix: assigned from agnt_t * paStack_N and indexed */
  uint16_t uStack_1a;
  uint16_t uStack_18;
  brect_t bStack_16;
  agnt_t *paStack_c;
  int iStack_a;
  undefined2 uStack_8;
  far_t fStack_6;
  
  iVar12 = 0x10;
  pcStack_13e = (char *)0x6a8f;
  uStack_140 = 0xc98c;
  dst.seg = (uint16_t)unaff_SS;
  dst.ofs = (uint16_t)&agnt;
  count = unaff_SS;
  F_SCOPY(far_from_u32((uint32_t)(0x24106e38)),dst);
  paVar4 = (agnt_t *)((long)agntIndex * 0x34);
  paVar9 = (agnt_t *)paVar4;
  paStack_c = paVar9;
  iStack_a = 0x1726;
  if ((paVar9->flags & 0x820) == 0) {
    pcVar19 = (char *)((ulong)agntPtr >> 0x10);
    paVar17 = (agnt_t *)agntPtr;
    paVar17->flags = paVar17->flags & 0xfff7;
    if ((((entity_t *)paVar17->entity)->base).level < 8) {
      fStack_6 = far_from_u32((uint32_t)(far_to_u32(fStack_6) & 0xffffff));
    }
    else if ((((entity_t *)paVar17->entity)->base).level < 10) {
      (*(uint8_t *)((uint8_t *)&(fStack_6.seg) + 1)) = 1;
    }
    else if ((((entity_t *)paVar17->entity)->base).level < 0xc) {
      (*(uint8_t *)((uint8_t *)&(fStack_6.seg) + 1)) = 2;
    }
    else {
      (*(uint8_t *)((uint8_t *)&(fStack_6.seg) + 1)) = 3;
    }
    uVar16 = (uint)(*(uint8_t *)((uint8_t *)&(fStack_6.seg) + 1));
    type = SUB21(unaff_SS,0);
    uVar21 = (undefined1)((uint)unaff_SS >> 8);
    if (uVar16 < 4) {
      iVar20 = 0x6000;
      switch(uVar16) {
      case 0:
        return (byte *)((int)(undefined4 *)&_DATA + 1);
      case 2:
        cVar3 = *(char *)(uVar16 * 2 + unaff_SI);
        puVar18 = &stack0xfffe + unaff_SI;
        iVar20 = uVar16 * 3;
        *(undefined1 **)((char *)0x7501 + iVar20) =
             puVar18 + *(int *)((char *)0x7501 + iVar20);
        *(int *)(&stack0xffff + (int)puVar18) = *(int *)(&stack0xffff + (int)puVar18) + iVar20;
        *(int *)(&stack0xfffe + (int)unaff_DI) = *(int *)(&stack0xfffe + (int)unaff_DI) + iVar20;
                    /* WARNING: Read-only address (ram,0x00033501) is written */
        iRam00033501 = uVar16 + 0x8b26;
        cVar13 = (char)(&stack0xfed8 + (int)unaff_DI +
                       CONCAT11((char)((ulong)paVar4 >> 0x18),(char)((ulong)paVar4 >> 0x10) + cVar3)
                       );
        pcVar19 = (char *)(uint)(byte)((char)iVar20 + cVar13);
        (&stack0x6ffe)[(int)puVar18] = (&stack0x6ffe)[(int)puVar18];
        pcVar1 = pcVar19;
        *pcVar1 = *pcVar1 + cVar13;
        *(undefined2 *)(&stack0xfed6 + (int)unaff_DI) = 0x6000;
        pcVar1 = pcVar19 + -0x61f9;
        *pcVar1 = *pcVar1;
        cVar13 = *pcVar1;
        *(undefined1 **)(&stack0xfeda + (int)unaff_DI) = &stack0xfedc + (int)unaff_DI;
        uVar22 = *(undefined2 *)(&stack0xfeda + (int)unaff_DI);
        *(undefined2 *)(&stack0xfeda + (int)unaff_DI) = uVar22;
        if (iVar12 == 1 || cVar13 == '\0') {
          s_constructing_2410_06a4[10] = -0x6b;
          s_constructing_2410_06a4[0xb] = '\x06';
                    /* WARNING: Read-only address (ram,0x000247ae) is written */
        }
        uVar2 = in(&stack0xfed8 + (int)unaff_DI +
                   CONCAT11((char)((ulong)paVar4 >> 0x18),(char)((ulong)paVar4 >> 0x10) + cVar3));
        *unaff_DI = uVar2;
        *(undefined2 *)(&stack0xfed8 + (int)unaff_DI) = uVar22;
        *(undefined2 *)(&stack0xfed6 + (int)unaff_DI) = uVar22;
        *(undefined2 *)(&stack0xfed4 + (int)unaff_DI) = uVar22;
        *(undefined2 *)(&stack0xfed4 + (int)unaff_DI) =
             *(undefined2 *)(&stack0xfed4 + (int)unaff_DI);
        pcVar5 = (code *)swi(1);
        pbVar8 = (byte *)(*pcVar5)();
        return pbVar8;
      case 3:
        do {
          TextBlitDstSeg = 0xa000;
          TextBlitX = uStack_8 + 6;
          TextBlitY = (uint16_t)(unaff_DI + 1);
          (*(uint16_t *)((uint8_t *)&(uStack_132))) = (uint16_t)(agnt_t *)(&paVar17->x + unaff_SI * 2)[1];
          puVar14 = (uint8_t *)(&paVar17->x)[unaff_SI * 2];
          fStack_6.seg = (uint16_t)(agnt_t *)uStack_132;
          fStack_6.ofs = (uint16_t)puVar14;
          iVar12 = unaff_SI;
          if (*(uint8_t *)MK_FP(fStack_6.seg, fStack_6.ofs) == 0x25) {
            BlitLetterType = 2;
            uVar22 = 0x13f;
            (*(uint16_t *)((uint8_t *)&(uStack_132) + 2)) = FontMain.ofs;
            pcVar7 = (char *)ovr_ovc45_compute9(acStack_80,(char *)CONCAT22(puVar14 + 1,unaff_SS),
                                                (char *)CONCAT22(FontMain.ofs,(agnt_t *)uStack_132),
                                                FontMain.seg,'E');
            ovr_blitLabel(pcVar7,(uint8_t *)CONCAT22(uVar22,puVar14),15,uStack_120);
            pbVar8 = (byte *)((char *)0x2410);
            BlitLetterType = 0;
          }
          else if (*(uint8_t *)MK_FP(fStack_6.seg, fStack_6.ofs) == 0x40) {
            uVar22 = 0x13f;
            (*(uint16_t *)((uint8_t *)&(uStack_132) + 2)) = FontMain.ofs;
            pcVar7 = (char *)ovr_ovc45_compute9(acStack_80,(char *)CONCAT22(puVar14 + 1,unaff_SS),
                                                (char *)CONCAT22(FontMain.ofs,(agnt_t *)uStack_132),
                                                FontMain.seg,'E');
            pbVar8 = (byte *)ovr_blitLabel(pcVar7,(uint8_t *)CONCAT22(uVar22,puVar14),15,uStack_120)
            ;
          }
          else {
            uVar22 = 0x13f;
            (*(uint16_t *)((uint8_t *)&(uStack_132) + 2)) = FontMain.ofs;
            (*(uint16_t *)((uint8_t *)&(uStack_132))) = (uint16_t)(agnt_t *)(&paVar17->x + unaff_SI * 2)[1];
            pcVar7 = (char *)ovr_ovc45_compute9(acStack_80,
                                                (char *)CONCAT22((&paVar17->x)[unaff_SI * 2],
                                                                 unaff_SS),
                                                (char *)CONCAT22(FontMain.ofs,(agnt_t *)uStack_132),
                                                FontMain.seg,'E');
            pbVar8 = (byte *)ovr_blitLabel(pcVar7,(uint8_t *)CONCAT22(uVar22,puVar14),15,uStack_120)
            ;
          }
          while( true ) {
            unaff_DI = unaff_DI + 7;
            unaff_SI = iVar12 + 1;
            if (agntIndex <= unaff_SI) {
              if (goldPartyIndex != 0xff) {
                pbVar8 = (byte *)CONCAT11((char)((uint)pbVar8 >> 8),goldPartyIndex);
                ovc28_drawGold(goldPartyIndex);
              }
              return pbVar8;
            }
            if ((&paVar17->targetX)[iVar12 * 2] != 0 || (&paVar17->targetX + iVar12 * 2)[1] != 0)
            break;
            pbVar8 = (byte *)0x0;
            iVar12 = unaff_SI;
          }
          uStack_11e = (undefined1)butt01Cut5Seg;
          uStack_11d = (undefined1)((uint)butt01Cut5Seg >> 8);
          uStack_120 = (uint8_t)butt01Cut5Ofs;
          (*(uint8_t *)((uint8_t *)&(gfx_03.seg))) = uStack_11e;
          gfx_03.ofs = butt01Cut5Ofs;
          (*(uint8_t *)((uint8_t *)&(gfx_03.seg) + 1)) = uStack_11d;
          (*(uint8_t *)((uint8_t *)&(dst_03.seg))) = 0;
          dst_03.ofs = uStack_8 + (int)unaff_DI * 0x140;
          (*(uint8_t *)((uint8_t *)&(dst_03.seg) + 1)) = 0xa0;
          ovr_blitLoadRleGfx(gfx_03,dst_03);
        } while( true );
      }
switchD_6000_ca06_caseD_1:
      (&stack0xfffe)[(int)unaff_DI] = (&stack0xfffe)[(int)unaff_DI] + (char)iVar12;
      *(undefined1 *)((int)unaff_DI + 0x15) = 0;
      (*(uint16_t *)((uint8_t *)&(uStack_132))) = (uint16_t)(agnt_t *)0x6a64;
      (*(uint16_t *)((uint8_t *)&(uStack_132) + 2)) = iVar20;
      bStack_3b = ovr_init2_usesCFGMice
                            ((uint16_t *)&paStack_2e,
                             (uint16_t *)
                             CONCAT13((char)((uint)&paStack_30 >> 8),
                                      CONCAT12((char)&paStack_30,unaff_SS)));
      while( true ) {
        if (rightButtonLatch != '\0') goto L_ui_unit_order_6616_0689_1054;
        if ((paStack_2e != paStack_2a) || (paStack_30 != paStack_2c)) {
          paStack_2a = paStack_2e;
          agnt = paStack_2e;
          paStack_2c = paStack_30;
          paStack_1e = paStack_30;
        }
        if (bStack_3b != 0) break;
        (*(uint16_t *)((uint8_t *)&(uStack_132) + 2)) = 0x22de;
        (*(uint16_t *)((uint8_t *)&(uStack_132))) = (uint16_t)(agnt_t *)0x69b5;
        uVar22 = keyprocessor_usesBiosKeyAvail
                           ((uint16_t *)CONCAT13(uVar21,CONCAT12(type,&paStack_36)),
                            (uint16_t *)CONCAT22(unaff_SS,&paStack_38),
                            (byte *)CONCAT22(unaff_SS,&bStack_3b));
        if ((char)uVar22 != '\0') goto L_ui_unit_order_6616_0689_1054;
        if ((paStack_36 != paStack_32) || (paStack_38 != paStack_34)) {
          paStack_32 = paStack_36;
          agnt = paStack_36;
          paStack_34 = paStack_38;
          paStack_1e = paStack_38;
          bStack_16.seg = uStack_8;
          gfx_00.seg = uStack_18;
          gfx_00.ofs = uStack_1a;
          dst_00.seg = uStack_8;
          dst_00.ofs = 0x8cc;
          ovr_blitLoadRleGfx(gfx_00,dst_00);
          (*(uint16_t *)((uint8_t *)&(uStack_132) + 2)) = 0x6a2a;
          (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)MiceCursors[3].seg;
          gfx.ofs = MiceCursors[3].ofs;
          (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)(MiceCursors[3].seg >> 8);
          ovr_blitGfx10(gfx,(uint16_t)&paStack_36[-1].variant,(uint16_t)&paStack_38[-1].faction,
                        &bStack_16,type);
          ovr_miceBlitRect(&bStack_16);
          ovr_blitRect(&bStack_16);
          ovr_miceUpdate();
        }
        iVar20 = 0x22de;
        if (bStack_3b == 0) goto switchD_6000_ca06_caseD_1;
      }
      if (((((int)agnt < 0xc) || (0xde < (int)agnt)) || ((int)paStack_1e < 7)) ||
         (0x96 < (int)paStack_1e)) goto L_ui_unit_order_6616_0689_1054;
      do {
        iVar12 = 0x22de;
        (*(uint16_t *)((uint8_t *)&(uStack_132))) = (uint16_t)(agnt_t *)0x6ae3;
        bVar6 = ovr_init2_usesCFGMice
                          ((uint16_t *)&paStack_2e,(uint16_t *)CONCAT22(&paStack_30,unaff_SS));
      } while (CONCAT11(extraout_AH,bVar6) != 0);
      paStack_26 = (agnt_t *)0xffff;
      paStack_28 = (agnt_t *)0xffff;
      paStack_20 = paStack_1e;
      bStack_3b = 0;
      paVar9 = agnt;
      do {
        (*(uint16_t *)((uint8_t *)&(uStack_132))) = (uint16_t)(agnt_t *)0x6b14;
        (*(uint16_t *)((uint8_t *)&(uStack_132) + 2)) = iVar12;
        uVar22 = keyprocessor_usesBiosKeyAvail
                           ((uint16_t *)CONCAT13(uVar21,CONCAT12(type,&paStack_36)),
                            (uint16_t *)CONCAT22(unaff_SS,&paStack_38),
                            (byte *)CONCAT22(unaff_SS,&bStack_3b));
        if ((char)uVar22 != '\0') goto L_ui_unit_order_6616_0689_1054;
        if ((paStack_36 != paStack_32) || (paStack_38 != paStack_34)) {
          paStack_32 = paStack_36;
          paStack_34 = paStack_38;
          paStack_20 = paStack_38;
          paVar9 = paStack_36;
        }
        if ((int)paVar9 < 0xc) {
          paVar9 = (agnt_t *)((byte *)__C0_ASM_CopyRight + 8);
        }
        if (0xde < (int)paVar9) {
          paVar9 = (agnt_t *)0xde;
        }
        if ((int)paStack_20 < 7) {
          paStack_20 = (agnt_t *)((byte *)__C0_ASM_CopyRight + 3);
        }
        if (0x96 < (int)paStack_20) {
          paStack_20 = (agnt_t *)((char *)0x96);
        }
        if ((paStack_26 != paVar9) || (paStack_28 != paStack_20)) {
          bStack_16.seg = uStack_8;
          uStack_120 = (uint8_t)uStack_8;
          uStack_11f = (undefined1)(uStack_8 >> 8);
          gfx_01.seg = uStack_18;
          gfx_01.ofs = uStack_1a;
          (*(uint8_t *)((uint8_t *)&(dst_01.seg))) = uStack_120;
          dst_01.ofs = 0x8cc;
          (*(uint8_t *)((uint8_t *)&(dst_01.seg) + 1)) = uStack_11f;
          ovr_blitLoadRleGfx(gfx_01,dst_01);
          ovr_driver_drawLine((uint8_t *)agnt,(int)paStack_1e,(uint8_t *)paVar9,(int)paStack_1e,
                              0xff);
          ovr_driver_drawLine((uint8_t *)agnt,(int)paStack_1e,(uint8_t *)agnt,(int)paStack_20,0xff
                             );
          ovr_driver_drawLine((uint8_t *)paVar9,(int)paStack_1e,(uint8_t *)paVar9,(int)paStack_20,
                              0xff);
          ovr_driver_drawLine((uint8_t *)agnt,(int)paStack_20,(uint8_t *)paVar9,(int)paStack_20,
                              0xff);
          ovr_miceBlitRect(&bStack_16);
          ovr_blitRect(&bStack_16);
          ovr_miceUpdate();
          paVar17 = (agnt_t *)((int)&paStack_20[-1].flags / 3 + Seed_2000_d10e);
          paVar15 = (agnt_t *)(Seed_2000_d110 + ((uint)&paVar9[-1].screenY >> 1) + 2 & 0xfffc);
          paStack_24 = (agnt_t *)((int)&paStack_1e[-1].flags / 3 + Seed_2000_d10e);
          paStack_22 = (agnt_t *)(Seed_2000_d110 + ((uint)&agnt[-1].screenY >> 1) + 2 & 0xfffc);
          paStack_26 = paVar15;
          if ((int)paVar15 < (int)paStack_22) {
            paStack_26 = paStack_22;
            paStack_22 = paVar15;
            paStack_c = paVar15;
          }
          paStack_28 = paVar17;
          if ((int)paVar17 < (int)paStack_24) {
            paStack_28 = paStack_24;
            paStack_24 = paVar17;
            paStack_c = paVar17;
          }
          iStack_a = 0;
          for (uVar16 = 0; uVar16 < EntityCount; uVar16 = uVar16 + 1) {
            uVar22 = (undefined2)((ulong)Entities >> 0x10);
            iVar12 = (int)Entities;
            if ((((*(byte *)(iVar12 + uVar16 * 0x37 + 0x1a) == bStack_3c) &&
                 (paStack_22 <= (agnt_t *)*(uint *)(iVar12 + uVar16 * 0x37))) &&
                ((agnt_t *)*(uint *)(iVar12 + uVar16 * 0x37) <= paStack_26)) &&
               ((paStack_24 <= (agnt_t *)*(uint *)(iVar12 + uVar16 * 0x37 + 2) &&
                ((agnt_t *)*(uint *)(iVar12 + uVar16 * 0x37 + 2) <= paStack_28)))) {
              iStack_a = iStack_a + 1;
            }
          }
          ovr_resetTextBlitCycle();
          ovr_ovc45_compute9(acStack_1aa,
                             (char *)CONCAT22(*(undefined2 *)((uint)bStack_3c * 4),unaff_SS),
                             (char *)CONCAT22(Font03.ofs,
                                              (char *)((undefined2 *)((uint)bStack_3c * 4))[1]),
                             Font03.seg,'C');
          ovr_ovc41_pluralSuffix(iStack_a);
          uVar10 = 0x2410;
          pcVar19 = ovr_stsprintf((char *)&uStack_132,(char *)CONCAT22(0x64b8,unaff_SS),
                                  (char *)CONCAT22(iStack_a,(char *)0x2410));
          iVar12 = 0x22c4;
          ovr_uiNotify(pcVar19,uVar10);
        }
        paStack_28 = paStack_20;
        paStack_26 = paVar9;
        if (bStack_3b == 0) {
          iVar12 = 0x22de;
          (*(uint16_t *)((uint8_t *)&(uStack_132))) = (uint16_t)(agnt_t *)0x6e04;
          bStack_3b = ovr_init2_usesCFGMice
                                ((uint16_t *)&paStack_2e,(uint16_t *)CONCAT22(&paStack_30,unaff_SS))
          ;
        }
        if (rightButtonLatch != '\0') goto L_ui_unit_order_6616_0689_1054;
        if ((paStack_2e != paStack_2a) || (paStack_30 != paStack_2c)) {
          paStack_2a = paStack_2e;
          paStack_2c = paStack_30;
          paStack_20 = paStack_30;
          paVar9 = paStack_2e;
        }
      } while (bStack_3b == 0);
      uStack_142 = 0x6e56;
      ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
      if (((((int)paVar9 < 0xc) || (0xde < (int)paVar9)) || ((int)paStack_20 < 7)) ||
         (0x96 < (int)paStack_20)) {
L_ui_unit_order_6616_0689_1054:
        ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
        ovr_say((char *)"Region selection aborted.");
      }
      else {
        paVar17 = (agnt_t *)((int)&paStack_20[-1].flags / 3 + Seed_2000_d10e);
        paVar15 = (agnt_t *)(Seed_2000_d110 + ((uint)&paVar9[-1].screenY >> 1) + 2 & 0xfffc);
        paVar9 = (agnt_t *)((int)&paStack_1e[-1].flags / 3 + Seed_2000_d10e);
        uVar16 = Seed_2000_d110 + ((uint)&agnt[-1].screenY >> 1) + 2;
        paStack_22 = (agnt_t *)(uVar16 & 0xfffc);
        paStack_26 = paVar15;
        if ((int)paVar15 < (int)paStack_22) {
          paStack_c = (agnt_t *)(uVar16 & 0xfffc);
          paStack_26 = paStack_c;
          paStack_22 = paVar15;
        }
        paStack_28 = paVar17;
        paStack_24 = paVar9;
        if ((int)paVar17 < (int)paVar9) {
          paStack_28 = paVar9;
          paStack_24 = paVar17;
          paStack_c = paVar9;
        }
        pcStack_13e = acStack_42;
        uStack_140 = 0x22de;
        uStack_142 = 0x6f2a;
        _fmemset((void *)ZEXT24(unaff_SS),5,(uint16_t)count);
        iStack_a = 0;
        for (uVar16 = 0; uVar16 < EntityCount; uVar16 = uVar16 + 1) {
          uVar22 = (undefined2)((ulong)Entities >> 0x10);
          iVar12 = (int)Entities;
          if (((*(byte *)(iVar12 + uVar16 * 0x37 + 0x1a) == bStack_3c) &&
              (paStack_22 <= (agnt_t *)*(uint *)(iVar12 + uVar16 * 0x37))) &&
             (((agnt_t *)*(uint *)(iVar12 + uVar16 * 0x37) <= paStack_26 &&
              ((paStack_24 <= (agnt_t *)*(uint *)(iVar12 + uVar16 * 0x37 + 2) &&
               ((agnt_t *)*(uint *)(iVar12 + uVar16 * 0x37 + 2) <= paStack_28)))))) {
            if (bStack_3b < 2) {
              unit_usesAlignUp42((byte)agntPtr,*(uint16_t *)(iVar12 + uVar16 * 0x37),
                                 *(int *)(iVar12 + uVar16 * 0x37 + 2));
            }
            else {
              pcStack_13e = (char *)0x6fdf;
              unit_usesEntities(bStack_3b,uVar16,(uint16_t)acStack_42,(uint16_t)unaff_SS);
            }
            iStack_a = iStack_a + 1;
          }
        }
        for (uStack_3a = 0; (int)uStack_3a < 5; uStack_3a = uStack_3a + 1) {
          if (acStack_42[uStack_3a] != '\0') {
            ovr_ovc41_usesMiceBlitRect(uStack_3a);
          }
        }
        ovr_constr_flushDirtyRects();
        (*(uint16_t *)((uint8_t *)&(uStack_132) + 2)) = 0x22ef;
        (*(uint16_t *)((uint8_t *)&(uStack_132))) = (uint16_t)(agnt_t *)0x7063;
        ovr_resetTextBlitCycle();
        if (bStack_3b == 1) {
          (*(uint16_t *)((uint8_t *)&(uStack_132) + 2)) = 0x7071;
          ovr_ovc41_pluralSuffix(iStack_a);
          (*(uint16_t *)((uint8_t *)&(uStack_132) + 2)) = iStack_a;
          (*(uint16_t *)((uint8_t *)&(uStack_132))) = (uint16_t)(agnt_t *)0x2410;
          pcVar19 = ovr_stsprintf((char *)&uStack_132,(char *)CONCAT22(0x6522,unaff_SS),
                                  (char *)CONCAT22(iStack_a,(char *)0x2410));
          ovr_say(pcVar19);
        }
        else if (bStack_3b == 2) {
          (*(uint16_t *)((uint8_t *)&(uStack_132) + 2)) = 0x70bf;
          ovr_ovc41_pluralSuffix(iStack_a);
          (*(uint16_t *)((uint8_t *)&(uStack_132) + 2)) = iStack_a;
          (*(uint16_t *)((uint8_t *)&(uStack_132))) = (uint16_t)(agnt_t *)0x2410;
          pcVar19 = ovr_stsprintf((char *)&uStack_132,(char *)CONCAT22(0x6543,unaff_SS),
                                  (char *)CONCAT22(iStack_a,(char *)0x2410));
          ovr_say(pcVar19);
        }
        else if (bStack_3b == 3) {
          (*(uint16_t *)((uint8_t *)&(uStack_132) + 2)) = 0x710d;
          ovr_ovc41_pluralSuffix(iStack_a);
          (*(uint16_t *)((uint8_t *)&(uStack_132) + 2)) = iStack_a;
          (*(uint16_t *)((uint8_t *)&(uStack_132))) = (uint16_t)(agnt_t *)0x2410;
          pcVar19 = ovr_stsprintf((char *)&uStack_132,(char *)CONCAT22(0x6557,unaff_SS),
                                  (char *)CONCAT22(iStack_a,(char *)0x2410));
          ovr_say(pcVar19);
        }
        else if (bStack_3b == 4) {
          (*(uint16_t *)((uint8_t *)&(uStack_132) + 2)) = 0x715a;
          ovr_ovc41_pluralSuffix(iStack_a);
          (*(uint16_t *)((uint8_t *)&(uStack_132) + 2)) = iStack_a;
          (*(uint16_t *)((uint8_t *)&(uStack_132))) = (uint16_t)(agnt_t *)0x2410;
          pcVar19 = ovr_stsprintf((char *)&uStack_132,(char *)CONCAT22(0x6568,unaff_SS),
                                  (char *)CONCAT22(iStack_a,(char *)0x2410));
          ovr_say(pcVar19);
        }
        ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x24));
      }
      bStack_16.seg = uStack_8;
      uStack_120 = (uint8_t)uStack_18;
      uStack_11f = (undefined1)(uStack_18 >> 8);
      (*(uint8_t *)((uint8_t *)&(gfx_02.seg))) = uStack_120;
      gfx_02.ofs = uStack_1a;
      (*(uint8_t *)((uint8_t *)&(gfx_02.seg) + 1)) = uStack_11f;
      dst_02.seg = uStack_8;
      dst_02.ofs = 0x8cc;
      ovr_blitLoadRleGfx(gfx_02,dst_02);
      ovr_miceBlitRect(&bStack_16);
      br = &bStack_16;
      ovr_blitRect(br);
      ovr_miceUpdate();
      stack0xfef4 = uStack_18;
      uStack_10e = uStack_1a;
      ovr_stshFree(uStack_10e);
      ovr_stshFree(fStack_6);
      ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
      return (byte *)br;
    }
    bVar6 = paVar9->strength;
    paVar9->strength = paVar9->strength + (char)fStack_6.ofs;
    if (paVar9->strengthMax < paVar9->strength) {
      paVar9->strength = paVar9->strengthMax;
    }
    puVar14 = &paVar9->strength;
    paVar9 = (agnt_t *)(uint)*puVar14;
    if (*puVar14 != bVar6) {
      (*(uint16_t *)((uint8_t *)&(uStack_132) + 2)) = 0xcae7;
      (*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) = bVar6;
      uVar10 = ovr_audio_panFromX(paVar17);
      ovr_play_sfxU(0x3b,0,uVar10);
      ovc41_pluralSuffix((uint)paStack_c->strength);
      ovc41_pluralSuffix((uint)paStack_c->strength - (uint)(*(uint8_t *)((uint8_t *)&(uStack_8) + 1)));
      (*(uint16_t *)((uint8_t *)&(uStack_132) + 2)) = 0x22f8;
      (*(uint16_t *)((uint8_t *)&(uStack_132))) = (uint16_t)(agnt_t *)0xcb5a;
      ovr_agnt_statusText(paStack_c,
                          (char *)CONCAT13((char)((uint)&stack0xfecc >> 8),
                                           CONCAT12((char)&stack0xfecc,iStack_a)));
      puVar14 = &agnt;
      uStack_132 = agntPtr;
      pcVar19 = ovr_agnt_statusText(paVar17,(char *)CONCAT22(&text,pcVar19));
      puVar11 = ovr_ovc15_usesStshRealloc(pcVar19);
      (*(uint16_t *)((uint8_t *)&(uStack_132) + 2)) = 0x2322;
      (*(uint16_t *)((uint8_t *)&(uStack_132))) = (uint16_t)(agnt_t *)0xcba4;
      paVar9 = (agnt_t *)
               ovr_stsprintf((char *)&msg,(char *)CONCAT13(0x6f,CONCAT12(0xeb,unaff_SS)),
                             (char *)CONCAT22(puVar11,(char *)0x2410));
      ovr_uiNotify((char *)paVar9,(uint16_t)puVar14);
    }
  }
  return (byte *)paVar9;
}
