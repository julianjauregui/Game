//This class is for the items that are stored in the inventory, which will either affect health, damage, defense, or fame
#pragma once
#include <string>
using namespace std;

class Item
{
protected:
	//will use a doubly linked list structure, so it has next and prev node pointers
	Item* nextItem;
	Item* prevItem;

	//affects said % of these three things (restores health, increases damage and defense, increases fame
	double healthEffect;
	double damageEffect;
	double defenseEffect;
	double fameEffect;

	//each item has a name
	string name;
	//each item has a type, whether it is a weapon, armor, potion, or other
	string type;
	//each item has a year that it was made, (might be implemented later on in the game)
	int year;

public:
	//initializes item with health, damage, defense, fame, name, year, and kind stats; sets pointers to null
	Item(double health, double damage, double defense, double fame, string nomen, int anno, string kind) {
		//healthEffect will be equal to the health input
		healthEffect = health;
		//damageEffect will be equal to the damage input
		damageEffect = damage;
		//defenseEffect will be equal to the defense input
		defenseEffect = defense;
		//fameEffect will be equal to the fame input
		fameEffect = fame;
		//name will be equal to the nomen input
		name = nomen;
		//year will be equal to the anno input
		year = anno;
		//sets type equal to the kind input
		type = kind;
		//nextItem pointer will be equal to nullptr
		nextItem = nullptr;
		//prevItem pointer will be equal to nullptr
		prevItem = nullptr;
	}

	//returns nextItem pointer
	Item* getNextItem();
	//returns prevItem pointer
	Item* getPrevItem();
	//returns healthEffect
	double getHealthEffect();
	//returns damageEffect
	double getDamageEffect();
	//returns defenseEffect
	double getDefenseEffect();
	//returns fameEffect
	double getFameEffect();
	//returns name
	string getName();
	//returns year
	int getYear();
	//returns type
	string getType();

	//sets nextItem pointer equal to next
	void setNextItem(Item* next);
	//sets prevItem pointer equal to prev
	void setPrevItem(Item* prev);
	//sets healthEffect equal to health
	void setHealthEffect(double health);
	//sets damageEffect equal to damage
	void setDamageEffect(double damage);
	//sets defenseEffect equal to defense
	void setDefenseEffect(double defense);
	//sets fameEffect equal to fame
	void setFameEffect(double fame);
	//sets name equal to nomen
	void setName(string nomen);
	//sets year equal to anno
	void setYear(int anno);
	//sets type equal to kind
	void setType(string kind);

	//returns a string with all of the item information
	string toString();
};

