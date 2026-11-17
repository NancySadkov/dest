// Recover function prototypes with Ghidra's Decompiler Parameter ID analyzer.
// Args: list | run
//@category DeSt
import ghidra.app.plugin.core.analysis.AutoAnalysisManager;
import ghidra.app.script.GhidraScript;
import ghidra.app.services.Analyzer;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;

public class RecoverProtos extends GhidraScript {
    int countDefault() {
        int n = 0;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            if (!f.isThunk() && f.getSignatureSource() == SourceType.DEFAULT) n++;
        }
        return n;
    }

    @Override
    public void run() throws Exception {
        String mode = getScriptArgs().length > 0 ? getScriptArgs()[0] : "list";
        AutoAnalysisManager mgr = AutoAnalysisManager.getAnalysisManager(currentProgram);
        Analyzer an = mgr.getAnalyzer("Decompiler Parameter ID");
        println("analyzer=" + (an == null ? "NOT FOUND" : an.getName()));
        int before = countDefault();
        println("functions_with_default_proto_before=" + before);
        if (!mode.equals("run") || an == null) return;

        AddressSetView set = currentProgram.getMemory()
                .getLoadedAndInitializedAddressSet();
        int tx = currentProgram.startTransaction("recover prototypes");
        long t0 = System.currentTimeMillis();
        try {
            mgr.scheduleOneTimeAnalysis(an, set);
            mgr.startAnalysis(monitor);
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("elapsed_ms=" + (System.currentTimeMillis() - t0));
        int after = countDefault();
        println("functions_with_default_proto_after=" + after);
        println("recovered=" + (before - after));
    }
}
