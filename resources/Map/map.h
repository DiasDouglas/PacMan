#pragma once
#include "../PacMan/pacman.h"
#include "../Ghost/ghost.h"
#include "../Utils/utils.h"

typedef struct Map {
    char** matrix;
    int rows;
    int columns;
} Map;

void findPacmanStartPosition(Map* map, PacMan* pacman);
void findGhostsStartPositions(Map* map, Ghost* ghosts);
void readMap(Map* map, PacMan* pacman, Ghost* ghosts);
void allocMap(Map* map);
void freeMap(Map* map);
void printMap(Map* map);
void movePacman(char command, Map* map, PacMan* pacman);