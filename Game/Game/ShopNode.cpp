#include "ShopNode.h"

string ShopNode::getDescription()
{
    return description;
}

void ShopNode::setDescription(string phrase)
{
    description = phrase;
}

int ShopNode::getYear()
{
    return year;
}

void ShopNode::setYear(int anno)
{
    year = anno;
}

double ShopNode::getFightChance()
{
    return fightChance;
}

void ShopNode::setFightChance(double chance)
{
    fightChance = chance;
}

YearNode* ShopNode::getCurrent()
{
    return current;
}

void ShopNode::setCurrent(YearNode* times)
{
    current = times;
}

void ShopNode::move()
{
    cout << description << endl;
    cout << "What would you like to do: " << endl;
    cout << "1. Buy things" << endl;
    cout << "2. Go to " << battle->getName();
    cout << "(press any other number) Return to the White House: " << endl;
    int selection;
    cin >> selection;
    if (selection == 1) {
        interact(user, inventory);
        move();
    }
    else if (selection == 2) {
        battle->interact();
        current->move();
    }
    else {
        current->move();
    }
}
