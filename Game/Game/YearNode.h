#pragma once
#include "ShopNode.h"
#include "Enemy.h"
#include "talker.h"
#include "battleNode.h"
#include "Player.h"
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
public:
	YearNode(YearNode* prevYear, YearNode* nextYear, ShopNode* shopper, int anno, Enemy* pres, talker* chatMan, battleNode* fight, Player* user) {
		prev = prevYear;
		next = nextYear;
		shop = shopper;
		year = anno;
		boss = pres;
		chatter = chatMan;
		battle = fight;
		player = user;
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
	void getBoss(Enemy* pres);
	void setChatter(talker* chatMan);

	void move();
	void fightBoss();

};

