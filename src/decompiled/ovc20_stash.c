/*
 * ovc20_stash.c - recovered from STRONG.EXE
 * memory block: OVC20_stash.c
 * range: 4b0a:0000 - 4b0a:1faf
 * functions: 23
 */
#include "recovered.h"


/* 4b0a:0000 */

/* Remaps unique colors, such as the those in portraits and biome skylines */

void __cdecl16far stshUniqueColorsRemap(stg_tmp_t *gfx,...)

{
  uint16_t si;
  uint16_t i;
  uint uVar1;
  undefined2 unaff_SS;
  char *in_stack_00000004;
  uint8_t cmap [769];
  uint8_t c;
  
  for (i = 0; i < 64000; i = i + 1) {
    c = *(byte *)((int)*(undefined4 *)(in_stack_00000004 + 0x300) + i);
    if ((c < 0x50) || (0x7f < c)) {
      if ((0x7f < c) && (c < 0xd0)) {
        c = c - 0x30;
      }
    }
    else {
      c = c + 0x50;
    }
    *(uint8_t *)((int)*(undefined4 *)(in_stack_00000004 + 0x300) + i) = c;
  }
  _fmemmove((char *)CONCAT22(unaff_SS,cmap),(char *)CONCAT22((stg_tmp_t *)gfx,in_stack_00000004),
            0x300);
  for (uVar1 = 0; uVar1 < 0x100; uVar1 = uVar1 + 1) {
    if ((uVar1 < 0x50) || (0x9f < uVar1)) {
      si = uVar1;
      if ((0x9f < uVar1) && (uVar1 < 0xd0)) {
        si = uVar1 - 0x50;
      }
    }
    else {
      si = uVar1 + 0x30;
    }
    in_stack_00000004[uVar1 * 3] = cmap[si * 3];
    in_stack_00000004[uVar1 * 3 + 1] = cmap[si * 3 + 1];
    in_stack_00000004[uVar1 * 3 + 2] = cmap[si * 3 + 2];
  }
  return;
}



/* 4b0a:010c */

/* [R2] string "uc%lx %d len %ld loc %ld \r" */

void __cdecl16far ovc20_textLenLoc(void)

{
  uint16_t *puVar1;
  uint16_t uStack_6;
  uint16_t uStack_4;
  
  uStack_4 = StshCtPtr2.seg;
  uStack_6 = StshCtPtr2.ofs;
  while (uStack_6 != 0 || uStack_4 != 0) {
    printf("uc%lx %d len %ld loc %ld \r");
    puVar1 = (uint16_t *)(uStack_6 + 0xb);
    uStack_6 = *(uint16_t *)(uStack_6 + 9);
    uStack_4 = *puVar1;
  }
  printf("N UP = %d \r");
  ovr_gameProcessKey();
  uStack_4 = Stsh_2410_47f6.seg;
  uStack_6 = Stsh_2410_47f6.ofs;
  while (uStack_6 != 0 || uStack_4 != 0) {
    printf("dc%lx %d ln %ld lc %ld @%lx \r");
    puVar1 = (uint16_t *)(uStack_6 + 0xf);
    uStack_6 = *(uint16_t *)(uStack_6 + 0xd);
    uStack_4 = *puVar1;
  }
  printf("N DOWN = %d \r");
  ovr_gameProcessKey();
  return;
}



/* 4b0a:01f8 */

/* Grabs LBM with transparency remap */

stg_tmp_t * __cdecl16far grabLbmTR(int16_t file_id,...)

{
  uint32_t r;
  undefined2 in_stack_00000004;
  far_t pixels;
  far_t pixels_00;
  
  (*(uint16_t *)((uint8_t *)&(r))) = ovr_grabLbm();
  pixels.seg = 0x14;
  pixels.ofs = (((stg_tmp_t *)r)->aptr).seg;
  ovr_grabRemap(pixels,0x0,(uint8_t)(stg_tmp_t *)r,(&((stg_tmp_t *)r)->aptr)->ofs);
  pixels_00.seg = 0xff;
  pixels_00.ofs = (((stg_tmp_t *)r)->aptr).seg;
  ovr_grabRemap(pixels_00,0x0,(uint8_t)(stg_tmp_t *)r,(&((stg_tmp_t *)r)->aptr)->ofs);
  return (stg_tmp_t *)r;
}



/* 4b0a:024e */

void __cdecl16far stgFreeTmp(stg_tmp_t *tg,...)

{
  uint16_t unaff_BP;
  int in_stack_00000004;
  far_t handle;
  far_t handle_00;
  
  handle.seg = unaff_BP;
  handle.ofs = *(uint16_t *)(in_stack_00000004 + 0x306);
  ovr_stshFree(handle,*(undefined2 *)(in_stack_00000004 + 0x304));
  handle_00.seg = handle.seg;
  handle_00.ofs = (uint16_t)(stg_tmp_t *)tg;
  ovr_stshFree(handle_00,in_stack_00000004);
  return;
}



/* 4b0a:0276 */

void __cdecl16far stubyBufSrcToDst(int src,int dst,...)

{
  uint16_t uVar1;
  uint16_t j;
  uint16_t i;
  int in_stack_00000004;
  
  for (i = 0; (int)i < 3; i = i + 1) {
    for (j = 0; (int)j < 3; j = j + 1) {
      uVar1 = ((far_t *)BldGfxNormal + j + (in_stack_00000004 + i) * 3)->ofs;
      *(undefined2 *)((int)&BldGfxNormal[0].seg + (src + i) * 0xc + j * 4) =
           *(undefined2 *)((int)&BldGfxNormal[0].seg + (in_stack_00000004 + i) * 0xc + j * 4);
      ((far_t *)BldGfxNormal + j + (src + i) * 3)->ofs = uVar1;
      uVar1 = ((far_t *)BldGfxRuin + j + (in_stack_00000004 + i) * 3)->ofs;
      *(undefined2 *)((int)&BldGfxRuin[0].seg + (src + i) * 0xc + j * 4) =
           *(undefined2 *)((int)&BldGfxRuin[0].seg + (in_stack_00000004 + i) * 0xc + j * 4);
      ((far_t *)BldGfxRuin + j + (src + i) * 3)->ofs = uVar1;
    }
  }
  return;
}



/* 4b0a:032c */

void __cdecl16far stshStubifyFromSrc(int src,int dst,...)

{
  uint16_t uVar1;
  uint16_t i;
  int in_stack_00000004;
  
  for (i = 0; (int)i < 3; i = i + 1) {
    uVar1 = ((far_t *)BldGfxNormal + i + in_stack_00000004 * 3)->ofs;
    *(undefined2 *)((int)&BldGfxNormal[0].seg + src * 0xc + i * 4) =
         *(undefined2 *)((int)&BldGfxNormal[0].seg + in_stack_00000004 * 0xc + i * 4);
    ((far_t *)BldGfxNormal + i + src * 3)->ofs = uVar1;
    uVar1 = ((far_t *)BldGfxRuin + i + in_stack_00000004 * 3)->ofs;
    *(undefined2 *)((int)&BldGfxRuin[0].seg + src * 0xc + i * 4) =
         *(undefined2 *)((int)&BldGfxRuin[0].seg + in_stack_00000004 * 0xc + i * 4);
    ((far_t *)BldGfxRuin + i + src * 3)->ofs = uVar1;
  }
  return;
}



/* 4b0a:03cd */

void __cdecl16far StubifyCopy1to0_alt(int index,...)

{
  uint16_t uVar1;
  int in_stack_00000004;
  
  uVar1 = ((far_t *)(BldGfxNormal + 1) + in_stack_00000004 * 3)->ofs;
  *(undefined2 *)((int)&BldGfxNormal[0].seg + in_stack_00000004 * 0xc) =
       *(undefined2 *)((int)&BldGfxNormal[1].seg + in_stack_00000004 * 0xc);
  ((far_t *)BldGfxNormal + in_stack_00000004 * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxNormal + 1) + in_stack_00000004 * 3)->ofs;
  *(undefined2 *)((int)&BldGfxNormal[2].seg + in_stack_00000004 * 0xc) =
       *(undefined2 *)((int)&BldGfxNormal[1].seg + in_stack_00000004 * 0xc);
  ((far_t *)(BldGfxNormal + 2) + in_stack_00000004 * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxRuin + 1) + in_stack_00000004 * 3)->ofs;
  *(undefined2 *)((int)&BldGfxRuin[0].seg + in_stack_00000004 * 0xc) =
       *(undefined2 *)((int)&BldGfxRuin[1].seg + in_stack_00000004 * 0xc);
  ((far_t *)BldGfxRuin + in_stack_00000004 * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxRuin + 1) + in_stack_00000004 * 3)->ofs;
  *(undefined2 *)((int)&BldGfxRuin[2].seg + in_stack_00000004 * 0xc) =
       *(undefined2 *)((int)&BldGfxRuin[1].seg + in_stack_00000004 * 0xc);
  ((far_t *)(BldGfxRuin + 2) + in_stack_00000004 * 3)->ofs = uVar1;
  return;
}



/* 4b0a:04a7 */

void __cdecl16far stshStubifyCopy1to0(int index,...)

{
  uint16_t uVar1;
  int in_stack_00000004;
  
  uVar1 = ((far_t *)(BldGfxNormal + 1) + in_stack_00000004 * 3)->ofs;
  *(undefined2 *)((int)&BldGfxNormal[0].seg + in_stack_00000004 * 0xc) =
       *(undefined2 *)((int)&BldGfxNormal[1].seg + in_stack_00000004 * 0xc);
  ((far_t *)BldGfxNormal + in_stack_00000004 * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxNormal + 1) + in_stack_00000004 * 3)->ofs;
  *(undefined2 *)((int)&BldGfxNormal[2].seg + in_stack_00000004 * 0xc) =
       *(undefined2 *)((int)&BldGfxNormal[1].seg + in_stack_00000004 * 0xc);
  ((far_t *)(BldGfxNormal + 2) + in_stack_00000004 * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxNormal + 4) + in_stack_00000004 * 3)->ofs;
  *(undefined2 *)((int)&BldGfxNormal[3].seg + in_stack_00000004 * 0xc) =
       *(undefined2 *)((int)&BldGfxNormal[4].seg + in_stack_00000004 * 0xc);
  ((far_t *)(BldGfxNormal + 3) + in_stack_00000004 * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxNormal + 4) + in_stack_00000004 * 3)->ofs;
  *(undefined2 *)((int)&BldGfxNormal[5].seg + in_stack_00000004 * 0xc) =
       *(undefined2 *)((int)&BldGfxNormal[4].seg + in_stack_00000004 * 0xc);
  ((far_t *)(BldGfxNormal + 5) + in_stack_00000004 * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxNormal + 7) + in_stack_00000004 * 3)->ofs;
  *(undefined2 *)((int)&BldGfxNormal[6].seg + in_stack_00000004 * 0xc) =
       *(undefined2 *)((int)&BldGfxNormal[7].seg + in_stack_00000004 * 0xc);
  ((far_t *)(BldGfxNormal + 6) + in_stack_00000004 * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxNormal + 7) + in_stack_00000004 * 3)->ofs;
  *(undefined2 *)((int)&BldGfxNormal[8].seg + in_stack_00000004 * 0xc) =
       *(undefined2 *)((int)&BldGfxNormal[7].seg + in_stack_00000004 * 0xc);
  ((far_t *)(BldGfxNormal + 8) + in_stack_00000004 * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxRuin + 1) + in_stack_00000004 * 3)->ofs;
  *(undefined2 *)((int)&BldGfxRuin[0].seg + in_stack_00000004 * 0xc) =
       *(undefined2 *)((int)&BldGfxRuin[1].seg + in_stack_00000004 * 0xc);
  ((far_t *)BldGfxRuin + in_stack_00000004 * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxRuin + 1) + in_stack_00000004 * 3)->ofs;
  *(undefined2 *)((int)&BldGfxRuin[2].seg + in_stack_00000004 * 0xc) =
       *(undefined2 *)((int)&BldGfxRuin[1].seg + in_stack_00000004 * 0xc);
  ((far_t *)(BldGfxRuin + 2) + in_stack_00000004 * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxRuin + 4) + in_stack_00000004 * 3)->ofs;
  *(undefined2 *)((int)&BldGfxRuin[3].seg + in_stack_00000004 * 0xc) =
       *(undefined2 *)((int)&BldGfxRuin[4].seg + in_stack_00000004 * 0xc);
  ((far_t *)(BldGfxRuin + 3) + in_stack_00000004 * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxRuin + 4) + in_stack_00000004 * 3)->ofs;
  *(undefined2 *)((int)&BldGfxRuin[5].seg + in_stack_00000004 * 0xc) =
       *(undefined2 *)((int)&BldGfxRuin[4].seg + in_stack_00000004 * 0xc);
  ((far_t *)(BldGfxRuin + 5) + in_stack_00000004 * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxRuin + 7) + in_stack_00000004 * 3)->ofs;
  *(undefined2 *)((int)&BldGfxRuin[6].seg + in_stack_00000004 * 0xc) =
       *(undefined2 *)((int)&BldGfxRuin[7].seg + in_stack_00000004 * 0xc);
  ((far_t *)(BldGfxRuin + 6) + in_stack_00000004 * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxRuin + 7) + in_stack_00000004 * 3)->ofs;
  *(undefined2 *)((int)&BldGfxRuin[8].seg + in_stack_00000004 * 0xc) =
       *(undefined2 *)((int)&BldGfxRuin[7].seg + in_stack_00000004 * 0xc);
  ((far_t *)(BldGfxRuin + 8) + in_stack_00000004 * 3)->ofs = uVar1;
  return;
}



/* 4b0a:0721 */

void __cdecl16far stshWriteFile(int fhandle,far_t buf,DW sz,...)

{
  int handle;
  uint16_t uVar1;
  uint16_t wrsz;
  bool bVar2;
  uint32_t pbuf;
  int in_stack_00000004;
  
  handle = in_stack_00000004;
  do {
    if ((0 < (int)sz.lo) || ((wrsz = buf.seg, -1 < (int)sz.lo && (0xbfff < buf.seg)))) {
      wrsz = 0xc000;
    }
    (*(uint16_t *)((uint8_t *)&(pbuf))) = ovr_mkp();
    uVar1 = (*(uint16_t *)((uint8_t *)&(pbuf) + 2));
    write(handle,(uint32_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(pbuf) + 2)),(uint32_t *)pbuf),wrsz);
    bVar2 = buf.seg < wrsz;
    buf.seg = buf.seg - wrsz;
    buf.ofs = (*(uint16_t *)((uint8_t *)&(pbuf) + 2));
    sz.lo = sz.lo - bVar2;
    sz.hi = 0;
    (*(uint16_t *)((uint8_t *)&(pbuf) + 2)) = uVar1;
  } while (buf.seg != 0 || sz.lo != 0);
  return;
}



/* 4b0a:077a */

void __cdecl16far stshReadFile(int handle,far_t dst,DW nbytes,...)

{
  int fd;
  uint16_t uVar1;
  uint uVar2;
  uint unaff_DI;
  bool bVar3;
  far_t pdst;
  int in_stack_00000004;
  
  fd = in_stack_00000004;
  do {
    if ((0 < (int)nbytes.lo) || ((uVar2 = dst.seg, -1 < (int)nbytes.lo && (0xbfff < dst.seg)))) {
      uVar2 = 0xc000;
    }
    ovr_mkp();
    uVar1 = pdst.seg;
    read(fd,(void *)CONCAT22(uVar2,pdst.seg),unaff_DI);
    bVar3 = dst.seg < uVar2;
    dst.seg = dst.seg - uVar2;
    dst.ofs = pdst.seg;
    nbytes.lo = nbytes.lo - bVar3;
    nbytes.hi = 0;
    pdst.seg = uVar1;
  } while (dst.seg != 0 || nbytes.lo != 0);
  return;
}



/* 4b0a:07d3 */

/* anms points to the array 0x1e sized anim_t entries,
   the last entry has nframes == 0
   the seq can have upto nanims total
   the function returns array of anim file stubs */

spr_t * __cdecl16far stshSpriteStub(anm_t *anms,uint16_t nanims,...)

{
  uint16_t k;
  uint16_t psrc;
  uint16_t pd;
  int iVar1;
  uint16_t unaff_SI;
  uint16_t j;
  uint16_t unaff_DI;
  uint16_t i;
  uint16_t ssrc;
  far_t dst;
  far_t pstub;
  int in_stack_00000004;
  uint16_t pdst;
  uint16_t sdst;
  
  if (StshSprIndex < 0x4f) {
    dst.seg = (uint16_t)((spr_t *)StshSprites + StshSprIndex);
    StshSprIndex = StshSprIndex + 1;
    dst.ofs = (uint16_t)ovr_mkp((*(uint16_t *)((uint8_t *)&(StshSprites) + 2)),unaff_DI,unaff_SI,dst.seg);
    _fsetmem((void *)CONCAT22(dst.seg,dst.ofs),0xb0,0);
    i = 0;
    while ((i < (*(uint16_t *)((uint8_t *)&(anms) + 2)) && (*(char *)(in_stack_00000004 + i * 0x1e + 0x1b) != '\0'))) {
      k = (uint16_t)*(byte *)(in_stack_00000004 + i * 0x1e);
      pd = dst.ofs + k * 4;
      *(undefined2 *)(pd + 2) = (anm_t *)anms;
      *(uint16_t *)pd = in_stack_00000004 + i * 0x1e;
      for (j = 0; pstub.seg = (uint16_t)((ulong)((long)(int)i * 0x1e) >> 0x10),
          j < *(byte *)(in_stack_00000004 + (int)((long)(int)i * 0x1e) + 0x1b); j = j + 1) {
        if (j == 0) {
          pstub.ofs = (uint16_t)ovr_stshAllocStub();
          iVar1 = dst.ofs + k * 4;
          *(uint16_t *)(iVar1 + 0x5a) = pstub.seg;
          *(uint16_t *)(iVar1 + 0x58) = pstub.ofs;
        }
        else {
          ovr_stshAllocStub();
        }
      }
      i = i + 1;
    }
    return (spr_t *)dst.ofs;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(unaff_DI,0x36);
}



/* 4b0a:08ee */

/* Allocates a size-rounded block while the archive allocation counter is below 0xd93. */

undefined1 * __cdecl16far ovc20_allocBlock(far_t buf,DW sz)

{
  DW sz_00;
  far_t ptr_ofs;
  far_t buf_00;
  uint16_t uVar1;
  uint32_t *puVar2;
  uint16_t unaff_BP;
  bool bVar3;
  far_t fVar4;
  undefined2 in_stack_00000000;
  undefined2 in_stack_00000002;
  uint16_t uVar5;
  uint16_t in_stack_0000fffa;
  long *in_stack_0000fffc;
  
  if (StshCount < 0xd93) {
    StshCount = StshCount + 1;
    LXMUL_at_(in_stack_0000fffc,CONCAT22(in_stack_00000000,unaff_BP),
              CONCAT22(buf.ofs,in_stack_00000002));
    uVar5 = 0x1000;
    fVar4.seg = in_stack_0000fffa;
    fVar4.ofs = 0x1000;
    ptr_ofs.seg = unaff_BP;
    ptr_ofs.ofs = (uint16_t)in_stack_0000fffc;
    fVar4 = PADD_at_(fVar4,ptr_ofs);
    fVar4.seg = fVar4.seg;
    puVar2 = ovr_mkp();
    *(uint16_t *)((int)puVar2 + 7) = sz.hi;
    *(uint16_t *)((int)puVar2 + 5) = sz.lo;
    *(undefined1 *)CONCAT22(fVar4.seg,puVar2) = 0;
    uVar1 = StshCtOfs.lo;
    *(uint16_t *)((int)puVar2 + 3) = StshCtOfs.hi;
    *(uint16_t *)((int)puVar2 + 1) = uVar1;
    *(undefined2 *)((int)puVar2 + 0x13) = 0;
    *(undefined2 *)((int)puVar2 + 0x11) = 0;
    bVar3 = CARRY2(StshCtOfs.lo,sz.lo);
    StshCtOfs.lo = StshCtOfs.lo + sz.lo;
    StshCtOfs.hi = StshCtOfs.hi + sz.hi + (uint)bVar3;
    *(undefined2 *)((int)puVar2 + 0xb) = 0;
    *(undefined2 *)((int)puVar2 + 9) = 0;
    *(undefined2 *)((int)puVar2 + 0xf) = 0;
    *(undefined2 *)((int)puVar2 + 0xd) = 0;
    buf_00.seg = sz.lo;
    buf_00.ofs = buf.seg;
    sz_00.hi = uVar5;
    sz_00.lo = sz.hi;
    stshWriteFile(buf.ofs,buf_00,sz_00,StshFile);
    ovr_stshFree();
    return (undefined1 *)puVar2;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(in_stack_0000fffa,0x24);
}



/* 4b0a:09ce */

/* WARNING: Variable defined which should be unmapped: sz */

cte_t * __cdecl16far stshStoreFile(uint8_t *data,...)

{
  far_t ptr_ofs;
  uint16_t uVar1;
  uint uVar2;
  cte_t *psVar4;
  undefined2 unaff_BP;
  bool bVar4;
  far_t fVar5;
  undefined2 in_stack_00000000;
  cte_t *in_stack_00000004;
  DW sz;
  uint16_t in_stack_0000fffa;
  undefined2 in_stack_0000fffc;
  uint16_t ofs_lo;
  uint16_t uVar3;
  
  uVar2 = (uint)((cte_t *)CONCAT22((uint8_t *)data,in_stack_00000004))->state;
  if (5 < uVar2) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(sz.lo,0x18);
  }
                    /* WARNING: Switch is manually overridden */
  switch((undefined4)*(undefined2 *)(uVar2 * 2 + 0xb69)) {
  case 0x4ba94:
    return in_stack_00000004;
  case 0x4ba9d:
    uVar2 = (&in_stack_00000004->ofs)->lo;
    sz.lo = uVar2 + 9;
    sz.hi = (in_stack_00000004->ofs).hi + (uint)(0xfff6 < uVar2);
    break;
  case 0x4bab6:
    uVar2 = *(uint *)((int)&(in_stack_00000004->sz).lo + 1);
    sz.lo = uVar2 + 0xe;
    sz.hi = *(int *)((int)&(in_stack_00000004->sz).hi + 1) + (uint)(0xfff1 < uVar2);
    break;
  case 0x4bacf:
    sz.lo = (&in_stack_00000004->sz)->lo + 0xd;
    sz.hi = 0;
    break;
  case 0x4bae3:
    sz.lo = *(uint *)(in_stack_00000004->info + 3) + 0x14;
    sz.hi = *(int *)(in_stack_00000004->info + 5) +
            (uint)(0xffeb < *(uint *)(in_stack_00000004->info + 3));
  }
  if (StshCount < 0xd93) {
    StshCount = StshCount + 1;
    LXMUL_at_((long *)sz.hi,CONCAT22(in_stack_0000fffc,in_stack_0000fffa),
              CONCAT22(in_stack_00000000,unaff_BP));
    fVar5.seg = sz.lo;
    fVar5.ofs = 0x1000;
    ptr_ofs.seg = in_stack_0000fffa;
    ptr_ofs.ofs = sz.hi;
    fVar5 = PADD_at_(fVar5,ptr_ofs);
    uVar3 = fVar5.seg;
    psVar4 = (cte_t *)ovr_mkp();
    (psVar4->sz).hi = sz.hi;
    (&psVar4->sz)->lo = sz.lo;
    ((cte_t *)CONCAT22(uVar3,psVar4))->state = 0x0;
    uVar1 = StshCtOfs.lo;
    (psVar4->ofs).hi = StshCtOfs.hi;
    (&psVar4->ofs)->lo = uVar1;
    (psVar4->info + 10)[0] = 0x0;
    (psVar4->info + 10)[1] = 0x0;
    (psVar4->info + 8)[0] = 0x0;
    (psVar4->info + 8)[1] = 0x0;
    bVar4 = CARRY2(StshCtOfs.lo,sz.lo);
    StshCtOfs.lo = StshCtOfs.lo + sz.lo;
    StshCtOfs.hi = StshCtOfs.hi + sz.hi + (uint)bVar4;
    (psVar4->info + 2)[0] = 0x0;
    (psVar4->info + 2)[1] = 0x0;
    psVar4->info[0] = 0x0;
    psVar4->info[1] = 0x0;
    (psVar4->info + 6)[0] = 0x0;
    (psVar4->info + 6)[1] = 0x0;
    (psVar4->info + 4)[0] = 0x0;
    (psVar4->info + 4)[1] = 0x0;
    if (DebugVerbose != false) {
      printf("type %d len %ld \r");
      ovr_biosReadKey();
    }
    stshWriteFile();
    ovr_stshFree();
    return psVar4;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(sz.lo,0x24);
}



/* 4b0a:0b75 */

uint16_t __cdecl16far stshDecVocSampleRate(uint8_t encfreq)

{
  long lVar1;
  
  lVar1 = LDIV_at_(1000000,(long)(int)(0x100 - (uint)encfreq));
  return (uint16_t)lVar1;
}



/* 4b0a:0b9c */

/* WARNING: Variable defined which should be unmapped: voc */

void __cdecl16far stshInitAudioAssets(char grab,...)

{
  undefined1 uVar1;
  char *pcVar2;
  long *plVar3;
  uint16_t freq;
  uint32_t *puVar4;
  void *pvVar5;
  cte_t *pcVar7;
  far_t *pfVar8;
  uint uVar9;
  uint uVar10;
  int in_DX;
  int iVar11;
  undefined2 *puVar12;
  uint uVar13;
  int iVar14;
  uint16_t unaff_SI;
  uint16_t i;
  uint32_t *unaff_DI;
  undefined2 uVar15;
  bool bVar16;
  char in_stack_00000004;
  uint8_t uVar17;
  undefined1 uVar18;
  voc_t voc;
  uint uStack_a;
  uint uStack_8;
  uint32_t sz;
  uint16_t uVar6;
  
  AudioAssetsReady1 = 1;
  AudioAssetsReady2 = 1;
  uStack_8 = 0;
  uStack_a = 0;
  i = 0;
  do {
                    /* ;0x90 = total .xmi and .voc files */
    if (0x89 < (int)i) {
      return;
    }
    puVar12 = (undefined2 *)(*(int *)(i * 2) * 4);
    pcVar2 = _fstrstr((char *)CONCAT22(puVar12[1],(char *)*puVar12),".xmi");
    if (pcVar2 == (char *)0x0 && in_DX == 0) {
      *(undefined2 *)(i * 2 + 0x114) = 1;
    }
    else {
      *(undefined2 *)(i * 2 + 0x114) = 0;
    }
    if (in_stack_00000004 == '\0') {
      pfVar8 = ovr_stshAllocStub();
      ((undefined2 *)(i * 4))[1] = in_DX;
      *(undefined2 *)(i * 4) = pfVar8;
      iVar11 = in_DX;
    }
    else {
      if (*(int *)(i * 2 + 0x114) == 0) {
        puVar4 = ovr_stshFilesize(unaff_DI,unaff_SI,(char)*(undefined2 *)(i * 2));
        iVar11 = (int)puVar4 + 0xd;
        pvVar5 = ovr_stshAlloc(CONCAT22(unaff_DI,in_DX + (uint)((uint32_t *)0xfff2 < puVar4)),iVar11
                              );
        ((undefined2 *)(i * 4))[1] = iVar11;
        *(undefined2 *)(i * 4) = pvVar5;
        *(undefined1 *)*(undefined4 *)(i << 2) = 3;
        uVar15 = (undefined2)((ulong)*(undefined4 *)(i << 2) >> 0x10);
        iVar14 = (int)*(undefined4 *)(i << 2);
        *(undefined2 *)(iVar14 + 3) = 0;
        *(undefined2 *)(iVar14 + 1) = 0;
        *(undefined2 *)((int)*(undefined4 *)(i << 2) + 5) = puVar4;
        uVar6 = ovr_stshOpen((uint16_t)unaff_DI,(char)*(undefined2 *)(i * 2));
        uVar1 = (undefined1)uVar6;
        iVar14 = ovr_stshRead();
        if (iVar14 != 0 || iVar11 != 0) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit((int)unaff_DI,0x20);
        }
        *(undefined2 *)((int)*(undefined4 *)(i << 2) + 0xb) = 0;
      }
      else {
        uVar6 = ovr_stshOpen((uint16_t)unaff_DI,(char)*(undefined2 *)(i * 2));
        uVar1 = (undefined1)uVar6;
        iVar11 = ovr_stshRead();
        if (iVar11 != 0 || in_DX != 0) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit((int)unaff_DI,0x20);
        }
        uVar18 = 0;
        iVar14 = 0;
        iVar11 = 0;
        uVar17 = voc.blksz[0];
        plVar3 = LXLSH_at_((long *)(uint)voc.blksz[0],(long)CONCAT22(unaff_SI,unaff_DI),voc.id[0]);
        uVar9 = CONCAT11(uVar18,uVar17) + (int)plVar3;
        uVar10 = uVar9 - 2;
        uVar13 = (iVar14 + iVar11 + (uint)CARRY2(CONCAT11(uVar18,uVar17),(uint)plVar3) +
                 (uint)voc.blksz[2]) - (uint)(uVar9 < 2);
        iVar11 = uVar9 + 0xb;
        pvVar5 = ovr_stshAlloc(CONCAT22(unaff_DI,uVar13 + (0xfff2 < uVar10)),iVar11);
        ((undefined2 *)(i * 4))[1] = iVar11;
        *(undefined2 *)(i * 4) = pvVar5;
        *(undefined1 *)*(undefined4 *)(i << 2) = 3;
        uVar15 = (undefined2)((ulong)*(undefined4 *)(i << 2) >> 0x10);
        iVar11 = (int)*(undefined4 *)(i << 2);
        *(undefined2 *)(iVar11 + 3) = 0;
        *(undefined2 *)(iVar11 + 1) = 0;
        *(uint *)((int)*(undefined4 *)(i << 2) + 5) = uVar10;
        if ((uStack_8 <= uVar13) && ((uVar13 != uStack_8 || (uStack_a <= uVar10)))) {
          bVar16 = 0xfff2 < uVar10;
          uVar10 = uVar9 + 0xb;
          uStack_8 = uVar13 + bVar16;
          uStack_a = uVar10;
        }
        iVar11 = ovr_stshRead();
        if (iVar11 != 0 || uVar10 != 0) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit((int)unaff_DI,0x20);
        }
        freq = stshDecVocSampleRate(voc.freq);
        iVar11 = 0x1703;
        *(uint16_t *)((int)*(undefined4 *)(i << 2) + 0xb) = freq;
      }
      ovr_stshClose((uint16_t)unaff_DI,uVar1);
      pcVar7 = stshStoreFile((uint8_t *)CONCAT22(unaff_DI,(uint8_t *)((undefined2 *)(i * 4))[1]),
                             *(undefined2 *)(i * 4));
      ((undefined2 *)(i * 4))[1] = iVar11;
      *(undefined2 *)(i * 4) = pcVar7;
    }
    i = i + 1;
    in_DX = iVar11;
  } while( true );
}



/* 4b0a:0eda */

/* duplicate name, disambiguated by address order */

long * __cdecl16far stshAlloc_2(long *__return_storage_ptr__,DW sz)

{
  far_t ptr_ofs;
  uint32_t *puVar1;
  uint16_t unaff_BP;
  bool bVar2;
  far_t fVar3;
  undefined2 in_stack_00000000;
  long in_stack_00000002;
  uint uVar4;
  uint16_t uVar5;
  uint16_t in_stack_0000fffa;
  long *in_stack_0000fffc;
  
  if (StshCount < 0xd93) {
    StshCount = StshCount + 1;
    LXMUL_at_(in_stack_0000fffc,CONCAT22(in_stack_00000000,unaff_BP),in_stack_00000002);
    uVar4 = (uint)((ulong)in_stack_00000002 >> 0x10);
    uVar5 = 0x1000;
    fVar3.seg = in_stack_0000fffa;
    fVar3.ofs = 0x1000;
    ptr_ofs.seg = unaff_BP;
    ptr_ofs.ofs = (uint16_t)in_stack_0000fffc;
    fVar3 = PADD_at_(fVar3,ptr_ofs);
    fVar3.seg = (uint32_t *)fVar3.seg;
    puVar1 = ovr_mkp(fVar3.seg,uVar5,in_stack_0000fffa,fVar3.ofs);
    *(undefined2 *)((int)puVar1 + 7) = __return_storage_ptr__;
    *(uint *)((int)puVar1 + 5) = uVar4;
    *(undefined1 *)CONCAT22(fVar3.seg,puVar1) = 0;
    uVar5 = StshCtOfs.lo;
    *(uint16_t *)((int)puVar1 + 3) = StshCtOfs.hi;
    *(uint16_t *)((int)puVar1 + 1) = uVar5;
    *(undefined2 *)((int)puVar1 + 0x13) = 0;
    *(undefined2 *)((int)puVar1 + 0x11) = 0;
    bVar2 = CARRY2(StshCtOfs.lo,uVar4);
    StshCtOfs.lo = StshCtOfs.lo + uVar4;
    StshCtOfs.hi = (int)__return_storage_ptr__ + bVar2 + StshCtOfs.hi;
    *(undefined2 *)((int)puVar1 + 0xb) = 0;
    *(undefined2 *)((int)puVar1 + 9) = 0;
    *(undefined2 *)((int)puVar1 + 0xf) = 0;
    *(undefined2 *)((int)puVar1 + 0xd) = 0;
    return (long *)puVar1;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(in_stack_0000fffa,0x24);
}



/* 4b0a:0f95 */

uint32_t * __cdecl16far stshWrite(uint32_t *__return_storage_ptr__,uint8_t *data,long sz,...)

{
  uint32_t *puVar1;
  uint16_t unaff_BP;
  DW sz_00;
  uint16_t in_stack_00000000;
  int in_stack_00000004;
  far_t buf;
  DW sz_01;
  
  if (data == (uint8_t *)0x0 && (long *)sz == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit();
  }
  sz_01.hi = unaff_BP;
  sz_01.lo = (uint16_t)(long *)sz;
  buf.seg = (uint16_t)data;
  buf.ofs = (uint16_t)__return_storage_ptr__;
  stshWriteFile(in_stack_00000004,buf,sz_01,StshFile);
  sz_00.lo = sz_01.hi;
  sz_00.hi = in_stack_00000000;
  puVar1 = (uint32_t *)stshAlloc_2((long *)sz,sz_00);
  return puVar1;
}



/* 4b0a:0fd0 */

/* duplicate name, disambiguated by address order */

far_t * __cdecl16far stshStoreFile_2(far_t *__return_storage_ptr__,char *filename,uint16_t flag)

{
  far_t buf;
  far_t handle;
  DW sz;
  int fd;
  far_t *pfVar1;
  long *in_DX;
  uint16_t unaff_SI;
  uint v;
  long *unaff_DI;
  uint16_t pbuf;
  long *plStack_c;
  uint16_t len;
  long *plStack_8;
  
  fd = ovr_open_wait_unlock_and_disk();
  if (-1 < fd) {
    plStack_c = filelength(unaff_DI,unaff_SI);
    len = (uint16_t)plStack_c;
    plStack_8 = in_DX;
    if ((char)filename != '\0') {
      len = (int)plStack_c + 0xf;
      plStack_8 = (long *)((int)in_DX + (uint)((long *)0xfff0 < plStack_c));
    }
    sz.hi = unaff_SI;
    sz.lo = (uint16_t)unaff_DI;
    pfVar1 = (far_t *)stshAlloc_2(plStack_8,sz);
    if (((int)plStack_8 < 0) || ((plStack_8 == (long *)0x0 && (len < 0xc000)))) {
      pbuf = (uint16_t)ovr_stshAlloc((uint32_t)CONCAT22(unaff_DI,plStack_8),len);
    }
    else {
      pbuf = (uint16_t)ovr_stshAlloc(ZEXT24(unaff_DI) << 0x10,0xc000);
    }
    for (; len != 0 || plStack_8 != (long *)0x0; len = len - v) {
      v = len;
      if ((-1 < (int)plStack_8) && ((plStack_8 != (long *)0x0 || (0xbfff < len)))) {
        v = 0xc000;
      }
      _fmemset((void *)ZEXT24(plStack_c),v,(uint16_t)unaff_DI);
      read(fd,(long *)CONCAT22(v,plStack_c),(uint)unaff_DI);
      buf.seg = v;
      buf.ofs = (uint16_t)plStack_c;
      stshWriteFile(pbuf,buf,(DW)(ZEXT24(unaff_DI) << 0x10),StshFile);
      plStack_8 = (long *)((int)plStack_8 - (uint)(len < v));
    }
    close(fd);
    handle.seg = (uint16_t)unaff_DI;
    handle.ofs = (uint16_t)plStack_c;
    ovr_stshFree(handle,pbuf);
    return pfVar1;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit((int)unaff_DI,0x23);
}



/* 4b0a:10ea */

void __cdecl16far init_special_graphics(char *gfxBlock)

{
  far_t handle;
  
  if (*(int *)((char *)gfxBlock + 0x11) != 0 || *(int *)((char *)gfxBlock + 0x13) != 0) {
    handle.seg = (uint16_t)(char *)gfxBlock;
    handle.ofs = *(uint16_t *)((char *)gfxBlock + 0x13);
    ovr_stshFree(handle,*(undefined2 *)((char *)gfxBlock + 0x11));
    ((char *)gfxBlock + 0x13)[0] = '\0';
    ((char *)gfxBlock + 0x13)[1] = '\0';
    ((char *)gfxBlock + 0x11)[0] = '\0';
    ((char *)gfxBlock + 0x11)[1] = '\0';
  }
  return;
}



/* 4b0a:112d */

/* [R7] body shape: compute */

void __cdecl16far ovc20_compute1(char *gfxBlock,...)

{
  int in_stack_00000004;
  
  *(undefined2 *)(in_stack_00000004 + 0x13) = 0;
  *(undefined2 *)(in_stack_00000004 + 0x11) = 0;
  return;
}



/* 4b0a:1150 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far init_ui_gfxes(void)

{
  undefined2 uVar1;
  far_t handle;
  far_t handle_00;
  far_t ptr;
  far_t handle_01;
  far_t hndl;
  far_t hndl_00;
  far_t hndl_01;
  uint16_t uVar2;
  far_t *pfVar3;
  void *pvVar4;
  far_t *in_DX;
  far_t *pfVar5;
  uint16_t unaff_SI;
  uint16_t i;
  uint16_t unaff_DI;
  uint8_t *unaff_SS;
  uint8_t colour;
  uint8_t palette;
  stg_tmp_t *psStack_e;
  stg_tmp_t *psStack_a;
  void *pvStack_6;
  far_t *pfStack_4;
  
  handle.seg = unaff_DI;
  handle.ofs = Lbm_nwpanel1.seg;
  psStack_a = ovr_stshLoadGfx(handle,Lbm_nwpanel1.ofs);
  uVar2 = ovr_calcSeasonPalette();
  init_special_graphics((char *)CONCAT13((char)((uint)in_DX >> 8),CONCAT12((char)in_DX,uVar2)));
  ovr_vgaSetPalette8bit((uint8_t *)CONCAT22(unaff_DI,unaff_SS),&palette);
  init_special_graphics
            ((char *)CONCAT13((char)(Lbm_nwpanel1.seg >> 8),
                              CONCAT12((char)Lbm_nwpanel1.seg,Lbm_nwpanel1.ofs)));
  handle_00.seg = unaff_DI;
  handle_00.ofs = specialColorsSeg;
  psStack_e = ovr_stshLoadGfx(handle_00,specialColorsOfs);
  memcpy((char *)SpecialColors,(char *)CONCAT22(in_DX,psStack_e),8);
  init_special_graphics
            ((char *)CONCAT13((char)(specialColorsSeg >> 8),
                              CONCAT12((char)specialColorsSeg,specialColorsOfs)));
  pvStack_6 = ovr_stshAlloc((ulong)unaff_DI << 0x10,0xfa0f);
  ptr.seg = unaff_DI;
  ptr.ofs = (uint16_t)in_DX;
  pfStack_4 = in_DX;
  ovr_alignToSeg(ptr,pvStack_6);
  colour = (uint8_t)in_DX;
  pfVar5 = in_DX;
  ovr_driver_fillRect(0,0x13f,199,0,colour,unaff_DI,0,colour);
  ovr_blitLoadRleGfx();
  init_special_graphics
            ((char *)CONCAT13((char)((uint)gamfont1Cut1Seg >> 8),
                              CONCAT12((char)gamfont1Cut1Seg,gamfont1Cut1Ofs)));
  hndl.seg = unaff_SI;
  hndl.ofs = unaff_DI;
  Font03.ofs = (uint16_t)ovr_stshProcessFontSub(in_DX,hndl,0);
  Font03.seg = (uint16_t)pfVar5;
  ovr_driver_fillRect(0,0x13f,199,0,colour,unaff_DI,0,colour);
  ovr_blitLoadRleGfx();
  init_special_graphics
            ((char *)CONCAT13((char)((uint)davfontCut1Seg >> 8),
                              CONCAT12((char)davfontCut1Seg,davfontCut1Ofs)));
  hndl_00.seg = unaff_SI;
  hndl_00.ofs = unaff_DI;
  Font02.ofs = (uint16_t)ovr_stshProcessFontSub(in_DX,hndl_00,0);
  Font02.seg = (uint16_t)pfVar5;
  ovr_driver_fillRect(0,0x13f,199,0,colour,unaff_DI,0,colour);
  ovr_blitLoadRleGfx();
  init_special_graphics
            ((char *)CONCAT13((char)((uint)davfont2Cut1Seg >> 8),
                              CONCAT12((char)davfont2Cut1Seg,_davfont2Cut1Ofs)));
  hndl_01.seg = unaff_SI;
  hndl_01.ofs = unaff_DI;
  pfVar3 = ovr_stshProcessFontSub(in_DX,hndl_01,0);
  FontMain.ofs = (uint16_t)pfVar3;
  FontMain.seg = (uint16_t)pfVar5;
  Font01.ofs = (uint16_t)pfVar3;
  Font01.seg = (uint16_t)pfVar5;
  for (i = 0; (int)i < 4; i = i + 1) {
    ovr_driver_fillRect(0,0x11,0x11,0,colour,unaff_DI,0,colour);
    ovr_blitLoadRleGfx();
    uVar1 = *(undefined2 *)((int)&MiceCursors[0].seg + i * 4);
    init_special_graphics
              ((char *)CONCAT13((char)((uint)uVar1 >> 8),
                                CONCAT12((char)uVar1,((far_t *)MiceCursors + i)->ofs)));
    video_copyScreenTile((uint16_t)in_DX,0,0);
    pvVar4 = ovr_stshAlloc((ulong)unaff_DI << 0x10,0x121);
    *(undefined2 *)((int)&MicePtrs.seg + i * 4) = pfVar3;
    ((far_t *)&MicePtrs + i)->ofs = (uint16_t)pvVar4;
    memcpy((char *)CONCAT22(*(undefined2 *)((int)&MicePtrs.seg + i * 4),
                            (char *)((far_t *)&MicePtrs + i)->ofs),(char *)MiceSaveArea,0x121);
  }
  handle_01.seg = unaff_DI;
  handle_01.ofs = (uint16_t)pfStack_4;
  ovr_stshFree(handle_01,pvStack_6);
  return;
}



/* 4b0a:13d3 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far stshLoadAudioDrivers(bool grab,...)

{
  far_t *pfVar1;
  uint16_t in_DX;
  far_t *pfVar2;
  uint16_t unaff_BP;
  char in_stack_00000004;
  
  if (in_stack_00000004 == '\0') {
    midpakAd.ofs = (uint16_t)ovr_stshAllocStub();
    midpakAd.seg = in_DX;
    cmidpakComOfs = ovr_stshAllocStub();
    _cmidpakComSeg = in_DX;
    ibmsndComOfs = ovr_stshAllocStub();
    ibmsndComSeg = in_DX;
    sblasterComOfs = ovr_stshAllocStub();
    audioPlaceholder2.seg = 0;
    audioPlaceholder2.ofs = 0;
    sblasterComSeg = in_DX;
    fibmbakComOfs = ovr_stshAllocStub();
    fibmbakComSeg = in_DX;
    pfVar1 = ovr_stshAllocStub();
    sbproComOfs = pfVar1;
    sbproComSeg = in_DX;
    sbproComCopyOfs = pfVar1;
    sbproComCopySeg = in_DX;
    paudioComOfs = ovr_stshAllocStub();
    sblasterComCopySeg = sblasterComSeg;
    sblasterComCopyOfs = sblasterComOfs;
    pfVar2 = sblasterComOfs;
    paudioComSeg = pfVar1;
    adlibComOfs = ovr_stshAllocStub();
    adlibComSeg = pfVar2;
    adlibgComOfs = ovr_stshAllocStub();
    audioPlaceholder3.seg = 0;
    audioPlaceholder3.ofs = 0;
    musDriver0Seg = 0;
    musDriver0Ofs = 0;
    adlibgComSeg = pfVar2;
    sbfmAdvOfs = ovr_stshAllocStub();
    audioPlaceholder0.seg = 0;
    audioPlaceholder0.ofs = 0;
    audioPlaceholder1.seg = 0;
    audioPlaceholder1.ofs = 0;
    sbfmAdvSeg = pfVar2;
    sbp2fmAdvOfs = ovr_stshAllocStub();
    sbp2fmAdvSeg = pfVar2;
    sbp1fmAdvOfs = ovr_stshAllocStub();
    sbp1fmAdvSeg = pfVar2;
    pasfmAdvOfs = ovr_stshAllocStub();
    pasfmAdvSeg = pfVar2;
    pasoplAdvOfs = ovr_stshAllocStub();
    pasoplAdvSeg = pfVar2;
    adlibAdvOfs = ovr_stshAllocStub();
    adlibAdvSeg = pfVar2;
    adlibgAdvOfs = ovr_stshAllocStub();
    adlibgAdvSeg = pfVar2;
    mt32mpuAdvOfs = ovr_stshAllocStub();
    mt32mpuAdvSeg = pfVar2;
  }
  else {
    midpakAd.ofs = (uint16_t)
                   stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),(char *)0x0,unaff_BP);
    midpakAd.seg = in_DX;
    cmidpakComOfs =
         stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                         (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
    _cmidpakComSeg = in_DX;
    ibmsndComOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                   (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
    ibmsndComSeg = in_DX;
    sblasterComOfs =
         stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                         (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
    audioPlaceholder2.seg = 0;
    audioPlaceholder2.ofs = 0;
    sblasterComSeg = in_DX;
    fibmbakComOfs =
         stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                         (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
    fibmbakComSeg = in_DX;
    pfVar1 = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                             (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
    sbproComOfs = pfVar1;
    sbproComSeg = in_DX;
    sbproComCopyOfs = pfVar1;
    sbproComCopySeg = in_DX;
    paudioComOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                   (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
    sblasterComCopySeg = sblasterComSeg;
    sblasterComCopyOfs = sblasterComOfs;
    pfVar2 = sblasterComOfs;
    paudioComSeg = pfVar1;
    adlibComOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                  (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
    adlibComSeg = pfVar2;
    adlibgComOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                   (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
    audioPlaceholder3.seg = 0;
    audioPlaceholder3.ofs = 0;
    musDriver0Seg = 0;
    musDriver0Ofs = 0;
    adlibgComSeg = pfVar2;
    sbfmAdvOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                 (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
    audioPlaceholder0.seg = 0;
    audioPlaceholder0.ofs = 0;
    audioPlaceholder1.seg = 0;
    audioPlaceholder1.ofs = 0;
    sbfmAdvSeg = pfVar2;
    sbp2fmAdvOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                   (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
    sbp2fmAdvSeg = pfVar2;
    sbp1fmAdvOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                   (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
    sbp1fmAdvSeg = pfVar2;
    pasfmAdvOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                  (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
    pasfmAdvSeg = pfVar2;
    pasoplAdvOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                   (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
    pasoplAdvSeg = pfVar2;
    adlibAdvOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                  (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
    adlibAdvSeg = pfVar2;
    adlibgAdvOfs = stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                                   (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
    adlibgAdvSeg = pfVar2;
    mt32mpuAdvOfs =
         stshStoreFile_2((far_t *)((char *)"puppetmaker" + 3),
                         (char *)((int)(undefined4 *)&_DATA + 1),unaff_BP);
    mt32mpuAdvSeg = pfVar2;
  }
  return;
}



/* 4b0a:1820 */

void __cdecl16far grabBldLbm(int16_t file_normal,int16_t file_ruin,uint16_t index,...)

{
  stg_tmp_t *psVar1;
  far_t *pfVar2;
  cte_t *pcVar3;
  uint16_t pg;
  stg_tmp_t *in_DX;
  uint8_t *puVar4;
  uint8_t *puVar5;
  stg_tmp_t *psVar6;
  int16_t unaff_SI;
  int16_t unaff_DI;
  uint32_t p;
  undefined2 in_stack_00000004;
  stg_tmp_t *psVar7;
  int16_t iVar9;
  uint8_t *puVar8;
  
  psVar1 = grabLbmTR();
  psVar6 = in_DX;
  pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x820000)),99,194,26,-1,unaff_DI,
                            unaff_SI,(&psVar1->aptr)->ofs);
  psVar7 = (stg_tmp_t *)CONCAT22(unaff_DI,psVar6);
  pcVar3 = stshStoreFile((uint8_t *)psVar7,pfVar2);
  iVar9 = (int16_t)((ulong)psVar7 >> 0x10);
  puVar5 = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
  *(undefined2 *)((int)&BldGfxNormal[0].seg + file_ruin * 0xc) = psVar6;
  ((far_t *)BldGfxNormal + file_ruin * 3)->ofs = (uint16_t)pcVar3;
  pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x820064)),199,194,26,-1,iVar9,unaff_SI
                            ,(&psVar1->aptr)->ofs);
  puVar8 = (uint8_t *)CONCAT22(iVar9,puVar5);
  pcVar3 = stshStoreFile(puVar8,pfVar2);
  iVar9 = (int16_t)((ulong)puVar8 >> 0x10);
  puVar4 = (uint8_t *)&AgntAnms[0x88].missileDy;
  *(int *)((int)&BldGfxNormal[1].seg + file_ruin * 0xc) = (int)puVar5;
  ((far_t *)(BldGfxNormal + 1) + file_ruin * 3)->ofs = (uint16_t)pcVar3;
  pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x8200c8)),299,194,26,-1,iVar9,unaff_SI
                            ,(&psVar1->aptr)->ofs);
  puVar8 = (uint8_t *)CONCAT22(iVar9,puVar4);
  pcVar3 = stshStoreFile(puVar8,pfVar2);
  iVar9 = (int16_t)((ulong)puVar8 >> 0x10);
  puVar5 = (uint8_t *)&AgntAnms[0x88].missileDy;
  *(undefined2 *)((int)&BldGfxNormal[2].seg + file_ruin * 0xc) = puVar4;
  ((far_t *)(BldGfxNormal + 2) + file_ruin * 3)->ofs = (uint16_t)pcVar3;
  pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x410000)),99,129,26,-1,iVar9,unaff_SI,
                            (&psVar1->aptr)->ofs);
  puVar8 = (uint8_t *)CONCAT22(iVar9,puVar5);
  pcVar3 = stshStoreFile(puVar8,pfVar2);
  iVar9 = (int16_t)((ulong)puVar8 >> 0x10);
  puVar4 = (uint8_t *)&AgntAnms[0x88].missileDy;
  *(undefined2 *)((int)&BldGfxNormal[3].seg + file_ruin * 0xc) = puVar5;
  ((far_t *)(BldGfxNormal + 3) + file_ruin * 3)->ofs = (uint16_t)pcVar3;
  pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x410064)),199,129,26,-1,iVar9,unaff_SI
                            ,(&psVar1->aptr)->ofs);
  puVar8 = (uint8_t *)CONCAT22(iVar9,puVar4);
  pcVar3 = stshStoreFile(puVar8,pfVar2);
  iVar9 = (int16_t)((ulong)puVar8 >> 0x10);
  puVar5 = (uint8_t *)&AgntAnms[0x88].missileDy;
  *(undefined2 *)((int)&BldGfxNormal[4].seg + file_ruin * 0xc) = puVar4;
  ((far_t *)(BldGfxNormal + 4) + file_ruin * 3)->ofs = (uint16_t)pcVar3;
  pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x4100c8)),299,129,26,-1,iVar9,unaff_SI
                            ,(&psVar1->aptr)->ofs);
  puVar8 = (uint8_t *)CONCAT22(iVar9,puVar5);
  pcVar3 = stshStoreFile(puVar8,pfVar2);
  iVar9 = (int16_t)((ulong)puVar8 >> 0x10);
  puVar4 = (uint8_t *)&AgntAnms[0x88].missileDy;
  *(undefined2 *)((int)&BldGfxNormal[5].seg + file_ruin * 0xc) = puVar5;
  ((far_t *)(BldGfxNormal + 5) + file_ruin * 3)->ofs = (uint16_t)pcVar3;
  pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x0)),99,64,26,-1,iVar9,unaff_SI,
                            (&psVar1->aptr)->ofs);
  puVar8 = (uint8_t *)CONCAT22(iVar9,puVar4);
  pcVar3 = stshStoreFile(puVar8,pfVar2);
  iVar9 = (int16_t)((ulong)puVar8 >> 0x10);
  puVar5 = (uint8_t *)&AgntAnms[0x88].missileDy;
  *(undefined2 *)((int)&BldGfxNormal[6].seg + file_ruin * 0xc) = puVar4;
  ((far_t *)(BldGfxNormal + 6) + file_ruin * 3)->ofs = (uint16_t)pcVar3;
  pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0x64)),199,64,26,-1,iVar9,unaff_SI,
                            (&psVar1->aptr)->ofs);
  puVar8 = (uint8_t *)CONCAT22(iVar9,puVar5);
  pcVar3 = stshStoreFile(puVar8,pfVar2);
  iVar9 = (int16_t)((ulong)puVar8 >> 0x10);
  puVar4 = (uint8_t *)&AgntAnms[0x88].missileDy;
  *(undefined2 *)((int)&BldGfxNormal[7].seg + file_ruin * 0xc) = puVar5;
  ((far_t *)(BldGfxNormal + 7) + file_ruin * 3)->ofs = (uint16_t)pcVar3;
  pfVar2 = ovr_stshRleType2((far_t *)(psVar1->aptr).seg,far_from_u32((uint32_t)(0xc8)),299,64,26,-1,iVar9,unaff_SI,
                            (&psVar1->aptr)->ofs);
  puVar8 = (uint8_t *)CONCAT22(iVar9,puVar4);
  pcVar3 = stshStoreFile(puVar8,pfVar2);
  psVar6 = (stg_tmp_t *)&AgntAnms[0x88].missileDy;
  *(undefined2 *)((int)&BldGfxNormal[8].seg + file_ruin * 0xc) = puVar4;
  ((far_t *)(BldGfxNormal + 8) + file_ruin * 3)->ofs = (uint16_t)pcVar3;
  psVar7 = (stg_tmp_t *)CONCAT22((int)((ulong)puVar8 >> 0x10),in_DX);
  stgFreeTmp(psVar7,psVar1);
  if (file_normal != 0) {
    iVar9 = (int16_t)((ulong)psVar7 >> 0x10);
    pg = (uint16_t)grabLbmTR();
    (*(uint16_t *)((uint8_t *)&(p) + 2)) = psVar6;
    (*(uint16_t *)((uint8_t *)&(p))) = ovr_stshRleType2((far_t *)*(undefined2 *)(pg + 0x302),far_from_u32((uint32_t)(0x820000)),99,194,26,-1,
                               iVar9,unaff_SI,*(undefined2 *)(pg + 0x300));
    psVar7 = (stg_tmp_t *)CONCAT22(iVar9,(*(uint16_t *)((uint8_t *)&(p) + 2)));
    pcVar3 = stshStoreFile((uint8_t *)psVar7,(far_t *)p);
    iVar9 = (int16_t)((ulong)psVar7 >> 0x10);
    puVar5 = (uint8_t *)&AgntAnms[0x88].missileDy;
    *(undefined2 *)((int)&BldGfxRuin[0].seg + file_ruin * 0xc) = (*(uint16_t *)((uint8_t *)&(p) + 2));
    ((far_t *)BldGfxRuin + file_ruin * 3)->ofs = (uint16_t)pcVar3;
    pfVar2 = ovr_stshRleType2((far_t *)*(undefined2 *)(pg + 0x302),far_from_u32((uint32_t)(0x820064)),199,194,26,-1,
                              iVar9,unaff_SI,*(undefined2 *)(pg + 0x300));
    puVar8 = (uint8_t *)CONCAT22(iVar9,puVar5);
    pcVar3 = stshStoreFile(puVar8,pfVar2);
    iVar9 = (int16_t)((ulong)puVar8 >> 0x10);
    puVar4 = (uint8_t *)&AgntAnms[0x88].missileDy;
    *(undefined2 *)((int)&BldGfxRuin[1].seg + file_ruin * 0xc) = puVar5;
    ((far_t *)(BldGfxRuin + 1) + file_ruin * 3)->ofs = (uint16_t)pcVar3;
    pfVar2 = ovr_stshRleType2((far_t *)*(undefined2 *)(pg + 0x302),far_from_u32((uint32_t)(0x8200c8)),299,194,26,-1,
                              iVar9,unaff_SI,*(undefined2 *)(pg + 0x300));
    puVar8 = (uint8_t *)CONCAT22(iVar9,puVar4);
    pcVar3 = stshStoreFile(puVar8,pfVar2);
    iVar9 = (int16_t)((ulong)puVar8 >> 0x10);
    puVar5 = (uint8_t *)&AgntAnms[0x88].missileDy;
    *(undefined2 *)((int)&BldGfxRuin[2].seg + file_ruin * 0xc) = puVar4;
    ((far_t *)(BldGfxRuin + 2) + file_ruin * 3)->ofs = (uint16_t)pcVar3;
    pfVar2 = ovr_stshRleType2((far_t *)*(undefined2 *)(pg + 0x302),far_from_u32((uint32_t)(0x410000)),99,129,26,-1,
                              iVar9,unaff_SI,*(undefined2 *)(pg + 0x300));
    puVar8 = (uint8_t *)CONCAT22(iVar9,puVar5);
    pcVar3 = stshStoreFile(puVar8,pfVar2);
    iVar9 = (int16_t)((ulong)puVar8 >> 0x10);
    puVar4 = (uint8_t *)&AgntAnms[0x88].missileDy;
    *(undefined2 *)((int)&BldGfxRuin[3].seg + file_ruin * 0xc) = puVar5;
    ((far_t *)(BldGfxRuin + 3) + file_ruin * 3)->ofs = (uint16_t)pcVar3;
    pfVar2 = ovr_stshRleType2((far_t *)*(undefined2 *)(pg + 0x302),far_from_u32((uint32_t)(0x410064)),199,129,26,-1,
                              iVar9,unaff_SI,*(undefined2 *)(pg + 0x300));
    puVar8 = (uint8_t *)CONCAT22(iVar9,puVar4);
    pcVar3 = stshStoreFile(puVar8,pfVar2);
    iVar9 = (int16_t)((ulong)puVar8 >> 0x10);
    puVar5 = (uint8_t *)&AgntAnms[0x88].missileDy;
    *(undefined2 *)((int)&BldGfxRuin[4].seg + file_ruin * 0xc) = puVar4;
    ((far_t *)(BldGfxRuin + 4) + file_ruin * 3)->ofs = (uint16_t)pcVar3;
    pfVar2 = ovr_stshRleType2((far_t *)*(undefined2 *)(pg + 0x302),far_from_u32((uint32_t)(0x4100c8)),299,129,26,-1,
                              iVar9,unaff_SI,*(undefined2 *)(pg + 0x300));
    puVar8 = (uint8_t *)CONCAT22(iVar9,puVar5);
    pcVar3 = stshStoreFile(puVar8,pfVar2);
    iVar9 = (int16_t)((ulong)puVar8 >> 0x10);
    puVar4 = (uint8_t *)&AgntAnms[0x88].missileDy;
    *(undefined2 *)((int)&BldGfxRuin[5].seg + file_ruin * 0xc) = puVar5;
    ((far_t *)(BldGfxRuin + 5) + file_ruin * 3)->ofs = (uint16_t)pcVar3;
    pfVar2 = ovr_stshRleType2((far_t *)*(undefined2 *)(pg + 0x302),far_from_u32((uint32_t)(0x0)),99,64,26,-1,iVar9,
                              unaff_SI,*(undefined2 *)(pg + 0x300));
    puVar8 = (uint8_t *)CONCAT22(iVar9,puVar4);
    pcVar3 = stshStoreFile(puVar8,pfVar2);
    iVar9 = (int16_t)((ulong)puVar8 >> 0x10);
    puVar5 = (uint8_t *)&AgntAnms[0x88].missileDy;
    *(undefined2 *)((int)&BldGfxRuin[6].seg + file_ruin * 0xc) = puVar4;
    ((far_t *)(BldGfxRuin + 6) + file_ruin * 3)->ofs = (uint16_t)pcVar3;
    pfVar2 = ovr_stshRleType2((far_t *)*(undefined2 *)(pg + 0x302),far_from_u32((uint32_t)(0x64)),199,64,26,-1,iVar9,
                              unaff_SI,*(undefined2 *)(pg + 0x300));
    puVar8 = (uint8_t *)CONCAT22(iVar9,puVar5);
    pcVar3 = stshStoreFile(puVar8,pfVar2);
    iVar9 = (int16_t)((ulong)puVar8 >> 0x10);
    puVar4 = (uint8_t *)&AgntAnms[0x88].missileDy;
    *(undefined2 *)((int)&BldGfxRuin[7].seg + file_ruin * 0xc) = puVar5;
    ((far_t *)(BldGfxRuin + 7) + file_ruin * 3)->ofs = (uint16_t)pcVar3;
    pfVar2 = ovr_stshRleType2((far_t *)*(undefined2 *)(pg + 0x302),far_from_u32((uint32_t)(0xc8)),299,64,26,-1,iVar9,
                              unaff_SI,*(undefined2 *)(pg + 0x300));
    puVar8 = (uint8_t *)CONCAT22(iVar9,puVar4);
    pcVar3 = stshStoreFile(puVar8,pfVar2);
    *(undefined2 *)((int)&BldGfxRuin[8].seg + file_ruin * 0xc) = puVar4;
    ((far_t *)(BldGfxRuin + 8) + file_ruin * 3)->ofs = (uint16_t)pcVar3;
    stgFreeTmp((stg_tmp_t *)CONCAT22((int)((ulong)puVar8 >> 0x10),psVar6),pg);
  }
  return;
}


