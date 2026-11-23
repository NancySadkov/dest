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
  uint16_t uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = 0;
  while( true ) {
    if ((int)(uint)AgntCount <= iVar5) {
      return -1;
    }
    uVar1 = AGNT_WORD(&Agnts[iVar5], frames, 2);
    piVar4 = (int *)(AGNT_WORD(&Agnts[iVar5], frames, 0) + (uint)Agnts[iVar5].frameIndex * 4);
    iVar2 = piVar4[1];
    iVar3 = *piVar4;
    if (((((Agnts[iVar5].screenX - *(int *)(iVar3 + 0x17)) + -0xc <= x) &&
         (x <= Agnts[iVar5].screenX + *(int *)(iVar3 + 0x17) + -0xc)) &&
        ((Agnts[iVar5].screenY - *(int *)(iVar3 + 0xd)) + -7 <= y)) &&
       (y <= Agnts[iVar5].screenY + -7)) break;
    iVar5 = iVar5 + 1;
  }
  return iVar5;
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
  int iVar1;
  char *pcVar2;
  uint uStack_8;
  uint uStack_6;
  word wStack_4;
  
  iVar1 = 0;
  pcVar2 = (char *)0x0;
  wStack_4 = 0x140 - x;
  uStack_6 = 200 - y;
  if (0x11 < wStack_4) {
    wStack_4 = 0x11;
  }
  if (0x11 < uStack_6) {
    uStack_6 = 0x11;
  }
  for (uStack_8 = 0; uStack_8 < uStack_6; uStack_8 = uStack_8 + 1) {
    memcpy((char *)CONCAT22(0x224a,pcVar2),(char *)CONCAT22(srcSeg,(char *)(x + y * 0x140 + iVar1)),
           wStack_4);
    iVar1 = iVar1 + 0x140;
    pcVar2 = pcVar2 + 0x11;
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
  uint16_t uVar1;
  uint16_t uVar2;
  byte bVar3;
  int dst_x;
  int dst_y;
  uint16_t dx;
  uint16_t dy;
  far_t src;
  uint16_t px;
  uint16_t py;
  
  uVar2 = MiceX;
  uVar1 = MiceY;
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
      bVar3 = video_usesMiceUnkState();
      if ((((MiceProcessed == '\0') || (MiceX != uVar2)) || (MiceY != uVar1)) ||
         (bVar3 != MiceIndex)) {
        MiceFlag = 1;
        if (MiceProcessed != '\0') {
          dst_x = uVar2 - *(int *)(&MiceOfsX[MiceIndex]);
          dst_y = uVar1 - *(int *)(&MiceOfsY[MiceIndex]);
          if (dst_x < 0) {
            dst_x = 0;
          }
          if (dst_y < 0) {
            dst_y = 0;
          }
          miceBlitAtSeg(0xa000,far_from_u32((uint32_t)(0x224a0000)),dst_x,dst_y);
        }
        MiceIndex = (uint)bVar3;
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


