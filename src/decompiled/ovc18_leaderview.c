/*
 * ovc18_leaderview.c - recovered from STRONG.EXE
 * memory block: OVC18_leaderview.c
 * range: 48ac:0000 - 48ac:150f
 * functions: 9
 */
#include "recovered.h"


/* 48ac:0000 */

/* Blits the trianglsCut4 graphic to the screen and sets its loaded flag. */

void __cdecl16far ovc18_blitTriangles(void)

{
  far_t gfx;
  
  gfx.seg = trianglsCut4Seg;
  gfx.ofs = trianglsCut4Ofs;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c306)));
  trianglesShown = 1;
  return;
}



/* 48ac:0027 */

/* Blits the nwpanel1Cut4 panel to the screen when GameRunning is clear. */

void __cdecl16far ovc18_blitPanelIfNotRunning(void)

{
  far_t gfx;
  
  if (!GameRunning) {
    gfx.seg = nwpanel1Cut4Seg;
    gfx.ofs = nwpanel1Cut4Ofs;
    ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa000c306)));
  }
  return;
}



/* 48ac:0051 */

/* Shows the "View %s." description and graphics for the leader standing on the cursor cell. */

void __cdecl16far ovc18_showLeaderView(void)

{
  bool bVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  uint16_t unaff_SI;
  int iVar5;
  uint unaff_SS;
  uint8_t partyCounts;
  char *pcStack_6;
  uint16_t uStack_4;
  
  trianglesShown = 0;
  if ((MsgShown != '\0') || (GameRunning)) {
    MsgShown = '\0';
  }
  else {
    _fmemset((void *)(ulong)unaff_SS,2,unaff_SI);
    for (iVar5 = 0; iVar5 < (int)(uint)GLeaderCount; iVar5 = iVar5 + 1) {
      if (((((char_sheet_t *)((iVar5 << 2)))->active != '\0') &&
          ((&partyCounts)[*(byte *)((int)*(uint32_t *)(iVar5 << 2) + 0x3f)] =
                (&partyCounts)[*(byte *)((int)*(uint32_t *)(iVar5 << 2) + 0x3f)] + 0x1,
          ((char_sheet_t *)((iVar5 << 2)))->x == GfxRndSeed)) &&
         (((char_sheet_t *)((iVar5 << 2)))->y == GfxRndSeed2)) {
        bVar1 = ovr_draw_textArena();
        if (!bVar1) {
          return;
        }
        uStack_4 = ((uint16_t *)(iVar5 * 4))[1];
        pcVar4 = (char *)*(uint16_t *)(iVar5 * 4);
        pcStack_6 = pcVar4;
        if (GameRunning == false) {
          pcVar2 = ovr_fmVsprintf("View %s.",(char *)CONCAT22(uStack_4,pcVar4));
          ovr_say(pcVar2,pcVar4);
        }
        ovc18_blitTriangles();
        return;
      }
    }
    if (PartyCount != 0) {
      uStack_4 = *(uint16_t *)((uint)PartyCount * 4 + -2);
      pcVar4 = (char *)*(uint16_t *)((uint)PartyCount * 4 + -4);
      pcStack_6 = pcVar4;
      uVar3 = ovc18_usesAlignUp4();
      if ((char)uVar3 == '\0') {
        pcVar2 = ovr_fmVsprintf("View %s. (Cannot place)",(char *)CONCAT22(uStack_4,pcStack_6));
        ovr_say(pcVar2,pcVar4);
      }
      else {
        pcVar2 = ovr_fmVsprintf("Place %s.",(char *)CONCAT22(uStack_4,pcStack_6));
        ovr_say(pcVar2,pcVar4);
      }
      trianglesShown = 1;
      ovc18_blitTriangles();
      return;
    }
    if (CurPartySlot < PartySize) {
      if (GameRunning == false) {
        if (CurPartySlot == 0) {
          ovr_say((char *)"Create baron or baroness.",0x2410);
        }
        else {
          ovr_say((char *)"Create party member.",0x2410);
        }
      }
      trianglesShown = 1;
      ovc18_blitTriangles();
      return;
    }
  }
  ovc18_blitPanelIfNotRunning();
  return;
}



/* 48ac:0251 */
uint8_t * __cdecl16far
ovc18_spawnClassAgent
          (uint16_t x,uint16_t y,uint16_t destX,uint16_t destY,uint8_t classStr,uint8_t partyIndex,
          uint16_t mode)

{
  undefined1 uVar1;
  char cVar2;
  uint32_t uVar3;
  uint32_t *puVar4;
  uint8_t *txt;
  far_t far *pfVar5;
  uint16_t uVar6;
  entity_t *peVar7;
  far_t far *pfVar8;
  uint16_t uVar9;
  uint16_t uVar10;
  uint16_t unaff_BP;
  uint16_t unaff_SI;
  uint uVar11;
  far_t far *unaff_DI;
  far_t far *pfVar12;
  char *unaff_SS;
  far_t far *in_stack_00000004;
  char acStackY_56 [46];
  uint8_t *puStackY_28;
  uint16_t uStackY_26;
  uint8_t far *uStackY_24;   /* was uint32_t: assigned uint8_t * values */
  far_t far *pfStackY_20;
  far_t far *pfVar13;
  far_t far *in_stack_0000ffe8;
  uint16_t in_stack_0000ffec;
  char *in_stack_0000ffee;
  int iVar14;
  char *filename;
  char *pcVar15;
  far_t far *pfVar16;
  uint32_t in_stack_0000fffa;
  byte bVar17;
  
  bVar17 = ((char_sheet_t *)(((uint)classStr << 2)))->classStr;
  filename = (char *)CONCAT13((char)((ulong)in_stack_0000fffa >> 0x18),CONCAT12(bVar17,unaff_SI));
  uVar10 = 0x195d;
  if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)bVar17 * 0x95) & 0x800) == 0) {
    if ((byte)destY < 6) {
      bVar17 = 6;
    }
    else if ((byte)destY < 0xb) {
      bVar17 = 0x19;
    }
    else {
      bVar17 = 0x13;
    }
    peVar7 = ovr_ovc15_usesLDIV_at_
                       ((uint16_t)in_stack_00000004,x,y,destX,bVar17,
                        *(uint8_t *)((int)*(uint32_t *)((uint)classStr << 2) + 0xa4),classStr);
  }
  else {
    iVar14 = 5;
    uVar6 = ovr_randBelow(5);
    pfVar8 = (far_t far *)(uVar6 & 0xff);
    pfVar12 = (far_t far *)0x0;
    pfVar5 = in_stack_00000004;
    switch((uint16_t)pfVar8)   /* hand fix: case values are ints */ {
    case (uint16_t)0x0:
      do {
        if (199 < iVar14 + (uint)*(byte *)(y + (int)pfVar8 * uVar10 + 10)) {
          filename = (char *)CONCAT22((int)((ulong)filename >> 0x10) +
                                      (uint)*(byte *)(y + (int)pfVar5 * 0x1e + 9),
                                      (char *)(*(int *)(y + (int)pfVar5 * 0x1e + 3) %
                                              (int)(uint)*(byte *)(y + (int)pfVar5 * 0x1e + 10)));
          unaff_DI = (far_t far *)((int)&unaff_DI->ofs + (uint)*(byte *)(y + (int)pfVar5 * 0x1e + 9));
          in_stack_0000ffe8 =
               (far_t far *)CONCAT22((int)((ulong)in_stack_0000ffe8 >> 0x10) +
                                 (uint)*(byte *)(y + (int)pfVar5 * 0x1e + 9),
                                 (far_t far *)((int)&((far_t far *)in_stack_0000ffe8)->ofs +
                                          (uint)*(byte *)(y + (int)pfVar5 * 0x1e + 9)));
        }
        uVar11 = in_stack_0000ffec + 1;
        pfVar8 = pfVar5;
        while (uVar9 = (uint16_t)((ulong)((long)(int)pfVar8 * 0x1e) >> 0x10),
              *(byte *)(y + (int)((long)(int)pfVar8 * 0x1e) + 0x1b) <= uVar11) {
          if ((char *)in_stack_0000ffee != (char *)0x0 ||
              (int)((ulong)in_stack_0000ffee >> 0x10) != 0) {
            *in_stack_0000ffee = (char)in_stack_0000ffe8 - (char)((ulong)in_stack_0000ffe8 >> 0x10);
          }
          pfVar8 = (far_t far *)((int)&pfVar8->ofs + 1);
          if ((destY <= pfVar8) || (*(char *)(y + (int)pfVar8 * 0x1e + 0x1b) == '\0')) {
            return puStackY_28;
          }
          uVar11 = (uint)*(byte *)(y + (int)pfVar8 * 0x1e);
          uStackY_24 = (uint8_t *)CONCAT22(uStackY_26,puStackY_28 + uVar11 * 4 + 0x58);
          *(uint16_t *)((int)(puStackY_28 + uVar11 * 4) + 2) = destX;
          *(uint16_t *)(puStackY_28 + uVar11 * 4) = y + (int)pfVar8 * 0x1e;
          pcVar15 = (char *)*(int *)(y + (int)pfVar8 * 0x1e + 3);
          filename = (char *)CONCAT22(*(uint16_t *)(y + (int)pfVar8 * 0x1e + 1),pcVar15);
          unaff_DI = (far_t far *)*(uint16_t *)(y + (int)pfVar8 * 0x1e + 5);
          if (*(int *)(y + (int)pfVar8 * 0x1e + 7) - (int)pcVar15 < 0) {
                    /* WARNING: Subroutine does not return */
            ovr_stExit(0x33);
          }
          in_stack_0000ffee = (char *)0x0;
          uVar11 = 0;
        }
        iVar14 = 0x15;
        pcVar15 = (char *)((ulong)filename >> 0x10);
        in_stack_0000ffee = (char *)CONCAT22((char *)filename,pcVar15);
        in_stack_0000ffe8 = (far_t far *)CONCAT22(in_stack_00000004,pfVar12);
        pfVar12 = (far_t far *)0x22d3;
        in_stack_0000ffec = x;
        pfVar5 = ovr_stshRleSub(in_stack_00000004,(uint8_t *)x,(uint16_t)pcVar15,
                                (uint16_t)(char *)filename,(uint16_t)unaff_DI,0x15,21);
        pfStackY_20 = (far_t far *)CONCAT22(uVar9,pfVar5);
        *(undefined1 *)&pfVar5[1].seg = 2;
        *(uint16_t *)((int)&pfVar5[1].seg + 1) = *(uint16_t *)(y + (int)pfVar8 * 0x1e + 0xb);
        *(uint16_t *)((int)&pfVar5[2].ofs + 1) = *(uint16_t *)(y + (int)pfVar8 * 0x1e + 0xd);
        *(uint16_t *)((uint8_t *)uStackY_24 + 2) = uVar9;
        *(far_t far **)uStackY_24 = pfVar5;
        uStackY_24 = (uint8_t *)CONCAT22(uVar9,(uint8_t *)((int)&pfVar5->ofs + 1));
        pfVar16 = (far_t far *)((ulong)filename >> 0x10);
        if ((*(byte *)(y + (int)pfVar8 * 0x1e + 0x1c) & 1) == 0) {
          *(undefined1 *)((int)&pfVar5[1].ofs + 1) = *(undefined1 *)(y + (int)pfVar8 * 0x1e + 0xf);
        }
        else {
          pfVar13 = pfVar16;
          if (in_stack_0000ffec == 0) {
            uVar11 = 0;
            while (uVar11 < 2) {
              if (unaff_DI + iVar14 * 0x50 + 0x50 < pfVar13) {
                    /* WARNING: Subroutine does not return */
                ovr_stExit(9);
              }
              if (*(char *)((int)&in_stack_00000004[iVar14 * 0x50 + 0x50].ofs + (int)pfVar13) == -2)
              {
                if (uVar11 == 0) {
                  in_stack_0000ffe8 = (far_t far *)CONCAT22(pfVar13,(far_t far *)in_stack_0000ffe8);
                }
                else {
                  in_stack_0000ffe8 =
                       (far_t far *)CONCAT22((int)((ulong)in_stack_0000ffe8 >> 0x10),pfVar13);
                }
                uVar11 = uVar11 + 1;
              }
              pfVar13 = (far_t far *)((int)&pfVar13->ofs + 1);
            }
            in_stack_0000ffee = (char *)CONCAT22(uVar9,(char *)((int)&pfVar5[1].ofs + 1));
          }
          else {
            for (; *(char *)((int)&in_stack_00000004[iVar14 * 0x50 + 0x50].ofs + (int)pfVar13) != -2
                ; pfVar13 = (far_t far *)((int)&pfVar13->ofs + 1)) {
              if (unaff_DI + iVar14 * 0x50 + 0x50 < pfVar13) {
                    /* WARNING: Subroutine does not return */
                ovr_stExit(9);
              }
            }
            *(char *)((int)&pfVar5[1].ofs + 1) = (char)in_stack_0000ffe8 - (char)pfVar13;
            in_stack_0000ffe8 = (far_t far *)CONCAT22((int)((ulong)in_stack_0000ffe8 >> 0x10),pfVar13);
          }
        }
        *(undefined1 *)&pfStackY_20->ofs = 4;
        *(uint16_t *)((int)&pfVar5->seg + 1) = 0;
        *(uint16_t *)((int)&pfVar5->ofs + 1) = 0;
        filename = (char *)CONCAT22(pfVar16,(char *)filename +
                                            *(byte *)(y + (int)pfVar8 * 0x1e + 10));
        uVar10 = 0x1e;
        pfVar5 = pfVar8;
      } while( true );
    case (uint16_t)0x1:
      uVar1 = in(uVar10);
      *(undefined1 *)x = uVar1;
      midpakAd.ofs = (uint16_t)stshStoreFile_2(unaff_DI,filename,unaff_BP);
      midpakAd.seg = uVar10;
      cmidpakComOfs =(uint16_t)( stshStoreFile_2((far_t *)"cmidpak.com",(char *)MK_FP(0x2410, 0x1),unaff_BP));
      cmidpakComSeg = uVar10;
      ibmsndComOfs =(uint16_t)( stshStoreFile_2((far_t *)"ibmsnd.com",(char *)MK_FP(0x2410, 0x1),unaff_BP));
      ibmsndComSeg = uVar10;
      sblasterComOfs =(uint16_t)( stshStoreFile_2((far_t *)"sblaster.com",(char *)MK_FP(0x2410, 0x1),unaff_BP));
      audioPlaceholder2.seg = 0;
      audioPlaceholder2.ofs = 0;
      sblasterComSeg = uVar10;
      fibmbakComOfs =(uint16_t)( stshStoreFile_2((far_t *)"fibmbak.com",(char *)MK_FP(0x2410, 0x1),unaff_BP));
      fibmbakComSeg = uVar10;
      pfVar8 = stshStoreFile_2((far_t *)"sbpro.com",(char *)MK_FP(0x2410, 0x1),unaff_BP);
      sbproComOfs =(uint16_t)( pfVar8);
      sbproComSeg = uVar10;
      sbproComCopyOfs =(uint16_t)( pfVar8);
      sbproComCopySeg = uVar10;
      paudioComOfs =(uint16_t)( stshStoreFile_2((far_t *)"paudio.com",(char *)MK_FP(0x2410, 0x1),unaff_BP));
      sblasterComCopySeg = sblasterComSeg;
      sblasterComCopyOfs = sblasterComOfs;
      pfVar12 = sblasterComOfs;
      paudioComSeg =(uint16_t)( pfVar8);
      adlibComOfs =(uint16_t)( stshStoreFile_2((far_t *)"adlib.com",(char *)MK_FP(0x2410, 0x1),unaff_BP));
      adlibComSeg =(uint16_t)( pfVar12);
      adlibgComOfs =(uint16_t)( stshStoreFile_2((far_t *)"adlibg.com",(char *)MK_FP(0x2410, 0x1),unaff_BP));
      audioPlaceholder3.seg = 0;
      audioPlaceholder3.ofs = 0;
      musDriver0Seg = 0;
      musDriver0Ofs = 0;
      adlibgComSeg =(uint16_t)( pfVar12);
      sbfmAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"sbfm.adv",(char *)MK_FP(0x2410, 0x1),unaff_BP));
      audioPlaceholder0.seg = 0;
      audioPlaceholder0.ofs = 0;
      audioPlaceholder1.seg = 0;
      audioPlaceholder1.ofs = 0;
      sbfmAdvSeg =(uint16_t)( pfVar12);
      sbp2fmAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"sbp2fm.adv",(char *)MK_FP(0x2410, 0x1),unaff_BP));
      sbp2fmAdvSeg =(uint16_t)( pfVar12);
      sbp1fmAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"sbp1fm.adv",(char *)MK_FP(0x2410, 0x1),unaff_BP));
      sbp1fmAdvSeg =(uint16_t)( pfVar12);
      pasfmAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"pasfm.adv",(char *)MK_FP(0x2410, 0x1),unaff_BP));
      pasfmAdvSeg =(uint16_t)( pfVar12);
      pasoplAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"pasopl.adv",(char *)MK_FP(0x2410, 0x1),unaff_BP));
      pasoplAdvSeg =(uint16_t)( pfVar12);
      adlibAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"adlib.adv",(char *)MK_FP(0x2410, 0x1),unaff_BP));
      adlibAdvSeg =(uint16_t)( pfVar12);
      adlibgAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"adlibg.adv",(char *)MK_FP(0x2410, 0x1),unaff_BP));
      adlibgAdvSeg =(uint16_t)( pfVar12);
      mt32mpuAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"mt32mpu.adv",(char *)MK_FP(0x2410, 0x1),unaff_BP));
      mt32mpuAdvSeg =(uint16_t)( pfVar12);
      return (uint8_t *)mt32mpuAdvOfs;
    case (uint16_t)0x2:
      iVar14 = ovr_ovc23_findClearColumn(GfxRndSeed,GfxRndSeed2);
      if (iVar14 < 0) {
        ovr_drawTextAt((char *)"You cannot attract units to this location.",0x2410);
        txt = (uint8_t *)((char *)0x26510);
        *(undefined1 *)&in_stack_00000004[-0x1be0].seg = 0;
      }
      else {
        callResultTemp = sub_OVC21_manage_c_24B1();
        if (callResultTemp < (char *)filename) {
          filename = (char *)CONCAT22((int)((ulong)filename >> 0x10),callResultTemp);
          *(char *)&in_stack_00000004[-0x1be0].seg = (char)callResultTemp;
        }
        puVar4 = (uint32_t *)((uint)(byte)((ulong)filename >> 0x10) << 2);
        uVar3 = *puVar4;
        cVar2 = *(char *)((int)uVar3 + 0x2f);
        txt = (uint8_t *)CONCAT11((char)((uint)puVar4 >> 8),cVar2);
        pcVar15 = (char *)filename;
        if (cVar2 != -1) {
          ovr_ovc41_pluralSuffix((int)pcVar15);
          uVar10 = 0x2410;
          pfStackY_20 = (far_t far *)CONCAT22(acStackY_56,0x23d5);
          uStackY_24 = (uint8_t *)CONCAT22(0xad0,(uint8_t *)uStackY_24);
          txt = (uint8_t *)
                ovr_stsprintf(acStackY_56,(char *)CONCAT22(0x921,unaff_SS),
                              (char *)CONCAT22(pcVar15,(char *)0x26510));
          ovr_drawTextAt((char *)txt,uVar10);
        }
      }
      return txt;
    case (uint16_t)0x3:
      ((int *)StshHandles)[(int)in_stack_00000004] = (int)pfVar8;
      *(uint16_t *)((int)(long *)StshPtrs + (int)in_stack_00000004 * 4 + 2) = 0;
      *(uint16_t *)((long *)StshPtrs + (int)in_stack_00000004) = 0;
      return (uint8_t *)in_stack_00000004;
    case (uint16_t)0x4:
      smm_restore_state();
      return (uint8_t *)pfVar8;
    default:
      bVar17 = (byte)((ulong)filename >> 0x18);
      if (partyIndex == 0x2) {
        peVar7 = ovr_ovc15_usesLDIV_at_((uint16_t)in_stack_00000004,x,y,destX,bVar17,0xa,classStr);
      }
      else {
        peVar7 = ovr_ovc15_usesLDIV_at_
                           ((uint16_t)in_stack_00000004,x,y,destX,bVar17,
                            *(uint8_t *)((int)*(uint32_t *)((uint)classStr << 2) + 0xa4),classStr)
        ;
      }
    }
  }
  return (uint8_t *)peVar7;
}


/* 48ac:0382 */
char * __cdecl16far
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


/* 48ac:05f2 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Checks a fortress site and reports the matching rejection message. */

void __cdecl16far ovc18_checkFortressPlacement(char strongholdKind,...)

{
  undefined1 stk_ffea;   /* stack slot ffea */
  undefined1 stk_ffec;   /* stack slot ffec */
  uint32_t uVar1;
  far_t dst;
  bool bVar2;
  uint uVar3;
  char *pcVar4;
  undefined1 *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint16_t unaff_DI;
  uint16_t uVar10;
  uint16_t unaff_SS;
  undefined1 uVar11;
  undefined1 uVar12;
  char partyIndex;
  undefined1 auStack_12 [13];
  uint8_t uStack_5;
  uint uStack_4;
  
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = (char)unaff_SS;
  dst.ofs = (uint16_t)auStack_12;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = (char)((uint)unaff_SS >> 8);
  F_SCOPY(far_from_u32((uint32_t)(0x241045b9)),dst);
  for (uVar8 = 0; partyIndex = (char)unaff_DI, uVar8 < EntityCount; uVar8 = uVar8 + 1) {
    uVar10 = (uint16_t)((ulong)Entities >> 0x10);
    if (*(char *)((int)(char **)GMenuStrings +
                 (uint)((entity_t *)Entities)[uVar8].base.gindex * 0x95 + 0x1f) != '\0') {
      uVar3 = ovr_alignUp4(*(int *)((int)Entities + uVar8 * 0x37));
      uVar11 = (undefined1)uVar3;
      uVar12 = (undefined1)(uVar3 >> 8);
      uVar3 = ovr_alignUp4(GfxRndSeed);
      if ((CONCAT11(uVar12,uVar11) == uVar3) &&
         (((entity_t *)Entities)[uVar8].base.y == GfxRndSeed2)) {
        ovr_stats_openCastlePanel();
        ovr_say((char *)"A fortress cannot be placed among enemy units.",0x10);
        MsgShown = 1;
        return;
      }
    }
  }
  for (iVar9 = 0; iVar9 < (int)(uint)GLeaderCount; iVar9 = iVar9 + 1) {
    if (((((char_sheet_t *)((iVar9 << 2)))->active != '\0') &&
        (((char_sheet_t *)((iVar9 << 2)))->x == GfxRndSeed)) &&
       (((char_sheet_t *)((iVar9 << 2)))->y == GfxRndSeed2)) {
      ovr_stats_openCastlePanel();
      ovr_say((char *)"Cannot place another fortress here.",0x10);
      MsgShown = 1;
      return;
    }
  }
  if (strongholdKind == '\x02') {
    uVar8 = ovr_constr_usesGMapFlags(GfxRndSeed - 2,GfxRndSeed2,(char)GfxRndSeed2);
    if ((((uVar8 & 0xff) == 0) ||
        (uVar8 = ovr_constr_usesGMapFlags(GfxRndSeed - 1,GfxRndSeed2,(char)GfxRndSeed2),
        (uVar8 & 0xff) == 0)) ||
       ((uVar8 = ovr_constr_usesGMapFlags(GfxRndSeed,GfxRndSeed2,(char)GfxRndSeed2),
        (uVar8 & 0xff) == 0 ||
        (uVar8 = ovr_constr_usesGMapFlags(GfxRndSeed + 1,GfxRndSeed2,(char)GfxRndSeed2),
        (uVar8 & 0xff) == 0)))) {
      ovr_stats_openCastlePanel();
      puVar5 = &stk_ffea;
      pcVar4 = ovr_fmVsprintf("This location is unsuitable for a main stronghold.  %s",
                              (char *)CONCAT13((char)((uint)*(uint16_t *)
                                                             (&stk_ffec +
                                                             (uint)placementStatus * 4) >> 8),
                                               CONCAT12((char)*(uint16_t *)
                                                               (&stk_ffec +
                                                               (uint)placementStatus * 4),
                                                        *(uint16_t *)
                                                         (puVar5 + (uint)placementStatus * 4))));
      ovr_say(pcVar4,(char)puVar5);
      MsgShown = 1;
      return;
    }
  }
  else {
    uVar8 = ovr_constr_usesGMapFlags(GfxRndSeed - 1,GfxRndSeed2,(char)GfxRndSeed2);
    if (((uVar8 & 0xff) == 0) ||
       (uVar8 = ovr_constr_usesGMapFlags(GfxRndSeed,GfxRndSeed2,(char)GfxRndSeed2),
       (uVar8 & 0xff) == 0)) {
      ovr_stats_openCastlePanel();
      puVar5 = &stk_ffea;
      pcVar4 = ovr_fmVsprintf("This location is unsuitable.  %s",
                              (char *)CONCAT13((char)((uint)*(uint16_t *)
                                                             (&stk_ffec +
                                                             (uint)placementStatus * 4) >> 8),
                                               CONCAT12((char)*(uint16_t *)
                                                               (&stk_ffec +
                                                               (uint)placementStatus * 4),
                                                        *(uint16_t *)
                                                         (puVar5 + (uint)placementStatus * 4))));
      ovr_say(pcVar4,(char)puVar5);
      MsgShown = 1;
      return;
    }
  }
  bVar2 = ovr_draw_textArena();
  if (bVar2) {
    if (1 < CurPartySlot) {
      uStack_4 = 0xffff;
      for (iVar9 = 0; iVar9 < (int)(uint)GLeaderCount; iVar9 = iVar9 + 1) {
        if (((((char_sheet_t *)((iVar9 << 2)))->active != '\0') &&
            (*(char *)((int)*(uint32_t *)(iVar9 << 2) + 0x3f) == '\0')) &&
           (uVar8 = ((char_sheet_t *)((iVar9 << 2)))->x - GfxRndSeed,
           uVar6 = (int)uVar8 >> 0xf,
           uVar3 = ((char_sheet_t *)((iVar9 << 2)))->y - GfxRndSeed2,
           uVar7 = (int)uVar3 >> 0xf, uVar8 = ((uVar8 ^ uVar6) - uVar6) + ((uVar3 ^ uVar7) - uVar7),
           uVar8 < uStack_4)) {
          uStack_4 = uVar8;
        }
      }
      if (0x1e < uStack_4) {
        ovr_stats_openCastlePanel();
        ovr_say((char *)"Your stronghold is too far away.",0x10);
        MsgShown = 1;
        return;
      }
    }
    uVar1 = *(uint32_t *)((uint)PartyCount * 4 + -4);
    *(uint16_t *)((int)uVar1 + 0x39) = GfxRndSeed;
    uVar1 = *(uint32_t *)((uint)PartyCount * 4 + -4);
    *(uint16_t *)((int)uVar1 + 0x3b) = GfxRndSeed2;
    uVar1 = *(uint32_t *)((uint)PartyCount * 4 + -4);
    *(undefined1 *)((int)uVar1 + 0x3d) = 1;
    uVar1 = *(uint32_t *)((uint)PartyCount * 4 + -4);
    *(char *)((int)uVar1 + 0x89) = CurPartySlot - 1;
    if (strongholdKind == '\x02') {
      uVar1 = *(uint32_t *)((uint)PartyCount * 4 + -4);
      *(undefined1 *)((int)uVar1 + 0x5a) = 1;
      ovr_createConstructionRecordFar
                (0x89,GfxRndSeed - 2,GfxRndSeed2,(uint8_t *)CONCAT22(unaff_SS,&uStack_5),
                 PartyCount - 1,partyIndex,(char)GfxRndSeed2,(char)&uStack_5,PartyCount - 1);
      ovc18_textTypeLen(PartyCount - 1,GfxRndSeed,GfxRndSeed2,0x0,(char)GfxRndSeed);
      ovr_ovc22_usesRandBelow2(PartyCount - 1,(uint16_t)&uStack_5);
    }
    else {
      uVar1 = *(uint32_t *)((uint)PartyCount * 4 + -4);
      *(char *)((int)uVar1 + 0x5a) = strongholdKind;
      uVar1 = *(uint32_t *)((uint)PartyCount * 4 + -4);
      ovr_createConstructionRecordFar
                (*(byte *)((int)(far_t *)(worldMenuLabels + 0xb) +
                          (uint)*(byte *)((int)uVar1 + 0x3e) * 0x95),GfxRndSeed - 1,GfxRndSeed2,
                 (uint8_t *)CONCAT22(unaff_SS,&uStack_5),PartyCount - 1,partyIndex,(char)GfxRndSeed2
                 ,(char)&uStack_5,PartyCount - 1);
      ovc18_textTypeLen(PartyCount - 1,GfxRndSeed,GfxRndSeed2,0x0,(char)GfxRndSeed);
    }
    if (2 < Difficulty) {
      ovr_ovc22_usesRandBelow2(PartyCount - 1,(uint16_t)&uStack_5);
    }
    ovr_ovc22_textRingProt(PartyCount - 1);
    PartyCount = 0;
    ovr_manage_mapPartySlots();
    ovr_stats_openCastlePanel();
    ovr_unit_usesAlignUp4();
    ovr_say((char *)0x286cd,0x10);
    if (PlayerIndex == '\0') {
      ovr_ovc30_nextWave(2);
    }
  }
  else {
    ovr_stats_openCastlePanel();
    ovr_say((char *)"Your stronghold is too far away.",0x10);
    MsgShown = 1;
  }
  return;
}



/* 48ac:0bf4 */

/* [R4] calls ovr_randBelow */

uint __cdecl16far ovc18_usesRandBelow(int x,int y,byte bldType,byte unitType,...)

{
  uint *puVar1;
  uint uVar2;
  uint16_t uVar3;
  short (*paasVar4) [148] [60];
  uint unaff_SI;
  uint16_t uVar5;
  uint16_t uVar6;
  uint uStack_6;
  
  paasVar4 = (short (*) [148] [60])GUnitGrid;
  uVar6 = (uint16_t)((ulong)GUnitGrid >> 0x10);
  uVar5 = (uint16_t)((ulong)GUnits >> 0x10);
  if (bldType == 0) {
    if ((uint)(*paasVar4)[x][y] < 0xf8) {
      (*paasVar4)[x][y] = 0;
    }
    else {
      unaff_SI = (*paasVar4)[x][y];
      ((unit_t *)GUnits + unaff_SI)->bldType = 0;
      ((unit_t *)GUnits)[unaff_SI].level = 8;
      ((unit_t *)GUnits)[unaff_SI].unitType = 0xff;
      (*(short (*) [148] [60])GUnitGrid)[x][y] = 0;
    }
    puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[y] + x);
    *puVar1 = *puVar1 & 0x3fff;
  }
  else {
    if ((uint)(*paasVar4)[x][y] < 0xf8) {
      unaff_SI = 0xf8;
      while ((unaff_SI < GUnitCount && (((unit_t *)GUnits + unaff_SI)->bldType != 0))) {
        unaff_SI = unaff_SI + 1;
      }
      if (GUnitCount <= unaff_SI) {
        if (GUnitCount + 1 < 0x4b0) {
          GUnitCount = GUnitCount + 1;
        }
        else {
          uVar3 = ovr_randBelow(0x3b8);
          uVar2 = (uVar3 & 0xff) + 0xf8;
          unaff_SI = uVar2;
          do {
            if ((((*(uint *)((uint8_t *)&BuildingTypes[unaff_SI] + 19) & 0xa0) != 0) ||
                (*(char *)((uint8_t *)&BuildingTypes[unaff_SI] + 37) == '\0')) ||
               (*(char *)((uint8_t *)&BuildingTypes[unaff_SI] + 37) == '\a')) break;
            unaff_SI = unaff_SI + 1;
            if (0x4af < unaff_SI) {
              unaff_SI = 0xf8;
            }
          } while (uVar2 != unaff_SI);
          for (uStack_6 = 0; uStack_6 < 0x94; uStack_6 = uStack_6 + 1) {
            for (uVar2 = 0; uVar2 < 0x3c; uVar2 = uVar2 + 1) {
              uVar6 = (uint16_t)((ulong)GUnitGrid >> 0x10);
              if ((*(short (*) [148] [60])GUnitGrid)[uStack_6][uVar2] == unaff_SI) {
                (*(short (*) [148] [60])GUnitGrid)[uStack_6][uVar2] = 0;
              }
            }
          }
        }
      }
    }
    else {
      unaff_SI = (*paasVar4)[x][y];
    }
    ((unit_t *)GUnits + unaff_SI)->bldType = bldType;
    ((unit_t *)GUnits)[unaff_SI].level = 8;
    ((unit_t *)GUnits)[unaff_SI].unitType = unitType;
    ((unit_t *)GUnits)[unaff_SI].x = x;
    ((unit_t *)GUnits)[unaff_SI].y = y;
    (*(short (*) [148] [60])GUnitGrid)[x][y] = unaff_SI;
    uVar6 = (uint16_t)((ulong)GMapFlags >> 0x10);
    (*(short (*) [60] [148])GMapFlags)[y][x] =
         (*(short (*) [60] [148])GMapFlags)[y][x] & 0x3fffU |
         (uint)*(byte *)((uint)bldType * 0x27 + 0x11e) << 0xe;
    if ((*(uint *)((uint)bldType * 0x27 + 0x121) & 0x40) == 0) {
      ((unit_t *)GUnits)[unaff_SI].timer = 0;
    }
    else {
      uVar2 = ovr_constr_usesGMapFlags2(x,y);
      if ((uVar2 & 0xff) == 3) {
        uVar3 = ovr_randBelow(0x28);
        ((unit_t *)GUnits)[unaff_SI].timer = (char)uVar3 + 0x1e;
      }
      else if ((uVar2 & 0xff) == 4) {
        uVar3 = ovr_randBelow(0x50);
        ((unit_t *)GUnits)[unaff_SI].timer = (char)uVar3 + 0x3c;
      }
      else {
        uVar3 = ovr_randBelow(0x14);
        ((unit_t *)GUnits)[unaff_SI].timer = (char)uVar3 + 0xf;
      }
    }
  }
  return unaff_SI;
}



/* 48ac:1022 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R2] string "arena" */

bool __cdecl16far ovc18_textArena(uint16_t x,uint16_t y,...)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = ovr_alignUp4(x);
  uVar3 = 0;
  while( true ) {
    if (EntityCount <= uVar3) {
      return false;
    }
    uVar2 = ovr_alignUp4(*(int *)((int)Entities + uVar3 * 0x37));
    if ((uVar2 == uVar1) && (((entity_t *)Entities)[uVar3].base.y == y)) break;
    uVar3 = uVar3 + 1;
  }
  return true;
}



/* 48ac:1092 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

uint __cdecl16far ovc18_usesAlignUp4(void)

{
  bool inArena;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int leaderIdx;
  uint16_t uVar7;
  uint bestDist;
  
  inArena = ovr_draw_textArena();
  if (inArena) {
    for (uVar5 = 0; uVar5 < EntityCount; uVar5 = uVar5 + 1) {
      uVar7 = (uint16_t)((ulong)Entities >> 0x10);
      if (*(char *)((int)(char **)GMenuStrings +
                   (uint)((entity_t *)Entities)[uVar5].base.gindex * 0x95 + 0x1f) != '\0') {
        uVar2 = ovr_alignUp4(*(int *)((int)Entities + uVar5 * 0x37));
        uVar3 = ovr_alignUp4(GfxRndSeed);
        if ((uVar2 == uVar3) &&
           (uVar2 = ((entity_t *)Entities)[uVar5].base.y, uVar2 == GfxRndSeed2)) {
          return uVar2 & 0xff00;
        }
      }
    }
    for (leaderIdx = 0; leaderIdx < (int)(uint)GLeaderCount; leaderIdx = leaderIdx + 1) {
      if (((((char_sheet_t *)((leaderIdx << 2)))->active != '\0') &&
          (((char_sheet_t *)((leaderIdx << 2)))->x == GfxRndSeed)) &&
         (uVar5 = ((char_sheet_t *)((leaderIdx << 2)))->y, uVar5 == GfxRndSeed2)) {
        return uVar5 & 0xff00;
      }
    }
    uVar5 = ovr_constr_usesGMapFlags(GfxRndSeed + -1,GfxRndSeed2);
    if (((uVar5 & 0xff) == 0) ||
       (uVar5 = ovr_constr_usesGMapFlags(GfxRndSeed,GfxRndSeed2), (uVar5 & 0xff) == 0)) {
      uVar5 = 0;
    }
    else if ((CurPartySlot == 1) &&
            ((uVar5 = ovr_constr_usesGMapFlags(GfxRndSeed + -2,GfxRndSeed2), (uVar5 & 0xff) == 0 ||
             (uVar5 = ovr_constr_usesGMapFlags(GfxRndSeed + 1,GfxRndSeed2), (uVar5 & 0xff) == 0))))
    {
      uVar5 = 0;
    }
    else {
      uVar5 = 0x2410;
      if (1 < CurPartySlot) {
        bestDist = 0xffff;
        for (leaderIdx = 0; uVar5 = (uint)GLeaderCount, leaderIdx < (int)uVar5; leaderIdx = leaderIdx + 1) {
          if (((((char_sheet_t *)((leaderIdx << 2)))->active != '\0') &&
              (*(char *)((int)*(uint32_t *)(leaderIdx << 2) + 0x3f) == '\0')) &&
             (uVar5 = ((char_sheet_t *)((leaderIdx << 2)))->x - GfxRndSeed,
             uVar3 = (int)uVar5 >> 0xf,
             uVar2 = ((char_sheet_t *)((leaderIdx << 2)))->y - GfxRndSeed2,
             uVar4 = (int)uVar2 >> 0xf,
             uVar5 = ((uVar5 ^ uVar3) - uVar3) + ((uVar2 ^ uVar4) - uVar4), uVar5 < bestDist)) {
            bestDist = uVar5;
          }
        }
        if (0x1e < bestDist) {
          return 0;
        }
      }
      uVar5 = CONCAT11((char)(uVar5 >> 8),1);
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}


