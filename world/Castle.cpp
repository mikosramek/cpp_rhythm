#include "Castle.h"

// game inits
// sequencer inits
// castle inits -> creating the rooms
// rooms being created makes the actual SONG at that point
// places rooms in possible locations (start/middle/end)

// choose location
// generate location -> strings together different rooms

Castle::Castle() {
    Room baseRoom(
        Sequences {
            Sequence(
                Notes {
                    NoteData(sf::Vector2f(0.25, 3)),
                    NoteData(sf::Vector2f(0.25, 2)),
                    NoteData(sf::Vector2f(0.25, 3)),
                    NoteData(sf::Vector2f(0.25, 2))
                },
                4,
                "castle_bg.ogg" // bg
            ),
            Sequence(
                Notes {
                    NoteData(sf::Vector2f(0.5, 1)),
                    NoteData(sf::Vector2f(0.125, 4)),
                    NoteData(sf::Vector2f(0.125, 4)),
                    NoteData(sf::Vector2f(0.25, 3))
                },
                4,
                "castle_bg.ogg" // enemy 1
            ),
            Sequence(
                Notes {
                    NoteData(sf::Vector2f(0.125, 4)),
                    NoteData(sf::Vector2f(0.125, 2)),
                    NoteData(sf::Vector2f(0.125, 4)),
                    NoteData(sf::Vector2f(0.125, 2)),
                    NoteData(sf::Vector2f(0.25, 1)),
                    NoteData(sf::Vector2f(0.25, 1))
                },
                4,
                "castle_bg.ogg" // enemy 2
            ),
            Sequence(
                Notes {
                    NoteData(sf::Vector2f(0.5, 3)),
                    NoteData(sf::Vector2f(0.125, 4)),
                    NoteData(sf::Vector2f(0.125, 4)),
                    NoteData(sf::Vector2f(0.25, 1))
                },
                4,
                "castle_bg.ogg" // enemy 3
            )
        }
    );

    m_entryRooms.push_back(baseRoom);
    m_middleRooms.push_back(baseRoom);
    m_bossRooms.push_back(baseRoom);

    m_roomIndex = 0;
}
