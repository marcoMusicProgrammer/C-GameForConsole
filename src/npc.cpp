#include <iostream>
#include "npc.h"
#include "main.h"

using namespace std; 

npc::npc(string name, string description)
{
    npc_name = name;
    npc_description = description;
}

npc::~npc()
{
}

string npc::getName()
{
     return this->npc_name;
}

string npc::getDescription()
{
    return this->npc_description;
}

