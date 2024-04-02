#include "talker.h"
#include <iostream>

//returns the name of the talker
string talker::getName()
{
    return name;
}

//main talking interface for the talker and the player
void talker::talk(int selection)
{
    cout << dialougeTree[selection] << endl;
    cout << "Pick your response: " << endl;
    cout <<
    
}
