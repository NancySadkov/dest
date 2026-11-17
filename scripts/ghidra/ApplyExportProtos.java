// Apply the signatures captured by ExportRecovered.java to the project.
//
// The export records what the decompiler inferred for every function; storing
// them makes the model carry real prototypes instead of `undefined f(void)`.
// Only signatures that actually say something (parameters or a non-undefined
// return) are applied, so no information is overwritten with an empty shape.
//
// Args: index.tsv
//@category DeSt
import ghidra.app.cmd.function.ApplyFunctionSignatureCmd;
import ghidra.app.script.GhidraScript;
import ghidra.app.util.cparser.C.CParserUtils;
import ghidra.program.model.address.Address;
import ghidra.app.services.DataTypeManagerService;
import ghidra.program.model.data.FunctionDefinitionDataType;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import java.io.*;
import java.util.*;

public class ApplyExportProtos extends GhidraScript {
    static final String[] CC = {"__cdecl16far", "__cdecl16near",
                                "__stdcall16far", "__stdcall16near",
                                "__cdecl", "__stdcall", "__pascal"};

    static boolean informative(String sig) {
        int i = sig.indexOf('(');
        int j = sig.lastIndexOf(')');
        if (i < 0 || j < i) return false;
        String inner = sig.substring(i + 1, j).trim();
        if (!inner.isEmpty() && !inner.equals("void")) return true;
        String ret = sig.substring(0, i).trim();
        for (String cc : CC) ret = ret.replace(cc, "");
        ret = ret.trim();
        return !(ret.isEmpty() || ret.equals("undefined") || ret.equals("void")
                 || ret.matches("undefined\\d"));
    }

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        if (a.length < 1) { println("usage: ApplyExportProtos <index.tsv>"); return; }
        List<String> lines = java.nio.file.Files.readAllLines(
                java.nio.file.Paths.get(a[0]), java.nio.charset.StandardCharsets.UTF_8);
        FunctionManager fm = currentProgram.getFunctionManager();
        int applied = 0, skipped = 0, failed = 0;
        int tx = currentProgram.startTransaction("apply export prototypes");
        try {
            for (int n = 1; n < lines.size(); n++) {
                String line = lines.get(n);
                String[] f = line.split("\t");
                if (f.length < 7) continue;
                String addr = f[1];
                String sig = f[6].trim();
                if (sig.isEmpty() || !informative(sig)) { skipped++; continue; }
                for (String cc : CC) sig = sig.replace(cc, " ");
                sig = sig.replaceAll("\\s+", " ").trim();
                Address at = currentProgram.getAddressFactory().getAddress(addr);
                Function fn = fm.getFunctionAt(at);
                if (fn == null || fn.isThunk()) { skipped++; continue; }
                FunctionDefinitionDataType fd = CParserUtils.parseSignature(
                        (DataTypeManagerService) null, currentProgram, sig);
                if (fd == null) { failed++; continue; }
                ApplyFunctionSignatureCmd cmd = new ApplyFunctionSignatureCmd(
                        at, fd, SourceType.ANALYSIS);
                if (cmd.applyTo(currentProgram, monitor)) applied++;
                else failed++;
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("applied=" + applied + " skipped=" + skipped + " failed=" + failed);
    }
}
