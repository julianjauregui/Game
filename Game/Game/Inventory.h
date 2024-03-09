//This is the player inventory class
#pragma once

//An item is equivalent to a node in a list
#include "Player.h"
#include "Item.h"
#include <string>
#include <iostream>

using namespace std;


class Inventory
{
protected:
	//Pointer to the current index of the Inventory
	Item* index = nullptr;
	//pointer to the first item in the Inventory
	Item* first = nullptr;
	//pointer to the last pointer in the Inventory
	Item* last = nullptr;

public:
	//Initializes Inventory with all nullptr values
	Inventory() {
		index = nullptr;
		first = nullptr;
		last = nullptr;
	}

	//Sets Index equal to add
	void setIndex(Item* add);
	//Returns the first Item in the Inventory
	Item getFirst();
	//Sets the first Item in the Inventory equal to add
	void setFirst(Item* add);
	//Sets the last Item in the Inventory equal to add
	void setLast(Item* add);
	//Returns the last Item in the Inventory
	Item getLast();
	//Returns the Item that is currently being indexed
	Item* getCurrent();
	//Adds an Item to the end of the Inventory
	void pushback(Item& newNode);
	//Removes and Returns the final Item to the end of the Inventory
	Item popBack();
	//Returns the size of the Inventory
	int size();
	//Adds a new Item between 2 different Nodes
	void insertAfter(Item& prevNode, Item& newNode);
	//Adds a new Node to the front of the Inventory
	void pushFront(Item& newNode);
	//Deletes the current Node being addressed by current
	Item deleteCurrent();
	//Returns and Removes the first element in the list
	Item popFront();
	//Returns all the Inventory information in a string
	string to_string();
	//moves index to the nth Item in the Inventory
	void setCurrent(int n);
};
