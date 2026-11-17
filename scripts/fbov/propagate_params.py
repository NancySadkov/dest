"""Propagate parameter names from call sites.

If a caller passes its own `param_N` straight into a callee's parameter that
already has a real name, the caller's parameter has the same role.  Only exact
`param_N` arguments count, and a name is applied only when at least two call
sites agree and none disagrees.

Usage: python scripts/fbov/propagate_params.py
"""
import collections
import csv
import glob
import io
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
EXPORT = os.path.join(ROOT, 'tmp', 'decompiled4')
AUTO = re.compile(r'^(param_\d+|in_stack_[0-9a-f]+|in_[A-Z]{2,3}_\w+|local_\w+|'
                  r'uVar\d+|iVar\d+|bVar\d+)$')


def parse_sigs():
    sigs = {}
    path = os.path.join(EXPORT, 'st_functions.h')
    for line in io.open(path, encoding='latin1'):
        line = line.strip()
        if not line.endswith(';') or '(' not in line:
            continue
        m = re.match(r'^(.*?)\b(\w+)\s*\(([^()]*)\)\s*;$', line)
        if not m:
            continue
        name = m.group(2)
        inner = m.group(3).strip()
        if not inner or inner == 'void':
            sigs[name] = []
            continue
        params = []
        for p in inner.split(','):
            p = p.strip()
            pm = re.search(r'(\w+)\s*$', p)
            params.append(pm.group(1) if pm else '')
        sigs[name] = params
    return sigs


def main():
    sigs = parse_sigs()
    addr = {}
    for r in csv.DictReader(io.open(os.path.join(EXPORT, 'index.tsv'),
                                    encoding='utf-8'), delimiter='\t'):
        addr.setdefault(r['name'], r['address'])

    votes = collections.defaultdict(collections.Counter)
    call = re.compile(r'\b(\w+)\s*\(([^()]*)\)')
    for path in glob.glob(os.path.join(EXPORT, '*.c')):
        if os.path.basename(path).startswith('st_'):
            continue
        text = io.open(path, encoding='latin1').read()
        # current function: last signature before the call
        funcs = [(m.start(), m.group(1)) for m in
                 re.finditer(r'^[A-Za-z_][\w \t\*]*\b(\w+)\s*\([^;]*\)\s*$', text, re.M)]
        for m in call.finditer(text):
            callee = m.group(1)
            if callee not in sigs or not sigs[callee]:
                continue
            args = [a.strip() for a in m.group(2).split(',')]
            if len(args) != len(sigs[callee]):
                continue
            caller = None
            for pos, name in funcs:
                if pos < m.start():
                    caller = name
                else:
                    break
            if caller is None or caller == callee:
                continue
            for i, (arg, cname) in enumerate(zip(args, sigs[callee])):
                am = re.fullmatch(r'param_(\d+)', arg)
                if not am:
                    continue
                idx = int(am.group(1)) - 1
                if AUTO.match(cname) or not cname:
                    continue
                votes[(caller, idx)][cname] += 1

    rows = []
    for (caller, idx), counter in votes.items():
        name, n = counter.most_common(1)[0]
        if n < 2 or len(counter) > 1:
            continue
        if caller not in addr:
            continue
        rows.append((addr[caller], idx, name, n))
    out = os.path.join(ROOT, 'tmp', 'param_renames.tsv')
    with io.open(out, 'w', encoding='utf-8', newline='') as f:
        for r in sorted(rows):
            f.write('%s\t%d\t%s\t%d\n' % r)
    print('candidates: %d -> %s' % (len(rows), out))


if __name__ == '__main__':
    sys.exit(main())
