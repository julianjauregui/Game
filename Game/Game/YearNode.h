#pragma once
#include "ShopNode.h"
#include "Enemy.h"
#include "talker.h"
#include "battleNode.h"
#include "Player.h"
#include "Inventory.h"
class ShopNode;
class battleNode;
class YearNode
{
protected:
	YearNode* prev;
	YearNode* next;
	ShopNode* shop;
	battleNode* battle;
	int year;
	Enemy* boss;
	talker* chatter;
	Player* player;
	Inventory* inventory;
public:
	YearNode(){
	}


	YearNode* getPrev();
	YearNode* getNext();
	ShopNode* getShop();
	battleNode* getBattle();
	int getYear();
	Enemy* getBoss();
	talker* getChatter();


	void setPrev(YearNode* previous);
	void setNext(YearNode* nextYear);
	void setShop(ShopNode* shoppers);
	void setBattle(battleNode* fight);
	void setYear(int anno);
	void setBoss(Enemy* pres);
	void setChatter(talker* chatMan);

	void move();
	void fightBoss();
	void setValues(YearNode* prevYear, YearNode* nextYear, ShopNode* shopper, int anno, Enemy* pres, talker* chatMan, battleNode* fight, Player* user, Inventory* cache);
	bool menu();
	void manageInventory();

};

