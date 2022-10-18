#pragma once
#include <SFML/Graphics.hpp>

// Duplicate for now
class NoteData {
public:
    NoteData(sf::Vector2f startPosition);
    NoteData();
    ~NoteData();
private:
    sf::Vector2f m_position;
    sf::CircleShape m_shape;
    bool m_isVisible;
};
