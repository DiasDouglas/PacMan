#pragma once

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define PACMAN '@'
#define GHOST 'G'
#define TOPDOWN_WALL '-'
#define SIDE_WALL '|'
#define EMPTY_SPACE '.'

typedef struct Position {
    int x;
    int y;
} Position;

typedef enum EDirection{
    UPWARD,
    DOWNWARD,
    LEFTWARD,
    RIGHTWARD
} EDirection;