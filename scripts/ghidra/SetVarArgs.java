// Turn variadic on or off for a function. Args: address true|false
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class SetVarArgs extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address at = currentProgram.getAddressFactory().getAddress(a[0]);
        Function f = currentProgram.getFunctionManager().getFunctionAt(at);
        if (f == null) { println("no function"); return; }
        boolean v = Boolean.parseBoolean(a.length > 1 ? a[1] : "false");
        int tx = currentProgram.startTransaction("set varargs");
        try {
            f.setVarArgs(v);
            println("varargs=" + f.hasVarArgs() + " " + f.getName() + " :: "
                    + f.getPrototypeString(false, false));
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
