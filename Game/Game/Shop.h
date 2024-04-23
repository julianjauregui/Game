//this is the shop class
#pragma once
#include "Inventory.h"

//shop is a double linked list, so it inherits from inventory
class Shop : public Inventory
{
protected:
	//type is what type of things a shop sells
	string type;

	//function to buy things from the shop
	void buy(Player user);
	//function to sell things to the shop
	void sell(Inventory& possessions, Player user);

public:
	//inputs kind and makes shop of type inventory
	Shop(string kind) : Inventory() {
		//sets kind equal to type
		type = kind;
	}

	//returns the type
	string getType();
	//sets type equal to kind
	void setType(string kind);

	//function to interact with shop
	void interact(Player& user, Inventory& list);
	string toString();

};