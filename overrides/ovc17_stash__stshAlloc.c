void * __cdecl16far stshAlloc(uint32_t nbytes,...)

{
  uint uVar1;
  uint16_t ofs_00;
  uint32_t r;
  uint32_t result;
  uint16_t ofs;
  uint16_t seg;
  uint32_t newbuf;
  
  if (nbytes == 0xfa0f) {
    (*(uint16_t *)((uint8_t *)&(r))) =(uint16_t) (far_t far *)StshBuf.ofs;
    if (StshBuf.ofs == 0 && StshBuf.seg == 0) {
      (*(uint16_t *)((uint8_t *)&(r))) =(uint16_t) farmalloc((far_t *)0xfa0f,(ulong)ofs << 0x10);
      StshBuf.ofs = (uint16_t)(far_t far *)r;
      StshBuf.seg = (*(uint16_t *)((uint8_t *)&(r) + 2));
    }
  }
  else {
    ovr_fmFreeAudio(0);
    if (nbytes == 0) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x1c);
    }
    do {
      if (HeapReady == '\0') {
        ofs = (uint16_t)farmalloc((far_t *)nbytes,CONCAT22(ofs,(*(uint16_t *)((uint8_t *)&(nbytes) + 2))));
        ofs_00 = (*(uint16_t *)((uint8_t *)&(r) + 2));
      }
      else {
        ofs = (uint16_t)ovr_heapAlloc((uint32_t *)(far_t far *)nbytes,CONCAT22(ofs,(*(uint16_t *)((uint8_t *)&(nbytes) + 2))));
        ofs_00 = (*(uint16_t *)((uint8_t *)&(r) + 2));
      }
      (*(uint16_t *)((uint8_t *)&(r) + 2)) = ofs_00;
      if ((ofs == 0 && ofs_00 == 0) && (uVar1 = fmOutOfMemory(nbytes), (uVar1 & 0xff) == 0)) {
        return (void *)0x0;
      }
    } while (ofs == 0 && ofs_00 == 0);
    (*(uint16_t *)((uint8_t *)&(r))) =(uint16_t) (far_t far *)ovr_mkp((uint32_t *)ofs,ofs_00,ofs);
  }
  return (far_t far *)r;
}
