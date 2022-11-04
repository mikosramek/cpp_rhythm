#pragma once
#include <iostream>
#include <map>
#include "Room.h"
#include "../utils/JSONLoader.h"

using Rooms = std::vector<Room>;

class Location
{
public:
    Location();
    Location(std::string configFilePath);
    ~Location();
    void GenerateNewRoomOrder();
    Notes GetNextRoomsNotes(int l_roomIndex);
protected:
    Rooms m_middleRooms;
    Rooms m_entryRooms;
    Rooms m_bossRooms;

    Rooms m_rooms;
    int m_roomIndex;
    JSONLoader loader;
    std::map<std::string, json> m_map;
    Rooms GetRoomsFromData(std::string roomType);
    json m_data;
    int m_tempo;
};