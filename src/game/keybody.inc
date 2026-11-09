uint16_t __cdecl16far gameProcessKey(void)

{
  uint16_t key;
  uint16_t uVar1;
  char *pcVar2;
  char local_52 [80];
  
  key = ovr_biosReadKey();
  if (key == 0x320D) {
    if (AudioAssetsReady2 != '\0') {
      ovr_stop_audio();
    }
    AudioAssetsReady2 = '\x01' - (AudioAssetsReady2 != '\0');
  }
  else if (key == 0x1F13) {
    if (AudioAssetsReady1 != '\0') {
      ovr_stop_audio();
    }
    AudioAssetsReady1 = '\x01' - (AudioAssetsReady1 != '\0');
  }
  else if (GDebug != false) {
    if (key == 0x1000) {
      ovr_OVC30_619c_0a5e(GfxRndSeed,GfxRndSeed2);
    }
    else if ((key == 0x1300) && (VideoFlag_2410_0167 == 0)) {
      VideoFlag_2410_0167 = 1;
      ovr_miceBlitRect(BlitRects + 1);
      ovr_OVC40_69c8_04c6(0,s_W_2410_0251,s_Archduchess_2410_027a,0);
      ovr_miceRestoreArea(BlitRects + 1);
      VideoFlag_2410_0167 = 0;
    }
    else if (key == 0x1500) {
      ovr_OVC41_6a8f_076f();
    }
    else if ((key == 0x1900) && (VideoFlag_2410_0167 == 0)) {
      VideoFlag_2410_0167 = 1;
      ovr_miceBlitRect(BlitRects + 1);
      uVar1 = ovr_randBelow(2);
      ovr_season_67e7_004d(uVar1);
      ovr_miceRestoreArea(BlitRects + 1);
      VideoFlag_2410_0167 = 0;
    }
    else if (key == 0x1f00) {
      GTimeHi = 1;
    }
    else if (key == 0x2000) {
      DebugVerbose = (bool)('\x01' - (DebugVerbose != false));
    }
    else if (key == 0x2100) {
      ovr_OVC41_6a8f_0fc1(10);
    }
    else if (key == 0x2200) {
      DAT_2410_0165 = 1;
    }
    else if (key == 0x2300) {
      pcVar2 = ovr_stsprintf(local_52,"The seed is %lx.",*(uint32_t *)&GSeed);
      ovr_say(pcVar2);
    }
    else if (key == 0x2400) {
      ovr_constrct_7e7c_0000();
    }
    else if (key == 0x2500) {
      DAT_2410_0164 = 1;
    }
    else if (key == 0x2600) {
      GCharLevelsInc = GCharLevelsInc + 1;
      pcVar2 = ovr_stsprintf(local_52,
                             "Increase by %d levels.  Click on character for higher levels.",
                             (int)GCharLevelsInc);
      ovr_say(pcVar2);
    }
    else if (key == 0x2C00) {
      ovr_OVC41_6a8f_29a0();
    }
    else if (key == 0x2E00) {
      ovr_dbgPromoteEnemy();
    }
    else if (key == 0x3000) {
      ovr_OVC41_6a8f_0fc1(1);
    }
    else if (key == 0x3200) {
      ovr_OVC20_4b0a_010c();
    }
  }
  return key;
}
