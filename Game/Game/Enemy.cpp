
//Imlementation of the Character class, from the Character.h file
#include "Enemy.h"

//COULD BE A POTENTIAL BUG HERE IF OVERRIDE DOES NOT WORK PROPERLY
//function that overides virtual function in character. enemy randomly chooses his own attack!!!!!
Attack Enemy::chooseAttack(){
    // Enemy chooses a random attack
    int choice = rand() % specialAttacks.size();
    return specialAttacks[choice];
}

void Enemy::makeBosses()
{
    Enemy georgeWashington(100, 5, 5, "George Washington", 5, 1795);
    georgeWashington.addAttack(Attack(100, 75, "LEADIN MURICA!!!"));
    georgeWashington.addAttack(Attack(75, 25, "marry a rich widow!!!"));
    georgeWashington.addAttack(Attack(50, 10, "bite with ivory teeth!!!"));
    
    Enemy thomasJefferson(100, 10, 10, "Thomas Jefferson", 10, 1805);
    thomasJefferson.addAttack(Attack(100, 75, "Writing the declaration of independence!!"));
    thomasJefferson.addAttack(Attack(75, 25, "treating my slaves better than most!!!"));
    thomasJefferson.addAttack(Attack(50, 10, "don't fight..just write!! then fight"));

    Enemy andrewJackson(100, 15, 15, "Andrew Jackson", 15, 1835);
    andrewJackson.addAttack(Attack(100, 75, "Rage!!! smashed with a liquor bottle"));
    andrewJackson.addAttack(Attack(75, 25, "racism!!! get movin ya red skins"));
    andrewJackson.addAttack(Attack(50, 10, "unexpected party in the white house!!"));
    

    Enemy jamesPolk(100, 20, 20, "James Polk", 20, 1845);
    jamesPolk.addAttack(Attack(100, 75, "lethal cross examination!!!"));
    jamesPolk.addAttack(Attack(75, 25, "expanding the country!!!"));
    jamesPolk.addAttack(Attack(50, 10, "sneaky influence"));

    Enemy abrahamLincoln(100, 25, 25, "Abraham Lincoln", 25, 1860);
    abrahamLincoln.addAttack(Attack(100, 75, "Freed your slaves!!!"));
    abrahamLincoln.addAttack(Attack(75, 25, "delivered a lethal adress!!"));
    abrahamLincoln.addAttack(Attack(50, 10, "taller than you!!!"));

    Enemy theodoreRoosevelt(100, 30, 30, "Theodore Roosevelt", 30, 1905);
    theodoreRoosevelt.addAttack(Attack(100, 75, "HIT WITH A BIG BIG BIG STICK"));
    theodoreRoosevelt.addAttack(Attack(75, 25, "speaking softly"));
    theodoreRoosevelt.addAttack(Attack(50, 10, "Back with a new party!!!"));

    Enemy woodrowWilson(100, 35, 35, "Woodrow Wilson", 35, 1915);
    woodrowWilson.addAttack(Attack(100, 75, "I will reluctantly throw you into WWI and blame you for the war."));
    woodrowWilson.addAttack(Attack(75, 25, "BLATANT SEXISM"));
    woodrowWilson.addAttack(Attack(50, 10, "HATE FOR CATHOLICS"));

    Enemy FDR(100, 40, 40, "FDR", 40, 1940);
    FDR.addAttack(Attack(100, 75, "I will be your president.....forever!!!!!!!!"));
    FDR.addAttack(Attack(75, 25, "You literally can't get rid of me......"));
    FDR.addAttack(Attack(50, 10, "I'll throw you into WWII and blame the whole thing on you!"));

    Enemy harryTruman(100, 45, 45, "Harry Truman", 45, 1947);
    harryTruman.addAttack(Attack(100, 75, "NUKED"));
    harryTruman.addAttack(Attack(75, 25, "I look nerdier than you!!!"));
    harryTruman.addAttack(Attack(50, 10, "I might scare you with red or freeze you with a cold war.....heck i might nuke you"));

    Enemy dwightEisenhower(100, 50, 50, "Dwight Eisenhower", 50, 1955);
    dwightEisenhower.addAttack(Attack(100, 75, "I replace you with a highway system!!"));
    dwightEisenhower.addAttack(Attack(75, 25, "My name is literally DWIGHT, I am part of the greatest generation, I fought in WWII, I made the highway system as you know it, I could go on..."));
    dwightEisenhower.addAttack(Attack(50, 10, "You deal with the Korean War!!"));

    Enemy millardFilmore(100, 60, 60, "Millard Filmore", 60, 1850);
    millardFilmore.addAttack(Attack(100, 50, "the worst campaign slogan ever : No fame, no gain, that's the Millard Fillmore way"));
    millardFilmore.addAttack(Attack(75, 25, "mid looks"));
    millardFilmore.addAttack(Attack(50, 10, "the worst name job ever"));
}

//generates random enemy.  takes nothing in, creates an enemy with randiomly selected name, randomizes other character stats
Enemy Enemy::generateEnemy() 
{
    std::string names[] = { "George Washington", "Thomas Jefferson", "Andrew Jackson", "James Polk", "Abraham Lincoln", "Theodore Roosevelt", "Woodrow Wilson", "FDR", "Harry Truman", "Dwight Eisenhower", "Millard Fillmore"};
    int index = rand() % 11+1;
    Enemy newEn(rand() % 100+1, rand() % 100 + 1, rand() % 100 + 1, names[index], rand() % 100 + 1, rand() % 100 + 1); //not right, needs to reflect the right stats that apply to character.  dummy names are being used at present.  implement the right constructor too
    //use conditional statements to see which enemy is selected, give each enemy his own attacks, //you have to use setters to add special attacks
    if (names[index] == "George Washington")
    {
        newEn.addAttack(Attack(100, 75, "LEADIN MURICA!!!"));
        newEn.addAttack(Attack(75, 25, "marry a rich widow!!!"));
        newEn.addAttack(Attack(50, 10, "bite with ivory teeth!!!"));
    }

    if (names[index] == "Thomas Jefferson")
    {
        newEn.addAttack(Attack(100, 75, "Writing the declaration of independence!!"));
        newEn.addAttack(Attack(75, 25, "treating my slaves better than most!!!"));
        newEn.addAttack(Attack(50, 10, "don't fight..just write!! then fight"));
    }

    if (names[index] == "Andrew Jackson")
    {
        newEn.addAttack(Attack(100, 75, "Rage!!! smashed with a liquor bottle"));
        newEn.addAttack(Attack(75, 25, "racism!!! get movin ya red skins"));
        newEn.addAttack(Attack(50, 10, "unexpected party in the white house!!"));
    }

    if (names[index] == "James Polk")
    {
        newEn.addAttack(Attack(100, 75, "lethal cross examination!!!"));
        newEn.addAttack(Attack(75, 25, "expanding the country!!!"));
        newEn.addAttack(Attack(50, 10, "sneaky influence"));
    }

    if (names[index] == "Abraham Lincoln")
    {
        newEn.addAttack(Attack(100, 75, "Freed your slaves!!!"));
        newEn.addAttack(Attack(75, 25, "delivered a lethal adress!!"));
        newEn.addAttack(Attack(50, 10, "taller than you!!!"));
    }

    if (names[index] == "Theodore Roosevelt")
    {
        newEn.addAttack(Attack(100, 75, "HIT WITH A BIG BIG BIG STICK"));
        newEn.addAttack(Attack(75, 25, "speaking softly"));
        newEn.addAttack(Attack(50, 10, "Back with a new party!!!"));
    }

    if (names[index] == "Woodrow Wilson")
    {
        newEn.addAttack(Attack(100, 75, "I will reluctantly throw you into WWI and blame you for the war."));
        newEn.addAttack(Attack(75, 25, "BLATANT SEXISM"));
        newEn.addAttack(Attack(50, 10, "HATE FOR CATHOLICS"));
    }

    if (names[index] == "FDR")
    {
        newEn.addAttack(Attack(100, 75, "I will be your president.....forever!!!!!!!!"));
        newEn.addAttack(Attack(75, 25, "You literally can't get rid of me......"));
        newEn.addAttack(Attack(50, 10, "I'll throw you into WWII and blame the whole thing on you!"));
    }

    if (names[index] == "Harry Truman")
    {
        newEn.addAttack(Attack(100, 75, "NUKED"));
        newEn.addAttack(Attack(75, 25, "I look nerdier than you!!!"));
        newEn.addAttack(Attack(50, 10, "I might scare you with red or freeze you with a cold war.....heck i might nuke you"));
    }

    if (names[index] == "Dwight Eisenhower")
    {
        newEn.addAttack(Attack(100, 75, "I replace you with a highway system!!"));
        newEn.addAttack(Attack(75, 25, "My name is literally DWIGHT, I am part of the greatest generation, I fought in WWII, I made the highway system as you know it, I could go on..."));
        newEn.addAttack(Attack(50, 10, "You deal with the Korean War!!"));
    }

    if (names[index] == "Dwight Eisenhower")
    {
        newEn.addAttack(Attack(100, 75, "I replace you with a highway system!!"));
        newEn.addAttack(Attack(75, 25, "My name is literally DWIGHT, I am part of the greatest generation, I fought in WWII, I made the highway system as you know it, I could go on..."));
        newEn.addAttack(Attack(50, 10, "You deal with the Korean War!!"));
    }

    if (names[index] == "Millard Fillmore")
    {
        newEn.addAttack(Attack(100, 50, "the worst campaign slogan ever : No fame, no gain, that's the Millard Fillmore way"));
        newEn.addAttack(Attack(75, 25, "mid looks"));
        newEn.addAttack(Attack(50, 10, "the worst name job ever"));
    }


    return newEn;

    }

   
    

   
