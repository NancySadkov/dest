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
  uint16_t uVar1;
  int fh;
  undefined2 unaff_SI;
  uint16_t in_stack_00000004;
  
  uVar1 = in_stack_00000004;
  fh = open_wait_unlock_and_disk
                 ((char *)CONCAT22(unaff_SI,(char *)((undefined2 *)(in_stack_00000004 * 4))[1]),
                  *(undefined2 *)(in_stack_00000004 * 4));
  ((int *)StshHandles)[uVar1] = fh;
  *(undefined2 *)((int)(long *)StshPtrs + uVar1 * 4 + 2) = 0;
  *(undefined2 *)((long *)StshPtrs + uVar1) = 0;
  return uVar1;
}



/* 474a:004e */

void __cdecl16far stshClose(uint16_t file_id,...)

{
  int iVar1;
  int in_stack_00000004;
  
  iVar1 = in_stack_00000004;
  if (((int *)StshHandles)[in_stack_00000004] != -1) {
    close(((int *)StshHandles)[in_stack_00000004]);
  }
  ((int *)StshHandles)[iVar1] = -1;
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
  uint16_t seg;
  uint32_t *puVar4;
  uint uVar5;
  uint16_t rdsz;
  uint16_t readed;
  uint uVar6;
  uint16_t ofs;
  uint32_t *unaff_SI;
  uint unaff_DI;
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
        puVar4 = ovr_mkp();
        xms_usesXmsHandle((int)puVar4,uVar5,uVar6,srcHi,countLo,uVar8);
        bVar7 = CARRY2((uint)StshPtrs[0],uStack_c);
        (*(uint16_t *)((uint8_t *)&(StshPtrs[0]))) = (uint)StshPtrs[0] + uStack_c;
        (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) = (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) + uStack_a + (uint)bVar7;
        uStack_10 = in_stack_0000000a - uStack_c;
        uStack_e = (in_stack_0000000c - uStack_a) - (uint)(in_stack_0000000a < uStack_c);
        puVar4 = LXURSH_at_(unaff_SI,_pbuf,in_stack_0000ffee);
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
          ofs = (uint)StshPtrs[0] - (uint)FMXmsHandle;
          seg = ((*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) - (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2))) -
                (uint)((uint)StshPtrs[0] < (uint)FMXmsHandle);
          uVar8 = ofs;
          uVar5 = uStack_c;
          lenHi = uStack_a;
          puVar4 = ovr_mkp(in_stack_00000008,ofs,seg,in_stack_00000006);
          ems_memmove1((uint16_t)puVar4,ofs,uVar8,seg,uVar5,lenHi);
          bVar7 = CARRY2((uint)StshPtrs[0],uStack_c);
          (*(uint16_t *)((uint8_t *)&(StshPtrs[0]))) = (uint)StshPtrs[0] + uStack_c;
          (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) = (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) + uStack_a + (uint)bVar7;
          bVar7 = uStack_10 < uStack_c;
          uStack_10 = uStack_10 - uStack_c;
          uStack_e = (uStack_e - uStack_a) - (uint)bVar7;
          puVar4 = LXURSH_at_(unaff_SI,_pbuf,in_stack_0000ffee);
          in_stack_00000008 = (uint32_t *)((int)puVar4 + (int)in_stack_00000008);
          in_stack_00000006 = (uint32_t *)((int)in_stack_00000006 + (uStack_c & 0xf));
        }
      }
      uVar5 = (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) +
              (uint)CARRY2((uint)FMXmsHandle,(uint)FMEmsHandle);
      if ((uVar5 <= (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2))) &&
         ((uVar5 != (*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)) ||
          ((uint)FMXmsHandle + (uint)FMEmsHandle <= (uint)StshPtrs[0])))) {
        lseek(StshHandles[0],(ulong)(*(uint16_t *)((uint8_t *)&(StshPtrs[0]) + 2)),unaff_DI);
      }
      if (uStack_10 == 0 && uStack_e == 0) {
        return uVar3 - in_stack_0000000a;
      }
    }
    fd = *(int *)((char *)"toymaker" + 7 + in_stack_00000004 * 2);
    puStack_14 = in_stack_00000008;
    while( true ) {
      if ((uStack_e == 0) && (uStack_10 == 0)) goto next_iteration;
      if ((uStack_e != 0) || (rdsz = uStack_10, 0xc000 < uStack_10)) {
        rdsz = 0xc000;
      }
      readed = read(fd,(uint32_t *)CONCAT22(rdsz,puStack_14),unaff_DI);
      if (readed != rdsz) break;
      bVar7 = uStack_10 < readed;
      uStack_10 = uStack_10 - readed;
      uStack_e = uStack_e - bVar7;
      ovr_mkp();
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
  int handle;
  uint uVar1;
  uint32_t *unaff_SI;
  uint16_t file_id;
  long *unaff_DI;
  uint32_t flen;
  uint16_t szlo;
  uint16_t szhi;
  
  _fmemset((void *)0xffff1ef4,0x440,(uint16_t)unaff_DI);
  _fmemset((void *)0x1ef4,0x220,(uint16_t)unaff_DI);
  for (file_id = 0; (int)file_id < 0x220; file_id = file_id + 1) {
    handle = open_wait_unlock_and_disk
                       ((char *)CONCAT22(unaff_DI,(char *)((undefined2 *)(file_id * 4))[1]),
                        *(undefined2 *)(file_id * 4));
    if (handle < 0) {
      szhi = 0;
      szlo = 0;
    }
    else {
      (*(uint16_t *)((uint8_t *)&(flen))) = filelength(unaff_DI,(int)unaff_SI);
      close(handle);
      szlo = (uint16_t)(long *)flen;
      szhi = (*(uint16_t *)((uint8_t *)&(flen) + 2));
    }
    *(uint16_t *)(file_id * 4 + 0xaa2) = szhi;
    *(uint16_t *)(file_id * 4 + 0xaa0) = szlo;
    *(undefined2 *)((int)(long *)StshPtrs + file_id * 4 + 2) = 0;
    *(undefined2 *)((long *)StshPtrs + file_id) = 0;
    (*(uint16_t *)((uint8_t *)&(flen) + 2)) = szhi;
  }
  (*(uint16_t *)((uint8_t *)&(FMXmsHandle))) = xms_init(unaff_SI);
  (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) = (*(uint16_t *)((uint8_t *)&(flen) + 2));
  (*(uint16_t *)((uint8_t *)&(FMEmsHandle))) = ems_init(unaff_SI);
  (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) = (*(uint16_t *)((uint8_t *)&(flen) + 2));
  if ((uint32_t *)FMXmsHandle != (uint32_t *)0x0 || (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) != 0) {
    if (((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)) <= (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2))) &&
       (((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)) < (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) ||
        ((uint32_t *)StshSizes[0] < (uint32_t *)FMXmsHandle)))) {
      stshInit_scan(CONCAT13((char)((*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)) >> 8),
                             CONCAT12((char)(*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2)),(uint32_t *)StshSizes[0])));
      (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) = (*(uint16_t *)((uint8_t *)&(StshSizes[0]) + 2));
      (*(uint16_t *)((uint8_t *)&(FMXmsHandle))) = (uint32_t *)StshSizes[0];
    }
    fmReadIntoHimem((char *)ZEXT24((*(uint16_t *)((uint8_t *)&(StshNames[0]) + 2))),0,0,(int)(uint32_t *)FMXmsHandle,
                    (char)(*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)),(uint16_t)unaff_DI,(uint16_t)unaff_SI,
                    (char *)StshNames[0],(char)(*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)));
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
      ems_realloc(CONCAT13((char)((*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) >> 8),
                           CONCAT12((char)(*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)),(uint32_t *)FMEmsHandle)));
    }
    fmReadIntoHimem((char *)CONCAT22((uint32_t *)FMXmsHandle,(*(uint16_t *)((uint8_t *)&(StshNames[0]) + 2))),(*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)),1
                    ,(int)(uint32_t *)FMEmsHandle,(char)(*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)),(uint16_t)unaff_DI,
                    (uint16_t)unaff_SI,(char *)StshNames[0],(char)(*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)));
  }
  return;
}



/* 474a:067b */

void __cdecl16far stshSeek(uint16_t fid,long ofs,...)

{
  int iVar1;
  uint uVar2;
  int unaff_SI;
  int in_stack_00000004;
  
  iVar1 = in_stack_00000004;
  if (in_stack_00000004 == 0) {
    uVar2 = (*(uint16_t *)((uint8_t *)&(FMEmsHandle) + 2)) + (*(uint16_t *)((uint8_t *)&(FMXmsHandle) + 2)) +
            (uint)CARRY2((uint)FMEmsHandle,(uint)FMXmsHandle);
    if ((uVar2 <= (uint)ofs) &&
       ((uVar2 != (uint)ofs || ((uint)FMEmsHandle + (uint)FMXmsHandle <= fid)))) {
      lseek(StshHandles[0],ofs & 0xffff,unaff_SI);
    }
  }
  else {
    lseek(*(int *)((char *)"toymaker" + 7 + in_stack_00000004 * 2),ofs & 0xffff,unaff_SI);
  }
  *(uint *)((int)&AgntAnms[0x53].maxDx + 1 + iVar1 * 4) = (uint)ofs;
  *(uint16_t *)((int)&AgntAnms[0x53].y + 1 + iVar1 * 4) = fid;
  return;
}



/* 474a:06fe */

uint32_t * __cdecl16far stshTell(uint32_t *__return_storage_ptr__,uint16_t file_id,...)

{
  int in_stack_00000004;
  
  return (uint32_t *)*(undefined2 *)((int)&AgntAnms[0x53].y + 1 + in_stack_00000004 * 4);
}



/* 474a:0718 */

void __cdecl16far stshFree(far_t handle,...)

{
  uint16_t unaff_BP;
  uint16_t in_stack_00000004;
  far_t ptr;
  
  if ((handle.ofs != StshBuf.seg) || (in_stack_00000004 != StshBuf.ofs)) {
    if (HeapReady == '\0') {
      farfree(in_stack_00000004,handle.ofs);
    }
    else {
      ptr.seg = unaff_BP;
      ptr.ofs = handle.ofs;
      ovr_heapFree(ptr,in_stack_00000004);
    }
  }
  return;
}



/* 474a:075a */

/* WARNING: Variable defined which should be unmapped: ofs */
/* WARNING: Variable defined which should be unmapped: seg */

void * __cdecl16far stshAlloc(uint32_t nbytes,...)

{
  far_t *pfVar1;
  uint uVar2;
  uint32_t r;
  uint32_t result;
  int in_stack_00000004;
  uint16_t ofs;
  uint16_t seg;
  uint32_t newbuf;
  
  if (((far_t *)nbytes == (far_t *)0x0) && (in_stack_00000004 == -0x5f1)) {
    (*(uint16_t *)((uint8_t *)&(r))) = (far_t *)StshBuf.ofs;
    if (StshBuf.ofs == 0 && StshBuf.seg == 0) {
      (*(uint16_t *)((uint8_t *)&(r))) = farmalloc((far_t *)0x0,(uint32_t)_ofs);
      StshBuf.ofs = (uint16_t)(far_t *)r;
      StshBuf.seg = (*(uint16_t *)((uint8_t *)&(r) + 2));
    }
  }
  else {
    ovr_fmFreeAudio();
    if (in_stack_00000004 == 0 && (far_t *)nbytes == (far_t *)0x0) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit();
    }
    do {
      if (HeapReady == '\0') {
        pfVar1 = farmalloc((far_t *)nbytes,(uint32_t)_ofs);
        _ofs = (far_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(r) + 2)),pfVar1);
      }
      else {
        pfVar1 = (far_t *)ovr_heapAlloc();
        _ofs = (far_t *)CONCAT22((*(uint16_t *)((uint8_t *)&(r) + 2)),pfVar1);
      }
      if ((ofs == 0 && seg == 0) &&
         (uVar2 = fmOutOfMemory(CONCAT22((far_t *)nbytes,in_stack_00000004)), (uVar2 & 0xff) == 0))
      {
        return (void *)0x0;
      }
    } while (ofs == 0 && seg == 0);
    (*(uint16_t *)((uint8_t *)&(r))) = (far_t *)ovr_mkp();
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
  uint32_t r;
  int in_stack_00000004;
  uint16_t in_stack_0000fffa;
  int iVar3;
  
  if (in_stack_00000004 == 0 && (int)oldblock == 0) {
    (*(uint16_t *)((uint8_t *)&(r))) = stshAlloc(CONCAT22(in_stack_0000fffa,(int)nbytes),(*(uint16_t *)((uint8_t *)&(oldblock) + 2)));
  }
  else {
    ovr_fmFreeAudio(in_stack_0000fffa,0);
    if ((*(uint16_t *)((uint8_t *)&(oldblock) + 2)) == 0 && (int)nbytes == 0) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit(in_stack_0000fffa,0x13);
    }
    do {
      if (HeapReady == '\0') {
        uVar1 = farrealloc(CONCAT22((int)oldblock,in_stack_00000004),
                           CONCAT22((int)nbytes,(*(uint16_t *)((uint8_t *)&(oldblock) + 2))));
        (*(uint16_t *)((uint8_t *)&(r))) = (long *)CONCAT11(extraout_AH,uVar1);
      }
      else {
        (*(uint16_t *)((uint8_t *)&(r))) = ovr_heapRealloc();
      }
      iVar3 = in_DX;
      if (((long *)r == (long *)0x0 && in_DX == 0) &&
         (uVar2 = fmOutOfMemory(CONCAT22((int)nbytes,(*(uint16_t *)((uint8_t *)&(oldblock) + 2)))), (uVar2 & 0xff) == 0)) {
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
  undefined2 in_DX;
  int in_stack_00000004;
  far_t *in_stack_0000fffa;
  
  ovr_fmFreeAudio((uint16_t)in_stack_0000fffa,0);
  if (in_stack_00000004 == 0 && __return_storage_ptr__ == (far_t *)0x0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit((int)in_stack_0000fffa,0x1c);
  }
  while( true ) {
    if (HeapReady == '\0') {
      pfVar1 = farmalloc(__return_storage_ptr__,(uint32_t)in_stack_0000fffa);
      in_stack_0000fffa = (far_t *)CONCAT22(in_DX,pfVar1);
    }
    else {
      pfVar1 = ovr_heapMalloc(__return_storage_ptr__,(uint32_t)in_stack_0000fffa,in_stack_00000004);
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
  uint8_t *puVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  undefined2 unaff_SS;
  char *in_stack_00000004;
  uint8_t *puVar5;
  uint8_t buf;
  int16_t iStack_8;
  uint16_t uStack_6;
  
  FMRingIndex = FMRingIndex + 1 & 7;
  uStack_6 = (int)&fmt + 2;
  iStack_8 = vsprintf((char *)CONCAT22(unaff_SS,&buf),
                      (char *)CONCAT22((char *)fmt,in_stack_00000004),uStack_6);
  puVar5 = &buf;
  iVar3 = iStack_8 + 1 >> 0xf;
  puVar1 = stshRealloc(CONCAT22(iStack_8 + 1,
                                *(undefined2 *)((int)&FMRingBuf[0].seg + (uint)FMRingIndex * 4)),
                       CONCAT22(puVar5,iVar3),((far_t *)FMRingBuf + FMRingIndex)->ofs);
                    /* Copy sprintfed string to dst */
  pcVar2 = strcpy((char *)CONCAT22(iVar3,puVar1),(char *)CONCAT22(unaff_SS,puVar5));
  uVar4 = (uint)FMRingIndex;
  *(int *)((int)&FMRingBuf[0].seg + uVar4 * 4) = iVar3;
  ((far_t *)FMRingBuf + uVar4)->ofs = (uint16_t)pcVar2;
  return (char *)((far_t *)FMRingBuf + FMRingIndex)->ofs;
}



/* 474a:09df */

char * __cdecl16far stsprintf(char *buf,char *fmt,char *arg1,...)

{
  char *in_stack_00000004;
  
  vsprintf((char *)CONCAT22((char *)buf,in_stack_00000004),(char *)CONCAT22((char *)fmt,(*(uint16_t *)((uint8_t *)&(buf) + 2))),
           (int)&fmt + 2);
  return in_stack_00000004;
}



/* 474a:0a10 */

/* WARNING: Variable defined which should be unmapped: i */

void __cdecl16far clean_ring_buffer(void)

{
  uint uVar1;
  uint16_t uStack_6;
  uint16_t uStack_4;
  uint8_t i;
  
  i = 0;
  while (i < 8) {
    if (((far_t *)FMRingBuf + i)->ofs != 0 || *(int *)((int)&FMRingBuf[0].seg + (uint)i * 4) != 0) {
      uVar1 = (uint)i;
      uStack_6 = *(uint16_t *)((int)&FMRingBuf[0].seg + uVar1 * 4);
      stshFree(_uStack_6,((far_t *)FMRingBuf + uVar1)->ofs);
    }
    *(undefined2 *)((int)&FMRingBuf[0].seg + (uint)i * 4) = 0;
    ((far_t *)FMRingBuf + i)->ofs = 0;
    i = i + 0x1;
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
    *(undefined2 *)(i * 4 + 0xaa2) = 0x7fff;
    *(undefined2 *)(i * 4 + 0xaa0) = 0xffff;
  }
  return;
}



/* 474a:0aa7 */

uint32_t * __cdecl16far stshFilesize(uint32_t *__return_storage_ptr__,uint16_t file_id,...)

{
  int iVar1;
  int handle;
  long *plVar2;
  undefined2 in_DX;
  int iVar3;
  int unaff_SI;
  undefined2 unaff_DI;
  int in_stack_00000004;
  char *filename;
  
  iVar1 = in_stack_00000004;
  if ((*(int *)(in_stack_00000004 * 4 + 0xaa2) == 0x7fff) &&
     (*(int *)(in_stack_00000004 * 4 + 0xaa0) == -1)) {
    filename = (char *)CONCAT22(unaff_DI,(char *)((undefined2 *)(in_stack_00000004 * 4))[1]);
    handle = open_wait_unlock_and_disk(filename,*(undefined2 *)(in_stack_00000004 * 4));
    plVar2 = filelength((long *)((ulong)filename >> 0x10),unaff_SI);
    iVar3 = iVar1 * 4;
    *(undefined2 *)(iVar3 + 0xaa2) = in_DX;
    *(undefined2 *)(iVar3 + 0xaa0) = plVar2;
    close(handle);
  }
  return (uint32_t *)*(undefined2 *)(iVar1 * 4 + 0xaa0);
}



/* 474a:0b26 */

uint16_t __cdecl16far randBelow(uint16_t n,...)

{
  uint8_t rnd;
  int in_stack_00000004;
  
  rnd = rand8();
  return (uint)rnd * in_stack_00000004 >> 8;
}



/* 474a:0b38 */

int __cdecl16far creat_wait_unlock_and_disk(char *path,...)

{
  uint16_t handle;
  uint16_t ioerr;
  int unaff_DI;
  undefined2 in_stack_00000004;
  
  do {
    ioErrorHndlrInstall();
    handle = _creat((char *)((ulong)path & 0xffff),unaff_DI);
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
  char *in_stack_00000004;
  
  do {
    ioErrorHndlrInstall();
    handle = _open((char *)CONCAT22((char *)filename,in_stack_00000004),0x41);
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
  far_t handle;
  int handle_00;
  long *plVar1;
  uint in_DX;
  int unaff_SI;
  long *unaff_DI;
  bool bVar2;
  undefined2 in_stack_00000004;
  uint uStack_e;
  uint16_t uStack_c;
  long *plStack_a;
  uint uStack_8;
  void *pvStack_6;
  long *plStack_4;
  
  handle_00 = open_wait_unlock_and_disk
                        ((char *)CONCAT22(unaff_DI,(char *)filename),in_stack_00000004);
  if (-1 < handle_00) {
    plStack_a = filelength(unaff_DI,unaff_SI);
    uStack_8 = in_DX;
    if ((*(uint16_t *)((uint8_t *)&(filename) + 2)) != (long *)0x0 || filenameSeg != 0) {
      lseek(handle_00,(ulong)filenameSeg,(int)unaff_DI);
      bVar2 = plStack_a < (*(uint16_t *)((uint8_t *)&(filename) + 2));
      plStack_a = (long *)((int)plStack_a - (int)(*(uint16_t *)((uint8_t *)&(filename) + 2)));
      uStack_8 = (in_DX - filenameSeg) - (uint)bVar2;
    }
    if ((_useEms <= uStack_8) && ((uStack_8 != _useEms || ((uint)skipHi < plStack_a)))) {
      uStack_8 = _useEms;
      plStack_a = (long *)skipHi;
    }
    plStack_4 = plStack_a;
    if (((int)uStack_8 < 0) || (((int)uStack_8 < 1 && (plStack_a < (long *)0xc001)))) {
      pvStack_6 = stshAlloc(CONCAT22(unaff_DI,uStack_8),plStack_a);
    }
    else {
      pvStack_6 = stshAlloc(ZEXT24(unaff_DI) << 0x10,0xc000);
    }
    uStack_c = 0;
    uStack_e = 0;
    for (; plStack_a != (long *)0x0 || uStack_8 != 0;
        plStack_a = (long *)((int)plStack_a - (int)plVar1)) {
      plVar1 = plStack_a;
      if ((-1 < (int)uStack_8) && ((0 < (int)uStack_8 || ((long *)0xc000 < plStack_a)))) {
        plVar1 = (long *)0xc000;
      }
      plVar1 = (long *)read(handle_00,(long *)CONCAT22(plVar1,plStack_4),(uint)unaff_DI);
      if ((plVar1 == (long *)0x0) || (plVar1 == (long *)0xffff)) break;
      if ((char)skipLo == '\0') {
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
    close(handle_00);
    handle.seg = (uint16_t)unaff_DI;
    handle.ofs = (uint16_t)plStack_4;
    stshFree(handle,pvStack_6);
  }
  return;
}



/* 474a:0cf8 */

stg_tmp_t * __cdecl16far stshLoadGfx(far_t handle,...)

{
  uint16_t uVar1;
  stg_tmp_t *psVar2;
  far_t *pfVar3;
  uint16_t in_DX;
  uint16_t uVar4;
  stg_tmp_t *in_stack_00000004;
  uint16_t in_stack_0000fff6;
  uint16_t in_stack_0000fff8;
  
  in_stack_00000004 =
       (stg_tmp_t *)
       ovr_mkp((uint32_t *)handle.ofs,in_stack_0000fff6,in_stack_0000fff8,in_stack_00000004);
  if (((stg_tmp_t *)CONCAT22(in_DX,in_stack_00000004))->cmap[0] == 0x0) {
    uVar4 = in_DX;
    psVar2 = (stg_tmp_t *)
             ovr_mkp((uint32_t *)Stsh_2410_47f6.seg,in_stack_0000fff6,in_stack_0000fff8,
                     Stsh_2410_47f6.ofs);
    if ((uVar4 != in_DX) || (psVar2 != in_stack_00000004)) {
      in_stack_0000fff8 = *(uint16_t *)(in_stack_00000004->cmap + 0xf);
      in_stack_0000fff6 = *(uint16_t *)(in_stack_00000004->cmap + 0xd);
      uVar4 = *(uint16_t *)(in_stack_00000004->cmap + 0xb);
      uVar1 = *(uint16_t *)(in_stack_00000004->cmap + 9);
      if (uVar1 != 0 || uVar4 != 0) {
        *(uint16_t *)(uVar1 + 0xf) = in_stack_0000fff8;
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
      *(uint16_t *)(in_stack_00000004->cmap + 0xf) = Stsh_2410_47f6.seg;
      *(uint16_t *)(in_stack_00000004->cmap + 0xd) = uVar4;
      (in_stack_00000004->cmap + 0xb)[0] = 0x0;
      (in_stack_00000004->cmap + 0xb)[1] = 0x0;
      (in_stack_00000004->cmap + 9)[0] = 0x0;
      (in_stack_00000004->cmap + 9)[1] = 0x0;
      *(uint16_t *)(Stsh_2410_47f6.ofs + 0xb) = in_DX;
      *(uint16_t *)(Stsh_2410_47f6.ofs + 9) = (uint16_t)in_stack_00000004;
      Stsh_2410_47f6.seg = in_DX;
      Stsh_2410_47f6.ofs = (uint16_t)in_stack_00000004;
      uVar4 = in_DX;
    }
    if (*(int *)(in_stack_00000004->cmap + 0x11) == 0 &&
        *(int *)(in_stack_00000004->cmap + 0x13) == 0) {
      pfVar3 = fmMalloc(*(far_t **)(in_stack_00000004->cmap + 7),
                        CONCAT22(in_stack_0000fff8,in_stack_0000fff6));
      *(uint16_t *)(in_stack_00000004->cmap + 0x13) = uVar4;
      *(far_t **)(in_stack_00000004->cmap + 0x11) = pfVar3;
      if (*(int *)(in_stack_00000004->cmap + 0x11) == 0 &&
          *(int *)(in_stack_00000004->cmap + 0x13) == 0) {
                    /* WARNING: Subroutine does not return */
        ovr_stExit(in_stack_0000fff6,0x47);
      }
      stshSeek(*(uint16_t *)(in_stack_00000004->cmap + 1),
               CONCAT22(in_stack_0000fff6,*(undefined2 *)(in_stack_00000004->cmap + 3)),
               StshStrongDatHnd);
      stshRead();
    }
    in_stack_00000004 = *(stg_tmp_t **)(in_stack_00000004->cmap + 0x11);
  }
  return in_stack_00000004;
}



/* 474a:0e9b */

/* Loads an archive entry from strong.dat into a heap block and caches it. */

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
  far_t *in_stack_00000004;
  undefined1 in_stack_0000fff0;
  undefined1 in_stack_0000fff1;
  undefined2 in_stack_0000fff2;
  
  pfVar4 = (far_t *)ovr_mkp();
  if ((char)((far_t *)CONCAT22(in_DX,pfVar4))->ofs == '\0') {
    uVar6 = in_DX;
    in_stack_00000004 = pfVar4;
    pfVar4 = fmMalloc((far_t *)*(undefined2 *)((int)&pfVar4[1].seg + 1),
                      CONCAT22(in_stack_0000fff2,CONCAT11(in_stack_0000fff1,in_stack_0000fff0)));
    if (pfVar4 == (far_t *)0x0 && uVar6 == 0) {
      pfVar4 = (far_t *)0x0;
    }
    else {
      if (*(int *)((int)&in_stack_00000004[4].ofs + 1) == 0 &&
          *(int *)((int)&in_stack_00000004[4].seg + 1) == 0) {
        uVar7 = uVar6;
        stshSeek();
        stshRead();
        pfVar5 = ovr_heapMalloc();
        *(uint16_t *)((int)&in_stack_00000004[4].seg + 1) = uVar7;
        *(undefined2 *)((int)&in_stack_00000004[4].ofs + 1) = pfVar5;
        if (*(int *)((int)&in_stack_00000004[4].ofs + 1) == 0 &&
            *(int *)((int)&in_stack_00000004[4].seg + 1) == 0) {
          bVar3 = false;
        }
        else {
          memcpy((char *)CONCAT22(*(undefined2 *)((int)&in_stack_00000004[4].seg + 1),
                                  (char *)*(undefined2 *)((int)&in_stack_00000004[4].ofs + 1)),
                 (char *)CONCAT22(uVar6,pfVar4),*(word *)((int)&in_stack_00000004[1].ofs + 1));
          bVar3 = true;
        }
      }
      else {
        memcpy((char *)CONCAT22(uVar6,pfVar4),
               (char *)CONCAT22(*(undefined2 *)((int)&in_stack_00000004[4].seg + 1),
                                (char *)*(undefined2 *)((int)&in_stack_00000004[4].ofs + 1)),
               *(word *)((int)&in_stack_00000004[1].ofs + 1));
        bVar3 = true;
        uVar7 = uVar6;
      }
      if ((bVar3) &&
         ((pfVar5 = (far_t *)ovr_mkp(), uVar7 != in_DX || (pfVar5 != in_stack_00000004)))) {
        iVar1 = *(int *)((int)&in_stack_00000004[3].seg + 1);
        iVar2 = *(int *)((int)&in_stack_00000004[3].ofs + 1);
        uVar6 = *(uint16_t *)((int)&in_stack_00000004[2].seg + 1);
        uVar7 = *(uint16_t *)((int)&in_stack_00000004[2].ofs + 1);
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
        *(uint16_t *)((int)&in_stack_00000004[3].seg + 1) = Stsh_2410_47f6.seg;
        *(uint16_t *)((int)&in_stack_00000004[3].ofs + 1) = uVar6;
        *(undefined2 *)((int)&in_stack_00000004[2].seg + 1) = 0;
        *(undefined2 *)((int)&in_stack_00000004[2].ofs + 1) = 0;
        *(uint16_t *)(Stsh_2410_47f6.ofs + 0xb) = in_DX;
        *(uint16_t *)(Stsh_2410_47f6.ofs + 9) = (uint16_t)in_stack_00000004;
        Stsh_2410_47f6.seg = in_DX;
        Stsh_2410_47f6.ofs = (uint16_t)in_stack_00000004;
      }
    }
  }
  return (undefined1 *)pfVar4;
}



/* 474a:10ac */

/* [R4] calls ovr_stExit */

stg_tmp_t * __cdecl16far stash_usesStExit(stg_tmp_t *gfxListOfs,...)

{
  uint8_t *puVar1;
  uint16_t unaff_SI;
  uint uVar2;
  stg_tmp_t *in_stack_00000004;
  far_t handle;
  
  if (in_stack_00000004 == (stg_tmp_t *)0x0 && (stg_tmp_t *)gfxListOfs == (stg_tmp_t *)0x0) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit();
  }
  if (((stg_tmp_t *)CONCAT22((stg_tmp_t *)gfxListOfs,in_stack_00000004))->cmap[0] == 0x0) {
    handle.seg = unaff_SI;
    handle.ofs = (uint16_t)(stg_tmp_t *)gfxListOfs;
    in_stack_00000004 = stshLoadGfx(handle,in_stack_00000004->cmap + (uint)(*(uint8_t *)((uint8_t *)&(gfxListOfs) + 2)) * 0x15);
  }
  else {
    for (uVar2 = 0; uVar2 < (*(uint8_t *)((uint8_t *)&(gfxListOfs) + 2)); uVar2 = uVar2 + 1) {
      if (in_stack_00000004 == (stg_tmp_t *)0x0 && (stg_tmp_t *)gfxListOfs == (stg_tmp_t *)0x0) {
                    /* WARNING: Subroutine does not return */
        ovr_stExit();
      }
      puVar1 = in_stack_00000004->cmap;
      in_stack_00000004 = *(stg_tmp_t **)(in_stack_00000004->cmap + 1);
      (*(uint16_t *)((uint8_t *)&(gfxListOfs))) = *(stg_tmp_t **)(puVar1 + 3);
    }
    if (in_stack_00000004 == (stg_tmp_t *)0x0 && (stg_tmp_t *)gfxListOfs == (stg_tmp_t *)0x0) {
                    /* WARNING: Subroutine does not return */
      ovr_stExit();
    }
  }
  return in_stack_00000004;
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
  uint16_t unaff_SI;
  far_t handle;
  uint16_t uStack_6;
  uint16_t uStack_4;
  
  bVar2 = ovr_fmFreeAudio();
  if (bVar2) {
    iVar3 = CONCAT11(extraout_AH,1);
  }
  else {
    uStack_4 = StshCtPtr2.seg;
    uStack_6 = StshCtPtr2.ofs;
    while (uStack_6 != 0 || uStack_4 != 0) {
      if (*(int *)(uStack_6 + 0x11) != 0 || *(int *)(uStack_6 + 0x13) != 0) {
        handle.seg = unaff_SI;
        handle.ofs = *(uint16_t *)(uStack_6 + 0x13);
        stshFree(handle,*(undefined2 *)(uStack_6 + 0x11));
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
    bVar2 = ovr_fmFreeAudio();
    if (bVar2) {
      iVar3 = CONCAT11(extraout_AH_00,1);
    }
    else {
      if (audioBusy == '\0') {
                    /* WARNING: Subroutine does not return */
        ovr_stExit();
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
  uint16_t unaff_SI;
  far_t handle;
  undefined2 uStack_6;
  undefined2 uStack_4;
  
  handle.seg = unaff_SI;
  handle.ofs = 1;
  ovr_fmFreeAudio();
  uStack_4 = StshCtPtr2.seg;
  uStack_6 = StshCtPtr2.ofs;
  while (uStack_6 != 0 || uStack_4 != 0) {
    if (*(int *)(uStack_6 + 0x11) != 0 || *(int *)(uStack_6 + 0x13) != 0) {
      handle.ofs = *(uint16_t *)(uStack_6 + 0x13);
      stshFree(handle,*(undefined2 *)(uStack_6 + 0x11));
      iVar2 = *(int *)(uStack_6 + 0x13);
      *(undefined2 *)(uStack_6 + 0x13) = 0;
      *(undefined2 *)(uStack_6 + 0x11) = 0;
      if (HeapPtr == iVar2) {
        handle.ofs = 0x22f8;
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
  long *unaff_SI;
  uint uVar7;
  uint16_t unaff_DI;
  uint uVar8;
  undefined2 uVar9;
  far_t handle;
  far_t handle_00;
  long in_stack_0000ffee;
  uint8_t in_stack_0000fff2;
  uint uStack_a;
  uint16_t uStack_6;
  uint16_t uStack_4;
  
  bVar2 = ovr_fmFreeAudio();
  uVar5 = extraout_AH;
  if (!bVar2) {
    iVar6 = (*(uint16_t *)((uint8_t *)&(nbytes) + 2)) + (uint)(0xffec < (uint)nbytes);
    handle.seg = unaff_DI;
    handle.ofs = 0x22f8;
    plVar3 = LXRSH_at_(unaff_SI,in_stack_0000ffee,in_stack_0000fff2);
    uVar4 = (int)plVar3 + HeapPtr;
    iVar6 = iVar6 + (uint)CARRY2((uint)plVar3,HeapPtr);
    uVar8 = uVar4;
    if (iVar6 != 0) {
      uVar8 = 0xffff;
    }
    if (((MUSHandle.ofs != 0 || MUSHandle.seg != 0) && ((iVar6 != 0 || (MUSHandle.seg < uVar4)))) ||
       ((DIGHandle.ofs != 0 || DIGHandle.seg != 0 && ((iVar6 != 0 || (MUSHandle.seg < uVar4)))))) {
      handle.ofs = 1;
      ovr_fmFreeAudio();
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
          handle.ofs = *(uint16_t *)(uStack_6 + 0x13);
          stshFree(handle,*(undefined2 *)(uStack_6 + 0x11));
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
        bVar2 = ovr_fmFreeAudio();
        if (bVar2) {
          return CONCAT11(extraout_AH_00,1);
        }
        if (audioBusy == '\0') {
                    /* WARNING: Subroutine does not return */
          ovr_stExit();
        }
        return (uint)extraout_AH_00 << 8;
      }
      uVar9 = (undefined2)((ulong)in_stack_0000ffee >> 0x10);
      handle_00.seg = handle.seg;
      handle_00.ofs = *(uint16_t *)((int)in_stack_0000ffee + 0x13);
      stshFree(handle_00,*(undefined2 *)((int)in_stack_0000ffee + 0x11));
      uVar9 = (undefined2)((ulong)in_stack_0000ffee >> 0x10);
      *(undefined2 *)((int)in_stack_0000ffee + 0x13) = 0;
      *(undefined2 *)((int)in_stack_0000ffee + 0x11) = 0;
      uVar5 = 0x24;
      HeapPtr = uStack_a;
    }
  }
  return CONCAT11(uVar5,1);
}


