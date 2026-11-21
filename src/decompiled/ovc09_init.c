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
  uint16_t unaff_BP;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t dst;
  far_t dst_00;
  uint16_t uVar1;
  far_t dst_01;
  
  dst.seg = unaff_BP;
  dst.ofs = 0xa000;
  gfx_00.seg = 0;
  gfx_00.ofs = fullScreenGfxSeg;
  ovr_blitLoadRleGfx(gfx_00,dst,fullScreenGfxOfs);
  dst_00.seg = dst.seg;
  dst_00.ofs = 0xa000;
  gfx_01.seg = 0x9af;
  gfx_01.ofs = GMenuGfxSeg;
  ovr_blitLoadRleGfx(gfx_01,dst_00,GMenuGfxOfs);
  uVar1 = dst_00.seg;
  gfx.seg = 0;
  gfx.ofs = nwpanel2Cut1Seg;
  ovr_blitGfxRect(gfx,0,1098,(brect_t *)0x102410,0x0,(*(uint8_t *)((uint8_t *)&(dst_00.seg))),nwpanel2Cut1Ofs);
  if (GameRunning == false) {
    dst_01.seg = uVar1;
    dst_01.ofs = 0xa000;
    gfx_02.seg = 0xc51d;
    gfx_02.ofs = panel01Cut3Seg;
    ovr_blitLoadRleGfx(gfx_02,dst_01,panel01Cut3Ofs);
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
  char *in_stack_00000004;
  
  l = strlen((char *)CONCAT22((char *)s,in_stack_00000004));
  if ((3 < (int)l) && (in_stack_00000004[l - 1] == '\\')) {
    in_stack_00000004[l - 1] = '\0';
  }
  return in_stack_00000004;
}



/* 3381:0132 */

char * __cdecl16far ensure_tail_slash(char *s,...)

{
  uint16_t l;
  char *in_stack_00000004;
  
  l = strlen((char *)CONCAT22((char *)s,in_stack_00000004));
  if ((l == 0) || (in_stack_00000004[l - 1] != '\\')) {
    in_stack_00000004[l] = '\\';
    in_stack_00000004[l + 1] = '\0';
  }
  return in_stack_00000004;
}



/* 3381:016c */

/* chdir doesn't change the disk, so we have to do that */

void __cdecl16far chpath(char *path,...)

{
  uint8_t c;
  char cVar1;
  int iVar2;
  undefined1 extraout_AH;
  char *in_stack_00000004;
  
  iVar2 = chdir((char *)CONCAT22((char *)path,in_stack_00000004));
  if (iVar2 == 0) {
    c = toupper(*(char *)CONCAT22((char *)path,in_stack_00000004));
    if (((in_stack_00000004[1] == ':') && ('@' < (char)c)) && ((char)c < '[')) {
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
  char *in_DX;
  size_t unaff_BP;
  
  getcwd((char *)0x442410,unaff_BP);
  strcpy(&GWorkDir,GOriginalDir);
  ensure_tail_slash((char *)CONCAT22(unaff_BP,(char *)"puppetmaker" + 3),0x8c6c);
  strcat(&GWorkDir,"strong.sav\\");
  full_path = (uint16_t)
              append_name_to_path((char *)CONCAT22(0x5bb,GGameExe.seg),
                                  (char *)CONCAT22(unaff_BP,(char *)"puppetmaker" + 3));
  p = (uint16_t)path_strip_tail_slash((char *)CONCAT22(unaff_BP,in_DX),full_path);
  chpath((char *)CONCAT22(unaff_BP,in_DX),p);
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
  ovr_stsprintf((char *)CONCAT22(0x5bc,unaff_SS),(char *)0x8c6c2410,(char *)"puppetmaker" + 3,lbuf);
  fh = ovr_open_wait_unlock_and_disk();
  if ((int)fh < 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit();
  }
  c = ovr_read_cfg();
  if (c == 0x0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit();
  }
  uVar2 = c;
  if ((((char)c < '1') || ('9' < (char)c)) && (((char)c < 'A' || ('B' < (char)c)))) {
    if (((char)c < 'a') || ('b' < (char)c)) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit();
    }
    uVar2 = toupper(c);
  }
  CFG_Sfx = uVar2;
  c = ovr_read_cfg();
  if (c == 0x0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit();
  }
  uVar2 = c;
  if ((((char)c < '1') || ('9' < (char)c)) && (((char)c < 'A' || ('B' < (char)c)))) {
    if (((char)c < 'a') || ('b' < (char)c)) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit();
    }
    uVar2 = toupper(c);
  }
  CFG_Mus = uVar2;
  c = ovr_read_cfg();
  if (c == 0x0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit();
  }
  if ((((char)c < '0') || ('9' < (char)c)) && (((char)c < 'A' || ('F' < (char)c)))) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit();
  }
  CFG_Irq = c;
  mice = ovr_read_cfg();
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
    ovr_stsprintf((char *)CONCAT22(0x5bc,unaff_SS),(char *)0x8c6c2410,(char *)"puppetmaker" + 3,lbuf
                 );
    iVar3 = ovr_creat_wait_unlock_and_disk();
    if (iVar3 < 0) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit();
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
      ovr_stExit();
    }
    clrscr();
  }
  return;
}



/* 3381:0579 */

void __cdecl16far init_game(void)

{
  int iVar1;
  undefined2 unaff_BP;
  uint8_t in_stack_00000000;
  uint8_t operation;
  undefined1 uVar2;
  
  operation = (uint8_t)unaff_BP;
  uVar2 = (undefined1)((uint)unaff_BP >> 8);
  _OvrInitExt(0,0);
  _OvrInitEms(0,0,0);
  ovr_init_base();
  init_paths();
  init_cfg();
  clrscr();
  srand8(CONCAT22(*(undefined2 *)(BDA_DailyTimeCounter.ofs + 2),*(undefined2 *)BDA_DailyTimeCounter)
        );
  ovr_stshAlloc((ulong)CONCAT11(uVar2,operation) << 0x10,0xfa0f);
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
  StshStrongDatHnd = ovr_stshOpen(CONCAT11(uVar2,operation),0);
  ovr_sfxInit();
  ovr_musInit();
  ovr_gfxInitRand();
  ovr_miceInit();
  ovr_biosVideoCall(operation,in_stack_00000000,0x13);
  init_grayscale_palette();
  ovr_init_ui_gfxes();
  init_buffers();
  ovr_clean_ring_buffer();
  ovr_heapInit();
  ovr_play_sfx(0,83);
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
  far_t src;
  ulong uVar1;
  char cVar2;
  byte bVar3;
  uint32_t *puVar4;
  void *pvVar5;
  byte extraout_AH;
  uint32_t *puVar6;
  uint16_t uVar7;
  uint uVar8;
  stg_tmp_t *psVar9;
  undefined1 extraout_AH_00;
  int in_CX;
  word extraout_DX;
  word wVar10;
  word wVar11;
  uint uVar12;
  uint uVar13;
  byte (*paabVar14) [59] [148];
  short (*paasVar15) [148] [60];
  uint32_t *puVar16;
  undefined2 unaff_SI;
  int iVar17;
  int iVar18;
  byte unaff_DI;
  uint uVar19;
  long *plVar20;
  undefined2 uVar21;
  undefined2 unaff_SS;
  bool bVar22;
  longdouble in_ST0;
  undefined4 in_stack_00000004;
  int16_t in_stack_00000008;
  byte abStackY_348 [488];
  undefined1 auStackY_160 [158];
  undefined2 uStackY_c2;
  undefined2 uStackY_c0;
  int iStackY_be;
  undefined1 uVar23;
  undefined1 uVar24;
  int8_t iStack_40;
  uint8_t uStack_3f;
  lbm_type_t lStack_3e;
  uint16_t uStack_34;
  uint16_t uStack_32;
  stg_tmp_t *psStack_30;
  char cStack_2c;
  byte bStack_2b;
  uint32_t *puStack_26;
  word wStack_24;
  word wStack_22;
  uint uStack_20;
  int iStack_1e;
  int iStack_1c;
  word wStack_16;
  uint uStack_14;
  word wStack_12;
  undefined2 uStack_10;
  word wStack_e;
  int iStack_c;
  uint uStack_a;
  
  uVar23 = (undefined1)unaff_SI;
  uVar24 = (undefined1)((uint)unaff_SI >> 8);
  uStack_10 = (uint)(byte)uStack_10;
  for (iVar17 = 0; iVar17 < 0x94; iVar17 = iVar17 + 1) {
    uVar7 = ovr_randBelow();
    if ((uVar7 & 0xff) == 0) {
      uVar7 = ovr_randBelow();
      cVar2 = (char)uVar7 * '\x02' + (*(uint8_t *)((uint8_t *)&(uStack_10) + 1)) + -1;
      uStack_10 = CONCAT11(cVar2,(byte)uStack_10);
      if (cVar2 < -1) {
        uStack_10 = CONCAT11(0xff,(byte)uStack_10);
      }
      if ('\x01' < (*(uint8_t *)((uint8_t *)&(uStack_10) + 1))) {
        uStack_10 = CONCAT11(1,(byte)uStack_10);
      }
    }
    if ((iVar17 == 0) || (iVar17 == 0x93)) {
      uStack_10 = uStack_10 & 0xff;
    }
    (&stack0xff5c)[iVar17] = (*(uint8_t *)((uint8_t *)&(uStack_10) + 1));
  }
  uStack_a = 0;
  _fsetmem(GUnitGrid,0x4560,0);
  psVar9 = (stg_tmp_t *)((char *)"puppetmaker" + 3);
  _fsetmem(GMapFlags,0x4560,0);
  for (uVar19 = 0; (int)uVar19 < 0x3c; uVar19 = uVar19 + 1) {
    if ((uVar19 & 1) == 0) {
      for (iVar17 = 0; iVar17 < 0x94; iVar17 = iVar17 + 1) {
        iStack_c = 0;
        if (iVar17 != 0) {
          iStack_c = (int)(char)((byte (*) [59] [148])GMapCells)[-1][uVar19 + 0x3a][iVar17 + 0x93];
        }
        if (uVar19 != 0) {
          iStack_c = iStack_c +
                     (char)((byte (*) [59] [148])GMapCells)[-1][uVar19 + 0x3a]
                           [(char)(&stack0xff5c)[iVar17] + iVar17];
        }
        iStack_c = iStack_c >> 1;
        if ((iVar17 != 0) && ((&stack0xff5b)[iVar17] != (&stack0xff5c)[iVar17])) {
          uVar7 = ovr_randBelow();
          if ((uVar7 & 0xff) == 1) {
            (&stack0xff5c)[iVar17] = (&stack0xff5b)[iVar17];
          }
          else if ((uVar7 & 0xff) == 2) {
            (&stack0xff5b)[iVar17] = (&stack0xff5c)[iVar17];
          }
        }
        uVar7 = ovr_randBelow();
        if ((uVar7 & 0xff) == 0) {
          if (iVar17 != 0) {
            cVar2 = (&stack0xff5b)[iVar17];
            uVar7 = ovr_randBelow();
            cVar2 = (char)uVar7 * '\x02' + cVar2 + -1;
            uStack_10 = CONCAT11(cVar2,(byte)uStack_10);
            if (cVar2 < -1) {
              uStack_10 = CONCAT11(0xff,(byte)uStack_10);
            }
            if ('\x01' < (*(uint8_t *)((uint8_t *)&(uStack_10) + 1))) {
              uStack_10 = CONCAT11(1,(byte)uStack_10);
            }
            (&stack0xff5c)[iVar17] = (*(uint8_t *)((uint8_t *)&(uStack_10) + 1));
          }
          if (iStack_c < 0x56) {
            if (iStack_c < 0x41) {
              if (iStack_c < 0x2b) {
                if (iStack_c < 0x16) {
                  if (iStack_c < 1) {
                    uVar7 = ovr_randBelow();
                    uStack_a = (uVar7 & 0xff) - 2;
                  }
                  else {
                    uVar7 = ovr_randBelow();
                    uStack_a = (uVar7 & 0xff) - 5;
                  }
                }
                else {
                  uVar7 = ovr_randBelow();
                  uStack_a = (uVar7 & 0xff) - 8;
                }
              }
              else {
                uVar7 = ovr_randBelow();
                uStack_a = (uVar7 & 0xff) - 5;
              }
            }
            else {
              uVar7 = ovr_randBelow();
              uStack_a = (uVar7 & 0xff) - 4;
            }
          }
          else {
            uVar7 = ovr_randBelow();
            uStack_a = (uVar7 & 0xff) - 8;
          }
        }
        if (iStack_c < 0x56) {
          if (iStack_c < 0x41) {
            if (iStack_c < 0x2b) {
              if (iStack_c < 0x16) {
                if (iStack_c < 1) {
                  wStack_e = 0xb;
                }
                else {
                  wStack_e = 5;
                }
              }
              else {
                wStack_e = 0xf;
              }
            }
            else {
              wStack_e = 5;
            }
          }
          else {
            wStack_e = 0x13;
          }
        }
        else {
          wStack_e = 9;
        }
        uVar7 = ovr_randBelow();
        iStack_c = iStack_c + ((uVar7 & 0xff) - ((int)wStack_e >> 1)) + uStack_a + 1;
        if (iStack_c < -0x23) {
          iStack_c = -0x23;
          uStack_a = (uStack_a ^ (int)uStack_a >> 0xf) - ((int)uStack_a >> 0xf);
        }
        if (0x7f < iStack_c) {
          iStack_c = 0x7f;
          uStack_a = -((uStack_a ^ (int)uStack_a >> 0xf) - ((int)uStack_a >> 0xf));
        }
        psVar9 = (stg_tmp_t *)CONCAT11((char)(uVar19 * 0x94 >> 8),(byte)iStack_c);
        (*(byte (*) [59] [148])GMapCells)[uVar19][iVar17] = (byte)iStack_c;
      }
    }
    else {
      for (iVar17 = 0x93; -1 < iVar17; iVar17 = iVar17 + -1) {
        iStack_c = 0;
        if (iVar17 != 0x93) {
          iStack_c = (int)(char)(*(byte (*) [59] [148])GMapCells)[uVar19][iVar17 + 1];
        }
        if (uVar19 != 0) {
          iStack_c = iStack_c +
                     (char)((byte (*) [59] [148])GMapCells)[-1][uVar19 + 0x3a]
                           [(char)(&stack0xff5c)[iVar17] + iVar17];
        }
        iStack_c = iStack_c >> 1;
        if ((iVar17 != 0x93) && ((&stack0xff5d)[iVar17] != (&stack0xff5c)[iVar17])) {
          uVar7 = ovr_randBelow();
          if ((uVar7 & 0xff) == 1) {
            (&stack0xff5c)[iVar17] = (&stack0xff5d)[iVar17];
          }
          else if ((uVar7 & 0xff) == 2) {
            (&stack0xff5d)[iVar17] = (&stack0xff5c)[iVar17];
          }
        }
        uVar7 = ovr_randBelow();
        if ((uVar7 & 0xff) == 0) {
          if (iVar17 != 0x93) {
            cVar2 = (&stack0xff5d)[iVar17];
            uVar7 = ovr_randBelow();
            cVar2 = (char)uVar7 * '\x02' + cVar2 + -1;
            uStack_10 = CONCAT11(cVar2,(byte)uStack_10);
            if (cVar2 < -1) {
              uStack_10 = CONCAT11(0xff,(byte)uStack_10);
            }
            if ('\x01' < (*(uint8_t *)((uint8_t *)&(uStack_10) + 1))) {
              uStack_10 = CONCAT11(1,(byte)uStack_10);
            }
            (&stack0xff5c)[iVar17] = (*(uint8_t *)((uint8_t *)&(uStack_10) + 1));
          }
          if (iStack_c < 0x56) {
            if (iStack_c < 0x41) {
              if (iStack_c < 0x2b) {
                if (iStack_c < 0x16) {
                  if (iStack_c < 1) {
                    uVar7 = ovr_randBelow();
                    uStack_a = (uVar7 & 0xff) - 2;
                  }
                  else {
                    uVar7 = ovr_randBelow();
                    uStack_a = (uVar7 & 0xff) - 5;
                  }
                }
                else {
                  uVar7 = ovr_randBelow();
                  uStack_a = (uVar7 & 0xff) - 8;
                }
              }
              else {
                uVar7 = ovr_randBelow();
                uStack_a = (uVar7 & 0xff) - 5;
              }
            }
            else {
              uVar7 = ovr_randBelow();
              uStack_a = (uVar7 & 0xff) - 4;
            }
          }
          else {
            uVar7 = ovr_randBelow();
            uStack_a = (uVar7 & 0xff) - 8;
          }
        }
        if (iStack_c < 0x56) {
          if (iStack_c < 0x41) {
            if (iStack_c < 0x2b) {
              if (iStack_c < 0x16) {
                if (iStack_c < 1) {
                  wStack_e = 0xb;
                }
                else {
                  wStack_e = 5;
                }
              }
              else {
                wStack_e = 0xf;
              }
            }
            else {
              wStack_e = 5;
            }
          }
          else {
            wStack_e = 0x13;
          }
        }
        else {
          wStack_e = 9;
        }
        uVar7 = ovr_randBelow();
        iStack_c = iStack_c + ((uVar7 & 0xff) - ((int)wStack_e >> 1)) + uStack_a + 1;
        if (iStack_c < -0x7f) {
          iStack_c = -0x7f;
          uStack_a = (uStack_a ^ (int)uStack_a >> 0xf) - ((int)uStack_a >> 0xf);
        }
        if (0x7f < iStack_c) {
          iStack_c = 0x7f;
          uStack_a = -((uStack_a ^ (int)uStack_a >> 0xf) - ((int)uStack_a >> 0xf));
        }
        psVar9 = (stg_tmp_t *)CONCAT11((char)(uVar19 * 0x94 >> 8),(byte)iStack_c);
        (*(byte (*) [59] [148])GMapCells)[uVar19][iVar17] = (byte)iStack_c;
      }
    }
  }
  for (iVar17 = 0; iVar17 < 0x3c; iVar17 = iVar17 + 1) {
    for (iVar18 = 0; iVar18 < 0x94; iVar18 = iVar18 + 1) {
      uVar21 = (undefined2)((ulong)GMapCells >> 0x10);
      if ((char)(*(byte (*) [59] [148])GMapCells)[iVar17][iVar18] < '\0') {
        (*(byte (*) [59] [148])GMapCells)[iVar17][iVar18] = 0;
      }
      psVar9 = (stg_tmp_t *)(iVar17 * 0x94);
      if ((iVar18 != 0x93) && (iVar17 != 0x3c)) {
        uVar21 = (undefined2)((ulong)GMapCells >> 0x10);
        paabVar14 = (byte (*) [59] [148])GMapCells;
        uVar19 = (int)(char)(*paabVar14)[iVar17 + 1][iVar18] -
                 (int)(char)(*paabVar14)[iVar17][iVar18 + 1];
        uVar12 = (int)uVar19 >> 0xf;
        uVar8 = (int)(char)(*paabVar14)[iVar17][iVar18] -
                (int)(char)(*paabVar14)[iVar17 + 1][iVar18 + 1];
        uVar13 = (int)uVar8 >> 0xf;
        psVar9 = (stg_tmp_t *)((uVar8 ^ uVar13) - uVar13);
        if ((int)((uVar19 ^ uVar12) - uVar12) < (int)psVar9) {
          psVar9 = (stg_tmp_t *)(iVar18 * 2);
          *(uint *)(psVar9->cmap + (int)(*(short (*) [60] [148])GMapFlags + iVar17)) =
               *(uint *)(psVar9->cmap + (int)(*(short (*) [60] [148])GMapFlags + iVar17)) | 4;
        }
      }
    }
  }
  init_rebuildMapFlags();
  init_usesRandBelow2();
  init_rebuildMapFlags();
  plVar20 = (long *)0x0;
  do {
    if (0x3a < (int)plVar20) {
      for (iVar17 = 1; iVar17 < 0x3a; iVar17 = iVar17 + 1) {
        for (iVar18 = 1; iVar18 < 0x92; iVar18 = iVar18 + 1) {
          uVar7 = ovr_randBelow();
          psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
          if (psVar9 == (stg_tmp_t *)0x0) {
            psVar9 = (stg_tmp_t *)(iVar17 * 0x94);
            uVar21 = (undefined2)((ulong)GMapCells >> 0x10);
            paabVar14 = (byte (*) [59] [148])GMapCells;
            if ((((psVar9->cmap[(int)(*paabVar14 + -1) + 0x93 + iVar18] != 0) &&
                 (psVar9 = (stg_tmp_t *)(*paabVar14 + iVar17), psVar9->cmap[iVar18 + 0x93] != 0)) &&
                (psVar9 = (stg_tmp_t *)(iVar17 * 0x94),
                psVar9->cmap[(int)((*paabVar14)[0] + iVar18)] != 0)) &&
               (((((psVar9 = (stg_tmp_t *)(*paabVar14 + iVar17), psVar9->cmap[iVar18 + 0x94] != 0 &&
                   (psVar9 = (stg_tmp_t *)(iVar17 * 0x94),
                   psVar9->cmap[(int)((*paabVar14)[0] + iVar18 + 1)] != 0)) &&
                  ((psVar9 = (stg_tmp_t *)(*paabVar14 + iVar17), psVar9->cmap[iVar18 + 0x95] != 0 &&
                   ((bVar3 = (*paabVar14)[iVar17][iVar18],
                    psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar17 * 0x94) >> 8),bVar3),
                    (char)bVar3 <= (char)(*paabVar14)[iVar17][iVar18 + 1] &&
                    (bVar3 = (*paabVar14)[iVar17][iVar18],
                    psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar17 * 0x94) >> 8),bVar3),
                    (char)bVar3 <= (char)paabVar14[-1][iVar17 + 0x3a][iVar18 + 0x93])))))) &&
                 (bVar3 = (*paabVar14)[iVar17][iVar18],
                 psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar17 * 0x94) >> 8),bVar3),
                 (char)bVar3 <= (char)paabVar14[-1][iVar17 + 0x3a][iVar18])) &&
                (((bVar3 = (*paabVar14)[iVar17][iVar18 + 1],
                  psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar17 * 0x94) >> 8),bVar3),
                  (char)bVar3 <= (char)paabVar14[-1][iVar17 + 0x3a][iVar18 + 1] &&
                  (bVar3 = (*paabVar14)[iVar17][iVar18],
                  psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar17 * 0x94) >> 8),bVar3),
                  (char)bVar3 <= (char)(*paabVar14)[iVar17 + 1][iVar18])) &&
                 (bVar3 = (*paabVar14)[iVar17][iVar18 + 1],
                 psVar9 = (stg_tmp_t *)CONCAT11((char)((uint)(iVar17 * 0x94) >> 8),bVar3),
                 (char)bVar3 <= (char)(*paabVar14)[iVar17 + 1][iVar18 + 1])))))) {
              uVar19 = init_getMapFlags();
              psVar9 = (stg_tmp_t *)(uVar19 & 0xff);
              if (psVar9 == (stg_tmp_t *)0x0) {
                uVar19 = init_getMapFlags();
                psVar9 = (stg_tmp_t *)(uVar19 & 0xff);
                if ((psVar9 == (stg_tmp_t *)0x0) &&
                   (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags2(), (char)psVar9 == '\x02')) {
                  psVar9 = (stg_tmp_t *)
                           ((uint)((unit_t *)GUnits +
                                  ((short (*) [148] [60])GUnitGrid)[-1][iVar18 + 0x92][iVar17])->
                                  bldType * 0x27);
                  if ((psVar9->cmap[0x11b] < 2) &&
                     (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags2(), (byte)psVar9 < 3)) {
                    uVar7 = ovr_randBelow();
                    ((short (*) [148] [60])GUnitGrid)[-1][iVar18 + 0x93][iVar17] =
                         (uVar7 & 0xff) + 0x92;
                    uVar1 = (ulong)GUnitGrid >> 0x10;
                    paasVar15 = (short (*) [148] [60])GUnitGrid;
                    psVar9 = (stg_tmp_t *)(iVar17 * 2);
                    (psVar9->cmap + (int)(*paasVar15 + iVar18))[0] = 0;
                    (psVar9->cmap + (int)(*paasVar15 + iVar18))[1] = 0;
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
    for (iVar17 = 0; iVar17 < 0x93; iVar17 = iVar17 + 1) {
      psVar9 = (stg_tmp_t *)((int)plVar20 * 0x94);
      uVar21 = (undefined2)((ulong)GMapCells >> 0x10);
      paabVar14 = (byte (*) [59] [148])GMapCells;
      if (((psVar9->cmap[(int)((*paabVar14)[0] + iVar17)] != 0) &&
          (psVar9 = (stg_tmp_t *)((int)plVar20 * 0x94),
          psVar9->cmap[(int)((*paabVar14)[0] + iVar17 + 1)] != 0)) &&
         ((psVar9 = (stg_tmp_t *)(*paabVar14 + (int)plVar20), psVar9->cmap[iVar17 + 0x94] != 0 &&
          (psVar9 = (stg_tmp_t *)(*paabVar14 + (int)plVar20), psVar9->cmap[iVar17 + 0x94] != 0)))) {
        uVar19 = init_getMapFlags();
        psVar9 = (stg_tmp_t *)(uVar19 & 0xff);
        if (psVar9 == (stg_tmp_t *)0x0) {
          uVar19 = (uint)(char)(*(byte (*) [59] [148])GMapCells)[(int)plVar20][iVar17];
          if ((int)uVar19 < 0x6b) {
            if ((int)uVar19 < 0x56) {
              if ((int)uVar19 < 0x40) {
                if ((int)uVar19 < 0x2b) {
                  if ((int)uVar19 < 0x16) {
                    uVar7 = ovr_randBelow();
                    psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
                    if (psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 2)) {
                      uVar7 = ovr_randBelow();
                      psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x3d);
                      (*(short (*) [148] [60])GUnitGrid)[iVar17][(int)plVar20] = (short)psVar9;
                    }
                    else if ((psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 3)) &&
                            (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(), (char)psVar9 != '\0')
                            ) {
                      uVar7 = ovr_randBelow();
                      psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
                      if (psVar9 == (stg_tmp_t *)0x0) {
                        uVar7 = ovr_randBelow();
                        psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
                        (*(short (*) [148] [60])GUnitGrid)[iVar17][(int)plVar20] = (short)psVar9;
                      }
                    }
                  }
                  else {
                    uVar7 = ovr_randBelow();
                    psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
                    switch(psVar9) {
                    case (stg_tmp_t *)0x0:
                      func_0x000318f5();
                      wVar11 = extraout_DX;
                      goto L_grabLbm_0445;
                    case (stg_tmp_t *)0x1:
                      while( true ) {
                        psVar9 = (stg_tmp_t *)(iVar17 + (int)plVar20);
                        if (iStack_1c <= (int)psVar9) {
                          psVar9 = memcpy((char *)CONCAT13((char)(wStack_12 >> 8),
                                                           CONCAT12((char)wStack_12,uStack_14)),
                                          (char *)CONCAT13((char)((uint)unaff_SS >> 8),
                                                           CONCAT12((char)unaff_SS,
                                                                    auStackY_160 + uVar19)),wStack_e
                                         );
                          uStack_14 = uStack_14 + 0x140;
                        }
                        iVar17 = iVar17 + 1;
                        if (((int)uStack_10 <= iVar17) ||
                           (psVar9 = (stg_tmp_t *)(iVar17 + (int)plVar20),
                           (int)uStack_20 < (int)psVar9)) break;
                        ovr_unrle();
                      }
                      return psVar9;
                    case (stg_tmp_t *)0x2:
                      *plVar20 = (long)in_ST0;
                    /* WARNING: Bad instruction - Truncating control flow here */
                      halt_baddata();
                    case (stg_tmp_t *)0x3:
                      goto switchD_3000_4a6e_caseD_3;
                    }
                  }
                }
                else {
                  uVar7 = ovr_randBelow();
                  psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
                  if (psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 1)) {
                    uVar7 = ovr_randBelow();
                    psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x3d);
                    (*(short (*) [148] [60])GUnitGrid)[iVar17][(int)plVar20] = (short)psVar9;
                  }
                  else if ((psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 3)) &&
                          (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(), (char)psVar9 != '\0'))
                  {
                    uVar7 = ovr_randBelow();
                    psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
                    (*(short (*) [148] [60])GUnitGrid)[iVar17][(int)plVar20] = (short)psVar9;
                  }
                }
              }
              else {
                uVar7 = ovr_randBelow();
                psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
                if (((psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 3)) &&
                    (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(), (char)psVar9 != '\0')) &&
                   (psVar9 = (stg_tmp_t *)ovr_randBelow(), (char)psVar9 != '\0')) {
                  uVar7 = ovr_randBelow();
                  psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
                  (*(short (*) [148] [60])GUnitGrid)[iVar17][(int)plVar20] = (short)psVar9;
                }
              }
            }
            else {
              uVar7 = ovr_randBelow();
              psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
              if (psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 1)) {
                psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags();
                if ((char)psVar9 != '\0') {
                  uVar7 = ovr_randBelow();
                  if ((uVar7 & 0xff) == 0) {
                    uVar7 = ovr_randBelow();
                    psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x3d);
                    (*(short (*) [148] [60])GUnitGrid)[iVar17][(int)plVar20] = (short)psVar9;
                  }
                  else {
                    uVar7 = ovr_randBelow();
                    psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
                    (*(short (*) [148] [60])GUnitGrid)[iVar17][(int)plVar20] = (short)psVar9;
                  }
                }
              }
              else if ((psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 3)) &&
                      (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(), (char)psVar9 != '\0')) {
                uVar7 = ovr_randBelow();
                psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
                (*(short (*) [148] [60])GUnitGrid)[iVar17][(int)plVar20] = (short)psVar9;
              }
            }
          }
          else {
            uVar7 = ovr_randBelow();
            psVar9 = (stg_tmp_t *)(uVar7 & 0xff);
            if (((psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 2)) ||
                (psVar9 == (stg_tmp_t *)((int)(undefined4 *)&_DATA + 3))) &&
               (psVar9 = (stg_tmp_t *)ovr_constr_usesGMapFlags(), (char)psVar9 != '\0')) {
              uVar7 = ovr_randBelow();
              psVar9 = (stg_tmp_t *)((uVar7 & 0xff) + 0x67);
              (*(short (*) [148] [60])GUnitGrid)[iVar17][(int)plVar20] = (short)psVar9;
            }
          }
        }
      }
    }
    plVar20 = (long *)((int)plVar20 + 1);
  } while( true );
switchD_3000_4a6e_caseD_3:
  do {
    *(int *)(&stack0xd744 + iVar17) = *(int *)(&stack0xd744 + iVar17) + in_CX;
    constr_compute2((uint8_t)uStack_20,(uint8_t)wStack_22,(uint8_t)iStack_1c,(byte)psVar9,unaff_DI);
    ovr_ovc07_usesBiosReadKey();
    constr_compute2((uint8_t)iStack_1c,(uint8_t)iStack_1e,(uint8_t)wStack_22,bStack_2b,2);
    ovr_ovc07_usesBiosReadKey();
    while( true ) {
      uVar19 = constr_usesGMapFlags();
      if ((char)uVar19 != '\0') {
        ovr_ovc07_usesLDIV_at_();
      }
      do {
        plVar20 = (long *)((int)plVar20 + 1);
        uVar7 = rowBandSquareFirst[0];
        if ((int)rowBandSquareEnd[0] <= (int)plVar20) {
          for (; (int)uVar7 < (int)rowBandSquareEnd[0]; uVar7 = uVar7 + 1) {
            bVar3 = constr_setHighlightAtOffset();
            if ((*(byte *)(CONCAT11(extraout_AH_00,bVar3) * 0x27 + 0x11e) & 2) != 0) {
              constr_usesSmoothPrev();
              ovr_blit_usesBlitGfxN();
            }
            if ((*(byte *)(CONCAT11(extraout_AH_00,bVar3) * 0x27 + 0x11e) & 1) != 0) {
              ovr_blitGfxRect();
            }
          }
          return (stg_tmp_t *)((char *)"puppetmaker" + 3);
        }
      } while (((int)((uint16_t *)SquareRightX)[(int)plVar20] < 0xef) ||
              (0x134 < (int)((uint16_t *)SquareLeftX)[(int)plVar20]));
      uVar7 = ((uint16_t *)squareColumn)[(int)plVar20];
      iStack_1c = constr_getCellAtOffset(uVar7,-2);
      iStack_1e = constr_getCellAtOffset(uVar7 + 1,-2);
      constr_usesSmoothPrev();
      constr_usesSmoothPrev();
      psVar9 = (stg_tmp_t *)constr_getFlagsAtOffset(uVar7,-1);
      bStack_2b = (byte)psVar9;
      if (((uint)psVar9 & 4) != 0) break;
      constr_compute2((uint8_t)uStack_20,(uint8_t)wStack_22,(uint8_t)iStack_1e,bStack_2b,2);
      ovr_ovc07_usesBiosReadKey();
      constr_compute2((uint8_t)iStack_1c,(uint8_t)iStack_1e,(uint8_t)uStack_20,bStack_2b,1);
      ovr_ovc07_usesBiosReadKey();
    }
    unaff_DI = 1;
  } while( true );
L_grabLbm_0445:
  iVar17 = ovr_stshRead();
  psVar9 = (stg_tmp_t *)psStack_30;
  uVar21 = (undefined2)((ulong)psStack_30 >> 0x10);
  if (iVar17 != 0 || wVar11 != 0) {
bad_lbm:
    if ((&psVar9->bptr)->ofs != 0 || (psVar9->bptr).seg != 0) {
      ovr_stshFree();
    }
    ovr_stshClose();
    ovr_stshFree();
    printf("Filename %d %s  \r");
    ovr_biosReadKey();
                    /* WARNING: Subroutine does not return */
    ovr_stExit();
  }
  if ((uStack_20 != uVar19) || (wStack_22 != wStack_e)) {
    if ((uStack_20 == uStack_14) && (wStack_22 == wStack_16)) {
      wVar10 = wStack_22;
      ovr_stshRead();
      puVar6 = ovr_be4();
      puStack_26 = puVar6;
      wStack_24 = wVar10;
      if (((uint)puVar6 & 1) != 0) {
        puStack_26 = (uint32_t *)((int)puVar6 + 1);
        wStack_24 = wVar10 + ((uint32_t *)0xfffe < puVar6);
      }
      if (((int)wStack_24 < 0) || ((wStack_24 == 0 && (puStack_26 < (char *)"Error 4 %d \r" + 0xb)))
         ) {
        if ((-1 < (int)wStack_24) && ((0 < (int)wStack_24 || (puStack_26 != (uint32_t *)0x0)))) {
          ovr_stshRead();
        }
      }
      else {
        ovr_stshRead();
        if ((-1 < (int)wStack_24) &&
           ((0 < (int)wStack_24 || ((char *)"Error 4 %d \r" + 0xb < puStack_26)))) {
          ovr_stshTell();
          ovr_stshSeek();
        }
      }
      puVar16 = (uint32_t *)0x0;
      while( true ) {
        if ((0 < (int)wVar10) ||
           ((puVar4 = puVar6, wVar11 = wVar10, wVar10 == 0 &&
            ((char *)"Error 4 %d \r" + 0xb < puVar6)))) {
          puVar4 = (uint32_t *)((char *)"Error 4 %d \r" + 0xb);
          wVar11 = 0;
        }
        if (((int)wVar11 < 1) && ((wVar11 != 0 || (puVar4 <= puVar16)))) break;
        psVar9->cmap[(int)puVar16] = (uint8_t)((int)(uint)abStackY_348[(int)puVar16] >> 2);
        puVar16 = (uint32_t *)((int)puVar16 + 1);
      }
    }
    else {
      if ((uStack_20 == uStack_10) && (wStack_22 == wStack_12)) {
        if (cStack_2c != '\0') {
          ovr_stshRead();
          puVar6 = ovr_be4();
          pvVar5 = ovr_stshAlloc();
          ovr_stshRead();
          bVar3 = extraout_AH;
          ovr_stshClose();
          iStackY_be = (uint)bVar3 << 8;
          uStackY_c0 = 0x2337;
          uStackY_c2 = 0x152a;
          src.seg = (uint16_t)psVar9;
          src.ofs = (uint16_t)puVar6;
          lbm_decode_body(lStack_3e,iStack_40,uStack_3f,(uint8_t)pvVar5,src,
                          (stg_tmp_t *)
                          CONCAT13((char)((ulong)in_stack_00000004 >> 0x18),
                                   CONCAT12((char)((ulong)in_stack_00000004 >> 0x10),uVar21)),
                          in_stack_00000008,uStack_32,uStack_34,CONCAT11(uVar24,uVar23));
          ovr_stshFree();
          return psVar9;
        }
        goto bad_lbm;
      }
      wStack_24 = wStack_22;
      ovr_stshRead();
      puStack_26 = ovr_be4();
      if (((uint)puStack_26 & 1) != 0) {
        bVar22 = (uint32_t *)0xfffe < puStack_26;
        puStack_26 = (uint32_t *)((int)puStack_26 + 1);
        wStack_24 = wStack_24 + bVar22;
      }
      puVar6 = ovr_stshTell();
      wVar11 = ((int)puVar6 >> 0xf) + wStack_24 + (uint)CARRY2((uint)puVar6,(uint)puStack_26);
      ovr_stshSeek();
    }
    goto L_grabLbm_0445;
  }
  cStack_2c = '\x01';
  wVar11 = wStack_22;
  iVar17 = ovr_stshRead();
  if ((iVar17 != 0 || wVar11 != 0) ||
     (((puVar6 = ovr_be4(), wVar11 != 0 ||
       (puVar6 != (uint32_t *)((byte *)__C0_ASM_CopyRight + 0x10))) ||
      (iVar17 = ovr_stshRead(), iVar17 != 0 || wVar11 != 0)))) goto bad_lbm;
  uStack_32 = ovr_be2();
  uStack_34 = ovr_be2();
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
  undefined2 in_DX;
  uint unaff_BP;
  uint32_t nbytes;
  uint uVar2;
  ulong uVar1;
  
  nbytes = (ulong)unaff_BP << 0x10;
  (*(uint16_t *)((uint8_t *)&(GUnits))) = ovr_stshAlloc(nbytes,0x2a30);
  uVar2 = (uint)(nbytes >> 0x10);
  (*(uint16_t *)((uint8_t *)&(GUnits) + 2)) = in_DX;
  _fsetmem((unit_t *)CONCAT22(in_DX,(unit_t *)GUnits),0x2a30,0);
  init_initGUnits();
  GUnitCount = 0xf8;
  uVar1 = (ulong)uVar2 << 0x10;
  (*(uint16_t *)((uint8_t *)&(GUnitGrid))) = ovr_stshAlloc(uVar1,0x4560);
  uVar1 = uVar1 & 0xffff0000;
  (*(uint16_t *)((uint8_t *)&(GUnitGrid) + 2)) = in_DX;
  (*(uint16_t *)((uint8_t *)&(GMapFlags))) = ovr_stshAlloc(uVar1,0x4560);
  uVar1 = uVar1 & 0xffff0000;
  (*(uint16_t *)((uint8_t *)&(GMapFlags) + 2)) = in_DX;
  (*(uint16_t *)((uint8_t *)&(GMapCells))) = ovr_stshAlloc(uVar1,0x22b0);
  uVar1 = uVar1 & 0xffff0000;
  (*(uint16_t *)((uint8_t *)&(GMapCells) + 2)) = in_DX;
  (*(uint16_t *)((uint8_t *)&(Entities))) = ovr_stshAlloc(uVar1,33000);
  (*(uint16_t *)((uint8_t *)&(Entities) + 2)) = in_DX;
  (*(uint16_t *)((uint8_t *)&(FillGrid))) = ovr_stshAlloc(uVar1 & 0xffff0000,0x6541);
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
  int unaff_DI;
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
            ovr_stExit(unaff_DI,8);
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
            ovr_stExit(unaff_DI,8);
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
          ovr_stExit(unaff_DI,7);
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
          ovr_stExit(unaff_DI,7);
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

uint __cdecl16far init_usesGMapCells(int x,int y,...)

{
  byte (*pabVar1) [148];
  uint uVar2;
  byte (*paabVar3) [59] [148];
  undefined2 uVar4;
  int in_stack_00000004;
  
  pabVar1 = (byte (*) [148])(x * 0x94);
  uVar4 = (undefined2)((ulong)GMapCells >> 0x10);
  paabVar3 = (byte (*) [59] [148])GMapCells;
  if (((((*paabVar3)[0][(int)(*pabVar1 + in_stack_00000004)] == 0) ||
       (pabVar1 = (byte (*) [148])(x * 0x94),
       (*paabVar3)[0][(int)(*pabVar1 + in_stack_00000004 + 1)] == 0)) ||
      (pabVar1 = *paabVar3 + x, pabVar1[1][in_stack_00000004] == 0)) ||
     (pabVar1 = *paabVar3 + x, pabVar1[1][in_stack_00000004] == 0)) {
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
  uint unaff_SI;
  int iVar1;
  far_t handle;
  far_t handle_00;
  far_t handle_01;
  far_t handle_02;
  far_t handle_03;
  
  handle = far_from_u32((uint32_t)((ulong)unaff_SI << 0x10));
  for (iVar1 = 0; iVar1 < (int)(uint)GLeaderCount; iVar1 = iVar1 + 1) {
    handle.ofs = ((undefined2 *)(iVar1 * 4))[1];
    ovr_stshFree(handle,*(undefined2 *)(iVar1 * 4));
  }
  GLeaderCount = 0;
  if (audioSaveCut1Ofs != 0 || audioSaveCut1Seg != 0) {
    handle_00.seg = handle.seg;
    handle_00.ofs = audioSaveCut1Seg;
    ovr_stshFree(handle_00,audioSaveCut1Ofs);
    handle.seg = handle_00.seg;
  }
  if (audioSaveCut2Ofs != 0 || audioSaveCut2Seg != 0) {
    handle_01.seg = handle.seg;
    handle_01.ofs = audioSaveCut2Seg;
    ovr_stshFree(handle_01,audioSaveCut2Ofs);
    handle.seg = handle_01.seg;
  }
  if (upperTextOfs != 0 || upperTextSeg != 0) {
    handle_02.seg = handle.seg;
    handle_02.ofs = upperTextSeg;
    ovr_stshFree(handle_02,upperTextOfs);
    handle.seg = handle_02.seg;
  }
  upperTextSeg = 0;
  upperTextOfs = 0;
  audioSaveCut1Seg = 0;
  audioSaveCut1Ofs = 0;
  audioSaveCut2Seg = 0;
  audioSaveCut2Ofs = 0;
  ovr_clean_ring_buffer();
  if (CrossBlitPtr.ofs != 0 || CrossBlitPtr.seg != 0) {
    handle_03.seg = handle.seg;
    handle_03.ofs = CrossBlitPtr.seg;
    ovr_stshFree(handle_03,CrossBlitPtr.ofs);
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
  uint16_t unaff_BP;
  
  ovr_fmFreeAudio(unaff_BP,1);
  freeLeaderData();
  return;
}



/* 3381:2101 */

/* WARNING: Variable defined which should be unmapped: palette */
/* [R4] calls clearEntities */

void __cdecl16far init_usesClearEntities(void)

{
  uint16_t uVar1;
  stg_tmp_t *psVar2;
  uint8_t *puVar3;
  undefined2 uVar4;
  uint16_t unaff_SS;
  undefined4 uStack_308;
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
  uVar1 = ovr_randBelow();
  puVar3 = (uint8_t *)((uVar1 & 0xff) * 3);
  seasonGroupBase = SUB21(puVar3,0);
  if (GameRunning == false) {
    uVar1 = ovr_randBelow();
    randomFeatureCount = (undefined1)uVar1;
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
  psVar2 = ovr_stshLoadGfx();
  uVar4 = 0x23c2;
  ovr_calcSeasonPalette
            ((uint8_t *)CONCAT22((uint8_t *)((int)register0x00000010 + -0x306),puVar3),unaff_SS,
             (uint8_t *)(*(uint16_t *)((uint8_t *)&(palette))),(*(uint16_t *)((uint8_t *)&(palette) + 2)),psVar2);
  if (GameRunning == false) {
    uVar4 = 0x22a6;
    ovr_vgaSetPalette8bit();
  }
  (*(uint8_t *)((uint8_t *)&(uStack_308))) = (char)uVar4;
  (*(uint8_t *)((uint8_t *)&(uStack_308) + 1)) = (char)((uint)uVar4 >> 8);
  ovr_manage_mapPartySlots();
  return;
}



/* 3381:233e */

/* Returns the GMapCells[y][x] byte inside the map bounds, else 0. */

uint __cdecl16far init_getMapCell(int x,int y,...)

{
  uint in_AX;
  uint uVar1;
  int in_stack_00000004;
  
  if ((((in_stack_00000004 < 0x94) && (-1 < in_stack_00000004)) && (x < 0x3c)) && (-1 < x)) {
    uVar1 = CONCAT11((char)((uint)(x * 0x94) >> 8),
                     (*(byte (*) [59] [148])GMapCells)[x][in_stack_00000004]);
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
  int in_stack_00000004;
  
  if ((((in_stack_00000004 < 0x94) && (-1 < in_stack_00000004)) && (x < 0x3c)) && (-1 < x)) {
    (*(byte (*) [59] [148])GMapCells)[x][in_stack_00000004] = (byte)y;
  }
  return;
}



/* 3381:23b5 */

/* Returns the flag bits of GMapFlags[y][x] inside the map bounds, else 0. */

uint __cdecl16far init_getMapFlags(int x,int y,...)

{
  uint in_AX;
  uint uVar1;
  int in_stack_00000004;
  
  if ((((in_stack_00000004 < 0x94) && (-1 < in_stack_00000004)) && (x < 0x3c)) && (-1 < x)) {
    uVar1 = CONCAT11((char)((uint)(in_stack_00000004 * 2) >> 8),
                     (char)(*(short (*) [60] [148])GMapFlags)[x][in_stack_00000004]) & 0xff03;
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
  int unaff_DI;
  
  uVar1 = init_getMapCell(y,unaff_DI,x);
  uVar1 = uVar1 & 0xff;
  uVar2 = init_getMapCell(y,uVar1,x + 1);
  iVar3 = uVar1 + (uVar2 & 0xff);
  uVar1 = init_getMapCell(y + 1,iVar3,x);
  iVar3 = iVar3 + (uVar1 & 0xff);
  uVar1 = init_getMapCell(y + 1,iVar3,x + 1);
  return iVar3 + (uVar1 & 0xff);
}



/* 3381:2452 */

/* [R7] body shape: compute */

undefined2 __cdecl16far init_compute2(int x,int y,byte direction)

{
  uint in_AX;
  int unaff_DI;
  byte bStack_3;
  
  bStack_3 = 0;
  while( true ) {
    if (3 < bStack_3) {
      return CONCAT11((char)(in_AX >> 8),1);
    }
    in_AX = (uint)bStack_3;
    if ((in_AX != (direction ^ 2)) &&
       (in_AX = init_getMapFlags(y + *(char *)(bStack_3 + 0x889),unaff_DI,
                                 x + *(char *)(bStack_3 + 0x885)), (char)in_AX != '\0')) break;
    bStack_3 = bStack_3 + 1;
  }
  return in_AX & 0xff00;
}



/* 3381:24c3 */

/* [R4] calls ovr_randBelow */

uint16_t __cdecl16far
init_usesRandBelow(int16_t x,int16_t y,uint8_t dir,uint8_t *lastDir,uint8_t *sameDirCount,...)

{
  char cVar1;
  int iVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  uint16_t uVar6;
  undefined1 uVar9;
  uint uVar7;
  uint uVar8;
  uint16_t unaff_DI;
  int in_stack_00000004;
  undefined1 uStack000b;
  uint uStack_e;
  uint uStack_c;
  byte bStack_8;
  byte bStack_7;
  byte bStack_6;
  byte bStack_5;
  byte bStack_3;
  
  iVar2 = in_stack_00000004;
  iVar5 = init_sumMapCells2x2(in_stack_00000004,x);
  uStack_e = iVar5 + 0x14;
  bStack_6 = 0xff;
  bStack_5 = 0xff;
  bStack_7 = 0xff;
  bStack_8 = 0xff;
  uVar6 = ovr_randBelow(unaff_DI,4);
  uVar9 = (undefined1)(uVar6 >> 8);
  uStack_c = uStack_e;
  bStack_3 = (byte)uVar6;
  do {
    uVar8 = CONCAT11(uVar9,bStack_3 - (char)y) & 0xff03;
    cVar3 = (char)uVar8;
    if ((cVar3 != '\x02') &&
       ((*(byte *)CONCAT22((uint8_t *)sameDirCount,(*(uint16_t *)((uint8_t *)&(lastDir) + 2))) < 2 ||
        (cVar1 = *(char *)CONCAT22((uint8_t *)lastDir,(char *)CONCAT11(uStack000b,dir)),
        uVar8 = CONCAT11((char)(uVar8 >> 8),cVar1), cVar1 != cVar3)))) {
      bStack_8 = bStack_3;
      uVar7 = init_sumMapCells2x2(iVar2 + *(char *)(bStack_3 + 0x885),
                                  x + *(char *)(bStack_3 + 0x889));
      if (uVar7 <= uStack_c) {
        bStack_5 = bStack_3;
        uStack_c = uVar7;
      }
      uVar8 = init_compute2(iVar2 + *(char *)(bStack_3 + 0x885),x + *(char *)(bStack_3 + 0x889),
                            bStack_3);
      uVar9 = (undefined1)(uVar8 >> 8);
      if ((char)uVar8 != '\0') {
        uVar8 = CONCAT11(uVar9,bStack_3);
        bStack_7 = bStack_3;
        if (uVar7 <= uStack_e) {
          uVar8 = CONCAT11(uVar9,bStack_3);
          bStack_6 = bStack_3;
          uStack_e = uVar7;
        }
      }
    }
    uVar8 = CONCAT11((char)(uVar8 >> 8),bStack_3 + 1) & 0xff03;
    bStack_3 = (byte)uVar8;
    uVar9 = (undefined1)(uVar8 >> 8);
  } while (bStack_3 != (byte)uVar6);
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
  bVar4 = bStack_3 - (char)y & 3;
  if (bVar4 != 0) {
    if (*(byte *)CONCAT22((uint8_t *)lastDir,(byte *)CONCAT11(uStack000b,dir)) == bVar4) {
      *(byte *)CONCAT22((uint8_t *)sameDirCount,(*(uint16_t *)((uint8_t *)&(lastDir) + 2))) =
           *(byte *)CONCAT22((uint8_t *)sameDirCount,(*(uint16_t *)((uint8_t *)&(lastDir) + 2))) + 1;
    }
    else {
      *(byte *)CONCAT22((uint8_t *)sameDirCount,(*(uint16_t *)((uint8_t *)&(lastDir) + 2))) = 0;
      *(byte *)CONCAT22((uint8_t *)lastDir,(byte *)CONCAT11(uStack000b,dir)) = bVar4;
    }
  }
  return CONCAT11(uVar9,bStack_3);
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
  int iVar5;
  uint uVar6;
  byte (*paabVar7) [59] [148];
  short (*paasVar8) [60] [148];
  uint y;
  undefined2 unaff_DI;
  uint x;
  undefined2 uVar9;
  uint8_t *unaff_SS;
  uint8_t dir;
  byte cell;
  undefined1 uVar10;
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
  
  cell = (byte)unaff_DI;
  uVar10 = (undefined1)((uint)unaff_DI >> 8);
  dst.seg = (uint16_t)unaff_SS;
  dst.ofs = (uint16_t)&edgeMasks;
  F_SCOPY(far_from_u32((uint32_t)(0x241004f2)),dst);
  dst_00.seg = (uint16_t)unaff_SS;
  dst_00.ofs = (uint16_t)&neighbourOfs;
  F_SCOPY(far_from_u32((uint32_t)(0x24100502)),dst_00);
  iStack_12 = 0;
  do {
    if ((int)(uint)randomFeatureCount <= iStack_12) {
      return;
    }
    uVar2 = ovr_randBelow(CONCAT11(uVar10,cell),0x93);
    y = uVar2 & 0xff;
    uVar2 = ovr_randBelow(CONCAT11(uVar10,cell),0x3b);
    x = uVar2 & 0xff;
    bStack_b = 100;
    uVar3 = init_getMapCell(x,y);
    bStack_c = (byte)uVar3;
    if (bStack_c < bStack_b) {
      bStack_b = bStack_c;
    }
    uVar3 = init_getMapCell(x,y + 1);
    bStack_c = (byte)uVar3;
    if (bStack_c < bStack_b) {
      bStack_b = bStack_c;
    }
    uVar3 = init_getMapCell(x + 1,y);
    bStack_c = (byte)uVar3;
    if (bStack_c < bStack_b) {
      bStack_b = bStack_c;
    }
    uVar3 = init_getMapCell(x + 1,y + 1);
    bStack_c = (byte)uVar3;
    if (bStack_c < bStack_b) {
      bStack_b = bStack_c;
    }
    iVar5 = CONCAT11((char)(uVar3 >> 8),bStack_b);
    init_setMapCell(x,iVar5,cell,y);
    iVar4 = y + 1;
    init_setMapCell(x,CONCAT11((char)((uint)iVar5 >> 8),bStack_b),cell,iVar4);
    iVar5 = x + 1;
    init_setMapCell(iVar5,CONCAT11((char)((uint)iVar4 >> 8),bStack_b),cell,y);
    init_setMapCell(x + 1,CONCAT11((char)((uint)iVar5 >> 8),bStack_b),cell,y + 1);
    if (bStack_b == 0) {
      init_usesGMapFlags3(y,x);
      init_usesGMapFlags3(y - 1,x);
      init_usesGMapFlags3(y + 1,x);
      init_usesGMapFlags3(y,x - 1);
      init_usesGMapFlags3(y,x + 1);
    }
    lastDir = 0x0;
    sameDirCount = 0x0;
    uVar2 = ovr_randBelow(CONCAT11(uVar10,cell),4);
    bStack_13 = (byte)uVar2;
    for (; ((((int)y < 0x93 && (-1 < (int)y)) && ((int)x < 0x3b)) && (-1 < (int)x));
        x = x + (int)*(char *)(bStack_14 + 0x889)) {
      uVar9 = (undefined2)((ulong)GMapCells >> 0x10);
      paabVar7 = (byte (*) [59] [148])GMapCells;
      if ((((*paabVar7)[x][y] == 0) && ((*paabVar7)[x][y + 1] == 0)) &&
         (((*paabVar7)[x + 1][y] == 0 && ((*paabVar7)[x + 1][y + 1] == 0)))) break;
      uVar9 = (undefined2)((ulong)GMapFlags >> 0x10);
      paasVar8 = (short (*) [60] [148])GMapFlags;
      if (((*paasVar8)[x][y] & 3U) == 3) break;
      if (((*paasVar8)[x][y] & 3U) != 0) {
        puVar1 = (uint *)((*paasVar8)[x] + y);
        *puVar1 = *puVar1 | 3;
      }
      dir = (uint8_t)&lastDir;
      uVar2 = init_usesRandBelow(x,CONCAT11((char)((uint)&lastDir >> 8),bStack_13),dir,
                                 (uint8_t *)CONCAT22(&sameDirCount,unaff_SS),
                                 (uint8_t *)CONCAT13(uVar10,CONCAT12(cell,unaff_SS)),y,dir);
      bStack_14 = (byte)uVar2;
      if (((bStack_14 == 0xff) || (bStack_13 == (bStack_14 ^ 2))) ||
         ((&edgeMasks)[(uint)bStack_13 * 4 + (uVar2 & 0xff)] == 0x0)) break;
      puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[x] + y);
      *puVar1 = *puVar1 & 0xfffb;
      puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[x] + y);
      *puVar1 = *puVar1 | (uint)(&edgeMasks)[(uint)bStack_13 * 4 + (uVar2 & 0xff)];
      uVar3 = init_getMapCell(x + ((int)(uint)abStack_9[(uint)bStack_13 * 2 + -1] >> 1),
                              y + (abStack_9[(uint)bStack_13 * 2 + -1] & 1));
      bStack_c = (byte)uVar3;
      uVar3 = init_getMapCell(x + ((int)(uint)abStack_9[(uint)bStack_13 * 2] >> 1),
                              y + (abStack_9[(uint)bStack_13 * 2] & 1));
      bStack_d = (byte)uVar3;
      if (bStack_c < bStack_b) {
        bStack_b = bStack_c;
      }
      if (bStack_d < bStack_b) {
        bStack_b = bStack_d;
      }
      uVar6 = abStack_9[(uint)bStack_14 * 2 + -1] & 1;
      init_setMapCell(x + ((int)(uint)abStack_9[(uint)bStack_14 * 2 + -1] >> 1),
                      CONCAT11((char)(uVar3 >> 8),bStack_b),cell,y + uVar6);
      init_setMapCell(x + ((int)(uint)abStack_9[(uint)bStack_14 * 2] >> 1),
                      CONCAT11((char)(uVar6 >> 8),bStack_b),cell,
                      y + (abStack_9[(uint)bStack_14 * 2] & 1));
      if (bStack_b == 0) {
        init_usesGMapFlags3(y,x);
        init_usesGMapFlags3(y - 1,x);
        init_usesGMapFlags3(y + 1,x);
        init_usesGMapFlags3(y,x - 1);
        init_usesGMapFlags3(y,x + 1);
      }
      y = y + (int)*(char *)(bStack_14 + 0x885);
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
  uint *in_AX;
  int x;
  undefined2 unaff_DI;
  int iVar2;
  byte bStack_3;
  
  for (iVar2 = 0; iVar2 < 0x94; iVar2 = iVar2 + 1) {
    for (x = 0; x < 0x3c; x = x + 1) {
      for (bStack_3 = 0; bStack_3 < 4; bStack_3 = bStack_3 + 1) {
        in_AX = ovr_ovc23_usesAlignUp43
                          (x,CONCAT11((char)((uint)in_AX >> 8),bStack_3),(byte)unaff_DI,iVar2);
        if ((char)in_AX != '\0') {
          in_AX = (uint *)(0x10 << (bStack_3 & 0x1f));
          puVar1 = (uint *)((*(short (*) [60] [148])GMapFlags)[x] + iVar2);
          *puVar1 = *puVar1 | (uint)in_AX;
        }
      }
    }
  }
  return;
}



/* 3381:2d9e */

void __cdecl16far init_grayscale_palette(void)

{
  far_t dst;
  far_t handle;
  stg_tmp_t *psVar1;
  uint16_t max_c;
  uint16_t in_DX;
  uint16_t i;
  uint unaff_DI;
  uint16_t unaff_SS;
  char buf [12];
  stg_tmp_t *pgfx;
  uint32_t gfx;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)buf;
  F_SCOPY(far_from_u32((uint32_t)(0x2410050e)),dst);
  if (GrayscalePalette.ofs == 0 && GrayscalePalette.seg == 0) {
    GrayscalePalette.ofs = (uint16_t)ovr_stshAlloc((ulong)unaff_DI << 0x10,0x100);
    GrayscalePalette.seg = in_DX;
  }
  handle.seg = unaff_DI;
  handle.ofs = Lbm_nwpanel1.seg;
  psVar1 = ovr_stshLoadGfx(handle,Lbm_nwpanel1.ofs);
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

/* WARNING: Variable defined which should be unmapped: msg */

void __cdecl16far copyProtectionCheck(void)

{
  far_t handle;
  uint16_t uVar1;
  char *pcVar2;
  undefined1 *textSeg;
  char *pcVar3;
  int iVar4;
  char *in_DX;
  char *unaff_SS;
  uint16_t uVar5;
  byte *pbVar6;
  undefined2 uVar7;
  uint16_t uVar8;
  uint8_t msg;
  undefined1 uStack_5b;
  uint16_t input;
  undefined4 uStack_8;
  uint8_t attempts;
  uint8_t codes;
  
  if (CopyProtectionDone == '\0') {
    uVar1 = ovr_randBelow(CONCAT11(uStack_5b,msg),0x19);
    attempts = 0x0;
    while( true ) {
      if (3 < attempts) {
        if (SaveAuto != '\0') {
          ovr_stSave();
        }
                    /* WARNING: Subroutine does not return */
        ovr_stExit(CONCAT11(uStack_5b,msg),0);
      }
      ovr_saveui_blitPanel();
      TextBlitX = 0x16;
      TextBlitY = 0xc;
      ovr_blitText((char *)CONCAT22(Font03.ofs,(char *)"puppetmaker" + 3),
                   (byte *)CONCAT22(0xde,Font03.seg),8,msg,0x6b1);
      TextBlitX = 0x16;
      TextBlitY = 0x2f;
      uVar8 = 8;
      uVar7 = 0xde;
      uVar5 = Font03.ofs;
      pbVar6 = (byte *)Font03.seg;
      pcVar2 = ovr_stsprintf((char *)CONCAT22(0x6cd,unaff_SS),
                             (char *)(ulong)CONCAT12(*(undefined1 *)((uVar1 & 0xff) + 0x51a),0x2410)
                             ,(char *)Font03.ofs,&msg);
      ovr_blitText((char *)CONCAT22(uVar5,in_DX),(byte *)CONCAT22(uVar7,pbVar6),uVar8,msg,pcVar2);
      TextBlitX = 0x16;
      TextBlitY = 0x43;
      uVar8 = 8;
      uVar7 = 0xde;
      uVar5 = Font03.ofs;
      pbVar6 = (byte *)Font03.seg;
      pcVar2 = ovr_stsprintf((char *)CONCAT22(0x6ed,unaff_SS),
                             (char *)(ulong)CONCAT12(*(undefined1 *)((uVar1 & 0xff) + 0x533),0x2410)
                             ,(char *)Font03.ofs,&msg);
      ovr_blitText((char *)CONCAT22(uVar5,in_DX),(byte *)CONCAT22(uVar7,pbVar6),uVar8,msg,pcVar2);
      TextBlitX = 0x16;
      TextBlitY = 0x57;
      ovr_blitText((char *)CONCAT22(Font03.ofs,(char *)"puppetmaker" + 3),
                   (byte *)CONCAT22(0xde,Font03.seg),8,msg,0x712);
      textSeg = ovr_stshAlloc((ulong)CONCAT11(uStack_5b,msg) << 0x10,2);
      uStack_8 = (undefined1 *)CONCAT22(in_DX,textSeg);
      *uStack_8 = *(undefined1 *)*(undefined4 *)((uVar1 & 0xff) * 4 + 0x54c);
      textSeg[1] = 0;
      pcVar3 = ovr_uiReadString((char *)0x60000,(int)textSeg,(int)in_DX,(char *)0x0);
      pcVar2 = in_DX;
      init_normalizeName((uint32_t)CONCAT22(in_DX,pcVar3));
      if (UserWantsExit != '\0') {
        if (SaveAuto != '\0') {
          ovr_stSave();
        }
                    /* WARNING: Subroutine does not return */
        ovr_stExit(CONCAT11(uStack_5b,msg),0);
      }
      if (pcVar3 != (char *)0x0 || in_DX != (char *)0x0) break;
      attempts = attempts + 0x1;
      in_DX = pcVar2;
    }
    iVar4 = (uVar1 & 0xff) * 4;
    _fstricmp((char *)CONCAT22(in_DX,pcVar3),
              (char *)CONCAT22(*(undefined2 *)(iVar4 + 0x54e),(char *)*(undefined2 *)(iVar4 + 0x54c)
                              ));
    (*(uint8_t *)((uint8_t *)&(handle.seg))) = msg;
    handle.ofs = (uint16_t)in_DX;
    (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = uStack_5b;
    ovr_stshFree(handle,pcVar3);
    ovr_saveui_blitPanel();
    CopyProtectionDone = '\x01';
  }
  return;
}


