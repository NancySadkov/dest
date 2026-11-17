// Link each Borland overlay entry stub (ovr_<name>) to the function it enters,
// so the decompiler propagates the target's prototype to the call sites.
// Args: none
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class LinkThunks extends GhidraScript {
    @Override
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        SymbolTable st = currentProgram.getSymbolTable();
        List<Function> stubs = new ArrayList<Function>();
        for (Function f : fm.getFunctions(true)) {
            if (f.getName().startsWith("ovr_")) stubs.add(f);
        }
        int linked = 0, missing = 0, failed = 0;
        int tx = currentProgram.startTransaction("link thunks");
        try {
            for (Function f : stubs) {
                String want = f.getName().substring(4);
                Function t = null;
                SymbolIterator it = st.getSymbols(want);
                while (it.hasNext()) {
                    Symbol s = it.next();
                    if (s.isExternal()) continue;
                    Function g = fm.getFunctionAt(s.getAddress());
                    if (g != null && g != f) { t = g; break; }
                }
                if (t == null) { missing++; continue; }
                try {
                    f.setThunkedFunction(t);
                    linked++;
                } catch (Throwable e) {
                    failed++;
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("linked=" + linked + " missing=" + missing + " failed=" + failed);
    }
}
