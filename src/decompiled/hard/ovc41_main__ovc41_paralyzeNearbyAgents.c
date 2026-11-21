void __cdecl16far ovc41_paralyzeNearbyAgents(int agntIndex,...)

{
  byte bVar1;
  agnt_t *paVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  entity_t *uStack_6;   /* hand fix: dereferenced as uStack_6->x */
  
  paVar2 = (agnt_t *)(agntIndex * 0x34);
  uStack_6 = (agnt_t *)CONCAT22(0x1726,paVar2);
  if ((((agntG_t *)paVar2->gdata)->flags2 & 4) != 0) {
    for (iVar6 = 0; iVar6 < (int)(uint)AgntCount; iVar6 = iVar6 + 1) {
      if ((iVar6 != agntIndex) &&
         (uVar3 = uStack_6->x - *(int *)(iVar6 * 0x34), uVar5 = (int)uVar3 >> 0xf,
         (int)((uVar3 ^ uVar5) - uVar5) < 0x32)) {
        bVar1 = ovr_manage_rollDice('\x06','\x06');
        uVar3 = (uint)bVar1;
        iVar4 = ovr_ovc27_rollToHitEntity(CONCAT22(0x1726,iVar6 * 0x34),1);
        if ((char)iVar4 != '\0') {
          uVar3 = (int)uVar3 >> 1;
        }
        ovc41_textParalyzed((agnt_t *)CONCAT22(0x1726,paVar2),
                            (agnt_t *)CONCAT22(0x1726,(agnt_t *)(iVar6 * 0x34)),uVar3);
      }
    }
  }
  return;
}
