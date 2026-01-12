#include <stdint.h>

#include "./Dice.h"
#include "./randDice.h"

uint16_t greateruint16_t(uint16_t a, uint16_t b) {
	return a ? a > b : b;
}
uint16_t lesseruint16_t(uint16_t a, uint16_t b) {
	return a ? a < b : b;
}

uint16_t roll(uint16_t numberOfFaces) {
	return randuint16_t(1, numberOfFaces + 1);
}

void rollDie(Die die) {
	die.rollResult = roll(die.numberOfFaces);
}

int rollAdvDie(Die die, const rollFlags flags) {
	// NOTE: returns 0 on success, 1 on error

	uint16_t firstRollResult = roll(die.numberOfFaces);
	uint16_t secondRollResult = roll(die.numberOfFaces);

	if (!(flags.hasAdv ^ flags.hasDisAdv)) {
		return 1;
		// WARN: ERROR if not Adv xor DisAdv => exactly 1 should be true
	}

	if (flags.hasAdv) {
		die.rollResult = greateruint16_t(firstRollResult, secondRollResult);
		return 0;
	}
	else /* flags.hasDisAdv */ {
		die.rollResult = lesseruint16_t(firstRollResult, secondRollResult);
		return 0;
	}
}

int isCriticalRoll(rollFlags * flags, Die die, const uint16_t successLeeway, const uint16_t failureLeeway) {
	// NOTE: returns 0 on success, 1 on error

	// INFO: Leeway = required closeness to min/max to count as a crit,
	// default 0 (must be **exactly** min/max roll.
	// E.g. in D&D 5e, Fighters can critically succeed on 19.
	// In this scenario, successLeeway = 1 (= 20 - 19)

	if ((successLeeway >= die.numberOfFaces) | (failureLeeway >= die.numberOfFaces)) {
		return 1;
	}

	const uint16_t successThreshold = die.numberOfFaces - successLeeway;
	flags->isHighRoll = die.rollResult >= successThreshold;

	const uint16_t failureThreshold = 1 + failureLeeway;
	flags->isLowRoll = die.rollResult <= failureThreshold;
	return 0;
}

