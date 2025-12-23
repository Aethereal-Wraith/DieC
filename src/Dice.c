#include <stdint.h>

typedef struct Die {
  const uint16_t numberOfFaces;
  uint16_t rollResult;
} Die;

typedef struct rollFlags {
	char isHighRoll : 1;
	char isLowRoll : 1;
	char hasAdv : 1;
	char hasDisAdv : 1;
	char modifiers : 4;
} rollFlags;

