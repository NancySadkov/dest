import os
D = os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(
    os.path.abspath(__file__)))), 'tmp', 'flat')
asmfiles = [l.strip() for l in open(os.path.join(D, 'ovlist.txt')) if l.strip()]
ovobjs = [os.path.basename(p).replace('.obj', '.obj') for p in asmfiles]
objs = ['dglink.obj', 'mainpad.obj', 'main.obj', 'runtime.obj', 'stubs.obj',
        'origsegs.obj'] + ovobjs
open(os.path.join(D, 'link5.rsp'), 'w').write(
    '/m ' + ' '.join(objs) + ', flat.exe, flat.map\r\n')
lines = ['@echo off', 'mode con lines=50']
for p in asmfiles:
    lines.append('E:\\BIN\\TASM.EXE %s >> build.log' % p)
lines.append('D:\\BIN\\TCC.EXE -ml -1 -G -O -ID:\\INCLUDE -IC:\\ -LD:\\LIB -w- -c stubs.c >> build.log')
lines.append('D:\\BIN\\TLINK.EXE @link5.rsp >> build.log')
lines.append('pause')
open(os.path.join(D, 'build11.bat'), 'w', newline='').write('\r\n'.join(lines) + '\r\n')
print('objects', len(objs), 'asm files', len(asmfiles))
