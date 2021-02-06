//implement functions here
#include <iostream>
using namespace std;

//add header file
//#include "hangman.h";
//showGallows recieves a guess limit as a parameter)
//draws correct ASCII art to the console window based on # of 
//incorrect guesses (max 8[rope head upper&lower body left and right arms and legs]
void showGallows(int guessLimit) {
	if (guessLimit == 0) {
		cout << " -------\n"<<
			    "|\n"<<
				"|\n"<<
				"|\n"<<
				"|\n"<<
				"|\n"<<
				"|\n"<<endl;

	}
	if (guessLimit == 1) {
		cout << " -------\n"<<
			    "|   |\n"<<
				"|\n"<<
				"|\n"<<
				"|\n"<<
				"|\n"<<
				"|\n"<<endl;
	}
	if (guessLimit == 2) {
		cout << " -------\n"<<
			    "|   |\n"<<
				"|   O\n"<<
				"|\n"<<
				"|\n"<<
				"|\n"<<
				"|\n"<<endl;
	}
	if (guessLimit == 3) {
		cout << " -------\n" <<
				"|   |\n" <<
				"|   O\n" <<
				"|   |\n" <<
				"|\n" <<
				"|\n" <<
				"|\n" << endl;
	}
	if (guessLimit == 4) {
		cout << " -------\n" <<
				"|   |\n" <<
				"|   O\n" <<
				"|  /|\n" <<
				"|\n" <<
				"|\n" <<
				"|\n" << endl;
	}
	if (guessLimit == 5) {
		cout << " -------\n" <<
				"|   |\n" <<
				"|   O\n" <<
				"|  /|\ \n" <<
				"|\n" <<
				"|\n" <<
				"|\n" << endl;
	}
	if (guessLimit == 6) {
		cout << " -------\n" <<
				"|   |\n" <<
				"|   O\n" <<
				"|  /|\ \n" <<
				"|   |\n" <<
				"|\n" <<
				"|\n" << endl;
	}
	if (guessLimit == 7) {
		cout << " -------\n" <<
				"|   |\n" <<
				"|   O\n" <<
				"|  /|\ \n" <<
				"|   |\n" <<
				"|  /\n" <<
				"|\n" << endl;
	}
	if (guessLimit == 8) {
		cout << " -------\n"<<
		         "|   |\n"<<
			     "|   O\n"<<
			     "|  /|\ \n"<<
			     "|   |\n"<<
			     "|  / \ \n"<<
			     "|\n"<<endl;
	}
}

//showSolved stores properly guessed letters in an array
//if word is hello, array of word is blank to begin (only contains _____)
//properly guessed letters are stored in w
//incorrect are stored in guesses
//THE CORRECT WORD IS: zoinks (letters to check: z o i n k s)
void showSolved(char word[], char guesses[]) {

	cout << "Wrong guesses: " + guesses[9] <<endl;
	cout << "Word to solve: " + word[7]<<endl; //6 letters plus 1 overflow
}