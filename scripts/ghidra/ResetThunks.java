// Reset overlay thunks to an unknown-parameter prototype so call sites keep
// their pushed arguments, then optionally re-type them from their target.
// Args: mode   (skip = leave untyped, typed = type from target)
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class ResetThunks extends GhidraScript {
    @Override
    public void run() throws Exception {
        String mode = getScriptArgs().length > 0 ? getScriptArgs()[0] : "skip";
        FunctionManager fm = currentProgram.getFunctionManager();
        SymbolTable st = currentProgram.getSymbolTable();
        List<Function> thunks = new ArrayList<Function>();
        for (Function f : fm.getFunctions(true)) {
            if (f.getName().startsWith("ovr_")) thunks.add(f);
        }
        int n = 0, typed = 0;
        // A return storage donor: any function whose return type is the
        // generic `undefined` (one byte, AL).
        DataType undefType = null;
        VariableStorage undefStore = null;
        for (Function g : fm.getFunctions(true)) {
            if (g.getReturnType().getName().equals("undefined")) {
                undefType = g.getReturnType();
                undefStore = g.getReturn().getVariableStorage();
                break;
            }
        }
        if (undefType == null) { println("no undefined-return donor"); return; }
        println("donor " + undefStore);
        int tx = currentProgram.startTransaction("reset thunks");
        try {
            for (Function f : thunks) {
                Variable[] ps = f.getParameters();
                for (int i = ps.length - 1; i >= 0; i--) f.removeParameter(i);
                f.setVarArgs(false);
                f.setReturn(undefType, undefStore, SourceType.DEFAULT);
                n++;
            }
            if (mode.equals("typed")) {
                for (Function f : thunks) {
                    String want = f.getName().substring(4);
                    SymbolIterator it = st.getSymbols(want);
                    Function t = null;
                    while (it.hasNext()) {
                        Symbol s = it.next();
                        if (s.isExternal()) continue;
                        Function g = fm.getFunctionAt(s.getAddress());
                        if (g != null && g != f) { t = g; break; }
                    }
                    if (t == null) continue;
                    if (t.getParameters().length == 0) continue;  // keep args
                    f.setCallingConvention(t.getCallingConventionName());
                    f.setReturn(t.getReturnType(),
                                t.getReturn().getVariableStorage(),
                                SourceType.USER_DEFINED);
                    for (Variable v : t.getParameters()) {
                        f.addParameter(new ParameterImpl(v.getName(),
                                v.getDataType(), currentProgram),
                                SourceType.USER_DEFINED);
                    }
                    typed++;
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("reset=" + n + " retyped=" + typed + " mode=" + mode);
    }
}
