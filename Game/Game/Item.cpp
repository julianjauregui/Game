#include "Item.h"

//returns nextItem pointer
Item* Item::getNextItem()
{
	return nextItem;
}

//returns prevItem pointer
Item* Item::getPrevItem()
{
	return prevItem;
}

//returns healthEffect stat
double Item::getHealthEffect()
{
	return healthEffect;
}

//returns damageEffect stat
double Item::getDamageEffect()
{
	return damageEffect;
}

//returns defenseEffect stat
double Item::getDefenseEffect()
{
	return defenseEffect;
}

//returns fameEffect stat
double Item::getFameEffect()
{
	return fameEffect;
}

//returns name
string Item::getName()
{
	return name;
}

//returns year
int Item::getYear()
{
	return year;
}

//takes input of next and returns nothing
void Item::setNextItem(Item* next)
{
	//sets nextItem pointer equal to next
	nextItem = next;
}

//takes input of prev and returns nothing
void Item::setPrevItem(Item* prev)
{
	//sets prevItem pointer equal to prev
	prevItem = prev;
}

//takes input of health and returns nothing
void Item::setHealthEffect(double health)
{
	//sets healthEffect stat equal to health
	healthEffect = health;
}

//takes input of damage and returns nothing
void Item::setDamageEffect(double damage)
{
	//sets damageEffect stat equal to damage
	damageEffect = damage;
}

//takes input of defense and returns nothing
void Item::setDefenseEffect(double defense)
{
	//sets defenseEffect stat equal to defense
	defenseEffect = defense;
}

//takes input of fame and returns nothing
void Item::setFameEffect(double fame)
{
	//sets fameEffect stat equal to fame
	fameEffect = fame;
}

//takes input of nomen and returns nothing
void Item::setName(string nomen)
{
	//sets name equal to nomen
	name = nomen;
}

//takes input of anno and returns nothing
void Item::setYear(int anno)
{
	//sets year equal to anno
	year = anno;
}

//inputs nothing and returns the item information as a string
string Item::toString()
{
	//output string has this format:
	//$NAME increases your defense by $DEFENSEEFFECT% and your damage by $DAMAGEEFFECT%, restores $HEALTHEFFECT% amount of health, and permanently increases your fame by $FAMEEFFECT%.
	string output = name + " increases your defense by " + to_string(defenseEffect) + "% and your damage by " + to_string(damageEffect) + ", restores " + to_string(healthEffect) + "% amount of health, and permanently increases your fame by  " + to_string(fameEffect) + "%.";
	//returns the output string
	return output;
}
