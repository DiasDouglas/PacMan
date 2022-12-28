#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "../Ghost/ghost.h"
#include "../Utils/utils.h"
#include "../PacMan/pacman.h"

int isValidMovementInput(char command){
    return command == UP || command == DOWN || command == LEFT || command == RIGHT;
}

void movePacmanToX(int positionX, Map* map, PacMan* pacman){
    char possiblePosition = map->matrix[positionX][pacman->position.y];

    if(possiblePosition != TOPDOWN_WALL && possiblePosition != SIDE_WALL){
        map->matrix[pacman->position.x][pacman->position.y] = EMPTY_SPACE;
        pacman->position.x = positionX;
        map->matrix[pacman->position.x][pacman->position.y] = PACMAN;
    }
}

void movePacmanToY(int positionY, Map* map, PacMan* pacman) {
    char possiblePosition = map->matrix[pacman->position.x][positionY];

    if(possiblePosition != TOPDOWN_WALL && possiblePosition != SIDE_WALL){
        map->matrix[pacman->position.x][pacman->position.y] = EMPTY_SPACE;
        pacman->position.y = positionY;
        map->matrix[pacman->position.x][pacman->position.y] = PACMAN;
    }
}

void movePacman(char command, Map* map, PacMan* pacman){
    if(!isValidMovementInput(command)){
        return;
    }

    switch (command){
        case UP: 
            movePacmanToX(pacman->position.x - 1, map, pacman);
            break;
        case LEFT:
            movePacmanToY(pacman->position.y - 1, map, pacman);
            break;
        case DOWN:
            movePacmanToX(pacman->position.x + 1, map, pacman);
            break;
        case RIGHT:
            movePacmanToY(pacman->position.y + 1, map, pacman);
            break;
    }
}

void moveGhosts(Map* map, Ghost[] ghosts, Position pacmanPosition){
    for(int i = 0; i < 2; i++){
        // TODO
    }
}

void findPacmanStartPosition(Map* map, PacMan* pacman) {
    for(int i = 0; i < map->rows; i++){
        for(int j = 0; j < map->columns; j++){
            if(map->matrix[i][j] == PACMAN){
                pacman->position.x = i;                
                pacman->position.y = j;   
                break;             
            }
        }
    }
}

void findGhostsStartPositions(Map* map, Ghost* ghosts) {
    int ghostCount = 0;
    
    for(int i = 0; i < map->rows; i++){
        for(int j = 0; j < map->columns; j++){
            if(map->matrix[i][j] == GHOST){
                Ghost ghost = newGhost(i, j);

                ghosts[ghostCount] = ghost;   

                ghostCount++;    
            }
        }
    }
}

void aloccMap(Map* map) {
    map->matrix = malloc(sizeof(char*) * map->rows);

    for(int i = 0; i < map->rows; i++){
        map->matrix[i] = malloc(sizeof(char) * map->columns + 1);
    }
}

void readMap(Map* map, PacMan* pacman, Ghost* ghosts) {
    FILE* f;
    f = fopen("resources/map.txt", "r");

    if(f == 0) {
        printf("Error reading map file!\n");
        exit(1);
    }

    fscanf(f, "%d %d", &(map->rows), &(map->columns));

    aloccMap(map);

    for(int i = 0; i < map->rows; i++){
        fscanf(f, "%s", map->matrix[i]);
    }

    findPacmanStartPosition(map, pacman);
    findGhostsStartPositions(map, ghosts);

    fclose(f);
}

void freeMap(Map* map) {
    for(int i = 0; i < map->rows; i++){
        free(map->matrix[i]);
    }
    free(map->matrix);
}

void printMap(Map* map) {
    system("cls");

    for(int i = 0; i < map->rows; i++){
        printf("%s\n", map->matrix[i]);
    }
}