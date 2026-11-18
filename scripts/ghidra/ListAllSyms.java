// Dump every global/label symbol: address<TAB>name<TAB>type.
// Args: outfile
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.symbol.*;
import java.io.*;

public class ListAllSyms extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        PrintWriter w = new PrintWriter(new FileWriter(new File(a[0])));
        w.println("address\tname\ttype");
        SymbolTable st = currentProgram.getSymbolTable();
        int n = 0;
        for (Symbol s : st.getAllSymbols(true)) {
            SymbolType t = s.getSymbolType();
            if (t != SymbolType.LABEL && t != SymbolType.FUNCTION) continue;
            if (s.isExternal()) continue;
            w.println(s.getAddress() + "\t" + s.getName() + "\t" + t);
            n++;
        }
        w.close();
        println("wrote " + a[0] + " syms=" + n);
    }
}
