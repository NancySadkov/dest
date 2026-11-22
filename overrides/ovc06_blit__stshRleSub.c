stshRleSub(far_t *__return_storage_ptr__,uint8_t *src,uint16_t sx,uint16_t sy,uint16_t ex,
          uint16_t ey,int16_t hdrsz,...)

{
  uint16_t sz;
  uint16_t width;
  uint16_t rlesz;
  uint16_t written;
  uint16_t start;
  uint16_t uVar1;
  uint16_t rows_left;
  uint32_t block;
  uint32_t r;
  uint16_t dst;
  uint16_t prow;
  undefined1 *uStack_6;   /* hand fix: assigned a byte pointer and dereferenced as *uStack_6 */
  uint16_t src_seg;
  uint16_t dseg;
  
  sz = ((ex - sx) + ((ex - sx) + 1 >> 7) + 2) * ((ey - sy) + 1);
  (*(uint16_t *)((uint8_t *)&(block) + 2)) = (sz + hdrsz) - 1;
  (*(uint16_t *)((uint8_t *)&(block))) = ovr_stshAlloc(CONCAT22((CARRY2(sz,hdrsz) - 1) + (uint)(sz + hdrsz != 0),(*(uint16_t *)((uint8_t *)&(block) + 2)))
                             );
  uStack_6 = (undefined1 *)CONCAT22((*(uint16_t *)((uint8_t *)&(block) + 2)),(undefined1 *)((int)(void *)block + hdrsz + -10));
  prow = (int)&__return_storage_ptr__[sy * 0x50].ofs + sx;
  uVar1 = (int)(void *)block + hdrsz + -1;
  width = (ex - sx) + 1;
  rows_left = (ey - sy) + 1;
  dst = uVar1;
  while (rows_left != 0) {
    rlesz = ovr_rle_line((uint8_t *)prow,(uint8_t *)CONCAT22(dst,src),(*(uint16_t *)((uint8_t *)&(block) + 2)));
    dst = dst + rlesz;
    prow = prow + 0x140;
    rows_left = rows_left - 1;
  }
  written = dst - uVar1;
  if (written <= sz) {
    *(uint16_t *)((int)(void *)block + hdrsz + -7) = 0;
    *(uint16_t *)((int)(void *)block + hdrsz + -9) = written;
    *(uint16_t *)((int)(void *)block + hdrsz + -5) = width;
    *(int *)((int)(void *)block + hdrsz + -3) = (ey - sy) + 1;
    *uStack_6 = 1;
    (*(uint16_t *)((uint8_t *)&(r))) = (uint16_t)(far_t far *)ovr_stshRealloc((uint32_t)CONCAT22((*(uint16_t *)((uint8_t *)&(block) + 2)),(void *)block),
                                       (ulong)((written + hdrsz) - 1));
    return (far_t far *)r;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(5);
}
