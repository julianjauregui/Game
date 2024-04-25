//Imlementation of the Character class, from the Character.h file
#include "Character.h"

//Getter for health, returns health
int Character::getHealth()
{
    return health;
}

//Getter for damage, returns damage
int Character::getDamage()
{
    return damage;
}

//Getter for defense, returns defense
int Character::getDefense()
{
    return defense;
}

//Getter for name, returns name
string Character::getName()
{
    return name;
}

//Getter for fame, returns fame
double Character::getFame()
{
    return fame;
}

//Returns attacks from Character
vector<Attack> Character::getAttacks()
{
    return attacks;
}

//returns year that the character is in
int Character::getYear()
{
    return year;
}

//Setter for health, sets Health equal to life
void Character::setHealth(int life)
{
    health = life;
}

//Setter for damage, sets damage equal to attack
void Character::setDamage(int attack)
{
    damage = attack;
}

//Setter for damage, sets defense equal to def
void Character::setDefense(int def)
{
    defense = def;
}

//Setter for damage, sets name equal to nomen
void Character::setName(string nomen)
{
    name = nomen;
}

//Setter for damage, sets fame equal to influence
void Character::setFame(double influence)
{
    fame = influence;
}

//sets attacks equal to moves input and returns nothing
void Character::setAttacks(vector<Attack> moves)
{
    attacks = moves;
}

//sets year equal to anno
void Character::setYear(int anno)
{
    year = anno;
}


//Adds move input to the list of attacks
void Character::addAttack(Attack move)
{
    attacks.push_back(move);
}


//Returns all the information of a character in string form
string Character::toString()
{
    //Creates the basic output string:
    //"$NAME has $HEALTH amount of health and has an attack stat of $DAMAGE and a defense stat of $DEFENSE. His attacks are as follows: 
    string output = name + " has " + to_string(health) + " amount of health " + " and has an attack stat of " + to_string(damage) + " and a defense stat of " + to_string(defense) + " as well as a fame stat of " + to_string(fame) + ". His attacks are as follows: ";
    //Adds attacks to output
    output += printAttacks();
    return output;
}

//Returns all the attacks with each attack on its own line
string Character::printAttacks()
{
    //sets output to empty string
    string output = "";
    //uses counter to print out the number next to the attack
    int counter = 1;
    //iterates through every attack in attacks
    for (Attack index : attacks) {
        //uses the toString functions for attacks and adds that to output
        output += '\n' + to_string(counter) + ". " + index.toString(damage, defense);
        //increments the counter by one
        counter++;
    }
    //returns output
    return output;
}
//Implemented separately for the enemy and character classes
Attack Character::chooseAttack()
{
    return Attack(0,0,"Not a real attack");
}


