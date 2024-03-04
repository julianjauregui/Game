#include "Inventory.h"
void Inventory::setIndex(Item* add) {
	index = add;
}

Item* Inventory::getIndex() {
	return index;
}

Item Inventory::getFirst() {
	if (first != nullptr) {
		return *first;
	}
	Item output(0, 0, 0, 0, "Nothing", 0, "Nothing");
	return output;
}

void Inventory::setFirst(Item* add) {
	first = add;
}

void Inventory::setLast(Item* add) {
	last = add;
}

Item Inventory::getLast() {
	if (last != nullptr) {
		return *last;
	}
	Item output(0, 0, 0, 0, "Nothing", 0, "Nothing");
	return output;
}

//functions to implement
Item Inventory::getCurrent() {
	if (index != nullptr) {
		return *index;
	}
	Item output(0, 0, 0, 0, "Nothing", 0, "Nothing");
	return output;
}

void Inventory::pushback(Item& newNode) {
	if (last == nullptr) {
		first = &newNode;
		last = &newNode;
		index = first;
	}
	else {
		last->setNextItem(&newNode);
		newNode.setPrevItem(last);
		last = &newNode;
		index = first;
	}
}

Item Inventory::popBack() {
	if (last == nullptr) {
		Item output(0, 0, 0, 0, "Nothing", 0, "Nothing");
		return output;
	}
	else if (first->getNextItem() == nullptr) {
		Item data = *index;
		last = nullptr;
		index = nullptr;
		first = nullptr;
		return data;
	}
	last = last->getPrevItem();
	last->setNextItem(nullptr);
	Item output(0, 0, 0, 0, "Nothing", 0, "Nothing");
	return output;
}

int Inventory::size() {
	Item* iterator = first;
	if (first == nullptr) {
		return 0;
	}
	bool end = false;
	int count = 0;
	while (!end) {
		if (iterator != nullptr) {
			iterator = iterator->getNextItem();
			count++;
		}
		if (iterator == nullptr) {
			return count;
		}
	}
}

void Inventory::insertAfter(Item& prevNode, Item& newNode)
{
	index = prevNode.getNextItem();
	prevNode.setNextItem(&newNode);
	newNode.setPrevItem(&prevNode);
	newNode.setNextItem(index);
	index->setPrevItem(&newNode);

	index = &newNode;
}

void Inventory::pushFront(Item& newNode) {
	newNode.setNextItem(first);
	first->setPrevItem(&newNode);
	first = &newNode;
	index = first;
}

Item Inventory::deleteCurrent()
{
	if (index != nullptr) {

		if (index->getPrevItem() != nullptr) {

			if (index->getNextItem() != nullptr) {

				index->getNextItem()->setPrevItem(index->getPrevItem());
				index->getPrevItem()->setNextItem(index->getNextItem());
				Item current = *index;
				index = index->getNextItem();
				return current;

			}

			Item current = *index;
			index = index->getPrevItem();
			index->setNextItem(nullptr);
			last = index;
			return current;

		}

		Item current = *index;
		index = index->getNextItem();
		index->setPrevItem(nullptr);
		first = index;
		return current;

	}

	Item output(0, 0, 0, 0, "Nothing", 0, "Nothing");
	return output;
}

Item Inventory::popFront() {
	if (first != nullptr) {
		Item copy = *first;
		first = first->getNextItem();
		first->setPrevItem(nullptr);
		index = first;
		return copy;
	}
	Item output(0, 0, 0, 0, "Nothing", 0, "Nothing");
	return output;
}

string Inventory::to_string()
{
	Item* iterator = first;
	std::string list = "";
	int count = this->size();
	for (int pos = 0; pos < count; pos++) {
		list += iterator->toString();
		list += ", ";
		iterator = iterator->getNextItem();
	}
	return list;
}