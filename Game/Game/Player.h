#pragma once
#include "Character.h"
//This will be the main player class
//player is a type of Character, so it inherits from character
class Player : public Character
{
	
protected:

public:
	//The same constructor, for now, as the character class
	Player(int life, int attack, int def, string nomen, int influence) :Character(life, attack, def, nomen, influence) {};
	//function that overides virtual function in character
	Attack chooseAttack();
	
};

