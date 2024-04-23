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

void Shop::interact(Player& user, Inventory& list)
{
	//Selection is the number of choice that the user does, from 1 to 3 being accounted for; it set equal to zero before any choice has been made
	int selection = 0;


	//already initializes item that will be bought outside of while loop
	Item* bought;

	//repeats the menu until the player chooses 3, which makes the player leave the shop
	while (selection != 4) {

		//Prints out the main menu choices, with each option being its own line
		cout << "Welcome to " + type + ". Pick what you would like to do: " << endl;
		cout << "1. Buy." << endl;
		cout << "2. Sell." << endl;
		cout << "3. View your current fame (money value)" << endl; 
		cout << "4. Leave." << endl;
		//Enters the selection from the user of what function they want to call
		cin >> selection;


		//Switch case with the user-inputted selection as the main variable being checked
		switch (selection) {

			//The first case is the buy function, which returns lets the user buy things
		case 1:
			//clears screen and then calls buy
			system("cls");
			//user buys
			buy(user);
			break;

			//The second option is the sell function, which is called to sell an item
		case 2:
			//clears screen and then calls sell
			system("cls");
			sell(list, user);
			break;

		case 3:
			cout << user.getFame() << endl;
			system("pause");
			system("cls");
			break;
			//The fourth option is the inventory function, that is called to manage and change and view the player's inventory
		case 4:
			//clears screen and then calls manage inventory
			system("pause");
			system("cls");

			break;

			//If something other than 1-6 was entered, it displays that the option was invalid and it returns to the main menu selection at the top
		default:
			//doesn't clear screen because the user should be able to see that his input was incorrect so as to not repeat it
			cout << "The selection you chose was invalid. Please choose again." << endl;

		}

	}
}

string Shop::toString()
{
	//if the list is empty, it says so
	if (size == 0) {
		return "The inventory is currently empty, go buy some things to make it bigger.";
	}
	//makes a temporary iterator item that is starts at first
	Item* iterator = first;
	//makes a string called list that is empty but will have all the info later on
	std::string list = "";

	//while the list is not at the end
	for (int pos = 0; pos < size; pos++) {
			list += (pos + 1);
			//adds a coma before adding all the information of the item
			list += to_string(pos + 1) + ", " + iterator->toString() + '\n';
			//sets iterator to the next iterator
			iterator = iterator->getNextItem();
			
	}

	//returns the string output
	return list;
	
}

//helper function for interact
void Shop::buy(Player user)
{
	//welcomes the user into the shop
    cout << "Welcome to the " + type + " shop. What would you like to buy: "<<endl;
	//prints out shop contents
    cout << toString();
	//starts the choice for what the user will pick at 0
    int choice = 0;

	//while no valid choice has been made
    while (choice <= 0 || choice > size) {
		//tells the user to pick what item they want
        cout << "Enter the number next to the thing that you would like to buy: ";
		//user enters their choice
        cin >> choice;

		//if the user does not have a valid choice
		if (choice <= 0 || choice > size) {
			//tells them that they have not made a valid choice
			cout << "Please choose a valid number: " << endl;
		}
    }

	//sets current index to choice, since that is the number that they have chosen
    setCurrent(choice);

	cout << "How many would you like to buy: ";
	int amount;
	cin >> amount;
	if (getCurrent()->getCost() * amount <= user.getFame()) {
		user.setFame(user.getFame() - getCurrent()->getCost() * amount);
		getCurrent()->setAmount(getCurrent()->getAmount() + amount);
	}
	else {
		cout << "You really are too poor. Leave my sight.";
	}
}

//helper function for interaction
void Shop::sell(Inventory& possessions, Player user)
{
	//checks to see if inventroy is empty before selling things
	if (possessions.getSize() == 0) {
		cout << "Your inventory is currenlty empty. You have nothing to sell." << endl;
		return;
	}
	//displays all of user inventory's contents and welcomes them to shop
    cout << "Welcome to the " + type + " shop. What would you like to sell: "<<endl;
    cout << possessions.makeString();
	//starts the choice for what the user will pick at 0
    int choice = 0;

	//while no valid choice has been made
    while (choice <= 0 || choice > 9) {
		//tells the user to pick what item they want
        cout << "Enter the number next to the thing that you would like to sell: ";
		//user enters their choice
        cin >> choice;

		//if the user does not have a valid choice
		if (choice <= 0 || choice > 9) {
			//tells the user that they have not yet made a valid choice
			cout << "Please choose a valid number: " << endl;
		}
    }

	//sets current index of user's inventory to choice
    possessions.setCurrent(choice+1);

	cout << "How many would you like to sell: ";
	int amount;
	cin >> amount;
	if (possessions.getCurrent()->getAmount() >= amount) {
		user.setFame(user.getFame() + getCurrent()->getCost() * amount);
		getCurrent()->setAmount(getCurrent()->getAmount() - amount);

		//tells the user that the thing he selected is being sold
		cout << "Selling " << possessions.getCurrent()->getName() << endl;
	}
	else {
		cout << "You do not own that item. Do not try to sell something that you do not own, you thief."<<endl;
	}

	system("pause");
	system("cls");
}