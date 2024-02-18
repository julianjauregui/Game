//Was unable to get much progress done on this class due to confusion about what variables should be in the character class as opposed to the enemy/npc/player classes

#pragma once
#include "Character.h"
//Enemy is a type of Character, so it inherits from character
class Enemy : public Character {
protected:
    //vector<attack> attackChoices;
    //The above will be implemented so that each enemy can have different attacks that they can do
public:
    //The same constructor, for now, as the character class
    Enemy(int life, int attack, int def, string nomen, int influence) :Character(life, attack, def, nomen, influence) {};

    static Enemy generateEnemy(); //generates random enemy.  takes nothing in, creates an enemy with randiomly selected name, randomizes other character stats
    Attack chooseAttack(); //function that overides virtual function in character
};

