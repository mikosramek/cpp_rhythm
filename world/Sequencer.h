#pragma once
#include "sequences/NoteData.h"
#include "sequences/CastleNoteSequence.h"
#include "sequences/Enemy1NoteSequence.h"

using SequenceMap = std::vector<NoteData>;

class Sequencer
{
public:
    Sequencer();
    ~Sequencer();
    void GenerateNextSequence();
    SequenceMap GetCurrentSequence();
private:
    SequenceMap m_possibleSequences;
    SequenceMap m_sequenceMap;
};


// each enemy / place will have its own vector of NoteData
// this class will have references to each?
// and will combine the other classes' vectors into its own vector

// future consideration:
// making it so that each sequence belongs to a biome of sorts, these biomes have base sequences + enemy patterns and such
// can also contain spawning patterns
