void __cdecl16far masked_memcpy(char *dst,char *src,int skip,int src_sz,int dst_sz,uint mask,...)

{
  uint16_t edst;
  uint16_t erc;
  uint16_t psrc;
  uint16_t pdst;
  uint in_stack_00000012;
  
  erc = dst_sz + (int)(*(uint16_t *)((uint8_t *)&(src) + 2));
  edst = mask + (int)dst;
  for (; (dst < edst && ((*(uint16_t *)((uint8_t *)&(src) + 2)) < erc)); (*(uint16_t *)((uint8_t *)&(src) + 2)) = (*(uint16_t *)((uint8_t *)&(src) + 2)) + 1) {
    if ((in_stack_00000012 & 1) != 0) {
      if (src_sz == 0) {
        if (*(byte *)(*(uint16_t *)((uint8_t *)&(src) + 2))   /* hand fix */ != '\0') {
          *dst = *(byte *)(*(uint16_t *)((uint8_t *)&(src) + 2))   /* hand fix */;
        }
        dst = dst + 1;
      }
      else {
        src_sz = src_sz + -1;
      }
    }
    in_stack_00000012 = in_stack_00000012 >> 1 | (uint)((in_stack_00000012 & 1) != 0) << 0xf;
  }
  return;
}
