#include <stdio.h>

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

