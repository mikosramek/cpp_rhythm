#include "Sequence.h"
#include "../utils/Debug.h"

using Sequences = std::vector<Sequence>;

class Room
{
public:
    Room(Sequences l_sequences);
    ~Room();
    void RenderNotes(sf::RenderWindow& l_window);
    void Tick();
private:
    Sequence m_background;
    Sequence m_positionOne;
    Sequence m_positionTwo;
    Sequence m_positionThree;
    Sequences m_roomSong;
    Notes m_roomNotes;
    Debug m_debug;
};
