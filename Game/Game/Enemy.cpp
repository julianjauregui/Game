
//Imlementation of the Character class, from the Character.h file
#include "Enemy.h"

//generates random enemy.  takes nothing in, creates an enemy with randiomly selected name, randomizes other character stats
static Enemy generateEnemy() 
{
    std::string names[] = { "Goblin", "Skeleton", "Orc", "Troll" };
    int index = rand() % 4;
    return Enemy(names[index], rand() % 20 + 10, rand() % 5 + 5); //not right, needs to reflect the right stats that apply to character.  dummy names are being used at present.  implement thenright constructor too
}

//function that overides virtual function in character. enemy randomly chooses his own attack!!!!!
Attack chooseAttack() override {
    // Enemy chooses a random attack
    int choice = rand() % specialAttacks.size();
    return specialAttacks[choice];
}
