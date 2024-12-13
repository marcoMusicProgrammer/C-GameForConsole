#pragma once
#ifndef level_h
#define level_h
#include <vector>

using namespace std;

class quest;

class Level
{
private:

public:
    Level(string l, string d, int n);
    ~Level();

    vector<quest> Quests;

    quest *Quest1;
    string nameLevel;
    string descriptionLevel;
    int numberLevel;
    string story;

    string getNameLevel();
    string getDescription();
    int getNumber();

    bool quest1_complete;
    bool quest2_complete;
    bool quest3_complete;
    bool quest4_complete;
    bool quest5_complete;
    bool completed;
    
    void addQuest(quest o);
    void seeQuest(int i);
    void getComplete(bool &quest1_complete,bool &quest2_complete,bool &quest3_complete,bool &quest4_complete,bool &quest5_complete, int i);
    

};

class quest 
{
public:

    quest(const string &nome_quest);
    ~quest();

    string questName;

    string getName();


};








#endif