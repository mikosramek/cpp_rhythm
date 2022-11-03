#pragma once
#include "Location.h"
#include "NoteBar.h"
#include "../base/Window.h"
#include "../utils/Debug.h"

enum LocationName {
    castle
};

class Sequencer
{
public:
    Sequencer();
    Sequencer(sf::RenderWindow& l_window);
    ~Sequencer();
    void GenerateNextSequence();
    void Render(sf::RenderWindow& l_window);
    void ChooseLocation(LocationName l_location);
    void Tick();
    void CheckInput();
    void HandleEvents(sf::Event& event);
private:
    Location m_castleLocation;
    Location m_currentLocation;
    void InitLocations();
    int m_roomIndex;
    int m_noteIndex;

    void CheckHit();
    void HitNote();
    void MissedNote();
    
    Notes m_notes;
    NoteBar m_bar;

    Debug m_debug;

    bool m_spacePressed;
};


// each enemy / place will have its own vector of NoteData
// this class will have references to each?
// and will combine the other classes' vectors into its own vector

// future consideration:
// making it so that each sequence belongs to a biome of sorts, these biomes have base sequences + enemy patterns and such
// can also contain spawning patterns
