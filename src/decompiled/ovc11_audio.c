/*
 * ovc11_audio.c - recovered from STRONG.EXE
 * memory block: OVC11_audio.c
 * range: 3a5b:0000 - 3a5b:0c1f
 * functions: 13
 */
#include "recovered.h"


/* 3a5b:0000 */
void __cdecl16far audio_usesLDIV_at_(void)

{
  bool bVar1;
  uint8_t sfxId;
  uint uVar3;
  uint16_t roll;
  ulong *puVar5;
  int in_DX;
  long lVar6;
  uint16_t uVar7;
  uint16_t uVar8;
  undefined1 in_stack_0000fffc;
  
  if (GameRunning) {
    uVar3 = audio_isPlaying();
    if ((uVar3 & 0xff) == 0) {
      GameRunning = false;
      play_sfx(46,0,0);
      GameRunning = true;
    }
  }
  else {
    if (((MusRunning != '\0') && (CurMusicType != 0xff)) &&
       (uVar3 = audio_isPlaying(), (uVar3 & 0xff) == 0)) {
      play_sfx((uint)CurMusicType,0,0);
    }
    if (((SfxRunning != '\0') && (CurSfxType3 != 0xff)) && (bVar1 = ovr_digSoundPlaying(), !bVar1))
    {
      uVar7 = 0;
      if (CurSfxType3 == 0x80) {
        roll = ovr_randBelow(3,0);
        sfxId = (char)roll + 0x80;
        uVar7 = CONCAT11((char)(roll >> 8),sfxId);
      }
      else if (CurSfxType3 == 0x83) {
        roll = ovr_randBelow(3,0);
        sfxId = (char)roll + 0x83;
        uVar7 = CONCAT11((char)(roll >> 8),sfxId);
      }
      else if (CurSfxType3 == 0x76) {
        puVar5 = ovr_attact_usesBDADailyTimeCounter
                           (sfxTickLo,CONCAT13(0x76,CONCAT12(in_stack_0000fffc,sfxTickHi)),0);
        if ((in_DX == 0) && (puVar5 < SfxDeadline)) {
          return;
        }
        roll = ovr_randBelow(4,0);
        sfxId = (char)roll + 0x76;
        uVar8 = 0;
        uVar7 = 0x8000;
        uVar3 = rand();
        lVar6 = LDIV_at_(CONCAT22(((int)uVar3 >> 0xf) << 1 | (uint)((int)uVar3 < 0),uVar3 << 1),
                         CONCAT22(uVar8,uVar7));
        if ((int)lVar6 == 0) {
          SfxDeadline = (uint16_t)(0x0);
        }
        else {
          roll = ovr_randBelow(0x48,0);
          SfxDeadline = (uint16_t)(((roll & 0xff) + 0x80));
        }
        uVar7 = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
        sfxTickLo = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);   /* hand fix: the offset half is the address, and sfxTickLo is 16-bit */
        sfxTickHi = uVar7;
      }
      else if (CurSfxType3 == 0x70) {
        roll = ovr_randBelow(3,0);
        sfxId = (char)roll + 0x70;
        uVar7 = CONCAT11((char)(roll >> 8),sfxId);
      }
      else if (CurSfxType3 == 0x86) {
        roll = ovr_randBelow(3,0);
        sfxId = (char)roll + 0x86;
        uVar7 = CONCAT11((char)(roll >> 8),sfxId);
      }
      else if (CurSfxType3 == 0x7a) {
        roll = ovr_randBelow(3,0);
        sfxId = (char)roll + 0x7a;
        uVar7 = CONCAT11((char)(roll >> 8),sfxId);
      }
      else if (CurSfxType3 == 0x7d) {
        roll = ovr_randBelow(3,0);
        sfxId = (char)roll + 0x7d;
        uVar7 = CONCAT11((char)(roll >> 8),sfxId);
      }
      else if (CurSfxType3 == 0x6a) {
        roll = ovr_randBelow(3,0);
        sfxId = (char)roll + 0x6a;
        uVar7 = CONCAT11((char)(roll >> 8),sfxId);
      }
      else if (CurSfxType3 == 0x64) {
        roll = ovr_randBelow(3,0);
        sfxId = (char)roll + 0x64;
        uVar7 = CONCAT11((char)(roll >> 8),sfxId);
      }
      else if (CurSfxType3 == 0x67) {
        roll = ovr_randBelow(3,0);
        sfxId = (char)roll + 0x67;
        uVar7 = CONCAT11((char)(roll >> 8),sfxId);
      }
      else if (CurSfxType3 == 0x5e) {
        roll = ovr_randBelow(3,0);
        sfxId = (char)roll + 0x5e;
        uVar7 = CONCAT11((char)(roll >> 8),sfxId);
      }
      else if (CurSfxType3 == 0x61) {
        roll = ovr_randBelow(6,0);
        sfxId = (char)roll + 0x5e;
        uVar7 = CONCAT11((char)(roll >> 8),sfxId);
      }
      else if (CurSfxType3 == 0x73) {
        roll = ovr_randBelow(6,0);
        sfxId = (char)roll + 0x73;
        uVar7 = CONCAT11((char)(roll >> 8),sfxId);
      }
      else {
        sfxId = CurSfxType3;
        if (CurSfxType3 == 0x6f) {
          roll = ovr_randBelow(3,0);
          sfxId = (char)roll + 0x6d;
          uVar7 = CONCAT11((char)(roll >> 8),sfxId);
        }
      }
      play_sfx(CONCAT11((char)((uint)uVar7 >> 8),sfxId),4,0);
    }
  }
  return;
}


/* 3a5b:026f */

/* Frees audio buffers, when we are out of space.
   Returns true on success. */

bool __cdecl16far fmFreeAudio(uint16_t force)

{
  bool playing;
  uint uVar2;
  far_t handle;
  far_t handle_00;
  uint8_t result;
  
  result = 0x0;
  if ((((SfxRunning != '\0') && (DIGHandle.ofs != 0 || DIGHandle.seg != 0)) &&
      (((char)force != '\0' || (playing = ovr_digSoundPlaying(), !playing)))) && (DIG_2410_07a8 == '\0')
     ) {
    playing = ovr_digSoundPlaying();
    if (playing) {
      ovr_digStopCurrentSound();
    }
    handle.seg = DIGHandle.seg;
    handle.ofs = DIGHandle.ofs;
    ovr_stshFree(handle);
    DIGHandle.seg = 0;
    DIGHandle.ofs = 0;
    result = 0x1;
  }
  if (((MusRunning != '\0') && (MUSHandle.ofs != 0 || MUSHandle.seg != 0)) &&
     (uVar2 = (uint)MUS_2410_07a9, uVar2 == 0)) {
    if (((char)force == '\0') && (ovr_midGetSequenceStatus(), uVar2 == 1)) {
      return (bool)result;
    }
    ovr_midGetSequenceStatus();
    if (uVar2 == 1) {
      ovr_midMidiStop();
    }
    handle_00.seg = MUSHandle.seg;
    handle_00.ofs = MUSHandle.ofs;
    ovr_stshFree(handle_00);
    MUSHandle.seg = 0;
    MUSHandle.ofs = 0;
    result = 0x1;
  }
  return (bool)result;
}



/* 3a5b:032e */

void __cdecl16far stop_audio(void)

{
  if (!GameRunning) {
    fmFreeAudio(1);
    CurSfxType3 = 0xff;
  }
  return;
}



/* 3a5b:034e */

/* Returns whether a sound effect or the music sequence is currently playing. */

uint __cdecl16far audio_isPlaying(void)

{
  /* 3a5b:034e (file 0x2C6FE), re-derived: the original is

       if (SfxRunning) { digSoundPlaying() ; if (al) return 1 }
       if (MusRunning) { if (midGetSequenceStatus() == 1) return 1 }
       return 0

     with `mov al,1` at 0x2C711/0x2C726 and `mov al,0` at 0x2C72A.  The exported
     `extraout_AH` / `in_AX` pseudo-registers were stale-High-byte artifacts, and the
     `in_AX == 1` test after the second call was testing that stale value instead of
     `midGetSequenceStatus()`'s own return (the original compares `ax` right after the
     lcall, 0x2C721). */
  if (SfxRunning != '\0') {
    if (ovr_digSoundPlaying()) {
      return 1;
    }
  }
  if (MusRunning != '\0') {
    if (ovr_midGetSequenceStatus() == 1) {
      return 1;
    }
  }
  return 0;
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
void __cdecl16far play_sfxU(byte fid,int type,uint16_t unk,uint16_t arg4,uint16_t arg5)

{
  bool playing;
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
              ((type != 1 || (playing = ovr_digSoundPlaying(), !playing)))))) &&
            (((CFG_Sfx != '1' && ((CFG_Sfx != '4' && (CFG_Sfx != '9')))) ||
             ((type != 3 && (type != 4)))))) {
      do {
        if (type != 2) break;
        playing = ovr_digSoundPlaying();
      } while (playing);
      playing = ovr_digSoundPlaying();
      if (playing) {
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
        *(uint16_t *)(uVar3 + 9) = 0x2410;   /* hand fix: 2-byte segment-half slot; the literal offset is that DGROUP segment value */
        *(uint16_t *)(uVar3 + 7) = 0x8f92;
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


/* 3a5b:0633 */

void __cdecl16far play_sfx(int16_t track,int16_t type,uint16_t arg3)

{
  play_sfxU((byte)track,type,0x40,0,0);
  return;
}



/* 3a5b:0648 */

/* [R2] string "Midi error\r" */

void __cdecl16far audio_textMidiError(byte track,int status)

{
  char cVar1;
  uint uVar2;
  uint16_t uVar3;
  bool bVar4;
  far_t entry;
  
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
      ovr_stshFree(MUSHandle);
    }
    MUSHandle.ofs = 0;
    MUSHandle.seg = 0;
    uVar3 = 0x1703;
    entry.seg = ((uint16_t *)((uint)track * 4))[1];
    entry.ofs = *(uint16_t *)((uint)track * 4);
    MUSHandle.ofs = (uint16_t)ovr_stash_loadFromStrongDat(entry);
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
        ovr_midPlaySequence(0);
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
  far_t ptr;
  uint16_t alignedSeg;
  char *in_stack_00000004;
  
  if (((uint)in_stack_00000004 & 0xf) == 0) {
    ptr.seg = (uint16_t)(uint8_t *)ofs;
    ptr.ofs = (uint16_t)in_stack_00000004;
    alignedSeg = ovr_alignToSeg(ptr);
  }
  else {
    _fmemmove((char *)((ulong)CONCAT22((uint8_t *)ofs + 1,in_stack_00000004) & 0xfffffff0),
              (char *)CONCAT22((uint8_t *)ofs,in_stack_00000004),(*(uint16_t *)((uint8_t *)&(ofs) + 2)) - 0xf);
    alignedSeg = ovr_alignToSeg(far_from_u32((uint32_t)((ulong)CONCAT22((uint8_t *)ofs + 1,in_stack_00000004) &
                                  0xfffffff0)));
  }
  return alignedSeg;
}



/* 3a5b:07c2 */

/* Converts one character to a hex digit in the driver parameter at +0x108 and clears the next byte.
    */

void __cdecl16far audio_parseHexDigit(char *driverData,char ch)

{
  uint16_t uVar1;
  
  if (ch != '0') {
    uVar1 = (uint16_t)((ulong)driverData >> 0x10);
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
  far_t handle;
  bool bVar1;
  undefined1 extraout_AH;
  uint8_t *in_DX;
  int iVar2;
  int unaff_SI;
  uint16_t uVar3;
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
    if (((uint16_t *)&ibmsndComOfs)[unaff_SI * 2] != 0 ||
        ((uint16_t *)&ibmsndComSeg)[unaff_SI * 2] != 0) {
      (*(uint8_t *)((uint8_t *)&(handle.seg))) = (char)((uint16_t *)&ibmsndComSeg)[unaff_SI * 2];
      handle.ofs = ((uint16_t *)&ibmsndComOfs)[unaff_SI * 2];
      (*(uint8_t *)((uint8_t *)&(handle.seg) + 1)) = (char)((uint)((uint16_t *)&ibmsndComSeg)[unaff_SI * 2] >> 8);
      SfxGfxOfs = ovr_stshLoadGfx(handle);
      uVar3 = (uint16_t)
              ((ulong)*(uint32_t *)((uint16_t *)&ibmsndComOfs + unaff_SI * 2) >> 0x10);
      iVar2 = (int)*(uint32_t *)((uint16_t *)&ibmsndComOfs + unaff_SI * 2);
      SfxGfxSeg = (uint16_t)in_DX;   /* hand fix: segment is 16-bit */
      DIGHandle.ofs =
           audio_usesAlignToSeg
                     ((uint8_t *)CONCAT22(*(uint16_t *)(iVar2 + 5),in_DX),*(uint16_t *)(iVar2 + 7)
                      ,size);
      DIGHandle.seg = (uint16_t)in_DX;
      audio_parseHexDigit((char *)CONCAT22(in_DX,DIGHandle.ofs),CFG_Irq);
      ovr_ovc20_compute1((char *)((uint16_t *)&ibmsndComOfs)[unaff_SI * 2],
                         (char)((uint16_t *)&ibmsndComSeg)[unaff_SI * 2]);
      bVar1 = audio_init(DIGHandle.seg);
      if (CONCAT11(extraout_AH,bVar1) == 0) {
        DIGHandle.seg = 0;
        DIGHandle.ofs = 0;
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0x81);
      }
      SfxRunning = 1;
    }
  }
  return;
}


/* 3a5b:0956 */
void __cdecl16far musInit(void)

{
  far_t handle;
  far_t handle_00;
  bool bVar1;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  uint8_t *in_DX;
  int iVar2;
  int unaff_SI;
  uint16_t uVar3;
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
    if (((uint16_t *)&musDriver0Ofs)[unaff_SI * 2] != 0 ||
        ((uint16_t *)&musDriver0Seg)[unaff_SI * 2] != 0) {
      MidGfxOfs = ovr_stshLoadGfx(cmidpakComOfs);
      MidGfxSeg = (uint16_t)in_DX;   /* hand fix: segment is 16-bit */
      MIDHandle.ofs =
           audio_usesAlignToSeg
                     ((uint8_t *)CONCAT22(*(uint16_t *)((char *)cmidpakComOfs + 5),in_DX),
                      *(uint16_t *)((char *)cmidpakComOfs + 7),size);
      MIDHandle.seg = (uint16_t)in_DX;
      ovr_ovc20_compute1(cmidpakComOfs,cmidpakComSeg);
      handle.seg = ((uint16_t *)&musDriver0Seg)[unaff_SI * 2];
      handle.ofs = ((uint16_t *)&musDriver0Ofs)[unaff_SI * 2];
      MusGfxOfs = ovr_stshLoadGfx(handle);
      uVar3 = (uint16_t)
              ((ulong)*(uint32_t *)((uint16_t *)&musDriver0Ofs + unaff_SI * 2) >> 0x10);
      iVar2 = (int)*(uint32_t *)((uint16_t *)&musDriver0Ofs + unaff_SI * 2);
      MusGfxSeg = (uint16_t)in_DX;   /* hand fix: segment is 16-bit */
      MusHandle_07ca = audio_usesAlignToSeg
                            ((uint8_t *)CONCAT22(*(uint16_t *)(iVar2 + 5),in_DX),
                             *(uint16_t *)(iVar2 + 7),size);
      MusHandleSeg_07cc = (uint16_t)in_DX;   /* hand fix: segment is 16-bit */
      ovr_ovc20_compute1((char *)((uint16_t *)&musDriver0Ofs)[unaff_SI * 2],
                         ((uint16_t *)&musDriver0Seg)[unaff_SI * 2]);
      handle_00.seg = midpakAd.seg;
      handle_00.ofs = midpakAd.ofs;
      MusDrvOfs = ovr_stshLoadGfx(handle_00);
      MusDrvSeg = (uint16_t)in_DX;   /* hand fix: segment is 16-bit */
      ovr_ovc20_compute1((char *)midpakAd.ofs,midpakAd.seg);
      bVar1 = audio_init(MIDHandle.seg);
      if (CONCAT11(extraout_AH_00,bVar1) == 0) {
        MIDHandle.seg = 0;
        MIDHandle.ofs = 0;
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0x82);
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

int __cdecl16far audio_panFromX(agnt_t far *agnt,uint16_t arg2)

{
  uint uVar1;
  uint16_t in_stack_00000006;
  
  uVar1 = (uint)(((long)(int)agnt->x * 0x7f & 0xffffU) / 0xd2);
  if (0x7f < uVar1) {
    uVar1 = 0x7f;
  }
  return 0x7f - uVar1;
}


