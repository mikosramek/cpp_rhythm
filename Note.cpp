#include "Note.h"

Note::Note(sf::Vector2f startPosition, float size, float speed, sf::Color color, sf::Texture* l_texture) {
    m_position = startPosition;
    m_shape = sf::CircleShape(size);
    m_shape.setOrigin(size, size);
    m_shape.setPosition(m_position);
    m_shape.setFillColor(color);
    m_speed = speed;

    m_texture = l_texture;
    m_sprite.setTexture((*m_texture));
    m_sprite.setPosition(m_position);


    m_sprite.setOrigin(275, 275); // red
    m_sprite.setOrigin(260, 290); // yellow
    m_sprite.setOrigin(270, 270); // green

    m_sprite.setTextureRect(sf::IntRect(30, 30, 550, 550)); // red
    m_sprite.setTextureRect(sf::IntRect(14, 600, 550, 580)); // yellow
    m_sprite.setTextureRect(sf::IntRect(0, 1200, 540, 540)); // green

    
    m_sprite.setScale(0.2, 0.2);
}

Note::Note() {
    m_position = sf::Vector2f(0,0);
    m_shape = sf::CircleShape(0);
    m_speed = 0;

    m_texture->create(0.0f, 0.0f);
}

Note::~Note() { }

void Note::Tick() {
    m_position.x -= m_speed;
    m_shape.setPosition(m_position);
    m_sprite.setPosition(m_position);
}

bool Note::isInBar(sf::RectangleShape bar) {
    return false;
}

void Note::Render(sf::RenderWindow& l_window) {
    l_window.draw(m_shape);
    l_window.draw(m_sprite);
}