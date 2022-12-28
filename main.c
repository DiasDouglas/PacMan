#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "resources/Map/map.h"
#include "resources/Utils/utils.h"
#include "resources/PacMan/pacman.h"


Map map;
PacMan pacman;
Ghost ghosts[2];

int isGameOver() {
    return 0;
}

int main() {    
    readMap(&map, &pacman, ghosts);

    do {
        printMap(&map);

        printf("Ghost 1 is at (%d, %d)\n", ghosts[0].position.x, ghosts[0].position.y);
        printf("Ghost 2 is at (%d, %d)\n", ghosts[1].position.x, ghosts[1].position.y);

        char command;
        scanf(" %c", &command);
        movePacman(command, &map, &pacman);
    } while(!isGameOver());

    freeMap(&map);
}