// Print the primary symbol (if any) at each address given as an argument.
// Args: address [address ...]
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;

public class SymAt extends GhidraScript {
    @Override
    public void run() throws Exception {
        for (String a : getScriptArgs()) {
            Address addr = currentProgram.getAddressFactory().getAddress(a);
            if (addr == null) { println(a + " BADADDR"); continue; }
            Symbol s = currentProgram.getSymbolTable().getPrimarySymbol(addr);
            if (s == null) {
                SymbolIterator it = currentProgram.getSymbolTable().getSymbolsAsIterator(addr);
                s = it.hasNext() ? it.next() : null;
            }
            if (s == null) println(a + " NOSYM");
            else println(a + " " + s.getName() + " (" + s.getSymbolType() + ")");
        }
    }
}
