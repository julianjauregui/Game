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
int Character::getFame()
{
    return fame;
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
void Character::setFame(int influence)
{
    fame = influence;
}




