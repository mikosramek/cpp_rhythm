#include "NoteData.h"

NoteData::NoteData(sf::Vector2f l_startPosition) {
    m_position = l_startPosition;
    m_isVisible = true;

    m_shape = sf::CircleShape(30);
    m_shape.setPosition(l_startPosition);
    m_shape.setOrigin(30, 30);
}

NoteData::NoteData() {
    m_position = sf::Vector2f(0, 0);
    m_isVisible = false;
    m_shape = sf::CircleShape(0);
}

NoteData::~NoteData() {}