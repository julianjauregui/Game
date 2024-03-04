#pragma once

#include "Item.h"
#include <string>
#include <iostream>

using namespace std;


class Inventory
{
protected:
	Item* index = nullptr;
	Item* first = nullptr;
	Item* last = nullptr;

public:
	Inventory() {
		index = nullptr;
		first = nullptr;
		last = nullptr;
	}

	void setIndex(Item* add);
	Item* getIndex();
	Item getFirst();
	void setFirst(Item* add);
	void setLast(Item* add);
	Item getLast();
	Item getCurrent();
	void pushback(Item& newNode);
	Item popBack();
	int size();
	void insertAfter(Item& prevNode, Item& newNode);
	void pushFront(Item& newNode);
	Item deleteCurrent();
	Item popFront();
	string to_string();
};
