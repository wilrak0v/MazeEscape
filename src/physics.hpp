#pragma once

#include <vector>

int idx(int x, int y, int width);

// Returns true if the position (x,y) is inside bounds and not a wall (1)
bool canMoveTo(int x, int y, const std::vector<int>& maze, int width, int height);
