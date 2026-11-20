/*
 * ovc23.c - recovered from STRONG.EXE
 * memory block: OVC23
 * range: 55fe:0000 - 55fe:345d
 * functions: 26
 */
#include "recovered.h"


/* 55fe:0000 */

/* WARNING: Instruction at (ram,0x0005c484) overlaps instruction at (ram,0x0005c483)
    */
/* [R2] string "               4. Adlib       5. None):" */

byte * __cdecl16far ovc23_textAdlibNone(uint partyIndex,uint16_t outFlag,agnt_t *agnt)

{
  uint *puVar1;
  int *piVar2;
  uint8_t *puVar3;
  bool bVar4;
  undefined4 uVar5;
  ulong uVar6;
  ulong uVar7;
  byte bVar8;
  char cVar9;
  byte bVar10;
  byte *pbVar11;
  uint16_t uVar12;
  uint uVar13;
  uint uVar14;
  char *pcVar15;
  int iVar16;
  char in_CL;
  uint in_DX;
  uint uVar17;
  uint uVar18;
  entity_t *peVar19;
  unit_t *puVar20;
  int iVar21;
  int iVar22;
  undefined2 unaff_DI;
  uint16_t uVar23;
  undefined2 uVar24;
  uint *unaff_SS;
  char acStackY_13e [36];
  undefined2 auStackY_11a [66];
  undefined2 auStackY_96 [23];
  char acStackY_68 [2];
  undefined1 auStackY_66 [56];
  byte bStackY_2e;
  byte bStackY_2d;
  uint16_t uStackY_2c;
  undefined2 uStackY_2a;
  uint16_t in_stack_0000ffd8;
  far_t entries;
  undefined4 uVar25;
  undefined1 uVar26;
  undefined1 uVar27;
  undefined1 uVar28;
  byte bVar29;
  undefined1 uVar30;
  undefined1 uVar31;
  undefined1 uVar32;
  undefined1 uVar33;
  uint uStack_10;
  undefined2 uStack_e;
  uint uStack_c;
  uint uStack_a;
  undefined2 uStack_8;
  undefined4 uStack_6;
  
  uVar33 = (undefined1)unaff_DI;
  bVar8 = (byte)((uint)unaff_DI >> 8);
  uStack_10 = 0;
  uStack_a = ovr_alignUp4(GfxRndSeed);
  for (iVar21 = 0; iVar21 < 4; iVar21 = iVar21 + 1) {
    in_DX = 0x2410;
    uStack_10 = uStack_10 |
                ((short (*) [60] [148])GMapFlags)[-1][GfxRndSeed2 + 0x3b][uStack_a + iVar21 + 0x92]
                & 0x3000U;
  }
  cursorRecordFound = '\0';
  _fmemset((void *)0x91d7,0x2410,0xff);
  uVar26 = 0;
  uVar27 = 0x10;
  uVar25 = 0x605e0000;
  _fmemset((void *)0x90ea,0x2410,0);
  for (uStack_c = 0; uStack_c < GRecordCount; uStack_c = uStack_c + 1) {
    in_DX = 0x2410;
    if ((*(int *)(uStack_c * 0x12 + 4) == GfxRndSeed2) &&
       (in_DX = 0x21f2, (*(byte *)(uStack_c * 0x12 + 0xd) & 1) != 0)) {
      bVar29 = *(byte *)(uStack_c * 0x12 + 7);
      uStack_6 = (byte *)CONCAT31((*(uint32_t *)((uint8_t *)&(uStack_6) + 1)),bVar29);
      iVar21 = *(int *)(uStack_c * 0x12 + 2) - (GfxRndSeed + -2);
      in_DX = (iVar21 + (uint)bVar29) - 1;
      if ((0 < (int)(iVar21 + (uint)bVar29)) && (iVar21 < 4)) {
        if (20000 < *(uint *)(uStack_c * 0x12)) {
          *(undefined2 *)(uStack_c * 0x12) = 3;
        }
        in_DX = 0x21f2;
        for (iVar22 = 0; iVar22 < (int)(uint)bVar29; iVar22 = iVar22 + 1) {
          if (((SCARRY2(iVar22,iVar21) == iVar22 + iVar21 < 0) && (iVar22 + iVar21 < 4)) &&
             (*(uint *)((iVar22 + iVar21) * 2 + -0x6e29) = uStack_c, in_DX = uStack_c, 0 < iVar22))
          {
            *(undefined1 *)(iVar21 + iVar22 + -0x6f16) = 1;
          }
        }
        cursorRecordFound = '\x01';
      }
    }
  }
  CurSfxType3 = 0xff;
  if (((byte *)(uint)GOngoingBattle != (byte *)0x0) || (uStack_10 == 0x3000)) {
    return (byte *)(uint)GOngoingBattle;
  }
  if (cursorRecordFound != '\0') {
    CurSfxType3 = 0x70;
    return (byte *)((char *)"puppetmaker" + 3);
  }
  uStack_6 = (byte *)((ulong)uStack_6 & 0xffffff);
  uVar23 = 0;
  (*(uint16_t *)((uint8_t *)&(uStack_6))) = (byte *)CONCAT11(0xff,(char)uStack_6);
  uStack_8 = (byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) << 8);
  for (iVar21 = -2; iVar21 < 2; iVar21 = iVar21 + 1) {
    uStack_e = ovr_ovc45_getUnitIndex(GfxRndSeed + iVar21,GfxRndSeed2);
    bVar10 = ovr_ovc45_getUnitType(GfxRndSeed + iVar21,GfxRndSeed2);
    uVar6 = (ulong)uStack_6;
    uStack_8 = (byte *)CONCAT11(bVar10,(byte)uStack_8);
    uVar24 = (undefined2)((ulong)GUnits >> 0x10);
    puVar20 = (unit_t *)GUnits;
    bVar29 = puVar20[uStack_e].unitType;
    (*(uint32_t *)((uint8_t *)&(uStack_6))) = CONCAT12(bVar29,(byte *)uStack_6);
    uStack_6 = (byte *)(ulong)(uint3)uStack_6;
    uVar7 = (ulong)uStack_6;
    uStack_6 = (byte *)uVar7;
    if (((0xf7 < uStack_e) && (bVar29 != 0xff)) &&
       ((*(char *)((int)*(undefined4 *)((uint)bVar29 << 2) + 0x3f) == '\0' &&
        ((*(uint8_t *)((uint8_t *)&(uStack_6) + 1)) = SUB41(uVar6,1), bVar4 = puVar20[uStack_e].level <= (*(uint8_t *)((uint8_t *)&(uStack_6) + 1)), bVar4))
       )) {
      (*(uint8_t *)((uint8_t *)&(uStack_6))) = (char)uVar6;
      (*(uint16_t *)((uint8_t *)&(uStack_6))) = (byte *)CONCAT11(puVar20[uStack_e].level,(char)uStack_6);
      uStack_6 = (byte *)(ulong)CONCAT12(bVar29,(byte *)uStack_6);
    }
    uVar6 = (ulong)uStack_6;
    if ((*(char *)((int)*(undefined4 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_6) + 2)) << 2) + 0x3f) == '\0') &&
       (puVar20[uStack_e].unitType != 0xff)) {
      uVar23 = uVar23 + *(byte *)((uint)bVar10 * 0x27 + 0x11b);
    }
    cVar9 = *(char *)((uint)bVar10 * 0x27 + 0x132);
    uStack_6 = (byte *)CONCAT13(cVar9,(uint3)uStack_6);
    in_DX = 0x2410;
    if (((5 < puVar20[uStack_e].level) && (cVar9 == -0x7a)) &&
       ((*(uint8_t *)((uint8_t *)&(uStack_8))) = (byte)uStack_8 + 1, uStack_8 = (byte *)CONCAT11(bVar10,(byte)uStack_8),
       (byte)uStack_8 < 2)) {
      uStack_6 = (byte *)uVar6;
    }
    if ((*(uint8_t *)((uint8_t *)&(uStack_6) + 3)) != 0x0) {
      if (CurSfxType3 == 0xff) {
        in_DX = CONCAT11(0x24,(*(uint8_t *)((uint8_t *)&(uStack_6) + 3)));
        CurSfxType3 = (*(uint8_t *)((uint8_t *)&(uStack_6) + 3));
      }
      else {
        uVar12 = ovr_randBelow(2);
        if ((uVar12 & 0xff) == 0) {
          in_DX = CONCAT11((char)(in_DX >> 8),(*(uint8_t *)((uint8_t *)&(uStack_6) + 3)));
          CurSfxType3 = (*(uint8_t *)((uint8_t *)&(uStack_6) + 3));
        }
      }
    }
  }
  if (((uStack_10 == 0x1000) && (CurSfxType3 == 0xff)) && ((*(uint8_t *)((uint8_t *)&(uStack_6) + 1)) != 0xff)) {
    if ((*(uint8_t *)((uint8_t *)&(uStack_6) + 1)) < 5) {
      CurSfxType3 = 0x61;
    }
    else if (2 < (int)uVar23) {
      CurSfxType3 = 0x5e;
    }
  }
  if (CurSfxType3 != 0xff) {
    return (byte *)((char *)"puppetmaker" + 3);
  }
  uVar28 = 0xca;
  uVar30 = 99;
  uVar13 = ovr_constr_usesGMapFlags2(GfxRndSeed,GfxRndSeed2 + 1);
  pbVar11 = (byte *)(uVar13 & 0xff);
  if ((byte *)__C0_ASM_CopyRight < pbVar11) {
    return pbVar11;
  }
  bVar29 = (byte)unaff_SS;
  uVar31 = (undefined1)((uint)unaff_SS >> 8);
  switch(pbVar11) {
  case (byte *)0x0:
    *(char *)((int)pbVar11 * 2) = *(char *)((int)pbVar11 * 2) + (char)(in_DX >> 8);
    uStack_c = (uint)(byte)((byte)uVar13 & (byte)*(undefined2 *)(&stack0x02c2 + uVar23));
    uVar23 = ovr_randBelow(in_stack_0000ffd8);
    uStack_e = uVar23 & 0xff;
    uVar23 = ovr_randBelow(uStackY_2c);
    uStack_6 = (byte *)(CONCAT22(uVar23,(byte *)uStack_6) & 0xffffff);
    uVar31 = 0x83;
    uVar32 = 0x9a;
    uVar23 = ovr_randBelow(in_stack_0000ffd8);
    uStack_6 = (byte *)(CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),uVar23) & 0xffff00ff);
    if (uStack_e < uStack_c) {
      uVar13 = (uint)(*(uint16_t *)((uint8_t *)&(uStack_6) + 2)) / (uint)((byte *)uStack_6 + 1);
      uStack_10 = 1;
    }
    else {
      if ((byte *)uStack_6 <= (*(uint16_t *)((uint8_t *)&(uStack_6) + 2))) {
        return (*(uint16_t *)((uint8_t *)&(uStack_6) + 2));
      }
      uVar13 = (uint)(byte *)uStack_6 / (uint)((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)) + 1);
      uStack_10 = 0;
    }
    pbVar11 = (byte *)(uVar13 + 1);
    uStack_8 = pbVar11;
    if ((byte *)((int)(undefined4 *)&_DATA + 2) < pbVar11) {
      uStack_8 = (byte *)((int)(undefined4 *)&_DATA + 2);
    }
    bStackY_2d = 0xff;
    bStackY_2e = 0;
    uVar14 = 0xffff;
    uStack_a = 0xffff;
    uVar13 = CONCAT11(uVar32,uVar31);
    break;
  case (byte *)0x1:
    TextBlitX = in_DX - (int)pbVar11;
    ovr_blitLabel((char *)"UNITS",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                  (uint8_t)Font02.seg);
    iVar21 = ovr_font_textWidth("POPULATION",
                                (char *)CONCAT13((char)(Font02.seg >> 8),
                                                 CONCAT12((char)Font02.seg,Font02.ofs)));
    uVar12 = 0xd4 - iVar21;
    TextBlitX = uVar12;
    ovr_blitLabel((char *)"POPULATION",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                  (uint8_t)Font02.seg);
    for (iVar21 = 0; TextBlitY = TextBlitY + 0xc, iVar21 < (int)(uStack_c >> 8); iVar21 = iVar21 + 1
        ) {
      TextBlitX = 0x11;
      if ((iVar21 < 5) || ((char)uStack_c == '\0')) {
        ovr_blitLabel((char *)auStackY_96[iVar21 * 2],(uint8_t *)auStackY_96[iVar21 * 2 + 1],
                      Font02.ofs,(uint8_t)Font02.seg);
      }
      else {
        uVar25 = *(undefined4 *)((partyIndex & 0xff) << 2);
        uVar13 = (uint)*(byte *)((int)uVar25 + 0x2f);
        ovr_blitLabel((char *)auStackY_11a[iVar21 * 2 + uVar13 * 8],
                      (uint8_t *)auStackY_11a[iVar21 * 2 + uVar13 * 8 + 1],Font02.ofs,
                      (uint8_t)Font02.seg);
      }
      func_0x0005f303();
      ovr_stsprintf(acStackY_13e,(char *)unaff_SS,(char *)"%d");
      iVar22 = ovr_font_textWidth((char *)CONCAT13(uVar31,CONCAT12(bVar29,acStackY_13e)),
                                  (char *)CONCAT13((char)(Font02.seg >> 8),
                                                   CONCAT12((char)Font02.seg,Font02.ofs)));
      TextBlitX = 0x89 - iVar22;
      ovr_blitLabel(acStackY_13e,(uint8_t *)unaff_SS,Font02.ofs,(uint8_t)Font02.seg);
      ovr_stsprintf(acStackY_13e,(char *)unaff_SS,(char *)"%d");
      iVar22 = ovr_font_textWidth((char *)CONCAT13(uVar31,CONCAT12(bVar29,acStackY_13e)),
                                  (char *)CONCAT13((char)(Font02.seg >> 8),
                                                   CONCAT12((char)Font02.seg,Font02.ofs)));
      uVar12 = 0xd4 - iVar22;
      TextBlitX = uVar12;
      ovr_blitLabel(acStackY_13e,(uint8_t *)unaff_SS,Font02.ofs,(uint8_t)Font02.seg);
    }
    CurSfxType3 = 0x3c;
    entries.seg = (uint16_t)unaff_SS;
    entries.ofs = (uint16_t)auStackY_66;
    uVar24 = ovr_ovc28_usesUiInputText
                       (entries,uVar23,far_from_u32((uint32_t)(0x0)),(uint8_t *)&uStack_e,(uint16_t)unaff_SS);
    cVar9 = (char)uVar24;
    uStack_e = CONCAT11(cVar9,(byte)uStack_e);
    keyboardInputMode = 0;
    if (((cVar9 != '\0') && (cVar9 != '\x01')) && (cVar9 != -2)) {
      (&stack0xbac4)[uVar23] = (&stack0xbac4)[uVar23] + in_CL;
      iVar22 = 0x2410;
      do {
        iVar16 = iVar22 * uVar12;
        iVar22 = iVar21;
        if (*(byte *)(iVar21 * 0x34 + 0x22) < *(byte *)(iVar16 + 0x21)) {
          *(undefined1 *)(iVar21 * 0x34 + 0x21) = *(undefined1 *)(iVar21 * 0x34 + 0x22);
        }
        do {
          iVar22 = iVar22 + 1;
          if ((int)(uint)AgntCount <= iVar22) {
            uVar23 = ovr_audio_panFromX(agnt);
            ovr_play_sfxU(0x1c,0,uVar23);
            return (byte *)CONCAT11((char)(uVar23 >> 8),1);
          }
        } while (*(uint16_t *)(iVar22 * 0x34 + 0x1b) != ((agnt_t *)agnt)->owner);
        uVar24 = (undefined2)((ulong)uStack_6 >> 0x10);
        if (*(byte *)((int)uStack_6 + 0x32) < *(byte *)(iVar22 * 0x34 + 0x22)) {
          *(undefined1 *)(iVar22 * 0x34 + 0x22) = *(undefined1 *)((int)uStack_6 + 0x32);
        }
        uVar12 = 0x34;
        iVar21 = iVar22;
      } while( true );
    }
    if (cVar9 == -2) {
      Cancelled = 1;
    }
    return (byte *)((char *)"puppetmaker" + 3);
  case (byte *)0x2:
    pbVar11 = (byte *)(partyIndex * 0x37);
    if (*(char *)((int)&((entity_t *)Entities)[partyIndex].base.entity + 3) != -1) {
      bVar8 = ovr_agnt_compute10((agnt_t *)
                                 CONCAT13((char)((ulong)Entities >> 0x18),
                                          CONCAT12((char)((ulong)Entities >> 0x10),
                                                   (entity_t *)Entities + partyIndex)));
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = (uint3)bVar8 << 8;
      uVar33 = *(undefined1 *)((int)&((entity_t *)Entities)[partyIndex].base.entity + 3);
      pbVar11 = (byte *)CONCAT11((char)(partyIndex * 0x37 >> 8),uVar33);
      uStack_6 = (byte *)CONCAT13(uVar33,(uint3)uStack_6);
      while (cVar9 = (char)uStack_6, (char)uStack_6 < '\x04') {
        pbVar11 = (byte *)((char)uStack_6 * 2);
        if (*(int *)(pbVar11 + (int)*(undefined4 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_6) + 3)) << 2) + 0x76) != 0) {
          pbVar11 = (byte *)(int)(char)(*(uint8_t *)((uint8_t *)&(uStack_6) + 1));
          if ((int)pbVar11 < (char)uStack_6 + 1) {
            (*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) = (char)uStack_6;
            piVar2 = (int *)((int)*(undefined4 *)((uint)(*(uint8_t *)((uint8_t *)&(uStack_6) + 3)) << 2) + (char)uStack_6 * 2 +
                            0x76);
            *piVar2 = *piVar2 + -1;
            uVar24 = (undefined2)((ulong)Entities >> 0x10);
            peVar19 = (entity_t *)Entities;
            peVar19[partyIndex].dir =
                 peVar19[partyIndex].dir + (char)(((ulong)peVar19[partyIndex].dir / 6) % 6) * -6;
            bVar8 = ((entity_t *)Entities)[partyIndex].base.gindex;
            (*(uint32_t *)((uint8_t *)&(uStack_6))) = CONCAT12(bVar8,(byte *)uStack_6);
            if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar8 * 0x95) == '\x03') &&
               ('\x01' < cVar9)) {
              (*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) = '\x01';
            }
            if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar8 * 0x95) == '\x01') &&
               ('\x02' < (char)(*(uint8_t *)((uint8_t *)&(uStack_8) + 1)))) {
              (*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) = '\x02';
            }
            cVar9 = ovc22_compute3((*(uint8_t *)((uint8_t *)&(uStack_8) + 1)) + '\x01');
            uVar24 = (undefined2)((ulong)Entities >> 0x10);
            bVar8 = ((entity_t *)Entities)[partyIndex].dir + cVar9 * '\x06';
            ((entity_t *)Entities)[partyIndex].dir = bVar8;
            return (byte *)CONCAT11((char)(partyIndex * 0x37 >> 8),bVar8);
          }
        }
        uStack_6 = (byte *)CONCAT31((*(uint32_t *)((uint8_t *)&(uStack_6) + 1)),(char)uStack_6 + '\x01');
      }
    }
    return pbVar11;
  case (byte *)0x3:
    do {
      if (*(uint *)((int)*(undefined4 *)(uStack_a << 2) + 0x47) < 10) {
        ovc25_usesAlignUp43((byte)uStack_a,10,
                            *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x39),
                            *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b),'\0');
        *(undefined1 *)((int)*(undefined4 *)(uStack_a << 2) + 0x4a) = 0;
      }
      else {
        *(undefined1 *)((int)*(undefined4 *)(uStack_a << 2) + 0x4a) = 0;
        iVar21 = ovc25_compute1(*(byte *)((int)*(undefined4 *)(uStack_a << 2) + 0x3e));
        uStack_6 = (byte *)CONCAT22(iVar21,(byte *)uStack_6);
        if ((int)(uint)PlayerCount < iVar21) {
          uVar12 = ovr_randBelow(0x28);
          iVar21 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x39) + -0x14 + (uVar12 & 0xff);
          (*(uint16_t *)((uint8_t *)&(uStack_6))) = (byte *)iVar21;
          if (iVar21 < 4) {
            (*(uint16_t *)((uint8_t *)&(uStack_6))) = (byte *)0x4;
          }
          if (0x8c < (int)(byte *)uStack_6) {
            uStack_6 = (byte *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),0x8b);
          }
          uVar12 = ovr_randBelow(0x14);
          uStack_8 = (byte *)(*(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) + -10 +
                             (uVar12 & 0xff));
          if ((int)uStack_8 < 1) {
            uStack_8 = (byte *)0x1;
          }
          if (0x3a < (int)uStack_8) {
            uStack_8 = (byte *)0x3a;
          }
          ovc25_usesAlignUp44((char)uStack_a,1,(uint16_t)(byte *)uStack_6,(uint16_t)uStack_8);
        }
      }
      while( true ) {
        while( true ) {
          do {
            uStack_a = uStack_a + 1;
            pbVar11 = (byte *)(uint)GLeaderCount;
            if ((int)pbVar11 <= (int)uStack_a) {
              ovc25_clearEntityFlags();
              return pbVar11;
            }
          } while ((*(char *)((int)*(undefined4 *)(uStack_a * 4) + 0x40) == '\0') ||
                  (*(char *)((int)*(undefined4 *)(uStack_a * 4) + 0x3d) == '\0'));
          ovc25_intelAttackingNotice((byte)uStack_a);
          if (*(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x4b) == -1) {
            uVar13 = 0xffff;
          }
          else {
            uVar23 = *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x4b);
            uVar24 = (undefined2)((ulong)Entities >> 0x10);
            uVar13 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x39) -
                     (((entity_t *)Entities + uVar23)->base).x;
            uVar17 = (int)uVar13 >> 0xf;
            uVar14 = *(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b) -
                     ((entity_t *)Entities)[uVar23].base.y;
            uVar18 = (int)uVar14 >> 0xf;
            uVar13 = (int)((uVar13 ^ uVar17) - uVar17) / 2 + ((uVar14 ^ uVar18) - uVar18);
          }
          if ((*(int *)((int)*(undefined4 *)(uStack_a << 2) + 0x43) == 0) || (9 < uVar13)) break;
          ovc25_usesEntityCount((byte)uStack_a);
          if (9 < *(uint *)((int)*(undefined4 *)(uStack_a << 2) + 0x47)) {
            uVar24 = (undefined2)((ulong)Entities >> 0x10);
            ovc25_usesAlignUp43((byte)uStack_a,5,(((entity_t *)Entities + uVar23)->base).x,
                                ((entity_t *)Entities)[uVar23].base.y,'\x01');
          }
          ovc25_usesAlignUp43((byte)uStack_a,10,
                              *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x39),
                              *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b),'\0');
          *(undefined1 *)((int)*(undefined4 *)(uStack_a << 2) + 0x4a) = 1;
        }
        if ((*(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x49) == -1) ||
           ((*(byte *)((int)*(undefined4 *)(uStack_a << 2) + 0x5d) & 1) == 0)) break;
        ovc25_usesEntityCount((byte)uStack_a);
        bVar8 = *(byte *)((int)*(undefined4 *)(uStack_a << 2) + 0x49);
        if (0xe < *(uint *)((int)*(undefined4 *)(uStack_a << 2) + 0x47)) {
          ovc25_usesAlignUp42((byte)uStack_a,10,
                              *(uint16_t *)((int)*(undefined4 *)((uint)bVar8 << 2) + 0x39),
                              *(uint16_t *)((int)*(undefined4 *)((uint)bVar8 << 2) + 0x3b),
                              *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x39),
                              *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b));
          if (*(char *)((int)*(undefined4 *)(uStack_a << 2) + 0x4a) != '\x02') {
            ovr_alignUp4(*(int *)((int)*(undefined4 *)((uint)bVar8 << 2) + 0x39));
            uVar12 = 0x195d;
            uStackY_2a = 0x2379;
            uStackY_2c = 0xc5d4;
            pcVar15 = ovr_stsprintf(acStackY_68,(char *)unaff_SS,
                                    (char *)"Spies report %s heading towards stronghold. (%d, %d)");
            ovr_uiNotify(pcVar15,uVar12);
          }
        }
        ovc25_usesAlignUp43((byte)uStack_a,0xf,
                            *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x39),
                            *(uint16_t *)((int)*(undefined4 *)(uStack_a << 2) + 0x3b),'\0');
        *(undefined1 *)((int)*(undefined4 *)(uStack_a << 2) + 0x4a) = 2;
      }
    } while( true );
  case (byte *)0x4:
    if ((byte)uStack_8 < ListCount) {
      uVar24 = (undefined2)((ulong)GUnits >> 0x10);
      uStack_a = ((unit_t *)GUnits)[*(int *)(((uint)uStack_8 & 0xff) * 2 + -0x6d44)].x;
      uStack_c = ((unit_t *)GUnits)[*(int *)(((uint)uStack_8 & 0xff) * 2 + -0x6d44)].y;
    }
    else {
      uVar25 = *(undefined4 *)((partyIndex & 0xff) << 2);
      uStack_a = *(uint16_t *)((int)uVar25 + 0x39);
      uVar25 = *(undefined4 *)((partyIndex & 0xff) << 2);
      uStack_c = *(uint16_t *)((int)uVar25 + 0x3b);
    }
    uVar25 = *(undefined4 *)((partyIndex & 0xff) << 2);
    uVar24 = (undefined2)((ulong)uVar25 >> 0x10);
    iVar22 = (int)uVar25;
    iVar21 = *(int *)(iVar22 + 0x58);
    if ((iVar21 < 1) && ((iVar21 < 0 || (*(uint *)(iVar22 + 0x56) < 10)))) {
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = CONCAT12(1,(byte *)uStack_6);
    }
    else {
      (*(uint32_t *)((uint8_t *)&(uStack_6))) = ZEXT23((byte *)uStack_6);
    }
    uVar25 = *(undefined4 *)((partyIndex & 0xff) << 2);
    if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 + (uint)*(byte *)((int)uVar25 + 0x3e) * 0x95) &
        0x80) == 0) {
      uStack_6 = (byte *)(ulong)(uint3)uStack_6;
    }
    else {
      uStack_6 = (byte *)CONCAT13(3,(uint3)uStack_6);
    }
    uVar25 = *(undefined4 *)((partyIndex & 0xff) << 2);
    if ((*(byte *)((int)uVar25 + 0x5d) & 2) != 0) {
      uStack_6 = (byte *)((ulong)uStack_6 | 0x1000000);
    }
    uVar25 = *(undefined4 *)((partyIndex & 0xff) << 2);
    if ((*(byte *)((int)uVar25 + 0x5d) & 4) != 0) {
      uStack_6 = (byte *)((ulong)uStack_6 | 0x2000000);
    }
    uVar13 = ovc22_searchCellsAround(&uStack_a,unaff_SS,(byte)&uStack_c,bVar29,(byte)partyIndex);
    pbVar11 = (byte *)(uVar13 & 0xff);
    if (pbVar11 != (byte *)0x0) {
      if (pbVar11 != (byte *)((int)(undefined4 *)&_DATA + 1U)) {
        return pbVar11;
      }
      uStack_e = ovc22_usesRandBelow((byte)partyIndex,uStack_a,uStack_c);
      if (uStack_e == 0) {
        uVar25 = *(undefined4 *)((partyIndex & 0xff) << 2);
        uStack_a = *(uint16_t *)((int)uVar25 + 0x39);
        uVar25 = *(undefined4 *)((partyIndex & 0xff) << 2);
        uStack_c = *(uint16_t *)((int)uVar25 + 0x3b);
      }
      else {
        if ((*(uint *)(uStack_e * 0x27 + 0x121) & 0x60) == 0) {
          uVar25 = *(undefined4 *)((partyIndex & 0xff) << 2);
          uVar24 = (undefined2)((ulong)uVar25 >> 0x10);
          iVar22 = (int)uVar25;
          iVar21 = *(int *)(iVar22 + 0x58);
          if ((iVar21 < 0) ||
             ((iVar21 == 0 && (*(uint *)(iVar22 + 0x56) < *(uint *)(uStack_e * 0x27 + 0x125))))) {
            uVar25 = *(undefined4 *)((partyIndex & 0xff) << 2);
            uVar24 = (undefined2)((ulong)uVar25 >> 0x10);
            iVar21 = (int)uVar25;
            *(undefined2 *)(iVar21 + 0x58) = 0;
            *(undefined2 *)(iVar21 + 0x56) = 0;
          }
          else {
            uVar14 = *(uint *)(uStack_e * 0x27 + 0x125);
            uVar25 = *(undefined4 *)((partyIndex & 0xff) << 2);
            uVar24 = (undefined2)((ulong)uVar25 >> 0x10);
            iVar21 = (int)uVar25;
            puVar1 = (uint *)(iVar21 + 0x56);
            uVar13 = *puVar1;
            *puVar1 = *puVar1 - uVar14;
            piVar2 = (int *)(iVar21 + 0x58);
            *piVar2 = *piVar2 - (uint)(uVar13 < uVar14);
          }
        }
        ovr_createConstructionRecordFar
                  ((byte)uStack_e,uStack_a,uStack_c,(uint8_t *)outFlag,(byte)agnt,(byte)partyIndex);
      }
    }
    uVar25 = *(undefined4 *)((partyIndex & 0xff) << 2);
    if (*(char *)((int)uVar25 + 0x3f) == '\0') {
      uVar25 = *(undefined4 *)((partyIndex & 0xff) << 2);
      uVar5 = *(undefined4 *)((partyIndex & 0xff) << 2);
      if (*(uint *)((int)uVar25 + 0x5b) < *(uint *)((int)uVar5 + 0x4d)) {
        pbVar11 = (byte *)ovr_ovc18_textTypeLen((byte)partyIndex,uStack_a,uStack_c,0x1);
      }
      else {
        pbVar11 = (byte *)ovr_ovc18_textTypeLen((byte)partyIndex,uStack_a,uStack_c,0x0);
      }
    }
    else {
      pbVar11 = (byte *)ovr_ovc18_textTypeLen((byte)partyIndex,0,0,0x0);
    }
    return pbVar11;
  }
  do {
    if (CONCAT11(uVar30,uVar28) < (int)uVar13) {
      if (uStack_a != 0xffff) {
        if (uVar14 == 0xffff) {
          ovr_attact_usesRandBelow
                    ((agnt_t *)
                     CONCAT13((char)((ulong)Entities >> 0x18),
                              CONCAT12((char)((ulong)Entities >> 0x10),
                                       (entity_t *)Entities + uStack_a)),
                     ((entity_t *)Entities)[uStack_a].base.target);
          ovr_attact_usesEntities(uStack_a,0,0,0,0);
          uVar24 = (undefined2)((ulong)Entities >> 0x10);
          pbVar11 = (byte *)(uint)*(byte *)((int)(char **)GMenuStrings +
                                           (uint)((entity_t *)Entities)[uStack_a].base.gindex * 0x95
                                           + 0x1f);
          if (pbVar11 == (byte *)0x0) {
            alignUp4((((entity_t *)Entities + uVar13)->base).x);
            uVar23 = 0x195d;
            pbVar11 = (byte *)ovr_fmVsprintf((char *)
                                             "Intelligence reports %s unit fleeing from battle. (%d, %d)"
                                             ,(char *)"puppetmaker" + 3);
            ovr_uiNotify((char *)pbVar11,uVar23);
          }
        }
        else {
          if ((byte *)(uint)((entity_t *)Entities)[uVar14].base.animFrame <= uStack_8) {
            uStack_8 = (byte *)(uint)((entity_t *)Entities)[uVar14].base.animFrame;
          }
          ((entity_t *)Entities)[uVar14].base.animFrame =
               ((entity_t *)Entities)[uVar14].base.animFrame - (byte)uStack_8;
          ovr_ovc41_compute4((agnt_t *)
                             CONCAT13((char)((ulong)Entities >> 0x18),
                                      CONCAT12((char)((ulong)Entities >> 0x10),
                                               (entity_t *)Entities + uVar14)),(byte)uStack_8,
                             (byte)((entity_t *)Entities + uStack_a),
                             (agnt_t *)CONCAT13(bVar8,CONCAT12(uVar33,(*(uint16_t *)((uint8_t *)&(Entities) + 2)))));
          ovr_ovc25_attackingNotice(*(byte *)((int)&((entity_t *)Entities)[uVar14].base.entity + 3))
          ;
          pbVar11 = (byte *)(uVar14 * 0x37);
          if (((entity_t *)Entities)[uVar14].base.animFrame != 0x0) {
            ovc24_usesLDIV_at_(uVar14);
            uVar24 = (undefined2)((ulong)Entities >> 0x10);
            peVar19 = (entity_t *)Entities;
            if ((((*(uint *)((int)&worldMenuLabels[7].ofs + 1 +
                            (uint)peVar19[uStack_a].base.gindex * 0x95) & 4) != 0) &&
                ((*(uint *)((int)&peVar19[uVar14].base.frames + 1) & 1) == 0)) &&
               (uVar17 = ovr_ovc27_rollToHitAgent
                                   (CONCAT13((char)((ulong)Entities >> 0x18),
                                             CONCAT12((char)((ulong)Entities >> 0x10),
                                                      peVar19 + uVar14)),0), (uVar17 & 0xff) == 0))
            {
              puVar1 = (uint *)((int)&((entity_t *)Entities)[uVar14].base.frames + 1);
              *puVar1 = *puVar1 | 1;
              alignUp4((((entity_t *)Entities + uVar13)->base).x);
              uVar23 = 0x195d;
              pcVar15 = ovr_fmVsprintf((char *)
                                       "Intelligence reports %s unit infected with disease. (%d, %d)"
                                       ,(char *)"puppetmaker" + 3);
              ovr_uiNotify(pcVar15,uVar23);
            }
            pbVar11 = (byte *)((uint)((entity_t *)Entities)[uStack_a].base.gindex * 0x95);
            if ((*(uint *)(pbVar11 + 0x2714) & 0xc00) != 0) {
              uVar17 = ovr_ovc27_rollToHitAgent
                                 (CONCAT13((char)((ulong)Entities >> 0x18),
                                           CONCAT12((char)((ulong)Entities >> 0x10),
                                                    (entity_t *)Entities + uVar14)),3);
              pbVar11 = (byte *)(uVar17 & 0xff);
              if (pbVar11 == (byte *)0x0) {
                if ((*(uint *)((int)&worldMenuLabels[7].ofs + 1 +
                              (uint)((entity_t *)Entities)[uStack_a].base.gindex * 0x95) & 0x800) ==
                    0) {
                  cVar9 = '\x01';
                }
                else {
                  cVar9 = '\x02';
                }
                uVar24 = ovr_ovc27_compute3(CONCAT13((char)((ulong)Entities >> 0x18),
                                                     CONCAT12((char)((ulong)Entities >> 0x10),
                                                              (entity_t *)Entities + uVar14)),cVar9)
                ;
                if ((char)uVar24 != '\0') {
                  if (DebugVerbose != false) {
                    printf("kill 3\r");
                  }
                  uVar24 = (undefined2)((ulong)Entities >> 0x10);
                  if (((entity_t *)Entities)[uVar14].base.animFrame != 0x0) {
                    puVar3 = &((entity_t *)Entities)[uVar14].base.animFrame;
                    *puVar3 = *puVar3 + 0xff;
                  }
                }
                alignUp4((((entity_t *)Entities + uVar13)->base).x);
                uVar23 = 0x195d;
                pbVar11 = (byte *)ovr_fmVsprintf((char *)
                                                 "Intelligence reports %s unit drained of energy. (%d, %d)"
                                                 ,(char *)"puppetmaker" + 3);
                ovr_uiNotify((char *)pbVar11,uVar23);
              }
            }
          }
        }
      }
      return pbVar11;
    }
    pbVar11 = (byte *)((entity_t *)Entities)[uVar13].base.y;
    if ((pbVar11 != (byte *)((ulong)uVar25 >> 0x10)) ||
       (pbVar11 = (byte *)alignUp4((((entity_t *)Entities + uVar13)->base).x),
       pbVar11 != (byte *)CONCAT11(uVar27,uVar26))) goto L_OVC24_5943_026e_08A7;
    uVar24 = (undefined2)((ulong)Entities >> 0x10);
    peVar19 = (entity_t *)Entities;
    if (*(char *)((int)(char **)GMenuStrings + (uint)peVar19[uVar13].base.gindex * 0x95 + 0x1f) ==
        (char)uStack_10) {
      if (peVar19[uVar13].base.level < bStackY_2d) {
L_OVC24_5943_026e_0772:
        uVar24 = (undefined2)((ulong)Entities >> 0x10);
        bVar8 = ((entity_t *)Entities)[uVar13].base.gindex;
        if ((((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)bVar8 * 0x95) & 0x40) == 0) ||
            (pbVar11 = &stack0xffde + (uStack_10 ^ 1), '\x01' < (char)*pbVar11)) &&
           ((((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)bVar8 * 0x95) & 8) == 0 ||
             (pbVar11 = &stack0xffde + (uStack_10 ^ 1), '\0' < (char)*pbVar11)) &&
            (((*(uint *)((int)&worldMenuLabels[7].ofs + 1 + (uint)bVar8 * 0x95) & 0x10) == 0 ||
             (pbVar11 = &stack0xffdc + (uStack_10 ^ 1), -1 < (char)*pbVar11)))))) {
          bStackY_2d = ((entity_t *)Entities)[uVar13].base.level;
          pbVar11 = (byte *)CONCAT11((char)(uVar13 * 0x37 >> 8),bStackY_2d);
          uVar14 = uVar13;
        }
      }
      else {
        bVar29 = peVar19[uVar13].base.level;
        pbVar11 = (byte *)CONCAT11((char)(uVar13 * 0x37 >> 8),bVar29);
        if (bVar29 == bStackY_2d) {
          uVar23 = ovr_randBelow(3);
          pbVar11 = (byte *)(uVar23 & 0xff);
          if (pbVar11 == (byte *)0x0) goto L_OVC24_5943_026e_0772;
        }
      }
    }
    else if (bStackY_2e < peVar19[uVar13].base.level) {
L_OVC24_5943_026e_088A:
      bStackY_2e = ((entity_t *)Entities)[uVar13].base.level;
      pbVar11 = (byte *)CONCAT11((char)(uVar13 * 0x37 >> 8),bStackY_2e);
      uStack_a = uVar13;
    }
    else {
      bVar29 = peVar19[uVar13].base.level;
      pbVar11 = (byte *)CONCAT11((char)(uVar13 * 0x37 >> 8),bVar29);
      if (bVar29 == bStackY_2e) {
        uVar23 = ovr_randBelow(3);
        pbVar11 = (byte *)(uVar23 & 0xff);
        if (pbVar11 == (byte *)0x0) goto L_OVC24_5943_026e_088A;
      }
    }
L_OVC24_5943_026e_08A7:
    uVar13 = uVar13 + 1;
  } while( true );
}



/* 55fe:0487 */

/* Stamps GameTick on the records overlapping a column and counts down their timers. */

undefined1 __cdecl16far ovc23_tickRecordsAt(uint16_t x,int y,char excluded)

{
  char *pcVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 uStack_3;
  
  uVar4 = ovr_alignUp4(x);
  uStack_3 = 0;
  for (uVar5 = 0; uVar5 < GRecordCount; uVar5 = uVar5 + 1) {
    if ((((*(int *)(uVar5 * 0x12 + 4) == y) && (*(uint *)(uVar5 * 0x12 + 2) <= uVar4 + 1)) &&
        (uVar4 - 2 <= (*(int *)(uVar5 * 0x12 + 2) + (uint)*(byte *)(uVar5 * 0x12 + 7)) - 1)) &&
       ((bVar2 = *(byte *)(uVar5 * 0x12 + 9), bVar2 != 0xff &&
        (uVar3 = *(undefined4 *)((uint)bVar2 << 2), *(char *)((int)uVar3 + 0x3f) == excluded)))) {
      *(undefined2 *)(uVar5 * 0x12 + 0xf) = GameTick;
      if (*(char *)(uVar5 * 0x12 + 0xb) != '\0') {
        pcVar1 = (char *)(uVar5 * 0x12 + 0xb);
        *pcVar1 = *pcVar1 + -1;
      }
      if (*(char *)(uVar5 * 0x12 + 0xb) == '\0') {
        *(undefined1 *)(uVar5 * 0x12 + 0xe) = 1;
      }
      uStack_3 = 1;
    }
  }
  return uStack_3;
}



/* 55fe:05db */

/* Returns whether the point matches the cell in GfxRndSeed/GfxRndSeed2. */

uint __cdecl16far ovc23_isCursorAt(uint16_t x,int y)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = ovr_alignUp4(x);
  uVar2 = ovr_alignUp4(GfxRndSeed);
  if ((uVar1 == uVar2) && (uVar2 = GfxRndSeed2, GfxRndSeed2 == y)) {
    uVar2 = CONCAT11((char)(GfxRndSeed2 >> 8),1);
  }
  else {
    uVar2 = uVar2 & 0xff00;
  }
  return uVar2;
}



/* 55fe:0617 */

/* [R6] touches cornerBR, cornerBL */

int __cdecl16far ovc23_usesCornerBR(int x,int bldType)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iStack_14;
  int iStack_12;
  uint8_t cornerBR;
  uint8_t cornerBL;
  uint8_t cornerTR;
  uint8_t cornerTL;
  int iStack_4;
  
  iVar1 = ovr_constr_usesSmoothPrev(x,-1,(int *)&cornerTL);
  iVar2 = ovr_constr_usesSmoothPrev(x,0,(int *)&cornerBL);
  if (*(byte *)(bldType * 0x27 + 0x11b) < 2) {
    iStack_12 = ovr_constr_usesSmoothPrev(x + 1,-1,(int *)&cornerTR);
    iStack_14 = ovr_constr_usesSmoothPrev(x + 1,0,(int *)&cornerBR);
  }
  else if (*(byte *)(bldType * 0x27 + 0x11b) < 3) {
    iStack_12 = ovr_constr_usesSmoothPrev(x + 2,-1,(int *)&cornerTR);
    iStack_14 = ovr_constr_usesSmoothPrev(x + 2,0,(int *)&cornerBR);
  }
  else {
    iStack_12 = ovr_constr_usesSmoothPrev(x + 4,-1,(int *)&cornerTR);
    iStack_14 = ovr_constr_usesSmoothPrev(x + 4,0,(int *)&cornerBR);
  }
  uVar3 = (uint)cornerShadeBias[0];
  iStack_4 = iVar2 + iVar1 + iStack_12 + iStack_14 >> 2;
  if ((int)(iVar1 - uVar3) < (int)(iStack_12 - uVar3)) {
    iVar2 = iVar1 - uVar3;
  }
  else {
    iVar2 = iStack_12 - uVar3;
  }
  if (iStack_4 < iVar2) {
    if ((int)(iVar1 - uVar3) < (int)(iStack_12 - uVar3)) {
      iStack_4 = iVar1 - uVar3;
    }
    else {
      iStack_4 = iStack_12 - uVar3;
    }
  }
  return iStack_4;
}



/* 55fe:0768 */

/* [R6] touches cornerBR, cornerBL */

int __cdecl16far ovc23_usesCornerBR2(int x,int step)

{
  int iVar1;
  int iVar2;
  int iStack_12;
  uint8_t cornerBR;
  uint8_t cornerBL;
  uint8_t cornerTR;
  uint8_t cornerTL;
  int iStack_8;
  int iStack_6;
  int iStack_4;
  
  if (step == 4) {
    iVar1 = ovr_constr_usesSmoothPrev(x + 1,-1,(int *)&cornerTL);
    iStack_4 = ovr_constr_usesSmoothPrev(x + 1,0,(int *)&cornerBL);
    iStack_6 = ovr_constr_usesSmoothPrev(x + 2,-1,(int *)&cornerTR);
    iStack_8 = ovr_constr_usesSmoothPrev(x + 2,0,(int *)&cornerBR);
  }
  else {
    iVar1 = ovr_constr_usesSmoothPrev(x,-1,(int *)&cornerTL);
    iStack_4 = ovr_constr_usesSmoothPrev(x,0,(int *)&cornerBL);
    iStack_6 = ovr_constr_usesSmoothPrev(x + step,-1,(int *)&cornerTR);
    iStack_8 = ovr_constr_usesSmoothPrev(x + step,0,(int *)&cornerBR);
  }
  iStack_12 = iStack_4 + iVar1 + iStack_6 + iStack_8 >> 2;
  iVar2 = iStack_6;
  if (iVar1 < iStack_6) {
    iVar2 = iVar1;
  }
  if ((iStack_12 < iVar2) && (iStack_12 = iStack_6, iVar1 < iStack_6)) {
    iStack_12 = iVar1;
  }
  return iStack_12;
}



/* 55fe:0863 */

/* [R2] string "build\\thfres01.lbm" */

void __cdecl16far ovc23_textBuildThfres01Lbm(far_t dst)

{
  uint16_t play_id;
  bool bVar1;
  byte bVar2;
  undefined1 extraout_AH;
  int iVar4;
  uint16_t uVar5;
  int iVar3;
  
  bVar1 = false;
  GAnimPlaying = 0;
  uVar5 = rowMapSquareFirst[0];
  while( true ) {
    if (rowMapSquareEnd[0] <= uVar5) break;
    play_id = *(uint16_t *)(uVar5 * 2 + 0x360);
    if ((-3 < (int)play_id) && ((int)play_id < 2)) {
      bVar2 = ovr_constr_setHighlightAtOffset(play_id,0);
      iVar3 = CONCAT11(extraout_AH,bVar2);
      if (((char *)"build\\thfres01.lbm" + 0x10)[iVar3 * 3 + *(int *)(uVar5 * 2)] != '\0') {
        iVar4 = ovc23_usesCornerBR(play_id,iVar3);
        ovr_animAdvance(play_id,((char *)"build\\thfres01.lbm" + 0x10)
                                [iVar3 * 3 + *(int *)(uVar5 * 2)],*(uint16_t *)(uVar5 * 2 + 0xa20),
                        (uint)bandOrigin[0] - iVar4,dst);
        bVar1 = true;
      }
      iVar3 = iRam0002d2d7;
      if (*(int *)(play_id * 2 + -0x6e25) != -1) {
        if (*(char *)(play_id + 0x90ec) == '\0') {
          iVar3 = *(int *)(play_id * 2 + -0x6e25);
          iVar4 = ovc23_usesCornerBR2(play_id,(uint)*(byte *)(iVar3 * 0x12 + 7));
          ovc23_usesBlitGfxRect2
                    (*(int *)(uVar5 * 2 + 0xa20),(uint)bandOrigin[0] - iVar4,iVar3,
                     (brect_t *)dst.ofs,dst.seg);
          bVar1 = true;
        }
        else if (play_id == 0xfffe) {
          iVar4 = ovc23_usesCornerBR2(-2,(uint)*(byte *)(iRam0002d2d7 * 0x12 + 7));
          ovc23_usesBlitGfxRect2
                    (*(int *)(uVar5 * 2 + 0xa20) + -0x30,(uint)bandOrigin[0] - iVar4,iVar3,
                     (brect_t *)dst.ofs,dst.seg);
          bVar1 = true;
        }
      }
    }
    uVar5 = uVar5 + 1;
  }
  if (bVar1) {
    ovr_constr_usesScreenOriginY(dst.ofs,dst.seg);
  }
  return;
}



/* 55fe:0a56 */

/* Returns whether the building at the cell has bldtp_t.size >= 2. */

int __cdecl16far ovc23_isLargeBuilding(int x,int y)

{
  int iVar1;
  byte bVar2;
  
  iVar1 = (uint)((unit_t *)GUnits + ((short (*) [148] [60])GUnitGrid)[-1][x + 0x93][y])->bldType *
          0x27;
  bVar2 = (byte)((uint)iVar1 >> 8);
  if (*(byte *)(iVar1 + 0x11b) < 2) {
    iVar1 = (uint)bVar2 << 8;
  }
  else {
    iVar1 = CONCAT11(bVar2,1);
  }
  return iVar1;
}



/* 55fe:0aba */

/* [R6] touches GfxRndSeed2, GfxRndSeed */

void __cdecl16far ovc23_usesGfxRndSeed2(int x,int y)

{
  if (((GfxRndSeed2 == y) && (GfxRndSeed + -2 <= x)) && (x <= GfxRndSeed + 1)) {
    AgntClearFlag = true;
  }
  return;
}



/* 55fe:0af5 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00053af7) overlaps instruction at (ram,0x00053af6)
    */
/* [R4] calls ovr_alignUp4 */

uint * __cdecl16far ovc23_usesAlignUp43(int16_t x,uint16_t unitIndex,byte dir)

{
  uint8_t *puVar1;
  int *piVar2;
  uint *puVar3;
  byte *pbVar4;
  byte bVar5;
  undefined4 uVar6;
  far_t pctOut;
  far_t remainderOut;
  far_t partOut;
  bool bVar7;
  bool bVar8;
  byte bVar9;
  char cVar10;
  uint uVar11;
  char *msg;
  byte *pbVar12;
  undefined1 uVar15;
  uint16_t uVar13;
  uint *msg_00;
  uint uVar14;
  int in_CX;
  undefined2 uVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  entity_t *peVar21;
  entity_t *peVar22;
  unit_t *puVar23;
  undefined2 unaff_BP;
  undefined2 unaff_SI;
  uint uVar24;
  uint16_t unaff_DI;
  undefined2 uVar25;
  undefined2 uVar26;
  uint16_t unaff_SS;
  bool bVar27;
  undefined2 in_stack_00000000;
  uint uStackY_2e;
  int iStackY_2c;
  int iStackY_2a;
  byte bStackY_20;
  byte bStackY_1f;
  undefined2 uStackY_1e;
  uint8_t uStackY_1c;
  byte bStackY_1b;
  far_t table;
  undefined1 uVar28;
  byte bVar29;
  undefined1 in_stack_0000ffea;
  uint *entityIndex;
  undefined1 in_stack_0000ffeb;
  uint uVar30;
  byte *pbVar31;
  uint16_t uVar32;
  uint16_t uVar33;
  uint16_t uVar34;
  uint8_t outFlagSeg;
  undefined2 *puVar35;
  undefined1 uVar36;
  uint8_t uVar37;
  undefined1 uVar38;
  byte bVar39;
  uint in_stack_0000fffc;
  
  uVar28 = (undefined1)unaff_SI;
  uVar15 = (undefined1)((uint)unaff_SI >> 8);
  uVar16 = 0x2410;
  iVar17 = x + *(char *)(dir + 0x885);
  uVar14 = ovr_attact_usesGUnits(iVar17,unitIndex + (int)*(char *)(dir + 0x889));
  uVar24 = CONCAT11(in_stack_0000ffeb,in_stack_0000ffea);
  if ((uVar14 & 0xff) == 0) {
    return (uint *)((int)(undefined4 *)&_DATA + 1);
  }
  uVar14 = (uint)dir;
  if (3 < uVar14) {
    return (uint *)0x0;
  }
  puVar23 = (unit_t *)(uVar14 * 2);
  outFlagSeg = (uint8_t)unaff_SS;
  switch(uVar14) {
  case 0:
    return (uint *)unitIndex;
  case 1:
    while( true ) {
      if (((&puVar23->flags)[uVar14] & 3) == 0) {
        uVar16 = (undefined2)((ulong)GUnits >> 0x10);
        bVar9 = ((unit_t *)GUnits)[unitIndex].unitType;
        if ((bVar9 == 0xff) ||
           (uVar6 = *(undefined4 *)((uint)bVar9 << 2), *(char *)((int)uVar6 + 0x3f) == '\0')) {
          unaff_DI = 0x96;
        }
        else {
          unaff_DI = 0x5dc;
        }
        if (((unit_t *)GUnits)[unitIndex].level != 0) {
          uVar33 = ovr_randBelow(unaff_DI);
          uVar16 = (undefined2)((ulong)GUnits >> 0x10);
          puVar23 = (unit_t *)GUnits;
          if ((int)(uVar33 & 0xff) <
              (int)(100 - (uint)*(byte *)((uint)(puVar23 + unitIndex)->bldType * 0x27 + 0x130))) {
            bStackY_20 = (puVar23 + unitIndex)->bldType;
            puVar23[unitIndex].level = puVar23[unitIndex].level - 1;
            puVar23 = (unit_t *)GUnits;
            uVar16 = (undefined2)((ulong)GUnits >> 0x10);
            if (((*(uint *)((uint)bStackY_20 * 0x27 + 0x121) & 4) == 0) &&
               ((puVar23[unitIndex].level == 0 ||
                ((*(uint *)((uint)bStackY_20 * 0x27 + 0x121) & 0x200) != 0)))) {
              ovc22_usesGUnits(unitIndex,&uStackY_1c,outFlagSeg);
            }
            else if (((((bld_inst_t *)BldInstances + bStackY_20)->ofs != 0 ||
                       *(int *)((int)&BldInstances[0].seg + (uint)bStackY_20 * 0xc) != 0) ||
                     (*(char *)((uint)bStackY_20 * 0x27 + 0x11e) == '\x10')) &&
                    (uVar16 = ovc22_usesGOngoingBattle2
                                        (*(byte *)&puVar23[unitIndex].x,
                                         *(byte *)&puVar23[unitIndex].y), (char)uVar16 != '\0')) {
              _uStackY_1c = CONCAT11(bStackY_1b,1);
            }
          }
        }
      }
      unitIndex = unitIndex + 1;
      if (GUnitCount <= unitIndex) break;
      uVar14 = unitIndex * 9;
      uVar16 = (undefined2)((ulong)GUnits >> 0x10);
      puVar23 = (unit_t *)GUnits;
    }
    GGameState = 0x43;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    for (uVar24 = 0; (int)uVar24 < (int)(uint)GLeaderCount; uVar24 = uVar24 + 1) {
      if (*(char *)((int)*(undefined4 *)(uVar24 << 2) + 0x3d) != '\0') {
        *(undefined2 *)((int)*(undefined4 *)(uVar24 << 2) + 0xa2) = 0;
        cVar10 = *(char *)((int)*(undefined4 *)(uVar24 << 2) + 0x3f);
        if ((cVar10 == '\0') &&
           (*(uint *)((int)*(undefined4 *)(uVar24 << 2) + 0x4f) <
            *(uint *)((int)*(undefined4 *)(uVar24 << 2) + 0x4d) >> 1)) {
          bVar7 = true;
        }
        else {
          bVar7 = false;
        }
        uVar14 = *(uint *)((int)*(undefined4 *)(uVar24 << 2) + 0x54);
        uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
        iVar17 = (int)*(undefined4 *)(uVar24 << 2);
        iVar17 = *(int *)(iVar17 + 0x58) + ((int)uVar14 >> 0xf) +
                 (uint)CARRY2(*(uint *)(iVar17 + 0x56),uVar14);
        if ((iVar17 < 1) && (iVar17 < 0)) {
          for (uVar14 = 0xf8; uVar14 < GUnitCount; uVar14 = uVar14 + 1) {
            uVar16 = (undefined2)((ulong)GUnits >> 0x10);
            puVar23 = (unit_t *)GUnits;
            bStackY_20 = (puVar23 + uVar14)->bldType;
            if ((puVar23[uVar14].unitType == uVar24) &&
               (*(int *)((uint)bStackY_20 * 0x27 + 0x123) < 0)) {
              uVar11 = *(uint *)((uint)bStackY_20 * 0x27 + 0x123);
              uVar26 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
              iVar17 = (int)*(undefined4 *)(uVar24 << 2);
              iVar17 = *(int *)(iVar17 + 0x58) + ((int)uVar11 >> 0xf) +
                       (uint)CARRY2(*(uint *)(iVar17 + 0x56),uVar11);
              if ((iVar17 < 1) && (iVar17 < 0)) {
                if ((cVar10 == '\0') && (puVar23[uVar14].level != 0)) {
                  uVar33 = ovr_randBelow(100);
                  uVar16 = (undefined2)((ulong)GUnits >> 0x10);
                  puVar23 = (unit_t *)GUnits;
                  if (*(byte *)((uint)(puVar23 + uVar14)->bldType * 0x27 + 0x130) <= (byte)uVar33) {
                    if (puVar23[uVar14].level != 0) {
                      puVar23[uVar14].level = puVar23[uVar14].level - 1;
                    }
                    puVar23 = (unit_t *)GUnits;
                    uVar16 = (undefined2)((ulong)GUnits >> 0x10);
                    if (((*(uint *)((uint)bStackY_20 * 0x27 + 0x121) & 4) == 0) &&
                       ((puVar23[uVar14].level == 0 ||
                        ((*(uint *)((uint)bStackY_20 * 0x27 + 0x121) & 0x200) != 0)))) {
                      ovc22_usesGUnits(uVar14,&uStackY_1c,outFlagSeg);
                    }
                    else if (((((bld_inst_t *)BldInstances + bStackY_20)->ofs != 0 ||
                               *(int *)((int)&BldInstances[0].seg + (uint)bStackY_20 * 0xc) != 0) ||
                             (*(char *)((uint)bStackY_20 * 0x27 + 0x11e) == '\x10')) &&
                            (uVar16 = ovc22_usesGOngoingBattle2
                                                (*(byte *)&puVar23[uVar14].x,
                                                 *(byte *)&puVar23[uVar14].y), (char)uVar16 != '\0')
                            ) {
                      _uStackY_1c = CONCAT11(bStackY_1b,1);
                    }
                  }
                }
              }
              else {
                uVar30 = *(uint *)((uint)bStackY_20 * 0x27 + 0x123);
                uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
                iVar17 = (int)*(undefined4 *)(uVar24 << 2);
                puVar3 = (uint *)(iVar17 + 0x56);
                uVar11 = *puVar3;
                *puVar3 = *puVar3 + uVar30;
                piVar2 = (int *)(iVar17 + 0x58);
                *piVar2 = *piVar2 + ((int)uVar30 >> 0xf) + (uint)CARRY2(uVar11,uVar30);
              }
            }
          }
          uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
          iVar17 = (int)*(undefined4 *)(uVar24 << 2);
          *(undefined2 *)(iVar17 + 0x58) = 0;
          *(undefined2 *)(iVar17 + 0x56) = 0;
        }
        else {
          if ((cVar10 == '\0') && (0 < *(int *)((int)*(undefined4 *)(uVar24 << 2) + 0x54))) {
            uVar14 = *(int *)((int)*(undefined4 *)(uVar24 << 2) + 0x54) / 10;
          }
          else {
            uVar14 = 0;
          }
          bVar27 = CARRY2(GPopulationLo,uVar14);
          GPopulationLo = GPopulationLo + uVar14;
          GPopulationHi = GPopulationHi + ((int)uVar14 >> 0xf) + (uint)bVar27;
          uVar14 = *(int *)((int)*(undefined4 *)(uVar24 << 2) + 0x54) - uVar14;
          uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
          iVar17 = (int)*(undefined4 *)(uVar24 << 2);
          puVar3 = (uint *)(iVar17 + 0x56);
          uVar11 = *puVar3;
          *puVar3 = *puVar3 + uVar14;
          piVar2 = (int *)(iVar17 + 0x58);
          *piVar2 = *piVar2 + ((int)uVar14 >> 0xf) + (uint)CARRY2(uVar11,uVar14);
        }
        if ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                      (uint)*(byte *)((int)*(undefined4 *)(uVar24 << 2) + 0x3e) * 0x95) & 0x100) ==
            0) {
          if (*(uint *)((int)*(undefined4 *)(uVar24 << 2) + 0x4f) <
              *(uint *)((int)*(undefined4 *)(uVar24 << 2) + 0x4d)) {
            uVar14 = *(int *)((int)*(undefined4 *)(uVar24 << 2) + 0x4d) -
                     *(int *)((int)*(undefined4 *)(uVar24 << 2) + 0x4f);
            uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
            iVar20 = (int)*(undefined4 *)(uVar24 << 2);
            iVar17 = *(int *)(iVar20 + 0x62);
            if ((-1 < iVar17) && ((0 < iVar17 || (*(int *)(iVar20 + 0x60) != 0)))) {
              uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
              iVar17 = (int)*(undefined4 *)(uVar24 << 2);
              uVar11 = *(uint *)(iVar17 + 0x62);
              if ((0x7fff < uVar11) ||
                 ((uVar30 = uVar14, (int)uVar11 < 1 && (*(uint *)(iVar17 + 0x60) <= uVar14)))) {
                uVar30 = *(uint *)((int)*(undefined4 *)(uVar24 << 2) + 0x60);
              }
              uVar14 = uVar14 - uVar30;
              uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
              iVar17 = (int)*(undefined4 *)(uVar24 << 2);
              puVar3 = (uint *)(iVar17 + 0x60);
              uVar11 = *puVar3;
              *puVar3 = *puVar3 - uVar30;
              piVar2 = (int *)(iVar17 + 0x62);
              *piVar2 = *piVar2 - (uint)(uVar11 < uVar30);
            }
            if (uVar14 == 0) {
              uVar14 = 0;
            }
            else {
              uVar36 = (undefined1)uVar14;
              uVar38 = (undefined1)(uVar14 >> 8);
              if (*(uint *)((int)*(undefined4 *)(uVar24 << 2) + 0xa0) < uVar14) {
                uVar16 = *(undefined2 *)((int)*(undefined4 *)(uVar24 << 2) + 0xa0);
                uVar36 = (undefined1)uVar16;
                uVar38 = (undefined1)((uint)uVar16 >> 8);
              }
              uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
              iVar17 = (int)*(undefined4 *)(uVar24 << 2);
              uVar11 = *(uint *)(iVar17 + 0x58);
              if (((int)uVar11 < 1) &&
                 ((0x7fff < uVar11 || (*(uint *)(iVar17 + 0x56) < CONCAT11(uVar38,uVar36))))) {
                uVar16 = *(undefined2 *)((int)*(undefined4 *)(uVar24 << 2) + 0x56);
                uVar36 = (undefined1)uVar16;
                uVar38 = (undefined1)((uint)uVar16 >> 8);
              }
              uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
              iVar17 = (int)*(undefined4 *)(uVar24 << 2);
              puVar3 = (uint *)(iVar17 + 0x56);
              uVar11 = *puVar3;
              *puVar3 = *puVar3 - CONCAT11(uVar38,uVar36);
              piVar2 = (int *)(iVar17 + 0x58);
              *piVar2 = *piVar2 - (uint)(uVar11 < CONCAT11(uVar38,uVar36));
              uVar14 = uVar14 - CONCAT11(uVar38,uVar36);
              *(undefined2 *)((int)*(undefined4 *)(uVar24 << 2) + 0xa2) = CONCAT11(uVar38,uVar36);
            }
            if (cVar10 == '\0') {
              for (iVar17 = 0; (uVar14 != 0 && (iVar17 < (int)(uint)GLeaderCount));
                  iVar17 = iVar17 + 1) {
                if ((*(char *)((int)*(undefined4 *)(iVar17 << 2) + 0x3d) != '\0') &&
                   ((*(char *)((int)*(undefined4 *)(iVar17 << 2) + 0x3f) == '\0' &&
                    (uVar16 = (undefined2)((ulong)*(undefined4 *)(iVar17 << 2) >> 0x10),
                    iVar20 = (int)*(undefined4 *)(iVar17 << 2),
                    *(int *)(iVar20 + 0x60) != 0 || *(int *)(iVar20 + 0x62) != 0)))) {
                  uVar16 = (undefined2)((ulong)*(undefined4 *)(iVar17 << 2) >> 0x10);
                  iVar20 = (int)*(undefined4 *)(iVar17 << 2);
                  uVar11 = *(uint *)(iVar20 + 0x62);
                  if ((0x7fff < uVar11) ||
                     ((uVar30 = uVar14, (int)uVar11 < 1 && (*(uint *)(iVar20 + 0x60) <= uVar14)))) {
                    uVar30 = *(uint *)((int)*(undefined4 *)(iVar17 << 2) + 0x60);
                  }
                  uVar14 = uVar14 - uVar30;
                  uVar16 = (undefined2)((ulong)*(undefined4 *)(iVar17 << 2) >> 0x10);
                  iVar20 = (int)*(undefined4 *)(iVar17 << 2);
                  puVar3 = (uint *)(iVar20 + 0x60);
                  uVar11 = *puVar3;
                  *puVar3 = *puVar3 - uVar30;
                  piVar2 = (int *)(iVar20 + 0x62);
                  *piVar2 = *piVar2 - (uint)(uVar11 < uVar30);
                }
              }
            }
            uVar11 = 0;
            while ((uVar11 < EntityCount && (uVar14 != 0))) {
              uVar16 = (undefined2)((ulong)Entities >> 0x10);
              peVar21 = (entity_t *)Entities;
              if (((*(char *)((int)&peVar21[uVar11].base.entity + 1) == '\0') &&
                  (*(byte *)((int)&peVar21[uVar11].base.entity + 3) == uVar24)) &&
                 ((bVar7 || (1 < peVar21[uVar11].base.animFrame)))) {
                if (peVar21[uVar11].base.animFrame != 0x0) {
                  if (DebugVerbose != false) {
                    printf("kill 3\r");
                  }
                  puVar1 = &((entity_t *)Entities)[uVar11].base.animFrame;
                  *puVar1 = *puVar1 + 0xff;
                  if (((entity_t *)Entities)[uVar11].base.animFrame == 0x0) {
                    uStackY_1e = CONCAT11(1,(byte)uStackY_1e);
                  }
                }
                uVar14 = uVar14 - 1;
              }
              uVar11 = uVar11 + 1;
            }
          }
          else {
            uVar11 = *(int *)((int)*(undefined4 *)(uVar24 << 2) + 0x4f) -
                     *(int *)((int)*(undefined4 *)(uVar24 << 2) + 0x4d);
            uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
            iVar17 = (int)*(undefined4 *)(uVar24 << 2);
            puVar3 = (uint *)(iVar17 + 0x60);
            uVar14 = *puVar3;
            *puVar3 = *puVar3 + uVar11;
            piVar2 = (int *)(iVar17 + 0x62);
            *piVar2 = *piVar2 + (uint)CARRY2(uVar14,uVar11);
          }
        }
        uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
        iVar18 = (int)*(undefined4 *)(uVar24 << 2);
        iVar17 = *(int *)(iVar18 + 0x62);
        uVar26 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
        iVar19 = (int)*(undefined4 *)(uVar24 << 2);
        iVar20 = *(int *)(iVar19 + 0x80);
        if ((iVar20 <= iVar17) &&
           ((iVar20 < iVar17 || (*(uint *)(iVar19 + 0x7e) < *(uint *)(iVar18 + 0x60))))) {
          uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
          iVar17 = (int)*(undefined4 *)(uVar24 << 2);
          uVar14 = *(uint *)(iVar17 + 0x60);
          uVar26 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
          iVar20 = (int)*(undefined4 *)(uVar24 << 2);
          puVar3 = (uint *)(iVar20 + 0x7e);
          uVar11 = (uint)(uVar14 < *puVar3);
          uVar30 = *(int *)(iVar17 + 0x62) - *(int *)(iVar20 + 0x80);
          if (((int)(uVar30 - uVar11) < 0) ||
             ((uVar30 == uVar11 &&
              (uVar14 - *puVar3 <= *(uint *)((int)*(undefined4 *)(uVar24 << 2) + 0xa0))))) {
            uVar14 = *(int *)((int)*(undefined4 *)(uVar24 << 2) + 0x60) -
                     *(int *)((int)*(undefined4 *)(uVar24 << 2) + 0x7e);
          }
          else {
            uVar14 = *(uint *)((int)*(undefined4 *)(uVar24 << 2) + 0xa0);
          }
          *(int *)((int)*(undefined4 *)(uVar24 << 2) + 0xa2) = -uVar14;
          uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
          iVar17 = (int)*(undefined4 *)(uVar24 << 2);
          puVar3 = (uint *)(iVar17 + 0x56);
          uVar11 = *puVar3;
          *puVar3 = *puVar3 + uVar14;
          piVar2 = (int *)(iVar17 + 0x58);
          *piVar2 = *piVar2 + (uint)CARRY2(uVar11,uVar14);
          uVar26 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
          iVar17 = (int)*(undefined4 *)(uVar24 << 2);
          uVar16 = *(undefined2 *)(iVar17 + 0x7e);
          uVar25 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
          iVar20 = (int)*(undefined4 *)(uVar24 << 2);
          *(undefined2 *)(iVar20 + 0x62) = *(undefined2 *)(iVar17 + 0x80);
          *(undefined2 *)(iVar20 + 0x60) = uVar16;
        }
        if ((*(uint *)((int)*(undefined4 *)(uVar24 << 2) + 0x5b) <
             *(uint *)((int)*(undefined4 *)(uVar24 << 2) + 0x4d)) &&
           ((*(uint *)((int)&worldMenuLabels[6].seg + 1 +
                      (uint)*(byte *)((int)*(undefined4 *)(uVar24 << 2) + 0x3e) * 0x95) & 0x80) == 0
           )) {
          iVar17 = *(int *)((int)*(undefined4 *)(uVar24 << 2) + 0x4d) -
                   *(int *)((int)*(undefined4 *)(uVar24 << 2) + 0x5b);
          uVar14 = 0;
          while ((uVar14 < EntityCount && (iVar17 != 0))) {
            uVar16 = (undefined2)((ulong)Entities >> 0x10);
            peVar21 = (entity_t *)Entities;
            if ((*(byte *)((int)&peVar21[uVar14].base.entity + 3) == uVar24) &&
               ((((*(char *)((int)&peVar21[uVar14].base.entity + 1) == '\0' &&
                  (peVar21[uVar14].base.destX == 0)) && (peVar21[uVar14].base.destY == 0)) &&
                (3 < peVar21[uVar14].base.animFrame)))) {
              if (DebugVerbose != false) {
                printf("kill 2 \r");
              }
              puVar1 = &((entity_t *)Entities)[uVar14].base.animFrame;
              *puVar1 = *puVar1 + 0xff;
              iVar17 = iVar17 + -1;
            }
            uVar14 = uVar14 + 1;
          }
        }
        ovr_ovc25_tickCountdown(uVar24);
        _fmemset((void *)(*(int *)(uVar24 * 4) + 0x6a),((int *)(uVar24 * 4))[1],0);
        _fmemset((void *)(*(int *)(uVar24 * 4) + 0x76),((int *)(uVar24 * 4))[1],0);
        uVar33 = ovr_randBelow(100);
        if ((byte)uVar33 < *(byte *)((int)*(undefined4 *)(uVar24 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uVar24 << 2) + 0x6c) =
               *(undefined2 *)((int)*(undefined4 *)(uVar24 << 2) + 100);
        }
        else {
          *(undefined2 *)((int)*(undefined4 *)(uVar24 << 2) + 0x6a) =
               *(undefined2 *)((int)*(undefined4 *)(uVar24 << 2) + 100);
        }
        uVar33 = ovr_randBelow(100);
        if ((byte)uVar33 < *(byte *)((int)*(undefined4 *)(uVar24 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uVar24 << 2) + 0x6e) =
               *(undefined2 *)((int)*(undefined4 *)(uVar24 << 2) + 0x66);
        }
        else {
          piVar2 = (int *)((int)*(undefined4 *)(uVar24 << 2) + 0x6c);
          *piVar2 = *piVar2 + *(int *)((int)*(undefined4 *)(uVar24 << 2) + 0x66);
        }
        piVar2 = (int *)((int)*(undefined4 *)(uVar24 << 2) + 0x6e);
        *piVar2 = *piVar2 + *(int *)((int)*(undefined4 *)(uVar24 << 2) + 0x68);
        uVar33 = ovr_randBelow(100);
        if ((byte)uVar33 < *(byte *)((int)*(undefined4 *)(uVar24 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uVar24 << 2) + 0x78) =
               *(undefined2 *)((int)*(undefined4 *)(uVar24 << 2) + 0x70);
        }
        else {
          *(undefined2 *)((int)*(undefined4 *)(uVar24 << 2) + 0x76) =
               *(undefined2 *)((int)*(undefined4 *)(uVar24 << 2) + 0x70);
        }
        uVar33 = ovr_randBelow(100);
        if ((byte)uVar33 < *(byte *)((int)*(undefined4 *)(uVar24 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uVar24 << 2) + 0x7a) =
               *(undefined2 *)((int)*(undefined4 *)(uVar24 << 2) + 0x72);
        }
        else {
          piVar2 = (int *)((int)*(undefined4 *)(uVar24 << 2) + 0x78);
          *piVar2 = *piVar2 + *(int *)((int)*(undefined4 *)(uVar24 << 2) + 0x72);
        }
        uVar33 = ovr_randBelow(100);
        if ((byte)uVar33 < *(byte *)((int)*(undefined4 *)(uVar24 << 2) + 0xa9)) {
          *(undefined2 *)((int)*(undefined4 *)(uVar24 << 2) + 0x7c) =
               *(undefined2 *)((int)*(undefined4 *)(uVar24 << 2) + 0x74);
        }
        else {
          piVar2 = (int *)((int)*(undefined4 *)(uVar24 << 2) + 0x7a);
          *piVar2 = *piVar2 + *(int *)((int)*(undefined4 *)(uVar24 << 2) + 0x74);
        }
        *(undefined1 *)((int)*(undefined4 *)(uVar24 << 2) + 0xa7) =
             *(undefined1 *)((int)*(undefined4 *)(uVar24 << 2) + 0xa6);
        if (*(char *)((int)*(undefined4 *)(uVar24 << 2) + 0x3f) != '\0') {
          uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
          iVar20 = (int)*(undefined4 *)(uVar24 << 2);
          iVar17 = *(int *)(iVar20 + 0x58);
          if ((iVar17 < 1) && ((iVar17 != 0 || (*(int *)(iVar20 + 0x56) == 0)))) {
            uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
            iVar17 = (int)*(undefined4 *)(uVar24 << 2);
            *(undefined2 *)(iVar17 + 0x58) = 0;
            *(undefined2 *)(iVar17 + 0x56) = 0x32;
          }
        }
        if (*(char *)((int)*(undefined4 *)(uVar24 << 2) + 0xaa) != '\0') {
          in_stack_0000fffc = (uint)*(byte *)((int)*(undefined4 *)(uVar24 << 2) + 0xaa);
          for (uVar14 = 0; (int)uVar14 < (int)(uint)GLeaderCount; uVar14 = uVar14 + 1) {
            uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
            iVar18 = (int)*(undefined4 *)(uVar24 << 2);
            iVar17 = *(int *)(iVar18 + 0x58);
            uVar26 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
            iVar19 = (int)*(undefined4 *)(uVar24 << 2);
            iVar20 = *(int *)(iVar19 + 0x8c);
            if ((iVar20 <= iVar17) &&
               ((iVar17 != iVar20 || (*(uint *)(iVar19 + 0x8a) <= *(uint *)(iVar18 + 0x56)))))
            break;
            if ((*(char *)((int)*(undefined4 *)(uVar14 << 2) + 0x3d) != '\0') &&
               (((0 < *(int *)((int)*(undefined4 *)(uVar14 << 2) + 0x54) &&
                 (*(char *)((int)*(undefined4 *)(uVar14 << 2) + 0x3f) == '\0')) &&
                (uVar14 != uVar24)))) {
              uStackY_2e = (uint)(((long)*(int *)((int)*(undefined4 *)(uVar14 << 2) + 0x54) *
                                   (long)(int)in_stack_0000fffc & 0xffffU) / 100);
              iStackY_2c = 0;
              uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
              iVar17 = (int)*(undefined4 *)(uVar24 << 2);
              uVar11 = *(uint *)(iVar17 + 0x8a);
              uVar26 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
              iVar20 = (int)*(undefined4 *)(uVar24 << 2);
              puVar3 = (uint *)(iVar20 + 0x56);
              iVar17 = (*(int *)(iVar17 + 0x8c) - *(int *)(iVar20 + 0x58)) -
                       (uint)(uVar11 < *puVar3);
              if ((iVar17 < 1) && ((iVar17 < 0 || (uVar11 - *puVar3 < uStackY_2e)))) {
                uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
                iVar17 = (int)*(undefined4 *)(uVar24 << 2);
                uVar11 = *(uint *)(iVar17 + 0x8a);
                uVar26 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
                iVar20 = (int)*(undefined4 *)(uVar24 << 2);
                puVar3 = (uint *)(iVar20 + 0x56);
                uStackY_2e = uVar11 - *puVar3;
                iStackY_2c = (*(int *)(iVar17 + 0x8c) - *(int *)(iVar20 + 0x58)) -
                             (uint)(uVar11 < *puVar3);
              }
              uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar14 << 2) >> 0x10);
              iVar20 = (int)*(undefined4 *)(uVar14 << 2);
              iVar17 = *(int *)(iVar20 + 0x58);
              if ((iVar17 <= iStackY_2c) &&
                 ((iVar17 < iStackY_2c || (*(uint *)(iVar20 + 0x56) < uStackY_2e)))) {
                uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar14 << 2) >> 0x10);
                iVar17 = (int)*(undefined4 *)(uVar14 << 2);
                iStackY_2c = *(int *)(iVar17 + 0x58);
                uStackY_2e = *(uint *)(iVar17 + 0x56);
              }
              uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
              iVar17 = (int)*(undefined4 *)(uVar24 << 2);
              puVar3 = (uint *)(iVar17 + 0x56);
              uVar11 = *puVar3;
              *puVar3 = *puVar3 + uStackY_2e;
              piVar2 = (int *)(iVar17 + 0x58);
              *piVar2 = *piVar2 + iStackY_2c + (uint)CARRY2(uVar11,uStackY_2e);
              uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar14 << 2) >> 0x10);
              iVar17 = (int)*(undefined4 *)(uVar14 << 2);
              puVar3 = (uint *)(iVar17 + 0x56);
              uVar11 = *puVar3;
              *puVar3 = *puVar3 - uStackY_2e;
              piVar2 = (int *)(iVar17 + 0x58);
              *piVar2 = (*piVar2 - iStackY_2c) - (uint)(uVar11 < uStackY_2e);
            }
          }
        }
        iVar17 = *(int *)((int)*(undefined4 *)(uVar24 << 2) + 0x58);
        if ((iVar17 < 1) && (iVar17 < 0)) {
          uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
          iVar17 = (int)*(undefined4 *)(uVar24 << 2);
          *(undefined2 *)(iVar17 + 0x58) = 0;
          *(undefined2 *)(iVar17 + 0x56) = 0;
        }
        uVar16 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
        iVar18 = (int)*(undefined4 *)(uVar24 << 2);
        iVar17 = *(int *)(iVar18 + 0x58);
        uVar26 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
        iVar19 = (int)*(undefined4 *)(uVar24 << 2);
        iVar20 = *(int *)(iVar19 + 0x8c);
        if ((iVar20 <= iVar17) &&
           ((iVar20 < iVar17 || (*(uint *)(iVar19 + 0x8a) < *(uint *)(iVar18 + 0x56))))) {
          uVar26 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
          iVar17 = (int)*(undefined4 *)(uVar24 << 2);
          uVar16 = *(undefined2 *)(iVar17 + 0x8a);
          uVar25 = (undefined2)((ulong)*(undefined4 *)(uVar24 << 2) >> 0x10);
          iVar20 = (int)*(undefined4 *)(uVar24 << 2);
          *(undefined2 *)(iVar20 + 0x58) = *(undefined2 *)(iVar17 + 0x8c);
          *(undefined2 *)(iVar20 + 0x56) = uVar16;
        }
      }
    }
    GGameState = 0x40;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    for (uVar24 = 0xf8; uVar24 < GUnitCount; uVar24 = uVar24 + 1) {
      uVar16 = (undefined2)((ulong)GUnits >> 0x10);
      puVar23 = (unit_t *)GUnits;
      if ((*(uint *)((uint)(puVar23 + uVar24)->bldType * 0x27 + 0x121) & 0x40) != 0) {
        if (puVar23[uVar24].timer != 0) {
          puVar23[uVar24].timer = puVar23[uVar24].timer - 1;
        }
        uVar16 = (undefined2)((ulong)GUnits >> 0x10);
        if (((unit_t *)GUnits)[uVar24].timer == 0) {
          uVar6 = *(undefined4 *)((uint)((unit_t *)GUnits)[uVar24].unitType << 2);
          if (*(char *)((int)uVar6 + 0x3f) == '\0') {
            ovr_play_sfx(81,0);
            ovr_alignUp4(((unit_t *)GUnits)[uVar24].x);
            msg = ovr_fmVsprintf((char *)"Mine exhausted at (%d, %d).",(char *)"puppetmaker" + 3);
            ovr_say(msg);
            ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x24));
          }
          ovc22_usesGUnits(uVar24,&uStackY_1c,outFlagSeg);
        }
      }
    }
    GGameState = 0x42;
    if (DebugVerbose == false) goto L_upd_units_5087_1d7d_323A;
    break;
  case 2:
    if (in_CX != 1 && uVar14 != 0) goto code_r0x00053afb;
    break;
  case 3:
    puVar3 = (uint *)(&puVar23->bldType + unitIndex);
    *puVar3 = *puVar3 >> 7 | *puVar3 << 9;
    *(uint *)(&puVar23->timer +
             (int)((char *)"%s: Costs %d gold of income and provides storage for %u food." + x)) =
         *(uint *)(&puVar23->timer +
                  (int)((char *)"%s: Costs %d gold of income and provides storage for %u food." + x)
                  ) | (uint)&stack0xfff8;
    *(uint *)(&puVar23[1].bldType + x) = *(uint *)(&puVar23[1].bldType + x) | (uint)&stack0xfffe;
    AgntAnms[0x7d].x = AgntAnms[0x7d].x | (uint)&stack0xfff8;
    *(uint *)unitIndex = *(uint *)unitIndex | uVar14;
    (&stack0x8d06)[unitIndex] = (&stack0x8d06)[unitIndex];
    *(byte *)(x + 8) = *(byte *)(x + 8) | (byte)((uint)iVar17 >> 8);
    (&stack0xfffe)[x] = (&stack0xfffe)[x] | (byte)((uint)&puVar23->level >> 8);
    pbVar4 = &puVar23->level + unitIndex;
    *pbVar4 = *pbVar4 | (byte)in_CX | (byte)x;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  printf((char *)CONCAT13(uVar15,CONCAT12(uVar28,unaff_DI)));
L_upd_units_5087_1d7d_323A:
  ovr_driver_clearMapFlagsRect((uint32_t)GMapFlags,0,0,0x93,0x3b,0xfff7);
  uVar14 = 0;
  while (uVar14 < SquareRecCount) {
    uVar16 = (undefined2)((ulong)GMapFlags >> 0x10);
    puVar23 = (unit_t *)(*(short (*) [60] [148])GMapFlags + *(int *)(uVar14 * 0x13 + 2));
    uVar24 = uVar14;
code_r0x00053afb:
    *(uint *)(&puVar23->bldType + *(int *)(uVar14 * 0x13) * 2) =
         *(uint *)(&puVar23->bldType + *(int *)(uVar14 * 0x13) * 2) | 8;
    uVar14 = uVar24 + 1;
  }
  if (EntityCount <= EntityScanPos) {
    EntityScanPos = 0;
    for (iVar17 = 0; iVar17 < (int)(uint)GLeaderCount; iVar17 = iVar17 + 1) {
      if (*(char *)((int)*(undefined4 *)(iVar17 << 2) + 0x3d) != '\0') {
        iVar20 = ((int *)(iVar17 * 4))[1];
        uVar28 = 0x95;
        uVar15 = 0x3b;
        memcpy((char *)CONCAT22(((int *)(iVar17 * 4))[1],(char *)(*(int *)(iVar17 * 4) + 0x8e)),
               (char *)CONCAT13((char)((uint)iVar20 >> 8),
                                CONCAT12((char)iVar20,*(int *)(iVar17 * 4) + 0x94)),3);
        iVar17 = CONCAT11(uVar15,uVar28);
      }
    }
  }
  uVar33 = 0;
  uVar16 = 0x2356;
  bVar9 = ovr_manage_findFirstLeader();
  uVar24 = EntityScanPos;
  if ((bVar9 == 0xff) || (GCanPromote == '\0')) {
    pbVar12 = (byte *)0x0;
  }
  else if (*(byte *)((int)*(undefined4 *)((uint)bVar9 << 2) + 0x86) < 5) {
    pbVar12 = (byte *)__C0_ASM_CopyRight + 0x24;
  }
  else {
    pbVar12 = (byte *)((uint)*(byte *)((int)*(undefined4 *)((uint)bVar9 << 2) + 0x86) * 4 + 0x14);
  }
  for (; uVar24 < EntityCount; uVar24 = uVar24 + 1) {
    uVar26 = (undefined2)((ulong)Entities >> 0x10);
    peVar21 = (entity_t *)Entities;
    if (((*(char *)((int)&peVar21[uVar24].base.entity + 1) == '\0') &&
        (peVar21[uVar24].base.destX == 0)) && (peVar21[uVar24].base.destY == 0)) {
      bVar39 = peVar21[uVar24].base.gindex;
      cVar10 = *(char *)((int)(char **)GMenuStrings + (uint)bVar39 * 0x95 + 0x1f);
      bVar5 = *(byte *)((int)&peVar21[uVar24].base.entity + 3);
      bVar27 = false;
      bVar8 = false;
      bVar7 = false;
      if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar39 * 0x95) == -1) {
        bVar27 = true;
      }
      else {
        bVar29 = *(byte *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x89);
        _uStackY_1c = CONCAT11(bVar29,uStackY_1c);
        if (bVar29 < 5) {
          uVar33 = peVar21[uVar24].base.y;
          uVar16 = 0x2379;
          uVar14 = ovr_alignUp4(((peVar21 + uVar24)->base).x);
          uVar13 = 0x2410;
          if (((*(short (*) [60] [148])GMapFlags)[uVar33][uVar14] & 8U) == 0) {
            uStackY_1e = CONCAT11((*(uint8_t *)((uint8_t *)&(uStackY_1e) + 1)),0x22);
            bStackY_1f = 0x21;
            bStackY_20 = 0x22;
          }
          else {
            puVar35 = &uStackY_1e;
            pbVar12 = &bStackY_1f;
            pbVar31 = &bStackY_20;
            bVar29 = bStackY_1b;
            uVar15 = (undefined1)((uint)pbVar31 >> 8);
            _uStackY_1c = 0x2379;
            uStackY_1e = 0x3d98;
            uVar32 = unaff_SS;
            uVar34 = unaff_SS;
            uVar37 = outFlagSeg;
            uVar28 = (char)(unaff_SS >> 8);
            uVar33 = ovr_attact_usesSquareRecCount(uVar33,uVar33);
            table.seg = uVar13;
            table.ofs = uVar33;
            _uStackY_1c = 0x2315;
            uVar16 = 0x2315;
            uStackY_1e = 0x3da2;
            pctOut.seg = uVar32;
            pctOut.ofs = (uint16_t)pbVar31;
            remainderOut.seg = uVar34;
            remainderOut.ofs = (uint16_t)pbVar12;
            (*(uint8_t *)((uint8_t *)&(partOut.seg))) = uVar37;
            partOut.ofs = (uint16_t)puVar35;
            (*(uint8_t *)((uint8_t *)&(partOut.seg) + 1)) = uVar28;
            ovr_attact_compute3_2(table,CONCAT11(uVar15,bVar29),pctOut,remainderOut,partOut);
            uVar24 = CONCAT11(uVar15,bVar29);
          }
        }
        else {
          uStackY_1e = CONCAT11((*(uint8_t *)((uint8_t *)&(uStackY_1e) + 1)),0x22);
          bStackY_1f = 0x21;
          bStackY_20 = 0x22;
        }
        uVar28 = (undefined1)uVar16;
        uVar15 = (undefined1)((uint)uVar16 >> 8);
        uVar16 = 0x2337;
        uVar33 = 0x3dca;
        uVar13 = ovr_randBelow(100);
        pbVar12 = (byte *)CONCAT11(uVar15,uVar28);
        if ((byte)uVar13 < (byte)uStackY_1e) {
          bVar27 = true;
          pbVar12 = (byte *)CONCAT11(uVar15,uVar28);
        }
        else if ((uVar13 & 0xff) < (uint)bStackY_1f + (uStackY_1e & 0xff)) {
          bVar8 = true;
          pbVar12 = (byte *)CONCAT11(uVar15,uVar28);
        }
        else {
          bVar7 = true;
        }
      }
      if (bVar7) {
        uVar16 = (undefined2)((ulong)Entities >> 0x10);
        uVar13 = ((entity_t *)Entities)[uVar24].base.y;
        uVar28 = (undefined1)uVar13;
        uVar15 = (undefined1)(uVar13 >> 8);
        uVar33 = (((entity_t *)Entities + uVar24)->base).x;
        uVar16 = 0x236f;
        cVar10 = ovr_ovc23_tickRecordsAt(uVar33,uVar13,cVar10);
        pbVar12 = (byte *)CONCAT11(uVar15,uVar28);
        if (cVar10 == '\0') {
          if ((bStackY_1f == 0) && ((byte)uStackY_1e == '\0')) {
            uVar28 = 0x6f;
            uVar15 = 0x23;
            uVar16 = 0x2337;
            uVar33 = 0x3e5d;
            uVar13 = ovr_randBelow(2);
            if ((uVar13 & 0xff) == 0) {
              bVar27 = true;
              pbVar12 = (byte *)CONCAT11(uVar15,uVar28);
            }
            else {
              bVar8 = true;
              pbVar12 = (byte *)CONCAT11(uVar15,uVar28);
            }
          }
          else {
            uVar28 = 0x6f;
            uVar15 = 0x23;
            uVar16 = 0x2337;
            uVar33 = 0x3e86;
            uVar13 = ovr_randBelow((uint)bStackY_1f + (uStackY_1e & 0xff));
            pbVar12 = (byte *)CONCAT11(uVar15,uVar28);
            if ((byte)uVar13 < (byte)uStackY_1e) {
              bVar27 = true;
              pbVar12 = (byte *)CONCAT11(uVar15,uVar28);
            }
            else {
              bVar8 = true;
            }
          }
        }
      }
      uVar28 = (undefined1)uVar16;
      uVar15 = (undefined1)((uint)uVar16 >> 8);
      if (bVar27) {
        uVar33 = 0x3ea5;
        uVar14 = ovc22_usesEntities(uVar24);
        pbVar12 = (byte *)CONCAT11(uVar15,uVar28);
        if ((uVar14 & 0xff) == 0) {
          bVar8 = true;
          pbVar12 = (byte *)CONCAT11(uVar15,uVar28);
        }
      }
      if (bVar8) {
        if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar39 * 0x95) != -1) &&
           (bVar5 != 0xff)) {
          if ((*(char *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x3f) != '\0') ||
             (((entity_t *)Entities)[uVar24].base.level <
              *(byte *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x53))) {
            ovc22_usesLUDIV_at_((entity_t *)
                                CONCAT13((char)((ulong)Entities >> 0x18),
                                         CONCAT12((char)((ulong)Entities >> 0x10),
                                                  (entity_t *)Entities + uVar24)));
            LXMUL_at_((long *)pbVar12,CONCAT22(in_stack_0000fffc,CONCAT11(bVar9,bVar39)),
                      CONCAT22(in_stack_00000000,unaff_BP));
            peVar21 = (entity_t *)Entities + uVar24;
            uVar28 = 0x89;
            uVar15 = 0x3f;
            uVar33 = ovr_ovc15_textError();
            uVar14 = ovc22_usesLUDIV_at_2(uVar33,(uint16_t)peVar21,(int)pbVar12);
            uVar16 = (undefined2)((ulong)Entities >> 0x10);
            peVar22 = (entity_t *)Entities;
            uVar24 = *(uint *)&peVar22[CONCAT11(uVar15,uVar28)].base.health;
            *(uint *)&peVar22[CONCAT11(uVar15,uVar28)].base.frameIndex =
                 (int)&(peVar21->base).x +
                 (uint)CARRY2(uVar24,uVar14) +
                 *(int *)&peVar22[CONCAT11(uVar15,uVar28)].base.frameIndex;
            *(uint *)&peVar22[CONCAT11(uVar15,uVar28)].base.health = uVar24 + uVar14;
            uVar16 = 0x23d5;
            ovr_ovc41_compute3(CONCAT13((char)((ulong)Entities >> 0x18),
                                        CONCAT12((char)((ulong)Entities >> 0x10),
                                                 (entity_t *)Entities + CONCAT11(uVar15,uVar28))));
            uVar24 = CONCAT11(uVar15,uVar28);
          }
        }
        ovc22_usesEntities2(uVar24);
        ovc22_usesEntities3(uVar24);
        uVar28 = (undefined1)uVar16;
        uVar15 = (undefined1)((uint)uVar16 >> 8);
        uVar33 = 0x4016;
        ovc22_usesEntities4(uVar24);
        pbVar12 = (byte *)CONCAT11(uVar15,uVar28);
      }
      iStackY_2a = (uint)((entity_t *)Entities)[uVar24].base.animFrame -
                   (uint)*(byte *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0xa4);
      if (0 < iStackY_2a) {
        if (3 < iStackY_2a) {
          iStackY_2a = 3;
        }
        if (iStackY_2a == 3) {
          if (*(int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x92) == 0) {
            iStackY_2a = 2;
          }
          else {
            piVar2 = (int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x92);
            *piVar2 = *piVar2 + -1;
          }
        }
        if (iStackY_2a == 2) {
          if (*(int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x90) == 0) {
            iStackY_2a = 1;
          }
          else {
            piVar2 = (int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x90);
            *piVar2 = *piVar2 + -1;
          }
        }
        if (iStackY_2a == 1) {
          if (*(int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x8e) == 0) {
            iStackY_2a = 0;
          }
          else {
            piVar2 = (int *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0x8e);
            *piVar2 = *piVar2 + -1;
          }
        }
        ((entity_t *)Entities)[uVar24].base.animFrame =
             *(char *)((int)*(undefined4 *)((uint)bVar5 << 2) + 0xa4) + (char)iStackY_2a;
      }
      uVar33 = uVar33 + 1;
      if (199 < (int)uVar33) break;
    }
  }
  EntityScanPos = uVar24;
  mapDirty = 1;
  ovr_unit_usesAlignUp4();
  GGameState = 0x44;
  msg_00 = (uint *)((char *)"puppetmaker" + 3);
  if (DebugVerbose != false) {
    msg_00 = (uint *)((char *)"puppetmaker" + 3);
    printf("%d \r");
  }
  if ((*(uint8_t *)((uint8_t *)&(uStackY_1e) + 1)) != '\0') {
    msg_00 = (uint *)(EntityCount - 1);
    for (entityIndex = msg_00; -1 < (int)entityIndex; entityIndex = (uint *)((int)entityIndex - 1))
    {
      uVar16 = (undefined2)((ulong)Entities >> 0x10);
      peVar21 = (entity_t *)Entities;
      msg_00 = (uint *)(uint)peVar21[(int)entityIndex].base.animFrame;
      if (msg_00 == (uint *)0x0) {
        msg_00 = (uint *)(uint)*(byte *)((int)(char **)GMenuStrings +
                                        (uint)peVar21[(int)entityIndex].base.gindex * 0x95 + 0x1f);
        if (msg_00 == (uint *)0x0) {
          ovr_alignUp4(((peVar21 + (int)entityIndex)->base).x);
          uVar33 = 0x195d;
          uVar28 = 0x12;
          uVar15 = 0x56;
          msg_00 = (uint *)ovr_fmVsprintf((char *)
                                          "Intelligence reports %s unit died of starvation. (%d, %d)"
                                          ,(char *)"puppetmaker" + 3);
          ovr_uiNotify((char *)msg_00,uVar33);
          entityIndex = (uint *)CONCAT11(uVar15,uVar28);
        }
        ovr_ovc15_removeEntity((uint)entityIndex);
      }
    }
  }
  if (uStackY_1c != 0x0) {
    ovr_constr_flushDirtyRects();
  }
  return msg_00;
}



/* 55fe:0cdf */

/* WARNING: Instruction at (ram,0x00056a00) overlaps instruction at (ram,0x000569fe)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* [R2] string "Construction abandoned." */

char * __cdecl16far ovc23_textConstructionAbandoned(char *ofs,uint8_t *seg,byte dir)

{
  int *piVar1;
  uint *puVar2;
  byte *pbVar3;
  byte bVar4;
  uint8_t *puVar6;
  uint8_t uVar7;
  uint16_t play_id;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  undefined2 uVar11;
  byte bVar12;
  byte bVar13;
  byte bVar14;
  byte bVar20;
  undefined1 extraout_AH;
  int iVar15;
  char *pcVar16;
  uint uVar17;
  undefined4 *puVar18;
  byte *pbVar19;
  undefined1 *in_CX;
  byte bVar21;
  byte bVar22;
  byte bVar24;
  char *pcVar23;
  uint *puVar25;
  uint *puVar26;
  int iVar27;
  uint *puVar29;
  undefined2 *puVar30;
  undefined2 *puVar31;
  undefined2 unaff_BP;
  uint uVar32;
  uint unaff_SI;
  uint uVar33;
  uint8_t *puVar34;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 uVar35;
  bool bVar36;
  bool bVar37;
  bool bVar38;
  byte in_AF;
  bool bVar39;
  bool bVar40;
  bool bVar41;
  far_t dst;
  uint8_t *in_stack_00000000;
  ulong uVar42;
  char cVar43;
  agnt_t *paVar44;
  agnt_t *in_stack_0000fffc;
  agnt_t *agnt;
  byte bVar5;
  byte bVar28;
  
  puVar34 = seg;
  pcVar16 = ofs;
  agnt = (agnt_t *)CONCAT22(unaff_BP,in_stack_0000fffc);
  pcVar23 = ofs + *(char *)(dir + 0x885);
  uVar42 = CONCAT22(pcVar23,0x55fe);
  uVar17 = ovr_attact_usesGUnits((int)pcVar23,(int)(seg + *(char *)(dir + 0x889)));
  if (((uVar17 & 0xff) != 0) &&
     (puVar18 = (undefined4 *)(uint)dir, puVar18 <= (undefined4 *)((int)(undefined4 *)&_DATA + 3)))
  {
    iVar27 = (int)puVar18 * 2;
    switch(puVar18) {
    case (undefined4 *)0x0:
      (**(code **)(pcVar16 + iVar27 + -0x70))();
      break;
    case (undefined4 *)0x2:
      uVar17 = 0x1000 << (*(byte *)((int)*puVar18 + 0x3f) & 0x1f);
      uVar10 = *(undefined4 *)((uint)(byte)(uVar42 >> 0x10) << 2);
      uVar32 = 0x1000 << ((*(byte *)((int)uVar10 + 0x3f) ^ 1) & 0x1f);
      uVar33 = 0;
      uVar42 = uVar42 & 0xffffff;
      while( true ) {
        bVar21 = (byte)(uVar42 >> 0x18);
        if (3 < bVar21) break;
        iVar27 = (int)&((agnt_t *)agnt)->x + (uint)bVar21;
        uVar32 = iVar27 * 2;
        uVar33 = uVar33 | ((short (*) [60] [148])GMapFlags)[-1][unaff_SI + 0x3b][iVar27 + 0x92] &
                          0x3000U;
        uVar42 = CONCAT13(bVar21 + 1,(int3)uVar42);
      }
      if ((((*(byte *)((int)pcVar16 * 0x12 + 0xd) & 3) == 1) && (uVar33 == uVar32)) &&
         (uVar10 = *(undefined4 *)((uint)(byte)(uVar42 >> 0x10) << 2),
         pcVar23 = ovr_ovc24_textArena((uint16_t)(agnt_t *)agnt,unaff_SI,
                                       *(char *)((int)uVar10 + 0x3f)), ((uint)pcVar23 & 0xff) == 0))
      {
        uVar35 = ovc23_isCursorAt((uint16_t)(agnt_t *)agnt,unaff_SI);
        if ((char)uVar35 != '\0') {
          ovr_say((char *)"Construction abandoned.");
        }
        if (pcVar16 + 1 < GRecordCount) {
          _fmemmove((char *)CONCAT22(0x21f2,(char *)((int)pcVar16 * 0x12)),
                    (char *)CONCAT22(0x21f2,(char *)((int)pcVar16 * 0x12 + 0x12)),
                    (int)(GRecordCount + (-1 - (int)pcVar16)) * 0x12);
        }
        GRecordCount = GRecordCount + -1;
        pbVar19 = ovc23_textAdlibNone(uVar17,unaff_SI,agnt);
      }
      else {
        bVar21 = *(byte *)((int)pcVar16 * 0x12 + 0xd);
        pbVar19 = (byte *)(uint)bVar21;
        if (((bVar21 & 1) == 0) && ((uVar17 & uVar33) != 0)) {
          pbVar19 = (byte *)((int)pcVar16 * 0x12);
          pbVar19[0xd] = pbVar19[0xd] | 1;
        }
      }
      return (char *)pbVar19;
    case (undefined4 *)0x3:
      pcVar23 = pcVar23 + -1;
      bVar22 = (byte)iVar27;
      bVar14 = bVar22 - AgntAnms[0xf].frmid;
      bVar12 = (byte)((uint)iVar27 >> 8);
      bVar21 = bVar12 - dir;
      bVar28 = bVar21 - (bVar22 < AgntAnms[0xf].frmid);
      puVar25 = (uint *)CONCAT11(bVar28,bVar14);
      puVar8 = (undefined1 *)(uint)(bVar12 < dir || bVar21 < (bVar22 < AgntAnms[0xf].frmid));
      puVar30 = (undefined2 *)(&stack0xfffe + -(int)in_CX + -(int)puVar8);
      puVar2 = (uint *)(puVar34 + -0x57e7);
      uVar32 = (uint)(&stack0xfffe < in_CX || &stack0xfffe + -(int)in_CX < puVar8);
      puVar31 = (undefined2 *)*puVar2;
      uVar17 = *puVar2;
      *puVar2 = (uVar17 - (int)puVar30) - uVar32;
      puVar2 = (uint *)((int)puVar30 + 0x7419);
      uVar32 = (uint)(puVar31 < puVar30 || uVar17 - (int)puVar30 < uVar32);
      puVar8 = (undefined1 *)*puVar2;
      uVar17 = *puVar2;
      *puVar2 = (uVar17 - (int)in_CX) - uVar32;
      puVar2 = (uint *)(pcVar16 + 0x19);
      uVar32 = (uint)(puVar8 < in_CX || uVar17 - (int)in_CX < uVar32);
      puVar26 = (uint *)*puVar2;
      uVar17 = *puVar2;
      *puVar2 = (uVar17 - (int)puVar25) - uVar32;
                    /* WARNING: Read-only address (ram,0x00026a19) is written */
      uVar17 = (uint)(puVar26 < puVar25 || uVar17 - (int)puVar25 < uVar32);
      (*(uint16_t *)((uint8_t *)&(s_Peaceful_2410_2915) + 4)) = (0x6665U - (int)puVar34) - uVar17;
      uVar17 = (uint)((uint)0x6665 < puVar34 || (uint)(0x6665U - (int)puVar34) < uVar17);
      bVar36 = (uint)AgntAnms[6].y < pcVar23;
      uVar32 = AgntAnms[6].y - (int)pcVar23;
      AgntAnms[6].y = uVar32 - uVar17;
      puVar8 = (undefined1 *)(uint)(bVar36 || uVar32 < uVar17);
      puVar9 = &stack0xfff6 + -(int)puVar34;
      bVar36 = &stack0xfff6 < puVar34 || puVar9 < puVar8;
      iVar27 = -(int)puVar8;
      puVar29 = (uint *)(puVar9 + iVar27);
      bVar12 = (byte)((uint)in_CX >> 8);
      bVar21 = (byte)pcVar23 - bVar12;
      bVar37 = (byte)pcVar23 < bVar12 || bVar21 < bVar36;
      bVar24 = (byte)((uint)pcVar23 >> 8);
      bVar21 = bVar21 - bVar36;
      bVar36 = bVar14 != 0 || (byte)-bVar14 < bVar37;
      bVar20 = -bVar14 - bVar37;
      bVar22 = bVar21 - dir;
      bVar37 = bVar21 < dir || bVar22 < bVar36;
      bVar22 = bVar22 - bVar36;
      pbVar3 = (byte *)((char *)((int)puVar25 + (int)pcVar16) + -0x60e8);
      bVar36 = *pbVar3 < bVar12 || (byte)(*pbVar3 - bVar12) < bVar37;
      *pbVar3 = (*pbVar3 - bVar12) - bVar37;
      pbVar3 = (byte *)(puVar30 + -0x3974);
      bVar37 = *pbVar3 < bVar22 || (byte)(*pbVar3 - bVar22) < bVar36;
      *pbVar3 = (*pbVar3 - bVar22) - bVar36;
      pbVar3 = (byte *)(pcVar16 + 31000);
      bVar38 = *pbVar3 < dir || (byte)(*pbVar3 - dir) < bVar37;
      *pbVar3 = (*pbVar3 - dir) - bVar37;
      pbVar3 = (byte *)(puVar30 + 0xc);
      bVar21 = *pbVar3;
      bVar12 = *pbVar3 - bVar24;
      bVar37 = bVar21 < bVar24 || bVar12 < bVar38;
      bVar41 = SBORROW1(*pbVar3,bVar24) != SBORROW1(bVar12,bVar38);
      *pbVar3 = bVar12 - bVar38;
      bVar40 = (char)*pbVar3 < '\0';
      bVar39 = *pbVar3 == 0;
      bVar36 = !bVar41;
      bVar13 = (byte)in_CX;
      puVar31 = puVar30;
      if (!bVar36) {
        puVar6 = puVar34;
        puVar34 = puVar34 + 1;
        uVar7 = in(CONCAT11(bVar24,bVar22));
        *puVar6 = uVar7;
        pbVar3 = (byte *)(pcVar16 + 0x18);
        bVar4 = *pbVar3;
        bVar5 = *pbVar3;
        *pbVar3 = (bVar5 - bVar20) - bVar37;
        *(uint **)(puVar9 + iVar27 + -2) = puVar25;
        ((char *)((int)puVar30 + (int)pcVar16))[0x18] =
             (((char *)((int)puVar30 + (int)pcVar16))[0x18] - bVar13) -
             (bVar4 < bVar20 || (byte)(bVar5 - bVar20) < bVar37);
        *(uint *)((int)puVar25 + (int)pcVar16) =
             *(uint *)((int)puVar25 + (int)pcVar16) ^ (uint)puVar25;
        *(uint *)((int)puVar25 + (int)pcVar16) =
             *(uint *)((int)puVar25 + (int)pcVar16) | (uint)puVar25;
        *(char *)((int)puVar25 + (int)pcVar16) = *(char *)((int)puVar25 + (int)pcVar16) + bVar14;
        *puVar25 = ~*puVar25;
        puVar31 = (undefined2 *)*puVar30;
        uVar17 = CONCAT11(bVar20,dir - 0x18) & 0x9e1f;
        bVar40 = (int)uVar17 < 0;
        bVar39 = uVar17 == 0;
        puVar29 = puVar30 + 3;
      }
      bVar37 = bVar36 && bVar37;
      uVar35 = *puVar29;
      if (bVar39 || (bVar36 && bVar41) != bVar40) {
        bVar40 = bVar37;
        if ((!bVar36 || bVar21 >= bVar24 && bVar12 >= bVar38) && !bVar39) {
          *puVar29 = (uint)puVar31;
          uVar35 = *puVar29;
          uVar17 = (int)(char)bVar13 + 0xe299;
          iVar27 = uVar17 - bVar37;
          *puVar29 = iVar27;
          *pcVar16 = -*pcVar16;
          return (char *)((iVar27 + -0x1d32) -
                         (uint)((uint)(int)(char)bVar13 < 0x1d67 || uVar17 < bVar37));
        }
      }
      else {
        bVar40 = bVar13 < 0x74 || (byte)(bVar13 + 0x8c) < bVar37;
        bVar13 = (bVar13 + 0x8c) - bVar37;
      }
      bVar36 = bVar13 < 100 || (byte)(bVar13 + 0x9c) < bVar40;
      bVar12 = (bVar13 + 0x9c) - bVar40;
      bVar21 = bVar12 - 0x39;
      bVar37 = bVar12 < 0x39 || bVar21 < bVar36;
      bVar21 = bVar21 - bVar36;
      bVar12 = bVar21 - 0x14;
      bVar36 = bVar21 < 0x14 || bVar12 < bVar37;
      bVar12 = bVar12 - bVar37;
      bVar21 = bVar12 - 8;
      bVar37 = bVar12 < 8 || bVar21 < bVar36;
      bVar21 = bVar21 - bVar36;
      bVar12 = bVar21 - 5;
      bVar13 = bVar12 - bVar37;
      iVar27 = -(uint)(bVar13 < 0xfa || (byte)(bVar13 + 6) < (bVar21 < 5 || bVar12 < bVar37)) -
               (int)puVar25;
      uVar32 = (uint)pcVar16 & *(uint *)((char *)((int)puVar25 + (int)pcVar16) + -0x6bdd);
      uVar33 = (uint)puVar34 & *(uint *)((uint8_t *)((int)puVar25 + (int)puVar34) + 0x23);
      *puVar29 = uVar32;
      uVar32 = uVar32 & *(uint *)((int)puVar25 + uVar33);
      uVar17 = CONCAT11(bVar24,bVar22) & *(uint *)((int)puVar31 + uVar32 + iVar27);
      puVar26 = (uint *)CONCAT11(bVar28,bVar14 & bVar28 &
                                        *(byte *)((int)&_streams[0xc].curp +
                                                 CONCAT11(bVar28,bVar14 & bVar28)));
      uVar11 = *puVar29;
      puVar2 = (uint *)((int)puVar31 + uVar32 + iVar27);
      *puVar2 = *puVar2 ^ (uint)(puVar29 + 1);
      piVar1 = (int *)((int)puVar31 + uVar32 + iVar27);
      *piVar1 = *piVar1 - (int)(puVar29 + 1);
      bVar21 = in(uVar17);
      uVar32 = uVar32 & uVar17;
      puVar2 = (uint *)((int)puVar26 + (int)((char *)"+%d ring of prot." + 1 + uVar32));
      *puVar2 = *puVar2 & uVar33;
      *(uint *)(uVar33 + 0x21) = *(uint *)(uVar33 + 0x21) & (uint)puVar26;
      *puVar26 = *puVar26 & uVar33;
      puVar2 = (uint *)&AgntAnms[0x5c].sx;
      *puVar2 = *puVar2 & (uint)(puVar29 + 1);
      puVar2 = (uint *)((int)puVar26 + uVar32);
      *puVar2 = *puVar2 & CONCAT11((char)((uint)uVar11 >> 8),bVar21);
      bVar14 = -(0x99 < bVar21);
      return (char *)CONCAT11((char)((uint)uVar11 >> 8),
                              bVar14 + (9 < (bVar14 & 0xf) | 9 < (bVar21 & 0xf) | in_AF) * '\x06' +
                              (0x99 < bVar14 || 0x99 < bVar21) * '`');
    }
    do {
      ovc23_usesBlitGfxRect2
                (unaff_DI,unaff_SI,(int)(agnt_t *)agnt,(brect_t *)((ulong)agnt >> 0x10),
                 (uint16_t)in_stack_00000000);
      cVar43 = '\x01';
      do {
        while( true ) {
          do {
            do {
              puVar34 = puVar34 + 1;
              pcVar16 = (char *)"puppetmaker" + 3;
              if (rowMapSquareEnd[0] <= puVar34) {
                if (cVar43 != '\0') {
                  ovr_constr_usesScreenOriginY((uint16_t)ofs,(uint16_t)seg);
                }
                return pcVar16;
              }
              play_id = *(uint16_t *)((int)puVar34 * 2 + 0x360);
            } while (((int)play_id < -2) || (1 < (int)play_id));
            bVar21 = ovr_constr_setHighlightAtOffset(play_id,0);
            iVar27 = CONCAT11(extraout_AH,bVar21);
            if (((char *)"build\\thfres01.lbm" + 0x10)[iVar27 * 3 + *(int *)((int)puVar34 * 2)] !=
                '\0') {
              iVar15 = ovc23_usesCornerBR(play_id,iVar27);
              dst.seg = (uint16_t)seg;
              dst.ofs = (uint16_t)ofs;
              ovr_animAdvance(play_id,((char *)"build\\thfres01.lbm" + 0x10)
                                      [iVar27 * 3 + *(int *)((int)puVar34 * 2)],
                              *(uint16_t *)((int)puVar34 * 2 + 0xa20),(uint)bandOrigin[0] - iVar15,
                              dst);
              cVar43 = '\x01';
            }
          } while (*(int *)(play_id * 2 + -0x6e25) == -1);
          if (*(char *)(play_id + 0x90ec) != '\0') break;
          iVar27 = 0x6964;
          ovc23_usesCornerBR2(play_id,(uint)*(byte *)(*(int *)(play_id * 2 + -0x6e25) * 0x12 + 7));
          ovc23_usesBlitGfxRect2
                    (*(int *)((int)puVar34 * 2 + 0xa20),(uint)bandOrigin[0] - iVar27,iVar27,
                     (brect_t *)ofs,(uint16_t)seg);
          cVar43 = '\x01';
        }
      } while (play_id != 0xfffe);
      paVar44 = (agnt_t *)((int)&GSeasonNames[1].seg + 1);
      ovc23_usesCornerBR2(-2,(uint)*(byte *)(iRam0002d2d7 * 0x12 + 7));
      agnt = (agnt_t *)CONCAT22(ofs,paVar44);
      unaff_SI = (uint)bandOrigin[0] - (int)paVar44;
      unaff_DI = *(int *)((int)puVar34 * 2 + 0xa20) + -0x30;
      in_stack_00000000 = seg;
    } while( true );
  }
  return (char *)0x0;
}



/* 55fe:0f39 */

/* Rebuilds the four direction bits of a map cell from its neighbour tests. */

void __cdecl16far ovc23_rebuildDirectionFlags(int x,int y)

{
  uint *puVar1;
  uint *puVar2;
  char *pcVar3;
  byte bStack_3;
  
  if ((((x < 0x94) && (-1 < x)) && (y < 0x3c)) && (-1 < y)) {
    puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[y] + x);
    *puVar1 = *puVar1 & 0xff0f;
    for (bStack_3 = 0; bStack_3 < 4; bStack_3 = bStack_3 + 1) {
      puVar2 = ovc23_usesAlignUp43(x,y,bStack_3);
      if ((char)puVar2 != '\0') {
        puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[y] + x);
        *puVar1 = *puVar1 | 0x10 << (bStack_3 & 0x1f);
      }
      pcVar3 = ovc23_textConstructionAbandoned((char *)x,(uint8_t *)y,bStack_3);
      if ((char)pcVar3 != '\0') {
        puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[y] + x);
        *puVar1 = *puVar1 | 0x100 << (bStack_3 & 0x1f);
      }
    }
  }
  return;
}



/* 55fe:1005 */

/* Places a building of the given bldType/unitType at (x,y). */

void __cdecl16far ovc23_placeBuilding(int x,int y,byte bldType,uint8_t unitType)

{
  byte *pbVar1;
  uint *puVar2;
  byte bVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined1 extraout_AH_02;
  
  iVar4 = (*(short (*) [148] [60])GUnitGrid)[x][y];
  bVar3 = ((unit_t *)GUnits + iVar4)->bldType;
  if ((*(uint *)((uint)bVar3 * 0x27 + 0x121) & 4) != 0) {
    strongholdCheckPending = 1;
  }
  uVar6 = ovr_ovc18_usesRandBelow(x,y,bldType,unitType);
  if ((*(byte *)((uint)bldType * 0x27 + 0x11e) & 2) == 2) {
    ovc23_usesGfxRndSeed2(x,y);
  }
  if (((*(byte *)((uint)bldType * 0x27 + 0x11e) & 0xf) != 0) ||
     ((*(byte *)((uint)bVar3 * 0x27 + 0x11e) & 0xf) != 0)) {
    ovc23_rebuildDirectionFlags(x,y);
  }
  if (((*(byte *)((uint)bVar3 * 0x27 + 0x11e) & 1) != 0) ||
     ((*(byte *)((uint)bldType * 0x27 + 0x11e) & 1) != 0)) {
    ovc23_rebuildDirectionFlags(x,y + 1);
  }
  if (((*(byte *)((uint)bldType * 0x27 + 0x11e) & 2) != 0) ||
     ((*(byte *)((uint)bVar3 * 0x27 + 0x11e) & 2) != 0)) {
    ovc23_rebuildDirectionFlags(x + -1,y);
  }
  if (((*(byte *)((uint)bldType * 0x27 + 0x11e) & 3) == 3) ||
     ((*(byte *)((uint)bVar3 * 0x27 + 0x11e) & 3) == 3)) {
    ovc23_rebuildDirectionFlags(x + 1,y);
    ovc23_rebuildDirectionFlags(x,y + 1);
  }
  if (*(char *)((uint)bldType * 0x27 + 0x11a) == '\x02') {
    if (((*(short (*) [60] [148])GMapFlags)[y + 1][x] & 3U) != 0) {
      pbVar1 = &((unit_t *)GUnits)[uVar6].flags;
      *pbVar1 = *pbVar1 | 4;
      puVar2 = (uint *)((*(short (*) [60] [148])GMapFlags)[y + 1] + x);
      *puVar2 = *puVar2 & 0xfffc;
    }
    if ((*(byte *)((uint)bldType * 0x27 + 0x11e) & 4) != 0) {
      if (((*(short (*) [60] [148])GMapFlags)[y][x + 0x93] & 3U) != 0) {
        pbVar1 = &((unit_t *)GUnits)[uVar6].flags;
        *pbVar1 = *pbVar1 | 8;
        puVar2 = (uint *)((*(short (*) [60] [148])GMapFlags)[y] + x + 0x93);
        *puVar2 = *puVar2 & 0xfffc;
        ovc23_rebuildDirectionFlags(x + -2,y);
        ovc23_rebuildDirectionFlags(x + -1,y + -1);
        ovc23_rebuildDirectionFlags(x + -1,y + 1);
      }
      if (((*(short (*) [60] [148])GMapFlags)[y + 1][x + 1] & 3U) != 0) {
        pbVar1 = &((unit_t *)GUnits)[uVar6].flags;
        *pbVar1 = *pbVar1 | 0x10;
        puVar2 = (uint *)((*(short (*) [60] [148])GMapFlags)[y + 1] + x + 1);
        *puVar2 = *puVar2 & 0xfffc;
        ovc23_rebuildDirectionFlags(x + 1,y + -1);
        ovc23_rebuildDirectionFlags(x + 1,y + 1);
        ovc23_rebuildDirectionFlags(x + 2,y);
      }
    }
    if ((*(byte *)((uint)bldType * 0x27 + 0x11e) & 8) != 0) {
      if (((*(short (*) [60] [148])GMapFlags)[y][x] & 3U) != 0) {
        pbVar1 = &((unit_t *)GUnits)[uVar6].flags;
        *pbVar1 = *pbVar1 | 8;
        puVar2 = (uint *)((*(short (*) [60] [148])GMapFlags)[y] + x);
        *puVar2 = *puVar2 & 0xfffc;
        ovc23_rebuildDirectionFlags(x + -1,y + -1);
        ovc23_rebuildDirectionFlags(x + 1,y + -1);
        ovc23_rebuildDirectionFlags(x,y + -2);
      }
      if (((*(short (*) [60] [148])GMapFlags)[y + 2][x] & 3U) != 0) {
        pbVar1 = &((unit_t *)GUnits)[uVar6].flags;
        *pbVar1 = *pbVar1 | 0x10;
        puVar2 = (uint *)((*(short (*) [60] [148])GMapFlags)[y + 2] + x);
        *puVar2 = *puVar2 & 0xfffc;
        ovc23_rebuildDirectionFlags(x + -1,y + 1);
        ovc23_rebuildDirectionFlags(x + 1,y + 1);
        ovc23_rebuildDirectionFlags(x,y + 2);
      }
    }
    ovc23_rebuildDirectionFlags(x,y);
    ovc23_rebuildDirectionFlags(x + 1,y);
    ovc23_rebuildDirectionFlags(x + -1,y);
    ovc23_rebuildDirectionFlags(x,y + -1);
    ovc23_rebuildDirectionFlags(x,y + 1);
  }
  if (*(char *)((uint)bVar3 * 0x27 + 0x11a) == '\x02') {
    ovc23_usesGfxRndSeed2(x,y);
    if ((((unit_t *)GUnits)[iVar4].flags & 4) != 0) {
      ovc23_drownUnitsAt(x,y);
    }
    if (*(char *)((uint)bVar3 * 0x27 + 0x11e) == '\x04') {
      bVar5 = ovr_ovc45_getUnitType(x + -1,y);
      if ((CONCAT11(extraout_AH,bVar5) == 0) && ((((unit_t *)GUnits)[iVar4].flags & 8) != 0)) {
        ovc23_usesGfxRndSeed2(x + -1,y);
        ovc23_drownUnitsAt(x - 1,y);
        ovc23_rebuildDirectionFlags(x + -1,y + -1);
        ovc23_rebuildDirectionFlags(x + -1,y + 1);
        ovc23_rebuildDirectionFlags(x + -2,y);
      }
      bVar5 = ovr_ovc45_getUnitType(x + 1,y);
      if ((CONCAT11(extraout_AH_00,bVar5) == 0) && ((((unit_t *)GUnits)[iVar4].flags & 0x10) != 0))
      {
        ovc23_usesGfxRndSeed2(x + 1,y);
        ovc23_drownUnitsAt(x + 1,y);
        ovc23_rebuildDirectionFlags(x + 1,y + -1);
        ovc23_rebuildDirectionFlags(x + 1,y + 1);
        ovc23_rebuildDirectionFlags(x + 2,y);
      }
    }
    else if (*(char *)((uint)bVar3 * 0x27 + 0x11e) == '\b') {
      bVar5 = ovr_ovc45_getUnitType(x,y + -1);
      if ((CONCAT11(extraout_AH_01,bVar5) == 0) && ((((unit_t *)GUnits)[iVar4].flags & 8) != 0)) {
        ovc23_usesGfxRndSeed2(x,y + -1);
        ovc23_drownUnitsAt(x,y - 1);
        ovc23_rebuildDirectionFlags(x + -1,y + -1);
        ovc23_rebuildDirectionFlags(x + 1,y + -1);
        ovc23_rebuildDirectionFlags(x,y + -2);
      }
      bVar5 = ovr_ovc45_getUnitType(x,y + 1);
      if ((CONCAT11(extraout_AH_02,bVar5) == 0) && ((((unit_t *)GUnits)[iVar4].flags & 0x10) != 0))
      {
        ovc23_usesGfxRndSeed2(x,y + 1);
        ovc23_drownUnitsAt(x,y + 1);
        ovc23_rebuildDirectionFlags(x + -1,y + 1);
        ovc23_rebuildDirectionFlags(x + 1,y + 1);
        ovc23_rebuildDirectionFlags(x,y + 2);
      }
    }
    ovc23_rebuildDirectionFlags(x,y);
    ovc23_rebuildDirectionFlags(x + 1,y);
    ovc23_rebuildDirectionFlags(x + -1,y);
    ovc23_rebuildDirectionFlags(x,y + -1);
    ovc23_rebuildDirectionFlags(x,y + 1);
  }
  if ((*(char *)((uint)bldType * 0x27 + 0x133) == '\x12') && (ListCount < 5)) {
    *(uint *)((uint)ListCount * 2 + -0x6d44) = uVar6;
    ListCount = ListCount + 1;
  }
  if ((*(int *)((uint)bldType * 0x27 + 0x12e) != 0) || (*(int *)((uint)bVar3 * 0x27 + 0x12e) != 0))
  {
    ovr_unit_usesAlignUp4();
  }
  return;
}



/* 55fe:1803 */

/* Removes a record from the 0x12-stride table at 0x21f2, compacts the tail and decrements
   GRecordCount. */

void __cdecl16far ovc23_removeRecord(int recordIndex)

{
  uint16_t unaff_BP;
  uint unaff_SI;
  agnt_t *in_stack_00000000;
  
  if (recordIndex + 1U < GRecordCount) {
    _fmemmove((char *)CONCAT22(0x21f2,(char *)(recordIndex * 0x12)),
              (char *)CONCAT22(0x21f2,(char *)(recordIndex * 0x12 + 0x12)),
              ((GRecordCount - recordIndex) + -1) * 0x12);
  }
  GRecordCount = GRecordCount - 1;
  ovc23_textAdlibNone(unaff_SI,unaff_BP,in_stack_00000000);
  return;
}



/* 55fe:184e */

/* appends a construction record (bldType, x, y, party, tick) */

void __cdecl16far
createConstructionRecord(byte bldType,int x,int y,uint8_t *outFlag,byte outFlagSeg,char partyIndex)

{
  int *piVar1;
  byte *pbVar2;
  undefined1 uVar3;
  int iVar4;
  undefined2 uVar5;
  uint uVar6;
  uint16_t unaff_SI;
  uint uVar7;
  uint unaff_DI;
  uint uVar8;
  undefined2 uVar9;
  undefined1 in_stack_0000000d;
  char in_stack_00000010;
  agnt_t *in_stack_0000fff6;
  agnt_t *paVar10;
  uint uVar11;
  byte bStack_5;
  byte bStack_3;
  
  _outFlag = (undefined1 *)CONCAT13(in_stack_0000000d,CONCAT12(outFlagSeg,outFlag));
  for (iVar4 = 0; iVar4 < (int)(uint)*(byte *)((uint)bldType * 0x27 + 0x11b); iVar4 = iVar4 + 1) {
    in_stack_0000fff6 = (agnt_t *)ovc23_findRecordAt(x + iVar4,y);
    if (-1 < (int)in_stack_0000fff6) {
      ovc23_removeRecord((int)in_stack_0000fff6);
    }
  }
  iVar4 = ovc23_isLargeBuilding(x,y);
  if ((char)iVar4 != '\0') {
    ovc23_placeBuilding(x + -1,y,0,partyIndex);
    uVar5 = ovr_ovc22_usesGOngoingBattle((byte)x - 1,(byte)y);
    if ((char)uVar5 != '\0') {
      *_outFlag = 1;
    }
  }
  for (paVar10 = (agnt_t *)CONCAT22(1,in_stack_0000fff6); iVar4 = (int)((ulong)paVar10 >> 0x10),
      iVar4 < (int)(uint)*(byte *)((uint)bldType * 0x27 + 0x11b);
      paVar10 = (agnt_t *)CONCAT22((int)((ulong)paVar10 >> 0x10) + 1,(agnt_t *)paVar10)) {
    ovc23_placeBuilding(x + iVar4,y,0,partyIndex);
    uVar5 = ovr_ovc22_usesGOngoingBattle((byte)x + (char)((ulong)paVar10 >> 0x10),(byte)y);
    if ((char)uVar5 != '\0') {
      *_outFlag = 1;
    }
  }
  if (*(char *)((int)*(undefined4 *)((uint)(byte)partyIndex << 2) + 0x3f) == '\0') {
    if (0x31 < GRecordCount) {
      uVar7 = 0;
      uVar8 = 0xffff;
      for (paVar10 = (agnt_t *)((ulong)paVar10 & 0xffff); uVar6 = (uint)((ulong)paVar10 >> 0x10),
          uVar6 < GRecordCount; paVar10 = (agnt_t *)CONCAT22(uVar11 + 1,(agnt_t *)paVar10)) {
        uVar6 = ovr_ovc22_usesGOngoingBattle
                          (*(byte *)(uVar6 * 0x12 + 2),*(byte *)(uVar6 * 0x12 + 4));
        uVar11 = (uint)((ulong)paVar10 >> 0x10);
        if (((uVar6 & 0xff) == 0) && (uVar7 <= (uint)(GameTick - *(int *)(uVar11 * 0x12 + 0xf)))) {
          uVar7 = GameTick - *(int *)(uVar11 * 0x12 + 0xf);
          uVar8 = uVar11;
        }
      }
      if (uVar8 == 0xffff) {
        for (paVar10 = (agnt_t *)((ulong)paVar10 & 0xffff); uVar6 = (uint)((ulong)paVar10 >> 0x10),
            uVar6 < GRecordCount; paVar10 = (agnt_t *)CONCAT22(uVar6 + 1,(agnt_t *)paVar10)) {
          if (uVar7 <= (uint)(GameTick - *(int *)(uVar6 * 0x12 + 0xf))) {
            uVar7 = GameTick - *(int *)(uVar6 * 0x12 + 0xf);
            uVar8 = uVar6;
          }
        }
      }
      if (uVar8 == 0xffff) {
        return;
      }
      paVar10 = (agnt_t *)CONCAT22(uVar8,(agnt_t *)paVar10);
      if (uVar8 + 1 < GRecordCount) {
        _fmemmove((char *)CONCAT22(0x21f2,(char *)(uVar8 * 0x12)),
                  (char *)CONCAT22(0x21f2,(char *)(uVar8 * 0x12 + 0x12)),
                  ((GRecordCount - uVar8) + -1) * 0x12);
      }
      GRecordCount = GRecordCount - 1;
    }
    _fmemset((void *)(GRecordCount * 0x12),0x21f2,0);
    *(byte *)(GRecordCount * 0x12 + 8) = bldType;
    *(int *)(GRecordCount * 0x12 + 2) = x;
    *(int *)(GRecordCount * 0x12 + 4) = y;
    *(char *)(GRecordCount * 0x12 + 9) = partyIndex;
    iVar4 = ovc23_isLargeBuilding(x,y);
    uVar5 = (undefined2)((ulong)GUnitGrid >> 0x10);
    uVar9 = (undefined2)((ulong)GUnits >> 0x10);
    if ((char)iVar4 == '\0') {
      bStack_5 = ((unit_t *)GUnits + (*(short (*) [148] [60])GUnitGrid)[x][y])->bldType;
    }
    else {
      bStack_5 = ((unit_t *)GUnits + ((short (*) [148] [60])GUnitGrid)[-1][x + 0x93][y])->bldType;
    }
    bStack_3 = *(byte *)((uint)bStack_5 * 0x27 + 0x11d);
    uVar3 = *(undefined1 *)((uint)bStack_5 * 0x27 + 0x11b);
    if (bStack_3 == 0) {
      bStack_3 = 1;
    }
    if (bStack_3 < *(byte *)((uint)bldType * 0x27 + 0x11c)) {
      *(undefined1 *)(GRecordCount * 0x12 + 6) = *(undefined1 *)((uint)bldType * 0x27 + 0x11c);
    }
    else {
      *(byte *)(GRecordCount * 0x12 + 6) = bStack_3;
    }
    *(int *)(GRecordCount * 0x12 + 0xf) = GameTick;
    *(undefined2 *)(GRecordCount * 0x12) = 0;
    uVar5 = ovc23_usesGRecordCount3(*(byte *)((uint)bldType * 0x27 + 0x120),partyIndex,GRecordCount)
    ;
    *(undefined1 *)(GRecordCount * 0x12 + 0xc) = (char)uVar5;
    if (*(char *)(GRecordCount * 0x12 + 0xc) == '\0') {
      *(undefined1 *)(GRecordCount * 0x12 + 0xc) = 1;
    }
    if (bldType == 0) {
      iVar4 = ovc23_isLargeBuilding(x,y);
      if ((char)iVar4 != '\0') {
        piVar1 = (int *)(GRecordCount * 0x12 + 2);
        *piVar1 = *piVar1 + -1;
      }
      *(undefined1 *)(GRecordCount * 0x12 + 7) = uVar3;
      if (in_stack_00000010 == '\x01') {
        *(undefined1 *)(GRecordCount * 0x12 + 0xe) = 1;
      }
      else {
        *(char *)(GRecordCount * 0x12 + 0xc) = in_stack_00000010;
        *(undefined1 *)(GRecordCount * 0x12 + 0xe) = 0;
      }
      pbVar2 = (byte *)(GRecordCount * 0x12 + 0xd);
      *pbVar2 = *pbVar2 | 3;
    }
    else {
      *(undefined1 *)(GRecordCount * 0x12 + 7) = *(undefined1 *)((uint)bldType * 0x27 + 0x11b);
      if (in_stack_00000010 != '\0') {
        ovc23_placeBuilding(x,y,0,partyIndex);
        uVar5 = ovr_ovc22_usesGOngoingBattle((byte)x,(byte)y);
        if ((char)uVar5 != '\0') {
          *_outFlag = 1;
        }
      }
      *(undefined1 *)(GRecordCount * 0x12 + 0xe) = 0;
    }
    *(undefined1 *)(GRecordCount * 0x12 + 0x11) = 0;
    *(undefined1 *)(GRecordCount * 0x12 + 0xb) = *(undefined1 *)(GRecordCount * 0x12 + 0xc);
    uVar8 = GRecordCount;
    GRecordCount = GRecordCount + 1;
    ovc23_abandonConstruction(uVar8);
    ovc23_textAdlibNone(unaff_DI,unaff_SI,paVar10);
  }
  else {
    ovc23_placeBuilding(x,y,bldType,partyIndex);
    uVar5 = ovr_ovc22_usesGOngoingBattle((byte)x,(byte)y);
    if ((char)uVar5 != '\0') {
      *_outFlag = 1;
    }
  }
  return;
}



/* 55fe:1e87 */

/* overlay entry that forwards to createConstructionRecord */

void __cdecl16far
createConstructionRecordFar
          (byte bldType,int x,int y,uint8_t *outFlag,byte outFlagSeg,char partyIndex)

{
  createConstructionRecord(bldType,x,y,outFlag,outFlagSeg,partyIndex);
  return;
}



/* 55fe:1ea9 */

/* [R4] calls ovr_blitGfxRect */

void __cdecl16far ovc23_usesBlitGfxRect(int x,int y,int recordIndex,brect_t *rect,uint16_t type)

{
  int y_00;
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int x_00;
  uint uVar4;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t gfx_05;
  far_t gfx_06;
  far_t gfx_07;
  far_t gfx_08;
  far_t gfx_09;
  far_t gfx_10;
  far_t gfx_11;
  uint8_t type_00;
  uint uStack_10;
  uint uStack_e;
  int iStack_c;
  uint16_t uStack_a;
  uint16_t uStack_8;
  
  uStack_10 = (uint)*(byte *)(recordIndex * 0x12 + 6);
  uVar3 = *(uint *)(recordIndex * 0x12);
  bVar1 = *(byte *)(recordIndex * 0x12 + 0xe);
  bVar2 = *(byte *)(recordIndex * 0x12 + 0x11);
  if (bVar2 < uStack_10) {
    uStack_10 = bVar2 + 1;
  }
  x_00 = x + -1;
  iStack_c = y + uStack_10 * -0x26 + -0x32;
  uStack_e = uStack_10;
  while (uStack_e = uStack_e - 1, -1 < (int)uStack_e) {
    y_00 = iStack_c + 0x26;
    type_00 = (uint8_t)type;
    if ((bVar1 == 2) || (0x13 < uVar3)) {
      if (bVar1 < 2) {
        if ((uStack_e == 0) && ((uVar3 - x_00 & 0x3f) < 0x20)) {
          uVar4 = uVar3 - x_00 & 0x3f;
          uStack_8 = ((undefined2 *)&csite5Seg)[uVar4 * 2];
          uStack_a = ((undefined2 *)&csite5Ofs)[uVar4 * 2];
        }
        else {
          uStack_8 = csite3_5Seg;
          uStack_a = csite3_5Ofs;
        }
        if (uStack_e == 0) {
          uVar4 = (uVar3 + GfxRndSeed2) % 0xe;
          gfx_01.seg = ((undefined2 *)&tmstrsSprites6Seg)[uVar4 * 2];
          gfx_01.ofs = ((undefined2 *)&tmstrsSprites6Ofs)[uVar4 * 2];
          ovr_blitGfxRect(gfx_01,x + 0xe,iStack_c + 0x8b,rect,type_00,true);
        }
        gfx_02.seg = uStack_8;
        gfx_02.ofs = uStack_a;
        ovr_blitGfxRect(gfx_02,x_00,y_00,rect,type_00,true);
        if ((uVar3 + uStack_e + GfxRndSeed2 + x_00 & 0x1f) < 0x11) {
          uVar4 = uVar3 + uStack_e + GfxRndSeed2 + x_00 & 0x1f;
          gfx_03.seg = ((undefined2 *)&tmstrsSprites5Seg)[uVar4 * 2];
          gfx_03.ofs = ((undefined2 *)&tmstrsSprites5Ofs)[uVar4 * 2];
          ovr_blitGfxRect(gfx_03,x_00 + ((uint)*(byte *)((uVar3 + uStack_e + GfxRndSeed2 + x_00 >> 5
                                                         ) + uStack_e + GfxRndSeed2 & 0xff) * 0x50)
                                        / 0x100,iStack_c + 0x66,rect,type_00,true);
        }
        if ((((uVar3 + uStack_e) - GfxRndSeed2) - x_00 & 0xf) < 7) {
          uVar4 = ((uVar3 + uStack_e) - GfxRndSeed2) - x_00 & 0xf;
          gfx_04.seg = ((undefined2 *)&tmstrsSprites4Seg)[uVar4 * 2];
          gfx_04.ofs = ((undefined2 *)&tmstrsSprites4Ofs)[uVar4 * 2];
          ovr_blitGfxRect(gfx_04,x_00 + ((uint)*(byte *)((((((uVar3 + uStack_e) - GfxRndSeed2) -
                                                            x_00 >> 4) + uStack_e) - GfxRndSeed2) +
                                                         0xe & 0xff) * 0x50) / 0x100,iStack_c + 0x66
                          ,rect,type_00,true);
        }
        uVar4 = (uVar3 + 5) % 7;
        gfx_05.seg = ((undefined2 *)&tmstrsSprites3Seg)[uVar4 * 2];
        gfx_05.ofs = ((undefined2 *)&tmstrsSprites3Ofs)[uVar4 * 2];
        ovr_blitGfxRect(gfx_05,x + 9,iStack_c + 0x62,rect,type_00,true);
        gfx_06.seg = ((undefined2 *)&tmstrsSprites3Seg)[(uVar3 % 7) * 2];
        gfx_06.ofs = ((undefined2 *)&tmstrsSprites3Ofs)[(uVar3 % 7) * 2];
        ovr_blitGfxRect(gfx_06,x + 0xd,iStack_c + 0x62,rect,type_00,true);
        uVar4 = (uVar3 + 2) % 7;
        gfx_07.seg = ((undefined2 *)&tmstrsSprites3Seg)[uVar4 * 2];
        gfx_07.ofs = ((undefined2 *)&tmstrsSprites3Ofs)[uVar4 * 2];
        ovr_blitGfxRect(gfx_07,x + 0x31,iStack_c + 0x62,rect,type_00,true);
        uVar4 = uVar3 + 3 & 7;
        gfx_08.seg = ((undefined2 *)&tmstrsSprites2Seg)[uVar4 * 2];
        gfx_08.ofs = ((undefined2 *)&tmstrsSprites2Ofs)[uVar4 * 2];
        ovr_blitGfxRect(gfx_08,x + 0x45,iStack_c + 0x62,rect,type_00,true);
        gfx_09.seg = ((undefined2 *)&tmstrsSprites2Seg)[(uVar3 & 7) * 2];
        gfx_09.ofs = ((undefined2 *)&tmstrsSprites2Ofs)[(uVar3 & 7) * 2];
        ovr_blitGfxRect(gfx_09,x + 0x3b,iStack_c + 0x62,rect,type_00,true);
        gfx_10.seg = ((undefined2 *)&tmstrsSprites1Seg)[(uVar3 % 5) * 2];
        gfx_10.ofs = ((undefined2 *)&tmstrsSprites1Ofs)[(uVar3 % 5) * 2];
        ovr_blitGfxRect(gfx_10,x + 0x27,iStack_c + 0x62,rect,type_00,true);
        gfx_11.seg = ((undefined2 *)&tmstrsSprites1Seg)[(uVar3 % 5) * 2];
        gfx_11.ofs = ((undefined2 *)&tmstrsSprites1Ofs)[(uVar3 % 5) * 2];
        ovr_blitGfxRect(gfx_11,x + 0x3f,iStack_c + 0x62,rect,type_00,true);
        iStack_c = y_00;
      }
      else {
        if (uVar3 < 9) {
          uStack_8 = ((undefined2 *)&csite2Seg)[(uVar3 + 0xe) * 2];
          uStack_a = ((undefined2 *)&csite2Ofs)[(uVar3 + 0xe) * 2];
        }
        else {
          uStack_8 = csite4_8Seg;
          uStack_a = csite4_8Ofs;
        }
        gfx_00.seg = uStack_8;
        gfx_00.ofs = uStack_a;
        ovr_blitGfxRect(gfx_00,x_00,y_00,rect,type_00,true);
        iStack_c = y_00;
      }
    }
    else {
      if ((uStack_10 - 1 == uStack_e) && (uVar3 < 0xf)) {
        uStack_8 = ((undefined2 *)&csite2Seg)[uVar3 * 2];
        uStack_a = ((undefined2 *)&csite2Ofs)[uVar3 * 2];
      }
      else {
        uStack_8 = csite3_5Seg;
        uStack_a = csite3_5Ofs;
      }
      gfx.seg = uStack_8;
      gfx.ofs = uStack_a;
      ovr_blitGfxRect(gfx,x_00,y_00,rect,type_00,true);
      iStack_c = y_00;
    }
  }
  return;
}



/* 55fe:23d8 */

/* [R4] calls ovr_blitGfxRect */

void __cdecl16far ovc23_usesBlitGfxRect2(int x,int y,int recordIndex,brect_t *rect,uint16_t type)

{
  int y_00;
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint16_t uVar4;
  uint16_t uVar5;
  int x_00;
  uint uVar6;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t gfx_05;
  far_t gfx_06;
  far_t gfx_07;
  far_t gfx_08;
  far_t gfx_09;
  far_t gfx_10;
  far_t gfx_11;
  uint8_t type_00;
  uint uStack_12;
  uint uStack_c;
  int iStack_a;
  uint16_t uStack_8;
  uint16_t uStack_6;
  
  bVar1 = *(byte *)(recordIndex * 0x12 + 7);
  if (bVar1 < 2) {
    uStack_12 = (uint)*(byte *)(recordIndex * 0x12 + 6);
    uVar3 = *(uint *)(recordIndex * 0x12);
    bVar1 = *(byte *)(recordIndex * 0x12 + 0xe);
    bVar2 = *(byte *)(recordIndex * 0x12 + 0x11);
    if (bVar2 < uStack_12) {
      uStack_12 = bVar2 + 1;
    }
    x_00 = x + -1;
    iStack_a = y + uStack_12 * -0x13 + 0x2a;
    uStack_c = uStack_12;
    while (uVar5 = csite1_12Seg, uVar4 = csite1_12Ofs, uStack_c = uStack_c - 1, -1 < (int)uStack_c)
    {
      y_00 = iStack_a + 0x13;
      type_00 = (uint8_t)type;
      if ((bVar1 == 2) || (0x13 < uVar3)) {
        if (bVar1 < 2) {
          if (uStack_c == 0) {
            uVar6 = (uVar3 + GfxRndSeed2) % 0xe;
            gfx_01.seg = ((undefined2 *)&tmstrsSprites6Seg)[uVar6 * 2];
            gfx_01.ofs = ((undefined2 *)&tmstrsSprites6Ofs)[uVar6 * 2];
            ovr_blitGfxRect(gfx_01,x + 0xe,iStack_a + 0x22,rect,type_00,true);
          }
          gfx_02.seg = uVar5;
          gfx_02.ofs = uVar4;
          ovr_blitGfxRect(gfx_02,x_00,y_00,rect,type_00,true);
          if ((uVar3 + uStack_c + GfxRndSeed2 + x_00 & 0x1f) < 0x11) {
            uVar6 = uVar3 + uStack_c + GfxRndSeed2 + x_00 & 0x1f;
            gfx_03.seg = ((undefined2 *)&tmstrsSprites5Seg)[uVar6 * 2];
            gfx_03.ofs = ((undefined2 *)&tmstrsSprites5Ofs)[uVar6 * 2];
            ovr_blitGfxRect(gfx_03,x_00 + ((int)((uint)*(byte *)((uVar3 + uStack_c + GfxRndSeed2 +
                                                                  x_00 >> 5) + uStack_c +
                                                                 GfxRndSeed2 & 0xff) * 0x25) >> 8) +
                                   3,iStack_a + 0x10,rect,type_00,true);
          }
          if ((((uVar3 + uStack_c) - GfxRndSeed2) - x_00 & 0xf) < 7) {
            uVar6 = ((uVar3 + uStack_c) - GfxRndSeed2) - x_00 & 0xf;
            gfx_04.seg = ((undefined2 *)&tmstrsSprites4Seg)[uVar6 * 2];
            gfx_04.ofs = ((undefined2 *)&tmstrsSprites4Ofs)[uVar6 * 2];
            ovr_blitGfxRect(gfx_04,x_00 + ((int)((uint)*(byte *)((((((uVar3 + uStack_c) -
                                                                    GfxRndSeed2) - x_00 >> 4) +
                                                                  uStack_c) - GfxRndSeed2) + 0xe &
                                                                0xff) * 0x25) >> 8) + 3,
                            iStack_a + 0x10,rect,type_00,true);
          }
          uVar6 = (uVar3 + 5) % 7;
          gfx_05.seg = ((undefined2 *)&tmstrsSprites3Seg)[uVar6 * 2];
          gfx_05.ofs = ((undefined2 *)&tmstrsSprites3Ofs)[uVar6 * 2];
          ovr_blitGfxRect(gfx_05,x + 4,iStack_a + 0xd,rect,type_00,true);
          gfx_06.seg = ((undefined2 *)&tmstrsSprites3Seg)[(uVar3 % 7) * 2];
          gfx_06.ofs = ((undefined2 *)&tmstrsSprites3Ofs)[(uVar3 % 7) * 2];
          ovr_blitGfxRect(gfx_06,x + 6,iStack_a + 0xd,rect,type_00,true);
          uVar6 = (uVar3 + 2) % 7;
          gfx_07.seg = ((undefined2 *)&tmstrsSprites3Seg)[uVar6 * 2];
          gfx_07.ofs = ((undefined2 *)&tmstrsSprites3Ofs)[uVar6 * 2];
          ovr_blitGfxRect(gfx_07,x + 0x18,iStack_a + 0xd,rect,type_00,true);
          uVar6 = uVar3 + 3 & 7;
          gfx_08.seg = ((undefined2 *)&tmstrsSprites2Seg)[uVar6 * 2];
          gfx_08.ofs = ((undefined2 *)&tmstrsSprites2Ofs)[uVar6 * 2];
          ovr_blitGfxRect(gfx_08,x + 0x22,iStack_a + 0xd,rect,type_00,true);
          gfx_09.seg = ((undefined2 *)&tmstrsSprites2Seg)[(uVar3 & 7) * 2];
          gfx_09.ofs = ((undefined2 *)&tmstrsSprites2Ofs)[(uVar3 & 7) * 2];
          ovr_blitGfxRect(gfx_09,x + 0x1d,iStack_a + 0xd,rect,type_00,true);
          gfx_10.seg = ((undefined2 *)&tmstrsSprites1Seg)[(uVar3 % 5) * 2];
          gfx_10.ofs = ((undefined2 *)&tmstrsSprites1Ofs)[(uVar3 % 5) * 2];
          ovr_blitGfxRect(gfx_10,x + 0x13,iStack_a + 0xd,rect,type_00,true);
          gfx_11.seg = ((undefined2 *)&tmstrsSprites1Seg)[(uVar3 % 5) * 2];
          gfx_11.ofs = ((undefined2 *)&tmstrsSprites1Ofs)[(uVar3 % 5) * 2];
          ovr_blitGfxRect(gfx_11,x + 0x1f,iStack_a + 0xd,rect,type_00,true);
          iStack_a = y_00;
        }
        else {
          if (uVar3 < 10) {
            uStack_6 = ((undefined2 *)&csite1Seg)[(uVar3 + 0xc) * 2];
            uStack_8 = ((undefined2 *)&csite1Ofs)[(uVar3 + 0xc) * 2];
          }
          else {
            uStack_6 = csite1_22Seg;
            uStack_8 = csite1_22Ofs;
          }
          gfx_00.seg = uStack_6;
          gfx_00.ofs = uStack_8;
          ovr_blitGfxRect(gfx_00,x_00,y_00,rect,type_00,true);
          iStack_a = y_00;
        }
      }
      else {
        if ((uStack_12 - 1 == uStack_c) && (uVar3 < 0xd)) {
          uStack_6 = ((undefined2 *)&csite1Seg)[uVar3 * 2];
          uStack_8 = ((undefined2 *)&csite1Ofs)[uVar3 * 2];
        }
        else {
          uStack_6 = csite1_12Seg;
          uStack_8 = csite1_12Ofs;
        }
        gfx.seg = uStack_6;
        gfx.ofs = uStack_8;
        ovr_blitGfxRect(gfx,x_00,y_00,rect,type_00,true);
        iStack_a = y_00;
      }
    }
  }
  else {
    ovc23_usesBlitGfxRect(x,y + 10,recordIndex,rect,type);
    if (2 < bVar1) {
      ovc23_usesBlitGfxRect(x + 0x5e,y + 10,recordIndex,rect,type);
    }
  }
  return;
}



/* 55fe:2937 */

/* Returns the index of the 0x12-stride record at 0x21f2 whose row is y and whose x-span contains x,
   or 0xffff. */

uint __cdecl16far ovc23_findRecordAt(int x,int y)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    if (GRecordCount <= uVar2) {
      return 0xffff;
    }
    if (((*(int *)(uVar2 * 0x12 + 4) == y) &&
        (iVar1 = *(int *)(uVar2 * 0x12 + 2),
        x <= (int)(iVar1 + (uint)*(byte *)(uVar2 * 0x12 + 7) + -1))) && (iVar1 <= x)) break;
    uVar2 = uVar2 + 1;
  }
  return uVar2;
}



/* 55fe:29a2 */

/* Removes an unreachable construction record and reports "Construction abandoned." on the cursor
   cell. */

void __cdecl16far ovc23_abandonConstruction(int recordIndex)

{
  byte *pbVar1;
  byte bVar2;
  uint y;
  undefined4 uVar3;
  uint x;
  char *pcVar4;
  undefined2 uVar5;
  uint16_t unaff_SI;
  uint unaff_DI;
  uint uVar6;
  byte bVar7;
  agnt_t *agnt;
  uint uVar8;
  
  bVar2 = *(byte *)(recordIndex * 0x12 + 9);
  uVar8 = (uint)bVar2;
  uVar3 = *(undefined4 *)((uint)bVar2 << 2);
  if (*(char *)((int)uVar3 + 0x3f) == '\0') {
    x = ovr_alignUp4(*(int *)(recordIndex * 0x12 + 2));
    y = *(uint *)(recordIndex * 0x12 + 4);
    uVar3 = *(undefined4 *)((uVar8 & 0xff) << 2);
    bVar2 = *(byte *)((int)uVar3 + 0x3f);
    uVar3 = *(undefined4 *)((uVar8 & 0xff) << 2);
    uVar6 = 0;
    agnt = (agnt_t *)
           (CONCAT22(0x1000 << ((*(byte *)((int)uVar3 + 0x3f) ^ 1) & 0x1f),uVar8) & 0xffff00ff);
    while( true ) {
      bVar7 = (byte)((ulong)agnt >> 8);
      uVar8 = (uint)((ulong)agnt >> 0x10);
      if (3 < bVar7) break;
      uVar6 = uVar6 | ((short (*) [60] [148])GMapFlags)[-1][y + 0x3b][x + bVar7 + 0x92] & 0x3000U;
      agnt = (agnt_t *)CONCAT22(uVar8,(agnt_t *)CONCAT11(bVar7 + 1,(byte)agnt));
    }
    if ((((*(byte *)(recordIndex * 0x12 + 0xd) & 3) == 1) && (uVar6 == uVar8)) &&
       (uVar3 = *(undefined4 *)((uint)(byte)agnt << 2),
       pcVar4 = ovr_ovc24_textArena(x,y,*(char *)((int)uVar3 + 0x3f)), ((uint)pcVar4 & 0xff) == 0))
    {
      uVar5 = ovc23_isCursorAt(x,y);
      if ((char)uVar5 != '\0') {
        ovr_say((char *)"Construction abandoned.");
      }
      if (recordIndex + 1U < GRecordCount) {
        _fmemmove((char *)CONCAT22(0x21f2,(char *)(recordIndex * 0x12)),
                  (char *)CONCAT22(0x21f2,(char *)(recordIndex * 0x12 + 0x12)),
                  ((GRecordCount - recordIndex) + -1) * 0x12);
      }
      GRecordCount = GRecordCount - 1;
      ovc23_textAdlibNone(unaff_DI,unaff_SI,agnt);
    }
    else if (((*(byte *)(recordIndex * 0x12 + 0xd) & 1) == 0) &&
            ((0x1000 << (bVar2 & 0x1f) & uVar6) != 0)) {
      pbVar1 = (byte *)(recordIndex * 0x12 + 0xd);
      *pbVar1 = *pbVar1 | 1;
    }
  }
  return;
}



/* 55fe:2b82 */

/* [R1] forwards to OVC23_55fe_29a2 */

void __cdecl16far OVC23_55fe_29a2_entry(void)

{
  int recordIndex;
  
  recordIndex = GRecordCount;
  while (recordIndex = recordIndex + -1, -1 < recordIndex) {
    ovc23_abandonConstruction(recordIndex);
  }
  return;
}



/* 55fe:2b9e */

/* [R7] body shape: compute */

uint __cdecl16far ovc23_compute1(int x,int y,byte bldType,uint8_t unitType)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  
  cVar1 = *(char *)((uint)bldType * 0x27 + 0x11e);
  if (cVar1 == '\0') {
    uVar4 = 0;
  }
  else if (cVar1 == '\x01') {
    bVar2 = ovr_ovc45_getUnitType(x,y + -1);
    if (*(char *)((uint)bVar2 * 0x27 + 0x11e) == '\x02') {
      ovc23_placeBuilding(x,y,bldType + 2,unitType);
    }
    else {
      ovc23_placeBuilding(x,y,bldType,unitType);
    }
    bVar2 = ovr_ovc45_getUnitType(x + -1,y);
    iVar3 = (uint)bVar2 * 0x27;
    if (*(char *)(iVar3 + 0x11e) == '\x02') {
      iVar3 = x + -1;
      ovc23_placeBuilding(iVar3,y,bVar2 + 1,unitType);
    }
    uVar4 = CONCAT11((char)((uint)iVar3 >> 8),1);
  }
  else if (cVar1 == '\x02') {
    bVar2 = ovr_ovc45_getUnitType(x + 1,y);
    if (*(char *)((uint)bVar2 * 0x27 + 0x11e) == '\x01') {
      ovc23_placeBuilding(x,y,bldType + 1,unitType);
    }
    else {
      ovc23_placeBuilding(x,y,bldType,unitType);
    }
    bVar2 = ovr_ovc45_getUnitType(x,y + 1);
    iVar3 = (uint)bVar2 * 0x27;
    if (*(char *)(iVar3 + 0x11e) == '\x01') {
      iVar3 = y + 1;
      ovc23_placeBuilding(x,iVar3,bVar2 + 2,unitType);
    }
    uVar4 = CONCAT11((char)((uint)iVar3 >> 8),1);
  }
  else if (cVar1 == '!') {
    bVar2 = ovr_ovc45_getUnitType(x + -1,y);
    uVar4 = (uint)bVar2 * 0x27;
    if (*(char *)(uVar4 + 0x11e) == '\x02') {
      uVar4 = x - 1;
      ovc23_placeBuilding(uVar4,y,bVar2 + 1,unitType);
    }
    uVar4 = uVar4 & 0xff00;
  }
  else if (cVar1 == '\"') {
    bVar2 = ovr_ovc45_getUnitType(x,y + 1);
    uVar4 = (uint)bVar2 * 0x27;
    if (*(char *)(uVar4 + 0x11e) == '\x01') {
      uVar4 = y + 1;
      ovc23_placeBuilding(x,uVar4,bVar2 + 2,unitType);
    }
    uVar4 = uVar4 & 0xff00;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}



/* 55fe:2da3 */

/* Scans four columns from alignUp4(x) for a cell with clear low flag bits and returns its x, else
   -1. */

int __cdecl16far ovc23_findClearColumn(int x,int y)

{
  uint uVar1;
  int iVar2;
  
  if (((*(short (*) [60] [148])GMapFlags)[y + 1][x] & 3U) != 0) {
    uVar1 = ovr_alignUp4(x);
    for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
      if (((*(short (*) [60] [148])GMapFlags)[y][uVar1 + iVar2 + 0x92] & 3U) == 0) {
        return uVar1 + iVar2 + -2;
      }
    }
    x = -1;
  }
  return x;
}



/* 55fe:2e2b */

/* [R7] body shape: compute */

int __cdecl16far ovc23_compute2(int x,uint16_t y)

{
  int iVar1;
  
  iVar1 = ovc23_findClearColumn(x,y);
  if (iVar1 < 0) {
    iVar1 = x;
  }
  return iVar1;
}



/* 55fe:2e4c */

/* Drowns the units at (x,y): marks the cell and reports each drowning. */

void __cdecl16far ovc23_drownUnitsAt(uint16_t x,uint16_t y)

{
  uint *puVar1;
  char *msg;
  uint16_t dst;
  uint entityIndex;
  undefined2 uVar2;
  char *unaff_SS;
  uint8_t text2;
  uint8_t text;
  uint16_t uStack_6;
  byte bStack_3;
  
  puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[y + 1] + x);
  *puVar1 = *puVar1 | 3;
  entityIndex = EntityCount;
  while (entityIndex = entityIndex - 1, -1 < (int)entityIndex) {
    uVar2 = (undefined2)((ulong)Entities >> 0x10);
    if (((((entity_t *)Entities + entityIndex)->base).x == x) &&
       (((entity_t *)Entities)[entityIndex].base.y == y)) {
      uStack_6 = ovc23_findClearColumn(x,y);
      uVar2 = (undefined2)((ulong)Entities >> 0x10);
      if ((int)uStack_6 < 0) {
        bStack_3 = ((entity_t *)Entities)[entityIndex].base.gindex;
        if (*(char *)((int)(char **)GMenuStrings + (uint)bStack_3 * 0x95 + 0x1f) == '\0') {
          dst = 0x195d;
          ovr_ovc15_capitalize((char *)CONCAT22(unaff_SS,&text2));
          msg = ovr_stsprintf((char *)&text,unaff_SS,(char *)"%s unit drowns.  (%d, %d)");
          ovr_uiNotify(msg,dst);
        }
        ovr_ovc15_removeEntity(entityIndex);
      }
      else {
        (((entity_t *)Entities + entityIndex)->base).x = uStack_6;
      }
    }
  }
  return;
}



/* 55fe:2f90 */

/* [R6] touches GRecordCount */

undefined2 __cdecl16far ovc23_usesGRecordCount3(byte amount,byte partyIndex,int recordIndex)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint16_t unaff_SS;
  byte bStack_8;
  uint8_t loopIndex;
  byte bStack_5;
  byte bStack_4;
  
  uVar3 = (uint)amount;
  bStack_8 = amount;
  _fmemset(&loopIndex,unaff_SS,0);
  for (uVar5 = 0; uVar5 < GRecordCount; uVar5 = uVar5 + 1) {
    if (*(byte *)(uVar5 * 0x12 + 9) == partyIndex) {
      if ((*(byte *)(uVar5 * 0x12 + 0xd) & 4) != 0) {
        loopIndex = loopIndex + 0x1;
      }
      if ((*(byte *)(uVar5 * 0x12 + 0xd) & 8) != 0) {
        bStack_5 = bStack_5 + 1;
      }
      if ((*(byte *)(uVar5 * 0x12 + 0xd) & 0x10) != 0) {
        bStack_4 = bStack_4 + 1;
      }
    }
  }
  if (bStack_4 < *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x9c)) {
    bStack_8 = (byte)((ulong)((long)(int)uVar3 * 7) / 10);
    iVar4 = recordIndex * 0x12;
    *(byte *)(iVar4 + 0xd) = *(byte *)(iVar4 + 0xd) | 0x10;
  }
  else if (bStack_5 < *(byte *)((int)*(undefined4 *)((uint)partyIndex << 2) + 0x9b)) {
    bStack_8 = (byte)((uVar3 << 3) / 100);
    iVar4 = recordIndex * 0x12;
    *(byte *)(iVar4 + 0xd) = *(byte *)(iVar4 + 0xd) | 8;
  }
  else {
    uVar2 = *(undefined4 *)((uint)partyIndex << 2);
    bVar1 = *(byte *)((int)uVar2 + 0x9a);
    iVar4 = CONCAT11((char)(((uint)partyIndex << 2) >> 8),bVar1);
    if (loopIndex < bVar1) {
      bStack_8 = (byte)((ulong)((long)(int)uVar3 * 9) / 10);
      iVar4 = recordIndex * 0x12;
      *(byte *)(iVar4 + 0xd) = *(byte *)(iVar4 + 0xd) | 4;
    }
  }
  return CONCAT11((char)((uint)iVar4 >> 8),bStack_8);
}



/* 55fe:3450 */

/* rounds a byte offset up to the next multiple of four */

uint __cdecl16far alignUp4(int value)

{
  return value + 2U & 0xfffc;
}


