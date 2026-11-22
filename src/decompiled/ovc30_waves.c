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

void __cdecl16far ovc30_nextWave(byte flags,...)

{
  uint16_t uVar1;
  undefined2 uVar2;
  char *msg;
  uint16_t in_DX;
  char *unaff_SS;
  int iVar3;
  char cVar4;
  char cVar5;
  undefined1 uVar6;
  byte bVar7;
  uint8_t text;
  char cStack_3;
  
  if (PlayerIndex < 2) {
    PlayerIndex = PlayerIndex + 1;
    if (PlayerIndex == 1) {
      cVar4 = *(char *)(Difficulty + 0x5dcb);
      uVar1 = ovr_randBelow((byte)((undefined1 *)&lowIntelEnemies)[Difficulty] + 1);
      cStack_3 = cVar4 + (char)uVar1;
      while (cStack_3 != '\0') {
        bVar7 = 0x19;
        cVar4 = '\x01';
        iVar3 = 1;
        cStack_3 = cStack_3 + -1;
        uVar2 = ovc30_usesRandBelow(0);
        ovc30_textDivideError((byte)uVar2,iVar3,cVar4,bVar7,cVar4);
      }
      cVar4 = *(char *)(Difficulty + 0x5dd3);
      cStack_3 = cStack_3 + -1;
      uVar1 = ovr_randBelow((byte)((undefined1 *)&lowIntelEnemies)[Difficulty] + 1);
      cStack_3 = cVar4 + (char)uVar1;
      while (cStack_3 != '\0') {
        bVar7 = 0x19;
        cVar4 = '\x01';
        iVar3 = 1;
        cStack_3 = cStack_3 + -1;
        uVar2 = ovc30_usesRandBelow(1);
        ovc30_textDivideError((byte)uVar2,iVar3,cVar4,bVar7,cVar4);
      }
      cVar4 = *(char *)(Difficulty + 0x5ddb);
      cStack_3 = cStack_3 + -1;
      uVar1 = ovr_randBelow((byte)((undefined1 *)&highIntelEnemies)[Difficulty] + 1);
      cStack_3 = cVar4 + (char)uVar1;
      while (cStack_3 != '\0') {
        bVar7 = 0;
        cVar4 = '\x01';
        iVar3 = 1;
        cStack_3 = cStack_3 + -1;
        uVar2 = ovc30_usesRandBelow(2);
        ovc30_textDivideError((byte)uVar2,iVar3,cVar4,bVar7,cVar4);
      }
      cStack_3 = -1;
    }
    else {
      cStack_3 = *(char *)(Difficulty + 0x5de3);
      while (cVar4 = cStack_3 + -1, cStack_3 != '\0') {
        bVar7 = 0;
        cVar5 = '\x01';
        iVar3 = 1;
        cStack_3 = cVar4;
        uVar2 = ovc30_usesRandBelow(3);
        ovc30_textDivideError((byte)uVar2,iVar3,cVar5,bVar7,cVar5);
      }
      cStack_3 = cVar4;
      if (1 < Difficulty) {
        bVar7 = 0;
        cVar5 = '\x01';
        iVar3 = 1;
        uVar2 = ovc30_usesRandBelow(4);
        ovc30_textDivideError((byte)uVar2,iVar3,cVar5,bVar7,cVar5);
      }
      if ((flags & 1) != 0) {
        ovr_uiNotify((char *)"All enemies destroyed.",0x2410,0x10,0);
        in_DX = 0;
        ovr_inputUpdate((ulong)((uint)MessageDelay * 2 + 0x36));
      }
      uVar6 = (undefined1)(PlayerIndex + 1);
      msg = ovr_stsprintf((char *)&text,(char *)CONCAT22(0x5e0f,unaff_SS),
                          (char *)CONCAT13((char)(PlayerIndex + 1 >> 8),CONCAT12(uVar6,0x2410)),
                          uVar6,0);
      ovr_uiNotify(msg,in_DX,(char)in_DX);
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

undefined1 __cdecl16far ovc30_compute1(byte level,...)

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
  undefined2 uVar1;
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
    uStack_4 = ((undefined2 *)(count * 4))[1];
    pcStack_6 = (char_sheet_t *)*(undefined2 *)(count * 4);
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
    ((undefined2 *)(uVar2 * 4))[1] = in_DX;
    *(undefined2 *)(uVar2 * 4) = (uint16_t)pcStack_6;   /* hand fix: store of the far pointer's offset half */
    GLeaderCount = GLeaderCount + 1;
    uStack_4 = in_DX;
  }
  _fmemset((void *)(ulong)uStack_4,0xae,count);
  partyIndex = (byte)count;
  uVar1 = *(undefined2 *)((int)&worldMenuLabels[1].ofs + 1 + (uint)gindex * 0x95);
  strcpy((char *)CONCAT22(uStack_4,pcStack_6),
         (char *)CONCAT13((char)((uint)uVar1 >> 8),
                          CONCAT12((char)uVar1,
                                   *(undefined2 *)
                                    ((int)&worldMenuLabels[0].seg + 1 + (uint)gindex * 0x95))));
  pcStack_6->active = 1;
  pcStack_6->x = x;
  pcStack_6->y = y;
  pcStack_6->classStr = gindex;
  pcStack_6->cls = 0xff;
  pcStack_6->race = 3;
  uVar3 = ovr_randBelow(1);
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
  *(undefined2 *)((int)&pcStack_6->gold + 2) = 0;
  *(undefined2 *)&pcStack_6->gold = 100;
  pcStack_6->partySlot = 0xff;
  pfVar4 = ovr_ovc22_textRingProt(partyIndex);
  return CONCAT11((char)((uint)pfVar4 >> 8),partyIndex);
}


/* 619c:05a5 */

/* [R2] string "Divide error\r\n" */

byte __cdecl16far ovc30_textDivideError(byte gindex,int frames,char mode,byte percent,...)

{
  byte *pbVar1;
  undefined4 uVar2;
  bool bVar3;
  int iVar4;
  uint16_t uVar5;
  uint uVar6;
  uint uVar7;
  uint16_t uVar8;
  uint uVar9;
  uint uVar10;
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
      uVar8 = demoCenterX;
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
      uVar8 = ovr_randBelow((iStack_a - iStack_8) + 1);
      uVar8 = (uVar8 & 0xff) + iStack_8 & 0xfffc;
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
        uVar8 = ovr_randBelow(0x8c);
        uVar8 = (uVar8 & 0xff) + 4 & 0xfffc;
        uStack_c = ovr_randBelow(0x3a);
        uStack_c = uStack_c & 0xff;
        for (iVar4 = 0; iVar4 < (int)(uint)GLeaderCount; iVar4 = iVar4 + 1) {
          if (((((char_sheet_t *)((iVar4 << 2)))->active != '\0') &&
              (*(char *)((int)*(undefined4 *)(iVar4 << 2) + 0x3f) != '\0')) &&
             (uVar6 = ((char_sheet_t *)((iVar4 << 2)))->x - uVar8,
             uVar9 = (int)uVar6 >> 0xf,
             uVar7 = ((char_sheet_t *)((iVar4 << 2)))->y - uStack_c,
             uVar10 = (int)uVar7 >> 0xf,
             (int)((int)((uVar6 ^ uVar9) - uVar9) / 2 + ((uVar7 ^ uVar10) - uVar10)) < 10)) {
            bVar3 = true;
            bStack_13 = bStack_13 + 1;
            break;
          }
          if (((((char_sheet_t *)((iVar4 << 2)))->active != '\0') &&
              (*(char *)((int)*(undefined4 *)(iVar4 << 2) + 0x3f) == '\0')) &&
             (uVar6 = ((char_sheet_t *)((iVar4 << 2)))->x - uVar8,
             uVar9 = (int)uVar6 >> 0xf,
             uVar7 = ((char_sheet_t *)((iVar4 << 2)))->y - uStack_c,
             uVar10 = (int)uVar7 >> 0xf,
             (int)((int)((uVar6 ^ uVar9) - uVar9) / 2 + ((uVar7 ^ uVar10) - uVar10)) < iStack_10)) {
            bVar3 = true;
            bStack_13 = bStack_13 + 1;
            break;
          }
        }
      } while ((bVar3) && (bStack_13 < 100));
    }
    uVar6 = ovr_constr_usesGMapFlags(uVar8 - 1,uStack_c);
    if ((((char)uVar6 == '\0') ||
        (uVar6 = ovr_constr_usesGMapFlags(uVar8,uStack_c), (char)uVar6 == '\0')) ||
       (bVar3 = ovr_ovc18_textArena(uVar8,uStack_c), bVar3)) {
      iStack_6 = iStack_6 + 1;
      if (500 < iStack_6) {
        return bStack_11;
      }
    }
    else {
      uVar6 = ovc30_createLeader(gindex,uVar8,uStack_c);
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
                    (uVar8,uStack_c,uVar8,uStack_c,gindex,*(uint8_t *)((int)uVar2 + 0xa4),bStack_11)
          ;
        }
        else {
          for (iStack_4 = 0; uVar7 = ovc30_difficultyFactor(), iStack_4 < (int)(uVar7 & 0xff);
              iStack_4 = iStack_4 + 1) {
            ovr_ovc15_usesLDIV_at_(uVar8,uStack_c,uVar8,uStack_c,gindex,0xa,bStack_11);
          }
        }
      }
      else {
        ovr_ovc15_usesLDIV_at_(uVar8,uStack_c,uVar8,uStack_c,gindex,0x1,bStack_11);
        for (iStack_4 = 0; uVar7 = ovc30_difficultyFactor(), iVar4 = (uVar7 & 0xff) * 2,
            iVar4 - iStack_4 != 0 && iStack_4 <= iVar4; iStack_4 = iStack_4 + 1) {
          ovr_ovc18_textTypeLen(bStack_11,uVar8,uStack_c,0x2);
        }
      }
      if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)gindex * 0x95) & 0x1000) != 0) {
        ovc30_usesRandBelow2(uVar8,uStack_c);
      }
      uVar2 = *(undefined4 *)((uVar6 & 0xff) << 2);
      *(undefined1 *)((int)uVar2 + 0x5a) = 0;
      ((short (*) [148] [60])GUnitGrid)[-1][uVar8 + 0x93][uStack_c] =
           (uint)*(byte *)((int)(far_t far *)(worldMenuLabels + 0xb) + (uint)gindex * 0x95);
      ovr_ovc23_placeBuilding
                (uVar8 - 1,uStack_c,
                 *(byte *)(((short (*) [148] [60])GUnitGrid)[-1][uVar8 + 0x93] + uStack_c),bStack_11
                );
      ovr_ovc23_placeBuilding(uVar8,uStack_c,0,bStack_11);
      (*(short (*) [148] [60])GUnitGrid)[uVar8][uStack_c] = 0;
      frames = frames + -1;
      demoCenterY = uStack_c;
      demoCenterX = uVar8;
      uVar8 = ovr_randBelow(100);
      mode = (byte)uVar8 < percent;
      iStack_6 = 0;
    }
  } while( true );
}



/* 619c:0a5e */

/* [R4] calls ovr_randBelow */

void __cdecl16far ovc30_usesRandBelow2(int centerX,int centerY,...)

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


