#pragma once
#include "Inventory.h"
#include "Character.h"
using namespace std;

//a different way to include different classes
class Inventory;

//This will be the main player class
//player is a type of Character, so it inherits from character
class Player : public Character
{
	
protected:

public:
	//The same constructor, for now, as the character class, except with an inventory
	Player(int life, int attack, int def, string nomen, double influence, int anno) :Character(life, attack, def, nomen, influence, anno){
	};

	static Player generatePlayer(); //generates random enemy.  takes nothing in, creates an enemy with randiomly selected name, randomizes other character stats

	//function that overides virtual function in character
	Attack chooseAttack() override;
};


