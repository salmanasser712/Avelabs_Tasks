@echo on
setlocal enabledelayedexpansion

REM Initialize an empty string for the include directories
set "Base_Dir=..\..\..\OpenSAR"
set "INCLUDE_FLAGS=-I%Base_Dir%\include -I%Base_Dir%\boot\config -I%Base_Dir%\include\generic -I%Base_Dir%\arch\generic\mingw\kernel"


:: Source Files to compile
set "CanIf_Source=%Base_Dir%\communication\CanIf\CanIf.c"
set "CanIfCfg_Source=%Base_Dir%\boot\config\CanIf_Cfg.c"
set "CanPBcfg_Source=%Base_Dir%\boot\config\Can_PBcfg.c"
set "Main_Source=main.c"
set "Stubs_Source=stubs.c"

REM Now you can use INCLUDE_DIRS in your gcc command
gcc %INCLUDE_FLAGS% %Stubs_Source%  -c -Wall
gcc %INCLUDE_FLAGS% %Main_Source%  -c  -Wall
gcc %INCLUDE_FLAGS% %CanIf_Source%  -c -Wall
gcc %INCLUDE_FLAGS% %CanIfCfg_Source%  -c -Wall
gcc %INCLUDE_FLAGS% %CanPBcfg_Source%  -c -Wall

gcc %INCLUDE_FLAGS% main.o stubs.o CanIf.o CanIf_cfg.o Can_PBcfg.o -o output -Wall --coverage

output.exe


clean.bat
