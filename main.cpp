#include "GameFunctions.h"
#include <cstdlib>
#include <windows.h>

int main() {
	srand(unsigned (time(NULL)));
	std::string secretWord{ buildGame() };

	for (int i = 5; i > 0; i--) {
		intro(secretWord);
		Sleep(1500);
	}

	int guessNumber{ 0 };
	char guess{ guessInput(guessNumber) };
	


	return 0;


}