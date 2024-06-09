Base_Dir :=../../../OpenSAR

INCLUDE_FLAGS := -I$(Base_Dir)/include -I$(Base_Dir)/boot/config/ -I$(Base_Dir)/include/generic -I$(Base_Dir)/arch/generic/mingw/kernel

vpath %.c $(Base_Dir)/communication/CanIf/:$(Base_Dir)/boot/config/

SOURCES = main.c stubs.c CanIf.c CanIf_Cfg.c Can_PBcfg.c

OBJECTS = $(SOURCES:.c=.o)


build: $(OBJECTS)
	gcc $(INCLUDE_FLAGS) $^ -o output -fprofile-arcs -ftest-coverage

%.o: %.c
	gcc $(INCLUDE_FLAGS) $^ -c -fprofile-arcs -ftest-coverage

coverage: build
	@./output.exe
	@gcov -c -d . -o $(OBJECTS)
#	@$(shell lcov.bat)
#	genhtml index.info -o html --ignore-errors source

clean:
	rm -f *.o *.gcno *.exe *.gcda