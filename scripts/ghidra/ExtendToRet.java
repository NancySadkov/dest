// For each function, walk instructions forward and report the real end:
//  - the last RET/RETF/IRET reachable before a genuine function boundary,
//  - the function entries encountered on the way (interior false entries),
//  - the first genuine boundary (entry that cannot be reached by fall-through).
// Args: tsv with address<TAB>name
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class ExtendToRet extends GhidraScript {
    private static boolean fallsThrough(Instruction i) {
        if (i == null) return false;
        String m = i.getMnemonicString().toUpperCase();
        if (m.startsWith("RET") || m.equals("IRET") || m.startsWith("JMP")
                || m.equals("HLT"))
            return false;
        return true;
    }

    private static boolean isRet(Instruction i) {
        if (i == null) return false;
        String m = i.getMnemonicString().toUpperCase();
        return m.startsWith("RET") || m.equals("IRET");
    }

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        FunctionManager fm = currentProgram.getFunctionManager();
        Listing lst = currentProgram.getListing();
        for (String line : lines) {
            line = line.trim();
            if (line.isEmpty() || line.startsWith("#")) continue;
            String[] f = line.split("\t");
            Address start = currentProgram.getAddressFactory().getAddress(f[0]);
            Function fn = fm.getFunctionAt(start);
            if (fn == null) { println("NOFUNC " + f[0]); continue; }
            Address cur = start;
            Address lastRet = null;
            Instruction prev = null;
            List<String> interior = new ArrayList<>();
            Address boundary = null;
            int n = 0;
            while (n++ < 4000) {
                Instruction ins = lst.getInstructionAt(cur);
                if (ins == null) { println("  noinsn @" + cur); break; }
                Function other = fm.getFunctionAt(cur);
                if (other != null && !cur.equals(start)) {
                    if (prev != null && fallsThrough(prev)) {
                        interior.add(cur + ":" + other.getName());
                    } else {
                        boundary = cur;
                        break;
                    }
                }
                if (isRet(ins)) lastRet = ins.getAddress();
                prev = ins;
                Address next = ins.getMaxAddress().next();
                cur = next;
            }
            println(f[0] + "\t" + fn.getName()
                    + "\tcurEnd=" + fn.getBody().getMaxAddress()
                    + "\tlastRet=" + lastRet
                    + "\tboundary=" + boundary
                    + "\tinterior=" + interior);
        }
    }
}
