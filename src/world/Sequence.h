#pragma once
#include "NoteData.h"
#include "../utils/Debug.h"

using Notes = std::vector<NoteData>;

class Sequence
{
public:
    Sequence(Notes l_notes, int l_tempo, std::string l_musicFileName);
    Sequence();
    ~Sequence();
    Notes GetNotes();
    std::string GetMusicFileName();
    void SetSequencePosition(int l_index);
    bool IsNull();
private:
    Notes m_notes;
    int m_tempo;
    std::string m_musicFileName;
    Debug m_debug;
    bool m_null;
};
