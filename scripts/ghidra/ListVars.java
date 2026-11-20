// List a function's parameters and locals with storage, type and size.
// Args: address
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;

public class ListVars extends GhidraScript {
    @Override
    public void run() throws Exception {
        Address at = currentProgram.getAddressFactory().getAddress(getScriptArgs()[0]);
        Function fn = currentProgram.getFunctionManager().getFunctionAt(at);
        if (fn == null) { println("NOFUNC"); return; }
        println("FUNC " + fn.getName() + " : " + fn.getPrototypeString(false, false));
        int i = 0;
        for (Variable v : fn.getParameters())
            println("param" + (i++) + "\t" + v.getName() + "\t" + v.getDataType().getName()
                    + "\t" + v.getLength() + "\t" + v.getVariableStorage());
        for (Variable v : fn.getLocalVariables())
            println("local\t" + v.getName() + "\t" + v.getDataType().getName()
                    + "\t" + v.getLength() + "\t" + v.getVariableStorage());
    }
}
