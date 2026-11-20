// Whole-program scan: report every instruction that uses a given scalar displacement as an operand.
// Args: TSV with one hex displacement per line (e.g. "94").
// Unlike a text match this also catches 'ADD BX,0x94', 'SUB SI,0x94', 'CMP AX,0x94' and any other
// form where the field offset is folded into a register before the memory access.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class ScanDisp extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        Listing lst = currentProgram.getListing();
        FunctionManager fm = currentProgram.getFunctionManager();
        for (String line : lines) {
            line = line.trim();
            if (line.isEmpty() || line.startsWith("#")) continue;
            long want = Long.parseLong(line.replace("0x", ""), 16);
            int hits = 0;
            InstructionIterator it = lst.getInstructions(true);
            while (it.hasNext()) {
                Instruction ins = it.next();
                boolean hasScalar = false, hasReg = false;
                for (int i = 0; i < ins.getNumOperands(); i++) {
                    for (Object o : ins.getOpObjects(i)) {
                        if (o instanceof Scalar && ((Scalar) o).getUnsignedValue() == want) hasScalar = true;
                        if (o instanceof Register) hasReg = true;
                    }
                }
                if (!hasScalar || !hasReg) continue;
                Address from = ins.getAddress();
                Function fn = fm.getFunctionContaining(from);
                println(String.format("%s\tdisp=0x%02x\t%s\t%s\t%s", line, want,
                        from, fn == null ? "-" : fn.getName(), ins));
                hits++;
            }
            println("HITS " + line + " = " + hits);
        }
    }
}
