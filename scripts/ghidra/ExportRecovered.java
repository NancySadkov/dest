// Recover the whole program into a source tree: one C file per module,
// plus types, globals and prototypes headers.
// Args: <outdir> [addressPrefixFilter]
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class ExportRecovered extends GhidraScript {
    private static final String IDCHARS =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_";

    private String sanitizeIdent(String s) {
        StringBuilder b = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (IDCHARS.indexOf(c) >= 0) b.append(c);
            else b.append('_');
        }
        String r = b.toString();
        if (r.isEmpty()) r = "x";
        if (Character.isDigit(r.charAt(0))) r = "_" + r;
        return r;
    }

    private String moduleName(MemoryBlock b) {
        if (b == null) return "unknown";
        String n = b.getName();
        if (n.matches("OVC\\d+.*")) {
            int us = n.indexOf('_');
            String num = n.substring(3, us >= 0 ? us : n.length());
            String rest = us >= 0 ? n.substring(us + 1) : "";
            int dot = rest.indexOf('.');
            if (dot >= 0) rest = rest.substring(0, dot);
            rest = sanitizeIdent(rest);
            if (rest.equals("x")) rest = "";
            return "ovc" + num + (rest.isEmpty() ? "" : "_" + rest);
        }
        if (n.matches("OVR\\d+.*")) return "ovr_stubs";
        if (n.contains("_TEXT_crtl")) return "crtl";
        if (n.contains("_TEXT_main")) return "main";
        if (n.contains("_TEXT_mouse")) return "mouse";
        if (n.contains("_TEXT_video")) return "video";
        if (n.contains("_OVRTEXT_")) return "ovl";
        if (n.contains("_TEXT_")) return sanitizeIdent(n.substring(n.indexOf("_TEXT_") + 6));
        return sanitizeIdent(n);
    }

    // Ghidra declares a parameter as `x` but sometimes prints uses of it as `_x`
    // (its disambiguator for a name that shadows something in scope).  The body
    // then references an identifier that nothing declares, which is a compile
    // error.  Rewrite `_x` back to `x` for names this function declares itself -
    // parameters and locals.  Names that are real program symbols are left alone:
    // Borland's runtime globals are also spelled with a leading underscore
    // (_drive, _c, _argv).
    private Set<String> allSymbolNames = null;
    private Set<String> allDataSymbolNames = null;

    private Set<String> symbolNames() {
        if (allSymbolNames == null) {
            allSymbolNames = new HashSet<>();
            for (ghidra.program.model.symbol.Symbol s
                    : currentProgram.getSymbolTable().getAllSymbols(false))
                allSymbolNames.add(s.getName());
        }
        return allSymbolNames;
    }

    // Names declared by the body's own declaration block, e.g. "  undefined1 uStack0004;"
    private void declaredLocals(String body, Set<String> out) {
        for (String line : body.split("\n")) {
            String t = line.trim();
            if (t.isEmpty() || t.startsWith("/*") || t.startsWith("*") || t.startsWith("#"))
                continue;
            if (!t.endsWith(";") || t.contains("(") || t.contains("=")) continue;
            t = t.substring(0, t.length() - 1).trim();
            int br = t.indexOf('[');
            if (br >= 0) t = t.substring(0, br).trim();
            java.util.regex.Matcher m =
                    java.util.regex.Pattern.compile("([A-Za-z_]\\w*)$").matcher(t);
            if (m.find()) out.add(m.group(1));
        }
    }

    private String fixShadowedParamUses(String body, String sig) {
        if (body == null || sig == null) return body;
        int lp = sig.indexOf('(');
        int rp = sig.lastIndexOf(')');
        Set<String> names = new HashSet<>();
        if (lp >= 0 && rp > lp) {
            String inner = sig.substring(lp + 1, rp);
            StringBuilder cur = new StringBuilder();
            int depth = 0;
            for (int i = 0; i <= inner.length(); i++) {
                char c = i < inner.length() ? inner.charAt(i) : ',';
                if (c == '(' || c == '[') depth++;
                if (c == ')' || c == ']') depth--;
                if (c == ',' && depth == 0) {
                    String p = cur.toString().trim();
                    cur.setLength(0);
                    if (p.isEmpty() || p.equals("void") || p.startsWith("...")) continue;
                    java.util.regex.Matcher m =
                            java.util.regex.Pattern.compile("([A-Za-z_]\\w*)\\s*$").matcher(p);
                    if (m.find() && !m.group(1).equals("void")) names.add(m.group(1));
                } else {
                    cur.append(c);
                }
            }
        }
        declaredLocals(body, names);
        if (names.isEmpty()) return body;
        Set<String> syms = symbolNames();
        Set<String> dataSyms = dataSymbolNames();
        StringBuffer out = new StringBuffer();
        java.util.regex.Matcher u =
                java.util.regex.Pattern.compile("\\b_(\\w+)\\b").matcher(body);
        while (u.find()) {
            String base = u.group(1);
            String prefixed = "_" + base;
            if (names.contains(base)) {
                // A name this function declares: Ghidra prefixed the use, not the
                // declaration.  Safe unless the prefixed spelling is itself real.
                if (names.contains(prefixed) || syms.contains(prefixed)) continue;
                u.appendReplacement(out, base);
            } else if (dataSyms.contains(base) && !names.contains(base)
                    && !syms.contains(prefixed)) {
                // A global that Ghidra also printed with a leading underscore.  Only
                // when nothing in this function shadows the plain name, so the use
                // cannot be redirected to a local.
                u.appendReplacement(out, base);
            }
        }
        u.appendTail(out);
        return out.toString();
    }

    private Set<String> dataSymbolNames() {
        if (allDataSymbolNames == null) {
            allDataSymbolNames = new HashSet<>();
            for (ghidra.program.model.symbol.Symbol s
                    : currentProgram.getSymbolTable().getAllSymbols(false))
                if (s.getSymbolType() != ghidra.program.model.symbol.SymbolType.FUNCTION)
                    allDataSymbolNames.add(s.getName());
        }
        return allDataSymbolNames;
    }

    // Two idioms Ghidra emits that C rejects, both rewritten to an exactly
    // equivalent legal form.  Kept deliberately narrow so nothing else changes.
    private static final java.util.regex.Pattern ARRAY_ASSIGN =
            java.util.regex.Pattern.compile(
                    "^(\\s*)([A-Za-z_]\\w*)\\s*=\\s*\\(\\s*byte\\s*\\[\\s*2\\s*\\]\\s*\\)\\s*\\(?(.*?)\\)?;\\s*$");

    private String fixUncompilableIdioms(String body) {
        if (body == null) return body;
        // `code` is a function type (needed by `(code *)swi(0x21)`), so the six
        // integral casts Ghidra emits against it are illegal.  The value is a
        // 16-bit quantity, so the cast becomes (unsigned short).
        body = body.replace("(code)", "(unsigned short)");
        // `x = (byte [2])(<lvalue>);` assigns an array.  Copy the two bytes.
        StringBuilder out = new StringBuilder();
        for (String line : body.split("\n", -1)) {
            java.util.regex.Matcher m = ARRAY_ASSIGN.matcher(line);
            if (m.matches()) {
                out.append(m.group(1)).append("memcpy(&").append(m.group(2))
                   .append(", &(").append(m.group(3)).append("), 2);");
            } else {
                out.append(line);
            }
            out.append('\n');
        }
        String s = out.toString();
        return s.endsWith("\n") ? s.substring(0, s.length() - 1) : s;
    }

    // `(char *)"literal" + N` is never string arithmetic: the value is
    // <address of the literal> + N, and Ghidra picked the nearest string symbol
    // to render a plain number.  Measured on this program, 211 of 452 such folds
    // are the single value 2410:2410 - the DGROUP segment constant 0x2410 in the
    // offset half of a far pointer whose segment the decompiler does not know.
    // Print the number instead of a fabricated string offset.
    // ---- fold de-symbolizer -------------------------------------------------
    // Ghidra renders a 16-bit constant by picking the nearest string symbol, so
    // the DGROUP segment 0x2410 prints as `(char *)"puppetmaker" + 3` when the
    // name-table entry happens to sit at 0x240d.  The value is exactly
    // <symbol address> + N, so replacing the whole expression with that number
    // is lossless and removes a false string reference.  Doing it inside the
    // exporter (not only in fix_recovered.py) means a partially written export
    // never shows the bogus form at all.
    private final Map<String, Long> foldAddr = new HashMap<String, Long>();

    private void buildFoldMap() {
        DataIterator it = currentProgram.getListing().getDefinedData(true);
        while (it.hasNext()) {
            Data d = it.next();
            try {
                Object v = d.getValue();
                if (!(v instanceof String)) continue;
                String k = foldKey((String) v);
                if (k.length() >= 4) {
                    Long prev = foldAddr.put(k, d.getAddress().getOffset());
                    // the same text at two addresses: Ghidra may have picked
                    // either one, so this key must not be rewritten blindly
                    if (prev != null) foldAddr.put(k, Long.valueOf(-1L));
                }
            } catch (Throwable t) {
                // unreadable data: skip it
            }
        }
    }

    private String foldKey(String t) {
        t = t.replace("\\r", " ").replace("\\n", " ").replace("\\t", " ");
        t = t.replace("\\'", "'").replace("\\\"", "\"");
        StringBuilder b = new StringBuilder();
        for (int i = 0; i < t.length(); i++) {
            char ch = t.charAt(i);
            b.append((Character.isLetterOrDigit(ch) || ch == ' ') ? ch : ' ');
        }
        String s = b.toString().toLowerCase();
        while (s.contains("  ")) s = s.replace("  ", " ");
        return s.trim();
    }

    private static final java.util.regex.Pattern FOLD =
            java.util.regex.Pattern.compile(
                "(?:\\(\\s*char\\s*\\*\\s*\\)\\s*)?\"((?:[^\"\\\\\\n]|\\\\.)*)\""
                + "\\s*\\+\\s*(0[xX][0-9a-fA-F]+|\\d+)\\b");

    private String desymbolizeFolds(String body) {
        if (body == null || foldAddr.isEmpty()) return body;
        java.util.regex.Matcher m = FOLD.matcher(body);
        StringBuffer out = new StringBuffer();
        int hits = 0;
        while (m.find()) {
            String dig = m.group(2);
            long delta;
            try {
                delta = (dig.startsWith("0x") || dig.startsWith("0X"))
                        ? Long.parseLong(dig.substring(2), 16) : Long.parseLong(dig);
            } catch (Exception e) {
                m.appendReplacement(out, java.util.regex.Matcher.quoteReplacement(m.group(0)));
                continue;
            }
            Long base = delta == 0 ? null : foldAddr.get(foldKey(m.group(1)));
            if (base == null || base.longValue() < 0) {
                // a genuine string reference keeps its literal (and any + 0)
                m.appendReplacement(out, java.util.regex.Matcher.quoteReplacement(m.group(0)));
                continue;
            }
            m.appendReplacement(out, java.util.regex.Matcher.quoteReplacement(
                    "(char *)0x" + Long.toHexString(base.longValue() + delta)));
            hits++;
        }
        m.appendTail(out);
        if (hits > 0) foldsRewritten += hits;
        return out.toString();
    }

    private int foldsRewritten = 0;

    // A Ghidra symbol can be namespace-qualified (switchD_6000:3cd8::caseD_0_3),
    // which is not a C identifier and breaks every module that includes the
    // generated header.  Replace the colons inside such a token only: the pattern
    // needs a word character after each ':' so strings like "%s: %d" and ternaries
    // "a ? b : c" are untouched.
    private static final java.util.regex.Pattern QUALIFIED_NAME =
            java.util.regex.Pattern.compile("[A-Za-z_]\\w*(?::+\\w+)+");

    private String sanitizeColons(String s) {
        if (s == null || s.indexOf(':') < 0) return s;
        java.util.regex.Matcher m = QUALIFIED_NAME.matcher(s);
        StringBuffer out = new StringBuffer();
        while (m.find())
            m.appendReplacement(out, m.group(0).replace(':', '_'));
        m.appendTail(out);
        return out.toString();
    }

    private String typeDecl(DataType dt, String name) {        if (dt instanceof Array) {
            Array a = (Array) dt;
            return typeDecl(a.getDataType(), name + "[" + a.getNumElements() + "]");
        }
        if (dt instanceof Pointer) {
            Pointer p = (Pointer) dt;
            return typeDecl(p.getDataType(), "*" + name);
        }
        if (dt instanceof TypeDef) {
            return dt.getName() + " " + name;
        }
        String dn = dt.getName();
        if (dn.contains("String")) return "char " + name + "[]";
        if (dt instanceof FunctionDefinition) return null;
        if (dt instanceof VoidDataType) return null;
        if (dt instanceof BitFieldDataType) return dt.getName() + " " + name;
        if (dt instanceof Dynamic) return "undefined " + name + "[]";
        String tn = dt.getDisplayName();
        if (tn == null || tn.length() == 0 || tn.equals("undefined")) tn = "undefined";
        return tn + " " + name;
    }

    private String extractSignature(String content) {
        String s = content.replaceAll("(?s)/\\*.*?\\*/", " ");
        int brace = s.indexOf('{');
        if (brace < 0) return null;
        s = s.substring(0, brace).trim().replaceAll("\\s+", " ");
        if (!s.endsWith(")")) return null;
        return s + ";";
    }

    private void writeTypes(File f) throws Exception {
        File tmp = new File(f.getPath() + ".tmp");
        Writer w = new FileWriter(tmp);
        DataTypeWriter dtw = new DataTypeWriter(currentProgram.getDataTypeManager(), w, false);
        dtw.write(currentProgram.getDataTypeManager(), monitor);
        w.close();
        // Borland/Turbo C++ 3.0 is a 16-bit compiler and has no 64-bit integer
        // type. Keep the generated header parseable by degrading 64-bit
        // placeholders to 32 bits; the few CRT routines that truly need 64 bits
        // are not part of the game-code rebuild.
        StringBuilder sb = new StringBuilder();
        BufferedReader r = new BufferedReader(new FileReader(tmp));
        String line;
        while ((line = r.readLine()) != null) {
            line = line.replace("unsigned long long", "unsigned long");
            line = line.replace("signed long long", "signed long");
            line = line.replace("long long", "long");
            sb.append(line).append('\n');
        }
        r.close();
        tmp.delete();
        PrintWriter out = new PrintWriter(new FileWriter(f));
        out.print(sb.toString());
        out.close();
    }

    private void writeGlobals(File dir) throws Exception {
        PrintWriter h = new PrintWriter(new FileWriter(new File(dir, "st_globals.h")));
        PrintWriter c = new PrintWriter(new FileWriter(new File(dir, "st_globals.c")));
        h.println("/* Global data recovered from the original image. */");
        h.println("#ifndef ST_GLOBALS_H");
        h.println("#define ST_GLOBALS_H");
        c.println("#include \"recovered.h\"");
        Set<String> seen = new HashSet<String>();
        Set<Long> seenAddr = new HashSet<Long>();
        SymbolTable st = currentProgram.getSymbolTable();
        Listing lst = currentProgram.getListing();
        List<Symbol> syms = new ArrayList<Symbol>();
        for (Symbol s : st.getAllSymbols(true)) {
            if (s.getSymbolType() == SymbolType.FUNCTION) continue;
            if (s.getParentNamespace().getID() != currentProgram.getGlobalNamespace().getID()) continue;
            if (!s.isPrimary()) continue;
            String n = s.getName();
            if (n.contains(".") || n.contains("[") || n.contains("+") || n.contains("::")) continue;
            if (n.startsWith("LAB_") || n.startsWith("switchD_") || n.startsWith("caseD_")) continue;
            syms.add(s);
        }
        syms.sort(new Comparator<Symbol>() {
            public int compare(Symbol a, Symbol b) {
                return a.getAddress().compareTo(b.getAddress());
            }
        });
        for (Symbol s : syms) {
            String n = s.getName();
            if (seen.contains(n)) continue;
            Data d = lst.getDataAt(s.getAddress());
            if (d == null) continue;
            long key = s.getAddress().getOffset();
            if (seenAddr.contains(key)) continue;
            String decl = typeDecl(d.getDataType(), n);
            if (decl == null) continue;
            seen.add(n);
            seenAddr.add(key);
            h.println("extern " + decl + ";");
            c.println(decl + ";");
        }
        h.println("#endif");
        h.close();
        c.close();
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outdir = args.length > 0 ? args[0] : "recovered";
        String filter = args.length > 1 ? args[1] : "";
        File dir = new File(outdir);
        dir.mkdirs();
        // Hand-corrected function bodies live outside the generated tree, so
        // src/decompiled stays one flat folder of module .c files.  The store is
        // <repo>/overrides; a legacy <outdir>/hard is still honoured.
        File ovrDir = new File(dir.getAbsoluteFile().getParentFile().getParentFile(),
                               "overrides");
        if (!ovrDir.isDirectory() && new File(dir, "hard").isDirectory())
            ovrDir = new File(dir, "hard");
        println("overrides: " + ovrDir);

        // types
        writeTypes(new File(dir, "st_types.h"));
        // globals
        writeGlobals(dir);

        // string symbol address table, used to de-symbolize `"lit" + N`
        buildFoldMap();
        println("fold symbols: " + foldAddr.size());

        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        DecompileOptions opts = new DecompileOptions();
        opts.setProtoEvalModel("__cdecl16far");
        // Keep integer constants as integers: the constant-pointer heuristic
        // renders key codes as expressions like (char *)"sword4.voc" + 8.
        opts.setInferConstantPointers(false);
        ifc.setOptions(opts);

        // group functions by module
        LinkedHashMap<String, List<Function>> mods = new LinkedHashMap<String, List<Function>>();
        FunctionManager fm = currentProgram.getFunctionManager();
        for (Function f : fm.getFunctions(true)) {
            if (f.isThunk()) continue;
            if (filter.length() > 0 && !f.getEntryPoint().toString().startsWith(filter)) continue;
            MemoryBlock b = currentProgram.getMemory().getBlock(f.getEntryPoint());
            if (b == null || !b.isExecute()) continue;
            if (b.getName().startsWith("DOS21") || b.getName().contains("FakeVdisk")) continue;
            String m = moduleName(b);
            List<Function> l = mods.get(m);
            if (l == null) { l = new ArrayList<Function>(); mods.put(m, l); }
            l.add(f);
        }

        PrintWriter idx = new PrintWriter(new FileWriter(new File(dir, "index.tsv")));
        idx.println("module\taddress\tname\tsize\tstatus\tfile\tsignature");
        PrintWriter protos = new PrintWriter(new FileWriter(new File(dir, "st_functions.h")));
        protos.println("/* Recovered function prototypes. */");
        protos.println("#ifndef ST_FUNCTIONS_H");
        protos.println("#define ST_FUNCTIONS_H");
        Set<String> emitted = new HashSet<String>();
        int ok = 0, fail = 0;
        List<String> failed = new ArrayList<String>();

        for (Map.Entry<String, List<Function>> e : mods.entrySet()) {
            String mod = e.getKey();
            List<Function> funcs = e.getValue();
            funcs.sort(new Comparator<Function>() {
                public int compare(Function a, Function b) {
                    return a.getEntryPoint().compareTo(b.getEntryPoint());
                }
            });
            PrintWriter w = new PrintWriter(new FileWriter(new File(dir, mod + ".c")));
            MemoryBlock b = currentProgram.getMemory().getBlock(funcs.get(0).getEntryPoint());
            w.println("/*");
            w.println(" * " + mod + ".c - recovered from STRONG.EXE");
            w.println(" * memory block: " + (b != null ? b.getName() : "?"));
            if (b != null) w.println(" * range: " + b.getStart() + " - " + b.getEnd());
            w.println(" * functions: " + funcs.size());
            w.println(" */");
            w.println("#include \"recovered.h\"");
            w.println();
            for (Function f : funcs) {
                String name = f.getName();
                DecompileResults res = null;
                boolean good = false;
                String msg = "";
                int fsize = (int) f.getBody().getNumAddresses();
                try {
                    int t1 = fsize > 3000 ? 60 : 90;
                    res = ifc.decompileFunction(f, t1, monitor);
                    good = res != null && res.decompileCompleted();
                    if (!good && fsize <= 2000) {
                        res = ifc.decompileFunction(f, 240, monitor);
                        good = res != null && res.decompileCompleted();
                    }
                } catch (Throwable t) {
                    msg = t.toString();
                }
                w.println();
                w.println("/* " + f.getEntryPoint() + " */");
                if (good) {
                    String body = res.getDecompiledFunction().getC();
                    String sig = res.getDecompiledFunction().getSignature();
                    // A symbol whose name contains ':' (a namespace qualifier such as
                    // switchD_6000:3cd8::caseD_0_3) is not a C identifier and breaks
                    // every module that includes the header.  Sanitise the exact name
                    // in both the body and the signature so they stay consistent.
                    body = sanitizeColons(body);
                    sig = sanitizeColons(sig);
                    // A hand-corrected body wins over the decompiler's.  This is the
                    // escape hatch for functions whose code the decompiler gets
                    // structurally wrong and no model type can repair - the written
                    // body keeps the decompiler's signature line, so the header and
                    // the definition still agree.
                    File ovr = new File(ovrDir, mod + "__" + sanitizeIdent(name) + ".c");
                    if (ovr.isFile()) {
                        StringBuilder ob = new StringBuilder();
                        BufferedReader orr = new BufferedReader(new FileReader(ovr));
                        String ol;
                        while ((ol = orr.readLine()) != null) ob.append(ol).append('\n');
                        orr.close();
                        body = ob.toString();
                        println("override " + mod + " " + name + " <- " + ovr.getName());
                    }
                    body = fixUncompilableIdioms(desymbolizeFolds(fixShadowedParamUses(body, sig)));
                    w.println(body);
                    if (emitted.add(name)) {
                        if (!sig.endsWith(";")) sig += ";";
                        protos.println(sig);
                    }
                    idx.println(mod + "\t" + f.getEntryPoint() + "\t" + name + "\t"
                            + fsize + "\tok\t" + mod + ".c\t" + sig.replace('\t',' '));
                    ok++;
                } else {
                    if (msg.isEmpty()) msg = res == null ? "null" : res.getErrorMessage();
                    if (msg == null) msg = "unknown";
                    File hard = new File(ovrDir, mod + "__" + sanitizeIdent(name) + ".c");
                    if (hard.isFile()) {
                        StringBuilder sb = new StringBuilder();
                        BufferedReader hr = new BufferedReader(new FileReader(hard));
                        String ln;
                        while ((ln = hr.readLine()) != null) sb.append(ln).append('\n');
                        hr.close();
                        w.println("/* recovered by relaxed-limit retry */");
                        w.println(sb.toString());
                        String hs = extractSignature(sb.toString());
                        if (hs != null && emitted.add(name)) protos.println(hs);
                        idx.println(mod + "\t" + f.getEntryPoint() + "\t" + name + "\t"
                                + fsize + "\tok-hard\t" + mod + ".c\trelaxed retry");
                        ok++;
                    } else {
                        w.println("/* DECOMPILATION FAILED: " + msg.replace("*/", "* /") + " */");
                        w.println("undefined " + sanitizeIdent(name) + "() { return 0; }");
                        idx.println(mod + "\t" + f.getEntryPoint() + "\t" + name + "\t"
                                + fsize + "\tfail\t" + mod + ".c\t" + msg.replace('\t',' '));
                        failed.add(mod + " " + f.getEntryPoint() + " " + name + " : " + msg);
                        fail++;
                    }
                }
            }
            w.close();
        }
        // Fallback prototypes for functions that failed in this run (a relaxed
        // retry may still provide the body from overrides/).
        for (Function f : fm.getFunctions(true)) {
            if (f.isThunk()) continue;
            MemoryBlock fb = currentProgram.getMemory().getBlock(f.getEntryPoint());
            if (fb == null || !fb.isExecute()) continue;
            if (fb.getName().startsWith("DOS21") || fb.getName().contains("FakeVdisk")) continue;
            if (emitted.add(f.getName()))
                protos.println("undefined " + sanitizeColons(f.getName()) + "();");
        }
        // overlay thunk prototypes (calls in recovered code go through these)
        for (Function f : fm.getFunctions(true)) {
            if (!f.isThunk()) continue;
            if (emitted.add(f.getName()))
                protos.println("undefined " + sanitizeColons(f.getName()) + "();");
        }
        protos.println("/* helper for Ghidra's (far_t) scalar casts */");
        protos.println("far_t far_from_u32(uint32_t v);");
        protos.println("#endif");
        protos.close();
        idx.close();

        // module dispatcher header + stub file for overlay thunks
        PrintWriter rh = new PrintWriter(new FileWriter(new File(dir, "recovered.h")));
        rh.println("/* Aggregated header for the auto-recovered source tree. */");
        rh.println("#ifndef ST_RECOVERED_H");
        rh.println("#define ST_RECOVERED_H");
        rh.println("#include \"st_compat.h\"");
        rh.println("#include \"st_types.h\"");
        rh.println("#include \"st_globals.h\"");
        rh.println("#include \"st_functions.h\"");
        rh.println("#endif");
        rh.close();

        PrintWriter ch = new PrintWriter(new FileWriter(new File(dir, "st_compat.h")));
        ch.println("/* Compatibility shims for Ghidra's decompiler output. */");
        ch.println("#ifndef ST_COMPAT_H");
        ch.println("#define ST_COMPAT_H");
        ch.println("#ifdef __BORLANDC__");
        ch.println("#define __cdecl16far");
        ch.println("#define __cdecl16near __cdecl");
        ch.println("#define __stdcall16far __pascal");
        ch.println("#define __stdcall16near __pascal");
        ch.println("#else");
        ch.println("#define __cdecl16far");
        ch.println("#define __cdecl16near");
        ch.println("#define __stdcall16far");
        ch.println("#define __stdcall16near");
        ch.println("#define __cdecl");
        ch.println("#define __pascal");
        ch.println("#define __fastcall");
        ch.println("#define far");
        ch.println("#define near");
        ch.println("#endif");
        ch.println("typedef unsigned short code();");
        ch.println("typedef unsigned short blitfn_t();");
        // Ghidra names its 3-byte working types int3/uint3/undefined3.  C has no
        // 3-byte integer; CONCAT13/31 and SUB41/42 cast their operand to the
        // width they need, so a 32-bit carrier is enough to compile.
        ch.println("typedef unsigned long int3;");
        ch.println("typedef unsigned long uint3;");
        ch.println("typedef unsigned long undefined3;");
        ch.println("code *swi(int vector);");
        ch.println("#define MK_FP(seg,ofs) ((void far *)(((uint32_t)(seg) << 16) | (uint16_t)(ofs)))");
        ch.println("#define CONCAT11(a,b) ((uint16_t)(((uint8_t)(a) << 8) | (uint8_t)(b)))");
        ch.println("#define CONCAT12(a,b) ((uint16_t)(((uint8_t)(a) << 8) | (uint16_t)(b)))");
        ch.println("#define CONCAT13(a,b) ((uint16_t)(((uint8_t)(a) << 8) | (uint16_t)(b)))");
        ch.println("#define CONCAT14(a,b) CONCAT12(a,b)");
        ch.println("#define CONCAT21(a,b) ((uint16_t)(((uint16_t)(a) >> 8) | ((uint16_t)(b) << 8)))");
        ch.println("#define CONCAT22(a,b) ((uint32_t)(((uint16_t)(a) << 16) | (uint16_t)(b)))");
        ch.println("#define CONCAT31(a,b) CONCAT22(a,b)");
        ch.println("#define CONCAT44(a,b) ((uint32_t)(((uint32_t)(a) << 16) | (uint16_t)(b)))");
        ch.println("#define CARRY1(a,b) ((uint8_t)((uint16_t)(a) + (uint16_t)(b) > 0xff))");
        ch.println("#define CARRY2(a,b) ((uint8_t)((uint32_t)(a) + (uint32_t)(b) > 0xffff))");
        ch.println("#define CARRY4(a,b) ((uint8_t)((uint32_t)(a) + (uint32_t)(b) < (uint32_t)(a)))");
        ch.println("#define SBORROW1(a,b) ((uint8_t)((int16_t)(int8_t)(a) - (int16_t)(int8_t)(b) < -0x80))");
        ch.println("#define SBORROW2(a,b) ((uint8_t)((int32_t)(int16_t)(a) - (int32_t)(int16_t)(b) < -0x8000))");
        ch.println("#define SBORROW4(a,b) ((uint8_t)((int32_t)(a) - (int32_t)(b) < 0))");
        ch.println("#define SUB41(x,n) ((uint8_t)((uint16_t)(x) >> ((n)*8)))");
        ch.println("#define SUB42(x,n) ((uint16_t)((uint32_t)(x) >> ((n)*8)))");
        ch.println("#define SUB84(x,n) ((uint32_t)(x) >> ((n)*8))");
        ch.println("#define SEXT12(x) ((int16_t)(int8_t)(x))");
        ch.println("#define SEXT13(x) SEXT12(x)");
        ch.println("#define SEXT14(x) SEXT12(x)");
        ch.println("#define SEXT21(x) ((int32_t)(int16_t)(x))");
        ch.println("#define SEXT22(x) SEXT21(x)");
        ch.println("#define SEXT24(x) SEXT21(x)");
        ch.println("#define SEXT31(x) ((int32_t)(int8_t)(x))");
        ch.println("#define SEXT41(x) SEXT31(x)");
        ch.println("#define ZEXT12(x) ((uint16_t)(uint8_t)(x))");
        ch.println("#define ZEXT14(x) ZEXT12(x)");
        ch.println("#define ZEXT21(x) ((uint32_t)(uint16_t)(x))");
        ch.println("#define ZEXT22(x) ZEXT21(x)");
        ch.println("#define ZEXT24(x) ZEXT21(x)");
        ch.println("#define ZEXT41(x) ((uint32_t)(uint8_t)(x))");
        ch.println("#endif");
        ch.close();

        PrintWriter os = new PrintWriter(new FileWriter(new File(dir, "ovr_stubs.c")));
        os.println("/* Borland VROOMM overlay thunks (INT 3Fh). */");
        os.println("#include \"recovered.h\"");
        int nth = 0;
        for (Function f : fm.getFunctions(true)) {
            if (!f.isThunk()) continue;
            Function t = f.getThunkedFunction(true);
            os.println("/* " + f.getEntryPoint() + " -> " + (t == null ? "?" : t.getName()) + " */");
            nth++;
        }
        os.close();

        PrintWriter man = new PrintWriter(new FileWriter(new File(dir, "MANIFEST.md")));
        man.println("# Recovered source manifest\n");
        man.println("Auto-generated by `scripts/ghidra/ExportRecovered.java`.");
        man.println("Modules: " + mods.size() + ", functions: " + (ok + fail)
                + " (ok " + ok + ", failed " + fail + "), overlay thunks: " + nth + ".\n");
        man.println("| module | functions |");
        man.println("|---|---|");
        for (Map.Entry<String, List<Function>> e : mods.entrySet())
            man.println("| " + e.getKey() + " | " + e.getValue().size() + " |");
        if (!failed.isEmpty()) {
            man.println("\n## Failed decompilations\n");
            for (String s : failed) man.println("- " + s);
        }
        man.close();
        println("recovered modules=" + mods.size() + " ok=" + ok + " fail=" + fail + " thunks=" + nth
                + " folds-rewritten=" + foldsRewritten);
    }
}
