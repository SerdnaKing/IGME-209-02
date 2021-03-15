#include "Player.h"
#include <iostream>
using namespace std;
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
void Player::printPlayer() {
	cout << name << endl;
	cout << strength << endl;
	cout << constitution << endl;
	cout << dexterity << endl;
}