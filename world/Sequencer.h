#pragma once
// #include "Location.h"
#include "Castle.h"

enum LocationName {
    castle
};

class Sequencer
{
public:
    Sequencer();
    ~Sequencer();
    void GenerateNextSequence();
    void Render(sf::RenderWindow& l_window);
    void ChooseLocation(LocationName l_location);
    void Tick();
private:
    Castle m_castle;
    Location m_currentLocation;
};


// each enemy / place will have its own vector of NoteData
// this class will have references to each?
// and will combine the other classes' vectors into its own vector

// future consideration:
// making it so that each sequence belongs to a biome of sorts, these biomes have base sequences + enemy patterns and such
// can also contain spawning patterns
