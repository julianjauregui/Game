//This class will be the parent class for every single character in the game, 
//different subclasses will be made for enemies, npc, and player characters

//Includes every header that is predicted to be used for any character subclass and functions
#pragma once
#include <string>
#include <vector>
#include "Attack.h"
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
	//Vector of attacks that will be used in battles
	vector<Attack> attacks{};
	//Year that the character is in
	int year;

public:
	//Creates a character, with health, damage, defense, name, fame, and year stats
	Character(int life, int attack, int def, string nomen, int influence, int anno) {
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
		//sets year equal to anno input
		year = anno;
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
	//Getter of attacks, implemented in Character.cpp file
	vector<Attack> getAttacks();
	//Getter of year, implemented in Character.cpp file
	int getYear();

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
	//Setter for attacks, implemented in Character.cpp file
	void setAttacks(vector<Attack> moves);
	//Setter for year, implemented in Character.cpp file
	void setYear(int anno);

	//Adds move to attacks vector
	void addAttack(Attack move);
	//Outputs the character with all their information
	string toString();
	//Outputs all the attacks in a list with each attack on a new line (Primarily used as a helper function for the above)
	string printAttacks();
};

