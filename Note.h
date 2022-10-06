#pragma once
#include <SFML/Graphics.hpp>

class Note
{
public:
    Note(sf::Vector2f startPosition, float size, float speed, sf::Color color);
    Note();
    ~Note();
    bool isInBar(sf::RectangleShape bar);
    void Render(sf::RenderWindow& l_window);
    void Tick();
private:
    sf::Vector2f m_position;
    sf::CircleShape m_shape;
    float m_speed;
};

