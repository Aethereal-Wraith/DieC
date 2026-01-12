#include <stdio.h>
#include <stdint.h>

#include "Dice.h"
#include "randDice.h"
#include "rollDice.h" // FIXME:

static Die scanfDie(void) { // TODO: Does this _need_ to be static?
	printf("\nWhich die is being used?\n");
	uint16_t input;
	scanf("d%hd", &input);
	Die die = { .numberOfFaces = input };
	return die;
}

uint16_t cliRollDie() {
	Die die = scanfDie();
	const uint16_t result = roll(die);
	printf("\nThe result is: %d\n", result);

	return 0;
}

uint16_t cliAdv() {
	rollFlags flags;
	uint8_t input;

	printf("Roll with [A]dvantage or [D]isadvantage?\n");
	scanf("Input A/a or D/d: %c", &input);
	switch (input) {
		case 'A' | 'a':
			flags.hasAdv = 1;
			  break;
		case 'D' | 'd':
			  flags.hasDisAdv = 1;
			  break;
		default:
			  printf("%c is an invalid input", input);
			  return 1;
        }

    Die die = scanfDie();
    const uint16_t firstRoll = roll(die), secondRoll = roll(die);
    const uint16_t result = rollAdvDie(firstRoll, secondRoll, isDisAdv);
    printf("\nThe rolls were: %d and %d. The result is: %d\n", firstRoll, secondRoll, result);

    return 0;
}

