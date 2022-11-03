#include "Sequencer.h"

Sequencer::Sequencer():
    m_bar(sf::Vector2f(0, 0))
{
    InitLocations();
}

Sequencer::Sequencer(sf::RenderWindow& l_window):
    m_bar(sf::Vector2f(l_window.getSize().x *  0.3, 450))
{
    InitLocations();
}

Sequencer::~Sequencer() {}

void Sequencer::InitLocations() {
    m_castleLocation = Location("data/castle.json");
    m_currentLocation = m_castleLocation;
}

void Sequencer::ChooseLocation(LocationName l_location) {
    m_roomIndex = 0;
    switch (l_location) {
        case castle:
            m_currentLocation = m_castleLocation;
            break;
        default:
            break;
    }
}

void Sequencer::GenerateNextSequence() {
    m_currentLocation.GenerateNewRoomOrder();
    m_notes = m_currentLocation.GetNextRoomsNotes(m_roomIndex);
    m_noteIndex = 0;
}

void Sequencer::Tick() {
    for (int i = 0; i < m_notes.size(); i += 1) {
        m_notes[i].Tick();
    }
}

void Sequencer::Render(sf::RenderWindow& l_window) {
    for (int i = 0; i < m_notes.size(); i += 1) {
        m_notes[i].Render(l_window);
    }
    m_bar.Render(l_window);
}

void Sequencer::HandleEvents(sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) {
            CheckHit();
        }
    }
}

void Sequencer::CheckHit() {
    NoteData& nextNote = m_notes[m_noteIndex];
    Result result = m_bar.IsInBar(nextNote.GetPosition());
    if (result == Result::miss) {
        MissedNote();
    } else {
        HitNote(result);
    } 
    nextNote.Destroy();
    m_noteIndex += 1;
}

void Sequencer::HitNote(Result l_result) {
    m_debug.Log(l_result == 2 ? "Perfect" : "Okay");
}

void Sequencer::MissedNote() {
    m_debug.Log("Missed!");
}
