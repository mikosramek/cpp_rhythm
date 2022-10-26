#include "Sequencer.h"

Sequencer::Sequencer():
    m_castleLocation("data/castle.json")
{
    m_currentLocation = m_castleLocation;
}

Sequencer::~Sequencer() {}

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
            m_currentLocation = m_castleLocation;
            break;
        default:
            break;
    }
}
