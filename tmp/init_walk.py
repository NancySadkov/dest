import io

p = 'src/decompiled/crtl.c'
t = io.open(p, encoding='latin-1').read()
anchor = '  /* __setargv is not recovered yet'
assert anchor in t

call = '''  /* The original walks the linker's init table (1000:01EA, over
     _INITSTART.._INITEND) and runs every entry in priority order, including the
     priority-1 far entry that prepares VROOMM.  We call the two plain
     initialisers directly, so the table is walked here for the priority-1
     entry only.  Entries are 6 bytes: priority at +0, far pointer at +2..+5. */
  {
    uint8_t *p = _INITSTART;

    while (p < _INITEND) {
      if (p[0] == 1) {
        uint16_t eofs = *(uint16_t *)(p + 2);
        uint16_t eseg = *(uint16_t *)(p + 4);

        ((void (far *)(void))MK_FP(eseg, eofs))();
        break;
      }
      p += 6;
    }
  }

'''
t = t.replace(anchor, call + anchor, 1)
io.open(p, 'w', encoding='latin-1', newline='\n').write(t)
print('init-table priority-1 call added')
