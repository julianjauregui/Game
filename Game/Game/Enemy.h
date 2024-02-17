#pragma once
#include "Character.h"
//Enemy is a type of Character, so it inherits from character
class Enemy : public Character {
protected:
    //will get more as time progresses
public:
    //The same constructor, for now, as the character class
    Enemy(int life, int attack, int def, string nomen, int influence, int anno) :Character(life, attack, def, nomen, influence, anno) {};
};

