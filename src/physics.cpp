#include "physics.hpp"

int idx(int x, int y, int width) {
    return y * width + x;
}

bool canMoveTo(int x, int y, const std::vector<int>& maze, int width, int height) {
    if (x < 0 || y < 0 || x >= width || y >= height) return false;
    int v = maze[idx(x,y,width)];
    // 1 is wall
    return (v != 1);
}
