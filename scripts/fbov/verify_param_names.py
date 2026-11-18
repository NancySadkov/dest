"""Re-check that every renamed parameter's evidence is in its own function body.

The sweeps used to search an 80-line window, which can cross into the next
function.  This script extracts each body strictly between the `/* addr */`
markers and searches only inside it.

Usage: python scripts/fbov/verify_param_names.py
"""
import io
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
EXPORT = os.path.join(ROOT, 'tmp', 'decompiled4')
HDR = re.compile(r'^/\* ([0-9a-f]{4}:[0-9a-f]{4}) \*/')


def funcs(path):
    lines = io.open(path, encoding='latin1').read().splitlines()
    out = {}
    cur = None
    body = []
    for l in lines:
        m = HDR.match(l.strip())
        if m:
            if cur:
                out[cur] = '\n'.join(body)
            cur = m.group(1)
            body = []
        elif cur:
            body.append(l)
    if cur:
        out[cur] = '\n'.join(body)
    return out


CHECKS = [
    # entity-index batch
    ('ovc13.c', '3d16:1045', r'peVar3\[param_1\]'),
    ('ovc22.c', '5087:1532', r'peVar5\[param_1\]'),
    ('ovc15.c', '4207:0e17', r'peVar6\[param_1\]'),
    ('ovc24.c', '5943:0196', r'Entities \+ param_1'),
    ('ovc33_stats.c', '6386:1572', r'peVar4\[param_1\]|Entities \+ param_1'),
    ('ovc45.c', '77eb:16b2', r'Entities\)\[param_1\]'),
    # agent-index batch
    ('ovc15.c', '4207:1d87', r'param_1 \* 0x34'),
    ('ovc27.c', '5ded:0a05', r'param_1 \* 0x34'),
    ('ovc27.c', '5ded:0cc2', r'param_1 \* 0x34'),
    ('ovc33_stats.c', '6386:12b7', r'param_1 \* 0x34'),
    ('ovc33_stats.c', '6386:16a2', r'param_1 \* 0x34'),
    ('ovc33_stats.c', '6386:1837', r'param_1 \* 0x34'),
    ('ovc33_stats.c', '6386:1997', r'param_1 \* 0x34'),
    ('ovc33_stats.c', '6386:1a19', r'param_1 \* 0x34'),
    ('ovc33_stats.c', '6386:1a9b', r'param_1 \* 0x34'),
    ('ovc41.c', '6a8f:01e7', r'\(int\)param_1 \+ 0x17'),
    ('ovc41.c', '6a8f:0256', r'param_2 \* 0x34|param_1 \* 0x34'),
    ('ovc41.c', '6a8f:0807', r'param_1 \* 0x34'),
    ('ovc41.c', '6a8f:08c2', r'param_1 \* 0x34'),
    # unit index
    ('ovc22.c', '5087:1674', r'GUnits\)\[param_1\]'),
    ('ovc34_unit.c', '6616:0000', r'GUnits\)\[param_1\]'),
    ('ovc37_season.c', '67e7:09b9', r'GUnits\)\[param_1\]'),
    ('ovc47_constrct.c', '7e7c:2e8e', r'GUnits\)\[param_1\]'),
    # handle / record / leader
    ('ovc19_save.c', '49fd:01da', r'save_49fd_0000\(param_1'),
    ('ovc23.c', '55fe:1803', r'param_1 \* 0x12'),
    ('ovc23.c', '55fe:29a2', r'param_1 \* 0x12'),
    ('ovc24.c', '5943:1007', r'\(uint\)param_1 << 2'),
    ('ovc24.c', '5943:190b', r'\(uint\)param_1 << 2'),
    ('ovc37_season.c', '67e7:026a', r'\(uint\)param_1 << 2'),
    # coordinates
    ('ovc23.c', '55fe:05db', r'OVC23_55fe_3450\(param_1'),
    ('ovc15.c', '4207:0ff0', r'OVC23_55fe_3450\(param_1'),
    ('ovc14_attact.c', '3f0b:0894', r'0x1b\) == param_1'),
    ('ovc13.c', '3d16:0186', r'param_2 \* 0x140'),
    ('ovc13.c', '3d16:01fb', r'GMapFlags'),
    ('ovc09_init.c', '3381:233e', r'GMapCells'),
    ('ovc09_init.c', '3381:237a', r'GMapCells|GMapFlags'),
    ('ovc09_init.c', '3381:23b5', r'GMapFlags'),
    ('ovc10_constr.c', '36ce:306b', r'GMapFlags'),
    ('ovc13.c', '3d16:01a4', r'GMapCells'),
    ('ovc14_attact.c', '3f0b:0000', r'GMapFlags'),
    ('ovc14_attact.c', '3f0b:007e', r'GMapFlags'),
    ('ovc14_attact.c', '3f0b:027d', r'GMapFlags'),
    ('ovc14_attact.c', '3f0b:0362', r'GMapFlags'),
    ('ovc18.c', '48ac:0bf4', r'GUnitGrid|GMapFlags'),
    ('ovc45.c', '77eb:0683', r'GMapFlags\)\[param_2\]'),
    ('ovc45.c', '77eb:0708', r'GMapFlags\)\[param_2 \+ 1\]\[param_1\]'),
    ('ovc45.c', '77eb:0742', r'GMapFlags\)\[param_2\]'),
    ('ovc23.c', '55fe:2937', r'param_1 <= \(int\)\(iVar1'),
    # bldType / gindex
    ('ovc22.c', '5087:0234', r'param_1 \* 0x27'),
    ('ovc22.c', '5087:0411', r'param_1 \* 0x27'),
    ('ovc35_bldng.c', '676c:003d', r'param_1 \* 0x27'),
    ('ovc45.c', '77eb:0778', r'param_1 \* 0x27'),
    ('ovc45.c', '77eb:0c36', r'param_1 \* 0x27'),
    ('ovc25.c', '5b66:18cc', r'param_1 \* 0x95'),
    ('ovc30.c', '619c:0339', r'param_1 \* 0x95'),
    # party index (0x217A far-pointer table of char_sheet_t)
    ('ovc22.c', '5087:0119', r'\[BX \+ 0x2f\]|\+ 0x2f\)'),
    ('ovc22.c', '5087:015c', r'\+ 0x2f\)'),
    ('ovc22.c', '5087:018f', r'\+ 0x87\)'),
    ('ovc25.c', '5b66:173b', r'\+ 0x3f\)|\+ 0x5d\)'),
    ('ovc22.c', '5087:1470', r'\+ 0x3f\)|\+ 0x45\)'),
    # GUnitGrid (x, y)
    ('ovc22.c', '5087:3c93', r'GUnitGrid\)\[param_1\]\[param_2\]'),
    ('ovc22.c', '5087:3d25', r'GUnitGrid\)\[param_1\]\[param_2\]'),
    ('ovc22.c', '5087:3dc7', r'GUnitGrid\)\[param_1\]\[param_2\]'),
    ('ovc22.c', '5087:3eb1', r'GUnitGrid\)\[param_1\]\[param_2\]'),
    ('ovc23.c', '55fe:1005', r'GUnitGrid\)\[param_1\]\[param_2\]'),
    ('ovc45.c', '77eb:0121', r'GUnitGrid\)\[param_1\]\[param_2\]'),
    ('ovc45.c', '77eb:0179', r'GUnitGrid\)\[param_1\]\[param_2\]'),
]


def main():
    bad = 0
    for fname, addr, expr in CHECKS:
        path = os.path.join(EXPORT, fname)
        body = funcs(path).get(addr, '')
        if not re.search(expr, body):
            bad += 1
            print('FAIL', fname, addr, '|', expr)
    print('checked', len(CHECKS), 'failures', bad)
    return 1 if bad else 0


if __name__ == '__main__':
    sys.exit(main())
