void __cdecl16far stshWriteFile(int fhandle,far_t buf,DW sz,...)

{
  uint16_t uVar1;
  uint16_t uVar2;
  uint16_t wrsz;
  uint16_t unaff_DI;
  uint32_t pbuf;
  
  do {
    if ((0 < (int)sz.hi) || ((wrsz = sz.lo, -1 < (long)CONCAT22(sz.hi, sz.lo) && (0xbfff < sz.lo)))) {
      wrsz = 0xc000;
    }
    (*(uint16_t *)((uint8_t *)&(pbuf))) = ovr_mkp((uint32_t *)buf.ofs,buf.seg,unaff_DI);
    uVar2 = (*(uint16_t *)((uint8_t *)&(pbuf) + 2));
    write(fhandle,(uint32_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(pbuf) + 2)),(uint32_t *)pbuf),wrsz);
    buf.seg = (*(uint16_t *)((uint8_t *)&(pbuf) + 2));
    buf.ofs = (int)(uint32_t *)pbuf + wrsz;
    uVar1 = sz.lo - wrsz;
    sz.hi = sz.hi - (sz.lo < wrsz);
    sz.lo = uVar1;
    (*(uint16_t *)((uint8_t *)&(pbuf) + 2)) = uVar2;
  } while (uVar1 != 0 || sz.hi != 0);
  return;
}
