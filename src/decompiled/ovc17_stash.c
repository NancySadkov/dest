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
  
  fh = open_wait_unlock_and_disk
                 ((char *)*(uint16_t *)(file_id * 4),((uint16_t *)(file_id * 4))[1]);
  ((int far *)StshHandles)[file_id] = fh;
  *(uint16_t *)((int)(long far *)StshPtrs + file_id * 4 + 2) = 0;
  *(uint16_t *)((long far *)StshPtrs + file_id) = 0;
  return file_id;
}



/* 474a:004e */

void __cdecl16far stshClose(uint16_t file_id)

{
  if (((int far *)StshHandles)[file_id] != -1) {
    close(((int far *)StshHandles)[file_id]);
  }
  ((int far *)StshHandles)[file_id] = -1;
  return;
}



/* 474a:008f */

/* WARNING: Variable defined which should be unmapped: pbuf */
/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* Returns number of remaining bytes */

uint __cdecl16far stshRead(void)

{
  uint *puVar1;
  int *piVar2;
  int fd;
  uint uVar3;
  uint16_t srcEmsOfsHi;
  uint32_t *puVar4;
  uint uVar5;
  uint16_t rdsz;
  uint16_t readed;
  uint uVar6;
  uint16_t seg;
  uint16_t unaff_SI;
  uint32_t *unaff_DI;
  bool bVar7;
  int in_stack_00000004;
  uint32_t *in_stack_00000006;
  uint32_t *in_stack_00000008;
  uint in_stack_0000000a;
  uint in_stack_0000000c;
  uint srcHi;
  uint countLo;
  uint16_t uVar8;
  uint16_t lenHi;
  uint32_t srcPtr;
  uint16_t pbuf;
  uint8_t in_stack_0000ffec;
  uint leftLo;
  uint leftHi;
  uint chunkLo;
  uint16_t chunkHi;
  
  uVar3 = in_stack_0000000a;
  srcPtr = CONCAT22(pbuf,unaff_SI);
  uVar5 = *(uint *)((int)(long far *)StshPtrs + in_stack_00000004 * 4 + 2);
  uVar6 = *(uint *)((uint8_t *)&StshSizes[in_stack_00000004] + 2);
  if ((uVar5 < uVar6) ||
     ((uVar5 == uVar6 &&
      (*(uint *)((long far *)StshPtrs + in_stack_00000004) < *(uint *)(&StshSizes[in_stack_00000004]))))
     ) {
    uVar6 = in_stack_0000000c + *(int *)((int)(long far *)StshPtrs + in_stack_00000004 * 4 + 2) +
            (uint)CARRY2(in_stack_0000000a,*(uint *)((long far *)StshPtrs + in_stack_00000004));
    uVar5 = *(uint *)((uint8_t *)&StshSizes[in_stack_00000004] + 2);
    if ((uVar5 <= uVar6) &&
       ((uVar5 < uVar6 ||
        (*(uint *)(&StshSizes[in_stack_00000004]) <
         in_stack_0000000a + *(uint *)((long far *)StshPtrs + in_stack_00000004))))) {
      uVar5 = *(uint *)(&StshSizes[in_stack_00000004]);
      puVar1 = (uint *)((int)&AgntAnms[0x53].y + 1 + in_stack_00000004 * 4);
      in_stack_0000000a = uVar5 - *puVar1;
      in_stack_0000000c =
           (*(int *)((uint8_t *)&StshSizes[in_stack_00000004] + 2) -
           *(int *)((int)&AgntAnms[0x53].maxDx + 1 + in_stack_00000004 * 4)) -
           (uint)(uVar5 < *puVar1);
    }
    leftHi = in_stack_0000000c;
    leftLo = in_stack_0000000a;
    if (in_stack_00000004 == 0) {
      if (((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) <= (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2))) &&
         (((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) < (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) || ((uint)StshPtrs[0] < (uint)FMXmsHandle)))) {
        uVar5 = ((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) - (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
                (uint)((uint)FMXmsHandle < (uint)StshPtrs[0]);
        if ((uVar5 < in_stack_0000000c) ||
           ((uVar5 <= in_stack_0000000c &&
            ((uint)FMXmsHandle - (uint)StshPtrs[0] <= in_stack_0000000a)))) {
          chunkLo = (uint)FMXmsHandle - (uint)StshPtrs[0];
          uVar5 = ((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) - (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
                  (uint)((uint)FMXmsHandle < (uint)StshPtrs[0]);
          chunkHi = uVar5;
        }
        else {
          chunkHi = in_stack_0000000c;
          chunkLo = in_stack_0000000a;
          uVar5 = in_stack_0000000a;
        }
        uVar6 = (uint)StshPtrs[0];
        srcHi = (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2));
        countLo = chunkLo;
        uVar8 = chunkHi;
        puVar4 = ovr_mkp(in_stack_00000006,(uint16_t)in_stack_00000008,(uint)StshPtrs[0]);
        xms_usesXmsHandle((int)puVar4,uVar5,uVar6,srcHi,countLo,uVar8);
        bVar7 = CARRY2((uint)StshPtrs[0],chunkLo);
        (*(uint16_t *)((uint8_t *)&(StshPtrs[0]))) = (uint)StshPtrs[0] + chunkLo;
        (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) = (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) + chunkHi + (uint)bVar7;
        leftLo = in_stack_0000000a - chunkLo;
        leftHi = (in_stack_0000000c - chunkHi) - (uint)(in_stack_0000000a < chunkLo);
        puVar4 = LXURSH_at_(unaff_DI,srcPtr,in_stack_0000ffec);
        in_stack_00000008 = (uint32_t *)((int)puVar4 + (int)in_stack_00000008);
        in_stack_00000006 = (uint32_t *)((int)in_stack_00000006 + (chunkLo & 0xf));
      }
      if (leftLo != 0 || leftHi != 0) {
        uVar5 = (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
                (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle);
        if (((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) <= uVar5) &&
           (((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) < uVar5 ||
            ((uint)StshPtrs[0] < (uint)FMXmsHandle + (uint)FMEmsHandle)))) {
          uVar5 = (((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
                   (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)) - (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
                  (uint)((uint)FMXmsHandle + (uint)FMEmsHandle < (uint)StshPtrs[0]);
          if ((uVar5 < leftHi) ||
             ((uVar5 <= leftHi &&
              (((uint)FMXmsHandle + (uint)FMEmsHandle) - (uint)StshPtrs[0] <= leftLo)))) {
            chunkLo = ((uint)FMXmsHandle + (uint)FMEmsHandle) - (uint)StshPtrs[0];
            chunkHi = (((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
                        (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle)) - (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
                       (uint)((uint)FMXmsHandle + (uint)FMEmsHandle < (uint)StshPtrs[0]);
          }
          else {
            chunkHi = leftHi;
            chunkLo = leftLo;
          }
          seg = (uint)StshPtrs[0] - (uint)FMXmsHandle;
          srcEmsOfsHi = ((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) - (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2))) -
                        (uint)((uint)StshPtrs[0] < (uint)FMXmsHandle);
          uVar8 = seg;
          uVar5 = chunkLo;
          lenHi = chunkHi;
          puVar4 = ovr_mkp(in_stack_00000006,(uint16_t)in_stack_00000008,seg);
          ems_memmove1((uint16_t)puVar4,seg,uVar8,srcEmsOfsHi,uVar5,lenHi);
          bVar7 = CARRY2((uint)StshPtrs[0],chunkLo);
          (*(uint16_t *)((uint8_t *)&(StshPtrs[0]))) = (uint)StshPtrs[0] + chunkLo;
          (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) = (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) + chunkHi + (uint)bVar7;
          bVar7 = leftLo < chunkLo;
          leftLo = leftLo - chunkLo;
          leftHi = (leftHi - chunkHi) - (uint)bVar7;
          puVar4 = LXURSH_at_(unaff_DI,srcPtr,in_stack_0000ffec);
          in_stack_00000008 = (uint32_t *)((int)puVar4 + (int)in_stack_00000008);
          in_stack_00000006 = (uint32_t *)((int)in_stack_00000006 + (chunkLo & 0xf));
        }
      }
      uVar5 = (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
              (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle);
      if ((uVar5 <= (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) &&
         ((uVar5 != (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) ||
          ((uint)FMXmsHandle + (uint)FMEmsHandle <= (uint)StshPtrs[0])))) {
        lseek(StshHandles[0],(ulong)(*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)),(int)unaff_DI);
      }
      if (leftLo == 0 && leftHi == 0) {
        return uVar3 - in_stack_0000000a;
      }
    }
    fd = *(int *)((char *)0x2420 + in_stack_00000004 * 2);
    pbuf = (uint16_t)in_stack_00000006;
    while( true ) {
      if ((leftHi == 0) && (leftLo == 0)) goto next_iteration;
      if ((leftHi != 0) || (rdsz = leftLo, 0xc000 < leftLo)) {
        rdsz = 0xc000;
      }
      readed = read(fd,(uint32_t *)CONCAT22(rdsz,in_stack_00000008),(uint)unaff_DI);
      if (readed != rdsz) break;
      bVar7 = leftLo < readed;
      leftLo = leftLo - readed;
      leftHi = leftHi - bVar7;
      pbuf = (uint16_t)
             ovr_mkp((uint32_t *)(pbuf + readed),(uint16_t)in_stack_00000008,(uint16_t)unaff_DI);
      puVar1 = (uint *)((int)&AgntAnms[0x53].y + 1 + in_stack_00000004 * 4);
      uVar5 = *puVar1;
      *puVar1 = *puVar1 + readed;
      piVar2 = (int *)((int)&AgntAnms[0x53].maxDx + 1 + in_stack_00000004 * 4);
      *piVar2 = *piVar2 + (uint)CARRY2(uVar5,readed);
      in_stack_00000008 = in_stack_00000006;
    }
    printf((char *)((long)&BldInstances[0x49].seg + 1));
    ovr_biosReadKey();
next_iteration:
    in_stack_0000000a = uVar3 - in_stack_0000000a;
  }
  return in_stack_0000000a;
}



/* 474a:0470 */
void __cdecl16far stshInit(void)

{
  long *retStorage;
  uint uVar1;
  uint16_t file_id;
  uint32_t *unaff_DI;
  uint32_t flen;
  uint16_t szlo;
  uint16_t szhi;
  
  _fmemset(MK_FP(0x1ef4, 0x2420), 0xFFFF, 0x440);
  _fmemset(MK_FP(0x1ef4, 0x0880), 0, 0x220);
  for (file_id = 0; (int)file_id < 0x220; file_id = file_id + 1) {
    retStorage =
         (long *)open_wait_unlock_and_disk
                           ((char *)*(uint16_t *)(file_id * 4),((uint16_t *)(file_id * 4))[1]);
    if ((int)retStorage < 0) {
      szhi = 0;
      szlo = 0;
    }
    else {
      (*(uint16_t *)((uint8_t *)&(flen))) =(uint16_t) filelength(retStorage,(int)unaff_DI);
      close((int)retStorage);
      szlo = (uint16_t)(long *)flen;
      szhi = (*(uint16_t *)((uint8_t *)&(flen) + 2));
    }
    *(uint16_t *)((uint8_t *)&StshSizes[file_id] + 2) = szhi;
    *(uint16_t *)(&StshSizes[file_id]) = szlo;
    *(uint16_t *)((int)(long far *)StshPtrs + file_id * 4 + 2) = 0;
    *(uint16_t *)((long far *)StshPtrs + file_id) = 0;
    (*(uint16_t *)((uint8_t *)&(flen) + 2)) = szhi;
  }
  (*(uint16_t *)((uint8_t *)&(FMXmsHandle))) =(uint16_t) xms_init(unaff_DI);
  (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) = (*(uint16_t *)((uint8_t *)&(flen) + 2));
  (*(uint16_t *)((uint8_t *)&(FMEmsHandle))) =(uint16_t) ems_init(unaff_DI);
  (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) = (*(uint16_t *)((uint8_t *)&(flen) + 2));
  if ((uint32_t *)FMXmsHandle != (uint32_t *)0x0 || (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) != 0) {
    if (((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)) <= (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2))) &&
       (((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)) < (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) ||
        ((uint32_t far *)StshSizes[0] < (uint32_t *)FMXmsHandle)))) {
      stshInit_scan((uint32_t)CONCAT22((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)),(uint32_t far *)StshSizes[0]));
      (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) = (*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2));
      (*(uint16_t *)((uint8_t *)&(FMXmsHandle))) =(uint16_t) (uint32_t far *)StshSizes[0];
    }
    fmReadIntoHimem((char *)StshNames[0],(*(uint16_t *)((uint8_t *)&(StshNames[0]) + 2)),0,0,'\0',
                    (uint16_t)(uint32_t *)FMXmsHandle,(*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)),0);
  }
  if ((((uint32_t *)FMEmsHandle == (uint32_t *)0x0 && (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) == 0) ||
      ((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)) < (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)))) ||
     (((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)) <= (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) &&
      ((uint32_t far *)StshSizes[0] <= (uint32_t *)FMXmsHandle)))) {
    if ((uint32_t *)FMEmsHandle != (uint32_t *)0x0 || (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) != 0) {
      ems_realloc(0);
    }
    (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) = 0;
    (*(uint16_t *)((uint8_t *)&(FMEmsHandle))) =(uint16_t) (uint32_t *)0x0;
  }
  else {
    uVar1 = (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
            (uint)CARRY2((uint)(uint32_t *)FMXmsHandle,(uint)(uint32_t *)FMEmsHandle);
    if (((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)) <= uVar1) &&
       (((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)) < uVar1 ||
        ((uint32_t far *)StshSizes[0] <
         (uint32_t *)((int)(uint32_t *)FMXmsHandle + (int)(uint32_t *)FMEmsHandle))))) {
      (*(uint16_t *)((uint8_t *)&(FMEmsHandle))) = (uint16_t)((uint32_t *)((int)(uint32_t far *)StshSizes[0] - (int)(uint32_t *)FMXmsHandle))
      ;
      (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) =
           ((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)) - (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2))) -
           (uint)((uint32_t far *)StshSizes[0] < (uint32_t *)FMXmsHandle);
      ems_realloc((uint32_t)CONCAT22((*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)),(uint32_t *)FMEmsHandle));
    }
    fmReadIntoHimem((char *)StshNames[0],(*(uint16_t *)((uint8_t *)&(StshNames[0]) + 2)),(int)(uint32_t *)FMXmsHandle,
                    (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)),'\x01',(uint16_t)(uint32_t *)FMEmsHandle,(*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)),1);
  }
  return;
}


/* 474a:067b */

/* WARNING: Removing unreachable block (ram,0x00047b3c) */

void __cdecl16far stshSeek(uint16_t fid,long ofs)

{
  int unaff_SI;
  
  if (fid == 0) {
    if (CONCAT22((*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) +
                 (uint)CARRY2((uint)FMEmsHandle,(uint)FMXmsHandle),
                 (uint)FMEmsHandle + (uint)FMXmsHandle) <= (ulong)ofs) {
      lseek(StshHandles[0],(ulong)(*(uint16_t *)((uint8_t *)&(ofs) + 2)),unaff_SI);
    }
  }
  else {
    lseek(*(int *)((char *)0x2420 + fid * 2),(ulong)(*(uint16_t *)((uint8_t *)&(ofs) + 2)),unaff_SI);
  }
  *(uint *)((int)&AgntAnms[0x53].maxDx + 1 + fid * 4) = (*(uint16_t *)((uint8_t *)&(ofs) + 2));
  *(uint16_t *)((int)&AgntAnms[0x53].y + 1 + fid * 4) = (uint16_t)ofs;
  return;
}



/* 474a:06fe */

uint32_t * __cdecl16far stshTell(uint32_t *retStorage,uint16_t file_id)

{
  return (uint32_t *)*(uint16_t *)((int)&AgntAnms[0x53].y + 1 + (int)retStorage * 4);
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
  uint uVar1;
  uint16_t ofs_00;
  uint32_t r;
  uint16_t ofs;
  uint16_t seg;
  
  if (nbytes == 0xfa0f) {
    (*(uint16_t *)((uint8_t *)&(r))) =(uint16_t) (far_t far *)StshBuf.ofs;
    if (StshBuf.ofs == 0 && StshBuf.seg == 0) {
      (*(uint16_t *)((uint8_t *)&(r))) =(uint16_t) farmalloc((far_t *)0xfa0f,(ulong)ofs << 0x10);
      StshBuf.ofs = (uint16_t)(far_t far *)r;
      StshBuf.seg = (*(uint16_t *)((uint8_t *)&(r) + 2));
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
        ofs = (uint16_t)farmalloc((far_t *)nbytes,CONCAT22(ofs,(*(uint16_t *)((uint8_t *)&(nbytes) + 2))));
        ofs_00 = (*(uint16_t *)((uint8_t *)&(r) + 2));
      }
      else {
        ofs = (uint16_t)ovr_heapAlloc((uint32_t *)(far_t far *)nbytes,CONCAT22(ofs,(*(uint16_t *)((uint8_t *)&(nbytes) + 2))));
        ofs_00 = (*(uint16_t *)((uint8_t *)&(r) + 2));
      }
      (*(uint16_t *)((uint8_t *)&(r) + 2)) = ofs_00;
      if ((ofs == 0 && ofs_00 == 0) && (uVar1 = fmOutOfMemory(nbytes), (uVar1 & 0xff) == 0)) {
        return (void *)0x0;
      }
    } while (ofs == 0 && ofs_00 == 0);
    (*(uint16_t *)((uint8_t *)&(r))) =(uint16_t) (far_t far *)ovr_mkp((uint32_t *)ofs,ofs_00,ofs);
  }
  return (far_t far *)r;
}


/* 474a:0822 */
uint8_t * __cdecl16far stshRealloc(uint32_t oldblock,uint32_t nbytes)

{
  uint8_t uVar1;
  undefined1 extraout_AH;
  uint uVar2;
  int in_DX;
  int iVar3;
  uint32_t r;
  
  if (oldblock == 0) {
    (*(uint16_t *)((uint8_t *)&(r))) =(uint16_t) stshAlloc(nbytes);
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
        (*(uint16_t *)((uint8_t *)&(r))) =(uint16_t) (long *)CONCAT11(extraout_AH,uVar1);
        iVar3 = in_DX;
      }
      else {
        (*(uint16_t *)((uint8_t *)&(r))) = ovr_heapRealloc((long *)oldblock,CONCAT22((uint16_t)nbytes,(*(uint16_t *)((uint8_t *)&(oldblock) + 2))),
                                  CONCAT22((long *)r,(*(uint16_t *)((uint8_t *)&(nbytes) + 2))));
        iVar3 = in_DX;
      }
      in_DX = iVar3;
      if (((long *)r == (long *)0x0 && iVar3 == 0) &&
         (uVar2 = fmOutOfMemory(nbytes), (uVar2 & 0xff) == 0)) {
        return (uint8_t *)0x0;
      }
    } while ((long *)r == (long *)0x0 && iVar3 == 0);
  }
  return (uint8_t *)(long *)r;
}


/* 474a:08d1 */

far_t * __cdecl16far fmMalloc(far_t *retStorage,uint32_t nbytes)

{
  far_t *pfVar1;
  uint uVar2;
  int in_DX;
  int iVar3;
  ulong in_stack_0000fff8;
  ulong uVar4;
  uint16_t uVar5;
  
  uVar4 = in_stack_0000fff8 & 0xffff0000;
  ovr_fmFreeAudio(0);
  if (retStorage == (far_t *)0x0 && (int)nbytes == 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x1c);
  }
  do {
    uVar5 = (uint16_t)(uVar4 >> 0x10);
    if (HeapReady == '\0') {
      pfVar1 = farmalloc(retStorage,CONCAT22(uVar5,(int)nbytes));
      iVar3 = in_DX;
    }
    else {
      pfVar1 = ovr_heapMalloc(retStorage,CONCAT22(uVar5,(int)nbytes));
      iVar3 = in_DX;
    }
    uVar4 = ZEXT24(pfVar1) << 0x10;
    in_DX = iVar3;
    if (pfVar1 == (far_t *)0x0 && iVar3 == 0) {
      uVar4 = ZEXT24(pfVar1) << 0x10;
      uVar2 = fmMallocRecover();
      if ((uVar2 & 0xff) == 0) {
        return (far_t *)0x0;
      }
    }
    pfVar1 = (far_t *)(uVar4 >> 0x10);
  } while (pfVar1 == (far_t *)0x0 && iVar3 == 0);
  return pfVar1;
}



/* 474a:0953 */

/* vsprintfs string into a ring buffer */

char * __cdecl16far fmVsprintf(char *fmt,char *arg)

{
  uint8_t *puVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint8_t *src;
  uint8_t buf;
  int16_t vlen;
  char **ppcStack_6;
  
  FMRingIndex = FMRingIndex + 1 & 7;
  ppcStack_6 = &arg;
  vlen = vsprintf((char *)CONCAT22(_SS,&buf),fmt,(uint16_t)ppcStack_6);
  src = (uint8_t *)CONCAT22(_SS,&buf);
  iVar3 = vlen + 1 >> 0xf;
  puVar1 = stshRealloc(CONCAT22(*(uint16_t *)((int)&FMRingBuf[0].seg + (uint)FMRingIndex * 4),
                                ((far_t *)FMRingBuf + FMRingIndex)->ofs),(long)(vlen + 1));
                    /* Copy sprintfed string to dst */
  pcVar2 = strcpy((char *)CONCAT22(iVar3,puVar1),(char *)src);
  uVar4 = (uint)FMRingIndex;
  *(int *)((int)&FMRingBuf[0].seg + uVar4 * 4) = iVar3;
  ((far_t *)FMRingBuf + uVar4)->ofs = (uint16_t)pcVar2;
  return (char *)((far_t *)FMRingBuf + FMRingIndex)->ofs;
}



/* 474a:09df */

char * __cdecl16far stsprintf(char *buf,char *fmt,char *arg1,...)

{
  vsprintf((char *)CONCAT22((char *)fmt,buf),(char *)CONCAT22((char *)arg1,(*(uint16_t *)((uint8_t *)&(fmt) + 2))),(int)&arg1 + 2
          );
  return buf;
}



/* 474a:0a10 */

void __cdecl16far clean_ring_buffer(void)

{
  far_t handle;
  uint8_t i;
  
  for (i = 0x0; i < 8; i = i + 0x1) {
    if (((far_t *)FMRingBuf + i)->ofs != 0 || *(int *)((int)&FMRingBuf[0].seg + (uint)i * 4) != 0) {
      handle.seg = *(uint16_t *)((int)&FMRingBuf[0].seg + (uint)i * 4);
      handle.ofs = ((far_t *)FMRingBuf + i)->ofs;
      stshFree(handle);
    }
    *(uint16_t *)((int)&FMRingBuf[0].seg + (uint)i * 4) = 0;
    ((far_t *)FMRingBuf + i)->ofs = 0;
  }
  return;
}



/* 474a:0a6a */

void __cdecl16far initStshTables(void)

{
  uint16_t i;
  
  _fmemset(MK_FP(0x1ef4, 0x0880), 0, 0x220);
  for (i = 0; (int)i < 0x220; i = i + 1) {
    *(uint16_t *)((uint8_t *)&StshSizes[i] + 2) = 0x7fff;
    *(uint16_t *)(&StshSizes[i]) = 0xffff;
  }
  return;
}



/* 474a:0aa7 */
uint32_t * __cdecl16far stshFilesize(uint32_t *retStorage,uint16_t file_id)

{
  long *retStorage2;
  long *plVar1;
  uint16_t in_DX;
  int unaff_DI;
  
  if ((*(int *)((int)retStorage * 4 + 0xaa2) == 0x7fff) &&
     (*(int *)((int)retStorage * 4 + 0xaa0) == -1)) {
    retStorage2 =
         (long *)open_wait_unlock_and_disk
                           ((char *)*(uint16_t *)((int)retStorage * 4),
                            ((uint16_t *)((int)retStorage * 4))[1]);
    plVar1 = filelength(retStorage2,unaff_DI);
    *(uint16_t *)((int)retStorage * 4 + 0xaa2) = in_DX;
    *(uint16_t *)((int)retStorage * 4 + 0xaa0) = (uint16_t)plVar1;
    close((int)retStorage2);
  }
  return (uint32_t *)*(uint16_t *)((int)retStorage * 4 + 0xaa0);
}


/* 474a:0b26 */

uint16_t __cdecl16far randBelow(uint16_t n,uint16_t arg2)

{
  uint8_t rnd;
  
  rnd = rand8();
  return rnd * n >> 8;
}



/* 474a:0b38 */

int __cdecl16far creat_wait_unlock_and_disk(char *path,uint16_t arg2)

{
  /* The decompiled form used a phantom stack parameter as the path and an
     uninitialised register as the create attribute.  Same shape as creat_wait_unlock
     in ovc31_config.c, whose near-path form is verified to work. */
  uint16_t handle;
  uint16_t ioerr;

  (void)arg2;
  do {
    ioErrorHndlrInstall();
    handle = _creat(path,0);
    ioerr = ioErrorHndlrUninstall();
    if (handle != 0xffff) {
      return handle;
    }
  } while ((ioerr == 0x20) || (ioerr == 0x37));
  return -1;
}



/* 474a:0b70 */

int __cdecl16far open_wait_unlock_and_disk(char *filename,uint16_t arg2)

{
  /* The decompiled form built the path as CONCAT22(phantomParam, filename), i.e. a
     far pointer whose segment was never supplied. */
  uint16_t handle;
  uint16_t ioerr;

  (void)arg2;
  do {
    ioErrorHndlrInstall();
    handle = _open(filename,0x41);
    ioerr = ioErrorHndlrUninstall();
    if (handle != 0xffff) {
      return handle;
    }
  } while ((ioerr == 0x20) || (ioerr == 0x37));
  return -1;
}



/* 474a:0ba8 */

void __cdecl16far
fmReadIntoHimem(char *filename,uint16_t filenameSeg,int skipLo,int skipHi,char useEms,uint16_t limitLo,uint16_t limitHi,uint16_t arg8)

{
  long *retStorage;
  long *plVar1;
  uint in_DX;
  uint unaff_DI;
  bool bVar2;
  far_t handle;
  uint uStack_e;
  uint16_t uStack_c;
  long *plStack_a;
  uint uStack_8;
  void *pvStack_6;
  long *plStack_4;
  
  retStorage = (long *)open_wait_unlock_and_disk(filename,0);
  if (-1 < (int)retStorage) {
    plStack_a = filelength(retStorage,unaff_DI);
    uStack_8 = in_DX;
    if (skipLo != 0 || skipHi != 0) {
      lseek((int)retStorage,(ulong)(uint)skipHi,unaff_DI);
      bVar2 = plStack_a < (uint)skipLo;
      plStack_a = (long *)((int)plStack_a - skipLo);
      uStack_8 = (in_DX - skipHi) - (uint)bVar2;
    }
    if ((limitHi <= uStack_8) && ((uStack_8 != limitHi || (limitLo < plStack_a)))) {
      uStack_8 = limitHi;
      plStack_a = (long *)limitLo;
    }
    plStack_4 = plStack_a;
    if (((int)uStack_8 < 0) || (((int)uStack_8 < 1 && (plStack_a < (long *)0xc001)))) {
      pvStack_6 = stshAlloc((uint32_t)CONCAT22(uStack_8,plStack_a));
    }
    else {
      pvStack_6 = stshAlloc(0xc000);
    }
    uStack_c = 0;
    uStack_e = 0;
    for (; plStack_a != (long *)0x0 || uStack_8 != 0;
        plStack_a = (long *)((int)plStack_a - (int)plVar1)) {
      plVar1 = plStack_a;
      if ((-1 < (int)uStack_8) && ((0 < (int)uStack_8 || ((long *)0xc000 < plStack_a)))) {
        plVar1 = (long *)0xc000;
      }
      plVar1 = (long *)read((int)retStorage,(long *)CONCAT22(plVar1,plStack_4),unaff_DI)
      ;
      if ((plVar1 == (long *)0x0) || (plVar1 == (long *)0xffff)) break;
      if (useEms == '\0') {
        xms_usesXmsHandle2(uStack_e,uStack_c,(int)pvStack_6,(uint16_t)plStack_4,(uint)plVar1,0);
      }
      else {
        ems_memmove2(uStack_e,uStack_c,(uint16_t)pvStack_6,(uint16_t)plStack_4,(uint16_t)plVar1,0);
      }
      bVar2 = CARRY2(uStack_e,(uint)plVar1);
      uStack_e = uStack_e + (int)plVar1;
      uStack_c = uStack_c + bVar2;
      uStack_8 = uStack_8 - (plStack_a < plVar1);
    }
    close((int)retStorage);
    handle.seg = (uint16_t)plStack_4;
    handle.ofs = (uint16_t)pvStack_6;
    stshFree(handle);
  }
  return;
}



/* 474a:0cf8 */

stg_tmp_t * __cdecl16far stshLoadGfx(far_t handle)

{
  int iVar1;
  uint16_t uVar2;
  stg_tmp_t *psVar3;
  far_t *pfVar4;
  uint16_t in_DX;
  uint16_t uVar5;
  uint16_t in_stack_0000fff6;
  
  handle.ofs = (uint16_t)ovr_mkp((uint32_t *)handle.ofs,handle.seg,in_stack_0000fff6);
  handle.seg = in_DX;
  if (*(char *)MK_FP(handle.seg, handle.ofs) == '\0') {
    uVar5 = in_DX;
    psVar3 = (stg_tmp_t *)
             ovr_mkp((uint32_t *)Stsh_2410_47f6.ofs,Stsh_2410_47f6.seg,in_stack_0000fff6);
    if ((uVar5 != in_DX) || (psVar3 != (stg_tmp_t *)handle.ofs)) {
      iVar1 = *(int *)(((stg_tmp_t *)handle.ofs)->cmap + 0xf);
      in_stack_0000fff6 = *(uint16_t *)(((stg_tmp_t *)handle.ofs)->cmap + 0xd);
      uVar5 = *(uint16_t *)(((stg_tmp_t *)handle.ofs)->cmap + 0xb);
      uVar2 = *(uint16_t *)(((stg_tmp_t *)handle.ofs)->cmap + 9);
      if (uVar2 != 0 || uVar5 != 0) {
        *(int *)(uVar2 + 0xf) = iVar1;
        *(uint16_t *)(uVar2 + 0xd) = in_stack_0000fff6;
      }
      if (in_stack_0000fff6 != 0 || iVar1 != 0) {
        *(uint16_t *)(in_stack_0000fff6 + 0xb) = uVar5;
        *(uint16_t *)(in_stack_0000fff6 + 9) = uVar2;
        uVar2 = StshCtPtr2.ofs;
        uVar5 = StshCtPtr2.seg;
      }
      StshCtPtr2.seg = uVar5;
      StshCtPtr2.ofs = uVar2;
      uVar5 = Stsh_2410_47f6.ofs;
      *(uint16_t *)(((stg_tmp_t *)handle.ofs)->cmap + 0xf) = Stsh_2410_47f6.seg;
      *(uint16_t *)(((stg_tmp_t *)handle.ofs)->cmap + 0xd) = uVar5;
      (((stg_tmp_t *)handle.ofs)->cmap + 0xb)[0] = 0x0;
      (((stg_tmp_t *)handle.ofs)->cmap + 0xb)[1] = 0x0;
      (((stg_tmp_t *)handle.ofs)->cmap + 9)[0] = 0x0;
      (((stg_tmp_t *)handle.ofs)->cmap + 9)[1] = 0x0;
      *(uint16_t far *)((uint8_t far *)MK_FP(Stsh_2410_47f6.seg, Stsh_2410_47f6.ofs) +  0xb) = in_DX;
      *(uint16_t far *)((uint8_t far *)MK_FP(Stsh_2410_47f6.seg, Stsh_2410_47f6.ofs) +  9) = handle.ofs;
      Stsh_2410_47f6.seg = in_DX;
      Stsh_2410_47f6.ofs = handle.ofs;
      uVar5 = in_DX;
    }
    if (*(int *)(((stg_tmp_t *)handle.ofs)->cmap + 0x11) == 0 &&
        *(int *)(((stg_tmp_t *)handle.ofs)->cmap + 0x13) == 0) {
      pfVar4 = fmMalloc(*(far_t **)(((stg_tmp_t *)handle.ofs)->cmap + 5),
                        CONCAT22(in_stack_0000fff6,
                                 *(uint16_t *)(((stg_tmp_t *)handle.ofs)->cmap + 7)));
      *(uint16_t *)(((stg_tmp_t *)handle.ofs)->cmap + 0x13) = uVar5;
      *(far_t **)(((stg_tmp_t *)handle.ofs)->cmap + 0x11) = pfVar4;
      if (*(int *)(((stg_tmp_t *)handle.ofs)->cmap + 0x11) == 0 &&
          *(int *)(((stg_tmp_t *)handle.ofs)->cmap + 0x13) == 0) {
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0x47);
      }
      stshSeek(StshStrongDatHnd,
               CONCAT22(*(uint16_t *)(((stg_tmp_t *)handle.ofs)->cmap + 3),
                        *(uint16_t *)(((stg_tmp_t *)handle.ofs)->cmap + 1)));
      stshRead();
    }
    handle.ofs = *(uint16_t *)(((stg_tmp_t *)handle.ofs)->cmap + 0x11);
  }
  return (stg_tmp_t *)handle.ofs;
}



/* 474a:0e9b */
undefined1 * __cdecl16far stash_loadFromStrongDat(far_t entry)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  far_t far *pfVar4;
  far_t far *pfVar5;
  uint16_t in_DX;
  uint16_t uVar6;
  uint16_t uVar7;
  undefined1 in_stack_0000fff0;
  undefined1 in_stack_0000fff1;
  
  entry.ofs = (uint16_t)ovr_mkp((uint32_t *)entry.ofs,entry.seg);
  entry.seg = in_DX;
  pfVar4 = (far_t far *)entry.ofs;
  if (*(char *)MK_FP(entry.seg, entry.ofs) == '\0') {
    uVar6 = in_DX;
    pfVar4 = fmMalloc((far_t *)*(uint16_t *)((int)&((far_t *)(entry.ofs + 4))->ofs + 1),
                      CONCAT13(in_stack_0000fff1,
                               CONCAT12(in_stack_0000fff0,
                                        *(uint16_t *)((int)&((far_t far *)(entry.ofs + 4))->seg + 1)))
                     );
    if (pfVar4 == (far_t far *)0x0 && uVar6 == 0) {
      pfVar4 = (far_t far *)0x0;
    }
    else {
      if (*(int *)((int)&((far_t far *)(entry.ofs + 0x10))->ofs + 1) == 0 &&
          *(int *)((int)&((far_t far *)(entry.ofs + 0x10))->seg + 1) == 0) {
        uVar7 = uVar6;
        stshSeek(StshStrongDatHnd,
                 CONCAT22(*(uint16_t *)((int)&((far_t far *)entry.ofs)->seg + 1),
                          *(uint16_t *)((int)&((far_t far *)entry.ofs)->ofs + 1)));
        stshRead();
        pfVar5 = ovr_heapMalloc((far_t far *)*(uint16_t *)((int)&((far_t far *)(entry.ofs + 4))->ofs + 1),
                                CONCAT13(in_stack_0000fff1,
                                         CONCAT12(in_stack_0000fff0,
                                                  *(uint16_t *)
                                                   ((int)&((far_t far *)(entry.ofs + 4))->seg + 1))));
        *(uint16_t *)((int)&((far_t far *)(entry.ofs + 0x10))->seg + 1) = uVar7;
        *(uint16_t *)((int)&((far_t far *)(entry.ofs + 0x10))->ofs + 1) =(uint16_t) pfVar5;
        if (*(int *)((int)&((far_t far *)(entry.ofs + 0x10))->ofs + 1) == 0 &&
            *(int *)((int)&((far_t far *)(entry.ofs + 0x10))->seg + 1) == 0) {
          bVar3 = false;
        }
        else {
          memcpy((char *)CONCAT22(*(uint16_t *)((int)&((far_t far *)(entry.ofs + 0x10))->seg + 1),
                                  (char *)*(uint16_t *)
                                           ((int)&((far_t far *)(entry.ofs + 0x10))->ofs + 1)),
                 (char *)CONCAT22(uVar6,pfVar4),*(word *)((int)&((far_t far *)(entry.ofs + 4))->ofs + 1)
                );
          bVar3 = true;
        }
      }
      else {
        memcpy((char *)CONCAT22(uVar6,pfVar4),
               (char *)CONCAT22(*(uint16_t *)((int)&((far_t far *)(entry.ofs + 0x10))->seg + 1),
                                (char *)*(uint16_t *)
                                         ((int)&((far_t far *)(entry.ofs + 0x10))->ofs + 1)),
               *(word *)((int)&((far_t far *)(entry.ofs + 4))->ofs + 1));
        bVar3 = true;
        uVar7 = uVar6;
      }
      if (bVar3) {
        pfVar5 = (far_t far *)ovr_mkp((uint32_t *)Stsh_2410_47f6.ofs,Stsh_2410_47f6.seg);
        if ((uVar7 != in_DX) || (pfVar5 != (far_t far *)entry.ofs)) {
          iVar1 = *(int *)((int)&((far_t far *)(entry.ofs + 0xc))->seg + 1);
          iVar2 = *(int *)((int)&((far_t far *)(entry.ofs + 0xc))->ofs + 1);
          uVar6 = *(uint16_t *)((int)&((far_t far *)(entry.ofs + 8))->seg + 1);
          uVar7 = *(uint16_t *)((int)&((far_t far *)(entry.ofs + 8))->ofs + 1);
          if (uVar7 != 0 || uVar6 != 0) {
            *(int *)(uVar7 + 0xf) = iVar1;
            *(int *)(uVar7 + 0xd) = iVar2;
          }
          if (iVar2 != 0 || iVar1 != 0) {
            *(uint16_t *)(iVar2 + 0xb) = uVar6;
            *(uint16_t *)(iVar2 + 9) = uVar7;
            uVar7 = StshCtPtr2.ofs;
            uVar6 = StshCtPtr2.seg;
          }
          StshCtPtr2.seg = uVar6;
          StshCtPtr2.ofs = uVar7;
          uVar6 = Stsh_2410_47f6.ofs;
          *(uint16_t *)((int)&((far_t far *)(entry.ofs + 0xc))->seg + 1) = Stsh_2410_47f6.seg;
          *(uint16_t *)((int)&((far_t far *)(entry.ofs + 0xc))->ofs + 1) = uVar6;
          *(uint16_t *)((int)&((far_t far *)(entry.ofs + 8))->seg + 1) = 0;
          *(uint16_t *)((int)&((far_t far *)(entry.ofs + 8))->ofs + 1) = 0;
          *(uint16_t far *)((uint8_t far *)MK_FP(Stsh_2410_47f6.seg, Stsh_2410_47f6.ofs) +  0xb) = in_DX;
          *(uint16_t far *)((uint8_t far *)MK_FP(Stsh_2410_47f6.seg, Stsh_2410_47f6.ofs) +  9) = entry.ofs;
          Stsh_2410_47f6.seg = in_DX;
          Stsh_2410_47f6.ofs = entry.ofs;
        }
      }
    }
  }
  return (undefined1 *)pfVar4;
}


/* 474a:10ac */

/* [R4] calls ovr_stExit */

stg_tmp_t * __cdecl16far stash_usesStExit(stg_tmp_t *gfxListOfs,uint16_t arg2,uint16_t arg3)

{
  uint uVar1;
  uint16_t in_stack_00000006;
  byte in_stack_00000008;
  far_t handle;
  
  if (gfxListOfs == (stg_tmp_t *)0x0 && in_stack_00000006 == 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0xb);
  }
  if (gfxListOfs->cmap[0] == 0x0) {
    handle.seg = in_stack_00000006;
    handle.ofs = (uint16_t)(gfxListOfs->cmap + (uint)in_stack_00000008 * 0x15);
    gfxListOfs = stshLoadGfx(handle);
  }
  else {
    uVar1 = 0;
    while( true ) {
      if (in_stack_00000008 <= uVar1) break;
      if (gfxListOfs == (stg_tmp_t *)0x0 && in_stack_00000006 == 0) {
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0xb);
      }
      uVar1 = uVar1 + 1;
      gfxListOfs = (stg_tmp_t *)
                    CONCAT22(*(uint16_t *)(gfxListOfs->cmap + 3),
                             *(stg_tmp_t **)(gfxListOfs->cmap + 1));
    }
    if (gfxListOfs == (stg_tmp_t *)0x0 && in_stack_00000006 == 0) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(0xb);
    }
  }
  return gfxListOfs;
}



/* 474a:1133 */

void __cdecl16far fmRewindHeapPtr(void)

{
  uint16_t *puVar1;
  uint16_t uStack_6;
  uint16_t uStack_4;
  
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

int __cdecl16far fmMallocRecover(void)

{
  uint16_t *puVar1;
  bool freed;
  undefined1 extraout_AH;
  int iVar3;
  undefined1 uVar4;
  byte extraout_AH_00;
  far_t handle;
  uint16_t uStack_6;
  uint16_t uStack_4;
  
  freed = ovr_fmFreeAudio(0);
  if (freed) {
    iVar3 = CONCAT11(extraout_AH,1);
  }
  else {
    uStack_4 = StshCtPtr2.seg;
    uStack_6 = StshCtPtr2.ofs;
    while (uStack_6 != 0 || uStack_4 != 0) {
      if (*(int *)(uStack_6 + 0x11) != 0 || *(int *)(uStack_6 + 0x13) != 0) {
        handle.seg = *(uint16_t *)(uStack_6 + 0x13);
        handle.ofs = *(uint16_t *)(uStack_6 + 0x11);
        stshFree(handle);
        iVar3 = *(int *)(uStack_6 + 0x13);
        *(uint16_t *)(uStack_6 + 0x13) = 0;
        *(uint16_t *)(uStack_6 + 0x11) = 0;
        uVar4 = 0x24;
        if (HeapPtr == iVar3) {
          uVar4 = 0x24;
          fmRewindHeapPtr();
        }
        return CONCAT11(uVar4,1);
      }
      puVar1 = (uint16_t *)(uStack_6 + 0xb);
      uStack_6 = *(uint16_t *)(uStack_6 + 9);
      uStack_4 = *puVar1;
    }
    freed = ovr_fmFreeAudio(1);
    if (freed) {
      iVar3 = CONCAT11(extraout_AH_00,1);
    }
    else {
      if (audioBusy == '\0') {
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0x15);
      }
      iVar3 = (uint)extraout_AH_00 << 8;
    }
  }
  return iVar3;
}



/* 474a:1254 */

void __cdecl16far fmFree(void)

{
  /* Re-derived: stops the audio, then walks the StshCtPtr2 chain.  Each node's handle at +0x11
     (offset) / +0x13 (segment) is freed and cleared, and when that segment equals the current
     HeapPtr the heap pointer is rewound.  Nodes link through +0x9 / +0xb. */
  uint16_t *nextSegPtr;
  int handleSeg;
  far_t handle;
  uint16_t cursorOfs;
  uint16_t cursorSeg;

  ovr_fmFreeAudio(1);
  cursorSeg = StshCtPtr2.seg;
  cursorOfs = StshCtPtr2.ofs;
  while (cursorOfs != 0 || cursorSeg != 0) {
    if ((*(int *)(cursorOfs + 0x11) != 0) || (*(int *)(cursorOfs + 0x13) != 0)) {
      handle.seg = *(uint16_t *)(cursorOfs + 0x13);
      handle.ofs = *(uint16_t *)(cursorOfs + 0x11);
      stshFree(handle);
      handleSeg = *(int *)(cursorOfs + 0x13);
      *(uint16_t *)(cursorOfs + 0x13) = 0;
      *(uint16_t *)(cursorOfs + 0x11) = 0;
      if (HeapPtr == handleSeg) {
        fmRewindHeapPtr();
      }
    }
    nextSegPtr = (uint16_t *)(cursorOfs + 0xb);
    cursorOfs = *(uint16_t *)(cursorOfs + 9);
    cursorSeg = *nextSegPtr;
  }
  return;
}



/* 474a:12dc */

uint16_t __cdecl16far fmOutOfMemory(uint32_t nbytes)

{
  uint16_t *nextSegPtr;
  bool freed;
  undefined1 extraout_AH;
  long *plVar3;
  uint uVar4;
  undefined1 uVar5;
  byte extraout_AH_00;
  int iVar6;
  uint16_t unaff_SI;
  uint uVar7;
  long *unaff_DI;
  uint uVar8;
  uint16_t uVar9;
  far_t block;
  far_t bestBlock;
  uint16_t bestOfs;
  uint8_t bestSegLo;
  undefined1 bestSegHi;
  uint bestSize;
  uint16_t nodeOfs;
  uint16_t nodeSeg;
  
  freed = ovr_fmFreeAudio(0);
  uVar5 = extraout_AH;
  if (!freed) {
    iVar6 = (*(uint16_t *)((uint8_t *)&(nbytes) + 2)) + (uint)(0xffec < (uint)nbytes);
    plVar3 = LXRSH_at_(unaff_DI,CONCAT22(bestOfs,unaff_SI),bestSegLo);
    uVar4 = (int)plVar3 + HeapPtr;
    iVar6 = iVar6 + (uint)CARRY2((uint)plVar3,HeapPtr);
    uVar8 = uVar4;
    if (iVar6 != 0) {
      uVar8 = 0xffff;
    }
    if (((MUSHandle.ofs != 0 || MUSHandle.seg != 0) && ((iVar6 != 0 || (MUSHandle.seg < uVar4)))) ||
       ((DIGHandle.ofs != 0 || DIGHandle.seg != 0 && ((iVar6 != 0 || (MUSHandle.seg < uVar4)))))) {
      ovr_fmFreeAudio(1);
    }
    bestSize = 0xffff;
    HeapPtr = 0xffff;
    freed = false;
    nodeSeg = StshCtPtr2.seg;
    nodeOfs = StshCtPtr2.ofs;
    uVar4 = 0xffff;
    while (nodeOfs != 0 || nodeSeg != 0) {
      uVar7 = uVar4;
      if (*(int *)(nodeOfs + 0x11) != 0 || *(int *)(nodeOfs + 0x13) != 0) {
        if (*(uint *)(nodeOfs + 0x13) < uVar8) {
          block.seg = *(uint16_t *)(nodeOfs + 0x13);
          block.ofs = *(uint16_t *)(nodeOfs + 0x11);
          stshFree(block);
          *(uint16_t *)(nodeOfs + 0x13) = 0;
          *(uint16_t *)(nodeOfs + 0x11) = 0;
          freed = true;
        }
        else {
          if (*(uint *)(nodeOfs + 0x13) < uVar4) {
            uVar7 = *(uint *)(nodeOfs + 0x13);
            bestSegLo = (uint8_t)nodeSeg;
            bestSegHi = (undefined1)(nodeSeg >> 8);
            bestOfs = nodeOfs;
            bestSize = uVar4;
          }
          if (*(uint *)(nodeOfs + 0x13) < HeapPtr) {
            HeapPtr = *(uint *)(nodeOfs + 0x13);
          }
        }
      }
      nextSegPtr = (uint16_t *)(nodeOfs + 0xb);
      nodeOfs = *(uint16_t *)(nodeOfs + 9);
      uVar4 = uVar7;
      nodeSeg = *nextSegPtr;
    }
    uVar5 = 0;
    if (!freed) {
      if (uVar4 == 0xffff) {
        freed = ovr_fmFreeAudio(1);
        if (freed) {
          return CONCAT11(extraout_AH_00,1);
        }
        if (audioBusy == '\0') {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x14);
        }
        return (uint)extraout_AH_00 << 8;
      }
      uVar9 = (uint16_t)(CONCAT13(bestSegHi,CONCAT12(bestSegLo,bestOfs)) >> 0x10)
      ;
      bestBlock.seg = *(uint16_t *)(bestOfs + 0x13);
      bestBlock.ofs = *(uint16_t *)(bestOfs + 0x11);
      stshFree(bestBlock);
      uVar9 = (uint16_t)(CONCAT13(bestSegHi,CONCAT12(bestSegLo,bestOfs)) >> 0x10)
      ;
      *(uint16_t *)(bestOfs + 0x13) = 0;
      *(uint16_t *)(bestOfs + 0x11) = 0;
      uVar5 = 0x24;
      HeapPtr = bestSize;
    }
  }
  return CONCAT11(uVar5,1);
}


