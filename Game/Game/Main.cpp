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
#include "talker.h"
#include "ShopNode.h"
#include "YearNode.h"
#include "battleNode.h"

//THIS IS THE LIBRARY TO INCLUDE IN ORDER TO WIPE SCREEN (USE system("cls"); IN ORDER TO CLEAR THE SCREEN)
#include <stdlib.h>

using namespace std;

//will contain all of the enemy presidents
vector <Enemy> enemyPresidents;

//this is the player's inventory for game start up
Inventory inventory;

//this is the player
Player player(0, 0, 0, "", 0.0, 0);

YearNode seventeenNinety;
YearNode eighteenSixty;
YearNode nineteenForty;
YearNode eighteenFifty;
YearNode twentyThirty;

//George washington will be the first ruler in the game, so he will have the weakest stats
//Health = 100; attack = 5; deffense = 5; name = "George Washington"; fame = 5; year = 1795
Enemy georgeWashington(100, 5, 5, "George Washington", 5, 1795);


Enemy abrahamLincoln(500, 25, 25, "Abraham Lincoln", 25, 1860);


Enemy FDR(800, 40, 40, "FDR", 40, 1940);


//Millard Filmore will be the last ruler in the game, so he will have the strongest stats
//Health = 1100; attack = 60; deffense = 60; name = "Millard Filmore"; fame = 60; year = 1850
Enemy millardFilmore(1100, 60, 60, "Millard Filmore", 60, 1850);

//initializes weaponsShop
ShopNode hawaii("Hawaii");
//makes 3 different items
//the stats are: health, damage, defense, fame, name, year, kind, and price 
Item nuke(-0.75, 100., 0., 100., "Nuke", 1947, "Weapon", 1000.);
Item gun(0.0, 10.0, 0.3, 0.0, "Gun", 1905, "Weapon", 25.);
Item pen(0., 5.0, 3.0, 10., "Pen", 1805, "Weapon", 1);

//initializes armorShop
ShopNode california("California");
//makes 3 different items
//the stats are: health, damage, defense, fame, name, year, kind, and price 
Item logs(0., 0.5, 10., 0., "Log", 1860, "Armor", 5.25);
Item counterEspionage(0, 0.0, 30.0, -20.0, "Counter Espionage", 1955, "Armor", 100.);
Item teddyBear(.5, 2.0, 5.0, 0., "Teddy Bear", 1905, "Armor", 30);

//makes potionShop
ShopNode russia("Russia");
//makes 3 different items
//the stats are: health, damage, defense, fame, name, year, kind, and price 
Item damagePotion(0., 1., 0., 0., "Damage Potion", 0, "Potion", 2.);
Item defensePotion(0, 0.0, 1.0, 0.0, "Defense Potion", 0, "Potion", 2.);
Item healthPotion(1., 0.0, 0.0, 0., "Health Potion", 0., "Potion", 2.);

//contains all the talkers
vector <talker> talkingNPCs;

battleNode virginia;
battleNode germany;
battleNode mexico;
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

	seventeenNinety.move();
	
	//Selection is the number of choice that the user does, from 1 to 6 being accounted for; it set equal to zero before any choice has been made
	int selection = 0;

	/*//repeats the menu until the player chooses 6, which makes the player leave the game
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

	}*/
	return 0;
}

//Any startup function will be called here
void startup()
{
	//generates the player with his desired president choice
	player = Player::generatePlayer();

	//puts all 3 items into the potionShop
	hawaii.pushback(nuke);
	hawaii.pushback(gun);
	hawaii.pushback(pen);

	//puts all 3 items into the potionShop
	california.pushback(logs);
	california.pushback(counterEspionage);
	california.pushback(teddyBear);

	//FDR will be the eigth ruler in the game, so he will have the eigth weakest stats
	//Health = 800; attack = 45; deffense = 45; name = "FDR"; fame = 45; year = 1940
	FDR.addAttack(Attack(10.0, 1.0, "I will be your president.....forever!!!!!!!!"));
	FDR.addAttack(Attack(7.5, 2.5, "You literally can't get rid of me......"));
	FDR.addAttack(Attack(5.0, 7.5, "I'll throw you into WWII and blame the whole thing on you!"));


	//puts all 3 items into the potionShop
	russia.pushback(damagePotion);
	russia.pushback(defensePotion);
	russia.pushback(healthPotion);

	//instantiates the 2 talking NPCs
	talkingNPCs = talker::initialize();
	seventeenNinety.setChatter(&talkingNPCs[0]);
	twentyThirty.setChatter(&talkingNPCs[1]);



	//George washington will be the first ruler in the game, so he will have the weakest stats
	//Health = 100; attack = 5; deffense = 5; name = "George Washington"; fame = 5; year = 1795
	georgeWashington.addAttack(Attack(10.0, 1.0, "LEADIN MURICA!!!"));
	georgeWashington.addAttack(Attack(7.5, 2.5, "marry a rich widow!!!"));
	georgeWashington.addAttack(Attack(5.0, 7.5, "bite with ivory teeth!!!"));


	//Abraham Lincoln will be the fifth ruler in the game, so he will have the fifth weakest stats
	//Health = 500; attack = 25; deffense = 25; name = "Abraham Lincoln"; fame = 25; year = 1860
	abrahamLincoln.addAttack(Attack(10.0, 1.0, "Freed your slaves!!!"));
	abrahamLincoln.addAttack(Attack(7.5, 2.5, "delivered a lethal adress!!"));
	abrahamLincoln.addAttack(Attack(5.0, 7.5, "taller than you!!!"));


	//Millard Filmore will be the last ruler in the game, so he will have the strongest stats
	//Health = 1100; attack = 60; deffense = 60; name = "Millard Filmore"; fame = 60; year = 1850
	millardFilmore.addAttack(Attack(10.0, 1.0, "the worst campaign slogan ever : No fame, no gain, that's the Millard Fillmore way"));
	millardFilmore.addAttack(Attack(7.5, 2.5, "mid looks"));
	millardFilmore.addAttack(Attack(5.0, 7.5, "the worst name job ever"));

	inventory.pushback(nuke);
	inventory.pushback(gun);
	inventory.pushback(pen);
	inventory.pushback(logs);
	inventory.pushback(counterEspionage);
	inventory.pushback(teddyBear);
	inventory.pushback(damagePotion);
	inventory.pushback(defensePotion);
	inventory.pushback(healthPotion);

	seventeenNinety.setValues(nullptr, &eighteenSixty, nullptr, 1790, &georgeWashington, &talkingNPCs[0], nullptr, &player, &inventory);
	eighteenSixty.setValues(&seventeenNinety, &nineteenForty, &russia, 1860, &abrahamLincoln, nullptr, &virginia, &player, &inventory);
	nineteenForty.setValues(&eighteenSixty, &eighteenFifty, &hawaii, 1940, &FDR, nullptr, &germany, &player, &inventory);
	eighteenFifty.setValues(&nineteenForty, &twentyThirty, &california, 1850, &millardFilmore, nullptr, &mexico, &player, &inventory);
	twentyThirty.setValues(&eighteenFifty, nullptr, nullptr, 2030, nullptr, &talkingNPCs[1], nullptr, &player, &inventory);

	hawaii.setValues("Hawaii", "Welcome to Hawaii. A place where the only thing that beats the sand and the beach is the bombs from the Japanesse.", 1940, 10, &nineteenForty, &player, &inventory, &germany);
	california.setValues("California", "Welcome to California boy. I hope that you're ready to strike it rich.", 1850, 3, &eighteenFifty, &player, &inventory, &mexico);
	russia.setValues("Russia", "Welcome to Russia comrade. We, the people of Russia, the free men of the glorious kingdom.", 1860, 7, &eighteenSixty, &player, &inventory, &virginia);

	virginia.setValues(&eighteenSixty, "Welcome to the glorious country of the Confederate States of America. We do not take kindly to the Union sympathizers.", "Virginia", &player, &russia);
	germany.setValues(&nineteenForty, "Welcome to the land of the chosen race. The land of the glorious Kaiser. If you do not agree with our ways, it is time for you to die.", "Nazi Germany", &player, &hawaii);
	mexico.setValues(&eighteenFifty, "Bienvenido a Mexico gringo. Aca tenemos muchos tacos y muerte para los Americanos de mierda.", "Mexico", &player, &california);
}

//This overworld function is still in production, so it says so
void returnToOverworld() {
	cout << "Sorry, it appears that the overworld is still in development." << endl;
}
/*
//This enterBattle function, the arena whwere battles are fought
void enterBattle() {
	if (player.getHealth() <= 0) {
		cout << "You are already dead. You did not live to fight another fight."<<endl;
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
	while (player.getHealth() > 0 && enemy.getHealth() > 0) {
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
		Attack playerAttack = player.chooseAttack();
		//prints out what attack the player chose
		cout << player.getName() << " used " << playerAttack.getName() << "!" << endl;

		//sets enemy health equal to their current health minus the damage multiplier on the player times their damage stat minus the defense stat of the enemy times the defense multiplier of their attack
		if (int(enemy.getHealth() - (playerAttack.getDamageMultiplier() * player.getDamage() - enemy.getDefense() * enemyAttack.getDefenseMultiplier())) < enemy.getHealth()) {
			enemy.setHealth(int(enemy.getHealth() - (playerAttack.getDamageMultiplier() * player.getDamage() - enemy.getDefense() * enemyAttack.getDefenseMultiplier())));
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
			player.setFame(player.getFame() + enemy.getFame());
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
			if (int(player.getHealth() - (enemyAttack.getDamageMultiplier() * enemy.getDamage() - player.getDefense() * playerAttack.getDefenseMultiplier())) < player.getHealth()) {
				player.setHealth(int(player.getHealth() - (enemyAttack.getDamageMultiplier() * enemy.getDamage() - player.getDefense() * playerAttack.getDefenseMultiplier())));
			}
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
	cout << inventory.makeString() << endl;

	if (inventory.getSize() == 0) {
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
	inventory.setCurrent(choice + 1);

	cout << "How many would you like to use: ";
	int amount;
	cin >> amount;
	if (inventory.getCurrent()->getAmount() >= amount) {
		player.setDamage(player.getDamage()+player.getDamage()*inventory.getCurrent()->getDamageEffect());
		player.setHealth(player.getHealth() + player.getHealth() * inventory.getCurrent()->getHealthEffect());
		player.setDefense(player.getDefense() + player.getDefense() * inventory.getCurrent()->getDefenseEffect());
		player.setFame(player.getFame() + player.getFame() * inventory.getCurrent()->getFameEffect());
		inventory.getCurrent()->setAmount(inventory.getCurrent()->getAmount() - amount);
		//tells the user that the thing he selected is being sold
		cout << "Using " << inventory.getCurrent()->getName() << endl;
	}
	else {
		cout << "You do not own that item. Do not try to use something that you do not own, you scoundrel." << endl;
	}

	system("pause");
	system("cls");
}

//This shop function is still in production, so it says so
void enterShop() {
	cout << "Welcome to the shops, please select what shop you would like to interact with: " << endl;
	cout << "1.Weapons shop" << endl;
	cout << "2.Armor shop" << endl;
	cout << "3.Potion shop" << endl;
	cout << "Enter any other number to return to the home screen." << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		//player interacts with weaponsShop
		hawaii.interact(player, inventory);
	}
	else if (choice == 2) {
		//player interacts with armorShop
		california.interact(player, inventory);
	}
	else if (choice == 3) {
		//player interacts with potionShop
		russia.interact(player, inventory);
	}
}


void chat() {
	cout << "Who would you like to speak to today: " << endl;
	cout << "1.Begining dude" << endl;
	cout << "2.End dude" << endl;
	cout << "Enter any other number to return to the home screen." << endl;
	int choice;
	cin >> choice;
	if (choice == 1 || choice == 2) {
		//player interacts with weaponsShop
		talker speaker = (talkingNPCs[(choice - 1)]);
		speaker.talk(0);
	}
}

//This function prints a message to tell the user that it is leaving the menu selection
//Also warns that the game itself is not yet set up
void quitGame() {
	cout << "Leaving the menu selection, but the game has not yet been set up." << endl;
}
*/
