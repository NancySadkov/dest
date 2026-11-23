import io

p = 'src/decompiled/crtl.c'
t = io.open(p, encoding='latin-1').read()

anchor = '  /* __setargv is not recovered yet'
assert anchor in t
call = '''  /* VROOMM: the overlay call thunks are `INT 3Fh` stubs, so the manager must be
     prepared before the first overlay call (main calls ovr_init_game).  The
     original runs this as the priority-1 init-table entry, module OVRUSER,
     which the link places at 07BF:0D29 (REBUILT.MAP).  The segment is derived
     from the PSP at run time because 07BF is a link-time paragraph. */
  {
    uint16_t ovrSeg = (uint16_t)(_psp + 0x10 + 0x7BF);

    ((void (far *)(void))MK_FP(ovrSeg, 0x0D29))();
  }

'''
t = t.replace(anchor, call + anchor, 1)
io.open(p, 'w', encoding='latin-1', newline='\n').write(t)
print('OVRUSER prepare call added to startx')
