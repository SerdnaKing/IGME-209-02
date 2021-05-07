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

//count initialization for readNextCrypto
int counter = 0;

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


	//this is kicking my butt, I'm making a temporary solution to make sure everything else works before continuing this in earnest
	string crypto = "";
	string arrayOfKeys[21] = { "324765" ,"329878","547825","457117","100235","000644","222222","483942","658393","234500","344323","654566","324664","468644","999999","564646","324679","087654","545678","435792","" };

	crypto = arrayOfKeys[counter];
	counter++;
	//ifstream ins("cryptoFile.txt");
	//// TODO DSA1
	//cryptoFile.open("cryptoFile.txt");
	//getline(cryptoFile, crypto);
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
	//keeps the while loop from infinitely checking
	int counter = 0;
	//have readNextCrypto and mainKey both set for the initial loop.
	string crypto = readNextCrypto();
	string key = mineKey();
	// write the main loop
	// mine the keys, check to see if the crypto is in the key
	// create a coin for the good keys and add it to your wallet
	//change this for loop into a while loop

	//while(size_t index != crypto.find(key) && calculatedValue != 0.0
	//change the key until it matches the current crypto.
	//once it does, change the crypto, add the current key to the wallet, 
	//make a new key and repeat the pattern
	//if the calculated value of the found key is zero BREAK that is the 
	//end of the test
	for (int i = 0; i < 20; i++) {
		if (size_t index = crypto.find(key) && index != 0) {
			Coin* newCoin = new Coin(key, calculateValue());
			myWallet.AddCoin(newCoin);
			counter++;
			cnt++;
			//move onto the next crypto
			crypto = readNextCrypto();
			//do I also get a new key?
			key = mineKey();
		}
		else {
			//what do I want it to do in this situation
			//mine another key and repeat
			key = mineKey();
			//loop back to the start and repeat until the key has a crypto
		}
	//}
	// write out the keys to the walletFile


	cout << "keys searched: " << cnt << endl;
	cout << "Wallet value: " << myWallet.GetValue() << endl;


}
