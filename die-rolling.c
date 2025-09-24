#include <stdlib.h>
#include <time.h>

// helper function
static unsigned int seed;
void seedRand(int &seed){ // makes the pseudo-random generator a bit more random
	if (!seed) {	// sets seed to current unix time if == 0
		seed = time(NULL);
	}
	seed = (seed >> 1) + 1;
	srand(seed);
}

int randInt(const int inclusiveMin, const int exclusiveMax) {
	// INFO:
	// rand() produces a positive int in the domain [0, sizeof(int)]
	// % max-min reduces possible results to the desired domain [0, max - min)
	// + min at the end shifts the min and max away from [0, max - min) to [min, max)
	seedRand();
	return (rand() % (exclusiveMax - inclusiveMin)) + inclusiveMin;
}

int rollDie(const int numberOfFaces) {
	return randInt(1, numberOfFaces + 1);
}

int rollAdvDie(const int firstRoll, const int secondRoll, const int isDisAdv) {
	if (isDisAdv) {

		return firstRoll < secondRoll ? firstRoll : secondRoll;
	}
	else {
		return firstRoll > secondRoll ? firstRoll : secondRoll;
	}
}

