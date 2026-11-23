/*
 * ovc30_waves.c - recovered from STRONG.EXE
 * memory block: OVC30_waves.c
 * range: 619c:0000 - 619c:0baf
 * functions: 7
 */
#include "recovered.h"


/* 619c:0000 */

/* Derives a 1..10 factor from the Difficulty setting (60 / difficulty, default 10). */

uint __cdecl16far ovc30_difficultyFactor(void)

{
  uint uVar1;
  
  if (*(char *)(Difficulty + 0x5de4) == '\0') {
    uVar1 = 10;
  }
  else {
    uVar1 = (uint)(0x3c / (ulong)(long)(int)(uint)*(byte *)(Difficulty + 0x5de4));
    if (uVar1 == 0) {
      uVar1 = 1;
    }
    if (9 < uVar1) {
      uVar1 = 10;
    }
  }
  return uVar1;
}



/* 619c:004e */

/* Advances the player index, spawns the next enemy wave and reports it. */

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
                (byte)ovr_randBelow((byte)lowIntelEnemies[Difficulty] + 1,0);
      while (pending != '\0') {
        pending = pending - 1;
        ovc30_textDivideError((byte)ovc30_usesRandBelow(0),1,1,0x19,0,0);
      }
      pending = enemyBaseMed[Difficulty] +
                (byte)ovr_randBelow((byte)lowIntelEnemies[Difficulty] + 1,0);
      while (pending != '\0') {
        pending = pending - 1;
        ovc30_textDivideError((byte)ovc30_usesRandBelow(1),1,1,0x19,0,0);
      }
      pending = enemyBaseHigh[Difficulty] +
                (byte)ovr_randBelow((byte)highIntelEnemies[Difficulty] + 1,0);
      while (pending != '\0') {
        pending = pending - 1;
        ovc30_textDivideError((byte)ovc30_usesRandBelow(2),1,1,0,0,0);
      }
    }
    else {
      pending = enemyBaseWave[Difficulty];
      while (pending != '\0') {
        pending = pending - 1;
        ovc30_textDivideError((byte)ovc30_usesRandBelow(3),1,1,0,0,0);
      }
      if (1 < Difficulty) {
        ovc30_textDivideError((byte)ovc30_usesRandBelow(4),1,1,0,0,0);
      }
      if ((flags & 1) != 0) {
        ovr_uiNotify((char far *)s_all_enemies_destroyed,0xa000,0);
        ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x36));
      }
      line = ((stsprintf_far_t *)ovr_stsprintf)
                 (msg,(char far *)s_next_wave_of_enemies_appear,PlayerIndex + 1);
      ovr_uiNotify(line,0xa000,0);
      ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x36));
    }
    if ((flags & 2) == 0) {
      ovr_constr_usesBlitRect();
    }
  }
  return;
}



/* 619c:025d */

/* [R4] calls ovr_randBelow */

uint16_t __cdecl16far ovc30_usesRandBelow(byte band)

{
  uint16_t uVar1;
  uint16_t uVar2;
  uint8_t bandMax;
  byte abStack_8 [2];
  uint8_t bandMin;
  byte abStack_4 [2];
  
  memcpy(&abStack_4, &((*(uint16_t *)((uint8_t *)&(LevelBandMin) + 2))), 2);
  bandMin = (*(uint16_t *)((uint8_t *)&(LevelBandMin)));
  memcpy(&abStack_8, &((*(uint16_t *)((uint8_t *)&(LevelBandMax) + 2))), 2);
  bandMax = (*(uint16_t *)((uint8_t *)&(LevelBandMax)));
  if (band == 4) {
    uVar1 = CONCAT11(SUB21((*(uint16_t *)((uint8_t *)&(LevelBandMax) + 2)),1),0x29);
  }
  else {
    do {
      do {
        uVar2 = ovr_randBelow(0x2a,0);
      } while ((char)uVar2 == ')');
    } while (((*(char *)((int)(char **)GMenuStrings + (uVar2 & 0xff) * 0x95 + 0x1f) == '\0') ||
             (*(byte *)((int)&worldMenuLabels[0xc].seg + (uVar2 & 0xff) * 0x95) < (&bandMin)[band]))
            || ((&bandMax)[band] < *(byte *)((int)&worldMenuLabels[0xc].seg + (uVar2 & 0xff) * 0x95)
               ));
    uVar1 = CONCAT11((char)((uint)(&bandMax + band) >> 8),(char)uVar2);
  }
  return uVar1;
}



/* 619c:031d */

/* [R7] body shape: compute */

undefined1 __cdecl16far ovc30_compute1(byte level)

{
  undefined1 uVar1;
  
  if (level < 5) {
    uVar1 = 0;
  }
  else if (level < 9) {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}



/* 619c:0339 */
uint __cdecl16far ovc30_createLeader(byte gindex,uint16_t x,uint16_t y)

{
  uint16_t uVar1;
  uint uVar2;
  uint16_t uVar3;
  far_t far *pfVar4;
  uint in_DX;
  byte partyIndex;
  uint count;
  char_sheet_t *pcStack_6;
  uint uStack_4;
  
  count = 0;
  while ((count < GLeaderCount && (((char_sheet_t *)((count << 2)))->statMask != '\0'))) {
    count = count + 1;
  }
  if (count < GLeaderCount) {
    uStack_4 = ((uint16_t *)(count * 4))[1];
    pcStack_6 = (char_sheet_t *)*(uint16_t *)(count * 4);
  }
  else {
    if (0x4f < GLeaderCount) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x21);
    }
    if (!GameRunning) {
      ovr_fmFreeAudio(1);
    }
    pcStack_6 = ovr_stshAlloc(0xae);
    count = (uint)GLeaderCount;
    uVar2 = (uint)GLeaderCount;
    ((uint16_t *)(uVar2 * 4))[1] = in_DX;
    *(uint16_t *)(uVar2 * 4) = (uint16_t)pcStack_6;   /* hand fix: store of the far pointer's offset half */
    GLeaderCount = GLeaderCount + 1;
    uStack_4 = in_DX;
  }
  _fmemset(MK_FP(uStack_4, (uint16_t)pcStack_6), 0, 0xae);
  partyIndex = (byte)count;
  uVar1 = *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + (uint)gindex * 0x95);
  strcpy((char *)CONCAT22(uStack_4,pcStack_6),
         (char *)CONCAT13((char)((uint)uVar1 >> 8),
                          CONCAT12((char)uVar1,
                                   *(uint16_t *)
                                    ((int)&worldMenuLabels[0].seg + 1 + (uint)gindex * 0x95))));
  pcStack_6->active = 1;
  pcStack_6->x = x;
  pcStack_6->y = y;
  pcStack_6->classStr = gindex;
  pcStack_6->cls = 0xff;
  pcStack_6->race = 3;
  uVar3 = ovr_randBelow(1,0);
  pcStack_6->gender = (byte)uVar3;
  ovr_manage_rollStats(pcStack_6,(char)uStack_4);
  if (*(char *)((int)&worldMenuLabels[0xc].seg + (uint)gindex * 0x95) != -1) {
    pcStack_6->stats[1] = *(byte *)((int)&worldMenuLabels[0xc].seg + (uint)gindex * 0x95);
  }
  if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)gindex * 0x95) & 0x800) != 0) {
    pcStack_6->stats[4] = 0x12;
  }
  pcStack_6->faction = *(uint8_t *)((int)(char **)GMenuStrings + (uint)gindex * 0x95 + 0x1f);
  pcStack_6->alignment = *(byte *)((int)(far_t far *)(worldMenuLabels + 9) + (uint)gindex * 0x95);
  pcStack_6->hp[0] = *(byte *)((int)&worldMenuLabels[6].seg + (uint)gindex * 0x95);
  pcStack_6->hp[1] = pcStack_6->hp[0];
  pcStack_6->statMask = pcStack_6->statMask | 0x16;
  pcStack_6->spyReports = 0x1;
  *(uint16_t *)((int)&pcStack_6->gold + 2) = 0;
  *(uint16_t *)&pcStack_6->gold = 100;
  pcStack_6->partySlot = 0xff;
  pfVar4 = ovr_ovc22_textRingProt(partyIndex);
  return CONCAT11((char)((uint)pfVar4 >> 8),partyIndex);
}


/* 619c:05a5 */

/* [R2] string "Divide error\r\n" */

byte __cdecl16far ovc30_textDivideError(byte gindex,int frames,char mode,byte percent,uint16_t arg5,uint16_t arg6)

{
  byte *pbVar1;
  uint32_t uVar2;
  bool bVar3;
  int iVar4;
  uint16_t uVar5;
  uint uVar6;
  uint uVar7;
  uint16_t uVar8;
  uint uVar9;
  uint uVar10;
  byte retries;
  byte leaderIndex;
  int maxDist;
  uint16_t spawnY;
  int maxBound;
  int minBound;
  int tries;
  int count;
  
  tries = 1;
  leaderIndex = 0xff;
  iVar4 = ovr_ovc25_compute1(gindex);
  maxDist = iVar4 * 3 + 0xf;
  if (0x31 < maxDist) {
    maxDist = 0x32;
  }
  do {
    if (frames == 0) {
      return leaderIndex;
    }
    if (mode == '\x02') {
      spawnY = demoCenterY;
      mode = '\x01';
      uVar8 = demoCenterX;
    }
    else if (mode == '\0') {
      minBound = demoCenterX + tries * -8;
      maxBound = demoCenterX + tries * 8;
      if (minBound < 8) {
        minBound = 8;
      }
      if (0x8c < maxBound) {
        maxBound = 0x8c;
      }
      uVar8 = ovr_randBelow((maxBound - minBound) + 1,0);
      uVar8 = (uVar8 & 0xff) + minBound & 0xfffc;
      minBound = demoCenterY + tries * -4;
      maxBound = demoCenterY + tries * 4;
      if (minBound < 8) {
        minBound = 8;
      }
      if (0x34 < maxBound) {
        maxBound = 0x34;
      }
      uVar5 = ovr_randBelow((maxBound - minBound) + 1,0);
      spawnY = (uVar5 & 0xff) + minBound;
    }
    else {
      retries = 0;
      do {
        bVar3 = false;
        uVar8 = ovr_randBelow(0x8c,0);
        uVar8 = (uVar8 & 0xff) + 4 & 0xfffc;
        spawnY = ovr_randBelow(0x3a,0);
        spawnY = spawnY & 0xff;
        for (iVar4 = 0; iVar4 < (int)(uint)GLeaderCount; iVar4 = iVar4 + 1) {
          if (((((char_sheet_t *)((iVar4 << 2)))->active != '\0') &&
              (*(char *)((int)*(uint32_t *)(iVar4 << 2) + 0x3f) != '\0')) &&
             (uVar6 = ((char_sheet_t *)((iVar4 << 2)))->x - uVar8,
             uVar9 = (int)uVar6 >> 0xf,
             uVar7 = ((char_sheet_t *)((iVar4 << 2)))->y - spawnY,
             uVar10 = (int)uVar7 >> 0xf,
             (int)((int)((uVar6 ^ uVar9) - uVar9) / 2 + ((uVar7 ^ uVar10) - uVar10)) < 10)) {
            bVar3 = true;
            retries = retries + 1;
            break;
          }
          if (((((char_sheet_t *)((iVar4 << 2)))->active != '\0') &&
              (*(char *)((int)*(uint32_t *)(iVar4 << 2) + 0x3f) == '\0')) &&
             (uVar6 = ((char_sheet_t *)((iVar4 << 2)))->x - uVar8,
             uVar9 = (int)uVar6 >> 0xf,
             uVar7 = ((char_sheet_t *)((iVar4 << 2)))->y - spawnY,
             uVar10 = (int)uVar7 >> 0xf,
             (int)((int)((uVar6 ^ uVar9) - uVar9) / 2 + ((uVar7 ^ uVar10) - uVar10)) < maxDist)) {
            bVar3 = true;
            retries = retries + 1;
            break;
          }
        }
      } while ((bVar3) && (retries < 100));
    }
    uVar6 = ovr_constr_usesGMapFlags(uVar8 - 1,spawnY,0);
    if ((((char)uVar6 == '\0') ||
        (uVar6 = ovr_constr_usesGMapFlags(uVar8,spawnY,0), (char)uVar6 == '\0')) ||
       (bVar3 = ovr_ovc18_textArena(uVar8,spawnY), bVar3)) {
      tries = tries + 1;
      if (500 < tries) {
        return leaderIndex;
      }
    }
    else {
      uVar6 = ovc30_createLeader(gindex,uVar8,spawnY);
      leaderIndex = (byte)uVar6;
      if (1 < PlayerIndex) {
        uVar2 = *(uint32_t *)((uVar6 & 0xff) << 2);
        pbVar1 = (byte *)((int)uVar2 + 0x5d);
        *pbVar1 = *pbVar1 | 0x10;
      }
      if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)gindex * 0x95) & 0x800) == 0) {
        if (PlayerIndex < 2) {
          uVar2 = *(uint32_t *)((uVar6 & 0xff) << 2);
          ovr_ovc15_usesLDIV_at_
                    (uVar8,spawnY,uVar8,spawnY,gindex,*(uint8_t *)((int)uVar2 + 0xa4),leaderIndex,0,0,0,0)
          ;
        }
        else {
          for (count = 0; uVar7 = ovc30_difficultyFactor(), count < (int)(uVar7 & 0xff);
              count = count + 1) {
            ovr_ovc15_usesLDIV_at_(uVar8,spawnY,uVar8,spawnY,gindex,0xa,leaderIndex,0,0,0,0);
          }
        }
      }
      else {
        ovr_ovc15_usesLDIV_at_(uVar8,spawnY,uVar8,spawnY,gindex,0x1,leaderIndex,0,0,0,0);
        for (count = 0; uVar7 = ovc30_difficultyFactor(), iVar4 = (uVar7 & 0xff) * 2,
            iVar4 - count != 0 && count <= iVar4; count = count + 1) {
          ovr_ovc18_textTypeLen(leaderIndex,uVar8,spawnY,0x2,0,0);
        }
      }
      if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)gindex * 0x95) & 0x1000) != 0) {
        ovc30_usesRandBelow2(uVar8,spawnY,0);
      }
      uVar2 = *(uint32_t *)((uVar6 & 0xff) << 2);
      *(undefined1 *)((int)uVar2 + 0x5a) = 0;
      ((short (*) [148] [60])GUnitGrid)[-1][uVar8 + 0x93][spawnY] =
           (uint)*(byte *)((int)(far_t *)(worldMenuLabels + 0xb) + (uint)gindex * 0x95);
      ovr_ovc23_placeBuilding
                (uVar8 - 1,spawnY,
                 *(byte *)(((short (*) [148] [60])GUnitGrid)[-1][uVar8 + 0x93] + spawnY),leaderIndex
                );
      ovr_ovc23_placeBuilding(uVar8,spawnY,0,leaderIndex);
      (*(short (*) [148] [60])GUnitGrid)[uVar8][spawnY] = 0;
      frames = frames + -1;
      demoCenterY = spawnY;
      demoCenterX = uVar8;
      uVar8 = ovr_randBelow(100,0);
      mode = (byte)uVar8 < percent;
      tries = 0;
    }
  } while( true );
}



/* 619c:0a5e */

/* [R4] calls ovr_randBelow */

void __cdecl16far ovc30_usesRandBelow2(int centerX,int centerY,uint16_t arg3)

{
  uint16_t uVar1;
  uint uVar2;
  int iVar3;
  int iStack_6;
  
  for (iStack_6 = -0xc; iStack_6 < 0xd; iStack_6 = iStack_6 + 1) {
    for (iVar3 = -8; iVar3 < 9; iVar3 = iVar3 + 1) {
      uVar1 = ovr_randBelow(2,0);
      if ((uVar1 & 0xff) == 0) {
        uVar2 = ovr_ovc45_compute4(centerX + iStack_6,centerY + iVar3,0);
        if ((char)uVar2 != '\0') {
          uVar1 = ovr_randBelow(9,0);
          (*(short (*) [148] [60])GUnitGrid)[centerX + iStack_6][centerY + iVar3] =
               (uVar1 & 0xff) + 0xef;
        }
      }
    }
  }
  return;
}


