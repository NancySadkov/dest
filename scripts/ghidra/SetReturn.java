// Set only a function's return type (leaves parameters alone).
// Args: address typePath [callingConvention]
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class SetReturn extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address at = currentProgram.getAddressFactory().getAddress(a[0]);
        Function f = currentProgram.getFunctionManager().getFunctionAt(at);
        if (f == null) { println("no function"); return; }
        DataType dt = currentProgram.getDataTypeManager().getDataType(a[1]);
        if (dt == null) { println("NOTYPE " + a[1]); return; }
        int tx = currentProgram.startTransaction("set return");
        try {
            if (a.length > 2 && !a[2].isEmpty()) f.setCallingConvention(a[2]);
            f.setReturn(dt, (VariableStorage) null, SourceType.USER_DEFINED);
            println("ok " + f.getPrototypeString(false, false));
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
