// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

class MovableObject
{
public:
	int xPos;
	int yPos;
	void PrintPos()
	{
		cout << "X:" << xPos << " Y:" << yPos << endl;
	}
};

class Player : public MovableObject
{
public:
	char* name;
	Player()
	{
		cout << "player ctor" << endl;
		name = new char[15];
	}

	~Player()
	{
		cout << "player dtor" << endl;
		delete[] name;
	}
};

class Monster : public MovableObject
{
public:
	int damage;
};

int main()
{
	Monster *boss = new Monster();
	Player *pOne = new Player();
	//MovableObject *boss = new Monster();
	//MovableObject *pOne = new Player();
	Monster *fakeMonster = (Monster*)pOne;

	// add code here
	cout << "Boss" << &*boss << endl;
	boss->xPos = 42;
	boss->yPos = 64;
	boss->PrintPos();
	//print out the addresses
	
	//cout << boss->PrintPos() << endl;
	cout << "pOne" <<&*pOne << endl;
	pOne->xPos = 34;
	pOne->yPos = 35;
	pOne->PrintPos();
	cout <<"fakeMonster"<< &*fakeMonster << endl;
	fakeMonster->PrintPos();
	delete boss;
	delete pOne; 
	//part 2 answer: if this is deleted, then won't fakemonster
	//also be deleted?? they are referencing the same address
	//delete fakeMonster; //There's a problem being triggered with this line of code

	//part 6 answer: player dtor is not listed when using the base class
	//_getch();
    return 0;
}

