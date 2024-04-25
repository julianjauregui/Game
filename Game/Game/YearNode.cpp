#include "YearNode.h"
#include <iostream>
using namespace std;

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
        cout << "Press anything else to stay in the year " << year << endl;
        cin >> choice;
        if (choice == "yes") {
            cout << "Time travelling..." << endl;
            system("pause");
            system("cls");
            next->move();
            return;
        }
    }
    if (prev != nullptr) {

        if (prev->getBoss()->getHealth() <= 0) {
            string choice;
            cout << "You have already beaten last year and proved that you were top dawg. Do you wish to return to the previous year (enter 'yes' to time travel):" << endl;
            cout << "Enter anything else to progress to the year " << year << endl;
            cin >> choice;
            if (choice == "yes") {
                cout << "Time travelling..." << endl;
                system("pause");
                system("cls");
                prev->move();
                return;
            }
        }
    }
    cout << "Welcome to the White House. It is currently the year " << year << ". What would you like to do: "<<endl;
    if(boss != nullptr){
        cout << "1. Fight " << boss->getName()<<endl;
    }
    if (shop!=nullptr) {
        cout << "2. Go to " << shop->getType()<<endl;
        cout << "3. Go to " << battle->getName() << endl;
        cout << "4. Go the the menu" << endl;
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
        case 4: {
            system("pause");
            system("cls");
            if (menu()) {
                return;
            }
            move();
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
        cout << "2. Talk to " << chatter->getName()<<endl;
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
            move();
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

            player->setDamage(player->getDamage() + boss->getDamage());
            player->setDefense(player->getDefense() + boss->getDefense());
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

void YearNode::setValues(YearNode* prevYear, YearNode* nextYear, ShopNode* shopper, int anno, Enemy* pres, talker* chatMan, battleNode* fight, Player* user, Inventory* cache)
{
    prev = prevYear;
    next = nextYear;
    shop = shopper;
    year = anno;
    boss = pres;
    chatter = chatMan;
    battle = fight;
    player = user;
    inventory = cache;
}

void YearNode::manageInventory()
{
    //outputs the user's inventory
    cout << "Welcome to your inventory. Please see what items you have: " << endl;
    cout << inventory->makeString() << endl;

    if (inventory->getSize() == 0) {
        return;
    }
    //starts the choice for what the user will pick at 0
    int choice = 0;

    //while no valid choice has been made
    while (choice <= 0 || choice > 9) {
        //tells the user to pick what item they want
        cout << "Enter the number next to the thing that you would like to use: ";
        //user enters their choice
        cin >> choice;

        //if the user does not have a valid choice
        if (choice <= 0 || choice > 9) {
            //tells the user that they have not yet made a valid choice
            cout << "Please choose a valid number: " << endl;
        }
    }

    //sets current index of user's inventory to choice
    inventory->setCurrent(choice + 1);

    cout << "How many would you like to use: ";
    int amount;
    cin >> amount;
    if (inventory->getCurrent()->getAmount() >= amount) {
        player->setDamage(player->getDamage() + player->getDamage() * inventory->getCurrent()->getDamageEffect());
        player->setHealth(player->getHealth() + player->getHealth() * inventory->getCurrent()->getHealthEffect());
        player->setDefense(player->getDefense() + player->getDefense() * inventory->getCurrent()->getDefenseEffect());
        player->setFame(player->getFame() + player->getFame() * inventory->getCurrent()->getFameEffect());
        inventory->getCurrent()->setAmount(inventory->getCurrent()->getAmount() - amount);
        //tells the user that the thing he selected is being sold
        cout << "Using " << inventory->getCurrent()->getName() << endl;
    }
    else {
        cout << "You do not own that item. Do not try to use something that you do not own, you scoundrel." << endl;
    }

    system("pause");
    system("cls");
}

bool YearNode::menu(){
    //Selection is the number of choice that the user does, from 1 to 6 being accounted for; it set equal to zero before any choice has been made
    int selection = 0;

    //repeats the menu until the player chooses 6, which makes the player leave the game
    while (selection < 1 || selection > 3) {

        //Prints out the main menu choices, with each option being its own line
        cout << "Welcome to the main Menu. Pick what you would like to do: " << endl;
        cout << "1. Return to Game." << endl;
        cout << "2. Check Inventory." << endl;
        cout << "3. Quit Game." << endl;
        cout << "Pick your selection: ";
        //Enters the selection from the user of what function they want to call
        cin >> selection;

        //Switch case with the user-inputted selection as the main variable being checked
        switch (selection) {

            //The first case is the overworld function, which returns to the overworld
        case 1:
            //clears screen and then calls overworld function
            system("cls");
            return false;
            break;

            //The second option is the enter battle function, which is called to enter and fight a battle
        case 2:
            //clears screen and then calls enter battle function
            system("cls");
            manageInventory();
            return false;
            break;

            //The third option is the inventory function, that is called to manage and change and view the player's inventory
        case 3:
            //clears screen and then calls manage inventory
            system("cls");
            cout << "You quit the game. Goodbye fellow American.";
            return true;
            break;

            //If something other than 1-6 was entered, it displays that the option was invalid and it returns to the main menu selection at the top
        default:
            //doesn't clear screen because the user should be able to see that his input was incorrect so as to not repeat it
            cout << "The selection you chose was invalid. Please choose again." << endl;

        }
    }

}
