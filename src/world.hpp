#pragma once

#include <vector>

// Simple maze: width x height
const int MAZE_WIDTH = 10;
const int MAZE_HEIGHT = 8;

// Row-major: 0 empty, 1 wall, 2 player
static std::vector<int> maze = {
    1,1,1,1,1,1,1,1,1,1,
    1,2,0,0,0,1,0,0,0,1,
    1,0,1,1,0,1,0,1,0,1,
    1,0,0,1,0,0,0,1,0,1,
    1,0,0,1,1,1,0,1,0,1,
    1,0,0,0,0,0,0,1,0,1,
    1,0,1,1,1,1,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1
};
