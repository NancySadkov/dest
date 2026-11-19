// Print the distinct address-space/segment prefixes of a function body, with byte counts.
// Args: address
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.util.*;

public class BodySegs extends GhidraScript {
    @Override
    public void run() throws Exception {
        Address entry = currentProgram.getAddressFactory().getAddress(getScriptArgs()[0]);
        Function f = currentProgram.getFunctionManager().getFunctionAt(entry);
        if (f == null) { println("no function"); return; }
        println("entry=" + entry + " flat=" + String.format("%X", entry.getOffset()));
        Map<String, long[]> m = new TreeMap<>();
        Map<String, long[]> lo = new TreeMap<>();
        for (Address a : f.getBody().getAddresses(true)) {
            String s = a.toString();
            int c = s.indexOf(':');
            String k = c < 0 ? s : s.substring(0, c);
            long[] v = m.get(k);
            if (v == null) { v = new long[1]; m.put(k, v); }
            v[0]++;
        }
        for (Map.Entry<String, long[]> e : m.entrySet())
            println("  " + e.getKey() + " bytes=" + e.getValue()[0]);
        println("total=" + f.getBody().getNumAddresses() + " ranges=" + f.getBody().getNumAddressRanges());
        for (AddressRange r : f.getBody())
            println("  range " + r.getMinAddress() + " - " + r.getMaxAddress() + " len=" + r.getLength());
    }
}
