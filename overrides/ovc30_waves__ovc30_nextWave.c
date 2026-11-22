/* 619c:004e */

/* Starts the next enemy wave.  On the first wave (PlayerIndex becomes 1) it
   spawns the low, medium and high bands, each of size
   enemyBase*[Difficulty] + randBelow(*IntelEnemies[Difficulty] + 1); on the
   second wave it spawns the elite band only, plus one more unit when
   Difficulty > 1, and announces the wave.  flags bit 0 asks for the
   "All enemies destroyed." notice, bit 1 suppresses the blit-rect update. */

void __cdecl16far ovc30_nextWave(byte flags)

{
  typedef char far *stsprintf_far_t(char *buf,char far *fmt,int v);

  char msg[0x79];
  char far *line;
  byte pending;

  if (PlayerIndex < 2) {
    PlayerIndex = PlayerIndex + 1;
    if (PlayerIndex == 1) {
      pending = enemyBaseLow[Difficulty] +
                (byte)ovr_randBelow((byte)lowIntelEnemies[Difficulty] + 1);
      while (pending != '\0') {
        pending = pending - 1;
        ovc30_textDivideError((byte)ovc30_usesRandBelow(0),1,1,0x19);
      }
      pending = enemyBaseMed[Difficulty] +
                (byte)ovr_randBelow((byte)lowIntelEnemies[Difficulty] + 1);
      while (pending != '\0') {
        pending = pending - 1;
        ovc30_textDivideError((byte)ovc30_usesRandBelow(1),1,1,0x19);
      }
      pending = enemyBaseHigh[Difficulty] +
                (byte)ovr_randBelow((byte)highIntelEnemies[Difficulty] + 1);
      while (pending != '\0') {
        pending = pending - 1;
        ovc30_textDivideError((byte)ovc30_usesRandBelow(2),1,1,0);
      }
    }
    else {
      pending = enemyBaseWave[Difficulty];
      while (pending != '\0') {
        pending = pending - 1;
        ovc30_textDivideError((byte)ovc30_usesRandBelow(3),1,1,0);
      }
      if (1 < Difficulty) {
        ovc30_textDivideError((byte)ovc30_usesRandBelow(4),1,1,0);
      }
      if ((flags & 1) != 0) {
        ovr_uiNotify((char far *)s_all_enemies_destroyed,0xa000);
        ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x36));
      }
      line = ((stsprintf_far_t *)ovr_stsprintf)
                 (msg,(char far *)s_next_wave_of_enemies_appear,PlayerIndex + 1);
      ovr_uiNotify(line,0xa000);
      ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x36));
    }
    if ((flags & 2) == 0) {
      ovr_constr_usesBlitRect();
    }
  }
  return;
}
