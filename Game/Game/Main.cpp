//This entire game is still getting made, so update each function accordingly, as time progresses
//This menu is only a development menu for the time being
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Inventory.h"
#include "Shop.h"

//THIS IS THE LIBRARY TO INCLUDE IN ORDER TO WIPE SCREEN (USE system("cls"); IN ORDER TO CLEAR THE SCREEN)
#include <stdlib.h>

using namespace std;

//will contain all of the enemy presidents
vector <Enemy> enemyPresidents;

//this is the player's inventory for game start up
Inventory inventory;

//this is the player
Player player(0, 0, 0, "", 0.0, 0);

//initializes weaponsShop
Shop weaponsShop("Weapon");
//makes 3 different items
//the stats are: health, damage, defense, fame, name, year, kind, and price 
Item nuke(-0.75, 100., 0., 100., "Nuke", 1947, "Weapon", 1000.);
Item gun(0.0, 10.0, 0.3, 0.0, "Gun", 1905, "Weapon", 25.);
Item pen(0., 5.0, 3.0, 10., "Pen", 1805, "Weapon", 1);

//initializes armorShop
Shop armorShop("Armor");
//makes 3 different items
//the stats are: health, damage, defense, fame, name, year, kind, and price 
Item logs(0., 0.5, 10., 0., "Log", 1860, "Armor", 5.25);
Item counterEspionage(0, 0.0, 30.0, -20.0, "Gun", 1955, "Armor", 100.);
Item teddyBear(.5, 2.0, 5.0, 0., "Teddy Bear", 1905, "Armor", 30);

//makes potionShop
Shop potionShop("Potion");
//makes 3 different items
//the stats are: health, damage, defense, fame, name, year, kind, and price 
Item damagePotion(0., 1., 0., 0., "Damage Potion", 0, "Potion", 2.);
Item defensePotion(0, 0.0, 1.0, 0.0, "Defense Potion", 0, "Potion", 2.);
Item healthPotion(1., 0.0, 0.0, 0., "Health Potion", 0., "Potion", 2.);

//This function is the startup function and is meant to be called at the beginning of the game, so as to start up the game 
void startup();

//This function returns to the game/map from the menu
void returnToOverworld();

//This function is called every time a battle starts and is the battle itself
void enterBattle();

//This function is made to open and change the inventory of the player
void manageInventory();

//This function is called every time the player enters a shop
void enterShop();

//This function is called every time the player talks to another character in the game
void chat();

//This function quits the game
void quitGame();


int main() {
	//runs the startup() function at the begining of the game
	startup();
	
	//Selection is the number of choice that the user does, from 1 to 6 being accounted for; it set equal to zero before any choice has been made
	int selection = 0;

	//repeats the menu until the player chooses 6, which makes the player leave the game
	while (selection != 6) {
		
		//Prints out the main menu choices, with each option being its own line
		cout << "Welcome to the main Menu. Pick what you would like to do: " << endl;
		cout << "1. Return to Game." << endl;
		cout << "2. Enter Battle." << endl;
		cout << "3. Manage Inventory." << endl;
		cout << "4. Enter shop." << endl;
		cout << "5.Talk to Someone." << endl;
		cout << "6. Quit Game." << endl;
		cout << "Pick your selection: ";
		//Enters the selection from the user of what function they want to call
		cin >> selection;

		//Switch case with the user-inputted selection as the main variable being checked
		switch (selection) {

			//The first case is the overworld function, which returns to the overworld
		case 1:
			//clears screen and then calls overworld function
			system("cls");
			returnToOverworld();
			break;

			//The second option is the enter battle function, which is called to enter and fight a battle
		case 2:
			//clears screen and then calls enter battle function
			system("cls");
			enterBattle();
			break;

			//The third option is the inventory function, that is called to manage and change and view the player's inventory
		case 3:
			//clears screen and then calls manage inventory
			system("cls");
			manageInventory();
			break;

			//The fourth option is the enter shop function, which is called to enter a shop and interact with it
		case 4:
			//clears screen and then calls enter shop function
			system("cls");
			enterShop();
			break;

			//The fifth option is the chat function, which is made to chat with other game characters in the game
		case 5:
			//clears screen and then calls chat function
			system("cls");
			chat();
			break;

			//The sixth option is the quit game option, which makes the user leave the game
		case 6:
			//clears screen and then calls quit game function
			system("cls");
			quitGame();
			break;

			//If something other than 1-6 was entered, it displays that the option was invalid and it returns to the main menu selection at the top
		default:
			//doesn't clear screen because the user should be able to see that his input was incorrect so as to not repeat it
			cout << "The selection you chose was invalid. Please choose again." << endl;

		}

	}
	return 0;
}

//Any startup function will be called here
void startup()
{
	//generates all of the presidents from the enemies and sets enemyPresidents equal to it
	enemyPresidents = Enemy::makeBosses();
	//generates the player with his desired president choice
	player = Player::generatePlayer();

	//puts all 3 items into the potionShop
	weaponsShop.pushback(nuke);
	weaponsShop.pushback(gun);
	weaponsShop.pushback(pen);

	//puts all 3 items into the potionShop
	armorShop.pushback(logs);
	armorShop.pushback(counterEspionage);
	armorShop.pushback(teddyBear);


	//puts all 3 items into the potionShop
	potionShop.pushback(damagePotion);
	potionShop.pushback(defensePotion);
	potionShop.pushback(healthPotion);

}

//This overworld function is still in production, so it says so
void returnToOverworld() {
	cout << "Sorry, it appears that the overworld is still in development." << endl;
}

//This enterBattle function, the arena whwere battles are fought
void enterBattle() {
	//initializes the random enemy that the user will be fighting
	Enemy enemy = Enemy::generateEnemy();
	cout << "A wild " << enemy.getName() << " appeared!" << endl;
	//waits for user input before clearing the screen
	system("pause");
	system("cls");

	//if none of the players have 0 health left
	while (player.getHealth() > 0 && enemy.getHealth() > 0) {
		//generates the enemy attack first for no confusion on the defense multiplier stat
		Attack enemyAttack = enemy.chooseAttack();

		// Player's turn
		//player chooses his attack
		Attack playerAttack = player.chooseAttack();
		//prints out what attack the player chose
		cout << player.getName() << " used " << playerAttack.getName() << "!" << endl;

		//sets enemy health equal to their current health minus the damage multiplier on the player times their damage stat minus the defense stat of the enemy times the defense multiplier of their attack
		enemy.setHealth(int(enemy.getHealth() - (playerAttack.getDamageMultiplier() * player.getDamage() - enemy.getDefense() * enemyAttack.getDefenseMultiplier())));
		//displays the current health of the enemy
		cout << enemy.getName() << " health: " << enemy.getHealth() << endl;
		//waits for user input before clearing screen
		system("pause");
		system("cls");

		//checks if enemy is still alive
		if (enemy.getHealth() <= 0) {
			//tells the user that the enemy has been defeated
			cout << "Congratulations! You defeated the " << enemy.getName() << "!" << endl;
			//breaks out of the attack sequence while loop
			break;
		}

		// Enemy's turn
		//attack has been generated before, so it only prints out the attack name
		cout << enemy.getName() << " used " << enemyAttack.getName() << "!" << endl;
		//sets player health equal to their current health minus the damage multiplier on the enemy times their damage stat minus the defense stat of the player times the defense multiplier of their attack
		player.setHealth(int(player.getHealth() - (enemyAttack.getDamageMultiplier() * enemy.getDamage() - player.getDefense() * playerAttack.getDefenseMultiplier())));
		//prints out the current player health
		cout << player.getName() << " health: " << player.getHealth() << endl;
		//waits for user input before clearing screen
		system("pause");
		system("cls");

		//if player dies, tells the player that he died
		if (player.getHealth() <= 0) {
			cout << "Game over! " << enemy.getName() << " defeated you." << endl;
			//breaks out of the while loop attack sequence
			break;
		}
	}
	//tells the user that the battle is over
	cout << "The Battle has been fought. Go in peace.";
	system("pause");
	system("cls");
}

//This is the manageInventory fuinction, the place where the hoarders get to see what they hoard
void manageInventory() {
	//outputs the user's inventory
	cout << "Welcome to your inventory. Please see what items you have: " << endl;
	cout << inventory.to_string() << endl;
	//pauses and waits for input before continuing to main menu
	system("pause");
	system("cls");
}

//This shop function is still in production, so it says so
void enterShop() {
	cout << "Welcome to the shops, please select what shop you would like to interact with: " << endl;
	cout << "1.Weapons shop" << endl;
	cout << "2.Armor shop" << endl;
	cout << "3.Potion shop" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		//player interacts with weaponsShop
		weaponsShop.interact(player, inventory);
	}
	else if (choice == 2) {
		//player interacts with armorShop
		armorShop.interact(player, inventory);
	}
	else if (choice == 3) {
		//player interacts with potionShop
		potionShop.interact(player, inventory);
	}
}

//This chat function is still in production, so it says so
void chat() {
	cout << "Sorry, there are no people to chat to yet." << endl;
}

//This function prints a message to tell the user that it is leaving the menu selection
//Also warns that the game itself is not yet set up
void quitGame() {
	cout << "Leaving the menu selection, but the game has not yet been set up." << endl;
}