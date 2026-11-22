uint16_t __cdecl16far setvbuf(FILE *stream,uint8_t *bufOfs,uint mode)

{
  uint8_t *puVar1;
  uint8_t *puVar2;
  FILE *pFVar3;
  uint16_t uVar4;
  uint in_stack_0000000e;
  
  uVar4 = (uint16_t)((ulong)stream >> 0x10);
  pFVar3 = (FILE *)stream;
  if ((((FILE *)pFVar3->token == pFVar3) && ((int)mode < 3)) && (in_stack_0000000e < 0x8000)) {
    if ((_stdoutStarted == 0) && (pFVar3 == (FILE *)(_streams + 1))) {
      _stdoutStarted = 1;
    }
    else if ((_stdinStarted == 0) && (pFVar3 == (FILE *)_streams)) {
      _stdinStarted = 1;
    }
    if (stream->level != 0) {
      fseek((uint16_t *)stream,0,0,1);
    }
    if ((pFVar3->flags & 4) != 0) {
      farfree((uint16_t)pFVar3->buffer,*(uint16_t *)((int)&pFVar3->buffer + 2));
    }
    pFVar3->flags = pFVar3->flags & 0xfff3;
    pFVar3->bsize = 0;
    puVar2 = &pFVar3->hold;
    *(uint16_t *)((int)&pFVar3->buffer + 2) = uVar4;
    *(uint8_t **)&pFVar3->buffer = puVar2;
    *(uint16_t *)((int)&pFVar3->curp + 2) = uVar4;
    *(uint8_t **)&pFVar3->curp = puVar2;
    if ((mode != 2) && (in_stack_0000000e != 0)) {
      _exitbuf.seg = 0x1000;
      _exitbuf.ofs = 0x2fe4;
      if (bufOfs == (uint8_t *)0x0) {
        puVar1 = (uint8_t *)malloc(0);   /* hand fix: size argument was lost by the decompiler */
        bufOfs = (uint8_t *)CONCAT22(puVar2,puVar1);
        if (puVar1 == (uint8_t *)0x0 && puVar2 == (uint8_t *)0x0) goto L_setvbuf_2B46;
        pFVar3->flags = pFVar3->flags | 4;
      }
      *(uint16_t *)((int)&pFVar3->curp + 2) = (*(uint16_t *)((uint8_t *)&(bufOfs) + 2));
      *(uint8_t **)&pFVar3->curp = (uint8_t *)bufOfs;
      *(uint16_t *)((int)&pFVar3->buffer + 2) = (*(uint16_t *)((uint8_t *)&(bufOfs) + 2));
      *(uint8_t **)&pFVar3->buffer = (uint8_t *)bufOfs;
      pFVar3->bsize = in_stack_0000000e;
      if (mode == 1) {
        pFVar3->flags = pFVar3->flags | 8;
      }
    }
    uVar4 = 0;
  }
  else {
L_setvbuf_2B46:
    uVar4 = 0xffff;
  }
  return uVar4;
}
