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





