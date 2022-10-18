#include "NoteData.h"

using Notes = std::vector<NoteData>;

class NoteSequenceTemplate
{
public:
    NoteSequenceTemplate();
    ~NoteSequenceTemplate();
    Notes GetNotes();
private:
    Notes m_notes;
    int m_tempo;
};
