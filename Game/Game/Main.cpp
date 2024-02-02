#include <iostream>

using namespace std;

void returnToOverworld();

void enterBattle();

void manageInventory();

void enterShop();

void chat();

void quitGame();


int main() {
	int selection = 0;
	while (selection != 6) {
		cout << "Welcome to the main Menu. Pick what you would like to do: " << endl;
		cout << "1. Return to Game." << endl;
		cout << "2. Enter Battle." << endl;
		cout << "3. Manage Inventory." << endl;
		cout << "4. Enter shop." << endl;
		cout << "5.Talk to Someone." << endl;
		cout << "6. Quit Game." << endl;
		cout << "Pick your selection: ";
		cin >> selection;

		switch (selection) {
		case 1:
			returnToOverworld();
			break;
		case 2:
			enterBattle();
			break;
		case 3:
			manageInventory();
			break;
		case 4:
			enterShop();
			break;
		case 5:
			chat();
			break;
		case 6:
			quitGame();
			break;
		default:
			cout << "The selection you chose was invalid. Please choose again." << endl;

		}

	}
	return 0;
}

void returnToOverworld() {
	cout << "Sorry, it appears that the overworld is still in development." << endl;
}

void enterBattle() {
	cout << "Sorry, it appears that battles are not yet able to be fought." << endl;
}

void manageInventory() {
	cout << "Sorry, it appears that your inventory has not yet been developed." << endl;
}

void enterShop() {
	cout << "Sorry, it appears that no shops have been developed yet." << endl;
}

void chat() {
	cout << "Sorry, there are no people to chat to yet." << endl;
}

void quitGame() {
	cout << "Leaving the menu selection, but the game has not yet been set up." << endl;
}