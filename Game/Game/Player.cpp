#include "Player.h"
#include <iostream>
//players functions will be here
//function that overides virtual function in character
Attack Player::chooseAttack(){
    printAttacks();

    int choice;
    std::cout << "Choose an attack (1-" << specialAttacks.size() << "): ";
    std::cin >> choice;

    if (choice >= 1 && choice <= specialAttacks.size()) {
        return specialAttacks[choice - 1];
    }
    else {
        // Default to basic attack
        std::cout << "Invalid choice. Using basic attack." << std::endl;
        return chooseAttack();
    }
}

//generates random enemy.  takes nothing in, creates an enemy with randiomly selected name, randomizes other character stats
Player Player::generatePlayer()
{
    std::string names[] = { "Joe Biden", "Donald Trump", "Barack Obama", "George W. Bush", "Bill 'Slick Willy' Clinton", "George H.W. Bush", "Ronald Reagan", "James Carter", "Gerald Ford", "Richard Nixon"};
    int index = rand() % 10 + 1;
    Player newPlay(rand() % 100 + 1, rand() % 100 + 1, rand() % 100 + 1, names[index], rand() % 100 + 1, rand() % 100 + 1); //not right, needs to reflect the right stats that apply to character.  dummy names are being used at present.  implement thenright constructor too //you have to use setters to add special attacks

    if (names[index] == "Joe Biden")
    {
        newPlay.addAttack(Attack(100, 75, "old, political snake, ambitious, greedy.....dangerous"));
        newPlay.addAttack(Attack(75, 25, "cover up for my crackhead son!!!"));
        newPlay.addAttack(Attack(50, 10, "sniff your hair!!"));
    }

    if (names[index] == "Donald Trump")
    {
        newPlay.addAttack(Attack(100, 75, "Build the wall!!!"));
        newPlay.addAttack(Attack(75, 25, "hits his button, which is bigger than North Korea's button"));
        newPlay.addAttack(Attack(50, 10, "calls you gay"));
    }

    if (names[index] == "Barack Obama")
    {
        newPlay.addAttack(Attack(100, 75, "takes you out like osama bin laden"));
        newPlay.addAttack(Attack(75, 25, "im black..but the good kind"));
        newPlay.addAttack(Attack(50, 10, "ill deliver a fiery speech about you that effectively sounds nothing, but it sounds inspiring"));
    }

    if (names[index] == "George W. Bush")
    {
        newPlay.addAttack(Attack(100, 75, "i am not my father!!!!"));
        newPlay.addAttack(Attack(75, 25, "if reagan had a revolution, i can too!!!"));
        newPlay.addAttack(Attack(50, 10, "better than slick willie"));
    }

    if (names[index] == "Bill 'Slick Willy' Clinton")
    {
        newPlay.addAttack(Attack(100, 75, "cheat on my wife!!!"));
        newPlay.addAttack(Attack(75, 25, "go to mcdonalds and knock down a few beers"));
        newPlay.addAttack(Attack(50, 10, "cheat on my wife again!!!"));
    }

    if (names[index] == "George H.W. Bush")
    {
        newPlay.addAttack(Attack(100, 75, "i am president, and my son will totally not inherit it from me...."));
        newPlay.addAttack(Attack(75, 25, "never enough Bush!!!!"));
        newPlay.addAttack(Attack(50, 10, "war on terrorism"));
    }

    if (names[index] == "Ronald Reagan")
    {
        newPlay.addAttack(Attack(100, 75, "start the Reagan revolution!!!"));
        newPlay.addAttack(Attack(75, 25, "i act too....."));
        newPlay.addAttack(Attack(50, 10, "i am not a rebranded Nixon!!!!"));
    }

    if (names[index] == "James Carter")
    {
        newPlay.addAttack(Attack(100, 75, "I will be your president.....forever!!!!!!!!"));
        newPlay.addAttack(Attack(75, 25, "You literally can't get rid of me......"));
        newPlay.addAttack(Attack(50, 10, "I'll throw you into WWII and blame the whole thing on you!"));
    }

    if (names[index] == "Gerald Ford")
    {
        newPlay.addAttack(Attack(100, 75, "NUKED"));
        newPlay.addAttack(Attack(75, 25, "I look nerdier than you!!!"));
        newPlay.addAttack(Attack(50, 10, "I might scare you with red or freeze you with a cold war.....heck i might nuke you"));
    }

    if (names[index] == "Richard Nixon")
    {
        newPlay.addAttack(Attack(100, 75, "scandal!!!!!"));
        newPlay.addAttack(Attack(75, 25, "lies!!! lies and deceit!!!"));
        newPlay.addAttack(Attack(50, 10, "but i support civil rights!!!"));
    }

    return newPlay;


}