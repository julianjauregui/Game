#include "talker.h"
#include <iostream>

//returns the name of the talker
string talker::getName()
{
    return name;
}

//main talking interface for the talker and the player
void talker::talk(int index)
{
    cout << (dialougeTree[index]).getTalker() << endl;
    if ((dialougeTree[index]).getFirstResponse() == "") {
        system("pause");
        system("cls");
        return;
    }
    
    int selection = 0;
    while(selection!=1&&selection!=2){
        cout << "Pick your response: " << endl;
        cout << "1. " << dialougeTree[index].getFirstResponse() << endl;
        cout << "2. " << dialougeTree[index].getSecondResponse() << endl;
        if (selection != 1 && selection != 2) {
            cout << "Invalid response, please try again." << endl;
        }
    }

    if (selection == 1) {
        index = index * 2 + 1;
    }
    else if (selection == 2) {
        index = index * 2 + 2;
    }
 
    talk(index);
}

array<talker, 2> talker::initialize()
{
    //goes to second and then third (part of zeroeth level)
    talkerPhrase first("Hello, welcome to the United States, the country where politics is literally life or death.", "Hello, what's your name?", "Amurica!!!!");
    //goes to fourth and then fifth (part of first level)
    talkerPhrase second("First rule of politics, never ask a straight question unless you want a straight lie.", "Well, I'm sorry, I guess. Are there any other rules that I should know about?", "False, I ask all the questions that I want, whenever I want, and I get all the answers");
    //goes to sixth and then seventh (part of first level)
    talkerPhrase third("It seems you've already got that spirit in you, you will need all that it gives you.", "You have not even seen the begining of my endless patriotism", "I live for one thing alone, and that is our nation");
    //goes to eigth and then ninth (part of second level)
    talkerPhrase fourth("Yes, you never ask your opponent to give you rules, it only limits you.", "So, I guess its better to ask for forgiveness than to ask for forgiveness", "I can not be limitted, I know the rules so that I may break them,");
    //goes to tenth and then eleventh (part of second level)
    talkerPhrase fifth("Well, excuse me princess, but this aint Britain any more, if you act entitled you get nothing.", "Forgive me my liege, I would like to return back to sipping my tea in my castle now.", "False, if I act entitled and I have money I can do whatever I want to.");
    //goes to twelth and then thirteenth (part of second level)
    talkerPhrase sixth("I hope you do not have empty words and no show, as that would get you quickly killed.", "Aha, who do you think that I am, some useless Brit?", "I prefer the phrase tarred and feathered, that is what I do with my enemies.");
    //goes to fourteenth and then fifteenth (part of second level)
    talkerPhrase seventh("The man who lives for one thing dies for one thing. Do not be that man.", "Death is but a trivial thing to do for your country.", "I am not that man, because I do not die.");
    //leads nowhere (part of third level)
    talkerPhrase eigth("You finally seem to have some logic. I hope that logic leads you to great futures. Bye bye now...", "", "");
    //leads nowhere (part of third level)
    talkerPhrase ninth("That is a classic lawyer move. May it not lead you down a bad path. Godbye now...", "", "");
    //leads nowhere (part of third level)
    talkerPhrase tenth("No, you do not go home. This is your home, and you will either die a traitor or live a patriot.Whatever you choose, I command you to leave me, for you are still a filthy brit.", "", "");
    //leads nowhere (part of third level)
    talkerPhrase eleventh("Let's see where that lazy mindset leads you in this country of labor. Leave my sight you greedy pig...", "", "");
    //leads nowhere (part of third level)
    talkerPhrase twelth("Hate of the brits, that is the one thing that unites Americans. Go, keep all the Americans united under this common enemy.", "", "");
    //leads nowhere (part of third level)
    talkerPhrase thirteenth("You relentless man. You show no mercy, may no mercy be shown unto you. Leave me, for I do not embrace merciless theives.", "", "");
    //leads nowhere (part of third level)
    talkerPhrase fourteenth("And yet, it is the only thing that you, being a poor man, can give. Go, die...", "", "");
    //leads nowhere (part of third level)
    talkerPhrase fifteenth("You have not yet died, but as you are still a man, I command you to leave me so that you may die...", "", "");

    talkerPhrase beginingPhrases[15] = { first, second, third, fourth, fifth, sixth, seventh, eigth, ninth, tenth, eleventh, twelth, thirteenth, fourteenth, fifteenth };
    talker begining("First Speaker", beginingPhrases);
    talker output[2] = { begining, end };
}
