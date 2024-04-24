#pragma once
#include "Shop.h"
#include <string>
#include "YearNode.h"
#include "Player.h"
#include "Inventory.h"
class ShopNode : public Shop
{
protected:
	YearNode* current;
	string description;
	int year;
	double fightChance;
	Player user;
	Inventory inventory;
public:
	ShopNode(string kind, string phrase, int anno, double chance, YearNode* times, Player& person, Inventory& collections) : Shop(kind) {
		description = phrase;
		year = anno;
		fightChance = chance;
		current = times;
		user = person;
		inventory = collections;
	}

	string getDescription();
	void setDescription(string phrase);
	int getYear();
	void setYear(int anno);
	double getFightChance();
	void setFightChance(double chance);
	YearNode* getCurrent();
	void setCurrent(YearNode* times);
	void move();
};

