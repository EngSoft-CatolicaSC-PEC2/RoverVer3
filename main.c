#include <stdio.h>
#include "map.h"
#include "rover.h"

void exercise2_1();

void exercise2_2();

void exercise2_3();

void displayFinalResult(int);

int menu();

int main() {
    menu();
}

void exercise2_1() {
    printf("\n Exercise 2-1\n");
    printf("\n Search in the same row 2-1\n");

    roverSetStart(2, 1);
    roverSetDestination(2, 7);

    printMap();

    int movementResult = 0;
    do {
        movementResult = roverMoveRow();
        printMap();
    } while (movementResult != MOVEMENT_END && movementResult != MOVEMENT_WRONG_LINE);
    displayFinalResult(movementResult);

}


void exercise2_2() {
    printf("\n Exercise 2-2\n");

    roverSetStart(7, 7);
    roverSetDestination(1, 1);

    printMap();

    int movementResult = 0;
    do {
        movementResult = roverMoveMatrix();
        printMap();
    } while (movementResult != MOVEMENT_END);
    displayFinalResult(movementResult);
}

void exercise2_3() {
    printf("\n Exercise 2-2\n");

    roverSetStart(0, 0);
    roverSetDestination(0, 7);
    markPosition(0, 2, BLOCK);
    markPosition(1, 2, BLOCK);
    markPosition(2, 2, BLOCK);
    markPosition(3, 2, BLOCK);
    markPosition(4, 2, BLOCK);
    markPosition(4, 1, BLOCK);
    markPosition(6, 1, BLOCK);
    markPosition(7, 1, BLOCK);
    markPosition(6, 4, BLOCK);
    markPosition(7, 6, BLOCK);
    markPosition(2, 0, BLOCK);

    printMap();

    int movementResult = 0;
    do {
        movementResult = roverMoveMatrixBlocking();
        printMap();
    } while (movementResult != MOVEMENT_END);

    displayFinalResult(movementResult);
}

void displayFinalResult(int movementResult) {
    if (movementResult == MOVEMENT_END) {
        printf("\n\nSUCCESS! \n - Rover arrived at Row: %d  and  Column: %d", roverRow, roverColumn);
        printf("\n - Destination  Row: %d  and  Column: %d\n", destinationRow, destinationRow);
    } else if (movementResult == MOVEMENT_WRONG_LINE) {
        printf("\n\nFAILURE - Wrong row! \n - Rover is at Row: %d  and  Column: %d", roverRow, roverColumn);
        printf("\n - Destination  Row: %d  and  Column: %d\n", destinationRow, destinationRow);
    }
}


int menu() {
    int option = 1;

    do {
        printf("\n\nChoose the exercise:\n\n");
        printf("1. Exercise 1 - search in row\n");
        printf("2. Exercise 2 - search in map\n");
        printf("3. Exercises 3 and 4 - search with block\n");
        printf("0. Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                exercise2_1();
                break;

            case 2:
                exercise2_2();
                break;

            case 3:
                exercise2_3();
                break;

            case 0:
                break;

            default:
                printf("Digite a opção:\n");
        }
    } while (option != 0);
}