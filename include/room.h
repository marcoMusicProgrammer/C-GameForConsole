#pragma once
#ifndef room_h
#define room_h

using namespace std;


class Room
{
private:

    string name_room;
    string room_description;
    int room_position;
    // vector[Npc]npc_people;
    // vector<Object>object_room;

    

public:
    Room(string name_room, string room_description,int room_position);
    ~Room();

    string getName();
    string getDescription();
    int getPosition();

};



#endif