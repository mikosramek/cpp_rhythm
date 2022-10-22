#pragma once
#include "Room.h"

using Rooms = std::vector<Room>;

class Location
{
public:
    Location();
    ~Location();
    void GenerateNewRoomOrder();
protected:
    Rooms m_middleRooms;
    Rooms m_entryRooms;
    Rooms m_bossRooms;

    Rooms m_sequence;
};