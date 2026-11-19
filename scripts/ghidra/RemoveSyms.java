// Delete the primary label at each given address (used for labels now covered by a struct).
// Args: addr1 addr2 ...
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;

public class RemoveSyms extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        int tx = currentProgram.startTransaction("remove syms");
        int ok = 0, missing = 0;
        try {
            for (String s : a) {
                Address ad = currentProgram.getAddressFactory().getAddress(s);
                Symbol sym = currentProgram.getSymbolTable().getPrimarySymbol(ad);
                if (sym == null) { missing++; continue; }
                if (sym.isDeleted()) { missing++; continue; }
                sym.delete();
                ok++;
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("deleted=" + ok + " missing=" + missing);
    }
}
