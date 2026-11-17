// Give generated string labels a name derived from their own content:
// data_2410_DATA_DGROUP_1A2B_string -> s_sorry_you_may_not_pause
//
// Args: out.tsv
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.DataType;
import ghidra.program.model.listing.Data;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class RenameStrings extends GhidraScript {
    static boolean isAuto(String n) {
        return n.endsWith("_string") || n.matches("data_[0-9A-Fa-f]{4}_\\w+_string[0-9]*");
    }

    static String ident(String s) {
        StringBuilder b = new StringBuilder();
        boolean sep = false;
        for (int i = 0; i < s.length() && b.length() < 44; i++) {
            char c = s.charAt(i);
            boolean ok = (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
            if (c >= 'A' && c <= 'Z') c = (char) (c + 32);
            if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
                if (sep && b.length() > 0) b.append('_');
                b.append(c);
                sep = false;
            } else {
                sep = true;
            }
        }
        String r = b.toString();
        if (r.isEmpty()) r = "empty";
        if (r.length() > 44) r = r.substring(0, 44);
        return "s_" + r;
    }

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        String out = a.length > 0 ? a[0] : "strings.tsv";
        Memory mem = currentProgram.getMemory();
        SymbolTable st = currentProgram.getSymbolTable();
        List<Symbol> todo = new ArrayList<Symbol>();
        for (Symbol s : st.getAllSymbols(true)) {
            if (s.getSymbolType() == SymbolType.LABEL && isAuto(s.getName()))
                todo.add(s);
        }
        PrintWriter w = new PrintWriter(new FileWriter(out));
        w.println("address\told\tvalue\tnew");
        int done = 0, skipped = 0;
        int tx = currentProgram.startTransaction("rename strings");
        try {
            for (Symbol s : todo) {
                Address ad = s.getAddress();
                Data d = currentProgram.getListing().getDataAt(ad);
                if (d == null) { skipped++; continue; }
                int len = d.getLength();
                if (len <= 0 || len > 512) { skipped++; continue; }
                byte[] raw = new byte[len];
                try {
                    mem.getBytes(ad, raw);
                } catch (Throwable t) { skipped++; continue; }
                int n = 0;
                while (n < raw.length && raw[n] != 0) n++;
                if (n < 2) { skipped++; continue; }
                String val = new String(raw, 0, n, "ISO-8859-1");
                String name = ident(val);
                String old = s.getName();
                try {
                    s.setName(name, SourceType.USER_DEFINED);
                } catch (Exception e) {
                    try {
                        s.setName(name + "_" + ad.getOffset(), SourceType.USER_DEFINED);
                    } catch (Exception e2) { skipped++; continue; }
                }
                w.println(ad + "\t" + old + "\t" + val.replace("\t", " ")
                        + "\t" + s.getName());
                done++;
            }
        } finally {
            currentProgram.endTransaction(tx, true);
            w.close();
        }
        println("renamed=" + done + " skipped=" + skipped + " candidates=" + todo.size());
    }
}
