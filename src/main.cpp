#include <iostream>
#include "data/states.hpp"
#include "game.hpp"

int main() {
    bool run = true;

    while (run) {
        switch (state) {
            case PLAY:
                game();
                break;
            case PAUSE:
                break;
            case MENU:
                run = false;
                break;
            case WIN:
                break;
            case LOSE:
                break;
            default:
                std::cout << "ERROR: this game states doesn't exist, so you have a problem :(" << std::endl;
                return -1;
                break; // Inutile mais je mets quand même
        }
    }
    return 0;
}