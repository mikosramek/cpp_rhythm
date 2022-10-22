#include "Room.h"

Room::Room(Sequences l_sequences) {
    // TODO: Change these variables to be enemy render data, rather than actual music
    switch (l_sequences.size())
    {
        case 4:
            m_positionThree = l_sequences[3];
        case 3:
            m_positionTwo = l_sequences[2];
        case 2:
            m_positionOne = l_sequences[1];
        case 1:
            m_background = l_sequences[0];
        default:
            break;
    }

    // TODO: make this dynamically chosen
    // order of song for this room
    m_roomSong = Sequences { m_background, m_positionOne, m_positionTwo, m_positionThree };
    for (int i = 0; i < m_roomSong.size(); i += 1) {
        m_roomSong[i].SetSequencePosition(i);
    }
}

Room::~Room() { }

void Room::Tick() {
    for (int i = 0; i < m_roomSong.size(); i++) {
       m_roomSong[i].TickNotes();
    }
}

// room has 4 possible sequences
void Room::RenderNotes(sf::RenderWindow& l_window) {
    for (int i = 0; i < m_roomSong.size(); i++) {
        Notes notes = m_roomSong[i].GetNotes();
        for (int x = 0; x < notes.size(); x += 1) {
            notes[x].Render(l_window);
        }
    }
}
