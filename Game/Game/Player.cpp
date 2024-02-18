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