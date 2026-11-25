"""List dirty functions (which still contain register/stack/label anomalies) that are small.

These are the ones naming cannot fix: their bodies still carry unaff_*/in_*/extraout_*
pseudo-variables, in_stack_/stk_ slots, code_r0x/L_ labels or swi().  A body that is small
enough to read end to end against the disassembly is the right starting point, because the
whole control flow can be re-derived in one pass.
"""

import glob
import io
import os
import re

TREE = 'src/decompiled'
FUNC = re.compile(r'^[A-Za-z_][\w \*]*\b(\w+)\s*\([^;]*\)\s*$')
MASS = re.compile(r'[iusbc]Var[_0-9]|p[iusbc]Var[_0-9]|[iusc]Stack_|bStack_')
ANOM = re.compile(r'unaff_[A-Z]|\bin_[A-Z]|extraout_|in_stack_|\bstk_[0-9a-f]|\bcode_r0x'
                  r'|\bL_[A-Z0-9_]+|\bswi\s*\(')


def functions(path):
    lines = io.open(path, encoding='latin-1').read().split('\n')
    out = []
    i = 0
    while i < len(lines):
        s = lines[i]
        if (s.rstrip().endswith(')') and '(' in s and ';' not in s
                and not s.startswith((' ', '\t', '/*', '//', '#'))):
            head = s.partition('(')[0]
            toks = re.findall(r'[A-Za-z_]\w*', head)
            if toks:
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
                    if j < len(lines):
                        out.append((toks[-1], i, j, lines))
                        i = j + 1
                        continue
        i += 1
    return out


rows = []
for path in sorted(glob.glob(os.path.join(TREE, '*.c'))):
    mod = os.path.basename(path)
    if mod in ('crtl.c', 'ovl.c'):
        continue
    for name, a, b, lines in functions(path):
        body = '\n'.join(lines[a:b + 1])
        nlines = b - a + 1
        if nlines > 70:
            continue
        mass = len(MASS.findall(body))
        nanom = len(ANOM.findall(body))
        if nanom == 0 or mass < 25:
            continue
        kinds = set()
        for m in ANOM.finditer(body):
            kinds.add(re.sub(r'[0-9a-fA-F]+$', '', m.group(0)))
        rows.append((mass, nanom, nlines, mod, name, a + 1, ','.join(sorted(kinds))[:44]))

rows.sort(reverse=True)
print('%-5s %-5s %-5s %-20s %-32s %-6s %s'
      % ('mass', 'anom', 'lines', 'module', 'function', 'line', 'anomaly kinds'))
for r in rows[:22]:
    print('%-5d %-5d %-5d %-20s %-32s %-6d %s' % r)
print()
print('small dirty candidates:', len(rows))
