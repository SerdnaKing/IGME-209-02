#include "Fighter.h"
#include <iostream>
using namespace std;

//default and parameterized constructor
Fighter::Fighter() {
	weaponSkill = 30;
}
Fighter::Fighter(char* name, int weaponSkill, int str, int con, int dex) 
:Player(name, str, con, dex) {
	this->weaponSkill = weaponSkill;
	
}
//destructor
//Fighter::~Fighter() {
//	printf("Destroyed Fighter Stuff");
//}
//print method
 //attack function is working
 void Fighter::Attack(Player* playername) {
	 cout << getName() << " has attacked " << playername->getName() << endl;
	// printf(*name + " has attacked " + *playername->name);
}
void Fighter::printFighter() {
	Player::printPlayer();
	cout << weaponSkill <<endl;
}