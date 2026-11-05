/*
 * ovc09_init.c - recovered from STRONG.EXE
 * memory block: OVC09_init.c
 * range: 3381:0000 - 3381:34cf
 * functions: 31
 */
#include "recovered.h"


/* 3381:0000 */

void __cdecl16far init_3381_0000(void)

{
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  
  gfx_00.seg = DAT_2000_cacf;
  gfx_00.ofs = DAT_2000_cacd;
  ovr_blitLoadRleGfx(gfx_00,(far_t)0xa0000000);
  gfx_01.seg = DAT_2000_d1a1;
  gfx_01.ofs = DAT_2000_d19f;
  ovr_blitLoadRleGfx(gfx_01,(far_t)0xa00009af);
  gfx.seg = DAT_2000_d1a5;
  gfx.ofs = DAT_2000_d1a3;
  ovr_blitGfxRect(gfx,0,0,BlitRects + 1,0x10,false);
  if (GameRunning == false) {
    gfx_02.seg = DAT_2000_caf3;
    gfx_02.ofs = DAT_2000_caf1;
    ovr_blitLoadRleGfx(gfx_02,(far_t)0xa000c51d);
    DAT_2000_d116 = 0;
  }
  return;
}



/* 3381:009a */

char * __cdecl16far append_name_to_path(char *path,char *name)

{
  size_t l;
  
  strcpy((char *)&GStaticBuffer,path);
  for (l = strlen((char *)&GStaticBuffer);
      (0 < (int)l && (((undefined1 *)&DAT_2000_ccb0)[l] != '\\')); l = l - 1) {
  }
  ((undefined *)&GStaticBuffer)[l] = 0;
  strcat((char *)&GStaticBuffer,name);
  return (char *)&GStaticBuffer;
}



/* 3381:00fe */

char * __cdecl16far path_strip_tail_slash(char *s)

{
  size_t l;
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
  size_t l;
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
  char c;
  int iVar1;
  undefined1 extraout_AH;
  undefined2 in_stack_00000006;
  
  iVar1 = chdir(path);
  if (iVar1 == 0) {
    c = toupper(*_path);
    if (((path[1] == ':') && ('@' < c)) && (c < '[')) {
      c = toupper(c);
      setdisk(CONCAT11(extraout_AH,c) + -0x41);
    }
  }
  return;
}



/* 3381:01c8 */

void __cdecl16far init_paths(void)

{
  char *full_path;
  
  getcwd((char *)GOriginalDir,0x44);
  strcpy((char *)&GWorkDir,(char *)GOriginalDir);
  ensure_tail_slash((char *)&GWorkDir);
  strcat((char *)&GWorkDir,(char *)"strong.sav\\");
  full_path = append_name_to_path((char *)GGameExe.ofs,(char *)"strong.sav\\" + 0xb);
  full_path = path_strip_tail_slash(full_path);
  chpath(full_path);
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
  char cVar1;
  int fh;
  int wrsz;
  char *pcVar2;
  char lbuf [80];
  byte goterr;
  uint8_t update;
  uint16_t crlf;
  char mice;
  char c;
  
  crlf = GCrLf;
  update = 0x0;
  pcVar2 = ovr_stsprintf(lbuf,"%sgame.cfg",(char *)&GWorkDir);
  fh = ovr_open_wait_unlock_and_disk((char *)pcVar2);
  if (fh < 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x80);
  }
  c = ovr_read_cfg(fh);
  if (c == '\0') {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x80);
  }
  cVar1 = c;
  if (((c < '1') || ('9' < c)) && ((c < 'A' || ('B' < c)))) {
    if ((c < 'a') || ('b' < c)) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x80);
    }
    cVar1 = toupper(c);
  }
  CFG_Sfx = cVar1;
  c = ovr_read_cfg(fh);
  if (c == '\0') {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x80);
  }
  cVar1 = c;
  if (((c < '1') || ('9' < c)) && ((c < 'A' || ('B' < c)))) {
    if ((c < 'a') || ('b' < c)) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x80);
    }
    cVar1 = toupper(c);
  }
  CFG_Mus = cVar1;
  c = ovr_read_cfg(fh);
  if (c == '\0') {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x80);
  }
  if (((c < '0') || ('9' < c)) && ((c < 'A' || ('F' < c)))) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x80);
  }
  CFG_Irq = c;
  mice = ovr_read_cfg(fh);
  if ((mice < '1') || ('2' < mice)) {
    init_cfg_mice();
    update = 0x1;
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
  if (update != 0x0) {
    pcVar2 = ovr_stsprintf(lbuf,"%sgame.cfg",(char *)&GWorkDir);
    fh = ovr_creat_wait_unlock_and_disk((char *)pcVar2);
    if (fh < 0) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x83);
    }
    wrsz = write(fh,(char *)&CFG_Sfx,1);
    goterr = wrsz != 1;
    wrsz = write(fh,&crlf,2);
    goterr = goterr | wrsz != 2;
    wrsz = write(fh,(char *)&CFG_Mus,1);
    goterr = wrsz != 1;
    wrsz = write(fh,&crlf,2);
    goterr = goterr | wrsz != 2;
    wrsz = write(fh,(char *)&CFG_Irq,1);
    goterr = wrsz != 1;
    wrsz = write(fh,&crlf,2);
    goterr = goterr | wrsz != 2;
    wrsz = write(fh,&mice,1);
    goterr = goterr | wrsz != 1;
    wrsz = write(fh,&crlf,2);
    goterr = goterr | wrsz != 2;
    fh = close(fh);
    goterr = goterr | (byte)fh;
    if (goterr != 0) {
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
  
  _OvrInitExt(0,0);
  _OvrInitEms(0,0,0);
  ovr_init_base();
  init_paths();
  init_cfg();
  clrscr();
  srand8(CONCAT22(*(undefined2 *)(BDA_DailyTimeCounter.ofs + 2),*(undefined2 *)BDA_DailyTimeCounter)
        );
  ovr_stshAlloc(0xfa0f);
  iVar1 = strcmp((char *)GExeArg.ofs,(char *)"debug");
  if (iVar1 == 0) {
    GDebug = true;
  }
  iVar1 = strcmp((char *)GExeArg.ofs,(char *)"grab");
  if (iVar1 == 0) {
    GDebug = true;
    ovr_init_assets(true);
  }
  else {
    ovr_init_assets(false);
  }
  ovr_stshInit();
  StshStrongDatHnd = ovr_stshOpen(0);
  ovr_sfxInit();
  ovr_musInit();
  ovr_gfxInitRand();
  ovr_miceInit();
  ovr_biosVideoCall(0x0,0x13);
  init_grayscale_palette();
  ovr_init_ui_gfxes();
  init_buffers();
  ovr_clean_ring_buffer();
  ovr_heapInit();
  ovr_play_sfx(83,0);
  return;
}



/* 3381:0693 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far init_3381_0693(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  
  for (iVar4 = 0; iVar4 < 0x3b; iVar4 = iVar4 + 1) {
    for (iVar3 = 0; iVar3 < 0x93; iVar3 = iVar3 + 1) {
      uVar5 = (undefined2)((ulong)DAT_2000_cb09 >> 0x10);
      iVar2 = (int)DAT_2000_cb09;
      if ((*(uint *)(iVar2 + iVar4 * 0x128 + iVar3 * 2) & 4) == 0) {
        if (((*(char *)(DAT_2000_cb05 + iVar4 * 0x94 + iVar3) == '\0') &&
            (*(char *)(iVar4 * 0x94 + DAT_2000_cb05 + iVar3 + 0x95) == '\0')) &&
           (*(char *)(iVar4 * 0x94 + DAT_2000_cb05 + iVar3 + 0x94) == '\0')) {
          puVar1 = (uint *)(iVar2 + iVar4 * 0x128 + iVar3 * 2);
          *puVar1 = *puVar1 | 1;
        }
        uVar5 = (undefined2)((ulong)_DAT_2000_cb05 >> 0x10);
        iVar2 = (int)_DAT_2000_cb05;
        if (((*(char *)(iVar2 + iVar4 * 0x94 + iVar3) == '\0') &&
            (*(char *)(iVar4 * 0x94 + iVar2 + iVar3 + 0x95) == '\0')) &&
           (*(char *)(iVar2 + iVar4 * 0x94 + iVar3 + 1) == '\0')) {
          puVar1 = (uint *)((int)DAT_2000_cb09 + iVar4 * 0x128 + iVar3 * 2);
          *puVar1 = *puVar1 | 2;
        }
      }
      else {
        if (((*(char *)(iVar4 * 0x94 + DAT_2000_cb05 + iVar3 + 0x94) == '\0') &&
            (*(char *)(DAT_2000_cb05 + iVar4 * 0x94 + iVar3 + 1) == '\0')) &&
           (*(char *)(DAT_2000_cb05 + iVar4 * 0x94 + iVar3) == '\0')) {
          puVar1 = (uint *)(iVar2 + iVar4 * 0x128 + iVar3 * 2);
          *puVar1 = *puVar1 | 1;
        }
        if (((*(char *)(iVar4 * 0x94 + DAT_2000_cb05 + iVar3 + 0x94) == '\0') &&
            (*(char *)(DAT_2000_cb05 + iVar4 * 0x94 + iVar3 + 1) == '\0')) &&
           (*(char *)(iVar4 * 0x94 + DAT_2000_cb05 + iVar3 + 0x95) == '\0')) {
          puVar1 = (uint *)((int)DAT_2000_cb09 + iVar4 * 0x128 + iVar3 * 2);
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
/* WARNING: Removing unreachable block (ram,0x00031440) */
/* WARNING: Removing unreachable block (ram,0x000313af) */
/* WARNING: Removing unreachable block (ram,0x000313d2) */
/* WARNING: Removing unreachable block (ram,0x00031406) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

stg_tmp_t * __cdecl16far init_3381_08dc(undefined4 param_1,int16_t param_2)

{
  uint *puVar1;
  uint16_t uVar2;
  far_t src;
  far_t buf;
  far_t buf_00;
  far_t buf_01;
  far_t buf_02;
  far_t buf_03;
  far_t buf_04;
  far_t buf_05;
  far_t buf_06;
  far_t dst;
  far_t handle;
  char cVar3;
  byte bVar4;
  uint16_t uVar5;
  uint uVar6;
  stg_tmp_t *psVar7;
  int in_CX;
  uint uVar8;
  uint uVar9;
  int iVar10;
  undefined2 unaff_SI;
  int iVar11;
  int iVar12;
  uint uVar13;
  long *file_id;
  undefined2 uVar14;
  uint16_t unaff_SS;
  longdouble in_ST0;
  long lVar15;
  uint32_t uVar16;
  byte abStackY_348 [488];
  uint8_t auStackY_160 [158];
  uint8_t auStackY_c2 [2];
  char *pcStackY_c0;
  far_t gfx;
  uint8_t auStack_a4 [92];
  uint16_t uStack_48;
  uint16_t uStack_46;
  uint8_t uStack_40;
  uint8_t uStack_3f;
  uint8_t uStack_3e;
  uint16_t uStack_34;
  uint16_t uStack_32;
  far_t fStack_30;
  uint8_t uStack_2c;
  lbm_type_t lStack_2b;
  undefined4 uStack_2a;
  undefined4 uStack_26;
  uint16_t uStack_22;
  int *piStack_20;
  far_t fStack_1e;
  uint16_t uStack_18;
  uint16_t uStack_16;
  int *piStack_14;
  uint16_t uStack_12;
  undefined2 uStack_10;
  uint16_t uStack_e;
  int *piStack_c;
  uint uStack_a;
  uint uStack_8;
  int iStack_6;
  byte bStack_3;
  
  uStack_10 = (int *)(uint)(byte)uStack_10;
  for (iVar11 = 0; iVar11 < 0x94; iVar11 = iVar11 + 1) {
    uVar5 = ovr_randBelow(10);
    if ((uVar5 & 0xff) == 0) {
      uVar5 = ovr_randBelow(2);
      cVar3 = (char)uVar5 * '\x02' + uStack_10._1_1_ + -1;
      uStack_10 = (int *)CONCAT11(cVar3,(byte)uStack_10);
      if (cVar3 < -1) {
        uStack_10 = (int *)CONCAT11(0xff,(byte)uStack_10);
      }
      if ('\x01' < (char)uStack_10._1_1_) {
        uStack_10 = (int *)CONCAT11(1,(byte)uStack_10);
      }
    }
    if ((iVar11 == 0) || (iVar11 == 0x93)) {
      uStack_10 = (int *)((uint)uStack_10 & 0xff);
    }
    auStack_a4[iVar11] = uStack_10._1_1_;
  }
  piStack_c = (int *)0x0;
  uStack_a = 0;
  _fsetmem(DAT_2000_cb0d,0x4560,0);
  _fsetmem(DAT_2000_cb09,0x4560,0);
  for (uVar13 = 0; (int)uVar13 < 0x3c; uVar13 = uVar13 + 1) {
    if ((uVar13 & 1) == 0) {
      for (iVar11 = 0; iVar11 < 0x94; iVar11 = iVar11 + 1) {
        piStack_c = (int *)0x0;
        if (iVar11 != 0) {
          piStack_c = (int *)(int)*(char *)(DAT_2000_cb05 + uVar13 * 0x94 + iVar11 + -1);
        }
        if (uVar13 != 0) {
          piStack_c = (int *)((int)piStack_c +
                             (int)*(char *)(uVar13 * 0x94 + DAT_2000_cb05 + iVar11 +
                                            (int)(char)auStack_a4[iVar11] + -0x94));
        }
        piStack_c = (int *)((int)piStack_c >> 1);
        if ((iVar11 != 0) && (auStack_a4[iVar11 + -1] != auStack_a4[iVar11])) {
          uVar5 = ovr_randBelow(8);
          uStack_8 = uVar5 & 0xff;
          if (uStack_8 == 1) {
            auStack_a4[iVar11] = auStack_a4[iVar11 + -1];
          }
          else if (uStack_8 == 2) {
            auStack_a4[iVar11 + -1] = auStack_a4[iVar11];
          }
        }
        uVar5 = ovr_randBelow(0x10);
        if ((uVar5 & 0xff) == 0) {
          if (iVar11 != 0) {
            uStack_10._1_1_ = auStack_a4[iVar11 + -1];
            uVar5 = ovr_randBelow(2);
            cVar3 = (char)uVar5 * '\x02' + uStack_10._1_1_ + -1;
            uStack_10 = (int *)CONCAT11(cVar3,(byte)uStack_10);
            if (cVar3 < -1) {
              uStack_10 = (int *)CONCAT11(0xff,(byte)uStack_10);
            }
            if ('\x01' < (char)uStack_10._1_1_) {
              uStack_10 = (int *)CONCAT11(1,(byte)uStack_10);
            }
            auStack_a4[iVar11] = uStack_10._1_1_;
          }
          if ((int)piStack_c < 0x56) {
            if ((int)piStack_c < 0x41) {
              if ((int)piStack_c < 0x2b) {
                if ((int)piStack_c < 0x16) {
                  if ((int)piStack_c < 1) {
                    uVar5 = ovr_randBelow(9);
                    uStack_a = (uVar5 & 0xff) - 2;
                  }
                  else {
                    uVar5 = ovr_randBelow(8);
                    uStack_a = (uVar5 & 0xff) - 5;
                  }
                }
                else {
                  uVar5 = ovr_randBelow(0x10);
                  uStack_a = (uVar5 & 0xff) - 8;
                }
              }
              else {
                uVar5 = ovr_randBelow(0xb);
                uStack_a = (uVar5 & 0xff) - 5;
              }
            }
            else {
              uVar5 = ovr_randBelow(8);
              uStack_a = (uVar5 & 0xff) - 4;
            }
          }
          else {
            uVar5 = ovr_randBelow(0x11);
            uStack_a = (uVar5 & 0xff) - 8;
          }
        }
        if ((int)piStack_c < 0x56) {
          if ((int)piStack_c < 0x41) {
            if ((int)piStack_c < 0x2b) {
              if ((int)piStack_c < 0x16) {
                if ((int)piStack_c < 1) {
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
        uVar5 = ovr_randBelow(uStack_e);
        piStack_c = (int *)((int)piStack_c + ((uVar5 & 0xff) - ((int)uStack_e >> 1)) + uStack_a + 1)
        ;
        if ((int)piStack_c < -0x23) {
          piStack_c = (int *)0xffdd;
          uStack_a = (uStack_a ^ (int)uStack_a >> 0xf) - ((int)uStack_a >> 0xf);
        }
        if (0x7f < (int)piStack_c) {
          piStack_c = (int *)&errno;
          uStack_a = -((uStack_a ^ (int)uStack_a >> 0xf) - ((int)uStack_a >> 0xf));
        }
        *(uint8_t *)((int)_DAT_2000_cb05 + uVar13 * 0x94 + iVar11) = (uint8_t)piStack_c;
      }
    }
    else {
      for (iVar11 = 0x93; -1 < iVar11; iVar11 = iVar11 + -1) {
        piStack_c = (int *)0x0;
        if (iVar11 != 0x93) {
          piStack_c = (int *)(int)*(char *)(DAT_2000_cb05 + uVar13 * 0x94 + iVar11 + 1);
        }
        if (uVar13 != 0) {
          piStack_c = (int *)((int)piStack_c +
                             (int)*(char *)(uVar13 * 0x94 + DAT_2000_cb05 + iVar11 +
                                            (int)(char)auStack_a4[iVar11] + -0x94));
        }
        piStack_c = (int *)((int)piStack_c >> 1);
        if ((iVar11 != 0x93) && (auStack_a4[iVar11 + 1] != auStack_a4[iVar11])) {
          uVar5 = ovr_randBelow(0x10);
          uStack_8 = uVar5 & 0xff;
          if (uStack_8 == 1) {
            auStack_a4[iVar11] = auStack_a4[iVar11 + 1];
          }
          else if (uStack_8 == 2) {
            auStack_a4[iVar11 + 1] = auStack_a4[iVar11];
          }
        }
        uVar5 = ovr_randBelow(0x10);
        if ((uVar5 & 0xff) == 0) {
          if (iVar11 != 0x93) {
            uStack_10._1_1_ = auStack_a4[iVar11 + 1];
            uVar5 = ovr_randBelow(2);
            cVar3 = (char)uVar5 * '\x02' + uStack_10._1_1_ + -1;
            uStack_10 = (int *)CONCAT11(cVar3,(byte)uStack_10);
            if (cVar3 < -1) {
              uStack_10 = (int *)CONCAT11(0xff,(byte)uStack_10);
            }
            if ('\x01' < (char)uStack_10._1_1_) {
              uStack_10 = (int *)CONCAT11(1,(byte)uStack_10);
            }
            auStack_a4[iVar11] = uStack_10._1_1_;
          }
          if ((int)piStack_c < 0x56) {
            if ((int)piStack_c < 0x41) {
              if ((int)piStack_c < 0x2b) {
                if ((int)piStack_c < 0x16) {
                  if ((int)piStack_c < 1) {
                    uVar5 = ovr_randBelow(9);
                    uStack_a = (uVar5 & 0xff) - 2;
                  }
                  else {
                    uVar5 = ovr_randBelow(8);
                    uStack_a = (uVar5 & 0xff) - 5;
                  }
                }
                else {
                  uVar5 = ovr_randBelow(0x10);
                  uStack_a = (uVar5 & 0xff) - 8;
                }
              }
              else {
                uVar5 = ovr_randBelow(0xb);
                uStack_a = (uVar5 & 0xff) - 5;
              }
            }
            else {
              uVar5 = ovr_randBelow(8);
              uStack_a = (uVar5 & 0xff) - 4;
            }
          }
          else {
            uVar5 = ovr_randBelow(0x11);
            uStack_a = (uVar5 & 0xff) - 8;
          }
        }
        if ((int)piStack_c < 0x56) {
          if ((int)piStack_c < 0x41) {
            if ((int)piStack_c < 0x2b) {
              if ((int)piStack_c < 0x16) {
                if ((int)piStack_c < 1) {
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
        uVar5 = ovr_randBelow(uStack_e);
        piStack_c = (int *)((int)piStack_c + ((uVar5 & 0xff) - ((int)uStack_e >> 1)) + uStack_a + 1)
        ;
        if ((int)piStack_c < -0x7f) {
          piStack_c = (int *)0xff81;
          uStack_a = (uStack_a ^ (int)uStack_a >> 0xf) - ((int)uStack_a >> 0xf);
        }
        if (0x7f < (int)piStack_c) {
          piStack_c = (int *)&errno;
          uStack_a = -((uStack_a ^ (int)uStack_a >> 0xf) - ((int)uStack_a >> 0xf));
        }
        *(uint8_t *)((int)_DAT_2000_cb05 + uVar13 * 0x94 + iVar11) = (uint8_t)piStack_c;
      }
    }
  }
  for (iVar11 = 0; iVar11 < 0x3c; iVar11 = iVar11 + 1) {
    for (iVar12 = 0; iVar12 < 0x94; iVar12 = iVar12 + 1) {
      uVar14 = (undefined2)((ulong)_DAT_2000_cb05 >> 0x10);
      if (*(char *)((int)_DAT_2000_cb05 + iVar11 * 0x94 + iVar12) < '\0') {
        *(undefined1 *)((int)_DAT_2000_cb05 + iVar11 * 0x94 + iVar12) = 0;
      }
      if ((iVar12 != 0x93) && (iVar11 != 0x3c)) {
        uVar14 = (undefined2)((ulong)_DAT_2000_cb05 >> 0x10);
        iVar10 = (int)_DAT_2000_cb05;
        uVar13 = (int)*(char *)(iVar11 * 0x94 + iVar10 + iVar12 + 0x94) -
                 (int)*(char *)(iVar10 + iVar11 * 0x94 + iVar12 + 1);
        uVar8 = (int)uVar13 >> 0xf;
        uVar6 = (int)*(char *)(iVar10 + iVar11 * 0x94 + iVar12) -
                (int)*(char *)(iVar11 * 0x94 + iVar10 + iVar12 + 0x95);
        uVar9 = (int)uVar6 >> 0xf;
        if ((int)((uVar13 ^ uVar8) - uVar8) < (int)((uVar6 ^ uVar9) - uVar9)) {
          puVar1 = (uint *)((int)(void *)DAT_2000_cb09 + iVar12 * 2 + iVar11 * 0x128);
          *puVar1 = *puVar1 | 4;
        }
      }
    }
  }
  init_3381_0693();
  init_3381_2883();
  init_3381_0693();
  file_id = (long *)0x0;
  do {
    if (0x3a < (int)file_id) {
      for (iVar11 = 1; iVar11 < 0x3a; iVar11 = iVar11 + 1) {
        for (iVar12 = 1; iVar12 < 0x92; iVar12 = iVar12 + 1) {
          uVar5 = ovr_randBelow(2);
          if ((uVar5 & 0xff) == 0) {
            uVar14 = (undefined2)((ulong)_DAT_2000_cb05 >> 0x10);
            iVar10 = (int)_DAT_2000_cb05;
            if (((((*(char *)(iVar10 + iVar11 * 0x94 + iVar12 + -1) != '\0') &&
                  (*(char *)(iVar11 * 0x94 + iVar10 + iVar12 + 0x93) != '\0')) &&
                 (*(char *)(iVar10 + iVar11 * 0x94 + iVar12) != '\0')) &&
                ((((*(char *)(iVar11 * 0x94 + iVar10 + iVar12 + 0x94) != '\0' &&
                   (*(char *)(iVar10 + iVar11 * 0x94 + iVar12 + 1) != '\0')) &&
                  ((*(char *)(iVar11 * 0x94 + iVar10 + iVar12 + 0x95) != '\0' &&
                   ((*(char *)(iVar10 + iVar11 * 0x94 + iVar12) <=
                     *(char *)(iVar10 + iVar11 * 0x94 + iVar12 + 1) &&
                    (*(char *)(iVar10 + iVar11 * 0x94 + iVar12) <=
                     *(char *)(iVar10 + iVar11 * 0x94 + iVar12 + -1))))))) &&
                 (*(char *)(iVar10 + iVar11 * 0x94 + iVar12) <=
                  *(char *)(iVar11 * 0x94 + iVar10 + iVar12 + -0x94))))) &&
               (((((*(char *)(iVar10 + iVar11 * 0x94 + iVar12 + 1) <=
                    *(char *)(iVar11 * 0x94 + iVar10 + iVar12 + -0x93) &&
                   (*(char *)(iVar10 + iVar11 * 0x94 + iVar12) <=
                    *(char *)(iVar11 * 0x94 + iVar10 + iVar12 + 0x94))) &&
                  (*(char *)(iVar10 + iVar11 * 0x94 + iVar12 + 1) <=
                   *(char *)(iVar11 * 0x94 + iVar10 + iVar12 + 0x95))) &&
                 ((cVar3 = init_3381_23b5(), cVar3 == '\0' &&
                  (cVar3 = init_3381_23b5(), cVar3 == '\0')))) &&
                (cVar3 = ovr_constr_36ce_3172(), cVar3 == '\x02')))) {
              iStack_6 = *(int *)((int)(void *)DAT_2000_cb0d + iVar11 * 2 + iVar12 * 0x78 + -0xf0);
              bStack_3 = *(byte *)((int)DAT_2000_ca95 + iStack_6 * 9);
              if ((*(byte *)((uint)bStack_3 * 0x27 + 0x11b) < 2) &&
                 (bVar4 = ovr_constr_36ce_3172(), bVar4 < 3)) {
                uVar5 = ovr_randBelow(5);
                *(int *)((int)(void *)DAT_2000_cb0d + iVar11 * 2 + iVar12 * 0x78 + -0x78) =
                     (uVar5 & 0xff) + 0x92;
                *(undefined2 *)((int)(void *)DAT_2000_cb0d + iVar11 * 2 + iVar12 * 0x78) = 0;
              }
            }
          }
        }
      }
      psVar7 = (stg_tmp_t *)init_3381_2d36();
      return psVar7;
    }
    for (iVar11 = 0; iVar11 < 0x93; iVar11 = iVar11 + 1) {
      uVar14 = (undefined2)((ulong)_DAT_2000_cb05 >> 0x10);
      iVar12 = (int)_DAT_2000_cb05;
      if ((((*(char *)(iVar12 + (int)file_id * 0x94 + iVar11) != '\0') &&
           (*(char *)(iVar12 + (int)file_id * 0x94 + iVar11 + 1) != '\0')) &&
          (*(char *)((int)file_id * 0x94 + iVar12 + iVar11 + 0x94) != '\0')) &&
         ((*(char *)((int)file_id * 0x94 + iVar12 + iVar11 + 0x94) != '\0' &&
          (cVar3 = init_3381_23b5(), cVar3 == '\0')))) {
        piStack_c = (int *)(int)*(char *)((int)_DAT_2000_cb05 + (int)file_id * 0x94 + iVar11);
        if ((int)piStack_c < 0x6b) {
          if ((int)piStack_c < 0x56) {
            if ((int)piStack_c < 0x40) {
              if ((int)piStack_c < 0x2b) {
                if ((int)piStack_c < 0x16) {
                  uVar5 = ovr_randBelow(4);
                  if ((uVar5 & 0xff) == 2) {
                    uVar5 = ovr_randBelow(6);
                    *(int *)((int)(void *)DAT_2000_cb0d + (int)file_id * 2 + iVar11 * 0x78) =
                         (uVar5 & 0xff) + 0x3d;
                  }
                  else if ((((uVar5 & 0xff) == 3) && (cVar3 = ovr_constr_36ce_306b(), cVar3 != '\0')
                           ) && (uVar5 = ovr_randBelow(2), (uVar5 & 0xff) == 0)) {
                    uVar5 = ovr_randBelow(9);
                    *(int *)((int)(void *)DAT_2000_cb0d + (int)file_id * 2 + iVar11 * 0x78) =
                         (uVar5 & 0xff) + 0x67;
                  }
                }
                else {
                  uVar5 = ovr_randBelow(4);
                  uVar13 = uVar5 & 0xff;
                  switch(uVar13) {
                  case 0:
                    func_0x000318f5();
                    lStack_2b = LBM_PBM;
                    goto LAB_30e6_0445;
                  case 1:
                    while( true ) {
                      uStack_18 = uStack_18 + uVar13;
                      psVar7 = (stg_tmp_t *)(iVar11 + (int)file_id);
                      if ((int)fStack_1e.seg <= (int)psVar7) {
                        psVar7 = (stg_tmp_t *)auStackY_160;
                        memcpy((uint8_t *)piStack_14,(uint8_t *)((int)piStack_c + (int)psVar7),
                               uStack_e);
                        piStack_14 = piStack_14 + 0xa0;
                      }
                      iVar11 = iVar11 + 1;
                      if (((int)uStack_10 <= iVar11) ||
                         (psVar7 = (stg_tmp_t *)(iVar11 + (int)file_id),
                         (int)piStack_20 < (int)psVar7)) break;
                      src.seg = uStack_16;
                      src.ofs = uStack_18;
                      dst.seg = unaff_SS;
                      dst.ofs = (uint16_t)auStackY_160;
                      uVar13 = ovr_unrle(src,dst,*(uint16_t *)((int)param_1 + 5));
                    }
                    return psVar7;
                  case 2:
                    *file_id = (long)in_ST0;
                    /* WARNING: Bad instruction - Truncating control flow here */
                    halt_baddata();
                  case 3:
                    goto switchD_3000_4a6e_caseD_3;
                  }
                }
              }
              else {
                uVar5 = ovr_randBelow(4);
                if ((uVar5 & 0xff) == 1) {
                  uVar5 = ovr_randBelow(6);
                  *(int *)((int)(void *)DAT_2000_cb0d + (int)file_id * 2 + iVar11 * 0x78) =
                       (uVar5 & 0xff) + 0x3d;
                }
                else if (((uVar5 & 0xff) == 3) && (cVar3 = ovr_constr_36ce_306b(), cVar3 != '\0')) {
                  uVar5 = ovr_randBelow(9);
                  *(int *)((int)(void *)DAT_2000_cb0d + (int)file_id * 2 + iVar11 * 0x78) =
                       (uVar5 & 0xff) + 0x67;
                }
              }
            }
            else {
              uVar5 = ovr_randBelow(4);
              if ((((uVar5 & 0xff) == 3) && (cVar3 = ovr_constr_36ce_306b(), cVar3 != '\0')) &&
                 (uVar5 = ovr_randBelow(2), (char)uVar5 != '\0')) {
                uVar5 = ovr_randBelow(9);
                *(int *)((int)(void *)DAT_2000_cb0d + (int)file_id * 2 + iVar11 * 0x78) =
                     (uVar5 & 0xff) + 0x67;
              }
            }
          }
          else {
            uVar5 = ovr_randBelow(4);
            if ((uVar5 & 0xff) == 1) {
              cVar3 = ovr_constr_36ce_306b();
              if (cVar3 != '\0') {
                uVar5 = ovr_randBelow(2);
                if ((uVar5 & 0xff) == 0) {
                  uVar5 = ovr_randBelow(6);
                  *(int *)((int)(void *)DAT_2000_cb0d + (int)file_id * 2 + iVar11 * 0x78) =
                       (uVar5 & 0xff) + 0x3d;
                }
                else {
                  uVar5 = ovr_randBelow(9);
                  *(int *)((int)(void *)DAT_2000_cb0d + (int)file_id * 2 + iVar11 * 0x78) =
                       (uVar5 & 0xff) + 0x67;
                }
              }
            }
            else if (((uVar5 & 0xff) == 3) && (cVar3 = ovr_constr_36ce_306b(), cVar3 != '\0')) {
              uVar5 = ovr_randBelow(9);
              *(int *)((int)(void *)DAT_2000_cb0d + (int)file_id * 2 + iVar11 * 0x78) =
                   (uVar5 & 0xff) + 0x67;
            }
          }
        }
        else {
          uVar5 = ovr_randBelow(4);
          if ((((uVar5 & 0xff) == 2) || ((uVar5 & 0xff) == 3)) &&
             (cVar3 = ovr_constr_36ce_306b(), cVar3 != '\0')) {
            uVar5 = ovr_randBelow(9);
            *(int *)((int)(void *)DAT_2000_cb0d + (int)file_id * 2 + iVar11 * 0x78) =
                 (uVar5 & 0xff) + 0x67;
          }
        }
      }
    }
    file_id = (long *)((int)file_id + 1);
  } while( true );
switchD_3000_4a6e_caseD_3:
  do {
    *(int *)(&stack0xd744 + iVar11) = *(int *)(&stack0xd744 + iVar11) + in_CX;
    bVar4 = constr_36ce_04c4();
    uStack_2a._2_2_ = (uint)bVar4;
    ovr_OVC07_32c9_0044();
    bVar4 = constr_36ce_04c4();
    uStack_2a._0_2_ = (uint)bVar4;
    ovr_OVC07_32c9_0044();
    while( true ) {
      cVar3 = constr_36ce_306b();
      if (cVar3 != '\0') {
        ovr_OVC07_32c9_0466();
      }
      do {
        file_id = (long *)((int)file_id + 1);
        iVar12 = DAT_2000_cdcc;
        if (DAT_2000_cdc6 <= (int)file_id) {
          for (; iVar12 < DAT_2000_cdc6; iVar12 = iVar12 + 1) {
            uStack_26._2_2_ = ((undefined2 *)&DAT_2000_ce26)[iVar12];
            uStack_e = constr_36ce_0159();
            if ((*(byte *)(uStack_e * 0x27 + 0x11e) & 2) != 0) {
              iVar11 = constr_36ce_0101();
              uStack_10 = (int *)(iVar11 / 3);
              ovr_blit_317e_0db7();
            }
            if ((*(byte *)(uStack_e * 0x27 + 0x11e) & 1) != 0) {
              gfx.seg = *(uint16_t *)
                         ((char *)
                          "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                          + 0x38 + uStack_e * 0xc);
              gfx.ofs = *(uint16_t *)
                         ((char *)
                          "You may raise a primary ability by trading two points of another ability. Select ability to increase."
                          + 0x36 + uStack_e * 0xc);
              ovr_blitGfxRect(gfx,((undefined2 *)&DAT_2000_ceb6)[iVar12],51,BlitRects + 3,
                              (uint8_t)uStack_a,false);
            }
          }
          return (stg_tmp_t *)((char *)"puppetmaker" + 3);
        }
      } while (((int)((undefined2 *)&DAT_2000_ce6e)[(int)file_id] < 0xef) ||
              (0x134 < (int)((undefined2 *)&DAT_2000_ceb6)[(int)file_id]));
      uStack_26._2_2_ = ((undefined2 *)&DAT_2000_ce26)[(int)file_id];
      fStack_1e.seg = constr_36ce_0000();
      fStack_1e.ofs = constr_36ce_0000();
      iVar12 = constr_36ce_0101();
      uStack_10 = (int *)(iVar12 / 3);
      iVar12 = constr_36ce_0101();
      uStack_12 = iVar12 / 3;
      lStack_2b = constr_36ce_0080();
      if ((lStack_2b & 4) != 0) break;
      bVar4 = constr_36ce_04c4();
      uStack_2a._2_2_ = (uint)bVar4;
      ovr_OVC07_32c9_0044();
      bVar4 = constr_36ce_04c4();
      uStack_2a._0_2_ = (uint)bVar4;
      ovr_OVC07_32c9_0044();
    }
  } while( true );
LAB_30e6_0445:
  buf.seg = unaff_SS;
  buf.ofs = (uint16_t)&uStack_22;
  lVar15 = ovr_stshRead((uint16_t)file_id,buf,4);
  if (lVar15 != 0) {
bad_lbm:
    uVar5 = fStack_30.seg;
    psVar7 = (stg_tmp_t *)fStack_30.ofs;
    if ((&psVar7->bptr)->ofs != 0 || (psVar7->bptr).seg != 0) {
      uVar2 = (psVar7->bptr).seg;
      handle.seg._0_1_ = (uint8_t)uVar2;
      handle.ofs = (&psVar7->bptr)->ofs;
      handle.seg._1_1_ = (uint8_t)(uVar2 >> 8);
      ovr_stshFree(handle);
    }
    ovr_stshClose((uint16_t)file_id);
    ovr_stshFree(fStack_30);
    printf("Filename %d %s  \r",(int)param_1);
    ovr_biosReadKey();
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0xd);
  }
  if ((piStack_20 == piStack_c) && (uStack_22 == uStack_e)) {
    uStack_2c = 0x1;
    buf_00.seg = unaff_SS;
    buf_00.ofs = (uint16_t)&uStack_2a;
    lVar15 = ovr_stshRead((uint16_t)file_id,buf_00,4);
    if (lVar15 != 0) goto bad_lbm;
    uVar16 = ovr_be4(uStack_2a);
    uStack_2a = uVar16;
    if (uVar16 != 0x14) goto bad_lbm;
    buf_01.seg = unaff_SS;
    buf_01.ofs = (uint16_t)&uStack_48;
    lVar15 = ovr_stshRead((uint16_t)file_id,buf_01,0x14);
    if (lVar15 != 0) goto bad_lbm;
    uStack_32 = ovr_be2(uStack_48);
    uStack_34 = ovr_be2(uStack_46);
    goto LAB_30e6_0445;
  }
  if ((piStack_20 == piStack_14) && (uStack_22 == uStack_16)) {
    buf_02.seg = unaff_SS;
    buf_02.ofs = (uint16_t)&uStack_2a;
    ovr_stshRead((uint16_t)file_id,buf_02,4);
    uVar16 = ovr_be4(uStack_2a);
    uStack_2a = uVar16;
    uStack_26 = uVar16;
    if ((uVar16 & 1) != 0) {
      uStack_26 = uVar16 + 1;
    }
    if ((long)uStack_26 < 0x300) {
      if (0 < (long)uStack_26) {
        buf_04.seg = unaff_SS;
        buf_04.ofs = (uint16_t)abStackY_348;
        ovr_stshRead((uint16_t)file_id,buf_04,uStack_26);
      }
    }
    else {
      buf_03.seg = unaff_SS;
      buf_03.ofs = (uint16_t)abStackY_348;
      ovr_stshRead((uint16_t)file_id,buf_03,0x300);
      if (0x300 < (long)uStack_26) {
        uVar16 = ovr_stshTell((uint16_t)file_id);
        lVar15 = uStack_26 + (long)(int)uVar16;
        ovr_stshSeek((uint16_t)file_id,
                     CONCAT22(unaff_SI,(int)((ulong)lVar15 >> 0x10) + -1 +
                                       (uint)(0x2ff < (uint)lVar15)));
      }
    }
    uVar13 = 0;
    while( true ) {
      uVar16 = uStack_2a;
      if (0x300 < (long)uStack_2a) {
        uVar16 = 0x300;
      }
      if (((long)uVar16 < 0x10000) && (((int)(uVar16 >> 0x10) != 0 || ((uint)uVar16 <= uVar13))))
      break;
      ((stg_tmp_t *)fStack_30.ofs)->cmap[uVar13] = (uint8_t)((int)(uint)abStackY_348[uVar13] >> 2);
      uVar13 = uVar13 + 1;
    }
  }
  else {
    if ((piStack_20 == uStack_10) && (uStack_22 == uStack_12)) {
      if (uStack_2c != 0x0) {
        buf_05.seg = unaff_SS;
        buf_05.ofs = (uint16_t)&uStack_2a;
        ovr_stshRead((uint16_t)file_id,buf_05,4);
        uVar16 = ovr_be4(uStack_2a);
        uStack_26 = uVar16;
        if ((uVar16 & 1) != 0) {
          uStack_26 = uVar16 + 1;
        }
        uStack_2a = uVar16;
        fStack_1e = (far_t)ovr_stshAlloc(uStack_26);
        ovr_stshRead((uint16_t)file_id,fStack_1e,uStack_26);
        ovr_stshClose((uint16_t)file_id);
        pcStackY_c0 = (char *)"glassworks" + 9;
        auStackY_c2[0] = 0x2a;
        auStackY_c2[1] = 0x15;
        lbm_decode_body(lStack_2b,uStack_3e,uStack_40,uStack_3f,fStack_1e,(stg_tmp_t *)fStack_30,
                        param_1._2_2_,param_2,uStack_32,uStack_34);
        ovr_stshFree(fStack_1e);
        return (stg_tmp_t *)fStack_30.ofs;
      }
      goto bad_lbm;
    }
    buf_06.seg = unaff_SS;
    buf_06.ofs = (uint16_t)&uStack_26;
    ovr_stshRead((uint16_t)file_id,buf_06,4);
    uVar16 = ovr_be4(uStack_26);
    if ((uVar16 & 1) != 0) {
      uVar16 = uVar16 + 1;
    }
    uStack_26 = uVar16;
    uVar16 = ovr_stshTell((uint16_t)file_id);
    ovr_stshSeek((uint16_t)file_id,CONCAT22(unaff_SI,(int)(uStack_26 + (long)(int)uVar16 >> 0x10)));
  }
  goto LAB_30e6_0445;
}



/* 3381:1697 */

void __cdecl16far init_3381_1697(void)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 0xf8; iVar1 = iVar1 + 1) {
    *(undefined1 *)((int)DAT_2000_ca95 + iVar1 * 9) = (char)iVar1;
    *(undefined1 *)((int)DAT_2000_ca95 + iVar1 * 9 + 1) = 0xff;
    *(undefined1 *)((int)DAT_2000_ca95 + iVar1 * 9 + 2) = 0xff;
  }
  return;
}



/* 3381:16ef */

void __cdecl16far init_buffers(void)

{
  void *pvVar1;
  
  DAT_2000_ca95 = ovr_stshAlloc(0x2a30);
  _fsetmem(DAT_2000_ca95,0x2a30,0);
  init_3381_1697();
  DAT_2000_ca99 = 0xf8;
  DAT_2000_cb0d = ovr_stshAlloc(0x4560);
  DAT_2000_cb09 = ovr_stshAlloc(0x4560);
  pvVar1 = ovr_stshAlloc(0x22b0);
  DAT_2000_cb07 = (undefined2)((ulong)pvVar1 >> 0x10);
  DAT_2000_cb05 = (void *)pvVar1;
  Entities = (far_t)ovr_stshAlloc(33000);
  DAT_2000_d2e8 = ovr_stshAlloc(0x6541);
  init_3381_17e8();
  DAT_2000_d1e6 = 0;
  GWantsExit2 = 0;
  DAT_2000_d116 = 0xff;
  return;
}



/* 3381:17e8 */

void __cdecl16far init_3381_17e8(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined2 unaff_SS;
  byte local_1e [10];
  uint uStack_14;
  uint uStack_12;
  char cStack_f;
  uint uStack_e;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  uint uStack_6;
  uint uStack_4;
  
  F_SCOPY(local_1e,(uint8_t *)0x4e8,10);
  DAT_2000_d020 = 0;
  cStack_f = '\b';
  do {
    if (cStack_f < '\0') {
      if (DAT_2000_d020 != 0x1b0) {
        printf("NEW MAXSQUARE %d \r",DAT_2000_d020);
        ovr_gameProcessKey();
      }
      DAT_2000_cfd6 = 0;
      cStack_f = '\x02';
      do {
        if (cStack_f < '\0') {
          if (DAT_2000_cfd6 != 0x24) {
            printf("NEW SMAXSQUARE %d \r",DAT_2000_cfd6);
            ovr_gameProcessKey();
          }
          return;
        }
        ((undefined2 *)&DAT_2000_cdcc)[cStack_f] = DAT_2000_cfd6;
        uStack_4 = ((uint)local_1e[cStack_f] * 0x30) / 0x30;
        uStack_6 = ((uint)local_1e[cStack_f + 1] * 0x30) / 0x30;
        *(int *)(cStack_f * 2 + -0x7328) =
             (uint)*(byte *)(cStack_f + 0x74c) + ((uint)local_1e[cStack_f + 1] * 0x3c) / 0x30;
        ((undefined2 *)&DAT_2000_cdd2)[cStack_f] =
             (uint)*(byte *)(cStack_f + 0x74b) + ((uint)local_1e[cStack_f] * 0x3c) / 0x30;
        uStack_14 = ((uint)local_1e[cStack_f] * 0x27) / 0x30;
        uStack_12 = ((uint)local_1e[cStack_f + 1] * 0x27) / 0x30;
        iStack_8 = 0x111 - uStack_14;
        uVar3 = 0;
        for (iVar1 = 0x111 - uStack_12; 0xee < (int)((iVar1 - uStack_6) + uStack_12 + uStack_6);
            iVar1 = iVar1 - uStack_6) {
          iStack_8 = iStack_8 - uStack_4;
          uVar3 = uVar3 - 1;
        }
        for (; 0x7fff < uVar3; uVar3 = uVar3 + 1) {
          if (0x23 < DAT_2000_cfd6) {
                    /* WARNING: Subroutine does not return */
            ovr_stExit(8);
          }
          ((undefined2 *)&DAT_2000_cf8e)[DAT_2000_cfd6] = iVar1 + uStack_12;
          ((undefined2 *)&DAT_2000_cefe)[DAT_2000_cfd6] =
               ((undefined2 *)&DAT_2000_cf8e)[DAT_2000_cfd6] + uStack_6;
          ((undefined2 *)&DAT_2000_ceb6)[DAT_2000_cfd6] = iStack_8 + uStack_14;
          ((undefined2 *)&DAT_2000_ce6e)[DAT_2000_cfd6] =
               ((undefined2 *)&DAT_2000_ceb6)[DAT_2000_cfd6] + uStack_4;
          ((undefined2 *)&DAT_2000_ce26)[DAT_2000_cfd6] = uVar3;
          if ((int)uVar3 < -1) {
            ((undefined2 *)&DAT_2000_cdde)[DAT_2000_cfd6] = 0;
          }
          else {
            ((undefined2 *)&DAT_2000_cdde)[DAT_2000_cfd6] = 1;
          }
          DAT_2000_cfd6 = DAT_2000_cfd6 + 1;
          iStack_8 = iStack_8 + uStack_4;
          iVar1 = iVar1 + uStack_6;
        }
        iStack_8 = 0x111 - uStack_14;
        iVar2 = 0;
        for (iVar1 = 0x111 - uStack_12; (int)(uStack_6 + iVar1 + uStack_12) < 0x135;
            iVar1 = iVar1 + uStack_6) {
          iStack_8 = iStack_8 + uStack_4;
          iVar2 = iVar2 + 1;
        }
        for (; -1 < iVar2; iVar2 = iVar2 + -1) {
          if (0x23 < DAT_2000_cfd6) {
                    /* WARNING: Subroutine does not return */
            ovr_stExit(8);
          }
          ((undefined2 *)&DAT_2000_cf8e)[DAT_2000_cfd6] = iVar1 + uStack_12;
          ((undefined2 *)&DAT_2000_cefe)[DAT_2000_cfd6] =
               ((undefined2 *)&DAT_2000_cf8e)[DAT_2000_cfd6] + uStack_6;
          ((undefined2 *)&DAT_2000_ceb6)[DAT_2000_cfd6] = iStack_8 + uStack_14;
          ((undefined2 *)&DAT_2000_ce6e)[DAT_2000_cfd6] =
               ((undefined2 *)&DAT_2000_ceb6)[DAT_2000_cfd6] + uStack_4;
          ((undefined2 *)&DAT_2000_ce26)[DAT_2000_cfd6] = iVar2;
          if (iVar2 < 1) {
            ((undefined2 *)&DAT_2000_cdde)[DAT_2000_cfd6] = 1;
          }
          else {
            ((undefined2 *)&DAT_2000_cdde)[DAT_2000_cfd6] = 2;
          }
          DAT_2000_cfd6 = DAT_2000_cfd6 + 1;
          iStack_8 = iStack_8 - uStack_4;
          iVar1 = iVar1 - uStack_6;
        }
        ((undefined2 *)&DAT_2000_cdc6)[cStack_f] = DAT_2000_cfd6;
        cStack_f = cStack_f + -1;
      } while( true );
    }
    ((undefined2 *)&DAT_2000_cfea)[cStack_f] = DAT_2000_d020;
    uStack_4 = ((uint)local_1e[cStack_f] * 0x30) / 0x10;
    uStack_6 = ((uint)local_1e[cStack_f + 1] * 0x30) / 0x10;
    *(int *)(cStack_f * 2 + -0x70f2) =
         (uint)*(byte *)(cStack_f + 0x729) + ((uint)local_1e[cStack_f + 1] * 0x38) / 0x10;
    ((undefined2 *)&DAT_2000_cffc)[cStack_f] =
         (uint)*(byte *)(cStack_f + 0x728) + ((uint)local_1e[cStack_f] * 0x38) / 0x10;
    uStack_14 = ((uint)local_1e[cStack_f] * 0x27) / 0x10;
    uStack_12 = ((uint)local_1e[cStack_f + 1] * 0x27) / 0x10;
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
        if (0x1af < DAT_2000_d020) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(7);
        }
        *(int *)((int)&AgntAnms[0x5d].sx + 1 + DAT_2000_d020 * 2) = iStack_c + uStack_12;
        *(int *)(DAT_2000_d020 * 2 + 0xd80) =
             *(int *)((int)&AgntAnms[0x5d].sx + 1 + DAT_2000_d020 * 2) + uStack_6;
        *(int *)(DAT_2000_d020 * 2 + 0xa20) = iStack_a + uStack_14;
        *(int *)(DAT_2000_d020 * 2 + 0x6c0) = *(int *)(DAT_2000_d020 * 2 + 0xa20) + uStack_4;
        *(uint *)(DAT_2000_d020 * 2 + 0x360) = uStack_e;
        if ((int)uStack_e < -1) {
          *(undefined2 *)(DAT_2000_d020 * 2) = 0;
        }
        else {
          *(undefined2 *)(DAT_2000_d020 * 2) = 1;
        }
        DAT_2000_d020 = DAT_2000_d020 + 1;
        iStack_a = iStack_a + uStack_4;
        iStack_c = iStack_c + uStack_6;
        uStack_e = uStack_e + 1;
      }
      if (-1 < iVar2) {
        if (0x1af < DAT_2000_d020) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(7);
        }
        *(int *)((int)&AgntAnms[0x5d].sx + 1 + DAT_2000_d020 * 2) = iVar1 + uStack_12;
        *(int *)(DAT_2000_d020 * 2 + 0xd80) =
             *(int *)((int)&AgntAnms[0x5d].sx + 1 + DAT_2000_d020 * 2) + uStack_6;
        *(int *)(DAT_2000_d020 * 2 + 0xa20) = iStack_8 + uStack_14;
        *(int *)(DAT_2000_d020 * 2 + 0x6c0) = *(int *)(DAT_2000_d020 * 2 + 0xa20) + uStack_4;
        *(int *)(DAT_2000_d020 * 2 + 0x360) = iVar2;
        if (iVar2 < 1) {
          *(undefined2 *)(DAT_2000_d020 * 2) = 1;
        }
        else {
          *(undefined2 *)(DAT_2000_d020 * 2) = 2;
        }
        DAT_2000_d020 = DAT_2000_d020 + 1;
        iStack_8 = iStack_8 - uStack_4;
        iVar1 = iVar1 - uStack_6;
        iVar2 = iVar2 + -1;
      }
    }
    ((undefined2 *)&DAT_2000_cfd8)[cStack_f] = DAT_2000_d020;
    cStack_f = cStack_f + -1;
  } while( true );
}



/* 3381:1f1d */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl16far init_3381_1f1d(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar1 = param_2 * 0x94;
  uVar3 = (undefined2)((ulong)_DAT_2000_cb05 >> 0x10);
  iVar2 = (int)_DAT_2000_cb05;
  if ((((*(char *)(iVar2 + uVar1 + param_1) == '\0') ||
       (uVar1 = param_2 * 0x94, *(char *)(iVar2 + uVar1 + param_1 + 1) == '\0')) ||
      (uVar1 = param_2 * 0x94 + iVar2, *(char *)(uVar1 + param_1 + 0x94) == '\0')) ||
     (uVar1 = param_2 * 0x94 + iVar2, *(char *)(uVar1 + param_1 + 0x94) == '\0')) {
    uVar1 = uVar1 & 0xff00;
  }
  else {
    uVar1 = CONCAT11((char)(uVar1 >> 8),1);
  }
  return uVar1;
}



/* 3381:1fa9 */

void __cdecl16far init_3381_1fa9(void)

{
  EntityCount = 0;
  return;
}



/* 3381:1fba */

void __cdecl16far init_3381_1fba(void)

{
  int iVar1;
  far_t handle;
  far_t handle_00;
  far_t handle_01;
  far_t handle_02;
  far_t handle_03;
  
  for (iVar1 = 0; iVar1 < (int)(uint)DAT_2000_d1e6; iVar1 = iVar1 + 1) {
    handle.seg = ((uint16_t *)(iVar1 * 4))[1];
    handle.ofs = *(uint16_t *)(iVar1 * 4);
    ovr_stshFree(handle);
  }
  DAT_2000_d1e6 = 0;
  if (DAT_2410_07e3 != 0 || DAT_2410_07e5 != 0) {
    handle_00.seg = DAT_2410_07e5;
    handle_00.ofs = DAT_2410_07e3;
    ovr_stshFree(handle_00);
  }
  if (DAT_2410_07e7 != 0 || DAT_2410_07e9 != 0) {
    handle_01.seg = DAT_2410_07e9;
    handle_01.ofs = DAT_2410_07e7;
    ovr_stshFree(handle_01);
  }
  if (DAT_2410_1d05 != 0 || DAT_2410_1d07 != 0) {
    handle_02.seg = DAT_2410_1d07;
    handle_02.ofs = DAT_2410_1d05;
    ovr_stshFree(handle_02);
  }
  DAT_2410_1d07 = 0;
  DAT_2410_1d05 = 0;
  DAT_2410_07e5 = 0;
  DAT_2410_07e3 = 0;
  DAT_2410_07e9 = 0;
  DAT_2410_07e7 = 0;
  ovr_clean_ring_buffer();
  if (CrossBlitPtr.ofs != 0 || CrossBlitPtr.seg != 0) {
    handle_03.seg = CrossBlitPtr.seg;
    handle_03.ofs = CrossBlitPtr.ofs;
    ovr_stshFree(handle_03);
  }
  CrossBlitPtr.seg = 0;
  CrossBlitPtr.ofs = 0;
  ovr_init2_3338_043e();
  return;
}



/* 3381:20ee */

void __cdecl16far init_3381_20ee(void)

{
  ovr_fmFreeAudio(1);
  init_3381_1fba();
  return;
}



/* 3381:2101 */

void __cdecl16far init_3381_2101(void)

{
  uint16_t uVar1;
  far_t handle;
  undefined1 local_306 [768];
  stg_tmp_t *psStack_6;
  
  DAT_2000_ca99 = 0xf8;
  init_3381_1697();
  AgntFlag1 = false;
  init_3381_20ee();
  DAT_2000_d1e6 = 0;
  DAT_2000_d1e5 = 0;
  DAT_2000_d1e3 = 5;
  DAT_2000_d1e4 = 0;
  DAT_2000_d2df = 0;
  DAT_2000_d16f = 0;
  DAT_2000_d16e = 0;
  DAT_2000_d16d = 0;
  DAT_2000_d16b = 0;
  DAT_2000_d169 = 0;
  DAT_2000_d310 = 0;
  uVar1 = ovr_randBelow(3);
  DAT_2410_0744 = (char)uVar1 * '\x03';
  if (GameRunning == false) {
    uVar1 = ovr_randBelow(0x14);
    DAT_2000_ccb0 = (undefined1)uVar1;
  }
  else {
    DAT_2410_0744 = '\0';
    DAT_2000_ccb0 = 0x14;
  }
  init_3381_08dc();
  ovr_attact_3f0b_057a();
  init_3381_1fa9();
  ovr_OVC24_5943_000e();
  GfxRndSeed = 0x48;
  GfxRndSeed2 = 0x1e;
  SaveAuto = 1;
  TimerSeed.hi = 0;
  TimerSeed.lo = 0;
  DAT_2000_d167 = 0;
  _fmemset(&DAT_2000_d3cd,0,2);
  DAT_2000_d3cc = 0;
  DAT_2410_6a86 = 0;
  DAT_2410_6a88 = 0;
  DAT_2000_d3ca = 0;
  DAT_2000_ca93 = 0;
  DAT_2000_ca91 = 0;
  DAT_2000_ca90 = 0;
  GSeason = 0;
  GTimeLo = 0;
  if (2 < DAT_2000_d19d) {
    DAT_2000_d2e6 = 2;
  }
  DAT_2000_d2e4 = 0;
  DAT_2000_d3c6 = 0;
  DAT_2000_d2e2 = 0;
  handle.seg = Lbm_nwpanel1.seg;
  handle.ofs = Lbm_nwpanel1.ofs;
  psStack_6 = ovr_stshLoadGfx(handle);
  ovr_calcSeasonPalette((stg_tmp_t *)psStack_6,(int)((ulong)psStack_6 >> 0x10),local_306);
  if (GameRunning == false) {
    ovr_vgaSetPalette8bit(local_306);
  }
  ovr_manage_4d05_0000();
  return;
}



/* 3381:233e */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl16far init_3381_233e(int param_1,int param_2)

{
  uint in_AX;
  uint uVar1;
  
  if ((((param_1 < 0x94) && (-1 < param_1)) && (param_2 < 0x3c)) && (-1 < param_2)) {
    uVar1 = CONCAT11((char)((uint)(param_2 * 0x94) >> 8),
                     *(undefined1 *)((int)_DAT_2000_cb05 + param_2 * 0x94 + param_1));
  }
  else {
    uVar1 = in_AX & 0xff00;
  }
  return uVar1;
}



/* 3381:237a */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far init_3381_237a(int param_1,int param_2,undefined1 param_3)

{
  if ((((param_1 < 0x94) && (-1 < param_1)) && (param_2 < 0x3c)) && (-1 < param_2)) {
    *(undefined1 *)((int)_DAT_2000_cb05 + param_2 * 0x94 + param_1) = param_3;
  }
  return;
}



/* 3381:23b5 */

uint __cdecl16far init_3381_23b5(int param_1,int param_2)

{
  uint in_AX;
  uint uVar1;
  
  if ((((param_1 < 0x94) && (-1 < param_1)) && (param_2 < 0x3c)) && (-1 < param_2)) {
    uVar1 = CONCAT11((char)((uint)(param_1 * 2) >> 8),
                     *(undefined1 *)((int)DAT_2000_cb09 + param_2 * 0x128 + param_1 * 2)) & 0xff03;
  }
  else {
    uVar1 = in_AX & 0xff00;
  }
  return uVar1;
}



/* 3381:23f9 */

int __cdecl16far init_3381_23f9(int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  bVar1 = init_3381_233e(param_1,param_2);
  uVar2 = (uint)bVar1;
  bVar1 = init_3381_233e(param_1 + 1,param_2);
  iVar3 = uVar2 + bVar1;
  bVar1 = init_3381_233e(param_1,param_2 + 1);
  iVar3 = iVar3 + (uint)bVar1;
  bVar1 = init_3381_233e(param_1 + 1,param_2 + 1);
  return iVar3 + (uint)bVar1;
}



/* 3381:2452 */

undefined2 __cdecl16far init_3381_2452(int param_1,int param_2,byte param_3)

{
  char cVar1;
  byte bStack_3;
  
  bStack_3 = 0;
  while( true ) {
    if (3 < bStack_3) {
      return 1;
    }
    if ((bStack_3 != (param_3 ^ 2)) &&
       (cVar1 = init_3381_23b5(param_1 + *(char *)(bStack_3 + 0x885),
                               param_2 + *(char *)(bStack_3 + 0x889)), cVar1 != '\0')) break;
    bStack_3 = bStack_3 + 1;
  }
  return 0;
}



/* 3381:24c3 */

undefined2 __cdecl16far
init_3381_24c3(int param_1,int param_2,char param_3,byte *param_4,byte *param_5)

{
  byte bVar1;
  char extraout_AL;
  int iVar2;
  uint16_t uVar3;
  undefined1 uVar5;
  uint uVar4;
  undefined1 extraout_AH;
  uint uStack_e;
  uint uStack_c;
  byte bStack_8;
  byte bStack_7;
  byte bStack_6;
  byte bStack_5;
  byte bStack_3;
  
  iVar2 = init_3381_23f9(param_1,param_2);
  uStack_e = iVar2 + 0x14;
  bStack_6 = 0xff;
  bStack_5 = 0xff;
  bStack_7 = 0xff;
  bStack_8 = 0xff;
  uVar3 = ovr_randBelow(4);
  uVar5 = (undefined1)(uVar3 >> 8);
  uStack_c = uStack_e;
  bStack_3 = (byte)uVar3;
  do {
    bVar1 = bStack_3 - param_3 & 3;
    if ((bVar1 != 2) && ((*param_5 < 2 || (*param_4 != bVar1)))) {
      bStack_8 = bStack_3;
      uVar4 = init_3381_23f9(param_1 + *(char *)(bStack_3 + 0x885),
                             param_2 + *(char *)(bStack_3 + 0x889));
      if (uVar4 <= uStack_c) {
        bStack_5 = bStack_3;
        uStack_c = uVar4;
      }
      init_3381_2452(param_1 + *(char *)(bStack_3 + 0x885),param_2 + *(char *)(bStack_3 + 0x889),
                     bStack_3);
      uVar5 = extraout_AH;
      if ((extraout_AL != '\0') && (bStack_7 = bStack_3, uVar4 <= uStack_e)) {
        bStack_6 = bStack_3;
        uStack_e = uVar4;
      }
    }
    uVar4 = CONCAT11(uVar5,bStack_3 + 1) & 0xff03;
    bStack_3 = (byte)uVar4;
    uVar5 = (undefined1)(uVar4 >> 8);
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
  bVar1 = bStack_3 - param_3 & 3;
  if (bVar1 != 0) {
    if (*param_4 == bVar1) {
      *param_5 = *param_5 + 1;
    }
    else {
      *param_5 = 0;
      *param_4 = bVar1;
    }
  }
  return CONCAT11(uVar5,bStack_3);
}



/* 3381:2651 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far init_3381_2651(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)DAT_2000_cb09 >> 0x10);
  iVar2 = (int)DAT_2000_cb09;
  if ((*(uint *)(iVar2 + param_2 * 0x128 + param_1 * 2) & 4) == 0) {
    if (((*(char *)(DAT_2000_cb05 + param_2 * 0x94 + param_1) == '\0') &&
        (*(char *)(param_2 * 0x94 + DAT_2000_cb05 + param_1 + 0x95) == '\0')) &&
       (*(char *)(param_2 * 0x94 + DAT_2000_cb05 + param_1 + 0x94) == '\0')) {
      puVar1 = (uint *)(iVar2 + param_2 * 0x128 + param_1 * 2);
      *puVar1 = *puVar1 | 1;
    }
    uVar3 = (undefined2)((ulong)_DAT_2000_cb05 >> 0x10);
    iVar2 = (int)_DAT_2000_cb05;
    if (((*(char *)(iVar2 + param_2 * 0x94 + param_1) == '\0') &&
        (*(char *)(param_2 * 0x94 + iVar2 + param_1 + 0x95) == '\0')) &&
       (*(char *)(iVar2 + param_2 * 0x94 + param_1 + 1) == '\0')) {
      puVar1 = (uint *)((int)DAT_2000_cb09 + param_2 * 0x128 + param_1 * 2);
      *puVar1 = *puVar1 | 2;
    }
  }
  else {
    if (((*(char *)(param_2 * 0x94 + DAT_2000_cb05 + param_1 + 0x94) == '\0') &&
        (*(char *)(DAT_2000_cb05 + param_2 * 0x94 + param_1 + 1) == '\0')) &&
       (*(char *)(DAT_2000_cb05 + param_2 * 0x94 + param_1) == '\0')) {
      puVar1 = (uint *)(iVar2 + param_2 * 0x128 + param_1 * 2);
      *puVar1 = *puVar1 | 1;
    }
    if (((*(char *)(param_2 * 0x94 + DAT_2000_cb05 + param_1 + 0x94) == '\0') &&
        (*(char *)(DAT_2000_cb05 + param_2 * 0x94 + param_1 + 1) == '\0')) &&
       (*(char *)(param_2 * 0x94 + DAT_2000_cb05 + param_1 + 0x95) == '\0')) {
      puVar1 = (uint *)((int)DAT_2000_cb09 + param_2 * 0x128 + param_1 * 2);
      *puVar1 = *puVar1 | 2;
    }
  }
  return;
}



/* 3381:2883 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far init_3381_2883(void)

{
  uint *puVar1;
  uint16_t uVar2;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined1 extraout_AH_02;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined2 uVar6;
  undefined2 unaff_SS;
  byte local_24 [16];
  byte bStack_14;
  byte bStack_13;
  int iStack_12;
  undefined1 local_f;
  undefined1 local_e;
  byte bStack_d;
  byte bStack_c;
  byte bStack_b;
  byte local_a [8];
  
  F_SCOPY(local_24,(uint8_t *)0x4f2,0x10);
  F_SCOPY(local_a,(uint8_t *)0x502,8);
  iStack_12 = 0;
  do {
    if ((int)(uint)DAT_2000_ccb0 <= iStack_12) {
      return;
    }
    uVar2 = ovr_randBelow(0x93);
    uVar4 = uVar2 & 0xff;
    uVar2 = ovr_randBelow(0x3b);
    uVar5 = uVar2 & 0xff;
    bStack_b = 100;
    bStack_c = init_3381_233e(uVar4,uVar5);
    if (bStack_c < bStack_b) {
      bStack_b = bStack_c;
    }
    bStack_c = init_3381_233e(uVar4 + 1,uVar5);
    if (bStack_c < bStack_b) {
      bStack_b = bStack_c;
    }
    bStack_c = init_3381_233e(uVar4,uVar5 + 1);
    if (bStack_c < bStack_b) {
      bStack_b = bStack_c;
    }
    bStack_c = init_3381_233e(uVar4 + 1,uVar5 + 1);
    if (bStack_c < bStack_b) {
      bStack_b = bStack_c;
    }
    init_3381_237a(uVar4,uVar5,bStack_b);
    init_3381_237a(uVar4 + 1,uVar5,CONCAT11(extraout_AH,bStack_b));
    init_3381_237a(uVar4,uVar5 + 1,CONCAT11(extraout_AH_00,bStack_b));
    init_3381_237a(uVar4 + 1,uVar5 + 1,CONCAT11(extraout_AH_01,bStack_b));
    if (bStack_b == 0) {
      init_3381_2651(uVar4,uVar5);
      init_3381_2651(uVar4 - 1,uVar5);
      init_3381_2651(uVar4 + 1,uVar5);
      init_3381_2651(uVar4,uVar5 - 1);
      init_3381_2651(uVar4,uVar5 + 1);
    }
    local_e = 0;
    local_f = 0;
    uVar2 = ovr_randBelow(4);
    bStack_13 = (byte)uVar2;
    for (; ((((int)uVar4 < 0x93 && (-1 < (int)uVar4)) && ((int)uVar5 < 0x3b)) && (-1 < (int)uVar5));
        uVar5 = uVar5 + (int)*(char *)(bStack_14 + 0x889)) {
      uVar6 = (undefined2)((ulong)_DAT_2000_cb05 >> 0x10);
      iVar3 = (int)_DAT_2000_cb05;
      if (((*(char *)(iVar3 + uVar5 * 0x94 + uVar4) == '\0') &&
          (*(char *)(iVar3 + uVar5 * 0x94 + uVar4 + 1) == '\0')) &&
         ((*(char *)(uVar5 * 0x94 + iVar3 + uVar4 + 0x94) == '\0' &&
          (*(char *)(uVar5 * 0x94 + iVar3 + uVar4 + 0x95) == '\0')))) break;
      uVar6 = (undefined2)((ulong)DAT_2000_cb09 >> 0x10);
      iVar3 = (int)DAT_2000_cb09;
      if ((*(uint *)(iVar3 + uVar5 * 0x128 + uVar4 * 2) & 3) == 3) break;
      if ((*(uint *)(iVar3 + uVar5 * 0x128 + uVar4 * 2) & 3) != 0) {
        puVar1 = (uint *)(iVar3 + uVar5 * 0x128 + uVar4 * 2);
        *puVar1 = *puVar1 | 3;
      }
      bStack_14 = init_3381_24c3(uVar4,uVar5,CONCAT11((char)((uint)&local_e >> 8),bStack_13),
                                 &local_e);
      if (((bStack_14 == 0xff) || (bStack_13 == (bStack_14 ^ 2))) ||
         (local_24[(uint)bStack_13 * 4 + (uint)bStack_14] == 0)) break;
      puVar1 = (uint *)((int)DAT_2000_cb09 + uVar5 * 0x128 + uVar4 * 2);
      *puVar1 = *puVar1 & 0xfffb;
      puVar1 = (uint *)((int)DAT_2000_cb09 + uVar5 * 0x128 + uVar4 * 2);
      *puVar1 = *puVar1 | (uint)local_24[(uint)bStack_13 * 4 + (uint)bStack_14];
      bStack_c = init_3381_233e(uVar4 + (local_a[(uint)bStack_13 * 2] & 1),
                                uVar5 + ((int)(uint)local_a[(uint)bStack_13 * 2] >> 1));
      bStack_d = init_3381_233e(uVar4 + (local_a[(uint)bStack_13 * 2 + 1] & 1),
                                uVar5 + ((int)(uint)local_a[(uint)bStack_13 * 2 + 1] >> 1));
      if (bStack_c < bStack_b) {
        bStack_b = bStack_c;
      }
      if (bStack_d < bStack_b) {
        bStack_b = bStack_d;
      }
      init_3381_237a(uVar4 + (local_a[(uint)bStack_14 * 2] & 1),
                     uVar5 + ((int)(uint)local_a[(uint)bStack_14 * 2] >> 1),bStack_b);
      init_3381_237a(uVar4 + (local_a[(uint)bStack_14 * 2 + 1] & 1),
                     uVar5 + ((int)(uint)local_a[(uint)bStack_14 * 2 + 1] >> 1),
                     CONCAT11(extraout_AH_02,bStack_b));
      if (bStack_b == 0) {
        init_3381_2651(uVar4,uVar5);
        init_3381_2651(uVar4 - 1,uVar5);
        init_3381_2651(uVar4 + 1,uVar5);
        init_3381_2651(uVar4,uVar5 - 1);
        init_3381_2651(uVar4,uVar5 + 1);
      }
      uVar4 = uVar4 + (int)*(char *)(bStack_14 + 0x885);
      bStack_13 = bStack_14;
    }
    iStack_12 = iStack_12 + 1;
  } while( true );
}



/* 3381:2d36 */

void __cdecl16far init_3381_2d36(void)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined1 uStack_3;
  
  for (iVar4 = 0; iVar4 < 0x94; iVar4 = iVar4 + 1) {
    for (iVar3 = 0; iVar3 < 0x3c; iVar3 = iVar3 + 1) {
      for (uStack_3 = 0; uStack_3 < 4; uStack_3 = uStack_3 + 1) {
        cVar2 = ovr_OVC23_55fe_0af5(iVar4,iVar3,uStack_3);
        if (cVar2 != '\0') {
          puVar1 = (uint *)((int)DAT_2000_cb09 + iVar3 * 0x128 + iVar4 * 2);
          *puVar1 = *puVar1 | 0x10 << (uStack_3 & 0x1f);
        }
      }
    }
  }
  return;
}



/* 3381:2d9e */

void __cdecl16far init_grayscale_palette(void)

{
  undefined2 uVar1;
  stg_tmp_t *psVar2;
  uint max_c;
  int i;
  undefined2 unaff_SS;
  far_t handle;
  uint8_t buf [12];
  stg_tmp_t *pgfx;
  stg_tmp_t *gfx;
  
  F_SCOPY(buf,(uint8_t *)GrayscaleIndices,0xb);
  if (GrayscalePalette.ofs == 0 && GrayscalePalette.seg == 0) {
    GrayscalePalette = (far_t)ovr_stshAlloc(0x100);
  }
  handle.seg = Lbm_nwpanel1.seg;
  handle.ofs = Lbm_nwpanel1.ofs;
  pgfx = ovr_stshLoadGfx(handle);
  psVar2 = (stg_tmp_t *)pgfx;
  uVar1 = (undefined2)((ulong)pgfx >> 0x10);
  gfx = pgfx;
  *(undefined1 *)GrayscalePalette = 0;
  for (i = 1; i < 0x100; i = i + 1) {
    max_c = (uint)psVar2->cmap[i * 3];
    if (max_c < psVar2->cmap[i * 3 + 1]) {
      max_c = (uint)psVar2->cmap[i * 3 + 1];
    }
    if (max_c < psVar2->cmap[i * 3 + 2]) {
      max_c = (uint)psVar2->cmap[i * 3 + 2];
    }
    *(uint8_t *)(GrayscalePalette.ofs + i) = buf[max_c * 0xb >> 6];
  }
  return;
}



/* 3381:2e9a */

void __cdecl16far init_3381_2e9a(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  if ((int)param_1 != 0 || param_1._2_2_ != 0) {
    iVar3 = 0;
    for (iVar2 = 0; *(char *)((int)param_1 + iVar2) != '\0'; iVar2 = iVar2 + 1) {
      if (*(char *)((int)param_1 + iVar2) != ' ') {
        uVar1 = tolower((int)*(char *)((int)param_1 + iVar2));
        *(undefined1 *)((int)param_1 + iVar3) = uVar1;
        iVar3 = iVar3 + 1;
      }
    }
    *(undefined1 *)((int)param_1 + iVar3) = 0;
  }
  return;
}



/* 3381:2ee2 */

void __cdecl16far copyProtectionCheck(void)

{
  uint16_t uVar1;
  char *pcVar2;
  byte *pbVar3;
  undefined4 uVar4;
  far_t handle;
  char local_5c [80];
  char *input;
  uint16_t uStack_a;
  undefined1 *puStack_8;
  byte attempts;
  byte codes;
  
  if (CopyProtectionDone == '\0') {
    uVar1 = ovr_randBelow(0x19);
    codes = (byte)uVar1;
    attempts = 0;
    while( true ) {
      if (3 < attempts) {
        if (SaveAuto != '\0') {
          ovr_stSave();
        }
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0);
      }
      ovr_saveui_4528_0533();
      TextBlitX = 0x16;
      TextBlitY = 0xc;
      ovr_blitText("Stronghold copy protection.",(byte *)Font03.ofs,0xde,0x8);
      TextBlitX = 0x16;
      TextBlitY = 0x2f;
      uVar4 = 0x800de;
      pbVar3 = (byte *)Font03.ofs;
      pcVar2 = ovr_stsprintf(local_5c,"Turn to page #%d of the manual.",
                             (char *)(uint)*(byte *)(codes + 0x51a));
      ovr_blitText(pcVar2,pbVar3,(uint16_t)uVar4,(uint8_t)((ulong)uVar4 >> 0x10));
      TextBlitX = 0x16;
      TextBlitY = 0x43;
      uVar4 = 0x800de;
      pbVar3 = (byte *)Font03.ofs;
      pcVar2 = ovr_stsprintf(local_5c,"Including titles, count to line #%d.",
                             (char *)(uint)*(byte *)(codes + 0x533));
      ovr_blitText(pcVar2,pbVar3,(uint16_t)uVar4,(uint8_t)((ulong)uVar4 >> 0x10));
      TextBlitX = 0x16;
      TextBlitY = 0x57;
      ovr_blitText("Enter the first word.",(byte *)Font03.ofs,0xde,0x8);
      uStack_a = 0;
      input = (char *)0x0;
      puStack_8 = ovr_stshAlloc(2);
      uVar1 = (uint16_t)((ulong)puStack_8 >> 0x10);
      *puStack_8 = *(undefined1 *)*(undefined4 *)((uint)codes * 4 + 0x54c);
      ((undefined1 *)puStack_8)[1] = 0;
      input = (char *)ovr_uiReadString(0,0,6,(undefined1 *)puStack_8);
      uStack_a = uVar1;
      init_3381_2e9a(input);
      if (UserWantsExit != '\0') {
        if (SaveAuto != '\0') {
          ovr_stSave();
        }
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0);
      }
      if (input != (char *)0x0 || uStack_a != 0) break;
      attempts = attempts + 1;
    }
    _fstricmp(input,(char *)*(undefined2 *)((uint)codes * 4 + 0x54c));
    handle.seg = uStack_a;
    handle.ofs = (uint16_t)input;
    ovr_stshFree(handle);
    ovr_saveui_4528_0533();
    CopyProtectionDone = '\x01';
  }
  return;
}


