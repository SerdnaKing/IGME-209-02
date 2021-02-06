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
    char toBeGuessed[7] = "______"; 

    //the string that holds all the incorrect guesses
    char wrongGuesses[100] = "";

    cout << "Let's play hangman!\nYour word has 6 letters in it.\n" << endl;
   showGallows(guessesMade);
   
   while (guessesMade != 8 || toBeGuessed != answer) {
      
       cout << "Type a letter and hit enter: ";
       cin >> guess;
    
       if (strstr(answer, guess) && strlen(guess)==1) {
           cout << "Good answer!" << endl;

           if (guess[0] == 'z') {
               toBeGuessed[0] = 'z';
               showGallows(guessesMade);
               cout << "Word to solve: " << toBeGuessed << endl;
               cout << wrongGuesses << endl;
               //  showSolved(toBeGuessed, wrongGuesses);
           }
           if (guess[0] == 'o') {
               toBeGuessed[1] = 'o';
               showGallows(guessesMade);
               cout << toBeGuessed << endl;
               cout << wrongGuesses << endl;
             //  showSolved(toBeGuessed, wrongGuesses);

           }
           if (guess[0] == 'i') {
               toBeGuessed[2] = 'i';
               showGallows(guessesMade);
               cout << toBeGuessed << endl;
               cout << wrongGuesses << endl;
               //  showSolved(toBeGuessed, wrongGuesses);

           }
           if (guess[0] == 'n') {
               toBeGuessed[3] = 'n';
               showGallows(guessesMade);
               cout << toBeGuessed << endl;
               cout << wrongGuesses << endl;
               //  showSolved(toBeGuessed, wrongGuesses);

           }
           if (guess[0] == 'k') {
               toBeGuessed[4] = 'k';
               showGallows(guessesMade);
               cout << toBeGuessed << endl;
               cout << wrongGuesses << endl;
               //  showSolved(toBeGuessed, wrongGuesses);

           }
           if (guess[0] == 's') {
               toBeGuessed[5] = 's';
               showGallows(guessesMade);
               cout << toBeGuessed << endl;
               cout << wrongGuesses << endl;
               //  showSolved(toBeGuessed, wrongGuesses);

           }
           if (strcmp(toBeGuessed,answer) == 0) {
               cout << "Congrats! You won!!!" << endl;
               break;
             }

       }
       else {
           if (strlen(guess) > 1) {
               cout << "Input too long, enter one letter please" << endl;
           }
           if (!strstr(wrongGuesses, guess) && strlen(guess) ==1) {
               guessesMade++;
               cout << "That's not right..." << endl;
               strcat_s(wrongGuesses, guess);
               if (strlen(wrongGuesses) == 8) {
                   cout << "Game over! You lost!" << endl;
                   break;
               }
               showGallows(guessesMade);
               cout << toBeGuessed << endl;
               cout << wrongGuesses << endl;
           }
        //   if (strstr(wrongGuesses, guess) && strlen(guess) == 1) {
           else {
               cout << "That letter was already guessed" << endl;

           }
       }
   }  
   cout << "Press any key to continue..." << endl;
}
