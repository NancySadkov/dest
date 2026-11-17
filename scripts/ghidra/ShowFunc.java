// Print the function containing/at an address. Args: addr
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;

public class ShowFunc extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address ad = currentProgram.getAddressFactory().getAddress(a[0]);
        Function f = currentProgram.getFunctionManager().getFunctionAt(ad);
        if (f == null) {
            f = currentProgram.getFunctionManager().getFunctionContaining(ad);
        }
        if (f == null) {
            println("no function at " + a[0]);
            return;
        }
        println("FUNC " + f.getEntryPoint() + " " + f.getName() + " :: " + f.getPrototypeString(false, false));
        println("RET " + f.getReturnType().getName());
        println("THUNK " + f.isThunk() + " -> "
                + (f.getThunkedFunction(true) == null ? "none"
                   : f.getThunkedFunction(true).getName()));
        for (Variable v : f.getParameters()) {
            println("PARAM " + v.getName() + " " + v.getDataType().getName());
        }
    }
}
