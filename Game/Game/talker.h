//this class will be the talker class, which will do nothing but talk to the player
#pragma once
#include <string>
using namespace std;
#include "talkerPhrase.h"
#include <stdlib.h>
#include <vector>
#include <array>

class talker
{
protected:
    //every talker will have a name
    string name;
    //will be a form of a dialouge tree, which is a full 3-level binary tree
    talkerPhrase dialougeTree[15];

public:
    //nomen and arr will be passed in
    talker(string nomen, talkerPhrase arr[15]) {
        name = nomen;
        //sets every element in dialougeTree to it's corresponding element in arr
        for (int i = 0; i < 15; i++){
            dialougeTree[i] = arr[i];
        }
    }

    //getter for name, because name will be used later on
    string getName();

    //main interface for player to talk to talker
    void talk(int index);

    static vector<talker> initialize();
};

