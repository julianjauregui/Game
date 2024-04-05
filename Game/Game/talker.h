//this class will be the talker class, which will do nothing but talk to the player
#pragma once
#include <string>
using namespace std;
#include "talkerPhrase.h"
#include <stdlib.h>

class talker
{
protected:
    //every talker will have a name
    string name;
    //makes a momentary talkerPhrase to fill tree
    talkerPhrase* momentary;
    //will be a form of a dialouge tree, which is a full 3-level binary tree
    talkerPhrase dialougeTree[10] = { *momentary, *momentary, *momentary,*momentary,*momentary,*momentary };

public:
    //nomen and arr will be passed in
    talker(string nomen, talkerPhrase arr[10]) {
        name = nomen;
        //sets every element in dialougeTree to it's corresponding element in arr
        for (int i = 0; i < 6; i++){
            dialougeTree[i] = arr[i];
        }
    }

    //getter for name, because name will be used later on
    string getName();

    //main interface for player to talk to talker
    void talk(int index);

    std::array<talker,2> initialize();
};

