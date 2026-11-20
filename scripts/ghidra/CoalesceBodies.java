// Coalesce small gaps inside a function body when every gap byte is already part of a decoded
// instruction.  Large gaps and cross-segment ranges are left alone.
// Args: [maxGapHex]
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.util.*;

public class CoalesceBodies extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        long maxGap = a.length > 0 ? Long.parseLong(a[0], 16) : 0x20;
        FunctionManager fm = currentProgram.getFunctionManager();
        Listing lst = currentProgram.getListing();
        int changed = 0, skipped = 0, badbytes = 0;
        int tx = currentProgram.startTransaction("coalesce bodies");
        try {
            List<Function> todo = new ArrayList<>();
            for (Function f : fm.getFunctions(true)) todo.add(f);
            for (Function f : todo) {
                AddressSetView body = f.getBody();
                if (body.getNumAddressRanges() < 2) continue;
                AddressSpace home = f.getEntryPoint().getAddressSpace();
                Address min = body.getMinAddress(), max = body.getMaxAddress();
                boolean ok = true;
                Address prevEnd = null;
                for (AddressRange r : body) {
                    if (!r.getMinAddress().getAddressSpace().equals(home)) { ok = false; break; }
                    if (prevEnd != null) {
                        long gap = r.getMinAddress().subtract(prevEnd) - 1;
                        if (gap > maxGap) { ok = false; break; }
                        for (long i = 1; i <= gap; i++) {
                            Address x = prevEnd.add(i);
                            if (lst.getInstructionContaining(x) == null) {
                                ok = false;
                                badbytes++;
                                break;
                            }
                        }
                        if (!ok) break;
                    }
                    prevEnd = r.getMaxAddress();
                }
                if (!ok) { skipped++; continue; }
                AddressSet ns = new AddressSet(min, max);
                f.setBody(ns);
                changed++;
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("coalesced=" + changed + " skipped=" + skipped + " undecodedGaps=" + badbytes);
    }
}
