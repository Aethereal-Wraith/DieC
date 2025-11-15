VERSION := c99

all: diec, test, libdiec, scratch

diec: DieC.o

src: main.o CLI.o rollDice.o

main.o:
	gcc -c main.c
CLI.o:
	gcc -c CLI.c
rollDice.o:
	gcc -c rollDice.c

scratch:
	gcc -std=c99 scratchpad.c -o scratch
	./scratch
	rm scratch

