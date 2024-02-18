
//Imlementation of the Character class, from the Character.h file
#include "Enemy.h"

//generates random enemy.  takes nothing in, creates an enemy with randiomly selected name, randomizes other character stats
static Enemy generateEnemy() 
{
    std::string names[] = { "George Washington", "Thomas Jefferson", "Andrew Jackson", "James Polk", "Abraham Lincoln", "Theodore Roosevelt", "Woodrow Wilson", "FDR", "Harry Truman", "Dwight Eisenhower", "Millard Fillmore"};
    int index = rand() % 11+1;
    return Enemy(rand() % 100+1, rand() % 100 + 1, rand() % 100 + 1, ames[index], rand() % 100 + 1); //not right, needs to reflect the right stats that apply to character.  dummy names are being used at present.  implement thenright constructor too
}

//function that overides virtual function in character. enemy randomly chooses his own attack!!!!!
Attack chooseAttack() override {
    // Enemy chooses a random attack
    int choice = rand() % specialAttacks.size();
    return specialAttacks[choice];
}
