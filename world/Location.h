#pragma once
#include "Room.h"
#include <iostream>

using Rooms = std::vector<Room>;

class Location
{
public:
    Location();
    ~Location();
    void GenerateNewRoomOrder();
    void Render(sf::RenderWindow& l_window);
    void Tick();
protected:
    Rooms m_middleRooms;
    Rooms m_entryRooms;
    Rooms m_bossRooms;

    Rooms m_sequence;
    int m_roomIndex;
};