.PHONY: all clean rebuild

# definitions

COMPILER = g++

COMPILER_FLAGS = -c -Wall -Wextra -Werror -Wunreachable-code -Wredundant-decls \
-Wwrite-strings -Wundef -Wendif-labels -Wcast-qual -pedantic -I$(HEADERS)

DELETE = rm -f -v

EXE = example.exe

HEADERS = ../main/include

OBJECTS = testsuite.o example.o

SOURCE = ../main/src

# targets

all: $(EXE)

$(EXE): $(OBJECTS)
	$(COMPILER) -o $(EXE) $(OBJECTS)

clean:
	$(DELETE) *.exe *.o *.o

rebuild: clean all

example.o: example.cpp $(HEADERS)/testsuite.h $(SOURCE)/testsuite.cpp
	$(COMPILER) $(COMPILER_FLAGS) example.cpp

testsuite.o: $(HEADERS)/testsuite.h $(SOURCE)/testsuite.cpp
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCE)/testsuite.cpp
