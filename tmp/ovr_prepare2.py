import io

p = 'src/decompiled/crtl.c'
t = io.open(p, encoding='latin-1').read()
anchor = '  /* __setargv is not recovered yet'
assert anchor in t

call = '''  /* The original's init table (_INITSTART.._INITEND) is reproduced byte for
     byte from the image, so its priority-1 far pointer still holds the
     ORIGINAL link-time segment 1403h - in our link that address is a VROOMM
     stub (INT 3Fh), not the prepare routine.  The same routine lives at
     offset 0D24h of our _OVRTEXT_ segment (REBUILT.MAP: 07BF), which the
     manager needs before the first overlay call. */
  {
    uint16_t ovrSeg = (uint16_t)(_psp + 0x10 + 0x7BF);

    ((void (far *)(void))MK_FP(ovrSeg, 0x0D24))();
  }

'''
t = t.replace(anchor, call + anchor, 1)
io.open(p, 'w', encoding='latin-1', newline='\n').write(t)
print('prepare call added at _OVRTEXT_:0D24')
