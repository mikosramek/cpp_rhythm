#include "NoteBar.h"

NoteBar::NoteBar(){ }
NoteBar::~NoteBar() { }

NoteBar::NoteBar(sf::Vector2f l_position, sf::Vector2f l_size) {
    m_rect.setSize(l_size);
    m_rect.setPosition(l_position);
    m_rect.setFillColor(sf::Color(60, 175, 60, 128));
}

sf::RectangleShape NoteBar::GetBar() {
    return m_rect;
}

void NoteBar::Render(sf::RenderWindow& l_window) {
    l_window.draw(m_rect);
}
