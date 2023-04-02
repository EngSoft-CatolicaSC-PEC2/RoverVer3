

#include <stdio.h>
#include "map.h"
#include "rover.h"

int roverRow = 0;
int roverColumn = 0;
int destinationRow = 0;
int destinationColumn = 0;

int roverMoveMatrixBlocking() {
    if (roverColumn < destinationColumn) {
        return roverMoveBlocking(RIGHT);
    } else if (roverColumn > destinationColumn) {
        return roverMoveBlocking(LEFT);
    } else if (roverRow < destinationRow) {
        return roverMoveBlocking(DOWN);
    } else if (roverRow > destinationRow) {
        return roverMoveBlocking(UP);
    }
}

int roverMoveMatrix() {
    if (roverColumn < destinationColumn) {
        return roverMove(RIGHT);
    } else if (roverColumn > destinationColumn) {
        return roverMove(LEFT);
    } else if (roverRow < destinationRow) {
        return roverMove(DOWN);
    } else if (roverRow > destinationRow) {
        return roverMove(UP);
    }
}

int roverMoveRow() {

    if (roverRow != destinationRow) {
        return MOVEMENT_WRONG_LINE;
    } else if (roverColumn < destinationColumn) {
        return roverMove(RIGHT);
    } else if (roverColumn > destinationColumn) {
        return roverMove(LEFT);
    } else {
        return MOVEMENT_END;
    }
}


int roverReadMap(char command) {
    if (command == RIGHT && isRightMapLimit() != 0) {
        return readPosition(roverRow, roverColumn + 1);
    } else if (command == LEFT && isLeftMapLimit() != 0) {
        return readPosition(roverRow, roverColumn - 1);
    } else if (command == UP && isUpperMapLimit() != 0) {
        return readPosition(roverRow - 1, roverColumn);
    } else if (command == DOWN && isLowerMapLimit() != 0) {
        return readPosition(roverRow + 1, roverColumn);
    } else {
        return INVALID;
    }
}

void roverSetStart(int row, int column) {
    roverRow = row;
    roverColumn = column;
    roverMakeTrail();
}

void roverSetDestination(int row, int column) {
    destinationRow = row;
    destinationColumn = column;
    markPosition(row, column, DESTINATION);
}


int roverMoveBlocking(char command) {
    char mapInfo = roverReadMap(command);
    if (mapInfo == INVALID || mapInfo == BLOCK || mapInfo == TRAIL) {
        command = roverRotateRobot(command);
        return roverMoveBlocking(command);
    }
    return roverMove(command);

}

int roverRotateRobot(char command) {
    if (command == RIGHT)
        if (isLowerMapLimit() != 0)
            return DOWN;
        else
            return UP;
    if (command == DOWN)
        if (isLeftMapLimit() != 0)
            return LEFT;
        else
            return RIGHT;
    if (command == LEFT)
        if (isUpperMapLimit() != 0)
            return UP;
        else
            return DOWN;
    if (command == UP)
        if (isRightMapLimit() != 0)
            return RIGHT;
        else
            return LEFT;
}

int roverMove(char command) {
    if (command == RIGHT && isRightMapLimit() != 0) {
        roverColumn++;
    } else if (command == LEFT && isLeftMapLimit() != 0) {
        roverColumn--;
    } else if (command == UP && isUpperMapLimit() != 0) {
        roverRow--;
    } else if (command == DOWN && isLowerMapLimit() != 0) {
        roverRow++;
    } else {
        return MOVEMENT_ERROR;
    }

    roverMakeTrail();


    if (foundEnd() != 0) {
        return MOVEMENT_END;
    } else {
        return MOVEMENT_SUCCESS;
    }
}

int foundEnd() {
    return roverColumn == destinationColumn && roverRow == destinationRow;
}

int isRightMapLimit() {
    return roverColumn < MAP_SIZE - 1;
}

int isLeftMapLimit() {
    return roverColumn > 0;
}

int isUpperMapLimit() {
    return roverRow > 0;
}

int isLowerMapLimit() {
    return roverRow < MAP_SIZE - 1;
}

void roverMakeTrail() {
    markPosition(roverRow, roverColumn, TRAIL);
}