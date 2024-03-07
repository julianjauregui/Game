#pragma once
#include "Character.h"
#include "Inventory.h"
using namespace std;

//This will be the main player class
//player is a type of Character, so it inherits from character
class Player : public Character
{
	
protected:
	//has an inventory
	Inventory inventory;

public:
	//The same constructor, for now, as the character class
	Player(int life, int attack, int def, string nomen, double influence, int anno) :Character(life, attack, def, nomen, influence, anno) {
		//sets inventory equal to list, which is new inventory type
		Inventory list;
		inventory = list;
	};

	static Player generatePlayer(); //generates random enemy.  takes nothing in, creates an enemy with randiomly selected name, randomizes other character stats
	
	//getter for inventory
	//Inventory getInventory();
	//setter for inventory
	//void setInventory(Inventory& list);

	//function that overides virtual function in character
	Attack chooseAttack() override;
};


