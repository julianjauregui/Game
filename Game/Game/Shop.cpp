#include "Shop.h"

//inputs nothing and returns string type
string Shop::getType()
{
    return type;
}

//inputs string kind and returns nothing
void Shop::setType(string kind)
{
    //sets type equal to kind
    type = kind;
}

void Shop::interact(Player& user)
{
	//Selection is the number of choice that the user does, from 1 to 3 being accounted for; it set equal to zero before any choice has been made
	int selection = 0;

	//repeats the menu until the player chooses 3, which makes the player leave the shop
	while (selection != 3) {

		//Prints out the main menu choices, with each option being its own line
		cout << "Welcome to the" + type + " shop.Pick what you would like to do: " << endl;
		cout << "1. Buy." << endl;
		cout << "2. Sell." << endl;
		cout << "3. Leave." << endl;
		//Enters the selection from the user of what function they want to call
		cin >> selection;

		//Switch case with the user-inputted selection as the main variable being checked
		switch (selection) {

			//The first case is the overworld function, which returns to the overworld
		case 1:
			//clears screen and then calls overworld function
			system("cls");
			buy();
			break;

			//The second option is the enter battle function, which is called to enter and fight a battle
		case 2:
			//clears screen and then calls enter battle function
			system("cls");
			//sell();
			break;

			//The third option is the inventory function, that is called to manage and change and view the player's inventory
		case 3:
			//clears screen and then calls manage inventory
			break;

			//If something other than 1-6 was entered, it displays that the option was invalid and it returns to the main menu selection at the top
		default:
			//doesn't clear screen because the user should be able to see that his input was incorrect so as to not repeat it
			cout << "The selection you chose was invalid. Please choose again." << endl;

		}

	}
}

Item Shop::buy()
{
    cout << "Welcome to the " + type + " shop. What would you like to buy: ";
    cout << to_string();
    int choice = 0;
    while (choice <= 0 || choice > size()) {
        cout << "Enter the number next to the thing that you would like to buy: ";
        cin >> choice;
    }
    setCurrent(choice);
    return getCurrent();
}

double Shop::sell(Inventory& possessions)
{
    cout << "Welcome to the " + type + " shop. What would you like to sell: ";
    cout << possessions.to_string();
    int choice = 0;
    while (choice <= 0 || choice > possessions.size()) {
        cout << "Enter the number next to the thing that you would like to buy: ";
        cin >> choice;
    }
    possessions.setCurrent(choice);
    int cost = possessions.getCurrent().getCost();
    deleteCurrent();
    return cost;
}
