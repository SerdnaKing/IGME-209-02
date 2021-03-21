// ClassesHW.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;
#include "Player.h"
#include "Fighter.h"
int main()
{
    //create a default player as a local variable,
    //create a parameterized player on the stack, and a default on the heap
    //lastly make a fourth on the heap with the parameterized constructor
    //PART 1
    Player kiir;
    Player henk((char*)"Henk", 16, 18, 14);
    //remember that using new will return a pointer
    Player* archimedes = new Player();
    Player* anabeth = new Player((char*)"Anabeth", 13, 15, 18);
    kiir.printPlayer();
    henk.printPlayer();
    archimedes->printPlayer();
    anabeth->printPlayer();
    //PART 2
    Fighter valerica;
    Fighter treybrin((char*)"Treybrin", 50, 18, 16, 15);
    valerica.printFighter();
    treybrin.printFighter();

    //deleters
    delete[] archimedes;
    delete[] anabeth;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
