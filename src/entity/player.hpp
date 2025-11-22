#pragma once

#include <vector>

class Player {
public:
    int x;
    int y;

    Player(int x_ = 1, int y_ = 1) : x(x_), y(y_) {}

    void setPos(int nx, int ny) { x = nx; y = ny; }

    // Try to move by (dx,dy); returns true if moved.
    bool tryMove(int dx, int dy, const std::vector<int>& maze, int width, int height);
};
