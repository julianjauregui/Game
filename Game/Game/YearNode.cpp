#include "YearNode.h"

YearNode* YearNode::getPrev()
{
    return prev;
}

YearNode* YearNode::getNext()
{
    return next;
}

ShopNode* YearNode::getShop()
{
    return shop;
}

battleNode* YearNode::getBattle()
{
    return battle;
}

int YearNode::getYear()
{
    return year;
}

Enemy* YearNode::getBoss()
{
    return boss;
}

talker* YearNode::getChatter()
{
    return chatter;
}

void YearNode::setPrev(YearNode* previous)
{
    prev = previous;
}

void YearNode::setNext(YearNode* nextYear)
{
    next = nextYear;
}

void YearNode::setShop(ShopNode* shoppers)
{
    shop = shoppers;
}

void YearNode::setBattle(battleNode* fight)
{
    battle = fight;
}

void YearNode::setYear(int anno)
{
    year = anno;
}

void YearNode::getBoss(Enemy* pres)
{
    boss = pres;
}

void YearNode::setChatter(talker* chatMan)
{
    chatter = chatMan;
}

void YearNode::move()
{
    int selection;
    cout << "Welcome to the White House. It is currently the year " << year << ". What would you like to do: "<<endl;
    cout << "1. Fight " << boss->getName();
    if (shop!=nullptr) {
        cout << "2. Go to " << shop->getType()<<endl;
        cout << "3. Go to " << battle->getName() << endl;
        cin >> selection;
        switch (selection) {
        case 1: {
            cout << "You chose to fight the boss" << endl;
            system("pause");
            system("cls");
            //fight boss
            break;
        }
        case 2: {
            cout << "You chose to go to " << shop->getType() << endl;
            system("pause");
            system("cls");
            shop->move();
            break;
        }
        case 3: {
            cout << "You chose to go to " << battle->getName() << endl;
            system("pause");
            system("cls");
            battle->interact();
            break;
        }
        default:
            cout << "You choose something invalid. Try again" << endl;
            system("pause");
            system("cls");
            move();
        }
    }
    else {
        cout << "2. Talk to " << chatter->getName();
        cin >> selection;
        switch (selection) {
        case 1: {
            cout << "You chose to fight the boss" << endl;
            system("pause");
            system("cls");
            //fight boss
            break;
        }
        case 2: {
            cout << "You chose talk to " << chatter->getName() << endl;
            system("pause");
            system("cls");
            chatter->talk(0);
            break;
        }
        default:
            cout << "You choose something invalid. Try again" << endl;
            system("pause");
            system("cls");
            move();
        }
        
    }


}
