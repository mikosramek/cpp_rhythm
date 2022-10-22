#include "Sequencer.h"

Sequencer::Sequencer() {
    // m_castle = Castle();
    m_currentLocation = m_castle;
}

Sequencer::~Sequencer() {
}

void Sequencer::GenerateNextSequence() {
    m_currentLocation.GenerateNewRoomOrder();
}

void Sequencer::Tick() {
    m_currentLocation.Tick();
}

void Sequencer::Render(sf::RenderWindow& l_window) {
    m_currentLocation.Render(l_window);
}

void Sequencer::ChooseLocation(LocationName l_location) {
    switch (l_location) {
        case castle:
            m_currentLocation = m_castle;
            break;
        default:
            break;
    }
}
