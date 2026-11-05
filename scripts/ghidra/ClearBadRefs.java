// Remove references to non-existent addresses from a function body, which
// sometimes makes the decompiler fail with "Cannot marshal address space".
// Args: function address
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class ClearBadRefs extends GhidraScript {
    @Override
    public void run() throws Exception {
        Address addr = currentProgram.getAddressFactory().getAddress(getScriptArgs()[0]);
        Function f = currentProgram.getFunctionManager().getFunctionAt(addr);
        if (f == null) { println("no function"); return; }
        ReferenceManager rm = currentProgram.getReferenceManager();
        AddressSetView body = f.getBody();
        int removed = 0, seen = 0;
        int tx = currentProgram.startTransaction("clear bad refs");
        try {
            AddressIterator it = body.getAddresses(true);
            while (it.hasNext()) {
                Address a = it.next();
                Reference[] refs = rm.getReferencesFrom(a);
                for (Reference r : refs) {
                    seen++;
                    Address to = r.getToAddress();
                    boolean bad = false;
                    if (to == null) bad = true;
                    else if (to.equals(Address.NO_ADDRESS)) bad = true;
                    else if (!to.isMemoryAddress() && !to.isStackAddress() && !to.isRegisterAddress()
                             && !to.isExternalAddress() && !to.isConstantAddress())
                        bad = true;
                    if (bad) {
                        println("removing bad ref at " + a + " -> " + r);
                        rm.delete(r);
                        removed++;
                    }
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("refs seen=" + seen + " removed=" + removed);
    }
}
