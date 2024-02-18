//This entire game is still getting made, so update each function accordingly, as time progresses
//This menu is only a development menu for the time being

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

//THIS IS THE LIBRARY TO INCLUDE IN ORDER TO WIPE SCREEN (USE system("cls"); IN ORDER TO CLEAR THE SCREEN)
#include <stdlib.h>

using namespace std;


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

//This overworld function is still in production, so it says so
void returnToOverworld() {
	cout << "Sorry, it appears that the overworld is still in development." << endl;
}

//This enterBattle function is still in production, so it says so
void enterBattle() {
	cout << "Sorry, it appears that battles are not yet able to be fought." << endl;
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