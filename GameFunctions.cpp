#include "GameFunctions.h"
#define STARS "****************************************************\n"

using std::cout;

void getWord() {
	std::vector<std::string> wordList = { "Mystery", "Pumpkin", "Dolphin", "Bicycle", "Cupcake", "Pirate", "Caramel",
										  "Rainbow", "Treasure", "Lantern", "Whisper", "Chocolate", "Forest", "Adventure",
										  "Moonlight", "Enigma", "Jungle", "Explorer", "Paradise", "Riddle", "Galaxy",
										  "Journey", "Serenade", "Discovery", "Bonfire", "Butterfly", "Castle", "Potion",
										  "Mermaid", "Telescope", "Wandering", "Potion", "Enchanting", "Gypsy", "Treasure",
										  "Whisper", "Labyrinth", "Wonderland", "Dragonfly", "Harmonica", "Harmony", "Mystic",
										  "Serenity", "Legend", "Mysterious", "Adventure", "Unicorn", "Melody", "Illusion", "Wanderer" };
	int chooseIndex = rand() % wordList.size();

	cout << wordList[chooseIndex];
	
	//return wordList[chooseIndex];
}

void buildGame() {
	cout << STARS;
	cout << STARS;
	cout << STARS;
	cout << "            WELCOME TO THE HANGMAN GAME\n";
	cout << STARS;
	cout << STARS;
	cout << STARS;
	cout << "Version 0.0\n5/27/2023 Maxwell Beam\n";
	cout << "\n\n\nContinue? (Y/N):"; 

	char chooseContinue{};
	std::cin >> chooseContinue;

	if (chooseContinue == 'N')
		exit(0);

	getWord();

}