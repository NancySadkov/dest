/* ovc15_usesAgntIndex - collects the entities standing on the GfxRndSeed/
   GfxRndSeed2 tile into agentIndices, then alternates ovc15_textArena calls
   between the upper and lower lane while either still owes text lines
   (linesTop/linesBottom, in 16-pixel units), and finally removes agents
   whose +0x2d flag is clear.  The stack array is addressed as words through
   &agentIndices, so it keeps its decompiler declaration. */
void __cdecl16far ovc15_usesAgntIndex(void)

{
  uint agntIndex;
  int entitiesOfs;
  int bottomIdx;
  int topIdx;
  uint16_t entitiesSeg;
  uint16_t unaff_SS;
  uint8_t agentIndices;
  uint linesBottom;
  uint linesTop;
  int count;
  uint i;
  
  ovc15_clearVisited();
  count = 0;
  for (i = 0; i < EntityCount; i = i + 1) {
    entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
    bottomIdx = (int)Entities;
    if (((GfxRndSeed - 2U <= *(uint *)((entity_t *)bottomIdx + i)) &&
        (*(uint *)((entity_t *)bottomIdx + i) <= GfxRndSeed + 1U)) &&
       (((entity_t *)bottomIdx)[i].base.y == GfxRndSeed2)) {
      *(uint *)(&agentIndices + count * 2) = i;
      count = count + 1;
    }
  }
  topIdx = 0;
  bottomIdx = 0;
  while ((bottomIdx < count || (topIdx < count))) {
    while( true ) {
      entitiesOfs = (int)Entities;
      entitiesSeg = (uint16_t)((ulong)Entities >> 0x10);
      if ((count <= topIdx) ||
         (*(char *)((int)(char **)GMenuStrings +
                   (uint)*(byte *)(entitiesOfs + *(int *)(&agentIndices + topIdx * 2) * 0x37 + 0xd) * 0x95
                   + 0x1f) == '\x01')) break;
      topIdx = topIdx + 1;
    }
    while ((bottomIdx < count &&
           (*(char *)((int)(char **)GMenuStrings +
                     (uint)*(byte *)(entitiesOfs + *(int *)(&agentIndices + bottomIdx * 2) * 0x37 + 0xd) *
                     0x95 + 0x1f) != '\0'))) {
      bottomIdx = bottomIdx + 1;
    }
    if (topIdx < count) {
      linesTop = (*(byte *)(entitiesOfs + *(int *)(&agentIndices + topIdx * 2) * 0x37 + 0xe) + 0xf) / 0x10;
    }
    else {
      linesTop = 0;
    }
    if (bottomIdx < count) {
      linesBottom = (*(byte *)(entitiesOfs + *(int *)(&agentIndices + bottomIdx * 2) * 0x37 + 0xe) + 0xf) / 0x10;
    }
    else {
      linesBottom = 0;
    }
    while ((linesTop != 0 || (linesBottom != 0))) {
      if (linesTop != 0) {
        ovc15_textArena(*(int *)(&agentIndices + topIdx * 2),0,(uint)(AgntFlag1 == false));
        linesTop = linesTop - 1;
      }
      if (linesBottom != 0) {
        ovc15_textArena(*(int *)(&agentIndices + bottomIdx * 2),0,(uint)(AgntFlag1 == false));
        linesBottom = linesBottom - 1;
      }
    }
    if (topIdx < count) {
      topIdx = topIdx + 1;
    }
    if (bottomIdx < count) {
      bottomIdx = bottomIdx + 1;
    }
  }
  for (i = 0; agntIndex = i, (int)i < (int)(uint)AgntCount;
      i = i + 1) {
    if (*(char *)(i * 0x34 + 0x2d) == '\0') {
      i = i - 1;
      ovr_ovc41_removeAgent(agntIndex,0);
    }
  }
  AgntFlag1 = true;
  return;
}
