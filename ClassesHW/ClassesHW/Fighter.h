#pragma once
#include "Player.h"
class Fighter :
    public Player
{
public:
   // int weaponSkill;
    //parameterized constructor that takes name weaponSkill and the 
    //three other stats from player
    Fighter();
    Fighter(char* name, int weaponSkill, int str, int con, int dex);
    //fighter destructor
    ~Fighter();
    //declare a public printFighter with no parameters
    void printFighter();
    void Attack(Player* playername);
private:
    int weaponSkill;
};

