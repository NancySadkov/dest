/*
 * ovc01_driver.c - recovered from STRONG.EXE
 * memory block: OVC01_driver.c
 * range: 2d63:0000 - 2d63:0c1f
 * functions: 60
 */
#include "recovered.h"


/* 2d63:0000 */

/* packs seg+ofs into a uint32_t */

uint32_t __cdecl16far mkp(uint16_t ofs,uint16_t seg)

{
  return CONCAT22(seg + (ofs >> 4),ofs) & 0xffff000f;
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

void __cdecl16far blitRaw(uint16_t x,uint16_t y,uint16_t w,uint16_t h,uint16_t src,uint16_t dst)

{
  undefined1 *puVar1;
  uint uVar2;
  int dy;
  int iVar3;
  int dx;
  undefined1 *s;
  undefined1 *d;
  
  uVar2 = CONCAT11((char)y,(char)(y >> 8));
  s = (undefined1 *)(uVar2 + (uVar2 >> 2) + x);
  dy = (h - y) + 1;
  dx = (w - x) + 1;
  iVar3 = dx;
  d = s;
  do {
    for (; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar1 = s;
      s = s + 1;
      *d = *puVar1;
      d = d + 1;
    }
    s = s + (0x140 - dx);
    d = d + (0x140 - dx);
    dy = dy + -1;
    iVar3 = dx;
  } while (dy != 0);
  return;
}



/* 2d63:00aa */

void __cdecl16far
lbm_combine_bitplanes(far_t src,far_t dst,uint16_t npixels,uint8_t nplanes,uint16_t plane_sz)

{
  byte *pbVar1;
  byte pixel;
  byte bits;
  byte mask;
  byte *s;
  byte *ps;
  byte *d;
  bool bit0;
  
  s = (byte *)src.ofs;
  d = (byte *)dst.ofs;
  mask = 0x80;
  do {
    pixel = 0;
    bits = 1;
    ps = s;
    do {
      if ((*ps & mask) != 0) {
        pixel = pixel | bits;
      }
      bits = bits << 1 | (char)bits < '\0';
      ps = ps + plane_sz;
    } while (bits != (byte)('\x01' << (nplanes & 7) | 1U >> 8 - (nplanes & 7)));
    pbVar1 = d;
    d = d + 1;
    *pbVar1 = pixel;
    bit0 = (bool)(mask & 1);
    mask = mask >> 1 | mask << 7;
    if (bit0) {
      s = s + 1;
    }
    npixels = npixels - 1;
  } while (npixels != 0);
  return;
}



/* 2d63:00eb */

/* Loads big-endian 32bit integer into DX:AX pair
   NOTE: the function has a bug (high order bytes are swapped) */

uint32_t __cdecl16far be4(uint32_t be)

{
  return CONCAT22((int)be,CONCAT11((*(uint8_t *)((uint8_t *)&(be) + 2)),(*(uint8_t *)((uint8_t *)&(be) + 3))));
}



/* 2d63:00fc */

/* Flips bytes in a 16bt word */

uint16_t __cdecl16far be2(uint16_t w)

{
  return CONCAT11((undefined1)w,(*(uint8_t *)((uint8_t *)&(w) + 1)));
}



/* 2d63:0107 */

char __cdecl16far driver_2d63_0107(char param_1,byte param_2,char param_3)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = (byte)(CONCAT11(CARRY1(param_3 + param_1,param_2),param_3 + param_1 + param_2) >> 7);
  if (2 < bVar1) {
    bVar1 = 2;
  }
  bVar2 = ((char)(param_2 - param_1) >> 2) + 2;
  if ((char)bVar2 < '\0') {
    bVar2 = 0;
  }
  else if (4 < bVar2) {
    bVar2 = 4;
  }
  return (bVar1 * '\x05' + -0xc) - bVar2;
}



/* 2d63:014b */

char __cdecl16far driver_2d63_014b(char param_1,byte param_2,char param_3)

{
  byte bVar1;
  
  bVar1 = (byte)(CONCAT11(CARRY1(param_3 + param_1,param_2),param_3 + param_1 + param_2) >> 7);
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
  uVar2 = (*pcVar1)((char *)"puppetmaker" + 3);
  return uVar2 & 7;
}



/* 2d63:01a7 */

void __cdecl16far miceSetPosition(uint16_t col,uint16_t row)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x33);
  (*pcVar1)((char *)"puppetmaker" + 3);
  return;
}



/* 2d63:01bf */

undefined1 __cdecl16far vgaSetPalette(undefined1 *param_1,undefined1 param_2,int param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined2 uVar3;
  
  out(0x3c8,param_2);
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  puVar2 = (undefined1 *)param_1;
  do {
    out(0x3c9,*puVar2);
    puVar1 = puVar2 + 2;
    out(0x3c9,puVar2[1]);
    puVar2 = puVar2 + 3;
    out(0x3c9,*puVar1);
    param_3 = param_3 + -1;
  } while (param_3 != 0);
  return *puVar1;
}



/* 2d63:01df */

undefined1 __cdecl16far vgaSetPalette8bit(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined2 uVar4;
  
  out(0x3c8,0);
  iVar2 = 0x100;
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  puVar3 = (undefined1 *)param_1;
  do {
    out(0x3c9,*puVar3);
    puVar1 = puVar3 + 2;
    out(0x3c9,puVar3[1]);
    puVar3 = puVar3 + 3;
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

int __cdecl16far unrle(far_t src,far_t dst,uint16_t len)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  uint i;
  byte *end;
  byte *pps;
  byte *s;
  byte *d;
  uint16_t uVar5;
  
  uVar5 = src.seg;
  d = (byte *)dst.ofs;
  end = d + len;
  s = (byte *)src.ofs;
  do {
    do {
      pps = s;
      s = pps + 1;
      bVar2 = *pps;
    } while (bVar2 == 0x80);
    if (bVar2 < 0x80) {
      for (i = (uint)(byte)(bVar2 + 1); i != 0; i = i - 1) {
        pbVar4 = d;
        d = d + 1;
        pbVar1 = s;
        s = s + 1;
        *pbVar4 = *pbVar1;
      }
    }
    else {
      pbVar1 = s;
      s = pps + 2;
      bVar3 = *pbVar1;
      for (i = (uint)(byte)((bVar2 ^ 0xff) + 2); i != 0; i = i - 1) {
        pbVar1 = d;
        d = d + 1;
        *pbVar1 = bVar3;
      }
    }
  } while (d < end);
  return (int)s - (int)src.ofs;
}



/* 2d63:0241 */

int __cdecl16far rle_blit_decode(byte *src,byte *dst,uint16_t sz)

{
  byte *pbVar1;
  byte bVar2;
  uint i;
  byte *end;
  byte *ps;
  byte *s;
  undefined2 in_stack_00000006;
  undefined2 in_stack_0000000a;
  
  end = dst + sz;
  s = src;
  do {
    do {
      ps = s;
      s = ps + 1;
      bVar2 = *ps;
    } while (bVar2 == 0x80);
    if (bVar2 < 0x80) {
      i = (uint)(byte)(bVar2 + 1);
      do {
        pbVar1 = s;
        s = s + 1;
        if (*pbVar1 != 0) {
          *dst = *pbVar1;
        }
        dst = dst + 1;
        i = i - 1;
      } while (i != 0);
    }
    else {
      i = (uint)(byte)((bVar2 ^ 0xff) + 2);
      pbVar1 = s;
      s = ps + 2;
      bVar2 = *pbVar1;
      if (bVar2 == 0) {
        dst = dst + i;
      }
      else {
        for (; i != 0; i = i - 1) {
          pbVar1 = dst;
          dst = dst + 1;
          *pbVar1 = bVar2;
        }
      }
    }
  } while (dst < end);
  return (int)s - (int)src;
}



/* 2d63:0292 */

void __cdecl16far grabRemap(far_t pixels,uint8_t scolor,uint8_t dcolor)

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

void __cdecl16far masked_memcpy(char *dst,char *src,int skip,int src_sz,int dst_sz,uint mask)

{
  char *edst;
  char *erc;
  char *psrc;
  char *pdst;
  
  psrc = (char *)src;
  erc = psrc + src_sz;
  pdst = (char *)dst;
  edst = pdst + dst_sz;
  for (; (pdst < edst && (psrc < erc)); psrc = psrc + 1) {
    if ((mask & 1) != 0) {
      if (skip == 0) {
        if (*psrc != '\0') {
          *pdst = *psrc;
        }
        pdst = pdst + 1;
      }
      else {
        skip = skip + -1;
      }
    }
    mask = mask >> 1 | (uint)((mask & 1) != 0) << 0xf;
  }
  return;
}



/* 2d63:02fe */

int __cdecl16far driver_2d63_02fe(char *param_1,uint param_2,uint param_3)

{
  char *pcVar1;
  char *pcVar2;
  
  if (param_3 < param_2) {
    param_2 = param_3;
  }
  pcVar1 = (char *)param_1;
  pcVar2 = pcVar1;
  do {
    pcVar2 = pcVar2 + 1;
    if (pcVar1 + param_2 <= pcVar2) break;
  } while (*param_1 == *pcVar2);
  return (int)pcVar2 - (int)pcVar1;
}



/* 2d63:032d */

/* WARNING: Restarted to delay deadcode elimination for space: stack */

int __cdecl16far rle_line(uint8_t *src,uint8_t *dst,uint16_t npixels)

{
  uint8_t *puVar1;
  int iVar2;
  uint8_t *end;
  uint8_t *puVar3;
  uint8_t *pps;
  uint c;
  uint8_t *ps;
  uint8_t *pd;
  undefined2 uVar4;
  undefined2 uVar5;
  
  uVar5 = (undefined2)(far_to_u32(src) >> 0x10);
  puVar3 = (uint8_t *)src;
  end = puVar3 + npixels;
  uVar4 = (undefined2)(far_to_u32(dst) >> 0x10);
  ps = puVar3;
  pd = (uint8_t *)dst;
LAB_2d63_0343:
  do {
    c = (int)end - (int)ps;
    if (0x7f < c) {
      c = 0x80;
    }
    pps = ps;
    do {
      pps = pps + 1;
      if (ps + c <= pps) break;
    } while (*ps == *pps);
    c = (int)pps - (int)ps;
    if (c < 3) {
      ps = ps + 1;
      iVar2 = (int)ps - (int)puVar3;
      if (((byte)iVar2 < 0x80) && (ps < end)) goto LAB_2d63_0343;
      *pd = (byte)iVar2 - 1;
      for (; pd = pd + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
        puVar1 = puVar3;
        puVar3 = puVar3 + 1;
        *pd = *puVar1;
      }
    }
    else {
      if (puVar3 != ps) {
        iVar2 = (int)ps - (int)puVar3;
        *pd = (char)iVar2 + 0xff;
        for (; pd = pd + 1, ps = puVar3, iVar2 != 0; iVar2 = iVar2 + -1) {
          puVar1 = puVar3;
          puVar3 = puVar3 + 1;
          *pd = *puVar1;
        }
      }
      puVar3 = pd + 1;
      *pd = 0x1 - (char)c;
      pd = pd + 2;
      *puVar3 = *ps;
      puVar3 = ps + c;
    }
    ps = puVar3;
    if (end <= puVar3) {
      return (int)pd - (int)(uint8_t *)dst;
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
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  uint cnt;
  byte *ppsrc;
  byte *psrc;
  byte *pdst;
  undefined2 uVar5;
  undefined2 uVar6;
  
  uVar6 = (undefined2)(far_to_u32(src) >> 0x10);
  uVar5 = (undefined2)(far_to_u32(dst) >> 0x10);
  pdst = (byte *)dst + len + -1;
  psrc = (byte *)src;
  do {
    do {
      ppsrc = psrc;
      psrc = ppsrc + 1;
      bVar2 = *ppsrc;
    } while (bVar2 == 0x80);
    if (bVar2 < 0x80) {
      cnt = (uint)(byte)(bVar2 + 1);
      do {
        pbVar1 = psrc;
        psrc = psrc + 1;
        pbVar4 = pdst;
        pdst = pdst + -1;
        *pbVar4 = *pbVar1;
        cnt = cnt - 1;
      } while (cnt != 0);
    }
    else {
      pbVar1 = psrc;
      psrc = ppsrc + 2;
      bVar3 = *pbVar1;
      for (cnt = (uint)(byte)((bVar2 ^ 0xff) + 2); cnt != 0; cnt = cnt - 1) {
        pbVar1 = pdst;
        pdst = pdst + -1;
        *pbVar1 = bVar3;
      }
    }
  } while ((byte *)dst <= pdst);
  return (int)psrc - (int)(byte *)src;
}



/* 2d63:03fc */

int __cdecl16far drawLine2(byte *param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  
  uVar8 = (undefined2)((ulong)param_1 >> 0x10);
  uVar7 = (undefined2)((ulong)param_2 >> 0x10);
  pbVar6 = (byte *)param_2 + param_3 + -1;
  pbVar5 = (byte *)param_1;
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
  } while ((byte *)param_2 <= pbVar6);
  return (int)pbVar5 - (int)(byte *)param_1;
}



/* 2d63:044e */

void __cdecl16far
driver_2d63_044e(char *param_1,int param_2,char param_3,byte param_4,undefined4 param_5,uint param_6
                )

{
  byte *pbVar1;
  char *pcVar2;
  char cVar3;
  char *pcVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  pcVar4 = (char *)param_1;
  uVar6 = (undefined2)((ulong)param_5 >> 0x10);
  if (param_3 == '\0') {
    do {
      while (cVar3 = *pcVar4, cVar3 == '\0') {
        pcVar4 = pcVar4 + 1;
        param_2 = param_2 + -1;
        if (param_2 == 0) {
          return;
        }
      }
      pbVar1 = (byte *)(param_6 + (int)param_5);
      param_6 = param_6 + 1 & 0xff;
      if (param_4 <= *pbVar1) {
        cVar3 = '\0';
      }
      pcVar2 = pcVar4;
      pcVar4 = pcVar4 + 1;
      *pcVar2 = cVar3;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  else {
    do {
      while (*pcVar4 != '\0') {
        param_6 = param_6 + 1 & 0xff;
        if (*(byte *)(param_6 + (int)param_5) < param_4) {
          *pcVar4 = param_3;
          break;
        }
        pcVar2 = pcVar4;
        pcVar4 = pcVar4 + 1;
        *pcVar2 = '\0';
        param_2 = param_2 + -1;
        if (param_2 == 0) {
          return;
        }
      }
      param_2 = param_2 + -1;
      pcVar4 = pcVar4 + 1;
    } while (param_2 != 0);
  }
  return;
}



/* 2d63:04b7 */

void __cdecl16far
vga_2d63_04b7(undefined1 *param_1,int param_2,undefined1 *param_3,int param_4,undefined1 param_5)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_ES;
  far_t *pfStack_8;
  
  iVar3 = param_2;
  uVar4 = 0x140;
  iVar2 = (int)param_3 - (int)param_1;
  if (iVar2 == 0) {
    iVar3 = param_4 - param_2;
    if (param_4 < param_2) {
      iVar3 = -iVar3;
    }
    iVar3 = iVar3 + 1;
    driver_2d63_0599();
    do {
      *param_1 = param_5;
      param_1 = param_1 + 0x140;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  else {
    if (iVar2 < 0) {
      iVar2 = -iVar2;
      LOCK();
      param_1 = param_3;
      UNLOCK();
      LOCK();
      param_2 = param_4;
      UNLOCK();
      param_4 = iVar3;
    }
    param_4 = param_4 - param_2;
    if (param_4 != 0) {
      if (param_4 < 0) {
        param_4 = -param_4;
        uVar4 = 0xfec0;
      }
      pfStack_8 = (far_t *)(CPKeys + 5);
      if (iVar2 < param_4) {
        pfStack_8 = (far_t *)(CPKeys + 0xb);
        iVar2 = param_4;
      }
      driver_2d63_0599(iVar2,uVar4);
                    /* WARNING: Could not recover jumptable at 0x0002db51. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)pfStack_8)();
      return;
    }
    driver_2d63_0599();
    for (iVar2 = iVar2 + 1; iVar2 != 0; iVar2 = iVar2 + -1) {
      puVar1 = param_1;
      param_1 = param_1 + 1;
      *puVar1 = param_5;
    }
  }
  return;
}



/* 2d63:0599 */

undefined2 __cdecl16near driver_2d63_0599(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  return *(undefined2 *)(unaff_BP + 0x10);
}



/* 2d63:05a9 */

void __cdecl16far
driver_2d63_05a9(uint param_1,uint param_2,undefined2 param_3,undefined1 param_4,undefined2 param_5)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  
  uVar2 = param_2;
  if (param_2 < param_1) {
    param_2 = param_1;
    param_1 = uVar2;
  }
  uVar2 = CONCAT11((char)param_3,(char)((uint)param_3 >> 8));
  puVar4 = (undefined1 *)(param_1 + uVar2 + (uVar2 >> 2));
  for (iVar3 = (param_2 - param_1) + 1; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *puVar1 = param_4;
  }
  return;
}



/* 2d63:05e5 */

undefined2 __cdecl16far
driver_2d63_05e5(uint param_1,uint param_2,uint param_3,uint param_4,undefined1 param_5,
                undefined2 param_6)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined2 in_AX;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  
  uVar2 = param_4;
  uVar3 = param_3;
  if (param_3 < param_1) {
    param_3 = param_1;
    param_1 = uVar3;
  }
  if (param_4 < param_2) {
    param_4 = param_2;
    param_2 = uVar2;
  }
  uVar3 = CONCAT11((char)param_2,(char)(param_2 >> 8));
  puVar7 = (undefined1 *)(param_1 + uVar3 + (uVar3 >> 2));
  iVar4 = (param_4 - param_2) + 1;
  iVar6 = (param_3 - param_1) + 1;
  iVar5 = iVar6;
  do {
    for (; iVar5 != 0; iVar5 = iVar5 + -1) {
      puVar1 = puVar7;
      puVar7 = puVar7 + 1;
      *puVar1 = param_5;
    }
    puVar7 = puVar7 + (0x140 - iVar6);
    iVar4 = iVar4 + -1;
    iVar5 = iVar6;
  } while (iVar4 != 0);
  return in_AX;
}



/* 2d63:0652 */

void __cdecl16far
driver_2d63_0652(int param_1,byte param_2,undefined1 param_3,undefined1 param_4,undefined2 param_5)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)(param_1 + (uint)param_2 * 0x140);
  *puVar1 = CONCAT11(param_3,param_3);
  *(undefined1 *)(puVar1 + 0xa0) = param_3;
  *(undefined1 *)((int)puVar1 + 0x141) = param_4;
  puVar1[0x140] = CONCAT11(param_4,param_4);
  return;
}



/* 2d63:0687 */

void __cdecl16far
driver_2d63_0687(int param_1,byte param_2,undefined1 param_3,undefined1 param_4,undefined2 param_5)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)(param_1 + (uint)param_2 * 0x140);
  *puVar1 = CONCAT11(param_3,param_3);
  *(undefined1 *)((int)puVar1 + 0x141) = param_3;
  *(undefined1 *)(puVar1 + 0xa0) = param_4;
  puVar1[0x140] = CONCAT11(param_4,param_4);
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
  (*pcVar1)((char *)"puppetmaker" + 3);
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
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)UNK_0000_0198 >> 0x10);
  iVar3 = (int)UNK_0000_0198;
  if (iVar3 == 0) {
return_false:
    bVar2 = false;
  }
  else {
    if ((*(int *)(iVar3 + -6) == 0x494d) && (*(int *)(iVar3 + -4) == 0x4944)) {
      pcVar1 = (code *)swi(0x66);
      iVar3 = (*pcVar1)((char *)"puppetmaker" + 3);
      if (iVar3 == 0) goto return_false;
    }
    else if (((char *)*(int *)(iVar3 + -6) != (char *)"build\\genbazr1.lbm" + 0x12) ||
            ((char *)*(int *)(iVar3 + -4) !=
             (char *)"A LAWFUL leader must achieve the rank of EMPEROR." + 0x11)) goto return_false;
    bVar2 = true;
  }
  return bVar2;
}



/* 2d63:075f */

void __cdecl16far midPlaySequence(uint16_t param_1)

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
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)UNK_0000_0198 >> 0x10);
  iVar2 = (int)UNK_0000_0198;
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

void __cdecl16far
driver_2d63_0846(undefined2 param_1,byte param_2,undefined2 param_3,byte param_4,undefined2 param_5,
                byte param_6)

{
  byte bVar1;
  byte bVar2;
  char *pcVar3;
  
  bVar2 = param_6;
  bVar1 = param_4;
  pcVar3 = (char *)"puppetmaker" + 3;
  if (param_4 < param_2) {
    param_4 = param_2;
    param_2 = bVar1;
  }
  if (param_6 < param_2) {
    param_6 = param_2;
    param_2 = bVar2;
  }
  if (param_6 < param_4) {
    param_4 = param_6;
  }
  if (param_4 != param_2) {
    driver_2d63_098a((char *)"puppetmaker" + 3);
  }
  driver_2d63_098a(pcVar3);
  return;
}



/* 2d63:098a */

void __cdecl16near driver_2d63_098a(void)

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
  undefined2 unaff_ES;
  undefined2 unaff_SS;
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
      bVar7 = bVar7 + (char)((code *)init_3381_08dc)[unaff_BP];
    }
    in_CX = in_CX + -1;
  } while (in_CX != 0);
  return;
}



/* 2d63:09c9 */

void __cdecl16far
driver_2d63_09c9(int param_1,int param_2,byte param_3,undefined1 param_4,int *param_5)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined1 *puVar5;
  undefined2 uVar6;
  
  iVar3 = param_2;
  if (param_2 < param_1) {
    iVar3 = param_1;
    param_1 = param_2;
  }
  uVar6 = (undefined2)((ulong)param_5 >> 0x10);
  piVar4 = (int *)param_5;
  if (param_1 < *param_5) {
    param_1 = *param_5;
  }
  if (piVar4[2] < iVar3) {
    iVar3 = piVar4[2];
  }
  if (((param_1 <= iVar3) && (*(byte *)(piVar4 + 1) <= param_3)) &&
     (param_3 <= *(byte *)(piVar4 + 3))) {
    puVar5 = (undefined1 *)(param_1 + (uint)param_3 * 0x140);
    iVar2 = piVar4[4];
    for (iVar3 = (iVar3 - param_1) + 1; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar1 = puVar5;
      puVar5 = puVar5 + 1;
      *puVar1 = param_4;
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

void __cdecl16far
driver_2d63_0a24(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,uint param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  
  puVar4 = (uint *)((int)param_1 + param_2 * 2 + param_3 * 0x128);
  iVar1 = (param_5 - param_3) + 1;
  iVar3 = (param_4 - param_2) + 1;
  iVar2 = iVar3;
  puVar5 = puVar4;
  do {
    do {
      *puVar4 = *puVar4 | param_6;
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

void __cdecl16far
driver_2d63_0a67(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,uint param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  
  puVar4 = (uint *)((int)param_1 + param_2 * 2 + param_3 * 0x128);
  iVar1 = (param_5 - param_3) + 1;
  iVar3 = (param_4 - param_2) + 1;
  iVar2 = iVar3;
  puVar5 = puVar4;
  do {
    do {
      *puVar4 = *puVar4 & param_6;
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

void __cdecl16far driver_2d63_0aac(byte *param_1,byte *param_2)

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
  undefined2 uVar11;
  undefined2 uVar12;
  
  uVar12 = (undefined2)((ulong)param_1 >> 0x10);
  pbVar7 = (byte *)param_1;
  uVar11 = (undefined2)((ulong)param_2 >> 0x10);
  pbVar9 = (byte *)param_2;
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
        if (bVar5 == 0) goto LAB_2d63_0ae8;
      }
      for (uVar4 = (uint)(byte)-bVar1; uVar4 != 0; uVar4 = uVar4 - 1) {
        pbVar3 = pbVar10;
        pbVar10 = pbVar10 + 1;
        pbVar2 = pbVar8;
        pbVar8 = pbVar8 + 1;
        *pbVar3 = *pbVar2;
      }
    }
LAB_2d63_0ae8:
    pbVar9 = pbVar9 + 0x140;
    iVar6 = iVar6 + -1;
    if (iVar6 == 0) {
      return;
    }
  } while( true );
}



/* 2d63:0af7 */

void __cdecl16far driver_2d63_0af7(int *param_1,undefined4 param_2)

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
  undefined2 uVar12;
  undefined2 uVar13;
  
  uVar13 = (undefined2)((ulong)param_1 >> 0x10);
  uVar12 = (undefined2)((ulong)param_2 >> 0x10);
  pbVar10 = (byte *)((int)param_2 + *param_1 * 0x140);
  pbVar9 = (byte *)((int *)param_1 + 2);
  iVar8 = ((int *)param_1)[1];
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
        if (bVar7 == 0) goto LAB_2d63_0b3e;
      }
      bVar4 = *pbVar9;
      for (uVar6 = (uint)(byte)-bVar3; uVar6 != 0; uVar6 = uVar6 - 1) {
        pbVar1 = pbVar11;
        pbVar11 = pbVar11 + 1;
        *pbVar1 = bVar4;
      }
    }
LAB_2d63_0b3e:
    pbVar10 = pbVar10 + 0x140;
    iVar8 = iVar8 + -1;
    if (iVar8 == 0) {
      return;
    }
  } while( true );
}



/* 2d63:0b4d */

int __cdecl16far vgaDoSomethingWithPalette(int *param_1)

{
  undefined1 *puVar1;
  int *piVar2;
  undefined1 uVar4;
  int iVar3;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  undefined2 uVar10;
  
  uVar10 = (undefined2)((ulong)param_1 >> 0x10);
  iVar8 = 0;
  piVar7 = (int *)param_1 + 1;
  iVar3 = *param_1;
  for (iVar6 = iVar3; iVar6 != 0; iVar6 = iVar6 + -1) {
    puVar1 = (undefined1 *)((int)piVar7 + 1);
    uVar4 = (undefined1)((uint)iVar3 >> 8);
    iVar9 = iVar8 + CONCAT11(uVar4,(char)*piVar7);
    piVar7 = piVar7 + 1;
    iVar5 = CONCAT11(uVar4,*puVar1);
    if (iVar5 == 0) {
      iVar5 = 0x100;
    }
    do {
      out(0x3c8,(char)iVar9);
      iVar8 = iVar9 + 1;
      out(0x3c9,(char)*piVar7);
      piVar2 = piVar7 + 1;
      out(0x3c9,*(undefined1 *)((int)piVar7 + 1));
      piVar7 = (int *)((int)piVar7 + 3);
      iVar3 = CONCAT11((char)((uint)iVar9 >> 8),(char)*piVar2);
      out(0x3c9,(char)*piVar2);
      iVar5 = iVar5 + -1;
      iVar9 = iVar8;
    } while (iVar5 != 0);
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

uint __cdecl16far driver_2d63_0b94(uint param_1)

{
  return param_1 & 0xf;
}



/* 2d63:0bad */

void __cdecl16far driver_2d63_0bad(undefined2 *param_1,undefined2 *param_2,int param_3)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  
  puVar3 = (undefined2 *)param_1;
  puVar4 = (undefined2 *)param_2;
  for (; param_3 != 0; param_3 = param_3 + -1) {
    puVar2 = puVar4;
    puVar4 = puVar4 + 1;
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar2 = *puVar1;
  }
  return;
}



/* 2d63:0bc8 */

void __cdecl16far driver_2d63_0bc8(undefined2 *param_1,int param_2)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  
  puVar2 = (undefined2 *)param_1;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    puVar1 = puVar2;
    puVar2 = puVar2 + 1;
    *puVar1 = 0;
  }
  return;
}



/* 2d63:0bde */

void __cdecl16far driver_2d63_0bde(int *param_1,char *param_2)

{
  int *piVar1;
  char *pcVar2;
  undefined1 uVar4;
  int iVar3;
  int iVar5;
  int iVar6;
  int *piVar7;
  char *pcVar8;
  undefined2 uVar9;
  
  uVar9 = (undefined2)((ulong)param_1 >> 0x10);
  pcVar8 = (char *)param_2;
  piVar7 = (int *)param_1 + 1;
  iVar3 = *param_1;
  for (iVar6 = iVar3; iVar6 != 0; iVar6 = iVar6 + -1) {
    piVar1 = piVar7;
    piVar7 = (int *)((int)piVar7 + 1);
    uVar4 = (undefined1)((uint)iVar3 >> 8);
    pcVar8 = pcVar8 + CONCAT11(uVar4,(char)*piVar1) * 3;
    iVar3 = CONCAT11(uVar4,(char)*piVar7);
    if ((char)*piVar7 == '\0') {
      iVar3 = 0x100;
    }
    for (iVar5 = iVar3 * 3; piVar7 = (int *)((int)piVar7 + 1), iVar5 != 0; iVar5 = iVar5 + -1) {
      pcVar2 = pcVar8;
      pcVar8 = pcVar8 + 1;
      *pcVar2 = (char)*piVar7;
    }
  }
  return;
}


