#include "battleNode.h"

void battleNode::interact()
{
	cout << description << endl;
	cout << "What would you like to do: " << endl;
	cout << "1. Leave" << endl;
	cout << "2.Flee to " << shop->getType() << endl;
	cout << "(anything else) stay and die: " << endl;
	int selection;
	cin >> selection;
	if (selection == 1) {
		system("pause");
		system("cls");
		year->move();
		return;
	}
	else if (selection == 2) {
		system("pause");
		system("cls");
		shop->move();
		return;
	}
	else {
		cout<<"You chose to die"<<endl;
		enterBattle();
		interact();
		return;
	}
}

//This enterBattle function, the arena whwere battles are fought
void battleNode::enterBattle() {
	if (player->getHealth() <= 0) {
		cout << "You are already dead. You did not live to fight another fight." << endl;
		system("pause");
		system("cls");
		return;
	}
	//initializes the random enemy that the user will be fighting
	Enemy enemy = Enemy::generateEnemy();
	cout << "A wild " << enemy.getName() << " appeared!" << endl;
	//waits for user input before clearing the screen
	system("pause");
	system("cls");

	//if none of the players have 0 health left
	while (player->getHealth() > 0 && enemy.getHealth() > 0) {
		//generates the enemy attack first for no confusion on the defense multiplier stat
		Attack enemyAttack = enemy.chooseAttack();

		int runner;
		cout << "Press 1 to fight or any other number to run away: " << endl;
		cin >> runner;
		if (runner != 1) {
			cout << "You do not fight the battle. Quitter." << endl;

			system("pause");
			system("cls");
			return;
		}

		// Player's turn
		//player chooses his attack
		Attack playerAttack = player->chooseAttack();
		//prints out what attack the player chose
		cout << player->getName() << " used " << playerAttack.getName() << "!" << endl;

		//sets enemy health equal to their current health minus the damage multiplier on the player times their damage stat minus the defense stat of the enemy times the defense multiplier of their attack
		if (int(enemy.getHealth() - (playerAttack.getDamageMultiplier() * player->getDamage() - enemy.getDefense() * enemyAttack.getDefenseMultiplier())) < enemy.getHealth()) {
			enemy.setHealth(int(enemy.getHealth() - (playerAttack.getDamageMultiplier() * player->getDamage() - enemy.getDefense() * enemyAttack.getDefenseMultiplier())));
		}
		//displays the current health of the enemy
		cout << enemy.getName() << " health: " << enemy.getHealth() << endl;
		//waits for user input before clearing screen
		system("pause");
		system("cls");

		//checks if enemy is still alive
		if (enemy.getHealth() <= 0) {
			//tells the user that the enemy has been defeated
			cout << "Congratulations! You defeated the " << enemy.getName() << "!" << endl;
			player->setFame(player->getFame() + enemy.getFame());
			//breaks out of the attack sequence while loop
			break;
		}

		// Generates a random seed
		srand(time(NULL));
		//Sets choice to a random index that is in the attack size
		int choice = rand() % 5;
		if (choice == 1) {
			cout << "The enemy ran away." << endl;
			enemy.setHealth(0);
		}
		else {
			//Enemy's turn
			//attack has been generated before, so it only prints out the attack name
			cout << enemy.getName() << " used " << enemyAttack.getName() << "!" << endl;
			//sets player health equal to their current health minus the damage multiplier on the enemy times their damage stat minus the defense stat of the player times the defense multiplier of their attack
			if (int(player->getHealth() - (enemyAttack.getDamageMultiplier() * enemy.getDamage() - player->getDefense() * playerAttack.getDefenseMultiplier())) < player->getHealth()) {
				player->setHealth(int(player->getHealth() - (enemyAttack.getDamageMultiplier() * enemy.getDamage() - player->getDefense() * playerAttack.getDefenseMultiplier())));
			}
			//prints out the current player health
			cout << player->getName() << " health: " << player->getHealth() << endl;
			//waits for user input before clearing screen
			system("pause");
			system("cls");

			//if player dies, tells the player that he died
			if (player->getHealth() <= 0) {
				cout << "Game over! " << enemy.getName() << " defeated you." << endl;
				//breaks out of the while loop attack sequence
				break;
			}
		}
	}
	//tells the user that the battle is over
	cout << "The Battle has been fought. Go in peace.";
	system("pause");
	system("cls");
}

string battleNode::getName()
{
	return name;
}

void battleNode::setYear(YearNode* anno)
{
	year = anno;
}

void battleNode::setShop(ShopNode* tienda)
{
	shop = tienda;
}

void battleNode::setValues(YearNode* current, string phrase, string nomen, Player* user, ShopNode* state)
{
	year = current;
	description = phrase;
	name = nomen;
	player = user;
	shop = state;
}
