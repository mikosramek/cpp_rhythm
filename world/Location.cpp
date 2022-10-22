#include "Location.h"

Location::Location() {
    Room baseRoom(
        Sequences {
            Sequence(
                Notes {
                    NoteData(sf::Vector2f(0.25, 1)),
                    NoteData(sf::Vector2f(0.25, 1)),
                    NoteData(sf::Vector2f(0.25, 1)),
                    NoteData(sf::Vector2f(0.25, 1))
                },
                4,
                "castle_bg.ogg"
            )
        }
    );

    m_entryRooms.push_back(baseRoom);
    m_middleRooms.push_back(baseRoom);
    m_bossRooms.push_back(baseRoom);
}

Location::~Location(){ }

void Location::GenerateNewRoomOrder() {
    m_sequence.clear();
    m_sequence.push_back(m_entryRooms[0]);
    m_sequence.push_back(m_middleRooms[0]);
    m_sequence.push_back(m_bossRooms[0]);
}