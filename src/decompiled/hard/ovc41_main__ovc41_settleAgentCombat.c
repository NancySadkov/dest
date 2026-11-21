uint __cdecl16far ovc41_settleAgentCombat(agnt_t *a,agnt_t *b,...)

{
  uint in_AX;
  uint uVar1;
  int iVar2;
  byte bVar3;
  undefined2 in_stack_0000000a;
  
  if ((((agnt_t *)(*(uint16_t *)((uint8_t *)&(b) + 2))))->combatState == 0x2) {
    uVar1 = in_AX & 0xff00;
  }
  else {
    if ((a != (agnt_t *)0x0 || (agnt_t *)b != (agnt_t *)0x0) && (a->gdata->ai == a->faction)) {
      ovc41_compute4(*(agnt_t **)&(((agnt_t *)(*(uint16_t *)((uint8_t *)&(b) + 2))))->entity,
                     (byte)*(undefined2 *)((int)&(((agnt_t *)(*(uint16_t *)((uint8_t *)&(b) + 2))))->entity + 2),1,*(agnt_t **)&a->entity);
    }
    if (((((((entity_t *)(((agnt_t *)(*(uint16_t *)((uint8_t *)&(b) + 2))))->entity)->base).animFrame == 0x0) ||
         ((uint)(((entity_t *)(((agnt_t *)(*(uint16_t *)((uint8_t *)&(b) + 2))))->entity)->base).animFrame % 0x10 == 1)) ||
        (((((agnt_t *)(*(uint16_t *)((uint8_t *)&(b) + 2))))->flags & 0xae4) != 0)) || ((((agntG_t *)(((agnt_t *)(*(uint16_t *)((uint8_t *)&(b) + 2))))->gdata)->flags2 & 4) != 0)) {
      (((agnt_t *)(*(uint16_t *)((uint8_t *)&(b) + 2))))->strength = 0x0;
      (((agnt_t *)(*(uint16_t *)((uint8_t *)&(b) + 2))))->timer = 0xa;
      (((agnt_t *)(*(uint16_t *)((uint8_t *)&(b) + 2))))->combatState = 0x2;
      (((agnt_t *)(*(uint16_t *)((uint8_t *)&(b) + 2))))->targetY = 0;
    }
    else {
      (((agnt_t *)(*(uint16_t *)((uint8_t *)&(b) + 2))))->strength = ((agntG_t *)(((agnt_t *)(*(uint16_t *)((uint8_t *)&(b) + 2))))->gdata)->strength;
      (((agnt_t *)(*(uint16_t *)((uint8_t *)&(b) + 2))))->timer = 0x6;
      (((agnt_t *)(*(uint16_t *)((uint8_t *)&(b) + 2))))->combatState = 0x1;
      (((agnt_t *)(*(uint16_t *)((uint8_t *)&(b) + 2))))->targetY = 0;
    }
    ovr_agnt_usesAnimFrame(((agnt_t *)(*(uint16_t *)((uint8_t *)&(b) + 2))));
    iVar2 = (((agnt_t *)(*(uint16_t *)((uint8_t *)&(b) + 2))))->owner * 0x37;
    bVar3 = (byte)((uint)iVar2 >> 8);
    ovr_ovc25_attackingNotice(*(byte *)((int)Entities + iVar2 + 0x1a));
    if (((((agnt_t *)(*(uint16_t *)((uint8_t *)&(b) + 2))))->flags & 0xae4) == 0) {
      ovc41_markAgentDead((agnt_t *)CONCAT22(in_stack_0000000a,((agnt_t *)(*(uint16_t *)((uint8_t *)&(b) + 2)))));
      uVar1 = CONCAT11(bVar3,1);
    }
    else {
      uVar1 = (uint)bVar3 << 8;
    }
  }
  return uVar1;
}
