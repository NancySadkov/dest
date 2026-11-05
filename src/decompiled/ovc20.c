/*
 * ovc20.c - recovered from STRONG.EXE
 * memory block: OVC20
 * range: 4b0a:0000 - 4b0a:1faf
 * functions: 23
 */
#include "recovered.h"


/* 4b0a:0000 */

/* Remaps unique colors, such as the those in portraits and biome skylines */

void __cdecl16far stshUniqueColorsRemap(stg_tmp_t *gfx)

{
  uint si;
  uint i;
  undefined2 unaff_SS;
  uint8_t cmap [769];
  byte c;
  
  for (i = 0; i < 64000; i = i + 1) {
    c = *(byte *)((((stg_tmp_t *)gfx)->aptr).ofs + i);
    if ((c < 0x50) || (0x7f < c)) {
      if ((0x7f < c) && (c < 0xd0)) {
        c = c - 0x30;
      }
    }
    else {
      c = c + 0x50;
    }
    *(byte *)((((stg_tmp_t *)gfx)->aptr).ofs + i) = c;
  }
  _fmemmove(cmap,((stg_tmp_t *)gfx)->cmap,0x300);
  for (i = 0; i < 0x100; i = i + 1) {
    if ((i < 0x50) || (0x9f < i)) {
      si = i;
      if ((0x9f < i) && (i < 0xd0)) {
        si = i - 0x50;
      }
    }
    else {
      si = i + 0x30;
    }
    ((stg_tmp_t *)gfx)->cmap[i * 3] = cmap[si * 3];
    ((stg_tmp_t *)gfx)->cmap[i * 3 + 1] = cmap[si * 3 + 1];
    ((stg_tmp_t *)gfx)->cmap[i * 3 + 2] = cmap[si * 3 + 2];
  }
  return;
}



/* 4b0a:010c */

void __cdecl16far OVC20_4b0a_010c(void)

{
  uint16_t *puVar1;
  int iVar2;
  uint16_t uStack_6;
  uint16_t uStack_4;
  
  iVar2 = 0;
  uStack_4 = StshCtPtr2.seg;
  uStack_6 = StshCtPtr2.ofs;
  while (uStack_6 != 0 || uStack_4 != 0) {
    printf("uc%lx %d len %ld loc %ld \r",uStack_6);
    iVar2 = iVar2 + 1;
    puVar1 = (uint16_t *)(uStack_6 + 0xb);
    uStack_6 = *(uint16_t *)(uStack_6 + 9);
    uStack_4 = *puVar1;
  }
  printf("N UP = %d \r",iVar2);
  ovr_gameProcessKey();
  iVar2 = 0;
  uStack_4 = Stsh_2410_47f6.seg;
  uStack_6 = Stsh_2410_47f6.ofs;
  while (uStack_6 != 0 || uStack_4 != 0) {
    printf("dc%lx %d ln %ld lc %ld @%lx \r",uStack_6);
    iVar2 = iVar2 + 1;
    puVar1 = (uint16_t *)(uStack_6 + 0xf);
    uStack_6 = *(uint16_t *)(uStack_6 + 0xd);
    uStack_4 = *puVar1;
  }
  printf("N DOWN = %d \r",iVar2);
  ovr_gameProcessKey();
  return;
}



/* 4b0a:01f8 */

/* Grabs LBM with transparency remap */

stg_tmp_t * __cdecl16far grabLbmTR(int16_t file_id)

{
  undefined2 uVar1;
  stg_tmp_t *psVar2;
  stg_tmp_t *r;
  far_t pixels;
  far_t pixels_00;
  
  r = ovr_grabLbm(file_id,0,0);
  psVar2 = (stg_tmp_t *)r;
  uVar1 = (undefined2)((ulong)r >> 0x10);
  pixels.seg = (psVar2->aptr).seg;
  pixels.ofs = (&psVar2->aptr)->ofs;
  ovr_grabRemap(pixels,0x14,0x0);
  pixels_00.seg = (psVar2->aptr).seg;
  pixels_00.ofs = (&psVar2->aptr)->ofs;
  ovr_grabRemap(pixels_00,0xff,0x0);
  return r;
}



/* 4b0a:024e */

void __cdecl16far stgFreeTmp(stg_tmp_t *tg)

{
  undefined2 uVar1;
  far_t handle;
  
  uVar1 = (undefined2)((ulong)tg >> 0x10);
  handle.seg = (((stg_tmp_t *)tg)->bptr).seg;
  handle.ofs = (&((stg_tmp_t *)tg)->bptr)->ofs;
  ovr_stshFree(handle);
  ovr_stshFree(far_from_u32((uint32_t)(tg)));
  return;
}



/* 4b0a:0276 */

void __cdecl16far stubyBufSrcToDst(int src,int dst)

{
  uint16_t uVar1;
  int j;
  int i;
  
  for (i = 0; i < 3; i = i + 1) {
    for (j = 0; j < 3; j = j + 1) {
      uVar1 = ((far_t *)BldGfxNormal + j + (src + i) * 3)->ofs;
      *(undefined2 *)((int)&BldGfxNormal[0].seg + (dst + i) * 0xc + j * 4) =
           *(undefined2 *)((int)&BldGfxNormal[0].seg + (src + i) * 0xc + j * 4);
      ((far_t *)BldGfxNormal + j + (dst + i) * 3)->ofs = uVar1;
      uVar1 = ((far_t *)BldGfxRuin + j + (src + i) * 3)->ofs;
      *(undefined2 *)((int)&BldGfxRuin[0].seg + (dst + i) * 0xc + j * 4) =
           *(undefined2 *)((int)&BldGfxRuin[0].seg + (src + i) * 0xc + j * 4);
      ((far_t *)BldGfxRuin + j + (dst + i) * 3)->ofs = uVar1;
    }
  }
  return;
}



/* 4b0a:032c */

void __cdecl16far stshStubifyFromSrc(int src,int dst)

{
  uint16_t uVar1;
  int i;
  
  for (i = 0; i < 3; i = i + 1) {
    uVar1 = ((far_t *)BldGfxNormal + i + src * 3)->ofs;
    *(undefined2 *)((int)&BldGfxNormal[0].seg + dst * 0xc + i * 4) =
         *(undefined2 *)((int)&BldGfxNormal[0].seg + src * 0xc + i * 4);
    ((far_t *)BldGfxNormal + i + dst * 3)->ofs = uVar1;
    uVar1 = ((far_t *)BldGfxRuin + i + src * 3)->ofs;
    *(undefined2 *)((int)&BldGfxRuin[0].seg + dst * 0xc + i * 4) =
         *(undefined2 *)((int)&BldGfxRuin[0].seg + src * 0xc + i * 4);
    ((far_t *)BldGfxRuin + i + dst * 3)->ofs = uVar1;
  }
  return;
}



/* 4b0a:03cd */

void __cdecl16far StubifyCopy1to0_alt(int index)

{
  uint16_t uVar1;
  
  uVar1 = ((far_t *)(BldGfxNormal + 1) + index * 3)->ofs;
  *(undefined2 *)((int)&BldGfxNormal[0].seg + index * 0xc) =
       *(undefined2 *)((int)&BldGfxNormal[1].seg + index * 0xc);
  ((far_t *)BldGfxNormal + index * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxNormal + 1) + index * 3)->ofs;
  *(undefined2 *)((int)&BldGfxNormal[2].seg + index * 0xc) =
       *(undefined2 *)((int)&BldGfxNormal[1].seg + index * 0xc);
  ((far_t *)(BldGfxNormal + 2) + index * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxRuin + 1) + index * 3)->ofs;
  *(undefined2 *)((int)&BldGfxRuin[0].seg + index * 0xc) =
       *(undefined2 *)((int)&BldGfxRuin[1].seg + index * 0xc);
  ((far_t *)BldGfxRuin + index * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxRuin + 1) + index * 3)->ofs;
  *(undefined2 *)((int)&BldGfxRuin[2].seg + index * 0xc) =
       *(undefined2 *)((int)&BldGfxRuin[1].seg + index * 0xc);
  ((far_t *)(BldGfxRuin + 2) + index * 3)->ofs = uVar1;
  return;
}



/* 4b0a:04a7 */

void __cdecl16far stshStubifyCopy1to0(int index)

{
  uint16_t uVar1;
  
  uVar1 = ((far_t *)(BldGfxNormal + 1) + index * 3)->ofs;
  *(undefined2 *)((int)&BldGfxNormal[0].seg + index * 0xc) =
       *(undefined2 *)((int)&BldGfxNormal[1].seg + index * 0xc);
  ((far_t *)BldGfxNormal + index * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxNormal + 1) + index * 3)->ofs;
  *(undefined2 *)((int)&BldGfxNormal[2].seg + index * 0xc) =
       *(undefined2 *)((int)&BldGfxNormal[1].seg + index * 0xc);
  ((far_t *)(BldGfxNormal + 2) + index * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxNormal + 4) + index * 3)->ofs;
  *(undefined2 *)((int)&BldGfxNormal[3].seg + index * 0xc) =
       *(undefined2 *)((int)&BldGfxNormal[4].seg + index * 0xc);
  ((far_t *)(BldGfxNormal + 3) + index * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxNormal + 4) + index * 3)->ofs;
  *(undefined2 *)((int)&BldGfxNormal[5].seg + index * 0xc) =
       *(undefined2 *)((int)&BldGfxNormal[4].seg + index * 0xc);
  ((far_t *)(BldGfxNormal + 5) + index * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxNormal + 7) + index * 3)->ofs;
  *(undefined2 *)((int)&BldGfxNormal[6].seg + index * 0xc) =
       *(undefined2 *)((int)&BldGfxNormal[7].seg + index * 0xc);
  ((far_t *)(BldGfxNormal + 6) + index * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxNormal + 7) + index * 3)->ofs;
  *(undefined2 *)((int)&BldGfxNormal[8].seg + index * 0xc) =
       *(undefined2 *)((int)&BldGfxNormal[7].seg + index * 0xc);
  ((far_t *)(BldGfxNormal + 8) + index * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxRuin + 1) + index * 3)->ofs;
  *(undefined2 *)((int)&BldGfxRuin[0].seg + index * 0xc) =
       *(undefined2 *)((int)&BldGfxRuin[1].seg + index * 0xc);
  ((far_t *)BldGfxRuin + index * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxRuin + 1) + index * 3)->ofs;
  *(undefined2 *)((int)&BldGfxRuin[2].seg + index * 0xc) =
       *(undefined2 *)((int)&BldGfxRuin[1].seg + index * 0xc);
  ((far_t *)(BldGfxRuin + 2) + index * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxRuin + 4) + index * 3)->ofs;
  *(undefined2 *)((int)&BldGfxRuin[3].seg + index * 0xc) =
       *(undefined2 *)((int)&BldGfxRuin[4].seg + index * 0xc);
  ((far_t *)(BldGfxRuin + 3) + index * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxRuin + 4) + index * 3)->ofs;
  *(undefined2 *)((int)&BldGfxRuin[5].seg + index * 0xc) =
       *(undefined2 *)((int)&BldGfxRuin[4].seg + index * 0xc);
  ((far_t *)(BldGfxRuin + 5) + index * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxRuin + 7) + index * 3)->ofs;
  *(undefined2 *)((int)&BldGfxRuin[6].seg + index * 0xc) =
       *(undefined2 *)((int)&BldGfxRuin[7].seg + index * 0xc);
  ((far_t *)(BldGfxRuin + 6) + index * 3)->ofs = uVar1;
  uVar1 = ((far_t *)(BldGfxRuin + 7) + index * 3)->ofs;
  *(undefined2 *)((int)&BldGfxRuin[8].seg + index * 0xc) =
       *(undefined2 *)((int)&BldGfxRuin[7].seg + index * 0xc);
  ((far_t *)(BldGfxRuin + 8) + index * 3)->ofs = uVar1;
  return;
}



/* 4b0a:0721 */

void __cdecl16far stshWriteFile(int fhandle,far_t buf,DW sz)

{
  uint16_t uVar1;
  uint wrsz;
  void *pbuf;
  
  do {
    if ((0 < (int)sz.hi) || ((wrsz = sz.lo, -1 < (int32_t)dw_to_u32(sz) && (0xbfff < sz.lo)))) {
      wrsz = 0xc000;
    }
    pbuf = (void *)ovr_mkp(buf.ofs,buf.seg);
    write(fhandle,(void *)pbuf,wrsz);
    buf.seg = (uint16_t)((ulong)pbuf >> 0x10);
    buf.ofs = (int)(void *)pbuf + wrsz;
    uVar1 = sz.lo - wrsz;
    sz.hi = sz.hi - (sz.lo < wrsz);
    sz.lo = uVar1;
  } while (uVar1 != 0 || sz.hi != 0);
  return;
}



/* 4b0a:077a */

void __cdecl16far stshReadFile(int handle,far_t dst,DW nbytes)

{
  uint16_t uVar1;
  uint len;
  void *pdst;
  
  do {
    if ((0 < (int)nbytes.hi) || ((len = nbytes.lo, -1 < (int32_t)dw_to_u32(nbytes) && (0xbfff < nbytes.lo)))) {
      len = 0xc000;
    }
    pdst = (void *)ovr_mkp(dst.ofs,dst.seg);
    read(handle,(void *)pdst,len);
    dst.seg = (uint16_t)((ulong)pdst >> 0x10);
    dst.ofs = (int)(void *)pdst + len;
    uVar1 = nbytes.lo - len;
    nbytes.hi = nbytes.hi - (nbytes.lo < len);
    nbytes.lo = uVar1;
  } while (uVar1 != 0 || nbytes.hi != 0);
  return;
}



/* 4b0a:07d3 */

/* anms points to the array 0x1e sized anim_t entries,
   the last entry has nframes == 0
   the seq can have upto nanims total
   the function returns array of anim file stubs */

spr_t * __cdecl16far stshSpriteStub(anm_t *anms,uint16_t nanims)

{
  uint k;
  spr_t *ofs;
  anm_t *psrc;
  uint j;
  uint i;
  uint16_t ssrc;
  spr_t *dst;
  far_t pstub;
  spr_t *pdst;
  undefined2 sdst;
  
  if (0x4e < StshSprIndex) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x36);
  }
  ofs = (spr_t *)StshSprites + StshSprIndex;
  StshSprIndex = StshSprIndex + 1;
  dst = (spr_t *)ovr_mkp((uint16_t)ofs,(*(uint16_t *)((uint8_t *)&(StshSprites) + 2)));
  _fsetmem(dst,0xb0,0);
  i = 0;
  while( true ) {
    sdst = (uint16_t)((uint32_t)dst >> 0x10);
    pdst = (spr_t *)dst;
    if (nanims <= i) {
      return dst;
    }
    ssrc = (uint16_t)((ulong)anms >> 0x10);
    psrc = (anm_t *)anms;
    if (psrc[i].nframes == 0x0) break;
    k = (uint)(psrc + i)->frmid;
    pdst->frames[k - 0x16].seg = ssrc;
    (pdst->frames + (k - 0x16))->ofs = (uint16_t)(psrc + i);
    for (j = 0; j < psrc[i].nframes; j = j + 1) {
      if (j == 0) {
        pstub = ovr_stshAllocStub();
        pdst->frames[k].seg = pstub.seg;
        (pdst->frames + k)->ofs = pstub.ofs;
      }
      else {
        ovr_stshAllocStub();
      }
    }
    i = i + 1;
  }
  return dst;
}



/* 4b0a:08ee */

undefined1 * __cdecl16far
OVC20_4b0a_08ee(uint16_t param_1,uint16_t param_2,uint param_3,uint16_t param_4)

{
  undefined2 uVar1;
  uint16_t uVar2;
  undefined1 *puVar3;
  bool bVar4;
  far_t fVar5;
  far_t ptr_base;
  undefined1 *puVar6;
  ulong b;
  DW sz;
  far_t handle;
  
  if (StshCount < 0xd93) {
    b = (ulong)StshCount;
    StshCount = StshCount + 1;
    fVar5 = far_from_u32((uint32_t)(LXMUL_at_(0x15,b)));
    ptr_base.seg = StshCtPtr.seg;
    ptr_base.ofs = StshCtPtr.ofs;
    fVar5 = PADD_at_(ptr_base,fVar5);
    puVar6 = (undefined1 *)ovr_mkp(fVar5.ofs,fVar5.seg);
    puVar3 = (undefined1 *)puVar6;
    uVar1 = (undefined2)((ulong)puVar6 >> 0x10);
    *(uint16_t *)(puVar3 + 7) = param_4;
    *(uint *)(puVar3 + 5) = param_3;
    *puVar6 = 0;
    uVar2 = StshCtOfs.lo;
    *(uint16_t *)(puVar3 + 3) = StshCtOfs.hi;
    *(uint16_t *)(puVar3 + 1) = uVar2;
    *(undefined2 *)(puVar3 + 0x13) = 0;
    *(undefined2 *)(puVar3 + 0x11) = 0;
    bVar4 = CARRY2(StshCtOfs.lo,param_3);
    StshCtOfs.lo = StshCtOfs.lo + param_3;
    StshCtOfs.hi = StshCtOfs.hi + param_4 + (uint)bVar4;
    *(undefined2 *)(puVar3 + 0xb) = 0;
    *(undefined2 *)(puVar3 + 9) = 0;
    *(undefined2 *)(puVar3 + 0xf) = 0;
    *(undefined2 *)(puVar3 + 0xd) = 0;
    sz.hi = param_4;
    sz.lo = param_3;
    fVar5.seg = param_2;
    fVar5.ofs = param_1;
    stshWriteFile(StshFile,fVar5,sz);
    handle.seg = param_2;
    handle.ofs = param_1;
    ovr_stshFree(handle);
    return puVar3;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x24);
}



/* 4b0a:09ce */

cte_t * __cdecl16far stshStoreFile(uint8_t *data)

{
  undefined2 uVar1;
  uint16_t uVar2;
  cte_t *psVar4;
  bool bVar3;
  far_t fVar4;
  far_t ptr_base;
  cte_t *pcVar5;
  ulong b;
  DW sz_00;
  DW sz;
  
  if (5 < *data) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x18);
  }
                    /* WARNING: Switch is manually overridden */
  switch((undefined4)*(undefined2 *)((uint)*data * 2 + 0xb69)) {
  case 0x4ba94:
    return (cte_t *)data;
  case 0x4ba9d:
    sz.lo = *(uint *)((uint8_t *)data + 1) + 9;
    sz.hi = *(int *)((uint8_t *)data + 3) + (uint)(0xfff6 < *(uint *)((uint8_t *)data + 1));
    break;
  case 0x4bab6:
    sz.lo = *(uint *)((uint8_t *)data + 6) + 0xe;
    sz.hi = *(int *)((uint8_t *)data + 8) + (uint)(0xfff1 < *(uint *)((uint8_t *)data + 6));
    break;
  case 0x4bacf:
    sz.lo = *(int *)((uint8_t *)data + 5) + 0xd;
    sz.hi = 0;
    break;
  case 0x4bae3:
    sz.lo = *(uint *)((uint8_t *)data + 0xc) + 0x14;
    sz.hi = *(int *)((uint8_t *)data + 0xe) + (uint)(0xffeb < *(uint *)((uint8_t *)data + 0xc));
  }
  if (StshCount < 0xd93) {
    b = (ulong)StshCount;
    StshCount = StshCount + 1;
    fVar4 = far_from_u32((uint32_t)(LXMUL_at_(0x15,b)));
    ptr_base.seg = StshCtPtr.seg;
    ptr_base.ofs = StshCtPtr.ofs;
    fVar4 = PADD_at_(ptr_base,fVar4);
    pcVar5 = (cte_t *)ovr_mkp(fVar4.ofs,fVar4.seg);
    psVar4 = (cte_t *)pcVar5;
    uVar1 = (undefined2)((ulong)pcVar5 >> 0x10);
    (psVar4->sz).hi = sz.hi;
    (&psVar4->sz)->lo = sz.lo;
    pcVar5->state = 0x0;
    uVar2 = StshCtOfs.lo;
    (psVar4->ofs).hi = StshCtOfs.hi;
    (&psVar4->ofs)->lo = uVar2;
    (psVar4->info + 10)[0] = 0x0;
    (psVar4->info + 10)[1] = 0x0;
    (psVar4->info + 8)[0] = 0x0;
    (psVar4->info + 8)[1] = 0x0;
    bVar3 = CARRY2(StshCtOfs.lo,sz.lo);
    StshCtOfs.lo = StshCtOfs.lo + sz.lo;
    StshCtOfs.hi = StshCtOfs.hi + sz.hi + (uint)bVar3;
    (psVar4->info + 2)[0] = 0x0;
    (psVar4->info + 2)[1] = 0x0;
    psVar4->info[0] = 0x0;
    psVar4->info[1] = 0x0;
    (psVar4->info + 6)[0] = 0x0;
    (psVar4->info + 6)[1] = 0x0;
    (psVar4->info + 4)[0] = 0x0;
    (psVar4->info + 4)[1] = 0x0;
    if (DebugVerbose != false) {
      printf("type %d len %ld \r",(uint)*data);
      ovr_biosReadKey();
    }
    sz_00.hi = sz.hi;
    sz_00.lo = sz.lo;
    stshWriteFile(StshFile,far_from_u32((uint32_t)(data)),sz_00);
    ovr_stshFree(far_from_u32((uint32_t)(data)));
    return pcVar5;
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
  uint16_t freq;
  uint16_t file_id;
  uint uVar2;
  uint uVar3;
  uint16_t in_DX;
  uint uVar4;
  int iVar5;
  int i;
  undefined2 uVar6;
  uint16_t unaff_SS;
  uint32_t nbytes;
  void *pvVar7;
  long lVar8;
  cte_t *pcVar9;
  far_t fVar10;
  far_t buf;
  far_t buf_00;
  long lVar11;
  voc_t voc;
  uint uStack_a;
  uint uStack_8;
  undefined2 sz;
  
  AudioAssetsReady1 = 1;
  AudioAssetsReady2 = 1;
  uStack_8 = 0;
  uStack_a = 0;
  i = 0;
  do {
                    /* ;0x90 = total .xmi and .voc files */
    if (0x89 < i) {
      return;
    }
    pcVar1 = _fstrstr((char *)*(undefined2 *)(*(int *)(i * 2) * 4),(char *)".xmi");
    if (pcVar1 == (char *)0x0 && in_DX == 0) {
      *(undefined2 *)(i * 2 + 0x114) = 1;
    }
    else {
      *(undefined2 *)(i * 2 + 0x114) = 0;
    }
    if (grab == '\0') {
      fVar10 = ovr_stshAllocStub();
      in_DX = fVar10.seg;
      ((uint16_t *)(i * 4))[1] = in_DX;
      *(uint16_t *)(i * 4) = fVar10.ofs;
    }
    else {
      if (*(int *)(i * 2 + 0x114) == 0) {
        nbytes = ovr_stshFilesize(*(uint16_t *)(i * 2));
        pvVar7 = ovr_stshAlloc(nbytes + 0xd);
        sz = (undefined2)nbytes;
        ((undefined2 *)(i * 4))[1] = (int)((ulong)pvVar7 >> 0x10);
        *(undefined2 *)(i * 4) = (uint16_t)pvVar7;
        *(undefined1 *)*(undefined4 *)(i << 2) = 3;
        uVar6 = (undefined2)((ulong)*(undefined4 *)(i << 2) >> 0x10);
        iVar5 = (int)*(undefined4 *)(i << 2);
        *(undefined2 *)(iVar5 + 3) = 0;
        *(undefined2 *)(iVar5 + 1) = 0;
        *(undefined2 *)((int)*(undefined4 *)(i << 2) + 5) = sz;
        file_id = ovr_stshOpen(*(uint16_t *)(i * 2));
        buf_00.seg = ((int *)(i * 4))[1];
        buf_00.ofs = *(int *)(i * 4) + 0xd;
        lVar8 = ovr_stshRead(file_id,buf_00,nbytes);
        if (lVar8 != 0) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x20);
        }
        *(undefined2 *)((int)*(undefined4 *)(i << 2) + 0xb) = 0;
      }
      else {
        file_id = ovr_stshOpen(*(uint16_t *)(i * 2));
        fVar10.seg = unaff_SS;
        fVar10.ofs = (uint16_t)&voc;
        lVar8 = ovr_stshRead(file_id,fVar10,0x20);
        if (lVar8 != 0) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x20);
        }
        lVar11 = (ulong)voc.blksz[0] << 0x10;
        lVar8 = LXLSH_at_((ulong)voc.blksz[1],8);
        lVar8 = lVar8 + CONCAT22((int)lVar11,(int)((ulong)lVar11 >> 0x10));
        uVar2 = (uint)lVar8;
        uVar3 = uVar2 - 2;
        uVar4 = ((int)((ulong)lVar8 >> 0x10) + (uint)voc.blksz[2]) - (uint)(uVar2 < 2);
        pvVar7 = ovr_stshAlloc(CONCAT22(uVar4 + (0xfff2 < uVar3),uVar2 + 0xb));
        ((undefined2 *)(i * 4))[1] = (int)((ulong)pvVar7 >> 0x10);
        *(undefined2 *)(i * 4) = (uint16_t)pvVar7;
        *(undefined1 *)*(undefined4 *)(i << 2) = 3;
        uVar6 = (undefined2)((ulong)*(undefined4 *)(i << 2) >> 0x10);
        iVar5 = (int)*(undefined4 *)(i << 2);
        *(undefined2 *)(iVar5 + 3) = 0;
        *(undefined2 *)(iVar5 + 1) = 0;
        *(uint *)((int)*(undefined4 *)(i << 2) + 5) = uVar3;
        if ((uStack_8 <= uVar4) && ((uVar4 != uStack_8 || (uStack_a <= uVar3)))) {
          uStack_a = uVar2 + 0xb;
          uStack_8 = uVar4 + (0xfff2 < uVar3);
        }
        buf.seg = ((int *)(i * 4))[1];
        buf.ofs = *(int *)(i * 4) + 0xd;
        lVar8 = ovr_stshRead(file_id,buf,CONCAT22(uVar4,uVar3));
        if (lVar8 != 0) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x20);
        }
        freq = stshDecVocSampleRate(voc.freq);
        *(uint16_t *)((int)*(undefined4 *)(i << 2) + 0xb) = freq;
      }
      ovr_stshClose(file_id);
      pcVar9 = stshStoreFile((uint8_t *)
                             CONCAT22(((undefined2 *)(i * 4))[1],(uint8_t *)*(undefined2 *)(i * 4)))
      ;
      in_DX = (uint16_t)((ulong)pcVar9 >> 0x10);
      ((undefined2 *)(i * 4))[1] = in_DX;
      *(undefined2 *)(i * 4) = (uint16_t)pcVar9;
    }
    i = i + 1;
  } while( true );
}



/* 4b0a:0eda */

long __cdecl16far stshAlloc2(DW sz)

{
  undefined2 uVar1;
  uint16_t uVar2;
  undefined1 *puVar3;
  bool bVar4;
  far_t fVar5;
  far_t ptr_base;
  undefined1 *puVar6;
  ulong b;
  
  if (StshCount < 0xd93) {
    b = (ulong)StshCount;
    StshCount = StshCount + 1;
    fVar5 = far_from_u32((uint32_t)(LXMUL_at_(0x15,b)));
    ptr_base.seg = StshCtPtr.seg;
    ptr_base.ofs = StshCtPtr.ofs;
    fVar5 = PADD_at_(ptr_base,fVar5);
    puVar6 = (undefined1 *)ovr_mkp(fVar5.ofs,fVar5.seg);
    puVar3 = (undefined1 *)puVar6;
    uVar1 = (undefined2)((ulong)puVar6 >> 0x10);
    *(uint16_t *)(puVar3 + 7) = sz.hi;
    *(uint16_t *)(puVar3 + 5) = sz.lo;
    *puVar6 = 0;
    uVar2 = StshCtOfs.lo;
    *(uint16_t *)(puVar3 + 3) = StshCtOfs.hi;
    *(uint16_t *)(puVar3 + 1) = uVar2;
    *(undefined2 *)(puVar3 + 0x13) = 0;
    *(undefined2 *)(puVar3 + 0x11) = 0;
    bVar4 = CARRY2(StshCtOfs.lo,sz.lo);
    StshCtOfs.lo = StshCtOfs.lo + sz.lo;
    StshCtOfs.hi = StshCtOfs.hi + sz.hi + (uint)bVar4;
    *(undefined2 *)(puVar3 + 0xb) = 0;
    *(undefined2 *)(puVar3 + 9) = 0;
    *(undefined2 *)(puVar3 + 0xf) = 0;
    *(undefined2 *)(puVar3 + 0xd) = 0;
    return (long)puVar6;
  }
                    /* WARNING: Subroutine does not return */
  ovr_stExit(0x24);
}



/* 4b0a:0f95 */

uint32_t __cdecl16far stshWrite(uint8_t *data,long sz)

{
  uint32_t uVar1;
  uint16_t in_stack_00000006;
  far_t buf;
  
  if (sz == 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x58);
  }
  buf.seg = in_stack_00000006;
  buf.ofs = (uint16_t)data;
  stshWriteFile(StshFile,buf,dw_from_u32((uint32_t)sz));
  uVar1 = stshAlloc2(dw_from_u32((uint32_t)sz));
  return uVar1;
}



/* 4b0a:0fd0 */

/* WARNING: Removing unreachable block (ram,0x0004c0da) */
/* WARNING: Removing unreachable block (ram,0x0004c116) */
/* Opens a file and writes it into STRONG.DAT */

far_t __cdecl16far stshStoreFile2(char *filename,uint16_t flag)

{
  int hande;
  uint count;
  DW sz;
  far_t fVar1;
  far_t buf;
  DW sz_00;
  uint len;
  uint16_t uStack_8;
  
  hande = ovr_open_wait_unlock_and_disk(filename);
  if (hande < 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x23);
  }
  sz = dw_from_u32(filelength(hande));
  if ((char)flag != '\0') {
    sz = dw_from_u32((uint32_t)((int32_t)dw_to_u32(sz) + 0xf));
  }
  fVar1 = far_from_u32((uint32_t)(stshAlloc2(sz)));
  if ((int32_t)dw_to_u32(sz) < 0xc000) {
    buf = far_from_u32((uint32_t)(ovr_stshAlloc(dw_to_u32(sz))));
  }
  else {
    buf = far_from_u32((uint32_t)(ovr_stshAlloc(0xc000)));
  }
  while( true ) {
    uStack_8 = sz.hi;
    len = sz.lo;
    if (dw_to_u32(sz) == 0) break;
    count = len;
    if (0xbfff < (int32_t)dw_to_u32(sz)) {
      count = 0xc000;
    }
    _fmemset((void *)MK_FP(buf.seg, buf.ofs),0,count);
    read(hande,(void *)buf.ofs,count);
    sz_00.hi = 0;
    sz_00.lo = count;
    stshWriteFile(StshFile,buf,sz_00);
    sz.hi = uStack_8 - (len < count);
    sz.lo = len - count;
  }
  close(hande);
  ovr_stshFree(buf);
  return fVar1;
}



/* 4b0a:10ea */

void __cdecl16far init_special_graphics(int param_1,undefined2 param_2)

{
  far_t handle;
  
  if (*(int *)(param_1 + 0x11) != 0 || *(int *)(param_1 + 0x13) != 0) {
    handle.seg = *(uint16_t *)(param_1 + 0x13);
    handle.ofs = *(uint16_t *)(param_1 + 0x11);
    ovr_stshFree(handle);
    *(undefined2 *)(param_1 + 0x13) = 0;
    *(undefined2 *)(param_1 + 0x11) = 0;
  }
  return;
}



/* 4b0a:112d */

void __cdecl16far OVC20_4b0a_112d(int param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 0x13) = 0;
  *(undefined2 *)(param_1 + 0x11) = 0;
  return;
}



/* 4b0a:1150 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far init_ui_gfxes(void)

{
  undefined2 uVar1;
  uint uVar2;
  int i;
  far_t fVar3;
  void *pvVar4;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t handle;
  far_t handle_00;
  undefined1 local_30e [768];
  stg_tmp_t *psStack_e;
  stg_tmp_t *psStack_a;
  far_t fStack_6;
  
  handle.seg = Lbm_nwpanel1.seg;
  handle.ofs = Lbm_nwpanel1.ofs;
  psStack_a = ovr_stshLoadGfx(handle);
  uVar1 = ovr_calcSeasonPalette(psStack_a,local_30e);
  init_special_graphics(uVar1,0);
  ovr_vgaSetPalette8bit(local_30e);
  init_special_graphics(Lbm_nwpanel1.ofs,0);
  handle_00.seg = DAT_2000_d1ce;
  handle_00.ofs = DAT_2000_d1cc;
  psStack_e = ovr_stshLoadGfx(handle_00);
  memcpy((uint8_t *)SpecialColors,((stg_tmp_t *)psStack_e)->cmap,8);
  init_special_graphics(DAT_2000_d1cc,0);
  fStack_6 = far_from_u32((uint32_t)(ovr_stshAlloc(0xfa0f)));
  fVar3 = ovr_alignToSeg(fStack_6);
  uVar2 = fVar3.seg;
  ovr_driver_2d63_05e5(0,0,0x13f,199,0);
  fVar3.seg = DAT_2000_d1ca;
  fVar3.ofs = DAT_2000_d1c8;
  ovr_blitLoadRleGfx(fVar3,far_from_u32((uint32_t)((ulong)uVar2 << 0x10)));
  init_special_graphics(DAT_2000_d1c8,0);
  Font03 = ovr_stshProcessFontSub(far_from_u32((uint32_t)((ulong)uVar2 << 0x10)));
  ovr_driver_2d63_05e5(0,0,0x13f,199,0);
  gfx.seg = DAT_2000_d1c6;
  gfx.ofs = DAT_2000_d1c4;
  ovr_blitLoadRleGfx(gfx,far_from_u32((uint32_t)((ulong)uVar2 << 0x10)));
  init_special_graphics(DAT_2000_d1c4,0);
  Font02 = ovr_stshProcessFontSub(far_from_u32((uint32_t)((ulong)uVar2 << 0x10)));
  ovr_driver_2d63_05e5(0,0,0x13f,199,0);
  gfx_00.seg = DAT_2000_d1c2;
  gfx_00.ofs = DAT_2000_d1c0;
  ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)((ulong)uVar2 << 0x10)));
  init_special_graphics(DAT_2000_d1c0,0);
  Font01 = ovr_stshProcessFontSub(far_from_u32((uint32_t)((ulong)uVar2 << 0x10)));
  FontMain = Font01;
  for (i = 0; i < 4; i = i + 1) {
    ovr_driver_2d63_05e5(0,0,0x11,0x11,0);
    gfx_01.seg = *(uint16_t *)((int)&MiceCursors[0].seg + i * 4);
    gfx_01.ofs = ((far_t *)MiceCursors + i)->ofs;
    ovr_blitLoadRleGfx(gfx_01,far_from_u32((uint32_t)((ulong)uVar2 << 0x10)));
    init_special_graphics(((far_t *)MiceCursors + i)->ofs,0);
    video_13aa_0266(0,0,0);
    pvVar4 = ovr_stshAlloc(0x121);
    *(undefined2 *)((int)&MicePtrs.seg + i * 4) = (int)((ulong)pvVar4 >> 0x10);
    ((far_t *)&MicePtrs + i)->ofs = (uint16_t)(void *)pvVar4;
    memcpy((uint8_t *)((far_t *)&MicePtrs + i)->ofs,(uint8_t *)0x0,0x121);
  }
  ovr_stshFree(fStack_6);
  return;
}



/* 4b0a:13d3 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far stshLoadAudioDrivers(bool grab)

{
  far_t fVar1;
  
  if (grab) {
    far_t_2000_d098 = stshStoreFile2((char *)"midpak.ad",0);
    fVar1 = stshStoreFile2((char *)"cmidpak.com",1);
    DAT_2000_d096 = fVar1.seg;
    DAT_2000_d094 = fVar1.ofs;
    fVar1 = stshStoreFile2((char *)"ibmsnd.com",1);
    DAT_2000_d0ca = fVar1.seg;
    DAT_2000_d0c8 = fVar1.ofs;
    fVar1 = stshStoreFile2((char *)"sblaster.com",1);
    DAT_2000_d0ce = fVar1.seg;
    DAT_2000_d0cc = fVar1.ofs;
    DAT_2000_d0d2 = 0;
    DAT_2000_d0d0 = 0;
    fVar1 = stshStoreFile2((char *)"fibmbak.com",1);
    DAT_2000_d0d6 = fVar1.seg;
    DAT_2000_d0d4 = fVar1.ofs;
    fVar1 = stshStoreFile2((char *)"sbpro.com",1);
    DAT_2000_d0da = fVar1.seg;
    DAT_2000_d0d8 = fVar1.ofs;
    DAT_2000_d0dc = DAT_2000_d0d8;
    DAT_2000_d0de = DAT_2000_d0da;
    fVar1 = stshStoreFile2((char *)"paudio.com",1);
    DAT_2000_d0e2 = fVar1.seg;
    DAT_2000_d0e0 = fVar1.ofs;
    DAT_2000_d0e6 = DAT_2000_d0ce;
    DAT_2000_d0e4 = DAT_2000_d0cc;
    fVar1 = stshStoreFile2((char *)"adlib.com",1);
    DAT_2000_d0ea = fVar1.seg;
    DAT_2000_d0e8 = fVar1.ofs;
    fVar1 = stshStoreFile2((char *)"adlibg.com",1);
    DAT_2000_d0ee = fVar1.seg;
    DAT_2000_d0ec = fVar1.ofs;
    DAT_2000_d0f2 = 0;
    DAT_2000_d0f0 = 0;
    DAT_2000_d09e = 0;
    DAT_2000_d09c = 0;
    fVar1 = stshStoreFile2((char *)"sbfm.adv",1);
    DAT_2000_d0a2 = fVar1.seg;
    DAT_2000_d0a0 = fVar1.ofs;
    DAT_2000_d0a6 = 0;
    DAT_2000_d0a4 = 0;
    DAT_2000_d0aa = 0;
    DAT_2000_d0a8 = 0;
    fVar1 = stshStoreFile2((char *)"sbp2fm.adv",1);
    DAT_2000_d0ae = fVar1.seg;
    DAT_2000_d0ac = fVar1.ofs;
    fVar1 = stshStoreFile2((char *)"sbp1fm.adv",1);
    DAT_2000_d0b2 = fVar1.seg;
    DAT_2000_d0b0 = fVar1.ofs;
    fVar1 = stshStoreFile2((char *)"pasfm.adv",1);
    DAT_2000_d0b6 = fVar1.seg;
    DAT_2000_d0b4 = fVar1.ofs;
    fVar1 = stshStoreFile2((char *)"pasopl.adv",1);
    DAT_2000_d0ba = fVar1.seg;
    DAT_2000_d0b8 = fVar1.ofs;
    fVar1 = stshStoreFile2((char *)"adlib.adv",1);
    DAT_2000_d0be = fVar1.seg;
    DAT_2000_d0bc = fVar1.ofs;
    fVar1 = stshStoreFile2((char *)"adlibg.adv",1);
    DAT_2000_d0c2 = fVar1.seg;
    DAT_2000_d0c0 = fVar1.ofs;
    fVar1 = stshStoreFile2((char *)"mt32mpu.adv",1);
  }
  else {
    far_t_2000_d098 = ovr_stshAllocStub();
    fVar1 = ovr_stshAllocStub();
    DAT_2000_d096 = fVar1.seg;
    DAT_2000_d094 = fVar1.ofs;
    fVar1 = ovr_stshAllocStub();
    DAT_2000_d0ca = fVar1.seg;
    DAT_2000_d0c8 = fVar1.ofs;
    fVar1 = ovr_stshAllocStub();
    DAT_2000_d0ce = fVar1.seg;
    DAT_2000_d0cc = fVar1.ofs;
    DAT_2000_d0d2 = 0;
    DAT_2000_d0d0 = 0;
    fVar1 = ovr_stshAllocStub();
    DAT_2000_d0d6 = fVar1.seg;
    DAT_2000_d0d4 = fVar1.ofs;
    fVar1 = ovr_stshAllocStub();
    DAT_2000_d0da = fVar1.seg;
    DAT_2000_d0d8 = fVar1.ofs;
    DAT_2000_d0dc = DAT_2000_d0d8;
    DAT_2000_d0de = DAT_2000_d0da;
    fVar1 = ovr_stshAllocStub();
    DAT_2000_d0e2 = fVar1.seg;
    DAT_2000_d0e0 = fVar1.ofs;
    DAT_2000_d0e6 = DAT_2000_d0ce;
    DAT_2000_d0e4 = DAT_2000_d0cc;
    fVar1 = ovr_stshAllocStub();
    DAT_2000_d0ea = fVar1.seg;
    DAT_2000_d0e8 = fVar1.ofs;
    fVar1 = ovr_stshAllocStub();
    DAT_2000_d0ee = fVar1.seg;
    DAT_2000_d0ec = fVar1.ofs;
    DAT_2000_d0f2 = 0;
    DAT_2000_d0f0 = 0;
    DAT_2000_d09e = 0;
    DAT_2000_d09c = 0;
    fVar1 = ovr_stshAllocStub();
    DAT_2000_d0a2 = fVar1.seg;
    DAT_2000_d0a0 = fVar1.ofs;
    DAT_2000_d0a6 = 0;
    DAT_2000_d0a4 = 0;
    DAT_2000_d0aa = 0;
    DAT_2000_d0a8 = 0;
    fVar1 = ovr_stshAllocStub();
    DAT_2000_d0ae = fVar1.seg;
    DAT_2000_d0ac = fVar1.ofs;
    fVar1 = ovr_stshAllocStub();
    DAT_2000_d0b2 = fVar1.seg;
    DAT_2000_d0b0 = fVar1.ofs;
    fVar1 = ovr_stshAllocStub();
    DAT_2000_d0b6 = fVar1.seg;
    DAT_2000_d0b4 = fVar1.ofs;
    fVar1 = ovr_stshAllocStub();
    DAT_2000_d0ba = fVar1.seg;
    DAT_2000_d0b8 = fVar1.ofs;
    fVar1 = ovr_stshAllocStub();
    DAT_2000_d0be = fVar1.seg;
    DAT_2000_d0bc = fVar1.ofs;
    fVar1 = ovr_stshAllocStub();
    DAT_2000_d0c2 = fVar1.seg;
    DAT_2000_d0c0 = fVar1.ofs;
    fVar1 = ovr_stshAllocStub();
  }
  DAT_2000_d0c6 = fVar1.seg;
  DAT_2000_d0c4 = fVar1.ofs;
  return;
}



/* 4b0a:1820 */

void __cdecl16far grabBldLbm(int16_t file_normal,int16_t file_ruin,uint16_t index)

{
  stg_tmp_t *pg;
  stg_tmp_t *psVar1;
  cte_t *pcVar2;
  uint8_t *p;
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
  undefined2 uStack_4;
  
  psVar1 = grabLbmTR(file_normal);
  pg = (stg_tmp_t *)psVar1;
  uStack_4 = (undefined2)((ulong)psVar1 >> 0x10);
  pixels.seg = (pg->aptr).seg;
  pixels.ofs = (&pg->aptr)->ofs;
  p = (uint8_t *)ovr_stshRleType2(pixels,0,130,99,194,26,-1);
  pcVar2 = stshStoreFile(p);
  *(undefined2 *)((int)&BldGfxNormal[0].seg + index * 0xc) = (int)((ulong)pcVar2 >> 0x10);
  ((far_t *)BldGfxNormal + index * 3)->ofs = (uint16_t)(cte_t *)pcVar2;
  pixels_00.seg = (pg->aptr).seg;
  pixels_00.ofs = (&pg->aptr)->ofs;
  p = (uint8_t *)ovr_stshRleType2(pixels_00,100,130,199,194,26,-1);
  pcVar2 = stshStoreFile(p);
  *(undefined2 *)((int)&BldGfxNormal[1].seg + index * 0xc) = (int)((ulong)pcVar2 >> 0x10);
  ((far_t *)(BldGfxNormal + 1) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar2;
  pixels_01.seg = (pg->aptr).seg;
  pixels_01.ofs = (&pg->aptr)->ofs;
  p = (uint8_t *)ovr_stshRleType2(pixels_01,200,130,299,194,26,-1);
  pcVar2 = stshStoreFile(p);
  *(undefined2 *)((int)&BldGfxNormal[2].seg + index * 0xc) = (int)((ulong)pcVar2 >> 0x10);
  ((far_t *)(BldGfxNormal + 2) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar2;
  pixels_02.seg = (pg->aptr).seg;
  pixels_02.ofs = (&pg->aptr)->ofs;
  p = (uint8_t *)ovr_stshRleType2(pixels_02,0,65,99,129,26,-1);
  pcVar2 = stshStoreFile(p);
  *(undefined2 *)((int)&BldGfxNormal[3].seg + index * 0xc) = (int)((ulong)pcVar2 >> 0x10);
  ((far_t *)(BldGfxNormal + 3) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar2;
  pixels_03.seg = (pg->aptr).seg;
  pixels_03.ofs = (&pg->aptr)->ofs;
  p = (uint8_t *)ovr_stshRleType2(pixels_03,100,65,199,129,26,-1);
  pcVar2 = stshStoreFile(p);
  *(undefined2 *)((int)&BldGfxNormal[4].seg + index * 0xc) = (int)((ulong)pcVar2 >> 0x10);
  ((far_t *)(BldGfxNormal + 4) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar2;
  pixels_04.seg = (pg->aptr).seg;
  pixels_04.ofs = (&pg->aptr)->ofs;
  p = (uint8_t *)ovr_stshRleType2(pixels_04,200,65,299,129,26,-1);
  pcVar2 = stshStoreFile(p);
  *(undefined2 *)((int)&BldGfxNormal[5].seg + index * 0xc) = (int)((ulong)pcVar2 >> 0x10);
  ((far_t *)(BldGfxNormal + 5) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar2;
  pixels_05.seg = (pg->aptr).seg;
  pixels_05.ofs = (&pg->aptr)->ofs;
  p = (uint8_t *)ovr_stshRleType2(pixels_05,0,0,99,64,26,-1);
  pcVar2 = stshStoreFile(p);
  *(undefined2 *)((int)&BldGfxNormal[6].seg + index * 0xc) = (int)((ulong)pcVar2 >> 0x10);
  ((far_t *)(BldGfxNormal + 6) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar2;
  pixels_06.seg = (pg->aptr).seg;
  pixels_06.ofs = (&pg->aptr)->ofs;
  p = (uint8_t *)ovr_stshRleType2(pixels_06,100,0,199,64,26,-1);
  pcVar2 = stshStoreFile(p);
  *(undefined2 *)((int)&BldGfxNormal[7].seg + index * 0xc) = (int)((ulong)pcVar2 >> 0x10);
  ((far_t *)(BldGfxNormal + 7) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar2;
  pixels_07.seg = (pg->aptr).seg;
  pixels_07.ofs = (&pg->aptr)->ofs;
  p = (uint8_t *)ovr_stshRleType2(pixels_07,200,0,299,64,26,-1);
  pcVar2 = stshStoreFile(p);
  *(undefined2 *)((int)&BldGfxNormal[8].seg + index * 0xc) = (int)((ulong)pcVar2 >> 0x10);
  ((far_t *)(BldGfxNormal + 8) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar2;
  stgFreeTmp(psVar1);
  if (file_ruin != 0) {
    psVar1 = grabLbmTR(file_ruin);
    pg = (stg_tmp_t *)psVar1;
    uStack_4 = (undefined2)((ulong)psVar1 >> 0x10);
    pixels_08.seg = (pg->aptr).seg;
    pixels_08.ofs = (&pg->aptr)->ofs;
    p = (uint8_t *)ovr_stshRleType2(pixels_08,0,130,99,194,26,-1);
    pcVar2 = stshStoreFile(p);
    *(undefined2 *)((int)&BldGfxRuin[0].seg + index * 0xc) = (int)((ulong)pcVar2 >> 0x10);
    ((far_t *)BldGfxRuin + index * 3)->ofs = (uint16_t)(cte_t *)pcVar2;
    pixels_09.seg = (pg->aptr).seg;
    pixels_09.ofs = (&pg->aptr)->ofs;
    p = (uint8_t *)ovr_stshRleType2(pixels_09,100,130,199,194,26,-1);
    pcVar2 = stshStoreFile(p);
    *(undefined2 *)((int)&BldGfxRuin[1].seg + index * 0xc) = (int)((ulong)pcVar2 >> 0x10);
    ((far_t *)(BldGfxRuin + 1) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar2;
    pixels_10.seg = (pg->aptr).seg;
    pixels_10.ofs = (&pg->aptr)->ofs;
    p = (uint8_t *)ovr_stshRleType2(pixels_10,200,130,299,194,26,-1);
    pcVar2 = stshStoreFile(p);
    *(undefined2 *)((int)&BldGfxRuin[2].seg + index * 0xc) = (int)((ulong)pcVar2 >> 0x10);
    ((far_t *)(BldGfxRuin + 2) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar2;
    pixels_11.seg = (pg->aptr).seg;
    pixels_11.ofs = (&pg->aptr)->ofs;
    p = (uint8_t *)ovr_stshRleType2(pixels_11,0,65,99,129,26,-1);
    pcVar2 = stshStoreFile(p);
    *(undefined2 *)((int)&BldGfxRuin[3].seg + index * 0xc) = (int)((ulong)pcVar2 >> 0x10);
    ((far_t *)(BldGfxRuin + 3) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar2;
    pixels_12.seg = (pg->aptr).seg;
    pixels_12.ofs = (&pg->aptr)->ofs;
    p = (uint8_t *)ovr_stshRleType2(pixels_12,100,65,199,129,26,-1);
    pcVar2 = stshStoreFile(p);
    *(undefined2 *)((int)&BldGfxRuin[4].seg + index * 0xc) = (int)((ulong)pcVar2 >> 0x10);
    ((far_t *)(BldGfxRuin + 4) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar2;
    pixels_13.seg = (pg->aptr).seg;
    pixels_13.ofs = (&pg->aptr)->ofs;
    p = (uint8_t *)ovr_stshRleType2(pixels_13,200,65,299,129,26,-1);
    pcVar2 = stshStoreFile(p);
    *(undefined2 *)((int)&BldGfxRuin[5].seg + index * 0xc) = (int)((ulong)pcVar2 >> 0x10);
    ((far_t *)(BldGfxRuin + 5) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar2;
    pixels_14.seg = (pg->aptr).seg;
    pixels_14.ofs = (&pg->aptr)->ofs;
    p = (uint8_t *)ovr_stshRleType2(pixels_14,0,0,99,64,26,-1);
    pcVar2 = stshStoreFile(p);
    *(undefined2 *)((int)&BldGfxRuin[6].seg + index * 0xc) = (int)((ulong)pcVar2 >> 0x10);
    ((far_t *)(BldGfxRuin + 6) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar2;
    pixels_15.seg = (pg->aptr).seg;
    pixels_15.ofs = (&pg->aptr)->ofs;
    p = (uint8_t *)ovr_stshRleType2(pixels_15,100,0,199,64,26,-1);
    pcVar2 = stshStoreFile(p);
    *(undefined2 *)((int)&BldGfxRuin[7].seg + index * 0xc) = (int)((ulong)pcVar2 >> 0x10);
    ((far_t *)(BldGfxRuin + 7) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar2;
    pixels_16.seg = (pg->aptr).seg;
    pixels_16.ofs = (&pg->aptr)->ofs;
    p = (uint8_t *)ovr_stshRleType2(pixels_16,200,0,299,64,26,-1);
    pcVar2 = stshStoreFile(p);
    *(undefined2 *)((int)&BldGfxRuin[8].seg + index * 0xc) = (int)((ulong)pcVar2 >> 0x10);
    ((far_t *)(BldGfxRuin + 8) + index * 3)->ofs = (uint16_t)(cte_t *)pcVar2;
    stgFreeTmp(psVar1);
  }
  return;
}


