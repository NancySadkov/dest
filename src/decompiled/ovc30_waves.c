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
  uint factor;
  
  if (*(char *)(Difficulty + 0x5de4) == '\0') {
    factor = 10;
  }
  else {
    factor = (uint)(0x3c / (ulong)(long)(int)(uint)*(byte *)(Difficulty + 0x5de4));
    if (factor == 0) {
      factor = 1;
    }
    if (9 < factor) {
      factor = 10;
    }
  }
  return factor;
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
  uint16_t packed;
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
    packed = CONCAT11(SUB21((*(uint16_t *)((uint8_t *)&(LevelBandMax) + 2)),1),0x29);
  }
  else {
    do {
      do {
        uVar2 = ovr_randBelow(0x2a,0);
      } while ((char)uVar2 == ')');
    } while (((AgntGs[(uVar2 & 0xff)].ai == '\0') ||
             (*(byte *)((int)&worldMenuLabels[0xc].seg + (uVar2 & 0xff) * 0x95) < (&bandMin)[band]))
            || ((&bandMax)[band] < *(byte *)((int)&worldMenuLabels[0xc].seg + (uVar2 & 0xff) * 0x95)
               ));
    packed = CONCAT11((char)((uint)(&bandMax + band) >> 8),(char)uVar2);
  }
  return packed;
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
  char_sheet_t *sheet;
  uint uStack_4;
  
  count = 0;
  while ((count < GLeaderCount && ((GLeaderSheets[count])->statMask != '\0'))) {
    count = count + 1;
  }
  if (count < GLeaderCount) {
    uStack_4 = ((uint16_t *)(count * 4))[1];
    sheet = (char_sheet_t *)*(uint16_t *)(count * 4);
  }
  else {
    if (0x4f < GLeaderCount) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x21);
    }
    if (!GameRunning) {
      ovr_fmFreeAudio(1);
    }
    sheet = ovr_stshAlloc(0xae);
    count = (uint)GLeaderCount;
    uVar2 = (uint)GLeaderCount;
    ((uint16_t *)(uVar2 * 4))[1] = in_DX;
    *(uint16_t *)(uVar2 * 4) = (uint16_t)sheet;   /* hand fix: store of the far pointer's offset half */
    GLeaderCount = GLeaderCount + 1;
    uStack_4 = in_DX;
  }
  _fmemset(MK_FP(uStack_4, (uint16_t)sheet), 0, 0xae);
  partyIndex = (byte)count;
  uVar1 = *(uint16_t *)((int)&worldMenuLabels[1].ofs + 1 + (uint)gindex * 0x95);
  strcpy((char *)CONCAT22(uStack_4,sheet),
         (char *)CONCAT13((char)((uint)uVar1 >> 8),
                          CONCAT12((char)uVar1,
                                   *(uint16_t *)
                                    ((int)&worldMenuLabels[0].seg + 1 + (uint)gindex * 0x95))));
  sheet->active = 1;
  sheet->x = x;
  sheet->y = y;
  sheet->classStr = gindex;
  sheet->cls = 0xff;
  sheet->race = 3;
  uVar3 = ovr_randBelow(1,0);
  sheet->gender = (byte)uVar3;
  ovr_manage_rollStats(sheet,(char)uStack_4);
  if (*(char *)((int)&worldMenuLabels[0xc].seg + (uint)gindex * 0x95) != -1) {
    sheet->stats[1] = *(byte *)((int)&worldMenuLabels[0xc].seg + (uint)gindex * 0x95);
  }
  if ((AgntGs[(uint)gindex].flags3 & 0x800) != 0) {
    sheet->stats[4] = 0x12;
  }
  sheet->faction = AgntGs[(uint)gindex].ai;
  sheet->alignment = *(byte *)((int)(far_t far *)(worldMenuLabels + 9) + (uint)gindex * 0x95);
  sheet->hp[0] = AgntGs[(uint)gindex].strength;
  sheet->hp[1] = sheet->hp[0];
  sheet->statMask = sheet->statMask | 0x16;
  sheet->spyReports = 0x1;
  *(uint16_t *)((int)&sheet->gold + 2) = 0;
  *(uint16_t *)&sheet->gold = 100;
  sheet->partySlot = 0xff;
  pfVar4 = ovr_ovc22_textRingProt(partyIndex);
  return CONCAT11((char)((uint)pfVar4 >> 8),partyIndex);
}


/* 619c:05a5 */

/* [R2] string "Divide error\r\n" */

byte __cdecl16far ovc30_textDivideError(byte gindex,int frames,char mode,byte percent,uint16_t arg5,uint16_t arg6)

{
  byte *flagsByte;
  uint32_t sheet;
  bool rejected;
  bool inArena;
  int baseDist;
  int scanIdx;
  int twiceFactor;
  uint16_t yRoll;
  uint dx;
  uint mapOk;
  uint newLeader;
  uint dy;
  uint factor;
  uint16_t spawnX;
  uint16_t roll;
  uint dxSign;
  uint dySign;
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
  baseDist = ovr_ovc25_compute1(gindex);
  maxDist = baseDist * 3 + 0xf;
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
      spawnX = demoCenterX;
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
      spawnX = ovr_randBelow((maxBound - minBound) + 1,0);
      spawnX = (spawnX & 0xff) + minBound & 0xfffc;
      minBound = demoCenterY + tries * -4;
      maxBound = demoCenterY + tries * 4;
      if (minBound < 8) {
        minBound = 8;
      }
      if (0x34 < maxBound) {
        maxBound = 0x34;
      }
      yRoll = ovr_randBelow((maxBound - minBound) + 1,0);
      spawnY = (yRoll & 0xff) + minBound;
    }
    else {
      retries = 0;
      do {
        rejected = false;
        spawnX = ovr_randBelow(0x8c,0);
        spawnX = (spawnX & 0xff) + 4 & 0xfffc;
        spawnY = ovr_randBelow(0x3a,0);
        spawnY = spawnY & 0xff;
        for (scanIdx = 0; scanIdx < (int)(uint)GLeaderCount; scanIdx = scanIdx + 1) {
          if ((((GLeaderSheets[scanIdx])->active != '\0') &&
              (*((char far *)GLeaderSheets[scanIdx] + 0x3f) != '\0')) &&
             (dx = (GLeaderSheets[scanIdx])->x - spawnX,
             dxSign = (int)dx >> 0xf,
             dy = (GLeaderSheets[scanIdx])->y - spawnY,
             dySign = (int)dy >> 0xf,
             (int)((int)((dx ^ dxSign) - dxSign) / 2 + ((dy ^ dySign) - dySign)) < 10)) {
            rejected = true;
            retries = retries + 1;
            break;
          }
          if ((((GLeaderSheets[scanIdx])->active != '\0') &&
              (*((char far *)GLeaderSheets[scanIdx] + 0x3f) == '\0')) &&
             (dx = (GLeaderSheets[scanIdx])->x - spawnX,
             dxSign = (int)dx >> 0xf,
             dy = (GLeaderSheets[scanIdx])->y - spawnY,
             dySign = (int)dy >> 0xf,
             (int)((int)((dx ^ dxSign) - dxSign) / 2 + ((dy ^ dySign) - dySign)) < maxDist)) {
            rejected = true;
            retries = retries + 1;
            break;
          }
        }
      } while ((rejected) && (retries < 100));
    }
    mapOk = ovr_constr_usesGMapFlags(spawnX - 1,spawnY,0);
    if ((((char)mapOk == '\0') ||
        (mapOk = ovr_constr_usesGMapFlags(spawnX,spawnY,0), (char)mapOk == '\0')) ||
       (inArena = ovr_ovc18_textArena(spawnX,spawnY), inArena)) {
      tries = tries + 1;
      if (500 < tries) {
        return leaderIndex;
      }
    }
    else {
      newLeader = ovc30_createLeader(gindex,spawnX,spawnY);
      leaderIndex = (byte)newLeader;
      if (1 < PlayerIndex) {
        sheet = *(uint32_t *)((newLeader & 0xff) << 2);
        flagsByte = (byte *)((int)sheet + 0x5d);
        *flagsByte = *flagsByte | 0x10;
      }
      if ((AgntGs[(uint)gindex].flags3 & 0x800) == 0) {
        if (PlayerIndex < 2) {
          sheet = *(uint32_t *)((newLeader & 0xff) << 2);
          ovr_ovc15_usesLDIV_at_
                    (spawnX,spawnY,spawnX,spawnY,gindex,*(uint8_t *)((int)sheet + 0xa4),leaderIndex,0,0,0,0)
          ;
        }
        else {
          for (count = 0; factor = ovc30_difficultyFactor(), count < (int)(factor & 0xff);
              count = count + 1) {
            ovr_ovc15_usesLDIV_at_(spawnX,spawnY,spawnX,spawnY,gindex,0xa,leaderIndex,0,0,0,0);
          }
        }
      }
      else {
        ovr_ovc15_usesLDIV_at_(spawnX,spawnY,spawnX,spawnY,gindex,0x1,leaderIndex,0,0,0,0);
        for (count = 0; factor = ovc30_difficultyFactor(), twiceFactor = (factor & 0xff) * 2,
            twiceFactor - count != 0 && count <= twiceFactor; count = count + 1) {
          ovr_ovc18_textTypeLen(leaderIndex,spawnX,spawnY,0x2,0,0);
        }
      }
      if ((AgntGs[(uint)gindex].flags3 & 0x1000) != 0) {
        ovc30_usesRandBelow2(spawnX,spawnY,0);
      }
      sheet = *(uint32_t *)((newLeader & 0xff) << 2);
      *(undefined1 *)((int)sheet + 0x5a) = 0;
      ((short (*) [148] [60])GUnitGrid)[-1][spawnX + 0x93][spawnY] =
           (uint)*(byte *)((int)(far_t *)(worldMenuLabels + 0xb) + (uint)gindex * 0x95);
      ovr_ovc23_placeBuilding
                (spawnX - 1,spawnY,
                 *(byte *)(((short (*) [148] [60])GUnitGrid)[-1][spawnX + 0x93] + spawnY),leaderIndex
                );
      ovr_ovc23_placeBuilding(spawnX,spawnY,0,leaderIndex);
      (*(short (*) [148] [60])GUnitGrid)[spawnX][spawnY] = 0;
      frames = frames + -1;
      demoCenterY = spawnY;
      demoCenterX = spawnX;
      roll = ovr_randBelow(100,0);
      mode = (byte)roll < percent;
      tries = 0;
    }
  } while( true );
}



/* 619c:0a5e */

/* [R4] calls ovr_randBelow */

void __cdecl16far ovc30_usesRandBelow2(int centerX,int centerY,uint16_t arg3)

{
  uint16_t randPick;
  uint uVar2;
  int iVar3;
  int iStack_6;
  
  for (iStack_6 = -0xc; iStack_6 < 0xd; iStack_6 = iStack_6 + 1) {
    for (iVar3 = -8; iVar3 < 9; iVar3 = iVar3 + 1) {
      randPick = ovr_randBelow(2,0);
      if ((randPick & 0xff) == 0) {
        uVar2 = ovr_ovc45_compute4(centerX + iStack_6,centerY + iVar3,0);
        if ((char)uVar2 != '\0') {
          randPick = ovr_randBelow(9,0);
          (*(short (*) [148] [60])GUnitGrid)[centerX + iStack_6][centerY + iVar3] =
               (randPick & 0xff) + 0xef;
        }
      }
    }
  }
  return;
}


