// List a function's parameters and locals: kind<TAB>name<TAB>type<TAB>size.
// Args: address
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;

public class ListVars extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address ad = currentProgram.getAddressFactory().getAddress(a[0]);
        Function fn = getFunctionAt(ad);
        if (fn == null) { println("NOFUNC " + a[0]); return; }
        println("FUNC " + fn.getName());
        for (Variable v : fn.getParameters())
            println("param\t" + v.getName() + "\t" + v.getDataType().getName() + "\t" + v.getLength());
        for (Variable v : fn.getLocalVariables())
            println("local\t" + v.getName() + "\t" + v.getDataType().getName() + "\t" + v.getLength());
    }
}
