#pragma once
#include "NoteSequence.h"

using SequenceMap = std::vector<NoteSequence>;

class Sequencer
{
public:
    Sequencer();
    ~Sequencer();
    void GenerateNextSequence();
    NoteSequence GetCurrentSequence();
private:
    SequenceMap m_possibleSequences;
    SequenceMap m_sequenceMap;
};
