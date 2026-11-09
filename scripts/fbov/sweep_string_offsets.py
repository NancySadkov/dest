#!/usr/bin/env python3
"""Sweep `"string" + offset` expressions in a Ghidra C export.

Every expression is resolved to its numeric DGROUP value.  Segment values are
replaced by DGROUP_SEG/SEG_xxxx, small integer collisions with the copyright
string are replaced by the integer, and everything else is reported for manual
type work.
"""
import csv
import os
import re
import shutil

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
EXE = os.path.join(ROOT, "game", "STRONG.EXE")
DGROUP_FILE = 0x15F00
DGROUP_SIZE = 0x949A

PAT = re.compile(r'"((?:[^"\\]|\\.)*)"\s*\+\s*(0x[0-9A-Fa-f]+|\d+)')


def build_literals():
    d = open(EXE, "rb").read()[DGROUP_FILE:DGROUP_FILE + DGROUP_SIZE]
    out = {}
    i = 0
    while i < len(d):
        if 32 <= d[i] < 127:
            j = i
            while j < len(d) and (32 <= d[j] < 127 or d[j] in (9, 10, 13)):
                j += 1
            if j < len(d) and d[j] == 0 and j - i >= 2:
                out.setdefault(d[i:j].decode("latin1"), i)
            i = j + 1
        else:
            i += 1
    return out


def build_segments():
    segs = {}
    path = os.path.join(ROOT, "doc", "fbov_segments.csv")
    for r in csv.DictReader(open(path)):
        segs[int(r["static_seg"], 16)] = r
    # Overlay code and header segments are also 16-bit segment constants.
    path = os.path.join(ROOT, "doc", "fbov_overlays.csv")
    for r in csv.DictReader(open(path)):
        segs.setdefault(int(r["code_seg"], 16),
                        {"class": "OVRCODE", "static_seg": r["code_seg"]})
        segs.setdefault(int(r["header_static_seg"], 16),
                        {"class": "OVRHDR", "static_seg": r["header_static_seg"]})
    return segs


def token_for(value, segs):
    if value == 0x2410:
        return "DGROUP_SEG"
    if value in segs:
        return "SEG_%04X" % value
    return None


def c_unescape(s):
    """Decode C string escapes without confusing \\t with a tab."""
    out = []
    i = 0
    while i < len(s):
        if s[i] == "\\" and i + 1 < len(s):
            c = s[i + 1]
            out.append({"n": "\n", "r": "\r", "t": "\t",
                        "\\": "\\", '"': '"', "'": "'"}.get(c, c))
            i += 2
        else:
            out.append(s[i])
            i += 1
    return "".join(out)


def main():
    import argparse
    ap = argparse.ArgumentParser()
    ap.add_argument("src")
    ap.add_argument("dst")
    ap.add_argument("--report",
                    default=os.path.join(ROOT, "tmp",
                                         "string_offset_sweep.csv"))
    a = ap.parse_args()
    lits = build_literals()
    segs = build_segments()
    shutil.rmtree(a.dst, ignore_errors=True)
    os.makedirs(a.dst)
    report = open(a.report, "w", newline="")
    wr = csv.writer(report)
    wr.writerow(["file", "line", "expression", "value", "kind", "replacement"])
    changed = 0
    for dp, _, fs in os.walk(a.src):
        rel = os.path.relpath(dp, a.src)
        outdir = os.path.join(a.dst, rel)
        os.makedirs(outdir, exist_ok=True)
        for f in fs:
            if not f.endswith((".c", ".h")):
                continue
            p = os.path.join(dp, f)
            text = open(p, encoding="latin1", errors="replace").read()
            lines = text.splitlines(True)
            used = set()
            for ln, line in enumerate(lines, 1):
                def repl(m):
                    lit = c_unescape(m.group(1))
                    k = int(m.group(2), 0)
                    off = lits.get(lit)
                    if off is None:
                        for sstr, soff in lits.items():
                            j = sstr.find(lit)
                            if j >= 0:
                                off = soff + j
                                break
                    if off is None:
                        wr.writerow([p, ln, m.group(0), "", "unmapped", ""])
                        return m.group(0)
                    val = off + k
                    tok = token_for(val, segs)
                    if tok:
                        used.add(tok)
                        wr.writerow([p, ln, m.group(0), "0x%04X" % val,
                                     "segment", tok])
                        return tok
                    if off is not None and off < 0x100 and val < 0x100:
                        wr.writerow([p, ln, m.group(0), "0x%04X" % val,
                                     "small-int", "0x%X" % val])
                        return "0x%X" % val
                    wr.writerow([p, ln, m.group(0), "0x%04X" % val,
                                 "other", ""])
                    return m.group(0)

                new = PAT.sub(repl, line)
                if new != line:
                    lines[ln - 1] = new
                    line = new
                # Replace raw scalar segment constants (skip our own defines).
                if not line.lstrip().startswith("#define"):
                    def rawrepl(m):
                        v = int(m.group(1), 16)
                        tok = token_for(v, segs)
                        if tok is None:
                            return m.group(0)
                        used.add(tok)
                        wr.writerow([p, ln, m.group(0), "0x%04X" % v,
                                     "raw-segment", tok])
                        return tok
                    new2 = re.sub(r"\b0x([0-9A-Fa-f]{4})\b", rawrepl, line)
                    if new2 != line:
                        lines[ln - 1] = new2
            text = "".join(lines)
            if used:
                defs = "".join("#define %s 0x%04X\n" % (t, 0x2410 if t == "DGROUP_SEG"
                                                        else int(t[4:], 16))
                               for t in sorted(used))
                # Put the defines after the first two header comment lines.
                head = text.split("\n", 2)
                if len(head) == 3:
                    text = head[0] + "\n" + head[1] + "\n" + defs + head[2]
                else:
                    text = defs + text
                changed += 1
            open(os.path.join(outdir, f), "w", encoding="latin1",
                 newline="").write(text)
    report.close()
    print("swept files", changed, "report", a.report)


if __name__ == "__main__":
    main()
