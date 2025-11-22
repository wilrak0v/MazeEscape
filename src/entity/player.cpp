#include "entity/player.hpp"
#include "physics.hpp"

bool Player::tryMove(int dx, int dy, const std::vector<int>& maze, int width, int height)
{
    int nx = x + dx;
    int ny = y + dy;
    if (canMoveTo(nx, ny, maze, width, height)) {
        x = nx;
        y = ny;
        return true;
    }
    return false;
}
