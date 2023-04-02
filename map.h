#ifndef MAPA_H
#define MAPA_H

// Define constants for the map
#define MAP_SIZE 8           // Size of the map
#define DESTINATION 'D'      // Character representing the destination
#define TRAIL 'T'            // Character representing a trail left by a player
#define BLOCK 'B'            // Character representing a blocked path
#define TERRAIN '*'          // Character representing terrain or an open path
#define INVALID 'I'          // Character representing an invalid position on the map

// Declare the 2D character array that represents the map
extern char map[MAP_SIZE][MAP_SIZE];

// Function declarations
void loadMap();                        // Initializes the map with default values
void markPosition(int, int, char);     // Sets a given character at a specified position on the map
void printMap();                       // Prints the map to the console
char readPosition(int, int);           // Reads the character at a specified position on the map

#endif //MAPA_H
