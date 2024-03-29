#include "NoteData.h"

using Notes = std::vector<NoteData>;

/*generationwarning*/
class NoteSequenceTemplate
{
public:
    NoteSequenceTemplate();
    ~NoteSequenceTemplate();
    Notes GetNotes();
    std::string GetMusicFileName();
private:
    Notes m_notes;
    int m_tempo;
    std::string m_musicFileName;
};
