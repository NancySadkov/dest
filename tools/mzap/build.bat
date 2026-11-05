@echo off
rem Build with any GCC on PATH (w64devkit, MinGW-w64, ...).
gcc -D WINDOWS -O2 -o mzap.exe mzap.c
