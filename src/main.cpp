#include "main.h"

using namespace std;

// VARIABILI GLOBALI //c b n d

string startGame;
string name;
string print;
int number_quest;
int caso;
float maxWeigh;
char direction;
char house1;
//char c;
int diary_story;
int choice;
int choice2;
int code;
int house_choice;
int npc1_quest;
bool first_time_start = true;
bool first_time_story = true;
bool first_time_beginning = true;
bool first_time_castle = false;
bool first_time_init = true;
bool castle = false;
bool first_time_blacksmith_forge = true;
bool first_time_blacksmith = true;
bool first_time_forge = true;
bool first_time_complete_market = true;
bool first_time_store = false;
bool first_time_path = true;
bool quest_taked_market = false;
bool mistery_guy_complete = false;
bool first_time_walking_market = true;
bool first_time_market = true;
bool completed1 = false;
bool completed = false;
bool first_time_reward = true;
bool first_time_guy = true;
bool fishing_rod = false;
bool first_time_house_story = true;
bool complete_forge = false; //modificato
bool complete_woods = false; //modificato
bool complete_market = false; //modificato
bool complete_path = false; //modificato
bool first_time_woods = true;
bool first_time_diary = true;
bool first_time_house = true;
bool quest5_complete = false; //modificato x castello
bool quest4_complete = false; //modificato x castello
bool quest3_complete = false; //modificato x castello
bool quest2_complete = false; //modificato
bool quest1_complete = true;
bool potrait = false;
bool main_house = false;
bool inside_house = true;
bool complete_house = false;
bool text_house = true;
bool keyPlayer = false;
bool exitGame;
bool start;
bool start1;
bool start2;
bool fine = false;
bool fine2 = false;
bool pass = false;
bool play = false;
bool bang;
bool start_music_home;
bool start_music_woods;
bool start_music_forge;
bool start_music_path;
bool start_music_market;
bool start_music_mainpage;
bool next1 = false;
bool quest_house1 = false;
bool quest_house2 = false;
bool quest_house3 = false;
bool quest_house4 = false;
bool bed = false;
bool diary = false;
int currentRoom;
int currentLevel;

// CLASSI

Game Game1 = Game ("Esmupachia");
player giocatore1 = player (name,20);
Level Level1 = Level ("begnning","Where all begins",0);
//npc Npc1 = npc ("Gary","Seems young, wear a red shirt and blue jeans");


// PD CLASSES 

RtAudio audio;
pd::PdBase lpd;
PdObject pdObject;

int audioCallback(void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
   double streamTime, RtAudioStreamStatus status, void *userData) 
{

   // pass audio samples to/from libpd
   int ticks = nBufferFrames / libpd_blocksize();
   lpd.processFloat(ticks, (float *)inputBuffer, (float *)outputBuffer);

   return 0;
}

void init() 
{
   unsigned int sampleRate = 48000;
   unsigned int bufferFrames = 128;

   // init pd
   if(!lpd.init(0, 2, sampleRate, true)) {
      std::cerr << "Could not init pd" << std::endl;
      exit(1);
   }

   // receive messages from pd
   lpd.setReceiver(&pdObject);
   lpd.subscribe("cursor");

   // send DSP 1 message to pd
   lpd.computeAudio(true);

   // load the patch
   pd::Patch patch = lpd.openPatch("Looper_Rework.pd", "./pd");
   pd::Patch patch2 = lpd.openPatch("fx.pd", "./pd");
   //pd::Patch patch2 = lpd.openPatch("fx_marco.pd", "./pd");
   std::cout << patch << std::endl;
   std::cout << patch2 << std::endl;

   // use the RtAudio API to connect to the default audio device
   if(audio.getDeviceCount() == 0) {
      std::cout << "There are no available sound devices" << std::endl;
      exit(1);
   }

   RtAudio::StreamParameters parameters;
   parameters.deviceId = audio.getDefaultOutputDevice();
   parameters.nChannels = 2;

   RtAudio::StreamOptions options;
   options.streamName = "libpd rtaudio test";
   options.flags = RTAUDIO_SCHEDULE_REALTIME;
   if(audio.getCurrentApi() != RtAudio::MACOSX_CORE) {
      options.flags |= RTAUDIO_MINIMIZE_LATENCY; // CoreAudio doesn't seem to like this
   }
   try {
      audio.openStream( &parameters, NULL, RTAUDIO_FLOAT32, sampleRate,
         &bufferFrames, &audioCallback, NULL, &options );
      audio.startStream();
   }
   catch(RtAudioError &e) {
      std::cerr << e.getMessage() << std::endl;
      exit(1);
   }
}

// INFO: Tutte le funzioni sono state trasferite nel file misclin.cpp.
// Nel file misclib.cpp dovranno essere dichiarate tutte le variabili con il suffisso "extern".

// VOID MENU1
// VOID MENU2
// VOID STORY
// VOID THE BEGINNING
// VOID STARTING TEXT - MUSICA PRINCIPALE
// VOID STARTING

void inThePlaces(int choice, int choice2,char direction, char house1, int house_choice)
{
    if(currentRoom == 0)
    {

        quest1_complete = true;

        if(start_music_home == true) // Funzione trigger audio
        {

            pd::List fadeMenu;
            fadeMenu << 0 << 0 << 6000;
            lpd.sendMessage("cpp","fadeout",fadeMenu);


            pd::List casa;
            casa << 1 << 0 << 1 << 6000;
            lpd.sendMessage("cpp", "play", casa);

        }

        if(first_time_house_story == true)
        {
            print = "- CHAPTER I -------------------------------------------------\n";
            slide(print);
            cout << "\n";
            print = "*TOC TOC*\n";
            slide(print);
            cout << "\n";
            print = "You wake up after hearing someone knocking on the door...\n";
            slide(print);
            print = "An emissary delivers you a message from the royal family.\n";
            slide(print);
            cout << "\n";
            print = " *The day has come, the most heroic warriors of Nora have been called* \n";
            slide(print);
            print = " *Find the road to the castle, your journey has just begun.\n";
            slide(print);
            cout << "\n";
            
            print = "You take your first quest. It consist in finding all the items to start your journey at your house!\n";
            slide(print);


            Level1.addQuest(quest("Find the first items"));

            first_time_house_story = false;
        }

            keyPlayer;
            next1;

    
        while (next1 == false)
        {
            if(text_house == true)
            {
                print = "*Looking around, you noticed that you live in a small house woods-made, in front of your bed there's a desk with old papers and a diary\n\n";
                slide(print);
                print = "Before to start you have to find some objects, these items are important for your journey!\n\n";
                slide(print);
                print = "Try to type a key between the <a> and the <z> to find out something!\n\n";
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
                
                            print = "You have found a key, finally the door can be opened!\n\n";
                            slide(print);

                            lpd.sendBang("addInventory_key");
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
                            lpd.sendBang("bangDiary");
                            print = "Looking on the desk, you find a diary... seems old and used, in the front there's a strange draw and it's written <Quests>...\n";
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
                            lpd.sendBang("bangKey");
                            print = "Somehing below the bed takes your attention, you bend down and find a key! <Maybe I can open the door now...>\n";
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
                        cout << "Looking around, you can see a Door, a Notes above a desk and something below the bed... On the wall you can also see a strange Potrait... try to type the first character of those to know more!\n\n";
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
/*         print = "You'are going outside, at first you should know that there are three different direction, you have to unlock different ways compliting the quests!\n";
            slide(print); */

            cout << "\n";
            print = "You are now at your house, this is what you can do: \n\n";
            slide(print);
            print = "1 - Open the door\n2 - Open your inventory\n3 - Open your diary\n4 - Back to Menù\n\n";
            slide(print);

            cin >> choice;
            cout << "\n";

           while(choice != 1 && choice != 2 && choice != 3 && choice != 4)
            {
                print = "Wrong choice, try again...\n";
                slide(print);
                cin >> choice;
            }
            if (choice == 1) // DIREZIONI
            {
                lpd.sendBang("bangDoor");
                
                pd::List forest;
                forest << 7 << 0 << 1.5 << 2000;
                lpd.sendMessage("cpp", "play", forest);

                if(first_time_house == true)
                {
                    print = "*DOOR IS OPENING\n\nBy completing the quests, you will get the chance to unlock different paths,\nafter you find and complete all the quest you will get also the chance to enter the castle!\n\n";
                    slide(print);

                    first_time_house == false;
                }

                if(complete_woods == true && complete_market == false && complete_path == false && complete_forge == false)
                {
                    print = "Hey seems like you have completed the woods quest, congratulation... Now you can go to the east, have a nice journey!\n\n";
                    slide(print);
                }
                else if(complete_market == true && complete_woods == true && complete_path == false && complete_forge == false)
                {
                    print = "Hey seems like you have completed the Market quest, congratulation... Now you can go to the east, have a nice journey!\n\n";
                    slide(print);
                }
                else if(complete_market == true && complete_woods == true && complete_path == true && complete_forge == false)
                {
                    print = "Hey seems like you have completed the Path quest, congratulation... Now you can go to the east, have a nice journey!\n\n";
                    slide(print);
                }
                else if(complete_market == true && complete_woods == true && complete_path == true && complete_forge == true)
                {
                    print = "Hey seems like you have completed all the Quests.\nNow you have to go to the castle, find the right path!\n\n";
                    slide(print);
                }


                pass = false;
            
                cout << "\n";
                cout << "'n'  to North\n";
                cout << "'e'  to East\n";
                cout << "'s'  to South\n";
                cout << "'w'  to West\n";
                cout << "\n";
                cout << "'o' - Exit Game";
                cout << "\n";

                cin >> direction;
                cout << "\n";

    

        
                while (direction != 'n' && direction != 'e' && direction != 's' && direction != 'w' && direction != 'o')
                {
                cout << "Wrong direction, try again!" << endl;

                cin >> direction;

                cout << "\n";
                }
                if(direction == 'n')
                {   
                    lpd.sendBang("pathSteps8");
                    Game1.moveNorth(currentRoom); 

                    pd::List fadeout;
                    fadeout << 1 << 0 << 6000;
                    lpd.sendMessage("cpp", "fadeout", fadeout);
                }
                else if (direction == 'e')
                {
                    if(complete_woods == false)
                    {
                        print = "You cannot go here, complete the wood's quest first!\n\n";
                        slide(print);

                    }
                    else if(complete_woods == true)
                    {
                        Game1.moveEast(currentRoom);


                        pd::List fadeout;
                        fadeout << 1 << 0 << 6000;
                        lpd.sendMessage("cpp", "fadeout", fadeout);
                    }
                    
                    start_music_home = false;
                }
                else if (direction == 's')
                {
                    if(complete_market == false)
                    {
                        print = "You cannot go here, complete the market's quest first!";
                        slide(print);

                        pd::List fadeout;
                        fadeout << 1 << 0 << 6000;
                        lpd.sendMessage("cpp", "fadeout", fadeout);

                        start_music_home = false;
                    }
                    else if(complete_market == true)
                    {
                        lpd.sendBang("pathSteps8");
                        Game1.moveSouth(currentRoom);
                    }
                }
                else if (direction == 'w')
                {
                    if(complete_path == false)
                    {
                        print = "You cannot go here, complete the Inner Path's quest first!";
                        slide(print);

                        start_music_home = false;
                    }
                    else if(complete_path == true)
                    {
                        Game1.moveWest(currentRoom);
                        
                        pd::List fadeout;
                        fadeout << 1 << 0 << 6000;
                        lpd.sendMessage("cpp", "fadeout", fadeout);
                    }
                    
                }
                else if (direction == 'o')
                {
                    cout << "Bye Bye!\n";
                    pass = true;
                    fine2 = true;
                    fine = true;
                    start2 = true;
                    exitGame = true;
                }
                else
                {
                    cout << "Wrong direction, try again!\n";
                }
            

                // QUANDO PRENDI UNA DIREZIONE - TRIGGERA GLI AUDIO DELLE STANZE (TRANNE QUELLA DELLA CASA)

                bang = true;
                start_music_forge   = true;
                start_music_home    = false;
                start_music_woods   = true;
                start_music_path    = true;
                start_music_market  = true;
            }
            else if(choice == 2) // INVENTARIO
            {
                lpd.sendBang("openInventory");
                giocatore1.seeInventory(1);

                start_music_home = false; //permette di non ripetere la funzione musica
            }
            else if(choice == 3) // DIARIO
            {

                lpd.sendBang("bangDiary");

                if (first_time_diary == true)
                {
                    print = "Here you can stay update on the story that you are living.\nEverytime you go thorugh the level of the game you can came here to see what is happening in the world...\n\n";
                    slide(print);

                    first_time_diary = false;
                    diary_story = 1;
                }   
                if (first_time_diary == false)
                {
                    if (diary_story == 1)
                    {
                        print = "Once upon a time there was a kingdome, where citizens lived peacefully and in harmony through each others.\n\nOne day, whithout any notice the world changed!\nOne of the most dangerous enemy appears breaking the peace\nThis things started to take Nora's people to putting them in chains.\n\nThe kingdome, lead by the queen organized a fellowship to save her people!\n\n";
                        slide(print);
                    }
                    if(diary_story == 1 && complete_woods == true)
                    {
                        print = "You woke up in your house, after a missionary gave you a message from the royal family you go out to the woods.\nOnce you arrived, a guy called Gary wnted your help to find his fishing rod\nWhile searching a box contaned the fishing rode caught you attention for the writes on it..\n When you catched the Nora's king the road for the east opened instantly!\n\n";
                        slide(print);
                    }
                }

                start_music_home = false;

            }
            else if(choice == 4)
            {

                pd::List fadeCasa;
                fadeCasa << 1 << 0 << 500;
                lpd.sendMessage("cpp", "fadeout", fadeCasa);

                fine2 = true;
                fine = true;
                start = false;
                start2 = true;
                start = true;
                pass = true;
                castle = true;
                
                
                
                
                
                //exitGame = false;

                start_music_home = false;
                start_music_mainpage = true;

            }
            else
            {
                cout << "Error\n\n";
            }

        } 


    }
    if(currentRoom == 1)   // MUSICA BOSCO - C B N D
    {
            //##########################################// MUSICA BOSCO

        if(start_music_woods == true) // funzione trigger audio
        {
            pd::List bosco;
            bosco << 2 << 0 << 1 << 10000;
            lpd.sendMessage("cpp", "play", bosco);
        }

            //##########################################//
        
        if(first_time_woods == true) // Testo di Ingresso
        {
            print = "Just arrived you can breathe the sweet and the fresh air of the woods inside the Nora's reign... You can see the great trees, known as the trees of god.\n\n";
            slide(print);

            first_time_woods = false;
        }

           //###########################################//

        if(first_time_guy == true) // NPC ti ferma
        {
            cout << "ATTENTION!\n\n";
            print = "While walking a guy stops you, seems like he needs help for something!\n\n";
            slide(print);

            Game1.npcQuest(0,first_time_reward,first_time_blacksmith);


            first_time_guy = false;
        }

            //##########################################//
        
        if(fishing_rod == false) // Azioni prima dell'oggetto quest
        {
            cout << "\n";
            print = "This is what you can do here: \n";
            slide(print);
            cout << "\n";
            cout << "1 - Walking\n\n";
            cout << "2 - Open inventory\n";
            cout << "3 - Open the Map\n";
            cout << "4 - Open Missions\n";
            cout << "5 - Go back\n\n";
            cout << "6 - Exit Game\n";

            cin >> choice2;
            cout << "\n";

            while(choice2 != 1 && choice2 != 2 && choice2 != 3 && choice2 != 4 && choice2 != 5 && choice2 != 6)
            {
                cout << "Wrong number, try again!\n";
                cin >> choice2;
                cout << "\n";

                start_music_woods = false; // permette di non rivalutare la funzione trigger audio
            }
            if (choice2 == 1)  // Quest 1
            {
                lpd.sendBang("pathSteps5");
                srand(time(NULL));
                int npc1_quest = rand() % 2;
                if (npc1_quest == 0)
                {

                    print = "Something under a tree takes your attention, seems a box, there's a write on it and says:\n";
                    slide(print);
                    print = "*Has two great wings, one little eye and four giant paws... if you will ever have the chance to catch it, a new path will be opened!\n\n Insert the code: \n";
                    slide(print);
                    cin >> code;

                    while(code != 214)
                    {
                    lpd.sendBang("wrongCode");        
                    cout << "Wrong code, try again!\n";
                    cin >> code;
                    }
                    if (code == 214)
                    {
                        lpd.sendBang("correctCode");
                        cout << "You've found a fishing rod!\n";
                        lpd.sendBang("addInventory");
                        giocatore1.addItem(item("fishing rod", "it's time for you to increase your fishing skills!",1,5),3);

                        fishing_rod = true;
                    }

                    start_music_woods = false;

                }
                else
                {   
                    cout << "\n";
                    print = "I have to find it, there's something around here, maybe i have to search again!\n\n";
                    slide(print);

                    start_music_woods = false;
                }
        
                first_time_woods = false;

            }
            else if (choice2 == 2) // Apri Inventario
            {
                lpd.sendBang("openInventory");
                giocatore1.seeInventory(1);

                start_music_woods = false;
            }
            else if (choice2 == 3) // Apri Mappa
            {
                lpd.sendBang("openMap");
                Game1.currentPosition(currentRoom);

                start_music_woods = false;
            }
            else if (choice2 == 4) // Controllare le Quest
            {
                lpd.sendBang("openMissions");
                Level1.getComplete(quest1_complete,quest2_complete,quest3_complete,quest4_complete,quest5_complete,0); // quest casa
                Level1.getComplete(quest1_complete,quest2_complete,quest3_complete,quest4_complete,quest5_complete,1); // quest bosco

                start_music_woods = false;
            }
            else if (choice2 == 5) // Tornare Indietro
            {

                pd::List fadeBosco;
                fadeBosco << 2 << 0 << 6000;
                lpd.sendMessage("cpp", "fadeout", fadeBosco);

                lpd.sendBang("pathSteps8");

                this_thread::sleep_for(chrono::milliseconds(4500));

                pd::List fadeForestAmbient;
                fadeForestAmbient << 7 << 0 << 2000;
                lpd.sendMessage("cpp", "fadeout", fadeForestAmbient);

                lpd.sendBang("bangDoor");

                Game1.moveSouth(currentRoom);
                start_music_home = true;

            }
            else if (choice2 == 6) // Uscire dal Gioco
            {
                pass = true;
                fine = true;
                fine2 = true;
                start = false;
            }
            else
            {
                cout << "Error!\n";
            }

        }
        else if(fishing_rod == true) // Azioni dopo l'oggetto Quest
        {
            cout << "\n";
            print = "This is what you can do here: \n";
            slide(print);
            cout << "\n";
            cout << "1 - Walking\n";
            cout << "2 - Fishing\n";
            cout << "3 - Meet Gary\n\n";
            cout << "4 - Open inventory\n";
            cout << "5 - Open the Map\n";
            cout << "6 - Open Missions\n";
            cout << "7 - Go back\n\n";
            cout << "8 - Exit Game\n";
        

            cin >> choice2;
            cout << "\n";

            while(choice2 != 1 && choice2 != 2 && choice2 != 3 && choice2 != 4 && choice2 != 5 && choice2 != 6 && choice2 != 7 && choice2 != 8)
            {
                cout << "Wrong number, try again!\n";
                cin >> choice2;

                start_music_woods = false; // permette di non rivalutare la funzione trigger audio
            }
            if (choice2 == 1)
            {

                print = "You are just passed by here, there's nothing to do\n\n";
                slide(print);

                start_music_woods = false;
                first_time_woods = false;

            }
            else if (choice2 == 2)
            {
                
                if (fishing_rod == true)
                {
                    

                
                    srand(time(NULL));
                    int fish = rand() % 5;
                    if(fish == 1)
                    {
                        lpd.sendBang("fishCatch");
                        print = "Hey you have caught the Giant Monster of Nora..., seems that corrispond to the description on the box...\n\n";
                        slide(print);

                        giocatore1.addItem(item("The King of Nora", "The ancient legend talk about him, it was considered like a god...",1,1000),4);

                        print = "Congratulation, you have completed the second quest.\nNow you can go to the east, to the main square of Nora!.\n\n";
                        slide(print);

                        quest2_complete = true;
                        complete_woods = true;
                        completed = true;
                    }
                    else
                    {   lpd.sendBang("fishingRod");
                        cout << "\n";
                        cout << "Seems that fishes don't bite!";
                    }
                }
                else if (fishing_rod == false)
                {
                    print = "You cannot use the fishing rod, first go to Gary!\n\n";
                    slide(print);
                }

                start_music_woods = false;
            }
            else if (choice2 == 3)
            {
                lpd.sendBang("pathSteps5");
                Game1.npcQuest(1,first_time_reward,first_time_blacksmith);

                first_time_reward = false;
                start_music_woods = false;
            }
            else if (choice2 == 4)
            {
                lpd.sendBang("openInventory");
                giocatore1.seeInventory(1);

                start_music_woods = false;
            }
            else if (choice2 == 5)
            {
                lpd.sendBang("openMap");
                Game1.currentPosition(currentRoom);

                start_music_woods = false;
            }
            else if (choice2 == 6)
            {
                lpd.sendBang("openMissions");
                Level1.getComplete(quest1_complete,quest2_complete,quest3_complete,quest4_complete,quest5_complete,0);
                Level1.getComplete(quest1_complete,quest2_complete,quest3_complete,quest4_complete,quest5_complete,1);

                start_music_woods = false;
            }

            else if (choice2 == 7)
            {
                pd::List fadeBosco;
                fadeBosco << 2 << 0 << 6000;
                lpd.sendMessage("cpp", "fadeout", fadeBosco);

                lpd.sendBang("pathSteps8");

                this_thread::sleep_for(chrono::milliseconds(4500));

                pd::List fadeForestAmbient;
                fadeForestAmbient << 7 << 0 << 2000;
                lpd.sendMessage("cpp", "fadeout", fadeForestAmbient);

                lpd.sendBang("bangDoor");

                Game1.moveSouth(currentRoom);
                start_music_home = true;

            }
            else if (choice2 == 8)
            {
                pass = true;
                fine = true;
                fine2 = true;
                start = false;
            }
            else
            {
                cout << "Error!\n";
            }
        }

    }
    if(currentRoom == 2) // IF GO TO EAST -- MUSICA MERCATO
    {
        if (first_time_market == true)
        { 
            lpd.sendBang("stoneSteps"); 
            cout << "\n\n";
            print = "After a long walk, you've finally arrived at Capital City, it's been a long time since the last one... so many things are changed... \n\n";
            slide (print);

            first_time_market = false;
        }

        if (start_music_market == true)
        {

        

        pd::List fadeout;
        fadeout << 7 << 0 << 6000;
        lpd.sendMessage("cpp", "fadeout", fadeout); 

        //##########################################// MUSICA MERCATO
        pd::List mercato;
        mercato << 3 << 0 << 1 << 10000;
        lpd.sendMessage("cpp", "play", mercato);

        //##########################################//
        }  

        cout << "\n";
        cout << "This is what you can do here: \n\n\n";
        cout << "1 - Walking\n";
        cout << "2 - Enter in a Store\n";
        cout << "3 - Take a Quest\n\n";
        cout << "4 - Open Inventory\n";
        cout << "5 - Open the Map\n";
        cout << "6 - Open Missions\n";
        cout << "7 - Came Back\n\n";
        cout << "8 - Exit the Game\n";

        cout << "\n";
        cin >> choice2;
        cout << "\n";


        while (choice2 != 1 && choice2 != 2 && choice2 != 3 && choice2 != 4 && choice2 != 5 && choice2 != 6 && choice2 != 7 && choice2 != 8)
        {
            cout << "Wrong number, try again!\n";
            cin >> choice2;
        }
        if (choice2 == 1) // WALKING
        {
            if(first_time_walking_market == true)
            {
                lpd.sendBang("stoneSteps"); 
                print = "After a walk, you rest taking time to think... <The people of here are living with smile and happiness, seems that no one know about the last dark events...\nHowever there's no sign of an Inn here, maybe i have to ask, probably someone can say me more...>\n\n";
                slide(print);

                first_time_walking_market = false;
            }
            else if(first_time_walking_market == false)
            {
                print = "Maybe i should not worry about... I 'have to go on, i've bad feelings about all this...\n\n";
                slide(print);
            }
            start_music_market = false;
        }
        else if (choice2 == 2) // ENTER IN A STORE
        {

            if(mistery_guy_complete == false)
            {

                if (first_time_walking_market == true && quest_taked_market == false)
                {
                    print = "The door seems locked, try next time...\n\n";
                    slide(print);

                }
                else if(first_time_walking_market == false && quest_taked_market == true )
                {
                    lpd.sendBang("stoneSteps5");
                    this_thread::sleep_for(chrono::milliseconds(3000));
                    lpd.sendBang("bangDoor");
                    this_thread::sleep_for(chrono::milliseconds(2000));
                    
                    print = "At the first step inside, the climax rapidly changed, when outside seemed to be all as always, in the store something in the air started to be heavy...\nA person is standing in front of you in the middle, maybe I'm in the right place...\n\n";
                    slide(print);

                    Game1.npcQuest(3,first_time_reward,first_time_blacksmith);

                    lpd.sendBang("addInventory");
                    giocatore1.addItem(item("Unknown Item","Just entered the store, i was stopped by a guy giving me this...",1,0),5);

                    first_time_store = false;
                    mistery_guy_complete = true;
                    
                }
                else if(first_time_walking_market == false && quest_taked_market == false)
                {
                    print = "Nothing seems happening, maybe i have to do something before...\n\n";
                    slide(print);
                }
                else if(first_time_walking_market == true && quest_taked_market == true)
                {
                    print = "I need to make two steps outside first...\n\n";
                    slide(print);
                }

                start_music_market = false;
            }
            else if(mistery_guy_complete == true && first_time_complete_market == true)
            {
                Game1.npcQuest(4,first_time_reward,first_time_blacksmith);
                quest3_complete = true;
                complete_market = true;

                first_time_complete_market = false;
            }
            else if(mistery_guy_complete == true && first_time_complete_market == false)
            {
                    print == "I have to harry up... something of terrible it's happening out there!\n\n";
                    slide(print);
            }

            start_music_market = false;
        }
        else if (choice2 == 3) // TAKE A QUEST
        {

            if(quest_taked_market == false)
            {
                Game1.npcQuest(2,first_time_reward,first_time_blacksmith);

                quest_taked_market = true;
                start_music_market = false;
            }
            else if(quest_taked_market == true)
            {
                print = "There aren't more quest to take...\n\n";
                slide(print);
            }
            
        }
        else if (choice2 == 4) // APRE L'INVENTARIO
        {
            lpd.sendBang("openInventory");
            giocatore1.seeInventory(1);

            start_music_market = false;
        }
        else if (choice2 == 5) // APRE LA MAPPA
        {
            lpd.sendBang("openMap");
            Game1.currentPosition(currentRoom);

            start_music_market = false;
        }
        else if (choice2 == 6) // CONTRLLA LE MISSIONI
        {
            lpd.sendBang("openMissions");
            Level1.getComplete(quest1_complete,quest2_complete,quest3_complete,quest4_complete,quest5_complete,0); // quest casa
            Level1.getComplete(quest1_complete,quest2_complete,quest3_complete,quest4_complete,quest5_complete,1); // quest bosco
            Level1.getComplete(quest1_complete,quest2_complete,quest3_complete,quest4_complete,quest5_complete,2); // quest market

        }
        else if (choice2 == 7) // TORNA INDIETRO
        {
                pd::List fadeMercato;
                fadeMercato << 3 << 0 << 6000;
                lpd.sendMessage("cpp", "fadeout", fadeMercato);

                lpd.sendBang("pathSteps8");

                this_thread::sleep_for(chrono::milliseconds(4500));

                lpd.sendBang("bangDoor");
                Game1.moveSouth(currentRoom);

            Game1.moveWest(currentRoom);

            start_music_market = false;
            start_music_home = true;
        }
        else
        {
            cout << "Error!\n";
        }

    }
    if(currentRoom == 3) // IF GO TOI SOUTH -- MUSICA SENTIERO
    {   
        if(start_music_path == true)
        {
        pd::List fadeout;
        fadeout << 1 << 0 << 3000;
        lpd.sendMessage("cpp", "fadeout", fadeout);

        pd::List fadeForestAmbient;
        fadeForestAmbient << 7 << 0 << 2000;
        lpd.sendMessage("cpp", "fadeout", fadeForestAmbient);


        pd::List sentiero;
        sentiero << 4 << 0 << 1 << 10000;
        lpd.sendMessage("cpp", "play", sentiero);

        pd::List nightAmbience;
        nightAmbience << 9 << 0 << 1 << 10000;
        lpd.sendMessage("cpp", "play", nightAmbience);


        }


        if(first_time_path == true)
        {
            print = "In the middle of the night, after passing a road full of barmbe and weed, you end up in a creepy spot...\nFrom the distance you hear someone calling your name...\n";
            slide(print);

            print = "The voices step by step starts to intensifies...\n\n<Please save us, we are suffering... Please save us...!!\n\n";
            slide(print);

            print = "At the mercy of your fear, you start to run... Watching behind you, something seems to appeared, like a ghost who chases you\n";
            slide(print);

            print = "You don't know for how much time you've been running, but at one point you stop to run... in front of you an angelic form makes his appear...\n\n";
            slide(print);

            Game1.npcQuest(5,first_time_reward,first_time_blacksmith);

            first_time_path = false;
            start_music_path = false;
            complete_path = true;
            quest4_complete = true;
        }
        else if(first_time_path == false)
        {
            cout << "\n";
            print = "Incredible... Seems that was only a dream... but... i can see the item that she gave to me.\nThis is the truth... i have to harry up, my friend, my people are all in danger!\n\n";
            slide(print);
        

            cout << "\n";
            cout << "This is what you can do here:\n\n";
            cout << "1 - Open inventory\n";
            cout << "2 - Open the Map\n";
            cout << "3 - Open Missions\n";
            cout << "4 - Go back\n\n";
            cout << "5 - Exit Game\n\n";

            cin >> choice2;
            cout << "\n\n";





            if (choice2 == 1) // Apri Inventario
            {
                    lpd.sendBang("openInventory");
                    giocatore1.seeInventory(1);

                    start_music_path = false;
            }
            else if (choice2 == 2) // Apri Mappa
            {   
                lpd.sendBang("openMap");
                Game1.currentPosition(currentRoom);


                start_music_path = false;
            }
            else if (choice2 == 3) // Controllare le Quest
            {
                //Level1.getComplete(quest1_complete);
                lpd.sendBang("openMissions");
                Level1.getComplete(quest1_complete,quest2_complete,quest3_complete,quest4_complete,quest5_complete,0); // quest casa
                Level1.getComplete(quest1_complete,quest2_complete,quest3_complete,quest4_complete,quest5_complete,1); // quest bosco
                Level1.getComplete(quest1_complete,quest2_complete,quest3_complete,quest4_complete,quest5_complete,2); // quest market
                Level1.getComplete(quest1_complete,quest2_complete,quest3_complete,quest4_complete,quest5_complete,3); // quest path

                start_music_path = false;
            }
            else if (choice2 == 4)
            {
                pd::List fadeSentiero;
                fadeSentiero << 4 << 0 << 6000;
                lpd.sendMessage("cpp", "fadeout", fadeSentiero);

                pd::List fadenightAmbience;
                fadenightAmbience << 9 << 0 << 6000;
                lpd.sendMessage("cpp", "fadeout", fadenightAmbience);

                lpd.sendBang("pathSteps8");

                this_thread::sleep_for(chrono::milliseconds(4500));

                pd::List fadeForestAmbient;
                fadeForestAmbient << 7 << 0 << 2000;
                lpd.sendMessage("cpp", "fadeout", fadeForestAmbient);

                lpd.sendBang("bangDoor");

                Game1.moveNorth(currentRoom);
                start_music_home = true;
            }
            else if (choice2 == 5)
            {
                pass = true;
                fine = true;
                fine2 = true;
                start = false;
            }
        }

    }
    if(currentRoom == 4) // IF GO TO WEST -- MUSICA FORGIA
    {

        if(first_time_forge == true)
        {
            Game1.npcQuest(6,first_time_reward,first_time_blacksmith);

            first_time_forge = false;
        }


        if(start_music_forge == true)
        {
            pd::List fadeForestAmbient;
            fadeForestAmbient << 7 << 0 << 2000;
            lpd.sendMessage("cpp", "fadeout", fadeForestAmbient);

            lpd.sendBang("pathSteps8");

            this_thread::sleep_for(chrono::milliseconds(4700));

            pd::List forgia;
            forgia << 5 << 0 << 1 << 10000;
            lpd.sendMessage("cpp", "play", forgia);

            pd::List blacksmithAmbience;
            blacksmithAmbience << 8 << 0 << 0.5 << 10000;
            lpd.sendMessage("cpp", "play", blacksmithAmbience); 

            lpd.sendBang("bangDoor");
        }



            cout << "\n";
            cout << "This is what you can do here:\n\n";
            cout << "1 - Meet the blacksmith\n\n";
            cout << "2 - Open inventory\n";
            cout << "3 - Open the Map\n";
            cout << "4 - Open Missions\n";
            cout << "5 - Go back\n\n";
            cout << "6 - Exit Game\n\n";

            cin >> choice2;
            cout << "\n\n";

            if(choice2 == 1)
            {   
                if (first_time_blacksmith_forge == true)
                {
                    Game1.npcQuest(7,first_time_reward,first_time_blacksmith);

                    first_time_blacksmith = false;
                    first_time_blacksmith_forge = false;
                    
                    quest5_complete = true;
                    start_music_forge = false;
                    complete_forge = true;
                }
                else if (first_time_blacksmith_forge == false)
                {
                    Game1.npcQuest(7,first_time_reward,first_time_blacksmith);

                    start_music_forge = false;
                }
            }
            else if (choice2 == 2) // Apri Inventario
            {
                lpd.sendBang("openInventory");
                giocatore1.seeInventory(1);

                start_music_forge = false;
            }
            else if (choice2 == 3) // Apri Mappa
            {   
                lpd.sendBang("openMap");
                Game1.currentPosition(currentRoom);


                start_music_path = false;
            }
            else if (choice2 == 4) // Controllare le Quest
            {
                //Level1.getComplete(quest1_complete);
                lpd.sendBang("openMissions");
                Level1.getComplete(quest1_complete,quest2_complete,quest3_complete,quest4_complete,quest5_complete,0); // quest casa
                Level1.getComplete(quest1_complete,quest2_complete,quest3_complete,quest4_complete,quest5_complete,1); // quest bosco
                Level1.getComplete(quest1_complete,quest2_complete,quest3_complete,quest4_complete,quest5_complete,2); // quest market
                Level1.getComplete(quest1_complete,quest2_complete,quest3_complete,quest4_complete,quest5_complete,3); // quest path

                start_music_path = false;
            }
            else if (choice2 == 5)
            {
                pd::List fadeForgia;
                fadeForgia << 5 << 0 << 6000;
                lpd.sendMessage("cpp", "fadeout", fadeForgia);

                pd::List fadeBlacksmith;
                fadeBlacksmith << 8 << 0 << 6000;
                lpd.sendMessage("cpp", "fadeout", fadeBlacksmith);  

                lpd.sendBang("pathSteps8");

                this_thread::sleep_for(chrono::milliseconds(4500));

                lpd.sendBang("bangDoor");

                Game1.moveEast(currentRoom);
                start_music_home = true;
            }
            else if (choice2 == 6)
            {
                pass = true;
                fine = true;
                fine2 = true;
                start = false;
            }
 
    }
}

void ToTheCastle()
{
    cout << "\n";
    print = "Hi ";
    slide(print);

    giocatore1.getName();

    print = "I'm the Queen, congratulation to be able to come here... You journey has just begun...!\n\n";
    slide(print);

    print = "Game Design and Sound Design by Marco Maisto and Matteo Androvetto\n\nMusic composition by Matteo Carlucci\n\nEsame di Sistema, Tecnologie, Applicazioni e linguaggi di programmazione per la multimedialità\n\nAnno 2022/2023\n\nConservatorio Giuseppe Verdi - Milano\n\n";
    slide(print);
}

int main()
{
    // Rooms
    Game1.addRoom(Room("Home","Home sweet Home!",1));
    Game1.addRoom(Room("Woods","Ancient wood",2));
    Game1.addRoom(Room("Capital City","The most modern city of Nora",3));
    Game1.addRoom(Room("The Inner Path", "A long path full of traps, keep attention!",4));
    Game1.addRoom(Room("The celestial forge", "worship of all warriors",5));
    Game1.addRoom(Room("Castle of Nora","The most beautuful creation of Nora",6));
    // Npc

    Game1.addNpc(npc("Gary","A strong bear, it seems he's searching something on the ground"));
    Game1.addNpc(npc("???","A guy appeard in a store, he wore a mask and i cannot say who he was..."));
    Game1.addNpc(npc("Bea","A lady appeared in an angelic form, who is she?"));
    Game1.addNpc(npc("Rex","One of the most important guard of the court"));
    Game1.addNpc(npc("Harris","The Blacksmith of the reign, his works has formed the artistic beauty of Nora"));

    while(exitGame == false)
    {

        if(first_time_init == true)
        {
            init();

            first_time_init = false;
        }
            menù1();

        while (start == false)
        {
            menù2();

            while(start1 == false)
            {
                if(first_time_story == true)
                {
                    story();
                
                    first_time_story = false;
                    
                }
                else if (first_time_story == false)
                {
                    start1 = true;
                }
            }
            if (start1 == true)
            {
               start = true;
            }
                
        }
        if (start == true)
        {
            while(start2 == false)
            { 
                if(first_time_beginning == true)
                {
                    the_beginning();
                    //starting_text();
                    
                    first_time_beginning = false;
                    

                }
                else if (first_time_beginning == false)
                {
                    start2 = true;
                    fine = false;
                    fine2 = false;
                    pass = false;
                }
                
            }
            if (start2 == true)
            {

                while (fine == false)
                {
                    

                    while(fine2 == false)
                    {

                        house(direction, house1, house_choice);

                        while (pass == false)
                        {
                            //inThePlaces(choice,choice2,direction,house1,house_choice);

                                while(castle == false)
                                {
                                    inThePlaces(choice,choice2,direction,house1,house_choice);
                                }
                                if(castle == true)
                                {
                                    if(first_time_castle == true)
                                    {

                                    pd::List fadeMenu;
                                    fadeMenu << 0 << 0 << 200;
                                    lpd.sendMessage("cpp","fadeout",fadeMenu);

                                        
                                    pd::List castello;
                                    castello << 6 << 0 << 1 << 10000;
                                    lpd.sendMessage("cpp", "play", castello);

                                    ToTheCastle();

                                    first_time_castle = false;
                                    }

                                }
                        }
                        if (pass == true)
                        {

                        }

                    }
                    if (fine2 == true)
                    {

                    }

                }
                if (fine == true)

                {

                }
            }
        }
    }
    if (exitGame == true)
    { 

    }

}