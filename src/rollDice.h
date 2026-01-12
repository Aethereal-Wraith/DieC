#ifndef ROLL_DICE_HEADER
	// include guard
#define ROLL_DICE_HEADER

#include <stdint.h>
#include "./Dice.h"

uint16_t randuint16_t(const uint16_t minimum, const uint16_t maximum);

uint16_t greateruint16_t(uint16_t a, uint16_t b);
uint16_t lesseruint16_t(uint16_t a, uint16_t b);

uint16_t roll(Die die);
uint16_t rollAdvDie(Die die, const uint8_t hasDisAdv);
uint8_t isHighRoll(Die die, const uint16_t leeway);

#endif	// ifndef ROLL_DICE_HEADER
	// end of include guard
