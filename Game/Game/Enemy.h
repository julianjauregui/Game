#pragma once
#include "Character.h"
//Enemy is a type of Character, so it inherits from character
class Enemy : public Character {
protected:
    //will get more as time progresses
public:
    //The same constructor, for now, as the character class
    Enemy(int life, int attack, int def, string nomen, double influence, int anno) :Character(life, attack, def, nomen, influence, anno) {};

    static Enemy generateEnemy(); //generates random enemy.  takes nothing in, creates an enemy with randiomly selected name, randomizes other character stats
    Attack chooseAttack() override; //function that overides virtual function in character
    static vector<Enemy> makeBosses();//called at the beggining ot the game to generate all of the presidents who are the bad guys
};

