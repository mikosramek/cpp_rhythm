#pragma once
#include <SFML/Graphics.hpp>
#include "../utils/Debug.h"

class NoteData {
public:
    NoteData(sf::Vector2f l_startPosition);
    NoteData();
    ~NoteData();
    void Render(sf::RenderWindow& l_window);
    void Tick();
    sf::Vector2f GetPosition();
    void SetPosition(sf::Vector2f l_pos);
    void Destroy();
    bool IsInBar(sf::Vector2f barBounds);
private:
    sf::Vector2f m_position;
    sf::CircleShape m_shape;
    bool m_isVisible;
    float m_speed;
    Debug m_debug;
};
