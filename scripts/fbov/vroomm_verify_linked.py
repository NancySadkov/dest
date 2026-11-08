#!/usr/bin/env python3
"""Build linked harnesses and substitute pure-C overlay functions.

Some recovered functions reference DGROUP symbols by offset.  A standalone OMF
object leaves those offsets unresolved, so the bytes cannot be compared with
the original image.  This tool links the module against the recovered DGROUP
(`dglink.obj`), which resolves them exactly as in the original, then verifies
each pure-C function and patches it into the staged VROOMM EXE.

Usage:
  python scripts/fbov/vroomm_verify_linked.py 3381:ov_3381 48ac:ov_48ac ...
"""
import argparse
import csv
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
LINK = os.path.join(ROOT, "tmp", "linkbuild")
EMU = os.path.join(ROOT, "emulator", "dosbox-x-mod.exe")


def write_link_batch(module):
    bat = (
        "@echo off\r\nmode con lines=50\r\n"
        "D:\\BIN\\TCC.EXE -ml -1 -G -O -ID:\\INCLUDE -IC:\\ -LD:\\LIB -w- -c %s.c\r\n"
        "D:\\BIN\\TCC.EXE -ml -1 -G -O -ID:\\INCLUDE -IC:\\ -LD:\\LIB -w- -c stubs.c\r\n"
        "D:\\BIN\\TLINK.EXE /m dglink.obj %s.obj start.obj stubs.obj, out.exe, out.map\r\n"
        "pause\r\n"
    ) % (module, module)
    open(os.path.join(LINK, "ovlink.bat"), "w", newline="").write(bat)
    conf = (
        "[sdl]\nfullscreen = false\noutput = surface\n"
        "[dosbox]\nmachine = svga_s3\nmemsize = 16\n"
        "[cpu]\ncore = normal\ncputype = 386\ncycles = max\n"
        "[mixer]\nnosound = true\n[sblaster]\nsbtype = none\n[midi]\nmididevice = none\n"
        "[autoexec]\nmount c " + LINK.replace("\\", "\\\\") + "\n"
        "mount d " + os.path.join(ROOT, "tools", "TC30").replace("\\", "\\\\") + "\n"
        "c:\ncall ovlink.bat\n"
    )
    path = os.path.join(ROOT, "tmp", "ovlink.conf")
    open(path, "w").write(conf)
    return path


def kill_dosbox():
    subprocess.run(
        ["powershell", "-NoProfile", "-Command",
         "Get-Process | Where-Object {$_.ProcessName -match 'dosbox'} | "
         "Stop-Process -Force -ErrorAction SilentlyContinue"],
        capture_output=True)


def build_harness(module, wait):
    os.makedirs(LINK, exist_ok=True)
    src = os.path.join(ROOT, "src", "recovered", module + ".c")
    if not os.path.exists(src):
        raise SystemExit("missing source: " + src)
    open(os.path.join(LINK, module + ".c"), "wb").write(open(src, "rb").read())
    open(os.path.join(LINK, "stubs.c"), "wb").write(
        open(os.path.join(ROOT, "scripts", "fbov", "stubs.c"), "rb").read())
    conf = write_link_batch(module)
    kill_dosbox()
    for name in ("OUT.EXE", "OUT.MAP"):
        p = os.path.join(LINK, name)
        if os.path.exists(p):
            os.remove(p)
    subprocess.run([sys.executable, os.path.join(ROOT, "scripts", "fbov", "run_dosbox.py"),
                    "--conf", conf, "--wait", str(wait)], check=True)
    return os.path.join(LINK, "OUT.EXE"), os.path.join(LINK, "OUT.MAP")


def parse_map(map_path, seg):
    text = open(map_path, encoding="ascii", errors="replace").read()
    segname = "OV_%04X_TEXT" % seg
    if not re.search(r"^\s*[0-9A-F]{5}H\s+[0-9A-F]{5}H\s+[0-9A-F]{5}H\s+%s\s" % segname,
                     text, re.M):
        raise SystemExit("segment %s missing from map" % segname)
    syms = {}
    for m in re.finditer(r"^\s*[0-9A-F]{4}:[0-9A-F]{4}\s+(_F_%04X_[0-9A-F]+)\s*$"
                         % seg, text, re.M):
        syms[int(m.group(1).rsplit("_", 1)[1], 16)] = m.group(1)
    return segname, syms


def pure_functions(src, seg):
    prefix = "f_%04x_" % seg
    text = open(src, encoding="ascii", errors="replace").read()
    out = {}
    for m in re.finditer(r"__cdecl16far\s+(%s[0-9a-f]+)\s*\([^)]*\)\s*\{" % prefix, text):
        name = m.group(1)
        i = m.end() - 1
        depth = 0
        for j in range(i, len(text)):
            if text[j] == "{":
                depth += 1
            elif text[j] == "}":
                depth -= 1
                if depth == 0:
                    out[name] = "asm db" not in text[i:j + 1]
                    break
    return out


def codesize(seg):
    for r in csv.DictReader(open(os.path.join(ROOT, "doc", "fbov_overlays.csv"))):
        if int(r["code_seg"], 16) == seg:
            return int(r["codesz"], 16)
    raise SystemExit("segment missing from overlay table")


def verify_module(exe, map_path, seghex, module):
    seg = int(seghex, 16)
    segname, syms = parse_map(map_path, seg)
    offsets = sorted(syms)
    pure = pure_functions(os.path.join(ROOT, "src", "recovered", module + ".c"), seg)
    total = codesize(seg)
    obj = None
    for name in (module.upper() + ".OBJ", module + ".OBJ"):
        p = os.path.join(LINK, name)
        if os.path.exists(p):
            obj = p
            break
    passed = 0
    for idx, ofs in enumerate(offsets):
        name = "f_%04x_%04x" % (seg, ofs)
        if not pure.get(name, False):
            continue
        size = (offsets[idx + 1] if idx + 1 < len(offsets) else total) - ofs
        if size <= 0:
            continue
        base = [sys.executable, os.path.join(ROOT, "scripts", "fbov", "vroomm_subst.py"),
                "--overlay-seg", seghex, "--ofs", "0x%X" % ofs, "--len", str(size)]
        # A standalone object keeps the module's original internal layout, so
        # layout-relative data (e.g. switch jump tables) stays correct.  Use
        # the linked image only when DGROUP-relative offsets need resolving.
        r = None
        if obj:
            r = subprocess.run(base + ["--obj", obj, "--name", name],
                               capture_output=True, text=True)
        how = "standalone"
        if r is None or r.returncode != 0:
            r = subprocess.run(
                [sys.executable, os.path.join(ROOT, "scripts", "fbov", "link_compare.py"),
                 "--symbol", syms[ofs], "--segname", segname, "--overlay-seg", seghex,
                 "--ofs", "0x%X" % ofs, "--size", str(size), "--show", "0"],
                capture_output=True, text=True)
            how = "linked"
            if r.returncode != 0:
                print("  DIFF %s ofs=%04X size=%d: %s"
                      % (name, ofs, size, (r.stdout or r.stderr).strip().splitlines()[-1]))
                continue
            r = subprocess.run(
                base + ["--linked-exe", exe, "--linked-map", map_path,
                        "--symbol", syms[ofs], "--segname", segname],
                capture_output=True, text=True)
        if r.returncode == 0:
            passed += 1
            print("  PASS %s ofs=%04X size=%d (%s)" % (name, ofs, size, how))
        else:
            print("  FAIL %s ofs=%04X: %s"
                  % (name, ofs, (r.stderr or r.stdout).strip().splitlines()[-1]))
    print("  %s: %d function(s) accepted" % (module, passed))
    return passed


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("modules", nargs="+", metavar="SEG:MODULE",
                    help="overlay segment and recovered source, e.g. 3381:ov_3381")
    ap.add_argument("--wait", type=int, default=30, help="seconds for the DOS build")
    a = ap.parse_args()

    total = 0
    for spec in a.modules:
        if ":" not in spec:
            raise SystemExit("expected SEG:MODULE, got " + spec)
        seghex, module = spec.split(":", 1)
        print("=== %s (%s) ===" % (module, seghex))
        exe, map_path = build_harness(module, a.wait)
        if not (os.path.exists(exe) and os.path.exists(map_path)):
            print("  link harness failed")
            continue
        total += verify_module(exe, map_path, seghex, module)
    print("total accepted:", total)


if __name__ == "__main__":
    main()
