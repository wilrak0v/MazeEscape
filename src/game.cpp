#include <iostream>
#include <vector>
#include <termios.h>
#include <unistd.h>

#include "game.hpp"
#include "world.hpp"
#include "entity/player.hpp"
#include "physics.hpp"

static void setCanonicalMode(bool enabled) {
    static struct termios oldt;
    struct termios newt;
    if (!enabled) {
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
}

static void drawMaze(const std::vector<int>& maze, int width, int height) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int v = maze[y*width + x];
            if (v == 1) std::cout << '#';
            else if (v == 2) std::cout << '@';
            else std::cout << ' ';
        }
        std::cout << std::endl;
    }
}

void game()
{
    // find player pos from maze
    int px = 0, py = 0;
    for (int y = 0; y < MAZE_HEIGHT; ++y) for (int x = 0; x < MAZE_WIDTH; ++x) if (maze[y*MAZE_WIDTH + x] == 2) { px = x; py = y; }
    Player player(px, py);

    setCanonicalMode(false);

    bool running = true;
    while (running && state == PLAY) {
        // update maze player position
        std::vector<int> m = maze;
        m[py*MAZE_WIDTH + px] = 0;
        m[player.y*MAZE_WIDTH + player.x] = 2;

        // clear screen
        std::cout << "\x1B[2J\x1B[H";
        drawMaze(m, MAZE_WIDTH, MAZE_HEIGHT);

        char buf[3] = {0};
        int n = read(STDIN_FILENO, buf, 3);
        if (n <= 0) continue;
        if (buf[0] == 'q') { running = false; state = MENU; break; }
        if (buf[0] == '\x1b' && n >= 3 && buf[1] == '[') {
            int dx = 0, dy = 0;
            if (buf[2] == 'A') dy = -1;
            else if (buf[2] == 'B') dy = 1;
            else if (buf[2] == 'C') dx = 1;
            else if (buf[2] == 'D') dx = -1;

            if (player.tryMove(dx, dy, maze, MAZE_WIDTH, MAZE_HEIGHT)) {
                maze[py*MAZE_WIDTH + px] = 0;
                px = player.x; py = player.y;
                maze[py*MAZE_WIDTH + px] = 2;
            }
        }
    }

    setCanonicalMode(true);
}