#pragma once
#ifndef player_h
#define player_h
#include "item.h"
#include "room.h"
#include <vector>


using namespace std;


class player
{
private:
    string name;
    float maxWeigh;
    int currentRoom;
    vector<item> inventory;
   


public:
    player(string nome, int weigh);
    ~player();

    string getName();
    void addItem(item o, int index);
    void removeItem(int index);
    void editItem(int index,item o);
    void seeInventory(int i);
};




#endif