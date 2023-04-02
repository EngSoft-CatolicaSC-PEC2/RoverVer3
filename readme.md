# Rover Navigation Project
This project is a simple console-based program that simulates a rover navigating a 2D grid map. The goal of the rover is to find its way from a starting position to a destination position while avoiding blocked paths. The program uses a predefined map size and provides various functions to move the rover, read the map, and manage the rover's position.

## Features
* 2D grid map navigation
* Rover movement functions
* Map boundary checks
* Console output of the map
* Trail marking for rover movements

## Files
* rover.h: Header file containing declarations for the rover, including its position, movement, and rotation functions.
* map.h: Header file containing declarations for the map, including its size, characters representing different elements, and functions to interact with the map.
* rover.c: Source file containing the implementation of the rover's functionality, such as moving, rotating, and checking map boundaries.
* map.c: Source file containing the implementation of the map's functionality, such as loading, marking positions, and printing the map.

### Usage

Compile the project using a C compiler:

```
gcc -o rover_navigation rover.c mapa.c
```

Run the compiled program:
    
```
./rover_navigation
```

Interact with the program by entering commands to move the rover and navigate the map. The available commands are:

R: Move the rover to the right
L: Move the rover to the left
U: Move the rover up
D: Move the rover down

The program will display the current map state after each command. The rover's goal is to reach the destination marked by 'D'.

# Contributing
Contributions to this project are welcome. Please create a fork of the repository, make your changes, and submit a pull request for review.

# License
This project is licensed under the MIT License. Please refer to the LICENSE file for more information.