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
Fighter::~Fighter() {
	printf("Destroyed Fighter Stuff");
}
//print method
void Fighter::printFighter() {
	Player::printPlayer();
	cout << weaponSkill <<endl;
}