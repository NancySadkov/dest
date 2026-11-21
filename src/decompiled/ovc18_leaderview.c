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
  uint16_t unaff_BP;
  far_t gfx;
  far_t dst;
  
  dst.seg = unaff_BP;
  dst.ofs = 0xa000;
  gfx.seg = 0xc306;
  gfx.ofs = trianglsCut4Seg;
  ovr_blitLoadRleGfx(gfx,dst,trianglsCut4Ofs);
  trianglesShown = 1;
  return;
}



/* 48ac:0027 */

/* Blits the nwpanel1Cut4 panel to the screen when GameRunning is clear. */

void __cdecl16far ovc18_blitPanelIfNotRunning(void)

{
  uint16_t unaff_BP;
  far_t gfx;
  far_t dst;
  
  if (!GameRunning) {
    dst.seg = unaff_BP;
    dst.ofs = 0xa000;
    gfx.seg = 0xc306;
    gfx.ofs = nwpanel1Cut4Seg;
    ovr_blitLoadRleGfx(gfx,dst,nwpanel1Cut4Ofs);
  }
  return;
}



/* 48ac:0051 */

/* Shows the "View %s." description and graphics for the leader standing on the cursor cell. */

void __cdecl16far ovc18_showLeaderView(void)

{
  bool bVar1;
  uint uVar2;
  uint16_t unaff_SI;
  int iVar3;
  uint unaff_SS;
  uint8_t partyCounts;
  undefined2 uStack_6;
  char *pcStack_4;
  
  trianglesShown = 0;
  if ((MsgShown != '\0') || (GameRunning)) {
    MsgShown = '\0';
  }
  else {
    _fmemset((void *)(ulong)unaff_SS,2,unaff_SI);
    for (iVar3 = 0; iVar3 < (int)(uint)GLeaderCount; iVar3 = iVar3 + 1) {
      if (((*(char *)((int)*(undefined4 *)(iVar3 << 2) + 0x3d) != '\0') &&
          ((&partyCounts)[*(byte *)((int)*(undefined4 *)(iVar3 << 2) + 0x3f)] =
                (&partyCounts)[*(byte *)((int)*(undefined4 *)(iVar3 << 2) + 0x3f)] + 0x1,
          *(int *)((int)*(undefined4 *)(iVar3 << 2) + 0x39) == GfxRndSeed)) &&
         (*(int *)((int)*(undefined4 *)(iVar3 << 2) + 0x3b) == GfxRndSeed2)) {
        bVar1 = ovr_draw_textArena();
        if (!bVar1) {
          return;
        }
        pcStack_4 = (char *)((undefined2 *)(iVar3 * 4))[1];
        uStack_6 = *(undefined2 *)(iVar3 * 4);
        if (GameRunning == false) {
          ovr_fmVsprintf((char *)CONCAT22(uStack_6,(char *)"puppetmaker" + 3),
                         (char *)CONCAT22(unaff_SI,pcStack_4));
          ovr_say();
        }
        ovc18_blitTriangles();
        return;
      }
    }
    if (PartyCount != 0) {
      pcStack_4 = (char *)*(undefined2 *)((uint)PartyCount * 4 + -2);
      uStack_6 = *(undefined2 *)((uint)PartyCount * 4 + -4);
      uVar2 = ovc18_usesAlignUp4();
      if ((char)uVar2 == '\0') {
        ovr_fmVsprintf((char *)CONCAT22(uStack_6,(char *)"puppetmaker" + 3),
                       (char *)CONCAT22(unaff_SI,pcStack_4));
        ovr_say();
      }
      else {
        ovr_fmVsprintf((char *)CONCAT22(uStack_6,(char *)"puppetmaker" + 3),
                       (char *)CONCAT22(unaff_SI,pcStack_4));
        ovr_say();
      }
      trianglesShown = 1;
      ovc18_blitTriangles();
      return;
    }
    if (CurPartySlot < PartySize) {
      if (GameRunning == false) {
        if (CurPartySlot == 0) {
          ovr_say();
        }
        else {
          ovr_say();
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Spawns an agent for a party slot with a gindex derived from the party sheet's classStr (6/19/25
   or a random case), forwarding x/y/destX/destY to ovc15_usesLDIV_at_. */

uint8_t * __cdecl16far
ovc18_spawnClassAgent
          (uint16_t x,uint16_t y,uint16_t destX,uint16_t destY,uint8_t classStr,uint8_t partyIndex,
          uint16_t mode)

{
  undefined1 uVar1;
  char cVar2;
  byte bVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  uint8_t *puVar7;
  far_t *pfVar8;
  int iVar9;
  uint16_t uVar10;
  entity_t *peVar11;
  far_t *pfVar12;
  undefined2 uVar13;
  uint16_t uVar14;
  uint16_t unaff_BP;
  uint8_t *puVar15;
  far_t *unaff_SI;
  uint uVar16;
  int unaff_DI;
  char *pcVar17;
  uint8_t *in_stack_00000004;
  undefined1 auStackY_56 [46];
  uint8_t *puStackY_28;
  undefined2 uStackY_26;
  undefined4 uStackY_24;
  undefined4 uStackY_20;
  char *pcVar18;
  char *in_stack_0000ffe8;
  uint16_t in_stack_0000ffec;
  char *in_stack_0000ffee;
  undefined2 in_stack_0000fffc;
  char *filename;
  
  bVar3 = *(byte *)((int)*(undefined4 *)((uint)classStr << 2) + 0x3e);
  filename = (char *)CONCAT11((char)((uint)in_stack_0000fffc >> 8),bVar3);
  uVar14 = 0x195d;
  if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)bVar3 * 0x95) & 0x800) == 0) {
    peVar11 = ovr_ovc15_usesLDIV_at_();
  }
  else {
    iVar5 = 5;
    uVar10 = ovr_randBelow();
    puVar7 = (uint8_t *)(uVar10 & 0xff);
    pcVar17 = (char *)0x0;
    puVar15 = in_stack_00000004;
    switch(puVar7) {
    case (uint8_t *)0x0:
      do {
        if (199 < iVar5 + (uint)*(byte *)(y + (int)puVar7 * uVar14 + 10)) {
          unaff_SI = (far_t *)(*(int *)(y + (int)puVar15 * 0x1e + 3) %
                              (int)(uint)*(byte *)(y + (int)puVar15 * 0x1e + 10));
          filename = filename + *(byte *)(y + (int)puVar15 * 0x1e + 9);
          unaff_DI = unaff_DI + (uint)*(byte *)(y + (int)puVar15 * 0x1e + 9);
          in_stack_0000ffe8 =
               (char *)CONCAT22((int)((ulong)in_stack_0000ffe8 >> 0x10) +
                                (uint)*(byte *)(y + (int)puVar15 * 0x1e + 9),
                                (char *)in_stack_0000ffe8 + *(byte *)(y + (int)puVar15 * 0x1e + 9));
        }
        uVar16 = in_stack_0000ffec + 1;
        puVar7 = puVar15;
        while (uVar13 = (undefined2)((ulong)((long)(int)puVar7 * 0x1e) >> 0x10),
              *(byte *)(y + (int)((long)(int)puVar7 * 0x1e) + 0x1b) <= uVar16) {
          if ((char *)in_stack_0000ffee != (char *)0x0 ||
              (int)((ulong)in_stack_0000ffee >> 0x10) != 0) {
            *in_stack_0000ffee = (char)in_stack_0000ffe8 - (char)((ulong)in_stack_0000ffe8 >> 0x10);
          }
          puVar7 = puVar7 + 1;
          if ((destY <= puVar7) || (*(char *)(y + (int)puVar7 * 0x1e + 0x1b) == '\0')) {
            return puStackY_28;
          }
          uVar16 = (uint)*(byte *)(y + (int)puVar7 * 0x1e);
          uStackY_24 = (uint8_t *)CONCAT22(uStackY_26,puStackY_28 + uVar16 * 4 + 0x58);
          *(uint16_t *)((int)(puStackY_28 + uVar16 * 4) + 2) = destX;
          *(uint16_t *)(puStackY_28 + uVar16 * 4) = y + (int)puVar7 * 0x1e;
          filename = (char *)*(uint *)(y + (int)puVar7 * 0x1e + 1);
          unaff_SI = (far_t *)*(int *)(y + (int)puVar7 * 0x1e + 3);
          unaff_DI = *(int *)(y + (int)puVar7 * 0x1e + 5);
          if (*(int *)(y + (int)puVar7 * 0x1e + 7) - (int)unaff_SI < 0) {
                    /* WARNING: Subroutine does not return */
            ovr_stExit();
          }
          in_stack_0000ffee = (char *)0x0;
          uVar16 = 0;
        }
        iVar5 = 0x15;
        in_stack_0000ffee = (char *)CONCAT22(unaff_SI,filename);
        in_stack_0000ffe8 = (char *)CONCAT22(in_stack_00000004,pcVar17);
        pcVar17 = (char *)"bath house" + 10;
        in_stack_0000ffec = x;
        pfVar8 = ovr_stshRleSub();
        uStackY_20 = (far_t *)CONCAT22(uVar13,pfVar8);
        *(undefined1 *)&pfVar8[1].seg = 2;
        *(undefined2 *)((int)&pfVar8[1].seg + 1) = *(undefined2 *)(y + (int)puVar7 * 0x1e + 0xb);
        *(undefined2 *)((int)&pfVar8[2].ofs + 1) = *(undefined2 *)(y + (int)puVar7 * 0x1e + 0xd);
        *(undefined2 *)((uint8_t *)uStackY_24 + 2) = uVar13;
        *(far_t **)uStackY_24 = pfVar8;
        uStackY_24 = (uint8_t *)CONCAT22(uVar13,(uint8_t *)((int)&pfVar8->ofs + 1));
        if ((*(byte *)(y + (int)puVar7 * 0x1e + 0x1c) & 1) == 0) {
          *(undefined1 *)((int)&pfVar8[1].ofs + 1) = *(undefined1 *)(y + (int)puVar7 * 0x1e + 0xf);
        }
        else {
          iVar9 = iVar5 * 0x140 + 0x140;
          pcVar18 = filename;
          if (in_stack_0000ffec == 0) {
            uVar16 = 0;
            while (uVar16 < 2) {
              if ((char *)(unaff_DI + iVar9) < pcVar18) {
                    /* WARNING: Subroutine does not return */
                ovr_stExit();
              }
              if (in_stack_00000004[(int)(pcVar18 + iVar9)] == 0xfe) {
                if (uVar16 == 0) {
                  in_stack_0000ffe8 = (char *)CONCAT22(pcVar18,(char *)in_stack_0000ffe8);
                }
                else {
                  in_stack_0000ffe8 =
                       (char *)CONCAT22((int)((ulong)in_stack_0000ffe8 >> 0x10),pcVar18);
                }
                uVar16 = uVar16 + 1;
              }
              pcVar18 = pcVar18 + 1;
            }
            in_stack_0000ffee = (char *)CONCAT22(uVar13,(char *)((int)&pfVar8[1].ofs + 1));
          }
          else {
            while (in_stack_00000004[(int)(pcVar18 + iVar9)] != 0xfe) {
              if ((char *)(unaff_DI + iVar9) < pcVar18) {
                    /* WARNING: Subroutine does not return */
                ovr_stExit();
              }
              pcVar18 = pcVar18 + 1;
            }
            *(char *)((int)&pfVar8[1].ofs + 1) = (char)in_stack_0000ffe8 - (char)pcVar18;
            in_stack_0000ffe8 = (char *)CONCAT22((int)((ulong)in_stack_0000ffe8 >> 0x10),pcVar18);
          }
        }
        *(undefined1 *)&uStackY_20->ofs = 4;
        *(undefined2 *)((int)&pfVar8->seg + 1) = 0;
        *(undefined2 *)((int)&pfVar8->ofs + 1) = 0;
        unaff_SI = (far_t *)((int)&unaff_SI->ofs + (uint)*(byte *)(y + (int)puVar7 * 0x1e + 10));
        uVar14 = 0x1e;
        puVar15 = puVar7;
      } while( true );
    case (uint8_t *)0x1:
      uVar1 = in(uVar14);
      *(undefined1 *)x = uVar1;
      midpakAd.ofs = (uint16_t)stshStoreFile_2(unaff_SI,filename,unaff_BP);
      midpakAd.seg = uVar14;
      cmidpakComOfs =
           stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                           (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
      _cmidpakComSeg = uVar14;
      ibmsndComOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                     (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
      ibmsndComSeg = uVar14;
      sblasterComOfs =
           stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                           (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
      audioPlaceholder2.seg = 0;
      audioPlaceholder2.ofs = 0;
      sblasterComSeg = uVar14;
      fibmbakComOfs =
           stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                           (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
      fibmbakComSeg = uVar14;
      pfVar12 = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
      sbproComOfs = pfVar12;
      sbproComSeg = uVar14;
      sbproComCopyOfs = pfVar12;
      sbproComCopySeg = uVar14;
      paudioComOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                     (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
      sblasterComCopySeg = sblasterComSeg;
      sblasterComCopyOfs = sblasterComOfs;
      pfVar8 = sblasterComOfs;
      paudioComSeg = pfVar12;
      adlibComOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                    (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
      adlibComSeg = pfVar8;
      adlibgComOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                     (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
      audioPlaceholder3.seg = 0;
      audioPlaceholder3.ofs = 0;
      musDriver0Seg = 0;
      musDriver0Ofs = 0;
      adlibgComSeg = pfVar8;
      sbfmAdvOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                   (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
      audioPlaceholder0.seg = 0;
      audioPlaceholder0.ofs = 0;
      audioPlaceholder1.seg = 0;
      audioPlaceholder1.ofs = 0;
      sbfmAdvSeg = pfVar8;
      sbp2fmAdvOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                     (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
      sbp2fmAdvSeg = pfVar8;
      sbp1fmAdvOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                     (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
      sbp1fmAdvSeg = pfVar8;
      pasfmAdvOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                    (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
      pasfmAdvSeg = pfVar8;
      pasoplAdvOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                     (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
      pasoplAdvSeg = pfVar8;
      adlibAdvOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                    (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
      adlibAdvSeg = pfVar8;
      adlibgAdvOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                     (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
      adlibgAdvSeg = pfVar8;
      mt32mpuAdvOfs =
           stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                           (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
      mt32mpuAdvSeg = pfVar8;
      return (uint8_t *)mt32mpuAdvOfs;
    case (uint8_t *)0x2:
      iVar5 = ovr_ovc23_findClearColumn();
      if (iVar5 < 0) {
        ovr_drawTextAt();
        puVar7 = (uint8_t *)((char *)"puppetmaker" + 3);
        in_stack_00000004[-0x6f7e] = 0x0;
      }
      else {
        callResultTemp = func_0x0004f501();
        if (callResultTemp < unaff_SI) {
          in_stack_00000004[-0x6f7e] = (uint8_t)callResultTemp;
        }
        puVar6 = (undefined4 *)(((uint)filename & 0xff) << 2);
        uVar4 = *puVar6;
        cVar2 = *(char *)((int)uVar4 + 0x2f);
        puVar7 = (uint8_t *)CONCAT11((char)((uint)puVar6 >> 8),cVar2);
        if (cVar2 != -1) {
          ovr_ovc41_pluralSuffix();
          uStackY_20 = (far_t *)CONCAT22(auStackY_56,0x23d5);
          uStackY_24 = (uint8_t *)CONCAT22(0xad0,(uint8_t *)uStackY_24);
          puVar7 = (uint8_t *)ovr_stsprintf();
          ovr_drawTextAt();
        }
      }
      return puVar7;
    case (uint8_t *)0x3:
      ((int *)StshHandles)[(int)in_stack_00000004] = (int)puVar7;
      *(undefined2 *)((int)(long *)StshPtrs + (int)in_stack_00000004 * 4 + 2) = 0;
      *(undefined2 *)((long *)StshPtrs + (int)in_stack_00000004) = 0;
      return in_stack_00000004;
    case (uint8_t *)0x4:
      smm_restore_state();
      return puVar7;
    default:
      if (partyIndex == 0x2) {
        peVar11 = ovr_ovc15_usesLDIV_at_();
      }
      else {
        peVar11 = ovr_ovc15_usesLDIV_at_();
      }
    }
  }
  return (uint8_t *)peVar11;
}



/* 48ac:0382 */

/* [R2] string "type %d len %ld \r" */

char * __cdecl16far
ovc18_textTypeLen(uint8_t partyIndex,uint16_t destX,uint16_t destY,uint8_t textVariant,...)

{
  int *piVar1;
  far_t ptr_ofs;
  uint8_t uVar2;
  byte bVar3;
  int *piVar4;
  uint uVar5;
  uint8_t *puVar6;
  uint32_t *puVar7;
  char *pcVar8;
  uint in_CX;
  uint uVar9;
  int iVar11;
  int iVar12;
  uint uVar13;
  long *unaff_SI;
  undefined2 unaff_DI;
  undefined2 uVar14;
  undefined2 unaff_SS;
  bool bVar15;
  far_t fVar16;
  uint8_t uStack0004;
  undefined1 uStack0007;
  int *in_stack_00000014;
  int *in_stack_00000018;
  int *in_stack_0000001c;
  int *in_stack_00000020;
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
  undefined1 uStack_4;
  undefined1 uStack_3;
  uint16_t uVar10;
  
  uVar2 = partyIndex;
  piVar1 = destX;
  uStack0004 = CONCAT13(uStack0007,CONCAT12(partyIndex,uStack0004));
  uVar19 = SUB21(unaff_SI,0);
  uVar20 = (undefined1)((uint)unaff_SI >> 8);
  uVar17 = (undefined1)unaff_DI;
  uVar18 = (undefined1)((uint)unaff_DI >> 8);
  piVar4 = (int *)((uStack0004 & 0xff) * 4);
  iVar12 = piVar4[1];
  iVar11 = *piVar4;
  uVar23 = (undefined1)iVar12;
  uVar24 = (undefined1)((uint)iVar12 >> 8);
  uVar21 = (undefined1)iVar11;
  uVar22 = (undefined1)((uint)iVar11 >> 8);
  uVar25 = (undefined1)*(undefined2 *)(iVar11 + 0x3b);
  uVar26 = (undefined1)((uint)*(undefined2 *)(iVar11 + 0x3b) >> 8);
  uVar14 = (undefined2)(CONCAT13(uVar24,CONCAT12(uVar23,iVar11)) >> 0x10);
  uVar5 = (uint)*(byte *)(iVar11 + 0x2f);
  if (uVar5 == 4) {
    ovr_ovc15_usesLDIV_at_();
  }
  else if (uVar5 < 5) {
    if (uVar5 < 4) {
      bVar15 = uVar5 == 0;
      switch(uVar5) {
      case 1:
        uVar13 = *(uint *)(uVar5 * 2 + 0xc);
        uVar9 = uVar13 + 0x14;
        iVar12 = uVar5 + (0xffeb < uVar13);
        if (StshCount < 0xd93) {
          StshCount = StshCount + 1;
          LXMUL_at_(unaff_SI,CONCAT13((char)(uVar9 >> 8),CONCAT12((char)uVar9,iVar11)),
                    CONCAT13((char)((uint)*(undefined2 *)(iVar11 + 0x39) >> 8),
                             CONCAT12((char)*(undefined2 *)(iVar11 + 0x39),iVar12)));
          (*(uint8_t *)((uint8_t *)&(fVar16.seg))) = uVar17;
          fVar16.ofs = 0x1000;
          (*(uint8_t *)((uint8_t *)&(fVar16.seg) + 1)) = uVar18;
          (*(uint8_t *)((uint8_t *)&(ptr_ofs.ofs) + 1)) = uVar20;
          (*(uint8_t *)((uint8_t *)&(ptr_ofs.ofs))) = uVar19;
          (*(uint8_t *)((uint8_t *)&(ptr_ofs.seg))) = uVar21;
          (*(uint8_t *)((uint8_t *)&(ptr_ofs.seg) + 1)) = uVar22;
          fVar16 = PADD_at_(fVar16,ptr_ofs);
          uVar10 = fVar16.seg;
          puVar7 = ovr_mkp();
          uStack_4 = (undefined1)uVar10;
          uStack_3 = (undefined1)(uVar10 >> 8);
          uVar17 = SUB21(puVar7,0);
          uVar18 = (undefined1)((uint)puVar7 >> 8);
          uVar14 = (undefined2)(CONCAT13(uStack_3,CONCAT12(uStack_4,puVar7)) >> 0x10);
          *(int *)((int)puVar7 + 7) = iVar12;
          *(uint *)((int)puVar7 + 5) = uVar9;
          *(undefined1 *)CONCAT13(uStack_3,CONCAT12(uStack_4,puVar7)) = 0;
          uVar10 = StshCtOfs.lo;
          uVar14 = (undefined2)(CONCAT13(uStack_3,CONCAT12(uStack_4,puVar7)) >> 0x10);
          *(uint16_t *)((int)puVar7 + 3) = StshCtOfs.hi;
          *(uint16_t *)((int)puVar7 + 1) = uVar10;
          uVar14 = (undefined2)(CONCAT13(uStack_3,CONCAT12(uStack_4,puVar7)) >> 0x10);
          *(undefined2 *)((int)puVar7 + 0x13) = 0;
          *(undefined2 *)((int)puVar7 + 0x11) = 0;
          bVar15 = CARRY2(StshCtOfs.lo,uVar9);
          StshCtOfs.lo = StshCtOfs.lo + uVar9;
          StshCtOfs.hi = StshCtOfs.hi + iVar12 + (uint)bVar15;
          uVar14 = (undefined2)(CONCAT13(uStack_3,CONCAT12(uStack_4,puVar7)) >> 0x10);
          *(undefined2 *)((int)puVar7 + 0xb) = 0;
          *(undefined2 *)((int)puVar7 + 9) = 0;
          uVar14 = (undefined2)(CONCAT13(uStack_3,CONCAT12(uStack_4,puVar7)) >> 0x10);
          *(undefined2 *)((int)puVar7 + 0xf) = 0;
          *(undefined2 *)((int)puVar7 + 0xd) = 0;
          if (DebugVerbose != false) {
            printf("type %d len %ld \r");
            ovr_biosReadKey();
          }
          stshWriteFile();
          ovr_stshFree();
          return (char *)CONCAT11(uVar18,uVar17);
        }
                    /* WARNING: Subroutine does not return */
        ovr_stExit();
      case 2:
        uVar13 = partyIndex + 1;
        piVar1 = (int *)(uVar5 * 2 + uVar13);
        *piVar1 = *piVar1 + 1;
        do {
          pcVar8 = ovr_ovc15_textArena();
          if (((uint)pcVar8 & 0xff) == 0) goto L_attact_3f0b_26bd_2767;
          destX = destX - 1;
          while (destX == 0) {
L_attact_3f0b_26bd_2767:
            do {
              uVar13 = uVar13 + 1;
              if (EntityCount <= uVar13) {
                return (char *)"puppetmaker" + 3;
              }
              uVar14 = ovr_ovc23_isCursorAt();
            } while ((char)uVar14 == '\0');
            destX = func_0x0004f944();
          }
        } while( true );
      case 3:
                    /* WARNING: Read-only address (ram,0x000277ff) is written */
        s_cue9a_xmi_2410_36fe[1] = -0x58;
        *(uint *)(&stack0x681c + partyIndex) = *(uint *)(&stack0x681c + partyIndex) & in_CX;
        ovr_blitLabel();
        uVar17 = 0xdc;
        uVar18 = 0;
        pcVar8 = litoa10();
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar11 >> 8),CONCAT12((char)iVar11,pcVar8)),
                   CONCAT11(uVar18,uVar17));
        TextBlitY = TextBlitY + 10;
        TextBlitX = 0x37;
        ovr_blitLabel();
        uVar17 = 0x7d;
        uVar18 = 0;
        pcVar8 = ovr_stsprintf();
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar11 >> 8),CONCAT12((char)iVar11,pcVar8)),
                   CONCAT11(uVar18,uVar17));
        TextBlitX = 0x82;
        ovr_blitLabel();
        uVar17 = 0xdc;
        uVar18 = 0;
        pcVar8 = litoa10();
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar11 >> 8),CONCAT12((char)iVar11,pcVar8)),
                   CONCAT11(uVar18,uVar17));
        TextBlitY = TextBlitY + 0xf;
        if (*(int *)(uStack0004 + 0xa0) != 0) {
          TextBlitX = 0x37;
          if (*(int *)(uStack0004 + 0xa2) < 0) {
            ovr_blitLabel();
            uVar17 = 0x7d;
            uVar18 = 0;
            iVar12 = -*(int *)(uStack0004 + 0xa2) >> 0xf;
            pcVar8 = litoa10();
            manage_blitLabelRight
                      ((char *)CONCAT13((char)((uint)iVar12 >> 8),CONCAT12((char)iVar12,pcVar8)),
                       CONCAT11(uVar18,uVar17));
          }
          else {
            ovr_blitLabel();
            uVar17 = 0x7d;
            uVar18 = 0;
            iVar12 = *(int *)(uStack0004 + 0xa2) >> 0xf;
            pcVar8 = litoa10();
            manage_blitLabelRight
                      ((char *)CONCAT13((char)((uint)iVar12 >> 8),CONCAT12((char)iVar12,pcVar8)),
                       CONCAT11(uVar18,uVar17));
          }
          TextBlitX = 0x82;
          ovr_blitLabel();
          uVar17 = 0xdc;
          uVar18 = 0;
          pcVar8 = litoa10();
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)iVar12 >> 8),CONCAT12((char)iVar12,pcVar8)),
                     CONCAT11(uVar18,uVar17));
        }
        TextBlitY = TextBlitY + 0xf;
        TextBlitX = 0x37;
        ovr_blitLabel();
        uVar17 = 0xdc;
        uVar18 = 0;
        iVar12 = *(int *)(uStack0004 + 0x54) >> 0xf;
        pcVar8 = litoa10();
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar12 >> 8),CONCAT12((char)iVar12,pcVar8)),
                   CONCAT11(uVar18,uVar17));
        TextBlitY = TextBlitY + 10;
        TextBlitX = 0x37;
        ovr_blitLabel();
        uVar17 = 0xdc;
        uVar18 = 0;
        pcVar8 = litoa10();
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar12 >> 8),CONCAT12((char)iVar12,pcVar8)),
                   CONCAT11(uVar18,uVar17));
        TextBlitY = TextBlitY + 10;
        TextBlitX = 0x37;
        ovr_blitLabel();
        uVar17 = 0xdc;
        uVar18 = 0;
        pcVar8 = litoa10();
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar12 >> 8),CONCAT12((char)iVar12,pcVar8)),
                   CONCAT11(uVar18,uVar17));
        TextBlitY = TextBlitY + 10;
        TextBlitX = 0x37;
        ovr_blitLabel();
        uVar17 = 0xdc;
        uVar18 = 0;
        ovr_ovc45_usesLDIV_at_();
        pcVar8 = litoa10();
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar12 >> 8),CONCAT12((char)iVar12,pcVar8)),
                   CONCAT11(uVar18,uVar17));
        TextBlitY = TextBlitY + 10;
        TextBlitX = 0x37;
        ovr_blitLabel();
        uVar17 = 0xdc;
        uVar18 = 0;
        pcVar8 = litoa10();
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar12 >> 8),CONCAT12((char)iVar12,pcVar8)),
                   CONCAT11(uVar18,uVar17));
        bVar3 = manage_findFirstLeader();
        pcVar8 = (char *)"puppetmaker" + 3;
        TextBlitY = TextBlitY + 0xf;
        if ((*(char *)(uStack0004 + 0x86) != '\0') && (bVar3 != 0xff)) {
          pcVar8 = (char *)((uint)bVar3 << 2);
          uVar14 = 0x217a;
          if (*(byte *)((int)*(undefined4 *)pcVar8 + 0x86) < 9) {
            manage_usesBlitLabel2("popularity",0x7d);
            manage_usesBlitLabel2("city blocks",0xdc);
            TextBlitY = TextBlitY + 10;
            TextBlitX = 0x11;
            ovr_blitLabel();
            uVar17 = 0x7d;
            uVar18 = 0;
            manage_usesGLeaderCount();
            pcVar8 = ovr_stsprintf();
            manage_blitLabelRight
                      ((char *)CONCAT13((char)((uint)uVar14 >> 8),CONCAT12((char)uVar14,pcVar8)),
                       CONCAT11(uVar18,uVar17));
            uVar17 = 0xdc;
            uVar18 = 0;
            pcVar8 = ovr_stsprintf();
            manage_blitLabelRight
                      ((char *)CONCAT13((char)((uint)uVar14 >> 8),CONCAT12((char)uVar14,pcVar8)),
                       CONCAT11(uVar18,uVar17));
            TextBlitY = TextBlitY + 10;
            TextBlitX = 0x11;
            ovr_blitLabel();
            uVar17 = 0x7d;
            uVar18 = 0;
            ovr_season_usesDifficulty();
            pcVar8 = ovr_stsprintf();
            manage_blitLabelRight
                      ((char *)CONCAT13((char)((uint)uVar14 >> 8),CONCAT12((char)uVar14,pcVar8)),
                       CONCAT11(uVar18,uVar17));
            uVar17 = 0xdc;
            uVar18 = 0;
            ovr_season_usesGPromotableCount2();
            pcVar8 = ovr_stsprintf();
            manage_blitLabelRight
                      ((char *)CONCAT13((char)((uint)uVar14 >> 8),CONCAT12((char)uVar14,pcVar8)),
                       CONCAT11(uVar18,uVar17));
          }
        }
        return pcVar8;
      }
      do {
        if (bVar15) {
          *in_stack_00000020 = *in_stack_00000020 + 1;
        }
        while( true ) {
          while( true ) {
            do {
              destX = destX + 1;
              if (GRecordCount <= destX) {
                iVar12 = *in_stack_0000001c;
                iVar11 = *in_stack_00000020;
                *piVar1 = *piVar1 - *in_stack_0000001c;
                *textVariant = *textVariant - *in_stack_00000020;
                return (char *)(CONCAT11(uStack_3,uStack_4) - (iVar12 + iVar11));
              }
            } while ((*(uint8_t *)(destX * 0x12 + 9) != uStack0004) ||
                    (bVar3 = *(byte *)(destX * 0x12 + 8),
                    *(uint8_t *)((uint)bVar3 * 0x27 + 0x133) != uVar2));
            *in_stack_00000014 = *in_stack_00000014 + 1;
            if (*(char *)((uint)bVar3 * 0x27 + 0x131) != '\x01') break;
            *in_stack_00000018 = *in_stack_00000018 + 1;
          }
          if (*(char *)((uint)bVar3 * 0x27 + 0x131) != '\x02') break;
          *in_stack_0000001c = *in_stack_0000001c + 1;
        }
        bVar15 = *(char *)((uint)bVar3 * 0x27 + 0x131) == '\x03';
      } while( true );
    }
  }
  else if (uVar5 == 5) {
    ovr_ovc15_usesLDIV_at_();
  }
  else if (uVar5 == 6) {
    ovr_ovc15_usesLDIV_at_();
  }
  else if ((uVar5 == 0xff) &&
          ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)*(byte *)(iVar11 + 0x3e) * 0x95) &
           0x800) == 0)) {
    if ((uint8_t)destY == 0x0) {
      ovr_ovc15_usesLDIV_at_();
    }
    else {
      ovr_ovc15_usesLDIV_at_();
    }
  }
  puVar6 = (uint8_t *)((uint)*(byte *)(CONCAT11(uVar22,uVar21) + 0x3e) * 0x95);
  if ((*(uint *)(puVar6 + 0x2714) & 0x8000) != 0) {
    puVar6 = ovc18_spawnClassAgent
                       (CONCAT11(uVar26,uVar25),partyIndex,destX,1,uStack0004,(uint8_t)destY,
                        CONCAT11(uVar18,uVar17));
  }
  return (char *)puVar6;
}



/* 48ac:05f2 */

/* Checks a fortress site and reports the matching rejection message. */

void __cdecl16far ovc18_checkFortressPlacement(char strongholdKind,...)

{
  undefined4 uVar1;
  far_t dst;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  undefined1 *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined2 unaff_DI;
  undefined2 uVar10;
  uint16_t unaff_SS;
  char in_stack_00000004;
  byte partyIndex;
  undefined1 uVar11;
  undefined1 auStack_12 [13];
  undefined1 uStack_5;
  uint uStack_4;
  
  partyIndex = (byte)unaff_DI;
  uVar11 = (undefined1)((uint)unaff_DI >> 8);
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)auStack_12;
  F_SCOPY(far_from_u32((uint32_t)(0x241045b9)),dst);
  for (uVar8 = 0; uVar8 < EntityCount; uVar8 = uVar8 + 1) {
    uVar10 = (undefined2)((ulong)Entities >> 0x10);
    if (*(char *)((int)(char **)GMenuStrings +
                 (uint)((entity_t *)Entities)[uVar8].base.gindex * 0x95 + 0x1f) != '\0') {
      uVar3 = ovr_alignUp4(CONCAT11(uVar11,partyIndex),(((entity_t *)Entities + uVar8)->base).x);
      uVar4 = ovr_alignUp4(uVar3,(char)GfxRndSeed);
      if ((uVar3 == uVar4) && (((entity_t *)Entities)[uVar8].base.y == GfxRndSeed2)) {
        ovr_stats_openCastlePanel();
        ovr_say((char *)CONCAT13(uVar11,CONCAT12(partyIndex,0x2410)),0x89);
        MsgShown = 1;
        return;
      }
    }
  }
  for (iVar9 = 0; iVar9 < (int)(uint)GLeaderCount; iVar9 = iVar9 + 1) {
    if (((*(char *)((int)*(undefined4 *)(iVar9 << 2) + 0x3d) != '\0') &&
        (*(int *)((int)*(undefined4 *)(iVar9 << 2) + 0x39) == GfxRndSeed)) &&
       (*(uint16_t *)((int)*(undefined4 *)(iVar9 << 2) + 0x3b) == GfxRndSeed2)) {
      ovr_stats_openCastlePanel();
      ovr_say((char *)CONCAT13(uVar11,CONCAT12(partyIndex,0x2410)),0xb8);
      MsgShown = 1;
      return;
    }
  }
  if (in_stack_00000004 == '\x02') {
    uVar8 = ovr_constr_usesGMapFlags(GfxRndSeed2,(char)(GfxRndSeed + -2));
    if ((((uVar8 & 0xff) == 0) ||
        (uVar8 = ovr_constr_usesGMapFlags(GfxRndSeed2,(char)(GfxRndSeed + -1)), (uVar8 & 0xff) == 0)
        ) || ((uVar8 = ovr_constr_usesGMapFlags(GfxRndSeed2,(char)GfxRndSeed), (uVar8 & 0xff) == 0
              || (uVar8 = ovr_constr_usesGMapFlags(GfxRndSeed2,(char)(GfxRndSeed + 1)),
                 (uVar8 & 0xff) == 0)))) {
      ovr_stats_openCastlePanel();
      puVar6 = &stack0xffea;
      pcVar5 = ovr_fmVsprintf((char *)CONCAT13((char)((uint)*(undefined2 *)
                                                             (puVar6 + (uint)placementStatus * 4) >>
                                                     8),CONCAT12((char)*(undefined2 *)
                                                                        (puVar6 + (uint)
                                                  placementStatus * 4),0x2410)),
                              (char *)CONCAT13(uVar11,CONCAT12(partyIndex,
                                                               *(undefined2 *)
                                                                (&stack0xffec +
                                                                (uint)placementStatus * 4))));
      ovr_say((char *)CONCAT13(uVar11,CONCAT12(partyIndex,puVar6)),(char)pcVar5);
      MsgShown = 1;
      return;
    }
  }
  else {
    uVar8 = ovr_constr_usesGMapFlags(GfxRndSeed2,(char)(GfxRndSeed + -1));
    if (((uVar8 & 0xff) == 0) ||
       (uVar8 = ovr_constr_usesGMapFlags(GfxRndSeed2,(char)GfxRndSeed), (uVar8 & 0xff) == 0)) {
      ovr_stats_openCastlePanel();
      puVar6 = &stack0xffea;
      pcVar5 = ovr_fmVsprintf((char *)CONCAT13((char)((uint)*(undefined2 *)
                                                             (puVar6 + (uint)placementStatus * 4) >>
                                                     8),CONCAT12((char)*(undefined2 *)
                                                                        (puVar6 + (uint)
                                                  placementStatus * 4),0x2410)),
                              (char *)CONCAT13(uVar11,CONCAT12(partyIndex,
                                                               *(undefined2 *)
                                                                (&stack0xffec +
                                                                (uint)placementStatus * 4))));
      ovr_say((char *)CONCAT13(uVar11,CONCAT12(partyIndex,puVar6)),(char)pcVar5);
      MsgShown = 1;
      return;
    }
  }
  bVar2 = ovr_draw_textArena();
  if (bVar2) {
    if (1 < CurPartySlot) {
      uStack_4 = 0xffff;
      for (iVar9 = 0; iVar9 < (int)(uint)GLeaderCount; iVar9 = iVar9 + 1) {
        if (((*(char *)((int)*(undefined4 *)(iVar9 << 2) + 0x3d) != '\0') &&
            (*(char *)((int)*(undefined4 *)(iVar9 << 2) + 0x3f) == '\0')) &&
           (uVar8 = *(int *)((int)*(undefined4 *)(iVar9 << 2) + 0x39) - GfxRndSeed,
           uVar4 = (int)uVar8 >> 0xf,
           uVar3 = *(int *)((int)*(undefined4 *)(iVar9 << 2) + 0x3b) - GfxRndSeed2,
           uVar7 = (int)uVar3 >> 0xf, uVar8 = ((uVar8 ^ uVar4) - uVar4) + ((uVar3 ^ uVar7) - uVar7),
           uVar8 < uStack_4)) {
          uStack_4 = uVar8;
        }
      }
      if (0x1e < uStack_4) {
        ovr_stats_openCastlePanel();
        ovr_say((char *)CONCAT13(uVar11,CONCAT12(partyIndex,0x2410)),0x34);
        MsgShown = 1;
        return;
      }
    }
    uVar1 = *(undefined4 *)((uint)PartyCount * 4 + -4);
    *(int *)((int)uVar1 + 0x39) = GfxRndSeed;
    uVar1 = *(undefined4 *)((uint)PartyCount * 4 + -4);
    *(uint16_t *)((int)uVar1 + 0x3b) = GfxRndSeed2;
    uVar1 = *(undefined4 *)((uint)PartyCount * 4 + -4);
    *(undefined1 *)((int)uVar1 + 0x3d) = 1;
    uVar1 = *(undefined4 *)((uint)PartyCount * 4 + -4);
    *(char *)((int)uVar1 + 0x89) = CurPartySlot - 1;
    if (in_stack_00000004 == '\x02') {
      uVar1 = *(undefined4 *)((uint)PartyCount * 4 + -4);
      *(undefined1 *)((int)uVar1 + 0x5a) = 1;
      ovr_createConstructionRecordFar
                ((char)GfxRndSeed - 2,GfxRndSeed2,(int)&uStack_5,0x89,(byte)&uStack_5);
      ovc18_textTypeLen((uint8_t)GfxRndSeed,GfxRndSeed2,0,partyIndex,CONCAT11(0x24,PartyCount - 1),
                        (char)GfxRndSeed2);
      ovr_ovc22_usesRandBelow2((byte)&uStack_5,unaff_SS,PartyCount - 1);
    }
    else {
      uVar1 = *(undefined4 *)((uint)PartyCount * 4 + -4);
      *(char *)((int)uVar1 + 0x5a) = in_stack_00000004;
      uVar1 = *(undefined4 *)((uint)PartyCount * 4 + -4);
      iVar9 = (uint)*(byte *)((int)uVar1 + 0x3e) * 0x95;
      ovr_createConstructionRecordFar
                ((char)GfxRndSeed - 1,GfxRndSeed2,(int)&uStack_5,
                 CONCAT11((char)((uint)iVar9 >> 8),
                          *(undefined1 *)((int)(far_t *)(worldMenuLabels + 0xb) + iVar9)),
                 (byte)&uStack_5);
      ovc18_textTypeLen((uint8_t)GfxRndSeed,GfxRndSeed2,0,partyIndex,CONCAT11(0x24,PartyCount - 1),
                        (char)GfxRndSeed2);
    }
    if (2 < Difficulty) {
      ovr_ovc22_usesRandBelow2((byte)&uStack_5,unaff_SS,PartyCount - 1);
    }
    ovr_ovc22_textRingProt(partyIndex,CONCAT11(0x24,PartyCount - 1));
    PartyCount = 0;
    ovr_manage_mapPartySlots();
    ovr_stats_openCastlePanel();
    ovr_unit_usesAlignUp4();
    ovr_say((char *)CONCAT13(uVar11,CONCAT12(partyIndex,0x2410)),0xcd);
    if (PlayerIndex == '\0') {
      ovr_ovc30_nextWave(partyIndex,2);
    }
  }
  else {
    ovr_stats_openCastlePanel();
    ovr_say((char *)CONCAT13(uVar11,CONCAT12(partyIndex,0x2410)),0x34);
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
  uint16_t unaff_DI;
  undefined2 uVar5;
  undefined2 uVar6;
  int in_stack_00000004;
  uint uStack_6;
  
  paasVar4 = (short (*) [148] [60])GUnitGrid;
  uVar6 = (undefined2)((ulong)GUnitGrid >> 0x10);
  uVar5 = (undefined2)((ulong)GUnits >> 0x10);
  if ((byte)y == 0) {
    if ((uint)(*paasVar4)[in_stack_00000004][x] < 0xf8) {
      (*paasVar4)[in_stack_00000004][x] = 0;
    }
    else {
      unaff_SI = (*paasVar4)[in_stack_00000004][x];
      ((unit_t *)GUnits + unaff_SI)->bldType = 0;
      ((unit_t *)GUnits)[unaff_SI].level = 8;
      ((unit_t *)GUnits)[unaff_SI].unitType = 0xff;
      (*(short (*) [148] [60])GUnitGrid)[in_stack_00000004][x] = 0;
    }
    puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[x] + in_stack_00000004);
    *puVar1 = *puVar1 & 0x3fff;
  }
  else {
    if ((uint)(*paasVar4)[in_stack_00000004][x] < 0xf8) {
      unaff_SI = 0xf8;
      while ((unaff_SI < GUnitCount && (((unit_t *)GUnits + unaff_SI)->bldType != 0))) {
        unaff_SI = unaff_SI + 1;
      }
      if (GUnitCount <= unaff_SI) {
        if (GUnitCount + 1 < 0x4b0) {
          GUnitCount = GUnitCount + 1;
        }
        else {
          uVar3 = ovr_randBelow(unaff_DI,0x3b8);
          uVar2 = (uVar3 & 0xff) + 0xf8;
          unaff_SI = uVar2;
          do {
            if ((((*(uint *)(unaff_SI * 0x27 + 0x121) & 0xa0) != 0) ||
                (*(char *)(unaff_SI * 0x27 + 0x133) == '\0')) ||
               (*(char *)(unaff_SI * 0x27 + 0x133) == '\a')) break;
            unaff_SI = unaff_SI + 1;
            if (0x4af < unaff_SI) {
              unaff_SI = 0xf8;
            }
          } while (uVar2 != unaff_SI);
          for (uStack_6 = 0; uStack_6 < 0x94; uStack_6 = uStack_6 + 1) {
            for (uVar2 = 0; uVar2 < 0x3c; uVar2 = uVar2 + 1) {
              uVar6 = (undefined2)((ulong)GUnitGrid >> 0x10);
              if ((*(short (*) [148] [60])GUnitGrid)[uStack_6][uVar2] == unaff_SI) {
                (*(short (*) [148] [60])GUnitGrid)[uStack_6][uVar2] = 0;
              }
            }
          }
        }
      }
    }
    else {
      unaff_SI = (*paasVar4)[in_stack_00000004][x];
    }
    ((unit_t *)GUnits + unaff_SI)->bldType = (byte)y;
    ((unit_t *)GUnits)[unaff_SI].level = 8;
    ((unit_t *)GUnits)[unaff_SI].unitType = bldType;
    ((unit_t *)GUnits)[unaff_SI].x = in_stack_00000004;
    ((unit_t *)GUnits)[unaff_SI].y = x;
    (*(short (*) [148] [60])GUnitGrid)[in_stack_00000004][x] = unaff_SI;
    uVar6 = (undefined2)((ulong)GMapFlags >> 0x10);
    (*(short (*) [60] [148])GMapFlags)[x][in_stack_00000004] =
         (*(short (*) [60] [148])GMapFlags)[x][in_stack_00000004] & 0x3fffU |
         (uint)*(byte *)((y & 0xffU) * 0x27 + 0x11e) << 0xe;
    if ((*(uint *)((y & 0xffU) * 0x27 + 0x121) & 0x40) == 0) {
      ((unit_t *)GUnits)[unaff_SI].timer = 0;
    }
    else {
      uVar2 = ovr_constr_usesGMapFlags2(x,unaff_DI,in_stack_00000004);
      if ((uVar2 & 0xff) == 3) {
        uVar3 = ovr_randBelow(unaff_DI,0x28);
        ((unit_t *)GUnits)[unaff_SI].timer = (char)uVar3 + 0x1e;
      }
      else if ((uVar2 & 0xff) == 4) {
        uVar3 = ovr_randBelow(unaff_DI,0x50);
        ((unit_t *)GUnits)[unaff_SI].timer = (char)uVar3 + 0x3c;
      }
      else {
        uVar3 = ovr_randBelow(unaff_DI,0x14);
        ((unit_t *)GUnits)[unaff_SI].timer = (char)uVar3 + 0xf;
      }
    }
  }
  return unaff_SI;
}



/* 48ac:1022 */

/* [R2] string "arena" */

bool __cdecl16far ovc18_textArena(uint16_t x,uint16_t y,...)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int unaff_DI;
  undefined2 in_stack_00000004;
  
  uVar1 = ovr_alignUp4(unaff_DI,in_stack_00000004);
  uVar3 = 0;
  while( true ) {
    if (EntityCount <= uVar3) {
      return false;
    }
    uVar2 = ovr_alignUp4(unaff_DI,(((entity_t *)Entities + uVar3)->base).x);
    if ((uVar2 == uVar1) && (((entity_t *)Entities)[uVar3].base.y == x)) break;
    uVar3 = uVar3 + 1;
  }
  return true;
}



/* 48ac:1092 */

/* [R4] calls ovr_alignUp4 */

uint __cdecl16far ovc18_usesAlignUp4(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int unaff_DI;
  undefined2 uVar7;
  uint uStack_4;
  
  bVar1 = ovr_draw_textArena();
  if (bVar1) {
    for (uVar5 = 0; uVar5 < EntityCount; uVar5 = uVar5 + 1) {
      uVar7 = (undefined2)((ulong)Entities >> 0x10);
      if (*(char *)((int)(char **)GMenuStrings +
                   (uint)((entity_t *)Entities)[uVar5].base.gindex * 0x95 + 0x1f) != '\0') {
        uVar2 = ovr_alignUp4(unaff_DI,(((entity_t *)Entities + uVar5)->base).x);
        uVar3 = ovr_alignUp4(uVar2,GfxRndSeed);
        if ((uVar2 == uVar3) && (uVar2 = ((entity_t *)Entities)[uVar5].base.y, uVar2 == GfxRndSeed2)
           ) {
          return uVar2 & 0xff00;
        }
      }
    }
    for (iVar6 = 0; iVar6 < (int)(uint)GLeaderCount; iVar6 = iVar6 + 1) {
      if (((*(char *)((int)*(undefined4 *)(iVar6 << 2) + 0x3d) != '\0') &&
          (*(int *)((int)*(undefined4 *)(iVar6 << 2) + 0x39) == GfxRndSeed)) &&
         (uVar5 = *(uint *)((int)*(undefined4 *)(iVar6 << 2) + 0x3b), uVar5 == GfxRndSeed2)) {
        return uVar5 & 0xff00;
      }
    }
    uVar5 = ovr_constr_usesGMapFlags(GfxRndSeed2,unaff_DI,GfxRndSeed + -1);
    if (((uVar5 & 0xff) == 0) ||
       (uVar5 = ovr_constr_usesGMapFlags(GfxRndSeed2,unaff_DI,GfxRndSeed), (uVar5 & 0xff) == 0)) {
      uVar5 = 0;
    }
    else if ((CurPartySlot == 1) &&
            ((uVar5 = ovr_constr_usesGMapFlags(GfxRndSeed2,unaff_DI,GfxRndSeed + -2),
             (uVar5 & 0xff) == 0 ||
             (uVar5 = ovr_constr_usesGMapFlags(GfxRndSeed2,unaff_DI,GfxRndSeed + 1),
             (uVar5 & 0xff) == 0)))) {
      uVar5 = 0;
    }
    else {
      uVar5 = 0x2410;
      if (1 < CurPartySlot) {
        uStack_4 = 0xffff;
        for (iVar6 = 0; uVar5 = (uint)GLeaderCount, iVar6 < (int)uVar5; iVar6 = iVar6 + 1) {
          if (((*(char *)((int)*(undefined4 *)(iVar6 << 2) + 0x3d) != '\0') &&
              (*(char *)((int)*(undefined4 *)(iVar6 << 2) + 0x3f) == '\0')) &&
             (uVar5 = *(int *)((int)*(undefined4 *)(iVar6 << 2) + 0x39) - GfxRndSeed,
             uVar3 = (int)uVar5 >> 0xf,
             uVar2 = *(int *)((int)*(undefined4 *)(iVar6 << 2) + 0x3b) - GfxRndSeed2,
             uVar4 = (int)uVar2 >> 0xf,
             uVar5 = ((uVar5 ^ uVar3) - uVar3) + ((uVar2 ^ uVar4) - uVar4), uVar5 < uStack_4)) {
            uStack_4 = uVar5;
          }
        }
        if (0x1e < uStack_4) {
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


