uint __cdecl16far ovc26_usesStExit(int entityIndex,...)

{
  byte *pbVar1;
  uint uVar2;
  char *pcVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  entity_t *peVar11;
  char *pcVar12;
  uint16_t unaff_DI;
  uint16_t uVar13;
  uint16_t unaff_SS;
  uint8_t pathDirs [80];
  int iStack_1e;
  int iStack_1c;
  int iStack_1a;
  int iStack_18;
  byte bStack_10;
  byte bStack_f;
  uint uStack_c;
  entity_t *uStack_a;   /* hand fix: holds a far entity pointer; written as two 2-byte halves by the original code */
  char *pcStack_6;
  
  uVar2 = DAT_2000_d190;
  peVar11 = Entities + entityIndex;
  uStack_a = (entity_t *)CONCAT22(DAT_2000_d190,peVar11);
  uVar5 = GameTick - peVar11->tick;
  if (uVar5 < 0x19) {
    uVar5 = uVar5 & 0xff00;
  }
  else {
    debugStaleTickCount = debugStaleTickCount + 1;
    ovc26_usesFillGrid((uStack_a->base).x,(peVar11->base).y,
                       *(uint8_t *)
                        ((int)(char **)GMenuStrings + (uint)(peVar11->base).gindex * 0x95 + 0x1f));
    iVar6 = (peVar11->base).destX - ((uStack_a->base).x - 0x50);
    if (iVar6 < 0) {
      iVar6 = 0;
    }
    if (0xa0 < iVar6) {
      iVar6 = 0xa0;
    }
    iVar7 = (peVar11->base).destY - ((peVar11->base).y - 0x50);
    if (iVar7 < 0) {
      iVar7 = 0;
    }
    if (0xa0 < iVar7) {
      iVar7 = 0xa0;
    }
    uVar13 = (uint16_t)((ulong)FillGrid >> 0x10);
    pcVar12 = (char *)FillGrid;
    if (pcVar12[iVar7 + iVar6 * 0xa1] == '\0') {
      debugEmptyCellCount = debugEmptyCellCount + 1;
      uStack_c = 0xffff;
      pcStack_6 = (uint16_t)FillGrid;
      for (iVar6 = 0; iVar6 < 0xa1; iVar6 = iVar6 + 1) {
        for (iVar7 = 0; pcVar3 = pcStack_6, iVar7 < 0xa1; iVar7 = iVar7 + 1) {
          pcStack_6 = (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(pcStack_6) + 2)),(char *)pcStack_6 + 1);
          if ((*pcVar3 != '\0') &&
             (uVar5 = (((peVar11->base).x - 0x50) - (peVar11->base).destX) + iVar6,
             uVar9 = (int)uVar5 >> 0xf,
             uVar8 = (((peVar11->base).y - 0x50) - (peVar11->base).destY) + iVar7,
             uVar10 = (int)uVar8 >> 0xf,
             uVar5 = ((uVar5 ^ uVar9) - uVar9) + ((uVar8 ^ uVar10) - uVar10), uVar5 < uStack_c)) {
            iStack_1a = iVar7;
            iStack_18 = iVar6;
            uStack_c = uVar5;
          }
        }
      }
      iVar7 = iStack_1a;
      iVar6 = iStack_18;
      if (uStack_c == 0xffff) {
        (peVar11->base).faction = 0x0;
        *(undefined1 *)&(peVar11->base).state = 0;
        uVar5 = GameTick;
        peVar11->tick = GameTick;
        return uVar5 & 0xff00;
      }
    }
    if ((iVar6 == 0x50) && (iVar7 == 0x50)) {
      (peVar11->base).faction = 0x0;
      *(undefined1 *)&(peVar11->base).state = 0;
      uVar5 = GameTick;
      peVar11->tick = GameTick;
      uVar5 = uVar5 & 0xff00;
    }
    else {
      bStack_f = 0;
      while (pcVar12[iVar7 + iVar6 * 0xa1] != '\x01') {
        bStack_10 = 0;
        while ((bStack_10 < 4 &&
               ((((SCARRY2(iVar6,(int)*(char *)(bStack_10 + 0x885)) !=
                   iVar6 + *(char *)(bStack_10 + 0x885) < 0 ||
                  (0xa0 < iVar6 + *(char *)(bStack_10 + 0x885))) ||
                 (SCARRY2(iVar7,(int)*(char *)(bStack_10 + 0x889)) !=
                  iVar7 + *(char *)(bStack_10 + 0x889) < 0)) ||
                ((0xa0 < iVar7 + *(char *)(bStack_10 + 0x889) ||
                 ((byte)pcVar12[(int)*(char *)(bStack_10 + 0x889) +
                                iVar7 + (iVar6 + *(char *)(bStack_10 + 0x885)) * 0xa1] + 1 !=
                  (uint)(byte)pcVar12[iVar7 + iVar6 * 0xa1]))))))) {
          bStack_10 = bStack_10 + 1;
        }
        if (3 < bStack_10) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x19);
        }
        pathDirs[bStack_f] = bStack_10 ^ 2;
        bStack_f = bStack_f + 1;
        iVar6 = iVar6 + *(char *)(bStack_10 + 0x885);
        iVar7 = iVar7 + *(char *)(bStack_10 + 0x889);
      }
      if (bStack_f == 0) {
        (peVar11->base).faction = 0x0;
        *(undefined1 *)&(peVar11->base).state = 0;
        uVar5 = GameTick;
        peVar11->tick = GameTick;
        uVar5 = uVar5 & 0xff00;
      }
      else {
        _fmemset((void *)(ulong)uVar2,0x14,unaff_DI);
        *(byte *)&(peVar11->base).state = bStack_f;
        iStack_1c = 0;
        iVar6 = bStack_f - 1;
        for (iStack_1e = iVar6; -1 < iStack_1e; iStack_1e = iStack_1e + -1) {
          bVar4 = pathDirs[iStack_1e] << (((byte)iStack_1c & 3) << 1);
          iVar6 = CONCAT11((char)((uint)pathDirs >> 8),bVar4);
          pbVar1 = (byte *)((int)&(peVar11->base).owner + (iStack_1c >> 2));
          *pbVar1 = *pbVar1 | bVar4;
          iStack_1c = iStack_1c + 1;
        }
        (peVar11->base).faction = 0x0;
        uVar5 = CONCAT11((char)((uint)iVar6 >> 8),1);
      }
    }
  }
  return uVar5;
}
