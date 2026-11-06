/*
 * ovc17_stash.c - recovered from STRONG.EXE
 * memory block: OVC17_stash.c
 * range: 474a:0000 - 474a:161f
 * functions: 26
 */
#include "recovered.h"


/* 474a:0000 */

uint16_t __cdecl16far stshOpen(uint16_t file_id)

{
  int fh;
  
  fh = open_wait_unlock_and_disk((char *)*(undefined2 *)(file_id * 4));
  ((int *)StshHandles)[file_id] = fh;
  *(undefined2 *)((int)(long *)StshPtrs + file_id * 4 + 2) = 0;
  *(undefined2 *)((long *)StshPtrs + file_id) = 0;
  return file_id;
}



/* 474a:004e */

void __cdecl16far stshClose(uint16_t file_id)

{
  if (((int *)StshHandles)[file_id] != -1) {
    close(((int *)StshHandles)[file_id]);
  }
  ((int *)StshHandles)[file_id] = -1;
  return;
}



/* 474a:008f */
/* recovered by relaxed-limit retry */
/* stshRead: read bytes from the stash file into a far buffer.
 * Recovered with the reset-vars workaround (Ghidra forced-merge bug).
 */
char __cdecl16far stshRead(uint16_t file_id, far_t buf, uint32_t nbytes)

{
  uint16_t nb_lo = (uint16_t)nbytes;
  uint16_t nb_hi = (uint16_t)(nbytes >> 16);

  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  uint32_t uVar10;
  void *pvVar11;
  uint uVar12;
  uint uVar13;
  void *pvStack_16;
  uint16_t uStack_14;
  uint uStack_10;
  uint uStack_e;
  uint uStack_c;
  uint uStack_a;
  
  uVar3 = nb_lo;
  uVar5 = *(uint *)((int)(long *)StshPtrs + file_id * 4 + 2);
  uVar7 = *(uint *)(file_id * 4 + 0xaa2);
  cVar6 = (char)nb_hi;
  if ((uVar5 < uVar7) ||
     ((uVar5 == uVar7 &&
      (*(uint *)((long *)StshPtrs + file_id) < *(uint *)(file_id * 4 + 0xaa0))))
     ) {
    uVar7 = nb_hi + *(int *)((int)(long *)StshPtrs + file_id * 4 + 2) +
            (uint)CARRY2(nb_lo,*(uint *)((long *)StshPtrs + file_id));
    uVar5 = *(uint *)(file_id * 4 + 0xaa2);
    if ((uVar5 <= uVar7) &&
       ((uVar5 < uVar7 ||
        (*(uint *)(file_id * 4 + 0xaa0) <
         nb_lo + *(uint *)((long *)StshPtrs + file_id))))) {
      uVar5 = *(uint *)(file_id * 4 + 0xaa0);
      puVar1 = (uint *)((int)&AgntAnms[0x53].y + 1 + file_id * 4);
      nb_lo = uVar5 - *puVar1;
      nb_hi =
           (*(int *)(file_id * 4 + 0xaa2) -
           *(int *)((int)&AgntAnms[0x53].field_0x10 + file_id * 4)) -
           (uint)(uVar5 < *puVar1);
    }
    uStack_e = nb_hi;
    uStack_10 = nb_lo;
    if (file_id == 0) {
      if (((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) <= (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2))) &&
         (((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) < (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) || ((uint)StshPtrs[0] < (uint)FMXmsHandle)))) {
        uVar5 = ((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) - (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
                (uint)((uint)FMXmsHandle < (uint)StshPtrs[0]);
        if ((uVar5 < nb_hi) ||
           ((uVar5 <= nb_hi &&
            ((uint)FMXmsHandle - (uint)StshPtrs[0] <= nb_lo)))) {
          uStack_c = (uint)FMXmsHandle - (uint)StshPtrs[0];
          uStack_a = ((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) - (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
                     (uint)((uint)FMXmsHandle < (uint)StshPtrs[0]);
        }
        else {
          uStack_a = nb_hi;
          uStack_c = nb_lo;
        }
        uVar5 = (uint)StshPtrs[0];
        uVar7 = (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2));
        uVar12 = uStack_c;
        uVar13 = uStack_a;
        uVar10 = ovr_mkp((uint16_t)buf.ofs,buf.seg);
        xms_1000_032f((int)uVar10,(undefined2)(uVar10 >> 16),uVar5,uVar7,uVar12,uVar13);
        bVar9 = CARRY2((uint)StshPtrs[0],uStack_c);
        (*(uint16_t *)((uint8_t *)&(StshPtrs[0]))) = (uint)StshPtrs[0] + uStack_c;
        (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) = (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) + uStack_a + (uint)bVar9;
        uStack_10 = nb_lo - uStack_c;
        uStack_e = (nb_hi - uStack_a) - (uint)(nb_lo < uStack_c);
        uVar10 = LXURSH_at_(CONCAT22(uStack_a,uStack_c),0x4);
        buf.seg = (int)uVar10 + buf.seg;
        buf.ofs = (uint16_t)((int)buf.ofs + (uStack_c & 0xf));
      }
      if (uStack_10 != 0 || uStack_e != 0) {
        uVar5 = (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
                (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle);
        if (((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) <= uVar5) &&
           (((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) < uVar5 ||
            ((uint)StshPtrs[0] < (uint)FMXmsHandle + (uint)FMEmsHandle)))) {
          uVar5 = (((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
                   (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)) - (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
                  (uint)((uint)FMXmsHandle + (uint)FMEmsHandle < (uint)StshPtrs[0]);
          if ((uVar5 < uStack_e) ||
             ((uVar5 <= uStack_e &&
              (((uint)FMXmsHandle + (uint)FMEmsHandle) - (uint)StshPtrs[0] <= uStack_10)))) {
            uStack_c = ((uint)FMXmsHandle + (uint)FMEmsHandle) - (uint)StshPtrs[0];
            uStack_a = (((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
                        (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)) - (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
                       (uint)((uint)FMXmsHandle + (uint)FMEmsHandle < (uint)StshPtrs[0]);
          }
          else {
            uStack_a = uStack_e;
            uStack_c = uStack_10;
          }
          iVar8 = (uint)StshPtrs[0] - (uint)FMXmsHandle;
          iVar4 = ((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) - (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2))) -
                  (uint)((uint)StshPtrs[0] < (uint)FMXmsHandle);
          uVar5 = uStack_c;
          uVar7 = uStack_a;
          uVar10 = ovr_mkp((uint16_t)buf.ofs,buf.seg);
          ems_memmove1((undefined2)uVar10,(undefined2)(uVar10 >> 16),iVar8,iVar4,uVar5,uVar7);
          bVar9 = CARRY2((uint)StshPtrs[0],uStack_c);
          (*(uint16_t *)((uint8_t *)&(StshPtrs[0]))) = (uint)StshPtrs[0] + uStack_c;
          (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) = (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) + uStack_a + (uint)bVar9;
          bVar9 = uStack_10 < uStack_c;
          uStack_10 = uStack_10 - uStack_c;
          uStack_e = (uStack_e - uStack_a) - (uint)bVar9;
          uVar10 = LXURSH_at_(CONCAT22(uStack_a,uStack_c),0x4);
          buf.seg = (int)uVar10 + buf.seg;
          buf.ofs = (uint16_t)((int)buf.ofs + (uStack_c & 0xf));
        }
      }
      uVar5 = (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
              (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle);
      if ((uVar5 <= (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) &&
         ((uVar5 != (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) ||
          ((uint)FMXmsHandle + (uint)FMEmsHandle <= (uint)StshPtrs[0])))) {
        lseek(StshHandles[0],CONCAT22((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)),(uint)StshPtrs[0]),0);
      }
      if (uStack_10 == 0 && uStack_e == 0) {
        return (cVar6 - (char)nb_hi) - (uVar3 < nb_lo);
      }
    }
    iVar4 = *(int *)((char *)"toymaker" + 7 + file_id * 2);
    pvVar11 = (void *)CONCAT22(buf.seg,buf.ofs);
    while( true ) {
      uStack_14 = (uint16_t)((ulong)pvVar11 >> 0x10);
      pvStack_16 = (void *)pvVar11;
      if ((uStack_e == 0) && (uStack_10 == 0)) goto next_iteration;
      if ((uStack_e != 0) || (uVar5 = uStack_10, 0xc000 < uStack_10)) {
        uVar5 = 0xc000;
      }
      uVar7 = read(iVar4,pvStack_16,uVar5);
      if (uVar7 != uVar5) break;
      bVar9 = uStack_10 < uVar7;
      uStack_10 = uStack_10 - uVar7;
      uStack_e = uStack_e - bVar9;
      pvVar11 = (void *)ovr_mkp((int)pvStack_16 + uVar7,uStack_14);
      puVar1 = (uint *)((int)&AgntAnms[0x53].y + 1 + file_id * 4);
      uVar5 = *puVar1;
      *puVar1 = *puVar1 + uVar7;
      piVar2 = (int *)((int)&AgntAnms[0x53].field_0x10 + file_id * 4);
      *piVar2 = *piVar2 + (uint)CARRY2(uVar5,uVar7);
    }
    printf("File read error %s \r",*(undefined2 *)(file_id * 4));
    ovr_biosReadKey();
next_iteration:
    cVar6 = (cVar6 - (char)nb_hi) - (uVar3 < nb_lo);
  }
  return cVar6;
}




/* 474a:0470 */

/* WARNING: Removing unreachable block (ram,0x000479f8) */
/* WARNING: Removing unreachable block (ram,0x00047a97) */
/* WARNING: Removing unreachable block (ram,0x00047a74) */

void __cdecl16far stshInit(void)

{
  ulong uVar1;
  uint32_t uVar2;
  int hande;
  int file_id;
  long flen;
  undefined2 szlo;
  undefined2 szhi;
  
  _fmemset(StshHandles,0xffff,0x440);
  _fmemset(StshBytes,0,0x220);
  for (file_id = 0; file_id < 0x220; file_id = file_id + 1) {
    hande = open_wait_unlock_and_disk((char *)*(undefined2 *)(file_id * 4));
    if (hande < 0) {
      flen = 0;
    }
    else {
      flen = filelength(hande);
      close(hande);
    }
    szhi = (undefined2)((ulong)flen >> 0x10);
    szlo = (undefined2)flen;
    *(undefined2 *)(file_id * 4 + 0xaa2) = szhi;
    *(undefined2 *)(file_id * 4 + 0xaa0) = szlo;
    *(undefined2 *)((int)(long *)StshPtrs + file_id * 4 + 2) = 0;
    *(undefined2 *)((long *)StshPtrs + file_id) = 0;
  }
  FMXmsHandle = xms_init();
  FMEmsHandle = ems_init();
  uVar1 = FMXmsHandle;
  if (FMXmsHandle != 0) {
    if (CONCAT22((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)),(uint)StshSizes[0]) < FMXmsHandle) {
      xms_1000_0472(CONCAT22((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)),(uint)StshSizes[0]));
      FMXmsHandle = CONCAT22((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)),(uint)StshSizes[0]);
    }
    fmReadIntoHimem((char *)StshNames[0],(*(uint16_t *)((uint8_t *)&(StshNames[0]) + 2)),0,0,0,(uint)FMXmsHandle,(int)(FMXmsHandle >> 0x10));
    uVar1 = FMXmsHandle;
  }
  (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) = (int)(uVar1 >> 0x10);
  (*(uint16_t *)((uint8_t *)&(FMXmsHandle))) = (uint)uVar1;
  FMXmsHandle = uVar1;
  if ((FMEmsHandle == 0) || (CONCAT22((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)),(uint)StshSizes[0]) <= uVar1)) {
    if (FMEmsHandle != 0) {
      ems_realloc(0);
    }
    uVar1 = FMXmsHandle;
    uVar2 = 0;
  }
  else {
    if (CONCAT22((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)),(uint)StshSizes[0]) < FMEmsHandle + uVar1) {
      (*(uint16_t *)((uint8_t *)&(FMEmsHandle))) = (uint)StshSizes[0] - (uint)FMXmsHandle;
      (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) =
           ((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)) - (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2))) - (uint)((uint)StshSizes[0] < (uint)FMXmsHandle)
      ;
      ems_realloc(CONCAT22((*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)),(int)FMEmsHandle));
      uVar1 = FMXmsHandle;
    }
    FMXmsHandle = uVar1;
    fmReadIntoHimem((char *)StshNames[0],(*(uint16_t *)((uint8_t *)&(StshNames[0]) + 2)),uVar1,1,0,(int)FMEmsHandle,
                    (int)(FMEmsHandle >> 0x10));
    uVar1 = FMXmsHandle;
    uVar2 = FMEmsHandle;
  }
  (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) = (int)(uVar2 >> 0x10);
  (*(uint16_t *)((uint8_t *)&(FMEmsHandle))) = (int)uVar2;
  (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) = (int)(uVar1 >> 0x10);
  (*(uint16_t *)((uint8_t *)&(FMXmsHandle))) = (uint)uVar1;
  return;
}



/* 474a:067b */

void __cdecl16far stshSeek(uint16_t fid,long ofs)

{
  uint uVar1;
  uint in_stack_00000006;
  
  if (fid == 0) {
    uVar1 = (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) +
            (uint)CARRY2((uint)FMEmsHandle,(uint)FMXmsHandle);
    if ((uVar1 <= (uint)ofs) &&
       ((uVar1 != (uint)ofs || ((uint)FMEmsHandle + (uint)FMXmsHandle <= in_stack_00000006)))) {
      lseek(StshHandles[0],CONCAT22((uint)ofs,in_stack_00000006),0);
    }
  }
  else {
    lseek(*(int *)((char *)"toymaker" + 7 + fid * 2),CONCAT22((uint)ofs,in_stack_00000006),0);
  }
  *(uint *)((int)&AgntAnms[0x53].field_0x10 + fid * 4) = (uint)ofs;
  *(uint *)((int)&AgntAnms[0x53].y + 1 + fid * 4) = in_stack_00000006;
  return;
}



/* 474a:06fe */

uint32_t __cdecl16far stshTell(uint16_t file_id)

{
  return CONCAT22(*(undefined2 *)((int)&AgntAnms[0x53].field_0x10 + file_id * 4),
                  *(undefined2 *)((int)&AgntAnms[0x53].y + 1 + file_id * 4));
}



/* 474a:0718 */

void __cdecl16far stshFree(far_t handle)

{
  if ((handle.seg != StshBuf.seg) || (handle.ofs != StshBuf.ofs)) {
    if (HeapReady == '\0') {
      farfree(handle.ofs,handle.seg);
    }
    else {
      ovr_heapFree(handle);
    }
  }
  return;
}



/* 474a:075a */

void * __cdecl16far stshAlloc(uint32_t nbytes)

{
  far_t fVar1;
  char cVar2;
  far_t r;
  undefined2 ofs;
  
  if (nbytes == 0xfa0f) {
    r = StshBuf;
    fVar1 = StshBuf;
    if (StshBuf.ofs == 0 && StshBuf.seg == 0) {
      r = farmalloc(0xfa0f);
      fVar1 = r;
    }
  }
  else {
    ovr_fmFreeAudio(0);
    if (nbytes == 0) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x1c);
    }
    do {
      if (HeapReady == '\0') {
        r = farmalloc(nbytes);
      }
      else {
        r = far_from_u32((uint32_t)(ovr_heapAlloc(nbytes)));
      }
      ofs = r.ofs;
      if (far_to_u32(r) == 0) {
        cVar2 = fmOutOfMemory(nbytes);
        fVar1.seg = StshBuf.seg;
        fVar1.ofs = StshBuf.ofs;
        if (cVar2 == '\0') {
          r.ofs = 0;
          r.seg = 0;
          goto end;
        }
      }
    } while (far_to_u32(r) == 0);
    r = far_from_u32((uint32_t)(ovr_mkp(ofs,r.seg)));
    fVar1.seg = StshBuf.seg;
    fVar1.ofs = StshBuf.ofs;
  }
end:
  StshBuf.seg = fVar1.seg;
  StshBuf.ofs = fVar1.ofs;
  return (void *)MK_FP(r.seg, r.ofs);
}



/* 474a:0822 */

uint8_t * __cdecl16far stshRealloc(uint32_t oldblock,uint32_t nbytes)

{
  uint8_t uVar1;
  char cVar2;
  undefined1 extraout_AH;
  undefined2 in_DX;
  uint8_t *r;
  
  if (oldblock == 0) {
    r = stshAlloc(nbytes);
  }
  else {
    ovr_fmFreeAudio(0);
    if (nbytes == 0) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0x13);
    }
    do {
      if (HeapReady == '\0') {
        uVar1 = farrealloc(oldblock,nbytes);
        r = (uint8_t *)CONCAT22(in_DX,(uint8_t *)CONCAT11(extraout_AH,uVar1));
      }
      else {
        r = (uint8_t *)ovr_heapRealloc(oldblock,nbytes);
        in_DX = (undefined2)((uint32_t)r >> 0x10);
      }
      if ((r == (uint8_t *)0x0) && (cVar2 = fmOutOfMemory(nbytes), cVar2 == '\0')) {
        return (uint8_t *)0x0;
      }
    } while (r == (uint8_t *)0x0);
  }
  return r;
}



/* 474a:08d1 */

far_t __cdecl16far fmMalloc(uint32_t nbytes)

{
  char cVar1;
  far_t fVar2;
  
  ovr_fmFreeAudio(0);
  if (nbytes == 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x1c);
  }
  while( true ) {
    if (HeapReady == '\0') {
      fVar2 = farmalloc(nbytes);
    }
    else {
      fVar2 = far_from_u32((uint32_t)ovr_heapMalloc(nbytes));
    }
    if ((far_to_u32(fVar2) == 0) && (cVar1 = fmMallocRecover(), cVar1 == '\0')) break;
    if (far_to_u32(fVar2) != 0) {
      return fVar2;
    }
  }
  fVar2.ofs = 0;
  fVar2.seg = 0;
  return fVar2;
}



/* 474a:0953 */

/* vsprintfs string into a ring buffer */

char * __cdecl16far fmVsprintf(char *fmt,char *arg)

{
  uint16_t uVar1;
  undefined2 uVar2;
  uint uVar3;
  uint8_t *puVar4;
  char *src;
  char local_d0 [200];
  int iStack_8;
  char **ppcStack_6;
  
  FMRingIndex = FMRingIndex + 1 & 7;
  ppcStack_6 = &arg;
  iStack_8 = vsprintf(local_d0,fmt,(char *)ppcStack_6);
  src = local_d0;
  puVar4 = stshRealloc(CONCAT22(*(undefined2 *)((int)&FMRingBuf[0].seg + (uint)FMRingIndex * 4),
                                ((far_t *)FMRingBuf + FMRingIndex)->ofs),(long)(iStack_8 + 1));
  uVar2 = (undefined2)((ulong)puVar4 >> 0x10);
                    /* Copy sprintfed string to dst */
  uVar1 = (uint16_t)_fstrcpy((char far *)puVar4,(char far *)src);
  uVar3 = (uint)FMRingIndex;
  *(undefined2 *)((int)&FMRingBuf[0].seg + uVar3 * 4) = uVar2;
  ((far_t *)FMRingBuf + uVar3)->ofs = uVar1;
  return (char *)((far_t *)FMRingBuf + FMRingIndex)->ofs;
}



/* 474a:09df */

char * __cdecl16far stsprintf(char *buf,char *fmt,char *arg1)

{
  undefined2 in_stack_00000006;
  
  vsprintf(buf,(char *)fmt,(char *)&arg1);
  return (char *)CONCAT22(in_stack_00000006,buf);
}



/* 474a:0a10 */

void __cdecl16far clean_ring_buffer(void)

{
  far_t handle;
  byte i;
  
  for (i = 0; i < 8; i = i + 1) {
    if (((far_t *)FMRingBuf + i)->ofs != 0 || *(int *)((int)&FMRingBuf[0].seg + (uint)i * 4) != 0) {
      handle.seg = *(uint16_t *)((int)&FMRingBuf[0].seg + (uint)i * 4);
      handle.ofs = ((far_t *)FMRingBuf + i)->ofs;
      stshFree(handle);
    }
    *(undefined2 *)((int)&FMRingBuf[0].seg + (uint)i * 4) = 0;
    ((far_t *)FMRingBuf + i)->ofs = 0;
  }
  return;
}



/* 474a:0a6a */

void __cdecl16far initStshTables(void)

{
  int i;
  
  _fmemset(StshBytes,0,0x220);
  for (i = 0; i < 0x220; i = i + 1) {
    *(undefined2 *)(i * 4 + 0xaa2) = 0x7fff;
    *(undefined2 *)(i * 4 + 0xaa0) = 0xffff;
  }
  return;
}



/* 474a:0aa7 */

uint32_t __cdecl16far stshFilesize(uint16_t file_id)

{
  int hande;
  long lVar1;
  
  if ((*(int *)(file_id * 4 + 0xaa2) == 0x7fff) && (*(int *)(file_id * 4 + 0xaa0) == -1)) {
    hande = open_wait_unlock_and_disk((char *)*(undefined2 *)(file_id * 4));
    lVar1 = filelength(hande);
    *(undefined2 *)(file_id * 4 + 0xaa2) = (int)((ulong)lVar1 >> 0x10);
    *(undefined2 *)(file_id * 4 + 0xaa0) = (int)lVar1;
    close(hande);
  }
  return CONCAT22(*(undefined2 *)(file_id * 4 + 0xaa2),*(undefined2 *)(file_id * 4 + 0xaa0));
}



/* 474a:0b26 */

uint16_t __cdecl16far randBelow(uint16_t n)

{
  byte rnd;
  
  rnd = rand8();
  return rnd * n >> 8;
}



/* 474a:0b38 */

int __cdecl16far creat_wait_unlock_and_disk(char *path)

{
  int handle;
  uint16_t ioerr;
  
  do {
    ioErrorHndlrInstall();
    handle = _creat(path,0);
    ioerr = ioErrorHndlrUninstall();
    if (handle != -1) {
      return handle;
    }
  } while ((ioerr == 0x20) || (ioerr == 0x37));
  return -1;
}



/* 474a:0b70 */

int __cdecl16far open_wait_unlock_and_disk(char *filename)

{
  int handle;
  uint16_t ioerr;
  
  do {
    ioErrorHndlrInstall();
    handle = _open(filename,0x41);
    ioerr = ioErrorHndlrUninstall();
    if (handle != -1) {
      return handle;
    }
  } while ((ioerr == 0x20) || (ioerr == 0x37));
  return -1;
}



/* 474a:0ba8 */

/* WARNING: Removing unreachable block (ram,0x000480c6) */
/* WARNING: Removing unreachable block (ram,0x000480ad) */
/* WARNING: Removing unreachable block (ram,0x00048108) */

void __cdecl16far
fmReadIntoHimem(char *param_1,undefined2 param_2,int param_3,int param_4,char param_5,
               undefined2 param_6,undefined2 param_7)

{
  int hande;
  uint uVar1;
  bool bVar2;
  ulong nbytes;
  far_t handle;
  uint uStack_e;
  int iStack_c;
  uint uStack_a;
  int iStack_8;
  void *pvStack_6;
  
  hande = open_wait_unlock_and_disk(param_1);
  if (-1 < hande) {
    nbytes = filelength(hande);
    if (param_3 != 0 || param_4 != 0) {
      lseek(hande,CONCAT22(param_4,param_3),0);
      nbytes = nbytes - CONCAT22(param_4,param_3);
    }
    if (CONCAT22(param_7,param_6) < nbytes) {
      nbytes = CONCAT22(param_7,param_6);
    }
    if ((long)nbytes < 0xc001) {
      handle = far_from_u32((uint32_t)(stshAlloc(nbytes)));
    }
    else {
      handle = far_from_u32((uint32_t)(stshAlloc(0xc000)));
    }
    iStack_c = 0;
    uStack_e = 0;
    while( true ) {
      pvStack_6 = (void *)handle.ofs;
      iStack_8 = (int)(nbytes >> 0x10);
      uStack_a = (uint)nbytes;
      if (nbytes == 0) break;
      uVar1 = uStack_a;
      if (0xc000 < (long)nbytes) {
        uVar1 = 0xc000;
      }
      uVar1 = read(hande,pvStack_6,uVar1);
      if ((uVar1 == 0) || (uVar1 == 0xffff)) break;
      if (param_5 == '\0') {
        xms_1000_03c2(uStack_e,iStack_c,handle.ofs,handle.seg,uVar1,0);
      }
      else {
        ems_memmove2(uStack_e,iStack_c,handle.ofs,handle.seg,uVar1,0);
      }
      bVar2 = CARRY2(uStack_e,uVar1);
      uStack_e = uStack_e + uVar1;
      iStack_c = iStack_c + (uint)bVar2;
      nbytes = CONCAT22(iStack_8 - (uint)(uStack_a < uVar1),uStack_a - uVar1);
    }
    close(hande);
    stshFree(handle);
  }
  return;
}



/* 474a:0cf8 */

stg_tmp_t * __cdecl16far stshLoadGfx(far_t handle)

{
  int iVar1;
  uint16_t uVar2;
  uint16_t uVar3;
  far_t fVar5;
  far_t fVar6;
  int in_stack_0000fff6;
  char *pcVar4;
  
  fVar5 = far_from_u32((uint32_t)(ovr_mkp(handle.ofs,handle.seg)));
  pcVar4 = (char *)fVar5.ofs;
  handle.seg = fVar5.seg;
  if (*(char *)MK_FP(fVar5.seg, fVar5.ofs) == '\0') {
    fVar6 = far_from_u32((uint32_t)(ovr_mkp(Stsh_2410_47f6.ofs,Stsh_2410_47f6.seg)));
    if (far_to_u32(fVar6) != far_to_u32(fVar5)) {
      iVar1 = *(int *)(pcVar4 + 0xf);
      in_stack_0000fff6 = *(int *)(pcVar4 + 0xd);
      uVar2 = *(uint16_t *)(pcVar4 + 0xb);
      uVar3 = *(uint16_t *)(pcVar4 + 9);
      if (uVar3 != 0 || uVar2 != 0) {
        *(int *)(uVar3 + 0xf) = iVar1;
        *(int *)(uVar3 + 0xd) = in_stack_0000fff6;
      }
      if (in_stack_0000fff6 != 0 || iVar1 != 0) {
        *(uint16_t *)(in_stack_0000fff6 + 0xb) = uVar2;
        *(uint16_t *)(in_stack_0000fff6 + 9) = uVar3;
        uVar3 = StshCtPtr2.ofs;
        uVar2 = StshCtPtr2.seg;
      }
      StshCtPtr2.seg = uVar2;
      StshCtPtr2.ofs = uVar3;
      uVar2 = Stsh_2410_47f6.ofs;
      *(uint16_t *)(pcVar4 + 0xf) = Stsh_2410_47f6.seg;
      *(uint16_t *)(pcVar4 + 0xd) = uVar2;
      (pcVar4 + 0xb)[0] = '\0';
      (pcVar4 + 0xb)[1] = '\0';
      (pcVar4 + 9)[0] = '\0';
      (pcVar4 + 9)[1] = '\0';
      *(uint16_t *)(Stsh_2410_47f6.ofs + 0xb) = handle.seg;
      *(undefined2 *)(Stsh_2410_47f6.ofs + 9) = (uint16_t)pcVar4;
      Stsh_2410_47f6 = fVar5;
    }
    if (*(int *)(pcVar4 + 0x11) == 0 && *(int *)(pcVar4 + 0x13) == 0) {
      fVar5 = fmMalloc(CONCAT22(*(undefined2 *)(pcVar4 + 7),*(undefined2 *)(pcVar4 + 5)));
      *(uint16_t *)(pcVar4 + 0x13) = fVar5.seg;
      *(uint16_t *)(pcVar4 + 0x11) = fVar5.ofs;
      if (*(int *)(pcVar4 + 0x11) == 0 && *(int *)(pcVar4 + 0x13) == 0) {
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0x47);
      }
      stshSeek(StshStrongDatHnd,CONCAT22(in_stack_0000fff6,*(undefined2 *)(pcVar4 + 3)));
      fVar6.seg = *(uint16_t *)(pcVar4 + 0x13);
      fVar6.ofs = *(uint16_t *)(pcVar4 + 0x11);
      stshRead(StshStrongDatHnd,fVar6,
               CONCAT22(*(undefined2 *)(pcVar4 + 7),*(undefined2 *)(pcVar4 + 5)));
    }
    fVar5.seg = *(uint16_t *)(pcVar4 + 0x13);
    fVar5.ofs = (uint16_t)*(char **)(pcVar4 + 0x11);
  }
  return (stg_tmp_t *)MK_FP(fVar5.seg, fVar5.ofs);
}



/* 474a:0e9b */

uint8_t * __cdecl16far stash_474a_0e9b(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  uint16_t uVar3;
  uint16_t uVar4;
  bool bVar5;
  uint8_t *puVar6;
  uint8_t *src;
  far_t fVar7;
  far_t fVar8;
  undefined1 in_stack_0000fff0;
  undefined1 in_stack_0000fff1;
  
  fVar7 = far_from_u32((uint32_t)(ovr_mkp((uint16_t)param_1,(*(uint16_t *)((uint8_t *)&(param_1) + 2)))));
  puVar6 = (uint8_t *)fVar7.ofs;
  (*(uint16_t *)((uint8_t *)&(param_1) + 2)) = fVar7.seg;
  src = puVar6;
  if (*(char *)MK_FP(fVar7.seg, fVar7.ofs) == '\0') {
    fVar8 = fmMalloc(CONCAT22(*(undefined2 *)(puVar6 + 7),*(undefined2 *)(puVar6 + 5)));
    src = (uint8_t *)fVar8.ofs;
    if (far_to_u32(fVar8) == 0) {
      src = (uint8_t *)0x0;
    }
    else {
      if (*(int *)(puVar6 + 0x11) == 0 && *(int *)(puVar6 + 0x13) == 0) {
        stshSeek(StshStrongDatHnd,
                 CONCAT13(in_stack_0000fff1,CONCAT12(in_stack_0000fff0,*(undefined2 *)(puVar6 + 3)))
                );
        stshRead(StshStrongDatHnd,fVar8,
                 CONCAT22(*(undefined2 *)(puVar6 + 7),*(undefined2 *)(puVar6 + 5)));
        fVar8 = far_from_u32((uint32_t)ovr_heapMalloc(CONCAT22(*(undefined2 *)(puVar6 + 7),*(undefined2 *)(puVar6 + 5))));
        *(uint16_t *)(puVar6 + 0x13) = fVar8.seg;
        *(uint16_t *)(puVar6 + 0x11) = fVar8.ofs;
        if (*(int *)(puVar6 + 0x11) == 0 && *(int *)(puVar6 + 0x13) == 0) {
          bVar5 = false;
        }
        else {
          memcpy(*(uint8_t **)(puVar6 + 0x11),src,*(uint16_t *)(puVar6 + 5));
          bVar5 = true;
        }
      }
      else {
        memcpy(src,*(uint8_t **)(puVar6 + 0x11),*(uint16_t *)(puVar6 + 5));
        bVar5 = true;
      }
      if (bVar5) {
        fVar8 = far_from_u32((uint32_t)(ovr_mkp(Stsh_2410_47f6.ofs,Stsh_2410_47f6.seg)));
        if (far_to_u32(fVar8) != far_to_u32(fVar7)) {
          iVar1 = *(int *)(puVar6 + 0xf);
          iVar2 = *(int *)(puVar6 + 0xd);
          uVar3 = *(uint16_t *)(puVar6 + 0xb);
          uVar4 = *(uint16_t *)(puVar6 + 9);
          if (uVar4 != 0 || uVar3 != 0) {
            *(int *)(uVar4 + 0xf) = iVar1;
            *(int *)(uVar4 + 0xd) = iVar2;
          }
          if (iVar2 != 0 || iVar1 != 0) {
            *(uint16_t *)(iVar2 + 0xb) = uVar3;
            *(uint16_t *)(iVar2 + 9) = uVar4;
            uVar4 = StshCtPtr2.ofs;
            uVar3 = StshCtPtr2.seg;
          }
          StshCtPtr2.seg = uVar3;
          StshCtPtr2.ofs = uVar4;
          uVar3 = Stsh_2410_47f6.ofs;
          *(uint16_t *)(puVar6 + 0xf) = Stsh_2410_47f6.seg;
          *(uint16_t *)(puVar6 + 0xd) = uVar3;
          (puVar6 + 0xb)[0] = 0x0;
          (puVar6 + 0xb)[1] = 0x0;
          (puVar6 + 9)[0] = 0x0;
          (puVar6 + 9)[1] = 0x0;
          *(uint16_t *)(Stsh_2410_47f6.ofs + 0xb) = (*(uint16_t *)((uint8_t *)&(param_1) + 2));
          *(undefined2 *)(Stsh_2410_47f6.ofs + 9) = (uint16_t)puVar6;
          Stsh_2410_47f6 = fVar7;
        }
      }
    }
  }
  return src;
}



/* 474a:10ac */

stg_tmp_t * __cdecl16far stash_474a_10ac(stg_tmp_t *param_1,byte param_2)

{
  uint uVar1;
  stg_tmp_t *psVar2;
  far_t handle;
  
  if ((stg_tmp_t *)param_1 == (stg_tmp_t *)0x0 && (*(uint16_t *)((uint8_t *)&(param_1) + 2)) == 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0xb);
  }
  if (param_1->cmap[0] == 0x0) {
    handle.seg = (*(uint16_t *)((uint8_t *)&(param_1) + 2));
    handle.ofs = (uint16_t)(((stg_tmp_t *)param_1)->cmap + (uint)param_2 * 0x15);
    psVar2 = stshLoadGfx(handle);
    (*(uint16_t *)((uint8_t *)&(param_1))) = (uint16_t)psVar2;
  }
  else {
    uVar1 = 0;
    while( true ) {
      if (param_2 <= uVar1) break;
      if ((stg_tmp_t *)param_1 == (stg_tmp_t *)0x0 && (*(uint16_t *)((uint8_t *)&(param_1) + 2)) == 0) {
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0xb);
      }
      uVar1 = uVar1 + 1;
      param_1 = (stg_tmp_t *)
                CONCAT22(*(undefined2 *)(((stg_tmp_t *)param_1)->cmap + 3),
                         *(stg_tmp_t **)(((stg_tmp_t *)param_1)->cmap + 1));
    }
    if ((stg_tmp_t *)param_1 == (stg_tmp_t *)0x0 && (*(uint16_t *)((uint8_t *)&(param_1) + 2)) == 0) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0xb);
    }
  }
  return (stg_tmp_t *)param_1;
}



/* 474a:1133 */

void __cdecl16far fmRewindHeapPtr(void)

{
  uint16_t *puVar1;
  undefined2 uStack_6;
  undefined2 uStack_4;
  
  HeapPtr = 0xffff;
  uStack_4 = StshCtPtr2.seg;
  uStack_6 = StshCtPtr2.ofs;
  while (uStack_6 != 0 || uStack_4 != 0) {
    if ((*(int *)(uStack_6 + 0x11) != 0 || *(int *)(uStack_6 + 0x13) != 0) &&
       (*(uint *)(uStack_6 + 0x13) < HeapPtr)) {
      HeapPtr = *(uint *)(uStack_6 + 0x13);
    }
    puVar1 = (uint16_t *)(uStack_6 + 0xb);
    uStack_6 = *(uint16_t *)(uStack_6 + 9);
    uStack_4 = *puVar1;
  }
  return;
}



/* 474a:1196 */

undefined2 __cdecl16far fmMallocRecover(void)

{
  uint16_t *puVar1;
  int iVar2;
  bool bVar3;
  undefined2 uVar4;
  far_t handle;
  uint16_t uStack_6;
  uint16_t uStack_4;
  
  bVar3 = ovr_fmFreeAudio(0);
  if (bVar3) {
    uVar4 = 1;
  }
  else {
    uStack_4 = StshCtPtr2.seg;
    uStack_6 = StshCtPtr2.ofs;
    while (uStack_6 != 0 || uStack_4 != 0) {
      if (*(int *)(uStack_6 + 0x11) != 0 || *(int *)(uStack_6 + 0x13) != 0) {
        handle.seg = *(uint16_t *)(uStack_6 + 0x13);
        handle.ofs = *(uint16_t *)(uStack_6 + 0x11);
        stshFree(handle);
        iVar2 = *(int *)(uStack_6 + 0x13);
        *(undefined2 *)(uStack_6 + 0x13) = 0;
        *(undefined2 *)(uStack_6 + 0x11) = 0;
        if (HeapPtr == iVar2) {
          fmRewindHeapPtr();
        }
        return 1;
      }
      puVar1 = (uint16_t *)(uStack_6 + 0xb);
      uStack_6 = *(uint16_t *)(uStack_6 + 9);
      uStack_4 = *puVar1;
    }
    bVar3 = ovr_fmFreeAudio(1);
    if (bVar3) {
      uVar4 = 1;
    }
    else {
      if (DAT_2410_2a4e == '\0') {
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0x15);
      }
      uVar4 = 0;
    }
  }
  return uVar4;
}



/* 474a:1254 */

void __cdecl16far fmFree(void)

{
  uint16_t *puVar1;
  int iVar2;
  far_t handle;
  undefined2 uStack_6;
  undefined2 uStack_4;
  
  ovr_fmFreeAudio(1);
  uStack_4 = StshCtPtr2.seg;
  uStack_6 = StshCtPtr2.ofs;
  while (uStack_6 != 0 || uStack_4 != 0) {
    if (*(int *)(uStack_6 + 0x11) != 0 || *(int *)(uStack_6 + 0x13) != 0) {
      handle.seg = *(uint16_t *)(uStack_6 + 0x13);
      handle.ofs = *(uint16_t *)(uStack_6 + 0x11);
      stshFree(handle);
      iVar2 = *(int *)(uStack_6 + 0x13);
      *(undefined2 *)(uStack_6 + 0x13) = 0;
      *(undefined2 *)(uStack_6 + 0x11) = 0;
      if (HeapPtr == iVar2) {
        fmRewindHeapPtr();
      }
    }
    puVar1 = (uint16_t *)(uStack_6 + 0xb);
    uStack_6 = *(uint16_t *)(uStack_6 + 9);
    uStack_4 = *puVar1;
  }
  return;
}



/* 474a:12dc */

undefined2 __cdecl16far fmOutOfMemory(uint32_t nbytes)

{
  uint16_t *puVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined2 uVar7;
  long lVar8;
  far_t handle;
  far_t handle_00;
  uint16_t uStack_12;
  uint16_t uStack_10;
  uint uStack_a;
  uint16_t uStack_6;
  uint16_t uStack_4;
  
  bVar2 = ovr_fmFreeAudio(0);
  if (!bVar2) {
    lVar8 = LXRSH_at_(nbytes + 0x13,0x4);
    uVar3 = (uint)(lVar8 + (ulong)HeapPtr);
    iVar4 = (int)(lVar8 + (ulong)HeapPtr >> 0x10);
    uVar6 = uVar3;
    if (iVar4 != 0) {
      uVar6 = 0xffff;
    }
    if (((MUSHandle.ofs != 0 || MUSHandle.seg != 0) && ((iVar4 != 0 || (MUSHandle.seg < uVar3)))) ||
       ((DIGHandle.ofs != 0 || DIGHandle.seg != 0 && ((iVar4 != 0 || (MUSHandle.seg < uVar3)))))) {
      ovr_fmFreeAudio(1);
    }
    uStack_a = 0xffff;
    HeapPtr = 0xffff;
    bVar2 = false;
    uStack_4 = StshCtPtr2.seg;
    uStack_6 = StshCtPtr2.ofs;
    uVar3 = 0xffff;
    while (uStack_6 != 0 || uStack_4 != 0) {
      uVar5 = uVar3;
      if (*(int *)(uStack_6 + 0x11) != 0 || *(int *)(uStack_6 + 0x13) != 0) {
        if (*(uint *)(uStack_6 + 0x13) < uVar6) {
          handle.seg = *(uint16_t *)(uStack_6 + 0x13);
          handle.ofs = *(uint16_t *)(uStack_6 + 0x11);
          stshFree(handle);
          *(undefined2 *)(uStack_6 + 0x13) = 0;
          *(undefined2 *)(uStack_6 + 0x11) = 0;
          bVar2 = true;
        }
        else {
          if (*(uint *)(uStack_6 + 0x13) < uVar3) {
            uVar5 = *(uint *)(uStack_6 + 0x13);
            _uStack_12 = CONCAT22(uStack_4,uStack_6);
            uStack_a = uVar3;
          }
          if (*(uint *)(uStack_6 + 0x13) < HeapPtr) {
            HeapPtr = *(uint *)(uStack_6 + 0x13);
          }
        }
      }
      puVar1 = (uint16_t *)(uStack_6 + 0xb);
      uStack_6 = *(uint16_t *)(uStack_6 + 9);
      uVar3 = uVar5;
      uStack_4 = *puVar1;
    }
    if (!bVar2) {
      if (uVar3 == 0xffff) {
        bVar2 = ovr_fmFreeAudio(1);
        if (bVar2) {
          return 1;
        }
        if (DAT_2410_2a4e == '\0') {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x14);
        }
        return 0;
      }
      uVar7 = (undefined2)((ulong)_uStack_12 >> 0x10);
      iVar4 = (int)_uStack_12;
      handle_00.seg = *(uint16_t *)(iVar4 + 0x13);
      handle_00.ofs = *(uint16_t *)(iVar4 + 0x11);
      stshFree(handle_00);
      *(undefined2 *)(iVar4 + 0x13) = 0;
      *(undefined2 *)(iVar4 + 0x11) = 0;
      HeapPtr = uStack_a;
    }
  }
  return 1;
}


