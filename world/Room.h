#include "Sequence.h"

using Sequences = std::vector<Sequence>;

class Room
{
public:
    Room(Sequences l_sequences);
    ~Room();
private:
    Sequence m_background;
    Sequence m_positionOne;
    Sequence m_positionTwo;
    Sequence m_positionThree;
};
