#pragma once
class Player
{
public:
	//create a constructor that has parameters name strength const and dex
	Player();
	Player(char* name, int str, int con, int dex);
	void printPlayer();
private:
	//private members go here
	char* name;
	int strength;
	int constitution;
	int dexterity;

};

