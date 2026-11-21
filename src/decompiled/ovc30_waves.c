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

/* WARNING: Variable defined which should be unmapped: text */
/* Advances the player index, spawns the next enemy wave and reports it. */

void __cdecl16far ovc30_nextWave(byte flags,...)

{
  char cVar1;
  uint16_t uVar2;
  char *pcVar3;
  undefined2 in_DX;
  char *unaff_SS;
  byte in_stack_00000004;
  byte bVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  uint8_t text;
  undefined1 uStack_7b;
  char cStack_3;
  
  if (PlayerIndex < 2) {
    PlayerIndex = PlayerIndex + 1;
    if (PlayerIndex == 1) {
      bVar4 = *(byte *)(Difficulty + 0x5dcb);
      uVar2 = ovr_randBelow((uint)bVar4,(byte)((undefined1 *)&lowIntelEnemies)[Difficulty] + 1);
      cStack_3 = bVar4 + (char)uVar2;
      while (cStack_3 != '\0') {
        cStack_3 = cStack_3 + -1;
        ovc30_usesRandBelow(0);
        ovc30_textDivideError();
      }
      bVar4 = *(byte *)(Difficulty + 0x5dd3);
      cStack_3 = cStack_3 + -1;
      uVar2 = ovr_randBelow((uint)bVar4,(byte)((undefined1 *)&lowIntelEnemies)[Difficulty] + 1);
      cStack_3 = bVar4 + (char)uVar2;
      while (cStack_3 != '\0') {
        cStack_3 = cStack_3 + -1;
        ovc30_usesRandBelow(1);
        ovc30_textDivideError();
      }
      bVar4 = *(byte *)(Difficulty + 0x5ddb);
      cStack_3 = cStack_3 + -1;
      uVar2 = ovr_randBelow((uint)bVar4,(byte)((undefined1 *)&highIntelEnemies)[Difficulty] + 1);
      cStack_3 = bVar4 + (char)uVar2;
      while (cStack_3 != '\0') {
        cStack_3 = cStack_3 + -1;
        ovc30_usesRandBelow(2);
        ovc30_textDivideError();
      }
      cStack_3 = -1;
    }
    else {
      cStack_3 = *(char *)(Difficulty + 0x5de3);
      while (cVar1 = cStack_3 + -1, cStack_3 != '\0') {
        cStack_3 = cVar1;
        ovc30_usesRandBelow(3);
        ovc30_textDivideError();
      }
      cStack_3 = cVar1;
      if (1 < Difficulty) {
        ovc30_usesRandBelow(4);
        ovc30_textDivideError();
      }
      if ((in_stack_00000004 & 1) != 0) {
        ovr_uiNotify((char *)0xa0002410,0xf8);
        in_DX = 0;
        ovr_inputUpdate((ulong)CONCAT11(uStack_7b,text) << 0x10,(uint)MessageDelay * 2 + 0x36);
      }
      uVar5 = 0;
      uVar6 = 0xa0;
      pcVar3 = ovr_stsprintf((char *)CONCAT22(0x5e0f,unaff_SS),
                             (char *)CONCAT22(PlayerIndex + 1,(char *)"puppetmaker" + 3),
                             (char *)0xa000,&text,0x10,0);
      ovr_uiNotify((char *)CONCAT13(uVar6,CONCAT12(uVar5,in_DX)),(char)pcVar3);
      ovr_inputUpdate((ulong)CONCAT11(uStack_7b,text) << 0x10,(uint)MessageDelay * 2 + 0x36);
    }
    if ((in_stack_00000004 & 2) == 0) {
      ovr_constr_usesBlitRect();
    }
  }
  return;
}



/* 619c:025d */

/* [R4] calls ovr_randBelow */

undefined2 __cdecl16far ovc30_usesRandBelow(byte band)

{
  char cVar1;
  undefined2 uVar2;
  uint16_t uVar3;
  undefined2 unaff_SS;
  undefined2 in_stack_0000fff4;
  undefined1 uVar4;
  uint16_t n;
  uint8_t bandMax;
  byte abStack_8 [2];
  uint8_t bandMin;
  byte abStack_4 [2];
  
  abStack_4 = (byte  [2])(*(uint16_t *)((uint8_t *)&(LevelBandMin) + 2));
  bandMin = (*(uint16_t *)((uint8_t *)&(LevelBandMin)));
  abStack_8 = (byte  [2])(*(uint16_t *)((uint8_t *)&(LevelBandMax) + 2));
  bandMax = (*(uint16_t *)((uint8_t *)&(LevelBandMax)));
  if (band == 4) {
    uVar2 = CONCAT11(SUB21((*(uint16_t *)((uint8_t *)&(LevelBandMax) + 2)),1),0x29);
  }
  else {
    uVar4 = (undefined1)((uint)in_stack_0000fff4 >> 8);
    n = CONCAT11(uVar4,uVar4);
    do {
      do {
        uVar3 = ovr_randBelow(n,0x2a);
        cVar1 = (char)uVar3;
        n = CONCAT11(cVar1,(char)n);
      } while (cVar1 == ')');
    } while (((*(char *)((int)(char **)GMenuStrings + (uVar3 & 0xff) * 0x95 + 0x1f) == '\0') ||
             (*(byte *)((int)&worldMenuLabels[0xc].seg + (uVar3 & 0xff) * 0x95) < (&bandMin)[band]))
            || ((&bandMax)[band] < *(byte *)((int)&worldMenuLabels[0xc].seg + (uVar3 & 0xff) * 0x95)
               ));
    uVar2 = CONCAT11((char)((uint)(&bandMax + band) >> 8),cVar1);
  }
  return uVar2;
}



/* 619c:031d */

/* [R7] body shape: compute */

undefined1 __cdecl16far ovc30_compute1(byte level,...)

{
  undefined1 uVar1;
  byte in_stack_00000004;
  
  if (in_stack_00000004 < 5) {
    uVar1 = 0;
  }
  else if (in_stack_00000004 < 9) {
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
  uint in_DX;
  byte partyIndex;
  uint force;
  char *pcStack_6;
  uint uStack_4;
  
  force = 0;
  while ((force < GLeaderCount && (*(char *)((int)*(undefined4 *)(force << 2) + 0x28) != '\0'))) {
    force = force + 1;
  }
  if (force < GLeaderCount) {
    uStack_4 = ((undefined2 *)(force * 4))[1];
    pcStack_6 = (char *)*(undefined2 *)(force * 4);
  }
  else {
    if (0x4f < GLeaderCount) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(force,0x21);
    }
    if (!GameRunning) {
      ovr_fmFreeAudio(force,1);
    }
    pcStack_6 = ovr_stshAlloc((ulong)force << 0x10,0xae);
    force = (uint)GLeaderCount;
    uVar1 = (uint)GLeaderCount;
    ((undefined2 *)(uVar1 * 4))[1] = in_DX;
    *(undefined2 *)(uVar1 * 4) = pcStack_6;
    GLeaderCount = GLeaderCount + 1;
    uStack_4 = in_DX;
  }
  _fmemset((void *)(ulong)uStack_4,0xae,force);
  strcpy((char *)CONCAT22(uStack_4,pcStack_6),
         (char *)CONCAT22(*(undefined2 *)((int)&worldMenuLabels[1].ofs + 1 + (uint)gindex * 0x95),
                          (char *)*(undefined2 *)
                                   ((int)&worldMenuLabels[0].seg + 1 + (uint)gindex * 0x95)));
  pcStack_6[0x3d] = '\x01';
  *(uint16_t *)(pcStack_6 + 0x39) = x;
  *(uint16_t *)(pcStack_6 + 0x3b) = y;
  pcStack_6[0x3e] = gindex;
  pcStack_6[0x2f] = -1;
  pcStack_6[0x30] = '\x03';
  uVar2 = ovr_randBelow(force,1);
  partyIndex = (byte)force;
  pcStack_6[0x34] = (char)uVar2;
  ovr_manage_rollStats
            ((char_sheet_t *)CONCAT13((char)(force >> 8),CONCAT12(partyIndex,uStack_4)),pcStack_6);
  if (*(char *)((int)&worldMenuLabels[0xc].seg + (uint)gindex * 0x95) != -1) {
    pcStack_6[0x2a] = *(char *)((int)&worldMenuLabels[0xc].seg + (uint)gindex * 0x95);
  }
  if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)gindex * 0x95) & 0x800) != 0) {
    pcStack_6[0x2d] = '\x12';
  }
  pcStack_6[0x3f] = *(char *)((int)(char **)GMenuStrings + (uint)gindex * 0x95 + 0x1f);
  pcStack_6[0x33] = *(char *)((int)(far_t *)(worldMenuLabels + 9) + (uint)gindex * 0x95);
  pcStack_6[0x31] = *(char *)((int)&worldMenuLabels[6].seg + (uint)gindex * 0x95);
  pcStack_6[0x32] = pcStack_6[0x31];
  pcStack_6[0x28] = pcStack_6[0x28] | 0x16;
  pcStack_6[0x40] = '\x01';
  (pcStack_6 + 0x58)[0] = '\0';
  (pcStack_6 + 0x58)[1] = '\0';
  (pcStack_6 + 0x56)[0] = 'd';
  (pcStack_6 + 0x56)[1] = '\0';
  pcStack_6[0x89] = -1;
  pfVar3 = ovr_ovc22_textRingProt(partyIndex,CONCAT11((char)((uint)gindex * 0x95 >> 8),partyIndex));
  return CONCAT11((char)((uint)pfVar3 >> 8),partyIndex);
}



/* 619c:05a5 */

/* [R2] string "Divide error\r\n" */

byte __cdecl16far ovc30_textDivideError(byte gindex,int frames,char mode,byte percent,...)

{
  byte *pbVar1;
  undefined4 uVar2;
  bool bVar3;
  undefined2 in_AX;
  int iVar4;
  uint16_t uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  short *psVar9;
  uint16_t uVar10;
  uint uVar11;
  uint uVar12;
  uint16_t unaff_DI;
  byte in_stack_00000004;
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
  iVar4 = ovr_ovc25_compute1((byte)unaff_DI,CONCAT11((char)((uint)in_AX >> 8),in_stack_00000004));
  iStack_10 = iVar4 * 3 + 0xf;
  if (0x31 < iStack_10) {
    iStack_10 = 0x32;
  }
  do {
    if (gindex == 0) {
      return bStack_11;
    }
    if ((char)frames == '\x02') {
      uStack_c = demoCenterY;
      frames = 1;
      uVar10 = demoCenterX;
    }
    else if ((char)frames == '\0') {
      iStack_8 = demoCenterX + iStack_6 * -8;
      iStack_a = demoCenterX + iStack_6 * 8;
      if (iStack_8 < 8) {
        iStack_8 = 8;
      }
      if (0x8c < iStack_a) {
        iStack_a = 0x8c;
      }
      uVar10 = ovr_randBelow(unaff_DI,(iStack_a - iStack_8) + 1);
      uVar10 = (uVar10 & 0xff) + iStack_8 & 0xfffc;
      iStack_8 = demoCenterY + iStack_6 * -4;
      iStack_a = demoCenterY + iStack_6 * 4;
      if (iStack_8 < 8) {
        iStack_8 = 8;
      }
      if (0x34 < iStack_a) {
        iStack_a = 0x34;
      }
      uVar5 = ovr_randBelow(unaff_DI,(iStack_a - iStack_8) + 1);
      uStack_c = (uVar5 & 0xff) + iStack_8;
    }
    else {
      bStack_13 = 0;
      do {
        bVar3 = false;
        uVar10 = ovr_randBelow(unaff_DI,0x8c);
        uVar10 = (uVar10 & 0xff) + 4 & 0xfffc;
        uStack_c = ovr_randBelow(unaff_DI,0x3a);
        uStack_c = uStack_c & 0xff;
        for (iVar4 = 0; iVar4 < (int)(uint)GLeaderCount; iVar4 = iVar4 + 1) {
          if (((*(char *)((int)*(undefined4 *)(iVar4 << 2) + 0x3d) != '\0') &&
              (*(char *)((int)*(undefined4 *)(iVar4 << 2) + 0x3f) != '\0')) &&
             (uVar6 = *(int *)((int)*(undefined4 *)(iVar4 << 2) + 0x39) - uVar10,
             uVar11 = (int)uVar6 >> 0xf,
             uVar7 = *(int *)((int)*(undefined4 *)(iVar4 << 2) + 0x3b) - uStack_c,
             uVar12 = (int)uVar7 >> 0xf,
             (int)((int)((uVar6 ^ uVar11) - uVar11) / 2 + ((uVar7 ^ uVar12) - uVar12)) < 10)) {
            bVar3 = true;
            bStack_13 = bStack_13 + 1;
            break;
          }
          if (((*(char *)((int)*(undefined4 *)(iVar4 << 2) + 0x3d) != '\0') &&
              (*(char *)((int)*(undefined4 *)(iVar4 << 2) + 0x3f) == '\0')) &&
             (uVar6 = *(int *)((int)*(undefined4 *)(iVar4 << 2) + 0x39) - uVar10,
             uVar11 = (int)uVar6 >> 0xf,
             uVar7 = *(int *)((int)*(undefined4 *)(iVar4 << 2) + 0x3b) - uStack_c,
             uVar12 = (int)uVar7 >> 0xf,
             (int)((int)((uVar6 ^ uVar11) - uVar11) / 2 + ((uVar7 ^ uVar12) - uVar12)) < iStack_10))
          {
            bVar3 = true;
            bStack_13 = bStack_13 + 1;
            break;
          }
        }
      } while ((bVar3) && (bStack_13 < 100));
    }
    uVar6 = ovr_constr_usesGMapFlags(uStack_c,unaff_DI,uVar10 - 1);
    if ((((char)uVar6 == '\0') ||
        (uVar6 = ovr_constr_usesGMapFlags(uStack_c,unaff_DI,uVar10), (char)uVar6 == '\0')) ||
       (bVar3 = ovr_ovc18_textArena(uStack_c,unaff_DI,uVar10), bVar3)) {
      iStack_6 = iStack_6 + 1;
      if (500 < iStack_6) {
        return bStack_11;
      }
    }
    else {
      uVar6 = ovc30_createLeader(in_stack_00000004,uVar10,uStack_c);
      bStack_11 = (byte)uVar6;
      if (1 < PlayerIndex) {
        uVar2 = *(undefined4 *)((uVar6 & 0xff) << 2);
        pbVar1 = (byte *)((int)uVar2 + 0x5d);
        *pbVar1 = *pbVar1 | 0x10;
      }
      if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)in_stack_00000004 * 0x95) & 0x800) ==
          0) {
        if (PlayerIndex < 2) {
          puVar8 = (undefined4 *)((uVar6 & 0xff) << 2);
          uVar2 = *puVar8;
          ovr_ovc15_usesLDIV_at_
                    (uStack_c,uVar10,uStack_c,CONCAT11((char)((uint)puVar8 >> 8),in_stack_00000004),
                     *(byte *)((int)uVar2 + 0xa4),bStack_11,(byte)unaff_DI,uVar10);
        }
        else {
          for (iStack_4 = 0; uVar7 = ovc30_difficultyFactor(), iStack_4 < (int)(uVar7 & 0xff);
              iStack_4 = iStack_4 + 1) {
            ovr_ovc15_usesLDIV_at_
                      (uStack_c,uVar10,uStack_c,(uint)in_stack_00000004,10,bStack_11,(byte)unaff_DI,
                       uVar10);
          }
        }
      }
      else {
        ovr_ovc15_usesLDIV_at_
                  (uStack_c,uVar10,uStack_c,
                   CONCAT11((char)((uint)in_stack_00000004 * 0x95 >> 8),in_stack_00000004),1,
                   bStack_11,(byte)unaff_DI,uVar10);
        iStack_4 = 0;
        while( true ) {
          uVar7 = ovc30_difficultyFactor();
          iVar4 = (uVar7 & 0xff) * 2;
          if (iVar4 - iStack_4 == 0 || iVar4 < iStack_4) break;
          ovr_ovc18_textTypeLen
                    ((uint8_t)uVar10,uStack_c,2,(uint8_t)unaff_DI,
                     CONCAT11((char)((uint)iVar4 >> 8),bStack_11));
          iStack_4 = iStack_4 + 1;
        }
      }
      if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)in_stack_00000004 * 0x95) & 0x1000) !=
          0) {
        ovc30_usesRandBelow2(uStack_c,unaff_DI,uVar10);
      }
      uVar2 = *(undefined4 *)((uVar6 & 0xff) << 2);
      *(undefined1 *)((int)uVar2 + 0x5a) = 0;
      ((short (*) [148] [60])GUnitGrid)[-1][uVar10 + 0x93][uStack_c] =
           (uint)*(byte *)((int)(far_t *)(worldMenuLabels + 0xb) + (uint)in_stack_00000004 * 0x95);
      psVar9 = (*(short (*) [148] [60])GUnitGrid)[uVar10] + uStack_c;
      ovr_ovc23_placeBuilding
                (uStack_c,CONCAT11((char)((uint)psVar9 >> 8),*(undefined1 *)(psVar9 + -0x3c)),
                 bStack_11,(uint8_t)unaff_DI,uVar10 - 1);
      ovr_ovc23_placeBuilding(uStack_c,0,bStack_11,(uint8_t)unaff_DI,uVar10);
      (*(short (*) [148] [60])GUnitGrid)[uVar10][uStack_c] = 0;
      gindex = gindex + -1;
      demoCenterY = uStack_c;
      demoCenterX = uVar10;
      uVar10 = ovr_randBelow(unaff_DI,100);
      frames = (int)((byte)uVar10 < (byte)mode);
      iStack_6 = 0;
    }
  } while( true );
}



/* 619c:0a5e */

/* [R4] calls ovr_randBelow */

void __cdecl16far ovc30_usesRandBelow2(int centerX,int centerY,...)

{
  int iVar1;
  uint16_t uVar2;
  uint uVar3;
  int iVar4;
  uint16_t unaff_DI;
  int in_stack_00000004;
  int iStack_6;
  
  for (iStack_6 = -0xc; iStack_6 < 0xd; iStack_6 = iStack_6 + 1) {
    for (iVar4 = -8; iVar4 < 9; iVar4 = iVar4 + 1) {
      iVar1 = in_stack_00000004 + iStack_6;
      uVar2 = ovr_randBelow(unaff_DI,2);
      if ((uVar2 & 0xff) == 0) {
        uVar3 = ovr_ovc45_compute4(centerX + iVar4,unaff_DI,iVar1);
        if ((char)uVar3 != '\0') {
          uVar2 = ovr_randBelow(unaff_DI,9);
          (*(short (*) [148] [60])GUnitGrid)[iVar1][centerX + iVar4] = (uVar2 & 0xff) + 0xef;
        }
      }
    }
  }
  return;
}


