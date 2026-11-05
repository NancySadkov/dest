/*
 * ovc31.c - recovered from STRONG.EXE
 * memory block: OVC31
 * range: 6257:0000 - 6257:0bef
 * functions: 10
 */
#include "recovered.h"


/* 6257:0000 */

int __cdecl16far creat_wait_unlock(char *filename)

{
  int handle;
  uint16_t ioerr;
  
  do {
    ioErrorHndlrInstall();
                    /* mode 0 = create regular file */
    handle = _creat(filename,0);
    ioerr = ioErrorHndlrUninstall();
    if (handle != -1) {
      return handle;
    }
  } while (ioerr == 0x20);
  return -1;
}



/* 6257:003b */

int __cdecl16far file_open_rdonly(char *filename)

{
  int handle;
  uint16_t hwerr;
  
  do {
    ioErrorHndlrInstall();
                    /* O_RDONLY|O_DENYNONE
                       O_DENYNONE = Allow concurrent access  */
    handle = _open(filename,0x41);
    hwerr = ioErrorHndlrUninstall();
    if (handle != -1) {
      return handle;
    }
                    /* while sharing violation error */
  } while (hwerr == 0x20);
  return -1;
}



/* 6257:0077 */

bool __cdecl16far OVC31_6257_0077(char *param_1)

{
  int handle;
  
  handle = file_open_rdonly(param_1);
  if (-1 < handle) {
    close(handle);
  }
  return -1 < handle;
}



/* 6257:009f */

bool __cdecl16far write_game_cfg(char sfx,char mus,char irq)

{
  int iVar1;
  size_t sz;
  size_t l;
  
  mkdir((char *)"strong.sav");
  iVar1 = creat_wait_unlock((char *)"strong.sav\\game.cfg");
  if (-1 < iVar1) {
    cRam00005e2c = sfx;
    sz = strlen((char *)GGCTemplate);
    sz = write(iVar1,(char *)GGCTemplate,sz);
    l = strlen((char *)GGCTemplate);
    if (sz == l) {
      cRam00005e2c = mus;
      sz = strlen((char *)GGCTemplate);
      sz = write(iVar1,(char *)GGCTemplate,sz);
      l = strlen((char *)GGCTemplate);
      if (sz == l) {
        cRam00005e2c = irq;
        sz = strlen((char *)GGCTemplate);
        sz = write(iVar1,(char *)GGCTemplate,sz);
        l = strlen((char *)GGCTemplate);
        iVar1 = close(iVar1);
        if (sz == l && (char)iVar1 == '\0') {
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
  int nread;
  char tmp;
  char b;
  
  nread = read(handle,&b,1);
  if (nread == 1) {
    do {
      nread = read(handle,&tmp,1);
      if (nread != 1) goto return_zero;
    } while (tmp != '\n');
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
  byte r;
  
  if ((((((((((byte *)_ctype + 1)[c] & 0xe) == 0) && (c != ':')) && (c != '.')) &&
        ((c != '\\' && (c != '}')))) && (((c != '!' && ((c != '@' && (c != '#')))) && (c != '$'))))
      && ((((c != '%' && (c != '^')) && (c != '&')) &&
          (((c != '(' && (c != ')')) && ((c != '-' && ((c != '_' && (c != '{')))))))))) &&
     ((c != '}' && ((c != '~' && (c != '`')))))) {
    r = 0;
  }
  else {
    r = 1;
  }
  return r;
}



/* 6257:029f */

void __cdecl16far input_folder_name(char *result)

{
  byte bVar1;
  uint16_t key;
  undefined2 unaff_SI;
  int len;
  undefined2 in_stack_00000006;
  
  len = 0;
  *_result = '\0';
  while( true ) {
    key = ovr_biosReadKey();
    if (key == 0x11b) {
      printf("\n",unaff_SI);
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if ((char *)key == (char *)"%s: provides housing and income." + 8) break;
    if ((key == 0xe08) && (0 < len)) {
      printf("\b \b",unaff_SI);
      result[len + -1] = '\0';
      return;
    }
    if (len < 0x41) {
      bVar1 = is_printable(result,(char)key);
      if (bVar1 != 0) {
        printf("%c",key & 0xff);
        result[len] = (char)key;
        len = len + 1;
        result[len] = '\0';
      }
    }
  }
  return;
}



/* 6257:0345 */

byte __cdecl16far init_strong_sav(void)

{
  byte bVar1;
  int file;
  char *path;
  undefined2 unaff_SI;
  char path_buffer [81];
  char b;
  
  do {
    file = file_open_rdonly((char *)"strong.sav\\game.cfg");
    if (-1 < file) {
      b = read_cfg(file);
      if ((((b == '\0') ||
           ((((b < '1' || ('9' < b)) && ((b < 'A' || ('B' < b)))) || (b = read_cfg(file), b == '\0')
            ))) || (((b < '1' || ('9' < b)) && ((b < 'A' || ('B' < b)))))) ||
         ((b = read_cfg(file), b == '\0' || (((b < '0' || ('9' < b)) && ((b < 'A' || ('F' < b)))))))
         ) {
        close(file);
l_made_new_strong_sav:
                    /* Needs new game.cfg */
        bVar1 = 0;
      }
      else {
        close(file);
                    /* Found previous game_cfg */
        bVar1 = 1;
      }
      return bVar1;
    }
                    /* create new folder */
    mkdir((char *)"strong.sav");
    file = creat_wait_unlock((char *)"strong.sav\\strong.$$$");
    if (-1 < file) {
      close(file);
      unlink((char *)"strong.sav\\strong.$$$");
      goto l_made_new_strong_sav;
    }
    clrscr();
    printf("Path to write game data:\n",unaff_SI);
    input_folder_name(path_buffer);
    path = ovr_path_strip_tail_slash(path_buffer);
    ovr_chpath(path);
  } while( true );
}



/* 6257:046a */

void __cdecl16far init_base(void)

{
  byte bVar1;
  uint8_t uVar2;
  bool bVar3;
  uint16_t key;
  undefined2 unaff_SI;
  char sfx;
  char mus;
  char irq;
  
  init_check_mem();
  getcwd((char *)GWorkDir,0x50);
  bVar1 = init_strong_sav();
  if (bVar1 != 0) {
    while (key = ovr_biosKeyAvail(), (char)key != '\0') {
      ovr_biosReadKey();
    }
    while( true ) {
      clrscr();
      printf("ENTER: use previous configuration, SPACE: reconfigure, ESC: quit",unaff_SI);
      key = ovr_biosReadKey();
                    /* Is ESC key? */
      if ((key & 0xff) == 0x1b) {
        printf("\n",unaff_SI);
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
  printf("Sound (1. PC Speaker  2. Sound Blaster  3. Pro Audio Spectrum\n",unaff_SI);
  printf("       4. Adlib       5. Roland         6. Off):",unaff_SI);
  irq = '0';
  do {
    while (key = ovr_biosKeyAvail(), (char)key != '\0') {
      ovr_biosReadKey();
    }
    key = ovr_biosReadKey();
    if ((key & 0xff) == 0x1b) {
      printf("\n",unaff_SI);
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if ((key & 0xff) == 0x31) {
      uVar2 = ovr_vda_query();
      if ((uVar2 == 0x0) || (uVar2 == 0x80)) {
        sfx = '1';
      }
      else {
        sfx = '4';
      }
      goto setup_pc_speaker;
    }
    if ((key & 0xff) == 0x32) {
      clrscr();
      printf("Sound Blaster (1. Original  2.  Pro Type 2  3. Pro Type 1):",unaff_SI);
      goto setup_soundblaster;
    }
                    /* 3 = Pro Audio Spectrum */
    if ((key & 0xff) == 0x33) {
      clrscr();
      printf("Pro Audio Spectrum (1. Plus  2. Spectrum 16):",unaff_SI);
      goto setup_pro_audio_spectrum;
    }
                    /* 4 = Adlib */
    if ((key & 0xff) == 0x34) {
      clrscr();
      printf("Adlib (1. Original  2. Gold):",unaff_SI);
      goto setup_adlib;
    }
                    /* Roland */
    if ((key & 0xff) == 0x35) {
      mus = 'B';
      clrscr();
      printf("Sound Effects (1. PC Speaker  2. Sound Blaster  3. Pro Audio Spectrum\n",unaff_SI);
      printf("               4. Adlib       5. None):",unaff_SI);
      goto pick_sfx_card;
    }
  } while ((key & 0xff) != 0x36);
  sfx = '3';
setup_pc_speaker:
  mus = '3';
  goto pick_irq;
  while( true ) {
    if ((key & 0xff) == 0x32) {
      sfx = '5';
      mus = '5';
      goto pick_irq;
    }
    if ((key & 0xff) == 0x33) break;
setup_soundblaster:
    irq = '7';
    while (key = ovr_biosKeyAvail(), (char)key != '\0') {
      ovr_biosReadKey();
    }
    key = ovr_biosReadKey();
    if ((key & 0xff) == 0x1b) {
      printf("\n",unaff_SI);
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if ((key & 0xff) == 0x31) {
      sfx = '2';
      mus = '2';
      goto pick_irq;
    }
  }
  sfx = '6';
  mus = '6';
  goto pick_irq;
  while ((key & 0xff) != 0x32) {
setup_pro_audio_spectrum:
    while (key = ovr_biosKeyAvail(), (char)key != '\0') {
      ovr_biosReadKey();
    }
    key = ovr_biosReadKey();
    if ((key & 0xff) == 0x1b) {
      printf("\n",unaff_SI);
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if ((key & 0xff) == 0x31) {
      sfx = '7';
      mus = '7';
      goto pick_irq;
    }
  }
  sfx = '8';
  mus = '8';
  irq = '5';
  goto pick_irq;
  while ((key & 0xff) != 0x32) {
setup_adlib:
    while (key = ovr_biosKeyAvail(), (char)key != '\0') {
      ovr_biosReadKey();
    }
    key = ovr_biosReadKey();
    if ((key & 0xff) == 0x1b) {
      printf("\n",unaff_SI);
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if ((key & 0xff) == 0x31) {
      sfx = '9';
      mus = '9';
      goto pick_irq;
    }
  }
  sfx = 'A';
  mus = 'A';
  goto pick_irq;
  while( true ) {
    if ((key & 0xff) == 0x32) {
      clrscr();
      printf("Sound Blaster (1. Original  2.  Pro):",unaff_SI);
      goto pick_sb_type;
    }
    if ((key & 0xff) == 0x33) {
      clrscr();
      printf("Pro Audio Spectrum (1. Plus  2. Spectrum 16):",unaff_SI);
      goto pick_spectrum_type;
    }
    if ((key & 0xff) == 0x34) {
      clrscr();
      printf("Adlib (1. Original  2. Gold):",unaff_SI);
      goto pick_adlib_type;
    }
    if ((key & 0xff) == 0x35) break;
pick_sfx_card:
    while (key = ovr_biosKeyAvail(), (char)key != '\0') {
      ovr_biosReadKey();
    }
    key = ovr_biosReadKey();
    if ((key & 0xff) == 0x1b) {
      printf("\n",unaff_SI);
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if ((key & 0xff) == 0x31) {
      uVar2 = ovr_vda_query();
      if ((uVar2 == 0x0) || (uVar2 == 0x80)) {
        sfx = '1';
      }
      else {
        sfx = '4';
      }
      goto pick_irq;
    }
  }
  sfx = '3';
  goto pick_irq;
  while ((key & 0xff) != 0x32) {
pick_sb_type:
    irq = '7';
    while (key = ovr_biosKeyAvail(), (char)key != '\0') {
      ovr_biosReadKey();
    }
    key = ovr_biosReadKey();
    if ((key & 0xff) == 0x1b) {
      printf("\n",unaff_SI);
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if ((key & 0xff) == 0x31) {
      sfx = '2';
      goto pick_irq;
    }
  }
  sfx = '5';
  goto pick_irq;
  while ((key & 0xff) != 0x32) {
pick_spectrum_type:
    while (key = ovr_biosKeyAvail(), (char)key != '\0') {
      ovr_biosReadKey();
    }
    key = ovr_biosReadKey();
    if ((key & 0xff) == 0x1b) {
      printf("\n",unaff_SI);
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if ((key & 0xff) == 0x31) {
      sfx = '7';
      goto pick_irq;
    }
  }
  sfx = '8';
  irq = '5';
  goto pick_irq;
  while ((key & 0xff) != 0x32) {
pick_adlib_type:
    while (key = ovr_biosKeyAvail(), (char)key != '\0') {
      ovr_biosReadKey();
    }
    key = ovr_biosReadKey();
    if ((key & 0xff) == 0x1b) {
      printf("\n",unaff_SI);
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if ((key & 0xff) == 0x31) {
      sfx = '9';
      goto pick_irq;
    }
  }
  sfx = 'A';
pick_irq:
  if (irq != '0') {
    clrscr();
    printf("Sound IRQ is %c (1. Don\'t change  2. IRQ 2  3. IRQ 5\n",(int)irq);
    printf("                                 ",unaff_SI);
    do {
      while (key = ovr_biosKeyAvail(), (char)key != '\0') {
        ovr_biosReadKey();
      }
      key = ovr_biosReadKey();
      if ((key & 0xff) == 0x1b) {
        printf("\n",unaff_SI);
                    /* WARNING: Subroutine does not return */
        exit(0);
      }
      if ((key & 0xff) == 0x31) goto done;
      if ((key & 0xff) == 0x32) {
        irq = '2';
        goto done;
      }
      if ((key & 0xff) == 0x33) {
        irq = '5';
        goto done;
      }
      if ((key & 0xff) == 0x34) {
        irq = '7';
        goto done;
      }
    } while ((key & 0xff) != 0x35);
    irq = 'A';
  }
done:
  clrscr();
  bVar3 = write_game_cfg(sfx,mus,irq);
  if (bVar3) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  exit(0x83);
}



/* 6257:0a81 */

/* WARNING: Removing unreachable block (ram,0x00063027) */

void __cdecl16far init_check_mem(void)

{
  char *smem;
  long lmem_without_psp;
  undefined2 in_stack_0000ffa8;
  long lmem;
  
  lmem_without_psp = LXLSH_at_((ulong)((*(int *)&_pspseg.himem - _psp) + 1),4);
  if (lmem_without_psp + 0x100 < 0x8ed28) {
    smem = ovr_litoa10(&stack0xffa8,lmem_without_psp + 0x100);
    printf("Largest executable program size is only %s bytes.\n",smem);
    printf("Stronghold requires 585,000 bytes.\n",in_stack_0000ffa8);
                    /* WARNING: Subroutine does not return */
    exit(0x84);
  }
  return;
}


