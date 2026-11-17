// Give every overlay entry thunk (ovr_<name>) the prototype of its target
// function <name>, so call sites decompile with real argument and return
// types instead of K&R `undefined f()`.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class TypeThunks extends GhidraScript {
    @Override
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        SymbolTable st = currentProgram.getSymbolTable();
        int typed = 0, missing = 0;
        List<Function> targets = new ArrayList<Function>();
        List<Function> thunks = new ArrayList<Function>();
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
            thunks.add(f);
            targets.add(t);
        }
        int tx = currentProgram.startTransaction("type thunks");
        try {
            for (int i = 0; i < thunks.size(); i++) {
                Function f = thunks.get(i);
                Function t = targets.get(i);
                f.setCallingConvention(t.getCallingConventionName());
                f.setReturn(t.getReturnType(), t.getReturn().getVariableStorage(),
                            SourceType.USER_DEFINED);
                Variable[] old = f.getParameters();
                for (int j = old.length - 1; j >= 0; j--) f.removeParameter(j);
                for (Variable v : t.getParameters()) {
                    f.addParameter(new ParameterImpl(v.getName(), v.getDataType(),
                            currentProgram), SourceType.USER_DEFINED);
                }
                typed++;
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("typed=" + typed + " missing=" + missing);
    }
}
