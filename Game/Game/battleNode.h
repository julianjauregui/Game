#pragma once
#include "YearNode.h"
#include "Player.h"
#include "Enemy.h"
#include "ShopNode.h"
class YearNode;
class ShopNode;
class battleNode
{
protected:
	YearNode* year;
	string description;
	string name;
	Player* player;
	ShopNode* shop;
public:
	battleNode() {
	}
	void interact();
	void enterBattle();
	string getName();
	void setYear(YearNode* anno);
	void setShop(ShopNode* tienda);
	void setValues(YearNode* current, string phrase, string nomen, Player* user, ShopNode* state);

};

