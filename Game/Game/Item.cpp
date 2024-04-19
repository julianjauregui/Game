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

//returns type
string Item::getType()
{
	return type;
}

//returns cost
double Item::getCost()
{
	return cost;
}

int Item::getAmount()
{
	return amount;
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

//takes input of kind and returns nothing
void Item::setType(string kind)
{
	//sets type equal to kind
	type = kind;
}

//takes input of price and returns nothing
void Item::setCost(double price)
{
	//sets cost equal to price
	cost = price;
}

void Item::setAmount(int numy)
{
	amount = numy;
}

//inputs nothing and returns the item information as a string
string Item::toString()
{
	//output string has this format:
	//$NAME is a $TYPE, and it increases your defense by $DEFENSEEFFECT% and your damage by $DAMAGEEFFECT%, restores $HEALTHEFFECT% amount of health, and permanently increases your fame by $FAMEEFFECT%.
	string output = name + " is a " + type + ", \n\tIncreases your defense by " + to_string(defenseEffect) + "% \n\tIncreases your damage by " + to_string(damageEffect) + ", \n\trestores " + to_string(healthEffect) + "% amount of health, \n\tpermanently increases your fame by  " + to_string(fameEffect) + "%." + "\n\tIt costs " + to_string(cost) + " amount of fame.";
	//returns the output string
	return output;
}

string Item::inventoryString()
{

	//output string has this format:
	//$NAME is a $TYPE, and it increases your defense by $DEFENSEEFFECT% and your damage by $DAMAGEEFFECT%, restores $HEALTHEFFECT% amount of health, and permanently increases your fame by $FAMEEFFECT%.
	string output = name + " is a " + type + " \n\tIncreases your defense by " + to_string(defenseEffect) + "% \n\tIncreases your damage by " + to_string(damageEffect) + ", \n\trestores " + to_string(healthEffect) + "% amount of health \n\tpermanently increases your fame by  " + to_string(fameEffect) + "%." + "\n\tYou own" + to_string(amount);
	//returns the output string
	return output;
}
