#include "Location.h"

// game inits
// sequencer inits
// castle inits -> creating the rooms
// rooms being created makes the actual SONG at that point
// places rooms in possible locations (start/middle/end)

// choose location
// generate location -> strings together different rooms

Location::Location() { }

Location::Location(std::string configFilePath) {
    m_data =  loader.LoadFile(configFilePath);

    // TODO: is there a better way to get/set defaults?
    m_tempo = m_data["tempo"];
    if (!m_tempo) { m_tempo = 4; }

    m_entryRooms = GetRoomsFromData("entryRooms");
    m_middleRooms = GetRoomsFromData("middleRooms");
    m_bossRooms = GetRoomsFromData("bossRooms");

    m_roomIndex = 0;
}

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

// meta: { name: string }
// tempo: number
// rooms: [ [ names of object for sequences ] ]
// sequence name: { musicFileName: string, notes: [ { row: number, length: number } ] }
Rooms Location::GetRoomsFromData(std::string roomType) {
    std::vector<Room> rooms;

    for(auto &roomSeqs: m_data[roomType]) {
        Sequences newSequence;
        for(auto &room: roomSeqs) {
            json roomData = m_data[room];
            Notes notes;
            for (auto &note: roomData["notes"]) {
                int row = note["row"];
                float length = note["length"];
                notes.push_back(NoteData(sf::Vector2f(length, row)));
            }
            newSequence.push_back(Sequence(
                notes,
                m_tempo,
                roomData["musicFileName"]
            ));
        }
        rooms.push_back(Room(newSequence, 24));
    }
    return rooms;
}

// todo: handle moving to next room