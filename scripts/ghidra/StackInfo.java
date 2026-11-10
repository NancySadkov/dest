// Print address spaces and a donor stack storage.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;

public class StackInfo extends GhidraScript {
    @Override
    public void run() throws Exception {
        for (AddressSpace sp : currentProgram.getAddressFactory().getAddressSpaces()) {
            println("space " + sp.getName() + " stack=" + sp.isStackSpace()
                    + " min=" + sp.getMinAddress() + " max=" + sp.getMaxAddress());
        }
        Function f = getFunctionAt(toAddr(getScriptArgs()[0]));
        Variable v = f.getParameter(Integer.parseInt(getScriptArgs()[1]));
        VariableStorage vs = v.getVariableStorage();
        println("donor " + vs + " min=" + vs.getMinAddress()
                + " space=" + (vs.getMinAddress() == null ? "null"
                               : vs.getMinAddress().getAddressSpace().getName()));
    }
}
