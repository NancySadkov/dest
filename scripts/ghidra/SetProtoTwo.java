// Set a two-parameter prototype with explicit storage.
// Args: funcAddr retDonor p1Donor p1Idx p1Name p2Donor p2Idx p2Name cc
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class SetProtoTwo extends GhidraScript {
    private Address stackAddress(int off) {
        AddressSpace sp = currentProgram.getAddressFactory().getAddressSpace("stack");
        return sp == null ? null : sp.getAddress(off);
    }

    private DataType donorType(Function f, int idx) {
        Variable[] ps = f.getParameters();
        return (idx >= 0 && idx < ps.length) ? ps[idx].getDataType() : null;
    }

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Function f = getFunctionAt(toAddr(a[0]));
        Function retDonor = getFunctionAt(toAddr(a[1]));
        Function p1Donor = getFunctionAt(toAddr(a[2]));
        int p1Idx = Integer.parseInt(a[3]);
        String p1Name = a[4];
        Function p2Donor = getFunctionAt(toAddr(a[5]));
        int p2Idx = Integer.parseInt(a[6]);
        String p2Name = a[7];
        String cc = a.length > 8 ? a[8] : "__cdecl16far";
        if (f == null || retDonor == null || p1Donor == null || p2Donor == null) {
            println("missing function");
            return;
        }
        DataType ret = retDonor.getReturnType();
        VariableStorage retStore = retDonor.getReturn().getVariableStorage();
        DataType p1Type = donorType(p1Donor, p1Idx);
        DataType p2Type = donorType(p2Donor, p2Idx);
        int tx = currentProgram.startTransaction("set two-param prototype");
        try {
            for (int i = f.getParameters().length - 1; i >= 0; i--)
                f.removeParameter(i);
            f.setCustomVariableStorage(true);
            f.setReturn(ret, retStore, SourceType.USER_DEFINED);
            f.addParameter(new ParameterImpl(p1Name, p1Type,
                    new VariableStorage(currentProgram, stackAddress(6), 4),
                    currentProgram), SourceType.USER_DEFINED);
            f.addParameter(new ParameterImpl(p2Name, p2Type,
                    new VariableStorage(currentProgram, stackAddress(0xa), 4),
                    currentProgram), SourceType.USER_DEFINED);
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("set " + f.getName() + " -> " + f.getSignature().getPrototypeString()
                + " cc=" + f.getCallingConventionName());
        println("return " + f.getReturn().getVariableStorage());
        for (Variable v : f.getParameters())
            println("param " + v.getName() + " " + v.getDataType().getName()
                    + " @ " + v.getVariableStorage());
    }
}
