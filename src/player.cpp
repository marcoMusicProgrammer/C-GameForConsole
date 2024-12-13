#include <iostream>
#include <string>
#include "player.h"
#include "game.h"

extern RtAudio audio;
extern pd::PdBase lpd;
extern PdObject pdObject;



using namespace std;

extern player giocatore1;

player::player(string nome, int weigh)
{
    name = nome;
    maxWeigh = weigh;
}

player::~player()
{
}

string player::getName()
{
    return this->name;
}


void player::addItem(item o, int index)
{
    lpd.sendBang("addInventory");
    inventory.push_back(o);
    cout << inventory[index].getName() << " added to your inventory\n" << endl;
    
}

void player::removeItem(int index)
{

    cout << giocatore1.getName() << "remove " << inventory[index].getName() << " from his inventory.\n\n";
    inventory.erase(inventory.begin()+index);


}

void player::editItem(int index, item o)
{
    inventory[index] = o;
}

void player::seeInventory(int i)
{
    for(int i=0;i< inventory.size();i++)
    {
        cout << i << ". " << endl;
        cout << inventory[i].getName() << endl;
        cout << inventory[i].getDescription() << endl;
        cout << inventory[i].getQuantity() << endl;
        cout << inventory[i].getPrice() << endl;
    }
}