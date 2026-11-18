// Create (or rename) a label at a data address from a TSV: address<TAB>name[<TAB>comment].
// Unlike Rename.java this does not require an existing symbol.
// Args: labels.tsv
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class LabelData extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        SymbolTable st = currentProgram.getSymbolTable();
        Listing lst = currentProgram.getListing();
        int ok = 0, missing = 0, failed = 0;
        int tx = currentProgram.startTransaction("label data");
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t", -1);
                if (f.length < 2) continue;
                Address ad = currentProgram.getAddressFactory().getAddress(f[0]);
                if (ad == null) { println("BADADDR " + f[0]); missing++; continue; }
                String comment = f.length > 2 ? f[2].trim() : "";
                if (comment.startsWith("#")) comment = comment.substring(1).trim();
                try {
                    Symbol s = st.getPrimarySymbol(ad);
                    if (s != null) {
                        s.setName(f[1], SourceType.USER_DEFINED);
                    } else {
                        st.createLabel(ad, f[1], SourceType.USER_DEFINED);
                    }
                    if (!comment.isEmpty()) {
                        lst.setComment(ad, CodeUnit.EOL_COMMENT, comment);
                    }
                    ok++;
                } catch (Exception e) {
                    println("FAIL " + f[0] + " -> " + f[1] + " : " + e);
                    failed++;
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("labeled=" + ok + " missing=" + missing + " failed=" + failed);
    }
}
