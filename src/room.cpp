#include <iostream>
#include "room.h"
#include <string>

using namespace std;


Room::Room(string name, string description, int position)
{
    name_room = name;
    room_description = description;
    room_position = position;
}

Room::~Room()
{

}

string Room::getName()
{
    return this->name_room;
}

string Room::getDescription()
{

    cout << " Description: ";
    return this->room_description;
}

int Room::getPosition()
{
    cout << " Position: ";
    return this->room_position;
}

