/* ovc18_usesAlignUp4 - recovered from STRONG.EXE.
   leaderIdx walks GLeaders (char_sheet_t at index<<2), bestDist is the min-tracked
   distance (tested against 0x1e), inArena is the ovr_draw_textArena() result that
   guards the body.  uVar2..uVar5 are absolute-difference intermediates; uVar5 is
   reused for three roles, so they keep their decompiler names. */
uint __cdecl16far ovc18_usesAlignUp4(void)

{
  bool inArena;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int leaderIdx;
  undefined2 uVar7;
  uint bestDist;
  
  inArena = ovr_draw_textArena();
  if (inArena) {
    for (uVar5 = 0; uVar5 < EntityCount; uVar5 = uVar5 + 1) {
      uVar7 = (undefined2)((ulong)Entities >> 0x10);
      if (*(char *)((int)(char **)GMenuStrings +
                   (uint)((entity_t *)Entities)[uVar5].base.gindex * 0x95 + 0x1f) != '\0') {
        uVar2 = ovr_alignUp4(*(int *)((int)Entities + uVar5 * 0x37));
        uVar3 = ovr_alignUp4(GfxRndSeed);
        if ((uVar2 == uVar3) &&
           (uVar2 = ((entity_t *)Entities)[uVar5].base.y, uVar2 == GfxRndSeed2)) {
          return uVar2 & 0xff00;
        }
      }
    }
    for (leaderIdx = 0; leaderIdx < (int)(uint)GLeaderCount; leaderIdx = leaderIdx + 1) {
      if (((((char_sheet_t *)((leaderIdx << 2)))->active != '\0') &&
          (((char_sheet_t *)((leaderIdx << 2)))->x == GfxRndSeed)) &&
         (uVar5 = ((char_sheet_t *)((leaderIdx << 2)))->y, uVar5 == GfxRndSeed2)) {
        return uVar5 & 0xff00;
      }
    }
    uVar5 = ovr_constr_usesGMapFlags(GfxRndSeed + -1,GfxRndSeed2);
    if (((uVar5 & 0xff) == 0) ||
       (uVar5 = ovr_constr_usesGMapFlags(GfxRndSeed,GfxRndSeed2), (uVar5 & 0xff) == 0)) {
      uVar5 = 0;
    }
    else if ((CurPartySlot == 1) &&
            ((uVar5 = ovr_constr_usesGMapFlags(GfxRndSeed + -2,GfxRndSeed2), (uVar5 & 0xff) == 0 ||
             (uVar5 = ovr_constr_usesGMapFlags(GfxRndSeed + 1,GfxRndSeed2), (uVar5 & 0xff) == 0))))
    {
      uVar5 = 0;
    }
    else {
      uVar5 = 0x2410;
      if (1 < CurPartySlot) {
        bestDist = 0xffff;
        for (leaderIdx = 0; uVar5 = (uint)GLeaderCount, leaderIdx < (int)uVar5; leaderIdx = leaderIdx + 1) {
          if (((((char_sheet_t *)((leaderIdx << 2)))->active != '\0') &&
              (*(char *)((int)*(undefined4 *)(leaderIdx << 2) + 0x3f) == '\0')) &&
             (uVar5 = ((char_sheet_t *)((leaderIdx << 2)))->x - GfxRndSeed,
             uVar3 = (int)uVar5 >> 0xf,
             uVar2 = ((char_sheet_t *)((leaderIdx << 2)))->y - GfxRndSeed2,
             uVar4 = (int)uVar2 >> 0xf,
             uVar5 = ((uVar5 ^ uVar3) - uVar3) + ((uVar2 ^ uVar4) - uVar4), uVar5 < bestDist)) {
            bestDist = uVar5;
          }
        }
        if (0x1e < bestDist) {
          return 0;
        }
      }
      uVar5 = CONCAT11((char)(uVar5 >> 8),1);
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}
