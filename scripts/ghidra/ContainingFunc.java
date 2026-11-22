// For each address, print the function that contains it.
// Args: tsv with  seg:ofs <TAB> label
//
// Used to decide how to bind a call whose target Ghidra renders as func_0x<linear>:
// when the address is not a function entry (the bytes show data or a function
// epilogue), the call cannot be split out - but the containing function is known
// and is the closest honest target.
//
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.io.*;
import java.nio.file.*;
import java.util.*;

public class ContainingFunc extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        if (a.length < 1) { println("usage: ContainingFunc <tsv>"); return; }
        FunctionManager fm = currentProgram.getFunctionManager();
        for (String line : Files.readAllLines(Paths.get(a[0]))) {
            line = line.trim();
            if (line.isEmpty() || line.startsWith("#")) continue;
            String[] p = line.split("\t");
            Address at = currentProgram.getAddressFactory().getAddress(p[0]);
            if (at == null) { println(p[0] + " BADADDR"); continue; }
            Function f = fm.getFunctionContaining(at);
            if (f == null) {
                println(p[0] + "\t" + (p.length > 1 ? p[1] : "") + "\tNOFUNC");
            } else {
                boolean entry = f.getEntryPoint().equals(at);
                println(p[0] + "\t" + (p.length > 1 ? p[1] : "") + "\t" + f.getName()
                        + "\tentry=" + f.getEntryPoint() + "\tinside=" + !entry);
            }
        }
    }
}
