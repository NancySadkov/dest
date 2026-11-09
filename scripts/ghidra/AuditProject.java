// Audit Ghidra naming coverage: functions, symbols, data, equates.
// Args: outdir
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class AuditProject extends GhidraScript {
    static boolean isDefault(String n) {
        return n.startsWith("FUN_") || n.startsWith("LAB_") || n.startsWith("DAT_")
            || n.startsWith("UNK_") || n.startsWith("SUB_") || n.startsWith("thunk_FUN_")
            || n.startsWith("Ordinal_") || n.startsWith("Entry_");
    }

    int countEquates() { int n=0; java.util.Iterator<ghidra.program.model.symbol.Equate> it=currentProgram.getEquateTable().getEquates(); while(it.hasNext()){it.next();n++;} return n; }

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        String outdir = a.length > 0 ? a[0] : "audit";
        new File(outdir).mkdirs();
        PrintWriter fn = new PrintWriter(new FileWriter(new File(outdir, "functions.tsv")));
        fn.println("address\tblock\tname\tsize\tdefault");
        int fTotal = 0, fDefault = 0;
        FunctionManager fm = currentProgram.getFunctionManager();
        for (Function f : fm.getFunctions(true)) {
            Address e = f.getEntryPoint();
            MemoryBlock b = currentProgram.getMemory().getBlock(e);
            boolean d = isDefault(f.getName());
            fTotal++; if (d) fDefault++;
            fn.println(e + "\t" + (b == null ? "?" : b.getName()) + "\t"
                + f.getName() + "\t" + f.getBody().getNumAddresses() + "\t" + d);
        }
        fn.close();

        PrintWriter sy = new PrintWriter(new FileWriter(new File(outdir, "symbols.tsv")));
        sy.println("address\tblock\tname\ttype\tdefault");
        int sTotal = 0, sDefault = 0;
        for (Symbol s : currentProgram.getSymbolTable().getAllSymbols(true)) {
            Address ad = s.getAddress();
            if (ad == null) continue;
            MemoryBlock b = currentProgram.getMemory().getBlock(ad);
            boolean d = isDefault(s.getName());
            sTotal++; if (d) sDefault++;
            sy.println(ad + "\t" + (b == null ? "?" : b.getName()) + "\t"
                + s.getName() + "\t" + s.getSymbolType() + "\t" + d);
        }
        sy.close();

        PrintWriter da = new PrintWriter(new FileWriter(new File(outdir, "data.tsv")));
        da.println("address\tblock\ttype\tlength\tsymbols\tdefault");
        int dTotal = 0, dNoSym = 0, dDefault = 0;
        for (Data d : currentProgram.getListing().getDefinedData(true)) {
            Address ad = d.getAddress();
            MemoryBlock b = currentProgram.getMemory().getBlock(ad);
            Symbol[] ss = currentProgram.getSymbolTable().getSymbols(ad);
            String names = "";
            boolean def = false;
            for (Symbol s : ss) {
                if (names.length() > 0) names += ";";
                names += s.getName();
                if (isDefault(s.getName())) def = true;
            }
            dTotal++;
            if (ss.length == 0) dNoSym++;
            if (def) dDefault++;
            DataType t = d.getDataType();
            da.println(ad + "\t" + (b == null ? "?" : b.getName()) + "\t"
                + (t == null ? "?" : t.getName()) + "\t" + d.getLength() + "\t"
                + names + "\t" + def);
        }
        da.close();

        PrintWriter su = new PrintWriter(new FileWriter(new File(outdir, "summary.txt")));
        su.println("functions=" + fTotal + " default=" + fDefault);
        su.println("symbols=" + sTotal + " default=" + sDefault);
        su.println("definedData=" + dTotal + " noSymbol=" + dNoSym + " defaultSymbol=" + dDefault);
        su.println("equates=" + countEquates());
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            su.println("block " + b.getName() + " " + b.getStart() + ".." + b.getEnd()
                + " size=" + b.getSize() + " exec=" + b.isExecute());
        }
        su.close();
        println("audit written to " + outdir);
    }
}
