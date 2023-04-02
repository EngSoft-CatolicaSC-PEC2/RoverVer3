// Implementation of the functions declared in mapa.h

#include <stdio.h>

#include "map.h"

int printCount = 0;
char map[MAP_SIZE][MAP_SIZE];          // Define the 2D character array that represents the map

// Sets a given character at a specified position on the map
void markPosition(int row, int column, char mark) {
    map[row][column] = mark;
}

// Reads the character at a specified position on the map
char readPosition(int row, int column) {
    return map[row][column];
}

// Initializes the map with default values
void loadMap() {
    printCount = 0;
    for (int row = 0; row < MAP_SIZE; row++) {
        for (int column = 0; column < MAP_SIZE; column++) {
            map[row][column] = TERRAIN;
        }
    }
}

// Prints the map to the console
void printMap() {
    printCount++;
    printf("\nPrint:%d\n", printCount);
    for (int row = 0; row < MAP_SIZE; row++) {
        for (int column = 0; column < MAP_SIZE; column++) {
            printf("%c ", map[row][column]);
        }
        printf("\n"); // Line break
    }
}