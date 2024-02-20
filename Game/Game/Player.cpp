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
    return Player(rand() % 100 + 1, rand() % 100 + 1, rand() % 100 + 1, names[index], rand() % 100 + 1); //not right, needs to reflect the right stats that apply to character.  dummy names are being used at present.  implement thenright constructor too //you have to use setters to add special attacks

    if (names[index] == "Joe Biden")
    {
        Player.specialAttacks.push_back(Attack(100, 75, "old, political snake, ambitious, greedy.....dangerous"));
        Player.specialAttacks.push_back(Attack(75, 25, "cover up for my crackhead son!!!"));
        Player.specialAttacks.push_back(Attack(50, 10, "sniff your hair!!"));
    }

    if (names[index] == "Donald Trump")
    {
        Player.specialAttacks.push_back(Attack(100, 75, "Build the wall!!!"));
        Player.specialAttacks.push_back(Attack(75, 25, "hits his button, which is bigger than North Korea's button"));
        Player.specialAttacks.push_back(Attack(50, 10, "calls you gay"));
    }

    if (names[index] == "Barack Obama")
    {
        Player.specialAttacks.push_back(Attack(100, 75, "takes you out like osama bin laden"));
        Player.specialAttacks.push_back(Attack(75, 25, "im black..but the good kind"));
        Player.specialAttacks.push_back(Attack(50, 10, "ill deliver a fiery speech about you that effectively sounds nothing, but it sounds inspiring"));
    }

    if (names[index] == "George W. Bush")
    {
        Player.specialAttacks.push_back(Attack(100, 75, "i am not my father!!!!"));
        Player.specialAttacks.push_back(Attack(75, 25, "if reagan had a revolution, i can too!!!"));
        Player.specialAttacks.push_back(Attack(50, 10, "better than slick willie"));
    }

    if (names[index] == "Bill 'Slick Willy' Clinton")
    {
        Player.specialAttacks.push_back(Attack(100, 75, "cheat on my wife!!!"));
        Player.specialAttacks.push_back(Attack(75, 25, "go to mcdonalds and knock down a few beers"));
        Player.specialAttacks.push_back(Attack(50, 10, "cheat on my wife again!!!"));
    }

    if (names[index] == "George H.W. Bush")
    {
        Player.specialAttacks.push_back(Attack(100, 75, "i am president, and my son will totally not inherit it from me...."));
        Player.specialAttacks.push_back(Attack(75, 25, "never enough Bush!!!!"));
        Player.specialAttacks.push_back(Attack(50, 10, "war on terrorism"));
    }

    if (names[index] == "Ronald Reagan")
    {
        Player.specialAttacks.push_back(Attack(100, 75, "start the Reagan revolution!!!"));
        Player.specialAttacks.push_back(Attack(75, 25, "i act too....."));
        Player.specialAttacks.push_back(Attack(50, 10, "i am not a rebranded Nixon!!!!"));
    }

    if (names[index] == "James Carter")
    {
        Player.specialAttacks.push_back(Attack(100, 75, "I will be your president.....forever!!!!!!!!"));
        Player.specialAttacks.push_back(Attack(75, 25, "You literally can't get rid of me......"));
        Player.specialAttacks.push_back(Attack(50, 10, "I'll throw you into WWII and blame the whole thing on you!"));
    }

    if (names[index] == "Gerald Ford")
    {
        Player.specialAttacks.push_back(Attack(100, 75, "NUKED"));
        Player.specialAttacks.push_back(Attack(75, 25, "I look nerdier than you!!!"));
        Player.specialAttacks.push_back(Attack(50, 10, "I might scare you with red or freeze you with a cold war.....heck i might nuke you"));
    }

    if (names[index] == "Richard Nixon")
    {
        Player.specialAttacks.push_back(Attack(100, 75, "scandal!!!!!"));
        Player.specialAttacks.push_back(Attack(75, 25, "lies!!! lies and deceit!!!"));
        Player.specialAttacks.push_back(Attack(50, 10, "but i support civil rights!!!"));
    }

    


}