#include "Player.h"
#include <iostream>
//players functions will be here
//function that overides virtual function in character
Attack Player::chooseAttack(){
    //prints attacks before letting player pick which one he wants to 
    printAttacks();

    //creates choice variable that will have index of attack later on
    int choice;
    //tells the user how to pick his attack
    std::cout << "Choose an attack (1-" << attacks.size() << "): ";
    //Takes the choice input from the user
    std::cin >> choice;

    //If choice is valid, returns the attack indexed by choice
    if (choice >= 1 && choice <= attacks.size()) {
        return attacks[choice - 1];
    }

    //if choice isn't valid, it runs the function again
    else {
        //Tells the user that the function will be re-run
        std::cout << "Invalid choice. Choose again." << std::endl;
        return chooseAttack();
    }
}

//generates random enemy.  takes nothing in, creates an enemy with randiomly selected name, randomizes other character stats
Player Player::generatePlayer()
{
    //makes a list of all of the possible player choices
    std::string names[] = { "Joe Biden", "Donald Trump", "Barack Obama", "George W. Bush", "Bill 'Slick Willy' Clinton", "George H.W. Bush", "Ronald Reagan", "James Carter", "Gerald Ford", "Richard Nixon"};
    //makes the number that the user will pick, it will be used to index names
    int index=13;

    //only stops when index is less than the size of the names, so as to avoid segfaults
    while (index > names->size()+1) {
        //Outputs the command giving the user the prompt to pick a character
        cout << "Please choose the number next to the character that you wish to select:" << endl;
        //iterates through entire names array printing each president next to a corresponding number
        for (int i = 1; i <= names->size()+1; i++) {
            cout << i << ". " << names[i - 1] << endl;
        }
        //takes the input of the index from the user
        cin >> index;

        //if the number is too large, tells the user and repeats the selection process, so as to avoid segfaults
        if (index > names->size()+1) {
            cout << "The number was too large." << endl;
        }
    }
    //makes the index smaller because indexing starts at 0, not at 1
    index--;

    //generates the player object with the amateur stats
    Player player(100, 5, 5, names[index], 0, 1790); 

    //initializes the characters attacks if he chooses to be joe biden
    if (names[index] == "Joe Biden")
    {
        //clears the screen and tells them who they've chosen
        system("cls");
        cout << "You choose Joe Biden."<<endl;
        
        //adds attacks to the president
        player.addAttack(Attack(10.0, 1.0, "old, political snake, ambitious, greedy.....dangerous"));
        player.addAttack(Attack(7.5, 2.5, "cover up for my crackhead son!!!"));
        player.addAttack(Attack(5.0, 7.5, "sniff your hair!!"));
    }

    //initializes the characters attacks if he chooses to be Donald Trump
    if (names[index] == "Donald Trump")
    {
        //clears the screen and tells them who they've chosen
        system("cls");
        cout << "You choose Donald Trump." << endl;

        //adds attacks to the president
        player.addAttack(Attack(10.0, 1.0, "Build the wall!!!"));
        player.addAttack(Attack(7.5, 2.5, "hits his button, which is bigger than North Korea's button"));
        player.addAttack(Attack(5.0, 7.5, "calls you gay")); //MIGHT HAVE TO CHANGE
    }

    //initializes the characters attacks if he chooses to be Barack Obama
    if (names[index] == "Barack Obama")
    {
        //clears the screen and tells them who they've chosen
        system("cls");
        cout << "You choose Barack Obama." << endl;

        //adds attacks to the president
        player.addAttack(Attack(10.0, 1.0, "takes you out like osama bin laden"));
        player.addAttack(Attack(7.5, 2.5, "im black..but the good kind")); //MIGHT HAVE TO CHANGE  
        player.addAttack(Attack(5.0, 7.5, "ill deliver a fiery speech about you that effectively sounds nothing, but it sounds inspiring"));
    }

    //initializes the characters attacks if he chooses to be George W. Bush
    if (names[index] == "George W. Bush")
    {
        //clears the screen and tells them who they've chosen
        system("cls");
        cout << "You choose George W. Bush." << endl;

        //adds attacks to the president
        player.addAttack(Attack(10.0, 1.0, "i am not my father!!!!"));
        player.addAttack(Attack(7.5, 2.5, "if reagan had a revolution, i can too!!!"));
        player.addAttack(Attack(5.0, 7.5, "better than slick willie"));
    }

    //initializes the characters attacks if he chooses to be Bill Clinton
    if (names[index] == "Bill 'Slick Willy' Clinton")
    {
        //clears the screen and tells them who they've chosen
        system("cls");
        cout << "You choose Bill Clinton." << endl;

        //adds attacks to the president
        player.addAttack(Attack(10.0, 1.0, "cheat on my wife!!!"));
        player.addAttack(Attack(7.5, 2.5, "go to mcdonalds and knock down a few beers"));
        player.addAttack(Attack(5.0, 7.5, "cheat on my wife again!!!"));
    }

    //initializes the characters attacks if he chooses to be George H.W. Bush
    if (names[index] == "George H.W. Bush")
    {
        //clears the screen and tells them who they've chosen
        system("cls");
        cout << "You choose George H.W. Bush." << endl;

        //adds attacks to the president
        player.addAttack(Attack(10.0, 1.0, "i am president, and my son will totally not inherit it from me...."));
        player.addAttack(Attack(7.5, 25, "never enough Bush!!!!"));
        player.addAttack(Attack(5.0, 7.5, "war on terrorism"));
    }

    //initializes the characters attacks if he chooses to be Ronald Reagan
    if (names[index] == "Ronald Reagan")
    {
        //clears the screen and tells them who they've chosen
        system("cls");
        cout << "You choose Ronald Reagan." << endl;

        //adds attacks to the president
        player.addAttack(Attack(10.0, 1.0, "start the Reagan revolution!!!"));
        player.addAttack(Attack(7.5, 2.5, "i act too....."));
        player.addAttack(Attack(5.0, 7.5, "i am not a rebranded Nixon!!!!"));
    }

    //initializes the characters attacks if he chooses to be James Carter
    if (names[index] == "James Carter")
    {
        //clears the screen and tells them who they've chosen
        system("cls");
        cout << "You choose James Carter." << endl;

        //adds attacks to the president
        player.addAttack(Attack(10.0, 1.0, "I will be your president.....forever!!!!!!!!"));
        player.addAttack(Attack(7.5, 2.5, "You literally can't get rid of me......"));
        player.addAttack(Attack(5.0, 7.5, "I'll throw you into WWII and blame the whole thing on you!"));
    }

    //initializes the characters attacks if he chooses to be Gerald Ford
    if (names[index] == "Gerald Ford")
    {
        //clears the screen and tells them who they've chosen
        system("cls");
        cout << "You choose Gerald Ford." << endl;

        //adds attacks to the president
        player.addAttack(Attack(10.0, 1.0, "NUKED"));
        player.addAttack(Attack(7.5, 2.5, "I look nerdier than you!!!"));
        player.addAttack(Attack(5.0, 7.5, "I might scare you with red or freeze you with a cold war.....heck i might nuke you"));
    }

    //initializes the characters attacks if he chooses to be Richard Nixon
    if (names[index] == "Richard Nixon")
    {
        //clears the screen and tells them who they've chosen
        system("cls");
        cout << "You choose Richard Nixon." << endl;

        //adds attacks to the president
        player.addAttack(Attack(10.0, 7.5, "scandal!!!!!"));
        player.addAttack(Attack(7.5, 2.5, "lies!!! lies and deceit!!!"));
        player.addAttack(Attack(5.0, 1.0, "but i support civil rights!!!"));
    }

    return player;


}