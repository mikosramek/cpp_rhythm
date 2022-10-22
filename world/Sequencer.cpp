#include "Sequencer.h"

Sequencer::Sequencer() {
    m_castle = Castle();
    m_currentLocation = m_castle;
}

Sequencer::~Sequencer() {
}

void Sequencer::GenerateNextSequence() {
    m_currentLocation.GenerateNewRoomOrder();
}
