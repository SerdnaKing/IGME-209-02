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
    
       if (strstr(answer, guess)) {
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
           if (toBeGuessed == "zoinks") {
               cout << "Congrats! You won!!!" << endl;
               break;
             }
       }
   
       else {


           
           showGallows(guessesMade);
           if (!strstr(wrongGuesses, guess)) {
               strcat_s(wrongGuesses, guess);
               guessesMade++;
           }
           if (strlen(guess) > 1) {
               cout << "\nThat's not one letter! try again!" << endl;
               //  showGallows(guessesMade);
               cout << "Word to solve: " << toBeGuessed << endl;
               cout << wrongGuesses << endl;
           }
           else {
               cout << "you already guessed that, try a different letter!"<<endl;
           }
          // strcat_s(wrongGuesses, guess);
           cout << wrongGuesses << endl;

           //showSolved(toBeGuessed, wrongGuesses);
       }
       
   }
   if (guessesMade == 8) {
       cout << "GAME OVER! YOU LOST!!" << endl;
       return 0;
   }
   else {
       cout << "You won!" << endl;
       return 0;
   }
  
}
