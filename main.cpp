#include <iostream>
#include "Game.h"

int main() {
    Game game("Rhythmic Motion");

    while (!game.GetWindow()->IsDone()) {
        game.Tick();
        game.Render();
    }
}