// Dump disassembly of a function. Args: address outfile
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class DumpAsm extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address start = currentProgram.getAddressFactory().getAddress(a[0]);
        Function f = currentProgram.getFunctionManager().getFunctionAt(start);
        if (f == null) { println("no function"); return; }
        PrintWriter w = new PrintWriter(new FileWriter(a[1]));
        Listing lst = currentProgram.getListing();
        InstructionIterator it = lst.getInstructions(f.getBody(), true);
        while (it.hasNext()) {
            Instruction ins = it.next();
            StringBuilder b = new StringBuilder();
            b.append(ins.getAddress()).append("  ").append(ins.toString());
            for (int i = 0; i < ins.getNumOperands(); i++) {
                Object[] objs = ins.getOpObjects(i);
                for (Object o : objs) b.append("  [").append(o.getClass().getSimpleName()).append(":").append(o).append("]");
            }
            w.println(b.toString());
        }
        w.close();
        println("wrote " + a[1]);
    }
}
