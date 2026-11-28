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
  /* Re-derived from 3381:01c8 (116 bytes), call by call:

       0x01cb  getcwd(GOriginalDir, 0x44)          lcall 0,0x2568
       0x01db  strcpy(GWorkDir, GOriginalDir)      lcall 0,0x2d31
       0x01ef  ensure_tail_slash(GWorkDir)         call  3381:0132
       0x01fc  strcat(GWorkDir, "strong.sav\\")    lcall 0,0x2cc2, src _DS:0x5b0
       0x020e  append_name_to_path(GGameExe, "%sgame.cfg")   call 3381:009a, name _DS:0x5bb
       0x0228  path_strip_tail_slash(<that result>)          call 3381:00fe
       0x0231  chpath(<that result>)                         call 3381:016c

     The buffers are the two named DGROUP areas the image addresses: the cwd buffer at
     0x8c28 (`GOriginalDir`, 68 bytes -- the size passed to getcwd) and the work buffer at
     0x8c6c (`GWorkDir`, 80 bytes).  The earlier body had replaced both with `""` string
     literals, which made getcwd write 68 bytes over a constant.

     The three path helpers were exported with a separate `uint16_t arg2` that they fold back
     into a far pointer with CONCAT22, so each call passes the data segment for it. */
  getcwd((char *)GOriginalDir,68);
  strcpy((char *)GWorkDir,(char *)GOriginalDir);
  ensure_tail_slash((char *)GWorkDir,(uint16_t)_DS);
  strcat((char *)GWorkDir,"strong.sav\\");
  chpath(path_strip_tail_slash(
             append_name_to_path((char far *)MK_FP(GGameExe.seg,GGameExe.ofs),
                                 (char far *)"%sgame.cfg"),(uint16_t)_DS),
         (uint16_t)_DS);
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

/* Terrain generation for one map.  The tree's name is a misnomer (kept to avoid churning the overlay
   thunk table): this is the map builder, called from 3381:2101 during init.

   Verified against tmp/o09_08dc.txt, 1,290 instructions, 60 calls: 43 ovr_randBelow,
   6 constr_usesGMapFlags, 2 constr_usesGMapFlags2, 2 _fsetmem, 6 near
   (init_rebuildMapFlags x2, init_usesRandBelow2, init_getMapFlags x2, init_rebuildAllDirectionFlags).
   The three grids are three views of one 60x148 map: GMapCells signed bytes (stride 148),
   GMapFlags words, GUnitGrid words transposed (GUnitGrid[col][row], stride 60). */
void __cdecl16far init_textFilename(void)

{
  signed char profile[0x94];
  uint16_t row;
  uint16_t col;
  int16_t nb;
  int16_t d;
  int16_t h;
  int16_t dy;
  int16_t spread;
  uint16_t r;
  uint16_t i;
  uint16_t hasNb;
  signed char v;
  uint16_t idx;
  uint8_t bld;

  /* 1. height profile: a random walk clamped to [-1,1], flat at both ends. */
  v = 0;
  for (i = 0; i < 0x94; i++) {
    if ((uint16_t)ovr_randBelow(10) == 0) {
      v = (signed char)((int)v + (int)(uint16_t)ovr_randBelow(2) * 2 - 1);
      if (v < -1) {
        v = -1;
      }
      if (v > 1) {
        v = 1;
      }
    }
    if (i == 0 || i == 0x93) {
      v = 0;
    }
    profile[i] = v;
  }

  /* 2. both auxiliary grids start empty (0x4560 bytes = 148*60*2). */
  _fsetmem(GUnitGrid,0x4560,0);
  _fsetmem(GMapFlags,0x4560,0);

  /* 3. height synthesis: mirrored rows, a drifting random walk with a reflecting clamp. */
  dy = 0;
  for (row = 0; row < 0x3c; row++) {
    d = (row & 1) ? -1 : 1;
    col = (row & 1) ? 0x93 : 0;
    for (;;) {
      nb = (int16_t)col + d;
      hasNb = (uint16_t)(nb >= 0 && nb <= 0x93);
      h = hasNb ? (int16_t)(signed char)GMapCells[row][nb] : 0;
      if (row != 0) {
        h = (int16_t)(h + profile[col] + (int16_t)(signed char)GMapCells[row - 1][col]);
      }
      h = (int16_t)(h >> 1);

      if (hasNb && profile[nb] != profile[col]) {
        r = (uint16_t)ovr_randBelow((row & 1) ? 0x10 : 8);
        if (r == 1) {
          profile[col] = profile[nb];
        }
        else if (r == 2) {
          profile[nb] = profile[col];
        }
      }

      if ((uint16_t)ovr_randBelow(0x10) == 0) {
        if (hasNb) {
          v = (signed char)((int)profile[nb] + (int)(uint16_t)ovr_randBelow(2) * 2 - 1);
          if (v < -1) {
            v = -1;
          }
          if (v > 1) {
            v = 1;
          }
          profile[col] = v;
        }
        if (h > 0x55) {
          dy = (int16_t)((uint16_t)ovr_randBelow(0x11) - 8);
        }
        else if (h > 0x40) {
          dy = (int16_t)((uint16_t)ovr_randBelow(8) - 4);
        }
        else if (h > 0x2a) {
          dy = (int16_t)((uint16_t)ovr_randBelow(0xb) - 5);
        }
        else if (h > 0x15) {
          dy = (int16_t)((uint16_t)ovr_randBelow(0x10) - 8);
        }
        else if (h > 0) {
          dy = (int16_t)((uint16_t)ovr_randBelow(8) - 5);
        }
        else {
          dy = (int16_t)((uint16_t)ovr_randBelow(9) - 2);
        }
      }

      /* the spread ladder is a different shape from the dy ladder. */
      if (h > 0x55) {
        spread = 9;
      }
      else if (h > 0x40) {
        spread = 0x13;
      }
      else if (h > 0x2a) {
        spread = 5;
      }
      else if (h > 0x15) {
        spread = 0xf;
      }
      else if (h > 0) {
        spread = 5;
      }
      else {
        spread = 0xb;
      }

      h = (int16_t)(h + ((int16_t)(uint16_t)ovr_randBelow(spread) - (spread >> 1) + dy + 1));
      if (h < -0x23) {
        h = -0x23;
        dy = (int16_t)(dy < 0 ? -dy : dy);
      }
      if (h > 0x7f) {
        h = 0x7f;
        dy = (int16_t)(-(dy < 0 ? -dy : dy));
      }
      GMapCells[row][col] = (byte)h;

      if ((d > 0 && col == 0x93) || (d < 0 && col == 0)) {
        break;
      }
      col = (uint16_t)(col + d);
    }
  }

  init_rebuildMapFlags();
  init_usesRandBelow2();
  init_rebuildMapFlags();

  /* 5. terrain typing into the transposed GUnitGrid, per height band. */
  for (row = 0; row < 0x3b; row++) {
    for (col = 0; col < 0x93; col++) {
      if (GMapCells[row][col] == 0) {
        continue;
      }
      if (GMapCells[row][col + 1] == 0) {
        continue;
      }
      if (GMapCells[row + 1][col] == 0) {
        continue;
      }
      if (init_getMapFlags((int)row,(int)col) != 0) {
        continue;
      }
      h = (int16_t)(signed char)GMapCells[row][col];

      if (h > 0x6a) {
        r = (uint16_t)ovr_randBelow(4);
        if ((r == 2 || r == 3) && constr_usesGMapFlags((int)row,(int)col) != 0) {
          GUnitGrid[col][row] = (short)((uint16_t)ovr_randBelow(9) + 0x67);
        }
      }
      else if (h > 0x55) {
        r = (uint16_t)ovr_randBelow(4);
        if (r == 1) {
          if (constr_usesGMapFlags((int)row,(int)col) != 0) {
            if ((uint16_t)ovr_randBelow(2) == 0) {
              GUnitGrid[col][row] = (short)((uint16_t)ovr_randBelow(6) + 0x3d);
            }
            else {
              GUnitGrid[col][row] = (short)((uint16_t)ovr_randBelow(9) + 0x67);
            }
          }
        }
        else if (r == 3) {
          if (constr_usesGMapFlags((int)row,(int)col) != 0) {
            GUnitGrid[col][row] = (short)((uint16_t)ovr_randBelow(9) + 0x67);
          }
        }
      }
      else if (h > 0x3f) {
        if ((uint16_t)ovr_randBelow(4) == 3 && constr_usesGMapFlags((int)row,(int)col) != 0) {
          GUnitGrid[col][row] = (short)((uint16_t)ovr_randBelow(9) + 0x67);
        }
      }
      else if (h > 0x2a) {
        r = (uint16_t)ovr_randBelow(4);
        if (r == 1) {
          GUnitGrid[col][row] = (short)((uint16_t)ovr_randBelow(6) + 0x3d);
        }
        else if (r == 3 && constr_usesGMapFlags((int)row,(int)col) != 0) {
          GUnitGrid[col][row] = (short)((uint16_t)ovr_randBelow(9) + 0x67);
        }
      }
      else if (h > 0x15) {
        /* the image's four-way switch at cs:0x168f has all four arms at the same target */
        if ((uint16_t)ovr_randBelow(4) <= 3) {
          GUnitGrid[col][row] = (short)((uint16_t)ovr_randBelow(6) + 0x3d);
        }
      }
      else {
        r = (uint16_t)ovr_randBelow(4);
        if (r == 2) {
          GUnitGrid[col][row] = (short)((uint16_t)ovr_randBelow(6) + 0x3d);
        }
        else if (r == 3 && constr_usesGMapFlags((int)row,(int)col) != 0) {
          GUnitGrid[col][row] = (short)((uint16_t)ovr_randBelow(9) + 0x67);
        }
      }
    }
  }

  /* 6. shore pass: a lake/coast cell next to a small building becomes 0x92..0x96. */
  for (row = 1; row < 0x3a; row++) {
    for (col = 1; col < 0x92; col++) {
      if ((uint16_t)ovr_randBelow(2) != 0) {
        continue;
      }
      if (GMapCells[row][col - 1] == 0) {
        continue;
      }
      if (GMapCells[row + 1][col - 1] == 0) {
        continue;
      }
      if (GMapCells[row][col] == 0) {
        continue;
      }
      if (GMapCells[row + 1][col] == 0) {
        continue;
      }
      if (GMapCells[row][col + 1] == 0) {
        continue;
      }
      if (GMapCells[row + 1][col + 1] == 0) {
        continue;
      }
      if ((signed char)GMapCells[row][col] > (signed char)GMapCells[row][col + 1]) {
        continue;
      }
      if ((signed char)GMapCells[row][col] > (signed char)GMapCells[row][col - 1]) {
        continue;
      }
      if ((signed char)GMapCells[row][col] > (signed char)GMapCells[row - 1][col]) {
        continue;
      }
      if ((signed char)GMapCells[row][col + 1] > (signed char)GMapCells[row - 1][col + 1]) {
        continue;
      }
      if ((signed char)GMapCells[row][col] > (signed char)GMapCells[row + 1][col]) {
        continue;
      }
      if ((signed char)GMapCells[row][col + 1] > (signed char)GMapCells[row + 1][col + 1]) {
        continue;
      }
      if (init_getMapFlags((int)row,(int)col) != 0) {
        continue;
      }
      if (init_getMapFlags((int)row,(int)(col - 1)) != 0) {
        continue;
      }
      if (constr_usesGMapFlags2((int)row,(int)col) != 2) {
        continue;
      }
      idx = (uint16_t)GUnitGrid[col - 1][row];
      bld = GUnits[idx].bldType;
      if (BuildingTypes[bld].size >= 2) {
        continue;
      }
      if (constr_usesGMapFlags2((int)row,(int)col) >= 3) {
        continue;
      }
      GUnitGrid[col - 1][row] = (short)((uint16_t)ovr_randBelow(5) + 0x92);
      GUnitGrid[col][row] = 0;
    }
  }

  init_rebuildAllDirectionFlags();
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
        printf((char *)"NEW MAXSQUARE %d \r");
        ovr_gameProcessKey();
      }
      GSMaxSquare = 0;
      row = '\x02';
      do {
        if (row < '\0') {
          if (GSMaxSquare != 0x24) {
            printf((char *)"NEW SMAXSQUARE %d \r");
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
      ovr_blitText((char *)(char *)"Enter the first word.",
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

