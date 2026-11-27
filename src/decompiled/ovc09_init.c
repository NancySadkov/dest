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
  ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)(0xa0000000)),0);
  gfx_01.seg = GMenuGfxSeg;
  gfx_01.ofs = GMenuGfxOfs;
  ovr_blitLoadRleGfx(gfx_01,far_from_u32((uint32_t)(0xa00009af)),0);
  gfx.seg = nwpanel2Cut1Seg;
  gfx.ofs = nwpanel2Cut1Ofs;
  ovr_blitGfxRect(gfx,0,0,(brect_t *)(BlitRects + 1),0x10,true,0,0,0,0,0,0);
  if (GameRunning == false) {
    gfx_02.seg = panel01Cut3Seg;
    gfx_02.ofs = panel01Cut3Ofs;
    ovr_blitLoadRleGfx(gfx_02,far_from_u32((uint32_t)(0xa000c51d)),0);
    mapViewActive = 0;
  }
  return;
}



/* 3381:009a */

char * __cdecl16far append_name_to_path(char far *path,char far *name)

{
  /* Re-derived from 3381:009a (100 bytes).  The prologue pushes each far argument segment-then-
     offset, so both parameters are far pointers: (seg [bp+8], ofs [bp+6]) for the path and
     (seg [bp+0xc], ofs [bp+0xa]) for the name.  strcpy into GStaticBuffer, strlen, then a backward
     scan that stops at the first backslash and terminates the string there, then strcat the name.
     The exported CONCAT22 builds split the far pointers and rejoined them in the wrong order, and it
     stored the terminator unconditionally instead of only on a hit. */
  uint16_t l;

  strcpy((char *)&GStaticBuffer,(char *)path);
  l = strlen((char *)&GStaticBuffer);
  for (;;) {
    l = l - 1;
    if ((int)l <= 0) {
      break;
    }
    if (((undefined1 *)&GStaticBuffer)[l - 1] != 0x5c) {
      continue;
    }
    ((undefined *)&GStaticBuffer)[l] = 0;
    break;
  }
  strcat((char *)&GStaticBuffer,(char *)name);
  return (char *)&GStaticBuffer;
}



/* 3381:00fe */

char * __cdecl16far path_strip_tail_slash(char far *s, uint16_t arg2)

{
  uint16_t l;
  
  l = strlen((char *)CONCAT22(arg2,s));
  if ((3 < (int)l) && (s[l - 1] == '\\')) {
    s[l - 1] = '\0';
  }
  return s;
}



/* 3381:0132 */

char * __cdecl16far ensure_tail_slash(char *s,uint16_t arg2)

{
  uint16_t l;
  
  l = strlen((char *)CONCAT22(arg2,s));
  if ((l == 0) || (s[l - 1] != '\\')) {
    s[l] = '\\';
    s[l + 1] = '\0';
  }
  return s;
}



/* 3381:016c */

/* chdir doesn't change the disk, so we have to do that */

void __cdecl16far chpath(char far *path, uint16_t arg2)

{
  uint8_t c;
  char driveLetter;
  int chdirResult;
  undefined1 extraout_AH;
  
  chdirResult = chdir((char *)CONCAT22(arg2,path));
  if (chdirResult == 0) {
    c = toupper((int)*path);
    if (((path[1] == ':') && ('@' < (char)c)) && ((char)c < '[')) {
      driveLetter = toupper((int)(char)c);
      setdisk(CONCAT11(extraout_AH,driveLetter) + -0x41);
    }
  }
  return;
}



/* 3381:01c8 */

void __cdecl16far init_paths(void)

{
  /* Recovered shape:
       getcwd(DGROUP:[0x44])                     ; the current directory
       strcpy(&GWorkDir, GOriginalDir)           ; same buffer
       ensure_tail_slash(&GWorkDir, 0x2410)
       strcat(&GWorkDir, (char *)GSaveFileName)
       append_name_to_path(exe path, work dir) ; chdir to the exe's directory

     The decompiled form addressed the original image's data segment (0x2410) for the
     cwd buffer and passed that segment number as ensure_tail_slash's second argument.
     The buffer it fills is copied into GWorkDir immediately afterwards, so it is
     GOriginalDir.  The trailing append_name_to_path/chpath only changes to the
     program's own directory, which is where this build already runs. */
  getcwd((char *)&GOriginalDir,68);
  strcpy((char *)&GWorkDir,(char *)&GOriginalDir);
  ensure_tail_slash((char *)&GWorkDir,0);
  strcat((char *)&GWorkDir,(char *)GSaveFileName);
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
  bool needWrite;
  uint8_t cfgChar;
  uint16_t cfgPath;
  uint16_t fh;
  char *path;
  int writeHnd;
  int closeResult;
  int wroteSfx;
  int wroteCrlf1;
  int wroteIrq;
  int wroteCrlf2;
  uint16_t in_DX;
  char lbuf [80];
  /* static: write() takes a near buffer (BC30 io.h, _FAR is empty for the
     medium model), so the two bytes it writes must live in DGROUP. */
  static uint16_t crlf;
  static char mice;
  uint8_t c;
  
  crlf = GCrLf;
  needWrite = false;
  /* Recovered address pair: the format at DGROUP:0x5BC is (char *)GCfgFileName (verified in
     audit/dgroup_2410.bin) and the argument was the buffer at 0x2410:0x8C6C,
     which is empty at startup and has no symbol - it is the data-path prefix,
     and every other file call in the recovered code uses (char *)GSaveFileName.
     Building it here keeps the same result without the original image's
     segment. */
  sprintf(lbuf,(char *)GCfgFileName,(char *)&GWorkDir);
  cfgPath = (uint16_t)lbuf;
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
  cfgChar = c;
  if ((((char)c < '1') || ('9' < (char)c)) && (((char)c < 'A' || ('B' < (char)c)))) {
    if (((char)c < 'a') || ('b' < (char)c)) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x80);
    }
    cfgChar = toupper((int)(char)c);
  }
  CFG_Sfx = cfgChar;
  c = ovr_read_cfg(fh);
  if (c == 0x0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x80);
  }
  cfgChar = c;
  if ((((char)c < '1') || ('9' < (char)c)) && (((char)c < 'A' || ('B' < (char)c)))) {
    if (((char)c < 'a') || ('b' < (char)c)) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x80);
    }
    cfgChar = toupper((int)(char)c);
  }
  CFG_Mus = cfgChar;
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
    needWrite = true;
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
  if (needWrite) {
    sprintf(lbuf,(char *)GCfgFileName,(char *)&GWorkDir);
  path = (char *)lbuf;
    writeHnd = ovr_creat_wait_unlock_and_disk(path,in_DX);
    if (writeHnd < 0) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x83);
    }
    write(writeHnd,&CFG_Sfx,1);
    write(writeHnd,(void *)&crlf,2);
    write(writeHnd,&CFG_Mus,1);
    write(writeHnd,(void *)&crlf,2);
    wroteSfx = write(writeHnd,&CFG_Irq,1);
    wroteCrlf1 = write(writeHnd,(void *)&crlf,2);
    wroteIrq = write(writeHnd,(void *)&mice,1);
    wroteCrlf2 = write(writeHnd,(void *)&crlf,2);
    closeResult = close(writeHnd);
    if ((((wroteSfx != 1 || wroteCrlf1 != 2) || wroteIrq != 1) || wroteCrlf2 != 2) || (char)closeResult != '\0') {
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
  srand8(CONCAT22(*(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2),*(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs))
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
  ovr_play_sfx(83,0,0);
  return;
}



/* 3381:0693 */

/* Rebuilds the whole GMapFlags array from GMapCells (bits 0/1/2 per cell triple). */

void __cdecl16far init_rebuildMapFlags(void)

{
  /* Re-derived: the same map-flags rebuild applied to the whole 0x3b x 0x93 grid. */
  uint16_t *flagWord;
  int col;
  int row;

  for (row = 0; row < 0x3b; row = row + 1) {
    for (col = 0; col < 0x93; col = col + 1) {
      if (((*(short (*) [60] [148])GMapFlags)[row][col] & 4U) == 0) {
        if (((*(byte (*) [59] [148])GMapCells)[row][col] == 0) &&
            ((*(byte (*) [59] [148])GMapCells)[row + 1][col + 1] == 0) &&
            ((*(byte (*) [59] [148])GMapCells)[row + 1][col] == 0)) {
          flagWord = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[row] + col);
          *flagWord = *flagWord | 1;
        }
        if (((*(byte (*) [59] [148])GMapCells)[row][col] == 0) &&
            ((*(byte (*) [59] [148])GMapCells)[row + 1][col + 1] == 0) &&
            ((*(byte (*) [59] [148])GMapCells)[row][col + 1] == 0)) {
          flagWord = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[row] + col);
          *flagWord = *flagWord | 2;
        }
      }
      else {
        if (((*(byte (*) [59] [148])GMapCells)[row + 1][col] == 0) &&
            ((*(byte (*) [59] [148])GMapCells)[row][col + 1] == 0) &&
            ((*(byte (*) [59] [148])GMapCells)[row][col] == 0)) {
          flagWord = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[row] + col);
          *flagWord = *flagWord | 1;
        }
        if (((*(byte (*) [59] [148])GMapCells)[row + 1][col] == 0) &&
            ((*(byte (*) [59] [148])GMapCells)[row][col + 1] == 0) &&
            ((*(byte (*) [59] [148])GMapCells)[row + 1][col + 1] == 0)) {
          flagWord = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[row] + col);
          *flagWord = *flagWord | 2;
        }
      }
    }
  }
  return;
}



/* 3381:08dc */
void __cdecl16far init_textFilename(void)

{
  undefined1 stk_d744;   /* stack slot d744 */
  uint16_t bptrSeg;
  far_t gfx;
  far_t gfx_00;
  far_t src;
  far_t src_00;
  far_t handle;
  far_t handle_00;
  ulong unitGridSeg;
  char cVar3;
  byte bVar4;
  uint32_t *puVar5;
  undefined1 extraout_AH;
  undefined1 uVar10;
  uint32_t *puVar6;
  uint16_t randPick;
  uint cellDiff;
  stg_tmp_t *psVar9;
  undefined1 extraout_AH_00;
  int in_CX;
  uint extraout_DX;
  uint otherDiffSign;
  uint cellDiffSign;
  byte (*mapCells) [59] [148];
  short (*paasVar14) [148] [60];
  uint16_t unaff_SI;
  int row;   /* map row, 0..0x93 */
  int iVar15;
  int col;   /* map column, 0..0x93 */
  int sample;
  byte unaff_DI;
  uint uVar17;
  uint32_t *retStorage;
  uint16_t uVar18;
  bool carry;
  longdouble in_ST0;
  uint32_t in_stack_00000004;
  int16_t in_stack_00000008;
  byte abStackY_348 [488];
  undefined1 auStackY_160 [158];
  uint16_t uStackY_c2;
  uint16_t uStackY_c0;
  uint16_t uStackY_be;
  char acStack_a4 [92];
  uint16_t uStack_48;
  uint16_t uStack_46;
  int8_t iStack_40;
  uint8_t uStack_3f;
  lbm_type_t lStack_3e;
  uint16_t beWordB;
  uint16_t beWordA;
  far_t fStack_30;
  char ok;
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
  uint accum;
  uint sampleHi;
  uint16_t uStack_10;
  uint16_t fileIdx;
  uint uStack_c;
  uint uStack_a;
  uint uStack_8;
  int unitIdx;
  byte bldType;
  
  uStack_10 = (uint)(byte)uStack_10;
  for (row = 0; row < 0x94; row = row + 1) {
    randPick = ovr_randBelow(10,0);
    if ((randPick & 0xff) == 0) {
      randPick = ovr_randBelow(2,0);
      cVar3 = (char)randPick * '\x02' + (*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) + -1;
      uStack_10 = CONCAT11(cVar3,(byte)uStack_10);
      if (cVar3 < -1) {
        uStack_10 = CONCAT11(0xff,(byte)uStack_10);
      }
      if ('\x01' < (*(uint8_t *)((uint8_t *)&(uStack_10) + 1))) {
        uStack_10 = CONCAT11(1,(byte)uStack_10);
      }
    }
    if ((row == 0) || (row == 0x93)) {
      uStack_10 = uStack_10 & 0xff;
    }
    acStack_a4[row] = (*(uint8_t *)((uint8_t *)&(uStack_10) + 1));
  }
  uStack_c = 0;
  uStack_a = 0;
  _fsetmem(GUnitGrid,0x4560,0);
  psVar9 = (stg_tmp_t *)((char *)0x26510);
  _fsetmem(GMapFlags,0x4560,0);
  for (uVar17 = 0; (int)uVar17 < 0x3c; uVar17 = uVar17 + 1) {
    if ((uVar17 & 1) == 0) {
      for (row = 0; row < 0x94; row = row + 1) {
        uStack_c = 0;
        if (row != 0) {
          uStack_c = (int)(char)((byte (*) [59] [148])GMapCells)[-1][uVar17 + 0x3a][row + 0x93];
        }
        if (uVar17 != 0) {
          uStack_c = uStack_c +
                     (int)(char)((byte (*) [59] [148])GMapCells)[-1][uVar17 + 0x3a]
                                [acStack_a4[row] + row];
        }
        uStack_c = (int)uStack_c >> 1;
        if ((row != 0) && (acStack_a4[row + -1] != acStack_a4[row])) {
          randPick = ovr_randBelow(8,0);
          uStack_8 = randPick & 0xff;
          if (uStack_8 == 1) {
            acStack_a4[row] = acStack_a4[row + -1];
          }
          else if (uStack_8 == 2) {
            acStack_a4[row + -1] = acStack_a4[row];
          }
        }
        randPick = ovr_randBelow(0x10,0);
        if ((randPick & 0xff) == 0) {
          if (row != 0) {
            (*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) = acStack_a4[row + -1];
            randPick = ovr_randBelow(2,0);
            cVar3 = (char)randPick * '\x02' + (*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) + -1;
            uStack_10 = CONCAT11(cVar3,(byte)uStack_10);
            if (cVar3 < -1) {
              uStack_10 = CONCAT11(0xff,(byte)uStack_10);
            }
            if ('\x01' < (*(uint8_t *)((uint8_t *)&(uStack_10) + 1))) {
              uStack_10 = CONCAT11(1,(byte)uStack_10);
            }
            acStack_a4[row] = (*(uint8_t *)((uint8_t *)&(uStack_10) + 1));
          }
          if ((int)uStack_c < 0x56) {
            if ((int)uStack_c < 0x41) {
              if ((int)uStack_c < 0x2b) {
                if ((int)uStack_c < 0x16) {
                  if ((int)uStack_c < 1) {
                    randPick = ovr_randBelow(9,0);
                    uStack_a = (randPick & 0xff) - 2;
                  }
                  else {
                    randPick = ovr_randBelow(8,0);
                    uStack_a = (randPick & 0xff) - 5;
                  }
                }
                else {
                  randPick = ovr_randBelow(0x10,0);
                  uStack_a = (randPick & 0xff) - 8;
                }
              }
              else {
                randPick = ovr_randBelow(0xb,0);
                uStack_a = (randPick & 0xff) - 5;
              }
            }
            else {
              randPick = ovr_randBelow(8,0);
              uStack_a = (randPick & 0xff) - 4;
            }
          }
          else {
            randPick = ovr_randBelow(0x11,0);
            uStack_a = (randPick & 0xff) - 8;
          }
        }
        if ((int)uStack_c < 0x56) {
          if ((int)uStack_c < 0x41) {
            if ((int)uStack_c < 0x2b) {
              if ((int)uStack_c < 0x16) {
                if ((int)uStack_c < 1) {
                  fileIdx = 0xb;
                }
                else {
                  fileIdx = 5;
                }
              }
              else {
                fileIdx = 0xf;
              }
            }
            else {
              fileIdx = 5;
            }
          }
          else {
            fileIdx = 0x13;
          }
        }
        else {
          fileIdx = 9;
        }
        randPick = ovr_randBelow(fileIdx,0);
        uStack_c = uStack_c + ((randPick & 0xff) - ((int)fileIdx >> 1)) + uStack_a + 1;
        if ((int)uStack_c < -0x23) {
          uStack_c = 0xffdd;
          uStack_a = (uStack_a ^ (int)uStack_a >> 0xf) - ((int)uStack_a >> 0xf);
        }
        if (0x7f < (int)uStack_c) {
          uStack_c = 0x7f;
          uStack_a = -((uStack_a ^ (int)uStack_a >> 0xf) - ((int)uStack_a >> 0xf));
        }
        psVar9 = (stg_tmp_t *)CONCAT11((char)(uVar17 * 0x94 >> 8),(byte)uStack_c);
        (*(byte (*) [59] [148])GMapCells)[uVar17][row] = (byte)uStack_c;
      }
    }
    else {
      for (row = 0x93; -1 < row; row = row + -1) {
        uStack_c = 0;
        if (row != 0x93) {
          uStack_c = (int)(char)(*(byte (*) [59] [148])GMapCells)[uVar17][row + 1];
        }
        if (uVar17 != 0) {
          uStack_c = uStack_c +
                     (int)(char)((byte (*) [59] [148])GMapCells)[-1][uVar17 + 0x3a]
                                [acStack_a4[row] + row];
        }
        uStack_c = (int)uStack_c >> 1;
        if ((row != 0x93) && (acStack_a4[row + 1] != acStack_a4[row])) {
          randPick = ovr_randBelow(0x10,0);
          uStack_8 = randPick & 0xff;
          if (uStack_8 == 1) {
            acStack_a4[row] = acStack_a4[row + 1];
          }
          else if (uStack_8 == 2) {
            acStack_a4[row + 1] = acStack_a4[row];
          }
        }
        randPick = ovr_randBelow(0x10,0);
        if ((randPick & 0xff) == 0) {
          if (row != 0x93) {
            (*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) = acStack_a4[row + 1];
            randPick = ovr_randBelow(2,0);
            cVar3 = (char)randPick * '\x02' + (*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) + -1;
            uStack_10 = CONCAT11(cVar3,(byte)uStack_10);
            if (cVar3 < -1) {
              uStack_10 = CONCAT11(0xff,(byte)uStack_10);
            }
            if ('\x01' < (*(uint8_t *)((uint8_t *)&(uStack_10) + 1))) {
              uStack_10 = CONCAT11(1,(byte)uStack_10);
            }
            acStack_a4[row] = (*(uint8_t *)((uint8_t *)&(uStack_10) + 1));
          }
          if ((int)uStack_c < 0x56) {
            if ((int)uStack_c < 0x41) {
              if ((int)uStack_c < 0x2b) {
                if ((int)uStack_c < 0x16) {
                  if ((int)uStack_c < 1) {
                    randPick = ovr_randBelow(9,0);
                    uStack_a = (randPick & 0xff) - 2;
                  }
                  else {
                    randPick = ovr_randBelow(8,0);
                    uStack_a = (randPick & 0xff) - 5;
                  }
                }
                else {
                  randPick = ovr_randBelow(0x10,0);
                  uStack_a = (randPick & 0xff) - 8;
                }
              }
              else {
                randPick = ovr_randBelow(0xb,0);
                uStack_a = (randPick & 0xff) - 5;
              }
            }
            else {
              randPick = ovr_randBelow(8,0);
              uStack_a = (randPick & 0xff) - 4;
            }
          }
          else {
            randPick = ovr_randBelow(0x11,0);
            uStack_a = (randPick & 0xff) - 8;
          }
        }
        if ((int)uStack_c < 0x56) {
          if ((int)uStack_c < 0x41) {
            if ((int)uStack_c < 0x2b) {
              if ((int)uStack_c < 0x16) {
                if ((int)uStack_c < 1) {
                  fileIdx = 0xb;
                }
                else {
                  fileIdx = 5;
                }
              }
              else {
                fileIdx = 0xf;
              }
            }
            else {
              fileIdx = 5;
            }
          }
          else {
            fileIdx = 0x13;
          }
        }
        else {
          fileIdx = 9;
        }
        randPick = ovr_randBelow(fileIdx,0);
        uStack_c = uStack_c + ((randPick & 0xff) - ((int)fileIdx >> 1)) + uStack_a + 1;
        if ((int)uStack_c < -0x7f) {
          uStack_c = 0xff81;
          uStack_a = (uStack_a ^ (int)uStack_a >> 0xf) - ((int)uStack_a >> 0xf);
        }
        if (0x7f < (int)uStack_c) {
          uStack_c = 0x7f;
          uStack_a = -((uStack_a ^ (int)uStack_a >> 0xf) - ((int)uStack_a >> 0xf));
        }
        psVar9 = (stg_tmp_t *)CONCAT11((char)(uVar17 * 0x94 >> 8),(byte)uStack_c);
        (*(byte (*) [59] [148])GMapCells)[uVar17][row] = (byte)uStack_c;
      }
    }
  }
  for (row = 0; row < 0x3c; row = row + 1) {
    for (col = 0; col < 0x94; col = col + 1) {
      uVar18 = (uint16_t)((ulong)GMapCells >> 0x10);
      if ((char)(*(byte (*) [59] [148])GMapCells)[row][col] < '\0') {
        (*(byte (*) [59] [148])GMapCells)[row][col] = 0;
      }
      psVar9 = (stg_tmp_t *)(row * 0x94);
      if ((col != 0x93) && (row != 0x3c)) {
        uVar18 = (uint16_t)((ulong)GMapCells >> 0x10);
        mapCells = (byte (*) [59] [148])GMapCells;
        uVar17 = (int)(char)(*mapCells)[row + 1][col] -
                 (int)(char)(*mapCells)[row][col + 1];
        otherDiffSign = (int)uVar17 >> 0xf;
        cellDiff = (int)(char)(*mapCells)[row][col] -
                (int)(char)(*mapCells)[row + 1][col + 1];
        cellDiffSign = (int)cellDiff >> 0xf;
        psVar9 = (stg_tmp_t *)((cellDiff ^ cellDiffSign) - cellDiffSign);
        if ((int)((uVar17 ^ otherDiffSign) - otherDiffSign) < (int)psVar9) {
          psVar9 = (stg_tmp_t *)(col * 2);
          *(uint *)(psVar9->cmap + (int)(*(short (*) [60] [148])GMapFlags + row)) =
               *(uint *)(psVar9->cmap + (int)(*(short (*) [60] [148])GMapFlags + row)) | 4;
        }
      }
    }
  }
  init_rebuildMapFlags();
  init_usesRandBelow2();
  init_rebuildMapFlags();
  retStorage = (uint32_t *)0x0;
  do {
    if (0x3a < (int)retStorage) {
      for (row = 1; row < 0x3a; row = row + 1) {
        for (col = 1; col < 0x92; col = col + 1) {
          randPick = ovr_randBelow(2,0);
          psVar9 = (stg_tmp_t *)(randPick & 0xff);
          if (psVar9 == (stg_tmp_t *)0x0) {
            psVar9 = (stg_tmp_t *)(row * 0x94);
            uVar18 = (uint16_t)((ulong)GMapCells >> 0x10);
            mapCells = (byte (*) [59] [148])GMapCells;
            if ((((((psVar9->cmap[(int)(*mapCells + -1) + 0x93 + col] != 0) &&
                   (psVar9 = (stg_tmp_t *)(*mapCells + row), psVar9->cmap[col + 0x93] != 0))
                  && (psVar9 = (stg_tmp_t *)(row * 0x94),
                     psVar9->cmap[(int)((*mapCells)[0] + col)] != 0)) &&
                 ((psVar9 = (stg_tmp_t *)(*mapCells + row), psVar9->cmap[col + 0x94] != 0 &&
                  (psVar9 = (stg_tmp_t *)(row * 0x94),
                  psVar9->cmap[(int)((*mapCells)[0] + col + 1)] != 0)))) &&
                (psVar9 = (stg_tmp_t *)(*mapCells + row), psVar9->cmap[col + 0x95] != 0)) &&
               (((bVar4 = (*mapCells)[row][col],
                 psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(row * 0x94) >> 8),bVar4),
                 (char)bVar4 <= (char)(*mapCells)[row][col + 1] &&
                 (bVar4 = (*mapCells)[row][col],
                 psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(row * 0x94) >> 8),bVar4),
                 (char)bVar4 <= (char)mapCells[-1][row + 0x3a][col + 0x93])) &&
                ((bVar4 = (*mapCells)[row][col],
                 psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(row * 0x94) >> 8),bVar4),
                 (char)bVar4 <= (char)mapCells[-1][row + 0x3a][col] &&
                 (((bVar4 = (*mapCells)[row][col + 1],
                   psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(row * 0x94) >> 8),bVar4),
                   (char)bVar4 <= (char)mapCells[-1][row + 0x3a][col + 1] &&
                   (bVar4 = (*mapCells)[row][col],
                   psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(row * 0x94) >> 8),bVar4),
                   (char)bVar4 <= (char)(*mapCells)[row + 1][col])) &&
                  (bVar4 = (*mapCells)[row][col + 1],
                  psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(row * 0x94) >> 8),bVar4),
                  (char)bVar4 <= (char)(*mapCells)[row + 1][col + 1])))))))) {
              uVar17 = ovr_init_getMapFlags(col);
              psVar9 = (stg_tmp_t *)(uVar17 & 0xff);
              if (psVar9 == (stg_tmp_t *)0x0) {
                uVar17 = ovr_init_getMapFlags(col + -1);
                psVar9 = (stg_tmp_t *)(uVar17 & 0xff);
                if ((psVar9 == (stg_tmp_t *)0x0) &&
                   (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags2(col), (char)psVar9 == '\x02')
                   ) {
                  unitIdx = ((short (*) [148] [60])GUnitGrid)[-1][col + 0x92][row];
                  bldType = (GUnits + unitIdx)->bldType;
                  psVar9 = (stg_tmp_t *)((uint)bldType * 0x27);
                  if ((psVar9->cmap[0x11b] < 2) &&
                     (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags2(col), (byte)psVar9 < 3)) {
                    randPick = ovr_randBelow(5,0);
                    ((short (*) [148] [60])GUnitGrid)[-1][col + 0x93][row] =
                         (randPick & 0xff) + 0x92;
                    unitGridSeg = (ulong)GUnitGrid >> 0x10;
                    paasVar14 = (short (*) [148] [60])GUnitGrid;
                    psVar9 = (stg_tmp_t *)(row * 2);
                    (psVar9->cmap + (int)(*paasVar14 + col))[0] = 0;
                    (psVar9->cmap + (int)(*paasVar14 + col))[1] = 0;
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
    for (row = 0; row < 0x93; row = row + 1) {
      psVar9 = (stg_tmp_t *)((int)retStorage * 0x94);
      uVar18 = (uint16_t)((ulong)GMapCells >> 0x10);
      mapCells = (byte (*) [59] [148])GMapCells;
      if (((psVar9->cmap[(int)((*mapCells)[0] + row)] != 0) &&
          (psVar9 = (stg_tmp_t *)((int)retStorage * 0x94),
          psVar9->cmap[(int)((*mapCells)[0] + row + 1)] != 0)) &&
         ((psVar9 = (stg_tmp_t *)(*mapCells + (int)retStorage),
          psVar9->cmap[row + 0x94] != 0 &&
          (psVar9 = (stg_tmp_t *)(*mapCells + (int)retStorage),
          psVar9->cmap[row + 0x94] != 0)))) {
        uVar17 = ovr_init_getMapFlags(row);
        psVar9 = (stg_tmp_t *)(uVar17 & 0xff);
        if (psVar9 == (stg_tmp_t *)0x0) {
          uStack_c = (uint)(char)(*(byte (*) [59] [148])GMapCells)[(int)retStorage]
                                 [row];
          if ((int)uStack_c < 0x6b) {
            if ((int)uStack_c < 0x56) {
              if ((int)uStack_c < 0x40) {
                if ((int)uStack_c < 0x2b) {
                  if ((int)uStack_c < 0x16) {
                    randPick = ovr_randBelow(4,0);
                    psVar9 = (stg_tmp_t *)(randPick & 0xff);
                    if (psVar9 == (stg_tmp_t *)((int)(uint32_t *)&_DATA + 2)) {
                      randPick = ovr_randBelow(6,0);
                      psVar9 = (stg_tmp_t *)((randPick & 0xff) + 0x3d);
                      (*(short (*) [148] [60])GUnitGrid)[row][(int)retStorage] =
                           (short)psVar9;
                    }
                    else if ((psVar9 == (stg_tmp_t *)((int)(uint32_t *)&_DATA + 3)) &&
                            (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(row,0,0),
                            (char)psVar9 != '\0')) {
                      randPick = ovr_randBelow(2,0);
                      psVar9 = (stg_tmp_t *)(randPick & 0xff);
                      if (psVar9 == (stg_tmp_t *)0x0) {
                        randPick = ovr_randBelow(9,0);
                        psVar9 = (stg_tmp_t *)((randPick & 0xff) + 0x67);
                        (*(short (*) [148] [60])GUnitGrid)[row][(int)retStorage] =
                             (short)psVar9;
                      }
                    }
                  }
                  else {
                    randPick = ovr_randBelow(4,0);
                    psVar9 = (stg_tmp_t *)(randPick & 0xff);
                    switch((uint16_t)psVar9)   /* hand fix: case values are ints */ {
                    case (uint16_t)0x0:
                      func_0x000318f5();
                      bStack_2b = 0;
                      uVar17 = extraout_DX;
                      goto L_grabLbm_0445;
                    case (uint16_t)0x1:
                      while( true ) {
                        pbStack_18 = psVar9->cmap + (int)pbStack_18;
                        psVar9 = (stg_tmp_t *)(row + (int)retStorage);
                        if ((int)puStack_1c <= (int)psVar9) {
                          psVar9 = memcpy((char *)CONCAT13((char)(sampleHi >> 8),
                                                           CONCAT12((char)sampleHi,accum)),
                                          (char *)CONCAT13((char)((uint)_SS >> 8),
                                                           CONCAT12((char)_SS,
                                                                    auStackY_160 + uStack_c)),
                                          fileIdx);
                          accum = accum + 0x140;
                        }
                        row = row + 1;
                        if (((int)uStack_10 <= row) ||
                           (psVar9 = (stg_tmp_t *)(row + (int)retStorage),
                           (int)uStack_20 < (int)psVar9)) break;
                        (*(uint8_t *)((uint8_t *)&(src_00.seg))) = (char)uStack_16;
                        src_00.ofs = (uint16_t)pbStack_18;
                        (*(uint8_t *)((uint8_t *)&(src_00.seg) + 1)) = (char)(uStack_16 >> 8);
                        psVar9 = (stg_tmp_t *)ovr_unrle(src_00,0,0,0,0);
                      }
                      return psVar9;
                    case (uint16_t)0x2:
                      *retStorage = 0L;
                    /* WARNING: Bad instruction - Truncating control flow here */
                      halt_baddata();
                    case (uint16_t)0x3:
                      goto switchD_3000_4a6e_caseD_3;
                    }
                  }
                }
                else {
                  randPick = ovr_randBelow(4,0);
                  psVar9 = (stg_tmp_t *)(randPick & 0xff);
                  if (psVar9 == (stg_tmp_t *)((int)(uint32_t *)&_DATA + 1)) {
                    randPick = ovr_randBelow(6,0);
                    psVar9 = (stg_tmp_t *)((randPick & 0xff) + 0x3d);
                    (*(short (*) [148] [60])GUnitGrid)[row][(int)retStorage] =
                         (short)psVar9;
                  }
                  else if ((psVar9 == (stg_tmp_t *)((int)(uint32_t *)&_DATA + 3)) &&
                          (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(row,0,0),
                          (char)psVar9 != '\0')) {
                    randPick = ovr_randBelow(9,0);
                    psVar9 = (stg_tmp_t *)((randPick & 0xff) + 0x67);
                    (*(short (*) [148] [60])GUnitGrid)[row][(int)retStorage] =
                         (short)psVar9;
                  }
                }
              }
              else {
                randPick = ovr_randBelow(4,0);
                psVar9 = (stg_tmp_t *)(randPick & 0xff);
                if (((psVar9 == (stg_tmp_t *)((int)(uint32_t *)&_DATA + 3)) &&
                    (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(row,0,0), (char)psVar9 != '\0'))
                   && (psVar9 = (stg_tmp_t *)ovr_randBelow(2,0), (char)psVar9 != '\0')) {
                  randPick = ovr_randBelow(9,0);
                  psVar9 = (stg_tmp_t *)((randPick & 0xff) + 0x67);
                  (*(short (*) [148] [60])GUnitGrid)[row][(int)retStorage] =
                       (short)psVar9;
                }
              }
            }
            else {
              randPick = ovr_randBelow(4,0);
              psVar9 = (stg_tmp_t *)(randPick & 0xff);
              if (psVar9 == (stg_tmp_t *)((int)(uint32_t *)&_DATA + 1)) {
                psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(row,0,0);
                if ((char)psVar9 != '\0') {
                  randPick = ovr_randBelow(2,0);
                  if ((randPick & 0xff) == 0) {
                    randPick = ovr_randBelow(6,0);
                    psVar9 = (stg_tmp_t *)((randPick & 0xff) + 0x3d);
                    (*(short (*) [148] [60])GUnitGrid)[row][(int)retStorage] =
                         (short)psVar9;
                  }
                  else {
                    randPick = ovr_randBelow(9,0);
                    psVar9 = (stg_tmp_t *)((randPick & 0xff) + 0x67);
                    (*(short (*) [148] [60])GUnitGrid)[row][(int)retStorage] =
                         (short)psVar9;
                  }
                }
              }
              else if ((psVar9 == (stg_tmp_t *)((int)(uint32_t *)&_DATA + 3)) &&
                      (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(row,0,0), (char)psVar9 != '\0')
                      ) {
                randPick = ovr_randBelow(9,0);
                psVar9 = (stg_tmp_t *)((randPick & 0xff) + 0x67);
                (*(short (*) [148] [60])GUnitGrid)[row][(int)retStorage] =
                     (short)psVar9;
              }
            }
          }
          else {
            randPick = ovr_randBelow(4,0);
            psVar9 = (stg_tmp_t *)(randPick & 0xff);
            if (((psVar9 == (stg_tmp_t *)((int)(uint32_t *)&_DATA + 2)) ||
                (psVar9 == (stg_tmp_t *)((int)(uint32_t *)&_DATA + 3))) &&
               (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(row,0,0), (char)psVar9 != '\0')) {
              randPick = ovr_randBelow(9,0);
              psVar9 = (stg_tmp_t *)((randPick & 0xff) + 0x67);
              (*(short (*) [148] [60])GUnitGrid)[row][(int)retStorage] =
                   (short)psVar9;
            }
          }
        }
      }
    }
    retStorage = (uint32_t *)((int)retStorage + 1);
  } while( true );
switchD_3000_4a6e_caseD_3:
  do {
    *(int *)(&stk_d744 + row) = *(int *)(&stk_d744 + row) + in_CX;
    uStack_28 = constr_compute2((uint8_t)uStack_20,(uint8_t)uStack_22,(uint8_t)puStack_1c,
                                (byte)psVar9,unaff_DI);
    uStack_28 = uStack_28 & 0xff;
    ovr_ovc07_usesBiosReadKey(((uint16_t *)SquareLeftX)[(int)retStorage],0,0,0,0,0,0,0,0,0,0,0,0,0);
    uVar17 = constr_compute2((uint8_t)puStack_1c,(uint8_t)pvStack_1e,(uint8_t)uStack_22,bStack_2b,2)
    ;
    puStack_2a = (uint32_t *)(uVar17 & 0xff);
    ovr_ovc07_usesBiosReadKey(((uint16_t *)SquareRightX)[(int)retStorage],0,0,0,0,0,0,0,0,0,0,0,0,0);
    while( true ) {
      uVar17 = ovr_constr_usesGMapFlags(uStack_24 + GfxRndSeed,0,0);
      if ((char)uVar17 != '\0') {
        ovr_ovc07_usesLDIV_at_
                  (((uint16_t *)SquareLeftX)[(int)retStorage],RowScreenY[0] - uStack_10,0,0,0,0,0)
        ;
      }
      do {
        retStorage = (uint32_t *)((int)retStorage + 1);
        randPick = rowBandSquareFirst[0];
        if ((int)rowBandSquareEnd[0] <= (int)retStorage) {
          for (; (int)randPick < (int)rowBandSquareEnd[0]; randPick = randPick + 1) {
            uStack_24 = ((uint16_t *)squareColumn)[randPick];
            bVar4 = ovr_constr_setHighlightAtOffset(uStack_24,0,0);
            fileIdx = CONCAT11(extraout_AH_00,bVar4);
            if ((*(byte *)((uint8_t *)&BuildingTypes[fileIdx] + 16) & 2) != 0) {
              iVar15 = ovr_constr_usesSmoothPrev(uStack_24,0,0,0,0);
              uStack_10 = iVar15 / 3;
              (*(uint8_t *)((uint8_t *)&(gfx.seg))) =
                   (char)*(uint16_t *)((char *)0x28ed6 + fileIdx * 0xc);
              gfx.ofs = *(uint16_t *)(uint16_t *)((char *)0x28ed4 + fileIdx * 0xc);
              (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) =
                   (char)((uint)*(uint16_t *)(uint16_t *)((char *)0x28ed6 + fileIdx * 0xc) >> 8);
              ovr_blit_usesBlitGfxN
                        (gfx,((uint16_t *)SquareLeftX)[randPick],rowBandOrigin[0] - uStack_10,6,0,0,0,0,0,0,0,0,0,0,0);
            }
            if ((*(byte *)((uint8_t *)&BuildingTypes[fileIdx] + 16) & 1) != 0) {
              gfx_00.seg = *(uint16_t *)(uint16_t *)((char *)0x28eda + fileIdx * 0xc);
              gfx_00.ofs = *(uint16_t *)(uint16_t *)((char *)0x28ed8 + fileIdx * 0xc);
              ovr_blitGfxRect(gfx_00,((uint16_t *)SquareLeftX)[randPick],0,0,0,0,0,0,0,0,0,0);
            }
          }
          return (stg_tmp_t *)((char *)0x26510);
        }
      } while (((int)((uint16_t *)SquareRightX)[(int)retStorage] < 0xef) ||
              (0x134 < (int)((uint16_t *)SquareLeftX)[(int)retStorage]));
      uStack_24 = ((uint16_t *)squareColumn)[(int)retStorage];
      puStack_1c = (uint32_t *)constr_getCellAtOffset(uStack_24,-2);
      pvStack_1e = (void *)constr_getCellAtOffset(uStack_24 + 1,-2);
      sample = ovr_constr_usesSmoothPrev(uStack_24,0,0,0,0);
      uStack_10 = sample / 3;
      sample = ovr_constr_usesSmoothPrev(uStack_24 + 1,0,0,0,0);
      sampleHi = sample / 3;
      psVar9 = (stg_tmp_t *)constr_getFlagsAtOffset(uStack_24,-1);
      bStack_2b = (byte)psVar9;
      if (((uint)psVar9 & 4) != 0) break;
      uStack_28 = constr_compute2((uint8_t)uStack_20,(uint8_t)uStack_22,(uint8_t)pvStack_1e,
                                  (byte)psVar9,2);
      uStack_28 = uStack_28 & 0xff;
      ovr_ovc07_usesBiosReadKey(((uint16_t *)SquareLeftX)[(int)retStorage],0,0,0,0,0,0,0,0,0,0,0,0,0);
      uVar17 = constr_compute2((uint8_t)puStack_1c,(uint8_t)pvStack_1e,(uint8_t)uStack_20,bStack_2b,
                               1);
      puStack_2a = (uint32_t *)(uVar17 & 0xff);
      ovr_ovc07_usesBiosReadKey(((uint16_t *)SquareLeftX)[(int)retStorage],0,0,0,0,0,0,0,0,0,0,0,0,0);
    }
    unaff_DI = 1;
  } while( true );
L_grabLbm_0445:
  iVar15 = ovr_stshRead();
  if (iVar15 != 0 || uVar17 != 0) {
bad_lbm:
    randPick = fStack_30.seg;
    psVar9 = (stg_tmp_t *)fStack_30.ofs;
    if ((&psVar9->bptr)->ofs != 0 || (psVar9->bptr).seg != 0) {
      bptrSeg = (psVar9->bptr).seg;
      (*(uint8_t *)((uint8_t *)&(handle_00.seg))) = (char)bptrSeg;
      handle_00.ofs = (&psVar9->bptr)->ofs;
      (*(uint8_t *)((uint8_t *)&(handle_00.seg) + 1)) = (char)(bptrSeg >> 8);
      ovr_stshFree(handle_00);
    }
    ovr_stshClose((uint16_t)retStorage);
    ovr_stshFree(fStack_30);
    printf("Filename %d %s  \r");
    ovr_biosReadKey();
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0xd);
  }
  if ((uStack_20 == uStack_c) && (uStack_22 == fileIdx)) {
    ok = '\x01';
    uVar17 = uStack_22;
    iVar15 = ovr_stshRead();
    if ((((iVar15 != 0 || uVar17 != 0) ||
         (puStack_2a = ovr_be4(puStack_2a), uStack_28 = uVar17, uVar17 != 0)) ||
        (puStack_2a != (uint32_t *)((byte *)__C0_ASM_CopyRight + 0x10))) ||
       (iVar15 = ovr_stshRead(), iVar15 != 0 || uVar17 != 0)) goto bad_lbm;
    beWordA = ovr_be2(uStack_48);
    beWordB = ovr_be2(uStack_46);
    goto L_grabLbm_0445;
  }
  if ((uStack_20 == accum) && (uStack_22 == uStack_16)) {
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
        ovr_stshTell(retStorage,unaff_SI);
        ovr_stshSeek((uint16_t)retStorage);
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
    if ((uStack_20 == uStack_10) && (uStack_22 == sampleHi)) {
      if (ok != '\0') {
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
        ovr_stshClose((uint16_t)retStorage);
        uStackY_be = CONCAT11(uVar10,bStack_2b);
        uStackY_c0 = 0x2337;
        uStackY_c2 = 0x152a;
        src.seg = fStack_30.ofs;
        src.ofs = (uint16_t)puStack_1c;
        lbm_decode_body(lStack_3e,iStack_40,uStack_3f,(uint8_t)pvStack_1e,src,
                        (stg_tmp_t *)
                        CONCAT13((char)((ulong)in_stack_00000004 >> 0x18),
                                 CONCAT12((char)((ulong)in_stack_00000004 >> 0x10),fStack_30.seg)),
                        in_stack_00000008,beWordA,beWordB,unaff_SI);
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
      carry = (uint32_t *)0xfffe < puStack_26;
      puStack_26 = (uint32_t *)((int)puStack_26 + 1);
      uStack_24 = uVar17 + carry;
    }
    puVar6 = ovr_stshTell(retStorage,unaff_SI);
    uVar17 = ((int)puVar6 >> 0xf) + uStack_24 + (uint)CARRY2((uint)puVar6,(uint)puStack_26);
    ovr_stshSeek((uint16_t)retStorage);
  }
  goto L_grabLbm_0445;
}


/* 3381:1697 */

/* Initialises the 0xf8 GUnits records (bldType = index, level/unitType = 0xff). */

void __cdecl16far init_initGUnits(void)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 0xf8; iVar1 = iVar1 + 1) {
    (GUnits + iVar1)->bldType = (byte)iVar1;
    (GUnits)[iVar1].level = 0xff;
    (GUnits)[iVar1].unitType = 0xff;
  }
  return;
}



/* 3381:16ef */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far init_buffers(void)

{
  
  GUnits = ovr_stshAlloc(0x2a30);
  _fsetmem(GUnits, 0x2a30, 0);
  init_initGUnits();
  GUnitCount = 0xf8;
  GUnitGrid = ovr_stshAlloc(0x4560);
  GMapFlags = ovr_stshAlloc(0x4560);
  GMapCells = ovr_stshAlloc(0x22b0);
  Entities = ovr_stshAlloc(33000);
  FillGrid = (uint32_t)ovr_stshAlloc(0x6541);
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
  int topY;
  int colDown;
  uint sqColUp;
  uint16_t sqColDown;
  uint8_t scaleRow[10];
  uint yOffset;
  uint xOffset;
  char row;
  uint colUp;
  int mapTopY;
  int mapLeftX;
  int leftX;
  uint yStep;
  uint xStep;
  
  dst.seg = _SS;
  dst.ofs = (uint16_t)&scaleRow;
  F_SCOPY(far_from_u32((uint32_t)(0x241004e8)),dst,10);
  GMaxSquare = 0;
  row = '\b';
  do {
    if (row < '\0') {
      if (GMaxSquare != 0x1b0) {
        printf((char *)s_new_maxsquare_d);
        ovr_gameProcessKey();
      }
      GSMaxSquare = 0;
      row = '\x02';
      do {
        if (row < '\0') {
          if (GSMaxSquare != 0x24) {
            printf((char *)s_new_smaxsquare_d);
            ovr_gameProcessKey();
          }
          return;
        }
        ((uint16_t *)rowBandSquareFirst)[row] = GSMaxSquare;
        xStep = ((uint)scaleRow[row + -1] * 0x30) / 0x30;
        yStep = ((uint)scaleRow[row] * 0x30) / 0x30;
        ((uint16_t *)RowScreenX)[row] =
             (uint)*(byte *)(row + 0x74c) + ((uint)scaleRow[row] * 0x3c) / 0x30;
        ((uint16_t *)RowScreenY)[row] =
             (uint)*(byte *)(row + 0x74b) + ((uint)scaleRow[row + -1] * 0x3c) / 0x30;
        yOffset = ((uint)scaleRow[row + -1] * 0x27) / 0x30;
        xOffset = ((uint)scaleRow[row] * 0x27) / 0x30;
        leftX = 0x111 - yOffset;
        sqColUp = 0;
        for (topY = 0x111 - xOffset; 0xee < (int)((topY - yStep) + xOffset + yStep);
            topY = topY - yStep) {
          leftX = leftX - xStep;
          sqColUp = sqColUp - 1;
        }
        for (; 0x7fff < sqColUp; sqColUp = sqColUp + 1) {
          if (0x23 < (int)GSMaxSquare) {
                    /* WARNING: Subroutine does not return */
            ovr_stExit(8);
          }
          ((uint16_t *)SquareTopY)[GSMaxSquare] = topY + xOffset;
          ((uint16_t *)SquareBottomY)[GSMaxSquare] =
               ((uint16_t *)SquareTopY)[GSMaxSquare] + yStep;
          ((uint16_t *)SquareLeftX)[GSMaxSquare] = leftX + yOffset;
          ((uint16_t *)SquareRightX)[GSMaxSquare] =
               ((uint16_t *)SquareLeftX)[GSMaxSquare] + xStep;
          ((uint16_t *)squareColumn)[GSMaxSquare] = sqColUp;
          if ((int)sqColUp < -1) {
            ((uint16_t *)squareSide)[GSMaxSquare] = 0;
          }
          else {
            ((uint16_t *)squareSide)[GSMaxSquare] = 1;
          }
          GSMaxSquare = GSMaxSquare + 1;
          leftX = leftX + xStep;
          topY = topY + yStep;
        }
        leftX = 0x111 - yOffset;
        sqColDown = 0;
        for (topY = 0x111 - xOffset; (int)(yStep + topY + xOffset) < 0x135;
            topY = topY + yStep) {
          leftX = leftX + xStep;
          sqColDown = sqColDown + 1;
        }
        for (; -1 < (int)sqColDown; sqColDown = sqColDown - 1) {
          if (0x23 < (int)GSMaxSquare) {
                    /* WARNING: Subroutine does not return */
            ovr_stExit(8);
          }
          ((uint16_t *)SquareTopY)[GSMaxSquare] = topY + xOffset;
          ((uint16_t *)SquareBottomY)[GSMaxSquare] =
               ((uint16_t *)SquareTopY)[GSMaxSquare] + yStep;
          ((uint16_t *)SquareLeftX)[GSMaxSquare] = leftX + yOffset;
          ((uint16_t *)SquareRightX)[GSMaxSquare] =
               ((uint16_t *)SquareLeftX)[GSMaxSquare] + xStep;
          ((uint16_t *)squareColumn)[GSMaxSquare] = sqColDown;
          if ((int)sqColDown < 1) {
            ((uint16_t *)squareSide)[GSMaxSquare] = 1;
          }
          else {
            ((uint16_t *)squareSide)[GSMaxSquare] = 2;
          }
          GSMaxSquare = GSMaxSquare + 1;
          leftX = leftX - xStep;
          topY = topY - yStep;
        }
        ((uint16_t *)rowBandSquareEnd)[row] = GSMaxSquare;
        row = row + -1;
      } while( true );
    }
    ((uint16_t *)rowMapSquareFirst)[row] = GMaxSquare;
    xStep = ((uint)scaleRow[row + -1] * 0x30) / 0x10;
    yStep = ((uint)scaleRow[row] * 0x30) / 0x10;
    ((uint16_t *)ScreenOriginX)[row] =
         (uint)*(byte *)(row + 0x729) + ((uint)scaleRow[row] * 0x38) / 0x10;
    ((uint16_t *)ScreenOriginY)[row] =
         (uint)*(byte *)(row + 0x728) + ((uint)scaleRow[row + -1] * 0x38) / 0x10;
    yOffset = ((uint)scaleRow[row + -1] * 0x27) / 0x10;
    xOffset = ((uint)scaleRow[row] * 0x27) / 0x10;
    mapLeftX = 0x75 - yOffset;
    colUp = 0;
    for (mapTopY = 0x75 - xOffset; 0xb < (int)((mapTopY - yStep) + xOffset + yStep);
        mapTopY = mapTopY - yStep) {
      mapLeftX = mapLeftX - xStep;
      colUp = colUp - 1;
    }
    *(uint *)(row * 2 + -0x73ed) = colUp;
    leftX = 0x75 - yOffset;
    colDown = 0;
    for (topY = 0x75 - xOffset; (int)(yStep + topY + xOffset) < 0xdf;
        topY = topY + yStep) {
      leftX = leftX + xStep;
      colDown = colDown + 1;
    }
    *(int *)(row * 2 + -0x73ff) = colDown;
    while ((0x7fff < colUp || (-1 < colDown))) {
      if ((int)colUp < 0) {
        if (0x1af < (int)GMaxSquare) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(7);
        }
        *(int *)((int)&AgntAnms[0x5d].sx + 1 + GMaxSquare * 2) = mapTopY + xOffset;
        *(int *)(&mapSquareBottomY[GMaxSquare]) =
             *(int *)((int)&AgntAnms[0x5d].sx + 1 + GMaxSquare * 2) + yStep;
        *(int *)(&mapSquareLeftX[GMaxSquare]) = mapLeftX + yOffset;
        *(int *)(&mapSquareRightX[GMaxSquare]) = *(int *)(&mapSquareLeftX[GMaxSquare]) + xStep;
        *(uint *)(&mapSquareColumn[GMaxSquare]) = colUp;
        if ((int)colUp < -1) {
          *(uint16_t *)(GMaxSquare * 2) = 0;
        }
        else {
          *(uint16_t *)(GMaxSquare * 2) = 1;
        }
        GMaxSquare = GMaxSquare + 1;
        mapLeftX = mapLeftX + xStep;
        mapTopY = mapTopY + yStep;
        colUp = colUp + 1;
      }
      if (-1 < colDown) {
        if (0x1af < (int)GMaxSquare) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(7);
        }
        *(int *)((int)&AgntAnms[0x5d].sx + 1 + GMaxSquare * 2) = topY + xOffset;
        *(int *)(&mapSquareBottomY[GMaxSquare]) =
             *(int *)((int)&AgntAnms[0x5d].sx + 1 + GMaxSquare * 2) + yStep;
        *(int *)(&mapSquareLeftX[GMaxSquare]) = leftX + yOffset;
        *(int *)(&mapSquareRightX[GMaxSquare]) = *(int *)(&mapSquareLeftX[GMaxSquare]) + xStep;
        *(int *)(&mapSquareColumn[GMaxSquare]) = colDown;
        if (colDown < 1) {
          *(uint16_t *)(GMaxSquare * 2) = 1;
        }
        else {
          *(uint16_t *)(GMaxSquare * 2) = 2;
        }
        GMaxSquare = GMaxSquare + 1;
        leftX = leftX - xStep;
        topY = topY - yStep;
        colDown = colDown + -1;
      }
    }
    ((uint16_t *)rowMapSquareEnd)[row] = GMaxSquare;
    row = row + -1;
  } while( true );
}



/* 3381:1f1d */

/* [R6] touches GMapCells */

uint __cdecl16far init_usesGMapCells(int x,int y)

{
  /* Re-derived (3381:1f1d): 0 when the cell at (x,y) or the two cells checked beside it are
     empty, otherwise 1.  The tail writes only AL (mov al,1 at 0x275AF, mov al,0 at
     0x275B3), so the exported `& 0xff00` / CONCAT11 returns were stale-AH artifacts.  The
     export repeats the `rowPtr[1][x] == 0` clause twice; it is idempotent and kept once. */
  byte (*rowPtr) [148];
  byte (*cells) [59] [148];

  rowPtr = (byte (*) [148])(y * 0x94);
  cells = (byte (*) [59] [148])GMapCells;
  if (((((*cells)[0][(int)(*rowPtr + x)] == 0) ||
       (rowPtr = (byte (*) [148])(y * 0x94),
        (*cells)[0][(int)(*rowPtr + x + 1)] == 0)) ||
      (rowPtr = *cells + y, rowPtr[1][x] == 0))) {
    return 0;
  }
  return 1;
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
  uVar1 = ovr_randBelow(3,0);
  uVar1 = (uVar1 & 0xff) * 3;
  seasonGroupBase = (undefined1)uVar1;
  if (GameRunning == false) {
    uVar2 = ovr_randBelow(0x14,0);
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
  _fmemset(MK_FP(_DS, (uint16_t)&promotionBandUsed), 0, 2);
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
  ovr_calcSeasonPalette(srcOfs->cmap,uVar1,palette,_SS,0,0);
  if (GameRunning == false) {
    ovr_vgaSetPalette8bit(palette,0);
  }
  ovr_manage_mapPartySlots();
  return;
}



/* 3381:233e */

/* Returns the GMapCells[y][x] byte inside the map bounds, else 0. */

uint __cdecl16far init_getMapCell(int x,int y,uint16_t arg3)

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
  
  uVar1 = init_getMapCell(x,y,0);
  uVar1 = uVar1 & 0xff;
  uVar2 = init_getMapCell(x + 1,y,0);
  iVar3 = uVar1 + (uVar2 & 0xff);
  uVar1 = init_getMapCell(x,y + 1,0);
  iVar3 = iVar3 + (uVar1 & 0xff);
  uVar1 = init_getMapCell(x + 1,y + 1,0);
  return iVar3 + (uVar1 & 0xff);
}



/* 3381:2452 */

/* [R7] body shape: compute */

uint16_t __cdecl16far init_compute2(int x,int y,byte direction)

{
  /* 3381:2452 (file 0x27AC0 / 0x27ACD), re-derived: the original ends with `mov al,0`
     and `mov al,1`, so the result is a boolean.  The exported `in_AX` pseudo-register was
     reused for the loop index, the direction comparison and the getMapFlags result, and
     both returns took their high byte from it (`CONCAT11((char)(in_AX >> 8),1)` /
     `in_AX & 0xff00`). */
  byte d;

  for (d = 0; d < 4; d = d + 1) {
    if ((d != (direction ^ 2)) &&
        ((char)init_getMapFlags(x + *(char *)(d + 0x885),y + *(char *)(d + 0x889)) != '\0')) {
      return 0;
    }
  }
  return 1;
}



/* 3381:24c3 */

/* [R4] calls ovr_randBelow */

uint16_t __cdecl16far
init_usesRandBelow(int16_t x,int16_t y,uint8_t dir,uint8_t *lastDir,uint8_t *sameDirCount)

{
  uint8_t uVar1;
  byte bVar2;
  int iVar3;
  uint16_t uVar4;
  undefined1 uVar7;
  uint uVar5;
  uint uVar6;
  uint16_t in_stack_00000010;
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
  uVar4 = ovr_randBelow(4,0);
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
  /* Re-derived: sets bit 0x1 or 0x2 in the cell's map-flags word according to which of the
     three neighbouring GMapCells are empty; the cell's own 0x4 flag selects which pair is
     tested against which neighbour.  The exported segment half (uVar4) and the paasVar2 /
     paabVar3 cast aliases were dead. */
  uint16_t *flagWord;

  if (((*(short (*) [60] [148])GMapFlags)[y][x] & 4U) == 0) {
    if (((*(byte (*) [59] [148])GMapCells)[y][x] == 0) &&
        ((*(byte (*) [59] [148])GMapCells)[y + 1][x + 1] == 0) &&
        ((*(byte (*) [59] [148])GMapCells)[y + 1][x] == 0)) {
      flagWord = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y] + x);
      *flagWord = *flagWord | 1;
    }
    if (((*(byte (*) [59] [148])GMapCells)[y][x] == 0) &&
        ((*(byte (*) [59] [148])GMapCells)[y + 1][x + 1] == 0) &&
        ((*(byte (*) [59] [148])GMapCells)[y][x + 1] == 0)) {
      flagWord = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y] + x);
      *flagWord = *flagWord | 2;
    }
  }
  else {
    if (((*(byte (*) [59] [148])GMapCells)[y + 1][x] == 0) &&
        ((*(byte (*) [59] [148])GMapCells)[y][x + 1] == 0) &&
        ((*(byte (*) [59] [148])GMapCells)[y][x] == 0)) {
      flagWord = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y] + x);
      *flagWord = *flagWord | 1;
    }
    if (((*(byte (*) [59] [148])GMapCells)[y + 1][x] == 0) &&
        ((*(byte (*) [59] [148])GMapCells)[y][x + 1] == 0) &&
        ((*(byte (*) [59] [148])GMapCells)[y + 1][x + 1] == 0)) {
      flagWord = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y] + x);
      *flagWord = *flagWord | 2;
    }
  }
  return;
}



/* 3381:2883 */

/* [R4] calls ovr_randBelow */

void __cdecl16far init_usesRandBelow2(void)

{
  /* Re-derived (3381:2883).  The flag writes go through uint16_t* - the original is
     `or word ptr es:[bx], 3` at 0x0280F2 - not the export's `uint *`, which writes four
     bytes and would corrupt the adjacent cell.  The two byte writes that built dst.seg from
     _SS are simply `dst.seg = _SS`, and the two dead segment copies are gone. */
  uint16_t *flagWordPtr;
  far_t dst;
  far_t dst_00;
  uint16_t randVal;
  uint16_t cellValue;
  int cellY;
  byte (*cells) [59] [148];
  short (*flags) [60] [148];
  uint x;
  uint y;
  uint8_t edgeMasks;
  byte dir;
  byte prevDir;
  int featureIdx;
  uint8_t sameDirCount;
  uint8_t lastDir;
  byte cellMin;
  byte cellByte;
  uint8_t minCell;
  uint8_t neighbourOfs;
  byte dirTable [7];

  dst.seg = _SS;
  dst.ofs = (uint16_t)&edgeMasks;
  F_SCOPY(far_from_u32((uint32_t)(0x241004f2)),dst,16);
  dst_00.seg = _SS;
  dst_00.ofs = (uint16_t)&neighbourOfs;
  F_SCOPY(far_from_u32((uint32_t)(0x24100502)),dst_00,8);
  featureIdx = 0;
  do {
    if ((int)(uint)randomFeatureCount <= featureIdx) {
      return;
    }
    randVal = ovr_randBelow(0x93,0);
    x = randVal & 0xff;
    randVal = ovr_randBelow(0x3b,0);
    y = randVal & 0xff;
    minCell = 100;
    cellValue = init_getMapCell(x,randVal & 0xff,(char)randVal);
    cellByte = (byte)cellValue;
    if (cellByte < minCell) {
      minCell = cellByte;
    }
    cellValue = init_getMapCell(x + 1,randVal & 0xff,(char)randVal);
    cellByte = (byte)cellValue;
    if (cellByte < minCell) {
      minCell = cellByte;
    }
    cellValue = init_getMapCell(x,y + 1,(char)(y + 1));
    cellByte = (byte)cellValue;
    if (cellByte < minCell) {
      minCell = cellByte;
    }
    cellValue = init_getMapCell(x + 1,y + 1,(char)(y + 1));
    cellByte = (byte)cellValue;
    if (cellByte < minCell) {
      minCell = cellByte;
    }
    init_setMapCell(x,y,minCell);
    init_setMapCell(x + 1,y,minCell);
    init_setMapCell(x,y + 1,minCell);
    init_setMapCell(x + 1,y + 1,minCell);
    if (minCell == 0) {
      init_usesGMapFlags3(x,randVal & 0xff);
      init_usesGMapFlags3(x - 1,randVal & 0xff);
      init_usesGMapFlags3(x + 1,randVal & 0xff);
      init_usesGMapFlags3(x,y - 1);
      init_usesGMapFlags3(x,y + 1);
    }
    lastDir = 0x0;
    sameDirCount = 0x0;
    randVal = ovr_randBelow(4,0);
    prevDir = (byte)randVal;
    for (; ((((int)x < 0x93 && (-1 < (int)x)) && ((int)y < 0x3b)) && (-1 < (int)y));
        y = y + (int)*(char *)(dir + 0x889)) {
      cells = (byte (*) [59] [148])GMapCells;
      if ((((*cells)[y][x] == 0) && ((*cells)[y][x + 1] == 0)) &&
         (((*cells)[y + 1][x] == 0 && ((*cells)[y + 1][x + 1] == 0)))) break;
      flags = (short (*) [60] [148])GMapFlags;
      if (((*flags)[y][x] & 3U) == 3) break;
      if (((*flags)[y][x] & 3U) != 0) {
        flagWordPtr = (uint16_t *)((*flags)[y] + x);
        *flagWordPtr = *flagWordPtr | 3;
      }
      randVal = init_usesRandBelow(x,y,prevDir,&lastDir,
                                   (uint8_t *)CONCAT22(&sameDirCount,_SS));
      dir = (byte)randVal;
      if (((dir == 0xff) || (prevDir == (dir ^ 2))) ||
         ((&edgeMasks)[(uint)prevDir * 4 + (randVal & 0xff)] == 0x0)) break;
      flagWordPtr = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y] + x);
      *flagWordPtr = *flagWordPtr & 0xfffb;
      flagWordPtr = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[y] + x);
      *flagWordPtr = *flagWordPtr | (uint)(&edgeMasks)[(uint)prevDir * 4 + (randVal & 0xff)];
      cellY = y + ((int)(uint)dirTable[(uint)prevDir * 2 + -1] >> 1);
      cellValue = init_getMapCell(x + (dirTable[(uint)prevDir * 2 + -1] & 1),cellY,(char)cellY);
      cellByte = (byte)cellValue;
      cellY = y + ((int)(uint)dirTable[(uint)prevDir * 2] >> 1);
      cellValue = init_getMapCell(x + (dirTable[(uint)prevDir * 2] & 1),cellY,(char)cellY);
      cellMin = (byte)cellValue;
      if (cellByte < minCell) {
        minCell = cellByte;
      }
      if (cellMin < minCell) {
        minCell = cellMin;
      }
      init_setMapCell(x + (dirTable[(uint)dir * 2 + -1] & 1),
                      y + ((int)(uint)dirTable[(uint)dir * 2 + -1] >> 1),minCell);
      init_setMapCell(x + (dirTable[(uint)dir * 2] & 1),
                      y + ((int)(uint)dirTable[(uint)dir * 2] >> 1),minCell);
      if (minCell == 0) {
        init_usesGMapFlags3(x,y);
        init_usesGMapFlags3(x - 1,y);
        init_usesGMapFlags3(x + 1,y);
        init_usesGMapFlags3(x,y - 1);
        init_usesGMapFlags3(x,y + 1);
      }
      x = x + (int)*(char *)(dir + 0x885);
      prevDir = dir;
    }
    featureIdx = featureIdx + 1;
  } while( true );
}



/* 3381:2d36 */

/* Rebuilds the four direction bits for every map cell. */

void __cdecl16far init_rebuildAllDirectionFlags(void)

{
  uint16_t *flagPtr;
  uint *slotUsed;
  uint16_t unitIndex;
  int x;
  byte dir;
  
  for (x = 0; x < 0x94; x = x + 1) {
    for (unitIndex = 0; (int)unitIndex < 0x3c; unitIndex = unitIndex + 1) {
      for (dir = 0; dir < 4; dir = dir + 1) {
        slotUsed = ovr_ovc23_usesAlignUp43(x,unitIndex,dir);
        if ((char)slotUsed != '\0') {
          flagPtr = (uint16_t *)((*(short (*) [60] [148])GMapFlags)[unitIndex] + x);
          *flagPtr = *flagPtr | 0x10 << (dir & 0x1f);
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
  far_t dst;
  far_t handle;
  char buf [12];
  stg_tmp_t *pgfx;
  
  dst.seg = _SS;
  dst.ofs = (uint16_t)buf;
  F_SCOPY(far_from_u32((uint32_t)(0x2410050e)),dst,11);
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
  uint16_t uVar3;
  uint8_t uVar4;
  far_t handle;
  static char msg[64];   /* DGROUP-backed formatting buffer */
  uint16_t input;
  byte *pbStack_a;
  char *uStack_8;   /* hand fix: *uStack_8 deref */
  uint8_t attempts;
  uint8_t codes;
  
  if (CopyProtectionDone == '\0') {
    uVar1 = ovr_randBelow(0x19,0);
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
      pcVar2 = ovr_stsprintf(msg,(char *)CONCAT22(0x6cd,_SS),
                             (char *)(ulong)CONCAT12(*(undefined1 *)(codes + 0x51a),0x2410));
      ovr_blitText(pcVar2,(byte *)CONCAT22(uVar1,in_DX),uVar3,uVar4);
      TextBlitX = 0x16;
      TextBlitY = 0x43;
      uVar4 = 0xde;
      uVar1 = Font03.ofs;
      uVar3 = Font03.seg;
      pcVar2 = ovr_stsprintf(msg,(char *)CONCAT22(0x6ed,_SS),
                             (char *)(ulong)CONCAT12(*(undefined1 *)(codes + 0x533),0x2410));
      ovr_blitText(pcVar2,(byte *)CONCAT22(uVar1,in_DX),uVar3,uVar4);
      TextBlitX = 0x16;
      TextBlitY = 0x57;
      ovr_blitText((char *)(char *)s_enter_the_first_word,
                   (byte *)CONCAT22(Font03.ofs,(char *)0x26510),Font03.seg,0xde);
      pbStack_a = (byte *)0x0;
      input = 0;
      pcVar2 = ovr_stshAlloc(2);
      uStack_8 = (char *)CONCAT22(in_DX,pcVar2);
      *uStack_8 = *(char *)*(uint32_t *)((uint)codes * 4 + 0x54c);
      pcVar2[1] = '\0';
      input = (uint16_t)ovr_uiReadString((char *)0x0,0,6,pcVar2,(uint16_t)in_DX,0);
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
              (char *)CONCAT22(*(uint16_t *)((uint)codes * 4 + 0x54e),
                               (char *)*(uint16_t *)((uint)codes * 4 + 0x54c)));
    handle.seg = (uint16_t)pbStack_a;
    handle.ofs = input;
    ovr_stshFree(handle);
    ovr_saveui_blitPanel();
    CopyProtectionDone = '\x01';
  }
  return;
}

