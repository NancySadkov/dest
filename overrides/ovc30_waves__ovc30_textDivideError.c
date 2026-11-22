/* ovc30_textDivideError - creates one unit.  It retries up to 500 times:
   pick a random x inside [minBound,maxBound] (demo centre +/- tries*8) and
   a random y (demo centre +/- tries*4), retry up to 100 times while
   ovr_ovc18_textArena rejects the tile, then ovc30_createLeader and the
   per-difficulty escorts.  Local names come from those assignments. */
byte __cdecl16far ovc30_textDivideError(byte gindex,int frames,char mode,byte percent,...)

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
      uVar8 = ovr_randBelow((maxBound - minBound) + 1);
      uVar8 = (uVar8 & 0xff) + minBound & 0xfffc;
      minBound = demoCenterY + tries * -4;
      maxBound = demoCenterY + tries * 4;
      if (minBound < 8) {
        minBound = 8;
      }
      if (0x34 < maxBound) {
        maxBound = 0x34;
      }
      uVar5 = ovr_randBelow((maxBound - minBound) + 1);
      spawnY = (uVar5 & 0xff) + minBound;
    }
    else {
      retries = 0;
      do {
        bVar3 = false;
        uVar8 = ovr_randBelow(0x8c);
        uVar8 = (uVar8 & 0xff) + 4 & 0xfffc;
        spawnY = ovr_randBelow(0x3a);
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
    uVar6 = ovr_constr_usesGMapFlags(uVar8 - 1,spawnY);
    if ((((char)uVar6 == '\0') ||
        (uVar6 = ovr_constr_usesGMapFlags(uVar8,spawnY), (char)uVar6 == '\0')) ||
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
                    (uVar8,spawnY,uVar8,spawnY,gindex,*(uint8_t *)((int)uVar2 + 0xa4),leaderIndex)
          ;
        }
        else {
          for (count = 0; uVar7 = ovc30_difficultyFactor(), count < (int)(uVar7 & 0xff);
              count = count + 1) {
            ovr_ovc15_usesLDIV_at_(uVar8,spawnY,uVar8,spawnY,gindex,0xa,leaderIndex);
          }
        }
      }
      else {
        ovr_ovc15_usesLDIV_at_(uVar8,spawnY,uVar8,spawnY,gindex,0x1,leaderIndex);
        for (count = 0; uVar7 = ovc30_difficultyFactor(), iVar4 = (uVar7 & 0xff) * 2,
            iVar4 - count != 0 && count <= iVar4; count = count + 1) {
          ovr_ovc18_textTypeLen(leaderIndex,uVar8,spawnY,0x2);
        }
      }
      if ((*(uint *)((int)&worldMenuLabels[7].seg + 1 + (uint)gindex * 0x95) & 0x1000) != 0) {
        ovc30_usesRandBelow2(uVar8,spawnY);
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
      uVar8 = ovr_randBelow(100);
      mode = (byte)uVar8 < percent;
      tries = 0;
    }
  } while( true );
}
