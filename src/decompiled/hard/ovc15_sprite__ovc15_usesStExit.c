void __cdecl16far ovc15_usesStExit(int entityIndex,...)

{
  uint8_t *puVar1;
  uint uVar2;
  entity_t *peVar3;
  int iVar4;
  uint uVar5;
  undefined2 uVar6;
  char cStack_5;
  
  if (EntityCount < 0x259) {
    if (EntityCount != 600) {
      memcpy((char *)CONCAT22(DAT_2000_d190,Entities + EntityCount),
             (char *)CONCAT22(DAT_2000_d190,Entities + entityIndex),0x37);
      uVar6 = (undefined2)((ulong)Entities >> 0x10);
      ((entity_t *)Entities)[EntityCount].base.animFrame =
           (uint8_t)((int)(uint)((entity_t *)Entities)[entityIndex].base.animFrame >> 1);
      uVar6 = (undefined2)((ulong)Entities >> 0x10);
      puVar1 = &((entity_t *)Entities)[entityIndex].base.animFrame;
      *puVar1 = *puVar1 - ((entity_t *)Entities)[EntityCount].base.animFrame;
      uVar2 = EntityCount;
      uVar5 = (uint)((entity_t *)Entities)[EntityCount].base.animFrame;
      EntityCount = EntityCount + 1;
      ovr_attact_usesGMapFlags3();
      if (AgntFlag1 != false) {
        cStack_5 = '\0';
        iVar4 = 0;
        while ((iVar4 < (int)(uint)AgntCount && (uVar5 != 0))) {
          if (*(int *)(iVar4 * 0x34 + 0x1b) == entityIndex) {
            if (cStack_5 == '\0') {
              *(uint *)(iVar4 * 0x34 + 0x1b) = uVar2;
              peVar3 = Entities + uVar2;
              *(undefined2 *)(iVar4 * 0x34 + 0x19) = DAT_2000_d190;
              *(undefined2 *)(iVar4 * 0x34 + 0x17) =(uint16_t)( peVar3);
              uVar5 = uVar5 - 1;
            }
            cStack_5 = '\x01' - (cStack_5 != '\0');
          }
          iVar4 = iVar4 + 1;
        }
      }
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x26);
}
