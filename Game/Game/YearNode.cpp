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

void YearNode::setBoss(Enemy* pres)
{
    boss = pres;
}

void YearNode::setChatter(talker* chatMan)
{
    chatter = chatMan;
}

void YearNode::move()
{
    if (boss==nullptr) {
        chatter->talk(0);
        cout << "You have beaten the game. You may leave in peace." << endl;
        system("pause");
        system("cls");
        return;
    }
    int selection;
    string choice;
    if(boss->getHealth()<=0){
        cout << "You have already beaten this year and prove that you are top dawg. Do you wish to advance to the next year (enter 'yes' to advance):" << endl;
        cin >> choice;
        if (choice == "yes") {
            cout << "Time travelling..." << endl;
            system("pause");
            system("cls");
            next->move();
            return;
        }
    }
    if (prev->getBoss()->getHealth() <= 0) {
        string choice;
        cout << "You have already beaten last year and proved that you were top dawg. Do you wish to return to the previous year (enter 'yes' to time travel):" << endl;
        cin >> choice;
        if (choice == "yes") {
            cout << "Time travelling..." << endl;
            system("pause");
            system("cls");
            prev->move();
            return;
        }
    }
    cout << "Welcome to the White House. It is currently the year " << year << ". What would you like to do: "<<endl;
    if(boss != nullptr){
        cout << "1. Fight " << boss->getName();
    }
    if (shop!=nullptr) {
        cout << "2. Go to " << shop->getType()<<endl;
        cout << "3. Go to " << battle->getName() << endl;
        cin >> selection;
        switch (selection) {
        case 1: {
            cout << "You chose to fight the boss" << endl;
            system("pause");
            system("cls");
            fightBoss();
            return;
            break;
        }
        case 2: {
            cout << "You chose to go to " << shop->getType() << endl;
            system("pause");
            system("cls");
            shop->move();
            return;
            break;
        }
        case 3: {
            cout << "You chose to go to " << battle->getName() << endl;
            system("pause");
            system("cls");
            battle->interact();
            return;
            break;
        }
        default:
            cout << "You choose something invalid. Try again" << endl;
            system("pause");
            system("cls");
            move();
            return;
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
            fightBoss();
            return;
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
            return;
        }
        
    }


}

void YearNode::fightBoss()
{
	if (player->getHealth() <= 0) {
		cout << "You are already dead. You did not live to fight another fight." << endl;
		system("pause");
		system("cls");
		move();
	}
    if (boss->getHealth() <= 0) {
        cout << "Do not beat up a dead man, you wicked American.";
        system("pause");
        system("cls");
        move();
    }
	//initializes the random enemy that the user will be fighting
	cout << "A wild " << boss->getName() << " appeared!" << endl;
	//waits for user input before clearing the screen
	system("pause");
	system("cls");

	//if none of the players have 0 health left
	while (player->getHealth() > 0 && boss->getHealth() > 0) {
		//generates the enemy attack first for no confusion on the defense multiplier stat
		Attack enemyAttack = boss->chooseAttack();

		int runner;
		cout << "Press 1 to fight or any other number to run away: " << endl;
		cin >> runner;
		if (runner != 1) {
			cout << "You can not escape this fight, boy." << endl;

			system("pause");
			system("cls");
		}

		// Player's turn
		//player chooses his attack
		Attack playerAttack = player->chooseAttack();
		//prints out what attack the player chose
		cout << player->getName() << " used " << playerAttack.getName() << "!" << endl;

		//sets enemy health equal to their current health minus the damage multiplier on the player times their damage stat minus the defense stat of the enemy times the defense multiplier of their attack
		if (int(boss->getHealth() - (playerAttack.getDamageMultiplier() * player->getDamage() - boss->getDefense() * enemyAttack.getDefenseMultiplier())) < boss->getHealth()) {
			boss->setHealth(int(boss->getHealth() - (playerAttack.getDamageMultiplier() * player->getDamage() - boss->getDefense() * enemyAttack.getDefenseMultiplier())));
		}
		//displays the current health of the enemy
		cout << boss->getName() << " health: " << boss->getHealth() << endl;
		//waits for user input before clearing screen
		system("pause");
		system("cls");

		//checks if enemy is still alive
		if (boss->getHealth() <= 0) {
			//tells the user that the enemy has been defeated
			cout << "Congratulations! You defeated the " << boss->getName() << "!" << endl;
			player->setFame(player->getFame() + boss->getFame());
			//breaks out of the attack sequence while loop
			break;
		}

		else {
			//Enemy's turn
			//attack has been generated before, so it only prints out the attack name
			cout << boss->getName() << " used " << enemyAttack.getName() << "!" << endl;
			//sets player health equal to their current health minus the damage multiplier on the enemy times their damage stat minus the defense stat of the player times the defense multiplier of their attack
			if (int(player->getHealth() - (enemyAttack.getDamageMultiplier() * boss->getDamage() - player->getDefense() * playerAttack.getDefenseMultiplier())) < player->getHealth()) {
				player->setHealth(int(player->getHealth() - (enemyAttack.getDamageMultiplier() * boss->getDamage() - player->getDefense() * playerAttack.getDefenseMultiplier())));
			}
			//prints out the current player health
			cout << player->getName() << " health: " << player->getHealth() << endl;
			//waits for user input before clearing screen
			system("pause");
			system("cls");

			//if player dies, tells the player that he died
			if (player->getHealth() <= 0) {
				cout << "Game over! " << boss->getName() << " defeated you." << endl;
				//breaks out of the while loop attack sequence
				break;
			}
		}
	}
	//tells the user that the battle is over
	cout << "The Battle has been fought. Go in peace.";
	system("pause");
	system("cls");
    move();
}

void YearNode::setValues(YearNode* prevYear, YearNode* nextYear, ShopNode* shopper, int anno, Enemy* pres, talker* chatMan, battleNode* fight, Player* user)
{
    prev = prevYear;
    next = nextYear;
    shop = shopper;
    year = anno;
    boss = pres;
    chatter = chatMan;
    battle = fight;
    player = user;
}
