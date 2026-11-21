/*
 * ovc33_stats.c - recovered from STRONG.EXE
 * memory block: OVC33_stats.c
 * range: 6386:0000 - 6386:28ff
 * functions: 25
 */
#include "recovered.h"


/* 6386:0000 */

/* [R7] body shape: compute */

char __cdecl16far stats_compute1(agnt_t *agnt)

{
  char cVar1;
  agnt_t *paVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)agnt >> 0x10);
  paVar2 = (agnt_t *)agnt;
  if ((((agntG_t *)paVar2->gdata)->shortName[3] == '\x04') &&
     (0xb < (((entity_t *)paVar2->entity)->base).level)) {
    cVar1 = (((entity_t *)paVar2->entity)->base).level + 0x37;
  }
  else if ((((agntG_t *)paVar2->gdata)->shortName[3] == '\x05') &&
          (9 < (((entity_t *)paVar2->entity)->base).level)) {
    cVar1 = (((entity_t *)paVar2->entity)->base).level + 0x39;
  }
  else if ((((agntG_t *)paVar2->gdata)->shortName[3] == '\x06') &&
          (7 < (((entity_t *)paVar2->entity)->base).level)) {
    cVar1 = (((entity_t *)paVar2->entity)->base).level + 0x39;
  }
  else {
    cVar1 = '0';
  }
  return cVar1;
}



/* 6386:0088 */

/* [R7] body shape: compute */

uint8_t __cdecl16far stats_compute2(agnt_t *agnt)

{
  uint8_t uVar1;
  agnt_t *paVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)agnt >> 0x10);
  paVar2 = (agnt_t *)agnt;
  if ((((agntG_t *)paVar2->gdata)->shortName[3] == '\x04') &&
     (0xc < (((entity_t *)paVar2->entity)->base).level)) {
    uVar1 = 0xc;
  }
  else if ((((agntG_t *)paVar2->gdata)->shortName[3] == '\x05') &&
          (10 < (((entity_t *)paVar2->entity)->base).level)) {
    uVar1 = 0xa;
  }
  else if ((((agntG_t *)paVar2->gdata)->shortName[3] == '\x06') &&
          (8 < (((entity_t *)paVar2->entity)->base).level)) {
    uVar1 = 0x8;
  }
  else {
    uVar1 = (((entity_t *)paVar2->entity)->base).level;
  }
  return uVar1;
}



/* 6386:00f8 */

/* Blits the full-screen stats background and the nwpanel1Cut3 panel. */

void __cdecl16far stats_drawStatsPanel(void)

{
  far_t gfx;
  far_t dst;
  undefined2 unaff_BP;
  far_t gfx_00;
  undefined1 type;
  undefined1 uVar1;
  
  type = (undefined1)unaff_BP;
  uVar1 = (undefined1)((uint)unaff_BP >> 8);
  gfx_00.seg = 0;
  gfx_00.ofs = fullScreenGfxSeg;
  ovr_blitGfx10(gfx_00,0,0x5ce5,(brect_t *)0x2410,(bool)type,fullScreenGfxOfs);
  gfx.seg = 0xadf;
  gfx.ofs = nwpanel1Cut3Seg;
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = type;
  dst.ofs = 0xa000;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = uVar1;
  ovr_blitLoadRleGfx(gfx,dst,nwpanel1Cut3Ofs);
  return;
}



/* 6386:013d */

/* [R7] body shape: compute */

undefined1 __cdecl16far stats_compute3(agnt_t *agnt)

{
  undefined1 uVar1;
  agnt_t *paVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)agnt >> 0x10);
  paVar2 = (agnt_t *)agnt;
  if ((((agntG_t *)paVar2->gdata)->shortName[3] == '\x04') &&
     (0xb < (((entity_t *)paVar2->entity)->base).level)) {
    uVar1 = 1;
  }
  else if ((((agntG_t *)paVar2->gdata)->shortName[3] == '\x05') &&
          (9 < (((entity_t *)paVar2->entity)->base).level)) {
    uVar1 = 1;
  }
  else if ((((agntG_t *)paVar2->gdata)->shortName[3] == '\x06') &&
          (7 < (((entity_t *)paVar2->entity)->base).level)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 6386:01a4 */

/* Draws the portrait of an agent type with the season palette. */

void __cdecl16far stats_drawPortrait(agntG_t *gdata,byte portraitIndex,int palette)

{
  stg_tmp_t *psVar1;
  undefined2 in_DX;
  agntG_t *paVar2;
  undefined2 uVar3;
  undefined2 in_stack_0000000c;
  far_t gfx;
  undefined1 mirror;
  undefined2 uVar4;
  
  psVar1 = ovr_stshLoadGfx();
  mirror = SUB21(psVar1,0);
  uVar4 = in_DX;
  ovr_calcSeasonPalette();
  uVar3 = (undefined2)((ulong)gdata >> 0x10);
  paVar2 = (agntG_t *)gdata;
  if (((paVar2->prts + portraitIndex)->ofs != 0 || paVar2->prts[portraitIndex].seg != 0) &&
     ((paVar2->prtpals + portraitIndex)->ofs != 0 || paVar2->prtpals[portraitIndex].seg != 0)) {
    psVar1 = ovr_stshLoadGfx();
    memcpy((char *)CONCAT22(in_stack_0000000c,(char *)(palette + 3)),
           (char *)CONCAT22(in_DX,psVar1->cmap + 3),0xed);
    memcpy((char *)CONCAT22(in_stack_0000000c,(char *)(palette + 0x1e0)),
           (char *)CONCAT22(in_DX,psVar1->cmap + 0x1e0),0x90);
    mirror = SUB21(psVar1,0);
    uVar4 = in_DX;
  }
  if (GameRunning == false) {
    ovr_vgaSetPalette8bit();
  }
  if ((paVar2->prts + portraitIndex)->ofs != 0 || paVar2->prts[portraitIndex].seg != 0) {
    ovr_driver_fillRect();
    gfx.seg = 0x10;
    gfx.ofs = paVar2->prts[portraitIndex].seg;
    ovr_blitGfxRect(gfx,10,1098,(brect_t *)0x102410,0x0,(bool)mirror,
                    (paVar2->prts + portraitIndex)->ofs,uVar4);
  }
  return;
}



/* 6386:02db */

char * __cdecl16far agntCopyNthField(uint8_t filed_index,char *dst,char *src)

{
  int iVar1;
  char *pcVar2;
  bool bVar3;
  uint16_t len;
  uint16_t i;
  uint8_t in_stack_00000004;
  undefined1 in_stack_00000007;
  uint8_t j;
  uint8_t found;
  
  iVar1 = CONCAT11(in_stack_00000007,filed_index);
  j = 0x0;
  bVar3 = false;
  i = 0;
  while( true ) {
    in_stack_00000007 = (undefined1)((uint)iVar1 >> 8);
    filed_index = (uint8_t)iVar1;
    pcVar2 = (char *)src;
    len = strlen((char *)CONCAT22(pcVar2,(*(uint16_t *)((uint8_t *)&(dst) + 2))));
    iVar1 = CONCAT11(in_stack_00000007,filed_index);
    if (len <= i) break;
    if ((*(uint16_t *)((uint8_t *)&(dst) + 2))[i] == ',') {
      j = j + 0x1;
      iVar1 = CONCAT11(in_stack_00000007,filed_index);
      if (bVar3) break;
    }
    else if (j == in_stack_00000004) {
      *(char *)CONCAT22((char *)dst,(char *)CONCAT11(in_stack_00000007,filed_index)) = (*(uint16_t *)((uint8_t *)&(dst) + 2))[i];
      iVar1 = CONCAT11(in_stack_00000007,filed_index) + 1;
      bVar3 = true;
    }
    i = i + 1;
  }
  if (bVar3) {
    *(undefined1 *)CONCAT22((char *)dst,(undefined1 *)CONCAT11(in_stack_00000007,filed_index)) = 0;
  }
  else {
    strcpy((char *)CONCAT22((char *)dst,(char *)CONCAT11(in_stack_00000007,filed_index)),
           (char *)CONCAT22(pcVar2,(*(uint16_t *)((uint8_t *)&(dst) + 2))));
  }
  return (char *)CONCAT11(in_stack_00000007,filed_index);
}



/* 6386:0367 */

char * __cdecl16far
agntGetWeaponName(char *dst,uint8_t atype,bool magical,uint8_t field_index,int32_t agent)

{
  undefined4 uVar1;
  uint16_t tofs;
  undefined2 unaff_BP;
  char *in_stack_00000004;
  undefined1 in_stack_0000000f;
  
  if (*(int *)((int)&AgntGs[0].wpn_name + (uint)(*(uint8_t *)((uint8_t *)&(dst) + 2)) * 0x95) == 0 &&
      *(int *)((int)&AgntGs[0].wpn_name + 2 + (uint)(*(uint8_t *)((uint8_t *)&(dst) + 2)) * 0x95) == 0) {
    if (atype == 0x0) {
      strcpy((char *)CONCAT22((char *)dst,in_stack_00000004),"normal weaponry");
    }
    else {
      strcpy((char *)CONCAT22((char *)dst,in_stack_00000004),"weaponry");
    }
  }
  else {
    uVar1 = *(undefined4 *)(CONCAT11(in_stack_0000000f,field_index) + 0x1d);
    if ((*(uint *)((int)uVar1 + 0x40) & 0x4000) == 0) {
      tofs = (uint)(*(uint8_t *)((uint8_t *)&(dst) + 2)) * 0x95;
      agntCopyNthField((uint8_t)in_stack_00000004,
                       (char *)CONCAT22(*(undefined2 *)((int)&AgntGs[0].wpn_name + tofs),(char *)dst
                                       ),
                       (char *)CONCAT22(unaff_BP,(char *)*(undefined2 *)
                                                          ((int)&AgntGs[0].wpn_name + 2 + tofs)));
    }
    else {
      strcpy((char *)CONCAT22((char *)dst,in_stack_00000004),"short sword");
    }
  }
  return in_stack_00000004;
}



/* 6386:0411 */

/* WARNING: Instruction at (ram,0x0006014c) overlaps instruction at (ram,0x0006014b)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unable to track spacebase fully for stack */
/* [R2] string "+%d ring of prot." */

far_t * __cdecl16far stats_textRingProt(char *dst,uint16_t src,uint16_t term,far_t ringValue)

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
  far_t entries;
  byte bVar10;
  undefined1 uVar11;
  bool bVar12;
  char cVar21;
  uint uVar13;
  byte *pbVar14;
  byte bVar22;
  uint uVar16;
  far_t *pfVar17;
  uint16_t uVar18;
  uint uVar19;
  byte *pbVar20;
  byte bVar24;
  far_t *in_CX;
  far_t *pfVar23;
  byte bVar25;
  byte bVar26;
  byte bVar27;
  int iVar28;
  undefined2 uVar29;
  undefined2 in_DX;
  byte *pbVar30;
  undefined2 *puVar31;
  int *piVar32;
  short (*pasVar33) [148];
  uint *puVar34;
  uint *puVar35;
  undefined1 *puVar37;
  uint *puVar38;
  int iVar39;
  far_t *unaff_SI;
  byte *pbVar40;
  byte *unaff_DI;
  undefined2 uVar41;
  undefined2 unaff_ES;
  undefined2 uVar42;
  undefined2 unaff_SS;
  undefined2 uVar43;
  bool bVar44;
  byte in_AF;
  longdouble in_ST0;
  undefined4 uVar45;
  undefined4 in_stack_00000000;
  byte in_stack_00000004;
  undefined1 uVar46;
  undefined1 in_stack_00000005;
  undefined1 auStack_2cc [698];
  undefined2 uStack_12;
  undefined2 uStack_10;
  undefined2 uStack_e;
  byte in_stack_0000fff4;
  short in_stack_0000fff6;
  char sfx;
  undefined1 in_stack_0000fff8;
  undefined1 in_stack_0000fff9;
  undefined1 uVar47;
  undefined1 in_stack_0000fffa;
  char in_stack_0000fffb;
  undefined1 uVar48;
  undefined1 in_stack_0000fffc;
  undefined1 uVar49;
  char in_stack_0000fffd;
  uint uVar15;
  uint *puVar36;
  
  if ((*(uint8_t *)((uint8_t *)&(dst) + 2)) == '\x01') {
    if ((char)term == '\0') {
      uStack_e = (undefined1 *)0x3c91;
      strcpy((char *)CONCAT13((*(uint8_t *)((uint8_t *)&(dst) + 1)),
                              CONCAT12((*(uint8_t *)((uint8_t *)&(dst))),CONCAT11(in_stack_00000005,in_stack_00000004))),"")
      ;
    }
    else if ('\0' < (char)term) {
      uStack_e = (undefined1 *)0x6386;
      uStack_10 = 0x3cb0;
      ovr_stsprintf();
    }
                    /* WARNING: Read-only address (ram,0x0002c58a) is written */
    return (far_t *)CONCAT11(in_stack_00000005,in_stack_00000004);
  }
  bVar27 = (char)src - (char)term;
  if ((*(uint8_t *)((uint8_t *)&(dst) + 2)) == '\x03') {
    uVar19 = (int)(char)bVar27 - 6;
    if (4 < uVar19) {
      uStack_e = (undefined1 *)0x3d28;
      strcpy((char *)CONCAT13((*(uint8_t *)((uint8_t *)&(dst) + 1)),
                              CONCAT12((*(uint8_t *)((uint8_t *)&(dst))),CONCAT11(in_stack_00000005,in_stack_00000004))),
             "+2 leather armor");
      return (far_t *)CONCAT11(in_stack_00000005,in_stack_00000004);
    }
    cVar21 = '`';
    pfVar17 = (far_t *)(uVar19 * 2);
    switch(uVar19) {
    case 0:
      (&stack0xfffe)[(int)unaff_SI] = (&stack0xfffe)[(int)unaff_SI] + '\x01';
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    case 1:
      pcVar7 = (code *)swi(1);
      pfVar17 = (far_t *)(*pcVar7)();
      return pfVar17;
    case 2:
      do {
        pfVar17 = (far_t *)(uint)(byte)(pfVar17 + -0x1db1)->ofs;
        if (pfVar17 == unaff_SI) {
          if ((far_t *)(uint)(byte)(unaff_SI + -0x1db1)->ofs == unaff_SI) {
            pfVar17 = (far_t *)((char *)"puppetmaker" + 3);
            *(char *)&(in_CX + -0x1db1)->ofs = (char)in_CX;
          }
          else {
            uVar11 = (undefined1)(unaff_SI + -0x1db1)->ofs;
            pfVar17 = (far_t *)CONCAT11(0x24,uVar11);
            *(undefined1 *)&(in_CX + -0x1db1)->ofs = uVar11;
          }
        }
        do {
          pfVar23 = in_CX;
          in_CX = (far_t *)((int)&pfVar23->ofs + 1);
          if (0xb < (int)in_CX) {
            return pfVar17;
          }
        } while (in_CX == unaff_SI);
        uVar11 = SUB21(in_CX,0);
        if ((far_t *)(uint)*(byte *)((int)&pfVar23[-0x1da8].ofs + 1) == unaff_SI) {
          if ((far_t *)(uint)(byte)(unaff_SI + -0x1da8)->ofs == unaff_SI) {
            *(undefined1 *)((int)&pfVar23[-0x1da8].ofs + 1) = uVar11;
          }
          else {
            *(undefined1 *)((int)&pfVar23[-0x1da8].ofs + 1) = (char)(unaff_SI + -0x1da8)->ofs;
          }
        }
        if ((far_t *)(uint)*(byte *)((int)&pfVar23[-0x1dab].ofs + 1) == unaff_SI) {
          if ((far_t *)(uint)(byte)(unaff_SI + -0x1dab)->ofs == unaff_SI) {
            *(undefined1 *)((int)&pfVar23[-0x1dab].ofs + 1) = uVar11;
          }
          else {
            *(undefined1 *)((int)&pfVar23[-0x1dab].ofs + 1) = (char)(unaff_SI + -0x1dab)->ofs;
          }
        }
        if ((far_t *)(uint)*(byte *)((int)&pfVar23[-0x1dae].ofs + 1) == unaff_SI) {
          if ((far_t *)(uint)(byte)(unaff_SI + -0x1dae)->ofs == unaff_SI) {
            *(undefined1 *)((int)&pfVar23[-0x1dae].ofs + 1) = uVar11;
          }
          else {
            *(undefined1 *)((int)&pfVar23[-0x1dae].ofs + 1) = (char)(unaff_SI + -0x1dae)->ofs;
          }
        }
        unaff_ES = 0x2410;
        pfVar17 = in_CX;
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
          while (uVar18 = ovr_biosKeyAvail(), (char)uVar18 != '\0') {
            ovr_biosReadKey();
          }
          cVar21 = '\"';
          uVar18 = ovr_biosReadKey();
          if ((uVar18 & 0xff) == 0x1b) {
            printf("\n");
                    /* WARNING: Subroutine does not return */
            exit(0);
          }
        } while (((((uVar18 & 0xff) != 0x31) && ((uVar18 & 0xff) != 0x32)) &&
                 ((uVar18 & 0xff) != 0x33)) &&
                (((uVar18 & 0xff) != 0x34 && ((uVar18 & 0xff) != 0x35))));
      }
      clrscr();
      bVar12 = write_game_cfg(sfx,cVar21,cVar21);
      if ((far_t *)(uint)bVar12 != (far_t *)0x0) {
        return (far_t *)(uint)bVar12;
      }
                    /* WARNING: Subroutine does not return */
      exit(0x83);
    }
    (&stack0xfffe)[(int)unaff_DI] = (&stack0xfffe)[(int)unaff_DI] + (byte)in_CX;
    unaff_DI[0x54] = 0;
    *(char *)&unaff_SI->ofs = (char)unaff_SI->ofs + (char)(uVar19 >> 8);
    if (((*(int *)&MouseMoved == 0) && (8 < MouseX)) &&
       ((MouseX < 0x19 && ((0xb4 < MouseY && ((MouseY < 0xb6 | 0xeU) != 0)))))) {
      return (far_t *)0x0;
    }
    if ((((MouseMoved == 0) && (0xea < MouseX)) && (0x3b < MouseY)) && (MouseX < 0x139)) {
      uVar19 = (MouseY - 0x3c) / 0xe;
      if (((uVar19 < (uint)((ulong)dst >> 0x10)) && ((MouseY - 0x3c) % 0xe < 0xc)) &&
         (uVar41 = (undefined2)
                   (CONCAT13((*(uint8_t *)((uint8_t *)&(dst) + 1)),
                             CONCAT12((*(uint8_t *)((uint8_t *)&(dst))),CONCAT11(in_stack_00000005,in_stack_00000004))) >>
                   0x10),
         piVar32 = (int *)(CONCAT11(in_stack_00000005,in_stack_00000004) + uVar19 * 4),
         *piVar32 != 0 || piVar32[1] != 0)) {
        cVar21 = (char)uVar19;
        (*(uint8_t *)((uint8_t *)&(entries.ofs) + 1)) = in_stack_00000005;
        (*(uint8_t *)((uint8_t *)&(entries.ofs))) = in_stack_00000004;
        (*(uint8_t *)((uint8_t *)&(entries.seg))) = (*(uint8_t *)((uint8_t *)&(dst)));
        (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = (*(uint8_t *)((uint8_t *)&(dst) + 1));
        ovc28_blitMenuEntry(entries,uVar19);
        GMenuItem = cVar21 + '\x01';
        return (far_t *)CONCAT11(0x24,cVar21 + '\x01');
      }
    }
    uVar11 = 0x24;
    if (((MouseMoved == 0) && (menuBarShown != '\0')) &&
       ((uVar11 = 0x24, 0xf < MouseX &&
        ((uVar11 = 0x24, 0xb2 < MouseY && (uVar11 = 0x24, MouseY < 0xbf)))))) {
      uVar19 = (MouseX - 0x10) / 0x44;
      uVar11 = (undefined1)((MouseX - 0x10) / 0x44 >> 8);
      if ((uVar19 < 3) && ((MouseX - 0x10) % 0x44 < 0x43)) {
        GMenuItem = (char)uVar19 + -4;
        return (far_t *)CONCAT11(0x24,GMenuItem);
      }
    }
    if ((((keyboardInputMode == '\0') || (uVar11 = 0x24, MouseMoved != 0)) ||
        (uVar11 = 0x24, MouseX < 0xc)) ||
       (((uVar11 = 0x24, 0xde < MouseX || (uVar11 = 0x24, MouseY < 7)) ||
        (uVar11 = 0x24, 0x96 < MouseY)))) goto L_OVC28_6018_0c76_0EAD;
  }
  else {
    pbVar20 = (byte *)(int)(char)bVar27;
    if ((byte *)__C0_ASM_CopyRight + 4 < pbVar20) {
      uStack_e = (undefined1 *)0x3d55;
      strcpy((char *)CONCAT13((*(uint8_t *)((uint8_t *)&(dst) + 1)),
                              CONCAT12((*(uint8_t *)((uint8_t *)&(dst))),CONCAT11(in_stack_00000005,in_stack_00000004))),
             "no armor");
      return (far_t *)CONCAT11(in_stack_00000005,in_stack_00000004);
    }
    pasVar33 = (short (*) [148])((int)pbVar20 * 2);
    uVar41 = 0x6000;
    bVar10 = (byte)((uint)in_DX >> 8);
    uVar11 = (undefined1)unaff_SS;
    uVar47 = (undefined1)((uint)unaff_SS >> 8);
    switch(pbVar20) {
    case (byte *)0x0:
      ovr_vgaSetPalette8bit();
      ovr_blitRect();
      TextBlitDstSeg = 0xa000;
      ovr_ovc28_textHalflingCastle();
      for (iVar28 = 0; iVar28 < 5; iVar28 = iVar28 + 1) {
        ovr_draw_usesBlitLoadRleGfx3();
        ovr_draw_menuRowBar();
      }
      mapViewActive = 0xff;
      ovr_attact_usesLDIV_at_2();
      ovr_stshFree();
      ovr_stop_audio();
      CurMusicType = 0xff;
      ScreenMode = 0;
      return (far_t *)((char *)"puppetmaker" + 3);
    case (byte *)0x1:
                    /* WARNING: Read-only address (ram,0x0002c58a) is written */
      s_s_regenerates_3_hitpoints_to_a_total_of_d_hi[0x1e] = '\0';
      (unaff_SI + 0xec0)->ofs = (uint16_t)unaff_SI;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case (byte *)0x2:
      pfVar17 = GPromotableCount;
      if (*(byte *)(*(int *)pbVar20 + 0x86) < 9) {
        pfVar17 = (far_t *)((uint)promotionCount * 0x32 + 0x32);
      }
      s_s_regenerates_3_hitpoints_to_a_total_of_d_hi[0x1e] = 'a';
      return pfVar17;
    case (byte *)0x3:
      do {
        uStack_e = (undefined1 *)0x6d6;
        uVar48 = uVar11;
        uVar49 = uVar47;
        ovr_ovc45_compute9();
        in_stack_00000004 = (byte)in_DX;
        uVar46 = (undefined1)((uint)in_DX >> 8);
        ovr_blitLabel();
        pfVar17 = (far_t *)((char *)"puppetmaker" + 3);
        BlitLetterType = 0;
        pbVar20 = unaff_DI;
        while( true ) {
          while( true ) {
            unaff_DI = pbVar20 + 0xe;
            unaff_SI = (far_t *)((int)&unaff_SI->ofs + 1);
            if (CONCAT11((*(uint8_t *)((uint8_t *)&(dst) + 3)),(*(uint8_t *)((uint8_t *)&(dst) + 2))) <= (int)unaff_SI) {
              if (goldPartyIndex != 0xff) {
                pfVar17 = (far_t *)CONCAT11((char)((uint)pfVar17 >> 8),goldPartyIndex);
                ovc28_drawGold(goldPartyIndex);
              }
              return pfVar17;
            }
            uVar41 = (undefined2)
                     (CONCAT13((*(uint8_t *)((uint8_t *)&(dst) + 1)),CONCAT12((*(uint8_t *)((uint8_t *)&(dst))),CONCAT11(uVar46,in_stack_00000004))) >>
                     0x10);
            piVar32 = (int *)(CONCAT11(uVar46,in_stack_00000004) + (int)unaff_SI * 4);
            if (*piVar32 != 0 || piVar32[1] != 0) break;
            pfVar17 = (far_t *)0x0;
            pbVar20 = unaff_DI;
          }
          (*(uint8_t *)((uint8_t *)&(dst))) = (undefined1)butt01Cut5Ofs;
          (*(uint8_t *)((uint8_t *)&(dst) + 1)) = (undefined1)((uint)butt01Cut5Ofs >> 8);
          in_stack_00000004 = 0xc4;
          uVar46 = 0x22;
          ovr_blitLoadRleGfx();
          TextBlitDstSeg = 0xa000;
          TextBlitX = CONCAT11(uVar49,uVar48) + 6;
          TextBlitY = (uint16_t)(pbVar20 + 0x10);
          uVar42 = (undefined2)
                   (CONCAT13((*(uint8_t *)((uint8_t *)&(dst) + 1)),CONCAT12((*(uint8_t *)((uint8_t *)&(dst))),CONCAT11(uVar46,in_stack_00000004))) >>
                   0x10);
          puVar31 = (undefined2 *)(CONCAT11(uVar46,in_stack_00000004) + (int)unaff_SI * 4);
          uVar41 = puVar31[1];
          in_DX = *puVar31;
          uVar48 = (undefined1)uVar41;
          uVar49 = (undefined1)((uint)uVar41 >> 8);
          (*(uint8_t *)((uint8_t *)&(dst) + 2)) = (char)FontMain.seg;
          (*(uint8_t *)((uint8_t *)&(dst) + 3)) = (undefined1)(FontMain.seg >> 8);
          (*(uint8_t *)((uint8_t *)&(dst))) = (undefined1)FontMain.ofs;
          (*(uint8_t *)((uint8_t *)&(dst) + 1)) = (undefined1)(FontMain.ofs >> 8);
          if (*(char *)CONCAT13(uVar49,CONCAT12(uVar48,in_DX)) == '%') break;
          if (*(char *)CONCAT13(uVar49,CONCAT12(uVar48,in_DX)) == '@') {
            in_stack_00000004 = 3;
            uStack_e = (undefined1 *)0x733;
            uVar48 = uVar11;
            uVar49 = uVar47;
            ovr_ovc45_compute9();
            in_stack_00000004 = (byte)in_DX;
            uVar46 = (undefined1)((uint)in_DX >> 8);
            pfVar17 = (far_t *)ovr_blitLabel();
            pbVar20 = unaff_DI;
          }
          else {
            in_stack_00000004 = 3;
            uStack_e = (undefined1 *)0x784;
            uVar48 = uVar11;
            uVar49 = uVar47;
            ovr_ovc45_compute9();
            in_stack_00000004 = (byte)in_DX;
            uVar46 = (undefined1)((uint)in_DX >> 8);
            pfVar17 = (far_t *)ovr_blitLabel();
            pbVar20 = unaff_DI;
          }
        }
        BlitLetterType = 2;
        in_stack_00000004 = 3;
      } while( true );
    case (byte *)0x4:
      out(0,bVar27);
      pcVar1 = (char *)((int)*pasVar33 + 0x3b);
      *pcVar1 = *pcVar1 + bVar10;
      break;
    case (byte *)0x5:
      bVar25 = 9 < (bVar27 & 0xf) | in_AF;
      bVar26 = bVar27 + bVar25 * '\x06';
      cVar21 = ((char)bVar27 >> 7) + bVar25;
      uVar13 = CONCAT11(cVar21,bVar26) & 0xff0f;
      bVar22 = (byte)pasVar33;
      uVar16 = CONCAT11(bVar10 + bVar22 + bVar25,(char)in_DX);
      uVar19 = (uint)(CARRY1(bVar10,bVar22) || CARRY1(bVar10 + bVar22,bVar25));
      puVar37 = &stack0xfffe + uVar13 + uVar19;
      puVar2 = (uint *)(puVar37 + (int)unaff_DI + -0x58ef);
      uVar15 = (uint)(CARRY2((uint)&stack0xfffe,uVar13) ||
                     CARRY2((uint)(&stack0xfffe + uVar13),uVar19));
      uVar19 = *puVar2;
      uVar13 = *puVar2;
      *puVar2 = (uint)(unaff_DI + uVar13 + uVar15);
      puVar2 = (uint *)(unaff_DI + -0x7aef);
      uVar13 = (uint)(CARRY2(uVar19,(uint)unaff_DI) || CARRY2((uint)(unaff_DI + uVar13),uVar15));
      uVar19 = *puVar2;
      uVar15 = (int)*pasVar33 + *puVar2;
      *puVar2 = uVar15 + uVar13;
      piVar3 = (int *)((int)*pasVar33 + 0x11);
      *piVar3 = *piVar3 + uVar16 + (uint)(CARRY2(uVar19,(uint)pasVar33) || CARRY2(uVar15,uVar13));
      bVar12 = CARRY2(uVar16,*(uint *)(unaff_DI + (int)*pasVar33));
      iVar28 = uVar16 + *(uint *)(unaff_DI + (int)*pasVar33);
      *(double *)((int)&unaff_SI->ofs + (int)*pasVar33) = (double)in_ST0;
      puVar4 = (undefined2 *)((int)&unaff_SI->ofs + (int)*pasVar33);
      bVar10 = ((byte)in_CX & 0x1f) % 0x11;
      uVar9 = CONCAT12(bVar12,*puVar4);
      uVar8 = (ulong)uVar9 << bVar10 | (ulong)(uVar9 >> 0x11 - bVar10);
      *puVar4 = (int)uVar8;
      pbVar5 = (byte *)((int)&unaff_SI->ofs + (int)*pasVar33);
      bVar27 = *pbVar5;
      *pbVar5 = bVar27 << 4 |
                (byte)(CONCAT11((bVar10 == 0) * bVar12 | (bVar10 != 0) * ((uVar8 & 0x10000) != 0),
                                bVar27) >> 5);
      bVar12 = (bVar27 & 0x10) != 0;
      pbVar5 = puVar37 + 0x5110;
      bVar27 = *pbVar5;
      bVar10 = *pbVar5;
      *pbVar5 = bVar10 + bVar22 + bVar12;
      *(byte *)(*pasVar33 + 8) =
           (char)(*pasVar33)[8] + (bVar26 & 0xf) +
           (CARRY1(bVar27,bVar22) || CARRY1(bVar10 + bVar22,bVar12));
      uVar19 = CONCAT11(cVar21,bVar26) & 0xff0f ^ 0x10;
      pbVar5 = (byte *)((int)&unaff_SI->ofs + (int)*pasVar33);
      bVar25 = (byte)iVar28;
      bVar12 = bVar25 < *pbVar5;
      bVar22 = (byte)((uint)iVar28 >> 8);
      bVar25 = bVar25 - *pbVar5;
      pbVar5 = (byte *)((int)&unaff_SI->ofs + (int)*pasVar33);
      bVar27 = *pbVar5;
      bVar10 = bVar25 + *pbVar5;
      bVar26 = bVar10 + bVar12;
      out(CONCAT11(bVar22,bVar26),uVar19);
      uVar19 = CONCAT11(cVar21,*(undefined1 *)(ulong)((int)*pasVar33 + (uVar19 & 0xff)));
      uVar41 = (undefined2)((ulong)in_stack_00000000 >> 0x10);
      (*pasVar33)[0] = CONCAT11(bVar22,bVar26);
      if (!CARRY1(bVar25,bVar27) && !CARRY1(bVar10,bVar12)) {
        pcVar7 = (code *)swi(3);
        pfVar17 = (far_t *)(*pcVar7)();
        return pfVar17;
      }
      iVar28 = (bVar26 & 3) - (AgntAnms[0x6e].maxDy & 3U);
      AgntAnms[0x6e].maxDy = AgntAnms[0x6e].maxDy + (uint)(0 < iVar28) * iVar28;
      uVar13 = (uint)unaff_SI ^ 0xdd16;
      LOCK();
      bVar27 = *unaff_DI;
      *unaff_DI = bVar26;
      UNLOCK();
      pbVar30 = (byte *)((int)*pasVar33 + 1);
      *unaff_DI = *unaff_DI & bVar27;
      *(undefined2 *)0xa813 = uVar41;
      iVar28 = uVar13 + 0x2b64 + (uint)(0xea39 < uVar13) +
               (uint)(0xea61 < uVar13 + 0x15c6 || CARRY2(uVar13 + 0x2b64,(uint)(0xea39 < uVar13))) +
               0x2a2f;
      bVar10 = (byte)iVar28;
      bVar12 = 0x34 < (byte)(bVar10 - 0x20) || CARRY1(bVar10 + 0xab,0x1f < bVar10);
      bVar25 = bVar10 + 0xab + (0x1f < bVar10);
      bVar10 = bVar25 + 0xbe;
      bVar44 = 0x41 < bVar25 || CARRY1(bVar10,bVar12);
      bVar10 = bVar10 + bVar12;
      bVar25 = bVar10 + 0xa0;
      bVar12 = 0x5f < bVar10 || CARRY1(bVar25,bVar44);
      bVar25 = bVar25 + bVar44;
      bVar10 = bVar25 + 0x93;
      bVar44 = 0x6c < bVar25 || CARRY1(bVar10,bVar12);
      bVar10 = bVar10 + bVar12;
      bVar25 = bVar10 + 0x7d;
      bVar12 = 0x82 < bVar10 || CARRY1(bVar25,bVar44);
      bVar25 = bVar25 + bVar44;
      bVar10 = bVar25 + 0x61;
      bVar44 = 0x9e < bVar25 || CARRY1(bVar10,bVar12);
      bVar10 = bVar10 + bVar12;
      bVar25 = bVar10 + 0x57;
      bVar12 = 0xa8 < bVar10 || CARRY1(bVar25,bVar44);
      bVar25 = bVar25 + bVar44;
      bVar10 = bVar25 + 0x43;
      bVar44 = 0xbc < bVar25 || CARRY1(bVar10,bVar12);
      bVar10 = bVar10 + bVar12;
      bVar25 = bVar10 + 0x39;
      bVar12 = 0xc6 < bVar10 || CARRY1(bVar25,bVar44);
      bVar25 = bVar25 + bVar44;
      bVar10 = bVar25 + 0x23;
      bVar44 = 0xdc < bVar25 || CARRY1(bVar10,bVar12);
      bVar10 = bVar10 + bVar12;
      bVar25 = bVar10 + 0xb;
      bVar12 = 0xf4 < bVar10 || CARRY1(bVar25,bVar44);
      bVar25 = bVar25 + bVar44;
      bVar10 = bVar25 + 0x8d;
      uVar16 = CONCAT11((char)((uint)iVar28 >> 8),bVar10 + bVar12);
      uVar13 = (uint)(0x72 < bVar25 || CARRY1(bVar10,bVar12));
      uVar15 = uVar16 - *(uint *)(pbVar30 + uVar19 + 0x5c1b);
      pbVar14 = (byte *)(uVar15 - uVar13);
      uVar13 = (uint)(uVar16 < *(uint *)(pbVar30 + uVar19 + 0x5c1b) || uVar15 < uVar13);
      uVar15 = (int)in_CX - *(uint *)(puVar37 + 0x1b);
      iVar28 = uVar15 - uVar13;
      uVar13 = (uint)(in_CX < *(far_t **)(puVar37 + 0x1b) || uVar15 < uVar13);
      uVar15 = uVar19 - *(uint *)(pbVar30 + uVar19);
      puVar38 = (uint *)(uVar15 - uVar13);
      uVar19 = (uint)(uVar19 < *(uint *)(pbVar30 + uVar19) || uVar15 < uVar13);
      uVar15 = 0xa814 - AgntAnms[0x39].missileDy;
      iVar39 = -uVar19;
      uVar19 = (uint)(0xa814 < (uint)AgntAnms[0x39].missileDy || uVar15 < uVar19);
      pbVar40 = (byte *)(((int)unaff_DI - (int)pbVar14) - uVar19);
      bVar12 = bVar22 < (pbVar30 + (int)pbVar40)[-0x5be6] ||
               (byte)(bVar22 - (pbVar30 + (int)pbVar40)[-0x5be6]) <
               (unaff_DI < pbVar14 || (uint)((int)unaff_DI - (int)pbVar14) < uVar19);
      bVar10 = (byte)iVar28;
      bVar25 = bVar10 - pbVar40[0x3e1a];
      bVar44 = bVar10 < pbVar40[0x3e1a] || bVar25 < bVar12;
      bVar26 = (byte)((uint)iVar28 >> 8);
      bVar25 = bVar25 - bVar12;
      bVar10 = bVar26 - bVar27;
      bVar24 = bVar10 - bVar44;
      pbVar5 = pbVar40 + 0x4119;
      uVar19 = (uint)(bVar26 < bVar27 || bVar10 < bVar44);
      pbVar20 = *(byte **)pbVar5;
      iVar28 = *(int *)pbVar5;
      *(uint *)pbVar5 = (iVar28 - (int)pbVar14) - uVar19;
      puVar2 = puVar38;
      uVar13 = (uint)(pbVar20 < pbVar14 || (uint)(iVar28 - (int)pbVar14) < uVar19);
      puVar34 = (uint *)*puVar2;
      uVar19 = *puVar2;
      *puVar2 = (uVar19 - (int)puVar38) - uVar13;
      uVar19 = (uint)(puVar34 < puVar38 || uVar19 - (int)puVar38 < uVar13);
      bVar12 = (uint)(*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight) + 21)) < CONCAT11(bVar24,bVar25);
      uVar13 = (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight) + 21)) - CONCAT11(bVar24,bVar25);
      (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight) + 21)) = uVar13 - uVar19;
      uVar19 = (uint)(bVar12 || uVar13 < uVar19);
      piVar32 = (int *)-uVar19;
      bVar22 = (byte)((uint)pbVar14 >> 8);
      bVar12 = bVar27 < bVar22 || (byte)(bVar27 - bVar22) < (uVar19 != 0);
      bVar10 = (bVar27 - bVar22) - (uVar19 != 0);
      bVar27 = (byte)pbVar14 - (byte)pbVar30;
      bVar26 = bVar27 - bVar12;
      bVar12 = bVar10 < bVar26 ||
               (byte)(bVar10 - bVar26) < ((byte)pbVar14 < (byte)pbVar30 || bVar27 < bVar12);
      pbVar5 = (byte *)((char *)"%s turns %d undead." + 9 + (int)puVar37 + (int)piVar32);
      bVar27 = *pbVar5;
      bVar10 = *pbVar5;
      *pbVar5 = (bVar10 - bVar24) - bVar12;
      pcVar1 = (char *)((int)puVar37 + (int)piVar32 + 0x18);
      *pcVar1 = (*pcVar1 - bVar22) - (bVar27 < bVar24 || (byte)(bVar10 - bVar24) < bVar12);
      bVar12 = CONCAT11(bVar22,bVar26) < 0x2318;
      bVar26 = bVar26 - 0x18;
      pbVar5 = pbVar30;
      bVar44 = *pbVar5 < bVar25 || (byte)(*pbVar5 - bVar25) < bVar12;
      *pbVar5 = (*pbVar5 - bVar25) - bVar12;
      pbVar5 = pbVar40;
      bVar27 = *pbVar5;
      bVar10 = *pbVar5;
      *pbVar5 = (bVar10 - bVar26) - bVar44;
      uVar42 = CONCAT11(bVar24,(bVar25 - bVar26) -
                               (bVar27 < bVar26 || (byte)(bVar10 - bVar26) < bVar44));
      uVar43 = *(undefined2 *)(uVar15 + iVar39 + 2);
      puVar34 = (uint *)(uVar15 + iVar39 + 4);
      pcVar7 = (code *)swi(0x1e);
      uVar45 = (*pcVar7)();
      uVar29 = (undefined2)((ulong)uVar45 >> 0x10);
      uVar19 = (uint)uVar45;
      uVar13 = *puVar34;
      *puVar34 = uVar43;
      puVar34[-1] = uVar43;
      bVar27 = (byte)((ulong)uVar45 >> 0x10);
      if (((uVar13 & 0x800) != 0) == ((uVar13 & 0x80) != 0)) {
code_r0x0006013c:
        lVar6 = (long)*piVar32 * 0x48;
        bVar12 = (int)lVar6 != lVar6;
        bVar25 = (byte)uVar19 - 0x1d;
        bVar44 = (byte)uVar19 < 0x1d || bVar25 < bVar12;
        bVar25 = bVar25 - bVar12;
        bVar26 = bVar25 + 3;
        bVar10 = bVar26 - bVar44;
        pbVar40 = pbVar40 + (-(uint)(bVar25 < 0xfd || bVar26 < bVar44) - (int)puVar34);
        pbVar30 = (byte *)CONCAT11((byte)((ulong)lVar6 >> 8) & (byte)((uint)uVar42 >> 8) & bVar10,
                                   (char)lVar6);
        (puVar37 + (int)pbVar40)[-0x62e0] =
             (puVar37 + (int)pbVar40)[-0x62e0] & (byte)((ulong)uVar45 >> 0x18);
        (pbVar30 + (int)pbVar40)[0x6f20] = (pbVar30 + (int)pbVar40)[0x6f20] & (byte)uVar42;
      }
      else {
        puVar34[-2] = uVar19;
        puVar34[-3] = uVar42;
        puVar34[-4] = uVar29;
        puVar34[-5] = (uint)pbVar30;
        puVar34[-6] = (uint)(puVar34 + -1);
        puVar34[-7] = (uint)puVar37;
        puVar34[-8] = (uint)piVar32;
        puVar34[-9] = (uint)pbVar40;
        puVar35 = puVar34 + -10;
        puVar36 = puVar34 + -10;
        puVar34[-10] = uVar43;
        uVar11 = in(uVar29);
        uVar15 = CONCAT11((char)((ulong)uVar45 >> 8),uVar11);
        uVar19 = (uint)((uVar13 & 1) != 0);
        uVar13 = uVar15 + 0xe253;
        uVar16 = uVar13 - uVar19;
        bVar10 = 0;
        puVar34 = puVar34 + -10;
        if (uVar16 != 0) {
          uVar19 = (uint)(uVar15 < 0x1dad || uVar13 < uVar19);
          bVar12 = uVar16 < 0x1d54 || uVar16 + 0xe2ac < uVar19;
          uVar19 = (uVar16 + 0xe2ac) - uVar19;
          puVar34 = puVar35;
          puVar38 = puVar36;
          if (-1 < (int)uVar19) goto L_OVC27_2288;
          goto code_r0x0006013c;
        }
      }
      (puVar37 + (int)pbVar40)[0x20] = (puVar37 + (int)pbVar40)[0x20] & bVar27;
      bVar12 = false;
      uVar19 = (uint)(bVar10 ^ 0x20);
      puVar38 = puVar34;
L_OVC27_2288:
      cVar21 = ((char)uVar19 + -0x20) - bVar12;
      pbVar30[(int)piVar32] = pbVar30[(int)piVar32] + cVar21;
      pbVar30[(int)piVar32] = pbVar30[(int)piVar32] + cVar21;
      pbVar30[(int)piVar32] = pbVar30[(int)piVar32] + cVar21;
      pbVar30[(int)piVar32] = pbVar30[(int)piVar32] + cVar21;
      pbVar30[(int)piVar32] = pbVar30[(int)piVar32] + cVar21;
      pbVar30[(int)piVar32] = pbVar30[(int)piVar32] + cVar21;
      pbVar30[(int)piVar32] = pbVar30[(int)piVar32] + cVar21;
      pbVar30[(int)piVar32] = pbVar30[(int)piVar32] + cVar21;
      pbVar30[(int)piVar32] = pbVar30[(int)piVar32] + cVar21;
      pbVar30[(int)piVar32] = pbVar30[(int)piVar32] + cVar21;
      pbVar30[(int)piVar32] = pbVar30[(int)piVar32] + cVar21;
      pbVar30[(int)piVar32] = pbVar30[(int)piVar32] + cVar21;
      pbVar30[(int)piVar32] = pbVar30[(int)piVar32] + cVar21;
      pbVar30[(int)piVar32] = pbVar30[(int)piVar32] + cVar21;
      pbVar30[(int)piVar32] = pbVar30[(int)piVar32] + cVar21;
      pbVar30[(int)piVar32] = pbVar30[(int)piVar32] + cVar21;
      pbVar30[(int)piVar32] = pbVar30[(int)piVar32] + cVar21;
      pbVar30[(int)piVar32] = pbVar30[(int)piVar32] + cVar21;
      pbVar40[-0x75] = pbVar40[-0x75] + bVar27;
      in(uVar29);
      *(undefined2 *)((int)puVar38 + -6) = piVar32;
      iVar28 = *(int *)(puVar37 + 6);
      do {
        iVar39 = iVar28 + -1;
        if (iVar28 == 0) {
          return (far_t *)0x0;
        }
        uVar42 = *(undefined2 *)BDA_DailyTimeCounter;
        *(undefined2 *)(puVar37 + -2) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
        *(undefined2 *)(puVar37 + -4) = uVar42;
        do {
          iVar28 = iVar39;
          if (*(int *)(BDA_DailyTimeCounter.ofs + 2) != *(int *)(puVar37 + -2)) break;
        } while (*(int *)BDA_DailyTimeCounter == *(int *)(puVar37 + -4));
      } while( true );
    case (byte *)0x6:
      *(byte *)(*pasVar33 + 0x15) = bVar27;
      if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)in_stack_00000004 * 0x95) & 0x800) !=
          0) {
        *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x2d) = 0x12;
      }
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x3f) =
           *(undefined1 *)((int)(char **)GMenuStrings + (uint)in_stack_00000004 * 0x95 + 0x1f);
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x33) =
           *(undefined1 *)((int)(far_t *)(worldMenuLabels + 9) + (uint)in_stack_00000004 * 0x95);
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x31) =
           *(undefined1 *)((int)&worldMenuLabels[6].seg + (uint)in_stack_00000004 * 0x95);
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x32) =
           *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x31);
      pbVar5 = (byte *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x28);
      *pbVar5 = *pbVar5 | 0x16;
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x40) = 1;
      iVar28 = CONCAT11(in_stack_0000fffb,in_stack_0000fffa);
      uVar41 = (undefined2)(CONCAT13(in_stack_0000fffd,CONCAT12(in_stack_0000fffc,iVar28)) >> 0x10);
      *(undefined2 *)(iVar28 + 0x58) = 0;
      *(undefined2 *)(iVar28 + 0x56) = 100;
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x89) = 0xff;
      uVar11 = 0x5d;
      pfVar17 = ovr_ovc22_textRingProt();
      return (far_t *)CONCAT11((char)((uint)pfVar17 >> 8),uVar11);
    case (byte *)0x7:
      do {
        unaff_DI = (byte *)((uint)unaff_DI | *(uint *)(pbVar20 + (int)(*pasVar33 + -2)) & 0x3000);
        unaff_SI = (far_t *)((int)&unaff_SI->ofs + 1);
        while( true ) {
          if ((int)unaff_SI < 4) break;
          pfVar17 = (far_t *)CONCAT11(in_stack_0000fffb,in_stack_0000fffa);
          if (unaff_DI == (byte *)((int)&AgntAnms[0x38].halfWidth + 1)) {
            GPromotableCount = (uint16_t)(((int)&GPromotableCount->ofs + 1));
            pfVar17 = (far_t *)CONCAT11(in_stack_0000fffb,in_stack_0000fffa);
          }
          do {
            pfVar17 = (far_t *)((int)&pfVar17->ofs + 1);
            if (GUnitCount <= pfVar17) {
              return GUnitCount;
            }
            uVar42 = (undefined2)((ulong)GUnits >> 0x10);
            bVar27 = ((unit_t *)GUnits)[(int)pfVar17].unitType;
          } while ((((*(uint *)((uint)((unit_t *)GUnits + (int)pfVar17)->bldType * 0x27 + 0x121) &
                     0x60) != 0) || (bVar27 == 0xff)) ||
                  (uVar45 = *(undefined4 *)((uint)bVar27 << 2),
                  *(char *)((int)uVar45 + 0x3f) != '\0'));
          in_stack_0000fffa = (undefined1)uVar41;
          in_stack_0000fffb = (char)((uint)uVar41 >> 8);
          uVar41 = 0x2379;
          uVar19 = ovr_alignUp4();
          in_stack_0000fff8 = (undefined1)uVar19;
          in_stack_0000fff9 = (undefined1)(uVar19 >> 8);
          in_stack_0000fff6 = ((unit_t *)GUnits)[CONCAT11(in_stack_0000fffb,in_stack_0000fffa)].y;
          unaff_DI = (byte *)0x0;
          unaff_SI = (far_t *)0x0;
        }
        unaff_ES = (undefined2)((ulong)GMapFlags >> 0x10);
        pasVar33 = *(short (*) [60] [148])GMapFlags + in_stack_0000fff6;
        pbVar20 = (byte *)((int)((int)&unaff_SI->ofs + CONCAT11(in_stack_0000fff9,in_stack_0000fff8)
                                ) * 2);
      } while( true );
    case (byte *)0x8:
      if (*(uint *)((int)*(undefined4 *)pbVar20 + 0x54) <
          (uint)-*(int *)((int)*(undefined4 *)((uint)in_stack_00000004 << 2) + 0x4d)) {
        (*(uint8_t *)((uint8_t *)&(uStack_e) + 1)) = 5;
      }
      else {
        (*(uint8_t *)((uint8_t *)&(uStack_e) + 1)) = 4;
      }
      if (((in_stack_0000fff4 == 0) || (in_stack_0000fff4 < (byte)uStack_e)) ||
         (in_stack_0000fff4 < (*(uint8_t *)((uint8_t *)&(uStack_e) + 1)))) {
        if (((byte)uStack_e == 0) || ((byte)uStack_e < (*(uint8_t *)((uint8_t *)&(uStack_e) + 1)))) {
          if ((*(uint8_t *)((uint8_t *)&(uStack_e) + 1)) == 0) {
            ovc39_lordOrLady();
            uStack_e = auStack_2cc;
            uStack_10 = 0x6000;
            uStack_12 = 0x9bb1;
            pfVar17 = (far_t *)ovr_stsprintf();
            ovr_drawString();
          }
          else {
            ovc39_loadArchiveEntry((*(uint8_t *)((uint8_t *)&(uStack_e) + 1)) + 0x17);
            ovc39_lordOrLady();
            uStack_e = auStack_2cc;
            uStack_10 = 0x6000;
            uStack_12 = 0x9b7b;
            pfVar17 = (far_t *)ovr_stsprintf();
            ovr_drawString();
            ovr_stshFree();
          }
        }
        else {
          ovc39_loadArchiveEntry((byte)uStack_e + 0xd);
          ovc39_lordOrLady();
          uStack_e = auStack_2cc;
          uStack_10 = 0x6000;
          uStack_12 = 0x9b2e;
          pfVar17 = (far_t *)ovr_stsprintf();
          ovr_drawString();
          ovr_stshFree();
        }
      }
      else {
        ovc39_loadArchiveEntry(in_stack_0000fff4 + 0x12);
        ovc39_lordOrLady();
        uStack_e = auStack_2cc;
        uStack_10 = 0x6000;
        uStack_12 = 0x9ad8;
        pfVar17 = (far_t *)ovr_stsprintf();
        ovr_drawString();
        ovr_stshFree();
      }
      return pfVar17;
    }
  }
  uVar11 = 0x24;
  if (MouseMoved == 0) {
    ovc28_textHalflingCastle();
    bVar27 = (byte)(MouseX - 0xc >> 9);
    ovr_ovc13_usesBlitLoadRleGfx2();
    return (far_t *)CONCAT11(bVar27,0xfe);
  }
L_OVC28_6018_0c76_0EAD:
  if (((keyboardInputMode == '\0') || (uVar11 = 0x24, MouseMoved != 0)) ||
     (((uVar11 = 0x24, MouseX < 0xef ||
       ((uVar11 = 0x24, 0x134 < MouseX || (uVar11 = 0x24, MouseY < 7)))) ||
      (uVar11 = 0x24, 0x36 < MouseY)))) {
    pfVar17 = (far_t *)CONCAT11(uVar11,0xff);
  }
  else {
    ovc28_textHalflingCastle();
    bVar27 = (byte)(MouseX - 0xef >> 9);
    ovr_ovc13_usesBlitLoadRleGfx3();
    pfVar17 = (far_t *)CONCAT11(bVar27,0xfe);
  }
                    /* WARNING: Read-only address (ram,0x0002c58a) is written */
  return pfVar17;
}



/* 6386:05d3 */

/* [R7] body shape: compute */

char __cdecl16far stats_compute4(agnt_t *agnt,...)

{
  byte bVar1;
  int iVar2;
  undefined2 uVar3;
  char cVar4;
  int in_stack_00000004;
  undefined3 in_stack_0000fff8;
  agnt_t *agnt_00;
  
  bVar1 = *(byte *)(in_stack_00000004 + 0xd);
  if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar1 * 0x95) == -1) {
    cVar4 = *(char *)((int)&worldMenuLabels[9].seg + (uint)bVar1 * 0x95);
  }
  else {
    agnt_00 = (agnt_t *)CONCAT22((int)(CONCAT13(bVar1,in_stack_0000fff8) >> 0x10),(agnt_t *)agnt);
    bVar1 = ovr_agnt_compute10(agnt_00,in_stack_00000004);
    iVar2 = (uint)(byte)((ulong)agnt_00 >> 0x18) * 0x95;
    bVar1 = *(char *)((int)&worldMenuLabels[9].seg + iVar2) - bVar1;
    uVar3 = ovr_agnt_abilityModifier
                      (3,bVar1,CONCAT11((char)((uint)iVar2 >> 8),
                                        *(undefined1 *)(in_stack_00000004 + 0x1a)));
    cVar4 = bVar1 - (char)uVar3;
  }
  return cVar4;
}



/* 6386:065c */

/* WARNING: Removing unreachable block (ram,0x00063ec8) */
/* Formats a long for the stats screen, switching to a 'K' suffix above a thousand. */

char * __cdecl16far stats_formatThousands(char *text,uint32_t value)

{
  size_t sVar1;
  undefined2 unaff_SI;
  long lVar2;
  
  if ((long)value < 1000000) {
    (*(uint16_t *)((uint8_t *)&(text))) = ovr_litoa10((char *)CONCAT22((undefined2)value,(*(uint16_t *)((uint8_t *)&(text) + 2))),
                             CONCAT22(unaff_SI,(*(uint16_t *)((uint8_t *)&(value) + 2))),(char *)text);
  }
  else {
    lVar2 = LDIV_at_(value,1000);
    ovr_litoa10((char *)CONCAT22((int)lVar2,(*(uint16_t *)((uint8_t *)&(text) + 2))),
                CONCAT22(unaff_SI,(int)((ulong)lVar2 >> 0x10)),(char *)text);
    sVar1 = strlen(text);
    ((char *)text)[sVar1] = 'K';
    ((char *)text)[sVar1 + 1] = '\0';
  }
  return (char *)text;
}



/* 6386:06cd */

/* WARNING: Variable defined which should be unmapped: palbuf */
/* WARNING: Variable defined which should be unmapped: cmap */

void __cdecl16far drawAgntStats(agnt_t *agnt,far_t cmap,...)

{
  undefined4 uVar1;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t ringValue;
  far_t palette;
  agnt_t *paVar2;
  undefined1 uVar3;
  byte bVar4;
  undefined1 uVar5;
  char cVar6;
  char *pcVar7;
  uint uVar8;
  int *piVar9;
  undefined2 *puVar10;
  int iVar11;
  char *pcVar12;
  far_t *pfVar13;
  undefined2 in_DX;
  uint16_t agnt_o;
  entity_t *peVar14;
  uint16_t agnt_s;
  undefined2 uVar15;
  char *unaff_SS;
  agnt_t *in_stack_00000004;
  uint8_t field_index_00;
  undefined1 uVar16;
  undefined1 uVar17;
  undefined1 uVar18;
  undefined1 uVar19;
  undefined2 uVar20;
  undefined2 uVar21;
  undefined1 uVar22;
  undefined1 uVar23;
  undefined1 uVar24;
  undefined1 uVar25;
  char palbuf [768];
  char buf [80];
  uint8_t text;
  uint8_t line;
  uint8_t field_index;
  byte bStack_4;
  int8_t damage;
  
  paVar2 = agnt;
  TextBlitDstSeg = 0xa000;
  if ((*(uint16_t *)((uint8_t *)&(agnt) + 2)) == (char *)0x0 && cmap.ofs == 0) {
    (*(uint16_t *)((uint8_t *)&(agnt) + 2)) = palbuf;
    cmap.ofs = (uint16_t)unaff_SS;
  }
  if (!GameRunning) {
    stats_drawStatsPanel();
  }
  if (DebugVerbose != false) {
    printf("Exp %ld \r");
  }
  field_index = (*(uint *)((int)&(((entity_t *)in_stack_00000004->entity)->base).frames + 3) & 1) !=
                0;
  bStack_4 = field_index;
  if (3 < (((entity_t *)in_stack_00000004->entity)->base).level) {
    bStack_4 = field_index + 4;
  }
  uVar20 = *(undefined2 *)((int)&in_stack_00000004->gdata + 2);
  stats_drawPortrait((agntG_t *)
                     CONCAT13((char)((uint)uVar20 >> 8),
                              CONCAT12((char)uVar20,*(undefined2 *)&in_stack_00000004->gdata)),
                     bStack_4,(int)(*(uint16_t *)((uint8_t *)&(agnt) + 2)));
  TextBlitY = 10;
  TextBlitX = 0x87;
  uVar22 = 0xe0;
  uVar23 = 0;
  uVar20 = 0xde;
  uVar18 = (undefined1)Font02.seg;
  uVar19 = (undefined1)(Font02.seg >> 8);
  uVar5 = (undefined1)Font02.ofs;
  uVar17 = (undefined1)(Font02.ofs >> 8);
  pcVar7 = ovr_agnt_statusText((agnt_t *)
                               CONCAT13((char)((uint)&line >> 8),
                                        CONCAT12((char)&line,(agnt_t *)agnt)),
                               (char *)CONCAT13(uVar17,CONCAT12(uVar5,unaff_SS)),
                               (char)in_stack_00000004);
  ovr_blitLabel((char *)CONCAT13(uVar17,CONCAT12(uVar5,in_DX)),
                (uint8_t *)CONCAT22(uVar20,(uint8_t *)CONCAT11(uVar19,uVar18)),
                CONCAT11(uVar23,uVar22),palbuf[0],(char)pcVar7,uVar18,uVar22);
  if ((GameRunning == false) && ((in_stack_00000004->gdata->ai == 0 || (DebugVerbose != false)))) {
    TextBlitY = 0xb5;
    TextBlitX = 0x13;
    if ((*(byte *)((int)&(((entity_t *)in_stack_00000004->entity)->base).flags32 + 1) & 1) == 0) {
      (*(uint8_t *)((uint8_t *)&(gfx_00.seg))) = 0x10;
      gfx_00.ofs = butt01Cut3Seg;
      (*(uint8_t *)((uint8_t *)&(gfx_00.seg) + 1)) = 0;
      ovr_blitGfxRect(gfx_00,179,1098,(brect_t *)0x102410,0x0,(bool)palbuf[0],(char)butt01Cut3Ofs,
                      0x4a,0x10,0);
    }
    else {
      (*(uint8_t *)((uint8_t *)&(gfx.seg))) = 0x10;
      gfx.ofs = butt01Cut4Seg;
      (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = 0;
      ovr_blitGfxRect(gfx,179,1098,(brect_t *)0x102410,0x0,(bool)palbuf[0],(char)butt01Cut4Ofs,0x4a,
                      0x10,0);
      TextBlitX = 0x47;
      ovr_blitLabel((char *)CONCAT13((char)(Font01.ofs >> 8),CONCAT12((char)Font01.ofs,0x2410)),
                    (uint8_t *)CONCAT22(0xde,Font01.seg),224,palbuf[0],0xdb,(char)Font01.seg,0xe0);
      TextBlitX = 0x13;
    }
    ovr_blitLabel((char *)CONCAT13((char)(Font01.ofs >> 8),CONCAT12((char)Font01.ofs,0x2410)),
                  (uint8_t *)CONCAT22(0xde,Font01.seg),224,palbuf[0],0xdd,(char)Font01.seg,0xe0);
    TextBlitY = 0xb5;
    TextBlitX = 0x57;
    uVar8 = stats_usesAlignUp4(in_stack_00000004->owner);
    if ((char)uVar8 == '\0') {
      (*(uint8_t *)((uint8_t *)&(gfx_02.seg))) = 0x54;
      gfx_02.ofs = butt01Cut3Seg;
      (*(uint8_t *)((uint8_t *)&(gfx_02.seg) + 1)) = 0;
      ovr_blitGfxRect(gfx_02,179,1098,(brect_t *)0x102410,0x0,(bool)palbuf[0],(char)butt01Cut3Ofs,
                      0x4a,0x10,0);
    }
    else {
      (*(uint8_t *)((uint8_t *)&(gfx_01.seg))) = 0x54;
      gfx_01.ofs = butt01Cut4Seg;
      (*(uint8_t *)((uint8_t *)&(gfx_01.seg) + 1)) = 0;
      ovr_blitGfxRect(gfx_01,179,1098,(brect_t *)0x102410,0x0,(bool)palbuf[0],(char)butt01Cut4Ofs,
                      0x4a,0x10,0);
      TextBlitX = 0x8b;
      ovr_blitLabel((char *)CONCAT13((char)(Font01.ofs >> 8),CONCAT12((char)Font01.ofs,0x2410)),
                    (uint8_t *)CONCAT22(0xde,Font01.seg),224,palbuf[0],0xdb,(char)Font01.seg,0xe0);
      TextBlitX = 0x57;
    }
    ovr_blitLabel((char *)CONCAT13((char)(FontMain.ofs >> 8),CONCAT12((char)FontMain.ofs,0x2410)),
                  (uint8_t *)CONCAT22(0xde,FontMain.seg),224,palbuf[0],0xe3,(char)FontMain.seg,0xe0)
    ;
    TextBlitY = 0xb5;
    TextBlitX = 0x9b;
    uVar8 = stats_usesAlignUp4(in_stack_00000004->owner);
    if (((uVar8 & 0xff) == 0) &&
       ((*(byte *)((int)&(((entity_t *)in_stack_00000004->entity)->base).flags32 + 1) & 1) == 0)) {
      (*(uint8_t *)((uint8_t *)&(gfx_03.seg))) = 0x98;
      gfx_03.ofs = butt01Cut4Seg;
      (*(uint8_t *)((uint8_t *)&(gfx_03.seg) + 1)) = 0;
      ovr_blitGfxRect(gfx_03,179,1098,(brect_t *)0x102410,0x0,(bool)palbuf[0],(char)butt01Cut4Ofs,
                      0x4a,0x10,0);
      TextBlitX = 0xcf;
      ovr_blitLabel((char *)CONCAT13((char)(Font01.ofs >> 8),CONCAT12((char)Font01.ofs,0x2410)),
                    (uint8_t *)CONCAT22(0xde,Font01.seg),224,palbuf[0],0xdb,(char)Font01.seg,0xe0);
      TextBlitX = 0x9b;
    }
    else {
      (*(uint8_t *)((uint8_t *)&(gfx_04.seg))) = 0x98;
      gfx_04.ofs = butt01Cut3Seg;
      (*(uint8_t *)((uint8_t *)&(gfx_04.seg) + 1)) = 0;
      ovr_blitGfxRect(gfx_04,179,1098,(brect_t *)0x102410,0x0,(bool)palbuf[0],(char)butt01Cut3Ofs,
                      0x4a,0x10,0);
    }
    ovr_blitLabel((char *)CONCAT13((char)(FontMain.ofs >> 8),CONCAT12((char)FontMain.ofs,0x2410)),
                  (uint8_t *)CONCAT22(0xde,FontMain.seg),224,palbuf[0],0xe8,(char)FontMain.seg,0xe0)
    ;
  }
  TextBlitY = 0x11;
  TextBlitX = 0x87;
  uVar22 = 0xe0;
  uVar23 = 0;
  uVar20 = 0xde;
  uVar18 = (undefined1)Font02.seg;
  uVar19 = (undefined1)(Font02.seg >> 8);
  uVar5 = (undefined1)Font02.ofs;
  uVar17 = (undefined1)(Font02.ofs >> 8);
  pcVar7 = ovr_stsprintf((char *)CONCAT13(0x62,CONCAT12(0xf3,unaff_SS)),
                         (char *)(ulong)CONCAT12((((entity_t *)in_stack_00000004->entity)->base).
                                                 animFrame,0x2410),(char *)Font02.ofs,&line,0x10,
                         uVar5);
  ovr_blitLabel((char *)CONCAT13(uVar17,CONCAT12(uVar5,in_DX)),
                (uint8_t *)CONCAT22(uVar20,(uint8_t *)CONCAT11(uVar19,uVar18)),
                CONCAT11(uVar23,uVar22),palbuf[0],(char)pcVar7,uVar18,uVar22);
  TextBlitY = 0x1b;
  TextBlitX = 0x87;
  if (*(char *)((int)&(((entity_t *)in_stack_00000004->entity)->base).entity + 3) != -1) {
    puVar10 = (undefined2 *)
              ((uint)*(byte *)((int)&(((entity_t *)in_stack_00000004->entity)->base).entity + 3) * 4
              );
    uVar8 = ovr_font_textWidth((char *)CONCAT22(Font02.ofs,(char *)puVar10[1]),
                               (char *)CONCAT13(palbuf[1],CONCAT12(palbuf[0],Font02.seg)),
                               (char)*puVar10,(char)Font02.seg);
    uVar18 = (undefined1)Font02.seg;
    uVar19 = (undefined1)(Font02.seg >> 8);
    uVar5 = (undefined1)Font02.ofs;
    uVar17 = (undefined1)(Font02.ofs >> 8);
    if (uVar8 < 0x30) {
      uVar22 = 0xe0;
      uVar23 = 0;
      uVar20 = 0xde;
      puVar10 = (undefined2 *)
                ((uint)*(byte *)((int)&(((entity_t *)in_stack_00000004->entity)->base).entity + 3) *
                4);
      in_DX = 0x217a;
      ovr_stsprintf((char *)CONCAT22(0x62fe,unaff_SS),
                    (char *)CONCAT22(*puVar10,(char *)"puppetmaker" + 3),(char *)puVar10[1],&text);
      iVar11 = ovr_ovc45_compute9();
      ovr_blitLabel((char *)CONCAT13(uVar17,CONCAT12(uVar5,in_DX)),
                    (uint8_t *)CONCAT22(uVar20,(uint8_t *)CONCAT11(uVar19,uVar18)),
                    CONCAT11(uVar23,uVar22),palbuf[0],(char)iVar11,uVar18,uVar22);
    }
    else {
      uVar22 = 0xe0;
      uVar23 = 0;
      uVar20 = 0xde;
      puVar10 = (undefined2 *)
                ((uint)*(byte *)((int)&(((entity_t *)in_stack_00000004->entity)->base).entity + 3) *
                4);
      in_DX = 0x217a;
      ovr_stsprintf((char *)CONCAT22(0x630a,unaff_SS),
                    (char *)CONCAT22(*puVar10,(char *)"puppetmaker" + 3),(char *)puVar10[1],&text);
      iVar11 = ovr_ovc45_compute9();
      ovr_blitLabel((char *)CONCAT13(uVar17,CONCAT12(uVar5,in_DX)),
                    (uint8_t *)CONCAT22(uVar20,(uint8_t *)CONCAT11(uVar19,uVar18)),
                    CONCAT11(uVar23,uVar22),palbuf[0],(char)iVar11,uVar18,uVar22);
    }
  }
  TextBlitY = 0x25;
  TextBlitX = 0x87;
  uVar5 = SUB41(paVar2,0);
  if (((agntG_t *)in_stack_00000004->gdata)->shortName[3] != -1) {
    uVar23 = (undefined1)((ulong)paVar2 >> 8);
    cVar6 = stats_compute3((agnt_t *)CONCAT13(uVar23,CONCAT12(uVar5,in_stack_00000004)));
    uVar19 = (undefined1)Font02.seg;
    uVar22 = (undefined1)(Font02.seg >> 8);
    uVar17 = (undefined1)Font02.ofs;
    uVar18 = (undefined1)(Font02.ofs >> 8);
    if (cVar6 == '\0') {
      uVar24 = 0xe0;
      uVar25 = 0;
      uVar15 = 0xde;
      bVar4 = stats_compute2((agnt_t *)CONCAT22((agnt_t *)agnt,in_stack_00000004));
      pcVar7 = ovr_manage_compute1(CONCAT11(uVar18,uVar17),(uint)bVar4);
      uVar3 = SUB21(pcVar7,0);
      uVar16 = (undefined1)((uint)pcVar7 >> 8);
      uVar20 = in_DX;
      uVar5 = stats_compute2((agnt_t *)CONCAT13(uVar23,CONCAT12(uVar5,in_stack_00000004)));
      pcVar7 = ovr_stsprintf((char *)CONCAT22(0x6323,unaff_SS),(char *)(ulong)CONCAT12(uVar5,0x2410)
                             ,(char *)CONCAT11(uVar16,uVar3),&line,0x10,uVar5,uVar3,uVar20);
      ovr_blitLabel((char *)CONCAT13(uVar18,CONCAT12(uVar17,in_DX)),
                    (uint8_t *)CONCAT22(uVar15,(uint8_t *)CONCAT11(uVar22,uVar19)),
                    CONCAT11(uVar25,uVar24),palbuf[0],(char)pcVar7,uVar19,uVar24);
    }
    else {
      uVar16 = 0xe0;
      uVar24 = 0;
      uVar20 = 0xde;
      cVar6 = stats_compute1((agnt_t *)CONCAT22((agnt_t *)agnt,in_stack_00000004));
      iVar11 = (int)cVar6;
      uVar3 = stats_compute2((agnt_t *)CONCAT13(uVar23,CONCAT12(uVar5,in_stack_00000004)));
      ovr_manage_compute1(iVar11,uVar3);
      stats_compute2((agnt_t *)CONCAT13(uVar23,CONCAT12(uVar5,in_stack_00000004)));
      pcVar7 = ovr_stsprintf();
      ovr_blitLabel((char *)CONCAT13(uVar18,CONCAT12(uVar17,in_DX)),
                    (uint8_t *)CONCAT22(uVar20,(uint8_t *)CONCAT11(uVar22,uVar19)),
                    CONCAT11(uVar24,uVar16),palbuf[0],(char)pcVar7,uVar19,uVar16);
    }
  }
  uVar5 = (undefined1)(Font02.ofs >> 8);
  if ((((agntG_t *)in_stack_00000004->gdata)->shortName[3] == -1) ||
     (*(char *)((int)&(((entity_t *)in_stack_00000004->entity)->base).entity + 3) == -1)) {
    uVar8 = (uint)(byte)((agntG_t *)in_stack_00000004->gdata)->shortName[2];
    pcVar7 = (char *)"puppetmaker" + 3;
    ovr_blitLabel((char *)CONCAT13(uVar5,CONCAT12((char)Font02.ofs,
                                                  *(undefined2 *)
                                                   ((int)&GAlignmentsNames[0].seg + uVar8 * 4))),
                  (uint8_t *)CONCAT22(0xde,Font02.seg),224,palbuf[0],
                  (char)((far_t *)GAlignmentsNames + uVar8)->ofs,(char)Font02.seg,0xe0);
  }
  else {
    uVar1 = *(undefined4 *)
             ((uint)*(byte *)((int)&(((entity_t *)in_stack_00000004->entity)->base).entity + 3) << 2
             );
    uVar8 = (uint)*(byte *)((int)uVar1 + 0x33);
    pcVar7 = (char *)"puppetmaker" + 3;
    ovr_blitLabel((char *)CONCAT13(uVar5,CONCAT12((char)Font02.ofs,
                                                  *(undefined2 *)
                                                   ((int)&GAlignmentsNames[0].seg + uVar8 * 4))),
                  (uint8_t *)CONCAT22(0xde,Font02.seg),224,palbuf[0],
                  (char)((far_t *)GAlignmentsNames + uVar8)->ofs,(char)Font02.seg,0xe0);
  }
  TextBlitY = 0x2f;
  TextBlitX = 0x87;
  if ((((agntG_t *)in_stack_00000004->gdata)->shortName[3] != -1) &&
     (in_stack_00000004->gdata->ai == 0)) {
    ovr_blitLabel((char *)CONCAT13((char)(Font02.ofs >> 8),CONCAT12((char)Font02.ofs,0x2410)),
                  (uint8_t *)CONCAT22(0xde,Font02.seg),224,palbuf[0],0x30,(char)Font02.seg,0xe0);
    TextBlitY = 0x36;
    TextBlitX = 0x87;
    piVar9 = (int *)((uint)(byte)((agntG_t *)in_stack_00000004->gdata)->shortName[3] * 0x94 +
                    (uint)(((entity_t *)in_stack_00000004->entity)->base).level * 4);
    pcVar7 = (char *)"sturdy e/w wall" + 0xf;
    uVar18 = (undefined1)Font02.seg;
    uVar19 = (undefined1)(Font02.seg >> 8);
    uVar5 = (undefined1)Font02.ofs;
    uVar17 = (undefined1)(Font02.ofs >> 8);
    if (*piVar9 == 0 && piVar9[1] == 0) {
      uVar22 = 0xe0;
      uVar23 = 0;
      uVar21 = 0xde;
      uVar15 = (undefined2)((ulong)in_stack_00000004->entity >> 0x10);
      peVar14 = (entity_t *)in_stack_00000004->entity;
      uVar20 = *(undefined2 *)&(peVar14->base).health;
      pcVar12 = ovr_litoa10((char *)CONCAT13((char)((uint)uVar20 >> 8),
                                             CONCAT12((char)uVar20,unaff_SS)),
                            CONCAT13(uVar17,CONCAT12(uVar5,*(undefined2 *)
                                                            &(peVar14->base).frameIndex)),
                            (char)&text);
      pcVar12 = ovr_stsprintf((char *)CONCAT13(99,CONCAT12(7,unaff_SS)),
                              (char *)CONCAT13((char)((uint)pcVar12 >> 8),
                                               CONCAT12((char)pcVar12,0x2410)),pcVar7,&line,0x10,
                              (char)pcVar12);
      ovr_blitLabel((char *)CONCAT13(uVar17,CONCAT12(uVar5,pcVar7)),
                    (uint8_t *)CONCAT22(uVar21,(uint8_t *)CONCAT11(uVar19,uVar18)),
                    CONCAT11(uVar23,uVar22),palbuf[0],(char)pcVar12,uVar18,uVar22);
    }
    else {
      uVar22 = 0xe0;
      uVar23 = 0;
      uVar21 = 0xde;
      puVar10 = (undefined2 *)
                ((uint)(byte)((agntG_t *)in_stack_00000004->gdata)->shortName[3] * 0x94 +
                (uint)(((entity_t *)in_stack_00000004->entity)->base).level * 4);
      pcVar7 = (char *)"sturdy e/w wall" + 0xf;
      stats_formatThousands
                ((char *)CONCAT13((char)((uint)unaff_SS >> 8),CONCAT12((char)unaff_SS,buf)),
                 CONCAT22(puVar10[1],*puVar10));
      uVar15 = (undefined2)((ulong)in_stack_00000004->entity >> 0x10);
      peVar14 = (entity_t *)in_stack_00000004->entity;
      uVar20 = *(undefined2 *)&(peVar14->base).frameIndex;
      stats_formatThousands
                ((char *)CONCAT22(unaff_SS,&text),
                 CONCAT13((char)((uint)uVar20 >> 8),
                          CONCAT12((char)uVar20,*(undefined2 *)&(peVar14->base).health)));
      pcVar12 = ovr_stsprintf();
      ovr_blitLabel((char *)CONCAT13(uVar17,CONCAT12(uVar5,pcVar7)),
                    (uint8_t *)CONCAT22(uVar21,(uint8_t *)CONCAT11(uVar19,uVar18)),
                    CONCAT11(uVar23,uVar22),palbuf[0],(char)pcVar12,uVar18,uVar22);
    }
  }
  if (in_stack_00000004->gdata->ai != 0) {
    uVar22 = 0xe0;
    uVar23 = 0;
    uVar20 = 0xde;
    uVar18 = (undefined1)Font02.seg;
    uVar19 = (undefined1)(Font02.seg >> 8);
    uVar5 = (undefined1)Font02.ofs;
    uVar17 = (undefined1)(Font02.ofs >> 8);
    iVar11 = ovr_ovc41_growthForLevel
                       ((agnt_t *)
                        CONCAT13(uVar17,CONCAT12(uVar5,*(undefined2 *)
                                                        ((int)&in_stack_00000004->entity + 2))),
                        (char)*(undefined2 *)&in_stack_00000004->entity);
    pcVar12 = ovr_stsprintf((char *)CONCAT13(99,CONCAT12(0x48,unaff_SS)),
                            (char *)CONCAT13((char)((uint)iVar11 >> 8),CONCAT12((char)iVar11,0x2410)
                                            ),pcVar7,&line,0x10,(char)iVar11);
    ovr_blitLabel((char *)CONCAT13(uVar17,CONCAT12(uVar5,pcVar7)),
                  (uint8_t *)CONCAT22(uVar20,(uint8_t *)CONCAT11(uVar19,uVar18)),
                  CONCAT11(uVar23,uVar22),palbuf[0],(char)pcVar12,uVar18,uVar22);
  }
  TextBlitY = 0x40;
  TextBlitX = 0x87;
  uVar22 = 0xe0;
  uVar23 = 0;
  uVar20 = 0xde;
  uVar18 = (undefined1)Font02.seg;
  uVar19 = (undefined1)(Font02.seg >> 8);
  uVar5 = (undefined1)Font02.ofs;
  uVar17 = (undefined1)(Font02.ofs >> 8);
  pcVar12 = ovr_stsprintf((char *)CONCAT13(99,CONCAT12(0x54,unaff_SS)),
                          (char *)(ulong)CONCAT12(in_stack_00000004->strength,0x2410),
                          (char *)(uint)in_stack_00000004->strengthMax,&line,0x10,
                          in_stack_00000004->strength);
  ovr_blitLabel((char *)CONCAT13(uVar17,CONCAT12(uVar5,pcVar7)),
                (uint8_t *)CONCAT22(uVar20,(uint8_t *)CONCAT11(uVar19,uVar18)),
                CONCAT11(uVar23,uVar22),palbuf[0],(char)pcVar12,uVar18,uVar22);
  TextBlitY = 0x4a;
  TextBlitX = 0x87;
  iVar11 = (uint)((agntG_t *)in_stack_00000004->gdata)->type * 0x95;
  pcVar7 = (char *)((int)&BuildingTypes[0x9f].income + 1);
  if (*(int *)((int)&AgntGs[0].wpn_name + iVar11) == 0 &&
      *(int *)((int)&AgntGs[0].wpn_name + 2 + iVar11) == 0) {
    damage = 0;
  }
  else {
    damage = ovr_agnt_compute9((agnt_t *)CONCAT13(palbuf[1],CONCAT12(palbuf[0],(agnt_t *)agnt)),
                               in_stack_00000004);
    uVar18 = (undefined1)Font02.seg;
    uVar19 = (undefined1)(Font02.seg >> 8);
    uVar5 = (undefined1)Font02.ofs;
    uVar17 = (undefined1)(Font02.ofs >> 8);
    field_index_00 = (uint8_t)in_stack_00000004;
    if (damage == 0) {
      uVar22 = 0xe0;
      uVar23 = 0;
      uVar20 = 0xde;
      pcVar12 = agntGetWeaponName((char *)CONCAT22(CONCAT11(0x24,((agntG_t *)
                                                                 in_stack_00000004->gdata)->type),
                                                   unaff_SS),0x0,(bool)field_index,field_index_00,
                                  CONCAT13(uVar17,CONCAT12(uVar5,(agnt_t *)agnt)));
      ovr_blitLabel((char *)CONCAT13(uVar17,CONCAT12(uVar5,pcVar7)),
                    (uint8_t *)CONCAT22(uVar20,(uint8_t *)CONCAT11(uVar19,uVar18)),
                    CONCAT11(uVar23,uVar22),palbuf[0],(char)pcVar12,uVar18,uVar22);
    }
    else if (damage < '\0') {
      uVar22 = 0xe0;
      uVar23 = 0;
      uVar20 = 0xde;
      pcVar12 = agntGetWeaponName((char *)CONCAT22(CONCAT11(0x24,((agntG_t *)
                                                                 in_stack_00000004->gdata)->type),
                                                   unaff_SS),damage,(bool)field_index,field_index_00
                                  ,CONCAT13(uVar17,CONCAT12(uVar5,(agnt_t *)agnt)));
      pcVar12 = ovr_stsprintf((char *)CONCAT13(99,CONCAT12(0x65,unaff_SS)),
                              (char *)CONCAT13((char)((uint)pcVar12 >> 8),
                                               CONCAT12((char)pcVar12,0x2410)),pcVar7,&line,0x10,
                              (char)pcVar12);
      ovr_blitLabel((char *)CONCAT13(uVar17,CONCAT12(uVar5,pcVar7)),
                    (uint8_t *)CONCAT22(uVar20,(uint8_t *)CONCAT11(uVar19,uVar18)),
                    CONCAT11(uVar23,uVar22),palbuf[0],(char)pcVar12,uVar18,uVar22);
    }
    else {
      uVar22 = 0xe0;
      uVar23 = 0;
      uVar20 = 0xde;
      pcVar12 = agntGetWeaponName((char *)CONCAT22(CONCAT11(0x24,((agntG_t *)
                                                                 in_stack_00000004->gdata)->type),
                                                   unaff_SS),damage,(bool)field_index,field_index_00
                                  ,CONCAT13(uVar17,CONCAT12(uVar5,(agnt_t *)agnt)));
      pcVar12 = ovr_stsprintf((char *)CONCAT22(0x6370,unaff_SS),
                              (char *)CONCAT13(damage >> 7,CONCAT12(damage,0x2410)),pcVar12,&line,
                              0x10,damage,(char)pcVar12,pcVar7);
      ovr_blitLabel((char *)CONCAT13(uVar17,CONCAT12(uVar5,pcVar7)),
                    (uint8_t *)CONCAT22(uVar20,(uint8_t *)CONCAT11(uVar19,uVar18)),
                    CONCAT11(uVar23,uVar22),palbuf[0],(char)pcVar12,uVar18,uVar22);
    }
  }
  TextBlitY = 0x54;
  TextBlitX = 0x87;
  if (in_stack_00000004->gdata->ai == 0) {
    damage = ovr_agnt_compute11((agnt_t *)CONCAT13(palbuf[1],CONCAT12(palbuf[0],(agnt_t *)agnt)),
                                in_stack_00000004);
  }
  else {
    damage = 0;
  }
  uVar22 = 0xe0;
  uVar23 = 0;
  uVar20 = 0xde;
  uVar18 = (undefined1)Font02.seg;
  uVar19 = (undefined1)(Font02.seg >> 8);
  uVar5 = (undefined1)Font02.ofs;
  uVar17 = (undefined1)(Font02.ofs >> 8);
  cVar6 = stats_compute4((agnt_t *)
                         CONCAT13(uVar17,CONCAT12(uVar5,*(undefined2 *)
                                                         ((int)&in_stack_00000004->entity + 2))),
                         (char)*(undefined2 *)&in_stack_00000004->entity);
  pcVar12 = ovr_stsprintf((char *)CONCAT13(99,CONCAT12(0x77,unaff_SS)),
                          (char *)CONCAT22((int)cVar6,(char *)"puppetmaker" + 3),
                          (char *)CONCAT11(uVar17,uVar5),&line,0x10,uVar5);
  ovr_blitLabel((char *)CONCAT13(uVar17,CONCAT12(uVar5,pcVar7)),
                (uint8_t *)CONCAT22(uVar20,(uint8_t *)CONCAT11(uVar19,uVar18)),
                CONCAT11(uVar23,uVar22),palbuf[0],(char)pcVar12,uVar18,uVar22);
  if (in_stack_00000004->gdata->ai == 0) {
    TextBlitY = 0x5e;
    TextBlitX = 0x87;
    uVar22 = 0xe0;
    uVar23 = 0;
    uVar20 = 0xde;
    uVar18 = (undefined1)Font02.seg;
    uVar19 = (undefined1)(Font02.seg >> 8);
    uVar5 = (undefined1)Font02.ofs;
    uVar17 = (undefined1)(Font02.ofs >> 8);
    (*(uint8_t *)((uint8_t *)&(ringValue.seg))) = uVar18;
    ringValue.ofs = Font02.ofs;
    (*(uint8_t *)((uint8_t *)&(ringValue.seg) + 1)) = uVar19;
    pfVar13 = stats_textRingProt((char *)CONCAT13(0x24,CONCAT12(((agntG_t *)in_stack_00000004->gdata
                                                                )->type,unaff_SS)),
                                 CONCAT11(0x24,((agntG_t *)in_stack_00000004->gdata)->shortName[4]),
                                 CONCAT11(0x24,damage),ringValue);
    ovr_blitLabel((char *)CONCAT13(uVar17,CONCAT12(uVar5,pcVar7)),
                  (uint8_t *)CONCAT22(uVar20,(uint8_t *)CONCAT11(uVar19,uVar18)),
                  CONCAT11(uVar23,uVar22),palbuf[0],(char)pfVar13,uVar18,uVar22);
  }
  else {
    damage = 0;
  }
  if ((*(uint *)((int)&(((entity_t *)in_stack_00000004->entity)->base).frames + 1) & 2) != 0) {
    TextBlitY = 0x68;
    TextBlitX = 0x87;
    ovr_blitLabel((char *)CONCAT13((char)(Font02.ofs >> 8),CONCAT12((char)Font02.ofs,0x2410)),
                  (uint8_t *)CONCAT22(0xde,Font02.seg),224,palbuf[0],0x86,(char)Font02.seg,0xe0);
  }
  if (GameRunning != false) {
    (*(uint8_t *)((uint8_t *)&(palette.seg))) = palbuf[0];
    palette.ofs = cmap.ofs;
    (*(uint8_t *)((uint8_t *)&(palette.seg) + 1)) = palbuf[1];
    ovr_setSeasonPalette(palette,(*(uint16_t *)((uint8_t *)&(agnt) + 2)));
  }
  return;
}



/* 6386:12b7 */

/* Formats the ready/not-ready line for an agent. */

char * __cdecl16far stats_readyStatusText(byte agntIndex,char *text)

{
  undefined4 uVar1;
  uint8_t *puVar2;
  char *pcVar3;
  byte in_stack_00000004;
  undefined1 in_stack_00000007;
  
  uVar1 = *(undefined4 *)((uint)in_stack_00000004 * 0x34 + 0x17);
  if ((*(byte *)((int)uVar1 + 0x33) & 1) == 0) {
    pcVar3 = (char *)((int)&AgntAnms[0x75].halfWidth + 1);
    puVar2 = ovr_ovc15_usesStshRealloc();
    pcVar3 = ovr_stsprintf((char *)CONCAT22(0x638d,(char *)text),
                           (char *)CONCAT22(puVar2,(char *)"puppetmaker" + 3),pcVar3,_agntIndex);
  }
  else {
    pcVar3 = (char *)((int)&AgntAnms[0x75].halfWidth + 1);
    puVar2 = ovr_ovc15_usesStshRealloc();
    pcVar3 = ovr_stsprintf((char *)CONCAT22(0x63a2,(char *)text),
                           (char *)CONCAT22(puVar2,(char *)"puppetmaker" + 3),pcVar3,_agntIndex);
  }
  return pcVar3;
}



/* 6386:1353 */

/* [R6] touches EntityCount, Entities */

void __cdecl16far stats_usesEntityCount(char partyIndex)

{
  byte *pbVar1;
  uint uVar2;
  undefined2 uVar3;
  
  for (uVar2 = 0; uVar2 < EntityCount; uVar2 = uVar2 + 1) {
    uVar3 = (undefined2)((ulong)Entities >> 0x10);
    if (*(char *)((int)&((entity_t *)Entities)[uVar2].base.entity + 3) == partyIndex) {
      pbVar1 = (byte *)((int)&((entity_t *)Entities)[uVar2].base.flags32 + 1);
      *pbVar1 = *pbVar1 & 0xfb;
    }
  }
  return;
}



/* 6386:13a1 */

/* WARNING: Variable defined which should be unmapped: text */
/* Formats the "%s is no longer ready." notice and ready-list hint. */

void __cdecl16far stats_unreadyNotice(byte agnt_id)

{
  byte *pbVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  uint8_t *puVar5;
  char *pcVar6;
  char *pcVar7;
  char *unaff_SS;
  uint8_t text;
  char *pcStack_d4;
  uint8_t msg;
  uint8_t unitFlags;
  undefined2 uStack_4;
  
  uVar2 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x17);
  uVar4 = _text;
  pcStack_d4 = (char *)(CONCAT22(_text,(uint)*(byte *)((int)uVar2 + 0x33)) ^ 1);
  uVar2 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x17);
  *(undefined1 *)((int)uVar2 + 0x33) = (char)pcStack_d4;
  uVar2 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x17);
  if ((*(byte *)((int)uVar2 + 0x33) & 1) == 0) {
    uVar2 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x17);
    pbVar1 = (byte *)((int)uVar2 + 0x33);
    *pbVar1 = *pbVar1 & 0xfb;
  }
  else {
    uVar2 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x17);
    _text = uVar4;
    stats_usesEntityCount(*(char *)((int)uVar2 + 0x1a));
    uVar2 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x17);
    pbVar1 = (byte *)((int)uVar2 + 0x33);
    *pbVar1 = *pbVar1 | 4;
    uStack_4 = *(undefined2 *)((uint)agnt_id * 0x34 + 0x1b);
    pcStack_d4 = (char *)CONCAT22(_text,unaff_SS);
    ovr_attact_usesEntities();
  }
  uVar2 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x17);
  uVar3 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x17);
  *(byte *)((int)uVar3 + 0x33) = *(byte *)((int)uVar2 + 0x33) & 0xfd;
  pcStack_d4 = (char *)((ulong)pcStack_d4 & 0xffff0000);
  drawAgntStats();
  pcVar7 = (char *)((int)&AgntAnms[0x75].halfWidth + 1);
  uVar2 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x17);
  if ((*(byte *)((int)uVar2 + 0x33) & 1) == 0) {
    pcVar7 = (char *)((int)&AgntAnms[0x75].halfWidth + 1);
    puVar5 = ovr_ovc15_usesStshRealloc();
    ovr_stsprintf((char *)CONCAT22(0x63b1,unaff_SS),
                  (char *)CONCAT22(puVar5,(char *)"puppetmaker" + 3),pcVar7,&msg);
    pcStack_d4 = (char *)CONCAT22(_text,pcVar7);
    drawString();
  }
  else {
    pcStack_d4 = (char *)CONCAT22(_text,unaff_SS);
    pcVar6 = stats_readyStatusText((byte)&text,pcStack_d4);
    ovr_stsprintf((char *)CONCAT22(0x63c8,unaff_SS),
                  (char *)CONCAT22(pcVar6,(char *)"puppetmaker" + 3),pcVar7,&msg);
    pcStack_d4 = (char *)CONCAT22(_text,pcVar7);
    drawString();
  }
  return;
}



/* 6386:1572 */

/* [R4] calls ovr_alignUp4 */

uint __cdecl16far stats_usesAlignUp4(int entityIndex)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  entity_t *peVar4;
  int unaff_SI;
  undefined2 uVar5;
  
  uVar5 = (undefined2)((ulong)Entities >> 0x10);
  if ((*(byte *)((int)&((entity_t *)Entities)[entityIndex].base.flags32 + 1) & 2) == 0) {
    uVar2 = 0;
  }
  else {
    uVar1 = ovr_alignUp4(unaff_SI,(((entity_t *)Entities + entityIndex)->base).x);
    uVar2 = ovr_alignUp4(uVar1,GfxRndSeed);
    if (uVar1 == uVar2) {
      uVar5 = (undefined2)((ulong)Entities >> 0x10);
      uVar2 = ((entity_t *)Entities)[entityIndex].base.y;
      if (uVar2 == GfxRndSeed2) {
        uVar1 = ovr_alignUp4(unaff_SI,((entity_t *)Entities)[entityIndex].base.targetX);
        uVar2 = ovr_alignUp4(uVar1,GfxRndSeed);
        if (uVar1 == uVar2) {
          uVar5 = (undefined2)((ulong)Entities >> 0x10);
          peVar4 = (entity_t *)Entities;
          uVar2 = peVar4[entityIndex].base.targetY;
          if (uVar2 == GfxRndSeed2) {
            if (peVar4[entityIndex].base.destX == 0) {
              bVar3 = (byte)((uint)(entityIndex * 0x37) >> 8);
              if (peVar4[entityIndex].base.destY == 0) {
                uVar2 = CONCAT11(bVar3,1);
              }
              else {
                uVar2 = (uint)bVar3 << 8;
              }
            }
            else {
              uVar2 = entityIndex * 0x37 & 0xff00;
            }
          }
          else {
            uVar2 = uVar2 & 0xff00;
          }
        }
        else {
          uVar2 = uVar2 & 0xff00;
        }
      }
      else {
        uVar2 = uVar2 & 0xff00;
      }
    }
    else {
      uVar2 = uVar2 & 0xff00;
    }
  }
  return uVar2;
}



/* 6386:16a2 */

/* WARNING: Variable defined which should be unmapped: msg */
/* Sets the agent's entity position to the cursor cell and reports the new base. */

void __cdecl16far stats_setAgentBase(byte agntIndex)

{
  byte *pbVar1;
  int iVar2;
  uint16_t uVar3;
  uint8_t *puVar4;
  char *arg1;
  undefined2 uVar5;
  char *unaff_SS;
  uint8_t msg;
  undefined2 uStack_c;
  undefined2 uStack_a;
  uint8_t unitFlags;
  
  iVar2 = *(int *)((uint)agntIndex * 0x34 + 0x1b);
  uStack_a = *(undefined2 *)((uint)agntIndex * 0x34 + 0x1f);
  uStack_c = *(undefined2 *)((uint)agntIndex * 0x34 + 0x1d);
  uVar3 = ovr_ovc23_compute2();
  (((entity_t *)Entities + iVar2)->base).x = uVar3;
  ((entity_t *)Entities)[iVar2].base.y = GfxRndSeed2;
  uVar5 = (undefined2)((ulong)Entities >> 0x10);
  ((entity_t *)Entities)[iVar2].base.targetX = (((entity_t *)Entities + iVar2)->base).x;
  ((entity_t *)Entities)[iVar2].base.targetY = GfxRndSeed2;
  pbVar1 = (byte *)((int)&((entity_t *)Entities)[iVar2].base.flags32 + 1);
  *pbVar1 = *pbVar1 | 2;
  arg1 = (char *)"puppetmaker" + 3;
  pbVar1 = (byte *)((int)&((entity_t *)Entities)[iVar2].base.flags32 + 1);
  *pbVar1 = *pbVar1 & 0xfa;
  ovr_attact_usesEntities();
  ovr_alignUp4();
  puVar4 = ovr_ovc15_usesStshRealloc();
  ovr_stsprintf((char *)CONCAT22(0x6406,unaff_SS),(char *)CONCAT22(puVar4,(char *)"puppetmaker" + 3)
                ,arg1,&msg);
  drawString();
  drawAgntStats();
  return;
}



/* 6386:1837 */

/* WARNING: Variable defined which should be unmapped: msg */
/* Formats the "%s can now be called away from home." notice. */

void __cdecl16far stats_calledAwayNotice(byte agntIndex)

{
  byte *pbVar1;
  int iVar2;
  uint16_t uVar3;
  uint8_t *puVar4;
  char *arg1;
  undefined2 uVar5;
  char *unaff_SS;
  uint8_t msg;
  undefined2 uStack_c;
  undefined2 uStack_a;
  uint8_t unitFlags;
  
  iVar2 = *(int *)((uint)agntIndex * 0x34 + 0x1b);
  uStack_a = *(undefined2 *)((uint)agntIndex * 0x34 + 0x1f);
  uStack_c = *(undefined2 *)((uint)agntIndex * 0x34 + 0x1d);
  uVar3 = ovr_ovc23_compute2();
  (((entity_t *)Entities + iVar2)->base).x = uVar3;
  ((entity_t *)Entities)[iVar2].base.y = GfxRndSeed2;
  uVar5 = (undefined2)((ulong)Entities >> 0x10);
  ((entity_t *)Entities)[iVar2].base.targetX = (((entity_t *)Entities + iVar2)->base).x;
  ((entity_t *)Entities)[iVar2].base.targetY = GfxRndSeed2;
  arg1 = (char *)"puppetmaker" + 3;
  pbVar1 = (byte *)((int)&((entity_t *)Entities)[iVar2].base.flags32 + 1);
  *pbVar1 = *pbVar1 & 0xfd;
  ovr_attact_usesEntities();
  puVar4 = ovr_ovc15_usesStshRealloc();
  ovr_stsprintf((char *)CONCAT22(0x644e,unaff_SS),(char *)CONCAT22(puVar4,(char *)"puppetmaker" + 3)
                ,arg1,&msg);
  drawString();
  drawAgntStats();
  return;
}



/* 6386:1997 */

/* Returns the agent whose owner index is the next larger one after the given agent's, or 0xff. */

undefined1 __cdecl16far stats_nextAgentByOwner(byte agntIndex)

{
  int iVar1;
  uint uVar2;
  undefined1 uStack_3;
  
  uStack_3 = 0xff;
  uVar2 = 0x7fff;
  for (iVar1 = 0; iVar1 < (int)(uint)AgntCount; iVar1 = iVar1 + 1) {
    if ((*(uint *)((uint)agntIndex * 0x34 + 0x1b) < *(uint *)(iVar1 * 0x34 + 0x1b)) &&
       (*(uint *)(iVar1 * 0x34 + 0x1b) < uVar2)) {
      uVar2 = *(uint *)(iVar1 * 0x34 + 0x1b);
      uStack_3 = (undefined1)iVar1;
    }
  }
  return uStack_3;
}



/* 6386:1a19 */

/* Returns the agent whose owner index is the next smaller one before the given agent's, or 0xff. */

undefined1 __cdecl16far stats_prevAgentByOwner(byte agntIndex)

{
  int iVar1;
  int iVar2;
  undefined1 uStack_3;
  
  uStack_3 = 0xff;
  iVar2 = -1;
  for (iVar1 = 0; iVar1 < (int)(uint)AgntCount; iVar1 = iVar1 + 1) {
    if ((*(uint *)(iVar1 * 0x34 + 0x1b) < *(uint *)((uint)agntIndex * 0x34 + 0x1b)) &&
       (iVar2 < *(int *)(iVar1 * 0x34 + 0x1b))) {
      iVar2 = *(int *)(iVar1 * 0x34 + 0x1b);
      uStack_3 = (undefined1)iVar1;
    }
  }
  return uStack_3;
}



/* 6386:1a9b */

/* [R7] body shape: compute */

void __cdecl16far stats_compute5(byte agntIndex)

{
  int unaff_BP;
  
  ovr_ovc15_usesStExit(unaff_BP,*(undefined2 *)((uint)agntIndex * 0x34 + 0x1b));
  return;
}



/* 6386:1abe */

/* Opens the agent detail page: ScreenMode 2, drawAgntStats and the detail text. */

void __cdecl16far stats_openAgentDetail(int agntIndex)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint unaff_SI;
  
  iVar2 = *(int *)(agntIndex * 0x34 + 0x1b);
  ovr_manage_openTalkWindow();
  ScreenMode = 2;
  drawAgntStats((agnt_t *)0x1726,far_from_u32((uint32_t)((ulong)unaff_SI << 0x10)),agntIndex * 0x34);
  drawString();
  bVar1 = ((entity_t *)Entities)[iVar2].base.gindex;
  if (*(char *)((int)(char **)GMenuStrings + (uint)bVar1 * 0x95 + 0x1f) == '\0') {
    if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar1 * 0x95) == '\0') ||
       (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar1 * 0x95) == '\x04')) {
      CurMusicType = 0x43;
    }
    else if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar1 * 0x95) == '\x02') {
      CurMusicType = 0x42;
    }
    else if ((*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar1 * 0x95) == '\x05') ||
            (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar1 * 0x95) == '\x01')) {
      CurMusicType = 0x27;
    }
    else if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar1 * 0x95) == '\x06') {
      CurMusicType = 0x28;
    }
    else if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar1 * 0x95) == '\x03') {
      CurMusicType = 0x20;
    }
    else {
      CurMusicType = 0xc;
    }
  }
  else if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)bVar1 * 0x95) & 8) == 0) {
    CurMusicType = 0x29;
  }
  else {
    CurMusicType = 0x59;
  }
  uVar3 = ovr_audio_isPlaying();
  if ((uVar3 & 0xff) == 0) {
    ovr_play_sfx();
  }
  return;
}



/* 6386:1c9f */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0006f700) overlaps instruction at (ram,0x0006f6ff)
    */
/* [R4] calls ovr_alignUp4 */

byte __cdecl16far
stats_usesAlignUp42(byte agntIndex,byte gfxIndex,int16_t x,int16_t y,brect_t *rect,uint16_t type)

{
  undefined4 uVar1;
  far_t gfx;
  far_t entries_00;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t dst;
  far_t dst_00;
  far_t dst_01;
  far_t dst_02;
  far_t dst_03;
  char cVar2;
  byte bVar3;
  bool bVar4;
  byte bVar5;
  uint uVar6;
  char *pcVar7;
  ulong *puVar8;
  uint uVar9;
  uint8_t *puVar10;
  uint16_t uVar11;
  int *piVar12;
  undefined2 *puVar13;
  int iVar14;
  undefined2 unaff_DI;
  undefined2 uVar15;
  undefined2 uVar16;
  uint16_t unaff_SS;
  undefined1 uVar17;
  undefined1 uVar18;
  undefined1 uVar19;
  uint8_t entries;
  undefined2 uStack_36;
  undefined2 uStack_34;
  undefined2 uStack_32;
  undefined2 uStack_30;
  undefined2 uStack_2e;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined2 uStack_28;
  undefined2 uStack_26;
  uint8_t permTable;
  undefined1 uStack_10;
  undefined1 uStack_f;
  undefined1 uStack_e;
  undefined1 uStack_d;
  undefined1 uStack_c;
  char cStack_6;
  char cStack_5;
  byte bStack_4;
  byte bStack_3;
  
  bVar5 = (byte)unaff_DI;
  uVar19 = (undefined1)((uint)unaff_DI >> 8);
  if (AgntCount <= agntIndex) {
    return AgntCount;
  }
  gfx_00.seg = 0xc31d;
  gfx_00.ofs = FontHandle.seg;
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = bVar5;
  dst.ofs = 0xa000;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = uVar19;
  ovr_blitLoadRleGfx(gfx_00,dst,FontHandle.ofs,0);
  Cancelled = 0;
  ovr_attact_usesAgntFlag1();
  ovr_draw_freeRingBuffers();
  ovr_stop_audio();
  savedMenuItem = GMenuItem;
  MenuModeSaved = MenuMode;
  CurMusicType = 0xff;
L_stats_6386_1c9f_1E1D:
  for (; GCharLevelsInc != '\0'; GCharLevelsInc = GCharLevelsInc + -1) {
    uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + 0x1d);
    bStack_3 = *(byte *)((int)uVar1 + 0x46);
    if (bStack_3 == 0xff) {
      bStack_3 = 0;
    }
    uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + 0x17);
    piVar12 = (int *)((uint)bStack_3 * 0x94 + (uint)*(byte *)((int)uVar1 + 0xf) * 4);
    if (*piVar12 != 0 || piVar12[1] != 0) {
      uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + 0x17);
      puVar13 = (undefined2 *)((uint)bStack_3 * 0x94 + (uint)*(byte *)((int)uVar1 + 0xf) * 4);
      uVar16 = *puVar13;
      uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + 0x17);
      uVar15 = (undefined2)((ulong)uVar1 >> 0x10);
      iVar14 = (int)uVar1;
      *(undefined2 *)(iVar14 + 0x12) = puVar13[1];
      *(undefined2 *)(iVar14 + 0x10) = uVar16;
      ovr_ovc41_compute3(CONCAT13(uVar19,CONCAT12(bVar5,*(undefined2 *)
                                                         ((uint)agntIndex * 0x34 + 0x19))),
                         *(undefined2 *)((uint)agntIndex * 0x34 + 0x17));
    }
  }
  iVar14 = *(int *)((uint)agntIndex * 0x34 + 0x1b);
  stats_openAgentDetail((uint)agntIndex);
  uVar16 = (undefined2)((ulong)Entities >> 0x10);
  if (((entity_t *)Entities)[iVar14].base.targetY == GfxRndSeed2) {
    uVar6 = ovr_alignUp4(CONCAT11(uVar19,bVar5),(char)((entity_t *)Entities)[iVar14].base.targetX);
    uVar17 = (undefined1)uVar6;
    uVar18 = (undefined1)(uVar6 >> 8);
    uVar6 = ovr_alignUp4(uVar6,GfxRndSeed);
    if (CONCAT11(uVar18,uVar17) == uVar6) {
      uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + 0x17);
      ovr_ovc39_textHalflingCastle(bVar5,*(undefined1 *)((int)uVar1 + 0x1a));
    }
  }
L_stats_6386_1c9f_1ECD:
  cVar2 = stats_prevAgentByOwner(agntIndex);
  if (cVar2 == -1) {
    uStack_36 = 0;
    _entries = 0;
  }
  else {
    uStack_36 = 0x2410;
    _entries = 0x6473;
  }
  uStack_10 = 4;
  cVar2 = stats_nextAgentByOwner(agntIndex);
  if (cVar2 == -1) {
    uStack_32 = 0;
    uStack_34 = 0;
  }
  else {
    uStack_32 = 0x2410;
    uStack_34 = 0x647c;
  }
  uStack_f = 5;
  uStack_e = 7;
  uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + 0x17);
  if (*(char *)((int)uVar1 + 0x1a) == -1) {
    uStack_2e = 0;
    uStack_30 = 0;
  }
  else {
    uStack_2e = 0x2410;
    uStack_30 = 0x6481;
  }
  uStack_d = 9;
  uStack_2a = 0x2410;
  uStack_2c = 0x6488;
  uStack_c = 6;
  uStack_26 = 0x2410;
  uStack_28 = 0x6401;
  puVar10 = (uint8_t *)((int)&AgntAnms[0x75].halfWidth + 1);
  if (*(char *)*(undefined4 *)((uint)agntIndex * 0x34 + 0x1d) == '\0') {
    menuBarShown = 1;
  }
  entries_00.seg = 5;
  entries_00.ofs = unaff_SS;
  pcVar7 = ovr_uiInputText(entries_00,0,far_from_u32((uint32_t)(0x0)),bVar5,&entries,0);
  bStack_4 = (byte)pcVar7;
  menuBarShown = 0;
  if ((bStack_4 != 0) && (bStack_4 < 10)) {
    puVar10 = &permTable;
    bStack_4 = puVar10[(uint)pcVar7 & 0xff];
  }
  cStack_5 = '\0';
  cStack_6 = '\0';
  uVar6 = (uint)bStack_4;
  if (uVar6 == 6) {
    cStack_6 = '\x01';
    cStack_5 = '\x01';
  }
  else if (uVar6 < 7) {
    uVar9 = 5;
    switch(uVar6) {
    case 0:
      menuBarShown = 0;
      uVar6 = 5;
      Agnts[5].x = 0x2b;
      Agnts[5].y = 2;
      do {
        bStack_3 = 1;
        while( true ) {
          uVar6 = uVar6 + 1;
          uVar9 = (uint)AgntCount;
          if ((int)uVar9 <= (int)uVar6) {
            ovr_agnt_usesAlignToSeg();
            bVar5 = (byte)uVar9;
            ovr_agnt_usesAlignToSeg();
            ovr_agnt_usesAlignToSeg();
            ovr_agnt_usesAlignToSeg();
            return bVar5;
          }
          uVar1 = *(undefined4 *)(uVar6 * 0x34 + 0x1d);
          uVar9 = uVar6;
          if (*(char *)((int)uVar1 + 1) == '\x02') break;
          uVar1 = *(undefined4 *)(uVar6 * 0x34 + 0x1d);
          if (*(char *)((int)uVar1 + 1) == '\x01') {
            *(undefined2 *)(uVar6 * 0x34) = 0x3d;
            *(undefined2 *)(uVar6 * 0x34 + 2) = 0x12;
          }
          else {
            uVar1 = *(undefined4 *)(uVar6 * 0x34 + 0x1d);
            if (*(char *)((int)uVar1 + 1) == '\v') {
              *(undefined2 *)(uVar6 * 0x34) = 0x56;
              *(undefined2 *)(uVar6 * 0x34 + 2) = 0x14;
            }
          }
        }
switchD_6000_58bf_caseD_5:
        *(undefined2 *)(uVar6 * 0x34) = 0x6e;
        *(undefined2 *)(uVar9 * 0x34 + 2) = 0xb;
        uVar6 = uVar9;
      } while( true );
    case 1:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 2:
      uVar16 = (undefined2)
               ((ulong)*(undefined4 *)((undefined *)&GfxFramePtrs + (uint)gfxIndex * 4) >> 0x10);
      iVar14 = (int)*(undefined4 *)((undefined *)&GfxFramePtrs + (uint)gfxIndex * 4) +
               (uint)bStack_3 * 4;
                    /* WARNING: Load size is inaccurate */
      gfx.seg = x;
      gfx.ofs = *(uint16_t *)(iVar14 + 2);
      ovr_blitGfxRect(gfx,y,(int16_t)rect,(brect_t *)(ulong)CONCAT12(0x10,type),bVar5,
                      *(bool *)iVar14,0x10);
      (*(uint8_t *)((uint8_t *)&(AnimSeqPtr[0].seg))) = bStack_3 + 1;
      GAnimPlaying = 1;
      return bStack_3 + 1;
    case 3:
      uVar17 = 0x10;
      uVar18 = 0x24;
      bStack_3 = '\0';
      do {
        bVar4 = ovr_draw_textProvidesMoreHousing();
      } while (bVar4);
      while( true ) {
        uVar11 = *(uint16_t *)BDA_DailyTimeCounter;
        if ((*(uint16_t *)(BDA_DailyTimeCounter.ofs + 2) != InputEventTime.hi) ||
           (uVar11 != InputEventTime.lo)) {
          InputEventTime.hi = *(uint16_t *)(BDA_DailyTimeCounter.ofs + 2);
          uVar11 = *(uint16_t *)BDA_DailyTimeCounter;
          InputEventTime.lo = uVar11;
          ovr_draw_usesPrintf();
        }
        bStack_4 = ovr_draw_textProvidesMoreHousing();
        if ((bool)bStack_4) break;
        puVar8 = ovr_attact_usesBDADailyTimeCounter
                           ((*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)),
                            CONCAT13(uVar19,CONCAT12(bVar5,CONCAT11(uVar18,uVar17))),
                            (undefined2)TextBlitCycle,uVar17);
        if ((uVar11 != 0) || ((ulong *)(uint)agntIndex <= puVar8)) break;
      }
      if (bStack_3 != '\0') {
        ovr_miceRestoreArea((brect_t *)CONCAT13(uVar18,CONCAT12(uVar17,0x2410)),0x44a);
      }
      return bStack_4;
    case 4:
      in(puVar10);
      ovr_draw_freeRingBuffers();
      ovr_stop_audio();
      savedMenuItem = GMenuItem;
      MenuModeSaved = MenuMode;
      gfx_01.seg = 0xe249;
      gfx_01.ofs = nwpanel1Cut2Seg;
      (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = bVar5;
      dst_00.ofs = 0xa000;
      (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = uVar19;
      ovr_blitLoadRleGfx(gfx_01,dst_00,nwpanel1Cut2Ofs,0);
      gfx_02.seg = 0xe249;
      gfx_02.ofs = trianglsCut6Seg;
      (*(uint8_t *)((uint8_t *)&(dst_01.seg))) = bVar5;
      dst_01.ofs = 0xa000;
      (*(uint8_t *)((uint8_t *)&(dst_01.seg) + 1)) = uVar19;
      ovr_blitLoadRleGfx(gfx_02,dst_01,trianglsCut6Ofs,0);
      ovr_uiMainMenuLoop();
      gfx_03.seg = 0xe249;
      gfx_03.ofs = nwpanel1Cut2Seg;
      (*(uint8_t *)((uint8_t *)&(dst_02.seg))) = bVar5;
      dst_02.ofs = 0xa000;
      (*(uint8_t *)((uint8_t *)&(dst_02.seg) + 1)) = uVar19;
      ovr_blitLoadRleGfx(gfx_03,dst_02,nwpanel1Cut2Ofs,0);
      bVar3 = 0x10;
      gfx_04.seg = 0xe249;
      gfx_04.ofs = trianglsCut5Seg;
      (*(uint8_t *)((uint8_t *)&(dst_03.seg))) = bVar5;
      dst_03.ofs = 0xa000;
      (*(uint8_t *)((uint8_t *)&(dst_03.seg) + 1)) = uVar19;
      ovr_blitLoadRleGfx(gfx_04,dst_03,trianglsCut5Ofs,0);
      ovc41_usesGMenuItem();
      return bVar3;
    case 5:
      goto switchD_6000_58bf_caseD_5;
    }
  }
  else if (uVar6 == 0xfc) {
    uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + 0x17);
    if ((*(byte *)((int)uVar1 + 0x33) & 1) == 0) {
      stats_unreadyNotice(agntIndex);
    }
  }
  else if (uVar6 < 0xfd) {
    if (uVar6 == 7) {
      uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + 0x17);
      if (*(char *)((int)uVar1 + 0x1a) != -1) {
        ovr_stop_audio();
        CurMusicType = 0xff;
        uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + 0x17);
        ovr_manage_settlementScreen(bVar5,*(undefined1 *)((int)uVar1 + 0x1a));
        if (Cancelled == 0) {
          iVar14 = *(int *)((uint)agntIndex * 0x34 + 0x1b);
          stats_openAgentDetail((uint)agntIndex);
          uVar16 = (undefined2)((ulong)Entities >> 0x10);
          if (((entity_t *)Entities)[iVar14].base.targetY == GfxRndSeed2) {
            uVar6 = ovr_alignUp4(CONCAT11(uVar19,bVar5),
                                 (char)((entity_t *)Entities)[iVar14].base.targetX);
            uVar17 = (undefined1)uVar6;
            uVar18 = (undefined1)(uVar6 >> 8);
            uVar6 = ovr_alignUp4(uVar6,GfxRndSeed);
            if (CONCAT11(uVar18,uVar17) == uVar6) {
              uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + 0x17);
              ovr_ovc39_textHalflingCastle(bVar5,*(undefined1 *)((int)uVar1 + 0x1a));
            }
          }
        }
        else {
          cStack_5 = '\x01';
        }
      }
    }
    else {
      if (uVar6 == 8) goto L_stats_6386_1c9f_20C5;
      if (uVar6 == 9) {
        ovr_ovc50_usesUiInputText();
        cStack_6 = '\x01';
      }
    }
  }
  else if (uVar6 == 0xfd) {
L_stats_6386_1c9f_20C5:
    uVar6 = stats_usesAlignUp4(*(int *)((uint)agntIndex * 0x34 + 0x1b));
    if ((uVar6 & 0xff) == 0) {
      stats_setAgentBase(agntIndex);
    }
  }
  else if (uVar6 == 0xfe) {
    uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + 0x17);
    if ((*(byte *)((int)uVar1 + 0x33) & 1) != 0) {
      stats_unreadyNotice(agntIndex);
    }
    uVar6 = stats_usesAlignUp4(*(int *)((uint)agntIndex * 0x34 + 0x1b));
    if ((char)uVar6 != '\0') {
      stats_calledAwayNotice(agntIndex);
    }
  }
  if ((cStack_5 != '\0') || (cStack_6 != '\0')) goto L_stats_6386_1c9f_22C8;
  goto L_stats_6386_1c9f_1ECD;
L_stats_6386_1c9f_22C8:
  if (cStack_5 != '\0') {
    if (Cancelled != 0) {
      return Cancelled;
    }
    bVar5 = Cancelled;
    stats_openCastlePanel();
    ovr_ovc41_usesGMenuItem();
    return bVar5;
  }
  goto L_stats_6386_1c9f_1E1D;
}



/* 6386:22fd */

/* Opens the stats page for the agent under the screen point (video_findAgentAt) and returns whether
   one was hit. */

bool __cdecl16far stats_selectAgentAt(uint16_t x,uint16_t y,...)

{
  int iVar1;
  int16_t unaff_BP;
  int16_t in_stack_00000000;
  brect_t *in_stack_00000002;
  uint16_t in_stack_00000004;
  
  iVar1 = video_findAgentAt(in_stack_00000004,x);
  if (iVar1 != -1) {
    stats_usesAlignUp42((byte)iVar1,(byte)iVar1,unaff_BP,in_stack_00000000,in_stack_00000002,
                        in_stack_00000004);
  }
  return iVar1 != -1;
}



/* 6386:232d */

/* WARNING: Variable defined which should be unmapped: palette */
/* Opens the castle status panel with its palette and five menu bars. */

void __cdecl16far stats_openCastlePanel(void)

{
  far_t gfx;
  far_t gfx_00;
  far_t ptr;
  far_t handle;
  far_t handle_00;
  uint8_t *in_DX;
  uint unaff_SI;
  uint16_t dstSeg;
  brect_t *unaff_SS;
  undefined1 type;
  undefined1 uVar1;
  uint8_t palette;
  stg_tmp_t *psStack_14;
  uint8_t dst;
  uint uStack_e;
  uint uStack_c;
  uint uStack_a;
  void *pvStack_6;
  uint8_t *puStack_4;
  
  type = (undefined1)unaff_SI;
  uVar1 = (undefined1)(unaff_SI >> 8);
  MiceNeedsUpdate = 1;
  pvStack_6 = ovr_stshAlloc((ulong)unaff_SI << 0x10,0xfa0f);
  (*(uint8_t *)((uint8_t *)&(ptr.seg))) = type;
  ptr.ofs = (uint16_t)in_DX;
  (*(uint8_t *)((uint8_t *)&(ptr.seg) + 1)) = uVar1;
  puStack_4 = in_DX;
  ovr_alignToSeg(ptr,pvStack_6);
  uStack_e = 7;
  uStack_a = 0xc2;
  _dst = 8;
  uStack_c = 0xe2;
  ovr_driver_fillRect(7,0xe2,0xc2,0,(uint8_t)in_DX,8);
  gfx_00.seg = 0;
  gfx_00.ofs = fullScreenGfxSeg;
  ovr_blitGfx10(gfx_00,0,(uint16_t)&dst,(brect_t *)ZEXT24(unaff_SS),(bool)type,fullScreenGfxOfs,0);
  gfx.seg = 0;
  gfx.ofs = nwpanel2Cut1Seg;
  ovr_blitGfxRect(gfx,0,(int16_t)&dst,(brect_t *)CONCAT22(0x10,unaff_SS),0x0,(bool)type,
                  nwpanel2Cut1Ofs,0);
  (*(uint8_t *)((uint8_t *)&(handle.seg))) = type;
  handle.ofs = Lbm_nwpanel1.seg;
  (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = uVar1;
  psStack_14 = ovr_stshLoadGfx(handle,Lbm_nwpanel1.ofs);
  ovr_calcSeasonPalette((uint8_t *)CONCAT22(&palette,in_DX),(uint16_t)psStack_14);
  ovr_driver_fillRect(uStack_e,uStack_c,uStack_a,0,0x0,_dst);
  ovr_vgaSetPalette8bit((uint8_t *)CONCAT13(uVar1,CONCAT12(type,unaff_SS)),&palette);
  ovr_blitRect((brect_t *)CONCAT13(uVar1,CONCAT12(type,unaff_SS)),&dst);
  TextBlitDstSeg = 0xa000;
  ovr_ovc28_textHalflingCastle();
  for (dstSeg = 0; (int)dstSeg < 5; dstSeg = dstSeg + 1) {
    ovr_draw_usesBlitLoadRleGfx3(CONCAT11(uVar1,type),(char)dstSeg);
    ovr_draw_menuRowBar(-0x6000,dstSeg);
  }
  mapViewActive = 0xff;
  ovr_attact_usesLDIV_at_2();
  (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = type;
  handle_00.ofs = (uint16_t)puStack_4;
  (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = uVar1;
  ovr_stshFree(handle_00,pvStack_6);
  ovr_stop_audio();
  CurMusicType = 0xff;
  ScreenMode = 0;
  return;
}



/* 6386:24c2 */

void __cdecl16far drawString(char *text,uint16_t widths,...)

{
  uint uVar1;
  size_t sVar2;
  undefined1 unaff_SI;
  brect_t *unaff_SS;
  int in_stack_00000004;
  far_t gfx;
  uint8_t rect;
  uint16_t uStack_a;
  undefined2 uStack_8;
  undefined2 uStack_6;
  
  memcpy((char *)CONCAT22(unaff_SS,&rect),(char *)(BlitRects + 1),10);
  if (ScreenMode == '\x01') {
    uStack_a = 0x9c;
    uStack_6 = 0xbe;
  }
  else {
    uStack_a = 0x75;
    if (GameRunning == false) {
      uStack_6 = 0xb2;
    }
    else {
      uStack_6 = 0x96;
    }
  }
  _rect = 0x13;
  uStack_8 = 0xd7;
  TextBlitFlag = 1;
  TextBlitDstSeg = 0xa000;
  gfx.seg = 0;
  gfx.ofs = talkwin9Cut4Seg;
  ovr_blitGfxRect(gfx,0,(int16_t)&rect,(brect_t *)CONCAT22(0x10,unaff_SS),0x0,(bool)unaff_SI,
                  talkwin9Cut4Ofs,0);
  TextBlitY = uStack_a;
  while( true ) {
    TextBlitX = 0x13;
    uVar1 = ovr_blitText();
    sVar2 = strlen((char *)CONCAT13((char)((ulong)text >> 8),CONCAT12((char)text,in_stack_00000004))
                  );
    if (sVar2 <= uVar1) break;
    in_stack_00000004 = in_stack_00000004 + uVar1;
    TextBlitY = TextBlitY + 0xb;
  }
  ovr_clean_ring_buffer();
  return;
}


