/* init_base - recovered from STRONG.EXE (6257:046a).
   Temporaries named from their single source: uVar4 folded into the existing
   `key` (both are ovr_biosReadKey() results tested with & 0xff), uVar2 ->
   vdaMode (ovr_vda_query()), bVar1 -> haveConfig (init_strong_sav()),
   bVar3 -> cfgWritten (write_game_cfg()). */
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
