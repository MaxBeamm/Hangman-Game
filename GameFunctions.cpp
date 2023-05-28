#include "GameFunctions.h"
#define STARS "****************************************************\n"
#define LINES "----------------------------------------------------\n"

using std::cout;

constexpr int INTRO_TIMER{ 6 };
constexpr int INTRO_WIDTH{ 52 };

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

void intro(std::string secretWord) {
	system("CLS");

	static int seconds{ INTRO_TIMER };
	seconds--;

	cout << LINES << LINES << LINES << "\n";
	cout << "                    Your word is\n";

	for (int i = 0; i < (INTRO_WIDTH/2 - secretWord.length()); i++)
		cout << " ";
	for (int i = 0; i < secretWord.length(); i++) 
		cout << "_ ";

	cout << "\n                          " << seconds;

}

