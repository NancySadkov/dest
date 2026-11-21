int __cdecl16far rle_blit_decode(byte *src,byte *dst,uint16_t sz,...)

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
