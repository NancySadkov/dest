// Dump every non-function label with its data type and length.
// Args: outfile
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;

public class SymTypes extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        PrintWriter w = new PrintWriter(new FileWriter(new File(a[0])));
        w.println("address\tname\ttype\tlength");
        Listing lst = currentProgram.getListing();
        int n = 0;
        for (Symbol s : currentProgram.getSymbolTable().getAllSymbols(true)) {
            if (s.getSymbolType() != SymbolType.LABEL) continue;
            if (s.isExternal()) continue;
            Address ad = s.getAddress();
            Data d = lst.getDataAt(ad);
            String tn = d == null ? "" : d.getDataType().getName();
            int len = d == null ? 0 : d.getLength();
            w.println(ad + "\t" + s.getName() + "\t" + tn + "\t" + len);
            n++;
        }
        w.close();
        println("wrote " + a[0] + " syms=" + n);
    }
}
