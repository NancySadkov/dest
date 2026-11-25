"""Find returns that are stale-AH artifacts.

Ghidra renders a function whose exits write only AL as if the high byte mattered, producing
returns like

    return uVar2 & 0xff00;
    return CONCAT11(bVar3,1);
    return (uint)bVar3 << 8;
    return entityIndex * 0x37 & 0xff00;

These are not booleans or bytes - they return whatever happened to be in AH, or an arbitrary
shifted value.  The correct recovery is the value AL actually receives, and the way to confirm it
is the disassembly: count `mov al,imm` at each exit.

This script lists the candidate sites only; deciding each one needs its disassembly.
"""

import glob
import io
import os
import re

TREE = 'src/decompiled'
FUNC = re.compile(r'^[A-Za-z_][\w \*]*\b(\w+)\s*\([^;]*\)\s*$')

PATTERNS = [
    ('& 0xff00', re.compile(r'return\s+[^;]*&\s*0xff00\b')),
    ('CONCAT11(..,1)', re.compile(r'return\s+CONCAT11\([^;]*\)\s*;')),
    ('<< 8', re.compile(r'return\s+[^;]*<<\s*8\b')),
]


def is_comment(text):
    s = text.strip()
    return s.startswith(('/*', '*', '//', '`')) or s.count('`') >= 2


def functions(path):
    lines = io.open(path, encoding='latin-1').read().split('\n')
    out = []
    i = 0
    while i < len(lines):
        m = FUNC.match(lines[i])
        if m:
            k = i + 1
            while k < len(lines) and lines[k].strip() == '':
                k += 1
            if k < len(lines) and lines[k].strip() == '{':
                d, j = 0, k
                while j < len(lines):
                    d += lines[j].count('{') - lines[j].count('}')
                    if d == 0 and lines[j].strip() == '}':
                        break
                    j += 1
                out.append((m.group(1), i, j, lines))
                i = j + 1
                continue
        i += 1
    return out


rows = []
for path in sorted(glob.glob(os.path.join(TREE, '*.c'))):
    mod = os.path.basename(path)
    if mod in ('crtl.c', 'ovl.c', 'ovr_stubs.c', 'st_stubs.c'):
        continue
    for name, a, b, lines in functions(path):
        hits = []
        for x in range(a, b + 1):
            if is_comment(lines[x]):
                continue
            for label, rx in PATTERNS:
                if rx.search(lines[x]):
                    hits.append((x + 1, label, lines[x].strip()[:62]))
        if hits:
            rows.append((mod, name, a + 1, hits))

print('%-20s %-30s %-6s %s' % ('module', 'function', 'line', 'pattern / text'))
total = 0
for mod, name, ln, hits in rows:
    for hl, label, text in hits:
        total += 1
        print('%-20s %-30s %-6d %-15s %s' % (mod, name, hl, label, text))
print()
print('candidate returns: %d   in %d functions' % (total, len(rows)))
