/*
 * ovc01_driver.c - recovered from STRONG.EXE
 * memory block: OVC01_driver.c
 * range: 2d63:0000 - 2d63:0c1f
 * functions: 60
 */
#include "recovered.h"


/* 2d63:0000 */

/* packs seg+ofs into a uint32_t */

uint32_t * __cdecl16far mkp(uint32_t *__return_storage_ptr__,uint16_t ofs,uint16_t seg,...)

{
  return (uint32_t *)((uint)__return_storage_ptr__ & 0xf);
}



/* 2d63:0016 */

uint16_t __cdecl16far biosVideoCall(uint8_t operation,uint8_t argument)

{
  code *pcVar1;
  uint16_t unaff_ES;
  
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)();
  return unaff_ES;
}



/* 2d63:0030 */

uint16_t __cdecl16far biosReadKey(void)

{
  code *pcVar1;
  uint16_t uVar2;
  
  pcVar1 = (code *)swi(0x16);
  uVar2 = (*pcVar1)();
  return uVar2;
}



/* 2d63:0039 */

uint16_t __cdecl16far biosKeyAvail(void)

{
  code *pcVar1;
  undefined1 in_ZF;
  
  pcVar1 = (code *)swi(0x16);
  (*pcVar1)();
  return (uint)!(bool)in_ZF;
}



/* 2d63:004a */

uint16_t __cdecl16far miceButtonsStates(void)

{
  code *pcVar1;
  uint in_BX;
  
  pcVar1 = (code *)swi(0x33);
  (*pcVar1)();
  return in_BX & 7;
}



/* 2d63:005d */

void __cdecl16far
blitRaw(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t srcSeg,uint16_t dstSeg)

{
  undefined1 *puVar1;
  uint uVar2;
  uint16_t dy;
  uint16_t uVar3;
  uint16_t dx;
  uint16_t s;
  uint16_t d;
  uint32_t ps;
  
  uVar2 = CONCAT11((char)y1,(char)(y1 >> 8));
  s = uVar2 + (uVar2 >> 2) + x1;
  dy = (y2 - y1) + 1;
  dx = (x2 - x1) + 1;
  uVar3 = dx;
  d = s;
  do {
    for (; uVar3 != 0; uVar3 = uVar3 - 1) {
      puVar1 = (undefined1 *)s;
      s = s + 1;
      *(undefined1 *)d = *puVar1;
      d = (uint16_t)(d + 1);
    }
    s = s + (0x140 - dx);
    d = d + (0x140 - dx);
    dy = dy - 1;
    uVar3 = dx;
  } while (dy != 0);
  return;
}



/* 2d63:00aa */

void __cdecl16far
lbm_combine_bitplanes(far_t src,far_t dst,uint16_t npixels,uint8_t nplanes,uint16_t plane_sz,uint16_t arg6)

{
  byte *pbVar1;
  uint8_t pixel;
  uint8_t bits;
  uint8_t mask;
  uint16_t s;
  uint16_t ps;
  uint16_t d;
  uint8_t bit0;
  uint32_t pd;
  
  s = src.ofs;
  d = dst.ofs;
  mask = 0x80;
  do {
    pixel = 0x0;
    bits = 0x1;
    ps = s;
    do {
      if ((*(byte *)ps & mask) != 0) {
        pixel = pixel | bits;
      }
      bits = bits << 1 | (char)bits < '\0';
      ps = ps + plane_sz;
    } while (bits != (byte)('\x01' << (nplanes & 7) | 1U >> 8 - (nplanes & 7)));
    pbVar1 = (byte *)d;
    d = d + 1;
    *pbVar1 = pixel;
    bit0 = mask & 1;
    mask = mask >> 1 | mask << 7;
    if ((bool)bit0) {
      s = s + 1;
    }
    npixels = npixels - 1;
  } while (npixels != 0);
  return;
}



/* 2d63:00eb */

/* Loads big-endian 32bit integer into DX_AX pair
   NOTE: the function has a bug (high order bytes are swapped) */

uint32_t * __cdecl16far be4(uint32_t *__return_storage_ptr__,uint32_t be)

{
  return (uint32_t *)CONCAT11((undefined1)be,(*(uint8_t *)((uint8_t *)&(be) + 1)));
}



/* 2d63:00fc */

/* Flips bytes in a 16bt word */

uint16_t __cdecl16far be2(uint16_t w)

{
  return CONCAT11((undefined1)w,(*(uint8_t *)((uint8_t *)&(w) + 1)));
}



/* 2d63:0107 */

/* [R7] body shape: compute */

char __cdecl16far driver_compute1(char cornerA,byte cornerB,char cornerC)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = (byte)(CONCAT11(CARRY1(cornerC + cornerA,cornerB),cornerC + cornerA + cornerB) >> 7);
  if (2 < bVar1) {
    bVar1 = 2;
  }
  bVar2 = ((char)(cornerB - cornerA) >> 2) + 2;
  if ((char)bVar2 < '\0') {
    bVar2 = 0;
  }
  else if (4 < bVar2) {
    bVar2 = 4;
  }
  return (bVar1 * '\x05' + -0xc) - bVar2;
}



/* 2d63:014b */

/* [R7] body shape: compute */

char __cdecl16far driver_compute2(char cornerA,byte cornerB,char cornerC)

{
  byte bVar1;
  
  bVar1 = (byte)(CONCAT11(CARRY1(cornerC + cornerA,cornerB),cornerC + cornerA + cornerB) >> 7);
  if (2 < bVar1) {
    bVar1 = 2;
  }
  return bVar1 * '\x05' + -0xe;
}



/* 2d63:017a */

void __cdecl16far miceDisableHandler(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x33);
  (*pcVar1)();
  return;
}



/* 2d63:0190 */

uint16_t __cdecl16far miceButton0PressStates(void)

{
  code *pcVar1;
  uint uVar2;
  
  pcVar1 = (code *)swi(0x33);
  uVar2 = (*pcVar1)(0x2410);
  return uVar2 & 7;
}



/* 2d63:01a7 */

void __cdecl16far miceSetPosition(uint16_t col,uint16_t row)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x33);
  (*pcVar1)(0x2410);
  return;
}



/* 2d63:01bf */

uint8_t __cdecl16far vgaSetPalette(uint8_t *paletteOfs,uint8_t paletteSeg,int startIndex,uint16_t arg4)

{
  uint8_t *puVar1;
  uint16_t uVar2;
  undefined1 uStack0007;
  int in_stack_0000000a;
  
  paletteOfs = CONCAT13(uStack0007,CONCAT12(paletteSeg,paletteOfs));
  out(0x3c8,(undefined1)startIndex);
  uVar2 = (uint16_t)((ulong)paletteOfs >> 0x10);
  do {
    out(0x3c9,*paletteOfs);
    puVar1 = paletteOfs + 2;
    out(0x3c9,paletteOfs[1]);
    paletteOfs = paletteOfs + 3;
    out(0x3c9,*puVar1);
    in_stack_0000000a = in_stack_0000000a + -1;
  } while (in_stack_0000000a != 0);
  return *puVar1;
}



/* 2d63:01df */

uint8_t __cdecl16far vgaSetPalette8bit(uint8_t *pal,uint16_t arg2)

{
  uint8_t *puVar1;
  int iVar2;
  uint16_t in_stack_00000006;
  
  out(0x3c8,0);
  iVar2 = 0x100;
  do {
    out(0x3c9,*pal);
    puVar1 = pal + 2;
    out(0x3c9,pal[1]);
    pal = pal + 3;
    out(0x3c9,*puVar1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return *puVar1;
}



/* 2d63:0203 */

/* Again PCX formal RLE
   void process_data_rle(uint8_t *src, uint16_t src_seg, uint8_t *dest, uint16_t dest_seg, uint16_t
   length) {
       uint8_t *SI = src;
       uint8_t *DI = dest;
       uint8_t *end = src + length;
       uint8_t *BX = SI;
       uint8_t AL;
   
       while (SI < end) {
           uint8_t *BP = SI;
           uint16_t run_length = end - SI;
           if (run_length > 128) run_length = 128;
   
           uint8_t *run_end = SI + run_length;
           AL = *SI++;
           while (SI < run_end && *SI == AL) SI++;
   
           uint16_t run_size = SI - BP;
           if (run_size >= 3) {
               *DI++ = 0xFF - (run_size - 2); // Store run-length
               *DI++ = AL;                   // Store the byte
           } else {
               while (BP < SI) {
                   *DI++ = *BP++;
               }
           }
   
           if (SI >= end) break;
   
           BX = SI;
       }
       
       // Adjust DI pointer based on the destination offset and original DI
       uint16_t adjusted_length = DI - dest;
   } */

int __cdecl16far unrle(far_t src,far_t dst,uint16_t len,uint16_t arg4,uint16_t arg5)

{
  undefined1 *puVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  uint uVar6;
  uint16_t i;
  uint16_t end;
  uint16_t pps;
  uint16_t s;
  uint16_t d;
  uint16_t uVar7;
  uint32_t ps;
  uint8_t val;
  uint32_t pd;
  uint8_t run_val;
  
  uVar7 = src.seg;
  d = dst.ofs;
  end = len + d;
  puVar5 = (undefined1 *)src.ofs;
  do {
    do {
      pps = (uint16_t)puVar5;
      s = pps + 1;
      bVar2 = *(byte *)pps;
      puVar5 = (undefined1 *)s;
    } while (bVar2 == 0x80);
    if (bVar2 < 0x80) {
      for (uVar6 = (uint)(byte)(bVar2 + 1); uVar6 != 0; uVar6 = uVar6 - 1) {
        puVar4 = (undefined1 *)d;
        d = d + 1;
        puVar1 = (undefined1 *)s;
        s = s + 1;
        *puVar4 = *puVar1;
      }
    }
    else {
      (*(uint8_t *)((uint8_t *)&(i))) = (bVar2 ^ 0xff) + 2;
      puVar1 = (undefined1 *)s;
      s = pps + 2;
      uVar3 = *puVar1;
      for (i = (uint16_t)(byte)i; i != 0; i = i - 1) {
        puVar1 = (undefined1 *)d;
        d = d + 1;
        *puVar1 = uVar3;
      }
    }
    puVar5 = (undefined1 *)s;
  } while (d < end);
  return s - src.ofs;
}



/* 2d63:0241 */
int __cdecl16far rle_blit_decode(byte *src,byte *dst,uint16_t sz)

{
  char *pcVar1;
  byte bVar2;
  char cVar3;
  byte *pbVar4;
  uint uVar5;
  uint16_t i;
  uint16_t end;
  uint16_t ps;
  uint16_t s;
  uint16_t d;
  int in_stack_0000000c;
  uint32_t q;
  
  end = in_stack_0000000c + (int)(*(uint16_t *)((uint8_t *)&(dst) + 2));
  pbVar4 = src;
  do {
    do {
      ps = (uint16_t)pbVar4;
      s = ps + 1;
      bVar2 = *(byte *)ps;
      pbVar4 = (byte *)(char *)s;
    } while (bVar2 == 0x80);
    if (bVar2 < 0x80) {
      uVar5 = (uint)(byte)(bVar2 + 1);
      do {
        pcVar1 = (char *)s;
        s = s + 1;
        if (*pcVar1 != '\0') {
          *(byte *)(*(uint16_t *)((uint8_t *)&(dst) + 2))   /* hand fix: the segment half is used as an address; make the indirection legal */ = *pcVar1;
        }
        (*(uint16_t *)((uint8_t *)&(dst) + 2)) = (*(uint16_t *)((uint8_t *)&(dst) + 2)) + 1;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    else {
      i = (uint16_t)(byte)((bVar2 ^ 0xff) + 2);
      pcVar1 = (char *)s;
      s = ps + 2;
      cVar3 = *pcVar1;
      if (cVar3 == '\0') {
        (*(uint16_t *)((uint8_t *)&(dst) + 2)) = (*(uint16_t *)((uint8_t *)&(dst) + 2)) + i;
      }
      else {
        for (; i != 0; i = i - 1) {
          pcVar1 = (*(uint16_t *)((uint8_t *)&(dst) + 2));
          (*(uint16_t *)((uint8_t *)&(dst) + 2)) = (*(uint16_t *)((uint8_t *)&(dst) + 2)) + 1;
          *pcVar1 = cVar3;
        }
      }
    }
    pbVar4 = (byte *)s;
  } while ((*(uint16_t *)((uint8_t *)&(dst) + 2)) < end);
  return s - (int)src;
}


/* 2d63:0292 */

void __cdecl16far grabRemap(far_t pixels,uint8_t scolor,uint8_t dcolor,uint16_t arg4)

{
  uint16_t count;
  uint8_t *p;
  
  p = (uint8_t *)pixels.ofs;
  count = 64000;
  do {
    if (*p == scolor) {
      *p = dcolor;
    }
    p = p + 1;
    count = count - 1;
  } while (count != 0);
  return;
}



/* 2d63:02b5 */
void __cdecl16far masked_memcpy(char *dst,char *src,int skip,int src_sz,int dst_sz,uint mask,uint16_t arg7)

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


/* 2d63:02fe */

/* counts the run of bytes equal to the first, bounded by the limit argument */

int16_t __cdecl16far countRunLength(char *src,uint16_t avail,uint16_t maxRun)

{
  char *pcVar1;
  char *pcVar2;
  
  if (maxRun < avail) {
    avail = maxRun;
  }
  pcVar1 = (char *)src;
  pcVar2 = pcVar1;
  do {
    pcVar2 = pcVar2 + 1;
    if (pcVar1 + avail <= pcVar2) break;
  } while (*src == *pcVar2);
  return (int)pcVar2 - (int)pcVar1;
}



/* 2d63:032d */

/* WARNING: Restarted to delay deadcode elimination for space: stack */

int __cdecl16far rle_line(uint8_t *src,uint8_t *dst,uint16_t npixels)

{
  uint8_t *puVar1;
  uint8_t *puVar2;
  uint uVar3;
  int iVar4;
  uint16_t end;
  uint16_t pps;
  uint16_t c;
  uint16_t ps;
  uint16_t pd;
  int in_stack_0000000c;
  
  end = in_stack_0000000c + (int)src;
  ps = (uint16_t)src;
  pd = (uint16_t)(*(uint16_t *)((uint8_t *)&(dst) + 2));
L_rle_line_0343:
  do {
    uVar3 = end - ps;
    if (0x7f < uVar3) {
      uVar3 = 0x80;
    }
    pps = ps;
    do {
      pps = pps + 1;
      if ((uint8_t *)(ps + uVar3) <= pps) break;
    } while (*(uint8_t *)ps == *(uint8_t *)pps);
    c = pps - ps;
    if (c < 3) {
      ps = ps + 1;
      iVar4 = ps - (int)src;
      if (((byte)iVar4 < 0x80) && (ps < end)) goto L_rle_line_0343;
      *(byte *)pd = (byte)iVar4 - 1;
      for (; pd = pd + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
        puVar1 = src;
        src = src + 1;
        *(uint8_t *)pd = *puVar1;
      }
    }
    else {
      if (src != (uint8_t *)ps) {
        iVar4 = ps - (int)src;
        *(uint8_t *)pd = (char)iVar4 + 0xff;
        for (; pd = pd + 1, ps = (uint16_t)src, iVar4 != 0; iVar4 = iVar4 + -1) {
          puVar1 = src;
          src = src + 1;
          *(uint8_t *)pd = *puVar1;
        }
      }
      puVar2 = (uint8_t *)(pd + 1);
      *(char *)pd = '\x01' - (char)c;
      pd = pd + 2;
      *puVar2 = *(uint8_t *)ps;
      src = (uint8_t *)(ps + c);
    }
    ps = (uint16_t)src;
    if (end <= src) {
      return pd - (int)(*(uint16_t *)((uint8_t *)&(dst) + 2));
    }
  } while( true );
}



/* 2d63:03b6 */

/* //apparently PCX compression
   void process_data(uint8_t *src, uint16_t src_seg, uint16_t *dest, uint16_t dest_seg, uint16_t
   dest_offset) {
       uint8_t *SI = src;
       uint8_t *DI = dest + dest_offset;
       DI--;  // Adjust initial DI
       bool done = false;
       
       while (!done) {
           uint8_t AL = *SI++;  // Load byte from source
           if (AL == 0x80) {
               continue;  // Restart loop if AL is 0x80
           }
           
           if (AL >= 0x80) {
               uint8_t count = 256 - AL + 2;
               AL = *SI++;
               for (int i = 0; i < count; i++) {
                   *DI-- = AL;  // Store byte to destination with repeat
               }
           } else {
               uint8_t count = AL + 1;
               for (int i = 0; i < count; i++) {
                   *DI-- = *SI++;  // Store byte to destination
               }
           }
           
           if (DI <= dest) {
               done = true;  // Exit loop if DI is at or before start of destination
           }
       }
   } */

int __cdecl16far unrle_mirror(byte *src,byte *dst,int len)

{
  undefined1 *puVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  uint16_t cnt;
  uint uVar6;
  uint16_t ppsrc;
  uint16_t psrc;
  uint16_t pdst;
  int in_stack_0000000c;
  uint32_t pd;
  uint32_t ps;
  uint8_t b;
  
  pdst = (int)(*(uint16_t *)((uint8_t *)&(dst) + 2)) + in_stack_0000000c + -1;
  pbVar5 = src;
  do {
    do {
      ppsrc = (uint16_t)pbVar5;
      psrc = ppsrc + 1;
      bVar2 = *(byte *)ppsrc;
      pbVar5 = (undefined1 *)psrc;
    } while (bVar2 == 0x80);
    if (bVar2 < 0x80) {
      cnt = (uint16_t)(byte)(bVar2 + 1);
      do {
        puVar1 = (undefined1 *)psrc;
        psrc = psrc + 1;
        puVar4 = (undefined1 *)pdst;
        pdst = pdst + -1;
        *puVar4 = *puVar1;
        cnt = cnt - 1;
      } while (cnt != 0);
    }
    else {
      puVar1 = (undefined1 *)psrc;
      psrc = ppsrc + 2;
      uVar3 = *puVar1;
      for (uVar6 = (uint)(byte)((bVar2 ^ 0xff) + 2); uVar6 != 0; uVar6 = uVar6 - 1) {
        puVar1 = (undefined1 *)pdst;
        pdst = pdst + -1;
        *puVar1 = uVar3;
      }
    }
    pbVar5 = (byte *)psrc;
  } while ((*(uint16_t *)((uint8_t *)&(dst) + 2)) <= pdst);
  return psrc - (int)src;
}



/* 2d63:03fc */

int16_t __cdecl16far drawLine2(char *src,char *dst,uint16_t count)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  int in_stack_0000000c;
  
  pbVar6 = (*(uint16_t *)((uint8_t *)&(dst) + 2)) + in_stack_0000000c + -1;
  pbVar5 = (byte *)src;
  do {
    do {
      pbVar4 = pbVar5;
      pbVar5 = pbVar4 + 1;
      bVar2 = *pbVar4;
    } while (bVar2 == 0x80);
    if (bVar2 < 0x80) {
      uVar3 = (uint)(byte)(bVar2 + 1);
      do {
        pbVar1 = pbVar5;
        pbVar5 = pbVar5 + 1;
        if (*pbVar1 != 0) {
          *pbVar6 = *pbVar1;
        }
        pbVar6 = pbVar6 + -1;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    else {
      uVar3 = (uint)(byte)((bVar2 ^ 0xff) + 2);
      pbVar1 = pbVar5;
      pbVar5 = pbVar4 + 2;
      bVar2 = *pbVar1;
      if (bVar2 == 0) {
        pbVar6 = pbVar6 + -uVar3;
      }
      else {
        for (; uVar3 != 0; uVar3 = uVar3 - 1) {
          pbVar1 = pbVar6;
          pbVar6 = pbVar6 + -1;
          *pbVar1 = bVar2;
        }
      }
    }
  } while ((*(uint16_t *)((uint8_t *)&(dst) + 2)) <= pbVar6);
  return (int)pbVar5 - (int)src;
}



/* 2d63:044e */

/* [R7] body shape: scan */

void __cdecl16far
driver_scan1(far_t buf,uint16_t count,uint8_t fill,uint8_t threshold,far_t pattern,uint16_t index)

{
  byte *pbVar1;
  uint8_t *puVar2;
  uint8_t uVar3;
  uint8_t *puVar4;
  uint16_t uVar5;
  
  uVar5 = buf.seg;
  puVar4 = (uint8_t *)buf.ofs;
  if (fill == 0x0) {
    do {
      while (uVar3 = *puVar4, uVar3 == 0x0) {
        puVar4 = puVar4 + 1;
        count = count - 1;
        if (count == 0) {
          return;
        }
      }
      pbVar1 = (byte *)(index + pattern.ofs);
      index = index + 1 & 0xff;
      if (threshold <= *pbVar1) {
        uVar3 = 0x0;
      }
      puVar2 = puVar4;
      puVar4 = puVar4 + 1;
      *puVar2 = uVar3;
      count = count - 1;
    } while (count != 0);
  }
  else {
    do {
      while (*puVar4 != 0x0) {
        index = index + 1 & 0xff;
        if (*(byte *)(index + pattern.ofs) < threshold) {
          *puVar4 = fill;
          break;
        }
        puVar2 = puVar4;
        puVar4 = puVar4 + 1;
        *puVar2 = 0x0;
        count = count - 1;
        if (count == 0) {
          return;
        }
      }
      count = count - 1;
      puVar4 = puVar4 + 1;
    } while (count != 0);
  }
  return;
}



/* 2d63:04b7 */

/* draws a line between two screen positions in one colour */

void __cdecl16far driver_drawLine(uint8_t *ofs1,int row1,uint8_t *ofs2,int row2,uint8_t colour,uint16_t arg6,uint16_t arg7,uint16_t arg8,uint16_t arg9)

{
  uint8_t *puVar1;
  int iVar2;
  int iVar3;
  uint16_t unaff_ES;
  far_t *pfStack_8;
  
  iVar3 = row1;
  iVar2 = (int)ofs2 - (int)ofs1;
  if (iVar2 == 0) {
    iVar3 = row2 - row1;
    if (row2 < row1) {
      iVar3 = -iVar3;
    }
    iVar3 = iVar3 + 1;
    driver_drawLine_compute();
    do {
      *ofs1 = colour;
      ofs1 = ofs1 + 0x140;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  else {
    if (iVar2 < 0) {
      iVar2 = -iVar2;
      LOCK();
      ofs1 = ofs2;
      UNLOCK();
      LOCK();
      row1 = row2;
      UNLOCK();
      row2 = iVar3;
    }
    iVar3 = row2 - row1;
    if (iVar3 != 0) {
      if (iVar3 < 0) {
        iVar3 = -iVar3;
      }
      pfStack_8 = (far_t *)(CPKeys + 5);
      if (iVar2 < iVar3) {
        pfStack_8 = (far_t *)(CPKeys + 0xb);
      }
      driver_drawLine_compute();
                    /* WARNING: Could not recover jumptable at 0x0002db51. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)pfStack_8)();
      return;
    }
    driver_drawLine_compute();
    for (iVar2 = iVar2 + 1; iVar2 != 0; iVar2 = iVar2 + -1) {
      puVar1 = ofs1;
      ofs1 = ofs1 + 1;
      *puVar1 = colour;
    }
  }
  return;
}



/* 2d63:0599 */

/* [R5] only caller driver_drawLine */

uint16_t __cdecl16near driver_drawLine_compute(void)

{
  int unaff_BP;
  
  return *(uint16_t *)(unaff_BP + 0x10);
}



/* 2d63:05a9 */

/* [R7] body shape: loop */

void __cdecl16far driver_loop1(uint x1,uint x2,uint16_t y,uint8_t colour,uint16_t dstSeg)

{
  uint8_t *puVar1;
  uint uVar2;
  int iVar3;
  uint8_t *puVar4;
  
  uVar2 = x2;
  if (x2 < x1) {
    x2 = x1;
    x1 = uVar2;
  }
  uVar2 = CONCAT11((char)y,(char)(y >> 8));
  puVar4 = (uint8_t *)(x1 + uVar2 + (uVar2 >> 2));
  for (iVar3 = (x2 - x1) + 1; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar1 = colour;
  }
  return;
}



/* 2d63:05e5 */

/* fills the rectangle (x1,y1)-(x2,y2) with one colour */

uint16_t __cdecl16far
driver_fillRect(uint x1,uint y1,uint x2,uint y2,uint8_t colour,uint16_t dstSeg,uint16_t arg7,uint16_t arg8,uint16_t arg9,uint16_t arg10,uint16_t arg11)

{
  uint8_t *puVar1;
  uint uVar2;
  uint16_t in_AX;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint8_t *puVar7;
  
  uVar2 = y2;
  uVar3 = x2;
  if (x2 < x1) {
    x2 = x1;
    x1 = uVar3;
  }
  if (y2 < y1) {
    y2 = y1;
    y1 = uVar2;
  }
  uVar3 = CONCAT11((char)y1,(char)(y1 >> 8));
  puVar7 = (uint8_t *)(x1 + uVar3 + (uVar3 >> 2));
  iVar4 = (y2 - y1) + 1;
  iVar6 = (x2 - x1) + 1;
  iVar5 = iVar6;
  do {
    for (; iVar5 != 0; iVar5 = iVar5 + -1) {
      puVar1 = puVar7;
      puVar7 = puVar7 + 1;
      *puVar1 = colour;
    }
    puVar7 = puVar7 + (0x140 - iVar6);
    iVar4 = iVar4 + -1;
    iVar5 = iVar6;
  } while (iVar4 != 0);
  return in_AX;
}



/* 2d63:0652 */

/* [R7] body shape: compute */

void __cdecl16far
driver_compute3(int ofs,byte y,uint8_t colour1,uint8_t colour2,uint16_t dstSeg)

{
  uint16_t *puVar1;
  
  puVar1 = (uint16_t *)(ofs + (uint)y * 0x140);
  *puVar1 = CONCAT11(colour1,colour1);
  *(uint8_t *)(puVar1 + 0xa0) = colour1;
  *(uint8_t *)((int)puVar1 + 0x141) = colour2;
  puVar1[0x140] = CONCAT11(colour2,colour2);
  return;
}



/* 2d63:0687 */

/* [R7] body shape: compute */

void __cdecl16far
driver_compute4(int ofs,byte y,uint8_t colour1,uint8_t colour2,uint16_t dstSeg)

{
  uint16_t *puVar1;
  
  puVar1 = (uint16_t *)(ofs + (uint)y * 0x140);
  *puVar1 = CONCAT11(colour1,colour1);
  *(uint8_t *)((int)puVar1 + 0x141) = colour1;
  *(uint8_t *)(puVar1 + 0xa0) = colour2;
  puVar1[0x140] = CONCAT11(colour2,colour2);
  return;
}



/* 2d63:06bf */

bool __cdecl16far digSoundPlaying(void)

{
  code *pcVar1;
  undefined1 uVar2;
  
  pcVar1 = (code *)swi(0x66);
  uVar2 = (*pcVar1)();
  return (bool)uVar2;
}



/* 2d63:06d1 */

void __cdecl16far digPlayPreformatedSound(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x66);
  (*pcVar1)();
  return;
}



/* 2d63:06e6 */

void __cdecl16far digPlayPreformatedData(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x66);
  (*pcVar1)();
  return;
}



/* 2d63:06fb */

void __cdecl16far digStopCurrentSound(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x66);
  (*pcVar1)();
  return;
}



/* 2d63:070d */

void __cdecl16far digPreformatSound(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x66);
  (*pcVar1)(0x2410);
  return;
}



/* 2d63:071e */

/* InstallCheck:
   test for a valid signature string six bytes prior to the
   interrupt handler; this string may be either "KERN" or "MIDI" (in
   the latter case, call AX=0701h to determine whether IBMSND is
   installed) */

bool __cdecl16far digIsInstalled(void)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  uint16_t uVar4;
  
  uVar4 = (uint16_t)((ulong)DriverEntry >> 0x10);
  iVar3 = (int)DriverEntry;
  if (iVar3 == 0) {
return_false:
    bVar2 = false;
  }
  else {
    if ((*(int *)(iVar3 + -6) == 0x494d) && (*(int *)(iVar3 + -4) == 0x4944)) {
      pcVar1 = (code *)swi(0x66);
      iVar3 = (*pcVar1)(0x2410);
      if (iVar3 == 0) goto return_false;
    }
    else if ((*(int *)(iVar3 + -6) != 0x454b) || (*(int *)(iVar3 + -4) != 0x4e52))
    goto return_false;
    bVar2 = true;
  }
  return bVar2;
}



/* 2d63:075f */

void __cdecl16far midPlaySequence(uint16_t sequence)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x66);
  (*pcVar1)();
  return;
}



/* 2d63:0774 */

void __cdecl16far midSegueSequence(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x66);
  (*pcVar1)();
  return;
}



/* 2d63:078c */

void __cdecl16far midRegisterXMIDI(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x66);
  (*pcVar1)();
  return;
}



/* 2d63:07aa */

void __cdecl16far midMidiStop(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x66);
  (*pcVar1)();
  return;
}



/* 2d63:07bc */

void __cdecl16far midGetSequenceStatus(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x66);
  (*pcVar1)();
  return;
}



/* 2d63:07ce */

bool __cdecl16far midIsLoaded(void)

{
  bool bVar1;
  int iVar2;
  uint16_t uVar3;
  
  uVar3 = (uint16_t)((ulong)DriverEntry >> 0x10);
  iVar2 = (int)DriverEntry;
  if (((iVar2 == 0) || (*(int *)(iVar2 + -6) != 0x494d)) || (*(int *)(iVar2 + -4) != 0x4944)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}



/* 2d63:07fb */

void __cdecl16far midLoadDriver(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x66);
  (*pcVar1)();
  return;
}



/* 2d63:0819 */

void __cdecl16far digSetSterioPanning(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x66);
  (*pcVar1)();
  return;
}



/* 2d63:082e */

void __cdecl16far midSetRelativeValue(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x66);
  (*pcVar1)();
  return;
}



/* 2d63:0846 */

/* [R7] body shape: compute */

void __cdecl16far driver_compute5(uint16_t x1,byte y1,uint16_t x2,byte y2,uint16_t x3,byte y3,uint16_t arg7,uint16_t arg8)

{
  byte bVar1;
  byte bVar2;
  
  bVar2 = y3;
  bVar1 = y2;
  if (y2 < y1) {
    y2 = y1;
    y1 = bVar1;
  }
  if (y3 < y1) {
    y3 = y1;
    y1 = bVar2;
  }
  if (y3 < y2) {
    y2 = y3;
  }
  if (y2 != y1) {
    driver_scan2();
  }
  driver_scan2();
  return;
}



/* 2d63:098a */
void __cdecl16near driver_scan2(void)

{
  undefined1 *puVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  int in_CX;
  int iVar5;
  byte bVar6;
  byte bVar7;
  int unaff_BP;
  undefined1 *unaff_SI;
  int unaff_DI;
  undefined1 *puVar8;
  uint16_t unaff_ES;
  bool bVar9;
  
  bVar2 = *(byte *)(unaff_BP + -6);
  bVar3 = *(byte *)(unaff_BP + -0x10);
  bVar6 = *(byte *)(unaff_BP + -2);
  bVar7 = *(byte *)(unaff_BP + -0xc);
  uVar4 = *(undefined1 *)(unaff_BP + 0x12);
  do {
    iVar5 = unaff_DI - (int)unaff_SI;
    bVar9 = iVar5 < 0;
    if (bVar9) {
      iVar5 = -iVar5;
    }
    puVar8 = unaff_SI;
    for (iVar5 = iVar5 + 1; iVar5 != 0; iVar5 = iVar5 + -1) {
      puVar1 = puVar8;
      puVar8 = puVar8 + (uint)bVar9 * -2 + 1;
      *puVar1 = uVar4;
    }
    unaff_SI = unaff_SI + *(int *)(unaff_BP + -4);
    bVar9 = bVar6 < bVar2;
    bVar6 = bVar6 - bVar2;
    if (bVar9) {
      unaff_SI = unaff_SI + *(int *)(unaff_BP + -8);
      bVar6 = bVar6 + *(char *)(unaff_BP + -10);
    }
    unaff_DI = unaff_DI + *(int *)(unaff_BP + -0xe);
    bVar9 = bVar7 < bVar3;
    bVar7 = bVar7 - bVar3;
    if (bVar9) {
      unaff_DI = unaff_DI + *(int *)(unaff_BP + -0x12);
      bVar7 = bVar7 + (char)((char *)init_textFilename   /* hand fix: indexing a code* has unknown size; the bytes are read as chars */)[unaff_BP];
    }
    in_CX = in_CX + -1;
  } while (in_CX != 0);
  return;
}


/* 2d63:09c9 */

/* Fills the horizontal span x1..x2 at y, clipped to the given rect. */

void __cdecl16far driver_fillSpan(int x1,int x2,byte y,uint8_t colour,int *rect,uint16_t arg6)

{
  uint8_t *puVar1;
  int iVar2;
  int iVar3;
  uint8_t *puVar4;
  uint16_t in_stack_0000000e;
  
  iVar3 = x2;
  if (x2 < x1) {
    iVar3 = x1;
    x1 = x2;
  }
  if (x1 < *rect) {
    x1 = *rect;
  }
  if (rect[2] < iVar3) {
    iVar3 = rect[2];
  }
  if (((x1 <= iVar3) && (*(byte *)(rect + 1) <= y)) && (y <= *(byte *)(rect + 3))) {
    puVar4 = (uint8_t *)(x1 + (uint)y * 0x140);
    iVar2 = rect[4];
    for (iVar3 = (iVar3 - x1) + 1; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar1 = puVar4;
      puVar4 = puVar4 + 1;
      *puVar1 = colour;
    }
  }
  return;
}



/* 2d63:0a18 */

uint8_t __cdecl16far vda_query(void)

{
  code *pcVar1;
  uint8_t uVar2;
  
  pcVar1 = (code *)swi(0x2f);
  uVar2 = (*pcVar1)();
  return uVar2;
}



/* 2d63:0a24 */

/* ORs a mask into every word of a rectangle of the map-flag array (row stride 0x128 bytes). */

void __cdecl16far driver_setMapFlagsRect(uint32_t buf,int x1,int y1,int x2,int y2,uint mask)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  
  puVar4 = (uint *)((int)buf + x1 * 2 + y1 * 0x128);
  iVar1 = (y2 - y1) + 1;
  iVar3 = (x2 - x1) + 1;
  iVar2 = iVar3;
  puVar5 = puVar4;
  do {
    do {
      *puVar4 = *puVar4 | mask;
      puVar4 = puVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    puVar4 = puVar5 + 0x94;
    iVar1 = iVar1 + -1;
    iVar2 = iVar3;
    puVar5 = puVar4;
  } while (iVar1 != 0);
  return;
}



/* 2d63:0a67 */

/* ANDs every word of a rectangle of the map-flag array with a mask (row stride 0x128 bytes). */

void __cdecl16far driver_clearMapFlagsRect(uint32_t buf,int x1,int y1,int x2,int y2,uint mask,uint16_t arg7,uint16_t arg8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  
  puVar4 = (uint *)((int)buf + x1 * 2 + y1 * 0x128);
  iVar1 = (y2 - y1) + 1;
  iVar3 = (x2 - x1) + 1;
  iVar2 = iVar3;
  puVar5 = puVar4;
  do {
    do {
      *puVar4 = *puVar4 & mask;
      puVar4 = puVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    puVar4 = puVar5 + 0x94;
    iVar1 = iVar1 + -1;
    iVar2 = iVar3;
    puVar5 = puVar4;
  } while (iVar1 != 0);
  return;
}



/* 2d63:0aac */

/* decodes a full 320x200 run-length image (200 rows, 0x140 stride) */

void __cdecl16far driver_unrleScreen(far_t src,far_t dst)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  byte bVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  uint16_t uVar11;
  
  uVar11 = src.seg;
  pbVar7 = (byte *)src.ofs;
  pbVar9 = (byte *)dst.ofs;
  iVar6 = 200;
  do {
    pbVar8 = pbVar7 + 1;
    pbVar10 = pbVar9;
    for (bVar5 = *pbVar7; pbVar7 = pbVar8, bVar5 != 0; bVar5 = bVar5 - 1) {
      while( true ) {
        pbVar8 = pbVar7 + 1;
        bVar1 = *pbVar7;
        uVar4 = (uint)bVar1;
        if ((char)bVar1 < '\0') break;
        pbVar7 = pbVar7 + 2;
        bVar1 = *pbVar8;
        for (; uVar4 != 0; uVar4 = uVar4 - 1) {
          pbVar2 = pbVar10;
          pbVar10 = pbVar10 + 1;
          *pbVar2 = bVar1;
        }
        bVar5 = bVar5 - 1;
        if (bVar5 == 0) goto L_driver_2d63_0aac_0AE8;
      }
      for (uVar4 = (uint)(byte)-bVar1; uVar4 != 0; uVar4 = uVar4 - 1) {
        pbVar3 = pbVar10;
        pbVar10 = pbVar10 + 1;
        pbVar2 = pbVar8;
        pbVar8 = pbVar8 + 1;
        *pbVar3 = *pbVar2;
      }
    }
L_driver_2d63_0aac_0AE8:
    pbVar9 = pbVar9 + 0x140;
    iVar6 = iVar6 + -1;
    if (iVar6 == 0) {
      return;
    }
  } while( true );
}



/* 2d63:0af7 */

/* decodes a run-length sprite (header row offset + height, per-run x offsets) */

void __cdecl16far driver_unrleSprite(int *spr,far_t dst)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  uint uVar6;
  byte bVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  uint16_t uVar12;
  
  uVar12 = (uint16_t)((ulong)spr >> 0x10);
  pbVar10 = (byte *)(dst.ofs + *spr * 0x140);
  pbVar9 = (byte *)((int *)spr + 2);
  iVar8 = ((int *)spr)[1];
  do {
    pbVar11 = pbVar10;
    for (bVar7 = *pbVar9; pbVar9 = pbVar9 + 1, bVar7 != 0; bVar7 = bVar7 - 1) {
      while( true ) {
        pbVar2 = pbVar9 + 1;
        pbVar11 = pbVar11 + *pbVar9;
        pbVar9 = pbVar9 + 2;
        bVar3 = *pbVar2;
        uVar6 = (uint)bVar3;
        if ((char)bVar3 < '\0') break;
        for (; uVar6 != 0; uVar6 = uVar6 - 1) {
          pbVar5 = pbVar11;
          pbVar11 = pbVar11 + 1;
          pbVar1 = pbVar9;
          pbVar9 = pbVar9 + 1;
          *pbVar5 = *pbVar1;
        }
        bVar7 = bVar7 - 1;
        if (bVar7 == 0) goto L_driver_2d63_0af7_0B3E;
      }
      bVar4 = *pbVar9;
      for (uVar6 = (uint)(byte)-bVar3; uVar6 != 0; uVar6 = uVar6 - 1) {
        pbVar1 = pbVar11;
        pbVar11 = pbVar11 + 1;
        *pbVar1 = bVar4;
      }
    }
L_driver_2d63_0af7_0B3E:
    pbVar10 = pbVar10 + 0x140;
    iVar8 = iVar8 + -1;
    if (iVar8 == 0) {
      return;
    }
  } while( true );
}



/* 2d63:0b4d */

int __cdecl16far vgaDoSomethingWithPalette(int *paletteData)

{
  undefined1 *lenPtr;
  int *entryPtr2;
  undefined1 countHi;
  int iVar3;
  int repeatCount;
  int blocksLeft;
  int *palPtr;
  int curIndex;
  int startIndex;
  
  curIndex = 0;
  palPtr = (int *)paletteData + 1;
  iVar3 = *paletteData;
  for (blocksLeft = iVar3; blocksLeft != 0; blocksLeft = blocksLeft + -1) {
    lenPtr = (undefined1 *)((int)palPtr + 1);
    countHi = (undefined1)((uint)iVar3 >> 8);
    startIndex = curIndex + CONCAT11(countHi,(char)*palPtr);
    palPtr = palPtr + 1;
    repeatCount = CONCAT11(countHi,*lenPtr);
    if (repeatCount == 0) {
      repeatCount = 0x100;
    }
    do {
      out(0x3c8,(char)startIndex);
      curIndex = startIndex + 1;
      out(0x3c9,(char)*palPtr);
      entryPtr2 = palPtr + 1;
      out(0x3c9,*(undefined1 *)((int)palPtr + 1));
      palPtr = (int *)((int)palPtr + 3);
      iVar3 = CONCAT11((char)((uint)startIndex >> 8),(char)*entryPtr2);
      out(0x3c9,(char)*entryPtr2);
      repeatCount = repeatCount + -1;
      startIndex = curIndex;
    } while (repeatCount != 0);
  }
  return iVar3;
}



/* 2d63:0b8b */

/* DX = Input Status #1 Register.
   0x1 = DisplayDisabled Bit
   0x8 = Vertical Retrace */

uint8_t __cdecl16far vgaWaitVerticalRetrace(void)

{
  byte bVar1;
  
  do {
    bVar1 = in(0x3da);
  } while ((bVar1 & 8) == 0);
  return bVar1;
}



/* 2d63:0b94 */

/* returns the low four bits of the argument */

uint __cdecl16far lowNibble(uint value,uint16_t arg2)

{
  return value & 0xf;
}



/* 2d63:0bad */

/* copies a run of words from the source to the destination */

void __cdecl16far driver_copyWords(far_t src,far_t dst,uint16_t count)

{
  uint16_t *puVar1;
  uint16_t *puVar2;
  uint16_t *puVar3;
  uint16_t *puVar4;
  
  puVar3 = (uint16_t *)src.ofs;
  puVar4 = (uint16_t *)dst.ofs;
  for (; count != 0; count = count - 1) {
    puVar2 = puVar4;
    puVar4 = puVar4 + 1;
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar2 = *puVar1;
  }
  return;
}



/* 2d63:0bc8 */

/* zero-fills a run of words */

void __cdecl16far driver_zeroWords(far_t dst,uint16_t count)

{
  uint16_t *puVar1;
  uint16_t *puVar2;
  
  puVar2 = (uint16_t *)dst.ofs;
  for (; count != 0; count = count - 1) {
    puVar1 = puVar2;
    puVar2 = puVar2 + 1;
    *puVar1 = 0;
  }
  return;
}



/* 2d63:0bde */

/* [R7] body shape: loop */

void __cdecl16far driver_loop3(far_t src,far_t dst)

{
  char *outPtr;
  undefined1 countHi;
  int runCount;
  int byteCount;
  int spanCount;
  char *srcPtr;
  char *dstPtr;
  
  dstPtr = (char *)dst.ofs;
  srcPtr = (char *)(src.ofs + 2);
  runCount = *(int *)MK_FP(src.seg, src.ofs);
  for (spanCount = runCount; spanCount != 0; spanCount = spanCount + -1) {
    outPtr = srcPtr;
    srcPtr = srcPtr + 1;
    countHi = (undefined1)((uint)runCount >> 8);
    dstPtr = dstPtr + CONCAT11(countHi,*outPtr) * 3;
    runCount = CONCAT11(countHi,*srcPtr);
    if (*srcPtr == '\0') {
      runCount = 0x100;
    }
    for (byteCount = runCount * 3; srcPtr = srcPtr + 1, byteCount != 0; byteCount = byteCount + -1) {
      outPtr = dstPtr;
      dstPtr = dstPtr + 1;
      *outPtr = *srcPtr;
    }
  }
  return;
}


