#include <iostream>
#include "Game.h"
#include "Config.h"

int main() {
    Config config;
    Game game(config.GetValue("title"));

    while (!game.GetWindow()->IsDone()) {
        game.Tick();
        game.Render();
    }
}