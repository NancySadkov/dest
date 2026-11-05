// Dump project statistics: segments, function counts, names.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import java.io.*;

public class DumpStats extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String out = args.length > 0 ? args[0] : "dumpstats.txt";
        PrintWriter w = new PrintWriter(new FileWriter(out));
        Memory mem = currentProgram.getMemory();
        w.println("PROGRAM " + currentProgram.getName());
        w.println("LANGUAGE " + currentProgram.getLanguageID());
        w.println("IMAGEBASE " + currentProgram.getImageBase());
        w.println("\n== MEMORY BLOCKS ==");
        for (MemoryBlock b : mem.getBlocks()) {
            w.printf("%-24s %s - %s size=%d init=%s vol=%s exec=%s r=%s w=%s class=%s%n",
                b.getName(), b.getStart(), b.getEnd(), b.getSize(),
                b.isInitialized(), b.isVolatile(), b.isExecute(),
                b.isRead(), b.isWrite(), b.getType());
        }
        FunctionManager fm = currentProgram.getFunctionManager();
        int nfunc = 0, nthunk = 0, nnamed = 0, nlib = 0;
        w.println("\n== FUNCTIONS ==");
        for (Function f : fm.getFunctions(true)) {
            nfunc++;
            String src = f.getSymbol() != null ? f.getSymbol().getSource().toString() : "?";
            boolean def = f.getName().startsWith("FUN_");
            if (f.isThunk()) nthunk++;
            if (!def) nnamed++;
            if (f.getParentNamespace().getID() != currentProgram.getGlobalNamespace().getID())
                nlib++;
            w.printf("%s %s %s src=%s thunk=%s noReturn=%s stack=%d params=%d%n",
                f.getEntryPoint(), f.getName(), f.getPrototypeString(false, false),
                src, f.isThunk(), f.hasNoReturn(), f.getStackFrame().getFrameSize(),
                f.getParameterCount());
        }
        w.println("TOTAL_FUNCS " + nfunc);
        w.println("TOTAL_THUNKS " + nthunk);
        w.println("NAMED_FUNCS " + nnamed);
        w.println("NAMESPACE_FUNCS " + nlib);
        w.println("\n== SYMBOL COUNTS ==");
        SymbolTable st = currentProgram.getSymbolTable();
        w.println("SYMBOLS " + st.getNumSymbols());
        w.println("\n== DATA/CODE UNITS ==");
        Listing lst = currentProgram.getListing();
        w.println("INSTRUCTIONS " + lst.getNumInstructions());
        w.println("DEFINED_DATA " + lst.getNumDefinedData());
        w.close();
        println("wrote " + out);
    }
}
