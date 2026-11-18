import io
import os
import re

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


# (module, addr, reason, regex that must appear in the function's OWN body)
CHECKS = [
    # entityIndex batch
    ('ovc13.c', '3d16:1045', 'Entities[param_1]', r'Entities\)\[param_1\]'),
    ('ovc22.c', '5087:1470', 'Entities[param_1]', r'Entities\)\[param_1\]'),
    ('ovc22.c', '5087:1532', 'Entities[param_1]', r'Entities\)\[param_1\]'),
    ('ovc24.c', '5943:0196', 'Entities + param_1', r'Entities \+ param_1'),
    ('ovc33_stats.c', '6386:1572', 'Entities[param_1]', r'Entities\)\[param_1\]'),
    ('ovc15.c', '4207:0e17', 'Entities[param_1]', r'Entities\)\[param_1\]'),
    ('ovc45.c', '77eb:16b2', 'Entities[param_1]', r'Entities\)\[param_1\]'),
    # agent index batch
    ('ovc15.c', '4207:1d87', '0x34 stride', r'param_1 \* 0x34'),
    ('ovc27.c', '5ded:0a05', '0x34 stride', r'param_1 \* 0x34'),
    ('ovc27.c', '5ded:0cc2', '0x34 stride', r'param_1 \* 0x34'),
    ('ovc33_stats.c', '6386:12b7', '0x34 stride', r'param_1 \* 0x34'),
    ('ovc33_stats.c', '6386:16a2', '0x34 stride', r'param_1 \* 0x34'),
    ('ovc33_stats.c', '6386:1837', '0x34 stride', r'param_1 \* 0x34'),
    ('ovc33_stats.c', '6386:1997', '0x34 stride', r'param_1 \* 0x34'),
    ('ovc33_stats.c', '6386:1a19', '0x34 stride', r'param_1 \* 0x34'),
    ('ovc33_stats.c', '6386:1a9b', '0x34 stride', r'param_1 \* 0x34'),
    ('ovc41.c', '6a8f:01e7', '0x34 stride', r'param_1 \* 0x34'),
    ('ovc41.c', '6a8f:0256', '0x34 stride', r'param_1 \* 0x34'),
    ('ovc41.c', '6a8f:0807', '0x34 stride', r'param_1 \* 0x34'),
    ('ovc41.c', '6a8f:08c2', '0x34 stride', r'param_1 \* 0x34'),
    # unit index
    ('ovc22.c', '5087:1674', 'GUnits[param_1]', r'GUnits\)\[param_1\]'),
    ('ovc34_unit.c', '6616:0000', 'GUnits[param_1]', r'GUnits\)\[param_1\]'),
    ('ovc37_season.c', '67e7:09b9', 'GUnits[param_1]', r'GUnits\)\[param_1\]'),
    ('ovc47_constrct.c', '7e7c:2e8e', 'GUnits[param_1]', r'GUnits\)\[param_1\]'),
    # handle / record / leader (last batches)
    ('ovc19_save.c', '49fd:01da', 'save_49fd_0000(param_1', r'save_49fd_0000\(param_1'),
    ('ovc23.c', '55fe:1803', 'param_1 * 0x12', r'param_1 \* 0x12'),
    ('ovc23.c', '55fe:29a2', 'param_1 * 0x12', r'param_1 \* 0x12'),
    ('ovc23.c', '55fe:2937', 'param_1 * 0x12', r'param_1 \* 0x12'),
    ('ovc24.c', '5943:1007', '<< 2 table', r'\(uint\)param_1 << 2'),
    ('ovc24.c', '5943:190b', '<< 2 table', r'\(uint\)param_1 << 2'),
    ('ovc37_season.c', '67e7:026a', '<< 2 table', r'\(uint\)param_1 << 2'),
    # coordinates
    ('ovc23.c', '55fe:05db', 'x clamp', r'OVC23_55fe_3450\(param_1'),
    ('ovc15.c', '4207:0ff0', 'x clamp', r'OVC23_55fe_3450\(param_1'),
    ('ovc14_attact.c', '3f0b:0894', 'owner compare', r'0x1b\) == param_1'),
    ('ovc13.c', '3d16:0186', '0x140 row', r'param_2 \* 0x140'),
    ('ovc13.c', '3d16:01fb', 'GMapFlags index', r'GMapFlags'),
    ('ovc09_init.c', '3381:233e', 'GMapCells index', r'GMapCells'),
    ('ovc09_init.c', '3381:237a', 'GMapCells index', r'GMapCells|GMapFlags'),
    ('ovc09_init.c', '3381:23b5', 'GMapFlags index', r'GMapFlags'),
    ('ovc10_constr.c', '36ce:306b', 'GMapFlags index', r'GMapFlags'),
    ('ovc13.c', '3d16:01a4', 'GMapCells index', r'GMapCells'),
    ('ovc14_attact.c', '3f0b:0000', 'GMapFlags index', r'GMapFlags'),
    ('ovc14_attact.c', '3f0b:007e', 'GMapFlags index', r'GMapFlags'),
    ('ovc14_attact.c', '3f0b:027d', 'GMapFlags index', r'GMapFlags'),
    ('ovc14_attact.c', '3f0b:0362', 'GMapFlags index', r'GMapFlags'),
    ('ovc18.c', '48ac:0bf4', 'GUnitGrid/GMapFlags', r'GUnitGrid|GMapFlags'),
    # bldType / gindex batches
    ('ovc22.c', '5087:0234', '0x27 stride', r'param_1 \* 0x27'),
    ('ovc22.c', '5087:0411', '0x27 stride', r'param_1 \* 0x27'),
    ('ovc35_bldng.c', '676c:003d', '0x27 stride', r'param_1 \* 0x27'),
    ('ovc45.c', '77eb:0778', '0x27 stride', r'param_1 \* 0x27'),
    ('ovc45.c', '77eb:0c36', '0x27 stride', r'param_1 \* 0x27'),
    ('ovc25.c', '5b66:18cc', '0x95 stride', r'param_1 \* 0x95'),
    ('ovc30.c', '619c:0339', '0x95 stride', r'param_1 \* 0x95'),
]

fails = []
for fname, addr, why, expr in CHECKS:
    fs = funcs(os.path.join('tmp/decompiled4', fname))
    body = fs.get(addr, '')
    if not re.search(expr, body):
        fails.append((fname, addr, why))

print('checked', len(CHECKS), 'failures', len(fails))
for f in fails:
    print('FAIL', f[0], f[1], '|', f[2])
