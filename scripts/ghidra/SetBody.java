// Set a function body to an explicit list of ranges.
// Args: address min1 max1 [min2 max2 ...]   (max is inclusive)
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;

public class SetBody extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        if (a.length < 3 || (a.length - 1) % 2 != 0) {
            println("usage: address min1 max1 [min2 max2 ...]");
            return;
        }
        Address at = currentProgram.getAddressFactory().getAddress(a[0]);
        Function f = currentProgram.getFunctionManager().getFunctionAt(at);
        if (f == null) { println("no function"); return; }
        AddressSet set = new AddressSet();
        for (int i = 1; i + 1 < a.length; i += 2) {
            set.add(currentProgram.getAddressFactory().getAddress(a[i]),
                    currentProgram.getAddressFactory().getAddress(a[i + 1]));
        }
        int tx = currentProgram.startTransaction("set body");
        try {
            f.setBody(set);
            println("ok bytes=" + f.getBody().getNumAddresses()
                    + " ranges=" + f.getBody().getNumAddressRanges());
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
