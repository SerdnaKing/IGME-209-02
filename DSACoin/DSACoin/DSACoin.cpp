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
	string key;

	// TODO DSA1

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

	// TODO DSA1

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
