#pragma once

#include "../Utils/utils.h"

typedef struct Ghost
{
    Position position;
    EDirection direction;
} Ghost;

Ghost newGhost(int x, int y);