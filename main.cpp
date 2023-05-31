#include "GameFunctions.h"
#include <cstdlib>
#include <conio.h>


int main() {
	//Max guesses before hangman is completely drawn is 10
	//Guess number represents the number of guesses the user has had
	//Word status represents how many of the letters are filled in
	constexpr int MAX_GUESSES{ 6 };
	int numWrong{ 0 };
	std::string wordStatus;

	//Start seeding for the random word generator
	//Start intro and
	srand(unsigned(time(NULL)));
	std::string secretWord{ buildGame() };
	std::string_view secretWord_v{ secretWord };

	//Initialize wordstatus to be '*******' the stars will be replaced by characters as the user correctly guesses
	wordStatus.resize(secretWord.size(), '*');
	for (int i = 0; i < secretWord.size(); i++)
		wordStatus[i] = '*';


	//Starts and loads in intro with countdown timer where word length is displayed to user
	for (int i = 5; i > 0; i--) {
		intro(secretWord_v);
		Sleep(1500);
	}

	//While guesses do not go past max guesses and wordStatus is still incomplete continously run loadState and updateState which displays and updated infromation after
	//  each user guess
	while (numWrong < MAX_GUESSES && wordStatus != secretWord) {
		char guess{};
		loadState(wordStatus, numWrong);
		std::cout << "\n\nGuess a letter: ";
		std::cin >> guess;
		updateState(wordStatus, numWrong, secretWord_v, guess);
    }

	//Display outro message
	if (numWrong == MAX_GUESSES) {
		std::cout << "Sorry you have ran out of guesses! The word was " << secretWord_v;
	}
	else if (wordStatus == secretWord) {
		std::cout << "Congratulations! You have guessed the word correctly!";
	}
	

	Sleep(10000);

	return 0;


}