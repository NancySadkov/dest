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
  uint16_t uVar3;
  
  uVar3 = (uint16_t)((ulong)agnt >> 0x10);
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
  uint16_t uVar3;
  
  uVar3 = (uint16_t)((ulong)agnt >> 0x10);
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
  
  gfx.seg = fullScreenGfxSeg;
  gfx.ofs = fullScreenGfxOfs;
  ovr_blitGfx10(gfx,0,0,(brect_t *)0x5ce5,true,0,0);
  gfx_00.seg = nwpanel1Cut3Seg;
  gfx_00.ofs = nwpanel1Cut3Ofs;
  ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)(0xa0000adf)),0);
  return;
}



/* 6386:013d */

/* [R7] body shape: compute */

undefined1 __cdecl16far stats_compute3(agnt_t *agnt)

{
  undefined1 result;
  agnt_t *paVar2;
  uint16_t uVar3;
  
  uVar3 = (uint16_t)((ulong)agnt >> 0x10);
  paVar2 = (agnt_t *)agnt;
  if ((((agntG_t *)paVar2->gdata)->shortName[3] == '\x04') &&
     (0xb < (((entity_t *)paVar2->entity)->base).level)) {
    result = 1;
  }
  else if ((((agntG_t *)paVar2->gdata)->shortName[3] == '\x05') &&
          (9 < (((entity_t *)paVar2->entity)->base).level)) {
    result = 1;
  }
  else if ((((agntG_t *)paVar2->gdata)->shortName[3] == '\x06') &&
          (7 < (((entity_t *)paVar2->entity)->base).level)) {
    result = 1;
  }
  else {
    result = 0;
  }
  return result;
}



/* 6386:01a4 */

/* Draws the portrait of an agent type with the season palette. */

void __cdecl16far stats_drawPortrait(agntG_t *gdata,byte portraitIndex,int palette)

{
  far_t handle;
  far_t handle_00;
  stg_tmp_t *gfxRec;
  uint16_t in_DX;
  agntG_t *paVar2;
  uint16_t uVar3;
  uint16_t in_stack_0000000c;
  far_t gfx;
  undefined1 uVar4;
  
  handle.seg = talkwin9Cut5Seg;
  handle.ofs = talkwin9Cut5Ofs;
  gfxRec = ovr_stshLoadGfx(handle);
  ovr_calcSeasonPalette
            (gfxRec->cmap,in_DX,(uint8_t *)palette,in_stack_0000000c,(char)in_DX,(char)palette);
  uVar3 = (uint16_t)((ulong)gdata >> 0x10);
  paVar2 = (agntG_t *)gdata;
  if (((paVar2->prts + portraitIndex)->ofs != 0 || paVar2->prts[portraitIndex].seg != 0) &&
     ((paVar2->prtpals + portraitIndex)->ofs != 0 || paVar2->prtpals[portraitIndex].seg != 0)) {
    handle_00.seg = paVar2->prtpals[portraitIndex].seg;
    handle_00.ofs = (paVar2->prtpals + portraitIndex)->ofs;
    gfxRec = ovr_stshLoadGfx(handle_00);
    uVar4 = (undefined1)(in_DX >> 8);
    memcpy((char *)CONCAT22(in_stack_0000000c,(char *)(palette + 3)),
           (char *)CONCAT13(uVar4,CONCAT12((char)in_DX,gfxRec->cmap + 3)),0xed);
    memcpy((char *)CONCAT22(in_stack_0000000c,(char *)(palette + 0x1e0)),
           (char *)CONCAT13(uVar4,CONCAT12((char)in_DX,gfxRec->cmap + 0x1e0)),0x90);
  }
  if (GameRunning == false) {
    ovr_vgaSetPalette8bit((uint8_t *)palette,in_stack_0000000c);
  }
  if ((paVar2->prts + portraitIndex)->ofs != 0 || paVar2->prts[portraitIndex].seg != 0) {
    ovr_driver_fillRect(0xf,9,0x83,0x72,0xec,0xa000,0x72,0xec,0,0,0);
    gfx.seg = paVar2->prts[portraitIndex].seg;
    gfx.ofs = (paVar2->prts + portraitIndex)->ofs;
    ovr_blitGfxRect(gfx,16,10,(brect_t *)(BlitRects + 1),0x10,true,0x10,0x10,0,0,0,0);
  }
  return;
}



/* 6386:02db */
char * __cdecl16far agntCopyNthField(uint8_t filed_index,char *dst,char *src)

{
  int packed;
  char *pcVar2;
  bool bVar3;
  uint16_t len;
  uint16_t i;
  uint8_t in_stack_00000004;
  undefined1 in_stack_00000007;
  uint8_t j;
  uint8_t found;
  
  packed = CONCAT11(in_stack_00000007,filed_index);
  j = 0x0;
  bVar3 = false;
  i = 0;
  while( true ) {
    in_stack_00000007 = (undefined1)((uint)packed >> 8);
    filed_index = (uint8_t)packed;
    pcVar2 = (char *)src;
    len = strlen((char *)CONCAT22(pcVar2,(*(uint16_t *)((uint8_t *)&(dst) + 2))));
    packed = CONCAT11(in_stack_00000007,filed_index);
    if (len <= i) break;
    if ((*(char *)((int)*(uint16_t *)((uint8_t *)&(dst) + 2) + i)) == ',') {
      j = j + 0x1;
      packed = CONCAT11(in_stack_00000007,filed_index);
      if (bVar3) break;
    }
    else if (j == in_stack_00000004) {
      *(char *)((int)*(uint16_t *)((uint8_t *)&(dst) + 2) + (int)(char)CONCAT11(in_stack_00000007,filed_index)) = (*(char *)((int)*(uint16_t *)((uint8_t *)&(dst) + 2) + i));
      packed = CONCAT11(in_stack_00000007,filed_index) + 1;
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
  uint32_t uVar1;
  uint16_t tofs;
  uint16_t unaff_BP;
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
    uVar1 = *(uint32_t *)(CONCAT11(in_stack_0000000f,field_index) + 0x1d);
    if ((*(uint *)((int)uVar1 + 0x40) & 0x4000) == 0) {
      tofs = (uint)(*(uint8_t *)((uint8_t *)&(dst) + 2)) * 0x95;
      agntCopyNthField((uint8_t)in_stack_00000004,
                       (char *)CONCAT22(*(uint16_t *)((int)&AgntGs[0].wpn_name + tofs),(char *)dst
                                       ),
                       (char *)CONCAT22(unaff_BP,(char *)*(uint16_t *)
                                                          ((int)&AgntGs[0].wpn_name + 2 + tofs)));
    }
    else {
      strcpy((char *)CONCAT22((char *)dst,in_stack_00000004),"short sword");
    }
  }
  return in_stack_00000004;
}



/* 6386:0411 */
far_t * __cdecl16far stats_textRingProt(char *dst,uint16_t src,uint16_t term,far_t ringValue)

{
  undefined1 stk_fffe;   /* stack slot fffe */
  char *pcVar1;
  uint *puVar2;
  int *piVar3;
  uint16_t *puVar4;
  byte *pbVar5;
  long lVar6;
  code *intVector;
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
  char *textPtr;
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
  uint16_t in_DX;
  uint16_t uVar30;
  byte *pbVar31;
  uint16_t *puVar32;
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
  uint16_t unaff_ES;
  uint16_t uVar43;
  uint16_t uVar44;
  bool bVar45;
  byte in_AF;
  longdouble in_ST0;
  uint32_t uVar46;
  uint16_t in_stack_00000002;
  byte in_stack_00000004;
  undefined1 in_stack_00000005;
  uint8_t auStack_314 [72];
  char acStack_2cc [588];
  char acStack_80 [110];
  uint16_t uStack_12;
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
      (&stk_fffe)[(int)unaff_SI] = (&stk_fffe)[(int)unaff_SI] + '\x01';
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    case 1:
      intVector = (code *)swi(1);
      pfVar18 = (far_t far *)(*intVector)();
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
    (&stk_fffe)[(int)unaff_DI] = (&stk_fffe)[(int)unaff_DI] + (byte)in_CX;
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
    uVar11 = (undefined1)_SS;
    uVar47 = (undefined1)((uint)_SS >> 8);
    switch((uint16_t)pbVar21)   /* hand fix: case values are ints */ {
    case (uint16_t)0x0:
      ovr_vgaSetPalette8bit(auStack_314,0);
      uVar11 = 0xa6;
      uVar47 = 0x22;
      ovr_blitRect((brect_t *)&iStack_10,0);
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
        textPtr = (char *)ovr_ovc45_compute9(acStack_80);
        in_stack_00000004 = (byte)in_DX;
        in_stack_00000005 = (undefined1)((uint)in_DX >> 8);
        ovr_blitLabel(textPtr);
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
          ovr_blitLoadRleGfx(gfx,src,0);
          TextBlitDstSeg = 0xa000;
          TextBlitX = CONCAT11(uVar49,uVar48) + 6;
          TextBlitY = (uint16_t)(pbVar21 + 0x10);
          puVar32 = (uint16_t *)
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
            textPtr = (char *)ovr_ovc45_compute9(acStack_80);
            in_stack_00000004 = (byte)in_DX;
            in_stack_00000005 = (undefined1)((uint)in_DX >> 8);
            pfVar18 = (far_t far *)ovr_blitLabel(textPtr);
            pbVar21 = unaff_DI;
          }
          else {
            src = far_ofs_u32((uint32_t)(0xf013f));
            (*(uint16_t *)((uint8_t *)&(dst))) =(uint16_t)( (char *)FontMain.ofs);
            in_stack_00000004 = 3;
            in_stack_00000005 = 0;
            uVar48 = uVar11;
            uVar49 = uVar47;
            textPtr = (char *)ovr_ovc45_compute9(acStack_80);
            in_stack_00000004 = (byte)in_DX;
            in_stack_00000005 = (undefined1)((uint)in_DX >> 8);
            pfVar18 = (far_t far *)ovr_blitLabel(textPtr);
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
      puVar39 = &stk_fffe + uVar13 + uVar20;
      puVar2 = (uint *)(puVar39 + (int)unaff_DI + -0x58ef);
      uVar15 = (uint)(CARRY2((uint)&stk_fffe,uVar13) ||
                     CARRY2((uint)(&stk_fffe + uVar13),uVar20));
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
      (void)0;
      puVar4 = (uint16_t *)((int)&unaff_SI->ofs + (int)*pasVar34);
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
        intVector = (code *)swi(3);
        pfVar18 = (far_t far *)(*intVector)();
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
      *(uint16_t *)0xa813 = in_stack_00000002;
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
      uVar44 = *(uint16_t *)(uVar15 + iVar41 + 2);
      puVar36 = (uint *)(uVar15 + iVar41 + 4);
      intVector = (code *)swi(0x1e);
      uVar46 = (*intVector)();
      uVar43 = (uint16_t)((ulong)uVar46 >> 0x10);
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
      { int _rep0; for (_rep0 = 0; _rep0 < 18; _rep0++)
          pbVar31[(int)piVar33] = pbVar31[(int)piVar33] + cVar22;
      }
      pbVar42[-0x75] = pbVar42[-0x75] + bVar28;
      in(uVar43);
      *(uint16_t *)((int)puVar40 + -6) =(uint16_t)( piVar33);
      iVar29 = *(int *)(puVar39 + 6);
      do {
        iVar41 = iVar29 + -1;
        if (iVar29 == 0) {
          return (far_t far *)0x0;
        }
        uVar30 = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
        *(uint16_t *)(puVar39 + -2) = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
        *(uint16_t *)(puVar39 + -4) = uVar30;
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
           AgntGs[(uint)in_stack_00000004].ai;
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
      uVar30 = (uint16_t)(CONCAT13(in_stack_0000fffd,CONCAT12(in_stack_0000fffc,iVar29)) >> 0x10);
      *(uint16_t *)(iVar29 + 0x58) = 0;
      *(uint16_t *)(iVar29 + 0x56) = 100;
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
            uVar43 = (uint16_t)((ulong)GUnits >> 0x10);
            puVar35 = (unit_t *)GUnits;
          } while ((((*(uint *)((uint)(puVar35 + (int)pfVar18)->bldType * 0x27 + 0x121) & 0x60) != 0
                    ) || (puVar35[(int)pfVar18].unitType == 0xff)) ||
                  (uVar46 = *(uint32_t *)((uint)puVar35[(int)pfVar18].unitType << 2),
                  *(char *)((int)uVar46 + 0x3f) != '\0'));
          in_stack_0000fffa = (undefined1)uVar30;
          in_stack_0000fffb = (char)((uint)uVar30 >> 8);
          uVar30 = 0x2379;
          uVar20 = ovr_alignUp4(puVar35[(int)pfVar18].x,0,0);
          in_stack_0000fff8 = (byte)uVar20;
          in_stack_0000fff9 = (undefined1)(uVar20 >> 8);
          in_stack_0000fff6 = ((unit_t *)GUnits)[CONCAT11(in_stack_0000fffb,in_stack_0000fffa)].y;
          unaff_DI = (byte *)0x0;
          unaff_SI = (far_t far *)0x0;
        }
        unaff_ES = (uint16_t)((ulong)GMapFlags >> 0x10);
        pasVar34 = *(short (*) [60] [148])GMapFlags + in_stack_0000fff6;
        pbVar21 = (byte *)((int)((int)&unaff_SI->ofs + CONCAT11(in_stack_0000fff9,in_stack_0000fff8)
                                ) * 2);
      } while( true );
    case (byte *)0x8:
      uVar30 = _DS;
      if (((char_sheet_t *)(pbVar21))->income <
          (uint)-(GLeaderSheets[in_stack_00000004])->population) {
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
            ovr_drawString((char *)pfVar18,0,0);
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
            ovr_drawString((char *)pfVar18,0,0);
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
          ovr_drawString((char *)pfVar18,0,0);
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
        ovr_drawString((char *)pfVar18,0,0);
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


/* 6386:05d3 */

/* [R7] body shape: compute */

char __cdecl16far stats_compute4(agnt_t *agnt,uint16_t arg2)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  uint16_t uVar4;
  uint16_t in_stack_00000006;
  
  bVar1 = agnt->gindex;
  if (*(char *)((int)&worldMenuLabels[9].ofs + 1 + (uint)bVar1 * 0x95) == -1) {
    cVar3 = *(char *)((int)&worldMenuLabels[9].seg + (uint)bVar1 * 0x95);
  }
  else {
    bVar2 = ovr_agnt_compute10(agnt,in_stack_00000006);
    cVar3 = *(char *)((int)&worldMenuLabels[9].seg + (uint)bVar1 * 0x95) - bVar2;
    uVar4 = ovr_agnt_abilityModifier(*(byte *)((int)&agnt->entity + 3),3);
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
  long lVar2;
  
  if ((long)value < 1000000) {
    (*(uint16_t *)((uint8_t *)&(text))) = ovr_litoa10((char *)text,CONCAT22((uint16_t)value,(*(uint16_t *)((uint8_t *)&(text) + 2))),(*(uint16_t *)((uint8_t *)&(value) + 2)),0);
  }
  else {
    lVar2 = LDIV_at_(value,1000);
    ovr_litoa10((char *)text,CONCAT22((int)lVar2,(*(uint16_t *)((uint8_t *)&(text) + 2))),(int)((ulong)lVar2 >> 0x10),0);
    sVar1 = strlen(text);
    ((char *)text)[sVar1] = 'K';
    ((char *)text)[sVar1 + 1] = '\0';
  }
  return (char *)text;
}



/* 6386:06cd */

void __cdecl16far drawAgntStats(agnt_t *agnt,far_t cmap,uint16_t arg3)

{
  uint32_t uVar1;
  far_t gfx;
  far_t fVar2;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t ringValue;
  far_t palette;
  char cVar3;
  byte value;
  undefined1 uVar5;
  char *textPtr;
  uint uVar7;
  int *piVar8;
  uint16_t *puVar9;
  int iVar10;
  far_t *text_00;
  uint8_t *in_DX;
  uint8_t *nameOfs;
  uint16_t agnt_o;
  entity_t *peVar12;
  uint16_t agnt_s;
  uint16_t uVar13;
  char *in_stack_0000000a;
  undefined1 uVar14;
  undefined1 segHi;
  undefined1 uVar16;
  undefined1 byteLo;
  uint8_t *puVar18;
  uint16_t fontOfs;
  undefined1 uVar20;
  undefined1 fontHi;
  undefined1 uVar22;
  uint8_t uVar23;
  uint8_t attr;
  uint16_t uVar25;
  uint16_t uVar26;
  char palbuf [768];
  char buf [80];
  uint8_t text;
  uint8_t line;
  uint8_t field_index;
  byte bStack_4;
  int8_t damage;
  
  fVar2 = cmap;
  TextBlitDstSeg = 0xa000;
  if (cmap.seg == 0 && in_stack_0000000a == (char *)0x0) {
    cmap.seg = (uint16_t)palbuf;
    in_stack_0000000a = _SS;
  }
  if (!GameRunning) {
    stats_drawStatsPanel();
  }
  if (DebugVerbose != false) {
    printf("Exp %ld \r");
  }
  field_index = (*(uint *)((int)&(((entity_t *)agnt->entity)->base).frames + 3) & 1) != 0;
  bStack_4 = field_index;
  if (3 < (((entity_t *)agnt->entity)->base).level) {
    bStack_4 = field_index + 4;
  }
                    /* WARNING: Load size is inaccurate */
  stats_drawPortrait((agntG_t *)CONCAT22(*(uint16_t *)((int)&agnt->gdata + 2),agnt->gdata),
                     bStack_4,cmap.seg);
  TextBlitY = 10;
  TextBlitX = 0x87;
  uVar25 = 0xe0;
  uVar23 = 0xde;
  byteLo = (undefined1)Font02.seg;
  fontHi = (undefined1)(Font02.seg >> 8);
  uVar5 = (undefined1)fVar2.ofs;
  segHi = (*(uint8_t *)((uint8_t *)&(fVar2.ofs) + 1));
  fontOfs = Font02.ofs;
  textPtr = ovr_agnt_statusText(agnt,(char *)CONCAT13((char)((uint)&line >> 8),
                                                     CONCAT12((char)&line,cmap.ofs)),uVar5);
  ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,in_DX),CONCAT11(fontHi,byteLo),uVar23,byteLo,
                uVar23,uVar25);
  if ((GameRunning == false) && ((agnt->gdata->ai == 0 || (DebugVerbose != false)))) {
    TextBlitY = 0xb5;
    TextBlitX = 0x13;
    if ((*(byte *)((int)&(((entity_t *)agnt->entity)->base).flags32 + 1) & 1) == 0) {
      (*(uint8_t *)((uint8_t *)&(fVar2.seg))) = (char)butt01Cut3Seg;
      fVar2.ofs = butt01Cut3Ofs;
      (*(uint8_t *)((uint8_t *)&(fVar2.seg) + 1)) = (char)((uint)butt01Cut3Seg >> 8);
      ovr_blitGfxRect(fVar2,16,179,(brect_t *)(BlitRects + 1),0x10,true,0x10,0x10,0x10,0,0,0);
    }
    else {
      (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)butt01Cut4Seg;
      gfx.ofs = butt01Cut4Ofs;
      (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)((uint)butt01Cut4Seg >> 8);
      ovr_blitGfxRect(gfx,16,179,(brect_t *)(BlitRects + 1),0x10,true,0x10,0x10,0x10,0,0,0);
      TextBlitX = 0x47;
      ovr_blitLabel((char *)"\x7f",(uint8_t *)CONCAT22(Font01.ofs,(char *)0x26510),
                    Font01.seg,0xde,(char)Font01.seg,0xde,0xe0);
      TextBlitX = 0x13;
    }
    ovr_blitLabel((char *)"Ready",(uint8_t *)CONCAT22(Font01.ofs,(char *)0x26510),
                  Font01.seg,0xde,(char)Font01.seg,0xde,0xe0);
    TextBlitY = 0xb5;
    TextBlitX = 0x57;
    uVar7 = stats_usesAlignUp4(agnt->owner);
    if ((char)uVar7 == '\0') {
      (*(uint8_t *)((uint8_t *)&(gfx_01.seg))) = (char)butt01Cut3Seg;
      gfx_01.ofs = butt01Cut3Ofs;
      (*(uint8_t *)((uint8_t *)&(gfx_01.seg) + 1)) = (char)((uint)butt01Cut3Seg >> 8);
      ovr_blitGfxRect(gfx_01,84,179,(brect_t *)(BlitRects + 1),0x10,true,0x54,0x10,0x10,0,0,0);
    }
    else {
      (*(uint8_t *)((uint8_t *)&(gfx_00.seg))) = (char)butt01Cut4Seg;
      gfx_00.ofs = butt01Cut4Ofs;
      (*(uint8_t *)((uint8_t *)&(gfx_00.seg) + 1)) = (char)((uint)butt01Cut4Seg >> 8);
      ovr_blitGfxRect(gfx_00,84,179,(brect_t *)(BlitRects + 1),0x10,true,0x54,0x10,0x10,0,0,0);
      TextBlitX = 0x8b;
      ovr_blitLabel((char *)"\x7f",(uint8_t *)CONCAT22(Font01.ofs,(char *)0x26510),
                    Font01.seg,0xde,(char)Font01.seg,0xde,0xe0);
      TextBlitX = 0x57;
    }
    ovr_blitLabel((char *)"Home",(uint8_t *)CONCAT22(FontMain.ofs,(char *)0x26510),
                  FontMain.seg,0xde,(char)FontMain.seg,0xde,0xe0);
    TextBlitY = 0xb5;
    TextBlitX = 0x9b;
    uVar7 = stats_usesAlignUp4(agnt->owner);
    if (((uVar7 & 0xff) == 0) &&
       ((*(byte *)((int)&(((entity_t *)agnt->entity)->base).flags32 + 1) & 1) == 0)) {
      (*(uint8_t *)((uint8_t *)&(gfx_02.seg))) = (char)butt01Cut4Seg;
      gfx_02.ofs = butt01Cut4Ofs;
      (*(uint8_t *)((uint8_t *)&(gfx_02.seg) + 1)) = (char)((uint)butt01Cut4Seg >> 8);
      ovr_blitGfxRect(gfx_02,152,179,(brect_t *)(BlitRects + 1),0x10,true,0x98,0x10,0x10,0,0,0);
      TextBlitX = 0xcf;
      ovr_blitLabel((char *)"\x7f",(uint8_t *)CONCAT22(Font01.ofs,(char *)0x26510),
                    Font01.seg,0xde,(char)Font01.seg,0xde,0xe0);
      TextBlitX = 0x9b;
    }
    else {
      (*(uint8_t *)((uint8_t *)&(gfx_03.seg))) = (char)butt01Cut3Seg;
      gfx_03.ofs = butt01Cut3Ofs;
      (*(uint8_t *)((uint8_t *)&(gfx_03.seg) + 1)) = (char)((uint)butt01Cut3Seg >> 8);
      ovr_blitGfxRect(gfx_03,152,179,(brect_t *)(BlitRects + 1),0x10,true,0x98,0x10,0x10,0,0,0);
    }
    ovr_blitLabel((char *)"Unassigned",(uint8_t *)CONCAT22(FontMain.ofs,(char *)0x26510),
                  FontMain.seg,0xde,(char)FontMain.seg,0xde,0xe0);
  }
  TextBlitY = 0x11;
  TextBlitX = 0x87;
  uVar25 = 0xe0;
  uVar23 = 0xde;
  byteLo = (undefined1)Font02.seg;
  fontHi = (undefined1)(Font02.seg >> 8);
  fontOfs = Font02.ofs;
  textPtr = ovr_stsprintf((char *)&line);
  ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,in_DX),CONCAT11(fontHi,byteLo),uVar23,byteLo,
                uVar23,uVar25);
  TextBlitY = 0x1b;
  TextBlitX = 0x87;
  if (*(char *)((int)&(((entity_t *)agnt->entity)->base).entity + 3) != -1) {
    puVar9 = (uint16_t *)
             ((uint)*(byte *)((int)&(((entity_t *)agnt->entity)->base).entity + 3) * 4);
    uVar25 = puVar9[1];
    uVar7 = ovr_font_textWidth((char *)*puVar9,
                               (char *)CONCAT13((char)(Font02.ofs >> 8),
                                                CONCAT12((char)Font02.ofs,uVar25)),(char)uVar25,
                               (char)Font02.ofs,Font02.seg);
    uVar14 = (undefined1)Font02.seg;
    uVar16 = (undefined1)(Font02.seg >> 8);
    byteLo = (undefined1)Font02.ofs;
    fontHi = (undefined1)(Font02.ofs >> 8);
    if (uVar7 < 0x30) {
      uVar13 = 0xe0;
      uVar23 = 0xde;
      uVar25 = 3;
      cVar3 = 'V';
      puVar9 = (uint16_t *)
               ((uint)*(byte *)((int)&(((entity_t *)agnt->entity)->base).entity + 3) * 4);
      in_DX = (uint8_t *)((char *)0x2627a);
      fontOfs = Font02.ofs;
      uVar20 = uVar14;
      uVar22 = uVar16;
      textPtr = ovr_stsprintf((char *)&text,(char *)CONCAT22(0x62fe,_SS),
                             (char *)CONCAT22(*puVar9,(char *)0x26510),puVar9[1]);
      textPtr = (char *)ovr_ovc45_compute9((char *)&line,(char *)CONCAT22(textPtr,_SS),
                                          (char *)CONCAT13(fontHi,CONCAT12(byteLo,in_DX)),
                                          CONCAT11(uVar16,uVar14),cVar3,byteLo,uVar14,cVar3,uVar25);
      ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,in_DX),CONCAT11(uVar22,uVar20),uVar23,uVar20,
                    uVar23,uVar13);
    }
    else {
      uVar13 = 0xe0;
      uVar23 = 0xde;
      uVar25 = 3;
      cVar3 = 'V';
      puVar9 = (uint16_t *)
               ((uint)*(byte *)((int)&(((entity_t *)agnt->entity)->base).entity + 3) * 4);
      in_DX = (uint8_t *)((char *)0x2627a);
      fontOfs = Font02.ofs;
      uVar20 = uVar14;
      uVar22 = uVar16;
      textPtr = ovr_stsprintf((char *)&text,(char *)CONCAT22(0x630a,_SS),
                             (char *)CONCAT22(*puVar9,(char *)0x26510),puVar9[1]);
      textPtr = (char *)ovr_ovc45_compute9((char *)&line,(char *)CONCAT22(textPtr,_SS),
                                          (char *)CONCAT13(fontHi,CONCAT12(byteLo,in_DX)),
                                          CONCAT11(uVar16,uVar14),cVar3,byteLo,uVar14,cVar3,uVar25);
      ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,in_DX),CONCAT11(uVar22,uVar20),uVar23,uVar20,
                    uVar23,uVar13);
    }
  }
  TextBlitY = 0x25;
  TextBlitX = 0x87;
  if (((agntG_t *)agnt->gdata)->shortName[3] != -1) {
    cVar3 = stats_compute3((agnt_t *)CONCAT22(cmap.ofs,agnt));
    byteLo = (undefined1)Font02.seg;
    fontHi = (undefined1)(Font02.seg >> 8);
    if (cVar3 == '\0') {
      uVar25 = 0xe0;
      uVar23 = 0xde;
      fontOfs = Font02.ofs;
      value = stats_compute2((agnt_t *)CONCAT22(cmap.ofs,agnt));
      textPtr = ovr_manage_compute1((uint)value,0);
      uVar14 = SUB21(textPtr,0);
      nameOfs = in_DX;
      uVar5 = stats_compute2((agnt_t *)CONCAT13(segHi,CONCAT12(uVar5,agnt)));
      textPtr = ovr_stsprintf((char *)&line,(char *)CONCAT22(0x6323,_SS),
                             (char *)(ulong)CONCAT12(uVar5,0x2410),0x10,uVar5,uVar14,nameOfs);
      ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,in_DX),CONCAT11(fontHi,byteLo),uVar23,byteLo,
                    uVar23,uVar25);
    }
    else {
      uVar23 = 0xde;
      fontOfs = Font02.ofs;
      cVar3 = stats_compute1((agnt_t *)CONCAT22(cmap.ofs,agnt));
      iVar10 = (int)cVar3;
      value = stats_compute2((agnt_t *)CONCAT13(segHi,CONCAT12(uVar5,agnt)));
      textPtr = ovr_manage_compute1((uint)value,iVar10);
      uVar16 = SUB21(in_DX,0);
      uVar14 = SUB21(textPtr,0);
      uVar5 = stats_compute2((agnt_t *)CONCAT13(segHi,CONCAT12(uVar5,agnt)));
      textPtr = ovr_stsprintf((char *)&line,(char *)CONCAT22(0x6313,_SS),
                             (char *)(ulong)CONCAT12(uVar5,0x2410),uVar5,uVar14,uVar16);
      ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,in_DX),CONCAT11(fontHi,byteLo),uVar23,byteLo);
    }
  }
  if ((((agntG_t *)agnt->gdata)->shortName[3] == -1) ||
     (*(char *)((int)&(((entity_t *)agnt->entity)->base).entity + 3) == -1)) {
    uVar7 = (uint)(byte)((agntG_t *)agnt->gdata)->shortName[2];
    nameOfs = (uint8_t *)((char *)0x26510);
    ovr_blitLabel((char *)((far_t *)GAlignmentsNames + uVar7)->ofs,
                  (uint8_t *)
                  CONCAT22(Font02.ofs,
                           (uint8_t *)*(uint16_t *)((int)&GAlignmentsNames[0].seg + uVar7 * 4)),
                  Font02.seg,0xde,(char)Font02.seg,0xde,0xe0);
  }
  else {
    uVar1 = *(uint32_t *)
             ((uint)*(byte *)((int)&(((entity_t *)agnt->entity)->base).entity + 3) << 2);
    uVar7 = (uint)*(byte *)((int)uVar1 + 0x33);
    nameOfs = (uint8_t *)((char *)0x26510);
    ovr_blitLabel((char *)((far_t *)GAlignmentsNames + uVar7)->ofs,
                  (uint8_t *)
                  CONCAT22(Font02.ofs,
                           (uint8_t *)*(uint16_t *)((int)&GAlignmentsNames[0].seg + uVar7 * 4)),
                  Font02.seg,0xde,(char)Font02.seg,0xde,0xe0);
  }
  TextBlitY = 0x2f;
  TextBlitX = 0x87;
  if ((((agntG_t *)agnt->gdata)->shortName[3] != -1) && (agnt->gdata->ai == 0)) {
    ovr_blitLabel((char *)"Experience points",
                  (uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),Font02.seg,0xde,
                  (char)Font02.seg,0xde,0xe0);
    TextBlitY = 0x36;
    TextBlitX = 0x87;
    piVar8 = (int *)((uint)(byte)((agntG_t *)agnt->gdata)->shortName[3] * 0x94 +
                    (uint)(((entity_t *)agnt->entity)->base).level * 4);
    nameOfs = (uint8_t *)((char *)0x262b1);
    uVar5 = (undefined1)Font02.seg;
    segHi = (undefined1)(Font02.seg >> 8);
    if (*piVar8 == 0 && piVar8[1] == 0) {
      uVar25 = 0xe0;
      uVar23 = 0xde;
      fontOfs = Font02.ofs;
      textPtr = ovr_litoa10((char *)&text,0,0,0);
      textPtr = ovr_stsprintf((char *)&line,(char *)CONCAT13(99,CONCAT12(7,_SS)),
                             (char *)CONCAT13((char)((uint)textPtr >> 8),
                                              CONCAT12((char)textPtr,0x2410)),7,0x10,(char)textPtr,
                             nameOfs);
      ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,nameOfs),CONCAT11(segHi,uVar5),uVar23,uVar5,
                    uVar23,uVar25);
    }
    else {
      uVar26 = 0xe0;
      uVar23 = 0xde;
      puVar9 = (uint16_t *)
               ((uint)(byte)((agntG_t *)agnt->gdata)->shortName[3] * 0x94 +
               (uint)(((entity_t *)agnt->entity)->base).level * 4);
      nameOfs = (uint8_t *)((char *)0x262b1);
      fontOfs = Font02.ofs;
      textPtr = stats_formatThousands
                         ((char *)CONCAT13((char)((uint)_SS >> 8),CONCAT12((char)_SS,buf))
                          ,CONCAT22(puVar9[1],*puVar9));
      byteLo = SUB21(textPtr,0);
      uVar13 = (uint16_t)((ulong)agnt->entity >> 0x10);
      peVar12 = (entity_t *)agnt->entity;
      uVar25 = *(uint16_t *)&(peVar12->base).frameIndex;
      puVar18 = nameOfs;
      textPtr = stats_formatThousands
                         ((char *)CONCAT22(_SS,&text),
                          CONCAT13((char)((uint)uVar25 >> 8),
                                   CONCAT12((char)uVar25,*(uint16_t *)&(peVar12->base).health)));
      textPtr = ovr_stsprintf((char *)&line,(char *)CONCAT22(0x6342,_SS),
                             (char *)CONCAT13((char)((uint)textPtr >> 8),
                                              CONCAT12((char)textPtr,0x2410)),(char)textPtr,
                             (char)nameOfs,byteLo,puVar18);
      ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,nameOfs),CONCAT11(segHi,uVar5),uVar23,uVar5,
                    uVar23,uVar26);
    }
  }
  if (agnt->gdata->ai != 0) {
    uVar25 = 0xe0;
    uVar23 = 0xde;
    uVar5 = (undefined1)Font02.seg;
    segHi = (undefined1)(Font02.seg >> 8);
    fontOfs = Font02.ofs;
    iVar10 = ovr_ovc41_growthForLevel
                       (*(agnt_t **)&agnt->entity,*(uint16_t *)((int)&agnt->entity + 2));
    textPtr = ovr_stsprintf((char *)&line,(char *)CONCAT13(99,CONCAT12(0x48,_SS)),
                           (char *)CONCAT13((char)((uint)iVar10 >> 8),CONCAT12((char)iVar10,0x2410))
                           ,0x48,0x10,(char)iVar10,nameOfs);
    ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,nameOfs),CONCAT11(segHi,uVar5),uVar23,uVar5,
                  uVar23,uVar25);
  }
  TextBlitY = 0x40;
  TextBlitX = 0x87;
  uVar25 = 0xe0;
  uVar23 = 0xde;
  uVar5 = (undefined1)Font02.seg;
  segHi = (undefined1)(Font02.seg >> 8);
  fontOfs = Font02.ofs;
  textPtr = ovr_stsprintf((char *)&line,(char *)CONCAT13(99,CONCAT12(0x54,_SS)),
                         (char *)(ulong)CONCAT12(agnt->strength,0x2410),0x54,0x10,agnt->strength,
                         (uint)agnt->strengthMax);
  ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,nameOfs),CONCAT11(segHi,uVar5),uVar23,uVar5,
                uVar23,uVar25);
  TextBlitY = 0x4a;
  TextBlitX = 0x87;
  iVar10 = (uint)((agntG_t *)agnt->gdata)->type * 0x95;
  nameOfs = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
  uVar23 = (uint8_t)agnt;
  if (*(int *)((int)&AgntGs[0].wpn_name + iVar10) == 0 &&
      *(int *)((int)&AgntGs[0].wpn_name + 2 + iVar10) == 0) {
    damage = 0;
  }
  else {
    damage = ovr_agnt_compute9(agnt,cmap.ofs);
    uVar5 = (undefined1)Font02.seg;
    segHi = (undefined1)(Font02.seg >> 8);
    if (damage == 0) {
      uVar25 = 0xe0;
      attr = 0xde;
      fontOfs = Font02.ofs;
      textPtr = agntGetWeaponName((char *)CONCAT22(CONCAT11(0x24,((agntG_t *)agnt->gdata)->type),
                                                  _SS),0x0,(bool)field_index,uVar23,
                                 CONCAT22(Font02.ofs,cmap.ofs));
      ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,nameOfs),CONCAT11(segHi,uVar5),attr,uVar5,
                    attr,uVar25);
    }
    else if (damage < '\0') {
      uVar25 = 0xe0;
      attr = 0xde;
      fontOfs = Font02.ofs;
      textPtr = agntGetWeaponName((char *)CONCAT22(CONCAT11(0x24,((agntG_t *)agnt->gdata)->type),
                                                  _SS),damage,(bool)field_index,uVar23,
                                 CONCAT22(Font02.ofs,cmap.ofs));
      textPtr = ovr_stsprintf((char *)&line,(char *)CONCAT13(99,CONCAT12(0x65,_SS)),
                             (char *)CONCAT13((char)((uint)textPtr >> 8),
                                              CONCAT12((char)textPtr,0x2410)),0x65,0x10,(char)textPtr,
                             nameOfs);
      ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,nameOfs),CONCAT11(segHi,uVar5),attr,uVar5,
                    attr,uVar25);
    }
    else {
      uVar25 = 0xe0;
      attr = 0xde;
      fontOfs = Font02.ofs;
      textPtr = agntGetWeaponName((char *)CONCAT22(CONCAT11(0x24,((agntG_t *)agnt->gdata)->type),
                                                  _SS),damage,(bool)field_index,uVar23,
                                 CONCAT22(Font02.ofs,cmap.ofs));
      textPtr = ovr_stsprintf((char *)&line,(char *)CONCAT22(0x6370,_SS),
                             (char *)CONCAT13(damage >> 7,CONCAT12(damage,0x2410)),0x10,damage,
                             (char)textPtr,nameOfs);
      ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,nameOfs),CONCAT11(segHi,uVar5),attr,uVar5,
                    attr,uVar25);
    }
  }
  TextBlitY = 0x54;
  TextBlitX = 0x87;
  if (agnt->gdata->ai == 0) {
    damage = ovr_agnt_compute11(agnt,cmap.ofs);
  }
  else {
    damage = 0;
  }
  uVar25 = 0xe0;
  uVar23 = 0xde;
  uVar5 = (undefined1)Font02.seg;
  segHi = (undefined1)(Font02.seg >> 8);
  fontOfs = Font02.ofs;
  stats_compute4(*(agnt_t **)&agnt->entity,*(uint16_t *)((int)&agnt->entity + 2));
  textPtr = ovr_stsprintf((char *)&line);
  ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,nameOfs),CONCAT11(segHi,uVar5),uVar23,uVar5,
                uVar23,uVar25);
  if (agnt->gdata->ai == 0) {
    TextBlitY = 0x5e;
    TextBlitX = 0x87;
    uVar25 = 0xe0;
    uVar23 = 0xde;
    uVar5 = (undefined1)Font02.seg;
    segHi = (undefined1)(Font02.seg >> 8);
    (*(uint8_t *)((uint8_t *)&(ringValue.seg))) = uVar5;
    ringValue.ofs = Font02.ofs;
    (*(uint8_t *)((uint8_t *)&(ringValue.seg) + 1)) = segHi;
    fontOfs = Font02.ofs;
    text_00 = stats_textRingProt((char *)CONCAT13(0x24,CONCAT12(((agntG_t *)agnt->gdata)->type,
                                                                _SS)),
                                 CONCAT11(0x24,((agntG_t *)agnt->gdata)->shortName[4]),
                                 CONCAT11(0x24,damage),ringValue);
    ovr_blitLabel((char *)text_00,(uint8_t *)CONCAT22(fontOfs,nameOfs),CONCAT11(segHi,uVar5),uVar23,
                  uVar5,uVar23,uVar25);
  }
  else {
    damage = 0;
  }
  if ((*(uint *)((int)&(((entity_t *)agnt->entity)->base).frames + 1) & 2) != 0) {
    TextBlitY = 0x68;
    TextBlitX = 0x87;
    ovr_blitLabel((char *)"Mirror",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,(char)Font02.seg,0xde,0xe0);
  }
  if (GameRunning != false) {
    palette.seg = (uint16_t)in_stack_0000000a;
    palette.ofs = cmap.seg;
    ovr_setSeasonPalette(palette);
  }
  return;
}



/* 6386:12b7 */

/* Formats the ready/not-ready line for an agent. */

char * __cdecl16far stats_readyStatusText(byte agntIndex,char *text)

{
  uint32_t uVar1;
  uint8_t *puVar2;
  char *pcVar3;
  uint16_t agntSeg;
  int iVar5;
  uint16_t uVar6;
  byte in_stack_00000004;
  undefined1 in_stack_00000007;
  
  uVar1 = *(uint32_t far *)&Agnts[in_stack_00000004].entity;
  if ((*(byte *)((int)uVar1 + 0x33) & 1) == 0) {
    agntSeg = SEG_OF(Agnts);
    uVar1 = *(uint32_t far *)&Agnts[in_stack_00000004].gdata;
    uVar6 = (uint16_t)((ulong)uVar1 >> 0x10);
    iVar5 = (int)uVar1;
    puVar2 = ovr_ovc15_usesStshRealloc
                       ((char *)*(uint16_t *)(iVar5 + 0x24),*(uint16_t *)(iVar5 + 0x26),0,0,0,0,0,0);
    pcVar3 = ovr_stsprintf(agntIndex,(char *)CONCAT22(0x638d,(char *)text),
                           (char *)CONCAT22(puVar2,(char *)0x26510),agntSeg);
  }
  else {
    agntSeg = SEG_OF(Agnts);
    uVar1 = *(uint32_t far *)&Agnts[in_stack_00000004].gdata;
    uVar6 = (uint16_t)((ulong)uVar1 >> 0x10);
    iVar5 = (int)uVar1;
    puVar2 = ovr_ovc15_usesStshRealloc
                       ((char *)*(uint16_t *)(iVar5 + 0x24),*(uint16_t *)(iVar5 + 0x26),0,0,0,0,0,0);
    pcVar3 = ovr_stsprintf(agntIndex,(char *)CONCAT22(0x63a2,(char *)text),
                           (char *)CONCAT22(puVar2,(char *)0x26510),agntSeg);
  }
  return pcVar3;
}



/* 6386:1353 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches EntityCount, Entities */

void __cdecl16far stats_usesEntityCount(char partyIndex)

{
  byte *pbVar1;
  uint uVar2;
  uint16_t uVar3;
  
  for (uVar2 = 0; uVar2 < EntityCount; uVar2 = uVar2 + 1) {
    uVar3 = (uint16_t)((ulong)Entities >> 0x10);
    if (*(char *)((int)&((entity_t *)Entities)[uVar2].base.entity + 3) == partyIndex) {
      pbVar1 = (byte *)((uint8_t *)&((entity_t *)Entities)[uVar2] + 0x33);
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
  uint32_t entityFar;
  uint32_t uVar3;
  uint8_t *puVar4;
  char *pcVar5;
  uint16_t agntSeg;
  int iVar7;
  uint16_t uVar8;
  uint8_t text;
  char *pcStack_d4;
  uint8_t msg;
  uint8_t unitFlags;
  int iStack_4;
  
  entityFar = *(uint32_t far *)&Agnts[agnt_id].entity;
  uVar8 = text;
  pcStack_d4 = (char *)(CONCAT22(text,(uint)*(byte *)((int)entityFar + 0x33)) ^ 1);
  entityFar = *(uint32_t far *)&Agnts[agnt_id].entity;
  *(undefined1 *)((int)entityFar + 0x33) = (char)pcStack_d4;
  entityFar = *(uint32_t far *)&Agnts[agnt_id].entity;
  if ((*(byte *)((int)entityFar + 0x33) & 1) == 0) {
    entityFar = *(uint32_t far *)&Agnts[agnt_id].entity;
    pbVar1 = (byte *)((int)entityFar + 0x33);
    *pbVar1 = *pbVar1 & 0xfb;
  }
  else {
    entityFar = *(uint32_t far *)&Agnts[agnt_id].entity;
    text = uVar8;
    stats_usesEntityCount(*(char *)((int)entityFar + 0x1a));
    entityFar = *(uint32_t far *)&Agnts[agnt_id].entity;
    pbVar1 = (byte *)((int)entityFar + 0x33);
    *pbVar1 = *pbVar1 | 4;
    iStack_4 = Agnts[agnt_id].owner;
    pcStack_d4 = (char *)CONCAT22(text,_SS);
    ovr_attact_usesEntities(iStack_4,0,0,(uint16_t)&unitFlags,(uint16_t)_SS,0,0,0,0);
  }
  entityFar = *(uint32_t far *)&Agnts[agnt_id].entity;
  uVar3 = *(uint32_t far *)&Agnts[agnt_id].entity;
  *(byte *)((int)uVar3 + 0x33) = *(byte *)((int)entityFar + 0x33) & 0xfd;
  pcStack_d4 = (char *)((ulong)pcStack_d4 & 0xffff0000);
  drawAgntStats((agnt_t *)&Agnts[agnt_id].x,far_from_u32((uint32_t)(SEG_OF(Agnts))),0);
  agntSeg = SEG_OF(Agnts);
  entityFar = *(uint32_t far *)&Agnts[agnt_id].entity;
  if ((*(byte *)((int)entityFar + 0x33) & 1) == 0) {
    agntSeg = SEG_OF(Agnts);
    entityFar = *(uint32_t far *)&Agnts[agnt_id].gdata;
    uVar8 = (uint16_t)((ulong)entityFar >> 0x10);
    iVar7 = (int)entityFar;
    puVar4 = ovr_ovc15_usesStshRealloc
                       ((char *)*(uint16_t *)(iVar7 + 0x24),*(uint16_t *)(iVar7 + 0x26),0,0,0,0,0,0);
    pcVar5 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x63b1,_SS),
                           (char *)CONCAT22(puVar4,(char *)0x26510),agntSeg);
    pcStack_d4 = (char *)CONCAT22(text,agntSeg);
    drawString(pcVar5,agntSeg,0);
  }
  else {
    pcStack_d4 = (char *)CONCAT22(text,_SS);
    pcVar5 = stats_readyStatusText((byte)&text,pcStack_d4);
    pcVar5 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x63c8,_SS),
                           (char *)CONCAT22(pcVar5,(char *)0x26510),agntSeg);
    pcStack_d4 = (char *)CONCAT22(text,agntSeg);
    drawString(pcVar5,agntSeg,0);
  }
  return;
}



/* 6386:1572 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

uint __cdecl16far stats_usesAlignUp4(int entityIndex)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  uint16_t uVar5;
  
  uVar5 = (uint16_t)((ulong)Entities >> 0x10);
  if ((*((uint8_t far *)&((entity_t *)Entities)[entityIndex].base.flags32 + 1) & 2) == 0) {
    uVar2 = 0;
  }
  else {
    uVar1 = ovr_alignUp4(((entity_t *)Entities)[entityIndex].base.x,0,0);
    uVar2 = ovr_alignUp4(GfxRndSeed,0,0);
    if (uVar1 == uVar2) {
      uVar5 = (uint16_t)((ulong)Entities >> 0x10);
      uVar2 = ((entity_t *)Entities)[entityIndex].base.y;
      if (uVar2 == GfxRndSeed2) {
        uVar1 = ovr_alignUp4(((entity_t *)Entities)[entityIndex].base.targetX,0,0);
        uVar2 = ovr_alignUp4(GfxRndSeed,0,0);
        if (uVar1 == uVar2) {
          uVar5 = (uint16_t)((ulong)Entities >> 0x10);
          iVar4 = (int)Entities;
          uVar2 = ((entity_t *)iVar4)[entityIndex].base.targetY;
          if (uVar2 == GfxRndSeed2) {
            if (((entity_t *)iVar4)[entityIndex].base.destX == 0) {
              bVar3 = (byte)((uint)(entityIndex * 0x37) >> 8);
              if (((entity_t *)iVar4)[entityIndex].base.destY == 0) {
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Sets the agent's entity position to the cursor cell and reports the new base. */

void __cdecl16far stats_setAgentBase(byte agntIndex)

{
  byte *pbVar1;
  int entityIndex;
  int iVar2;
  uint8_t *puVar3;
  char *text;
  uint16_t widths;
  uint16_t uVar4;
  uint8_t msg;
  int iStack_c;
  uint16_t uStack_a;
  uint8_t unitFlags;
  
  entityIndex = Agnts[agntIndex].owner;
  uStack_a = AGNT_WORD(&Agnts[agntIndex], gdata, 2);
  iStack_c = AGNT_WORD(&Agnts[agntIndex], gdata, 0);
  iVar2 = ovr_ovc23_compute2(GfxRndSeed,GfxRndSeed2);
  ((entity_t *)Entities)[entityIndex].base.x = iVar2;
  ((entity_t *)Entities)[entityIndex].base.y = GfxRndSeed2;
  uVar4 = (uint16_t)((ulong)Entities >> 0x10);
  ((entity_t *)Entities)[entityIndex].base.targetX =
       ((entity_t *)Entities)[entityIndex].base.x;
  ((entity_t *)Entities)[entityIndex].base.targetY = GfxRndSeed2;
  pbVar1 = (byte *)((uint8_t *)&((entity_t *)Entities)[entityIndex] + 0x33);
  *pbVar1 = *pbVar1 | 2;
  widths = 0x2410;
  pbVar1 = (byte *)((uint8_t *)&((entity_t *)Entities)[entityIndex] + 0x33);
  *pbVar1 = *pbVar1 & 0xfa;
  ovr_attact_usesEntities(entityIndex,0,0,(uint16_t)&unitFlags,(uint16_t)_SS,0,0,0,0);
  ovr_alignUp4(GfxRndSeed,GfxRndSeed2,0);
  puVar3 = ovr_ovc15_usesStshRealloc
                     ((char *)*(uint16_t *)(iStack_c + 0x24),*(uint16_t *)(iStack_c + 0x26),0,0,0,0,0,0);
  text = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x6406,_SS),
                       (char *)CONCAT22(puVar3,(char *)0x26510),widths);
  drawString(text,widths,0);
  drawAgntStats((agnt_t *)&Agnts[agntIndex].x,far_from_u32((uint32_t)(SEG_OF(Agnts))),0);
  return;
}



/* 6386:1837 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Formats the "%s can now be called away from home." notice. */

void __cdecl16far stats_calledAwayNotice(byte agntIndex)

{
  byte *pbVar1;
  int entityIndex;
  int iVar2;
  uint8_t *puVar3;
  char *text;
  uint16_t widths;
  uint16_t uVar4;
  uint8_t msg;
  int iStack_c;
  uint16_t uStack_a;
  uint8_t unitFlags;
  
  entityIndex = Agnts[agntIndex].owner;
  uStack_a = AGNT_WORD(&Agnts[agntIndex], gdata, 2);
  iStack_c = AGNT_WORD(&Agnts[agntIndex], gdata, 0);
  iVar2 = ovr_ovc23_compute2(GfxRndSeed,GfxRndSeed2);
  ((entity_t *)Entities)[entityIndex].base.x = iVar2;
  ((entity_t *)Entities)[entityIndex].base.y = GfxRndSeed2;
  uVar4 = (uint16_t)((ulong)Entities >> 0x10);
  ((entity_t *)Entities)[entityIndex].base.targetX =
       ((entity_t *)Entities)[entityIndex].base.x;
  ((entity_t *)Entities)[entityIndex].base.targetY = GfxRndSeed2;
  widths = 0x2410;
  pbVar1 = (byte *)((uint8_t *)&((entity_t *)Entities)[entityIndex] + 0x33);
  *pbVar1 = *pbVar1 & 0xfd;
  ovr_attact_usesEntities(entityIndex,0,0,(uint16_t)&unitFlags,(uint16_t)_SS,0,0,0,0);
  puVar3 = ovr_ovc15_usesStshRealloc
                     ((char *)*(uint16_t *)(iStack_c + 0x24),*(uint16_t *)(iStack_c + 0x26),0,0,0,0,0,0);
  text = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x644e,_SS),
                       (char *)CONCAT22(puVar3,(char *)0x26510),widths);
  drawString(text,widths,0);
  drawAgntStats((agnt_t *)&Agnts[agntIndex].x,far_from_u32((uint32_t)(SEG_OF(Agnts))),0);
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
    if ((Agnts[agntIndex].owner < Agnts[iVar1].owner) &&
       (Agnts[iVar1].owner < uVar2)) {
      uVar2 = Agnts[iVar1].owner;
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
    if ((Agnts[iVar1].owner < Agnts[agntIndex].owner) &&
       (iVar2 < Agnts[iVar1].owner)) {
      iVar2 = Agnts[iVar1].owner;
      uStack_3 = (undefined1)iVar1;
    }
  }
  return uStack_3;
}



/* 6386:1a9b */

/* [R7] body shape: compute */

void __cdecl16far stats_compute5(byte agntIndex)

{
  ovr_ovc15_usesStExit(Agnts[agntIndex].owner);
  return;
}



/* 6386:1abe */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Opens the agent detail page: ScreenMode 2, drawAgntStats and the detail text. */

void __cdecl16far stats_openAgentDetail(int agntIndex)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = Agnts[agntIndex].owner;
  ovr_manage_openTalkWindow();
  ScreenMode = 2;
  drawAgntStats((agnt_t *)&Agnts[agntIndex].x,far_from_u32((uint32_t)(SEG_OF(Agnts))),0);
  drawString((char *)0x620f,0x2410,0);
  bVar1 = ((entity_t *)Entities)[iVar2].base.gindex;
  if (AgntGs[(uint)bVar1].ai == '\0') {
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
    ovr_play_sfx(CONCAT11(0x24,CurMusicType),0,0);
  }
  return;
}



/* 6386:1c9f */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0006f700) overlaps instruction at (ram,0x0006f6ff)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

byte __cdecl16far
stats_usesAlignUp42(byte agntIndex,byte gfxIndex,int16_t x,int16_t y,brect_t *rect,uint16_t type)

{
  uint32_t uVar1;
  far_t gfx;
  far_t entries_00;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  char cVar2;
  byte bVar3;
  bool bVar4;
  uint uVar5;
  char *pcVar6;
  ulong *puVar7;
  uint uVar8;
  uint8_t *puVar9;
  uint16_t uVar10;
  uint16_t *puVar11;
  int *piVar12;
  uint16_t *puVar13;
  int iVar14;
  uint16_t uVar15;
  uint16_t uVar16;
  undefined1 uVar17;
  undefined1 uVar18;
  uint8_t entries;
  uint16_t uStack_36;
  uint16_t uStack_34;
  uint16_t uStack_32;
  uint16_t uStack_30;
  uint16_t uStack_2e;
  uint16_t uStack_2c;
  uint16_t uStack_2a;
  uint16_t uStack_28;
  uint16_t uStack_26;
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
  ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)(0xa000c31d)),0x1d);
  Cancelled = 0;
  ovr_attact_usesAgntFlag1();
  ovr_draw_freeRingBuffers();
  ovr_stop_audio();
  savedMenuItem = GMenuItem;
  MenuModeSaved = MenuMode;
  CurMusicType = 0xff;
L_stats_6386_1c9f_1E1D:
  for (; GCharLevelsInc != '\0'; GCharLevelsInc = GCharLevelsInc + -1) {
    uVar1 = *(uint32_t far *)&Agnts[agntIndex].gdata;
    bStack_3 = *(byte *)((int)uVar1 + 0x46);
    if (bStack_3 == 0xff) {
      bStack_3 = 0;
    }
    uVar1 = *(uint32_t far *)&Agnts[agntIndex].entity;
    piVar12 = (int *)((uint)bStack_3 * 0x94 + (uint)*(byte *)((int)uVar1 + 0xf) * 4);
    if (*piVar12 != 0 || piVar12[1] != 0) {
      uVar1 = *(uint32_t far *)&Agnts[agntIndex].entity;
      puVar13 = (uint16_t *)((uint)bStack_3 * 0x94 + (uint)*(byte *)((int)uVar1 + 0xf) * 4);
      uVar16 = *puVar13;
      uVar1 = *(uint32_t far *)&Agnts[agntIndex].entity;
      uVar15 = (uint16_t)((ulong)uVar1 >> 0x10);
      iVar14 = (int)uVar1;
      *(uint16_t *)(iVar14 + 0x12) = puVar13[1];
      *(uint16_t *)(iVar14 + 0x10) = uVar16;
      uVar16 = AGNT_WORD(&Agnts[agntIndex], entity, 2);
      ovr_ovc41_compute3(CONCAT13((char)((uint)uVar16 >> 8),
                                  CONCAT12((char)uVar16,
                                           AGNT_WORD(&Agnts[agntIndex], entity, 0))));
    }
  }
  iVar14 = Agnts[agntIndex].owner;
  stats_openAgentDetail((uint)agntIndex);
  uVar16 = (uint16_t)((ulong)Entities >> 0x10);
  if (((entity_t *)Entities)[iVar14].base.targetY == GfxRndSeed2) {
    uVar5 = ovr_alignUp4(((entity_t *)Entities)[iVar14].base.targetX,0,0);
    uVar17 = (undefined1)uVar5;
    uVar18 = (undefined1)(uVar5 >> 8);
    uVar5 = ovr_alignUp4(GfxRndSeed,0,0);
    if (CONCAT11(uVar18,uVar17) == uVar5) {
      uVar1 = *(uint32_t far *)&Agnts[agntIndex].entity;
      ovr_ovc39_textHalflingCastle(*(byte *)((int)uVar1 + 0x1a));
    }
  }
L_stats_6386_1c9f_1ECD:
  cVar2 = stats_prevAgentByOwner(agntIndex);
  if (cVar2 == -1) {
    uStack_36 = 0;
    entries = 0;
  }
  else {
    uStack_36 = 0x2410;
    entries = 0x6473;
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
  uVar1 = *(uint32_t far *)&Agnts[agntIndex].entity;
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
  puVar9 = (uint8_t *)((int)&AgntAnms[0x75].halfWidth + 1);
  if (*(char *)*(uint32_t far *)&Agnts[agntIndex].gdata == '\0') {
    menuBarShown = 1;
  }
  entries_00.seg = _SS;
  entries_00.ofs = (uint16_t)&entries;
  pcVar6 = ovr_uiInputText(entries_00,5,far_from_u32((uint32_t)(0x0)),0x0,0);
  bStack_4 = (byte)pcVar6;
  menuBarShown = 0;
  if ((bStack_4 != 0) && (bStack_4 < 10)) {
    puVar9 = &permTable;
    bStack_4 = puVar9[(uint)pcVar6 & 0xff];
  }
  cStack_5 = '\0';
  cStack_6 = '\0';
  uVar5 = (uint)bStack_4;
  if (uVar5 == 6) {
    cStack_6 = '\x01';
    cStack_5 = '\x01';
  }
  else if (uVar5 < 7) {
    uVar8 = 5;
    switch(uVar5) {
    case 0:
      menuBarShown = 0;
      uVar5 = 5;
      Agnts[5].x = 0x2b;
      Agnts[5].y = 2;
      do {
        bStack_3 = 1;
        while( true ) {
          uVar5 = uVar5 + 1;
          uVar8 = (uint)AgntCount;
          if ((int)uVar8 <= (int)uVar5) {
            ovr_agnt_usesAlignToSeg();
            bVar3 = (byte)uVar8;
            ovr_agnt_usesAlignToSeg();
            ovr_agnt_usesAlignToSeg();
            ovr_agnt_usesAlignToSeg();
            return bVar3;
          }
          uVar1 = *(uint32_t far *)&Agnts[uVar5].gdata;
          uVar8 = uVar5;
          if (*(char *)((int)uVar1 + 1) == '\x02') break;
          uVar1 = *(uint32_t far *)&Agnts[uVar5].gdata;
          if (*(char *)((int)uVar1 + 1) == '\x01') {
            Agnts[uVar5].x = 0x3d;
            Agnts[uVar5].y = 0x12;
          }
          else {
            uVar1 = *(uint32_t far *)&Agnts[uVar5].gdata;
            if (*(char *)((int)uVar1 + 1) == '\v') {
              Agnts[uVar5].x = 0x56;
              Agnts[uVar5].y = 0x14;
            }
          }
        }
switchD_6000_58bf_caseD_5:
        Agnts[uVar5].x = 0x6e;
        Agnts[uVar8].y = 0xb;
        uVar5 = uVar8;
      } while( true );
    case 1:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 2:
      uVar16 = (uint16_t)
               ((ulong)*(uint32_t *)((undefined *)&GfxFramePtrs + (uint)gfxIndex * 4) >> 0x10);
      puVar11 = (uint16_t *)
                ((int)*(uint32_t *)((undefined *)&GfxFramePtrs + (uint)gfxIndex * 4) +
                (uint)bStack_3 * 4);
      gfx.seg = puVar11[1];
      gfx.ofs = *puVar11;
      ovr_blitGfxRect(gfx,x,y,rect,(uint8_t)type,true,(uint8_t)type,0,0,0,0,0);
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
        uVar10 = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
        if ((*(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2) != InputEventTime.hi) ||
           (uVar10 != InputEventTime.lo)) {
          InputEventTime.hi = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
          uVar10 = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
          InputEventTime.lo = uVar10;
          ovr_draw_usesPrintf();
        }
        bStack_4 = ovr_draw_textProvidesMoreHousing();
        if ((bool)bStack_4) break;
        puVar7 = ovr_attact_usesBDADailyTimeCounter
                           ((ulong *)TextBlitCycle,
                            CONCAT13(uVar18,CONCAT12(uVar17,(*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)))),
                            (char)(*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)));
        if ((uVar10 != 0) || ((ulong *)(uint)agntIndex <= puVar7)) break;
      }
      if (bStack_3 != '\0') {
        ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
      }
      return bStack_4;
    case 4:
      in(puVar9);
      ovr_draw_freeRingBuffers();
      ovr_stop_audio();
      savedMenuItem = GMenuItem;
      MenuModeSaved = MenuMode;
      gfx_01.seg = nwpanel1Cut2Seg;
      gfx_01.ofs = nwpanel1Cut2Ofs;
      ovr_blitLoadRleGfx(gfx_01,far_from_u32((uint32_t)(0xa000e249)),0x49);
      gfx_02.seg = trianglsCut6Seg;
      gfx_02.ofs = trianglsCut6Ofs;
      ovr_blitLoadRleGfx(gfx_02,far_from_u32((uint32_t)(0xa000e249)),0x49);
      ovr_uiMainMenuLoop();
      gfx_03.seg = nwpanel1Cut2Seg;
      gfx_03.ofs = nwpanel1Cut2Ofs;
      ovr_blitLoadRleGfx(gfx_03,far_from_u32((uint32_t)(0xa000e249)),0x49);
      bVar3 = 0x10;
      gfx_04.seg = trianglsCut5Seg;
      gfx_04.ofs = trianglsCut5Ofs;
      ovr_blitLoadRleGfx(gfx_04,far_from_u32((uint32_t)(0xa000e249)),0x49);
      ovc41_usesGMenuItem();
      return bVar3;
    case 5:
      goto switchD_6000_58bf_caseD_5;
    }
  }
  else if (uVar5 == 0xfc) {
    uVar1 = *(uint32_t far *)&Agnts[agntIndex].entity;
    if ((*(byte *)((int)uVar1 + 0x33) & 1) == 0) {
      stats_unreadyNotice(agntIndex);
    }
  }
  else if (uVar5 < 0xfd) {
    if (uVar5 == 7) {
      uVar1 = *(uint32_t far *)&Agnts[agntIndex].entity;
      if (*(char *)((int)uVar1 + 0x1a) != -1) {
        ovr_stop_audio();
        CurMusicType = 0xff;
        uVar1 = *(uint32_t far *)&Agnts[agntIndex].entity;
        ovr_manage_settlementScreen(*(byte *)((int)uVar1 + 0x1a));
        if (Cancelled == 0) {
          iVar14 = Agnts[agntIndex].owner;
          stats_openAgentDetail((uint)agntIndex);
          uVar16 = (uint16_t)((ulong)Entities >> 0x10);
          if (((entity_t *)Entities)[iVar14].base.targetY == GfxRndSeed2) {
            uVar5 = ovr_alignUp4(((entity_t *)Entities)[iVar14].base.targetX,0,0);
            uVar17 = (undefined1)uVar5;
            uVar18 = (undefined1)(uVar5 >> 8);
            uVar5 = ovr_alignUp4(GfxRndSeed,0,0);
            if (CONCAT11(uVar18,uVar17) == uVar5) {
              uVar1 = *(uint32_t far *)&Agnts[agntIndex].entity;
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
      if (uVar5 == 8) goto L_stats_6386_1c9f_20C5;
      if (uVar5 == 9) {
        ovr_ovc50_usesUiInputText();
        cStack_6 = '\x01';
      }
    }
  }
  else if (uVar5 == 0xfd) {
L_stats_6386_1c9f_20C5:
    uVar5 = stats_usesAlignUp4(Agnts[agntIndex].owner);
    if ((uVar5 & 0xff) == 0) {
      stats_setAgentBase(agntIndex);
    }
  }
  else if (uVar5 == 0xfe) {
    uVar1 = *(uint32_t far *)&Agnts[agntIndex].entity;
    if ((*(byte *)((int)uVar1 + 0x33) & 1) != 0) {
      stats_unreadyNotice(agntIndex);
    }
    uVar5 = stats_usesAlignUp4(Agnts[agntIndex].owner);
    if ((char)uVar5 != '\0') {
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
  uint16_t in_DX;
  int menuIndex;
  far_t ptr;
  far_t handle;
  far_t handle_00;
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
  ptr.seg = in_DX;
  ptr.ofs = (uint16_t)pvStack_6;
  uStack_4 = in_DX;
  ovr_alignToSeg(ptr);
  uStack_e = 7;
  uStack_a = 0xc2;
  dst = 8;
  uStack_c = 0xe2;
  ovr_driver_fillRect(8,7,0xe2,0xc2,0x0,in_DX,0,0,0,0,0);
  gfx_00.seg = fullScreenGfxSeg;
  gfx_00.ofs = fullScreenGfxOfs;
  ovr_blitGfx10(gfx_00,0,0,(brect_t *)&dst,SUB21(_SS,0),0,0);
  gfx.seg = nwpanel2Cut1Seg;
  gfx.ofs = nwpanel2Cut1Ofs;
  ovr_blitGfxRect(gfx,0,0,(brect_t *)&dst,SUB21(_SS,0),true,0,0,0,0,0,0);
  handle.seg = Lbm_nwpanel1.seg;
  handle.ofs = Lbm_nwpanel1.ofs;
  psStack_14 = ovr_stshLoadGfx(handle);
  ovr_calcSeasonPalette(psStack_14->cmap,in_DX,&palette,_SS,0,0);
  ovr_driver_fillRect(dst,uStack_e,uStack_c,uStack_a,0x0,0xa000,0,0,0,0,0);
  ovr_vgaSetPalette8bit(&palette,0);
  ovr_blitRect((brect_t *)&dst,0);
  TextBlitDstSeg = 0xa000;
  ovr_ovc28_textHalflingCastle();
  for (menuIndex = 0; menuIndex < 5; menuIndex = menuIndex + 1) {
    ovr_draw_usesBlitLoadRleGfx3(menuIndex);
    ovr_draw_menuRowBar(menuIndex,0xa000);
  }
  mapViewActive = 0xff;
  ovr_attact_usesLDIV_at_2();
  handle_00.seg = uStack_4;
  handle_00.ofs = (uint16_t)pvStack_6;
  ovr_stshFree(handle_00);
  ovr_stop_audio();
  CurMusicType = 0xff;
  ScreenMode = 0;
  return;
}



/* 6386:24c2 */

void __cdecl16far drawString(char *text,uint16_t widths,uint16_t arg3)

{
  uint uVar1;
  size_t sVar2;
  far_t gfx;
  uint8_t rect;
  uint16_t uStack_a;
  int16_t iStack_8;
  int16_t iStack_6;
  
  memcpy((char *)CONCAT22(_SS,&rect),(char *)(BlitRects + 1),10);
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
  rect = 19;
  iStack_8 = 215;
  TextBlitFlag = 1;
  TextBlitDstSeg = 0xa000;
  gfx.seg = talkwin9Cut4Seg;
  gfx.ofs = talkwin9Cut4Ofs;
  ovr_blitGfxRect(gfx,0,0,(brect_t *)&rect,(uint8_t)_SS,0,0,0,0,0,0,0);
  TextBlitY = uStack_a;
  while( true ) {
    TextBlitX = 0x13;
    uVar1 = ovr_blitText(text,(byte *)CONCAT22(Font03.ofs,widths),Font03.seg,0xd7,(char)Font03.seg,
                         0xd7,0xed);
    sVar2 = strlen((char *)CONCAT22(widths,text));
    if (sVar2 <= uVar1) break;
    text = text + uVar1;
    TextBlitY = TextBlitY + 0xb;
  }
  ovr_clean_ring_buffer();
  return;
}


