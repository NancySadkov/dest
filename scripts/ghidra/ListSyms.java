// List symbols whose name starts with a prefix. Args: prefix
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.symbol.*;

public class ListSyms extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        SymbolTable st = currentProgram.getSymbolTable();
        int n = 0;
        for (Symbol s : st.getAllSymbols(true)) {
            if (!s.getName().startsWith(a[0])) continue;
            println(s.getAddress() + " " + s.getName() + " " + s.getSymbolType());
            if (++n > 400) break;
        }
        println("total " + n);
    }
}
