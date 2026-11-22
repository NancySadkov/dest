int fseek_Displacement(uint *stream)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  uint16_t uVar8;
  undefined1 *uStack_6;   /* hand fix: dereferenced as *uStack_6 */
  
  uVar8 = (uint16_t)((ulong)stream >> 0x10);
  puVar6 = (uint *)stream;
  if ((int)*stream < 0) {
    iVar2 = puVar6[3] + *stream + 1;
  }
  else {
    uVar5 = (int)*stream >> 0xf;
    iVar2 = (*stream ^ uVar5) - uVar5;
  }
  iVar7 = iVar2;
  if ((puVar6[1] & 0x40) == 0) {
    uStack_6 = (char *)CONCAT22(puVar6[7],(char *)puVar6[6]);
    iVar3 = iVar2;
    if ((int)*stream < 0) {
      while (iVar3 = iVar2 + -1, iVar2 != 0) {
        uStack_6 = (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(char *)uStack_6 + -1);
        iVar2 = iVar3;
        if (*uStack_6 == '\n') {
          iVar7 = iVar7 + 1;
        }
      }
    }
    else {
      while (pcVar1 = uStack_6, iVar4 = iVar3 + -1, iVar7 = iVar2, iVar3 != 0) {
        uStack_6 = (char *)CONCAT22((*(uint16_t *)((uint8_t *)&(uStack_6) + 2)),(char *)uStack_6 + 1);
        iVar3 = iVar4;
        if (*pcVar1 == '\n') {
          iVar2 = iVar2 + 1;
        }
      }
    }
  }
  return iVar7;
}
