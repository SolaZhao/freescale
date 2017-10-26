SET INSTALLPATH=C:\Freescale\CodeWarrior_HC12

%INSTALLPATH%\prog\piper.exe %INSTALLPATH%\prog\maker.exe -ENV"GENPATH=.\Sources;%INSTALLPATH%\lib\hc12c\src;%INSTALLPATH%\lib\hc12c\lib" -ENV"OBJPATH=.\bin" -ENV"ABSPATH=.\bin" -ENV"TEXTPATH=.\bin" -DINSTALLPATH=%INSTALLPATH% default.mak 
