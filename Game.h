#pragma once
#include "Window.h"
#include "Note.h"
#include "DataReader.h"
#include "NoteBar.h"

using Notes = std::vector<Note>;

class Game
{
public:
    Game(const std::string& l_title);
    ~Game();
    Window* GetWindow();

    void Render();
    void Tick();
    float GetElapsed();
	void RestartClock();
private:
    Window m_window;

    Notes m_notes;

	sf::Clock m_clock;
	float m_elapsed;

	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;

    sf::Texture m_noteTexture;

    sf::Texture m_playerTexture;
    sf::Sprite m_playerSprite;
    float m_playerYPo;

    NoteBar m_bar;
};