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

int ShopNode::getFightChance()
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

    // Generates a random seed
    srand(time(NULL));
    //Sets choice to a random index that is in the attack size
    int choice = rand() % fightChance;
    if (choice == 1) {
        if (battle->enterBattle()) {
            cout << "You died. Rest in peace my homie." << endl;
            system("pause");
            system("cls");
        }
    }

    cout << "What would you like to do: " << endl;
    cout << "1. Buy things" << endl;
    cout << "2. Go to " << battle->getName()<<endl; 
    cout << "3. Go the the menu" << endl;
    cout << "(press any other number) Return to the White House: " << endl;
    int selection;
    cin >> selection;
    if (selection == 1) {
        interact(*user,*inventory);
        move();
        return;
    }
    else if (selection == 2) {
        battle->interact();
        return;
    }
    else if (selection == 3) {
        system("pause");
        system("cls");
        if (current->menu()) {
            return;
        }
        move();
    }
    else {
        current->move();
        return;
    }
}

void ShopNode::setValues(string kind, string phrase, int anno, int chance, YearNode* times, Player* person, Inventory* collections, battleNode* fight)
{
    description = phrase;
    year = anno;
    fightChance = chance;
    current = times;
    user = person;
    inventory = collections;
    battle = fight;
}
