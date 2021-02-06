// Homework1_Hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


using namespace std;
#include "hangman.h";
int main()
{
    //integer counting guesses remaining
    int guessesMade = 0;
    char answer[7] = "zoinks";
    //the string that will be guessed by the user
    char guess[] = "";
    
    //the string that holds the correctly guessed letters
    //7 is overflow
    char toBeGuessed[7] = ""; 

    //the string that holds all the incorrect guesses
    char wrongGuesses[9] = "";

    cout << "Let's play hangman!\nYour word has 6 letters in it.\n" << endl;
   showGallows(guessesMade);
   
   while (guessesMade != 8 && answer != toBeGuessed) {
       cout << "Type a letter and hit enter: ";
       cin >> guess;
       if (strstr(answer, guess)) {
           cout << "Good answer!" << endl;

           if (guess[0] == 'z') {
               toBeGuessed[0] = 'z';
               showSolved(toBeGuessed, wrongGuesses);

           }
           if (guess[0] == 'o') {
               toBeGuessed[1] = 'o';
               showSolved(toBeGuessed, wrongGuesses);

           }
           if (guess[0] == 'i') {
               toBeGuessed[2] = 'i';
               showSolved(toBeGuessed, wrongGuesses);

           }
           if (guess[0] == 'n') {
               toBeGuessed[3] = 'n';
               showSolved(toBeGuessed, wrongGuesses);

           }
           if (guess[0] == 'k') {
               toBeGuessed[4] = 'k';
               showSolved(toBeGuessed, wrongGuesses);

           }
           if (guess[0] == 's') {
               toBeGuessed[5] = 's';
               showSolved(toBeGuessed, wrongGuesses);

           }
       
       }
       else {


           guessesMade++;
           showGallows(guessesMade);
           wrongGuesses;
       }
   }
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
