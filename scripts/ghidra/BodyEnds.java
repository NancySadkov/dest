// Report functions whose body does not end in a return/jump (a sign of a truncated body).
// Args: [out.tsv]
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class BodyEnds extends GhidraScript {
    private static boolean terminator(String m) {
        String s = m.toUpperCase();
        return s.equals("RET") || s.equals("RETF") || s.equals("IRET") || s.equals("JMP")
                || s.equals("JMPF") || s.equals("HLT");
    }

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        PrintWriter w = a.length > 0 ? new PrintWriter(new FileWriter(a[0]))
                                    : new PrintWriter(System.out);
        int bad = 0, total = 0;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            total++;
            AddressSetView body = f.getBody();
            if (body.getNumAddresses() == 0) continue;
            Address last = body.getMaxAddress();
            Instruction ins = currentProgram.getListing().getInstructionAt(last);
            if (ins == null) ins = currentProgram.getListing().getInstructionContaining(last);
            if (ins == null) {
                w.println(f.getEntryPoint() + "\t" + f.getName() + "\tNOINSN\t" + last);
                bad++;
                continue;
            }
            if (!terminator(ins.getMnemonicString())) {
                w.println(f.getEntryPoint() + "\t" + f.getName() + "\t" + ins.getMnemonicString()
                        + "\t" + last);
                bad++;
            }
        }
        w.println("TOTAL " + bad + " / " + total);
        if (a.length > 0) w.close();
        println("bodies not ending in return/jump: " + bad + " / " + total);
    }
}
