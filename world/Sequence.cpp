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

std::string Sequence::GetMusicFileName() {
    return m_musicFileName;
}
