// Replace a function's complete signature (return type + parameter list) from a definition, which is
// the only way to drop Ghidra's auto hidden return-storage parameter or change a far-pointer return.
// Args: tsv with
//   address<TAB>name<TAB>returnTypePath<TAB>callingConvention<TAB>param1Name:param1TypePath<TAB>...
// An empty parameter column list means "no parameters".
//@category DeSt
import ghidra.app.cmd.function.ApplyFunctionSignatureCmd;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class ApplySig extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        int ok = 0, failed = 0;
        for (String line : lines) {
            line = line.trim();
            if (line.isEmpty() || line.startsWith("#")) continue;
            String[] f = line.split("\t", -1);
            if (f.length < 4) { println("BADROW " + line); failed++; continue; }
            Address at = currentProgram.getAddressFactory().getAddress(f[0]);
            Function fn = at == null ? null : currentProgram.getFunctionManager().getFunctionAt(at);
            if (fn == null) { println("NOFUNC " + f[0]); failed++; continue; }
            DataType ret = dtm.getDataType(f[2].trim());
            if (ret == null) { println("NOTYPE " + f[2]); failed++; continue; }
            List<ParameterDefinition> params = new ArrayList<>();
            boolean bad = false;
            for (int i = 4; i < f.length; i++) {
                String spec = f[i].trim();
                if (spec.isEmpty()) continue;
                int c = spec.indexOf(':');
                if (c <= 0) { println("BADPARAM " + spec); bad = true; break; }
                DataType pt = dtm.getDataType(spec.substring(c + 1).trim());
                if (pt == null) { println("NOTYPE " + spec); bad = true; break; }
                params.add(new ParameterDefinitionImpl(spec.substring(0, c).trim(), pt, null));
            }
            if (bad) { failed++; continue; }
            FunctionDefinitionDataType sig =
                    new FunctionDefinitionDataType(new CategoryPath("/st.h"), f[1].trim(), dtm);
            sig.setReturnType(ret);
            sig.setArguments(params.toArray(new ParameterDefinition[0]));
            if (!f[3].trim().isEmpty()) sig.setCallingConvention(f[3].trim());
            int tx = currentProgram.startTransaction("apply signature");
            try {
                ApplyFunctionSignatureCmd cmd =
                        new ApplyFunctionSignatureCmd(at, sig, SourceType.USER_DEFINED);
                if (cmd.applyTo(currentProgram, monitor)) {
                    ok++;
                    println("ok " + fn.getName() + " : " + fn.getPrototypeString(false, false));
                } else {
                    failed++;
                    println("FAIL " + fn.getName() + " : " + cmd.getStatusMsg());
                }
            } catch (Throwable t) {
                failed++;
                println("FAIL " + fn.getName() + " : " + t);
            } finally {
                currentProgram.endTransaction(tx, true);
            }
        }
        println("applied=" + ok + " failed=" + failed);
    }
}
