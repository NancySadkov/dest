char * __cdecl16far agntCopyNthField(uint8_t filed_index,char *dst,char *src)

{
  int iVar1;
  char *pcVar2;
  bool bVar3;
  uint16_t len;
  uint16_t i;
  uint8_t in_stack_00000004;
  undefined1 in_stack_00000007;
  uint8_t j;
  uint8_t found;
  
  iVar1 = CONCAT11(in_stack_00000007,filed_index);
  j = 0x0;
  bVar3 = false;
  i = 0;
  while( true ) {
    in_stack_00000007 = (undefined1)((uint)iVar1 >> 8);
    filed_index = (uint8_t)iVar1;
    pcVar2 = (char *)src;
    len = strlen((char *)CONCAT22(pcVar2,(*(uint16_t *)((uint8_t *)&(dst) + 2))));
    iVar1 = CONCAT11(in_stack_00000007,filed_index);
    if (len <= i) break;
    if ((*(char *)((int)*(uint16_t *)((uint8_t *)&(dst) + 2) + i)) == ',') {
      j = j + 0x1;
      iVar1 = CONCAT11(in_stack_00000007,filed_index);
      if (bVar3) break;
    }
    else if (j == in_stack_00000004) {
      *(char *)((int)*(uint16_t *)((uint8_t *)&(dst) + 2) + (int)(char)CONCAT11(in_stack_00000007,filed_index)) = (*(char *)((int)*(uint16_t *)((uint8_t *)&(dst) + 2) + i));
      iVar1 = CONCAT11(in_stack_00000007,filed_index) + 1;
      bVar3 = true;
    }
    i = i + 1;
  }
  if (bVar3) {
    *(undefined1 *)CONCAT22((char *)dst,(undefined1 *)CONCAT11(in_stack_00000007,filed_index)) = 0;
  }
  else {
    strcpy((char *)CONCAT22((char *)dst,(char *)CONCAT11(in_stack_00000007,filed_index)),
           (char *)CONCAT22(pcVar2,(*(uint16_t *)((uint8_t *)&(dst) + 2))));
  }
  return (char *)CONCAT11(in_stack_00000007,filed_index);
}
