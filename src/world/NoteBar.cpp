#include "NoteBar.h"

const int OKAY_DISTANCE_LIMIT = 200;
const int PERFECT_DISTANCE_LIMIT = 50;

NoteBar::NoteBar(){ }
NoteBar::~NoteBar() { }

NoteBar::NoteBar(sf::Vector2f l_position) {
    m_okayBar.setSize(sf::Vector2f(OKAY_DISTANCE_LIMIT, 500));
    m_okayBar.setPosition(l_position);
    m_okayBar.setFillColor(sf::Color(60, 175, 60, 128));

    m_perfectBar.setSize(sf::Vector2f(PERFECT_DISTANCE_LIMIT, 500));
    m_perfectBar.setPosition(sf::Vector2f(l_position.x + OKAY_DISTANCE_LIMIT / 2 - PERFECT_DISTANCE_LIMIT / 2, l_position.y));
    m_perfectBar.setFillColor(sf::Color(200, 175, 60, 128));

    m_barMiddle = l_position.x + OKAY_DISTANCE_LIMIT/ 2;
}

sf::RectangleShape* NoteBar::GetBar() {
    return &m_okayBar;
}

void NoteBar::Render(sf::RenderWindow& l_window) {
    l_window.draw(m_perfectBar);
    l_window.draw(m_okayBar);
}


Result NoteBar::IsInBar(sf::Vector2f l_notePosition) {
    float distanceToNote = std::abs(m_barMiddle - l_notePosition.x);

    if (distanceToNote < PERFECT_DISTANCE_LIMIT) {
        return Result::perfect;
    } else if (distanceToNote < OKAY_DISTANCE_LIMIT) {
        return Result::okay;
    }
    return Result::miss;
}