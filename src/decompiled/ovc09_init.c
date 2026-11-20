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
  
  strcpy((char *)&GStaticBuffer,(char *)"puppetmaker" + 3);
  for (l = strlen((char *)&GStaticBuffer);
      (0 < (int)l && (((undefined1 *)&randomFeatureCount)[l] != '\\')); l = l - 1) {
  }
  ((undefined *)&GStaticBuffer)[l] = 0;
  strcat((char *)&GStaticBuffer,(char *)"puppetmaker" + 3);
  return (char *)&GStaticBuffer;
}



/* 3381:00fe */

char * __cdecl16far path_strip_tail_slash(char *s)

{
  uint16_t l;
  undefined2 in_stack_00000006;
  
  l = strlen(s);
  if ((3 < (int)l) && (s[l - 1] == '\\')) {
    s[l - 1] = '\0';
  }
  return s;
}



/* 3381:0132 */

char * __cdecl16far ensure_tail_slash(char *s)

{
  uint16_t l;
  undefined2 in_stack_00000006;
  
  l = strlen(s);
  if ((l == 0) || (s[l - 1] != '\\')) {
    s[l] = '\\';
    s[l + 1] = '\0';
  }
  return s;
}



/* 3381:016c */

/* chdir doesn't change the disk, so we have to do that */

void __cdecl16far chpath(char *path)

{
  uint8_t c;
  char cVar1;
  int iVar2;
  undefined1 extraout_AH;
  undefined2 in_stack_00000006;
  
  iVar2 = chdir(path);
  if (iVar2 == 0) {
    c = toupper(*_path);
    if (((path[1] == ':') && ('@' < (char)c)) && ((char)c < '[')) {
      cVar1 = toupper(c);
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
  
  getcwd((char *)GOriginalDir,0x2410);
  strcpy((char *)&GWorkDir,(char *)"puppetmaker" + 3);
  ensure_tail_slash((char *)&GWorkDir);
  strcat((char *)&GWorkDir,(char *)"puppetmaker" + 3);
  full_path = (uint16_t)append_name_to_path((char *)GGameExe.ofs,(char *)GGameExe.seg);
  p = (uint16_t)path_strip_tail_slash((char *)full_path);
  chpath((char *)p);
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
  char *unaff_SS;
  char lbuf [80];
  uint8_t goterr;
  uint8_t update;
  uint16_t crlf;
  char mice;
  uint8_t c;
  
  crlf = GCrLf;
  bVar1 = false;
  cfgPath = (uint16_t)ovr_stsprintf(lbuf,unaff_SS,(char *)"%sgame.cfg");
  fh = ovr_open_wait_unlock_and_disk((char *)cfgPath);
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
    uVar2 = toupper(c);
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
    uVar2 = toupper(c);
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
    path = ovr_stsprintf(lbuf,unaff_SS,(char *)"%sgame.cfg");
    iVar3 = ovr_creat_wait_unlock_and_disk(path);
    if (iVar3 < 0) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x83);
    }
    write(iVar3,(char *)&CFG_Sfx,0x2410);
    write(iVar3,&crlf,(uint16_t)unaff_SS);
    write(iVar3,(char *)&CFG_Mus,0x2410);
    write(iVar3,&crlf,(uint16_t)unaff_SS);
    iVar4 = write(iVar3,(char *)&CFG_Irq,0x2410);
    iVar5 = write(iVar3,&crlf,(uint16_t)unaff_SS);
    iVar6 = write(iVar3,&mice,(uint16_t)unaff_SS);
    iVar7 = write(iVar3,&crlf,(uint16_t)unaff_SS);
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
  srand8(CONCAT22(*(undefined2 *)(BDA_DailyTimeCounter.ofs + 2),*(undefined2 *)BDA_DailyTimeCounter)
        );
  ovr_stshAlloc(0xfa0f);
  iVar1 = strcmp((char *)GExeArg.ofs,(char *)GExeArg.seg);
  if (iVar1 == 0) {
    GDebug = true;
  }
  iVar1 = strcmp((char *)GExeArg.ofs,(char *)GExeArg.seg);
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

/* WARNING: Instruction at (ram,0x00039a04) overlaps instruction at (ram,0x00039a03)
    */
/* WARNING: Control flow encountered bad instruction data */
/* [R2] string "Filename %d %s  \r" */

stg_tmp_t * __cdecl16far init_textFilename(void)

{
  uint16_t uVar1;
  far_t gfx;
  far_t src;
  far_t gfx_00;
  far_t src_00;
  far_t dst;
  far_t handle;
  far_t handle_00;
  ulong uVar2;
  char cVar3;
  byte bVar4;
  uint32_t *puVar5;
  uint32_t *puVar6;
  uint16_t uVar7;
  uint uVar8;
  stg_tmp_t *psVar9;
  undefined1 extraout_AH;
  int in_CX;
  word extraout_DX;
  word wVar10;
  word wVar11;
  uint uVar12;
  uint uVar13;
  byte (*paabVar14) [59] [148];
  short (*paasVar15) [148] [60];
  uint16_t unaff_SI;
  int iVar16;
  int iVar17;
  byte unaff_DI;
  uint uVar18;
  uint32_t *__return_storage_ptr__;
  undefined2 uVar19;
  undefined2 unaff_SS;
  bool bVar20;
  longdouble in_ST0;
  int iStack0004;
  int16_t iStack0006;
  int16_t in_stack_00000008;
  byte abStackY_348 [488];
  undefined1 auStackY_160 [158];
  undefined2 uStackY_c2;
  undefined2 uStackY_c0;
  undefined1 uVar21;
  undefined2 in_stack_0000ff5c;
  uint16_t uStack_48;
  uint16_t uStack_46;
  uint8_t uStack_40;
  uint8_t uStack_3f;
  int8_t iStack_3e;
  uint16_t uStack_32;
  far_t fStack_30;
  char cStack_2c;
  byte bStack_2b;
  uint32_t *puStack_2a;
  char cStack_28;
  uint32_t *puStack_26;
  word wStack_24;
  word wStack_22;
  uint uStack_20;
  void *pvStack_1e;
  uint32_t *puStack_1c;
  byte *pbStack_18;
  word wStack_16;
  uint uStack_14;
  word wStack_12;
  undefined2 uStack_10;
  uint16_t uStack_e;
  uint uStack_c;
  uint uStack_a;
  uint uStack_8;
  int iStack_6;
  byte bStack_3;
  
  uStack_10 = (uint)(byte)uStack_10;
  for (iVar16 = 0; iVar16 < 0x94; iVar16 = iVar16 + 1) {
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
    if ((iVar16 == 0) || (iVar16 == 0x93)) {
      uStack_10 = uStack_10 & 0xff;
    }
    (&stack0xff5c)[iVar16] = (*(uint8_t *)((uint8_t *)&(uStack_10) + 1));
  }
  uStack_c = 0;
  uStack_a = 0;
  _fsetmem((short (*) [148] [60])GUnitGrid,(*(uint16_t *)((uint8_t *)&(GUnitGrid) + 2)),0x4560);
  psVar9 = (stg_tmp_t *)((char *)"puppetmaker" + 3);
  _fsetmem((short (*) [60] [148])GMapFlags,(*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)),0x4560);
  for (uVar18 = 0; (int)uVar18 < 0x3c; uVar18 = uVar18 + 1) {
    if ((uVar18 & 1) == 0) {
      for (iVar16 = 0; iVar16 < 0x94; iVar16 = iVar16 + 1) {
        uStack_c = 0;
        if (iVar16 != 0) {
          uStack_c = (int)(char)((byte (*) [59] [148])GMapCells)[-1][uVar18 + 0x3a][iVar16 + 0x93];
        }
        if (uVar18 != 0) {
          uStack_c = uStack_c +
                     (int)(char)((byte (*) [59] [148])GMapCells)[-1][uVar18 + 0x3a]
                                [(char)(&stack0xff5c)[iVar16] + iVar16];
        }
        uStack_c = (int)uStack_c >> 1;
        if ((iVar16 != 0) && ((&stack0xff5b)[iVar16] != (&stack0xff5c)[iVar16])) {
          uVar7 = ovr_randBelow(8);
          uStack_8 = uVar7 & 0xff;
          if (uStack_8 == 1) {
            (&stack0xff5c)[iVar16] = (&stack0xff5b)[iVar16];
          }
          else if (uStack_8 == 2) {
            (&stack0xff5b)[iVar16] = (&stack0xff5c)[iVar16];
          }
        }
        uVar7 = ovr_randBelow(0x10);
        if ((uVar7 & 0xff) == 0) {
          if (iVar16 != 0) {
            (*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) = (&stack0xff5b)[iVar16];
            uVar7 = ovr_randBelow(2);
            cVar3 = (char)uVar7 * '\x02' + (*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) + -1;
            uStack_10 = CONCAT11(cVar3,(byte)uStack_10);
            if (cVar3 < -1) {
              uStack_10 = CONCAT11(0xff,(byte)uStack_10);
            }
            if ('\x01' < (*(uint8_t *)((uint8_t *)&(uStack_10) + 1))) {
              uStack_10 = CONCAT11(1,(byte)uStack_10);
            }
            (&stack0xff5c)[iVar16] = (*(uint8_t *)((uint8_t *)&(uStack_10) + 1));
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
        psVar9 = (stg_tmp_t *)CONCAT11((char)(uVar18 * 0x94 >> 8),(byte)uStack_c);
        (*(byte (*) [59] [148])GMapCells)[uVar18][iVar16] = (byte)uStack_c;
      }
    }
    else {
      for (iVar16 = 0x93; -1 < iVar16; iVar16 = iVar16 + -1) {
        uStack_c = 0;
        if (iVar16 != 0x93) {
          uStack_c = (int)(char)(*(byte (*) [59] [148])GMapCells)[uVar18][iVar16 + 1];
        }
        if (uVar18 != 0) {
          uStack_c = uStack_c +
                     (int)(char)((byte (*) [59] [148])GMapCells)[-1][uVar18 + 0x3a]
                                [(char)(&stack0xff5c)[iVar16] + iVar16];
        }
        uStack_c = (int)uStack_c >> 1;
        if ((iVar16 != 0x93) && ((&stack0xff5d)[iVar16] != (&stack0xff5c)[iVar16])) {
          uVar7 = ovr_randBelow(0x10);
          uStack_8 = uVar7 & 0xff;
          if (uStack_8 == 1) {
            (&stack0xff5c)[iVar16] = (&stack0xff5d)[iVar16];
          }
          else if (uStack_8 == 2) {
            (&stack0xff5d)[iVar16] = (&stack0xff5c)[iVar16];
          }
        }
        uVar7 = ovr_randBelow(0x10);
        if ((uVar7 & 0xff) == 0) {
          if (iVar16 != 0x93) {
            (*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) = (&stack0xff5d)[iVar16];
            uVar7 = ovr_randBelow(2);
            cVar3 = (char)uVar7 * '\x02' + (*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) + -1;
            uStack_10 = CONCAT11(cVar3,(byte)uStack_10);
            if (cVar3 < -1) {
              uStack_10 = CONCAT11(0xff,(byte)uStack_10);
            }
            if ('\x01' < (*(uint8_t *)((uint8_t *)&(uStack_10) + 1))) {
              uStack_10 = CONCAT11(1,(byte)uStack_10);
            }
            (&stack0xff5c)[iVar16] = (*(uint8_t *)((uint8_t *)&(uStack_10) + 1));
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
        psVar9 = (stg_tmp_t *)CONCAT11((char)(uVar18 * 0x94 >> 8),(byte)uStack_c);
        (*(byte (*) [59] [148])GMapCells)[uVar18][iVar16] = (byte)uStack_c;
      }
    }
  }
  for (iVar16 = 0; iVar16 < 0x3c; iVar16 = iVar16 + 1) {
    for (iVar17 = 0; iVar17 < 0x94; iVar17 = iVar17 + 1) {
      uVar19 = (undefined2)((ulong)GMapCells >> 0x10);
      if ((char)(*(byte (*) [59] [148])GMapCells)[iVar16][iVar17] < '\0') {
        (*(byte (*) [59] [148])GMapCells)[iVar16][iVar17] = 0;
      }
      psVar9 = (stg_tmp_t *)(iVar16 * 0x94);
      if ((iVar17 != 0x93) && (iVar16 != 0x3c)) {
        uVar19 = (undefined2)((ulong)GMapCells >> 0x10);
        paabVar14 = (byte (*) [59] [148])GMapCells;
        uVar18 = (int)(char)(*paabVar14)[iVar16 + 1][iVar17] -
                 (int)(char)(*paabVar14)[iVar16][iVar17 + 1];
        uVar12 = (int)uVar18 >> 0xf;
        uVar8 = (int)(char)(*paabVar14)[iVar16][iVar17] -
                (int)(char)(*paabVar14)[iVar16 + 1][iVar17 + 1];
        uVar13 = (int)uVar8 >> 0xf;
        psVar9 = (stg_tmp_t *)((uVar8 ^ uVar13) - uVar13);
        if ((int)((uVar18 ^ uVar12) - uVar12) < (int)psVar9) {
          psVar9 = (stg_tmp_t *)(iVar17 * 2);
          *(uint *)(psVar9->cmap + (int)(*(short (*) [60] [148])GMapFlags + iVar16)) =
               *(uint *)(psVar9->cmap + (int)(*(short (*) [60] [148])GMapFlags + iVar16)) | 4;
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
      for (iVar16 = 1; iVar16 < 0x3a; iVar16 = iVar16 + 1) {
        for (iVar17 = 1; iVar17 < 0x92; iVar17 = iVar17 + 1) {
          uVar7 = ovr_randBelow(2);
          psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
          if (psVar9 == (stg_tmp_t *)0x0) {
            psVar9 = (stg_tmp_t *)(iVar16 * 0x94);
            uVar19 = (undefined2)((ulong)GMapCells >> 0x10);
            paabVar14 = (byte (*) [59] [148])GMapCells;
            if ((((((psVar9->cmap[(int)(*paabVar14 + -1) + 0x93 + iVar17] != 0) &&
                   (psVar9 = (stg_tmp_t *)(*paabVar14 + iVar16), psVar9->cmap[iVar17 + 0x93] != 0))
                  && (psVar9 = (stg_tmp_t *)(iVar16 * 0x94),
                     psVar9->cmap[(int)((*paabVar14)[0] + iVar17)] != 0)) &&
                 ((psVar9 = (stg_tmp_t *)(*paabVar14 + iVar16), psVar9->cmap[iVar17 + 0x94] != 0 &&
                  (psVar9 = (stg_tmp_t *)(iVar16 * 0x94),
                  psVar9->cmap[(int)((*paabVar14)[0] + iVar17 + 1)] != 0)))) &&
                (psVar9 = (stg_tmp_t *)(*paabVar14 + iVar16), psVar9->cmap[iVar17 + 0x95] != 0)) &&
               (((bVar4 = (*paabVar14)[iVar16][iVar17],
                 psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar16 * 0x94) >> 8),bVar4),
                 (char)bVar4 <= (char)(*paabVar14)[iVar16][iVar17 + 1] &&
                 (bVar4 = (*paabVar14)[iVar16][iVar17],
                 psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar16 * 0x94) >> 8),bVar4),
                 (char)bVar4 <= (char)paabVar14[-1][iVar16 + 0x3a][iVar17 + 0x93])) &&
                ((bVar4 = (*paabVar14)[iVar16][iVar17],
                 psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar16 * 0x94) >> 8),bVar4),
                 (char)bVar4 <= (char)paabVar14[-1][iVar16 + 0x3a][iVar17] &&
                 (((bVar4 = (*paabVar14)[iVar16][iVar17 + 1],
                   psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar16 * 0x94) >> 8),bVar4),
                   (char)bVar4 <= (char)paabVar14[-1][iVar16 + 0x3a][iVar17 + 1] &&
                   (bVar4 = (*paabVar14)[iVar16][iVar17],
                   psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar16 * 0x94) >> 8),bVar4),
                   (char)bVar4 <= (char)(*paabVar14)[iVar16 + 1][iVar17])) &&
                  (bVar4 = (*paabVar14)[iVar16][iVar17 + 1],
                  psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar16 * 0x94) >> 8),bVar4),
                  (char)bVar4 <= (char)(*paabVar14)[iVar16 + 1][iVar17 + 1])))))))) {
              uVar18 = init_getMapFlags(iVar17,iVar16);
              psVar9 = (stg_tmp_t *)(uVar18 & 0xff);
              if (psVar9 == (stg_tmp_t *)0x0) {
                uVar18 = init_getMapFlags(iVar17 + -1,iVar16);
                psVar9 = (stg_tmp_t *)(uVar18 & 0xff);
                if ((psVar9 == (stg_tmp_t *)0x0) &&
                   (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags2(iVar17,iVar16),
                   (char)psVar9 == '\x02')) {
                  iStack_6 = ((short (*) [148] [60])GUnitGrid)[-1][iVar17 + 0x92][iVar16];
                  bStack_3 = ((unit_t *)GUnits + iStack_6)->bldType;
                  psVar9 = (stg_tmp_t *)((uint)bStack_3 * 0x27);
                  if ((psVar9->cmap[0x11b] < 2) &&
                     (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags2(iVar17,iVar16),
                     (byte)psVar9 < 3)) {
                    uVar7 = ovr_randBelow(5);
                    ((short (*) [148] [60])GUnitGrid)[-1][iVar17 + 0x93][iVar16] =
                         (uVar7 & 0xff) + 0x92;
                    uVar2 = (ulong)GUnitGrid >> 0x10;
                    paasVar15 = (short (*) [148] [60])GUnitGrid;
                    psVar9 = (stg_tmp_t *)(iVar16 * 2);
                    (psVar9->cmap + (int)(*paasVar15 + iVar17))[0] = 0;
                    (psVar9->cmap + (int)(*paasVar15 + iVar17))[1] = 0;
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
    for (iVar16 = 0; iVar16 < 0x93; iVar16 = iVar16 + 1) {
      psVar9 = (stg_tmp_t *)((int)__return_storage_ptr__ * 0x94);
      uVar19 = (undefined2)((ulong)GMapCells >> 0x10);
      paabVar14 = (byte (*) [59] [148])GMapCells;
      if (((psVar9->cmap[(int)((*paabVar14)[0] + iVar16)] != 0) &&
          (psVar9 = (stg_tmp_t *)((int)__return_storage_ptr__ * 0x94),
          psVar9->cmap[(int)((*paabVar14)[0] + iVar16 + 1)] != 0)) &&
         ((psVar9 = (stg_tmp_t *)(*paabVar14 + (int)__return_storage_ptr__),
          psVar9->cmap[iVar16 + 0x94] != 0 &&
          (psVar9 = (stg_tmp_t *)(*paabVar14 + (int)__return_storage_ptr__),
          psVar9->cmap[iVar16 + 0x94] != 0)))) {
        uVar18 = init_getMapFlags(iVar16,(int)__return_storage_ptr__);
        psVar9 = (stg_tmp_t *)(uVar18 & 0xff);
        if (psVar9 == (stg_tmp_t *)0x0) {
          uStack_c = (uint)(char)(*(byte (*) [59] [148])GMapCells)[(int)__return_storage_ptr__]
                                 [iVar16];
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
                      (*(short (*) [148] [60])GUnitGrid)[iVar16][(int)__return_storage_ptr__] =
                           (short)psVar9;
                    }
                    else if ((psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 3)) &&
                            (psVar9 = (stg_tmp_t *)
                                      ovr_constr_usesGMapFlags(iVar16,(int)__return_storage_ptr__),
                            (char)psVar9 != '\0')) {
                      uVar7 = ovr_randBelow(2);
                      psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
                      if (psVar9 == (stg_tmp_t *)0x0) {
                        uVar7 = ovr_randBelow(9);
                        psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
                        (*(short (*) [148] [60])GUnitGrid)[iVar16][(int)__return_storage_ptr__] =
                             (short)psVar9;
                      }
                    }
                  }
                  else {
                    uVar7 = ovr_randBelow(4);
                    psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
                    uVar21 = (undefined1)((uint)unaff_SS >> 8);
                    switch(psVar9) {
                    case (stg_tmp_t *)0x0:
                      func_0x000318f5();
                      wVar11 = extraout_DX;
                      goto L_grabLbm_0445;
                    case (stg_tmp_t *)0x1:
                      while( true ) {
                        pbStack_18 = psVar9->cmap + (int)pbStack_18;
                        psVar9 = (stg_tmp_t *)(iVar16 + (int)__return_storage_ptr__);
                        if ((int)puStack_1c <= (int)psVar9) {
                          psVar9 = memcpy((char *)CONCAT13((char)(wStack_12 >> 8),
                                                           CONCAT12((char)wStack_12,uStack_14)),
                                          (char *)CONCAT13(uVar21,CONCAT12((char)unaff_SS,
                                                                           auStackY_160 + uStack_c))
                                          ,uStack_e);
                          uStack_14 = uStack_14 + 0x140;
                        }
                        iVar16 = iVar16 + 1;
                        if (((int)uStack_10 <= iVar16) ||
                           (psVar9 = (stg_tmp_t *)(iVar16 + (int)__return_storage_ptr__),
                           (int)uStack_20 < (int)psVar9)) break;
                        (*(uint8_t *)((uint8_t *)&(src_00.seg))) = (char)wStack_16;
                        src_00.ofs = (uint16_t)pbStack_18;
                        (*(uint8_t *)((uint8_t *)&(src_00.seg) + 1)) = (char)(wStack_16 >> 8);
                        (*(uint8_t *)((uint8_t *)&(dst.seg))) = (char)unaff_SS;
                        dst.ofs = (uint16_t)auStackY_160;
                        (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = uVar21;
                        psVar9 = (stg_tmp_t *)ovr_unrle(src_00,dst,*(uint16_t *)(iStack0004 + 5));
                      }
                      return psVar9;
                    case (stg_tmp_t *)0x2:
                      *__return_storage_ptr__ = (long)in_ST0;
                    /* WARNING: Bad instruction - Truncating control flow here */
                      halt_baddata();
                    case (stg_tmp_t *)0x3:
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
                    (*(short (*) [148] [60])GUnitGrid)[iVar16][(int)__return_storage_ptr__] =
                         (short)psVar9;
                  }
                  else if ((psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 3)) &&
                          (psVar9 = (stg_tmp_t *)
                                    ovr_constr_usesGMapFlags(iVar16,(int)__return_storage_ptr__),
                          (char)psVar9 != '\0')) {
                    uVar7 = ovr_randBelow(9);
                    psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
                    (*(short (*) [148] [60])GUnitGrid)[iVar16][(int)__return_storage_ptr__] =
                         (short)psVar9;
                  }
                }
              }
              else {
                uVar7 = ovr_randBelow(4);
                psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
                if (((psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 3)) &&
                    (psVar9 = (stg_tmp_t *)
                              ovr_constr_usesGMapFlags(iVar16,(int)__return_storage_ptr__),
                    (char)psVar9 != '\0')) &&
                   (psVar9 = (stg_tmp_t *)ovr_randBelow(2), (char)psVar9 != '\0')) {
                  uVar7 = ovr_randBelow(9);
                  psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
                  (*(short (*) [148] [60])GUnitGrid)[iVar16][(int)__return_storage_ptr__] =
                       (short)psVar9;
                }
              }
            }
            else {
              uVar7 = ovr_randBelow(4);
              psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
              if (psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 1)) {
                psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(iVar16,(int)__return_storage_ptr__);
                if ((char)psVar9 != '\0') {
                  uVar7 = ovr_randBelow(2);
                  if ((uVar7 & 0xff) == 0) {
                    uVar7 = ovr_randBelow(6);
                    psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x3d);
                    (*(short (*) [148] [60])GUnitGrid)[iVar16][(int)__return_storage_ptr__] =
                         (short)psVar9;
                  }
                  else {
                    uVar7 = ovr_randBelow(9);
                    psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
                    (*(short (*) [148] [60])GUnitGrid)[iVar16][(int)__return_storage_ptr__] =
                         (short)psVar9;
                  }
                }
              }
              else if ((psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 3)) &&
                      (psVar9 = (stg_tmp_t *)
                                ovr_constr_usesGMapFlags(iVar16,(int)__return_storage_ptr__),
                      (char)psVar9 != '\0')) {
                uVar7 = ovr_randBelow(9);
                psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
                (*(short (*) [148] [60])GUnitGrid)[iVar16][(int)__return_storage_ptr__] =
                     (short)psVar9;
              }
            }
          }
          else {
            uVar7 = ovr_randBelow(4);
            psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
            if (((psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 2)) ||
                (psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 3))) &&
               (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(iVar16,(int)__return_storage_ptr__),
               (char)psVar9 != '\0')) {
              uVar7 = ovr_randBelow(9);
              psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
              (*(short (*) [148] [60])GUnitGrid)[iVar16][(int)__return_storage_ptr__] =
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
    *(int *)(&stack0xd744 + iVar16) = *(int *)(&stack0xd744 + iVar16) + in_CX;
    uVar8 = constr_compute2((uint8_t)uStack_20,(uint8_t)wStack_22,(uint8_t)puStack_1c,(byte)psVar9,
                            unaff_DI);
    ovr_ovc07_usesBiosReadKey
              (((uint16_t *)SquareLeftX)[(int)__return_storage_ptr__],RowScreenY[0] - uStack_10,
               ((uint16_t *)SquareRightX)[(int)__return_storage_ptr__],RowScreenY[0] - wStack_12,
               ((uint16_t *)SquareLeftX)[(int)__return_storage_ptr__],0x36,uVar8 & 0xff,
               (brect_t *)CONCAT22(unaff_SI,(brect_t *)((char *)"puppetmaker" + 3)));
    uVar18 = constr_compute2((uint8_t)puStack_1c,(uint8_t)pvStack_1e,(uint8_t)wStack_22,bStack_2b,2)
    ;
    ovr_ovc07_usesBiosReadKey
              (((uint16_t *)SquareRightX)[(int)__return_storage_ptr__],RowScreenY[0] - wStack_12,
               ((uint16_t *)SquareLeftX)[(int)__return_storage_ptr__],0x36,
               ((uint16_t *)SquareRightX)[(int)__return_storage_ptr__],0x36,uVar18 & 0xff,
               (brect_t *)CONCAT22(unaff_SI,(brect_t *)((char *)"puppetmaker" + 3)));
    while( true ) {
      uVar18 = constr_usesGMapFlags(wStack_24 + GfxRndSeed,GfxRndSeed2);
      if ((char)uVar18 != '\0') {
        cStack_28 = (char)uVar8;
        ovr_ovc07_usesLDIV_at_
                  (((uint16_t *)SquareLeftX)[(int)__return_storage_ptr__],RowScreenY[0] - uStack_10,
                   ((uint16_t *)SquareRightX)[(int)__return_storage_ptr__],RowScreenY[0] - wStack_12
                   ,cStack_28 + 0xff,
                   (brect_t *)CONCAT22(unaff_SI,(brect_t *)((char *)"puppetmaker" + 3)));
      }
      do {
        __return_storage_ptr__ = (uint32_t *)((int)__return_storage_ptr__ + 1);
        uVar7 = rowBandSquareFirst[0];
        if ((int)rowBandSquareEnd[0] <= (int)__return_storage_ptr__) {
          for (; (int)uVar7 < (int)rowBandSquareEnd[0]; uVar7 = uVar7 + 1) {
            uVar1 = ((uint16_t *)squareColumn)[uVar7];
            bVar4 = constr_setHighlightAtOffset(uVar1,0);
            uStack_e = CONCAT11(extraout_AH,bVar4);
            if ((*(byte *)(uStack_e * 0x27 + 0x11e) & 2) != 0) {
              iVar16 = constr_usesSmoothPrev(uVar1,-1,(int *)&uStack_20);
              uStack_10 = iVar16 / 3;
              gfx.seg = *(uint16_t *)
                         ((char *)
                          "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                          + 0x34 + uStack_e * 0xc);
              gfx.ofs = *(uint16_t *)
                         ((char *)
                          "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                          + 0x32 + uStack_e * 0xc);
              ovr_blit_usesBlitGfxN
                        (gfx,((uint16_t *)SquareLeftX)[uVar7],rowBandOrigin[0] - uStack_10,6,0x27,6,
                         (brect_t *)(BlitRects + 3),0x2410);
            }
            if ((*(byte *)(uStack_e * 0x27 + 0x11e) & 1) != 0) {
              gfx_00.seg = *(uint16_t *)
                            ((char *)
                             "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                             + 0x38 + uStack_e * 0xc);
              gfx_00.ofs = *(uint16_t *)
                            ((char *)
                             "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                             + 0x36 + uStack_e * 0xc);
              ovr_blitGfxRect(gfx_00,((uint16_t *)SquareLeftX)[uVar7],51,(brect_t *)(BlitRects + 3),
                              0x10,(*(uint8_t *)((uint8_t *)&(uStack_a))));
            }
          }
          return (stg_tmp_t *)((char *)"puppetmaker" + 3);
        }
      } while (((int)((uint16_t *)SquareRightX)[(int)__return_storage_ptr__] < 0xef) ||
              (0x134 < (int)((uint16_t *)SquareLeftX)[(int)__return_storage_ptr__]));
      wStack_24 = ((uint16_t *)squareColumn)[(int)__return_storage_ptr__];
      puStack_1c = (uint32_t *)constr_getCellAtOffset(wStack_24,-2);
      pvStack_1e = (void *)constr_getCellAtOffset(wStack_24 + 1,-2);
      iVar17 = constr_usesSmoothPrev(wStack_24,-1,(int *)&uStack_20);
      uStack_10 = iVar17 / 3;
      iVar17 = constr_usesSmoothPrev(wStack_24 + 1,-1,(int *)&wStack_22);
      wStack_12 = iVar17 / 3;
      psVar9 = (stg_tmp_t *)constr_getFlagsAtOffset(wStack_24,-1);
      bStack_2b = (byte)psVar9;
      if (((uint)psVar9 & 4) != 0) break;
      uVar8 = constr_compute2((uint8_t)uStack_20,(uint8_t)wStack_22,(uint8_t)pvStack_1e,bStack_2b,2)
      ;
      ovr_ovc07_usesBiosReadKey
                (((uint16_t *)SquareLeftX)[(int)__return_storage_ptr__],RowScreenY[0] - uStack_10,
                 ((uint16_t *)SquareRightX)[(int)__return_storage_ptr__],RowScreenY[0] - wStack_12,
                 ((uint16_t *)SquareRightX)[(int)__return_storage_ptr__],0x36,uVar8 & 0xff,
                 (brect_t *)CONCAT22(unaff_SI,(brect_t *)((char *)"puppetmaker" + 3)));
      uVar18 = constr_compute2((uint8_t)puStack_1c,(uint8_t)pvStack_1e,(uint8_t)uStack_20,bStack_2b,
                               1);
      ovr_ovc07_usesBiosReadKey
                (((uint16_t *)SquareLeftX)[(int)__return_storage_ptr__],RowScreenY[0] - uStack_10,
                 ((uint16_t *)SquareLeftX)[(int)__return_storage_ptr__],0x36,
                 ((uint16_t *)SquareRightX)[(int)__return_storage_ptr__],0x36,uVar18 & 0xff,
                 (brect_t *)CONCAT22(unaff_SI,(brect_t *)((char *)"puppetmaker" + 3)));
    }
    unaff_DI = 1;
  } while( true );
L_grabLbm_0445:
  iVar16 = ovr_stshRead();
  psVar9 = (stg_tmp_t *)fStack_30.ofs;
  uVar7 = fStack_30.seg;
  if (iVar16 != 0 || wVar11 != 0) {
bad_lbm:
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
  if ((uStack_20 == uStack_c) && (wStack_22 == uStack_e)) {
    cStack_2c = '\x01';
    wVar11 = wStack_22;
    iVar16 = ovr_stshRead();
    if ((((iVar16 != 0 || wVar11 != 0) ||
         (puVar6 = ovr_be4(puStack_2a,CONCAT22(in_stack_0000ff5c,unaff_SI)), wVar11 != 0)) ||
        (puVar6 != (uint32_t *)((byte *)__C0_ASM_CopyRight + 0x10))) ||
       (iVar16 = ovr_stshRead(), iVar16 != 0 || wVar11 != 0)) goto bad_lbm;
    uStack_32 = ovr_be2(uStack_48);
    ovr_be2(uStack_46);
    puStack_2a = (uint32_t *)((byte *)__C0_ASM_CopyRight + 0x10);
    goto L_grabLbm_0445;
  }
  if ((uStack_20 == uStack_14) && (wStack_22 == wStack_16)) {
    wVar10 = wStack_22;
    ovr_stshRead();
    puStack_2a = ovr_be4(puStack_2a,CONCAT22(in_stack_0000ff5c,unaff_SI));
    puStack_26 = puStack_2a;
    wStack_24 = wVar10;
    if (((uint)puStack_2a & 1) != 0) {
      puStack_26 = (uint32_t *)((int)puStack_2a + 1);
      wStack_24 = wVar10 + ((uint32_t *)0xfffe < puStack_2a);
    }
    if (((int)wStack_24 < 0) || ((wStack_24 == 0 && (puStack_26 < (char *)"Error 4 %d \r" + 0xb))))
    {
      if ((-1 < (int)wStack_24) && ((0 < (int)wStack_24 || (puStack_26 != (uint32_t *)0x0)))) {
        ovr_stshRead();
      }
    }
    else {
      ovr_stshRead();
      if ((-1 < (int)wStack_24) &&
         ((0 < (int)wStack_24 || ((char *)"Error 4 %d \r" + 0xb < puStack_26)))) {
        puVar6 = ovr_stshTell(__return_storage_ptr__,unaff_SI);
        ovr_stshSeek((uint16_t)__return_storage_ptr__,
                     CONCAT22(unaff_SI,((int)puVar6 >> 0xf) + wStack_24 +
                                       (uint)CARRY2((uint)puVar6,(uint)puStack_26) + -1 +
                                       (uint)(" \r" < (char *)((int)puVar6 + (int)puStack_26))));
      }
    }
    puVar6 = (uint32_t *)0x0;
    while( true ) {
      if ((0 < (int)wVar10) ||
         ((puVar5 = puStack_2a, wVar11 = wVar10, wVar10 == 0 &&
          ((char *)"Error 4 %d \r" + 0xb < puStack_2a)))) {
        puVar5 = (uint32_t *)((char *)"Error 4 %d \r" + 0xb);
        wVar11 = 0;
      }
      if (((int)wVar11 < 1) && ((wVar11 != 0 || (puVar5 <= puVar6)))) break;
      psVar9->cmap[(int)puVar6] = (uint8_t)((int)(uint)abStackY_348[(int)puVar6] >> 2);
      puVar6 = (uint32_t *)((int)puVar6 + 1);
    }
  }
  else {
    if ((uStack_20 == uStack_10) && (wStack_22 == wStack_12)) {
      if (cStack_2c != '\0') {
        ovr_stshRead();
        puStack_1c = ovr_be4(puStack_2a,CONCAT22(in_stack_0000ff5c,unaff_SI));
        puStack_26 = puStack_1c;
        wStack_24 = wStack_22;
        if (((uint)puStack_1c & 1) != 0) {
          puStack_26 = (uint32_t *)((int)puStack_1c + 1);
          wStack_24 = wStack_22 + ((uint32_t *)0xfffe < puStack_1c);
        }
        pvStack_1e = ovr_stshAlloc(CONCAT13((char)(wStack_24 >> 8),
                                            CONCAT12((char)wStack_24,puStack_26)));
        ovr_stshRead();
        ovr_stshClose((uint16_t)__return_storage_ptr__);
        uStackY_c0 = 0x2337;
        uStackY_c2 = 0x152a;
        src.seg = (uint16_t)puStack_1c;
        src.ofs = (uint16_t)pvStack_1e;
        lbm_decode_body(LBM_PBM,iStack_3e,uStack_40,uStack_3f,src,psVar9,uVar7,iStack0006,
                        in_stack_00000008,uStack_32);
        (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)puStack_1c;
        handle.ofs = (uint16_t)pvStack_1e;
        (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)puStack_1c >> 8);
        ovr_stshFree(handle);
        return psVar9;
      }
      goto bad_lbm;
    }
    wStack_24 = wStack_22;
    ovr_stshRead();
    puStack_26 = ovr_be4(puStack_26,CONCAT22(in_stack_0000ff5c,unaff_SI));
    if (((uint)puStack_26 & 1) != 0) {
      bVar20 = (uint32_t *)0xfffe < puStack_26;
      puStack_26 = (uint32_t *)((int)puStack_26 + 1);
      wStack_24 = wStack_24 + bVar20;
    }
    puVar6 = ovr_stshTell(__return_storage_ptr__,unaff_SI);
    wVar11 = ((int)puVar6 >> 0xf) + wStack_24 + (uint)CARRY2((uint)puVar6,(uint)puStack_26);
    ovr_stshSeek((uint16_t)__return_storage_ptr__,CONCAT22(unaff_SI,wVar11));
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

void __cdecl16far init_buffers(void)

{
  uint16_t in_DX;
  
  (*(uint16_t *)((uint8_t *)&(GUnits))) = ovr_stshAlloc(0x2a30);
  (*(uint16_t *)((uint8_t *)&(GUnits) + 2)) = in_DX;
  _fsetmem((unit_t *)GUnits,in_DX,0x2a30);
  init_initGUnits();
  GUnitCount = 0xf8;
  (*(uint16_t *)((uint8_t *)&(GUnitGrid))) = ovr_stshAlloc(0x4560);
  (*(uint16_t *)((uint8_t *)&(GUnitGrid) + 2)) = in_DX;
  (*(uint16_t *)((uint8_t *)&(GMapFlags))) = ovr_stshAlloc(0x4560);
  (*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)) = in_DX;
  (*(uint16_t *)((uint8_t *)&(GMapCells))) = ovr_stshAlloc(0x22b0);
  (*(uint16_t *)((uint8_t *)&(GMapCells) + 2)) = in_DX;
  (*(uint16_t *)((uint8_t *)&(Entities))) = ovr_stshAlloc(33000);
  (*(uint16_t *)((uint8_t *)&(Entities) + 2)) = in_DX;
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
        *(int *)(GMaxSquare * 2 + 0xd80) =
             *(int *)((int)&AgntAnms[0x5d].sx + 1 + GMaxSquare * 2) + uStack_6;
        *(int *)(GMaxSquare * 2 + 0xa20) = iStack_a + uStack_14;
        *(int *)(GMaxSquare * 2 + 0x6c0) = *(int *)(GMaxSquare * 2 + 0xa20) + uStack_4;
        *(uint *)(GMaxSquare * 2 + 0x360) = uStack_e;
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
        *(int *)(GMaxSquare * 2 + 0xd80) =
             *(int *)((int)&AgntAnms[0x5d].sx + 1 + GMaxSquare * 2) + uStack_6;
        *(int *)(GMaxSquare * 2 + 0xa20) = iStack_8 + uStack_14;
        *(int *)(GMaxSquare * 2 + 0x6c0) = *(int *)(GMaxSquare * 2 + 0xa20) + uStack_4;
        *(int *)(GMaxSquare * 2 + 0x360) = iVar2;
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

uint __cdecl16far init_usesGMapCells(int x,int y)

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
  if (upperTextOfs != 0 || upperTextSeg != 0) {
    handle_02.seg = upperTextSeg;
    handle_02.ofs = upperTextOfs;
    ovr_stshFree(handle_02);
  }
  upperTextSeg = 0;
  upperTextOfs = 0;
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

/* [R4] calls clearEntities */

void __cdecl16far init_usesClearEntities(void)

{
  uint16_t uVar1;
  uint16_t uVar2;
  stg_tmp_t *srcOfs;
  uint16_t unaff_SS;
  far_t handle;
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
  _fmemset((byte *)promotionBandUsed,0x2410,0);
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
    ovr_vgaSetPalette8bit((uint8_t *)CONCAT22(unaff_SS,palette));
  }
  ovr_manage_mapPartySlots();
  return;
}



/* 3381:233e */

/* Returns the GMapCells[y][x] byte inside the map bounds, else 0. */

uint __cdecl16far init_getMapCell(int x,int y)

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

void __cdecl16far init_setMapCell(int x,int y,byte cell)

{
  if ((((x < 0x94) && (-1 < x)) && (y < 0x3c)) && (-1 < y)) {
    (*(byte (*) [59] [148])GMapCells)[y][x] = cell;
  }
  return;
}



/* 3381:23b5 */

/* Returns the flag bits of GMapFlags[y][x] inside the map bounds, else 0. */

uint __cdecl16far init_getMapFlags(int x,int y)

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
init_usesRandBelow(int16_t x,int16_t y,uint8_t dir,uint8_t *lastDir,uint16_t lastDirSeg,
                  uint8_t *sameDirCount,uint16_t sameDirCountSeg)

{
  byte bVar1;
  int iVar2;
  uint16_t uVar3;
  undefined1 uVar6;
  uint uVar4;
  uint uVar5;
  uint uStack_e;
  uint uStack_c;
  byte bStack_8;
  byte bStack_7;
  byte bStack_6;
  byte bStack_5;
  byte bStack_3;
  
  iVar2 = init_sumMapCells2x2(x,y);
  uStack_e = iVar2 + 0x14;
  bStack_6 = 0xff;
  bStack_5 = 0xff;
  bStack_7 = 0xff;
  bStack_8 = 0xff;
  uVar3 = ovr_randBelow(4);
  uVar6 = (undefined1)(uVar3 >> 8);
  uStack_c = uStack_e;
  bStack_3 = (byte)uVar3;
  do {
    uVar5 = CONCAT11(uVar6,bStack_3 - dir) & 0xff03;
    bVar1 = (byte)uVar5;
    if ((bVar1 != 2) &&
       ((*_sameDirCount < 2 || (uVar5 = CONCAT11((char)(uVar5 >> 8),*_lastDir), *_lastDir != bVar1))
       )) {
      bStack_8 = bStack_3;
      uVar4 = init_sumMapCells2x2(x + *(char *)(bStack_3 + 0x885),y + *(char *)(bStack_3 + 0x889));
      if (uVar4 <= uStack_c) {
        bStack_5 = bStack_3;
        uStack_c = uVar4;
      }
      uVar5 = init_compute2(x + *(char *)(bStack_3 + 0x885),y + *(char *)(bStack_3 + 0x889),bStack_3
                           );
      uVar6 = (undefined1)(uVar5 >> 8);
      if ((char)uVar5 != '\0') {
        uVar5 = CONCAT11(uVar6,bStack_3);
        bStack_7 = bStack_3;
        if (uVar4 <= uStack_e) {
          uVar5 = CONCAT11(uVar6,bStack_3);
          bStack_6 = bStack_3;
          uStack_e = uVar4;
        }
      }
    }
    uVar5 = CONCAT11((char)(uVar5 >> 8),bStack_3 + 1) & 0xff03;
    bStack_3 = (byte)uVar5;
    uVar6 = (undefined1)(uVar5 >> 8);
  } while (bStack_3 != (byte)uVar3);
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
  bVar1 = bStack_3 - dir & 3;
  if (bVar1 != 0) {
    if (*_lastDir == bVar1) {
      *_sameDirCount = *_sameDirCount + 1;
    }
    else {
      *_sameDirCount = 0;
      *_lastDir = bVar1;
    }
  }
  return CONCAT11(uVar6,bStack_3);
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
  uint16_t uVar2;
  uint16_t uVar3;
  uint uVar4;
  byte (*paabVar5) [59] [148];
  short (*paasVar6) [60] [148];
  uint x;
  uint y;
  undefined2 uVar7;
  uint16_t unaff_SS;
  far_t dst;
  far_t dst_00;
  ulong uVar8;
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
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&edgeMasks;
  F_SCOPY(far_from_u32((uint32_t)(0x241004f2)),dst);
  dst_00.seg = unaff_SS;
  dst_00.ofs = (uint16_t)&neighbourOfs;
  F_SCOPY(far_from_u32((uint32_t)(0x24100502)),dst_00);
  iStack_12 = 0;
  do {
    if ((int)(uint)randomFeatureCount <= iStack_12) {
      return;
    }
    uVar2 = ovr_randBelow(0x93);
    x = uVar2 & 0xff;
    uVar3 = ovr_randBelow(0x3b);
    y = uVar3 & 0xff;
    bStack_b = 100;
    uVar8 = CONCAT22(uVar3,uVar2) & 0xff00ff;
    uVar4 = init_getMapCell((int)uVar8,(int)(uVar8 >> 0x10));
    bStack_c = (byte)uVar4;
    if (bStack_c < bStack_b) {
      bStack_b = bStack_c;
    }
    uVar4 = init_getMapCell(x + 1,y);
    bStack_c = (byte)uVar4;
    if (bStack_c < bStack_b) {
      bStack_b = bStack_c;
    }
    uVar8 = CONCAT22(y + 1,uVar2) & 0xffff00ff;
    uVar4 = init_getMapCell((int)uVar8,(int)(uVar8 >> 0x10));
    bStack_c = (byte)uVar4;
    if (bStack_c < bStack_b) {
      bStack_b = bStack_c;
    }
    uVar4 = init_getMapCell(x + 1,y + 1);
    bStack_c = (byte)uVar4;
    if (bStack_c < bStack_b) {
      bStack_b = bStack_c;
    }
    uVar8 = (ulong)CONCAT12(bStack_b,uVar3) & 0xffff00ff;
    init_setMapCell(x,(int)uVar8,(byte)(uVar8 >> 0x10));
    uVar8 = (ulong)CONCAT12(bStack_b,uVar3) & 0xffff00ff;
    init_setMapCell(x + 1,(int)uVar8,(byte)(uVar8 >> 0x10));
    init_setMapCell(x,y + 1,bStack_b);
    init_setMapCell(x + 1,y + 1,bStack_b);
    if (bStack_b == 0) {
      uVar8 = CONCAT22(uVar3,uVar2) & 0xff00ff;
      init_usesGMapFlags3((int)uVar8,(int)(uVar8 >> 0x10));
      init_usesGMapFlags3(x - 1,y);
      init_usesGMapFlags3(x + 1,y);
      uVar8 = CONCAT22(y - 1,uVar2) & 0xffff00ff;
      init_usesGMapFlags3((int)uVar8,(int)(uVar8 >> 0x10));
      uVar8 = CONCAT22(y + 1,uVar2) & 0xffff00ff;
      init_usesGMapFlags3((int)uVar8,(int)(uVar8 >> 0x10));
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
      uVar2 = init_usesRandBelow(x,y,bStack_13,&lastDir,unaff_SS,&sameDirCount,unaff_SS);
      bStack_14 = (byte)uVar2;
      if (((bStack_14 == 0xff) || (bStack_13 == (bStack_14 ^ 2))) ||
         ((&edgeMasks)[(uint)bStack_13 * 4 + (uVar2 & 0xff)] == 0x0)) break;
      puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[y] + x);
      *puVar1 = *puVar1 & 0xfffb;
      puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[y] + x);
      *puVar1 = *puVar1 | (uint)(&edgeMasks)[(uint)bStack_13 * 4 + (uVar2 & 0xff)];
      uVar4 = init_getMapCell(x + (abStack_9[(uint)bStack_13 * 2 + -1] & 1),
                              y + ((int)(uint)abStack_9[(uint)bStack_13 * 2 + -1] >> 1));
      bStack_c = (byte)uVar4;
      uVar4 = init_getMapCell(x + (abStack_9[(uint)bStack_13 * 2] & 1),
                              y + ((int)(uint)abStack_9[(uint)bStack_13 * 2] >> 1));
      bStack_d = (byte)uVar4;
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
  *(undefined1 *)GrayscalePalette = 0;
  for (i = 1; (int)i < 0x100; i = i + 1) {
    max_c = (uint16_t)psVar1->cmap[i * 3];
    if (max_c < psVar1->cmap[i * 3 + 1]) {
      max_c = (uint16_t)psVar1->cmap[i * 3 + 1];
    }
    if (max_c < psVar1->cmap[i * 3 + 2]) {
      max_c = (uint16_t)psVar1->cmap[i * 3 + 2];
    }
    *(char *)(GrayscalePalette.ofs + i) = buf[max_c * 0xb >> 6];
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
  far_t handle;
  uint8_t msg;
  uint16_t input;
  byte *pbStack_a;
  undefined4 uStack_8;
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
      ovr_blitText((char *)"Stronghold copy protection.",(byte *)((char *)"puppetmaker" + 3),
                   Font03.ofs,(uint8_t)Font03.seg);
      TextBlitX = 0x16;
      TextBlitY = 0x2f;
      uVar1 = Font03.ofs;
      uVar3 = Font03.seg;
      pcVar2 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"Turn to page #%d of the manual.");
      ovr_blitText(pcVar2,in_DX,uVar1,(uint8_t)uVar3);
      TextBlitX = 0x16;
      TextBlitY = 0x43;
      uVar1 = Font03.ofs;
      uVar3 = Font03.seg;
      pcVar2 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"Including titles, count to line #%d.");
      ovr_blitText(pcVar2,in_DX,uVar1,(uint8_t)uVar3);
      TextBlitX = 0x16;
      TextBlitY = 0x57;
      ovr_blitText((char *)"Enter the first word.",(byte *)((char *)"puppetmaker" + 3),Font03.ofs,
                   (uint8_t)Font03.seg);
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
    _fstricmp((char *)input,(char *)pbStack_a);
    handle.seg = (uint16_t)pbStack_a;
    handle.ofs = input;
    ovr_stshFree(handle);
    ovr_saveui_blitPanel();
    CopyProtectionDone = '\x01';
  }
  return;
}


