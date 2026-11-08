import os
ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
D = os.path.join(ROOT, 'tmp', 'flat')
objs = ['dglink.obj', 'mainpad.obj', 'main.obj', 'runtime.obj', 'stubs.obj',
        'origsegs.obj', 'ovltrap.obj']
open(os.path.join(D, 'link6.rsp'), 'w').write(
    '/m ' + ' '.join(objs) + ', flat.exe, flat.map\r\n')
lines = ['@echo off', 'mode con lines=50',
         'E:\\BIN\\TASM.EXE origsegs.asm > build.log',
         'E:\\BIN\\TASM.EXE ovltrap.asm >> build.log',
         'D:\\BIN\\TCC.EXE -ml -1 -G -O -ID:\\INCLUDE -IC:\\ -LD:\\LIB -w- -c stubs.c >> build.log',
         'D:\\BIN\\TLINK.EXE @link6.rsp >> build.log',
         'pause']
open(os.path.join(D, 'build12.bat'), 'w', newline='').write('\r\n'.join(lines) + '\r\n')
print('wrote link6.rsp and build12.bat')
