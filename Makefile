EXEC: diec
LIB: libdiec

BUILD-DIR := ./build
CC := clang $(CFLAGS)
CFLAGS := -std=c99 -Wall -Werror
CCTEST := $(CC) -g -Og

.PHONY: install lib all clean scratch

install: $(EXEC)

lib: $(LIB)

all: $(EXEC) $(LIB) test scratch clean

test: rollDice_test.o
	$(CCTEST) -o test rollDice_test.o
	./test

scratch:
	$(CC) scratchpad.c -o scratchpad
	./scratchpad

clean:
	rm -rf build

rollDice_test.o: rollDice.o
	$(CC) -o rollDice_test.o ./rollDice.o

rollDice.o

