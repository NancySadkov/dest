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
  far_t gfx_00;
  
  gfx_00.seg = fullScreenGfxSeg;
  gfx_00.ofs = fullScreenGfxOfs;
  ovr_blitGfx10(gfx_00,0,0,(brect_t *)0x24105ce5,false);
  gfx.seg = nwpanel1Cut3Seg;
  gfx.ofs = nwpanel1Cut3Ofs;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)(0xa0000adf)));
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
  far_t handle;
  far_t handle_00;
  stg_tmp_t *psVar1;
  uint16_t in_DX;
  agntG_t *paVar2;
  undefined2 uVar3;
  uint16_t in_stack_0000000c;
  far_t gfx;
  undefined1 uVar4;
  
  handle.seg = talkwin9Cut5Seg;
  handle.ofs = talkwin9Cut5Ofs;
  psVar1 = ovr_stshLoadGfx(handle);
  ovr_calcSeasonPalette(psVar1->cmap,in_DX,(uint8_t *)palette,in_stack_0000000c);
  uVar3 = (undefined2)((ulong)gdata >> 0x10);
  paVar2 = (agntG_t *)gdata;
  if (((paVar2->prts + portraitIndex)->ofs != 0 || paVar2->prts[portraitIndex].seg != 0) &&
     ((paVar2->prtpals + portraitIndex)->ofs != 0 || paVar2->prtpals[portraitIndex].seg != 0)) {
    handle_00.seg = paVar2->prtpals[portraitIndex].seg;
    handle_00.ofs = (paVar2->prtpals + portraitIndex)->ofs;
    psVar1 = ovr_stshLoadGfx(handle_00);
    uVar4 = (undefined1)(in_DX >> 8);
    memcpy((char *)CONCAT22(in_stack_0000000c,(char *)(palette + 3)),
           (char *)CONCAT13(uVar4,CONCAT12((char)in_DX,psVar1->cmap + 3)),0xed);
    memcpy((char *)CONCAT22(in_stack_0000000c,(char *)(palette + 0x1e0)),
           (char *)CONCAT13(uVar4,CONCAT12((char)in_DX,psVar1->cmap + 0x1e0)),0x90);
  }
  if (GameRunning == false) {
    ovr_vgaSetPalette8bit((uint8_t *)CONCAT22(in_stack_0000000c,palette));
  }
  if ((paVar2->prts + portraitIndex)->ofs != 0 || paVar2->prts[portraitIndex].seg != 0) {
    ovr_driver_fillRect(0xf,9,0x83,0x72,0xec,0xa000);
    gfx.seg = paVar2->prts[portraitIndex].seg;
    gfx.ofs = (paVar2->prts + portraitIndex)->ofs;
    ovr_blitGfxRect(gfx,16,10,(brect_t *)(BlitRects + 1),0x10,true);
  }
  return;
}



/* 6386:02db */

char * __cdecl16far agntCopyNthField(uint8_t filed_index,char *dst,char *src)

{
  bool bVar1;
  uint16_t len;
  uint16_t i;
  char *pcStack000a;
  undefined2 uStack000c;
  uint8_t j;
  uint8_t found;
  
  j = 0x0;
  bVar1 = false;
  i = 0;
  while( true ) {
    len = strlen(pcStack000a);
    if (len <= i) break;
    if (pcStack000a[i] == ',') {
      j = j + 0x1;
      if (bVar1) break;
    }
    else if (j == filed_index) {
      *_dst = pcStack000a[i];
      _dst = (char *)CONCAT22(src,dst + 1);
      bVar1 = true;
    }
    i = i + 1;
  }
  if (bVar1) {
    *_dst = '\0';
  }
  else {
    strcpy(dst,src);
  }
  return dst;
}



/* 6386:0367 */

char * __cdecl16far
agntGetWeaponName(char *dst,uint8_t atype,bool magical,uint8_t field_index,int32_t agent)

{
  uint16_t tofs;
  undefined1 in_stack_00000007;
  undefined2 in_stack_00000010;
  
  if (*(int *)((int)&AgntGs[0].wpn_name + (uint)magical * 0x95) == 0 &&
      *(int *)((int)&AgntGs[0].wpn_name + 2 + (uint)magical * 0x95) == 0) {
    if (field_index == 0x0) {
      strcpy(dst,_atype);
    }
    else {
      strcpy(dst,_atype);
    }
  }
  else if ((*(uint *)((int)*(undefined4 *)((*(uint16_t *)((uint8_t *)&(agent) + 2)) + 0x1d) + 0x40) & 0x4000) == 0) {
    agntCopyNthField((uint8_t)agent,dst,_atype);
  }
  else {
    strcpy(dst,_atype);
  }
  return dst;
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
  far_t *pfVar17;
  uint16_t uVar18;
  uint uVar19;
  byte *pbVar20;
  char *pcVar21;
  byte bVar25;
  far_t *in_CX;
  far_t *pfVar24;
  byte bVar26;
  byte bVar27;
  byte bVar28;
  int iVar29;
  uint8_t *in_DX;
  byte *pbVar30;
  int *piVar31;
  short (*pasVar32) [148];
  unit_t *puVar33;
  uint *puVar34;
  uint *puVar35;
  undefined1 *puVar37;
  char *unaff_BP;
  uint *puVar38;
  int iVar39;
  far_t *unaff_SI;
  byte *pbVar40;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 uVar41;
  undefined2 uVar42;
  char *unaff_SS;
  undefined2 uVar43;
  bool bVar44;
  byte in_AF;
  longdouble in_ST0;
  undefined4 uVar45;
  uint16_t in_stack_00000000;
  uint in_stack_00000002;
  uint8_t auStack_314 [72];
  char acStack_2cc [588];
  undefined1 auStack_80 [110];
  undefined2 uStack_12;
  int16_t iStack_10;
  byte in_stack_0000fff2;
  byte in_stack_0000fff4;
  short in_stack_0000fff6;
  undefined1 uVar46;
  char sfx;
  byte in_stack_0000fff8;
  undefined1 uVar47;
  undefined1 in_stack_0000fff9;
  undefined1 in_stack_0000fffa;
  char in_stack_0000fffb;
  undefined1 uVar48;
  undefined1 in_stack_0000fffc;
  char in_stack_0000fffd;
  uint uVar15;
  uint *puVar36;
  
  if ((uint8_t)term == '\x01') {
    if ((char)ringValue.seg == '\0') {
      strcpy(dst,(char *)src);
    }
    else if ('\0' < (char)ringValue.seg) {
      iStack_10 = 15536;
      ovr_stsprintf(dst,(char *)src,(char *)"+%d ring of prot.");
    }
                    /* WARNING: Read-only address (ram,0x0002c58a) is written */
    return (far_t *)dst;
  }
  bVar28 = (byte)ringValue.ofs - (char)ringValue.seg;
  (*(uint8_t *)((uint8_t *)&(ringValue.ofs))) = bVar28;
  if ((uint8_t)term == '\x03') {
    uVar19 = (int)(char)bVar28 - 6;
    if (4 < uVar19) {
      strcpy(dst,(char *)src);
      return (far_t *)dst;
    }
    cVar22 = '`';
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
          pfVar24 = in_CX;
          in_CX = (far_t *)((int)&pfVar24->ofs + 1);
          if (0xb < (int)in_CX) {
            return pfVar17;
          }
        } while (in_CX == unaff_SI);
        uVar11 = SUB21(in_CX,0);
        if ((far_t *)(uint)*(byte *)((int)&pfVar24[-0x1da8].ofs + 1) == unaff_SI) {
          if ((far_t *)(uint)(byte)(unaff_SI + -0x1da8)->ofs == unaff_SI) {
            *(undefined1 *)((int)&pfVar24[-0x1da8].ofs + 1) = uVar11;
          }
          else {
            *(undefined1 *)((int)&pfVar24[-0x1da8].ofs + 1) = (char)(unaff_SI + -0x1da8)->ofs;
          }
        }
        if ((far_t *)(uint)*(byte *)((int)&pfVar24[-0x1dab].ofs + 1) == unaff_SI) {
          if ((far_t *)(uint)(byte)(unaff_SI + -0x1dab)->ofs == unaff_SI) {
            *(undefined1 *)((int)&pfVar24[-0x1dab].ofs + 1) = uVar11;
          }
          else {
            *(undefined1 *)((int)&pfVar24[-0x1dab].ofs + 1) = (char)(unaff_SI + -0x1dab)->ofs;
          }
        }
        if ((far_t *)(uint)*(byte *)((int)&pfVar24[-0x1dae].ofs + 1) == unaff_SI) {
          if ((far_t *)(uint)(byte)(unaff_SI + -0x1dae)->ofs == unaff_SI) {
            *(undefined1 *)((int)&pfVar24[-0x1dae].ofs + 1) = uVar11;
          }
          else {
            *(undefined1 *)((int)&pfVar24[-0x1dae].ofs + 1) = (char)(unaff_SI + -0x1dae)->ofs;
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
          while( true ) {
            uVar18 = ovr_biosKeyAvail();
            if ((char)uVar18 == '\0') break;
            ovr_biosReadKey();
          }
          cVar22 = '\"';
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
      bVar12 = write_game_cfg(sfx,cVar22,cVar22);
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
      if (((uVar19 < term) && ((MouseY - 0x3c) % 0xe < 0xc)) &&
         (*(int *)(dst + uVar19 * 4) != 0 || *(int *)((int)(dst + uVar19 * 4) + 2) != 0)) {
        cVar22 = (char)uVar19;
        (*(uint8_t *)((uint8_t *)&(entries.seg))) = (char)src;
        entries.ofs = (uint16_t)dst;
        (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = (char)(src >> 8);
        ovc28_blitMenuEntry(entries,uVar19);
        GMenuItem = cVar22 + '\x01';
        return (far_t *)CONCAT11(0x24,cVar22 + '\x01');
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
    pbVar20 = (byte *)(int)(char)bVar28;
    if ((byte *)__C0_ASM_CopyRight + 4 < pbVar20) {
      strcpy(dst,(char *)src);
      return (far_t *)dst;
    }
    pasVar32 = (short (*) [148])((int)pbVar20 * 2);
    uVar42 = 0x6000;
    bVar10 = (byte)((uint)in_DX >> 8);
    switch(pbVar20) {
    case (byte *)0x0:
      ovr_vgaSetPalette8bit((uint8_t *)CONCAT22(unaff_BP,auStack_314));
      uVar11 = 0xa6;
      uVar48 = 0x22;
      ovr_blitRect((brect_t *)&iStack_10);
      TextBlitDstSeg = 0xa000;
      ovr_ovc28_textHalflingCastle();
      for (iVar29 = 0; iVar29 < 5; iVar29 = iVar29 + 1) {
        ovr_draw_usesBlitLoadRleGfx3(iVar29);
        uVar11 = 0xbb;
        uVar48 = 0x22;
        ovr_draw_menuRowBar(iVar29,0xa000);
      }
      mapViewActive = 0xff;
      uVar46 = 0xf6;
      uVar47 = 0x5c;
      ovr_attact_usesLDIV_at_2();
      (*(uint8_t *)((uint8_t *)&(handle_02.seg) + 1)) = uVar47;
      (*(uint8_t *)((uint8_t *)&(handle_02.seg))) = uVar46;
      (*(uint8_t *)((uint8_t *)&(handle_02.ofs) + 1)) = uVar48;
      (*(uint8_t *)((uint8_t *)&(handle_02.ofs))) = uVar11;
      ovr_stshFree(handle_02);
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
        uVar46 = SUB21(unaff_SS,0);
        uVar47 = (undefined1)((uint)unaff_SS >> 8);
        uVar11 = uVar46;
        uVar48 = uVar47;
        pcVar21 = (char *)ovr_ovc45_compute9((char *)CONCAT13(uVar47,CONCAT12(uVar46,auStack_80)),
                                             (char *)CONCAT13(in_stack_0000fffd,
                                                              CONCAT12(in_stack_0000fffc,
                                                                       CONCAT11(in_stack_0000fffb,
                                                                                in_stack_0000fffa) +
                                                                       1)),
                                             (char *)CONCAT22(in_stack_00000000,unaff_BP),
                                             in_stack_00000002,(char)dst);
        (*(uint8_t *)((uint8_t *)&(dst))) = (char)in_DX;
        (*(uint8_t *)((uint8_t *)&(dst) + 1)) = (undefined1)((uint)in_DX >> 8);
        ovr_blitLabel(pcVar21,in_DX,src,(uint8_t)term);
        ringValue.seg = (uint16_t)((char *)"puppetmaker" + 3);
        BlitLetterType = 0;
        pbVar20 = unaff_DI;
        while( true ) {
          while( true ) {
            unaff_DI = pbVar20 + 0xe;
            unaff_SI = (far_t *)((int)&unaff_SI->ofs + 1);
            if ((int)term <= (int)unaff_SI) {
              if (goldPartyIndex != 0xff) {
                ringValue.seg = CONCAT11((char)(ringValue.seg >> 8),goldPartyIndex);
                ringValue.ofs = 0x22c4;
                (*(uint8_t *)((uint8_t *)&(term))) = 0xad;
                (*(uint8_t *)((uint8_t *)&(term) + 1)) = 7;
                ovc28_drawGold(goldPartyIndex);
              }
              return (far_t *)ringValue.seg;
            }
            piVar31 = (int *)(CONCAT11((*(uint8_t *)((uint8_t *)&(dst) + 1)),(char)dst) + (int)unaff_SI * 4);
            if (*piVar31 != 0 || piVar31[1] != 0) break;
            ringValue.seg = 0;
            pbVar20 = unaff_DI;
          }
          ringValue.seg = 0xa000;
          ringValue.ofs = CONCAT11(uVar48,uVar11) + (int)unaff_DI * 0x140;
          (*(uint8_t *)((uint8_t *)&(term))) = (uint8_t)butt01Cut5Seg;
          (*(uint8_t *)((uint8_t *)&(term) + 1)) = (undefined1)((uint)butt01Cut5Seg >> 8);
          src = butt01Cut5Ofs;
          (*(uint8_t *)((uint8_t *)&(dst))) = 0xc4;
          (*(uint8_t *)((uint8_t *)&(dst) + 1)) = 0x22;
          (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (uint8_t)term;
          gfx.ofs = butt01Cut5Ofs;
          (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (*(uint8_t *)((uint8_t *)&(term) + 1));
          ovr_blitLoadRleGfx(gfx,ringValue);
          TextBlitDstSeg = 0xa000;
          TextBlitX = CONCAT11(uVar48,uVar11) + 6;
          TextBlitY = (uint16_t)(pbVar20 + 0x10);
          piVar31 = (int *)(CONCAT11((*(uint8_t *)((uint8_t *)&(dst) + 1)),(char)dst) + (int)unaff_SI * 4);
          iVar29 = piVar31[1];
          in_DX = (uint8_t *)*piVar31;
          in_stack_0000fffc = (undefined1)iVar29;
          in_stack_0000fffd = (char)((uint)iVar29 >> 8);
          in_stack_0000fffa = SUB21(in_DX,0);
          in_stack_0000fffb = (char)((uint)in_DX >> 8);
          term = FontMain.seg;
          if (*(char *)CONCAT13(in_stack_0000fffd,CONCAT12(in_stack_0000fffc,in_DX)) == '%') break;
          if (*(char *)CONCAT13(in_stack_0000fffd,CONCAT12(in_stack_0000fffc,in_DX)) == '@') {
            ringValue.ofs = 0x13f;
            ringValue.seg = 0xf;
            src = FontMain.ofs;
            (*(uint8_t *)((uint8_t *)&(dst))) = 3;
            (*(uint8_t *)((uint8_t *)&(dst) + 1)) = 0;
            uVar11 = uVar46;
            uVar48 = uVar47;
            pcVar21 = (char *)ovr_ovc45_compute9((char *)CONCAT13(uVar47,CONCAT12(uVar46,auStack_80)
                                                                 ),
                                                 (char *)CONCAT13(in_stack_0000fffd,
                                                                  CONCAT12(in_stack_0000fffc,
                                                                           in_DX + 1)),
                                                 (char *)CONCAT22(FontMain.seg,FontMain.ofs),0x45,
                                                 '\x03');
            (*(uint8_t *)((uint8_t *)&(dst))) = (char)in_DX;
            (*(uint8_t *)((uint8_t *)&(dst) + 1)) = (undefined1)((uint)in_DX >> 8);
            ringValue.seg = ovr_blitLabel(pcVar21,in_DX,src,(uint8_t)term);
            pbVar20 = unaff_DI;
          }
          else {
            ringValue.ofs = 0x13f;
            ringValue.seg = 0xf;
            src = FontMain.ofs;
            (*(uint8_t *)((uint8_t *)&(dst))) = 3;
            (*(uint8_t *)((uint8_t *)&(dst) + 1)) = 0;
            uVar42 = *(undefined2 *)((int)unaff_SI * 4 + 5);
            uVar11 = uVar46;
            uVar48 = uVar47;
            pcVar21 = (char *)ovr_ovc45_compute9((char *)CONCAT13(uVar47,CONCAT12(uVar46,auStack_80)
                                                                 ),
                                                 (char *)CONCAT13((char)((uint)uVar42 >> 8),
                                                                  CONCAT12((char)uVar42,
                                                                           *(undefined2 *)
                                                                            ((int)unaff_SI * 4 + 3))
                                                                 ),
                                                 (char *)CONCAT22(FontMain.seg,FontMain.ofs),0x45,
                                                 '\x03');
            (*(uint8_t *)((uint8_t *)&(dst))) = (char)in_DX;
            (*(uint8_t *)((uint8_t *)&(dst) + 1)) = (undefined1)((uint)in_DX >> 8);
            ringValue.seg = ovr_blitLabel(pcVar21,in_DX,src,(uint8_t)term);
            pbVar20 = unaff_DI;
          }
        }
        BlitLetterType = 2;
        ringValue.ofs = 0x13f;
        ringValue.seg = 0xf;
        src = FontMain.ofs;
        dst = (char *)((int)(undefined4 *)&_DATA + 3);
        in_stack_00000002 = 0x45;
        in_stack_00000000 = FontMain.seg;
        unaff_BP = (char *)FontMain.ofs;
      } while( true );
    case (byte *)0x4:
      out(0,bVar28);
      pcVar1 = (char *)((int)*pasVar32 + 0x3b);
      *pcVar1 = *pcVar1 + bVar10;
      break;
    case (byte *)0x5:
      bVar26 = 9 < (bVar28 & 0xf) | in_AF;
      bVar27 = bVar28 + bVar26 * '\x06';
      cVar22 = ((char)bVar28 >> 7) + bVar26;
      uVar13 = CONCAT11(cVar22,bVar27) & 0xff0f;
      bVar23 = (byte)pasVar32;
      uVar16 = CONCAT11(bVar10 + bVar23 + bVar26,(char)in_DX);
      uVar19 = (uint)(CARRY1(bVar10,bVar23) || CARRY1(bVar10 + bVar23,bVar26));
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
      uVar15 = (int)*pasVar32 + *puVar2;
      *puVar2 = uVar15 + uVar13;
      piVar3 = (int *)((int)*pasVar32 + 0x11);
      *piVar3 = *piVar3 + uVar16 + (uint)(CARRY2(uVar19,(uint)pasVar32) || CARRY2(uVar15,uVar13));
      bVar12 = CARRY2(uVar16,*(uint *)(unaff_DI + (int)*pasVar32));
      iVar29 = uVar16 + *(uint *)(unaff_DI + (int)*pasVar32);
      *(double *)((int)&unaff_SI->ofs + (int)*pasVar32) = (double)in_ST0;
      puVar4 = (undefined2 *)((int)&unaff_SI->ofs + (int)*pasVar32);
      bVar10 = ((byte)in_CX & 0x1f) % 0x11;
      uVar9 = CONCAT12(bVar12,*puVar4);
      uVar8 = (ulong)uVar9 << bVar10 | (ulong)(uVar9 >> 0x11 - bVar10);
      *puVar4 = (int)uVar8;
      pbVar5 = (byte *)((int)&unaff_SI->ofs + (int)*pasVar32);
      bVar28 = *pbVar5;
      *pbVar5 = bVar28 << 4 |
                (byte)(CONCAT11((bVar10 == 0) * bVar12 | (bVar10 != 0) * ((uVar8 & 0x10000) != 0),
                                bVar28) >> 5);
      bVar12 = (bVar28 & 0x10) != 0;
      pbVar5 = puVar37 + 0x5110;
      bVar28 = *pbVar5;
      bVar10 = *pbVar5;
      *pbVar5 = bVar10 + bVar23 + bVar12;
      *(byte *)(*pasVar32 + 8) =
           (char)(*pasVar32)[8] + (bVar27 & 0xf) +
           (CARRY1(bVar28,bVar23) || CARRY1(bVar10 + bVar23,bVar12));
      uVar19 = CONCAT11(cVar22,bVar27) & 0xff0f ^ 0x10;
      pbVar5 = (byte *)((int)&unaff_SI->ofs + (int)*pasVar32);
      bVar26 = (byte)iVar29;
      bVar12 = bVar26 < *pbVar5;
      bVar23 = (byte)((uint)iVar29 >> 8);
      bVar26 = bVar26 - *pbVar5;
      pbVar5 = (byte *)((int)&unaff_SI->ofs + (int)*pasVar32);
      bVar28 = *pbVar5;
      bVar10 = bVar26 + *pbVar5;
      bVar27 = bVar10 + bVar12;
      out(CONCAT11(bVar23,bVar27),uVar19);
      uVar19 = CONCAT11(cVar22,*(undefined1 *)(ulong)((int)*pasVar32 + (uVar19 & 0xff)));
      (*pasVar32)[0] = CONCAT11(bVar23,bVar27);
      if (!CARRY1(bVar26,bVar28) && !CARRY1(bVar10,bVar12)) {
        ringValue.seg = 0x6000;
        pcVar7 = (code *)swi(3);
        pfVar17 = (far_t *)(*pcVar7)();
        return pfVar17;
      }
      iVar29 = (bVar27 & 3) - (AgntAnms[0x6e].maxDy & 3U);
      AgntAnms[0x6e].maxDy = AgntAnms[0x6e].maxDy + (uint)(0 < iVar29) * iVar29;
      uVar13 = (uint)unaff_SI ^ 0xdd16;
      LOCK();
      bVar28 = *unaff_DI;
      *unaff_DI = bVar27;
      UNLOCK();
      pbVar30 = (byte *)((int)*pasVar32 + 1);
      *unaff_DI = *unaff_DI & bVar28;
      *(uint *)0xa813 = in_stack_00000002;
      iVar29 = uVar13 + 0x2b64 + (uint)(0xea39 < uVar13) +
               (uint)(0xea61 < uVar13 + 0x15c6 || CARRY2(uVar13 + 0x2b64,(uint)(0xea39 < uVar13))) +
               0x2a2f;
      bVar10 = (byte)iVar29;
      bVar12 = 0x34 < (byte)(bVar10 - 0x20) || CARRY1(bVar10 + 0xab,0x1f < bVar10);
      bVar26 = bVar10 + 0xab + (0x1f < bVar10);
      bVar10 = bVar26 + 0xbe;
      bVar44 = 0x41 < bVar26 || CARRY1(bVar10,bVar12);
      bVar10 = bVar10 + bVar12;
      bVar26 = bVar10 + 0xa0;
      bVar12 = 0x5f < bVar10 || CARRY1(bVar26,bVar44);
      bVar26 = bVar26 + bVar44;
      bVar10 = bVar26 + 0x93;
      bVar44 = 0x6c < bVar26 || CARRY1(bVar10,bVar12);
      bVar10 = bVar10 + bVar12;
      bVar26 = bVar10 + 0x7d;
      bVar12 = 0x82 < bVar10 || CARRY1(bVar26,bVar44);
      bVar26 = bVar26 + bVar44;
      bVar10 = bVar26 + 0x61;
      bVar44 = 0x9e < bVar26 || CARRY1(bVar10,bVar12);
      bVar10 = bVar10 + bVar12;
      bVar26 = bVar10 + 0x57;
      bVar12 = 0xa8 < bVar10 || CARRY1(bVar26,bVar44);
      bVar26 = bVar26 + bVar44;
      bVar10 = bVar26 + 0x43;
      bVar44 = 0xbc < bVar26 || CARRY1(bVar10,bVar12);
      bVar10 = bVar10 + bVar12;
      bVar26 = bVar10 + 0x39;
      bVar12 = 0xc6 < bVar10 || CARRY1(bVar26,bVar44);
      bVar26 = bVar26 + bVar44;
      bVar10 = bVar26 + 0x23;
      bVar44 = 0xdc < bVar26 || CARRY1(bVar10,bVar12);
      bVar10 = bVar10 + bVar12;
      bVar26 = bVar10 + 0xb;
      bVar12 = 0xf4 < bVar10 || CARRY1(bVar26,bVar44);
      bVar26 = bVar26 + bVar44;
      bVar10 = bVar26 + 0x8d;
      uVar16 = CONCAT11((char)((uint)iVar29 >> 8),bVar10 + bVar12);
      uVar13 = (uint)(0x72 < bVar26 || CARRY1(bVar10,bVar12));
      uVar15 = uVar16 - *(uint *)(pbVar30 + uVar19 + 0x5c1b);
      pbVar14 = (byte *)(uVar15 - uVar13);
      uVar13 = (uint)(uVar16 < *(uint *)(pbVar30 + uVar19 + 0x5c1b) || uVar15 < uVar13);
      uVar15 = (int)in_CX - *(uint *)(puVar37 + 0x1b);
      iVar29 = uVar15 - uVar13;
      uVar13 = (uint)(in_CX < *(far_t **)(puVar37 + 0x1b) || uVar15 < uVar13);
      uVar15 = uVar19 - *(uint *)(pbVar30 + uVar19);
      puVar38 = (uint *)(uVar15 - uVar13);
      uVar19 = (uint)(uVar19 < *(uint *)(pbVar30 + uVar19) || uVar15 < uVar13);
      uVar15 = 0xa814 - AgntAnms[0x39].missileDy;
      iVar39 = -uVar19;
      uVar19 = (uint)(0xa814 < (uint)AgntAnms[0x39].missileDy || uVar15 < uVar19);
      pbVar40 = (byte *)(((int)unaff_DI - (int)pbVar14) - uVar19);
      bVar12 = bVar23 < (pbVar30 + (int)pbVar40)[-0x5be6] ||
               (byte)(bVar23 - (pbVar30 + (int)pbVar40)[-0x5be6]) <
               (unaff_DI < pbVar14 || (uint)((int)unaff_DI - (int)pbVar14) < uVar19);
      bVar10 = (byte)iVar29;
      bVar26 = bVar10 - pbVar40[0x3e1a];
      bVar44 = bVar10 < pbVar40[0x3e1a] || bVar26 < bVar12;
      bVar27 = (byte)((uint)iVar29 >> 8);
      bVar26 = bVar26 - bVar12;
      bVar10 = bVar27 - bVar28;
      bVar25 = bVar10 - bVar44;
      pbVar5 = pbVar40 + 0x4119;
      uVar19 = (uint)(bVar27 < bVar28 || bVar10 < bVar44);
      pbVar20 = *(byte **)pbVar5;
      iVar29 = *(int *)pbVar5;
      *(uint *)pbVar5 = (iVar29 - (int)pbVar14) - uVar19;
      puVar2 = puVar38;
      uVar13 = (uint)(pbVar20 < pbVar14 || (uint)(iVar29 - (int)pbVar14) < uVar19);
      puVar34 = (uint *)*puVar2;
      uVar19 = *puVar2;
      *puVar2 = (uVar19 - (int)puVar38) - uVar13;
      uVar19 = (uint)(puVar34 < puVar38 || uVar19 - (int)puVar38 < uVar13);
      bVar12 = (uint)(*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight) + 21)) < CONCAT11(bVar25,bVar26);
      uVar13 = (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight) + 21)) - CONCAT11(bVar25,bVar26);
      (*(uint16_t *)((uint8_t *)&(__C0_ASM_CopyRight) + 21)) = uVar13 - uVar19;
      uVar19 = (uint)(bVar12 || uVar13 < uVar19);
      piVar31 = (int *)-uVar19;
      bVar23 = (byte)((uint)pbVar14 >> 8);
      bVar12 = bVar28 < bVar23 || (byte)(bVar28 - bVar23) < (uVar19 != 0);
      bVar10 = (bVar28 - bVar23) - (uVar19 != 0);
      bVar28 = (byte)pbVar14 - (byte)pbVar30;
      bVar27 = bVar28 - bVar12;
      bVar12 = bVar10 < bVar27 ||
               (byte)(bVar10 - bVar27) < ((byte)pbVar14 < (byte)pbVar30 || bVar28 < bVar12);
      pbVar5 = (byte *)((char *)"%s turns %d undead." + 9 + (int)puVar37 + (int)piVar31);
      bVar28 = *pbVar5;
      bVar10 = *pbVar5;
      *pbVar5 = (bVar10 - bVar25) - bVar12;
      pcVar1 = (char *)((int)puVar37 + (int)piVar31 + 0x18);
      *pcVar1 = (*pcVar1 - bVar23) - (bVar28 < bVar25 || (byte)(bVar10 - bVar25) < bVar12);
      bVar12 = CONCAT11(bVar23,bVar27) < 0x2318;
      bVar27 = bVar27 - 0x18;
      pbVar5 = pbVar30;
      bVar44 = *pbVar5 < bVar26 || (byte)(*pbVar5 - bVar26) < bVar12;
      *pbVar5 = (*pbVar5 - bVar26) - bVar12;
      pbVar5 = pbVar40;
      bVar28 = *pbVar5;
      bVar10 = *pbVar5;
      *pbVar5 = (bVar10 - bVar27) - bVar44;
      uVar42 = CONCAT11(bVar25,(bVar26 - bVar27) -
                               (bVar28 < bVar27 || (byte)(bVar10 - bVar27) < bVar44));
      uVar43 = *(undefined2 *)(uVar15 + iVar39 + 2);
      puVar34 = (uint *)(uVar15 + iVar39 + 4);
      pcVar7 = (code *)swi(0x1e);
      uVar45 = (*pcVar7)();
      uVar41 = (undefined2)((ulong)uVar45 >> 0x10);
      uVar19 = (uint)uVar45;
      uVar13 = *puVar34;
      *puVar34 = uVar43;
      puVar34[-1] = uVar43;
      bVar28 = (byte)((ulong)uVar45 >> 0x10);
      if (((uVar13 & 0x800) != 0) == ((uVar13 & 0x80) != 0)) {
code_r0x0006013c:
        lVar6 = (long)*piVar31 * 0x48;
        bVar12 = (int)lVar6 != lVar6;
        bVar26 = (byte)uVar19 - 0x1d;
        bVar44 = (byte)uVar19 < 0x1d || bVar26 < bVar12;
        bVar26 = bVar26 - bVar12;
        bVar27 = bVar26 + 3;
        bVar10 = bVar27 - bVar44;
        pbVar40 = pbVar40 + (-(uint)(bVar26 < 0xfd || bVar27 < bVar44) - (int)puVar34);
        pbVar30 = (byte *)CONCAT11((byte)((ulong)lVar6 >> 8) & (byte)((uint)uVar42 >> 8) & bVar10,
                                   (char)lVar6);
        (puVar37 + (int)pbVar40)[-0x62e0] =
             (puVar37 + (int)pbVar40)[-0x62e0] & (byte)((ulong)uVar45 >> 0x18);
        (pbVar30 + (int)pbVar40)[0x6f20] = (pbVar30 + (int)pbVar40)[0x6f20] & (byte)uVar42;
      }
      else {
        puVar34[-2] = uVar19;
        puVar34[-3] = uVar42;
        puVar34[-4] = uVar41;
        puVar34[-5] = (uint)pbVar30;
        puVar34[-6] = (uint)(puVar34 + -1);
        puVar34[-7] = (uint)puVar37;
        puVar34[-8] = (uint)piVar31;
        puVar34[-9] = (uint)pbVar40;
        puVar35 = puVar34 + -10;
        puVar36 = puVar34 + -10;
        puVar34[-10] = uVar43;
        uVar11 = in(uVar41);
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
      (puVar37 + (int)pbVar40)[0x20] = (puVar37 + (int)pbVar40)[0x20] & bVar28;
      bVar12 = false;
      uVar19 = (uint)(bVar10 ^ 0x20);
      puVar38 = puVar34;
L_OVC27_2288:
      cVar22 = ((char)uVar19 + -0x20) - bVar12;
      pbVar30[(int)piVar31] = pbVar30[(int)piVar31] + cVar22;
      pbVar30[(int)piVar31] = pbVar30[(int)piVar31] + cVar22;
      pbVar30[(int)piVar31] = pbVar30[(int)piVar31] + cVar22;
      pbVar30[(int)piVar31] = pbVar30[(int)piVar31] + cVar22;
      pbVar30[(int)piVar31] = pbVar30[(int)piVar31] + cVar22;
      pbVar30[(int)piVar31] = pbVar30[(int)piVar31] + cVar22;
      pbVar30[(int)piVar31] = pbVar30[(int)piVar31] + cVar22;
      pbVar30[(int)piVar31] = pbVar30[(int)piVar31] + cVar22;
      pbVar30[(int)piVar31] = pbVar30[(int)piVar31] + cVar22;
      pbVar30[(int)piVar31] = pbVar30[(int)piVar31] + cVar22;
      pbVar30[(int)piVar31] = pbVar30[(int)piVar31] + cVar22;
      pbVar30[(int)piVar31] = pbVar30[(int)piVar31] + cVar22;
      pbVar30[(int)piVar31] = pbVar30[(int)piVar31] + cVar22;
      pbVar30[(int)piVar31] = pbVar30[(int)piVar31] + cVar22;
      pbVar30[(int)piVar31] = pbVar30[(int)piVar31] + cVar22;
      pbVar30[(int)piVar31] = pbVar30[(int)piVar31] + cVar22;
      pbVar30[(int)piVar31] = pbVar30[(int)piVar31] + cVar22;
      pbVar30[(int)piVar31] = pbVar30[(int)piVar31] + cVar22;
      pbVar40[-0x75] = pbVar40[-0x75] + bVar28;
      in(uVar41);
      *(undefined2 *)((int)puVar38 + -6) = piVar31;
      iVar29 = *(int *)(puVar37 + 6);
      do {
        iVar39 = iVar29 + -1;
        if (iVar29 == 0) {
          return (far_t *)0x0;
        }
        uVar42 = *(undefined2 *)BDA_DailyTimeCounter;
        *(undefined2 *)(puVar37 + -2) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
        *(undefined2 *)(puVar37 + -4) = uVar42;
        do {
          iVar29 = iVar39;
          if (*(int *)(BDA_DailyTimeCounter.ofs + 2) != *(int *)(puVar37 + -2)) break;
        } while (*(int *)BDA_DailyTimeCounter == *(int *)(puVar37 + -4));
      } while( true );
    case (byte *)0x6:
      *(byte *)(*pasVar32 + 0x15) = bVar28;
      if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + ((uint)dst & 0xff) * 0x95) & 0x800) != 0) {
        *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x2d) = 0x12;
      }
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x3f) =
           *(undefined1 *)((int)(char **)GMenuStrings + ((uint)dst & 0xff) * 0x95 + 0x1f);
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x33) =
           *(undefined1 *)((int)(far_t *)(worldMenuLabels + 9) + ((uint)dst & 0xff) * 0x95);
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x31) =
           *(undefined1 *)((int)&worldMenuLabels[6].seg + ((uint)dst & 0xff) * 0x95);
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x32) =
           *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x31);
      pbVar5 = (byte *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x28);
      *pbVar5 = *pbVar5 | 0x16;
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x40) = 1;
      iVar29 = CONCAT11(in_stack_0000fffb,in_stack_0000fffa);
      uVar42 = (undefined2)(CONCAT13(in_stack_0000fffd,CONCAT12(in_stack_0000fffc,iVar29)) >> 0x10);
      *(undefined2 *)(iVar29 + 0x58) = 0;
      *(undefined2 *)(iVar29 + 0x56) = 100;
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x89) = 0xff;
      uVar11 = 0x5d;
      pfVar17 = ovr_ovc22_textRingProt(in_stack_0000fff8);
      return (far_t *)CONCAT11((char)((uint)pfVar17 >> 8),uVar11);
    case (byte *)0x7:
      do {
        unaff_DI = (byte *)((uint)unaff_DI | *(uint *)(pbVar20 + (int)(*pasVar32 + -2)) & 0x3000);
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
            uVar41 = (undefined2)((ulong)GUnits >> 0x10);
            puVar33 = (unit_t *)GUnits;
          } while ((((*(uint *)((uint)(puVar33 + (int)pfVar17)->bldType * 0x27 + 0x121) & 0x60) != 0
                    ) || (puVar33[(int)pfVar17].unitType == 0xff)) ||
                  (uVar45 = *(undefined4 *)((uint)puVar33[(int)pfVar17].unitType << 2),
                  *(char *)((int)uVar45 + 0x3f) != '\0'));
          in_stack_0000fffa = (undefined1)uVar42;
          in_stack_0000fffb = (char)((uint)uVar42 >> 8);
          uVar42 = 0x2379;
          uVar19 = ovr_alignUp4(puVar33[(int)pfVar17].x);
          in_stack_0000fff8 = (byte)uVar19;
          in_stack_0000fff9 = (undefined1)(uVar19 >> 8);
          in_stack_0000fff6 = ((unit_t *)GUnits)[CONCAT11(in_stack_0000fffb,in_stack_0000fffa)].y;
          unaff_DI = (byte *)0x0;
          unaff_SI = (far_t *)0x0;
        }
        unaff_ES = (undefined2)((ulong)GMapFlags >> 0x10);
        pasVar32 = *(short (*) [60] [148])GMapFlags + in_stack_0000fff6;
        pbVar20 = (byte *)((int)((int)&unaff_SI->ofs + CONCAT11(in_stack_0000fff9,in_stack_0000fff8)
                                ) * 2);
      } while( true );
    case (byte *)0x8:
      uVar18 = 0x217a;
      uVar45 = *(undefined4 *)(((uint)dst & 0xff) << 2);
      if (*(uint *)((int)*(undefined4 *)pbVar20 + 0x54) < (uint)-*(int *)((int)uVar45 + 0x4d)) {
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
            pfVar17 = (far_t *)ovr_stsprintf(acStack_2cc,unaff_SS,(char *)msgFormat.ofs);
            ovr_drawString((char *)pfVar17,uVar18);
          }
          else {
            ovc39_loadArchiveEntry(bVar28 + 0x17);
            pcVar21 = ovc39_lordOrLady();
            iStack_10 = 24576;
            uStack_12 = 0x9b7b;
            pfVar17 = (far_t *)ovr_stsprintf(acStack_2cc,unaff_SS,pcVar21);
            uVar46 = (undefined1)uVar18;
            uVar47 = (undefined1)(uVar18 >> 8);
            uVar11 = SUB21(pfVar17,0);
            uVar48 = (undefined1)((uint)pfVar17 >> 8);
            ovr_drawString((char *)pfVar17,uVar18);
            (*(uint8_t *)((uint8_t *)&(handle_01.ofs) + 1)) = uVar48;
            (*(uint8_t *)((uint8_t *)&(handle_01.ofs))) = uVar11;
            (*(uint8_t *)((uint8_t *)&(handle_01.seg))) = uVar46;
            (*(uint8_t *)((uint8_t *)&(handle_01.seg) + 1)) = uVar47;
            ovr_stshFree(handle_01);
          }
        }
        else {
          ovc39_loadArchiveEntry(in_stack_0000fff2 + 0xd);
          pcVar21 = ovc39_lordOrLady();
          iStack_10 = 24576;
          uStack_12 = 0x9b2e;
          pfVar17 = (far_t *)ovr_stsprintf(acStack_2cc,unaff_SS,pcVar21);
          uVar46 = (undefined1)uVar18;
          uVar47 = (undefined1)(uVar18 >> 8);
          uVar11 = SUB21(pfVar17,0);
          uVar48 = (undefined1)((uint)pfVar17 >> 8);
          ovr_drawString((char *)pfVar17,uVar18);
          (*(uint8_t *)((uint8_t *)&(handle_00.ofs) + 1)) = uVar48;
          (*(uint8_t *)((uint8_t *)&(handle_00.ofs))) = uVar11;
          (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = uVar46;
          (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = uVar47;
          ovr_stshFree(handle_00);
        }
      }
      else {
        ovc39_loadArchiveEntry(in_stack_0000fff4 + 0x12);
        pcVar21 = ovc39_lordOrLady();
        iStack_10 = 24576;
        uStack_12 = 0x9ad8;
        pfVar17 = (far_t *)ovr_stsprintf(acStack_2cc,unaff_SS,pcVar21);
        uVar46 = (undefined1)uVar18;
        uVar47 = (undefined1)(uVar18 >> 8);
        uVar11 = SUB21(pfVar17,0);
        uVar48 = (undefined1)((uint)pfVar17 >> 8);
        ovr_drawString((char *)pfVar17,uVar18);
        (*(uint8_t *)((uint8_t *)&(handle.ofs) + 1)) = uVar48;
        (*(uint8_t *)((uint8_t *)&(handle.ofs))) = uVar11;
        (*(uint8_t *)((uint8_t *)&(handle.seg))) = uVar46;
        (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = uVar47;
        ovr_stshFree(handle);
      }
      return pfVar17;
    }
  }
  uVar11 = 0x24;
  if (MouseMoved == 0) {
    ovc28_textHalflingCastle();
    uVar19 = MouseX - 0xc >> 1;
    ovr_ovc13_usesBlitLoadRleGfx2
              (CONCAT11((byte)(MouseX - 0xc >> 9),(char)uVar19),MouseY - 7,'\x01');
    return (far_t *)CONCAT11((char)(uVar19 >> 8),0xfe);
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
    uVar19 = MouseX - 0xef >> 1;
    ovr_ovc13_usesBlitLoadRleGfx3
              (CONCAT11((byte)(MouseX - 0xef >> 9),(char)uVar19),MouseY - 7,'\x01');
    pfVar17 = (far_t *)CONCAT11((char)(uVar19 >> 8),0xfe);
  }
                    /* WARNING: Read-only address (ram,0x0002c58a) is written */
  return pfVar17;
}



/* 6386:05d3 */

/* [R7] body shape: compute */

char __cdecl16far stats_compute4(agnt_t *agnt)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)agnt >> 0x10);
  bVar1 = ((agnt_t *)agnt)->gindex;
  if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar1 * 0x95) == -1) {
    cVar3 = *(char *)((int)&worldMenuLabels[9].seg + (uint)bVar1 * 0x95);
  }
  else {
    bVar2 = ovr_agnt_compute10(agnt);
    cVar3 = *(char *)((int)&worldMenuLabels[9].seg + (uint)bVar1 * 0x95) - bVar2;
    uVar4 = ovr_agnt_abilityModifier(*(byte *)((int)&((agnt_t *)agnt)->entity + 3),3);
    cVar3 = cVar3 - (char)uVar4;
  }
  return cVar3;
}



/* 6386:065c */

/* WARNING: Removing unreachable block (ram,0x00063ec8) */
/* Formats a long for the stats screen, switching to a 'K' suffix above a thousand. */

char * __cdecl16far stats_formatThousands(char *text,uint32_t value)

{
  size_t sVar1;
  long n;
  
  if ((long)value < 1000000) {
    (*(uint16_t *)((uint8_t *)&(text))) = ovr_litoa10((char *)text,value);
  }
  else {
    n = LDIV_at_(value,1000);
    ovr_litoa10((char *)text,n);
    sVar1 = strlen((char *)text);
    ((char *)text)[sVar1] = 'K';
    ((char *)text)[sVar1 + 1] = '\0';
  }
  return (char *)text;
}



/* 6386:06cd */

/* WARNING: Variable defined which should be unmapped: cmap */

void __cdecl16far drawAgntStats(agnt_t *agnt,far_t cmap)

{
  undefined4 uVar1;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t ringValue;
  char cVar2;
  byte bVar3;
  char *pcVar4;
  uint uVar5;
  int *piVar6;
  undefined2 *puVar7;
  int iVar8;
  far_t *text_00;
  uint8_t *in_DX;
  uint8_t *puVar9;
  uint16_t agnt_o;
  uint16_t agnt_s;
  undefined2 uVar10;
  undefined2 uVar11;
  char *unaff_SS;
  undefined1 uVar12;
  undefined1 uVar13;
  uint16_t uVar14;
  uint16_t uVar15;
  uint8_t uVar16;
  uint8_t uVar17;
  char palbuf [768];
  char buf [80];
  uint8_t text;
  uint8_t line;
  uint8_t field_index;
  byte bStack_4;
  int8_t damage;
  
  TextBlitDstSeg = 0xa000;
  if (cmap.ofs == 0 && cmap.seg == 0) {
    cmap.seg = (uint16_t)unaff_SS;
    cmap.ofs = (uint16_t)palbuf;
  }
  if (!GameRunning) {
    stats_drawStatsPanel();
  }
  agnt_o = (uint16_t)agnt;
  agnt_s = (uint16_t)((ulong)agnt >> 0x10);
  if (DebugVerbose != false) {
    printf("Exp %ld \r");
  }
  field_index = (*(uint *)((int)*(undefined4 *)(agnt_o + 0x17) + 0x16) & 1) != 0;
  bStack_4 = field_index;
  if (3 < *(byte *)((int)*(undefined4 *)(agnt_o + 0x17) + 0xf)) {
    bStack_4 = field_index + 4;
  }
  stats_drawPortrait((agntG_t *)
                     CONCAT22(*(undefined2 *)(agnt_o + 0x1f),
                              (agntG_t *)*(undefined2 *)(agnt_o + 0x1d)),bStack_4,cmap.ofs);
  TextBlitY = 10;
  TextBlitX = 0x87;
  uVar16 = (uint8_t)Font02.seg;
  uVar14 = Font02.ofs;
  pcVar4 = ovr_agnt_statusText(agnt,(char *)&line);
  ovr_blitLabel(pcVar4,in_DX,uVar14,uVar16);
  if ((GameRunning == false) &&
     ((*(char *)*(undefined4 *)(agnt_o + 0x1d) == '\0' || (DebugVerbose != false)))) {
    TextBlitY = 0xb5;
    TextBlitX = 0x13;
    if ((*(byte *)((int)*(undefined4 *)(agnt_o + 0x17) + 0x33) & 1) == 0) {
      gfx_00.seg = butt01Cut3Seg;
      gfx_00.ofs = butt01Cut3Ofs;
      ovr_blitGfxRect(gfx_00,16,179,(brect_t *)(BlitRects + 1),0x10,true);
    }
    else {
      gfx.seg = butt01Cut4Seg;
      gfx.ofs = butt01Cut4Ofs;
      ovr_blitGfxRect(gfx,16,179,(brect_t *)(BlitRects + 1),0x10,true);
      TextBlitX = 0x47;
      ovr_blitLabel((char *)"\x7f",(uint8_t *)((char *)"puppetmaker" + 3),Font01.ofs,
                    (uint8_t)Font01.seg);
      TextBlitX = 0x13;
    }
    ovr_blitLabel((char *)"Ready",(uint8_t *)((char *)"puppetmaker" + 3),Font01.ofs,
                  (uint8_t)Font01.seg);
    TextBlitY = 0xb5;
    TextBlitX = 0x57;
    uVar5 = stats_usesAlignUp4(*(int *)(agnt_o + 0x1b));
    if ((char)uVar5 == '\0') {
      gfx_02.seg = butt01Cut3Seg;
      gfx_02.ofs = butt01Cut3Ofs;
      ovr_blitGfxRect(gfx_02,84,179,(brect_t *)(BlitRects + 1),0x10,true);
    }
    else {
      gfx_01.seg = butt01Cut4Seg;
      gfx_01.ofs = butt01Cut4Ofs;
      ovr_blitGfxRect(gfx_01,84,179,(brect_t *)(BlitRects + 1),0x10,true);
      TextBlitX = 0x8b;
      ovr_blitLabel((char *)"\x7f",(uint8_t *)((char *)"puppetmaker" + 3),Font01.ofs,
                    (uint8_t)Font01.seg);
      TextBlitX = 0x57;
    }
    ovr_blitLabel((char *)"Home",(uint8_t *)((char *)"puppetmaker" + 3),FontMain.ofs,
                  (uint8_t)FontMain.seg);
    TextBlitY = 0xb5;
    TextBlitX = 0x9b;
    uVar5 = stats_usesAlignUp4(*(int *)(agnt_o + 0x1b));
    if (((uVar5 & 0xff) == 0) && ((*(byte *)((int)*(undefined4 *)(agnt_o + 0x17) + 0x33) & 1) == 0))
    {
      gfx_03.seg = butt01Cut4Seg;
      gfx_03.ofs = butt01Cut4Ofs;
      ovr_blitGfxRect(gfx_03,152,179,(brect_t *)(BlitRects + 1),0x10,true);
      TextBlitX = 0xcf;
      ovr_blitLabel((char *)"\x7f",(uint8_t *)((char *)"puppetmaker" + 3),Font01.ofs,
                    (uint8_t)Font01.seg);
      TextBlitX = 0x9b;
    }
    else {
      gfx_04.seg = butt01Cut3Seg;
      gfx_04.ofs = butt01Cut3Ofs;
      ovr_blitGfxRect(gfx_04,152,179,(brect_t *)(BlitRects + 1),0x10,true);
    }
    ovr_blitLabel((char *)"Unassigned",(uint8_t *)((char *)"puppetmaker" + 3),FontMain.ofs,
                  (uint8_t)FontMain.seg);
  }
  TextBlitY = 0x11;
  TextBlitX = 0x87;
  uVar16 = (uint8_t)Font02.seg;
  uVar14 = Font02.ofs;
  pcVar4 = ovr_stsprintf((char *)&line,unaff_SS,(char *)"Unit of %d");
  ovr_blitLabel(pcVar4,in_DX,uVar14,uVar16);
  TextBlitY = 0x1b;
  TextBlitX = 0x87;
  if (*(char *)((int)*(undefined4 *)(agnt_o + 0x17) + 0x1a) != -1) {
    puVar7 = (undefined2 *)((uint)*(byte *)((int)*(undefined4 *)(agnt_o + 0x17) + 0x1a) * 4);
    uVar10 = puVar7[1];
    uVar5 = ovr_font_textWidth((char *)CONCAT13((char)((uint)uVar10 >> 8),
                                                CONCAT12((char)uVar10,*puVar7)),
                               (char *)CONCAT22(Font02.seg,Font02.ofs));
    uVar16 = (uint8_t)Font02.seg;
    uVar12 = (undefined1)Font02.ofs;
    uVar13 = (undefined1)(Font02.ofs >> 8);
    if (uVar5 < 0x30) {
      cVar2 = '\x03';
      uVar5 = 0x56;
      in_DX = (uint8_t *)((char *)"halfling castle" + 0xc);
      uVar14 = Font02.seg;
      uVar15 = Font02.ofs;
      pcVar4 = ovr_stsprintf((char *)&text,unaff_SS,(char *)"Loyal to %s");
      pcVar4 = (char *)ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,&line),
                                          (char *)CONCAT13((char)((uint)in_DX >> 8),
                                                           CONCAT12((char)in_DX,pcVar4)),
                                          (char *)CONCAT22(uVar14,(char *)CONCAT11(uVar13,uVar12)),
                                          uVar5,cVar2);
      ovr_blitLabel(pcVar4,in_DX,uVar15,uVar16);
    }
    else {
      cVar2 = '\x03';
      uVar5 = 0x56;
      in_DX = (uint8_t *)((char *)"halfling castle" + 0xc);
      uVar14 = Font02.seg;
      uVar15 = Font02.ofs;
      pcVar4 = ovr_stsprintf((char *)&text,unaff_SS,(char *)"L. to %s");
      pcVar4 = (char *)ovr_ovc45_compute9((char *)CONCAT22(unaff_SS,&line),
                                          (char *)CONCAT13((char)((uint)in_DX >> 8),
                                                           CONCAT12((char)in_DX,pcVar4)),
                                          (char *)CONCAT22(uVar14,(char *)CONCAT11(uVar13,uVar12)),
                                          uVar5,cVar2);
      ovr_blitLabel(pcVar4,in_DX,uVar15,uVar16);
    }
  }
  TextBlitY = 0x25;
  TextBlitX = 0x87;
  uVar16 = (uint8_t)unaff_SS;
  if (*(char *)((int)*(undefined4 *)(agnt_o + 0x1d) + 0x46) != -1) {
    cVar2 = stats_compute3(agnt);
    uVar17 = (uint8_t)Font02.seg;
    if (cVar2 == '\0') {
      uVar14 = Font02.ofs;
      bVar3 = stats_compute2(agnt);
      ovr_manage_compute1((uint)bVar3);
      stats_compute2(agnt);
      pcVar4 = ovr_stsprintf((char *)&line,unaff_SS,(char *)"%d%s level, ");
      ovr_blitLabel(pcVar4,in_DX,uVar14,uVar17);
    }
    else {
      uVar14 = Font02.ofs;
      stats_compute1(agnt);
      bVar3 = stats_compute2(agnt);
      ovr_manage_compute1((uint)bVar3);
      stats_compute2(agnt);
      pcVar4 = ovr_stsprintf((char *)&line,unaff_SS,(char *)"%d%s lv rn %c, ");
      ovr_blitLabel(pcVar4,in_DX,uVar14,uVar17);
    }
  }
  if ((*(char *)((int)*(undefined4 *)(agnt_o + 0x1d) + 0x46) == -1) ||
     (*(char *)((int)*(undefined4 *)(agnt_o + 0x17) + 0x1a) == -1)) {
    uVar5 = (uint)*(byte *)((int)*(undefined4 *)(agnt_o + 0x1d) + 0x45);
    puVar9 = (uint8_t *)((char *)"puppetmaker" + 3);
    ovr_blitLabel((char *)((far_t *)GAlignmentsNames + uVar5)->ofs,
                  (uint8_t *)*(undefined2 *)((int)&GAlignmentsNames[0].seg + uVar5 * 4),Font02.ofs,
                  (uint8_t)Font02.seg);
  }
  else {
    uVar1 = *(undefined4 *)((uint)*(byte *)((int)*(undefined4 *)(agnt_o + 0x17) + 0x1a) << 2);
    uVar5 = (uint)*(byte *)((int)uVar1 + 0x33);
    puVar9 = (uint8_t *)((char *)"puppetmaker" + 3);
    ovr_blitLabel((char *)((far_t *)GAlignmentsNames + uVar5)->ofs,
                  (uint8_t *)*(undefined2 *)((int)&GAlignmentsNames[0].seg + uVar5 * 4),Font02.ofs,
                  (uint8_t)Font02.seg);
  }
  TextBlitY = 0x2f;
  TextBlitX = 0x87;
  if ((*(char *)((int)*(undefined4 *)(agnt_o + 0x1d) + 0x46) != -1) &&
     (*(char *)*(undefined4 *)(agnt_o + 0x1d) == '\0')) {
    ovr_blitLabel((char *)"Experience points",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                  (uint8_t)Font02.seg);
    TextBlitY = 0x36;
    TextBlitX = 0x87;
    piVar6 = (int *)((uint)*(byte *)((int)*(undefined4 *)(agnt_o + 0x1d) + 0x46) * 0x94 +
                    (uint)*(byte *)((int)*(undefined4 *)(agnt_o + 0x17) + 0xf) * 4);
    puVar9 = (uint8_t *)((char *)"sturdy e/w wall" + 0xf);
    uVar17 = (uint8_t)Font02.seg;
    if (*piVar6 == 0 && piVar6[1] == 0) {
      uVar11 = (undefined2)((ulong)*(undefined4 *)(agnt_o + 0x17) >> 0x10);
      iVar8 = (int)*(undefined4 *)(agnt_o + 0x17);
      uVar10 = *(undefined2 *)(iVar8 + 0x12);
      uVar14 = Font02.ofs;
      ovr_litoa10((char *)&text,
                  CONCAT13((char)((uint)uVar10 >> 8),
                           CONCAT12((char)uVar10,*(undefined2 *)(iVar8 + 0x10))));
      pcVar4 = ovr_stsprintf((char *)&line,unaff_SS,(char *)"Loyal to %s" + 9);
      ovr_blitLabel(pcVar4,puVar9,uVar14,uVar17);
    }
    else {
      puVar7 = (undefined2 *)
               ((uint)*(byte *)((int)*(undefined4 *)(agnt_o + 0x1d) + 0x46) * 0x94 +
               (uint)*(byte *)((int)*(undefined4 *)(agnt_o + 0x17) + 0xf) * 4);
      puVar9 = (uint8_t *)((char *)"sturdy e/w wall" + 0xf);
      uVar10 = puVar7[1];
      uVar14 = Font02.ofs;
      stats_formatThousands
                ((char *)CONCAT22(unaff_SS,buf),
                 CONCAT13((char)((uint)uVar10 >> 8),CONCAT12((char)uVar10,*puVar7)));
      uVar10 = (undefined2)((ulong)*(undefined4 *)(agnt_o + 0x17) >> 0x10);
      iVar8 = (int)*(undefined4 *)(agnt_o + 0x17);
      stats_formatThousands
                ((char *)CONCAT13((char)((uint)unaff_SS >> 8),CONCAT12(uVar16,&text)),
                 CONCAT22(*(undefined2 *)(iVar8 + 0x12),*(undefined2 *)(iVar8 + 0x10)));
      pcVar4 = ovr_stsprintf((char *)&line,unaff_SS,(char *)"%s/%s");
      ovr_blitLabel(pcVar4,puVar9,uVar14,uVar17);
    }
  }
  if (*(char *)*(undefined4 *)(agnt_o + 0x1d) != '\0') {
    uVar17 = (uint8_t)Font02.seg;
    uVar14 = Font02.ofs;
    ovr_ovc41_growthForLevel
              ((agnt_t *)
               CONCAT13((char)((uint)*(undefined2 *)(agnt_o + 0x19) >> 8),
                        CONCAT12((char)*(undefined2 *)(agnt_o + 0x19),*(undefined2 *)(agnt_o + 0x17)
                                )));
    pcVar4 = ovr_stsprintf((char *)&line,unaff_SS,(char *)"XP value %d");
    ovr_blitLabel(pcVar4,puVar9,uVar14,uVar17);
  }
  TextBlitY = 0x40;
  TextBlitX = 0x87;
  uVar17 = (uint8_t)Font02.seg;
  uVar14 = Font02.ofs;
  pcVar4 = ovr_stsprintf((char *)&line,unaff_SS,(char *)"Hit Points %d/%d");
  ovr_blitLabel(pcVar4,puVar9,uVar14,uVar17);
  TextBlitY = 0x4a;
  TextBlitX = 0x87;
  iVar8 = (uint)*(byte *)((int)*(undefined4 *)(agnt_o + 0x1d) + 1) * 0x95;
  puVar9 = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
  if (*(int *)((int)&AgntGs[0].wpn_name + iVar8) == 0 &&
      *(int *)((int)&AgntGs[0].wpn_name + 2 + iVar8) == 0) {
    damage = 0;
  }
  else {
    damage = ovr_agnt_compute9(agnt);
    uVar17 = (uint8_t)Font02.seg;
    if (damage == 0) {
      uVar14 = Font02.ofs;
      pcVar4 = agntGetWeaponName(buf,uVar16,*(bool *)((int)*(undefined4 *)(agnt_o + 0x1d) + 1),0x0,
                                 CONCAT22(agnt_o,CONCAT11(0x24,field_index)));
      ovr_blitLabel(pcVar4,puVar9,uVar14,uVar17);
    }
    else if (damage < '\0') {
      uVar14 = Font02.ofs;
      agntGetWeaponName(buf,uVar16,*(bool *)((int)*(undefined4 *)(agnt_o + 0x1d) + 1),damage,
                        CONCAT22(agnt_o,CONCAT11(0x24,field_index)));
      pcVar4 = ovr_stsprintf((char *)&line,unaff_SS,(char *)"damaged %s");
      ovr_blitLabel(pcVar4,puVar9,uVar14,uVar17);
    }
    else {
      uVar14 = Font02.ofs;
      agntGetWeaponName(buf,uVar16,*(bool *)((int)*(undefined4 *)(agnt_o + 0x1d) + 1),damage,
                        CONCAT22(agnt_o,CONCAT11(0x24,field_index)));
      pcVar4 = ovr_stsprintf((char *)&line,unaff_SS,(char *)"+%d %s");
      ovr_blitLabel(pcVar4,puVar9,uVar14,uVar17);
    }
  }
  TextBlitY = 0x54;
  TextBlitX = 0x87;
  if (*(char *)*(undefined4 *)(agnt_o + 0x1d) == '\0') {
    damage = ovr_agnt_compute11(agnt);
  }
  else {
    damage = 0;
  }
  uVar16 = (uint8_t)Font02.seg;
  uVar14 = Font02.ofs;
  stats_compute4((agnt_t *)
                 CONCAT13((char)((uint)*(undefined2 *)(agnt_o + 0x19) >> 8),
                          CONCAT12((char)*(undefined2 *)(agnt_o + 0x19),
                                   *(undefined2 *)(agnt_o + 0x17))));
  pcVar4 = ovr_stsprintf((char *)&line,unaff_SS,(char *)"Armor class %d");
  ovr_blitLabel(pcVar4,puVar9,uVar14,uVar16);
  if (*(char *)*(undefined4 *)(agnt_o + 0x1d) == '\0') {
    TextBlitY = 0x5e;
    TextBlitX = 0x87;
    uVar16 = (uint8_t)Font02.seg;
    (*(uint8_t *)((uint8_t *)&(ringValue.ofs) + 1)) = 0x24;
    (*(uint8_t *)((uint8_t *)&(ringValue.ofs))) = *(undefined1 *)((int)*(undefined4 *)(agnt_o + 0x1d) + 0x47);
    (*(uint8_t *)((uint8_t *)&(ringValue.seg))) = damage;
    (*(uint8_t *)((uint8_t *)&(ringValue.seg) + 1)) = 0x24;
    uVar14 = Font02.ofs;
    text_00 = stats_textRingProt(buf,(uint16_t)unaff_SS,
                                 CONCAT11(0x24,*(undefined1 *)
                                                ((int)*(undefined4 *)(agnt_o + 0x1d) + 1)),ringValue
                                );
    ovr_blitLabel((char *)text_00,puVar9,uVar14,uVar16);
  }
  else {
    damage = 0;
  }
  if ((*(uint *)((int)*(undefined4 *)(agnt_o + 0x17) + 0x14) & 2) != 0) {
    TextBlitY = 0x68;
    TextBlitX = 0x87;
    ovr_blitLabel((char *)"Mirror",(uint8_t *)((char *)"puppetmaker" + 3),Font02.ofs,
                  (uint8_t)Font02.seg);
  }
  if (GameRunning != false) {
    ovr_setSeasonPalette(cmap);
  }
  return;
}



/* 6386:12b7 */

/* Formats the ready/not-ready line for an agent. */

char * __cdecl16far stats_readyStatusText(byte agntIndex,char *text)

{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  undefined2 uVar4;
  char *in_stack_00000008;
  
  uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + 0x17);
  if ((*(byte *)((int)uVar1 + 0x33) & 1) == 0) {
    uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + 0x1d);
    uVar4 = (undefined2)((ulong)uVar1 >> 0x10);
    iVar3 = (int)uVar1;
    ovr_ovc15_usesStshRealloc
              ((char *)CONCAT22(*(undefined2 *)(iVar3 + 0x26),(char *)*(undefined2 *)(iVar3 + 0x24))
              );
    pcVar2 = ovr_stsprintf(text,in_stack_00000008,(char *)"  %s is not readied.");
  }
  else {
    uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + 0x1d);
    uVar4 = (undefined2)((ulong)uVar1 >> 0x10);
    iVar3 = (int)uVar1;
    ovr_ovc15_usesStshRealloc
              ((char *)CONCAT22(*(undefined2 *)(iVar3 + 0x26),(char *)*(undefined2 *)(iVar3 + 0x24))
              );
    pcVar2 = ovr_stsprintf(text,in_stack_00000008,(char *)"  %s is ready.");
  }
  return pcVar2;
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

/* Formats the "%s is no longer ready." notice and ready-list hint. */

void __cdecl16far stats_unreadyNotice(byte agnt_id)

{
  byte *pbVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  uint16_t uVar5;
  int iVar6;
  undefined2 uVar7;
  char *unaff_SS;
  uint8_t text;
  uint8_t msg;
  uint8_t unitFlags;
  int iStack_4;
  
  uVar2 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x17);
  uVar3 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x17);
  *(byte *)((int)uVar3 + 0x33) = *(byte *)((int)uVar2 + 0x33) ^ 1;
  uVar2 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x17);
  if ((*(byte *)((int)uVar2 + 0x33) & 1) == 0) {
    uVar2 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x17);
    pbVar1 = (byte *)((int)uVar2 + 0x33);
    *pbVar1 = *pbVar1 & 0xfb;
  }
  else {
    uVar2 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x17);
    stats_usesEntityCount(*(char *)((int)uVar2 + 0x1a));
    uVar2 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x17);
    pbVar1 = (byte *)((int)uVar2 + 0x33);
    *pbVar1 = *pbVar1 | 4;
    iStack_4 = *(int *)((uint)agnt_id * 0x34 + 0x1b);
    ovr_attact_usesEntities(iStack_4,0,0,(uint16_t)&unitFlags,(uint16_t)unaff_SS);
  }
  uVar2 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x17);
  uVar3 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x17);
  *(byte *)((int)uVar3 + 0x33) = *(byte *)((int)uVar2 + 0x33) & 0xfd;
  drawAgntStats((agnt_t *)CONCAT22(0x1726,(agnt_t *)((uint)agnt_id * 0x34)),far_from_u32((uint32_t)(0x0)));
  uVar5 = 0x1726;
  uVar2 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x17);
  if ((*(byte *)((int)uVar2 + 0x33) & 1) == 0) {
    uVar5 = 0x1726;
    uVar2 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x1d);
    uVar7 = (undefined2)((ulong)uVar2 >> 0x10);
    iVar6 = (int)uVar2;
    ovr_ovc15_usesStshRealloc
              ((char *)CONCAT22(*(undefined2 *)(iVar6 + 0x26),(char *)*(undefined2 *)(iVar6 + 0x24))
              );
    pcVar4 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%s is no longer ready.");
    drawString(pcVar4,uVar5);
  }
  else {
    stats_readyStatusText(agnt_id,(char *)&text);
    pcVar4 = ovr_stsprintf((char *)&msg,unaff_SS,
                           (char *)"Ready characters are the first to come when attracted.%s");
    drawString(pcVar4,uVar5);
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
  undefined2 uVar5;
  
  uVar5 = (undefined2)((ulong)Entities >> 0x10);
  if ((*(byte *)((int)&((entity_t *)Entities)[entityIndex].base.flags32 + 1) & 2) == 0) {
    uVar2 = 0;
  }
  else {
    uVar1 = ovr_alignUp4((((entity_t *)Entities + entityIndex)->base).x);
    uVar2 = ovr_alignUp4(GfxRndSeed);
    if (uVar1 == uVar2) {
      uVar5 = (undefined2)((ulong)Entities >> 0x10);
      uVar2 = ((entity_t *)Entities)[entityIndex].base.y;
      if (uVar2 == GfxRndSeed2) {
        uVar1 = ovr_alignUp4(((entity_t *)Entities)[entityIndex].base.targetX);
        uVar2 = ovr_alignUp4(GfxRndSeed);
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

/* Sets the agent's entity position to the cursor cell and reports the new base. */

void __cdecl16far stats_setAgentBase(byte agntIndex)

{
  byte *pbVar1;
  int entityIndex;
  uint16_t uVar2;
  char *text;
  undefined2 uVar3;
  char *unaff_SS;
  uint8_t msg;
  int iStack_c;
  undefined2 uStack_a;
  uint8_t unitFlags;
  
  entityIndex = *(int *)((uint)agntIndex * 0x34 + 0x1b);
  uStack_a = *(undefined2 *)((uint)agntIndex * 0x34 + 0x1f);
  iStack_c = *(int *)((uint)agntIndex * 0x34 + 0x1d);
  uVar2 = ovr_ovc23_compute2(GfxRndSeed,GfxRndSeed2);
  (((entity_t *)Entities + entityIndex)->base).x = uVar2;
  ((entity_t *)Entities)[entityIndex].base.y = GfxRndSeed2;
  uVar3 = (undefined2)((ulong)Entities >> 0x10);
  ((entity_t *)Entities)[entityIndex].base.targetX = (((entity_t *)Entities + entityIndex)->base).x;
  ((entity_t *)Entities)[entityIndex].base.targetY = GfxRndSeed2;
  pbVar1 = (byte *)((int)&((entity_t *)Entities)[entityIndex].base.flags32 + 1);
  *pbVar1 = *pbVar1 | 2;
  uVar2 = 0x2410;
  pbVar1 = (byte *)((int)&((entity_t *)Entities)[entityIndex].base.flags32 + 1);
  *pbVar1 = *pbVar1 & 0xfa;
  ovr_attact_usesEntities(entityIndex,0,0,(uint16_t)&unitFlags,(uint16_t)unaff_SS);
  ovr_alignUp4(GfxRndSeed);
  ovr_ovc15_usesStshRealloc
            ((char *)CONCAT22(*(undefined2 *)(iStack_c + 0x26),
                              (char *)*(undefined2 *)(iStack_c + 0x24)));
  text = ovr_stsprintf((char *)&msg,unaff_SS,
                       (char *)
                       "%s is now based at (%d, %d). This unit will remain home when attracted.");
  drawString(text,uVar2);
  drawAgntStats((agnt_t *)CONCAT22(0x1726,(agnt_t *)((uint)agntIndex * 0x34)),far_from_u32((uint32_t)(0x0)));
  return;
}



/* 6386:1837 */

/* Formats the "%s can now be called away from home." notice. */

void __cdecl16far stats_calledAwayNotice(byte agntIndex)

{
  byte *pbVar1;
  int entityIndex;
  uint16_t uVar2;
  char *text;
  undefined2 uVar3;
  char *unaff_SS;
  uint8_t msg;
  int iStack_c;
  undefined2 uStack_a;
  uint8_t unitFlags;
  
  entityIndex = *(int *)((uint)agntIndex * 0x34 + 0x1b);
  uStack_a = *(undefined2 *)((uint)agntIndex * 0x34 + 0x1f);
  iStack_c = *(int *)((uint)agntIndex * 0x34 + 0x1d);
  uVar2 = ovr_ovc23_compute2(GfxRndSeed,GfxRndSeed2);
  (((entity_t *)Entities + entityIndex)->base).x = uVar2;
  ((entity_t *)Entities)[entityIndex].base.y = GfxRndSeed2;
  uVar3 = (undefined2)((ulong)Entities >> 0x10);
  ((entity_t *)Entities)[entityIndex].base.targetX = (((entity_t *)Entities + entityIndex)->base).x;
  ((entity_t *)Entities)[entityIndex].base.targetY = GfxRndSeed2;
  uVar2 = 0x2410;
  pbVar1 = (byte *)((int)&((entity_t *)Entities)[entityIndex].base.flags32 + 1);
  *pbVar1 = *pbVar1 & 0xfd;
  ovr_attact_usesEntities(entityIndex,0,0,(uint16_t)&unitFlags,(uint16_t)unaff_SS);
  ovr_ovc15_usesStshRealloc
            ((char *)CONCAT22(*(undefined2 *)(iStack_c + 0x26),
                              (char *)*(undefined2 *)(iStack_c + 0x24)));
  text = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%s can now be called away from home.");
  drawString(text,uVar2);
  drawAgntStats((agnt_t *)CONCAT22(0x1726,(agnt_t *)((uint)agntIndex * 0x34)),far_from_u32((uint32_t)(0x0)));
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
  ovr_ovc15_usesStExit(*(int *)((uint)agntIndex * 0x34 + 0x1b));
  return;
}



/* 6386:1abe */

/* Opens the agent detail page: ScreenMode 2, drawAgntStats and the detail text. */

void __cdecl16far stats_openAgentDetail(int agntIndex)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(agntIndex * 0x34 + 0x1b);
  ovr_manage_openTalkWindow();
  ScreenMode = 2;
  drawAgntStats((agnt_t *)CONCAT22(0x1726,(agnt_t *)(agntIndex * 0x34)),far_from_u32((uint32_t)(0x0)));
  drawString((char *)"short sword" + 0xb,0x2410);
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
    ovr_play_sfx(CONCAT11(0x24,CurMusicType),0);
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
  char cVar2;
  byte bVar3;
  uint uVar4;
  char *pcVar5;
  ulong *puVar6;
  uint uVar7;
  uint8_t *puVar8;
  uint16_t uVar9;
  uint16_t *puVar10;
  int *piVar11;
  undefined2 *puVar12;
  int iVar13;
  undefined2 unaff_DI;
  undefined2 uVar14;
  undefined2 uVar15;
  uint16_t unaff_SS;
  undefined1 uVar16;
  undefined1 uVar17;
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
  
  if (AgntCount <= agntIndex) {
    return AgntCount;
  }
  gfx_00.seg = FontHandle.seg;
  gfx_00.ofs = FontHandle.ofs;
  ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)(0xa000c31d)));
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
    piVar11 = (int *)((uint)bStack_3 * 0x94 + (uint)*(byte *)((int)uVar1 + 0xf) * 4);
    if (*piVar11 != 0 || piVar11[1] != 0) {
      uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + 0x17);
      puVar12 = (undefined2 *)((uint)bStack_3 * 0x94 + (uint)*(byte *)((int)uVar1 + 0xf) * 4);
      uVar15 = *puVar12;
      uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + 0x17);
      uVar14 = (undefined2)((ulong)uVar1 >> 0x10);
      iVar13 = (int)uVar1;
      *(undefined2 *)(iVar13 + 0x12) = puVar12[1];
      *(undefined2 *)(iVar13 + 0x10) = uVar15;
      uVar15 = *(undefined2 *)((uint)agntIndex * 0x34 + 0x19);
      ovr_ovc41_compute3(CONCAT13((char)((uint)uVar15 >> 8),
                                  CONCAT12((char)uVar15,
                                           *(undefined2 *)((uint)agntIndex * 0x34 + 0x17))));
    }
  }
  iVar13 = *(int *)((uint)agntIndex * 0x34 + 0x1b);
  stats_openAgentDetail((uint)agntIndex);
  uVar15 = (undefined2)((ulong)Entities >> 0x10);
  if (((entity_t *)Entities)[iVar13].base.targetY == GfxRndSeed2) {
    uVar4 = ovr_alignUp4(((entity_t *)Entities)[iVar13].base.targetX);
    uVar16 = (undefined1)uVar4;
    uVar17 = (undefined1)(uVar4 >> 8);
    uVar4 = ovr_alignUp4(GfxRndSeed);
    if (CONCAT11(uVar17,uVar16) == uVar4) {
      uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + 0x17);
      ovr_ovc39_textHalflingCastle(*(byte *)((int)uVar1 + 0x1a));
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
  puVar8 = (uint8_t *)((int)&AgntAnms[0x75].halfWidth + 1);
  if (*(char *)*(undefined4 *)((uint)agntIndex * 0x34 + 0x1d) == '\0') {
    menuBarShown = 1;
  }
  entries_00.seg = unaff_SS;
  entries_00.ofs = (uint16_t)&entries;
  pcVar5 = ovr_uiInputText(entries_00,5,far_from_u32((uint32_t)(0x0)),0x0);
  bStack_4 = (byte)pcVar5;
  menuBarShown = 0;
  if ((bStack_4 != 0) && (bStack_4 < 10)) {
    puVar8 = &permTable;
    bStack_4 = puVar8[(uint)pcVar5 & 0xff];
  }
  cStack_5 = '\0';
  cStack_6 = '\0';
  uVar4 = (uint)bStack_4;
  if (uVar4 == 6) {
    cStack_6 = '\x01';
    cStack_5 = '\x01';
  }
  else if (uVar4 < 7) {
    uVar7 = 5;
    switch(uVar4) {
    case 0:
      menuBarShown = 0;
      uVar4 = 5;
      Agnts[5].x = 0x2b;
      Agnts[5].y = 2;
      do {
        bStack_3 = 1;
        while( true ) {
          uVar4 = uVar4 + 1;
          uVar7 = (uint)AgntCount;
          if ((int)uVar7 <= (int)uVar4) {
            ovr_agnt_usesAlignToSeg();
            bVar3 = (byte)uVar7;
            ovr_agnt_usesAlignToSeg();
            ovr_agnt_usesAlignToSeg();
            ovr_agnt_usesAlignToSeg();
            return bVar3;
          }
          uVar1 = *(undefined4 *)(uVar4 * 0x34 + 0x1d);
          uVar7 = uVar4;
          if (*(char *)((int)uVar1 + 1) == '\x02') break;
          uVar1 = *(undefined4 *)(uVar4 * 0x34 + 0x1d);
          if (*(char *)((int)uVar1 + 1) == '\x01') {
            *(undefined2 *)(uVar4 * 0x34) = 0x3d;
            *(undefined2 *)(uVar4 * 0x34 + 2) = 0x12;
          }
          else {
            uVar1 = *(undefined4 *)(uVar4 * 0x34 + 0x1d);
            if (*(char *)((int)uVar1 + 1) == '\v') {
              *(undefined2 *)(uVar4 * 0x34) = 0x56;
              *(undefined2 *)(uVar4 * 0x34 + 2) = 0x14;
            }
          }
        }
switchD_6000_58bf_caseD_5:
        *(undefined2 *)(uVar4 * 0x34) = 0x6e;
        *(undefined2 *)(uVar7 * 0x34 + 2) = 0xb;
        uVar4 = uVar7;
      } while( true );
    case 1:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 2:
      uVar15 = (undefined2)
               ((ulong)*(undefined4 *)((undefined *)&GfxFramePtrs + (uint)gfxIndex * 4) >> 0x10);
      puVar10 = (uint16_t *)
                ((int)*(undefined4 *)((undefined *)&GfxFramePtrs + (uint)gfxIndex * 4) +
                (uint)bStack_3 * 4);
      gfx.seg = puVar10[1];
      gfx.ofs = *puVar10;
      ovr_blitGfxRect(gfx,x,y,rect,(uint8_t)type,true);
      (*(uint8_t *)((uint8_t *)&(AnimSeqPtr[0].seg))) = bStack_3 + 1;
      GAnimPlaying = 1;
      return bStack_3 + 1;
    case 3:
      uVar16 = 0x10;
      uVar17 = 0x24;
      bStack_3 = '\0';
      do {
        pcVar5 = ovr_draw_textProvidesMoreHousing();
      } while ((char)pcVar5 != '\0');
      while( true ) {
        uVar9 = *(uint16_t *)BDA_DailyTimeCounter;
        if ((*(uint16_t *)(BDA_DailyTimeCounter.ofs + 2) != InputEventTime.hi) ||
           (uVar9 != InputEventTime.lo)) {
          InputEventTime.hi = *(uint16_t *)(BDA_DailyTimeCounter.ofs + 2);
          uVar9 = *(uint16_t *)BDA_DailyTimeCounter;
          InputEventTime.lo = uVar9;
          ovr_draw_usesPrintf();
        }
        pcVar5 = ovr_draw_textProvidesMoreHousing();
        bStack_4 = (byte)pcVar5;
        if (bStack_4 != 0) break;
        puVar6 = ovr_attact_usesBDADailyTimeCounter
                           ((ulong *)TextBlitCycle,CONCAT22(unaff_DI,CONCAT11(uVar17,uVar16)));
        if ((uVar9 != 0) || ((ulong *)(uint)agntIndex <= puVar6)) break;
      }
      if (bStack_3 != '\0') {
        ovr_miceRestoreArea((brect_t *)(BlitRects + 1));
      }
      return bStack_4;
    case 4:
      in(puVar8);
      ovr_draw_freeRingBuffers();
      ovr_stop_audio();
      savedMenuItem = GMenuItem;
      MenuModeSaved = MenuMode;
      gfx_01.seg = nwpanel1Cut2Seg;
      gfx_01.ofs = nwpanel1Cut2Ofs;
      ovr_blitLoadRleGfx(gfx_01,far_from_u32((uint32_t)(0xa000e249)));
      gfx_02.seg = trianglsCut6Seg;
      gfx_02.ofs = trianglsCut6Ofs;
      ovr_blitLoadRleGfx(gfx_02,far_from_u32((uint32_t)(0xa000e249)));
      ovr_uiMainMenuLoop();
      gfx_03.seg = nwpanel1Cut2Seg;
      gfx_03.ofs = nwpanel1Cut2Ofs;
      ovr_blitLoadRleGfx(gfx_03,far_from_u32((uint32_t)(0xa000e249)));
      bVar3 = 0x10;
      gfx_04.seg = trianglsCut5Seg;
      gfx_04.ofs = trianglsCut5Ofs;
      ovr_blitLoadRleGfx(gfx_04,far_from_u32((uint32_t)(0xa000e249)));
      ovc41_usesGMenuItem();
      return bVar3;
    case 5:
      goto switchD_6000_58bf_caseD_5;
    }
  }
  else if (uVar4 == 0xfc) {
    uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + 0x17);
    if ((*(byte *)((int)uVar1 + 0x33) & 1) == 0) {
      stats_unreadyNotice(agntIndex);
    }
  }
  else if (uVar4 < 0xfd) {
    if (uVar4 == 7) {
      uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + 0x17);
      if (*(char *)((int)uVar1 + 0x1a) != -1) {
        ovr_stop_audio();
        CurMusicType = 0xff;
        uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + 0x17);
        ovr_manage_settlementScreen(*(byte *)((int)uVar1 + 0x1a));
        if (Cancelled == 0) {
          iVar13 = *(int *)((uint)agntIndex * 0x34 + 0x1b);
          stats_openAgentDetail((uint)agntIndex);
          uVar15 = (undefined2)((ulong)Entities >> 0x10);
          if (((entity_t *)Entities)[iVar13].base.targetY == GfxRndSeed2) {
            uVar4 = ovr_alignUp4(((entity_t *)Entities)[iVar13].base.targetX);
            uVar16 = (undefined1)uVar4;
            uVar17 = (undefined1)(uVar4 >> 8);
            uVar4 = ovr_alignUp4(GfxRndSeed);
            if (CONCAT11(uVar17,uVar16) == uVar4) {
              uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + 0x17);
              ovr_ovc39_textHalflingCastle(*(byte *)((int)uVar1 + 0x1a));
            }
          }
        }
        else {
          cStack_5 = '\x01';
        }
      }
    }
    else {
      if (uVar4 == 8) goto L_stats_6386_1c9f_20C5;
      if (uVar4 == 9) {
        ovr_ovc50_usesUiInputText();
        cStack_6 = '\x01';
      }
    }
  }
  else if (uVar4 == 0xfd) {
L_stats_6386_1c9f_20C5:
    uVar4 = stats_usesAlignUp4(*(int *)((uint)agntIndex * 0x34 + 0x1b));
    if ((uVar4 & 0xff) == 0) {
      stats_setAgentBase(agntIndex);
    }
  }
  else if (uVar4 == 0xfe) {
    uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + 0x17);
    if ((*(byte *)((int)uVar1 + 0x33) & 1) != 0) {
      stats_unreadyNotice(agntIndex);
    }
    uVar4 = stats_usesAlignUp4(*(int *)((uint)agntIndex * 0x34 + 0x1b));
    if ((char)uVar4 != '\0') {
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
    bVar3 = Cancelled;
    stats_openCastlePanel();
    ovr_ovc41_usesGMenuItem();
    return bVar3;
  }
  goto L_stats_6386_1c9f_1E1D;
}



/* 6386:22fd */

/* Opens the stats page for the agent under the screen point (video_findAgentAt) and returns whether
   one was hit. */

bool __cdecl16far stats_selectAgentAt(uint16_t x,uint16_t y)

{
  int iVar1;
  int16_t unaff_BP;
  int16_t in_stack_00000000;
  brect_t *in_stack_00000002;
  
  iVar1 = video_findAgentAt(x,y);
  if (iVar1 != -1) {
    stats_usesAlignUp42((byte)iVar1,(byte)iVar1,unaff_BP,in_stack_00000000,in_stack_00000002,x);
  }
  return iVar1 != -1;
}



/* 6386:232d */

/* Opens the castle status panel with its palette and five menu bars. */

void __cdecl16far stats_openCastlePanel(void)

{
  far_t gfx;
  far_t gfx_00;
  far_t ptr;
  far_t handle;
  far_t handle_00;
  uint16_t in_DX;
  int menuIndex;
  uint16_t unaff_SS;
  uint8_t type;
  undefined1 uVar1;
  uint8_t palette;
  stg_tmp_t *psStack_14;
  uint8_t dst;
  uint uStack_e;
  uint uStack_c;
  uint uStack_a;
  void *pvStack_6;
  uint16_t uStack_4;
  
  MiceNeedsUpdate = 1;
  pvStack_6 = ovr_stshAlloc(0xfa0f);
  (*(uint8_t *)((uint8_t *)&(ptr.seg))) = (char)in_DX;
  ptr.ofs = (uint16_t)pvStack_6;
  (*(uint8_t *)((uint8_t *)&(ptr.seg) + 1)) = (char)(in_DX >> 8);
  uStack_4 = in_DX;
  ovr_alignToSeg(ptr);
  uStack_e = 7;
  uStack_a = 0xc2;
  _dst = 8;
  uStack_c = 0xe2;
  ovr_driver_fillRect(8,7,0xe2,0xc2,0x0,in_DX);
  type = (uint8_t)unaff_SS;
  uVar1 = (undefined1)(unaff_SS >> 8);
  gfx_00.seg = fullScreenGfxSeg;
  gfx_00.ofs = fullScreenGfxOfs;
  ovr_blitGfx10(gfx_00,0,0,(brect_t *)CONCAT13(uVar1,CONCAT12(type,&dst)),false);
  gfx.seg = nwpanel2Cut1Seg;
  gfx.ofs = nwpanel2Cut1Ofs;
  ovr_blitGfxRect(gfx,0,0,(brect_t *)&dst,type,true);
  (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)Lbm_nwpanel1.seg;
  handle.ofs = Lbm_nwpanel1.ofs;
  (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)(Lbm_nwpanel1.seg >> 8);
  psStack_14 = ovr_stshLoadGfx(handle);
  ovr_calcSeasonPalette(psStack_14->cmap,in_DX,&palette,unaff_SS);
  ovr_driver_fillRect(_dst,uStack_e,uStack_c,uStack_a,0x0,0xa000);
  ovr_vgaSetPalette8bit((uint8_t *)CONCAT13(uVar1,CONCAT12(type,&palette)));
  ovr_blitRect((brect_t *)&dst);
  TextBlitDstSeg = 0xa000;
  ovr_ovc28_textHalflingCastle();
  for (menuIndex = 0; menuIndex < 5; menuIndex = menuIndex + 1) {
    ovr_draw_usesBlitLoadRleGfx3(menuIndex);
    ovr_draw_menuRowBar(menuIndex,0xa000);
  }
  mapViewActive = 0xff;
  ovr_attact_usesLDIV_at_2();
  (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = (char)uStack_4;
  handle_00.ofs = (uint16_t)pvStack_6;
  (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = (char)(uStack_4 >> 8);
  ovr_stshFree(handle_00);
  ovr_stop_audio();
  CurMusicType = 0xff;
  ScreenMode = 0;
  return;
}



/* 6386:24c2 */

void __cdecl16far drawString(char *text,uint16_t widths)

{
  uint uVar1;
  size_t sVar2;
  undefined2 unaff_SS;
  far_t gfx;
  uint8_t rect;
  uint16_t uStack_a;
  int16_t iStack_8;
  int16_t iStack_6;
  
  memcpy((char *)CONCAT22(unaff_SS,&rect),(char *)(BlitRects + 1),10);
  if (ScreenMode == '\x01') {
    uStack_a = 0x9c;
    iStack_6 = 190;
  }
  else {
    uStack_a = 0x75;
    if (GameRunning == false) {
      iStack_6 = 178;
    }
    else {
      iStack_6 = 150;
    }
  }
  _rect = 19;
  iStack_8 = 215;
  TextBlitFlag = 1;
  TextBlitDstSeg = 0xa000;
  gfx.seg = talkwin9Cut4Seg;
  gfx.ofs = talkwin9Cut4Ofs;
  ovr_blitGfxRect(gfx,0,0,(brect_t *)&rect,(uint8_t)unaff_SS,true);
  TextBlitY = uStack_a;
  while( true ) {
    TextBlitX = 0x13;
    uVar1 = ovr_blitText(text,(byte *)widths,Font03.ofs,(uint8_t)Font03.seg);
    sVar2 = strlen(text);
    if (sVar2 <= uVar1) break;
    text = text + uVar1;
    TextBlitY = TextBlitY + 0xb;
  }
  ovr_clean_ring_buffer();
  return;
}


