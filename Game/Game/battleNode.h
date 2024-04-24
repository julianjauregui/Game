#pragma once
#include "YearNode.h"
#include "Player.h"
#include "Enemy.h"
class battleNode
{
protected:
	YearNode* year;
	string description;
	string name;
	Player* player;
public:
	battleNode(YearNode* current, string phrase, string nomen, Player* user) {
		year = current;
		description = phrase;
		name = nomen;
		player = user;
	}
	void interact();
	void enterBattle();
	string getName();

};

