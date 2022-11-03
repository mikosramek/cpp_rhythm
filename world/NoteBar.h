#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../utils/Debug.h"

class NoteBar
{
public:
    NoteBar(sf::Vector2f l_position, sf::Vector2f l_size);
    NoteBar();
    ~NoteBar();

    sf::RectangleShape* GetBar();
    sf::Vector2f GetBounds();
    void Render(sf::RenderWindow& l_window);
private:
    sf::RectangleShape m_rect;
    sf::Vector2f m_bounds;

    Debug m_debug;
};
