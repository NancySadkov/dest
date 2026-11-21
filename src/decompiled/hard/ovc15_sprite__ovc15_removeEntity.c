void __cdecl16far ovc15_removeEntity(uint entityIndex,...)

{
  int *piVar1;
  char cVar2;
  char partyIndex;
  uint16_t x;
  uint16_t y;
  entity_t *peVar3;
  uint uVar4;
  undefined2 uVar5;
  
  if (AgntFlag1) {
    for (uVar4 = 0; uVar4 < AgntCount; uVar4 = uVar4 + 1) {
      if ((*(uint *)(uVar4 * 0x34 + 0x1b) == entityIndex) &&
         (*(char *)(uVar4 * 0x34 + 0x24) != '\x02')) {
        *(undefined1 *)(uVar4 * 0x34 + 0x24) = 2;
        *(undefined2 *)(uVar4 * 0x34 + 6) = 0;
      }
    }
  }
  uVar5 = (undefined2)((ulong)Entities >> 0x10);
  peVar3 = (entity_t *)Entities;
  x = peVar3[entityIndex].base.destX;
  y = peVar3[entityIndex].base.destY;
  cVar2 = *(char *)((int)(char **)GMenuStrings + (uint)peVar3[entityIndex].base.gindex * 0x95 + 0x1f
                   );
  partyIndex = *(char *)((int)&peVar3[entityIndex].base.entity + 3);
  if (entityIndex < EntityCount - 1U) {
    _fmemmove((char *)CONCAT22(uVar5,peVar3 + entityIndex),
              (char *)CONCAT22(uVar5,peVar3 + entityIndex + 1),
              ((EntityCount + -1) - entityIndex) * 0x37);
  }
  if (AgntFlag1 != false) {
    for (uVar4 = 0; uVar4 < AgntCount; uVar4 = uVar4 + 1) {
      if (entityIndex < *(uint *)(uVar4 * 0x34 + 0x1b)) {
        piVar1 = (int *)(uVar4 * 0x34 + 0x1b);
        *piVar1 = *piVar1 + -1;
        peVar3 = Entities + *(int *)(uVar4 * 0x34 + 0x1b);
        *(undefined2 *)(uVar4 * 0x34 + 0x19) = DAT_2000_d190;
        *(undefined2 *)(uVar4 * 0x34 + 0x17) =(uint16_t)( peVar3);
      }
    }
  }
  EntityCount = EntityCount + -1;
  if ((cVar2 == '\0') && ((x != 0 || (y != 0)))) {
    ovr_attact_usesAlignUp4(x,y,partyIndex,0,partyIndex);
  }
  ovr_attact_usesGMapFlags3();
  return;
}
