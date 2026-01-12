#ifndef RAND_DICE_HEADER
	// include guard
#define RAND_DICE_HEADER

#include <stdint.h>

int restrictDomain(int input, const int inclusiveMin, const int exclusiveMax);

int randInt(const int inclusiveMin, const int exclusiveMax);
uint16_t randuint16_t(const uint16_t inclusiveMin, const uint16_t exclusiveMax);

#endif	// ifndef RAND_DICE_HEADER
	// end include guard
