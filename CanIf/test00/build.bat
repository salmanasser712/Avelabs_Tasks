@echo on
setlocal enabledelayedexpansion

REM Initialize an empty string for the include directories
set "INCLUDE_FLAGS=-I..\..\..\include -I..\..\..\boot\config -I..\..\..\include\generic -I..\..\..\arch\generic\mingw\kernel"


:: Source Files to compile
set "CanIf_Source=..\..\..\communication\CanIf\CanIf.c"
set "Main_Source=main.c"
set "Stubs_Source=stubs.c"

REM Now you can use INCLUDE_DIRS in your gcc command
gcc %INCLUDE_FLAGS% %Stubs_Source%  -c -Wall
gcc %INCLUDE_FLAGS% %Main_Source%  -c  -Wall
gcc %INCLUDE_FLAGS% %CanIf_Source%  -c -Wall

gcc %INCLUDE_FLAGS% main.o stubs.o CanIf.o -o output -Wall

output.exe

objdump -t output.exe

clean.bat
