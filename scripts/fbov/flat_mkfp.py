import glob, os
D = os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(
    os.path.abspath(__file__)))), 'tmp', 'flat')
n = 0
for p in glob.glob(os.path.join(D, 'ov_*.c')) + [os.path.join(D, 'main.c')]:
    s = open(p, encoding='ascii').read()
    o = s
    s = s.replace('MK_FP(0x1410,', 'MK_FP(__DS,')
    s = s.replace('MK_FP(0x280,', 'MK_FP(__DS,')
    if s != o:
        open(p, 'w', encoding='ascii', newline='').write(s)
        n += 1
print('rewrote', n, 'files')
