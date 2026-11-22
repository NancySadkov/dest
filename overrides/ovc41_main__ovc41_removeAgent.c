void __cdecl16far ovc41_removeAgent(uint agntIndex,int notify,...)

{
  char *pcVar1;
  uint16_t uVar2;
  agnt_t *agnt;
  int iVar3;
  uint16_t uVar4;
  bool bVar5;
  uint uVar6;
  entity_t *uStack_8;   /* hand fix: dereferenced as uStack_8->base.x */
  
  uVar2 = *(uint16_t *)(agntIndex * 0x34 + 0x19);
  agnt = (agnt_t *)*(uint16_t *)(agntIndex * 0x34 + 0x17);
  uStack_8 = (agnt_t *)CONCAT22(uVar2,agnt);
  iVar3 = *(int *)(agntIndex * 0x34 + 0x1b);
  ovr_agnt_usesAgntCount4(agntIndex + 1);
  bVar5 = false;
  for (uVar6 = 0; (int)uVar6 < (int)(uint)AgntCount; uVar6 = uVar6 + 1) {
    if ((uVar6 != agntIndex) && (*(int *)(uVar6 * 0x34 + 0x1b) == iVar3)) {
      bVar5 = true;
    }
    if (*(char *)(uVar6 * 0x34 + 0xc) != -1) {
      if ((int)agntIndex < (int)(uint)*(byte *)(uVar6 * 0x34 + 0xc)) {
        pcVar1 = (char *)(uVar6 * 0x34 + 0xc);
        *pcVar1 = *pcVar1 + -1;
      }
      else if (*(byte *)(uVar6 * 0x34 + 0xc) == agntIndex) {
        *(undefined1 *)(uVar6 * 0x34 + 0xc) = 0xff;
      }
    }
  }
  if ((int)(agntIndex + 1) < (int)(uint)AgntCount) {
    _fmemmove((char *)CONCAT22(0x1726,(char *)(agntIndex * 0x34)),
              (char *)CONCAT22(0x1726,(char *)(agntIndex * 0x34 + 0x34)),
              ((AgntCount - agntIndex) + -1) * 0x34);
  }
  AgntCount = AgntCount - 1;
  if ((((notify != 0) && (!bVar5)) && (agnt->y == GfxRndSeed2)) &&
     ((GfxRndSeed - 2U <= uStack_8->base.x && (GfxRndSeed - 2U <= uStack_8->base.x)))) {
    agnt->destX = agnt->targetX;
    uVar4 = agnt->targetY;
    agnt->destY = uVar4;
    ovr_attact_usesRandBelow(agnt,(byte)uVar2,CONCAT11((char)(uVar4 >> 8),agnt->target));
  }
  return;
}
