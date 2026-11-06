// Disassemble a range from a seed and print bytes + text. Args: address length outfile
//@category DeSt
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class RawDisasm extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address start = currentProgram.getAddressFactory().getAddress(a[0]);
        int len = Integer.decode(a[1]);
        AddressSet seeds = new AddressSet(start, start);
        DisassembleCommand cmd = new DisassembleCommand(seeds, null, true);
        cmd.applyTo(currentProgram, monitor);
        PrintWriter w = new PrintWriter(new FileWriter(a[2]));
        Listing lst = currentProgram.getListing();
        Address cur = start;
        Address end = start.add(len - 1);
        while (cur != null && cur.compareTo(end) <= 0) {
            Instruction ins = lst.getInstructionAt(cur);
            if (ins == null) break;
            StringBuilder b = new StringBuilder();
            b.append(ins.getAddress()).append("  ");
            for (byte x : ins.getBytes()) b.append(String.format("%02X ", x & 0xff));
            b.append(" ").append(ins.toString());
            w.println(b.toString());
            println(b.toString());
            cur = ins.getMaxAddress().add(1);
        }
        w.close();
    }
}
