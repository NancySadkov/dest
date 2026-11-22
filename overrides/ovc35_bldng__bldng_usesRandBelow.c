undefined2 __cdecl16far bldng_usesRandBelow(byte typeIndex,...)

{
  uint16_t uVar1;
  int iVar2;
  
  uVar1 = ovr_randBelow((uint)*(byte *)MK_FP(((far_t far *)GStrangeTable)[typeIndex].seg,((far_t far *)GStrangeTable)[typeIndex].ofs))   /* hand fix: the entry is a far pointer, not a far_t value */;
  iVar2 = (uVar1 & 0xff) + ((far_t far *)GStrangeTable + typeIndex)->ofs;
  return CONCAT11((char)((uint)iVar2 >> 8),*(undefined1 *)(iVar2 + 1));
}
