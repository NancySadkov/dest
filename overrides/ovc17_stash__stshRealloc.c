uint8_t * __cdecl16far stshRealloc(uint32_t oldblock,uint32_t nbytes,...)

{
  uint8_t uVar1;
  undefined1 extraout_AH;
  uint uVar2;
  int in_DX;
  int iVar3;
  uint32_t r;
  
  if (oldblock == 0) {
    (*(uint16_t *)((uint8_t *)&(r))) =(uint16_t) stshAlloc(nbytes);
  }
  else {
    ovr_fmFreeAudio(0);
    if (nbytes == 0) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x13);
    }
    do {
      if (HeapReady == '\0') {
        uVar1 = farrealloc(oldblock,nbytes);
        (*(uint16_t *)((uint8_t *)&(r))) =(uint16_t) (long *)CONCAT11(extraout_AH,uVar1);
        iVar3 = in_DX;
      }
      else {
        (*(uint16_t *)((uint8_t *)&(r))) = ovr_heapRealloc((long *)oldblock,CONCAT22((undefined2)nbytes,(*(uint16_t *)((uint8_t *)&(oldblock) + 2))),
                                  CONCAT22((long *)r,(*(uint16_t *)((uint8_t *)&(nbytes) + 2))));
        iVar3 = in_DX;
      }
      in_DX = iVar3;
      if (((long *)r == (long *)0x0 && iVar3 == 0) &&
         (uVar2 = fmOutOfMemory(nbytes), (uVar2 & 0xff) == 0)) {
        return (uint8_t *)0x0;
      }
    } while ((long *)r == (long *)0x0 && iVar3 == 0);
  }
  return (uint8_t *)(long *)r;
}
