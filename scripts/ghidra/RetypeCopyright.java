// Retype the DGROUP copyright string as a byte array so small integer
// constants are not symbolized as pointers into it.
// Args: address length
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;

public class RetypeCopyright extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address at = currentProgram.getAddressFactory().getAddress(a[0]);
        int len = Integer.parseInt(a[1]);
        int tx = currentProgram.startTransaction("retype data");
        try {
            clearListing(at, at.add(len - 1));
            createData(at, new ArrayDataType(ByteDataType.dataType, len, 1));
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("retyped " + at + " len " + len);
    }
}
