/*
 * ovc30.c - recovered from STRONG.EXE
 * memory block: OVC30
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

void __cdecl16far ovc30_nextWave(byte flags)

{
  uint16_t uVar1;
  undefined2 uVar2;
  char *msg;
  uint16_t in_DX;
  char *unaff_SS;
  int iVar3;
  char cVar5;
  undefined4 uVar4;
  uint8_t text;
  char cStack_3;
  
  if (PlayerIndex < 2) {
    PlayerIndex = PlayerIndex + 1;
    if (PlayerIndex == 1) {
      cVar5 = *(char *)(Difficulty + 0x5dcb);
      uVar1 = ovr_randBelow((byte)((undefined1 *)&lowIntelEnemies)[Difficulty] + 1);
      cStack_3 = cVar5 + (char)uVar1;
      while (cStack_3 != '\0') {
        uVar4 = 0x190001;
        iVar3 = 1;
        cStack_3 = cStack_3 + -1;
        uVar2 = ovc30_usesRandBelow(0);
        ovc30_textDivideError((byte)uVar2,iVar3,(char)uVar4,(byte)((ulong)uVar4 >> 0x10));
      }
      cVar5 = *(char *)(Difficulty + 0x5dd3);
      cStack_3 = cStack_3 + -1;
      uVar1 = ovr_randBelow((byte)((undefined1 *)&lowIntelEnemies)[Difficulty] + 1);
      cStack_3 = cVar5 + (char)uVar1;
      while (cStack_3 != '\0') {
        uVar4 = 0x190001;
        iVar3 = 1;
        cStack_3 = cStack_3 + -1;
        uVar2 = ovc30_usesRandBelow(1);
        ovc30_textDivideError((byte)uVar2,iVar3,(char)uVar4,(byte)((ulong)uVar4 >> 0x10));
      }
      cVar5 = *(char *)(Difficulty + 0x5ddb);
      cStack_3 = cStack_3 + -1;
      uVar1 = ovr_randBelow((byte)((undefined1 *)&highIntelEnemies)[Difficulty] + 1);
      cStack_3 = cVar5 + (char)uVar1;
      while (cStack_3 != '\0') {
        uVar4 = 1;
        iVar3 = 1;
        cStack_3 = cStack_3 + -1;
        uVar2 = ovc30_usesRandBelow(2);
        ovc30_textDivideError((byte)uVar2,iVar3,(char)uVar4,(byte)((ulong)uVar4 >> 0x10));
      }
      cStack_3 = -1;
    }
    else {
      cStack_3 = *(char *)(Difficulty + 0x5de3);
      while (cVar5 = cStack_3 + -1, cStack_3 != '\0') {
        uVar4 = 1;
        iVar3 = 1;
        cStack_3 = cVar5;
        uVar2 = ovc30_usesRandBelow(3);
        ovc30_textDivideError((byte)uVar2,iVar3,(char)uVar4,(byte)((ulong)uVar4 >> 0x10));
      }
      cStack_3 = cVar5;
      if (1 < Difficulty) {
        uVar4 = 1;
        iVar3 = 1;
        uVar2 = ovc30_usesRandBelow(4);
        ovc30_textDivideError((byte)uVar2,iVar3,(char)uVar4,(byte)((ulong)uVar4 >> 0x10));
      }
      if ((flags & 1) != 0) {
        ovr_uiNotify((char *)"All enemies destroyed.",0x2410);
        in_DX = 0;
        ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x36));
      }
      msg = ovr_stsprintf((char *)&text,unaff_SS,(char *)"Next wave of enemies appear.");
      ovr_uiNotify(msg,in_DX);
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

undefined2 __cdecl16far ovc30_usesRandBelow(byte band)

{
  undefined2 uVar1;
  uint16_t uVar2;
  undefined2 unaff_SS;
  uint8_t bandMax;
  byte abStack_8 [2];
  uint8_t bandMin;
  byte abStack_4 [2];
  
  abStack_4 = (byte  [2])(*(uint16_t *)((uint8_t *)&(LevelBandMin) + 2));
  _bandMin = (*(uint16_t *)((uint8_t *)&(LevelBandMin)));
  abStack_8 = (byte  [2])(*(uint16_t *)((uint8_t *)&(LevelBandMax) + 2));
  _bandMax = (*(uint16_t *)((uint8_t *)&(LevelBandMax)));
  if (band == 4) {
    uVar1 = CONCAT11(SUB21((*(uint16_t *)((uint8_t *)&(LevelBandMax) + 2)),1),0x29);
  }
  else {
    do {
      do {
        uVar2 = ovr_randBelow(0x2a);
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

/* Finds or allocates a free leader record in the party-sheet table. */

uint __cdecl16far ovc30_createLeader(byte gindex,uint16_t x,uint16_t y)

{
  uint uVar1;
  uint16_t uVar2;
  far_t *pfVar3;
  char *in_DX;
  uint uStack_8;
  char_sheet_t *pcStack_6;
  char *pcStack_4;
  
  uStack_8 = 0;
  while ((uStack_8 < GLeaderCount && (*(char *)((int)*(undefined4 *)(uStack_8 << 2) + 0x28) != '\0')
         )) {
    uStack_8 = uStack_8 + 1;
  }
  if (uStack_8 < GLeaderCount) {
    pcStack_4 = (char *)((undefined2 *)(uStack_8 * 4))[1];
    pcStack_6 = (char_sheet_t *)*(undefined2 *)(uStack_8 * 4);
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
    uStack_8 = (uint)GLeaderCount;
    uVar1 = (uint)GLeaderCount;
    ((undefined2 *)(uVar1 * 4))[1] = in_DX;
    *(undefined2 *)(uVar1 * 4) = pcStack_6;
    GLeaderCount = GLeaderCount + 1;
    pcStack_4 = in_DX;
  }
  _fmemset(pcStack_6,(uint16_t)pcStack_4,0);
  strcpy(pcStack_6->nameText,pcStack_4);
  pcStack_6->active = 1;
  pcStack_6->x = x;
  pcStack_6->y = y;
  pcStack_6->classStr = gindex;
  pcStack_6->cls = 0xff;
  pcStack_6->race = 3;
  uVar2 = ovr_randBelow(1);
  pcStack_6->gender = (byte)uVar2;
  ovr_manage_rollStats(pcStack_6);
  if (*(char *)((int)&worldMenuLabels[0xc].seg + (uint)gindex * 0x95) != -1) {
    pcStack_6->stats[1] = *(byte *)((int)&worldMenuLabels[0xc].seg + (uint)gindex * 0x95);
  }
  if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)gindex * 0x95) & 0x800) != 0) {
    pcStack_6->stats[4] = 0x12;
  }
  pcStack_6->faction = *(uint8_t *)((int)(char **)GMenuStrings + (uint)gindex * 0x95 + 0x1f);
  pcStack_6->alignment = *(byte *)((int)(far_t *)(worldMenuLabels + 9) + (uint)gindex * 0x95);
  pcStack_6->hp[0] = *(byte *)((int)&worldMenuLabels[6].seg + (uint)gindex * 0x95);
  pcStack_6->hp[1] = pcStack_6->hp[0];
  pcStack_6->statMask = pcStack_6->statMask | 0x16;
  pcStack_6->spyReports = 0x1;
  *(undefined2 *)((int)&pcStack_6->gold + 2) = 0;
  *(undefined2 *)&pcStack_6->gold = 100;
  pcStack_6->partySlot = 0xff;
  pfVar3 = ovr_ovc22_textRingProt((byte)uStack_8);
  return CONCAT11((char)((uint)pfVar3 >> 8),(byte)uStack_8);
}



/* 619c:05a5 */

/* [R2] string "Divide error\r\n" */

byte __cdecl16far ovc30_textDivideError(byte gindex,int frames,char mode,byte percent)

{
  byte *pbVar1;
  undefined4 uVar2;
  bool bVar3;
  int iVar4;
  uint16_t uVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  uint16_t uVar9;
  uint uVar10;
  uint uVar11;
  byte bStack_13;
  byte bStack_11;
  int iStack_10;
  uint16_t uStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  int iStack_4;
  
  iStack_6 = 1;
  bStack_11 = 0xff;
  iVar4 = ovr_ovc25_compute1(gindex);
  iStack_10 = iVar4 * 3 + 0xf;
  if (0x31 < iStack_10) {
    iStack_10 = 0x32;
  }
  do {
    if (frames == 0) {
      return bStack_11;
    }
    if (mode == '\x02') {
      uStack_c = demoCenterY;
      mode = '\x01';
      uVar9 = demoCenterX;
    }
    else if (mode == '\0') {
      iStack_8 = demoCenterX + iStack_6 * -8;
      iStack_a = demoCenterX + iStack_6 * 8;
      if (iStack_8 < 8) {
        iStack_8 = 8;
      }
      if (0x8c < iStack_a) {
        iStack_a = 0x8c;
      }
      uVar9 = ovr_randBelow((iStack_a - iStack_8) + 1);
      uVar9 = (uVar9 & 0xff) + iStack_8 & 0xfffc;
      iStack_8 = demoCenterY + iStack_6 * -4;
      iStack_a = demoCenterY + iStack_6 * 4;
      if (iStack_8 < 8) {
        iStack_8 = 8;
      }
      if (0x34 < iStack_a) {
        iStack_a = 0x34;
      }
      uVar5 = ovr_randBelow((iStack_a - iStack_8) + 1);
      uStack_c = (uVar5 & 0xff) + iStack_8;
    }
    else {
      bStack_13 = 0;
      do {
        bVar3 = false;
        uVar9 = ovr_randBelow(0x8c);
        uVar9 = (uVar9 & 0xff) + 4 & 0xfffc;
        uStack_c = ovr_randBelow(0x3a);
        uStack_c = uStack_c & 0xff;
        for (iVar4 = 0; iVar4 < (int)(uint)GLeaderCount; iVar4 = iVar4 + 1) {
          if (((*(char *)((int)*(undefined4 *)(iVar4 << 2) + 0x3d) != '\0') &&
              (*(char *)((int)*(undefined4 *)(iVar4 << 2) + 0x3f) != '\0')) &&
             (uVar6 = *(int *)((int)*(undefined4 *)(iVar4 << 2) + 0x39) - uVar9,
             uVar10 = (int)uVar6 >> 0xf,
             uVar8 = *(int *)((int)*(undefined4 *)(iVar4 << 2) + 0x3b) - uStack_c,
             uVar11 = (int)uVar8 >> 0xf,
             (int)((int)((uVar6 ^ uVar10) - uVar10) / 2 + ((uVar8 ^ uVar11) - uVar11)) < 10)) {
            bVar3 = true;
            bStack_13 = bStack_13 + 1;
            break;
          }
          if (((*(char *)((int)*(undefined4 *)(iVar4 << 2) + 0x3d) != '\0') &&
              (*(char *)((int)*(undefined4 *)(iVar4 << 2) + 0x3f) == '\0')) &&
             (uVar6 = *(int *)((int)*(undefined4 *)(iVar4 << 2) + 0x39) - uVar9,
             uVar10 = (int)uVar6 >> 0xf,
             uVar8 = *(int *)((int)*(undefined4 *)(iVar4 << 2) + 0x3b) - uStack_c,
             uVar11 = (int)uVar8 >> 0xf,
             (int)((int)((uVar6 ^ uVar10) - uVar10) / 2 + ((uVar8 ^ uVar11) - uVar11)) < iStack_10))
          {
            bVar3 = true;
            bStack_13 = bStack_13 + 1;
            break;
          }
        }
      } while ((bVar3) && (bStack_13 < 100));
    }
    uVar6 = ovr_constr_usesGMapFlags(uVar9 - 1,uStack_c);
    if ((((char)uVar6 == '\0') ||
        (uVar6 = ovr_constr_usesGMapFlags(uVar9,uStack_c), (char)uVar6 == '\0')) ||
       (pcVar7 = ovr_ovc18_textArena(uVar9,uStack_c), ((uint)pcVar7 & 0xff) != 0)) {
      iStack_6 = iStack_6 + 1;
      if (500 < iStack_6) {
        return bStack_11;
      }
    }
    else {
      uVar6 = ovc30_createLeader(gindex,uVar9,uStack_c);
      bStack_11 = (byte)uVar6;
      if (1 < PlayerIndex) {
        uVar2 = *(undefined4 *)((uVar6 & 0xff) << 2);
        pbVar1 = (byte *)((int)uVar2 + 0x5d);
        *pbVar1 = *pbVar1 | 0x10;
      }
      if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)gindex * 0x95) & 0x800) == 0) {
        if (PlayerIndex < 2) {
          uVar2 = *(undefined4 *)((uVar6 & 0xff) << 2);
          ovr_ovc15_usesLDIV_at_
                    (uVar9,uStack_c,uVar9,uStack_c,gindex,*(uint8_t *)((int)uVar2 + 0xa4),bStack_11)
          ;
        }
        else {
          for (iStack_4 = 0; uVar8 = ovc30_difficultyFactor(), iStack_4 < (int)(uVar8 & 0xff);
              iStack_4 = iStack_4 + 1) {
            ovr_ovc15_usesLDIV_at_(uVar9,uStack_c,uVar9,uStack_c,gindex,0xa,bStack_11);
          }
        }
      }
      else {
        ovr_ovc15_usesLDIV_at_(uVar9,uStack_c,uVar9,uStack_c,gindex,0x1,bStack_11);
        for (iStack_4 = 0; uVar8 = ovc30_difficultyFactor(), iVar4 = (uVar8 & 0xff) * 2,
            iVar4 - iStack_4 != 0 && iStack_4 <= iVar4; iStack_4 = iStack_4 + 1) {
          ovr_ovc18_textTypeLen(bStack_11,uVar9,uStack_c,0x2);
        }
      }
      if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)gindex * 0x95) & 0x1000) != 0) {
        ovc30_usesRandBelow2(uVar9,uStack_c);
      }
      uVar2 = *(undefined4 *)((uVar6 & 0xff) << 2);
      *(undefined1 *)((int)uVar2 + 0x5a) = 0;
      ((short (*) [148] [60])GUnitGrid)[-1][uVar9 + 0x93][uStack_c] =
           (uint)*(byte *)((int)(far_t *)(worldMenuLabels + 0xb) + (uint)gindex * 0x95);
      ovr_ovc23_placeBuilding
                (uVar9 - 1,uStack_c,
                 *(byte *)(((short (*) [148] [60])GUnitGrid)[-1][uVar9 + 0x93] + uStack_c),bStack_11
                );
      ovr_ovc23_placeBuilding(uVar9,uStack_c,0,bStack_11);
      (*(short (*) [148] [60])GUnitGrid)[uVar9][uStack_c] = 0;
      frames = frames + -1;
      demoCenterY = uStack_c;
      demoCenterX = uVar9;
      uVar9 = ovr_randBelow(100);
      mode = (byte)uVar9 < percent;
      iStack_6 = 0;
    }
  } while( true );
}



/* 619c:0a5e */

/* [R4] calls ovr_randBelow */

void __cdecl16far ovc30_usesRandBelow2(int centerX,int centerY)

{
  uint16_t uVar1;
  uint uVar2;
  int iVar3;
  int iStack_6;
  
  for (iStack_6 = -0xc; iStack_6 < 0xd; iStack_6 = iStack_6 + 1) {
    for (iVar3 = -8; iVar3 < 9; iVar3 = iVar3 + 1) {
      uVar1 = ovr_randBelow(2);
      if ((uVar1 & 0xff) == 0) {
        uVar2 = ovr_ovc45_compute4(centerX + iStack_6,centerY + iVar3);
        if ((char)uVar2 != '\0') {
          uVar1 = ovr_randBelow(9);
          (*(short (*) [148] [60])GUnitGrid)[centerX + iStack_6][centerY + iVar3] =
               (uVar1 & 0xff) + 0xef;
        }
      }
    }
  }
  return;
}


