#pragma once
#include "NoteData.h"

using Notes = std::vector<NoteData>;

class Sequence
{
public:
    Sequence(Notes l_notes, int l_tempo, std::string l_musicFileName);
    Sequence();
    ~Sequence();
    Notes GetNotes();
    std::string GetMusicFileName();
private:
    Notes m_notes;
    int m_tempo;
    std::string m_musicFileName;
};
