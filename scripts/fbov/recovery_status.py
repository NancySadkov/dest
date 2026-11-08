#!/usr/bin/env python3
"""Report true C recovery versus byte acceptance.

The verifier accepts a function when its bytes match the original.  That does
not mean the function is C: many overlay functions are still manual-frame
`asm db` dumps that happen to be byte-exact.  This tool classifies every
overlay function as:

  C              - body is real C / inline asm, not a raw dump
  accepted-asm   - byte-accepted but still a raw asm/pad body
  unaccepted-asm - raw asm/pad body not yet byte-accepted

It writes `doc/recovery_status.md` and prints the totals.
"""
import argparse
import csv
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
ACC = os.path.join(ROOT, "doc", "vroomm_accepted.md")
OUT = os.path.join(ROOT, "doc", "recovery_status.md")


def is_c(body):
    for line in body.splitlines():
        s = line.strip()
        if s in ("{", "}"):
            continue
        s = re.sub(r"/\*.*?\*/", "", s).strip()
        s = re.sub(r"//.*$", "", s).strip()
        if not s:
            continue
        if re.match(r"asm\s+db\b", s):
            continue
        if re.match(r"unsigned\s+char\s+pad\s*\[", s):
            continue
        if s == "(void)pad;":
            continue
        return True
    return False


def codesizes():
    out = {}
    for r in csv.DictReader(open(os.path.join(ROOT, "doc", "fbov_overlays.csv"))):
        out[int(r["code_seg"], 16)] = int(r["codesz"], 16)
    return out


def inventory():
    out = {}
    for r in csv.DictReader(open(os.path.join(ROOT, "tmp", "fn_inventory.csv"))):
        out[(int(r["seg"], 16), int(r["ofs"], 16))] = int(r["size"])
    return out


def accepted():
    out = {}
    for line in open(ACC, encoding="ascii"):
        if not line.startswith("| `ov_"):
            continue
        parts = [p.strip() for p in line.strip().strip("|").split("|")]
        seg = int(parts[0].strip("`").split("_")[1], 16)
        out[seg] = {int(n, 16) for n, _ in re.findall(r"`([0-9a-f]+)`\((\d+)\)", parts[1])}
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default=OUT)
    a = ap.parse_args()

    acc = accepted()
    sizes = codesizes()
    inv = inventory()
    totals = {"C": [0, 0], "accepted-asm": [0, 0], "unaccepted-asm": [0, 0]}
    per = {}

    for path in sorted(os.listdir(os.path.join(ROOT, "src"))):
        m = re.match(r"ov_([0-9a-f]{4})\.c$", path)
        if not m:
            continue
        seg = int(m.group(1), 16)
        text = open(os.path.join(ROOT, "src", path), encoding="ascii", errors="replace").read()
        funcs = []
        for mm in re.finditer(r"__cdecl16far\s+(f_%s_[0-9a-f]+)\s*\(([^)]*)\)\s*\{" % m.group(1), text):
            name = mm.group(1)
            i = mm.end() - 1
            depth = 0
            for j in range(i, len(text)):
                if text[j] == "{":
                    depth += 1
                elif text[j] == "}":
                    depth -= 1
                    if depth == 0:
                        funcs.append((int(name.split("_")[-1], 16), name,
                                      is_c(text[i:j + 1])))
                        break
        funcs.sort()
        row = {"C": [0, 0], "accepted-asm": [0, 0], "unaccepted-asm": [0, 0]}
        for name in os.listdir(os.path.join(ROOT, "src")):
            am = re.match(r"a%s\d+\.asm$" % m.group(1), name)
            if not am:
                continue
            asm = open(os.path.join(ROOT, "src", name),
                       encoding="ascii", errors="replace").read()
            for hm in re.finditer(r"_(f_%s_([0-9a-f]+)):" % m.group(1), asm, re.I):
                ofs = int(hm.group(2), 16)
                n = inv.get((seg, ofs), 0)
                row["accepted-asm"][0] += 1
                row["accepted-asm"][1] += n
                totals["accepted-asm"][0] += 1
                totals["accepted-asm"][1] += n
        for k, (ofs, name, c) in enumerate(funcs):
            size = inv.get((seg, ofs), 0)
            if c:
                bucket = "C"
            elif ofs in acc.get(seg, set()):
                bucket = "accepted-asm"
            else:
                bucket = "unaccepted-asm"
            row[bucket][0] += 1
            row[bucket][1] += size
            totals[bucket][0] += 1
            totals[bucket][1] += size
        per[seg] = row

    lines = [
        "# Recovery status",
        "",
        "Byte acceptance is not the same as C recovery.  The verifier accepts a",
        "function when its bytes match; many are still manual-frame `asm db` dumps.",
        "",
        "| Class | Functions | Bytes |",
        "|---|---:|---:|",
    ]
    for k in ("C", "accepted-asm", "unaccepted-asm"):
        lines.append("| %s | %d | %d |" % (k, totals[k][0], totals[k][1]))
    total_f = sum(v[0] for v in totals.values())
    total_b = sum(v[1] for v in totals.values())
    lines += ["| **total** | **%d** | **%d** |" % (total_f, total_b), ""]
    lines += [
        "| Module | C | accepted-asm | unaccepted-asm |",
        "|---|---:|---:|---:|",
    ]
    for seg in sorted(per):
        r = per[seg]
        lines.append("| `ov_%04x` | %d | %d | %d |" % (seg, r["C"][0],
                                                      r["accepted-asm"][0],
                                                      r["unaccepted-asm"][0]))
    open(a.out, "w", encoding="ascii", newline="").write("\n".join(lines) + "\n")

    print("C:              %4d functions, %7d bytes" % tuple(totals["C"]))
    print("accepted-asm:   %4d functions, %7d bytes" % tuple(totals["accepted-asm"]))
    print("unaccepted-asm: %4d functions, %7d bytes" % tuple(totals["unaccepted-asm"]))
    print("total:          %4d functions, %7d bytes" % (total_f, total_b))
    print("wrote", a.out)


if __name__ == "__main__":
    main()
