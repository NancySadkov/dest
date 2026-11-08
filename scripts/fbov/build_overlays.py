#!/usr/bin/env python3
"""Build the 51 overlay code regions from src/.

All overlay translation units are compiled and linked together, then each
OV_<seg>_TEXT segment is extracted and the committed relocation patch table
(src/ov_patch.csv) is applied.  The result is byte-identical to the original
overlay code without reading game/STRONG.EXE.

Outputs:
  tmp/ovcode/OV_<seg>.BIN
  tmp/ovcode/index.json
"""
import argparse
import csv
import json
import os
import re
import shutil
import struct
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
SRC = os.path.join(ROOT, "src")
WORK = os.path.join(ROOT, "tmp", "ovbuild_src")
OUT = os.path.join(ROOT, "tmp", "ovcode")
TOOLS = os.path.join(ROOT, "tools")

sys.path.insert(0, os.path.join(ROOT, "scripts", "fbov"))
import vroomm_verify_linked as V


def tcc(name):
    return ("D:\\BIN\\TCC.EXE -ml -1 -G -O -ID:\\INCLUDE -IC:\\ "
            "-LD:\\LIB -w- -c %s" % name)


def copy_headers():
    shutil.copyfile(os.path.join(SRC, "st_compat.h"),
                    os.path.join(WORK, "compat.h"))
    shutil.copyfile(os.path.join(SRC, "st_types.h"),
                    os.path.join(WORK, "types.h"))
    h = open(os.path.join(SRC, "dgroup.h"), encoding="ascii").read()
    h = h.replace('#include "st_compat.h"', '#include "compat.h"')
    h = h.replace('#include "st_types.h"', '#include "types.h"')
    open(os.path.join(WORK, "dgroup.h"), "w", encoding="ascii",
         newline="").write(h)
    shutil.copyfile(os.path.join(SRC, "dgroup.c"),
                    os.path.join(WORK, "dgroup.c"))


def write_conf(name, cmds, wait):
    bat = ("@echo off\r\nmode con lines=50\r\n" + "\r\n".join(cmds) +
           "\r\npause\r\n")
    open(os.path.join(WORK, name + ".bat"), "w", newline="").write(bat)
    conf = (
        "[sdl]\nfullscreen = false\noutput = surface\n"
        "[dosbox]\nmachine = svga_s3\nmemsize = 16\n"
        "[cpu]\ncore = normal\ncputype = 386\ncycles = max\n"
        "[mixer]\nnosound = true\n[sblaster]\nsbtype = none\n[midi]\nmididevice = none\n"
        "[autoexec]\nmount c " + WORK.replace("\\", "\\\\") + "\n"
        "mount d " + os.path.join(TOOLS, "TC30").replace("\\", "\\\\") + "\n"
        "mount e " + os.path.join(TOOLS, "BC30").replace("\\", "\\\\") + "\n"
        "c:\ncall " + name + ".bat\n"
    )
    path = os.path.join(WORK, name + ".conf")
    open(path, "w").write(conf)
    return path


def run(cmds, wait):
    conf = write_conf("run", cmds, wait)
    V.kill_dosbox()
    subprocess.run([sys.executable,
                    os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                    "--conf", conf, "--wait", str(wait)], check=True)


def patch_bss():
    """Move compiler _BSS segments out of the BSS class.

    TLINK otherwise lays _BSS after every code segment, so DGROUP spans the
    whole image and exceeds 64K.  A two-byte compiler BSS is not referenced by
    the recovered code, so class DATA keeps it next to _DATA.
    """
    for name in os.listdir(WORK):
        if not name.lower().endswith(".obj"):
            continue
        path = os.path.join(WORK, name)
        d = bytearray(open(path, "rb").read())
        names = []
        i = 0
        while i + 3 <= len(d):
            t = d[i]
            ln = d[i + 1] | (d[i + 2] << 8)
            p = d[i + 3:i + 3 + ln]
            if t == 0x96:
                j = 0
                while j < len(p) - 1:
                    n = p[j]
                    names.append(p[j + 1:j + 1 + n].decode("latin1"))
                    j += 1 + n
            elif t == 0x8A:
                break
            i += 3 + ln
        if "DATA" not in names or "_BSS" not in names:
            continue
        data_ci = names.index("DATA") + 1
        bss_ni = names.index("_BSS") + 1
        i = 0
        changed = 0
        while i + 3 <= len(d):
            t = d[i]
            ln = d[i + 1] | (d[i + 2] << 8)
            p = i + 3
            if t == 0x98:
                body = d[p:p + ln - 1]
                acbp = body[0]
                off = 5 if acbp & 1 else 3
                if body[off] == bss_ni:
                    d[p + off + 1] = data_ci
                    changed += 1
                d[p + ln - 1] = (-sum(d[i:p + ln - 1])) & 0xFF
            i += 3 + ln
            if t == 0x8A:
                break
        if changed:
            open(path, "wb").write(d)


def parse_map(path):
    segs = {}
    for line in open(path, encoding="ascii", errors="replace"):
        m = re.match(r"^\s*([0-9A-F]{5})H\s+([0-9A-F]{5})H\s+"
                     r"([0-9A-F]{5})H\s+(\S+)", line)
        if m:
            segs[m.group(4)] = (int(m.group(1), 16), int(m.group(3), 16))
    return segs


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--wait", type=int, default=150)
    ap.add_argument("--verify", action="store_true",
                    help="compare against game/STRONG.EXE")
    a = ap.parse_args()

    shutil.rmtree(WORK, ignore_errors=True)
    os.makedirs(WORK, exist_ok=True)
    os.makedirs(OUT, exist_ok=True)
    copy_headers()

    # Phase 1: DGROUP object from src/dgroup.c.
    run([tcc("dgroup.c")], 20)
    os.makedirs(os.path.join(ROOT, "tmp", "dgbuild"), exist_ok=True)
    shutil.copyfile(os.path.join(WORK, "DGROUP.OBJ"),
                    os.path.join(ROOT, "tmp", "dgbuild", "DGROUP.OBJ"))
    subprocess.run([sys.executable,
                    os.path.join(ROOT, "scripts", "fbov", "gen_link_dgroup.py")],
                   check=True)
    shutil.copyfile(os.path.join(ROOT, "tmp", "dglink", "dglink.asm"),
                    os.path.join(WORK, "dglink.asm"))
    shutil.copyfile(os.path.join(ROOT, "scripts", "fbov", "start.asm"),
                    os.path.join(WORK, "start.asm"))
    shutil.copyfile(os.path.join(ROOT, "scripts", "fbov", "stubs.c"),
                    os.path.join(WORK, "stubs.c"))

    # Stage modules and collect the link order.
    modules = []
    for r in csv.DictReader(open(os.path.join(ROOT, "doc",
                                              "fbov_overlays.csv"))):
        modules.append("ov_%04x" % int(r["code_seg"], 16))
    defined = set()
    cmds = ["E:\\BIN\\TASM.EXE dglink.asm", "E:\\BIN\\TASM.EXE start.asm"]
    objs = ["dglink.obj", "start.obj"]
    for mod in modules:
        plan = V.chunk_plan(mod, SRC)
        if plan:
            seg = mod[3:]
            shutil.copyfile(os.path.join(SRC, "k%s.h" % seg),
                            os.path.join(WORK, "k%s.h" % seg))
            for kind, base in plan:
                ext = ".c" if kind == "c" else ".asm"
                shutil.copyfile(os.path.join(SRC, base + ext),
                                os.path.join(WORK, base + ext))
                if kind == "c":
                    cmds.append(tcc(base + ".c"))
                else:
                    cmds.append("E:\\BIN\\TASM.EXE /mx " + base + ".asm")
                objs.append(base + ".obj")
            hdr = open(os.path.join(SRC, "k%s.h" % seg),
                       encoding="ascii").read()
            defined |= set(re.findall(
                r"__cdecl16far\s+(f_[0-9a-f]{4}_[0-9a-f]+)\s*\(", hdr))
        else:
            shutil.copyfile(os.path.join(SRC, mod + ".c"),
                            os.path.join(WORK, mod + ".c"))
            cmds.append(tcc(mod + ".c"))
            objs.append(mod + ".obj")
            text = open(os.path.join(SRC, mod + ".c"),
                        encoding="ascii").read()
            defined |= set(re.findall(
                r"__cdecl16far\s+(f_[0-9a-f]{4}_[0-9a-f]+)\s*\([^)]*\)\s*\{",
                text))
            defined |= set(re.findall(
                r"unsigned char (f_[0-9a-f]{4}_[0-9a-f]+)\[\]", text))

    # Keep only stubs that no module defines.
    lines = open(os.path.join(WORK, "stubs.c"), encoding="ascii").read().splitlines()
    out = []
    for line in lines:
        m = re.search(r"(f_[0-9a-f]{4}_[0-9a-f]+)\s*\(", line)
        if m and m.group(1) in defined:
            continue
        out.append(line)
    open(os.path.join(WORK, "stubs.c"), "w", newline="").write(
        "\n".join(out) + "\n")
    cmds.append(tcc("stubs.c"))
    objs.append("stubs.obj")

    open(os.path.join(WORK, "link.rsp"), "w", newline="").write(
        "/m " + " ".join(objs) + ", out.exe, out.map\r\n")
    cmds.append("D:\\BIN\\TLINK.EXE @link.rsp")
    run(cmds, a.wait)

    patch_bss()
    run(["D:\\BIN\\TLINK.EXE @link.rsp"], 15)

    raw = open(os.path.join(WORK, "OUT.EXE"), "rb").read()
    base = struct.unpack_from("<H", raw, 8)[0] * 16
    segs = parse_map(os.path.join(WORK, "OUT.MAP"))

    patches = {}
    for r in csv.DictReader(open(os.path.join(SRC, "ov_patch.csv"))):
        patches.setdefault(int(r["seg"], 16), {})[int(r["offset"], 16)] = \
            int(r["value"], 16)

    exe = None
    if a.verify:
        exe = open(os.path.join(ROOT, "game", "STRONG.EXE"), "rb").read()

    index = []
    bad = 0
    for r in csv.DictReader(open(os.path.join(ROOT, "doc",
                                              "fbov_overlays.csv"))):
        seg = int(r["code_seg"], 16)
        size = int(r["codesz"], 16)
        name = "OV_%04X_TEXT" % seg
        if size == 0:
            code = b""
        else:
            start, length = segs[name]
            code = bytearray(raw[base + start:base + start + length])
            if len(code) != size:
                raise SystemExit("%s: linked size %d != %d"
                                 % (name, len(code), size))
            for off, val in patches.get(seg, {}).items():
                code[off] = val
            code = bytes(code)
        fn = "OV_%04X.BIN" % seg
        open(os.path.join(OUT, fn), "wb").write(code)
        index.append({"seg": "%04X" % seg, "size": size, "file": fn})
        if exe is not None:
            off0 = int(r["code_file_offset"], 0)
            orig = exe[off0:off0 + size]
            if code != orig:
                d = [i for i in range(size) if code[i] != orig[i]]
                print("%s: %d byte(s) differ" % (name, len(d)))
                bad += len(d)
    open(os.path.join(OUT, "index.json"), "w").write(
        json.dumps(index, indent=1) + "\n")
    print("wrote %d overlay code regions to %s" %
          (len(index), OUT))
    if a.verify:
        print("verify differences:", bad)
        if bad:
            raise SystemExit(1)


if __name__ == "__main__":
    main()
