#pragma once
#ifndef npc_h
#define npc_h


using namespace std;

class npc
{
private:

    string npc_name;
    string npc_description;
    string print;

public:
    npc(string name, string description);
    ~npc();



    string getName();
    string getDescription();

};




#endif