#include "NoteSequenceTemplate.h"

NoteSequenceTemplate::NoteSequenceTemplate() {
    // set tempo
    // IE how many seconds per whole sequence?
    m_tempo = 4; // 60 bpms
    // Notes
    // start position, and that's it
    // I 

    // starts at 500 px
    // every 50 pixels we generate a note (quarter)
    // 500 | 550 | 600 | 650 | 675 
    // set note position, then increment by note length
    // (currentPosition + note length (50 for quarter, 25 for 8th, etc))

    // so these sequences just need to assume we start at 0
    // ie we're only setting offets for each note from the beginning of the sequence, the sequencer will handle actually spawning them in?
    // these offsets can be in percentages? aka, 0.25 * sequence time (bpm)

    /*
        whole note   = 1.0
        half note    = 0.5
        quarter note = 0.25
        eigth note   = 1/8
        16th note    = 1/16
    */
    m_notes.push_back(NoteData(sf::Vector2f(0, 0)));
}

NoteSequenceTemplate::~NoteSequenceTemplate() {}

Notes NoteSequenceTemplate::GetNotes() {
    return m_notes;
}