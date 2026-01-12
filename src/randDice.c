#include <stdlib.h>
#include <time.h>

static void seedRand(unsigned int seed){ // Makes the pseudo-random generator a bit more random
	unsigned int unixTime = time(NULL);
	if (seed == 0) { // Sets seed to current UNIX time if == 0
		seed = time(NULL);
	}
	seed = (seed >> 1) + 1;
	seed = seed ^ ((unixTime << 1) - 1);
	srand(seed);
}

int restrictDomain(int input, const int inclusiveMin, const int exclusiveMax) {
	/* INFO:
	 * % (exclusiveMax - inclusiveMin) reduces possible results to the desired domain [0, max - min)
	 * + min at the end shifts the min and max away from [0, max - min) to [min, max) */
	const int domainSize = exclusiveMax - inclusiveMin;
	const int sizeRestricted = input % domainSize;
	return sizeRestricted + inclusiveMin;
}

int randInt(const int inclusiveMin, const int exclusiveMax) {
	/* NOTE: static means each function call uses
	 * same var instead of initialising new one each time */
	static unsigned int seed;
	seedRand(seed);
	const int randNum = rand();
	return restrictDomain(randNum, inclusiveMin, exclusiveMax);
}

uint16_t randuint16_t(const uint16_t inclusiveMin, const uint16_t exclusiveMax) {
	return (uint16_t)randInt((int)inclusiveMin, exclusiveMax);
}

