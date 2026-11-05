// Sanitize and improve symbol names so decompiled C is readable and valid C.
// - Invalid characters in global symbols are replaced.
// - thunk_FUN_xxx -> ovr_<target name>
// - FUN_seg_off in a named source segment -> <module>_seg_off
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class SanitizeSymbols extends GhidraScript {
    private Set<String> used = new HashSet<String>();
    private static final String IDCHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_";

    private String modulePrefix(MemoryBlock b) {
        if (b == null) return "seg";
        String n = b.getName();
        if (n.startsWith("OVC")) {
            int us = n.indexOf('_');
            String rest = us >= 0 ? n.substring(us + 1) : n;
            int dot = rest.indexOf('.');
            if (dot >= 0) rest = rest.substring(0, dot);
            rest = sanitizeIdent(rest);
            return rest.length() > 0 ? rest : "ovc";
        }
        if (n.contains("_TEXT_")) return sanitizeIdent(n.substring(n.indexOf("_TEXT_") + 6));
        if (n.contains("_OVRTEXT_")) return "ovl";
        if (n.startsWith("OVR")) return "ovr";
        if (n.contains("_TEXT")) return "crt";
        return sanitizeIdent(n.toLowerCase(Locale.ROOT));
    }

    private String sanitizeIdent(String s) {
        StringBuilder b = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (IDCHARS.indexOf(c) >= 0) b.append(c);
            else if (c == '@') b.append("_at_");
            else if (c == '$') b.append("_dlr_");
            else b.append('_');
        }
        String r = b.toString();
        if (r.isEmpty()) r = "x";
        if (Character.isDigit(r.charAt(0))) r = "_" + r;
        return r;
    }

    private String unique(String base, String addr) {
        String n = base;
        int k = 2;
        while (used.contains(n)) {
            n = base + "_" + k++;
            if (k > 50) { n = base + "_" + addr.replace(':', '_'); break; }
        }
        used.add(n);
        return n;
    }

    private String segOff(Address a) {
        String s = a.toString();
        int c = s.indexOf(':');
        if (c >= 0) return s.substring(0, c) + "_" + s.substring(c + 1);
        return String.format("%08x", a.getOffset());
    }

    private String targetName(Function t) {
        if (t == null) return null;
        String n = t.getName();
        if (!n.startsWith("FUN_")) return sanitizeIdent(n);
        MemoryBlock b = currentProgram.getMemory().getBlock(t.getEntryPoint());
        return modulePrefix(b) + "_" + segOff(t.getEntryPoint());
    }

    @Override
    public void run() throws Exception {
        int tx = currentProgram.startTransaction("sanitize symbols");
        int nren = 0, nfun = 0, nthunk = 0;
        try {
            // First pass: reserve existing valid global symbol names.
            SymbolTable st = currentProgram.getSymbolTable();
            for (Symbol s : st.getAllSymbols(true)) {
                if (s.getParentNamespace().getID() == currentProgram.getGlobalNamespace().getID()) {
                    used.add(s.getName());
                }
            }

            // Rename functions with characters that are invalid in C identifiers
            // (Borland runtime helpers such as LXLSH@, N_LDIV@, ...).
            FunctionManager fm = currentProgram.getFunctionManager();
            Set<String> funcNames = new HashSet<String>();
            for (Function f : fm.getFunctions(true)) {
                String n = f.getName();
                String nn = sanitizeIdent(n);
                if (!nn.equals(n)) {
                    String base = nn;
                    int k = 2;
                    while (funcNames.contains(nn)) nn = base + "_" + k++;
                    try {
                        f.setName(nn, SourceType.USER_DEFINED);
                        funcNames.add(nn);
                        nfun++;
                    } catch (Exception e) {
                        println("cannot rename function " + n + ": " + e);
                        funcNames.add(n);
                    }
                } else {
                    funcNames.add(n);
                }
            }

            // Rename unnamed functions with a module-qualified stable name.
            for (Function f : fm.getFunctions(true)) {
                String n = f.getName();
                if (f.isThunk()) continue;
                if (!n.startsWith("FUN_")) continue;
                Address a = f.getEntryPoint();
                String base = modulePrefix(currentProgram.getMemory().getBlock(a)) + "_" + segOff(a);
                String nn = unique(base, a.toString());
                try {
                    f.setName(nn, SourceType.USER_DEFINED);
                    funcNames.add(nn);
                    nfun++;
                } catch (Exception e) {
                    println("cannot rename " + n + ": " + e);
                }
            }

            // Rename thunks to ovr_<target>. Re-running this script must be
            // idempotent, so names already of the form ovr_<target>[_N] are
            // canonicalised instead of gaining another suffix.
            Map<String, Address> nameAddr = new HashMap<String, Address>();
            for (Symbol s : st.getAllSymbols(true)) {
                if (s.getParentNamespace().getID() != currentProgram.getGlobalNamespace().getID()) continue;
                if (!nameAddr.containsKey(s.getName())) nameAddr.put(s.getName(), s.getAddress());
            }
            for (Function f : fm.getFunctions(true)) {
                if (!f.isThunk()) continue;
                Function t = f.getThunkedFunction(true);
                String tn = targetName(t);
                if (tn == null) continue;
                String desired = "ovr_" + tn;
                String nn = desired;
                int k = 2;
                while (true) {
                    Address other = nameAddr.get(nn);
                    if (other == null || other.equals(f.getEntryPoint())) break;
                    nn = desired + "_" + k++;
                }
                if (nn.equals(f.getName())) continue;
                try {
                    f.setName(nn, SourceType.USER_DEFINED);
                    nameAddr.put(nn, f.getEntryPoint());
                    funcNames.add(nn);
                    nthunk++;
                } catch (Exception e) {
                    println("cannot rename thunk " + f.getName() + ": " + e);
                }
            }

            // Sanitize non-function global symbols. A global whose name equals a
            // function name gets a _data suffix so the recovered C is valid.
            for (Symbol s : st.getAllSymbols(true)) {
                if (s.getSymbolType() == SymbolType.FUNCTION) continue;
                if (s.getParentNamespace().getID() != currentProgram.getGlobalNamespace().getID()) continue;
                String n = s.getName();
                if (n.contains(".") || n.contains("[") || n.contains("+") || n.contains("::")) continue;
                String nn = sanitizeIdent(n);
                if (funcNames.contains(nn)) nn = nn + "_data";
                if (nn.equals(n)) continue;
                nn = unique(nn, s.getAddress().toString());
                try {
                    s.setName(nn, SourceType.USER_DEFINED);
                    nren++;
                } catch (Exception e) {
                    println("cannot rename symbol " + n + ": " + e);
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("renamed funcs=" + nfun + " thunks=" + nthunk + " symbols=" + nren);
    }
}
