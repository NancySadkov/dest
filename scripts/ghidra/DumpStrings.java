// Dump the string data with escaped text, for the naming ledger.
// Args: out.tsv
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Data;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.*;
import java.io.*;

public class DumpStrings extends GhidraScript {
    static String esc(String s) {
        StringBuilder b = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '\n') b.append("\\n");
            else if (c == '\r') b.append("\\r");
            else if (c == '\t') b.append("\\t");
            else if (c >= 32 && c < 127) b.append(c);
            else b.append(String.format("\\x%02x", (int) c));
        }
        return b.toString();
    }

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        PrintWriter w = new PrintWriter(new FileWriter(a[0]));
        w.println("address\tname\tvalue");
        Memory mem = currentProgram.getMemory();
        int n = 0;
        for (Symbol s : currentProgram.getSymbolTable().getAllSymbols(true)) {
            if (!s.getName().startsWith("s_")) continue;
            Address ad = s.getAddress();
            Data d = currentProgram.getListing().getDataAt(ad);
            if (d == null || d.getLength() <= 0 || d.getLength() > 512) continue;
            byte[] raw = new byte[d.getLength()];
            try { mem.getBytes(ad, raw); } catch (Throwable t) { continue; }
            int k = 0;
            while (k < raw.length && raw[k] != 0) k++;
            if (k == 0) continue;
            w.println(ad + "\t" + s.getName() + "\t"
                    + esc(new String(raw, 0, k, "ISO-8859-1")));
            n++;
        }
        w.close();
        println("strings=" + n);
    }
}
