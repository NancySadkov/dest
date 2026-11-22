spr_t * __cdecl16far stshRleAnims(uint8_t *src,anm_t *anms,uint16_t nanims)

{
  uint uVar1;
  uint16_t anim_height;
  uint16_t row;
  uint16_t panms;
  int *piVar2;
  uint16_t i;
  uint16_t unaff_DI;
  uint16_t count;
  far_t dst;
  frm_t *frm;
  far_t far *in_stack_00000004;
  uint16_t pdst;
  uint16_t sdst;
  uint32_t prev_next;
  frm_t *pfStack_20;
  uint16_t frm_seg;
  uint16_t xx;
  uint16_t exx;
  uint16_t sxx;
  uint16_t j;
  uint32_t p_ow;
  uint16_t ey;
  uint16_t ex;
  uint16_t sy;
  uint16_t sx;
  uint8_t index;
  
  if (0x4e < StshSprIndex) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x36);
  }
  dst.seg = (uint16_t)((spr_t *)StshSprites + StshSprIndex);
  StshSprIndex = StshSprIndex + 1;
  dst.ofs = (uint16_t)ovr_mkp((uint32_t *)dst.seg,(*(uint16_t *)((uint8_t *)&(StshSprites) + 2)),unaff_DI);
  _fsetmem((void *)CONCAT22(dst.seg,dst.ofs),0xb0,0);
  i = 0;
  while ((i < (*(uint16_t *)((uint8_t *)&(anms) + 2)) && (*(char *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 0x1b) != '\0'))) {
    uVar1 = (uint)*(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e);
    prev_next = CONCAT22(dst.seg,dst.ofs + uVar1 * 4 + 0x58);
    piVar2 = (int *)(dst.ofs + uVar1 * 4);
    piVar2[1] = (int)(anm_t *)anms;
    *piVar2 = (*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e;
    sx = *(uint16_t *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 1);
    sy = *(uint16_t *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 3);
    ex = *(uint16_t *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 5);
    ey = *(uint16_t *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 7);
    anim_height = ey - sy;
    if ((int)anim_height < 0) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x33);
    }
    p_ow = 0;
    j = 0;
    while( true ) {
      (*(uint16_t *)((uint8_t *)&(frm) + 2)) = (undefined2)((ulong)((long)(int)i * 0x1e) >> 0x10);
      if (*(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + (int)((long)(int)i * 0x1e) + 0x1b) <= j) break;
      (*(uint16_t *)((uint8_t *)&(frm))) =(uint16_t)( (frm_t *)ovr_stshRleSub(in_stack_00000004,(uint8_t *)src,sx,sy,ex,ey,21));
      pfStack_20 = (frm_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(frm) + 2)),(frm_t *)frm);
      ((frm_t *)frm)->type2 = 2;
      ((frm_t *)frm)->x = *(int16_t *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 0xb);
      ((frm_t *)frm)->y = *(int16_t *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 0xd);
      *(undefined2 *)((int)prev_next + 2) = (*(uint16_t *)((uint8_t *)&(frm) + 2));
      *(frm_t **)prev_next = (frm_t *)frm;
      prev_next = CONCAT22((*(uint16_t *)((uint8_t *)&(frm) + 2)),&((frm_t *)frm)->next);
      if ((*(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 0x1c) & 1) == 0) {
        ((frm_t *)frm)->ow = *(uint8_t *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 0xf);
      }
      else {
        row = ey * 0x140 + 0x140;
        if (j == 0) {
          count = 0;
          xx = sx;
          while (count < 2) {
            if (ex + row < xx) {
                    /* WARNING: Subroutine does not return */
              ovr_stExit(9);
            }
            if (*(char *)((int)&in_stack_00000004[ey * 0x50 + 0x50].ofs + xx) == -2) {
              if (count == 0) {
                sxx = xx;
              }
              else {
                exx = xx;
              }
              count = count + 1;
            }
            xx = xx + 1;
          }
          p_ow = CONCAT22((*(uint16_t *)((uint8_t *)&(frm) + 2)),&((frm_t *)frm)->ow);
        }
        else {
          for (xx = sx; *(char *)((int)&in_stack_00000004[ey * 0x50 + 0x50].ofs + xx) != -2;
              xx = xx + 1) {
            if (ex + row < xx) {
                    /* WARNING: Subroutine does not return */
              ovr_stExit(9);
            }
          }
          ((frm_t *)frm)->ow = (char)exx - (char)xx;
          exx = xx;
        }
      }
      pfStack_20->type4 = 4;
      *(undefined2 *)((int)&((frm_t *)frm)->next + 2) = 0;
      *(undefined2 *)&((frm_t *)frm)->next = 0;
      sy = sy + *(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 10);
      ey = ey + *(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 10);
      if (199 < ey) {
        sy = *(int *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 3) % (int)(uint)*(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 10);
        ey = sy + anim_height;
        sx = sx + *(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 9);
        ex = ex + *(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 9);
        sxx = sxx + *(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 9);
        exx = exx + *(byte *)((*(uint16_t *)((uint8_t *)&(src) + 2)) + i * 0x1e + 9);
      }
      j = j + 1;
    }
    if ((int)p_ow != 0 || (*(uint16_t *)((uint8_t *)&(p_ow) + 2)) != 0) {
      *(char *)p_ow = (char)exx - (char)sxx;
    }
    i = i + 1;
  }
  return (spr_t *)dst.ofs;
}
