//This class will be the parent class for every single character in the game, 
//different subclasses will be made for enemies, npc, and player characters

//Includes every header that is predicted to be used for any character subclass and functions
#pragma once
#include "Attack.h"
#include <string>
#include <vector>
using namespace std;

class Character
{

protected:
	//This value saves the current health of the character
	int health;
	//This value saves the current damage stat of the character
	int damage;
	//This value saves the current defense stat of the character
	int defense;
	//This value saves the name of the character
	string name;
	//This value saves the current fame level of the character
	//Fame is defined as how famous the character is in the overworld, or how much infuluence he has, or how many people know of him
	//Every character will have fame, but it primarilly affects the player and the enemies
	int fame;

	//vector from attack allows character to have multiple attack options
	std::vector<Attack> specialAttacks;

public:
	//Creates a character, with health, damage, defense, name, and fame stats
	Character(int life, int attack, int def, string nomen, int influence) {
		//sets health equal to the life input
		health = life;
		//sets damage equal to the attack input
		damage = attack;
		//sets defense equal to the def input
		defense = def;
		//sets name equal to the nomen input
		name = nomen;
		//sets fame equal to the influence input
		fame = influence;
	}

	//Getter for health, implemented in the Character.cpp file
	int getHealth();
	//Getter for damage, implemented in the Character.cpp file
	int getDamage();
	//Getter for defense, implemented in the Character.cpp file
	int getDefense();
	//Getter for name, implemented in the Character.cpp file
	string getName();
	//Getter of fame, implemented in the Character.cpp file
	int getFame();

	//Setter for the health, implemented in the Character.cpp file
	void setHealth(int life);
	//Setter for the damage, implemented in the Character.spp file
	void setDamage(int attack);
	//Setter for the defense, implemented in the Character.spp file
	void setDefense(int def);
	//Setter for the name, implemented in the Character.spp file
	void setName(string nomen);
	//Setter for the fame, implemented in the Character.spp file
	void setFame(int influence);
	//shows attacks that a characterr can execute, takes nothing
	void displayAttacks();
	//takes nothing, usage has yet to be determined, will vary by character
	virtual Attack chooseAttack();

};

