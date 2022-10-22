#include "Castle.h"


Castle::Castle() {
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
