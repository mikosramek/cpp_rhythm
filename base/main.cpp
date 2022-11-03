#include "Game.h"
#include "Config.h"
#include "GlobalSettings.h"

int main() {
    Config config;
    GlobalSettings settings;
    Game game(settings, config);

    while (!game.GetWindow()->IsDone()) {
        game.Tick();
        game.Render();
        game.RestartClock();
    }
}