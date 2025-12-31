BINS := diec libdiec test_diec scratch
CC := clang ${CFLAGS}
CFLAGS := -std=c99 -Wall -Werror
OBJECTS := src.o Dice.o randDice.o rollDice.o

###

all: ${BINS}

clean:
	rm -rf ${BINS} ${OBJECTS}

scratch:
	${CC} scratchpad.c -o scratch
	./scratch

### NOTE: Program Sources

src.o: Dice.o randDice.o rollDice.o
	ld -o src.o -r Dice.o randDice.o rollDice.o

Dice.o:
	${CC} -o Dice.o -c src/Dice.c src/Dice.h

randDice.o:
	${CC} -o randDice.o -c src/randDice.c src/randDice.h

rollDice.o:
	${CC} -o rollDice.o -c src/rollDice.c src/rollDice.h

### NOTE: Dynamic Library

libdiec: src.so

### NOTE: CLI

diec: src.o CLI.o

CLI.o:

### NOTE: Unit Tests

test_diec:

