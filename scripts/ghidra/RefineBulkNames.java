// Refine the bulk-generated type prefixes to readable C-like ones.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;

public class RefineBulkNames extends GhidraScript {
    private String refine(String n) {
        if (n.startsWith("undefined1_")) return "byte_" + n.substring(11);
        if (n.startsWith("undefined2_")) return "word_" + n.substring(11);
        if (n.startsWith("undefined4_")) return "dword_" + n.substring(11);
        if (n.startsWith("undefined_")) return "data_" + n.substring(10);
        return n;
    }

    @Override
    public void run() throws Exception {
        int tx = currentProgram.startTransaction("refine names");
        int n = 0;
        try {
            SymbolTable st = currentProgram.getSymbolTable();
            for (Symbol s : st.getAllSymbols(true)) {
                String old = s.getName();
                String nn = refine(old);
                if (nn.equals(old)) continue;
                try {
                    s.setName(nn, SourceType.USER_DEFINED);
                    n++;
                } catch (Throwable t) {
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("refined " + n);
    }
}
