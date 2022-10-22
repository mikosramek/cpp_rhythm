#include "Sequence.h"

Sequence::Sequence() {
    m_notes = Notes {};
    m_tempo = 4;
    m_musicFileName = "";
}

Sequence::Sequence(Notes l_notes, int l_tempo, std::string l_musicFileName){
    m_notes = l_notes;
    m_tempo = l_tempo;
    m_musicFileName = l_musicFileName;
}

Sequence::~Sequence(){ }

Notes Sequence::GetNotes() {
    return m_notes;
}

void Sequence::TickNotes() {
    for (int x = 0; x < m_notes.size(); x += 1) {
        m_notes[x].Tick();
    }
}

std::string Sequence::GetMusicFileName() {
    return m_musicFileName;
}

// TODO: move startingPos and yBaseline into dynamic config %s

void Sequence::SetSequencePosition(int l_index) {
    // first bar is at 600, then we add sequenceOffset (so 2nd starts at 700)
    // this is assuming that each sequence will equal `1` in the % total, ie all `x`s added up won't surpass 1
    // meaning it's not possible to have 2 bar sequences right now
    int startingPos = 1700;
    int yBaseline = 1080;
    int barLength = m_tempo * 150; // base off tempo?
    int sequenceOffset = startingPos + l_index * barLength;
    float previousNoteLength = 0;
    // then notes are placed at % of barLength
    for (int i = 0; i < m_notes.size(); i += 1) {
        NoteData note = m_notes[i];
        sf::Vector2f pos = note.GetPosition();
        float x = sequenceOffset + previousNoteLength * barLength;
        previousNoteLength += pos.x;
        float y = yBaseline - pos.y * 100;
        note.SetPosition(sf::Vector2f(x, y));
        m_notes[i] = note;
    }
}