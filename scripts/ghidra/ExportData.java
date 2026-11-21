// Export global data with initialisers recovered from the original image.
// Args: outfile
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class ExportData extends GhidraScript {
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

    private String typeDecl(DataType dt, String name) {
        if (dt instanceof Array) {
            Array a = (Array) dt;
            return typeDecl(a.getDataType(), name + "[" + a.getNumElements() + "]");
        }
        if (dt instanceof Pointer) {
            Pointer p = (Pointer) dt;
            return typeDecl(p.getDataType(), "*" + name);
        }
        if (dt instanceof TypeDef) return dt.getName() + " " + name;
        String dn = dt.getName();
        if (dn.contains("String")) return "char " + name + "[]";
        if (dt instanceof FunctionDefinition) return null;
        if (dt instanceof VoidDataType) return null;
        if (dt instanceof Dynamic) return "undefined " + name + "[]";
        String tn = dt.getDisplayName();
        if (tn == null || tn.length() == 0 || tn.equals("undefined")) tn = "undefined";
        return tn + " " + name;
    }

    private boolean isFarStruct(DataType dt) {
        if (dt == null) return false;
        if (dt instanceof Structure) return true;
        String n = dt.getName();
        if (n != null && (n.equals("far_t") || n.equals("Pfar_t"))) return true;
        if (dt instanceof TypeDef) {
            DataType base = ((TypeDef) dt).getDataType();
            if (base instanceof Structure) return true;
            String bn = base.getName();
            return bn != null && bn.equals("far_t");
        }
        return false;
    }

    private String toC(String rep, DataType dt) {
        if (rep == null) return "0";
        rep = rep.trim();
        if (rep.length() == 0) return "0";
        if (rep.startsWith("\"") || rep.startsWith("'")) return rep;
        if (rep.equalsIgnoreCase("true")) return "1";
        if (rep.equalsIgnoreCase("false")) return "0";
        if (rep.equalsIgnoreCase("NULL")) return "0";

        // Ghidra sometimes appends a rendered ASCII column: "0x20     ".
        if (rep.matches("^-?0x[0-9A-Fa-f]+\\s+.*")) rep = rep.split("\\s+")[0];
        if (rep.matches("^-?[0-9A-Fa-f]+h\\s+.*")) rep = rep.split("\\s+")[0];

        // Segmented address SSSS:OOOO.
        java.util.regex.Matcher sa = java.util.regex.Pattern
                .compile("^([0-9A-Fa-f]{1,4}):([0-9A-Fa-f]{1,4})$").matcher(rep);
        if (sa.matches()) {
            String seg = sa.group(1);
            String off = sa.group(2);
            if (dt instanceof Pointer) {
                return "(void far *)(0x" + seg + "0000UL + 0x" + off + "UL)";
            }
            if (isFarStruct(dt)) {
                return "{ 0x" + off + ", 0x" + seg + " }";
            }
            return "0x" + seg + "0000UL + 0x" + off + "UL";
        }

        // Borland-style hex suffix forms: 0h, Ah, BB8h, -1h.
        java.util.regex.Matcher hm = java.util.regex.Pattern
                .compile("^(-?)(?:0x)?([0-9A-Fa-f]+)h$").matcher(rep);
        if (hm.matches()) return hm.group(1) + "0x" + hm.group(2);

        return rep;
    }

    // Ghidra renders a char array whose text is followed by a non-printable byte
    // as  "Auto-build    ",7Fh  -- Borland assembly syntax, not C.  Turn the
    // suffix into an adjacent string literal so the bytes are unchanged:
    //   "Auto-build    " "\x7f"
    private static final java.util.regex.Pattern STR_TAIL =
            java.util.regex.Pattern.compile("^([0-9A-Fa-f]{1,2})h$");

    private String fixStringRep(String rep) {
        if (rep == null) return null;
        int comma = rep.lastIndexOf(',');
        if (comma < 0) return rep;
        java.util.regex.Matcher m = STR_TAIL.matcher(rep.substring(comma + 1).trim());
        if (!m.matches()) return rep;
        int v = Integer.parseInt(m.group(1), 16);
        return rep.substring(0, comma) + " \"\\x" + String.format("%02x", v) + "\"";
    }

    private String initOf(Data d, int depth) throws Exception {
        if (depth > 8) return "0";
        DataType dt = d.getDataType();
        String rep = d.getDefaultValueRepresentation();
        if (rep != null && rep.trim().startsWith("\"")) {
            String r = fixStringRep(rep.trim());
            // A char array whose bytes are a mix of text and numbers comes back as
            // one representation: "$",04h,02h,...  That is not a C initialiser.
            // Convert every quoted run to character constants and brace the list.
            boolean charArray = false;
            if (dt instanceof Array) {
                String et = ((Array) dt).getDataType().getName().toLowerCase();
                charArray = et.contains("char") || et.contains("byte");
            }
            if (charArray && r.indexOf("\"") >= 0 && r.substring(r.indexOf("\"") + 1).contains(",")) {
                StringBuilder out = new StringBuilder("{ ");
                int i = 0;
                boolean first = true;
                while (i < r.length()) {
                    char c = r.charAt(i);
                    if (c == '"') {
                        int j = i + 1;
                        StringBuilder body = new StringBuilder();
                        while (j < r.length() && r.charAt(j) != '"') {
                            if (r.charAt(j) == '\\' && j + 1 < r.length()) {
                                body.append(r.charAt(j)).append(r.charAt(j + 1));
                                j += 2;
                            } else {
                                body.append(r.charAt(j));
                                j++;
                            }
                        }
                        String bd = body.toString();
                        int k = 0;
                        while (k < bd.length()) {
                            if (!first) out.append(", ");
                            first = false;
                            if (bd.charAt(k) == '\\' && k + 1 < bd.length()) {
                                int L = escLen(bd, k);
                                out.append("'").append(bd, k, k + L).append("'");
                                k += L;
                            } else {
                                char ch = bd.charAt(k);
                                if (ch == '\'') out.append("'\\''");
                                else out.append("'").append(ch).append("'");
                                k++;
                            }
                        }
                        i = j + 1;
                        continue;
                    }
                    if (c == ',' || c == ' ') { i++; continue; }
                    int st = i;
                    while (i < r.length() && r.charAt(i) != ',' && r.charAt(i) != ' ') i++;
                    if (!first) out.append(", ");
                    first = false;
                    out.append(r, st, i);
                }
                out.append(" }");
                return out.toString();
            }
            return r;
        }
        if (dt instanceof Pointer) return toC(rep, dt);
        if (dt.getName().contains("String") && rep != null && rep.trim().startsWith("\""))
            return fixStringRep(rep.trim());
        if (dt instanceof Dynamic) return "{ " + toC(rep, null) + " }";
        if (dt instanceof Array && d.getNumComponents() == 0)
            return "{ " + toC(rep, ((Array) dt).getDataType()) + " }";
        int n = d.getNumComponents();
        if (n > 0) {
            if (d.isUnion()) return "{ " + initOf(d.getComponent(0), depth + 1) + " }";
            StringBuilder b = new StringBuilder("{ ");
            String elemType = (dt instanceof Array)
                    ? ((Array) dt).getDataType().getName().toLowerCase() : "";
            boolean charArray = elemType.contains("char") || elemType.contains("byte");
            for (int i = 0; i < n; i++) {
                if (i > 0) b.append(", ");
                String el = initOf(d.getComponent(i), depth + 1);
                // inside a char/byte array a quoted run is not a legal sibling of
                // scalar elements; turn it into character constants
                if (charArray && el.trim().startsWith("\"")) {
                    String body = el.trim();
                    body = body.substring(1, body.length() - 1);
                    StringBuilder cb = new StringBuilder();
                    int k = 0;
                    while (k < body.length()) {
                        if (cb.length() > 0) cb.append(", ");
                        if (body.charAt(k) == '\\' && k + 1 < body.length()) {
                            int L = escLen(body, k);
                            cb.append("'").append(body, k, k + L).append("'");
                            k += L;
                        } else {
                            char ch = body.charAt(k);
                            if (ch == '\'') cb.append("'\\''");
                            else cb.append("'").append(ch).append("'");
                            k++;
                        }
                    }
                    el = cb.toString();
                }
                b.append(el);
            }
            b.append(" }");
            return b.toString();
        }
        return toC(rep, dt);
    }

    // Turbo C has a small maximum logical-line length; one 34 KB line for
    // agntG_t AgntGs[42] produced ", expected" / "Declaration syntax error" /
    // "Unexpected }" at that line even though the text is well formed.  Break the
    // initialiser at commas so no physical line is long.
    // Ghidra renders runs of raw bytes inside a char array in assembler style:
    //   "$",04h,02h ... 82h,E9h "\xff"
    // C needs `0x` prefixes, and the byte before a quoted run is missing its
    // comma.  Both are text-level fixes on the emitted initialiser.
    private String sanitizeAsmBytes(String t) {
        java.util.regex.Pattern h = java.util.regex.Pattern
                .compile("(?<![0-9A-Za-z_])([0-9A-Fa-f]{1,2})h(?![0-9A-Za-z_])");
        String r = h.matcher(t).replaceAll("0x$1");
        java.util.regex.Pattern miss = java.util.regex.Pattern
                .compile("(0x[0-9A-Fa-f]+)\\s+\"");
        return miss.matcher(r).replaceAll("$1, \"");
    }

    // Inside a braced byte list Ghidra emits quoted runs ("$", "\t", "\xff")
    // which C does not allow next to scalar elements.  Convert them to character
    // constants; a value that is a single string (the whole initialiser) is left
    // alone so ordinary string globals stay readable.
    private String stringsToChars(String init) {
        if (init == null || init.trim().startsWith("\"")) return init;
        StringBuilder out = new StringBuilder();
        int i = 0;
        while (i < init.length()) {
            char c = init.charAt(i);
            if (c != '"') {
                out.append(c);
                i++;
                continue;
            }
            int j = i + 1;
            StringBuilder lit = new StringBuilder();
            while (j < init.length() && init.charAt(j) != '"') {
                if (init.charAt(j) == '\\' && j + 1 < init.length()) {
                    lit.append(init.charAt(j)).append(init.charAt(j + 1));
                    j += 2;
                } else {
                    lit.append(init.charAt(j));
                    j++;
                }
            }
            if (j >= init.length()) {          // unterminated: leave it
                out.append(init.substring(i));
                break;
            }
            String body = lit.toString();
            // split a multi-character run into one constant per byte
            java.util.List<String> parts = new java.util.ArrayList<String>();
            int k = 0;
            while (k < body.length()) {
                if (body.charAt(k) == '\\') {
                    parts.add(body.substring(k, Math.min(k + 2, body.length())));
                    k += 2;
                } else {
                    parts.add(String.valueOf(body.charAt(k)));
                    k++;
                }
            }
            for (String part : parts) {
                if (out.length() > 0) out.append(", ");
                if (part.startsWith("\\")) out.append("'").append(part).append("'");
                else if (part.equals("'")) out.append("'\\''");
                else out.append("'").append(part).append("'");
            }
            i = j + 1;
        }
        return out.toString();
    }

    private static int escLen(String s, int k) {
        if (s.charAt(k) != '\\' || k + 1 >= s.length()) return 1;
        char n = Character.toLowerCase(s.charAt(k + 1));
        if (n == 'x') {
            int j = k + 2;
            int digits = 0;
            while (j < s.length() && digits < 2
                    && Character.digit(s.charAt(j), 16) >= 0) { j++; digits++; }
            return j - k;
        }
        int j = k + 1;
        int digits = 0;
        while (j < s.length() && digits < 3
                && s.charAt(j) >= '0' && s.charAt(j) <= '7') { j++; digits++; }
        return Math.max(2, j - k);
    }

    private void writeWrapped(PrintWriter w, String text) {
        int limit = 100;
        StringBuilder line = new StringBuilder();
        boolean inStr = false, inChr = false, esc = false;
        for (int i = 0; i < text.length(); i++) {
            char c = text.charAt(i);
            line.append(c);
            if (esc) {
                esc = false;
                continue;
            }
            if (c == '\\' && (inStr || inChr)) {
                esc = true;
                continue;
            }
            if (inStr) {
                if (c == '"') inStr = false;
                continue;
            }
            if (inChr) {
                if (c == '\'') inChr = false;
                continue;
            }
            if (c == '"') { inStr = true; continue; }
            if (c == '\'') { inChr = true; continue; }
            // never split inside a literal; break after a comma once the line is long
            if (line.length() >= limit && c == ',') {
                w.println(line.toString());
                line.setLength(0);
                line.append("    ");
            }
        }
        if (line.length() > 0) w.println(line.toString());
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String out = args.length > 0 ? args[0] : "st_data.c";
        PrintWriter w = new PrintWriter(new FileWriter(out));
        w.println("/* Global data with original initialisers (recovered image). */");
        w.println("#include \"recovered.h\"");
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
            public int compare(Symbol a, Symbol b) { return a.getAddress().compareTo(b.getAddress()); }
        });
        // Reuse the declarations from st_globals.h so the definition and the
        // extern declaration can never disagree (two independent typeDecl
        // copies used to disagree for strings and a few pointer globals).
        Map<String, String> headerDecl = new HashMap<String, String>();
        File hdr = new File(out).getParentFile() == null ? null
                : new File(new File(out).getParentFile(), "st_globals.h");
        if (hdr != null && hdr.isFile()) {
            BufferedReader hr = new BufferedReader(new FileReader(hdr));
            String hl;
            while ((hl = hr.readLine()) != null) {
                hl = hl.trim();
                if (!hl.startsWith("extern ") || !hl.endsWith(";")) continue;
                String d = hl.substring("extern ".length(), hl.length() - 1).trim();
                // a pointer to an array is declared `T (far *name)[dims]`, where the
                // identifier sits inside the parentheses, so the plain trailing-name
                // pattern does not see it
                java.util.regex.Matcher pa = java.util.regex.Pattern
                        .compile("\\(\\s*(?:far\\s*)?\\*\\s*([A-Za-z_]\\w*)\\s*\\)").matcher(d);
                java.util.regex.Matcher nm = java.util.regex.Pattern
                        .compile("^(.*?)([A-Za-z_]\\w*)\\s*(\\[[^\\]]*\\])?$").matcher(d);
                if (pa.find()) headerDecl.put(pa.group(1), d);
                else if (nm.matches()) headerDecl.put(nm.group(2), d);
            }
            hr.close();
            println("header declarations: " + headerDecl.size());
        }

        int n = 0;
        for (Symbol s : syms) {
            String name = s.getName();
            if (seen.contains(name)) continue;
            long key = s.getAddress().getOffset();
            if (seenAddr.contains(key)) continue;
            Data d = lst.getDataAt(s.getAddress());
            if (d == null) continue;
            MemoryBlock b = currentProgram.getMemory().getBlock(s.getAddress());
            if (b == null) continue;
            String decl = headerDecl.get(name);
            if (decl == null) decl = typeDecl(d.getDataType(), name);
            if (decl == null) continue;
            seen.add(name);
            seenAddr.add(key);
            if (b.isInitialized()) {
                try {
                    String init = initOf(d, 0);
                    // a string literal needs an array declaration; typeDecl can
                    // return `undefined name[]` for a char datum, which then
                    // clashes with the `extern char name[]` in the header
                    if (init.trim().startsWith("\"") && !headerDecl.containsKey(name))
                        decl = "char " + name + "[]";
                    writeWrapped(w, sanitizeAsmBytes(decl + " = " + init + ";"));
                } catch (Throwable t) {
                    w.println(decl + ";");
                }
            } else {
                w.println(decl + ";");
            }
            n++;
        }
        w.close();
        println("wrote " + out + " symbols=" + n);
    }
}
