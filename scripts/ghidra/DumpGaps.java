// Emit every intra-function gap (small, same-segment) with its bytes, for boundary validation.
// Args: out.tsv
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;

public class DumpGaps extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        PrintWriter w = new PrintWriter(new FileWriter(a[0]));
        w.println("func\tgapStart\tlen\thex");
        FunctionManager fm = currentProgram.getFunctionManager();
        Memory mem = currentProgram.getMemory();
        int n = 0;
        for (Function f : fm.getFunctions(true)) {
            AddressSetView body = f.getBody();
            if (body.getNumAddressRanges() < 2) continue;
            AddressSpace home = f.getEntryPoint().getAddressSpace();
            Address prevEnd = null;
            boolean cross = false;
            for (AddressRange r : body)
                if (!r.getMinAddress().getAddressSpace().equals(home)) cross = true;
            if (cross) continue;
            for (AddressRange r : body) {
                if (prevEnd != null) {
                    Address gs = prevEnd.add(1);
                    long len = r.getMinAddress().subtract(gs);
                    if (len > 0 && len <= 0x40) {
                        StringBuilder sb = new StringBuilder();
                        for (long i = 0; i < len; i++) {
                            try { sb.append(String.format("%02X", mem.getByte(gs.add(i)) & 0xff)); }
                            catch (Exception e) { sb.append("??"); }
                        }
                        w.println(f.getEntryPoint() + "\t" + gs + "\t" + len + "\t" + sb);
                        n++;
                    }
                }
                prevEnd = r.getMaxAddress();
            }
        }
        w.close();
        println("gaps=" + n);
    }
}
