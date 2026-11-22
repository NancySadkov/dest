/*
 * ovc31_config.c - recovered from STRONG.EXE
 * memory block: OVC31_config.c
 * range: 6257:0000 - 6257:0bef
 * functions: 10
 */
#include "recovered.h"


/* 6257:0000 */

int __cdecl16far creat_wait_unlock(char *filename)

{
  uint16_t handle;
  uint16_t ioerr;
  int unaff_SI;
  
  do {
    ioErrorHndlrInstall();
                    /* mode 0 = create regular file */
    handle = _creat((char *)((ulong)filename & 0xffff),unaff_SI);
    ioerr = ioErrorHndlrUninstall();
    if (handle != 0xffff) {
      return handle;
    }
  } while (ioerr == 0x20);
  return -1;
}



/* 6257:003b */

int __cdecl16far file_open_rdonly(char *filename)

{
  uint16_t handle;
  uint16_t hwerr;
  char *in_stack_00000004;
  
  do {
    ioErrorHndlrInstall();
                    /* O_RDONLY|O_DENYNONE
                       O_DENYNONE = Allow concurrent access  */
    handle = _open((char *)CONCAT22((char *)filename,in_stack_00000004),0x41);
    hwerr = ioErrorHndlrUninstall();
    if (handle != 0xffff) {
      return handle;
    }
                    /* while sharing violation error */
  } while (hwerr == 0x20);
  return -1;
}



/* 6257:0077 */

/* Opens a file read-only and closes it, returning whether it exists. */

bool __cdecl16far ovc31_fileExists(char *filename)

{
  int handle;
  uint16_t unaff_SI;
  
  handle = file_open_rdonly((char *)CONCAT22(unaff_SI,(char *)filename));
  if (-1 < handle) {
    close(handle);
  }
  return -1 < handle;
}



/* 6257:009f */

bool __cdecl16far write_game_cfg(char sfx,char mus,char irq)

{
  int iVar1;
  size_t sVar2;
  uint16_t sz;
  uint16_t l;
  size_t sVar3;
  uint unaff_SI;
  
  mkdir((char *)0x5e30);
  iVar1 = creat_wait_unlock((char *)((ulong)unaff_SI << 0x10));
  if (-1 < iVar1) {
    cRam00005e2c = sfx;
    sVar2 = strlen((char *)0x5e2c);
    sz = write(iVar1,(void *)0x5e2c,sVar2);
    l = strlen((char *)0x5e2c);
    if (sz == l) {
      cRam00005e2c = mus;
      sVar2 = strlen((char *)0x5e2c);
      sVar2 = write(iVar1,(void *)0x5e2c,sVar2);
      sVar3 = strlen((char *)0x5e2c);
      if (sVar2 == sVar3) {
        cRam00005e2c = irq;
        sVar2 = strlen((char *)0x5e2c);
        sVar2 = write(iVar1,(void *)0x5e2c,sVar2);
        sVar3 = strlen((char *)0x5e2c);
        iVar1 = close(iVar1);
        if (sVar2 == sVar3 && (char)iVar1 == '\0') {
          clrscr();
          return true;
        }
      }
    }
  }
  return false;
}



/* 6257:01cc */

char __cdecl16far read_cfg(int handle)

{
  uint16_t nread;
  int iVar1;
  uint16_t rdsz;
  uint unaff_SI;
  void *unaff_SS;
  uint8_t tmp;
  char b;
  
  nread = read(handle,(void *)CONCAT22(1,unaff_SS),unaff_SI);
  if (nread == 1) {
    do {
      iVar1 = read(handle,(void *)CONCAT22(1,unaff_SS),unaff_SI);
      if (iVar1 != 1) goto return_zero;
    } while (tmp != 0xa);
  }
  else {
return_zero:
    b = '\0';
  }
  return b;
}



/* 6257:021e */

byte __cdecl16far is_printable(char *buf,char c)

{
  uint8_t r;
  char in_stack_00000008;
  
  if ((((((((((byte *)_ctype + 1)[in_stack_00000008] & 0xe) == 0) && (in_stack_00000008 != ':')) &&
         (in_stack_00000008 != '.')) && ((in_stack_00000008 != '\\' && (in_stack_00000008 != '}'))))
       && (((in_stack_00000008 != '!' && ((in_stack_00000008 != '@' && (in_stack_00000008 != '#'))))
           && (in_stack_00000008 != '$')))) &&
      ((((in_stack_00000008 != '%' && (in_stack_00000008 != '^')) && (in_stack_00000008 != '&')) &&
       (((in_stack_00000008 != '(' && (in_stack_00000008 != ')')) &&
        ((in_stack_00000008 != '-' && ((in_stack_00000008 != '_' && (in_stack_00000008 != '{')))))))
       ))) && ((in_stack_00000008 != '}' &&
               ((in_stack_00000008 != '~' && (in_stack_00000008 != '`')))))) {
    r = 0;
  }
  else {
    r = 0x1;
  }
  return r;
}



/* 6257:029f */

void __cdecl16far input_folder_name(char *result)

{
  byte bVar1;
  uint16_t key;
  uint16_t len;
  uint8_t ascii;
  
  len = 0;
  *result = '\0';
  while( true ) {
    key = ovr_biosReadKey();
    if (key == 0x11b) {
      printf("\n");
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if (key == 0x1c0d) break;
    if ((key == 0xe08) && (0 < (int)len)) {
      printf("\b \b");
      ((char *)result)[len - 1] = '\0';
      return;
    }
    if (((int)len < 0x41) &&
       (bVar1 = is_printable((char *)result,(char)((ulong)result >> 0x10)), bVar1 != 0)) {
      printf("%c");
      ascii = (uint8_t)key;
      ((char *)result)[len] = ascii;
      len = len + 1;
      ((char *)result)[len] = '\0';
    }
  }
  return;
}



/* 6257:0345 */

byte __cdecl16far init_strong_sav(void)

{
  char cVar1;
  uint16_t file;
  int handle;
  uint16_t result;
  char *path;
  uint16_t in_DX;
  uint16_t unaff_SI;
  uint16_t unaff_SS;
  char path_buffer [81];
  uint8_t b;
  
  do {
    file = file_open_rdonly((char *)CONCAT22(unaff_SI,(char *)0x26510));
    if (-1 < (int)file) {
      cVar1 = read_cfg(file);
      if ((((cVar1 == '\0') ||
           ((((cVar1 < '1' || ('9' < cVar1)) && ((cVar1 < 'A' || ('B' < cVar1)))) ||
            (cVar1 = read_cfg(file), cVar1 == '\0')))) ||
          (((cVar1 < '1' || ('9' < cVar1)) && ((cVar1 < 'A' || ('B' < cVar1)))))) ||
         ((cVar1 = read_cfg(file), cVar1 == '\0' ||
          (((cVar1 < '0' || ('9' < cVar1)) && ((cVar1 < 'A' || ('F' < cVar1)))))))) {
        close(file);
l_made_new_strong_sav:
                    /* Needs new game.cfg */
        (*(uint8_t *)((uint8_t *)&(result))) = 0;
      }
      else {
        close(file);
                    /* Found previous game_cfg */
        (*(uint8_t *)((uint8_t *)&(result))) = 1;
      }
      return (byte)result;
    }
                    /* create new folder */
    mkdir("strong.sav");
    handle = creat_wait_unlock((char *)CONCAT22(unaff_SI,(char *)0x26510));
    if (-1 < handle) {
      close(handle);
      unlink("strong.sav\\strong.$$$");
      goto l_made_new_strong_sav;
    }
    clrscr();
    printf("Path to write game data:\n");
    input_folder_name((char *)CONCAT22(unaff_SS,path_buffer));
    path = ovr_path_strip_tail_slash(path_buffer,0);
    ovr_chpath(path,in_DX);
  } while( true );
}



/* 6257:046a */

void __cdecl16far init_base(void)

{
  byte haveConfig;
  uint8_t vdaMode;
  bool cfgWritten;
  uint16_t key;
  size_t unaff_SI;
  uint8_t sfx;
  uint8_t mus;
  uint8_t irq;
  
  init_check_mem();
  getcwd((char *)MK_FP(0x2410, 0x50),unaff_SI);
  haveConfig = init_strong_sav();
  if (haveConfig != 0) {
    while (key = ovr_biosKeyAvail(), (char)key != '\0') {
      ovr_biosReadKey();
    }
    while( true ) {
      clrscr();
      printf("ENTER: use previous configuration, SPACE: reconfigure, ESC: quit");
      key = ovr_biosReadKey();
                    /* Is ESC key? */
      if ((key & 0xff) == 0x1b) {
        printf("\n");
                    /* WARNING: Subroutine does not return */
        exit(0);
      }
                    /* Space */
      if ((key & 0xff) == 0x20) break;
                    /* carriage return */
      if ((key & 0xff) == 0xd) {
        clrscr();
        return;
      }
    }
  }
  clrscr();
  printf("Sound (1. PC Speaker  2. Sound Blaster  3. Pro Audio Spectrum\n");
  printf("       4. Adlib       5. Roland         6. Off):");
  irq = 0x30;
  do {
    while (key = ovr_biosKeyAvail(), (char)key != '\0') {
      ovr_biosReadKey();
    }
    key = ovr_biosReadKey();
    if ((key & 0xff) == 0x1b) {
      printf("\n");
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if ((key & 0xff) == 0x31) {
      vdaMode = ovr_vda_query();
      if ((vdaMode == 0x0) || (vdaMode == 0x80)) {
        sfx = 0x31;
      }
      else {
        sfx = 0x34;
      }
      goto setup_pc_speaker;
    }
    if ((key & 0xff) == 0x32) {
      clrscr();
      printf("Sound Blaster (1. Original  2.  Pro Type 2  3. Pro Type 1):");
      goto setup_soundblaster;
    }
                    /* 3 = Pro Audio Spectrum */
    if ((key & 0xff) == 0x33) {
      clrscr();
      printf("Pro Audio Spectrum (1. Plus  2. Spectrum 16):");
      goto setup_pro_audio_spectrum;
    }
                    /* 4 = Adlib */
    if ((key & 0xff) == 0x34) {
      clrscr();
      printf("Adlib (1. Original  2. Gold):");
      goto setup_adlib;
    }
                    /* Roland */
    if ((key & 0xff) == 0x35) {
      mus = 0x42;
      clrscr();
      printf("Sound Effects (1. PC Speaker  2. Sound Blaster  3. Pro Audio Spectrum\n");
      printf("               4. Adlib       5. None):");
      goto pick_sfx_card;
    }
  } while ((key & 0xff) != 0x36);
  sfx = 0x33;
setup_pc_speaker:
  mus = 0x33;
  goto pick_irq;
  while( true ) {
    if ((key & 0xff) == 0x32) {
      sfx = 0x35;
      mus = 0x35;
      goto pick_irq;
    }
    if ((key & 0xff) == 0x33) break;
setup_soundblaster:
    irq = 0x37;
    while (key = ovr_biosKeyAvail(), (char)key != '\0') {
      ovr_biosReadKey();
    }
    key = ovr_biosReadKey();
    if ((key & 0xff) == 0x1b) {
      printf("\n");
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if ((key & 0xff) == 0x31) {
      sfx = 0x32;
      mus = 0x32;
      goto pick_irq;
    }
  }
  sfx = 0x36;
  mus = 0x36;
  goto pick_irq;
  while ((key & 0xff) != 0x32) {
setup_pro_audio_spectrum:
    while (key = ovr_biosKeyAvail(), (char)key != '\0') {
      ovr_biosReadKey();
    }
    key = ovr_biosReadKey();
    if ((key & 0xff) == 0x1b) {
      printf("\n");
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if ((key & 0xff) == 0x31) {
      sfx = 0x37;
      mus = 0x37;
      goto pick_irq;
    }
  }
  sfx = 0x38;
  mus = 0x38;
  irq = 0x35;
  goto pick_irq;
  while ((key & 0xff) != 0x32) {
setup_adlib:
    while (key = ovr_biosKeyAvail(), (char)key != '\0') {
      ovr_biosReadKey();
    }
    key = ovr_biosReadKey();
    if ((key & 0xff) == 0x1b) {
      printf("\n");
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if ((key & 0xff) == 0x31) {
      sfx = 0x39;
      mus = 0x39;
      goto pick_irq;
    }
  }
  sfx = 0x41;
  mus = 0x41;
  goto pick_irq;
  while( true ) {
    if ((key & 0xff) == 0x32) {
      clrscr();
      printf("Sound Blaster (1. Original  2.  Pro):");
      goto pick_sb_type;
    }
    if ((key & 0xff) == 0x33) {
      clrscr();
      printf("Pro Audio Spectrum (1. Plus  2. Spectrum 16):");
      goto pick_spectrum_type;
    }
    if ((key & 0xff) == 0x34) {
      clrscr();
      printf("Adlib (1. Original  2. Gold):");
      goto pick_adlib_type;
    }
    if ((key & 0xff) == 0x35) break;
pick_sfx_card:
    while (key = ovr_biosKeyAvail(), (char)key != '\0') {
      ovr_biosReadKey();
    }
    key = ovr_biosReadKey();
    if ((key & 0xff) == 0x1b) {
      printf("\n");
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if ((key & 0xff) == 0x31) {
      vdaMode = ovr_vda_query();
      if ((vdaMode == 0x0) || (vdaMode == 0x80)) {
        sfx = 0x31;
      }
      else {
        sfx = 0x34;
      }
      goto pick_irq;
    }
  }
  sfx = 0x33;
  goto pick_irq;
  while ((key & 0xff) != 0x32) {
pick_sb_type:
    irq = 0x37;
    while (key = ovr_biosKeyAvail(), (char)key != '\0') {
      ovr_biosReadKey();
    }
    key = ovr_biosReadKey();
    if ((key & 0xff) == 0x1b) {
      printf("\n");
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if ((key & 0xff) == 0x31) {
      sfx = 0x32;
      goto pick_irq;
    }
  }
  sfx = 0x35;
  goto pick_irq;
  while ((key & 0xff) != 0x32) {
pick_spectrum_type:
    while (key = ovr_biosKeyAvail(), (char)key != '\0') {
      ovr_biosReadKey();
    }
    key = ovr_biosReadKey();
    if ((key & 0xff) == 0x1b) {
      printf("\n");
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if ((key & 0xff) == 0x31) {
      sfx = 0x37;
      goto pick_irq;
    }
  }
  sfx = 0x38;
  irq = 0x35;
  goto pick_irq;
  while ((key & 0xff) != 0x32) {
pick_adlib_type:
    while (key = ovr_biosKeyAvail(), (char)key != '\0') {
      ovr_biosReadKey();
    }
    key = ovr_biosReadKey();
    if ((key & 0xff) == 0x1b) {
      printf("\n");
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if ((key & 0xff) == 0x31) {
      sfx = 0x39;
      goto pick_irq;
    }
  }
  sfx = 0x41;
pick_irq:
  if (irq != 0x30) {
    clrscr();
    printf("Sound IRQ is %c (1. Don\'t change  2. IRQ 2  3. IRQ 5\n");
    printf("                                 ");
    do {
      while (key = ovr_biosKeyAvail(), (char)key != '\0') {
        ovr_biosReadKey();
      }
      key = ovr_biosReadKey();
      if ((key & 0xff) == 0x1b) {
        printf("\n");
                    /* WARNING: Subroutine does not return */
        exit(0);
      }
      if ((key & 0xff) == 0x31) goto done;
      if ((key & 0xff) == 0x32) {
        irq = 0x32;
        goto done;
      }
      if ((key & 0xff) == 0x33) {
        irq = 0x35;
        goto done;
      }
      if ((key & 0xff) == 0x34) {
        irq = 0x37;
        goto done;
      }
    } while ((key & 0xff) != 0x35);
    irq = 0x41;
  }
done:
  clrscr();
  cfgWritten = write_game_cfg(sfx,mus,irq);
  if (cfgWritten) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  exit(0x83);
}



/* 6257:0a81 */

/* WARNING: Variable defined which should be unmapped: buf */

void __cdecl16far init_check_mem(void)

{
  uint16_t smem;
  int iVar1;
  uint16_t unaff_SS;
  far_t lmem_without_psp;
  char buf [80];
  long lmem;
  uint16_t himem;
  
  lmem_without_psp.seg = 0;
  lmem_without_psp.ofs = (uint16_t)LXLSH_at_((long *)(*(uint16_t *)((uint8_t *)&(buf))),(*(uint32_t *)((uint8_t *)&(buf) + 2)),buf[6]);
  iVar1 = lmem_without_psp.seg + (0xfeff < lmem_without_psp.ofs);
  if ((7 < iVar1) && ((iVar1 != 8 || (0xed27 < lmem_without_psp.ofs + 0x100)))) {
    return;
  }
  ovr_litoa10(buf,CONCAT22(lmem_without_psp.ofs + 0x100,unaff_SS),iVar1,0);
  printf("Largest executable program size is only %s bytes.\n");
  printf("Stronghold requires 585,000 bytes.\n");
                    /* WARNING: Subroutine does not return */
  exit(0x84);
}


