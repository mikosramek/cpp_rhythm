#pragma once
#include <SFML/Graphics.hpp>

class NoteBar
{
public:
    NoteBar(sf::Vector2f l_position, sf::Vector2f l_size);
    NoteBar();
    ~NoteBar();

    sf::RectangleShape* GetBar();
    void Render(sf::RenderWindow& l_window);
private:
    sf::RectangleShape m_rect;
};
