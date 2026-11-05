/*
 * ovc33_stats.c - recovered from STRONG.EXE
 * memory block: OVC33_stats.c
 * range: 6386:0000 - 6386:28ff
 * functions: 25
 */
#include "recovered.h"


/* 6386:0000 */

char __cdecl16far stats_6386_0000(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if ((*(char *)((int)*(undefined4 *)(iVar2 + 0x1d) + 0x46) == '\x04') &&
     (0xb < *(byte *)((int)*(undefined4 *)(iVar2 + 0x17) + 0xf))) {
    cVar1 = *(char *)((int)*(undefined4 *)(iVar2 + 0x17) + 0xf) + '7';
  }
  else if ((*(char *)((int)*(undefined4 *)(iVar2 + 0x1d) + 0x46) == '\x05') &&
          (9 < *(byte *)((int)*(undefined4 *)(iVar2 + 0x17) + 0xf))) {
    cVar1 = *(char *)((int)*(undefined4 *)(iVar2 + 0x17) + 0xf) + '9';
  }
  else if ((*(char *)((int)*(undefined4 *)(iVar2 + 0x1d) + 0x46) == '\x06') &&
          (7 < *(byte *)((int)*(undefined4 *)(iVar2 + 0x17) + 0xf))) {
    cVar1 = *(char *)((int)*(undefined4 *)(iVar2 + 0x17) + 0xf) + '9';
  }
  else {
    cVar1 = '0';
  }
  return cVar1;
}



/* 6386:0088 */

undefined1 __cdecl16far stats_6386_0088(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if ((*(char *)((int)*(undefined4 *)(iVar2 + 0x1d) + 0x46) == '\x04') &&
     (0xc < *(byte *)((int)*(undefined4 *)(iVar2 + 0x17) + 0xf))) {
    uVar1 = 0xc;
  }
  else if ((*(char *)((int)*(undefined4 *)(iVar2 + 0x1d) + 0x46) == '\x05') &&
          (10 < *(byte *)((int)*(undefined4 *)(iVar2 + 0x17) + 0xf))) {
    uVar1 = 10;
  }
  else if ((*(char *)((int)*(undefined4 *)(iVar2 + 0x1d) + 0x46) == '\x06') &&
          (8 < *(byte *)((int)*(undefined4 *)(iVar2 + 0x17) + 0xf))) {
    uVar1 = 8;
  }
  else {
    uVar1 = *(undefined1 *)((int)*(undefined4 *)(iVar2 + 0x17) + 0xf);
  }
  return uVar1;
}



/* 6386:00f8 */

void __cdecl16far stats_6386_00f8(void)

{
  far_t gfx;
  far_t gfx_00;
  
  gfx_00.seg = DAT_2000_cacf;
  gfx_00.ofs = DAT_2000_cacd;
  ovr_blitGfx10(gfx_00,0,0,(brect_t *)0x24105ce5,0);
  gfx.seg = DAT_2000_caab;
  gfx.ofs = DAT_2000_caa9;
  ovr_blitLoadRleGfx(gfx,(far_t)0xa0000adf);
  return;
}



/* 6386:013d */

undefined1 __cdecl16far stats_6386_013d(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if ((*(char *)((int)*(undefined4 *)(iVar2 + 0x1d) + 0x46) == '\x04') &&
     (0xb < *(byte *)((int)*(undefined4 *)(iVar2 + 0x17) + 0xf))) {
    uVar1 = 1;
  }
  else if ((*(char *)((int)*(undefined4 *)(iVar2 + 0x1d) + 0x46) == '\x05') &&
          (9 < *(byte *)((int)*(undefined4 *)(iVar2 + 0x17) + 0xf))) {
    uVar1 = 1;
  }
  else if ((*(char *)((int)*(undefined4 *)(iVar2 + 0x1d) + 0x46) == '\x06') &&
          (7 < *(byte *)((int)*(undefined4 *)(iVar2 + 0x17) + 0xf))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 6386:01a4 */

void __cdecl16far stats_6386_01a4(undefined4 param_1,byte param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  stg_tmp_t *psVar4;
  far_t gfx;
  far_t handle;
  far_t handle_00;
  
  handle.seg = DAT_2000_d386;
  handle.ofs = DAT_2000_d384;
  psVar4 = ovr_stshLoadGfx(handle);
  ovr_calcSeasonPalette((stg_tmp_t *)psVar4,(int)((ulong)psVar4 >> 0x10),param_3);
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  iVar2 = iVar1 + (uint)param_2 * 4;
  if ((*(int *)(iVar2 + 0x60) != 0 || *(int *)(iVar2 + 0x62) != 0) &&
     (iVar2 = iVar1 + (uint)param_2 * 4, *(int *)(iVar2 + 0x78) != 0 || *(int *)(iVar2 + 0x7a) != 0)
     ) {
    iVar2 = iVar1 + (uint)param_2 * 4;
    handle_00.seg = *(uint16_t *)(iVar2 + 0x7a);
    handle_00.ofs = *(uint16_t *)(iVar2 + 0x78);
    psVar4 = ovr_stshLoadGfx(handle_00);
    memcpy((uint8_t *)(param_3 + 3),((stg_tmp_t *)psVar4)->cmap + 3,0xed);
    memcpy((uint8_t *)(param_3 + 0x1e0),((stg_tmp_t *)psVar4)->cmap + 0x1e0,0x90);
  }
  if (GameRunning == false) {
    ovr_vgaSetPalette8bit(param_3);
  }
  iVar2 = iVar1 + (uint)param_2 * 4;
  if (*(int *)(iVar2 + 0x60) != 0 || *(int *)(iVar2 + 0x62) != 0) {
    ovr_driver_2d63_05e5(0xf,9,0x83,0x72,0xec);
    iVar1 = iVar1 + (uint)param_2 * 4;
    gfx.seg = *(uint16_t *)(iVar1 + 0x62);
    gfx.ofs = *(uint16_t *)(iVar1 + 0x60);
    ovr_blitGfxRect(gfx,16,10,BlitRects + 1,0x10,false);
  }
  return;
}



/* 6386:02db */

char * __cdecl16far agntCopyNthField(uint8_t filed_index,char *dst,char *src)

{
  bool bVar1;
  size_t len;
  uint i;
  uint8_t j;
  
  j = 0x0;
  bVar1 = false;
  i = 0;
  while( true ) {
    len = strlen((char *)src);
    if (len <= i) break;
    if (((char *)src)[i] == ',') {
      j = j + 0x1;
      if (bVar1) break;
    }
    else if (j == filed_index) {
      *dst = ((char *)src)[i];
      dst = (char *)CONCAT22(dst._2_2_,(char *)dst + 1);
      bVar1 = true;
    }
    i = i + 1;
  }
  if (bVar1) {
    *dst = '\0';
  }
  else {
    strcpy((char *)dst,(char *)src);
  }
  return (char *)dst;
}



/* 6386:0367 */

char * __cdecl16far
agntGetWeaponName(char *dst,uint8_t atype,bool magical,uint8_t field_index,int32_t agent)

{
  undefined4 uVar1;
  
  if (*(int *)((int)&AgntGs[0].wpn_name + (uint)atype * 0x95) == 0 &&
      *(int *)((int)&AgntGs[0].wpn_name + 2 + (uint)atype * 0x95) == 0) {
    if (magical) {
      strcpy((char *)dst,(char *)"normal weaponry" + 7);
    }
    else {
      strcpy((char *)dst,(char *)"normal weaponry");
    }
  }
  else {
    uVar1 = *(undefined4 *)((int)agent + 0x1d);
    if ((*(uint *)((int)uVar1 + 0x40) & 0x4000) == 0) {
      agntCopyNthField(field_index,dst,
                       (char *)CONCAT22(*(undefined2 *)
                                         ((int)&AgntGs[0].wpn_name + 2 + (uint)atype * 0x95),
                                        (char *)*(undefined2 *)
                                                 ((int)&AgntGs[0].wpn_name + (uint)atype * 0x95)));
    }
    else {
      strcpy((char *)dst,(char *)"short sword");
    }
  }
  return dst;
}



/* 6386:0411 */

/* WARNING: Instruction at (ram,0x0006014c) overlaps instruction at (ram,0x0006014b)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

far_t * __cdecl16far
stats_6386_0411(char *param_1,uint16_t param_2,undefined2 param_3,far_t param_4)

{
  uint *puVar1;
  byte *pbVar2;
  uint uVar3;
  long lVar4;
  code *pcVar5;
  ulong uVar6;
  uint3 uVar7;
  far_t gfx;
  far_t handle;
  far_t handle_00;
  far_t handle_01;
  far_t handle_02;
  byte bVar8;
  undefined1 uVar9;
  bool bVar10;
  char cVar21;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  byte bVar22;
  char *pcVar15;
  far_t *pfVar16;
  uint16_t uVar17;
  uint uVar18;
  int *piVar19;
  char *pcVar20;
  byte bVar24;
  far_t *in_CX;
  far_t *pfVar23;
  byte bVar25;
  byte bVar26;
  byte bVar27;
  int iVar28;
  undefined2 uVar29;
  undefined2 in_DX;
  char *pcVar30;
  byte *pbVar31;
  undefined2 *puVar32;
  uint *puVar33;
  uint *puVar34;
  undefined1 *puVar36;
  undefined2 unaff_BP;
  uint *puVar37;
  int iVar38;
  far_t *unaff_SI;
  byte *pbVar39;
  byte *pbVar40;
  byte *unaff_DI;
  char *unaff_ES;
  undefined2 uVar41;
  undefined2 unaff_SS;
  undefined2 uVar42;
  bool bVar43;
  byte in_AF;
  longdouble in_ST0;
  undefined4 uVar44;
  char *pcVar45;
  undefined2 in_stack_00000002;
  byte bStack0004;
  undefined1 uStack0005;
  char cStack0008;
  undefined1 uStack0009;
  char cStack000a;
  undefined3 uStack000b;
  char acStack_2cc [698];
  undefined2 uStack_12;
  char *pcStack_10;
  byte in_stack_0000fff2;
  byte in_stack_0000fff4;
  int in_stack_0000fff6;
  undefined1 uVar46;
  char sfx;
  undefined1 in_stack_0000fff8;
  undefined1 uVar47;
  undefined1 in_stack_0000fff9;
  undefined1 in_stack_0000fffa;
  char in_stack_0000fffb;
  undefined1 uVar48;
  undefined1 in_stack_0000fffc;
  char in_stack_0000fffd;
  char *pcVar14;
  uint *puVar35;
  
  uVar41 = _cStack0008;
  pcVar20 = _bStack0004;
  uStack0009 = (undefined1)((uint)_cStack0008 >> 8);
  cStack0008 = (char)uVar41;
  uStack0005 = (undefined1)((uint)_bStack0004 >> 8);
  bStack0004 = (byte)pcVar20;
  if (cStack0008 == '\x01') {
    if (uStack000b._1_1_ == '\0') {
      strcpy(pcVar20,(char *)"short sword" + 0xb);
    }
    else if ('\0' < (char)uStack000b._1_1_) {
      pcStack_10 = (char *)"portrait\\sp20.lbm";
      ovr_stsprintf(pcVar20,"+%d ring of prot.",(char *)(int)(char)uStack000b._1_1_);
    }
                    /* WARNING: Read-only address (ram,0x00024119) is written */
                    /* WARNING: Read-only address (ram,0x0002c58a) is written */
    return (far_t *)(uint)bStack0004;
  }
  bVar27 = cStack000a - uStack000b._1_1_;
  _cStack000a = (far_t)CONCAT31(uStack000b,bVar27);
  if (cStack0008 == '\x03') {
    uVar18 = (int)(char)bVar27 - 6;
    if (4 < uVar18) {
      strcpy(pcVar20,(char *)"+2 leather armor");
      return (far_t *)(uint)bStack0004;
    }
    cVar21 = '`';
    pfVar16 = (far_t *)(uVar18 * 2);
    switch(uVar18) {
    case 0:
      (&stack0xfffe)[(int)unaff_SI] = (&stack0xfffe)[(int)unaff_SI] + '\x01';
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    case 1:
      pcVar5 = (code *)swi(1);
      pfVar16 = (far_t *)(*pcVar5)();
      return pfVar16;
    case 2:
      do {
        pfVar16 = (far_t *)(uint)(byte)(pfVar16 + -0x1db1)->ofs;
        if (pfVar16 == unaff_SI) {
          if ((far_t *)(uint)(byte)(unaff_SI + -0x1db1)->ofs == unaff_SI) {
            pfVar16 = (far_t *)((char *)"puppetmaker" + 3);
            *(char *)&(in_CX + -0x1db1)->ofs = (char)in_CX;
          }
          else {
            cVar21 = (char)(unaff_SI + -0x1db1)->ofs;
            pfVar16 = (far_t *)CONCAT11(0x24,cVar21);
            *(char *)&(in_CX + -0x1db1)->ofs = cVar21;
          }
        }
        do {
          pfVar23 = in_CX;
          in_CX = (far_t *)((int)&pfVar23->ofs + 1);
          if (0xb < (int)in_CX) {
            return pfVar16;
          }
        } while (in_CX == unaff_SI);
        cVar21 = (char)in_CX;
        if ((far_t *)(uint)*(byte *)((int)&pfVar23[-0x1da8].ofs + 1) == unaff_SI) {
          if ((far_t *)(uint)(byte)(unaff_SI + -0x1da8)->ofs == unaff_SI) {
            *(char *)((int)&pfVar23[-0x1da8].ofs + 1) = cVar21;
          }
          else {
            *(char *)((int)&pfVar23[-0x1da8].ofs + 1) = (char)(unaff_SI + -0x1da8)->ofs;
          }
        }
        if ((far_t *)(uint)*(byte *)((int)&pfVar23[-0x1dab].ofs + 1) == unaff_SI) {
          if ((far_t *)(uint)(byte)(unaff_SI + -0x1dab)->ofs == unaff_SI) {
            *(char *)((int)&pfVar23[-0x1dab].ofs + 1) = cVar21;
          }
          else {
            *(char *)((int)&pfVar23[-0x1dab].ofs + 1) = (char)(unaff_SI + -0x1dab)->ofs;
          }
        }
        if ((far_t *)(uint)*(byte *)((int)&pfVar23[-0x1dae].ofs + 1) == unaff_SI) {
          if ((far_t *)(uint)(byte)(unaff_SI + -0x1dae)->ofs == unaff_SI) {
            *(char *)((int)&pfVar23[-0x1dae].ofs + 1) = cVar21;
          }
          else {
            *(char *)((int)&pfVar23[-0x1dae].ofs + 1) = (char)(unaff_SI + -0x1dae)->ofs;
          }
        }
        unaff_ES = (char *)"puppetmaker" + 3;
        pfVar16 = in_CX;
      } while( true );
    case 4:
      if (in_stack_0000fffb == -0x80) {
        sfx = '1';
      }
      else {
        sfx = '4';
      }
      if (in_stack_0000fffd != '0') {
        cVar21 = '`';
        clrscr();
        printf("Sound IRQ is %c (1. Don\'t change  2. IRQ 2  3. IRQ 5\n",(int)cVar21);
        sfx = '\0';
        printf("                                 ",unaff_BP);
        do {
          while (uVar17 = ovr_biosKeyAvail(), (char)uVar17 != '\0') {
            ovr_biosReadKey();
          }
          cVar21 = '\"';
          uVar17 = ovr_biosReadKey();
          if ((uVar17 & 0xff) == 0x1b) {
            printf("\n",unaff_BP);
                    /* WARNING: Subroutine does not return */
            exit(0);
          }
        } while (((((uVar17 & 0xff) != 0x31) && ((uVar17 & 0xff) != 0x32)) &&
                 ((uVar17 & 0xff) != 0x33)) &&
                (((uVar17 & 0xff) != 0x34 && ((uVar17 & 0xff) != 0x35))));
      }
      clrscr();
      bVar10 = write_game_cfg(sfx,cVar21,cVar21);
      if ((far_t *)(uint)bVar10 != (far_t *)0x0) {
        return (far_t *)(uint)bVar10;
      }
                    /* WARNING: Subroutine does not return */
      exit(0x83);
    }
    (&stack0xfffe)[(int)unaff_DI] = (&stack0xfffe)[(int)unaff_DI] + (byte)in_CX;
    unaff_DI[0x54] = 0;
    *(char *)&unaff_SI->ofs = (char)unaff_SI->ofs + (char)(uVar18 >> 8);
    if (((*(int *)&DAT_2410_00e8 == 0) && (8 < DAT_2410_00e4)) &&
       ((DAT_2410_00e4 < 0x19 && ((0xb4 < DAT_2410_00e6 && ((DAT_2410_00e6 < 0xb6 | 0xeU) != 0))))))
    {
      return (far_t *)0x0;
    }
    if ((((DAT_2410_00e8 == 0) && (0xea < DAT_2410_00e4)) && (0x3b < DAT_2410_00e6)) &&
       (DAT_2410_00e4 < 0x139)) {
      uVar18 = (DAT_2410_00e6 - 0x3c) / 0xe;
      if (((uVar18 < CONCAT11(uStack0009,3)) && ((DAT_2410_00e6 - 0x3c) % 0xe < 0xc)) &&
         (*(int *)(pcVar20 + uVar18 * 4) != 0 || *(int *)((int)(pcVar20 + uVar18 * 4) + 2) != 0)) {
        cVar21 = (char)uVar18;
        OVC28_6018_0aac();
        GMenuItem = cVar21 + '\x01';
        return (far_t *)CONCAT11(0x24,cVar21 + '\x01');
      }
    }
    if (((DAT_2410_00e8 == 0) && (DAT_2410_5ce4 != '\0')) &&
       ((0xf < DAT_2410_00e4 && ((0xb2 < DAT_2410_00e6 && (DAT_2410_00e6 < 0xbf)))))) {
      uVar18 = (DAT_2410_00e4 - 0x10) / 0x44;
      if ((uVar18 < 3) && ((DAT_2410_00e4 - 0x10) % 0x44 < 0x43)) {
        GMenuItem = (char)uVar18 + -4;
        return (far_t *)CONCAT11(0x24,GMenuItem);
      }
    }
    if ((((DAT_2410_5cf0 == '\0') || (DAT_2410_00e8 != 0)) || (DAT_2410_00e4 < 0xc)) ||
       (((0xde < DAT_2410_00e4 || (DAT_2410_00e6 < 7)) || (0x96 < DAT_2410_00e6))))
    goto LAB_6018_0ead;
  }
  else {
    piVar19 = (int *)(int)(char)bVar27;
    if ((char *)"Borland C++ - Copyright 1991 Borland Intl." + 4 < piVar19) {
      strcpy(pcVar20,(char *)"no armor");
      return (far_t *)(uint)bStack0004;
    }
    puVar32 = (undefined2 *)((int)piVar19 * 2);
    pcVar30 = "Sound Effects (1. PC Speaker  2. Sound Blaster  3. Pro Audio Spectrum\n";
    bVar8 = (byte)((uint)in_DX >> 8);
    switch(piVar19) {
    case (int *)0x0:
      ovr_vgaSetPalette8bit();
      uVar9 = 0xa6;
      uVar48 = 0x22;
      ovr_blitRect((brect_t *)CONCAT22(unaff_SS,(brect_t *)&pcStack_10));
      TextBlitDstSeg = 0xa000;
      ovr_OVC28_6018_0251();
      for (iVar28 = 0; iVar28 < 5; iVar28 = iVar28 + 1) {
        ovr_draw_2e25_0efd();
        uVar9 = 0xbb;
        uVar48 = 0x22;
        ovr_draw_2e25_0000();
      }
      DAT_2000_d116 = 0xff;
      uVar46 = 0xf6;
      uVar47 = 0x5c;
      ovr_attact_3f0b_2a09();
      handle_02.seg._1_1_ = uVar47;
      handle_02.seg._0_1_ = uVar46;
      handle_02.ofs._1_1_ = uVar48;
      handle_02.ofs._0_1_ = uVar9;
      ovr_stshFree(handle_02);
      ovr_stop_audio();
      DAT_2410_07a6 = 0xff;
      DAT_2410_26a8 = 0;
      return (far_t *)((char *)"puppetmaker" + 3);
    case (int *)0x1:
                    /* WARNING: Read-only address (ram,0x0002c58a) is written */
      s__s_regenerates_3_hitpoints_to_a_t_2410_846c[0x1e] = '\0';
      (unaff_SI + 0xec0)->ofs = (uint16_t)unaff_SI;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case (int *)0x2:
      pfVar16 = DAT_2000_d3ca;
      if (*(byte *)(*piVar19 + 0x86) < 9) {
        pfVar16 = (far_t *)((uint)DAT_2000_d3cc * 0x32 + 0x32);
      }
      __C0_ASM_CopyRight[0x15] = 'h';
      __C0_ASM_CopyRight[0x16] = 't';
      s__s_regenerates_3_hitpoints_to_a_t_2410_846c[0x1e] = 'a';
      return pfVar16;
    case (int *)0x3:
      do {
        uVar46 = (undefined1)unaff_SS;
        uVar47 = (undefined1)((uint)unaff_SS >> 8);
        uVar9 = uVar46;
        uVar48 = uVar47;
        uVar41 = ovr_OVC45_77eb_226e();
        bStack0004 = (byte)in_DX;
        uStack0005 = (undefined1)((uint)in_DX >> 8);
        ovr_blitLabel((char *)CONCAT13(uStack0005,CONCAT12(bStack0004,uVar41)),
                      (uint8_t *)CONCAT13(uStack0009,CONCAT12(cStack0008,param_2)),_cStack000a,
                      uStack000b._1_1_);
        pfVar16 = (far_t *)((char *)"puppetmaker" + 3);
        BlitLetterType = 0;
        pbVar40 = unaff_DI;
        while( true ) {
          while( true ) {
            unaff_DI = pbVar40 + 0xe;
            unaff_SI = (far_t *)((int)&unaff_SI->ofs + 1);
            if (CONCAT11(uStack0009,cStack0008) <= (int)unaff_SI) {
              if (DAT_2410_5cef != -1) {
                _cStack000a = (far_t)CONCAT22(CONCAT11((char)((uint)pfVar16 >> 8),DAT_2410_5cef),
                                              (char *)"steam bath" + 6);
                cStack0008 = 0xad;
                uStack0009 = 7;
                pfVar16 = (far_t *)OVC28_6018_0634();
              }
              return pfVar16;
            }
            piVar19 = (int *)(CONCAT11(uStack0005,bStack0004) + (int)unaff_SI * 4);
            if (*piVar19 != 0 || piVar19[1] != 0) break;
            pfVar16 = (far_t *)0x0;
            pbVar40 = unaff_DI;
          }
          uStack000b._1_2_ = 0xa000;
          _cStack000a = CONCAT11(uVar48,uVar9) + (int)unaff_DI * 0x140;
          cStack0008 = (char)DAT_2000_d37e;
          uStack0009 = (undefined1)((uint)DAT_2000_d37e >> 8);
          param_2 = DAT_2000_d37c;
          bStack0004 = 0xc4;
          uStack0005 = 0x22;
          gfx.seg._0_1_ = cStack0008;
          gfx.ofs = DAT_2000_d37c;
          gfx.seg._1_1_ = uStack0009;
          ovr_blitLoadRleGfx(gfx,_cStack000a);
          TextBlitDstSeg = 0xa000;
          TextBlitX = CONCAT11(uVar48,uVar9) + 6;
          TextBlitY = (uint16_t)(pbVar40 + 0x10);
          puVar32 = (undefined2 *)(CONCAT11(uStack0005,bStack0004) + (int)unaff_SI * 4);
          uVar41 = puVar32[1];
          in_DX = *puVar32;
          uVar9 = (undefined1)uVar41;
          uVar48 = (undefined1)((uint)uVar41 >> 8);
          cStack0008 = (char)FontMain.seg;
          uStack0009 = (undefined1)(FontMain.seg >> 8);
          if (*(char *)CONCAT13(uVar48,CONCAT12(uVar9,in_DX)) == '%') break;
          if (*(char *)CONCAT13(uVar48,CONCAT12(uVar9,in_DX)) == '@') {
            _cStack000a = (far_t)0xf013f;
            param_2 = FontMain.ofs;
            bStack0004 = 3;
            uStack0005 = 0;
            uVar9 = uVar46;
            uVar48 = uVar47;
            uVar41 = ovr_OVC45_77eb_226e();
            bStack0004 = (byte)in_DX;
            uStack0005 = (undefined1)((uint)in_DX >> 8);
            pfVar16 = (far_t *)ovr_blitLabel((char *)CONCAT13(uStack0005,CONCAT12(bStack0004,uVar41)
                                                             ),
                                             (uint8_t *)
                                             CONCAT13(uStack0009,CONCAT12(cStack0008,param_2)),
                                             _cStack000a,uStack000b._1_1_);
            pbVar40 = unaff_DI;
          }
          else {
            _cStack000a = (far_t)0xf013f;
            param_2 = FontMain.ofs;
            bStack0004 = 3;
            uStack0005 = 0;
            uVar9 = uVar46;
            uVar48 = uVar47;
            uVar41 = ovr_OVC45_77eb_226e();
            bStack0004 = (byte)in_DX;
            uStack0005 = (undefined1)((uint)in_DX >> 8);
            pfVar16 = (far_t *)ovr_blitLabel((char *)CONCAT13(uStack0005,CONCAT12(bStack0004,uVar41)
                                                             ),
                                             (uint8_t *)
                                             CONCAT13(uStack0009,CONCAT12(cStack0008,param_2)),
                                             _cStack000a,uStack000b._1_1_);
            pbVar40 = unaff_DI;
          }
        }
        BlitLetterType = 2;
        _cStack000a = (far_t)0xf013f;
        param_2 = FontMain.ofs;
        bStack0004 = 3;
        uStack0005 = 0;
      } while( true );
    case (int *)0x4:
      out(0,bVar27);
      *(char *)((int)puVar32 + 0x3b) = *(char *)((int)puVar32 + 0x3b) + bVar8;
      break;
    case (int *)0x5:
      bVar25 = 9 < (bVar27 & 0xf) | in_AF;
      bVar26 = bVar27 + bVar25 * '\x06';
      cVar21 = ((char)bVar27 >> 7) + bVar25;
      uVar11 = CONCAT11(cVar21,bVar26) & 0xff0f;
      bVar22 = (byte)puVar32;
      uVar12 = CONCAT11(bVar8 + bVar22 + bVar25,(char)in_DX);
      uVar18 = (uint)(CARRY1(bVar8,bVar22) || CARRY1(bVar8 + bVar22,bVar25));
      puVar36 = &stack0xfffe + uVar11 + uVar18;
      puVar1 = (uint *)(puVar36 + (int)unaff_DI + -0x58ef);
      uVar3 = (uint)(CARRY2((uint)&stack0xfffe,uVar11) ||
                    CARRY2((uint)(&stack0xfffe + uVar11),uVar18));
      uVar18 = *puVar1;
      uVar11 = *puVar1;
      *puVar1 = (uint)(unaff_DI + uVar11 + uVar3);
      puVar1 = (uint *)(unaff_DI + -0x7aef);
      uVar3 = (uint)(CARRY2(uVar18,(uint)unaff_DI) || CARRY2((uint)(unaff_DI + uVar11),uVar3));
      uVar18 = *puVar1;
      uVar11 = *puVar1;
      *puVar1 = uVar11 + (int)puVar32 + uVar3;
      *(int *)((int)puVar32 + 0x11) =
           *(int *)((int)puVar32 + 0x11) + uVar12 +
           (uint)(CARRY2(uVar18,(uint)puVar32) || CARRY2(uVar11 + (int)puVar32,uVar3));
      bVar10 = CARRY2(uVar12,*(uint *)((int)puVar32 + (int)unaff_DI));
      iVar28 = uVar12 + *(uint *)((int)puVar32 + (int)unaff_DI);
      *(double *)((int)puVar32 + (int)unaff_SI) = (double)in_ST0;
      bVar8 = ((byte)in_CX & 0x1f) % 0x11;
      uVar7 = CONCAT12(bVar10,*(undefined2 *)(char *)((int)puVar32 + (int)unaff_SI));
      uVar6 = (ulong)uVar7 << bVar8 | (ulong)(uVar7 >> 0x11 - bVar8);
      *(int *)(char *)((int)puVar32 + (int)unaff_SI) = (int)uVar6;
      bVar27 = *(byte *)((int)puVar32 + (int)unaff_SI);
      *(byte *)((int)puVar32 + (int)unaff_SI) =
           bVar27 << 4 |
           (byte)(CONCAT11((bVar8 == 0) * bVar10 | (bVar8 != 0) * ((uVar6 & 0x10000) != 0),bVar27)
                 >> 5);
      bVar10 = (bVar27 & 0x10) != 0;
      pbVar2 = puVar36 + 0x5110;
      bVar27 = *pbVar2;
      bVar8 = *pbVar2;
      *pbVar2 = bVar8 + bVar22 + bVar10;
      *(byte *)(puVar32 + 8) =
           *(char *)(puVar32 + 8) + (bVar26 & 0xf) +
           (CARRY1(bVar27,bVar22) || CARRY1(bVar8 + bVar22,bVar10));
      uVar18 = CONCAT11(cVar21,bVar26) & 0xff0f ^ 0x10;
      bVar25 = (byte)iVar28;
      bVar10 = bVar25 < *(byte *)((int)puVar32 + (int)unaff_SI);
      bVar22 = (byte)((uint)iVar28 >> 8);
      bVar25 = bVar25 - *(byte *)((int)puVar32 + (int)unaff_SI);
      bVar27 = *(byte *)((int)puVar32 + (int)unaff_SI);
      bVar8 = bVar25 + *(byte *)((int)puVar32 + (int)unaff_SI);
      bVar26 = bVar8 + bVar10;
      out(CONCAT11(bVar22,bVar26),uVar18);
      uVar18 = CONCAT11(cVar21,*(undefined1 *)(ulong)((int)puVar32 + (uVar18 & 0xff)));
      *puVar32 = CONCAT11(bVar22,bVar26);
      if (!CARRY1(bVar25,bVar27) && !CARRY1(bVar8,bVar10)) {
        _cStack000a = (far_t)CONCAT22(0x6000,_cStack000a);
        pcVar5 = (code *)swi(3);
        pfVar16 = (far_t *)(*pcVar5)();
        return pfVar16;
      }
      iVar28 = (bVar26 & 3) - (AgntAnms[0x6e]._17_2_ & 3);
      AgntAnms[0x6e]._17_2_ = AgntAnms[0x6e]._17_2_ + (uint)(0 < iVar28) * iVar28;
      uVar11 = (uint)unaff_SI ^ 0xdd16;
      LOCK();
      bVar27 = *unaff_DI;
      *unaff_DI = bVar26;
      UNLOCK();
      pbVar31 = (byte *)((int)puVar32 + 1);
      *unaff_DI = *unaff_DI & bVar27;
      *(undefined2 *)0xa813 = in_stack_00000002;
      bVar8 = (byte)((char *)"Resetting game..." + 7 +
                    (int)((char *)"ping.xmi" + 3 + uVar11 +
                         (uint)(0xea61 < uVar11 + 0x15c6 ||
                               CARRY2((uint)((char *)"ping.xmi" + 3 + uVar11),
                                      (uint)(0xea39 < uVar11))) + (uint)(0xea39 < uVar11)));
      bVar10 = 0x34 < (byte)(bVar8 - 0x20) || CARRY1(bVar8 + 0xab,0x1f < bVar8);
      bVar25 = bVar8 + 0xab + (0x1f < bVar8);
      bVar8 = bVar25 + 0xbe;
      bVar43 = 0x41 < bVar25 || CARRY1(bVar8,bVar10);
      bVar8 = bVar8 + bVar10;
      bVar25 = bVar8 + 0xa0;
      bVar10 = 0x5f < bVar8 || CARRY1(bVar25,bVar43);
      bVar25 = bVar25 + bVar43;
      bVar8 = bVar25 + 0x93;
      bVar43 = 0x6c < bVar25 || CARRY1(bVar8,bVar10);
      bVar8 = bVar8 + bVar10;
      bVar25 = bVar8 + 0x7d;
      bVar10 = 0x82 < bVar8 || CARRY1(bVar25,bVar43);
      bVar25 = bVar25 + bVar43;
      bVar8 = bVar25 + 0x61;
      bVar43 = 0x9e < bVar25 || CARRY1(bVar8,bVar10);
      bVar8 = bVar8 + bVar10;
      bVar25 = bVar8 + 0x57;
      bVar10 = 0xa8 < bVar8 || CARRY1(bVar25,bVar43);
      bVar25 = bVar25 + bVar43;
      bVar8 = bVar25 + 0x43;
      bVar43 = 0xbc < bVar25 || CARRY1(bVar8,bVar10);
      bVar8 = bVar8 + bVar10;
      bVar25 = bVar8 + 0x39;
      bVar10 = 0xc6 < bVar8 || CARRY1(bVar25,bVar43);
      bVar25 = bVar25 + bVar43;
      bVar8 = bVar25 + 0x23;
      bVar43 = 0xdc < bVar25 || CARRY1(bVar8,bVar10);
      bVar8 = bVar8 + bVar10;
      bVar25 = bVar8 + 0xb;
      bVar10 = 0xf4 < bVar8 || CARRY1(bVar25,bVar43);
      bVar25 = bVar25 + bVar43;
      bVar8 = bVar25 + 0x8d;
      uVar12 = CONCAT11((char)((uint)((char *)"Resetting game..." + 7 +
                                     (int)((char *)"ping.xmi" + 3 + uVar11 +
                                          (uint)(0xea61 < uVar11 + 0x15c6 ||
                                                CARRY2((uint)((char *)"ping.xmi" + 3 + uVar11),
                                                       (uint)(0xea39 < uVar11))) +
                                          (uint)(0xea39 < uVar11))) >> 8),bVar8 + bVar10);
      uVar11 = (uint)(0x72 < bVar25 || CARRY1(bVar8,bVar10));
      uVar3 = uVar12 - *(uint *)(pbVar31 + uVar18 + 0x5c1b);
      pbVar13 = (byte *)(uVar3 - uVar11);
      uVar11 = (uint)(uVar12 < *(uint *)(pbVar31 + uVar18 + 0x5c1b) || uVar3 < uVar11);
      uVar3 = (int)in_CX - *(uint *)(puVar36 + 0x1b);
      iVar28 = uVar3 - uVar11;
      uVar11 = (uint)(in_CX < *(far_t **)(puVar36 + 0x1b) || uVar3 < uVar11);
      uVar3 = uVar18 - *(uint *)(pbVar31 + uVar18);
      puVar37 = (uint *)(uVar3 - uVar11);
      uVar18 = (uint)(uVar18 < *(uint *)(pbVar31 + uVar18) || uVar3 < uVar11);
      uVar3 = 0xa814 - AgntAnms[0x39]._21_2_;
      iVar38 = -uVar18;
      uVar18 = (uint)(0xa814 < (uint)AgntAnms[0x39]._21_2_ || uVar3 < uVar18);
      pbVar39 = (byte *)(((int)unaff_DI - (int)pbVar13) - uVar18);
      bVar10 = bVar22 < (pbVar31 + (int)pbVar39)[-0x5be6] ||
               (byte)(bVar22 - (pbVar31 + (int)pbVar39)[-0x5be6]) <
               (unaff_DI < pbVar13 || (uint)((int)unaff_DI - (int)pbVar13) < uVar18);
      bVar8 = (byte)iVar28;
      bVar25 = bVar8 - pbVar39[0x3e1a];
      bVar43 = bVar8 < pbVar39[0x3e1a] || bVar25 < bVar10;
      bVar26 = (byte)((uint)iVar28 >> 8);
      bVar25 = bVar25 - bVar10;
      bVar8 = bVar26 - bVar27;
      bVar24 = bVar8 - bVar43;
      pbVar2 = pbVar39 + 0x4119;
      uVar18 = (uint)(bVar26 < bVar27 || bVar8 < bVar43);
      pbVar40 = *(byte **)pbVar2;
      iVar28 = *(int *)pbVar2;
      *(uint *)pbVar2 = (iVar28 - (int)pbVar13) - uVar18;
      puVar1 = puVar37;
      uVar11 = (uint)(pbVar40 < pbVar13 || (uint)(iVar28 - (int)pbVar13) < uVar18);
      puVar33 = (uint *)*puVar1;
      uVar18 = *puVar1;
      *puVar1 = (uVar18 - (int)puVar37) - uVar11;
                    /* WARNING: Read-only address (ram,0x00024119) is written */
      uVar18 = (uint)(puVar33 < puVar37 || uVar18 - (int)puVar37 < uVar11);
      uVar11 = 0x7468 - CONCAT11(bVar24,bVar25);
      __C0_ASM_CopyRight._21_2_ = uVar11 - uVar18;
      uVar18 = (uint)((uint)0x7468 < CONCAT11(bVar24,bVar25) || uVar11 < uVar18);
      piVar19 = (int *)-uVar18;
      bVar22 = (byte)((uint)pbVar13 >> 8);
      bVar10 = bVar27 < bVar22 || (byte)(bVar27 - bVar22) < (uVar18 != 0);
      bVar8 = (bVar27 - bVar22) - (uVar18 != 0);
      bVar27 = (byte)pbVar13 - (byte)pbVar31;
      bVar26 = bVar27 - bVar10;
      bVar10 = bVar8 < bVar26 ||
               (byte)(bVar8 - bVar26) < ((byte)pbVar13 < (byte)pbVar31 || bVar27 < bVar10);
      pbVar2 = (byte *)((char *)"%s turns %d undead." + 9 + (int)puVar36 + (int)piVar19);
      bVar27 = *pbVar2;
      bVar8 = *pbVar2;
      *pbVar2 = (bVar8 - bVar24) - bVar10;
      pcVar45 = (char *)((int)puVar36 + (int)piVar19 + 0x18);
      *pcVar45 = (*pcVar45 - bVar22) - (bVar27 < bVar24 || (byte)(bVar8 - bVar24) < bVar10);
      bVar10 = (char *)CONCAT11(bVar22,bVar26) < (char *)"ringmaker\'s shop" + 10;
      bVar26 = bVar26 - 0x18;
      pbVar2 = pbVar31;
      bVar43 = *pbVar2 < bVar25 || (byte)(*pbVar2 - bVar25) < bVar10;
      *pbVar2 = (*pbVar2 - bVar25) - bVar10;
      pbVar2 = pbVar39;
      bVar27 = *pbVar2;
      bVar8 = *pbVar2;
      *pbVar2 = (bVar8 - bVar26) - bVar43;
      uVar41 = CONCAT11(bVar24,(bVar25 - bVar26) -
                               (bVar27 < bVar26 || (byte)(bVar8 - bVar26) < bVar43));
      uVar42 = *(undefined2 *)(uVar3 + iVar38 + 2);
      puVar33 = (uint *)(uVar3 + iVar38 + 4);
      pcVar5 = (code *)swi(0x1e);
      uVar44 = (*pcVar5)();
      uVar29 = (undefined2)((ulong)uVar44 >> 0x10);
      uVar18 = (uint)uVar44;
      uVar11 = *puVar33;
      *puVar33 = uVar42;
      puVar33[-1] = uVar42;
      bVar27 = (byte)((ulong)uVar44 >> 0x10);
      if (((uVar11 & 0x800) != 0) == ((uVar11 & 0x80) != 0)) {
code_r0x0006013c:
        lVar4 = (long)*piVar19 * 0x48;
        bVar10 = (int)lVar4 != lVar4;
        bVar25 = (byte)uVar18 - 0x1d;
        bVar43 = (byte)uVar18 < 0x1d || bVar25 < bVar10;
        bVar25 = bVar25 - bVar10;
        bVar26 = bVar25 + 3;
        bVar8 = bVar26 - bVar43;
        pbVar39 = pbVar39 + (-(uint)(bVar25 < 0xfd || bVar26 < bVar43) - (int)puVar33);
        pbVar31 = (byte *)CONCAT11((byte)((ulong)lVar4 >> 8) & (byte)((uint)uVar41 >> 8) & bVar8,
                                   (char)lVar4);
        (puVar36 + (int)pbVar39)[-0x62e0] =
             (puVar36 + (int)pbVar39)[-0x62e0] & (byte)((ulong)uVar44 >> 0x18);
        (pbVar31 + (int)pbVar39)[0x6f20] = (pbVar31 + (int)pbVar39)[0x6f20] & (byte)uVar41;
      }
      else {
        puVar33[-2] = uVar18;
        puVar33[-3] = uVar41;
        puVar33[-4] = uVar29;
        puVar33[-5] = (uint)pbVar31;
        puVar33[-6] = (uint)(puVar33 + -1);
        puVar33[-7] = (uint)puVar36;
        puVar33[-8] = (uint)piVar19;
        puVar33[-9] = (uint)pbVar39;
        puVar34 = puVar33 + -10;
        puVar35 = puVar33 + -10;
        puVar33[-10] = uVar42;
        uVar9 = in(uVar29);
        pcVar14 = (char *)CONCAT11((char)((ulong)uVar44 >> 8),uVar9);
        pcVar20 = (char *)(uint)((uVar11 & 1) != 0);
        pcVar30 = pcVar14 + -0x1dad;
        pcVar15 = pcVar30 + -(int)pcVar20;
        bVar8 = 0;
        puVar33 = puVar33 + -10;
        if (pcVar15 != (char *)0x0) {
          pcVar20 = (char *)(uint)(pcVar14 < (char *)"black market" + 9 || pcVar30 < pcVar20);
          bVar10 = pcVar15 < (char *)"magicians\' room" + 6 || pcVar15 + -0x1d54 < pcVar20;
          uVar18 = (int)(pcVar15 + -0x1d54) - (int)pcVar20;
          puVar33 = puVar34;
          puVar37 = puVar35;
          if (-1 < (int)uVar18) goto LAB_5ded_2288;
          goto code_r0x0006013c;
        }
      }
      (puVar36 + (int)pbVar39)[0x20] = (puVar36 + (int)pbVar39)[0x20] & bVar27;
      bVar10 = false;
      uVar18 = (uint)(bVar8 ^ 0x20);
      puVar37 = puVar33;
LAB_5ded_2288:
      cVar21 = ((char)uVar18 + -0x20) - bVar10;
      pbVar31[(int)piVar19] = pbVar31[(int)piVar19] + cVar21;
      pbVar31[(int)piVar19] = pbVar31[(int)piVar19] + cVar21;
      pbVar31[(int)piVar19] = pbVar31[(int)piVar19] + cVar21;
      pbVar31[(int)piVar19] = pbVar31[(int)piVar19] + cVar21;
      pbVar31[(int)piVar19] = pbVar31[(int)piVar19] + cVar21;
      pbVar31[(int)piVar19] = pbVar31[(int)piVar19] + cVar21;
      pbVar31[(int)piVar19] = pbVar31[(int)piVar19] + cVar21;
      pbVar31[(int)piVar19] = pbVar31[(int)piVar19] + cVar21;
      pbVar31[(int)piVar19] = pbVar31[(int)piVar19] + cVar21;
      pbVar31[(int)piVar19] = pbVar31[(int)piVar19] + cVar21;
      pbVar31[(int)piVar19] = pbVar31[(int)piVar19] + cVar21;
      pbVar31[(int)piVar19] = pbVar31[(int)piVar19] + cVar21;
      pbVar31[(int)piVar19] = pbVar31[(int)piVar19] + cVar21;
      pbVar31[(int)piVar19] = pbVar31[(int)piVar19] + cVar21;
      pbVar31[(int)piVar19] = pbVar31[(int)piVar19] + cVar21;
      pbVar31[(int)piVar19] = pbVar31[(int)piVar19] + cVar21;
      pbVar31[(int)piVar19] = pbVar31[(int)piVar19] + cVar21;
      pbVar31[(int)piVar19] = pbVar31[(int)piVar19] + cVar21;
      pbVar39[-0x75] = pbVar39[-0x75] + bVar27;
      in(uVar29);
      *(undefined2 *)((int)puVar37 + -6) = piVar19;
      iVar28 = *(int *)(puVar36 + 6);
      do {
        iVar38 = iVar28 + -1;
        if (iVar28 == 0) {
          return (far_t *)0x0;
        }
        uVar41 = *(undefined2 *)BDA_DailyTimeCounter;
        *(undefined2 *)(puVar36 + -2) = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
        *(undefined2 *)(puVar36 + -4) = uVar41;
        do {
          iVar28 = iVar38;
          if (*(int *)(BDA_DailyTimeCounter.ofs + 2) != *(int *)(puVar36 + -2)) break;
        } while (*(int *)BDA_DailyTimeCounter == *(int *)(puVar36 + -4));
      } while( true );
    case (int *)0x6:
      *(byte *)(puVar32 + 0x15) = bVar27;
      if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[7].seg + 1 + ((uint)pcVar20 & 0xff) * 0x95) & 0x800
          ) != 0) {
        *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x2d) = 0x12;
      }
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x3f) =
           *(undefined1 *)((int)(char **)GMenuStrings + ((uint)pcVar20 & 0xff) * 0x95 + 0x1f);
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x33) =
           *(undefined1 *)
            ((int)(far_t *)(far_t_ARRAY_2410_26f7 + 9) + ((uint)pcVar20 & 0xff) * 0x95);
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x31) =
           *(undefined1 *)((int)&far_t_ARRAY_2410_26f7[6].seg + ((uint)pcVar20 & 0xff) * 0x95);
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x32) =
           *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x31);
      pbVar2 = (byte *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x28);
      *pbVar2 = *pbVar2 | 0x16;
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x40) = 1;
      iVar28 = CONCAT11(in_stack_0000fffb,in_stack_0000fffa);
      uVar41 = (undefined2)(CONCAT13(in_stack_0000fffd,CONCAT12(in_stack_0000fffc,iVar28)) >> 0x10);
      *(undefined2 *)(iVar28 + 0x58) = 0;
      *(undefined2 *)(iVar28 + 0x56) = 100;
      *(undefined1 *)(CONCAT11(in_stack_0000fffb,in_stack_0000fffa) + 0x89) = 0xff;
      bVar27 = 0x5d;
      ovr_OVC22_5087_056e();
      return (far_t *)(uint)bVar27;
    case (int *)0x7:
      do {
        unaff_DI = (byte *)((uint)unaff_DI | *(uint *)((int)puVar32 + (int)piVar19 + -4) & 0x3000);
        unaff_SI = (far_t *)((int)&unaff_SI->ofs + 1);
        while( true ) {
          if ((int)unaff_SI < 4) break;
          pfVar16 = (far_t *)CONCAT11(in_stack_0000fffb,in_stack_0000fffa);
          if (unaff_DI == (byte *)&AgntAnms[0x38].field_0x18) {
            DAT_2000_d3ca = (far_t *)((int)&DAT_2000_d3ca->ofs + 1);
            pfVar16 = (far_t *)CONCAT11(in_stack_0000fffb,in_stack_0000fffa);
          }
          do {
            pfVar16 = (far_t *)((int)&pfVar16->ofs + 1);
            if (DAT_2000_ca99 <= pfVar16) {
              return DAT_2000_ca99;
            }
            uVar41 = (undefined2)((ulong)DAT_2000_ca95 >> 0x10);
            bVar27 = *(byte *)((int)DAT_2000_ca95 + (int)pfVar16 * 9 + 2);
          } while ((((*(uint *)((uint)*(byte *)((int)DAT_2000_ca95 + (int)pfVar16 * 9) * 0x27 +
                               0x121) & 0x60) != 0) || (bVar27 == 0xff)) ||
                  (uVar44 = *(undefined4 *)((uint)bVar27 << 2),
                  *(char *)((int)uVar44 + 0x3f) != '\0'));
          in_stack_0000fffa = SUB21(pcVar30,0);
          in_stack_0000fffb = (char)((uint)pcVar30 >> 8);
          pcVar30 = (char *)"dwarf outpost" + 6;
          uVar41 = ovr_OVC23_55fe_3450();
          in_stack_0000fff8 = (undefined1)uVar41;
          in_stack_0000fff9 = (undefined1)((uint)uVar41 >> 8);
          in_stack_0000fff6 =
               *(int *)((int)DAT_2000_ca95 + CONCAT11(in_stack_0000fffb,in_stack_0000fffa) * 9 + 6);
          unaff_DI = (byte *)0x0;
          unaff_SI = (far_t *)0x0;
        }
        unaff_ES = (char *)((ulong)DAT_2000_cb09 >> 0x10);
        puVar32 = (undefined2 *)((int)DAT_2000_cb09 + in_stack_0000fff6 * 0x128);
        piVar19 = (int *)((int)((int)&unaff_SI->ofs + CONCAT11(in_stack_0000fff9,in_stack_0000fff8))
                         * 2);
      } while( true );
    case (int *)0x8:
      pcVar30 = (char *)"halfling castle" + 0xc;
      uVar44 = *(undefined4 *)(((uint)pcVar20 & 0xff) << 2);
      if (*(uint *)((int)*(undefined4 *)piVar19 + 0x54) < (uint)-*(int *)((int)uVar44 + 0x4d)) {
        bVar27 = 5;
      }
      else {
        bVar27 = 4;
      }
      if (((in_stack_0000fff4 == 0) || (in_stack_0000fff4 < in_stack_0000fff2)) ||
         (in_stack_0000fff4 < bVar27)) {
        if ((in_stack_0000fff2 == 0) || (in_stack_0000fff2 < bVar27)) {
          if (bVar27 == 0) {
            pcVar20 = (char *)OVC39_690b_00d1();
            pcStack_10 = "Sound Effects (1. PC Speaker  2. Sound Blaster  3. Pro Audio Spectrum\n";
            uStack_12 = 0x9bb1;
            ovr_stsprintf(acStack_2cc,
                          (char *)CONCAT13((char)((uint)_DAT_2410_6ac6 >> 8),
                                           CONCAT12((char)_DAT_2410_6ac6,DAT_2410_6ac4)),pcVar20);
            pfVar16 = (far_t *)ovr_drawString();
          }
          else {
            OVC39_690b_0000();
            pcVar20 = (char *)OVC39_690b_00d1();
            pcStack_10 = "Sound Effects (1. PC Speaker  2. Sound Blaster  3. Pro Audio Spectrum\n";
            uStack_12 = 0x9b7b;
            pcVar45 = ovr_stsprintf(acStack_2cc,
                                    (char *)CONCAT13((char)((uint)pcVar30 >> 8),
                                                     CONCAT12((char)pcVar30,pcVar20)),pcVar20);
            uVar46 = (undefined1)((ulong)pcVar45 >> 0x10);
            uVar47 = (undefined1)((ulong)pcVar45 >> 0x18);
            uVar9 = SUB41(pcVar45,0);
            uVar48 = (undefined1)((ulong)pcVar45 >> 8);
            pfVar16 = (far_t *)ovr_drawString();
            handle_01.ofs._1_1_ = uVar48;
            handle_01.ofs._0_1_ = uVar9;
            handle_01.seg._0_1_ = uVar46;
            handle_01.seg._1_1_ = uVar47;
            ovr_stshFree(handle_01);
          }
        }
        else {
          OVC39_690b_0000();
          pcVar20 = (char *)OVC39_690b_00d1();
          pcStack_10 = "Sound Effects (1. PC Speaker  2. Sound Blaster  3. Pro Audio Spectrum\n";
          uStack_12 = 0x9b2e;
          pcVar45 = ovr_stsprintf(acStack_2cc,
                                  (char *)CONCAT13((char)((uint)pcVar30 >> 8),
                                                   CONCAT12((char)pcVar30,pcVar20)),pcVar20);
          uVar46 = (undefined1)((ulong)pcVar45 >> 0x10);
          uVar47 = (undefined1)((ulong)pcVar45 >> 0x18);
          uVar9 = SUB41(pcVar45,0);
          uVar48 = (undefined1)((ulong)pcVar45 >> 8);
          pfVar16 = (far_t *)ovr_drawString();
          handle_00.ofs._1_1_ = uVar48;
          handle_00.ofs._0_1_ = uVar9;
          handle_00.seg._0_1_ = uVar46;
          handle_00.seg._1_1_ = uVar47;
          ovr_stshFree(handle_00);
        }
      }
      else {
        OVC39_690b_0000();
        pcVar20 = (char *)OVC39_690b_00d1();
        pcStack_10 = "Sound Effects (1. PC Speaker  2. Sound Blaster  3. Pro Audio Spectrum\n";
        uStack_12 = 0x9ad8;
        pcVar45 = ovr_stsprintf(acStack_2cc,
                                (char *)CONCAT13((char)((uint)pcVar30 >> 8),
                                                 CONCAT12((char)pcVar30,pcVar20)),pcVar20);
        uVar46 = (undefined1)((ulong)pcVar45 >> 0x10);
        uVar47 = (undefined1)((ulong)pcVar45 >> 0x18);
        uVar9 = SUB41(pcVar45,0);
        uVar48 = (undefined1)((ulong)pcVar45 >> 8);
        pfVar16 = (far_t *)ovr_drawString();
        handle.ofs._1_1_ = uVar48;
        handle.ofs._0_1_ = uVar9;
        handle.seg._0_1_ = uVar46;
        handle.seg._1_1_ = uVar47;
        ovr_stshFree(handle);
      }
      return pfVar16;
    }
  }
  if (DAT_2410_00e8 == 0) {
    OVC28_6018_0251();
    ovr_OVC13_3d16_1945();
    return (far_t *)((int)&GUnitDescriptions[4].seg + 1);
  }
LAB_6018_0ead:
  if (((DAT_2410_5cf0 == '\0') || (DAT_2410_00e8 != 0)) ||
     (((DAT_2410_00e4 < 0xef || ((0x134 < DAT_2410_00e4 || (DAT_2410_00e6 < 7)))) ||
      (0x36 < DAT_2410_00e6)))) {
    pfVar16 = (far_t *)(GUnitDescriptions + 5);
  }
  else {
    OVC28_6018_0251();
    ovr_OVC13_3d16_1a01();
    pfVar16 = (far_t *)((int)&GUnitDescriptions[4].seg + 1);
  }
                    /* WARNING: Read-only address (ram,0x00024119) is written */
                    /* WARNING: Read-only address (ram,0x0002c58a) is written */
  return pfVar16;
}



/* 6386:05d3 */

char __cdecl16far stats_6386_05d3(undefined4 param_1)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  undefined2 uVar5;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  bVar1 = *(byte *)(iVar4 + 0xd);
  if (*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)bVar1 * 0x95) == -1) {
    cVar2 = *(char *)((int)&far_t_ARRAY_2410_26f7[9].seg + (uint)bVar1 * 0x95);
  }
  else {
    cVar2 = ovr_agnt_3b1d_0cc6(iVar4,uVar5);
    cVar2 = *(char *)((int)&far_t_ARRAY_2410_26f7[9].seg + (uint)bVar1 * 0x95) - cVar2;
    cVar3 = ovr_agnt_3b1d_0c1e(CONCAT11((char)((uint)bVar1 * 0x95 >> 8),
                                        *(undefined1 *)(iVar4 + 0x1a)),3);
    cVar2 = cVar2 - cVar3;
  }
  return cVar2;
}



/* 6386:065c */

char * __cdecl16far stats_6386_065c(char *param_1,char *param_2,int param_3)

{
  size_t sVar1;
  long n;
  
  if ((param_3 < 0x10) && ((param_3 < 0xf || (param_2 <= (char *)"build\\dwfmas01.lbm" + 4)))) {
    param_1._0_2_ = ovr_litoa10((char *)param_1,(long)CONCAT22(param_3,param_2));
  }
  else {
    n = LDIV_at_((long)CONCAT22(param_3,param_2),1000);
    ovr_litoa10((char *)param_1,n);
    sVar1 = strlen((char *)param_1);
    ((char *)param_1)[sVar1] = 'K';
    ((char *)param_1)[sVar1 + 1] = '\0';
  }
  return (char *)param_1;
}



/* 6386:06cd */

/* WARNING: Variable defined which should be unmapped: cmap */

void __cdecl16far drawAgntStats(int32_t agnt,far_t cmap)

{
  undefined4 uVar1;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  undefined1 extraout_AH;
  undefined1 uVar10;
  char *pcVar5;
  undefined2 *puVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  undefined2 in_DX;
  undefined2 uVar11;
  int agnt_o;
  undefined2 agnt_s;
  undefined2 uVar12;
  uint16_t unaff_SS;
  char *pcVar13;
  undefined1 uVar14;
  uint8_t *puVar15;
  int16_t iVar16;
  uint8_t uVar17;
  undefined1 palbuf [768];
  char buf [80];
  char local_f6 [120];
  char local_7e [121];
  uint8_t field_index;
  char cStack_4;
  int8_t cStack_3;
  
  TextBlitDstSeg = 0xa000;
  if (cmap.ofs == 0 && cmap.seg == 0) {
    cmap.seg = unaff_SS;
    cmap.ofs = (uint16_t)palbuf;
  }
  if (!GameRunning) {
    stats_6386_00f8();
  }
  uVar10 = 0x24;
  agnt_o = (int)agnt;
  agnt_s = (undefined2)((ulong)agnt >> 0x10);
  if (DebugVerbose != false) {
    printf("Exp %ld \r",*(undefined2 *)((int)*(undefined4 *)(agnt_o + 0x17) + 0x10));
    uVar10 = extraout_AH;
  }
  field_index = (*(uint *)((int)*(undefined4 *)(agnt_o + 0x17) + 0x16) & 1) != 0;
  cStack_4 = field_index;
  if (3 < *(byte *)((int)*(undefined4 *)(agnt_o + 0x17) + 0xf)) {
    cStack_4 = field_index + '\x04';
  }
  stats_6386_01a4(*(undefined2 *)(agnt_o + 0x1d),*(undefined2 *)(agnt_o + 0x1f),
                  CONCAT11(uVar10,cStack_4),cmap.ofs,cmap.seg);
  TextBlitY = 10;
  TextBlitX = 0x87;
  uVar17 = 0xe0;
  iVar16 = 222;
  puVar15 = (uint8_t *)CONCAT22(Font02.seg,Font02.ofs);
  uVar14 = (undefined1)((ulong)agnt >> 0x10);
  uVar10 = (undefined1)agnt;
  pcVar5 = (char *)ovr_agnt_3b1d_0ac0(uVar10,uVar14,local_7e);
  ovr_blitLabel((char *)CONCAT22(in_DX,pcVar5),puVar15,iVar16,uVar17);
  if ((GameRunning == false) &&
     ((*(char *)*(undefined4 *)(agnt_o + 0x1d) == '\0' || (DebugVerbose != false)))) {
    TextBlitY = 0xb5;
    TextBlitX = 0x13;
    if ((*(byte *)((int)*(undefined4 *)(agnt_o + 0x17) + 0x33) & 1) == 0) {
      gfx_00.seg._0_1_ = (char)DAT_2000_d376;
      gfx_00.ofs = DAT_2000_d374;
      gfx_00.seg._1_1_ = (char)((uint)DAT_2000_d376 >> 8);
      ovr_blitGfxRect(gfx_00,16,179,BlitRects + 1,0x10,false);
    }
    else {
      gfx.seg._0_1_ = (char)DAT_2000_d37a;
      gfx.ofs = DAT_2000_d378;
      gfx.seg._1_1_ = (char)((uint)DAT_2000_d37a >> 8);
      ovr_blitGfxRect(gfx,16,179,BlitRects + 1,0x10,false);
      TextBlitX = 0x47;
      ovr_blitLabel("\x7f",(uint8_t *)CONCAT22(Font01.seg,Font01.ofs),222,0xe0);
      TextBlitX = 0x13;
    }
    ovr_blitLabel("Ready",(uint8_t *)CONCAT22(Font01.seg,Font01.ofs),222,0xe0);
    TextBlitY = 0xb5;
    TextBlitX = 0x57;
    cVar4 = stats_6386_1572(*(undefined2 *)(agnt_o + 0x1b));
    if (cVar4 == '\0') {
      gfx_02.seg._0_1_ = (char)DAT_2000_d376;
      gfx_02.ofs = DAT_2000_d374;
      gfx_02.seg._1_1_ = (char)((uint)DAT_2000_d376 >> 8);
      ovr_blitGfxRect(gfx_02,84,179,BlitRects + 1,0x10,false);
    }
    else {
      gfx_01.seg._0_1_ = (char)DAT_2000_d37a;
      gfx_01.ofs = DAT_2000_d378;
      gfx_01.seg._1_1_ = (char)((uint)DAT_2000_d37a >> 8);
      ovr_blitGfxRect(gfx_01,84,179,BlitRects + 1,0x10,false);
      TextBlitX = 0x8b;
      ovr_blitLabel("\x7f",(uint8_t *)CONCAT22(Font01.seg,Font01.ofs),222,0xe0);
      TextBlitX = 0x57;
    }
    ovr_blitLabel("Home",(uint8_t *)CONCAT22(FontMain.seg,FontMain.ofs),222,0xe0);
    TextBlitY = 0xb5;
    TextBlitX = 0x9b;
    cVar4 = stats_6386_1572(*(undefined2 *)(agnt_o + 0x1b));
    if ((cVar4 == '\0') && ((*(byte *)((int)*(undefined4 *)(agnt_o + 0x17) + 0x33) & 1) == 0)) {
      gfx_03.seg._0_1_ = (char)DAT_2000_d37a;
      gfx_03.ofs = DAT_2000_d378;
      gfx_03.seg._1_1_ = (char)((uint)DAT_2000_d37a >> 8);
      ovr_blitGfxRect(gfx_03,152,179,BlitRects + 1,0x10,false);
      TextBlitX = 0xcf;
      ovr_blitLabel("\x7f",(uint8_t *)CONCAT22(Font01.seg,Font01.ofs),222,0xe0);
      TextBlitX = 0x9b;
    }
    else {
      gfx_04.seg._0_1_ = (char)DAT_2000_d376;
      gfx_04.ofs = DAT_2000_d374;
      gfx_04.seg._1_1_ = (char)((uint)DAT_2000_d376 >> 8);
      ovr_blitGfxRect(gfx_04,152,179,BlitRects + 1,0x10,false);
    }
    ovr_blitLabel("Unassigned",(uint8_t *)CONCAT22(FontMain.seg,FontMain.ofs),222,0xe0);
  }
  TextBlitY = 0x11;
  TextBlitX = 0x87;
  uVar17 = 0xe0;
  iVar16 = 222;
  puVar15 = (uint8_t *)CONCAT22(Font02.seg,Font02.ofs);
  pcVar13 = ovr_stsprintf(local_7e,"Unit of %d",
                          (char *)(uint)*(byte *)((int)*(undefined4 *)(agnt_o + 0x17) + 0xe));
  uVar7 = (uint)((ulong)pcVar13 >> 0x10);
  ovr_blitLabel(pcVar13,puVar15,iVar16,uVar17);
  pcVar13 = (char *)((ulong)uVar7 << 0x10);
  TextBlitY = 0x1b;
  TextBlitX = 0x87;
  if (*(char *)((int)*(undefined4 *)(agnt_o + 0x17) + 0x1a) != -1) {
    puVar6 = (undefined2 *)((uint)*(byte *)((int)*(undefined4 *)(agnt_o + 0x17) + 0x1a) * 4);
    uVar7 = ovr_font_302d_06ea(*puVar6,puVar6[1],Font02.ofs,Font02.seg);
    if (uVar7 < 0x30) {
      uVar17 = 0xe0;
      iVar16 = 222;
      puVar15 = (uint8_t *)CONCAT22(Font02.seg,Font02.ofs);
      pcVar13 = ovr_stsprintf(local_f6,"Loyal to %s",
                              (char *)*(undefined2 *)
                                       ((uint)*(byte *)((int)*(undefined4 *)(agnt_o + 0x17) + 0x1a)
                                       * 4));
      pcVar5 = (char *)ovr_OVC45_77eb_226e(local_7e);
      ovr_blitLabel((char *)CONCAT22((int)((ulong)pcVar13 >> 0x10),pcVar5),puVar15,iVar16,uVar17);
    }
    else {
      uVar17 = 0xe0;
      iVar16 = 222;
      puVar15 = (uint8_t *)CONCAT22(Font02.seg,Font02.ofs);
      pcVar13 = ovr_stsprintf(local_f6,"L. to %s",
                              (char *)*(undefined2 *)
                                       ((uint)*(byte *)((int)*(undefined4 *)(agnt_o + 0x17) + 0x1a)
                                       * 4));
      pcVar5 = (char *)ovr_OVC45_77eb_226e(local_7e);
      ovr_blitLabel((char *)CONCAT22((int)((ulong)pcVar13 >> 0x10),pcVar5),puVar15,iVar16,uVar17);
    }
  }
  TextBlitY = 0x25;
  TextBlitX = 0x87;
  if (*(char *)((int)*(undefined4 *)(agnt_o + 0x1d) + 0x46) != -1) {
    cVar4 = stats_6386_013d(agnt);
    if (cVar4 == '\0') {
      uVar17 = 0xe0;
      iVar16 = 222;
      puVar15 = (uint8_t *)CONCAT22(Font02.seg,Font02.ofs);
      uVar2 = stats_6386_0088(agnt);
      uVar11 = (undefined2)((ulong)pcVar13 >> 0x10);
      uVar12 = ovr_manage_4d05_023a(uVar2);
      bVar3 = stats_6386_0088(uVar10,uVar14,uVar12,uVar11);
      pcVar13 = ovr_stsprintf(local_7e,"%d%s level, ",(char *)(uint)bVar3);
      ovr_blitLabel(pcVar13,puVar15,iVar16,uVar17);
    }
    else {
      uVar17 = 0xe0;
      iVar16 = 222;
      puVar15 = (uint8_t *)CONCAT22(Font02.seg,Font02.ofs);
      cVar4 = stats_6386_0000(agnt);
      uVar12 = (undefined2)((ulong)pcVar13 >> 0x10);
      uVar2 = stats_6386_0088(uVar10,agnt_s,(int)cVar4);
      uVar2 = ovr_manage_4d05_023a(uVar2);
      bVar3 = stats_6386_0088(uVar10,uVar14,uVar2,uVar12);
      pcVar13 = ovr_stsprintf(local_7e,"%d%s lv rn %c, ",(char *)(uint)bVar3);
      ovr_blitLabel(pcVar13,puVar15,iVar16,uVar17);
    }
  }
  if ((*(char *)((int)*(undefined4 *)(agnt_o + 0x1d) + 0x46) == -1) ||
     (*(char *)((int)*(undefined4 *)(agnt_o + 0x17) + 0x1a) == -1)) {
    uVar7 = (uint)*(byte *)((int)*(undefined4 *)(agnt_o + 0x1d) + 0x45);
    ovr_blitLabel((char *)CONCAT22(*(undefined2 *)((int)&GAlignmentsNames[0].seg + uVar7 * 4),
                                   (char *)((far_t *)GAlignmentsNames + uVar7)->ofs),
                  (uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
  }
  else {
    uVar1 = *(undefined4 *)((uint)*(byte *)((int)*(undefined4 *)(agnt_o + 0x17) + 0x1a) << 2);
    uVar7 = (uint)*(byte *)((int)uVar1 + 0x33);
    ovr_blitLabel((char *)CONCAT22(*(undefined2 *)((int)&GAlignmentsNames[0].seg + uVar7 * 4),
                                   (char *)((far_t *)GAlignmentsNames + uVar7)->ofs),
                  (uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
  }
  TextBlitY = 0x2f;
  TextBlitX = 0x87;
  if ((*(char *)((int)*(undefined4 *)(agnt_o + 0x1d) + 0x46) != -1) &&
     (*(char *)*(undefined4 *)(agnt_o + 0x1d) == '\0')) {
    ovr_blitLabel("Experience points",(uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
    TextBlitY = 0x36;
    TextBlitX = 0x87;
    piVar8 = (int *)((uint)*(byte *)((int)*(undefined4 *)(agnt_o + 0x1d) + 0x46) * 0x94 +
                    (uint)*(byte *)((int)*(undefined4 *)(agnt_o + 0x17) + 0xf) * 4);
    if (*piVar8 == 0 && piVar8[1] == 0) {
      uVar17 = 0xe0;
      iVar16 = 222;
      puVar15 = (uint8_t *)CONCAT22(Font02.seg,Font02.ofs);
      uVar12 = (undefined2)((ulong)*(undefined4 *)(agnt_o + 0x17) >> 0x10);
      iVar9 = (int)*(undefined4 *)(agnt_o + 0x17);
      pcVar5 = ovr_litoa10(local_f6,CONCAT22(*(undefined2 *)(iVar9 + 0x12),
                                             *(undefined2 *)(iVar9 + 0x10)));
      pcVar13 = ovr_stsprintf(local_7e,"%s",pcVar5);
      ovr_blitLabel(pcVar13,puVar15,iVar16,uVar17);
    }
    else {
      uVar17 = 0xe0;
      iVar16 = 222;
      puVar15 = (uint8_t *)CONCAT22(Font02.seg,Font02.ofs);
      stats_6386_065c((char)buf);
      pcVar5 = (char *)stats_6386_065c(local_f6);
      pcVar13 = ovr_stsprintf(local_7e,"%s/%s",pcVar5);
      ovr_blitLabel(pcVar13,puVar15,iVar16,uVar17);
    }
  }
  if (*(char *)*(undefined4 *)(agnt_o + 0x1d) != '\0') {
    uVar17 = 0xe0;
    iVar16 = 222;
    puVar15 = (uint8_t *)CONCAT22(Font02.seg,Font02.ofs);
    pcVar5 = (char *)ovr_OVC41_6a8f_29ea(*(undefined2 *)(agnt_o + 0x17),
                                         *(undefined2 *)(agnt_o + 0x19));
    pcVar13 = ovr_stsprintf(local_7e,"XP value %d",pcVar5);
    ovr_blitLabel(pcVar13,puVar15,iVar16,uVar17);
  }
  TextBlitY = 0x40;
  TextBlitX = 0x87;
  uVar17 = 0xe0;
  iVar16 = 222;
  puVar15 = (uint8_t *)CONCAT22(Font02.seg,Font02.ofs);
  pcVar13 = ovr_stsprintf(local_7e,"Hit Points %d/%d",(char *)(uint)*(byte *)(agnt_o + 0x21));
  ovr_blitLabel(pcVar13,puVar15,iVar16,uVar17);
  TextBlitY = 0x4a;
  TextBlitX = 0x87;
  iVar9 = (uint)*(byte *)((int)*(undefined4 *)(agnt_o + 0x1d) + 1) * 0x95;
  if (*(int *)((int)&AgntGs[0].wpn_name + iVar9) == 0 &&
      *(int *)((int)&AgntGs[0].wpn_name + 2 + iVar9) == 0) {
    cStack_3 = 0;
  }
  else {
    cStack_3 = ovr_agnt_3b1d_0c9f(agnt);
    if ((bool)cStack_3 == false) {
      uVar17 = 0xe0;
      iVar16 = 222;
      puVar15 = (uint8_t *)CONCAT22(Font02.seg,Font02.ofs);
      pcVar13 = agntGetWeaponName((char *)CONCAT22(unaff_SS,buf),
                                  *(uint8_t *)((int)*(undefined4 *)(agnt_o + 0x1d) + 1),false,
                                  field_index,agnt);
      ovr_blitLabel(pcVar13,puVar15,iVar16,uVar17);
    }
    else if (cStack_3 < '\0') {
      uVar17 = 0xe0;
      iVar16 = 222;
      puVar15 = (uint8_t *)CONCAT22(Font02.seg,Font02.ofs);
      pcVar13 = agntGetWeaponName((char *)CONCAT22(unaff_SS,buf),
                                  *(uint8_t *)((int)*(undefined4 *)(agnt_o + 0x1d) + 1),
                                  (bool)cStack_3,field_index,agnt);
      pcVar13 = ovr_stsprintf(local_7e,"damaged %s",(char *)pcVar13);
      ovr_blitLabel(pcVar13,puVar15,iVar16,uVar17);
    }
    else {
      uVar17 = 0xe0;
      iVar16 = 222;
      puVar15 = (uint8_t *)CONCAT22(Font02.seg,Font02.ofs);
      agntGetWeaponName((char *)CONCAT22(unaff_SS,buf),
                        *(uint8_t *)((int)*(undefined4 *)(agnt_o + 0x1d) + 1),(bool)cStack_3,
                        field_index,agnt);
      pcVar13 = ovr_stsprintf(local_7e,"+%d %s",(char *)(int)cStack_3);
      ovr_blitLabel(pcVar13,puVar15,iVar16,uVar17);
    }
  }
  TextBlitY = 0x54;
  TextBlitX = 0x87;
  if (*(char *)*(undefined4 *)(agnt_o + 0x1d) == '\0') {
    cStack_3 = ovr_agnt_3b1d_0cef(agnt);
  }
  else {
    cStack_3 = 0;
  }
  uVar17 = 0xe0;
  iVar16 = 222;
  puVar15 = (uint8_t *)CONCAT22(Font02.seg,Font02.ofs);
  cVar4 = stats_6386_05d3(*(undefined2 *)(agnt_o + 0x17),*(undefined2 *)(agnt_o + 0x19));
  pcVar13 = ovr_stsprintf(local_7e,"Armor class %d",(char *)(int)cVar4);
  uVar12 = (undefined2)((ulong)pcVar13 >> 0x10);
  ovr_blitLabel(pcVar13,puVar15,iVar16,uVar17);
  if (*(char *)*(undefined4 *)(agnt_o + 0x1d) == '\0') {
    TextBlitY = 0x5e;
    TextBlitX = 0x87;
    uVar17 = 0xe0;
    iVar16 = 222;
    puVar15 = (uint8_t *)CONCAT22(Font02.seg,Font02.ofs);
    pcVar5 = (char *)stats_6386_0411((char)buf);
    ovr_blitLabel((char *)CONCAT22(uVar12,pcVar5),puVar15,iVar16,uVar17);
  }
  else {
    cStack_3 = 0;
  }
  if ((*(uint *)((int)*(undefined4 *)(agnt_o + 0x17) + 0x14) & 2) != 0) {
    TextBlitY = 0x68;
    TextBlitX = 0x87;
    ovr_blitLabel("Mirror",(uint8_t *)CONCAT22(Font02.seg,Font02.ofs),222,0xe0);
  }
  if (GameRunning != false) {
    ovr_setSeasonPalette(cmap.ofs,cmap.seg);
  }
  return;
}



/* 6386:12b7 */

char * __cdecl16far stats_6386_12b7(byte param_1,char *param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  undefined2 uVar4;
  char *pcVar5;
  
  uVar1 = *(undefined4 *)((uint)param_1 * 0x34 + 0x17);
  if ((*(byte *)((int)uVar1 + 0x33) & 1) == 0) {
    uVar1 = *(undefined4 *)((uint)param_1 * 0x34 + 0x1d);
    uVar4 = (undefined2)((ulong)uVar1 >> 0x10);
    iVar3 = (int)uVar1;
    pcVar2 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)(iVar3 + 0x24),*(undefined2 *)(iVar3 + 0x26)
                                        );
    pcVar5 = ovr_stsprintf(param_2,"  %s is not readied.",pcVar2);
    pcVar2 = (char *)pcVar5;
  }
  else {
    uVar1 = *(undefined4 *)((uint)param_1 * 0x34 + 0x1d);
    uVar4 = (undefined2)((ulong)uVar1 >> 0x10);
    iVar3 = (int)uVar1;
    pcVar2 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)(iVar3 + 0x24),*(undefined2 *)(iVar3 + 0x26)
                                        );
    pcVar5 = ovr_stsprintf(param_2,"  %s is ready.",pcVar2);
    pcVar2 = (char *)pcVar5;
  }
  return pcVar2;
}



/* 6386:1353 */

void __cdecl16far stats_6386_1353(char param_1)

{
  byte *pbVar1;
  uint uVar2;
  
  for (uVar2 = 0; uVar2 < EntityCount; uVar2 = uVar2 + 1) {
    if (*(char *)(Entities.ofs + uVar2 * 0x37 + 0x1a) == param_1) {
      pbVar1 = (byte *)(Entities.ofs + uVar2 * 0x37 + 0x33);
      *pbVar1 = *pbVar1 & 0xfb;
    }
  }
  return;
}



/* 6386:13a1 */

void __cdecl16far stats_6386_13a1(byte agnt_id)

{
  byte *pbVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  char local_82 [126];
  undefined2 uStack_4;
  
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
    stats_6386_1353();
    uVar2 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x17);
    pbVar1 = (byte *)((int)uVar2 + 0x33);
    *pbVar1 = *pbVar1 | 4;
    uStack_4 = *(undefined2 *)((uint)agnt_id * 0x34 + 0x1b);
    ovr_attact_3f0b_0ade(uStack_4,0);
  }
  uVar2 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x17);
  uVar3 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x17);
  *(byte *)((int)uVar3 + 0x33) = *(byte *)((int)uVar2 + 0x33) & 0xfd;
  drawAgntStats(CONCAT22(0x1726,(uint)agnt_id * 0x34),(far_t)0x0);
  uVar2 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x17);
  if ((*(byte *)((int)uVar2 + 0x33) & 1) == 0) {
    uVar2 = *(undefined4 *)((uint)agnt_id * 0x34 + 0x1d);
    pcVar4 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)((int)uVar2 + 0x24));
    pcVar5 = ovr_stsprintf(local_82,"%s is no longer ready.",pcVar4);
    drawString((char *)pcVar5,(int)((ulong)pcVar5 >> 0x10));
  }
  else {
    pcVar4 = (char *)stats_6386_12b7();
    pcVar5 = ovr_stsprintf(local_82,"Ready characters are the first to come when attracted.%s",
                           pcVar4);
    drawString((char *)pcVar5,(int)((ulong)pcVar5 >> 0x10));
  }
  return;
}



/* 6386:1572 */

uint __cdecl16far stats_6386_1572(int param_1)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  uint16_t uVar4;
  uint16_t uVar5;
  
  if ((*(byte *)(Entities.ofs + param_1 * 0x37 + 0x33) & 2) == 0) {
    uVar2 = 0;
  }
  else {
    uVar1 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + param_1 * 0x37));
    uVar2 = ovr_OVC23_55fe_3450(GfxRndSeed);
    if (uVar1 == uVar2) {
      uVar2 = *(uint *)(Entities.ofs + param_1 * 0x37 + 2);
      if (uVar2 == GfxRndSeed2) {
        uVar1 = ovr_OVC23_55fe_3450(*(undefined2 *)(Entities.ofs + param_1 * 0x37 + 4));
        uVar2 = ovr_OVC23_55fe_3450(GfxRndSeed);
        if (uVar1 == uVar2) {
          uVar5 = Entities.seg;
          uVar4 = Entities.ofs;
          uVar2 = *(uint *)(uVar4 + param_1 * 0x37 + 6);
          if (uVar2 == GfxRndSeed2) {
            if (*(int *)(uVar4 + param_1 * 0x37 + 8) == 0) {
              bVar3 = (byte)((uint)(param_1 * 0x37) >> 8);
              if (*(int *)(uVar4 + param_1 * 0x37 + 10) == 0) {
                uVar2 = CONCAT11(bVar3,1);
              }
              else {
                uVar2 = (uint)bVar3 << 8;
              }
            }
            else {
              uVar2 = param_1 * 0x37 & 0xff00;
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

void __cdecl16far stats_6386_16a2(byte param_1)

{
  byte *pbVar1;
  int iVar2;
  undefined2 uVar3;
  char *arg1;
  char *pcVar4;
  char local_d4 [200];
  int iStack_c;
  undefined2 uStack_a;
  
  iVar2 = *(int *)((uint)param_1 * 0x34 + 0x1b);
  uStack_a = *(undefined2 *)((uint)param_1 * 0x34 + 0x1f);
  iStack_c = *(int *)((uint)param_1 * 0x34 + 0x1d);
  uVar3 = ovr_OVC23_55fe_2e2b();
  *(undefined2 *)(Entities.ofs + iVar2 * 0x37) = uVar3;
  *(undefined2 *)(Entities.ofs + iVar2 * 0x37 + 2) = GfxRndSeed2;
  *(undefined2 *)(Entities.ofs + iVar2 * 0x37 + 4) = *(undefined2 *)(Entities.ofs + iVar2 * 0x37);
  *(undefined2 *)(Entities.ofs + iVar2 * 0x37 + 6) = GfxRndSeed2;
  pbVar1 = (byte *)(Entities.ofs + iVar2 * 0x37 + 0x33);
  *pbVar1 = *pbVar1 | 2;
  pbVar1 = (byte *)(Entities.ofs + iVar2 * 0x37 + 0x33);
  *pbVar1 = *pbVar1 & 0xfa;
  ovr_attact_3f0b_0ade();
  uVar3 = ovr_OVC23_55fe_3450(GfxRndSeed);
  arg1 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)(iStack_c + 0x24),
                                     *(undefined2 *)(iStack_c + 0x26),uVar3);
  pcVar4 = ovr_stsprintf(local_d4,
                         "%s is now based at (%d, %d). This unit will remain home when attracted.",
                         arg1);
  drawString((char *)pcVar4);
  drawAgntStats(CONCAT22(0x1726,(uint)param_1 * 0x34),(far_t)0x0);
  return;
}



/* 6386:1837 */

void __cdecl16far stats_6386_1837(byte param_1)

{
  byte *pbVar1;
  int iVar2;
  undefined2 uVar3;
  char *arg1;
  char *pcVar4;
  char local_d4 [200];
  int iStack_c;
  undefined2 uStack_a;
  undefined1 local_8 [6];
  
  iVar2 = *(int *)((uint)param_1 * 0x34 + 0x1b);
  uStack_a = *(undefined2 *)((uint)param_1 * 0x34 + 0x1f);
  iStack_c = *(int *)((uint)param_1 * 0x34 + 0x1d);
  uVar3 = ovr_OVC23_55fe_2e2b();
  *(undefined2 *)(Entities.ofs + iVar2 * 0x37) = uVar3;
  *(undefined2 *)(Entities.ofs + iVar2 * 0x37 + 2) = GfxRndSeed2;
  *(undefined2 *)(Entities.ofs + iVar2 * 0x37 + 4) = *(undefined2 *)(Entities.ofs + iVar2 * 0x37);
  *(undefined2 *)(Entities.ofs + iVar2 * 0x37 + 6) = GfxRndSeed2;
  pbVar1 = (byte *)(Entities.ofs + iVar2 * 0x37 + 0x33);
  *pbVar1 = *pbVar1 & 0xfd;
  ovr_attact_3f0b_0ade(iVar2,0,0,local_8);
  arg1 = (char *)ovr_OVC15_4207_1c16(*(undefined2 *)(iStack_c + 0x24));
  pcVar4 = ovr_stsprintf(local_d4,"%s can now be called away from home.",arg1);
  drawString((char *)pcVar4);
  drawAgntStats(CONCAT22(0x1726,(uint)param_1 * 0x34),(far_t)0x0);
  return;
}



/* 6386:1997 */

undefined1 __cdecl16far stats_6386_1997(byte param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 uStack_3;
  
  uStack_3 = 0xff;
  uVar2 = 0x7fff;
  for (iVar1 = 0; iVar1 < (int)(uint)AgntCount; iVar1 = iVar1 + 1) {
    if ((*(uint *)((uint)param_1 * 0x34 + 0x1b) < *(uint *)(iVar1 * 0x34 + 0x1b)) &&
       (*(uint *)(iVar1 * 0x34 + 0x1b) < uVar2)) {
      uVar2 = *(uint *)(iVar1 * 0x34 + 0x1b);
      uStack_3 = (undefined1)iVar1;
    }
  }
  return uStack_3;
}



/* 6386:1a19 */

undefined1 __cdecl16far stats_6386_1a19(byte param_1)

{
  int iVar1;
  int iVar2;
  undefined1 uStack_3;
  
  uStack_3 = 0xff;
  iVar2 = -1;
  for (iVar1 = 0; iVar1 < (int)(uint)AgntCount; iVar1 = iVar1 + 1) {
    if ((*(uint *)(iVar1 * 0x34 + 0x1b) < *(uint *)((uint)param_1 * 0x34 + 0x1b)) &&
       (iVar2 < *(int *)(iVar1 * 0x34 + 0x1b))) {
      iVar2 = *(int *)(iVar1 * 0x34 + 0x1b);
      uStack_3 = (undefined1)iVar1;
    }
  }
  return uStack_3;
}



/* 6386:1a9b */

void __cdecl16far stats_6386_1a9b(byte param_1)

{
  ovr_OVC15_4207_1aae(*(undefined2 *)((uint)param_1 * 0x34 + 0x1b));
  return;
}



/* 6386:1abe */

void __cdecl16far stats_6386_1abe(int param_1)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  
  iVar2 = *(int *)(param_1 * 0x34 + 0x1b);
  ovr_manage_4d05_0081();
  DAT_2410_26a8 = 2;
  drawAgntStats(CONCAT22(0x1726,param_1 * 0x34),(far_t)0x0);
  drawString((char *)"short sword" + 0xb);
  bVar1 = *(byte *)(Entities.ofs + iVar2 * 0x37 + 0xd);
  if (*(char *)((int)(char **)GMenuStrings + (uint)bVar1 * 0x95 + 0x1f) == '\0') {
    if ((*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)bVar1 * 0x95) == '\0') ||
       (*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)bVar1 * 0x95) == '\x04')) {
      DAT_2410_07a6 = 0x43;
    }
    else if (*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)bVar1 * 0x95) == '\x02') {
      DAT_2410_07a6 = 0x42;
    }
    else if ((*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)bVar1 * 0x95) == '\x05') ||
            (*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)bVar1 * 0x95) == '\x01')) {
      DAT_2410_07a6 = 0x27;
    }
    else if (*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)bVar1 * 0x95) == '\x06') {
      DAT_2410_07a6 = 0x28;
    }
    else if (*(char *)((int)&far_t_ARRAY_2410_26f7[9].ofs + 1 + (uint)bVar1 * 0x95) == '\x03') {
      DAT_2410_07a6 = 0x20;
    }
    else {
      DAT_2410_07a6 = 0xc;
    }
  }
  else if ((*(uint *)((int)&far_t_ARRAY_2410_26f7[7].seg + 1 + (uint)bVar1 * 0x95) & 8) == 0) {
    DAT_2410_07a6 = 0x29;
  }
  else {
    DAT_2410_07a6 = 0x59;
  }
  cVar3 = ovr_audio_3a5b_034e();
  if (cVar3 == '\0') {
    ovr_play_sfx(CONCAT11(0x24,DAT_2410_07a6),0);
  }
  return;
}



/* 6386:1c9f */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0006f700) overlaps instruction at (ram,0x0006f6ff)
    */

byte __cdecl16far
stats_6386_1c9f(byte param_1,byte param_2,int16_t param_3,int16_t param_4,brect_t *param_5,
               undefined2 param_6)

{
  undefined4 uVar1;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  char cVar2;
  byte bVar3;
  undefined2 uVar4;
  byte *pbVar5;
  uint16_t *puVar6;
  int *piVar7;
  undefined2 *puVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined2 unaff_DI;
  undefined2 uVar12;
  undefined2 unaff_SS;
  ulong uVar13;
  far_t gfx_04;
  undefined1 uVar14;
  undefined1 uVar15;
  byte local_11 [11];
  char cStack_6;
  char cStack_5;
  byte bStack_4;
  byte bStack_3;
  
  if (AgntCount <= param_1) {
    return AgntCount;
  }
  gfx.seg = FontHandle.seg;
  gfx.ofs = FontHandle.ofs;
  ovr_blitLoadRleGfx(gfx,(far_t)0xa000c31d);
  DAT_2410_4926 = 0;
  ovr_attact_3f0b_0685();
  ovr_draw_2e25_1662();
  ovr_stop_audio();
  DAT_2000_ca71 = GMenuItem;
  DAT_2000_ca70 = DAT_2000_ca6f;
  DAT_2410_07a6 = 0xff;
LAB_6386_1e1d:
  for (; GCharLevelsInc != '\0'; GCharLevelsInc = GCharLevelsInc + -1) {
    uVar1 = *(undefined4 *)((uint)param_1 * 0x34 + 0x1d);
    bStack_3 = *(byte *)((int)uVar1 + 0x46);
    if (bStack_3 == 0xff) {
      bStack_3 = 0;
    }
    uVar1 = *(undefined4 *)((uint)param_1 * 0x34 + 0x17);
    piVar7 = (int *)((uint)bStack_3 * 0x94 + (uint)*(byte *)((int)uVar1 + 0xf) * 4);
    if (*piVar7 != 0 || piVar7[1] != 0) {
      uVar1 = *(undefined4 *)((uint)param_1 * 0x34 + 0x17);
      puVar8 = (undefined2 *)((uint)bStack_3 * 0x94 + (uint)*(byte *)((int)uVar1 + 0xf) * 4);
      uVar4 = *puVar8;
      uVar1 = *(undefined4 *)((uint)param_1 * 0x34 + 0x17);
      uVar12 = (undefined2)((ulong)uVar1 >> 0x10);
      iVar9 = (int)uVar1;
      *(undefined2 *)(iVar9 + 0x12) = puVar8[1];
      *(undefined2 *)(iVar9 + 0x10) = uVar4;
      ovr_OVC41_6a8f_002e(*(undefined2 *)((uint)param_1 * 0x34 + 0x17),
                          (char)*(undefined2 *)((uint)param_1 * 0x34 + 0x19));
    }
  }
  iVar9 = *(int *)((uint)param_1 * 0x34 + 0x1b);
  stats_6386_1abe(param_1);
  if (*(int *)(Entities.ofs + iVar9 * 0x37 + 6) == GfxRndSeed2) {
    uVar4 = ovr_OVC23_55fe_3450((char)*(undefined2 *)(Entities.ofs + iVar9 * 0x37 + 4));
    uVar14 = (undefined1)uVar4;
    uVar15 = (undefined1)((uint)uVar4 >> 8);
    iVar9 = ovr_OVC23_55fe_3450(GfxRndSeed);
    if (CONCAT11(uVar15,uVar14) == iVar9) {
      uVar1 = *(undefined4 *)((uint)param_1 * 0x34 + 0x17);
      ovr_OVC39_690b_0180(*(undefined1 *)((int)uVar1 + 0x1a));
    }
  }
LAB_6386_1ecd:
  stats_6386_1a19(param_1);
  local_11[1] = 4;
  stats_6386_1997(param_1);
  local_11[2] = 5;
  local_11[3] = 7;
  local_11[4] = 9;
  local_11[5] = 6;
  pbVar5 = (byte *)&AgntAnms[0x75].field_0x18;
  if (*(char *)*(undefined4 *)((uint)param_1 * 0x34 + 0x1d) == '\0') {
    DAT_2410_5ce4 = 1;
  }
  bStack_4 = ovr_uiInputText();
  DAT_2410_5ce4 = 0;
  if ((bStack_4 != 0) && (bStack_4 < 10)) {
    pbVar5 = local_11;
    bStack_4 = pbVar5[bStack_4];
  }
  cStack_5 = '\0';
  cStack_6 = '\0';
  uVar11 = (uint)bStack_4;
  if (uVar11 == 6) {
    cStack_6 = '\x01';
    cStack_5 = '\x01';
  }
  else if (uVar11 < 7) {
    uVar10 = 5;
    switch(uVar11) {
    case 0:
      DAT_2410_5ce4 = 0;
      uVar11 = 5;
      Agnts[5].field0_0x0 = 0x2b;
      Agnts[5].field1_0x2 = 2;
      do {
        bStack_3 = 1;
        while( true ) {
          uVar11 = uVar11 + 1;
          if ((int)(uint)AgntCount <= (int)uVar11) {
            ovr_agnt_3b1d_1ad8();
            ovr_agnt_3b1d_1ad8();
            ovr_agnt_3b1d_1ad8();
            bVar3 = ovr_agnt_3b1d_1ad8();
            return bVar3;
          }
          uVar1 = *(undefined4 *)(uVar11 * 0x34 + 0x1d);
          uVar10 = uVar11;
          if (*(char *)((int)uVar1 + 1) == '\x02') break;
          uVar1 = *(undefined4 *)(uVar11 * 0x34 + 0x1d);
          if (*(char *)((int)uVar1 + 1) == '\x01') {
            *(undefined2 *)(uVar11 * 0x34) = 0x3d;
            *(undefined2 *)(uVar11 * 0x34 + 2) = 0x12;
          }
          else {
            uVar1 = *(undefined4 *)(uVar11 * 0x34 + 0x1d);
            if (*(char *)((int)uVar1 + 1) == '\v') {
              *(undefined2 *)(uVar11 * 0x34) = 0x56;
              *(undefined2 *)(uVar11 * 0x34 + 2) = 0x14;
            }
          }
        }
switchD_6000_58bf_caseD_5:
        *(undefined2 *)(uVar11 * 0x34) = 0x6e;
        *(undefined2 *)(uVar10 * 0x34 + 2) = 0xb;
        uVar11 = uVar10;
      } while( true );
    case 1:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 2:
      uVar4 = (undefined2)
              ((ulong)*(undefined4 *)((undefined *)&GfxFramePtrs + (uint)param_2 * 4) >> 0x10);
      puVar6 = (uint16_t *)
               ((int)*(undefined4 *)((undefined *)&GfxFramePtrs + (uint)param_2 * 4) +
               (uint)bStack_3 * 4);
      gfx_04.seg = puVar6[1];
      gfx_04.ofs = *puVar6;
      ovr_blitGfxRect(gfx_04,param_3,param_4,(brect_t *)CONCAT22(param_6,param_5),0x10,
                      SUB21(unaff_DI,0));
      AnimSeqPtr[0].seg._0_1_ = bStack_3 + 1;
      GAnimPlaying = 1;
      return bStack_3 + 1;
    case 3:
      uVar14 = 0x10;
      bStack_3 = '\0';
      do {
        cVar2 = ovr_draw_2e25_1d7c(uVar14);
      } while (cVar2 != '\0');
      while( true ) {
        if ((*(uint16_t *)(BDA_DailyTimeCounter.ofs + 2) != InputEventTime.hi) ||
           (*(uint16_t *)BDA_DailyTimeCounter != InputEventTime.lo)) {
          InputEventTime.hi = *(uint16_t *)(BDA_DailyTimeCounter.ofs + 2);
          InputEventTime.lo = *(uint16_t *)BDA_DailyTimeCounter;
          ovr_draw_2e25_0938();
        }
        bStack_4 = ovr_draw_2e25_1d7c(uVar14);
        if (bStack_4 != 0) break;
        uVar13 = ovr_attact_3f0b_082f(CONCAT22(TextBlitCycle._2_2_,(undefined2)TextBlitCycle));
        if (((int)(uVar13 >> 0x10) != 0) || ((uint)param_1 <= (uint)uVar13)) break;
      }
      if (bStack_3 != '\0') {
        ovr_miceRestoreArea(BlitRects + 1);
      }
      return bStack_4;
    case 4:
      in(pbVar5);
      ovr_draw_2e25_1662();
      ovr_stop_audio();
      DAT_2000_ca71 = GMenuItem;
      DAT_2000_ca70 = DAT_2000_ca6f;
      gfx_00.seg = DAT_2000_cabb;
      gfx_00.ofs = DAT_2000_cab9;
      ovr_blitLoadRleGfx(gfx_00,(far_t)0xa000e249);
      gfx_01.seg = DAT_2000_cabf;
      gfx_01.ofs = DAT_2000_cabd;
      ovr_blitLoadRleGfx(gfx_01,(far_t)0xa000e249);
      ovr_uiMainMenuLoop();
      gfx_02.seg = DAT_2000_cabb;
      gfx_02.ofs = DAT_2000_cab9;
      ovr_blitLoadRleGfx(gfx_02,(far_t)0xa000e249);
      gfx_03.seg = DAT_2000_cac3;
      gfx_03.ofs = DAT_2000_cac1;
      ovr_blitLoadRleGfx(gfx_03,(far_t)0xa000e249);
      bVar3 = OVC41_6a8f_18c6();
      return bVar3;
    case 5:
      goto switchD_6000_58bf_caseD_5;
    }
  }
  else if (uVar11 == 0xfc) {
    uVar1 = *(undefined4 *)((uint)param_1 * 0x34 + 0x17);
    if ((*(byte *)((int)uVar1 + 0x33) & 1) == 0) {
      stats_6386_13a1(param_1);
    }
  }
  else if (uVar11 < 0xfd) {
    if (uVar11 == 7) {
      uVar1 = *(undefined4 *)((uint)param_1 * 0x34 + 0x17);
      if (*(char *)((int)uVar1 + 0x1a) != -1) {
        ovr_stop_audio();
        DAT_2410_07a6 = 0xff;
        uVar1 = *(undefined4 *)((uint)param_1 * 0x34 + 0x17);
        ovr_manage_4d05_1bee(*(undefined1 *)((int)uVar1 + 0x1a));
        if (DAT_2410_4926 == 0) {
          iVar9 = *(int *)((uint)param_1 * 0x34 + 0x1b);
          stats_6386_1abe(param_1);
          if (*(int *)(Entities.ofs + iVar9 * 0x37 + 6) == GfxRndSeed2) {
            uVar4 = ovr_OVC23_55fe_3450((char)*(undefined2 *)(Entities.ofs + iVar9 * 0x37 + 4));
            uVar14 = (undefined1)uVar4;
            uVar15 = (undefined1)((uint)uVar4 >> 8);
            iVar9 = ovr_OVC23_55fe_3450(GfxRndSeed);
            if (CONCAT11(uVar15,uVar14) == iVar9) {
              uVar1 = *(undefined4 *)((uint)param_1 * 0x34 + 0x17);
              ovr_OVC39_690b_0180(*(undefined1 *)((int)uVar1 + 0x1a));
            }
          }
        }
        else {
          cStack_5 = '\x01';
        }
      }
    }
    else {
      if (uVar11 == 8) goto LAB_6386_20c5;
      if (uVar11 == 9) {
        ovr_OVC50_8adb_00f1();
        cStack_6 = '\x01';
      }
    }
  }
  else if (uVar11 == 0xfd) {
LAB_6386_20c5:
    cVar2 = stats_6386_1572((char)*(undefined2 *)((uint)param_1 * 0x34 + 0x1b));
    if (cVar2 == '\0') {
      stats_6386_16a2(param_1);
    }
  }
  else if (uVar11 == 0xfe) {
    uVar1 = *(undefined4 *)((uint)param_1 * 0x34 + 0x17);
    if ((*(byte *)((int)uVar1 + 0x33) & 1) != 0) {
      stats_6386_13a1(param_1);
    }
    cVar2 = stats_6386_1572((char)*(undefined2 *)((uint)param_1 * 0x34 + 0x1b));
    if (cVar2 != '\0') {
      stats_6386_1837(param_1);
    }
  }
  if ((cStack_5 != '\0') || (cStack_6 != '\0')) goto LAB_6386_22c8;
  goto LAB_6386_1ecd;
LAB_6386_22c8:
  if (cStack_5 != '\0') {
    if (DAT_2410_4926 != 0) {
      return DAT_2410_4926;
    }
    stats_6386_232d();
    bVar3 = ovr_OVC41_6a8f_18c6();
    return bVar3;
  }
  goto LAB_6386_1e1d;
}



/* 6386:22fd */

bool __cdecl16far stats_6386_22fd(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  
  iVar1 = video_13aa_005b(param_1,param_2);
  if (iVar1 != -1) {
    stats_6386_1c9f(iVar1);
  }
  return iVar1 != -1;
}



/* 6386:232d */

void __cdecl16far stats_6386_232d(void)

{
  far_t gfx;
  far_t handle;
  int iVar1;
  undefined2 unaff_SS;
  far_t fVar2;
  undefined1 uVar3;
  undefined1 local_314 [768];
  stg_tmp_t *psStack_14;
  brect_t local_10;
  far_t fStack_6;
  
  MiceNeedsUpdate = 1;
  fStack_6 = (far_t)ovr_stshAlloc(0xfa0f);
  fVar2 = ovr_alignToSeg(fStack_6);
  TextBlitDstSeg = fVar2.seg;
  local_10.y = 7;
  local_10.h = 194;
  local_10.x = 8;
  local_10.w = 226;
  local_10.seg = TextBlitDstSeg;
  ovr_driver_2d63_05e5(8,7,0xe2,0xc2,0,(char)fVar2.seg);
  uVar3 = (undefined1)((uint)unaff_SS >> 8);
  gfx.seg = DAT_2000_cacf;
  gfx.ofs = DAT_2000_cacd;
  ovr_blitGfx10(gfx,0,0,(brect_t *)CONCAT13(uVar3,CONCAT12((char)unaff_SS,&local_10)),0);
  fVar2.seg = DAT_2000_d1a5;
  fVar2.ofs = DAT_2000_d1a3;
  ovr_blitGfxRect(fVar2,0,0,(brect_t *)CONCAT22(unaff_SS,&local_10),0x10,false);
  handle.seg._0_1_ = (char)Lbm_nwpanel1.seg;
  handle.ofs = Lbm_nwpanel1.ofs;
  handle.seg._1_1_ = (char)(Lbm_nwpanel1.seg >> 8);
  psStack_14 = ovr_stshLoadGfx(handle);
  ovr_calcSeasonPalette(psStack_14,(char)local_314);
  ovr_driver_2d63_05e5(local_10.x,local_10.y,local_10.w,local_10.h,0,0);
  ovr_vgaSetPalette8bit((char)local_314);
  ovr_blitRect((brect_t *)CONCAT13(uVar3,CONCAT12((char)unaff_SS,&local_10)));
  TextBlitDstSeg = 0xa000;
  ovr_OVC28_6018_0251();
  for (iVar1 = 0; iVar1 < 5; iVar1 = iVar1 + 1) {
    ovr_draw_2e25_0efd((char)iVar1);
    ovr_draw_2e25_0000((char)iVar1,0);
  }
  DAT_2000_d116 = 0xff;
  ovr_attact_3f0b_2a09();
  ovr_stshFree(fStack_6);
  ovr_stop_audio();
  DAT_2410_07a6 = 0xff;
  DAT_2410_26a8 = 0;
  return;
}



/* 6386:24c2 */

void __cdecl16far drawString(char *param_1,undefined2 param_2)

{
  uint uVar1;
  size_t sVar2;
  undefined2 unaff_SS;
  far_t gfx;
  brect_t local_c;
  
  memcpy((uint8_t *)&local_c,(uint8_t *)(brect_t *)(BlitRects + 1),10);
  if (DAT_2410_26a8 == '\x01') {
    local_c.y = 0x9c;
    local_c.h = 190;
  }
  else {
    local_c.y = 0x75;
    if (GameRunning == false) {
      local_c.h = 178;
    }
    else {
      local_c.h = 150;
    }
  }
  local_c.x = 19;
  local_c.w = 215;
  TextBlitFlag = 1;
  TextBlitDstSeg = 0xa000;
  gfx.seg = DAT_2000_d39e;
  gfx.ofs = DAT_2000_d39c;
  ovr_blitGfxRect(gfx,0,0,(brect_t *)CONCAT22(unaff_SS,&local_c),0x10,false);
  TextBlitY = local_c.y;
  while( true ) {
    TextBlitX = 0x13;
    uVar1 = ovr_blitText((char *)CONCAT22(param_2,param_1),(byte *)Font03.ofs,0xd7,0xed);
    sVar2 = strlen(param_1);
    if (sVar2 <= uVar1) break;
    param_1 = param_1 + uVar1;
    TextBlitY = TextBlitY + 0xb;
  }
  ovr_clean_ring_buffer();
  return;
}


