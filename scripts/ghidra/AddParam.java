// Add one parameter to a function without touching its return type (far-pointer returns on
// __cdecl16far go through hidden return storage, so a full prototype rewrite is risky).
// Args: address name typePath
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class AddParam extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address at = currentProgram.getAddressFactory().getAddress(a[0]);
        Function f = currentProgram.getFunctionManager().getFunctionAt(at);
        if (f == null) { println("no function"); return; }
        DataType dt = currentProgram.getDataTypeManager().getDataType(a[2]);
        if (dt == null) { println("NOTYPE " + a[2]); return; }
        int tx = currentProgram.startTransaction("add parameter");
        try {
            f.addParameter(new ParameterImpl(a[1], dt, currentProgram), SourceType.USER_DEFINED);
            println("ok " + f.getPrototypeString(false, false));
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
