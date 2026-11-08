import os, re
ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
D = os.path.join(ROOT, 'tmp', 'flat')
defined = set()
for line in open(os.path.join(D, 'origsegs.asm'), encoding='ascii'):
    m = re.match(r'PUBLIC _(\w+)', line)
    if m:
        defined.add(m.group(1).lower())
src = open(os.path.join(ROOT, 'scripts', 'fbov', 'stubs.c'), encoding='ascii').read().splitlines()
resident = re.compile(r'^f_(1000|1403)_[0-9a-f]+$|^f_0000_2747$')
out = []
for line in src:
    m = re.search(r'\b(f_[0-9a-f]+_[0-9a-f]+|main)\s*\(', line)
    if m:
        name = m.group(1)
        if name == 'main' or name.lower() in defined or resident.match(name):
            continue
    out.append(line)
open(os.path.join(D, 'stubs.c'), 'w', encoding='ascii', newline='').write('\n'.join(out) + '\n')
print('stubs left', len(out), 'defined', len(defined))
