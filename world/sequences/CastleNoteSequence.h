#include "NoteData.h"

using Notes = std::vector<NoteData>;


// AUTOGENERATED FILE
// DO NOTE EDIT
// UPDATE compilers/SequencesCompiler/Sequences AND RUN "make sequences-(debug|release)"
class CastleNoteSequence
{
public:
    CastleNoteSequence();
    ~CastleNoteSequence();
    Notes GetNotes();
    std::string GetMusicFileName();
private:
    Notes m_notes;
    int m_tempo;
    std::string m_musicFileName;
};