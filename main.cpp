#include "Game.h"
#include "Config.h"
#include "GlobalSettings.h"

int main() {
    Config config;
    GlobalSettings settings;
    Game game(settings.GetValue("title"));

    while (!game.GetWindow()->IsDone()) {
        game.Tick();
        game.Render();
    }
}