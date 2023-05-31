#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <array>
#include <windows.h>

std::string buildGame();

void intro(std::string_view secretWord);

//void updateWordStatus(std::string& wordStatus);

void loadState(std::string wordStatus, int numWrong);

void updateState(std::string& wordStatus, int& numWrong, std::string_view secretWord_v, char guess);