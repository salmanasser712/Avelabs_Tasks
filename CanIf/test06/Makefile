Base_Dir :=../../../OpenSAR

CPPUTEST_HOME :=D:/cygwin64/usr/local
CPPFLAGS = -I$(CPPUTEST_HOME)/include/ -I$(CPPUTEST_HOME)/include/CppUTest -I$(CPPUTEST_HOME)/include/CppUTestExt 

LD_LIBRARIES = -LD:/cygwin64/usr/local/lib -lCppUTest -lCppUTestExt

CXXFLAGS := -I$(Base_Dir)/include -I$(Base_Dir)/boot/config/ -I$(Base_Dir)/include/generic -I$(Base_Dir)/arch/generic/mingw/kernel

vpath %.c $(Base_Dir)/communication/CanIf/:$(Base_Dir)/boot/config/

SOURCES = stubs.c CanIf.c CanIf_Cfg.c main.cpp test.cpp

OBJECTS = $(SOURCES:.c=.o)

OBJECTS := $(OBJECTS:.cpp=.o)


build: $(OBJECTS)
	g++ -std=c++2a -O0 $(CXXFLAGS) $(CPPFLAGS) $^ $(LD_LIBRARIES) -o output

%.o: %.c
	g++ -std=c++2a -O0 $(CXXFLAGS) $(CPPFLAGS) $^  -c 

%.o: %.cpp
	g++ -std=c++2a -O0 $(CXXFLAGS) $(CPPFLAGS) $^ -c 


clean:
	rm -f *.o *.exe 