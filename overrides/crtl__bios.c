void bios(int width,uint16_t *vramOfs)

{
  uint16_t *puVar1;
  uint16_t *puVar2;
  uint16_t uVar3;
  uint16_t unaff_SS;
  bool bVar4;
  bool bVar5;
  uint16_t *in_stack_00000004;
  int in_stack_0000000a;
  uint8_t cursorPos;
  uint8_t vramScreenOfs;
  uint8_t srcScreenOfs;
  
  cursorPos = _wherexy();
  bVar4 = in_stack_0000000a == (*(uint16_t *)((uint8_t *)&(_video.displayptr) + 1));
  if (bVar4) {
    srcScreenOfs = screenpos((uint)(*(uint16_t *)((uint8_t *)&(vramOfs) + 2)));
  }
  bVar5 = (uint16_t *)vramOfs == (uint16_t *)(*(uint16_t *)((uint8_t *)&(_video.displayptr) + 1));
  puVar1 = vramOfs;
  if (bVar5) {
    vramScreenOfs = screenpos((uint)in_stack_00000004);
  }
  while( true ) {
    (*(uint16_t *)((uint8_t *)&(vramOfs) + 2)) = (uint16_t)(uint16_t *)((ulong)puVar1 >> 0x10);
    (*(uint16_t *)((uint8_t *)&(vramOfs))) = (uint16_t)(uint16_t *)puVar1;
    if (width == 0) break;
    if (bVar5) {
      puVar2 = (uint16_t *)&cursorPos;
      moveto((uint16_t *)CONCAT22(unaff_SS,puVar2),(uint16_t *)CONCAT22(unaff_SS,&vramScreenOfs));
      uVar3 = CONCAT11(8,(char)puVar2);
      _VideoInt();
    }
    else {
      uVar3 = *(uint16_t *)CONCAT22((uint16_t *)vramOfs,in_stack_00000004);
      in_stack_00000004 = in_stack_00000004 + 1;
    }
    if (bVar4) {
      moveto((uint16_t *)CONCAT22(unaff_SS,&cursorPos),(uint16_t *)CONCAT22(unaff_SS,&srcScreenOfs))
      ;
      _VideoInt();
      width = width + -1;
    }
    else {
      *(uint16_t *)CONCAT22(in_stack_0000000a,(*(uint16_t *)((uint8_t *)&(vramOfs) + 2))) = uVar3;
      puVar1 = (uint16_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(vramOfs) + 2)) + 1,(uint16_t *)vramOfs);
      width = width + -1;
    }
  }
  _VideoInt();
  return;
}
