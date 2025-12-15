GCC99 := gcc -std=c99

###

all: diec, test, libdiec, scratch

###

diec: main.o src.o src.l

libdiec.h: src.l

src.c: CLI.o rollDice.o

src.l: CLI.l rollDice.l


main.o:
	{$GCC99} -c main.c -o main.o
CLI.o:
	{$GCC99} -c CLI.c -o cli.o
rollDice.o:
	{$GCC99} -c rollDice.c -o rollDice.o

###

test: test_rollDice.o

test_rollDice.o: rollDice.l
	{$GCC99}

###

scratch:
	{$GCC99} scratchpad.c -o scratch
	./scratch
	rm scratch

