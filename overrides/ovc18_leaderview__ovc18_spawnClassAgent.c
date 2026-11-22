uint8_t * __cdecl16far
ovc18_spawnClassAgent
          (uint16_t x,uint16_t y,uint16_t destX,uint16_t destY,uint8_t classStr,uint8_t partyIndex,
          uint16_t mode)

{
  undefined1 uVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint8_t *txt;
  far_t far *pfVar5;
  uint16_t uVar6;
  entity_t *peVar7;
  far_t far *pfVar8;
  undefined2 uVar9;
  uint16_t uVar10;
  uint16_t unaff_BP;
  undefined2 unaff_SI;
  uint uVar11;
  far_t far *unaff_DI;
  far_t far *pfVar12;
  char *unaff_SS;
  far_t far *in_stack_00000004;
  char acStackY_56 [46];
  uint8_t *puStackY_28;
  undefined2 uStackY_26;
  uint8_t far *uStackY_24;   /* was undefined4: assigned uint8_t * values */
  far_t far *pfStackY_20;
  far_t far *pfVar13;
  far_t far *in_stack_0000ffe8;
  uint16_t in_stack_0000ffec;
  char *in_stack_0000ffee;
  int iVar14;
  char *filename;
  char *pcVar15;
  far_t far *pfVar16;
  undefined4 in_stack_0000fffa;
  byte bVar17;
  
  bVar17 = *(byte *)((int)*(undefined4 *)((uint)classStr << 2) + 0x3e);
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
                        *(uint8_t *)((int)*(undefined4 *)((uint)classStr << 2) + 0xa4),classStr);
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
        while (uVar9 = (undefined2)((ulong)((long)(int)pfVar8 * 0x1e) >> 0x10),
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
          filename = (char *)CONCAT22(*(undefined2 *)(y + (int)pfVar8 * 0x1e + 1),pcVar15);
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
        *(undefined2 *)((int)&pfVar5[1].seg + 1) = *(undefined2 *)(y + (int)pfVar8 * 0x1e + 0xb);
        *(undefined2 *)((int)&pfVar5[2].ofs + 1) = *(undefined2 *)(y + (int)pfVar8 * 0x1e + 0xd);
        *(undefined2 *)((uint8_t *)uStackY_24 + 2) = uVar9;
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
        *(undefined2 *)((int)&pfVar5->seg + 1) = 0;
        *(undefined2 *)((int)&pfVar5->ofs + 1) = 0;
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
        callResultTemp = func_0x0004f501();
        if (callResultTemp < (char *)filename) {
          filename = (char *)CONCAT22((int)((ulong)filename >> 0x10),callResultTemp);
          *(char *)&in_stack_00000004[-0x1be0].seg = (char)callResultTemp;
        }
        puVar4 = (undefined4 *)((uint)(byte)((ulong)filename >> 0x10) << 2);
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
      *(undefined2 *)((int)(long *)StshPtrs + (int)in_stack_00000004 * 4 + 2) = 0;
      *(undefined2 *)((long *)StshPtrs + (int)in_stack_00000004) = 0;
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
                            *(uint8_t *)((int)*(undefined4 *)((uint)classStr << 2) + 0xa4),classStr)
        ;
      }
    }
  }
  return (uint8_t *)peVar7;
}
