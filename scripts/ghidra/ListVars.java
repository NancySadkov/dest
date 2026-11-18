// List a function's parameters and locals: kind<TAB>name<TAB>type<TAB>size.
// Args: address-or-function-name
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.util.*;

public class ListVars extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        String ref = a[0];
        FunctionManager fm = currentProgram.getFunctionManager();
        Address ad = currentProgram.getAddressFactory().getAddress(ref);
        Function fn = ad == null ? null : fm.getFunctionAt(ad);
        if (fn == null) {
            List<Function> found = new ArrayList<>();
            for (Function cand : fm.getFunctions(true))
                if (cand.getName().equals(ref.trim())) found.add(cand);
            if (found.size() == 1) {
                fn = found.get(0);
                println("BYNAME " + ref + " -> " + fn.getEntryPoint());
            } else {
                println("NOFUNC " + ref + " matches=" + found.size());
                return;
            }
        }
        println("FUNC " + fn.getName() + " @ " + fn.getEntryPoint());
        if (fn.isThunk())
            println("THUNK of " + (fn.getThunkedFunction(true) == null ? "?"
                    : fn.getThunkedFunction(true).getName()));
        for (Variable v : fn.getParameters())
            println("param\t" + v.getName() + "\t" + v.getDataType().getName() + "\t" + v.getLength());
        for (Variable v : fn.getLocalVariables())
            println("local\t" + v.getName() + "\t" + v.getDataType().getName() + "\t" + v.getLength());
    }
}
