#pragma once
#include "YearNode.h"
#include "Player.h"
#include "Enemy.h"
#include "ShopNode.h"
class battleNode
{
protected:
	YearNode* year;
	string description;
	string name;
	Player* player;
	ShopNode* shop;
public:
	battleNode(YearNode* current, string phrase, string nomen, Player* user, ShopNode* state) {
		year = current;
		description = phrase;
		name = nomen;
		player = user;
		shop = state;
	}
	void interact();
	void enterBattle();
	string getName();

};

