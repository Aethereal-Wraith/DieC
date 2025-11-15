#include <stdlib.h>
#include <time.h>

// TODO: resize most ints to short int instead?

// helper functions
static unsigned int seed = 0;
static void seedRand(int *seed_ptr){ // makes the pseudo-random generator a bit more random
	if *seed_ptr == 0 {	// sets seed to current unix time if == 0
		*seed_ptr = time(NULL);
	}
	*seed_ptr = (*seed_ptr >> 1) + 1;
	srand(*seed_ptr);
}

int randInt(const int inclusiveMin, const int exclusiveMax, unsigned int *seed_ptr) {
	seedRand(*seed_ptr);
	/* INFO:
	rand() produces a positive int in the domain [0, sizeof(int)] % max-min reduces possible results to the desired domain [0, max - min) + min at the end shifts the min and max away from [0, max - min) to [min, max)
	*/
  return (rand() % (exclusiveMax - inclusiveMin)) + inclusiveMin;
}
// end of helper functions

typedef struct {
  const int numberOfFaces;
  int rollResult;
} Die;

int rollDie(Die *die) {
	return randInt(1, die.numberOfFaces + 1);
}

// TODO: change firstRoll to firstRollResult?
int rollAdvDie(const int firstRoll, const int secondRoll, const int isDisAdv) {
	if (isDisAdv) {

		return firstRoll < secondRoll ? firstRoll : secondRoll;
	}
	else {
		return firstRoll > secondRoll ? firstRoll : secondRoll;
	}
}

int isHighRoll(Die *die, const int leeway) {
  const int threshold = die.numberOfFaces - leeway
  return die.rollResult >= leeway;
}
