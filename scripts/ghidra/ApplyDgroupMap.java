// Apply recovered DGROUP symbols/types to the current program from
// doc/dgroup_map.csv (offset,name,length,decl).
// Args: dgroup_map.csv
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.file.*;
import java.util.regex.*;

public class ApplyDgroupMap extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        BufferedReader r = Files.newBufferedReader(Paths.get(a[0]));
        String ln;
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        DataType undef = new Undefined1DataType();
        int labels = 0, types = 0, fallback = 0;
        int tx = currentProgram.startTransaction("apply DGROUP map");
        try {
            boolean header = true;
            while ((ln = r.readLine()) != null) {
                if (header) { header = false; continue; }
                String[] c = ln.split(",", -1);
                if (c.length < 4) continue;
                int off = Integer.parseInt(c[0], 16);
                String name = c[1];
                int len = Integer.parseInt(c[2]);
                String decl = c[3];
                if (len <= 0) continue;
                Address at = currentProgram.getAddressFactory().getAddress(
                        String.format("2410:%04X", off));
                if (at == null) continue;
                if (currentProgram.getMemory().getBlock(at) == null) continue;

                // label
                try {
                    Symbol s = currentProgram.getSymbolTable().getPrimarySymbol(at);
                    if (s == null) createLabel(at, name, true);
                    else s.setName(name, SourceType.USER_DEFINED);
                    labels++;
                } catch (Throwable t) { }

                // type: parse "type name[N]" or "type name"
                DataType dt = null;
                Matcher m = Pattern.compile("^(.*?)\\s+([A-Za-z_]\\w*)(?:\\[(\\d+)\\])?$")
                        .matcher(decl.trim());
                if (m.matches()) {
                    String tn = m.group(1).trim();
                    int n = m.group(3) == null ? 0 : Integer.parseInt(m.group(3));
                    DataType base = dtm.getDataType(tn);
                    if (base == null) base = dtm.getDataType("/" + tn);
                    if (base == null && tn.equals("undefined")) base = undef;
                    if (base != null) {
                        if (n > 0) {
                            int el = base.getLength();
                            if (el <= 0) el = 1;
                            dt = new ArrayDataType(base, n, el);
                        } else {
                            dt = base;
                        }
                    }
                }
                if (dt == null || dt.getLength() != len) {
                    dt = new ArrayDataType(undef, len, 1);
                    fallback++;
                }
                try {
                    clearListing(at, at.add(len - 1));
                    createData(at, dt);
                    types++;
                } catch (Throwable t) { }
            }
            r.close();
            println("DGROUP labels=" + labels + " typed=" + types
                    + " fallback=" + fallback);
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
