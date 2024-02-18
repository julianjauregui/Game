#include "Player.h"
//players functions will be here
//function that overides virtual function in character
Attack chooseAttack() override {
    displayAttacks();

    int choice;
    std::cout << "Choose an attack (1-" << specialAttacks.size() << "): ";
    std::cin >> choice;

    if (choice >= 1 && choice <= specialAttacks.size()) {
        return specialAttacks[choice - 1];
    }
    else {
        // Default to basic attack
        std::cout << "Invalid choice. Using basic attack." << std::endl;
        return Attack("Basic Attack", 10);
    }
}

//generates random enemy.  takes nothing in, creates an enemy with randiomly selected name, randomizes other character stats
static Player generatePlayer()
{
    std::string names[] = { "Joe Biden", "Donald Trump", "Barack Obama", "George W. Bush", "Bill 'Slick Willy' Clinton", "George H.W. Bush", "Ronald Reagan", "James Carter", "Gerald Ford", "Richard Nixon"};
    int index = rand() % 10 + 1;
    return Player(rand() % 100 + 1, rand() % 100 + 1, rand() % 100 + 1, ames[index], rand() % 100 + 1); //not right, needs to reflect the right stats that apply to character.  dummy names are being used at present.  implement thenright constructor too
}