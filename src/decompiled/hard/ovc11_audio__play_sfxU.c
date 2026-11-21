void __cdecl16far play_sfxU(byte fid,int type,uint16_t unk,...)

{
  bool bVar1;
  uint8_t *puVar2;
  uint16_t uVar3;
  uint16_t uVar4;
  far_t entry;
  uint uStack_a;
  
  if ((!GameRunning) && (fid != 0xff)) {
    if ((0x89 < fid) || (*(int *)((uint)fid * 4) == 0 && ((int *)((uint)fid * 4))[1] == 0)) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x22);
    }
    if (*(int *)((uint)fid * 2 + 0x114) == 0) {
      audio_textMidiError(fid,type);
    }
    else if ((((AudioAssetsReady1 != '\0') && (SfxRunning != '\0')) &&
             ((CurrentlyPlayingSfx == fid ||
              ((type != 1 || (bVar1 = ovr_digSoundPlaying(), !bVar1)))))) &&
            (((CFG_Sfx != '1' && ((CFG_Sfx != '4' && (CFG_Sfx != '9')))) ||
             ((type != 3 && (type != 4)))))) {
      do {
        if (type != 2) break;
        bVar1 = ovr_digSoundPlaying();
      } while (bVar1);
      bVar1 = ovr_digSoundPlaying();
      if (bVar1) {
        ovr_digStopCurrentSound();
      }
      DIG_2410_07a8 = 1;
      audioBusy = 1;
      if (DIGHandle.ofs != 0 || DIGHandle.seg != 0) {
        ovr_stshFree(DIGHandle);
      }
      DIGHandle.ofs = 0;
      DIGHandle.seg = 0;
      uVar3 = 0x1703;
      entry.seg = ((uint16_t *)((uint)fid * 4))[1];
      entry.ofs = *(uint16_t *)((uint)fid * 4);
      DIGHandle.ofs = (uint16_t)ovr_stash_loadFromStrongDat(entry);
      DIGHandle.seg = uVar3;
      audioBusy = 0;
      if ((undefined1 *)DIGHandle.ofs != (undefined1 *)0x0 || uVar3 != 0) {
        if (((CFG_Sfx == '1') || (CFG_Sfx == '4')) || (CFG_Sfx == '9')) {
          uStack_a = *(uint far *)((uint8_t far *)MK_FP(DIGHandle.seg, DIGHandle.ofs) +  5);
          if (30000 < uStack_a) {
            uStack_a = 30000;
          }
        }
        else {
          uStack_a = *(uint far *)((uint8_t far *)MK_FP(DIGHandle.seg, DIGHandle.ofs) +  5);
        }
        uVar4 = uStack_a + 0xd;
        puVar2 = ovr_stshRealloc((uint32_t)CONCAT22(uVar3,DIGHandle.ofs),
                                 CONCAT22((uint)(0xfff1 < uStack_a) - (uint)(uStack_a == 0xfff2),
                                          uVar4));
        DIGHandle.seg = uVar4;
        DIGHandle.ofs = (uint16_t)puVar2;
        DIG_2410_07a8 = 0;
        *(uint16_t *)(puVar2 + 3) = uVar4;
        *(uint8_t **)(puVar2 + 1) = puVar2 + 0xd;
        uVar4 = DIGHandle.seg;
        uVar3 = DIGHandle.ofs;
        *(undefined2 *)(uVar3 + 9) = 0x2410;   /* hand fix: 2-byte segment-half slot; the literal offset is that DGROUP segment value */
        *(undefined2 *)(uVar3 + 7) = 0x8f92;
        *(uint far *)((uint8_t far *)MK_FP(DIGHandle.seg, DIGHandle.ofs) +  5) = uStack_a;
        ovr_digPreformatSound();
        ovr_digPlayPreformatedSound();
        ovr_digSetSterioPanning();
        if (type == 3) {
          CurSfxType3 = fid;
        }
        CurrentlyPlayingSfx = fid;
      }
    }
  }
  return;
}
