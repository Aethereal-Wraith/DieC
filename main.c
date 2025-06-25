#include <stdlib.h>

int randInt(int min, int max) {
    // rand() produces a positive int [0, sizeof(int)].
    // % max-min reduces possible results to the desired range [0, max - min)
    // + min at the end shifts the min and max away from [0, max - min) to [min, max)
    return ( rand() % ( max - min ) ) + min;
}

int main() {}
