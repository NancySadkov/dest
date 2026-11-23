"""Second transform: the stshStoreFile argument is the RLE result's segment.

Original (init_assets1 7A57):

  003e CALLF ovr_stshRleType2        ; DX:AX = far pointer
  0046 PUSH DX / PUSH AX             ; the WHOLE far pointer is the 2nd argument
  0048 CALLF ovr_stshStoreFile

so the argument's segment is `ovr_stshRleType2`'s returned DX.  Ghidra modelled
that as `uVarN = in_DX` (or seeded it with the dead 0x195d) *before* the call.
The capture has to happen right after the call, which inline asm can do.

This applies the change to the first chain in ovc46_assets.c only (entries
0x201/0x202) as a controlled test.
"""
import io
import re

p = 'src/decompiled/ovc46_assets.c'
t = io.open(p, encoding='latin-1').read()

# 1. drop the premature seed of uVar3 and capture DX after the first RLE call
old1 = """    uVar3 = in_DX;
    pfVar2 = ovr_stshRleType2((far_t *)(&lbmTmp->aptr)->ofs,pixels,126,110,176,0,-6,(int16_t)unaff_SI,0,0);
    BldGfxNormal[0x201].ofs = stsh_store((uint8_t *)pfVar2, (uint16_t)uVar3, &stshSegTmp);
    uVar4 = 0x195d;"""
new1 = """    pfVar2 = ovr_stshRleType2((far_t *)(&lbmTmp->aptr)->ofs,pixels,126,110,176,0,-6,(int16_t)unaff_SI,0,0);
    asm { mov uVar3,dx };            /* segment of pfVar2, from the RLE call */
    BldGfxNormal[0x201].ofs = stsh_store((uint8_t *)pfVar2, (uint16_t)uVar3, &stshSegTmp);"""
assert old1 in t, 'first chain not found exactly'
t = t.replace(old1, new1, 1)

# 2. same for the second element: capture after its own RLE call
old2 = """    pfVar2 = ovr_stshRleType2((far_t *)(&lbmTmp->aptr)->ofs,pixels_00,126,201,176,0,-6,(int16_t)unaff_SI,0,0);
    BldGfxNormal[0x202].ofs = stsh_store((uint8_t *)pfVar2, (uint16_t)uVar4, &stshSegTmp);
    uVar3 = 0x195d;"""
new2 = """    pfVar2 = ovr_stshRleType2((far_t *)(&lbmTmp->aptr)->ofs,pixels_00,126,201,176,0,-6,(int16_t)unaff_SI,0,0);
    asm { mov uVar4,dx };
    BldGfxNormal[0x202].ofs = stsh_store((uint8_t *)pfVar2, (uint16_t)uVar4, &stshSegTmp);"""
assert old2 in t, 'second chain element not found exactly'
t = t.replace(old2, new2, 1)

io.open(p, 'w', encoding='latin-1', newline='\n').write(t)
print('first chain converted')
