
//Imlementation of the Character class, from the Character.h file
#include "Enemy.h"

//COULD BE A POTENTIAL BUG HERE IF OVERRIDE DOES NOT WORK PROPERLY
//function that overides virtual function in character. enemy randomly chooses his own attack!!!!!
Attack Enemy::chooseAttack(){
    // Generates a random seed
    srand(time(NULL));
    //Sets choice to a random index that is in the attack size
    int choice = rand() % attacks.size();
    //Returns that attack
    return attacks[choice];
}

vector<Enemy> Enemy::makeBosses()
{
    //creates the vector that will hold all of the presidents
    vector<Enemy> presidents = {};

    //George washington will be the first ruler in the game, so he will have the weakest stats
    //Health = 100; attack = 5; deffense = 5; name = "George Washington"; fame = 5; year = 1795
    Enemy georgeWashington(100, 5, 5, "George Washington", 5, 1795);
    georgeWashington.addAttack(Attack(10.0, 1.0, "LEADIN MURICA!!!"));
    georgeWashington.addAttack(Attack(7.5, 2.5, "marry a rich widow!!!"));
    georgeWashington.addAttack(Attack(5.0, 7.5, "bite with ivory teeth!!!"));
    //Adds George Washington to the presidents
    presidents.push_back(georgeWashington);

    //Thomas Jefferson will be the second ruler in the game, so he will have the second weakest stats
    //Health = 200; attack = 10; deffense = 10; name = "Thomas Jefferson"; fame = 10; year = 1805
    Enemy thomasJefferson(200, 10, 10, "Thomas Jefferson", 10, 1805);
    thomasJefferson.addAttack(Attack(10.0, 1.0, "Writing the declaration of independence!!"));
    thomasJefferson.addAttack(Attack(7.5, 2.5, "treating my slaves better than most!!!"));
    thomasJefferson.addAttack(Attack(5.0, 7.5, "don't fight..just write!! then fight"));
    //Adds Thomas Jefferson to the presidents
    presidents.push_back(thomasJefferson);

    //Andrew Jackson will be the third ruler in the game, so he will have the third weakest stats
    //Health = 300; attack = 15; deffense = 15; name = "Andrew Jackson"; fame = 15; year = 1835
    Enemy andrewJackson(300, 15, 15, "Andrew Jackson", 15, 1835);
    andrewJackson.addAttack(Attack(10.0, 1.0, "Rage!!! smashed with a liquor bottle"));
    andrewJackson.addAttack(Attack(7.5, 2.5, "racism!!! get movin ya red skins"));
    andrewJackson.addAttack(Attack(5.0, 7.5, "unexpected party in the white house!!"));
    //Adds Andrew Jackson to the presidents
    presidents.push_back(andrewJackson);

    //James Polk will be the fourth ruler in the game, so he will have the fourth weakest stats
    //Health = 400; attack = 20; deffense = 20; name = "James Polk"; fame = 20; year = 1845
    Enemy jamesPolk(400, 20, 20, "James Polk", 20, 1845);
    jamesPolk.addAttack(Attack(10.0, 1.0, "lethal cross examination!!!"));
    jamesPolk.addAttack(Attack(7.5, 2.5, "expanding the country!!!"));
    jamesPolk.addAttack(Attack(5.0, 7.5, "sneaky influence"));
    //Adds James Polk to the presidents
    presidents.push_back(jamesPolk);

    //Abraham Lincoln will be the fifth ruler in the game, so he will have the fifth weakest stats
    //Health = 500; attack = 25; deffense = 25; name = "Abraham Lincoln"; fame = 25; year = 1860
    Enemy abrahamLincoln(500, 25, 25, "Abraham Lincoln", 25, 1860);
    abrahamLincoln.addAttack(Attack(10.0, 1.0, "Freed your slaves!!!"));
    abrahamLincoln.addAttack(Attack(7.5, 2.5, "delivered a lethal adress!!"));
    abrahamLincoln.addAttack(Attack(5.0, 7.5, "taller than you!!!"));
    //Adds Abraham Lincoln to the presidents
    presidents.push_back(abrahamLincoln);

    //Theodore Roosevelt will be the sixth ruler in the game, so he will have the sixth weakest stats
    //Health = 600; attack = 30; deffense = 30; name = "Theodore Roosevelt"; fame = 30; year = 1900
    Enemy theodoreRoosevelt(600, 30, 30, "Theodore Roosevelt", 30, 1905);
    theodoreRoosevelt.addAttack(Attack(10.0, 1.0, "HIT WITH A BIG BIG BIG STICK"));
    theodoreRoosevelt.addAttack(Attack(7.5, 2.5, "speaking softly"));
    theodoreRoosevelt.addAttack(Attack(5.0, 7.5, "Back with a new party!!!"));
    //Adds Theodore Roosevelt to the presidents
    presidents.push_back(theodoreRoosevelt);

    //Woodrow Wilson will be the seventh ruler in the game, so he will have the seventh weakest stats
    //Health = 700; attack = 35; deffense = 35; name = "Woodrow Wilson"; fame = 35; year = 1915
    Enemy woodrowWilson(700, 35, 35, "Woodrow Wilson", 35, 1915);
    woodrowWilson.addAttack(Attack(10.0, 1.0, "I will reluctantly throw you into WWI and blame you for the war."));
    woodrowWilson.addAttack(Attack(7.5, 2.5, "BLATANT SEXISM"));
    woodrowWilson.addAttack(Attack(5.0, 7.5, "HATE FOR CATHOLICS"));
    //Adds Woodrow Wilson to the presidents
    presidents.push_back(woodrowWilson);

    //FDR will be the eigth ruler in the game, so he will have the eigth weakest stats
    //Health = 800; attack = 45; deffense = 45; name = "FDR"; fame = 45; year = 1940
    Enemy FDR(800, 40, 40, "FDR", 40, 1940);
    FDR.addAttack(Attack(10.0, 1.0, "I will be your president.....forever!!!!!!!!"));
    FDR.addAttack(Attack(7.5, 2.5, "You literally can't get rid of me......"));
    FDR.addAttack(Attack(5.0, 7.5, "I'll throw you into WWII and blame the whole thing on you!"));
    //Adds FDR to the presidents
    presidents.push_back(FDR);

    //Harry Truman will be the ninth ruler in the game, so he will have the ninth weakest stats
    //Health = 900; attack = 45; deffense = 45; name = "Woodrow Wilson"; fame = 45; year = 1947
    Enemy harryTruman(900, 45, 45, "Harry Truman", 45, 1947);
    harryTruman.addAttack(Attack(10.0, 1.0, "NUKED"));
    harryTruman.addAttack(Attack(7.5, 2.5, "I look nerdier than you!!!"));
    harryTruman.addAttack(Attack(5.0, 7.5, "I might scare you with red or freeze you with a cold war.....heck i might nuke you"));
    //Adds Harry Truman to the presidents
    presidents.push_back(harryTruman);

    //Dwight Eisenhower will be the tenth ruler in the game, so he will have the tenth weakest stats
    //Health = 1000; attack = 50; deffense = 50; name = "Woodrow Wilson"; fame = 50; year = 1955
    Enemy dwightEisenhower(1000, 50, 50, "Dwight Eisenhower", 50, 1955);
    dwightEisenhower.addAttack(Attack(10.0, 1.0, "I replace you with a highway system!!"));
    dwightEisenhower.addAttack(Attack(7.5, 2.5, "My name is literally DWIGHT, I am part of the greatest generation, I fought in WWII, I made the highway system as you know it, I could go on..."));
    dwightEisenhower.addAttack(Attack(5.0, 7.5, "You deal with the Korean War!!"));
    //Adds Dwight Eisenhower to the presidents
    presidents.push_back(dwightEisenhower);

    //Millard Filmore will be the last ruler in the game, so he will have the strongest stats
    //Health = 1100; attack = 60; deffense = 60; name = "Millard Filmore"; fame = 60; year = 1850
    Enemy millardFilmore(1100, 60, 60, "Millard Filmore", 60, 1850);
    millardFilmore.addAttack(Attack(10.0, 1.0, "the worst campaign slogan ever : No fame, no gain, that's the Millard Fillmore way"));
    millardFilmore.addAttack(Attack(7.5, 2.5, "mid looks"));
    millardFilmore.addAttack(Attack(5.0, 7.5, "the worst name job ever"));
    //Adds Millard Filmore to the presidents
    presidents.push_back(millardFilmore);

    return presidents;
}

//generates random enemy.  takes nothing in, creates an enemy with randiomly selected name, randomizes other character stats
Enemy Enemy::generateEnemy() 
{
    //seeds a trully random int depending on time
    srand(time(NULL));
    //four different names will be implemented later on
    std::string names[] = { "FBI", "Assasinator", "Vice President", "Opposing Ruler"};
    //sets index to a random number 0-3
    int index = rand() % 5;

    //Declares an FBI agent
    if (names[index] == "FBI")
    {
        //FBI Agent will have, health:25; attack:3; deffense:3; name: "FBI Agent"; fame:0; year:0
        Enemy FBI(25, 3, 3, "FBI Agent", 1, 0);
        FBI.addAttack(Attack(10.0, 1.0, "Spying on you!!!"));
        FBI.addAttack(Attack(7.5, 2.5, "Coup d'etat!!!"));
        FBI.addAttack(Attack(5.0, 7.5, "Hack!!!"));
        return FBI;
    }

    //Declares an Assassinator
    else if (names[index] == "Assasinator")
    {
        //Assassinator will have, health:20; attack:2; deffense:2; name: "Assassinator"; fame:0; year:0
        Enemy assassinator(20, 2, 2, "Assassinator", 2, 0);
        assassinator.addAttack(Attack(10.0, 1.0, "Reveals that he works for the CIA."));
        assassinator.addAttack(Attack(7.5, 2.5, "Poison"));
        assassinator.addAttack(Attack(5.0, 7.5, "Death by cherries"));
        return assassinator;
    }

    //Declares Vice President
    else if (names[index] == "Vice President")
    {
        //vp will have, health:50; attack:5; deffense:5; name: "Vice President"; fame:5; year:0
        Enemy vp(50, 5, 5, "Vice President", 5, 0);
        vp.addAttack(Attack(10.0, 1.0, "Steals your thunder"));
        vp.addAttack(Attack(7.5, 2.5, "Gets you out of the way! Who is president now?"));
        vp.addAttack(Attack(50, 7.5, "Ruins your social image!!"));
        return vp;
    }

    //Declares Opposing Ruler
    else if (names[index] == "Opposing Ruler")
    {
        //Opposing Ruler will have, health:50; attack:10; deffense:10; name: "Opposing Ruler"; fame:10; year:0
        Enemy opposingRuler(50, 10, 10, "Opposing Ruler", 10, 0);
        opposingRuler.addAttack(Attack(10.0, 1.0, "Invades your country!!!"));
        opposingRuler.addAttack(Attack(7.5, 2.5, "Nukes you!!!"));
        opposingRuler.addAttack(Attack(5.0, 7.5, "Spies on you"));
        return opposingRuler;
    }

    //Declares angry mob
    else
    {
        //Angry Mob will have, health:15; attack:1; deffense:3; name: "Angry Mob"; fame:10; year:0
        Enemy mob(15, 1, 3, "Angry Mob", 10, 0);
        mob.addAttack(Attack(10.0, 1.0, "Is on social media."));
        mob.addAttack(Attack(7.5, 2.5, "Storms the Capitol!!!"));
        mob.addAttack(Attack(5.0, 7.5, "Cry loudly."));
        return mob;
    }
}

   
    

   
