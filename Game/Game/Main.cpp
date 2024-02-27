//This entire game is still getting made, so update each function accordingly, as time progresses
//This menu is only a development menu for the time being
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

//THIS IS THE LIBRARY TO INCLUDE IN ORDER TO WIPE SCREEN (USE system("cls"); IN ORDER TO CLEAR THE SCREEN)
#include <stdlib.h>

using namespace std;

//will contain all of the enemy presidents
vector <Enemy> enemyPresidents;

//this is the player
Player player(0,0,0,"",0,0);

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
		cout << "\n\nhello world\n\n";
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
}

//This overworld function is still in production, so it says so
void returnToOverworld() {
	cout << "Sorry, it appears that the overworld is still in development." << endl;
}

//This enterBattle function is still in production, so it says so
void enterBattle() {
	//Player.generatePlayer();
	//Enemy.generateEnemy();

	// Create player and enemy, add attacks
	//Player Player(100,100,100,"Dwight Eisenhower", 75);
	//Enemy Enemy(100,100,100,"George Washington", 99);

	//std::cout << "A wild " << enemy.name << " appeared!" << std::endl;

	//while (Player.health > 0 && Enemy.health > 0) {
		// Player's turn
		//Attack playerAttack = Player.chooseAttack();
		//std::cout << Player.name << " used " << playerAttack.name << "!" << std::endl;
		//Enemy.health -= playerAttack.damage;
		//std::cout << Enemy.name << " health: " << Enemy.health << std::endl;

		//if (Enemy.health <= 0) {
			//std::cout << "Congratulations! You defeated the " << Enemy.name << "!" << std::endl;
			//break;
		//}

		// Enemy's turn
		//Attack enemyAttack = Enemy.chooseAttack();
		//std::cout << Enemy.name << " used " << enemyAttack.name << "!" << std::endl;
		//player.health -= enemyAttack.damage;
		//std::cout << Player.name << " health: " << Player.health << std::endl;

		//if (Player.health <= 0) {
			//std::cout << "Game over! " << Enemy.name << " defeated you." << std::endl;
			//break;
		//}
	//}

	//return 0;
	// 
	//Enter battle is not yet ready
	cout << "Enter battle is currently faulty, and is under construction still. Sorry";
}

//This manage inventory function is still in production, so it says so
void manageInventory() {
	cout << "Sorry, it appears that your inventory has not yet been developed." << endl;
}

//This shop function is still in production, so it says so
void enterShop() {
	cout << "Sorry, it appears that no shops have been developed yet." << endl;
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