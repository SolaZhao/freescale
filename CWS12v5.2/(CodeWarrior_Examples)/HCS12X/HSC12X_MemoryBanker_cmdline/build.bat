@echo off

set PRM=prm\example.prm

set SRC=.\src
set OBJ=.\obj

set C_OPTIONS_PHASE_1=-CpuHCS12XE -Ml -AddIncldistribution_support.h -D_DISTRIBUTE_CONST -D_DISTRIBUTE_DATA -D_DISTRIBUTE_CODE -MemBanker -I"%INSTALLPATH%\lib\hc12c\include"
set C_OPTIONS_PHASE_2=-CpuHCS12XE -Ml -AddIncldata.h -AddInclcode.h -I"%INSTALLPATH%\lib\hc12c\include"
set L_OPTIONS_PHASE_1=-Dist -DistSegDISTRIBUTE -DistFilecode.h -DistInfocode.txt -ConstDist -ConstDistSegCONST_DISTRIBUTE -DataDist -DataDistInfodata.txt -DataDistSegDATA_DISTRIBUTE -DataDistFiledata.h -Options -LibOptions -OptionFileoptions.txt -LibFilelibrary.txt  -L"%INSTALLPATH%\lib\hc12c\lib"
set L_OPTIONS_PHASE_2=-M -ReadLibFile -P2LibFileNamegen\library.txt -L"%INSTALLPATH%\lib\hc12c\lib"

set COMPILER="%INSTALLPATH%\prog\piper.exe" "%INSTALLPATH%\prog\chc12.exe"
set LINKER="%INSTALLPATH%\prog\piper.exe" "%INSTALLPATH%\prog\linker.exe"
set GENPATH=.\gen
set OBJPATH=.\obj
set TEXTPATH=.\gen

REM PASS #1
for /f "tokens=*" %%f in ('dir /b src\*.c') do (
  %COMPILER% %C_OPTIONS_PHASE_1% %SRC%\%%f -objn="%OBJ%\%%f.o"
)

%LINKER% %L_OPTIONS_PHASE_1% %PRM%

rem PASS #2
set TEXTPATH="."
set G_OPT=
set /p G_OPT=<gen\options.txt

for /f "tokens=*" %%f in ('dir /b src\*.c') do (
  %COMPILER% %C_OPTIONS_PHASE_2% %G_OPT% %SRC%\%%f -objn="%OBJ%\%%f.o"
)

%LINKER% %L_OPTIONS_PHASE_2% %PRM%
