/*
 * ovc09_init.c - recovered from STRONG.EXE
 * memory block: OVC09_init.c
 * range: 3381:0000 - 3381:34cf
 * functions: 31
 */
#include "recovered.h"


/* 3381:0000 */

/* [R4] calls ovr_blitGfxRect */

void __cdecl16far init_usesBlitGfxRect(void)

{
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  
  gfx_00.seg = fullScreenGfxSeg;
  gfx_00.ofs = fullScreenGfxOfs;
  ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)(0xa0000000)));
  gfx_01.seg = GMenuGfxSeg;
  gfx_01.ofs = GMenuGfxOfs;
  ovr_blitLoadRleGfx(gfx_01,far_from_u32((uint32_t)(0xa00009af)));
  gfx.seg = nwpanel2Cut1Seg;
  gfx.ofs = nwpanel2Cut1Ofs;
  ovr_blitGfxRect(gfx,0,0,(brect_t *)(BlitRects + 1),0x10,true);
  if (GameRunning == false) {
    gfx_02.seg = panel01Cut3Seg;
    gfx_02.ofs = panel01Cut3Ofs;
    ovr_blitLoadRleGfx(gfx_02,far_from_u32((uint32_t)(0xa000c51d)));
    mapViewActive = 0;
  }
  return;
}



/* 3381:009a */

char * __cdecl16far append_name_to_path(char *path,char *name)

{
  uint16_t l;
  char *in_stack_00000004;
  
  strcpy(&GStaticBuffer,(char *)CONCAT22((char *)path,in_stack_00000004));
  for (l = strlen(&GStaticBuffer); (0 < (int)l && (((undefined1 *)&randomFeatureCount)[l] != '\\'));
      l = l - 1) {
  }
  ((undefined *)&GStaticBuffer)[l] = 0;
  strcat(&GStaticBuffer,(char *)CONCAT22((char *)name,(*(uint16_t *)((uint8_t *)&(path) + 2))));
  return (char *)&GStaticBuffer;
}



/* 3381:00fe */

char * __cdecl16far path_strip_tail_slash(char *s,...)

{
  uint16_t l;
  undefined2 in_stack_00000006;
  
  l = strlen((char *)CONCAT22(in_stack_00000006,s));
  if ((3 < (int)l) && (s[l - 1] == '\\')) {
    s[l - 1] = '\0';
  }
  return s;
}



/* 3381:0132 */

char * __cdecl16far ensure_tail_slash(char *s,...)

{
  uint16_t l;
  undefined2 in_stack_00000006;
  
  l = strlen((char *)CONCAT22(in_stack_00000006,s));
  if ((l == 0) || (s[l - 1] != '\\')) {
    s[l] = '\\';
    s[l + 1] = '\0';
  }
  return s;
}



/* 3381:016c */

/* chdir doesn't change the disk, so we have to do that */

void __cdecl16far chpath(char *path,...)

{
  uint8_t c;
  char cVar1;
  int iVar2;
  undefined1 extraout_AH;
  undefined2 in_stack_00000006;
  
  iVar2 = chdir((char *)CONCAT22(in_stack_00000006,path));
  if (iVar2 == 0) {
    c = toupper((int)*path);
    if (((path[1] == ':') && ('@' < (char)c)) && ((char)c < '[')) {
      cVar1 = toupper((int)(char)c);
      setdisk(CONCAT11(extraout_AH,cVar1) + -0x41);
    }
  }
  return;
}



/* 3381:01c8 */

void __cdecl16far init_paths(void)

{
  uint16_t full_path;
  uint16_t p;
  undefined2 in_DX;
  size_t unaff_BP;
  
  getcwd((char *)MK_FP(0x2410, 0x44),unaff_BP);
  strcpy(&GWorkDir,GOriginalDir);
  ensure_tail_slash((char *)&GWorkDir,0x2410);
  strcat(&GWorkDir,"strong.sav\\");
  full_path = (uint16_t)
              append_name_to_path((char *)CONCAT22(0x5bb,GGameExe.seg),
                                  (char *)CONCAT22(unaff_BP,(char *)0x26510));
  p = (uint16_t)path_strip_tail_slash((char *)full_path,in_DX);
  chpath((char *)p,in_DX);
  return;
}



/* 3381:023c */

void __cdecl16far init_cfg_mice(void)

{
  CFG_Mice = 1;
  return;
}



/* 3381:024d */

void __cdecl16far init_cfg(void)

{
  bool bVar1;
  uint8_t uVar2;
  uint16_t cfgPath;
  uint16_t fh;
  char *path;
  int iVar3;
  uint16_t wrsz;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined2 in_DX;
  char *unaff_SS;
  char lbuf [80];
  uint8_t goterr;
  uint8_t update;
  uint16_t crlf;
  char mice;
  uint8_t c;
  
  crlf = GCrLf;
  bVar1 = false;
  cfgPath = (uint16_t)ovr_stsprintf(lbuf,(char *)CONCAT22(0x5bc,unaff_SS),(char *)MK_FP(0x2410, 0x8c6c),0x2410)
  ;
  fh = ovr_open_wait_unlock_and_disk((char *)cfgPath,in_DX);
  if ((int)fh < 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x80);
  }
  c = ovr_read_cfg(fh);
  if (c == 0x0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x80);
  }
  uVar2 = c;
  if ((((char)c < '1') || ('9' < (char)c)) && (((char)c < 'A' || ('B' < (char)c)))) {
    if (((char)c < 'a') || ('b' < (char)c)) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x80);
    }
    uVar2 = toupper((int)(char)c);
  }
  CFG_Sfx = uVar2;
  c = ovr_read_cfg(fh);
  if (c == 0x0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x80);
  }
  uVar2 = c;
  if ((((char)c < '1') || ('9' < (char)c)) && (((char)c < 'A' || ('B' < (char)c)))) {
    if (((char)c < 'a') || ('b' < (char)c)) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x80);
    }
    uVar2 = toupper((int)(char)c);
  }
  CFG_Mus = uVar2;
  c = ovr_read_cfg(fh);
  if (c == 0x0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x80);
  }
  if ((((char)c < '0') || ('9' < (char)c)) && (((char)c < 'A' || ('F' < (char)c)))) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x80);
  }
  CFG_Irq = c;
  mice = ovr_read_cfg(fh);
  if ((mice < '1') || ('2' < mice)) {
    init_cfg_mice();
    bVar1 = true;
    mice = '2';
    if (CFG_Mice != 0) {
      mice = '1';
    }
  }
  else if (mice == '1') {
    CFG_Mice = 1;
  }
  else {
    CFG_Mice = 0;
  }
  close(fh);
  if (bVar1) {
    path = ovr_stsprintf(lbuf,(char *)CONCAT22(0x5bc,unaff_SS),(char *)MK_FP(0x2410, 0x8c6c),0x2410);
    iVar3 = ovr_creat_wait_unlock_and_disk(path,in_DX);
    if (iVar3 < 0) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x83);
    }
    write(iVar3,&CFG_Sfx,1);
    write(iVar3,(uint16_t *)CONCAT22(unaff_SS,&crlf),2);
    write(iVar3,&CFG_Mus,1);
    write(iVar3,(uint16_t *)CONCAT22(unaff_SS,&crlf),2);
    iVar4 = write(iVar3,&CFG_Irq,1);
    iVar5 = write(iVar3,(uint16_t *)CONCAT22(unaff_SS,&crlf),2);
    iVar6 = write(iVar3,(char *)CONCAT22(unaff_SS,&mice),1);
    iVar7 = write(iVar3,(uint16_t *)CONCAT22(unaff_SS,&crlf),2);
    iVar3 = close(iVar3);
    if ((((iVar4 != 1 || iVar5 != 2) || iVar6 != 1) || iVar7 != 2) || (char)iVar3 != '\0') {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x80);
    }
    clrscr();
  }
  return;
}



/* 3381:0579 */

void __cdecl16far init_game(void)

{
  int iVar1;
  uint8_t unaff_BP;
  
  _OvrInitExt(0,0);
  _OvrInitEms(0,0,0);
  ovr_init_base();
  init_paths();
  init_cfg();
  clrscr();
  srand8(CONCAT22(*(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2),*(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs))
        );
  ovr_stshAlloc(0xfa0f);
  iVar1 = strcmp((char *)CONCAT22(GExeArg.seg,GExeArg.ofs),"debug");
  if (iVar1 == 0) {
    GDebug = true;
  }
  iVar1 = strcmp((char *)CONCAT22(GExeArg.seg,GExeArg.ofs),"grab");
  if (iVar1 == 0) {
    GDebug = true;
    ovr_init_assets();
  }
  else {
    ovr_init_assets();
  }
  ovr_stshInit();
  StshStrongDatHnd = ovr_stshOpen(0);
  ovr_sfxInit();
  ovr_musInit();
  ovr_gfxInitRand();
  ovr_miceInit();
  ovr_biosVideoCall(0x13,unaff_BP);
  init_grayscale_palette();
  ovr_init_ui_gfxes();
  init_buffers();
  ovr_clean_ring_buffer();
  ovr_heapInit();
  ovr_play_sfx(83,0);
  return;
}



/* 3381:0693 */

/* Rebuilds the whole GMapFlags array from GMapCells (bits 0/1/2 per cell triple). */

void __cdecl16far init_rebuildMapFlags(void)

{
  uint *puVar1;
  short (*paasVar2) [60] [148];
  byte (*paabVar3) [59] [148];
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  
  for (iVar5 = 0; iVar5 < 0x3b; iVar5 = iVar5 + 1) {
    for (iVar4 = 0; iVar4 < 0x93; iVar4 = iVar4 + 1) {
      uVar6 = (undefined2)((ulong)GMapFlags >> 0x10);
      paasVar2 = (short (*) [60] [148])GMapFlags;
      if (((*paasVar2)[iVar5][iVar4] & 4U) == 0) {
        if ((((*(byte (*) [59] [148])GMapCells)[iVar5][iVar4] == 0) &&
            ((*(byte (*) [59] [148])GMapCells)[iVar5 + 1][iVar4 + 1] == 0)) &&
           ((*(byte (*) [59] [148])GMapCells)[iVar5 + 1][iVar4] == 0)) {
          puVar1 = (uint *)((*paasVar2)[iVar5] + iVar4);
          *puVar1 = *puVar1 | 1;
        }
        uVar6 = (undefined2)((ulong)GMapCells >> 0x10);
        paabVar3 = (byte (*) [59] [148])GMapCells;
        if ((((*paabVar3)[iVar5][iVar4] == 0) && ((*paabVar3)[iVar5 + 1][iVar4 + 1] == 0)) &&
           ((*paabVar3)[iVar5][iVar4 + 1] == 0)) {
          puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[iVar5] + iVar4);
          *puVar1 = *puVar1 | 2;
        }
      }
      else {
        if ((((*(byte (*) [59] [148])GMapCells)[iVar5 + 1][iVar4] == 0) &&
            ((*(byte (*) [59] [148])GMapCells)[iVar5][iVar4 + 1] == 0)) &&
           ((*(byte (*) [59] [148])GMapCells)[iVar5][iVar4] == 0)) {
          puVar1 = (uint *)((*paasVar2)[iVar5] + iVar4);
          *puVar1 = *puVar1 | 1;
        }
        if ((((*(byte (*) [59] [148])GMapCells)[iVar5 + 1][iVar4] == 0) &&
            ((*(byte (*) [59] [148])GMapCells)[iVar5][iVar4 + 1] == 0)) &&
           ((*(byte (*) [59] [148])GMapCells)[iVar5 + 1][iVar4 + 1] == 0)) {
          puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[iVar5] + iVar4);
          *puVar1 = *puVar1 | 2;
        }
      }
    }
  }
  return;
}



/* 3381:08dc */
stg_tmp_t * __cdecl16far init_textFilename(void)

{
  undefined1 stk_d744;   /* stack slot d744 */
  uint16_t uVar1;
  far_t gfx;
  far_t gfx_00;
  far_t src;
  far_t src_00;
  far_t handle;
  far_t handle_00;
  ulong uVar2;
  char cVar3;
  byte bVar4;
  uint32_t *puVar5;
  undefined1 extraout_AH;
  undefined1 uVar10;
  uint32_t *puVar6;
  uint16_t uVar7;
  uint uVar8;
  stg_tmp_t *psVar9;
  undefined1 extraout_AH_00;
  int in_CX;
  uint extraout_DX;
  uint uVar11;
  uint uVar12;
  byte (*paabVar13) [59] [148];
  short (*paasVar14) [148] [60];
  uint16_t unaff_SI;
  int iVar15;
  int iVar16;
  byte unaff_DI;
  uint uVar17;
  uint32_t *__return_storage_ptr__;
  undefined2 uVar18;
  undefined2 unaff_SS;
  bool bVar19;
  longdouble in_ST0;
  undefined4 in_stack_00000004;
  int16_t in_stack_00000008;
  byte abStackY_348 [488];
  undefined1 auStackY_160 [158];
  undefined2 uStackY_c2;
  undefined2 uStackY_c0;
  undefined2 uStackY_be;
  char acStack_a4 [92];
  uint16_t uStack_48;
  uint16_t uStack_46;
  int8_t iStack_40;
  uint8_t uStack_3f;
  lbm_type_t lStack_3e;
  uint16_t uStack_34;
  uint16_t uStack_32;
  far_t fStack_30;
  char cStack_2c;
  byte bStack_2b;
  uint32_t *puStack_2a;
  uint uStack_28;
  uint32_t *puStack_26;
  uint uStack_24;
  uint uStack_22;
  uint uStack_20;
  void *pvStack_1e;
  uint32_t *puStack_1c;
  byte *pbStack_18;
  uint uStack_16;
  uint uStack_14;
  uint uStack_12;
  undefined2 uStack_10;
  uint16_t uStack_e;
  uint uStack_c;
  uint uStack_a;
  uint uStack_8;
  int iStack_6;
  byte bStack_3;
  
  uStack_10 = (uint)(byte)uStack_10;
  for (iVar15 = 0; iVar15 < 0x94; iVar15 = iVar15 + 1) {
    uVar7 = ovr_randBelow(10);
    if ((uVar7 & 0xff) == 0) {
      uVar7 = ovr_randBelow(2);
      cVar3 = (char)uVar7 * '\x02' + (*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) + -1;
      uStack_10 = CONCAT11(cVar3,(byte)uStack_10);
      if (cVar3 < -1) {
        uStack_10 = CONCAT11(0xff,(byte)uStack_10);
      }
      if ('\x01' < (*(uint8_t *)((uint8_t *)&(uStack_10) + 1))) {
        uStack_10 = CONCAT11(1,(byte)uStack_10);
      }
    }
    if ((iVar15 == 0) || (iVar15 == 0x93)) {
      uStack_10 = uStack_10 & 0xff;
    }
    acStack_a4[iVar15] = (*(uint8_t *)((uint8_t *)&(uStack_10) + 1));
  }
  uStack_c = 0;
  uStack_a = 0;
  _fsetmem(GUnitGrid,0x4560,0);
  psVar9 = (stg_tmp_t *)((char *)0x26510);
  _fsetmem(GMapFlags,0x4560,0);
  for (uVar17 = 0; (int)uVar17 < 0x3c; uVar17 = uVar17 + 1) {
    if ((uVar17 & 1) == 0) {
      for (iVar15 = 0; iVar15 < 0x94; iVar15 = iVar15 + 1) {
        uStack_c = 0;
        if (iVar15 != 0) {
          uStack_c = (int)(char)((byte (*) [59] [148])GMapCells)[-1][uVar17 + 0x3a][iVar15 + 0x93];
        }
        if (uVar17 != 0) {
          uStack_c = uStack_c +
                     (int)(char)((byte (*) [59] [148])GMapCells)[-1][uVar17 + 0x3a]
                                [acStack_a4[iVar15] + iVar15];
        }
        uStack_c = (int)uStack_c >> 1;
        if ((iVar15 != 0) && (acStack_a4[iVar15 + -1] != acStack_a4[iVar15])) {
          uVar7 = ovr_randBelow(8);
          uStack_8 = uVar7 & 0xff;
          if (uStack_8 == 1) {
            acStack_a4[iVar15] = acStack_a4[iVar15 + -1];
          }
          else if (uStack_8 == 2) {
            acStack_a4[iVar15 + -1] = acStack_a4[iVar15];
          }
        }
        uVar7 = ovr_randBelow(0x10);
        if ((uVar7 & 0xff) == 0) {
          if (iVar15 != 0) {
            (*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) = acStack_a4[iVar15 + -1];
            uVar7 = ovr_randBelow(2);
            cVar3 = (char)uVar7 * '\x02' + (*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) + -1;
            uStack_10 = CONCAT11(cVar3,(byte)uStack_10);
            if (cVar3 < -1) {
              uStack_10 = CONCAT11(0xff,(byte)uStack_10);
            }
            if ('\x01' < (*(uint8_t *)((uint8_t *)&(uStack_10) + 1))) {
              uStack_10 = CONCAT11(1,(byte)uStack_10);
            }
            acStack_a4[iVar15] = (*(uint8_t *)((uint8_t *)&(uStack_10) + 1));
          }
          if ((int)uStack_c < 0x56) {
            if ((int)uStack_c < 0x41) {
              if ((int)uStack_c < 0x2b) {
                if ((int)uStack_c < 0x16) {
                  if ((int)uStack_c < 1) {
                    uVar7 = ovr_randBelow(9);
                    uStack_a = (uVar7 & 0xff) - 2;
                  }
                  else {
                    uVar7 = ovr_randBelow(8);
                    uStack_a = (uVar7 & 0xff) - 5;
                  }
                }
                else {
                  uVar7 = ovr_randBelow(0x10);
                  uStack_a = (uVar7 & 0xff) - 8;
                }
              }
              else {
                uVar7 = ovr_randBelow(0xb);
                uStack_a = (uVar7 & 0xff) - 5;
              }
            }
            else {
              uVar7 = ovr_randBelow(8);
              uStack_a = (uVar7 & 0xff) - 4;
            }
          }
          else {
            uVar7 = ovr_randBelow(0x11);
            uStack_a = (uVar7 & 0xff) - 8;
          }
        }
        if ((int)uStack_c < 0x56) {
          if ((int)uStack_c < 0x41) {
            if ((int)uStack_c < 0x2b) {
              if ((int)uStack_c < 0x16) {
                if ((int)uStack_c < 1) {
                  uStack_e = 0xb;
                }
                else {
                  uStack_e = 5;
                }
              }
              else {
                uStack_e = 0xf;
              }
            }
            else {
              uStack_e = 5;
            }
          }
          else {
            uStack_e = 0x13;
          }
        }
        else {
          uStack_e = 9;
        }
        uVar7 = ovr_randBelow(uStack_e);
        uStack_c = uStack_c + ((uVar7 & 0xff) - ((int)uStack_e >> 1)) + uStack_a + 1;
        if ((int)uStack_c < -0x23) {
          uStack_c = 0xffdd;
          uStack_a = (uStack_a ^ (int)uStack_a >> 0xf) - ((int)uStack_a >> 0xf);
        }
        if (0x7f < (int)uStack_c) {
          uStack_c = 0x7f;
          uStack_a = -((uStack_a ^ (int)uStack_a >> 0xf) - ((int)uStack_a >> 0xf));
        }
        psVar9 = (stg_tmp_t *)CONCAT11((char)(uVar17 * 0x94 >> 8),(byte)uStack_c);
        (*(byte (*) [59] [148])GMapCells)[uVar17][iVar15] = (byte)uStack_c;
      }
    }
    else {
      for (iVar15 = 0x93; -1 < iVar15; iVar15 = iVar15 + -1) {
        uStack_c = 0;
        if (iVar15 != 0x93) {
          uStack_c = (int)(char)(*(byte (*) [59] [148])GMapCells)[uVar17][iVar15 + 1];
        }
        if (uVar17 != 0) {
          uStack_c = uStack_c +
                     (int)(char)((byte (*) [59] [148])GMapCells)[-1][uVar17 + 0x3a]
                                [acStack_a4[iVar15] + iVar15];
        }
        uStack_c = (int)uStack_c >> 1;
        if ((iVar15 != 0x93) && (acStack_a4[iVar15 + 1] != acStack_a4[iVar15])) {
          uVar7 = ovr_randBelow(0x10);
          uStack_8 = uVar7 & 0xff;
          if (uStack_8 == 1) {
            acStack_a4[iVar15] = acStack_a4[iVar15 + 1];
          }
          else if (uStack_8 == 2) {
            acStack_a4[iVar15 + 1] = acStack_a4[iVar15];
          }
        }
        uVar7 = ovr_randBelow(0x10);
        if ((uVar7 & 0xff) == 0) {
          if (iVar15 != 0x93) {
            (*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) = acStack_a4[iVar15 + 1];
            uVar7 = ovr_randBelow(2);
            cVar3 = (char)uVar7 * '\x02' + (*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) + -1;
            uStack_10 = CONCAT11(cVar3,(byte)uStack_10);
            if (cVar3 < -1) {
              uStack_10 = CONCAT11(0xff,(byte)uStack_10);
            }
            if ('\x01' < (*(uint8_t *)((uint8_t *)&(uStack_10) + 1))) {
              uStack_10 = CONCAT11(1,(byte)uStack_10);
            }
            acStack_a4[iVar15] = (*(uint8_t *)((uint8_t *)&(uStack_10) + 1));
          }
          if ((int)uStack_c < 0x56) {
            if ((int)uStack_c < 0x41) {
              if ((int)uStack_c < 0x2b) {
                if ((int)uStack_c < 0x16) {
                  if ((int)uStack_c < 1) {
                    uVar7 = ovr_randBelow(9);
                    uStack_a = (uVar7 & 0xff) - 2;
                  }
                  else {
                    uVar7 = ovr_randBelow(8);
                    uStack_a = (uVar7 & 0xff) - 5;
                  }
                }
                else {
                  uVar7 = ovr_randBelow(0x10);
                  uStack_a = (uVar7 & 0xff) - 8;
                }
              }
              else {
                uVar7 = ovr_randBelow(0xb);
                uStack_a = (uVar7 & 0xff) - 5;
              }
            }
            else {
              uVar7 = ovr_randBelow(8);
              uStack_a = (uVar7 & 0xff) - 4;
            }
          }
          else {
            uVar7 = ovr_randBelow(0x11);
            uStack_a = (uVar7 & 0xff) - 8;
          }
        }
        if ((int)uStack_c < 0x56) {
          if ((int)uStack_c < 0x41) {
            if ((int)uStack_c < 0x2b) {
              if ((int)uStack_c < 0x16) {
                if ((int)uStack_c < 1) {
                  uStack_e = 0xb;
                }
                else {
                  uStack_e = 5;
                }
              }
              else {
                uStack_e = 0xf;
              }
            }
            else {
              uStack_e = 5;
            }
          }
          else {
            uStack_e = 0x13;
          }
        }
        else {
          uStack_e = 9;
        }
        uVar7 = ovr_randBelow(uStack_e);
        uStack_c = uStack_c + ((uVar7 & 0xff) - ((int)uStack_e >> 1)) + uStack_a + 1;
        if ((int)uStack_c < -0x7f) {
          uStack_c = 0xff81;
          uStack_a = (uStack_a ^ (int)uStack_a >> 0xf) - ((int)uStack_a >> 0xf);
        }
        if (0x7f < (int)uStack_c) {
          uStack_c = 0x7f;
          uStack_a = -((uStack_a ^ (int)uStack_a >> 0xf) - ((int)uStack_a >> 0xf));
        }
        psVar9 = (stg_tmp_t *)CONCAT11((char)(uVar17 * 0x94 >> 8),(byte)uStack_c);
        (*(byte (*) [59] [148])GMapCells)[uVar17][iVar15] = (byte)uStack_c;
      }
    }
  }
  for (iVar15 = 0; iVar15 < 0x3c; iVar15 = iVar15 + 1) {
    for (iVar16 = 0; iVar16 < 0x94; iVar16 = iVar16 + 1) {
      uVar18 = (undefined2)((ulong)GMapCells >> 0x10);
      if ((char)(*(byte (*) [59] [148])GMapCells)[iVar15][iVar16] < '\0') {
        (*(byte (*) [59] [148])GMapCells)[iVar15][iVar16] = 0;
      }
      psVar9 = (stg_tmp_t *)(iVar15 * 0x94);
      if ((iVar16 != 0x93) && (iVar15 != 0x3c)) {
        uVar18 = (undefined2)((ulong)GMapCells >> 0x10);
        paabVar13 = (byte (*) [59] [148])GMapCells;
        uVar17 = (int)(char)(*paabVar13)[iVar15 + 1][iVar16] -
                 (int)(char)(*paabVar13)[iVar15][iVar16 + 1];
        uVar11 = (int)uVar17 >> 0xf;
        uVar8 = (int)(char)(*paabVar13)[iVar15][iVar16] -
                (int)(char)(*paabVar13)[iVar15 + 1][iVar16 + 1];
        uVar12 = (int)uVar8 >> 0xf;
        psVar9 = (stg_tmp_t *)((uVar8 ^ uVar12) - uVar12);
        if ((int)((uVar17 ^ uVar11) - uVar11) < (int)psVar9) {
          psVar9 = (stg_tmp_t *)(iVar16 * 2);
          *(uint *)(psVar9->cmap + (int)(*(short (*) [60] [148])GMapFlags + iVar15)) =
               *(uint *)(psVar9->cmap + (int)(*(short (*) [60] [148])GMapFlags + iVar15)) | 4;
        }
      }
    }
  }
  init_rebuildMapFlags();
  init_usesRandBelow2();
  init_rebuildMapFlags();
  __return_storage_ptr__ = (uint32_t *)0x0;
  do {
    if (0x3a < (int)__return_storage_ptr__) {
      for (iVar15 = 1; iVar15 < 0x3a; iVar15 = iVar15 + 1) {
        for (iVar16 = 1; iVar16 < 0x92; iVar16 = iVar16 + 1) {
          uVar7 = ovr_randBelow(2);
          psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
          if (psVar9 == (stg_tmp_t *)0x0) {
            psVar9 = (stg_tmp_t *)(iVar15 * 0x94);
            uVar18 = (undefined2)((ulong)GMapCells >> 0x10);
            paabVar13 = (byte (*) [59] [148])GMapCells;
            if ((((((psVar9->cmap[(int)(*paabVar13 + -1) + 0x93 + iVar16] != 0) &&
                   (psVar9 = (stg_tmp_t *)(*paabVar13 + iVar15), psVar9->cmap[iVar16 + 0x93] != 0))
                  && (psVar9 = (stg_tmp_t *)(iVar15 * 0x94),
                     psVar9->cmap[(int)((*paabVar13)[0] + iVar16)] != 0)) &&
                 ((psVar9 = (stg_tmp_t *)(*paabVar13 + iVar15), psVar9->cmap[iVar16 + 0x94] != 0 &&
                  (psVar9 = (stg_tmp_t *)(iVar15 * 0x94),
                  psVar9->cmap[(int)((*paabVar13)[0] + iVar16 + 1)] != 0)))) &&
                (psVar9 = (stg_tmp_t *)(*paabVar13 + iVar15), psVar9->cmap[iVar16 + 0x95] != 0)) &&
               (((bVar4 = (*paabVar13)[iVar15][iVar16],
                 psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar15 * 0x94) >> 8),bVar4),
                 (char)bVar4 <= (char)(*paabVar13)[iVar15][iVar16 + 1] &&
                 (bVar4 = (*paabVar13)[iVar15][iVar16],
                 psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar15 * 0x94) >> 8),bVar4),
                 (char)bVar4 <= (char)paabVar13[-1][iVar15 + 0x3a][iVar16 + 0x93])) &&
                ((bVar4 = (*paabVar13)[iVar15][iVar16],
                 psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar15 * 0x94) >> 8),bVar4),
                 (char)bVar4 <= (char)paabVar13[-1][iVar15 + 0x3a][iVar16] &&
                 (((bVar4 = (*paabVar13)[iVar15][iVar16 + 1],
                   psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar15 * 0x94) >> 8),bVar4),
                   (char)bVar4 <= (char)paabVar13[-1][iVar15 + 0x3a][iVar16 + 1] &&
                   (bVar4 = (*paabVar13)[iVar15][iVar16],
                   psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar15 * 0x94) >> 8),bVar4),
                   (char)bVar4 <= (char)(*paabVar13)[iVar15 + 1][iVar16])) &&
                  (bVar4 = (*paabVar13)[iVar15][iVar16 + 1],
                  psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar15 * 0x94) >> 8),bVar4),
                  (char)bVar4 <= (char)(*paabVar13)[iVar15 + 1][iVar16 + 1])))))))) {
              uVar17 = ovr_init_getMapFlags(iVar16);
              psVar9 = (stg_tmp_t *)(uVar17 & 0xff);
              if (psVar9 == (stg_tmp_t *)0x0) {
                uVar17 = ovr_init_getMapFlags(iVar16 + -1);
                psVar9 = (stg_tmp_t *)(uVar17 & 0xff);
                if ((psVar9 == (stg_tmp_t *)0x0) &&
                   (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags2(iVar16), (char)psVar9 == '\x02')
                   ) {
                  iStack_6 = ((short (*) [148] [60])GUnitGrid)[-1][iVar16 + 0x92][iVar15];
                  bStack_3 = ((unit_t *)GUnits + iStack_6)->bldType;
                  psVar9 = (stg_tmp_t *)((uint)bStack_3 * 0x27);
                  if ((psVar9->cmap[0x11b] < 2) &&
                     (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags2(iVar16), (byte)psVar9 < 3)) {
                    uVar7 = ovr_randBelow(5);
                    ((short (*) [148] [60])GUnitGrid)[-1][iVar16 + 0x93][iVar15] =
                         (uVar7 & 0xff) + 0x92;
                    uVar2 = (ulong)GUnitGrid >> 0x10;
                    paasVar14 = (short (*) [148] [60])GUnitGrid;
                    psVar9 = (stg_tmp_t *)(iVar15 * 2);
                    (psVar9->cmap + (int)(*paasVar14 + iVar16))[0] = 0;
                    (psVar9->cmap + (int)(*paasVar14 + iVar16))[1] = 0;
                  }
                }
              }
            }
          }
        }
      }
      init_rebuildAllDirectionFlags();
      return psVar9;
    }
    for (iVar15 = 0; iVar15 < 0x93; iVar15 = iVar15 + 1) {
      psVar9 = (stg_tmp_t *)((int)__return_storage_ptr__ * 0x94);
      uVar18 = (undefined2)((ulong)GMapCells >> 0x10);
      paabVar13 = (byte (*) [59] [148])GMapCells;
      if (((psVar9->cmap[(int)((*paabVar13)[0] + iVar15)] != 0) &&
          (psVar9 = (stg_tmp_t *)((int)__return_storage_ptr__ * 0x94),
          psVar9->cmap[(int)((*paabVar13)[0] + iVar15 + 1)] != 0)) &&
         ((psVar9 = (stg_tmp_t *)(*paabVar13 + (int)__return_storage_ptr__),
          psVar9->cmap[iVar15 + 0x94] != 0 &&
          (psVar9 = (stg_tmp_t *)(*paabVar13 + (int)__return_storage_ptr__),
          psVar9->cmap[iVar15 + 0x94] != 0)))) {
        uVar17 = ovr_init_getMapFlags(iVar15);
        psVar9 = (stg_tmp_t *)(uVar17 & 0xff);
        if (psVar9 == (stg_tmp_t *)0x0) {
          uStack_c = (uint)(char)(*(byte (*) [59] [148])GMapCells)[(int)__return_storage_ptr__]
                                 [iVar15];
          if ((int)uStack_c < 0x6b) {
            if ((int)uStack_c < 0x56) {
              if ((int)uStack_c < 0x40) {
                if ((int)uStack_c < 0x2b) {
                  if ((int)uStack_c < 0x16) {
                    uVar7 = ovr_randBelow(4);
                    psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
                    if (psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 2)) {
                      uVar7 = ovr_randBelow(6);
                      psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x3d);
                      (*(short (*) [148] [60])GUnitGrid)[iVar15][(int)__return_storage_ptr__] =
                           (short)psVar9;
                    }
                    else if ((psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 3)) &&
                            (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(iVar15),
                            (char)psVar9 != '\0')) {
                      uVar7 = ovr_randBelow(2);
                      psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
                      if (psVar9 == (stg_tmp_t *)0x0) {
                        uVar7 = ovr_randBelow(9);
                        psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
                        (*(short (*) [148] [60])GUnitGrid)[iVar15][(int)__return_storage_ptr__] =
                             (short)psVar9;
                      }
                    }
                  }
                  else {
                    uVar7 = ovr_randBelow(4);
                    psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
                    switch((uint16_t)psVar9)   /* hand fix: case values are ints */ {
                    case (uint16_t)0x0:
                      func_0x000318f5();
                      bStack_2b = 0;
                      uVar17 = extraout_DX;
                      goto L_grabLbm_0445;
                    case (uint16_t)0x1:
                      while( true ) {
                        pbStack_18 = psVar9->cmap + (int)pbStack_18;
                        psVar9 = (stg_tmp_t *)(iVar15 + (int)__return_storage_ptr__);
                        if ((int)puStack_1c <= (int)psVar9) {
                          psVar9 = memcpy((char *)CONCAT13((char)(uStack_12 >> 8),
                                                           CONCAT12((char)uStack_12,uStack_14)),
                                          (char *)CONCAT13((char)((uint)unaff_SS >> 8),
                                                           CONCAT12((char)unaff_SS,
                                                                    auStackY_160 + uStack_c)),
                                          uStack_e);
                          uStack_14 = uStack_14 + 0x140;
                        }
                        iVar15 = iVar15 + 1;
                        if (((int)uStack_10 <= iVar15) ||
                           (psVar9 = (stg_tmp_t *)(iVar15 + (int)__return_storage_ptr__),
                           (int)uStack_20 < (int)psVar9)) break;
                        (*(uint8_t *)((uint8_t *)&(src_00.seg))) = (char)uStack_16;
                        src_00.ofs = (uint16_t)pbStack_18;
                        (*(uint8_t *)((uint8_t *)&(src_00.seg) + 1)) = (char)(uStack_16 >> 8);
                        psVar9 = (stg_tmp_t *)ovr_unrle(src_00);
                      }
                      return psVar9;
                    case (uint16_t)0x2:
                      *__return_storage_ptr__ = (long)in_ST0;
                    /* WARNING: Bad instruction - Truncating control flow here */
                      halt_baddata();
                    case (uint16_t)0x3:
                      goto switchD_3000_4a6e_caseD_3;
                    }
                  }
                }
                else {
                  uVar7 = ovr_randBelow(4);
                  psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
                  if (psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 1)) {
                    uVar7 = ovr_randBelow(6);
                    psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x3d);
                    (*(short (*) [148] [60])GUnitGrid)[iVar15][(int)__return_storage_ptr__] =
                         (short)psVar9;
                  }
                  else if ((psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 3)) &&
                          (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(iVar15),
                          (char)psVar9 != '\0')) {
                    uVar7 = ovr_randBelow(9);
                    psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
                    (*(short (*) [148] [60])GUnitGrid)[iVar15][(int)__return_storage_ptr__] =
                         (short)psVar9;
                  }
                }
              }
              else {
                uVar7 = ovr_randBelow(4);
                psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
                if (((psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 3)) &&
                    (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(iVar15), (char)psVar9 != '\0'))
                   && (psVar9 = (stg_tmp_t *)ovr_randBelow(2), (char)psVar9 != '\0')) {
                  uVar7 = ovr_randBelow(9);
                  psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
                  (*(short (*) [148] [60])GUnitGrid)[iVar15][(int)__return_storage_ptr__] =
                       (short)psVar9;
                }
              }
            }
            else {
              uVar7 = ovr_randBelow(4);
              psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
              if (psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 1)) {
                psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(iVar15);
                if ((char)psVar9 != '\0') {
                  uVar7 = ovr_randBelow(2);
                  if ((uVar7 & 0xff) == 0) {
                    uVar7 = ovr_randBelow(6);
                    psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x3d);
                    (*(short (*) [148] [60])GUnitGrid)[iVar15][(int)__return_storage_ptr__] =
                         (short)psVar9;
                  }
                  else {
                    uVar7 = ovr_randBelow(9);
                    psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
                    (*(short (*) [148] [60])GUnitGrid)[iVar15][(int)__return_storage_ptr__] =
                         (short)psVar9;
                  }
                }
              }
              else if ((psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 3)) &&
                      (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(iVar15), (char)psVar9 != '\0')
                      ) {
                uVar7 = ovr_randBelow(9);
                psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
                (*(short (*) [148] [60])GUnitGrid)[iVar15][(int)__return_storage_ptr__] =
                     (short)psVar9;
              }
            }
          }
          else {
            uVar7 = ovr_randBelow(4);
            psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
            if (((psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 2)) ||
                (psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 3))) &&
               (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(iVar15), (char)psVar9 != '\0')) {
              uVar7 = ovr_randBelow(9);
              psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
              (*(short (*) [148] [60])GUnitGrid)[iVar15][(int)__return_storage_ptr__] =
                   (short)psVar9;
            }
          }
        }
      }
    }
    __return_storage_ptr__ = (uint32_t *)((int)__return_storage_ptr__ + 1);
  } while( true );
switchD_3000_4a6e_caseD_3:
  do {
    *(int *)(&stk_d744 + iVar15) = *(int *)(&stk_d744 + iVar15) + in_CX;
    uStack_28 = constr_compute2((uint8_t)uStack_20,(uint8_t)uStack_22,(uint8_t)puStack_1c,
                                (byte)psVar9,unaff_DI);
    uStack_28 = uStack_28 & 0xff;
    ovr_ovc07_usesBiosReadKey(((uint16_t *)SquareLeftX)[(int)__return_storage_ptr__]);
    uVar17 = constr_compute2((uint8_t)puStack_1c,(uint8_t)pvStack_1e,(uint8_t)uStack_22,bStack_2b,2)
    ;
    puStack_2a = (uint32_t *)(uVar17 & 0xff);
    ovr_ovc07_usesBiosReadKey(((uint16_t *)SquareRightX)[(int)__return_storage_ptr__]);
    while( true ) {
      uVar17 = ovr_constr_usesGMapFlags(uStack_24 + GfxRndSeed);
      if ((char)uVar17 != '\0') {
        ovr_ovc07_usesLDIV_at_
                  (((uint16_t *)SquareLeftX)[(int)__return_storage_ptr__],RowScreenY[0] - uStack_10)
        ;
      }
      do {
        __return_storage_ptr__ = (uint32_t *)((int)__return_storage_ptr__ + 1);
        uVar7 = rowBandSquareFirst[0];
        if ((int)rowBandSquareEnd[0] <= (int)__return_storage_ptr__) {
          for (; (int)uVar7 < (int)rowBandSquareEnd[0]; uVar7 = uVar7 + 1) {
            uStack_24 = ((uint16_t *)squareColumn)[uVar7];
            bVar4 = ovr_constr_setHighlightAtOffset(uStack_24);
            uStack_e = CONCAT11(extraout_AH_00,bVar4);
            if ((*(byte *)((uint8_t *)&BuildingTypes[uStack_e] + 16) & 2) != 0) {
              iVar15 = ovr_constr_usesSmoothPrev(uStack_24);
              uStack_10 = iVar15 / 3;
              (*(uint8_t *)((uint8_t *)&(gfx.seg))) =
                   (char)*(undefined2 *)((char *)0x28ed6 + uStack_e * 0xc);
              gfx.ofs = *(undefined2 *)(undefined2 *)((char *)0x28ed4 + uStack_e * 0xc);
              (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) =
                   (char)((uint)*(undefined2 *)(undefined2 *)((char *)0x28ed6 + uStack_e * 0xc) >> 8);
              ovr_blit_usesBlitGfxN
                        (gfx,((uint16_t *)SquareLeftX)[uVar7],rowBandOrigin[0] - uStack_10,6);
            }
            if ((*(byte *)((uint8_t *)&BuildingTypes[uStack_e] + 16) & 1) != 0) {
              gfx_00.seg = *(uint16_t *)(undefined2 *)((char *)0x28eda + uStack_e * 0xc);
              gfx_00.ofs = *(uint16_t *)(undefined2 *)((char *)0x28ed8 + uStack_e * 0xc);
              ovr_blitGfxRect(gfx_00,((uint16_t *)SquareLeftX)[uVar7]);
            }
          }
          return (stg_tmp_t *)((char *)0x26510);
        }
      } while (((int)((uint16_t *)SquareRightX)[(int)__return_storage_ptr__] < 0xef) ||
              (0x134 < (int)((uint16_t *)SquareLeftX)[(int)__return_storage_ptr__]));
      uStack_24 = ((uint16_t *)squareColumn)[(int)__return_storage_ptr__];
      puStack_1c = (uint32_t *)constr_getCellAtOffset(uStack_24,-2);
      pvStack_1e = (void *)constr_getCellAtOffset(uStack_24 + 1,-2);
      iVar16 = ovr_constr_usesSmoothPrev(uStack_24);
      uStack_10 = iVar16 / 3;
      iVar16 = ovr_constr_usesSmoothPrev(uStack_24 + 1);
      uStack_12 = iVar16 / 3;
      psVar9 = (stg_tmp_t *)constr_getFlagsAtOffset(uStack_24,-1);
      bStack_2b = (byte)psVar9;
      if (((uint)psVar9 & 4) != 0) break;
      uStack_28 = constr_compute2((uint8_t)uStack_20,(uint8_t)uStack_22,(uint8_t)pvStack_1e,
                                  (byte)psVar9,2);
      uStack_28 = uStack_28 & 0xff;
      ovr_ovc07_usesBiosReadKey(((uint16_t *)SquareLeftX)[(int)__return_storage_ptr__]);
      uVar17 = constr_compute2((uint8_t)puStack_1c,(uint8_t)pvStack_1e,(uint8_t)uStack_20,bStack_2b,
                               1);
      puStack_2a = (uint32_t *)(uVar17 & 0xff);
      ovr_ovc07_usesBiosReadKey(((uint16_t *)SquareLeftX)[(int)__return_storage_ptr__]);
    }
    unaff_DI = 1;
  } while( true );
L_grabLbm_0445:
  iVar15 = ovr_stshRead();
  if (iVar15 != 0 || uVar17 != 0) {
bad_lbm:
    uVar7 = fStack_30.seg;
    psVar9 = (stg_tmp_t *)fStack_30.ofs;
    if ((&psVar9->bptr)->ofs != 0 || (psVar9->bptr).seg != 0) {
      uVar1 = (psVar9->bptr).seg;
      (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = (char)uVar1;
      handle_00.ofs = (&psVar9->bptr)->ofs;
      (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = (char)(uVar1 >> 8);
      ovr_stshFree(handle_00);
    }
    ovr_stshClose((uint16_t)__return_storage_ptr__);
    ovr_stshFree(fStack_30);
    printf("Filename %d %s  \r");
    ovr_biosReadKey();
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0xd);
  }
  if ((uStack_20 == uStack_c) && (uStack_22 == uStack_e)) {
    cStack_2c = '\x01';
    uVar17 = uStack_22;
    iVar15 = ovr_stshRead();
    if ((((iVar15 != 0 || uVar17 != 0) ||
         (puStack_2a = ovr_be4(puStack_2a), uStack_28 = uVar17, uVar17 != 0)) ||
        (puStack_2a != (uint32_t *)((byte *)__C0_ASM_CopyRight + 0x10))) ||
       (iVar15 = ovr_stshRead(), iVar15 != 0 || uVar17 != 0)) goto bad_lbm;
    uStack_32 = ovr_be2(uStack_48);
    uStack_34 = ovr_be2(uStack_46);
    goto L_grabLbm_0445;
  }
  if ((uStack_20 == uStack_14) && (uStack_22 == uStack_16)) {
    uVar17 = uStack_22;
    ovr_stshRead();
    puStack_2a = ovr_be4(puStack_2a);
    uStack_28 = uVar17;
    uStack_24 = uVar17;
    puStack_26 = puStack_2a;
    if (((uint)puStack_2a & 1) != 0) {
      puStack_26 = (uint32_t *)((int)puStack_2a + 1);
      uStack_24 = uVar17 + ((uint32_t *)0xfffe < puStack_2a);
    }
    if (((int)uStack_24 < 0) || ((uStack_24 == 0 && (puStack_26 < (char *)0x24400))))
    {
      if ((-1 < (int)uStack_24) && ((0 < (int)uStack_24 || (puStack_26 != (uint32_t *)0x0)))) {
        ovr_stshRead();
      }
    }
    else {
      ovr_stshRead();
      if ((-1 < (int)uStack_24) &&
         ((0 < (int)uStack_24 || ((char *)0x24400 < puStack_26)))) {
        ovr_stshTell(__return_storage_ptr__,unaff_SI);
        ovr_stshSeek((uint16_t)__return_storage_ptr__);
      }
    }
    puVar6 = (uint32_t *)0x0;
    while( true ) {
      if ((0 < (int)uStack_28) ||
         ((puVar5 = puStack_2a, uVar17 = uStack_28, uStack_28 == 0 &&
          ((char *)0x24400 < puStack_2a)))) {
        puVar5 = (uint32_t *)((char *)0x24400);
        uVar17 = 0;
      }
      if (((int)uVar17 < 1) && ((uVar17 != 0 || (puVar5 <= puVar6)))) break;
      ((stg_tmp_t *)fStack_30.ofs)->cmap[(int)puVar6] =
           (uint8_t)((int)(uint)abStackY_348[(int)puVar6] >> 2);
      puVar6 = (uint32_t *)((int)puVar6 + 1);
    }
  }
  else {
    if ((uStack_20 == uStack_10) && (uStack_22 == uStack_12)) {
      if (cStack_2c != '\0') {
        ovr_stshRead();
        puStack_1c = ovr_be4(puStack_2a);
        puStack_26 = puStack_1c;
        uStack_24 = uStack_22;
        if (((uint)puStack_1c & 1) != 0) {
          puStack_26 = (uint32_t *)((int)puStack_1c + 1);
          uStack_24 = uStack_22 + ((uint32_t *)0xfffe < puStack_1c);
        }
        puStack_2a = puStack_1c;
        pvStack_1e = ovr_stshAlloc(CONCAT13((char)(uStack_24 >> 8),
                                            CONCAT12((char)uStack_24,puStack_26)));
        ovr_stshRead();
        uVar10 = extraout_AH;
        ovr_stshClose((uint16_t)__return_storage_ptr__);
        uStackY_be = CONCAT11(uVar10,bStack_2b);
        uStackY_c0 = 0x2337;
        uStackY_c2 = 0x152a;
        src.seg = fStack_30.ofs;
        src.ofs = (uint16_t)puStack_1c;
        lbm_decode_body(lStack_3e,iStack_40,uStack_3f,(uint8_t)pvStack_1e,src,
                        (stg_tmp_t *)
                        CONCAT13((char)((ulong)in_stack_00000004 >> 0x18),
                                 CONCAT12((char)((ulong)in_stack_00000004 >> 0x10),fStack_30.seg)),
                        in_stack_00000008,uStack_32,uStack_34,unaff_SI);
        (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)puStack_1c;
        handle.ofs = (uint16_t)pvStack_1e;
        (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)puStack_1c >> 8);
        ovr_stshFree(handle);
        return (stg_tmp_t *)fStack_30.ofs;
      }
      goto bad_lbm;
    }
    uVar17 = uStack_22;
    ovr_stshRead();
    puStack_26 = ovr_be4(puStack_26);
    uStack_24 = uVar17;
    if (((uint)puStack_26 & 1) != 0) {
      bVar19 = (uint32_t *)0xfffe < puStack_26;
      puStack_26 = (uint32_t *)((int)puStack_26 + 1);
      uStack_24 = uVar17 + bVar19;
    }
    puVar6 = ovr_stshTell(__return_storage_ptr__,unaff_SI);
    uVar17 = ((int)puVar6 >> 0xf) + uStack_24 + (uint)CARRY2((uint)puVar6,(uint)puStack_26);
    ovr_stshSeek((uint16_t)__return_storage_ptr__);
  }
  goto L_grabLbm_0445;
}


/* 3381:1697 */

/* Initialises the 0xf8 GUnits records (bldType = index, level/unitType = 0xff). */

void __cdecl16far init_initGUnits(void)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 0xf8; iVar1 = iVar1 + 1) {
    ((unit_t *)GUnits + iVar1)->bldType = (byte)iVar1;
    ((unit_t *)GUnits)[iVar1].level = 0xff;
    ((unit_t *)GUnits)[iVar1].unitType = 0xff;
  }
  return;
}



/* 3381:16ef */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far init_buffers(void)

{
  undefined2 in_DX;
  
  (*(uint16_t *)((uint8_t *)&(GUnits))) = ovr_stshAlloc(0x2a30);
  (*(uint16_t *)((uint8_t *)&(GUnits) + 2)) = in_DX;
  _fsetmem((unit_t *)CONCAT22(in_DX,(unit_t *)GUnits),0x2a30,0);
  init_initGUnits();
  GUnitCount = 0xf8;
  (*(uint16_t *)((uint8_t *)&(GUnitGrid))) = ovr_stshAlloc(0x4560);
  (*(uint16_t *)((uint8_t *)&(GUnitGrid) + 2)) = in_DX;
  (*(uint16_t *)((uint8_t *)&(GMapFlags))) = ovr_stshAlloc(0x4560);
  (*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)) = in_DX;
  (*(uint16_t *)((uint8_t *)&(GMapCells))) = ovr_stshAlloc(0x22b0);
  (*(uint16_t *)((uint8_t *)&(GMapCells) + 2)) = in_DX;
  Entities = ovr_stshAlloc(33000);
  DAT_2000_d190 = in_DX;
  (*(uint16_t *)((uint8_t *)&(FillGrid))) = ovr_stshAlloc(0x6541);
  (*(uint16_t *)((uint8_t *)&(FillGrid) + 2)) = in_DX;
  init_computeMaxSquares();
  GLeaderCount = 0;
  GWantsExit2 = 0;
  mapViewActive = 0xff;
  return;
}



/* 3381:17e8 */

/* Computes the maximum square counts (GMaxSquare/GSMaxSquare) from the scale table and range-checks
   them. */

void __cdecl16far init_computeMaxSquares(void)

{
  far_t dst;
  int iVar1;
  int iVar2;
  uint uVar3;
  uint16_t uVar4;
  uint16_t unaff_SS;
  uint8_t scaleMap;
  byte abStack_1d [9];
  uint uStack_14;
  uint uStack_12;
  char cStack_f;
  uint uStack_e;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  uint uStack_6;
  uint uStack_4;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&scaleMap;
  F_SCOPY(far_from_u32((uint32_t)(0x241004e8)),dst);
  GMaxSquare = 0;
  cStack_f = '\b';
  do {
    if (cStack_f < '\0') {
      if (GMaxSquare != 0x1b0) {
        printf("NEW MAXSQUARE %d \r");
        ovr_gameProcessKey();
      }
      GSMaxSquare = 0;
      cStack_f = '\x02';
      do {
        if (cStack_f < '\0') {
          if (GSMaxSquare != 0x24) {
            printf("NEW SMAXSQUARE %d \r");
            ovr_gameProcessKey();
          }
          return;
        }
        ((uint16_t *)rowBandSquareFirst)[cStack_f] = GSMaxSquare;
        uStack_4 = ((uint)abStack_1d[cStack_f + -1] * 0x30) / 0x30;
        uStack_6 = ((uint)abStack_1d[cStack_f] * 0x30) / 0x30;
        ((uint16_t *)RowScreenX)[cStack_f] =
             (uint)*(byte *)(cStack_f + 0x74c) + ((uint)abStack_1d[cStack_f] * 0x3c) / 0x30;
        ((uint16_t *)RowScreenY)[cStack_f] =
             (uint)*(byte *)(cStack_f + 0x74b) + ((uint)abStack_1d[cStack_f + -1] * 0x3c) / 0x30;
        uStack_14 = ((uint)abStack_1d[cStack_f + -1] * 0x27) / 0x30;
        uStack_12 = ((uint)abStack_1d[cStack_f] * 0x27) / 0x30;
        iStack_8 = 0x111 - uStack_14;
        uVar3 = 0;
        for (iVar1 = 0x111 - uStack_12; 0xee < (int)((iVar1 - uStack_6) + uStack_12 + uStack_6);
            iVar1 = iVar1 - uStack_6) {
          iStack_8 = iStack_8 - uStack_4;
          uVar3 = uVar3 - 1;
        }
        for (; 0x7fff < uVar3; uVar3 = uVar3 + 1) {
          if (0x23 < (int)GSMaxSquare) {
                    /* WARNING: Subroutine does not return */
            ovr_stExit(8);
          }
          ((uint16_t *)SquareTopY)[GSMaxSquare] = iVar1 + uStack_12;
          ((uint16_t *)SquareBottomY)[GSMaxSquare] =
               ((uint16_t *)SquareTopY)[GSMaxSquare] + uStack_6;
          ((uint16_t *)SquareLeftX)[GSMaxSquare] = iStack_8 + uStack_14;
          ((uint16_t *)SquareRightX)[GSMaxSquare] =
               ((uint16_t *)SquareLeftX)[GSMaxSquare] + uStack_4;
          ((uint16_t *)squareColumn)[GSMaxSquare] = uVar3;
          if ((int)uVar3 < -1) {
            ((uint16_t *)squareSide)[GSMaxSquare] = 0;
          }
          else {
            ((uint16_t *)squareSide)[GSMaxSquare] = 1;
          }
          GSMaxSquare = GSMaxSquare + 1;
          iStack_8 = iStack_8 + uStack_4;
          iVar1 = iVar1 + uStack_6;
        }
        iStack_8 = 0x111 - uStack_14;
        uVar4 = 0;
        for (iVar1 = 0x111 - uStack_12; (int)(uStack_6 + iVar1 + uStack_12) < 0x135;
            iVar1 = iVar1 + uStack_6) {
          iStack_8 = iStack_8 + uStack_4;
          uVar4 = uVar4 + 1;
        }
        for (; -1 < (int)uVar4; uVar4 = uVar4 - 1) {
          if (0x23 < (int)GSMaxSquare) {
                    /* WARNING: Subroutine does not return */
            ovr_stExit(8);
          }
          ((uint16_t *)SquareTopY)[GSMaxSquare] = iVar1 + uStack_12;
          ((uint16_t *)SquareBottomY)[GSMaxSquare] =
               ((uint16_t *)SquareTopY)[GSMaxSquare] + uStack_6;
          ((uint16_t *)SquareLeftX)[GSMaxSquare] = iStack_8 + uStack_14;
          ((uint16_t *)SquareRightX)[GSMaxSquare] =
               ((uint16_t *)SquareLeftX)[GSMaxSquare] + uStack_4;
          ((uint16_t *)squareColumn)[GSMaxSquare] = uVar4;
          if ((int)uVar4 < 1) {
            ((uint16_t *)squareSide)[GSMaxSquare] = 1;
          }
          else {
            ((uint16_t *)squareSide)[GSMaxSquare] = 2;
          }
          GSMaxSquare = GSMaxSquare + 1;
          iStack_8 = iStack_8 - uStack_4;
          iVar1 = iVar1 - uStack_6;
        }
        ((uint16_t *)rowBandSquareEnd)[cStack_f] = GSMaxSquare;
        cStack_f = cStack_f + -1;
      } while( true );
    }
    ((uint16_t *)rowMapSquareFirst)[cStack_f] = GMaxSquare;
    uStack_4 = ((uint)abStack_1d[cStack_f + -1] * 0x30) / 0x10;
    uStack_6 = ((uint)abStack_1d[cStack_f] * 0x30) / 0x10;
    ((uint16_t *)ScreenOriginX)[cStack_f] =
         (uint)*(byte *)(cStack_f + 0x729) + ((uint)abStack_1d[cStack_f] * 0x38) / 0x10;
    ((uint16_t *)ScreenOriginY)[cStack_f] =
         (uint)*(byte *)(cStack_f + 0x728) + ((uint)abStack_1d[cStack_f + -1] * 0x38) / 0x10;
    uStack_14 = ((uint)abStack_1d[cStack_f + -1] * 0x27) / 0x10;
    uStack_12 = ((uint)abStack_1d[cStack_f] * 0x27) / 0x10;
    iStack_a = 0x75 - uStack_14;
    uStack_e = 0;
    for (iStack_c = 0x75 - uStack_12; 0xb < (int)((iStack_c - uStack_6) + uStack_12 + uStack_6);
        iStack_c = iStack_c - uStack_6) {
      iStack_a = iStack_a - uStack_4;
      uStack_e = uStack_e - 1;
    }
    *(uint *)(cStack_f * 2 + -0x73ed) = uStack_e;
    iStack_8 = 0x75 - uStack_14;
    iVar2 = 0;
    for (iVar1 = 0x75 - uStack_12; (int)(uStack_6 + iVar1 + uStack_12) < 0xdf;
        iVar1 = iVar1 + uStack_6) {
      iStack_8 = iStack_8 + uStack_4;
      iVar2 = iVar2 + 1;
    }
    *(int *)(cStack_f * 2 + -0x73ff) = iVar2;
    while ((0x7fff < uStack_e || (-1 < iVar2))) {
      if ((int)uStack_e < 0) {
        if (0x1af < (int)GMaxSquare) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(7);
        }
        *(int *)((int)&AgntAnms[0x5d].sx + 1 + GMaxSquare * 2) = iStack_c + uStack_12;
        *(int *)(&mapSquareBottomY[GMaxSquare]) =
             *(int *)((int)&AgntAnms[0x5d].sx + 1 + GMaxSquare * 2) + uStack_6;
        *(int *)(&mapSquareLeftX[GMaxSquare]) = iStack_a + uStack_14;
        *(int *)(&mapSquareRightX[GMaxSquare]) = *(int *)(&mapSquareLeftX[GMaxSquare]) + uStack_4;
        *(uint *)(&mapSquareColumn[GMaxSquare]) = uStack_e;
        if ((int)uStack_e < -1) {
          *(undefined2 *)(GMaxSquare * 2) = 0;
        }
        else {
          *(undefined2 *)(GMaxSquare * 2) = 1;
        }
        GMaxSquare = GMaxSquare + 1;
        iStack_a = iStack_a + uStack_4;
        iStack_c = iStack_c + uStack_6;
        uStack_e = uStack_e + 1;
      }
      if (-1 < iVar2) {
        if (0x1af < (int)GMaxSquare) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(7);
        }
        *(int *)((int)&AgntAnms[0x5d].sx + 1 + GMaxSquare * 2) = iVar1 + uStack_12;
        *(int *)(&mapSquareBottomY[GMaxSquare]) =
             *(int *)((int)&AgntAnms[0x5d].sx + 1 + GMaxSquare * 2) + uStack_6;
        *(int *)(&mapSquareLeftX[GMaxSquare]) = iStack_8 + uStack_14;
        *(int *)(&mapSquareRightX[GMaxSquare]) = *(int *)(&mapSquareLeftX[GMaxSquare]) + uStack_4;
        *(int *)(&mapSquareColumn[GMaxSquare]) = iVar2;
        if (iVar2 < 1) {
          *(undefined2 *)(GMaxSquare * 2) = 1;
        }
        else {
          *(undefined2 *)(GMaxSquare * 2) = 2;
        }
        GMaxSquare = GMaxSquare + 1;
        iStack_8 = iStack_8 - uStack_4;
        iVar1 = iVar1 - uStack_6;
        iVar2 = iVar2 + -1;
      }
    }
    ((uint16_t *)rowMapSquareEnd)[cStack_f] = GMaxSquare;
    cStack_f = cStack_f + -1;
  } while( true );
}



/* 3381:1f1d */

/* [R6] touches GMapCells */

uint __cdecl16far init_usesGMapCells(int x,int y,...)

{
  byte (*pabVar1) [148];
  uint uVar2;
  byte (*paabVar3) [59] [148];
  undefined2 uVar4;
  
  pabVar1 = (byte (*) [148])(y * 0x94);
  uVar4 = (undefined2)((ulong)GMapCells >> 0x10);
  paabVar3 = (byte (*) [59] [148])GMapCells;
  if (((((*paabVar3)[0][(int)(*pabVar1 + x)] == 0) ||
       (pabVar1 = (byte (*) [148])(y * 0x94), (*paabVar3)[0][(int)(*pabVar1 + x + 1)] == 0)) ||
      (pabVar1 = *paabVar3 + y, pabVar1[1][x] == 0)) ||
     (pabVar1 = *paabVar3 + y, pabVar1[1][x] == 0)) {
    uVar2 = (uint)pabVar1 & 0xff00;
  }
  else {
    uVar2 = CONCAT11((char)((uint)pabVar1 >> 8),1);
  }
  return uVar2;
}



/* 3381:1fa9 */

/* resets EntityCount to 0 */

void __cdecl16far clearEntities(void)

{
  EntityCount = 0;
  return;
}



/* 3381:1fba */

/* frees every leader sheet and the cached graphics blocks, then zeroes GLeaderCount */

void __cdecl16far freeLeaderData(void)

{
  int iVar1;
  far_t handle;
  far_t handle_00;
  far_t handle_01;
  far_t handle_02;
  far_t handle_03;
  
  for (iVar1 = 0; iVar1 < (int)(uint)GLeaderCount; iVar1 = iVar1 + 1) {
    handle.seg = ((uint16_t *)(iVar1 * 4))[1];
    handle.ofs = *(uint16_t *)(iVar1 * 4);
    ovr_stshFree(handle);
  }
  GLeaderCount = 0;
  if (audioSaveCut1Ofs != 0 || audioSaveCut1Seg != 0) {
    handle_00.seg = audioSaveCut1Seg;
    handle_00.ofs = audioSaveCut1Ofs;
    ovr_stshFree(handle_00);
  }
  if (audioSaveCut2Ofs != 0 || audioSaveCut2Seg != 0) {
    handle_01.seg = audioSaveCut2Seg;
    handle_01.ofs = audioSaveCut2Ofs;
    ovr_stshFree(handle_01);
  }
  if (upperTextOfs != (byte *)0x0 || upperTextSeg != 0) {
    handle_02.seg = upperTextSeg;
    handle_02.ofs = (uint16_t)upperTextOfs;
    ovr_stshFree(handle_02);
  }
  upperTextSeg = 0;
  upperTextOfs = (byte *)0x0;
  audioSaveCut1Seg = 0;
  audioSaveCut1Ofs = 0;
  audioSaveCut2Seg = 0;
  audioSaveCut2Ofs = 0;
  ovr_clean_ring_buffer();
  if (CrossBlitPtr.ofs != 0 || CrossBlitPtr.seg != 0) {
    handle_03.seg = CrossBlitPtr.seg;
    handle_03.ofs = CrossBlitPtr.ofs;
    ovr_stshFree(handle_03);
  }
  CrossBlitPtr.seg = 0;
  CrossBlitPtr.ofs = 0;
  ovr_clearMiceProcessed();
  return;
}



/* 3381:20ee */

/* frees the audio tracks and the leader data when the game is unloaded */

void __cdecl16far freeGameResources(void)

{
  ovr_fmFreeAudio(1);
  freeLeaderData();
  return;
}



/* 3381:2101 */

/* WARNING: Variable defined which should be unmapped: palette */
/* [R4] calls clearEntities */

void __cdecl16far init_usesClearEntities(void)

{
  far_t handle;
  uint16_t uVar1;
  uint16_t uVar2;
  stg_tmp_t *srcOfs;
  uint16_t unaff_SS;
  uint8_t palette [768];
  
  GUnitCount = 0xf8;
  init_initGUnits();
  AgntFlag1 = false;
  freeGameResources();
  GLeaderCount = 0;
  CurPartySlot = 0;
  PartySize = 5;
  PartyCount = 0;
  GRecordCount = 0;
  spyReportTimer = 0;
  seasonTimer = 0;
  unitUpdateTimer = 0;
  tickCountHi = 0;
  tickCountLo = 0;
  PlayerIndex = 0;
  uVar1 = ovr_randBelow(3);
  uVar1 = (uVar1 & 0xff) * 3;
  seasonGroupBase = (undefined1)uVar1;
  if (GameRunning == false) {
    uVar2 = ovr_randBelow(0x14);
    randomFeatureCount = (undefined1)uVar2;
  }
  else {
    seasonGroupBase = 0;
    randomFeatureCount = 0x14;
  }
  init_textFilename();
  ovr_clearSquareRecords();
  clearEntities();
  ovr_ovc24_usesAlignUp4();
  GfxRndSeed = 0x48;
  GfxRndSeed2 = 0x1e;
  SaveAuto = 1;
  TimerSeed.hi = 0;
  TimerSeed.lo = 0;
  GameTick = 0;
  _fmemset((void *)0x2410,2,(*(uint16_t *)((uint8_t *)&(palette))));
  promotionCount = 0;
  strongholdsDestroyed = 0;
  GHighScoreSaved = 0;
  GPromotableCount = 0;
  GPopulationHi = 0;
  GPopulationLo = 0;
  GGameInProgress = 0;
  GSeason = 0;
  GTimeLo = 0;
  if (2 < Difficulty) {
    PlayerCount = 2;
  }
  GYear = 0;
  ListCount = 0;
  strongholdCheckPending = 0;
  handle.seg = Lbm_nwpanel1.seg;
  handle.ofs = Lbm_nwpanel1.ofs;
  srcOfs = ovr_stshLoadGfx(handle);
  ovr_calcSeasonPalette(srcOfs->cmap,uVar1,palette,unaff_SS);
  if (GameRunning == false) {
    ovr_vgaSetPalette8bit(palette);
  }
  ovr_manage_mapPartySlots();
  return;
}



/* 3381:233e */

/* Returns the GMapCells[y][x] byte inside the map bounds, else 0. */

uint __cdecl16far init_getMapCell(int x,int y,...)

{
  uint in_AX;
  uint uVar1;
  
  if ((((x < 0x94) && (-1 < x)) && (y < 0x3c)) && (-1 < y)) {
    uVar1 = CONCAT11((char)((uint)(y * 0x94) >> 8),(*(byte (*) [59] [148])GMapCells)[y][x]);
  }
  else {
    uVar1 = in_AX & 0xff00;
  }
  return uVar1;
}



/* 3381:237a */

/* Writes a byte into GMapCells[y][x] after the map bounds check. */

void __cdecl16far init_setMapCell(int x,int y,byte cell,...)

{
  if ((((x < 0x94) && (-1 < x)) && (y < 0x3c)) && (-1 < y)) {
    (*(byte (*) [59] [148])GMapCells)[y][x] = cell;
  }
  return;
}



/* 3381:23b5 */

/* Returns the flag bits of GMapFlags[y][x] inside the map bounds, else 0. */

uint __cdecl16far init_getMapFlags(int x,int y,...)

{
  uint in_AX;
  uint uVar1;
  
  if ((((x < 0x94) && (-1 < x)) && (y < 0x3c)) && (-1 < y)) {
    uVar1 = CONCAT11((char)((uint)(x * 2) >> 8),(char)(*(short (*) [60] [148])GMapFlags)[y][x]) &
            0xff03;
  }
  else {
    uVar1 = in_AX & 0xff00;
  }
  return uVar1;
}



/* 3381:23f9 */

/* Sums the four GMapCells bytes of the 2x2 block at (x,y). */

int __cdecl16far init_sumMapCells2x2(int x,int y)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = init_getMapCell(x,y);
  uVar1 = uVar1 & 0xff;
  uVar2 = init_getMapCell(x + 1,y);
  iVar3 = uVar1 + (uVar2 & 0xff);
  uVar1 = init_getMapCell(x,y + 1);
  iVar3 = iVar3 + (uVar1 & 0xff);
  uVar1 = init_getMapCell(x + 1,y + 1);
  return iVar3 + (uVar1 & 0xff);
}



/* 3381:2452 */

/* [R7] body shape: compute */

undefined2 __cdecl16far init_compute2(int x,int y,byte direction)

{
  uint in_AX;
  byte bStack_3;
  
  bStack_3 = 0;
  while( true ) {
    if (3 < bStack_3) {
      return CONCAT11((char)(in_AX >> 8),1);
    }
    in_AX = (uint)bStack_3;
    if ((in_AX != (direction ^ 2)) &&
       (in_AX = init_getMapFlags(x + *(char *)(bStack_3 + 0x885),y + *(char *)(bStack_3 + 0x889)),
       (char)in_AX != '\0')) break;
    bStack_3 = bStack_3 + 1;
  }
  return in_AX & 0xff00;
}



/* 3381:24c3 */

/* [R4] calls ovr_randBelow */

uint16_t __cdecl16far
init_usesRandBelow(int16_t x,int16_t y,uint8_t dir,uint8_t *lastDir,uint8_t *sameDirCount,...)

{
  uint8_t uVar1;
  byte bVar2;
  int iVar3;
  uint16_t uVar4;
  undefined1 uVar7;
  uint uVar5;
  uint uVar6;
  undefined2 in_stack_00000010;
  uint uStack_e;
  uint uStack_c;
  byte bStack_8;
  byte bStack_7;
  byte bStack_6;
  byte bStack_5;
  byte bStack_3;
  
  iVar3 = init_sumMapCells2x2(x,y);
  uStack_e = iVar3 + 0x14;
  bStack_6 = 0xff;
  bStack_5 = 0xff;
  bStack_7 = 0xff;
  bStack_8 = 0xff;
  uVar4 = ovr_randBelow(4);
  uVar7 = (undefined1)(uVar4 >> 8);
  uStack_c = uStack_e;
  bStack_3 = (byte)uVar4;
  do {
    uVar6 = CONCAT11(uVar7,bStack_3 - dir) & 0xff03;
    uVar1 = (uint8_t)uVar6;
    if ((uVar1 != 0x2) &&
       ((*(byte *)CONCAT22(in_stack_00000010,(*(uint16_t *)((uint8_t *)&(sameDirCount) + 2))) < 2 ||
        (uVar6 = CONCAT11((char)(uVar6 >> 8),*(uint8_t *)CONCAT22((uint8_t *)sameDirCount,lastDir)),
        *(uint8_t *)CONCAT22((uint8_t *)sameDirCount,lastDir) != uVar1)))) {
      bStack_8 = bStack_3;
      uVar5 = init_sumMapCells2x2(x + *(char *)(bStack_3 + 0x885),y + *(char *)(bStack_3 + 0x889));
      if (uVar5 <= uStack_c) {
        bStack_5 = bStack_3;
        uStack_c = uVar5;
      }
      uVar6 = init_compute2(x + *(char *)(bStack_3 + 0x885),y + *(char *)(bStack_3 + 0x889),bStack_3
                           );
      uVar7 = (undefined1)(uVar6 >> 8);
      if ((char)uVar6 != '\0') {
        uVar6 = CONCAT11(uVar7,bStack_3);
        bStack_7 = bStack_3;
        if (uVar5 <= uStack_e) {
          uVar6 = CONCAT11(uVar7,bStack_3);
          bStack_6 = bStack_3;
          uStack_e = uVar5;
        }
      }
    }
    uVar6 = CONCAT11((char)(uVar6 >> 8),bStack_3 + 1) & 0xff03;
    bStack_3 = (byte)uVar6;
    uVar7 = (undefined1)(uVar6 >> 8);
  } while (bStack_3 != (byte)uVar4);
  if (bStack_6 == 0xff) {
    if (bStack_7 == 0xff) {
      if (bStack_5 == 0xff) {
        bStack_3 = bStack_8;
      }
      else {
        bStack_3 = bStack_5;
      }
    }
    else {
      bStack_3 = bStack_7;
    }
  }
  else {
    bStack_3 = bStack_6;
  }
  bVar2 = bStack_3 - dir & 3;
  if (bVar2 != 0) {
    if (*(byte *)CONCAT22((uint8_t *)sameDirCount,lastDir) == bVar2) {
      *(byte *)CONCAT22(in_stack_00000010,(*(uint16_t *)((uint8_t *)&(sameDirCount) + 2))) =
           *(byte *)CONCAT22(in_stack_00000010,(*(uint16_t *)((uint8_t *)&(sameDirCount) + 2))) + 1;
    }
    else {
      *(byte *)CONCAT22(in_stack_00000010,(*(uint16_t *)((uint8_t *)&(sameDirCount) + 2))) = 0;
      *(byte *)CONCAT22((uint8_t *)sameDirCount,lastDir) = bVar2;
    }
  }
  return CONCAT11(uVar7,bStack_3);
}



/* 3381:2651 */

/* [R6] touches GMapFlags, GMapCells */

void __cdecl16far init_usesGMapFlags3(int x,int y)

{
  uint *puVar1;
  short (*paasVar2) [60] [148];
  byte (*paabVar3) [59] [148];
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)GMapFlags >> 0x10);
  paasVar2 = (short (*) [60] [148])GMapFlags;
  if (((*paasVar2)[y][x] & 4U) == 0) {
    if ((((*(byte (*) [59] [148])GMapCells)[y][x] == 0) &&
        ((*(byte (*) [59] [148])GMapCells)[y + 1][x + 1] == 0)) &&
       ((*(byte (*) [59] [148])GMapCells)[y + 1][x] == 0)) {
      puVar1 = (uint *)((*paasVar2)[y] + x);
      *puVar1 = *puVar1 | 1;
    }
    uVar4 = (undefined2)((ulong)GMapCells >> 0x10);
    paabVar3 = (byte (*) [59] [148])GMapCells;
    if ((((*paabVar3)[y][x] == 0) && ((*paabVar3)[y + 1][x + 1] == 0)) &&
       ((*paabVar3)[y][x + 1] == 0)) {
      puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[y] + x);
      *puVar1 = *puVar1 | 2;
    }
  }
  else {
    if ((((*(byte (*) [59] [148])GMapCells)[y + 1][x] == 0) &&
        ((*(byte (*) [59] [148])GMapCells)[y][x + 1] == 0)) &&
       ((*(byte (*) [59] [148])GMapCells)[y][x] == 0)) {
      puVar1 = (uint *)((*paasVar2)[y] + x);
      *puVar1 = *puVar1 | 1;
    }
    if ((((*(byte (*) [59] [148])GMapCells)[y + 1][x] == 0) &&
        ((*(byte (*) [59] [148])GMapCells)[y][x + 1] == 0)) &&
       ((*(byte (*) [59] [148])GMapCells)[y + 1][x + 1] == 0)) {
      puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[y] + x);
      *puVar1 = *puVar1 | 2;
    }
  }
  return;
}



/* 3381:2883 */

/* [R4] calls ovr_randBelow */

void __cdecl16far init_usesRandBelow2(void)

{
  uint *puVar1;
  far_t dst;
  far_t dst_00;
  uint16_t uVar2;
  uint uVar3;
  int iVar4;
  byte (*paabVar5) [59] [148];
  short (*paasVar6) [60] [148];
  uint x;
  uint y;
  undefined2 uVar7;
  uint8_t *unaff_SS;
  undefined1 uVar8;
  uint8_t edgeMasks;
  byte bStack_14;
  byte bStack_13;
  int iStack_12;
  uint8_t sameDirCount;
  uint8_t lastDir;
  byte bStack_d;
  byte bStack_c;
  byte bStack_b;
  uint8_t neighbourOfs;
  byte abStack_9 [7];
  
  uVar8 = (undefined1)((uint)unaff_SS >> 8);
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = (char)unaff_SS;
  dst.ofs = (uint16_t)&edgeMasks;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = uVar8;
  F_SCOPY(far_from_u32((uint32_t)(0x241004f2)),dst);
  (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = (char)unaff_SS;
  dst_00.ofs = (uint16_t)&neighbourOfs;
  (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = uVar8;
  F_SCOPY(far_from_u32((uint32_t)(0x24100502)),dst_00);
  iStack_12 = 0;
  do {
    if ((int)(uint)randomFeatureCount <= iStack_12) {
      return;
    }
    uVar2 = ovr_randBelow(0x93);
    x = uVar2 & 0xff;
    uVar2 = ovr_randBelow(0x3b);
    y = uVar2 & 0xff;
    bStack_b = 100;
    uVar3 = init_getMapCell(x,uVar2 & 0xff,(char)uVar2);
    bStack_c = (byte)uVar3;
    if (bStack_c < bStack_b) {
      bStack_b = bStack_c;
    }
    uVar3 = init_getMapCell(x + 1,uVar2 & 0xff,(char)uVar2);
    bStack_c = (byte)uVar3;
    if (bStack_c < bStack_b) {
      bStack_b = bStack_c;
    }
    uVar3 = init_getMapCell(x,y + 1,(char)(y + 1));
    bStack_c = (byte)uVar3;
    if (bStack_c < bStack_b) {
      bStack_b = bStack_c;
    }
    uVar3 = init_getMapCell(x + 1,y + 1,(char)(y + 1));
    bStack_c = (byte)uVar3;
    if (bStack_c < bStack_b) {
      bStack_b = bStack_c;
    }
    init_setMapCell(x,y,bStack_b);
    init_setMapCell(x + 1,y,bStack_b);
    init_setMapCell(x,y + 1,bStack_b);
    init_setMapCell(x + 1,y + 1,bStack_b);
    if (bStack_b == 0) {
      init_usesGMapFlags3(x,uVar2 & 0xff);
      init_usesGMapFlags3(x - 1,uVar2 & 0xff);
      init_usesGMapFlags3(x + 1,uVar2 & 0xff);
      init_usesGMapFlags3(x,y - 1);
      init_usesGMapFlags3(x,y + 1);
    }
    lastDir = 0x0;
    sameDirCount = 0x0;
    uVar2 = ovr_randBelow(4);
    bStack_13 = (byte)uVar2;
    for (; ((((int)x < 0x93 && (-1 < (int)x)) && ((int)y < 0x3b)) && (-1 < (int)y));
        y = y + (int)*(char *)(bStack_14 + 0x889)) {
      uVar7 = (undefined2)((ulong)GMapCells >> 0x10);
      paabVar5 = (byte (*) [59] [148])GMapCells;
      if ((((*paabVar5)[y][x] == 0) && ((*paabVar5)[y][x + 1] == 0)) &&
         (((*paabVar5)[y + 1][x] == 0 && ((*paabVar5)[y + 1][x + 1] == 0)))) break;
      uVar7 = (undefined2)((ulong)GMapFlags >> 0x10);
      paasVar6 = (short (*) [60] [148])GMapFlags;
      if (((*paasVar6)[y][x] & 3U) == 3) break;
      if (((*paasVar6)[y][x] & 3U) != 0) {
        puVar1 = (uint *)((*paasVar6)[y] + x);
        *puVar1 = *puVar1 | 3;
      }
      uVar2 = init_usesRandBelow(x,y,bStack_13,&lastDir,(uint8_t *)CONCAT22(&sameDirCount,unaff_SS))
      ;
      bStack_14 = (byte)uVar2;
      if (((bStack_14 == 0xff) || (bStack_13 == (bStack_14 ^ 2))) ||
         ((&edgeMasks)[(uint)bStack_13 * 4 + (uVar2 & 0xff)] == 0x0)) break;
      puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[y] + x);
      *puVar1 = *puVar1 & 0xfffb;
      puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[y] + x);
      *puVar1 = *puVar1 | (uint)(&edgeMasks)[(uint)bStack_13 * 4 + (uVar2 & 0xff)];
      iVar4 = y + ((int)(uint)abStack_9[(uint)bStack_13 * 2 + -1] >> 1);
      uVar3 = init_getMapCell(x + (abStack_9[(uint)bStack_13 * 2 + -1] & 1),iVar4,(char)iVar4);
      bStack_c = (byte)uVar3;
      iVar4 = y + ((int)(uint)abStack_9[(uint)bStack_13 * 2] >> 1);
      uVar3 = init_getMapCell(x + (abStack_9[(uint)bStack_13 * 2] & 1),iVar4,(char)iVar4);
      bStack_d = (byte)uVar3;
      if (bStack_c < bStack_b) {
        bStack_b = bStack_c;
      }
      if (bStack_d < bStack_b) {
        bStack_b = bStack_d;
      }
      init_setMapCell(x + (abStack_9[(uint)bStack_14 * 2 + -1] & 1),
                      y + ((int)(uint)abStack_9[(uint)bStack_14 * 2 + -1] >> 1),bStack_b);
      init_setMapCell(x + (abStack_9[(uint)bStack_14 * 2] & 1),
                      y + ((int)(uint)abStack_9[(uint)bStack_14 * 2] >> 1),bStack_b);
      if (bStack_b == 0) {
        init_usesGMapFlags3(x,y);
        init_usesGMapFlags3(x - 1,y);
        init_usesGMapFlags3(x + 1,y);
        init_usesGMapFlags3(x,y - 1);
        init_usesGMapFlags3(x,y + 1);
      }
      x = x + (int)*(char *)(bStack_14 + 0x885);
      bStack_13 = bStack_14;
    }
    iStack_12 = iStack_12 + 1;
  } while( true );
}



/* 3381:2d36 */

/* Rebuilds the four direction bits for every map cell. */

void __cdecl16far init_rebuildAllDirectionFlags(void)

{
  uint *puVar1;
  uint *puVar2;
  uint16_t unitIndex;
  int x;
  byte bStack_3;
  
  for (x = 0; x < 0x94; x = x + 1) {
    for (unitIndex = 0; (int)unitIndex < 0x3c; unitIndex = unitIndex + 1) {
      for (bStack_3 = 0; bStack_3 < 4; bStack_3 = bStack_3 + 1) {
        puVar2 = ovr_ovc23_usesAlignUp43(x,unitIndex,bStack_3);
        if ((char)puVar2 != '\0') {
          puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[unitIndex] + x);
          *puVar1 = *puVar1 | 0x10 << (bStack_3 & 0x1f);
        }
      }
    }
  }
  return;
}



/* 3381:2d9e */

void __cdecl16far init_grayscale_palette(void)

{
  stg_tmp_t *psVar1;
  uint16_t max_c;
  uint16_t in_DX;
  uint16_t i;
  uint16_t unaff_SS;
  far_t dst;
  far_t handle;
  char buf [12];
  stg_tmp_t *pgfx;
  uint32_t gfx;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)buf;
  F_SCOPY(far_from_u32((uint32_t)(0x2410050e)),dst);
  if (GrayscalePalette.ofs == 0 && GrayscalePalette.seg == 0) {
    GrayscalePalette.ofs = (uint16_t)ovr_stshAlloc(0x100);
    GrayscalePalette.seg = in_DX;
  }
  handle.seg = Lbm_nwpanel1.seg;
  handle.ofs = Lbm_nwpanel1.ofs;
  psVar1 = ovr_stshLoadGfx(handle);
  *(undefined1 far *)MK_FP(GrayscalePalette.seg, GrayscalePalette.ofs) = 0;
  for (i = 1; (int)i < 0x100; i = i + 1) {
    max_c = (uint16_t)psVar1->cmap[i * 3];
    if (max_c < psVar1->cmap[i * 3 + 1]) {
      max_c = (uint16_t)psVar1->cmap[i * 3 + 1];
    }
    if (max_c < psVar1->cmap[i * 3 + 2]) {
      max_c = (uint16_t)psVar1->cmap[i * 3 + 2];
    }
    *(char far *)((uint8_t far *)MK_FP(GrayscalePalette.seg, GrayscalePalette.ofs) +  i) = buf[max_c * 0xb >> 6];
  }
  return;
}



/* 3381:2e9a */

/* Lowercases a name in place and removes its spaces. */

void __cdecl16far init_normalizeName(uint32_t s)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (s != 0) {
    iVar3 = 0;
    for (iVar2 = 0; *(char *)((int)s + iVar2) != '\0'; iVar2 = iVar2 + 1) {
      if (*(char *)((int)s + iVar2) != ' ') {
        uVar1 = tolower((int)*(char *)((int)s + iVar2));
        *(undefined1 *)((int)s + iVar3) = (char)uVar1;
        iVar3 = iVar3 + 1;
      }
    }
    *(undefined1 *)((int)s + iVar3) = 0;
  }
  return;
}



/* 3381:2ee2 */
void __cdecl16far copyProtectionCheck(void)

{
  uint16_t uVar1;
  char *pcVar2;
  byte *in_DX;
  char *unaff_SS;
  uint16_t uVar3;
  uint8_t uVar4;
  far_t handle;
  uint8_t msg;
  uint16_t input;
  byte *pbStack_a;
  char *uStack_8;   /* hand fix: *uStack_8 deref */
  uint8_t attempts;
  uint8_t codes;
  
  if (CopyProtectionDone == '\0') {
    uVar1 = ovr_randBelow(0x19);
    codes = (uint8_t)uVar1;
    attempts = 0x0;
    while( true ) {
      if (3 < attempts) {
        if (SaveAuto != '\0') {
          ovr_stSave();
        }
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0);
      }
      ovr_saveui_blitPanel();
      TextBlitX = 0x16;
      TextBlitY = 0xc;
      ovr_blitText((char *)"Stronghold copy protection.",
                   (byte *)CONCAT22(Font03.ofs,(char *)0x26510),Font03.seg,0xde);
      TextBlitX = 0x16;
      TextBlitY = 0x2f;
      uVar4 = 0xde;
      uVar1 = Font03.ofs;
      uVar3 = Font03.seg;
      pcVar2 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x6cd,unaff_SS),
                             (char *)(ulong)CONCAT12(*(undefined1 *)(codes + 0x51a),0x2410));
      ovr_blitText(pcVar2,(byte *)CONCAT22(uVar1,in_DX),uVar3,uVar4);
      TextBlitX = 0x16;
      TextBlitY = 0x43;
      uVar4 = 0xde;
      uVar1 = Font03.ofs;
      uVar3 = Font03.seg;
      pcVar2 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x6ed,unaff_SS),
                             (char *)(ulong)CONCAT12(*(undefined1 *)(codes + 0x533),0x2410));
      ovr_blitText(pcVar2,(byte *)CONCAT22(uVar1,in_DX),uVar3,uVar4);
      TextBlitX = 0x16;
      TextBlitY = 0x57;
      ovr_blitText((char *)"Enter the first word.",
                   (byte *)CONCAT22(Font03.ofs,(char *)0x26510),Font03.seg,0xde);
      pbStack_a = (byte *)0x0;
      input = 0;
      pcVar2 = ovr_stshAlloc(2);
      uStack_8 = (char *)CONCAT22(in_DX,pcVar2);
      *uStack_8 = *(char *)*(undefined4 *)((uint)codes * 4 + 0x54c);
      pcVar2[1] = '\0';
      input = (uint16_t)ovr_uiReadString((char *)0x0,0,6,pcVar2,(uint16_t)in_DX);
      pbStack_a = in_DX;
      init_normalizeName((uint32_t)CONCAT22(in_DX,input));
      if (UserWantsExit != '\0') {
        if (SaveAuto != '\0') {
          ovr_stSave();
        }
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0);
      }
      if (input != 0 || pbStack_a != (byte *)0x0) break;
      attempts = attempts + 0x1;
    }
    _fstricmp((char *)CONCAT22(pbStack_a,input),
              (char *)CONCAT22(*(undefined2 *)((uint)codes * 4 + 0x54e),
                               (char *)*(undefined2 *)((uint)codes * 4 + 0x54c)));
    handle.seg = (uint16_t)pbStack_a;
    handle.ofs = input;
    ovr_stshFree(handle);
    ovr_saveui_blitPanel();
    CopyProtectionDone = '\x01';
  }
  return;
}

