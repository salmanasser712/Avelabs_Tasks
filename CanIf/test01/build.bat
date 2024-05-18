@echo on
setlocal enabledelayedexpansion

REM Initialize an empty string for the include directories
set "INCLUDE_FLAGS=-I..\..\..\include -I..\..\..\include\arm -I..\..\..\arch\arm\arm_cr4\kernel\ -I..\..\..\include\arm -I..\..\..\app\config -I..\..\..\app\config\GEN"


:: Source Files to compile
set "CanIf_Source=..\..\..\communication\CanIf\CanIf.c"
set "Main_Source=main.c"
set "Stubs_Source=stubs.c"


REM Now you can use INCLUDE_DIRS in your gcc command
tiarmclang -c -flto -mcpu=cortex-m4 %INCLUDE_FLAGS% %Stubs_Source% 
tiarmclang -c -flto -mcpu=cortex-m4 %INCLUDE_FLAGS% %CanIf_Source%  
tiarmclang -c -flto -mcpu=cortex-m4 %INCLUDE_FLAGS% %Main_Source%   

tiarmclang -mcpu=cortex-m4 %INCLUDE_DIRS% CanIf.o stubs.o main.o -o output.hex -Wl,Linkscript_ti.cmd

tiarmnm output.hex

clean.bat

