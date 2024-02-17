#pragma once
#include "Character.h"
//Player is a type of character, so it inherits from character
class Player : public Character {
protected:
    //currently empty, will get more as the need progresses
public:
    //The same constructor, for now, as the character class
    Player(int life, int attack, int def, string nomen, int influence, int anno) :Character(life, attack, def, nomen, influence, anno) {};
};


