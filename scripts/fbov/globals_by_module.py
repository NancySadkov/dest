"""Group the auto-named globals by the modules that use them.

A global used by one or two modules is usually local state of that subsystem
and can be named from its uses there; one used everywhere is game state and
needs cross-module evidence.

Usage: python scripts/fbov/globals_by_module.py
"""
import collections
import csv
import glob
import io
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def main():
    audit = sys.argv[1] if len(sys.argv) > 1 else \
        os.path.join(ROOT, 'tmp', 'auditn5', 'naming_globals.tsv')
    export = os.path.join(ROOT, 'tmp', 'decompiled4')
    out = sys.argv[2] if len(sys.argv) > 2 else \
        os.path.join(ROOT, 'tmp', 'globals_by_module.tsv')

    names = {}
    for r in csv.DictReader(io.open(audit, encoding='utf-8'), delimiter='\t'):
        names[r['name']] = r

    use = collections.defaultdict(collections.Counter)
    pat = re.compile(r'\b(%s)\b' % '|'.join(re.escape(n) for n in names))
    for path in sorted(glob.glob(os.path.join(export, '*.c'))):
        mod = os.path.basename(path)[:-2]
        if mod.startswith('st_'):
            continue
        for line in io.open(path, encoding='latin1'):
            for m in set(pat.findall(line)):
                use[m][mod] += 1

    rows = []
    for n, r in names.items():
        mods = use[n]
        rows.append((len(mods), sum(mods.values()), n, r['type'],
                     r['address'], ','.join(m for m, _ in mods.most_common())))
    rows.sort(key=lambda x: (x[0], -x[1]))

    with io.open(out, 'w', encoding='utf-8', newline='') as f:
        f.write('modules\trefs\tname\ttype\taddress\twhere\n')
        for row in rows:
            f.write('\t'.join(str(x) for x in row) + '\n')
    print('wrote %d globals to %s' % (len(rows), out))
    single = sum(1 for r in rows if r[0] == 1)
    print('used by a single module: %d' % single)


if __name__ == '__main__':
    sys.exit(main())
