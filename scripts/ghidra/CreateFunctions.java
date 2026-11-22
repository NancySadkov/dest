// Create functions at a list of addresses.
// Args: tsv with  address <TAB> name
//
// The recovered call sites name their target as func_0x<linear address> when
// Ghidra has a *label* there but no function.  Creating the function makes the
// decompiler render the call by name, so the call site binds to a real symbol.
//
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.file.*;
import java.util.*;

public class CreateFunctions extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        if (a.length < 1) { println("usage: CreateFunctions <tsv>"); return; }
        int made = 0, existed = 0, failed = 0;
        for (String line : Files.readAllLines(Paths.get(a[0]))) {
            line = line.trim();
            if (line.isEmpty() || line.startsWith("#")) continue;
            String[] p = line.split("\t");
            if (p.length < 2 || p[0].startsWith("-")) continue;
            Address at = currentProgram.getAddressFactory().getAddress(p[0]);
            if (at == null) { println("bad address " + p[0]); failed++; continue; }
            if (currentProgram.getListing().getInstructionAt(at) == null) {
                disassemble(at);
            }
            Function f = currentProgram.getFunctionManager().getFunctionAt(at);
            if (f == null) {
                f = createFunction(at, p[1]);
            } else {
                existed++;
            }
            if (f == null) {
                println("failed at " + at);
                failed++;
                continue;
            }
            f.setName(p[1], SourceType.USER_DEFINED);
            made++;
            println("function " + f.getName() + " at " + f.getEntryPoint()
                    + " body=" + f.getBody().getNumAddresses());
        }
        println("created/named=" + made + " existed=" + existed + " failed=" + failed);
    }
}
