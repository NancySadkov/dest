// Audit every structure: size, field names, and which fields still carry
// auto-generated names.  Args: <out.csv>
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import java.io.*;
import java.util.*;
import java.util.regex.*;

public class AuditTypes extends GhidraScript {
    static final Pattern AUTO = Pattern.compile(
        "^(field\\d+_0x[0-9a-fA-F]+|field_0x[0-9a-fA-F]+|UNK_.*|undefined.*|" +
        "gap_.*|DAT_.*|u?Ram.*|.*Stack_.*|.*_0x[0-9a-fA-F]+|)$");

    static String pathOf(DataType dt) {
        String p = dt.getPathName();
        if (p == null || p.isEmpty()) p = dt.getName();
        return p.replace(',', ';');
    }

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        String out = a.length > 0 ? a[0] : null;
        PrintWriter w = out == null ? null : new PrintWriter(new FileWriter(out));
        if (w != null) w.println("struct,size,fields,auto_fields,offset,name,type,length,auto");
        int nStruct = 0, nFields = 0, nAuto = 0, nStructAuto = 0;
        TreeMap<String, Structure> structs = new TreeMap<>();
        Iterator<DataType> it = currentProgram.getDataTypeManager().getAllDataTypes();
        while (it.hasNext()) {
            DataType d = it.next();
            if (d instanceof Structure) structs.put(d.getPathName(), (Structure) d);
        }
        for (Structure s : structs.values()) {
            nStruct++;
            int nf = s.getNumComponents();
            List<String> lines = new ArrayList<>();
            int naf = 0;
            for (int i = 0; i < nf; i++) {
                DataTypeComponent c = s.getComponent(i);
                String name = c.getFieldName();
                boolean isAuto = AUTO.matcher(name == null ? "" : name).matches();
                if (isAuto) naf++;
                lines.add(String.format("%d,%s,%s,%d,%d", c.getOffset(),
                    name == null || name.isEmpty() ? "-" : name,
                    pathOf(c.getDataType()), c.getLength(), isAuto ? 1 : 0));
            }
            nFields += nf;
            nAuto += naf;
            if (naf > 0) nStructAuto++;
            if (w != null) {
                String head = String.format("%s,%d,%d,%d,",
                    s.getPathName().replace(',', ';'), s.getLength(), nf, naf);
                for (String l : lines) w.println(head + l);
            }
        }
        if (w != null) w.close();
        println("structures=" + nStruct + " fields=" + nFields +
                " auto_fields=" + nAuto + " structs_with_auto=" + nStructAuto);
        if (out != null) println("wrote " + out);
    }
}
