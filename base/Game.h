#pragma once
#include "Window.h"
#include "Note.h"
#include "DataReader.h"
#include "NoteBar.h"
#include "Config.h"
#include "GlobalSettings.h"
#include "../utils/MusicClip.h"
#include "../world/Sequencer.h"

class Game
{
public:
    Game(GlobalSettings settings, Config config);
    ~Game();
    Window* GetWindow();

    void Render();
    void Tick();
    float GetElapsed();
	void RestartClock();
private:
    Window m_window;

	sf::Clock m_clock;
	float m_elapsed;

	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;

    sf::Texture m_noteTexture;

    sf::Texture m_playerTexture;
    sf::Sprite m_playerSprite;
    float m_playerYPo;

    NoteBar m_bar;
    MusicClip m_clip;
    Sequencer m_sequencer;
};
