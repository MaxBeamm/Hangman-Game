#include "GameFunctions.h"
#define STARS "****************************************************\n"
#define LINES "----------------------------------------------------\n"

using std::cout;

constexpr int INTRO_WIDTH{ 52 };

//Hangman display states
constexpr std::array<std::string_view, 7> displayState{
  "  + -- - +\n"
  "  |   |\n"
  "      |\n"
  "      |\n"
  "      |\n"
  "      |\n"
  "======== = ",

  "  + -- - +\n"
  "  |   |\n"
  "  O   |\n"
  "      |\n"
  "      |\n"
  "      |\n"
  "======== = ",

  "  + -- - +\n"
  "  |   |\n"
  "  O   |\n"
  "  |   |\n"
  "      |\n"
  "      |\n"
  "======== = ",

  "  + -- - +\n"
  "  |   |\n"
  "  O   |\n"
  " /|   |\n"
  "      |\n"
  "      |\n"
  "======== = ",

  "  + -- - +\n"
  "  |   |\n"
  "  O   |\n"
  " /|\\  |\n"
  "      |\n"
  "      |\n"
  "======== = ",

  "  + -- - +\n"
  "  |   |\n"
  "  O   |\n"
  " /|\\  |\n"
  " /    |\n"
  "      |\n"
  "======== = ",

  "  + -- - +\n"
  "  |   |\n"
  "  O   |\n"
  " /|\\  |\n"
  " / \\  |\n"
  "      |\n"
  "======== = "
};

//picks one of the words from the list randomly and returns it as the secret word
static std::string getWord() {
	std::vector<std::string> wordList = { "Mystery", "Pumpkin", "Dolphin", "Bicycle", "Cupcake", "Pirate", "Caramel",
										  "Rainbow", "Treasure", "Lantern", "Whisper", "Chocolate", "Forest", "Adventure",
										  "Moonlight", "Enigma", "Jungle", "Explorer", "Paradise", "Riddle", "Galaxy",
										  "Journey", "Serenade", "Discovery", "Bonfire", "Butterfly", "Castle", "Potion",
										  "Mermaid", "Telescope", "Wandering", "Potion", "Enchanting", "Gypsy", "Treasure",
										  "Whisper", "Labyrinth", "Wonderland", "Dragonfly", "Harmonica", "Harmony", "Mystic",
										  "Serenity", "Legend", "Mysterious", "Adventure", "Unicorn", "Melody", "Illusion", "Wanderer" };
	int chooseIndex = rand() % wordList.size();

	cout << wordList[chooseIndex];
	
	return wordList[chooseIndex];
}

//Initializes the game and shows the beginning credits if user wants to continue playing it will return the secret word using getWord()
std::string buildGame() {
	system("CLS");

	cout << STARS << STARS << STARS;
	cout << "            WELCOME TO THE HANGMAN GAME\n";
	cout << STARS << STARS << STARS;
	cout << "Version 0.0\n5/27/2023 Maxwell Beam\n";
	cout << "\n\n\nContinue? (Y/N):"; 

	char chooseContinue{};
	std::cin >> chooseContinue;

	if (chooseContinue == 'N')
		exit(0);

	return getWord();

}

void intro(std::string_view secretWord, int& timer) {
	system("CLS");

	timer--;

	cout << LINES << LINES << LINES << "\n";
	cout << "                    Your word is\n";

	for (int i = 0; i < (INTRO_WIDTH/2 - secretWord.length()); i++)
		cout << " ";
	for (int i = 0; i < secretWord.length(); i++) 
		cout << "_ ";

	cout << "\n              Your word is " << secretWord.length() << " words long.";
	cout << "\n\n                          " << timer;

}

//Refreshes and loads in updated information and hangman stage
void loadState(std::string wordStatus, int numWrong) {
	system("CLS");
	cout << displayState[numWrong];
	cout << "\n\n";
	for (int i = 0; i < wordStatus.size(); i++) {
		if (wordStatus[i] == '*') {
			cout << "_ ";
		}
		else {
			cout << wordStatus[i] << " ";
		}
	}
	
}

//Updates numWrong and secretWord to reflect the result of new user guess
void updateState(std::string& wordStatus, int& numWrong, std::string_view secretWord_v, char guess) {
	bool wrongGuess = true;
	for (int i = 0; i < secretWord_v.size(); i++) {
		if (guess == secretWord_v[i]) {
			wordStatus[i] = guess;
			wrongGuess = false;
		}
	}
	if (wrongGuess)
		numWrong++;
}

