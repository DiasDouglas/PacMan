#include "ghost.h"
#include "../Utils/utils.h"

Ghost newGhost(int x, int y){
    Ghost ghost;

    ghost.position.x = x;
    ghost.position.y = y;
    ghost.direction = RIGHTWARD;

    return ghost;
}

