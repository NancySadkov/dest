// Inventory of data types and global symbols.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;

public class Inventory extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String out = args.length > 0 ? args[0] : "inventory.txt";
        PrintWriter w = new PrintWriter(new FileWriter(out));
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        w.println("== DATA TYPES ==");
        java.util.Iterator<DataType> it = dtm.getAllDataTypes();
        while (it.hasNext()) {
            DataType dt = it.next();
            w.println(dt.getPathName() + "\t" + dt.getDisplayName() + "\t" + dt.getLength());
        }
        w.println("\n== GLOBAL SYMBOLS (non-function) ==");
        SymbolTable st = currentProgram.getSymbolTable();
        Listing lst = currentProgram.getListing();
        for (Symbol s : st.getAllSymbols(true)) {
            if (s.getSymbolType() == SymbolType.FUNCTION) continue;
            if (s.getParentNamespace().getID() != currentProgram.getGlobalNamespace().getID()) continue;
            Data d = lst.getDataAt(s.getAddress());
            String tn = "";
            String len = "";
            if (d != null) { tn = d.getDataType().getName(); len = String.valueOf(d.getLength()); }
            w.println(s.getAddress() + "\t" + s.getName() + "\t" + s.getSymbolType()
                      + "\t" + tn + "\t" + len);
        }
        w.println("\n== FUNCTIONS WITH TYPES ==");
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            w.println(f.getEntryPoint() + "\t" + f.getName() + "\t"
                + f.getReturnType().getName() + "\t" + f.getCallingConventionName()
                + "\t" + f.getParameterCount() + "\t" + f.getPrototypeString(false, false));
        }
        w.close();
        println("wrote " + out);
    }
}
