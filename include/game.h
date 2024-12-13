#pragma once
#ifndef game_h
#define game_h
#include <vector>
#include "room.h"
#include "npc.h"
#include "main.h"

using namespace std;


class Game
{
private:

    
    string name;
    string print;
    int currentRoom;
    int number_quest;
    int number_npc;
    bool complete_woods;
    bool first_time_reward;
    bool first_time_blacksmith;
    bool quest5_complete;
    //int currentLevel;
    vector<Room> rooms;
    vector<npc> Npc;
    
public:
    Game(string name);
    ~Game();

    void addRoom(Room o);
    void seeRoom(int i);
    int pointerRoom(int i);
    void currentPosition(int currentRoom);
    void moveHouse(int &currentRoom);
    void moveNorth(int &currentRoom);
    void moveEast(int &currentRoom);
    void moveSouth(int &currentRoom);
    void moveWest(int &currentRoom);
    void moveCastle(bool &quest5_complete);

    void addNpc(npc o);
    void npcQuest(int number_quest,bool &first_time_reward,bool &first_time_blacksmith);

};




#endif