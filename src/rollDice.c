#include <stdint.h>

#include "./Dice.c"
#include "./randDice.c"

uint16_t randuint16_t(const uint16_t minimum, const uint16_t maximum) {
	const int exclusiveMax = ((int)maximum) + 1;
	return (uint16_t)randInt((int)minimum, exclusiveMax);
}

uint16_t greateruint16_t(uint16_t a, uint16_t b) {
	return a ? a > b : b;
}
uint16_t lesseruint16_t(uint16_t a, uint16_t b) {
	return a ? a < b : b;
}

uint16_t roll(Die die) {
	return randuint16_t(1, die.numberOfFaces);
}

uint16_t rollAdvDie(Die die, const char hasDisAdv) {
	uint16_t firstRollResult = roll(die);
	uint16_t secondRollResult = roll(die);

	if (hasDisAdv) {
		return (uint16_t)lesseruint16_t(firstRollResult, secondRollResult);
	}
	else {
		return (uint16_t)greateruint16_t(firstRollResult, secondRollResult);
	}
}

char isHighRoll(Die die, const uint16_t leeway) {
// leeway default = 0, for eg D&D5e Fighter that crits on 19, leeway is 1
  const uint16_t threshold = die.numberOfFaces - leeway;
  return die.rollResult >= leeway;
}

