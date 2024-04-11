//this will be the individual nodes that will go into the dialougeTree for the talker class
#pragma once
#include <string>
using namespace std;

class talkerPhrase
{
protected:
	//talker is what the talker says
	string talker;
	//firstResponse is the first response option given to player
	string firstResponse;
	//secondResponse is the second response option gien to player
	string secondResponse;

public:
	//initializer for talkerPhrase, where quote becomes talker quote, responseA and responseB are other response options given to user
	talkerPhrase(string quote, string responseA, string responseB) {
		talker = quote;
		firstResponse = responseA;
		secondResponse = responseB;
	}

	//default constructor for talkerPhrase
	talkerPhrase() {
		talker = "";
		firstResponse = "";
		secondResponse = "";
	}

	//getters for talker, and the response options
	string getTalker();
	string getFirstResponse();
	string getSecondResponse();
};

