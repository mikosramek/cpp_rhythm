#pragma once
#include "Window.h"
#include "Note.h"
#include "DataReader.h"
#include "Config.h"
#include "GlobalSettings.h"
#include "../utils/MusicClip.h"
#include "../utils/Debug.h"
#include "../world/Sequencer.h"

class Game
{
public:
    Game(GlobalSettings settings, Config config);
    ~Game();
    Window* GetWindow();

    void CheckInput();
    void Render();
    void Tick();
	void RestartClock();
    sf::Time GetElapsed();
private:
    Window m_window;

	sf::Clock m_clock;
	sf::Time m_elapsed;

	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;

    sf::Texture m_noteTexture;

    sf::Texture m_playerTexture;
    sf::Sprite m_playerSprite;
    float m_playerYPo;

    NoteBar m_bar;
    MusicClip m_clip;
    Sequencer m_sequencer;

    Debug m_debug;
};
