#include "Note.h"

Note::Note(sf::Vector2f startPosition, float size, float speed, sf::Color color) {
    m_position = startPosition;
    m_shape = sf::CircleShape(size);
    m_shape.setOrigin(size, size);
    m_shape.setPosition(m_position);
    m_shape.setFillColor(color);
    m_speed = speed;
}

Note::Note() {
    m_position = sf::Vector2f(0,0);
    m_shape = sf::CircleShape(0);
    m_speed = 0;
}

Note::~Note() { }

void Note::Tick() {
    m_position.x -= m_speed;
    m_shape.setPosition(m_position);
}

bool Note::isInBar(sf::RectangleShape bar) {
    return false;
}

void Note::Render(sf::RenderWindow& l_window) {
    l_window.draw(m_shape);
}