#pragma once
#include "Shop.h"
#include <string>
#include "YearNode.h"
#include "Player.h"
#include "Inventory.h"
#include "battleNode.h"
class battleNode;
class YearNode;
class ShopNode : public Shop
{
protected:
	YearNode* current;
	string description;
	int year;
	int fightChance;
	Player* user;
	Inventory* inventory;
	battleNode* battle;
public:
	ShopNode(string kind): Shop(kind) {
	}

	string getDescription();
	void setDescription(string phrase);
	int getYear();
	void setYear(int anno);
	int getFightChance();
	void setFightChance(double chance);
	YearNode* getCurrent();
	void setCurrent(YearNode* times);
	void move();
	void setValues(string kind, string phrase, int anno, int chance, YearNode* times, Player* person, Inventory* collections, battleNode* fight);
};

