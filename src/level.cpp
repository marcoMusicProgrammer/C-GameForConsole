#include <iostream>
#include <string>
#include "level.h"

using namespace std;



Level::Level(string l, string d, int n)
{
    nameLevel   = l;
    descriptionLevel = d;
    numberLevel = n;
    Quest1 = new quest ("numero 1");
}

Level::~Level()
{
}

string Level::getNameLevel()
{
    return this->nameLevel;
}

int Level::getNumber()
{
    return this->numberLevel;
}

string Level::getDescription()
{
    return this->descriptionLevel;
}

void Level::addQuest(quest o)
{
    Quests.push_back(o);
}

void Level::seeQuest(int i)
{
    for (int i=0; i<Quests.size();i++)
    {
        cout << i << " - " << Quests[i].getName() << endl;
    }
}

void Level::getComplete(bool &quest1_complete,bool &quest2_complete,bool &quest3_complete,bool &quest4_complete,bool &quest5_complete, int i)
{
    switch (i)
    {
    case 0:
        if(quest1_complete == true)
        {
            cout << "1 - [completed] ";
            cout << Quests[i].getName() << endl;

        }
        else if(quest1_complete == false)
        {
            cout << "1 - [active] ";
            cout << Quests[i].getName() << endl;
        }
        break;
    case 1:
        if(quest2_complete == true)
        {
            cout << "2 - [completed] ";
            cout << Quests[i].getName() << endl;

        }
        else if(quest2_complete == false)
        {
            cout << "2 - [active] ";
            cout << Quests[i].getName() << endl;
        }
        break;
    case 2:
        if(quest3_complete == true)
        {
            cout << "3 - [completed] ";
            cout << Quests[i].getName() << endl;

        }
        else if(quest3_complete == false)
        {
            cout << "3 - [active] ";
            cout << Quests[i].getName() << endl;
        }

        break;  
    case 3:

        if(quest4_complete == true)
        {
            cout << "4 - [completed] ";
            cout << Quests[i].getName() << endl;

        }
        else if(quest4_complete == false)
        {
            cout << "4 - [active] ";
            cout << Quests[i].getName() << endl;
        }

        break;
    case 4:

        if(quest5_complete == true)
        {
            cout << "5 - [completed] ";
            cout << Quests[i].getName() << endl;

        }
        else if(quest5_complete == false)
        {
            cout << "5 - [active] ";
            cout << Quests[i].getName() << endl;
        }

        break;
    default:
        break;
    }

    

    


    

}



quest::quest(const string &nome_quest)
{
    questName = nome_quest;

}

quest::~quest()
{

}

string quest::getName()
{
        return this->questName;
}


