#include <stdlib.h>
#include <time.h>

typedef unsigned short int u16;

// INFO: helper functions
static void seedRand(unsigned int seed){ // makes the pseudo-random generator a bit more random
	unsigned int unixTime = time(NULL);
	if (seed == 0) { // sets seed to current unix time if == 0
		seed = time(NULL);
	}
	seed = (seed >> 1) + 1;
	seed = seed ^ ((unixTime << 1) - 1);
	srand(seed);
}

int randInt(const int inclusiveMin, const int exclusiveMax) {
	static unsigned int seed;
	seedRand(seed);

	/* NOTE:
	 * rand() produces a positive int in the domain [0, int)
	 * % max-min reduces possible results to the desired domain [0, max - min)
	 * + min at the end shifts the min and max away from [0, max - min) to [min, max) */
	return (rand() % (exclusiveMax - inclusiveMin)) + inclusiveMin;
}

u16 randU16(const u16 inclusiveMin, const u16 exclusiveMax) {
	return (u16)randInt(inclusiveMin, exclusiveMax);
}

u16 greaterU16(u16 a, u16 b) {
	return a ? a > b : b;
}
u16 lesserU16(u16 a, u16 b) {
	return a ? a < b : b;
}
// INFO: end of helper functions

typedef struct Die {
  const u16 numberOfFaces;
  u16 rollResult;
} Die;

u16 rollDie(Die die) {
	return (u16)randU16(1, die.numberOfFaces + 1);
}

u16 rollAdvDie(Die die, const char isDisAdv) {
	u16 firstRollResult = rollDie(die);
	u16 secondRollResult = rollDie(die);

	if (isDisAdv) {
		return (u16)lesserU16(firstRollResult, secondRollResult);
	}
	else {
		return (u16)greaterU16(firstRollResult, secondRollResult);
	}
}

char isHighRoll(Die die, const u16 leeway) {
// leeway default = 0, for eg D&D5e Fighter that crits on 19, leway is 1
  const u16 threshold = die.numberOfFaces - leeway;
  return die.rollResult >= leeway;
}

