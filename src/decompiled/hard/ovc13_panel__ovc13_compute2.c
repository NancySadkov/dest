void __cdecl16far ovc13_compute2(int x,int y,byte upperMask,byte lowerMask,uint16_t seg)

{
  undefined1 *puVar1;
  undefined1 *uStack_6;   /* hand fix: assigned a byte pointer and dereferenced as *uStack_6 */
  
  puVar1 = (undefined1 *)(x + y * 0x140);
  uStack_6 = (undefined1 *)CONCAT22(seg,puVar1);
  if ((upperMask & 1) != 0) {
    puVar1[0x140] = 0xfd;
    puVar1[0x141] = 0xfd;
  }
  if ((upperMask & 2) != 0) {
    *uStack_6 = 0xfd;
    puVar1[0x140] = 0xfd;
  }
  if (((lowerMask & 2) != 0) && (puVar1[0x280] = 0xfd, (lowerMask & 1) != 0)) {
    puVar1[0x281] = 0xfd;
  }
  return;
}
