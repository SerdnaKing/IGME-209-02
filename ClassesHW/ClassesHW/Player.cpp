#include "Player.h"
#include <iostream>
using namespace std;

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
	printf("Destroying Player Object\n");
}

//player name getter
 char *Player::getName() {
	//userName = name;
	 //cout << ()name;
	 return (char*)name;
}
 //attack function is working
 void Player::Attack(Player* playername) {
	 cout << (char*)name << " has attacked " << (char*)playername->name << endl;
	// printf(*name + " has attacked " + *playername->name);
}

 //print method
void Player::printPlayer() {
	cout << name << endl;
	cout << strength << endl;
	cout << constitution << endl;
	cout << dexterity << endl;
}