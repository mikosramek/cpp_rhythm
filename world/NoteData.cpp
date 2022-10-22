#include "NoteData.h"

const int NOTE_SIZE = 25;

NoteData::NoteData(sf::Vector2f l_startPosition) {
    m_position = l_startPosition;
    m_isVisible = true;

    m_shape = sf::CircleShape(NOTE_SIZE);
    m_shape.setOrigin(NOTE_SIZE, NOTE_SIZE);
    m_shape.setPosition(m_position);
    m_shape.setFillColor(sf::Color::Red);

    m_speed = 0.1; // TODO: base speed on sequence tempo
}

NoteData::NoteData() {
    m_position = sf::Vector2f(0, 0);
    m_isVisible = false;
    m_shape = sf::CircleShape(0);
    m_speed = 0;
}

NoteData::~NoteData() {}

void NoteData::Render(sf::RenderWindow& l_window) {
    if (!m_isVisible) return;
    l_window.draw(m_shape);
}

void NoteData::Tick() {
    m_position.x -= m_speed;
    m_shape.setPosition(m_position);
}

sf::Vector2f NoteData::GetPosition() {
    return m_position;
}

void NoteData::SetPosition(sf::Vector2f l_pos) {
    m_position = l_pos;
    m_shape.setPosition(m_position);
}
