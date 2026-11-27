/*
 * video.c - recovered from STRONG.EXE
 * memory block: 138e_TEXT_video
 * range: 13aa:000b - 13aa:0591
 * functions: 6
 */
#include "recovered.h"


/* 13aa:000b */

/* Returns 1 when the screen point (x,y) falls inside the region recorded for that column in the
   button table at 0x34c. */

uint16_t __cdecl16far video_pointInButton(int x,int y)

{
  uint16_t uVar1;
  
  if ((((y + 7U < *(uint *)((x + -0xc) * 2 + 0x34c)) &&
       (*(uint *)((x + -0xc) * 2 + 0x34c) <= y + 0x39U)) && (8 < x)) && (x < 0xc9)) {
    uVar1 = 0x1601;
  }
  else {
    uVar1 = 0x1600;
  }
  return uVar1;
}



/* 13aa:005b */

/* Returns the index of the first agent whose sprite bounds contain screen point (x,y), or -1. */

int __cdecl16far video_findAgentAt(int x,int y)

{
  /* Re-derived: the first agent whose frame rectangle contains (x,y), else -1.  The frame
     entry is a far pointer pair and only its offset half is read here, so the exporter's
     unused `AGNT_WORD(..., frames, 2)` word and the `piVar4[1]` segment are gone. */
  int agentIdx;
  int frameOfs;
  int *framePtr;

  agentIdx = 0;
  while( true ) {
    if ((int)(uint)AgntCount <= agentIdx) {
      return -1;
    }
    framePtr = (int *)(AGNT_WORD(&Agnts[agentIdx], frames, 0) +
                       (uint)Agnts[agentIdx].frameIndex * 4);
    frameOfs = *framePtr;
    if (((((Agnts[agentIdx].screenX - *(int *)(frameOfs + 0x17)) + -0xc <= x) &&
         (x <= Agnts[agentIdx].screenX + *(int *)(frameOfs + 0x17) + -0xc)) &&
        ((Agnts[agentIdx].screenY - *(int *)(frameOfs + 0xd)) + -7 <= y)) &&
       (y <= Agnts[agentIdx].screenY + -7)) break;
    agentIdx = agentIdx + 1;
  }
  return agentIdx;
}



/* 13aa:0165 */

/* [R6] touches MiceUnkState, MouseX */

uint8_t __cdecl16far video_usesMiceUnkState(void)

{
  uint8_t uVar1;
  int iVar2;
  uint16_t uVar3;
  
  if (MiceUnkState == '\0') {
    uVar1 = 0x0;
  }
  else if ((((MouseX < 0xc) || (0xde < MouseX)) || (MouseY < 7)) || (0x96 < MouseY)) {
    if (((MouseX < 0xef) || (0x134 < MouseX)) || ((MouseY < 7 || (0x36 < MouseY)))) {
      uVar1 = 0x0;
    }
    else {
      uVar1 = 0x3;
    }
  }
  else if (GOngoingBattle == '\0') {
    iVar2 = video_findAgentAt(MouseX - 0xc,MouseY - 7);
    if (iVar2 == -1) {
      uVar3 = video_pointInButton(MouseX - 0xc,MouseY - 7);
      if ((char)uVar3 == '\0') {
        uVar1 = 0x3;
      }
      else {
        uVar1 = 0x1;
      }
    }
    else {
      uVar1 = 0x2;
    }
  }
  else {
    uVar1 = 0x3;
  }
  return uVar1;
}



/* 13aa:0266 */

/* Copies up to a 17x17 pixel tile from the screen segment at (x,y) into the staging buffer at
   0x224a, clamped to the screen edges. */

void __cdecl16far video_copyScreenTile(uint16_t srcSeg,int x,int y)

{
  /* Re-derived: copies an at-most 17x17 tile from srcSeg:(x + y*0x140) to the 0x224a segment,
     0x11 apart per row, with a 0x140 row stride in the source. */
  int srcOfs;
  char *dstOfs;
  uint width;
  uint height;
  uint row;

  srcOfs = 0;
  dstOfs = (char *)0x0;
  width = 0x140 - x;
  height = 200 - y;
  if (0x11 < width) {
    width = 0x11;
  }
  if (0x11 < height) {
    height = 0x11;
  }
  for (row = 0; row < height; row = row + 1) {
    _fmemmove((char far *)MK_FP(0x224a,dstOfs),
           (char far *)MK_FP(srcSeg,(char *)(x + y * 0x140 + srcOfs)),width);
    srcOfs = srcOfs + 0x140;
    dstOfs = dstOfs + 0x11;
  }
  return;
}



/* 13aa:02ec */

void __cdecl16far miceBlitAtSeg(uint16_t dst_seg,far_t src,int16_t dst_x,int16_t dst_y)

{
  far_t src_00;
  uint16_t dofs;
  uint16_t sofs;
  far_t dst;
  uint16_t y;
  uint16_t h;
  uint16_t w;
  
  dofs = 0;
  sofs = 0;
  w = 0x140 - dst_x;
  h = 200 - dst_y;
  if (0x11 < w) {
    w = 0x11;
  }
  if (0x11 < h) {
    h = 0x11;
  }
  for (y = 0; y < h; y = y + 1) {
    src_00.seg = src.seg;
    src_00.ofs = src.ofs + sofs;
    dst.seg = dst_seg;
    dst.ofs = dst_x + dst_y * 0x140 + dofs;
    blitTillAlpha(dst,src_00,w);
    dofs = dofs + 0x140;
    sofs = sofs + 0x11;
  }
  return;
}



/* 13aa:0372 */

void __cdecl16far videoMiceEvent(uint16_t x,uint16_t y,uint16_t mask)

{
  uint16_t prevY;
  uint16_t prevX;
  byte shapeIdx;
  int dst_x;
  int dst_y;
  uint16_t dx;
  uint16_t dy;
  far_t src;
  
  prevX = MiceX;
  prevY = MiceY;
  if ((mask & 2) == 0) {
    if (MiceNeedsUpdate == '\0') {
      MiceNeedsUpdate = 1;
      MiceX = (int)x >> 1;
      MiceY = y;
      if ((int)MiceX < 0) {
        MiceX = 0;
      }
      if (0x13f < (int)MiceX) {
        MiceX = 0x13f;
      }
      if ((int)y < 0) {
        MiceY = 0;
      }
      if (199 < (int)MiceY) {
        MiceY = 199;
      }
      shapeIdx = video_usesMiceUnkState();
      if ((((MiceProcessed == '\0') || (MiceX != prevX)) || (MiceY != prevY)) ||
         (shapeIdx != MiceIndex)) {
        MiceFlag = 1;
        if (MiceProcessed != '\0') {
          dst_x = prevX - *(int *)(&MiceOfsX[MiceIndex]);
          dst_y = prevY - *(int *)(&MiceOfsY[MiceIndex]);
          if (dst_x < 0) {
            dst_x = 0;
          }
          if (dst_y < 0) {
            dst_y = 0;
          }
          miceBlitAtSeg(0xa000,far_from_u32((uint32_t)(0x224a0000)),dst_x,dst_y);
        }
        MiceIndex = (uint)shapeIdx;
        dx = MiceX - *(int *)(&MiceOfsX[MiceIndex]);
        dy = MiceY - *(int *)(&MiceOfsY[MiceIndex]);
        if ((int)dx < 0) {
          dx = 0;
        }
        if ((int)dy < 0) {
          dy = 0;
        }
        video_copyScreenTile(0xa000,dx,dy);
        src.seg = *(uint16_t *)((int)&MicePtrs.seg + MiceIndex * 4);
        src.ofs = ((far_t *)&MicePtrs + MiceIndex)->ofs;
        miceBlitAtSeg(0xa000,src,dx,dy);
        MiceProcessed = '\x01';
        MiceNeedsUpdate = '\0';
      }
      else {
        MiceNeedsUpdate = '\0';
      }
    }
  }
  else {
    MiceClickX = MiceX;
    MiceClickY = MiceY;
    MiceClick = 1;
  }
  return;
}


