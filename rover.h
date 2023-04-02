#ifndef ROVER_H
#define ROVER_H

// Define constants for movement directions and movement statuses
#define RIGHT 'R'
#define LEFT 'L'
#define UP 'U'
#define DOWN 'D'
#define MOVEMENT_END  10
#define MOVEMENT_SUCCESS  1
#define MOVEMENT_ERROR  -1
#define MOVEMENT_WRONG_LINE  -2

// Declare external variables for rover's position and destination position
extern int roverRow;
extern int roverColumn;
extern int destinationRow;
extern int destinationColumn;

// Function prototypes
int roverMoveRow();                // Move rover in row direction
int roverMoveMatrix();             // Move rover in matrix
int roverMoveMatrixBlocking();     // Move rover in matrix with blocking

int roverMove(char);               // Move rover based on given command
int roverMoveBlocking(char);       // Move rover with blocking based on given command
int roverRotateRobot(char);        // Rotate the rover based on given command
int roverReadMap(char);            // Read the map based on given command

void roverSetStart(int, int);      // Set rover's starting position
void roverSetDestination(int, int);// Set rover's destination position
void roverMakeTrail();             // Make a trail at the rover's current position

int isRightMapLimit();             // Check if the rover is at the right limit of the map
int isLeftMapLimit();              // Check if the rover is at the left limit of the map
int isUpperMapLimit();             // Check if the rover is at the upper limit of the map
int isLowerMapLimit();             // Check if the rover is at the lower limit of the map

int foundEnd();                    // Check if the rover has reached its destination

#endif //ROVER_H
