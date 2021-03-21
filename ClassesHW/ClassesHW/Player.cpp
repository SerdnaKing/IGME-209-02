#include "Player.h"
#include <iostream>
using namespace std;
char* userName;
//default and parameterized constructors
Player::Player() {
	name = (char*)"Unknown";
	strength = 10;
	constitution = 10;
	dexterity = 10;
}
Player::Player(char* name, int str, int con, int dex) {
	this->name = name;
	strength = str;
	constitution = con;
	dexterity = dex;
}
//destructor
Player::~Player() {
	printf("Deleted Player Stuff\n");
}

//player name getter
 char Player::getName() {
	userName = name;
	 return* userName;
}
 //print method
void Player::printPlayer() {
	cout << name << endl;
	cout << strength << endl;
	cout << constitution << endl;
	cout << dexterity << endl;
}