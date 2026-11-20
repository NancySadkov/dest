// Report the code gaps (addresses inside a function body with no instruction) for given functions.
// Args: address [address ...]
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;

public class FnGaps extends GhidraScript {
    @Override
    public void run() throws Exception {
        Listing lst = currentProgram.getListing();
        for (String a : getScriptArgs()) {
            Address addr = currentProgram.getAddressFactory().getAddress(a);
            Function fn = addr == null ? null : currentProgram.getFunctionManager().getFunctionAt(addr);
            if (fn == null) { println("NOFUNC " + a); continue; }
            AddressSetView body = fn.getBody();
            int gaps = 0, gapBytes = 0;
            StringBuilder sb = new StringBuilder();
            for (AddressRange r : body.getAddressRanges()) {
                Address cur = r.getMinAddress();
                Address runStart = null;
                while (cur.compareTo(r.getMaxAddress()) <= 0) {
                    Instruction ins = lst.getInstructionAt(cur);
                    boolean covered = ins != null || lst.getDefinedDataAt(cur) != null;
                    if (covered) {
                        if (runStart != null) {
                            gaps++; sb.append(" GAP ").append(runStart).append('-')
                                    .append(cur.subtract(1));
                            runStart = null;
                        }
                        cur = ins != null ? ins.getMaxAddress().add(1) : cur.add(1);
                    } else {
                        if (runStart == null) runStart = cur;
                        gapBytes++;
                        cur = cur.add(1);
                    }
                }
                if (runStart != null) {
                    gaps++;
                    sb.append(" GAP ").append(runStart).append('-').append(r.getMaxAddress());
                }
            }
            println("FUNC " + fn.getName() + " @ " + fn.getEntryPoint()
                    + " bytes=" + body.getNumAddresses() + " gapRanges=" + gaps
                    + " gapBytes=" + gapBytes + sb);
        }
    }
}
