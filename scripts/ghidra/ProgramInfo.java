// Report program language, image base, memory blocks, and a few instructions.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.lang.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;

public class ProgramInfo extends GhidraScript {
    @Override
    public void run() throws Exception {
        println("LANGUAGE=" + currentProgram.getLanguageID());
        println("COMPILER=" + currentProgram.getCompilerSpec().getCompilerSpecID());
        println("IMAGEBASE=" + currentProgram.getImageBase());
        Memory mem = currentProgram.getMemory();
        for (MemoryBlock b : mem.getBlocks()) {
            println(String.format("BLOCK %-24s %s - %s  size=%d init=%s r=%s w=%s x=%s src=%s",
                    b.getName(), b.getStart(), b.getEnd(), b.getSize(),
                    b.isInitialized(), b.isRead(), b.isWrite(), b.isExecute(),
                    b.getSourceName()));
        }
        Listing lst = currentProgram.getListing();
        String[] addrs = {"55fe:0010", "55fe:0029", "1000:2666", "55fe:0000"};
        for (String a : addrs) {
            Address ad = currentProgram.getAddressFactory().getAddress(a);
            Instruction ins = lst.getInstructionAt(ad);
            if (ins == null) {
                println("INSN " + a + " = none");
                continue;
            }
            byte[] bytes = ins.getBytes();
            StringBuilder sb = new StringBuilder();
            for (byte x : bytes) sb.append(String.format("%02X ", x & 0xff));
            println("INSN " + a + " bytes=" + sb + " mnem=" + ins.getMnemonicString()
                    + " text=" + ins);
        }
    }
}
