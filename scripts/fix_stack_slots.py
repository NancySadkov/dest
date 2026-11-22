"""Give the untyped stack operands real stack storage.

Ghidra sometimes fails to create a variable for a stack operand and renders the
address itself: `&stack0xfffe`, `&stack0xfffa[i]`, `(int *)(&stack0xfff8 + n)`.
The exporter turns those into `extern undefined1 stack0xNNNN;`, i.e. a DGROUP
global - so the program would read and write the wrong memory, and TLINK reports
51 undefined symbols.

The usage shows what they are: the *address of a stack slot*, addressed as bytes
(every access is `&slot + i` or a cast through it).  So each one becomes a local
byte in the function that uses it:

    undefined1 stk_fffe;

which gives the same address arithmetic inside the real frame.  The offset is the
name, so nothing is invented beyond "this is a byte-addressable stack slot", which
is what the accesses already say.

usage: python scripts/fix_stack_slots.py [--apply]
"""
import glob
import io
import re
import sys

apply = "--apply" in sys.argv

PAT = re.compile(r"\bstack0x([0-9a-fA-F]+)\b")

files = sorted(glob.glob("src/decompiled/*.c"))
functions = 0
slots = 0
files_changed = 0

for path in files:
    lines = io.open(path, encoding="utf-8", errors="ignore").read().split("\n")
    if not any("stack0x" in l for l in lines):
        continue
    out = []
    i = 0
    changed_here = 0
    while i < len(lines):
        line = lines[i]
        if line.strip() == "{":
            # function body: gather until depth returns to zero
            depth = 0
            j = i
            body = []
            while j < len(lines):
                depth += lines[j].count("{") - lines[j].count("}")
                body.append(lines[j])
                if depth == 0:
                    break
                j += 1
            text = "\n".join(body)
            names = sorted(set(PAT.findall(text)))
            if names:
                functions += 1
                decls = ["  undefined1 stk_%s;   /* stack slot %s */" % (n, n)
                         for n in names]
                slots += len(names)
                changed_here += len(names)
                # insert right after the opening brace
                body = body[:1] + decls + body[1:]
                text = "\n".join(body)
                text = PAT.sub(lambda m: "stk_" + m.group(1), text)
                out.extend(text.split("\n"))
                i = j + 1
                continue
        out.append(line)
        i += 1
    if changed_here:
        files_changed += 1
        if apply:
            io.open(path, "w", encoding="utf-8", newline="\n").write("\n".join(out))

print("functions given stack slots:", functions)
print("slots materialised:", slots, "in", files_changed, "files")
print("mode:", "APPLY" if apply else "dry run")
