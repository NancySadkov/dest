// For every function whose body spans more than one segment, print each range, the last
// instruction of each range, and whether the home-segment ranges contain a RET/RETF.
// Args: [out.tsv]
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class BodyCheck extends GhidraScript {
    private String segOf(Address a) {
        if (a instanceof SegmentedAddress) return Integer.toHexString(((SegmentedAddress) a).getSegment());
        MemoryBlock b = currentProgram.getMemory().getBlock(a);
        return b == null ? a.getAddressSpace().getName() : b.getName();
    }

    private static boolean isRet(Instruction i) {
        if (i == null) return false;
        String m = i.getMnemonicString().toUpperCase();
        return m.equals("RET") || m.equals("RETF") || m.equals("IRET");
    }

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        PrintWriter w = a.length > 0 ? new PrintWriter(new FileWriter(a[0]))
                                    : new PrintWriter(System.out);
        int n = 0;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            AddressSetView body = f.getBody();
            java.util.Set<String> segs = new java.util.HashSet<>();
            for (AddressRange r : body)
                segs.add(segOf(r.getMinAddress()));
            if (segs.size() < 2) continue;
            n++;
            String home = segOf(f.getEntryPoint());
            boolean homeRet = false;
            w.println("FUNC\t" + f.getEntryPoint() + "\t" + f.getName() + "\thome=" + home);
            for (AddressRange r : body) {
                String seg = segOf(r.getMinAddress());
                Instruction last = currentProgram.getListing()
                        .getInstructionContaining(r.getMaxAddress());
                if (last == null) last = currentProgram.getListing()
                        .getInstructionAt(r.getMaxAddress());
                boolean ret = isRet(last);
                if (seg.equals(home) && ret) homeRet = true;
                w.println("\t" + (seg.equals(home) ? "home " : "FOREIGN ")
                        + r.getMinAddress() + "-" + r.getMaxAddress()
                        + "\tlast=" + (last == null ? "?" : last.getMnemonicString() + "@" + last.getAddress())
                        + (ret ? "\tRET" : ""));
            }
            w.println("\thomeHasRet=" + homeRet);
        }
        w.println("TOTAL " + n);
        if (a.length > 0) w.close();
        println("multi-segment functions: " + n);
    }
}
