void __cdecl16far stshReadFile(int handle,far_t dst,DW nbytes,...)

{
  uint16_t uVar1;
  uint16_t uVar2;
  uint uVar3;
  uint16_t unaff_DI;
  far_t pdst;
  
  do {
    if ((0 < (int)nbytes.hi) || ((uVar3 = nbytes.lo, -1 < (long)CONCAT22(nbytes.hi, nbytes.lo) && (0xbfff < nbytes.lo)))) {
      uVar3 = 0xc000;
    }
    pdst.ofs = (uint16_t)ovr_mkp((uint32_t *)dst.ofs,dst.seg,unaff_DI);
    uVar2 = pdst.seg;
    read(handle,(void *)CONCAT22(uVar3,pdst.seg),unaff_DI);
    dst.seg = pdst.seg;
    dst.ofs = pdst.ofs + uVar3;
    uVar1 = nbytes.lo - uVar3;
    nbytes.hi = nbytes.hi - (nbytes.lo < uVar3);
    nbytes.lo = uVar1;
    pdst.seg = uVar2;
  } while (uVar1 != 0 || nbytes.hi != 0);
  return;
}
