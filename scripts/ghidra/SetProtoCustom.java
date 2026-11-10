// Set a function prototype with explicit return/parameter storage.
// Args: funcAddr retDonorAddr paramDonorAddr paramIndex paramName cc
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class SetProtoCustom extends GhidraScript {
    private Address stackAddress(int off) {
        AddressSpace sp = currentProgram.getAddressFactory().getAddressSpace("stack");
        if (sp != null) return sp.getAddress(off);
        for (AddressSpace x : currentProgram.getAddressFactory().getAddressSpaces()) {
            if (x.getName().equalsIgnoreCase("stack")) return x.getAddress(off);
        }
        return null;
    }

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Function f = getFunctionAt(toAddr(a[0]));
        Function retDonor = getFunctionAt(toAddr(a[1]));
        Function paramDonor = getFunctionAt(toAddr(a[2]));
        int idx = Integer.parseInt(a[3]);
        String pname = a[4];
        String cc = a.length > 5 ? a[5] : "__cdecl16far";
        if (f == null || retDonor == null || paramDonor == null) {
            println("missing function");
            return;
        }
        DataType ret = retDonor.getReturnType();
        VariableStorage retStore = retDonor.getReturn().getVariableStorage();
        Variable[] ps = paramDonor.getParameters();
        if (idx < 0 || idx >= ps.length) { println("bad param index"); return; }
        DataType pt = ps[idx].getDataType();
        int tx = currentProgram.startTransaction("set custom prototype");
        try {
            for (int i = f.getParameters().length - 1; i >= 0; i--)
                f.removeParameter(i);
            f.setCustomVariableStorage(true);
            f.setReturn(ret, retStore, SourceType.USER_DEFINED);
            Address saddr = stackAddress(6);
            VariableStorage pstore = new VariableStorage(currentProgram, saddr, 4);
            f.addParameter(new ParameterImpl(pname, pt, pstore, currentProgram),
                           SourceType.USER_DEFINED);
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("set " + f.getName() + " -> " + f.getSignature().getPrototypeString()
                + " cc=" + f.getCallingConventionName());
        println("return storage " + f.getReturn().getVariableStorage());
        for (Variable v : f.getParameters())
            println("param " + v.getName() + " " + v.getDataType().getName()
                    + " @ " + v.getVariableStorage());
    }
}
