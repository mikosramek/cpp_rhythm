#include "Room.h"

Room::Room(Sequences l_sequences) {
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
}

Room::~Room() { }