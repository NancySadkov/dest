/*
 * ovc11_audio.c - recovered from STRONG.EXE
 * memory block: OVC11_audio.c
 * range: 3a5b:0000 - 3a5b:0c1f
 * functions: 13
 */
#include "recovered.h"


/* 3a5b:0000 */

/* WARNING: Removing unreachable block (ram,0x0003a69a) */
/* [R4] calls LDIV_at_ */

void __cdecl16far audio_usesLDIV_at_(void)

{
  bool bVar1;
  uint uVar2;
  ulong *puVar3;
  uint16_t uVar4;
  int in_DX;
  long lVar5;
  
  if (GameRunning) {
    uVar2 = audio_isPlaying();
    if ((uVar2 & 0xff) == 0) {
      GameRunning = false;
      play_sfx();
      GameRunning = true;
    }
  }
  else {
    if (((MusRunning != '\0') && (CurMusicType != -1)) &&
       (uVar2 = audio_isPlaying(), (uVar2 & 0xff) == 0)) {
      play_sfx();
    }
    if (((SfxRunning != '\0') && (CurSfxType3 != 0xff)) && (bVar1 = ovr_digSoundPlaying(), !bVar1))
    {
      if (CurSfxType3 == 0x80) {
        ovr_randBelow();
      }
      else if (CurSfxType3 == 0x83) {
        ovr_randBelow();
      }
      else if (CurSfxType3 == 0x76) {
        puVar3 = ovr_attact_usesBDADailyTimeCounter();
        if ((in_DX == 0) && (puVar3 < SfxDeadline)) {
          return;
        }
        ovr_randBelow();
        lVar5 = 0x8000;
        uVar2 = rand();
        lVar5 = LDIV_at_(CONCAT22(((int)uVar2 >> 0xf) << 1 | (uint)((int)uVar2 < 0),uVar2 << 1),
                         lVar5);
        if ((int)lVar5 == 0) {
          SfxDeadline = (uint16_t)(0x0);
        }
        else {
          uVar4 = ovr_randBelow();
          SfxDeadline = (uint16_t)(((uVar4 & 0xff) + 0x80));
        }
        sfxTickHi = *(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
        sfxTickLo = *(undefined2 *)BDA_DailyTimeCounter;
      }
      else if (CurSfxType3 == 0x70) {
        ovr_randBelow();
      }
      else if (CurSfxType3 == 0x86) {
        ovr_randBelow();
      }
      else if (CurSfxType3 == 0x7a) {
        ovr_randBelow();
      }
      else if (CurSfxType3 == 0x7d) {
        ovr_randBelow();
      }
      else if (CurSfxType3 == 0x6a) {
        ovr_randBelow();
      }
      else if (CurSfxType3 == 0x64) {
        ovr_randBelow();
      }
      else if (CurSfxType3 == 0x67) {
        ovr_randBelow();
      }
      else if (CurSfxType3 == 0x5e) {
        ovr_randBelow();
      }
      else if (CurSfxType3 == 0x61) {
        ovr_randBelow();
      }
      else if (CurSfxType3 == 0x73) {
        ovr_randBelow();
      }
      else if (CurSfxType3 == 0x6f) {
        ovr_randBelow();
      }
      play_sfx();
    }
  }
  return;
}



/* 3a5b:026f */

/* WARNING: Variable defined which should be unmapped: result */
/* Frees audio buffers, when we are out of space.
   Returns true on success. */

bool __cdecl16far fmFreeAudio(uint16_t force,...)

{
  uint3 uVar1;
  ulong uVar2;
  bool bVar3;
  uint uVar4;
  char in_stack_00000004;
  uint16_t uStack_6;
  uint uStack_4;
  uint8_t result;
  
  uVar1 = _uStack_6;
  _uStack_6 = far_from_u32((uint32_t)(ulong))_uStack_6;
  if ((SfxRunning != '\0') && (DIGHandle.ofs != 0 || DIGHandle.seg != 0)) {
    if (in_stack_00000004 == '\0') {
      uStack_4 = (uint)(byte)(uVar1 >> 0x10);
      _uStack_6 = far_from_u32((uint32_t)(CONCAT22(uStack_4,0x3a5b)));
      bVar3 = ovr_digSoundPlaying();
      if (bVar3) goto L_fmFreeAudio_02D1;
    }
    if (DIG_2410_07a8 == '\0') {
      bVar3 = ovr_digSoundPlaying();
      if (bVar3) {
        ovr_digStopCurrentSound();
      }
      uStack_6 = DIGHandle.seg;
      ovr_stshFree(_uStack_6,DIGHandle.ofs);
      DIGHandle.seg = 0;
      DIGHandle.ofs = 0;
      _uStack_6 = far_from_u32((uint32_t)(CONCAT13(1,_uStack_6)));
    }
  }
L_fmFreeAudio_02D1:
  uVar2 = (ulong)_uStack_6;
  if (((MusRunning != '\0') && (MUSHandle.ofs != 0 || MUSHandle.seg != 0)) &&
     (uVar4 = (uint)MUS_2410_07a9, uVar4 == 0)) {
    if (in_stack_00000004 == '\0') {
      _uStack_6 = far_from_u32((uint32_t)((ulong)_uStack_6 & 0xffff0000));
      ovr_midGetSequenceStatus();
      if (uVar4 == 1) goto end;
    }
    uStack_4 = SUB42(uVar2,2);
    ovr_midGetSequenceStatus();
    if (uVar4 == 1) {
      ovr_midMidiStop();
    }
    uStack_6 = MUSHandle.seg;
    ovr_stshFree(_uStack_6,MUSHandle.ofs);
    MUSHandle.seg = 0;
    MUSHandle.ofs = 0;
    _uStack_6 = far_from_u32((uint32_t)(0x1000000));
  }
end:
  return (bool)result;
}



/* 3a5b:032e */

void __cdecl16far stop_audio(void)

{
  uint16_t unaff_BP;
  
  if (!GameRunning) {
    fmFreeAudio(unaff_BP,1);
    CurSfxType3 = 0xff;
  }
  return;
}



/* 3a5b:034e */

/* Returns whether a sound effect or the music sequence is currently playing. */

uint __cdecl16far audio_isPlaying(void)

{
  bool bVar1;
  uint in_AX;
  undefined1 extraout_AH;
  
  if (SfxRunning != '\0') {
    bVar1 = ovr_digSoundPlaying();
    in_AX = CONCAT11(extraout_AH,bVar1);
    if (bVar1) {
      return CONCAT11(extraout_AH,1);
    }
  }
  if ((MusRunning != '\0') && (ovr_midGetSequenceStatus(), in_AX == 1)) {
    return 1;
  }
  return in_AX & 0xff00;
}



/* 3a5b:037e */

/* [R1] forwards to ovr_midGetSequenceStatus */

uint __cdecl16far ovr_midGetSequenceStatus_entry(void)

{
  uint in_AX;
  
  if ((MusRunning != '\0') && (ovr_midGetSequenceStatus(), in_AX == 1)) {
    return 1;
  }
  return in_AX & 0xff00;
}



/* 3a5b:039a */

void __cdecl16far play_sfxU(byte fid,int type,uint16_t unk,...)

{
  bool bVar1;
  uint8_t *puVar2;
  uint16_t uVar3;
  uint16_t uVar4;
  uint unaff_DI;
  byte in_stack_00000004;
  ulong uVar5;
  undefined2 uVar6;
  uint uStack_a;
  
  uVar5 = (ulong)unaff_DI << 0x10;
  if ((!GameRunning) && (in_stack_00000004 != 0xff)) {
    if ((0x89 < in_stack_00000004) ||
       (*(int *)((uint)in_stack_00000004 * 4) == 0 && ((int *)((uint)in_stack_00000004 * 4))[1] == 0
       )) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit();
    }
    if (*(int *)((uint)in_stack_00000004 * 2 + 0x114) == 0) {
      audio_textMidiError(in_stack_00000004,_fid);
    }
    else if ((AudioAssetsReady1 != '\0') && (SfxRunning != '\0')) {
      if ((CurrentlyPlayingSfx != in_stack_00000004) && (_fid == 1)) {
        uVar5 = CONCAT22(unaff_DI,0x3a5b);
        bVar1 = ovr_digSoundPlaying();
        if (bVar1) {
          return;
        }
      }
      if ((((CFG_Sfx != '1') && (CFG_Sfx != '4')) && (CFG_Sfx != '9')) ||
         ((_fid != 3 && (_fid != 4)))) {
        do {
          uVar6 = (undefined2)(uVar5 >> 0x10);
          if (_fid != 2) break;
          uVar5 = uVar5 & 0xffff0000;
          bVar1 = ovr_digSoundPlaying();
          uVar6 = (undefined2)(uVar5 >> 0x10);
        } while (bVar1);
        bVar1 = ovr_digSoundPlaying();
        if (bVar1) {
          ovr_digStopCurrentSound();
        }
        DIG_2410_07a8 = 1;
        audioBusy = 1;
        if (DIGHandle.ofs != 0 || DIGHandle.seg != 0) {
          ovr_stshFree();
        }
        DIGHandle.ofs = 0;
        DIGHandle.seg = 0;
        uVar3 = 0x1703;
        DIGHandle.ofs = (uint16_t)ovr_stash_loadFromStrongDat();
        DIGHandle.seg = uVar3;
        audioBusy = 0;
        if ((undefined1 *)DIGHandle.ofs != (undefined1 *)0x0 || uVar3 != 0) {
          if (((CFG_Sfx == '1') || (CFG_Sfx == '4')) || (CFG_Sfx == '9')) {
            uStack_a = *(uint *)(DIGHandle.ofs + 5);
            if (30000 < uStack_a) {
              uStack_a = 30000;
            }
          }
          else {
            uStack_a = *(uint *)(DIGHandle.ofs + 5);
          }
          uVar4 = uStack_a + 0xd;
          puVar2 = ovr_stshRealloc(CONCAT22(uVar4,uVar3),
                                   CONCAT22(uVar6,(uint)(0xfff1 < uStack_a) -
                                                  (uint)(uStack_a == 0xfff2)),DIGHandle.ofs);
          DIGHandle.seg = uVar4;
          DIGHandle.ofs = (uint16_t)puVar2;
          DIG_2410_07a8 = 0;
          *(uint16_t *)(puVar2 + 3) = uVar4;
          *(uint8_t **)(puVar2 + 1) = puVar2 + 0xd;
          uVar4 = DIGHandle.seg;
          uVar3 = DIGHandle.ofs;
          *(undefined2 *)(uVar3 + 9) = (char *)"puppetmaker" + 3;
          *(undefined2 *)(uVar3 + 7) = 0x8f92;
          *(uint *)(DIGHandle.ofs + 5) = uStack_a;
          ovr_digPreformatSound();
          ovr_digPlayPreformatedSound();
          ovr_digSetSterioPanning();
          if (_fid == 3) {
            CurSfxType3 = in_stack_00000004;
          }
          CurrentlyPlayingSfx = in_stack_00000004;
        }
      }
    }
  }
  return;
}



/* 3a5b:0633 */

void __cdecl16far play_sfx(int16_t track,int16_t type,...)

{
  undefined2 in_AX;
  uint16_t unaff_BP;
  undefined1 in_stack_00000004;
  
  play_sfxU((byte)track,0x40,unaff_BP,CONCAT11((char)((uint)in_AX >> 8),in_stack_00000004));
  return;
}



/* 3a5b:0648 */

/* [R2] string "Midi error\r" */

void __cdecl16far audio_textMidiError(byte track,int status)

{
  far_t handle;
  far_t entry;
  char cVar1;
  uint uVar2;
  uint16_t uVar3;
  uint16_t unaff_SI;
  bool bVar4;
  
  if (((MusRunning != '\0') && (AudioAssetsReady2 != '\0')) &&
     ((uVar2 = (uint)CurrentTrack, CurrentTrack == track ||
      ((status != 1 || (ovr_midGetSequenceStatus(), uVar2 != 1)))))) {
    do {
      if (status != 2) break;
      ovr_midGetSequenceStatus();
      bVar4 = uVar2 == 1;
      uVar2 = 1;
    } while (bVar4);
    ovr_midMidiStop();
    audioBusy = 1;
    MUS_2410_07a9 = 1;
    if (MUSHandle.ofs != 0 || MUSHandle.seg != 0) {
      handle.seg = unaff_SI;
      handle.ofs = MUSHandle.seg;
      ovr_stshFree(handle,MUSHandle.ofs);
    }
    MUSHandle.ofs = 0;
    MUSHandle.seg = 0;
    uVar3 = 0x1703;
    entry.seg = unaff_SI;
    entry.ofs = ((undefined2 *)((uint)track * 4))[1];
    MUSHandle.ofs = (uint16_t)ovr_stash_loadFromStrongDat(entry,*(undefined2 *)((uint)track * 4));
    MUSHandle.seg = uVar3;
    audioBusy = 0;
    if ((undefined1 *)MUSHandle.ofs != (undefined1 *)0x0 || uVar3 != 0) {
      MUS_2410_07a9 = 0;
      cVar1 = (char)MUSHandle.ofs + '\r';
      ovr_midRegisterXMIDI();
      if (cVar1 == '\0') {
        printf("Midi error\r");
      }
      else {
        ovr_midSetRelativeValue();
        ovr_midPlaySequence(unaff_SI,0);
      }
      CurrentTrack = track;
    }
  }
  return;
}



/* 3a5b:0761 */

/* [R4] calls ovr_alignToSeg */

uint16_t __cdecl16far audio_usesAlignToSeg(uint8_t *ofs,uint16_t seg,int size)

{
  uint16_t uVar1;
  char *in_stack_00000004;
  
  if (((uint)in_stack_00000004 & 0xf) == 0) {
    uVar1 = ovr_alignToSeg();
  }
  else {
    _fmemmove((char *)((ulong)CONCAT22((uint8_t *)ofs + 1,in_stack_00000004) & 0xfffffff0),
              (char *)CONCAT22((uint8_t *)ofs,in_stack_00000004),(*(uint16_t *)((uint8_t *)&(ofs) + 2)) - 0xf);
    uVar1 = ovr_alignToSeg();
  }
  return uVar1;
}



/* 3a5b:07c2 */

/* Converts one character to a hex digit in the driver parameter at +0x108 and clears the next byte.
    */

void __cdecl16far audio_parseHexDigit(char *driverData,char ch)

{
  undefined2 uVar1;
  
  if (ch != '0') {
    uVar1 = (undefined2)((ulong)driverData >> 0x10);
    if (((char *)driverData)[0x108] != -1) {
      if ((((byte *)_ctype + 1)[ch] & 2) == 0) {
        ((char *)driverData)[0x108] = ch + -0x37;
      }
      else {
        ((char *)driverData)[0x108] = ch + -0x30;
      }
      ((char *)driverData)[0x109] = '\0';
    }
  }
  return;
}



/* 3a5b:081e */

void __cdecl16far sfxInit(void)

{
  bool bVar1;
  undefined1 extraout_AH;
  uint8_t *in_DX;
  int iVar2;
  int unaff_SI;
  undefined2 uVar3;
  int size;
  
  size = unaff_SI;
  bVar1 = ovr_digIsInstalled();
  if (bVar1) {
    SfxRunning = 1;
  }
  else {
    if ((CFG_Sfx < '1') || ('9' < CFG_Sfx)) {
      if (('@' < CFG_Sfx) && (CFG_Sfx < 'G')) {
        unaff_SI = CFG_Sfx + -0x38;
      }
    }
    else {
      unaff_SI = CFG_Sfx + -0x31;
    }
    if (((undefined2 *)&ibmsndComOfs)[unaff_SI * 2] != 0 ||
        ((undefined2 *)&ibmsndComSeg)[unaff_SI * 2] != 0) {
      SfxGfxOfs = ovr_stshLoadGfx();
      uVar3 = (undefined2)
              ((ulong)*(undefined4 *)((undefined2 *)&ibmsndComOfs + unaff_SI * 2) >> 0x10);
      iVar2 = (int)*(undefined4 *)((undefined2 *)&ibmsndComOfs + unaff_SI * 2);
      SfxGfxSeg = in_DX;
      DIGHandle.ofs =
           audio_usesAlignToSeg
                     ((uint8_t *)CONCAT22(*(undefined2 *)(iVar2 + 5),in_DX),*(uint16_t *)(iVar2 + 7)
                      ,size);
      DIGHandle.seg = (uint16_t)in_DX;
      audio_parseHexDigit((char *)CONCAT22(in_DX,DIGHandle.ofs),CFG_Irq);
      ovr_ovc20_compute1();
      bVar1 = audio_init(DIGHandle.seg);
      if (CONCAT11(extraout_AH,bVar1) == 0) {
        DIGHandle.seg = 0;
        DIGHandle.ofs = 0;
                    /* WARNING: Subroutine does not return */
        ovr_stExit();
      }
      SfxRunning = 1;
    }
  }
  return;
}



/* 3a5b:0956 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far musInit(void)

{
  bool bVar1;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  uint8_t *in_DX;
  int iVar2;
  int unaff_SI;
  undefined2 uVar3;
  int size;
  
  size = unaff_SI;
  bVar1 = ovr_midIsLoaded();
  if (CONCAT11(extraout_AH,bVar1) == 0) {
    if ((CFG_Mus < '1') || ('9' < CFG_Mus)) {
      if (('@' < CFG_Mus) && (CFG_Mus < 'G')) {
        unaff_SI = CFG_Mus + -0x38;
      }
    }
    else {
      unaff_SI = CFG_Mus + -0x31;
    }
    if (((undefined2 *)&musDriver0Ofs)[unaff_SI * 2] != 0 ||
        ((undefined2 *)&musDriver0Seg)[unaff_SI * 2] != 0) {
      MidGfxOfs = ovr_stshLoadGfx();
      uVar3 = (undefined2)((ulong)_cmidpakComOfs >> 0x10);
      MidGfxSeg = in_DX;
      MIDHandle.ofs =
           audio_usesAlignToSeg
                     ((uint8_t *)CONCAT22(*(undefined2 *)((int)_cmidpakComOfs + 5),in_DX),
                      *(uint16_t *)((int)_cmidpakComOfs + 7),size);
      MIDHandle.seg = (uint16_t)in_DX;
      ovr_ovc20_compute1();
      MusGfxOfs = ovr_stshLoadGfx();
      uVar3 = (undefined2)
              ((ulong)*(undefined4 *)((undefined2 *)&musDriver0Ofs + unaff_SI * 2) >> 0x10);
      iVar2 = (int)*(undefined4 *)((undefined2 *)&musDriver0Ofs + unaff_SI * 2);
      MusGfxSeg = in_DX;
      MusHandle = audio_usesAlignToSeg
                            ((uint8_t *)CONCAT22(*(undefined2 *)(iVar2 + 5),in_DX),
                             *(uint16_t *)(iVar2 + 7),size);
      MusHandleSeg = in_DX;
      ovr_ovc20_compute1();
      MusDrvOfs = ovr_stshLoadGfx();
      MusDrvSeg = in_DX;
      ovr_ovc20_compute1();
      bVar1 = audio_init(MIDHandle.seg);
      if (CONCAT11(extraout_AH_00,bVar1) == 0) {
        MIDHandle.seg = 0;
        MIDHandle.ofs = 0;
                    /* WARNING: Subroutine does not return */
        ovr_stExit();
      }
      ovr_midLoadDriver();
      MusRunning = 1;
    }
  }
  else {
    MusRunning = 1;
  }
  return;
}



/* 3a5b:0afd */

/* WARNING: Removing unreachable block (ram,0x0003b0c9) */
/* Returns a 0..0x7f pan value from an agent's x (0x7f - clamp(x*127/210)). */

int __cdecl16far audio_panFromX(agnt_t *agnt,...)

{
  uint uVar1;
  int *in_stack_00000004;
  
  uVar1 = (uint)(((long)*(int *)CONCAT22((agnt_t *)agnt,in_stack_00000004) * 0x7f & 0xffffU) / 0xd2)
  ;
  if (0x7f < uVar1) {
    uVar1 = 0x7f;
  }
  return 0x7f - uVar1;
}


