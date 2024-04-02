#include "talker.h"
#include <iostream>

//returns the name of the talker
string talker::getName()
{
    return name;
}

//main talking interface for the talker and the player
void talker::talk(int index)
{
    cout << (dialougeTree[index]).getTalker() << endl;
    if ((dialougeTree[index]).getFirstResponse() == "") {
        system("pause");
        system("cls");
        return;
    }
    
    int selection = 0;
    while(selection!=1&&selection!=2){
        cout << "Pick your response: " << endl;
        cout << "1. " << dialougeTree[index].getFirstResponse() << endl;
        cout << "2. " << dialougeTree[index].getSecondResponse() << endl;
        if (selection != 1 && selection != 2) {
            cout << "Invalid response, please try again." << endl;
        }
    }

    if (selection == 1) {
        index = index * 2 + 1;
    }
    else if (selection == 2) {
        index = index * 2 + 2;
    }
 
    talk(index);
}

/*array<talker, 2> talker::initialize()
{
    
}*/
