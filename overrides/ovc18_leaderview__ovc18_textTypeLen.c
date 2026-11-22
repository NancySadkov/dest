ovc18_textTypeLen(uint8_t partyIndex,uint16_t destX,uint16_t destY,uint8_t textVariant,...)

{
  undefined1 stk_681c;   /* stack slot 681c */
  int *piVar1;
  uint16_t y;
  far_t buf;
  far_t handle;
  far_t ptr_ofs;
  byte bVar2;
  int *piVar3;
  uint uVar4;
  uint8_t *puVar5;
  uint32_t *puVar6;
  char *pcVar7;
  uint in_CX;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint16_t unaff_SI;
  long *unaff_DI;
  uint16_t uVar12;
  uint16_t uVar13;
  uint16_t uVar14;
  uint16_t unaff_SS;
  bool bVar15;
  far_t fVar16;
  undefined1 uStack000b;
  int *in_stack_0000000c;
  int *in_stack_00000014;
  int *in_stack_00000018;
  int *in_stack_0000001c;
  int *in_stack_00000020;
  char acStackY_f6 [120];
  char acStackY_7e [92];
  uint16_t uStackY_22;
  uint16_t uStackY_20;
  undefined1 in_stack_0000ffef;
  undefined1 uVar17;
  undefined1 uVar18;
  undefined1 uVar19;
  undefined1 uVar20;
  undefined1 uVar21;
  undefined1 uVar22;
  undefined1 uVar23;
  undefined1 uVar24;
  undefined1 uVar25;
  undefined1 uVar26;
  undefined1 uStack_5;
  undefined1 uStack_4;
  undefined1 uStack_3;
  
  destY =(uint16_t)( (int *)CONCAT13(uStack000b,CONCAT12(textVariant,destY)));
  uVar14 = 0x48ac;
  uVar19 = (undefined1)unaff_SI;
  uVar20 = (undefined1)((uint)unaff_SI >> 8);
  uVar17 = SUB21(unaff_DI,0);
  uVar18 = (undefined1)((uint)unaff_DI >> 8);
  piVar3 = (int *)((partyIndex & 0xff) * 4);
  iVar10 = piVar3[1];
  iVar9 = *piVar3;
  uVar23 = (undefined1)iVar10;
  uVar24 = (undefined1)((uint)iVar10 >> 8);
  uVar21 = (undefined1)iVar9;
  uVar22 = (undefined1)((uint)iVar9 >> 8);
  uVar12 = *(uint16_t *)(iVar9 + 0x39);
  y = *(uint16_t *)(iVar9 + 0x3b);
  uVar25 = (undefined1)y;
  uVar26 = (undefined1)(y >> 8);
  uVar13 = (uint16_t)(CONCAT13(uVar24,CONCAT12(uVar23,iVar9)) >> 0x10);
  uVar4 = (uint)*(byte *)(iVar9 + 0x2f);
  if (uVar4 == 4) {
    uStackY_20 = 0x48ac;
    uVar14 = 0x2322;
    uStackY_22 = 0x8fca;
    ovr_ovc15_usesLDIV_at_(uVar12,y,destX,destY,10);
  }
  else if (uVar4 < 5) {
    if (uVar4 < 4) {
      bVar15 = uVar4 == 0;
      uVar12 = destY;
      switch(uVar4) {
      case 1:
        uVar11 = *(uint *)(uVar4 * 2 + 0xc);
        uVar8 = uVar11 + 0x14;
        iVar10 = uVar4 + (0xffeb < uVar11);
        if (StshCount < 0xd93) {
          StshCount = StshCount + 1;
          LXMUL_at_(unaff_DI,CONCAT13(uVar22,CONCAT12(uVar21,unaff_SI)),
                    CONCAT13((char)((uint)iVar10 >> 8),CONCAT12((char)iVar10,uVar8)));
          (*(uint8_t *)((uint8_t *)&(fVar16.seg))) = uVar17;
          fVar16.ofs = 0x1000;
          (*(uint8_t *)((uint8_t *)&(fVar16.seg) + 1)) = uVar18;
          (*(uint8_t *)((uint8_t *)&(ptr_ofs.ofs) + 1)) = uVar20;
          (*(uint8_t *)((uint8_t *)&(ptr_ofs.ofs))) = uVar19;
          (*(uint8_t *)((uint8_t *)&(ptr_ofs.seg))) = uVar21;
          (*(uint8_t *)((uint8_t *)&(ptr_ofs.seg) + 1)) = uVar22;
          fVar16 = PADD_at_(fVar16,ptr_ofs);
          uVar12 = fVar16.seg;
          puVar6 = ovr_mkp((uint32_t *)fVar16.ofs);
          uStack_4 = (undefined1)uVar12;
          uStack_3 = (undefined1)(uVar12 >> 8);
          uVar17 = SUB21(puVar6,0);
          uStack_5 = (undefined1)((uint)puVar6 >> 8);
          uVar13 = (uint16_t)(CONCAT13(uStack_3,CONCAT12(uStack_4,puVar6)) >> 0x10);
          *(int *)((int)puVar6 + 7) = iVar10;
          *(uint *)((int)puVar6 + 5) = uVar8;
          *(undefined1 *)CONCAT13(uStack_3,CONCAT12(uStack_4,puVar6)) = 0;
          uVar12 = StshCtOfs.lo;
          uVar13 = (uint16_t)(CONCAT13(uStack_3,CONCAT12(uStack_4,puVar6)) >> 0x10);
          *(uint16_t *)((int)puVar6 + 3) = StshCtOfs.hi;
          *(uint16_t *)((int)puVar6 + 1) = uVar12;
          uVar13 = (uint16_t)(CONCAT13(uStack_3,CONCAT12(uStack_4,puVar6)) >> 0x10);
          *(uint16_t *)((int)puVar6 + 0x13) = 0;
          *(uint16_t *)((int)puVar6 + 0x11) = 0;
          bVar15 = CARRY2(StshCtOfs.lo,uVar8);
          StshCtOfs.lo = StshCtOfs.lo + uVar8;
          StshCtOfs.hi = StshCtOfs.hi + iVar10 + (uint)bVar15;
          uVar13 = (uint16_t)(CONCAT13(uStack_3,CONCAT12(uStack_4,puVar6)) >> 0x10);
          *(uint16_t *)((int)puVar6 + 0xb) = 0;
          *(uint16_t *)((int)puVar6 + 9) = 0;
          uVar13 = (uint16_t)(CONCAT13(uStack_3,CONCAT12(uStack_4,puVar6)) >> 0x10);
          *(uint16_t *)((int)puVar6 + 0xf) = 0;
          *(uint16_t *)((int)puVar6 + 0xd) = 0;
          if (DebugVerbose != false) {
            uStackY_20 = 0xbbd4;
            printf("type %d len %ld \r");
            ovr_biosReadKey();
          }
          uStackY_20 = 0xbbf0;
          buf.seg = destX;
          buf.ofs = partyIndex;
          ovr_stshWriteFile(StshFile,buf);
          (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)destX;
          handle.ofs = partyIndex;
          (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)(destX >> 8);
          ovr_stshFree(handle);
          return (char *)CONCAT11(uStack_5,uVar17);
        }
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0x24);
      case 2:
        uVar11 = destX + 1;
        piVar1 = (int *)(uVar4 * 2 + uVar11);
        *piVar1 = *piVar1 + 1;
        do {
          pcVar7 = ovr_ovc15_textArena(uVar11);
          if (((uint)pcVar7 & 0xff) == 0) goto L_attact_3f0b_26bd_2767;
          destY = destY - 1;
          while (destY == 0) {
L_attact_3f0b_26bd_2767:
            do {
              uVar11 = uVar11 + 1;
              if (EntityCount <= uVar11) {
                return (char *)0x26510;
              }
              uVar13 = ovr_ovc23_isCursorAt(*(uint16_t *)((int)Entities + uVar11 * 0x37));
            } while ((char)uVar13 == '\0');
            destY = manage_usesLitoa103();
          }
        } while( true );
      case 3:
                    /* WARNING: Read-only address (ram,0x000277ff) is written */
        ((char *)0x36fe)[1] = -0x58;
        *(uint *)(&stk_681c + destX) = *(uint *)(&stk_681c + destX) & in_CX;
        ovr_blitLabel((char *)CONCAT11(uVar17,in_stack_0000ffef));
        uVar17 = 0xdc;
        uVar18 = 0;
        pcVar7 = ovr_litoa10(acStackY_f6);
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar9 >> 8),CONCAT12((char)iVar9,pcVar7)),
                   CONCAT11(uVar18,uVar17));
        TextBlitY = TextBlitY + 10;
        TextBlitX = 0x37;
        ovr_blitLabel((char *)"Housing");
        uVar17 = 0x7d;
        uVar18 = 0;
        pcVar7 = ovr_stsprintf(acStackY_7e);
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar9 >> 8),CONCAT12((char)iVar9,pcVar7)),
                   CONCAT11(uVar18,uVar17));
        TextBlitX = 0x82;
        ovr_blitLabel((char *)"Food storage");
        uVar17 = 0xdc;
        uVar18 = 0;
        pcVar7 = ovr_litoa10(acStackY_f6);
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar9 >> 8),CONCAT12((char)iVar9,pcVar7)),
                   CONCAT11(uVar18,uVar17));
        TextBlitY = TextBlitY + 0xf;
        if (*(int *)(partyIndex + 0xa0) != 0) {
          TextBlitX = 0x37;
          if (*(int *)(partyIndex + 0xa2) < 0) {
            ovr_blitLabel((char *)"Food sold");
            uVar17 = 0x7d;
            uVar18 = 0;
            iVar10 = -*(int *)(partyIndex + 0xa2) >> 0xf;
            pcVar7 = ovr_litoa10(acStackY_f6);
            manage_blitLabelRight
                      ((char *)CONCAT13((char)((uint)iVar10 >> 8),CONCAT12((char)iVar10,pcVar7)),
                       CONCAT11(uVar18,uVar17));
          }
          else {
            ovr_blitLabel((char *)"Food bought");
            uVar17 = 0x7d;
            uVar18 = 0;
            iVar10 = *(int *)(partyIndex + 0xa2) >> 0xf;
            pcVar7 = ovr_litoa10(acStackY_f6);
            manage_blitLabelRight
                      ((char *)CONCAT13((char)((uint)iVar10 >> 8),CONCAT12((char)iVar10,pcVar7)),
                       CONCAT11(uVar18,uVar17));
          }
          TextBlitX = 0x82;
          ovr_blitLabel((char *)"Max. trade");
          uVar17 = 0xdc;
          uVar18 = 0;
          pcVar7 = ovr_litoa10(acStackY_f6);
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)iVar10 >> 8),CONCAT12((char)iVar10,pcVar7)),
                     CONCAT11(uVar18,uVar17));
        }
        TextBlitY = TextBlitY + 0xf;
        TextBlitX = 0x37;
        ovr_blitLabel((char *)"Income");
        uVar17 = 0xdc;
        uVar18 = 0;
        iVar10 = *(int *)(partyIndex + 0x54) >> 0xf;
        pcVar7 = ovr_litoa10(acStackY_7e);
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar10 >> 8),CONCAT12((char)iVar10,pcVar7)),
                   CONCAT11(uVar18,uVar17));
        TextBlitY = TextBlitY + 10;
        TextBlitX = 0x37;
        ovr_blitLabel((char *)"Gold");
        uVar17 = 0xdc;
        uVar18 = 0;
        pcVar7 = ovr_litoa10(acStackY_7e);
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar10 >> 8),CONCAT12((char)iVar10,pcVar7)),
                   CONCAT11(uVar18,uVar17));
        TextBlitY = TextBlitY + 10;
        TextBlitX = 0x37;
        ovr_blitLabel((char *)"Vault storage");
        uVar17 = 0xdc;
        uVar18 = 0;
        pcVar7 = ovr_litoa10(acStackY_7e);
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar10 >> 8),CONCAT12((char)iVar10,pcVar7)),
                   CONCAT11(uVar18,uVar17));
        TextBlitY = TextBlitY + 10;
        TextBlitX = 0x37;
        ovr_blitLabel((char *)"Fund Access");
        uVar17 = 0xdc;
        uVar18 = 0;
        ovr_ovc45_usesLDIV_at_(*(uint8_t *)(partyIndex + 0x51));
        pcVar7 = ovr_litoa10(acStackY_f6);
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar10 >> 8),CONCAT12((char)iVar10,pcVar7)),
                   CONCAT11(uVar18,uVar17));
        TextBlitY = TextBlitY + 10;
        TextBlitX = 0x37;
        ovr_blitLabel((char *)"Common fund");
        uVar17 = 0xdc;
        uVar18 = 0;
        pcVar7 = ovr_litoa10(acStackY_f6);
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar10 >> 8),CONCAT12((char)iVar10,pcVar7)),
                   CONCAT11(uVar18,uVar17));
        bVar2 = manage_findFirstLeader();
        pcVar7 = (char *)0x26510;
        TextBlitY = TextBlitY + 0xf;
        if ((*(char *)(partyIndex + 0x86) != '\0') && (bVar2 != 0xff)) {
          pcVar7 = (char *)((uint)bVar2 << 2);
          uVar13 = 0x217a;
          if (((char_sheet_t *)(pcVar7))->titleIndex < 9) {
            manage_usesBlitLabel2("popularity",0x7d);
            manage_usesBlitLabel2("city blocks",0xdc);
            TextBlitY = TextBlitY + 10;
            TextBlitX = 0x11;
            ovr_blitLabel((char *)"Current");
            uVar17 = 0x7d;
            uVar18 = 0;
            manage_usesGLeaderCount();
            pcVar7 = ovr_stsprintf(acStackY_7e);
            manage_blitLabelRight
                      ((char *)CONCAT13((char)((uint)uVar13 >> 8),CONCAT12((char)uVar13,pcVar7)),
                       CONCAT11(uVar18,uVar17));
            uVar17 = 0xdc;
            uVar18 = 0;
            pcVar7 = ovr_stsprintf(acStackY_7e);
            manage_blitLabelRight
                      ((char *)CONCAT13((char)((uint)uVar13 >> 8),CONCAT12((char)uVar13,pcVar7)),
                       CONCAT11(uVar18,uVar17));
            TextBlitY = TextBlitY + 10;
            TextBlitX = 0x11;
            ovr_blitLabel((char *)"to promote");
            uVar17 = 0x7d;
            uVar18 = 0;
            ovr_season_usesDifficulty();
            pcVar7 = ovr_stsprintf(acStackY_7e);
            manage_blitLabelRight
                      ((char *)CONCAT13((char)((uint)uVar13 >> 8),CONCAT12((char)uVar13,pcVar7)),
                       CONCAT11(uVar18,uVar17));
            uVar17 = 0xdc;
            uVar18 = 0;
            ovr_season_usesGPromotable_e11a();
            pcVar7 = ovr_stsprintf(acStackY_7e);
            manage_blitLabelRight
                      ((char *)CONCAT13((char)((uint)uVar13 >> 8),CONCAT12((char)uVar13,pcVar7)),
                       CONCAT11(uVar18,uVar17));
          }
        }
        return pcVar7;
      }
      do {
        if (bVar15) {
          *in_stack_00000020 = *in_stack_00000020 + 1;
        }
        while( true ) {
          while( true ) {
            do {
              uVar12 = uVar12 + 1;
              if (GRecordCount <= uVar12) {
                iVar10 = *in_stack_0000001c;
                iVar9 = *in_stack_00000020;
                *(uint16_t *)destY = *(uint16_t *)destY - *(uint16_t *)in_stack_0000001c;   /* hand fix: 16-bit pointer slots */
                *(uint16_t *)in_stack_0000000c = *(uint16_t *)in_stack_0000000c - *(uint16_t *)in_stack_00000020;
                return (char *)(CONCAT11(uStack_3,uStack_4) - (iVar10 + iVar9));
              }
            } while ((*(uint8_t *)(uVar12 * 0x12 + 9) != partyIndex) ||
                    (bVar2 = *(byte *)(uVar12 * 0x12 + 8),
                    *(char *)((uint)bVar2 * 0x27 + 0x133) != (char)destX));
            *in_stack_00000014 = *in_stack_00000014 + 1;
            if (*(char *)((uint)bVar2 * 0x27 + 0x131) != '\x01') break;
            *in_stack_00000018 = *in_stack_00000018 + 1;
          }
          if (*(char *)((uint)bVar2 * 0x27 + 0x131) != '\x02') break;
          *in_stack_0000001c = *in_stack_0000001c + 1;
        }
        bVar15 = *(char *)((uint)bVar2 * 0x27 + 0x131) == '\x03';
      } while( true );
    }
  }
  else if (uVar4 == 5) {
    uStackY_20 = 0x48ac;
    uVar14 = 0x2322;
    uStackY_22 = 0x8fe5;
    ovr_ovc15_usesLDIV_at_(uVar12,y,destX,destY,8);
  }
  else if (uVar4 == 6) {
    uStackY_20 = 0x48ac;
    uVar14 = 0x2322;
    uStackY_22 = 0x9000;
    ovr_ovc15_usesLDIV_at_(uVar12,y,destX,destY,0xb);
  }
  else if ((uVar4 == 0xff) &&
          ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)*(byte *)(iVar9 + 0x3e) * 0x95) &
           0x800) == 0)) {
    if (textVariant == 0x0) {
      uStackY_20 = 0x48ac;
      uVar14 = 0x2322;
      uStackY_22 = 0x906a;
      ovr_ovc15_usesLDIV_at_(uVar12,y,destX,destY,*(byte *)(iVar9 + 0x3e));
    }
    else {
      uStackY_20 = 0x48ac;
      uVar14 = 0x2322;
      uStackY_22 = 0x904a;
      ovr_ovc15_usesLDIV_at_(uVar12,y,destX,destY,*(byte *)(iVar9 + 0x3e));
    }
  }
  puVar5 = (uint8_t *)((uint)*(byte *)(CONCAT11(uVar22,uVar21) + 0x3e) * 0x95);
  if ((*(uint *)(puVar5 + 0x2714) & 0x8000) != 0) {
    uStackY_22 = 0x90a3;
    uStackY_20 = uVar14;
    puVar5 = ovc18_spawnClassAgent
                       (CONCAT11(uVar26,uVar25),destX,destY,1,partyIndex,textVariant,
                        CONCAT11(uVar18,uVar17));
  }
  return (char *)puVar5;
}
