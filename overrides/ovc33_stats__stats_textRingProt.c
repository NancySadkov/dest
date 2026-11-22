far_t far * __cdecl16far stats_textRingProt(char *dst,uint16_t src,uint16_t term,far_t ringValue)

{
  char *pcVar1;
  uint *puVar2;
  int *piVar3;
  undefined2 *puVar4;
  byte *pbVar5;
  long lVar6;
  code *pcVar7;
  ulong uVar8;
  uint3 uVar9;
  far_t gfx;
  far_t entries;
  far_t handle;
  far_t handle_00;
  far_t handle_01;
  far_t handle_02;
  byte bVar10;
  undefined1 uVar11;
  bool bVar12;
  char cVar22;
  uint uVar13;
  byte *pbVar14;
  byte bVar23;
  uint uVar16;
  char *pcVar17;
  far_t far *pfVar18;
  uint16_t uVar19;
  uint uVar20;
  byte *pbVar21;
  byte bVar25;
  far_t far *in_CX;
  far_t far *pfVar24;
  byte bVar26;
  byte bVar27;
  byte bVar28;
  int iVar29;
  undefined2 in_DX;
  undefined2 uVar30;
  byte *pbVar31;
  undefined2 *puVar32;
  int *piVar33;
  short (*pasVar34) [148];
  unit_t *puVar35;
  uint *puVar36;
  uint *puVar37;
  undefined1 *puVar39;
  uint *puVar40;
  int iVar41;
  far_t far *unaff_SI;
  byte *pbVar42;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 uVar43;
  undefined2 unaff_SS;
  undefined2 uVar44;
  bool bVar45;
  byte in_AF;
  longdouble in_ST0;
  undefined4 uVar46;
  undefined2 in_stack_00000002;
  byte in_stack_00000004;
  undefined1 in_stack_00000005;
  uint8_t auStack_314 [72];
  char acStack_2cc [588];
  char acStack_80 [110];
  undefined2 uStack_12;
  int16_t iStack_10;
  byte in_stack_0000fff2;
  byte in_stack_0000fff4;
  short in_stack_0000fff6;
  char sfx;
  byte in_stack_0000fff8;
  undefined1 in_stack_0000fff9;
  undefined1 in_stack_0000fffa;
  char in_stack_0000fffb;
  undefined1 uVar47;
  undefined1 uVar48;
  undefined1 in_stack_0000fffc;
  undefined1 uVar49;
  char in_stack_0000fffd;
  uint uVar15;
  uint *puVar38;
  
  uVar46 = src;
  uVar11 = SUB41(dst,0);
  uVar47 = (undefined1)((ulong)dst >> 8);
  if ((*(uint8_t *)((uint8_t *)&(dst) + 2)) == '\x01') {
    src = far_ofs_u32((uint32_t)(uVar46));
    if ((char)term == '\0') {
      strcpy((char *)CONCAT13(uVar47,CONCAT12(uVar11,CONCAT11(in_stack_00000005,in_stack_00000004)))
             ,"");
    }
    else if ('\0' < (char)term) {
      iStack_10 = 15536;
      ovr_stsprintf((char *)CONCAT11(in_stack_00000005,in_stack_00000004),
                    (char *)CONCAT13(0x62,CONCAT12(0x20,(char *)dst)));
    }
                    /* WARNING: Read-only address (ram,0x0002c58a) is written */
    return (far_t far *)CONCAT11(in_stack_00000005,in_stack_00000004);
  }
  bVar28 = (char)src - (char)term;
  src = far_ofs_u32((uint32_t)(CONCAT31(SUB43(uVar46,1),bVar28)));
  if ((*(uint8_t *)((uint8_t *)&(dst) + 2)) == '\x03') {
    uVar20 = (int)(char)bVar28 - 6;
    if (4 < uVar20) {
      strcpy((char *)CONCAT13(uVar47,CONCAT12(uVar11,CONCAT11(in_stack_00000005,in_stack_00000004)))
             ,"+2 leather armor");
      return (far_t far *)CONCAT11(in_stack_00000005,in_stack_00000004);
    }
    cVar22 = '`';
    pfVar18 = (far_t far *)(uVar20 * 2);
    switch(uVar20) {
    case 0:
      (&stack0xfffe)[(int)unaff_SI] = (&stack0xfffe)[(int)unaff_SI] + '\x01';
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    case 1:
      pcVar7 = (code *)swi(1);
      pfVar18 = (far_t far *)(*pcVar7)();
      return pfVar18;
    case 2:
      do {
        pfVar18 = (far_t far *)(uint)(byte)(pfVar18 + -0x1db1)->ofs;
        if (pfVar18 == unaff_SI) {
          if ((far_t far *)(uint)(byte)(unaff_SI + -0x1db1)->ofs == unaff_SI) {
            pfVar18 = (far_t far *)((char *)0x26510);
            *(char *)&(in_CX + -0x1db1)->ofs = (char)in_CX;
          }
          else {
            uVar11 = (undefined1)(unaff_SI + -0x1db1)->ofs;
            pfVar18 = (far_t far *)CONCAT11(0x24,uVar11);
            *(undefined1 *)&(in_CX + -0x1db1)->ofs = uVar11;
          }
        }
        do {
          pfVar24 = in_CX;
          in_CX = (far_t far *)((int)&pfVar24->ofs + 1);
          if (0xb < (int)in_CX) {
            return pfVar18;
          }
        } while (in_CX == unaff_SI);
        uVar11 = SUB21(in_CX,0);
        if ((far_t far *)(uint)*(byte *)((int)&pfVar24[-0x1da8].ofs + 1) == unaff_SI) {
          if ((far_t far *)(uint)(byte)(unaff_SI + -0x1da8)->ofs == unaff_SI) {
            *(undefined1 *)((int)&pfVar24[-0x1da8].ofs + 1) = uVar11;
          }
          else {
            *(undefined1 *)((int)&pfVar24[-0x1da8].ofs + 1) = (char)(unaff_SI + -0x1da8)->ofs;
          }
        }
        if ((far_t far *)(uint)*(byte *)((int)&pfVar24[-0x1dab].ofs + 1) == unaff_SI) {
          if ((far_t far *)(uint)(byte)(unaff_SI + -0x1dab)->ofs == unaff_SI) {
            *(undefined1 *)((int)&pfVar24[-0x1dab].ofs + 1) = uVar11;
          }
          else {
            *(undefined1 *)((int)&pfVar24[-0x1dab].ofs + 1) = (char)(unaff_SI + -0x1dab)->ofs;
          }
        }
        if ((far_t far *)(uint)*(byte *)((int)&pfVar24[-0x1dae].ofs + 1) == unaff_SI) {
          if ((far_t far *)(uint)(byte)(unaff_SI + -0x1dae)->ofs == unaff_SI) {
            *(undefined1 *)((int)&pfVar24[-0x1dae].ofs + 1) = uVar11;
          }
          else {
            *(undefined1 *)((int)&pfVar24[-0x1dae].ofs + 1) = (char)(unaff_SI + -0x1dae)->ofs;
          }
        }
        unaff_ES = 0x2410;
        pfVar18 = in_CX;
      } while( true );
    case 4:
      if (in_stack_0000fffb == -0x80) {
        sfx = '1';
      }
      else {
        sfx = '4';
      }
      if (in_stack_0000fffd != '0') {
        clrscr();
        printf("Sound IRQ is %c (1. Don\'t change  2. IRQ 2  3. IRQ 5\n");
        sfx = '\0';
        printf("                                 ");
        do {
          while (uVar19 = ovr_biosKeyAvail(), (char)uVar19 != '\0') {
            ovr_biosReadKey();
          }
          cVar22 = '\"';
          uVar19 = ovr_biosReadKey();
          if ((uVar19 & 0xff) == 0x1b) {
            printf("\n");
                    /* WARNING: Subroutine does not return */
            exit(0);
          }
        } while (((((uVar19 & 0xff) != 0x31) && ((uVar19 & 0xff) != 0x32)) &&
                 ((uVar19 & 0xff) != 0x33)) &&
                (((uVar19 & 0xff) != 0x34 && ((uVar19 & 0xff) != 0x35))));
      }
      clrscr();
      bVar12 = write_game_cfg(sfx,cVar22,cVar22);
      if ((far_t far *)(uint)bVar12 != (far_t far *)0x0) {
        return (far_t far *)(uint)bVar12;
      }
                    /* WARNING: Subroutine does not return */
      exit(0x83);
    }
    (&stack0xfffe)[(int)unaff_DI] = (&stack0xfffe)[(int)unaff_DI] + (byte)in_CX;
    unaff_DI[0x54] = 0;
    *(char *)&unaff_SI->ofs = (char)unaff_SI->ofs + (char)(uVar20 >> 8);
    if (((*(int *)&MouseMoved == 0) && (8 < MouseX)) &&
       ((MouseX < 0x19 && ((0xb4 < MouseY && ((MouseY < 0xb6 | 0xeU) != 0)))))) {
      return (far_t far *)0x0;
    }
    if ((((MouseMoved == 0) && (0xea < MouseX)) && (0x3b < MouseY)) && (MouseX < 0x139)) {
      uVar20 = (MouseY - 0x3c) / 0xe;
      if (((uVar20 < (uint)((ulong)dst >> 0x10)) && ((MouseY - 0x3c) % 0xe < 0xc)) &&
         (piVar33 = (int *)(CONCAT11(in_stack_00000005,in_stack_00000004) + uVar20 * 4),
         *piVar33 != 0 || piVar33[1] != 0)) {
        cVar22 = (char)uVar20;
        (*(uint8_t *)((uint8_t *)&(entries.ofs) + 1)) = in_stack_00000005;
        (*(uint8_t *)((uint8_t *)&(entries.ofs))) = in_stack_00000004;
        (*(uint8_t *)((uint8_t *)&(entries.seg))) = uVar11;
        (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = uVar47;
        ovc28_blitMenuEntry(entries,uVar20);
        GMenuItem = cVar22 + '\x01';
        return (far_t far *)CONCAT11(0x24,cVar22 + '\x01');
      }
    }
    uVar11 = 0x24;
    if (((MouseMoved == 0) && (menuBarShown != '\0')) &&
       ((uVar11 = 0x24, 0xf < MouseX &&
        ((uVar11 = 0x24, 0xb2 < MouseY && (uVar11 = 0x24, MouseY < 0xbf)))))) {
      uVar20 = (MouseX - 0x10) / 0x44;
      uVar11 = (undefined1)((MouseX - 0x10) / 0x44 >> 8);
      if ((uVar20 < 3) && ((MouseX - 0x10) % 0x44 < 0x43)) {
        GMenuItem = (char)uVar20 + -4;
        return (far_t far *)CONCAT11(0x24,GMenuItem);
      }
    }
    if ((((keyboardInputMode == '\0') || (uVar11 = 0x24, MouseMoved != 0)) ||
        (uVar11 = 0x24, MouseX < 0xc)) ||
       (((uVar11 = 0x24, 0xde < MouseX || (uVar11 = 0x24, MouseY < 7)) ||
        (uVar11 = 0x24, 0x96 < MouseY)))) goto L_OVC28_6018_0c76_0EAD;
  }
  else {
    pbVar21 = (byte *)(int)(char)bVar28;
    if ((byte *)__C0_ASM_CopyRight + 4 < pbVar21) {
      strcpy((char *)CONCAT13(uVar47,CONCAT12(uVar11,CONCAT11(in_stack_00000005,in_stack_00000004)))
             ,"no armor");
      return (far_t far *)CONCAT11(in_stack_00000005,in_stack_00000004);
    }
    pasVar34 = (short (*) [148])((int)pbVar21 * 2);
    uVar30 = 0x6000;
    bVar10 = (byte)((uint)in_DX >> 8);
    uVar11 = (undefined1)unaff_SS;
    uVar47 = (undefined1)((uint)unaff_SS >> 8);
    switch((uint16_t)pbVar21)   /* hand fix: case values are ints */ {
    case (uint16_t)0x0:
      ovr_vgaSetPalette8bit(auStack_314);
      uVar11 = 0xa6;
      uVar47 = 0x22;
      ovr_blitRect((brect_t *)&iStack_10);
      TextBlitDstSeg = 0xa000;
      ovr_ovc28_textHalflingCastle();
      for (iVar29 = 0; iVar29 < 5; iVar29 = iVar29 + 1) {
        ovr_draw_usesBlitLoadRleGfx3(iVar29);
        uVar11 = 0xbb;
        uVar47 = 0x22;
        ovr_draw_menuRowBar(iVar29,0xa000);
      }
      mapViewActive = 0xff;
      uVar48 = 0xf6;
      uVar49 = 0x5c;
      ovr_attact_usesLDIV_at_2();
      (*(uint8_t *)((uint8_t *)&(handle_02.seg) + 1)) = uVar49;
      (*(uint8_t *)((uint8_t *)&(handle_02.seg))) = uVar48;
      (*(uint8_t *)((uint8_t *)&(handle_02.ofs) + 1)) = uVar47;
      (*(uint8_t *)((uint8_t *)&(handle_02.ofs))) = uVar11;
      ovr_stshFree(handle_02);
      ovr_stop_audio();
      CurMusicType = 0xff;
      ScreenMode = 0;
      return (far_t far *)((char *)0x26510);
    case (uint16_t)0x1:
                    /* WARNING: Read-only address (ram,0x0002c58a) is written */
      s_s_regenerates_3_hitpoint_5ade[0x1e] = '\0';
      (unaff_SI + 0xec0)->ofs = (uint16_t)unaff_SI;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case (uint16_t)0x2:
      pfVar18 = GPromotableCount;
      if (*(byte *)(*(int *)pbVar21 + 0x86) < 9) {
        pfVar18 = (far_t far *)((uint)promotionCount * 0x32 + 0x32);
      }
      s_s_regenerates_3_hitpoint_5ade[0x1e] = 'a';
      return pfVar18;
    case (uint16_t)0x3:
      do {
        uVar48 = uVar11;
        uVar49 = uVar47;
        pcVar17 = (char *)ovr_ovc45_compute9(acStack_80);
        in_stack_00000004 = (byte)in_DX;
        in_stack_00000005 = (undefined1)((uint)in_DX >> 8);
        ovr_blitLabel(pcVar17);
        pfVar18 = (far_t far *)((char *)0x26510);
        BlitLetterType = 0;
        pbVar21 = unaff_DI;
        while( true ) {
          while( true ) {
            unaff_DI = pbVar21 + 0xe;
            unaff_SI = (far_t far *)((int)&unaff_SI->ofs + 1);
            if (CONCAT11((*(uint8_t *)((uint8_t *)&(dst) + 3)),(*(uint8_t *)((uint8_t *)&(dst) + 2))) <= (int)unaff_SI) {
              if (goldPartyIndex != 0xff) {
                pfVar18 = (far_t far *)CONCAT11((char)((uint)pfVar18 >> 8),goldPartyIndex);
                src = far_ofs_u32((uint32_t)(CONCAT22(pfVar18,0x22c4)));
                (*(uint8_t *)((uint8_t *)&(dst) + 2)) = 0xad;
                (*(uint8_t *)((uint8_t *)&(dst) + 3)) = 7;
                ovc28_drawGold(goldPartyIndex);
              }
              return pfVar18;
            }
            piVar33 = (int *)(CONCAT11(in_stack_00000005,in_stack_00000004) + (int)unaff_SI * 4);
            if (*piVar33 != 0 || piVar33[1] != 0) break;
            pfVar18 = (far_t far *)0x0;
            pbVar21 = unaff_DI;
          }
          term = 0xa000;
          src = CONCAT11(uVar49,uVar48) + (int)unaff_DI * 0x140;
          (*(uint8_t *)((uint8_t *)&(dst) + 2)) = (char)butt01Cut5Seg;
          (*(uint8_t *)((uint8_t *)&(dst) + 3)) = (undefined1)((uint)butt01Cut5Seg >> 8);
          (*(uint16_t *)((uint8_t *)&(dst))) = butt01Cut5Ofs;
          in_stack_00000004 = 0xc4;
          in_stack_00000005 = 0x22;
          (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (*(uint8_t *)((uint8_t *)&(dst) + 2));
          gfx.ofs = (uint16_t)butt01Cut5Ofs;
          (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (*(uint8_t *)((uint8_t *)&(dst) + 3));
          ovr_blitLoadRleGfx(gfx,src);
          TextBlitDstSeg = 0xa000;
          TextBlitX = CONCAT11(uVar49,uVar48) + 6;
          TextBlitY = (uint16_t)(pbVar21 + 0x10);
          puVar32 = (undefined2 *)
                    (CONCAT11(in_stack_00000005,in_stack_00000004) + (int)unaff_SI * 4);
          uVar30 = puVar32[1];
          in_DX = *puVar32;
          uVar48 = (undefined1)uVar30;
          uVar49 = (undefined1)((uint)uVar30 >> 8);
          (*(uint8_t *)((uint8_t *)&(dst) + 2)) = (char)FontMain.seg;
          (*(uint8_t *)((uint8_t *)&(dst) + 3)) = (undefined1)(FontMain.seg >> 8);
          if (*(char *)CONCAT13(uVar49,CONCAT12(uVar48,in_DX)) == '%') break;
          if (*(char *)CONCAT13(uVar49,CONCAT12(uVar48,in_DX)) == '@') {
            src = far_ofs_u32((uint32_t)(0xf013f));
            (*(uint16_t *)((uint8_t *)&(dst))) =(uint16_t)( (char *)FontMain.ofs);
            in_stack_00000004 = 3;
            in_stack_00000005 = 0;
            uVar48 = uVar11;
            uVar49 = uVar47;
            pcVar17 = (char *)ovr_ovc45_compute9(acStack_80);
            in_stack_00000004 = (byte)in_DX;
            in_stack_00000005 = (undefined1)((uint)in_DX >> 8);
            pfVar18 = (far_t far *)ovr_blitLabel(pcVar17);
            pbVar21 = unaff_DI;
          }
          else {
            src = far_ofs_u32((uint32_t)(0xf013f));
            (*(uint16_t *)((uint8_t *)&(dst))) =(uint16_t)( (char *)FontMain.ofs);
            in_stack_00000004 = 3;
            in_stack_00000005 = 0;
            uVar48 = uVar11;
            uVar49 = uVar47;
            pcVar17 = (char *)ovr_ovc45_compute9(acStack_80);
            in_stack_00000004 = (byte)in_DX;
            in_stack_00000005 = (undefined1)((uint)in_DX >> 8);
            pfVar18 = (far_t far *)ovr_blitLabel(pcVar17);
            pbVar21 = unaff_DI;
          }
        }
        BlitLetterType = 2;
        src = far_ofs_u32((uint32_t)(0xf013f));
        (*(uint16_t *)((uint8_t *)&(dst))) =(uint16_t)( (char *)FontMain.ofs);
        in_stack_00000004 = 3;
        in_stack_00000005 = 0;
      } while( true );
    case (uint16_t)0x4:
      out(0,bVar28);
      pcVar1 = (char *)((int)*pasVar34 + 0x3b);
      *pcVar1 = *pcVar1 + bVar10;
      break;
    case (uint16_t)0x5:
      bVar26 = 9 < (bVar28 & 0xf) | in_AF;
      bVar27 = bVar28 + bVar26 * '\x06';
      cVar22 = ((char)bVar28 >> 7) + bVar26;
      uVar13 = CONCAT11(cVar22,bVar27) & 0xff0f;
      bVar23 = (byte)pasVar34;
      uVar16 = CONCAT11(bVar10 + bVar23 + bVar26,(char)in_DX);
      uVar20 = (uint)(CARRY1(bVar10,bVar23) || CARRY1(bVar10 + bVar23,bVar26));
      puVar39 = &stack0xfffe + uVar13 + uVar20;
      puVar2 = (uint *)(puVar39 + (int)unaff_DI + -0x58ef);
      uVar15 = (uint)(CARRY2((uint)&stack0xfffe,uVar13) ||
                     CARRY2((uint)(&stack0xfffe + uVar13),uVar20));
      uVar20 = *puVar2;
      uVar13 = *puVar2;
      *puVar2 = (uint)(unaff_DI + uVar13 + uVar15);
      puVar2 = (uint *)(unaff_DI + -0x7aef);
      uVar13 = (uint)(CARRY2(uVar20,(uint)unaff_DI) || CARRY2((uint)(unaff_DI + uVar13),uVar15));
      uVar20 = *puVar2;
      uVar15 = (int)*pasVar34 + *puVar2;
      *puVar2 = uVar15 + uVar13;
      piVar3 = (int *)((int)*pasVar34 + 0x11);
      *piVar3 = *piVar3 + uVar16 + (uint)(CARRY2(uVar20,(uint)pasVar34) || CARRY2(uVar15,uVar13));
      bVar12 = CARRY2(uVar16,*(uint *)(unaff_DI + (int)*pasVar34));
      iVar29 = uVar16 + *(uint *)(unaff_DI + (int)*pasVar34);
      *(double *)((int)&unaff_SI->ofs + (int)*pasVar34) = (double)in_ST0;
      puVar4 = (undefined2 *)((int)&unaff_SI->ofs + (int)*pasVar34);
      bVar10 = ((byte)in_CX & 0x1f) % 0x11;
      uVar9 = CONCAT12(bVar12,*puVar4);
      uVar8 = (ulong)uVar9 << bVar10 | (ulong)(uVar9 >> 0x11 - bVar10);
      *puVar4 = (int)uVar8;
      pbVar5 = (byte *)((int)&unaff_SI->ofs + (int)*pasVar34);
      bVar28 = *pbVar5;
      *pbVar5 = bVar28 << 4 |
                (byte)(CONCAT11((bVar10 == 0) * bVar12 | (bVar10 != 0) * ((uVar8 & 0x10000) != 0),
                                bVar28) >> 5);
      bVar12 = (bVar28 & 0x10) != 0;
      pbVar5 = puVar39 + 0x5110;
      bVar28 = *pbVar5;
      bVar10 = *pbVar5;
      *pbVar5 = bVar10 + bVar23 + bVar12;
      *(byte *)(*pasVar34 + 8) =
           (char)(*pasVar34)[8] + (bVar27 & 0xf) +
           (CARRY1(bVar28,bVar23) || CARRY1(bVar10 + bVar23,bVar12));
      uVar20 = CONCAT11(cVar22,bVar27) & 0xff0f ^ 0x10;
      pbVar5 = (byte *)((int)&unaff_SI->ofs + (int)*pasVar34);
      bVar26 = (byte)iVar29;
      bVar12 = bVar26 < *pbVar5;
      bVar23 = (byte)((uint)iVar29 >> 8);
      bVar26 = bVar26 - *pbVar5;
      pbVar5 = (byte *)((int)&unaff_SI->ofs + (int)*pasVar34);
      bVar28 = *pbVar5;
      bVar10 = bVar26 + *pbVar5;
      bVar27 = bVar10 + bVar12;
      out(CONCAT11(bVar23,bVar27),uVar20);
      uVar20 = CONCAT11(cVar22,*(undefined1 *)(ulong)((int)*pasVar34 + (uVar20 & 0xff)));
      (*pasVar34)[0] = CONCAT11(bVar23,bVar27);
      if (!CARRY1(bVar26,bVar28) && !CARRY1(bVar10,bVar12)) {
        src = far_ofs_u32((uint32_t)(CONCAT22(0x6000,src)));
        pcVar7 = (code *)swi(3);
        pfVar18 = (far_t far *)(*pcVar7)();
        return pfVar18;
      }
      iVar29 = (bVar27 & 3) - (AgntAnms[0x6e].maxDy & 3U);
      AgntAnms[0x6e].maxDy = AgntAnms[0x6e].maxDy + (uint)(0 < iVar29) * iVar29;
      uVar13 = (uint)unaff_SI ^ 0xdd16;
      LOCK();
      bVar28 = *unaff_DI;
      *unaff_DI = bVar27;
      UNLOCK();
      pbVar31 = (byte *)((int)*pasVar34 + 1);
      *unaff_DI = *unaff_DI & bVar28;
      *(undefined2 *)0xa813 = in_stack_00000002;
      iVar29 = uVar13 + 0x2b64 + (uint)(0xea39 < uVar13) +
               (uint)(0xea61 < uVar13 + 0x15c6 || CARRY2(uVar13 + 0x2b64,(uint)(0xea39 < uVar13))) +
               0x2a2f;
      bVar10 = (byte)iVar29;
      bVar12 = 0x34 < (byte)(bVar10 - 0x20) || CARRY1(bVar10 + 0xab,0x1f < bVar10);
      bVar26 = bVar10 + 0xab + (0x1f < bVar10);
      bVar10 = bVar26 + 0xbe;
      bVar45 = 0x41 < bVar26 || CARRY1(bVar10,bVar12);
      bVar10 = bVar10 + bVar12;
      bVar26 = bVar10 + 0xa0;
      bVar12 = 0x5f < bVar10 || CARRY1(bVar26,bVar45);
      bVar26 = bVar26 + bVar45;
      bVar10 = bVar26 + 0x93;
      bVar45 = 0x6c < bVar26 || CARRY1(bVar10,bVar12);
      bVar10 = bVar10 + bVar12;
      bVar26 = bVar10 + 0x7d;
      bVar12 = 0x82 < bVar10 || CARRY1(bVar26,bVar45);
      bVar26 = bVar26 + bVar45;
      bVar10 = bVar26 + 0x61;
      bVar45 = 0x9e < bVar26 || CARRY1(bVar10,bVar12);
      bVar10 = bVar10 + bVar12;
      bVar26 = bVar10 + 0x57;
      bVar12 = 0xa8 < bVar10 || CARRY1(bVar26,bVar45);
      bVar26 = bVar26 + bVar45;
      bVar10 = bVar26 + 0x43;
      bVar45 = 0xbc < bVar26 || CARRY1(bVar10,bVar12);
      bVar10 = bVar10 + bVar12;
      bVar26 = bVar10 + 0x39;
      bVar12 = 0xc6 < bVar10 || CARRY1(bVar26,bVar45);
      bVar26 = bVar26 + bVar45;
      bVar10 = bVar26 + 0x23;
      bVar45 = 0xdc < bVar26 || CARRY1(bVar10,bVar12);
      bVar10 = bVar10 + bVar12;
      bVar26 = bVar10 + 0xb;
      bVar12 = 0xf4 < bVar10 || CARRY1(bVar26,bVar45);
      bVar26 = bVar26 + bVar45;
      bVar10 = bVar26 + 0x8d;
      uVar16 = CONCAT11((char)((uint)iVar29 >> 8),bVar10 + bVar12);
      uVar13 = (uint)(0x72 < bVar26 || CARRY1(bVar10,bVar12));
      uVar15 = uVar16 - *(uint *)(pbVar31 + uVar20 + 0x5c1b);
      pbVar14 = (byte *)(uVar15 - uVar13);
      uVar13 = (uint)(uVar16 < *(uint *)(pbVar31 + uVar20 + 0x5c1b) || uVar15 < uVar13);
      uVar15 = (int)in_CX - *(uint *)(puVar39 + 0x1b);
      iVar29 = uVar15 - uVar13;
      uVar13 = (uint)(in_CX < *(far_t far **)(puVar39 + 0x1b) || uVar15 < uVar13);
      uVar15 = uVar20 - *(uint *)(pbVar31 + uVar20);
      puVar40 = (uint *)(uVar15 - uVar13);
      uVar20 = (uint)(uVar20 < *(uint *)(pbVar31 + uVar20) || uVar15 < uVar13);
      uVar15 = 0xa814 - AgntAnms[0x39].missileDy;
      iVar41 = -uVar20;
      uVar20 = (uint)(0xa814 < (uint)AgntAnms[0x39].missileDy || uVar15 < uVar20);
      pbVar42 = (byte *)(((int)unaff_DI - (int)pbVar14) - uVar20);
      bVar12 = bVar23 < (pbVar31 + (int)pbVar42)[-0x5be6] ||
               (byte)(bVar23 - (pbVar31 + (int)pbVar42)[-0x5be6]) <
               (unaff_DI < pbVar14 || (uint)((int)unaff_DI - (int)pbVar14) < uVar20);
      bVar10 = (byte)iVar29;
      bVar26 = bVar10 - pbVar42[0x3e1a];
      bVar45 = bVar10 < pbVar42[0x3e1a] || bVar26 < bVar12;
      bVar27 = (byte)((uint)iVar29 >> 8);
      bVar26 = bVar26 - bVar12;
      bVar10 = bVar27 - bVar28;
      bVar25 = bVar10 - bVar45;
      pbVar5 = pbVar42 + 0x4119;
      uVar20 = (uint)(bVar27 < bVar28 || bVar10 < bVar45);
      pbVar21 = *(byte **)pbVar5;
      iVar29 = *(int *)pbVar5;
      *(uint *)pbVar5 = (iVar29 - (int)pbVar14) - uVar20;
      puVar2 = puVar40;
      uVar13 = (uint)(pbVar21 < pbVar14 || (uint)(iVar29 - (int)pbVar14) < uVar20);
      puVar36 = (uint *)*puVar2;
      uVar20 = *puVar2;
      *puVar2 = (uVar20 - (int)puVar40) - uVar13;
      uVar20 = (uint)(puVar36 < puVar40 || uVar20 - (int)puVar40 < uVar13);
      bVar12 = (uint)(*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight) + 21)) < CONCAT11(bVar25,bVar26);
      uVar13 = (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight) + 21)) - CONCAT11(bVar25,bVar26);
      (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight) + 21)) = uVar13 - uVar20;
      uVar20 = (uint)(bVar12 || uVar13 < uVar20);
      piVar33 = (int *)-uVar20;
      bVar23 = (byte)((uint)pbVar14 >> 8);
      bVar12 = bVar28 < bVar23 || (byte)(bVar28 - bVar23) < (uVar20 != 0);
      bVar10 = (bVar28 - bVar23) - (uVar20 != 0);
      bVar28 = (byte)pbVar14 - (byte)pbVar31;
      bVar27 = bVar28 - bVar12;
      bVar12 = bVar10 < bVar27 ||
               (byte)(bVar10 - bVar27) < ((byte)pbVar14 < (byte)pbVar31 || bVar28 < bVar12);
      pbVar5 = (byte *)((char *)0x2b018 + (int)puVar39 + (int)piVar33);
      bVar28 = *pbVar5;
      bVar10 = *pbVar5;
      *pbVar5 = (bVar10 - bVar25) - bVar12;
      pcVar1 = (char *)((int)puVar39 + (int)piVar33 + 0x18);
      *pcVar1 = (*pcVar1 - bVar23) - (bVar28 < bVar25 || (byte)(bVar10 - bVar25) < bVar12);
      bVar12 = CONCAT11(bVar23,bVar27) < 0x2318;
      bVar27 = bVar27 - 0x18;
      pbVar5 = pbVar31;
      bVar45 = *pbVar5 < bVar26 || (byte)(*pbVar5 - bVar26) < bVar12;
      *pbVar5 = (*pbVar5 - bVar26) - bVar12;
      pbVar5 = pbVar42;
      bVar28 = *pbVar5;
      bVar10 = *pbVar5;
      *pbVar5 = (bVar10 - bVar27) - bVar45;
      uVar30 = CONCAT11(bVar25,(bVar26 - bVar27) -
                               (bVar28 < bVar27 || (byte)(bVar10 - bVar27) < bVar45));
      uVar44 = *(undefined2 *)(uVar15 + iVar41 + 2);
      puVar36 = (uint *)(uVar15 + iVar41 + 4);
      pcVar7 = (code *)swi(0x1e);
      uVar46 = (*pcVar7)();
      uVar43 = (undefined2)((ulong)uVar46 >> 0x10);
      uVar20 = (uint)uVar46;
      uVar13 = *puVar36;
      *puVar36 = uVar44;
      puVar36[-1] = uVar44;
      bVar28 = (byte)((ulong)uVar46 >> 0x10);
      if (((uVar13 & 0x800) != 0) == ((uVar13 & 0x80) != 0)) {
code_r0x0006013c:
        lVar6 = (long)*piVar33 * 0x48;
        bVar12 = (int)lVar6 != lVar6;
        bVar26 = (byte)uVar20 - 0x1d;
        bVar45 = (byte)uVar20 < 0x1d || bVar26 < bVar12;
        bVar26 = bVar26 - bVar12;
        bVar27 = bVar26 + 3;
        bVar10 = bVar27 - bVar45;
        pbVar42 = pbVar42 + (-(uint)(bVar26 < 0xfd || bVar27 < bVar45) - (int)puVar36);
        pbVar31 = (byte *)CONCAT11((byte)((ulong)lVar6 >> 8) & (byte)((uint)uVar30 >> 8) & bVar10,
                                   (char)lVar6);
        (puVar39 + (int)pbVar42)[-0x62e0] =
             (puVar39 + (int)pbVar42)[-0x62e0] & (byte)((ulong)uVar46 >> 0x18);
        (pbVar31 + (int)pbVar42)[0x6f20] = (pbVar31 + (int)pbVar42)[0x6f20] & (byte)uVar30;
      }
      else {
        puVar36[-2] = uVar20;
        puVar36[-3] = uVar30;
        puVar36[-4] = uVar43;
        puVar36[-5] = (uint)pbVar31;
        puVar36[-6] = (uint)(puVar36 + -1);
        puVar36[-7] = (uint)puVar39;
        puVar36[-8] = (uint)piVar33;
        puVar36[-9] = (uint)pbVar42;
        puVar37 = puVar36 + -10;
        puVar38 = puVar36 + -10;
        puVar36[-10] = uVar44;
        uVar11 = in(uVar43);
        uVar15 = CONCAT11((char)((ulong)uVar46 >> 8),uVar11);
        uVar20 = (uint)((uVar13 & 1) != 0);
        uVar13 = uVar15 + 0xe253;
        uVar16 = uVar13 - uVar20;
        bVar10 = 0;
        puVar36 = puVar36 + -10;
        if (uVar16 != 0) {
          uVar20 = (uint)(uVar15 < 0x1dad || uVar13 < uVar20);
          bVar12 = uVar16 < 0x1d54 || uVar16 + 0xe2ac < uVar20;
          uVar20 = (uVar16 + 0xe2ac) - uVar20;
          puVar36 = puVar37;
          puVar40 = puVar38;
          if (-1 < (int)uVar20) goto L_OVC27_2288;
          goto code_r0x0006013c;
        }
      }
      (puVar39 + (int)pbVar42)[0x20] = (puVar39 + (int)pbVar42)[0x20] & bVar28;
      bVar12 = false;
      uVar20 = (uint)(bVar10 ^ 0x20);
      puVar40 = puVar36;
L_OVC27_2288:
      cVar22 = ((char)uVar20 + -0x20) - bVar12;
      pbVar31[(int)piVar33] = pbVar31[(int)piVar33] + cVar22;
      pbVar31[(int)piVar33] = pbVar31[(int)piVar33] + cVar22;
      pbVar31[(int)piVar33] = pbVar31[(int)piVar33] + cVar22;
      pbVar31[(int)piVar33] = pbVar31[(int)piVar33] + cVar22;
      pbVar31[(int)piVar33] = pbVar31[(int)piVar33] + cVar22;
      pbVar31[(int)piVar33] = pbVar31[(int)piVar33] + cVar22;
      pbVar31[(int)piVar33] = pbVar31[(int)piVar33] + cVar22;
      pbVar31[(int)piVar33] = pbVar31[(int)piVar33] + cVar22;
      pbVar31[(int)piVar33] = pbVar31[(int)piVar33] + cVar22;
      pbVar31[(int)piVar33] = pbVar31[(int)piVar33] + cVar22;
      pbVar31[(int)piVar33] = pbVar31[(int)piVar33] + cVar22;
      pbVar31[(int)piVar33] = pbVar31[(int)piVar33] + cVar22;
      pbVar31[(int)piVar33] = pbVar31[(int)piVar33] + cVar22;
      pbVar31[(int)piVar33] = pbVar31[(int)piVar33] + cVar22;
      pbVar31[(int)piVar33] = pbVar31[(int)piVar33] + cVar22;
      pbVar31[(int)piVar33] = pbVar31[(int)piVar33] + cVar22;
      pbVar31[(int)piVar33] = pbVar31[(int)piVar33] + cVar22;
      pbVar31[(int)piVar33] = pbVar31[(int)piVar33] + cVar22;
      pbVar42[-0x75] = pbVar42[-0x75] + bVar28;
      in(uVar43);
      *(undefined2 *)((int)puVar40 + -6) =(uint16_t)( piVar33);
      iVar29 = *(int *)(puVar39 + 6);
      do {
        iVar41 = iVar29 + -1;
        if (iVar29 == 0) {
          return (far_t far *)0x0;
        }
        uVar30 = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
        *(undefined2 *)(puVar39 + -2) = *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
        *(undefined2 *)(puVar39 + -4) = uVar30;
        do {
          iVar29 = iVar41;
          if (*(int far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2) != *(int *)(puVar39 + -2)) break;
        } while (*(int far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) == *(int *)(puVar39 + -4));
      } while( true );
    case (byte *)0x6:
      *(byte *)(*pasVar34 + 0x15) = bVar28;
      if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)in_stack_00000004 * 0x95) & 0x800) !=
          0) {
        *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x2d) = 0x12;
      }
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x3f) =
           *(undefined1 *)((int)(char **)GMenuStrings + (uint)in_stack_00000004 * 0x95 + 0x1f);
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x33) =
           *(undefined1 *)((int)(far_t far *)(worldMenuLabels + 9) + (uint)in_stack_00000004 * 0x95);
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x31) =
           *(undefined1 *)((int)&worldMenuLabels[6].seg + (uint)in_stack_00000004 * 0x95);
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x32) =
           *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x31);
      pbVar5 = (byte *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x28);
      *pbVar5 = *pbVar5 | 0x16;
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x40) = 1;
      iVar29 = CONCAT11(in_stack_0000fffb,in_stack_0000fffa);
      uVar30 = (undefined2)(CONCAT13(in_stack_0000fffd,CONCAT12(in_stack_0000fffc,iVar29)) >> 0x10);
      *(undefined2 *)(iVar29 + 0x58) = 0;
      *(undefined2 *)(iVar29 + 0x56) = 100;
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x89) = 0xff;
      uVar11 = 0x5d;
      pfVar18 = ovr_ovc22_textRingProt(in_stack_0000fff8);
      return (far_t far *)CONCAT11((char)((uint)pfVar18 >> 8),uVar11);
    case (byte *)0x7:
      do {
        unaff_DI = (byte *)((uint)unaff_DI | *(uint *)(pbVar21 + (int)(*pasVar34 + -2)) & 0x3000);
        unaff_SI = (far_t far *)((int)&unaff_SI->ofs + 1);
        while( true ) {
          if ((int)unaff_SI < 4) break;
          pfVar18 = (far_t far *)CONCAT11(in_stack_0000fffb,in_stack_0000fffa);
          if (unaff_DI == (byte *)((int)&AgntAnms[0x38].halfWidth + 1)) {
            GPromotableCount = (uint16_t)((int)&GPromotableCount + 1)   /* hand fix: scalar, no ->ofs */;
            pfVar18 = (far_t far *)CONCAT11(in_stack_0000fffb,in_stack_0000fffa);
          }
          do {
            pfVar18 = (far_t far *)((int)&pfVar18->ofs + 1);
            if (GUnitCount <= pfVar18) {
              return GUnitCount;
            }
            uVar43 = (undefined2)((ulong)GUnits >> 0x10);
            puVar35 = (unit_t *)GUnits;
          } while ((((*(uint *)((uint)(puVar35 + (int)pfVar18)->bldType * 0x27 + 0x121) & 0x60) != 0
                    ) || (puVar35[(int)pfVar18].unitType == 0xff)) ||
                  (uVar46 = *(undefined4 *)((uint)puVar35[(int)pfVar18].unitType << 2),
                  *(char *)((int)uVar46 + 0x3f) != '\0'));
          in_stack_0000fffa = (undefined1)uVar30;
          in_stack_0000fffb = (char)((uint)uVar30 >> 8);
          uVar30 = 0x2379;
          uVar20 = ovr_alignUp4(puVar35[(int)pfVar18].x);
          in_stack_0000fff8 = (byte)uVar20;
          in_stack_0000fff9 = (undefined1)(uVar20 >> 8);
          in_stack_0000fff6 = ((unit_t *)GUnits)[CONCAT11(in_stack_0000fffb,in_stack_0000fffa)].y;
          unaff_DI = (byte *)0x0;
          unaff_SI = (far_t far *)0x0;
        }
        unaff_ES = (undefined2)((ulong)GMapFlags >> 0x10);
        pasVar34 = *(short (*) [60] [148])GMapFlags + in_stack_0000fff6;
        pbVar21 = (byte *)((int)((int)&unaff_SI->ofs + CONCAT11(in_stack_0000fff9,in_stack_0000fff8)
                                ) * 2);
      } while( true );
    case (byte *)0x8:
      uVar30 = 0x217a;
      if (((char_sheet_t *)(pbVar21))->income <
          (uint)-((char_sheet_t *)(((uint)in_stack_00000004 << 2)))->population) {
        bVar28 = 5;
      }
      else {
        bVar28 = 4;
      }
      if (((in_stack_0000fff4 == 0) || (in_stack_0000fff4 < in_stack_0000fff2)) ||
         (in_stack_0000fff4 < bVar28)) {
        if ((in_stack_0000fff2 == 0) || (in_stack_0000fff2 < bVar28)) {
          if (bVar28 == 0) {
            ovc39_lordOrLady();
            iStack_10 = 24576;
            uStack_12 = 0x9bb1;
            pfVar18 = (far_t far *)ovr_stsprintf(acStack_2cc);
            ovr_drawString((char *)pfVar18);
          }
          else {
            ovc39_loadArchiveEntry(bVar28 + 0x17);
            ovc39_lordOrLady();
            iStack_10 = 24576;
            uStack_12 = 0x9b7b;
            pfVar18 = (far_t far *)ovr_stsprintf(acStack_2cc);
            uVar48 = (undefined1)uVar30;
            uVar49 = (undefined1)((uint)uVar30 >> 8);
            uVar11 = SUB21(pfVar18,0);
            uVar47 = (undefined1)((uint)pfVar18 >> 8);
            ovr_drawString((char *)pfVar18);
            (*(uint8_t *)((uint8_t *)&(handle_01.ofs) + 1)) = uVar47;
            (*(uint8_t *)((uint8_t *)&(handle_01.ofs))) = uVar11;
            (*(uint8_t *)((uint8_t *)&(handle_01.seg))) = uVar48;
            (*(uint8_t *)((uint8_t *)&(handle_01.seg) + 1)) = uVar49;
            ovr_stshFree(handle_01);
          }
        }
        else {
          ovc39_loadArchiveEntry(in_stack_0000fff2 + 0xd);
          ovc39_lordOrLady();
          iStack_10 = 24576;
          uStack_12 = 0x9b2e;
          pfVar18 = (far_t far *)ovr_stsprintf(acStack_2cc);
          uVar48 = (undefined1)uVar30;
          uVar49 = (undefined1)((uint)uVar30 >> 8);
          uVar11 = SUB21(pfVar18,0);
          uVar47 = (undefined1)((uint)pfVar18 >> 8);
          ovr_drawString((char *)pfVar18);
          (*(uint8_t *)((uint8_t *)&(handle_00.ofs) + 1)) = uVar47;
          (*(uint8_t *)((uint8_t *)&(handle_00.ofs))) = uVar11;
          (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = uVar48;
          (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = uVar49;
          ovr_stshFree(handle_00);
        }
      }
      else {
        ovc39_loadArchiveEntry(in_stack_0000fff4 + 0x12);
        ovc39_lordOrLady();
        iStack_10 = 24576;
        uStack_12 = 0x9ad8;
        pfVar18 = (far_t far *)ovr_stsprintf(acStack_2cc);
        uVar48 = (undefined1)uVar30;
        uVar49 = (undefined1)((uint)uVar30 >> 8);
        uVar11 = SUB21(pfVar18,0);
        uVar47 = (undefined1)((uint)pfVar18 >> 8);
        ovr_drawString((char *)pfVar18);
        (*(uint8_t *)((uint8_t *)&(handle.ofs) + 1)) = uVar47;
        (*(uint8_t *)((uint8_t *)&(handle.ofs))) = uVar11;
        (*(uint8_t *)((uint8_t *)&(handle.seg))) = uVar48;
        (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = uVar49;
        ovr_stshFree(handle);
      }
      return pfVar18;
    }
  }
  uVar11 = 0x24;
  if (MouseMoved == 0) {
    ovc28_textHalflingCastle();
    uVar20 = MouseX - 0xc >> 1;
    ovr_ovc13_usesBlitLoadRleGfx2(CONCAT11((byte)(MouseX - 0xc >> 9),(char)uVar20));
    return (far_t far *)CONCAT11((char)(uVar20 >> 8),0xfe);
  }
L_OVC28_6018_0c76_0EAD:
  if (((keyboardInputMode == '\0') || (uVar11 = 0x24, MouseMoved != 0)) ||
     (((uVar11 = 0x24, MouseX < 0xef ||
       ((uVar11 = 0x24, 0x134 < MouseX || (uVar11 = 0x24, MouseY < 7)))) ||
      (uVar11 = 0x24, 0x36 < MouseY)))) {
    pfVar18 = (far_t far *)CONCAT11(uVar11,0xff);
  }
  else {
    ovc28_textHalflingCastle();
    uVar20 = MouseX - 0xef >> 1;
    ovr_ovc13_usesBlitLoadRleGfx3(CONCAT11((byte)(MouseX - 0xef >> 9),(char)uVar20));
    pfVar18 = (far_t far *)CONCAT11((char)(uVar20 >> 8),0xfe);
  }
                    /* WARNING: Read-only address (ram,0x0002c58a) is written */
  return pfVar18;
}
