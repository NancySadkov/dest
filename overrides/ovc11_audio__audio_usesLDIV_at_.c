void __cdecl16far audio_usesLDIV_at_(void)

{
  bool bVar1;
  uint8_t uVar2;
  uint uVar3;
  uint16_t uVar4;
  ulong *puVar5;
  int in_DX;
  long lVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined1 in_stack_0000fffc;
  
  if (GameRunning) {
    uVar3 = audio_isPlaying();
    if ((uVar3 & 0xff) == 0) {
      GameRunning = false;
      play_sfx(46,0);
      GameRunning = true;
    }
  }
  else {
    if (((MusRunning != '\0') && (CurMusicType != 0xff)) &&
       (uVar3 = audio_isPlaying(), (uVar3 & 0xff) == 0)) {
      play_sfx((uint)CurMusicType,0);
    }
    if (((SfxRunning != '\0') && (CurSfxType3 != 0xff)) && (bVar1 = ovr_digSoundPlaying(), !bVar1))
    {
      uVar7 = 0;
      if (CurSfxType3 == 0x80) {
        uVar4 = ovr_randBelow(3);
        uVar2 = (char)uVar4 + 0x80;
        uVar7 = CONCAT11((char)(uVar4 >> 8),uVar2);
      }
      else if (CurSfxType3 == 0x83) {
        uVar4 = ovr_randBelow(3);
        uVar2 = (char)uVar4 + 0x83;
        uVar7 = CONCAT11((char)(uVar4 >> 8),uVar2);
      }
      else if (CurSfxType3 == 0x76) {
        puVar5 = ovr_attact_usesBDADailyTim_8bbe
                           (sfxTickLo,CONCAT13(0x76,CONCAT12(in_stack_0000fffc,sfxTickHi)));
        if ((in_DX == 0) && (puVar5 < SfxDeadline)) {
          return;
        }
        uVar4 = ovr_randBelow(4);
        uVar2 = (char)uVar4 + 0x76;
        uVar8 = 0;
        uVar7 = 0x8000;
        uVar3 = rand();
        lVar6 = LDIV_at_(CONCAT22(((int)uVar3 >> 0xf) << 1 | (uint)((int)uVar3 < 0),uVar3 << 1),
                         CONCAT22(uVar8,uVar7));
        if ((int)lVar6 == 0) {
          SfxDeadline = (uint16_t)(0x0);
        }
        else {
          uVar4 = ovr_randBelow(0x48);
          SfxDeadline = (uint16_t)(((uVar4 & 0xff) + 0x80));
        }
        uVar7 = *(undefined2 far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
        sfxTickLo = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);   /* hand fix: the offset half is the address, and sfxTickLo is 16-bit */
        sfxTickHi = uVar7;
      }
      else if (CurSfxType3 == 0x70) {
        uVar4 = ovr_randBelow(3);
        uVar2 = (char)uVar4 + 0x70;
        uVar7 = CONCAT11((char)(uVar4 >> 8),uVar2);
      }
      else if (CurSfxType3 == 0x86) {
        uVar4 = ovr_randBelow(3);
        uVar2 = (char)uVar4 + 0x86;
        uVar7 = CONCAT11((char)(uVar4 >> 8),uVar2);
      }
      else if (CurSfxType3 == 0x7a) {
        uVar4 = ovr_randBelow(3);
        uVar2 = (char)uVar4 + 0x7a;
        uVar7 = CONCAT11((char)(uVar4 >> 8),uVar2);
      }
      else if (CurSfxType3 == 0x7d) {
        uVar4 = ovr_randBelow(3);
        uVar2 = (char)uVar4 + 0x7d;
        uVar7 = CONCAT11((char)(uVar4 >> 8),uVar2);
      }
      else if (CurSfxType3 == 0x6a) {
        uVar4 = ovr_randBelow(3);
        uVar2 = (char)uVar4 + 0x6a;
        uVar7 = CONCAT11((char)(uVar4 >> 8),uVar2);
      }
      else if (CurSfxType3 == 0x64) {
        uVar4 = ovr_randBelow(3);
        uVar2 = (char)uVar4 + 0x64;
        uVar7 = CONCAT11((char)(uVar4 >> 8),uVar2);
      }
      else if (CurSfxType3 == 0x67) {
        uVar4 = ovr_randBelow(3);
        uVar2 = (char)uVar4 + 0x67;
        uVar7 = CONCAT11((char)(uVar4 >> 8),uVar2);
      }
      else if (CurSfxType3 == 0x5e) {
        uVar4 = ovr_randBelow(3);
        uVar2 = (char)uVar4 + 0x5e;
        uVar7 = CONCAT11((char)(uVar4 >> 8),uVar2);
      }
      else if (CurSfxType3 == 0x61) {
        uVar4 = ovr_randBelow(6);
        uVar2 = (char)uVar4 + 0x5e;
        uVar7 = CONCAT11((char)(uVar4 >> 8),uVar2);
      }
      else if (CurSfxType3 == 0x73) {
        uVar4 = ovr_randBelow(6);
        uVar2 = (char)uVar4 + 0x73;
        uVar7 = CONCAT11((char)(uVar4 >> 8),uVar2);
      }
      else {
        uVar2 = CurSfxType3;
        if (CurSfxType3 == 0x6f) {
          uVar4 = ovr_randBelow(3);
          uVar2 = (char)uVar4 + 0x6d;
          uVar7 = CONCAT11((char)(uVar4 >> 8),uVar2);
        }
      }
      play_sfx(CONCAT11((char)((uint)uVar7 >> 8),uVar2),4);
    }
  }
  return;
}
