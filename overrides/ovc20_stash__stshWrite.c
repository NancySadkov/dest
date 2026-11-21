uint32_t * __cdecl16far stshWrite(uint32_t *__return_storage_ptr__,uint8_t *data,long sz,...)

{
  DW sz_00;
  DW sz_01;
  far_t buf;
  uint32_t *puVar1;
  uint16_t unaff_BP;
  
  if ((*(uint16_t *)((uint8_t *)&(data) + 2)) == (long *)0x0 && (uint16_t)sz == 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x58);
  }
  buf.seg = (uint16_t)(uint8_t *)data;
  buf.ofs = (uint16_t)__return_storage_ptr__;
  sz_00.hi = (uint16_t)sz;
  sz_00.lo = (uint16_t)(*(uint16_t *)((uint8_t *)&(data) + 2));
  stshWriteFile(StshFile,buf,sz_00);
  sz_01.hi = unaff_BP;
  sz_01.lo = (uint16_t)sz;
  puVar1 = (uint32_t *)stshAlloc_2((long *)(*(uint16_t *)((uint8_t *)&(data) + 2)),sz_01)   /* hand fix: hidden return-storage pointer */;
  return puVar1;
}
