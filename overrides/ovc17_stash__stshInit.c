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
                           ((char *)*(uint16_t *)(file_id * 4),((uint16_t *)(file_id * 4))[1]);
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
    *(uint16_t *)((int)(long *)StshPtrs + file_id * 4 + 2) = 0;
    *(uint16_t *)((long *)StshPtrs + file_id) = 0;
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
