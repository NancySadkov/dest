// Create (or replace) data of a given type at an address and name it.
// Args: tsv with  address <TAB> name <TAB> typeSpec [<TAB> comment]
// typeSpec accepts the same forms as SetVarType ("/x", "base *", "T[N]").
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.util.task.ConsoleTaskMonitor;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;
import java.util.regex.*;

public class ApplyDataAt extends GhidraScript {
    private DataTypeManager dtm;

    private DataType resolve(String spec) {
        Matcher am = Pattern.compile("^(.+)\\[(\\d+)\\]$").matcher(spec);
        if (spec.endsWith(" *32")) {
            DataType b = dtm.getDataType(spec.substring(0, spec.length() - 4).trim());
            return b == null ? null : new PointerDataType(b, 4, dtm);
        }
        if (spec.endsWith(" *")) {
            DataType b = dtm.getDataType(spec.substring(0, spec.length() - 2).trim());
            return b == null ? null : new PointerDataType(b, 2, dtm);
        }
        if (am.matches()) {
            DataType b = dtm.getDataType(am.group(1).trim());
            return b == null ? null : new ArrayDataType(b, Integer.parseInt(am.group(2)), b.getLength());
        }
        return dtm.getDataType(spec);
    }

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        dtm = currentProgram.getDataTypeManager();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        int tx = currentProgram.startTransaction("apply data");
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t", -1);
                if (f.length < 3) { println("BADLINE " + line); continue; }
                Address at = currentProgram.getAddressFactory().getAddress(f[0]);
                if (at == null) { println("BADADDR " + f[0]); continue; }
                DataType dt = resolve(f[2].trim());
                if (dt == null) { println("NOTYPE " + f[2]); continue; }
                SymbolTable st = currentProgram.getSymbolTable();
                Symbol old = st.getPrimarySymbol(at);
                if (old != null) {
                    String n = old.getName();
                    st.removeSymbolSpecial(old);
                    println("  removed " + n + " @ " + at);
                }
                clearListing(at, at.add(dt.getLength() - 1));
                Data d = currentProgram.getListing().createData(at, dt);
                if (d == null) { println("CREATEFAILED " + f[0]); continue; }
                Symbol s = st.createLabel(at, f[1].trim(), SourceType.USER_DEFINED);
                if (f.length > 3 && !f[3].trim().isEmpty())
                    currentProgram.getListing().setComment(at,
                            CommentType.PLATE, f[3].trim());
                println("data " + f[1] + " : " + dt.getName() + " @ " + at
                        + " len=" + d.getLength());
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
