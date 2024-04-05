#include "talker.h"
#include <iostream>
#include <array>

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

std::array<talker,2> talker::initialize()
{
    //goes to second and then third (part of zeroeth level)
    talkerPhrase firstBeg("Hello, welcome to the United States, the country where politics is literally life or death.", "Hello, what's your name?", "Amurica!!!!");
    //goes to fourth and then fifth (part of first level)
    talkerPhrase secondBeg("First rule of politics, never ask a straight question unless you want a straight lie.", "Well, I'm sorry, I guess. Are there any other rules that I should know about?", "False, I ask all the questions that I want, whenever I want, and I get all the answers");
    //goes to sixth and then seventh (part of first level)
    talkerPhrase thirdBeg("It seems you've already got that spirit in you, you will need all that it gives you.", "You have not even seen the begining of my endless patriotism", "I live for one thing alone, and that is our nation");
    //goes to eigth and then ninth (part of second level)
    talkerPhrase fourthBeg("Yes, you never ask your opponent to give you rules, it only limits you.", "So, I guess its better to ask for forgiveness than to ask for forgiveness", "I can not be limitted, I know the rules so that I may break them,");
    //goes to tenth and then eleventh (part of second level)
    talkerPhrase fifthBeg("Well, excuse me princess, but this aint Britain any more, if you act entitled you get nothing.", "Forgive me my liege, I would like to return back to sipping my tea in my castle now.", "False, if I act entitled and I have money I can do whatever I want to.");
    //goes to twelth and then thirteenth (part of second level)
    talkerPhrase sixthBeg("I hope you do not have empty words and no show, as that would get you quickly killed.", "Aha, who do you think that I am, some useless Brit?", "I prefer the phrase tarred and feathered, that is what I do with my enemies.");
    //goes to fourteenth and then fifteenth (part of second level)
    talkerPhrase seventhBeg("The man who lives for one thing dies for one thing. Do not be that man.", "Death is but a trivial thing to do for your country.", "I am not that man, because I do not die.");
    //leads nowhere (part of third level)
    talkerPhrase eigthBeg("You finally seem to have some logic. I hope that logic leads you to great futures. Bye bye now...", "", "");
    //leads nowhere (part of third level)
    talkerPhrase ninthBeg("That is a classic lawyer move. May it not lead you down a bad path. Godbye now...", "", "");
    //leads nowhere (part of third level)
    talkerPhrase tenthBeg("No, you do not go home. This is your home, and you will either die a traitor or live a patriot.Whatever you choose, I command you to leave me, for you are still a filthy brit.", "", "");
    //leads nowhere (part of third level)
    talkerPhrase eleventhBeg("Let's see where that lazy mindset leads you in this country of labor. Leave my sight you greedy pig...", "", "");
    //leads nowhere (part of third level)
    talkerPhrase twelthBeg("Hate of the brits, that is the one thing that unites Americans. Go, keep all the Americans united under this common enemy.", "", "");
    //leads nowhere (part of third level)
    talkerPhrase thirteenthBeg("You relentless man. You show no mercy, may no mercy be shown unto you. Leave me, for I do not embrace merciless theives.", "", "");
    //leads nowhere (part of third level)
    talkerPhrase fourteenthBeg("And yet, it is the only thing that you, being a poor man, can give. Go, die...", "", "");
    //leads nowhere (part of third level)
    talkerPhrase fifteenthBeg("You have not yet died, but as you are still a man, I command you to leave me so that you may die...", "", "");

    talkerPhrase beginingPhrases[15] = { firstBeg, secondBeg, thirdBeg, fourthBeg, fifthBeg, sixthBeg, seventhBeg, eigthBeg, ninthBeg, tenthBeg, eleventhBeg, twelthBeg, thirteenthBeg, fourteenthBeg, fifteenthBeg };
    talker begining("First Speaker", beginingPhrases);

    //goes to second and then third (part of zeroeth level)
    talkerPhrase firstEnd("You have survived the game and have reached the end. Congratulations.", "Thank you, the work really paid off.", "Of course I did. Why did you doubt?");
    //goes to fourth and then fifth (part of first level)
    talkerPhrase secondEnd("It seems your extreme politeness got you this far. What do you have to get you farther?", "Do I need to go farther?", "Nothing but my unending charisma");
    //goes to sixth and then seventh (part of first level)
    talkerPhrase thirdEnd("With your relentless cockiness, I do not doubt the fact that you did.", "I am unrelentless in all my qualities, not just in my speech", "Soon, all will learn to not doubt me");
    //goes to eigth and then ninth (part of second level)
    talkerPhrase fourthEnd("You fool. You have nothing but politeness. If you did not lack brains you would see that you have yet to conquer the whole world.", "I think that having separate cultures is a good thing though. Not everything should be the United States.", "I do things, not out of necessity but out of desire, and my desires do not stop at this world. But continue to the entire galaxy.");
    //goes to tenth and then eleventh (part of second level)
    talkerPhrase fifthEnd("So you will be going down the highly political path.", "Do you really think that without my political abilities I would be able to haver gotten this far.", "Let's just say that it isn't the only thing that got me this far.");
    //goes to twelth and then thirteenth (part of second level)
    talkerPhrase sixthEnd("Of course you are. The real question is, are you relentless with your ambition and your goals?", "It depends, would you call wanting to be the literal king of the world lacking ambition?", "Ambition is but the start of what you need to rule.");
    //goes to fourteenth and then fifteenth (part of second level)
    talkerPhrase seventhEnd("How soon though is up to you.", "People will always doubt the obvious, it is not my responsibility to take care of them.", "A politician never reveals his plans.");
    //leads nowhere (part of third level)
    talkerPhrase eigthEnd("I am still shocked at how you can beat America with out the one thing that Americans have: ambition. Now leave, you ambitionless fool...", "", "");
    //leads nowhere (part of third level)
    talkerPhrase ninthEnd("You have the American spirit. May it lead you to being the highest man in the multiverse. Good bye my friend...", "", "");
    //leads nowhere (part of third level)
    talkerPhrase tenthEnd("May you continue to use them wisely as you continue to rule with a sly heart. Goodbye my highly political friend", "", "");
    //leads nowhere (part of third level)
    talkerPhrase eleventhEnd("That is the classic American way, to hide one's dirty deeds with political tact. I do not deal with people like you. Leave my presence you criminal.", "", "");
    //leads nowhere (part of third level)
    talkerPhrase twelthEnd("Big words and, I hope, big deeds too. Go, prove yourself...", "", "");
    //leads nowhere (part of third level)
    talkerPhrase thirteenthEnd("A well balanced man, I hope that it pays off. Go, be well-balanced somewhere else...", "", "");
    //leads nowhere (part of third level)
    talkerPhrase fourteenthEnd("And yet, if you do not take care of them, they will defeat you. Go, do not ignore the helpless...", "", "");
    //leads nowhere (part of third level)
    talkerPhrase fifteenthEnd("And a wise man never wastes his time talking to one. Leave me, you worthless politician...", "", "");

    talkerPhrase endingPhrases[15] = { firstBeg, secondBeg, thirdBeg, fourthBeg, fifthBeg, sixthBeg, seventhBeg, eigthBeg, ninthBeg, tenthBeg, eleventhBeg, twelthBeg, thirteenthBeg, fourteenthBeg, fifteenthBeg };
    talker end("First Speaker", beginingPhrases);
    array<talker,2> output = { begining, end };

    return output;
}
