// Create a function at an address. Args: address
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;

public class CreateFunctionAt extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address at = currentProgram.getAddressFactory().getAddress(a[0]);
        if (currentProgram.getListing().getInstructionAt(at) == null) {
            disassemble(at);
        }
        Function f = currentProgram.getFunctionManager().getFunctionAt(at);
        if (f == null) {
            f = createFunction(at, null);
        }
        if (f == null) println("failed to create function at " + at);
        else println("function " + f.getName() + " at " + f.getEntryPoint()
                + " body=" + f.getBody().getNumAddresses());
    }
}
