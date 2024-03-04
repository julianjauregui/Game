//This is the implementation of Inventory.h
#include "Inventory.h"

//inputs add Item and returns nothing
void Inventory::setIndex(Item* add) {
	//sets index equal to add input
	index = add;
}

//inputs nothing and returns Item
Item Inventory::getFirst() {
	//checks to see if the list is not empty
	if (first != nullptr) {
		//returns first de-referenced
		return *first;
	}
	//if list is empty, it returns an empty Item
	Item output(0, 0, 0, 0, "Nothing", 0, "Nothing");
	return output;
}

//inputs add Item and outputs nothing
void Inventory::setFirst(Item* add) {
	//sets first equal to add
	first = add;
}

//inputs add Item and outputs nothing
void Inventory::setLast(Item* add) {
	//sets last equal to add
	last = add;
}

//inputs nothing and returns Item
Item Inventory::getLast() {
	//checks to see if list is not empty
	if (last != nullptr) {
		//returns the last element in the list
		return *last;
	}
	//if list is empty, it returns an empty item
	Item output(0, 0, 0, 0, "Nothing", 0, "Nothing");
	return output;
}

//inputs nothing and returns Item
Item Inventory::getCurrent() {
	//checks to see if list is not empty
	if (index != nullptr) {
		//returns index
		return *index;
	}
	//if list is empty, it returns an empty Item
	Item output(0, 0, 0, 0, "Nothing", 0, "Nothing");
	return output;
}

//inputs Item newNode and returns nothing
void Inventory::pushback(Item& newNode) {
	//checks to see if list is empty
	if (last == nullptr) {
		//if list is empty, it sets first equal to the newNode address
		first = &newNode;
		//if list is empty, it sets last equal to the newNode address
		last = &newNode;
		//if list is empty, it sets index equal to the newNode address
		index = first;
	}

	//if list is not empty
	else {
		//sets last's next item equal to the address of newNode
		last->setNextItem(&newNode);
		//sets newNode's prev item equal to last
		newNode.setPrevItem(last);
		//sets last equal to newNode address
		last = &newNode;
		//sets index back to the begining
		index = first;
	}
}

//inputs nothing and returns Item
Item Inventory::popBack() {
	//if list is empty
	if (last == nullptr) {
		//returns a default Item
		Item output(0, 0, 0, 0, "Nothing", 0, "Nothing");
		return output;
	}

	//if list is only one element long
	else if (first->getNextItem() == nullptr) {
		//makes a temporary Item called data that is equal to the first item
		Item data = *index;
		//sets last equal to nullptr
		last = nullptr;
		//sets index equal to nullptr
		index = nullptr;
		//sets first equal to nullptr
		first = nullptr;
		//returns the temporary item
		return data;
	}

	//it will only get here if the list is more than 1 long
	//makes a new temporary item that is equal to the last element in the Inventory
	Item temp = *last;
	//sets last equal to second-to-last element
	last = last->getPrevItem();
	//sets the last item to null, so that the second to last item is the last one around
	last->setNextItem(nullptr);
	//returns the temporary item
	return temp;
}

//inputs nothing and outputs an int
int Inventory::size() {
	//sets an iterator at the begining
	Item* iterator = first;

	//checks to see if list is empty
	if (first == nullptr) {
		//if it is empty, it returns 0
		return 0;
	}

	//makes a bool which is used to indicate if the iterator is at the end of the list
	bool end = false;
	//creates a counter to be able to add up all the items
	int count = 0;

	//while the iterator is not at the end of the list
	while (!end) {
		//it checks to see if iterator is an item
		if (iterator != nullptr) {
			//sets iterator equal to the next item
			iterator = iterator->getNextItem();
			//adds one to the count
			count++;
		}
		//if the iterator is no longer pointing to an item
		if (iterator == nullptr) {
			//it returns the count
			return count;
		}
	}
}

//inputs 2 Items, prevNode and newNode, and returns nothing
void Inventory::insertAfter(Item& prevNode, Item& newNode)
{
	//sets index temporarily equal to the prevNode's next item, so as to not lose it
	index = prevNode.getNextItem();
	//sets prevNode's next item equal to the address of the new node
	prevNode.setNextItem(&newNode);
	//sets the newNode's previous item equal to the address of the prevNode
	newNode.setPrevItem(&prevNode);
	//sets the newNode's next item equal to the index item
	newNode.setNextItem(index);
	//sets index's previous item equal to the newNode
	index->setPrevItem(&newNode);
	
	//sets index equal to the address of the newNode
	index = &newNode;
}

//inputs newNode and returns nothing
void Inventory::pushFront(Item& newNode) {
	//sets newNode's next item equal to the first item
	newNode.setNextItem(first);
	//sets the first item equal to the prevItem
	first->setPrevItem(&newNode);
	//sets first equal to the address of the newNode
	first = &newNode;
	//sets index equal to the address of the newNode
	index = first;
}

//inputs nothing and returns Item
Item Inventory::deleteCurrent()
{
	//checks to see if the list is not empty
	if (index != nullptr) {
		//checks to see if the index if not the first item in the list
		if (index->getPrevItem() != nullptr) {
			//checks to see if index is not the last item in the list
			if (index->getNextItem() != nullptr) {

				//sets index's next item's previous item equal to index's previous item (skips index)
				index->getNextItem()->setPrevItem(index->getPrevItem());
				//sets index's previous item's next item equal to index's next item (skips index)
				index->getPrevItem()->setNextItem(index->getNextItem());
				//sets a temporary node that is equal to index
				Item current = *index;
				//sets index equal to the item in front of index
				index = index->getNextItem();
				//returns the temporary current item
				return current;
			}

			//Same as popback()
			//makes a temporary current Item that is equal to index
			Item current = *index;
			//sets index equal to the previous item
			index = index->getPrevItem();
			//sets index's next item equal to nullptr
			index->setNextItem(nullptr);
			//sets last equal to index
			last = index;
			//returns the temporary current Item
			return current;
		}

		//same as popfront()
		//makes a temporary current Item that is equal to index
		Item current = *index;
		//sets index equal to index's next item
		index = index->getNextItem();
		//sets index's previous item equal to nullptr
		index->setPrevItem(nullptr);
		//sets first equal to index (index is the new front of the list)
		first = index;
		//returns the temporary current pointer
		return current;
	}

	//if the list is empty, it returns a default item
	Item output(0, 0, 0, 0, "Nothing", 0, "Nothing");
	return output;
}

//inputs nothing and returns an Item
Item Inventory::popFront() {
	//if list is not empty
	if (first != nullptr) {
		//creates a temporary copy Item equal to first
		Item copy = *first;
		//sets first equal to the second element in the list
		first = first->getNextItem();
		//sets first's prev item to nullptr
		first->setPrevItem(nullptr);
		//sets index equal to first
		index = first;
		//returns the temporary copy item
		return copy;
	}

	//if the list is empty it returns a default item
	Item output(0, 0, 0, 0, "Nothing", 0, "Nothing");
	return output;
}

//inputs nothing and outputs a string
string Inventory::to_string()
{
	//makes a temporary iterator item that is starts at first
	Item* iterator = first;
	//makes a string called list that is empty but will have all the info later on
	std::string list = "";
	//sets count equal to the size of the list
	int count = this->size();
	
	//while the list is not at the end
	for (int pos = 0; pos < count; pos++) {
		//it adds the number of the iteration starting at 1
		list += (pos + 1);
		//adds a coma before adding all the information of the item
		list += ", " + iterator->toString() + '\n';
		//sets iterator to the next iterator
		iterator = iterator->getNextItem();
	}

	//returns the string output
	return list;
}

//inputs an int n and outputs nothing
void Inventory::setCurrent(int n)
{
	//makes index be at the begining of the list
	index = first;
	//increments index one by one until it gets to the desired node
	for (int i = 1; i < n && i != this->size(); i++) {
		index = index->getNextItem();
	}
}
