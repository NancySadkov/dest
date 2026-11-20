/*
 * ovc18.c - recovered from STRONG.EXE
 * memory block: OVC18
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
  char *pcVar1;
  uint uVar2;
  int iVar3;
  uint16_t unaff_SS;
  uint8_t partyCounts;
  undefined2 uStack_6;
  undefined2 uStack_4;
  
  trianglesShown = 0;
  if ((MsgShown != '\0') || (GameRunning)) {
    MsgShown = '\0';
  }
  else {
    _fmemset(&partyCounts,unaff_SS,0);
    for (iVar3 = 0; iVar3 < (int)(uint)GLeaderCount; iVar3 = iVar3 + 1) {
      if (((*(char *)((int)*(undefined4 *)(iVar3 << 2) + 0x3d) != '\0') &&
          ((&partyCounts)[*(byte *)((int)*(undefined4 *)(iVar3 << 2) + 0x3f)] =
                (&partyCounts)[*(byte *)((int)*(undefined4 *)(iVar3 << 2) + 0x3f)] + 0x1,
          *(int *)((int)*(undefined4 *)(iVar3 << 2) + 0x39) == GfxRndSeed)) &&
         (*(int *)((int)*(undefined4 *)(iVar3 << 2) + 0x3b) == GfxRndSeed2)) {
        pcVar1 = ovr_draw_textArena();
        if (((uint)pcVar1 & 0xff) == 0) {
          return;
        }
        uStack_4 = ((undefined2 *)(iVar3 * 4))[1];
        uStack_6 = *(undefined2 *)(iVar3 * 4);
        if (GameRunning == false) {
          pcVar1 = ovr_fmVsprintf((char *)"View %s.",(char *)"puppetmaker" + 3);
          ovr_say(pcVar1);
        }
        ovc18_blitTriangles();
        return;
      }
    }
    if (PartyCount != 0) {
      uStack_4 = *(undefined2 *)((uint)PartyCount * 4 + -2);
      uStack_6 = *(undefined2 *)((uint)PartyCount * 4 + -4);
      uVar2 = ovc18_usesAlignUp4();
      if ((char)uVar2 == '\0') {
        pcVar1 = ovr_fmVsprintf((char *)"View %s. (Cannot place)",(char *)"puppetmaker" + 3);
        ovr_say(pcVar1);
      }
      else {
        pcVar1 = ovr_fmVsprintf((char *)"Place %s.",(char *)"puppetmaker" + 3);
        ovr_say(pcVar1);
      }
      trianglesShown = 1;
      ovc18_blitTriangles();
      return;
    }
    if (CurPartySlot < PartySize) {
      if (GameRunning == false) {
        if (CurPartySlot == 0) {
          ovr_say((char *)"Create baron or baroness.");
        }
        else {
          ovr_say((char *)"Create party member.");
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
  undefined4 uVar2;
  char *pcVar3;
  undefined4 *puVar4;
  uint8_t *txt;
  far_t *pfVar5;
  uint16_t uVar6;
  entity_t *peVar7;
  far_t *pfVar8;
  undefined2 uVar9;
  uint16_t uVar10;
  far_t *pfVar11;
  char *unaff_SI;
  uint uVar12;
  far_t *unaff_DI;
  far_t *pfVar13;
  char *unaff_SS;
  far_t *in_stack_00000004;
  char acStackY_56 [46];
  uint8_t *puStackY_28;
  undefined2 uStackY_26;
  undefined4 uStackY_24;
  far_t *pfStackY_20;
  far_t *pfVar14;
  far_t *pfStack_18;
  char cVar15;
  far_t *in_stack_0000ffea;
  uint16_t in_stack_0000ffec;
  far_t *in_stack_0000ffee;
  int iVar16;
  undefined2 in_stack_0000fffc;
  byte bVar17;
  
  bVar17 = *(byte *)((int)*(undefined4 *)((uint)classStr << 2) + 0x3e);
  pfVar11 = (far_t *)CONCAT11((char)((uint)in_stack_0000fffc >> 8),bVar17);
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
                        *(uint8_t *)((int)*(undefined4 *)((uint)classStr << 2) + 0xa4),classStr);
  }
  else {
    iVar16 = 5;
    uVar6 = ovr_randBelow(5);
    pfVar8 = (far_t *)(uVar6 & 0xff);
    pfVar5 = in_stack_00000004;
    pfVar13 = (far_t *)0x0;
    switch(pfVar8) {
    case (far_t *)0x0:
      do {
        cVar15 = (char)in_stack_0000ffea;
        if (199 < iVar16 + (uint)*(byte *)(y + (int)pfVar8 * uVar10 + 10)) {
          unaff_SI = (char *)(*(int *)(y + (int)pfVar5 * 0x1e + 3) %
                             (int)(uint)*(byte *)(y + (int)pfVar5 * 0x1e + 10));
          pfVar11 = (far_t *)((int)&pfVar11->ofs + (uint)*(byte *)(y + (int)pfVar5 * 0x1e + 9));
          unaff_DI = (far_t *)((int)&unaff_DI->ofs + (uint)*(byte *)(y + (int)pfVar5 * 0x1e + 9));
          cVar15 = cVar15 + *(char *)(y + (int)pfVar5 * 0x1e + 9);
          (*(uint8_t *)((uint8_t *)&(pfStack_18))) = (char)pfStack_18 + *(char *)(y + (int)pfVar5 * 0x1e + 9);
        }
        uVar12 = in_stack_0000ffec + 1;
        pfVar8 = pfVar5;
        while (uVar9 = (undefined2)((ulong)((long)(int)pfVar8 * 0x1e) >> 0x10),
              *(byte *)(y + (int)((long)(int)pfVar8 * 0x1e) + 0x1b) <= uVar12) {
          if ((far_t *)in_stack_0000ffee != (far_t *)0x0 ||
              (int)((ulong)in_stack_0000ffee >> 0x10) != 0) {
            *(char *)&in_stack_0000ffee->ofs = (char)pfStack_18 - cVar15;
          }
          pfVar8 = (far_t *)((int)&pfVar8->ofs + 1);
          if ((destY <= pfVar8) || (*(char *)(y + (int)pfVar8 * 0x1e + 0x1b) == '\0')) {
            return puStackY_28;
          }
          uVar12 = (uint)*(byte *)(y + (int)pfVar8 * 0x1e);
          uStackY_24 = (uint8_t *)CONCAT22(uStackY_26,puStackY_28 + uVar12 * 4 + 0x58);
          *(uint16_t *)((int)(puStackY_28 + uVar12 * 4) + 2) = destX;
          *(uint16_t *)(puStackY_28 + uVar12 * 4) = y + (int)pfVar8 * 0x1e;
          pfVar11 = (far_t *)*(undefined2 *)(y + (int)pfVar8 * 0x1e + 1);
          unaff_SI = (char *)*(uint16_t *)(y + (int)pfVar8 * 0x1e + 3);
          unaff_DI = (far_t *)*(uint16_t *)(y + (int)pfVar8 * 0x1e + 5);
          if (*(int *)(y + (int)pfVar8 * 0x1e + 7) - (int)unaff_SI < 0) {
                    /* WARNING: Subroutine does not return */
            ovr_stExit(0x33);
          }
          in_stack_0000ffee = (far_t *)0x0;
          uVar12 = 0;
        }
        iVar16 = 0x15;
        in_stack_0000ffee = (far_t *)CONCAT22(unaff_SI,pfVar11);
        in_stack_0000ffea = in_stack_00000004;
        in_stack_0000ffec = x;
        pfVar5 = ovr_stshRleSub(in_stack_00000004,(uint8_t *)x,(uint16_t)pfVar11,(uint16_t)unaff_SI,
                                (uint16_t)unaff_DI,0x15,21);
        _pfStackY_20 = (far_t *)CONCAT22(uVar9,pfVar5);
        *(undefined1 *)&pfVar5[1].seg = 2;
        *(undefined2 *)((int)&pfVar5[1].seg + 1) = *(undefined2 *)(y + (int)pfVar8 * 0x1e + 0xb);
        *(undefined2 *)((int)&pfVar5[2].ofs + 1) = *(undefined2 *)(y + (int)pfVar8 * 0x1e + 0xd);
        *(undefined2 *)((uint8_t *)uStackY_24 + 2) = uVar9;
        *(far_t **)uStackY_24 = pfVar5;
        uStackY_24 = (uint8_t *)CONCAT22(uVar9,(uint8_t *)((int)&pfVar5->ofs + 1));
        pfStack_18 = pfVar13;
        if ((*(byte *)(y + (int)pfVar8 * 0x1e + 0x1c) & 1) == 0) {
          *(undefined1 *)((int)&pfVar5[1].ofs + 1) = *(undefined1 *)(y + (int)pfVar8 * 0x1e + 0xf);
        }
        else {
          pfVar14 = pfVar11;
          if (in_stack_0000ffec == 0) {
            uVar12 = 0;
            pfVar13 = pfVar11;
            while (uVar12 < 2) {
              if (unaff_DI + iVar16 * 0x50 + 0x50 < pfVar13) {
                    /* WARNING: Subroutine does not return */
                ovr_stExit(9);
              }
              if (*(char *)((int)&pfVar13[iVar16 * 0x50 + 0x50].ofs + (int)&in_stack_00000004->ofs)
                  == -2) {
                pfVar14 = pfVar13;
                if (uVar12 == 0) {
                  pfVar14 = pfStack_18;
                  in_stack_0000ffea = pfVar13;
                }
                pfStack_18 = pfVar14;
                uVar12 = uVar12 + 1;
              }
              pfVar13 = (far_t *)((int)&pfVar13->ofs + 1);
            }
            in_stack_0000ffee = (far_t *)CONCAT22(uVar9,(far_t *)((int)&pfVar5[1].ofs + 1));
          }
          else {
            while (*(char *)((int)&pfVar14[iVar16 * 0x50 + 0x50].ofs + (int)&in_stack_00000004->ofs)
                   != -2) {
              if (unaff_DI + iVar16 * 0x50 + 0x50 < pfVar14) {
                    /* WARNING: Subroutine does not return */
                ovr_stExit(9);
              }
              pfVar14 = (far_t *)((int)&pfVar14->ofs + 1);
            }
            (*(uint8_t *)((uint8_t *)&(pfStack_18))) = (char)pfVar13;
            *(char *)((int)&pfVar5[1].ofs + 1) = (char)pfStack_18 - (char)pfVar14;
            pfStack_18 = pfVar14;
          }
        }
        *(undefined1 *)&_pfStackY_20->ofs = 4;
        *(undefined2 *)((int)&pfVar5->seg + 1) = 0;
        *(undefined2 *)((int)&pfVar5->ofs + 1) = 0;
        unaff_SI = unaff_SI + *(byte *)(y + (int)pfVar8 * 0x1e + 10);
        uVar10 = 0x1e;
        pfVar5 = pfVar8;
        pfVar13 = (far_t *)((char *)"bath house" + 10);
      } while( true );
    case (far_t *)0x1:
      uVar1 = in(uVar10);
      *(undefined1 *)x = uVar1;
      midpakAd.ofs = (uint16_t)stshStoreFile_2(unaff_DI,unaff_SI,(uint16_t)pfVar11);
      midpakAd.seg = uVar10;
      cmidpakComOfs = stshStoreFile_2((far_t *)"cmidpak.com",(char *)"puppetmaker" + 3,1);
      _cmidpakComSeg = uVar10;
      ibmsndComOfs = stshStoreFile_2((far_t *)"ibmsnd.com",(char *)"puppetmaker" + 3,1);
      ibmsndComSeg = uVar10;
      sblasterComOfs = stshStoreFile_2((far_t *)"sblaster.com",(char *)"puppetmaker" + 3,1);
      audioPlaceholder2.seg = 0;
      audioPlaceholder2.ofs = 0;
      sblasterComSeg = uVar10;
      fibmbakComOfs = stshStoreFile_2((far_t *)"fibmbak.com",(char *)"puppetmaker" + 3,1);
      fibmbakComSeg = uVar10;
      pfVar8 = stshStoreFile_2((far_t *)"sbpro.com",(char *)"puppetmaker" + 3,1);
      sbproComOfs = pfVar8;
      sbproComSeg = uVar10;
      sbproComCopyOfs = pfVar8;
      sbproComCopySeg = uVar10;
      paudioComOfs = stshStoreFile_2((far_t *)"paudio.com",(char *)"puppetmaker" + 3,1);
      sblasterComCopySeg = sblasterComSeg;
      sblasterComCopyOfs = sblasterComOfs;
      pfVar11 = sblasterComOfs;
      paudioComSeg = pfVar8;
      adlibComOfs = stshStoreFile_2((far_t *)"adlib.com",(char *)"puppetmaker" + 3,1);
      adlibComSeg = pfVar11;
      adlibgComOfs = stshStoreFile_2((far_t *)"adlibg.com",(char *)"puppetmaker" + 3,1);
      audioPlaceholder3.seg = 0;
      audioPlaceholder3.ofs = 0;
      musDriver0Seg = 0;
      musDriver0Ofs = 0;
      adlibgComSeg = pfVar11;
      sbfmAdvOfs = stshStoreFile_2((far_t *)"sbfm.adv",(char *)"puppetmaker" + 3,1);
      audioPlaceholder0.seg = 0;
      audioPlaceholder0.ofs = 0;
      audioPlaceholder1.seg = 0;
      audioPlaceholder1.ofs = 0;
      sbfmAdvSeg = pfVar11;
      sbp2fmAdvOfs = stshStoreFile_2((far_t *)"sbp2fm.adv",(char *)"puppetmaker" + 3,1);
      sbp2fmAdvSeg = pfVar11;
      sbp1fmAdvOfs = stshStoreFile_2((far_t *)"sbp1fm.adv",(char *)"puppetmaker" + 3,1);
      sbp1fmAdvSeg = pfVar11;
      pasfmAdvOfs = stshStoreFile_2((far_t *)"pasfm.adv",(char *)"puppetmaker" + 3,1);
      pasfmAdvSeg = pfVar11;
      pasoplAdvOfs = stshStoreFile_2((far_t *)"pasopl.adv",(char *)"puppetmaker" + 3,1);
      pasoplAdvSeg = pfVar11;
      adlibAdvOfs = stshStoreFile_2((far_t *)"adlib.adv",(char *)"puppetmaker" + 3,1);
      adlibAdvSeg = pfVar11;
      adlibgAdvOfs = stshStoreFile_2((far_t *)"adlibg.adv",(char *)"puppetmaker" + 3,1);
      adlibgAdvSeg = pfVar11;
      mt32mpuAdvOfs = stshStoreFile_2((far_t *)"mt32mpu.adv",(char *)"puppetmaker" + 3,1);
      mt32mpuAdvSeg = pfVar11;
      return (uint8_t *)mt32mpuAdvOfs;
    case (far_t *)0x2:
      iVar16 = ovr_ovc23_findClearColumn(GfxRndSeed,GfxRndSeed2);
      if (iVar16 < 0) {
        ovr_drawTextAt((char *)"You cannot attract units to this location.",0x2410);
        txt = (uint8_t *)((char *)"puppetmaker" + 3);
        *(undefined1 *)&in_stack_00000004[-0x1be0].seg = 0;
      }
      else {
        pcVar3 = (char *)func_0x0004f501();
        callResultTemp = (uint16_t)pcVar3;
        if (pcVar3 < unaff_SI) {
          *(char *)&in_stack_00000004[-0x1be0].seg = (char)pcVar3;
          unaff_SI = pcVar3;
        }
        puVar4 = (undefined4 *)(((uint)pfVar11 & 0xff) << 2);
        uVar2 = *puVar4;
        cVar15 = *(char *)((int)uVar2 + 0x2f);
        txt = (uint8_t *)CONCAT11((char)((uint)puVar4 >> 8),cVar15);
        if (cVar15 != -1) {
          ovr_ovc41_pluralSuffix((int)unaff_SI);
          uVar10 = 0x2410;
          _pfStackY_20 = (far_t *)CONCAT22(acStackY_56,0x23d5);
          uStackY_24 = (uint8_t *)CONCAT22(0xad0,(uint8_t *)uStackY_24);
          txt = (uint8_t *)
                ovr_stsprintf(acStackY_56,unaff_SS,
                              (char *)"Attracting %d of a possible %d %s%s to this location.");
          ovr_drawTextAt((char *)txt,uVar10);
        }
      }
      return txt;
    case (far_t *)0x3:
      ((int *)StshHandles)[(int)in_stack_00000004] = (int)pfVar8;
      *(undefined2 *)((int)(long *)StshPtrs + (int)in_stack_00000004 * 4 + 2) = 0;
      *(undefined2 *)((long *)StshPtrs + (int)in_stack_00000004) = 0;
      return (uint8_t *)in_stack_00000004;
    case (far_t *)0x4:
      smm_restore_state();
      return (uint8_t *)pfVar8;
    default:
      bVar17 = (byte)((uint)pfVar11 >> 8);
      if (partyIndex == 0x2) {
        peVar7 = ovr_ovc15_usesLDIV_at_((uint16_t)in_stack_00000004,x,y,destX,bVar17,0xa,classStr);
      }
      else {
        peVar7 = ovr_ovc15_usesLDIV_at_
                           ((uint16_t)in_stack_00000004,x,y,destX,bVar17,
                            *(uint8_t *)((int)*(undefined4 *)((uint)classStr << 2) + 0xa4),classStr)
        ;
      }
    }
  }
  return (uint8_t *)peVar7;
}



/* 48ac:0382 */

/* [R2] string "type %d len %ld \r" */

char * __cdecl16far
ovc18_textTypeLen(uint8_t partyIndex,uint16_t destX,uint16_t destY,uint8_t textVariant)

{
  int *piVar1;
  uint16_t uVar2;
  far_t buf;
  DW sz;
  far_t handle;
  far_t ptr_ofs;
  byte bVar3;
  uint uVar4;
  uint8_t *puVar5;
  uint32_t *puVar6;
  char *pcVar7;
  int iVar8;
  uint in_CX;
  uint uVar9;
  int iVar11;
  uint uVar12;
  undefined2 unaff_SI;
  long *unaff_DI;
  uint16_t uVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  char *unaff_SS;
  bool bVar16;
  far_t fVar17;
  undefined1 in_stack_00000005;
  undefined1 in_stack_0000000b;
  int *in_stack_0000000c;
  int *in_stack_00000014;
  int *in_stack_00000018;
  int *in_stack_0000001c;
  int *in_stack_00000020;
  char acStackY_f6 [120];
  char acStackY_7e [92];
  undefined2 uStackY_22;
  undefined2 uStackY_20;
  undefined1 uVar18;
  undefined1 in_stack_0000ffef;
  undefined1 uVar19;
  undefined1 uVar20;
  undefined1 uVar21;
  undefined1 uVar22;
  undefined1 uVar23;
  undefined1 uVar24;
  uint8_t term;
  char cVar25;
  undefined1 uVar26;
  undefined1 uVar27;
  undefined1 uStack_4;
  undefined1 uStack_3;
  uint16_t uVar10;
  
  _destY = (int *)CONCAT13(in_stack_0000000b,CONCAT12(textVariant,destY));
  uVar2 = CONCAT11(in_stack_00000005,partyIndex);
  uVar15 = 0x48ac;
  uVar22 = (undefined1)unaff_SI;
  uVar23 = (undefined1)((uint)unaff_SI >> 8);
  uVar20 = SUB21(unaff_DI,0);
  uVar21 = (undefined1)((uint)unaff_DI >> 8);
  iVar8 = ((int *)((uint)partyIndex * 4))[1];
  iVar11 = *(int *)((uint)partyIndex * 4);
  uVar18 = (undefined1)iVar8;
  uVar19 = (undefined1)((uint)iVar8 >> 8);
  uVar24 = (undefined1)iVar11;
  term = (uint8_t)((uint)iVar11 >> 8);
  uVar10 = *(uint16_t *)(iVar11 + 0x39);
  uVar13 = *(uint16_t *)(iVar11 + 0x3b);
  uVar26 = (undefined1)uVar13;
  uVar27 = (undefined1)(uVar13 >> 8);
  uVar14 = (undefined2)(CONCAT13(uVar19,CONCAT12(uVar18,iVar11)) >> 0x10);
  uVar4 = (uint)*(byte *)(iVar11 + 0x2f);
  if (uVar4 == 4) {
    uStackY_20 = 0x48ac;
    uVar15 = 0x2322;
    uStackY_22 = 0x8fca;
    ovr_ovc15_usesLDIV_at_(uVar10,uVar13,destX,destY,10,0x1,partyIndex);
  }
  else if (uVar4 < 5) {
    if (uVar4 < 4) {
      bVar16 = uVar4 == 0;
      uVar13 = destY;
      switch(uVar4) {
      case 1:
        uVar12 = *(uint *)(uVar4 * 2 + 0xc);
        uVar9 = uVar12 + 0x14;
        iVar8 = uVar4 + (0xffeb < uVar12);
        if (StshCount < 0xd93) {
          StshCount = StshCount + 1;
          LXMUL_at_(unaff_DI,CONCAT13((char)(uVar9 >> 8),CONCAT12((char)uVar9,iVar11)),
                    CONCAT13((char)(uVar10 >> 8),CONCAT12((char)uVar10,iVar8)));
          uVar18 = 0;
          uVar19 = 0x10;
          (*(uint8_t *)((uint8_t *)&(fVar17.seg))) = uVar20;
          fVar17.ofs = 0x1000;
          (*(uint8_t *)((uint8_t *)&(fVar17.seg) + 1)) = uVar21;
          (*(uint8_t *)((uint8_t *)&(ptr_ofs.ofs) + 1)) = uVar23;
          (*(uint8_t *)((uint8_t *)&(ptr_ofs.ofs))) = uVar22;
          (*(uint8_t *)((uint8_t *)&(ptr_ofs.seg))) = uVar24;
          (*(uint8_t *)((uint8_t *)&(ptr_ofs.seg) + 1)) = term;
          fVar17 = PADD_at_(fVar17,ptr_ofs);
          uVar10 = fVar17.seg;
          puVar6 = ovr_mkp((uint32_t *)fVar17.ofs,uVar10,CONCAT11(uVar19,uVar18));
          uStack_4 = (undefined1)uVar10;
          uStack_3 = (undefined1)(uVar10 >> 8);
          uVar20 = SUB21(puVar6,0);
          uVar21 = (undefined1)((uint)puVar6 >> 8);
          uVar14 = (undefined2)(CONCAT13(uStack_3,CONCAT12(uStack_4,puVar6)) >> 0x10);
          *(int *)((int)puVar6 + 7) = iVar8;
          *(uint *)((int)puVar6 + 5) = uVar9;
          *(undefined1 *)CONCAT13(uStack_3,CONCAT12(uStack_4,puVar6)) = 0;
          uVar10 = StshCtOfs.lo;
          uVar14 = (undefined2)(CONCAT13(uStack_3,CONCAT12(uStack_4,puVar6)) >> 0x10);
          *(uint16_t *)((int)puVar6 + 3) = StshCtOfs.hi;
          *(uint16_t *)((int)puVar6 + 1) = uVar10;
          uVar14 = (undefined2)(CONCAT13(uStack_3,CONCAT12(uStack_4,puVar6)) >> 0x10);
          *(undefined2 *)((int)puVar6 + 0x13) = 0;
          *(undefined2 *)((int)puVar6 + 0x11) = 0;
          bVar16 = CARRY2(StshCtOfs.lo,uVar9);
          StshCtOfs.lo = StshCtOfs.lo + uVar9;
          StshCtOfs.hi = StshCtOfs.hi + iVar8 + (uint)bVar16;
          uVar14 = (undefined2)(CONCAT13(uStack_3,CONCAT12(uStack_4,puVar6)) >> 0x10);
          *(undefined2 *)((int)puVar6 + 0xb) = 0;
          *(undefined2 *)((int)puVar6 + 9) = 0;
          uVar14 = (undefined2)(CONCAT13(uStack_3,CONCAT12(uStack_4,puVar6)) >> 0x10);
          *(undefined2 *)((int)puVar6 + 0xf) = 0;
          *(undefined2 *)((int)puVar6 + 0xd) = 0;
          if (DebugVerbose != false) {
            uStackY_20 = 0xbbd4;
            printf("type %d len %ld \r");
            ovr_biosReadKey();
          }
          uStackY_20 = 0xbbf0;
          buf.seg = destX;
          buf.ofs = uVar2;
          (*(uint8_t *)((uint8_t *)&(sz.hi))) = (char)iVar8;
          sz.lo = uVar9;
          (*(uint8_t *)((uint8_t *)&(sz.hi) + 1)) = (char)((uint)iVar8 >> 8);
          stshWriteFile(StshFile,buf,sz);
          (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)destX;
          handle.ofs = uVar2;
          (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)(destX >> 8);
          ovr_stshFree(handle);
          return (char *)CONCAT11(uVar21,uVar20);
        }
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0x24);
      case 2:
        uVar12 = destX + 1;
        piVar1 = (int *)(uVar4 * 2 + uVar12);
        *piVar1 = *piVar1 + 1;
        do {
          pcVar7 = ovr_ovc15_textArena(uVar12);
          if (((uint)pcVar7 & 0xff) == 0) goto L_attact_3f0b_26bd_2767;
          destY = destY - 1;
          while (destY == 0) {
L_attact_3f0b_26bd_2767:
            do {
              uVar12 = uVar12 + 1;
              if (EntityCount <= uVar12) {
                return (char *)"puppetmaker" + 3;
              }
              uVar14 = (undefined2)((ulong)Entities >> 0x10);
              uVar14 = ovr_ovc23_isCursorAt
                                 ((((entity_t *)Entities + uVar12)->base).x,
                                  ((entity_t *)Entities)[uVar12].base.y);
            } while ((char)uVar14 == '\0');
            destY = func_0x0004f944();
          }
        } while( true );
      case 3:
                    /* WARNING: Read-only address (ram,0x000277ff) is written */
        s_cue9a_xmi_2410_36fe[1] = -0x58;
        *(uint *)(&stack0x681c + destX) = *(uint *)(&stack0x681c + destX) & in_CX;
        ovr_blitLabel((char *)CONCAT11(uVar20,in_stack_0000ffef),(uint8_t *)CONCAT11(uVar22,uVar21),
                      CONCAT11(uVar24,uVar23),term);
        uVar20 = 0xdc;
        uVar21 = 0;
        pcVar7 = litoa10(acStackY_f6,
                         CONCAT13((char)((uint)*(undefined2 *)(uVar2 + 0x62) >> 8),
                                  CONCAT12((char)*(undefined2 *)(uVar2 + 0x62),
                                           *(undefined2 *)(uVar2 + 0x60))));
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar11 >> 8),CONCAT12((char)iVar11,pcVar7)),
                   CONCAT11(uVar21,uVar20));
        TextBlitY = TextBlitY + 10;
        TextBlitX = 0x37;
        ovr_blitLabel((char *)"Housing",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                      (uint8_t)Font02.seg);
        uVar20 = 0x7d;
        uVar21 = 0;
        pcVar7 = ovr_stsprintf(acStackY_7e,unaff_SS,(char *)"%d");
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar11 >> 8),CONCAT12((char)iVar11,pcVar7)),
                   CONCAT11(uVar21,uVar20));
        TextBlitX = 0x82;
        ovr_blitLabel((char *)"Food storage",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                      (uint8_t)Font02.seg);
        uVar20 = 0xdc;
        uVar21 = 0;
        pcVar7 = litoa10(acStackY_f6,
                         CONCAT13((char)((uint)*(undefined2 *)(uVar2 + 0x80) >> 8),
                                  CONCAT12((char)*(undefined2 *)(uVar2 + 0x80),
                                           *(undefined2 *)(uVar2 + 0x7e))));
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar11 >> 8),CONCAT12((char)iVar11,pcVar7)),
                   CONCAT11(uVar21,uVar20));
        TextBlitY = TextBlitY + 0xf;
        if (*(int *)(uVar2 + 0xa0) != 0) {
          TextBlitX = 0x37;
          if (*(int *)(uVar2 + 0xa2) < 0) {
            ovr_blitLabel((char *)"Food sold",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                          (uint8_t)Font02.seg);
            uVar20 = 0x7d;
            uVar21 = 0;
            iVar8 = -*(int *)(uVar2 + 0xa2);
            iVar11 = iVar8 >> 0xf;
            cVar25 = (char)(iVar8 >> 0xf);
            pcVar7 = litoa10(acStackY_f6,CONCAT13(cVar25,CONCAT12(cVar25,iVar8)));
            manage_blitLabelRight
                      ((char *)CONCAT13((char)((uint)iVar11 >> 8),CONCAT12((char)iVar11,pcVar7)),
                       CONCAT11(uVar21,uVar20));
          }
          else {
            ovr_blitLabel((char *)"Food bought",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                          (uint8_t)Font02.seg);
            uVar20 = 0x7d;
            uVar21 = 0;
            iVar8 = *(int *)(uVar2 + 0xa2);
            iVar11 = iVar8 >> 0xf;
            cVar25 = (char)(iVar8 >> 0xf);
            pcVar7 = litoa10(acStackY_f6,CONCAT13(cVar25,CONCAT12(cVar25,iVar8)));
            manage_blitLabelRight
                      ((char *)CONCAT13((char)((uint)iVar11 >> 8),CONCAT12((char)iVar11,pcVar7)),
                       CONCAT11(uVar21,uVar20));
          }
          TextBlitX = 0x82;
          ovr_blitLabel((char *)"Max. trade",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                        (uint8_t)Font02.seg);
          uVar20 = 0xdc;
          uVar21 = 0;
          pcVar7 = litoa10(acStackY_f6,(ulong)*(uint *)(uVar2 + 0xa0));
          manage_blitLabelRight
                    ((char *)CONCAT13((char)((uint)iVar11 >> 8),CONCAT12((char)iVar11,pcVar7)),
                     CONCAT11(uVar21,uVar20));
        }
        TextBlitY = TextBlitY + 0xf;
        TextBlitX = 0x37;
        ovr_blitLabel((char *)"Income",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                      (uint8_t)Font02.seg);
        uVar20 = 0xdc;
        uVar21 = 0;
        iVar8 = *(int *)(uVar2 + 0x54);
        iVar11 = iVar8 >> 0xf;
        cVar25 = (char)(iVar8 >> 0xf);
        pcVar7 = litoa10(acStackY_7e,CONCAT13(cVar25,CONCAT12(cVar25,iVar8)));
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar11 >> 8),CONCAT12((char)iVar11,pcVar7)),
                   CONCAT11(uVar21,uVar20));
        TextBlitY = TextBlitY + 10;
        TextBlitX = 0x37;
        ovr_blitLabel((char *)"Gold",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                      (uint8_t)Font02.seg);
        uVar20 = 0xdc;
        uVar21 = 0;
        pcVar7 = litoa10(acStackY_7e,
                         CONCAT13((char)((uint)*(undefined2 *)(uVar2 + 0x58) >> 8),
                                  CONCAT12((char)*(undefined2 *)(uVar2 + 0x58),
                                           *(undefined2 *)(uVar2 + 0x56))));
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar11 >> 8),CONCAT12((char)iVar11,pcVar7)),
                   CONCAT11(uVar21,uVar20));
        TextBlitY = TextBlitY + 10;
        TextBlitX = 0x37;
        ovr_blitLabel((char *)"Vault storage",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                      (uint8_t)Font02.seg);
        uVar20 = 0xdc;
        uVar21 = 0;
        pcVar7 = litoa10(acStackY_7e,
                         CONCAT13((char)((uint)*(undefined2 *)(uVar2 + 0x8c) >> 8),
                                  CONCAT12((char)*(undefined2 *)(uVar2 + 0x8c),
                                           *(undefined2 *)(uVar2 + 0x8a))));
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar11 >> 8),CONCAT12((char)iVar11,pcVar7)),
                   CONCAT11(uVar21,uVar20));
        TextBlitY = TextBlitY + 10;
        TextBlitX = 0x37;
        ovr_blitLabel((char *)"Fund Access",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                      (uint8_t)Font02.seg);
        uVar20 = 0xdc;
        uVar21 = 0;
        uVar14 = ovr_ovc45_usesLDIV_at_(*(uint8_t *)(uVar2 + 0x51));
        pcVar7 = litoa10(acStackY_f6,
                         CONCAT13((char)((uint)iVar11 >> 8),CONCAT12((char)iVar11,uVar14)));
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar11 >> 8),CONCAT12((char)iVar11,pcVar7)),
                   CONCAT11(uVar21,uVar20));
        TextBlitY = TextBlitY + 10;
        TextBlitX = 0x37;
        ovr_blitLabel((char *)"Common fund",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                      (uint8_t)Font02.seg);
        uVar20 = 0xdc;
        uVar21 = 0;
        pcVar7 = litoa10(acStackY_f6,
                         CONCAT13((char)((uint)GPopulationHi >> 8),
                                  CONCAT12((char)GPopulationHi,GPopulationLo)));
        manage_blitLabelRight
                  ((char *)CONCAT13((char)((uint)iVar11 >> 8),CONCAT12((char)iVar11,pcVar7)),
                   CONCAT11(uVar21,uVar20));
        bVar3 = manage_findFirstLeader();
        pcVar7 = (char *)"puppetmaker" + 3;
        TextBlitY = TextBlitY + 0xf;
        if ((*(char *)(uVar2 + 0x86) != '\0') && (bVar3 != 0xff)) {
          pcVar7 = (char *)((uint)bVar3 << 2);
          uVar14 = 0x217a;
          if (*(byte *)((int)*(undefined4 *)pcVar7 + 0x86) < 9) {
            manage_usesBlitLabel2("popularity",0x7d);
            manage_usesBlitLabel2("city blocks",0xdc);
            TextBlitY = TextBlitY + 10;
            TextBlitX = 0x11;
            ovr_blitLabel((char *)"Current",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                          (uint8_t)Font02.seg);
            uVar20 = 0x7d;
            uVar21 = 0;
            manage_usesGLeaderCount();
            pcVar7 = ovr_stsprintf(acStackY_7e,unaff_SS,(char *)"%d%%");
            manage_blitLabelRight
                      ((char *)CONCAT13((char)((uint)uVar14 >> 8),CONCAT12((char)uVar14,pcVar7)),
                       CONCAT11(uVar21,uVar20));
            uVar20 = 0xdc;
            uVar21 = 0;
            pcVar7 = ovr_stsprintf(acStackY_7e,unaff_SS,(char *)"%d");
            manage_blitLabelRight
                      ((char *)CONCAT13((char)((uint)uVar14 >> 8),CONCAT12((char)uVar14,pcVar7)),
                       CONCAT11(uVar21,uVar20));
            TextBlitY = TextBlitY + 10;
            TextBlitX = 0x11;
            ovr_blitLabel((char *)"to promote",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                          (uint8_t)Font02.seg);
            uVar20 = 0x7d;
            uVar21 = 0;
            ovr_season_usesDifficulty();
            pcVar7 = ovr_stsprintf(acStackY_7e,unaff_SS,(char *)"%d%%");
            manage_blitLabelRight
                      ((char *)CONCAT13((char)((uint)uVar14 >> 8),CONCAT12((char)uVar14,pcVar7)),
                       CONCAT11(uVar21,uVar20));
            uVar20 = 0xdc;
            uVar21 = 0;
            ovr_season_usesGPromotableCount2();
            pcVar7 = ovr_stsprintf(acStackY_7e,unaff_SS,(char *)"%d");
            manage_blitLabelRight
                      ((char *)CONCAT13((char)((uint)uVar14 >> 8),CONCAT12((char)uVar14,pcVar7)),
                       CONCAT11(uVar21,uVar20));
          }
        }
        return pcVar7;
      }
      do {
        if (bVar16) {
          *in_stack_00000020 = *in_stack_00000020 + 1;
        }
        while( true ) {
          while( true ) {
            do {
              uVar13 = uVar13 + 1;
              if (GRecordCount <= uVar13) {
                iVar8 = *in_stack_0000001c;
                iVar11 = *in_stack_00000020;
                *_destY = *_destY - *in_stack_0000001c;
                *in_stack_0000000c = *in_stack_0000000c - *in_stack_00000020;
                return (char *)(CONCAT11(uStack_3,uStack_4) - (iVar8 + iVar11));
              }
            } while ((*(uint8_t *)(uVar13 * 0x12 + 9) != partyIndex) ||
                    (bVar3 = *(byte *)(uVar13 * 0x12 + 8),
                    *(char *)((uint)bVar3 * 0x27 + 0x133) != (char)destX));
            *in_stack_00000014 = *in_stack_00000014 + 1;
            if (*(char *)((uint)bVar3 * 0x27 + 0x131) != '\x01') break;
            *in_stack_00000018 = *in_stack_00000018 + 1;
          }
          if (*(char *)((uint)bVar3 * 0x27 + 0x131) != '\x02') break;
          *in_stack_0000001c = *in_stack_0000001c + 1;
        }
        bVar16 = *(char *)((uint)bVar3 * 0x27 + 0x131) == '\x03';
      } while( true );
    }
  }
  else if (uVar4 == 5) {
    uStackY_20 = 0x48ac;
    uVar15 = 0x2322;
    uStackY_22 = 0x8fe5;
    ovr_ovc15_usesLDIV_at_(uVar10,uVar13,destX,destY,8,0x1,partyIndex);
  }
  else if (uVar4 == 6) {
    uStackY_20 = 0x48ac;
    uVar15 = 0x2322;
    uStackY_22 = 0x9000;
    ovr_ovc15_usesLDIV_at_(uVar10,uVar13,destX,destY,0xb,0x1,partyIndex);
  }
  else if ((uVar4 == 0xff) &&
          ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)*(byte *)(iVar11 + 0x3e) * 0x95) &
           0x800) == 0)) {
    if (textVariant == 0x0) {
      uStackY_20 = 0x48ac;
      uVar15 = 0x2322;
      uStackY_22 = 0x906a;
      ovr_ovc15_usesLDIV_at_(uVar10,uVar13,destX,destY,*(byte *)(iVar11 + 0x3e),0x1,partyIndex);
    }
    else {
      uStackY_20 = 0x48ac;
      uVar15 = 0x2322;
      uStackY_22 = 0x904a;
      ovr_ovc15_usesLDIV_at_(uVar10,uVar13,destX,destY,*(byte *)(iVar11 + 0x3e),0x1,partyIndex);
    }
  }
  puVar5 = (uint8_t *)((uint)*(byte *)(CONCAT11(term,uVar24) + 0x3e) * 0x95);
  if ((*(uint *)(puVar5 + 0x2714) & 0x8000) != 0) {
    uStackY_22 = 0x90a3;
    uStackY_20 = uVar15;
    puVar5 = ovc18_spawnClassAgent
                       (CONCAT11(uVar27,uVar26),destX,destY,1,partyIndex,textVariant,
                        CONCAT11(uVar21,uVar20));
  }
  return (char *)puVar5;
}



/* 48ac:05f2 */

/* Checks a fortress site and reports the matching rejection message. */

void __cdecl16far ovc18_checkFortressPlacement(char strongholdKind)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined2 uVar8;
  uint16_t unaff_SS;
  far_t dst;
  undefined1 auStack_12 [13];
  uint8_t uStack_5;
  uint uStack_4;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)auStack_12;
  F_SCOPY(far_from_u32((uint32_t)(0x241045b9)),dst);
  for (uVar6 = 0; uVar6 < EntityCount; uVar6 = uVar6 + 1) {
    uVar8 = (undefined2)((ulong)Entities >> 0x10);
    if (*(char *)((int)(char **)GMenuStrings +
                 (uint)((entity_t *)Entities)[uVar6].base.gindex * 0x95 + 0x1f) != '\0') {
      uVar2 = ovr_alignUp4((((entity_t *)Entities + uVar6)->base).x);
      uVar3 = ovr_alignUp4(GfxRndSeed);
      if ((uVar2 == uVar3) && (((entity_t *)Entities)[uVar6].base.y == GfxRndSeed2)) {
        ovr_stats_openCastlePanel();
        ovr_say((char *)"A fortress cannot be placed among enemy units.");
        MsgShown = 1;
        return;
      }
    }
  }
  for (iVar7 = 0; iVar7 < (int)(uint)GLeaderCount; iVar7 = iVar7 + 1) {
    if (((*(char *)((int)*(undefined4 *)(iVar7 << 2) + 0x3d) != '\0') &&
        (*(uint16_t *)((int)*(undefined4 *)(iVar7 << 2) + 0x39) == GfxRndSeed)) &&
       (*(uint16_t *)((int)*(undefined4 *)(iVar7 << 2) + 0x3b) == GfxRndSeed2)) {
      ovr_stats_openCastlePanel();
      ovr_say((char *)"Cannot place another fortress here.");
      MsgShown = 1;
      return;
    }
  }
  if (strongholdKind == '\x02') {
    uVar6 = ovr_constr_usesGMapFlags(GfxRndSeed - 2,GfxRndSeed2);
    if ((((uVar6 & 0xff) == 0) ||
        (uVar6 = ovr_constr_usesGMapFlags(GfxRndSeed - 1,GfxRndSeed2), (uVar6 & 0xff) == 0)) ||
       ((uVar6 = ovr_constr_usesGMapFlags(GfxRndSeed,GfxRndSeed2), (uVar6 & 0xff) == 0 ||
        (uVar6 = ovr_constr_usesGMapFlags(GfxRndSeed + 1,GfxRndSeed2), (uVar6 & 0xff) == 0)))) {
      ovr_stats_openCastlePanel();
      pcVar4 = ovr_fmVsprintf((char *)"This location is unsuitable for a main stronghold.  %s",
                              (char *)"puppetmaker" + 3);
      ovr_say(pcVar4);
      MsgShown = 1;
      return;
    }
  }
  else {
    uVar6 = ovr_constr_usesGMapFlags(GfxRndSeed - 1,GfxRndSeed2);
    if (((uVar6 & 0xff) == 0) ||
       (uVar6 = ovr_constr_usesGMapFlags(GfxRndSeed,GfxRndSeed2), (uVar6 & 0xff) == 0)) {
      ovr_stats_openCastlePanel();
      pcVar4 = ovr_fmVsprintf((char *)"This location is unsuitable.  %s",(char *)"puppetmaker" + 3);
      ovr_say(pcVar4);
      MsgShown = 1;
      return;
    }
  }
  pcVar4 = ovr_draw_textArena();
  if (((uint)pcVar4 & 0xff) == 0) {
    ovr_stats_openCastlePanel();
    ovr_say((char *)"Your stronghold is too far away.");
    MsgShown = 1;
  }
  else {
    if (1 < CurPartySlot) {
      uStack_4 = 0xffff;
      for (iVar7 = 0; iVar7 < (int)(uint)GLeaderCount; iVar7 = iVar7 + 1) {
        if (((*(char *)((int)*(undefined4 *)(iVar7 << 2) + 0x3d) != '\0') &&
            (*(char *)((int)*(undefined4 *)(iVar7 << 2) + 0x3f) == '\0')) &&
           (uVar6 = *(int *)((int)*(undefined4 *)(iVar7 << 2) + 0x39) - GfxRndSeed,
           uVar3 = (int)uVar6 >> 0xf,
           uVar2 = *(int *)((int)*(undefined4 *)(iVar7 << 2) + 0x3b) - GfxRndSeed2,
           uVar5 = (int)uVar2 >> 0xf, uVar6 = ((uVar6 ^ uVar3) - uVar3) + ((uVar2 ^ uVar5) - uVar5),
           uVar6 < uStack_4)) {
          uStack_4 = uVar6;
        }
      }
      if (0x1e < uStack_4) {
        ovr_stats_openCastlePanel();
        ovr_say((char *)"Your stronghold is too far away.");
        MsgShown = 1;
        return;
      }
    }
    uVar1 = *(undefined4 *)((uint)PartyCount * 4 + -4);
    *(uint16_t *)((int)uVar1 + 0x39) = GfxRndSeed;
    uVar1 = *(undefined4 *)((uint)PartyCount * 4 + -4);
    *(uint16_t *)((int)uVar1 + 0x3b) = GfxRndSeed2;
    uVar1 = *(undefined4 *)((uint)PartyCount * 4 + -4);
    *(undefined1 *)((int)uVar1 + 0x3d) = 1;
    uVar1 = *(undefined4 *)((uint)PartyCount * 4 + -4);
    *(char *)((int)uVar1 + 0x89) = CurPartySlot - 1;
    if (strongholdKind == '\x02') {
      uVar1 = *(undefined4 *)((uint)PartyCount * 4 + -4);
      *(undefined1 *)((int)uVar1 + 0x5a) = 1;
      ovr_createConstructionRecordFar
                (0x89,GfxRndSeed - 2,GfxRndSeed2,&uStack_5,(byte)unaff_SS,PartyCount - 1);
      ovc18_textTypeLen(PartyCount - 1,GfxRndSeed,GfxRndSeed2,0x0);
      ovr_ovc22_usesRandBelow2(PartyCount - 1,(uint16_t)&uStack_5,unaff_SS);
    }
    else {
      uVar1 = *(undefined4 *)((uint)PartyCount * 4 + -4);
      *(char *)((int)uVar1 + 0x5a) = strongholdKind;
      uVar1 = *(undefined4 *)((uint)PartyCount * 4 + -4);
      ovr_createConstructionRecordFar
                (*(byte *)((int)(far_t *)(worldMenuLabels + 0xb) +
                          (uint)*(byte *)((int)uVar1 + 0x3e) * 0x95),GfxRndSeed - 1,GfxRndSeed2,
                 &uStack_5,(byte)unaff_SS,PartyCount - 1);
      ovc18_textTypeLen(PartyCount - 1,GfxRndSeed,GfxRndSeed2,0x0);
    }
    if (2 < Difficulty) {
      ovr_ovc22_usesRandBelow2(PartyCount - 1,(uint16_t)&uStack_5,unaff_SS);
    }
    ovr_ovc22_textRingProt(PartyCount - 1);
    PartyCount = 0;
    ovr_manage_mapPartySlots();
    ovr_stats_openCastlePanel();
    ovr_unit_usesAlignUp4();
    ovr_say((char *)"View %s." + 8);
    if (PlayerIndex == '\0') {
      ovr_ovc30_nextWave(2);
    }
  }
  return;
}



/* 48ac:0bf4 */

/* [R4] calls ovr_randBelow */

uint __cdecl16far ovc18_usesRandBelow(int x,int y,byte bldType,byte unitType)

{
  uint *puVar1;
  uint uVar2;
  uint16_t uVar3;
  short (*paasVar4) [148] [60];
  uint unaff_SI;
  undefined2 uVar5;
  undefined2 uVar6;
  uint uStack_6;
  
  paasVar4 = (short (*) [148] [60])GUnitGrid;
  uVar6 = (undefined2)((ulong)GUnitGrid >> 0x10);
  uVar5 = (undefined2)((ulong)GUnits >> 0x10);
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
      unaff_SI = (*paasVar4)[x][y];
    }
    ((unit_t *)GUnits + unaff_SI)->bldType = bldType;
    ((unit_t *)GUnits)[unaff_SI].level = 8;
    ((unit_t *)GUnits)[unaff_SI].unitType = unitType;
    ((unit_t *)GUnits)[unaff_SI].x = x;
    ((unit_t *)GUnits)[unaff_SI].y = y;
    (*(short (*) [148] [60])GUnitGrid)[x][y] = unaff_SI;
    uVar6 = (undefined2)((ulong)GMapFlags >> 0x10);
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

/* [R2] string "arena" */

char * __cdecl16far ovc18_textArena(uint16_t x,uint16_t y)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = ovr_alignUp4(x);
  uVar3 = 0;
  while( true ) {
    if (EntityCount <= uVar3) {
      return (char *)"arena" + 4;
    }
    uVar2 = ovr_alignUp4((((entity_t *)Entities + uVar3)->base).x);
    if ((uVar2 == uVar1) && (((entity_t *)Entities)[uVar3].base.y == y)) break;
    uVar3 = uVar3 + 1;
  }
  return (char *)CONCAT11((char)(uVar3 * 0x37 >> 8),1);
}



/* 48ac:1092 */

/* [R4] calls ovr_alignUp4 */

uint __cdecl16far ovc18_usesAlignUp4(void)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined2 uVar7;
  uint uStack_4;
  
  pcVar1 = ovr_draw_textArena();
  if (((uint)pcVar1 & 0xff) == 0) {
    uVar5 = 0;
  }
  else {
    for (uVar5 = 0; uVar5 < EntityCount; uVar5 = uVar5 + 1) {
      uVar7 = (undefined2)((ulong)Entities >> 0x10);
      if (*(char *)((int)(char **)GMenuStrings +
                   (uint)((entity_t *)Entities)[uVar5].base.gindex * 0x95 + 0x1f) != '\0') {
        uVar2 = ovr_alignUp4((((entity_t *)Entities + uVar5)->base).x);
        uVar3 = ovr_alignUp4(GfxRndSeed);
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
  return uVar5;
}


