#include "Location.h"

Location::Location() { }

Location::~Location() { }

// order of rooms for this location
// TODO: dynamically push rooms into sequence
void Location::GenerateNewRoomOrder() {
    m_sequence.clear();
    m_sequence.push_back(m_entryRooms[0]);
    m_sequence.push_back(m_middleRooms[0]);
    m_sequence.push_back(m_bossRooms[0]);
    std::cout << "creating new sequence" << std::endl;
}

void Location::Tick() {
    m_sequence[m_roomIndex].Tick();
}

void Location::Render(sf::RenderWindow& l_window) {
    m_sequence[m_roomIndex].RenderNotes(l_window);
}

// todo: handle moving to next room