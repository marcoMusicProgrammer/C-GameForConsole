#include <iostream>
#include <string>
#include "game.h"
#include "main.h"

using namespace std;

extern Level Level1;
extern player giocatore1;

Game::Game(string nameGame)
{
    name = nameGame;
}

Game::~Game()
{
}

void Game::addRoom(Room o)
{
    rooms.push_back(o);
}

void Game::seeRoom(int i)
{
    for (int i = 0; i < rooms.size(); i++)
    {
        cout << i << " - " << rooms[i].getName() << endl;
        cout << rooms[i].getDescription() << endl;
        cout << rooms[i].getPosition() << endl;
    }
}

int Game::pointerRoom(int i)
{

    currentRoom = i;

    return this->currentRoom;
}

void Game::currentPosition(int currentRoom)
{
    cout << "\n Actual Room: " << rooms[currentRoom].getName() << "\n"
         << endl;

    if (currentRoom == 1)
    {
        cout << "East  = \n";
        cout << "South = " << rooms[0].getName() << "\n"
             << rooms[0].getDescription() << endl;
        cout << "West  = \n";
    }
    else if (currentRoom == 2)
    {
        cout << "North = \n";
        cout << "East  = \n";
        cout << "South = \n";
        cout << "West  = " << rooms[0].getName() << endl;
    }
    else if (currentRoom == 3)
    {
        cout << "North = " << rooms[0].getName() << endl;
        cout << "East  = If i see to that position i see the great wall of Nora...\n";
        cout << "South = \n";
        cout << "West  = \n";
    }
    else if (currentRoom == 4)
    {
        cout << "North = \n";
        cout << "East  = " << rooms[0].getName() << endl;
        cout << "South = If i see to that position i see the great wall of Nora...";
        cout << "West  = \n";
    }
    else
    {
        cout << "I don't know where i am, i have to trust only to my senses! \n";
    }
}

void Game::moveHouse(int &currentRoom)
{
    if (currentRoom == 1)
    {
        currentRoom = 0;

        cout << "Current Room: " << rooms[0].getName() << endl;
        cout << rooms[0].getDescription() << endl;
    }
}

void Game::moveNorth(int &currentRoom)
{
    if (currentRoom == 0)
    {
        currentRoom = 1;

        cout << "Current Room: " << rooms[1].getName() << endl;
        cout << rooms[1].getDescription() << endl;
    }
    else if (currentRoom == 3)
    {
        currentRoom = 0;

        cout << "Current Room: " << rooms[0].getName() << endl;
        cout << rooms[0].getDescription() << "\n"
             << endl;
    }
    else
    {
        cout << "You can't move from that position.\n";
    }
}

void Game::moveEast(int &currentRoom)
{
    if (currentRoom == 0)
    {
        currentRoom = 2;

        cout << "Current Room: " << rooms[2].getName() << endl;
        cout << rooms[2].getDescription() << endl;
    }

    else if (currentRoom == 4)
    {
        currentRoom = 0;

        cout << "Current Room: " << rooms[0].getName() << endl;
        cout << rooms[0].getDescription() << endl;
    }

    else
    {
        cout << "You can't go to East from that position!\n";
    }
}

void Game::moveSouth(int &currentRoom)
{
    if (currentRoom == 0)
    {
        currentRoom = 3;

        cout << "Current Room: " << rooms[3].getName() << endl;
        cout << rooms[3].getDescription() << endl;
    }

    else if (currentRoom == 1)
    {
        currentRoom = 0;

        cout << "Current Room: " << rooms[0].getName() << endl;
        cout << rooms[0].getDescription() << endl;
    }

    else
    {
        cout << "You can't go to South from that position!\n";
    }
}

void Game::moveWest(int &currentRoom)
{
    if (currentRoom == 0)
    {
        currentRoom = 4;

        cout << "Current Room: " << rooms[4].getName() << endl;
        cout << rooms[4].getDescription() << endl;
    }

    else if (currentRoom == 2)
    {
        currentRoom = 0;

        cout << "Current Room: " << rooms[0].getName() << endl;
        cout << rooms[0].getDescription() << endl;
    }

    else
    {
        cout << "You can't go to South from that position!\n";
    }
}

void Game::moveCastle(bool &quest5_complete)
{
    if(quest5_complete == true)
    {
        currentRoom = 5;

        if(currentRoom == 5)
        {
            cout << "Current Room: " << rooms[5].getName() << endl;
            cout << rooms[5].getDescription() << endl;
        }
    }
}

void Game::addNpc(npc o)
{
    Npc.push_back(o);
}

void Game::npcQuest(int number_quest, bool &first_time_reward, bool &first_time_blacksmith)
{

    switch (number_quest)
    {
    case 0:    
                            // Interazione 1
        print = "<Hi i'm "; 
        slide(print);
        cout << Npc[0].getName();
        print = " can you help me?>\n<I was here to take some fishes but my fishing rod is disappeared...>\n\n<if you can help me, I can reward you with something interesting...>\n";
        slide(print);
        Level1.addQuest(quest("A guy named Gary, has stopped you asking your help, find his fishing rod!"));
        break;
    case 1:

        if (first_time_reward == true) // Interazione 2
        {
            print = "<Hey ";
            slide(print);
            cout << giocatore1.getName();
            print = " i see that you have find my fishing rod, thanks for that.>\n<As a reward a i can give you my second fishing rod, i bet that you will found out very usefull!>\n\n";
            slide(print);
        }
        else if (first_time_reward == false)
        {
            print = "<Hi ";
            slide(print);
            cout << giocatore1.getName();
            print = " how it's going your journey?>\n\n";
            slide(print);
        }
        break;
    case 2:

        print = "In front of the table of the quests, you're scrolling the pages to look for the right quests...\nOne in specific caught your attention...\n\n";
        slide(print);
        print = "*It is written: <One of the most dangerous enemy of Nora is still living in our deepest seas, if you are the chosen one, we will give you the chance to obtain something special for it!\n\nBring the creature to the Brook Inn's at Capital City, speak with the master!\n\n";
        slide(print);

        Level1.addQuest(quest("You have found a flyer where it's written on it that you have to bring the King of Nora to obtain something..."));

        break;
    case 3:

        print = "Hey ";
        slide(print);
        cout << giocatore1.getName();

        print = " finally we can meet... I know who you are, I'm here to warn you on the recent events, the veil of darkness are full, is coming... take this, when will be the right moment, you will know...\n\n";
        slide(print);

        break;
    case 4:

        print = "Welcome at the Brook Inn, I'm the master, I believe you need something...\nUh... what are you saying... Have ";
        slide(print);

        giocatore1.getName();

        print = "... have you something for me?\n\n";
        slide(print);

        giocatore1.removeItem(4);

        print = "WOW! you have caught the King of Nora... Seems passed decades from the lastthat was able to do it...\n\nWell... you have completed my quest, I think that I have to give you something.. what do you need?\n\n";
        slide(print);
        print = "Are you saying that you want go to the castle? I don't know how but i can say that the road is at south/west from here...\nYou have to go through the Inner Path, but keep attention... In the last time strange rumors came from people...\n\n";
        slide(print);

        giocatore1.addItem(item("Rope","A long rope, seems very tough, with these i can climb to the south...",1,50),5);
        break;
    case 5:

        Level1.addQuest(quest("Speak with Bea, the ghost appeard in the Inner Path"));

        print = "<Hi ";
        slide(print);
        giocatore1.getName();

        print = "finally we can meet, I'm Bea... i represent all the souls here...\nWe need you, we need a hero... someone that can stops the thin wave of blood and hate, something of unknown by our people it's happening..>\n\n";
        slide(print);

        print = "<There's nothing to do for some of us... I lived in peace in a no-distant house from Nora... but without any noticed someone has trapped me and now i'm not in this world anymore...>\n\n";
        slide(print);

        print = "<I know that you are the chosen one, please hurry up, go to the castle and save the reign... we need you!\nPlease take this item, you will get the chance to go to south and then to open the door for the castle...>\n\n";
        slide(print);

        giocatore1.addItem(item("The Ring of the Souls","At first can seems only a common ring, but when you touch it seems that spread a lot of energy...",1,10000),6);
        break;

    case 6:

        print = "Hi ";
        slide(print);
        giocatore1.getName();

        print = "I was waiting for you... I have the mission to bring you at the court to start the preparation... but first you have to meet the blacksmith, you need an armor!\n\n";
        slide(print);

        print = "Take this, is an order for the blacksmith...\nUnless this he will not do anything for you...\n\n";
        slide(print);

        giocatore1.addItem(item("Armor License","A license directly from the Royal Family for the armor...",1,1000),7);

        Level1.addQuest(quest("You meet Rex, one of the most important guard of the court... He said that to go to the castle you have to ask at the blacksmith your first armor..."));

        break;
    case 7:
        if(first_time_blacksmith == true)
        {
            print = "Hi... I don't wanna know your name... I'm working hard right now... I'm not wasting time with novice!";
            slide(print);

            giocatore1.removeItem(7);

            print = "Huh... what is this?\n...\nA license from the royal family for an armor...\nWell, so you're one of the chosen for the nex expedition...\n\n";
            slide(print);

            print = "I'm sorry for you... out there there are things that no one has never seen... But don't be afraid... My armors are the more resistent of the reign, they can protect you from everything!\n\n";
            slide(print);

            print = "Before to start you have to give me something special, to enfuse to instil the power...\n\n";
            slide(print);

            giocatore1.removeItem(6);

            print = "This ring is perfect, spread a lot of energy... I never seen a things like that...";
            slide(print);

            giocatore1.addItem(item("Armor of the soul","Like the ring, this armor spread a lot of energy",1,50000),6);

            print = "It was funny do it... but now i have finished, please go away of my road!\n\n";
            slide(print);

            first_time_blacksmith = false;
        }
        else if (first_time_blacksmith == false)
        {
            print = "Still here, go away!\n\n";
            slide(print);
        }



        break;

    default:
        break;
    }
}
