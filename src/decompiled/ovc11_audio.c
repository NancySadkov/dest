/*
 * ovc11_audio.c - recovered from STRONG.EXE
 * memory block: OVC11_audio.c
 * range: 3a5b:0000 - 3a5b:0c1f
 * functions: 13
 */
#include "recovered.h"


/* 3a5b:0000 */

/* WARNING: Removing unreachable block (ram,0x0003a69a) */

void __cdecl16far audio_3a5b_0000(void)

{
  char cVar1;
  bool bVar2;
  uint16_t uVar3;
  undefined2 uVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  uint8_t uStack_3;
  
  if (GameRunning) {
    cVar1 = audio_3a5b_034e();
    if (cVar1 == '\0') {
      GameRunning = false;
      play_sfx(46,0);
      GameRunning = true;
    }
  }
  else {
    if (((MusRunning != '\0') && (DAT_2410_07a6 != 0xff)) &&
       (cVar1 = audio_3a5b_034e(), cVar1 == '\0')) {
      play_sfx((uint)DAT_2410_07a6,0);
    }
    if (((SfxRunning != '\0') && (CurSfxType3 != 0xff)) && (bVar2 = ovr_digSoundPlaying(), !bVar2))
    {
      uVar4 = 0;
      uStack_3 = CurSfxType3;
      if (CurSfxType3 == 0x80) {
        uVar3 = ovr_randBelow(3);
        uStack_3 = (char)uVar3 + 0x80;
        uVar4 = CONCAT11((char)(uVar3 >> 8),uStack_3);
      }
      else if (CurSfxType3 == 0x83) {
        uVar3 = ovr_randBelow(3);
        uStack_3 = (char)uVar3 + 0x83;
        uVar4 = CONCAT11((char)(uVar3 >> 8),uStack_3);
      }
      else if (CurSfxType3 == 0x76) {
        uVar6 = ovr_attact_3f0b_082f(CONCAT22(DAT_2410_07b0,DAT_2410_07ae));
        if (((int)(uVar6 >> 0x10) == 0) && ((uint)uVar6 < DAT_2410_07b2)) {
          return;
        }
        uVar3 = ovr_randBelow(4);
        uStack_3 = (char)uVar3 + 0x76;
        lVar7 = 0x8000;
        iVar5 = rand();
        lVar7 = LDIV_at_(CONCAT22((iVar5 >> 0xf) << 1 | (uint)(iVar5 < 0),iVar5 << 1),lVar7);
        if ((int)lVar7 == 0) {
          DAT_2410_07b2 = 0;
        }
        else {
          uVar3 = ovr_randBelow(0x48);
          DAT_2410_07b2 = (uVar3 & 0xff) + 0x80;
        }
        uVar4 = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs + 2);
        DAT_2410_07ae = *(undefined2 far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
        DAT_2410_07b0 = uVar4;
      }
      else if (CurSfxType3 == 0x70) {
        uVar3 = ovr_randBelow(3);
        uStack_3 = (char)uVar3 + 0x70;
        uVar4 = CONCAT11((char)(uVar3 >> 8),uStack_3);
      }
      else if (CurSfxType3 == 0x86) {
        uVar3 = ovr_randBelow(3);
        uStack_3 = (char)uVar3 + 0x86;
        uVar4 = CONCAT11((char)(uVar3 >> 8),uStack_3);
      }
      else if (CurSfxType3 == 0x7a) {
        uVar3 = ovr_randBelow(3);
        uStack_3 = (char)uVar3 + 0x7a;
        uVar4 = CONCAT11((char)(uVar3 >> 8),uStack_3);
      }
      else if (CurSfxType3 == 0x7d) {
        uVar3 = ovr_randBelow(3);
        uStack_3 = (char)uVar3 + 0x7d;
        uVar4 = CONCAT11((char)(uVar3 >> 8),uStack_3);
      }
      else if (CurSfxType3 == 0x6a) {
        uVar3 = ovr_randBelow(3);
        uStack_3 = (char)uVar3 + 0x6a;
        uVar4 = CONCAT11((char)(uVar3 >> 8),uStack_3);
      }
      else if (CurSfxType3 == 0x64) {
        uVar3 = ovr_randBelow(3);
        uStack_3 = (char)uVar3 + 0x64;
        uVar4 = CONCAT11((char)(uVar3 >> 8),uStack_3);
      }
      else if (CurSfxType3 == 0x67) {
        uVar3 = ovr_randBelow(3);
        uStack_3 = (char)uVar3 + 0x67;
        uVar4 = CONCAT11((char)(uVar3 >> 8),uStack_3);
      }
      else if (CurSfxType3 == 0x5e) {
        uVar3 = ovr_randBelow(3);
        uStack_3 = (char)uVar3 + 0x5e;
        uVar4 = CONCAT11((char)(uVar3 >> 8),uStack_3);
      }
      else if (CurSfxType3 == 0x61) {
        uVar3 = ovr_randBelow(6);
        uStack_3 = (char)uVar3 + 0x5e;
        uVar4 = CONCAT11((char)(uVar3 >> 8),uStack_3);
      }
      else if (CurSfxType3 == 0x73) {
        uVar3 = ovr_randBelow(6);
        uStack_3 = (char)uVar3 + 0x73;
        uVar4 = CONCAT11((char)(uVar3 >> 8),uStack_3);
      }
      else if (CurSfxType3 == 0x6f) {
        uVar3 = ovr_randBelow(3);
        uStack_3 = (char)uVar3 + 0x6d;
        uVar4 = CONCAT11((char)(uVar3 >> 8),uStack_3);
      }
      play_sfx(CONCAT11((char)((uint)uVar4 >> 8),uStack_3),4);
    }
  }
  return;
}



/* 3a5b:026f */

/* Frees audio buffers, when we are out of space.
   Returns true on success. */

bool __cdecl16far fmFreeAudio(uint16_t force)

{
  bool bVar1;
  int iVar2;
  far_t handle;
  far_t handle_00;
  bool result;
  
  result = false;
  if ((((SfxRunning != '\0') && (DIGHandle.ofs != 0 || DIGHandle.seg != 0)) &&
      (((char)force != '\0' || (bVar1 = ovr_digSoundPlaying(), !bVar1)))) && (DIG_2410_07a8 == '\0')
     ) {
    bVar1 = ovr_digSoundPlaying();
    if (bVar1) {
      ovr_digStopCurrentSound();
    }
    handle.seg = DIGHandle.seg;
    handle.ofs = DIGHandle.ofs;
    ovr_stshFree(handle);
    DIGHandle.seg = 0;
    DIGHandle.ofs = 0;
    result = true;
  }
  if (((MusRunning != '\0') && (MUSHandle.ofs != 0 || MUSHandle.seg != 0)) &&
     (MUS_2410_07a9 == '\0')) {
    if (((char)force == '\0') && (iVar2 = ovr_midGetSequenceStatus(), iVar2 == 1)) {
      return result;
    }
    iVar2 = ovr_midGetSequenceStatus();
    if (iVar2 == 1) {
      ovr_midMidiStop();
    }
    handle_00.seg = MUSHandle.seg;
    handle_00.ofs = MUSHandle.ofs;
    ovr_stshFree(handle_00);
    MUSHandle.seg = 0;
    MUSHandle.ofs = 0;
    result = true;
  }
  return result;
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

undefined2 __cdecl16far audio_3a5b_034e(void)

{
  bool bVar1;
  int iVar2;
  
  if ((SfxRunning != '\0') && (bVar1 = ovr_digSoundPlaying(), bVar1)) {
    return 1;
  }
  if ((MusRunning != '\0') && (iVar2 = ovr_midGetSequenceStatus(), iVar2 == 1)) {
    return 1;
  }
  return 0;
}



/* 3a5b:037e */

uint __cdecl16far audio_3a5b_037e(void)

{
  uint in_AX;
  
  if ((MusRunning != '\0') && (in_AX = ovr_midGetSequenceStatus(), in_AX == 1)) {
    return 1;
  }
  return in_AX & 0xff00;
}



/* 3a5b:039a */

void __cdecl16far play_sfxU(byte fid,int type,uint16_t unk)

{
  bool bVar1;
  uint16_t uVar2;
  uint16_t uVar3;
  char *pcStack_a;
  
  if ((!GameRunning) && (fid != 0xff)) {
    if ((0x89 < fid) || (*(int *)((uint)fid * 4) == 0 && ((int *)((uint)fid * 4))[1] == 0)) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x22);
    }
    if (*(int *)((uint)fid * 2 + 0x114) == 0) {
      audio_3a5b_0648(CONCAT11((char)((uint)fid * 2 >> 8),fid),type);
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
      DAT_2410_2a4e = 1;
      if (DIGHandle.ofs != 0 || DIGHandle.seg != 0) {
        ovr_stshFree(DIGHandle);
      }
      DIGHandle.ofs = 0;
      DIGHandle.seg = 0;
      uVar2 = 0x1703;
      DIGHandle.ofs = ovr_stash_474a_0e9b(*(undefined2 *)((uint)fid * 4));
      DIGHandle.seg = uVar2;
      DAT_2410_2a4e = 0;
      if (DIGHandle.ofs != 0 || uVar2 != 0) {
        if (((CFG_Sfx == '1') || (CFG_Sfx == '4')) || (CFG_Sfx == '9')) {
          pcStack_a = (char *)*(uint *)(DIGHandle.ofs + 5);
          if ((char *)" Bridges must be near water\'s edge." + 0x18 < pcStack_a) {
            pcStack_a = (char *)" Bridges must be near water\'s edge." + 0x18;
          }
        }
        else {
          pcStack_a = (char *)*(undefined2 *)(DIGHandle.ofs + 5);
        }
        DIGHandle = far_from_u32((uint32_t)(ovr_stshRealloc(CONCAT22(uVar2,DIGHandle.ofs),
                                           (uint32_t)
                                           CONCAT22((uint)((char *)0xfff1 < pcStack_a) -
                                                    (uint)(pcStack_a == (char *)0xfff2),
                                                    pcStack_a + 0xd))));
        uVar3 = DIGHandle.ofs;
        uVar2 = DIGHandle.seg;
        DIG_2410_07a8 = 0;
        *(uint16_t *)(uVar3 + 3) = uVar2;
        *(int *)(uVar3 + 1) = uVar3 + 0xd;
        uVar3 = DIGHandle.seg;
        uVar2 = DIGHandle.ofs;
        *(undefined2 *)(uVar2 + 9) = (char *)"puppetmaker" + 3;
        *(undefined2 *)(uVar2 + 7) = 0x8f92;
        *(undefined2 *)(DIGHandle.ofs + 5) = pcStack_a;
        ovr_digPreformatSound(DIGHandle.ofs + 1,DIGHandle.seg);
        ovr_digPlayPreformatedSound(DIGHandle.ofs + 1,DIGHandle.seg);
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

void __cdecl16far play_sfx(int16_t track,int16_t type)

{
  play_sfxU((byte)track,type,0x40);
  return;
}



/* 3a5b:0648 */

void __cdecl16far audio_3a5b_0648(byte param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint16_t uVar3;
  undefined2 unaff_SI;
  
  if (((MusRunning != '\0') && (AudioAssetsReady2 != '\0')) &&
     ((DAT_2410_07b5 == param_1 ||
      ((param_2 != 1 || (iVar2 = ovr_midGetSequenceStatus(), iVar2 != 1)))))) {
    do {
      if (param_2 != 2) break;
      iVar2 = ovr_midGetSequenceStatus();
    } while (iVar2 == 1);
    ovr_midMidiStop();
    DAT_2410_2a4e = 1;
    MUS_2410_07a9 = 1;
    if (MUSHandle.ofs != 0 || MUSHandle.seg != 0) {
      ovr_stshFree(MUSHandle);
    }
    MUSHandle.ofs = 0;
    MUSHandle.seg = 0;
    uVar3 = 0x1703;
    MUSHandle.ofs = ovr_stash_474a_0e9b(*(undefined2 *)((uint)param_1 * 4));
    MUSHandle.seg = uVar3;
    DAT_2410_2a4e = 0;
    if (MUSHandle.ofs != 0 || uVar3 != 0) {
      MUS_2410_07a9 = 0;
      cVar1 = ovr_midRegisterXMIDI(MUSHandle.ofs + 0xd,uVar3,*(undefined2 *)(MUSHandle.ofs + 5));
      if (cVar1 == '\0') {
        printf("Midi error\r",unaff_SI);
      }
      else {
        ovr_midSetRelativeValue(100);
        ovr_midPlaySequence(0);
      }
      DAT_2410_07b5 = param_1;
    }
  }
  return;
}



/* 3a5b:0761 */

uint16_t __cdecl16far audio_3a5b_0761(uint8_t *param_1,uint16_t param_2,int param_3)

{
  uint16_t uVar1;
  far_t fVar2;
  
  if (((uint)param_1 & 0xf) == 0) {
    fVar2.seg = param_2;
    fVar2.ofs = (uint16_t)param_1;
    fVar2 = ovr_alignToSeg(fVar2);
    uVar1 = fVar2.ofs;
  }
  else {
    _fmemmove((uint8_t *)((uint)param_1 & 0xfff0),param_1,param_3 + -0xf);
    fVar2 = ovr_alignToSeg(far_from_u32((uint32_t)((ulong)CONCAT22(param_2 + 1,param_1) & 0xfffffff0)));
    uVar1 = fVar2.ofs;
  }
  return uVar1;
}



/* 3a5b:07c2 */

void __cdecl16far audio_3a5b_07c2(int param_1,undefined2 param_2,char param_3)

{
  if (param_3 != '0') {
    if (*(char *)(param_1 + 0x108) != -1) {
      if ((((byte *)_ctype + 1)[param_3] & 2) == 0) {
        *(char *)(param_1 + 0x108) = param_3 + -0x37;
      }
      else {
        *(char *)(param_1 + 0x108) = param_3 + -0x30;
      }
      *(undefined1 *)(param_1 + 0x109) = 0;
    }
  }
  return;
}



/* 3a5b:081e */

void __cdecl16far sfxInit(void)

{
  bool bVar1;
  undefined1 extraout_AH;
  uint16_t uVar2;
  int unaff_SI;
  stg_tmp_t *psVar3;
  far_t handle;
  
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
    if (((undefined2 *)&DAT_2000_d0c8)[unaff_SI * 2] != 0 ||
        ((undefined2 *)&DAT_2000_d0ca)[unaff_SI * 2] != 0) {
      handle.seg = ((undefined2 *)&DAT_2000_d0ca)[unaff_SI * 2];
      handle.ofs = ((undefined2 *)&DAT_2000_d0c8)[unaff_SI * 2];
      psVar3 = ovr_stshLoadGfx(handle);
      uVar2 = (uint16_t)((ulong)psVar3 >> 0x10);
      DAT_2410_07b6 = (uint16_t)(psVar3);
      DAT_2410_07b8 = uVar2;
      DIGHandle.ofs =
           audio_3a5b_0761(psVar3,*(undefined2 *)
                                   ((int)*(undefined4 *)
                                          ((undefined2 *)&DAT_2000_d0c8 + unaff_SI * 2) + 5));
      DIGHandle.seg = uVar2;
      audio_3a5b_07c2(DIGHandle.ofs,uVar2);
      ovr_OVC20_4b0a_112d(((undefined2 *)&DAT_2000_d0c8)[unaff_SI * 2]);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far musInit(void)

{
  bool bVar1;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  uint16_t uVar2;
  undefined2 uVar3;
  int unaff_SI;
  stg_tmp_t *psVar4;
  far_t handle;
  far_t handle_00;
  
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
    if (((undefined2 *)&DAT_2000_d09c)[unaff_SI * 2] != 0 ||
        ((undefined2 *)&DAT_2000_d09e)[unaff_SI * 2] != 0) {
      psVar4 = ovr_stshLoadGfx(DAT_2000_d094);
      uVar2 = (uint16_t)((ulong)psVar4 >> 0x10);
      DAT_2410_07be = (uint16_t)(psVar4);
      DAT_2410_07c0 = uVar2;
      MIDHandle.ofs = audio_3a5b_0761(psVar4,*(undefined2 *)(DAT_2000_d094 + 5));
      MIDHandle.seg = uVar2;
      ovr_OVC20_4b0a_112d(DAT_2000_d094);
      handle.seg = ((undefined2 *)&DAT_2000_d09e)[unaff_SI * 2];
      handle.ofs = ((undefined2 *)&DAT_2000_d09c)[unaff_SI * 2];
      psVar4 = ovr_stshLoadGfx(handle);
      uVar3 = (undefined2)((ulong)psVar4 >> 0x10);
      DAT_2410_07c6 = (uint16_t)(psVar4);
      DAT_2410_07c8 = uVar3;
      DAT_2410_07ca =
           audio_3a5b_0761(psVar4,*(undefined2 *)
                                   ((int)*(undefined4 *)
                                          ((undefined2 *)&DAT_2000_d09c + unaff_SI * 2) + 5));
      DAT_2410_07cc = uVar3;
      ovr_OVC20_4b0a_112d(((undefined2 *)&DAT_2000_d09c)[unaff_SI * 2]);
      handle_00.seg = far_t_2000_d098.seg;
      handle_00.ofs = far_t_2000_d098.ofs;
      psVar4 = ovr_stshLoadGfx(handle_00);
      DAT_2410_07d0 = (undefined2)((ulong)psVar4 >> 0x10);
      DAT_2410_07ce = (uint16_t)(psVar4);
      ovr_OVC20_4b0a_112d(far_t_2000_d098.ofs);
      bVar1 = audio_init(MIDHandle.seg);
      if (CONCAT11(extraout_AH_00,bVar1) == 0) {
        MIDHandle.seg = 0;
        MIDHandle.ofs = 0;
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0x82);
      }
      ovr_midLoadDriver(DAT_2410_07ca,DAT_2410_07cc,DAT_2410_07ce,DAT_2410_07d0);
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

int __cdecl16far audio_3a5b_0afd(int *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)(((long)*param_1 * 0x7f & 0xffffU) / 0xd2);
  if (0x7f < uVar1) {
    uVar1 = 0x7f;
  }
  return 0x7f - uVar1;
}


