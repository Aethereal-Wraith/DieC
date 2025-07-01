#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void seedRand(){ // makes the pseudo-random generator a bit more random
    time_t currentTime;
    srand(time(&currentTime)); // time() sets the value pointed to by 1st arg as the current UNIX time, or returns the timestamp if NULL pointer
}

int randInt(int inclusiveMin, int exclusiveMax) {
    // rand() produces a positive int [0, sizeof(int)]
    // % max-min reduces possible results to the desired range [0, max - min)
    // + min at the end shifts the min and max away from [0, max - min) to [min, max)
    seedRand();
    return ( rand() % ( exclusiveMax - inclusiveMin ) ) + inclusiveMin;
}

int dieRoll(int numberOfFaces) {
    return randInt(1, (numberOfFaces + 1));
}

int main() {
    int inputInt, result;

    printf("\nWhich die is being used?\nd");
    scanf("%d", &inputInt);

    result = dieRoll(inputInt);
    printf("The result is: %d \n", result);

}
