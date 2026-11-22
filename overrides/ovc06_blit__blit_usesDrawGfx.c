/* blit_usesDrawGfx - clipped RLE blit.  Local names come from the clip
   arithmetic: rectX/Y/W/H from the rectangle, clipX0/clipY0 =
   max(origin, rect), clipX1/clipY1 = min(rect edge, origin+size-1),
   xSkip = rectX - x, copyW/copyH = clipped run length, rowLen =
   ovr_unrle() result.  dstOfs/dstSeg and srcOfs/srcSeg are the video
   destination and the RLE source; unaff_SS stays because it is the stack
   segment used to address rowBuf. */
void __cdecl16far blit_usesDrawGfx(far_t gfx,int x,int y,brect_t *rect)

{
  far_t dst;
  far_t dst_00;
  int rowLen;
  uint16_t in_DX;
  brect_t *rectP;
  int row;
  uint16_t uVar4;
  uint16_t unaff_SS;
  far_t src;
  uint8_t rowBuf;
  int rectH;
  int rectW;
  int rectY;
  int rectX;
  uint16_t srcOfs;
  uint16_t srcSeg;
  char *dstOfs;
  uint16_t dstSeg;
  int copyH;
  word copyW;
  int xSkip;
  int clipY1;
  int clipX1;
  int clipY0;
  int clipX0;
  
  if (gfx.ofs != 0 || gfx.seg != 0) {
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) == '\0') {
      gfx.ofs = (uint16_t)ovr_stshLoadGfx(gfx);
      gfx.seg = in_DX;
    }
    if (*(char *)MK_FP(gfx.seg, gfx.ofs) != '\x01') {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x1a);
    }
    rectX = rect->x;
    uVar4 = (uint16_t)((ulong)rect >> 0x10);
    rectP = (brect_t *)rect;
    rectY = rectP->y;
    rectW = rectP->w;
    rectH = rectP->h;
    if ((((x < rectX) || (y < rectY)) || (rectW < x + *(int *)(gfx.ofs + 5) + -1)) ||
       (rectH < y + *(int *)(gfx.ofs + 7) + -1)) {
      if ((rectX <= x + *(int *)(gfx.ofs + 5) + -1) && (x <= rectW)) {
        if (x < rectX) {
          xSkip = rectX - x;
          clipX0 = rectX;
        }
        else {
          clipX0 = x;
          xSkip = 0;
        }
        clipX1 = rectW;
        if (x + *(int *)(gfx.ofs + 5) + -1 <= rectW) {
          clipX1 = x + *(int *)(gfx.ofs + 5) + -1;
        }
        copyW = (clipX1 - clipX0) + 1;
        clipY0 = rectY;
        if (rectY <= y) {
          clipY0 = y;
        }
        clipY1 = rectH;
        if (y + *(int *)(gfx.ofs + 7) + -1 <= rectH) {
          clipY1 = y + *(int *)(gfx.ofs + 7) + -1;
        }
        copyH = (clipY1 - y) + 1;
        dstOfs = (char *)(clipX0 + clipY0 * 0x140);
        dstSeg = rectP->seg;
        srcOfs = gfx.ofs + 9;
        srcSeg = gfx.seg;
        for (row = 0; (row < copyH && (row + y <= rectH)); row = row + 1) {
          src.seg = srcSeg;
          src.ofs = srcOfs;
          dst_00.seg = unaff_SS;
          dst_00.ofs = (uint16_t)&rowBuf;
          rowLen = ovr_unrle(src,dst_00,*(uint16_t *)(gfx.ofs + 5),(char)*(uint16_t *)(gfx.ofs + 5));
          srcOfs = srcOfs + rowLen;
          if (rectY <= row + y) {
            memcpy((char *)CONCAT22(dstSeg,dstOfs),
                   (char *)CONCAT22(unaff_SS,&rowBuf + xSkip),copyW);
            dstOfs = dstOfs + 0x140;
          }
        }
      }
    }
    else {
      dst.seg = rectP->seg;
      dst.ofs = x + y * 0x140;
      drawGfx(gfx,dst,false);
    }
  }
  return;
}
