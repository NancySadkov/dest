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
