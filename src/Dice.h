#ifndef DICE_HEADER
	// include guard
#define DICE_HEADER

#include <stdint.h>

typedef struct Die {
  const uint16_t numberOfFaces;
  uint16_t rollResult;
} Die;

typedef struct rollFlags {
	uint8_t isHighRoll : 1;
	uint8_t isLowRoll : 1;
	uint8_t hasAdv : 1;
	uint8_t hasDisAdv : 1;
	uint8_t modifiers : 4;
} rollFlags;

#endif	// #ifndef DICE_HEADER
	// end include guard
