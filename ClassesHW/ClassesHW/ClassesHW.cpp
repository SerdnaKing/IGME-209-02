// ClassesHW.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;
#include "Player.h"
#include "Fighter.h"
#include <time.h>
int main()
{
    time_t t;
    srand((unsigned) time(&t));
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
    anabeth->Attack(&henk);
    treybrin.Attack(&henk);

    //deleters if they weren't created as an array don't delete them as an array.
  
    const char* funkyFreshNames[10] = { "Punky Brewmaster","David No-Nose McGee",
                                        "Flat Stanley's Brother: Obtuse Charles", 
                                        "Beauregard McBigMac",
                                         "Estranged Uncle Eddy","Crystal Pepsi TM",
                                         "Genghis Ron","Spaghetti Joe",
                                         "Garlic Bread","Fuzzbee Morse"};
    //PART 3
   //define an array of pointers to player objects
    Player* battlers[10];
    //loop 10 times and randomly create either a player or a fighter object at the current spot
    //in the array. Use rand() to get a random numebr and mod to make it either a 1 or a 0
    //to determine either a fighter or a player
    for (int i = 0; i < 10; i++) {
        int randomNumber = rand() % 2;
        if (randomNumber == 1) {
            Player* p = new Player((char*)funkyFreshNames[i], 10, 10, 10);
            battlers[i] = p;
   
        }
        else {
            Fighter* fighter = new Fighter((char*)funkyFreshNames[i], 15, 15, 15, 15);
            battlers[i] = fighter;
            
        }
    }
    //in a separate loop have the players and fighters battle each other. When a battler is 
    //attacked assume they die instantly and set their pointer in the array to nullptr.
    //Delete the pointers before losing it so that no memory is leaked (e.g delete THEN set to nullptr)
    int deadPeople = 0;
   do {
        int randomEnemy = rand() % 10;
        int randomTarget = rand() % 10;
        while (randomEnemy == randomTarget && battlers[randomEnemy] != nullptr && battlers[randomTarget] != nullptr) {
            randomEnemy = rand() % 10;
            randomTarget = rand() % 10;
        }
        if (battlers[randomEnemy] != nullptr && battlers[randomTarget] != nullptr) {
            battlers[randomEnemy]->Attack(battlers[randomTarget]);
            delete battlers[randomTarget];
            battlers[randomTarget] = nullptr;
            deadPeople++;
     }
       
       
       
    } while (deadPeople != 9);

    //check each index for the one player left standing and declare them the winner
    for (int k = 0; k < 10; k++) {
        if (battlers[k] != nullptr) {
            cout << "The winner is: " << battlers[k]->getName() << endl;
        }
    }

    //delete battlers to remove chances of memory leakage
    delete archimedes;
    delete anabeth;
   /* for (int i = 0; i < 10; i++) {
        delete[]battlers[i];
    }*/
    delete[] *battlers;
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
