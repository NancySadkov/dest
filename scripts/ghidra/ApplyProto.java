// Apply a C prototype to functions from a TSV: address<TAB>signature
// Args: protos.tsv
//@category DeSt
import ghidra.app.cmd.function.ApplyFunctionSignatureCmd;
import ghidra.app.script.GhidraScript;
import ghidra.app.services.DataTypeManagerService;
import ghidra.app.util.cparser.C.CParserUtils;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.FunctionDefinitionDataType;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class ApplyProto extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        int ok = 0, failed = 0;
        int tx = currentProgram.startTransaction("apply prototypes");
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t");
                if (f.length < 2) continue;
                Address at = currentProgram.getAddressFactory().getAddress(f[0]);
                Function fn = currentProgram.getFunctionManager().getFunctionAt(at);
                if (fn == null) { println("NOFUNC " + f[0]); failed++; continue; }
                String sig = f[1].replace("__cdecl16far", " ").trim();
                FunctionDefinitionDataType fd = CParserUtils.parseSignature(
                        (DataTypeManagerService) null, currentProgram, sig);
                if (fd == null) { println("PARSE " + f[0] + " : " + sig); failed++; continue; }
                ApplyFunctionSignatureCmd cmd = new ApplyFunctionSignatureCmd(
                        at, fd, SourceType.USER_DEFINED);
                if (cmd.applyTo(currentProgram, monitor)) {
                    println("ok " + f[0] + " -> " + fn.getPrototypeString(false, false));
                    ok++;
                } else {
                    println("FAIL " + f[0]); failed++;
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("applied=" + ok + " failed=" + failed);
    }
}
