// Print full prototypes (with parameter sizes and stack offsets) for many addresses.
// Args: address ...
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Variable;
import ghidra.program.model.data.DataType;

public class ShowProtos extends GhidraScript {
    @Override
    public void run() throws Exception {
        for (String a : getScriptArgs()) {
            Address ad = currentProgram.getAddressFactory().getAddress(a);
            Function f = currentProgram.getFunctionManager().getFunctionAt(ad);
            if (f == null) { println("NOFUNC " + a); continue; }
            println("== " + a + " " + f.getName() + "  ret=" + f.getReturnType().getName()
                    + " cc=" + f.getCallingConventionName());
            int i = 0;
            for (Variable v : f.getParameters()) {
                DataType t = v.getDataType();
                println("   #" + i + " " + v.getName() + " : " + t.getName() + " len=" + t.getLength()
                        + " storage=" + v.getVariableStorage());
                i++;
            }
        }
    }
}
