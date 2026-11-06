// Disassemble a range and dump pcode. Args: address length
//@category DeSt
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.pcode.*;

public class PcodeDump extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address start = currentProgram.getAddressFactory().getAddress(a[0]);
        int len = Integer.decode(a[1]);
        DisassembleCommand cmd = new DisassembleCommand(new AddressSet(start, start), null, true);
        cmd.applyTo(currentProgram, monitor);
        Listing lst = currentProgram.getListing();
        Address cur = start;
        Address end = start.add(len - 1);
        while (cur != null && cur.compareTo(end) <= 0) {
            Instruction ins = lst.getInstructionAt(cur);
            if (ins == null) break;
            println("INSN " + ins.getAddress() + "  " + ins);
            for (PcodeOp op : ins.getPcode()) {
                println("   PCODE " + op);
            }
            cur = ins.getMaxAddress().add(1);
        }
    }
}
