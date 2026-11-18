// Remove a label that is not a variable (an offset artifact), so references
// resolve to the containing symbol instead.
// Args: address<TAB>expectedName
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.symbol.*;

public class RemoveSym extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address ad = currentProgram.getAddressFactory().getAddress(a[0]);
        Symbol s = currentProgram.getSymbolTable().getPrimarySymbol(ad);
        if (s == null) { println("no symbol at " + a[0]); return; }
        if (a.length > 1 && !s.getName().equals(a[1])) {
            println("name mismatch: " + s.getName());
            return;
        }
        String name = s.getName();
        int tx = currentProgram.startTransaction("remove symbol");
        try {
            currentProgram.getSymbolTable().removeSymbolSpecial(s);
            println("removed " + name + " at " + a[0]);
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
