/*
 * ovc20_stash.c - recovered from STRONG.EXE
 * memory block: OVC20_stash.c
 * range: 4b0a:0000 - 4b0a:1faf
 * functions: 23
 */
#include "recovered.h"


/* 4b0a:0000 */

/* Remaps unique colors, such as the those in portraits and biome skylines */

void __cdecl16far stshUniqueColorsRemap(stg_tmp_t *gfx,uint16_t arg2)

{
  uint16_t si;
  uint16_t i;
  uint uVar1;
  uint16_t in_stack_00000006;
  uint8_t cmap [769];
  uint8_t c;
  
  for (i = 0; i < 64000; i = i + 1) {
    c = *(byte *)((gfx->aptr).ofs + i);
    if ((c < 0x50) || (0x7f < c)) {
      if ((0x7f < c) && (c < 0xd0)) {
        c = c - 0x30;
      }
    }
    else {
      c = c + 0x50;
    }
    *(uint8_t *)((gfx->aptr).ofs + i) = c;
  }
  _fmemmove((char far *)MK_FP(_SS,cmap),(char far *)MK_FP(in_stack_00000006,gfx),0x300);
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
    gfx->cmap[uVar1 * 3] = cmap[si * 3];
    gfx->cmap[uVar1 * 3 + 1] = cmap[si * 3 + 1];
    gfx->cmap[uVar1 * 3 + 2] = cmap[si * 3 + 2];
  }
  return;
}



/* 4b0a:010c */

/* Walk both stash chains and print each node.  Re-derived from the image: the head of the first
   chain is StshCtPtr2 (47fa/47fc) and its link is at +9/+0xb; the second chain starts at
   Stsh_2410_47f6 (47f6/47f8) and links through +0xd/+0xf.  Each node is a cte_t: `ofs` at +1,
   `sz` at +5, `info[12]` at +9 (the long at +0x11 is printed as "@%lx").  The count of nodes is
   printed after each pass and the key wait comes from the overlay manager. */
void __cdecl16far ovc20_textLenLoc(void)

{
  cte_t far *node;
  uint16_t count;

  count = 0;
  node = (cte_t far *)MK_FP(StshCtPtr2.seg,StshCtPtr2.ofs);
  while (node != (cte_t far *)0) {
    printf("uc%lx %d len %ld loc %ld \r",(uint32_t)node,count,node->sz,node->ofs,
           *(uint32_t far *)(node->info + 8));
    count++;
    node = (cte_t far *)MK_FP(*(uint16_t far *)(node->info + 2),
                              *(uint16_t far *)(node->info + 0));
  }
  printf("N UP = %d \r",count);
  ovr_gameProcessKey();
  count = 0;
  node = (cte_t far *)MK_FP(Stsh_2410_47f6.seg,Stsh_2410_47f6.ofs);
  while (node != (cte_t far *)0) {
    printf("dc%lx %d ln %ld lc %ld @%lx \r",(uint32_t)node,count,node->sz,node->ofs,
           *(uint32_t far *)(node->info + 8));
    count++;
    node = (cte_t far *)MK_FP(*(uint16_t far *)(node->info + 6),
                              *(uint16_t far *)(node->info + 4));
  }
  printf("N DOWN = %d \r",count);
  ovr_gameProcessKey();
  return;
}



/* 4b0a:01f8 */

/* Grabs LBM with transparency remap */

stg_tmp_t * __cdecl16far grabLbmTR(int16_t file_id)

{
  uint32_t r;
  far_t pixels;
  far_t pixels_00;
  
  (*(uint16_t *)((uint8_t *)&(r))) = ovr_grabLbm(file_id,0,0);
  pixels.seg = (((stg_tmp_t *)r)->aptr).seg;
  pixels.ofs = (&((stg_tmp_t *)r)->aptr)->ofs;
  ovr_grabRemap(pixels,0x14,0x0,0);
  pixels_00.seg = (((stg_tmp_t *)r)->aptr).seg;
  pixels_00.ofs = (&((stg_tmp_t *)r)->aptr)->ofs;
  ovr_grabRemap(pixels_00,0xff,0x0,0);
  return (stg_tmp_t *)r;
}



/* 4b0a:024e */

void __cdecl16far stgFreeTmp(stg_tmp_t *tg,uint16_t arg2)

{
  uint16_t in_stack_00000006;
  far_t handle;
  far_t handle_00;
  
  handle.seg = (tg->bptr).seg;
  handle.ofs = (&tg->bptr)->ofs;
  ovr_stshFree(handle);
  handle_00.seg = in_stack_00000006;
  handle_00.ofs = (uint16_t)tg;
  ovr_stshFree(handle_00);
  return;
}



/* 4b0a:0276 */

void __cdecl16far stubyBufSrcToDst(int src,int dst,uint16_t arg3)

{
  uint16_t uVar1;
  uint16_t j;
  uint16_t i;
  
  for (i = 0; (int)i < 3; i = i + 1) {
    for (j = 0; (int)j < 3; j = j + 1) {
      uVar1 = ((far_t far *)BldGfxNormal + j + (src + i) * 3)->ofs;
      *(uint16_t *)((int)&BldGfxNormal[0].seg + (dst + i) * 0xc + j * 4) =
           *(uint16_t *)((int)&BldGfxNormal[0].seg + (src + i) * 0xc + j * 4);
      ((far_t far *)BldGfxNormal + j + (dst + i) * 3)->ofs = uVar1;
      uVar1 = ((far_t far *)BldGfxRuin + j + (src + i) * 3)->ofs;
      *(uint16_t *)((int)&BldGfxRuin[0].seg + (dst + i) * 0xc + j * 4) =
           *(uint16_t *)((int)&BldGfxRuin[0].seg + (src + i) * 0xc + j * 4);
      ((far_t far *)BldGfxRuin + j + (dst + i) * 3)->ofs = uVar1;
    }
  }
  return;
}



/* 4b0a:032c */

void __cdecl16far stshStubifyFromSrc(int src,int dst,uint16_t arg3)

{
  uint16_t uVar1;
  uint16_t i;
  
  for (i = 0; (int)i < 3; i = i + 1) {
    uVar1 = ((far_t far *)BldGfxNormal + i + src * 3)->ofs;
    BldGfxNormal[dst * 3 + i].seg =
         BldGfxNormal[src * 3 + i].seg;
    ((far_t far *)BldGfxNormal + i + dst * 3)->ofs = uVar1;
    uVar1 = ((far_t far *)BldGfxRuin + i + src * 3)->ofs;
    BldGfxRuin[dst * 3 + i].seg =
         BldGfxRuin[src * 3 + i].seg;
    ((far_t far *)BldGfxRuin + i + dst * 3)->ofs = uVar1;
  }
  return;
}



/* 4b0a:03cd */

void __cdecl16far StubifyCopy1to0_alt(int index)

{
  uint16_t uVar1;
  
  uVar1 = ((far_t *)(BldGfxNormal + 1) + index * 3)->ofs;
  BldGfxNormal[index * 3].seg =
       BldGfxNormal[1 + index * 3].seg;
  ((far_t far *)BldGfxNormal + index * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxNormal + 1) + index * 3)->ofs;
  BldGfxNormal[2 + index * 3].seg =
       BldGfxNormal[1 + index * 3].seg;
  ((far_t *)(BldGfxNormal + 2) + index * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxRuin + 1) + index * 3)->ofs;
  BldGfxRuin[index * 3].seg =
       BldGfxRuin[1 + index * 3].seg;
  ((far_t far *)BldGfxRuin + index * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxRuin + 1) + index * 3)->ofs;
  BldGfxRuin[2 + index * 3].seg =
       BldGfxRuin[1 + index * 3].seg;
  ((far_t *)(BldGfxRuin + 2) + index * 3)->ofs = uVar1;
  return;
}



/* 4b0a:04a7 */

void __cdecl16far stshStubifyCopy1to0(int index)

{
  uint16_t gfxOfs;
  
  gfxOfs = ((far_t *)(BldGfxNormal + 1) + index * 3)->ofs;
  BldGfxNormal[index * 3].seg =
       BldGfxNormal[1 + index * 3].seg;
  ((far_t far *)BldGfxNormal + index * 3)->ofs = gfxOfs;
  gfxOfs = ((far_t *)(BldGfxNormal + 1) + index * 3)->ofs;
  BldGfxNormal[2 + index * 3].seg =
       BldGfxNormal[1 + index * 3].seg;
  ((far_t *)(BldGfxNormal + 2) + index * 3)->ofs = gfxOfs;
  gfxOfs = ((far_t *)(BldGfxNormal + 4) + index * 3)->ofs;
  BldGfxNormal[3 + index * 3].seg =
       BldGfxNormal[4 + index * 3].seg;
  ((far_t *)(BldGfxNormal + 3) + index * 3)->ofs = gfxOfs;
  gfxOfs = ((far_t *)(BldGfxNormal + 4) + index * 3)->ofs;
  BldGfxNormal[5 + index * 3].seg =
       BldGfxNormal[4 + index * 3].seg;
  ((far_t *)(BldGfxNormal + 5) + index * 3)->ofs = gfxOfs;
  gfxOfs = ((far_t *)(BldGfxNormal + 7) + index * 3)->ofs;
  BldGfxNormal[6 + index * 3].seg =
       BldGfxNormal[7 + index * 3].seg;
  ((far_t *)(BldGfxNormal + 6) + index * 3)->ofs = gfxOfs;
  gfxOfs = ((far_t *)(BldGfxNormal + 7) + index * 3)->ofs;
  BldGfxNormal[8 + index * 3].seg =
       BldGfxNormal[7 + index * 3].seg;
  ((far_t *)(BldGfxNormal + 8) + index * 3)->ofs = gfxOfs;
  gfxOfs = ((far_t *)(BldGfxRuin + 1) + index * 3)->ofs;
  BldGfxRuin[index * 3].seg =
       BldGfxRuin[1 + index * 3].seg;
  ((far_t far *)BldGfxRuin + index * 3)->ofs = gfxOfs;
  gfxOfs = ((far_t *)(BldGfxRuin + 1) + index * 3)->ofs;
  BldGfxRuin[2 + index * 3].seg =
       BldGfxRuin[1 + index * 3].seg;
  ((far_t *)(BldGfxRuin + 2) + index * 3)->ofs = gfxOfs;
  gfxOfs = ((far_t *)(BldGfxRuin + 4) + index * 3)->ofs;
  BldGfxRuin[3 + index * 3].seg =
       BldGfxRuin[4 + index * 3].seg;
  ((far_t *)(BldGfxRuin + 3) + index * 3)->ofs = gfxOfs;
  gfxOfs = ((far_t *)(BldGfxRuin + 4) + index * 3)->ofs;
  BldGfxRuin[5 + index * 3].seg =
       BldGfxRuin[4 + index * 3].seg;
  ((far_t *)(BldGfxRuin + 5) + index * 3)->ofs = gfxOfs;
  gfxOfs = ((far_t *)(BldGfxRuin + 7) + index * 3)->ofs;
  BldGfxRuin[6 + index * 3].seg =
       BldGfxRuin[7 + index * 3].seg;
  ((far_t *)(BldGfxRuin + 6) + index * 3)->ofs = gfxOfs;
  gfxOfs = ((far_t *)(BldGfxRuin + 7) + index * 3)->ofs;
  BldGfxRuin[8 + index * 3].seg =
       BldGfxRuin[7 + index * 3].seg;
  ((far_t *)(BldGfxRuin + 8) + index * 3)->ofs = gfxOfs;
  return;
}



/* 4b0a:0721 */
void __cdecl16far stshWriteFile(int fhandle,far_t buf,DW sz,uint16_t arg4,uint16_t arg5)

{
  uint16_t remaining;
  uint16_t bufSeg;
  uint16_t wrsz;
  uint16_t unaff_DI;
  uint32_t pbuf;
  
  do {
    if ((0 < (int)sz.hi) || ((wrsz = sz.lo, -1 < (long)CONCAT22(sz.hi, sz.lo) && (0xbfff < sz.lo)))) {
      wrsz = 0xc000;
    }
    (*(uint16_t *)((uint8_t *)&(pbuf))) = ovr_mkp((uint32_t *)buf.ofs,buf.seg,unaff_DI);
    bufSeg = (*(uint16_t *)((uint8_t *)&(pbuf) + 2));
    write(fhandle,(uint32_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(pbuf) + 2)),(uint32_t *)pbuf),wrsz);
    buf.seg = (*(uint16_t *)((uint8_t *)&(pbuf) + 2));
    buf.ofs = (int)(uint32_t *)pbuf + wrsz;
    remaining = sz.lo - wrsz;
    sz.hi = sz.hi - (sz.lo < wrsz);
    sz.lo = remaining;
    (*(uint16_t *)((uint8_t *)&(pbuf) + 2)) = bufSeg;
  } while (remaining != 0 || sz.hi != 0);
  return;
}


/* 4b0a:077a */
void __cdecl16far stshReadFile(int handle,far_t dst,DW nbytes,uint16_t arg4)

{
  uint16_t remaining;
  uint16_t dstSeg;
  uint uVar3;
  uint16_t unaff_DI;
  far_t pdst;
  
  do {
    if ((0 < (int)nbytes.hi) || ((uVar3 = nbytes.lo, -1 < (long)CONCAT22(nbytes.hi, nbytes.lo) && (0xbfff < nbytes.lo)))) {
      uVar3 = 0xc000;
    }
    pdst.ofs = (uint16_t)ovr_mkp((uint32_t *)dst.ofs,dst.seg,unaff_DI);
    dstSeg = pdst.seg;
    read(handle,(void *)CONCAT22(uVar3,pdst.seg),unaff_DI);
    dst.seg = pdst.seg;
    dst.ofs = pdst.ofs + uVar3;
    remaining = nbytes.lo - uVar3;
    nbytes.hi = nbytes.hi - (nbytes.lo < uVar3);
    nbytes.lo = remaining;
    pdst.seg = dstSeg;
  } while (remaining != 0 || nbytes.hi != 0);
  return;
}


/* 4b0a:07d3 */

/* anms points to the array 0x1e sized anim_t entries,
   the last entry has nframes == 0
   the seq can have upto nanims total
   the function returns array of anim file stubs */

spr_t * __cdecl16far stshSpriteStub(anm_t *anms,uint16_t nanims)

{
  uint16_t k;
  uint16_t pd;
  int iVar1;
  uint16_t j;
  far_t *unaff_DI;
  uint16_t i;
  far_t dst;
  far_t pstub;
  uint in_stack_00000008;
  
  if (StshSprIndex < 0x4f) {
    dst.seg = (uint16_t)((spr_t far *)StshSprites + StshSprIndex);
    StshSprIndex = StshSprIndex + 1;
    dst.ofs = (uint16_t)ovr_mkp((uint32_t *)dst.seg,(*(uint16_t *)((uint8_t *)&(StshSprites) + 2)),(uint16_t)unaff_DI);
    _fsetmem(MK_FP(dst.seg,dst.ofs),0xb0,0);
    i = 0;
    while ((i < in_stack_00000008 && (anms[i].nframes != 0x0))) {
      k = (uint16_t)(anms + i)->frmid;
      pd = dst.ofs + k * 4;
      *(uint16_t *)(pd + 2) = nanims;
      *(anm_t **)pd = anms + i;
      for (j = 0; pstub.seg = (uint16_t)((ulong)((long)(int)i * 0x1e) >> 0x10),
          j < (&anms->nframes)[(int)((long)(int)i * 0x1e)]; j = j + 1) {
        if (j == 0) {
          pstub.ofs = (uint16_t)ovr_stshAllocStub(unaff_DI);
          iVar1 = dst.ofs + k * 4;
          *(uint16_t *)(iVar1 + 0x5a) = pstub.seg;
          *(uint16_t *)(iVar1 + 0x58) = pstub.ofs;
        }
        else {
          ovr_stshAllocStub(unaff_DI);
        }
      }
      i = i + 1;
    }
    return (spr_t *)dst.ofs;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x36);
}



/* 4b0a:08ee */

/* Allocates a size-rounded block while the archive allocation counter is below 0xd93. */

undefined1 * __cdecl16far ovc20_allocBlock(far_t buf,DW sz)

{
  far_t padOfs;
  uint32_t *puVar1;
  uint16_t unaff_BP;
  bool bVar2;
  far_t fVar3;
  long in_stack_00000000;
  uint16_t uVar4;
  long *in_stack_0000fffa;
  uint16_t in_stack_0000fffc;
  
  if (StshCount < 0xd93) {
    StshCount = StshCount + 1;
    LXMUL_at_(in_stack_0000fffa,CONCAT22(unaff_BP,in_stack_0000fffc),in_stack_00000000);
    uVar4 = 0x1000;
    fVar3.seg = (uint16_t)in_stack_0000fffa;
    fVar3.ofs = 0x1000;
    padOfs.seg = unaff_BP;
    padOfs.ofs = in_stack_0000fffc;
    fVar3 = PADD_at_(fVar3,padOfs);
    fVar3.seg = fVar3.seg;
    puVar1 = ovr_mkp((uint32_t *)fVar3.ofs,fVar3.seg,uVar4);
    *(uint16_t *)((int)puVar1 + 7) = sz.hi;
    *(uint16_t *)((int)puVar1 + 5) = sz.lo;
    *(undefined1 *)CONCAT22(fVar3.seg,puVar1) = 0;
    uVar4 = StshCtOfs.lo;
    *(uint16_t *)((int)puVar1 + 3) = StshCtOfs.hi;
    *(uint16_t *)((int)puVar1 + 1) = uVar4;
    *(uint16_t *)((int)puVar1 + 0x13) = 0;
    *(uint16_t *)((int)puVar1 + 0x11) = 0;
    bVar2 = CARRY2(StshCtOfs.lo,sz.lo);
    StshCtOfs.lo = StshCtOfs.lo + sz.lo;
    StshCtOfs.hi = StshCtOfs.hi + sz.hi + (uint)bVar2;
    *(uint16_t *)((int)puVar1 + 0xb) = 0;
    *(uint16_t *)((int)puVar1 + 9) = 0;
    *(uint16_t *)((int)puVar1 + 0xf) = 0;
    *(uint16_t *)((int)puVar1 + 0xd) = 0;
    stshWriteFile(StshFile,buf,sz,0,0);
    ovr_stshFree(buf);
    return (undefined1 *)puVar1;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x24);
}



/* 4b0a:09ce */
cte_t * __cdecl16far stshStoreFile(uint8_t *data,uint16_t arg2)

{
  far_t buf;
  uint16_t ctOfsLo;
  uint16_t sizeLo;
  cte_t *psVar4;
  uint16_t unaff_BP;
  bool carry;
  far_t fVar4;
  uint16_t in_stack_00000006;
  DW sz_00;
  far_t handle;
  DW DStack_c;
  DW sz;
  uint16_t uStack_6;
  uint16_t in_stack_0000fffc;
  uint16_t ofs;
  
  if (5 < *data) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x18);
  }
                    /* WARNING: Switch is manually overridden */
  switch((uint32_t)*(uint16_t *)((uint)*data * 2 + 0xb69)) {
  case 0x4ba94:
    return (cte_t *)data;
  case 0x4ba9d:
    sz.lo = *(uint *)(data + 1) + 9;
    sz.hi = *(int *)(data + 3) + (uint)(0xfff6 < *(uint *)(data + 1));
    break;
  case 0x4bab6:
    sz.lo = *(uint *)(data + 6) + 0xe;
    sz.hi = *(int *)(data + 8) + (uint)(0xfff1 < *(uint *)(data + 6));
    break;
  case 0x4bacf:
    sz.lo = *(int *)(data + 5) + 0xd;
    sz.hi = 0;
    break;
  case 0x4bae3:
    sz.lo = *(uint *)(data + 0xc) + 0x14;
    sz.hi = *(int *)(data + 0xe) + (uint)(0xffeb < *(uint *)(data + 0xc));
  }
  sizeLo = sz.lo;
  if (StshCount < 0xd93) {
    StshCount = StshCount + 1;
    LXMUL_at_((long *)sz.lo,CONCAT22(uStack_6,sz.hi),CONCAT22(unaff_BP,in_stack_0000fffc));
    DStack_c.lo = 0x1000;
    fVar4.seg = uStack_6;
    fVar4.ofs = sz.hi;
    fVar4 = PADD_at_(far_from_u32(CONCAT22(DStack_c.hi, DStack_c.lo)),fVar4);
    ofs = fVar4.seg;
    psVar4 = (cte_t *)ovr_mkp((uint32_t *)fVar4.ofs,ofs,0x1000);
    (psVar4->sz).hi = sz.hi;
    (&psVar4->sz)->lo = sizeLo;
    ((cte_t *)CONCAT22(ofs,psVar4))->state = 0x0;
    ctOfsLo = StshCtOfs.lo;
    (psVar4->ofs).hi = StshCtOfs.hi;
    (&psVar4->ofs)->lo = ctOfsLo;
    (psVar4->info + 10)[0] = 0x0;
    (psVar4->info + 10)[1] = 0x0;
    (psVar4->info + 8)[0] = 0x0;
    (psVar4->info + 8)[1] = 0x0;
    carry = CARRY2(StshCtOfs.lo,sizeLo);
    StshCtOfs.lo = StshCtOfs.lo + sizeLo;
    StshCtOfs.hi = StshCtOfs.hi + sz.hi + (uint)carry;
    (psVar4->info + 2)[0] = 0x0;
    (psVar4->info + 2)[1] = 0x0;
    psVar4->info[0] = 0x0;
    psVar4->info[1] = 0x0;
    (psVar4->info + 6)[0] = 0x0;
    (psVar4->info + 6)[1] = 0x0;
    (psVar4->info + 4)[0] = 0x0;
    (psVar4->info + 4)[1] = 0x0;
    if (DebugVerbose != false) {
      printf("type %d len %ld \r",*data,sz);
      ovr_biosReadKey();
    }
    sz_00.hi = sz.hi;
    sz_00.lo = sizeLo;
    buf.seg = in_stack_00000006;
    buf.ofs = (uint16_t)data;
    stshWriteFile(StshFile,buf,sz_00,0,0);
    handle.seg = in_stack_00000006;
    handle.ofs = (uint16_t)data;
    ovr_stshFree(handle);
    return psVar4;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x24);
}


/* 4b0a:0b75 */

uint16_t __cdecl16far stshDecVocSampleRate(uint8_t encfreq)

{
  long lVar1;
  
  lVar1 = LDIV_at_(1000000,(long)(int)(0x100 - (uint)encfreq));
  return (uint16_t)lVar1;
}



/* 4b0a:0b9c */
void __cdecl16far stshInitAudioAssets(char grab)

{
  char *pcVar1;
  long *plVar2;
  uint16_t freq;
  uint32_t *puVar3;
  int iVar4;
  void *pvVar5;
  uint16_t file_id;
  cte_t *pcVar6;
  far_t far *pfVar7;
  uint sumLo;
  uint uVar9;
  int in_DX;
  int iVar10;
  uint16_t *puVar11;
  uint sumHi;
  uint16_t unaff_SI;
  uint16_t i;
  far_t far *unaff_DI;
  uint16_t entrySeg;
  bool carry;
  uint8_t blkSize;
  undefined1 blkSizeHi;
  voc_t voc;
  uint uStack_a;
  uint uStack_8;
  
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
    puVar11 = (uint16_t *)(*(int *)(i * 2) * 4);
    pcVar1 = _fstrstr((char *)CONCAT22(puVar11[1],(char *)*puVar11),".xmi");
    if (pcVar1 == (char *)0x0 && in_DX == 0) {
      *(uint16_t *)(&AudioHandles[i]) = 1;
    }
    else {
      *(uint16_t *)(&AudioHandles[i]) = 0;
    }
    if (grab == '\0') {
      pfVar7 = ovr_stshAllocStub(unaff_DI);
      ((uint16_t *)(i * 4))[1] = in_DX;
      *(uint16_t *)(i * 4) =(uint16_t)( pfVar7);
      iVar10 = in_DX;
    }
    else {
      if (*(int *)(&AudioHandles[i]) == 0) {
        puVar3 = ovr_stshFilesize((uint32_t *)*(uint16_t *)(i * 2),(uint16_t)unaff_DI);
        iVar10 = (int)puVar3 + 0xd;
        iVar4 = in_DX + (uint)((uint32_t *)0xfff2 < puVar3);
        pvVar5 = ovr_stshAlloc(CONCAT13((char)((uint)iVar4 >> 8),CONCAT12((char)iVar4,iVar10)));
        {
          uint8_t far *handle;
          /* 014B: the table lives in AudioHandles' own segment, not at DS offset i*4. */
          ((uint16_t far *)((uint8_t far *)&AudioHandles[0] + i * 4))[1] = iVar10;
          ((uint16_t far *)((uint8_t far *)&AudioHandles[0] + i * 4))[0] = (uint16_t)pvVar5;
          handle = (uint8_t far *)*(uint32_t far *)&AudioHandles[i];
          *handle = 3;
          *(uint16_t far *)(handle + 3) = 0;
          *(uint16_t far *)(handle + 1) = 0;
          *(uint16_t far *)(handle + 5) = (uint16_t)puVar3;
        }
        file_id = ovr_stshOpen(*(uint16_t *)(i * 2));
        iVar4 = ovr_stshRead();
        if (iVar4 != 0 || iVar10 != 0) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x20);
        }
        ((anm_t *)((i << 2)))->x = 0;
      }
      else {
        file_id = ovr_stshOpen(*(uint16_t *)(i * 2));
        iVar10 = ovr_stshRead();
        if (iVar10 != 0 || in_DX != 0) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x20);
        }
        blkSizeHi = 0;
        iVar4 = 0;
        iVar10 = 0;
        blkSize = voc.blksz[0];
        plVar2 = LXLSH_at_((long *)0x0,CONCAT22(unaff_DI,(uint)voc.blksz[0]),(byte)unaff_SI);
        sumLo = CONCAT11(blkSizeHi,blkSize) + (int)plVar2;
        uVar9 = sumLo - 2;
        sumHi = (iVar4 + iVar10 + (uint)CARRY2(CONCAT11(blkSizeHi,blkSize),(uint)plVar2) +
                 (uint)voc.blksz[2]) - (uint)(sumLo < 2);
        iVar4 = sumLo + 0xb;
        iVar10 = sumHi + (0xfff2 < uVar9);
        pvVar5 = ovr_stshAlloc(CONCAT13((char)((uint)iVar10 >> 8),CONCAT12((char)iVar10,iVar4)));
        ((uint16_t *)(i * 4))[1] = iVar4;
        *(uint16_t *)(i * 4) =(uint16_t)( pvVar5);
        *(undefined1 *)*(uint32_t *)(i << 2) = 3;
        entrySeg = (uint16_t)((ulong)*(uint32_t *)(i << 2) >> 0x10);
        iVar10 = (int)*(uint32_t *)(i << 2);
        *(uint16_t *)(iVar10 + 3) = 0;
        *(uint16_t *)(iVar10 + 1) = 0;
        *(uint *)((int)*(uint32_t *)(i << 2) + 5) = uVar9;
        if ((uStack_8 <= sumHi) && ((sumHi != uStack_8 || (uStack_a <= uVar9)))) {
          carry = 0xfff2 < uVar9;
          uVar9 = sumLo + 0xb;
          uStack_8 = sumHi + carry;
          uStack_a = uVar9;
        }
        iVar10 = ovr_stshRead();
        if (iVar10 != 0 || uVar9 != 0) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x20);
        }
        freq = stshDecVocSampleRate(voc.freq);
        iVar10 = 0x1703;
        ((anm_t *)((i << 2)))->x = freq;
      }
      ovr_stshClose(file_id);
      pcVar6 = stshStoreFile((uint8_t *)*(uint16_t *)(i * 4),(char)((uint16_t *)(i * 4))[1]);
      ((uint16_t *)(i * 4))[1] = iVar10;
      *(uint16_t *)(i * 4) =(uint16_t)( pcVar6);
    }
    i = i + 1;
    in_DX = iVar10;
  } while( true );
}


/* 4b0a:0eda */
long * __cdecl16far stshAlloc_2(long *retStorage,DW sz)

{
  far_t padOfs;
  uint32_t *puVar1;
  uint16_t unaff_BP;
  bool bVar2;
  far_t fVar3;
  long in_stack_00000000;
  uint16_t uVar4;
  long *in_stack_0000fffa;
  uint16_t in_stack_0000fffc;
  
  if (StshCount < 0xd93) {
    StshCount = StshCount + 1;
    LXMUL_at_(in_stack_0000fffa,CONCAT22(unaff_BP,in_stack_0000fffc),in_stack_00000000);
    uVar4 = 0x1000;
    fVar3.seg = (uint16_t)in_stack_0000fffa;
    fVar3.ofs = 0x1000;
    padOfs.seg = unaff_BP;
    padOfs.ofs = in_stack_0000fffc;
    fVar3 = PADD_at_(fVar3,padOfs);
    fVar3.seg = fVar3.seg;
    puVar1 = ovr_mkp((uint32_t *)fVar3.ofs,fVar3.seg,uVar4);
    *(uint16_t *)((int)puVar1 + 7) = sz.lo;
    *(uint16_t *)((int)puVar1 + 5) =(uint16_t)( retStorage);
    *(undefined1 *)CONCAT22(fVar3.seg,puVar1) = 0;
    uVar4 = StshCtOfs.lo;
    *(uint16_t *)((int)puVar1 + 3) = StshCtOfs.hi;
    *(uint16_t *)((int)puVar1 + 1) = uVar4;
    *(uint16_t *)((int)puVar1 + 0x13) = 0;
    *(uint16_t *)((int)puVar1 + 0x11) = 0;
    bVar2 = CARRY2(StshCtOfs.lo,(uint)retStorage);
    StshCtOfs.lo = StshCtOfs.lo + (int)retStorage;
    StshCtOfs.hi = StshCtOfs.hi + sz.lo + (uint)bVar2;
    *(uint16_t *)((int)puVar1 + 0xb) = 0;
    *(uint16_t *)((int)puVar1 + 9) = 0;
    *(uint16_t *)((int)puVar1 + 0xf) = 0;
    *(uint16_t *)((int)puVar1 + 0xd) = 0;
    return (long *)puVar1;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x24);
}


/* 4b0a:0f95 */
uint32_t * __cdecl16far stshWrite(uint32_t *retStorage,uint8_t *data,long sz,uint16_t arg4)

{
  DW sz_00;
  DW sz_01;
  far_t buf;
  uint32_t *puVar1;
  uint16_t unaff_BP;
  
  if ((*(uint16_t *)((uint8_t *)&(data) + 2)) == (long *)0x0 && (uint16_t)sz == 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x58);
  }
  buf.seg = (uint16_t)(uint8_t *)data;
  buf.ofs = (uint16_t)retStorage;
  sz_00.hi = (uint16_t)sz;
  sz_00.lo = (uint16_t)(*(uint16_t *)((uint8_t *)&(data) + 2));
  stshWriteFile(StshFile,buf,sz_00,0,0);
  sz_01.hi = unaff_BP;
  sz_01.lo = (uint16_t)sz;
  puVar1 = (uint32_t *)stshAlloc_2((long *)(*(uint16_t *)((uint8_t *)&(data) + 2)),sz_01)   /* hand fix: hidden return-storage pointer */;
  return puVar1;
}


/* 4b0a:0fd0 */

/* duplicate name, disambiguated by address order */

far_t * __cdecl16far stshStoreFile_2(far_t *retStorage,char *filename,uint16_t flag)

{
  far_t buf;
  DW sz;
  far_t handle;
  DW sz_00;
  long *retStorage2;
  far_t *pfVar1;
  uint16_t in_DX;
  uint v;
  uint16_t unaff_DI;
  uint16_t pbuf;
  void far *p;   /* buffer returned by ovr_stshAlloc (DX:AX) */
  long *plStack_c;
  uint16_t len;
  uint16_t uStack_8;
  
  retStorage2 =
       (long *)ovr_open_wait_unlock_and_disk((char *)retStorage,(char *)filename);
  if (-1 < (int)retStorage2) {
    plStack_c = filelength(retStorage2,unaff_DI);
    len = (uint16_t)plStack_c;
    uStack_8 = in_DX;
    if ((*(uint8_t *)((uint8_t *)&(filename) + 2)) != '\0') {
      len = (int)plStack_c + 0xf;
      uStack_8 = in_DX + ((long *)0xfff0 < plStack_c);
    }
    sz_00.hi = unaff_DI;
    sz_00.lo = uStack_8;
    pfVar1 = (far_t *)stshAlloc_2((long *)len,sz_00);
    if (((int)uStack_8 < 0) || ((uStack_8 == 0 && (len < 0xc000)))) {
      p = ovr_stshAlloc(CONCAT22(uStack_8,len));
    }
    else {
      p = ovr_stshAlloc(0xc000);
    }
    pbuf = ST_OFF(p);
    for (; len != 0 || uStack_8 != 0; len = len - v) {
      v = len;
      if ((-1 < (int)uStack_8) && ((uStack_8 != 0 || (0xbfff < len)))) {
        v = 0xc000;
      }
      _fmemset(p, 0, v);
      read((int)retStorage2,p,v);
      buf.seg = ST_SEG(p);
      buf.ofs = pbuf;
      sz.hi = 0;
      sz.lo = v;
      stshWriteFile(StshFile,buf,sz,0,0);
      uStack_8 = uStack_8 - (len < v);
    }
    close((int)retStorage2);
    handle.seg = (uint16_t)plStack_c;
    handle.ofs = pbuf;
    ovr_stshFree(handle);
    return pfVar1;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x23);
}



/* 4b0a:10ea */

void __cdecl16far init_special_graphics(char *gfxBlock)

{
  far_t handle;
  
  if (*(int *)((char *)gfxBlock + 0x11) != 0 || *(int *)((char *)gfxBlock + 0x13) != 0) {
    handle.seg = *(uint16_t *)((char *)gfxBlock + 0x13);
    handle.ofs = *(uint16_t *)((char *)gfxBlock + 0x11);
    ovr_stshFree(handle);
    ((char *)gfxBlock + 0x13)[0] = '\0';
    ((char *)gfxBlock + 0x13)[1] = '\0';
    ((char *)gfxBlock + 0x11)[0] = '\0';
    ((char *)gfxBlock + 0x11)[1] = '\0';
  }
  return;
}



/* 4b0a:112d */

/* [R7] body shape: compute */

void __cdecl16far ovc20_compute1(char *gfxBlock,uint16_t arg2)

{
  
  (gfxBlock + 0x13)[0] = '\0';
  (gfxBlock + 0x13)[1] = '\0';
  (gfxBlock + 0x11)[0] = '\0';
  (gfxBlock + 0x11)[1] = '\0';
  return;
}



/* 4b0a:1150 */
void __cdecl16far init_ui_gfxes(void)

{
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t handle;
  far_t handle_00;
  far_t ptr;
  far_t handle_01;
  far_t hndl;
  far_t hndl_00;
  far_t hndl_01;
  char *pcVar1;
  far_t far *pfVar2;
  void *pvVar3;
  uint16_t in_DX;
  uint16_t fontSeg;
  uint16_t i;
  uint16_t unaff_DI;
  uint8_t palette;
  stg_tmp_t *gfxRec;
  stg_tmp_t *palRec;
  void *pvStack_6;
  uint16_t gfxSeg;
  
  handle.seg = Lbm_nwpanel1.seg;
  handle.ofs = Lbm_nwpanel1.ofs;
  palRec = ovr_stshLoadGfx(handle);
  pcVar1 = (char *)ovr_calcSeasonPalette(palRec->cmap,in_DX,&palette,_SS,(char)&palette,0);
  init_special_graphics((char *)CONCAT22(in_DX,pcVar1));
  ovr_vgaSetPalette8bit(&palette,0);
  init_special_graphics((char *)CONCAT22(Lbm_nwpanel1.seg,Lbm_nwpanel1.ofs));
  handle_00.seg = specialColorsSeg;
  handle_00.ofs = (uint16_t)specialColorsOfs;
  gfxRec = ovr_stshLoadGfx(handle_00);
  memcpy((char *)SpecialColors,(char *)CONCAT13((char)(in_DX >> 8),CONCAT12((char)in_DX,gfxRec)),
         8);
  init_special_graphics((char *)CONCAT22(specialColorsSeg,specialColorsOfs));
  pvStack_6 = ovr_stshAlloc(0xfa0f);
  ptr.seg = in_DX;
  ptr.ofs = (uint16_t)pvStack_6;
  gfxSeg = in_DX;
  ovr_alignToSeg(ptr);
  fontSeg = in_DX;
  ovr_driver_fillRect(0,0,0x13f,199,0x0,in_DX,0,0,0,0,0);
  gfx.seg = gamfont1Cut1Seg;
  gfx.ofs = (uint16_t)gamfont1Cut1Ofs;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)((ulong)in_DX << 0x10)),0);
  init_special_graphics((char *)CONCAT22(gamfont1Cut1Seg,gamfont1Cut1Ofs));
  hndl.seg = unaff_DI;
  hndl.ofs = in_DX;
  Font03.ofs = (uint16_t)ovr_stshProcessFontSub((far_t far *)0x0,hndl,0);
  Font03.seg = fontSeg;
  ovr_driver_fillRect(0,0,0x13f,199,0x0,in_DX,0,0,0,0,0);
  gfx_00.seg = davfontCut1Seg;
  gfx_00.ofs = (uint16_t)davfontCut1Ofs;
  ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)((ulong)in_DX << 0x10)),0);
  init_special_graphics((char *)CONCAT22(davfontCut1Seg,davfontCut1Ofs));
  hndl_00.seg = unaff_DI;
  hndl_00.ofs = in_DX;
  Font02.ofs = (uint16_t)ovr_stshProcessFontSub((far_t far *)0x0,hndl_00,0);
  Font02.seg = fontSeg;
  ovr_driver_fillRect(0,0,0x13f,199,0x0,in_DX,0,0,0,0,0);
  gfx_01.seg = davfont2Cut1Seg;
  gfx_01.ofs = (uint16_t)davfont2Cut1Ofs;
  ovr_blitLoadRleGfx(gfx_01,far_from_u32((uint32_t)((ulong)in_DX << 0x10)),0);
  init_special_graphics((char *)CONCAT22(davfont2Cut1Seg,davfont2Cut1Ofs));
  hndl_01.seg = unaff_DI;
  hndl_01.ofs = in_DX;
  pfVar2 = ovr_stshProcessFontSub((far_t far *)0x0,hndl_01,0);
  FontMain.ofs = (uint16_t)pfVar2;
  FontMain.seg = fontSeg;
  Font01.ofs = (uint16_t)pfVar2;
  Font01.seg = fontSeg;
  for (i = 0; (int)i < 4; i = i + 1) {
    ovr_driver_fillRect(0,0,0x11,0x11,0x0,in_DX,0,0,0,0,0);
    gfx_02.seg = *(uint16_t *)((int)&MiceCursors[0].seg + i * 4);
    gfx_02.ofs = ((far_t far *)MiceCursors + i)->ofs;
    ovr_blitLoadRleGfx(gfx_02,far_from_u32((uint32_t)((ulong)in_DX << 0x10)),0);
    init_special_graphics
              ((char *)CONCAT22(*(uint16_t *)((int)&MiceCursors[0].seg + i * 4),
                                (char *)((far_t far *)MiceCursors + i)->ofs));
    video_copyScreenTile(in_DX,0,0);
    pvVar3 = ovr_stshAlloc(0x121);
    *(uint16_t *)((int)&MicePtrs.seg + i * 4) =(uint16_t)( pfVar2);
    ((far_t far *)&MicePtrs + i)->ofs = (uint16_t)pvVar3;
    memcpy((char *)CONCAT22(*(uint16_t *)((int)&MicePtrs.seg + i * 4),
                            (char *)((far_t far *)&MicePtrs + i)->ofs),(char *)MiceSaveBuf,0x121);
  }
  handle_01.seg = gfxSeg;
  handle_01.ofs = (uint16_t)pvStack_6;
  ovr_stshFree(handle_01);
  return;
}


/* 4b0a:13d3 */
void __cdecl16far stshLoadAudioDrivers(bool grab)

{
  far_t far *pfVar1;
  uint16_t in_DX;
  far_t far *pfVar2;
  far_t far *unaff_BP;
  
  if (grab) {
    midpakAd.ofs = (uint16_t)stshStoreFile_2((far_t *)"midpak.ad",(char *)0x2410,(uint16_t)unaff_BP)
    ;
    midpakAd.seg = in_DX;
    cmidpakComOfs =(uint16_t)( stshStoreFile_2((far_t *)"cmidpak.com",(char *)MK_FP(0x2410, 0x1),(uint16_t)unaff_BP));
    cmidpakComSeg = in_DX;
    ibmsndComOfs =(uint16_t)( stshStoreFile_2((far_t *)"ibmsnd.com",(char *)MK_FP(0x2410, 0x1),(uint16_t)unaff_BP));
    ibmsndComSeg = in_DX;
    sblasterComOfs =(uint16_t)( stshStoreFile_2((far_t *)"sblaster.com",(char *)MK_FP(0x2410, 0x1),(uint16_t)unaff_BP));
    audioPlaceholder2.seg = 0;
    audioPlaceholder2.ofs = 0;
    sblasterComSeg = in_DX;
    fibmbakComOfs =(uint16_t)( stshStoreFile_2((far_t *)"fibmbak.com",(char *)MK_FP(0x2410, 0x1),(uint16_t)unaff_BP));
    fibmbakComSeg = in_DX;
    pfVar1 = stshStoreFile_2((far_t *)"sbpro.com",(char *)MK_FP(0x2410, 0x1),(uint16_t)unaff_BP);
    sbproComOfs =(uint16_t)( pfVar1);
    sbproComSeg = in_DX;
    sbproComCopyOfs =(uint16_t)( pfVar1);
    sbproComCopySeg = in_DX;
    paudioComOfs =(uint16_t)( stshStoreFile_2((far_t *)"paudio.com",(char *)MK_FP(0x2410, 0x1),(uint16_t)unaff_BP));
    sblasterComCopySeg = sblasterComSeg;
    sblasterComCopyOfs = sblasterComOfs;
    pfVar2 = sblasterComOfs;
    paudioComSeg =(uint16_t)( pfVar1);
    adlibComOfs =(uint16_t)( stshStoreFile_2((far_t *)"adlib.com",(char *)MK_FP(0x2410, 0x1),(uint16_t)unaff_BP));
    adlibComSeg =(uint16_t)( pfVar2);
    adlibgComOfs =(uint16_t)( stshStoreFile_2((far_t *)"adlibg.com",(char *)MK_FP(0x2410, 0x1),(uint16_t)unaff_BP));
    audioPlaceholder3.seg = 0;
    audioPlaceholder3.ofs = 0;
    musDriver0Seg = 0;
    musDriver0Ofs = 0;
    adlibgComSeg =(uint16_t)( pfVar2);
    sbfmAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"sbfm.adv",(char *)MK_FP(0x2410, 0x1),(uint16_t)unaff_BP));
    audioPlaceholder0.seg = 0;
    audioPlaceholder0.ofs = 0;
    audioPlaceholder1.seg = 0;
    audioPlaceholder1.ofs = 0;
    sbfmAdvSeg =(uint16_t)( pfVar2);
    sbp2fmAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"sbp2fm.adv",(char *)MK_FP(0x2410, 0x1),(uint16_t)unaff_BP));
    sbp2fmAdvSeg =(uint16_t)( pfVar2);
    sbp1fmAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"sbp1fm.adv",(char *)MK_FP(0x2410, 0x1),(uint16_t)unaff_BP));
    sbp1fmAdvSeg =(uint16_t)( pfVar2);
    pasfmAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"pasfm.adv",(char *)MK_FP(0x2410, 0x1),(uint16_t)unaff_BP));
    pasfmAdvSeg =(uint16_t)( pfVar2);
    pasoplAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"pasopl.adv",(char *)MK_FP(0x2410, 0x1),(uint16_t)unaff_BP));
    pasoplAdvSeg =(uint16_t)( pfVar2);
    adlibAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"adlib.adv",(char *)MK_FP(0x2410, 0x1),(uint16_t)unaff_BP));
    adlibAdvSeg =(uint16_t)( pfVar2);
    adlibgAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"adlibg.adv",(char *)MK_FP(0x2410, 0x1),(uint16_t)unaff_BP));
    adlibgAdvSeg =(uint16_t)( pfVar2);
    mt32mpuAdvOfs =(uint16_t)( stshStoreFile_2((far_t *)"mt32mpu.adv",(char *)MK_FP(0x2410, 0x1),(uint16_t)unaff_BP));
    mt32mpuAdvSeg =(uint16_t)( pfVar2);
  }
  else {
    midpakAd.ofs = (uint16_t)ovr_stshAllocStub(unaff_BP);
    midpakAd.seg = in_DX;
    cmidpakComOfs = ovr_stshAllocStub(unaff_BP);
    cmidpakComSeg = in_DX;
    ibmsndComOfs = ovr_stshAllocStub(unaff_BP);
    ibmsndComSeg = in_DX;
    sblasterComOfs = ovr_stshAllocStub(unaff_BP);
    audioPlaceholder2.seg = 0;
    audioPlaceholder2.ofs = 0;
    sblasterComSeg = in_DX;
    fibmbakComOfs = ovr_stshAllocStub(unaff_BP);
    fibmbakComSeg = in_DX;
    pfVar1 = ovr_stshAllocStub(unaff_BP);
    sbproComOfs =(uint16_t)( pfVar1);
    sbproComSeg = in_DX;
    sbproComCopyOfs =(uint16_t)( pfVar1);
    sbproComCopySeg = in_DX;
    paudioComOfs = ovr_stshAllocStub(unaff_BP);
    sblasterComCopySeg = sblasterComSeg;
    sblasterComCopyOfs = sblasterComOfs;
    pfVar2 = sblasterComOfs;
    paudioComSeg =(uint16_t)( pfVar1);
    adlibComOfs = ovr_stshAllocStub(unaff_BP);
    adlibComSeg =(uint16_t)( pfVar2);
    adlibgComOfs = ovr_stshAllocStub(unaff_BP);
    audioPlaceholder3.seg = 0;
    audioPlaceholder3.ofs = 0;
    musDriver0Seg = 0;
    musDriver0Ofs = 0;
    adlibgComSeg =(uint16_t)( pfVar2);
    sbfmAdvOfs = ovr_stshAllocStub(unaff_BP);
    audioPlaceholder0.seg = 0;
    audioPlaceholder0.ofs = 0;
    audioPlaceholder1.seg = 0;
    audioPlaceholder1.ofs = 0;
    sbfmAdvSeg =(uint16_t)( pfVar2);
    sbp2fmAdvOfs = ovr_stshAllocStub(unaff_BP);
    sbp2fmAdvSeg =(uint16_t)( pfVar2);
    sbp1fmAdvOfs = ovr_stshAllocStub(unaff_BP);
    sbp1fmAdvSeg =(uint16_t)( pfVar2);
    pasfmAdvOfs = ovr_stshAllocStub(unaff_BP);
    pasfmAdvSeg =(uint16_t)( pfVar2);
    pasoplAdvOfs = ovr_stshAllocStub(unaff_BP);
    pasoplAdvSeg =(uint16_t)( pfVar2);
    adlibAdvOfs = ovr_stshAllocStub(unaff_BP);
    adlibAdvSeg =(uint16_t)( pfVar2);
    adlibgAdvOfs = ovr_stshAllocStub(unaff_BP);
    adlibgAdvSeg =(uint16_t)( pfVar2);
    mt32mpuAdvOfs = ovr_stshAllocStub(unaff_BP);
    mt32mpuAdvSeg =(uint16_t)( pfVar2);
  }
  return;
}


/* 4b0a:1820 */

void __cdecl16far grabBldLbm(int16_t file_normal,int16_t file_ruin,uint16_t index,uint16_t arg4,uint16_t arg5)

{
  uint16_t segArg;
  stg_tmp_t *tg;
  far_t *pfVar1;
  cte_t *stored;
  uint16_t pg;
  uint16_t in_DX;
  uint16_t uVar3;
  uint16_t uVar5;
  int16_t unaff_DI;
  uint32_t p;
  far_t pixels;
  far_t pixels_00;
  far_t pixels_01;
  far_t pixels_02;
  far_t pixels_03;
  far_t pixels_04;
  far_t pixels_05;
  far_t pixels_06;
  far_t pixels_07;
  far_t pixels_08;
  far_t pixels_09;
  far_t pixels_10;
  far_t pixels_11;
  far_t pixels_12;
  far_t pixels_13;
  far_t pixels_14;
  far_t pixels_15;
  far_t pixels_16;
  
  tg = grabLbmTR(file_normal);
  pixels.seg = 0;
  pixels.ofs = (tg->aptr).seg;
  pfVar1 = ovr_stshRleType2((far_t *)(&tg->aptr)->ofs,pixels,130,99,194,26,-1,unaff_DI,0,0);
  asm { mov segArg,dx };
  stored = stsh_store((uint8_t *)pfVar1, segArg, &stshSegTmp);
  BldGfxNormal[index * 3].seg = stshSegTmp;
  ((far_t far *)BldGfxNormal + index * 3)->ofs = (uint16_t)stored;
  pixels_00.seg = 100;
  pixels_00.ofs = (tg->aptr).seg;
  pfVar1 = ovr_stshRleType2((far_t *)(&tg->aptr)->ofs,pixels_00,130,199,194,26,-1,unaff_DI,0,0);
  asm { mov segArg,dx };
  stored = stsh_store((uint8_t *)pfVar1, segArg, &stshSegTmp);
  BldGfxNormal[1 + index * 3].seg = stshSegTmp;
  ((far_t *)(BldGfxNormal + 1) + index * 3)->ofs = (uint16_t)stored;
  pixels_01.seg = 200;
  pixels_01.ofs = (tg->aptr).seg;
  pfVar1 = ovr_stshRleType2((far_t *)(&tg->aptr)->ofs,pixels_01,130,299,194,26,-1,unaff_DI,0,0);
  asm { mov segArg,dx };
  stored = stsh_store((uint8_t *)pfVar1, segArg, &stshSegTmp);
  BldGfxNormal[2 + index * 3].seg = stshSegTmp;
  ((far_t *)(BldGfxNormal + 2) + index * 3)->ofs = (uint16_t)stored;
  pixels_02.seg = 0;
  pixels_02.ofs = (tg->aptr).seg;
  pfVar1 = ovr_stshRleType2((far_t *)(&tg->aptr)->ofs,pixels_02,65,99,129,26,-1,unaff_DI,0,0);
  asm { mov segArg,dx };
  stored = stsh_store((uint8_t *)pfVar1, segArg, &stshSegTmp);
  BldGfxNormal[3 + index * 3].seg = stshSegTmp;
  ((far_t *)(BldGfxNormal + 3) + index * 3)->ofs = (uint16_t)stored;
  pixels_03.seg = 100;
  pixels_03.ofs = (tg->aptr).seg;
  pfVar1 = ovr_stshRleType2((far_t *)(&tg->aptr)->ofs,pixels_03,65,199,129,26,-1,unaff_DI,0,0);
  asm { mov segArg,dx };
  stored = stsh_store((uint8_t *)pfVar1, segArg, &stshSegTmp);
  BldGfxNormal[4 + index * 3].seg = stshSegTmp;
  ((far_t *)(BldGfxNormal + 4) + index * 3)->ofs = (uint16_t)stored;
  pixels_04.seg = 200;
  pixels_04.ofs = (tg->aptr).seg;
  pfVar1 = ovr_stshRleType2((far_t *)(&tg->aptr)->ofs,pixels_04,65,299,129,26,-1,unaff_DI,0,0);
  asm { mov segArg,dx };
  stored = stsh_store((uint8_t *)pfVar1, segArg, &stshSegTmp);
  BldGfxNormal[5 + index * 3].seg = stshSegTmp;
  ((far_t *)(BldGfxNormal + 5) + index * 3)->ofs = (uint16_t)stored;
  pixels_05.seg = 0;
  pixels_05.ofs = (tg->aptr).seg;
  pfVar1 = ovr_stshRleType2((far_t *)(&tg->aptr)->ofs,pixels_05,0,99,64,26,-1,unaff_DI,0,0);
  asm { mov segArg,dx };
  stored = stsh_store((uint8_t *)pfVar1, segArg, &stshSegTmp);
  BldGfxNormal[6 + index * 3].seg = stshSegTmp;
  ((far_t *)(BldGfxNormal + 6) + index * 3)->ofs = (uint16_t)stored;
  pixels_06.seg = 100;
  pixels_06.ofs = (tg->aptr).seg;
  pfVar1 = ovr_stshRleType2((far_t *)(&tg->aptr)->ofs,pixels_06,0,199,64,26,-1,unaff_DI,0,0);
  asm { mov segArg,dx };
  stored = stsh_store((uint8_t *)pfVar1, segArg, &stshSegTmp);
  BldGfxNormal[7 + index * 3].seg = stshSegTmp;
  ((far_t *)(BldGfxNormal + 7) + index * 3)->ofs = (uint16_t)stored;
  pixels_07.seg = 200;
  pixels_07.ofs = (tg->aptr).seg;
  pfVar1 = ovr_stshRleType2((far_t *)(&tg->aptr)->ofs,pixels_07,0,299,64,26,-1,unaff_DI,0,0);
  asm { mov segArg,dx };
  stored = stsh_store((uint8_t *)pfVar1, segArg, &stshSegTmp);
  BldGfxNormal[8 + index * 3].seg = stshSegTmp;
  ((far_t *)(BldGfxNormal + 8) + index * 3)->ofs = (uint16_t)stored;
  stgFreeTmp(tg,in_DX);
  if (file_ruin != 0) {
    pg = (uint16_t)grabLbmTR(file_ruin);
    pixels_08.seg = 0;
    pixels_08.ofs = *(uint *)(pg + 0x302);
    (*(uint16_t *)((uint8_t *)&(p))) = ovr_stshRleType2((far_t *)*(uint16_t *)(pg + 0x300),pixels_08,130,99,194,26,-1,unaff_DI,0,0);
    asm { mov uVar3,dx };
    (*(uint16_t *)((uint8_t *)&(p) + 2)) = uVar3;
    stored = stsh_store((uint8_t *)(far_t *)p, uVar3, &stshSegTmp);
    BldGfxRuin[index * 3].seg = stshSegTmp;
    ((far_t far *)BldGfxRuin + index * 3)->ofs = (uint16_t)stored;
    pixels_09.seg = 100;
    pixels_09.ofs = *(uint16_t *)(pg + 0x302);
    pfVar1 = ovr_stshRleType2((far_t *)*(uint16_t *)(pg + 0x300),pixels_09,130,199,194,26,-1,unaff_DI,0,0);
    asm { mov segArg,dx };
    stored = stsh_store((uint8_t *)pfVar1, segArg, &stshSegTmp);
    BldGfxRuin[1 + index * 3].seg = stshSegTmp;
    ((far_t *)(BldGfxRuin + 1) + index * 3)->ofs = (uint16_t)stored;
    pixels_10.seg = 200;
    pixels_10.ofs = *(uint16_t *)(pg + 0x302);
    pfVar1 = ovr_stshRleType2((far_t *)*(uint16_t *)(pg + 0x300),pixels_10,130,299,194,26,-1,unaff_DI,0,0);
    asm { mov segArg,dx };
    stored = stsh_store((uint8_t *)pfVar1, segArg, &stshSegTmp);
    BldGfxRuin[2 + index * 3].seg = stshSegTmp;
    ((far_t *)(BldGfxRuin + 2) + index * 3)->ofs = (uint16_t)stored;
    pixels_11.seg = 0;
    pixels_11.ofs = *(uint *)(pg + 0x302);
    pfVar1 = ovr_stshRleType2((far_t *)*(uint16_t *)(pg + 0x300),pixels_11,65,99,129,26,-1,unaff_DI,0,0);
    asm { mov segArg,dx };
    stored = stsh_store((uint8_t *)pfVar1, segArg, &stshSegTmp);
    BldGfxRuin[3 + index * 3].seg = stshSegTmp;
    ((far_t *)(BldGfxRuin + 3) + index * 3)->ofs = (uint16_t)stored;
    pixels_12.seg = 100;
    pixels_12.ofs = *(uint16_t *)(pg + 0x302);
    pfVar1 = ovr_stshRleType2((far_t *)*(uint16_t *)(pg + 0x300),pixels_12,65,199,129,26,-1,unaff_DI,0,0);
    asm { mov segArg,dx };
    stored = stsh_store((uint8_t *)pfVar1, segArg, &stshSegTmp);
    BldGfxRuin[4 + index * 3].seg = stshSegTmp;
    ((far_t *)(BldGfxRuin + 4) + index * 3)->ofs = (uint16_t)stored;
    pixels_13.seg = 200;
    pixels_13.ofs = *(uint16_t *)(pg + 0x302);
    pfVar1 = ovr_stshRleType2((far_t *)*(uint16_t *)(pg + 0x300),pixels_13,65,299,129,26,-1,unaff_DI,0,0);
    asm { mov segArg,dx };
    stored = stsh_store((uint8_t *)pfVar1, segArg, &stshSegTmp);
    BldGfxRuin[5 + index * 3].seg = stshSegTmp;
    ((far_t *)(BldGfxRuin + 5) + index * 3)->ofs = (uint16_t)stored;
    pixels_14.seg = 0;
    pixels_14.ofs = *(uint *)(pg + 0x302);
    pfVar1 = ovr_stshRleType2((far_t *)*(uint16_t *)(pg + 0x300),pixels_14,0,99,64,26,-1,unaff_DI,0,0);
    asm { mov uVar5,dx };
    stored = stsh_store((uint8_t *)pfVar1, uVar5, &stshSegTmp);
    BldGfxRuin[6 + index * 3].seg = stshSegTmp;
    ((far_t *)(BldGfxRuin + 6) + index * 3)->ofs = (uint16_t)stored;
    pixels_15.seg = 100;
    pixels_15.ofs = *(uint16_t *)(pg + 0x302);
    pfVar1 = ovr_stshRleType2((far_t *)*(uint16_t *)(pg + 0x300),pixels_15,0,199,64,26,-1,unaff_DI,0,0);
    asm { mov segArg,dx };
    stored = stsh_store((uint8_t *)pfVar1, segArg, &stshSegTmp);
    BldGfxRuin[7 + index * 3].seg = stshSegTmp;
    ((far_t *)(BldGfxRuin + 7) + index * 3)->ofs = (uint16_t)stored;
    pixels_16.seg = 200;
    pixels_16.ofs = *(uint16_t *)(pg + 0x302);
    pfVar1 = ovr_stshRleType2((far_t *)*(uint16_t *)(pg + 0x300),pixels_16,0,299,64,26,-1,unaff_DI,0,0);
    asm { mov segArg,dx };
    stored = stsh_store((uint8_t *)pfVar1, segArg, &stshSegTmp);
    BldGfxRuin[8 + index * 3].seg = stshSegTmp;
    ((far_t *)(BldGfxRuin + 8) + index * 3)->ofs = (uint16_t)stored;
    stgFreeTmp((stg_tmp_t *)pg,uVar3);
  }
  return;
}


