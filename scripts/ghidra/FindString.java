// Find a byte substring in the program. Args: text
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.mem.*;

public class FindString extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        byte[] needle = a[0].getBytes("ISO-8859-1");
        Memory mem = currentProgram.getMemory();
        for (MemoryBlock b : mem.getBlocks()) {
            if (!b.isInitialized()) continue;
            Address p = b.getStart();
            Address end = b.getEnd();
            try {
                while (p.compareTo(end) <= 0) {
                    Address hit = mem.findBytes(p, end, needle, null, true, monitor);
                    if (hit == null) break;
                    println("HIT " + hit);
                    p = hit.add(1);
                }
            } catch (Throwable t) {
                println("block " + b.getName() + ": " + t);
            }
        }
    }
}
