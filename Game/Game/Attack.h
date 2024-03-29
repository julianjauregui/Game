//this is the attack class, it is used for the battle class and is the basic moves that each character does in an attack
#pragma once
#include <string>
using namespace std;
class Attack
{
protected:
	//Has double for damage multiplier, which multiplies the attack power of a character in the battle
	double damageMultiplier;
	//Has double for defense multiplier, which multiplies the defense power of a character in the battle
	double defenseMultiplier;
	//Has string for the name of the attack
	string name;

public:
	//declares an attack with all 3 variables, attackMultiplier, defenseMultiplier, and name
	Attack(double damage, double defense, string nomen) {
		//sets damageMultiplier to damage input
		damageMultiplier = damage;
		//sets defenseMultiplier to defense
		defenseMultiplier = defense;
		//sets name to nomen
		name = nomen;
	}

	//takes nothing and outputs the damage multiplier stat
	double getDamageMultiplier();
	//Takes nothing and outputs the defense multiplier stat
	double getDefenseMultiplier();
	//Takes nothing and outputs the name of the attack
	string getName();

	//sets damageMultiplier equal to damage
	void setDamageMultiplier(double damage);
	//sets defenseMultiplier equal to defense
	void setDefenseMultiplier(double defense);
	//sets the name equal to nomen
	void setName(string nomen);

	//returns the attack in string form
	string toString(double damage, double def);
};

