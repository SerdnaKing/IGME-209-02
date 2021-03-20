// SmartPointersPE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <memory>
#include "gameLevel.h";
using namespace std;

int currentLevel = 30;
int difficulty = 500;
int enemyNumber = 20;
//create a smart pointer variable to the class
void smartfunctionPointer() {
    std::shared_ptr<gameLevel> gameLevel(new gameLevel(currentLevel, difficulty, enemyNumber));
}
void basicPointer() {
    gameLevel* newLevel = new gameLevel(currentLevel, difficulty, enemyNumber);
    delete newLevel;
}
int main()
{

   // { std::shared_ptr<gameLevel> gameLevel(new gameLevel(currentLevel, difficulty, enemyNumber)); }
    smartfunctionPointer();
    basicPointer();
    _CrtDumpMemoryLeaks(); //checking for memory leaks
}
