/*
 * ovc17_stash.c - recovered from STRONG.EXE
 * memory block: OVC17_stash.c
 * range: 474a:0000 - 474a:161f
 * functions: 26
 */
#include "recovered.h"


/* 474a:0000 */

uint16_t __cdecl16far stshOpen(uint16_t file_id,...)

{
  int fh;
  
  fh = open_wait_unlock_and_disk
                 ((char *)*(undefined2 *)(file_id * 4),((undefined2 *)(file_id * 4))[1]);
  ((int *)StshHandles)[file_id] = fh;
  *(undefined2 *)((int)(long *)StshPtrs + file_id * 4 + 2) = 0;
  *(undefined2 *)((long *)StshPtrs + file_id) = 0;
  return file_id;
}



/* 474a:004e */

void __cdecl16far stshClose(uint16_t file_id,...)

{
  if (((int *)StshHandles)[file_id] != -1) {
    close(((int *)StshHandles)[file_id]);
  }
  ((int *)StshHandles)[file_id] = -1;
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
  undefined2 unaff_SI;
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
  uint32_t uStack_18;
  uint16_t pbuf;
  uint8_t in_stack_0000ffec;
  uint uStack_10;
  uint uStack_e;
  uint uStack_c;
  uint16_t uStack_a;
  uint32_t snbytes;
  
  uVar3 = in_stack_0000000a;
  uStack_18 = CONCAT22(pbuf,unaff_SI);
  uVar5 = *(uint *)((int)(long *)StshPtrs + in_stack_00000004 * 4 + 2);
  uVar6 = *(uint *)((uint8_t *)&StshSizes[in_stack_00000004] + 2);
  if ((uVar5 < uVar6) ||
     ((uVar5 == uVar6 &&
      (*(uint *)((long *)StshPtrs + in_stack_00000004) < *(uint *)(&StshSizes[in_stack_00000004]))))
     ) {
    uVar6 = in_stack_0000000c + *(int *)((int)(long *)StshPtrs + in_stack_00000004 * 4 + 2) +
            (uint)CARRY2(in_stack_0000000a,*(uint *)((long *)StshPtrs + in_stack_00000004));
    uVar5 = *(uint *)((uint8_t *)&StshSizes[in_stack_00000004] + 2);
    if ((uVar5 <= uVar6) &&
       ((uVar5 < uVar6 ||
        (*(uint *)(&StshSizes[in_stack_00000004]) <
         in_stack_0000000a + *(uint *)((long *)StshPtrs + in_stack_00000004))))) {
      uVar5 = *(uint *)(&StshSizes[in_stack_00000004]);
      puVar1 = (uint *)((int)&AgntAnms[0x53].y + 1 + in_stack_00000004 * 4);
      in_stack_0000000a = uVar5 - *puVar1;
      in_stack_0000000c =
           (*(int *)((uint8_t *)&StshSizes[in_stack_00000004] + 2) -
           *(int *)((int)&AgntAnms[0x53].maxDx + 1 + in_stack_00000004 * 4)) -
           (uint)(uVar5 < *puVar1);
    }
    uStack_e = in_stack_0000000c;
    uStack_10 = in_stack_0000000a;
    if (in_stack_00000004 == 0) {
      if (((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) <= (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2))) &&
         (((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) < (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) || ((uint)StshPtrs[0] < (uint)FMXmsHandle)))) {
        uVar5 = ((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) - (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
                (uint)((uint)FMXmsHandle < (uint)StshPtrs[0]);
        if ((uVar5 < in_stack_0000000c) ||
           ((uVar5 <= in_stack_0000000c &&
            ((uint)FMXmsHandle - (uint)StshPtrs[0] <= in_stack_0000000a)))) {
          uStack_c = (uint)FMXmsHandle - (uint)StshPtrs[0];
          uVar5 = ((*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) - (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) -
                  (uint)((uint)FMXmsHandle < (uint)StshPtrs[0]);
          uStack_a = uVar5;
        }
        else {
          uStack_a = in_stack_0000000c;
          uStack_c = in_stack_0000000a;
          uVar5 = in_stack_0000000a;
        }
        uVar6 = (uint)StshPtrs[0];
        srcHi = (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2));
        countLo = uStack_c;
        uVar8 = uStack_a;
        puVar4 = ovr_mkp(in_stack_00000006,(uint16_t)in_stack_00000008,(uint)StshPtrs[0]);
        xms_usesXmsHandle((int)puVar4,uVar5,uVar6,srcHi,countLo,uVar8);
        bVar7 = CARRY2((uint)StshPtrs[0],uStack_c);
        (*(uint16_t *)((uint8_t *)&(StshPtrs[0]))) = (uint)StshPtrs[0] + uStack_c;
        (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) = (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) + uStack_a + (uint)bVar7;
        uStack_10 = in_stack_0000000a - uStack_c;
        uStack_e = (in_stack_0000000c - uStack_a) - (uint)(in_stack_0000000a < uStack_c);
        puVar4 = LXURSH_at_(unaff_DI,uStack_18,in_stack_0000ffec);
        in_stack_00000008 = (uint32_t *)((int)puVar4 + (int)in_stack_00000008);
        in_stack_00000006 = (uint32_t *)((int)in_stack_00000006 + (uStack_c & 0xf));
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
          seg = (uint)StshPtrs[0] - (uint)FMXmsHandle;
          srcEmsOfsHi = ((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) - (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2))) -
                        (uint)((uint)StshPtrs[0] < (uint)FMXmsHandle);
          uVar8 = seg;
          uVar5 = uStack_c;
          lenHi = uStack_a;
          puVar4 = ovr_mkp(in_stack_00000006,(uint16_t)in_stack_00000008,seg);
          ems_memmove1((uint16_t)puVar4,seg,uVar8,srcEmsOfsHi,uVar5,lenHi);
          bVar7 = CARRY2((uint)StshPtrs[0],uStack_c);
          (*(uint16_t *)((uint8_t *)&(StshPtrs[0]))) = (uint)StshPtrs[0] + uStack_c;
          (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) = (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) + uStack_a + (uint)bVar7;
          bVar7 = uStack_10 < uStack_c;
          uStack_10 = uStack_10 - uStack_c;
          uStack_e = (uStack_e - uStack_a) - (uint)bVar7;
          puVar4 = LXURSH_at_(unaff_DI,uStack_18,in_stack_0000ffec);
          in_stack_00000008 = (uint32_t *)((int)puVar4 + (int)in_stack_00000008);
          in_stack_00000006 = (uint32_t *)((int)in_stack_00000006 + (uStack_c & 0xf));
        }
      }
      uVar5 = (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
              (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle);
      if ((uVar5 <= (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) &&
         ((uVar5 != (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) ||
          ((uint)FMXmsHandle + (uint)FMEmsHandle <= (uint)StshPtrs[0])))) {
        lseek(StshHandles[0],(ulong)(*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)),(int)unaff_DI);
      }
      if (uStack_10 == 0 && uStack_e == 0) {
        return uVar3 - in_stack_0000000a;
      }
    }
    fd = *(int *)((char *)0x2420 + in_stack_00000004 * 2);
    pbuf = (uint16_t)in_stack_00000006;
    while( true ) {
      if ((uStack_e == 0) && (uStack_10 == 0)) goto next_iteration;
      if ((uStack_e != 0) || (rdsz = uStack_10, 0xc000 < uStack_10)) {
        rdsz = 0xc000;
      }
      readed = read(fd,(uint32_t *)CONCAT22(rdsz,in_stack_00000008),(uint)unaff_DI);
      if (readed != rdsz) break;
      bVar7 = uStack_10 < readed;
      uStack_10 = uStack_10 - readed;
      uStack_e = uStack_e - bVar7;
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
  long *__return_storage_ptr__;
  uint uVar1;
  uint16_t file_id;
  uint32_t *unaff_DI;
  uint32_t flen;
  uint16_t szlo;
  uint16_t szhi;
  
  _fmemset((void *)0xffff1ef4,0x440,(uint16_t)unaff_DI);
  _fmemset((void *)0x1ef4,0x220,(uint16_t)unaff_DI);
  for (file_id = 0; (int)file_id < 0x220; file_id = file_id + 1) {
    __return_storage_ptr__ =
         (long *)open_wait_unlock_and_disk
                           ((char *)*(undefined2 *)(file_id * 4),((undefined2 *)(file_id * 4))[1]);
    if ((int)__return_storage_ptr__ < 0) {
      szhi = 0;
      szlo = 0;
    }
    else {
      (*(uint16_t *)((uint8_t *)&(flen))) =(uint16_t) filelength(__return_storage_ptr__,(int)unaff_DI);
      close((int)__return_storage_ptr__);
      szlo = (uint16_t)(long *)flen;
      szhi = (*(uint16_t *)((uint8_t *)&(flen) + 2));
    }
    *(uint16_t *)((uint8_t *)&StshSizes[file_id] + 2) = szhi;
    *(uint16_t *)(&StshSizes[file_id]) = szlo;
    *(undefined2 *)((int)(long *)StshPtrs + file_id * 4 + 2) = 0;
    *(undefined2 *)((long *)StshPtrs + file_id) = 0;
    (*(uint16_t *)((uint8_t *)&(flen) + 2)) = szhi;
  }
  (*(uint16_t *)((uint8_t *)&(FMXmsHandle))) =(uint16_t) xms_init(unaff_DI);
  (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) = (*(uint16_t *)((uint8_t *)&(flen) + 2));
  (*(uint16_t *)((uint8_t *)&(FMEmsHandle))) =(uint16_t) ems_init(unaff_DI);
  (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) = (*(uint16_t *)((uint8_t *)&(flen) + 2));
  if ((uint32_t *)FMXmsHandle != (uint32_t *)0x0 || (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) != 0) {
    if (((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)) <= (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2))) &&
       (((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)) < (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) ||
        ((uint32_t *)StshSizes[0] < (uint32_t *)FMXmsHandle)))) {
      stshInit_scan((uint32_t)CONCAT22((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)),(uint32_t *)StshSizes[0]));
      (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) = (*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2));
      (*(uint16_t *)((uint8_t *)&(FMXmsHandle))) =(uint16_t) (uint32_t *)StshSizes[0];
    }
    fmReadIntoHimem((char *)StshNames[0],(*(uint16_t *)((uint8_t *)&(StshNames[0]) + 2)),0,0,'\0',
                    (uint16_t)(uint32_t *)FMXmsHandle,(*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)),0);
  }
  if ((((uint32_t *)FMEmsHandle == (uint32_t *)0x0 && (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) == 0) ||
      ((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)) < (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)))) ||
     (((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)) <= (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) &&
      ((uint32_t *)StshSizes[0] <= (uint32_t *)FMXmsHandle)))) {
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
        ((uint32_t *)StshSizes[0] <
         (uint32_t *)((int)(uint32_t *)FMXmsHandle + (int)(uint32_t *)FMEmsHandle))))) {
      (*(uint16_t *)((uint8_t *)&(FMEmsHandle))) = (uint16_t)((uint32_t *)((int)(uint32_t *)StshSizes[0] - (int)(uint32_t *)FMXmsHandle))
      ;
      (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) =
           ((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)) - (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2))) -
           (uint)((uint32_t *)StshSizes[0] < (uint32_t *)FMXmsHandle);
      ems_realloc((uint32_t)CONCAT22((*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)),(uint32_t *)FMEmsHandle));
    }
    fmReadIntoHimem((char *)StshNames[0],(*(uint16_t *)((uint8_t *)&(StshNames[0]) + 2)),(int)(uint32_t *)FMXmsHandle,
                    (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)),'\x01',(uint16_t)(uint32_t *)FMEmsHandle,(*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)),1);
  }
  return;
}


/* 474a:067b */

/* WARNING: Removing unreachable block (ram,0x00047b3c) */

void __cdecl16far stshSeek(uint16_t fid,long ofs,...)

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
  *(undefined2 *)((int)&AgntAnms[0x53].y + 1 + fid * 4) = (undefined2)ofs;
  return;
}



/* 474a:06fe */

uint32_t * __cdecl16far stshTell(uint32_t *__return_storage_ptr__,uint16_t file_id,...)

{
  return (uint32_t *)*(undefined2 *)((int)&AgntAnms[0x53].y + 1 + (int)__return_storage_ptr__ * 4);
}



/* 474a:0718 */

void __cdecl16far stshFree(far_t handle,...)

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
void * __cdecl16far stshAlloc(uint32_t nbytes,...)

{
  uint uVar1;
  uint16_t ofs_00;
  uint32_t r;
  uint32_t result;
  uint16_t ofs;
  uint16_t seg;
  uint32_t newbuf;
  
  if (nbytes == 0xfa0f) {
    (*(uint16_t *)((uint8_t *)&(r))) =(uint16_t) (far_t *)StshBuf.ofs;
    if (StshBuf.ofs == 0 && StshBuf.seg == 0) {
      (*(uint16_t *)((uint8_t *)&(r))) =(uint16_t) farmalloc((far_t *)0xfa0f,(ulong)ofs << 0x10);
      StshBuf.ofs = (uint16_t)(far_t *)r;
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
        ofs = (uint16_t)ovr_heapAlloc((uint32_t *)(far_t *)nbytes,CONCAT22(ofs,(*(uint16_t *)((uint8_t *)&(nbytes) + 2))));
        ofs_00 = (*(uint16_t *)((uint8_t *)&(r) + 2));
      }
      (*(uint16_t *)((uint8_t *)&(r) + 2)) = ofs_00;
      if ((ofs == 0 && ofs_00 == 0) && (uVar1 = fmOutOfMemory(nbytes), (uVar1 & 0xff) == 0)) {
        return (void *)0x0;
      }
    } while (ofs == 0 && ofs_00 == 0);
    (*(uint16_t *)((uint8_t *)&(r))) =(uint16_t) (far_t *)ovr_mkp((uint32_t *)ofs,ofs_00,ofs);
  }
  return (far_t *)r;
}


/* 474a:0822 */
uint8_t * __cdecl16far stshRealloc(uint32_t oldblock,uint32_t nbytes,...)

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
        (*(uint16_t *)((uint8_t *)&(r))) = ovr_heapRealloc((long *)oldblock,CONCAT22((undefined2)nbytes,(*(uint16_t *)((uint8_t *)&(oldblock) + 2))),
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

far_t * __cdecl16far fmMalloc(far_t *__return_storage_ptr__,uint32_t nbytes)

{
  far_t *pfVar1;
  uint uVar2;
  int in_DX;
  int iVar3;
  ulong in_stack_0000fff8;
  ulong uVar4;
  undefined2 uVar5;
  
  uVar4 = in_stack_0000fff8 & 0xffff0000;
  ovr_fmFreeAudio(0);
  if (__return_storage_ptr__ == (far_t *)0x0 && (int)nbytes == 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x1c);
  }
  do {
    uVar5 = (undefined2)(uVar4 >> 0x10);
    if (HeapReady == '\0') {
      pfVar1 = farmalloc(__return_storage_ptr__,CONCAT22(uVar5,(int)nbytes));
      iVar3 = in_DX;
    }
    else {
      pfVar1 = ovr_heapMalloc(__return_storage_ptr__,CONCAT22(uVar5,(int)nbytes));
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
  undefined2 unaff_SS;
  uint8_t *src;
  uint8_t buf;
  int16_t iStack_8;
  char **ppcStack_6;
  
  FMRingIndex = FMRingIndex + 1 & 7;
  ppcStack_6 = &arg;
  iStack_8 = vsprintf((char *)CONCAT22(unaff_SS,&buf),fmt,(uint16_t)ppcStack_6);
  src = (uint8_t *)CONCAT22(unaff_SS,&buf);
  iVar3 = iStack_8 + 1 >> 0xf;
  puVar1 = stshRealloc(CONCAT22(*(undefined2 *)((int)&FMRingBuf[0].seg + (uint)FMRingIndex * 4),
                                ((far_t *)FMRingBuf + FMRingIndex)->ofs),(long)(iStack_8 + 1));
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
    *(undefined2 *)((int)&FMRingBuf[0].seg + (uint)i * 4) = 0;
    ((far_t *)FMRingBuf + i)->ofs = 0;
  }
  return;
}



/* 474a:0a6a */

void __cdecl16far initStshTables(void)

{
  uint16_t unaff_SI;
  uint16_t i;
  
  _fmemset((void *)0x1ef4,0x220,unaff_SI);
  for (i = 0; (int)i < 0x220; i = i + 1) {
    *(undefined2 *)((uint8_t *)&StshSizes[i] + 2) = 0x7fff;
    *(undefined2 *)(&StshSizes[i]) = 0xffff;
  }
  return;
}



/* 474a:0aa7 */
uint32_t * __cdecl16far stshFilesize(uint32_t *__return_storage_ptr__,uint16_t file_id,...)

{
  long *__return_storage_ptr___00;
  long *plVar1;
  undefined2 in_DX;
  int unaff_DI;
  
  if ((*(int *)((int)__return_storage_ptr__ * 4 + 0xaa2) == 0x7fff) &&
     (*(int *)((int)__return_storage_ptr__ * 4 + 0xaa0) == -1)) {
    __return_storage_ptr___00 =
         (long *)open_wait_unlock_and_disk
                           ((char *)*(undefined2 *)((int)__return_storage_ptr__ * 4),
                            ((undefined2 *)((int)__return_storage_ptr__ * 4))[1]);
    plVar1 = filelength(__return_storage_ptr___00,unaff_DI);
    *(undefined2 *)((int)__return_storage_ptr__ * 4 + 0xaa2) = in_DX;
    *(undefined2 *)((int)__return_storage_ptr__ * 4 + 0xaa0) = (uint16_t)plVar1;
    close((int)__return_storage_ptr___00);
  }
  return (uint32_t *)*(undefined2 *)((int)__return_storage_ptr__ * 4 + 0xaa0);
}


/* 474a:0b26 */

uint16_t __cdecl16far randBelow(uint16_t n,...)

{
  uint8_t rnd;
  
  rnd = rand8();
  return rnd * n >> 8;
}



/* 474a:0b38 */

int __cdecl16far creat_wait_unlock_and_disk(char *path,...)

{
  uint16_t handle;
  uint16_t ioerr;
  int unaff_DI;
  uint in_stack_00000006;
  
  do {
    ioErrorHndlrInstall();
    handle = _creat((char *)(ulong)in_stack_00000006,unaff_DI);
    ioerr = ioErrorHndlrUninstall();
    if (handle != 0xffff) {
      return handle;
    }
  } while ((ioerr == 0x20) || (ioerr == 0x37));
  return -1;
}



/* 474a:0b70 */

int __cdecl16far open_wait_unlock_and_disk(char *filename,...)

{
  uint16_t handle;
  uint16_t ioerr;
  undefined2 in_stack_00000006;
  
  do {
    ioErrorHndlrInstall();
    handle = _open((char *)CONCAT22(in_stack_00000006,filename),0x41);
    ioerr = ioErrorHndlrUninstall();
    if (handle != 0xffff) {
      return handle;
    }
  } while ((ioerr == 0x20) || (ioerr == 0x37));
  return -1;
}



/* 474a:0ba8 */

void __cdecl16far
fmReadIntoHimem(char *filename,uint16_t filenameSeg,int skipLo,int skipHi,char useEms,
               uint16_t limitLo,uint16_t limitHi,...)

{
  long *__return_storage_ptr__;
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
  
  __return_storage_ptr__ = (long *)open_wait_unlock_and_disk(filename);
  if (-1 < (int)__return_storage_ptr__) {
    plStack_a = filelength(__return_storage_ptr__,unaff_DI);
    uStack_8 = in_DX;
    if (skipLo != 0 || skipHi != 0) {
      lseek((int)__return_storage_ptr__,(ulong)(uint)skipHi,unaff_DI);
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
      plVar1 = (long *)read((int)__return_storage_ptr__,(long *)CONCAT22(plVar1,plStack_4),unaff_DI)
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
    close((int)__return_storage_ptr__);
    handle.seg = (uint16_t)plStack_4;
    handle.ofs = (uint16_t)pvStack_6;
    stshFree(handle);
  }
  return;
}



/* 474a:0cf8 */

stg_tmp_t * __cdecl16far stshLoadGfx(far_t handle,...)

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
      *(undefined2 far *)((uint8_t far *)MK_FP(Stsh_2410_47f6.seg, Stsh_2410_47f6.ofs) +  9) = handle.ofs;
      Stsh_2410_47f6.seg = in_DX;
      Stsh_2410_47f6.ofs = handle.ofs;
      uVar5 = in_DX;
    }
    if (*(int *)(((stg_tmp_t *)handle.ofs)->cmap + 0x11) == 0 &&
        *(int *)(((stg_tmp_t *)handle.ofs)->cmap + 0x13) == 0) {
      pfVar4 = fmMalloc(*(far_t **)(((stg_tmp_t *)handle.ofs)->cmap + 5),
                        CONCAT22(in_stack_0000fff6,
                                 *(undefined2 *)(((stg_tmp_t *)handle.ofs)->cmap + 7)));
      *(uint16_t *)(((stg_tmp_t *)handle.ofs)->cmap + 0x13) = uVar5;
      *(far_t **)(((stg_tmp_t *)handle.ofs)->cmap + 0x11) = pfVar4;
      if (*(int *)(((stg_tmp_t *)handle.ofs)->cmap + 0x11) == 0 &&
          *(int *)(((stg_tmp_t *)handle.ofs)->cmap + 0x13) == 0) {
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0x47);
      }
      stshSeek(StshStrongDatHnd,
               CONCAT22(*(undefined2 *)(((stg_tmp_t *)handle.ofs)->cmap + 3),
                        *(undefined2 *)(((stg_tmp_t *)handle.ofs)->cmap + 1)));
      stshRead();
    }
    handle.ofs = *(uint16_t *)(((stg_tmp_t *)handle.ofs)->cmap + 0x11);
  }
  return (stg_tmp_t *)handle.ofs;
}



/* 474a:0e9b */
undefined1 * __cdecl16far stash_loadFromStrongDat(far_t entry,...)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  far_t *pfVar4;
  far_t *pfVar5;
  uint16_t in_DX;
  uint16_t uVar6;
  uint16_t uVar7;
  undefined1 in_stack_0000fff0;
  undefined1 in_stack_0000fff1;
  
  entry.ofs = (uint16_t)ovr_mkp((uint32_t *)entry.ofs,entry.seg);
  entry.seg = in_DX;
  pfVar4 = (far_t *)entry.ofs;
  if (*(char *)MK_FP(entry.seg, entry.ofs) == '\0') {
    uVar6 = in_DX;
    pfVar4 = fmMalloc((far_t *)*(undefined2 *)((int)&((far_t *)(entry.ofs + 4))->ofs + 1),
                      CONCAT13(in_stack_0000fff1,
                               CONCAT12(in_stack_0000fff0,
                                        *(undefined2 *)((int)&((far_t *)(entry.ofs + 4))->seg + 1)))
                     );
    if (pfVar4 == (far_t *)0x0 && uVar6 == 0) {
      pfVar4 = (far_t *)0x0;
    }
    else {
      if (*(int *)((int)&((far_t *)(entry.ofs + 0x10))->ofs + 1) == 0 &&
          *(int *)((int)&((far_t *)(entry.ofs + 0x10))->seg + 1) == 0) {
        uVar7 = uVar6;
        stshSeek(StshStrongDatHnd,
                 CONCAT22(*(undefined2 *)((int)&((far_t *)entry.ofs)->seg + 1),
                          *(undefined2 *)((int)&((far_t *)entry.ofs)->ofs + 1)));
        stshRead();
        pfVar5 = ovr_heapMalloc((far_t *)*(undefined2 *)((int)&((far_t *)(entry.ofs + 4))->ofs + 1),
                                CONCAT13(in_stack_0000fff1,
                                         CONCAT12(in_stack_0000fff0,
                                                  *(undefined2 *)
                                                   ((int)&((far_t *)(entry.ofs + 4))->seg + 1))));
        *(uint16_t *)((int)&((far_t *)(entry.ofs + 0x10))->seg + 1) = uVar7;
        *(undefined2 *)((int)&((far_t *)(entry.ofs + 0x10))->ofs + 1) =(uint16_t) pfVar5;
        if (*(int *)((int)&((far_t *)(entry.ofs + 0x10))->ofs + 1) == 0 &&
            *(int *)((int)&((far_t *)(entry.ofs + 0x10))->seg + 1) == 0) {
          bVar3 = false;
        }
        else {
          memcpy((char *)CONCAT22(*(undefined2 *)((int)&((far_t *)(entry.ofs + 0x10))->seg + 1),
                                  (char *)*(undefined2 *)
                                           ((int)&((far_t *)(entry.ofs + 0x10))->ofs + 1)),
                 (char *)CONCAT22(uVar6,pfVar4),*(word *)((int)&((far_t *)(entry.ofs + 4))->ofs + 1)
                );
          bVar3 = true;
        }
      }
      else {
        memcpy((char *)CONCAT22(uVar6,pfVar4),
               (char *)CONCAT22(*(undefined2 *)((int)&((far_t *)(entry.ofs + 0x10))->seg + 1),
                                (char *)*(undefined2 *)
                                         ((int)&((far_t *)(entry.ofs + 0x10))->ofs + 1)),
               *(word *)((int)&((far_t *)(entry.ofs + 4))->ofs + 1));
        bVar3 = true;
        uVar7 = uVar6;
      }
      if (bVar3) {
        pfVar5 = (far_t *)ovr_mkp((uint32_t *)Stsh_2410_47f6.ofs,Stsh_2410_47f6.seg);
        if ((uVar7 != in_DX) || (pfVar5 != (far_t *)entry.ofs)) {
          iVar1 = *(int *)((int)&((far_t *)(entry.ofs + 0xc))->seg + 1);
          iVar2 = *(int *)((int)&((far_t *)(entry.ofs + 0xc))->ofs + 1);
          uVar6 = *(uint16_t *)((int)&((far_t *)(entry.ofs + 8))->seg + 1);
          uVar7 = *(uint16_t *)((int)&((far_t *)(entry.ofs + 8))->ofs + 1);
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
          *(uint16_t *)((int)&((far_t *)(entry.ofs + 0xc))->seg + 1) = Stsh_2410_47f6.seg;
          *(uint16_t *)((int)&((far_t *)(entry.ofs + 0xc))->ofs + 1) = uVar6;
          *(undefined2 *)((int)&((far_t *)(entry.ofs + 8))->seg + 1) = 0;
          *(undefined2 *)((int)&((far_t *)(entry.ofs + 8))->ofs + 1) = 0;
          *(uint16_t far *)((uint8_t far *)MK_FP(Stsh_2410_47f6.seg, Stsh_2410_47f6.ofs) +  0xb) = in_DX;
          *(undefined2 far *)((uint8_t far *)MK_FP(Stsh_2410_47f6.seg, Stsh_2410_47f6.ofs) +  9) = entry.ofs;
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

stg_tmp_t * __cdecl16far stash_usesStExit(stg_tmp_t *gfxListOfs,...)

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
                    CONCAT22(*(undefined2 *)(gfxListOfs->cmap + 3),
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

int __cdecl16far fmMallocRecover(void)

{
  uint16_t *puVar1;
  bool bVar2;
  undefined1 extraout_AH;
  int iVar3;
  undefined1 uVar4;
  byte extraout_AH_00;
  far_t handle;
  uint16_t uStack_6;
  uint16_t uStack_4;
  
  bVar2 = ovr_fmFreeAudio(0);
  if (bVar2) {
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
        *(undefined2 *)(uStack_6 + 0x13) = 0;
        *(undefined2 *)(uStack_6 + 0x11) = 0;
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
    bVar2 = ovr_fmFreeAudio(1);
    if (bVar2) {
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
  undefined1 extraout_AH;
  long *plVar3;
  uint uVar4;
  undefined1 uVar5;
  byte extraout_AH_00;
  int iVar6;
  undefined2 unaff_SI;
  uint uVar7;
  long *unaff_DI;
  uint uVar8;
  undefined2 uVar9;
  far_t handle;
  far_t handle_00;
  uint16_t in_stack_0000ffee;
  uint8_t in_stack_0000fff0;
  undefined1 uStack_f;
  uint uStack_a;
  uint16_t uStack_6;
  uint16_t uStack_4;
  
  bVar2 = ovr_fmFreeAudio(0);
  uVar5 = extraout_AH;
  if (!bVar2) {
    iVar6 = (*(uint16_t *)((uint8_t *)&(nbytes) + 2)) + (uint)(0xffec < (uint)nbytes);
    plVar3 = LXRSH_at_(unaff_DI,CONCAT22(in_stack_0000ffee,unaff_SI),in_stack_0000fff0);
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
    uStack_a = 0xffff;
    HeapPtr = 0xffff;
    bVar2 = false;
    uStack_4 = StshCtPtr2.seg;
    uStack_6 = StshCtPtr2.ofs;
    uVar4 = 0xffff;
    while (uStack_6 != 0 || uStack_4 != 0) {
      uVar7 = uVar4;
      if (*(int *)(uStack_6 + 0x11) != 0 || *(int *)(uStack_6 + 0x13) != 0) {
        if (*(uint *)(uStack_6 + 0x13) < uVar8) {
          handle.seg = *(uint16_t *)(uStack_6 + 0x13);
          handle.ofs = *(uint16_t *)(uStack_6 + 0x11);
          stshFree(handle);
          *(undefined2 *)(uStack_6 + 0x13) = 0;
          *(undefined2 *)(uStack_6 + 0x11) = 0;
          bVar2 = true;
        }
        else {
          if (*(uint *)(uStack_6 + 0x13) < uVar4) {
            uVar7 = *(uint *)(uStack_6 + 0x13);
            in_stack_0000fff0 = (uint8_t)uStack_4;
            uStack_f = (undefined1)(uStack_4 >> 8);
            in_stack_0000ffee = uStack_6;
            uStack_a = uVar4;
          }
          if (*(uint *)(uStack_6 + 0x13) < HeapPtr) {
            HeapPtr = *(uint *)(uStack_6 + 0x13);
          }
        }
      }
      puVar1 = (uint16_t *)(uStack_6 + 0xb);
      uStack_6 = *(uint16_t *)(uStack_6 + 9);
      uVar4 = uVar7;
      uStack_4 = *puVar1;
    }
    uVar5 = 0;
    if (!bVar2) {
      if (uVar4 == 0xffff) {
        bVar2 = ovr_fmFreeAudio(1);
        if (bVar2) {
          return CONCAT11(extraout_AH_00,1);
        }
        if (audioBusy == '\0') {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0x14);
        }
        return (uint)extraout_AH_00 << 8;
      }
      uVar9 = (undefined2)(CONCAT13(uStack_f,CONCAT12(in_stack_0000fff0,in_stack_0000ffee)) >> 0x10)
      ;
      handle_00.seg = *(uint16_t *)(in_stack_0000ffee + 0x13);
      handle_00.ofs = *(uint16_t *)(in_stack_0000ffee + 0x11);
      stshFree(handle_00);
      uVar9 = (undefined2)(CONCAT13(uStack_f,CONCAT12(in_stack_0000fff0,in_stack_0000ffee)) >> 0x10)
      ;
      *(undefined2 *)(in_stack_0000ffee + 0x13) = 0;
      *(undefined2 *)(in_stack_0000ffee + 0x11) = 0;
      uVar5 = 0x24;
      HeapPtr = uStack_a;
    }
  }
  return CONCAT11(uVar5,1);
}


