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
  uint16_t pbuf;
  uint32_t *puStack_14;
  uint8_t in_stack_0000ffee;
  uint uStack_10;
  uint uStack_e;
  uint uStack_c;
  uint16_t uStack_a;
  uint32_t snbytes;
  
  uVar3 = in_stack_0000000a;
  uVar5 = *(uint *)((int)(long *)StshPtrs + in_stack_00000004 * 4 + 2);
  uVar6 = *(uint *)(in_stack_00000004 * 4 + 0xaa2);
  if ((uVar5 < uVar6) ||
     ((uVar5 == uVar6 &&
      (*(uint *)((long *)StshPtrs + in_stack_00000004) < *(uint *)(in_stack_00000004 * 4 + 0xaa0))))
     ) {
    uVar6 = in_stack_0000000c + *(int *)((int)(long *)StshPtrs + in_stack_00000004 * 4 + 2) +
            (uint)CARRY2(in_stack_0000000a,*(uint *)((long *)StshPtrs + in_stack_00000004));
    uVar5 = *(uint *)(in_stack_00000004 * 4 + 0xaa2);
    if ((uVar5 <= uVar6) &&
       ((uVar5 < uVar6 ||
        (*(uint *)(in_stack_00000004 * 4 + 0xaa0) <
         in_stack_0000000a + *(uint *)((long *)StshPtrs + in_stack_00000004))))) {
      uVar5 = *(uint *)(in_stack_00000004 * 4 + 0xaa0);
      puVar1 = (uint *)((int)&AgntAnms[0x53].y + 1 + in_stack_00000004 * 4);
      in_stack_0000000a = uVar5 - *puVar1;
      in_stack_0000000c =
           (*(int *)(in_stack_00000004 * 4 + 0xaa2) -
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
        puVar4 = LXURSH_at_(unaff_DI,_pbuf,in_stack_0000ffee);
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
          puVar4 = LXURSH_at_(unaff_DI,_pbuf,in_stack_0000ffee);
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
    fd = *(int *)((char *)"toymaker" + 7 + in_stack_00000004 * 2);
    puStack_14 = in_stack_00000008;
    pbuf = (uint16_t)in_stack_00000006;
    while( true ) {
      if ((uStack_e == 0) && (uStack_10 == 0)) goto next_iteration;
      if ((uStack_e != 0) || (rdsz = uStack_10, 0xc000 < uStack_10)) {
        rdsz = 0xc000;
      }
      readed = read(fd,(void *)pbuf,(uint)puStack_14);
      if (readed != rdsz) break;
      bVar7 = uStack_10 < readed;
      uStack_10 = uStack_10 - readed;
      uStack_e = uStack_e - bVar7;
      pbuf = (uint16_t)ovr_mkp((uint32_t *)(pbuf + readed),(uint16_t)puStack_14,(uint16_t)unaff_DI);
      puVar1 = (uint *)((int)&AgntAnms[0x53].y + 1 + in_stack_00000004 * 4);
      uVar5 = *puVar1;
      *puVar1 = *puVar1 + readed;
      piVar2 = (int *)((int)&AgntAnms[0x53].maxDx + 1 + in_stack_00000004 * 4);
      *piVar2 = *piVar2 + (uint)CARRY2(uVar5,readed);
      puStack_14 = in_stack_00000006;
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
  
  _fmemset((int *)StshHandles,0x1ef4,0xffff);
  _fmemset((uint8_t *)StshBytes,0x1ef4,0);
  for (file_id = 0; (int)file_id < 0x220; file_id = file_id + 1) {
    __return_storage_ptr__ = (long *)open_wait_unlock_and_disk((char *)*(undefined2 *)(file_id * 4))
    ;
    if ((int)__return_storage_ptr__ < 0) {
      szhi = 0;
      szlo = 0;
    }
    else {
      (*(uint16_t *)((uint8_t *)&(flen))) = filelength(__return_storage_ptr__,(int)unaff_DI);
      close((int)__return_storage_ptr__);
      szlo = (uint16_t)(long *)flen;
      szhi = (*(uint16_t *)((uint8_t *)&(flen) + 2));
    }
    *(uint16_t *)(file_id * 4 + 0xaa2) = szhi;
    *(uint16_t *)(file_id * 4 + 0xaa0) = szlo;
    *(undefined2 *)((int)(long *)StshPtrs + file_id * 4 + 2) = 0;
    *(undefined2 *)((long *)StshPtrs + file_id) = 0;
    (*(uint16_t *)((uint8_t *)&(flen) + 2)) = szhi;
  }
  (*(uint16_t *)((uint8_t *)&(FMXmsHandle))) = xms_init(unaff_DI);
  (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) = (*(uint16_t *)((uint8_t *)&(flen) + 2));
  (*(uint16_t *)((uint8_t *)&(FMEmsHandle))) = ems_init(unaff_DI);
  (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) = (*(uint16_t *)((uint8_t *)&(flen) + 2));
  if ((uint32_t *)FMXmsHandle != (uint32_t *)0x0 || (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) != 0) {
    if (((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)) <= (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2))) &&
       (((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)) < (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) ||
        ((uint32_t *)StshSizes[0] < (uint32_t *)FMXmsHandle)))) {
      stshInit_scan((uint32_t)CONCAT22((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)),(uint32_t *)StshSizes[0]));
      (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) = (*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2));
      (*(uint16_t *)((uint8_t *)&(FMXmsHandle))) = (uint32_t *)StshSizes[0];
    }
    fmReadIntoHimem((char *)StshNames[0],(*(uint16_t *)((uint8_t *)&(StshNames[0]) + 2)),0,0,'\0',
                    (uint16_t)(uint32_t *)FMXmsHandle,(*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)));
  }
  if ((((uint32_t *)FMEmsHandle == (uint32_t *)0x0 && (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) == 0) ||
      ((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)) < (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)))) ||
     (((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)) <= (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) &&
      ((uint32_t *)StshSizes[0] <= (uint32_t *)FMXmsHandle)))) {
    if ((uint32_t *)FMEmsHandle != (uint32_t *)0x0 || (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) != 0) {
      ems_realloc(0);
    }
    (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) = 0;
    (*(uint16_t *)((uint8_t *)&(FMEmsHandle))) = (uint32_t *)0x0;
  }
  else {
    uVar1 = (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
            (uint)CARRY2((uint)(uint32_t *)FMXmsHandle,(uint)(uint32_t *)FMEmsHandle);
    if (((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)) <= uVar1) &&
       (((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)) < uVar1 ||
        ((uint32_t *)StshSizes[0] <
         (uint32_t *)((int)(uint32_t *)FMXmsHandle + (int)(uint32_t *)FMEmsHandle))))) {
      (*(uint16_t *)((uint8_t *)&(FMEmsHandle))) = (uint32_t *)((int)(uint32_t *)StshSizes[0] - (int)(uint32_t *)FMXmsHandle)
      ;
      (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) =
           ((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)) - (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2))) -
           (uint)((uint32_t *)StshSizes[0] < (uint32_t *)FMXmsHandle);
      ems_realloc((uint32_t)CONCAT22((*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)),(uint32_t *)FMEmsHandle));
    }
    fmReadIntoHimem((char *)StshNames[0],(*(uint16_t *)((uint8_t *)&(StshNames[0]) + 2)),(int)(uint32_t *)FMXmsHandle,
                    (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)),'\x01',(uint16_t)(uint32_t *)FMEmsHandle,(*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)));
  }
  return;
}



/* 474a:067b */

void __cdecl16far stshSeek(uint16_t fid,long ofs)

{
  uint uVar1;
  int unaff_SI;
  uint in_stack_00000006;
  
  if (fid == 0) {
    uVar1 = (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) +
            (uint)CARRY2((uint)FMEmsHandle,(uint)FMXmsHandle);
    if ((uVar1 <= (uint)ofs) &&
       ((uVar1 != (uint)ofs || ((uint)FMEmsHandle + (uint)FMXmsHandle <= in_stack_00000006)))) {
      lseek(StshHandles[0],ofs & 0xffff,unaff_SI);
    }
  }
  else {
    lseek(*(int *)((char *)"toymaker" + 7 + fid * 2),ofs & 0xffff,unaff_SI);
  }
  *(uint *)((int)&AgntAnms[0x53].maxDx + 1 + fid * 4) = (uint)ofs;
  *(uint *)((int)&AgntAnms[0x53].y + 1 + fid * 4) = in_stack_00000006;
  return;
}



/* 474a:06fe */

uint32_t * __cdecl16far stshTell(uint32_t *__return_storage_ptr__,uint16_t file_id)

{
  return (uint32_t *)*(undefined2 *)((int)&AgntAnms[0x53].y + 1 + (int)__return_storage_ptr__ * 4);
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

/* WARNING: Variable defined which should be unmapped: ofs */

void * __cdecl16far stshAlloc(uint32_t nbytes)

{
  far_t *pfVar1;
  uint uVar2;
  uint32_t r;
  uint32_t result;
  uint16_t ofs;
  uint16_t seg;
  uint32_t newbuf;
  
  if (nbytes == 0xfa0f) {
    (*(uint16_t *)((uint8_t *)&(r))) = (far_t *)StshBuf.ofs;
    if (StshBuf.ofs == 0 && StshBuf.seg == 0) {
      (*(uint16_t *)((uint8_t *)&(r))) = farmalloc((far_t *)0xfa0f,(uint32_t)_ofs);
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
        pfVar1 = farmalloc((far_t *)nbytes,(uint32_t)_ofs);
        _ofs = (far_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(r) + 2)),pfVar1);
      }
      else {
        pfVar1 = (far_t *)ovr_heapAlloc((uint32_t *)(far_t *)nbytes,(uint32_t)_ofs);
        _ofs = (far_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(r) + 2)),pfVar1);
      }
      if ((ofs == 0 && seg == 0) && (uVar2 = fmOutOfMemory(nbytes), (uVar2 & 0xff) == 0)) {
        return (void *)0x0;
      }
    } while (ofs == 0 && seg == 0);
    (*(uint16_t *)((uint8_t *)&(r))) = (far_t *)ovr_mkp((uint32_t *)ofs,seg,ofs);
  }
  return (far_t *)r;
}



/* 474a:0822 */

uint8_t * __cdecl16far stshRealloc(uint32_t oldblock,uint32_t nbytes)

{
  uint8_t uVar1;
  long *plVar2;
  undefined1 extraout_AH;
  uint uVar3;
  undefined2 in_DX;
  uint32_t r;
  long *in_stack_0000fffa;
  
  if (oldblock == 0) {
    (*(uint16_t *)((uint8_t *)&(r))) = stshAlloc(nbytes);
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
        in_stack_0000fffa = (long *)CONCAT22(in_DX,(long *)CONCAT11(extraout_AH,uVar1));
      }
      else {
        plVar2 = ovr_heapRealloc((long *)oldblock,nbytes,(long)in_stack_0000fffa);
        in_stack_0000fffa = (long *)CONCAT22(in_DX,plVar2);
      }
      if (((long *)in_stack_0000fffa == (long *)0x0 && (int)((ulong)in_stack_0000fffa >> 0x10) == 0)
         && (uVar3 = fmOutOfMemory(nbytes), (uVar3 & 0xff) == 0)) {
        return (uint8_t *)0x0;
      }
      (*(uint16_t *)((uint8_t *)&(r))) = (long *)in_stack_0000fffa;
    } while ((long *)r == (long *)0x0 && (int)((ulong)in_stack_0000fffa >> 0x10) == 0);
  }
  return (uint8_t *)(long *)r;
}



/* 474a:08d1 */

far_t * __cdecl16far fmMalloc(far_t *__return_storage_ptr__,uint32_t nbytes)

{
  far_t *pfVar1;
  uint uVar2;
  undefined2 in_DX;
  int in_stack_00000006;
  far_t *in_stack_0000fffa;
  
  ovr_fmFreeAudio(0);
  if (__return_storage_ptr__ == (far_t *)0x0 && in_stack_00000006 == 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x1c);
  }
  while( true ) {
    if (HeapReady == '\0') {
      pfVar1 = farmalloc(__return_storage_ptr__,(uint32_t)in_stack_0000fffa);
      in_stack_0000fffa = (far_t *)CONCAT22(in_DX,pfVar1);
    }
    else {
      pfVar1 = ovr_heapMalloc(__return_storage_ptr__,(uint32_t)in_stack_0000fffa);
      in_stack_0000fffa = (far_t *)CONCAT22(in_DX,pfVar1);
    }
    if (((int)in_stack_0000fffa == 0 && (int)((ulong)in_stack_0000fffa >> 0x10) == 0) &&
       (uVar2 = fmMallocRecover(), (uVar2 & 0xff) == 0)) break;
    if ((far_t *)in_stack_0000fffa != (far_t *)0x0 || (int)((ulong)in_stack_0000fffa >> 0x10) != 0)
    {
      return (far_t *)in_stack_0000fffa;
    }
  }
  return (far_t *)0x0;
}



/* 474a:0953 */

/* vsprintfs string into a ring buffer */

char * __cdecl16far fmVsprintf(char *fmt,char *arg)

{
  uint8_t *dst;
  char *pcVar1;
  char *src;
  uint uVar2;
  undefined2 unaff_SS;
  uint8_t buf;
  int16_t iStack_8;
  undefined1 *puStack_6;
  
  FMRingIndex = FMRingIndex + 1 & 7;
  puStack_6 = &stack0x0008;
  iStack_8 = vsprintf((char *)CONCAT22(unaff_SS,&buf),(char *)CONCAT22(arg,fmt),(uint16_t)puStack_6)
  ;
  src = (char *)(iStack_8 + 1 >> 0xf);
  dst = stshRealloc(CONCAT22(*(undefined2 *)((int)&FMRingBuf[0].seg + (uint)FMRingIndex * 4),
                             ((far_t *)FMRingBuf + FMRingIndex)->ofs),(long)(iStack_8 + 1));
                    /* Copy sprintfed string to dst */
  pcVar1 = strcpy((char *)dst,src);
  uVar2 = (uint)FMRingIndex;
  *(undefined2 *)((int)&FMRingBuf[0].seg + uVar2 * 4) = src;
  ((far_t *)FMRingBuf + uVar2)->ofs = (uint16_t)pcVar1;
  return (char *)((far_t *)FMRingBuf + FMRingIndex)->ofs;
}



/* 474a:09df */

char * __cdecl16far stsprintf(char *buf,char *fmt,char *arg1)

{
  undefined2 in_stack_0000000a;
  
  vsprintf((char *)CONCAT22(fmt,buf),(char *)CONCAT22(in_stack_0000000a,arg1),(uint16_t)&stack0x000c
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
  uint16_t i;
  
  _fmemset((void *)0x880,0x1ef4,0);
  for (i = 0; (int)i < 0x220; i = i + 1) {
    *(undefined2 *)(i * 4 + 0xaa2) = 0x7fff;
    *(undefined2 *)(i * 4 + 0xaa0) = 0xffff;
  }
  return;
}



/* 474a:0aa7 */

uint32_t * __cdecl16far stshFilesize(uint32_t *__return_storage_ptr__,uint16_t file_id)

{
  long *__return_storage_ptr___00;
  long *plVar1;
  undefined2 in_DX;
  int unaff_DI;
  
  if ((*(int *)((int)__return_storage_ptr__ * 4 + 0xaa2) == 0x7fff) &&
     (*(int *)((int)__return_storage_ptr__ * 4 + 0xaa0) == -1)) {
    __return_storage_ptr___00 =
         (long *)open_wait_unlock_and_disk((char *)*(undefined2 *)((int)__return_storage_ptr__ * 4))
    ;
    plVar1 = filelength(__return_storage_ptr___00,unaff_DI);
    *(undefined2 *)((int)__return_storage_ptr__ * 4 + 0xaa2) = in_DX;
    *(undefined2 *)((int)__return_storage_ptr__ * 4 + 0xaa0) = plVar1;
    close((int)__return_storage_ptr___00);
  }
  return (uint32_t *)*(undefined2 *)((int)__return_storage_ptr__ * 4 + 0xaa0);
}



/* 474a:0b26 */

uint16_t __cdecl16far randBelow(uint16_t n)

{
  uint8_t rnd;
  
  rnd = rand8();
  return rnd * n >> 8;
}



/* 474a:0b38 */

int __cdecl16far creat_wait_unlock_and_disk(char *path)

{
  uint16_t handle;
  uint16_t ioerr;
  int in_stack_00000006;
  
  do {
    ioErrorHndlrInstall();
    handle = _creat(path,in_stack_00000006);
    ioerr = ioErrorHndlrUninstall();
    if (handle != 0xffff) {
      return handle;
    }
  } while ((ioerr == 0x20) || (ioerr == 0x37));
  return -1;
}



/* 474a:0b70 */

int __cdecl16far open_wait_unlock_and_disk(char *filename)

{
  uint16_t handle;
  uint16_t ioerr;
  int in_stack_00000006;
  
  do {
    ioErrorHndlrInstall();
    handle = _open(filename,in_stack_00000006);
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
               uint16_t limitLo,uint16_t limitHi)

{
  long *__return_storage_ptr__;
  long *countLo;
  uint in_DX;
  int unaff_DI;
  bool bVar1;
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
      bVar1 = plStack_a < (uint)skipLo;
      plStack_a = (long *)((int)plStack_a - skipLo);
      uStack_8 = (in_DX - skipHi) - (uint)bVar1;
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
    while (((plStack_a != (long *)0x0 || uStack_8 != 0 &&
            (countLo = (long *)read((int)__return_storage_ptr__,pvStack_6,(uint)plStack_4),
            countLo != (long *)0x0)) && (countLo != (long *)0xffff))) {
      if (useEms == '\0') {
        xms_usesXmsHandle2(uStack_e,uStack_c,(int)pvStack_6,(uint16_t)plStack_4,(uint)countLo,0);
      }
      else {
        ems_memmove2(uStack_e,uStack_c,(uint16_t)pvStack_6,(uint16_t)plStack_4,(uint16_t)countLo,0);
      }
      bVar1 = CARRY2(uStack_e,(uint)countLo);
      uStack_e = uStack_e + (int)countLo;
      uStack_c = uStack_c + bVar1;
      bVar1 = plStack_a < countLo;
      plStack_a = (long *)((int)plStack_a - (int)countLo);
      uStack_8 = uStack_8 - bVar1;
    }
    close((int)__return_storage_ptr__);
    handle.seg = (uint16_t)plStack_4;
    handle.ofs = (uint16_t)pvStack_6;
    stshFree(handle);
  }
  return;
}



/* 474a:0cf8 */

stg_tmp_t * __cdecl16far stshLoadGfx(far_t handle)

{
  uint16_t uVar1;
  stg_tmp_t *psVar2;
  far_t *pfVar3;
  uint16_t in_DX;
  uint16_t uVar4;
  uint16_t in_stack_0000fff6;
  int in_stack_0000fff8;
  
  handle.ofs = (uint16_t)ovr_mkp((uint32_t *)handle.ofs,handle.seg,in_stack_0000fff6);
  handle.seg = in_DX;
  if (*(char *)MK_FP(handle.seg, handle.ofs) == '\0') {
    uVar4 = in_DX;
    psVar2 = (stg_tmp_t *)
             ovr_mkp((uint32_t *)Stsh_2410_47f6.ofs,Stsh_2410_47f6.seg,in_stack_0000fff6);
    if ((uVar4 != in_DX) || (psVar2 != (stg_tmp_t *)handle.ofs)) {
      in_stack_0000fff8 = *(int *)(((stg_tmp_t *)handle.ofs)->cmap + 0xf);
      in_stack_0000fff6 = *(uint16_t *)(((stg_tmp_t *)handle.ofs)->cmap + 0xd);
      uVar4 = *(uint16_t *)(((stg_tmp_t *)handle.ofs)->cmap + 0xb);
      uVar1 = *(uint16_t *)(((stg_tmp_t *)handle.ofs)->cmap + 9);
      if (uVar1 != 0 || uVar4 != 0) {
        *(int *)(uVar1 + 0xf) = in_stack_0000fff8;
        *(uint16_t *)(uVar1 + 0xd) = in_stack_0000fff6;
      }
      if (in_stack_0000fff6 != 0 || in_stack_0000fff8 != 0) {
        *(uint16_t *)(in_stack_0000fff6 + 0xb) = uVar4;
        *(uint16_t *)(in_stack_0000fff6 + 9) = uVar1;
        uVar1 = StshCtPtr2.ofs;
        uVar4 = StshCtPtr2.seg;
      }
      StshCtPtr2.seg = uVar4;
      StshCtPtr2.ofs = uVar1;
      uVar4 = Stsh_2410_47f6.ofs;
      *(uint16_t *)(((stg_tmp_t *)handle.ofs)->cmap + 0xf) = Stsh_2410_47f6.seg;
      *(uint16_t *)(((stg_tmp_t *)handle.ofs)->cmap + 0xd) = uVar4;
      (((stg_tmp_t *)handle.ofs)->cmap + 0xb)[0] = 0x0;
      (((stg_tmp_t *)handle.ofs)->cmap + 0xb)[1] = 0x0;
      (((stg_tmp_t *)handle.ofs)->cmap + 9)[0] = 0x0;
      (((stg_tmp_t *)handle.ofs)->cmap + 9)[1] = 0x0;
      *(uint16_t *)(Stsh_2410_47f6.ofs + 0xb) = in_DX;
      *(undefined2 *)(Stsh_2410_47f6.ofs + 9) = handle.ofs;
      Stsh_2410_47f6.seg = in_DX;
      Stsh_2410_47f6.ofs = handle.ofs;
      uVar4 = in_DX;
    }
    if (*(int *)(((stg_tmp_t *)handle.ofs)->cmap + 0x11) == 0 &&
        *(int *)(((stg_tmp_t *)handle.ofs)->cmap + 0x13) == 0) {
      pfVar3 = fmMalloc(*(far_t **)(((stg_tmp_t *)handle.ofs)->cmap + 5),
                        CONCAT22(in_stack_0000fff8,in_stack_0000fff6));
      *(uint16_t *)(((stg_tmp_t *)handle.ofs)->cmap + 0x13) = uVar4;
      *(far_t **)(((stg_tmp_t *)handle.ofs)->cmap + 0x11) = pfVar3;
      if (*(int *)(((stg_tmp_t *)handle.ofs)->cmap + 0x11) == 0 &&
          *(int *)(((stg_tmp_t *)handle.ofs)->cmap + 0x13) == 0) {
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0x47);
      }
      stshSeek(StshStrongDatHnd,
               CONCAT22(in_stack_0000fff6,*(undefined2 *)(((stg_tmp_t *)handle.ofs)->cmap + 3)));
      stshRead();
    }
    handle.ofs = *(uint16_t *)(((stg_tmp_t *)handle.ofs)->cmap + 0x11);
  }
  return (stg_tmp_t *)handle.ofs;
}



/* 474a:0e9b */

/* Loads an archive entry from strong.dat into a heap block and caches it. */

undefined1 * __cdecl16far stash_loadFromStrongDat(far_t entry)

{
  int iVar1;
  int iVar2;
  far_t *pfVar3;
  far_t *pfVar4;
  uint16_t in_DX;
  uint16_t uVar5;
  uint16_t uVar6;
  undefined1 in_stack_0000fff0;
  undefined1 in_stack_0000fff1;
  char cVar7;
  undefined2 in_stack_0000fff2;
  
  entry.ofs = (uint16_t)
              ovr_mkp((uint32_t *)entry.ofs,entry.seg,CONCAT11(in_stack_0000fff1,in_stack_0000fff0))
  ;
  entry.seg = in_DX;
  pfVar3 = (far_t *)entry.ofs;
  if (*(char *)MK_FP(entry.seg, entry.ofs) == '\0') {
    uVar5 = in_DX;
    pfVar3 = fmMalloc((far_t *)*(undefined2 *)((int)&((far_t *)(entry.ofs + 4))->ofs + 1),
                      CONCAT22(in_stack_0000fff2,CONCAT11(in_stack_0000fff1,in_stack_0000fff0)));
    if (pfVar3 == (far_t *)0x0 && uVar5 == 0) {
      pfVar3 = (far_t *)0x0;
    }
    else {
      if (*(int *)((int)&((far_t *)(entry.ofs + 0x10))->ofs + 1) == 0 &&
          *(int *)((int)&((far_t *)(entry.ofs + 0x10))->seg + 1) == 0) {
        uVar6 = uVar5;
        stshSeek(StshStrongDatHnd,
                 CONCAT13(in_stack_0000fff1,
                          CONCAT12(in_stack_0000fff0,
                                   *(undefined2 *)((int)&((far_t *)entry.ofs)->seg + 1))));
        stshRead();
        pfVar4 = ovr_heapMalloc((far_t *)*(undefined2 *)((int)&((far_t *)(entry.ofs + 4))->ofs + 1),
                                CONCAT22(pfVar3,CONCAT11(in_stack_0000fff1,in_stack_0000fff0)));
        *(uint16_t *)((int)&((far_t *)(entry.ofs + 0x10))->seg + 1) = uVar6;
        *(undefined2 *)((int)&((far_t *)(entry.ofs + 0x10))->ofs + 1) = pfVar4;
        if (*(int *)((int)&((far_t *)(entry.ofs + 0x10))->ofs + 1) == 0 &&
            *(int *)((int)&((far_t *)(entry.ofs + 0x10))->seg + 1) == 0) {
          cVar7 = '\0';
        }
        else {
          memcpy((char *)CONCAT22(*(undefined2 *)((int)&((far_t *)(entry.ofs + 0x10))->seg + 1),
                                  (char *)*(undefined2 *)
                                           ((int)&((far_t *)(entry.ofs + 0x10))->ofs + 1)),
                 (char *)CONCAT22(uVar5,pfVar3),*(word *)((int)&((far_t *)(entry.ofs + 4))->ofs + 1)
                );
          cVar7 = '\x01';
        }
      }
      else {
        memcpy((char *)CONCAT22(uVar5,pfVar3),
               (char *)CONCAT22(*(undefined2 *)((int)&((far_t *)(entry.ofs + 0x10))->seg + 1),
                                (char *)*(undefined2 *)
                                         ((int)&((far_t *)(entry.ofs + 0x10))->ofs + 1)),
               *(word *)((int)&((far_t *)(entry.ofs + 4))->ofs + 1));
        cVar7 = '\x01';
        uVar6 = uVar5;
      }
      if (cVar7 != '\0') {
        pfVar4 = (far_t *)ovr_mkp((uint32_t *)Stsh_2410_47f6.ofs,Stsh_2410_47f6.seg,
                                  CONCAT11(cVar7,in_stack_0000fff0));
        if ((uVar6 != in_DX) || (pfVar4 != (far_t *)entry.ofs)) {
          iVar1 = *(int *)((int)&((far_t *)(entry.ofs + 0xc))->seg + 1);
          iVar2 = *(int *)((int)&((far_t *)(entry.ofs + 0xc))->ofs + 1);
          uVar5 = *(uint16_t *)((int)&((far_t *)(entry.ofs + 8))->seg + 1);
          uVar6 = *(uint16_t *)((int)&((far_t *)(entry.ofs + 8))->ofs + 1);
          if (uVar6 != 0 || uVar5 != 0) {
            *(int *)(uVar6 + 0xf) = iVar1;
            *(int *)(uVar6 + 0xd) = iVar2;
          }
          if (iVar2 != 0 || iVar1 != 0) {
            *(uint16_t *)(iVar2 + 0xb) = uVar5;
            *(uint16_t *)(iVar2 + 9) = uVar6;
            uVar6 = StshCtPtr2.ofs;
            uVar5 = StshCtPtr2.seg;
          }
          StshCtPtr2.seg = uVar5;
          StshCtPtr2.ofs = uVar6;
          uVar5 = Stsh_2410_47f6.ofs;
          *(uint16_t *)((int)&((far_t *)(entry.ofs + 0xc))->seg + 1) = Stsh_2410_47f6.seg;
          *(uint16_t *)((int)&((far_t *)(entry.ofs + 0xc))->ofs + 1) = uVar5;
          *(undefined2 *)((int)&((far_t *)(entry.ofs + 8))->seg + 1) = 0;
          *(undefined2 *)((int)&((far_t *)(entry.ofs + 8))->ofs + 1) = 0;
          *(uint16_t *)(Stsh_2410_47f6.ofs + 0xb) = in_DX;
          *(undefined2 *)(Stsh_2410_47f6.ofs + 9) = entry.ofs;
          Stsh_2410_47f6.seg = in_DX;
          Stsh_2410_47f6.ofs = entry.ofs;
        }
      }
    }
  }
  return (undefined1 *)pfVar3;
}



/* 474a:10ac */

/* [R4] calls ovr_stExit */

stg_tmp_t * __cdecl16far stash_usesStExit(stg_tmp_t *gfxListOfs,byte gfxListSeg)

{
  uint uVar1;
  undefined1 in_stack_00000007;
  byte in_stack_00000008;
  far_t handle;
  
  _gfxListOfs = (stg_tmp_t *)CONCAT13(in_stack_00000007,CONCAT12(gfxListSeg,gfxListOfs));
  if (gfxListOfs == (stg_tmp_t *)0x0 && _gfxListSeg == 0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0xb);
  }
  if (_gfxListOfs->cmap[0] == 0x0) {
    handle.seg = _gfxListSeg;
    handle.ofs = (uint16_t)(gfxListOfs->cmap + (uint)in_stack_00000008 * 0x15);
    gfxListOfs = stshLoadGfx(handle);
  }
  else {
    uVar1 = 0;
    while( true ) {
      if (in_stack_00000008 <= uVar1) break;
      if (gfxListOfs == (stg_tmp_t *)0x0 && _gfxListSeg == 0) {
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0xb);
      }
      uVar1 = uVar1 + 1;
      _gfxListOfs = (stg_tmp_t *)
                    CONCAT22(*(undefined2 *)(gfxListOfs->cmap + 3),
                             *(stg_tmp_t **)(gfxListOfs->cmap + 1));
    }
    if (gfxListOfs == (stg_tmp_t *)0x0 && _gfxListSeg == 0) {
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
  uint uVar7;
  long *unaff_DI;
  uint uVar8;
  undefined2 uVar9;
  far_t handle;
  far_t handle_00;
  long in_stack_0000ffee;
  uint8_t in_stack_0000fff2;
  uint uStack_a;
  uint16_t uStack_6;
  uint16_t uStack_4;
  
  bVar2 = ovr_fmFreeAudio(0);
  uVar5 = extraout_AH;
  if (!bVar2) {
    iVar6 = (*(uint16_t *)((uint8_t *)&(nbytes) + 2)) + (uint)(0xffec < (uint)nbytes);
    plVar3 = LXRSH_at_(unaff_DI,in_stack_0000ffee,in_stack_0000fff2);
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
            in_stack_0000ffee = CONCAT22(uStack_4,uStack_6);
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
      uVar9 = (undefined2)((ulong)in_stack_0000ffee >> 0x10);
      handle_00.seg = *(uint16_t *)((int)in_stack_0000ffee + 0x13);
      handle_00.ofs = *(uint16_t *)((int)in_stack_0000ffee + 0x11);
      stshFree(handle_00);
      uVar9 = (undefined2)((ulong)in_stack_0000ffee >> 0x10);
      *(undefined2 *)((int)in_stack_0000ffee + 0x13) = 0;
      *(undefined2 *)((int)in_stack_0000ffee + 0x11) = 0;
      uVar5 = 0x24;
      HeapPtr = uStack_a;
    }
  }
  return CONCAT11(uVar5,1);
}


