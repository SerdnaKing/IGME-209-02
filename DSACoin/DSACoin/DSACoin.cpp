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
	int max = 10;
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
//count initialization for readNextCrypto
int counter = 0;
vector<string> lines;
string readNextCrypto()
{
	string crypto = "";
	string line;
	//only access this if it hasn't been already, otherwise just go straight to 
	//the setting of crypto to the next in line
	if (cryptoFile.is_open() && lines.size() == 0)
	{

		while (getline(cryptoFile, line))
		{
			if (line.size() > 0)
			{
				lines.push_back(line);
			}
		}

		cryptoFile.close();

	}
	crypto = lines.at(counter);
	counter++;
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
	//at the beginning of each call, clear out the wallet from the last run
//	walletFile.open("walletFile.txt", ios::trunc);
	//walletFile.close();
	start_time = clockTimer.now();
	srand(2021);
	Wallet myWallet;
	int cnt = 0;
	int keysLeft = 0;
	

	//have readNextCrypto and mainKey both set for the initial loop.
	//string crypto = readNextCrypto();
	//keysLeft++;
	//string key = mineKey();
	//string key;
	//string crypto;

	//threaded version of above comments. 
	//This consistently gives off higher wallet scores than the unthreaded version
	string crypto;
	string key;
	thread c(readNextCrypto);
	thread k(mineKey);

	c.join();
	k.join();
	
	// write the main loop
	// mine the keys, check to see if the crypto is in the key
	// create a coin for the good keys and add it to your wallet

	//change the key until it matches the current crypto.
	//once it does, change the crypto, add the current key to the wallet, 
	//make a new key and repeat the pattern
	//if the calculated value of the found key is zero BREAK that is the 
	//end of the test
	double value = calculateValue();
	vector<string> filedKeys;
		 do{
			double value = calculateValue();
			if (key.find(crypto,0) != string::npos && keysLeft <19) {
			Coin* newCoin = new Coin(key, calculateValue());
				myWallet.AddCoin(newCoin);
				cnt++;
				filedKeys.push_back(key);
				//move onto the next crypto
				crypto = readNextCrypto();
				keysLeft++;
				//do I also get a new key?
				key = mineKey();

			}
			else {
				//mine another key and repeat
				key = mineKey();
				cnt++;
				//loop back to the start and repeat until the key has a crypto
			}
			//if the value of coins ever reaches zero, break immediately
			if (value == 0.0) {
				break;
			}
			//check to make sure that the key is not an empty string (signifying the end of the list)
		} while (value != 0.0 || key == "");

		//take the keys and write them to the wallet.
		std::ostream_iterator<std::string> output_iterator(walletFile, "\n");
		std::copy(filedKeys.begin(), filedKeys.end(), output_iterator);

		//clean out filedKeys for next loop
		for (int i = 0; i < filedKeys.size(); i++) {
			filedKeys.at(i).clear();
		}
	// write out the keys to the walletFile


	cout << "keys searched: " << cnt << endl;
	cout << "Wallet value: " << myWallet.GetValue() << endl;


}
