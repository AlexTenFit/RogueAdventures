#pragma once

#include "raylib.h"
#include "raymath.h"

struct MapData
{
    Vector2 pos;
    float scale;
};

enum AnimLoop {
    IDLE_DOWN = 0,
    IDLE_SIDE = 1,
    IDLE_UP = 2,
    MOVE_DOWN = 3,
    MOVE_SIDE = 4,
    MOVE_UP = 5
};

struct AnimData
{
    int frame;
    int maxFrame;
    float runningTime;
    float updateTime;
};
