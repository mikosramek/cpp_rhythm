#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../utils/Debug.h"

enum Result {
    miss,
    okay,
    perfect
};

class NoteBar
{
public:
    NoteBar(sf::Vector2f l_position);
    NoteBar();
    ~NoteBar();

    sf::RectangleShape* GetBar();
    void Render(sf::RenderWindow& l_window);
    Result IsInBar(sf::Vector2f l_notePosition);
private:
    sf::RectangleShape m_okayBar;
    sf::RectangleShape m_perfectBar;
    float m_barMiddle;

    Debug m_debug;
};
