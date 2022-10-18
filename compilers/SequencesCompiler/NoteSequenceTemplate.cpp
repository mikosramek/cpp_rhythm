#include "NoteSequenceTemplate.h"

/*generationwarning*/
NoteSequenceTemplate::NoteSequenceTemplate() {
    /*musicFileName*/
    /*tempo*/ //  a tempo of 4 = 60 bpms

    // offsets are in percentages of bar size
    /*
        whole note   = 1.0
        half note    = 0.5
        quarter note = 0.25
        eigth note   = 1/8
        16th note    = 1/16
    */
    // m_notes.push_back(NoteData(sf::Vector2f(length, row)));
/*notes*/
}

NoteSequenceTemplate::~NoteSequenceTemplate() {}

std::string NoteSequenceTemplate::GetMusicFileName() {
    return m_musicFileName;
}

Notes NoteSequenceTemplate::GetNotes() {
    return m_notes;
}