#include "Sequence.h"
#include "../utils/Debug.h"

using Sequences = std::vector<Sequence>;

class Room
{
public:
    Room(Sequences l_sequences, int l_roomLength);
    ~Room();
    Notes GetNotes();
private:
    Sequence m_background;
    Sequence m_positionOne;
    Sequence m_positionTwo;
    Sequence m_positionThree;
    Sequences m_roomSong;

    Debug m_debug;
    int m_roomLength;
    void GenerateFourSequenceSong();
    void GenerateThreeSequenceSong();
    void GenerateTwoSequenceSong();
    void GenerateOneSequenceSong();
};
