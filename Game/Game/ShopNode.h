#pragma once
#include "Shop.h"
#include <string>
class ShopNode : public Shop
{
protected:
	//will add yearNode
	string description;
	int year;
	double fightChance;
public:
	ShopNode(string kind, string phrase, int anno, double chance) : Shop(kind) {
		description = phrase;
		year = anno;
		fightChance = chance;
	}

	string getDescription();
	void setDescription(string phrase);
	int getYear();
	void setYear(int anno);
	double getFightChance();
	void setFightChance(double chance);
};

