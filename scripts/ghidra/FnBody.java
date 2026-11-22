// Print a function's body ranges and instruction count. Args: address
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;

public class FnBody extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address at = currentProgram.getAddressFactory().getAddress(a[0]);
        Function f = currentProgram.getFunctionManager().getFunctionAt(at);
        if (f == null) f = currentProgram.getFunctionManager().getFunctionContaining(at);
        if (f == null) { println("no function at " + a[0]); return; }
        println("name=" + f.getName() + " entry=" + f.getEntryPoint());
        int n = 0;
        for (AddressRange r : f.getBody())
            println("  range " + r.getMinAddress() + " .. " + r.getMaxAddress());
        InstructionIterator it = currentProgram.getListing().getInstructions(f.getBody(), true);
        while (it.hasNext()) { it.next(); n++; }
        println("  instructions=" + n);
    }
}
