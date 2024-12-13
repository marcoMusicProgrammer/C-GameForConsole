#include <iostream>
#include "misclib.h"
#include "level.h"
#include "game.h"
#include "PdBase.hpp"
#include "RtAudio.h"
#include "PdObject.h"
#include "player.h"
#include "item.h"
#include <chrono>
#include <thread>


extern int currentRoom;
extern int currentLevel;
extern int house_choice;
extern bool first_time_castle;
extern bool first_time_start;
extern bool quest5_complete;
extern bool castle;
extern bool complete_forge;
extern bool start_music_home;
extern bool start_music_mainpage;
extern bool quest1_complete;
extern bool potrait;
extern bool complete_house;
extern bool inside_house;
extern bool main_house;
extern bool text_house;
extern bool keyPlayer;
extern bool pass;
extern bool start;
extern bool start1;
extern bool start2;
extern bool exitGame;
extern bool fine;
extern bool fine2;
extern bool bang;
extern bool bang_square;
extern bool next1;
extern bool quest_house1;
extern bool quest_house2;
extern bool quest_house3;
extern bool quest_house4;
extern bool bed;
extern bool diary;
extern char direction;
extern char house1;
extern string name;
extern string print;
extern int caso;

extern pd::PdBase lpd;
extern PdObject pdObject;
extern player giocatore1;
extern Game Game1;
extern potion potion1;
extern Level Level1;

using namespace std;

void slide(string& print) 
{

    for (const char& c: print)
    {
	    cout << c;
	    cout.flush();
	    this_thread::sleep_for(chrono::milliseconds(1));
    };
};

void menù1()
{
    cout << "#######################################################\n";
    cout << "#######################################################\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    print = "                        WELCOME\n";
    slide(print);
    cout << "\n";
    print = "            Programmed and Sound Designed by\n";
    slide(print);
    print = "           Marco Maisto and Matteo Androvetto\n";
    slide(print);
    print = "                Music by Matteo Carlucci\n";
    slide(print);
    cout << "\n";
    cout << "\n";
    print =  "                   PROJECT SISTEMI 2\n";
    slide(print);
    print = "                      2022/2023\n";
    slide(print);
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "#######################################################\n";
    cout << "#######################################################\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";

    start_music_mainpage = true;
    start = false;
    start1 = false;
    start2 = false;
    fine = false;
    fine2 = false;
    pass = false;
}

void menù2()   // INSERIRE MUSICA PRINCIPALE
{

    if(complete_forge == false)
    {
        if(start_music_mainpage == true)
        {
        pd::List menu;
        menu << 0 << 0 << 1 << 100;
        lpd.sendMessage("cpp", "play", menu);
        }
        
        print = "               THE ADVENTURES OF ESMUPACHIA   \n";
        slide(print);

        cout << "\n";
        print = "                   1. Start The Game\n";
        slide(print);
        print = "                   2. Exit the Game\n";
        slide(print);\
        print = "                   3.   Credits\n";
        slide(print);
        cout << "\n";                                                         

        cin >> caso;

        switch (caso)
        {
        case 1:

            lpd.sendBang("bangMenu");
            start = false;
            start1 = false;
            start2 = false;
            castle = false;
            start_music_mainpage = false;
            start_music_home = true;



            break;

        case 2:

            lpd.sendBang("bangMenu");
            cout << "Bye Bye!\n";

            exitGame = true;
            start = true;
            start1 = true;
            start2 = true;
            fine = true;
            pass = true;
            start_music_mainpage = false;

            break;

        case 3:

            lpd.sendBang("bangMenu");
            cout << "           This game was created by humans!\n";
            cout << "\n";
            start = false;
            start1 = true;
            start_music_mainpage = false;

            break;
        
        default:
            cout << "Try Again!\n";
            start_music_mainpage = false;
            
            break;
        }
    }
    else if (complete_forge == true)
    {
        if(start_music_mainpage == true)
        {
        pd::List menu;
        menu << 0 << 0 << 1 << 100;
        lpd.sendMessage("cpp", "play", menu);
        }
        
        print = "               THE ADVENTURES OF ESMUPACHIA   \n";
        slide(print);

        cout << "\n";
        print = "                   1. Start The Game\n";
        slide(print);
        print = "                   2. Exit the Game\n";
        slide(print);\
        print = "                   3.   Credits\n";
        slide(print);
        print = "                 4.  Go to the Castle\n";
        slide(print);
        cout << "\n";                                                         

        cin >> caso;

        switch (caso)
        {
        case 1:


                lpd.sendBang("bangMenu");
                start = false;
                start1 = false;
                start2 = false;
                start_music_mainpage = false;


                

                //first_time_start = false;
            
/*             else if (first_time_start == false)
            {
                lpd.sendBang("bangMenu");
                start = false;
                start1 = false;
                start2 = false;
                start_music_mainpage = false;
            } */
            break;

        case 2:

            lpd.sendBang("bangMenu");
            cout << "Bye Bye!\n";

            exitGame = true;
            start = true;
            start1 = true;
            start2 = true;
            fine = true;
            pass = true;
            start_music_mainpage = false;

            break;

        case 3:

            lpd.sendBang("bangMenu");
            cout << "           This game was created by humans!\n";
            cout << "\n";
            start = false;
            start1 = true;
            start_music_mainpage = false;

            break;

        case 4:

            lpd.sendBang("bangMenu");

            Game1.moveCastle(quest5_complete);

            start = true;
            start2 = true;
            fine = false;
            fine2 = false;
            pass = false;
            castle = true;
            first_time_castle = true;


            break;
        
        default:
            cout << "Try Again!\n";
            start_music_mainpage = false;
            
            break;
        }
    }


}

void story() // MUSICA PRINCIPALE 
{
    print = "# The Beginning\n\n\n";
    slide(print);
    print = "Once upon a time there was a kingdome, where citizens lived peacefully and in harmony through each others.\n\n";
    slide(print);
    print = "One day, whithout any notice the world changed!\n\nOne of the most dangerous enemy appears breaking a long period of peace\n";
    slide(print);
    print = "This enemy started to take Nora's people and putting them in chains.\n\n";
    slide(print);
    print = "The kingdome, lead by the queen organized a fellowship to save Nora's people!\n";
    slide(print);
    print = "You are the one choosed for this journey!\n\n";
    slide(print);
    print = "It's time for you to move your first steps into this world...\n\n";
    slide(print);
    print = "What's your name?\n";
    slide(print);

    start2 = false;
    start1 = true;
    start  = true;

}

void the_beginning()
{
    
    currentLevel = 0;

    cin >> name;
    lpd.sendBang("bangMenu");
    cout << "\n";

    giocatore1 = player(name,20);

    cout << giocatore1.getName() << " please takes these items before starts the journey!\n";
    cout << "";

    cout << "\n";

    giocatore1.addItem(item("Health Potion","Restore Health points",3,1),0);
    giocatore1.addItem(item("Magicka Potion","Restore Magicka points",3,1),1);

    cout << "\n";
    cout << "\n";


    start2 = true;

    pd::List fadeMenu;
    fadeMenu << 0 << 0 << 6000;
    lpd.sendMessage("cpp","fadeout",fadeMenu);

    start_music_home = true;
}   

void starting_text () //MUSICA PRINCIPALE
{
    


}

void house (char direction, char house1, int house_choice)
{   
/*     keyPlayer;
    next1;

    
    while (next1 == false)
    {
        if (text_house == true)
        {
            print = "Looking around you, you noticed that you are living in a small house woods-made, in front of your bed there's a desk with old papers and a diary,\nlooking on the left you can see a box, that seems contain something.\n\n";
            slide(print);
            print = "Before to start you have to find some objects, these items are important for your journey!\n\n";
            slide(print);
            print = "Press a key between the <a> and the <z> to find out something!\n\n";
            slide(print);

            text_house = false;
        }
        if (text_house == false)
        {

            cin >> house1;

            switch (house1)
            {
                case 'd':
                if (keyPlayer == false && quest_house1 == false)
                {
                    print = "You try to open the door, but is locked... maybe there's a key...\n";
                    slide(print);
                }
                if (keyPlayer == true && quest_house1 == false)
                {
                
                    print = "You have found a key, finally the door will be opened!\n\n";
                    slide(print);

                    giocatore1.addItem(item("Door Key","The key to have access to your house",1,0),2);

                    quest_house1 = true;

                }
                else if (keyPlayer == true && quest_house1 == true)
                {
                    print = "you've already found the key, try other words to continue...\n";
                    slide(print);
                }
        
                break;
                case 'c':
                if(quest_house2 == false && potrait == false)
                {
                    print = "On the wall, next to the bed... a painting takes you attention... it seems like your potraits but with another person, but seem that you can't recognize him, very strange...\n";
                    slide(print);

                    potrait = true;
                    quest_house2 = true;
                }
                else if(quest_house2 == true && potrait == true)
                {
                    print = "The potrait seems familiar, but i cannot recognize the second person...\n";
                    slide(print);
                }
                break;
                case 'n':
                if(diary == false)
                {                    
                    print = "Loocking on the desk, you find a diary... seems old and used, in the front there's a strange draw and it's written <Quests>...\n";
                    slide(print);
                    //quest Quest1 = quest("Find a key");

                    print = "Now you can tracks your missions!\n";
                    slide(print);

                    diary = true;
                    quest_house3 = true;
                }
                else if (diary == true)
                {
                    print = "You've already found the diary, try other words to continue...\n";
                    slide(print);
                }
                break;

                case 'b':
                if(bed == false)
                {
                    print = "Somehing below the bed takes your attention, you bend down and find a key! <Maybe can i open the door now...>\n";
                    slide(print);

                    quest_house4 = true;
                    keyPlayer = true;
                }
                else if (keyPlayer == true)
                {
                    print = "Just watched here, go on to continue!\n";
                    slide(print);
                }
                break;
    
                default:
                    cout << "Looking around you see a Door, a Desk with a Notes above and something below the bed... try to type the first character of those!\n\n";
                break;
            }
            
        }
        if (quest_house1 == true && quest_house2 == true && quest_house3 == true && quest_house4 == true)
        {
            next1 = true;
        }

    }
    if (next1 == true)
    {
         print = "You'are going outside, at first you should know that there are three different direction, you have to unlock different ways compliting the quests!\n";
        slide(print); 
    }*/
}


