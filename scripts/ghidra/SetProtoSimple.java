// WARNING: Ghidra may add a hidden return-storage parameter when this sets a
// far-pointer return type on a __cdecl16far function.  Use a scalar return type
// or set custom variable storage explicitly for those cases.
// Set a function prototype from donor types.
// Args: funcAddr donorFuncAddr returnDonorFuncAddr paramDonorFuncAddr paramIndex paramName callingConvention
// The return type is taken from returnDonorFuncAddr, the parameter type from
// paramDonorFuncAddr at paramIndex.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class SetProtoSimple extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Function f = getFunctionAt(toAddr(a[0]));
        Function retDonor = getFunctionAt(toAddr(a[1]));
        Function paramDonor = getFunctionAt(toAddr(a[2]));
        int idx = Integer.parseInt(a[3]);
        String pname = a[4];
        String cc = a.length > 5 ? a[5] : "__cdecl";
        if (f == null || retDonor == null || paramDonor == null) {
            println("missing function");
            return;
        }
        DataType ret = retDonor.getReturnType();
        Variable[] ps = paramDonor.getParameters();
        if (idx < 0 || idx >= ps.length) { println("bad param index"); return; }
        DataType pt = ps[idx].getDataType();
        int tx = currentProgram.startTransaction("set prototype");
        try {
            f.setCallingConvention(cc);
            f.setReturn(ret, retDonor.getReturn().getVariableStorage(), SourceType.USER_DEFINED);
            Variable[] old = f.getParameters();
            for (int i = old.length - 1; i >= 0; i--) f.removeParameter(i);
            if (pt != null && pt.getLength() != 0) {
                f.addParameter(new ParameterImpl(pname, pt, currentProgram),
                               SourceType.USER_DEFINED);
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("set " + f.getName() + " -> " + f.getSignature().getPrototypeString()
                + " cc=" + f.getCallingConventionName());
    }
}
