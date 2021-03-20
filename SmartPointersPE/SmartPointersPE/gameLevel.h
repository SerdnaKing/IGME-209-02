#pragma once
class gameLevel
{
public: 
	gameLevel(int levelNumber, int difficulty, int numberEnemies); //constructor
	~gameLevel(); //destructor
	int levelNumber;
	int difficulty;
	int numberEnemies;
};

