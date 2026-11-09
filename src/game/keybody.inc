uint16_t __cdecl16far gameProcessKey(void)

{
  uint16_t key;
  uint16_t uVar1;
  char *pcVar2;
  char local_52 [80];
  
  key = ovr_biosReadKey();
  if ((char *)key == (char *)"marble.lbm" + 5) {
    if (AudioAssetsReady2 != '\0') {
      ovr_stop_audio();
    }
    AudioAssetsReady2 = '\x01' - (AudioAssetsReady2 != '\0');
  }
  else if ((char *)key == (char *)"halfling abode" + 7) {
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
      ovr_OVC40_69c8_04c6(0,0x251,(char *)"puppetmaker" + 3,0x27a,(char *)"puppetmaker" + 3,0);
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
    else if ((char *)key == (char *)"main castle" + 1) {
      ovr_OVC41_6a8f_0fc1(10);
    }
    else if ((char *)key == (char *)"manned corner wall" + 0xb) {
      DAT_2410_0165 = 1;
    }
    else if ((char *)key == (char *)"mason\'s hall" + 7) {
      pcVar2 = ovr_stsprintf(local_52,"The seed is %lx.",GSeed);
      ovr_say(pcVar2);
    }
    else if ((char *)key == (char *)"arena" + 4) {
      ovr_constrct_7e7c_0000();
    }
    else if ((char *)key == (char *)"dagger") {
      DAT_2410_0164 = 1;
    }
    else if ((char *)key == (char *)"wood golem" + 6) {
      GCharLevelsInc = GCharLevelsInc + 1;
      pcVar2 = ovr_stsprintf(local_52,
                             "Increase by %d levels.  Click on character for higher levels.",
                             (char *)(uint)GCharLevelsInc);
      ovr_say(pcVar2);
    }
    else if ((char *)key == (char *)"wall2.lbm" + 2) {
      ovr_OVC41_6a8f_29a0();
    }
    else if ((char *)key == (char *)"magelop2.xmi" + 0xb) {
      ovr_dbgPromoteEnemy();
    }
    else if (key == 0x3000) {
      ovr_OVC41_6a8f_0fc1(1);
    }
    else if ((char *)key == (char *)"strong4.lbm" + 4) {
      ovr_OVC20_4b0a_010c();
    }
  }
  return key;
}
