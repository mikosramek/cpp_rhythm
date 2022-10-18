#include "../Note.h"

using Notes = std::vector<Note>;

class NoteSequence
{
public:
    NoteSequence();
    ~NoteSequence();
    Notes GetNotes();
private:
    Notes m_notes;
};
