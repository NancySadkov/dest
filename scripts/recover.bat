@echo off
rem Reproduce the full DeSt recovery export.
rem Requires Ghidra 12.1.3 at C:\soft\ghidra_12.1.3_PUBLIC.
setlocal
set GHIDRA=C:\soft\ghidra_12.1.3_PUBLIC\support\analyzeHeadless.bat
set PROJECT=C:\Users\nangl\d\code\dest\gpr
set SCRIPTDIR=C:\Users\nangl\d\code\dest\scripts\ghidra
set OUTDIR=C:\Users\nangl\d\code\dest\src\decompiled

echo === Sanitizing symbol names ===
call "%GHIDRA%" "%PROJECT%" st -process st.exe -noanalysis -scriptPath "%SCRIPTDIR%" -postScript SanitizeSymbols.java
if errorlevel 1 goto :eof

echo === Exporting recovered source tree ===
call "%GHIDRA%" "%PROJECT%" st -process st.exe -noanalysis -scriptPath "%SCRIPTDIR%" -postScript ExportRecovered.java "%OUTDIR%"
if errorlevel 1 goto :eof

echo === Recovering global-data initialisers ===
call "%GHIDRA%" "%PROJECT%" st -process st.exe -noanalysis -scriptPath "%SCRIPTDIR%" -postScript ExportData.java "%OUTDIR%\st_globals.c"
if errorlevel 1 goto :eof

echo === Post-processing recovered source tree ===
python "%SCRIPTDIR%\..\fix_recovered.py"

echo Done: %OUTDIR%
endlocal
