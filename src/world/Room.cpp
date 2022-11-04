#include "Room.h"

Room::Room(Sequences l_sequences, int l_roomLength) {
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

    m_roomLength = l_roomLength;

    if (!m_positionThree.IsNull()) {
        GenerateFourSequenceSong();
    } else if (!m_positionTwo.IsNull()) {
        GenerateThreeSequenceSong();
    } else if (!m_positionOne.IsNull()) {
        GenerateTwoSequenceSong();
    } else {
        GenerateOneSequenceSong();
    }

    for (int i = 0; i < m_roomSong.size(); i += 1) {
        m_roomSong[i].SetSequencePosition(i);
    }
}

Room::~Room() { }

Notes Room::GetNotes() {
    Notes notes;
    for(int i = 0; i < m_roomSong.size(); i += 1) {
        Notes sequenceNotes = m_roomSong[i].GetNotes();
        for (int y = 0; y < sequenceNotes.size(); y += 1) {
            notes.push_back(sequenceNotes[y]);
        }
    }
    return notes;
}

void Room::GenerateOneSequenceSong() {
    for (int i = 0; i < m_roomLength; i += 1) {
        m_roomSong.push_back(m_background);
    }
}
void Room::GenerateTwoSequenceSong() {
    int rand;
    for (int i = 0; i < m_roomLength; i += 1) {
        rand = std::rand() % 10;
        // 0, 1, 2, 3, 4
        // 5, 6, 7, 8, 9
        if (rand <= 4) {
            m_roomSong.push_back(m_positionOne);
        } else {
            m_roomSong.push_back(m_background);
        }
    }
}

void Room::GenerateThreeSequenceSong() {
    int rand;
    for (int i = 0; i < m_roomLength; i += 1) {
        rand = std::rand() % 10;
        // 0, 1, 2,
        // 3, 4, 5
        // 6, 7, 8, 9
        if (rand <= 2) {
            m_roomSong.push_back(m_positionOne);
        } else if (rand <= 5) {
            m_roomSong.push_back(m_positionOne);
        } else {
            m_roomSong.push_back(m_background);
        }
    }
}

void Room::GenerateFourSequenceSong() {
    int rand;
    for (int i = 0; i < m_roomLength; i += 1) {
        rand = std::rand() % 10;
        // 0, 1,
        // 2, 3, 4
        // 5, 6,
        // 7, 8, 9
        if (rand <= 1) {
            m_roomSong.push_back(m_positionOne);
        } else if (rand <= 4) {
            m_roomSong.push_back(m_positionOne);
        } else if (rand <= 6) {
            m_roomSong.push_back(m_positionOne);
        } else {
            m_roomSong.push_back(m_background);
        }
    }
}
