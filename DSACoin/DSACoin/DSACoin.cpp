// DSACoin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <mutex>
#include <chrono>
#include "Coin.h"
#include "Wallet.h"
using namespace std;

/// <summary>
/// global variables
/// </summary>
std::chrono::high_resolution_clock clockTimer; 
std::chrono::high_resolution_clock::time_point start_time;
ifstream cryptoFile("cryptoFile.txt");;
ofstream walletFile("walletFile.txt");;


/// <summary>
/// Generates an 80 charater long string with random numbers in each such as
/// "01234567890123456789012345678901234567890123456789012345678901234567890123456789"
/// but with random numbers for each one
/// </summary>
/// <returns></returns>
string mineKey()
{
	//the random generation is already managed by the main's call to a timer

	string key;
	//make a max of 9 for the random
	int max = 9;
	//initialize random
	int random;
	//loop through 80 times to generate 80 random numbers
	//assign the random int to a string using to_String set to a temporary 
	//string
	//append the temp String to the key.
	for (int i = 0; i < 80; i++) {
		random = rand() % max;
		string newString = to_string(random);
		key.append(newString);
	}
	//with this set up, each call to mineKey() in main will generate
	//a completely random string of 80 numbers
	
	return key;
}

/// <summary>
/// reads the next crypto key from the keybank file
/// </summary>
/// <returns>returns new crypto to use or "" if the file was completely read</returns>
string readNextCrypto()
{
	string crypto = "";

	// TODO DSA1

	return crypto;
}

double calculateValue()
{
	double coinValue = 0.0;

	//take a time based on function call (clockTimer.now() and subtract when the clock started
	//this will calculate the time elapsed in milliseconds
	auto EndTime = chrono::duration_cast<chrono::milliseconds>(clockTimer.now() - start_time);
	//coinValue = 3 seconds (3000ms) - the current time elapsed since start * 100;
	coinValue = (3000 - EndTime.count()) * 100;
	//this will constantly check if the value is at or below zero, setting it to 0
	if (coinValue <= 0.0) {
		coinValue = 0.0;
	}
	return coinValue;
}

int main()
{
	start_time = clockTimer.now();
	srand(2021);
	Wallet myWallet;
	int cnt = 0;

	// TODO DSA1
	// write the main loop
	// mine the keys, check to see if the crypto is in the key
	// create a coin for the good keys and add it to your wallet
	// write out the keys to the walletFile


	cout << "keys searched: " << cnt << endl;
	cout << "Wallet value: " << myWallet.GetValue() << endl;


}
