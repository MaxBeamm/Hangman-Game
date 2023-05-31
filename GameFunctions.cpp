#include "GameFunctions.h"
#define STARS "****************************************************\n"
#define LINES "----------------------------------------------------\n"

using std::cout;

constexpr int INTRO_TIMER{ 6 };
constexpr int INTRO_WIDTH{ 52 };
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

void intro(std::string_view secretWord) {
	system("CLS");

	static int seconds{ INTRO_TIMER };
	seconds--;

	cout << LINES << LINES << LINES << "\n";
	cout << "                    Your word is\n";

	for (int i = 0; i < (INTRO_WIDTH/2 - secretWord.length()); i++)
		cout << " ";
	for (int i = 0; i < secretWord.length(); i++) 
		cout << "_ ";

	cout << "\n              Your word is " << secretWord.length() << " words long.";
	cout << "\n\n                          " << seconds;

}

//void updateWordStatus(std::string& secretWord) {
	
//}

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

void updateState(std::string& wordStatus, int& numWrong, std::string_view secretWord_v, char guess) {
	bool wrongGuess = true;
	for (int i = 0; i < secretWord_v.size(); i++) {
		if (guess == secretWord_v[i]) {
			wordStatus[i] = guess;
			wrongGuess = false;
		}
	}
	if (wrongGuess) {
		cout << "Sorry! The word does not contain a '" << guess << "'.";
		numWrong++;
	}
}

//void drawHangman(wrongAttempts)

