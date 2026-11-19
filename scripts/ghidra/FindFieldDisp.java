// Find instructions that mention a given struct field offset inside functions taking that struct.
// Args: TSV with structName<TAB>displacementHex (e.g. agnt_t<TAB>2a)
// Prints: struct  disp  function  instructionAddress  instructionText
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.Reference;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class FindFieldDisp extends GhidraScript {
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
            String structName = f[0];
            String disp = "0x" + f[1].replace("0x", "");
            int hits = 0;
            for (Function fn : fm.getFunctions(true)) {
                boolean takes = structName.equals("*");
                for (Variable v : fn.getParameters()) {
                    if (takes) break;
                    DataType t = v.getDataType();
                    String tn = t.getName();
                    if (tn.contains(structName)) { takes = true; break; }
                    if (t instanceof Pointer) {
                        DataType base = ((Pointer) t).getDataType();
                        if (base != null && base.getName().contains(structName)) { takes = true; break; }
                    }
                }
                if (!takes) continue;
                for (Instruction ins : lst.getInstructions(fn.getBody(), true)) {
                    if (ins.toString().contains("[" + disp) || ins.toString().contains("+ " + disp + "]")
                        || ins.toString().contains(disp + "]")) {
                        println(structName + "\t" + f[1] + "\t" + fn.getName() + "\t" + ins.getAddress()
                                + "\t" + ins);
                        hits++;
                    }
                }
            }
            println("HITS " + structName + " " + f[1] + " = " + hits);
        }
    }
}
