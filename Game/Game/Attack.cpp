#include "Attack.h"
//I will put all the functions for this class in here

//returns damage multiplier
double Attack::getDamageMultiplier()
{
	return damageMultiplier;
}

//returns defense multiplier
double Attack::getDefenseMultiplier()
{
	return defenseMultiplier;
}
\
//returns name of attack
string Attack::getName()
{
	return name;
}

//Sets damageMultiplier equal to damage input
void Attack::setDamageMultiplier(double damage)
{
	damageMultiplier = damage;
}

//sets defenseMultiplier equal to defense input
void Attack::setDefenseMultiplier(double defense)
{
	defenseMultiplier = defense;
}

//sets name equal to nomen input
void Attack::setName(string nomen)
{
	name = nomen;
}

//Takes the input of the damage stat from the character attacking and def stat and outputs the attack in a string
string Attack::toString(double damage, double def)
{
	//makes a string called output that has all the information for the attack being done by a specific character
	//Format will be: "$ATTACK does $NUMBER damage and increases the characters defense by $DEFENSE.
	string output = name + " does " + (to_string(damage * damageMultiplier)) + " damage and increases the characters defense by " + (to_string(def * defenseMultiplier));
	return output;
}
