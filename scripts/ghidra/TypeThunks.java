// Verify overlay stub signatures.
//
// An `ovr_<name>` stub SHARES the parameter list of its target `<name>`: Ghidra
// reports the target's parameters through the stub, and removeParameter() on the
// stub deletes them from the target.  So there is nothing to copy -- the stub is
// already typed -- and the previous implementation, which removed every stub
// parameter and re-added the target's, silently emptied 308 real functions.
//
// This script therefore only reports.  See doc/functions_naming.md.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class TypeThunks extends GhidraScript {
    @Override
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        SymbolTable st = currentProgram.getSymbolTable();
        int match = 0, differ = 0, missing = 0;
        for (Function f : fm.getFunctions(true)) {
            String n = f.getName();
            if (!n.startsWith("ovr_")) continue;
            String want = n.substring(4);
            Function t = null;
            SymbolIterator it = st.getSymbols(want);
            while (it.hasNext()) {
                Symbol s = it.next();
                if (s.isExternal()) continue;
                Function g = fm.getFunctionAt(s.getAddress());
                if (g != null && g != f) { t = g; break; }
            }
            if (t == null) { missing++; continue; }
            int a = f.getParameters().length, b = t.getParameters().length;
            if (a == b) match++;
            else { differ++; println("DIFFER " + n + " stub=" + a + " target=" + b); }
        }
        println("stubs_matching_target=" + match + " differing=" + differ + " no-target=" + missing);
        println("stubs share their target's parameters; no copying is performed");
    }
}
