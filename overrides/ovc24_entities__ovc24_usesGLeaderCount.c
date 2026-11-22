/* ovc24_usesGLeaderCount - recovered from STRONG.EXE.
   leaderIdx is the GLeaders loop index; bestDist/bestSameIdx and
   bestOtherDist/bestOtherIdx are the min-tracking pairs (initialised 0xffff /
   0xff, updated together when a closer leader is found); unitIdx walks GUnits
   from the first unit slot 0xf8.  Arithmetic temporaries left as-is. */
void __cdecl16far ovc24_usesGLeaderCount(byte leaderIndex)

{
  uint uVar1;
  uint uVar2;
  byte leaderIdx;
  uint uVar4;
  uint uVar5;
  undefined2 uVar6;
  uint bestOtherDist;
  uint bestDist;
  byte bestOtherIdx;
  byte bestSameIdx;
  uint unitIdx;
  
  bestDist = 0xffff;
  bestOtherDist = 0xffff;
  bestSameIdx = 0xff;
  bestOtherIdx = 0xff;
  if (*(char *)((int)*(undefined4 *)((uint)leaderIndex << 2) + 0x3f) == '\0') {
    for (leaderIdx = 0; leaderIdx < GLeaderCount; leaderIdx = leaderIdx + 1) {
      if (((((char_sheet_t *)(((uint)leaderIdx << 2)))->active != '\0') &&
          (*(char *)((int)*(undefined4 *)((uint)leaderIdx << 2) + 0x3f) ==
           *(char *)((int)*(undefined4 *)((uint)leaderIndex << 2) + 0x3f))) &&
         (uVar1 = ((char_sheet_t *)(((uint)leaderIdx << 2)))->x -
                  ((char_sheet_t *)(((uint)leaderIndex << 2)))->x,
         uVar4 = (int)uVar1 >> 0xf,
         uVar2 = ((char_sheet_t *)(((uint)leaderIdx << 2)))->y -
                 ((char_sheet_t *)(((uint)leaderIndex << 2)))->y,
         uVar5 = (int)uVar2 >> 0xf, uVar1 = ((uVar1 ^ uVar4) - uVar4) + ((uVar2 ^ uVar5) - uVar5),
         uVar1 < bestDist)) {
        bestDist = uVar1;
        bestSameIdx = leaderIdx;
      }
    }
  }
  else {
    for (leaderIdx = 0; leaderIdx < GLeaderCount; leaderIdx = leaderIdx + 1) {
      if (((((char_sheet_t *)(((uint)leaderIdx << 2)))->active != '\0') &&
          (*(char *)((int)*(undefined4 *)((uint)leaderIdx << 2) + 0x3f) == '\0')) &&
         (uVar1 = ((char_sheet_t *)(((uint)leaderIdx << 2)))->x -
                  ((char_sheet_t *)(((uint)leaderIndex << 2)))->x,
         uVar4 = (int)uVar1 >> 0xf,
         uVar2 = ((char_sheet_t *)(((uint)leaderIdx << 2)))->y -
                 ((char_sheet_t *)(((uint)leaderIndex << 2)))->y,
         uVar5 = (int)uVar2 >> 0xf,
         uVar1 = ((uVar1 ^ uVar4) - uVar4) + ((uVar2 ^ uVar5) - uVar5) * 2, uVar1 < bestOtherDist)) {
        bestOtherDist = uVar1;
        bestOtherIdx = leaderIdx;
      }
    }
  }
  for (uVar1 = 0; uVar1 < EntityCount; uVar1 = uVar1 + 1) {
    uVar6 = (undefined2)((ulong)Entities >> 0x10);
    if ((*(byte *)((int)Entities + uVar1 * 0x37 + 0x1a) == leaderIndex) &&
       (*(byte *)((int)Entities + uVar1 * 0x37 + 0x1a) = bestSameIdx, bestOtherIdx != 0xff)) {
      *(undefined2 *)((int)Entities + uVar1 * 0x37 + 8) =
           ((char_sheet_t *)(((uint)bestOtherIdx << 2)))->x;
      *(undefined2 *)((int)Entities + uVar1 * 0x37 + 10) =
           ((char_sheet_t *)(((uint)bestOtherIdx << 2)))->y;
    }
  }
  for (unitIdx = 0xf8; unitIdx < GUnitCount; unitIdx = unitIdx + 1) {
    uVar6 = (undefined2)((ulong)GUnits >> 0x10);
    if (((unit_t *)GUnits)[unitIdx].unitType == leaderIndex) {
      ((unit_t *)GUnits)[unitIdx].unitType = 0xff;
    }
  }
  return;
}
