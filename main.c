#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//helper function
unsigned int seed = 0;
void seedRand(){ // makes the pseudo-random generator a bit more random
    if (seed == 0) {
        const time_t currentTime = time(NULL);
        seed = currentTime;
    }
    seed = (seed >> 1) + 1;
    srand(seed);
}

int randInt(const int inclusiveMin, const int exclusiveMax) {
    // rand() produces a positive int [0, sizeof(int)]
    // % max-min reduces possible results to the desired range [0, max - min)
    // + min at the end shifts the min and max away from [0, max - min) to [min, max)
    seedRand();
    return (rand() % (exclusiveMax - inclusiveMin)) + inclusiveMin;
}

int rollDie(const int numberOfFaces) {
    return randInt(1, numberOfFaces + 1);
}

int rollAdvDie(const int firstRoll, const int secondRoll, const int isDisAdv) {
    if (isDisAdv) {
        return (firstRoll < secondRoll ? firstRoll : secondRoll);
    }
    else {
        return firstRoll > secondRoll ? firstRoll : secondRoll;
    }
}

//Command Line Interface functions

void scanfDieFaces(int* ptrInputInt) {
    printf("\nWhich die is being used?\nd");
    scanf("%d", ptrInputInt);
}

int cliRollDie() {
    int dieFaces;

    scanfDieFaces(&dieFaces);
    const int result = rollDie(dieFaces);
    printf("\nThe result is: %d\n", result);

    return 0;
}

int cliAdv() {
    int dieFaces, isDisAdv;
    char inputDisAdv;

    printf("Roll with advantage or disadvantage? (a or d)\n");
    scanf("%c", &inputDisAdv);
    switch (inputDisAdv) {
        case 'a':
            isDisAdv = 0;
            break;
        case 'd':
            isDisAdv = 1;
            break;
        default:
            printf("%c is an invalid input", inputDisAdv);
            return 1;
    }

    scanfDieFaces(&dieFaces);
    const int firstRoll = rollDie(dieFaces), secondRoll = rollDie(dieFaces);
    const int result = rollAdvDie(firstRoll, secondRoll, isDisAdv);
    printf("\nThe rolls were: %d and %d. The result is: %d\n", firstRoll, secondRoll, result);

    return 0;
}

//MAIN

int main() {
    int errCode;
    // cliRollDie();
    if ((errCode = cliAdv()) > 0) {
        return errCode;
    };
}
