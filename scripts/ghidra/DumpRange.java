// Dump disassembly of an address range. Args: start end outfile
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class DumpRange extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address start = currentProgram.getAddressFactory().getAddress(a[0]);
        Address end = currentProgram.getAddressFactory().getAddress(a[1]);
        PrintWriter w = new PrintWriter(new FileWriter(a[2]));
        Listing lst = currentProgram.getListing();
        Address cur = start;
        while (cur.compareTo(end) < 0) {
            Instruction ins = lst.getInstructionAt(cur);
            if (ins == null) {
                try { disassemble(cur); } catch (Exception e) {}
                ins = lst.getInstructionAt(cur);
            }
            if (ins == null) {
                w.println(cur + "  (no instruction)");
                cur = cur.add(1);
                continue;
            }
            StringBuilder b = new StringBuilder();
            b.append(ins.getAddress()).append("  ");
            byte[] ib = ins.getBytes();
            for (byte x : ib) b.append(String.format("%02X ", x & 0xff));
            b.append(" ").append(ins.toString());
            w.println(b.toString());
            cur = ins.getMaxAddress().add(1);
        }
        w.close();
        println("wrote " + a[2]);
    }
}
