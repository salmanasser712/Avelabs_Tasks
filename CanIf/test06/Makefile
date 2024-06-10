Base_Dir :=../../../OpenSAR

CPPUTEST_HOME :=D:/cygwin64/usr/local
CPPFLAGS = -I$(CPPUTEST_HOME)/include/ -I$(CPPUTEST_HOME)/include/CppUTest -I$(CPPUTEST_HOME)/include/CppUTestExt 

LD_LIBRARIES = -LD:/cygwin64/usr/local/lib -lCppUTest -lCppUTestExt

CXXFLAGS := -I$(Base_Dir)/include -I$(Base_Dir)/boot/config/ -I$(Base_Dir)/include/generic -I$(Base_Dir)/arch/generic/mingw/kernel

vpath %.c $(Base_Dir)/communication/CanIf/:$(Base_Dir)/boot/config/

SOURCES = stubs.c CanIf.c CanIf_Cfg.c Can_PBcfg.c main.cpp test.cpp

OBJECTS = $(SOURCES:.c=.o)

OBJECTS := $(OBJECTS:.cpp=.o)


build: $(OBJECTS)
	g++ -std=c++2a $(CXXFLAGS) $(CPPFLAGS) $^ $(LD_LIBRARIES) -o output

%.o: %.c
	gcc $(CXXFLAGS) $(CPPFLAGS) $^ -c 

%.o: %.cpp
	g++ -std=c++2a $(CXXFLAGS) $(CPPFLAGS) $^ -c 


.PHONY: TestReport
TestReport: build
	-./output.exe > TestReport.txt
	make -s clean

clean:
	rm -f *.o *.exe 